#!/usr/bin/env python3
"""Extract intrinsic information from source/index.md into JSON format."""

import json
import re
import sys
from pathlib import Path


# Packed SIMD type definitions from the spec.
PACKED_TYPES = [
    {"name": "int8x4_t",   "size_bytes": 4, "alignment_bytes": 4, "description": "Four signed 8-bit integers",     "element_type": "int8_t",   "element_count": 4, "total_bits": 32},
    {"name": "uint8x4_t",  "size_bytes": 4, "alignment_bytes": 4, "description": "Four unsigned 8-bit integers",   "element_type": "uint8_t",  "element_count": 4, "total_bits": 32},
    {"name": "int16x2_t",  "size_bytes": 4, "alignment_bytes": 4, "description": "Two signed 16-bit integers",     "element_type": "int16_t",  "element_count": 2, "total_bits": 32},
    {"name": "uint16x2_t", "size_bytes": 4, "alignment_bytes": 4, "description": "Two unsigned 16-bit integers",   "element_type": "uint16_t", "element_count": 2, "total_bits": 32},
    {"name": "int8x8_t",   "size_bytes": 8, "alignment_bytes": 8, "description": "Eight signed 8-bit integers",    "element_type": "int8_t",   "element_count": 8, "total_bits": 64},
    {"name": "uint8x8_t",  "size_bytes": 8, "alignment_bytes": 8, "description": "Eight unsigned 8-bit integers",  "element_type": "uint8_t",  "element_count": 8, "total_bits": 64},
    {"name": "int16x4_t",  "size_bytes": 8, "alignment_bytes": 8, "description": "Four signed 16-bit integers",    "element_type": "int16_t",  "element_count": 4, "total_bits": 64},
    {"name": "uint16x4_t", "size_bytes": 8, "alignment_bytes": 8, "description": "Four unsigned 16-bit integers",  "element_type": "uint16_t", "element_count": 4, "total_bits": 64},
    {"name": "int32x2_t",  "size_bytes": 8, "alignment_bytes": 8, "description": "Two signed 32-bit integers",     "element_type": "int32_t",  "element_count": 2, "total_bits": 64},
    {"name": "uint32x2_t", "size_bytes": 8, "alignment_bytes": 8, "description": "Two unsigned 32-bit integers",   "element_type": "uint32_t", "element_count": 2, "total_bits": 64},
]

# Regex to extract prototype: return_type func_name(args);
PROTO_RE = re.compile(
    r'^(?P<ret>.+?)\s+(?P<name>__riscv_\w+)\((?P<args>[^)]*)\);?$'
)

# Regex to parse a single argument: type name
# Handles: int32_t rs1, const unsigned shamt, int8_t *p, uint32_t rs2
ARG_RE = re.compile(
    r'^(?P<type>(?:const\s+)?[\w]+(?:\s+[\w]+)*(?:\s*\*)?)\s+(?P<name>\w+)$'
)

# Heading level detection
HEADING_RE = re.compile(r'^(?P<hashes>#{2,4})\s+(?P<title>.+)$')

# Table row with backtick prototype
TABLE_ROW_RE = re.compile(r'^\|.*`.*__riscv_.*\|')

# Availability from heading title
AVAILABILITY_RE = re.compile(r'\((?P<avail>RV32|RV64)\s+Only\)', re.IGNORECASE)


def parse_argument(arg_str):
    """Parse a single C argument string into type and name.

    Handles cases like:
      int32_t rs1        -> type="int32_t", name="rs1"
      const unsigned shamt -> type="const unsigned", name="shamt"
      int8_t *p          -> type="int8_t *", name="p"
      uint8x4_t v        -> type="uint8x4_t", name="v"
    """
    arg_str = arg_str.strip()
    if not arg_str:
        return None

    # Handle pointer: "int8_t *p" or "int8_t* p"
    # The * belongs to the type, name is last identifier
    m = re.match(r'^(.+?)\s*(\*)\s*(\w+)$', arg_str)
    if m:
        return {"type": m.group(1).strip() + ' *', "name": m.group(3)}

    # Regular: split on last whitespace
    m = ARG_RE.match(arg_str)
    if m:
        return {"type": m.group('type').strip(), "name": m.group('name').strip()}

    # Fallback: split on last space
    parts = arg_str.rsplit(None, 1)
    if len(parts) == 2:
        return {"type": parts[0].strip(), "name": parts[1].strip()}

    return {"type": arg_str, "name": ""}


def parse_prototype(proto_str):
    """Parse a C prototype string into return_type, name, and arguments."""
    proto_str = proto_str.strip().rstrip(';').strip()
    m = PROTO_RE.match(proto_str)
    if not m:
        return None
    ret = m.group('ret').strip()
    name = m.group('name').strip()
    args_str = m.group('args').strip()

    arguments = []
    if args_str:
        for arg in args_str.split(','):
            arg = arg.strip()
            parsed_arg = parse_argument(arg)
            if parsed_arg:
                arguments.append(parsed_arg)

    return {"return_type": ret, "name": name, "arguments": arguments}


def parse_instructions(instr_str, availability):
    """Parse instruction column into rv32/rv64 instruction lists.

    Platform annotations like (RV32) or (RV64) apply to all preceding
    unannotated parts since the last annotation. For example:
      `pwslli.b`, `pwsll.bs`(RV32), `zip8p`+`pslli.h`, `zip8p`+`psll.hs`(RV64)
    means: RV32 = [pwslli.b, pwsll.bs], RV64 = [zip8p+pslli.h, zip8p+psll.hs]
    """
    if not instr_str or not instr_str.strip():
        return {"rv32": [], "rv64": []}

    instr_str = instr_str.strip()

    parts = split_instruction_parts(instr_str)

    # First pass: extract instruction names and platform annotations per part
    parsed_parts = []
    for part in parts:
        part = part.strip()
        if not part:
            continue

        insn_names = re.findall(r'`([^`]+)`', part)
        if not insn_names:
            continue
        insn_str = '+'.join(insn_names)

        platform = None
        plat_match = re.search(r'\(RV(32|64)\)\s*$', part)
        if plat_match:
            platform = f"rv{plat_match.group(1)}"

        parsed_parts.append({"insn": insn_str, "platform": platform})

    # Second pass: platform annotations apply backwards to preceding
    # unannotated parts. Walk backwards from each annotated part and claim
    # preceding unannotated parts.
    # Strategy: walk from end, assign platform retroactively.
    assigned = [p["platform"] for p in parsed_parts]
    for i in range(len(assigned) - 1, -1, -1):
        if assigned[i] is not None:
            # Walk backwards and assign the same platform to unannotated parts
            for j in range(i - 1, -1, -1):
                if assigned[j] is not None:
                    break
                assigned[j] = assigned[i]

    rv32_instrs = []
    rv64_instrs = []
    generic_instrs = []

    for i, pp in enumerate(parsed_parts):
        platform = assigned[i]
        if platform == 'rv32':
            rv32_instrs.append(pp["insn"])
        elif platform == 'rv64':
            rv64_instrs.append(pp["insn"])
        else:
            generic_instrs.append(pp["insn"])

    # Assign generic (unannotated) instructions based on availability
    if availability == 'rv32_only':
        rv32_instrs = generic_instrs + rv32_instrs
        rv64_instrs = []
    elif availability == 'rv64_only':
        rv64_instrs = generic_instrs + rv64_instrs
        rv32_instrs = []
    else:
        if rv32_instrs or rv64_instrs:
            if generic_instrs:
                rv32_instrs = generic_instrs + rv32_instrs
                rv64_instrs = generic_instrs + rv64_instrs
        else:
            rv32_instrs = generic_instrs[:]
            rv64_instrs = generic_instrs[:]

    return {"rv32": rv32_instrs, "rv64": rv64_instrs}


def split_instruction_parts(s):
    """Split instruction string by commas, respecting parentheses.

    The tricky bit: "(RV64)" after a backtick-quoted instruction belongs to that
    instruction, but the *next* comma-separated chunk may carry its own "(RV32)".
    We split on ", " that is followed by a backtick (start of next instruction)
    or some text that looks like another instruction group.
    """
    # Approach: walk through and split on `, ` when not inside parens
    parts = []
    depth = 0
    current = []
    i = 0
    while i < len(s):
        ch = s[i]
        if ch == '(':
            depth += 1
            current.append(ch)
        elif ch == ')':
            depth = max(0, depth - 1)
            current.append(ch)
        elif ch == ',' and depth == 0:
            parts.append(''.join(current))
            current = []
            # Skip whitespace after comma
            i += 1
            while i < len(s) and s[i] == ' ':
                i += 1
            continue
        else:
            current.append(ch)
        i += 1
    if current:
        parts.append(''.join(current))
    return parts


def parse_availability(title):
    """Derive availability from section/subsection title."""
    # Match "(RV32 Only)" or "(RV64 Only)" with parentheses
    m = AVAILABILITY_RE.search(title)
    if m:
        return f"rv{m.group('avail').lower()}_only"
    # Match "RV32 Only" or "RV64 Only" without parentheses (e.g. section titles)
    m2 = re.search(r'\bRV(32|64)\s+Only\b', title, re.IGNORECASE)
    if m2:
        return f"rv{m2.group(1)}_only"
    return "both"


def extract_table_cells(line):
    """Extract cells from a markdown table row."""
    # Strip leading/trailing |
    line = line.strip()
    if line.startswith('|'):
        line = line[1:]
    if line.endswith('|'):
        line = line[:-1]
    return [cell.strip() for cell in line.split('|')]


def extract_prototype_from_cell(cell):
    """Extract prototype string from a table cell (inside backticks)."""
    m = re.search(r'`([^`]+)`', cell)
    if m:
        return m.group(1)
    return cell.strip()


def is_separator_row(line):
    """Check if a table row is a separator (contains ---)."""
    return bool(re.match(r'^\|[\s\-:|]+\|$', line.strip()))


def is_table_header(line, next_line):
    """Check if current line is a table header (next line is separator)."""
    return next_line and is_separator_row(next_line)


def parse_spec(filepath):
    """Parse the spec file and return structured data."""
    lines = Path(filepath).read_text().splitlines()

    sections = []
    current_category = ""
    current_section_name = ""
    current_section_desc = ""
    current_availability = "both"
    current_section = None

    # Track description lines between heading and table
    desc_lines = []
    collecting_desc = False

    i = 0
    while i < len(lines):
        line = lines[i]

        # Check for headings
        hm = HEADING_RE.match(line)
        if hm:
            level = len(hm.group('hashes'))
            title = hm.group('title').strip()

            if level == 2:
                # Major category
                current_category = title
                current_section_name = ""
                current_availability = "both"
                current_section = None
                desc_lines = []
                collecting_desc = True
            elif level == 3:
                # Check if this is a bit-width sub-heading like "### 64-bit"
                # or "### 32-bit (RV32 Only)"
                if re.match(r'^\d+-bit', title):
                    current_availability = parse_availability(title)
                else:
                    # New section
                    current_section_name = title
                    current_availability = parse_availability(title)
                    desc_lines = []
                    collecting_desc = True
                    current_section = None
            elif level == 4:
                # Sub-section, usually bit-width: "#### 32-bit", "#### 64-bit (RV64 Only)"
                current_availability = parse_availability(title)

            i += 1
            continue

        # Collect description text between heading and first table
        if collecting_desc and not line.startswith('|') and not line.startswith('*'):
            if line.strip():
                desc_lines.append(line.strip())
            i += 1
            continue
        elif collecting_desc and (line.startswith('|') or line.startswith('*')):
            collecting_desc = False
            current_section_desc = ' '.join(desc_lines) if desc_lines else ""

        # Check for table rows with prototypes
        if line.startswith('|') and '__riscv_' in line:
            # Skip if this is a header row
            if i + 1 < len(lines) and is_separator_row(lines[i + 1]):
                i += 1
                continue

            # Skip separator rows
            if is_separator_row(line):
                i += 1
                continue

            # Ensure we have a section
            if current_section is None:
                current_section = {
                    "category": current_category,
                    "name": current_section_name or current_category,
                    "description": current_section_desc,
                    "intrinsics": [],
                }
                sections.append(current_section)

            cells = extract_table_cells(line)
            if not cells:
                i += 1
                continue

            proto_str = extract_prototype_from_cell(cells[0])
            parsed = parse_prototype(proto_str)
            if not parsed:
                print(f"WARNING: Failed to parse prototype: {proto_str}", file=sys.stderr)
                i += 1
                continue

            instr_str = ""
            notes = ""
            if len(cells) >= 2:
                instr_str = cells[1].strip()
            if len(cells) >= 3:
                notes = cells[2].strip()

            instructions = parse_instructions(instr_str, current_availability)

            # Check for "swapped operands" in instruction text
            if re.search(r'\bswapped?\s+operands?\b', instr_str, re.IGNORECASE):
                if notes:
                    notes = notes + "; swapped operands"
                else:
                    notes = "swapped operands"

            intrinsic = {
                "name": parsed["name"],
                "return_type": parsed["return_type"],
                "arguments": parsed["arguments"],
                "instructions": instructions,
                "availability": current_availability,
            }
            if notes:
                intrinsic["notes"] = notes

            current_section["intrinsics"].append(intrinsic)

        i += 1

    # Remove empty sections
    sections = [s for s in sections if s["intrinsics"]]

    return {"types": PACKED_TYPES, "sections": sections}


def main():
    script_dir = Path(__file__).resolve().parent
    repo_root = script_dir.parent
    spec_path = repo_root / "source" / "index.md"
    output_path = repo_root / "intrinsics.json"

    if len(sys.argv) > 1:
        spec_path = Path(sys.argv[1])
    if len(sys.argv) > 2:
        output_path = Path(sys.argv[2])

    if not spec_path.exists():
        print(f"Error: {spec_path} not found", file=sys.stderr)
        sys.exit(1)

    result = parse_spec(spec_path)

    total = sum(len(s["intrinsics"]) for s in result["sections"])
    print(f"Parsed {len(result['sections'])} sections, {total} intrinsics")
    for s in result["sections"]:
        print(f"  {s['name']}: {len(s['intrinsics'])} intrinsics")

    with open(output_path, 'w') as f:
        json.dump(result, f, indent=2)
        f.write('\n')

    print(f"Written to {output_path}")


if __name__ == '__main__':
    main()

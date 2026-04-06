# RISC-V P Extension Intrinsics

Working draft for the RISC-V P extension intrinsics.

## Tools

### spec2json — Intrinsic Spec Parser

Extracts all intrinsic definitions from `source/index.md` into a structured JSON file (`intrinsics.json`).

```
python3 scripts/spec2json.py [SPEC_PATH] [OUTPUT_PATH]
```

- Default spec: `source/index.md`
- Default output: `intrinsics.json`

The JSON contains packed SIMD type definitions and all intrinsics grouped by section, including prototypes, argument types, instruction mappings for RV32/RV64, and availability.

### api_tester — Compile-Only API Tester

Verifies that every intrinsic declared in the spec exists and has the correct signature by generating and compiling a test file for each intrinsic.

```
python3 scripts/api_tester.py --cc <compiler> [options] [-- extra_compiler_flags]
```

Options:

| Option | Default | Description |
|--------|---------|-------------|
| `--cc` | (required) | Path to C compiler |
| `--header` | `riscv_p_asm.h` | Header file name to include |
| `--march` | `rv64gcp` | Architecture string |
| `--mabi` | `lp64` | ABI string |
| `-I` | | Include path (can be specified multiple times) |
| `-j` | nproc | Number of parallel compile jobs |
| `-o` | `./api-test` | Output directory for generated test files |
| `--spec` | `source/index.md` | Path to spec file |

Examples:

```bash
# Test with GCC cross compiler
python3 scripts/api_tester.py --cc riscv64-unknown-elf-gcc

# Test RV32 with custom header and include path
python3 scripts/api_tester.py --cc riscv64-unknown-elf-gcc \
    --march rv32gcp --mabi ilp32 \
    --header my_p_ext.h -I /path/to/headers

# Test with clang (auto-adds -target and -menable-experimental-extensions)
python3 scripts/api_tester.py --cc clang -I /path/to/headers

# Pass extra flags to the compiler
python3 scripts/api_tester.py --cc riscv64-unknown-elf-gcc -- -Werror -std=c11
```

#ifndef __RISCV_P_ASM_H
#define __RISCV_P_ASM_H

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__riscv_p)

#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__))

// Packed SIMD Types
// A 32-bit type will occupy a full GPR on RV32 and half of a GPR on RV64.
// A 64-bit type will occupy a pair of GPRs on RV32 and a full GPR on RV64.

typedef struct { uint32_t __val; } int8x4_t;
typedef struct { uint32_t __val; } uint8x4_t;
typedef struct { uint32_t __val; } int16x2_t;
typedef struct { uint32_t __val; } uint16x2_t;

typedef struct { uint64_t __val; } int8x8_t;
typedef struct { uint64_t __val; } uint8x8_t;
typedef struct { uint64_t __val; } int16x4_t;
typedef struct { uint64_t __val; } uint16x4_t;
typedef struct { uint64_t __val; } int32x2_t;
typedef struct { uint64_t __val; } uint32x2_t;

// Scalar Intrinsics Common to RV32 and RV64

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_abs_u32(int32_t __rs1) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("abs %0, %1" : "=r"(__result) : "r"(__rs1));
#else
  __asm__("absw %0, %1" : "=r"(__result) : "r"(__rs1));
#endif
  return __result;
}

static __inline__ unsigned __DEFAULT_FN_ATTRS
__riscv_cls_32(int32_t __rs1) {
  unsigned __result;
#if __riscv_xlen == 32
  __asm__("cls %0, %1" : "=r"(__result) : "r"(__rs1));
#else
  __asm__("clsw %0, %1" : "=r"(__result) : "r"(__rs1));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_rev_32(uint32_t __rs1) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("rev %0, %1" : "=r"(__result) : "r"(__rs1));
#else
  // On RV64, emulated with rev then shift right
  uint64_t __tmp;
  __asm__("rev %0, %1" : "=r"(__tmp) : "r"((uint64_t)__rs1));
  __result = (uint32_t)(__tmp >> 32);
#endif
  return __result;
}

#if __riscv_xlen == 32
#define __riscv_sslai_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("sslai %0, %1, %2" : "=r"(__result) : "r"((int32_t)(rs1)), "i"(shamt)); \
    __result; \
  })
#else
#define __riscv_sslai_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("psslai.w %0, %1, %2" : "=r"(__result) : "r"((int32_t)(rs1)), "i"(shamt)); \
    __result; \
  })
#endif

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_ssha_i32(int32_t __rs1, int __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("ssha %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pssha.ws %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_sshar_i32(int32_t __rs1, int __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("sshar %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("psshar.ws %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_sadd_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("sadd %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("psadd.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_aadd_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("aadd %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("paadd.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_saddu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("saddu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("psaddu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_aaddu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("aaddu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("paaddu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_ssub_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("ssub %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pssub.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_asub_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("asub %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pasub.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_ssubu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("ssubu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pssubu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_asubu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("asubu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pasubu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

#if __riscv_xlen == 32
#define __riscv_usati_u32(rs1, shamt) \
  __extension__ ({ \
    uint32_t __result; \
    __asm__("usati %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#else
#define __riscv_usati_u32(rs1, shamt) \
  __extension__ ({ \
    uint32_t __result; \
    __asm__("pusati.w %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#endif

#if __riscv_xlen == 32
#define __riscv_srari_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("srari %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#else
#define __riscv_srari_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("psrari.w %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#endif

#if __riscv_xlen == 32
#define __riscv_sati_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("sati %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#else
#define __riscv_sati_i32(rs1, shamt) \
  __extension__ ({ \
    int32_t __result; \
    __asm__("psati.w %0, %1, %2" : "=r"(__result) : "r"((int32_t)(__rs1)), "i"(shamt)); \
    __result; \
  })
#endif

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_ssh1sadd_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("ssh1sadd %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pssh1sadd.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulh_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulh %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  // On RV64, emulated with mul + shift
  int64_t __tmp = (int64_t)__rs1 * (int64_t)__rs2;
  __result = (int32_t)(__tmp >> 32);
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulhr_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhr %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulhr.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhacc_i32(int32_t __rd, int32_t __rs1, int32_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhacc %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhacc.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhracc_i32(int32_t __rd, int32_t __rs1, int32_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhracc %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhracc.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mulhu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  // On RV64, emulated with mul + shift
  uint64_t __tmp = (uint64_t)__rs1 * (uint64_t)__rs2;
  __result = (uint32_t)(__tmp >> 32);
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mulhru_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhru %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulhru.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mhaccu_u32(uint32_t __rd, uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhaccu %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhaccu.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mhraccu_u32(uint32_t __rd, uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhraccu %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhraccu.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulhsu_i32(int32_t __rs1, uint32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhsu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  // On RV64, emulated with mul + shift
  int64_t __tmp = (int64_t)__rs1 * (uint64_t)__rs2;
  __result = (int32_t)(__tmp >> 32);
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulhrsu_i32(int32_t __rs1, uint32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhrsu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulhrsu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhaccsu_i32(int32_t __rd, int32_t __rs1, uint32_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhaccsu %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhaccsu.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhraccsu_i32(int32_t __rd, int32_t __rs1, uint32_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhraccsu %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhraccsu.w %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulq_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulq %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulq.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulqr_i32(int32_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulqr %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulqr.w %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

// RV32 Only Scalar Intrinsics (without 64-bit integers)

#if __riscv_xlen == 32
static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_slx_u32(uint32_t __rd, uint32_t __rs1, unsigned __shamt) {
  uint32_t __result = __rd;
  __asm__("slx %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__shamt));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_srx_u32(uint32_t __rd, uint32_t __rs1, unsigned __shamt) {
  uint32_t __result = __rd;
  __asm__("srx %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__shamt));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mseq_i32(int32_t __rs1, int32_t __rs2) {
  uint32_t __result;
  __asm__("mseq %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mseq_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("mseq %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mslt_i32(int32_t __rs1, int32_t __rs2) {
  uint32_t __result;
  __asm__("mslt %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_msgt_i32(int32_t __rs1, int32_t __rs2) {
  uint32_t __result;
  // Swap operands to implement greater-than using less-than
  __asm__("mslt %0, %2, %1" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_msltu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("msltu %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_msgtu_u32(uint32_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  // Swap operands to implement greater-than using less-than
  __asm__("msltu %0, %2, %1" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// RV32 Only Scalar Intrinsics (with 64-bit integers using "R" constraint)

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_wzip8p_u64(uint32_t __rs1, uint32_t __rs2) {
  uint64_t __result;
  __asm__("wzip8p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_wzip16p_u64(uint32_t __rs1, uint32_t __rs2) {
  uint64_t __result;
  __asm__("wzip16p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqwacc_i64(int64_t __rd, int32_t __rs1, int32_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqwacc %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqrwacc_i64(int64_t __rd, int32_t __rs1, int32_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqrwacc %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_nclipu_u32(uint64_t __rs1_p, uint32_t __rs2) {
  uint32_t __result;
  __asm__("nclipu %0, %1, %2" : "=r"(__result) : "R"(__rs1_p), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_nclipru_u32(uint64_t __rs1_p, uint32_t __rs2) {
  uint32_t __result;
  __asm__("nclipru %0, %1, %2" : "=r"(__result) : "R"(__rs1_p), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_nsrar_i32(int64_t __rs1_p, uint32_t __rs2) {
  int32_t __result;
  __asm__("nsrar %0, %1, %2" : "=r"(__result) : "R"(__rs1_p), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_nclip_i32(int64_t __rs1_p, uint32_t __rs2) {
  int32_t __result;
  __asm__("nclip %0, %1, %2" : "=r"(__result) : "R"(__rs1_p), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_nclipr_i32(int64_t __rs1_p, uint32_t __rs2) {
  int32_t __result;
  __asm__("nclipr %0, %1, %2" : "=r"(__result) : "R"(__rs1_p), "r"(__rs2));
  return __result;
}

// Packed Multiplication with Widening Horizontal Addition (RV32 Only)

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wadd_i64(int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result;
  __asm__("pm2wadd.h %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wadda_i64(int64_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2wadda.h %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wadd_x_i64(int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result;
  __asm__("pm2wadd.hx %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wadda_x_i64(int64_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2wadda.hx %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm2waddu_u64(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint64_t __result;
  __asm__("pm2waddu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm2waddau_u64(uint64_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint64_t __result = __rd;
  __asm__("pm2waddau.h %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wsub_i64(int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result;
  __asm__("pm2wsub.h %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wsuba_i64(int64_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2wsuba.h %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wsub_x_i64(int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result;
  __asm__("pm2wsub.hx %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2wsuba_x_i64(int64_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2wsuba.hx %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2waddsu_u64(int16x2_t __rs1, uint16x2_t __rs2) {
  int64_t __result;
  __asm__("pm2waddsu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2waddasu_u64(int64_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2waddasu.h %0, %1, %2" : "+R"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}
#endif // __riscv_xlen == 32

// RV64 Only Scalar Intrinsics

#if __riscv_xlen == 64
static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_abs_u64(int64_t __rs1) {
  uint64_t __result;
  __asm__("abs %0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ unsigned __DEFAULT_FN_ATTRS
__riscv_cls_64(int64_t __rs1) {
  unsigned __result;
  __asm__("cls %0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_rev_64(uint64_t __rs1) {
  uint64_t __result;
  __asm__("rev %0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_rev16_u64(uint64_t __rs1) {
  uint64_t __result;
  __asm__("rev16 %0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_sha_i64(int64_t __rs1, int __rs2) {
  int64_t __result;
  __asm__("sha %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_shar_i64(int64_t __rs1, int __rs2) {
  int64_t __result;
  __asm__("shar %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

#define __riscv_usati_u64(rs1, shamt) \
  __extension__ ({ \
    uint64_t __result; \
    __asm__("usati %0, %1, %2" : "=r"(__result) : "r"((int64_t)(rs1)), "i"(shamt)); \
    __result; \
  })

#define __riscv_srari_i64(rs1, shamt) \
  __extension__ ({ \
    int64_t __result; \
    __asm__("srari %0, %1, %2" : "=r"(__result) : "r"((int64_t)(rs1)), "i"(shamt)); \
    __result; \
  })

#define __riscv_sati_i64(rs1, shamt) \
  __extension__ ({ \
    int64_t __result; \
    __asm__("sati %0, %1, %2" : "=r"(__result) : "r"((int64_t)(rs1)), "i"(shamt)); \
    __result; \
  })

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_slx_u64(uint64_t __rd, uint64_t __rs1, unsigned __shamt) {
  uint64_t __result = __rd;
  __asm__("slx %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__shamt));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_srx_u64(uint64_t __rd, uint64_t __rs1, unsigned __shamt) {
  uint64_t __result = __rd;
  __asm__("srx %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__shamt));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_unzip8p_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("unzip8p %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_unzip16p_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("unzip16p %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_unzip8hp_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("unzip8hp %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_unzip16hp_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("unzip16hp %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_zip8p_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("zip8p %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_zip16p_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("zip16p %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_zip8hp_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("zip8hp %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_zip16hp_u64(uint64_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("zip16hp %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}
#endif // __riscv_xlen == 64

// Packed SIMD Intrinsics

// Packed Splat - 32-bit types
// Implemented as macros to allow compiler to choose immediate forms when possible

#define __riscv_pmv_s_u8x4(x) __extension__ ({ \
  uint8_t __val = (uint8_t)(x); \
  uint8x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.b %0, %1" : "=r"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.bs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i8x4(x) __extension__ ({ \
  int8_t __val = (int8_t)(x); \
  int8x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.b %0, %1" : "=r"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.bs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_u16x2(x) __extension__ ({ \
  uint16_t __val = (uint16_t)(x); \
  uint16x2_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val <= 511 || __val >= 65024) { \
      __asm__("pli.h %0, %1" : "=r"(__result.__val) : "i"((int16_t)__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.h %0, %1" : "=r"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i16x2(x) __extension__ ({ \
  int16_t __val = (int16_t)(x); \
  int16x2_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val >= -512 && __val <= 511) { \
      __asm__("pli.h %0, %1" : "=r"(__result.__val) : "i"(__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.h %0, %1" : "=r"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

// Packed Splat - 64-bit types

#if __riscv_xlen == 32

#define __riscv_pmv_s_u8x8(x) __extension__ ({ \
  uint8_t __val = (uint8_t)(x); \
  uint8x8_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.db %0, %1" : "=R"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.dbs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i8x8(x) __extension__ ({ \
  int8_t __val = (int8_t)(x); \
  int8x8_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.db %0, %1" : "=R"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.dbs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_u16x4(x) __extension__ ({ \
  uint16_t __val = (uint16_t)(x); \
  uint16x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val <= 511 || __val >= 65024) { \
      __asm__("pli.dh %0, %1" : "=R"(__result.__val) : "i"((int16_t)__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.dh %0, %1" : "=R"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.dhs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.dhs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i16x4(x) __extension__ ({ \
  int16_t __val = (int16_t)(x); \
  int16x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val >= -512 && __val <= 511) { \
      __asm__("pli.dh %0, %1" : "=R"(__result.__val) : "i"(__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.dh %0, %1" : "=R"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.dhs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.dhs %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_u32x2(x) __extension__ ({ \
  uint32_t __val = (uint32_t)(x); \
  uint32x2_t __result; \
  __asm__("padd.dws %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  __result; \
})

#define __riscv_pmv_s_i32x2(x) __extension__ ({ \
  int32_t __val = (int32_t)(x); \
  int32x2_t __result; \
  __asm__("padd.dws %0, x0, %1" : "=R"(__result.__val) : "r"(__val)); \
  __result; \
})

// Packed Shifts - 64-bit types (RV32)

// Packed shift left logical
#define __riscv_psll_s_u8x8(rs1, shamt) __extension__ ({ \
  uint8x8_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 8) { \
    __asm__("pslli.db %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dbs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psll_s_i8x8(rs1, shamt) __extension__ ({ \
  int8x8_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 8) { \
    __asm__("pslli.db %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dbs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psll_s_u16x4(rs1, shamt) __extension__ ({ \
  uint16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 16) { \
    __asm__("pslli.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psll_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 16) { \
    __asm__("pslli.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psll_s_u32x2(rs1, shamt) __extension__ ({ \
  uint32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 32) { \
    __asm__("pslli.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psll_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 32) { \
    __asm__("pslli.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psll.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed saturating shift left arithmetic (immediate only)
#define __riscv_psslai_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psslai.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(shamt)); \
  __result; \
})

#define __riscv_psslai_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psslai.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(shamt)); \
  __result; \
})

// Packed saturating shift with scalar (variable shift amount, signed)
#define __riscv_pssha_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("pssha.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(shamt)); \
  __result; \
})

#define __riscv_pssha_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("pssha.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed saturating shift right arithmetic with rounding and scalar
#define __riscv_psshar_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psshar.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(shamt)); \
  __result; \
})

#define __riscv_psshar_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psshar.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed shift right logical
#define __riscv_psrl_s_u8x8(rs1, shamt) __extension__ ({ \
  uint8x8_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 8) { \
    __asm__("psrli.db %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psrl.dbs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psrl_s_u16x4(rs1, shamt) __extension__ ({ \
  uint16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 16) { \
    __asm__("psrli.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psrl.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psrl_s_u32x2(rs1, shamt) __extension__ ({ \
  uint32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 32) { \
    __asm__("psrli.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psrl.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed shift right arithmetic
#define __riscv_psra_s_i8x8(rs1, shamt) __extension__ ({ \
  int8x8_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 8) { \
    __asm__("psrai.db %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psra.dbs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psra_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 16) { \
    __asm__("psrai.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psra.dhs %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_psra_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u < 32) { \
    __asm__("psrai.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(__shamt_u)); \
  } else { \
    __asm__("psra.dws %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed shift right arithmetic with rounding (immediate only)
#define __riscv_psrari_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psrari.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(shamt)); \
  __result; \
})

#define __riscv_psrari_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psrari.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(shamt)); \
  __result; \
})

#else // __riscv_xlen == 64

#define __riscv_pmv_s_u8x8(x) __extension__ ({ \
  uint8_t __val = (uint8_t)(x); \
  uint8x8_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.b %0, %1" : "=r"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.bs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i8x8(x) __extension__ ({ \
  int8_t __val = (int8_t)(x); \
  int8x8_t __result; \
  if (__builtin_constant_p(__val)) { \
    __asm__("pli.b %0, %1" : "=r"(__result.__val) : "i"(__val)); \
  } else { \
    __asm__("padd.bs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_u16x4(x) __extension__ ({ \
  uint16_t __val = (uint16_t)(x); \
  uint16x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val <= 511 || __val >= 65024) { \
      __asm__("pli.h %0, %1" : "=r"(__result.__val) : "i"((int16_t)__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.h %0, %1" : "=r"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i16x4(x) __extension__ ({ \
  int16_t __val = (int16_t)(x); \
  int16x4_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val >= -512 && __val <= 511) { \
      __asm__("pli.h %0, %1" : "=r"(__result.__val) : "i"(__val)); \
    } else if ((__val & 0x3F) == 0) { \
      __asm__("plui.h %0, %1" : "=r"(__result.__val) : "i"(__val >> 6)); \
    } else { \
      __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.hs %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_u32x2(x) __extension__ ({ \
  uint32_t __val = (uint32_t)(x); \
  uint32x2_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val <= 511 || __val >= 4294966784U) { \
      __asm__("pli.w %0, %1" : "=r"(__result.__val) : "i"((int32_t)__val)); \
    } else if ((__val & 0x3FFFFF) == 0) { \
      __asm__("plui.w %0, %1" : "=r"(__result.__val) : "i"(__val >> 22)); \
    } else { \
      __asm__("padd.ws %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.ws %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

#define __riscv_pmv_s_i32x2(x) __extension__ ({ \
  int32_t __val = (int32_t)(x); \
  int32x2_t __result; \
  if (__builtin_constant_p(__val)) { \
    if (__val >= -512 && __val <= 511) { \
      __asm__("pli.w %0, %1" : "=r"(__result.__val) : "i"(__val)); \
    } else if ((__val & 0x3FFFFF) == 0) { \
      __asm__("plui.w %0, %1" : "=r"(__result.__val) : "i"(__val >> 22)); \
    } else { \
      __asm__("padd.ws %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
    } \
  } else { \
    __asm__("padd.ws %0, x0, %1" : "=r"(__result.__val) : "r"(__val)); \
  } \
  __result; \
})

// Packed Shifts - 64-bit types (RV64)

// Packed shift left logical
#define __riscv_psll_s_u8x8(rs1, shamt) __extension__ ({ \
  uint8x8_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("pslli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_i8x8(rs1, shamt) __extension__ ({ \
  int8x8_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("pslli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_u16x4(rs1, shamt) __extension__ ({ \
  uint16x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("pslli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("pslli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_u32x2(rs1, shamt) __extension__ ({ \
  uint32x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 32) { \
    __asm__("pslli.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 32) { \
    __asm__("pslli.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed saturating shift left arithmetic (immediate only)
#define __riscv_psslai_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psslai.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

#define __riscv_psslai_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psslai.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

// Packed saturating shift with scalar (variable shift amount, signed)
#define __riscv_pssha_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("pssha.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

#define __riscv_pssha_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("pssha.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed saturating shift right arithmetic with rounding and scalar
#define __riscv_psshar_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psshar.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

#define __riscv_psshar_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psshar.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed shift right logical
#define __riscv_psrl_s_u8x8(rs1, shamt) __extension__ ({ \
  uint8x8_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("psrli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psrl.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psrl_s_u16x4(rs1, shamt) __extension__ ({ \
  uint16x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("psrli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psrl.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psrl_s_u32x2(rs1, shamt) __extension__ ({ \
  uint32x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 32) { \
    __asm__("psrli.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psrl.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed shift right arithmetic
#define __riscv_psra_s_i8x8(rs1, shamt) __extension__ ({ \
  int8x8_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("psrai.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psra.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psra_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("psrai.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psra.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psra_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 32) { \
    __asm__("psrai.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psra.ws %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed shift right arithmetic with rounding (immediate only)
#define __riscv_psrari_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psrari.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

#define __riscv_psrari_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psrari.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

#endif

// Packed Shifts - 32-bit types (common to RV32 and RV64)

// Packed shift left logical
#define __riscv_psll_s_u8x4(rs1, shamt) __extension__ ({ \
  uint8x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("pslli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("pslli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_u16x2(rs1, shamt) __extension__ ({ \
  uint16x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("pslli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psll_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("pslli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psll.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed saturating shift left arithmetic (immediate only)
#define __riscv_psslai_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  __asm__("psslai.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

// Packed saturating shift with scalar (variable shift amount, signed)
#define __riscv_pssha_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  __asm__("pssha.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed saturating shift right arithmetic with rounding and scalar
#define __riscv_psshar_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  __asm__("psshar.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  __result; \
})

// Packed shift right logical
#define __riscv_psrl_s_u8x4(rs1, shamt) __extension__ ({ \
  uint8x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("psrli.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psrl.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psrl_s_u16x2(rs1, shamt) __extension__ ({ \
  uint16x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("psrli.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psrl.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed shift right arithmetic
#define __riscv_psra_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 8) { \
    __asm__("psrai.b %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psra.bs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

#define __riscv_psra_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  if (__builtin_constant_p(shamt) && (shamt) < 16) { \
    __asm__("psrai.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  } else { \
    __asm__("psra.hs %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "r"(shamt)); \
  } \
  __result; \
})

// Packed shift right arithmetic with rounding (immediate only)
#define __riscv_psrari_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  __asm__("psrari.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(shamt)); \
  __result; \
})

// Packed Sign Extend

// 32-bit types (common to RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psext_b_i16x2(int16x2_t __rs1) {
  int16x2_t __result;
  __asm__("psext.h.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psext_b_i16x4(int16x4_t __rs1) {
  int16x4_t __result;
  __asm__("psext.dh.b %0, %1" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psext_b_i32x2(int32x2_t __rs1) {
  int32x2_t __result;
  __asm__("psext.dw.b %0, %1" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psext_h_i32x2(int32x2_t __rs1) {
  int32x2_t __result;
  __asm__("psext.dw.h %0, %1" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psext_b_i16x4(int16x4_t __rs1) {
  int16x4_t __result;
  __asm__("psext.h.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psext_b_i32x2(int32x2_t __rs1) {
  int32x2_t __result;
  __asm__("psext.w.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psext_h_i32x2(int32x2_t __rs1) {
  int32x2_t __result;
  __asm__("psext.w.h %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Zero Extend

// 32-bit types (common to RV32 and RV64)
static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pzext_b_i16x2(uint16x2_t __rs1) {
  uint16x2_t __result;
  __asm__("ppaire.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pzext_b_i16x4(uint16x4_t __rs1) {
  uint16x4_t __result;
  __asm__("ppaire.db %0, %1, x0" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pzext_h_i32x2(uint32x2_t __rs1) {
  uint32x2_t __result;
  __asm__("ppaire.dh %0, %1, x0" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pzext_b_i16x4(uint16x4_t __rs1) {
  uint16x4_t __result;
  __asm__("ppaire.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pzext_h_i32x2(uint32x2_t __rs1) {
  uint32x2_t __result;
  __asm__("ppaire.h %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Saturating Absolute Value

// 32-bit types (common to RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_psabs_i8x4(int8x4_t __rs1) {
  int8x4_t __result;
  __asm__("psabs.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psabs_i16x2(int16x2_t __rs1) {
  int16x2_t __result;
  __asm__("psabs.h %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psabs_i8x8(int8x8_t __rs1) {
  int8x8_t __result;
  __asm__("psabs.db %0, %1" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psabs_i16x4(int16x4_t __rs1) {
  int16x4_t __result;
  __asm__("psabs.dh %0, %1" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psabs_i8x8(int8x8_t __rs1) {
  int8x8_t __result;
  __asm__("psabs.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psabs_i16x4(int16x4_t __rs1) {
  int16x4_t __result;
  __asm__("psabs.h %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Addition with Scalar

// 32-bit types (common to RV32 and RV64)
static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u8x4(uint8x4_t __rs1, uint8_t __rs2) {
  uint8x4_t __result;
  __asm__("padd.bs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i8x4(int8x4_t __rs1, int8_t __rs2) {
  int8x4_t __result;
  __asm__("padd.bs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u16x2(uint16x2_t __rs1, uint16_t __rs2) {
  uint16x2_t __result;
  __asm__("padd.hs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i16x2(int16x2_t __rs1, int16_t __rs2) {
  int16x2_t __result;
  __asm__("padd.hs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u8x8(uint8x8_t __rs1, uint8_t __rs2) {
  uint8x8_t __result;
  __asm__("padd.dbs %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i8x8(int8x8_t __rs1, int8_t __rs2) {
  int8x8_t __result;
  __asm__("padd.dbs %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u16x4(uint16x4_t __rs1, uint16_t __rs2) {
  uint16x4_t __result;
  __asm__("padd.dhs %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i16x4(int16x4_t __rs1, int16_t __rs2) {
  int16x4_t __result;
  __asm__("padd.dhs %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u32x2(uint32x2_t __rs1, uint32_t __rs2) {
  uint32x2_t __result;
  __asm__("padd.dws %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i32x2(int32x2_t __rs1, int32_t __rs2) {
  int32x2_t __result;
  __asm__("padd.dws %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u8x8(uint8x8_t __rs1, uint8_t __rs2) {
  uint8x8_t __result;
  __asm__("padd.bs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i8x8(int8x8_t __rs1, int8_t __rs2) {
  int8x8_t __result;
  __asm__("padd.bs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u16x4(uint16x4_t __rs1, uint16_t __rs2) {
  uint16x4_t __result;
  __asm__("padd.hs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i16x4(int16x4_t __rs1, int16_t __rs2) {
  int16x4_t __result;
  __asm__("padd.hs %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_u32x2(uint32x2_t __rs1, uint32_t __rs2) {
  uint32x2_t __result;
  __asm__("padd.ws %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_s_i32x2(int32x2_t __rs1, int32_t __rs2) {
  int32x2_t __result;
  __asm__("padd.ws %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Saturation

// 32-bit types (common to RV32 and RV64)
#define __riscv_pusati_u16x2(rs1, width) __extension__ ({ \
  uint16x2_t __result; \
  __asm__("pusati.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_psati_i16x2(rs1, width) __extension__ ({ \
  int16x2_t __result; \
  __asm__("psati.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

// 64-bit types
#if __riscv_xlen == 32

#define __riscv_pusati_u16x4(rs1, width) __extension__ ({ \
  uint16x4_t __result; \
  __asm__("pusati.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_pusati_u32x2(rs1, width) __extension__ ({ \
  uint32x2_t __result; \
  __asm__("pusati.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_psati_i16x4(rs1, width) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psati.dh %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_psati_i32x2(rs1, width) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psati.dw %0, %1, %2" : "=R"(__result.__val) : "R"((rs1).__val), "i"(width)); \
  __result; \
})

#else // __riscv_xlen == 64

#define __riscv_pusati_u16x4(rs1, width) __extension__ ({ \
  uint16x4_t __result; \
  __asm__("pusati.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_pusati_u32x2(rs1, width) __extension__ ({ \
  uint32x2_t __result; \
  __asm__("pusati.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_psati_i16x4(rs1, width) __extension__ ({ \
  int16x4_t __result; \
  __asm__("psati.h %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

#define __riscv_psati_i32x2(rs1, width) __extension__ ({ \
  int32x2_t __result; \
  __asm__("psati.w %0, %1, %2" : "=r"(__result.__val) : "r"((rs1).__val), "i"(width)); \
  __result; \
})

#endif // __riscv_xlen == 64

// Packed Reduction Sum

// 32-bit types (common to RV32 and RV64)
static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i8x4_i32(int8x4_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("predsum.bs %0, %1, %2" : "=r"(__result) : "r"((uint64_t)__rs1.__val), "r"(__rs2));
#else
  __asm__("predsum.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u8x4_u32(uint8x4_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 64
  __asm__("predsumu.bs %0, %1, %2" : "=r"(__result) : "r"((uint64_t)__rs1.__val), "r"(__rs2));
#else
  __asm__("predsumu.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i16x2_i32(int16x2_t __rs1, int32_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("predsum.hs %0, %1, %2" : "=r"(__result) : "r"((uint64_t)__rs1.__val), "r"(__rs2));
#else
  __asm__("predsum.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u16x2_u32(uint16x2_t __rs1, uint32_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 64
  __asm__("predsumu.hs %0, %1, %2" : "=r"(__result) : "r"((uint64_t)__rs1.__val), "r"(__rs2));
#else
  __asm__("predsumu.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
#endif
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i8x8_i32(int8x8_t __rs1, int32_t __rs2) {
  int32_t __result;
  __asm__("predsum.dbs %0, %1, %2" : "=r"(__result) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u8x8_u32(uint8x8_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("predsumu.dbs %0, %1, %2" : "=r"(__result) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i16x4_i32(int16x4_t __rs1, int32_t __rs2) {
  int32_t __result;
  __asm__("predsum.dhs %0, %1, %2" : "=r"(__result) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u16x4_u32(uint16x4_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("predsumu.dhs %0, %1, %2" : "=r"(__result) : "R"(__rs1.__val), "r"(__rs2));
  return __result;
}

// For 64-bit accumulator on RV32, pass 0 to get the sum, then add to the 64-bit accumulator
// The compiler will generate the 64-bit addition with proper carry handling
static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i8x8_i64(int8x8_t __rs1, int64_t __rs2) {
  int32_t __sum;
  __asm__("predsum.dbs %0, %1, x0" : "=r"(__sum) : "R"(__rs1.__val));
  return (int64_t)__sum + __rs2;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u8x8_u64(uint8x8_t __rs1, uint64_t __rs2) {
  uint32_t __sum;
  __asm__("predsumu.dbs %0, %1, x0" : "=r"(__sum) : "R"(__rs1.__val));
  return (uint64_t)__sum + __rs2;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i16x4_i64(int16x4_t __rs1, int64_t __rs2) {
  int32_t __sum;
  __asm__("predsum.dhs %0, %1, x0" : "=r"(__sum) : "R"(__rs1.__val));
  return (int64_t)__sum + __rs2;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u16x4_u64(uint16x4_t __rs1, uint64_t __rs2) {
  uint32_t __sum;
  __asm__("predsumu.dhs %0, %1, x0" : "=r"(__sum) : "R"(__rs1.__val));
  return (uint64_t)__sum + __rs2;
}

// For 32-bit word reduction on RV32, extract the two words and add in plain C
// The compiler will generate efficient code (likely using wadd/waddu + addd)
static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i32x2_i64(int32x2_t __rs1, int64_t __rs2) {
  int32_t low = (int32_t)(__rs1.__val);
  int32_t high = (int32_t)(__rs1.__val >> 32);
  return (int64_t)low + (int64_t)high + __rs2;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u32x2_u64(uint32x2_t __rs1, uint64_t __rs2) {
  uint32_t low = (uint32_t)(__rs1.__val);
  uint32_t high = (uint32_t)(__rs1.__val >> 32);
  return (uint64_t)low + (uint64_t)high + __rs2;
}

#else // __riscv_xlen == 64

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i8x8_i32(int8x8_t __rs1, int32_t __rs2) {
  int32_t __result;
  __asm__("predsum.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u8x8_u32(uint8x8_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("predsumu.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_predsum_i16x4_i32(int16x4_t __rs1, int32_t __rs2) {
  int32_t __result;
  __asm__("predsum.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u16x4_u32(uint16x4_t __rs1, uint32_t __rs2) {
  uint32_t __result;
  __asm__("predsumu.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i8x8_i64(int8x8_t __rs1, int64_t __rs2) {
  int64_t __result;
  __asm__("predsum.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u8x8_u64(uint8x8_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("predsumu.bs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i16x4_i64(int16x4_t __rs1, int64_t __rs2) {
  int64_t __result;
  __asm__("predsum.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u16x4_u64(uint16x4_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("predsumu.hs %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_predsum_i32x2_i64(int32x2_t __rs1, int64_t __rs2) {
  int64_t __result;
  __asm__("predsum.ws %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_predsumu_u32x2_u64(uint32x2_t __rs1, uint64_t __rs2) {
  uint64_t __result;
  __asm__("predsumu.ws %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Addition and Subtraction

// 32-bit types (common to RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_padd_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("padd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_padd_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("padd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_padd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("padd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_padd_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("padd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_psub_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("psub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_psub_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("psub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psub_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_psub_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("psub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pneg_i8x4(int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("psub.b %0, x0, %1" : "=r"(__result.__val) : "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pneg_i16x2(int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psub.h %0, x0, %1" : "=r"(__result.__val) : "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("padd.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("padd.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("padd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("padd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("padd.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("padd.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psub.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_psub_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("psub.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psub.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psub_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psub.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psub.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psub_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psub.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pneg_i8x8(int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psub.db %0, x0, %1" : "=R"(__result.__val) : "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pneg_i16x4(int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psub.dh %0, x0, %1" : "=R"(__result.__val) : "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pneg_i32x2(int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psub.dw %0, x0, %1" : "=R"(__result.__val) : "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("padd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_padd_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("padd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("padd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_padd_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("padd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("padd.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_padd_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("padd.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_psub_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("psub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psub_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psub.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psub_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psub.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pneg_i8x8(int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psub.b %0, x0, %1" : "=r"(__result.__val) : "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pneg_i16x4(int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psub.h %0, x0, %1" : "=r"(__result.__val) : "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pneg_i32x2(int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psub.w %0, x0, %1" : "=r"(__result.__val) : "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Saturating Addition and Subtraction

// 32-bit types (common to RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_psadd_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("psadd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psadd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("psaddu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("psaddu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pssub_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("pssub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pssub_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pssub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pssubu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pssubu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psadd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psadd.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psadd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psadd.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("psaddu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psaddu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psaddu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pssub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("pssub.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pssub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pssub.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pssub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pssub.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pssubu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pssubu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pssubu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_psadd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("psadd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psadd.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("psaddu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psaddu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psaddu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psaddu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pssub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("pssub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pssub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pssub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pssub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pssub.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pssubu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pssubu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pssubu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pssubu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Averaging Addition and Subtraction

// 32-bit types (common to RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_paadd_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("paadd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_paadd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("paadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("paaddu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("paaddu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pasub_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("pasub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pasub_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pasub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pasubu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pasubu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_paadd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("paadd.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_paadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("paadd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_paadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("paadd.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("paaddu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("paaddu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("paaddu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pasub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("pasub.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pasub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pasub.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pasub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pasub.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pasubu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pasubu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pasubu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_paadd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("paadd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_paadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("paadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_paadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("paadd.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("paaddu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("paaddu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_paaddu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("paaddu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pasub_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("pasub.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pasub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pasub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pasub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pasub.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pasubu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pasubu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pasubu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pasubu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Absolute Value and Absolute Difference

// 32-bit types (common to RV32 and RV64)
static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pabs_i8x4(int8x4_t __rs1) {
  uint8x4_t __result;
  __asm__("pabd.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pabs_i16x2(int16x2_t __rs1) {
  uint16x2_t __result;
  __asm__("pabd.h %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pabd_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pabd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pabd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pabd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pabdu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pabdu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabs_i8x8(int8x8_t __rs1) {
  uint8x8_t __result;
  __asm__("pabd.db %0, %1, x0" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabs_i16x4(int16x4_t __rs1) {
  uint16x4_t __result;
  __asm__("pabd.dh %0, %1, x0" : "=R"(__result.__val) : "R"(__rs1.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pabd.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pabd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pabdu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pabdu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabs_i8x8(int8x8_t __rs1) {
  uint8x8_t __result;
  __asm__("pabd.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabs_i16x4(int16x4_t __rs1) {
  uint16x4_t __result;
  __asm__("pabd.h %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabd_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pabd.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pabd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("pabdu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pabdu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pabdu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// ========================================================================
// Packed Merge
// ========================================================================
// Bitwise merge using mask in __rd. If mask bit is 0, select bit from __rs1,
// else select bit from __rs2.

// 32-bit types
static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u8x4(uint8x4_t __rd, uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i8x4(uint8x4_t __rd, int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u16x2(uint16x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i16x2(uint16x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u8x8(uint8x8_t __rd, uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i8x8(uint8x8_t __rd, int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u16x4(uint16x4_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i16x4(uint16x4_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u32x2(uint32x2_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i32x2(uint32x2_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u8x8(uint8x8_t __rd, uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i8x8(uint8x8_t __rd, int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u16x4(uint16x4_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i16x4(uint16x4_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_u32x2(uint32x2_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmerge_i32x2(uint32x2_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __result.__val = (__rs1.__val & ~__rd.__val) | (__rs2.__val & __rd.__val);
  return __result;
}

#endif // __riscv_xlen == 64

// ========================================================================
// Packed Absolute Difference Sum
// ========================================================================

// 32-bit types
static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pabdsumu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 32
  __asm__("pabdsumu.b %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pabdsumu.b %0, %1, %2" : "=r"(__result) : "r"((uint64_t)__rs1.__val), "r"((uint64_t)__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pabdsumau_u8x4_u32(uint32_t __rd, uint8x4_t __rs1, uint8x4_t __rs2) {
  
  uint32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("pabdsumau.b %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pabdsumau.b %0, %1, %2" : "+r"(__result) : "r"((uint64_t)__rs1.__val), "r"((uint64_t)__rs2.__val));
#endif
  return __result;
}

// 64-bit types (RV64 only)
#if __riscv_xlen == 64

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pabdsumu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint64_t __result;
  __asm__("pabdsumu.b %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pabdsumau_u8x8_u64(uint64_t __rd, uint8x8_t __rs1, uint8x8_t __rs2) {
  
  uint64_t __result = __rd;
  __asm__("pabdsumau.b %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// ========================================================================
// Packed SH1ADD and SSH1SADD
// ========================================================================

// 32-bit types
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psh1add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("psh1add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pssh1sadd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pssh1sadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psh1add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psh1add.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psh1add_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psh1add.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psh1add.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psh1add.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pssh1sadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pssh1sadd.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pssh1sadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pssh1sadd.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psh1add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("psh1add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_psh1add_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("psh1add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psh1add.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_psh1add_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("psh1add.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pssh1sadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pssh1sadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pssh1sadd_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pssh1sadd.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// ========================================================================
// Packed Pair
// ========================================================================

// 32-bit types
static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("ppaireo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("ppaireo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("ppairoe.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("ppairoe.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// ppaire for 16-bit elements uses different instructions on RV32 vs RV64
#if __riscv_xlen == 32

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pack %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pack %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("ppaireo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("ppaireo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("ppairoe.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("ppairoe.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types
#if __riscv_xlen == 32

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaire.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppaire.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaireo.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppaireo.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairoe.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppairoe.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairo.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppairo.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaire.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppaire.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaireo.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppaireo.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairoe.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppairoe.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairo.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppairo.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
  return __result;
}

#else // __riscv_xlen == 64

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaireo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppaireo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairoe.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppairoe.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaireo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppaireo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairoe.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppairoe.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// 32-bit element pair operations
#if __riscv_xlen == 32

// On RV32, manually extract and pack the bits
static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  // Extract even elements (low 32 bits) from each pair
  uint32_t __rs1_lo = (uint32_t)__rs1.__val;
  uint32_t __rs2_lo = (uint32_t)__rs2.__val;
  // Pack them together
  __result.__val = ((uint64_t)__rs2_lo << 32) | __rs1_lo;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  uint32_t __rs1_lo = (uint32_t)__rs1.__val;
  uint32_t __rs2_lo = (uint32_t)__rs2.__val;
  __result.__val = ((uint64_t)__rs2_lo << 32) | __rs1_lo;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  // Extract even from __rs1 (low 32 bits), odd from __rs2 (high 32 bits)
  uint32_t __rs1_lo = (uint32_t)__rs1.__val;
  uint32_t __rs2_hi = (uint32_t)(__rs2.__val >> 32);
  __result.__val = ((uint64_t)__rs2_hi << 32) | __rs1_lo;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  uint32_t __rs1_lo = (uint32_t)__rs1.__val;
  uint32_t __rs2_hi = (uint32_t)(__rs2.__val >> 32);
  __result.__val = ((uint64_t)__rs2_hi << 32) | __rs1_lo;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  // Extract odd from __rs1 (high 32 bits), even from __rs2 (low 32 bits)
  uint32_t __rs1_hi = (uint32_t)(__rs1.__val >> 32);
  uint32_t __rs2_lo = (uint32_t)__rs2.__val;
  __result.__val = ((uint64_t)__rs2_lo << 32) | __rs1_hi;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  uint32_t __rs1_hi = (uint32_t)(__rs1.__val >> 32);
  uint32_t __rs2_lo = (uint32_t)__rs2.__val;
  __result.__val = ((uint64_t)__rs2_lo << 32) | __rs1_hi;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  // Extract odd elements (high 32 bits) from each pair
  uint32_t __rs1_hi = (uint32_t)(__rs1.__val >> 32);
  uint32_t __rs2_hi = (uint32_t)(__rs2.__val >> 32);
  __result.__val = ((uint64_t)__rs2_hi << 32) | __rs1_hi;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  uint32_t __rs1_hi = (uint32_t)(__rs1.__val >> 32);
  uint32_t __rs2_hi = (uint32_t)(__rs2.__val >> 32);
  __result.__val = ((uint64_t)__rs2_hi << 32) | __rs1_hi;
  return __result;
}

#else // __riscv_xlen == 64

// On RV64, use the instructions
static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pack %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaire_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pack %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("ppaireo.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppaireo_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("ppaireo.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("ppairoe.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairoe_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("ppairoe.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("ppairo.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_ppairo_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("ppairo.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Multiplication with Horizontal Addition

// 32-bit types

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm4add_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int32_t __result;
  __asm__("pm4add.b %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2add_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2add.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm4adda_i8x4(int32_t __rd, int8x4_t __rs1, int8x4_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm4adda.b %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm2adda.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2add_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2add.hx %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_x_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm2adda.hx %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pm4addu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint32_t __result;
  __asm__("pm4addu.b %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pm2addu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result;
  __asm__("pm2addu.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pm4addau_u8x4(uint32_t __rd, uint8x4_t __rs1, uint8x4_t __rs2) {
  uint32_t __result = __rd;
  __asm__("pm4addau.b %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_pm2addau_u16x2(uint32_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result = __rd;
  __asm__("pm2addau.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pmq2add_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pmq2add.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pmq2adda_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pmq2adda.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pmqr2add_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pmqr2add.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pmqr2adda_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pmqr2adda.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2sadd_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2sadd.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2sadd_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2sadd.hx %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2sub.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm2suba.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2sub.hx %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_x_i16x2(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm2suba.hx %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm4addsu_i8x4(int8x4_t __rs1, uint8x4_t __rs2) {
  int32_t __result;
  __asm__("pm4addsu.b %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2addsu_i16x2(int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result;
  __asm__("pm2addsu.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm4addasu_i8x4(int32_t __rd, int8x4_t __rs1, uint8x4_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm4addasu.b %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_pm2addasu_i16x2(int32_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result = __rd;
  __asm__("pm2addasu.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// 64-bit types

#if __riscv_xlen == 64

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4add_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int32x2_t __result;
  __asm__("pm4add.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4adda_i8x8(int32x2_t __rd, int8x8_t __rs1, int8x8_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm4adda.b %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm2adda.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2add_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2add.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_x_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm2adda.hx %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4addu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint32x2_t __result;
  __asm__("pm4addu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2addu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result;
  __asm__("pm2addu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4addau_u8x8(uint32x2_t __rd, uint8x8_t __rs1, uint8x8_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pm4addau.b %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2addau_u16x4(uint32x2_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pm2addau.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmq2add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmq2add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmq2adda_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmq2adda.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqr2add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmqr2add.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqr2adda_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqr2adda.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2sadd_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2sadd.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2sadd_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2sadd.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2sub.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm2suba.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2sub.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_x_i16x4(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm2suba.hx %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4addsu_i8x8(int8x8_t __rs1, uint8x8_t __rs2) {
  int32x2_t __result;
  __asm__("pm4addsu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2addsu_i16x4(int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pm2addsu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm4addasu_i8x8(int32x2_t __rd, int8x8_t __rs1, uint8x8_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm4addasu.b %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pm2addasu_i16x4(int32x2_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pm2addasu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2add_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pm2add.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2adda.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2add_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pm2add.wx %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2adda_x_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2adda.wx %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm2addu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result;
  __asm__("pm2addu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm2addau_u32x2(uint64_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result = __rd;
  __asm__("pm2addau.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pmq2add_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pmq2add.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pmq2adda_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pmq2adda.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pmqr2add_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pmqr2add.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pmqr2adda_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pmqr2adda.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pm2sub.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2suba.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2sub_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("pm2sub.wx %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2suba_x_i32x2(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2suba.wx %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2addsu_i32x2(int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result;
  __asm__("pm2addsu.w %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm2addasu_i32x2(int64_t __rd, int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm2addasu.w %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm4add_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int64_t __result;
  __asm__("pm4add.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm4adda_i16x4(int64_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm4adda.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm4addu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint64_t __result;
  __asm__("pm4addu.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_pm4addau_u16x4(uint64_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint64_t __result = __rd;
  __asm__("pm4addau.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm4addsu_i16x4(int16x4_t __rs1, uint16x4_t __rs2) {
  int64_t __result;
  __asm__("pm4addsu.h %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_pm4addasu_i16x4(int64_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int64_t __result = __rd;
  __asm__("pm4addasu.h %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Exchanged Addition and Subtraction (RV64 only - 32-bit element)
static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pas_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pas.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psa_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psa.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_psas_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("psas.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pssa_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pssa.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_paas_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("paas.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pasa_x_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pasa.wx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Exchanged Addition and Subtraction (32-bit types - both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pas_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psa_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_psas_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("psas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pssa_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pssa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_paas_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("paas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pasa_x_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pasa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Exchanged Addition and Subtraction (64-bit types - both RV32 and RV64)
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pas_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pas.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psa_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("psa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("psa.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_psas_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("psas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("psas.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pssa_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pssa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pssa.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_paas_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("paas.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("paas.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pasa_x_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pasa.hx %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pasa.dhx %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

// Packed Comparisons (32-bit types - both RV32 and RV64)
static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmseq_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmseq.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmseq_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmseq.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmseq_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmseq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmseq_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmseq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmslt_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmslt.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmslt_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmslt.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmsgt_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmslt.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmsgt_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmslt.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmsltu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmsltu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmsltu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmsltu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmsgtu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmsltu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmsgtu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmsltu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
  return __result;
}

// Packed Comparisons (64-bit types - both RV32 and RV64)
static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmseq_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmseq_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmseq_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmseq_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmseq_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmseq_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmseq.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmseq.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmslt_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmslt.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmslt_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmslt.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmslt_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmslt.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmsgt_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmslt.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmsgt_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmslt.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmsgt_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmslt.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmslt.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmsltu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmsltu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmsltu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmsltu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmsltu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmsltu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmsgtu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmsltu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmsgtu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmsltu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmsgtu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmsltu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs2.__val), "r"(__rs1.__val));
#else
  __asm__("pmsltu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs2.__val), "R"(__rs1.__val));
#endif
  return __result;
}

// Packed Minimum and Maximum (32-bit types - both RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pmin_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("pmin.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmin_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmin.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pminu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pminu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pminu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pminu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pmax_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  int8x4_t __result;
  __asm__("pmax.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmax_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmax.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pmaxu_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x4_t __result;
  __asm__("pmaxu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmaxu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmaxu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Minimum and Maximum (64-bit types - both RV32 and RV64)
static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pmin_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmin.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmin.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmin_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmin.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmin.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmin_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmin.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmin.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pminu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pminu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pminu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pminu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pminu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pminu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pminu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pminu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pminu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pmax_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  int8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmax.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmax.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmax_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmax.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmax.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmax_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmax.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmax.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pmaxu_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint8x8_t __result;
#if __riscv_xlen == 64
  __asm__("pmaxu.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmaxu.db %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmaxu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
#if __riscv_xlen == 64
  __asm__("pmaxu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmaxu.dh %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaxu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
#if __riscv_xlen == 64
  __asm__("pmaxu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("pmaxu.dw %0, %1, %2" : "=R"(__result.__val) : "R"(__rs1.__val), "R"(__rs2.__val));
#endif
  return __result;
}

// Packed Multiply High (32-bit types - both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulh.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhr_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulhr.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhu_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmulhu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhru_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result;
  __asm__("pmulhru.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_i16x2(int16x2_t __rs1, uint16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulhsu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhrsu_i16x2(int16x2_t __rs1, uint16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulhrsu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Multiply High (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulh_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulh.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulh.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhr_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulhr.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhr_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulhr.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhu_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pmulhu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhu_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pmulhu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhru_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pmulhru.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhru_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pmulhru.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_i16x4(int16x4_t __rs1, uint16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulhsu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_i32x2(int32x2_t __rs1, uint32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulhsu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhrsu_i16x4(int16x4_t __rs1, uint16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulhrsu.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhrsu_i32x2(int32x2_t __rs1, uint32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulhrsu.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Multiply High Accumulate (32-bit types - both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_i16x2(int16x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhacc.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhracc_i16x2(int16x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhracc.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccu_u16x2(uint16x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result = __rd;
  __asm__("pmhaccu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhraccu_u16x2(uint16x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x2_t __result = __rd;
  __asm__("pmhraccu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_i16x2(int16x2_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhaccsu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhraccsu_i16x2(int16x2_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhraccsu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Multiply High Accumulate (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_i16x4(int16x4_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhacc.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_i32x2(int32x2_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhacc.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhracc_i16x4(int16x4_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhracc.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhracc_i32x2(int32x2_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhracc.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhaccu_u16x4(uint16x4_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result = __rd;
  __asm__("pmhaccu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccu_u32x2(uint32x2_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pmhaccu.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhraccu_u16x4(uint16x4_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint16x4_t __result = __rd;
  __asm__("pmhraccu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhraccu_u32x2(uint32x2_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pmhraccu.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_i16x4(int16x4_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhaccsu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_i32x2(int32x2_t __rd, int32x2_t __rs1, uint32x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhaccsu.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhraccsu_i16x4(int16x4_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhraccsu.h %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhraccsu_i32x2(int32x2_t __rd, int32x2_t __rs1, uint32x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhraccsu.w %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed "Q-format" Multiplication (32-bit types - both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulq_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulqr_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  int16x2_t __result;
  __asm__("pmulqr.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed "Q-format" Multiplication (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulq_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulq.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulq_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulq.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulqr_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  int16x4_t __result;
  __asm__("pmulqr.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulqr_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  int32x2_t __result;
  __asm__("pmulqr.w %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Multiply Parts (32-bit types - both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_b00_i16x2(int8x4_t __rs1, int8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmul.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_b01_i16x2(int8x4_t __rs1, int8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmul.h.b01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_b11_i16x2(int8x4_t __rs1, int8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmul.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b00_u16x2(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x2_t __result;
  __asm__("pmulu.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b01_u16x2(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x2_t __result;
  __asm__("pmulu.h.b01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b11_u16x2(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x2_t __result;
  __asm__("pmulu.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_b00_i16x2(int8x4_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulsu.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_b11_i16x2(int8x4_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulsu.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mul_h00_i32(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("pmul.w.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mul.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mul_h01_i32(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("pmul.w.h01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mul.h01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mul_h11_i32(int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("pmul.w.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mul.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mulu_h00_u32(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 64
  __asm__("pmulu.w.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mulu.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mulu_h01_u32(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 64
  __asm__("pmulu.w.h01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mulu.h01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_mulu_h11_u32(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result;
#if __riscv_xlen == 64
  __asm__("pmulu.w.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mulu.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulsu_h00_i32(int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("pmulsu.w.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mulsu.h00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulsu_h11_i32(int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 64
  __asm__("pmulsu.w.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mulsu.h11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

// Packed Multiply Parts (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmul_b00_i16x4(int8x8_t __rs1, int8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmul.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmul_b01_i16x4(int8x8_t __rs1, int8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmul.h.b01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmul_b11_i16x4(int8x8_t __rs1, int8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmul.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b00_u16x4(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint16x4_t __result;
  __asm__("pmulu.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b01_u16x4(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint16x4_t __result;
  __asm__("pmulu.h.b01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulu_b11_u16x4(uint8x8_t __rs1, uint8x8_t __rs2) {
  uint16x4_t __result;
  __asm__("pmulu.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_b00_i16x4(int8x8_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulsu.h.b00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_b11_i16x4(int8x8_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulsu.h.b11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_h00_i32x2(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmul.w.h00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_h01_i32x2(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmul.w.h01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmul_h11_i32x2(int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmul.w.h11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_h00_u32x2(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result;
  __asm__("pmulu.w.h00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_h01_u32x2(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result;
  __asm__("pmulu.w.h01 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulu_h11_u32x2(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result;
  __asm__("pmulu.w.h11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_h00_i32x2(int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulsu.w.h00 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulsu_h11_i32x2(int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulsu.w.h11 %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mul_w00_i64(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("mul.w00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mul_w01_i64(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("mul.w01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mul_w11_i64(int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result;
  __asm__("mul.w11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_mulu_w00_u64(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result;
  __asm__("mulu.w00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_mulu_w01_u64(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result;
  __asm__("mulu.w01 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_mulu_w11_u64(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result;
  __asm__("mulu.w11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mulsu_w00_i64(int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result;
  __asm__("mulsu.w00 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mulsu_w11_i64(int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result;
  __asm__("mulsu.w11 %0, %1, %2" : "=r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Multiply Parts Accumulate (32-bit types - both RV32 and RV64)

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_macc_h00_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmacc.w.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("macc.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_macc_h01_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmacc.w.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("macc.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_macc_h11_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmacc.w.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("macc.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_maccu_h00_u32(uint32_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmaccu.w.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("maccu.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_maccu_h01_u32(uint32_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmaccu.w.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("maccu.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_maccu_h11_u32(uint32_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmaccu.w.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("maccu.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_maccsu_h00_i32(int32_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmaccsu.w.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("maccsu.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_maccsu_h11_i32(int32_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmaccsu.w.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("maccsu.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

// Packed Multiply Parts Accumulate (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmacc_h00_i32x2(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmacc.w.h00 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmacc_h01_i32x2(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmacc.w.h01 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmacc_h11_i32x2(int32x2_t __rd, int16x4_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmacc.w.h11 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaccu_h00_u32x2(uint32x2_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pmaccu.w.h00 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaccu_h01_u32x2(uint32x2_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pmaccu.w.h01 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaccu_h11_u32x2(uint32x2_t __rd, uint16x4_t __rs1, uint16x4_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pmaccu.w.h11 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaccsu_h00_i32x2(int32x2_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmaccsu.w.h00 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmaccsu_h11_i32x2(int32x2_t __rd, int16x4_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmaccsu.w.h11 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_macc_w00_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("macc.w00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_macc_w01_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("macc.w01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_macc_w11_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("macc.w11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_maccu_w00_u64(uint64_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result = __rd;
  __asm__("maccu.w00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_maccu_w01_u64(uint64_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result = __rd;
  __asm__("maccu.w01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_maccu_w11_u64(uint64_t __rd, uint32x2_t __rs1, uint32x2_t __rs2) {
  uint64_t __result = __rd;
  __asm__("maccu.w11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_maccsu_w00_i64(int64_t __rd, int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("maccsu.w00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_maccsu_w11_i64(int64_t __rd, int32x2_t __rs1, uint32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("maccsu.w11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed "Q-format" Multiply Parts Accumulate (32-bit types - both RV32 and RV64)

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqacc_h00_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqacc.w.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqacc.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqacc_h01_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqacc.w.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqacc.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqacc_h11_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqacc.w.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqacc.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqracc_h00_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqracc.w.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqracc.h00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqracc_h01_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqracc.w.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqracc.h01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mqracc_h11_i32(int32_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 64
  __asm__("pmqracc.w.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#else
  __asm__("mqracc.h11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
#endif
  return __result;
}

// Packed "Q-format" Multiply Parts Accumulate (64-bit types - RV64 only)
#if __riscv_xlen == 64
static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqacc_h00_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqacc.w.h00 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqacc_h01_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqacc.w.h01 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqacc_h11_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqacc.w.h11 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqracc_h00_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqracc.w.h00 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqracc_h01_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqracc.w.h01 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqracc_h11_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqracc.w.h11 %0, %1, %2" : "+r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqacc_w00_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqacc.w00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqacc_w01_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqacc.w01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqacc_w11_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqacc.w11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqracc_w00_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqracc.w00 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqracc_w01_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqracc.w01 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_mqracc_w11_i64(int64_t __rd, int32x2_t __rs1, int32x2_t __rs2) {
  int64_t __result = __rd;
  __asm__("mqracc.w11 %0, %1, %2" : "+r"(__result) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

#endif // __riscv_xlen == 64

// Packed Multiply High Parts

// 32-bit types (work on both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_b0_i16x2(int16x2_t __rs1, int8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulh.h.b0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_b1_i16x2(int16x2_t __rs1, int8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulh.h.b1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_b0_i16x2(int16x2_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulhsu.h.b0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_b1_i16x2(int16x2_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result;
  __asm__("pmulhsu.h.b1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulh_h0_i32(int32_t __rs1, int16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulh.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulh.w.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulh_h1_i32(int32_t __rs1, int16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulh.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulh.w.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulhsu_h0_i32(int32_t __rs1, uint16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhsu.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulhsu.w.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mulhsu_h1_i32(int32_t __rs1, uint16x2_t __rs2) {
  int32_t __result;
#if __riscv_xlen == 32
  __asm__("mulhsu.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmulhsu.w.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

// 64-bit types (RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulh_b0_i16x4(int16x4_t __rs1, int8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulh.h.b0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulh_b1_i16x4(int16x4_t __rs1, int8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulh.h.b1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_b0_i16x4(int16x4_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulhsu.h.b0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_b1_i16x4(int16x4_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result;
  __asm__("pmulhsu.h.b1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_h0_i32x2(int32x2_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulh.w.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulh_h1_i32x2(int32x2_t __rs1, int16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulh.w.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_h0_i32x2(int32x2_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulhsu.w.h0 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmulhsu_h1_i32x2(int32x2_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result;
  __asm__("pmulhsu.w.h1 %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}
#endif // __riscv_xlen == 64

// Packed Multiply High Parts Accumulate

// 32-bit types (work on both RV32 and RV64)
static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_b0_i16x2(int16x2_t __rd, int16x2_t __rs1, int8x4_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhacc.h.b0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_b1_i16x2(int16x2_t __rd, int16x2_t __rs1, int8x4_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhacc.h.b1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_b0_i16x2(int16x2_t __rd, int16x2_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhaccsu.h.b0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_b1_i16x2(int16x2_t __rd, int16x2_t __rs1, uint8x4_t __rs2) {
  int16x2_t __result = __rd;
  __asm__("pmhaccsu.h.b1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhacc_h0_i32(int32_t __rd, int32_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhacc.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhacc.w.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhacc_h1_i32(int32_t __rd, int32_t __rs1, int16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhacc.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhacc.w.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhaccsu_h0_i32(int32_t __rd, int32_t __rs1, uint16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhaccsu.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhaccsu.w.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_mhaccsu_h1_i32(int32_t __rd, int32_t __rs1, uint16x2_t __rs2) {
  int32_t __result = __rd;
#if __riscv_xlen == 32
  __asm__("mhaccsu.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#else
  __asm__("pmhaccsu.w.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
#endif
  return __result;
}

// 64-bit types (RV64 only)
#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_b0_i16x4(int16x4_t __rd, int16x4_t __rs1, int8x8_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhacc.h.b0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_b1_i16x4(int16x4_t __rd, int16x4_t __rs1, int8x8_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhacc.h.b1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_b0_i16x4(int16x4_t __rd, int16x4_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhaccsu.h.b0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_b1_i16x4(int16x4_t __rd, int16x4_t __rs1, uint8x8_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pmhaccsu.h.b1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_h0_i32x2(int32x2_t __rd, int32x2_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhacc.w.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhacc_h1_i32x2(int32x2_t __rd, int32x2_t __rs1, int16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhacc.w.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_h0_i32x2(int32x2_t __rd, int32x2_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhaccsu.w.h0 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmhaccsu_h1_i32x2(int32x2_t __rd, int32x2_t __rs1, uint16x4_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmhaccsu.w.h1 %0, %1, %2" : "+r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}
#endif // __riscv_xlen == 64

// Packed Logical Operations

// 32-bit types (work on both RV32 and RV64)
static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pand_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  return (int8x4_t){__rs1.__val & __rs2.__val};
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pand_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  return (uint8x4_t){__rs1.__val & __rs2.__val};
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pand_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  return (int16x2_t){__rs1.__val & __rs2.__val};
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pand_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  return (uint16x2_t){__rs1.__val & __rs2.__val};
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_por_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  return (int8x4_t){__rs1.__val | __rs2.__val};
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_por_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  return (uint8x4_t){__rs1.__val | __rs2.__val};
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_por_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  return (int16x2_t){__rs1.__val | __rs2.__val};
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_por_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  return (uint16x2_t){__rs1.__val | __rs2.__val};
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pxor_i8x4(int8x4_t __rs1, int8x4_t __rs2) {
  return (int8x4_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pxor_u8x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  return (uint8x4_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pxor_i16x2(int16x2_t __rs1, int16x2_t __rs2) {
  return (int16x2_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pxor_u16x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  return (uint16x2_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pnot_i8x4(int8x4_t __rs1) {
  return (int8x4_t){~__rs1.__val};
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pnot_u8x4(uint8x4_t __rs1) {
  return (uint8x4_t){~__rs1.__val};
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pnot_i16x2(int16x2_t __rs1) {
  return (int16x2_t){~__rs1.__val};
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pnot_u16x2(uint16x2_t __rs1) {
  return (uint16x2_t){~__rs1.__val};
}

// 64-bit types (work on both RV32 and RV64)
static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pand_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  return (int8x8_t){__rs1.__val & __rs2.__val};
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pand_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  return (uint8x8_t){__rs1.__val & __rs2.__val};
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pand_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  return (int16x4_t){__rs1.__val & __rs2.__val};
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pand_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  return (uint16x4_t){__rs1.__val & __rs2.__val};
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pand_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  return (int32x2_t){__rs1.__val & __rs2.__val};
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pand_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  return (uint32x2_t){__rs1.__val & __rs2.__val};
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_por_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  return (int8x8_t){__rs1.__val | __rs2.__val};
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_por_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  return (uint8x8_t){__rs1.__val | __rs2.__val};
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_por_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  return (int16x4_t){__rs1.__val | __rs2.__val};
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_por_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  return (uint16x4_t){__rs1.__val | __rs2.__val};
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_por_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  return (int32x2_t){__rs1.__val | __rs2.__val};
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_por_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  return (uint32x2_t){__rs1.__val | __rs2.__val};
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pxor_i8x8(int8x8_t __rs1, int8x8_t __rs2) {
  return (int8x8_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pxor_u8x8(uint8x8_t __rs1, uint8x8_t __rs2) {
  return (uint8x8_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pxor_i16x4(int16x4_t __rs1, int16x4_t __rs2) {
  return (int16x4_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pxor_u16x4(uint16x4_t __rs1, uint16x4_t __rs2) {
  return (uint16x4_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pxor_i32x2(int32x2_t __rs1, int32x2_t __rs2) {
  return (int32x2_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pxor_u32x2(uint32x2_t __rs1, uint32x2_t __rs2) {
  return (uint32x2_t){__rs1.__val ^ __rs2.__val};
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pnot_i8x8(int8x8_t __rs1) {
  return (int8x8_t){~__rs1.__val};
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pnot_u8x8(uint8x8_t __rs1) {
  return (uint8x8_t){~__rs1.__val};
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pnot_i16x4(int16x4_t __rs1) {
  return (int16x4_t){~__rs1.__val};
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pnot_u16x4(uint16x4_t __rs1) {
  return (uint16x4_t){~__rs1.__val};
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pnot_i32x2(int32x2_t __rs1) {
  return (int32x2_t){~__rs1.__val};
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pnot_u32x2(uint32x2_t __rs1) {
  return (uint32x2_t){~__rs1.__val};
}

// Packed Widening Addition and Subtraction (RV32 only)

#if __riscv_xlen == 32
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwadd_i16x4(int8x4_t __rs1, int8x4_t __rs2) {
  int16x4_t __result;
  __asm__("pwadd.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwadd_i32x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result;
  __asm__("pwadd.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwaddu_u16x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pwaddu.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwaddu_u32x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pwaddu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwsub_i16x4(int8x4_t __rs1, int8x4_t __rs2) {
  int16x4_t __result;
  __asm__("pwsub.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwsub_i32x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result;
  __asm__("pwsub.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwsubu_u16x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pwsubu.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwsubu_u32x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pwsubu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Widening Addition and Subtraction Accumulate (RV32 only)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwadda_i16x4(int16x4_t __rd, int8x4_t __rs1, int8x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pwadda.b %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwadda_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pwadda.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwaddau_u16x4(uint16x4_t __rd, uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x4_t __result = __rd;
  __asm__("pwaddau.b %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwaddau_u32x2(uint32x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pwaddau.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwsuba_i16x4(int16x4_t __rd, int8x4_t __rs1, int8x4_t __rs2) {
  int16x4_t __result = __rd;
  __asm__("pwsuba.b %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwsuba_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pwsuba.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwsubau_u16x4(uint16x4_t __rd, uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x4_t __result = __rd;
  __asm__("pwsubau.b %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwsubau_u32x2(uint32x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pwsubau.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Widening Multiply (RV32 only)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwmul_i16x4(int8x4_t __rs1, int8x4_t __rs2) {
  int16x4_t __result;
  __asm__("pwmul.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmul_i32x2(int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result;
  __asm__("pwmul.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwmulu_u16x4(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint16x4_t __result;
  __asm__("pwmulu.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmulu_u32x2(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result;
  __asm__("pwmulu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwmulsu_u16x4(int8x4_t __rs1, uint8x4_t __rs2) {
  int16x4_t __result;
  __asm__("pwmulsu.b %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmulsu_u32x2(int16x2_t __rs1, uint16x2_t __rs2) {
  int32x2_t __result;
  __asm__("pwmulsu.h %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Widening Multiply Accumulate (RV32 only)

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmacc_i32x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pwmacc.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmaccu_u32x2(uint32x2_t __rd, uint16x2_t __rs1, uint16x2_t __rs2) {
  uint32x2_t __result = __rd;
  __asm__("pwmaccu.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwmaccsu_u32x2(int32x2_t __rd, int16x2_t __rs1, uint16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pwmaccsu.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Q-format Multiply with Widening Accumulate (RV32 only)

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqwacc_i16x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqwacc.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pmqrwacc_i16x2(int32x2_t __rd, int16x2_t __rs1, int16x2_t __rs2) {
  int32x2_t __result = __rd;
  __asm__("pmqrwacc.h %0, %1, %2" : "+R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Widening Shift (RV32 only)

#define __riscv_pwsll_s_u16x4(rs1, shamt) __extension__ ({ \
  uint16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pwslli.b %0, %1, %2" : "=R"(__result) : "r"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pwsll.bs %0, %1, %2" : "=R"(__result) : "r"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pwsll_s_u32x2(rs1, shamt) __extension__ ({ \
  uint32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pwslli.h %0, %1, %2" : "=R"(__result) : "r"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pwsll.hs %0, %1, %2" : "=R"(__result) : "r"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pwsla_s_i16x4(rs1, shamt) __extension__ ({ \
  int16x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pwslai.b %0, %1, %2" : "=R"(__result) : "r"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pwsla.bs %0, %1, %2" : "=R"(__result) : "r"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pwsla_s_i32x2(rs1, shamt) __extension__ ({ \
  int32x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pwslai.h %0, %1, %2" : "=R"(__result) : "r"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pwsla.hs %0, %1, %2" : "=R"(__result) : "r"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed Narrowing Shift (RV32 only)

#define __riscv_pnsrl_s_u8x4(rs1, shamt) __extension__ ({ \
  uint8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnsrli.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsrl.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnsrl_s_u16x2(rs1, shamt) __extension__ ({ \
  uint16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnsrli.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsrl.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnsra_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnsrai.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsra.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnsra_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnsrai.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsra.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnsrar_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnsrari.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsrar.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnsrar_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnsrari.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnsrar.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed Narrowing Clip (RV32 only)

#define __riscv_pnclipu_s_u8x4(rs1, shamt) __extension__ ({ \
  uint8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnclipiu.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipu.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclipu_s_u16x2(rs1, shamt) __extension__ ({ \
  uint16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnclipiu.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipu.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclipru_s_u8x4(rs1, shamt) __extension__ ({ \
  uint8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnclipriu.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipru.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclipru_s_u16x2(rs1, shamt) __extension__ ({ \
  uint16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnclipriu.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipru.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclip_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnclipi.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclip.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclip_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnclipi.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclip.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclipr_s_i8x4(rs1, shamt) __extension__ ({ \
  int8x4_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 15) { \
    __asm__("pnclipri.b %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipr.bs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

#define __riscv_pnclipr_s_i16x2(rs1, shamt) __extension__ ({ \
  int16x2_t __result; \
  unsigned __shamt_u = (unsigned)(shamt); \
  if (__builtin_constant_p(__shamt_u) && __shamt_u <= 31) { \
    __asm__("pnclipri.h %0, %1, %2" : "=r"(__result) : "R"((rs1)), "i"(__shamt_u)); \
  } else { \
    __asm__("pnclipr.hs %0, %1, %2" : "=r"(__result) : "R"((rs1)), "r"(__shamt_u)); \
  } \
  __result; \
})

// Packed Widening Convert (RV32 only)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvt_i16x4(int8x4_t __rs1) {
  int16x4_t __result;
  __asm__("pwadd.b %0, %1, x0" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvt_i32x2(int16x2_t __rs1) {
  int32x2_t __result;
  __asm__("pwadd.h %0, %1, x0" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvtu_u16x4(uint8x4_t __rs1) {
  uint16x4_t __result;
  __asm__("wzip8p %0, %1, x0" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvtu_u32x2(uint16x2_t __rs1) {
  uint32x2_t __result;
  __asm__("wzip16p %0, %1, x0" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_i16x4(int8x4_t __rs1) {
  int16x4_t __result;
  __asm__("wzip8p %0, x0, %1" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_u16x4(uint8x4_t __rs1) {
  uint16x4_t __result;
  __asm__("wzip8p %0, x0, %1" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_i32x2(int16x2_t __rs1) {
  int32x2_t __result;
  __asm__("wzip16p %0, x0, %1" : "=R"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_u32x2(uint16x2_t __rs1) {
  uint32x2_t __result;
  __asm__("wzip16p %0, x0, %1" : "=R"(__result) : "r"(__rs1));
  return __result;
}

// Packed Narrowing Convert (RV32 only)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvt_i8x4(int16x4_t __rs1) {
  int8x4_t __result;
  __asm__("pnsrli.b %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvt_u8x4(uint16x4_t __rs1) {
  uint8x4_t __result;
  __asm__("pnsrli.b %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvt_i16x2(int32x2_t __rs1) {
  int16x2_t __result;
  __asm__("pnsrli.h %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvt_u16x2(uint32x2_t __rs1) {
  uint16x2_t __result;
  __asm__("pnsrli.h %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvth_i8x4(int16x4_t __rs1) {
  int8x4_t __result;
  __asm__("pnsrli.b %0, %1, 8" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvth_u8x4(uint16x4_t __rs1) {
  uint8x4_t __result;
  __asm__("pnsrli.b %0, %1, 8" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvth_i16x2(int32x2_t __rs1) {
  int16x2_t __result;
  __asm__("pnsrli.h %0, %1, 16" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvth_u16x2(uint32x2_t __rs1) {
  uint16x2_t __result;
  __asm__("pnsrli.h %0, %1, 16" : "=r"(__result) : "R"(__rs1));
  return __result;
}

// Packed Zip (RV32 only)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pzip_i8x8(int8x4_t __rs1, int8x4_t __rs2) {
  int8x8_t __result;
  __asm__("wzip8p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pzip_u8x8(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x8_t __result;
  __asm__("wzip8p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pzip_i16x4(int16x2_t __rs1, int16x2_t __rs2) {
  int16x4_t __result;
  __asm__("wzip16p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pzip_u16x4(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x4_t __result;
  __asm__("wzip16p %0, %1, %2" : "=R"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Unzip (RV32 only)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipe_i8x4(int8x8_t __rs1) {
  int8x4_t __result;
  __asm__("pnsrli.b %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipo_i8x4(int8x8_t __rs1) {
  int8x4_t __result;
  __asm__("pnsrli.b %0, %1, 8" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipe_u8x4(uint8x8_t __rs1) {
  uint8x4_t __result;
  __asm__("pnsrli.b %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipo_u8x4(uint8x8_t __rs1) {
  uint8x4_t __result;
  __asm__("pnsrli.b %0, %1, 8" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipe_i16x2(int16x4_t __rs1) {
  int16x2_t __result;
  __asm__("pnsrli.h %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipo_i16x2(int16x4_t __rs1) {
  int16x2_t __result;
  __asm__("pnsrli.h %0, %1, 16" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipe_u16x2(uint16x4_t __rs1) {
  uint16x2_t __result;
  __asm__("pnsrli.h %0, %1, 0" : "=r"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipo_u16x2(uint16x4_t __rs1) {
  uint16x2_t __result;
  __asm__("pnsrli.h %0, %1, 16" : "=r"(__result) : "R"(__rs1));
  return __result;
}

// Packed Narrowing Zip (RV32 only - 32-bit types)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_i8x4(int16x2_t __rs1, int16x2_t __rs2) {
  int8x4_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_u8x4(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint8x4_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_i8x4(int16x2_t __rs1, int16x2_t __rs2) {
  int8x4_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_u8x4(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint8x4_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result) : "r"(__rs1), "r"(__rs2));
  return __result;
}

// Packed Narrowing Zip (RV32 only - 64-bit types)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pnzip_i8x8(int16x4_t __rs1, int16x4_t __rs2) {
  int8x8_t __result;
  __asm__("ppaire.db %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pnzip_u8x8(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaire.db %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_i16x4(int32x2_t __rs1, int32x2_t __rs2) {
  int16x4_t __result;
  __asm__("ppaire.dh %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_u16x4(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaire.dh %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pnziph_i8x8(int16x4_t __rs1, int16x4_t __rs2) {
  int8x8_t __result;
  __asm__("ppairo.db %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pnziph_u8x8(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairo.db %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_i16x4(int32x2_t __rs1, int32x2_t __rs2) {
  int16x4_t __result;
  __asm__("ppairo.dh %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_u16x4(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairo.dh %0, %1, %2" : "=R"(__result) : "R"(__rs1), "R"(__rs2));
  return __result;
}

// Packed Narrowing Unzip (RV32 only - 32-bit types)

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipe_i16x2(int8x4_t __rs1) {
  int16x2_t __result;
  __asm__("psext.h.b %0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipo_i16x2(int8x4_t __rs1) {
  int16x2_t __result;
  __asm__("psrai.h %0, %1, 8" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipue_u16x2(uint8x4_t __rs1) {
  uint16x2_t __result;
  __asm__("ppaire.b %0, %1, x0" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipuo_u16x2(uint8x4_t __rs1) {
  uint16x2_t __result;
  __asm__("ppairo.b %0, %1, x0" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_i16x2(int8x4_t __rs1) {
  int16x2_t __result;
  __asm__("pslli.h %0, %1, 8" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_i16x2(int8x4_t __rs1) {
  int16x2_t __result;
  __asm__("ppairo.b %0, x0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_u16x2(uint8x4_t __rs1) {
  uint16x2_t __result;
  __asm__("pslli.h %0, %1, 8" : "=r"(__result) : "r"(__rs1));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_u16x2(uint8x4_t __rs1) {
  uint16x2_t __result;
  __asm__("ppairo.b %0, x0, %1" : "=r"(__result) : "r"(__rs1));
  return __result;
}

// Packed Narrowing Unzip (RV32 only - 64-bit types)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipe_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("psext.dh.b %0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipo_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("psrai.dh %0, %1, 8" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipue_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppaire.db %0, %1, x0" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipuo_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppairo.db %0, %1, x0" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipe_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("psext.dw.h %0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipo_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("psrai.dw %0, %1, 16" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipue_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppaire.dh %0, %1, x0" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipuo_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppairo.dh %0, %1, x0" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("pslli.dh %0, %1, 8" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("ppairo.db %0, x0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("pslli.dh %0, %1, 8" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppairo.db %0, x0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("pslli.dw %0, %1, 16" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("ppairo.dh %0, x0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("pslli.dw %0, %1, 16" : "=R"(__result) : "R"(__rs1));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppairo.dh %0, x0, %1" : "=R"(__result) : "R"(__rs1));
  return __result;
}

// Packed Load and Store (RV32 only - 32-bit types)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pload_i8x4(const int8_t *__p) {
  int8x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pload_u8x4(const uint8_t *__p) {
  uint8x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pload_i16x2(const int16_t *__p) {
  int16x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pload_u16x2(const uint16_t *__p) {
  uint16x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i8x4(int8_t *__p, int8x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u8x4(uint8_t *__p, uint8x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i16x2(int16_t *__p, int16x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u16x2(uint16_t *__p, uint16x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

// Packed Load and Store (64-bit types)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pload_i8x8(const int8_t *__p) {
  int8x8_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pload_u8x8(const uint8_t *__p) {
  uint8x8_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pload_i16x4(const int16_t *__p) {
  int16x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pload_u16x4(const uint16_t *__p) {
  uint16x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pload_i32x2(const int32_t *__p) {
  int32x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pload_u32x2(const uint32_t *__p) {
  uint32x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i8x8(int8_t *__p, int8x8_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u8x8(uint8_t *__p, uint8x8_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i16x4(int16_t *__p, int16x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u16x4(uint16_t *__p, uint16x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i32x2(int32_t *__p, int32x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u32x2(uint32_t *__p, uint32x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

// Packed Element Extract (RV32 only - 32-bit types)

#define __riscv_pget_i8x4_i8(v, idx) __extension__ ({ \
  int8_t __result; \
  int8x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (int8_t)((int32_t)__v.__val >> (__idx * 8)); \
  __result; \
})

#define __riscv_pget_u8x4_u8(v, idx) __extension__ ({ \
  uint8_t __result; \
  uint8x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (uint8_t)(__v.__val >> (__idx * 8)); \
  __result; \
})

#define __riscv_pget_i16x2_i16(v, idx) __extension__ ({ \
  int16_t __result; \
  int16x2_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (int16_t)((int32_t)__v.__val >> (__idx * 16)); \
  __result; \
})

#define __riscv_pget_u16x2_u16(v, idx) __extension__ ({ \
  uint16_t __result; \
  uint16x2_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (uint16_t)(__v.__val >> (__idx * 16)); \
  __result; \
})

// Packed Element Insert (RV32 only - 32-bit types)

#define __riscv_pset_i8_i8x4(v, e, idx) __extension__ ({ \
  int8x4_t __result = (v); \
  int8_t __e = (e); \
  unsigned __idx = (idx); \
  uint32_t __mask = ~(0xFFu << (__idx * 8)); \
  uint32_t __e_shifted = ((uint32_t)((uint8_t)__e)) << (__idx * 8); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_u8_u8x4(v, e, idx) __extension__ ({ \
  uint8x4_t __result = (v); \
  uint8_t __e = (e); \
  unsigned __idx = (idx); \
  uint32_t __mask = ~(0xFFu << (__idx * 8)); \
  uint32_t __e_shifted = ((uint32_t)__e) << (__idx * 8); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_i16_i16x2(v, e, idx) __extension__ ({ \
  int16x2_t __result = (v); \
  int16_t __e = (e); \
  unsigned __idx = (idx); \
  uint32_t __mask = ~(0xFFFFu << (__idx * 16)); \
  uint32_t __e_shifted = ((uint32_t)((uint16_t)__e)) << (__idx * 16); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_u16_u16x2(v, e, idx) __extension__ ({ \
  uint16x2_t __result = (v); \
  uint16_t __e = (e); \
  unsigned __idx = (idx); \
  uint32_t __mask = ~(0xFFFFu << (__idx * 16)); \
  uint32_t __e_shifted = ((uint32_t)__e) << (__idx * 16); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

// Packed Element Join (RV32 only - 32-bit types)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin4_i8x4(int8_t __e0, int8_t __e1, int8_t __e2, int8_t __e3) {
  int8x4_t __result;
  __result.__val = ((uint32_t)((uint8_t)__e0)) |
                   (((uint32_t)((uint8_t)__e1)) << 8) |
                   (((uint32_t)((uint8_t)__e2)) << 16) |
                   (((uint32_t)((uint8_t)__e3)) << 24);
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin4_u8x4(uint8_t __e0, uint8_t __e1, uint8_t __e2, uint8_t __e3) {
  uint8x4_t __result;
  __result.__val = ((uint32_t)__e0) |
                   (((uint32_t)__e1) << 8) |
                   (((uint32_t)__e2) << 16) |
                   (((uint32_t)__e3) << 24);
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_i16x2(int16_t __e0, int16_t __e1) {
  int16x2_t __result;
  __result.__val = ((uint32_t)((uint16_t)__e0)) |
                   (((uint32_t)((uint16_t)__e1)) << 16);
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_u16x2(uint16_t __e0, uint16_t __e1) {
  uint16x2_t __result;
  __result.__val = ((uint32_t)__e0) |
                   (((uint32_t)__e1) << 16);
  return __result;
}

#endif // __riscv_xlen == 32

// Packed Widening Convert (RV64)

#if __riscv_xlen == 64
static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvt_i16x4(int8x4_t __rs1) {
  int16x4_t __result;
  __asm__("zip8p %0, %1, x0; psext.h.b %0, %0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvt_i32x2(int16x2_t __rs1) {
  int32x2_t __result;
  __asm__("zip16p %0, %1, x0; psext.w.h %0, %0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvtu_u16x4(uint8x4_t __rs1) {
  uint16x4_t __result;
  __asm__("zip8p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvtu_u32x2(uint16x2_t __rs1) {
  uint32x2_t __result;
  __asm__("zip16p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_i16x4(int8x4_t __rs1) {
  int16x4_t __result;
  __asm__("zip8p %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_u16x4(uint8x4_t __rs1) {
  uint16x4_t __result;
  __asm__("zip8p %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_i32x2(int16x2_t __rs1) {
  int32x2_t __result;
  __asm__("zip16p %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwcvth_u32x2(uint16x2_t __rs1) {
  uint32x2_t __result;
  __asm__("zip16p %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// Packed Narrowing Convert (RV64)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvt_i8x4(int16x4_t __rs1) {
  int8x4_t __result;
  __asm__("unzip8p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvt_u8x4(uint16x4_t __rs1) {
  uint8x4_t __result;
  __asm__("unzip8p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvt_i16x2(int32x2_t __rs1) {
  int16x2_t __result;
  __asm__("unzip16p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvt_u16x2(uint32x2_t __rs1) {
  uint16x2_t __result;
  __asm__("unzip16p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvth_i8x4(int16x4_t __rs1) {
  int8x4_t __result;
  __asm__("unzip8hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_pncvth_u8x4(uint16x4_t __rs1) {
  uint8x4_t __result;
  __asm__("unzip8hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvth_i16x2(int32x2_t __rs1) {
  int16x2_t __result;
  __asm__("unzip16hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_pncvth_u16x2(uint32x2_t __rs1) {
  uint16x2_t __result;
  __asm__("unzip16hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// Packed Zip (RV64)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pzip_i8x8(int8x4_t __rs1, int8x4_t __rs2) {
  int8x8_t __result;
  __asm__("zip8p %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pzip_u8x8(uint8x4_t __rs1, uint8x4_t __rs2) {
  uint8x8_t __result;
  __asm__("zip8p %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pzip_i16x4(int16x2_t __rs1, int16x2_t __rs2) {
  int16x4_t __result;
  __asm__("zip16p %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pzip_u16x4(uint16x2_t __rs1, uint16x2_t __rs2) {
  uint16x4_t __result;
  __asm__("zip16p %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Unzip (RV64)

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipe_i8x4(int8x8_t __rs1) {
  int8x4_t __result;
  __asm__("unzip8p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipo_i8x4(int8x8_t __rs1) {
  int8x4_t __result;
  __asm__("unzip8hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipe_u8x4(uint8x8_t __rs1) {
  uint8x4_t __result;
  __asm__("unzip8p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_punzipo_u8x4(uint8x8_t __rs1) {
  uint8x4_t __result;
  __asm__("unzip8hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipe_i16x2(int16x4_t __rs1) {
  int16x2_t __result;
  __asm__("unzip16p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipo_i16x2(int16x4_t __rs1) {
  int16x2_t __result;
  __asm__("unzip16hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipe_u16x2(uint16x4_t __rs1) {
  uint16x2_t __result;
  __asm__("unzip16p %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_punzipo_u16x2(uint16x4_t __rs1) {
  uint16x2_t __result;
  __asm__("unzip16hp %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// Packed Narrowing Zip (RV64)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pnzip_i8x8(int16x4_t __rs1, int16x4_t __rs2) {
  int8x8_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pnzip_u8x8(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint8x8_t __result;
  __asm__("ppaire.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_i16x4(int32x2_t __rs1, int32x2_t __rs2) {
  int16x4_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pnzip_u16x4(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint16x4_t __result;
  __asm__("ppaire.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pnziph_i8x8(int16x4_t __rs1, int16x4_t __rs2) {
  int8x8_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pnziph_u8x8(uint16x4_t __rs1, uint16x4_t __rs2) {
  uint8x8_t __result;
  __asm__("ppairo.b %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_i16x4(int32x2_t __rs1, int32x2_t __rs2) {
  int16x4_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pnziph_u16x4(uint32x2_t __rs1, uint32x2_t __rs2) {
  uint16x4_t __result;
  __asm__("ppairo.h %0, %1, %2" : "=r"(__result.__val) : "r"(__rs1.__val), "r"(__rs2.__val));
  return __result;
}

// Packed Narrowing Unzip (RV64)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipe_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("psext.h.b %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipo_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("psrai.h %0, %1, 8" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipue_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppaire.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipuo_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppairo.b %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipe_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("psext.w.h %0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipo_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("psrai.w %0, %1, 16" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipue_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppaire.h %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipuo_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppairo.h %0, %1, x0" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("pslli.h %0, %1, 8" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_i16x4(int8x8_t __rs1) {
  int16x4_t __result;
  __asm__("ppairo.b %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("pslli.h %0, %1, 8" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_u16x4(uint8x8_t __rs1) {
  uint16x4_t __result;
  __asm__("ppairo.b %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("pslli.w %0, %1, 16" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_i32x2(int16x4_t __rs1) {
  int32x2_t __result;
  __asm__("ppairo.h %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunziphe_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("pslli.w %0, %1, 16" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pwunzipho_u32x2(uint16x4_t __rs1) {
  uint32x2_t __result;
  __asm__("ppairo.h %0, x0, %1" : "=r"(__result.__val) : "r"(__rs1.__val));
  return __result;
}

// Packed Load and Store (RV64 - 64-bit types)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pload_i8x8(const int8_t *__p) {
  int8x8_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pload_u8x8(const uint8_t *__p) {
  uint8x8_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pload_i16x4(const int16_t *__p) {
  int16x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pload_u16x4(const uint16_t *__p) {
  uint16x4_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pload_i32x2(const int32_t *__p) {
  int32x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pload_u32x2(const uint32_t *__p) {
  uint32x2_t __result;
  __builtin_memcpy(&__result, __p, sizeof(__result));
  return __result;
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i8x8(int8_t *__p, int8x8_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u8x8(uint8_t *__p, uint8x8_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i16x4(int16_t *__p, int16x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u16x4(uint16_t *__p, uint16x4_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_i32x2(int32_t *__p, int32x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

static __inline__ void __DEFAULT_FN_ATTRS
__riscv_pstore_u32x2(uint32_t *__p, uint32x2_t __v) {
  __builtin_memcpy(__p, &__v, sizeof(__v));
}

#endif // __riscv_xlen == 64

// Reinterpret casts - Packed <-> Scalar (32-bit types - shared by RV32 and RV64)

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x4_u32(uint8x4_t __x) {
  return __x.__val;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x2_u32(uint16x2_t __x) {
  return __x.__val;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x4_u32(int8x4_t __x) {
  return __x.__val;
}

static __inline__ uint32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x2_u32(int16x2_t __x) {
  return __x.__val;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x4_i32(uint8x4_t __x) {
  return (int32_t)__x.__val;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x2_i32(uint16x2_t __x) {
  return (int32_t)__x.__val;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x4_i32(int8x4_t __x) {
  return (int32_t)__x.__val;
}

static __inline__ int32_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x2_i32(int16x2_t __x) {
  return (int32_t)__x.__val;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32_u8x4(uint32_t __x) {
  uint8x4_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32_u16x2(uint32_t __x) {
  uint16x2_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32_i8x4(uint32_t __x) {
  int8x4_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32_i16x2(uint32_t __x) {
  int16x2_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32_u8x4(int32_t __x) {
  uint8x4_t __result;
  __result.__val = (uint32_t)__x;
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32_u16x2(int32_t __x) {
  uint16x2_t __result;
  __result.__val = (uint32_t)__x;
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32_i8x4(int32_t __x) {
  int8x4_t __result;
  __result.__val = (uint32_t)__x;
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32_i16x2(int32_t __x) {
  int16x2_t __result;
  __result.__val = (uint32_t)__x;
  return __result;
}

// Reinterpret casts - Packed <-> Packed (32-bit types - shared by RV32 and RV64)

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x4_u8x4(int8x4_t __x) {
  uint8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x2_u8x4(uint16x2_t __x) {
  uint8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x2_u8x4(int16x2_t __x) {
  uint8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x4_i8x4(uint8x4_t __x) {
  int8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x2_i8x4(uint16x2_t __x) {
  int8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x2_i8x4(int16x2_t __x) {
  int8x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x4_u16x2(uint8x4_t __x) {
  uint16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x4_u16x2(int8x4_t __x) {
  uint16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x2_u16x2(int16x2_t __x) {
  uint16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x4_i16x2(uint8x4_t __x) {
  int16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x4_i16x2(int8x4_t __x) {
  int16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x2_i16x2(uint16x2_t __x) {
  int16x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

// Reinterpret casts - Packed <-> Scalar (64-bit types - shared by RV32 and RV64)

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_u64(uint8x8_t __x) {
  return __x.__val;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_u64(uint16x4_t __x) {
  return __x.__val;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_u64(uint32x2_t __x) {
  return __x.__val;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_u64(int8x8_t __x) {
  return __x.__val;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_u64(int16x4_t __x) {
  return __x.__val;
}

static __inline__ uint64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_u64(int32x2_t __x) {
  return __x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_i64(uint8x8_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_i64(uint16x4_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_i64(uint32x2_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_i64(int8x8_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_i64(int16x4_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ int64_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_i64(int32x2_t __x) {
  return (int64_t)__x.__val;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_u8x8(uint64_t __x) {
  uint8x8_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_u16x4(uint64_t __x) {
  uint16x4_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_u32x2(uint64_t __x) {
  uint32x2_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_i8x8(uint64_t __x) {
  int8x8_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_i16x4(uint64_t __x) {
  int16x4_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u64_i32x2(uint64_t __x) {
  int32x2_t __result;
  __result.__val = __x;
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_u8x8(int64_t __x) {
  uint8x8_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_u16x4(int64_t __x) {
  uint16x4_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_u32x2(int64_t __x) {
  uint32x2_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_i8x8(int64_t __x) {
  int8x8_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_i16x4(int64_t __x) {
  int16x4_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i64_i32x2(int64_t __x) {
  int32x2_t __result;
  __result.__val = (uint64_t)__x;
  return __result;
}

// Reinterpret casts - Packed <-> Packed (64-bit types - shared by RV32 and RV64)

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_u8x8(int8x8_t __x) {
  uint8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_u8x8(uint16x4_t __x) {
  uint8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_u8x8(int16x4_t __x) {
  uint8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_u8x8(uint32x2_t __x) {
  uint8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_u8x8(int32x2_t __x) {
  uint8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_i8x8(uint8x8_t __x) {
  int8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_i8x8(uint16x4_t __x) {
  int8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_i8x8(int16x4_t __x) {
  int8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_i8x8(uint32x2_t __x) {
  int8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_i8x8(int32x2_t __x) {
  int8x8_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_u16x4(uint8x8_t __x) {
  uint16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_u16x4(int8x8_t __x) {
  uint16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_u16x4(int16x4_t __x) {
  uint16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_u16x4(uint32x2_t __x) {
  uint16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_u16x4(int32x2_t __x) {
  uint16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_i16x4(uint8x8_t __x) {
  int16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_i16x4(int8x8_t __x) {
  int16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_i16x4(uint16x4_t __x) {
  int16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_i16x4(uint32x2_t __x) {
  int16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_i16x4(int32x2_t __x) {
  int16x4_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_u32x2(uint8x8_t __x) {
  uint32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_u32x2(int8x8_t __x) {
  uint32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_u32x2(uint16x4_t __x) {
  uint32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_u32x2(int16x4_t __x) {
  uint32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i32x2_u32x2(int32x2_t __x) {
  uint32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u8x8_i32x2(uint8x8_t __x) {
  int32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i8x8_i32x2(int8x8_t __x) {
  int32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u16x4_i32x2(uint16x4_t __x) {
  int32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_i16x4_i32x2(int16x4_t __x) {
  int32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_preinterpret_u32x2_i32x2(uint32x2_t __x) {
  int32x2_t __result;
  __result.__val = __x.__val;
  return __result;
}

// Packed Subvector Extract (64-bit types - shared by RV32 and RV64)

#define __riscv_pget_i8x8_i8x4(v, idx) __extension__ ({ \
  int8x4_t __result; \
  int8x8_t __v = (v); \
  unsigned __idx = (idx); \
  __result.__val = (uint32_t)(__v.__val >> (__idx * 32)); \
  __result; \
})

#define __riscv_pget_u8x8_u8x4(v, idx) __extension__ ({ \
  uint8x4_t __result; \
  uint8x8_t __v = (v); \
  unsigned __idx = (idx); \
  __result.__val = (uint32_t)(__v.__val >> (__idx * 32)); \
  __result; \
})

#define __riscv_pget_i16x4_i16x2(v, idx) __extension__ ({ \
  int16x2_t __result; \
  int16x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result.__val = (uint32_t)(__v.__val >> (__idx * 32)); \
  __result; \
})

#define __riscv_pget_u16x4_u16x2(v, idx) __extension__ ({ \
  uint16x2_t __result; \
  uint16x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result.__val = (uint32_t)(__v.__val >> (__idx * 32)); \
  __result; \
})

// Packed Subvector Insert (64-bit types - shared by RV32 and RV64)

#define __riscv_pset_i8x4_i8x8(v, s, idx) __extension__ ({ \
  int8x8_t __result = (v); \
  int8x4_t __s = (s); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __s_shifted = ((uint64_t)__s.__val) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __s_shifted; \
  __result; \
})

#define __riscv_pset_u8x4_u8x8(v, s, idx) __extension__ ({ \
  uint8x8_t __result = (v); \
  uint8x4_t __s = (s); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __s_shifted = ((uint64_t)__s.__val) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __s_shifted; \
  __result; \
})

#define __riscv_pset_i16x2_i16x4(v, s, idx) __extension__ ({ \
  int16x4_t __result = (v); \
  int16x2_t __s = (s); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __s_shifted = ((uint64_t)__s.__val) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __s_shifted; \
  __result; \
})

#define __riscv_pset_u16x2_u16x4(v, s, idx) __extension__ ({ \
  uint16x4_t __result = (v); \
  uint16x2_t __s = (s); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __s_shifted = ((uint64_t)__s.__val) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __s_shifted; \
  __result; \
})

// Packed Element Join (64-bit types - shared by RV32 and RV64)

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin4_i16x4(int16_t __e0, int16_t __e1, int16_t __e2, int16_t __e3) {
  int16x4_t __result;
  __result.__val = ((uint64_t)((uint16_t)__e0)) |
                   (((uint64_t)((uint16_t)__e1)) << 16) |
                   (((uint64_t)((uint16_t)__e2)) << 32) |
                   (((uint64_t)((uint16_t)__e3)) << 48);
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin4_u16x4(uint16_t __e0, uint16_t __e1, uint16_t __e2, uint16_t __e3) {
  uint16x4_t __result;
  __result.__val = ((uint64_t)__e0) |
                   (((uint64_t)__e1) << 16) |
                   (((uint64_t)__e2) << 32) |
                   (((uint64_t)__e3) << 48);
  return __result;
}

static __inline__ int32x2_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_i32x2(int32_t __e0, int32_t __e1) {
  int32x2_t __result;
  __result.__val = ((uint64_t)((uint32_t)__e0)) |
                   (((uint64_t)((uint32_t)__e1)) << 32);
  return __result;
}

static __inline__ uint32x2_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_u32x2(uint32_t __e0, uint32_t __e1) {
  uint32x2_t __result;
  __result.__val = ((uint64_t)__e0) |
                   (((uint64_t)__e1) << 32);
  return __result;
}

// Packed Subvector Join (64-bit types - shared by RV32 and RV64)

static __inline__ int8x8_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_i8x8(int8x4_t __lo, int8x4_t __hi) {
  int8x8_t __result;
  __result.__val = ((uint64_t)__lo.__val) |
                   (((uint64_t)__hi.__val) << 32);
  return __result;
}

static __inline__ uint8x8_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_u8x8(uint8x4_t __lo, uint8x4_t __hi) {
  uint8x8_t __result;
  __result.__val = ((uint64_t)__lo.__val) |
                   (((uint64_t)__hi.__val) << 32);
  return __result;
}

static __inline__ int16x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_i16x4(int16x2_t __lo, int16x2_t __hi) {
  int16x4_t __result;
  __result.__val = ((uint64_t)__lo.__val) |
                   (((uint64_t)__hi.__val) << 32);
  return __result;
}

static __inline__ uint16x4_t __DEFAULT_FN_ATTRS
__riscv_pjoin2_u16x4(uint16x2_t __lo, uint16x2_t __hi) {
  uint16x4_t __result;
  __result.__val = ((uint64_t)__lo.__val) |
                   (((uint64_t)__hi.__val) << 32);
  return __result;
}

// Packed Element Extract and Insert (64-bit types - shared by RV32 and RV64)

#define __riscv_pget_i8x8_i8(v, idx) __extension__ ({ \
  int8_t __result; \
  int8x8_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (int8_t)((int64_t)__v.__val >> (__idx * 8)); \
  __result; \
})

#define __riscv_pget_u8x8_u8(v, idx) __extension__ ({ \
  uint8_t __result; \
  uint8x8_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (uint8_t)(__v.__val >> (__idx * 8)); \
  __result; \
})

#define __riscv_pget_i16x4_i16(v, idx) __extension__ ({ \
  int16_t __result; \
  int16x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (int16_t)((int64_t)__v.__val >> (__idx * 16)); \
  __result; \
})

#define __riscv_pget_u16x4_u16(v, idx) __extension__ ({ \
  uint16_t __result; \
  uint16x4_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (uint16_t)(__v.__val >> (__idx * 16)); \
  __result; \
})

#define __riscv_pget_i32x2_i32(v, idx) __extension__ ({ \
  int32_t __result; \
  int32x2_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (int32_t)((int64_t)__v.__val >> (__idx * 32)); \
  __result; \
})

#define __riscv_pget_u32x2_u32(v, idx) __extension__ ({ \
  uint32_t __result; \
  uint32x2_t __v = (v); \
  unsigned __idx = (idx); \
  __result = (uint32_t)(__v.__val >> (__idx * 32)); \
  __result; \
})

#define __riscv_pset_i8_i8x8(v, e, idx) __extension__ ({ \
  int8x8_t __result = (v); \
  int8_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFULL << (__idx * 8)); \
  uint64_t __e_shifted = ((uint64_t)((uint8_t)__e)) << (__idx * 8); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_u8_u8x8(v, e, idx) __extension__ ({ \
  uint8x8_t __result = (v); \
  uint8_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFULL << (__idx * 8)); \
  uint64_t __e_shifted = ((uint64_t)__e) << (__idx * 8); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_i16_i16x4(v, e, idx) __extension__ ({ \
  int16x4_t __result = (v); \
  int16_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFULL << (__idx * 16)); \
  uint64_t __e_shifted = ((uint64_t)((uint16_t)__e)) << (__idx * 16); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_u16_u16x4(v, e, idx) __extension__ ({ \
  uint16x4_t __result = (v); \
  uint16_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFULL << (__idx * 16)); \
  uint64_t __e_shifted = ((uint64_t)__e) << (__idx * 16); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_i32_i32x2(v, e, idx) __extension__ ({ \
  int32x2_t __result = (v); \
  int32_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __e_shifted = ((uint64_t)((uint32_t)__e)) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#define __riscv_pset_u32_u32x2(v, e, idx) __extension__ ({ \
  uint32x2_t __result = (v); \
  uint32_t __e = (e); \
  unsigned __idx = (idx); \
  uint64_t __mask = ~(0xFFFFFFFFULL << (__idx * 32)); \
  uint64_t __e_shifted = ((uint64_t)__e) << (__idx * 32); \
  __result.__val = (__result.__val & __mask) | __e_shifted; \
  __result; \
})

#undef __DEFAULT_FN_ATTRS

#endif // defined(__riscv_p)

#if defined(__cplusplus)
}
#endif

#endif // __RISCV_P_ASM_H

# RISC-V P Extension Intrinsics

This is a draft specification of the RISC-V P extension intrinsics. Based on the ISA specification [ISA specification](https://www.jhauser.us/RISCV/ext-P/).

## Introduction

The RISC-V P Extension C intrinsics provide users interface in the C language level to directly leverage the RISC-V "P" extension.

## Scalar Intrinsics

### Scalar Intrinsics Common to RV32 and RV64

* TODO: cls and rev names match clz/ctz/rev8 names from bitmanip

| Prototype                                                                | Instruction                           | Notes                                              |
|--------------------------------------------------------------------------|---------------------------------------|----------------------------------------------------|
| `uint32_t __riscv_abs_u32(int32_t rs1);`                                 | `abs[w]`                              |                                                    |
| `unsigned __riscv_cls_32(int32_t rs1);`                                  | `cls[w]`                              |                                                    |
| `uint32_t __riscv_rev_32(uint32_t rs1);`                                 | `rev`                                 | Emulated with rev+srai on RV64                     |
| `int32_t __riscv_sslai_i32(int32_t rs1, const unsigned shamt);`          | `sslai`(RV32), `psslai.w`(RV64)       |                                                    |
| `int32_t __riscv_ssha_i32(int32_t rs1, int rs2);`                        | `ssha`(RV32), `pssha.ws`(RV64)        |                                                    |
| `int32_t __riscv_sshar_i32(int32_t rs1, int rs2);`                       | `sshar`(RV32), `psshar.ws`(RV64)      |                                                    |
| `int32_t __riscv_sadd_i32(int32_t rs1, int32_t rs2);`                    | `sadd`(RV32), `psadd.w`(RV64)         |                                                    |
| `int32_t __riscv_aadd_i32(int32_t rs1, int32_t rs2);`                    | `aadd`(RV32), `paadd.w`(RV64)         |                                                    |
| `uint32_t __riscv_saddu_u32(uint32_t rs1, uint32_t rs2);`                | `saddu`(RV32), `psaddu.w`(RV64)       |                                                    |
| `uint32_t __riscv_aaddu_u32(uint32_t rs1, uint32_t rs2);`                | `aaddu`(RV32), `paaddu.w`(RV64)       |                                                    |
| `int32_t __riscv_ssub_i32(int32_t rs1, int32_t rs2);`                    | `ssub`(RV32), `pssub.w`(RV64)         |                                                    |
| `int32_t __riscv_asub_i32(int32_t rs1, int32_t rs2);`                    | `asub`(RV32), `pasub.w`(RV64)         |                                                    |
| `uint32_t __riscv_ssubu_u32(uint32_t rs1, uint32_t rs2);`                | `ssubu`(RV32), `pssubu.w`(RV64)       |                                                    |
| `uint32_t __riscv_asubu_u32(uint32_t rs1, uint32_t rs2);`                | `asubu`(RV32), `pasubu.w`(RV64)       |                                                    |
| `uint32_t __riscv_usati_u32(int32_t rs1, const unsigned shamt);`         | `usati`(RV32), `pusati.w`(RV64)       |                                                    |
| `int32_t __riscv_srari_i32(int32_t rs1, const unsigned shamt);`          | `srari`(RV32), `psrari.w`(RV64)       |                                                    |
| `int32_t __riscv_sati_i32(int32_t rs1, const unsigned shamt);`           | `sati`(RV32), `psati.w`(RV64)         |                                                    |
| `int32_t __riscv_ssh1sadd_i32(int32_t rs1, int32_t rs2);`                | `ssh1sadd`(RV32), `pssh1sadd.w`(RV64) |                                                    |
| `int32_t __riscv_mulh_i32(int32_t rs1, int32_t rs2);`                    | `mulh`(RV32), various(RV64)           | Emulated on RV64                                   |
| `int32_t __riscv_mulhr_i32(int32_t rs1, int32_t rs2);`                   | `mulhr`(RV32), `pmulhr.w`(RV64)       |                                                    |
| `int32_t __riscv_mhacc_i32(int32_t rd, int32_t rs1, int32_t rs2);`       | `mhacc`(RV32), `pmhacc.w`?(RV64)      |                                                    |
| `int32_t __riscv_mhracc_i32(int32_t rd, int32_t rs1, int32_t rs2);`      | `mhracc`(RV32), `pmhracc.w`(RV64)     |                                                    |
| `uint32_t __riscv_mulhu_u32(uint32_t rs1, uint32_t rs2);`                | `mulhu`(RV32), various(RV64)          | Emulated on RV64                                   |
| `uint32_t __riscv_mulhru_u32(uint32_t rs1, uint32_t rs2);`               | `mulhru`(RV32), `pmulhru.w`(RV64)     |                                                    |
| `uint32_t __riscv_mhaccu_u32(uint32_t rd, uint32_t rs1, uint32_t rs2);`  | `mhaccu`(RV32), `pmhaccu.w`?(RV64)    |                                                    |
| `uint32_t __riscv_mhraccu_u32(uint32_t rd, uint32_t rs1, uint32_t rs2);` | `mhraccu`(RV32), `pmhraccu.w`(RV64)   |                                                    |
| `int32_t __riscv_mulhsu_i32(int32_t rs1, uint32_t rs2);`                 | `mulhsu`(RV32), various(RV64)         | Emulated on RV64                                   |
| `int32_t __riscv_mulhrsu_i32(int32_t rs1, uint32_t rs2);`                | `mulhrsu`(RV32), `pmulhrsu.w`(RV64)   |                                                    |
| `int32_t __riscv_mhaccsu_i32(int32_t rd, int32_t rs1, uint32_t rs2);`    | `mhaccsu`(RV32), `pmhaccsu.w`?(RV64)  |                                                    |
| `int32_t __riscv_mhraccsu_i32(int32_t rd, int32_t rs1, uint32_t rs2);`   | `mhraccsu`(RV32), `pmhraccsu.w`(RV64) |                                                    |
| `int32_t __riscv_mulq_i32(int32_t rs1, uint32_t rs2);`                   | `mulq`(RV32), `pmulq.w`(RV64)         |                                                    |
| `int32_t __riscv_mulqr_i32(int32_t rs1, uint32_t rs2);`                  | `mulqr`(RV32), `pmulqr.w`(RV64)       |                                                    |

* TODO: Do we need intrinsics for MERGE?
* TODO: How to handle VXSAT?

### RV32 Only Scalar Intrinsics

| Prototype                                                              | Instruction                     | Notes                         |
|------------------------------------------------------------------------|---------------------------------|-------------------------------|
| `uint32_t __riscv_slx_u32(uint32_t rd, uint32_t rs1, unsigned shamt);` | `slx`                           |                               |
| `uint32_t __riscv_srx_u32(uint32_t rd, uint32_t rs1, unsigned shamt);` | `srx`                           |                               |
| `uint64_t __riscv_wzip8p_u64(uint32_t rs1, uint32_t rs2);`             | `wzip8p`                        |                               |
| `uint64_t __riscv_wzip16p_u64(uint32_t rs1, uint32_t rs2);`            | `wzip16p`                       |                               |
| `int64_t __riscv_mqwacc_i64(int64_t rd, int32_t rs1, int32_t rs2);`    | `mqwacc`                        |                               |
| `int64_t __riscv_mqrwacc_i64(int64_t rd, int32_t rs1, int32_t rs2);`   | `mqrwacc`                       |                               |
| `uint32_t __riscv_nclipu_u32(uint64_t rs1_p, uint32_t rs2);`           | `nclip[i]u`                     |                               |
| `uint32_t __riscv_nclipru_u32(uint64_t rs1_p, uint32_t rs2);`          | `nclipr[i]u`                    |                               |
| `int32_t __riscv_nsrar_i32(int64_t rs1_p, uint32_t rs2);`              | `nsrar[i]`                      |                               |
| `int32_t __riscv_nclip_i32(int64_t rs1_p, uint32_t rs2);`              | `nclip[i]`                      |                               |
| `int32_t __riscv_nclipr_i32(int64_t rs1_p, uint32_t rs2);`             | `nclipr[i]`                     |                               |
| `uint32_t __riscv_mseq_i32(int32_t rs1, int32_t rs2);`                 | `mseq`(RV32), `pmseq.w`(RV64)   |                               |
| `uint32_t __riscv_mseq_u32(uint32_t rs1, uint32_t rs2);`               | `mseq`(RV32), `pmseq.w`(RV64)   |                               |
| `uint32_t __riscv_mslt_i32(int32_t rs1, int32_t rs2);`                 | `mslt`(RV32), `pmslt.w`(RV64)   |                               |
| `uint32_t __riscv_msgt_i32(int32_t rs1, int32_t rs2);`                 | `mslt`(RV32), `pmslt.w`(RV64)   | Swap operands and use pmslt   |
| `uint32_t __riscv_msltu_u32(uint32_t rs1, uint32_t rs2);`              | `msltu`(RV32), `pmsltu.w`(RV64) |                               |
| `uint32_t __riscv_msgtu_u32(uint32_t rs1, uint32_t rs2);`              | `msltu`(RV32), `pmsltu.w`(RV64) | Swap operands and use pmsltu  |

* TODO: Do we need intrinsics for ADDD or SUBD? Or can compiler figure it out?
* TODO: mseq/mslt/etc return unsigned type but take signed/unsigned input types. Should we list both types?

### RV64 Only Scalar Intrinsics

* TODO: cls and rev names match clz/ctz/rev8 names from bitmanip

| Prototype                                                              | Instruction                 |
|------------------------------------------------------------------------|-----------------------------|
| `uint64_t __riscv_abs_u64(int64_t rs1);`                               | `abs`                       |
| `unsigned __riscv_cls_64(int64_t rs1);`                                | `cls`                       |
| `uint64_t __riscv_rev_64(uint64_t rs1);`                               | `rev`                       |
| `uint64_t __riscv_rev16_u64(uint64_t rs1);`                            | `rev16`                     |
| `int64_t __riscv_sha_i64(int64_t rs1, int rs2);`                       | `sha`                       |
| `int64_t __riscv_shar_i64(int64_t rs1, int rs2);`                      | `shar`                      |
| `uint64_t __riscv_usati_u64(int64_t rs1, const unsigned shamt);`       | `usati`                     |
| `int64_t __riscv_srari_i64(int64_t rs1, const unsigned shamt);`        | `srari`                     |
| `int64_t __riscv_sati_i64(int64_t rs1, const unsigned shamt);`         | `sati`                      |
| `uint64_t __riscv_slx_u64(uint64_t rd, uint64_t rs1, unsigned shamt);` | `slx`                       |
| `uint64_t __riscv_srx_u64(uint64_t rd, uint64_t rs1, unsigned shamt);` | `srx`                       |
| `uint64_t __riscv_unzip8p_u64(uint64_t rs1, uint64_t rs2);`            | `unzip8p`                   |
| `uint64_t __riscv_unzip16p_u64(uint64_t rs1, uint64_t rs2);`           | `unzip16p`                  |
| `uint64_t __riscv_unzip8hp_u64(uint64_t rs1, uint64_t rs2);`           | `unzip8hp`                  |
| `uint64_t __riscv_unzip16hp_u64(uint64_t rs1, uint64_t rs2);`          | `unzip16hp`                 |
| `uint64_t __riscv_zip8p_u64(uint64_t rs1, uint64_t rs2);`              | `zip8p`                     |
| `uint64_t __riscv_zip16p_u64(uint64_t rs1, uint64_t rs2);`             | `zip16p`                    |
| `uint64_t __riscv_zip8hp_u64(uint64_t rs1, uint64_t rs2);`             | `zip8hp`                    |
| `uint64_t __riscv_zip16hp_u64(uint64_t rs1, uint64_t rs2);`            | `zip16hp`                   |

## Packed SIMD Types

A 32-bit type will occupy a full GPR on RV32 and half of a GPR on RV64.
A 64-bit type will occupy a pair of GPRs on RV32 and a full GPR on RV64.

| Type       | Size (Bytes) | Alignment (Bytes) | Description                    |
|------------|--------------|-------------------|--------------------------------|
| int8x4_t   | 4            | 4                 | Four signed 8-bit integers     |
| uint8x4_t  | 4            | 4                 | Four unsigned 8-bit integers   |
| int16x2_t  | 4            | 4                 | Two signed 16-bit integers     |
| uint16x2_t | 4            | 4                 | Two unsigned 16-bit integers   |
| int8x8_t   | 8            | 8                 | Eight signed 8-bit integers    |
| uint8x8_t  | 8            | 8                 | Eight unsigned 8-bit integers  |
| int16x4_t  | 8            | 8                 | Four signed 16-bit integers    |
| uint16x4_t | 8            | 8                 | Four unsigned 16-bit integers  |
| int32x2_t  | 8            | 8                 | Two signed 32-bit integers     |
| uint32x2_t | 8            | 8                 | Two unsigned 32-bit integers   |

## Packed Intrinsics

The intrinsic interface is designed as much as possible to be source code portable between RV32 and RV64. This does not necessarily mean it is performance portable. Intrinsics operating
on 32-bit and 64-bit types are provided for both RV32 and RV64.

* TODO: Packed intrinsics for (un)zip(8|16)8(h)p?

### Packed Splat

Intrinsics for splatting a scalar to every element of a packed type. Compiler will choose
an immediate form when possible.

#### 32-bit

| Prototype                                     | Instruction                               |
|-----------------------------------------------|-------------------------------------------|
| `uint8x4_t __riscv_pmv_s_u8x4(uint8_t x);`    | `padd.bs`(rs1=x0), `pli.b`                |
| `int8x4_t __riscv_pmv_s_i8x4(int8_t x);`      | `padd.bs`(rs1=x0), `pli.b`                |
| `uint16x2_t __riscv_pmv_s_u16x2(uint16_t x);` | `padd.hs`(rs1=x0), `pli.h`, `plui.h`      |
| `int16x2_t __riscv_pmv_s_i16x2(int16_t x);`   | `padd.hs`(rs1=x0), `pli.h`, `plui.h`      |

#### 64-bit

| Prototype                                     | Instruction                                                                                    |
|-----------------------------------------------|------------------------------------------------------------------------------------------------|
| `uint8x8_t __riscv_pmv_s_u8x8(uint8_t x);`    | `padd.bs`(rs1=x0), `pli.b`(RV64), `padd.dbs`(rs1_p=x0), `pli.db`(RV32)                         |
| `int8x8_t __riscv_pmv_s_i8x8(int8_t x);`      | `padd.bs`(rs1=x0), `pli.b`(RV64), `padd.dbs`(rs1_p=x0), `pli.db`(RV32)                         |
| `uint16x4_t __riscv_pmv_s_u16x4(uint16_t x);` | `padd.hs`(rs1=x0), `pli.h`, `plui.h`(RV64), `padd.dhs`(rs1_p=x0), `pli.dh`, `plui.dh`(RV32)    |
| `int16x4_t __riscv_pmv_s_i16x4(int16_t x);`   | `padd.hs`(rs1=x0), `pli.h`, `plui.h`(RV64), `padd.dhs`(rs1_p=x0), `pli.dh`, `plui.dh`(RV32)    |
| `uint32x2_t __riscv_pmv_s_u32x2(uint32_t x);` | `padd.ws`(rs1=x0), `pli.w`, `plui.w`(RV64), `padd.dws`(rs1_p=x0), `lui`+`addi`+`mv`(RV32)      |
| `int32x2_t __riscv_pmv_s_i32x2(int32_t x);`   | `padd.ws`(rs1=x0), `pli.w`, `plui.w`(RV64), `padd.dws`(rs1_p=x0), `lui`+`addi`+`mv`(RV32)      |

### Packed Shifts

Shift each element in a packed type by the same amount. Result may be saturated
and/or rounded. Compiler will choose an immediate form when possible. Intrinsics
with 'i' in the name require a constant shift amount.

#### 32-bit

| Prototype                                                              | Instruction                               |
|------------------------------------------------------------------------|-------------------------------------------|
| `uint8x4_t __riscv_psll_s_u8x4(uint8x4_t rs1, unsigned shamt);`        | `pslli.b`, `psll.bs`                      |
| `int8x4_t __riscv_psll_s_i8x4(int8x4_t rs1, unsigned shamt);`          | `pslli.b`, `psll.bs`                      |
| `uint16x2_t __riscv_psll_s_u16x2(uint16x2_t rs1, unsigned shamt);`     | `pslli.h`, `psll.hs`                      |
| `int16x2_t __riscv_psll_s_i16x2(int16x2_t rs1, unsigned shamt);`       | `pslli.h`, `psll.hs`                      |
| `int16x2_t __riscv_psslai_i16x2(int16x2_t rs1, const unsigned shamt);` | `psslai.h`                                |
| `int16x2_t __riscv_pssha_s_i16x2(int16x2_t rs1, int shamt);`           | `pssha.hs`                                |
| `int16x2_t __riscv_psshar_s_i16x2(int16x2_t rs1, int shamt);`          | `psshar.hs`                               |
| `uint8x4_t __riscv_psrl_s_u8x4(uint8x4_t rs1, unsigned shamt);`        | `psrli.b`, `psrl.bs`                      |
| `uint16x2_t __riscv_psrl_s_u16x2(uint16x2_t rs1, unsigned shamt);`     | `psrli.h`, `psrl.hs`                      |
| `int8x4_t __riscv_psra_s_i8x4(int8x4_t rs1, unsigned shamt);`          | `psrai.b`, `psra.bs`                      |
| `int16x2_t __riscv_psra_s_i16x2(int16x2_t rs1, unsigned shamt);`       | `psrai.h`, `psra.hs`                      |
| `int16x2_t __riscv_psrari_i16x2(int16x2_t rs1, const unsigned shamt);` | `psrari.h`                                |

#### 64-bit

| Prototype                                                              | Instruction                                               |
|------------------------------------------------------------------------|-----------------------------------------------------------|
| `uint8x8_t __riscv_psll_s_u8x8(uint8x8_t rs1, unsigned shamt);`        | `pslli.b`, `psll.bs`(RV64), `pslli.db`, `psll.dbs` (RV32) |
| `int8x8_t __riscv_psll_s_i8x8(int8x8_t rs1, unsigned shamt);`          | `pslli.b`, `psll.bs`(RV64), `pslli.db`, `psll.dbs` (RV32) |
| `uint16x4_t __riscv_psll_s_u16x4(uint16x4_t rs1, unsigned shamt);`     | `pslli.h`, `psll.hs`(RV64), `pslli.dh`, `psll.dhs` (RV32) |
| `int16x4_t __riscv_psll_s_i16x4(int16x4_t rs1, unsigned shamt);`       | `pslli.h`, `psll.hs`(RV64), `pslli.dh`, `psll.dhs` (RV32) |
| `uint32x2_t __riscv_psll_s_u32x2(uint32x2_t rs1, unsigned shamt);`     | `pslli.w`, `psll.ws`(RV64), `pslli.dw`, `psll.dws` (RV32) |
| `int32x2_t __riscv_psll_s_i32x2(int32x2_t rs1, unsigned shamt);`       | `pslli.w`, `psll.ws`(RV64), `pslli.dw`, `psll.dws` (RV32) |
| `int16x4_t __riscv_psslai_i16x4(int16x4_t rs1, const unsigned shamt);` | `psslai.h`(RV64), `psslai.dh`(RV32)                       |
| `int32x2_t __riscv_psslai_i32x2(int32x2_t rs1, const unsigned shamt);` | `psslai.w`(RV64), `psslai.dw`(RV32)                       |
| `int16x4_t __riscv_pssha_s_i16x4(int16x4_t rs1, int shamt);`           | `pssha.hs`(RV64), `pssha.dhs`(RV32)                       |
| `int32x2_t __riscv_pssha_s_i32x2(int16x4_t rs1, int shamt);`           | `pssha.ws`(RV64), `pssha.dws`(RV32)                       |
| `int16x4_t __riscv_psshar_s_i16x4(int32x2_t rs1, int shamt);`          | `psshar.hs`(RV64), `psshar.dhs`(RV32)                     |
| `int32x2_t __riscv_psshar_s_i32x2(int32x2_t rs1, int shamt);`          | `psshar.ws`(RV64), `psshar.dws`(RV32)                     |
| `uint8x8_t __riscv_psrl_s_u8x8(uint8x8_t rs1, unsigned shamt);`        | `psrli.b`, `psrl.bs`(RV64), `psrli.db`, `psrl.dbs`(RV32)  |
| `uint16x4_t __riscv_psrl_s_u16x4(uint16x4_t rs1, unsigned shamt);`     | `psrli.h`, `psrl.hs`(RV64), `psrli.dh`, `psrl.dhs`(RV32)  |
| `uint32x2_t __riscv_psrl_s_u32x2(uint32x2_t rs1, unsigned shamt);`     | `psrli.w`, `psrl.ws`(RV64), `psrli.dw`, `psrl.dws`(RV32)  |
| `int8x8_t __riscv_psra_s_i8x8(int8x8_t rs1, unsigned shamt);`          | `psrai.b`, `psra.bs`(RV64), `psrai.db`, `psra.dbs`(RV32)  |
| `int16x4_t __riscv_psra_s_i16x4(int16x4_t rs1, unsigned shamt);`       | `psrai.h`, `psra.hs`(RV64), `psrai.dh`, `psra.dhs`(RV32)  |
| `int32x2_t __riscv_psra_s_i32x2(int32x2_t rs1, unsigned shamt);`       | `psrai.w`, `psra.ws`(RV64), `psrai.dw`, `psra.dws`(RV32)  |
| `int16x4_t __riscv_psrari_i16x4(int16x4_t rs1, const unsigned shamt);` | `psrari.h`(RV64), `psrari.dh`(RV32)                       |
| `int32x2_t __riscv_psrari_i32x2(int32x2_t rs1, const unsigned shamt);` | `psrari.w`(RV64), `psrari.dw`(RV32)                       |

### Packed Sign Extend

Sign extend within each element. Does not change the start position of each
element.

#### 32-bit

| Prototype                                         | Instruction                           |
|---------------------------------------------------|---------------------------------------|
| `int16x2_t __riscv_psext_b_i16x2(int16x2_t rs1);` | `psext.h.b`                           |
| `int16x2_t __riscv_pzext_b_i16x2(int16x2_t rs1);` | `ppaire.b`(rs2=x0)                    |

### 64-bit

| Prototype                                         | Instruction                                           |
|---------------------------------------------------|-------------------------------------------------------|
| `int16x4_t __riscv_psext_b_i16x4(int16x4_t rs1);` | `psext.h.b`(RV64), `psext.dh.b`(RV32)                 |
| `int32x2_t __riscv_psext_b_i32x2(int32x2_t rs1);` | `psext.w.b`(RV64), `psext.dw.b`(RV32)                 |
| `int32x2_t __riscv_psext_h_i32x2(int32x2_t rs1);` | `psext.w.h`(RV64), `psext.dw.h`(RV32)                 |
| `int16x4_t __riscv_pzext_b_i16x4(int16x4_t rs1);` | `ppaire.b`(rs2=x0)(RV64), `ppaire.db`(rs2_p=x0)(RV32) |
| `int32x2_t __riscv_pzext_h_i32x2(int32x2_t rs1);` | `ppaire.h`(rs2=x0)(RV64), `ppaire.dh`(rs2_p=x0)(RV32) |

### Packed Saturating Absolute Value

Saturating absolute value of packed signed elements.

#### 32-bit

| Prototype                                       | Instruction                       |
|-------------------------------------------------|-----------------------------------|
| `int8x4_t __riscv_psabs_i8x4(int8x4_t rs1);`    | `psabs.b`                         |
| `int16x2_t __riscv_psabs_i16x2(int16x2_t rs1);` | `psabs.h`                         |

### 64-bit

| Prototype                                       | Instruction                       |
|-------------------------------------------------|-----------------------------------|
| `int8x8_t __riscv_psabs_i8x8(int8x8_t rs1);`    | `psabs.b`(RV64), `psabs.db`(RV32) |
| `int16x4_t __riscv_psabs_i16x4(int16x4_t rs1);` | `psabs.h`(RV64), `psabs.dh`(RV32) |

### Packed Addition with Scalar

Adds a scalar to every element of a packed value.

#### 32-bit

| Prototype                                                        | Instruction                       |
|------------------------------------------------------------------|-----------------------------------|
| `uint8x4_t __riscv_padd_s_u8x4(uint8x4_t rs1, uint8_t rs2);`     | `padd.bs`                         |
| `int8x4_t __riscv_padd_s_i8x4(int8x4_t rs1, int8_t rs2);`        | `padd.bs`                         |
| `uint16x2_t __riscv_padd_s_u16x2(uint16x2_t rs1, uint16_t rs2);` | `padd.hs`                         |
| `int16x2_t __riscv_padd_s_i16x2(int16x2_t rs1, int16_t rs2);`    | `padd.hs`                         |

#### 64-bit

| Prototype                                                        | Instruction                       |
|------------------------------------------------------------------|-----------------------------------|
| `uint8x8_t __riscv_padd_s_u8x8(uint8x8_t rs1, uint8_t rs2);`     | `padd.bs`(RV64), `padd.dbs`(RV32) |
| `int8x8_t __riscv_padd_s_i8x8(int8x8_t rs1, int8_t rs2);`        | `padd.bs`(RV64), `padd.dbs`(RV32) |
| `uint16x4_t __riscv_padd_s_u16x4(uint16x4_t rs1, uint16_t rs2);` | `padd.hs`(RV64), `padd.dhs`(RV32) |
| `int16x4_t __riscv_padd_s_i16x4(int16x4_t rs1, int16_t rs2);`    | `padd.hs`(RV64), `padd.dhs`(RV32) |
| `uint32x2_t __riscv_padd_s_u32x2(uint32x2_t rs1, uint32_t rs2);` | `padd.ws`(RV64), `padd.dws`(RV32) |
| `int32x2_t __riscv_padd_s_i32x2(int32x2_t rs1, int32_t rs2);`    | `padd.ws`(RV64), `padd.dws`(RV32) |

### Packed Saturation

Saturate every element to the specified width.

#### 32-bit

| Prototype                                                               | Instruction                         |
|-------------------------------------------------------------------------|-------------------------------------|
| `uint16x2_t __riscv_pusati_u16x2(int16x2_t rs1, const unsigned width);` | `pusati.h`                          |
| `int16x2_t __riscv_psati_i16x2(int16x2_t rs1, const unsigned width);`   | `psati.h`                           |

#### 64-bit

| Prototype                                                               | Instruction                         |
|-------------------------------------------------------------------------|-------------------------------------|
| `uint16x4_t __riscv_pusati_u16x4(int16x4_t rs1, const unsigned width);` | `pusati.h`(RV64), `pusati.dh`(RV32) |
| `uint32x2_t __riscv_pusati_u32x2(int32x2_t rs1, const unsigned width);` | `pusati.w`(RV64), `pusati.dw`(RV32) |
| `int16x4_t __riscv_psati_i16x4(int16x4_t rs1, const unsigned width);`   | `psati.h`(RV64), `psati.h`(RV32)    |
| `int32x2_t __riscv_psati_i32x2(int32x2_t rs1, const unsigned width);`   | `psati.w`(RV64), `psati.w`(RV32)    |

### Packed Reduction Sum

Sum every element together to produce and add result to scalar accumulator.

#### 32-bit

Requires a zext.w to mask upper elements on RV64. RV64 may need a sext.w or
zext.w to extend result in some circumstances.

* TODO: Do we need a 64-bit accumulator version?

| Prototype                                                            | Instruction                               |
|----------------------------------------------------------------------|-------------------------------------------|
| `int32_t __riscv_predsum_i8x4_i32(int8x4_t rs1, int32_t rs2);`       | `predsum.bs`                              |
| `uint32_t __riscv_predsumu_u8x4_u32(uint8x4_t rs1, uint32_t rs2);`   | `predsumu.bs`                             |
| `int32_t __riscv_predsum_i16x2_i32(int16x2_t rs1, int32_t rs2);`     | `predsum.hs`                              |
| `uint32_t __riscv_predsumu_i16x2_u32(uint16x2_t rs1, uint32_t rs2);` | `predsumu.hs`                             |

#### 64-bit

Intrinsics are provided with 32-bit and 64-bit accumulator for maximum software compatibility between RV32 and RV64.
This will incur additional instructions when accumulator size is not XLEN.

| Prototype                                                            | Instruction                               |
|----------------------------------------------------------------------|-------------------------------------------|
| `int32_t __riscv_predsum_i8x8_i32(int8x8_t rs1, int32_t rs2);`       | `predsum.bs`(RV64), `predsum.dbs`(RV32)   |
| `uint32_t __riscv_predsumu_u8x8_u32(uint8x8_t rs1, uint32_t rs2);`   | `predsumu.bs`(RV64), `predsumu.dbs`(RV32) |
| `int32_t __riscv_predsum_i16x4_i32(int16x4_t rs1, int32_t rs2);`     | `predsum.hs`(RV64), `predsum.dhs`(RV32)   |
| `uint32_t __riscv_predsumu_i16x4_u32(uint16x4_t rs1, uint32_t rs2);` | `predsumu.hs`(RV64), `predsumu.dhs`(RV32) |
| `int64_t __riscv_predsum_i8x8_i64(int8x8_t rs1, int64_t rs2);`       | `predsum.bs`(RV64), `predsum.dbs`(RV32)   |
| `uint64_t __riscv_predsumu_u8x8_u64(uint8x8_t rs1, uint64_t rs2);`   | `predsumu.bs`(RV64), `predsumu.dbs`(RV32) |
| `int64_t __riscv_predsum_i16x4_i64(int16x4_t rs1, int64_t rs2);`     | `predsum.hs`(RV64), `predsum.dhs`(RV32)   |
| `uint64_t __riscv_predsumu_i16x4_u64(uint16x4_t rs1, uint64_t rs2);` | `predsumu.hs`(RV64), `predsum.dhs`(RV32)  |
| `int64_t __riscv_predsum_i32x2_i64(int32x2_t rs1, int64_t rs2);`     | `predsum.ws`(RV64), `waddu`+`addd`(RV32)  |
| `uint64_t __riscv_predsumu_i32x2_u64(uint32x2_t rs1, uint64_t rs2);` | `predsumu.ws`(RV64), `wadd`+`addd`(RV32)  |

### Packed Addition and Subtraction

Addition/subtract of packed vectors. Signed and unsigned versions are provided
to avoid casts.

`pneg` is provided for convenience.

#### 32-bit

| Prototype                                                        | Instruction                                       |
|------------------------------------------------------------------|---------------------------------------------------|
| `int8x4_t __riscv_padd_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `padd.b`                                          |
| `uint8x4_t __riscv_padd_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `padd.b`                                          |
| `int16x2_t __riscv_padd_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `padd.h`                                          |
| `uint16x2_t __riscv_padd_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `padd.h`                                          |
| `int8x4_t __riscv_psub_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `psub.b`                                          |
| `uint8x4_t __riscv_psub_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `psub.b`                                          |
| `int16x2_t __riscv_psub_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `psub.h`                                          |
| `uint16x2_t __riscv_psub_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `psub.h`                                          |
| `int8x4_t __riscv_pneg_i8x4(int8x4_t rs2);`                      | `psub.b`(rs1=x0)                                  |
| `int16x2_t __riscv_pneg_i16x2(int16x2_t rs2);`                   | `psub.h`(rs1=x0)                                  |

#### 64-bit

| Prototype                                                        | Instruction                                       |
|------------------------------------------------------------------|---------------------------------------------------|
| `int8x8_t __riscv_padd_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `padd.b`(RV64), `padd.db`(RV32)                   |
| `uint8x8_t __riscv_padd_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `padd.b`(RV64), `padd.db`(RV32)                   |
| `int16x4_t __riscv_padd_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `padd.h`(RV64), `padd.dh`(RV32)                   |
| `uint16x4_t __riscv_padd_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `padd.h`(RV64), `padd.dh`(RV32)                   |
| `int32x2_t __riscv_padd_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `padd.w`(RV64), `padd.dw`(RV32)                   |
| `uint32x2_t __riscv_padd_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `padd.w`(RV64), `padd.dw`(RV32)                   |
| `int8x8_t __riscv_psub_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `psub.b`(RV64), `psub.db`(RV32)                   |
| `uint8x8_t __riscv_psub_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `psub.b`(RV64), `psub.db`(RV32)                   |
| `int16x4_t __riscv_psub_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `psub.h`(RV64), `psub.dh`(RV32)                   |
| `uint16x4_t __riscv_psub_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `psub.h`(RV64), `psub.dh`(RV32)                   |
| `int32x2_t __riscv_psub_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `psub.w`(RV64), `psub.dw`(RV32)                   |
| `uint32x2_t __riscv_psub_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `psub.w`(RV64), `psub.dw`(RV32)                   |
| `int8x8_t __riscv_pneg_i8x8(int8x8_t rs1);`                      | `psub.b`(rs1=x0)(RV64), `psub.db`(rs1_p=x0)(RV32) |
| `int16x4_t __riscv_pneg_i16x4(int16x4_t rs1);`                   | `psub.h`(rs1=x0)(RV64), `psub.dh`(rs1_p=x0)(RV32) |
| `int32x2_t __riscv_pneg_i32x2(int32x2_t rs1);`                   | `psub.w`(rs1=x0)(RV64), `psub.dw`(rs1_p=x0)(RV32) |

### Packed Saturating Addition and Subtraction

#### 32-bit

| Prototype                                                          | Instruction                         |
|--------------------------------------------------------------------|-------------------------------------|
| `int8x4_t __riscv_psadd_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `psadd.b`                           |
| `int16x2_t __riscv_psadd_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `psadd.h`                           |
| `uint8x4_t __riscv_psaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `psaddu.b`                          |
| `uint16x2_t __riscv_psaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `psaddu.h`                          |
| `int8x4_t __riscv_pssub_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `pssub.b`                           |
| `int16x2_t __riscv_pssub_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pssub.h`                           |
| `uint8x4_t __riscv_pssubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `pssubu.b`                          |
| `uint16x2_t __riscv_pssubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pssubu.h`                          |

#### 64-bit

| Prototype                                                          | Instruction                         |
|--------------------------------------------------------------------|-------------------------------------|
| `int8x8_t __riscv_psadd_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `psadd.b`(RV64), `psadd.db`(RV32)   |
| `int16x4_t __riscv_psadd_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `psadd.h`(RV64), `psadd.dh`(RV32)   |
| `int32x2_t __riscv_psadd_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `psadd.w`(RV64), `psadd.dw`(RV32)   |
| `uint8x8_t __riscv_psaddu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `psaddu.b`(RV64), `psaddu.db`(RV32) |
| `uint16x4_t __riscv_psaddu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `psaddu.h`(RV64), `psaddu.dh`(RV32) |
| `uint32x2_t __riscv_psaddu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `psaddu.w`(RV64), `psaddu.dw`(RV32) |
| `int8x8_t __riscv_pssub_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `pssub.b`(RV64), `pssub.db`(RV32)   |
| `int16x4_t __riscv_pssub_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `pssub.h`(RV64), `pssub.dh`(RV32)   |
| `int32x2_t __riscv_pssub_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pssub.w`(RV64), `pssub.dw`(RV32)   |
| `uint8x8_t __riscv_pssubu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `pssubu.b`(RV64), `pssubu.db`(RV32) |
| `uint16x4_t __riscv_pssubu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pssubu.h`(RV64), `pssubu.dh`(RV32) |
| `uint32x2_t __riscv_pssubu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `pssubu.w`(RV64), `pssubu.dw`(RV32) |

### Packed Averaging Addition and Subtraction

#### 32-bit

| Prototype                                                          | Instruction                         |
|--------------------------------------------------------------------|-------------------------------------|
| `int8x4_t __riscv_paadd_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `psadd.b`                           |
| `int16x2_t __riscv_paadd_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `psadd.h`                           |
| `uint8x4_t __riscv_paaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `psaddu.b`                          |
| `uint16x2_t __riscv_paaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `psaddu.h`                          |
| `int8x4_t __riscv_pasub_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `pasub.b`                           |
| `int16x2_t __riscv_pasub_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pasub.h`                           |
| `uint8x4_t __riscv_pasubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `pasubu.b`                          |
| `uint16x2_t __riscv_pasubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pasubu.h`                          |

#### 64-bit

| Prototype                                                          | Instruction                         |
|--------------------------------------------------------------------|-------------------------------------|
| `int8x8_t __riscv_paadd_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `paadd.b`(RV64), `paadd.db`(RV32)   |
| `int16x4_t __riscv_paadd_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `paadd.h`(RV64), `paadd.dh`(RV32)   |
| `int32x2_t __riscv_paadd_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `paadd.w`(RV64), `paadd.dw`(RV32)   |
| `uint8x8_t __riscv_paaddu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `paaddu.b`(RV64), `paaddu.db`(RV32) |
| `uint16x4_t __riscv_paaddu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `paaddu.h`(RV64), `paaddu.dh`(RV32) |
| `uint32x2_t __riscv_paaddu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `paaddu.w`(RV64), `paaddu.dw`(RV32) |
| `int8x8_t __riscv_pasub_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `pasub.b`(RV64), `pasub.db`(RV32)   |
| `int16x4_t __riscv_pasub_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `pasub.h`(RV64), `pasub.dh`(RV32)   |
| `int32x2_t __riscv_pasub_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pasub.w`(RV64), `pasub.dw`(RV32)   |
| `uint8x8_t __riscv_pasubu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `pasubu.b`(RV64), `pasubu.db`(RV32) |
| `uint16x4_t __riscv_pasubu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pasubu.h`(RV64), `pasubu.dh`(RV32) |
| `uint32x2_t __riscv_pasubu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `pasubu.w`(RV64), `pasubu.dw`(RV32) |

### Packed Absolute Difference

#### 32-bit

| Prototype                                                         | Instruction                       |
|-------------------------------------------------------------------|-----------------------------------|
| `uint8x4_t __riscv_pabd_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `pabd.b`                          |
| `uint16x2_t __riscv_pabd_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `pabd.h`                          |
| `uint8x4_t __riscv_pabdu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `pabdu.b`                         |
| `uint16x2_t __riscv_pabdu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pabdu.h`                         |

#### 64-bit

| Prototype                                                         | Instruction                       |
|-------------------------------------------------------------------|-----------------------------------|
| `uint8x8_t __riscv_pabd_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `pabd.b`(RV64), `pabd.db`(RV32)   |
| `uint16x4_t __riscv_pabd_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `pabd.h`(RV64), `pabd.dh`(RV32)   |
| `uint8x8_t __riscv_pabdu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `pabdu.b`(RV64), `pabdu.db`(RV32) |
| `uint16x4_t __riscv_pabdu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pabdu.h`(RV64), `pabdu.dh`(RV32) |

### Packed Merge

Bitwidth merge using the mask in `rd`. If mask is 0, bit from `rs1` selected else
the bit from `rs2` is selected. Signed and unsigned versions provided to avoid
casts.

Compiler will choose `merge`, `mvm`, or `mvmn` opcode to minimize register copies.

#### 32-bit

| Prototype                                                                        | Instruction            |
|----------------------------------------------------------------------------------|------------------------|
| `uint8x4_t __riscv_merge_u8x4(uint8x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`      | `merge`, `mvm`, `mvmn` |
| `int8x4_t __riscv_merge_i8x4(uint8x4_t rd, int8x4_t rs1, int8x4_t rs2);`         | `merge`, `mvm`, `mvmn` |
| `uint16x2_t __riscv_merge_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `merge`, `mvm`, `mvmn` |
| `int16x2_t __riscv_merge_i16x2(uint16x2_t rd, int16x2_t rs1, int16x2_t rs2);`    | `merge`, `mvm`, `mvmn` |

#### 64-bit

| Prototype                                                                        | Instruction            |
|----------------------------------------------------------------------------------|------------------------|
| `uint8x8_t __riscv_merge_u8x8(uint8x8_t rd, uint8x8_t rs1, uint8x8_t rs2);`      | `merge`, `mvm`, `mvmn` |
| `int8x8_t __riscv_merge_i8x8(uint8x8_t rd, int8x8_t rs1, int8x8_t rs2);`         | `merge`, `mvm`, `mvmn` |
| `uint16x4_t __riscv_merge_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);` | `merge`, `mvm`, `mvmn` |
| `int16x4_t __riscv_merge_i16x4(uint16x4_t rd, int16x4_t rs1, int16x4_t rs2);`    | `merge`, `mvm`, `mvmn` |
| `uint32x2_t __riscv_merge_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);` | `merge`, `mvm`, `mvmn` |
| `int32x2_t __riscv_merge_i32x2(uint32x2_t rd, int32x2_t rs1, int32x2_t rs2);`    | `merge`, `mvm`, `mvmn` |

### Packed Absolute Difference Sum

#### 32-bit

Requires a zext.w to mask upper elements on RV64. RV64 may need a sext.w or
zext.w to extend result in some circumstances.

* TODO: Do we need a 64-bit accumulator version?

| Prototype                                                                         | Instruction   |
|-----------------------------------------------------------------------------------|---------------|
| `uint32_t __riscv_pabdsumu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                   | `pabdsumu.b`  |
| `uint32_t __riscv_pabdsumau_u8x4_u32(uint32_t rd, uint8x4_t rs1, uint8x4_t rs2);` | `pabdsumau.b` |

#### 64-bit (RV64 Only)

| Prototype                                                                         | Instruction   |
|-----------------------------------------------------------------------------------|---------------|
| `uint64_t __riscv_pabdsumu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                   | `pabdsumu.b`  |
| `uint64_t __riscv_pabdsumau_u8x8_u64(uint64_t rd, uint8x8_t rs1, uint8x8_t rs2);` | `pabdsumau.b` |

### Packed SH1ADD and SSH1SADD

#### 32-bit

| Prototype                                                          | Instruction                               |
|--------------------------------------------------------------------|-------------------------------------------|
| `int16x2_t __riscv_psh1add_i16x2(int16x2_t rs1, int16x2_t rs2);`   | `psh1add.h`                               |
| `int16x2_t __riscv_pssh1sadd_i16x2(int16x2_t rs1, int16x2_t rs2);` | `pssh1sadd.h`                             |

#### 64-bit

| Prototype                                                          | Instruction                               |
|--------------------------------------------------------------------|-------------------------------------------|
| `int16x4_t __riscv_psh1add_i16x4(int16x4_t rs1, int16x4_t rs2);`   | `psh1add.h`(RV64), `psh1add.dh`(RV32)     |
| `int32x2_t __riscv_psh1add_i32x2(int32x2_t rs1, int32x2_t rs2);`   | `psh1add.w`(RV64), `psh1add.dw`(RV32)     |
| `int16x4_t __riscv_pssh1sadd_i16x4(int16x4_t rs1, int16x4_t rs2);` | `pssh1sadd.h`(RV64), `pssh1sadd.dh`(RV32) |
| `int32x2_t __riscv_pssh1sadd_i32x2(int32x2_t rs1, int32x2_t rs2);` | `pssh1sadd.w`(RV64), `pssh1sadd.dw`(RV32) |

### Packed Pair

#### 32-bit

| Prototype                                                           | Instruction                           |
|---------------------------------------------------------------------|---------------------------------------|
| `uint8x4_t __riscv_ppaire_u8x4(uint8x4_t rs1, uint8x4_t rs2);`      | `ppaire.b`                            |
| `int8x4_t __riscv_ppaireo_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `ppaireo.b`                           |
| `uint8x4_t __riscv_ppaireo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `ppaireo.b`                           |
| `int8x4_t __riscv_ppairoe_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `ppairoe.b`                           |
| `uint8x4_t __riscv_ppairoe_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `ppairoe.b`                           |
| `uint8x4_t __riscv_ppairo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`      | `ppairo.b`                            |
| `int8x4_t __riscv_ppairo_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `ppairo.b`                            |
| `uint16x2_t __riscv_ppaire_u16x2(uint16x2_t rs1, uint16x2_t rs2);`  | `pack`(RV32), `ppaire.h`(RV64)        |
| `int16x2_t __riscv_ppaire_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pack`(RV32), `ppaire.h`(RV64)        |
| `uint16x2_t __riscv_ppaireo_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `ppaireo.h`                           |
| `int16x2_t __riscv_ppaireo_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `ppaireo.h`                           |
| `uint16x2_t __riscv_ppairoe_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `ppairoe.h`                           |
| `int16x2_t __riscv_ppairoe_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `ppairoe.h`                           |
| `uint16x2_t __riscv_ppairo_u16x2(uint16x2_t rs1, uint16x2_t rs2);`  | `ppairo.h`                            |
| `int16x2_t __riscv_ppairo_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `ppairo.h`                            |

# ### 64-bit

| Prototype                                                           | Instruction                           |
|---------------------------------------------------------------------|---------------------------------------|
| `uint8x8_t __riscv_ppaire_u8x8(uint8x8_t rs1, uint8x8_t rs2);`      | `ppaire.b`(RV64), `ppaire.db`(RV32)   |
| `int8x8_t __riscv_ppaire_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `ppaire.b`(RV64), `ppaire.db`(RV32)   |
| `uint8x8_t __riscv_ppaireo_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `ppaireo.b`(RV64), `ppaireo.db`(RV32) |
| `int8x8_t __riscv_ppaireo_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `ppaireo.b`(RV64), `ppaireo.db`(RV32) |
| `uint8x8_t __riscv_ppairoe_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `ppairoe.b`(RV64), `ppairoe.db`(RV32) |
| `int8x8_t __riscv_ppairoe_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `ppairoe.b`(RV64), `ppairoe.db`(RV32) |
| `uint8x8_t __riscv_ppairo_u8x8(uint8x8_t rs1, uint8x8_t rs2);`      | `ppairo.b`(RV64), `ppairo.db`(RV32)   |
| `int8x8_t __riscv_ppairo_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `ppairo.b`(RV64), `ppairo.db`(RV32)   |
| `uint16x4_t __riscv_ppaire_u16x4(uint16x4_t rs1, uint16x4_t rs2);`  | `ppaire.h`(RV64), `ppaire.dh`(RV32)   |
| `int16x4_t __riscv_ppaire_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `ppaire.h`(RV64), `ppaire.dh`(RV32)   |
| `uint16x4_t __riscv_ppaireo_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `ppaireo.h`(RV64), `ppaireo.dh`(RV32) |
| `int16x4_t __riscv_ppaireo_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `ppaireo.h`(RV64), `ppaireo.dh`(RV32) |
| `uint16x4_t __riscv_ppairoe_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `ppairoe.h`(RV64), `ppairoe.dh`(RV32) |
| `int16x4_t __riscv_ppairoe_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `ppairoe.h`(RV64), `ppairoe.dh`(RV32) |
| `uint16x4_t __riscv_ppairo_u16x4(uint16x4_t rs1, uint16x4_t rs2);`  | `ppairo.h`(RV64), `ppairo.dh`(RV32)   |
| `int16x4_t __riscv_ppairo_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `ppairo.h`(RV64), `ppairo.dh`(RV32)   |

# ### 64-bit (RV64 Only)

| Prototype                                                           | Instruction                           |
|---------------------------------------------------------------------|---------------------------------------|
| `uint32x2_t __riscv_ppaire_u32x2(uint32x2_t rs1, uint32x2_t rs2);`  | `pack`                                |
| `int32x2_t __riscv_ppaire_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pack`                                |
| `uint32x2_t __riscv_ppaireo_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `ppaireo.w`                           |
| `int32x2_t __riscv_ppaireo_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `ppaireo.w`                           |
| `uint32x2_t __riscv_ppairoe_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `ppairoe.w`                           |
| `int32x2_t __riscv_ppairoe_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `ppairoe.w`                           |
| `uint32x2_t __riscv_ppairo_u32x2(uint32x2_t rs1, uint32x2_t rs2);`  | `ppairo.w`                            |
| `int32x2_t __riscv_ppairo_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `ppairo.w`                            |

### Packed Multiplication with Horizontal Addition

#### 32-bit

| Prototype                                                                         | Instruction   |
|-----------------------------------------------------------------------------------|---------------|
| `int32_t __riscv_pm4add_i8x4(int8x4_t rs1, int8x4_t rs2);`                        | `pm4add.b`    |
| `int32_t __riscv_pm2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pm2add.h`    |
| `int32_t __riscv_pm4adda_i8x4(int32_t rd, int8x4_t rs1, int8x4_t rs2);`           | `pm4adda.b`   |
| `int32_t __riscv_pm2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `pm2adda.h`   |
| `int32_t __riscv_pm2add_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                   | `pm2add.hx`   |
| `int32_t __riscv_pm2adda_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pm2adda.hx`  |
| `uint32_t __riscv_pm4addu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                    | `pm4addu.b`   |
| `uint32_t __riscv_pm2addu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | `pm2addu.h`   |
| `uint32_t __riscv_pm4addau_u8x4(uint32_t rd, uint8x4_t rs1, uint8x4_t rs2);`      | `pm4addau.b`  |
| `uint32_t __riscv_pm2addau_u16x2(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`   | `pm2addau.h`  |
| `int32_t __riscv_pmq2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `pmq2add.h`   |
| `int32_t __riscv_pmqr2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                   | `pmqr2add.h`  |
| `int32_t __riscv_pmq2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pmq2adda.h`  |
| `int32_t __riscv_pmqr2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pmqr2adda.h` |
| `int32_t __riscv_pm2sadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `pm2sadd.h`   |
| `int32_t __riscv_pm2sadd_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                  | `pm2sadd.hx`  |
| `int32_t __riscv_pm2sub_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pm2sub.h`    |
| `int32_t __riscv_pm2suba_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `pm2suba.h`   |
| `int32_t __riscv_pm2sub_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                   | `pm2sub.hx`   |
| `int32_t __riscv_pm2suba_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pm2suba.hx`  |
| `int32_t __riscv_pm4addsu_i8x4(int8x4_t rs1, uint8x4_t rs2);`                     | `pm4addsu.b`  |
| `int32_t __riscv_pm2addsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                  | `pm2addsu.h`  |
| `int32_t __riscv_pm4addasu_i8x4(int32_t rd, int8x4_t rs1, uint8x4_t rs2);`        | `pm4addasu.b` |
| `int32_t __riscv_pm2addasu_i16x2(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`     | `pm2addasu.h` |

#### 64-bit (RV64 Only)

* TODO: These do not have a single RV32 instruction, but could be emulated.

| Prototype                                                                           | Instruction   |
|-------------------------------------------------------------------------------------|---------------|
| `int32x2_t __riscv_pm4add_i8x8(int8x8_t rs1, int8x8_t rs2);`                        | `pm4add.b`    |
| `int32x2_t __riscv_pm2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pm2add.h`    |
| `int32x2_t __riscv_pm4adda_i8x8(int32x2_t rd, int8x8_t rs1, int8x8_t rs2);`         | `pm4adda.b`   |
| `int32x2_t __riscv_pm2adda_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pm2adda.h`   |
| `int32x2_t __riscv_pm2add_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pm2add.hx`   |
| `int32x2_t __riscv_pm2adda_x_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`    | `pm2adda.hx`  |
| `uint32x2_t __riscv_pm4addu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                    | `pm4addu.b`   |
| `uint32x2_t __riscv_pm2addu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                 | `pm2addu.h`   |
| `uint32x2_t __riscv_pm4addau_u8x8(uint32x2_t rd, uint8x8_t rs1, uint8x8_t rs2);`    | `pm4addau.b`  |
| `uint32x2_t __riscv_pm2addau_u16x4(uint32x2_t rd, uint16x4_t rs1, uint16x4_t rs2);` | `pm2addau.h`  |
| `int32x2_t __riscv_pmq2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                    | `pmq2add.h`   |
| `int32x2_t __riscv_pmqr2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pmqr2add.h`  |
| `int32x2_t __riscv_pmq2adda_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`     | `pmq2adda.h`  |
| `int32x2_t __riscv_pmqr2adda_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`    | `pmqr2adda.h` |
| `int32x2_t __riscv_pm2sadd_i16x4(int16x4_t rs1, int16x4_t rs2);`                    | `pm2sadd.h`   |
| `int32x2_t __riscv_pm2sadd_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                  | `pm2sadd.hx`  |
| `int32x2_t __riscv_pm2sub_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pm2sub.h`    |
| `int32x2_t __riscv_pm2suba_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pm2suba.h`   |
| `int32x2_t __riscv_pm2sub_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pm2sub.hx`   |
| `int32x2_t __riscv_pm2suba_x_i16x4(int32x2_t rd, int16x4_t rs1, int16x4_t rs2);`    | `pm2suba.hx`  |
| `int32x2_t __riscv_pm4addsu_i8x8(int8x8_t rs1, uint8x8_t rs2);`                     | `pm4addsu.b`  |
| `int32x2_t __riscv_pm2addsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                  | `pm2addsu.h`  |
| `int32x2_t __riscv_pm4addasu_i8x8(int32x2_t rd, int8x8_t rs1, uint8x8_t rs2);`      | `pm4addasu.b` |
| `int32x2_t __riscv_pm2addasu_i16x4(int32x2_t rd, int16x4_t rs1, uint16x4_t rs2);`   | `pm2addasu.h` |
| `int64_t __riscv_pm2add_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pm2add.w`    |
| `int64_t __riscv_pm2adda_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `pm2adda.w`   |
| `int64_t __riscv_pm2add_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pm2add.wx`   |
| `int64_t __riscv_pm2adda_x_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pm2adda.wx`  |
| `uint64_t __riscv_pm2addu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pm2addu.w`   |
| `uint64_t __riscv_pm2addau_u32x2(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`     | `pm2addau.w`  |
| `int64_t __riscv_pmq2add_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pmq2add.w`   |
| `int64_t __riscv_pmq2adda_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`         | `pmq2adda.w`  |
| `int64_t __riscv_pm2sub_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pm2sub.w`    |
| `int64_t __riscv_pm2suba_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `pm2suba.w`   |
| `int64_t __riscv_pm2sub_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pm2sub.wx`   |
| `int64_t __riscv_pm2suba_x_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pm2suba.wx`  |
| `int64_t __riscv_pm2addsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`                    | `pm2addsu.w`  |
| `int64_t __riscv_pm2addasu_i32x2(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`       | `pm2addasu.w` |
| `int64_t __riscv_pmqr2add_i16x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmqr2add.w`  |
| `int64_t __riscv_pmqr2adda_i16x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pmqr2adda.w` |
| `int64_t __riscv_pm4add_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `pm4add.h`    |
| `int64_t __riscv_pm4adda_i16x4(int64_t rd, int16x4_t rs1, int16x4_t rs2);`          | `pm4adda.h`   |
| `uint64_t __riscv_pm4addu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pm4addu.h`   |
| `uint64_t __riscv_pm4addau_u16x4(uint64_t rd, uint16x4_t rs1, uint16x4_t rs2);`     | `pm4addau.h`  |
| `int64_t __riscv_pm4addsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                    | `pm4addsu.h`  |
| `int64_t __riscv_pm4addasu_i16x4(int64_t rd, int16x4_t rs1, uint16x4_t rs2);`       | `pm4addasu.h` |

### Packed Exchanged Addition and Subtraction

#### 32-bit

| Prototype                                                       | Instruction                       |
|-----------------------------------------------------------------|-----------------------------------|
| `int16x2_t __riscv_pas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`  | `pas.hx`                          |
| `int16x2_t __riscv_psa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`  | `psa.hx`                          |
| `int16x2_t __riscv_psas_x_i16x2(int16x2_t rs1, int16x2_t rs2);` | `psas.hx`                         |
| `int16x2_t __riscv_pssa_x_i16x2(int16x2_t rs1, int16x2_t rs2);` | `pssa.hx`                         |
| `int16x2_t __riscv_paas_x_i16x2(int16x2_t rs1, int16x2_t rs2);` | `paas.hx`                         |
| `int16x2_t __riscv_pasa_x_i16x2(int16x2_t rs1, int16x2_t rs2);` | `pasa.hx`                         |

#### 64-bit

| Prototype                                                       | Instruction                       |
|-----------------------------------------------------------------|-----------------------------------|
| `int16x4_t __riscv_pas_x_i16x4(int16x4_t rs1, int16x4_t rs2);`  | `pas.hx`(RV64), `pas.dhx`(RV32)   |
| `int16x4_t __riscv_psa_x_i16x4(int16x4_t rs1, int16x4_t rs2);`  | `psa.hx`(RV64), `psa.dhx`(RV32)   |
| `int16x4_t __riscv_psas_x_i16x4(int16x4_t rs1, int16x4_t rs2);` | `psas.hx`(RV64), `psas.dhx`(RV32) |
| `int16x4_t __riscv_pssa_x_i16x4(int16x4_t rs1, int16x4_t rs2);` | `pssa.hx`(RV64), `pssa.dhx`(RV32) |
| `int16x4_t __riscv_paas_x_i16x4(int16x4_t rs1, int16x4_t rs2);` | `paas.hx`(RV64), `paas.dhx`(RV32) |
| `int16x4_t __riscv_pasa_x_i16x4(int16x4_t rs1, int16x4_t rs2);` | `pasa.hx`(RV64), `pasa.dhx`(RV32) |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                       | Instruction                       |
|-----------------------------------------------------------------|-----------------------------------|
| `int32x2_t __riscv_pas_x_i32x2(int32x2_t rs1, int32x2_t rs2);`  | `pas.wx`                          |
| `int32x2_t __riscv_psa_x_i32x2(int32x2_t rs1, int32x2_t rs2);`  | `psa.wx`                          |
| `int32x2_t __riscv_psas_x_i32x2(int32x2_t rs1, int32x2_t rs2);` | `psas.wx`                         |
| `int32x2_t __riscv_pssa_x_i32x2(int32x2_t rs1, int32x2_t rs2);` | `pssa.wx`                         |
| `int32x2_t __riscv_paas_x_i32x2(int32x2_t rs1, int32x2_t rs2);` | `paas.wx`                         |
| `int32x2_t __riscv_pasa_x_i32x2(int32x2_t rs1, int32x2_t rs2);` | `pasa.wx`                         |

### Packed Comparisons

Result of all comparison is an unsigned type regardless of input type. `pmseq`
is provided a signed and unsigned version.

#### 32-bit

| Prototype                                                                           | Instruction                        |
|-------------------------------------------------------------------------------------|------------------------------------|
| `uint8x4_t __riscv_pmseq_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pmseq.b`                          |
| `uint8x4_t __riscv_pmseq_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | `pmseq.b`                          |
| `uint16x2_t __riscv_pmseq_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmseq.h`                          |
| `uint16x2_t __riscv_pmseq_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pmseq.h`                          |
| `uint8x4_t __riscv_pmslt_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pmslt.b`                          |
| `uint16x2_t __riscv_pmslt_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmslt.h`                          |
| `uint8x4_t __riscv_pmsgt_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pmslt.b` swapped operands         |
| `uint16x2_t __riscv_pmsgt_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmslt.h` swapped operands         |
| `uint8x4_t __riscv_pmsltu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pmsltu.b`                         |
| `uint16x2_t __riscv_pmsltu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pmsltu.h`                         |
| `uint8x4_t __riscv_pmsgtu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pmsltu.b` swapped operands        |
| `uint16x2_t __riscv_pmsgtu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pmsltu.h` swapped operands        |

* TODO: pmseq/pmslt/etc return unsigned type but take signed/unsigned input types. Should we list both types?

#### 64-bit

| Prototype                                                                           | Instruction                                         |
|-------------------------------------------------------------------------------------|-----------------------------------------------------|
| `uint8x8_t __riscv_pmseq_i8x8(int8x8_t rs1, int8x8_t rs2);`                         | `pmseq.b`(RV64), `pmseq.db`(RV32)                   |
| `uint8x8_t __riscv_pmseq_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                       | `pmseq.b`(RV64), `pmseq.db`(RV32)                   |
| `uint16x4_t __riscv_pmseq_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmseq.h`(RV64), `pmseq.dh`(RV32)                   |
| `uint16x4_t __riscv_pmseq_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pmseq.h`(RV64), `pmseq.dh`(RV32)                   |
| `uint32x2_t __riscv_pmseq_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmseq.w`(RV64), `pmseq.dw`(RV32)                   |
| `uint32x2_t __riscv_pmseq_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pmseq.w`(RV64), `pmseq.dw`(RV32)                   |
| `uint8x8_t __riscv_pmslt_i8x8(int8x8_t rs1, int8x8_t rs2);`                         | `pmslt.b`(RV64), `pmslt.db`(RV32)                   |
| `uint16x4_t __riscv_pmslt_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dh`(RV32)                   |
| `uint32x2_t __riscv_pmslt_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dw`(RV32)                   |
| `uint8x8_t __riscv_pmsgt_i8x8(int8x8_t rs1, int8x8_t rs2);`                         | `pmslt.b`(RV64), `pmslt.db`(RV32) swapped operands  |
| `uint16x4_t __riscv_pmsgt_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dh`(RV32) swapped operands  |
| `uint32x2_t __riscv_pmsgt_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dw`(RV32) swapped operands  |
| `uint8x8_t __riscv_pmsltu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `pmsltu.b`(RV64), `pmslt.db`(RV32)                  |
| `uint16x4_t __riscv_pmsltu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pmsltu.h`(RV64), `pmslt.dh`(RV32)                  |
| `uint32x2_t __riscv_pmsltu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pmsltu.w`(RV64), `pmslt.dw`(RV32)                  |
| `uint8x8_t __riscv_pmsgtu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `pmsltu.b`(RV64), `pmslt.db`(RV32) swapped operands |
| `uint16x4_t __riscv_pmsgtu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pmsltu.h`(RV64), `pmslt.dh`(RV32) swapped operands |
| `uint32x2_t __riscv_pmsgtu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pmsltu.w`(RV64), `pmslt.dw`(RV32) swapped operands |

TODO: pmseqz/pmsnez/pmsgtz/pmsltz? Allows x0 usage without pmv_s intrisic.

### Packed Minimum and Maximum

#### 32-bit

| Prototype                                                         | Instruction                       |
|-------------------------------------------------------------------|-----------------------------------|
| `int8x4_t __riscv_pmin_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `pmin.b`                          |
| `int16x2_t __riscv_pmin_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pmin.h`                          |
| `uint8x4_t __riscv_pminu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `pminu.b`                         |
| `uint16x2_t __riscv_pminu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pminu.h`                         |
| `int8x4_t __riscv_pmax_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `pmax.b`                          |
| `int16x2_t __riscv_pmax_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pmax.h`                          |
| `uint8x4_t __riscv_pmaxu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `pmaxu.b`                         |
| `uint16x2_t __riscv_pmaxu_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pmaxu.h`                         |

#### 64-bit

| Prototype                                                         | Instruction                       |
|-------------------------------------------------------------------|-----------------------------------|
| `int8x8_t __riscv_pmin_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `pmin.b`(RV64), `pmin.db`(RV32)   |
| `int16x4_t __riscv_pmin_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `pmin.h`(RV64), `pmin.dh`(RV32)   |
| `int32x2_t __riscv_pmin_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pmin.w`(RV64), `pmin.dw`(RV32)   |
| `uint8x8_t __riscv_pminu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `pminu.b`(RV64), `pminu.db`(RV32) |
| `uint16x4_t __riscv_pminu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pminu.h`(RV64), `pminu.dh`(RV32) |
| `uint32x2_t __riscv_pminu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `pminu.w`(RV64), `pminu.dw`(RV32) |
| `int8x8_t __riscv_pmax_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `pmax.b`(RV64), `pmax.db`(RV32)   |
| `int16x4_t __riscv_pmax_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `pmax.h`(RV64), `pmax.dh`(RV32)   |
| `int32x2_t __riscv_pmax_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pmax.w`(RV64), `pmax.dw`(RV32)   |
| `uint8x8_t __riscv_pmaxu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `pmaxu.b`(RV64), `pmaxu.db`(RV32) |
| `uint16x4_t __riscv_pmaxu_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pmaxu.h`(RV64), `pmaxu.dh`(RV32) |
| `uint32x2_t __riscv_pmaxu_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `pmaxu.w`(RV64), `pmaxu.dw`(RV32) |

### Packed Multiply High

#### 32-bit

| Prototype                                                           | Instruction        |
|---------------------------------------------------------------------|--------------------|
| `int16x2_t __riscv_pmulh_i16x2(int16x2_t rs1, int16x2_t rs2);`      | `pmulh.h`          |
| `int16x2_t __riscv_pmulhr_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `pmulhr.h`         |
| `uint16x2_t __riscv_pmulhu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`  | `pmulhu.h`         |
| `uint16x2_t __riscv_pmulhru_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `pmulhru.h`        |
| `int16x2_t __riscv_pmulhsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`   | `pmulhsu.h`        |
| `int16x2_t __riscv_pmulhrsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`  | `pmulhrsu.h`       |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                           | Instruction        |
|---------------------------------------------------------------------|--------------------|
| `int16x4_t __riscv_pmulh_i16x4(int16x4_t rs1, int16x4_t rs2);`      | `pmulh.h`(RV64)    |
| `int32x2_t __riscv_pmulh_i32x2(int32x2_t rs1, int32x2_t rs2);`      | `pmulh.w`(RV64)    |
| `int16x4_t __riscv_pmulhr_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `pmulhr.h`(RV64)   |
| `int32x2_t __riscv_pmulhr_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `pmulhr.w`(RV64)   |
| `uint16x4_t __riscv_pmulhu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`  | `pmulhu.h`(RV64)   |
| `uint32x2_t __riscv_pmulhu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`  | `pmulhu.w`(RV64)   |
| `uint16x4_t __riscv_pmulhru_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `pmulhru.h`(RV64)  |
| `uint32x2_t __riscv_pmulhru_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `pmulhru.w`(RV64)  |
| `int16x4_t __riscv_pmulhsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`   | `pmulhsu.h`(RV64)  |
| `int32x2_t __riscv_pmulhsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`   | `pmulhsu.w`(RV64)  |
| `int16x4_t __riscv_pmulhrsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`  | `pmulhrsu.h`(RV64) |
| `int32x2_t __riscv_pmulhrsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`  | `pmulhrsu.w`(RV64) |

### Packed Multiply High Accumulate

#### 32-bit

| Prototype                                                                           | Instruction         |
|-------------------------------------------------------------------------------------|---------------------|
| `int16x2_t __riscv_pmhacc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pmhacc.h`          |
| `int16x2_t __riscv_pmhracc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pmhracc.h`         |
| `uint16x2_t __riscv_pmhaccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | `pmhaccu.h`         |
| `uint16x2_t __riscv_pmhraccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pmhraccu.h`        |
| `int16x2_t __riscv_pmhaccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`    | `pmhaccsu.h`        |
| `int16x2_t __riscv_pmhraccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`   | `pmhraccsu.h`       |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                                           | Instruction         |
|-------------------------------------------------------------------------------------|---------------------|
| `int16x4_t __riscv_pmhacc_i16x4(int16x4_t rd, int16x4_t rs1, int16x4_t rs2);`       | `pmhacc.h`          |
| `int32x2_t __riscv_pmhacc_i32x2(int32x2_t rd, int32x2_t rs1, int32x2_t rs2);`       | `pmhacc.w`          |
| `int16x4_t __riscv_pmhracc_i16x4(int16x4_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pmhracc.h`         |
| `int32x2_t __riscv_pmhracc_i32x2(int32x2_t rd, int32x2_t rs1, int32x2_t rs2);`      | `pmhracc.w`         |
| `uint16x4_t __riscv_pmhaccu_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);`  | `pmhaccu.h`         |
| `uint32x2_t __riscv_pmhaccu_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);`  | `pmhaccu.w`         |
| `uint16x4_t __riscv_pmhraccu_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);` | `pmhraccu.h`        |
| `uint32x2_t __riscv_pmhraccu_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);` | `pmhraccu.w`        |
| `int16x4_t __riscv_pmhaccsu_i16x4(int16x4_t rd, int16x4_t rs1, uint16x4_t rs2);`    | `pmhaccsu.h`        |
| `int32x2_t __riscv_pmhaccsu_i32x2(int32x2_t rd, int32x2_t rs1, uint32x2_t rs2);`    | `pmhaccsu.w`        |
| `int16x4_t __riscv_pmhraccsu_i16x4(int16x4_t rd, int16x4_t rs1, uint16x4_t rs2);`   | `pmhraccsu.h`       |
| `int32x2_t __riscv_pmhraccsu_i32x2(int32x2_t rd, int32x2_t rs1, uint32x2_t rs2);`   | `pmhraccsu.w`       |

### Packed "Q-format" Multiplication

#### 32-bit

| Prototype                                                       | Instruction      |
|-----------------------------------------------------------------|------------------|
| `int16x2_t __riscv_pmulq_i16x2(int16x2_t rs1, int16x2_t rs2);`  | `pmulq.h`        |
| `int16x2_t __riscv_pmulqr_i16x2(int16x2_t rs1, int16x2_t rs2);` | `pmulqr.h`       |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                       | Instruction      |
|-----------------------------------------------------------------|------------------|
| `int16x4_t __riscv_pmulq_i16x4(int16x4_t rs1, int16x4_t rs2);`  | `pmulq.h`        |
| `int32x2_t __riscv_pmulq_i32x2(int32x2_t rs1, int32x2_t rs2);`  | `pmulq.w`        |
| `int16x4_t __riscv_pmulqr_i16x4(int16x4_t rs1, int16x4_t rs2);` | `pmulqr.h`       |
| `int32x2_t __riscv_pmulqr_i32x2(int32x2_t rs1, int32x2_t rs2);` | `pmulqr.w`       |

### Packed Multiply Parts

#### 32-bit

| Prototype                                                            | Instruction                             |
|----------------------------------------------------------------------|-----------------------------------------|
| `int16x2_t __riscv_pmul_b00_i16x2(int8x4_t rs1, int8x4_t rs2);`      | `pmul.h.b00`                            |
| `int16x2_t __riscv_pmul_b01_i16x2(int8x4_t rs1, int8x4_t rs2);`      | `pmul.h.b01`                            |
| `int16x2_t __riscv_pmul_b11_i16x2(int8x4_t rs1, int8x4_t rs2);`      | `pmul.h.b11`                            |
| `uint16x2_t __riscv_pmulu_b00_u16x2(uint8x4_t rs1, uint8x4_t rs2);`  | `pmulu.h.b00`                           |
| `uint16x2_t __riscv_pmulu_b01_u16x2(uint8x4_t rs1, uint8x4_t rs2);`  | `pmulu.h.b01`                           |
| `uint16x2_t __riscv_pmulu_b11_u16x2(uint8x4_t rs1, uint8x4_t rs2);`  | `pmulu.h.b11`                           |
| `int16x2_t __riscv_pmulsu_b00_i16x2(int8x4_t rs1, uint8x4_t rs2);`   | `pmulsu.h.b00`                          |
| `int16x2_t __riscv_pmulsu_b11_i16x2(int8x4_t rs1, uint8x4_t rs2);`   | `pmulsu.h.b11`                          |
| `int32_t __riscv_mul_h00_i32(int16x2_t rs1, int16x2_t rs2);`         | `mul.h00`(RV32), `pmul.w.h00`(RV64)     |
| `int32_t __riscv_mul_h01_i32(int16x2_t rs1, int16x2_t rs2);`         | `mul.h01`(RV32), `pmul.w.h01`(RV64)     |
| `int32_t __riscv_mul_h11_i32(int16x2_t rs1, int16x2_t rs2);`         | `mul.h11`(RV32), `pmul.w.h11`(RV64)     |
| `uint32_t __riscv_mulu_h00_u32(uint16x2_t rs1, uint16x2_t rs2);`     | `mulu.h00`(RV32), `pmulu.w.h00`(RV64)   |
| `uint32_t __riscv_mulu_h01_u32(uint16x2_t rs1, uint16x2_t rs2);`     | `mulu.h01`(RV32), `pmulu.w.h01`(RV64)   |
| `uint32_t __riscv_mulu_h11_u32(uint16x2_t rs1, uint16x2_t rs2);`     | `mulu.h11`(RV32), `pmulu.w.h11`(RV64)   |
| `int32_t __riscv_mulsu_h00_i32(int16x2_t rs1, uint16x2_t rs2);`      | `mulsu.h00`(RV32), `pmulsu.w.h00`(RV64) |
| `int32_t __riscv_mulsu_h11_i32(int16x2_t rs1, uint16x2_t rs2);`      | `mulsu.h11`(RV32), `pmulsu.w.h11`(RV64) |

### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                            | Instruction                             |
|----------------------------------------------------------------------|-----------------------------------------|
| `int16x4_t __riscv_pmul_b00_i16x4(int8x8_t rs1, int8x8_t rs2);`      | `pmul.h.b00`                            |
| `int16x4_t __riscv_pmul_b01_i16x4(int8x8_t rs1, int8x8_t rs2);`      | `pmul.h.b01`                            |
| `int16x4_t __riscv_pmul_b11_i16x4(int8x8_t rs1, int8x8_t rs2);`      | `pmul.h.b11`                            |
| `uint16x4_t __riscv_pmulu_b00_u16x4(uint8x8_t rs1, uint8x8_t rs2);`  | `pmulu.h.b00`                           |
| `uint16x4_t __riscv_pmulu_b01_u16x4(uint8x8_t rs1, uint8x8_t rs2);`  | `pmulu.h.b01`                           |
| `uint16x4_t __riscv_pmulu_b11_u16x4(uint8x8_t rs1, uint8x8_t rs2);`  | `pmulu.h.b11`                           |
| `int16x4_t __riscv_pmulsu_b00_i16x4(int8x8_t rs1, uint8x8_t rs2);`   | `pmulsu.h.b00`                          |
| `int16x4_t __riscv_pmulsu_b11_i16x4(int8x8_t rs1, uint8x8_t rs2);`   | `pmulsu.h.b11`                          |
| `int32x2_t __riscv_pmul_h00_i32x2(int16x4_t rs1, int8x8_t rs2);`     | `pmul.w.h00`                            |
| `int32x2_t __riscv_pmul_h01_i32x2(int16x4_t rs1, int8x8_t rs2);`     | `pmul.w.h01`                            |
| `int32x2_t __riscv_pmul_h11_i32x2(int16x4_t rs1, int8x8_t rs2);`     | `pmul.w.h11`                            |
| `uint32x2_t __riscv_pmulu_h00_u32x2(uint16x4_t rs1, uint8x8_t rs2);` | `pmulu.w.h00`                           |
| `uint32x2_t __riscv_pmulu_h01_u32x2(uint16x4_t rs1, uint8x8_t rs2);` | `pmulu.w.h01`                           |
| `uint32x2_t __riscv_pmulu_h11_u32x2(uint16x4_t rs1, uint8x8_t rs2);` | `pmulu.w.h11`                           |
| `int32x2_t __riscv_pmulsu_h00_i32x2(int16x4_t rs1, uint8x8_t rs2);`  | `pmulsu.w.h00`                          |
| `int32x2_t __riscv_pmulsu_h11_i32x2(int16x4_t rs1, uint8x8_t rs2);`  | `pmulsu.w.h11`                          |
| `int64_t __riscv_mul_w00_i64(int32x2_t rs1, int32x2_t rs2);`         | `mul.w00`                               |
| `int64_t __riscv_mul_w01_i64(int32x2_t rs1, int32x2_t rs2);`         | `mul.w01`                               |
| `int64_t __riscv_mul_w11_i64(int32x2_t rs1, int32x2_t rs2);`         | `mul.w11`                               |
| `uint64_t __riscv_mulu_w00_i64(uint32x2_t rs1, uint32x2_t rs2);`     | `mulu.w00`                              |
| `uint64_t __riscv_mulu_w01_i64(uint32x2_t rs1, uint32x2_t rs2);`     | `mulu.w01`                              |
| `uint64_t __riscv_mulu_w11_i64(uint32x2_t rs1, uint32x2_t rs2);`     | `mulu.w11`                              |
| `int64_t __riscv_mulsu_w00_i64(int32x2_t rs1, uint32x2_t rs2);`      | `mulsu.w00`                             |
| `int64_t __riscv_mulsu_w11_i64(int32x2_t rs1, uint32x2_t rs2);`      | `mulsu.w11`                             |

### Packed Multiply Parts Accumulate

#### 32-bit

| Prototype                                                                          | Instruction                               |
|------------------------------------------------------------------------------------|-------------------------------------------|
| `int32_t __riscv_macc_h00_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | `macc.h00`(RV32), `pmacc.w.h00`(RV64)     |
| `int32_t __riscv_macc_h01_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | `macc.h01`(RV32), `pmacc.w.h01`(RV64)     |
| `int32_t __riscv_macc_h11_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | `macc.h11`(RV32), `pmacc.w.h11`(RV64)     |
| `uint32_t __riscv_maccu_h00_u32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`     | `maccu.h00`(RV32), `pmaccu.w.h00`(RV64)   |
| `uint32_t __riscv_maccu_h01_u32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`     | `maccu.h01`(RV32), `pmaccu.w.h01`(RV64)   |
| `uint32_t __riscv_maccu_h11_u32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`     | `maccu.h11`(RV32), `pmaccu.w.h11`(RV64)   |
| `int32_t __riscv_maccsu_h00_i32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`       | `maccsu.h00`(RV32), `pmaccsu.w.h00`(RV64) |
| `int32_t __riscv_maccsu_h11_i32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`       | `maccsu.h11`(RV32), `pmaccsu.w.h11`(RV64) |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                                          | Instruction                               |
|------------------------------------------------------------------------------------|-------------------------------------------|
| `int32x2_t __riscv_pmacc_h00_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`    | `pmacc.w.h00`                             |
| `int32x2_t __riscv_pmacc_h01_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`    | `pmacc.w.h01`                             |
| `int32x2_t __riscv_pmacc_h11_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`    | `pmacc.w.h11`                             |
| `uint32x2_t __riscv_pmaccu_h00_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`  | `pmaccu.w.h00`                            |
| `uint32x2_t __riscv_pmaccu_h01_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`  | `pmaccu.w.h01`                            |
| `uint32x2_t __riscv_pmaccu_h11_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`  | `pmaccu.w.h11`                            |
| `int32x2_t __riscv_pmaccsu_h00_i32x2(int32x2_t rd, int16x4_t rs1, uint8x8_t rs2);` | `pmaccsu.w.h00`                           |
| `int32x2_t __riscv_pmaccsu_h11_i32x2(int32x2_t rd, int16x4_t rs1, uint8x8_t rs2);` | `pmaccsu.w.h11`                           |
| `int64_t __riscv_macc_w00_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `macc.w00`                                |
| `int64_t __riscv_macc_w01_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `macc.w01`                                |
| `int64_t __riscv_macc_w11_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `macc.w11`                                |
| `uint64_t __riscv_maccu_w00_u64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`     | `maccu.w00`                               |
| `uint64_t __riscv_maccu_w01_u64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`     | `maccu.w01`                               |
| `uint64_t __riscv_maccu_w11_u64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`     | `maccu.w11`                               |
| `int64_t __riscv_maccsu_w00_i64(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`       | `maccsu.w00`                              |
| `int64_t __riscv_maccsu_w11_i64(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`       | `maccsu.w11`                              |


### Packed "Q-format" Multiply Parts Accumulate

#### 32-bit

| Prototype                                                                          | Instruction                               |
|------------------------------------------------------------------------------------|-------------------------------------------|
| `int32_t __riscv_mqacc_h00_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`         | `mqacc.h00`(RV32), `pmqacc.w.h00`(RV64)   |
| `int32_t __riscv_mqacc_h01_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`         | `mqacc.h01`(RV32), `pmqacc.w.h01`(RV64)   |
| `int32_t __riscv_mqacc_h11_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`         | `mqacc.h11`(RV32), `pmqacc.w.h11`(RV64)   |
| `int32_t __riscv_mqracc_h00_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `mqracc.h00`(RV32), `pmqracc.w.h00`(RV64) |
| `int32_t __riscv_mqracc_h01_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `mqracc.h01`(RV32), `pmqracc.w.h01`(RV64) |
| `int32_t __riscv_mqracc_h11_i32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `mqracc.h11`(RV32), `pmqracc.w.h11`(RV64) |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                                          | Instruction                               |
|------------------------------------------------------------------------------------|-------------------------------------------|
| `int32x2_t __riscv_pmqacc_h00_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`  | `pmqacc.w.h00`                            |
| `int32x2_t __riscv_pmqacc_h01_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`  | `pmqacc.w.h01`                            |
| `int32x2_t __riscv_pmqacc_h11_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`  | `pmqacc.w.h11`                            |
| `int32x2_t __riscv_pmqracc_h00_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);` | `pmqracc.w.h00`                           |
| `int32x2_t __riscv_pmqracc_h01_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);` | `pmqracc.w.h01`                           |
| `int32x2_t __riscv_pmqracc_h11_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);` | `pmqracc.w.h11`                           |
| `int64_t __riscv_mqacc_h00_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`         | `mqacc.w00`                               |
| `int64_t __riscv_mqacc_h01_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`         | `mqacc.w01`                               |
| `int64_t __riscv_mqacc_h11_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`         | `mqacc.w11`                               |
| `int64_t __riscv_mqracc_h00_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `mqracc.w00`                              |
| `int64_t __riscv_mqracc_h01_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `mqracc.w01`                              |
| `int64_t __riscv_mqracc_h11_i64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `mqracc.w11`                              |

### Packed Multiply High Parts

#### 32-bit

| Prototype                                                            | Instruction                             |
|----------------------------------------------------------------------|-----------------------------------------|
| `int16x2_t __riscv_pmulh_b0_i16x2(int16x2_t rs1, int8x4_t rs2);`     | `pmulh.h.b0`                            |
| `int16x2_t __riscv_pmulh_b1_i16x2(int16x2_t rs1, int8x4_t rs2);`     | `pmulh.h.b1`                            |
| `int16x2_t __riscv_pmulhsu_b0_i16x2(int16x2_t rs1, uint8x4_t rs2);`  | `pmulhsu.h.b0`                          |
| `int16x2_t __riscv_pmulhsu_b1_i16x2(int16x2_t rs1, uint8x4_t rs2);`  | `pmulhsu.h.b1`                          |
| `int32_t __riscv_mulh_h0_i32(int32_t rs1, int16x2_t rs2);`           | `mulh.h0`(RV32), `pmulh.w.h0`(RV64)     |
| `int32_t __riscv_mulh_h1_i32(int32_t rs1, int16x2_t rs2);`           | `mulh.h1`(RV32), `pmulh.w.h1`(RV64)     |
| `int32_t __riscv_mulhsu_h0_i32(int32_t rs1, uint16x2_t rs2);`        | `mulhsu.h0`(RV32), `pmulhsu.w.h0`(RV64) |
| `int32_t __riscv_mulhsu_h1_i32(int32_t rs1, uint16x2_t rs2);`        | `mulhsu.h1`(RV32), `pmulhsu.w.h1`(RV64) |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                            | Instruction                             |
|----------------------------------------------------------------------|-----------------------------------------|
| `int16x4_t __riscv_pmulh_b0_i16x4(int16x4_t rs1, int8x8_t rs2);`     | `pmulh.h.b0`                            |
| `int16x4_t __riscv_pmulh_b1_i16x4(int16x4_t rs1, int8x8_t rs2);`     | `pmulh.h.b1`                            |
| `int16x4_t __riscv_pmulhsu_b0_i16x4(int16x4_t rs1, uint8x8_t rs2);`  | `pmulhsu.h.b0`                          |
| `int16x4_t __riscv_pmulhsu_b1_i16x4(int16x4_t rs1, uint8x8_t rs2);`  | `pmulhsu.h.b1`                          |
| `int32x2_t __riscv_pmulh_b0_i32x2(int32x2_t rs1, int16x4_t rs2);`    | `pmulh.w.h0`                            |
| `int32x2_t __riscv_pmulh_b1_i32x2(int32x2_t rs1, int16x4_t rs2);`    | `pmulh.w.h1`                            |
| `int32x2_t __riscv_pmulhsu_b0_i32x2(int32x2_t rs1, uint16x4_t rs2);` | `pmulhsu.w.h0`                          |
| `int32x2_t __riscv_pmulhsu_b1_i32x2(int32x2_t rs1, uint16x4_t rs2);` | `pmulhsu.w.h1`                          |

### Packed Multiply High Parts Accumulate

#### 32-bit

| Prototype                                                                           | Instruction                               |
|-------------------------------------------------------------------------------------|-------------------------------------------|
| `int16x2_t __riscv_pmhacc_b0_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`     | `pmhacc.h.b0`                             |
| `int16x2_t __riscv_pmhacc_b1_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`     | `pmhacc.h.b1`                             |
| `int16x2_t __riscv_pmhaccsu_b0_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`  | `pmhaccsu.h.b0`                           |
| `int16x2_t __riscv_pmhaccsu_b1_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`  | `pmhaccsu.h.b1`                           |
| `int32_t __riscv_mhacc_h0_i32(int32_t rd, int32_t rs1, int16x2_t rs2);`             | `mhacc.h0`(RV32), `pmhacc.w.h0`(RV64)     |
| `int32_t __riscv_mhacc_h1_i32(int32_t rd, int32_t rs1, int16x2_t rs2);`             | `mhacc.h1`(RV32), `pmhacc.w.h1`(RV64)     |
| `int32_t __riscv_mhaccsu_h0_i32(int32_t rd, int32_t rs1, uint16x2_t rs2);`          | `mhaccsu.h0`(RV32), `pmhaccsu.w.h0`(RV64) |
| `int32_t __riscv_mhaccsu_h1_i32(int32_t rd, int32_t rs1, uint16x2_t rs2);`          | `mhaccsu.h1`(RV32), `pmhaccsu.w.h1`(RV64) |

#### 64-bit (RV64 Only)

* TODO: Could be emulated on RV32 with 2 instructions.

| Prototype                                                                           | Instruction                               |
|-------------------------------------------------------------------------------------|-------------------------------------------|
| `int16x4_t __riscv_pmhacc_b0_i16x4(int16x4_t rd, int16x4_t rs1, int8x8_t rs2);`     | `pmhacc.h.b0`                             |
| `int16x4_t __riscv_pmhacc_b1_i16x4(int16x4_t rd, int16x4_t rs1, int8x8_t rs2);`     | `pmhacc.h.b1`                             |
| `int16x4_t __riscv_pmhaccsu_b0_i16x4(int16x4_t rd, int16x4_t rs1, uint8x8_t rs2);`  | `pmhaccsu.h.b0`                           |
| `int16x4_t __riscv_pmhaccsu_b1_i16x4(int16x4_t rd, int16x4_t rs1, uint8x8_t rs2);`  | `pmhaccsu.h.b1`                           |
| `int32x2_t __riscv_pmhacc_h0_i32x2(int32x2_t rd, int32x2_t rs1, int16x4_t rs2);`    | `pmhacc.w.h0`                             |
| `int32x2_t __riscv_pmhacc_h1_i32x2(int32x2_t rd, int32x2_t rs1, int16x4_t rs2);`    | `pmhacc.w.h1`                             |
| `int32x2_t __riscv_pmhaccsu_h0_i32x2(int32x2_t rd, int32x2_t rs1, uint16x4_t rs2);` | `pmhaccsu.w.h0`                           |
| `int32x2_t __riscv_pmhaccsu_h1_i32x2(int32x2_t rd, int32x2_t rs1, uint16x4_t rs2);` | `pmhaccsu.w.h1`                           |

### Packed Logical Operations

These are convenience functions to allow bitwise and/or/xor/not on packed vectors using scalar instructions.

#### 32-bit

| Prototype                                                        | Instruction |
|------------------------------------------------------------------|-------------|
| `int8x4_t __riscv_pand_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `and`       |
| `uint8x4_t __riscv_pand_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `and`       |
| `int16x2_t __riscv_pand_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `and`       |
| `uint16x2_t __riscv_pand_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `and`       |
| `int8x4_t __riscv_por_i8x4(int8x4_t rs1, int8x4_t rs2);`         | `or`        |
| `uint8x4_t __riscv_por_u8x4(uint8x4_t rs1, uint8x4_t rs2);`      | `or`        |
| `int16x2_t __riscv_por_i16x2(int16x2_t rs1, int16x2_t rs2);`     | `or`        |
| `uint16x2_t __riscv_por_u16x2(uint16x2_t rs1, uint16x2_t rs2);`  | `or`        |
| `int8x4_t __riscv_pxor_i8x4(int8x4_t rs1, int8x4_t rs2);`        | `xor`       |
| `uint8x4_t __riscv_pxor_u8x4(uint8x4_t rs1, uint8x4_t rs2);`     | `xor`       |
| `int16x2_t __riscv_pxor_i16x2(int16x2_t rs1, int16x2_t rs2);`    | `xor`       |
| `uint16x2_t __riscv_pxor_u16x2(uint16x2_t rs1, uint16x2_t rs2);` | `xor`       |
| `int8x4_t __riscv_pnot_i8x4(int8x4_t rs1);`                      | `not`       |
| `uint8x4_t __riscv_pnot_u8x4(uint8x4_t rs1);`                    | `not`       |
| `int16x2_t __riscv_pnot_i16x2(int16x2_t rs1);`                   | `not`       |
| `uint16x2_t __riscv_pnot_u16x2(uint16x2_t rs1);`                 | `not`       |

#### 64-bit

* NOTE: This requires 2 instructions for RV32.

| Prototype                                                        | Instruction |
|------------------------------------------------------------------|-------------|
| `int8x8_t __riscv_pand_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `and`       |
| `uint8x8_t __riscv_pand_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `and`       |
| `int16x4_t __riscv_pand_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `and`       |
| `uint16x4_t __riscv_pand_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `and`       |
| `int32x2_t __riscv_pand_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `and`       |
| `uint32x2_t __riscv_pand_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `and`       |
| `int8x8_t __riscv_por_i8x8(int8x8_t rs1, int8x8_t rs2);`         | `or`        |
| `uint8x8_t __riscv_por_u8x8(uint8x8_t rs1, uint8x8_t rs2);`      | `or`        |
| `int16x4_t __riscv_por_i16x4(int16x4_t rs1, int16x4_t rs2);`     | `or`        |
| `uint16x4_t __riscv_por_u16x4(uint16x4_t rs1, uint16x4_t rs2);`  | `or`        |
| `int32x2_t __riscv_por_i32x2(int32x2_t rs1, int32x2_t rs2);`     | `or`        |
| `uint32x2_t __riscv_por_u32x2(uint32x2_t rs1, uint32x2_t rs2);`  | `or`        |
| `int8x8_t __riscv_pxor_i8x8(int8x8_t rs1, int8x8_t rs2);`        | `xor`       |
| `uint8x8_t __riscv_pxor_u8x8(uint8x8_t rs1, uint8x8_t rs2);`     | `xor`       |
| `int16x4_t __riscv_pxor_i16x4(int16x4_t rs1, int16x4_t rs2);`    | `xor`       |
| `uint16x4_t __riscv_pxor_u16x4(uint16x4_t rs1, uint16x4_t rs2);` | `xor`       |
| `int32x2_t __riscv_pxor_i32x2(int32x2_t rs1, int32x2_t rs2);`    | `xor`       |
| `uint32x2_t __riscv_pxor_u32x2(uint32x2_t rs1, uint32x2_t rs2);` | `xor`       |
| `int8x8_t __riscv_pnot_i8x8(int8x8_t rs1);`                      | `not`       |
| `uint8x8_t __riscv_pnot_u8x8(uint8x8_t rs1);`                    | `not`       |
| `int16x4_t __riscv_pnot_i16x4(int16x4_t rs1);`                   | `not`       |
| `uint16x4_t __riscv_pnot_u16x4(uint16x4_t rs1);`                 | `not`       |
| `int32x2_t __riscv_pnot_i32x2(int32x2_t rs1);`                   | `not`       |
| `uint32x2_t __riscv_pnot_u32x2(uint32x2_t rs1);`                 | `not`       |

### Packed Widening Addition and Subtraction

### 32-bit (RV32 Only)

| Prototype                                                          | Instruction     |
|--------------------------------------------------------------------|-----------------|
| `int16x4_t __riscv_pwadd_i16x4(int8x4_t rs1, int8x4_t rs2);`       | `pwadd.b`       |
| `int32x2_t __riscv_pwadd_i32x2(int16x2_t rs1, int16x2_t rs2);`     | `pwadd.h`       |
| `uint16x4_t __riscv_pwaddu_u16x4(uint8x4_t rs1, uint8x4_t rs2);`   | `pwaddu.b`      |
| `uint32x2_t __riscv_pwaddu_u32x2(uint16x2_t rs1, uint16x2_t rs2);` | `pwaddu.h`      |
| `int16x4_t __riscv_pwsub_i16x4(int8x4_t rs1, int8x4_t rs2);`       | `pwsub.b`       |
| `int32x2_t __riscv_pwsub_i32x2(int16x2_t rs1, int16x2_t rs2);`     | `pwsub.h`       |
| `uint16x4_t __riscv_pwsubu_u16x4(uint8x4_t rs1, uint8x4_t rs2);`   | `pwsubu.b`      |
| `uint32x2_t __riscv_pwsubu_u32x2(uint16x2_t rs1, uint16x2_t rs2);` | `pwsubu.h`      |

### Packed Widening Addition and Subtraction Accumulate

### 32-bit (RV32 Only)

| Prototype                                                                          | Instruction     |
|------------------------------------------------------------------------------------|-----------------|
| `int16x4_t __riscv_pwadda_i16x4(int16x4_t rd, int8x4_t rs1, int8x4_t rs2);`        | `pwadda.b`      |
| `int32x2_t __riscv_pwadda_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pwadda.h`      |
| `uint16x4_t __riscv_pwaddau_u16x4(uint16x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`   | `pwaddau.b`     |
| `uint32x2_t __riscv_pwaddau_u32x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pwaddau.h`     |
| `int16x4_t __riscv_pwsuba_i16x4(int16x4_t rd, int8x4_t rs1, int8x4_t rs2);`        | `pwsuba.b`      |
| `int32x2_t __riscv_pwsuba_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pwsuba.h`      |
| `uint16x4_t __riscv_pwsubau_u16x4(uint16x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`   | `pwsubau.b`     |
| `uint32x2_t __riscv_pwsubau_u32x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pwsubau.h`     |

### Packed Widening Multiply

### 32-bit (RV32 Only)

| Prototype                                                          | Instruction |
|--------------------------------------------------------------------|-------------|
| `int16x4_t __riscv_pwmul_i16x4(int8x4_t rs1, int8x4_t rs2);`       | `pwmul.b`   |
| `int32x2_t __riscv_pwmul_i32x2(int16x2_t rs1, int16x2_t rs2);`     | `pwmul.h`   |
| `uint16x4_t __riscv_pwmulu_u16x4(uint8x4_t rs1, uint8x4_t rs2);`   | `pwmulu.b`  |
| `uint32x2_t __riscv_pwmulu_u32x2(uint16x2_t rs1, uint16x2_t rs2);` | `pwmulu.h`  |
| `int16x4_t __riscv_pwmulsu_u16x4(int8x4_t rs1, uint8x4_t rs2);`    | `pwmulsu.b` |
| `int32x2_t __riscv_pwmulsu_u32x2(int16x2_t rs1, uint16x2_t rs2);`  | `pwmulsu.h` |

### Packed Widening Multiply Accmulate

#### 32-bit (RV32 Only)

| Prototype                                                                          | Instruction  |
|------------------------------------------------------------------------------------|--------------|
| `int32x2_t __riscv_pwmacc_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pwmacc.h`   |
| `uint32x2_t __riscv_pwmaccu_u32x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pwmaccu.h`  |
| `int32x2_t __riscv_pwmaccsu_u32x2(int32x2_t rd, int16x2_t rs1, uint16x2_t rs2);`   | `pwmaccsu.h` |

### Packed "Q-format" Multiply with Widening Accumulate

#### 32-bit (RV32 Only)

| Prototype                                                                       | Instruction  |
|---------------------------------------------------------------------------------|--------------|
| `int32x2_t __riscv_pmqwacc_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`  | `pmqwacc.h`  |
| `int32x2_t __riscv_pmqrwacc_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);` | `pmqrwacc.h` |

### Packed Widening Shift

#### 32-bit (RV32 Only)

| Prototype                                                           | Instruction            |
|---------------------------------------------------------------------|------------------------|
| `uint16x4_t __riscv_pwsll_s_u16x4(uint8x4_t rs1, unsigned shamt);`  | `pwslli.b`, `pwsll.bs` |
| `uint32x2_t __riscv_pwsll_s_u32x2(uint16x2_t rs1, unsigned shamt);` | `pwslli.h`, `pwsll.hs` |
| `int16x4_t __riscv_pwsla_s_i16x4(int8x4_t rs1, unsigned shamt);`    | `pwslai.b`, `pwsla.bs` |
| `int32x2_t __riscv_pwsla_s_i32x2(int16x2_t rs1, unsigned shamt);`   | `pwslai.h`, `pwsla.hs` |

### Packed Narrowing Shift

#### 32-bit (RV32 Only)

| Prototype                                                           | Instruction              |
|---------------------------------------------------------------------|--------------------------|
| `uint8x4_t __riscv_pnsrl_s_u8x4(uint16x4_t rs1, unsigned shamt);`   | `pnsrli.b`, `pnsrl.bs`   |
| `uint16x2_t __riscv_pnsrl_s_u16x2(uint32x2_t rs1, unsigned shamt);` | `pnsrli.h`, `pnsrl.hs`   |
| `int8x4_t __riscv_pnsra_s_i8x4(int16x4_t rs1, unsigned shamt);`     | `pnsrai.b`, `pnsra.bs`   |
| `int16x2_t __riscv_pnsra_s_i16x2(int32x2_t rs1, unsigned shamt);`   | `pnsrai.h`, `pnsra.hs`   |
| `int8x4_t __riscv_pnsrar_s_i8x4(int16x4_t rs1, unsigned shamt);`    | `pnsrari.b`, `pnsrar.bs` |
| `int16x2_t __riscv_pnsrar_s_i16x2(int32x2_t rs1, unsigned shamt);`  | `pnsrari.h`, `pnsrar.hs` |

### Packed Narrowing Clip

#### 32-bit (RV32 Only)

| Prototype                                                              | Instruction                  |
|------------------------------------------------------------------------|------------------------------|
| `uint8x4_t __riscv_pnclipu_s_u8x4(uint16x4_t rs1, unsigned shamt);`    | `pnclipiu.b`, `pnclipu.bs`   |
| `uint16x2_t __riscv_pnclipu_s_u16x2(uint32x2_t rs1, unsigned shamt);`  | `pnclipiu.h`, `pnclipu.hs`   |
| `uint8x4_t __riscv_pnclipru_s_u8x4(uint16x4_t rs1, unsigned shamt);`   | `pnclipriu.b`, `pnclipru.bs` |
| `uint16x2_t __riscv_pnclipru_s_u16x2(uint32x2_t rs1, unsigned shamt);` | `pnclipriu.h`, `pnclipru.hs` |
| `int8x4_t __riscv_pnclip_s_i8x4(int16x4_t rs1, unsigned shamt);`       | `pnclipi.b`, `pnclipu.bs`    |
| `int16x2_t __riscv_pnclip_s_i16x2(int32x2_t rs1, unsigned shamt);`     | `pnclipi.h`, `pnclipu.hs`    |
| `int8x4_t __riscv_pnclipr_s_i8x4(int16x4_t rs1, unsigned shamt);`      | `pnclipri.b`, `pnclipr.bs`   |
| `int16x2_t __riscv_pnclipr_s_i16x2(int32x2_t rs1, unsigned shamt);`    | `pnclipri.h`, `pnclipr.hs`   |

### Packed Multiplication with Widening Horizontal Addition

#### 32-bit (RV32 Only)

| Prototype                                                                      | Instruction    |
|--------------------------------------------------------------------------------|----------------|
| `int64_t __riscv_pm2wadd_i64(int16x2_t rs1, int16x2_t rs2);`                   | `pm2wadd.h`    |
| `int64_t __riscv_pm2wadda_i64(int64_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pm2wadda.h`   |
| `int64_t __riscv_pm2wadd_x_i64(int16x2_t rs1, int16x2_t rs2);`                 | `pm2wadd.hx`   |
| `int64_t __riscv_pm2wadda_x_i64(int64_t rd, int16x2_t rs1, int16x2_t rs2);`    | `pm2wadda.hx`  |
| `uint64_t __riscv_pm2waddu_u64(uint16x2_t rs1, uint16x2_t rs2);`               | `pm2waddu.h`   |
| `uint64_t __riscv_pm2waddau_u64(uint64_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pm2waddau.h`  |
| `int64_t __riscv_pm2wsub_i64(int16x2_t rs1, int16x2_t rs2);`                   | `pm2wsub.h`    |
| `int64_t __riscv_pm2wsuba_i64(int64_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pm2wsuba.h`   |
| `int64_t __riscv_pm2wsub_x_i64(int16x2_t rs1, int16x2_t rs2);`                 | `pm2wsub.hx`   |
| `int64_t __riscv_pm2wsuba_x_i64(int64_t rd, int16x2_t rs1, int16x2_t rs2);`    | `pm2wsuba.hx`  |
| `int64_t __riscv_pm2waddsu_u64(int16x2_t rs1, uint16x2_t rs2);`                | `pm2waddsu.h`  |
| `int64_t __riscv_pm2waddasu_u64(int64_t rd, int16x2_t rs1, uint16x2_t rs2);`   | `pm2waddasu.h` |

## Packed Load and Store

Load and store intrinsics. These assume the pointer is aligned to the element
size. If target CPU does not support unaligned scalar accesses and the compiler
cannot prove the pointer is more aligned, this will be broken down into multiple
loads and stores.

Compiler hints like `__builtin_assume_aligned` can help.

* TODO: Do we need aligned load/store intrinsics?

#### 32-bit

| Prototype                                               | Instruction                         |
|---------------------------------------------------------|-------------------------------------|
| `int8x4_t __riscv_pload_i8x4(int8_t *p);`               | `lw` or multiple loads and packs    |
| `uint8x4_t __riscv_pload_u8x4(uint8_t *p);`             | `lw` or multiple loads and packs    |
| `int16x2_t __riscv_pload_i16x2(int16_t *p);`            | `lw` or multiple loads and packs    |
| `uint16x2_t __riscv_pload_u16x2(uint16_t *p);`          | `lw` or multiple loads and packs    |
| `void __riscv_pstore_i8x4(int8_t *p, int8x4_t v);`      | `sw` or multiple stores and shifts  |
| `void __riscv_pstore_u8x4(uint8_t *p, uint8x4_t v);`    | `sw` or multiple stores and shifts  |
| `void __riscv_pstore_i16x2(int16_t *p, int16x2_t v);`   | `sw` or multiple stores and shifts  |
| `void __riscv_pstore_u16x2(uint16_t *p, uint16x2_t v);` | `sw` or multiple stores and shifts  |

#### 64-bit

| Prototype                                               | Instruction                         |
|---------------------------------------------------------|-------------------------------------|
| `int8x8_t __riscv_pload_i8x8(int8_t *p);`               | `ld` or multiple loads and pack     |
| `uint8x8_t __riscv_pload_i8x8(uint8_t *p);`             | `ld` or multiple loads and pack     |
| `int16x4_t __riscv_pload_i16x4(int16_t *p);`            | `ld` or multiple loads and pack     |
| `uint16x4_t __riscv_pload_u16x4(uint16_t *p);`          | `ld` or multiple loads and pack     |
| `int32x2_t __riscv_pload_i32x2(int32_t *p);`            | `ld` or multiple loads and pack     |
| `uint32x2_t __riscv_pload_u32x2(uint32_t *p);`          | `ld` or multiple loads and pack     |
| `void __riscv_pstore_i8x8(int8_t *p, int8x8_t v);`      | `sd` or multiple stores and shifts  |
| `void __riscv_pstore_u8x8(uint8_t *p, uint8x8_t v);`    | `sd` or multiple stores and shifts  |
| `void __riscv_pstore_i16x4(int16_t *p, int16x4_t v);`   | `sd` or multiple stores and shifts  |
| `void __riscv_pstore_u16x4(uint16_t *p, uint16x4_t v);` | `sd` or multiple stores and shifts  |
| `void __riscv_pstore_i32x2(int32_t *p, int32x2_t v);`   | `sd` or multiple stores and shifts  |
| `void __riscv_pstore_u32x2(uint32_t *p, uint32x2_t v);` | `sd` or multiple stores and shifts  |

### Packed Element Insert and Extract

Intrinsics to extract or insert individual elements. These will turn into base
ISA shifts and and/or/xor. Index must be a constant.

#### 32-bit

| Prototype                                                                          | Instruction     |
|------------------------------------------------------------------------------------|-----------------|
| `int8_t __riscv_pget_i8x4_i8(int8x4_t v, const unsigned idx);`                     | `srli`+`sext.b` |
| `uint8_t __riscv_pget_u8x4_u8(uint8x4_t v, const unsigned idx);`                   | `srli`+`zext.b` |
| `int16_t __riscv_pget_i16x2_i16(int16x4_t v, const unsigned idx);`                 | `srli`+`sext.h` |
| `uint16_t __riscv_pget_u16x2_u16(uint16x4_t v, const unsigned idx);`               | `srli`+`zext.h` |
| `int8x4_t __riscv_pset_i8_i8x4(int8x4_t v, int8_t e, const unsigned idx);`         | Multiple        |
| `uint8x4_t __riscv_pset_u8_u8x4(uint8x4_t v, uint8_t e, const unsigned idx);`      | Multiple        |
| `int16x2_t __riscv_pset_i16_i16x2(int16x2_t v, int16_t e, const unsigned idx);`    | Multiple        |
| `uint16x2_t __riscv_pset_u16_u16x2(uint16x2_t v, uint16_t e, const unsigned idx);` | Multiple        |

#### 64-bit

| Prototype                                                                          | Instruction                       |
|------------------------------------------------------------------------------------|-----------------------------------|
| `int8_t __riscv_pget_i8x8_i8(int8x8_t v, const unsigned idx);`                     | `srli`+`sextb`                    |
| `uint8_t __riscv_pget_u8x8_u8(uint8x8_t v, const unsigned idx);`                   | `srli`+`zext.b`                   |
| `int16_t __riscv_pget_i16x4_i16(int16x4_t v, const unsigned idx);`                 | `srli`+`sext.h`                   |
| `uint16_t __riscv_pget_u16x4_u16(uint16x4_t v, const unsigned idx);`               | `srli`+`zext.h`                   |
| `int32_t __riscv_pget_i32x2_i32(int32x2_t v, const unsigned idx);`                 | `srai`/`sext.w`(RV64), Free(RV32) |
| `uint32_t __riscv_pget_u32x2_u32(uint32x2_t v, const unsigned idx);`               | `srli`/`zext.w`(RV64), Free(RV32) |
| `int8x8_t __riscv_pset_i8_i8x8(int8x8_t v, int8_t e, const unsigned idx);`         | Multiple                          |
| `uint8x8_t __riscv_pset_u8_u8x8(uint8x8_t v, uint8_t e, const unsigned idx);`      | Multiple                          |
| `int16x4_t __riscv_pset_i16_i16x4(int16x4_t v, int16_t e, const unsigned idx);`    | Multiple                          |
| `uint16x4_t __riscv_pset_u16_u16x4(uint16x4_t v, uint16_t e, const unsigned idx);` | Multiple                          |
| `int32x2_t __riscv_pset_i32_i32x2(int32x2_t v, int32_t e, const unsigned idx);`    | Multiple(RV64), `mv`(RV32)        |
| `uint32x2_t __riscv_pset_u32_u32x2(uint32x2_t v, uint32_t e, const unsigned idx);` | Multiple(RV64), `mv`(RV32)        |

### Packed Element Join

Intrinsics to join multiple scalars into a packed vector.

#### 32-bit

| Prototype                                                                      | Instruction                          |
|--------------------------------------------------------------------------------|--------------------------------------|
| `int8x4_t __riscv_join4_i8x4(int8_t e0, int8_t e1, int8_t e2, int8_t e3)`      | Multiple pack or ppair instructions. |
| `uint8x4_t __riscv_join4_u8x4(uint8_t e0, uint8_t e1, uint8_t e2, uint8_t e3)` | Multiple pack or ppair instructions. |
| `int16x2_t __riscv_join2_i16x2(int16_t e0, int16_t e1)`                        | `pack`(RV32), `ppaire.h`(RV64)       |
| `uint16x2_t __riscv_join2_u16x2(uint16_t e0, uint16_t e1)`                     | `pack`(RV32), `ppaire.h`(RV64)       |

#### 64-bit

| Prototype                                                                            | Instruction                         |
|--------------------------------------------------------------------------------------|-------------------------------------|
| `int16x4_t __riscv_join4_i16x4(int16_t e0, int16_t e1, int16_t e2, int16_t e3)`      | Multiple pack or ppair instructions |
| `uint16x4_t __riscv_join4_u16x4(uint16_t e0, uint16_t e1, uint16_t e2, uint16_t e3)` | Multiple pack or ppair instructions |
| `int32x2_t __riscv_join2_i32x2(int32_t e0, int32_t e1)`                              | `mv`(RV32), `ppaire.h`(RV64)        |
| `uint32x2_t __riscv_join2_u32x2(uint32_t e0, uint32_t e1)`                           | `mv`(RV32), `ppaire.h`(RV64)        |

### Packed Subvector Insert and Extract

Intrinsics to insert or extract 32-bit packed subvectors from 64-bit packed vectors. The index
specifies which subvector to extract. 0 - low, 1 - high.

| Prototype                                                                              | Instruction   |
|----------------------------------------------------------------------------------------|---------------|
| `int8x4_t __riscv_pget_i8x8_i8x4(int8x8_t v, const unsigned idx);`                     | `srai`/`sext.w`(RV64), Free(RV32)    |
| `uint8x4_t __riscv_pget_u8x8_u8x4(uint8x8_t v, const unsigned idx);`                   | `srli`/`zext.w`(RV64), Free(RV32)    |
| `int16x2_t __riscv_pget_i16x4_i16x2(int16x4_t v, const unsigned idx);`                 | `srai`/`sext.w`(RV64), Free(RV32)    |
| `uint16x2_t __riscv_pget_u16x4_u16x2(uint16x4_t , const unsigned idx);`                | `srli`/`zext.w`(RV64), Free(RV32)    |
| `int8x8_t __riscv_pset_i8x4_i8x8(int8x8_t v, int8x4_t s, const unsigned idx);`         | Multiple(RV64), `mv`(RV32)           |
| `uint8x8_t __riscv_pset_u8x4_u8x8(uint8x8_t v, uint8x4_t s, const unsigned idx);`      | Multiple(RV64), `mv`(RV32)           |
| `int16x4_t __riscv_pset_i16x2_i16x4(int16x4_t v, int16x2_t s, const unsigned idx);`    | `pack`/`ppaireo.w`(RV64), `mv`(RV32) |
| `uint16x4_t __riscv_pset_u16x2_u16x4(uint16x4_t v, uint16x2_t s, const unsigned idx);` | `pack`/`ppaireo.w`(RV64), `mv`(RV32) |


### Packed Subvector Join

Intrinsics to join multiple 32-bit subvectors into a 64-bit vector.

| Prototype                                                        | Instruction                                  |
|------------------------------------------------------------------|----------------------------------------------|
| `int8x8_t __riscv_pjoin2_i8x8(int8x4_t lo, int8x4_t hi);`        | `pack`/`ppaireo.w`(RV64), up to 2 `mv`(RV32) |
| `uint8x8_t __riscv_pjoin2_i8x8(uint8x4_t lo, uint8x4_t hi);`     | `pack`/`ppaireo.w`(RV64), up to 2 `mv`(RV32) |
| `int16x4_t __riscv_pjoin2_i16x4(int16x2_t lo, int16x2_t hi);`    | `pack`/`ppaireo.w`(RV64), up to 2 `mv`(RV32) |
| `uint16x4_t __riscv_pjoin2_i16x4(uint16x2_t lo, uint16x2_t hi);` | `pack`/`ppaireo.w`(RV64), up to 2 `mv`(RV32) |

## Reinterpret casts

### Packed <-> Scalar

#### 32-bit

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint32_t __riscv_preinterpret_u8x4_u32(uint8x4_t x);`           |
| `uint32_t __riscv_preinterpret_u16x2_u32(uint16x2_t x);`         |
| `uint32_t __riscv_preinterpret_i8x4_u32(int8x4_t x);`            |
| `uint32_t __riscv_preinterpret_i16x2_u32(int16x2_t x);`          |
| `int32_t __riscv_preinterpret_u8x4_i32(uint8x4_t x);`            |
| `int32_t __riscv_preinterpret_u16x2_i32(uint16x2_t x);`          |
| `int32_t __riscv_preinterpret_i8x4_i32(int8x4_t x);`             |
| `int32_t __riscv_preinterpret_i16x2_i32(int16x2_t x);`           |
| `uint8x4_t __riscv_preinterpret_u32_u8x4(uint32_t x);`           |
| `uint16x2_t __riscv_preinterpret_u32_u16x2(uint32_t x);`         |
| `int8x4_t __riscv_preinterpret_u32_i8x4(uint32_t x);`            |
| `int16x2_t __riscv_preinterpret_u32_i16x2(uint32_t x);`          |
| `uint8x4_t __riscv_preinterpret_i32_u8x4(int32_t x);`            |
| `uint16x2_t __riscv_preinterpret_i32_u16x2(int32_t x);`          |
| `int8x4_t __riscv_preinterpret_i32_i8x4(int32_t x);`             |
| `int16x2_t __riscv_preinterpret_i32_i16x2(int32_t x);`           |

#### 64-bit

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint64_t __riscv_preinterpret_u8x8_u64(uint8x8_t x);`           |
| `uint64_t __riscv_preinterpret_u16x4_u64(uint16x4_t x);`         |
| `uint64_t __riscv_preinterpret_u32x2_u64(uint32x2_t x);`         |
| `uint64_t __riscv_preinterpret_i8x8_u64(int8x8_t x);`            |
| `uint64_t __riscv_preinterpret_i16x4_u64(int16x4_t x);`          |
| `uint64_t __riscv_preinterpret_i32x2_u64(int32x2_t x);`          |
| `int64_t __riscv_preinterpret_u8x8_i64(uint8x8_t x);`            |
| `int64_t __riscv_preinterpret_u16x4_i64(uint16x4_t x);`          |
| `int64_t __riscv_preinterpret_u32x2_i64(uint32x2_t x);`          |
| `int64_t __riscv_preinterpret_i8x8_i64(int8x8_t x);`             |
| `int64_t __riscv_preinterpret_i16x4_i64(int16x4_t x);`           |
| `int64_t __riscv_preinterpret_i32x2_i64(int32x2_t x);`           |
| `uint8x8_t __riscv_preinterpret_u64_u8x8(uint64_t x);`           |
| `uint16x4_t __riscv_preinterpret_u64_u16x4(uint64_t x);`         |
| `uint32x2_t __riscv_preinterpret_u64_u64x2(uint64_t x);`         |
| `int8x8_t __riscv_preinterpret_u64_i8x8(uint64_t x);`            |
| `int16x4_t __riscv_preinterpret_u64_i16x4(uint64_t x);`          |
| `int32x2_t __riscv_preinterpret_u64_i32x2(uint64_t x);`          |
| `uint8x8_t __riscv_preinterpret_i64_u8x8(int64_t x);`            |
| `uint16x4_t __riscv_preinterpret_i64_u16x4(int64_t x);`          |
| `uint32x2_t __riscv_preinterpret_i64_u32x2(int64_t x);`          |
| `int8x8_t __riscv_preinterpret_i64_i8x8(int64_t x);`             |
| `int16x4_t __riscv_preinterpret_i64_i16x4(int64_t x);`           |
| `int32x2_t __riscv_preinterpret_i64_i32x2(int64_t x);`           |

### Packed <-> Packed

#### 32-bit

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint8x4_t __riscv_preinterpet_i8x4_u8x4(int8x4_t x);`           |
| `uint8x4_t __riscv_preinterpet_u16x2_u8x4(uint16x2_t x);`        |
| `uint8x4_t __riscv_preinterpet_i16x2_u8x4(int16x2_t x);`         |
| `int8x4_t __riscv_preinterpet_u8x4_i8x4(uint8x4_t x);`           |
| `int8x4_t __riscv_preinterpet_u16x2_i8x4(uint16x2_t x);`         |
| `int8x4_t __riscv_preinterpet_i16x2_i8x4(int16x2_t x);`          |
| `uint16x2_t __riscv_preinterpet_u8x4_u16x2(uint8x4_t x);`        |
| `uint16x2_t __riscv_preinterpet_i8x4_u16x2(int8x4_t x);`         |
| `uint16x2_t __riscv_preinterpet_i16x2_u16x2(int16x2_t x);`       |
| `int16x2_t __riscv_preinterpet_u8x4_i16x2(uint8x4_t x);`         |
| `int16x2_t __riscv_preinterpet_i8x4_i16x2(int8x4_t x);`          |
| `int16x2_t __riscv_preinterpet_u16x2_i16x2(uint16x2_t x);`       |

#### 64-bit

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint8x8_t __riscv_preinterpet_i8x8_u8x8(int8x8_t x);`           |
| `uint8x8_t __riscv_preinterpet_u16x4_u8x8(uint16x4_t x);`        |
| `uint8x8_t __riscv_preinterpet_i16x4_u8x8(int16x4_t x);`         |
| `uint8x8_t __riscv_preinterpet_u32x2_u8x8(uint32x2_t x);`        |
| `uint8x8_t __riscv_preinterpet_i32x2_u8x8(int32x2_t x);`         |
| `int8x8_t __riscv_preinterpet_u8x8_i8x8(uint8x8_t x);`           |
| `int8x8_t __riscv_preinterpet_u16x4_i8x8(uint16x4_t x);`         |
| `int8x8_t __riscv_preinterpet_i16x4_i8x8(int16x4_t x);`          |
| `int8x8_t __riscv_preinterpet_u32x2_i8x8(uint32x2_t x);`         |
| `int8x8_t __riscv_preinterpet_i32x2_i8x8(int32x2_t x);`          |
| `uint16x4_t __riscv_preinterpet_u8x8_u16x4(uint8x8_t x);`        |
| `uint16x4_t __riscv_preinterpet_i8x8_u16x4(int8x8_t x);`         |
| `uint16x4_t __riscv_preinterpet_i16x4_u16x4(int16x4_t x);`       |
| `uint16x4_t __riscv_preinterpet_u32x2_u16x4(uint32x2_t x);`      |
| `uint16x4_t __riscv_preinterpet_i32x2_u16x4(int32x2_t x);`       |
| `int16x4_t __riscv_preinterpet_u8x8_i16x4(uint8x8_t x);`         |
| `int16x4_t __riscv_preinterpet_i8x8_i16x4(int8x8_t x);`          |
| `int16x4_t __riscv_preinterpet_u16x4_i16x4(uint16x4_t x);`       |
| `int16x4_t __riscv_preinterpet_u32x2_i16x4(uint32x2_t x);`       |
| `int16x4_t __riscv_preinterpet_i32x2_i16x4(int32x2_t x);`        |
| `uint32x2_t __riscv_preinterpet_u8x8_u32x2(uint8x8_t x);`        |
| `uint32x2_t __riscv_preinterpet_i8x8_u32x2(int8x8_t x);`         |
| `uint32x2_t __riscv_preinterpet_u16x4_u32x2(uint16x4_t x);`      |
| `uint32x2_t __riscv_preinterpet_i16x4_u32x2(int16x4_t x);`       |
| `uint32x2_t __riscv_preinterpet_i32x2_u32x2(int32x2_t x);`       |
| `int32x2_t __riscv_preinterpet_u8x8_i32x2(uint8x8_t x);`         |
| `int32x2_t __riscv_preinterpet_i8x8_i32x2(int8x8_t x);`          |
| `int32x2_t __riscv_preinterpet_u16x4_i32x2(uint16x4_t x);`       |
| `int32x2_t __riscv_preinterpet_i16x4_i32x2(int16x4_t x);`        |
| `int32x2_t __riscv_preinterpet_u32x2_i32x2(uint32x2_t x);`       |

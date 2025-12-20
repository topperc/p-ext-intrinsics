# RISC-V P Extension Intrinsics

This is a draft specification of the RISC-V P extension intrinsics. Based on the ISA specification [ISA specification](https://www.jhauser.us/RISCV/ext-P/).

## Introduction

The RISC-V P Extension C intrinsics provide users interface in the C language level to directly leverage the RISC-V "P" extension.

## Scalar Intrinsics

### Scalar Intrinsics Common to RV32 and RV64

| Prototype                                                                | Instruction                           | Notes                                              |
|--------------------------------------------------------------------------|---------------------------------------|----------------------------------------------------|
| `uint32_t __riscv_abs_32(int32_t rs1);`                                  | `abs[w]`                              |                                                    |
| `unsigned __riscv_cls_32(int32_t rs1);`                                  | `cls[w]`                              |                                                    |
| `uint32_t __riscv_rev_32(uint32_t rs1);`                                 | `rev`                                 | Emulated with rev+srai on RV64                     |
| `int32_t __riscv_sslai_32(int32_t rs1, const unsigned shamt);`           | `sslai`(RV32), `psslai.w`(RV64)       |                                                    |
| `int32_t __riscv_ssha_32(int32_t rs1, int rs2);`                         | `ssha`(RV32), `pssha.ws`(RV64)        |                                                    |
| `int32_t __riscv_sshar_32(int32_t rs1, int rs2);`                        | `sshar`(RV32), `psshar.ws`(RV64)      |                                                    |
| `int32_t __riscv_sadd_32(int32_t rs1, int32_t rs2);`                     | `sadd`(RV32), `psadd.w`(RV64)         |                                                    |
| `int32_t __riscv_aadd_32(int32_t rs1, int32_t rs2);`                     | `aadd`(RV32), `paadd.w`(RV64)         |                                                    |
| `uint32_t __riscv_saddu_32(uint32_t rs1, uint32_t rs2);`                 | `saddu`(RV32), `psaddu.w`(RV64)       |                                                    |
| `uint32_t __riscv_aaddu_32(uint32_t rs1, uint32_t rs2);`                 | `aaddu`(RV32), `paaddu.w`(RV64)       |                                                    |
| `int32_t __riscv_ssub_32(int32_t rs1, int32_t rs2);`                     | `ssub`(RV32), `pssub.w`(RV64)         |                                                    |
| `int32_t __riscv_asub_32(int32_t rs1, int32_t rs2);`                     | `asub`(RV32), `pasub.w`(RV64)         |                                                    |
| `uint32_t __riscv_ssubu_32(uint32_t rs1, uint32_t rs2);`                 | `ssubu`(RV32), `pssubu.w`(RV64)       |                                                    |
| `uint32_t __riscv_asubu_32(uint32_t rs1, uint32_t rs2);`                 | `asubu`(RV32), `pasubu.w`(RV64)       |                                                    |
| `uint32_t __riscv_usati_32(int32_t rs1, const unsigned shamt);`          | `usati`(RV32), `pusati.w`(RV64)       |                                                    |
| `int32_t __riscv_srari_32(int32_t rs1, const unsigned shamt);`           | `srari`(RV32), `psrari.w`(RV64)       |                                                    |
| `int32_t __riscv_sati_32(int32_t rs1, const unsigned shamt);`            | `sati`(RV32), `psati.w`(RV64)         |                                                    |
| `int32_t __riscv_ssh1sadd_32(int32_t rs1, const unsigned shamt);`        | `ssh1sadd`(RV32), `pssh1sadd.w`(RV64) |                                                    |
| `int32_t __riscv_mulhr_32(int32_t rs1, int32_t rs2);`                    | `mulhr`(RV32), `pmulhr.w`(RV64)       |                                                    |
| `int32_t __riscv_mhracc_32(int32_t rd, int32_t rs1, int32_t rs2);`       | `mhracc`(RV32), `pmhracc.w`(RV64)     |                                                    |
| `uint32_t __riscv_mulhru_32(uint32_t rs1, uint32_t rs2);`                | `mulhru`(RV32), `pmulhru.w`(RV64)     |                                                    |
| `uint32_t __riscv_mhraccu_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`  | `mhraccu`(RV32), `pmhraccu.w`(RV64)   |                                                    |
| `int32_t __riscv_mulhrsu_32(int32_t rs1, uint32_t rs2);`                 | `mulhrsu`(RV32), `pmulhrsu.w`(RV64)   |                                                    |
| `int32_t __riscv_mhraccsu_32(int32_t rd, int32_t rs1, uint32_t rs2);`    | `mhraccsu`(RV32), `pmhraccsu.w`(RV64) |                                                    |
| `int32_t __riscv_mulq_32(int32_t rs1, uint32_t rs2);`                    | `mulq`(RV32), `pmulq.w`(RV64)         |                                                    |
| `int32_t __riscv_mulqr_32(int32_t rs1, uint32_t rs2);`                   | `mulqr`(RV32), `pmulqr.w`(RV64)       |                                                    |

* TODO: Do we need intrinsic for MHACC(U)
* TODO: Do we need intrinsic for MULHRACC(U)
* TODO: Do we need intrinsics for MSEQ/MSLT/MSLTU
* TODO: How to handle VXSAT?

### RV32 Only Scalar Intrinsics

| Prototype                                                              | Instruction                 | Notes                          |
|------------------------------------------------------------------------|-----------------------------|--------------------------------|
| `uint32_t __riscv_slx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`    | `slx`                       |                                |
| `uint32_t __riscv_srx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`    | `srx`                       |                                |
| `uint64_t __riscv_wsll_32(uint32_t rs1, unsigned shamt);`              | `wsll[i]`                   |                                |
| `int64_t __riscv_wsla_32(int32_t rs1, unsigned shamt);`                | `wsla[i]`                   |                                |
| `uint64_t __riscv_wzip8p_32(uint32_t rs1, uint32_t rs2);`              | `wzip8p`                    |                                |
| `uint64_t __riscv_wzip16p_32(uint32_t rs1, uint32_t rs2);`             | `wzip16p`                   |                                |
| `int64_t __riscv_wadd_32(int32_t rs1, int32_t rs2);`                   | `wadd`                      |                                |
| `int64_t __riscv_wadda_32(int64_t rd, int32_t rs1, int32_t rs2);`      | `wadda`                     |                                |
| `uint64_t __riscv_waddu_32(uint32_t rs1, uint32_t rs2);`               | `waddu`                     |                                |
| `uint64_t __riscv_waddau_32(uint64_t rd, uint32_t rs1, uint32_t rs2);` | `waddau`                    |                                |
| `int64_t __riscv_wmul_32(int32_t rs1, int32_t rs2);`                   | `wmul`                      |                                |
| `int64_t __riscv_wmacc_32(int32_t rd, int32_t rs1, int32_t rs2);`      | `wmacc`                     |                                |
| `int64_t __riscv_wmulu_32(uint32_t rs1, uint32_t rs2);`                | `wmulu`                     |                                |
| `uint64_t __riscv_wmaccu_32(uint64_t rd, uint32_t rs1, uint32_t rs2);` | `wmaccu`                    |                                |
| `int64_t __riscv_wsub_32(int32_t rs1, int32_t rs2);`                   | `wsub`                      |                                |
| `int64_t __riscv_wsuba_32(int64_t rd, int32_t rs1, int32_t rs2);`      | `wsuba`                     |                                |
| `uint64_t __riscv_wsubu_32(uint32_t rs1, uint32_t rs2);`               | `wsubu`                     |                                |
| `uint64_t __riscv_wsubau_32(uint64_t rd, uint32_t rs1, uint32_t rs2);` | `wsubau`                    |                                |
| `int64_t __riscv_wmulsu_32(int32_t rs1, uint32_t rs2);`                | `wmulsu`                    |                                |
| `int64_t __riscv_wmaccsu_32(int64_t rd, int32_t rs1, uint32_t rs2);`   | `wmaccsu`                   |                                |
| `int64_t __riscv_mqwacc_32(int64_t rd, int32_t rs1, int32_t rs2);`     | `mqwacc`                    |                                |
| `int64_t __riscv_mqrwacc_32(int64_t rd, int32_t rs1, int32_t rs2);`    | `mqrwacc`                   |                                |
| `uint32_t __riscv_nsrl_32(uint64_t rs1_p, uint32_t rs2);`              | `nsrl[i]`                   |                                |
| `uint32_t __riscv_nclipu_32(uint64_t rs1_p, uint32_t rs2);`            | `nclip[i]u`                 |                                |
| `uint32_t __riscv_nclipru_32(uint64_t rs1_p, uint32_t rs2);`           | `nclipr[i]u`                |                                |
| `int32_t __riscv_nsra_32(int64_t rs1_p, uint32_t rs2);`                | `nsra[i]`                   |                                |
| `int32_t __riscv_nsrar_32(int64_t rs1_p, uint32_t rs2);`               | `nsrar[i]`                  |                                |
| `int32_t __riscv_nclip_32(int64_t rs1_p, uint32_t rs2);`               | `nclip[i]`                  |                                |
| `int32_t __riscv_nclipr_32(int64_t rs1_p, uint32_t rs2);`              | `nclipr[i]`                 |                                |

* TODO: Do we need intrinsics for ADDD or SUBD? Or can compiler figure it out?

### RV64 Only Scalar Intrinsics

| Prototype                                                               | Instruction                 | Notes                          |
|-------------------------------------------------------------------------|-----------------------------|--------------------------------|
| `uint64_t __riscv_abs_64(int64_t rs1);`                                 | `abs`                       |                                |
| `unsigned __riscv_cls_64(int64_t rs1);`                                 | `cls`                       |                                |
| `uint64_t __riscv_rev_64(uint64_t rs1);`                                | `rev`                       |                                |
| `uint64_t __riscv_rev16_64(uint64_t rs1);`                              | `rev16`                     |                                |
| `int64_t __riscv_sha_64(int64_t rs1, int rs2);`                         | `sha`                       |                                |
| `int64_t __riscv_shar_64(int64_t rs1, int rs2);`                        | `shar`                      |                                |
| `uint64_t __riscv_usati_64(int64_t rs1, const unsigned shamt);`         | `usati`                     |                                |
| `int64_t __riscv_srari_64(int64_t rs1, const unsigned shamt);`          | `srari`                     |                                |
| `int64_t __riscv_sati_64(int64_t rs1, const unsigned shamt);`           | `sati`                      |                                |
| `uint64_t __riscv_slx_64(uint64_t rd, uint64_t rs1, uint64_t rs2);`     | `slx`                       |                                |
| `uint64_t __riscv_srx_64(uint64_t rd, uint64_t rs1, uint64_t rs2);`     | `srx`                       |                                |
| `uint64_t __riscv_unzip8p_64(uint64_t rs1, uint64_t rs2);`              | `unzip8p`                   |                                |
| `uint64_t __riscv_unzip16p_64(uint64_t rs1, uint64_t rs2);`             | `unzip16p`                  |                                |
| `uint64_t __riscv_unzip8hp_64(uint64_t rs1, uint64_t rs2);`             | `unzip8hp`                  |                                |
| `uint64_t __riscv_unzip16hp_64(uint64_t rs1, uint64_t rs2);`            | `unzip16hp`                 |                                |
| `uint64_t __riscv_zip8p_64(uint64_t rs1, uint64_t rs2);`                | `zip8p`                     |                                |
| `uint64_t __riscv_zip16p_64(uint64_t rs1, uint64_t rs2);`               | `zip16p`                    |                                |
| `uint64_t __riscv_zip8hp_64(uint64_t rs1, uint64_t rs2);`               | `zip8hp`                    |                                |
| `uint64_t __riscv_zip16hp_64(uint64_t rs1, uint64_t rs2);`              | `zip16hp`                   |                                |

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

## Packed 32-bit Intrinsics

The intrinsic interface is designed as much as possible to be source code portable between RV32 and RV64. This does not necessarily mean it is performance portable. Intrinsics operating
on 32-bit and 64-bit types are provided for both RV32 and RV64.

| Prototype                                                                           | Instruction                               | Notes                                              |
|-------------------------------------------------------------------------------------|-------------------------------------------|----------------------------------------------------|
| `uint8x4_t __riscv_pmv_s_u8x4(uint8_t x);`                                          | `padd.bs`(rs1=x0), `pli.b`                | Compiler will pick immediate form when possible    |
| `int8x4_t __riscv_pmv_s_i8x4(int8_t x);`                                            | `padd.bs`(rs1=x0), `pli.b`                | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_pmv_s_u16x2(uint16_t x);`                                       | `padd.hs`(rs1=x0), `pli.h`, `plui.h`      | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_pmv_s_i16x2(int16_t x);`                                         | `padd.hs`(rs1=x0), `pli.h`, `plui.h`      | Compiler will pick immediate form when possible    |
| `uint8x4_t __riscv_psll_s_u8x4(uint8x4_t rs1, unsigned shamt);`                     | `pslli.b`, `psll.bs`                      | Compiler will pick immediate form when possible    |
| `int8x4_t __riscv_psll_s_i8x4(int8x4_t rs1, unsigned shamt);`                       | `pslli.b`, `psll.bs`                      | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_psll_s_u16x2(uint16x2_t rs1, unsigned shamt);`                  | `pslli.h`, `psll.hs`                      | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psll_s_i16x2(int16x2_t rs1, unsigned shamt);`                    | `pslli.h`, `psll.hs`                      | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psslai_i16x2(int16x2_t rs1, const unsigned shamt);`              | `psslai.h`                                |                                                    |
| `int16x2_t __riscv_psext_b_i16x2(int16x2_t rs1);`                                   | `psext.h.b`                               |                                                    |
| `int8x4_t __riscv_psabs_i8x4(int8x4_t rs1);`                                        | `psabs.b`                                 |                                                    |
| `int16x2_t __riscv_psabs_i16x2(int16x2_t rs1);`                                     | `psabs.h`                                 |                                                    |
| `uint8x4_t __riscv_padd_s_u8x4(uint8x4_t rs1, uint8_t rs2);`                        | `padd.bs`                                 |                                                    |
| `int8x4_t __riscv_padd_s_i8x4(int8x4_t rs1, int8_t rs2);`                           | `padd.bs`                                 |                                                    |
| `uint16x2_t __riscv_padd_s_u16x2(uint16x2_t rs1, uint16_t rs2);`                    | `padd.hs`                                 |                                                    |
| `int16x2_t __riscv_padd_s_i16x2(int16x2_t rs1, int16_t rs2);`                       | `padd.hs`                                 |                                                    |
| `int16x2_t __riscv_pssha_s_i16x2(int16x2_t rs1, int shamt);`                        | `pssha.hs`                                |                                                    |
| `int16x2_t __riscv_psshar_s_i16x2(int16x2_t rs1, int shamt);`                       | `psshar.hs`                               |                                                    |
| `uint8x4_t __riscv_psrl_s_u8x4(uint8x4_t rs1, unsigned shamt);`                     | `psrli.b`, `psrl.bs`                      | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_psrl_s_u16x2(uint16x2_t rs1, unsigned shamt);`                  | `psrli.h`, `psrl.hs`                      | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_pusati_u16x2(int16x2_t rs1, const unsigned shamt);`             | `pusati.h`                                |                                                    |
| `int8x4_t __riscv_psra_s_i8x4(int8x4_t rs1, unsigned shamt);`                       | `psrai.b`, `psra.bs`                      | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psra_s_i16x2(int16x2_t rs1, unsigned shamt);`                    | `psrai.h`, `psra.hs`                      | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psrari_i16x2(int16x2_t rs1, const unsigned shamt);`              | `psrari.h`                                |                                                    |
| `int16x2_t __riscv_psati_i16x2(int16x2_t rs1, const unsigned shamt);`               | `psati.h`                                 |                                                    |
| `int32_t __riscv_predsum_s_32_i8x4(int8x4_t rs1, int32_t rs2);`                     | `predsum.bs`                              | Requires zext.w to clear upper lanes on RV64       |
| `uint32_t __riscv_predsumu_s_32_u8x4(uint8x4_t rs1, uint32_t rs2);`                 | `predsumu.bs`                             | Requires zext.w to clear upper lanes on RV64       |
| `int32_t __riscv_predsum_s_32_i16x2(int16x2_t rs1, int32_t rs2);`                   | `predsum.hs`                              | Requires zext.w to clear upper lanes on RV64       |
| `uint32_t __riscv_predsumu_s_32_i16x2(uint16x2_t rs1, uint32_t rs2);`               | `predsumu.hs`                             | Requires zext.w to clear upper lanes on RV64       |
| `int64_t __riscv_predsum_s_64_i8x4(int8x4_t rs1, int64_t rs2);`                     | `predsum.bs`                              | Requires zext.w to clear upper lanes on RV64       |
| `uint64_t __riscv_predsumu_s_64_u8x4(uint8x4_t rs1, uint64_t rs2);`                 | `predsumu.bs`                             | Requires zext.w to clear upper lanes on RV64       |
| `int64_t __riscv_predsum_s_64_i16x2(int16x2_t rs1, int64_t rs2);`                   | `predsum.hs`                              | Requires zext.w to clear upper lanes on RV64       |
| `uint64_t __riscv_predsumu_s_64_i16x2(uint16x2_t rs1, uint64_t rs2);`               | `predsumu.hs`                             | Requires zext.w to clear upper lanes on RV64       |
| `int8x4_t __riscv_padd_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `padd.b`                                  |                                                    |
| `uint8x4_t __riscv_padd_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | `padd.b`                                  |                                                    |
| `int16x2_t __riscv_padd_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `padd.h`                                  |                                                    |
| `uint16x2_t __riscv_padd_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | `padd.h`                                  |                                                    |
| `int8x4_t __riscv_psadd_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `psadd.b`                                 |                                                    |
| `int16x2_t __riscv_psadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `psadd.h`                                 |                                                    |
| `int8x4_t __riscv_paadd_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `paadd.b`                                 |                                                    |
| `int16x2_t __riscv_paadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `paadd.h`                                 |                                                    |
| `uint8x4_t __riscv_psaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `psaddu.b`                                |                                                    |
| `uint16x2_t __riscv_psaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `psaddu.h`                                |                                                    |
| `uint8x4_t __riscv_paaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `paaddu.b`                                |                                                    |
| `uint16x2_t __riscv_paaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `paaddu.h`                                |                                                    |
| `int8x4_t __riscv_psub_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `psub.b`                                  |                                                    |
| `uint8x4_t __riscv_psub_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | `psub.b`                                  |                                                    |
| `int16x2_t __riscv_psub_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `psub.h`                                  |                                                    |
| `uint16x2_t __riscv_psub_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | `psub.h`                                  |                                                    |
| `uint8x4_t __riscv_pabd_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `pabd.b`                                  |                                                    |
| `uint16x2_t __riscv_pabd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pabd.h`                                  |                                                    |
| `int8x4_t __riscv_pssub_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `pssub.b`                                 |                                                    |
| `int16x2_t __riscv_pssub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pssub.h`                                 |                                                    |
| `int8x4_t __riscv_pasub_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `pasub.b`                                 |                                                    |
| `int16x2_t __riscv_pasub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pasub.h`                                 |                                                    |
| `uint8x4_t __riscv_pabdu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | `pabdu.b`                                 |                                                    |
| `uint16x2_t __riscv_pabdu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pabdu.h`                                 |                                                    |
| `uint8x4_t __riscv_pssubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pssubu.b`                                |                                                    |
| `uint16x2_t __riscv_pssubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pssubu.h`                                |                                                    |
| `uint8x4_t __riscv_pasubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pasubu.b`                                |                                                    |
| `uint16x2_t __riscv_pasubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pasubu.h`                                |                                                    |
| `uint8x4_t __riscv_merge_u8x4(uint8x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`         | `merge`, `mvm`, `mvmn`                    | Compiler will pick instruction                     |
| `int8x4_t __riscv_merge_i8x4(uint8x4_t rd, int8x4_t rs1, int8x4_t rs2);`            | `merge`, `mvm`, `mvmn`                    | Compiler will pick instruction                     |
| `uint16x2_t __riscv_merge_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`    | `merge`, `mvm`, `mvmn`                    | Compiler will pick instruction                     |
| `int16x2_t __riscv_merge_i16x2(uint16x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `merge`, `mvm`, `mvmn`                    | Compiler will pick instruction                     |
| `uint32_t __riscv_pabdsumu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `pabdsumu.b`                              | Requires zext.w to clear upper lanes on RV64       |
| `uint32_t __riscv_pabdsumau_32_u8x4(uint32_t rd, uint8x4_t rs1, uint8x4_t rs2);`    | `pabdsumau.b`                             | Requires zext.w to clear upper lanes on RV64       |
| `uint64_t __riscv_pabdsumau_64_u8x4(uint64_t rd, uint8x4_t rs1, uint8x4_t rs2);`    | `pabdsumau.b`                             | Requires zext.w to clear upper lanes on RV64       |
| `int16x2_t __riscv_psh1add_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `psh1add.h`                               |                                                    |
| `int16x2_t __riscv_pssh1sadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                  | `pssh1sadd.h`                             |                                                    |
| `uint8x4_t __riscv_ppaire_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `ppaire.b`                                |                                                    |
| `uint8x4_t __riscv_ppaireo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `ppaireo.b`                               |                                                    |
| `uint8x4_t __riscv_ppairoe_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `ppairoe.b`                               |                                                    |
| `uint8x4_t __riscv_ppairo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `ppairo.b`                                |                                                    |
| `uint16x2_t __riscv_ppaire_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pack`(RV32), `ppaire.h`(RV64)            |                                                    |
| `uint16x2_t __riscv_ppaireo_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | `ppaireo.h`                               |                                                    |
| `uint16x2_t __riscv_ppairoe_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | `ppairoe.h`                               |                                                    |
| `uint16x2_t __riscv_ppairo_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `ppairo.h`                                |                                                    |
| `int32_t __riscv_pm4add_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | `pm4add.b`                                |                                                    |
| `int32_t __riscv_pm2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `pm2add.h`                                |                                                    |
| `int32_t __riscv_pm4adda_i8x4(int32_t rd, int8x4_t rs1, int8x4_t rs2);`             | `pm4adda.b`                               |                                                    |
| `int32_t __riscv_pm2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | `pm2adda.h`                               |                                                    |
| `int32_t __riscv_pm2add_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pm2add.hx`                               |                                                    |
| `int32_t __riscv_pm2adda_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `pm2adda.hx`                              |                                                    |
| `uint32_t __riscv_pm4addu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pm4addu.b`                               |                                                    |
| `uint32_t __riscv_pm2addu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pm2addu.h`                               |                                                    |
| `uint32_t __riscv_pm4addau_u8x4(uint32_t rd, uint8x4_t rs1, uint8x4_t rs2);`        | `pm4addau.b`                              |                                                    |
| `uint32_t __riscv_pm2addau_u16x2(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`     | `pm2addau.h`                              |                                                    |
| `int32_t __riscv_pmq2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pmq2add.h`                               |                                                    |
| `int32_t __riscv_pmqr2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmqr2add.h`                              |                                                    |
| `int32_t __riscv_pmq2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`         | `pmq2adda.h`                              |                                                    |
| `int32_t __riscv_pmqr2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `pmqr2adda.h`                             |                                                    |
| `int32_t __riscv_pm2sadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pm2sadd.h`                               |                                                    |
| `int32_t __riscv_pm2sadd_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `pm2sadd.hx`                              |                                                    |
| `int32_t __riscv_pm2sub_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `pm2sub.h`                                |                                                    |
| `int32_t __riscv_pm2suba_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | `pm2suba.h`                               |                                                    |
| `int32_t __riscv_pm2sub_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pm2sub.hx`                               |                                                    |
| `int32_t __riscv_pm2suba_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | `pm2suba.hx`                              |                                                    |
| `int32_t __riscv_pm4addsu_i8x4(int8x4_t rs1, uint8x4_t rs2);`                       | `pm4addsu.b`                              |                                                    |
| `int32_t __riscv_pm2addsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                    | `pm2addsu.h`                              |                                                    |
| `int32_t __riscv_pm4addasu_i8x4(int32_t rd, int8x4_t rs1, uint8x4_t rs2);`          | `pm4addasu.b`                             |                                                    |
| `int32_t __riscv_pm2addasu_i16x2(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`       | `pm2addasu.h`                             |                                                    |
| `int16x2_t __riscv_pas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pas.hx`                                  |                                                    |
| `int16x2_t __riscv_psa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `psa.hx`                                  |                                                    |
| `int16x2_t __riscv_psas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `psas.hx`                                 |                                                    |
| `int16x2_t __riscv_pssa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pssa.hx`                                 |                                                    |
| `int16x2_t __riscv_paas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `paas.hx`                                 |                                                    |
| `int16x2_t __riscv_pasa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pasa.hx`                                 |                                                    |
| `uint8x4_t __riscv_pmseq_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pmseq.b`                                 |                                                    |
| `uint8x4_t __riscv_pmseq_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | `pmseq.b`                                 |                                                    |
| `uint16x2_t __riscv_pmseq_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmseq.h`                                 |                                                    |
| `uint16x2_t __riscv_pmseq_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pmseq.h`                                 |                                                    |
| `uint8x4_t __riscv_pmslt_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pmslt.b`                                 |                                                    |
| `uint16x2_t __riscv_pmslt_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmslt.h`                                 |                                                    |
| `uint8x4_t __riscv_pmsltu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | `pmsltu.b`                                |                                                    |
| `uint16x2_t __riscv_pmsltu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pmsltu.h`                                |                                                    |
| `int8x4_t __riscv_pmin_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `pmin.b`                                  |                                                    |
| `int16x2_t __riscv_pmin_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `pmin.h`                                  |                                                    |
| `uint8x4_t __riscv_pminu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | `pminu.b`                                 |                                                    |
| `uint16x2_t __riscv_pminu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pminu.h`                                 |                                                    |
| `int8x4_t __riscv_pmax_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `pmax.b`                                  |                                                    |
| `int16x2_t __riscv_pmax_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `pmax.h`                                  |                                                    |
| `uint8x4_t __riscv_pmaxu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | `pmaxu.b`                                 |                                                    |
| `uint16x2_t __riscv_pmaxu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | `pmaxu.h`                                 |                                                    |
| `int16x2_t __riscv_pmulh_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pmulh.h`                                 |                                                    |
| `int16x2_t __riscv_pmulhr_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmulhr.h`                                |                                                    |
| `int16x2_t __riscv_pmhacc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pmhacc.h`                                |                                                    |
| `int16x2_t __riscv_pmhracc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pmhracc.h`                               |                                                    |
| `uint16x2_t __riscv_pmulhu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pmulhu.h`                                |                                                    |
| `uint16x2_t __riscv_pmulhru_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | `pmulhru.h`                               |                                                    |
| `uint16x2_t __riscv_pmhaccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | `pmhaccu.h`                               |                                                    |
| `uint16x2_t __riscv_pmhraccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | `pmhraccu.h`                              |                                                    |
| `int16x2_t __riscv_pmulhsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                   | `pmulhsu.h`                               |                                                    |
| `int16x2_t __riscv_pmulhrsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                  | `pmulhrsu.h`                              |                                                    |
| `int16x2_t __riscv_pmhaccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`    | `pmhaccsu.h`                              |                                                    |
| `int16x2_t __riscv_pmhraccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`   | `pmhraccsu.h`                             |                                                    |
| `int16x2_t __riscv_pmulq_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pmulq.h`                                 |                                                    |
| `int16x2_t __riscv_pmulqr_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | `pmulqr.h`                                |                                                    |
| `int16x2_t __riscv_pmul00_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | `pmul.h.b00`                              |                                                    |
| `int16x2_t __riscv_pmul01_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | `pmul.h.b01`                              |                                                    |
| `int16x2_t __riscv_pmul11_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | `pmul.h.b11`                              |                                                    |
| `uint16x2_t __riscv_pmulu00_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | `pmulu.h.b00`                             |                                                    |
| `uint16x2_t __riscv_pmulu01_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | `pmulu.h.b01`                             |                                                    |
| `uint16x2_t __riscv_pmulu11_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | `pmulu.h.b11`                             |                                                    |
| `int16x2_t __riscv_pmulsu00_i16x2(int8x4_t rs1, uint8x4_t rs2);`                    | `pmulsu.h.b00`                            |                                                    |
| `int16x2_t __riscv_pmulsu11_i16x2(int8x4_t rs1, uint8x4_t rs2);`                    | `pmulsu.h.b11`                            |                                                    |
| `int32_t __riscv_mul00_32(int16x2_t rs1, int16x2_t rs2);`                           | `mul.h00`(RV32), `pmul.w.h00`(RV64)       |                                                    |
| `int32_t __riscv_mul01_32(int16x2_t rs1, int16x2_t rs2);`                           | `mul.h01`(RV32), `pmul.w.h01`(RV64)       |                                                    |
| `int32_t __riscv_mul11_32(int16x2_t rs1, int16x2_t rs2);`                           | `mul.h11`(RV32), `pmul.w.h11`(RV64)       |                                                    |
| `int32_t __riscv_macc00_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | `macc.h00`(RV32), `pmacc.w.h00`(RV64)     |                                                    |
| `int32_t __riscv_macc01_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | `macc.h01`(RV32), `pmacc.w.h01`(RV64)     |                                                    |
| `int32_t __riscv_macc11_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | `macc.h11`(RV32), `pmacc.w.h11`(RV64)     |                                                    |
| `uint32_t __riscv_mulu00_32(uint16x2_t rs1, uint16x2_t rs2);`                       | `mulu.h00`(RV32), `pmulu.w.h00`(RV64)     |                                                    |
| `uint32_t __riscv_mulu01_32(uint16x2_t rs1, uint16x2_t rs2);`                       | `mulu.h01`(RV32), `pmulu.w.h01`(RV64)     |                                                    |
| `uint32_t __riscv_mulu11_32(uint16x2_t rs1, uint16x2_t rs2);`                       | `mulu.h11`(RV32), `pmulu.w.h11`(RV64)     |                                                    |
| `uint32_t __riscv_maccu00_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | `maccu.h00`(RV32), `pmaccu.w.h00`(RV64)   |                                                    |
| `uint32_t __riscv_maccu01_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | `maccu.h01`(RV32), `pmaccu.w.h01`(RV64)   |                                                    |
| `uint32_t __riscv_maccu11_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | `maccu.h11`(RV32), `pmaccu.w.h11`(RV64)   |                                                    |
| `int32_t __riscv_mulsu00_32(int16x2_t rs1, uint16x2_t rs2);`                        | `mulsu.h00`(RV32), `pmulsu.w.h00`(RV64)   |                                                    |
| `int32_t __riscv_maccsu00_32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`           | `maccsu.h00`(RV32), `pmaccsu.w.h00`(RV64) |                                                    |
| `int32_t __riscv_mulsu11_32(int16x2_t rs1, uint16x2_t rs2);`                        | `mulsu.h11`(RV32), `pmulsu.w.h11`(RV64)   |                                                    |
| `int32_t __riscv_maccsu11_32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`           | `maccsu.h11`(RV32), `pmaccsu.w.h11`(RV64) |                                                    |
| `int32_t __riscv_mqacc00_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`             | `mqacc.h00`(RV32), `pmqacc.w.h00`(RV64)   |                                                    |
| `int32_t __riscv_mqacc01_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`             | `mqacc.h01`(RV32), `pmqacc.w.h01`(RV64)   |                                                    |
| `int32_t __riscv_mqacc11_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`             | `mqacc.h11`(RV32), `pmqacc.w.h11`(RV64)   |                                                    |
| `int32_t __riscv_mqracc00_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`            | `mqracc.h00`(RV32), `pmqracc.w.h00`(RV64) |                                                    |
| `int32_t __riscv_mqracc01_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`            | `mqracc.h01`(RV32), `pmqracc.w.h01`(RV64) |                                                    |
| `int32_t __riscv_mqracc11_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`            | `mqracc.h11`(RV32), `pmqracc.w.h11`(RV64) |                                                    |
| `int16x2_t __riscv_pmulh0_i16x2(int16x2_t rs1, int8x4_t rs2);`                      | `pmulh.h.b0`                              |                                                    |
| `int16x2_t __riscv_pmulh1_i16x2(int16x2_t rs1, int8x4_t rs2);`                      | `pmulh.h.b1`                              |                                                    |
| `int16x2_t __riscv_pmhacc0_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`       | `pmhacc.h.b0`                             |                                                    |
| `int16x2_t __riscv_pmhacc1_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`       | `pmhacc.h.b1`                             |                                                    |
| `int16x2_t __riscv_pmulhsu0_i16x2(int16x2_t rs1, uint8x4_t rs2);`                   | `pmulhsu.h.b0`                            |                                                    |
| `int16x2_t __riscv_pmulhsu1_i16x2(int16x2_t rs1, uint8x4_t rs2);`                   | `pmulhsu.h.b1`                            |                                                    |
| `int16x2_t __riscv_pmhaccsu0_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`    | `pmhaccsu.h.b0`                           |                                                    |
| `int16x2_t __riscv_pmhaccsu1_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`    | `pmhaccsu.h.b1`                           |                                                    |
| `int32_t __riscv_mulh0_32(int32_t rs1, int16x2_t rs2);`                             | `mulh.h0`(RV32), `pmulh.w.h0`(RV64)       |                                                    |
| `int32_t __riscv_mulh1_32(int32_t rs1, int16x2_t rs2);`                             | `mulh.h1`(RV32), `pmulh.w.h1`(RV64)       |                                                    |
| `int32_t __riscv_mhacc0_32(int32_t rd, int32_t rs1, int16x2_t rs2);`                | `mhacc.h0`(RV32), `pmhacc.w.h0`(RV64)     |                                                    |
| `int32_t __riscv_mhacc1_32(int32_t rd, int32_t rs1, int16x2_t rs2);`                | `mhacc.h1`(RV32), `pmhacc.w.h1`(RV64)     |                                                    |
| `int32_t __riscv_mulhsu0_32(int32_t rs1, uint16x2_t rs2);`                          | `mulhsu.h0`(RV32), `pmulhsu.w.h0`(RV64)   |                                                    |
| `int32_t __riscv_mulhsu1_32(int32_t rs1, uint16x2_t rs2);`                          | `mulhsu.h1`(RV32), `pmulhsu.w.h1`(RV64)   |                                                    |
| `int32_t __riscv_mhaccsu0_32(int32_t rd, int32_t rs1, uint16x2_t rs2);`             | `mhaccsu.h0`(RV32), `pmhaccsu.w.h0`(RV64) |                                                    |
| `int32_t __riscv_mhaccsu1_32(int32_t rd, int32_t rs1, uint16x2_t rs2);`             | `mhaccsu.h1`(RV32), `pmhaccsu.w.h1`(RV64) |                                                    |
| `int8x4_t __riscv_pand_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `and`                                     |                                                    |
| `uint8x4_t __riscv_pand_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | `and`                                     |                                                    |
| `int16x2_t __riscv_pand_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `and`                                     |                                                    |
| `uint16x2_t __riscv_pand_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | `and`                                     |                                                    |
| `int8x4_t __riscv_por_i8x4(int8x4_t rs1, int8x4_t rs2);`                            | `or`                                      |                                                    |
| `uint8x4_t __riscv_por_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                         | `or`                                      |                                                    |
| `int16x2_t __riscv_por_i16x2(int16x2_t rs1, int16x2_t rs2);`                        | `or`                                      |                                                    |
| `uint16x2_t __riscv_por_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                     | `or`                                      |                                                    |
| `int8x4_t __riscv_pxor_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | `xor`                                     |                                                    |
| `uint8x4_t __riscv_pxor_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | `xor`                                     |                                                    |
| `int16x2_t __riscv_pxor_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | `xor`                                     |                                                    |
| `uint16x2_t __riscv_pxor_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | `xor`                                     |                                                    |
| `int8x4_t __riscv_pnot_i8x4(int8x4_t rs1);`                                         | `not`                                     |                                                    |
| `uint8x4_t __riscv_pnot_u8x4(uint8x4_t rs1);`                                       | `not`                                     |                                                    |
| `int16x2_t __riscv_pnot_i16x2(int16x2_t rs1);`                                      | `not`                                     |                                                    |
| `uint16x2_t __riscv_pnot_u16x2(uint16x2_t rs1);`                                    | `not`                                     |                                                    |
| `int8x4_t __riscv_pneg_i8x4(int8x4_t rs2);`                                         | `psub.b`(rs1=x0)                          |                                                    |
| `int16x2_t __riscv_pneg_i16x2(int16x2_t rs2);`                                      | `psub.h`(rs1=x0)                          |                                                    |

* NOTE: pmv, padd, psub, pmeq, merge is provided in signed and unsigned version to avoid casts.
* NOTE: predsum(u) and pabdsumau provided with 32-bit and 64-bit accumulator sizes for software portability while also allowing XLEN specific coding. May require additional instructions when accumulator size is not XLEN.
* NOTE: pand/por/pxor provided to avoid casts to scalar
* NOTE: pnot provided to avoid needing to load -1 into a vector
* TODO: Packed intrinsics for (un)zip(8|16)8(h)p?
* TODO: `__riscv_pm2add_x_i16x2` or `__riscv_pm2addx_i16x2`
* TODO: Should we have (u)int32x1_t for symmetry with (u)int32x2_t. Intrinsics would then be named __riscv_p*.
* TODO: pzext_b pseudo using ppaire with x0
* TODO: cast intrinsics
* TODO: (un)aligned loads/stores

## Packed 64-bit Intrinsics

| Prototype                                                                           | Instruction                                                                                 | Notes                                              |
|-------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------|----------------------------------------------------|
| `uint8x8_t __riscv_pmv_s_u8x8(uint8_t x);`                                          | `padd.bs`(rs1=x0), `pli.b`(RV64), `padd.dbs`(rs1_p=x0), `pli.db`(RV32)                      | Compiler will pick immediate form when possible    |
| `int8x8_t __riscv_pmv_s_i8x8(int8_t x);`                                            | `padd.bs`(rs1=x0), `pli.b`(RV64), `padd.dbs`(rs1_p=x0), `pli.db`(RV32)                      | Compiler will pick immediate form when possible    |
| `uint16x4_t __riscv_pmv_s_u16x4(uint16_t x);`                                       | `padd.hs`(rs1=x0), `pli.h`, `plui.h`(RV64), `padd.dhs`(rs1_p=x0), `pli.dh`, `plui.dh`(RV32) | Compiler will pick immediate form when possible    |
| `int16x4_t __riscv_pmv_s_i16x4(int16_t x);`                                         | `padd.hs`(rs1=x0), `pli.h`, `plui.h`(RV64), `padd.dhs`(rs1_p=x0), `pli.dh`, `plui.dh`(RV32) | Compiler will pick immediate form when possible    |
| `uint32x2_t __riscv_pmv_s_u32x2(uint32_t x);`                                       | `padd.ws`(rs1=x0), `pli.w`, `plui.w`(RV64), `padd.dws`(rs1_p=x0), `lui`+`addi`+`mv`(RV32)   | Compiler will pick immediate form when possible    |
| `int32x2_t __riscv_pmv_s_i32x2(int32_t x);`                                         | `padd.ws`(rs1=x0), `pli.w`, `plui.w`(RV64), `padd.dws`(rs1_p=x0), `lui`+`addi`+`mv`(RV32)   | Compiler will pick immediate form when possible    |
| `uint8x8_t __riscv_psll_s_u8x8(uint8x8_t rs1, unsigned shamt);`                     | `pslli.b`, `psll.bs`(RV64), `pslli.db`, `psll.dbs` (RV32)                                   | Compiler will pick immediate form when possible    |
| `int8x8_t __riscv_psll_s_i8x8(int8x8_t rs1, unsigned shamt);`                       | `pslli.b`, `psll.bs`(RV64), `pslli.db`, `psll.dbs` (RV32)                                   | Compiler will pick immediate form when possible    |
| `uint16x4_t __riscv_psll_s_u16x4(uint16x4_t rs1, unsigned shamt);`                  | `pslli.h`, `psll.hs`(RV64), `pslli.dh`, `psll.dhs` (RV32)                                   | Compiler will pick immediate form when possible    |
| `int16x4_t __riscv_psll_s_i16x4(int16x4_t rs1, unsigned shamt);`                    | `pslli.h`, `psll.hs`(RV64), `pslli.dh`, `psll.dhs` (RV32)                                   | Compiler will pick immediate form when possible    |
| `uint32x2_t __riscv_psll_s_u32x2(uint32x2_t rs1, unsigned shamt);`                  | `pslli.w`, `psll.ws`(RV64), `pslli.dw`, `psll.dws` (RV32)                                   | Compiler will pick immediate form when possible    |
| `int32x2_t __riscv_psll_s_i32x2(int32x2_t rs1, unsigned shamt);`                    | `pslli.w`, `psll.ws`(RV64), `pslli.dw`, `psll.dws` (RV32)                                   | Compiler will pick immediate form when possible    |
| `int16x4_t __riscv_psslai_i16x4(int16x4_t rs1, const unsigned shamt);`              | `psslai.h`(RV64), `psslai.dh`(RV32)                                                         |                                                    |
| `int32x2_t __riscv_psslai_i32x2(int32x2_t rs1, const unsigned shamt);`              | `psslai.w`(RV64), `psslai.dw`(RV32)                                                         |                                                    |
| `int16x4_t __riscv_psext_b_i16x4(int16x4_t rs1);`                                   | `psext.h.b`(RV64), `psext.dh.b`(RV32)                                                       |                                                    |
| `int32x2_t __riscv_psext_b_i32x2(int32x2_t rs1);`                                   | `psext.w.b`(RV64), `psext.dw.b`(RV32)                                                       |                                                    |
| `int32x2_t __riscv_psext_h_i32x2(int32x2_t rs1);`                                   | `psext.w.h`(RV64), `psext.dw.h`(RV32)                                                       |                                                    |
| `int8x8_t __riscv_psabs_i8x8(int8x8_t rs1);`                                        | `psabs.b`(RV64), `psabs.db`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_psabs_i16x4(int16x4_t rs1);`                                     | `psabs.h`(RV64), `psabs.dh`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_padd_s_u8x8(uint8x8_t rs1, uint8_t rs2);`                        | `padd.bs`(RV64), `padd.dbs`(RV32)                                                           |                                                    |
| `int8x8_t __riscv_padd_s_i8x8(int8x8_t rs1, int8_t rs2);`                           | `padd.bs`(RV64), `padd.dbs`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_padd_s_u16x4(uint16x4_t rs1, uint16_t rs2);`                    | `padd.hs`(RV64), `padd.dhs`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_padd_s_i16x4(int16x4_t rs1, int16_t rs2);`                       | `padd.hs`(RV64), `padd.dhs`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_padd_s_u32x2(uint32x2_t rs1, uint32_t rs2);`                    | `padd.ws`(RV64), `padd.dws`(RV32)                                                           |                                                    |
| `int32x2_t __riscv_padd_s_i32x2(int32x2_t rs1, int32_t rs2);`                       | `padd.ws`(RV64), `padd.dws`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_pssha_s_i16x4(int16x4_t rs1, int shamt);`                        | `pssha.hs`(RV64), `pssha.dhs`(RV32)                                                         |                                                    |
| `int32x2_t __riscv_pssha_s_i32x2(int16x4_t rs1, int shamt);`                        | `pssha.ws`(RV64), `pssha.dws`(RV32)                                                         |                                                    |
| `int16x4_t __riscv_psshar_s_i16x4(int32x2_t rs1, int shamt);`                       | `psshar.hs`(RV64), `psshar.dhs`(RV32)                                                       |                                                    |
| `int32x2_t __riscv_psshar_s_i32x2(int32x2_t rs1, int shamt);`                       | `psshar.ws`(RV64), `psshar.dws`(RV32)                                                       |                                                    |
| `uint8x8_t __riscv_psrl_s_u8x8(uint8x8_t rs1, unsigned shamt);`                     | `psrli.b`, `psrl.bs`(RV64), `psrli.db`, `psrl.dbs`(RV32)                                    |                                                    |
| `uint16x4_t __riscv_psrl_s_u16x4(uint16x4_t rs1, unsigned shamt);`                  | `psrli.h`, `psrl.hs`(RV64), `psrli.dh`, `psrl.dhs`(RV32)                                    |                                                    |
| `uint32x2_t __riscv_psrl_s_u32x2(uint32x2_t rs1, unsigned shamt);`                  | `psrli.w`, `psrl.ws`(RV64), `psrli.dw`, `psrl.dws`(RV32)                                    |                                                    |
| `uint16x4_t __riscv_pusati_u16x4(int16x4_t rs1, const unsigned shamt);`             | `pusati.h`(RV64), `pusati.dh`(RV32)                                                         |                                                    |
| `uint32x2_t __riscv_pusati_u32x2(int32x2_t rs1, const unsigned shamt);`             | `pusati.w`(RV64), `pusati.dw`(RV32)                                                         |                                                    |
| `int8x8_t __riscv_psra_s_i8x8(int8x8_t rs1, unsigned shamt);`                       | `psrai.b`, `psra.bs`(RV64), `psrai.db`, `psra.dbs`(RV32)                                    | Compiler will pick immediate form when possible    |
| `int16x4_t __riscv_psra_s_i16x4(int16x4_t rs1, unsigned shamt);`                    | `psrai.h`, `psra.hs`(RV64), `psrai.dh`, `psra.dhs`(RV32)                                    | Compiler will pick immediate form when possible    |
| `int32x2_t __riscv_psra_s_i32x2(int32x2_t rs1, unsigned shamt);`                    | `psrai.w`, `psra.ws`(RV64), `psrai.dw`, `psra.dws`(RV32)                                    | Compiler will pick immediate form when possible    |
| `int16x4_t __riscv_psrari_i16x4(int16x4_t rs1, const unsigned shamt);`              | `psrari.h`(RV64), `psrari.dh`(RV32)                                                         |                                                    |
| `int32x2_t __riscv_psrari_i32x2(int32x2_t rs1, const unsigned shamt);`              | `psrari.w`(RV64), `psrari.dw`(RV32)                                                         |                                                    |
| `int16x4_t __riscv_psati_i16x4(int16x4_t rs1, const unsigned shamt);`               | `psati.h`(RV64), `psati.h`(RV32)                                                            |                                                    |
| `int32x2_t __riscv_psati_i32x2(int32x2_t rs1, const unsigned shamt);`               | `psati.w`(RV64), `psati.w`(RV32)                                                            |                                                    |
| `int32_t __riscv_predsum_s_32_i8x8(int8x8_t rs1, int32_t rs2);`                     | `predsum.bs`(RV64), `predsum.dbs`(RV32)                                                     |                                                    |
| `uint32_t __riscv_predsumu_s_32_u8x8(uint8x8_t rs1, uint32_t rs2);`                 | `predsumu.bs`(RV64), `predsumu.dbs`(RV32)                                                   |                                                    |
| `int32_t __riscv_predsum_s_32_i16x4(int16x4_t rs1, int32_t rs2);`                   | `predsum.hs`(RV64), `predsum.dhs`(RV32)                                                     |                                                    |
| `uint32_t __riscv_predsumu_s_32_i16x4(uint16x4_t rs1, uint32_t rs2);`               | `predsumu.hs`(RV64), `predsumu.dhs`(RV32)                                                   |                                                    |
| `int64_t __riscv_predsum_s_64_i8x8(int8x8_t rs1, int64_t rs2);`                     | `predsum.bs`(RV64), `predsum.dbs`(RV32)                                                     |                                                    |
| `uint64_t __riscv_predsumu_s_64_u8x8(uint8x8_t rs1, uint64_t rs2);`                 | `predsumu.bs`(RV64), `predsumu.dbs`(RV32)                                                   |                                                    |
| `int64_t __riscv_predsum_s_64_i16x4(int16x4_t rs1, int64_t rs2);`                   | `predsum.hs`(RV64), `predsum.dhs`(RV32)                                                     |                                                    |
| `uint64_t __riscv_predsumu_s_64_i16x4(uint16x4_t rs1, uint64_t rs2);`               | `predsumu.hs`(RV64), `predsum.dhs`(RV32)                                                    |                                                    |
| `int8x8_t __riscv_padd_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `padd.b`(RV64), `padd.db`(RV32)                                                             |                                                    |
| `uint8x8_t __riscv_padd_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                        | `padd.b`(RV64), `padd.db`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_padd_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `padd.h`(RV64), `padd.dh`(RV32)                                                             |                                                    |
| `uint16x4_t __riscv_padd_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                    | `padd.h`(RV64), `padd.dh`(RV32)                                                             |                                                    |
| `int32x2_t __riscv_padd_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `padd.w`(RV64), `padd.dw`(RV32)                                                             |                                                    |
| `uint32x2_t __riscv_padd_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                    | `padd.w`(RV64), `padd.dw`(RV32)                                                             |                                                    |
| `int8x8_t __riscv_psadd_i8x8(int8x8_t rs1, int8x8_t rs2);`                          | `psadd.b`(RV64), `psadd.db`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_psadd_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `psadd.h`(RV64), `psadd.dh`(RV32)                                                           |                                                    |
| `int32x2_t __riscv_psadd_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `psadd.w`(RV64), `psadd.dw`(RV32)                                                           |                                                    |
| `int8x8_t __riscv_paadd_i8x8(int8x8_t rs1, int8x8_t rs2);`                          | `paadd.b`(RV64), `paadd.db`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_paadd_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `paadd.h`(RV64), `paadd.dh`(RV32)                                                           |                                                    |
| `int32x2_t __riscv_paadd_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `paadd.w`(RV64), `paadd.dw`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_psaddu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `psaddu.b`(RV64), `psaddu.db`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_psaddu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `psaddu.h`(RV64), `psaddu.dh`(RV32)                                                         |                                                    |
| `uint32x2_t __riscv_psaddu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `psaddu.w`(RV64), `psaddu.dw`(RV32)                                                         |                                                    |
| `uint8x8_t __riscv_paaddu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `paaddu.b`(RV64), `paaddu.db`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_paaddu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `paaddu.h`(RV64), `paaddu.dh`(RV32)                                                         |                                                    |
| `uint32x2_t __riscv_paaddu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `paaddu.w`(RV64), `paaddu.dw`(RV32)                                                         |                                                    |
| `int8x8_t __riscv_psub_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `psub.b`(RV64), `psub.db`(RV32)                                                             |                                                    |
| `uint8x8_t __riscv_psub_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                        | `psub.b`(RV64), `psub.db`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_psub_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `psub.h`(RV64), `psub.dh`(RV32)                                                             |                                                    |
| `uint16x4_t __riscv_psub_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                    | `psub.h`(RV64), `psub.dh`(RV32)                                                             |                                                    |
| `int32x2_t __riscv_psub_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `psub.w`(RV64), `psub.dw`(RV32)                                                             |                                                    |
| `uint32x2_t __riscv_psub_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                    | `psub.w`(RV64), `psub.dw`(RV32)                                                             |                                                    |
| `uint8x8_t __riscv_pabd_i8x8(int8x8_t rs1, int8x8_t rs2);`                          | `pabd.b`(RV64), `pabd.db`(RV32)                                                             |                                                    |
| `uint16x4_t __riscv_pabd_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pabd.h`(RV64), `pabd.dh`(RV32)                                                             |                                                    |
| `int8x8_t __riscv_pssub_i8x8(int8x8_t rs1, int8x8_t rs2);`                          | `pssub.b`(RV64), `pssub.db`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_pssub_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pssub.h`(RV64), `pssub.dh`(RV32)                                                           |                                                    |
| `int32x2_t __riscv_pssub_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pssub.w`(RV64), `pssub.dw`(RV32)                                                           |                                                    |
| `int8x8_t __riscv_pasub_i8x8(int8x8_t rs1, int8x8_t rs2);`                          | `pasub.b`(RV64), `pasub.db`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_pasub_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pasub.h`(RV64), `pasub.dh`(RV32)                                                           |                                                    |
| `int32x2_t __riscv_pasub_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pasub.w`(RV64), `pasub.dw`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pabdu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                       | `pabdu.b`(RV64), `pabdu.db`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pabdu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pabdu.h`(RV64), `pabdu.dh`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pssubu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `pssubu.b`(RV64), `pssubu.db`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_pssubu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pssubu.h`(RV64), `pssubu.dh`(RV32)                                                         |                                                    |
| `uint32x2_t __riscv_pssubu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pssubu.w`(RV64), `pssubu.dw`(RV32)                                                         |                                                    |
| `uint8x8_t __riscv_pasubu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `pasubu.b`(RV64), `pasubu.db`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_pasubu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pasubu.h`(RV64), `pasubu.dh`(RV32)                                                         |                                                    |
| `uint32x2_t __riscv_pasubu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pasubu.w`(RV64), `pasubu.dw`(RV32)                                                         |                                                    |
| `uint8x8_t __riscv_merge_u8x8(uint8x8_t rd, uint8x8_t rs1, uint8x8_t rs2);`         | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `int8x8_t __riscv_merge_i8x8(uint8x8_t rd, int8x8_t rs1, int8x8_t rs2);`            | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `uint16x4_t __riscv_merge_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);`    | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `int16x4_t __riscv_merge_i16x4(uint16x4_t rd, int16x4_t rs1, int16x4_t rs2);`       | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `uint32x2_t __riscv_merge_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);`    | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `int32x2_t __riscv_merge_i32x2(uint32x2_t rd, int32x2_t rs1, int32x2_t rs2);`       | `merge`, `mvm`, `mvmn`                                                                      | Compiler will pick instruction                     |
| `int16x4_t __riscv_psh1add_i16x4(int16x4_t rs1, int16x4_t rs2);`                    | `psh1add.h`(RV64), `psh1add.dh`(RV32)                                                       |                                                    |
| `int32x2_t __riscv_psh1add_i32x2(int32x2_t rs1, int32x2_t rs2);`                    | `psh1add.w`(RV64), `psh1add.dw`(RV32)                                                       |                                                    |
| `int16x4_t __riscv_pssh1sadd_i16x4(int16x4_t rs1, int16x4_t rs2);`                  | `pssh1sadd.h`(RV64), `pssh1sadd.dh`(RV32)                                                   |                                                    |
| `int32x2_t __riscv_pssh1sadd_i32x2(int32x2_t rs1, int32x2_t rs2);`                  | `pssh1sadd.w`(RV64), `pssh1sadd.dw`(RV32)                                                   |                                                    |
| `uint8x8_t __riscv_ppaire_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `ppaire.b`(RV64), `ppaire.db`(RV32)                                                         |                                                    |
| `uint8x8_t __riscv_ppaireo_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                     | `ppaireo.b`(RV64), `ppaireo.db`(RV32)                                                       |                                                    |
| `uint8x8_t __riscv_ppairoe_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                     | `ppairoe.b`(RV64), `ppairoe.db`(RV32)                                                       |                                                    |
| `uint8x8_t __riscv_ppairo_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `ppairo.b`(RV64), `ppairo.db`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_ppaire_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `ppaire.h`(RV64), `ppaire.dh`(RV32)                                                         |                                                    |
| `uint16x4_t __riscv_ppaireo_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                 | `ppaireo.h`(RV64), `ppaireo.dh`(RV32)                                                       |                                                    |
| `uint16x4_t __riscv_ppairoe_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                 | `ppairoe.h`(RV64), `ppairoe.dh`(RV32)                                                       |                                                    |
| `uint16x4_t __riscv_ppairo_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `ppairo.h`(RV64), `ppairo.dh`(RV32)                                                         |                                                    |
| `int16x4_t __riscv_pas_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pas.hx`(RV64), `pas.dhx`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_psa_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `psa.hx`(RV64), `psa.dhx`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_psas_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `psas.hx`(RV64), `psas.dhx`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_pssa_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pssa.hx`(RV64), `pssa.dhx`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_paas_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `paas.hx`(RV64), `paas.dhx`(RV32)                                                           |                                                    |
| `int16x4_t __riscv_pasa_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pasa.hx`(RV64), `pasa.dhx`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pmseq_i8x8(int8x8_t rs1, int8x8_t rs2);`                         | `pmseq.b`(RV64), `pmseq.db`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pmseq_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                       | `pmseq.b`(RV64), `pmseq.db`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pmseq_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmseq.h`(RV64), `pmseq.dh`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pmseq_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pmseq.h`(RV64), `pmseq.dh`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_pmseq_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmseq.w`(RV64), `pmseq.dw`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_pmseq_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pmseq.w`(RV64), `pmseq.dw`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pmslt_i8x8(int8x8_t rs1, int8x8_t rs2);`                         | `pmslt.b`(RV64), `pmslt.db`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pmslt_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dh`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_pmslt_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmslt.h`(RV64), `pmslt.dw`(RV32)                                                           |                                                    |
| `uint8x8_t __riscv_pmsltu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                      | `pmsltu.b`(RV64), `pmslt.db`(RV32)                                                          |                                                    |
| `uint16x4_t __riscv_pmsltu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pmsltu.h`(RV64), `pmslt.dh`(RV32)                                                          |                                                    |
| `uint32x2_t __riscv_pmsltu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pmsltu.w`(RV64), `pmslt.dw`(RV32)                                                          |                                                    |
| `int8x8_t __riscv_pmin_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `pmin.b`(RV64), `pmin.db`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_pmin_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `pmin.h`(RV64), `pmin.dh`(RV32)                                                             |                                                    |
| `int32x2_t __riscv_pmin_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pmin.w`(RV64), `pmin.dw`(RV32)                                                             |                                                    |
| `uint8x8_t __riscv_pminu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                       | `pminu.b`(RV64), `pminu.db`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pminu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pminu.h`(RV64), `pminu.dh`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_pminu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pminu.w`(RV64), `pminu.dw`(RV32)                                                           |                                                    |
| `int8x8_t __riscv_pmax_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `pmax.b`(RV64), `pmax.db`(RV32)                                                             |                                                    |
| `int16x4_t __riscv_pmax_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `pmax.h`(RV64), `pmax.dh`(RV32)                                                             |                                                    |
| `int32x2_t __riscv_pmax_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pmax.w`(RV64), `pmax.dw`(RV32)                                                             |                                                    |
| `uint8x8_t __riscv_pmaxu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                       | `pmaxu.b`(RV64), `pmaxu.db`(RV32)                                                           |                                                    |
| `uint16x4_t __riscv_pmaxu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pmaxu.h`(RV64), `pmaxu.dh`(RV32)                                                           |                                                    |
| `uint32x2_t __riscv_pmaxu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pmaxu.w`(RV64), `pmaxu.dw`(RV32)                                                           |                                                    |
| `int8x8_t __riscv_pand_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `and`                                                                                       | RV32 requires 2 instructions                       |
| `uint8x8_t __riscv_pand_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                        | `and`                                                                                       | RV32 requires 2 instructions                       |
| `int16x4_t __riscv_pand_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `and`                                                                                       | RV32 requires 2 instructions                       |
| `uint16x4_t __riscv_pand_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                    | `and`                                                                                       | RV32 requires 2 instructions                       |
| `int32x2_t __riscv_pand_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `and`                                                                                       | RV32 requires 2 instructions                       |
| `uint32x2_t __riscv_pand_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                    | `and`                                                                                       | RV32 requires 2 instructions                       |
| `int8x8_t __riscv_por_i8x8(int8x8_t rs1, int8x8_t rs2);`                            | `or`                                                                                        | RV32 requires 2 instructions                       |
| `uint8x8_t __riscv_por_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                         | `or`                                                                                        | RV32 requires 2 instructions                       |
| `int16x4_t __riscv_por_i16x4(int16x4_t rs1, int16x4_t rs2);`                        | `or`                                                                                        | RV32 requires 2 instructions                       |
| `uint16x4_t __riscv_por_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                     | `or`                                                                                        | RV32 requires 2 instructions                       |
| `int32x2_t __riscv_por_i32x2(int32x2_t rs1, int32x2_t rs2);`                        | `or`                                                                                        | RV32 requires 2 instructions                       |
| `uint32x2_t __riscv_por_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                     | `or`                                                                                        | RV32 requires 2 instructions                       |
| `int8x8_t __riscv_pxor_i8x8(int8x8_t rs1, int8x8_t rs2);`                           | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `uint8x8_t __riscv_pxor_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                        | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `int16x4_t __riscv_pxor_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `uint16x4_t __riscv_pxor_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                    | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `int32x2_t __riscv_pxor_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `uint32x2_t __riscv_pxor_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                    | `xor`                                                                                       | RV32 requires 2 instructions                       |
| `int8x8_t __riscv_pnot_i8x8(int8x8_t rs1);`                                         | `not`                                                                                       | RV32 requires 2 instructions                       |
| `uint8x8_t __riscv_pnot_u8x8(uint8x8_t rs1);`                                       | `not`                                                                                       | RV32 requires 2 instructions                       |
| `int16x4_t __riscv_pnot_i16x4(int16x4_t rs1);`                                      | `not`                                                                                       | RV32 requires 2 instructions                       |
| `uint16x4_t __riscv_pnot_u16x4(uint16x4_t rs1);`                                    | `not`                                                                                       | RV32 requires 2 instructions                       |
| `int32x2_t __riscv_pnot_i32x2(int32x2_t rs1);`                                      | `not`                                                                                       | RV32 requires 2 instructions                       |
| `uint32x2_t __riscv_pnot_u32x2(uint32x2_t rs1);`                                    | `not`                                                                                       | RV32 requires 2 instructions                       |
| `int8x8_t __riscv_pneg_i8x8(int8x8_t rs1);`                                         | `psub.b`(rs1=x0)(RV64), `psub.db`(rs1_p=x0)(RV32)                                           |                                                    |
| `int16x4_t __riscv_pneg_i16x4(int16x4_t rs1);`                                      | `psub.h`(rs1=x0)(RV64), `psub.dh`(rs1_p=x0)(RV32)                                           |                                                    |
| `int32x2_t __riscv_pneg_i32x2(int32x2_t rs1);`                                      | `psub.w`(rs1=x0)(RV64), `psub.dw`(rs1_p=x0)(RV32)                                           |                                                    |

## Packed Intrinsics (RV32 Only)

| Prototype                                                                           | Instruction                  | Notes       |
|-------------------------------------------------------------------------------------|------------------------------|-------------|
| `uint16x4_t __riscv_pwsll_s_u8x4(uint8x4_t rs1, unsigned shamt);`                   | `pwslli.b`, `pwsll.bs`       |             |
| `uint32x2_t __riscv_pwsll_s_u16x2(uint16x2_t rs1, unsigned shamt);`                 | `pwslli.h`, `pwsll.hs`       |             |
| `int16x4_t __riscv_pwsla_s_i8x4(int8x4_t rs1, unsigned shamt);`                     | `pwslai.b`, `pwsla.bs`       |             |
| `int32x2_t __riscv_pwsla_s_i16x2(int16x2_t rs1, unsigned shamt);`                   | `pwslai.h`, `pwsla.hs`       |             |
| `uint8x4_t __riscv_pnsrl_s_u8x4(uint16x4_t rs1, unsigned shamt);`                   | `pnsrli.b`, `pnsrl.bs`       |             |
| `uint16x2_t __riscv_pnsrl_s_u16x2(uint32x2_t rs1, unsigned shamt);`                 | `pnsrli.h`, `pnsrl.hs`       |             |
| `uint8x4_t __riscv_pnclipu_s_u8x4(uint16x4_t rs1, unsigned shamt);`                 | `pnclipiu.b`, `pnclipu.bs`   |             |
| `uint16x2_t __riscv_pnclipu_s_u16x2(uint32x2_t rs1, unsigned shamt);`               | `pnclipiu.h`, `pnclipu.hs`   |             |
| `uint8x4_t __riscv_pnclipru_s_u8x4(uint16x4_t rs1, unsigned shamt);`                | `pnclipriu.b`, `pnclipru.bs` |             |
| `uint16x2_t __riscv_pnclipru_s_u16x2(uint32x2_t rs1, unsigned shamt);`              | `pnclipriu.h`, `pnclipru.hs` |             |
| `int8x4_t __riscv_pnsra_s_i8x4(int16x4_t rs1, unsigned shamt);`                     | `pnsrai.b`, `pnsra.bs`       |             |
| `int16x2_t __riscv_pnsra_s_i16x2(int32x2_t rs1, unsigned shamt);`                   | `pnsrai.h`, `pnsra.hs`       |             |
| `int8x4_t __riscv_pnsrar_s_i8x4(int16x4_t rs1, unsigned shamt);`                    | `pnsrari.b`, `pnsrar.bs`     |             |
| `int16x2_t __riscv_pnsrar_s_i16x2(int32x2_t rs1, unsigned shamt);`                  | `pnsrari.h`, `pnsrar.hs`     |             |
| `int8x4_t __riscv_pnclip_s_u8x4(int16x4_t rs1, unsigned shamt);`                    | `pnclipi.b`, `pnclipu.bs`    |             |
| `int16x2_t __riscv_pnclip_s_u16x2(int32x2_t rs1, unsigned shamt);`                  | `pnclipi.h`, `pnclipu.hs`    |             |
| `int8x4_t __riscv_pnclipr_s_u8x4(int16x4_t rs1, unsigned shamt);`                   | `pnclipri.b`, `pnclipr.bs`   |             |
| `int16x2_t __riscv_pnclipr_s_u16x2(int32x2_t rs1, unsigned shamt);`                 | `pnclipri.h`, `pnclipr.hs`   |             |
| `int64_t __riscv_pm2wadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pm2wadd.h`                  |             |
| `int64_t __riscv_pm2wadda_i16x2(int64_t rd, int16x2_t rs1, int16x2_t rs2);`         | `pm2wadda.h`                 |             |
| `int64_t __riscv_pm2wadd_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `pm2wadd.hx`                 |             |
| `int64_t __riscv_pm2wadda_x_i16x2(int64_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pm2wadda.hx`                |             |
| `uint64_t __riscv_pm2waddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pm2waddu.h`                 |             |
| `uint64_t __riscv_pm2waddau_u16x2(uint64_t rd, uint16x2_t rs1, uint16x2_t rs2);`    | `pm2waddau.h`                |             |
| `int64_t __riscv_pm2wsub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pm2wsub.h`                  |             |
| `int64_t __riscv_pm2wsuba_i16x2(int64_t rd, int16x2_t rs1, int16x2_t rs2);`         | `pm2wsuba.h`                 |             |
| `int64_t __riscv_pm2wsub_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | `pm2wsub.hx`                 |             |
| `int64_t __riscv_pm2wsuba_x_i16x2(int64_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pm2wsuba.hx`                |             |
| `int64_t __riscv_pm2waddsu_u16x2(int16x2_t rs1, uint16x2_t rs2);`                   | `pm2waddsu.h`                |             |
| `int64_t __riscv_pm2waddasu_u16x2(int64_t rd, int16x2_t rs1, uint16x2_t rs2);`      | `pm2waddasu.h`               |             |
| `int16x4_t __riscv_pwadd_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pwadd.b`                    |             |
| `int32x2_t __riscv_pwadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pwadd.h`                    |             |
| `int16x4_t __riscv_pwadda_i8x4(int16x4_t rd, int8x4_t rs1, int8x4_t rs2);`          | `pwadda.b`                   |             |
| `int32x2_t __riscv_pwadda_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pwadda.h`                   |             |
| `uint16x4_t __riscv_pwaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `pwaddu.b`                   |             |
| `uint32x2_t __riscv_pwaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pwaddu.h`                   |             |
| `uint16x4_t __riscv_pwaddau_u8x4(uint16x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`     | `pwaddau.b`                  |             |
| `uint32x2_t __riscv_pwaddau_u16x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | `pwaddau.h`                  |             |
| `int16x4_t __riscv_pwmul_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pwmul.b`                    |             |
| `int32x2_t __riscv_pwmul_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pwmul.h`                    |             |
| `int32x2_t __riscv_pwmacc_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pwmacc.h`                   |             |
| `uint16x4_t __riscv_pwmulu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `pwmulu.b`                   |             |
| `uint32x2_t __riscv_pwmulu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pwmulu.h`                   |             |
| `uint32x2_t __riscv_pwmaccu_u16x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | `pwmaccu.h`                  |             |
| `int16x4_t __riscv_pwsub_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | `pwsub.b`                    |             |
| `int32x2_t __riscv_pwsub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | `pwsub.h`                    |             |
| `int16x4_t __riscv_pwsuba_i8x4(int16x4_t rd, int8x4_t rs1, int8x4_t rs2);`          | `pwsuba.b`                   |             |
| `int32x2_t __riscv_pwsuba_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | `pwsuba.h`                   |             |
| `uint16x4_t __riscv_pwsubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | `pwsubu.b`                   |             |
| `uint32x2_t __riscv_pwsubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | `pwsubu.h`                   |             |
| `uint16x4_t __riscv_pwsubau_u8x4(uint16x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`     | `pwsubau.b`                  |             |
| `uint32x2_t __riscv_pwsubau_u16x2(uint32x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | `pwsubau.h`                  |             |
| `int16x4_t __riscv_pwmulsu_u8x4(int8x4_t rs1, uint8x4_t rs2);`                      | `pwmulsu.b`                  |             |
| `int32x2_t __riscv_pwmulsu_u16x2(int16x2_t rs1, uint16x2_t rs2);`                   | `pwmulsu.h`                  |             |
| `int32x2_t __riscv_pwmaccsu_u16x2(int32x2_t rd, int16x2_t rs1, uint16x2_t rs2);`    | `pwmaccsu.h`                 |             |
| `int32x2_t __riscv_pmqwacc_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | `pmqwacc.h`                  |             |
| `int32x2_t __riscv_pmqrwacc_i16x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`     | `pmqrwacc.h`                 |             |

## Packed Intrinsics (RV64 Only)

* TODO: Many of these could be emulated on RV32 using 2 instructions.

| Prototype                                                                           | Instruction                  | Notes       |
|-------------------------------------------------------------------------------------|------------------------------|-------------|
| `int32_t __riscv_predsum_s_32_i32x2(int32x2_t rs1, int32_t rs2);`                   | `predsum.ws`                 |             |
| `uint32_t __riscv_predsumu_s_32_i32x2(uint32x2_t rs1, uint32_t rs2);`               | `predsumu.ws`                |             |
| `int64_t __riscv_predsum_s_64_i32x2(int32x2_t rs1, int64_t rs2);`                   | `predsum.ws`                 |             |
| `uint64_t __riscv_predsumu_s_64_i32x2(uint32x2_t rs1, uint64_t rs2);`               | `predsumu.ws`                |             |
| `uint32_t __riscv_pabdsumu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                     | `pabdsumu.b`                 |             |
| `uint32_t __riscv_pabdsumau_32_u8x8(uint32_t rd, uint8x8_t rs1, uint8x8_t rs2);`    | `pabdsumau.b`                |             |
| `uint64_t __riscv_pabdsumau_64_u8x8(uint64_t rd, uint8x8_t rs1, uint8x8_t rs2);`    | `pabdsumau.b`                |             |
| `int32x2_t __riscv_pm4add_i8x8(int8x8_t rs1, int8x8_t rs2);`                        | `pm4add.b`                   |             |
| `int32x2_t __riscv_pm2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pm2add.h`                   |             |
| `int32x2_t __riscv_pm4adda_i8x8(int32_t rd, int8x8_t rs1, int8x8_t rs2);`           | `pm4adda.b`                  |             |
| `int32x2_t __riscv_pm2adda_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`        | `pm2adda.h`                  |             |
| `int32x2_t __riscv_pm2add_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pm2add.hx`                  |             |
| `int32x2_t __riscv_pm2adda_x_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pm2adda.hx`                 |             |
| `uint32x2_t __riscv_pm4addu_u8x8(uint8x8_t rs1, uint8x8_t rs2);`                    | `pm4addu.b`                  |             |
| `uint32x2_t __riscv_pm2addu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                 | `pm2addu.h`                  |             |
| `uint32x2_t __riscv_pm4addau_u8x8(uint32_t rd, uint8x8_t rs1, uint8x8_t rs2);`      | `pm4addau.b`                 |             |
| `uint32x2_t __riscv_pm2addau_u16x4(uint32_t rd, uint16x4_t rs1, uint16x4_t rs2);`   | `pm2addau.h`                 |             |
| `int32x2_t __riscv_pmq2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                    | `pmq2add.h`                  |             |
| `int32x2_t __riscv_pmqr2add_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pmqr2add.h`                 |             |
| `int32x2_t __riscv_pmq2adda_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`       | `pmq2adda.h`                 |             |
| `int32x2_t __riscv_pmqr2adda_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pmqr2adda.h`                |             |
| `int32x2_t __riscv_pm2sadd_i16x4(int16x4_t rs1, int16x4_t rs2);`                    | `pm2sadd.h`                  |             |
| `int32x2_t __riscv_pm2sadd_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                  | `pm2sadd.hx`                 |             |
| `int32x2_t __riscv_pm2sub_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pm2sub.h`                   |             |
| `int32x2_t __riscv_pm2suba_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`        | `pm2suba.h`                  |             |
| `int32x2_t __riscv_pm2sub_x_i16x4(int16x4_t rs1, int16x4_t rs2);`                   | `pm2sub.hx`                  |             |
| `int32x2_t __riscv_pm2suba_x_i16x4(int32_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pm2suba.hx`                 |             |
| `int32x2_t __riscv_pm4addsu_i8x8(int8x8_t rs1, uint8x8_t rs2);`                     | `pm4addsu.b`                 |             |
| `int32x2_t __riscv_pm2addsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                  | `pm2addsu.h`                 |             |
| `int32x2_t __riscv_pm4addasu_i8x8(int32_t rd, int8x8_t rs1, uint8x8_t rs2);`        | `pm4addasu.b`                |             |
| `int32x2_t __riscv_pm2addasu_i16x4(int32_t rd, int16x4_t rs1, uint16x4_t rs2);`     | `pm2addasu.h`                |             |
| `int64_t __riscv_pm2add_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pm2add.w`                   |             |
| `int64_t __riscv_pm2adda_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `pm2adda.w`                  |             |
| `int64_t __riscv_pm2add_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pm2add.wx`                  |             |
| `int64_t __riscv_pm2adda_x_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pm2adda.wx`                 |             |
| `uint64_t __riscv_pm2addu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                   | `pm2addu.w`                  |             |
| `uint64_t __riscv_pm2addau_u32x2(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`     | `pm2addau.w`                 |             |
| `int64_t __riscv_pmq2add_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pmq2add.w`                  |             |
| `int64_t __riscv_pmq2adda_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`         | `pmq2adda.w`                 |             |
| `int64_t __riscv_pm2sub_i32x2(int32x2_t rs1, int32x2_t rs2);`                       | `pm2sub.w`                   |             |
| `int64_t __riscv_pm2suba_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`          | `pm2suba.w`                  |             |
| `int64_t __riscv_pm2sub_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pm2sub.wx`                  |             |
| `int64_t __riscv_pm2suba_x_i32x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pm2suba.wx`                 |             |
| `int64_t __riscv_pm2addsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`                    | `pm2addsu.w`                 |             |
| `int64_t __riscv_pm2addasu_i32x2(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`       | `pm2addasu.w`                |             |
| `int64_t __riscv_pmqr2add_i16x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmqr2add.w`                 |             |
| `int64_t __riscv_pmqr2adda_i16x2(int64_t rd, int32x2_t rs1, int32x2_t rs2);`        | `pmqr2adda.w`                |             |
| `int64_t __riscv_pm4add_i16x4(int16x4_t rs1, int16x4_t rs2);`                       | `pm4add.h`                   |             |
| `int64_t __riscv_pm4adda_i16x4(int64_t rd, int16x4_t rs1, int16x4_t rs2);`          | `pm4adda.h`                  |             |
| `uint64_t __riscv_pm4addu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                   | `pm4addu.h`                  |             |
| `uint64_t __riscv_pm4addau_u16x4(uint64_t rd, uint16x4_t rs1, uint16x4_t rs2);`     | `pm4addau.h`                 |             |
| `int64_t __riscv_pm4addsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                    | `pm4addsu.h`                 |             |
| `int64_t __riscv_pm4addasu_i16x4(int64_t rd, int16x4_t rs1, uint16x4_t rs2);`       | `pm4addasu.h`                |             |
| `int32x2_t __riscv_pas_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pas.wx`                     |             |
| `int32x2_t __riscv_psa_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `psa.wx`                     |             |
| `int32x2_t __riscv_psas_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `psas.wx`                    |             |
| `int32x2_t __riscv_pssa_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pssa.wx`                    |             |
| `int32x2_t __riscv_paas_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `paas.wx`                    |             |
| `int32x2_t __riscv_pasa_x_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pasa.wx`                    |             |
| `int16x4_t __riscv_pmulh_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pmulh.h`                    |             |
| `int32x2_t __riscv_pmulh_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pmulh.w`                    |             |
| `int16x4_t __riscv_pmulhr_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmulhr.h`                   |             |
| `int32x2_t __riscv_pmulhr_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmulhr.w`                   |             |
| `int16x4_t __riscv_pmhacc_i16x4(int16x4_t rd, int16x4_t rs1, int16x4_t rs2);`       | `pmhacc.h`                   |             |
| `int32x2_t __riscv_pmhacc_i32x2(int32x2_t rd, int32x2_t rs1, int32x2_t rs2);`       | `pmhacc.w`                   |             |
| `int16x4_t __riscv_pmhracc_i16x4(int16x4_t rd, int16x4_t rs1, int16x4_t rs2);`      | `pmhracc.h`                  |             |
| `int32x2_t __riscv_pmhracc_i32x2(int32x2_t rd, int32x2_t rs1, int32x2_t rs2);`      | `pmhracc.w`                  |             |
| `uint16x4_t __riscv_pmulhu_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                  | `pmulhu.h`                   |             |
| `uint32x2_t __riscv_pmulhu_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                  | `pmulhu.w`                   |             |
| `uint16x4_t __riscv_pmulhru_u16x4(uint16x4_t rs1, uint16x4_t rs2);`                 | `pmulhru.h`                  |             |
| `uint32x2_t __riscv_pmulhru_u32x2(uint32x2_t rs1, uint32x2_t rs2);`                 | `pmulhru.w`                  |             |
| `uint16x4_t __riscv_pmhaccu_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);`  | `pmhaccu.h`                  |             |
| `uint32x2_t __riscv_pmhaccu_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);`  | `pmhaccu.w`                  |             |
| `uint16x4_t __riscv_pmhraccu_u16x4(uint16x4_t rd, uint16x4_t rs1, uint16x4_t rs2);` | `pmhraccu.h`                 |             |
| `uint32x2_t __riscv_pmhraccu_u32x2(uint32x2_t rd, uint32x2_t rs1, uint32x2_t rs2);` | `pmhraccu.w`                 |             |
| `int16x4_t __riscv_pmulhsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                   | `pmulhsu.h`                  |             |
| `int32x2_t __riscv_pmulhsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`                   | `pmulhsu.w`                  |             |
| `int16x4_t __riscv_pmulhrsu_i16x4(int16x4_t rs1, uint16x4_t rs2);`                  | `pmulhrsu.h`                 |             |
| `int32x2_t __riscv_pmulhrsu_i32x2(int32x2_t rs1, uint32x2_t rs2);`                  | `pmulhrsu.w`                 |             |
| `int16x4_t __riscv_pmhaccsu_i16x4(int16x4_t rd, int16x4_t rs1, uint16x4_t rs2);`    | `pmhaccsu.h`                 |             |
| `int32x2_t __riscv_pmhaccsu_i32x2(int32x2_t rd, int32x2_t rs1, uint32x2_t rs2);`    | `pmhaccsu.w`                 |             |
| `int16x4_t __riscv_pmhraccsu_i16x4(int16x4_t rd, int16x4_t rs1, uint16x4_t rs2);`   | `pmhraccsu.h`                |             |
| `int32x2_t __riscv_pmhraccsu_i32x2(int32x2_t rd, int32x2_t rs1, uint32x2_t rs2);`   | `pmhraccsu.w`                |             |
| `int16x4_t __riscv_pmulq_i16x4(int16x4_t rs1, int16x4_t rs2);`                      | `pmulq.h`                    |             |
| `int32x2_t __riscv_pmulq_i32x2(int32x2_t rs1, int32x2_t rs2);`                      | `pmulq.w`                    |             |
| `int16x4_t __riscv_pmulqr_i16x4(int16x4_t rs1, int16x4_t rs2);`                     | `pmulqr.h`                   |             |
| `int32x2_t __riscv_pmulqr_i32x2(int32x2_t rs1, int32x2_t rs2);`                     | `pmulqr.w`                   |             |
| `int16x4_t __riscv_pmul00_i16x4(int8x8_t rs1, int8x8_t rs2);`                       | `pmul.h.b00`                 |             |
| `int16x4_t __riscv_pmul01_i16x4(int8x8_t rs1, int8x8_t rs2);`                       | `pmul.h.b01`                 |             |
| `int16x4_t __riscv_pmul11_i16x4(int8x8_t rs1, int8x8_t rs2);`                       | `pmul.h.b11`                 |             |
| `uint16x4_t __riscv_pmulu00_u16x4(uint8x8_t rs1, uint8x8_t rs2);`                   | `pmulu.h.b00`                |             |
| `uint16x4_t __riscv_pmulu01_u16x4(uint8x8_t rs1, uint8x8_t rs2);`                   | `pmulu.h.b01`                |             |
| `uint16x4_t __riscv_pmulu11_u16x4(uint8x8_t rs1, uint8x8_t rs2);`                   | `pmulu.h.b11`                |             |
| `int16x4_t __riscv_pmulsu00_i16x4(int8x8_t rs1, uint8x8_t rs2);`                    | `pmulsu.h.b00`               |             |
| `int16x4_t __riscv_pmulsu11_i16x4(int8x8_t rs1, uint8x8_t rs2);`                    | `pmulsu.h.b11`               |             |
| `int32x2_t __riscv_pmul00_i32x2(int16x4_t rs1, int8x8_t rs2);`                      | `pmul.w.h00`                 |             |
| `int32x2_t __riscv_pmul01_i32x2(int16x4_t rs1, int8x8_t rs2);`                      | `pmul.w.h01`                 |             |
| `int32x2_t __riscv_pmul11_i32x2(int16x4_t rs1, int8x8_t rs2);`                      | `pmul.w.h11`                 |             |
| `uint32x2_t __riscv_pmulu00_u32x2(uint16x4_t rs1, uint8x8_t rs2);`                  | `pmulu.w.h00`                |             |
| `uint32x2_t __riscv_pmulu01_u32x2(uint16x4_t rs1, uint8x8_t rs2);`                  | `pmulu.w.h01`                |             |
| `uint32x2_t __riscv_pmulu11_u32x2(uint16x4_t rs1, uint8x8_t rs2);`                  | `pmulu.w.h11`                |             |
| `int32x2_t __riscv_pmulsu00_i32x2(int16x4_t rs1, uint8x8_t rs2);`                   | `pmulsu.w.h00`               |             |
| `int32x2_t __riscv_pmulsu11_i32x2(int16x4_t rs1, uint8x8_t rs2);`                   | `pmulsu.w.h11`               |             |
| `int32x2_t __riscv_pmacc00_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`       | `pmacc.w.h00`                |             |
| `int32x2_t __riscv_pmacc01_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`       | `pmacc.w.h01`                |             |
| `int32x2_t __riscv_pmacc11_i32x2(int32x2_t rd, int16x4_t rs1, int8x8_t rs2);`       | `pmacc.w.h11`                |             |
| `uint32x2_t __riscv_pmaccu00_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`     | `pmaccu.w.h00`               |             |
| `uint32x2_t __riscv_pmaccu01_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`     | `pmaccu.w.h01`               |             |
| `uint32x2_t __riscv_pmaccu11_u32x2(uint32x2_t, uint16x4_t rs1, uint8x8_t rs2);`     | `pmaccu.w.h11`               |             |
| `int32x2_t __riscv_pmaccsu00_i32x2(int32x2_t rd, int16x4_t rs1, uint8x8_t rs2);`    | `pmaccsu.w.h00`              |             |
| `int32x2_t __riscv_pmaccsu11_i32x2(int32x2_t rd, int16x4_t rs1, uint8x8_t rs2);`    | `pmaccsu.w.h11`              |             |
| `int32x2_t __riscv_pmqacc00_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`     | `pmqacc.w.h00`               |             |
| `int32x2_t __riscv_pmqacc01_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`     | `pmqacc.w.h01`               |             |
| `int32x2_t __riscv_pmqacc11_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`     | `pmqacc.w.h11`               |             |
| `int32x2_t __riscv_pmqracc00_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`    | `pmqracc.w.h00`              |             |
| `int32x2_t __riscv_pmqracc01_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`    | `pmqracc.w.h01`              |             |
| `int32x2_t __riscv_pmqracc11_i32x2(int32x2_t rd, int16x2_t rs1, int16x2_t rs2);`    | `pmqracc.w.h11`              |             |
| `int64_t __riscv_mqacc00_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`             | `mqacc.w00`                  |             |
| `int64_t __riscv_mqacc01_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`             | `mqacc.w01`                  |             |
| `int64_t __riscv_mqacc11_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`             | `mqacc.w11`                  |             |
| `int64_t __riscv_mqracc00_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`            | `mqracc.w00`                 |             |
| `int64_t __riscv_mqracc01_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`            | `mqracc.w01`                 |             |
| `int64_t __riscv_mqracc11_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`            | `mqracc.w11`                 |             |
| `int16x4_t __riscv_pmulh0_i16x4(int16x4_t rs1, int8x8_t rs2);`                      | `pmulh.h.b0`                 |             |
| `int16x4_t __riscv_pmulh1_i16x4(int16x4_t rs1, int8x8_t rs2);`                      | `pmulh.h.b1`                 |             |
| `int16x4_t __riscv_pmhacc0_i16x4(int16x4_t rd, int16x4_t rs1, int8x8_t rs2);`       | `pmhacc.h.b0`                |             |
| `int16x4_t __riscv_pmhacc1_i16x4(int16x4_t rd, int16x4_t rs1, int8x8_t rs2);`       | `pmhacc.h.b1`                |             |
| `int16x4_t __riscv_pmulhsu0_i16x4(int16x4_t rs1, uint8x8_t rs2);`                   | `pmulhsu.h.b0`               |             |
| `int16x4_t __riscv_pmulhsu1_i16x4(int16x4_t rs1, uint8x8_t rs2);`                   | `pmulhsu.h.b1`               |             |
| `int16x4_t __riscv_pmhaccsu0_i16x4(int16x4_t rd, int16x4_t rs1, uint8x8_t rs2);`    | `pmhaccsu.h.b0`              |             |
| `int16x4_t __riscv_pmhaccsu1_i16x4(int16x4_t rd, int16x4_t rs1, uint8x8_t rs2);`    | `pmhaccsu.h.b1`              |             |
| `int32x2_t __riscv_pmulh0_i32x2(int32x2_t rs1, int16x4_t rs2);`                     | `pmulh.w.h0`                 |             |
| `int32x2_t __riscv_pmulh1_i32x2(int32x2_t rs1, int16x4_t rs2);`                     | `pmulh.w.h1`                 |             |
| `int32x2_t __riscv_pmhacc0_i32x2(int32x2_t rd, int32x2_t rs1, int16x4_t rs2);`      | `pmhacc.w.h0`                |             |
| `int32x2_t __riscv_pmhacc1_i32x2(int32x2_t rd, int32x2_t rs1, int16x4_t rs2);`      | `pmhacc.w.h1`                |             |
| `int32x2_t __riscv_pmulhsu0_i32x2(int32x2_t rs1, uint16x4_t rs2);`                  | `pmulhsu.w.h0`               |             |
| `int32x2_t __riscv_pmulhsu1_i32x2(int32x2_t rs1, uint16x4_t rs2);`                  | `pmulhsu.w.h1`               |             |
| `int32x2_t __riscv_pmhaccsu0_i32x2(int32x2_t rd, int32x2_t rs1, uint16x4_t rs2);`   | `pmhaccsu.w.h0`              |             |
| `int32x2_t __riscv_pmhaccsu1_i32x2(int32x2_t rd, int32x2_t rs1, uint16x4_t rs2);`   | `pmhaccsu.w.h1`              |             |
| `int64_t __riscv_mul00_64(int32x2_t rs1, int32x2_t rs2);`                           | `mul.w00`                    |             |
| `int64_t __riscv_mul01_64(int32x2_t rs1, int32x2_t rs2);`                           | `mul.w01`                    |             |
| `int64_t __riscv_mul11_64(int32x2_t rs1, int32x2_t rs2);`                           | `mul.w11`                    |             |
| `int64_t __riscv_macc00_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`              | `macc.w00`                   |             |
| `int64_t __riscv_macc01_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`              | `macc.w01`                   |             |
| `int64_t __riscv_macc11_64(int64_t rd, int32x2_t rs1, int32x2_t rs2);`              | `macc.w11`                   |             |
| `uint64_t __riscv_mulu00_64(uint32x2_t rs1, uint32x2_t rs2);`                       | `mulu.w00`                   |             |
| `uint64_t __riscv_mulu01_64(uint32x2_t rs1, uint32x2_t rs2);`                       | `mulu.w01`                   |             |
| `uint64_t __riscv_mulu11_64(uint32x2_t rs1, uint32x2_t rs2);`                       | `mulu.w11`                   |             |
| `uint64_t __riscv_maccu00_64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`         | `maccu.w00`                  |             |
| `uint64_t __riscv_maccu01_64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`         | `maccu.w01`                  |             |
| `uint64_t __riscv_maccu11_64(uint64_t rd, uint32x2_t rs1, uint32x2_t rs2);`         | `maccu.w11`                  |             |
| `int64_t __riscv_mulsu00_64(int32x2_t rs1, uint32x2_t rs2);`                        | `mulsu.w00`                  |             |
| `int64_t __riscv_maccsu00_64(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`           | `maccsu.w00`                 |             |
| `int64_t __riscv_mulsu11_64(int32x2_t rs1, uint32x2_t rs2);`                        | `mulsu.w11`                  |             |
| `int64_t __riscv_maccsu11_64(int64_t rd, int32x2_t rs1, uint32x2_t rs2);`           | `maccsu.w11`                 |             |

## Reinterpret casts

### Packed <-> Scalar

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint32_t __riscv_preinterpret_u32_u8x4(uint8x4_t x);`           |
| `uint32_t __riscv_preinterpret_u32_u16x2(uint16x2_t x);`         |
| `uint32_t __riscv_preinterpret_u32_i8x4(int8x4_t x);`            |
| `uint32_t __riscv_preinterpret_u32_i16x2(int16x2_t x);`          |
| `int32_t __riscv_preinterpret_i32_u8x4(uint8x4_t x);`            |
| `int32_t __riscv_preinterpret_i32_u16x2(uint16x2_t x);`          |
| `int32_t __riscv_preinterpret_i32_i8x4(int8x4_t x);`             |
| `int32_t __riscv_preinterpret_i32_i16x2(int16x2_t x);`           |
| `uint8x4_t __riscv_preinterpret_u8x4_u32(uint32_t x);`           |
| `uint16x2_t __riscv_preinterpret_u16x2_u32(uint32_t x);`         |
| `int8x4_t __riscv_preinterpret_i8x4_u32(uint32_t x);`            |
| `int16x2_t __riscv_preinterpret_i16x2_u32(uint32_t x);`          |
| `uint8x4_t __riscv_preinterpret_u8x4_i32(int32_t x);`            |
| `uint16x2_t __riscv_preinterpret_u16x2_i32(int32_t x);`          |
| `int8x4_t __riscv_preinterpret_i8x4_i32(int32_t x);`             |
| `int16x2_t __riscv_preinterpret_i16x2_i32(int32_t x);`           |
| `uint64_t __riscv_preinterpret_u32_u8x8(uint8x8_t x);`           |
| `uint64_t __riscv_preinterpret_u32_u16x4(uint16x4_t x);`         |
| `uint64_t __riscv_preinterpret_u32_u32x2(uint32x2_t x);`         |
| `uint64_t __riscv_preinterpret_u32_i8x8(int8x8_t x);`            |
| `uint64_t __riscv_preinterpret_u32_i16x4(int16x4_t x);`          |
| `uint64_t __riscv_preinterpret_u32_i32x2(int32x2_t x);`          |
| `int64_t __riscv_preinterpret_i32_u8x8(uint8x8_t x);`            |
| `int64_t __riscv_preinterpret_i32_u16x4(uint16x4_t x);`          |
| `int64_t __riscv_preinterpret_i32_u32x2(uint32x2_t x);`          |
| `int64_t __riscv_preinterpret_i32_i8x8(int8x8_t x);`             |
| `int64_t __riscv_preinterpret_i32_i16x4(int16x4_t x);`           |
| `int64_t __riscv_preinterpret_i32_i32x2(int32x2_t x);`           |
| `uint8x8_t __riscv_preinterpret_u8x8_u64(uint64_t x);`           |
| `uint16x4_t __riscv_preinterpret_u16x4_u64(uint64_t x);`         |
| `uint32x2_t __riscv_preinterpret_u64x2_u64(uint64_t x);`         |
| `int8x8_t __riscv_preinterpret_i8x8_u64(uint64_t x);`            |
| `int16x4_t __riscv_preinterpret_i16x4_u64(uint64_t x);`          |
| `int32x2_t __riscv_preinterpret_i32x2_u64(uint64_t x);`          |
| `uint8x8_t __riscv_preinterpret_u8x8_i64(int64_t x);`            |
| `uint16x4_t __riscv_preinterpret_u16x4_i64(int64_t x);`          |
| `uint32x2_t __riscv_preinterpret_u32x2_i64(int64_t x);`          |
| `int8x8_t __riscv_preinterpret_i8x8_i64(int64_t x);`             |
| `int16x4_t __riscv_preinterpret_i16x4_i64(int64_t x);`           |
| `int32x2_t __riscv_preinterpret_i32x2_i64(int64_t x);`           |

### Packed <-> Packed

| Prototype                                                        |
|------------------------------------------------------------------|
| `uint8x4_t __riscv_preinterpet_u8x4_i8x4(int8x4_t x);`           |
| `uint8x4_t __riscv_preinterpet_u8x4_u16x2(uint16x2_t x);`        |
| `uint8x4_t __riscv_preinterpet_u8x4_i16x2(int16x2_t x);`         |
| `int8x4_t __riscv_preinterpet_i8x4_u8x4(uint8x4_t x);`           |
| `int8x4_t __riscv_preinterpet_i8x4_u16x2(uint16x2_t x);`         |
| `int8x4_t __riscv_preinterpet_i8x4_i16x2(int16x2_t x);`          |
| `uint16x2_t __riscv_preinterpet_u16x2_u8x4(uint8x4_t x);`        |
| `uint16x2_t __riscv_preinterpet_u16x2_i8x4(int8x4_t x);`         |
| `uint16x2_t __riscv_preinterpet_u16x2_i16x2(int16x2_t x);`       |
| `int16x2_t __riscv_preinterpet_i16x2_u8x4(uint8x4_t x);`         |
| `int16x2_t __riscv_preinterpet_i16x2_i8x4(int8x4_t x);`          |
| `int16x2_t __riscv_preinterpet_i16x2_u16x2(uint16x2_t x);`       |
| `uint8x8_t __riscv_preinterpet_u8x8_i8x8(int8x8_t x);`           |
| `uint8x8_t __riscv_preinterpet_u8x8_u16x4(uint16x4_t x);`        |
| `uint8x8_t __riscv_preinterpet_u8x8_i16x4(int16x4_t x);`         |
| `uint8x8_t __riscv_preinterpet_u8x8_u16x4(uint16x4_t x);`        |
| `uint8x8_t __riscv_preinterpet_u8x8_i16x4(int16x4_t x);`         |
| `uint8x8_t __riscv_preinterpet_u8x8_u32x2(uint32x2_t x);`        |
| `uint8x8_t __riscv_preinterpet_u8x8_i32x2(int32x2_t x);`         |
| `int8x8_t __riscv_preinterpet_i8x8_u8x8(uint8x8_t x);`           |
| `int8x8_t __riscv_preinterpet_i8x8_u16x4(uint16x4_t x);`         |
| `int8x8_t __riscv_preinterpet_i8x8_i16x4(int16x4_t x);`          |
| `int8x8_t __riscv_preinterpet_i8x8_u32x2(uint32x2_t x);`         |
| `int8x8_t __riscv_preinterpet_i8x8_i32x2(int32x2_t x);`          |
| `uint16x4_t __riscv_preinterpet_u16x4_u8x8(uint8x8_t x);`        |
| `uint16x4_t __riscv_preinterpet_u16x4_i8x8(int8x8_t x);`         |
| `uint16x4_t __riscv_preinterpet_u16x4_i16x4(int16x4_t x);`       |
| `uint16x4_t __riscv_preinterpet_u16x4_u32x2(uint32x2_t x);`      |
| `uint16x4_t __riscv_preinterpet_u16x4_i32x2(int32x2_t x);`       |
| `int16x4_t __riscv_preinterpet_i16x4_u8x8(uint8x8_t x);`         |
| `int16x4_t __riscv_preinterpet_i16x4_i8x8(int8x8_t x);`          |
| `int16x4_t __riscv_preinterpet_i16x4_u16x4(uint16x4_t x);`       |
| `int16x4_t __riscv_preinterpet_i16x4_u32x2(uint32x2_t x);`       |
| `int16x4_t __riscv_preinterpet_i16x4_i32x2(int32x2_t x);`        |
| `uint32x2_t __riscv_preinterpet_u32x2_u8x8(uint8x8_t x);`        |
| `uint32x2_t __riscv_preinterpet_u32x2_i8x8(int8x8_t x);`         |
| `uint32x2_t __riscv_preinterpet_u32x2_u16x4(uint16x4_t x);`      |
| `uint32x2_t __riscv_preinterpet_u32x2_i16x4(int16x4_t x);`       |
| `uint32x2_t __riscv_preinterpet_u32x2_i32x2(int32x2_t x);`       |
| `int32x2_t __riscv_preinterpet_i32x2_u8x8(uint8x8_t x);`         |
| `int32x2_t __riscv_preinterpet_i32x2_i8x8(int8x8_t x);`          |
| `int32x2_t __riscv_preinterpet_i32x2_u16x4(uint16x4_t x);`       |
| `int32x2_t __riscv_preinterpet_i32x2_i16x4(int16x4_t x);`        |
| `int32x2_t __riscv_preinterpet_i32x2_u32x2(uint32x2_t x);`       |

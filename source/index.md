# RISC-V P Extension Intrinsics

This is a draft specification of the RISC-V P extension intrinsics. Based on the ISA specification [ISA specification](https://www.jhauser.us/RISCV/ext-P/).

## Introduction

The RISC-V P Extension C intrinsics provide users interface in the C language level to directly leverage the RISC-V "P" extension.

The intrinsic interface is designed as much as possible to be source code portable between RV32 and RV64. This does necessarily mean it is performance portable. Intrinsics operating
on 32-bit and 64-bit types are provided for both RV32 and RV64.

## Scalar Intrinsics

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
| `uint32_t __riscv_usati_32(uint32_t rs1, const unsigned shamt);`         | `usati`(RV32), `pusati.w`(RV64)       |                                                    |
| `int32_t __riscv_srari_32(int32_t rs1, const unsigned shamt);`           | `srari`(RV32), `psrari.w`(RV64)       |                                                    |
| `int32_t __riscv_sati_32(int32_t rs1, const unsigned shamt);`            | `sati`(RV32), `psati.w`(RV64)         |                                                    |
| `uint32_t __riscv_slx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`      | `slx`(RV32)                           | Emulated for RV64                                  |
| `uint32_t __riscv_srx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`      | `srx`(RV32)                           | Emulated for RV64                                  |
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
* TODO: mul.h00, etc.
* TODO: How to handle VXSAT?

## Scalar Intrinsics (RV32 Only)

| Prototype                                                              | Instruction                 | Notes                          |
|------------------------------------------------------------------------|-----------------------------|--------------------------------|
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

## Scalar Intrinsics (RV64 Only)

| Prototype                                                               | Instruction                 | Notes                          |
|-------------------------------------------------------------------------|-----------------------------|--------------------------------|
| `uint64_t __riscv_abs_64(int64_t rs1);`                                 | `abs`                       |                                |
| `unsigned __riscv_cls_64(int64_t rs1);`                                 | `cls`                       |                                |
| `uint64_t __riscv_rev_64(uint64_t rs1);`                                | `rev`                       |                                |
| `uint64_t __riscv_rev16_64(uint64_t rs1);`                              | `rev16`                     |                                |
| `int64_t __riscv_sha_64(int64_t rs1, int rs2);`                         | `sha`                       |                                |
| `int64_t __riscv_shar_64(int64_t rs1, int rs2);`                        | `shar`                      |                                |
| `uint64_t __riscv_usati_64(uint64_t rs1, const unsigned shamt);`        | `usati`                     |                                |
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

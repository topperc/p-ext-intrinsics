# RISC-V P Extension Intrinsics

This is the draft specification of the RISC-V P extension intrinsics. Based on the ISA specification here https://www.jhauser.us/RISCV/ext-P/

## Introduction

The RISC-V P Extension C intrinsics provide users interface in the C language level to directly leverage the RISC-V "P" extension.

## Scalar Intrinsics

| Prototype                                                                | Instruction                       | Notes                                              |
|-----------------------------------------------------------------------   |-----------------------------------|----------------------------------------------------|
| `uint32_t __riscv_abs_32(int32_t rs1);`                                  | abs[w]                            |                                                    |
| `unsigned __riscv_cls_32(int32_t rs1);`                                  | cls[w]                            |                                                    |
| `uint32_t __riscv_rev_32(uint32_t rs1);`                                 | rev                               | Emulated with rev+srai on RV64                     |
| `int32_t __riscv_sslai_32(int32_t rs1, const unsigned shamt);`           | sslai(RV32), psslai.w(RV64)       |                                                    |
| `int32_t __riscv_ssha_32(int32_t rs1, int rs2);`                         | ssha(RV32), pssha.ws(RV64)        |                                                    |
| `int32_t __riscv_sshar_32(int32_t rs1, int rs2);`                        | sshar(RV32), psshar.ws(RV64)      |                                                    |
| `int32_t __riscv_sadd_32(int32_t rs1, int32_t rs2);`                     | sadd(RV32), psadd.w(RV64)         |                                                    |
| `int32_t __riscv_aadd_32(int32_t rs1, int32_t rs2);`                     | aadd(RV32), paadd.w(RV64)         |                                                    |
| `uint32_t __riscv_saddu_32(uint32_t rs1, uint32_t rs2);`                 | saddu(RV32), psaddu.w(RV64)       |                                                    |
| `uint32_t __riscv_aaddu_32(uint32_t rs1, uint32_t rs2);`                 | aaddu(RV32), paaddu.w(RV64)       |                                                    |
| `int32_t __riscv_ssub_32(int32_t rs1, int32_t rs2);`                     | ssub(RV32), pssub.w(RV64)         |                                                    |
| `int32_t __riscv_asub_32(int32_t rs1, int32_t rs2);`                     | asub(RV32), pasub.w(RV64)         |                                                    |
| `uint32_t __riscv_ssubu_32(uint32_t rs1, uint32_t rs2);`                 | ssubu(RV32), pssubu.w(RV64)       |                                                    |
| `uint32_t __riscv_asubu_32(uint32_t rs1, uint32_t rs2);`                 | asubu(RV32), pasubu.w(RV64)       |                                                    |
| `uint32_t __riscv_usati_32(uint32_t rs1, const unsigned shamt);`         | usati(RV32), pusati.w(RV64)       |                                                    |
| `int32_t __riscv_srari_32(int32_t rs1, const unsigned shamt);`           | srari(RV32), psrari.w(RV64)       |                                                    |
| `int32_t __riscv_sati_32(int32_t rs1, const unsigned shamt);`            | sati(RV32), psati.w(RV64)         |                                                    |
| `uint32_t __riscv_slx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`      | slx(RV32)                         | Emulated for RV64                                  |
| `uint32_t __riscv_srx_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`      | srx(RV32)                         | Emulated for RV64                                  |
| `int32_t __riscv_ssh1sadd_32(int32_t rs1, const unsigned shamt);`        | ssh1sadd(RV32), pssh1sadd.w(RV64) |                                                    |
| `int32_t __riscv_mulhr_32(int32_t rs1, int32_t rs2);`                    | mulhr(RV32), pmulhr.w(RV64)       |                                                    |
| `int32_t __riscv_mhracc_32(int32_t rd, int32_t rs1, int32_t rs2);`       | mhracc(RV32), pmhracc.w(RV64)     |                                                    |
| `uint32_t __riscv_mulhru_32(uint32_t rs1, uint32_t rs2);`                | mulhru(RV32), pmulhru.w(RV64)     |                                                    |
| `uint32_t __riscv_mhraccu_32(uint32_t rd, uint32_t rs1, uint32_t rs2);`  | mhraccu(RV32), pmhraccu.w(RV64)   |                                                    |
| `int32_t __riscv_mulhrsu_32(int32_t rs1, uint32_t rs2);`                 | mulhrsu(RV32), pmulhrsu.w(RV64)   |                                                    |
| `int32_t __riscv_mhraccsu_32(int32_t rd, int32_t rs1, uint32_t rs2);`    | mhraccsu(RV32), pmhraccsu.w(RV64) |                                                    |
| `int32_t __riscv_mulq_32(int32_t rs1, uint32_t rs2);`                    | mulq(RV32), pmulq.w(RV64)         |                                                    |
| `int32_t __riscv_mulqr_32(int32_t rs1, uint32_t rs2);`                   | mulqr(RV32), pmulqr.w(RV64)       |                                                    |

TODO: Do we need intrinsic for MHACC(U)
TODO: Do we need intrinsic for MULHRACC(U)
TODO: Do we need intrinsics for MSEQ/MSLT/MSLTU
TODO: mul.h00, etc.
TODO: How to handle VXSAT?

## Scalar Intrinsics (RV32 Only)

| Prototype                                                              | Instruction                 | Notes                          |
|------------------------------------------------------------------------|-----------------------------|--------------------------------|
| `uint64_t __riscv_wsll_32(uint32_t rs1, uint32_t shamt);`              | wsll[i]                     |                                |
| `int64_t __riscv_wsla_32(int32_t rs1, uint32_t shamt);`                | wsla[i]                     |                                |
| `uint64_t __riscv_wzip8p_32(uint32_t rs1, uint32_t rs2);`              | wzip8p                      |                                |
| `uint64_t __riscv_wzip16p_32(uint32_t rs1, uint32_t rs2);`             | wzip16p                     |                                |
| `int64_t __riscv_wadd_32(int32_t rs1, int32_t rs2);`                   | wadd                        |                                |
| `int64_t __riscv_wadda_32(int32_t rs1, int32_t rs2);`                  | wadda                       |                                |
| `uint64_t __riscv_waddu_32(uint32_t rs1, uint32_t rs2);`               | waddu                       |                                |
| `uint64_t __riscv_waddau_32(uint32_t rs1, uint32_t rs2);`              | waddau                      |                                |
| `int64_t __riscv_wmul_32(int32_t rs1, int32_t rs2);`                   | wmul                        |                                |
| `int64_t __riscv_wmacc_32(int32_t rd, int32_t rs1, int32_t rs2);`      | wmacc                       |                                |
| `int64_t __riscv_wmulu_32(uint32_t rs1, uint32_t rs2);`                | wmulu                       |                                |
| `uint64_t __riscv_wmaccu_32(uint32_t rd, uint32_t rs1, uint32_t rs2);` | wmaccu                      |                                |
| `int64_t __riscv_wsub_32(int32_t rs1, int32_t rs2);`                   | wsub                        |                                |
| `int64_t __riscv_wsuba_32(int32_t rs1, int32_t rs2);`                  | wsuba                       |                                |
| `uint64_t __riscv_wsubu_32(uint32_t rs1, uint32_t rs2);`               | wsubu                       |                                |
| `uint64_t __riscv_wsubau_32(uint32_t rs1, uint32_t rs2);`              | wsubau                      |                                |
| `int64_t __riscv_wmulsu_32(int32_t rs1, uint32_t rs2);`                | wmulsu                      |                                |
| `int64_t __riscv_wmaccsu_32(int32_t rd, int32_t rs1, uint32_t rs2);`   | wmaccsu                     |                                |
| `uint32_t __riscv_nsrl_32(uint64_t rs1_p, uint32_t rs2);`              | nsrl[i]                     |                                |
| `uint32_t __riscv_nclipu_32(uint64_t rs1_p, uint32_t rs2);`            | nclip[i]u                   |                                |
| `uint32_t __riscv_nclipru_32(uint64_t rs1_p, uint32_t rs2);`           | nclipr[i]u                  |                                |
| `int32_t __riscv_nsra_32(int64_t rs1_p, uint32_t rs2);`                | nsra[i]                     |                                |
| `int32_t __riscv_nsrar_32(int64_t rs1_p, uint32_t rs2);`               | nsrar[i]                    |                                |
| `int32_t __riscv_nclip_32(int64_t rs1_p, uint32_t rs2);`               | nclip[i]                    |                                |
| `int32_t __riscv_nclipr_32(int64_t rs1_p, uint32_t rs2);`              | nclipr[i]                   |                                |

TODO: Do we need intrinsics for ADDD or SUBD? Or can compiler figure it out?

## Scalar Intrinsics (RV64 Only)

| Prototype                                                               | Instruction                 | Notes                          |
|-------------------------------------------------------------------------|-----------------------------|--------------------------------|
| `uint64_t __riscv_abs_64(int64_t rs1);`                                 | abs                         |                                |
| `unsigned __riscv_cls_64(int64_t rs1);`                                 | cls                         |                                |
| `uint64_t __riscv_rev_64(uint64_t rs1);`                                | rev                         |                                |
| `uint64_t __riscv_rev16_64(uint64_t rs1);`                              | rev16                       |                                |
| `int64_t __riscv_sha_64(int64_t rs1, int rs2);`                         | sha                         |                                |
| `int64_t __riscv_shar_64(int64_t rs1, int rs2);`                        | shar                        |                                |
| `uint64_t __riscv_usati_64(uint64_t rs1, const unsigned shamt);`        | usati                       |                                |
| `int64_t __riscv_srari_64(int64_t rs1, const unsigned shamt);`          | srari                       |                                |
| `int64_t __riscv_sati_64(int64_t rs1, const unsigned shamt);`           | sati                        |                                |
| `uint64_t __riscv_slx_64(uint64_t rd, uint64_t rs1, uint64_t rs2);`     | slx                         |                                |
| `uint64_t __riscv_srx_64(uint64_t rd, uint64_t rs1, uint64_t rs2);`     | srx                         |                                |
| `uint64_t __riscv_unzip8p_64(uint64_t rs1, uint64_t rs2);`              | unzip8p                     |                                |
| `uint64_t __riscv_unzip16p_64(uint64_t rs1, uint64_t rs2);`             | unzip16p                    |                                |
| `uint64_t __riscv_unzip8hp_64(uint64_t rs1, uint64_t rs2);`             | unzip8hp                    |                                |
| `uint64_t __riscv_unzip16hp_64(uint64_t rs1, uint64_t rs2);`            | unzip16hp                   |                                |
| `uint64_t __riscv_zip8p_64(uint64_t rs1, uint64_t rs2);`                | zip8p                       |                                |
| `uint64_t __riscv_zip16p_64(uint64_t rs1, uint64_t rs2);`               | zip16p                      |                                |
| `uint64_t __riscv_zip8hp_64(uint64_t rs1, uint64_t rs2);`               | zip8hp                      |                                |
| `uint64_t __riscv_zip16hp_64(uint64_t rs1, uint64_t rs2);`              | zip16hp                     |                                |

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
| int32x2_t  | 8            | 8                 | Two signed 16-bit integers     |
| uint32x2_t | 8            | 8                 | Two unsigned 16-bit integers   |

## Packed 32-bit Intrinsics

The intrinsic interface is designed as much as possible to be source code portable between RV32 and RV64. This does necessarily mean it is performance portable. Intrinsics operating
on 32-bit and 64-bit types are provided for both RV32 and RV64.

| Prototype                                                                           | Instruction                           | Notes                                              |
|-------------------------------------------------------------------------------------|---------------------------------------|----------------------------------------------------|
| `uint8x4_t __riscv_psll_s_u8x4(uint8x4_t rs1, unsigned shamt);`                     | pslli.b/psll.bs                       | Compiler will pick immediate form when possible    |
| `int8x4_t __riscv_psll_s_i8x4(int8x4_t rs1, unsigned shamt);`                       | pslli.b/psll.bs                       | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_psll_s_u16x2(uint16x2_t rs1, unsigned shamt);`                  | pslli.h/psll.hs                       | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psll_s_i16x2(int16x2_t rs1, unsigned shamt);`                    | pslli.h/psll.hs                       | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psslai_i16x2(int16x2_t rs1, const unsigned shamt);`              | psslai.h                              |                                                    |
| `int16x2_t __riscv_psext_b_i16x2(int16x2_t rs1);`                                   | psext.h.b                             |                                                    |
| `int8x4_t __riscv_psabs_i8x4(int8x4_t rs1);`                                        | psabs.b                               |                                                    |
| `int16x2_t __riscv_psabs_i16x2(int16x2_t rs1);`                                     | psabs.h                               |                                                    |
| `uint8x4_t __riscv_padd_s_u8x4(uint8x4_t rs1, uint8_t rs2);`                        | padd.bs                               |                                                    |
| `int8x4_t __riscv_padd_s_i8x4(int8x4_t rs1, int8_t rs2);`                           | padd.bs                               |                                                    |
| `uint16x2_t __riscv_padd_s_u16x2(uint16x2_t rs1, uint16_t rs2);`                    | padd.hs                               |                                                    |
| `int16x2_t __riscv_padd_s_i16x2(int16x2_t rs1, int16_t rs2);`                       | padd.hs                               |                                                    |
| `int16x2_t __riscv_ssha_s_i16x2(int16x2_t rs1, int shamt);`                         | pssha.hs                              |                                                    |
| `int16x2_t __riscv_sshar_s_i16x2(int16x2_t rs1, int shamt);`                        | psshar.hs                             |                                                    |
| `uint8x4_t __riscv_psrl_s_u8x4(uint8x4_t rs1, unsigned shamt);`                     | psrli.b/psrl.bs                       | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_psrl_s_u16x2(uint16x2_t rs1, unsigned shamt);`                  | psrli.h/psrl.hs                       | Compiler will pick immediate form when possible    |
| `uint16x2_t __riscv_pusati_u16x2(uint16x2_t rs1, const unsigned shamt);`            | pusati.h                              |                                                    |
| `int8x4_t __riscv_psra_s_i8x4(int8x4_t rs1, unsigned shamt);`                       | psrai.b/psra.bs                       | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psra_s_i16x2(int16x2_t rs1, unsigned shamt);`                    | psrai.h/psra.hs                       | Compiler will pick immediate form when possible    |
| `int16x2_t __riscv_psrari_i16x2(int16x2_t rs1, const unsigned shamt);`              | psrari.h                              |                                                    |
| `int16x2_t __riscv_psati_i16x2(int16x2_t rs1, const unsigned shamt);`               | psati.h                               |                                                    |
| `int32_t __riscv_predsum_s_i8x4(int32_t rs1, int8x4_t rs2);`                        | predsum.bs                            | Accmulator is only 32-bits on RV64                 |
| `uint32_t __riscv_predsumu_s_u8x4(uint32_t rs1, uint8x4_t rs2);`                    | predsumu.bs                           | Accmulator is only 32-bits on RV64                 |
| `int32_t __riscv_predsum_s_i16x2(int32_t rs1, int16x2_t rs2);`                      | predsum.hs                            | Accmulator is only 32-bits on RV64                 |
| `uint32_t __riscv_predsumu_s_i16x2(uint32_t rs1, uint16x2_t rs2);`                  | predsumu.hs                           | Accmulator is only 32-bits on RV64                 |
| `int8x4_t __riscv_padd_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | padd.b                                |                                                    |
| `uint8x4_t __riscv_padd_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | padd.b                                |                                                    |
| `int16x2_t __riscv_padd_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | padd.h                                |                                                    |
| `uint16x2_t __riscv_padd_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | padd.h                                |                                                    |
| `int8x4_t __riscv_psadd_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | psadd.b                               |                                                    |
| `int16x2_t __riscv_psadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | psadd.h                               |                                                    |
| `int8x4_t __riscv_paadd_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | paadd.b                               |                                                    |
| `int16x2_t __riscv_paadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | paadd.h                               |                                                    |
| `uint8x4_t __riscv_psaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | psaddu.b                              |                                                    |
| `uint16x2_t __riscv_psaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | psaddu.h                              |                                                    |
| `uint8x4_t __riscv_paaddu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | paaddu.b                              |                                                    |
| `uint16x2_t __riscv_paaddu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | paaddu.h                              |                                                    |
| `int8x4_t __riscv_psub_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | psub.b                                |                                                    |
| `uint8x4_t __riscv_psub_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                        | psub.b                                |                                                    |
| `int16x2_t __riscv_psub_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | psub.h                                |                                                    |
| `uint16x2_t __riscv_psub_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                    | psub.h                                |                                                    |
| `int8x4_t __riscv_pabd_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | pabd.b                                |                                                    |
| `int16x2_t __riscv_pabd_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | pabd.h                                |                                                    |
| `int8x4_t __riscv_pssub_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | pssub.b                               |                                                    |
| `int16x2_t __riscv_pssub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pssub.h                               |                                                    |
| `int8x4_t __riscv_pasub_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | pasub.b                               |                                                    |
| `int16x2_t __riscv_pasub_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pasub.h                               |                                                    |
| `uint8x4_t __riscv_pabdu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | pabdu.b                               |                                                    |
| `uint16x2_t __riscv_pabdu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | pabdu.h                               |                                                    |
| `uint8x4_t __riscv_pssubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | pssubu.b                              |                                                    |
| `uint16x2_t __riscv_pssubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | pssubu.h                              |                                                    |
| `uint8x4_t __riscv_pasubu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | pasubu.b                              |                                                    |
| `uint16x2_t __riscv_pasubu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | pasubu.h                              |                                                    |
| `uint8x4_t __riscv_merge_u8x4(uint8x4_t rd, uint8x4_t rs1, uint8x4_t rs2);`         | merge, mvm, mvmn                      | Compiler will pick instruction                     |
| `uint16x2_t __riscv_merge_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`    | merge, mvm, mvmn                      | Compiler will pick instruction                     |
| `uint32_t __riscv_pabdsumu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                           | pabdsumu.b                            |                                                    |
| `uint32_t __riscv_pabdsumau_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                          | pabdsumau.b                           |                                                    |
| `int16x2_t __riscv_psh1add_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | psh1add.h                             |                                                    |
| `int16x2_t __riscv_pssh1sadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                  | pssh1sadd.h                           |                                                    |
| `uint8x4_t __riscv_ppaire_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | ppaire.b                              |                                                    |
| `uint8x4_t __riscv_ppaireo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | ppaireo.b                             |                                                    |
| `uint8x4_t __riscv_ppairoe_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                     | ppairoe.b                             |                                                    |
| `uint8x4_t __riscv_ppairo_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | ppairo.b                              |                                                    |
| `uint16x2_t __riscv_ppaire_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | pack(w)                               | Emulated if pack doesn't exist.                    |
| `uint16x2_t __riscv_ppaireo_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | ppaireo.h                             |                                                    |
| `uint16x2_t __riscv_ppairoe_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | ppairoe.h                             |                                                    |
| `uint16x2_t __riscv_ppairo_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | ppairo.h                              |                                                    |
| `int32_t __riscv_pm4add_i8x4(int8x4_t rs1, int8x4_t rs2);`                          | pm4add.b                              |                                                    |
| `int32_t __riscv_pm2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | pm2add.h                              |                                                    |
| `int32_t __riscv_pm4adda_i8x4(int32_t rd, int8x4_t rs1, int8x4_t rs2);`             | pm4adda.b                             |                                                    |
| `int32_t __riscv_pm2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | pm2adda.h                             |                                                    |
| `int32_t __riscv_pm2add_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pm2add.hx                             |                                                    |
| `int32_t __riscv_pm2adda_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | pm2adda.hx                            |                                                    |
| `uint32_t __riscv_pm4addu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | pm4addu.b                             |                                                    |
| `uint32_t __riscv_pm2addu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | pm2addu.h                             |                                                    |
| `uint32_t __riscv_pm4addau_u8x4(uint32_t rd, uint8x4_t rs1, uint8x4_t rs2);`        | pm4addau.b                            |                                                    |
| `uint32_t __riscv_pm2addau_u16x2(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`     | pm2addau.h                            |                                                    |
| `int32_t __riscv_pmq2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pmq2add.h                             |                                                    |
| `int32_t __riscv_pmqr2add_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pmqr2add.h                            |                                                    |
| `int32_t __riscv_pmq2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`         | pmq2adda.h                            |                                                    |
| `int32_t __riscv_pmqr2adda_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | pmqr2adda.h                           |                                                    |
| `int32_t __riscv_pm2sadd_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pm2sadd.h                             |                                                    |
| `int32_t __riscv_pm2sadd_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                    | pm2sadd.hx                            |                                                    |
| `int32_t __riscv_pm2sub_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | pm2sub.h                              |                                                    |
| `int32_t __riscv_pm2suba_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`          | pm2suba.h                             |                                                    |
| `int32_t __riscv_pm2sub_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pm2sub.hx                             |                                                    |
| `int32_t __riscv_pm2suba_x_i16x2(int32_t rd, int16x2_t rs1, int16x2_t rs2);`        | pm2suba.hx                            |                                                    |
| `int32_t __riscv_pm4addsu_i8x4(int8x4_t rs1, uint8x4_t rs2);`                       | pm4addsu.b                            |                                                    |
| `int32_t __riscv_pm2addsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                    | pm2addsu.h                            |                                                    |
| `int32_t __riscv_pm4addasu_i8x4(int32_t rd, int8x4_t rs1, uint8x4_t rs2);`          | pm4addasu.b                           |                                                    |
| `int32_t __riscv_pm2addasu_i16x2(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`       | pm2addasu.h                           |                                                    |
| `int16x2_t __riscv_pas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pas.hx                                |                                                    |
| `int16x2_t __riscv_psa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | psa.hx                                |                                                    |
| `int16x2_t __riscv_psas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | psas.hx                               |                                                    |
| `int16x2_t __riscv_pssa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pssa.hx                               |                                                    |
| `int16x2_t __riscv_paas_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | paas.hx                               |                                                    |
| `int16x2_t __riscv_pasa_x_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pasa.hx                               |                                                    |
| `uint8x4_t __riscv_pmseq_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | pmseq.b                               |                                                    |
| `uint8x4_t __riscv_pmseq_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | pmseq.b                               |                                                    |
| `uint16x2_t __riscv_pmseq_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pmseq.h                               |                                                    |
| `uint16x2_t __riscv_pmseq_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | pmseq.h                               |                                                    |
| `uint8x4_t __riscv_pmslt_i8x4(int8x4_t rs1, int8x4_t rs2);`                         | pmslt.b                               |                                                    |
| `uint16x2_t __riscv_pmslt_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pmslt.h                               |                                                    |
| `uint8x4_t __riscv_pmsltu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                      | pmsltu.b                              |                                                    |
| `uint16x2_t __riscv_pmsltu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | pmsltu.h                              |                                                    |
| `int8x4_t __riscv_pmin_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | pmin.b                                |                                                    |
| `int16x2_t __riscv_pmin_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | pmin.h                                |                                                    |
| `uint8x4_t __riscv_pminu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | pminu.b                               |                                                    |
| `uint16x2_t __riscv_pminu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | pminu.h                               |                                                    |
| `int8x4_t __riscv_pmax_i8x4(int8x4_t rs1, int8x4_t rs2);`                           | pmax.b                                |                                                    |
| `int16x2_t __riscv_pmax_i16x2(int16x2_t rs1, int16x2_t rs2);`                       | pmax.h                                |                                                    |
| `uint8x4_t __riscv_pmaxu_u8x4(uint8x4_t rs1, uint8x4_t rs2);`                       | pmaxu.b                               |                                                    |
| `uint16x2_t __riscv_pmaxu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                   | pmaxu.h                               |                                                    |
| `int16x2_t __riscv_pmulh_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pmulh.h                               |                                                    |
| `int16x2_t __riscv_pmulhr_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pmulhr.h                              |                                                    |
| `int16x2_t __riscv_pmhacc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`       | pmhacc.h                              |                                                    |
| `int16x2_t __riscv_pmhracc_i16x2(int16x2_t rd, int16x2_t rs1, int16x2_t rs2);`      | pmhracc.h                             |                                                    |
| `uint16x2_t __riscv_pmulhu_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                  | pmulhu.h                              |                                                    |
| `uint16x2_t __riscv_pmulhru_u16x2(uint16x2_t rs1, uint16x2_t rs2);`                 | pmulhru.h                             |                                                    |
| `uint16x2_t __riscv_pmhaccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);`  | pmhaccu.h                             |                                                    |
| `uint16x2_t __riscv_pmhraccu_u16x2(uint16x2_t rd, uint16x2_t rs1, uint16x2_t rs2);` | pmhraccu.h                            |                                                    |
| `int16x2_t __riscv_pmulhsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                   | pmulhsu.h                             |                                                    |
| `int16x2_t __riscv_pmulhrsu_i16x2(int16x2_t rs1, uint16x2_t rs2);`                  | pmulhrsu.h                            |                                                    |
| `int16x2_t __riscv_pmhaccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`    | pmhaccsu.h                            |                                                    |
| `int16x2_t __riscv_pmhraccsu_i16x2(int16x2_t rd, int16x2_t rs1, uint16x2_t rs2);`   | pmhraccsu.h                           |                                                    |
| `int16x2_t __riscv_pmulq_i16x2(int16x2_t rs1, int16x2_t rs2);`                      | pmulq.h                               |                                                    |
| `int16x2_t __riscv_pmulqr_i16x2(int16x2_t rs1, int16x2_t rs2);`                     | pmulqr.h                              |                                                    |
| `int16x2_t __riscv_pmul00_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | pmul.h.b00                            |                                                    |
| `int16x2_t __riscv_pmul01_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | pmul.h.b01                            |                                                    |
| `int16x2_t __riscv_pmul11_i16x2(int8x4_t rs1, int8x4_t rs2);`                       | pmul.h.b11                            |                                                    |
| `uint16x2_t __riscv_pmulu00_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | pmulu.h.b00                           |                                                    |
| `uint16x2_t __riscv_pmulu01_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | pmulu.h.b01                           |                                                    |
| `uint16x2_t __riscv_pmulu11_u16x2(uint8x4_t rs1, uint8x4_t rs2);`                   | pmulu.h.b11                           |                                                    |
| `int16x2_t __riscv_pmulsu00_i16x2(int8x4_t rs1, uint8x4_t rs2);`                    | pmulsu.h.b00                          |                                                    |
| `int16x2_t __riscv_pmulsu11_i16x2(int8x4_t rs1, uint8x4_t rs2);`                    | pmulsu.h.b11                          |                                                    |
| `int32_t __riscv_mul00_32(int16x2_t rs1, int16x2_t rs2);`                           | mul.h00(RV32), pmul.w.h00(RV64)       |                                                    |
| `int32_t __riscv_mul01_32(int16x2_t rs1, int16x2_t rs2);`                           | mul.h01(RV32), pmul.w.h01(RV64)       |                                                    |
| `int32_t __riscv_mul11_32(int16x2_t rs1, int16x2_t rs2);`                           | mul.h11(RV32), pmul.w.h11(RV64)       |                                                    |
| `int32_t __riscv_macc00_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | macc.h00(RV32), pmacc.w.h00(RV64)     |                                                    |
| `int32_t __riscv_macc01_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | macc.h01(RV32), pmacc.w.h01(RV64)     |                                                    |
| `int32_t __riscv_macc11_32(int32_t rd, int16x2_t rs1, int16x2_t rs2);`              | macc.h11(RV32), pmacc.w.h11(RV64)     |                                                    |
| `uint32_t __riscv_mulu00_32(uint16x2_t rs1, uint16x2_t rs2);`                       | mulu.h00(RV32), pmulu.w.h00(RV64)     |                                                    |
| `uint32_t __riscv_mulu01_32(uint16x2_t rs1, uint16x2_t rs2);`                       | mulu.h01(RV32), pmulu.w.h01(RV64)     |                                                    |
| `uint32_t __riscv_mulu11_32(uint16x2_t rs1, uint16x2_t rs2);`                       | mulu.h11(RV32), pmulu.w.h11(RV64)     |                                                    |
| `uint32_t __riscv_maccu00_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | maccu.h00(RV32), pmaccu.w.h00(RV64)   |                                                    |
| `uint32_t __riscv_maccu01_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | maccu.h01(RV32), pmaccu.w.h01(RV64)   |                                                    |
| `uint32_t __riscv_maccu11_32(uint32_t rd, uint16x2_t rs1, uint16x2_t rs2);`         | maccu.h11(RV32), pmaccu.w.h11(RV64)   |                                                    |
| `int32_t __riscv_mulsu00_32(int16x2_t rs1, uint16x2_t rs2);`                        | mulsu.h00(RV32), pmulsu.w.h00(RV64)   |                                                    |
| `int32_t __riscv_maccsu00_32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`           | maccsu.h00(RV32), pmaccsu.w.h00(RV64) |                                                    |
| `int32_t __riscv_mulsu11_32(int16x2_t rs1, uint16x2_t rs2);`                        | mulsu.h11(RV32), pmulsu.w.h11(RV64)   |                                                    |
| `int32_t __riscv_maccsu11_32(int32_t rd, int16x2_t rs1, uint16x2_t rs2);`           | maccsu.h11(RV32), pmaccsu.w.h11(RV64) |                                                    |
| `int32_t __riscv_mqacc00_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`             | mqacc.h00(RV32), pmqacc.w.h00(RV64)   |                                                    |
| `int32_t __riscv_mqacc01_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`             | mqacc.h01(RV32), pmqacc.w.h01(RV64)   |                                                    |
| `int32_t __riscv_mqacc11_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`             | mqacc.h11(RV32), pmqacc.w.h11(RV64)   |                                                    |
| `int32_t __riscv_mqracc00_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`            | mqracc.h00(RV32), pmqracc.w.h00(RV64) |                                                    |
| `int32_t __riscv_mqracc01_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`            | mqracc.h01(RV32), pmqracc.w.h01(RV64) |                                                    |
| `int32_t __riscv_mqracc11_32(int32_t rd, int16x2_t rs2, int16x2_t rs2);`            | mqracc.h11(RV32), pmqracc.w.h11(RV64) |                                                    |
| `int16x2_t __riscv_pmulh0_i16x2(int16x2_t rs1, int8x4_t rs2);`                      | pmulh.h.b0                            |                                                    |
| `int16x2_t __riscv_pmulh1_i16x2(int16x2_t rs1, int8x4_t rs2);`                      | pmulh.h.b1                            |                                                    |
| `int16x2_t __riscv_pmhacc0_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`       | pmhacc.h.b0                           |                                                    |
| `int16x2_t __riscv_pmhacc1_i16x2(int16x2_t rd, int16x2_t rs1, int8x4_t rs2);`       | pmhacc.h.b1                           |                                                    |
| `int16x2_t __riscv_pmulhsu0_i16x2(int16x2_t rs1, uint8x4_t rs2);`                   | pmulhsu.h.b0                          |                                                    |
| `int16x2_t __riscv_pmulhsu1_i16x2(int16x2_t rs1, uint8x4_t rs2);`                   | pmulhsu.h.b1                          |                                                    |
| `int16x2_t __riscv_pmhaccsu0_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`    | pmhaccsu.h.b0                         |                                                    |
| `int16x2_t __riscv_pmhaccsu1_i16x2(int16x2_t rd, int16x2_t rs1, uint8x4_t rs2);`    | pmhaccsu.h.b1                         |                                                    |
| `int32_t __riscv_mulh0_32(int32_t rs1, int16x2_t rs2);`                             | mulh.h0(RV32), pmulh.w.h0(RV64)       |                                                    |
| `int32_t __riscv_mulh1_32(int32_t rs1, int16x2_t rs2);`                             | mulh.h1(RV32), pmulh.w.h1(RV64)       |                                                    |
| `int32_t __riscv_mhacc0_32(int32_t rd, int32_t rs1, int16x2_t rs2);`                | mhacc.h0(RV32), pmhacc.w.h0(RV64)     |                                                    |
| `int32_t __riscv_mhacc1_32(int32_t rd, int32_t rs1, int16x2_t rs2);`                | mhacc.h1(RV32), pmhacc.w.h1(RV64)     |                                                    |
| `int32_t __riscv_mulhsu0_32(int32_t rs1, uint16x2_t rs2);`                          | mulhsu.h0(RV32), pmulhsu.w.h0(RV64)   |                                                    |
| `int32_t __riscv_mulhsu1_32(int32_t rs1, uint16x2_t rs2);`                          | mulhsu.h1(RV32), pmulhsu.w.h1(RV64)   |                                                    |
| `int32_t __riscv_mhaccsu0_32(int32_t rd, int32_t rs1, uint16x2_t rs2);`             | mhaccsu.h0(RV32), pmhaccsu.w.h0(RV64) |                                                    |
| `int32_t __riscv_mhaccsu1_32(int32_t rd, int32_t rs1, uint16x2_t rs2);`             | mhaccsu.h1(RV32), pmhaccsu.w.h1(RV64) |                                                    |

// NOTE: padd, psub, pmeq is provided in signed and unsigned version to avoid casts.
// TODO: should we provide signed `merge`
// TODO: pli.b, pli.h, pli.w, plui.h, plui.w
// TODO: Packed intrinsics for (un)zip(8|16)8(h)p?
// TODO: `__riscv_pm2add_x_i16x2` or `__riscv_pm2addx_i16x2`

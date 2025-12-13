# RISC-V P Extension Intrinsics

This is the draft specification of the RISC-V P extension intrinsics. Based on the ISA specification here https://www.jhauser.us/RISCV/ext-P/

## Introduction

The RISC-V P Extension C intrinsics provide users interface in the C language level to directly leverage the RISC-V "P" extension".

The intrinsic interface is designed as much as possible to be source code portable between RV32 and RV64. This does necessarily mean it is performance portable. Intrinsics operating
on 32-bit and 64-bit types are provided for both RV32 and RV64.

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

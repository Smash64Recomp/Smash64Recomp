#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sc1PTrainingModeInitMenuOptionSpriteAttrs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ECA4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018ECA8: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018ECAC: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x8018ECB0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    // 0x8018ECB4: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8018ECB8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018ECBC: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    // 0x8018ECC0: sh          $a1, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r5;
    // 0x8018ECC4: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x8018ECC8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018ECCC: sh          $a1, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r5;
    // 0x8018ECD0: lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X30);
    // 0x8018ECD4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8018ECD8: sh          $a1, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r5;
L_8018ECDC:
    // 0x8018ECDC: lw          $t2, 0x30($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X30);
    // 0x8018ECE0: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8018ECE4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8018ECE8: sh          $a1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r5;
    // 0x8018ECEC: lw          $t5, 0x30($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X30);
    // 0x8018ECF0: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8018ECF4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018ECF8: sh          $a1, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r5;
    // 0x8018ECFC: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x8018ED00: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8018ED04: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8018ED08: sh          $a1, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r5;
    // 0x8018ED0C: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8018ED10: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8018ED14: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8018ED18: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8018ED1C: bne         $v1, $v0, L_8018ECDC
    if (ctx->r3 != ctx->r2) {
        // 0x8018ED20: sh          $a1, 0x14($t3)
        MEM_H(0X14, ctx->r11) = ctx->r5;
            goto L_8018ECDC;
    }
    // 0x8018ED20: sh          $a1, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r5;
    // 0x8018ED24: jr          $ra
    // 0x8018ED28: nop

    return;
    // 0x8018ED28: nop

;}
RECOMP_FUNC void func_80010918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010918: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8001091C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80010920: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80010924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010928: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8001092C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010930: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80010934: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010938: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001093C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80010940: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80010944: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010948: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001094C: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80010950: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80010954: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80010958: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8001095C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010960: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80010964: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80010968: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8001096C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80010970: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x80010974: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80010978: jal         0x80033510
    // 0x8001097C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001097C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80010980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010984: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80010988: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001098C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010990: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80010994: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80010998: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8001099C: nop

    // 0x800109A0: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800109A4: nop

    // 0x800109A8: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800109AC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800109B0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800109B4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800109B8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800109BC: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800109C0: jal         0x80033510
    // 0x800109C4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800109C4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x800109C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800109CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800109D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800109D4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800109D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800109DC: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800109E0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800109E4: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800109E8: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800109EC: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800109F0: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x800109F4: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x800109F8: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x800109FC: bc1t        L_80010A64
    if (c1cs) {
        // 0x80010A00: swc1        $f6, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
            goto L_80010A64;
    }
    // 0x80010A00: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80010A04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80010A0C: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x80010A10: neg.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = -ctx->f18.fl;
    // 0x80010A14: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80010A18: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80010A1C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80010A20: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80010A24: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80010A28: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80010A2C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80010A30: nop

    // 0x80010A34: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80010A38: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80010A3C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80010A40: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80010A44: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80010A48: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80010A4C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80010A50: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80010A54: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80010A58: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80010A5C: b           L_80010A90
    // 0x80010A60: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
        goto L_80010A90;
    // 0x80010A60: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
L_80010A64:
    // 0x80010A64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010A68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010A6C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80010A70: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80010A74: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80010A78: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80010A7C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80010A80: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80010A84: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80010A88: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80010A8C: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
L_80010A90:
    // 0x80010A90: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80010A94: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80010A98: beql        $t7, $zero, L_80010AC0
    if (ctx->r15 == 0) {
        // 0x80010A9C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80010AC0;
    }
    goto skip_0;
    // 0x80010A9C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80010AA0: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010AA4: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x80010AA8: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80010AAC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80010AB0: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80010AB4: b           L_80010AD0
    // 0x80010AB8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
        goto L_80010AD0;
    // 0x80010AB8: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80010ABC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80010AC0:
    // 0x80010AC0: nop

    // 0x80010AC4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x80010AC8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x80010ACC: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
L_80010AD0:
    // 0x80010AD0: jal         0x80019EA0
    // 0x80010AD4: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_2;
    // 0x80010AD4: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_2:
    // 0x80010AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010ADC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80010AE0: jr          $ra
    // 0x80010AE4: nop

    return;
    // 0x80010AE4: nop

;}
RECOMP_FUNC void ftCommonCaptureKirbyUpdatePositionsMag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014B704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014B70C: jal         0x80018F7C
    // 0x8014B710: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    syVectorMag3D(rdram, ctx);
        goto after_0;
    // 0x8014B710: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8014B714: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8014B718: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8014B71C: nop

    // 0x8014B720: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8014B724: nop

    // 0x8014B728: bc1fl       L_8014B768
    if (!c1cs) {
        // 0x8014B72C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B768;
    }
    goto skip_0;
    // 0x8014B72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014B730: div.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8014B734: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014B738: lwc1        $f4, -0x3DE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3DE0);
    // 0x8014B73C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8014B740: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014B744: lwc1        $f6, -0x3DDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3DDC);
    // 0x8014B748: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8014B74C: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x8014B750: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8014B754: add.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8014B758: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8014B75C: swc1        $f2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f2.u32l;
    // 0x8014B760: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    // 0x8014B764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014B768:
    // 0x8014B768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014B76C: jr          $ra
    // 0x8014B770: nop

    return;
    // 0x8014B770: nop

;}
RECOMP_FUNC void ftYoshiSpecialNReleaseInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E8C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E8CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015E8D0: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8015E8D4: jal         0x800E8098
    // 0x8015E8D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015E8D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015E8DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E8E0: sw          $zero, 0x184($a0)
    MEM_W(0X184, ctx->r4) = 0;
    // 0x8015E8E4: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    // 0x8015E8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E8EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E8F0: jr          $ra
    // 0x8015E8F4: nop

    return;
    // 0x8015E8F4: nop

;}
RECOMP_FUNC void mnScreenAdjustFrameProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131B28: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131B2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131B34: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80131B38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131B3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131B40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131B48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B4C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80131B50: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80131B54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131B58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B60: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131B64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B68: lui         $t8, 0xBFA4
    ctx->r24 = S32(0XBFA4 << 16);
    // 0x80131B6C: ori         $t8, $t8, 0x47FF
    ctx->r24 = ctx->r24 | 0X47FF;
    // 0x80131B70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131B74: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131B78: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80131B7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131B80: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131B84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B88: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80131B8C: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80131B90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131B94: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131B98: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80131B9C: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80131BA0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131BA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131BA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BAC: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80131BB0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80131BB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131BB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131BBC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80131BC0: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80131BC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131BC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131BCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BD0: lui         $t9, 0x27
    ctx->r25 = S32(0X27 << 16);
    // 0x80131BD4: lui         $t8, 0xF628
    ctx->r24 = S32(0XF628 << 16);
    // 0x80131BD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131BDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131BE0: ori         $t8, $t8, 0x43F8
    ctx->r24 = ctx->r24 | 0X43F8;
    // 0x80131BE4: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80131BE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131BEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131BF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BF4: lui         $t7, 0xF653
    ctx->r15 = S32(0XF653 << 16);
    // 0x80131BF8: ori         $t7, $t7, 0x81E4
    ctx->r15 = ctx->r15 | 0X81E4;
    // 0x80131BFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131C00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131C04: addiu       $t8, $zero, 0x1DC
    ctx->r24 = ADD32(0, 0X1DC);
    // 0x80131C08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131C0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131C10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C14: lui         $t7, 0x8B8B
    ctx->r15 = S32(0X8B8B << 16);
    // 0x80131C18: ori         $t7, $t7, 0x8BFF
    ctx->r15 = ctx->r15 | 0X8BFF;
    // 0x80131C1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131C20: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131C24: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80131C28: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131C2C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131C30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C34: lui         $t6, 0xB
    ctx->r14 = S32(0XB << 16);
    // 0x80131C38: lui         $t9, 0xF645
    ctx->r25 = S32(0XF645 << 16);
    // 0x80131C3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131C40: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131C44: ori         $t9, $t9, 0xB4
    ctx->r25 = ctx->r25 | 0XB4;
    // 0x80131C48: ori         $t6, $t6, 0xB0
    ctx->r14 = ctx->r14 | 0XB0;
    // 0x80131C4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131C50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131C54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C58: lui         $t9, 0xB
    ctx->r25 = S32(0XB << 16);
    // 0x80131C5C: lui         $t8, 0xF645
    ctx->r24 = S32(0XF645 << 16);
    // 0x80131C60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131C64: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131C68: ori         $t8, $t8, 0x314
    ctx->r24 = ctx->r24 | 0X314;
    // 0x80131C6C: ori         $t9, $t9, 0x310
    ctx->r25 = ctx->r25 | 0X310;
    // 0x80131C70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131C74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131C78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C7C: lui         $t8, 0xB
    ctx->r24 = S32(0XB << 16);
    // 0x80131C80: lui         $t7, 0xF60B
    ctx->r15 = S32(0XF60B << 16);
    // 0x80131C84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131C88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131C8C: ori         $t7, $t7, 0x4310
    ctx->r15 = ctx->r15 | 0X4310;
    // 0x80131C90: ori         $t8, $t8, 0xB0
    ctx->r24 = ctx->r24 | 0XB0;
    // 0x80131C94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131C98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131C9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CA0: lui         $t7, 0x45
    ctx->r15 = S32(0X45 << 16);
    // 0x80131CA4: lui         $t6, 0xF645
    ctx->r14 = S32(0XF645 << 16);
    // 0x80131CA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131CAC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131CB0: ori         $t6, $t6, 0x4310
    ctx->r14 = ctx->r14 | 0X4310;
    // 0x80131CB4: ori         $t7, $t7, 0xB0
    ctx->r15 = ctx->r15 | 0XB0;
    // 0x80131CB8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131CBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131CC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CC4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80131CC8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80131CCC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131CD0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131CD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131CD8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131CDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CE0: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80131CE4: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80131CE8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131CEC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131CF0: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80131CF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131CF8: jr          $ra
    // 0x80131CFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    return;
    // 0x80131CFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void mnPlayersVSBackToVSMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801380F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801380F8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801380FC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80138100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138108: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8013810C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80138110: jal         0x8013A664
    // 0x80138114: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    mnPlayersVSSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80138114: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_0:
    // 0x80138118: jal         0x8013A8B8
    // 0x8013811C: nop

    mnPlayersVSPauseSlotProcesses(rdram, ctx);
        goto after_1;
    // 0x8013811C: nop

    after_1:
    // 0x80138120: jal         0x80020A74
    // 0x80138124: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x80138124: nop

    after_2:
    // 0x80138128: jal         0x80005C74
    // 0x8013812C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x8013812C: nop

    after_3:
    // 0x80138130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80138134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138138: jr          $ra
    // 0x8013813C: nop

    return;
    // 0x8013813C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPuckAdjustProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136450: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80136454: lw          $t6, 0x7678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7678);
    // 0x80136458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013645C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136460: beq         $t6, $zero, L_80136474
    if (ctx->r14 == 0) {
        // 0x80136464: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80136474;
    }
    // 0x80136464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136468: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013646C: jal         0x8013637C
    // 0x80136470: lw          $a0, 0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76F8);
    mnPlayers1PBonusPuckAdjustRecall(rdram, ctx);
        goto after_0;
    // 0x80136470: lw          $a0, 0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76F8);
    after_0:
L_80136474:
    // 0x80136474: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80136478: lw          $t7, 0x7674($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7674);
    // 0x8013647C: beql        $t7, $zero, L_80136490
    if (ctx->r15 == 0) {
        // 0x80136480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136490;
    }
    goto skip_0;
    // 0x80136480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80136484: jal         0x8013635C
    // 0x80136488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnPlayers1PBonusPuckAdjustPlaced(rdram, ctx);
        goto after_1;
    // 0x80136488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8013648C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136490:
    // 0x80136490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136494: jr          $ra
    // 0x80136498: nop

    return;
    // 0x80136498: nop

;}
RECOMP_FUNC void ftCommonHammerFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147C50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147C54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80147C58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80147C5C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80147C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80147C64: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80147C68: lw          $t8, 0x14C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14C);
    // 0x80147C6C: bne         $t8, $zero, L_80147C7C
    if (ctx->r24 != 0) {
        // 0x80147C70: nop
    
            goto L_80147C7C;
    }
    // 0x80147C70: nop

    // 0x80147C74: jal         0x800DEEC8
    // 0x80147C78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80147C78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
L_80147C7C:
    // 0x80147C7C: jal         0x800F3828
    // 0x80147C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_1;
    // 0x80147C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80147C84: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80147C88: jal         0x800F385C
    // 0x80147C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_2;
    // 0x80147C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80147C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147C94: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80147C98: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80147C9C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147CA0: jal         0x800E6F24
    // 0x80147CA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x80147CA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80147CA8: jal         0x800F388C
    // 0x80147CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_4;
    // 0x80147CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80147CB0: jal         0x800D8EB8
    // 0x80147CB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_5;
    // 0x80147CB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80147CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80147CBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80147CC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80147CC4: jr          $ra
    // 0x80147CC8: nop

    return;
    // 0x80147CC8: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FB24: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FB28: jal         0x800DE6E4
    // 0x8015FB2C: addiu       $a1, $a1, -0x5D4
    ctx->r5 = ADD32(ctx->r5, -0X5D4);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015FB2C: addiu       $a1, $a1, -0x5D4
    ctx->r5 = ADD32(ctx->r5, -0X5D4);
    after_0:
    // 0x8015FB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FB34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FB38: jr          $ra
    // 0x8015FB3C: nop

    return;
    // 0x8015FB3C: nop

;}
RECOMP_FUNC void grPupupuFlowersFrontLoopEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106220: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106224: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80106228: lbu         $t6, 0x28($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X28);
    // 0x8010622C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106234: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80106238: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8010623C: bne         $t8, $zero, L_80106278
    if (ctx->r24 != 0) {
        // 0x80106240: sb          $t7, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r15;
            goto L_80106278;
    }
    // 0x80106240: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80106244: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x80106248: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8010624C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80106250: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x80106254: sb          $t9, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r25;
    // 0x80106258: sb          $t0, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r8;
    // 0x8010625C: beq         $v1, $zero, L_80106280
    if (ctx->r3 == 0) {
        // 0x80106260: sb          $t1, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r9;
            goto L_80106280;
    }
    // 0x80106260: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80106264: lhu         $a0, 0xB8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XB8);
    // 0x80106268: jal         0x800D39D4
    // 0x8010626C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleEjectStructID(rdram, ctx);
        goto after_0;
    // 0x8010626C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80106270: b           L_80106284
    // 0x80106274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106284;
    // 0x80106274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106278:
    // 0x80106278: jal         0x8010595C
    // 0x8010627C: nop

    grPupupuWhispySetWindPush(rdram, ctx);
        goto after_1;
    // 0x8010627C: nop

    after_1:
L_80106280:
    // 0x80106280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106284:
    // 0x80106284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106288: jr          $ra
    // 0x8010628C: nop

    return;
    // 0x8010628C: nop

;}
RECOMP_FUNC void mvOpeningRoomTransitionOverlayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B58: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133B5C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133B60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133B6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133B70: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133B74: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80133B78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133B7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133B80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B84: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80133B88: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80133B8C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133B90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133B94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133B98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133B9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133BA0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80133BA4: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80133BA8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80133BAC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80133BB0: lw          $t4, 0x6678($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6678);
    // 0x80133BB4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80133BB8: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80133BBC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80133BC0: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80133BC4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80133BC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133BCC: lw          $t8, 0x6670($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6670);
    // 0x80133BD0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133BD4: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80133BD8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133BDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133BE0: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80133BE4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80133BE8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133BEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133BF0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80133BF4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80133BF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133BFC: ori         $t7, $t7, 0xFCFE
    ctx->r15 = ctx->r15 | 0XFCFE;
    // 0x80133C00: lui         $t3, 0xF0A
    ctx->r11 = S32(0XF0A << 16);
    // 0x80133C04: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80133C08: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80133C0C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133C10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133C14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C18: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80133C1C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80133C20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133C24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133C28: ori         $t3, $t3, 0x4000
    ctx->r11 = ctx->r11 | 0X4000;
    // 0x80133C2C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80133C30: jal         0x80013E68
    // 0x80133C34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    gcDrawDObjDLHead0(rdram, ctx);
        goto after_0;
    // 0x80133C34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80133C38: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133C3C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133C40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C44: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80133C48: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80133C4C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80133C50: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80133C54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133C58: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80133C5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C60: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80133C64: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80133C68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133C6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133C70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133C74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133C78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C7C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80133C80: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80133C84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133C88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133C8C: lw          $t9, 0x6674($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6674);
    // 0x80133C90: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x80133C94: andi        $t3, $t9, 0x3
    ctx->r11 = ctx->r25 & 0X3;
    // 0x80133C98: sll         $t4, $t3, 19
    ctx->r12 = S32(ctx->r11 << 19);
    // 0x80133C9C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80133CA0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80133CA4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80133CA8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80133CAC: lui         $t3, 0xF00
    ctx->r11 = S32(0XF00 << 16);
    // 0x80133CB0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80133CB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133CB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133CBC: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80133CC0: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80133CC4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80133CC8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80133CCC: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80133CD0: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80133CD4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133CD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133CE4: jr          $ra
    // 0x80133CE8: nop

    return;
    // 0x80133CE8: nop

;}
RECOMP_FUNC void func_ovl29_80133F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F54: jr          $ra
    // 0x80133F58: nop

    return;
    // 0x80133F58: nop

;}
RECOMP_FUNC void func_80010748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010748: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8001074C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80010750: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80010754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010758: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8001075C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010760: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80010764: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010768: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001076C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80010770: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80010774: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010778: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001077C: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80010780: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80010784: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80010788: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8001078C: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010790: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80010794: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80010798: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8001079C: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800107A0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800107A4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800107A8: jal         0x80033510
    // 0x800107AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800107AC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800107B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800107B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800107B8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800107BC: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800107C0: div.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800107C4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800107C8: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800107CC: nop

    // 0x800107D0: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800107D4: nop

    // 0x800107D8: mul.s       $f18, $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800107DC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800107E0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800107E4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800107E8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800107EC: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800107F0: jal         0x80033510
    // 0x800107F4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800107F4: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x800107F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800107FC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80010800: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010804: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80010808: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001080C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80010810: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010814: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010818: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001081C: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x80010820: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x80010824: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x80010828: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x8001082C: bc1t        L_80010894
    if (c1cs) {
        // 0x80010830: swc1        $f6, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
            goto L_80010894;
    }
    // 0x80010830: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80010834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010838: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001083C: neg.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = -ctx->f16.fl;
    // 0x80010840: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80010844: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80010848: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8001084C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x80010850: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80010854: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80010858: nop

    // 0x8001085C: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80010860: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80010864: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80010868: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001086C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80010870: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80010874: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80010878: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001087C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80010880: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80010884: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80010888: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8001088C: b           L_800108C0
    // 0x80010890: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
        goto L_800108C0;
    // 0x80010890: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
L_80010894:
    // 0x80010894: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80010898: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001089C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800108A0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800108A4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800108A8: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800108AC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800108B0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800108B4: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800108B8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800108BC: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
L_800108C0:
    // 0x800108C0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800108C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800108C8: beql        $t7, $zero, L_800108F0
    if (ctx->r15 == 0) {
        // 0x800108CC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_800108F0;
    }
    goto skip_0;
    // 0x800108CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x800108D0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800108D4: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800108D8: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800108DC: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x800108E0: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800108E4: b           L_80010900
    // 0x800108E8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
        goto L_80010900;
    // 0x800108E8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800108EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800108F0:
    // 0x800108F0: nop

    // 0x800108F4: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800108F8: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x800108FC: swc1        $f2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f2.u32l;
L_80010900:
    // 0x80010900: jal         0x80019EA0
    // 0x80010904: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_2;
    // 0x80010904: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_2:
    // 0x80010908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001090C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80010910: jr          $ra
    // 0x80010914: nop

    return;
    // 0x80010914: nop

;}
RECOMP_FUNC void ftCommonCliffCommonProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144B54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80144B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144B5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144B60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144B64: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80144B68: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80144B6C: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x80144B70: lw          $a2, 0x8EC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8EC);
    // 0x80144B74: bnel        $t6, $at, L_80144BA8
    if (ctx->r14 != ctx->r1) {
        // 0x80144B78: lw          $a0, 0x140($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X140);
            goto L_80144BA8;
    }
    goto skip_0;
    // 0x80144B78: lw          $a0, 0x140($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X140);
    skip_0:
    // 0x80144B7C: lw          $a0, 0x140($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X140);
    // 0x80144B80: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80144B84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80144B88: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80144B8C: jal         0x800F4428
    // 0x80144B90: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x80144B90: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80144B94: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80144B98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80144B9C: b           L_80144BC4
    // 0x80144BA0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
        goto L_80144BC4;
    // 0x80144BA0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80144BA4: lw          $a0, 0x140($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X140);
L_80144BA8:
    // 0x80144BA8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80144BAC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80144BB0: jal         0x800F4408
    // 0x80144BB4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x80144BB4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80144BB8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80144BBC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80144BC0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_80144BC4:
    // 0x80144BC4: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x80144BC8: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80144BCC: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80144BD0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80144BD4: nop

    // 0x80144BD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80144BDC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80144BE0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80144BE4: nop

    // 0x80144BE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80144BEC: lwc1        $f10, 0x44($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80144BF0: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80144BF4: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80144BF8: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80144BFC: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80144C00: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80144C04: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80144C08: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x80144C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144C10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80144C14: jr          $ra
    // 0x80144C18: nop

    return;
    // 0x80144C18: nop

;}
RECOMP_FUNC void efManagerYoshiEggLaySetAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102F98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102F9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80102FA0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80102FA4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80102FA8: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x80102FAC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80102FB0: lw          $t1, 0x1000($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1000);
    // 0x80102FB4: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80102FB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80102FBC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80102FC0: lw          $t0, -0x1A2C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1A2C);
    // 0x80102FC4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80102FC8: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    // 0x80102FCC: jal         0x800C8758
    // 0x80102FD0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonAddDObjAnimJointAll(rdram, ctx);
        goto after_0;
    // 0x80102FD0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x80102FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102FDC: jr          $ra
    // 0x80102FE0: nop

    return;
    // 0x80102FE0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSetPortraitWallpaperPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321CC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801321D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801321D4: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801321D8: addiu       $t6, $t6, 0x7120
    ctx->r14 = ADD32(ctx->r14, 0X7120);
    // 0x801321DC: addiu       $t0, $t6, 0x60
    ctx->r8 = ADD32(ctx->r14, 0X60);
    // 0x801321E0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801321E4:
    // 0x801321E4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801321E8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801321EC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801321F0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801321F4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801321F8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801321FC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132200: bne         $t6, $t0, L_801321E4
    if (ctx->r14 != ctx->r8) {
        // 0x80132204: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801321E4;
    }
    // 0x80132204: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132208: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x8013220C: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80132210: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80132214: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80132218: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8013221C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80132220: jr          $ra
    // 0x80132224: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80132224: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnVSRecordMakeBattleScoreTableHeaders(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134618: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013461C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134624: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80134628: jal         0x80009968
    // 0x8013462C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013462C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134630: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134634: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134638: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013463C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134640: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134648: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013464C: jal         0x80009DF4
    // 0x80134650: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134650: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134654: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134658: lw          $t7, 0x6D88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D88);
    // 0x8013465C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80134660: addiu       $t8, $t8, 0x258
    ctx->r24 = ADD32(ctx->r24, 0X258);
    // 0x80134664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134668: jal         0x800CCFDC
    // 0x8013466C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013466C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80134670: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80134674: lui         $at, 0x4384
    ctx->r1 = S32(0X4384 << 16);
    // 0x80134678: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013467C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80134680: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80134684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134688: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013468C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80134690: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x80134694: addiu       $t4, $zero, 0x88
    ctx->r12 = ADD32(0, 0X88);
    // 0x80134698: addiu       $t5, $zero, 0x92
    ctx->r13 = ADD32(0, 0X92);
    // 0x8013469C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801346A0: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x801346A4: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x801346A8: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x801346AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801346B0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801346B4: jal         0x8013388C
    // 0x801346B8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    mnVSRecordMakeRowIcons(rdram, ctx);
        goto after_3;
    // 0x801346B8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x801346BC: jal         0x801335FC
    // 0x801346C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSRecordMakeColumnIcons(rdram, ctx);
        goto after_4;
    // 0x801346C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801346C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801346C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801346CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801346D0: jr          $ra
    // 0x801346D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801346D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80385AAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385AAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80385AB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80385AB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80385AB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385ABC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80385AC0: bne         $a0, $zero, L_80385AD8
    if (ctx->r4 != 0) {
        // 0x80385AC4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80385AD8;
    }
    // 0x80385AC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80385AC8: jal         0x803717A0
    // 0x80385ACC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385ACC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x80385AD0: beq         $v0, $zero, L_80385B60
    if (ctx->r2 == 0) {
        // 0x80385AD4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385B60;
    }
    // 0x80385AD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80385AD8:
    // 0x80385AD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80385ADC: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80385AE0: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x80385AE4: bnel        $t6, $zero, L_80385B08
    if (ctx->r14 != 0) {
        // 0x80385AE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80385B08;
    }
    goto skip_0;
    // 0x80385AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80385AEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80385AF0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80385AF4: jal         0x803717E0
    // 0x80385AF8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80385AF8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80385AFC: jal         0x8037C2D0
    // 0x80385B00: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80385B00: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80385B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80385B08:
    // 0x80385B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80385B0C: jal         0x8037C710
    // 0x80385B10: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C710(rdram, ctx);
        goto after_3;
    // 0x80385B10: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80385B14: jal         0x80381130
    // 0x80385B18: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    func_ovl8_80381130(rdram, ctx);
        goto after_4;
    // 0x80385B18: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    after_4:
    // 0x80385B1C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80385B20: addiu       $t7, $t7, -0x2140
    ctx->r15 = ADD32(ctx->r15, -0X2140);
    // 0x80385B24: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80385B28: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80385B2C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80385B30: addiu       $t8, $t8, -0x2060
    ctx->r24 = ADD32(ctx->r24, -0X2060);
    // 0x80385B34: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80385B38: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80385B3C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80385B40: addiu       $t0, $t0, -0x1F08
    ctx->r8 = ADD32(ctx->r8, -0X1F08);
    // 0x80385B44: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80385B48: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80385B4C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x80385B50: addiu       $t3, $t3, -0x1E78
    ctx->r11 = ADD32(ctx->r11, -0X1E78);
    // 0x80385B54: addiu       $t2, $t2, -0x1EE0
    ctx->r10 = ADD32(ctx->r10, -0X1EE0);
    // 0x80385B58: sw          $t2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r10;
    // 0x80385B5C: sw          $t3, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r11;
L_80385B60:
    // 0x80385B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80385B64: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80385B68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80385B6C: jr          $ra
    // 0x80385B70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80385B70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuBoundSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155114: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80155118: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015511C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80155120: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80155124: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80155128: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8015512C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80155130: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80155134: jal         0x800C7B08
    // 0x80155138: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    lbCommonReflect2D(rdram, ctx);
        goto after_0;
    // 0x80155138: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015513C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155140: jal         0x800C7AE0
    // 0x80155144: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    lbCommonScale2D(rdram, ctx);
        goto after_1;
    // 0x80155144: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x80155148: jal         0x800C7A84
    // 0x8015514C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    lbCommonMag2D(rdram, ctx);
        goto after_2;
    // 0x8015514C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80155150: jal         0x800D8EB8
    // 0x80155154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_3;
    // 0x80155154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80155158: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015515C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80155160: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80155164: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80155168: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8015516C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80155170: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80155174: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80155178: bc1fl       L_8015518C
    if (!c1cs) {
        // 0x8015517C: sw          $t8, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r24;
            goto L_8015518C;
    }
    goto skip_0;
    // 0x8015517C: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    skip_0:
    // 0x80155180: b           L_8015518C
    // 0x80155184: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
        goto L_8015518C;
    // 0x80155184: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x80155188: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
L_8015518C:
    // 0x8015518C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80155190: jal         0x800E6F24
    // 0x80155194: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x80155194: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80155198: jal         0x800E0830
    // 0x8015519C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_5;
    // 0x8015519C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x801551A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x801551A4: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801551A8: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801551AC: jal         0x8001863C
    // 0x801551B0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_6;
    // 0x801551B0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_6:
    // 0x801551B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801551B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801551BC: jal         0x800FFD58
    // 0x801551C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    efManagerImpactWaveMakeEffect(rdram, ctx);
        goto after_7;
    // 0x801551C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x801551C4: jal         0x801008F4
    // 0x801551C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_8;
    // 0x801551C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x801551CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801551D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801551D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801551D8: jr          $ra
    // 0x801551DC: nop

    return;
    // 0x801551DC: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015354C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153550: jal         0x800DEE98
    // 0x80153554: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80153554: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80153558: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015355C: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80153560: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80153564: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153568: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015356C: jal         0x800E6F24
    // 0x80153570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015357C: jr          $ra
    // 0x80153580: nop

    return;
    // 0x80153580: nop

;}
RECOMP_FUNC void itIwarkWeaponRockProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DCCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017DCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DCD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017DCD8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017DCDC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8017DCE0: jal         0x80168088
    // 0x8017DCE4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    wpMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017DCE4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_0:
    // 0x8017DCE8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017DCEC: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017DCF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DCF4: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x8017DCF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DCFC: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8017DD00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017DD04: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x8017DD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017DD10: jr          $ra
    // 0x8017DD14: nop

    return;
    // 0x8017DD14: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckFighterCrossed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132148: jr          $ra
    // 0x8013214C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013214C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032940: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80032944: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80032948: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8003294C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80032950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80032954: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80032958: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003295C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80032960: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80032964:
    // 0x80032964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80032968: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8003296C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80032970: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80032974: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80032978: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8003297C: beq         $a0, $t3, L_800329E4
    if (ctx->r4 == ctx->r11) {
        // 0x80032980: nop
    
            goto L_800329E4;
    }
    // 0x80032980: nop

L_80032984:
    // 0x80032984: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80032988: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003298C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80032990: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80032994: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80032998: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8003299C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800329A0: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800329A4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800329A8: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800329AC: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800329B0: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800329B4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800329B8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800329BC: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800329C0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800329C4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800329C8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800329CC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800329D0: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800329D4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800329D8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800329DC: bne         $a0, $t3, L_80032984
    if (ctx->r4 != ctx->r11) {
        // 0x800329E0: nop
    
            goto L_80032984;
    }
    // 0x800329E0: nop

L_800329E4:
    // 0x800329E4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800329E8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800329EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800329F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800329F4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800329F8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800329FC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80032A00: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80032A04: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80032A08: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80032A0C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80032A10: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80032A14: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80032A18: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80032A1C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80032A20: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80032A24: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80032A28: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80032A2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80032A30: bne         $a2, $t4, L_80032964
    if (ctx->r6 != ctx->r12) {
        // 0x80032A34: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80032964;
    }
    // 0x80032A34: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80032A38: jr          $ra
    // 0x80032A3C: nop

    return;
    // 0x80032A3C: nop

;}
RECOMP_FUNC void mvOpeningMarioFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD9C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDA0: addiu       $v0, $v0, -0x1DF8
    ctx->r2 = ADD32(ctx->r2, -0X1DF8);
    // 0x8018DDA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DDB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DDB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDBC: jal         0x8039076C
    // 0x8018DDC0: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDC0: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDC4: beq         $v0, $zero, L_8018DDE4
    if (ctx->r2 == 0) {
        // 0x8018DDC8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DDE4;
    }
    // 0x8018DDC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDCC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDD0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDD4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDD8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DDDC: jal         0x80005C74
    // 0x8018DDE0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DDE0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DDE4:
    // 0x8018DDE4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDE8: lw          $v0, -0x1DF8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DF8);
    // 0x8018DDEC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DDF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDF4: bnel        $v0, $at, L_8018DE28
    if (ctx->r2 != ctx->r1) {
        // 0x8018DDF8: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE28;
    }
    goto skip_0;
    // 0x8018DDF8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DDFC: jal         0x80009A84
    // 0x8018DE00: lw          $a0, -0x1DF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DF4);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DE00: lw          $a0, -0x1DF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DF4);
    after_2:
    // 0x8018DE04: jal         0x8018D614
    // 0x8018DE08: nop

    mvOpeningMarioMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE08: nop

    after_3:
    // 0x8018DE0C: jal         0x8018D944
    // 0x8018DE10: nop

    mvOpeningMarioMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE10: nop

    after_4:
    // 0x8018DE14: jal         0x8018DA60
    // 0x8018DE18: nop

    mvOpeningMarioMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE18: nop

    after_5:
    // 0x8018DE1C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE20: lw          $v0, -0x1DF8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DF8);
    // 0x8018DE24: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE28:
    // 0x8018DE28: bne         $v0, $at, L_8018DE48
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE2C: addiu       $t1, $zero, 0x1F
        ctx->r9 = ADD32(0, 0X1F);
            goto L_8018DE48;
    }
    // 0x8018DE2C: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x8018DE30: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE34: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE38: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE3C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE40: jal         0x80005C74
    // 0x8018DE44: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE44: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE48:
    // 0x8018DE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE50: jr          $ra
    // 0x8018DE54: nop

    return;
    // 0x8018DE54: nop

;}
RECOMP_FUNC void lbTransitionSetupTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4404: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D4408: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D440C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D4410: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D4414: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800D4418: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800D441C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D4420: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D4424: addiu       $s2, $s2, 0x5E10
    ctx->r18 = ADD32(ctx->r18, 0X5E10);
    // 0x800D4428: addiu       $s0, $s0, 0x5D60
    ctx->r16 = ADD32(ctx->r16, 0X5D60);
L_800D442C:
    // 0x800D442C: jal         0x800CDBD0
    // 0x800D4430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x800D4430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800D4434: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800D4438: beq         $at, $zero, L_800D4444
    if (ctx->r1 == 0) {
        // 0x800D443C: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800D4444;
    }
    // 0x800D443C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800D4440: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800D4444:
    // 0x800D4444: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800D4448: bne         $at, $zero, L_800D442C
    if (ctx->r1 != 0) {
        // 0x800D444C: nop
    
            goto L_800D442C;
    }
    // 0x800D444C: nop

    // 0x800D4450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D4454: jal         0x80004980
    // 0x800D4458: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x800D4458: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800D445C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D4460: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x800D4464: sw          $v0, 0x6484($at)
    MEM_W(0X6484, ctx->r1) = ctx->r2;
    // 0x800D4468: ori         $a0, $a0, 0x3A0
    ctx->r4 = ctx->r4 | 0X3A0;
    // 0x800D446C: jal         0x80004980
    // 0x800D4470: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x800D4470: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x800D4474: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D4478: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x800D447C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800D4480: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800D4484: lw          $v1, 0x4FA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4FA8);
    // 0x800D4488: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800D448C: ori         $at, $at, 0x3F14
    ctx->r1 = ctx->r1 | 0X3F14;
    // 0x800D4490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D4494: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x800D4498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D449C: addiu       $a3, $zero, 0xDC
    ctx->r7 = ADD32(0, 0XDC);
    // 0x800D44A0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800D44A4:
    // 0x800D44A4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D44A8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D44AC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800D44B0: sw          $t6, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r14;
    // 0x800D44B4: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800D44B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800D44BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800D44C0: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
L_800D44C4:
    // 0x800D44C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800D44C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D44CC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800D44D0: sw          $t8, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->r24;
    // 0x800D44D4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800D44D8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D44DC: sw          $t9, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->r25;
    // 0x800D44E0: lw          $t0, -0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, -0X8);
    // 0x800D44E4: sw          $t0, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->r8;
    // 0x800D44E8: lw          $t1, -0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, -0X4);
    // 0x800D44EC: bne         $v0, $a1, L_800D44C4
    if (ctx->r2 != ctx->r5) {
        // 0x800D44F0: sw          $t1, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r9;
            goto L_800D44C4;
    }
    // 0x800D44F0: sw          $t1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r9;
    // 0x800D44F4: bne         $a2, $a3, L_800D44A4
    if (ctx->r6 != ctx->r7) {
        // 0x800D44F8: addiu       $v1, $v1, -0x4D8
        ctx->r3 = ADD32(ctx->r3, -0X4D8);
            goto L_800D44A4;
    }
    // 0x800D44F8: addiu       $v1, $v1, -0x4D8
    ctx->r3 = ADD32(ctx->r3, -0X4D8);
    // 0x800D44FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D4500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4504: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4508: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D450C: jr          $ra
    // 0x800D4510: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D4510: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80371DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DFC: jr          $ra
    // 0x80371E00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371E00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mnVSRecordMakeLockedIcon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801335A4: lw          $t6, 0x6D88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D88);
    // 0x801335A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801335AC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801335B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801335B4: addiu       $t7, $t7, 0x70
    ctx->r15 = ADD32(ctx->r15, 0X70);
    // 0x801335B8: jal         0x800CCFDC
    // 0x801335BC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x801335BC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x801335C0: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801335C4: addiu       $t2, $zero, 0x8A
    ctx->r10 = ADD32(0, 0X8A);
    // 0x801335C8: addiu       $t3, $zero, 0x88
    ctx->r11 = ADD32(0, 0X88);
    // 0x801335CC: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801335D0: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801335D4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801335D8: addiu       $t4, $zero, 0x92
    ctx->r12 = ADD32(0, 0X92);
    // 0x801335DC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801335E0: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801335E4: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801335E8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x801335EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801335F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801335F4: jr          $ra
    // 0x801335F8: nop

    return;
    // 0x801335F8: nop

;}
RECOMP_FUNC void itEggExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181B98: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181B9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80181BA0: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80181BA4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80181BA8: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x80181BAC: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80181BB0: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80181BB4: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80181BB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80181BBC: jal         0x801005C8
    // 0x80181BC0: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80181BC0: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_0:
    // 0x80181BC4: beq         $v0, $zero, L_80181BF0
    if (ctx->r2 == 0) {
        // 0x80181BC8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80181BF0;
    }
    // 0x80181BC8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80181BCC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80181BD0: lwc1        $f4, -0x314C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X314C);
    // 0x80181BD4: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x80181BD8: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80181BDC: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80181BE0: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80181BE4: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80181BE8: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x80181BEC: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_80181BF0:
    // 0x80181BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80181BF4: jal         0x801008F4
    // 0x80181BF8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80181BF8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80181BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80181C00: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80181C04: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80181C08: jal         0x80181B5C
    // 0x80181C0C: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    itEggExplodeSetStatus(rdram, ctx);
        goto after_2;
    // 0x80181C0C: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    after_2:
    // 0x80181C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181C18: jr          $ra
    // 0x80181C1C: nop

    return;
    // 0x80181C1C: nop

;}
RECOMP_FUNC void ftNessSpecialHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153E0C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153E10: jal         0x800D9480
    // 0x80153E14: addiu       $a1, $a1, 0x435C
    ctx->r5 = ADD32(ctx->r5, 0X435C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80153E14: addiu       $a1, $a1, 0x435C
    ctx->r5 = ADD32(ctx->r5, 0X435C);
    after_0:
    // 0x80153E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153E20: jr          $ra
    // 0x80153E24: nop

    return;
    // 0x80153E24: nop

;}
RECOMP_FUNC void ftDonkeySpecialNLoopSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B2CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B2D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B2D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B2D8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B2DC: jal         0x800DEEC8
    // 0x8015B2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015B2E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B2E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B2E8: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x8015B2EC: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015B2F0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B2F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B2F8: jal         0x800E6F24
    // 0x8015B2FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B2FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B300: jal         0x8015B244
    // 0x8015B304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x8015B304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015B308: jal         0x800D8EB8
    // 0x8015B30C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_3;
    // 0x8015B30C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8015B310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B318: jr          $ra
    // 0x8015B31C: nop

    return;
    // 0x8015B31C: nop

;}
RECOMP_FUNC void mnVSRecordPortraitArrowsProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132A54: lw          $t6, 0x6C18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C18);
    // 0x80132A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132A5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132A60: bnel        $t6, $at, L_80132A74
    if (ctx->r14 != ctx->r1) {
        // 0x80132A64: sw          $t7, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r15;
            goto L_80132A74;
    }
    goto skip_0;
    // 0x80132A64: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    skip_0:
    // 0x80132A68: jr          $ra
    // 0x80132A6C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80132A6C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80132A70: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
L_80132A74:
    // 0x80132A74: jr          $ra
    // 0x80132A78: nop

    return;
    // 0x80132A78: nop

;}
RECOMP_FUNC void gcRemoveDObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B710: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B714: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000B718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B71C: bne         $a0, $zero, L_8000B72C
    if (ctx->r4 != 0) {
        // 0x8000B720: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000B72C;
    }
    // 0x8000B720: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B724: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000B728: lw          $s1, 0x6A54($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X6A54);
L_8000B72C:
    // 0x8000B72C: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x8000B730: beql        $s0, $zero, L_8000B750
    if (ctx->r16 == 0) {
        // 0x8000B734: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B750;
    }
    goto skip_0;
    // 0x8000B734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000B738:
    // 0x8000B738: jal         0x8000948C
    // 0x8000B73C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectDObj(rdram, ctx);
        goto after_0;
    // 0x8000B73C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000B740: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x8000B744: bne         $s0, $zero, L_8000B738
    if (ctx->r16 != 0) {
        // 0x8000B748: nop
    
            goto L_8000B738;
    }
    // 0x8000B748: nop

    // 0x8000B74C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000B750:
    // 0x8000B750: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B754: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B758: jr          $ra
    // 0x8000B75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000B75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamResumeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9CB0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800E9CB4: lbu         $t6, 0x10($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X10);
    // 0x800E9CB8: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800E9CBC: jr          $ra
    // 0x800E9CC0: sb          $t7, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r15;
    return;
    // 0x800E9CC0: sb          $t7, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void efManagerThunderAmpMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010140C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80101410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80101414: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010141C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80101420: jal         0x800CE9E8
    // 0x80101424: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80101424: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    after_0:
    // 0x80101428: beq         $v0, $zero, L_80101490
    if (ctx->r2 == 0) {
        // 0x8010142C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80101490;
    }
    // 0x8010142C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80101430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101434: jal         0x800CE1DC
    // 0x80101438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80101438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8010143C: beq         $v0, $zero, L_80101484
    if (ctx->r2 == 0) {
        // 0x80101440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80101484;
    }
    // 0x80101440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101444: jal         0x800CEA14
    // 0x80101448: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80101448: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010144C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80101450: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80101454: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80101458: bnel        $t6, $zero, L_8010146C
    if (ctx->r14 != 0) {
        // 0x8010145C: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_8010146C;
    }
    goto skip_0;
    // 0x8010145C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80101460: b           L_80101494
    // 0x80101464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101494;
    // 0x80101464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101468: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_8010146C:
    // 0x8010146C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80101470: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80101474: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80101478: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8010147C: b           L_80101490
    // 0x80101480: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80101490;
    // 0x80101480: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80101484:
    // 0x80101484: jal         0x800CEA40
    // 0x80101488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80101488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010148C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80101490:
    // 0x80101490: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80101494:
    // 0x80101494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80101498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010149C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801014A0: jr          $ra
    // 0x801014A4: nop

    return;
    // 0x801014A4: nop

;}
RECOMP_FUNC void gmCollisionGetWeaponAttacksPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0C94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0C9C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0CA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0CA4: jal         0x800F08C8
    // 0x800F0CA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0CA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0CAC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0CB0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0CB4: jal         0x800F08C8
    // 0x800F0CB8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0CB8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F0CBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0CC0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0CC4: jal         0x800F0A48
    // 0x800F0CC8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0CC8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0CD4: jr          $ra
    // 0x800F0CD8: nop

    return;
    // 0x800F0CD8: nop

;}
RECOMP_FUNC void ftCommonAttack100LoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F388: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014F38C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014F390: lhu         $v1, 0x1B4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014F394: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014F398: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8014F39C: bnel        $t7, $zero, L_8014F3B8
    if (ctx->r15 != 0) {
        // 0x8014F3A0: sw          $t0, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->r8;
            goto L_8014F3B8;
    }
    goto skip_0;
    // 0x8014F3A0: sw          $t0, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r8;
    skip_0:
    // 0x8014F3A4: lhu         $t8, 0x1C0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1C0);
    // 0x8014F3A8: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8014F3AC: beq         $t9, $zero, L_8014F3B8
    if (ctx->r25 == 0) {
        // 0x8014F3B0: nop
    
            goto L_8014F3B8;
    }
    // 0x8014F3B0: nop

    // 0x8014F3B4: sw          $t0, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r8;
L_8014F3B8:
    // 0x8014F3B8: jr          $ra
    // 0x8014F3BC: nop

    return;
    // 0x8014F3BC: nop

;}
RECOMP_FUNC void mnMessageFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801322D8: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801322DC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801322E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801322E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801322E8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801322EC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801322F0: addiu       $t8, $t8, 0x2668
    ctx->r24 = ADD32(ctx->r24, 0X2668);
    // 0x801322F4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801322F8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801322FC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80132300: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80132304: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132308: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8013230C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80132310: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80132314: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80132318: jal         0x800CDF78
    // 0x8013231C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013231C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80132320: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132324: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    // 0x80132328: jal         0x800CDEEC
    // 0x8013232C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013232C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132334: jal         0x80004980
    // 0x80132338: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132338: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013233C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132340: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132344: addiu       $a2, $a2, 0x2988
    ctx->r6 = ADD32(ctx->r6, 0X2988);
    // 0x80132348: addiu       $a0, $a0, 0x2500
    ctx->r4 = ADD32(ctx->r4, 0X2500);
    // 0x8013234C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132350: jal         0x800CDE04
    // 0x80132354: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132354: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132358: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013235C: addiu       $a1, $a1, 0x223C
    ctx->r5 = ADD32(ctx->r5, 0X223C);
    // 0x80132360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132368: jal         0x80009968
    // 0x8013236C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013236C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132374: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132378: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013237C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80132380: jal         0x8000B9FC
    // 0x80132384: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132384: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80132388: jal         0x80132168
    // 0x8013238C: nop

    mnMessageInitVars(rdram, ctx);
        goto after_6;
    // 0x8013238C: nop

    after_6:
    // 0x80132390: jal         0x80132028
    // 0x80132394: nop

    mnMessageMakeWallpaperCamera(rdram, ctx);
        goto after_7;
    // 0x80132394: nop

    after_7:
    // 0x80132398: jal         0x80131F88
    // 0x8013239C: nop

    mnMessageMakeMessageCamera(rdram, ctx);
        goto after_8;
    // 0x8013239C: nop

    after_8:
    // 0x801323A0: jal         0x80131EE8
    // 0x801323A4: nop

    mnMessageMakeTintCamera(rdram, ctx);
        goto after_9;
    // 0x801323A4: nop

    after_9:
    // 0x801323A8: jal         0x801320C8
    // 0x801323AC: nop

    mnMessageMakeExclaimCamera(rdram, ctx);
        goto after_10;
    // 0x801323AC: nop

    after_10:
    // 0x801323B0: jal         0x80131B24
    // 0x801323B4: nop

    mnMessageMakeWallpaper(rdram, ctx);
        goto after_11;
    // 0x801323B4: nop

    after_11:
    // 0x801323B8: jal         0x80131CB8
    // 0x801323BC: nop

    mnMessageMakeTint(rdram, ctx);
        goto after_12;
    // 0x801323BC: nop

    after_12:
    // 0x801323C0: jal         0x80131D04
    // 0x801323C4: nop

    mnMessageMakeExclaim(rdram, ctx);
        goto after_13;
    // 0x801323C4: nop

    after_13:
    // 0x801323C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801323CC: jal         0x80131D9C
    // 0x801323D0: lw          $a0, 0x2658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2658);
    mnMessageMakeMessage(rdram, ctx);
        goto after_14;
    // 0x801323D0: lw          $a0, 0x2658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2658);
    after_14:
    // 0x801323D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323D8: jal         0x80020AB4
    // 0x801323DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    syAudioPlayBGM(rdram, ctx);
        goto after_15;
    // 0x801323DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_15:
    // 0x801323E0: jal         0x800269C0
    // 0x801323E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800269C0_275C0(rdram, ctx);
        goto after_16;
    // 0x801323E4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_16:
    // 0x801323E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801323EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801323F0: jr          $ra
    // 0x801323F4: nop

    return;
    // 0x801323F4: nop

;}
RECOMP_FUNC void ftCaptainSpecialNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F8EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F8F4: jal         0x8015F7F0
    // 0x8015F8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCaptainSpecialNUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015F8F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015F8FC: jal         0x800D8C14
    // 0x8015F900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_1;
    // 0x8015F900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015F904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F90C: jr          $ra
    // 0x8015F910: nop

    return;
    // 0x8015F910: nop

;}
RECOMP_FUNC void mnTitleGetFighterKindsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131B04: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80131B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131B0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131B10: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_80131B14:
    // 0x80131B14: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x80131B18: beq         $t6, $zero, L_80131B24
    if (ctx->r14 == 0) {
        // 0x80131B1C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80131B24;
    }
    // 0x80131B1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80131B20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131B24:
    // 0x80131B24: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131B28: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131B2C: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80131B30: beq         $t7, $zero, L_80131B3C
    if (ctx->r15 == 0) {
        // 0x80131B34: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80131B3C;
    }
    // 0x80131B34: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131B38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131B3C:
    // 0x80131B3C: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131B40: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80131B44: beq         $t8, $zero, L_80131B50
    if (ctx->r24 == 0) {
        // 0x80131B48: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80131B50;
    }
    // 0x80131B48: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131B4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131B50:
    // 0x80131B50: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80131B54: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x80131B58: beq         $t9, $zero, L_80131B64
    if (ctx->r25 == 0) {
        // 0x80131B5C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80131B64;
    }
    // 0x80131B5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80131B60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131B64:
    // 0x80131B64: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80131B68: bne         $v0, $a2, L_80131B14
    if (ctx->r2 != ctx->r6) {
        // 0x80131B6C: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_80131B14;
    }
    // 0x80131B6C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80131B70: jr          $ra
    // 0x80131B74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131B74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl2_801023D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801023D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801023D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801023DC: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x801023E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801023E4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801023E8: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x801023EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801023F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801023F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801023F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801023FC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80102400: jal         0x801021C0
    // 0x80102404: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    efManagerDeadExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80102404: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x80102408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010240C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102410: jr          $ra
    // 0x80102414: nop

    return;
    // 0x80102414: nop

;}
RECOMP_FUNC void lbCommonStartSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD0D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD0D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CD0DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CD0E0: jal         0x800CCEAC
    // 0x800CD0E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x800CD0E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CD0E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD0EC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800CD0F0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CD0F4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800CD0F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CD0FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800CD100: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x800CD104: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800CD108: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CD10C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CD110: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800CD114: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x800CD118: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800CD11C: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CD120: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800CD124: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x800CD128: ori         $t1, $t1, 0x1E01
    ctx->r9 = ctx->r9 | 0X1E01;
    // 0x800CD12C: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800CD130: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CD134: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x800CD138: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800CD13C: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800CD140: ori         $t3, $t3, 0xC00
    ctx->r11 = ctx->r11 | 0XC00;
    // 0x800CD144: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800CD148: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800CD14C: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x800CD150: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800CD154: ori         $t4, $t4, 0x1201
    ctx->r12 = ctx->r12 | 0X1201;
    // 0x800CD158: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x800CD15C: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x800CD160: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CD164: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800CD168: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800CD16C: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x800CD170: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x800CD174: addiu       $t7, $zero, 0xC00
    ctx->r15 = ADD32(0, 0XC00);
    // 0x800CD178: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CD17C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CD180: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CD184: ori         $t8, $t8, 0xD01
    ctx->r24 = ctx->r24 | 0XD01;
    // 0x800CD188: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800CD18C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CD190: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CD194: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800CD198: ori         $t9, $t9, 0xF00
    ctx->r25 = ctx->r25 | 0XF00;
    // 0x800CD19C: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800CD1A0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CD1A4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800CD1A8: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x800CD1AC: ori         $t0, $t0, 0x1001
    ctx->r8 = ctx->r8 | 0X1001;
    // 0x800CD1B0: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x800CD1B4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800CD1B8: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x800CD1BC: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x800CD1C0: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x800CD1C4: ori         $t2, $t2, 0x4000
    ctx->r10 = ctx->r10 | 0X4000;
    // 0x800CD1C8: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x800CD1CC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800CD1D0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800CD1D4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800CD1D8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800CD1DC: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x800CD1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD1E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CD1E8: jr          $ra
    // 0x800CD1EC: nop

    return;
    // 0x800CD1EC: nop

;}
RECOMP_FUNC void alSeqpGetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002FDE4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002FDE8: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8002FDEC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8002FDF0: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8002FDF4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002FDF8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8002FDFC: lbu         $t8, 0x11($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X11);
    // 0x8002FE00: lbu         $t9, 0x9($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X9);
    // 0x8002FE04: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8002FE08: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002FE0C: mflo        $v0
    ctx->r2 = lo;
    // 0x8002FE10: nop

    // 0x8002FE14: nop

    // 0x8002FE18: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8002FE1C: mflo        $v0
    ctx->r2 = lo;
    // 0x8002FE20: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8002FE24: jr          $ra
    // 0x8002FE28: nop

    return;
    // 0x8002FE28: nop

;}
RECOMP_FUNC void sc1PTrainingModeFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DA7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DA80: jal         0x8018D9F0
    // 0x8018DA84: nop

    sc1PTrainingModeUpdateAll(rdram, ctx);
        goto after_0;
    // 0x8018DA84: nop

    after_0:
    // 0x8018DA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DA90: jr          $ra
    // 0x8018DA94: nop

    return;
    // 0x8018DA94: nop

;}
RECOMP_FUNC void ftCommonEscapeGetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801492F8: lb          $v0, 0x1C2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1C2);
    // 0x801492FC: bgez        $v0, L_8014930C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80149300: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8014930C;
    }
    // 0x80149300: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80149304: b           L_8014930C
    // 0x80149308: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8014930C;
    // 0x80149308: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8014930C:
    // 0x8014930C: slti        $at, $v1, 0x38
    ctx->r1 = SIGNED(ctx->r3) < 0X38 ? 1 : 0;
    // 0x80149310: bnel        $at, $zero, L_80149354
    if (ctx->r1 != 0) {
        // 0x80149314: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80149354;
    }
    goto skip_0;
    // 0x80149314: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80149318: lbu         $t6, 0x268($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X268);
    // 0x8014931C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80149320: beql        $at, $zero, L_80149354
    if (ctx->r1 == 0) {
        // 0x80149324: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80149354;
    }
    goto skip_1;
    // 0x80149324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x80149328: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8014932C: addiu       $v1, $zero, 0x9D
    ctx->r3 = ADD32(0, 0X9D);
    // 0x80149330: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80149334: mflo        $t8
    ctx->r24 = lo;
    // 0x80149338: bltz        $t8, L_80149348
    if (SIGNED(ctx->r24) < 0) {
        // 0x8014933C: nop
    
            goto L_80149348;
    }
    // 0x8014933C: nop

    // 0x80149340: jr          $ra
    // 0x80149344: addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
    return;
    // 0x80149344: addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
L_80149348:
    // 0x80149348: jr          $ra
    // 0x8014934C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8014934C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80149350: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80149354:
    // 0x80149354: jr          $ra
    // 0x80149358: nop

    return;
    // 0x80149358: nop

;}
RECOMP_FUNC void func_80029100_29D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029100: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029108: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8002910C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029110: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80029114: bnel        $t6, $at, L_80029164
    if (ctx->r14 != ctx->r1) {
        // 0x80029118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029164;
    }
    goto skip_0;
    // 0x80029118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002911C: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80029120: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80029124: beql        $a0, $zero, L_80029164
    if (ctx->r4 == 0) {
        // 0x80029128: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029164;
    }
    goto skip_1;
    // 0x80029128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8002912C: jal         0x80028AF8
    // 0x80029130: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x80029130: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80029134: beq         $v0, $zero, L_80029160
    if (ctx->r2 == 0) {
        // 0x80029138: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80029160;
    }
    // 0x80029138: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8002913C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80029140: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    // 0x80029144: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80029148: addiu       $a0, $a3, 0x50
    ctx->r4 = ADD32(ctx->r7, 0X50);
    // 0x8002914C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80029150: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029154: mflo        $a2
    ctx->r6 = lo;
    // 0x80029158: jal         0x80028D70
    // 0x8002915C: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x8002915C: nop

    after_1:
L_80029160:
    // 0x80029160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80029164:
    // 0x80029164: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029168: jr          $ra
    // 0x8002916C: nop

    return;
    // 0x8002916C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801327C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801327CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801327D0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801327D4: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x801327D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801327DC: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x801327E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801327E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801327E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801327EC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801327F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801327F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801327F8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801327FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132800: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132804: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132808: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013280C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132810: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132814: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013281C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132820: jal         0x8000B93C
    // 0x80132824: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132824: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132828: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013282C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132830: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132834: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013283C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132840: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132844: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132848: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013284C: jal         0x80007080
    // 0x80132850: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132850: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132854: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132858: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013285C: jr          $ra
    // 0x80132860: nop

    return;
    // 0x80132860: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeLogoCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A6C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133A70: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80133A74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133A78: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80133A7C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80133A80: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133A84: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80133A88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133A8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133A90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133A94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133A98: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80133A9C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80133AA0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80133AA4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133AA8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133AAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133AB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133AB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133AB8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133ABC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133AC0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133AC8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133ACC: jal         0x8000B93C
    // 0x80133AD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133AD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133AD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133AD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133ADC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133AE0: sw          $v0, 0x4CF0($at)
    MEM_W(0X4CF0, ctx->r1) = ctx->r2;
    // 0x80133AE4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80133AE8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133AEC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133AF4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133AF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133AFC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133B00: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133B04: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80133B08: jal         0x80007080
    // 0x80133B0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133B0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133B10: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133B14: lw          $t4, 0x50B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50B8);
    // 0x80133B18: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80133B1C: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x80133B20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80133B24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133B28: jal         0x8000FA3C
    // 0x80133B2C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80133B2C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80133B30: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133B34: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80133B38: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80133B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133B40: jal         0x80008188
    // 0x80133B44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80133B44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80133B48: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133B4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133B50: jr          $ra
    // 0x80133B54: nop

    return;
    // 0x80133B54: nop

;}
RECOMP_FUNC void mnPlayersVSCheckFighterLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132044: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80132048: beq         $a0, $at, L_801320E4
    if (ctx->r4 == ctx->r1) {
        // 0x8013204C: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_801320E4;
    }
    // 0x8013204C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132050: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132054: beq         $a0, $at, L_801320C0
    if (ctx->r4 == ctx->r1) {
        // 0x80132058: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_801320C0;
    }
    // 0x80132058: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013205C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80132060: beq         $a0, $at, L_8013209C
    if (ctx->r4 == ctx->r1) {
        // 0x80132064: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_8013209C;
    }
    // 0x80132064: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132068: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013206C: bne         $a0, $at, L_80132108
    if (ctx->r4 != ctx->r1) {
        // 0x80132070: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80132108;
    }
    // 0x80132070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132074: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132078: lhu         $t6, -0x4244($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4244);
    // 0x8013207C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132080: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80132084: beq         $t7, $zero, L_80132094
    if (ctx->r15 == 0) {
        // 0x80132088: nop
    
            goto L_80132094;
    }
    // 0x80132088: nop

    // 0x8013208C: jr          $ra
    // 0x80132090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132094:
    // 0x80132094: jr          $ra
    // 0x80132098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013209C:
    // 0x8013209C: lhu         $t8, -0x4244($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4244);
    // 0x801320A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801320A4: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x801320A8: beq         $t9, $zero, L_801320B8
    if (ctx->r25 == 0) {
        // 0x801320AC: nop
    
            goto L_801320B8;
    }
    // 0x801320AC: nop

    // 0x801320B0: jr          $ra
    // 0x801320B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801320B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801320B8:
    // 0x801320B8: jr          $ra
    // 0x801320BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801320BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801320C0:
    // 0x801320C0: lhu         $t0, -0x4244($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4244);
    // 0x801320C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801320C8: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x801320CC: beq         $t1, $zero, L_801320DC
    if (ctx->r9 == 0) {
        // 0x801320D0: nop
    
            goto L_801320DC;
    }
    // 0x801320D0: nop

    // 0x801320D4: jr          $ra
    // 0x801320D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801320D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801320DC:
    // 0x801320DC: jr          $ra
    // 0x801320E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801320E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801320E4:
    // 0x801320E4: lhu         $t2, -0x4244($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4244);
    // 0x801320E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801320EC: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x801320F0: beq         $t3, $zero, L_80132100
    if (ctx->r11 == 0) {
        // 0x801320F4: nop
    
            goto L_80132100;
    }
    // 0x801320F4: nop

    // 0x801320F8: jr          $ra
    // 0x801320FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801320FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132100:
    // 0x80132100: jr          $ra
    // 0x80132104: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132104: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132108:
    // 0x80132108: jr          $ra
    // 0x8013210C: nop

    return;
    // 0x8013210C: nop

;}
RECOMP_FUNC void mnVSOptionsMakeTint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013346C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133474: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80133478: jal         0x80009968
    // 0x8013347C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013347C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133480: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133484: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133488: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013348C: addiu       $a1, $a1, 0x334C
    ctx->r5 = ADD32(ctx->r5, 0X334C);
    // 0x80133490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133494: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133498: jal         0x80009DF4
    // 0x8013349C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013349C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801334A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801334A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801334A8: jr          $ra
    // 0x801334AC: nop

    return;
    // 0x801334AC: nop

;}
RECOMP_FUNC void mpProcessFloorEdgeLAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9AB0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D9AB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9AB8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D9ABC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D9AC0: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x800D9AC4: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D9AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D9ACC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800D9AD0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9AD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D9ADC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9AE0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800D9AE4: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800D9AE8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9AEC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800D9AF0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800D9AF4: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x800D9AF8: jal         0x800F4194
    // 0x800D9AFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_0;
    // 0x800D9AFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800D9B00: beq         $v0, $zero, L_800D9BF4
    if (ctx->r2 == 0) {
        // 0x800D9B04: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800D9BF4;
    }
    // 0x800D9B04: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800D9B08: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9B0C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9B10: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800D9B14: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D9B18: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9B1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D9B20: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D9B24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9B28: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800D9B2C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9B30: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800D9B34: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9B38: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9B3C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D9B40: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9B44: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9B48: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800D9B4C: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800D9B50: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9B54: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800D9B58: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D9B5C: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9B60: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D9B64: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800D9B68: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9B6C: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800D9B70: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800D9B74: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9B78: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D9B7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9B80: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D9B84: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9B88: jal         0x800F7F00
    // 0x800D9B8C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D9B8C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800D9B90: beq         $v0, $zero, L_800D9CAC
    if (ctx->r2 == 0) {
        // 0x800D9B94: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_800D9CAC;
    }
    // 0x800D9B94: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800D9B98: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D9B9C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9BA0: addiu       $t6, $s0, 0x80
    ctx->r14 = ADD32(ctx->r16, 0X80);
    // 0x800D9BA4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9BA8: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800D9BAC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D9BB0: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800D9BB4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800D9BB8: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9BBC: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9BC0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9BC4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9BC8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800D9BCC: jal         0x800F3DD8
    // 0x800D9BD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x800D9BD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x800D9BD4: beq         $v0, $zero, L_800D9CAC
    if (ctx->r2 == 0) {
        // 0x800D9BD8: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800D9CAC;
    }
    // 0x800D9BD8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D9BDC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9BE0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D9BE4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x800D9BE8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9BEC: b           L_800D9CAC
    // 0x800D9BF0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_800D9CAC;
    // 0x800D9BF0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_800D9BF4:
    // 0x800D9BF4: jal         0x800F4650
    // 0x800D9BF8: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_3;
    // 0x800D9BF8: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    after_3:
    // 0x800D9BFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D9C00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9C04: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D9C08: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9C0C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D9C10: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800D9C14: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800D9C18: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9C1C: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D9C20: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800D9C24: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9C28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9C2C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9C30: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800D9C34: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800D9C38: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9C3C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9C40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9C44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9C48: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800D9C4C: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D9C50: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800D9C54: jal         0x800F4BD8
    // 0x800D9C58: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_4;
    // 0x800D9C58: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x800D9C5C: beql        $v0, $zero, L_800D9CB0
    if (ctx->r2 == 0) {
        // 0x800D9C60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D9CB0;
    }
    goto skip_0;
    // 0x800D9C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800D9C64: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D9C68: addiu       $t7, $s0, 0x80
    ctx->r15 = ADD32(ctx->r16, 0X80);
    // 0x800D9C6C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9C70: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800D9C74: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9C78: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D9C7C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800D9C80: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800D9C84: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800D9C88: jal         0x800F3DD8
    // 0x800D9C8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_5;
    // 0x800D9C8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800D9C90: beq         $v0, $zero, L_800D9CAC
    if (ctx->r2 == 0) {
        // 0x800D9C94: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800D9CAC;
    }
    // 0x800D9C94: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D9C98: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9C9C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D9CA0: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x800D9CA4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9CA8: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_800D9CAC:
    // 0x800D9CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D9CB0:
    // 0x800D9CB0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9CB4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D9CB8: jr          $ra
    // 0x800D9CBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800D9CBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}

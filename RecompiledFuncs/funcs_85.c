#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gcGetAObjValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CB94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000CB98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000CB9C: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8000CBA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CBA4: beq         $v0, $at, L_8000CC08
    if (ctx->r2 == ctx->r1) {
        // 0x8000CBA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000CC08;
    }
    // 0x8000CBA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CBAC: beq         $v0, $at, L_8000CBC4
    if (ctx->r2 == ctx->r1) {
        // 0x8000CBB0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000CBC4;
    }
    // 0x8000CBB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000CBB4: beql        $v0, $at, L_8000CBE0
    if (ctx->r2 == ctx->r1) {
        // 0x8000CBB8: lwc1        $f16, 0x18($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
            goto L_8000CBE0;
    }
    goto skip_0;
    // 0x8000CBB8: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x8000CBBC: b           L_8000CC34
    // 0x8000CBC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000CC34;
    // 0x8000CBC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CBC4:
    // 0x8000CBC4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CBC8: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000CBCC: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000CBD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CBD4: b           L_8000CC30
    // 0x8000CBD8: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
        goto L_8000CC30;
    // 0x8000CBD8: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000CBDC: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
L_8000CBE0:
    // 0x8000CBE0: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000CBE4: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CBE8: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8000CBEC: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x8000CBF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000CBF4: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000CBF8: jal         0x8000CA28
    // 0x8000CBFC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    gcGetInterpValueCubic(rdram, ctx);
        goto after_0;
    // 0x8000CBFC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8000CC00: b           L_8000CC34
    // 0x8000CC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000CC34;
    // 0x8000CC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CC08:
    // 0x8000CC08: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CC0C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000CC10: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8000CC14: nop

    // 0x8000CC18: bc1fl       L_8000CC2C
    if (!c1cs) {
        // 0x8000CC1C: lwc1        $f2, 0x10($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
            goto L_8000CC2C;
    }
    goto skip_1;
    // 0x8000CC1C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x8000CC20: b           L_8000CC2C
    // 0x8000CC24: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
        goto L_8000CC2C;
    // 0x8000CC24: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000CC28: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
L_8000CC2C:
    // 0x8000CC2C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000CC30:
    // 0x8000CC30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000CC34:
    // 0x8000CC34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000CC38: jr          $ra
    // 0x8000CC3C: nop

    return;
    // 0x8000CC3C: nop

;}
RECOMP_FUNC void itMewFlyInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EC84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EC88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017EC8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017EC90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017EC94: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017EC98: addiu       $t7, $zero, 0x1E0
    ctx->r15 = ADD32(0, 0X1E0);
    // 0x8017EC9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8017ECA0: jal         0x80018994
    // 0x8017ECA4: sh          $t7, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r15;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8017ECA4: sh          $t7, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r15;
    after_0:
    // 0x8017ECA8: beq         $v0, $zero, L_8017ECC0
    if (ctx->r2 == 0) {
        // 0x8017ECAC: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_8017ECC0;
    }
    // 0x8017ECAC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8017ECB0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017ECB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017ECB8: b           L_8017ECCC
    // 0x8017ECBC: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_8017ECCC;
    // 0x8017ECBC: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_8017ECC0:
    // 0x8017ECC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017ECC4: nop

    // 0x8017ECC8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_8017ECCC:
    // 0x8017ECCC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8017ECD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017ECD4: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    // 0x8017ECD8: jal         0x800269C0
    // 0x8017ECDC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8017ECDC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8017ECE0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8017ECE4: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8017ECE8: bnel        $t8, $at, L_8017ECFC
    if (ctx->r24 != ctx->r1) {
        // 0x8017ECEC: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_8017ECFC;
    }
    goto skip_0;
    // 0x8017ECEC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8017ECF0: jal         0x800269C0
    // 0x8017ECF4: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017ECF4: addiu       $a0, $zero, 0x13B
    ctx->r4 = ADD32(0, 0X13B);
    after_2:
    // 0x8017ECF8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_8017ECFC:
    // 0x8017ECFC: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x8017ED00: jal         0x801014A8
    // 0x8017ED04: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerRippleMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8017ED04: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8017ED08: sw          $zero, 0x350($s0)
    MEM_W(0X350, ctx->r16) = 0;
    // 0x8017ED0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017ED10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017ED14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017ED18: jr          $ra
    // 0x8017ED1C: nop

    return;
    // 0x8017ED1C: nop

;}
RECOMP_FUNC void itSwordFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174B5C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80174B60: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174B64: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80174B68: jal         0x80172558
    // 0x80174B6C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174B6C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80174B70: jal         0x801713F4
    // 0x80174B74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80174B74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80174B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174B84: jr          $ra
    // 0x80174B88: nop

    return;
    // 0x80174B88: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F33C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F340: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F344: jal         0x800DE6E4
    // 0x8015F348: addiu       $a1, $a1, -0xBF8
    ctx->r5 = ADD32(ctx->r5, -0XBF8);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015F348: addiu       $a1, $a1, -0xBF8
    ctx->r5 = ADD32(ctx->r5, -0XBF8);
    after_0:
    // 0x8015F34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F354: jr          $ra
    // 0x8015F358: nop

    return;
    // 0x8015F358: nop

;}
RECOMP_FUNC void mnVSResultsEmblemProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A68: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132A6C: lw          $t6, -0x6488($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6488);
    // 0x80132A70: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x80132A74: bne         $at, $zero, L_80132B18
    if (ctx->r1 != 0) {
        // 0x80132A78: nop
    
            goto L_80132B18;
    }
    // 0x80132A78: nop

    // 0x80132A7C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132A80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132A84: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132A88: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80132A8C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132A90: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80132A94: nop

    // 0x80132A98: bc1fl       L_80132AD0
    if (!c1cs) {
        // 0x80132A9C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80132AD0;
    }
    goto skip_0;
    // 0x80132A9C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_0:
    // 0x80132AA0: lwc1        $f4, -0x67A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X67A0);
    // 0x80132AA4: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80132AA8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80132AAC: nop

    // 0x80132AB0: bc1fl       L_80132AC0
    if (!c1cs) {
        // 0x80132AB4: swc1        $f2, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
            goto L_80132AC0;
    }
    goto skip_1;
    // 0x80132AB4: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80132AB8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80132ABC: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
L_80132AC0:
    // 0x80132AC0: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80132AC4: swc1        $f2, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f2.u32l;
    // 0x80132AC8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132ACC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
L_80132AD0:
    // 0x80132AD0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132AD4: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80132AD8: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80132ADC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132AE0: nop

    // 0x80132AE4: bc1f        L_80132B18
    if (!c1cs) {
        // 0x80132AE8: nop
    
            goto L_80132B18;
    }
    // 0x80132AE8: nop

    // 0x80132AEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132AF0: nop

    // 0x80132AF4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80132AF8: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80132AFC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132B00: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80132B04: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80132B08: nop

    // 0x80132B0C: bc1f        L_80132B18
    if (!c1cs) {
        // 0x80132B10: nop
    
            goto L_80132B18;
    }
    // 0x80132B10: nop

    // 0x80132B14: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
L_80132B18:
    // 0x80132B18: jr          $ra
    // 0x80132B1C: nop

    return;
    // 0x80132B1C: nop

;}
RECOMP_FUNC void itDisplayColAnimOPA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171DF4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80171DF8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80171DFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80171E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80171E0C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80171E10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80171E14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80171E18: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80171E1C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80171E20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80171E24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171E28: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x80171E2C: ori         $t1, $t1, 0xA01
    ctx->r9 = ctx->r9 | 0XA01;
    // 0x80171E30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80171E34: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80171E38: lui         $t2, 0x10
    ctx->r10 = S32(0X10 << 16);
    // 0x80171E3C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80171E40: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80171E44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171E48: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x80171E4C: lui         $t5, 0xC19
    ctx->r13 = S32(0XC19 << 16);
    // 0x80171E50: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80171E54: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80171E58: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x80171E5C: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x80171E60: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80171E64: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80171E68: lw          $t6, 0x338($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X338);
    // 0x80171E6C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80171E70: beql        $t7, $zero, L_80171EC0
    if (ctx->r15 == 0) {
        // 0x80171E74: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80171EC0;
    }
    goto skip_0;
    // 0x80171E74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80171E78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171E7C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80171E80: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80171E84: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80171E88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80171E8C: lbu         $t5, 0x319($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X319);
    // 0x80171E90: lbu         $t2, 0x318($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X318);
    // 0x80171E94: lbu         $t9, 0x31A($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X31A);
    // 0x80171E98: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80171E9C: lbu         $t5, 0x31B($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X31B);
    // 0x80171EA0: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80171EA4: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80171EA8: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x80171EAC: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x80171EB0: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x80171EB4: b           L_80171ED4
    // 0x80171EB8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
        goto L_80171ED4;
    // 0x80171EB8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80171EBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80171EC0:
    // 0x80171EC0: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80171EC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80171EC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80171ECC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80171ED0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80171ED4:
    // 0x80171ED4: jal         0x80014038
    // 0x80171ED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80171ED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80171EDC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80171EE0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80171EE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171EE8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80171EEC: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x80171EF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80171EF4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80171EF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80171EFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80171F00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171F04: ori         $t4, $t4, 0xA01
    ctx->r12 = ctx->r12 | 0XA01;
    // 0x80171F08: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80171F0C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80171F10: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80171F14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80171F18: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80171F1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80171F20: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x80171F24: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x80171F28: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80171F2C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80171F30: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80171F34: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80171F38: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80171F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80171F44: jr          $ra
    // 0x80171F48: nop

    return;
    // 0x80171F48: nop

;}
RECOMP_FUNC void func_ovl8_803744D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803744D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803744D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803744DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x803744E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803744E4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803744E8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803744EC: jal         0x803717A0
    // 0x803744F0: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803744F0: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x803744F4: beq         $v0, $zero, L_80374530
    if (ctx->r2 == 0) {
        // 0x803744F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80374530;
    }
    // 0x803744F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803744FC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80374500: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80374504: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80374508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037450C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374510: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80374514: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80374518: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037451C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80374520: jal         0x8037CBA0
    // 0x80374524: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_8037CBA0(rdram, ctx);
        goto after_1;
    // 0x80374524: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x80374528: b           L_80374534
    // 0x8037452C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_80374534;
    // 0x8037452C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80374530:
    // 0x80374530: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80374534:
    // 0x80374534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80374538: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037453C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80374540: jr          $ra
    // 0x80374544: nop

    return;
    // 0x80374544: nop

;}
RECOMP_FUNC void mnVSOptionsSetAllSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013394C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133950: lw          $t6, 0x48E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X48E4);
    // 0x80133954: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133958: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x8013395C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133960: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
    // 0x80133964: lw          $t7, 0x48E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X48E8);
    // 0x80133968: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013396C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133970: sb          $t7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r15;
    // 0x80133974: lw          $t8, 0x48EC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X48EC);
    // 0x80133978: andi        $t0, $t6, 0xFF
    ctx->r8 = ctx->r14 & 0XFF;
    // 0x8013397C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80133980: sb          $t8, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r24;
    // 0x80133984: lw          $t9, 0x48F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X48F0);
    // 0x80133988: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8013398C: bne         $t0, $zero, L_801339BC
    if (ctx->r8 != 0) {
        // 0x80133990: sb          $t9, 0xB($v0)
        MEM_B(0XB, ctx->r2) = ctx->r25;
            goto L_801339BC;
    }
    // 0x80133990: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    // 0x80133994: sb          $t1, 0x4D29($at)
    MEM_B(0X4D29, ctx->r1) = ctx->r9;
    // 0x80133998: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8013399C: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x801339A0: sb          $t2, 0x4D9D($at)
    MEM_B(0X4D9D, ctx->r1) = ctx->r10;
    // 0x801339A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801339A8: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x801339AC: sb          $t3, 0x4E11($at)
    MEM_B(0X4E11, ctx->r1) = ctx->r11;
    // 0x801339B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801339B4: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x801339B8: sb          $t4, 0x4E85($at)
    MEM_B(0X4E85, ctx->r1) = ctx->r12;
L_801339BC:
    // 0x801339BC: jr          $ra
    // 0x801339C0: nop

    return;
    // 0x801339C0: nop

;}
RECOMP_FUNC void func_ovl7_8018F41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F41C: jr          $ra
    // 0x8018F420: nop

    return;
    // 0x8018F420: nop

;}
RECOMP_FUNC void func_ovl8_8037A8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A8BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037A8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037A8C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037A8C8: jal         0x8037A9F4
    // 0x8037A8CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_ovl8_8037A9F4(rdram, ctx);
        goto after_0;
    // 0x8037A8CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8037A8D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A8D4: jal         0x8037A9F4
    // 0x8037A8D8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_ovl8_8037A9F4(rdram, ctx);
        goto after_1;
    // 0x8037A8D8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8037A8DC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8037A8E0: jal         0x8037A904
    // 0x8037A8E4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_ovl8_8037A904(rdram, ctx);
        goto after_2;
    // 0x8037A8E4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8037A8E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8037A8EC: jal         0x8037AA28
    // 0x8037A8F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037AA28(rdram, ctx);
        goto after_3;
    // 0x8037A8F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8037A8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037A8F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037A8FC: jr          $ra
    // 0x8037A900: nop

    return;
    // 0x8037A900: nop

;}
RECOMP_FUNC void ftCommonJumpAerialUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013FA94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013FA98: lw          $v1, 0xB20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB20);
    // 0x8013FA9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8013FAA0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013FAA4: beq         $v1, $zero, L_8013FAF0
    if (ctx->r3 == 0) {
        // 0x8013FAA8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8013FAF0;
    }
    // 0x8013FAA8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8013FAAC: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013FAB0: sw          $t6, 0xB20($a0)
    MEM_W(0XB20, ctx->r4) = ctx->r14;
    // 0x8013FAB4: lwc1        $f6, -0x3F30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3F30);
    // 0x8013FAB8: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8013FABC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013FAC0: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x8013FAC4: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013FAC8: jal         0x800EB528
    // 0x8013FACC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x8013FACC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8013FAD0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8013FAD4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013FAD8: lw          $t7, 0xB20($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB20);
    // 0x8013FADC: bnel        $t7, $at, L_8013FAF4
    if (ctx->r15 != ctx->r1) {
        // 0x8013FAE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013FAF4;
    }
    goto skip_0;
    // 0x8013FAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013FAE4: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x8013FAE8: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8013FAEC: sw          $t9, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r25;
L_8013FAF0:
    // 0x8013FAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013FAF4:
    // 0x8013FAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013FAF8: jr          $ra
    // 0x8013FAFC: nop

    return;
    // 0x8013FAFC: nop

;}
RECOMP_FUNC void grYamabukiGateSetClosedWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B0BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B0C0: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010B0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B0C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8010B0CC: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8010B0D0: sb          $t6, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r14;
    // 0x8010B0D4: sh          $t7, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r15;
    // 0x8010B0D8: jal         0x80018994
    // 0x8010B0DC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010B0DC: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_0:
    // 0x8010B0E0: addiu       $t8, $v0, 0x3E8
    ctx->r24 = ADD32(ctx->r2, 0X3E8);
    // 0x8010B0E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B0E8: jal         0x8010AE68
    // 0x8010B0EC: sh          $t8, 0x140E($at)
    MEM_H(0X140E, ctx->r1) = ctx->r24;
    grYamabukiGateSetPositionNear(rdram, ctx);
        goto after_1;
    // 0x8010B0EC: sh          $t8, 0x140E($at)
    MEM_H(0X140E, ctx->r1) = ctx->r24;
    after_1:
    // 0x8010B0F0: jal         0x8010AEFC
    // 0x8010B0F4: nop

    grYamabukiGateAddAnimClose(rdram, ctx);
        goto after_2;
    // 0x8010B0F4: nop

    after_2:
    // 0x8010B0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B0FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B100: jr          $ra
    // 0x8010B104: nop

    return;
    // 0x8010B104: nop

;}
RECOMP_FUNC void func_ovl8_80382D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80382D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382D38: jal         0x80381308
    // 0x80382D3C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_ovl8_80381308(rdram, ctx);
        goto after_0;
    // 0x80382D3C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x80382D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80382D48: jr          $ra
    // 0x80382D4C: nop

    return;
    // 0x80382D4C: nop

;}
RECOMP_FUNC void mnStartupStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131EF8: jal         0x80020A74
    // 0x80131EFC: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_0;
    // 0x80131EFC: nop

    after_0:
    // 0x80131F00: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80131F04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F08: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80131F0C: addiu       $a0, $a0, 0x1F98
    ctx->r4 = ADD32(ctx->r4, 0X1F98);
    // 0x80131F10: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80131F14: jal         0x80007024
    // 0x80131F18: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_1;
    // 0x80131F18: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_1:
    // 0x80131F1C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80131F20: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131F24: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F28: addiu       $t9, $t9, 0x2080
    ctx->r25 = ADD32(ctx->r25, 0X2080);
    // 0x80131F2C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80131F30: addiu       $a0, $a0, 0x1FB4
    ctx->r4 = ADD32(ctx->r4, 0X1FB4);
    // 0x80131F34: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80131F38: jal         0x8000683C
    // 0x80131F3C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_2;
    // 0x80131F3C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_2:
    // 0x80131F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131F48: jr          $ra
    // 0x80131F4C: nop

    return;
    // 0x80131F4C: nop

;}
RECOMP_FUNC void mvOpeningKirbyFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E014: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E018: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E01C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E020: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E024: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E028: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E02C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E030: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E034: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E038: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E03C: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E040: jal         0x800FCB70
    // 0x8018E044: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E044: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E050: jr          $ra
    // 0x8018E054: nop

    return;
    // 0x8018E054: nop

;}
RECOMP_FUNC void mnVSResultsGetCharacterID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80133F20: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80133F24: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80133F28: beq         $a0, $at, L_80133F5C
    if (ctx->r4 == ctx->r1) {
        // 0x80133F2C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80133F5C;
    }
    // 0x80133F2C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80133F30: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80133F34: beq         $a0, $at, L_80133F4C
    if (ctx->r4 == ctx->r1) {
        // 0x80133F38: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80133F4C;
    }
    // 0x80133F38: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80133F3C: beq         $a0, $at, L_80133F54
    if (ctx->r4 == ctx->r1) {
        // 0x80133F40: addiu       $v0, $v1, -0x41
        ctx->r2 = ADD32(ctx->r3, -0X41);
            goto L_80133F54;
    }
    // 0x80133F40: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
    // 0x80133F44: b           L_80133F64
    // 0x80133F48: nop

        goto L_80133F64;
    // 0x80133F48: nop

L_80133F4C:
    // 0x80133F4C: jr          $ra
    // 0x80133F50: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x80133F50: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_80133F54:
    // 0x80133F54: jr          $ra
    // 0x80133F58: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80133F58: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80133F5C:
    // 0x80133F5C: jr          $ra
    // 0x80133F60: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80133F60: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80133F64:
    // 0x80133F64: jr          $ra
    // 0x80133F68: nop

    return;
    // 0x80133F68: nop

;}
RECOMP_FUNC void grJungleTaruCannUpdateMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109D44: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80109D48: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80109D4C: lhu         $t6, 0xA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XA);
    // 0x80109D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109D54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109D58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80109D5C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80109D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80109D64: bne         $t8, $zero, L_80109DAC
    if (ctx->r24 != 0) {
        // 0x80109D68: sh          $t7, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r15;
            goto L_80109DAC;
    }
    // 0x80109D68: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x80109D6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80109D70: jal         0x80018910
    // 0x80109D74: sb          $t9, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r25;
    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x80109D74: sb          $t9, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r25;
    after_0:
    // 0x80109D78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80109D7C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80109D80: beq         $t0, $zero, L_80109D98
    if (ctx->r8 == 0) {
        // 0x80109D84: addiu       $v1, $v1, 0x13F0
        ctx->r3 = ADD32(ctx->r3, 0X13F0);
            goto L_80109D98;
    }
    // 0x80109D84: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80109D88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109D8C: lwc1        $f4, 0xB60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB60);
    // 0x80109D90: b           L_80109DA4
    // 0x80109D94: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
        goto L_80109DA4;
    // 0x80109D94: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
L_80109D98:
    // 0x80109D98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109D9C: lwc1        $f6, 0xB64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB64);
    // 0x80109DA0: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_80109DA4:
    // 0x80109DA4: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x80109DA8: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
L_80109DAC:
    // 0x80109DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109DB4: jr          $ra
    // 0x80109DB8: nop

    return;
    // 0x80109DB8: nop

;}
RECOMP_FUNC void efManagerNessPKFlashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102A94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102A98: jal         0x800FDAFC
    // 0x80102A9C: addiu       $a0, $a0, -0x1B44
    ctx->r4 = ADD32(ctx->r4, -0X1B44);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102A9C: addiu       $a0, $a0, -0x1B44
    ctx->r4 = ADD32(ctx->r4, -0X1B44);
    after_0:
    // 0x80102AA0: bne         $v0, $zero, L_80102AB0
    if (ctx->r2 != 0) {
        // 0x80102AA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102AB0;
    }
    // 0x80102AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102AA8: b           L_80102AD4
    // 0x80102AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102AD4;
    // 0x80102AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102AB0:
    // 0x80102AB0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102AB4: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102AB8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102ABC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102AC0: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80102AC4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102AC8: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80102ACC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102AD0: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80102AD4:
    // 0x80102AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102ADC: jr          $ra
    // 0x80102AE0: nop

    return;
    // 0x80102AE0: nop

;}
RECOMP_FUNC void func_ovl8_8037483C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037483C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374844: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80374848: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037484C: lw          $t9, 0x13C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X13C);
    // 0x80374850: lh          $t6, 0x138($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X138);
    // 0x80374854: jalr        $t9
    // 0x80374858: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374858: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x8037485C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374864: jr          $ra
    // 0x80374868: nop

    return;
    // 0x80374868: nop

;}
RECOMP_FUNC void func_ovl8_80371828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037182C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371830: bne         $a0, $zero, L_80371848
    if (ctx->r4 != 0) {
        // 0x80371834: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80371848;
    }
    // 0x80371834: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80371838: jal         0x803717A0
    // 0x8037183C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037183C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x80371840: beq         $v0, $zero, L_80371864
    if (ctx->r2 == 0) {
        // 0x80371844: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80371864;
    }
    // 0x80371844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80371848:
    // 0x80371848: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037184C: addiu       $t6, $t6, -0x7680
    ctx->r14 = ADD32(ctx->r14, -0X7680);
    // 0x80371850: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    // 0x80371854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80371858: jal         0x80371ECC
    // 0x8037185C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_80371ECC(rdram, ctx);
        goto after_1;
    // 0x8037185C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80371860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80371864:
    // 0x80371864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037186C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80371870: jr          $ra
    // 0x80371874: nop

    return;
    // 0x80371874: nop

;}
RECOMP_FUNC void efManagerNessPKReflectTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801028C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801028C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801028C8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801028CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801028D0: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x801028D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801028D8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801028DC: beql        $t7, $zero, L_80102900
    if (ctx->r15 == 0) {
        // 0x801028E0: lw          $v1, 0x1C($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X1C);
            goto L_80102900;
    }
    goto skip_0;
    // 0x801028E0: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    skip_0:
    // 0x801028E4: jal         0x800FD4F8
    // 0x801028E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x801028E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801028EC: jal         0x80009A84
    // 0x801028F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x801028F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801028F4: b           L_8010295C
    // 0x801028F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010295C;
    // 0x801028F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801028FC: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
L_80102900:
    // 0x80102900: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80102904: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80102908: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8010290C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80102910: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80102914: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80102918: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8010291C: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x80102920: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80102924: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80102928: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8010292C: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80102930: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
    // 0x80102934: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80102938: lw          $t0, 0x1C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1C);
    // 0x8010293C: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80102940: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80102944: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x80102948: lwc1        $f18, 0x20($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8010294C: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80102950: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80102954: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x80102958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010295C:
    // 0x8010295C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102960: jr          $ra
    // 0x80102964: nop

    return;
    // 0x80102964: nop

;}
RECOMP_FUNC void itBatHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174F44: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80174F48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80174F4C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174F50: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    // 0x80174F54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80174F58: jal         0x80172EC8
    // 0x80174F5C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174F5C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80174F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174F68: jr          $ra
    // 0x80174F6C: nop

    return;
    // 0x80174F6C: nop

;}
RECOMP_FUNC void func_ovl8_8037D9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D9D0: lwl         $t8, 0x0($a0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r4, 0X0);
    // 0x8037D9D4: lwr         $t8, 0x3($a0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r4, 0X3);
    // 0x8037D9D8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D9DC: addiu       $t6, $t6, -0x46C
    ctx->r14 = ADD32(ctx->r14, -0X46C);
    // 0x8037D9E0: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x8037D9E4: jr          $ra
    // 0x8037D9E8: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    return;
    // 0x8037D9E8: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
;}
RECOMP_FUNC void func_ovl28_80134830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134830: jr          $ra
    // 0x80134834: nop

    return;
    // 0x80134834: nop

;}
RECOMP_FUNC void itProcessUpdateAttackPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F280: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016F284: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016F288: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8016F28C: lw          $a1, 0x160($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X160);
    // 0x8016F290: addiu       $t2, $zero, 0x60
    ctx->r10 = ADD32(0, 0X60);
    // 0x8016F294: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8016F298: blez        $a1, L_8016F3CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8016F29C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8016F3CC;
    }
    // 0x8016F29C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8016F2A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016F2A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8016F2A8: lw          $a2, 0x10C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10C);
L_8016F2AC:
    // 0x8016F2AC: beql        $a2, $zero, L_8016F3C0
    if (ctx->r6 == 0) {
        // 0x8016F2B0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8016F3C0;
    }
    goto skip_0;
    // 0x8016F2B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8016F2B4: beq         $a2, $a3, L_8016F2D4
    if (ctx->r6 == ctx->r7) {
        // 0x8016F2B8: nop
    
            goto L_8016F2D4;
    }
    // 0x8016F2B8: nop

    // 0x8016F2BC: beql        $a2, $t0, L_8016F344
    if (ctx->r6 == ctx->r8) {
        // 0x8016F2C0: sw          $t1, 0x10C($v0)
        MEM_W(0X10C, ctx->r2) = ctx->r9;
            goto L_8016F344;
    }
    goto skip_1;
    // 0x8016F2C0: sw          $t1, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r9;
    skip_1:
    // 0x8016F2C4: beq         $a2, $t1, L_8016F344
    if (ctx->r6 == ctx->r9) {
        // 0x8016F2C8: nop
    
            goto L_8016F344;
    }
    // 0x8016F2C8: nop

    // 0x8016F2CC: b           L_8016F3C0
    // 0x8016F2D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8016F3C0;
    // 0x8016F2D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8016F2D4:
    // 0x8016F2D4: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016F2D8: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8016F2DC: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8016F2E0: mflo        $t6
    ctx->r14 = lo;
    // 0x8016F2E4: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x8016F2E8: nop

    // 0x8016F2EC: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016F2F0: mflo        $t7
    ctx->r15 = lo;
    // 0x8016F2F4: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8016F2F8: lwc1        $f4, 0x120($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X120);
    // 0x8016F2FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F300: swc1        $f8, 0x164($a2)
    MEM_W(0X164, ctx->r6) = ctx->f8.u32l;
    // 0x8016F304: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8016F308: lwc1        $f10, 0x124($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X124);
    // 0x8016F30C: lwc1        $f16, 0x20($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8016F310: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F314: swc1        $f18, 0x168($a2)
    MEM_W(0X168, ctx->r6) = ctx->f18.u32l;
    // 0x8016F318: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x8016F31C: lwc1        $f4, 0x128($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X128);
    // 0x8016F320: lwc1        $f6, 0x24($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X24);
    // 0x8016F324: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F328: swc1        $f8, 0x16C($a2)
    MEM_W(0X16C, ctx->r6) = ctx->f8.u32l;
    // 0x8016F32C: sw          $t0, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r8;
    // 0x8016F330: sw          $zero, 0x17C($a2)
    MEM_W(0X17C, ctx->r6) = 0;
    // 0x8016F334: swc1        $f0, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->f0.u32l;
    // 0x8016F338: b           L_8016F3BC
    // 0x8016F33C: lw          $a1, 0x160($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X160);
        goto L_8016F3BC;
    // 0x8016F33C: lw          $a1, 0x160($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X160);
    // 0x8016F340: sw          $t1, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r9;
L_8016F344:
    // 0x8016F344: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016F348: mflo        $t5
    ctx->r13 = lo;
    // 0x8016F34C: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8016F350: lw          $t7, 0x164($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X164);
    // 0x8016F354: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8016F358: lw          $t6, 0x168($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X168);
    // 0x8016F35C: sw          $t7, 0x170($a2)
    MEM_W(0X170, ctx->r6) = ctx->r15;
    // 0x8016F360: lw          $t7, 0x16C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X16C);
    // 0x8016F364: sw          $t6, 0x174($a2)
    MEM_W(0X174, ctx->r6) = ctx->r14;
    // 0x8016F368: sw          $t7, 0x178($a2)
    MEM_W(0X178, ctx->r6) = ctx->r15;
    // 0x8016F36C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8016F370: mflo        $t8
    ctx->r24 = lo;
    // 0x8016F374: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x8016F378: lwc1        $f10, 0x120($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X120);
    // 0x8016F37C: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8016F380: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F384: swc1        $f18, 0x164($a2)
    MEM_W(0X164, ctx->r6) = ctx->f18.u32l;
    // 0x8016F388: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x8016F38C: lwc1        $f4, 0x124($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X124);
    // 0x8016F390: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8016F394: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F398: swc1        $f8, 0x168($a2)
    MEM_W(0X168, ctx->r6) = ctx->f8.u32l;
    // 0x8016F39C: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x8016F3A0: lwc1        $f10, 0x128($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X128);
    // 0x8016F3A4: lwc1        $f16, 0x24($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X24);
    // 0x8016F3A8: sw          $zero, 0x17C($a2)
    MEM_W(0X17C, ctx->r6) = 0;
    // 0x8016F3AC: swc1        $f0, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->f0.u32l;
    // 0x8016F3B0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016F3B4: swc1        $f18, 0x16C($a2)
    MEM_W(0X16C, ctx->r6) = ctx->f18.u32l;
    // 0x8016F3B8: lw          $a1, 0x160($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X160);
L_8016F3BC:
    // 0x8016F3BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8016F3C0:
    // 0x8016F3C0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016F3C4: bnel        $at, $zero, L_8016F2AC
    if (ctx->r1 != 0) {
        // 0x8016F3C8: lw          $a2, 0x10C($v0)
        ctx->r6 = MEM_W(ctx->r2, 0X10C);
            goto L_8016F2AC;
    }
    goto skip_2;
    // 0x8016F3C8: lw          $a2, 0x10C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10C);
    skip_2:
L_8016F3CC:
    // 0x8016F3CC: jr          $ra
    // 0x8016F3D0: nop

    return;
    // 0x8016F3D0: nop

;}
RECOMP_FUNC void ftMainAddHiddenPartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6CE0: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x800E6CE4: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x800E6CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6CEC: lw          $t7, 0x2D0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2D0);
    // 0x800E6CF0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800E6CF4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800E6CF8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800E6CFC: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x800E6D00: bne         $a2, $at, L_800E6DF8
    if (ctx->r6 != ctx->r1) {
        // 0x800E6D04: lw          $v1, 0x8E8($t1)
        ctx->r3 = MEM_W(ctx->r9, 0X8E8);
            goto L_800E6DF8;
    }
    // 0x800E6D04: lw          $v1, 0x8E8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X8E8);
    // 0x800E6D08: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x800E6D0C: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x800E6D10: beql        $a2, $zero, L_800E6D80
    if (ctx->r6 == 0) {
        // 0x800E6D14: lw          $t0, 0xC($v1)
        ctx->r8 = MEM_W(ctx->r3, 0XC);
            goto L_800E6D80;
    }
    goto skip_0;
    // 0x800E6D14: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x800E6D18: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x800E6D1C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E6D20: bnel        $t0, $zero, L_800E6D34
    if (ctx->r8 != 0) {
        // 0x800E6D24: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800E6D34;
    }
    goto skip_1;
    // 0x800E6D24: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800E6D28: b           L_800E6D3C
    // 0x800E6D2C: sw          $a2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r6;
        goto L_800E6D3C;
    // 0x800E6D2C: sw          $a2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r6;
    // 0x800E6D30: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800E6D34:
    // 0x800E6D34: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x800E6D38: sw          $t2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r10;
L_800E6D3C:
    // 0x800E6D3C: lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X8);
    // 0x800E6D40: sw          $a1, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r5;
    // 0x800E6D44: beql        $a2, $zero, L_800E6D64
    if (ctx->r6 == 0) {
        // 0x800E6D48: lw          $t3, 0x8($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X8);
            goto L_800E6D64;
    }
    goto skip_2;
    // 0x800E6D48: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x800E6D4C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_800E6D50:
    // 0x800E6D50: sw          $a1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r5;
    // 0x800E6D54: lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X8);
    // 0x800E6D58: bnel        $a2, $zero, L_800E6D50
    if (ctx->r6 != 0) {
        // 0x800E6D5C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800E6D50;
    }
    goto skip_3;
    // 0x800E6D5C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    skip_3:
    // 0x800E6D60: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
L_800E6D64:
    // 0x800E6D64: sw          $t3, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r11;
    // 0x800E6D68: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x800E6D6C: beql        $a1, $zero, L_800E6DB4
    if (ctx->r5 == 0) {
        // 0x800E6D70: sw          $zero, 0x10($v1)
        MEM_W(0X10, ctx->r3) = 0;
            goto L_800E6DB4;
    }
    goto skip_4;
    // 0x800E6D70: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    skip_4:
    // 0x800E6D74: b           L_800E6DB0
    // 0x800E6D78: sw          $a3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r7;
        goto L_800E6DB0;
    // 0x800E6D78: sw          $a3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r7;
    // 0x800E6D7C: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
L_800E6D80:
    // 0x800E6D80: bnel        $t0, $zero, L_800E6D98
    if (ctx->r8 != 0) {
        // 0x800E6D84: lw          $t5, 0x8($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X8);
            goto L_800E6D98;
    }
    goto skip_5;
    // 0x800E6D84: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    skip_5:
    // 0x800E6D88: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800E6D8C: b           L_800E6D9C
    // 0x800E6D90: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
        goto L_800E6D9C;
    // 0x800E6D90: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
    // 0x800E6D94: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
L_800E6D98:
    // 0x800E6D98: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
L_800E6D9C:
    // 0x800E6D9C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x800E6DA0: beql        $a1, $zero, L_800E6DB4
    if (ctx->r5 == 0) {
        // 0x800E6DA4: sw          $zero, 0x10($v1)
        MEM_W(0X10, ctx->r3) = 0;
            goto L_800E6DB4;
    }
    goto skip_6;
    // 0x800E6DA4: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    skip_6:
    // 0x800E6DA8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800E6DAC: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
L_800E6DB0:
    // 0x800E6DB0: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_800E6DB4:
    // 0x800E6DB4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800E6DB8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800E6DBC: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x800E6DC0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800E6DC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E6DC8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800E6DCC: lw          $a1, 0x8E8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8E8);
    // 0x800E6DD0: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    // 0x800E6DD4: beq         $a2, $zero, L_800E6DF0
    if (ctx->r6 == 0) {
        // 0x800E6DD8: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800E6DF0;
    }
    // 0x800E6DD8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E6DDC: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x800E6DE0: sw          $v1, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r3;
L_800E6DE4:
    // 0x800E6DE4: lw          $a3, 0x8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X8);
    // 0x800E6DE8: bnel        $a3, $zero, L_800E6DE4
    if (ctx->r7 != 0) {
        // 0x800E6DEC: sw          $v1, 0x14($a3)
        MEM_W(0X14, ctx->r7) = ctx->r3;
            goto L_800E6DE4;
    }
    goto skip_7;
    // 0x800E6DEC: sw          $v1, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r3;
    skip_7:
L_800E6DF0:
    // 0x800E6DF0: sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
    // 0x800E6DF4: sw          $a1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r5;
L_800E6DF8:
    // 0x800E6DF8: jr          $ra
    // 0x800E6DFC: nop

    return;
    // 0x800E6DFC: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchUpdateCaptureVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E3D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E3E0: lw          $t6, 0x184($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X184);
    // 0x8015E3E4: beql        $t6, $zero, L_8015E40C
    if (ctx->r14 == 0) {
        // 0x8015E3E8: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8015E40C;
    }
    goto skip_0;
    // 0x8015E3E8: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_0:
    // 0x8015E3EC: lw          $v0, 0x840($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X840);
    // 0x8015E3F0: beql        $v0, $zero, L_8015E40C
    if (ctx->r2 == 0) {
        // 0x8015E3F4: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8015E40C;
    }
    goto skip_1;
    // 0x8015E3F4: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_1:
    // 0x8015E3F8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8015E3FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015E400: sh          $t7, 0xB1C($v1)
    MEM_H(0XB1C, ctx->r3) = ctx->r15;
    // 0x8015E404: sw          $zero, 0x184($a0)
    MEM_W(0X184, ctx->r4) = 0;
    // 0x8015E408: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
L_8015E40C:
    // 0x8015E40C: beql        $t8, $zero, L_8015E440
    if (ctx->r24 == 0) {
        // 0x8015E410: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015E440;
    }
    goto skip_2;
    // 0x8015E410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8015E414: lw          $v0, 0x840($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X840);
    // 0x8015E418: beql        $v0, $zero, L_8015E440
    if (ctx->r2 == 0) {
        // 0x8015E41C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015E440;
    }
    goto skip_3;
    // 0x8015E41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8015E420: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8015E424: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8015E428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015E42C: sh          $t9, 0xB1C($v1)
    MEM_H(0XB1C, ctx->r3) = ctx->r25;
    // 0x8015E430: sw          $zero, 0x840($a0)
    MEM_W(0X840, ctx->r4) = 0;
    // 0x8015E434: jal         0x800E8098
    // 0x8015E438: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015E438: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    after_0:
    // 0x8015E43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015E440:
    // 0x8015E440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E444: jr          $ra
    // 0x8015E448: nop

    return;
    // 0x8015E448: nop

;}
RECOMP_FUNC void func_ovl8_80383300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8038330C: jal         0x80371DD0
    // 0x80383310: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    func_ovl8_80371DD0(rdram, ctx);
        goto after_0;
    // 0x80383310: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x80383314: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80383318: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x8038331C: beq         $v1, $zero, L_80383334
    if (ctx->r3 == 0) {
        // 0x80383320: addiu       $v0, $v1, 0x7C
        ctx->r2 = ADD32(ctx->r3, 0X7C);
            goto L_80383334;
    }
    // 0x80383320: addiu       $v0, $v1, 0x7C
    ctx->r2 = ADD32(ctx->r3, 0X7C);
    // 0x80383324: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80383328: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8038332C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80383330: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80383334:
    // 0x80383334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038333C: jr          $ra
    // 0x80383340: nop

    return;
    // 0x80383340: nop

;}
RECOMP_FUNC void itNBumperAttachedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BD4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017BD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BD54: jal         0x8017B8DC
    // 0x8017BD58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itNBumperAttachedInitVars(rdram, ctx);
        goto after_0;
    // 0x8017BD58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017BD5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017BD60: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017BD64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017BD68: jal         0x80172EC8
    // 0x8017BD6C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017BD6C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8017BD70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BD74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BD78: jr          $ra
    // 0x8017BD7C: nop

    return;
    // 0x8017BD7C: nop

;}
RECOMP_FUNC void ftHammerSetStatusHammerWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3938: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F393C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F3940: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F3944: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800F3948: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F394C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F3950: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x800F3954: bne         $t6, $at, L_800F3964
    if (ctx->r14 != ctx->r1) {
        // 0x800F3958: nop
    
            goto L_800F3964;
    }
    // 0x800F3958: nop

    // 0x800F395C: jal         0x800DEE98
    // 0x800F3960: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x800F3960: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_800F3964:
    // 0x800F3964: jal         0x800F3828
    // 0x800F3968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_1;
    // 0x800F3968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F396C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800F3970: jal         0x800F385C
    // 0x800F3974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_2;
    // 0x800F3974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F3978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F397C: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x800F3980: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800F3984: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800F3988: jal         0x800E6F24
    // 0x800F398C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x800F398C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x800F3990: jal         0x800F388C
    // 0x800F3994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_4;
    // 0x800F3994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F3998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F399C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F39A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F39A4: jr          $ra
    // 0x800F39A8: nop

    return;
    // 0x800F39A8: nop

;}
RECOMP_FUNC void itProcessUpdateDamageStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801702C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801702CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801702D0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801702D4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801702D8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801702DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801702E0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801702E4: jal         0x80168128
    // 0x801702E8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x801702E8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_0:
    // 0x801702EC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801702F0: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x801702F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801702F8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x801702FC: bne         $t6, $zero, L_80170320
    if (ctx->r14 != 0) {
        // 0x80170300: lw          $a2, 0x80($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X80);
            goto L_80170320;
    }
    // 0x80170300: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80170304: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80170308: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x8017030C: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80170310: bgezl       $t0, L_80170324
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80170314: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80170324;
    }
    goto skip_0;
    // 0x80170314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80170318: b           L_80170324
    // 0x8017031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80170324;
    // 0x8017031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80170320:
    // 0x80170320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80170324:
    // 0x80170324: beq         $v0, $zero, L_80170334
    if (ctx->r2 == 0) {
        // 0x80170328: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80170334;
    }
    // 0x80170328: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017032C: b           L_80170334
    // 0x80170330: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
        goto L_80170334;
    // 0x80170330: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_80170334:
    // 0x80170334: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80170338: jal         0x8016679C
    // 0x8017033C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x8017033C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80170340: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80170344: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80170348: beq         $v0, $zero, L_80170368
    if (ctx->r2 == 0) {
        // 0x8017034C: or          $a2, $t1, $zero
        ctx->r6 = ctx->r9 | 0;
            goto L_80170368;
    }
    // 0x8017034C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80170350: lw          $t2, 0x238($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X238);
    // 0x80170354: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80170358: beql        $at, $zero, L_80170380
    if (ctx->r1 == 0) {
        // 0x8017035C: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_80170380;
    }
    goto skip_1;
    // 0x8017035C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_1:
    // 0x80170360: b           L_8017037C
    // 0x80170364: sw          $t1, 0x238($s1)
    MEM_W(0X238, ctx->r17) = ctx->r9;
        goto L_8017037C;
    // 0x80170364: sw          $t1, 0x238($s1)
    MEM_W(0X238, ctx->r17) = ctx->r9;
L_80170368:
    // 0x80170368: lw          $t3, 0x234($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X234);
    // 0x8017036C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80170370: beql        $at, $zero, L_80170380
    if (ctx->r1 == 0) {
        // 0x80170374: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_80170380;
    }
    goto skip_2;
    // 0x80170374: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x80170378: sw          $a2, 0x234($s1)
    MEM_W(0X234, ctx->r17) = ctx->r6;
L_8017037C:
    // 0x8017037C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_80170380:
    // 0x80170380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170384: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80170388: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8017038C: bnel        $t5, $at, L_801705A8
    if (ctx->r13 != ctx->r1) {
        // 0x80170390: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_801705A8;
    }
    goto skip_3;
    // 0x80170390: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_3:
    // 0x80170394: lw          $t6, 0x298($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X298);
    // 0x80170398: lw          $t9, 0x290($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X290);
    // 0x8017039C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801703A0: sw          $t8, 0x298($s0)
    MEM_W(0X298, ctx->r16) = ctx->r24;
    // 0x801703A4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x801703A8: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801703AC: beql        $at, $zero, L_801704A0
    if (ctx->r1 == 0) {
        // 0x801703B0: lw          $t5, 0x2D0($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X2D0);
            goto L_801704A0;
    }
    goto skip_4;
    // 0x801703B0: lw          $t5, 0x2D0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2D0);
    skip_4:
    // 0x801703B4: sw          $t0, 0x290($s0)
    MEM_W(0X290, ctx->r16) = ctx->r8;
    // 0x801703B8: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x801703BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801703C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801703C4: lw          $t1, 0x2C($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X2C);
    // 0x801703C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801703CC: sw          $t1, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r9;
    // 0x801703D0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x801703D4: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x801703D8: sw          $t4, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->r12;
    // 0x801703DC: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x801703E0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x801703E4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x801703E8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801703EC: nop

    // 0x801703F0: bc1fl       L_80170404
    if (!c1cs) {
        // 0x801703F4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80170404;
    }
    goto skip_5;
    // 0x801703F4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_5:
    // 0x801703F8: b           L_80170404
    // 0x801703FC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80170404;
    // 0x801703FC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80170400: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80170404:
    // 0x80170404: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80170408: nop

    // 0x8017040C: bc1fl       L_8017044C
    if (!c1cs) {
        // 0x80170410: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8017044C;
    }
    goto skip_6;
    // 0x80170410: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_6:
    // 0x80170414: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x80170418: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8017041C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80170420: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80170424: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80170428: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8017042C: nop

    // 0x80170430: bc1f        L_80170440
    if (!c1cs) {
        // 0x80170434: nop
    
            goto L_80170440;
    }
    // 0x80170434: nop

    // 0x80170438: b           L_80170440
    // 0x8017043C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80170440;
    // 0x8017043C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80170440:
    // 0x80170440: b           L_8017046C
    // 0x80170444: sw          $a3, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r7;
        goto L_8017046C;
    // 0x80170444: sw          $a3, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r7;
    // 0x80170448: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8017044C:
    // 0x8017044C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80170450: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80170454: nop

    // 0x80170458: bc1f        L_80170468
    if (!c1cs) {
        // 0x8017045C: nop
    
            goto L_80170468;
    }
    // 0x8017045C: nop

    // 0x80170460: b           L_80170468
    // 0x80170464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80170468;
    // 0x80170464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80170468:
    // 0x80170468: sw          $v0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r2;
L_8017046C:
    // 0x8017046C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80170470: sw          $t9, 0x2A8($s0)
    MEM_W(0X2A8, ctx->r16) = ctx->r25;
    // 0x80170474: lbu         $t0, 0x10($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X10);
    // 0x80170478: sb          $t0, 0x2AC($s0)
    MEM_B(0X2AC, ctx->r16) = ctx->r8;
    // 0x8017047C: lbu         $t2, 0x11($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X11);
    // 0x80170480: sb          $t2, 0x2AD($s0)
    MEM_B(0X2AD, ctx->r16) = ctx->r10;
    // 0x80170484: lw          $t1, 0x14($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X14);
    // 0x80170488: sw          $t1, 0x2B0($s0)
    MEM_W(0X2B0, ctx->r16) = ctx->r9;
    // 0x8017048C: lbu         $t3, 0x12($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X12);
    // 0x80170490: sb          $t3, 0x2B4($s0)
    MEM_B(0X2B4, ctx->r16) = ctx->r11;
    // 0x80170494: lw          $t4, 0x2BC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2BC);
    // 0x80170498: sw          $t4, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r12;
    // 0x8017049C: lw          $t5, 0x2D0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2D0);
L_801704A0:
    // 0x801704A0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x801704A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801704A8: sll         $t7, $t5, 28
    ctx->r15 = S32(ctx->r13 << 28);
    // 0x801704AC: bgezl       $t7, L_8017050C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801704B0: lw          $t3, 0x260($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X260);
            goto L_8017050C;
    }
    goto skip_7;
    // 0x801704B0: lw          $t3, 0x260($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X260);
    skip_7:
    // 0x801704B4: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x801704B8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x801704BC: lw          $a1, 0x298($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X298);
    // 0x801704C0: lw          $a3, 0x34($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X34);
    // 0x801704C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801704C8: lw          $t0, 0x38($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X38);
    // 0x801704CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801704D0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x801704D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801704D8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801704DC: lbu         $t2, 0x12($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12);
    // 0x801704E0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801704E4: lbu         $t1, 0x16($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X16);
    // 0x801704E8: jal         0x800E9D78
    // 0x801704EC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_2;
    // 0x801704EC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_2:
    // 0x801704F0: lwc1        $f4, 0x294($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X294);
    // 0x801704F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801704F8: nop

    // 0x801704FC: bc1fl       L_8017050C
    if (!c1cs) {
        // 0x80170500: lw          $t3, 0x260($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X260);
            goto L_8017050C;
    }
    goto skip_8;
    // 0x80170500: lw          $t3, 0x260($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X260);
    skip_8:
    // 0x80170504: swc1        $f0, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->f0.u32l;
    // 0x80170508: lw          $t3, 0x260($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X260);
L_8017050C:
    // 0x8017050C: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x80170510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170514: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80170518: beq         $t4, $zero, L_801705A4
    if (ctx->r12 == 0) {
        // 0x8017051C: lw          $a1, 0x6C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X6C);
            goto L_801705A4;
    }
    // 0x8017051C: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80170520: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80170524: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80170528: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8017052C: jal         0x800F0D8C
    // 0x80170530: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    gmCollisionGetWeaponAttackItemDamagePosition(rdram, ctx);
        goto after_3;
    // 0x80170530: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80170534: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80170538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017053C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80170540: lw          $a3, 0xC($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XC);
    // 0x80170544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170548: beq         $a3, $at, L_8017056C
    if (ctx->r7 == ctx->r1) {
        // 0x8017054C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017056C;
    }
    // 0x8017054C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80170550: beq         $a3, $at, L_8017057C
    if (ctx->r7 == ctx->r1) {
        // 0x80170554: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8017057C;
    }
    // 0x80170554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170558: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017055C: beq         $a3, $at, L_8017058C
    if (ctx->r7 == ctx->r1) {
        // 0x80170560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8017058C;
    }
    // 0x80170560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170564: b           L_8017059C
    // 0x80170568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8017059C;
    // 0x80170568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8017056C:
    // 0x8017056C: jal         0x800FE2F4
    // 0x80170570: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80170570: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80170574: b           L_801705A8
    // 0x80170578: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
        goto L_801705A8;
    // 0x80170578: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_8017057C:
    // 0x8017057C: jal         0x800FE4EC
    // 0x80170580: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80170580: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x80170584: b           L_801705A8
    // 0x80170588: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
        goto L_801705A8;
    // 0x80170588: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_8017058C:
    // 0x8017058C: jal         0x80100ACC
    // 0x80170590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_6;
    // 0x80170590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80170594: b           L_801705A8
    // 0x80170598: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
        goto L_801705A8;
    // 0x80170598: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_8017059C:
    // 0x8017059C: jal         0x800FDC04
    // 0x801705A0: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_7;
    // 0x801705A0: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    after_7:
L_801705A4:
    // 0x801705A4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_801705A8:
    // 0x801705A8: jal         0x800269C0
    // 0x801705AC: lhu         $a0, 0x46($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X46);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801705AC: lhu         $a0, 0x46($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X46);
    after_8:
    // 0x801705B0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801705B4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801705B8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801705BC: jr          $ra
    // 0x801705C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801705C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_ovl27_80135BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BFC: jr          $ra
    // 0x80135C00: nop

    return;
    // 0x80135C00: nop

;}
RECOMP_FUNC void func_80016338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001633C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016340: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80016344: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80016348: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001634C: beq         $a2, $zero, L_80016360
    if (ctx->r6 == 0) {
        // 0x80016350: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_80016360;
    }
    // 0x80016350: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80016354: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016358: bnel        $a2, $at, L_8001639C
    if (ctx->r6 != ctx->r1) {
        // 0x8001635C: lui         $t9, 0xDC08
        ctx->r25 = S32(0XDC08 << 16);
            goto L_8001639C;
    }
    goto skip_0;
    // 0x8001635C: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    skip_0:
L_80016360:
    // 0x80016360: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80016364: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80016368: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8001636C: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x80016370: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x80016374: beql        $t6, $zero, L_8001639C
    if (ctx->r14 == 0) {
        // 0x80016378: lui         $t9, 0xDC08
        ctx->r25 = S32(0XDC08 << 16);
            goto L_8001639C;
    }
    goto skip_1;
    // 0x80016378: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    skip_1:
    // 0x8001637C: jal         0x80005344
    // 0x80016380: lhu         $a1, 0x6626($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6626);
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_0;
    // 0x80016380: lhu         $a1, 0x6626($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6626);
    after_0:
    // 0x80016384: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80016388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001638C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016390: sh          $t7, 0x6628($at)
    MEM_H(0X6628, ctx->r1) = ctx->r15;
    // 0x80016394: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x80016398: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
L_8001639C:
    // 0x8001639C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800163A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800163A4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800163A8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800163AC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800163B0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800163B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800163B8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800163BC: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x800163C0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x800163C4: lh          $a3, 0xA($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XA);
    // 0x800163C8: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800163CC: lw          $t1, 0x6678($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6678);
    // 0x800163D0: lw          $t7, -0x46C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X46C8);
    // 0x800163D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800163D8: bgez        $a1, L_800163E4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800163DC: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_800163E4;
    }
    // 0x800163DC: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x800163E0: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_800163E4:
    // 0x800163E4: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800163E8: bgez        $a2, L_800163F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800163EC: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_800163F4;
    }
    // 0x800163EC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x800163F0: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_800163F4:
    // 0x800163F4: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800163F8: subu        $t4, $a1, $a2
    ctx->r12 = SUB32(ctx->r5, ctx->r6);
    // 0x800163FC: bgez        $a3, L_80016408
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80016400: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_80016408;
    }
    // 0x80016400: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x80016404: addiu       $at, $a3, 0x3
    ctx->r1 = ADD32(ctx->r7, 0X3);
L_80016408:
    // 0x80016408: sra         $a3, $at, 2
    ctx->r7 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8001640C: bgez        $t0, L_80016418
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80016410: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_80016418;
    }
    // 0x80016410: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x80016414: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
L_80016418:
    // 0x80016418: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8001641C: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80016420: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80016424: mflo        $t2
    ctx->r10 = lo;
    // 0x80016428: addu        $t6, $t0, $a3
    ctx->r14 = ADD32(ctx->r8, ctx->r7);
    // 0x8001642C: subu        $t5, $a3, $t0
    ctx->r13 = SUB32(ctx->r7, ctx->r8);
    // 0x80016430: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016434: addu        $ra, $a2, $a1
    ctx->r31 = ADD32(ctx->r6, ctx->r5);
    // 0x80016438: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001643C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80016440: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80016444: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80016448: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001644C: mflo        $t3
    ctx->r11 = lo;
    // 0x80016450: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80016454: beq         $at, $zero, L_80016460
    if (ctx->r1 == 0) {
        // 0x80016458: nop
    
            goto L_80016460;
    }
    // 0x80016458: nop

    // 0x8001645C: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
L_80016460:
    // 0x80016460: lw          $v0, 0x667C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X667C);
    // 0x80016464: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80016468: lw          $t8, -0x46D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X46D0);
    // 0x8001646C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80016470: mflo        $a0
    ctx->r4 = lo;
    // 0x80016474: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80016478: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8001647C: multu       $a0, $t8
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016484: mflo        $a1
    ctx->r5 = lo;
    // 0x80016488: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001648C: beq         $at, $zero, L_80016498
    if (ctx->r1 == 0) {
        // 0x80016490: nop
    
            goto L_80016498;
    }
    // 0x80016490: nop

    // 0x80016494: or          $t5, $a1, $zero
    ctx->r13 = ctx->r5 | 0;
L_80016498:
    // 0x80016498: lw          $t9, -0x46C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X46C4);
    // 0x8001649C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800164A0: multu       $t2, $t9
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800164A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800164A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800164AC: subu        $a1, $t1, $t6
    ctx->r5 = SUB32(ctx->r9, ctx->r14);
    // 0x800164B0: slt         $at, $a1, $ra
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r31) ? 1 : 0;
    // 0x800164B4: beq         $at, $zero, L_800164C0
    if (ctx->r1 == 0) {
        // 0x800164B8: nop
    
            goto L_800164C0;
    }
    // 0x800164B8: nop

    // 0x800164BC: or          $ra, $a1, $zero
    ctx->r31 = ctx->r5 | 0;
L_800164C0:
    // 0x800164C0: lw          $t7, -0x46CC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X46CC);
    // 0x800164C4: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800164C8: mflo        $t8
    ctx->r24 = lo;
    // 0x800164CC: subu        $a1, $v0, $t8
    ctx->r5 = SUB32(ctx->r2, ctx->r24);
    // 0x800164D0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800164D4: beql        $at, $zero, L_800164E4
    if (ctx->r1 == 0) {
        // 0x800164D8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800164E4;
    }
    goto skip_2;
    // 0x800164D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_2:
    // 0x800164DC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800164E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_800164E4:
    // 0x800164E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800164E8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800164EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800164F0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800164F4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800164F8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800164FC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80016500: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016504: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80016508: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001650C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80016510: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016514: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016518: mtc1        $ra, $f8
    ctx->f8.u32l = ctx->r31;
    // 0x8001651C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80016520: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80016524: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80016528: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001652C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80016530: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80016534: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80016538: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8001653C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016540: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016544: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80016548: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8001654C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80016550: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80016554: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016558: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001655C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016560: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80016564: nop

    // 0x80016568: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8001656C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80016570: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80016574: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80016578: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001657C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80016580: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80016584: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80016588: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8001658C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80016590: lw          $t6, 0x6674($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6674);
    // 0x80016594: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016598: andi        $t8, $t6, 0x3
    ctx->r24 = ctx->r14 & 0X3;
    // 0x8001659C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800165A0: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x800165A4: sll         $t7, $t8, 19
    ctx->r15 = S32(ctx->r24 << 19);
    // 0x800165A8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800165AC: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800165B0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x800165B4: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800165B8: lui         $t8, 0xF00
    ctx->r24 = S32(0XF00 << 16);
    // 0x800165BC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800165C0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800165C4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800165C8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800165CC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800165D0: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800165D4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800165D8: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800165DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800165E0: beq         $t7, $zero, L_800165F0
    if (ctx->r15 == 0) {
        // 0x800165E4: ori         $t6, $t6, 0x1C
        ctx->r14 = ctx->r14 | 0X1C;
            goto L_800165F0;
    }
    // 0x800165E4: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x800165E8: bne         $t7, $at, L_80016608
    if (ctx->r15 != ctx->r1) {
        // 0x800165EC: lui         $t9, 0xE200
        ctx->r25 = S32(0XE200 << 16);
            goto L_80016608;
    }
    // 0x800165EC: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
L_800165F0:
    // 0x800165F0: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x800165F4: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800165F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800165FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016600: b           L_80016624
    // 0x80016604: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80016624;
    // 0x80016604: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80016608:
    // 0x80016608: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001660C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80016610: ori         $t7, $t7, 0x49D8
    ctx->r15 = ctx->r15 | 0X49D8;
    // 0x80016614: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80016618: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001661C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80016620: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016624:
    // 0x80016624: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80016628: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8001662C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016630: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80016634: jr          $ra
    // 0x80016638: nop

    return;
    // 0x80016638: nop

;}
RECOMP_FUNC void ftManagerMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7F3C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800D7F40: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800D7F44: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800D7F48: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D7F4C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800D7F50: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800D7F54: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800D7F58: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800D7F5C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800D7F60: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800D7F64: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x800D7F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D7F6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800D7F70: jal         0x80009968
    // 0x800D7F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D7F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D7F78: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800D7F7C: lw          $a1, 0x3C($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X3C);
    // 0x800D7F80: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D7F84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D7F88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D7F8C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x800D7F90: jal         0x80009DF4
    // 0x800D7F94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800D7F94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800D7F98: jal         0x800D7594
    // 0x800D7F9C: nop

    ftManagerGetNextStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800D7F9C: nop

    after_2:
    // 0x800D7FA0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800D7FA4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800D7FA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D7FAC: sw          $v0, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r2;
    // 0x800D7FB0: lw          $t7, 0x28($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X28);
    // 0x800D7FB4: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x800D7FB8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800D7FBC: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x800D7FC0: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800D7FC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D7FC8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800D7FCC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800D7FD0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800D7FD4: lw          $t3, 0x6E10($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6E10);
    // 0x800D7FD8: sw          $t3, 0x9C4($v0)
    MEM_W(0X9C4, ctx->r2) = ctx->r11;
    // 0x800D7FDC: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x800D7FE0: lw          $t6, 0x60($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X60);
    // 0x800D7FE4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800D7FE8: addu        $s4, $t5, $t6
    ctx->r20 = ADD32(ctx->r13, ctx->r14);
    // 0x800D7FEC: sw          $s4, 0x9C8($v0)
    MEM_W(0X9C8, ctx->r2) = ctx->r20;
    // 0x800D7FF0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800D7FF4: lw          $t7, 0x38($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X38);
    // 0x800D7FF8: lw          $t3, 0x20($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X20);
    // 0x800D7FFC: sw          $t7, 0x9D0($v0)
    MEM_W(0X9D0, ctx->r2) = ctx->r15;
    // 0x800D8000: lbu         $t8, 0x14($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X14);
    // 0x800D8004: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800D8008: lbu         $t9, 0x15($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X15);
    // 0x800D800C: sb          $t9, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r25;
    // 0x800D8010: lbu         $t2, 0x1B($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X1B);
    // 0x800D8014: beq         $t3, $at, L_800D8048
    if (ctx->r11 == ctx->r1) {
        // 0x800D8018: sb          $t2, 0x14($v0)
        MEM_B(0X14, ctx->r2) = ctx->r10;
            goto L_800D8048;
    }
    // 0x800D8018: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x800D801C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800D8020: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800D8024: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800D8028: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800D802C: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x800D8030: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D8034: lbu         $t4, 0x1B($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X1B);
    // 0x800D8038: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D803C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D8040: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800D8044: sb          $t4, 0x2B($t8)
    MEM_B(0X2B, ctx->r24) = ctx->r12;
L_800D8048:
    // 0x800D8048: lbu         $a0, 0x16($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X16);
    // 0x800D804C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800D8050: sb          $a0, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r4;
    // 0x800D8054: sb          $a0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r4;
    // 0x800D8058: lbu         $t9, 0x17($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X17);
    // 0x800D805C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D8060: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
    // 0x800D8064: lbu         $t2, 0x18($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X18);
    // 0x800D8068: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800D806C: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800D8070: addu        $v1, $s4, $t6
    ctx->r3 = ADD32(ctx->r20, ctx->r14);
    // 0x800D8074: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x800D8078: lbu         $t5, 0xEF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XEF);
    // 0x800D807C: lbu         $t7, 0xEC($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XEC);
    // 0x800D8080: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D8084: mflo        $t4
    ctx->r12 = lo;
    // 0x800D8088: nop

    // 0x800D808C: nop

    // 0x800D8090: div         $zero, $t4, $a1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r5)));
    // 0x800D8094: mflo        $t8
    ctx->r24 = lo;
    // 0x800D8098: sb          $t8, 0xA90($v0)
    MEM_B(0XA90, ctx->r2) = ctx->r24;
    // 0x800D809C: lbu         $t9, 0xEF($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XEF);
    // 0x800D80A0: lbu         $t2, 0xED($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XED);
    // 0x800D80A4: bne         $a1, $zero, L_800D80B0
    if (ctx->r5 != 0) {
        // 0x800D80A8: nop
    
            goto L_800D80B0;
    }
    // 0x800D80A8: nop

    // 0x800D80AC: break       7
    do_break(2148368556);
L_800D80B0:
    // 0x800D80B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D80B4: bne         $a1, $at, L_800D80C8
    if (ctx->r5 != ctx->r1) {
        // 0x800D80B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D80C8;
    }
    // 0x800D80B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D80BC: bne         $t4, $at, L_800D80C8
    if (ctx->r12 != ctx->r1) {
        // 0x800D80C0: nop
    
            goto L_800D80C8;
    }
    // 0x800D80C0: nop

    // 0x800D80C4: break       6
    do_break(2148368580);
L_800D80C8:
    // 0x800D80C8: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D80CC: mflo        $t3
    ctx->r11 = lo;
    // 0x800D80D0: nop

    // 0x800D80D4: nop

    // 0x800D80D8: div         $zero, $t3, $a1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r5)));
    // 0x800D80DC: mflo        $t6
    ctx->r14 = lo;
    // 0x800D80E0: sb          $t6, 0xA91($v0)
    MEM_B(0XA91, ctx->r2) = ctx->r14;
    // 0x800D80E4: lbu         $t7, 0xEE($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XEE);
    // 0x800D80E8: lbu         $t5, 0xEF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XEF);
    // 0x800D80EC: bne         $a1, $zero, L_800D80F8
    if (ctx->r5 != 0) {
        // 0x800D80F0: nop
    
            goto L_800D80F8;
    }
    // 0x800D80F0: nop

    // 0x800D80F4: break       7
    do_break(2148368628);
L_800D80F8:
    // 0x800D80F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D80FC: bne         $a1, $at, L_800D8110
    if (ctx->r5 != ctx->r1) {
        // 0x800D8100: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D8110;
    }
    // 0x800D8100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D8104: bne         $t3, $at, L_800D8110
    if (ctx->r11 != ctx->r1) {
        // 0x800D8108: nop
    
            goto L_800D8110;
    }
    // 0x800D8108: nop

    // 0x800D810C: break       6
    do_break(2148368652);
L_800D8110:
    // 0x800D8110: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D8114: lhu         $t3, 0x18E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X18E);
    // 0x800D8118: lbu         $t5, 0x18D($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X18D);
    // 0x800D811C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D8120: andi        $t6, $t3, 0xFC3F
    ctx->r14 = ctx->r11 & 0XFC3F;
    // 0x800D8124: lbu         $t3, 0x191($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X191);
    // 0x800D8128: andi        $t7, $t5, 0xFFFE
    ctx->r15 = ctx->r13 & 0XFFFE;
    // 0x800D812C: mflo        $t4
    ctx->r12 = lo;
    // 0x800D8130: nop

    // 0x800D8134: nop

    // 0x800D8138: div         $zero, $t4, $a1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r5)));
    // 0x800D813C: mflo        $t8
    ctx->r24 = lo;
    // 0x800D8140: sb          $t8, 0xA92($v0)
    MEM_B(0XA92, ctx->r2) = ctx->r24;
    // 0x800D8144: lbu         $t9, 0x19($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X19);
    // 0x800D8148: bne         $a1, $zero, L_800D8154
    if (ctx->r5 != 0) {
        // 0x800D814C: nop
    
            goto L_800D8154;
    }
    // 0x800D814C: nop

    // 0x800D8150: break       7
    do_break(2148368720);
L_800D8154:
    // 0x800D8154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D8158: bne         $a1, $at, L_800D816C
    if (ctx->r5 != ctx->r1) {
        // 0x800D815C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D816C;
    }
    // 0x800D815C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D8160: bne         $t4, $at, L_800D816C
    if (ctx->r12 != ctx->r1) {
        // 0x800D8164: nop
    
            goto L_800D816C;
    }
    // 0x800D8164: nop

    // 0x800D8168: break       6
    do_break(2148368744);
L_800D816C:
    // 0x800D816C: sb          $t9, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r25;
    // 0x800D8170: lbu         $t2, 0x1A($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X1A);
    // 0x800D8174: sh          $t6, 0x18E($v0)
    MEM_H(0X18E, ctx->r2) = ctx->r14;
    // 0x800D8178: lbu         $t4, 0x18E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X18E);
    // 0x800D817C: lbu         $t9, 0x190($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X190);
    // 0x800D8180: sb          $t2, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r10;
    // 0x800D8184: andi        $t6, $t3, 0xFF7F
    ctx->r14 = ctx->r11 & 0XFF7F;
    // 0x800D8188: andi        $t8, $t4, 0xFF7F
    ctx->r24 = ctx->r12 & 0XFF7F;
    // 0x800D818C: andi        $t2, $t9, 0xFFF7
    ctx->r10 = ctx->r25 & 0XFFF7;
    // 0x800D8190: sw          $zero, 0x178($v0)
    MEM_W(0X178, ctx->r2) = 0;
    // 0x800D8194: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800D8198: sw          $zero, 0x198($v0)
    MEM_W(0X198, ctx->r2) = 0;
    // 0x800D819C: sw          $zero, 0xA10($v0)
    MEM_W(0XA10, ctx->r2) = 0;
    // 0x800D81A0: sh          $zero, 0xA14($v0)
    MEM_H(0XA14, ctx->r2) = 0;
    // 0x800D81A4: sw          $zero, 0xA18($v0)
    MEM_W(0XA18, ctx->r2) = 0;
    // 0x800D81A8: sh          $zero, 0xA1C($v0)
    MEM_H(0XA1C, ctx->r2) = 0;
    // 0x800D81AC: sw          $zero, 0xA20($v0)
    MEM_W(0XA20, ctx->r2) = 0;
    // 0x800D81B0: sh          $zero, 0xA24($v0)
    MEM_H(0XA24, ctx->r2) = 0;
    // 0x800D81B4: sb          $t7, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r15;
    // 0x800D81B8: sb          $t8, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r24;
    // 0x800D81BC: sw          $zero, 0xB4C($v0)
    MEM_W(0XB4C, ctx->r2) = 0;
    // 0x800D81C0: sb          $t2, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r10;
    // 0x800D81C4: sb          $t6, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r14;
    // 0x800D81C8: sw          $zero, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = 0;
    // 0x800D81CC: lbu         $t5, 0x1C($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X1C);
    // 0x800D81D0: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x800D81D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D81D8: sb          $t5, 0x149($v0)
    MEM_B(0X149, ctx->r2) = ctx->r13;
    // 0x800D81DC: lbu         $t7, 0x1E($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X1E);
    // 0x800D81E0: sb          $t4, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r12;
    // 0x800D81E4: lbu         $t5, 0x18E($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X18E);
    // 0x800D81E8: sb          $t7, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r15;
    // 0x800D81EC: lw          $t8, 0x1C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X1C);
    // 0x800D81F0: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x800D81F4: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800D81F8: sll         $t9, $t8, 26
    ctx->r25 = S32(ctx->r24 << 26);
    // 0x800D81FC: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
    // 0x800D8200: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800D8204: andi        $t6, $t3, 0x20
    ctx->r14 = ctx->r11 & 0X20;
    // 0x800D8208: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x800D820C: sb          $t4, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r12;
    // 0x800D8210: lwc1        $f4, 0x94($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X94);
    // 0x800D8214: lbu         $t2, 0x18D($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18D);
    // 0x800D8218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D821C: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x800D8220: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x800D8224: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x800D8228: sb          $t9, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r25;
    // 0x800D822C: sb          $t3, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r11;
    // 0x800D8230: swc1        $f4, 0x860($v0)
    MEM_W(0X860, ctx->r2) = ctx->f4.u32l;
    // 0x800D8234: swc1        $f6, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f6.u32l;
    // 0x800D8238: lw          $t5, 0x324($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X324);
    // 0x800D823C: beql        $t5, $zero, L_800D8258
    if (ctx->r13 == 0) {
        // 0x800D8240: lbu         $t8, 0x18F($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X18F);
            goto L_800D8258;
    }
    goto skip_0;
    // 0x800D8240: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
    skip_0:
    // 0x800D8244: lbu         $t7, 0x18F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18F);
    // 0x800D8248: ori         $t4, $t7, 0x4
    ctx->r12 = ctx->r15 | 0X4;
    // 0x800D824C: b           L_800D8260
    // 0x800D8250: sb          $t4, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r12;
        goto L_800D8260;
    // 0x800D8250: sb          $t4, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r12;
    // 0x800D8254: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
L_800D8258:
    // 0x800D8258: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x800D825C: sb          $t9, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r25;
L_800D8260:
    // 0x800D8260: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D8264: slti        $at, $s0, 0x25
    ctx->r1 = SIGNED(ctx->r16) < 0X25 ? 1 : 0;
    // 0x800D8268: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D826C: bne         $at, $zero, L_800D8260
    if (ctx->r1 != 0) {
        // 0x800D8270: sw          $zero, 0x8E4($v1)
        MEM_W(0X8E4, ctx->r3) = 0;
            goto L_800D8260;
    }
    // 0x800D8270: sw          $zero, 0x8E4($v1)
    MEM_W(0X8E4, ctx->r3) = 0;
    // 0x800D8274: jal         0x800092D0
    // 0x800D8278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x800D8278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800D827C: sw          $v0, 0x8E8($s5)
    MEM_W(0X8E8, ctx->r21) = ctx->r2;
    // 0x800D8280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D8284: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800D8288: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D828C: jal         0x800C89BC
    // 0x800D8290: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_4;
    // 0x800D8290: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800D8294: lw          $t3, 0x8E8($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X8E8);
    // 0x800D8298: lbu         $t2, 0x1D($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X1D);
    // 0x800D829C: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x800D82A0: lw          $t5, 0x58($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X58);
    // 0x800D82A4: addiu       $a3, $s5, 0x8F8
    ctx->r7 = ADD32(ctx->r21, 0X8F8);
    // 0x800D82A8: sb          $t2, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r10;
    // 0x800D82AC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800D82B0: lw          $t7, 0x29C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X29C);
    // 0x800D82B4: lbu         $a2, 0xE($s5)
    ctx->r6 = MEM_BU(ctx->r21, 0XE);
    // 0x800D82B8: lw          $a1, 0x2D4($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X2D4);
    // 0x800D82BC: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x800D82C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D82C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800D82C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D82CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D82D0: lbu         $t8, 0x10($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X10);
    // 0x800D82D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800D82D8: bgez        $t8, L_800D82F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D82DC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D82F0;
    }
    // 0x800D82DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D82E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D82E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D82E8: nop

    // 0x800D82EC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800D82F0:
    // 0x800D82F0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800D82F4: lbu         $t9, 0x149($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X149);
    // 0x800D82F8: jal         0x800C8DB4
    // 0x800D82FC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    lbCommonSetupFighterPartsDObjs(rdram, ctx);
        goto after_5;
    // 0x800D82FC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_5:
    // 0x800D8300: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D8304: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
L_800D8308:
    // 0x800D8308: lw          $t3, 0x8E8($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X8E8);
    // 0x800D830C: beql        $t3, $zero, L_800D83D0
    if (ctx->r11 == 0) {
        // 0x800D8310: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D83D0;
    }
    goto skip_1;
    // 0x800D8310: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800D8314: jal         0x800D7604
    // 0x800D8318: nop

    ftManagerGetNextPartsAlloc(rdram, ctx);
        goto after_6;
    // 0x800D8318: nop

    after_6:
    // 0x800D831C: lw          $t2, 0x8E8($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X8E8);
    // 0x800D8320: sw          $v0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r2;
    // 0x800D8324: lbu         $t7, 0xE($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0XE);
    // 0x800D8328: lw          $t5, 0x8E8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8E8);
    // 0x800D832C: lw          $t6, 0x2D4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X2D4);
    // 0x800D8330: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x800D8334: lw          $s2, 0x84($t5)
    ctx->r18 = MEM_W(ctx->r13, 0X84);
    // 0x800D8338: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x800D833C: lbu         $t9, -0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X4);
    // 0x800D8340: sb          $s0, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r16;
    // 0x800D8344: sb          $t9, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r25;
    // 0x800D8348: lbu         $t3, 0x10($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X10);
    // 0x800D834C: beql        $t3, $zero, L_800D83D0
    if (ctx->r11 == 0) {
        // 0x800D8350: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D83D0;
    }
    goto skip_2;
    // 0x800D8350: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800D8354: lw          $v0, 0x32C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X32C);
    // 0x800D8358: beql        $v0, $zero, L_800D83D0
    if (ctx->r2 == 0) {
        // 0x800D835C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D83D0;
    }
    goto skip_3;
    // 0x800D835C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x800D8360: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800D8364: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D8368: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x800D836C: bne         $s0, $t2, L_800D83CC
    if (ctx->r16 != ctx->r10) {
        // 0x800D8370: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800D83CC;
    }
    // 0x800D8370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D8374: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x800D8378: jal         0x80009968
    // 0x800D837C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_7;
    // 0x800D837C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_7:
    // 0x800D8380: sw          $v0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r2;
    // 0x800D8384: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x800D8388: jal         0x800092D0
    // 0x800D838C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_8;
    // 0x800D838C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x800D8390: lbu         $t7, 0x10($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X10);
    // 0x800D8394: lw          $t5, 0xDC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XDC);
    // 0x800D8398: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x800D839C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800D83A0: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800D83A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D83A8: lw          $a0, 0x74($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X74);
    // 0x800D83AC: bgez        $t7, L_800D83C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D83B0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800D83C4;
    }
    // 0x800D83B0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800D83B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D83B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D83BC: nop

    // 0x800D83C0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800D83C4:
    // 0x800D83C4: jal         0x800C8CB8
    // 0x800D83C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_9;
    // 0x800D83C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
L_800D83CC:
    // 0x800D83CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800D83D0:
    // 0x800D83D0: slti        $at, $s0, 0x25
    ctx->r1 = SIGNED(ctx->r16) < 0X25 ? 1 : 0;
    // 0x800D83D4: bne         $at, $zero, L_800D8308
    if (ctx->r1 != 0) {
        // 0x800D83D8: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800D8308;
    }
    // 0x800D83D8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800D83DC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800D83E0: addiu       $s3, $s5, 0x10
    ctx->r19 = ADD32(ctx->r21, 0X10);
L_800D83E4:
    // 0x800D83E4: lw          $v1, 0x8E8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8E8);
    // 0x800D83E8: beql        $v1, $zero, L_800D8418
    if (ctx->r3 == 0) {
        // 0x800D83EC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D8418;
    }
    goto skip_4;
    // 0x800D83EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x800D83F0: lw          $t4, 0x50($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X50);
    // 0x800D83F4: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800D83F8: addu        $v0, $s5, $t6
    ctx->r2 = ADD32(ctx->r21, ctx->r14);
    // 0x800D83FC: beq         $t4, $zero, L_800D840C
    if (ctx->r12 == 0) {
        // 0x800D8400: addiu       $s4, $zero, -0x1
        ctx->r20 = ADD32(0, -0X1);
            goto L_800D840C;
    }
    // 0x800D8400: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x800D8404: b           L_800D840C
    // 0x800D8408: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_800D840C;
    // 0x800D8408: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800D840C:
    // 0x800D840C: sb          $s4, 0x975($v0)
    MEM_B(0X975, ctx->r2) = ctx->r20;
    // 0x800D8410: sb          $s4, 0x974($v0)
    MEM_B(0X974, ctx->r2) = ctx->r20;
    // 0x800D8414: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800D8418:
    // 0x800D8418: slti        $at, $s0, 0x25
    ctx->r1 = SIGNED(ctx->r16) < 0X25 ? 1 : 0;
    // 0x800D841C: bne         $at, $zero, L_800D83E4
    if (ctx->r1 != 0) {
        // 0x800D8420: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800D83E4;
    }
    // 0x800D8420: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800D8424: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D8428: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800D842C:
    // 0x800D842C: sb          $zero, 0x9BF($v0)
    MEM_B(0X9BF, ctx->r2) = 0;
    // 0x800D8430: lb          $t8, 0x9BF($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X9BF);
    // 0x800D8434: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D8438: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800D843C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800D8440: bne         $at, $zero, L_800D842C
    if (ctx->r1 != 0) {
        // 0x800D8444: sb          $t8, 0x9BC($v0)
        MEM_B(0X9BC, ctx->r2) = ctx->r24;
            goto L_800D842C;
    }
    // 0x800D8444: sb          $t8, 0x9BC($v0)
    MEM_B(0X9BC, ctx->r2) = ctx->r24;
    // 0x800D8448: jal         0x800EB6EC
    // 0x800D844C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    ftParamSetAnimLocks(rdram, ctx);
        goto after_10;
    // 0x800D844C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x800D8450: sb          $zero, 0x1C9($s5)
    MEM_B(0X1C9, ctx->r21) = 0;
    // 0x800D8454: lb          $v0, 0x1C9($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X1C9);
    // 0x800D8458: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D845C: sh          $v1, 0x1BE($s5)
    MEM_H(0X1BE, ctx->r21) = ctx->r3;
    // 0x800D8460: sh          $v1, 0x1BC($s5)
    MEM_H(0X1BC, ctx->r21) = ctx->r3;
    // 0x800D8464: sh          $zero, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = 0;
    // 0x800D8468: sb          $v0, 0x1C8($s5)
    MEM_B(0X1C8, ctx->r21) = ctx->r2;
    // 0x800D846C: sb          $v0, 0x1C5($s5)
    MEM_B(0X1C5, ctx->r21) = ctx->r2;
    // 0x800D8470: sb          $v0, 0x1C4($s5)
    MEM_B(0X1C4, ctx->r21) = ctx->r2;
    // 0x800D8474: sb          $v0, 0x1C3($s5)
    MEM_B(0X1C3, ctx->r21) = ctx->r2;
    // 0x800D8478: sb          $v0, 0x1C2($s5)
    MEM_B(0X1C2, ctx->r21) = ctx->r2;
    // 0x800D847C: lw          $t9, 0x2C($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X2C);
    // 0x800D8480: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x800D8484: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D8488: sw          $t9, 0x1B0($s5)
    MEM_W(0X1B0, ctx->r21) = ctx->r25;
    // 0x800D848C: lhu         $t3, 0x30($s6)
    ctx->r11 = MEM_HU(ctx->r22, 0X30);
    // 0x800D8490: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D8494: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800D8498: sh          $t3, 0x1B4($s5)
    MEM_H(0X1B4, ctx->r21) = ctx->r11;
    // 0x800D849C: lhu         $t2, 0x32($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0X32);
    // 0x800D84A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D84A4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800D84A8: sh          $t2, 0x1B6($s5)
    MEM_H(0X1B6, ctx->r21) = ctx->r10;
    // 0x800D84AC: lhu         $t5, 0x34($s6)
    ctx->r13 = MEM_HU(ctx->r22, 0X34);
    // 0x800D84B0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800D84B4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D84B8: sh          $t5, 0x1B8($s5)
    MEM_H(0X1B8, ctx->r21) = ctx->r13;
    // 0x800D84BC: lhu         $t7, 0x36($s6)
    ctx->r15 = MEM_HU(ctx->r22, 0X36);
    // 0x800D84C0: sb          $a1, 0x268($s5)
    MEM_B(0X268, ctx->r21) = ctx->r5;
    // 0x800D84C4: sb          $a1, 0x269($s5)
    MEM_B(0X269, ctx->r21) = ctx->r5;
    // 0x800D84C8: sb          $a1, 0x26A($s5)
    MEM_B(0X26A, ctx->r21) = ctx->r5;
    // 0x800D84CC: sb          $a1, 0x26B($s5)
    MEM_B(0X26B, ctx->r21) = ctx->r5;
    // 0x800D84D0: addiu       $a3, $zero, 0x1E4
    ctx->r7 = ADD32(0, 0X1E4);
    // 0x800D84D4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D84D8: sh          $t7, 0x1BA($s5)
    MEM_H(0X1BA, ctx->r21) = ctx->r15;
L_800D84DC:
    // 0x800D84DC: lw          $t4, 0x104($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X104);
    // 0x800D84E0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x800D84E4: beql        $t0, $t4, L_800D8584
    if (ctx->r8 == ctx->r12) {
        // 0x800D84E8: sw          $zero, 0x5BC($v0)
        MEM_W(0X5BC, ctx->r2) = 0;
            goto L_800D8584;
    }
    goto skip_5;
    // 0x800D84E8: sw          $zero, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = 0;
    skip_5:
    // 0x800D84EC: sw          $s0, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = ctx->r16;
    // 0x800D84F0: lw          $t8, 0x104($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X104);
    // 0x800D84F4: addiu       $a2, $v1, 0x11C
    ctx->r6 = ADD32(ctx->r3, 0X11C);
    // 0x800D84F8: addiu       $a1, $v0, 0x5DC
    ctx->r5 = ADD32(ctx->r2, 0X5DC);
    // 0x800D84FC: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800D8500: addu        $t2, $s5, $t3
    ctx->r10 = ADD32(ctx->r21, ctx->r11);
    // 0x800D8504: sw          $t8, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = ctx->r24;
    // 0x800D8508: lw          $t5, 0x8E8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8E8);
    // 0x800D850C: sw          $t5, 0x5C4($v0)
    MEM_W(0X5C4, ctx->r2) = ctx->r13;
    // 0x800D8510: lw          $t7, 0x108($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X108);
    // 0x800D8514: sw          $t7, 0x5C8($v0)
    MEM_W(0X5C8, ctx->r2) = ctx->r15;
    // 0x800D8518: lw          $t6, 0x10C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10C);
    // 0x800D851C: sw          $t6, 0x5CC($v0)
    MEM_W(0X5CC, ctx->r2) = ctx->r14;
    // 0x800D8520: lw          $t8, 0x110($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X110);
    // 0x800D8524: sw          $t8, 0x5D0($v0)
    MEM_W(0X5D0, ctx->r2) = ctx->r24;
    // 0x800D8528: lw          $t4, 0x114($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X114);
    // 0x800D852C: sw          $t4, 0x5D4($v0)
    MEM_W(0X5D4, ctx->r2) = ctx->r12;
    // 0x800D8530: lw          $t8, 0x118($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X118);
    // 0x800D8534: sw          $t8, 0x5D8($v0)
    MEM_W(0X5D8, ctx->r2) = ctx->r24;
    // 0x800D8538: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800D853C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800D8540: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800D8544: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800D8548: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x800D854C: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800D8550: lwc1        $f8, 0x5DC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5DC);
    // 0x800D8554: lwc1        $f10, 0x5E0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5E0);
    // 0x800D8558: lwc1        $f6, 0x5E4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5E4);
    // 0x800D855C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D8560: nop

    // 0x800D8564: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D8568: nop

    // 0x800D856C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D8570: swc1        $f16, 0x5DC($v0)
    MEM_W(0X5DC, ctx->r2) = ctx->f16.u32l;
    // 0x800D8574: swc1        $f18, 0x5E0($v0)
    MEM_W(0X5E0, ctx->r2) = ctx->f18.u32l;
    // 0x800D8578: b           L_800D8584
    // 0x800D857C: swc1        $f4, 0x5E4($v0)
    MEM_W(0X5E4, ctx->r2) = ctx->f4.u32l;
        goto L_800D8584;
    // 0x800D857C: swc1        $f4, 0x5E4($v0)
    MEM_W(0X5E4, ctx->r2) = ctx->f4.u32l;
    // 0x800D8580: sw          $zero, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = 0;
L_800D8584:
    // 0x800D8584: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x800D8588: bne         $a0, $a3, L_800D84DC
    if (ctx->r4 != ctx->r7) {
        // 0x800D858C: addiu       $v0, $v0, 0x2C
        ctx->r2 = ADD32(ctx->r2, 0X2C);
            goto L_800D84DC;
    }
    // 0x800D858C: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x800D8590: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8594: addiu       $t7, $s5, 0x44
    ctx->r15 = ADD32(ctx->r21, 0X44);
    // 0x800D8598: addiu       $v0, $s5, 0xB0
    ctx->r2 = ADD32(ctx->r21, 0XB0);
    // 0x800D859C: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x800D85A0: sw          $t7, 0x7C($s5)
    MEM_W(0X7C, ctx->r21) = ctx->r15;
    // 0x800D85A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800D85A8: addiu       $t5, $t2, 0x1C
    ctx->r13 = ADD32(ctx->r10, 0X1C);
    // 0x800D85AC: sw          $t5, 0x78($s5)
    MEM_W(0X78, ctx->r21) = ctx->r13;
    // 0x800D85B0: lw          $t4, 0x9C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X9C);
    // 0x800D85B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D85B8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x800D85BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800D85C0: lw          $t6, 0xA0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XA0);
    // 0x800D85C4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800D85C8: addiu       $a1, $a1, 0x584
    ctx->r5 = ADD32(ctx->r5, 0X584);
    // 0x800D85CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D85D0: lw          $t4, 0xA4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XA4);
    // 0x800D85D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D85D8: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x800D85DC: lw          $t6, 0xA8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XA8);
    // 0x800D85E0: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x800D85E4: sw          $v0, 0xC0($s5)
    MEM_W(0XC0, ctx->r21) = ctx->r2;
    // 0x800D85E8: lw          $t9, 0xAC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XAC);
    // 0x800D85EC: lw          $t2, 0x20($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X20);
    // 0x800D85F0: sw          $t9, 0xC4($s5)
    MEM_W(0XC4, ctx->r21) = ctx->r25;
    // 0x800D85F4: lw          $t8, 0xB0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0XB0);
    // 0x800D85F8: sw          $t0, 0x144($s5)
    MEM_W(0X144, ctx->r21) = ctx->r8;
    // 0x800D85FC: sw          $t8, 0xC8($s5)
    MEM_W(0XC8, ctx->r21) = ctx->r24;
    // 0x800D8600: lhu         $t3, 0x1398($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1398);
    // 0x800D8604: sh          $zero, 0xCE($s5)
    MEM_H(0XCE, ctx->r21) = 0;
    // 0x800D8608: beq         $t2, $at, L_800D86A0
    if (ctx->r10 == ctx->r1) {
        // 0x800D860C: sh          $t3, 0xD4($s5)
        MEM_H(0XD4, ctx->r21) = ctx->r11;
            goto L_800D86A0;
    }
    // 0x800D860C: sh          $t3, 0xD4($s5)
    MEM_H(0XD4, ctx->r21) = ctx->r11;
    // 0x800D8610: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D8614: addiu       $a1, $a1, 0x1260
    ctx->r5 = ADD32(ctx->r5, 0X1260);
    // 0x800D8618: jal         0x80008188
    // 0x800D861C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x800D861C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800D8620: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D8624: addiu       $a1, $a1, 0x2604
    ctx->r5 = ADD32(ctx->r5, 0X2604);
    // 0x800D8628: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D862C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D8630: jal         0x80008188
    // 0x800D8634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_12;
    // 0x800D8634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_12:
    // 0x800D8638: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D863C: addiu       $a1, $a1, 0x2660
    ctx->r5 = ADD32(ctx->r5, 0X2660);
    // 0x800D8640: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D8648: jal         0x80008188
    // 0x800D864C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x800D864C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_13:
    // 0x800D8650: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D8654: addiu       $a1, $a1, 0x6100
    ctx->r5 = ADD32(ctx->r5, 0X6100);
    // 0x800D8658: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D865C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D8660: jal         0x80008188
    // 0x800D8664: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcAddGObjProcess(rdram, ctx);
        goto after_14;
    // 0x800D8664: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x800D8668: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D866C: addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    // 0x800D8670: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D8674: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D8678: jal         0x80008188
    // 0x800D867C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_15;
    // 0x800D867C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x800D8680: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D8684: addiu       $a1, $a1, 0x61EC
    ctx->r5 = ADD32(ctx->r5, 0X61EC);
    // 0x800D8688: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D868C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D8690: jal         0x80008188
    // 0x800D8694: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_16;
    // 0x800D8694: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x800D8698: b           L_800D86AC
    // 0x800D869C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
        goto L_800D86AC;
    // 0x800D869C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_800D86A0:
    // 0x800D86A0: jal         0x80008188
    // 0x800D86A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_17;
    // 0x800D86A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_17:
    // 0x800D86A8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_800D86AC:
    // 0x800D86AC: jal         0x800D79F0
    // 0x800D86B0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    ftManagerInitFighter(rdram, ctx);
        goto after_18;
    // 0x800D86B0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_18:
    // 0x800D86B4: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
    // 0x800D86B8: bnel        $s0, $v0, L_800D86D0
    if (ctx->r16 != ctx->r2) {
        // 0x800D86BC: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_800D86D0;
    }
    goto skip_6;
    // 0x800D86BC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    skip_6:
    // 0x800D86C0: jal         0x8013A8A8
    // 0x800D86C4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftComputerSetupAll(rdram, ctx);
        goto after_19;
    // 0x800D86C4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_19:
    // 0x800D86C8: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
    // 0x800D86CC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_800D86D0:
    // 0x800D86D0: beq         $v1, $v0, L_800D86E0
    if (ctx->r3 == ctx->r2) {
        // 0x800D86D4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800D86E0;
    }
    // 0x800D86D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D86D8: bnel        $v0, $at, L_800D86F0
    if (ctx->r2 != ctx->r1) {
        // 0x800D86DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800D86F0;
    }
    goto skip_7;
    // 0x800D86DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_7:
L_800D86E0:
    // 0x800D86E0: sw          $zero, 0xA98($s5)
    MEM_W(0XA98, ctx->r21) = 0;
    // 0x800D86E4: sw          $zero, 0xA94($s5)
    MEM_W(0XA94, ctx->r21) = 0;
    // 0x800D86E8: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
    // 0x800D86EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800D86F0:
    // 0x800D86F0: beq         $v0, $at, L_800D8708
    if (ctx->r2 == ctx->r1) {
        // 0x800D86F4: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D8708;
    }
    // 0x800D86F4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D86F8: beq         $v0, $v1, L_800D8718
    if (ctx->r2 == ctx->r3) {
        // 0x800D86FC: nop
    
            goto L_800D8718;
    }
    // 0x800D86FC: nop

    // 0x800D8700: b           L_800D872C
    // 0x800D8704: lb          $t7, 0x1F($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X1F);
        goto L_800D872C;
    // 0x800D8704: lb          $t7, 0x1F($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X1F);
L_800D8708:
    // 0x800D8708: jal         0x803905CC
    // 0x800D870C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_20;
    // 0x800D870C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_20:
    // 0x800D8710: b           L_800D8760
    // 0x800D8714: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
        goto L_800D8760;
    // 0x800D8714: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
L_800D8718:
    // 0x800D8718: jal         0x800DEE54
    // 0x800D871C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_21;
    // 0x800D871C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_21:
    // 0x800D8720: b           L_800D8760
    // 0x800D8724: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
        goto L_800D8760;
    // 0x800D8724: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
    // 0x800D8728: lb          $t7, 0x1F($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X1F);
L_800D872C:
    // 0x800D872C: bgez        $t7, L_800D874C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D8730: nop
    
            goto L_800D874C;
    }
    // 0x800D8730: nop

    // 0x800D8734: jal         0x800DEE54
    // 0x800D8738: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_22;
    // 0x800D8738: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_22:
    // 0x800D873C: jal         0x800E7F14
    // 0x800D8740: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftParamLockPlayerControl(rdram, ctx);
        goto after_23;
    // 0x800D8740: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_23:
    // 0x800D8744: b           L_800D8760
    // 0x800D8748: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
        goto L_800D8760;
    // 0x800D8748: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
L_800D874C:
    // 0x800D874C: jal         0x8013D930
    // 0x800D8750: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftCommonEntrySetStatus(rdram, ctx);
        goto after_24;
    // 0x800D8750: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_24:
    // 0x800D8754: jal         0x800E7F14
    // 0x800D8758: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftParamLockPlayerControl(rdram, ctx);
        goto after_25;
    // 0x800D8758: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_25:
    // 0x800D875C: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
L_800D8760:
    // 0x800D8760: beq         $v0, $zero, L_800D8770
    if (ctx->r2 == 0) {
        // 0x800D8764: nop
    
            goto L_800D8770;
    }
    // 0x800D8764: nop

    // 0x800D8768: bnel        $s0, $v0, L_800D8780
    if (ctx->r16 != ctx->r2) {
        // 0x800D876C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800D8780;
    }
    goto skip_8;
    // 0x800D876C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_8:
L_800D8770:
    // 0x800D8770: jal         0x8013AC00
    // 0x800D8774: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftComputerSetFighterDamageDetectSize(rdram, ctx);
        goto after_26;
    // 0x800D8774: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_26:
    // 0x800D8778: lw          $v0, 0x20($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X20);
    // 0x800D877C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800D8780:
    // 0x800D8780: beql        $v0, $at, L_800D87A4
    if (ctx->r2 == ctx->r1) {
        // 0x800D8784: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_800D87A4;
    }
    goto skip_9;
    // 0x800D8784: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_9:
    // 0x800D8788: lw          $t6, 0x1C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X1C);
    // 0x800D878C: sll         $t8, $t6, 25
    ctx->r24 = S32(ctx->r14 << 25);
    // 0x800D8790: bltzl       $t8, L_800D87A4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D8794: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_800D87A4;
    }
    goto skip_10;
    // 0x800D8794: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_10:
    // 0x800D8798: jal         0x8013BB88
    // 0x800D879C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftShadowMakeShadow(rdram, ctx);
        goto after_27;
    // 0x800D879C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_27:
    // 0x800D87A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800D87A4:
    // 0x800D87A4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800D87A8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800D87AC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800D87B0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800D87B4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800D87B8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800D87BC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800D87C0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800D87C4: jr          $ra
    // 0x800D87C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800D87C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ftKirbySpecialNCopyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801623C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801623C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801623CC: jal         0x80161F0C
    // 0x801623D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNCopyInitCopyVars(rdram, ctx);
        goto after_0;
    // 0x801623D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801623D4: jal         0x801622DC
    // 0x801623D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialNCopyUpdateCheckCopyStar(rdram, ctx);
        goto after_1;
    // 0x801623D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801623DC: jal         0x800D94C4
    // 0x801623E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_2;
    // 0x801623E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801623E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801623E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801623EC: jr          $ra
    // 0x801623F0: nop

    return;
    // 0x801623F0: nop

;}
RECOMP_FUNC void mnVSRecordGetAvgAgainst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801353F4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801353F8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801353FC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135400: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135404: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80135408: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8013540C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80135410: addiu       $t9, $t9, 0x44E0
    ctx->r25 = ADD32(ctx->r25, 0X44E0);
    // 0x80135414: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80135418: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8013541C: lhu         $v1, 0x44($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X44);
    // 0x80135420: beql        $v1, $zero, L_80135470
    if (ctx->r3 == 0) {
        // 0x80135424: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80135470;
    }
    goto skip_0;
    // 0x80135424: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80135428: lhu         $t0, 0x2C($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2C);
    // 0x8013542C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80135430: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135434: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80135438: bgez        $t0, L_8013544C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8013543C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8013544C;
    }
    // 0x8013543C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135440: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135444: nop

    // 0x80135448: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8013544C:
    // 0x8013544C: bgez        $v1, L_80135464
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80135450: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80135464;
    }
    // 0x80135450: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80135454: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135458: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013545C: nop

    // 0x80135460: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80135464:
    // 0x80135464: jr          $ra
    // 0x80135468: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    return;
    // 0x80135468: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8013546C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80135470:
    // 0x80135470: nop

    // 0x80135474: jr          $ra
    // 0x80135478: nop

    return;
    // 0x80135478: nop

;}
RECOMP_FUNC void syTaskmanCheckBufferLengths(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B9C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80004BA0: lw          $t6, 0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6630);
    // 0x80004BA4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004BAC: addiu       $t8, $t8, 0x6570
    ctx->r24 = ADD32(ctx->r24, 0X6570);
    // 0x80004BB0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004BB4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80004BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004BBC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80004BC0: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80004BC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80004BC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80004BCC:
    // 0x80004BCC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80004BD0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80004BD4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x80004BD8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80004BDC: addu        $t1, $t9, $a3
    ctx->r9 = ADD32(ctx->r25, ctx->r7);
    // 0x80004BE0: sltu        $at, $t1, $t0
    ctx->r1 = ctx->r9 < ctx->r8 ? 1 : 0;
    // 0x80004BE4: beql        $at, $zero, L_80004C10
    if (ctx->r1 == 0) {
        // 0x80004BE8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80004C10;
    }
    goto skip_0;
    // 0x80004BE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80004BEC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004BF0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80004BF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80004BF8: addiu       $a0, $a0, -0x2910
    ctx->r4 = ADD32(ctx->r4, -0X2910);
    // 0x80004BFC: jal         0x80023624
    // 0x80004C00: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80004C00: subu        $a2, $t0, $a3
    ctx->r6 = SUB32(ctx->r8, ctx->r7);
    after_0:
L_80004C04:
    // 0x80004C04: b           L_80004C04
    pause_self(rdram);
    // 0x80004C08: nop

    // 0x80004C0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80004C10:
    // 0x80004C10: bne         $v1, $a1, L_80004BCC
    if (ctx->r3 != ctx->r5) {
        // 0x80004C14: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80004BCC;
    }
    // 0x80004C14: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80004C18: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80004C1C: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80004C20: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80004C24: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80004C28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004C30: sltu        $at, $t2, $v0
    ctx->r1 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x80004C34: beq         $at, $zero, L_80004C54
    if (ctx->r1 == 0) {
        // 0x80004C38: nop
    
            goto L_80004C54;
    }
    // 0x80004C38: nop

    // 0x80004C3C: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x80004C40: addiu       $a0, $a0, -0x28D8
    ctx->r4 = ADD32(ctx->r4, -0X28D8);
    // 0x80004C44: jal         0x80023624
    // 0x80004C48: subu        $a1, $v0, $t3
    ctx->r5 = SUB32(ctx->r2, ctx->r11);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80004C48: subu        $a1, $v0, $t3
    ctx->r5 = SUB32(ctx->r2, ctx->r11);
    after_1:
L_80004C4C:
    // 0x80004C4C: b           L_80004C4C
    pause_self(rdram);
    // 0x80004C50: nop

L_80004C54:
    // 0x80004C54: jr          $ra
    // 0x80004C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itTosakintoAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E7A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017E7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E7A8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017E7AC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8017E7B0: jal         0x80172558
    // 0x8017E7B4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017E7B4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_0:
    // 0x8017E7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017E7C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E7C4: jr          $ra
    // 0x8017E7C8: nop

    return;
    // 0x8017E7C8: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157EAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157EB4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80157EB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157EBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80157EC0: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x80157EC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157EC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80157ECC: jal         0x800E6F24
    // 0x80157ED0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157ED0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80157ED4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80157ED8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80157EDC: addiu       $t7, $t7, 0x77A0
    ctx->r15 = ADD32(ctx->r15, 0X77A0);
    // 0x80157EE0: sw          $t7, 0x9EC($t8)
    MEM_W(0X9EC, ctx->r24) = ctx->r15;
    // 0x80157EE4: jal         0x800E0830
    // 0x80157EE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80157EE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80157EEC: jal         0x80157E7C
    // 0x80157EF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftKirbyCopyDonkeySpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80157EF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80157EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157EF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157EFC: jr          $ra
    // 0x80157F00: nop

    return;
    // 0x80157F00: nop

;}
RECOMP_FUNC void gmRumbleActorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115298: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8011529C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801152A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801152A4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801152A8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801152AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801152B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801152B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801152B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801152BC: addiu       $s2, $s2, 0x19F0
    ctx->r18 = ADD32(ctx->r18, 0X19F0);
    // 0x801152C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801152C4: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_801152C8:
    // 0x801152C8: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x801152CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801152D0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801152D4: beql        $t7, $zero, L_80115390
    if (ctx->r15 == 0) {
        // 0x801152D8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80115390;
    }
    goto skip_0;
    // 0x801152D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x801152DC: jal         0x80115170
    // 0x801152E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gmRumbleUpdateEventLinks(rdram, ctx);
        goto after_0;
    // 0x801152E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x801152E4: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x801152E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801152EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x801152F0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801152F4: jal         0x801151F4
    // 0x801152F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmRumbleGetMotorUpdateStatus(rdram, ctx);
        goto after_1;
    // 0x801152F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801152FC: bne         $v0, $zero, L_8011538C
    if (ctx->r2 != 0) {
        // 0x80115300: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8011538C;
    }
    // 0x80115300: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80115304: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80115308: jal         0x80114E30
    // 0x8011530C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    gmRumbleUpdateEventExecute(rdram, ctx);
        goto after_2;
    // 0x8011530C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80115310: bnel        $v0, $zero, L_80115338
    if (ctx->r2 != 0) {
        // 0x80115314: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80115338;
    }
    goto skip_1;
    // 0x80115314: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x80115318: lhu         $t8, 0x2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2);
    // 0x8011531C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80115320: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80115324: blez        $v0, L_80115334
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80115328: sh          $t9, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r25;
            goto L_80115334;
    }
    // 0x80115328: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8011532C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80115330: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
L_80115334:
    // 0x80115334: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_80115338:
    // 0x80115338: beql        $s1, $zero, L_80115390
    if (ctx->r17 == 0) {
        // 0x8011533C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80115390;
    }
    goto skip_2;
    // 0x8011533C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x80115340: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80115344:
    // 0x80115344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80115348: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x8011534C: beql        $t1, $zero, L_80115390
    if (ctx->r9 == 0) {
        // 0x80115350: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80115390;
    }
    goto skip_3;
    // 0x80115350: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x80115354: jal         0x80114F98
    // 0x80115358: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmRumbleUpdateEventQueue(rdram, ctx);
        goto after_3;
    // 0x80115358: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8011535C: bnel        $v0, $zero, L_80115384
    if (ctx->r2 != 0) {
        // 0x80115360: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80115384;
    }
    goto skip_4;
    // 0x80115360: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_4:
    // 0x80115364: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x80115368: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8011536C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80115370: blez        $v0, L_80115380
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80115374: sh          $t3, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r11;
            goto L_80115380;
    }
    // 0x80115374: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80115378: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8011537C: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
L_80115380:
    // 0x80115380: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_80115384:
    // 0x80115384: bnel        $s1, $zero, L_80115344
    if (ctx->r17 != 0) {
        // 0x80115388: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80115344;
    }
    goto skip_5;
    // 0x80115388: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_5:
L_8011538C:
    // 0x8011538C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80115390:
    // 0x80115390: bne         $s3, $s4, L_801152C8
    if (ctx->r19 != ctx->r20) {
        // 0x80115394: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_801152C8;
    }
    // 0x80115394: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80115398: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8011539C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801153A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801153A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801153A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801153AC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801153B0: jr          $ra
    // 0x801153B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801153B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSRecordSetIconPositionForColumn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133438: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8013343C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133440: addiu       $t7, $t7, 0x677C
    ctx->r15 = ADD32(ctx->r15, 0X677C);
    // 0x80133444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133448: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013344C: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x80133450: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
L_80133454:
    // 0x80133454: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133458: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8013345C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133460: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133464: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133468: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013346C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133470: bne         $t7, $t0, L_80133454
    if (ctx->r15 != ctx->r8) {
        // 0x80133474: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133454;
    }
    // 0x80133474: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133478: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013347C: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x80133480: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x80133484: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x80133488: beq         $v0, $zero, L_801334A4
    if (ctx->r2 == 0) {
        // 0x8013348C: sll         $t1, $a1, 2
        ctx->r9 = S32(ctx->r5 << 2);
            goto L_801334A4;
    }
    // 0x8013348C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80133490: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133494: beq         $v0, $at, L_801334C8
    if (ctx->r2 == ctx->r1) {
        // 0x80133498: addiu       $t3, $zero, 0x13
        ctx->r11 = ADD32(0, 0X13);
            goto L_801334C8;
    }
    // 0x80133498: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x8013349C: b           L_801334FC
    // 0x801334A0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
        goto L_801334FC;
    // 0x801334A0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
L_801334A4:
    // 0x801334A4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801334A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801334AC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801334B0: lw          $t2, 0x6C28($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6C28);
    // 0x801334B4: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x801334B8: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x801334BC: swc1        $f2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f2.u32l;
    // 0x801334C0: b           L_801334F8
    // 0x801334C4: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
        goto L_801334F8;
    // 0x801334C4: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
L_801334C8:
    // 0x801334C8: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x801334CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801334D0: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x801334D4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801334D8: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x801334DC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801334E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801334E4: lw          $t5, 0x6C88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C88);
    // 0x801334E8: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x801334EC: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x801334F0: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x801334F4: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
L_801334F8:
    // 0x801334F8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
L_801334FC:
    // 0x801334FC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80133500: jal         0x801326EC
    // 0x80133504: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x80133504: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    after_0:
    // 0x80133508: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x8013350C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80133510: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80133514: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80133518: beq         $v0, $zero, L_80133564
    if (ctx->r2 == 0) {
        // 0x8013351C: lwc1        $f12, 0x88($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
            goto L_80133564;
    }
    // 0x8013351C: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80133520: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133524: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80133528: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8013352C: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x80133530: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80133534: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133538: mflo        $t8
    ctx->r24 = lo;
    // 0x8013353C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80133540: nop

    // 0x80133544: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133548: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8013354C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80133550: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
    // 0x80133554: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80133558: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8013355C: b           L_80133590
    // 0x80133560: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
        goto L_80133590;
    // 0x80133560: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
L_80133564:
    // 0x80133564: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133568: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8013356C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133570: swc1        $f12, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f12.u32l;
    // 0x80133574: mflo        $t9
    ctx->r25 = lo;
    // 0x80133578: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8013357C: nop

    // 0x80133580: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80133584: add.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80133588: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013358C: swc1        $f6, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f6.u32l;
L_80133590:
    // 0x80133590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133594: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80133598: jr          $ra
    // 0x8013359C: nop

    return;
    // 0x8013359C: nop

;}
RECOMP_FUNC void func_ovl8_80375BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375BD0: lwl         $t8, 0x0($a0)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r4, 0X0);
    // 0x80375BD4: lwr         $t8, 0x3($a0)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r4, 0X3);
    // 0x80375BD8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375BDC: addiu       $t6, $t6, -0x1050
    ctx->r14 = ADD32(ctx->r14, -0X1050);
    // 0x80375BE0: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x80375BE4: jr          $ra
    // 0x80375BE8: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    return;
    // 0x80375BE8: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
;}
RECOMP_FUNC void func_ovl8_80380920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380920: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80380924: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80380928: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8038092C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80380930: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380934: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80380938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038093C: lw          $s2, 0xAC($a0)
    ctx->r18 = MEM_W(ctx->r4, 0XAC);
    // 0x80380940: lw          $s1, 0x58($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X58);
    // 0x80380944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80380948: lw          $t9, 0x11C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X11C);
    // 0x8038094C: lh          $t6, 0x118($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X118);
    // 0x80380950: jalr        $t9
    // 0x80380954: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80380954: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_0:
    // 0x80380958: jal         0x80380AD0
    // 0x8038095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_80380AD0(rdram, ctx);
        goto after_1;
    // 0x8038095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80380960:
    // 0x80380960: jal         0x8037D384
    // 0x80380964: nop

    func_ovl8_8037D384(rdram, ctx);
        goto after_2;
    // 0x80380964: nop

    after_2:
    // 0x80380968: beq         $v0, $zero, L_80380A70
    if (ctx->r2 == 0) {
        // 0x8038096C: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_80380A70;
    }
    // 0x8038096C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80380970: jal         0x8037D3AC
    // 0x80380974: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    func_ovl8_8037D3AC(rdram, ctx);
        goto after_3;
    // 0x80380974: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    after_3:
    // 0x80380978: beq         $s0, $zero, L_80380984
    if (ctx->r16 == 0) {
        // 0x8038097C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80380984;
    }
    // 0x8038097C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80380980: lw          $s1, 0x20($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X20);
L_80380984:
    // 0x80380984: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    // 0x80380988: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8038098C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80380990: and         $t0, $t7, $t8
    ctx->r8 = ctx->r15 & ctx->r24;
    // 0x80380994: bne         $t0, $zero, L_80380AB4
    if (ctx->r8 != 0) {
        // 0x80380998: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_80380AB4;
    }
    // 0x80380998: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8038099C: beq         $s0, $zero, L_803809A8
    if (ctx->r16 == 0) {
        // 0x803809A0: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_803809A8;
    }
    // 0x803809A0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x803809A4: lw          $s1, 0x20($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X20);
L_803809A8:
    // 0x803809A8: lw          $t2, 0x34($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X34);
    // 0x803809AC: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x803809B0: beq         $t3, $zero, L_803809C0
    if (ctx->r11 == 0) {
        // 0x803809B4: nop
    
            goto L_803809C0;
    }
    // 0x803809B4: nop

    // 0x803809B8: b           L_80380AB4
    // 0x803809BC: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
        goto L_80380AB4;
    // 0x803809BC: sw          $zero, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = 0;
L_803809C0:
    // 0x803809C0: beq         $s0, $zero, L_803809CC
    if (ctx->r16 == 0) {
        // 0x803809C4: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_803809CC;
    }
    // 0x803809C4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x803809C8: lw          $s1, 0x20($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X20);
L_803809CC:
    // 0x803809CC: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x803809D0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x803809D4: and         $v0, $t4, $t5
    ctx->r2 = ctx->r12 & ctx->r13;
    // 0x803809D8: bnel        $v0, $zero, L_80380A00
    if (ctx->r2 != 0) {
        // 0x803809DC: lw          $t8, 0xAC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XAC);
            goto L_80380A00;
    }
    goto skip_0;
    // 0x803809DC: lw          $t8, 0xAC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAC);
    skip_0:
    // 0x803809E0: beq         $s0, $zero, L_803809EC
    if (ctx->r16 == 0) {
        // 0x803809E4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_803809EC;
    }
    // 0x803809E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803809E8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_803809EC:
    // 0x803809EC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x803809F0: and         $t7, $t6, $t9
    ctx->r15 = ctx->r14 & ctx->r25;
    // 0x803809F4: beq         $t7, $zero, L_80380A14
    if (ctx->r15 == 0) {
        // 0x803809F8: nop
    
            goto L_80380A14;
    }
    // 0x803809F8: nop

    // 0x803809FC: lw          $t8, 0xAC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAC);
L_80380A00:
    // 0x80380A00: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x80380A04: bgtz        $t0, L_80380A14
    if (SIGNED(ctx->r8) > 0) {
        // 0x80380A08: sw          $t0, 0xAC($s0)
        MEM_W(0XAC, ctx->r16) = ctx->r8;
            goto L_80380A14;
    }
    // 0x80380A08: sw          $t0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r8;
    // 0x80380A0C: lw          $t2, 0xB0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB0);
    // 0x80380A10: sw          $t2, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r10;
L_80380A14:
    // 0x80380A14: beq         $s0, $zero, L_80380A20
    if (ctx->r16 == 0) {
        // 0x80380A18: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80380A20;
    }
    // 0x80380A18: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80380A1C: lw          $s1, 0x20($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X20);
L_80380A20:
    // 0x80380A20: lw          $t4, 0x3C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X3C);
    // 0x80380A24: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80380A28: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80380A2C: bnel        $t5, $zero, L_80380A54
    if (ctx->r13 != 0) {
        // 0x80380A30: lw          $t8, 0xAC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XAC);
            goto L_80380A54;
    }
    goto skip_1;
    // 0x80380A30: lw          $t8, 0xAC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAC);
    skip_1:
    // 0x80380A34: beq         $s0, $zero, L_80380A40
    if (ctx->r16 == 0) {
        // 0x80380A38: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80380A40;
    }
    // 0x80380A38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380A3C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80380A40:
    // 0x80380A40: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x80380A44: and         $t7, $t6, $t9
    ctx->r15 = ctx->r14 & ctx->r25;
    // 0x80380A48: beql        $t7, $zero, L_80380A74
    if (ctx->r15 == 0) {
        // 0x80380A4C: lw          $t4, 0xAC($s0)
        ctx->r12 = MEM_W(ctx->r16, 0XAC);
            goto L_80380A74;
    }
    goto skip_2;
    // 0x80380A4C: lw          $t4, 0xAC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XAC);
    skip_2:
    // 0x80380A50: lw          $t8, 0xAC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAC);
L_80380A54:
    // 0x80380A54: lw          $t1, 0xB0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB0);
    // 0x80380A58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80380A5C: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80380A60: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80380A64: beq         $at, $zero, L_80380A70
    if (ctx->r1 == 0) {
        // 0x80380A68: sw          $t0, 0xAC($s0)
        MEM_W(0XAC, ctx->r16) = ctx->r8;
            goto L_80380A70;
    }
    // 0x80380A68: sw          $t0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r8;
    // 0x80380A6C: sw          $t3, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r11;
L_80380A70:
    // 0x80380A70: lw          $t4, 0xAC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XAC);
L_80380A74:
    // 0x80380A74: beq         $s2, $t4, L_80380AA4
    if (ctx->r18 == ctx->r12) {
        // 0x80380A78: nop
    
            goto L_80380AA4;
    }
    // 0x80380A78: nop

    // 0x80380A7C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80380A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80380A84: lw          $s1, 0x58($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X58);
    // 0x80380A88: lw          $t9, 0x11C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X11C);
    // 0x80380A8C: lh          $t5, 0x118($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X118);
    // 0x80380A90: jalr        $t9
    // 0x80380A94: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80380A94: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    after_4:
    // 0x80380A98: lw          $s2, 0xAC($s0)
    ctx->r18 = MEM_W(ctx->r16, 0XAC);
    // 0x80380A9C: jal         0x80380AD0
    // 0x80380AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_80380AD0(rdram, ctx);
        goto after_5;
    // 0x80380AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80380AA4:
    // 0x80380AA4: jal         0x8000B1E8
    // 0x80380AA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_6;
    // 0x80380AA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80380AAC: b           L_80380960
    // 0x80380AB0: nop

        goto L_80380960;
    // 0x80380AB0: nop

L_80380AB4:
    // 0x80380AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80380AB8: lw          $v0, 0xAC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAC);
    // 0x80380ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380AC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80380AC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80380AC8: jr          $ra
    // 0x80380ACC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80380ACC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnVSResultsBarProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135B78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80135B7C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80135B80: addiu       $t1, $t1, -0x6484
    ctx->r9 = ADD32(ctx->r9, -0X6484);
    // 0x80135B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135B88: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80135B8C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80135B90: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80135B94: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80135B98: addiu       $t8, $t7, 0xA
    ctx->r24 = ADD32(ctx->r15, 0XA);
    // 0x80135B9C: slti        $at, $t8, 0xBF
    ctx->r1 = SIGNED(ctx->r24) < 0XBF ? 1 : 0;
    // 0x80135BA0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80135BA4: bne         $at, $zero, L_80135BB4
    if (ctx->r1 != 0) {
        // 0x80135BA8: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80135BB4;
    }
    // 0x80135BA8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135BAC: addiu       $t3, $zero, 0xBE
    ctx->r11 = ADD32(0, 0XBE);
    // 0x80135BB0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80135BB4:
    // 0x80135BB4: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80135BB8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135BBC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80135BC0: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80135BC4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80135BC8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80135BCC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80135BD0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80135BD4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135BD8: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80135BDC: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x80135BE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80135BE4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80135BE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80135BEC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80135BF0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135BF4: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x80135BF8: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x80135BFC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80135C00: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80135C04: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80135C08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80135C0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135C10: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x80135C14: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80135C18: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80135C1C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80135C20: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80135C24: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80135C28: jal         0x80006D70
    // 0x80135C2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x80135C2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80135C30: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80135C34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135C38: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x80135C3C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80135C40: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80135C44: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80135C48: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80135C4C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80135C50: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80135C54: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80135C58: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x80135C5C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80135C60: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80135C64: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x80135C68: addiu       $t1, $t1, -0x6484
    ctx->r9 = ADD32(ctx->r9, -0X6484);
    // 0x80135C6C: beq         $a2, $zero, L_80135CBC
    if (ctx->r6 == 0) {
        // 0x80135C70: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_80135CBC;
    }
    // 0x80135C70: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80135C74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80135C78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135C7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135C80: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80135C84: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x80135C88: nop

    // 0x80135C8C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80135C90: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x80135C94: nop

    // 0x80135C98: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x80135C9C: bne         $a2, $zero, L_80135CB4
    if (ctx->r6 != 0) {
        // 0x80135CA0: nop
    
            goto L_80135CB4;
    }
    // 0x80135CA0: nop

    // 0x80135CA4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80135CA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80135CAC: b           L_80135CCC
    // 0x80135CB0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_80135CCC;
    // 0x80135CB0: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_80135CB4:
    // 0x80135CB4: b           L_80135CCC
    // 0x80135CB8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80135CCC;
    // 0x80135CB8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80135CBC:
    // 0x80135CBC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80135CC0: nop

    // 0x80135CC4: bltz        $a2, L_80135CB4
    if (SIGNED(ctx->r6) < 0) {
        // 0x80135CC8: nop
    
            goto L_80135CB4;
    }
    // 0x80135CC8: nop

L_80135CCC:
    // 0x80135CCC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80135CD0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80135CD4: andi        $a2, $a2, 0x3FF
    ctx->r6 = ctx->r6 & 0X3FF;
    // 0x80135CD8: addiu       $t9, $t8, 0x57
    ctx->r25 = ADD32(ctx->r24, 0X57);
    // 0x80135CDC: andi        $t3, $t9, 0x3FF
    ctx->r11 = ctx->r25 & 0X3FF;
    // 0x80135CE0: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x80135CE4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80135CE8: lui         $at, 0x15
    ctx->r1 = S32(0X15 << 16);
    // 0x80135CEC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80135CF0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80135CF4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80135CF8: or          $t7, $a2, $at
    ctx->r15 = ctx->r6 | ctx->r1;
    // 0x80135CFC: or          $t6, $t5, $a2
    ctx->r14 = ctx->r13 | ctx->r6;
    // 0x80135D00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80135D04: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80135D08: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135D0C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80135D10: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x80135D14: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80135D18: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80135D1C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80135D20: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80135D24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80135D28: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x80135D2C: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x80135D30: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80135D34: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80135D38: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x80135D3C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80135D40: jal         0x800CCEAC
    // 0x80135D44: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x80135D44: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_1:
    // 0x80135D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135D4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80135D50: jr          $ra
    // 0x80135D54: nop

    return;
    // 0x80135D54: nop

;}
RECOMP_FUNC void mpCommonRunFighterCollisionDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DF018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF01C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DF020: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DF024: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    // 0x800DF028: jal         0x800DEFBC
    // 0x800DF02C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCopyCollDataStats(rdram, ctx);
        goto after_0;
    // 0x800DF02C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DF030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DF034: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800DF038: jal         0x800DEEF4
    // 0x800DF03C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mpCommonRunDefaultCollision(rdram, ctx);
        goto after_1;
    // 0x800DF03C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800DF040: jal         0x800DEFF8
    // 0x800DF044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonResetCollDataStats(rdram, ctx);
        goto after_2;
    // 0x800DF044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800DF048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF04C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DF050: jr          $ra
    // 0x800DF054: nop

    return;
    // 0x800DF054: nop

;}
RECOMP_FUNC void mvOpeningClashVoidProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80131CD0: addiu       $v0, $v0, 0x2A0C
    ctx->r2 = ADD32(ctx->r2, 0X2A0C);
    // 0x80131CD4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80131CD8: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80131CDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131CE0: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x80131CE4: beq         $at, $zero, L_80131D04
    if (ctx->r1 == 0) {
        // 0x80131CE8: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80131D04;
    }
    // 0x80131CE8: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80131CEC: addiu       $t6, $v1, 0x1E
    ctx->r14 = ADD32(ctx->r3, 0X1E);
    // 0x80131CF0: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80131CF4: bne         $at, $zero, L_80131D04
    if (ctx->r1 != 0) {
        // 0x80131CF8: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_80131D04;
    }
    // 0x80131CF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131CFC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80131D00: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80131D04:
    // 0x80131D04: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131D08: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80131D0C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80131D10: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80131D14: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80131D18: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80131D1C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80131D20: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131D24: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80131D28: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80131D2C: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80131D30: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80131D34: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80131D38: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80131D3C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131D40: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80131D44: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80131D48: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80131D4C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80131D50: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80131D54: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80131D58: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80131D5C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80131D60: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131D64: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80131D68: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80131D6C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80131D70: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80131D74: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80131D78: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80131D7C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80131D80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131D84: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131D88: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80131D8C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80131D90: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80131D94: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80131D98: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80131D9C: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80131DA0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80131DA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80131DA8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131DAC: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80131DB0: lui         $t8, 0xF64D
    ctx->r24 = S32(0XF64D << 16);
    // 0x80131DB4: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80131DB8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80131DBC: ori         $t8, $t8, 0x8398
    ctx->r24 = ctx->r24 | 0X8398;
    // 0x80131DC0: ori         $t9, $t9, 0x8028
    ctx->r25 = ctx->r25 | 0X8028;
    // 0x80131DC4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80131DC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80131DCC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131DD0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80131DD4: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80131DD8: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80131DDC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80131DE0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80131DE4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80131DE8: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80131DEC: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80131DF0: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80131DF4: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80131DF8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80131DFC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80131E00: jr          $ra
    // 0x80131E04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    return;
    // 0x80131E04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132F20: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132F24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132F28: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132F2C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132F30: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132F34: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80132F38: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132F3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132F40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132F44: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132F48: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132F4C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132F50: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132F54: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132F58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132F5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132F60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132F64: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132F68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132F6C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F74: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132F78: jal         0x8000B93C
    // 0x80132F7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132F7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132F80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132F84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F88: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132F8C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132F90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132F94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132F98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132F9C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132FA0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132FA4: jal         0x80007080
    // 0x80132FA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132FA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132FAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132FB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132FB4: jr          $ra
    // 0x80132FB8: nop

    return;
    // 0x80132FB8: nop

;}
RECOMP_FUNC void lbCommonAddTreeDObjsAnimAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C88AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C88B0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C88B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C88B8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800C88BC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800C88C0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800C88C4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800C88C8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C88CC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C88D0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800C88D4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800C88D8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C88DC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C88E0: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800C88E4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800C88E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C88EC: beq         $a0, $zero, L_800C8990
    if (ctx->r4 == 0) {
        // 0x800C88F0: swc1        $f20, 0x78($t6)
        MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
            goto L_800C8990;
    }
    // 0x800C88F0: swc1        $f20, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
    // 0x800C88F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C88F8: lwc1        $f22, 0x5E84($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5E84);
L_800C88FC:
    // 0x800C88FC: beq         $s3, $zero, L_800C892C
    if (ctx->r19 == 0) {
        // 0x800C8900: nop
    
            goto L_800C892C;
    }
    // 0x800C8900: nop

    // 0x800C8904: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x800C8908: beql        $a1, $zero, L_800C8928
    if (ctx->r5 == 0) {
        // 0x800C890C: swc1        $f22, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
            goto L_800C8928;
    }
    goto skip_0;
    // 0x800C890C: swc1        $f22, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
    skip_0:
    // 0x800C8910: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C8914: jal         0x8000BD1C
    // 0x800C8918: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800C8918: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800C891C: b           L_800C892C
    // 0x800C8920: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
        goto L_800C892C;
    // 0x800C8920: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800C8924: swc1        $f22, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
L_800C8928:
    // 0x800C8928: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_800C892C:
    // 0x800C892C: beql        $s4, $zero, L_800C8980
    if (ctx->r20 == 0) {
        // 0x800C8930: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C8980;
    }
    goto skip_1;
    // 0x800C8930: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800C8934: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800C8938: beql        $v0, $zero, L_800C897C
    if (ctx->r2 == 0) {
        // 0x800C893C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800C897C;
    }
    goto skip_2;
    // 0x800C893C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_2:
    // 0x800C8940: lw          $s0, 0x80($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X80);
    // 0x800C8944: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C8948: beql        $s0, $zero, L_800C897C
    if (ctx->r16 == 0) {
        // 0x800C894C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800C897C;
    }
    goto skip_3;
    // 0x800C894C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_3:
    // 0x800C8950: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_800C8954:
    // 0x800C8954: beql        $a1, $zero, L_800C896C
    if (ctx->r5 == 0) {
        // 0x800C8958: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_800C896C;
    }
    goto skip_4;
    // 0x800C8958: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800C895C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C8960: jal         0x8000BD54
    // 0x800C8964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x800C8964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C8968: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_800C896C:
    // 0x800C896C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C8970: bnel        $s0, $zero, L_800C8954
    if (ctx->r16 != 0) {
        // 0x800C8974: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_800C8954;
    }
    goto skip_5;
    // 0x800C8974: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x800C8978: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_800C897C:
    // 0x800C897C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C8980:
    // 0x800C8980: jal         0x800C86E8
    // 0x800C8984: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_2;
    // 0x800C8984: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x800C8988: bne         $v0, $zero, L_800C88FC
    if (ctx->r2 != 0) {
        // 0x800C898C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800C88FC;
    }
    // 0x800C898C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800C8990:
    // 0x800C8990: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C8994: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C8998: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800C899C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C89A0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C89A4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800C89A8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800C89AC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800C89B0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800C89B4: jr          $ra
    // 0x800C89B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C89B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itBatFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174E38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174E3C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174E40: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80174E44: jal         0x80172558
    // 0x80174E48: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174E48: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_0:
    // 0x80174E4C: jal         0x801713F4
    // 0x80174E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80174E50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80174E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174E60: jr          $ra
    // 0x80174E64: nop

    return;
    // 0x80174E64: nop

;}
RECOMP_FUNC void ftCommonFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F9E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013F9E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013F9E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013F9EC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013F9F0: jal         0x800F3794
    // 0x8013F9F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x8013F9F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013F9F8: beql        $v0, $zero, L_8013FA14
    if (ctx->r2 == 0) {
        // 0x8013F9FC: lw          $t6, 0x14C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X14C);
            goto L_8013FA14;
    }
    goto skip_0;
    // 0x8013F9FC: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    skip_0:
    // 0x8013FA00: jal         0x80147C50
    // 0x8013FA04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonHammerFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013FA04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013FA08: b           L_8013FA74
    // 0x8013FA0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8013FA74;
    // 0x8013FA0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013FA10: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
L_8013FA14:
    // 0x8013FA14: bnel        $t6, $zero, L_8013FA28
    if (ctx->r14 != 0) {
        // 0x8013FA18: lw          $t8, 0x9C8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X9C8);
            goto L_8013FA28;
    }
    goto skip_1;
    // 0x8013FA18: lw          $t8, 0x9C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C8);
    skip_1:
    // 0x8013FA1C: jal         0x800DEEC8
    // 0x8013FA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_2;
    // 0x8013FA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013FA24: lw          $t8, 0x9C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C8);
L_8013FA28:
    // 0x8013FA28: lbu         $t7, 0x148($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X148);
    // 0x8013FA2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013FA30: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8013FA34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013FA38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013FA3C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8013FA40: bne         $at, $zero, L_8013FA50
    if (ctx->r1 != 0) {
        // 0x8013FA44: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_8013FA50;
    }
    // 0x8013FA44: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8013FA48: b           L_8013FA54
    // 0x8013FA4C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
        goto L_8013FA54;
    // 0x8013FA4C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
L_8013FA50:
    // 0x8013FA50: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
L_8013FA54:
    // 0x8013FA54: jal         0x800E6F24
    // 0x8013FA58: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x8013FA58: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x8013FA5C: jal         0x800D8EB8
    // 0x8013FA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_4;
    // 0x8013FA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013FA64: lbu         $t2, 0x192($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X192);
    // 0x8013FA68: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x8013FA6C: sb          $t3, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r11;
    // 0x8013FA70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013FA74:
    // 0x8013FA74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013FA78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013FA7C: jr          $ra
    // 0x8013FA80: nop

    return;
    // 0x8013FA80: nop

;}

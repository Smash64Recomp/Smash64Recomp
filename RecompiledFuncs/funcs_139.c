#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x6678
    ctx->r24 = ADD32(ctx->r24, 0X6678);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void sc1PTrainingModeSetPlayDefaultBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190168: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8019016C: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, 0X13A0);
    // 0x80190170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190174: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80190178: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8019017C: jal         0x80020AB4
    // 0x80190180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioPlayBGM(rdram, ctx);
        goto after_0;
    // 0x80190180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80190184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190188: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8019018C: lw          $t7, 0x13A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13A0);
    // 0x80190190: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80190194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80190198: jr          $ra
    // 0x8019019C: sw          $t7, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r15;
    return;
    // 0x8019019C: sw          $t7, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void ifCommonBattleEndSetBossDefeat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011385C: jal         0x8018F6DC
    // 0x80113860: nop

    func_ovl65_8018F6DC(rdram, ctx);
        goto after_0;
    // 0x80113860: nop

    after_0:
    // 0x80113864: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80113868: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8011386C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80113870: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80113874: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80113878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011387C: sh          $zero, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = 0;
    // 0x80113880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113884: jr          $ra
    // 0x80113888: nop

    return;
    // 0x80113888: nop

;}
RECOMP_FUNC void mnItemSwitchSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EFC: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131F00: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80131F04: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80131F08: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131F0C: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131F10: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131F14: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131F18: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80131F1C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x80131F20: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80131F24: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80131F28: jr          $ra
    // 0x80131F2C: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80131F2C: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void mvOpeningFoxInitName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8018D164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D168: sb          $v0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r2;
    // 0x8018D16C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x8018D170: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8018D174: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8018D178: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x8018D17C: sb          $v0, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r2;
    // 0x8018D180: sb          $v0, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r2;
    // 0x8018D184: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8018D188: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x8018D18C: jr          $ra
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void itPowerBlockWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C0D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C0DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C0E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017C0E4: addiu       $a1, $a1, -0x57FC
    ctx->r5 = ADD32(ctx->r5, -0X57FC);
    // 0x8017C0E8: jal         0x80172EC8
    // 0x8017C0EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017C0EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8017C0F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8017C0F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017C0F8: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8017C0FC: sw          $t7, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r15;
    // 0x8017C100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C108: jr          $ra
    // 0x8017C10C: nop

    return;
    // 0x8017C10C: nop

;}
RECOMP_FUNC void syMatrixPersp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B694: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001B698: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B69C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001B6A0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001B6A4: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B6A8: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001B6AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001B6B0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001B6B4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001B6B8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001B6BC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B6C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001B6C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001B6C8: jal         0x8001B4CC
    // 0x8001B6CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspF(rdram, ctx);
        goto after_0;
    // 0x8001B6CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8001B6D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B6D4: jal         0x80019C70
    // 0x8001B6D8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001B6D8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001B6DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001B6E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001B6E4: jr          $ra
    // 0x8001B6E8: nop

    return;
    // 0x8001B6E8: nop

;}
RECOMP_FUNC void func_ovl8_803743D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803743D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803743DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803743E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803743E4: beq         $a2, $a3, L_80374444
    if (ctx->r6 == ctx->r7) {
        // 0x803743E8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80374444;
    }
    // 0x803743E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803743EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x803743F0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x803743F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803743F8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x803743FC: nop

    // 0x80374400: bc1t        L_80374410
    if (c1cs) {
        // 0x80374404: nop
    
            goto L_80374410;
    }
    // 0x80374404: nop

    // 0x80374408: b           L_80374410
    // 0x8037440C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80374410;
    // 0x8037440C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80374410:
    // 0x80374410: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80374414: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80374418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037441C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80374420: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80374424: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80374428: lw          $v1, 0x38($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X38);
    // 0x8037442C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374430: lh          $t9, 0x118($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X118);
    // 0x80374434: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x80374438: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x8037443C: jalr        $t9
    // 0x80374440: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374440: nop

    after_0:
L_80374444:
    // 0x80374444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037444C: jr          $ra
    // 0x80374450: nop

    return;
    // 0x80374450: nop

;}
RECOMP_FUNC void itLGunDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017572C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175734: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175738: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017573C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80175740: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80175744: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80175748: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8017574C: bne         $t6, $zero, L_80175768
    if (ctx->r14 != 0) {
        // 0x80175750: lui         $a3, 0x8017
        ctx->r7 = S32(0X8017 << 16);
            goto L_80175768;
    }
    // 0x80175750: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175754: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80175758: jal         0x80173DF4
    // 0x8017575C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x8017575C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80175760: b           L_80175774
    // 0x80175764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80175774;
    // 0x80175764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175768:
    // 0x80175768: jal         0x80173B24
    // 0x8017576C: addiu       $a3, $a3, 0x5584
    ctx->r7 = ADD32(ctx->r7, 0X5584);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x8017576C: addiu       $a3, $a3, 0x5584
    ctx->r7 = ADD32(ctx->r7, 0X5584);
    after_1:
    // 0x80175770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80175774:
    // 0x80175774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175778: jr          $ra
    // 0x8017577C: nop

    return;
    // 0x8017577C: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151FC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151FC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151FCC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80151FD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151FD4: jal         0x800E6F24
    // 0x80151FD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151FD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151FDC: jal         0x800E0830
    // 0x80151FE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80151FE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151FE4: jal         0x80151FA8
    // 0x80151FE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialLwStartInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80151FE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151FF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151FF4: jr          $ra
    // 0x80151FF8: nop

    return;
    // 0x80151FF8: nop

;}
RECOMP_FUNC void itMapSetGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173F54: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80173F58: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80173F5C: sw          $zero, 0x108($a0)
    MEM_W(0X108, ctx->r4) = 0;
    // 0x80173F60: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80173F64: nop

    // 0x80173F68: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80173F6C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80173F70: jr          $ra
    // 0x80173F74: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80173F74: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void syMatrixTraRotPyrR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB4C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001CB50: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CB54: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CB58: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001CB5C: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001CB60: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001CB64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001CB68: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001CB6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CB70: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CB74: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001CB78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001CB7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001CB80: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001CB84: jal         0x8001CAF8
    // 0x8001CB88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixTraRotPyrRF(rdram, ctx);
        goto after_0;
    // 0x8001CB88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8001CB8C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001CB90: jal         0x80019EA0
    // 0x8001CB94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CB94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001CB98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001CB9C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001CBA0: jr          $ra
    // 0x8001CBA4: nop

    return;
    // 0x8001CBA4: nop

;}
RECOMP_FUNC void func_ovl8_80372360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372360: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80372364: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80372368: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8037236C: addiu       $t1, $a1, 0x3C
    ctx->r9 = ADD32(ctx->r5, 0X3C);
    // 0x80372370: lw          $t0, 0x74($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X74);
L_80372374:
    // 0x80372374: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80372378: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8037237C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80372380: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80372384: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x80372388: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8037238C: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x80372390: bne         $t9, $t1, L_80372374
    if (ctx->r25 != ctx->r9) {
        // 0x80372394: sw          $t8, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->r24;
            goto L_80372374;
    }
    // 0x80372394: sw          $t8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r24;
    // 0x80372398: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8037239C: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x803723A0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x803723A4: jr          $ra
    // 0x803723A8: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    return;
    // 0x803723A8: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
;}
RECOMP_FUNC void ftCommonAttack11SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EA44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014EA48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014EA4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014EA50: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014EA54: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014EA58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014EA5C: jal         0x80146064
    // 0x8014EA60: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014EA60: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014EA64: bne         $v0, $zero, L_8014EAC4
    if (ctx->r2 != 0) {
        // 0x8014EA68: lui         $t7, 0x8015
        ctx->r15 = S32(0X8015 << 16);
            goto L_8014EAC4;
    }
    // 0x8014EA68: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8014EA6C: addiu       $t7, $t7, -0x15FC
    ctx->r15 = ADD32(ctx->r15, -0X15FC);
    // 0x8014EA70: sw          $t7, 0xA0C($s0)
    MEM_W(0XA0C, ctx->r16) = ctx->r15;
    // 0x8014EA74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014EA78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014EA7C: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x8014EA80: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014EA84: jal         0x800E6F24
    // 0x8014EA88: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014EA88: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014EA8C: jal         0x800E0830
    // 0x8014EA90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014EA90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8014EA94: lbu         $t9, 0x18D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014EA98: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8014EA9C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8014EAA0: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8014EAA4: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8014EAA8: sw          $zero, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = 0;
    // 0x8014EAAC: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
    // 0x8014EAB0: sb          $t0, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r8;
    // 0x8014EAB4: sw          $t8, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r24;
    // 0x8014EAB8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8014EABC: lwc1        $f4, 0x6C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8014EAC0: swc1        $f4, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f4.u32l;
L_8014EAC4:
    // 0x8014EAC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014EAC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014EACC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014EAD0: jr          $ra
    // 0x8014EAD4: nop

    return;
    // 0x8014EAD4: nop

;}
RECOMP_FUNC void gmCameraMakePlayerArrowsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E2D4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010E2D8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010E2DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010E2E0: addiu       $t6, $t6, -0x1DAC
    ctx->r14 = ADD32(ctx->r14, -0X1DAC);
    // 0x8010E2E4: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x8010E2E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010E2EC: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8010E2F0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8010E2F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8010E2F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010E2FC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8010E300: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8010E304: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8010E308: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010E30C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010E310: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010E314: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010E318: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010E31C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010E320: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010E324: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x8010E328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E32C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010E330: jal         0x8000B93C
    // 0x8010E334: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010E334: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010E338: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8010E33C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x8010E340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010E344: jal         0x800CD440
    // 0x8010E348: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    lbCommonInitCameraOrtho(rdram, ctx);
        goto after_1;
    // 0x8010E348: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_1:
    // 0x8010E34C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010E350: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E354: lw          $t3, 0x80($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X80);
    // 0x8010E358: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8010E35C: sw          $t4, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r12;
    // 0x8010E360: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E364: sb          $zero, 0x158E($at)
    MEM_B(0X158E, ctx->r1) = 0;
    // 0x8010E368: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010E36C: jr          $ra
    // 0x8010E370: nop

    return;
    // 0x8010E370: nop

;}
RECOMP_FUNC void efManagerDonkeyEntryTaruMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010341C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80103420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103424: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103428: jal         0x800FDAFC
    // 0x8010342C: addiu       $a0, $a0, -0x19AC
    ctx->r4 = ADD32(ctx->r4, -0X19AC);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x8010342C: addiu       $a0, $a0, -0x19AC
    ctx->r4 = ADD32(ctx->r4, -0X19AC);
    after_0:
    // 0x80103430: bne         $v0, $zero, L_80103440
    if (ctx->r2 != 0) {
        // 0x80103434: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80103440;
    }
    // 0x80103434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103438: b           L_80103464
    // 0x8010343C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103464;
    // 0x8010343C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103440:
    // 0x80103440: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80103444: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80103448: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010344C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80103450: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80103454: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80103458: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x8010345C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80103460: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80103464:
    // 0x80103464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010346C: jr          $ra
    // 0x80103470: nop

    return;
    // 0x80103470: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttackSpecialCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0518: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F051C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F0520: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800F0524: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800F0528: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800F052C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800F0530: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F0534: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800F0538: lw          $a0, 0x8E8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8E8);
    // 0x800F053C: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    // 0x800F0540: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x800F0544: jal         0x800EDE00
    // 0x800F0548: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800F0548: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    after_0:
    // 0x800F054C: jal         0x800EDE5C
    // 0x800F0550: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800F0550: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800F0554: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F0558: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800F055C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0560: lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X2C);
    // 0x800F0564: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800F0568: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800F056C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800F0570: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800F0574: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800F0578: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800F057C: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
    // 0x800F0580: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x800F0584: addiu       $t7, $t0, 0x14
    ctx->r15 = ADD32(ctx->r8, 0X14);
    // 0x800F0588: addiu       $t5, $t1, 0x9C
    ctx->r13 = ADD32(ctx->r9, 0X9C);
    // 0x800F058C: addiu       $t8, $t1, 0x90
    ctx->r24 = ADD32(ctx->r9, 0X90);
    // 0x800F0590: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F0594: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800F0598: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800F059C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800F05A0: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F05A4: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800F05A8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800F05AC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800F05B0: jal         0x800EE750
    // 0x800F05B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    gmCollisionTestSphere(rdram, ctx);
        goto after_2;
    // 0x800F05B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x800F05B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F05BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800F05C0: jr          $ra
    // 0x800F05C4: nop

    return;
    // 0x800F05C4: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D7B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D7BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016D7C0: lbu         $t6, 0x2A2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2A2);
    // 0x8016D7C4: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x8016D7C8: bnel        $t7, $zero, L_8016D7DC
    if (ctx->r15 != 0) {
        // 0x8016D7CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D7DC;
    }
    goto skip_0;
    // 0x8016D7CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8016D7D0: jal         0x8016CDC8
    // 0x8016D7D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpLinkBoomerangSetReturnVars(rdram, ctx);
        goto after_0;
    // 0x8016D7D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016D7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016D7DC:
    // 0x8016D7DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016D7E4: jr          $ra
    // 0x8016D7E8: nop

    return;
    // 0x8016D7E8: nop

;}
RECOMP_FUNC void wpDisplayPKThunderProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80167664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80167668: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016766C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80167670: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80167674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80167678: lw          $v1, 0x2BC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2BC);
    // 0x8016767C: lw          $t3, 0x2A0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2A0);
    // 0x80167680: bne         $v1, $at, L_8016776C
    if (ctx->r3 != ctx->r1) {
        // 0x80167684: nop
    
            goto L_8016776C;
    }
    // 0x80167684: nop

    // 0x80167688: jal         0x80167454
    // 0x8016768C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    wpDisplayDrawNormal(rdram, ctx);
        goto after_0;
    // 0x8016768C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_0:
    // 0x80167690: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80167694: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80167698: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8016769C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801676A0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801676A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801676A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801676AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801676B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801676B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801676B8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x801676BC: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x801676C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801676C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801676C8: addiu       $t4, $t4, -0x71F0
    ctx->r12 = ADD32(ctx->r12, -0X71F0);
    // 0x801676CC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801676D0: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x801676D4: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x801676D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801676DC: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x801676E0: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x801676E4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x801676E8: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x801676EC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801676F0: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x801676F4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801676F8: or          $t7, $t5, $t9
    ctx->r15 = ctx->r13 | ctx->r25;
    // 0x801676FC: ori         $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 | 0XFF;
    // 0x80167700: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80167704: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80167708: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8016770C: addiu       $t5, $t5, -0x71E4
    ctx->r13 = ADD32(ctx->r13, -0X71E4);
    // 0x80167710: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80167714: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80167718: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8016771C: addu        $a2, $t1, $t5
    ctx->r6 = ADD32(ctx->r9, ctx->r13);
    // 0x80167720: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80167724: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80167728: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    // 0x8016772C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x80167730: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x80167734: sll         $t4, $t7, 8
    ctx->r12 = S32(ctx->r15 << 8);
    // 0x80167738: or          $t9, $t4, $t5
    ctx->r25 = ctx->r12 | ctx->r13;
    // 0x8016773C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80167740: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x80167744: ori         $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 | 0XFF;
    // 0x80167748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016774C: jal         0x800143FC
    // 0x80167750: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    gcDrawDObjDLLinksForGObj(rdram, ctx);
        goto after_1;
    // 0x80167750: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    after_1:
    // 0x80167754: jal         0x801674B8
    // 0x80167758: nop

    wpDisplayDrawZBuffer(rdram, ctx);
        goto after_2;
    // 0x80167758: nop

    after_2:
    // 0x8016775C: jal         0x801671F0
    // 0x80167760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80167760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80167764: b           L_80167868
    // 0x80167768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80167868;
    // 0x80167768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016776C:
    // 0x8016776C: beq         $v1, $zero, L_80167780
    if (ctx->r3 == 0) {
        // 0x80167770: nop
    
            goto L_80167780;
    }
    // 0x80167770: nop

    // 0x80167774: lw          $t7, 0x100($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X100);
    // 0x80167778: bne         $t7, $zero, L_8016785C
    if (ctx->r15 != 0) {
        // 0x8016777C: nop
    
            goto L_8016785C;
    }
    // 0x8016777C: nop

L_80167780:
    // 0x80167780: jal         0x80167454
    // 0x80167784: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    wpDisplayDrawNormal(rdram, ctx);
        goto after_4;
    // 0x80167784: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_4:
    // 0x80167788: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8016778C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80167790: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80167794: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80167798: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8016779C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801677A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801677A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801677A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801677AC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801677B0: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x801677B4: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x801677B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801677BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801677C0: addiu       $t5, $t5, -0x71F0
    ctx->r13 = ADD32(ctx->r13, -0X71F0);
    // 0x801677C4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801677C8: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x801677CC: addu        $a1, $t1, $t5
    ctx->r5 = ADD32(ctx->r9, ctx->r13);
    // 0x801677D0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801677D4: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x801677D8: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x801677DC: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x801677E0: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x801677E4: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x801677E8: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x801677EC: sll         $t4, $t8, 16
    ctx->r12 = S32(ctx->r24 << 16);
    // 0x801677F0: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x801677F4: ori         $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 | 0XFF;
    // 0x801677F8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801677FC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80167800: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80167804: addiu       $t7, $t7, -0x71E4
    ctx->r15 = ADD32(ctx->r15, -0X71E4);
    // 0x80167808: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8016780C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80167810: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80167814: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x80167818: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8016781C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80167820: lbu         $t9, 0x2($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2);
    // 0x80167824: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x80167828: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x8016782C: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x80167830: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x80167834: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80167838: or          $t5, $t4, $t8
    ctx->r13 = ctx->r12 | ctx->r24;
    // 0x8016783C: ori         $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 | 0XFF;
    // 0x80167840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167844: jal         0x800143FC
    // 0x80167848: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    gcDrawDObjDLLinksForGObj(rdram, ctx);
        goto after_5;
    // 0x80167848: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_5:
    // 0x8016784C: jal         0x801674B8
    // 0x80167850: nop

    wpDisplayDrawZBuffer(rdram, ctx);
        goto after_6;
    // 0x80167850: nop

    after_6:
    // 0x80167854: b           L_80167868
    // 0x80167858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80167868;
    // 0x80167858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016785C:
    // 0x8016785C: jal         0x80166E80
    // 0x80167860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpDisplayHitCollisions(rdram, ctx);
        goto after_7;
    // 0x80167860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80167864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80167868:
    // 0x80167868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016786C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80167870: jr          $ra
    // 0x80167874: nop

    return;
    // 0x80167874: nop

;}
RECOMP_FUNC void alSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F75C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F760: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F764: jal         0x8002F70C
    // 0x8002F768: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    static_5_8002F70C(rdram, ctx);
        goto after_0;
    // 0x8002F768: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_0:
    // 0x8002F76C: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x8002F770: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F774: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8002F778: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8002F77C: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x8002F780: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F784: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002F788: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F78C: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8002F790: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002F794: bne         $a0, $at, L_8002F854
    if (ctx->r4 != ctx->r1) {
        // 0x8002F798: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_8002F854;
    }
    // 0x8002F798: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8002F79C: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x8002F7A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F7A4: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8002F7A8: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8002F7AC: bne         $v0, $at, L_8002F81C
    if (ctx->r2 != ctx->r1) {
        // 0x8002F7B0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8002F81C;
    }
    // 0x8002F7B0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8002F7B4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002F7B8: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x8002F7BC: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8002F7C0: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x8002F7C4: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x8002F7C8: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F7CC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F7D0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8002F7D4: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x8002F7D8: sb          $v0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r2;
    // 0x8002F7DC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F7E0: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F7E4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F7E8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8002F7EC: sb          $a0, 0xB($a3)
    MEM_B(0XB, ctx->r7) = ctx->r4;
    // 0x8002F7F0: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F7F4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F7F8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8002F7FC: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8002F800: sb          $a1, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r5;
    // 0x8002F804: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F808: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F80C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8002F810: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8002F814: b           L_8002F84C
    // 0x8002F818: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
        goto L_8002F84C;
    // 0x8002F818: sb          $a0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r4;
L_8002F81C:
    // 0x8002F81C: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8002F820: bne         $v0, $at, L_8002F84C
    if (ctx->r2 != ctx->r1) {
        // 0x8002F824: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_8002F84C;
    }
    // 0x8002F824: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8002F828: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8002F82C: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8002F830: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x8002F834: sb          $t0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r8;
    // 0x8002F838: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F83C: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F840: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F844: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8002F848: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_8002F84C:
    // 0x8002F84C: b           L_8002F8CC
    // 0x8002F850: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
        goto L_8002F8CC;
    // 0x8002F850: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
L_8002F854:
    // 0x8002F854: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F858: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8002F85C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
    // 0x8002F860: beq         $t6, $zero, L_8002F888
    if (ctx->r14 == 0) {
        // 0x8002F864: sw          $t1, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r9;
            goto L_8002F888;
    }
    // 0x8002F864: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x8002F868: sb          $a1, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r5;
    // 0x8002F86C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F870: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F874: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8002F878: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x8002F87C: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x8002F880: b           L_8002F894
    // 0x8002F884: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
        goto L_8002F894;
    // 0x8002F884: sh          $a1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r5;
L_8002F888:
    // 0x8002F888: lh          $t8, 0x1A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1A);
    // 0x8002F88C: sb          $a0, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r4;
    // 0x8002F890: sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
L_8002F894:
    // 0x8002F894: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x8002F898: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8002F89C: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x8002F8A0: beq         $v0, $at, L_8002F8C8
    if (ctx->r2 == ctx->r1) {
        // 0x8002F8A4: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_8002F8C8;
    }
    // 0x8002F8A4: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x8002F8A8: beql        $v0, $at, L_8002F8CC
    if (ctx->r2 == ctx->r1) {
        // 0x8002F8AC: sb          $zero, 0xA($a3)
        MEM_B(0XA, ctx->r7) = 0;
            goto L_8002F8CC;
    }
    goto skip_0;
    // 0x8002F8AC: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
    skip_0:
    // 0x8002F8B0: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x8002F8B4: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F8B8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8002F8BC: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x8002F8C0: b           L_8002F8CC
    // 0x8002F8C4: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
        goto L_8002F8CC;
    // 0x8002F8C4: sb          $a0, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r4;
L_8002F8C8:
    // 0x8002F8C8: sb          $zero, 0xA($a3)
    MEM_B(0XA, ctx->r7) = 0;
L_8002F8CC:
    // 0x8002F8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F8D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F8D4: jr          $ra
    // 0x8002F8D8: nop

    return;
    // 0x8002F8D8: nop

;}
RECOMP_FUNC void gmCollisionCheckFighterAttackItemDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFC20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800EFC24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EFC28: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800EFC2C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800EFC30: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800EFC34: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x800EFC38: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFC3C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800EFC40: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800EFC44: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x800EFC48: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x800EFC4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EFC50: addiu       $t3, $t8, 0x14
    ctx->r11 = ADD32(ctx->r24, 0X14);
    // 0x800EFC54: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x800EFC58: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x800EFC5C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EFC60: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x800EFC64: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800EFC68: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800EFC6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EFC70: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800EFC74: lw          $t0, 0x74($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X74);
    // 0x800EFC78: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800EFC7C: addiu       $a1, $t1, 0x50
    ctx->r5 = ADD32(ctx->r9, 0X50);
    // 0x800EFC80: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800EFC84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EFC88: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800EFC8C: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x800EFC90: lw          $a2, 0x24($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X24);
    // 0x800EFC94: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800EFC98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800EFC9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800EFCA0: lw          $t4, 0x74($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X74);
    // 0x800EFCA4: addiu       $t5, $t4, 0x40
    ctx->r13 = ADD32(ctx->r12, 0X40);
    // 0x800EFCA8: jal         0x800EE300
    // 0x800EFCAC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    gmCollisionTestRectangle(rdram, ctx);
        goto after_0;
    // 0x800EFCAC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_0:
    // 0x800EFCB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EFCB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800EFCB8: jr          $ra
    // 0x800EFCBC: nop

    return;
    // 0x800EFCBC: nop

;}
RECOMP_FUNC void ftKirbySpecialNCatchSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162BF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162BF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162BF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162BFC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162C00: jal         0x800DEEC8
    // 0x80162C04: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162C04: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162C08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162C0C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162C10: addiu       $a1, $zero, 0x119
    ctx->r5 = ADD32(0, 0X119);
    // 0x80162C14: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162C18: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162C1C: jal         0x800E6F24
    // 0x80162C20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162C20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162C24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162C28: jal         0x800E8098
    // 0x80162C2C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162C2C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162C34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162C38: jr          $ra
    // 0x80162C3C: nop

    return;
    // 0x80162C3C: nop

;}
RECOMP_FUNC void syMatrixRotYawRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CFE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001CFEC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CFF0: jal         0x800303F0
    // 0x8001CFF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CFF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CFF8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CFFC: jal         0x80035CD0
    // 0x8001D000: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D000: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8001D004: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001D008: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D00C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D010: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D018: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8001D01C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8001D020: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8001D024: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8001D028: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x8001D02C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8001D030: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8001D034: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x8001D038: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x8001D03C: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8001D040: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8001D044: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x8001D048: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x8001D04C: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x8001D050: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x8001D054: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x8001D058: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x8001D05C: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x8001D060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D068: jr          $ra
    // 0x8001D06C: nop

    return;
    // 0x8001D06C: nop

;}
RECOMP_FUNC void func_ovl8_80377208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377208: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8037720C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80377210: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80377214: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80377218: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x8037721C: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x80377220: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80377224: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80377228: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8037722C: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x80377230: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80377234: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80377238: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8037723C: jr          $ra
    // 0x80377240: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    return;
    // 0x80377240: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
;}
RECOMP_FUNC void mpProcessRunLWallCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA658: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800DA65C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800DA660: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800DA664: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800DA668: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DA66C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DA670: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DA674: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DA678: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DA67C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DA680: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DA684: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800DA688: jal         0x800D9590
    // 0x800DA68C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    mpProcessSetLastWallCollideRight(rdram, ctx);
        goto after_0;
    // 0x800DA68C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800DA690: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DA694: lw          $t7, 0xDE0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDE0);
    // 0x800DA698: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800DA69C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800DA6A0: blez        $t7, L_800DAA44
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800DA6A4: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_800DAA44;
    }
    // 0x800DA6A4: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x800DA6A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DA6AC: addiu       $v0, $v0, 0xDE8
    ctx->r2 = ADD32(ctx->r2, 0XDE8);
    // 0x800DA6B0: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800DA6B4: addiu       $s7, $s7, 0xDFC
    ctx->r23 = ADD32(ctx->r23, 0XDFC);
    // 0x800DA6B8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800DA6BC: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
    // 0x800DA6C0: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
    // 0x800DA6C4: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
L_800DA6C8:
    // 0x800DA6C8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800DA6CC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA6D0: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x800DA6D4: jal         0x800F4650
    // 0x800DA6D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_1;
    // 0x800DA6D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800DA6DC: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA6E0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DA6E4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DA6E8: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DA6EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DA6F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA6F4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DA6F8: nop

    // 0x800DA6FC: bc1f        L_800DA74C
    if (!c1cs) {
        // 0x800DA700: nop
    
            goto L_800DA74C;
    }
    // 0x800DA700: nop

    // 0x800DA704: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA708: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA70C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA710: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DA714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA718: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA71C: bc1fl       L_800DAA20
    if (!c1cs) {
        // 0x800DA720: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DAA20;
    }
    goto skip_0;
    // 0x800DA720: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x800DA724: jal         0x800F4194
    // 0x800DA728: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_2;
    // 0x800DA728: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800DA72C: beq         $v0, $zero, L_800DAA1C
    if (ctx->r2 == 0) {
        // 0x800DA730: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DAA1C;
    }
    // 0x800DA730: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DA734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DA738: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DA73C: jal         0x800D95A4
    // 0x800DA740: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_3;
    // 0x800DA740: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x800DA744: b           L_800DAA20
    // 0x800DA748: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DAA20;
    // 0x800DA748: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DA74C:
    // 0x800DA74C: jal         0x800F4670
    // 0x800DA750: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    mpCollisionGetLWallEdgeD(rdram, ctx);
        goto after_4;
    // 0x800DA750: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_4:
    // 0x800DA754: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA758: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA75C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DA760: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DA764: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DA768: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DA76C: nop

    // 0x800DA770: bc1fl       L_800DA7C4
    if (!c1cs) {
        // 0x800DA774: lwc1        $f6, 0x0($s6)
        ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DA7C4;
    }
    goto skip_1;
    // 0x800DA774: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800DA778: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA77C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA780: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA784: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DA788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA78C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA790: bc1fl       L_800DAA20
    if (!c1cs) {
        // 0x800DA794: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DAA20;
    }
    goto skip_2;
    // 0x800DA794: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x800DA798: jal         0x800F4194
    // 0x800DA79C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_5;
    // 0x800DA79C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x800DA7A0: beq         $v0, $zero, L_800DAA1C
    if (ctx->r2 == 0) {
        // 0x800DA7A4: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DAA1C;
    }
    // 0x800DA7A4: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DA7A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DA7AC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DA7B0: jal         0x800D95A4
    // 0x800DA7B4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_6;
    // 0x800DA7B4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x800DA7B8: b           L_800DAA20
    // 0x800DA7BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DAA20;
    // 0x800DA7BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800DA7C0: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
L_800DA7C4:
    // 0x800DA7C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA7C8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA7CC: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800DA7D0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DA7D4: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA7D8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DA7DC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DA7E0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DA7E4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA7E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DA7EC: jal         0x800F4194
    // 0x800DA7F0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_7;
    // 0x800DA7F0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800DA7F4: beq         $v0, $zero, L_800DA828
    if (ctx->r2 == 0) {
        // 0x800DA7F8: lwc1        $f18, 0x64($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DA828;
    }
    // 0x800DA7F8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DA7FC: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DA800: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA804: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DA808: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DA80C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DA810: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800DA814: nop

    // 0x800DA818: bc1fl       L_800DA82C
    if (!c1cs) {
        // 0x800DA81C: lwc1        $f8, 0x0($s6)
        ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DA82C;
    }
    goto skip_3;
    // 0x800DA81C: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    skip_3:
    // 0x800DA820: jal         0x800D95A4
    // 0x800DA824: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_8;
    // 0x800DA824: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_8:
L_800DA828:
    // 0x800DA828: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
L_800DA82C:
    // 0x800DA82C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DA830: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA834: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA838: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DA83C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DA840: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA844: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800DA848: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA84C: lwc1        $f16, 0x4($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA850: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DA854: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DA858: jal         0x800F4194
    // 0x800DA85C: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_9;
    // 0x800DA85C: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800DA860: beq         $v0, $zero, L_800DA894
    if (ctx->r2 == 0) {
        // 0x800DA864: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DA894;
    }
    // 0x800DA864: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DA868: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DA86C: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA870: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DA874: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DA878: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DA87C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800DA880: nop

    // 0x800DA884: bc1fl       L_800DA898
    if (!c1cs) {
        // 0x800DA888: lwc1        $f16, 0x0($s6)
        ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DA898;
    }
    goto skip_4;
    // 0x800DA888: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800DA88C: jal         0x800D95A4
    // 0x800DA890: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_10;
    // 0x800DA890: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_10:
L_800DA894:
    // 0x800DA894: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
L_800DA898:
    // 0x800DA898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA89C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DA8A0: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800DA8A4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA8A8: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA8AC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DA8B0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DA8B4: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800DA8B8: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA8BC: jal         0x800F4194
    // 0x800DA8C0: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_11;
    // 0x800DA8C0: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x800DA8C4: beq         $v0, $zero, L_800DA8F8
    if (ctx->r2 == 0) {
        // 0x800DA8C8: lwc1        $f10, 0x64($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DA8F8;
    }
    // 0x800DA8C8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DA8CC: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DA8D0: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA8D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DA8D8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800DA8DC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DA8E0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800DA8E4: nop

    // 0x800DA8E8: bc1f        L_800DA8F8
    if (!c1cs) {
        // 0x800DA8EC: nop
    
            goto L_800DA8F8;
    }
    // 0x800DA8EC: nop

    // 0x800DA8F0: jal         0x800D95A4
    // 0x800DA8F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_12;
    // 0x800DA8F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_12:
L_800DA8F8:
    // 0x800DA8F8: jal         0x800FA518
    // 0x800DA8FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetVertexCountLineID(rdram, ctx);
        goto after_13;
    // 0x800DA8FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x800DA900: blez        $v0, L_800DAA1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800DA904: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DAA1C;
    }
    // 0x800DA904: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DA908: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800DA90C:
    // 0x800DA90C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DA910: jal         0x800FA5E8
    // 0x800DA914: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_14;
    // 0x800DA914: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x800DA918: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DA91C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DA920: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DA924: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DA928: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x800DA92C: nop

    // 0x800DA930: bc1fl       L_800DA978
    if (!c1cs) {
        // 0x800DA934: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DA978;
    }
    goto skip_5;
    // 0x800DA934: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x800DA938: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA93C: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DA940: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800DA944: nop

    // 0x800DA948: bc1fl       L_800DA978
    if (!c1cs) {
        // 0x800DA94C: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DA978;
    }
    goto skip_6;
    // 0x800DA94C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x800DA950: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800DA954: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DA958: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DA95C: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800DA960: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800DA964: div.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DA968: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800DA96C: b           L_800DA9C8
    // 0x800DA970: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_800DA9C8;
    // 0x800DA970: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800DA974: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_800DA978:
    // 0x800DA978: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DA97C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DA980: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800DA984: nop

    // 0x800DA988: bc1fl       L_800DAA10
    if (!c1cs) {
        // 0x800DA98C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DAA10;
    }
    goto skip_7;
    // 0x800DA98C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800DA990: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA994: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DA998: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x800DA99C: nop

    // 0x800DA9A0: bc1fl       L_800DAA10
    if (!c1cs) {
        // 0x800DA9A4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DAA10;
    }
    goto skip_8;
    // 0x800DA9A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x800DA9A8: sub.s       $f16, $f14, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800DA9AC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DA9B0: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DA9B4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800DA9B8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DA9BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800DA9C0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800DA9C4: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800DA9C8:
    // 0x800DA9C8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DA9CC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DA9D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA9D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DA9D8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800DA9DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA9E0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DA9E4: bc1fl       L_800DAA10
    if (!c1cs) {
        // 0x800DA9E8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DAA10;
    }
    goto skip_9;
    // 0x800DA9E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800DA9EC: jal         0x800F4194
    // 0x800DA9F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_15;
    // 0x800DA9F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x800DA9F4: beq         $v0, $zero, L_800DAA0C
    if (ctx->r2 == 0) {
        // 0x800DA9F8: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DAA0C;
    }
    // 0x800DA9F8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DA9FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DAA00: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DAA04: jal         0x800D95A4
    // 0x800DAA08: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_16;
    // 0x800DAA08: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_16:
L_800DAA0C:
    // 0x800DAA0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800DAA10:
    // 0x800DAA10: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DAA14: bnel        $at, $zero, L_800DA90C
    if (ctx->r1 != 0) {
        // 0x800DAA18: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800DA90C;
    }
    goto skip_10;
    // 0x800DAA18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_10:
L_800DAA1C:
    // 0x800DAA1C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DAA20:
    // 0x800DAA20: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800DAA24: lw          $t0, 0xDE0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XDE0);
    // 0x800DAA28: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800DAA2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DAA30: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DAA34: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DAA38: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800DAA3C: bne         $at, $zero, L_800DA6C8
    if (ctx->r1 != 0) {
        // 0x800DAA40: sw          $v0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r2;
            goto L_800DA6C8;
    }
    // 0x800DAA40: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_800DAA44:
    // 0x800DAA44: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800DAA48: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800DAA4C: addiu       $a1, $t1, 0xA0
    ctx->r5 = ADD32(ctx->r9, 0XA0);
    // 0x800DAA50: addiu       $a2, $t1, 0xA4
    ctx->r6 = ADD32(ctx->r9, 0XA4);
    // 0x800DAA54: jal         0x800D95E0
    // 0x800DAA58: addiu       $a3, $t1, 0xA8
    ctx->r7 = ADD32(ctx->r9, 0XA8);
    mpProcessGetLastWallCollideStats(rdram, ctx);
        goto after_17;
    // 0x800DAA58: addiu       $a3, $t1, 0xA8
    ctx->r7 = ADD32(ctx->r9, 0XA8);
    after_17:
    // 0x800DAA5C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DAA60: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DAA64: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800DAA68: nop

    // 0x800DAA6C: bc1fl       L_800DAA7C
    if (!c1cs) {
        // 0x800DAA70: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800DAA7C;
    }
    goto skip_11;
    // 0x800DAA70: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_11:
    // 0x800DAA74: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x800DAA78: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800DAA7C:
    // 0x800DAA7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DAA80: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DAA84: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DAA88: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DAA8C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DAA90: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DAA94: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DAA98: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800DAA9C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800DAAA0: jr          $ra
    // 0x800DAAA4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800DAAA4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ftMarioSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015647C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156480: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156484: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80156488: jal         0x80156418
    // 0x8015648C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMarioSpecialHiInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x8015648C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80156490: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80156494: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80156498: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8015649C: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801564A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801564A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801564A8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801564AC: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x801564B0: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x801564B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801564B8: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x801564BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801564C0: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x801564C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801564C8: jal         0x800E6F24
    // 0x801564CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801564CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801564D0: jal         0x800E0830
    // 0x801564D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801564D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801564D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801564DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801564E0: jr          $ra
    // 0x801564E4: nop

    return;
    // 0x801564E4: nop

;}
RECOMP_FUNC void itLGunHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801755FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175604: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80175608: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017560C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175610: addiu       $a1, $a1, -0x647C
    ctx->r5 = ADD32(ctx->r5, -0X647C);
    // 0x80175614: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80175618: jal         0x80172EC8
    // 0x8017561C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017561C: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80175620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175628: jr          $ra
    // 0x8017562C: nop

    return;
    // 0x8017562C: nop

;}
RECOMP_FUNC void mnSoundTestMakeBFunctionSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E60: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132E64: lw          $t6, 0x4478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4478);
    // 0x80132E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132E6C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E74: addiu       $t7, $t7, 0x1208
    ctx->r15 = ADD32(ctx->r15, 0X1208);
    // 0x80132E78: jal         0x800CCFDC
    // 0x80132E7C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132E7C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132E80: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80132E84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E88: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x80132E8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132E90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132E94: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80132E98: addiu       $t0, $zero, 0x6B
    ctx->r8 = ADD32(0, 0X6B);
    // 0x80132E9C: addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // 0x80132EA0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132EA4: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132EA8: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132EAC: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132EB0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132EB4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132EC0: jr          $ra
    // 0x80132EC4: nop

    return;
    // 0x80132EC4: nop

;}
RECOMP_FUNC void itStarRodWeaponStarMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178474: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178478: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8017847C: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80178480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80178484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178488: bne         $t6, $at, L_801784A0
    if (ctx->r14 != ctx->r1) {
        // 0x8017848C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_801784A0;
    }
    // 0x8017848C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80178490: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80178494: addiu       $t7, $t7, 0x508
    ctx->r15 = ADD32(ctx->r15, 0X508);
    // 0x80178498: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017849C: sw          $t7, -0x5E30($at)
    MEM_W(-0X5E30, ctx->r1) = ctx->r15;
L_801784A0:
    // 0x801784A0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801784A4: addiu       $a1, $a1, -0x5E3C
    ctx->r5 = ADD32(ctx->r5, -0X5E3C);
    // 0x801784A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801784AC: jal         0x801655C8
    // 0x801784B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x801784B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801784B4: lbu         $a1, 0x2B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2B);
    // 0x801784B8: bne         $v0, $zero, L_801784C8
    if (ctx->r2 != 0) {
        // 0x801784BC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_801784C8;
    }
    // 0x801784BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x801784C0: b           L_80178584
    // 0x801784C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80178584;
    // 0x801784C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801784C8:
    // 0x801784C8: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801784CC: bne         $a1, $zero, L_801784E4
    if (ctx->r5 != 0) {
        // 0x801784D0: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_801784E4;
    }
    // 0x801784D0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801784D4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801784D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801784DC: b           L_801784F4
    // 0x801784E0: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
        goto L_801784F4;
    // 0x801784E0: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
L_801784E4:
    // 0x801784E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801784E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801784EC: nop

    // 0x801784F0: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
L_801784F4:
    // 0x801784F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801784F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801784FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80178500: nop

    // 0x80178504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80178508: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017850C: bne         $a1, $zero, L_80178530
    if (ctx->r5 != 0) {
        // 0x80178510: swc1        $f8, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
            goto L_80178530;
    }
    // 0x80178510: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x80178514: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80178518: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017851C: nop

    // 0x80178520: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80178524: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80178528: b           L_80178548
    // 0x8017852C: sw          $t0, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r8;
        goto L_80178548;
    // 0x8017852C: sw          $t0, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r8;
L_80178530:
    // 0x80178530: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80178534: nop

    // 0x80178538: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8017853C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80178540: nop

    // 0x80178544: sw          $t2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r10;
L_80178548:
    // 0x80178548: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8017854C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80178550: jal         0x80008CC0
    // 0x80178554: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80178554: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80178558: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017855C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80178560: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178564: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80178568: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017856C: sw          $t5, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r13;
    // 0x80178570: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80178574: sw          $t4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r12;
    // 0x80178578: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8017857C: sw          $t5, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r13;
    // 0x80178580: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
L_80178584:
    // 0x80178584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017858C: jr          $ra
    // 0x80178590: nop

    return;
    // 0x80178590: nop

;}
RECOMP_FUNC void efManagerReflectBreakMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010155C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101568: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010156C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80101570: jal         0x800FDAFC
    // 0x80101574: addiu       $a0, $a0, -0x1E54
    ctx->r4 = ADD32(ctx->r4, -0X1E54);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101574: addiu       $a0, $a0, -0x1E54
    ctx->r4 = ADD32(ctx->r4, -0X1E54);
    after_0:
    // 0x80101578: bne         $v0, $zero, L_80101588
    if (ctx->r2 != 0) {
        // 0x8010157C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101588;
    }
    // 0x8010157C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101580: b           L_801015C4
    // 0x80101584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801015C4;
    // 0x80101584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101588:
    // 0x80101588: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010158C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80101590: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80101594: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80101598: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8010159C: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x801015A0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801015A4: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x801015A8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801015AC: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x801015B0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801015B4: bne         $t9, $at, L_801015C4
    if (ctx->r25 != ctx->r1) {
        // 0x801015B8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801015C4;
    }
    // 0x801015B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801015BC: lwc1        $f4, 0x9D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9D8);
    // 0x801015C0: swc1        $f4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f4.u32l;
L_801015C4:
    // 0x801015C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801015C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801015CC: jr          $ra
    // 0x801015D0: nop

    return;
    // 0x801015D0: nop

;}
RECOMP_FUNC void lbRelocGetForceStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD6FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD704: jal         0x800CD698
    // 0x800CD708: nop

    lbRelocFindForceStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CD708: nop

    after_0:
    // 0x800CD70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD714: jr          $ra
    // 0x800CD718: nop

    return;
    // 0x800CD718: nop

;}
RECOMP_FUNC void mnPlayersVSMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801343B0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801343B4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801343B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801343BC: addiu       $t6, $t6, -0x48A4
    ctx->r14 = ADD32(ctx->r14, -0X48A4);
    // 0x801343C0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801343C4: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x801343C8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801343CC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801343D0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801343D4: addiu       $t9, $t9, -0x489C
    ctx->r25 = ADD32(ctx->r25, -0X489C);
    // 0x801343D8: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x801343DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801343E0: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x801343E4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801343E8: addiu       $t1, $t1, -0x4258
    ctx->r9 = ADD32(ctx->r9, -0X4258);
    // 0x801343EC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801343F0: lhu         $t3, 0x4($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X4);
    // 0x801343F4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x801343F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x801343FC: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x80134400: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134404: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x80134408: addiu       $t4, $zero, 0x1A
    ctx->r12 = ADD32(0, 0X1A);
    // 0x8013440C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80134410: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80134414: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80134418: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8013441C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80134420: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80134424: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80134428: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013442C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80134430: lw          $t2, -0x3B50($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3B50);
    // 0x80134434: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80134438: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013443C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80134440: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80134444: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80134448: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8013444C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80134450: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80134454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013445C: jal         0x800CD050
    // 0x80134460: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80134460: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_0:
    // 0x80134464: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80134468: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013446C: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80134470: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80134474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134478: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x8013447C: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80134480: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134484: addiu       $t1, $t1, -0x4258
    ctx->r9 = ADD32(ctx->r9, -0X4258);
    // 0x80134488: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x8013448C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134490: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80134494: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x80134498: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x8013449C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801344A0: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x801344A4: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801344A8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801344AC: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    // 0x801344B0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801344B4: sh          $t3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r11;
    // 0x801344B8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x801344BC: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x801344C0: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801344C4: mflo        $t5
    ctx->r13 = lo;
    // 0x801344C8: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x801344CC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x801344D0: sb          $t7, 0x28($t8)
    MEM_B(0X28, ctx->r24) = ctx->r15;
    // 0x801344D4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x801344D8: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801344DC: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801344E0: mflo        $t2
    ctx->r10 = lo;
    // 0x801344E4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801344E8: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x801344EC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801344F0: sb          $t4, 0x29($t5)
    MEM_B(0X29, ctx->r13) = ctx->r12;
    // 0x801344F4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x801344F8: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801344FC: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134500: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134504: mflo        $t7
    ctx->r15 = lo;
    // 0x80134508: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8013450C: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x80134510: sb          $t9, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r25;
    // 0x80134514: lw          $t3, -0x4254($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4254);
    // 0x80134518: sw          $v0, -0x4250($at)
    MEM_W(-0X4250, ctx->r1) = ctx->r2;
    // 0x8013451C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134520: bne         $t3, $at, L_8013453C
    if (ctx->r11 != ctx->r1) {
        // 0x80134524: nop
    
            goto L_8013453C;
    }
    // 0x80134524: nop

    // 0x80134528: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013452C: jal         0x80133FAC
    // 0x80134530: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    mnPlayersVSMakeTimeSelect(rdram, ctx);
        goto after_1;
    // 0x80134530: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    after_1:
    // 0x80134534: b           L_80134544
    // 0x80134538: nop

        goto L_80134544;
    // 0x80134538: nop

L_8013453C:
    // 0x8013453C: jal         0x80134198
    // 0x80134540: lw          $a0, -0x4280($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4280);
    mnPlayersVSMakeStockSelect(rdram, ctx);
        goto after_2;
    // 0x80134540: lw          $a0, -0x4280($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4280);
    after_2:
L_80134544:
    // 0x80134544: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134548: lw          $t7, -0x3B60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3B60);
    // 0x8013454C: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80134550: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80134554: addiu       $t8, $t8, 0x15C8
    ctx->r24 = ADD32(ctx->r24, 0X15C8);
    // 0x80134558: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013455C: addiu       $t5, $zero, 0x1A
    ctx->r13 = ADD32(0, 0X1A);
    // 0x80134560: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134564: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134568: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013456C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80134570: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80134574: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80134578: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8013457C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80134580: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80134584: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80134588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013458C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134590: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80134594: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80134598: jal         0x800CD050
    // 0x8013459C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_3;
    // 0x8013459C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x801345A0: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801345A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801345A8: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x801345AC: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801345B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801345B4: swc1        $f8, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f8.u32l;
    // 0x801345B8: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801345BC: swc1        $f10, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f10.u32l;
    // 0x801345C0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801345C4: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801345C8: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801345CC: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801345D0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801345D4: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x801345D8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801345DC: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801345E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801345E4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801345E8: jr          $ra
    // 0x801345EC: nop

    return;
    // 0x801345EC: nop

;}
RECOMP_FUNC void dbCubeFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FDC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80131FE0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80131FE4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131FE8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FF0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80131FF4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80131FF8: addiu       $t8, $t8, 0x3140
    ctx->r24 = ADD32(ctx->r24, 0X3140);
    // 0x80131FFC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80132000: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80132004: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80132008: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8013200C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80132010: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132014: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132018: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8013201C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80132020: jal         0x800CDF78
    // 0x80132024: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132024: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132028: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013202C: addiu       $a1, $a1, 0x1E00
    ctx->r5 = ADD32(ctx->r5, 0X1E00);
    // 0x80132030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132038: jal         0x80009968
    // 0x8013203C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8013203C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132040: jal         0x80018994
    // 0x80132044: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80132044: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_2:
    // 0x80132048: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8013204C: jal         0x80018994
    // 0x80132050: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80132050: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_3:
    // 0x80132054: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132058: jal         0x80018994
    // 0x8013205C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    syUtilsRandIntRange(rdram, ctx);
        goto after_4;
    // 0x8013205C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_4:
    // 0x80132060: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80132064: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80132068: sll         $t0, $v0, 8
    ctx->r8 = S32(ctx->r2 << 8);
    // 0x8013206C: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80132070: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80132074: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80132078: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8013207C: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x80132080: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132088: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8013208C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132090: jal         0x8000B9FC
    // 0x80132094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80132098: jal         0x80131F28
    // 0x8013209C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dbCubeMakeCamera(rdram, ctx);
        goto after_6;
    // 0x8013209C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x801320A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801320A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801320A8: addiu       $a1, $a1, 0x2B68
    ctx->r5 = ADD32(ctx->r5, 0X2B68);
    // 0x801320AC: jal         0x80131EA0
    // 0x801320B0: addiu       $a0, $a0, 0x1B24
    ctx->r4 = ADD32(ctx->r4, 0X1B24);
    dbCubeMakeGObj(rdram, ctx);
        goto after_7;
    // 0x801320B0: addiu       $a0, $a0, 0x1B24
    ctx->r4 = ADD32(ctx->r4, 0X1B24);
    after_7:
    // 0x801320B4: jal         0x800D4404
    // 0x801320B8: nop

    lbTransitionSetupTransition(rdram, ctx);
        goto after_8;
    // 0x801320B8: nop

    after_8:
    // 0x801320BC: lui         $a0, 0x2000
    ctx->r4 = S32(0X2000 << 16);
    // 0x801320C0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801320C4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801320C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801320CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801320D0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801320D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801320D8: jal         0x800D4130
    // 0x801320DC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    lbTransitionMakeCamera(rdram, ctx);
        goto after_9;
    // 0x801320DC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_9:
    // 0x801320E0: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x801320E4: addiu       $t0, $t0, 0x42C8
    ctx->r8 = ADD32(ctx->r8, 0X42C8);
    // 0x801320E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801320EC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x801320F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801320F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801320F8: addiu       $a3, $a3, 0x4248
    ctx->r7 = ADD32(ctx->r7, 0X4248);
    // 0x801320FC: lw          $a0, 0x2D84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D84);
    // 0x80132100: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80132104: lui         $a1, 0x2000
    ctx->r5 = S32(0X2000 << 16);
    // 0x80132108: jal         0x800D430C
    // 0x8013210C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    lbTransitionMakeTransition(rdram, ctx);
        goto after_10;
    // 0x8013210C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80132110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132114: jal         0x8000BB04
    // 0x80132118: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    gcSetAnimSpeed(rdram, ctx);
        goto after_11;
    // 0x80132118: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_11:
    // 0x8013211C: jal         0x801156E4
    // 0x80132120: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_12;
    // 0x80132120: nop

    after_12:
    // 0x80132124: jal         0x80369EE0
    // 0x80132128: nop

    dbMenuInitMenu(rdram, ctx);
        goto after_13;
    // 0x80132128: nop

    after_13:
    // 0x8013212C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132130: addiu       $a0, $a0, 0x1D00
    ctx->r4 = ADD32(ctx->r4, 0X1D00);
    // 0x80132134: jal         0x80131EA0
    // 0x80132138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    dbCubeMakeGObj(rdram, ctx);
        goto after_14;
    // 0x80132138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8013213C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132140: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80132144: jr          $ra
    // 0x80132148: nop

    return;
    // 0x80132148: nop

;}
RECOMP_FUNC void ftKirbySpecialNEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162B58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162B5C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162B60: jal         0x800DEEC8
    // 0x80162B64: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162B64: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162B68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162B6C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162B70: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x80162B74: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162B78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162B7C: jal         0x800E6F24
    // 0x80162B80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162B80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162B84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162B88: jal         0x800E8098
    // 0x80162B8C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162B8C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162B94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162B98: jr          $ra
    // 0x80162B9C: nop

    return;
    // 0x80162B9C: nop

;}
RECOMP_FUNC void func_ovl8_8038612C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038612C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80386130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80386134: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80386138: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8038613C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80386140: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80386144: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80386148: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8038614C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80386150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80386154: jal         0x803863A4
    // 0x80386158: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    func_ovl8_803863A4(rdram, ctx);
        goto after_0;
    // 0x80386158: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x8038615C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80386160: addiu       $t9, $v0, -0x1D2C
    ctx->r25 = ADD32(ctx->r2, -0X1D2C);
    // 0x80386164: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80386168: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038616C: addiu       $a1, $a1, -0x1DF8
    ctx->r5 = ADD32(ctx->r5, -0X1DF8);
    // 0x80386170: addiu       $t6, $t6, -0x1A74
    ctx->r14 = ADD32(ctx->r14, -0X1A74);
    // 0x80386174: sw          $t6, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r14;
    // 0x80386178: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8038617C: addiu       $t1, $t9, 0x24
    ctx->r9 = ADD32(ctx->r25, 0X24);
L_80386180:
    // 0x80386180: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80386184: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80386188: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8038618C: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80386190: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x80386194: sw          $t7, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r15;
    // 0x80386198: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8038619C: bne         $t9, $t1, L_80386180
    if (ctx->r25 != ctx->r9) {
        // 0x803861A0: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80386180;
    }
    // 0x803861A0: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x803861A4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x803861A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x803861AC: jal         0x803864CC
    // 0x803861B0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    func_ovl8_803864CC(rdram, ctx);
        goto after_1;
    // 0x803861B0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_1:
    // 0x803861B4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803861B8: addiu       $a0, $a0, -0x1E20
    ctx->r4 = ADD32(ctx->r4, -0X1E20);
    // 0x803861BC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x803861C0: jal         0x80381C80
    // 0x803861C4: sw          $s1, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r17;
    func_ovl8_80381C80(rdram, ctx);
        goto after_2;
    // 0x803861C4: sw          $s1, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r17;
    after_2:
    // 0x803861C8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803861CC: addiu       $v1, $v1, 0x3C0
    ctx->r3 = ADD32(ctx->r3, 0X3C0);
    // 0x803861D0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x803861D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x803861D8: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x803861DC: jal         0x8037481C
    // 0x803861E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_ovl8_8037481C(rdram, ctx);
        goto after_3;
    // 0x803861E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x803861E4: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x803861E8: addiu       $s0, $s0, 0x3C8
    ctx->r16 = ADD32(ctx->r16, 0X3C8);
    // 0x803861EC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803861F0: beq         $t2, $s1, L_8038620C
    if (ctx->r10 == ctx->r17) {
        // 0x803861F4: nop
    
            goto L_8038620C;
    }
    // 0x803861F4: nop

L_803861F8:
    // 0x803861F8: jal         0x8000B1E8
    // 0x803861FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x803861FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80386200: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80386204: bne         $t3, $s1, L_803861F8
    if (ctx->r11 != ctx->r17) {
        // 0x80386208: nop
    
            goto L_803861F8;
    }
    // 0x80386208: nop

L_8038620C:
    // 0x8038620C: jal         0x8038649C
    // 0x80386210: nop

    func_ovl8_8038649C(rdram, ctx);
        goto after_5;
    // 0x80386210: nop

    after_5:
    // 0x80386214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80386218: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8038621C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80386220: jr          $ra
    // 0x80386224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80386224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80384C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384C14: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384C18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384C1C: lh          $a1, 0x3C($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X3C);
    // 0x80384C20: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80384C24: lh          $t6, 0xD0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD0);
    // 0x80384C28: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80384C2C: jalr        $t9
    // 0x80384C30: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384C30: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80384C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384C3C: jr          $ra
    // 0x80384C40: nop

    return;
    // 0x80384C40: nop

;}
RECOMP_FUNC void mvOpeningNewcomersInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132388: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013238C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132390: lhu         $t6, 0x4938($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4938);
    // 0x80132394: sw          $zero, 0x2748($at)
    MEM_W(0X2748, ctx->r1) = 0;
    // 0x80132398: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013239C: jr          $ra
    // 0x801323A0: sh          $t6, 0x2750($at)
    MEM_H(0X2750, ctx->r1) = ctx->r14;
    return;
    // 0x801323A0: sh          $t6, 0x2750($at)
    MEM_H(0X2750, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mnMapsLoadMapFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132B8C: addiu       $t7, $t7, 0x44E4
    ctx->r15 = ADD32(ctx->r15, 0X44E4);
    // 0x80132B90: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80132B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B98: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80132B9C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80132BA0: jal         0x800CDDD8
    // 0x80132BA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    lbRelocGetForceExternHeapFile(rdram, ctx);
        goto after_0;
    // 0x80132BA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80132BA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80132BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132BB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BB4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80132BB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132BBC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80132BC0: jr          $ra
    // 0x80132BC4: sw          $t9, 0x4C10($at)
    MEM_W(0X4C10, ctx->r1) = ctx->r25;
    return;
    // 0x80132BC4: sw          $t9, 0x4C10($at)
    MEM_W(0X4C10, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void itBombHeiWalkProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801777D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801777DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801777E0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801777E4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801777E8: addiu       $a1, $a1, 0x75E8
    ctx->r5 = ADD32(ctx->r5, 0X75E8);
    // 0x801777EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801777F0: jal         0x801735A0
    // 0x801777F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x801777F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801777F8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801777FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80177800: lhu         $v0, 0x8E($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X8E);
    // 0x80177804: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80177808: beql        $t8, $zero, L_80177824
    if (ctx->r24 == 0) {
        // 0x8017780C: andi        $t0, $v0, 0x20
        ctx->r8 = ctx->r2 & 0X20;
            goto L_80177824;
    }
    goto skip_0;
    // 0x8017780C: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
    skip_0:
    // 0x80177810: jal         0x80177104
    // 0x80177814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_1;
    // 0x80177814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80177818: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017781C: lhu         $v0, 0x8E($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X8E);
    // 0x80177820: andi        $t0, $v0, 0x20
    ctx->r8 = ctx->r2 & 0X20;
L_80177824:
    // 0x80177824: beq         $t0, $zero, L_80177834
    if (ctx->r8 == 0) {
        // 0x80177828: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80177834;
    }
    // 0x80177828: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017782C: jal         0x80177104
    // 0x80177830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_2;
    // 0x80177830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80177834:
    // 0x80177834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017783C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177840: jr          $ra
    // 0x80177844: nop

    return;
    // 0x80177844: nop

;}
RECOMP_FUNC void mnBackupClearEjectOptionConfirmGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013212C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132130: jal         0x80009A84
    // 0x80132134: lw          $a0, 0x30C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C8);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132134: lw          $a0, 0x30C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C8);
    after_0:
    // 0x80132138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013213C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132140: jr          $ra
    // 0x80132144: nop

    return;
    // 0x80132144: nop

;}
RECOMP_FUNC void gcMakeModelGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B82C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000B830: jal         0x80009968
    // 0x8000B834: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8000B834: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x8000B838: bne         $v0, $zero, L_8000B848
    if (ctx->r2 != 0) {
        // 0x8000B83C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000B848;
    }
    // 0x8000B83C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B840: b           L_8000B8A8
    // 0x8000B844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B8A8;
    // 0x8000B844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B848:
    // 0x8000B848: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B84C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B850: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8000B854: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B858: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8000B85C: jal         0x80009DF4
    // 0x8000B860: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8000B860: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8000B864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B868: jal         0x800092D0
    // 0x8000B86C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8000B86C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8000B870: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B874: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000B878: beql        $t7, $zero, L_8000B88C
    if (ctx->r15 == 0) {
        // 0x8000B87C: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_8000B88C;
    }
    goto skip_0;
    // 0x8000B87C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8000B880: jal         0x8000B3EC
    // 0x8000B884: nop

    gcAddDObjMatrixSetsRpyD(rdram, ctx);
        goto after_3;
    // 0x8000B884: nop

    after_3:
    // 0x8000B888: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
L_8000B88C:
    // 0x8000B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B890: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x8000B894: beql        $a1, $zero, L_8000B8A8
    if (ctx->r5 == 0) {
        // 0x8000B898: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8000B8A8;
    }
    goto skip_1;
    // 0x8000B898: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_1:
    // 0x8000B89C: jal         0x80008188
    // 0x8000B8A0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8000B8A0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x8000B8A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8000B8A8:
    // 0x8000B8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B8AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B8B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000B8B4: jr          $ra
    // 0x8000B8B8: nop

    return;
    // 0x8000B8B8: nop

;}
RECOMP_FUNC void syUtilsRandFloat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018948: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001894C: lw          $v1, -0x46BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X46BC);
    // 0x80018950: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80018954: ori         $at, $at, 0x43FD
    ctx->r1 = ctx->r1 | 0X43FD;
    // 0x80018958: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001895C: multu       $v0, $at
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018960: lui         $at, 0x26
    ctx->r1 = S32(0X26 << 16);
    // 0x80018964: ori         $at, $at, 0x9EC3
    ctx->r1 = ctx->r1 | 0X9EC3;
    // 0x80018968: mflo        $v0
    ctx->r2 = lo;
    // 0x8001896C: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x80018970: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80018974: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80018978: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001897C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80018980: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018984: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018988: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001898C: jr          $ra
    // 0x80018990: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x80018990: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
;}
RECOMP_FUNC void ifCommonPlayerMagnifyProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801111A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801111A4: lbu         $t6, 0x1580($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1580);
    // 0x801111A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801111AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801111B0: beq         $t6, $zero, L_80111430
    if (ctx->r14 == 0) {
        // 0x801111B4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80111430;
    }
    // 0x801111B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801111B8: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x801111BC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801111C0: addiu       $t9, $t9, 0x1748
    ctx->r25 = ADD32(ctx->r25, 0X1748);
    // 0x801111C4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x801111C8: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x801111CC: lw          $v0, 0x18($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X18);
    // 0x801111D0: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801111D4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801111D8: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x801111DC: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x801111E0: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x801111E4: lwc1        $f14, 0x1A8($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1A8);
    // 0x801111E8: lwc1        $f12, 0x1AC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1AC);
    // 0x801111EC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801111F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801111F4: jal         0x8001863C
    // 0x801111F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x801111F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801111FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80111200: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80111204: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80111208: lwc1        $f8, 0xC6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC6C);
    // 0x8011120C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80111210: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80111214: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80111218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011121C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80111220: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80111224: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80111228: lwc1        $f16, 0x1584($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1584);
    // 0x8011122C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80111230: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80111234: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80111238: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x8011123C: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80111240: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80111244: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x80111248: addiu       $t3, $t3, 0x14B0
    ctx->r11 = ADD32(ctx->r11, 0X14B0);
    // 0x8011124C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80111250: swc1        $f2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f2.u32l;
    // 0x80111254: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x80111258: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x8011125C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111260: lw          $t5, 0x74($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X74);
    // 0x80111264: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80111268: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8011126C: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x80111270: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80111274: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80111278: lw          $t7, 0x20($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X20);
    // 0x8011127C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111280: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80111284: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80111288: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8011128C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80111290: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80111294: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80111298: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8011129C: nop

    // 0x801112A0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801112A4: lw          $t9, 0x24($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X24);
    // 0x801112A8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x801112AC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801112B0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801112B4: nop

    // 0x801112B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801112BC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801112C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801112C4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801112C8: nop

    // 0x801112CC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x801112D0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x801112D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801112D8: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    // 0x801112DC: lw          $t8, 0x2C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X2C);
    // 0x801112E0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801112E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801112E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801112EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801112F0: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x801112F4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801112F8: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801112FC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80111300: nop

    // 0x80111304: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80111308: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8011130C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80111310: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80111314: nop

    // 0x80111318: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8011131C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80111320: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80111324: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111328: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x8011132C: ori         $t7, $t7, 0x7
    ctx->r15 = ctx->r15 | 0X7;
    // 0x80111330: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80111334: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80111338: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8011133C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80111340: lw          $t8, 0x6A58($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A58);
    // 0x80111344: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x80111348: lw          $t6, 0x68($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X68);
    // 0x8011134C: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x80111350: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x80111354: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80111358: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8011135C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111360: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80111364: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80111368: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8011136C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80111370: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80111374: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111378: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8011137C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80111380: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80111384: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80111388: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8011138C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80111390: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80111394: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80111398: ori         $t6, $t6, 0x2048
    ctx->r14 = ctx->r14 | 0X2048;
    // 0x8011139C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801113A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801113A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801113A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801113AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801113B0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801113B4: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x801113B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801113BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801113C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801113C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801113C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801113CC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801113D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801113D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801113D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801113DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801113E0: lbu         $a1, 0x1C($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X1C);
    // 0x801113E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801113E8: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x801113EC: lbu         $t7, -0x108C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X108C);
    // 0x801113F0: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x801113F4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801113F8: lbu         $t7, -0x109C($t6)
    ctx->r15 = MEM_BU(ctx->r14, -0X109C);
    // 0x801113FC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80111400: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80111404: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80111408: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8011140C: lbu         $t7, -0x1094($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1094);
    // 0x80111410: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80111414: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80111418: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8011141C: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80111420: ori         $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 | 0XFF;
    // 0x80111424: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80111428: jal         0x80013E68
    // 0x8011142C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcDrawDObjDLHead0(rdram, ctx);
        goto after_1;
    // 0x8011142C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
L_80111430:
    // 0x80111430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80111438: jr          $ra
    // 0x8011143C: nop

    return;
    // 0x8011143C: nop

;}
RECOMP_FUNC void func_ovl8_80385F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385F44: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80385F48: addiu       $v0, $v0, -0x1E20
    ctx->r2 = ADD32(ctx->r2, -0X1E20);
    // 0x80385F4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80385F50: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80385F54: lwl         $t7, 0x0($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X0);
    // 0x80385F58: lwl         $t6, 0x4($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0X4);
    // 0x80385F5C: lwr         $t7, 0x3($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X3);
    // 0x80385F60: lwr         $t6, 0x7($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0X7);
    // 0x80385F64: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80385F68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80385F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385F70: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80385F74: lw          $s0, 0x24($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X24);
    // 0x80385F78: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x80385F7C: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x80385F80: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80385F84: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x80385F88: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    // 0x80385F8C: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x80385F90: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80385F94: addiu       $a2, $a2, -0x60B8
    ctx->r6 = ADD32(ctx->r6, -0X60B8);
    // 0x80385F98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80385F9C: jal         0x80377AEC
    // 0x80385FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_80377AEC(rdram, ctx);
        goto after_0;
    // 0x80385FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80385FA4: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80385FA8: addiu       $a2, $a2, -0x60B4
    ctx->r6 = ADD32(ctx->r6, -0X60B4);
    // 0x80385FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80385FB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80385FB4: jal         0x80378064
    // 0x80385FB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_ovl8_80378064(rdram, ctx);
        goto after_1;
    // 0x80385FB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x80385FBC: lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X30);
    // 0x80385FC0: lhu         $t2, 0x32($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X32);
    // 0x80385FC4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80385FC8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80385FCC: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80385FD0: addiu       $t1, $t0, -0x4
    ctx->r9 = ADD32(ctx->r8, -0X4);
    // 0x80385FD4: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x80385FD8: sh          $t9, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r25;
    // 0x80385FDC: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    // 0x80385FE0: sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // 0x80385FE4: sh          $t3, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r11;
    // 0x80385FE8: addiu       $a2, $a2, -0x60B4
    ctx->r6 = ADD32(ctx->r6, -0X60B4);
    // 0x80385FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80385FF0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80385FF4: jal         0x80378064
    // 0x80385FF8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_ovl8_80378064(rdram, ctx);
        goto after_2;
    // 0x80385FF8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80385FFC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80386000: beql        $t4, $zero, L_8038611C
    if (ctx->r12 == 0) {
        // 0x80386004: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8038611C;
    }
    goto skip_0;
    // 0x80386004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80386008: jal         0x8037D95C
    // 0x8038600C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_ovl8_8037D95C(rdram, ctx);
        goto after_3;
    // 0x8038600C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80386010: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80386014: jal         0x8037D9B4
    // 0x80386018: addiu       $a0, $a0, -0x1E14
    ctx->r4 = ADD32(ctx->r4, -0X1E14);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_4;
    // 0x80386018: addiu       $a0, $a0, -0x1E14
    ctx->r4 = ADD32(ctx->r4, -0X1E14);
    after_4:
    // 0x8038601C: jal         0x8037E7A8
    // 0x80386020: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_5;
    // 0x80386020: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x80386024: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80386028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8038602C: bne         $t5, $at, L_803860BC
    if (ctx->r13 != ctx->r1) {
        // 0x80386030: nop
    
            goto L_803860BC;
    }
    // 0x80386030: nop

    // 0x80386034: jal         0x8037E80C
    // 0x80386038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_ovl8_8037E80C(rdram, ctx);
        goto after_6;
    // 0x80386038: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_6:
    // 0x8038603C: lhu         $t7, 0x30($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X30);
    // 0x80386040: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80386044: lhu         $t2, 0x32($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X32);
    // 0x80386048: lh          $t6, 0x2C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2C);
    // 0x8038604C: bgez        $t7, L_8038605C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80386050: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8038605C;
    }
    // 0x80386050: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80386054: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x80386058: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8038605C:
    // 0x8038605C: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x80386060: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80386064: bgez        $v1, L_80386074
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80386068: sra         $t0, $v1, 1
        ctx->r8 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80386074;
    }
    // 0x80386068: sra         $t0, $v1, 1
    ctx->r8 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8038606C: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80386070: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80386074:
    // 0x80386074: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80386078: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8038607C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80386080: bgez        $t2, L_80386090
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80386084: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80386090;
    }
    // 0x80386084: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80386088: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8038608C: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80386090:
    // 0x80386090: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80386094: bgez        $v0, L_803860A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80386098: sra         $t5, $v0, 1
        ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
            goto L_803860A4;
    }
    // 0x80386098: sra         $t5, $v0, 1
    ctx->r13 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8038609C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x803860A0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_803860A4:
    // 0x803860A4: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x803860A8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x803860AC: jal         0x8037DFCC
    // 0x803860B0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_7;
    // 0x803860B0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_7:
    // 0x803860B4: b           L_80386108
    // 0x803860B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80386108;
    // 0x803860B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_803860BC:
    // 0x803860BC: jal         0x8037E80C
    // 0x803860C0: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_8;
    // 0x803860C0: nop

    after_8:
    // 0x803860C4: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x803860C8: lh          $t7, 0x2E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2E);
    // 0x803860CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x803860D0: bgez        $t6, L_803860E0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x803860D4: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_803860E0;
    }
    // 0x803860D4: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x803860D8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x803860DC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_803860E0:
    // 0x803860E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803860E4: bgez        $v0, L_803860F4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x803860E8: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_803860F4;
    }
    // 0x803860E8: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x803860EC: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x803860F0: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_803860F4:
    // 0x803860F4: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x803860F8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x803860FC: jal         0x8037DFCC
    // 0x80386100: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_9;
    // 0x80386100: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_9:
    // 0x80386104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80386108:
    // 0x80386108: jal         0x8037DD60
    // 0x8038610C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_10;
    // 0x8038610C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x80386110: jal         0x8037D908
    // 0x80386114: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_ovl8_8037D908(rdram, ctx);
        goto after_11;
    // 0x80386114: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x80386118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8038611C:
    // 0x8038611C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80386120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80386124: jr          $ra
    // 0x80386128: nop

    return;
    // 0x80386128: nop

;}
RECOMP_FUNC void mnMapsMakeNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329B0: lw          $a1, 0x4BE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BE0);
    // 0x801329B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801329B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801329BC: beq         $a1, $zero, L_801329CC
    if (ctx->r5 == 0) {
        // 0x801329C0: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_801329CC;
    }
    // 0x801329C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801329C4: jal         0x80009A84
    // 0x801329C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801329C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_801329CC:
    // 0x801329CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801329D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801329D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801329D8: jal         0x80009968
    // 0x801329DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x801329DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801329E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329E4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801329E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801329EC: sw          $v0, 0x4BE0($at)
    MEM_W(0X4BE0, ctx->r1) = ctx->r2;
    // 0x801329F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801329F4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801329F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801329FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132A00: jal         0x80009DF4
    // 0x80132A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132A04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132A08: jal         0x80132430
    // 0x80132A0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_3;
    // 0x80132A0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80132A10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A14: lw          $a0, 0x4BE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BE0);
    // 0x80132A18: jal         0x801328A8
    // 0x80132A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnMapsMakeEmblem(rdram, ctx);
        goto after_4;
    // 0x80132A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80132A20: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80132A24: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80132A28: beql        $t7, $at, L_80132A4C
    if (ctx->r15 == ctx->r1) {
        // 0x80132A2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132A4C;
    }
    goto skip_0;
    // 0x80132A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80132A30: jal         0x80132430
    // 0x80132A34: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mnMapsGetGroundKind(rdram, ctx);
        goto after_5;
    // 0x80132A34: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_5:
    // 0x80132A38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A3C: lw          $a0, 0x4BE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BE0);
    // 0x80132A40: jal         0x80132738
    // 0x80132A44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnMapsMakeName(rdram, ctx);
        goto after_6;
    // 0x80132A44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80132A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132A4C:
    // 0x80132A4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132A50: jr          $ra
    // 0x80132A54: nop

    return;
    // 0x80132A54: nop

;}
RECOMP_FUNC void ftCommonCliffCommon2ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145298: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8014529C: jal         0x800D9480
    // 0x801452A0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801452A0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    after_0:
    // 0x801452A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801452A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801452AC: jr          $ra
    // 0x801452B0: nop

    return;
    // 0x801452B0: nop

;}
RECOMP_FUNC void ftFoxSpecialAirLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D1B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D1B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D1B8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015D1BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015D1C0: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x8015D1C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D1C8: jal         0x800E6F24
    // 0x8015D1CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D1CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D1D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D1D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D1D8: jr          $ra
    // 0x8015D1DC: nop

    return;
    // 0x8015D1DC: nop

;}
RECOMP_FUNC void scExplainSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E640: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E644: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018E648: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018E64C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E650: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E658: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018E65C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018E660: addiu       $t8, $t8, -0x15D0
    ctx->r24 = ADD32(ctx->r24, -0X15D0);
    // 0x8018E664: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8018E668: addiu       $t0, $t0, -0x1440
    ctx->r8 = ADD32(ctx->r8, -0X1440);
    // 0x8018E66C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018E670: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018E674: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018E678: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018E67C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018E680: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018E684: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018E688: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018E68C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018E690: jal         0x800CDF78
    // 0x8018E694: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018E694: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018E698: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E69C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E6A0: jal         0x800CDEEC
    // 0x8018E6A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018E6A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8018E6A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E6AC: jal         0x80004980
    // 0x8018E6B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018E6B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018E6B4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E6B8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E6BC: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018E6C0: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E6C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018E6C8: jal         0x800CDE04
    // 0x8018E6CC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018E6CC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018E6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E6D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018E6D8: jr          $ra
    // 0x8018E6DC: nop

    return;
    // 0x8018E6DC: nop

;}
RECOMP_FUNC void mpCollisionGetCeilEdgeL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F446C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4470: jal         0x800F41EC
    // 0x800F4474: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    mpCollisionGetLREdge(rdram, ctx);
        goto after_0;
    // 0x800F4474: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x800F4478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F447C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4480: jr          $ra
    // 0x800F4484: nop

    return;
    // 0x800F4484: nop

;}
RECOMP_FUNC void gmCameraUpdatePlayerZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C960: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010C964: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010C968: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x8010C96C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8010C970: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010C974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010C978: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x8010C97C: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8010C980: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8010C984: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8010C988: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8010C98C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8010C990: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8010C994: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8010C998: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8010C99C: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x8010C9A0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010C9A4: lwc1        $f12, 0x58($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8010C9A8: lw          $t0, 0x9C8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X9C8);
    // 0x8010C9AC: lwc1        $f6, 0x8C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x8010C9B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010C9B4: jal         0x8010C70C
    // 0x8010C9B8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    gmCameraAdjustFOV(rdram, ctx);
        goto after_0;
    // 0x8010C9B8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8010C9BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010C9C0: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010C9C4: lwc1        $f10, 0x50($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X50);
    // 0x8010C9C8: lw          $a2, 0x54($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X54);
    // 0x8010C9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C9D0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010C9D4: jal         0x8010C55C
    // 0x8010C9D8: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    gmCameraPan(rdram, ctx);
        goto after_1;
    // 0x8010C9D8: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    after_1:
    // 0x8010C9DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010C9E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C9E4: lwc1        $f16, 0x1468($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8010C9E8: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010C9EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C9F0: lwc1        $f18, 0x48($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8010C9F4: lwc1        $f6, 0x1464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1464);
    // 0x8010C9F8: lwc1        $f8, 0x4C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8010C9FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8010CA00: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010CA04: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8010CA08: jal         0x800C7840
    // 0x8010CA0C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x8010CA0C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8010CA10: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8010CA14: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010CA18: jal         0x800C78B8
    // 0x8010CA1C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x8010CA1C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8010CA20: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8010CA24: jal         0x800C7840
    // 0x8010CA28: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    lbCommonSin(rdram, ctx);
        goto after_4;
    // 0x8010CA28: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x8010CA2C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010CA30: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010CA34: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8010CA38: jal         0x800C78B8
    // 0x8010CA3C: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    lbCommonCos(rdram, ctx);
        goto after_5;
    // 0x8010CA3C: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8010CA40: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010CA44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CA48: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8010CA4C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010CA50: jal         0x8010C5C0
    // 0x8010CA54: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    func_ovl2_8010C5C0(rdram, ctx);
        goto after_6;
    // 0x8010CA54: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8010CA58: jal         0x8010C6B8
    // 0x8010CA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_7;
    // 0x8010CA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8010CA60: jal         0x8010C6FC
    // 0x8010CA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_8;
    // 0x8010CA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010CA68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CA6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010CA70: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8010CA74: jr          $ra
    // 0x8010CA78: nop

    return;
    // 0x8010CA78: nop

;}

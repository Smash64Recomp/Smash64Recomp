#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftPikachuSpecialHiInitStatusVarsZip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152E2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152E30: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80152E34: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x80152E38: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x80152E3C: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80152E40: jr          $ra
    // 0x80152E44: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
    return;
    // 0x80152E44: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void mvEndingMakeRoomLightCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013249C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801324A0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801324A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801324A8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801324AC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801324B0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801324B4: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x801324B8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801324BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801324C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801324C4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801324C8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801324CC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801324D0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801324D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801324D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801324DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801324E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801324E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801324E8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801324EC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801324F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801324F4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801324F8: jal         0x8000B93C
    // 0x801324FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801324FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132500: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132504: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132508: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013250C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132514: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132518: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013251C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132520: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132524: jal         0x80007080
    // 0x80132528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013252C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132530: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132534: jr          $ra
    // 0x80132538: nop

    return;
    // 0x80132538: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateShutter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BF4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80132BF8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80132BFC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80132C00: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80132C04: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132C08: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80132C0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132C10: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80132C14: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80132C18: lw          $t8, 0xA4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA4);
    // 0x80132C1C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80132C20: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80132C24: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80132C28: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80132C2C: addiu       $t0, $t9, -0x13
    ctx->r8 = ADD32(ctx->r25, -0X13);
    // 0x80132C30: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80132C34: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x80132C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132C3C: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80132C40: swc1        $f6, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f6.u32l;
    // 0x80132C44: lw          $t3, 0xA4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XA4);
    // 0x80132C48: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x80132C4C: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x80132C50: addiu       $t5, $t4, 0x58
    ctx->r13 = ADD32(ctx->r12, 0X58);
    // 0x80132C54: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80132C58: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80132C5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132C60: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80132C64: jr          $ra
    // 0x80132C68: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
    return;
    // 0x80132C68: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
;}
RECOMP_FUNC void ifCommonSuddenDeathThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80112ADC: jal         0x8000B1E8
    // 0x80112AE0: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80112AE0: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
    // 0x80112AE4: jal         0x801120D4
    // 0x80112AE8: nop

    ifCommonAnnounceGoMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80112AE8: nop

    after_1:
    // 0x80112AEC: jal         0x8010E690
    // 0x80112AF0: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_2;
    // 0x80112AF0: nop

    after_2:
    // 0x80112AF4: jal         0x801121C4
    // 0x80112AF8: nop

    ifCommonAnnounceGoSetStatus(rdram, ctx);
        goto after_3;
    // 0x80112AF8: nop

    after_3:
    // 0x80112AFC: jal         0x800269C0
    // 0x80112B00: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80112B00: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_4:
    // 0x80112B04: jal         0x80009A84
    // 0x80112B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80112B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80112B0C: jal         0x8000B1E8
    // 0x80112B10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_6;
    // 0x80112B10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80112B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112B1C: jr          $ra
    // 0x80112B20: nop

    return;
    // 0x80112B20: nop

;}
RECOMP_FUNC void func_ovl29_80136B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B1C: jr          $ra
    // 0x80136B20: nop

    return;
    // 0x80136B20: nop

;}
RECOMP_FUNC void wpPikachuThunderHeadSetDestroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A640: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016A644: lw          $t6, 0x29C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X29C);
    // 0x8016A648: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8016A64C: bne         $t7, $zero, L_8016A678
    if (ctx->r15 != 0) {
        // 0x8016A650: nop
    
            goto L_8016A678;
    }
    // 0x8016A650: nop

    // 0x8016A654: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8016A658: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8016A65C: lw          $v1, 0x84($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X84);
    // 0x8016A660: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x8016A664: bne         $t9, $t0, L_8016A678
    if (ctx->r25 != ctx->r8) {
        // 0x8016A668: nop
    
            goto L_8016A678;
    }
    // 0x8016A668: nop

    // 0x8016A66C: lw          $t1, 0xADC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XADC);
    // 0x8016A670: or          $t2, $t1, $a1
    ctx->r10 = ctx->r9 | ctx->r5;
    // 0x8016A674: sw          $t2, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r10;
L_8016A678:
    // 0x8016A678: jr          $ra
    // 0x8016A67C: nop

    return;
    // 0x8016A67C: nop

;}
RECOMP_FUNC void func_ovl8_8037488C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037488C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374890: beq         $a0, $zero, L_803748B0
    if (ctx->r4 == 0) {
        // 0x80374894: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_803748B0;
    }
    // 0x80374894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374898: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8037489C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x803748A0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x803748A4: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x803748A8: jalr        $t9
    // 0x803748AC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803748AC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
L_803748B0:
    // 0x803748B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803748B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803748B8: jr          $ra
    // 0x803748BC: nop

    return;
    // 0x803748BC: nop

;}
RECOMP_FUNC void mnPlayersVSGetPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132168: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013216C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132170: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80132174: addiu       $t6, $t6, -0x4AFC
    ctx->r14 = ADD32(ctx->r14, -0X4AFC);
    // 0x80132178: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8013217C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132180:
    // 0x80132180: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132184: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132188: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013218C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132190: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132194: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132198: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013219C: bne         $t6, $t0, L_80132180
    if (ctx->r14 != ctx->r8) {
        // 0x801321A0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132180;
    }
    // 0x801321A0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801321A4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801321A8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801321AC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801321B0: jr          $ra
    // 0x801321B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801321B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbySpecialNThrowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016237C: jal         0x80162258
    // 0x80162380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNThrowUpdateCheckThrowStar(rdram, ctx);
        goto after_0;
    // 0x80162380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162384: jal         0x800D94C4
    // 0x80162388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x80162388: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016238C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162394: jr          $ra
    // 0x80162398: nop

    return;
    // 0x80162398: nop

;}
RECOMP_FUNC void mnVSResultsSetPoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80136BA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136BA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80136BA8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136BAC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80136BB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80136BB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80136BB8: addiu       $s1, $s1, -0x6460
    ctx->r17 = ADD32(ctx->r17, -0X6460);
    // 0x80136BBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80136BC0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80136BC4:
    // 0x80136BC4: jal         0x80135670
    // 0x80136BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetKOs(rdram, ctx);
        goto after_0;
    // 0x80136BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80136BCC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80136BD0: jal         0x801358C4
    // 0x80136BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetTKO(rdram, ctx);
        goto after_1;
    // 0x80136BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80136BD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80136BDC: subu        $t6, $s2, $v0
    ctx->r14 = SUB32(ctx->r18, ctx->r2);
    // 0x80136BE0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80136BE4: bne         $s0, $s3, L_80136BC4
    if (ctx->r16 != ctx->r19) {
        // 0x80136BE8: sw          $t6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r14;
            goto L_80136BC4;
    }
    // 0x80136BE8: sw          $t6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r14;
    // 0x80136BEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136BF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136BF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136BF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80136BFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80136C00: jr          $ra
    // 0x80136C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80136C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl27_801358BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358BC: jr          $ra
    // 0x801358C0: nop

    return;
    // 0x801358C0: nop

;}
RECOMP_FUNC void efManagerKirbyStarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010201C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80102020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102028: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x8010202C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80102030: jal         0x800D35DC
    // 0x80102034: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    lbParticleMakeGenerator(rdram, ctx);
        goto after_0;
    // 0x80102034: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80102038: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8010203C: beq         $v0, $zero, L_8010205C
    if (ctx->r2 == 0) {
        // 0x80102040: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010205C;
    }
    // 0x80102040: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80102044: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80102048: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x8010204C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80102050: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80102054: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80102058: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
L_8010205C:
    // 0x8010205C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80102068: jr          $ra
    // 0x8010206C: nop

    return;
    // 0x8010206C: nop

;}
RECOMP_FUNC void itMainDestroyItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801728D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801728D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801728DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801728E0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801728E4: lw          $t7, 0x2CC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2CC);
    // 0x801728E8: sll         $t9, $t7, 17
    ctx->r25 = S32(ctx->r15 << 17);
    // 0x801728EC: bgezl       $t9, L_80172920
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801728F0: lw          $v0, 0xC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XC);
            goto L_80172920;
    }
    goto skip_0;
    // 0x801728F0: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    skip_0:
    // 0x801728F4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x801728F8: beql        $v1, $zero, L_80172920
    if (ctx->r3 == 0) {
        // 0x801728FC: lw          $v0, 0xC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XC);
            goto L_80172920;
    }
    goto skip_1;
    // 0x801728FC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    skip_1:
    // 0x80172900: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80172904: sw          $zero, 0x84C($v0)
    MEM_W(0X84C, ctx->r2) = 0;
    // 0x80172908: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x8017290C: jal         0x800E8744
    // 0x80172910: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamSetHammerParams(rdram, ctx);
        goto after_0;
    // 0x80172910: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80172914: b           L_8017294C
    // 0x80172918: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_8017294C;
    // 0x80172918: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8017291C: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
L_80172920:
    // 0x80172920: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80172924: slti        $at, $v0, 0x1B
    ctx->r1 = SIGNED(ctx->r2) < 0X1B ? 1 : 0;
    // 0x80172928: bne         $at, $zero, L_80172938
    if (ctx->r1 != 0) {
        // 0x8017292C: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_80172938;
    }
    // 0x8017292C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80172930: bnel        $at, $zero, L_80172950
    if (ctx->r1 != 0) {
        // 0x80172934: lw          $a0, 0x348($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X348);
            goto L_80172950;
    }
    goto skip_2;
    // 0x80172934: lw          $a0, 0x348($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X348);
    skip_2:
L_80172938:
    // 0x80172938: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    // 0x8017293C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80172940: jal         0x800FF590
    // 0x80172944: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandLargeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80172944: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80172948: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8017294C:
    // 0x8017294C: lw          $a0, 0x348($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X348);
L_80172950:
    // 0x80172950: beq         $a0, $zero, L_80172964
    if (ctx->r4 == 0) {
        // 0x80172954: nop
    
            goto L_80172964;
    }
    // 0x80172954: nop

    // 0x80172958: jal         0x80009A84
    // 0x8017295C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8017295C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80172960: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80172964:
    // 0x80172964: jal         0x8016DFDC
    // 0x80172968: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itManagerSetPrevStructAlloc(rdram, ctx);
        goto after_3;
    // 0x80172968: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8017296C: jal         0x80009A84
    // 0x80172970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80172970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80172974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172978: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017297C: jr          $ra
    // 0x80172980: nop

    return;
    // 0x80172980: nop

;}
RECOMP_FUNC void ftCommonJumpAerialCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014019C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801401A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801401A4: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801401A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801401AC: jal         0x800F3794
    // 0x801401B0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x801401B0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801401B4: beq         $v0, $zero, L_801401C4
    if (ctx->r2 == 0) {
        // 0x801401B8: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_801401C4;
    }
    // 0x801401B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801401BC: b           L_80140324
    // 0x801401C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140324;
    // 0x801401C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801401C4:
    // 0x801401C4: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x801401C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801401CC: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x801401D0: beql        $a0, $v1, L_801401F4
    if (ctx->r4 == ctx->r3) {
        // 0x801401D4: lw          $t6, 0x9C8($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X9C8);
            goto L_801401F4;
    }
    goto skip_0;
    // 0x801401D4: lw          $t6, 0x9C8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X9C8);
    skip_0:
    // 0x801401D8: beq         $v1, $at, L_801401F0
    if (ctx->r3 == ctx->r1) {
        // 0x801401DC: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_801401F0;
    }
    // 0x801401DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801401E0: beq         $v1, $at, L_801401F0
    if (ctx->r3 == ctx->r1) {
        // 0x801401E4: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_801401F0;
    }
    // 0x801401E4: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801401E8: bnel        $v1, $at, L_801402E4
    if (ctx->r3 != ctx->r1) {
        // 0x801401EC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801402E4;
    }
    goto skip_1;
    // 0x801401EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_1:
L_801401F0:
    // 0x801401F0: lw          $t6, 0x9C8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X9C8);
L_801401F4:
    // 0x801401F4: lbu         $v0, 0x148($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X148);
    // 0x801401F8: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x801401FC: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80140200: beq         $at, $zero, L_80140320
    if (ctx->r1 == 0) {
        // 0x80140204: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80140320;
    }
    // 0x80140204: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140208: bne         $v0, $at, L_80140230
    if (ctx->r2 != ctx->r1) {
        // 0x8014020C: nop
    
            goto L_80140230;
    }
    // 0x8014020C: nop

    // 0x80140210: jal         0x8013F474
    // 0x80140214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_1;
    // 0x80140214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80140218: beq         $v0, $zero, L_80140320
    if (ctx->r2 == 0) {
        // 0x8014021C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80140320;
    }
    // 0x8014021C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80140220: jal         0x8013FF38
    // 0x80140224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonJumpAerialMultiSetStatus(rdram, ctx);
        goto after_2;
    // 0x80140224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80140228: b           L_80140324
    // 0x8014022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140324;
    // 0x8014022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140230:
    // 0x80140230: beq         $v1, $a0, L_80140258
    if (ctx->r3 == ctx->r4) {
        // 0x80140234: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80140258;
    }
    // 0x80140234: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80140238: beq         $v1, $at, L_8014029C
    if (ctx->r3 == ctx->r1) {
        // 0x8014023C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8014029C;
    }
    // 0x8014023C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80140240: beq         $v1, $at, L_80140258
    if (ctx->r3 == ctx->r1) {
        // 0x80140244: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80140258;
    }
    // 0x80140244: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80140248: beql        $v1, $at, L_801402A0
    if (ctx->r3 == ctx->r1) {
        // 0x8014024C: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_801402A0;
    }
    goto skip_2;
    // 0x8014024C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_2:
    // 0x80140250: b           L_80140324
    // 0x80140254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140324;
    // 0x80140254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140258:
    // 0x80140258: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8014025C: slti        $at, $v0, 0xDF
    ctx->r1 = SIGNED(ctx->r2) < 0XDF ? 1 : 0;
    // 0x80140260: bne         $at, $zero, L_8014027C
    if (ctx->r1 != 0) {
        // 0x80140264: slti        $at, $v0, 0xE4
        ctx->r1 = SIGNED(ctx->r2) < 0XE4 ? 1 : 0;
            goto L_8014027C;
    }
    // 0x80140264: slti        $at, $v0, 0xE4
    ctx->r1 = SIGNED(ctx->r2) < 0XE4 ? 1 : 0;
    // 0x80140268: beq         $at, $zero, L_8014027C
    if (ctx->r1 == 0) {
        // 0x8014026C: nop
    
            goto L_8014027C;
    }
    // 0x8014026C: nop

    // 0x80140270: lw          $t8, 0x180($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X180);
    // 0x80140274: beql        $t8, $zero, L_80140324
    if (ctx->r24 == 0) {
        // 0x80140278: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140324;
    }
    goto skip_3;
    // 0x80140278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
L_8014027C:
    // 0x8014027C: jal         0x80140150
    // 0x80140280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonJumpAerialMultiGetJumpInputType(rdram, ctx);
        goto after_3;
    // 0x80140280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80140284: beq         $v0, $zero, L_80140320
    if (ctx->r2 == 0) {
        // 0x80140288: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80140320;
    }
    // 0x80140288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014028C: jal         0x8013FF38
    // 0x80140290: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonJumpAerialMultiSetStatus(rdram, ctx);
        goto after_4;
    // 0x80140290: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80140294: b           L_80140324
    // 0x80140298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140324;
    // 0x80140298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014029C:
    // 0x8014029C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_801402A0:
    // 0x801402A0: slti        $at, $v0, 0xDF
    ctx->r1 = SIGNED(ctx->r2) < 0XDF ? 1 : 0;
    // 0x801402A4: bne         $at, $zero, L_801402C0
    if (ctx->r1 != 0) {
        // 0x801402A8: slti        $at, $v0, 0xE4
        ctx->r1 = SIGNED(ctx->r2) < 0XE4 ? 1 : 0;
            goto L_801402C0;
    }
    // 0x801402A8: slti        $at, $v0, 0xE4
    ctx->r1 = SIGNED(ctx->r2) < 0XE4 ? 1 : 0;
    // 0x801402AC: beq         $at, $zero, L_801402C0
    if (ctx->r1 == 0) {
        // 0x801402B0: nop
    
            goto L_801402C0;
    }
    // 0x801402B0: nop

    // 0x801402B4: lw          $t9, 0x180($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X180);
    // 0x801402B8: beql        $t9, $zero, L_80140324
    if (ctx->r25 == 0) {
        // 0x801402BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140324;
    }
    goto skip_4;
    // 0x801402BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
L_801402C0:
    // 0x801402C0: jal         0x80140150
    // 0x801402C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonJumpAerialMultiGetJumpInputType(rdram, ctx);
        goto after_5;
    // 0x801402C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x801402C8: beq         $v0, $zero, L_80140320
    if (ctx->r2 == 0) {
        // 0x801402CC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80140320;
    }
    // 0x801402CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801402D0: jal         0x8013FF38
    // 0x801402D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonJumpAerialMultiSetStatus(rdram, ctx);
        goto after_6;
    // 0x801402D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801402D8: b           L_80140324
    // 0x801402DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140324;
    // 0x801402DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801402E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_801402E4:
    // 0x801402E4: jal         0x8013F474
    // 0x801402E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_7;
    // 0x801402E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_7:
    // 0x801402EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801402F0: beq         $v0, $zero, L_80140320
    if (ctx->r2 == 0) {
        // 0x801402F4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80140320;
    }
    // 0x801402F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801402F8: lw          $t1, 0x9C8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X9C8);
    // 0x801402FC: lbu         $t0, 0x148($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X148);
    // 0x80140300: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x80140304: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80140308: beql        $at, $zero, L_80140324
    if (ctx->r1 == 0) {
        // 0x8014030C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80140324;
    }
    goto skip_5;
    // 0x8014030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80140310: jal         0x8013FD74
    // 0x80140314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonJumpAerialSetStatus(rdram, ctx);
        goto after_8;
    // 0x80140314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80140318: b           L_80140324
    // 0x8014031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80140324;
    // 0x8014031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140320:
    // 0x80140320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80140324:
    // 0x80140324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014032C: jr          $ra
    // 0x80140330: nop

    return;
    // 0x80140330: nop

;}
RECOMP_FUNC void itFushigibanaCommonUpdateMonsterEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184440: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80184444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184448: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018444C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80184450: lw          $t6, -0x4ACC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4ACC);
    // 0x80184454: lw          $a2, 0x340($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X340);
    // 0x80184458: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018445C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80184460: srl         $a2, $a2, 28
    ctx->r6 = S32(U32(ctx->r6) >> 28);
    // 0x80184464: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80184468: addiu       $t8, $t8, 0x2C0
    ctx->r24 = ADD32(ctx->r24, 0X2C0);
    // 0x8018446C: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80184470: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80184474: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80184478: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x8018447C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80184480: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80184484: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80184488: bnel        $t0, $t1, L_8018455C
    if (ctx->r8 != ctx->r9) {
        // 0x8018448C: lhu         $t3, 0x33E($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X33E);
            goto L_8018455C;
    }
    goto skip_0;
    // 0x8018448C: lhu         $t3, 0x33E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X33E);
    skip_0:
    // 0x80184490: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80184494: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80184498: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8018449C: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x801844A0: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x801844A4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801844A8: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x801844AC: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x801844B0: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x801844B4: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    // 0x801844B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801844BC: bgez        $t8, L_801844D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801844C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801844D0;
    }
    // 0x801844C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801844C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801844C8: nop

    // 0x801844CC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801844D0:
    // 0x801844D0: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x801844D4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x801844D8: lbu         $t7, 0x158($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X158);
    // 0x801844DC: lbu         $t5, 0x340($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X340);
    // 0x801844E0: sw          $t9, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->r25;
    // 0x801844E4: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x801844E8: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801844EC: andi        $t7, $t5, 0xFF0F
    ctx->r15 = ctx->r13 & 0XFF0F;
    // 0x801844F0: sw          $t0, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r8;
    // 0x801844F4: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x801844F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801844FC: sw          $t1, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r9;
    // 0x80184500: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x80184504: sw          $t2, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r10;
    // 0x80184508: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x8018450C: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x80184510: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80184514: sll         $t6, $t4, 7
    ctx->r14 = S32(ctx->r12 << 7);
    // 0x80184518: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8018451C: sb          $t9, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r25;
    // 0x80184520: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x80184524: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80184528: andi        $t4, $t3, 0xF0
    ctx->r12 = ctx->r11 & 0XF0;
    // 0x8018452C: sw          $t0, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r8;
    // 0x80184530: lhu         $t1, 0x20($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X20);
    // 0x80184534: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x80184538: sb          $t6, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r14;
    // 0x8018453C: lw          $t8, 0x340($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X340);
    // 0x80184540: sh          $t1, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r9;
    // 0x80184544: andi        $t1, $t6, 0xF
    ctx->r9 = ctx->r14 & 0XF;
    // 0x80184548: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8018454C: bne         $t9, $at, L_80184558
    if (ctx->r25 != ctx->r1) {
        // 0x80184550: ori         $t2, $t1, 0x10
        ctx->r10 = ctx->r9 | 0X10;
            goto L_80184558;
    }
    // 0x80184550: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80184554: sb          $t2, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r10;
L_80184558:
    // 0x80184558: lhu         $t3, 0x33E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X33E);
L_8018455C:
    // 0x8018455C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80184560: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80184564: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x80184568: bne         $t4, $at, L_801845A4
    if (ctx->r12 != ctx->r1) {
        // 0x8018456C: sh          $t5, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r13;
            goto L_801845A4;
    }
    // 0x8018456C: sh          $t5, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r13;
    // 0x80184570: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80184574: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80184578: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018457C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80184580: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80184584: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80184588: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8018458C: lw          $t6, 0x20($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X20);
    // 0x80184590: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80184594: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80184598: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8018459C: jal         0x800FF048
    // 0x801845A0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801845A0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_0:
L_801845A4:
    // 0x801845A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801845A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801845AC: jr          $ra
    // 0x801845B0: nop

    return;
    // 0x801845B0: nop

;}
RECOMP_FUNC void func_ovl2_80106CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106CC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80106CC8: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80106CCC: lhu         $v0, 0x46($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X46);
    // 0x80106CD0: addiu       $at, $zero, 0xB2
    ctx->r1 = ADD32(0, 0XB2);
    // 0x80106CD4: beq         $v0, $zero, L_80106CEC
    if (ctx->r2 == 0) {
        // 0x80106CD8: nop
    
            goto L_80106CEC;
    }
    // 0x80106CD8: nop

    // 0x80106CDC: beq         $v0, $at, L_80106CF4
    if (ctx->r2 == ctx->r1) {
        // 0x80106CE0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80106CF4;
    }
    // 0x80106CE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80106CE4: jr          $ra
    // 0x80106CE8: nop

    return;
    // 0x80106CE8: nop

L_80106CEC:
    // 0x80106CEC: jr          $ra
    // 0x80106CF0: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
    return;
    // 0x80106CF0: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
L_80106CF4:
    // 0x80106CF4: sb          $t6, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r14;
    // 0x80106CF8: jr          $ra
    // 0x80106CFC: nop

    return;
    // 0x80106CFC: nop

;}
RECOMP_FUNC void mnVSOptionsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134504: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134508: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8013450C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80134510: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134518: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8013451C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80134520: addiu       $t8, $t8, 0x4918
    ctx->r24 = ADD32(ctx->r24, 0X4918);
    // 0x80134524: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80134528: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8013452C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80134530: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80134534: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134538: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8013453C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80134540: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80134544: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80134548: jal         0x800CDF78
    // 0x8013454C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013454C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80134550: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134554: addiu       $a0, $a0, 0x46C0
    ctx->r4 = ADD32(ctx->r4, 0X46C0);
    // 0x80134558: jal         0x800CDEEC
    // 0x8013455C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013455C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80134560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134564: jal         0x80004980
    // 0x80134568: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134568: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013456C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134570: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134574: addiu       $a2, $a2, 0x49D8
    ctx->r6 = ADD32(ctx->r6, 0X49D8);
    // 0x80134578: addiu       $a0, $a0, 0x46C0
    ctx->r4 = ADD32(ctx->r4, 0X46C0);
    // 0x8013457C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80134580: jal         0x800CDE04
    // 0x80134584: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134584: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134588: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013458C: addiu       $a1, $a1, 0x3A40
    ctx->r5 = ADD32(ctx->r5, 0X3A40);
    // 0x80134590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134598: jal         0x80009968
    // 0x8013459C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013459C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801345A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801345A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801345A8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801345AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801345B0: jal         0x8000B9FC
    // 0x801345B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801345B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801345B8: jal         0x80133878
    // 0x801345BC: nop

    mnVSOptionsInitVars(rdram, ctx);
        goto after_6;
    // 0x801345BC: nop

    after_6:
    // 0x801345C0: jal         0x80133738
    // 0x801345C4: nop

    mnVSOptionsMakeWallpaperCamera(rdram, ctx);
        goto after_7;
    // 0x801345C4: nop

    after_7:
    // 0x801345C8: jal         0x80133698
    // 0x801345CC: nop

    mnVSOptionsMakeLabelUnderlineCamera(rdram, ctx);
        goto after_8;
    // 0x801345CC: nop

    after_8:
    // 0x801345D0: jal         0x801335F8
    // 0x801345D4: nop

    mnVSOptionsMakeOptionCamera(rdram, ctx);
        goto after_9;
    // 0x801345D4: nop

    after_9:
    // 0x801345D8: jal         0x80133558
    // 0x801345DC: nop

    mnVSOptionsMakeTintCamera(rdram, ctx);
        goto after_10;
    // 0x801345DC: nop

    after_10:
    // 0x801345E0: jal         0x801337D8
    // 0x801345E4: nop

    mnVSOptionsMakeDecalCamera(rdram, ctx);
        goto after_11;
    // 0x801345E4: nop

    after_11:
    // 0x801345E8: jal         0x80132EAC
    // 0x801345EC: nop

    mnVSOptionsMakeWallpaper(rdram, ctx);
        goto after_12;
    // 0x801345EC: nop

    after_12:
    // 0x801345F0: jal         0x80133464
    // 0x801345F4: nop

    mnVSOptionsMakeTint(rdram, ctx);
        goto after_13;
    // 0x801345F4: nop

    after_13:
    // 0x801345F8: jal         0x801334B0
    // 0x801345FC: nop

    mnVSOptionsMakeDecal(rdram, ctx);
        goto after_14;
    // 0x801345FC: nop

    after_14:
    // 0x80134600: jal         0x80132D68
    // 0x80134604: nop

    mnVSOptionsMakeLabel(rdram, ctx);
        goto after_15;
    // 0x80134604: nop

    after_15:
    // 0x80134608: jal         0x80132AC8
    // 0x8013460C: nop

    mnVSOptionsMakeHandicapOption(rdram, ctx);
        goto after_16;
    // 0x8013460C: nop

    after_16:
    // 0x80134610: jal         0x80132968
    // 0x80134614: nop

    mnVSOptionsMakeTeamAttackOption(rdram, ctx);
        goto after_17;
    // 0x80134614: nop

    after_17:
    // 0x80134618: jal         0x80132804
    // 0x8013461C: nop

    mnVSOptionsMakeStageSelectOption(rdram, ctx);
        goto after_18;
    // 0x8013461C: nop

    after_18:
    // 0x80134620: jal         0x80132564
    // 0x80134624: nop

    mnVSOptionsMakeDamageOption(rdram, ctx);
        goto after_19;
    // 0x80134624: nop

    after_19:
    // 0x80134628: jal         0x80132478
    // 0x8013462C: nop

    mnVSOptionsMakeDamageDigits(rdram, ctx);
        goto after_20;
    // 0x8013462C: nop

    after_20:
    // 0x80134630: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134634: lw          $t0, 0x4904($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4904);
    // 0x80134638: beq         $t0, $zero, L_80134648
    if (ctx->r8 == 0) {
        // 0x8013463C: nop
    
            goto L_80134648;
    }
    // 0x8013463C: nop

    // 0x80134640: jal         0x801326F0
    // 0x80134644: nop

    mnVSOptionsMakeItemSwitchOption(rdram, ctx);
        goto after_21;
    // 0x80134644: nop

    after_21:
L_80134648:
    // 0x80134648: jal         0x80133300
    // 0x8013464C: nop

    mnVSOptionsMakeUnderline(rdram, ctx);
        goto after_22;
    // 0x8013464C: nop

    after_22:
    // 0x80134650: jal         0x80132E58
    // 0x80134654: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_23;
    // 0x80134654: nop

    after_23:
    // 0x80134658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013465C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80134660: jr          $ra
    // 0x80134664: nop

    return;
    // 0x80134664: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeTimeUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E2E8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E2EC: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x8018E2F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E2F4: sw          $zero, -0xC58($at)
    MEM_W(-0XC58, ctx->r1) = 0;
    // 0x8018E2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E2FC: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8018E300: bne         $t6, $at, L_8018E334
    if (ctx->r14 != ctx->r1) {
        // 0x8018E304: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018E334;
    }
    // 0x8018E304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E308: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E310: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018E314: jal         0x80009968
    // 0x8018E318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018E31C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E320: addiu       $a1, $a1, -0x1D58
    ctx->r5 = ADD32(ctx->r5, -0X1D58);
    // 0x8018E324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E328: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E32C: jal         0x80008188
    // 0x8018E330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8018E330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8018E334:
    // 0x8018E334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E33C: jr          $ra
    // 0x8018E340: nop

    return;
    // 0x8018E340: nop

;}
RECOMP_FUNC void func_ovl8_8037B760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B760: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8037B764: bne         $at, $zero, L_8037B7A8
    if (ctx->r1 != 0) {
        // 0x8037B768: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8037B7A8;
    }
    // 0x8037B768: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8037B76C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037B770: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8037B774: beq         $a3, $zero, L_8037B7E8
    if (ctx->r7 == 0) {
        // 0x8037B778: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_8037B7E8;
    }
    // 0x8037B778: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8037B77C:
    // 0x8037B77C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037B780: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B784: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8037B788: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037B78C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037B790: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037B794: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8037B798: bne         $a3, $zero, L_8037B77C
    if (ctx->r7 != 0) {
        // 0x8037B79C: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_8037B77C;
    }
    // 0x8037B79C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8037B7A0: jr          $ra
    // 0x8037B7A4: nop

    return;
    // 0x8037B7A4: nop

L_8037B7A8:
    // 0x8037B7A8: addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // 0x8037B7AC: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8037B7B0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8037B7B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8037B7B8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8037B7BC: beq         $a3, $zero, L_8037B7E8
    if (ctx->r7 == 0) {
        // 0x8037B7C0: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_8037B7E8;
    }
    // 0x8037B7C0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8037B7C4:
    // 0x8037B7C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037B7C8: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B7CC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8037B7D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037B7D4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8037B7D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8037B7DC: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8037B7E0: bne         $a3, $zero, L_8037B7C4
    if (ctx->r7 != 0) {
        // 0x8037B7E4: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_8037B7C4;
    }
    // 0x8037B7E4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8037B7E8:
    // 0x8037B7E8: jr          $ra
    // 0x8037B7EC: nop

    return;
    // 0x8037B7EC: nop

;}
RECOMP_FUNC void sc1PGameFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D208: jal         0x8011485C
    // 0x8018D20C: nop

    ifCommonBattleUpdateInterfaceAll(rdram, ctx);
        goto after_0;
    // 0x8018D20C: nop

    after_0:
    // 0x8018D210: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D214: lw          $t6, 0x33C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X33C4);
    // 0x8018D218: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018D21C: bne         $t6, $zero, L_8018D240
    if (ctx->r14 != 0) {
        // 0x8018D220: nop
    
            goto L_8018D240;
    }
    // 0x8018D220: nop

    // 0x8018D224: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018D228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D22C: lbu         $t8, 0x11($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X11);
    // 0x8018D230: bne         $t8, $at, L_8018D240
    if (ctx->r24 != ctx->r1) {
        // 0x8018D234: nop
    
            goto L_8018D240;
    }
    // 0x8018D234: nop

    // 0x8018D238: jal         0x8018D160
    // 0x8018D23C: nop

    sc1PGameSetGameStart(rdram, ctx);
        goto after_1;
    // 0x8018D23C: nop

    after_1:
L_8018D240:
    // 0x8018D240: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D244: lw          $t9, 0x33C0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33C0);
    // 0x8018D248: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8018D24C: bnel        $t9, $zero, L_8018D274
    if (ctx->r25 != 0) {
        // 0x8018D250: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D274;
    }
    goto skip_0;
    // 0x8018D250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D254: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x8018D258: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018D25C: lbu         $t1, 0x11($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X11);
    // 0x8018D260: bnel        $t1, $at, L_8018D274
    if (ctx->r9 != ctx->r1) {
        // 0x8018D264: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D274;
    }
    goto skip_1;
    // 0x8018D264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8018D268: jal         0x8018D1A8
    // 0x8018D26C: nop

    sc1PGameSetGameEnd(rdram, ctx);
        goto after_2;
    // 0x8018D26C: nop

    after_2:
    // 0x8018D270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D274:
    // 0x8018D274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D278: jr          $ra
    // 0x8018D27C: nop

    return;
    // 0x8018D27C: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitSpeedOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F264: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F268: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F26C: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x8018F270: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018F274: lw          $v0, 0x44($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X44);
    // 0x8018F278: sb          $a0, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r4;
    // 0x8018F27C: sb          $a0, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r4;
    // 0x8018F280: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8018F284: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8018F288: lw          $v0, 0x48($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X48);
    // 0x8018F28C: sb          $a0, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r4;
    // 0x8018F290: sb          $a0, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r4;
    // 0x8018F294: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8018F298: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x8018F29C: lw          $v0, 0x4C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4C);
    // 0x8018F2A0: sb          $a0, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r4;
    // 0x8018F2A4: sb          $a0, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r4;
    // 0x8018F2A8: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x8018F2AC: lw          $t9, 0x30($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X30);
    // 0x8018F2B0: lw          $v0, 0x50($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X50);
    // 0x8018F2B4: sb          $a0, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r4;
    // 0x8018F2B8: sb          $a0, 0x19($v0)
    MEM_B(0X19, ctx->r2) = ctx->r4;
    // 0x8018F2BC: jr          $ra
    // 0x8018F2C0: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    return;
    // 0x8018F2C0: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mnPlayers1PGameMakeLevelOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133F38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133F40: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80133F44: jal         0x80009968
    // 0x80133F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133F4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133F50: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133F54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133F58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133F5C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133F60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133F64: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80133F68: jal         0x80009DF4
    // 0x80133F6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133F6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133F70: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F74: addiu       $a1, $a1, 0x3BC0
    ctx->r5 = ADD32(ctx->r5, 0X3BC0);
    // 0x80133F78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133F7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133F80: jal         0x80008188
    // 0x80133F84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80133F84: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133F88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133F8C: jal         0x80133D9C
    // 0x80133F90: lw          $a0, -0x704C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X704C);
    mnPlayers1PGameMakeLevel(rdram, ctx);
        goto after_3;
    // 0x80133F90: lw          $a0, -0x704C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X704C);
    after_3:
    // 0x80133F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133F9C: jr          $ra
    // 0x80133FA0: nop

    return;
    // 0x80133FA0: nop

;}
RECOMP_FUNC void sc1PIntroInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134810: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80134814: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, 0X4AD0);
    // 0x80134818: lbu         $t6, 0x17($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X17);
    // 0x8013481C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134820: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
    // 0x80134824: sw          $t6, 0x5C28($at)
    MEM_W(0X5C28, ctx->r1) = ctx->r14;
    // 0x80134828: lbu         $t7, 0x13($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X13);
    // 0x8013482C: lbu         $t5, 0x18($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X18);
    // 0x80134830: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80134834: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134838: addiu       $a3, $a3, 0x4B18
    ctx->r7 = ADD32(ctx->r7, 0X4B18);
    // 0x8013483C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134840: addiu       $a2, $a2, 0x5CC8
    ctx->r6 = ADD32(ctx->r6, 0X5CC8);
    // 0x80134844: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134848: addiu       $t1, $t1, 0x5CD8
    ctx->r9 = ADD32(ctx->r9, 0X5CD8);
    // 0x8013484C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80134850: addiu       $t2, $t2, 0x5CE8
    ctx->r10 = ADD32(ctx->r10, 0X5CE8);
    // 0x80134854: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134858: mflo        $t8
    ctx->r24 = lo;
    // 0x8013485C: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80134860: lbu         $t3, 0x26($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X26);
    // 0x80134864: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134868: lbu         $t4, 0x27($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X27);
    // 0x8013486C: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x80134870: lbu         $t3, 0x19($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X19);
    // 0x80134874: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x80134878: lbu         $t9, 0x23($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X23);
    // 0x8013487C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80134880: mflo        $t6
    ctx->r14 = lo;
    // 0x80134884: addu        $v1, $a3, $t6
    ctx->r3 = ADD32(ctx->r7, ctx->r14);
    // 0x80134888: lbu         $t7, 0x23($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X23);
    // 0x8013488C: multu       $t3, $t0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134890: lbu         $t8, 0x26($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X26);
    // 0x80134894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80134898: lbu         $t9, 0x27($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X27);
    // 0x8013489C: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x801348A0: sw          $t9, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r25;
    // 0x801348A4: mflo        $t4
    ctx->r12 = lo;
    // 0x801348A8: addu        $a0, $a3, $t4
    ctx->r4 = ADD32(ctx->r7, ctx->r12);
    // 0x801348AC: lbu         $t5, 0x23($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X23);
    // 0x801348B0: lbu         $t6, 0x26($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X26);
    // 0x801348B4: lbu         $t7, 0x27($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X27);
    // 0x801348B8: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x801348BC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x801348C0: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x801348C4: sw          $zero, 0x5CB8($at)
    MEM_W(0X5CB8, ctx->r1) = 0;
    // 0x801348C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348CC: sw          $zero, 0x5CBC($at)
    MEM_W(0X5CBC, ctx->r1) = 0;
    // 0x801348D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348D4: sw          $zero, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = 0;
    // 0x801348D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348DC: sw          $zero, 0x5CF4($at)
    MEM_W(0X5CF4, ctx->r1) = 0;
    // 0x801348E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348E4: jr          $ra
    // 0x801348E8: sw          $zero, 0x5CF8($at)
    MEM_W(0X5CF8, ctx->r1) = 0;
    return;
    // 0x801348E8: sw          $zero, 0x5CF8($at)
    MEM_W(0X5CF8, ctx->r1) = 0;
;}
RECOMP_FUNC void scStaffrollCheckCursorNameOverlap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EB8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131EBC: lw          $t6, -0x5734($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5734);
    // 0x80131EC0: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x80131EC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80131EC8: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80131ECC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80131ED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131ED4: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131ED8: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131EDC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80131EE0: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80131EE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131EE8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131EEC: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80131EF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131EF4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80131EF8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80131EFC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80131F00: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80131F04: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80131F08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80131F0C: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80131F10: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80131F14: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80131F18: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80131F1C: nop

    // 0x80131F20: bc1f        L_80131F2C
    if (!c1cs) {
        // 0x80131F24: nop
    
            goto L_80131F2C;
    }
    // 0x80131F24: nop

    // 0x80131F28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80131F2C:
    // 0x80131F2C: jr          $ra
    // 0x80131F30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131F30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itNBumperMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BF8C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017BF90: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8017BF94: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017BF98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017BF9C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8017BFA0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8017BFA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017BFA8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017BFAC: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8017BFB0: addiu       $a1, $a1, -0x5970
    ctx->r5 = ADD32(ctx->r5, -0X5970);
    // 0x8017BFB4: jal         0x8016E174
    // 0x8017BFB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017BFB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8017BFBC: beq         $v0, $zero, L_8017C074
    if (ctx->r2 == 0) {
        // 0x8017BFC0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017C074;
    }
    // 0x8017BFC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017BFC4: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x8017BFC8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8017BFCC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017BFD0: addiu       $t0, $s0, 0x1C
    ctx->r8 = ADD32(ctx->r16, 0X1C);
    // 0x8017BFD4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8017BFD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BFDC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8017BFE0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017BFE4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8017BFE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017BFF0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8017BFF4: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8017BFF8: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8017BFFC: lw          $a3, 0x84($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X84);
    // 0x8017C000: lbu         $t2, 0x158($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X158);
    // 0x8017C004: sh          $zero, 0x33E($a3)
    MEM_H(0X33E, ctx->r7) = 0;
    // 0x8017C008: sb          $t9, 0x154($a3)
    MEM_B(0X154, ctx->r7) = ctx->r25;
    // 0x8017C00C: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8017C010: sb          $t3, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r11;
    // 0x8017C014: lw          $t4, 0x80($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X80);
    // 0x8017C018: swc1        $f4, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->f4.u32l;
    // 0x8017C01C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017C020: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8017C024: jal         0x80008CC0
    // 0x8017C028: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8017C028: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017C02C: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x8017C030: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C034: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8017C038: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8017C03C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C040: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8017C044: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017C048: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8017C04C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8017C050: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8017C054: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x8017C058: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x8017C05C: ori         $t1, $t9, 0x4
    ctx->r9 = ctx->r25 | 0X4;
    // 0x8017C060: jal         0x80111EC0
    // 0x8017C064: sb          $t1, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r9;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_2;
    // 0x8017C064: sb          $t1, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r9;
    after_2:
    // 0x8017C068: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8017C06C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8017C070: sw          $v0, 0x348($a3)
    MEM_W(0X348, ctx->r7) = ctx->r2;
L_8017C074:
    // 0x8017C074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017C078: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017C07C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017C080: jr          $ra
    // 0x8017C084: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8017C084: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_8037F590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F590: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8037F594: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037F598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F59C: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8037F5A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F5A4: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8037F5A8: lw          $t9, 0xBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XBC);
    // 0x8037F5AC: lh          $t6, 0xB8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XB8);
    // 0x8037F5B0: jalr        $t9
    // 0x8037F5B4: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037F5B4: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    after_0:
    // 0x8037F5B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8037F5BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8037F5C0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8037F5C4: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8037F5C8: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x8037F5CC: lh          $t7, 0xA8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA8);
    // 0x8037F5D0: jalr        $t9
    // 0x8037F5D4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037F5D4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x8037F5D8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8037F5DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F5E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8037F5E4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x8037F5E8: jal         0x8037B46C
    // 0x8037F5EC: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_2;
    // 0x8037F5EC: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_2:
    // 0x8037F5F0: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8037F5F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8037F5F8: lw          $t9, 0xD4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XD4);
    // 0x8037F5FC: lh          $t8, 0xD0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XD0);
    // 0x8037F600: jalr        $t9
    // 0x8037F604: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8037F604: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    after_3:
    // 0x8037F608: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
    // 0x8037F60C: lh          $t1, 0x38($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X38);
    // 0x8037F610: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x8037F614: lh          $t4, 0x3A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3A);
    // 0x8037F618: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8037F61C: sh          $t2, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r10;
    // 0x8037F620: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8037F624: sh          $t5, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r13;
    // 0x8037F628: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8037F62C: lw          $a2, 0x44($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X44);
    // 0x8037F630: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8037F634: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8037F638: jal         0x8037B46C
    // 0x8037F63C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_4;
    // 0x8037F63C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_4:
    // 0x8037F640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037F644: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F648: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8037F64C: jr          $ra
    // 0x8037F650: nop

    return;
    // 0x8037F650: nop

;}
RECOMP_FUNC void gmCollisionTestSphere(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE750: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800EE754: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x800EE758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE75C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800EE760: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800EE764: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EE768: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800EE76C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800EE770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EE774: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800EE778: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE77C: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800EE780: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE784: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800EE788: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EE78C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE790: div.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800EE794: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800EE798: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EE79C: div.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800EE7A0: beq         $a3, $at, L_800EE7F4
    if (ctx->r7 == ctx->r1) {
        // 0x800EE7A4: add.s       $f18, $f6, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800EE7F4;
    }
    // 0x800EE7A4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EE7A8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE7AC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EE7B0: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x800EE7B4: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x800EE7B8: nop

    // 0x800EE7BC: bc1fl       L_800EE910
    if (!c1cs) {
        // 0x800EE7C0: lw          $t7, 0x0($t5)
        ctx->r15 = MEM_W(ctx->r13, 0X0);
            goto L_800EE910;
    }
    goto skip_0;
    // 0x800EE7C0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    skip_0:
    // 0x800EE7C4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE7C8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EE7CC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800EE7D0: nop

    // 0x800EE7D4: bc1fl       L_800EE910
    if (!c1cs) {
        // 0x800EE7D8: lw          $t7, 0x0($t5)
        ctx->r15 = MEM_W(ctx->r13, 0X0);
            goto L_800EE910;
    }
    goto skip_1;
    // 0x800EE7D8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    skip_1:
    // 0x800EE7DC: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE7E0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EE7E4: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x800EE7E8: nop

    // 0x800EE7EC: bc1fl       L_800EE910
    if (!c1cs) {
        // 0x800EE7F0: lw          $t7, 0x0($t5)
        ctx->r15 = MEM_W(ctx->r13, 0X0);
            goto L_800EE910;
    }
    goto skip_2;
    // 0x800EE7F0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    skip_2:
L_800EE7F4:
    // 0x800EE7F4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800EE7F8: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800EE7FC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800EE800: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800EE804: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800EE808: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800EE80C: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x800EE810: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800EE814: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800EE818: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800EE81C: jal         0x800ED3C0
    // 0x800EE820: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EE820: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_0:
    // 0x800EE824: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x800EE828: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800EE82C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EE830: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE834: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EE838: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EE83C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EE840: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EE844: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800EE848: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x800EE84C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE850: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EE854: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800EE858: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800EE85C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE860: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EE864: div.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800EE868: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800EE86C: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800EE870: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x800EE874: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EE878: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x800EE87C: jal         0x80018F7C
    // 0x800EE880: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x800EE880: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800EE884: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EE888: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EE88C: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x800EE890: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EE894: nop

    // 0x800EE898: bc1f        L_800EE904
    if (!c1cs) {
        // 0x800EE89C: nop
    
            goto L_800EE904;
    }
    // 0x800EE89C: nop

    // 0x800EE8A0: beq         $v0, $zero, L_800EE8C8
    if (ctx->r2 == 0) {
        // 0x800EE8A4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800EE8C8;
    }
    // 0x800EE8A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EE8A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EE8AC: beq         $v0, $at, L_800EE8DC
    if (ctx->r2 == ctx->r1) {
        // 0x800EE8B0: lw          $a2, 0xC8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XC8);
            goto L_800EE8DC;
    }
    // 0x800EE8B0: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x800EE8B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EE8B8: beq         $v0, $at, L_800EE8FC
    if (ctx->r2 == ctx->r1) {
        // 0x800EE8BC: nop
    
            goto L_800EE8FC;
    }
    // 0x800EE8BC: nop

    // 0x800EE8C0: b           L_800EEE9C
    // 0x800EE8C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EE8C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EE8C8:
    // 0x800EE8C8: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EE8CC: lwc1        $f8, 0x248($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X248);
    // 0x800EE8D0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800EE8D4: b           L_800EEE9C
    // 0x800EE8D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EE8D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EE8DC:
    // 0x800EE8DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EE8E0: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EE8E4: lwc1        $f10, 0x24C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X24C);
    // 0x800EE8E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EE8EC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800EE8F0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800EE8F4: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800EE8F8: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
L_800EE8FC:
    // 0x800EE8FC: b           L_800EEE9C
    // 0x800EE900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EE900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EE904:
    // 0x800EE904: b           L_800EEE9C
    // 0x800EE908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EEE9C;
    // 0x800EE908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EE90C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
L_800EE910:
    // 0x800EE910: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800EE914: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x800EE918: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800EE91C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800EE920: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800EE924: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800EE928: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x800EE92C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800EE930: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800EE934: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800EE938: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800EE93C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800EE940: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800EE944: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x800EE948: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x800EE94C: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800EE950: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800EE954: jal         0x800ED3C0
    // 0x800EE958: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x800EE958: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    after_2:
    // 0x800EE95C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800EE960: jal         0x800ED3C0
    // 0x800EE964: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_3;
    // 0x800EE964: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_3:
    // 0x800EE968: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x800EE96C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE970: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE974: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE978: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EE97C: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EE980: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EE984: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EE988: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EE98C: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x800EE990: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE994: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800EE998: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800EE99C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800EE9A0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE9A4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800EE9A8: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800EE9AC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EE9B0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800EE9B4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE9B8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800EE9BC: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800EE9C0: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EE9C4: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x800EE9C8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE9CC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800EE9D0: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800EE9D4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE9D8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x800EE9DC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE9E0: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800EE9E4: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800EE9E8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800EE9EC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EE9F0: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800EE9F4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800EE9F8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EE9FC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800EEA00: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800EEA04: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800EEA08: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800EEA0C: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800EEA10: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800EEA14: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EEA18: div.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800EEA1C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800EEA20: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800EEA24: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEA28: div.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EEA2C: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x800EEA30: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800EEA34: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800EEA38: div.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800EEA3C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800EEA40: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800EEA44: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800EEA48: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800EEA4C: div.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EEA50: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800EEA54: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800EEA58: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEA5C: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800EEA60: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EEA64: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800EEA68: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EEA6C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800EEA70: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800EEA74: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800EEA78: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EEA7C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EEA80: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800EEA84: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EEA88: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EEA8C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EEA90: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800EEA94: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EEA98: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EEA9C: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EEAA0: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EEAA4: c.eq.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl == ctx->f14.fl;
    // 0x800EEAA8: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x800EEAAC: bc1t        L_800EEE0C
    if (c1cs) {
        // 0x800EEAB0: nop
    
            goto L_800EEE0C;
    }
    // 0x800EEAB0: nop

    // 0x800EEAB4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800EEAB8: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EEABC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800EEAC0: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EEAC4: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EEAC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEACC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EEAD0: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EEAD4: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800EEAD8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EEADC: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEAE0: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EEAE4: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800EEAE8: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800EEAEC: nop

    // 0x800EEAF0: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800EEAF4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EEAF8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800EEAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EEB00: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800EEB04: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EEB08: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800EEB0C: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EEB10: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EEB14: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EEB18: bc1f        L_800EEB28
    if (!c1cs) {
        // 0x800EEB1C: swc1        $f10, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
            goto L_800EEB28;
    }
    // 0x800EEB1C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800EEB20: b           L_800EEE9C
    // 0x800EEB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EEE9C;
    // 0x800EEB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EEB28:
    // 0x800EEB28: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EEB2C: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x800EEB30: nop

    // 0x800EEB34: bc1fl       L_800EEBA8
    if (!c1cs) {
        // 0x800EEB38: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_800EEBA8;
    }
    goto skip_3;
    // 0x800EEB38: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_3:
    // 0x800EEB3C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800EEB40: nop

    // 0x800EEB44: bc1f        L_800EEB64
    if (!c1cs) {
        // 0x800EEB48: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800EEB64;
    }
L_800EEB48:
    // 0x800EEB48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EEB4C: jal         0x80023624
    // 0x800EEB50: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    syDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x800EEB50: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    after_4:
    // 0x800EEB54: jal         0x800A3040
    // 0x800EEB58: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_5;
    // 0x800EEB58: nop

    after_5:
    // 0x800EEB5C: b           L_800EEB48
    // 0x800EEB60: nop

        goto L_800EEB48;
    // 0x800EEB60: nop

L_800EEB64:
    // 0x800EEB64: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800EEB68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEB6C: div.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800EEB70: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800EEB74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800EEB78: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x800EEB7C: bc1f        L_800EEB9C
    if (!c1cs) {
        // 0x800EEB80: nop
    
            goto L_800EEB9C;
    }
    // 0x800EEB80: nop

    // 0x800EEB84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EEB88: nop

    // 0x800EEB8C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800EEB90: nop

    // 0x800EEB94: bc1tl       L_800EEC9C
    if (c1cs) {
        // 0x800EEB98: lw          $v0, 0xC0($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC0);
            goto L_800EEC9C;
    }
    goto skip_4;
    // 0x800EEB98: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    skip_4:
L_800EEB9C:
    // 0x800EEB9C: b           L_800EEE9C
    // 0x800EEBA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EEE9C;
    // 0x800EEBA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEBA4: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
L_800EEBA8:
    // 0x800EEBA8: nop

    // 0x800EEBAC: bc1f        L_800EEBCC
    if (!c1cs) {
        // 0x800EEBB0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800EEBCC;
    }
L_800EEBB0:
    // 0x800EEBB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EEBB4: jal         0x80023624
    // 0x800EEBB8: addiu       $a0, $a0, 0x220
    ctx->r4 = ADD32(ctx->r4, 0X220);
    syDebugPrintf(rdram, ctx);
        goto after_6;
    // 0x800EEBB8: addiu       $a0, $a0, 0x220
    ctx->r4 = ADD32(ctx->r4, 0X220);
    after_6:
    // 0x800EEBBC: jal         0x800A3040
    // 0x800EEBC0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_7;
    // 0x800EEBC0: nop

    after_7:
    // 0x800EEBC4: b           L_800EEBB0
    // 0x800EEBC8: nop

        goto L_800EEBB0;
    // 0x800EEBC8: nop

L_800EEBCC:
    // 0x800EEBCC: jal         0x80033510
    // 0x800EEBD0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x800EEBD0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x800EEBD4: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EEBD8: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EEBDC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EEBE0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800EEBE4: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800EEBE8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800EEBEC: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800EEBF0: jal         0x80033510
    // 0x800EEBF4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x800EEBF4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x800EEBF8: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EEBFC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EEC00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EEC04: sub.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800EEC08: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800EEC0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEC10: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EEC14: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x800EEC18: nop

    // 0x800EEC1C: bc1f        L_800EEC44
    if (!c1cs) {
        // 0x800EEC20: swc1        $f2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
            goto L_800EEC44;
    }
    // 0x800EEC20: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800EEC24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EEC28: nop

    // 0x800EEC2C: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x800EEC30: nop

    // 0x800EEC34: bc1fl       L_800EEC48
    if (!c1cs) {
        // 0x800EEC38: c.le.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
            goto L_800EEC48;
    }
    goto skip_5;
    // 0x800EEC38: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    skip_5:
    // 0x800EEC3C: b           L_800EEC98
    // 0x800EEC40: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
        goto L_800EEC98;
    // 0x800EEC40: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
L_800EEC44:
    // 0x800EEC44: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
L_800EEC48:
    // 0x800EEC48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEC4C: bc1f        L_800EEC74
    if (!c1cs) {
        // 0x800EEC50: nop
    
            goto L_800EEC74;
    }
    // 0x800EEC50: nop

    // 0x800EEC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EEC58: nop

    // 0x800EEC5C: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x800EEC60: nop

    // 0x800EEC64: bc1f        L_800EEC74
    if (!c1cs) {
        // 0x800EEC68: nop
    
            goto L_800EEC74;
    }
    // 0x800EEC68: nop

    // 0x800EEC6C: b           L_800EEC98
    // 0x800EEC70: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
        goto L_800EEC98;
    // 0x800EEC70: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
L_800EEC74:
    // 0x800EEC74: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800EEC78: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800EEC7C: nop

    // 0x800EEC80: bc1f        L_800EEC90
    if (!c1cs) {
        // 0x800EEC84: nop
    
            goto L_800EEC90;
    }
    // 0x800EEC84: nop

    // 0x800EEC88: b           L_800EEC98
    // 0x800EEC8C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
        goto L_800EEC98;
    // 0x800EEC8C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
L_800EEC90:
    // 0x800EEC90: b           L_800EEE9C
    // 0x800EEC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EEE9C;
    // 0x800EEC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EEC98:
    // 0x800EEC98: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800EEC9C:
    // 0x800EEC9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EECA0: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EECA4: beql        $v0, $zero, L_800EECC8
    if (ctx->r2 == 0) {
        // 0x800EECA8: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_800EECC8;
    }
    goto skip_6;
    // 0x800EECA8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_6:
    // 0x800EECAC: beq         $v0, $at, L_800EED34
    if (ctx->r2 == ctx->r1) {
        // 0x800EECB0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800EED34;
    }
    // 0x800EECB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EECB4: beq         $v0, $at, L_800EEE04
    if (ctx->r2 == ctx->r1) {
        // 0x800EECB8: nop
    
            goto L_800EEE04;
    }
    // 0x800EECB8: nop

    // 0x800EECBC: b           L_800EEE9C
    // 0x800EECC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EECC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EECC4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
L_800EECC8:
    // 0x800EECC8: nop

    // 0x800EECCC: bc1fl       L_800EECE0
    if (!c1cs) {
        // 0x800EECD0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800EECE0;
    }
    goto skip_7;
    // 0x800EECD0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_7:
    // 0x800EECD4: b           L_800EECE0
    // 0x800EECD8: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_800EECE0;
    // 0x800EECD8: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x800EECDC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800EECE0:
    // 0x800EECE0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EECE4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EECE8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EECEC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800EECF0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800EECF4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EECF8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EECFC: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EED00: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800EED04: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EED08: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EED0C: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EED10: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EED14: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800EED18: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EED1C: jal         0x800191FC
    // 0x800EED20: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_10;
    // 0x800EED20: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x800EED24: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EED28: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800EED2C: b           L_800EEE9C
    // 0x800EED30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EED30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EED34:
    // 0x800EED34: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800EED38: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800EED3C: bc1fl       L_800EED50
    if (!c1cs) {
        // 0x800EED40: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800EED50;
    }
    goto skip_8;
    // 0x800EED40: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_8:
    // 0x800EED44: b           L_800EED50
    // 0x800EED48: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_800EED50;
    // 0x800EED48: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x800EED4C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800EED50:
    // 0x800EED50: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EED54: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EED58: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EED5C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EED60: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x800EED64: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x800EED68: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EED6C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EED70: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EED74: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x800EED78: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800EED7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EED80: bc1f        L_800EEDA8
    if (!c1cs) {
        // 0x800EED84: swc1        $f10, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
            goto L_800EEDA8;
    }
    // 0x800EED84: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x800EED88: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800EED8C: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EED90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EED94: bc1f        L_800EEDA8
    if (!c1cs) {
        // 0x800EED98: nop
    
            goto L_800EEDA8;
    }
    // 0x800EED98: nop

    // 0x800EED9C: lwc1        $f4, 0x250($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X250);
    // 0x800EEDA0: b           L_800EEDBC
    // 0x800EEDA4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_800EEDBC;
    // 0x800EEDA4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_800EEDA8:
    // 0x800EEDA8: jal         0x800191FC
    // 0x800EEDAC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_11;
    // 0x800EEDAC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_11:
    // 0x800EEDB0: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EEDB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EEDB8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800EEDBC:
    // 0x800EEDBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EEDC0: lwc1        $f6, 0x254($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X254);
    // 0x800EEDC4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EEDC8: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x800EEDCC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800EEDD0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800EEDD4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800EEDD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEDDC: bc1tl       L_800EEDF8
    if (c1cs) {
        // 0x800EEDE0: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800EEDF8;
    }
    goto skip_9;
    // 0x800EEDE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_9:
    // 0x800EEDE4: jal         0x80019980
    // 0x800EEDE8: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    syVectorNormCross3D(rdram, ctx);
        goto after_12;
    // 0x800EEDE8: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    after_12:
    // 0x800EEDEC: b           L_800EEE9C
    // 0x800EEDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EEDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEDF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800EEDF8:
    // 0x800EEDF8: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x800EEDFC: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800EEE00: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_800EEE04:
    // 0x800EEE04: b           L_800EEE9C
    // 0x800EEE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EEE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEE0C:
    // 0x800EEE0C: jal         0x80018F7C
    // 0x800EEE10: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    syVectorMag3D(rdram, ctx);
        goto after_13;
    // 0x800EEE10: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    after_13:
    // 0x800EEE14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EEE18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EEE1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EEE20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEE24: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EEE28: nop

    // 0x800EEE2C: bc1f        L_800EEE9C
    if (!c1cs) {
        // 0x800EEE30: nop
    
            goto L_800EEE9C;
    }
    // 0x800EEE30: nop

    // 0x800EEE34: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x800EEE38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EEE3C: beql        $v0, $zero, L_800EEE68
    if (ctx->r2 == 0) {
        // 0x800EEE40: lw          $v0, 0xC4($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC4);
            goto L_800EEE68;
    }
    goto skip_10;
    // 0x800EEE40: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    skip_10:
    // 0x800EEE44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EEE48: beq         $v0, $at, L_800EEE78
    if (ctx->r2 == ctx->r1) {
        // 0x800EEE4C: lw          $a2, 0xC8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XC8);
            goto L_800EEE78;
    }
    // 0x800EEE4C: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x800EEE50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EEE54: beq         $v0, $at, L_800EEE94
    if (ctx->r2 == ctx->r1) {
        // 0x800EEE58: nop
    
            goto L_800EEE94;
    }
    // 0x800EEE58: nop

    // 0x800EEE5C: b           L_800EEE9C
    // 0x800EEE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EEE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEE64: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
L_800EEE68:
    // 0x800EEE68: lwc1        $f4, 0x258($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X258);
    // 0x800EEE6C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800EEE70: b           L_800EEE9C
    // 0x800EEE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EEE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEE78:
    // 0x800EEE78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EEE7C: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x800EEE80: lwc1        $f6, 0x25C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X25C);
    // 0x800EEE84: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800EEE88: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800EEE8C: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800EEE90: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
L_800EEE94:
    // 0x800EEE94: b           L_800EEE9C
    // 0x800EEE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EEE9C;
    // 0x800EEE98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEE9C:
    // 0x800EEE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEEA0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x800EEEA4: jr          $ra
    // 0x800EEEA8: nop

    return;
    // 0x800EEEA8: nop

;}
RECOMP_FUNC void n_alSynSetPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DA20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002DA24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DA28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002DA2C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002DA30: beql        $t6, $zero, L_8002DA8C
    if (ctx->r14 == 0) {
        // 0x8002DA34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002DA8C;
    }
    goto skip_0;
    // 0x8002DA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002DA38: jal         0x8002C618
    // 0x8002DA3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002DA3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002DA40: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002DA44: beq         $v0, $zero, L_8002DA88
    if (ctx->r2 == 0) {
        // 0x8002DA48: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002DA88;
    }
    // 0x8002DA48: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002DA4C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002DA50: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002DA54: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002DA58: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8002DA5C: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002DA60: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002DA64: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002DA68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002DA6C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002DA70: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002DA74: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002DA78: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002DA7C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8002DA80: jal         0x8002A230
    // 0x8002DA84: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002DA84: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    after_1:
L_8002DA88:
    // 0x8002DA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002DA8C:
    // 0x8002DA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002DA90: jr          $ra
    // 0x8002DA94: nop

    return;
    // 0x8002DA94: nop

;}
RECOMP_FUNC void mnVSModeGetTimeStockValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B70: jal         0x80132B38
    // 0x80132B74: nop

    mnVSModeIsTime(rdram, ctx);
        goto after_0;
    // 0x80132B74: nop

    after_0:
    // 0x80132B78: beq         $v0, $zero, L_80132B8C
    if (ctx->r2 == 0) {
        // 0x80132B7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132B8C;
    }
    // 0x80132B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132B84: b           L_80132B98
    // 0x80132B88: lw          $v0, 0x4950($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4950);
        goto L_80132B98;
    // 0x80132B88: lw          $v0, 0x4950($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4950);
L_80132B8C:
    // 0x80132B8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132B90: lw          $v0, 0x4954($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4954);
    // 0x80132B94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80132B98:
    // 0x80132B98: jr          $ra
    // 0x80132B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lbCommonDecodeBitmapSiz4b(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CB678: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CB67C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CB680: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CB684: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x800CB688: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CB68C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CB690: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CB694: bne         $at, $zero, L_800CB720
    if (ctx->r1 != 0) {
        // 0x800CB698: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_800CB720;
    }
    // 0x800CB698: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_800CB69C:
    // 0x800CB69C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800CB6A0: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x800CB6A4: jal         0x800CB644
    // 0x800CB6A8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    lbCommonGetBitmapDecodeNibble(rdram, ctx);
        goto after_0;
    // 0x800CB6A8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x800CB6AC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800CB6B0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800CB6B4: andi        $a0, $a0, 0xC
    ctx->r4 = ctx->r4 & 0XC;
    // 0x800CB6B8: sra         $a0, $a0, 2
    ctx->r4 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800CB6BC: jal         0x800CB644
    // 0x800CB6C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    lbCommonGetBitmapDecodeNibble(rdram, ctx);
        goto after_1;
    // 0x800CB6C0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_1:
    // 0x800CB6C4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800CB6C8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800CB6CC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800CB6D0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800CB6D4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800CB6D8: andi        $a0, $a0, 0x30
    ctx->r4 = ctx->r4 & 0X30;
    // 0x800CB6DC: sra         $a0, $a0, 4
    ctx->r4 = S32(SIGNED(ctx->r4) >> 4);
    // 0x800CB6E0: jal         0x800CB644
    // 0x800CB6E4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    lbCommonGetBitmapDecodeNibble(rdram, ctx);
        goto after_2;
    // 0x800CB6E4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_2:
    // 0x800CB6E8: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x800CB6EC: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800CB6F0: andi        $a0, $a0, 0xC0
    ctx->r4 = ctx->r4 & 0XC0;
    // 0x800CB6F4: sra         $a0, $a0, 6
    ctx->r4 = S32(SIGNED(ctx->r4) >> 6);
    // 0x800CB6F8: jal         0x800CB644
    // 0x800CB6FC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    lbCommonGetBitmapDecodeNibble(rdram, ctx);
        goto after_3;
    // 0x800CB6FC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_3:
    // 0x800CB700: lbu         $t9, -0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X1);
    // 0x800CB704: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800CB708: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x800CB70C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x800CB710: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800CB714: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x800CB718: beq         $at, $zero, L_800CB69C
    if (ctx->r1 == 0) {
        // 0x800CB71C: sb          $t1, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r9;
            goto L_800CB69C;
    }
    // 0x800CB71C: sb          $t1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r9;
L_800CB720:
    // 0x800CB720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CB724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB728: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB72C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CB730: jr          $ra
    // 0x800CB734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CB734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftNessSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153BD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153BDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80153BE0: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x80153BE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80153BE8: jal         0x800E6F24
    // 0x80153BEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80153BEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80153BF0: jal         0x800E0830
    // 0x80153BF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80153BF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80153BF8: jal         0x80153BB8
    // 0x80153BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80153BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80153C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153C08: jr          $ra
    // 0x80153C0C: nop

    return;
    // 0x80153C0C: nop

;}
RECOMP_FUNC void wpYoshiStarProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016C6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C6F8: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016C6FC: jal         0x80100480
    // 0x8016C700: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016C700: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016C704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016C70C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016C710: jr          $ra
    // 0x8016C714: nop

    return;
    // 0x8016C714: nop

;}
RECOMP_FUNC void ifScreenFlashProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115DAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80115DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115DB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80115DB8: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    // 0x80115DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80115DC0: jal         0x800E0880
    // 0x80115DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftMainUpdateColAnim(rdram, ctx);
        goto after_0;
    // 0x80115DC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80115DC8: beq         $v0, $zero, L_80115DD8
    if (ctx->r2 == 0) {
        // 0x80115DCC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80115DD8;
    }
    // 0x80115DCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80115DD0: jal         0x800E9838
    // 0x80115DD4: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    ftParamResetColAnim(rdram, ctx);
        goto after_1;
    // 0x80115DD4: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    after_1:
L_80115DD8:
    // 0x80115DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115DE0: jr          $ra
    // 0x80115DE4: nop

    return;
    // 0x80115DE4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeBoss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321F8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801321FC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80132200: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80132204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132208: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x8013220C: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80132210:
    // 0x80132210: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132214: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132218: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013221C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132220: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132224: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132228: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013222C: bne         $t7, $t0, L_80132210
    if (ctx->r15 != ctx->r8) {
        // 0x80132230: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132210;
    }
    // 0x80132230: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132234: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132238: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8013223C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80132240: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132244: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80132248: jal         0x800EC0EC
    // 0x8013224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8013224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80132250: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132254: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132258: lw          $t2, 0x4CD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4CD8);
    // 0x8013225C: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80132260: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80132264: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80132268: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8013226C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80132270: jal         0x800D7F3C
    // 0x80132274: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80132274: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x80132278: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013227C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80132280: sw          $v0, 0x4CF4($at)
    MEM_W(0X4CF4, ctx->r1) = ctx->r2;
    // 0x80132284: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x80132288: jal         0x803905CC
    // 0x8013228C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013228C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80132290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132294: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80132298: jr          $ra
    // 0x8013229C: nop

    return;
    // 0x8013229C: nop

;}
RECOMP_FUNC void ftParamsUpdateFighterPartsTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB648: beq         $a0, $zero, L_800EB6E4
    if (ctx->r4 == 0) {
        // 0x800EB64C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800EB6E4;
    }
    // 0x800EB64C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800EB650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800EB654: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_800EB658:
    // 0x800EB658: beql        $v1, $zero, L_800EB678
    if (ctx->r3 == 0) {
        // 0x800EB65C: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_800EB678;
    }
    goto skip_0;
    // 0x800EB65C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x800EB660: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800EB664: bnel        $a2, $t6, L_800EB674
    if (ctx->r6 != ctx->r14) {
        // 0x800EB668: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_800EB674;
    }
    goto skip_1;
    // 0x800EB668: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_1:
    // 0x800EB66C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800EB670: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800EB674:
    // 0x800EB674: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_800EB678:
    // 0x800EB678: beq         $v1, $zero, L_800EB688
    if (ctx->r3 == 0) {
        // 0x800EB67C: nop
    
            goto L_800EB688;
    }
    // 0x800EB67C: nop

    // 0x800EB680: b           L_800EB6DC
    // 0x800EB684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB6DC;
    // 0x800EB684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB688:
    // 0x800EB688: bnel        $v0, $a0, L_800EB69C
    if (ctx->r2 != ctx->r4) {
        // 0x800EB68C: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800EB69C;
    }
    goto skip_2;
    // 0x800EB68C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x800EB690: b           L_800EB6DC
    // 0x800EB694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB6DC;
    // 0x800EB694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB698: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800EB69C:
    // 0x800EB69C: beql        $v1, $zero, L_800EB6B0
    if (ctx->r3 == 0) {
        // 0x800EB6A0: lw          $v1, 0x14($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X14);
            goto L_800EB6B0;
    }
    goto skip_3;
    // 0x800EB6A0: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    skip_3:
    // 0x800EB6A4: b           L_800EB6DC
    // 0x800EB6A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB6DC;
    // 0x800EB6A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB6AC:
    // 0x800EB6AC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
L_800EB6B0:
    // 0x800EB6B0: bnel        $a0, $v1, L_800EB6C4
    if (ctx->r4 != ctx->r3) {
        // 0x800EB6B4: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_800EB6C4;
    }
    goto skip_4;
    // 0x800EB6B4: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_4:
    // 0x800EB6B8: b           L_800EB6DC
    // 0x800EB6BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB6DC;
    // 0x800EB6BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB6C0: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_800EB6C4:
    // 0x800EB6C4: beq         $a1, $zero, L_800EB6D4
    if (ctx->r5 == 0) {
        // 0x800EB6C8: nop
    
            goto L_800EB6D4;
    }
    // 0x800EB6C8: nop

    // 0x800EB6CC: b           L_800EB6DC
    // 0x800EB6D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800EB6DC;
    // 0x800EB6D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800EB6D4:
    // 0x800EB6D4: b           L_800EB6AC
    // 0x800EB6D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB6AC;
    // 0x800EB6D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB6DC:
    // 0x800EB6DC: bnel        $v0, $zero, L_800EB658
    if (ctx->r2 != 0) {
        // 0x800EB6E0: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_800EB658;
    }
    goto skip_5;
    // 0x800EB6E0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_5:
L_800EB6E4:
    // 0x800EB6E4: jr          $ra
    // 0x800EB6E8: nop

    return;
    // 0x800EB6E8: nop

;}
RECOMP_FUNC void ftSamusSpecialAirLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E10C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E114: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E118: jal         0x800DE6E4
    // 0x8015E11C: addiu       $a1, $a1, -0x1ED0
    ctx->r5 = ADD32(ctx->r5, -0X1ED0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015E11C: addiu       $a1, $a1, -0x1ED0
    ctx->r5 = ADD32(ctx->r5, -0X1ED0);
    after_0:
    // 0x8015E120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E128: jr          $ra
    // 0x8015E12C: nop

    return;
    // 0x8015E12C: nop

;}
RECOMP_FUNC void ftFoxSpecialHiProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C264: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015C268: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x8015C26C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8015C270: beq         $t7, $zero, L_8015C28C
    if (ctx->r15 == 0) {
        // 0x8015C274: nop
    
            goto L_8015C28C;
    }
    // 0x8015C274: nop

    // 0x8015C278: lw          $t8, 0xB2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB2C);
    // 0x8015C27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015C280: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x8015C284: bne         $at, $zero, L_8015C294
    if (ctx->r1 != 0) {
        // 0x8015C288: nop
    
            goto L_8015C294;
    }
    // 0x8015C288: nop

L_8015C28C:
    // 0x8015C28C: jr          $ra
    // 0x8015C290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8015C290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015C294:
    // 0x8015C294: jr          $ra
    // 0x8015C298: nop

    return;
    // 0x8015C298: nop

;}
RECOMP_FUNC void mvOpeningCliffMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131F30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F3C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80131F40: jal         0x80009968
    // 0x80131F44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F48: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131F4C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131F50: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131F54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F58: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131F5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F60: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131F64: jal         0x80009DF4
    // 0x80131F68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131F68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131F6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F70: addiu       $a1, $a1, 0x1D8C
    ctx->r5 = ADD32(ctx->r5, 0X1D8C);
    // 0x80131F74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F7C: jal         0x80008188
    // 0x80131F80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80131F80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80131F84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F88: lw          $t7, 0x299C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X299C);
    // 0x80131F8C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80131F90: addiu       $v1, $v1, -0x4B00
    ctx->r3 = ADD32(ctx->r3, -0X4B00);
    // 0x80131F94: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80131F98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F9C: jal         0x800CCFDC
    // 0x80131FA0: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131FA0: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_3:
    // 0x80131FA4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80131FA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131FAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80131FB4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131FB8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131FBC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80131FC0: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80131FC4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131FC8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80131FCC: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80131FD0: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80131FD4: lw          $t0, 0x299C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X299C);
    // 0x80131FD8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131FDC: jal         0x800CCFDC
    // 0x80131FE0: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131FE0: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    after_4:
    // 0x80131FE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131FE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FEC: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131FF0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80131FF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80131FFC: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80132000: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132004: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80132008: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8013200C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132010: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013201C: jr          $ra
    // 0x80132020: nop

    return;
    // 0x80132020: nop

;}
RECOMP_FUNC void unref_80004338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004338: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000433C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004340: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80004344: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80004348: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000434C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80004350: jal         0x80004284
    // 0x80004354: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syControllerDispatchEvent(rdram, ctx);
        goto after_0;
    // 0x80004354: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80004358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000435C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80004360: jr          $ra
    // 0x80004364: nop

    return;
    // 0x80004364: nop

;}
RECOMP_FUNC void mvOpeningYoshiFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDC0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDC4: addiu       $v0, $v0, -0x1DD8
    ctx->r2 = ADD32(ctx->r2, -0X1DD8);
    // 0x8018DDC8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DDD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DDDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDE0: jal         0x8039076C
    // 0x8018DDE4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDE4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDE8: beq         $v0, $zero, L_8018DE08
    if (ctx->r2 == 0) {
        // 0x8018DDEC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DE08;
    }
    // 0x8018DDEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDF4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDF8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDFC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DE00: jal         0x80005C74
    // 0x8018DE04: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DE04: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DE08:
    // 0x8018DE08: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE0C: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE10: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DE14: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE18: bnel        $v0, $at, L_8018DE4C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE1C: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE4C;
    }
    goto skip_0;
    // 0x8018DE1C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DE20: jal         0x80009A84
    // 0x8018DE24: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DE24: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    after_2:
    // 0x8018DE28: jal         0x8018D61C
    // 0x8018DE2C: nop

    mvOpeningYoshiMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE2C: nop

    after_3:
    // 0x8018DE30: jal         0x8018D974
    // 0x8018DE34: nop

    mvOpeningYoshiMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE34: nop

    after_4:
    // 0x8018DE38: jal         0x8018DA90
    // 0x8018DE3C: nop

    mvOpeningYoshiMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE3C: nop

    after_5:
    // 0x8018DE40: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE44: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE48: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE4C:
    // 0x8018DE4C: bne         $v0, $at, L_8018DE6C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE50: addiu       $t1, $zero, 0x25
        ctx->r9 = ADD32(0, 0X25);
            goto L_8018DE6C;
    }
    // 0x8018DE50: addiu       $t1, $zero, 0x25
    ctx->r9 = ADD32(0, 0X25);
    // 0x8018DE54: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE58: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE5C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE60: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE64: jal         0x80005C74
    // 0x8018DE68: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE68: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE6C:
    // 0x8018DE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE74: jr          $ra
    // 0x8018DE78: nop

    return;
    // 0x8018DE78: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157F08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157F0C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80157F10: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80157F14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157F18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157F1C: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x80157F20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157F24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80157F28: jal         0x800E6F24
    // 0x80157F2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157F2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80157F30: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80157F34: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80157F38: addiu       $t8, $t8, 0x77A0
    ctx->r24 = ADD32(ctx->r24, 0X77A0);
    // 0x80157F3C: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x80157F40: jal         0x800E0830
    // 0x80157F44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80157F44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80157F48: jal         0x80157E7C
    // 0x80157F4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftKirbyCopyDonkeySpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80157F4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80157F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157F54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157F58: jr          $ra
    // 0x80157F5C: nop

    return;
    // 0x80157F5C: nop

;}
RECOMP_FUNC void grZebesAcidUpdateRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108268: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010826C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80108270: lbu         $v0, 0x18($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X18);
    // 0x80108274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010827C: bnel        $v0, $zero, L_801082A4
    if (ctx->r2 != 0) {
        // 0x80108280: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801082A4;
    }
    goto skip_0;
    // 0x80108280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80108284: jal         0x801008F4
    // 0x80108288: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80108288: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8010828C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80108290: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80108294: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80108298: sb          $t6, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r14;
    // 0x8010829C: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x801082A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801082A4:
    // 0x801082A4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801082A8: sb          $t7, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r15;
    // 0x801082AC: jr          $ra
    // 0x801082B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801082B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftLinkSpecialHiUpdateWeaponVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163D44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163D4C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163D50: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80163D54: beql        $v1, $zero, L_80163D88
    if (ctx->r3 == 0) {
        // 0x80163D58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80163D88;
    }
    goto skip_0;
    // 0x80163D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80163D5C: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x80163D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80163D64: jal         0x80163C2C
    // 0x80163D68: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    ftLinkSpecialHiUpdateWeaponAttack(rdram, ctx);
        goto after_0;
    // 0x80163D68: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80163D6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80163D70: jal         0x80163B80
    // 0x80163D74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftLinkSpecialHiUpdateWeaponPos(rdram, ctx);
        goto after_1;
    // 0x80163D74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80163D78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80163D7C: jal         0x80163BF0
    // 0x80163D80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftLinkSpecialHiDecWeaponLifeCheckDestroy(rdram, ctx);
        goto after_2;
    // 0x80163D80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80163D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80163D88:
    // 0x80163D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163D8C: jr          $ra
    // 0x80163D90: nop

    return;
    // 0x80163D90: nop

;}
RECOMP_FUNC void ftCommonHammerKneeBendProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147F54: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80147F58: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x80147F5C: lwc1        $f6, 0xB18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x80147F60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80147F64: nop

    // 0x80147F68: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80147F6C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80147F70: nop

    // 0x80147F74: bc1f        L_80147F80
    if (!c1cs) {
        // 0x80147F78: nop
    
            goto L_80147F80;
    }
    // 0x80147F78: nop

    // 0x80147F7C: swc1        $f0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f0.u32l;
L_80147F80:
    // 0x80147F80: jr          $ra
    // 0x80147F84: nop

    return;
    // 0x80147F84: nop

;}
RECOMP_FUNC void efManagerImpactWaveProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFB74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFB78: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800FFB7C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800FFB80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFB84: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x800FFB88: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800FFB8C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FFB90: lbu         $v1, 0x18($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X18);
    // 0x800FFB94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FFB98: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800FFB9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FFBA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FFBA4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800FFBA8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FFBAC: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800FFBB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FFBB4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800FFBB8: ori         $t3, $t3, 0x49D8
    ctx->r11 = ctx->r11 | 0X49D8;
    // 0x800FFBBC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FFBC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FFBC4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800FFBC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800FFBCC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FFBD0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800FFBD4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800FFBD8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800FFBDC: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800FFBE0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800FFBE4: lbu         $t6, -0x2128($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2128);
    // 0x800FFBE8: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800FFBEC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FFBF0: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x800FFBF4: lbu         $t3, -0x2138($t9)
    ctx->r11 = MEM_BU(ctx->r25, -0X2138);
    // 0x800FFBF8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800FFBFC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800FFC00: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FFC04: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800FFC08: lbu         $t6, -0x2130($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2130);
    // 0x800FFC0C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800FFC10: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800FFC14: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x800FFC18: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800FFC1C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800FFC20: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800FFC24: or          $t3, $t5, $t9
    ctx->r11 = ctx->r13 | ctx->r25;
    // 0x800FFC28: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x800FFC2C: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800FFC30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800FFC34: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800FFC38: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800FFC3C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FFC40: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800FFC44: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800FFC48: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800FFC4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FFC50: lbu         $t8, -0x2110($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2110);
    // 0x800FFC54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FFC58: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800FFC5C: andi        $t4, $t8, 0xFF
    ctx->r12 = ctx->r24 & 0XFF;
    // 0x800FFC60: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FFC64: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800FFC68: lbu         $t8, -0x2118($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2118);
    // 0x800FFC6C: lbu         $t7, -0x2120($t6)
    ctx->r15 = MEM_BU(ctx->r14, -0X2120);
    // 0x800FFC70: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x800FFC74: andi        $t4, $t8, 0xFF
    ctx->r12 = ctx->r24 & 0XFF;
    // 0x800FFC78: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x800FFC7C: or          $t9, $t3, $t5
    ctx->r25 = ctx->r11 | ctx->r13;
    // 0x800FFC80: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800FFC84: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800FFC88: ori         $t3, $t7, 0xFF
    ctx->r11 = ctx->r15 | 0XFF;
    // 0x800FFC8C: jal         0x80013E68
    // 0x800FFC90: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    gcDrawDObjDLHead0(rdram, ctx);
        goto after_0;
    // 0x800FFC90: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    after_0:
    // 0x800FFC94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFC98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFC9C: jr          $ra
    // 0x800FFCA0: nop

    return;
    // 0x800FFCA0: nop

;}
RECOMP_FUNC void ftCommonAttack11ProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E91C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014E920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E924: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014E928: lw          $v0, 0xB1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB1C);
    // 0x8014E92C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8014E930: beq         $at, $zero, L_8014E954
    if (ctx->r1 == 0) {
        // 0x8014E934: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8014E954;
    }
    // 0x8014E934: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8014E938: sw          $t6, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = ctx->r14;
    // 0x8014E93C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014E940: jal         0x80149E24
    // 0x8014E944: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonCatchCheckInterruptAttack11(rdram, ctx);
        goto after_0;
    // 0x8014E944: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014E948: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014E94C: bne         $v0, $zero, L_8014E9A4
    if (ctx->r2 != 0) {
        // 0x8014E950: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014E9A4;
    }
    // 0x8014E950: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8014E954:
    // 0x8014E954: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8014E958: jal         0x8014F4EC
    // 0x8014E95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonAttack100StartCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014E95C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8014E960: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014E964: bne         $v0, $zero, L_8014E9A4
    if (ctx->r2 != 0) {
        // 0x8014E968: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014E9A4;
    }
    // 0x8014E968: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014E96C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014E970: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8014E974: beq         $v0, $at, L_8014E984
    if (ctx->r2 == ctx->r1) {
        // 0x8014E978: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8014E984;
    }
    // 0x8014E978: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8014E97C: bne         $v0, $at, L_8014E99C
    if (ctx->r2 != ctx->r1) {
        // 0x8014E980: nop
    
            goto L_8014E99C;
    }
    // 0x8014E980: nop

L_8014E984:
    // 0x8014E984: jal         0x8014EEC0
    // 0x8014E988: nop

    ftCommonAttack11CheckGoto(rdram, ctx);
        goto after_2;
    // 0x8014E988: nop

    after_2:
    // 0x8014E98C: beql        $v0, $zero, L_8014E9A8
    if (ctx->r2 == 0) {
        // 0x8014E990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014E9A8;
    }
    goto skip_0;
    // 0x8014E990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014E994: b           L_8014E9A8
    // 0x8014E998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E9A8;
    // 0x8014E998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E99C:
    // 0x8014E99C: jal         0x8014EF50
    // 0x8014E9A0: nop

    ftCommonAttack12CheckGoto(rdram, ctx);
        goto after_3;
    // 0x8014E9A0: nop

    after_3:
L_8014E9A4:
    // 0x8014E9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E9A8:
    // 0x8014E9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014E9AC: jr          $ra
    // 0x8014E9B0: nop

    return;
    // 0x8014E9B0: nop

;}
RECOMP_FUNC void sc1PGameBossDefeatInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F75C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F764: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018F768: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018F76C: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
    // 0x8018F770: jal         0x8018F540
    // 0x8018F774: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    sc1PGameBossHidePlayerTagAll(rdram, ctx);
        goto after_0;
    // 0x8018F774: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018F778: jal         0x8010F76C
    // 0x8018F77C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ifCommonPlayerDamageStartBreakAnim(rdram, ctx);
        goto after_1;
    // 0x8018F77C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8018F780: jal         0x8018F4B0
    // 0x8018F784: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    sc1PGameBossSetCameraZoom(rdram, ctx);
        goto after_2;
    // 0x8018F784: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8018F788: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018F78C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F790: addiu       $a1, $a1, -0x910
    ctx->r5 = ADD32(ctx->r5, -0X910);
    // 0x8018F794: addiu       $a0, $a0, -0xA14
    ctx->r4 = ADD32(ctx->r4, -0XA14);
    // 0x8018F798: addiu       $a2, $zero, 0x2B7
    ctx->r6 = ADD32(0, 0X2B7);
    // 0x8018F79C: jal         0x80114B80
    // 0x8018F7A0: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_3;
    // 0x8018F7A0: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_3:
    // 0x8018F7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F7A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018F7AC: jr          $ra
    // 0x8018F7B0: nop

    return;
    // 0x8018F7B0: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331F4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801331F8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801331FC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133200: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80133204: addiu       $t7, $t7, -0x75EC
    ctx->r15 = ADD32(ctx->r15, -0X75EC);
    // 0x80133208: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013320C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133210: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80133214: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133218: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013321C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133220: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133224: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133228: addiu       $t1, $t1, -0x75DC
    ctx->r9 = ADD32(ctx->r9, -0X75DC);
    // 0x8013322C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133230: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133234: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80133238: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8013323C: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x80133240: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133244: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133248: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8013324C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133250: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133254: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133258: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8013325C: lw          $t6, -0x694C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X694C);
    // 0x80133260: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133264: addiu       $t7, $t7, 0x32A8
    ctx->r15 = ADD32(ctx->r15, 0X32A8);
    // 0x80133268: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8013326C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133270: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x80133274: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133278: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013327C: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x80133280: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133284: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80133288: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8013328C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80133290: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133294: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80133298: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8013329C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801332A0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801332A4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801332A8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801332AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801332B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801332B4: jal         0x800CD050
    // 0x801332B8: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x801332B8: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x801332BC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x801332C0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801332C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801332C8: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x801332CC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x801332D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801332D4: swc1        $f4, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f4.u32l;
    // 0x801332D8: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801332DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801332E0: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801332E4: swc1        $f6, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f6.u32l;
    // 0x801332E8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801332EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801332F0: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x801332F4: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x801332F8: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x801332FC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133300: lhu         $t5, 0x24($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X24);
    // 0x80133304: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80133308: sh          $t6, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r14;
    // 0x8013330C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80133310: sw          $v0, -0x7104($at)
    MEM_W(-0X7104, ctx->r1) = ctx->r2;
    // 0x80133314: lw          $t8, -0x6960($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6960);
    // 0x80133318: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8013331C: addu        $t7, $sp, $a2
    ctx->r15 = ADD32(ctx->r29, ctx->r6);
    // 0x80133320: lw          $t7, 0x58($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X58);
    // 0x80133324: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80133328: jal         0x800CCFDC
    // 0x8013332C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x8013332C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133330: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80133334: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80133338: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013333C: addu        $t9, $sp, $a2
    ctx->r25 = ADD32(ctx->r29, ctx->r6);
    // 0x80133340: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x80133344: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133348: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x8013334C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80133350: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133354: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80133358: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013335C: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133360: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80133364: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133368: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x8013336C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80133370: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80133374: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133378: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8013337C: jal         0x8013319C
    // 0x80133380: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    mnPlayers1PGameSetGateLUT(rdram, ctx);
        goto after_2;
    // 0x80133380: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x80133384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013338C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133390: jal         0x80009968
    // 0x80133394: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80133394: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133398: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013339C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801333A0: sw          $v0, -0x710C($at)
    MEM_W(-0X710C, ctx->r1) = ctx->r2;
    // 0x801333A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801333A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801333AC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801333B0: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x801333B4: jal         0x80009DF4
    // 0x801333B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801333B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801333BC: jal         0x801358C4
    // 0x801333C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    mnPlayers1PGameUpdateNameAndEmblem(rdram, ctx);
        goto after_5;
    // 0x801333C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_5:
    // 0x801333C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801333C8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801333CC: jr          $ra
    // 0x801333D0: nop

    return;
    // 0x801333D0: nop

;}
RECOMP_FUNC void sc1PIntroUpdateAnnounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345CC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x801345D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801345D4: addiu       $t7, $t7, 0x5A68
    ctx->r15 = ADD32(ctx->r15, 0X5A68);
    // 0x801345D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801345DC: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x801345E0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x801345E4: addiu       $t6, $sp, 0x88
    ctx->r14 = ADD32(ctx->r29, 0X88);
L_801345E8:
    // 0x801345E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801345EC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801345F0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801345F4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801345F8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801345FC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80134600: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80134604: bne         $t7, $t0, L_801345E8
    if (ctx->r15 != ctx->r8) {
        // 0x80134608: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801345E8;
    }
    // 0x80134608: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013460C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80134610: addiu       $t2, $t2, 0x5A98
    ctx->r10 = ADD32(ctx->r10, 0X5A98);
    // 0x80134614: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80134618: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
L_8013461C:
    // 0x8013461C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134620: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80134624: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80134628: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x8013462C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80134630: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80134634: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80134638: bne         $t2, $t5, L_8013461C
    if (ctx->r10 != ctx->r13) {
        // 0x8013463C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_8013461C;
    }
    // 0x8013463C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80134640: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134644: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80134648: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013464C: addiu       $t0, $t0, 0x5AD0
    ctx->r8 = ADD32(ctx->r8, 0X5AD0);
    // 0x80134650: addiu       $t9, $t0, 0x30
    ctx->r25 = ADD32(ctx->r8, 0X30);
    // 0x80134654: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x80134658: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8013465C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
L_80134660:
    // 0x80134660: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80134664: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80134668: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8013466C: sw          $t6, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r14;
    // 0x80134670: lw          $t7, -0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, -0X8);
    // 0x80134674: sw          $t7, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r15;
    // 0x80134678: lw          $t6, -0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, -0X4);
    // 0x8013467C: bne         $t0, $t9, L_80134660
    if (ctx->r8 != ctx->r25) {
        // 0x80134680: sw          $t6, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r14;
            goto L_80134660;
    }
    // 0x80134680: sw          $t6, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r14;
    // 0x80134684: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134688: lw          $t5, 0x5CC8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5CC8);
    // 0x8013468C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134690: lw          $a0, 0x5C28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5C28);
    // 0x80134694: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80134698: addu        $t1, $v0, $t2
    ctx->r9 = ADD32(ctx->r2, ctx->r10);
    // 0x8013469C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801346A0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801346A4: jal         0x80131F6C
    // 0x801346A8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    sc1PIntroCheckNotBonusStage(rdram, ctx);
        goto after_0;
    // 0x801346A8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_0:
    // 0x801346AC: beq         $v0, $zero, L_80134798
    if (ctx->r2 == 0) {
        // 0x801346B0: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80134798;
    }
    // 0x801346B0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801346B4: lw          $t9, 0x5C28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5C28);
    // 0x801346B8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801346BC: beq         $t9, $at, L_80134798
    if (ctx->r25 == ctx->r1) {
        // 0x801346C0: nop
    
            goto L_80134798;
    }
    // 0x801346C0: nop

    // 0x801346C4: jal         0x8000092C
    // 0x801346C8: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_1;
    // 0x801346C8: nop

    after_1:
    // 0x801346CC: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x801346D0: bne         $at, $zero, L_80134708
    if (ctx->r1 != 0) {
        // 0x801346D4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80134708;
    }
    // 0x801346D4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801346D8: lw          $t0, 0x5CB8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5CB8);
    // 0x801346DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801346E0: bne         $t0, $zero, L_80134708
    if (ctx->r8 != 0) {
        // 0x801346E4: nop
    
            goto L_80134708;
    }
    // 0x801346E4: nop

    // 0x801346E8: lw          $t8, 0x5CC8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5CC8);
    // 0x801346EC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x801346F0: addu        $a0, $sp, $t7
    ctx->r4 = ADD32(ctx->r29, ctx->r15);
    // 0x801346F4: jal         0x800269C0
    // 0x801346F8: lhu         $a0, 0x8A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X8A);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801346F8: lhu         $a0, 0x8A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X8A);
    after_2:
    // 0x801346FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80134700: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134704: sw          $t6, 0x5CB8($at)
    MEM_W(0X5CB8, ctx->r1) = ctx->r14;
L_80134708:
    // 0x80134708: jal         0x8000092C
    // 0x8013470C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_3;
    // 0x8013470C: nop

    after_3:
    // 0x80134710: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80134714: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80134718: sltu        $at, $t5, $v0
    ctx->r1 = ctx->r13 < ctx->r2 ? 1 : 0;
    // 0x8013471C: beq         $at, $zero, L_80134744
    if (ctx->r1 == 0) {
        // 0x80134720: nop
    
            goto L_80134744;
    }
    // 0x80134720: nop

    // 0x80134724: lw          $t2, 0x5CBC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5CBC);
    // 0x80134728: bne         $t2, $zero, L_80134744
    if (ctx->r10 != 0) {
        // 0x8013472C: nop
    
            goto L_80134744;
    }
    // 0x8013472C: nop

    // 0x80134730: jal         0x800269C0
    // 0x80134734: addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80134734: addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    after_4:
    // 0x80134738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013473C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134740: sw          $t1, 0x5CBC($at)
    MEM_W(0X5CBC, ctx->r1) = ctx->r9;
L_80134744:
    // 0x80134744: jal         0x8000092C
    // 0x80134748: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_5;
    // 0x80134748: nop

    after_5:
    // 0x8013474C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80134750: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134754: addiu       $t4, $t3, 0x3C
    ctx->r12 = ADD32(ctx->r11, 0X3C);
    // 0x80134758: sltu        $at, $t4, $v0
    ctx->r1 = ctx->r12 < ctx->r2 ? 1 : 0;
    // 0x8013475C: beql        $at, $zero, L_80134804
    if (ctx->r1 == 0) {
        // 0x80134760: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134804;
    }
    goto skip_0;
    // 0x80134760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80134764: lw          $t9, 0x5CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5CC0);
    // 0x80134768: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013476C: bnel        $t9, $zero, L_80134804
    if (ctx->r25 != 0) {
        // 0x80134770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134804;
    }
    goto skip_1;
    // 0x80134770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80134774: lw          $t0, 0x5C28($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5C28);
    // 0x80134778: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8013477C: addu        $a0, $sp, $t8
    ctx->r4 = ADD32(ctx->r29, ctx->r24);
    // 0x80134780: jal         0x800269C0
    // 0x80134784: lhu         $a0, 0x52($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X52);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80134784: lhu         $a0, 0x52($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X52);
    after_6:
    // 0x80134788: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013478C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134790: b           L_80134800
    // 0x80134794: sw          $t7, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = ctx->r15;
        goto L_80134800;
    // 0x80134794: sw          $t7, 0x5CC0($at)
    MEM_W(0X5CC0, ctx->r1) = ctx->r15;
L_80134798:
    // 0x80134798: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013479C: lw          $t6, 0x5CF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CF8);
    // 0x801347A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801347A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801347A8: bnel        $t6, $at, L_80134804
    if (ctx->r14 != ctx->r1) {
        // 0x801347AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134804;
    }
    goto skip_2;
    // 0x801347AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801347B0: lw          $v0, 0x5C28($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C28);
    // 0x801347B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801347B8: beq         $v0, $at, L_801347D8
    if (ctx->r2 == ctx->r1) {
        // 0x801347BC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801347D8;
    }
    // 0x801347BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801347C0: beq         $v0, $at, L_801347E8
    if (ctx->r2 == ctx->r1) {
        // 0x801347C4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_801347E8;
    }
    // 0x801347C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801347C8: beq         $v0, $at, L_801347F8
    if (ctx->r2 == ctx->r1) {
        // 0x801347CC: nop
    
            goto L_801347F8;
    }
    // 0x801347CC: nop

    // 0x801347D0: b           L_80134804
    // 0x801347D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134804;
    // 0x801347D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801347D8:
    // 0x801347D8: jal         0x800269C0
    // 0x801347DC: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x801347DC: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
    after_7:
    // 0x801347E0: b           L_80134804
    // 0x801347E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134804;
    // 0x801347E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801347E8:
    // 0x801347E8: jal         0x800269C0
    // 0x801347EC: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801347EC: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    after_8:
    // 0x801347F0: b           L_80134804
    // 0x801347F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134804;
    // 0x801347F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801347F8:
    // 0x801347F8: jal         0x800269C0
    // 0x801347FC: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x801347FC: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_9:
L_80134800:
    // 0x80134800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134804:
    // 0x80134804: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x80134808: jr          $ra
    // 0x8013480C: nop

    return;
    // 0x8013480C: nop

;}
RECOMP_FUNC void lbParticleStructFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0C74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D0C78: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D0C7C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D0C80: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D0C84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D0C88: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D0C8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D0C90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D0C94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D0C98: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800D0C9C: lw          $s3, 0x7C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X7C);
    // 0x800D0CA0: addiu       $s6, $s6, 0x6358
    ctx->r22 = ADD32(ctx->r22, 0X6358);
    // 0x800D0CA4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D0CA8: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
    // 0x800D0CAC: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_800D0CB0:
    // 0x800D0CB0: and         $t6, $s3, $s4
    ctx->r14 = ctx->r19 & ctx->r20;
    // 0x800D0CB4: bne         $t6, $zero, L_800D0D00
    if (ctx->r14 != 0) {
        // 0x800D0CB8: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_800D0D00;
    }
    // 0x800D0CB8: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800D0CBC: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800D0CC0: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800D0CC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D0CC8: beq         $s0, $zero, L_800D0D00
    if (ctx->r16 == 0) {
        // 0x800D0CCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0D00;
    }
    // 0x800D0CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0CD0:
    // 0x800D0CD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D0CD4: jal         0x800CEF4C
    // 0x800D0CD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    lbParticleUpdateStruct(rdram, ctx);
        goto after_0;
    // 0x800D0CD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x800D0CDC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800D0CE0: bnel        $v0, $t9, L_800D0CF8
    if (ctx->r2 != ctx->r25) {
        // 0x800D0CE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D0CF8;
    }
    goto skip_0;
    // 0x800D0CE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_0:
    // 0x800D0CE8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800D0CEC: b           L_800D0CF8
    // 0x800D0CF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800D0CF8;
    // 0x800D0CF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0CF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D0CF8:
    // 0x800D0CF8: bnel        $s0, $zero, L_800D0CD0
    if (ctx->r16 != 0) {
        // 0x800D0CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0CD0;
    }
    goto skip_1;
    // 0x800D0CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800D0D00:
    // 0x800D0D00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D0D04: bne         $s2, $s5, L_800D0CB0
    if (ctx->r18 != ctx->r21) {
        // 0x800D0D08: srl         $s3, $s3, 1
        ctx->r19 = S32(U32(ctx->r19) >> 1);
            goto L_800D0CB0;
    }
    // 0x800D0D08: srl         $s3, $s3, 1
    ctx->r19 = S32(U32(ctx->r19) >> 1);
    // 0x800D0D0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D0D10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0D14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0D18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D0D1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D0D20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D0D24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0D28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D0D2C: jr          $ra
    // 0x800D0D30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D0D30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

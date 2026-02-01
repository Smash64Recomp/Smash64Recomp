#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gmCameraCheckPausePlayerOutBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CA7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CA80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CA84: jal         0x8010B810
    // 0x8010CA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gmCameraGetBoundsMask(rdram, ctx);
        goto after_0;
    // 0x8010CA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010CA8C: bne         $v0, $zero, L_8010CAD0
    if (ctx->r2 != 0) {
        // 0x8010CA90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010CAD0;
    }
    // 0x8010CA90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CA94: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010CA98: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8010CA9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010CAA0: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8010CAA4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010CAA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8010CAAC: nop

    // 0x8010CAB0: bc1t        L_8010CAD0
    if (c1cs) {
        // 0x8010CAB4: nop
    
            goto L_8010CAD0;
    }
    // 0x8010CAB4: nop

    // 0x8010CAB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010CABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010CAC0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8010CAC4: nop

    // 0x8010CAC8: bc1f        L_8010CAD8
    if (!c1cs) {
        // 0x8010CACC: nop
    
            goto L_8010CAD8;
    }
    // 0x8010CACC: nop

L_8010CAD0:
    // 0x8010CAD0: b           L_8010CAD8
    // 0x8010CAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010CAD8;
    // 0x8010CAD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010CAD8:
    // 0x8010CAD8: jr          $ra
    // 0x8010CADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010CADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lbParticleAddAttachDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2720: blez        $a0, L_800D273C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800D2724: slti        $at, $a0, 0x9
        ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
            goto L_800D273C;
    }
    // 0x800D2724: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x800D2728: beq         $at, $zero, L_800D273C
    if (ctx->r1 == 0) {
        // 0x800D272C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800D273C;
    }
    // 0x800D272C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D2730: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2734: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D2738: sw          $a1, 0x639C($at)
    MEM_W(0X639C, ctx->r1) = ctx->r5;
L_800D273C:
    // 0x800D273C: jr          $ra
    // 0x800D2740: nop

    return;
    // 0x800D2740: nop

;}
RECOMP_FUNC void ftParamGetCostumeDebug(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC11C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800EC120: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EC124: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800EC128: jr          $ra
    // 0x800EC12C: lbu         $v0, -0x47C9($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47C9);
    return;
    // 0x800EC12C: lbu         $v0, -0x47C9($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47C9);
;}
RECOMP_FUNC void ftFoxSpecialHiStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BE48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015BE4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BE50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015BE54: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015BE58: jal         0x800DEEC8
    // 0x8015BE5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015BE5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015BE60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015BE64: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015BE68: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015BE6C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015BE70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015BE74: jal         0x800E6F24
    // 0x8015BE78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BE78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015BE7C: jal         0x800D8EB8
    // 0x8015BE80: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015BE80: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015BE84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BE88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015BE8C: jr          $ra
    // 0x8015BE90: nop

    return;
    // 0x8015BE90: nop

;}
RECOMP_FUNC void ifCommonItemArrowMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80111EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111EC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80111ECC: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80111ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80111ED4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80111ED8: jal         0x80009968
    // 0x80111EDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80111EDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80111EE0: beq         $v0, $zero, L_80111F6C
    if (ctx->r2 == 0) {
        // 0x80111EE4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80111F6C;
    }
    // 0x80111EE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80111EE8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80111EEC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80111EF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80111EF4: addiu       $a1, $a1, 0x1D64
    ctx->r5 = ADD32(ctx->r5, 0X1D64);
    // 0x80111EF8: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80111EFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80111F00: jal         0x80009DF4
    // 0x80111F04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80111F04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80111F08: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80111F0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80111F10: jal         0x800CCFDC
    // 0x80111F14: lw          $a1, 0x17F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X17F0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80111F14: lw          $a1, 0x17F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X17F0);
    after_2:
    // 0x80111F18: beq         $v0, $zero, L_80111F64
    if (ctx->r2 == 0) {
        // 0x80111F1C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80111F64;
    }
    // 0x80111F1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80111F20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80111F24: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80111F28: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80111F2C: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    // 0x80111F30: lbu         $t8, 0x4AD0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4AD0);
    // 0x80111F34: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80111F38: bne         $t8, $at, L_80111F5C
    if (ctx->r24 != ctx->r1) {
        // 0x80111F3C: nop
    
            goto L_80111F5C;
    }
    // 0x80111F3C: nop

    // 0x80111F40: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x80111F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80111F48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80111F4C: lbu         $t0, 0x11($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X11);
    // 0x80111F50: bne         $t0, $at, L_80111F5C
    if (ctx->r8 != ctx->r1) {
        // 0x80111F54: nop
    
            goto L_80111F5C;
    }
    // 0x80111F54: nop

    // 0x80111F58: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
L_80111F5C:
    // 0x80111F5C: b           L_80111F70
    // 0x80111F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80111F70;
    // 0x80111F60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80111F64:
    // 0x80111F64: jal         0x80009A84
    // 0x80111F68: nop

    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80111F68: nop

    after_3:
L_80111F6C:
    // 0x80111F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80111F70:
    // 0x80111F70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111F74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80111F78: jr          $ra
    // 0x80111F7C: nop

    return;
    // 0x80111F7C: nop

;}
RECOMP_FUNC void mnSoundTestMakeVoiceSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132AF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132AFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132B00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132B04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B08: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132B0C: jal         0x80009968
    // 0x80132B10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132B10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B14: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132B18: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132B1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132B20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132B24: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132B28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132B30: jal         0x80009DF4
    // 0x80132B34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132B34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132B38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B3C: addiu       $a1, $a1, 0x2450
    ctx->r5 = ADD32(ctx->r5, 0X2450);
    // 0x80132B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132B48: jal         0x80008188
    // 0x80132B4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132B4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132B50: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80132B54: sw          $t7, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r15;
    // 0x80132B58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B60: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132B64: jal         0x80009968
    // 0x80132B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132B6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B70: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132B74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132B78: addiu       $a1, $a1, 0x29B8
    ctx->r5 = ADD32(ctx->r5, 0X29B8);
    // 0x80132B7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B80: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132B84: jal         0x80009DF4
    // 0x80132B88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132B88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132B8C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132B90: lw          $t9, 0x4478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4478);
    // 0x80132B94: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80132B98: addiu       $t0, $t0, 0xE48
    ctx->r8 = ADD32(ctx->r8, 0XE48);
    // 0x80132B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132BA0: jal         0x800CCFDC
    // 0x80132BA4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132BA4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x80132BA8: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80132BAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132BB0: lui         $at, 0x431C
    ctx->r1 = S32(0X431C << 16);
    // 0x80132BB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132BB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132BBC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132BC0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132BC4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132BC8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132BCC: lw          $t2, 0x4478($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4478);
    // 0x80132BD0: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132BD4: addiu       $t3, $t3, 0x1138
    ctx->r11 = ADD32(ctx->r11, 0X1138);
    // 0x80132BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132BDC: jal         0x800CCFDC
    // 0x80132BE0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132BE0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132BE4: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80132BE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132BEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132BF0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132BF4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132BF8: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132BFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132C00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132C08: jr          $ra
    // 0x80132C0C: nop

    return;
    // 0x80132C0C: nop

;}
RECOMP_FUNC void mpCollisionUpdateBoundsCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB808: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800FB80C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FB810: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800FB814: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800FB818: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800FB81C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800FB820: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800FB824: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800FB828: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800FB82C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800FB830: addiu       $t6, $t6, 0x1318
    ctx->r14 = ADD32(ctx->r14, 0X1318);
    // 0x800FB834: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FB838: addiu       $t3, $sp, 0x7C
    ctx->r11 = ADD32(ctx->r29, 0X7C);
    // 0x800FB83C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FB840: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800FB844: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FB848: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800FB84C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800FB850: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x800FB854: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FB858: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800FB85C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800FB860: sw          $t8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r24;
    // 0x800FB864: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800FB868: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x800FB86C: lw          $t1, 0x1368($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1368);
    // 0x800FB870: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x800FB874: lw          $a3, 0x10($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X10);
    // 0x800FB878: blezl       $v1, L_800FBA38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800FB87C: lw          $t8, 0x0($t3)
        ctx->r24 = MEM_W(ctx->r11, 0X0);
            goto L_800FBA38;
    }
    goto skip_0;
    // 0x800FB87C: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    skip_0:
    // 0x800FB880: lw          $t2, 0x1304($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1304);
L_800FB884:
    // 0x800FB884: lhu         $t9, 0x0($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X0);
    // 0x800FB888: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800FB88C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800FB890: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800FB894: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x800FB898: lw          $t8, 0x70($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X70);
    // 0x800FB89C: bnel        $t8, $zero, L_800FB8BC
    if (ctx->r24 != 0) {
        // 0x800FB8A0: addiu       $a0, $a3, 0x2
        ctx->r4 = ADD32(ctx->r7, 0X2);
            goto L_800FB8BC;
    }
    goto skip_1;
    // 0x800FB8A0: addiu       $a0, $a3, 0x2
    ctx->r4 = ADD32(ctx->r7, 0X2);
    skip_1:
    // 0x800FB8A4: lw          $a0, 0x84($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X84);
    // 0x800FB8A8: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800FB8AC: beql        $at, $zero, L_800FBA2C
    if (ctx->r1 == 0) {
        // 0x800FB8B0: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800FBA2C;
    }
    goto skip_2;
    // 0x800FB8B0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
    // 0x800FB8B4: beq         $a0, $zero, L_800FBA28
    if (ctx->r4 == 0) {
        // 0x800FB8B8: addiu       $a0, $a3, 0x2
        ctx->r4 = ADD32(ctx->r7, 0X2);
            goto L_800FBA28;
    }
    // 0x800FB8B8: addiu       $a0, $a3, 0x2
    ctx->r4 = ADD32(ctx->r7, 0X2);
L_800FB8BC:
    // 0x800FB8BC: lwc1        $f0, 0x1C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800FB8C0: lwc1        $f2, 0x20($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X20);
    // 0x800FB8C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FB8C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800FB8CC:
    // 0x800FB8CC: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800FB8D0: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x800FB8D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FB8D8: blez        $t9, L_800FBA18
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800FB8DC: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800FBA18;
    }
    // 0x800FB8DC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FB8E0: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800FB8E4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800FB8E8: addu        $t5, $a1, $v1
    ctx->r13 = ADD32(ctx->r5, ctx->r3);
    // 0x800FB8EC: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800FB8F0: lhu         $s3, 0x0($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X0);
L_800FB8F4:
    // 0x800FB8F4: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x800FB8F8: or          $t4, $s1, $zero
    ctx->r12 = ctx->r17 | 0;
    // 0x800FB8FC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800FB900: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x800FB904: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800FB908: beq         $at, $zero, L_800FBA00
    if (ctx->r1 == 0) {
        // 0x800FB90C: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_800FBA00;
    }
    // 0x800FB90C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x800FB910: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FB914: lw          $t6, 0x1374($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1374);
    // 0x800FB918: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    // 0x800FB91C: lw          $s4, 0x1370($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X1370);
    // 0x800FB920: addu        $s5, $t6, $t7
    ctx->r21 = ADD32(ctx->r14, ctx->r15);
    // 0x800FB924: lhu         $t8, 0x0($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X0);
L_800FB928:
    // 0x800FB928: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FB92C: mflo        $t9
    ctx->r25 = lo;
    // 0x800FB930: addu        $s6, $s4, $t9
    ctx->r22 = ADD32(ctx->r20, ctx->r25);
    // 0x800FB934: lh          $t8, 0x2($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X2);
    // 0x800FB938: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x800FB93C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800FB940: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800FB944: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FB948: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800FB94C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FB950: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800FB954: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800FB958: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800FB95C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800FB960: mfc1        $s7, $f6
    ctx->r23 = (int32_t)ctx->f6.u32l;
    // 0x800FB964: nop

    // 0x800FB968: mtc1        $s7, $f8
    ctx->f8.u32l = ctx->r23;
    // 0x800FB96C: mfc1        $s3, $f10
    ctx->r19 = (int32_t)ctx->f10.u32l;
    // 0x800FB970: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800FB974: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FB978: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x800FB97C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800FB980: nop

    // 0x800FB984: bc1fl       L_800FB998
    if (!c1cs) {
        // 0x800FB988: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_800FB998;
    }
    goto skip_3;
    // 0x800FB988: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_3:
    // 0x800FB98C: b           L_800FB9A8
    // 0x800FB990: swc1        $f12, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f12.u32l;
        goto L_800FB9A8;
    // 0x800FB990: swc1        $f12, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f12.u32l;
    // 0x800FB994: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_800FB998:
    // 0x800FB998: nop

    // 0x800FB99C: bc1fl       L_800FB9AC
    if (!c1cs) {
        // 0x800FB9A0: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800FB9AC;
    }
    goto skip_4;
    // 0x800FB9A0: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    skip_4:
    // 0x800FB9A4: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
L_800FB9A8:
    // 0x800FB9A8: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
L_800FB9AC:
    // 0x800FB9AC: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800FB9B0: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800FB9B4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800FB9B8: nop

    // 0x800FB9BC: bc1fl       L_800FB9D0
    if (!c1cs) {
        // 0x800FB9C0: c.lt.s      $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
            goto L_800FB9D0;
    }
    goto skip_5;
    // 0x800FB9C0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    skip_5:
    // 0x800FB9C4: b           L_800FB9E0
    // 0x800FB9C8: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
        goto L_800FB9E0;
    // 0x800FB9C8: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x800FB9CC: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
L_800FB9D0:
    // 0x800FB9D0: nop

    // 0x800FB9D4: bc1fl       L_800FB9E4
    if (!c1cs) {
        // 0x800FB9D8: lhu         $t6, 0x0($t4)
        ctx->r14 = MEM_HU(ctx->r12, 0X0);
            goto L_800FB9E4;
    }
    goto skip_6;
    // 0x800FB9D8: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    skip_6:
    // 0x800FB9DC: swc1        $f12, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f12.u32l;
L_800FB9E0:
    // 0x800FB9E0: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
L_800FB9E4:
    // 0x800FB9E4: lhu         $t7, 0x2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X2);
    // 0x800FB9E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800FB9EC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x800FB9F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FB9F4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800FB9F8: bnel        $at, $zero, L_800FB928
    if (ctx->r1 != 0) {
        // 0x800FB9FC: lhu         $t8, 0x0($s5)
        ctx->r24 = MEM_HU(ctx->r21, 0X0);
            goto L_800FB928;
    }
    goto skip_7;
    // 0x800FB9FC: lhu         $t8, 0x0($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X0);
    skip_7:
L_800FBA00:
    // 0x800FBA00: lhu         $t9, 0x2($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X2);
    // 0x800FBA04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800FBA08: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800FBA0C: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800FBA10: bnel        $at, $zero, L_800FB8F4
    if (ctx->r1 != 0) {
        // 0x800FBA14: lhu         $s3, 0x0($s1)
        ctx->r19 = MEM_HU(ctx->r17, 0X0);
            goto L_800FB8F4;
    }
    goto skip_8;
    // 0x800FBA14: lhu         $s3, 0x0($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X0);
    skip_8:
L_800FBA18:
    // 0x800FBA18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800FBA1C: bne         $v1, $a2, L_800FB8CC
    if (ctx->r3 != ctx->r6) {
        // 0x800FBA20: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800FB8CC;
    }
    // 0x800FBA20: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800FBA24: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
L_800FBA28:
    // 0x800FBA28: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
L_800FBA2C:
    // 0x800FBA2C: bne         $at, $zero, L_800FB884
    if (ctx->r1 != 0) {
        // 0x800FBA30: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_800FB884;
    }
    // 0x800FBA30: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x800FBA34: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
L_800FBA38:
    // 0x800FBA38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FBA3C: addiu       $t6, $t6, 0x1328
    ctx->r14 = ADD32(ctx->r14, 0X1328);
    // 0x800FBA40: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800FBA44: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x800FBA48: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800FBA4C: lw          $t8, 0x8($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X8);
    // 0x800FBA50: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x800FBA54: lw          $t7, 0xC($t3)
    ctx->r15 = MEM_W(ctx->r11, 0XC);
    // 0x800FBA58: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
    // 0x800FBA5C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800FBA60: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800FBA64: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800FBA68: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800FBA6C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800FBA70: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800FBA74: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800FBA78: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800FBA7C: jr          $ra
    // 0x800FBA80: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800FBA80: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeReadyCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801361CC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801361D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801361D4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801361D8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801361DC: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x801361E0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801361E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801361E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801361EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801361F0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801361F4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801361F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801361FC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136200: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80136204: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136208: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013620C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80136210: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80136214: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136218: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013621C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136220: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80136224: jal         0x8000B93C
    // 0x80136228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013622C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136230: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136234: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80136238: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013623C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136240: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80136244: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80136248: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013624C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80136250: jal         0x80007080
    // 0x80136254: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80136254: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80136258: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013625C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80136260: jr          $ra
    // 0x80136264: nop

    return;
    // 0x80136264: nop

;}
RECOMP_FUNC void itTaruThrownInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179EF0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80179EF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179EF8: lwc1        $f4, -0x327C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X327C);
    // 0x80179EFC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80179F00: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179F04: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    // 0x80179F08: lwc1        $f0, 0x7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80179F0C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80179F10: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80179F14: jr          $ra
    // 0x80179F18: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80179F18: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mvOpeningClashStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132874: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013287C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132880: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132884: addiu       $a0, $a0, 0x2928
    ctx->r4 = ADD32(ctx->r4, 0X2928);
    // 0x80132888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013288C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132890: jal         0x80007024
    // 0x80132894: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132894: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132898: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8013289C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801328A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328A4: addiu       $t9, $t9, 0x2D80
    ctx->r25 = ADD32(ctx->r25, 0X2D80);
    // 0x801328A8: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801328AC: addiu       $a0, $a0, 0x2944
    ctx->r4 = ADD32(ctx->r4, 0X2944);
    // 0x801328B0: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801328B4: jal         0x8000683C
    // 0x801328B8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801328B8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801328BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328C4: jr          $ra
    // 0x801328C8: nop

    return;
    // 0x801328C8: nop

;}
RECOMP_FUNC void wpMarioFireballProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168548: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016854C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80168550: jal         0x80167FE8
    // 0x80168554: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80168554: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168558: beq         $v0, $zero, L_8016857C
    if (ctx->r2 == 0) {
        // 0x8016855C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8016857C;
    }
    // 0x8016855C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80168560: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80168564: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80168568: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8016856C: jal         0x800FF648
    // 0x80168570: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80168570: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80168574: b           L_801685E0
    // 0x80168578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801685E0;
    // 0x80168578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016857C:
    // 0x8016857C: lw          $t8, 0x29C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X29C);
    // 0x80168580: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80168584: addiu       $t0, $t0, -0x71D0
    ctx->r8 = ADD32(ctx->r8, -0X71D0);
    // 0x80168588: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8016858C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80168590: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80168594: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80168598: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8016859C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801685A0: jal         0x80168088
    // 0x801685A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainApplyGravityClampTVel(rdram, ctx);
        goto after_2;
    // 0x801685A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x801685A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801685AC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801685B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801685B4: lw          $t2, 0x29C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X29C);
    // 0x801685B8: lw          $v1, 0x74($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X74);
    // 0x801685BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801685C0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801685C4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801685C8: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x801685CC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801685D0: lwc1        $f6, -0x71BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X71BC);
    // 0x801685D4: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801685D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801685DC: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
L_801685E0:
    // 0x801685E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801685E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801685E8: jr          $ra
    // 0x801685EC: nop

    return;
    // 0x801685EC: nop

;}
RECOMP_FUNC void sc1PStageClearUpdateResultScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134604: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134608: addiu       $a1, $a1, 0x52EC
    ctx->r5 = ADD32(ctx->r5, 0X52EC);
    // 0x8013460C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80134610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134614: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80134618: beq         $a0, $t6, L_8013468C
    if (ctx->r4 == ctx->r14) {
        // 0x8013461C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8013468C;
    }
    // 0x8013461C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134620: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134624: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x80134628: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013462C: bnel        $v0, $at, L_80134648
    if (ctx->r2 != ctx->r1) {
        // 0x80134630: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80134648;
    }
    goto skip_0;
    // 0x80134630: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_0:
    // 0x80134634: jal         0x80132C80
    // 0x80134638: nop

    sc1PStageClearMakeTargetTextSObjs(rdram, ctx);
        goto after_0;
    // 0x80134638: nop

    after_0:
    // 0x8013463C: b           L_801346A4
    // 0x80134640: nop

        goto L_801346A4;
    // 0x80134640: nop

    // 0x80134644: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_80134648:
    // 0x80134648: bne         $v0, $at, L_80134684
    if (ctx->r2 != ctx->r1) {
        // 0x8013464C: nop
    
            goto L_80134684;
    }
    // 0x8013464C: nop

    // 0x80134650: jal         0x80132F78
    // 0x80134654: nop

    func_ovl56_80132F78(rdram, ctx);
        goto after_1;
    // 0x80134654: nop

    after_1:
    // 0x80134658: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8013465C: addiu       $a3, $a3, 0x53A4
    ctx->r7 = ADD32(ctx->r7, 0X53A4);
    // 0x80134660: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80134664: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80134668: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013466C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134670: lw          $t9, 0x52CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52CC);
    // 0x80134674: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134678: mflo        $t8
    ctx->r24 = lo;
    // 0x8013467C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80134680: sw          $t0, 0x53A0($at)
    MEM_W(0X53A0, ctx->r1) = ctx->r8;
L_80134684:
    // 0x80134684: b           L_801346A4
    // 0x80134688: nop

        goto L_801346A4;
    // 0x80134688: nop

L_8013468C:
    // 0x8013468C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134690: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x80134694: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80134698: bne         $v0, $at, L_801346A4
    if (ctx->r2 != ctx->r1) {
        // 0x8013469C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801346A4;
    }
    // 0x8013469C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801346A0: sw          $v0, 0x53A0($at)
    MEM_W(0X53A0, ctx->r1) = ctx->r2;
L_801346A4:
    // 0x801346A4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801346A8: lw          $t1, 0x53A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X53A0);
    // 0x801346AC: beq         $t1, $zero, L_801348F0
    if (ctx->r9 == 0) {
        // 0x801346B0: nop
    
            goto L_801348F0;
    }
    // 0x801346B0: nop

    // 0x801346B4: jal         0x80133F28
    // 0x801346B8: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_2;
    // 0x801346B8: nop

    after_2:
    // 0x801346BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801346C0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801346C4: addiu       $a3, $a3, 0x53A4
    ctx->r7 = ADD32(ctx->r7, 0X53A4);
    // 0x801346C8: addiu       $a1, $a1, 0x52EC
    ctx->r5 = ADD32(ctx->r5, 0X52EC);
    // 0x801346CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801346D0: beq         $v0, $zero, L_80134740
    if (ctx->r2 == 0) {
        // 0x801346D4: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_80134740;
    }
    // 0x801346D4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801346D8: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x801346DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801346E0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801346E4: beq         $a0, $t2, L_80134740
    if (ctx->r4 == ctx->r10) {
        // 0x801346E8: nop
    
            goto L_80134740;
    }
    // 0x801346E8: nop

    // 0x801346EC: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x801346F0: lw          $t3, 0x53A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X53A0);
    // 0x801346F4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801346F8: bne         $v0, $t3, L_801348F0
    if (ctx->r2 != ctx->r11) {
        // 0x801346FC: nop
    
            goto L_801348F0;
    }
    // 0x801346FC: nop

    // 0x80134700: lw          $t4, 0x52D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X52D8);
    // 0x80134704: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134708: addiu       $v1, $v1, 0x5348
    ctx->r3 = ADD32(ctx->r3, 0X5348);
    // 0x8013470C: beq         $t4, $zero, L_80134730
    if (ctx->r12 == 0) {
        // 0x80134710: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134730;
    }
    // 0x80134710: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134714: addiu       $t5, $v0, 0xA
    ctx->r13 = ADD32(ctx->r2, 0XA);
    // 0x80134718: addiu       $a0, $a0, 0x5344
    ctx->r4 = ADD32(ctx->r4, 0X5344);
    // 0x8013471C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80134720: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80134724: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134728: b           L_801348F0
    // 0x8013472C: sw          $t5, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r13;
        goto L_801348F0;
    // 0x8013472C: sw          $t5, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r13;
L_80134730:
    // 0x80134730: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134734: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134738: b           L_801348F0
    // 0x8013473C: sw          $t8, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r24;
        goto L_801348F0;
    // 0x8013473C: sw          $t8, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r24;
L_80134740:
    // 0x80134740: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134744: lw          $v1, 0x53A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X53A0);
    // 0x80134748: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013474C: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x80134750: addiu       $t9, $v1, 0xA
    ctx->r25 = ADD32(ctx->r3, 0XA);
    // 0x80134754: addiu       $t2, $v1, 0x1E
    ctx->r10 = ADD32(ctx->r3, 0X1E);
    // 0x80134758: bne         $v0, $t9, L_801347A8
    if (ctx->r2 != ctx->r25) {
        // 0x8013475C: nop
    
            goto L_801347A8;
    }
    // 0x8013475C: nop

    // 0x80134760: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80134764: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134768: bnel        $a0, $t0, L_80134788
    if (ctx->r4 != ctx->r8) {
        // 0x8013476C: lw          $t1, 0x0($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X0);
            goto L_80134788;
    }
    goto skip_1;
    // 0x8013476C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80134770: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80134774: jal         0x801324FC
    // 0x80134778: nop

    sc1PStageClearMakeTimerTextSObjs(rdram, ctx);
        goto after_3;
    // 0x80134778: nop

    after_3:
    // 0x8013477C: b           L_801348F0
    // 0x80134780: nop

        goto L_801348F0;
    // 0x80134780: nop

    // 0x80134784: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_80134788:
    // 0x80134788: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x8013478C: bne         $a2, $t1, L_801348F0
    if (ctx->r6 != ctx->r9) {
        // 0x80134790: nop
    
            goto L_801348F0;
    }
    // 0x80134790: nop

    // 0x80134794: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80134798: jal         0x801324FC
    // 0x8013479C: nop

    sc1PStageClearMakeTimerTextSObjs(rdram, ctx);
        goto after_4;
    // 0x8013479C: nop

    after_4:
    // 0x801347A0: b           L_801348F0
    // 0x801347A4: nop

        goto L_801348F0;
    // 0x801347A4: nop

L_801347A8:
    // 0x801347A8: bne         $v0, $t2, L_801347F8
    if (ctx->r2 != ctx->r10) {
        // 0x801347AC: addiu       $t5, $v1, 0x32
        ctx->r13 = ADD32(ctx->r3, 0X32);
            goto L_801347F8;
    }
    // 0x801347AC: addiu       $t5, $v1, 0x32
    ctx->r13 = ADD32(ctx->r3, 0X32);
    // 0x801347B0: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801347B4: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x801347B8: bnel        $a0, $t3, L_801347D8
    if (ctx->r4 != ctx->r11) {
        // 0x801347BC: lw          $t4, 0x0($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X0);
            goto L_801347D8;
    }
    goto skip_2;
    // 0x801347BC: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x801347C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801347C4: jal         0x8013263C
    // 0x801347C8: nop

    sc1PStageClearMakeTimerDigits(rdram, ctx);
        goto after_5;
    // 0x801347C8: nop

    after_5:
    // 0x801347CC: b           L_801348F0
    // 0x801347D0: nop

        goto L_801348F0;
    // 0x801347D0: nop

    // 0x801347D4: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
L_801347D8:
    // 0x801347D8: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x801347DC: bne         $a2, $t4, L_801348F0
    if (ctx->r6 != ctx->r12) {
        // 0x801347E0: nop
    
            goto L_801348F0;
    }
    // 0x801347E0: nop

    // 0x801347E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801347E8: jal         0x8013263C
    // 0x801347EC: nop

    sc1PStageClearMakeTimerDigits(rdram, ctx);
        goto after_6;
    // 0x801347EC: nop

    after_6:
    // 0x801347F0: b           L_801348F0
    // 0x801347F4: nop

        goto L_801348F0;
    // 0x801347F4: nop

L_801347F8:
    // 0x801347F8: bne         $v0, $t5, L_80134878
    if (ctx->r2 != ctx->r13) {
        // 0x801347FC: addiu       $t2, $v1, 0x46
        ctx->r10 = ADD32(ctx->r3, 0X46);
            goto L_80134878;
    }
    // 0x801347FC: addiu       $t2, $v1, 0x46
    ctx->r10 = ADD32(ctx->r3, 0X46);
    // 0x80134800: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80134804: bne         $a0, $t6, L_8013483C
    if (ctx->r4 != ctx->r14) {
        // 0x80134808: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8013483C;
    }
    // 0x80134808: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013480C: jal         0x80009A84
    // 0x80134810: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_7;
    // 0x80134810: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_7:
    // 0x80134814: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134818: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013481C: jal         0x801327D4
    // 0x80134820: nop

    sc1PStageClearGetAppendTotalTimeScore(rdram, ctx);
        goto after_8;
    // 0x80134820: nop

    after_8:
    // 0x80134824: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134828: addiu       $v1, $v1, 0x52E8
    ctx->r3 = ADD32(ctx->r3, 0X52E8);
    // 0x8013482C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80134830: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80134834: b           L_801348F0
    // 0x80134838: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_801348F0;
    // 0x80134838: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8013483C:
    // 0x8013483C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80134840: bne         $a2, $t9, L_801348F0
    if (ctx->r6 != ctx->r25) {
        // 0x80134844: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801348F0;
    }
    // 0x80134844: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134848: jal         0x80009A84
    // 0x8013484C: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_9;
    // 0x8013484C: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_9:
    // 0x80134850: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80134854: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80134858: jal         0x801327D4
    // 0x8013485C: nop

    sc1PStageClearGetAppendTotalTimeScore(rdram, ctx);
        goto after_10;
    // 0x8013485C: nop

    after_10:
    // 0x80134860: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134864: addiu       $v1, $v1, 0x52E8
    ctx->r3 = ADD32(ctx->r3, 0X52E8);
    // 0x80134868: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8013486C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80134870: b           L_801348F0
    // 0x80134874: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_801348F0;
    // 0x80134874: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80134878:
    // 0x80134878: bne         $v0, $t2, L_801348F0
    if (ctx->r2 != ctx->r10) {
        // 0x8013487C: nop
    
            goto L_801348F0;
    }
    // 0x8013487C: nop

    // 0x80134880: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80134884: beq         $a2, $t3, L_80134894
    if (ctx->r6 == ctx->r11) {
        // 0x80134888: nop
    
            goto L_80134894;
    }
    // 0x80134888: nop

    // 0x8013488C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80134890: bne         $a0, $t4, L_801348A8
    if (ctx->r4 != ctx->r12) {
        // 0x80134894: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801348A8;
    }
L_80134894:
    // 0x80134894: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134898: jal         0x80009A84
    // 0x8013489C: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_11;
    // 0x8013489C: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_11:
    // 0x801348A0: jal         0x80133F00
    // 0x801348A4: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_12;
    // 0x801348A4: nop

    after_12:
L_801348A8:
    // 0x801348A8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801348AC: lw          $t5, 0x52D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X52D8);
    // 0x801348B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801348B4: addiu       $v1, $v1, 0x5348
    ctx->r3 = ADD32(ctx->r3, 0X5348);
    // 0x801348B8: beq         $t5, $zero, L_801348E4
    if (ctx->r13 == 0) {
        // 0x801348BC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801348E4;
    }
    // 0x801348BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801348C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801348C4: lw          $t6, 0x52CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X52CC);
    // 0x801348C8: addiu       $a0, $a0, 0x5344
    ctx->r4 = ADD32(ctx->r4, 0X5344);
    // 0x801348CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348D0: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x801348D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801348D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801348DC: b           L_801348F0
    // 0x801348E0: sw          $t7, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r15;
        goto L_801348F0;
    // 0x801348E0: sw          $t7, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r15;
L_801348E4:
    // 0x801348E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801348E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348EC: sw          $t0, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r8;
L_801348F0:
    // 0x801348F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801348F4: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
    // 0x801348F8: beq         $v0, $zero, L_801349D0
    if (ctx->r2 == 0) {
        // 0x801348FC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801349D0;
    }
    // 0x801348FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134900: lw          $a0, 0x5314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5314);
    // 0x80134904: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134908: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013490C: beq         $a0, $zero, L_801349D0
    if (ctx->r4 == 0) {
        // 0x80134910: nop
    
            goto L_801349D0;
    }
    // 0x80134910: nop

    // 0x80134914: lw          $t1, 0x52CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X52CC);
    // 0x80134918: lw          $t2, 0x5340($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5340);
    // 0x8013491C: bne         $t1, $t2, L_801349D0
    if (ctx->r9 != ctx->r10) {
        // 0x80134920: nop
    
            goto L_801349D0;
    }
    // 0x80134920: nop

    // 0x80134924: jal         0x80009A84
    // 0x80134928: nop

    gcEjectGObj(rdram, ctx);
        goto after_13;
    // 0x80134928: nop

    after_13:
    // 0x8013492C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134930: lw          $a0, 0x5318($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5318);
    // 0x80134934: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134938: sw          $zero, 0x5314($at)
    MEM_W(0X5314, ctx->r1) = 0;
    // 0x8013493C: beq         $a0, $zero, L_8013498C
    if (ctx->r4 == 0) {
        // 0x80134940: nop
    
            goto L_8013498C;
    }
    // 0x80134940: nop

    // 0x80134944: jal         0x80009A84
    // 0x80134948: nop

    gcEjectGObj(rdram, ctx);
        goto after_14;
    // 0x80134948: nop

    after_14:
    // 0x8013494C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134950: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134954: sw          $zero, 0x5318($at)
    MEM_W(0X5318, ctx->r1) = 0;
    // 0x80134958: addiu       $v0, $v0, 0x5378
    ctx->r2 = ADD32(ctx->r2, 0X5378);
    // 0x8013495C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_80134960:
    // 0x80134960: beq         $a0, $zero, L_80134978
    if (ctx->r4 == 0) {
        // 0x80134964: nop
    
            goto L_80134978;
    }
    // 0x80134964: nop

    // 0x80134968: jal         0x80009A84
    // 0x8013496C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_15;
    // 0x8013496C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_15:
    // 0x80134970: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80134974: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80134978:
    // 0x80134978: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013497C: addiu       $t3, $t3, 0x53A0
    ctx->r11 = ADD32(ctx->r11, 0X53A0);
    // 0x80134980: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80134984: bnel        $v0, $t3, L_80134960
    if (ctx->r2 != ctx->r11) {
        // 0x80134988: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_80134960;
    }
    goto skip_3;
    // 0x80134988: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_3:
L_8013498C:
    // 0x8013498C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134990: lw          $a0, 0x52F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52F8);
    // 0x80134994: beq         $a0, $zero, L_801349C0
    if (ctx->r4 == 0) {
        // 0x80134998: nop
    
            goto L_801349C0;
    }
    // 0x80134998: nop

    // 0x8013499C: jal         0x80009A84
    // 0x801349A0: nop

    gcEjectGObj(rdram, ctx);
        goto after_16;
    // 0x801349A0: nop

    after_16:
    // 0x801349A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801349A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801349AC: sw          $zero, 0x52F8($at)
    MEM_W(0X52F8, ctx->r1) = 0;
    // 0x801349B0: jal         0x80009A84
    // 0x801349B4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_17;
    // 0x801349B4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_17:
    // 0x801349B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801349BC: sw          $zero, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = 0;
L_801349C0:
    // 0x801349C0: jal         0x801338A0
    // 0x801349C4: nop

    sc1PStageClearMakeBonusTable(rdram, ctx);
        goto after_18;
    // 0x801349C4: nop

    after_18:
    // 0x801349C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801349CC: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
L_801349D0:
    // 0x801349D0: beql        $v0, $zero, L_801349E4
    if (ctx->r2 == 0) {
        // 0x801349D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801349E4;
    }
    goto skip_4;
    // 0x801349D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801349D8: jal         0x80133F50
    // 0x801349DC: nop

    sc1PStageUpdateBonusStatAll(rdram, ctx);
        goto after_19;
    // 0x801349DC: nop

    after_19:
    // 0x801349E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801349E4:
    // 0x801349E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801349E8: jr          $ra
    // 0x801349EC: nop

    return;
    // 0x801349EC: nop

;}
RECOMP_FUNC void grInishiePowerBlockUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109838: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010983C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80109840: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109844: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109848: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8010984C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80109850: addiu       $t9, $zero, 0x708
    ctx->r25 = ADD32(0, 0X708);
    // 0x80109854: beq         $t7, $zero, L_80109864
    if (ctx->r15 == 0) {
        // 0x80109858: nop
    
            goto L_80109864;
    }
    // 0x80109858: nop

    // 0x8010985C: sb          $t8, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r24;
    // 0x80109860: sh          $t9, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r25;
L_80109864:
    // 0x80109864: jr          $ra
    // 0x80109868: nop

    return;
    // 0x80109868: nop

;}
RECOMP_FUNC void mpCommonProcFighterCliffFloorCeil(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE99C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DE9A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE9A4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800DE9A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DE9AC: jal         0x800DE87C
    // 0x800DE9B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_0;
    // 0x800DE9B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800DE9B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE9B8: beq         $v0, $zero, L_800DEA10
    if (ctx->r2 == 0) {
        // 0x800DE9BC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800DEA10;
    }
    // 0x800DE9BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DE9C0: lhu         $v0, 0xD2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XD2);
    // 0x800DE9C4: andi        $t6, $v0, 0x3000
    ctx->r14 = ctx->r2 & 0X3000;
    // 0x800DE9C8: beq         $t6, $zero, L_800DE9E0
    if (ctx->r14 == 0) {
        // 0x800DE9CC: andi        $t7, $v0, 0x800
        ctx->r15 = ctx->r2 & 0X800;
            goto L_800DE9E0;
    }
    // 0x800DE9CC: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x800DE9D0: jal         0x80144C24
    // 0x800DE9D4: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DE9D4: nop

    after_1:
    // 0x800DE9D8: b           L_800DEA14
    // 0x800DE9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEA14;
    // 0x800DE9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DE9E0:
    // 0x800DE9E0: beql        $t7, $zero, L_800DE9FC
    if (ctx->r15 == 0) {
        // 0x800DE9E4: lhu         $t8, 0xCE($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XCE);
            goto L_800DE9FC;
    }
    goto skip_0;
    // 0x800DE9E4: lhu         $t8, 0xCE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XCE);
    skip_0:
    // 0x800DE9E8: jal         0x800DE8E4
    // 0x800DE9EC: nop

    mpCommonSetFighterWaitOrLanding(rdram, ctx);
        goto after_2;
    // 0x800DE9EC: nop

    after_2:
    // 0x800DE9F0: b           L_800DEA14
    // 0x800DE9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEA14;
    // 0x800DE9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE9F8: lhu         $t8, 0xCE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XCE);
L_800DE9FC:
    // 0x800DE9FC: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x800DEA00: beql        $t9, $zero, L_800DEA14
    if (ctx->r25 == 0) {
        // 0x800DEA04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DEA14;
    }
    goto skip_1;
    // 0x800DEA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800DEA08: jal         0x801441C0
    // 0x800DEA0C: nop

    ftCommonStopCeilSetStatus(rdram, ctx);
        goto after_3;
    // 0x800DEA0C: nop

    after_3:
L_800DEA10:
    // 0x800DEA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEA14:
    // 0x800DEA14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DEA18: jr          $ra
    // 0x800DEA1C: nop

    return;
    // 0x800DEA1C: nop

;}
RECOMP_FUNC void itRShellSpinAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A6A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017A6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A6A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017A6AC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A6B0: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017A6B4: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x8017A6B8: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017A6BC: addiu       $v1, $v1, 0x5F88
    ctx->r3 = ADD32(ctx->r3, 0X5F88);
    // 0x8017A6C0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8017A6C4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017A6C8: addiu       $t0, $t0, 0x6018
    ctx->r8 = ADD32(ctx->r8, 0X6018);
    // 0x8017A6CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017A6D0: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x8017A6D4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8017A6D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017A6DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017A6E0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8017A6E4: jal         0x8000BD1C
    // 0x8017A6E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017A6E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8017A6EC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017A6F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A6F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8017A6F8: lw          $t1, 0x2D4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017A6FC: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x8017A700: addiu       $t4, $t4, 0x6048
    ctx->r12 = ADD32(ctx->r12, 0X6048);
    // 0x8017A704: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017A708: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017A70C: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
    // 0x8017A710: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x8017A714: jal         0x8000BD54
    // 0x8017A718: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017A718: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8017A71C: jal         0x8000DF34
    // 0x8017A720: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8017A720: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8017A724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A728: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017A72C: jr          $ra
    // 0x8017A730: nop

    return;
    // 0x8017A730: nop

;}
RECOMP_FUNC void func_ovl8_8037B7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B7F0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B7F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037B7F8: beq         $v1, $zero, L_8037B850
    if (ctx->r3 == 0) {
        // 0x8037B7FC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8037B850;
    }
    // 0x8037B7FC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8037B800:
    // 0x8037B800: beq         $at, $zero, L_8037B810
    if (ctx->r1 == 0) {
        // 0x8037B804: andi        $t6, $v1, 0x80
        ctx->r14 = ctx->r3 & 0X80;
            goto L_8037B810;
    }
    // 0x8037B804: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x8037B808: jr          $ra
    // 0x8037B80C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8037B80C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037B810:
    // 0x8037B810: beql        $t6, $zero, L_8037B840
    if (ctx->r14 == 0) {
        // 0x8037B814: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037B840;
    }
    goto skip_0;
    // 0x8037B814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8037B818: bnel        $a1, $v0, L_8037B82C
    if (ctx->r5 != ctx->r2) {
        // 0x8037B81C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037B82C;
    }
    goto skip_1;
    // 0x8037B81C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8037B820: jr          $ra
    // 0x8037B824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037B824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037B828: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8037B82C:
    // 0x8037B82C: bnel        $a1, $v0, L_8037B840
    if (ctx->r5 != ctx->r2) {
        // 0x8037B830: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037B840;
    }
    goto skip_2;
    // 0x8037B830: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8037B834: jr          $ra
    // 0x8037B838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037B838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037B83C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8037B840:
    // 0x8037B840: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x8037B844: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x8037B848: bnel        $v1, $zero, L_8037B800
    if (ctx->r3 != 0) {
        // 0x8037B84C: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8037B800;
    }
    goto skip_3;
    // 0x8037B84C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    skip_3:
L_8037B850:
    // 0x8037B850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037B854: jr          $ra
    // 0x8037B858: nop

    return;
    // 0x8037B858: nop

;}
RECOMP_FUNC void syMatrixTraRotR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCA0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001BCA4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BCA8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001BCAC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001BCB0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001BCB4: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001BCB8: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001BCBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001BCC0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001BCC4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001BCC8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001BCCC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001BCD0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001BCD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001BCD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001BCDC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001BCE0: jal         0x8001BC44
    // 0x8001BCE4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotRF(rdram, ctx);
        goto after_0;
    // 0x8001BCE4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8001BCE8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001BCEC: jal         0x80019EA0
    // 0x8001BCF0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001BCF0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001BCF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001BCF8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001BCFC: jr          $ra
    // 0x8001BD00: nop

    return;
    // 0x8001BD00: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPauseSlotProcesses(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137638: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013763C: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x80137640: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137644: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80137648: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8013764C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80137650: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80137654: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80137658: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8013765C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80137660: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80137664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013766C: beql        $v1, $zero, L_801376A8
    if (ctx->r3 == 0) {
        // 0x80137670: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_801376A8;
    }
    goto skip_0;
    // 0x80137670: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80137674: jal         0x8000B2EC
    // 0x80137678: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_0;
    // 0x80137678: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    after_0:
    // 0x8013767C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137680: lw          $t9, -0x776C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X776C);
    // 0x80137684: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80137688: addiu       $t1, $t1, -0x7AA8
    ctx->r9 = ADD32(ctx->r9, -0X7AA8);
    // 0x8013768C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80137690: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80137694: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80137698: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8013769C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801376A0: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x801376A4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
L_801376A8:
    // 0x801376A8: beq         $v1, $zero, L_801376B8
    if (ctx->r3 == 0) {
        // 0x801376AC: nop
    
            goto L_801376B8;
    }
    // 0x801376AC: nop

    // 0x801376B0: jal         0x8000B2EC
    // 0x801376B4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_1;
    // 0x801376B4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    after_1:
L_801376B8:
    // 0x801376B8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801376BC: lw          $t2, -0x7768($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7768);
    // 0x801376C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801376C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801376C8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801376CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801376D0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801376D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801376D8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x801376DC: lw          $v0, -0x7AA4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AA4);
    // 0x801376E0: beql        $v0, $zero, L_801376F4
    if (ctx->r2 == 0) {
        // 0x801376E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801376F4;
    }
    goto skip_1;
    // 0x801376E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801376E8: jal         0x8000B2EC
    // 0x801376EC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801376EC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_2:
    // 0x801376F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801376F4:
    // 0x801376F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801376F8: jr          $ra
    // 0x801376FC: nop

    return;
    // 0x801376FC: nop

;}
RECOMP_FUNC void efManagerDamageElectricMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE4EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FE4F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FE4F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FE4FC: jal         0x800FD4B8
    // 0x800FE500: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE500: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FE504: bne         $v0, $zero, L_800FE514
    if (ctx->r2 != 0) {
        // 0x800FE508: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FE514;
    }
    // 0x800FE508: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FE50C: b           L_800FE6D0
    // 0x800FE510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE6D0;
    // 0x800FE510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE514:
    // 0x800FE514: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FE518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE51C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FE520: jal         0x80009968
    // 0x800FE524: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FE524: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FE528: bne         $v0, $zero, L_800FE540
    if (ctx->r2 != 0) {
        // 0x800FE52C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FE540;
    }
    // 0x800FE52C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FE530: jal         0x800FD4F8
    // 0x800FE534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FE534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FE538: b           L_800FE6D0
    // 0x800FE53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE6D0;
    // 0x800FE53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE540:
    // 0x800FE540: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FE544: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE548: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x800FE54C: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FE550: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FE554: jal         0x800CE9E8
    // 0x800FE558: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FE558: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FE55C: beq         $v0, $zero, L_800FE6C0
    if (ctx->r2 == 0) {
        // 0x800FE560: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FE6C0;
    }
    // 0x800FE560: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FE564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FE568: jal         0x800CE1DC
    // 0x800FE56C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FE56C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FE570: beq         $v0, $zero, L_800FE6AC
    if (ctx->r2 == 0) {
        // 0x800FE574: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FE6AC;
    }
    // 0x800FE574: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FE578: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FE57C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FE580: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FE584: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FE588: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FE58C: jal         0x800CEA14
    // 0x800FE590: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FE590: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FE594: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FE598: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FE59C: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FE5A0: bne         $t9, $zero, L_800FE5B0
    if (ctx->r25 != 0) {
        // 0x800FE5A4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FE5B0;
    }
    // 0x800FE5A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FE5A8: b           L_800FE6D0
    // 0x800FE5AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE6D0;
    // 0x800FE5AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE5B0:
    // 0x800FE5B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FE5B4: jal         0x80008188
    // 0x800FE5B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FE5B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FE5BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FE5C0: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FE5C4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FE5C8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FE5CC: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FE5D0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FE5D4: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FE5D8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FE5DC: jal         0x80018948
    // 0x800FE5E0: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FE5E0: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FE5E4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800FE5E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE5EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800FE5F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FE5F4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE5F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FE5FC: jal         0x80018948
    // 0x800FE600: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FE600: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800FE604: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE608: lwc1        $f16, 0x944($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X944);
    // 0x800FE60C: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800FE610: jal         0x80035CD0
    // 0x800FE614: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FE614: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x800FE618: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE61C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FE620: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FE624: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x800FE628: jal         0x800303F0
    // 0x800FE62C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FE62C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x800FE630: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE634: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE638: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FE63C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE640: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800FE644: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800FE648: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800FE64C: addiu       $t8, $v0, -0x5
    ctx->r24 = ADD32(ctx->r2, -0X5);
    // 0x800FE650: beq         $at, $zero, L_800FE67C
    if (ctx->r1 == 0) {
        // 0x800FE654: swc1        $f8, 0x1C($t5)
        MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
            goto L_800FE67C;
    }
    // 0x800FE654: swc1        $f8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
    // 0x800FE658: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800FE65C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE660: lwc1        $f18, 0x948($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X948);
    // 0x800FE664: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE668: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE66C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FE670: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800FE674: b           L_800FE69C
    // 0x800FE678: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_800FE69C;
    // 0x800FE678: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800FE67C:
    // 0x800FE67C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800FE680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE684: lwc1        $f16, 0x94C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X94C);
    // 0x800FE688: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FE68C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE694: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800FE698: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_800FE69C:
    // 0x800FE69C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800FE6A0: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800FE6A4: b           L_800FE6CC
    // 0x800FE6A8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_800FE6CC;
    // 0x800FE6A8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_800FE6AC:
    // 0x800FE6AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FE6B0: jal         0x800FDB3C
    // 0x800FE6B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x800FE6B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x800FE6B8: b           L_800FE6CC
    // 0x800FE6BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FE6CC;
    // 0x800FE6BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FE6C0:
    // 0x800FE6C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FE6C4: jal         0x800FDB3C
    // 0x800FE6C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FE6C8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_800FE6CC:
    // 0x800FE6CC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FE6D0:
    // 0x800FE6D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE6D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FE6D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FE6DC: jr          $ra
    // 0x800FE6E0: nop

    return;
    // 0x800FE6E0: nop

;}
RECOMP_FUNC void mnPlayersVSSetSceneData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A664: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A668: lw          $t6, -0x4284($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4284);
    // 0x8013A66C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013A670: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x8013A674: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A678: sb          $t6, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r14;
    // 0x8013A67C: lw          $t7, -0x4280($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4280);
    // 0x8013A680: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013A684: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A688: sb          $t7, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r15;
    // 0x8013A68C: lw          $v0, -0x4258($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4258);
    // 0x8013A690: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8013A694: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013A698: sb          $v0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r2;
    // 0x8013A69C: lw          $t8, -0x4254($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4254);
    // 0x8013A6A0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013A6A4: addiu       $t3, $t3, -0x10C0
    ctx->r11 = ADD32(ctx->r11, -0X10C0);
    // 0x8013A6A8: addiu       $a1, $a1, -0x4578
    ctx->r5 = ADD32(ctx->r5, -0X4578);
    // 0x8013A6AC: addiu       $a0, $a0, 0x4D08
    ctx->r4 = ADD32(ctx->r4, 0X4D08);
    // 0x8013A6B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013A6B4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8013A6B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013A6BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013A6C0: sb          $t8, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r24;
L_8013A6C4:
    // 0x8013A6C4: bnel        $v0, $zero, L_8013A6D8
    if (ctx->r2 != 0) {
        // 0x8013A6C8: lw          $a2, 0x40($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X40);
            goto L_8013A6D8;
    }
    goto skip_0;
    // 0x8013A6C8: lw          $a2, 0x40($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X40);
    skip_0:
    // 0x8013A6CC: b           L_8013A6E0
    // 0x8013A6D0: sb          $v1, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r3;
        goto L_8013A6E0;
    // 0x8013A6D0: sb          $v1, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r3;
    // 0x8013A6D4: lw          $a2, 0x40($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X40);
L_8013A6D8:
    // 0x8013A6D8: sb          $a2, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r6;
    // 0x8013A6DC: sb          $a2, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r6;
L_8013A6E0:
    // 0x8013A6E0: lw          $t4, 0x84($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X84);
    // 0x8013A6E4: lw          $t9, 0x48($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X48);
    // 0x8013A6E8: lw          $t5, 0x4C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4C);
    // 0x8013A6EC: lw          $t6, 0x50($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X50);
    // 0x8013A6F0: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x8013A6F4: sb          $t4, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r12;
    // 0x8013A6F8: sb          $t9, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r25;
    // 0x8013A6FC: sb          $t5, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r13;
    // 0x8013A700: bne         $t7, $zero, L_8013A730
    if (ctx->r15 != 0) {
        // 0x8013A704: sb          $t6, 0x27($a0)
        MEM_B(0X27, ctx->r4) = ctx->r14;
            goto L_8013A730;
    }
    // 0x8013A704: sb          $t6, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r14;
    // 0x8013A708: lbu         $t8, 0x2($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X2);
    // 0x8013A70C: bnel        $t8, $zero, L_8013A720
    if (ctx->r24 != 0) {
        // 0x8013A710: lbu         $t9, 0x24($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X24);
            goto L_8013A720;
    }
    goto skip_1;
    // 0x8013A710: lbu         $t9, 0x24($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X24);
    skip_1:
    // 0x8013A714: b           L_8013A754
    // 0x8013A718: sb          $v1, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r3;
        goto L_8013A754;
    // 0x8013A718: sb          $v1, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r3;
    // 0x8013A71C: lbu         $t9, 0x24($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X24);
L_8013A720:
    // 0x8013A720: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x8013A724: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8013A728: b           L_8013A754
    // 0x8013A72C: sb          $t5, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r13;
        goto L_8013A754;
    // 0x8013A72C: sb          $t5, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r13;
L_8013A730:
    // 0x8013A730: lbu         $t6, 0x2($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2);
    // 0x8013A734: bnel        $t6, $zero, L_8013A748
    if (ctx->r14 != 0) {
        // 0x8013A738: lbu         $t7, 0x24($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X24);
            goto L_8013A748;
    }
    goto skip_2;
    // 0x8013A738: lbu         $t7, 0x24($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X24);
    skip_2:
    // 0x8013A73C: b           L_8013A754
    // 0x8013A740: sb          $t2, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r10;
        goto L_8013A754;
    // 0x8013A740: sb          $t2, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r10;
    // 0x8013A744: lbu         $t7, 0x24($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X24);
L_8013A748:
    // 0x8013A748: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8013A74C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8013A750: sb          $t9, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r25;
L_8013A754:
    // 0x8013A754: lbu         $t4, 0x22($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X22);
    // 0x8013A758: bnel        $t4, $zero, L_8013A76C
    if (ctx->r12 != 0) {
        // 0x8013A75C: sb          $t2, 0x2A($a0)
        MEM_B(0X2A, ctx->r4) = ctx->r10;
            goto L_8013A76C;
    }
    goto skip_3;
    // 0x8013A75C: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
    skip_3:
    // 0x8013A760: b           L_8013A76C
    // 0x8013A764: sb          $v1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r3;
        goto L_8013A76C;
    // 0x8013A764: sb          $v1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r3;
    // 0x8013A768: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
L_8013A76C:
    // 0x8013A76C: lbu         $t5, 0x3($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X3);
    // 0x8013A770: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8013A774: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8013A778: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8013A77C: beql        $t6, $zero, L_8013A790
    if (ctx->r14 == 0) {
        // 0x8013A780: sb          $zero, 0x29($a0)
        MEM_B(0X29, ctx->r4) = 0;
            goto L_8013A790;
    }
    goto skip_4;
    // 0x8013A780: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    skip_4:
    // 0x8013A784: b           L_8013A790
    // 0x8013A788: sb          $t0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r8;
        goto L_8013A790;
    // 0x8013A788: sb          $t0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r8;
    // 0x8013A78C: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
L_8013A790:
    // 0x8013A790: lbu         $t7, 0x22($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X22);
    // 0x8013A794: bnel        $t1, $t7, L_8013A7AC
    if (ctx->r9 != ctx->r15) {
        // 0x8013A798: lw          $t9, 0x3C($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X3C);
            goto L_8013A7AC;
    }
    goto skip_5;
    // 0x8013A798: lw          $t9, 0x3C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X3C);
    skip_5:
    // 0x8013A79C: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x8013A7A0: b           L_8013A7B0
    // 0x8013A7A4: sb          $t8, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r24;
        goto L_8013A7B0;
    // 0x8013A7A4: sb          $t8, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r24;
    // 0x8013A7A8: lw          $t9, 0x3C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X3C);
L_8013A7AC:
    // 0x8013A7AC: sb          $t9, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r25;
L_8013A7B0:
    // 0x8013A7B0: addiu       $a0, $a0, 0x74
    ctx->r4 = ADD32(ctx->r4, 0X74);
    // 0x8013A7B4: bne         $at, $zero, L_8013A6C4
    if (ctx->r1 != 0) {
        // 0x8013A7B8: addiu       $a1, $a1, 0xBC
        ctx->r5 = ADD32(ctx->r5, 0XBC);
            goto L_8013A6C4;
    }
    // 0x8013A7B8: addiu       $a1, $a1, 0xBC
    ctx->r5 = ADD32(ctx->r5, 0XBC);
    // 0x8013A7BC: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x8013A7C0: sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // 0x8013A7C4: sb          $zero, 0x5($a3)
    MEM_B(0X5, ctx->r7) = 0;
    // 0x8013A7C8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8013A7CC: lbu         $a0, 0x4D2A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4D2A);
    // 0x8013A7D0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013A7D4: beql        $a0, $zero, L_8013A7F0
    if (ctx->r4 == 0) {
        // 0x8013A7D8: lbu         $t4, 0x4($a3)
        ctx->r12 = MEM_BU(ctx->r7, 0X4);
            goto L_8013A7F0;
    }
    goto skip_6;
    // 0x8013A7D8: lbu         $t4, 0x4($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X4);
    skip_6:
    // 0x8013A7DC: beq         $a0, $t1, L_8013A7FC
    if (ctx->r4 == ctx->r9) {
        // 0x8013A7E0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8013A7FC;
    }
    // 0x8013A7E0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8013A7E4: b           L_8013A800
    // 0x8013A7E8: nop

        goto L_8013A800;
    // 0x8013A7E8: nop

    // 0x8013A7EC: lbu         $t4, 0x4($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X4);
L_8013A7F0:
    // 0x8013A7F0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013A7F4: b           L_8013A800
    // 0x8013A7F8: sb          $t5, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r13;
        goto L_8013A800;
    // 0x8013A7F8: sb          $t5, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r13;
L_8013A7FC:
    // 0x8013A7FC: sb          $t6, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r14;
L_8013A800:
    // 0x8013A800: lbu         $v1, 0x4D9E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4D9E);
    // 0x8013A804: beql        $v1, $zero, L_8013A820
    if (ctx->r3 == 0) {
        // 0x8013A808: lbu         $t7, 0x4($a3)
        ctx->r15 = MEM_BU(ctx->r7, 0X4);
            goto L_8013A820;
    }
    goto skip_7;
    // 0x8013A808: lbu         $t7, 0x4($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4);
    skip_7:
    // 0x8013A80C: beql        $v1, $t1, L_8013A830
    if (ctx->r3 == ctx->r9) {
        // 0x8013A810: lbu         $t9, 0x5($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0X5);
            goto L_8013A830;
    }
    goto skip_8;
    // 0x8013A810: lbu         $t9, 0x5($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X5);
    skip_8:
    // 0x8013A814: b           L_8013A838
    // 0x8013A818: nop

        goto L_8013A838;
    // 0x8013A818: nop

    // 0x8013A81C: lbu         $t7, 0x4($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X4);
L_8013A820:
    // 0x8013A820: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013A824: b           L_8013A838
    // 0x8013A828: sb          $t8, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r24;
        goto L_8013A838;
    // 0x8013A828: sb          $t8, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r24;
    // 0x8013A82C: lbu         $t9, 0x5($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X5);
L_8013A830:
    // 0x8013A830: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8013A834: sb          $t4, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r12;
L_8013A838:
    // 0x8013A838: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013A83C: lbu         $v1, 0x4E12($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4E12);
    // 0x8013A840: beql        $v1, $zero, L_8013A85C
    if (ctx->r3 == 0) {
        // 0x8013A844: lbu         $t5, 0x4($a3)
        ctx->r13 = MEM_BU(ctx->r7, 0X4);
            goto L_8013A85C;
    }
    goto skip_9;
    // 0x8013A844: lbu         $t5, 0x4($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X4);
    skip_9:
    // 0x8013A848: beql        $v1, $t1, L_8013A86C
    if (ctx->r3 == ctx->r9) {
        // 0x8013A84C: lbu         $t7, 0x5($a3)
        ctx->r15 = MEM_BU(ctx->r7, 0X5);
            goto L_8013A86C;
    }
    goto skip_10;
    // 0x8013A84C: lbu         $t7, 0x5($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X5);
    skip_10:
    // 0x8013A850: b           L_8013A874
    // 0x8013A854: nop

        goto L_8013A874;
    // 0x8013A854: nop

    // 0x8013A858: lbu         $t5, 0x4($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X4);
L_8013A85C:
    // 0x8013A85C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8013A860: b           L_8013A874
    // 0x8013A864: sb          $t6, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r14;
        goto L_8013A874;
    // 0x8013A864: sb          $t6, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r14;
    // 0x8013A868: lbu         $t7, 0x5($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X5);
L_8013A86C:
    // 0x8013A86C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8013A870: sb          $t8, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r24;
L_8013A874:
    // 0x8013A874: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013A878: lbu         $v1, 0x4E86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4E86);
    // 0x8013A87C: beql        $v1, $zero, L_8013A898
    if (ctx->r3 == 0) {
        // 0x8013A880: lbu         $t9, 0x4($a3)
        ctx->r25 = MEM_BU(ctx->r7, 0X4);
            goto L_8013A898;
    }
    goto skip_11;
    // 0x8013A880: lbu         $t9, 0x4($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4);
    skip_11:
    // 0x8013A884: beql        $v1, $t1, L_8013A8A8
    if (ctx->r3 == ctx->r9) {
        // 0x8013A888: lbu         $t5, 0x5($a3)
        ctx->r13 = MEM_BU(ctx->r7, 0X5);
            goto L_8013A8A8;
    }
    goto skip_12;
    // 0x8013A888: lbu         $t5, 0x5($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X5);
    skip_12:
    // 0x8013A88C: jr          $ra
    // 0x8013A890: nop

    return;
    // 0x8013A890: nop

    // 0x8013A894: lbu         $t9, 0x4($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4);
L_8013A898:
    // 0x8013A898: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8013A89C: jr          $ra
    // 0x8013A8A0: sb          $t4, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r12;
    return;
    // 0x8013A8A0: sb          $t4, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r12;
    // 0x8013A8A4: lbu         $t5, 0x5($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X5);
L_8013A8A8:
    // 0x8013A8A8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8013A8AC: sb          $t6, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r14;
    // 0x8013A8B0: jr          $ra
    // 0x8013A8B4: nop

    return;
    // 0x8013A8B4: nop

;}
RECOMP_FUNC void func_ovl3_80138AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138AA8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80138AAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80138AB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80138AB4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80138AB8: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80138ABC: lwc1        $f4, 0x230($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X230);
    // 0x80138AC0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80138AC4: lwc1        $f0, 0x20($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80138AC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80138ACC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80138AD0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80138AD4: lw          $a2, 0x238($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X238);
    // 0x80138AD8: addiu       $v1, $s0, 0x1CC
    ctx->r3 = ADD32(ctx->r16, 0X1CC);
    // 0x80138ADC: bc1fl       L_80138AFC
    if (!c1cs) {
        // 0x80138AE0: lwc1        $f8, 0x64($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X64);
            goto L_80138AFC;
    }
    goto skip_0;
    // 0x80138AE0: lwc1        $f8, 0x64($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X64);
    skip_0:
    // 0x80138AE4: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80138AE8: lwc1        $f6, 0x64($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80138AEC: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80138AF0: b           L_80138B00
    // 0x80138AF4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80138B00;
    // 0x80138AF4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80138AF8: lwc1        $f8, 0x64($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X64);
L_80138AFC:
    // 0x80138AFC: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
L_80138B00:
    // 0x80138B00: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80138B04: nop

    // 0x80138B08: bc1fl       L_80138ED0
    if (!c1cs) {
        // 0x80138B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80138ED0;
    }
    goto skip_1;
    // 0x80138B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80138B10: lbu         $t7, 0x35($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X35);
    // 0x80138B14: bnel        $t7, $zero, L_80138BDC
    if (ctx->r15 != 0) {
        // 0x80138B18: sw          $v1, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r3;
            goto L_80138BDC;
    }
    goto skip_2;
    // 0x80138B18: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    skip_2:
    // 0x80138B1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80138B20: jal         0x80018948
    // 0x80138B24: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80138B24: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80138B28: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x80138B2C: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80138B30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138B34: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80138B38: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80138B3C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80138B40: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80138B44: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80138B48: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80138B4C: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80138B50: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80138B54: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80138B58: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80138B5C: nop

    // 0x80138B60: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80138B64: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80138B68: nop

    // 0x80138B6C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80138B70: beql        $t2, $zero, L_80138BC0
    if (ctx->r10 == 0) {
        // 0x80138B74: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_80138BC0;
    }
    goto skip_3;
    // 0x80138B74: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80138B78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80138B7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138B80: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80138B84: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80138B88: nop

    // 0x80138B8C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80138B90: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80138B94: nop

    // 0x80138B98: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80138B9C: bne         $t2, $zero, L_80138BB4
    if (ctx->r10 != 0) {
        // 0x80138BA0: nop
    
            goto L_80138BB4;
    }
    // 0x80138BA0: nop

    // 0x80138BA4: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80138BA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80138BAC: b           L_80138BCC
    // 0x80138BB0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80138BCC;
    // 0x80138BB0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80138BB4:
    // 0x80138BB4: b           L_80138BCC
    // 0x80138BB8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80138BCC;
    // 0x80138BB8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80138BBC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_80138BC0:
    // 0x80138BC0: nop

    // 0x80138BC4: bltz        $t2, L_80138BB4
    if (SIGNED(ctx->r10) < 0) {
        // 0x80138BC8: nop
    
            goto L_80138BB4;
    }
    // 0x80138BC8: nop

L_80138BCC:
    // 0x80138BCC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80138BD0: sb          $t2, 0x35($v1)
    MEM_B(0X35, ctx->r3) = ctx->r10;
    // 0x80138BD4: nop

    // 0x80138BD8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
L_80138BDC:
    // 0x80138BDC: jal         0x80018948
    // 0x80138BE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80138BE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_1:
    // 0x80138BE4: lbu         $t3, 0x13($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X13);
    // 0x80138BE8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80138BEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138BF0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80138BF4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80138BF8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80138BFC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80138C00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80138C04: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80138C08: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80138C0C: nop

    // 0x80138C10: bc1fl       L_80138C44
    if (!c1cs) {
        // 0x80138C14: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80138C44;
    }
    goto skip_4;
    // 0x80138C14: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_4:
    // 0x80138C18: beql        $a2, $zero, L_80138C44
    if (ctx->r6 == 0) {
        // 0x80138C1C: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80138C44;
    }
    goto skip_5;
    // 0x80138C1C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x80138C20: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80138C24: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80138C28: beq         $v0, $at, L_80138C38
    if (ctx->r2 == ctx->r1) {
        // 0x80138C2C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80138C38;
    }
    // 0x80138C2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138C30: bnel        $v0, $at, L_80138C44
    if (ctx->r2 != ctx->r1) {
        // 0x80138C34: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80138C44;
    }
    goto skip_6;
    // 0x80138C34: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_6:
L_80138C38:
    // 0x80138C38: b           L_80138ED0
    // 0x80138C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138C40: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80138C44:
    // 0x80138C44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80138C48: bne         $v0, $at, L_80138C58
    if (ctx->r2 != ctx->r1) {
        // 0x80138C4C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80138C58;
    }
    // 0x80138C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80138C50: b           L_80138C58
    // 0x80138C54: lw          $a0, 0xADC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XADC);
        goto L_80138C58;
    // 0x80138C54: lw          $a0, 0xADC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XADC);
L_80138C58:
    // 0x80138C58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138C5C: bnel        $a0, $at, L_80138CB8
    if (ctx->r4 != ctx->r1) {
        // 0x80138C60: sltiu       $at, $a0, 0xE
        ctx->r1 = ctx->r4 < 0XE ? 1 : 0;
            goto L_80138CB8;
    }
    goto skip_7;
    // 0x80138C60: sltiu       $at, $a0, 0xE
    ctx->r1 = ctx->r4 < 0XE ? 1 : 0;
    skip_7:
    // 0x80138C64: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80138C68: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80138C6C: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C70: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80138CAC;
    }
    // 0x80138C70: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80138C74: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C78: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80138CAC;
    }
    // 0x80138C78: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80138C7C: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C80: addiu       $at, $zero, 0xE2
        ctx->r1 = ADD32(0, 0XE2);
            goto L_80138CAC;
    }
    // 0x80138C80: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x80138C84: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C88: addiu       $at, $zero, 0xED
        ctx->r1 = ADD32(0, 0XED);
            goto L_80138CAC;
    }
    // 0x80138C88: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80138C8C: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C90: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80138CAC;
    }
    // 0x80138C90: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80138C94: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138C98: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_80138CAC;
    }
    // 0x80138C98: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x80138C9C: beq         $v0, $at, L_80138CAC
    if (ctx->r2 == ctx->r1) {
        // 0x80138CA0: addiu       $at, $zero, 0xF1
        ctx->r1 = ADD32(0, 0XF1);
            goto L_80138CAC;
    }
    // 0x80138CA0: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x80138CA4: bnel        $v0, $at, L_80138CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80138CA8: sltiu       $at, $a0, 0xE
        ctx->r1 = ctx->r4 < 0XE ? 1 : 0;
            goto L_80138CB8;
    }
    goto skip_8;
    // 0x80138CA8: sltiu       $at, $a0, 0xE
    ctx->r1 = ctx->r4 < 0XE ? 1 : 0;
    skip_8:
L_80138CAC:
    // 0x80138CAC: b           L_80138ED0
    // 0x80138CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138CB4: sltiu       $at, $a0, 0xE
    ctx->r1 = ctx->r4 < 0XE ? 1 : 0;
L_80138CB8:
    // 0x80138CB8: beq         $at, $zero, L_80138ECC
    if (ctx->r1 == 0) {
        // 0x80138CBC: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_80138ECC;
    }
    // 0x80138CBC: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80138CC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138CC4: addu        $at, $at, $t5
    gpr jr_addend_80138CCC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80138CC8: lw          $t5, -0x40EC($at)
    ctx->r13 = ADD32(ctx->r1, -0X40EC);
    // 0x80138CCC: jr          $t5
    // 0x80138CD0: nop

    switch (jr_addend_80138CCC >> 2) {
        case 0: goto L_80138D24; break;
        case 1: goto L_80138D24; break;
        case 2: goto L_80138ECC; break;
        case 3: goto L_80138D24; break;
        case 4: goto L_80138D24; break;
        case 5: goto L_80138CD4; break;
        case 6: goto L_80138ECC; break;
        case 7: goto L_80138ECC; break;
        case 8: goto L_80138ECC; break;
        case 9: goto L_80138D24; break;
        case 10: goto L_80138ECC; break;
        case 11: goto L_80138ECC; break;
        case 12: goto L_80138ECC; break;
        case 13: goto L_80138D24; break;
        default: switch_error(__func__, 0x80138CCC, 0x8018BF14);
    }
    // 0x80138CD0: nop

L_80138CD4:
    // 0x80138CD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138CD8: lwc1        $f6, -0x40B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X40B4);
    // 0x80138CDC: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80138CE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80138CE4: nop

    // 0x80138CE8: bc1fl       L_80138D28
    if (!c1cs) {
        // 0x80138CEC: lbu         $t6, 0x35($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X35);
            goto L_80138D28;
    }
    goto skip_9;
    // 0x80138CEC: lbu         $t6, 0x35($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X35);
    skip_9:
    // 0x80138CF0: jal         0x80018948
    // 0x80138CF4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80138CF4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_2:
    // 0x80138CF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138CFC: lwc1        $f8, -0x40B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X40B0);
    // 0x80138D00: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80138D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138D08: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80138D0C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80138D10: bc1fl       L_80138D28
    if (!c1cs) {
        // 0x80138D14: lbu         $t6, 0x35($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X35);
            goto L_80138D28;
    }
    goto skip_10;
    // 0x80138D14: lbu         $t6, 0x35($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X35);
    skip_10:
    // 0x80138D18: jal         0x80132564
    // 0x80138D1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_3;
    // 0x80138D1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_3:
    // 0x80138D20: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_80138D24:
    // 0x80138D24: lbu         $t6, 0x35($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X35);
L_80138D28:
    // 0x80138D28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80138D2C: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80138D30: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80138D34: bne         $at, $zero, L_80138D4C
    if (ctx->r1 != 0) {
        // 0x80138D38: sb          $t7, 0x35($v1)
        MEM_B(0X35, ctx->r3) = ctx->r15;
            goto L_80138D4C;
    }
    // 0x80138D38: sb          $t7, 0x35($v1)
    MEM_B(0X35, ctx->r3) = ctx->r15;
    // 0x80138D3C: jal         0x80134E98
    // 0x80138D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_4;
    // 0x80138D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80138D44: b           L_80138ED0
    // 0x80138D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80138ED0;
    // 0x80138D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80138D4C:
    // 0x80138D4C: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138D50: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80138D54: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138D58: lw          $t1, 0x1C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1C);
    // 0x80138D5C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138D60: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80138D64: lw          $t0, 0x20($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X20);
    // 0x80138D68: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80138D6C: lw          $t1, 0x24($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X24);
    // 0x80138D70: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80138D74: lwc1        $f10, 0x60($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80138D78: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80138D7C: lwc1        $f16, 0x64($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80138D80: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80138D84: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138D88: lwc1        $f18, 0x60($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80138D8C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80138D90: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80138D94: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80138D98: nop

    // 0x80138D9C: bc1fl       L_80138E28
    if (!c1cs) {
        // 0x80138DA0: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80138E28;
    }
    goto skip_11;
    // 0x80138DA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_11:
    // 0x80138DA4: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80138DA8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138DAC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138DB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80138DB4: jal         0x800F6B58
    // 0x80138DB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_5;
    // 0x80138DB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80138DBC: beq         $v0, $zero, L_80138DCC
    if (ctx->r2 == 0) {
        // 0x80138DC0: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80138DCC;
    }
    // 0x80138DC0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80138DC4: b           L_80138ED0
    // 0x80138DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138DCC:
    // 0x80138DCC: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138DD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80138DD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80138DD8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138DDC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138DE0: jal         0x800F4BD8
    // 0x80138DE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_6;
    // 0x80138DE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_6:
    // 0x80138DE8: beq         $v0, $zero, L_80138DF8
    if (ctx->r2 == 0) {
        // 0x80138DEC: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80138DF8;
    }
    // 0x80138DEC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80138DF0: b           L_80138ED0
    // 0x80138DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138DF8:
    // 0x80138DF8: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138DFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80138E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80138E04: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138E08: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138E0C: jal         0x800F5E90
    // 0x80138E10: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_7;
    // 0x80138E10: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_7:
    // 0x80138E14: beql        $v0, $zero, L_80138E9C
    if (ctx->r2 == 0) {
        // 0x80138E18: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_80138E9C;
    }
    goto skip_12;
    // 0x80138E18: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    skip_12:
    // 0x80138E1C: b           L_80138ED0
    // 0x80138E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138E24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80138E28:
    // 0x80138E28: jal         0x800F7F00
    // 0x80138E2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_8;
    // 0x80138E2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
    // 0x80138E30: beq         $v0, $zero, L_80138E40
    if (ctx->r2 == 0) {
        // 0x80138E34: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80138E40;
    }
    // 0x80138E34: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80138E38: b           L_80138ED0
    // 0x80138E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138E40:
    // 0x80138E40: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138E44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80138E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80138E4C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138E50: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138E54: jal         0x800F4BD8
    // 0x80138E58: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_9;
    // 0x80138E58: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_9:
    // 0x80138E5C: beq         $v0, $zero, L_80138E6C
    if (ctx->r2 == 0) {
        // 0x80138E60: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80138E6C;
    }
    // 0x80138E60: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80138E64: b           L_80138ED0
    // 0x80138E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138E6C:
    // 0x80138E6C: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x80138E70: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80138E74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80138E78: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80138E7C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80138E80: jal         0x800F5E90
    // 0x80138E84: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_10;
    // 0x80138E84: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_10:
    // 0x80138E88: beql        $v0, $zero, L_80138E9C
    if (ctx->r2 == 0) {
        // 0x80138E8C: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_80138E9C;
    }
    goto skip_13;
    // 0x80138E8C: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    skip_13:
    // 0x80138E90: b           L_80138ED0
    // 0x80138E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80138ED0;
    // 0x80138E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138E98: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_80138E9C:
    // 0x80138E9C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80138EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138EA4: bne         $t2, $zero, L_80138EBC
    if (ctx->r10 != 0) {
        // 0x80138EA8: nop
    
            goto L_80138EBC;
    }
    // 0x80138EA8: nop

    // 0x80138EAC: jal         0x80132778
    // 0x80138EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerSetCommandWaitLong(rdram, ctx);
        goto after_11;
    // 0x80138EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80138EB4: b           L_80138ED0
    // 0x80138EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80138ED0;
    // 0x80138EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80138EBC:
    // 0x80138EBC: jal         0x80132778
    // 0x80138EC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ftComputerSetCommandWaitLong(rdram, ctx);
        goto after_12;
    // 0x80138EC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x80138EC4: b           L_80138ED0
    // 0x80138EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80138ED0;
    // 0x80138EC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80138ECC:
    // 0x80138ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138ED0:
    // 0x80138ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80138ED4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80138ED8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80138EDC: jr          $ra
    // 0x80138EE0: nop

    return;
    // 0x80138EE0: nop

;}
RECOMP_FUNC void mvOpeningRunMakeFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BE8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80131BEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131BF0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131BF4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80131BF8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80131BFC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80131C00: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80131C04: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80131C08: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80131C0C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80131C10: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80131C14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131C18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131C1C: addiu       $t7, $t7, 0x2610
    ctx->r15 = ADD32(ctx->r15, 0X2610);
    // 0x80131C20: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131C28: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80131C2C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131C30: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131C34: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131C38: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131C3C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131C40: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131C44: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131C48: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80131C4C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80131C50: addiu       $t1, $t1, 0x2630
    ctx->r9 = ADD32(ctx->r9, 0X2630);
    // 0x80131C54: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80131C58: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80131C5C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80131C60: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80131C64: addiu       $t0, $sp, 0x98
    ctx->r8 = ADD32(ctx->r29, 0X98);
    // 0x80131C68: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80131C6C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80131C70: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80131C74: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131C78: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80131C7C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80131C80: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131C84: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80131C88: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80131C8C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80131C90: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80131C94: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80131C98: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80131C9C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80131CA0: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x80131CA4: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80131CA8: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80131CAC: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80131CB0: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80131CB4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80131CB8: addiu       $s7, $s7, 0x6DD0
    ctx->r23 = ADD32(ctx->r23, 0X6DD0);
    // 0x80131CBC: addiu       $s6, $s6, 0x1B58
    ctx->r22 = ADD32(ctx->r22, 0X1B58);
    // 0x80131CC0: addiu       $s4, $s4, 0x2718
    ctx->r20 = ADD32(ctx->r20, 0X2718);
    // 0x80131CC4: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
    // 0x80131CC8: addiu       $s2, $sp, 0x98
    ctx->r18 = ADD32(ctx->r29, 0X98);
    // 0x80131CCC: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80131CD0: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x80131CD4: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80131CD8: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
L_80131CDC:
    // 0x80131CDC: or          $t6, $s7, $zero
    ctx->r14 = ctx->r23 | 0;
    // 0x80131CE0: or          $t7, $s5, $zero
    ctx->r15 = ctx->r21 | 0;
    // 0x80131CE4: addiu       $t8, $s7, 0x3C
    ctx->r24 = ADD32(ctx->r23, 0X3C);
L_80131CE8:
    // 0x80131CE8: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80131CEC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131CF0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131CF4: sw          $t5, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r13;
    // 0x80131CF8: lw          $t4, -0x8($t6)
    ctx->r12 = MEM_W(ctx->r14, -0X8);
    // 0x80131CFC: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
    // 0x80131D00: lw          $t5, -0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, -0X4);
    // 0x80131D04: bne         $t6, $t8, L_80131CE8
    if (ctx->r14 != ctx->r24) {
        // 0x80131D08: sw          $t5, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r13;
            goto L_80131CE8;
    }
    // 0x80131D08: sw          $t5, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r13;
    // 0x80131D0C: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80131D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D14: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80131D18: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80131D1C: jal         0x800EC0EC
    // 0x80131D20: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131D20: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131D24: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80131D28: sb          $v0, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r2;
    // 0x80131D2C: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
    // 0x80131D30: swc1        $f20, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f20.u32l;
    // 0x80131D34: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80131D38: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80131D3C: jal         0x800D7F3C
    // 0x80131D40: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131D40: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    after_1:
    // 0x80131D44: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80131D48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131D4C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80131D50: bne         $fp, $t0, L_80131D60
    if (ctx->r30 != ctx->r8) {
        // 0x80131D54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80131D60;
    }
    // 0x80131D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D5C: sw          $v0, 0x2738($at)
    MEM_W(0X2738, ctx->r1) = ctx->r2;
L_80131D60:
    // 0x80131D60: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131D64: jal         0x803905CC
    // 0x80131D68: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131D68: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    after_2:
    // 0x80131D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D74: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131D78: jal         0x80009968
    // 0x80131D7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80131D7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131D80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131D84: sw          $s3, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r19;
    // 0x80131D88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D8C: jal         0x800092D0
    // 0x80131D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80131D94: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80131D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D9C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131DA0: jal         0x80008CC0
    // 0x80131DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_5;
    // 0x80131DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80131DA8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131DAC: lw          $t2, 0x2AA0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2AA0);
    // 0x80131DB0: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80131DB4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80131DB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131DBC: jal         0x8000BD1C
    // 0x80131DC0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_6;
    // 0x80131DC0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80131DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DC8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80131DCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131DD0: jal         0x80008188
    // 0x80131DD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131DD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131DD8: jal         0x8000DF34
    // 0x80131DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_8;
    // 0x80131DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80131DE0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80131DE4: addiu       $t3, $sp, 0xB8
    ctx->r11 = ADD32(ctx->r29, 0XB8);
    // 0x80131DE8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80131DEC: bne         $s2, $t3, L_80131CDC
    if (ctx->r18 != ctx->r11) {
        // 0x80131DF0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80131CDC;
    }
    // 0x80131DF0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80131DF4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80131DF8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80131DFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131E00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80131E04: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80131E08: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80131E0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80131E10: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80131E14: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80131E18: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80131E1C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80131E20: jr          $ra
    // 0x80131E24: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80131E24: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void sc1PBonusStageInitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD14: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018DD18: lw          $a2, 0x50E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X50E8);
    // 0x8018DD1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DD20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DD24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018DD28: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    // 0x8018DD2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018DD30: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8018DD34:
    // 0x8018DD34: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x8018DD38: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
    // 0x8018DD3C: beq         $a0, $t6, L_8018DDC8
    if (ctx->r4 == ctx->r14) {
        // 0x8018DD40: nop
    
            goto L_8018DDC8;
    }
    // 0x8018DD40: nop

    // 0x8018DD44: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x8018DD48: lui         $a2, 0xBE20
    ctx->r6 = S32(0XBE20 << 16);
    // 0x8018DD4C: ori         $a2, $a2, 0xD97C
    ctx->r6 = ctx->r6 | 0XD97C;
    // 0x8018DD50: slti        $at, $t7, 0x1D
    ctx->r1 = SIGNED(ctx->r15) < 0X1D ? 1 : 0;
    // 0x8018DD54: bne         $at, $zero, L_8018DD98
    if (ctx->r1 != 0) {
        // 0x8018DD58: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_8018DD98;
    }
    // 0x8018DD58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DD5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DD60: lwc1        $f4, -0xE6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE6C);
    // 0x8018DD64: lui         $at, 0x41FC
    ctx->r1 = S32(0X41FC << 16);
    // 0x8018DD68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DD6C: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x8018DD70: lui         $a2, 0xBE86
    ctx->r6 = S32(0XBE86 << 16);
    // 0x8018DD74: lui         $a3, 0x460C
    ctx->r7 = S32(0X460C << 16);
    // 0x8018DD78: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x8018DD7C: ori         $a2, $a2, 0xA92
    ctx->r6 = ctx->r6 | 0XA92;
    // 0x8018DD80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DD84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018DD88: jal         0x8010CFA8
    // 0x8018DD8C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    gmCameraSetStatusPlayerFollow(rdram, ctx);
        goto after_0;
    // 0x8018DD8C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8018DD90: b           L_8018DDD4
    // 0x8018DD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018DDD4;
    // 0x8018DD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DD98:
    // 0x8018DD98: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DD9C: lwc1        $f8, -0xE68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE68);
    // 0x8018DDA0: lui         $at, 0x41FC
    ctx->r1 = S32(0X41FC << 16);
    // 0x8018DDA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DDA8: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x8018DDAC: lui         $a3, 0x460C
    ctx->r7 = S32(0X460C << 16);
    // 0x8018DDB0: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x8018DDB4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018DDB8: jal         0x8010CFA8
    // 0x8018DDBC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    gmCameraSetStatusPlayerFollow(rdram, ctx);
        goto after_1;
    // 0x8018DDBC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8018DDC0: b           L_8018DDD4
    // 0x8018DDC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018DDD4;
    // 0x8018DDC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DDC8:
    // 0x8018DDC8: bne         $v0, $a1, L_8018DD34
    if (ctx->r2 != ctx->r5) {
        // 0x8018DDCC: addiu       $v1, $v1, 0x74
        ctx->r3 = ADD32(ctx->r3, 0X74);
            goto L_8018DD34;
    }
    // 0x8018DDCC: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x8018DDD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DDD4:
    // 0x8018DDD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DDD8: jr          $ra
    // 0x8018DDDC: nop

    return;
    // 0x8018DDDC: nop

;}
RECOMP_FUNC void mvOpeningPikachuMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA80: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA88: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA8C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA90: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DA98: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DA9C: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DAA0:
    // 0x8018DAA0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAA4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DAA8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DAAC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DAB0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DAB4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DAB8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DABC: bne         $t6, $t0, L_8018DAA0
    if (ctx->r14 != ctx->r8) {
        // 0x8018DAC0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DAA0;
    }
    // 0x8018DAC0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAC4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAC8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8018DACC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DAD0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAD4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DAD8: jal         0x800EC0EC
    // 0x8018DADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAE4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAE8: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x8018DAEC: lw          $t2, -0x1DC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1DC4);
    // 0x8018DAF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DAF4: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DAF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DAFC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB00: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB04: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DB08: jal         0x800D7F3C
    // 0x8018DB0C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DB0C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DB10: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DB14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB18: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DB1C: jal         0x803905CC
    // 0x8018DB20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DB20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB28: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB2C: jal         0x8000A0D0
    // 0x8018DB30: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB30: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB34: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB38: addiu       $a1, $a1, -0x2650
    ctx->r5 = ADD32(ctx->r5, -0X2650);
    // 0x8018DB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB44: jal         0x80008188
    // 0x8018DB48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB54: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB58: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB5C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB60: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB64: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB68: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB78: jr          $ra
    // 0x8018DB7C: nop

    return;
    // 0x8018DB7C: nop

;}
RECOMP_FUNC void syAudioSetBGMPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020CD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020CD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80020CDC: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x80020CE0: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x80020CE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80020CE8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80020CEC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80020CF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80020CF4: bne         $at, $zero, L_80020D00
    if (ctx->r1 != 0) {
        // 0x80020CF8: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80020D00;
    }
    // 0x80020CF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020CFC: addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
L_80020D00:
    // 0x80020D00: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020D04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020D08: addiu       $t7, $t7, -0x26A0
    ctx->r15 = ADD32(ctx->r15, -0X26A0);
    // 0x80020D0C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80020D10: sb          $s1, -0x2698($at)
    MEM_B(-0X2698, ctx->r1) = ctx->r17;
    // 0x80020D14: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x80020D18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020D1C: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x80020D20: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_80020D24:
    // 0x80020D24: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80020D28: jal         0x80025FC0
    // 0x80020D2C: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    alCSPSetChlPriority(rdram, ctx);
        goto after_0;
    // 0x80020D2C: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x80020D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020D34: bnel        $s0, $s3, L_80020D24
    if (ctx->r16 != ctx->r19) {
        // 0x80020D38: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_80020D24;
    }
    goto skip_0;
    // 0x80020D38: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80020D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80020D40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80020D44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80020D48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80020D4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80020D50: jr          $ra
    // 0x80020D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80020D54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftPikachuSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151B50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80151B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151B58: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80151B5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151B60: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x80151B64: beql        $t7, $zero, L_80151C08
    if (ctx->r15 == 0) {
        // 0x80151B68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80151C08;
    }
    goto skip_0;
    // 0x80151B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80151B6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80151B70: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80151B74: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80151B78: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80151B7C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80151B80: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80151B84: lw          $a0, 0x914($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X914);
    // 0x80151B88: jal         0x800EDF24
    // 0x80151B8C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80151B8C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80151B90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80151B94: jal         0x80035CD0
    // 0x80151B98: lwc1        $f12, -0x3AC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3AC0);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80151B98: lwc1        $f12, -0x3AC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3AC0);
    after_1:
    // 0x80151B9C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80151BA0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80151BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80151BA8: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80151BAC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80151BB0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80151BB4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80151BB8: lwc1        $f12, -0x3ABC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3ABC);
    // 0x80151BBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80151BC0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80151BC4: jal         0x800303F0
    // 0x80151BC8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80151BC8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80151BCC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80151BD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80151BD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80151BD8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80151BDC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80151BE0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80151BE4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80151BE8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80151BEC: jal         0x801695E4
    // 0x80151BF0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    wpPikachuThunderJoltAirMakeWeapon(rdram, ctx);
        goto after_3;
    // 0x80151BF0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80151BF4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80151BF8: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80151BFC: jal         0x800E9814
    // 0x80151C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_4;
    // 0x80151C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80151C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80151C08:
    // 0x80151C08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80151C0C: jr          $ra
    // 0x80151C10: nop

    return;
    // 0x80151C10: nop

;}
RECOMP_FUNC void itBombHeiExplodeWaitInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177D30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177D34: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80177D38: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x80177D3C: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80177D40: lw          $t6, 0x80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X80);
    // 0x80177D44: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x80177D48: jal         0x80172F98
    // 0x80177D4C: sw          $zero, 0x94($t6)
    MEM_W(0X94, ctx->r14) = 0;
    itMainCheckSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x80177D4C: sw          $zero, 0x94($t6)
    MEM_W(0X94, ctx->r14) = 0;
    after_0:
    // 0x80177D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177D58: jr          $ra
    // 0x80177D5C: nop

    return;
    // 0x80177D5C: nop

;}
RECOMP_FUNC void ftKirbySpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160D24: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80160D28: jal         0x800D9480
    // 0x80160D2C: addiu       $a1, $a1, 0x12D8
    ctx->r5 = ADD32(ctx->r5, 0X12D8);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80160D2C: addiu       $a1, $a1, 0x12D8
    ctx->r5 = ADD32(ctx->r5, 0X12D8);
    after_0:
    // 0x80160D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80160D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80160D38: jr          $ra
    // 0x80160D3C: nop

    return;
    // 0x80160D3C: nop

;}
RECOMP_FUNC void ftFoxSpecialLwLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CD5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015CD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CD64: jal         0x8015D0CC
    // 0x8015CD68: nop

    ftFoxSpecialLwTurnCheckInterruptLoop(rdram, ctx);
        goto after_0;
    // 0x8015CD68: nop

    after_0:
    // 0x8015CD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015CD70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015CD74: jr          $ra
    // 0x8015CD78: nop

    return;
    // 0x8015CD78: nop

;}
RECOMP_FUNC void grZebesMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010844C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108450: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80108454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010845C: jal         0x80009968
    // 0x80108460: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80108460: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80108464: jal         0x801080EC
    // 0x80108468: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    grZebesMakeAcid(rdram, ctx);
        goto after_1;
    // 0x80108468: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8010846C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80108470: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80108474: addiu       $a1, $a1, -0x7C3C
    ctx->r5 = ADD32(ctx->r5, -0X7C3C);
    // 0x80108478: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010847C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108480: jal         0x80008188
    // 0x80108484: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80108484: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80108488: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010848C: addiu       $a1, $a1, -0x7B54
    ctx->r5 = ADD32(ctx->r5, -0X7B54);
    // 0x80108490: jal         0x800E1DE8
    // 0x80108494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftMainCheckAddGroundHazard(rdram, ctx);
        goto after_3;
    // 0x80108494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80108498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010849C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801084A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801084A4: jr          $ra
    // 0x801084A8: nop

    return;
    // 0x801084A8: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateScroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D3E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D3E4: jal         0x8018F630
    // 0x8018D3E8: nop

    sc1PTrainingModeUpdateOptionArrows(rdram, ctx);
        goto after_0;
    // 0x8018D3E8: nop

    after_0:
    // 0x8018D3EC: jal         0x8018FE40
    // 0x8018D3F0: nop

    sc1PTrainingModeUpdateUnderline(rdram, ctx);
        goto after_1;
    // 0x8018D3F0: nop

    after_1:
    // 0x8018D3F4: jal         0x800269C0
    // 0x8018D3F8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8018D3F8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_2:
    // 0x8018D3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D404: jr          $ra
    // 0x8018D408: nop

    return;
    // 0x8018D408: nop

;}
RECOMP_FUNC void func_ovl8_8037499C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037499C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803749A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803749A4: jal         0x8037C5E8
    // 0x803749A8: nop

    func_ovl8_8037C5E8(rdram, ctx);
        goto after_0;
    // 0x803749A8: nop

    after_0:
    // 0x803749AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803749B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803749B4: jr          $ra
    // 0x803749B8: nop

    return;
    // 0x803749B8: nop

;}
RECOMP_FUNC void mnVSItemSwitchFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132AF4: addiu       $v0, $v0, 0x3468
    ctx->r2 = ADD32(ctx->r2, 0X3468);
    // 0x80132AF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132AFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B04: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132B08: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132B0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132B10: bne         $at, $zero, L_80133080
    if (ctx->r1 != 0) {
        // 0x80132B14: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80133080;
    }
    // 0x80132B14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132B18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132B1C: addiu       $v1, $v1, 0x3464
    ctx->r3 = ADD32(ctx->r3, 0X3464);
    // 0x80132B20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132B24: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132B28: beq         $v0, $zero, L_80132B34
    if (ctx->r2 == 0) {
        // 0x80132B2C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132B34;
    }
    // 0x80132B2C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132B30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80132B34:
    // 0x80132B34: jal         0x80390A04
    // 0x80132B38: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132B38: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80132B3C: beq         $v0, $zero, L_80132B78
    if (ctx->r2 == 0) {
        // 0x80132B40: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132B78;
    }
    // 0x80132B40: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132B44: jal         0x80390AC0
    // 0x80132B48: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132B48: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80132B4C: beq         $v0, $zero, L_80132B78
    if (ctx->r2 == 0) {
        // 0x80132B50: nop
    
            goto L_80132B78;
    }
    // 0x80132B50: nop

    // 0x80132B54: jal         0x80390804
    // 0x80132B58: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_2;
    // 0x80132B58: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_2:
    // 0x80132B5C: bne         $v0, $zero, L_80132B78
    if (ctx->r2 != 0) {
        // 0x80132B60: nop
    
            goto L_80132B78;
    }
    // 0x80132B60: nop

    // 0x80132B64: jal         0x80390804
    // 0x80132B68: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_3;
    // 0x80132B68: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_3:
    // 0x80132B6C: bne         $v0, $zero, L_80132B78
    if (ctx->r2 != 0) {
        // 0x80132B70: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132B78;
    }
    // 0x80132B70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B74: sw          $zero, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = 0;
L_80132B78:
    // 0x80132B78: jal         0x8039076C
    // 0x80132B7C: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_4;
    // 0x80132B7C: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_4:
    // 0x80132B80: beq         $v0, $zero, L_80132BA8
    if (ctx->r2 == 0) {
        // 0x80132B84: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_80132BA8;
    }
    // 0x80132B84: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80132B88: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B8C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132B90: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80132B94: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80132B98: jal         0x80132A44
    // 0x80132B9C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    mnVSItemSwitchSetItemToggles(rdram, ctx);
        goto after_5;
    // 0x80132B9C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_5:
    // 0x80132BA0: jal         0x80005C74
    // 0x80132BA4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x80132BA4: nop

    after_6:
L_80132BA8:
    // 0x80132BA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132BAC: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
    // 0x80132BB0: bne         $v0, $zero, L_80132BD0
    if (ctx->r2 != 0) {
        // 0x80132BB4: nop
    
            goto L_80132BD0;
    }
    // 0x80132BB4: nop

    // 0x80132BB8: jal         0x80390804
    // 0x80132BBC: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x80132BBC: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_7:
    // 0x80132BC0: bne         $v0, $zero, L_80132BE8
    if (ctx->r2 != 0) {
        // 0x80132BC4: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132BE8;
    }
    // 0x80132BC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80132BC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132BCC: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
L_80132BD0:
    // 0x80132BD0: bne         $v0, $zero, L_80132C94
    if (ctx->r2 != 0) {
        // 0x80132BD4: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132C94;
    }
    // 0x80132BD4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132BD8: jal         0x80390950
    // 0x80132BDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_8;
    // 0x80132BDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80132BE0: beq         $v0, $zero, L_80132C94
    if (ctx->r2 == 0) {
        // 0x80132BE4: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132C94;
    }
    // 0x80132BE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80132BE8:
    // 0x80132BE8: jal         0x800269C0
    // 0x80132BEC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80132BEC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_9:
    // 0x80132BF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80132BF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132BF8: addiu       $v1, $v1, 0x3464
    ctx->r3 = ADD32(ctx->r3, 0X3464);
    // 0x80132BFC: beq         $t2, $zero, L_80132C0C
    if (ctx->r10 == 0) {
        // 0x80132C00: addiu       $t3, $zero, 0xC
        ctx->r11 = ADD32(0, 0XC);
            goto L_80132C0C;
    }
    // 0x80132C00: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80132C04: b           L_80132C34
    // 0x80132C08: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80132C34;
    // 0x80132C08: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80132C0C:
    // 0x80132C0C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80132C10: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x80132C14: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132C18: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x80132C1C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80132C20: mflo        $t7
    ctx->r15 = lo;
    // 0x80132C24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132C28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132C2C: addiu       $v1, $v1, 0x3464
    ctx->r3 = ADD32(ctx->r3, 0X3464);
    // 0x80132C30: sw          $t7, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r15;
L_80132C34:
    // 0x80132C34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C38: addiu       $v0, $v0, 0x33D8
    ctx->r2 = ADD32(ctx->r2, 0X33D8);
    // 0x80132C3C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132C40: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80132C44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C48: bne         $a2, $zero, L_80132C58
    if (ctx->r6 != 0) {
        // 0x80132C4C: addiu       $t9, $a2, -0x1
        ctx->r25 = ADD32(ctx->r6, -0X1);
            goto L_80132C58;
    }
    // 0x80132C4C: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x80132C50: b           L_80132C5C
    // 0x80132C54: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80132C5C;
    // 0x80132C54: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80132C58:
    // 0x80132C58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80132C5C:
    // 0x80132C5C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132C60: bne         $a2, $zero, L_80132C74
    if (ctx->r6 != 0) {
        // 0x80132C64: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80132C74;
    }
    // 0x80132C64: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80132C68: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80132C6C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80132C70: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80132C74:
    // 0x80132C74: jal         0x8013212C
    // 0x80132C78: lw          $a0, 0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3460);
    mnVSItemSwitchSetCursorPosition(rdram, ctx);
        goto after_10;
    // 0x80132C78: lw          $a0, 0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3460);
    after_10:
    // 0x80132C7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C80: jal         0x80009A84
    // 0x80132C84: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    gcEjectGObj(rdram, ctx);
        goto after_11;
    // 0x80132C84: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    after_11:
    // 0x80132C88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C8C: jal         0x80131F30
    // 0x80132C90: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_12;
    // 0x80132C90: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_12:
L_80132C94:
    // 0x80132C94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C98: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
    // 0x80132C9C: bne         $v0, $zero, L_80132CBC
    if (ctx->r2 != 0) {
        // 0x80132CA0: nop
    
            goto L_80132CBC;
    }
    // 0x80132CA0: nop

    // 0x80132CA4: jal         0x80390804
    // 0x80132CA8: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_13;
    // 0x80132CA8: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_13:
    // 0x80132CAC: bne         $v0, $zero, L_80132CD4
    if (ctx->r2 != 0) {
        // 0x80132CB0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132CD4;
    }
    // 0x80132CB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80132CB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132CB8: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
L_80132CBC:
    // 0x80132CBC: bne         $v0, $zero, L_80132D7C
    if (ctx->r2 != 0) {
        // 0x80132CC0: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132D7C;
    }
    // 0x80132CC0: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132CC4: jal         0x80390950
    // 0x80132CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_14;
    // 0x80132CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80132CCC: beq         $v0, $zero, L_80132D7C
    if (ctx->r2 == 0) {
        // 0x80132CD0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132D7C;
    }
    // 0x80132CD0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80132CD4:
    // 0x80132CD4: jal         0x800269C0
    // 0x80132CD8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_15;
    // 0x80132CD8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_15:
    // 0x80132CDC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80132CE0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132CE4: addiu       $v0, $v0, 0x33D8
    ctx->r2 = ADD32(ctx->r2, 0X33D8);
    // 0x80132CE8: beq         $t2, $zero, L_80132D00
    if (ctx->r10 == 0) {
        // 0x80132CEC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80132D00;
    }
    // 0x80132CEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132CF0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80132CF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CF8: b           L_80132D1C
    // 0x80132CFC: sw          $t3, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r11;
        goto L_80132D1C;
    // 0x80132CFC: sw          $t3, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r11;
L_80132D00:
    // 0x80132D00: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80132D04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132D08: addiu       $t4, $t5, 0xA0
    ctx->r12 = ADD32(ctx->r13, 0XA0);
    // 0x80132D0C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80132D10: mflo        $t6
    ctx->r14 = lo;
    // 0x80132D14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D18: sw          $t6, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r14;
L_80132D1C:
    // 0x80132D1C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132D20: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80132D24: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132D28: bne         $a2, $at, L_80132D38
    if (ctx->r6 != ctx->r1) {
        // 0x80132D2C: addiu       $t7, $a2, 0x1
        ctx->r15 = ADD32(ctx->r6, 0X1);
            goto L_80132D38;
    }
    // 0x80132D2C: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x80132D30: b           L_80132D3C
    // 0x80132D34: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80132D3C;
    // 0x80132D34: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80132D38:
    // 0x80132D38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80132D3C:
    // 0x80132D3C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132D40: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80132D44: bne         $a2, $at, L_80132D5C
    if (ctx->r6 != ctx->r1) {
        // 0x80132D48: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80132D5C;
    }
    // 0x80132D48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80132D4C: lw          $t8, 0x3464($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3464);
    // 0x80132D50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D54: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80132D58: sw          $t9, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r25;
L_80132D5C:
    // 0x80132D5C: jal         0x8013212C
    // 0x80132D60: lw          $a0, 0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3460);
    mnVSItemSwitchSetCursorPosition(rdram, ctx);
        goto after_16;
    // 0x80132D60: lw          $a0, 0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3460);
    after_16:
    // 0x80132D64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D68: jal         0x80009A84
    // 0x80132D6C: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    gcEjectGObj(rdram, ctx);
        goto after_17;
    // 0x80132D6C: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    after_17:
    // 0x80132D70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D74: jal         0x80131F30
    // 0x80132D78: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_18;
    // 0x80132D78: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_18:
L_80132D7C:
    // 0x80132D7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132D80: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
    // 0x80132D84: bne         $v0, $zero, L_80132DA4
    if (ctx->r2 != 0) {
        // 0x80132D88: nop
    
            goto L_80132DA4;
    }
    // 0x80132D88: nop

    // 0x80132D8C: jal         0x80390804
    // 0x80132D90: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_19;
    // 0x80132D90: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_19:
    // 0x80132D94: bne         $v0, $zero, L_80132DBC
    if (ctx->r2 != 0) {
        // 0x80132D98: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132DBC;
    }
    // 0x80132D98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80132D9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132DA0: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
L_80132DA4:
    // 0x80132DA4: bne         $v0, $zero, L_80132E9C
    if (ctx->r2 != 0) {
        // 0x80132DA8: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132E9C;
    }
    // 0x80132DA8: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132DAC: jal         0x8039089C
    // 0x80132DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_20;
    // 0x80132DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80132DB4: beq         $v0, $zero, L_80132E9C
    if (ctx->r2 == 0) {
        // 0x80132DB8: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132E9C;
    }
    // 0x80132DB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80132DBC:
    // 0x80132DBC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132DC0: lw          $a2, 0x33D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X33D8);
    // 0x80132DC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132DC8: bne         $a2, $zero, L_80132E2C
    if (ctx->r6 != 0) {
        // 0x80132DCC: sll         $t2, $a2, 2
        ctx->r10 = S32(ctx->r6 << 2);
            goto L_80132E2C;
    }
    // 0x80132DCC: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80132DD0: jal         0x800269C0
    // 0x80132DD4: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_21;
    // 0x80132DD4: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_21:
    // 0x80132DD8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132DDC: addiu       $a2, $a2, 0x3420
    ctx->r6 = ADD32(ctx->r6, 0X3420);
    // 0x80132DE0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132DE4: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80132DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132DEC: blez        $v1, L_80132DFC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80132DF0: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80132DFC;
    }
    // 0x80132DF0: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80132DF4: b           L_80132E00
    // 0x80132DF8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80132E00;
    // 0x80132DF8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80132DFC:
    // 0x80132DFC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_80132E00:
    // 0x80132E00: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    // 0x80132E04: jal         0x80132A94
    // 0x80132E08: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_22;
    // 0x80132E08: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    after_22:
    // 0x80132E0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E10: jal         0x80009A84
    // 0x80132E14: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80132E14: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    after_23:
    // 0x80132E18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E1C: jal         0x80131F30
    // 0x80132E20: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_24;
    // 0x80132E20: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_24:
    // 0x80132E24: b           L_80132E6C
    // 0x80132E28: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
        goto L_80132E6C;
    // 0x80132E28: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80132E2C:
    // 0x80132E2C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80132E30: lw          $t3, 0x3420($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3420);
    // 0x80132E34: bnel        $t3, $zero, L_80132E6C
    if (ctx->r11 != 0) {
        // 0x80132E38: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80132E6C;
    }
    goto skip_0;
    // 0x80132E38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80132E3C: jal         0x800269C0
    // 0x80132E40: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_25;
    // 0x80132E40: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_25:
    // 0x80132E44: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132E48: lw          $a0, 0x33D8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X33D8);
    // 0x80132E4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132E54: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80132E58: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80132E5C: sw          $t5, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r13;
    // 0x80132E60: jal         0x80132A94
    // 0x80132E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_26;
    // 0x80132E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80132E68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80132E6C:
    // 0x80132E6C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80132E70: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132E74: beq         $t6, $zero, L_80132E8C
    if (ctx->r14 == 0) {
        // 0x80132E78: addiu       $t9, $t8, 0xA0
        ctx->r25 = ADD32(ctx->r24, 0XA0);
            goto L_80132E8C;
    }
    // 0x80132E78: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x80132E7C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80132E80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E84: b           L_80132E9C
    // 0x80132E88: sw          $t7, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r15;
        goto L_80132E9C;
    // 0x80132E88: sw          $t7, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r15;
L_80132E8C:
    // 0x80132E8C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80132E90: mflo        $t0
    ctx->r8 = lo;
    // 0x80132E94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E98: sw          $t0, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r8;
L_80132E9C:
    // 0x80132E9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132EA0: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
    // 0x80132EA4: bne         $v0, $zero, L_80132EC4
    if (ctx->r2 != 0) {
        // 0x80132EA8: nop
    
            goto L_80132EC4;
    }
    // 0x80132EA8: nop

    // 0x80132EAC: jal         0x80390804
    // 0x80132EB0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_27;
    // 0x80132EB0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_27:
    // 0x80132EB4: bne         $v0, $zero, L_80132EDC
    if (ctx->r2 != 0) {
        // 0x80132EB8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132EDC;
    }
    // 0x80132EB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80132EBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132EC0: lw          $v0, 0x3464($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3464);
L_80132EC4:
    // 0x80132EC4: bne         $v0, $zero, L_80132FC0
    if (ctx->r2 != 0) {
        // 0x80132EC8: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132FC0;
    }
    // 0x80132EC8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132ECC: jal         0x8039089C
    // 0x80132ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_28;
    // 0x80132ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80132ED4: beq         $v0, $zero, L_80132FC0
    if (ctx->r2 == 0) {
        // 0x80132ED8: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132FC0;
    }
    // 0x80132ED8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80132EDC:
    // 0x80132EDC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132EE0: lw          $a2, 0x33D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X33D8);
    // 0x80132EE4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132EE8: bne         $a2, $zero, L_80132F4C
    if (ctx->r6 != 0) {
        // 0x80132EEC: sll         $t2, $a2, 2
        ctx->r10 = S32(ctx->r6 << 2);
            goto L_80132F4C;
    }
    // 0x80132EEC: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80132EF0: jal         0x800269C0
    // 0x80132EF4: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_29;
    // 0x80132EF4: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_29:
    // 0x80132EF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132EFC: addiu       $a2, $a2, 0x3420
    ctx->r6 = ADD32(ctx->r6, 0X3420);
    // 0x80132F00: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132F04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132F08: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80132F0C: beq         $at, $zero, L_80132F1C
    if (ctx->r1 == 0) {
        // 0x80132F10: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_80132F1C;
    }
    // 0x80132F10: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80132F14: b           L_80132F20
    // 0x80132F18: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80132F20;
    // 0x80132F18: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_80132F1C:
    // 0x80132F1C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80132F20:
    // 0x80132F20: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    // 0x80132F24: jal         0x80132A94
    // 0x80132F28: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_30;
    // 0x80132F28: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    after_30:
    // 0x80132F2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132F30: jal         0x80009A84
    // 0x80132F34: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    gcEjectGObj(rdram, ctx);
        goto after_31;
    // 0x80132F34: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    after_31:
    // 0x80132F38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132F3C: jal         0x80131F30
    // 0x80132F40: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_32;
    // 0x80132F40: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_32:
    // 0x80132F44: b           L_80132F8C
    // 0x80132F48: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
        goto L_80132F8C;
    // 0x80132F48: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
L_80132F4C:
    // 0x80132F4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80132F50: lw          $t3, 0x3420($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3420);
    // 0x80132F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132F58: bnel        $t3, $at, L_80132F8C
    if (ctx->r11 != ctx->r1) {
        // 0x80132F5C: lw          $t4, 0x1C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X1C);
            goto L_80132F8C;
    }
    goto skip_1;
    // 0x80132F5C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80132F60: jal         0x800269C0
    // 0x80132F64: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_33;
    // 0x80132F64: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_33:
    // 0x80132F68: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132F6C: lw          $a0, 0x33D8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X33D8);
    // 0x80132F70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F78: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80132F7C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80132F80: jal         0x80132A94
    // 0x80132F84: sw          $zero, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = 0;
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_34;
    // 0x80132F84: sw          $zero, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = 0;
    after_34:
    // 0x80132F88: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
L_80132F8C:
    // 0x80132F8C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80132F90: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80132F94: beq         $t4, $zero, L_80132FAC
    if (ctx->r12 == 0) {
        // 0x80132F98: subu        $t9, $t8, $t7
        ctx->r25 = SUB32(ctx->r24, ctx->r15);
            goto L_80132FAC;
    }
    // 0x80132F98: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80132F9C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80132FA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FA4: b           L_80132FC0
    // 0x80132FA8: sw          $t6, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r14;
        goto L_80132FC0;
    // 0x80132FA8: sw          $t6, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r14;
L_80132FAC:
    // 0x80132FAC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132FB0: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80132FB4: mflo        $t0
    ctx->r8 = lo;
    // 0x80132FB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FBC: sw          $t0, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = ctx->r8;
L_80132FC0:
    // 0x80132FC0: jal         0x8039076C
    // 0x80132FC4: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_35;
    // 0x80132FC4: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_35:
    // 0x80132FC8: beq         $v0, $zero, L_80133080
    if (ctx->r2 == 0) {
        // 0x80132FCC: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_80133080;
    }
    // 0x80132FCC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132FD0: lw          $t1, 0x33D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X33D8);
    // 0x80132FD4: bne         $t1, $zero, L_80133038
    if (ctx->r9 != 0) {
        // 0x80132FD8: nop
    
            goto L_80133038;
    }
    // 0x80132FD8: nop

    // 0x80132FDC: jal         0x800269C0
    // 0x80132FE0: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_36;
    // 0x80132FE0: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_36:
    // 0x80132FE4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132FE8: addiu       $a2, $a2, 0x3420
    ctx->r6 = ADD32(ctx->r6, 0X3420);
    // 0x80132FEC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132FF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132FF4: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80132FF8: beq         $at, $zero, L_80133008
    if (ctx->r1 == 0) {
        // 0x80132FFC: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80133008;
    }
    // 0x80132FFC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80133000: b           L_8013300C
    // 0x80133004: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_8013300C;
    // 0x80133004: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_80133008:
    // 0x80133008: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8013300C:
    // 0x8013300C: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    // 0x80133010: jal         0x80132A94
    // 0x80133014: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_37;
    // 0x80133014: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    after_37:
    // 0x80133018: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013301C: jal         0x80009A84
    // 0x80133020: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    gcEjectGObj(rdram, ctx);
        goto after_38;
    // 0x80133020: lw          $a0, 0x33DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33DC);
    after_38:
    // 0x80133024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133028: jal         0x80131F30
    // 0x8013302C: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_39;
    // 0x8013302C: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_39:
    // 0x80133030: b           L_80133084
    // 0x80133034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133084;
    // 0x80133034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133038:
    // 0x80133038: jal         0x800269C0
    // 0x8013303C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_40;
    // 0x8013303C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_40:
    // 0x80133040: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133044: lw          $a2, 0x33D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X33D8);
    // 0x80133048: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8013304C: addiu       $t5, $t5, 0x3420
    ctx->r13 = ADD32(ctx->r13, 0X3420);
    // 0x80133050: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80133054: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80133058: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8013305C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133060: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80133064: bnel        $t4, $zero, L_80133078
    if (ctx->r12 != 0) {
        // 0x80133068: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80133078;
    }
    goto skip_2;
    // 0x80133068: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_2:
    // 0x8013306C: b           L_80133078
    // 0x80133070: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80133078;
    // 0x80133070: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133074: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80133078:
    // 0x80133078: jal         0x80132A94
    // 0x8013307C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    mnVSItemSwitchUpdateOption(rdram, ctx);
        goto after_41;
    // 0x8013307C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_41:
L_80133080:
    // 0x80133080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133084:
    // 0x80133084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133088: jr          $ra
    // 0x8013308C: nop

    return;
    // 0x8013308C: nop

;}
RECOMP_FUNC void dbBattleGetShuffledFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80131DF0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80131DF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131DF8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80131DFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80131E00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131E04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131E08:
    // 0x80131E08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80131E0C: sllv        $a0, $t6, $v1
    ctx->r4 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80131E10: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x80131E14: beq         $t7, $zero, L_80131E28
    if (ctx->r15 == 0) {
        // 0x80131E18: and         $t8, $a1, $a0
        ctx->r24 = ctx->r5 & ctx->r4;
            goto L_80131E28;
    }
    // 0x80131E18: and         $t8, $a1, $a0
    ctx->r24 = ctx->r5 & ctx->r4;
    // 0x80131E1C: bne         $t8, $zero, L_80131E28
    if (ctx->r24 != 0) {
        // 0x80131E20: nop
    
            goto L_80131E28;
    }
    // 0x80131E20: nop

    // 0x80131E24: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80131E28:
    // 0x80131E28: bnel        $a2, $zero, L_80131E08
    if (ctx->r6 != 0) {
        // 0x80131E2C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80131E08;
    }
    goto skip_0;
    // 0x80131E2C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80131E30: jr          $ra
    // 0x80131E34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131E34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itMSBombHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017657C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176584: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176588: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x8017658C: jal         0x80172EC8
    // 0x80176590: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80176590: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80176594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017659C: jr          $ra
    // 0x801765A0: nop

    return;
    // 0x801765A0: nop

;}
RECOMP_FUNC void mpCollisionGetVertexPositionID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA5E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA5EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA5F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA5F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FA5F8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800FA5FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FA600: beq         $a0, $at, L_800FA614
    if (ctx->r4 == ctx->r1) {
        // 0x800FA604: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800FA614;
    }
    // 0x800FA604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA608: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FA60C: bne         $a0, $at, L_800FA638
    if (ctx->r4 != ctx->r1) {
        // 0x800FA610: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800FA638;
    }
    // 0x800FA610: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
L_800FA614:
    // 0x800FA614: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA618: addiu       $s0, $s0, 0x3CC
    ctx->r16 = ADD32(ctx->r16, 0X3CC);
    // 0x800FA61C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA620:
    // 0x800FA620: jal         0x80023624
    // 0x800FA624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FA624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FA628: jal         0x800A3040
    // 0x800FA62C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FA62C: nop

    after_1:
    // 0x800FA630: b           L_800FA620
    // 0x800FA634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FA620;
    // 0x800FA634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA638:
    // 0x800FA638: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800FA63C: addiu       $t4, $t4, 0x136C
    ctx->r12 = ADD32(ctx->r12, 0X136C);
    // 0x800FA640: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800FA644: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x800FA648: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x800FA64C: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800FA650: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800FA654: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800FA658: addiu       $t3, $t3, 0x1304
    ctx->r11 = ADD32(ctx->r11, 0X1304);
    // 0x800FA65C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800FA660: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800FA664: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FA668: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x800FA66C: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800FA670: addiu       $t1, $t1, 0x1378
    ctx->r9 = ADD32(ctx->r9, 0X1378);
    // 0x800FA674: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800FA678: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x800FA67C: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800FA680: bnel        $at, $zero, L_800FA6AC
    if (ctx->r1 != 0) {
        // 0x800FA684: lw          $t6, 0x0($t1)
        ctx->r14 = MEM_W(ctx->r9, 0X0);
            goto L_800FA6AC;
    }
    goto skip_0;
    // 0x800FA684: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    skip_0:
    // 0x800FA688: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA68C: addiu       $s0, $s0, 0x3E4
    ctx->r16 = ADD32(ctx->r16, 0X3E4);
L_800FA690:
    // 0x800FA690: jal         0x80023624
    // 0x800FA694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FA694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FA698: jal         0x800A3040
    // 0x800FA69C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FA69C: nop

    after_3:
    // 0x800FA6A0: b           L_800FA690
    // 0x800FA6A4: nop

        goto L_800FA690;
    // 0x800FA6A4: nop

    // 0x800FA6A8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
L_800FA6AC:
    // 0x800FA6AC: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800FA6B0: addiu       $t0, $t0, 0x1374
    ctx->r8 = ADD32(ctx->r8, 0X1374);
    // 0x800FA6B4: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800FA6B8: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x800FA6BC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800FA6C0: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800FA6C4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800FA6C8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800FA6CC: addu        $t5, $t6, $a0
    ctx->r13 = ADD32(ctx->r14, ctx->r4);
    // 0x800FA6D0: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x800FA6D4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800FA6D8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800FA6DC: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA6E0: addiu       $a3, $a3, 0x1370
    ctx->r7 = ADD32(ctx->r7, 0X1370);
    // 0x800FA6E4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800FA6E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800FA6EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800FA6F0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800FA6F4: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800FA6F8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800FA6FC: nop

    // 0x800FA700: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FA704: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800FA708: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800FA70C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800FA710: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800FA714: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800FA718: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800FA71C: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800FA720: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x800FA724: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800FA728: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800FA72C: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FA730: mflo        $t7
    ctx->r15 = lo;
    // 0x800FA734: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800FA738: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800FA73C: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x800FA740: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800FA744: nop

    // 0x800FA748: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FA74C: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x800FA750: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800FA754: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800FA758: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800FA75C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800FA760: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800FA764: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800FA768: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x800FA76C: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x800FA770: bnel        $t7, $zero, L_800FA788
    if (ctx->r15 != 0) {
        // 0x800FA774: lwc1        $f18, 0x0($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
            goto L_800FA788;
    }
    goto skip_1;
    // 0x800FA774: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x800FA778: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x800FA77C: beql        $t8, $zero, L_800FA7A8
    if (ctx->r24 == 0) {
        // 0x800FA780: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FA7A8;
    }
    goto skip_2;
    // 0x800FA780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800FA784: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
L_800FA788:
    // 0x800FA788: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FA78C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800FA790: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800FA794: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800FA798: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FA79C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FA7A0: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x800FA7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FA7A8:
    // 0x800FA7A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA7AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA7B0: jr          $ra
    // 0x800FA7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonAttackHi4SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801505F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801505F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801505F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801505FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80150600: addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // 0x80150604: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80150608: jal         0x800E6F24
    // 0x8015060C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015060C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80150610: jal         0x800E0830
    // 0x80150614: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80150614: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80150618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015061C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150620: jr          $ra
    // 0x80150624: nop

    return;
    // 0x80150624: nop

;}
RECOMP_FUNC void mnVSResultsDrawResultsStockTeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364B0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801364B4: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801364B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801364BC: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x801364C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801364C4: bne         $v0, $at, L_801364DC
    if (ctx->r2 != ctx->r1) {
        // 0x801364C8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801364DC;
    }
    // 0x801364C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801364CC: jal         0x80134DA0
    // 0x801364D0: nop

    mnVSResultsMakeTint(rdram, ctx);
        goto after_0;
    // 0x801364D0: nop

    after_0:
    // 0x801364D4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801364D8: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_801364DC:
    // 0x801364DC: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x801364E0: bnel        $v0, $at, L_801364FC
    if (ctx->r2 != ctx->r1) {
        // 0x801364E4: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_801364FC;
    }
    goto skip_0;
    // 0x801364E4: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    skip_0:
    // 0x801364E8: jal         0x80136100
    // 0x801364EC: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    mnVSResultsMakePlaceRow(rdram, ctx);
        goto after_1;
    // 0x801364EC: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_1:
    // 0x801364F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801364F4: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801364F8: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
L_801364FC:
    // 0x801364FC: bnel        $v0, $at, L_80136518
    if (ctx->r2 != ctx->r1) {
        // 0x80136500: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80136518;
    }
    goto skip_1;
    // 0x80136500: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    skip_1:
    // 0x80136504: jal         0x80135D58
    // 0x80136508: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    mnVSResultsMakeBar(rdram, ctx);
        goto after_2;
    // 0x80136508: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    after_2:
    // 0x8013650C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136510: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136514: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
L_80136518:
    // 0x80136518: bnel        $v0, $at, L_80136534
    if (ctx->r2 != ctx->r1) {
        // 0x8013651C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136534;
    }
    goto skip_2;
    // 0x8013651C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80136520: jal         0x8013549C
    // 0x80136524: nop

    mnVSResultsMakeHeader(rdram, ctx);
        goto after_3;
    // 0x80136524: nop

    after_3:
    // 0x80136528: jal         0x8013569C
    // 0x8013652C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    mnVSResultsMakeKOs(rdram, ctx);
        goto after_4;
    // 0x8013652C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_4:
    // 0x80136530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136534:
    // 0x80136534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136538: jr          $ra
    // 0x8013653C: nop

    return;
    // 0x8013653C: nop

;}
RECOMP_FUNC void efManagerYoshiShieldProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80101184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101188: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8010118C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80101190: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80101194: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80101198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010119C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801011A0: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x801011A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801011A8: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x801011AC: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x801011B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801011B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801011B8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801011BC: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x801011C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801011C4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801011C8: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x801011CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801011D0: nop

    // 0x801011D4: bc1f        L_801011E0
    if (!c1cs) {
        // 0x801011D8: nop
    
            goto L_801011E0;
    }
    // 0x801011D8: nop

    // 0x801011DC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801011E0:
    // 0x801011E0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801011E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801011E8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x801011EC: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x801011F0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801011F4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801011F8: nop

    // 0x801011FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80101200: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80101204: nop

    // 0x80101208: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8010120C: beql        $t9, $zero, L_8010125C
    if (ctx->r25 == 0) {
        // 0x80101210: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_8010125C;
    }
    goto skip_0;
    // 0x80101210: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80101214: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80101218: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010121C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80101220: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80101224: nop

    // 0x80101228: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8010122C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80101230: nop

    // 0x80101234: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80101238: bne         $t9, $zero, L_80101250
    if (ctx->r25 != 0) {
        // 0x8010123C: nop
    
            goto L_80101250;
    }
    // 0x8010123C: nop

    // 0x80101240: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80101244: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80101248: b           L_80101268
    // 0x8010124C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80101268;
    // 0x8010124C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80101250:
    // 0x80101250: b           L_80101268
    // 0x80101254: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80101268;
    // 0x80101254: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80101258: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_8010125C:
    // 0x8010125C: nop

    // 0x80101260: bltz        $t9, L_80101250
    if (SIGNED(ctx->r25) < 0) {
        // 0x80101264: nop
    
            goto L_80101250;
    }
    // 0x80101264: nop

L_80101268:
    // 0x80101268: lui         $at, 0x4356
    ctx->r1 = S32(0X4356 << 16);
    // 0x8010126C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80101270: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80101274: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80101278: sb          $t9, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r25;
    // 0x8010127C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80101280: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80101284: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80101288: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x8010128C: nop

    // 0x80101290: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80101294: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80101298: nop

    // 0x8010129C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801012A0: beql        $v1, $zero, L_801012F0
    if (ctx->r3 == 0) {
        // 0x801012A4: mfc1        $v1, $f10
        ctx->r3 = (int32_t)ctx->f10.u32l;
            goto L_801012F0;
    }
    goto skip_1;
    // 0x801012A4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x801012A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801012AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801012B0: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x801012B4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x801012B8: nop

    // 0x801012BC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801012C0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x801012C4: nop

    // 0x801012C8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x801012CC: bne         $v1, $zero, L_801012E4
    if (ctx->r3 != 0) {
        // 0x801012D0: nop
    
            goto L_801012E4;
    }
    // 0x801012D0: nop

    // 0x801012D4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x801012D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801012DC: b           L_801012FC
    // 0x801012E0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_801012FC;
    // 0x801012E0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_801012E4:
    // 0x801012E4: b           L_801012FC
    // 0x801012E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_801012FC;
    // 0x801012E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x801012EC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
L_801012F0:
    // 0x801012F0: nop

    // 0x801012F4: bltz        $v1, L_801012E4
    if (SIGNED(ctx->r3) < 0) {
        // 0x801012F8: nop
    
            goto L_801012E4;
    }
    // 0x801012F8: nop

L_801012FC:
    // 0x801012FC: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x80101300: sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    // 0x80101304: sb          $v1, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r3;
    // 0x80101308: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8010130C: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x80101310: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101314: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80101318: lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4);
    // 0x8010131C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80101320: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80101324: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80101328: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x8010132C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80101330: lbu         $t9, 0x18($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X18);
    // 0x80101334: lbu         $t6, 0x1A($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1A);
    // 0x80101338: lbu         $t3, 0x19($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X19);
    // 0x8010133C: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x80101340: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80101344: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80101348: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8010134C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80101350: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80101354: jal         0x80013E8C
    // 0x80101358: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    gcDrawDObjDLHead1(rdram, ctx);
        goto after_0;
    // 0x80101358: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010135C: jal         0x800FCCC0
    // 0x80101360: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efDisplayCLDProcDisplay(rdram, ctx);
        goto after_1;
    // 0x80101360: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80101364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101368: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010136C: jr          $ra
    // 0x80101370: nop

    return;
    // 0x80101370: nop

;}
RECOMP_FUNC void func_ovl8_80374D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374D34: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80374D38: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374D3C: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x80374D40: lh          $t6, 0xB8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB8);
    // 0x80374D44: jalr        $t9
    // 0x80374D48: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374D48: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80374D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374D54: jr          $ra
    // 0x80374D58: nop

    return;
    // 0x80374D58: nop

;}
RECOMP_FUNC void itDisplayXLUProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80171D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171D40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80171D44: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80171D48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80171D4C: jal         0x80171C10
    // 0x80171D50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x80171D50: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80171D54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80171D58: beq         $v0, $zero, L_80171DE4
    if (ctx->r2 == 0) {
        // 0x80171D5C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80171DE4;
    }
    // 0x80171D5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80171D60: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x80171D64: beq         $v0, $zero, L_80171D80
    if (ctx->r2 == 0) {
        // 0x80171D68: nop
    
            goto L_80171D80;
    }
    // 0x80171D68: nop

    // 0x80171D6C: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    // 0x80171D70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80171D74: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80171D78: bgez        $t8, L_80171D90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80171D7C: nop
    
            goto L_80171D90;
    }
    // 0x80171D7C: nop

L_80171D80:
    // 0x80171D80: jal         0x80014768
    // 0x80171D84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_1;
    // 0x80171D84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80171D88: b           L_80171DE8
    // 0x80171D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171DE8;
    // 0x80171D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171D90:
    // 0x80171D90: bnel        $v0, $at, L_80171DB8
    if (ctx->r2 != ctx->r1) {
        // 0x80171D94: lw          $t9, 0x248($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X248);
            goto L_80171DB8;
    }
    goto skip_0;
    // 0x80171D94: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
    skip_0:
    // 0x80171D98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80171D9C: jal         0x80014768
    // 0x80171DA0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_2;
    // 0x80171DA0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80171DA4: jal         0x801719AC
    // 0x80171DA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80171DA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80171DAC: b           L_80171DE8
    // 0x80171DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171DE8;
    // 0x80171DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171DB4: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
L_80171DB8:
    // 0x80171DB8: bne         $t9, $zero, L_80171DDC
    if (ctx->r25 != 0) {
        // 0x80171DBC: nop
    
            goto L_80171DDC;
    }
    // 0x80171DBC: nop

    // 0x80171DC0: lw          $t0, 0x10C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10C);
    // 0x80171DC4: bne         $t0, $zero, L_80171DDC
    if (ctx->r8 != 0) {
        // 0x80171DC8: nop
    
            goto L_80171DDC;
    }
    // 0x80171DC8: nop

    // 0x80171DCC: jal         0x80014768
    // 0x80171DD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_4;
    // 0x80171DD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80171DD4: b           L_80171DE8
    // 0x80171DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171DE8;
    // 0x80171DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171DDC:
    // 0x80171DDC: jal         0x80171410
    // 0x80171DE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x80171DE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_80171DE4:
    // 0x80171DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171DE8:
    // 0x80171DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80171DEC: jr          $ra
    // 0x80171DF0: nop

    return;
    // 0x80171DF0: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFallProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DA08: jal         0x80146BE0
    // 0x8014DA0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014DA0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014DA10: bnel        $v0, $zero, L_8014DA24
    if (ctx->r2 != 0) {
        // 0x8014DA14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014DA24;
    }
    goto skip_0;
    // 0x8014DA14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014DA18: jal         0x8014DFA8
    // 0x8014DA1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFFCheckInterruptThrowFCommon(rdram, ctx);
        goto after_1;
    // 0x8014DA1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014DA20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014DA24:
    // 0x8014DA24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DA28: jr          $ra
    // 0x8014DA2C: nop

    return;
    // 0x8014DA2C: nop

;}
RECOMP_FUNC void mn1PModeMakeBonus1Practice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131FFC: jal         0x80009968
    // 0x80132000: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132000: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132008: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013200C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132010: sw          $v0, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r2;
    // 0x80132014: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132018: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013201C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132024: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132028: jal         0x80009DF4
    // 0x8013202C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013202C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132030: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132034: lw          $t7, 0x3294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3294);
    // 0x80132038: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8013203C: addiu       $t8, $t8, 0x1108
    ctx->r24 = ADD32(ctx->r24, 0X1108);
    // 0x80132040: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132044: jal         0x800CCFDC
    // 0x80132048: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132048: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013204C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132050: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x80132054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132058: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x8013205C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132060: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132064: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132068: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013206C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132070: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132074: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132078: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013207C: lw          $a1, 0x31B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31B8);
    // 0x80132080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132084: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132088: xori        $a1, $a1, 0x2
    ctx->r5 = ctx->r5 ^ 0X2;
    // 0x8013208C: jal         0x80131B24
    // 0x80132090: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132090: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80132094: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132098: lw          $t3, 0x3294($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3294);
    // 0x8013209C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801320A0: addiu       $t4, $t4, 0x5F28
    ctx->r12 = ADD32(ctx->r12, 0X5F28);
    // 0x801320A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801320A8: jal         0x800CCFDC
    // 0x801320AC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801320AC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x801320B0: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x801320B4: lui         $at, 0x42C2
    ctx->r1 = S32(0X42C2 << 16);
    // 0x801320B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801320BC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x801320C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801320C4: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x801320C8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801320CC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801320D0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x801320D4: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801320D8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801320DC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801320E0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801320E4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801320E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801320EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801320F0: jr          $ra
    // 0x801320F4: nop

    return;
    // 0x801320F4: nop

;}
RECOMP_FUNC void ftKirbySpecialNLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801631A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801631A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801631A8: addiu       $t6, $zero, 0x824
    ctx->r14 = ADD32(0, 0X824);
    // 0x801631AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801631B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801631B4: addiu       $a1, $zero, 0x10E
    ctx->r5 = ADD32(0, 0X10E);
    // 0x801631B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801631BC: jal         0x800E6F24
    // 0x801631C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801631C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801631C4: jal         0x80161E94
    // 0x801631C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x801631C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801631CC: jal         0x800E0830
    // 0x801631D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801631D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801631D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801631D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801631DC: jr          $ra
    // 0x801631E0: nop

    return;
    // 0x801631E0: nop

;}
RECOMP_FUNC void wpKirbyCutterMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BE8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016BE90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8016BE94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8016BE98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8016BE9C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016BEA0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016BEA4: addiu       $a1, $a1, -0x6D60
    ctx->r5 = ADD32(ctx->r5, -0X6D60);
    // 0x8016BEA8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8016BEAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8016BEB0: jal         0x801655C8
    // 0x8016BEB4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016BEB4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016BEB8: bne         $v0, $zero, L_8016BEC8
    if (ctx->r2 != 0) {
        // 0x8016BEBC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8016BEC8;
    }
    // 0x8016BEBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8016BEC0: b           L_8016BF38
    // 0x8016BEC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016BF38;
    // 0x8016BEC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BEC8:
    // 0x8016BEC8: lw          $s0, 0x84($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X84);
    // 0x8016BECC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8016BED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016BED4: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x8016BED8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8016BEDC: sw          $t7, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r15;
    // 0x8016BEE0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8016BEE4: addiu       $t0, $s0, 0xAC
    ctx->r8 = ADD32(ctx->r16, 0XAC);
    // 0x8016BEE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016BEEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016BEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016BEF4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016BEF8: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8016BEFC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8016BF00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8016BF04: lw          $a0, 0xEC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XEC);
    // 0x8016BF08: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8016BF0C: jal         0x800F3DD8
    // 0x8016BF10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_1;
    // 0x8016BF10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x8016BF14: beq         $v0, $zero, L_8016BF2C
    if (ctx->r2 == 0) {
        // 0x8016BF18: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_8016BF2C;
    }
    // 0x8016BF18: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8016BF1C: lw          $t2, 0xEC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XEC);
    // 0x8016BF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016BF24: jal         0x80167E78
    // 0x8016BF28: sw          $t2, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r10;
    wpMapSetGround(rdram, ctx);
        goto after_2;
    // 0x8016BF28: sw          $t2, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r10;
    after_2:
L_8016BF2C:
    // 0x8016BF2C: jal         0x80167FA0
    // 0x8016BF30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_3;
    // 0x8016BF30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8016BF34: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8016BF38:
    // 0x8016BF38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8016BF3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8016BF40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8016BF44: jr          $ra
    // 0x8016BF48: nop

    return;
    // 0x8016BF48: nop

;}
RECOMP_FUNC void mnVSOptionsMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132EB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132EBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132EC0: jal         0x80009968
    // 0x80132EC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132EC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132EC8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132ECC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132ED0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132ED4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132ED8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132EE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132EE4: jal         0x80009DF4
    // 0x80132EE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132EE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132EEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132EF0: lw          $t7, 0x49D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49D8);
    // 0x80132EF4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80132EF8: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x80132EFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132F00: jal         0x800CCFDC
    // 0x80132F04: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132F04: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132F08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132F0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F10: nop

    // 0x80132F14: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132F18: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132F20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132F24: jr          $ra
    // 0x80132F28: nop

    return;
    // 0x80132F28: nop

;}
RECOMP_FUNC void syAudioStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F42C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001F430: addiu       $v0, $v0, -0x2608
    ctx->r2 = ADD32(ctx->r2, -0X2608);
    // 0x8001F434: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001F438: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001F43C: jr          $ra
    // 0x8001F440: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8001F440: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mnSoundTestVoiceProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329B8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801329BC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801329C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801329C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801329C8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801329CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801329D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801329D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801329D8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801329DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801329E0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x801329E4: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x801329E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801329EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801329F0: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x801329F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801329F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801329FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132A00: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132A04: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132A08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132A0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132A10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132A14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132A1C: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x80132A20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132A24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132A28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132A2C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132A30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132A34: lw          $t8, 0x4318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4318);
    // 0x80132A38: lw          $t6, 0x4338($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4338);
    // 0x80132A3C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80132A40: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132A44: lw          $t8, 0x4328($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4328);
    // 0x80132A48: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80132A4C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80132A50: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80132A54: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x80132A58: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80132A5C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132A60: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x80132A64: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80132A68: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x80132A6C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80132A70: sra         $t6, $a0, 13
    ctx->r14 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80132A74: andi        $t8, $t6, 0x7C0
    ctx->r24 = ctx->r14 & 0X7C0;
    // 0x80132A78: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80132A7C: sra         $t6, $a0, 10
    ctx->r14 = S32(SIGNED(ctx->r4) >> 10);
    // 0x80132A80: andi        $t9, $t6, 0x3E
    ctx->r25 = ctx->r14 & 0X3E;
    // 0x80132A84: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80132A88: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x80132A8C: or          $t6, $t1, $t8
    ctx->r14 = ctx->r9 | ctx->r24;
    // 0x80132A90: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132A94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132A98: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80132A9C: lui         $t9, 0xF626
    ctx->r25 = S32(0XF626 << 16);
    // 0x80132AA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132AA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132AA8: ori         $t9, $t9, 0x264
    ctx->r25 = ctx->r25 | 0X264;
    // 0x80132AAC: ori         $t8, $t8, 0x8260
    ctx->r24 = ctx->r24 | 0X8260;
    // 0x80132AB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132AB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132AB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132ABC: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80132AC0: lui         $t7, 0xF626
    ctx->r15 = S32(0XF626 << 16);
    // 0x80132AC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132AC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132ACC: ori         $t7, $t7, 0x300
    ctx->r15 = ctx->r15 | 0X300;
    // 0x80132AD0: ori         $t9, $t9, 0x82FC
    ctx->r25 = ctx->r25 | 0X82FC;
    // 0x80132AD4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132AD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132ADC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132AE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132AE4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132AE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132AEC: jr          $ra
    // 0x80132AF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x80132AF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8002AA68_2B668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AA68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002AA6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AA70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AA74: lw          $t1, 0x1C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1C);
    // 0x8002AA78: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8002AA7C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002AA80: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8002AA84: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8002AA88: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x8002AA8C: beq         $at, $zero, L_8002AA98
    if (ctx->r1 == 0) {
        // 0x8002AA90: addu        $v1, $v0, $t1
        ctx->r3 = ADD32(ctx->r2, ctx->r9);
            goto L_8002AA98;
    }
    // 0x8002AA90: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x8002AA94: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
L_8002AA98:
    // 0x8002AA98: addiu       $a2, $a1, 0x170
    ctx->r6 = ADD32(ctx->r5, 0X170);
    // 0x8002AA9C: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x8002AAA0: beq         $at, $zero, L_8002AB5C
    if (ctx->r1 == 0) {
        // 0x8002AAA4: addiu       $s0, $a3, 0x8
        ctx->r16 = ADD32(ctx->r7, 0X8);
            goto L_8002AB5C;
    }
    // 0x8002AAA4: addiu       $s0, $a3, 0x8
    ctx->r16 = ADD32(ctx->r7, 0X8);
    // 0x8002AAA8: subu        $t2, $v1, $a1
    ctx->r10 = SUB32(ctx->r3, ctx->r5);
    // 0x8002AAAC: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002AAB0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8002AAB4: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x8002AAB8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8002AABC: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x8002AAC0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002AAC4: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8002AAC8: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x8002AACC: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8002AAD0: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x8002AAD4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8002AAD8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8002AADC: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8002AAE0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8002AAE4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8002AAE8: addiu       $s0, $a3, 0x8
    ctx->r16 = ADD32(ctx->r7, 0X8);
    // 0x8002AAEC: jal         0x80032150
    // 0x8002AAF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8002AAF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8002AAF4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8002AAF8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8002AAFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002AB00: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002AB04: subu        $t5, $a2, $v1
    ctx->r13 = SUB32(ctx->r6, ctx->r3);
    // 0x8002AB08: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8002AB0C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002AB10: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002AB14: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8002AB18: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8002AB1C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8002AB20: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x8002AB24: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x8002AB28: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8002AB2C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8002AB30: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8002AB34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002AB38: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x8002AB3C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8002AB40: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8002AB44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002AB48: jal         0x80032150
    // 0x8002AB4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8002AB4C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x8002AB50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AB54: b           L_8002AB80
    // 0x8002AB58: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
        goto L_8002AB80;
    // 0x8002AB58: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_8002AB5C:
    // 0x8002AB5C: andi        $t8, $t3, 0xFFF
    ctx->r24 = ctx->r11 & 0XFFF;
    // 0x8002AB60: lui         $at, 0x617
    ctx->r1 = S32(0X617 << 16);
    // 0x8002AB64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002AB68: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8002AB6C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002AB70: jal         0x80032150
    // 0x8002AB74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8002AB74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8002AB78: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8002AB7C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002AB80:
    // 0x8002AB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB84: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002AB88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002AB8C: jr          $ra
    // 0x8002AB90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8002AB90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnVSResultsSetAutoHandicaps(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138548: addiu       $t5, $zero, 0x74
    ctx->r13 = ADD32(0, 0X74);
    // 0x8013854C: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138550: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80138554: addiu       $t4, $t4, 0x4D08
    ctx->r12 = ADD32(ctx->r12, 0X4D08);
    // 0x80138558: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013855C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80138560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138564: mflo        $t6
    ctx->r14 = lo;
    // 0x80138568: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x8013856C: lbu         $a2, 0x21($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X21);
    // 0x80138570: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138574: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80138578: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8013857C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80138580: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x80138584: mflo        $t7
    ctx->r15 = lo;
    // 0x80138588: addu        $a3, $t4, $t7
    ctx->r7 = ADD32(ctx->r12, ctx->r15);
    // 0x8013858C: lbu         $t2, 0x21($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X21);
    // 0x80138590: bne         $a2, $t3, L_801385A0
    if (ctx->r6 != ctx->r11) {
        // 0x80138594: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_801385A0;
    }
    // 0x80138594: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80138598: beql        $v1, $a1, L_801386B0
    if (ctx->r3 == ctx->r5) {
        // 0x8013859C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801386B0;
    }
    goto skip_0;
    // 0x8013859C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_801385A0:
    // 0x801385A0: bne         $at, $zero, L_801385C8
    if (ctx->r1 != 0) {
        // 0x801385A4: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_801385C8;
    }
    // 0x801385A4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801385A8: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x801385AC: beq         $at, $zero, L_801385C8
    if (ctx->r1 == 0) {
        // 0x801385B0: addiu       $t8, $a2, -0x1
        ctx->r24 = ADD32(ctx->r6, -0X1);
            goto L_801385C8;
    }
    // 0x801385B0: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x801385B4: sb          $t8, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r24;
    // 0x801385B8: lbu         $t9, 0x21($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X21);
    // 0x801385BC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801385C0: b           L_801386AC
    // 0x801385C4: sb          $t6, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r14;
        goto L_801386AC;
    // 0x801385C4: sb          $t6, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r14;
L_801385C8:
    // 0x801385C8: bne         $v0, $t3, L_801385E0
    if (ctx->r2 != ctx->r11) {
        // 0x801385CC: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_801385E0;
    }
    // 0x801385CC: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x801385D0: beq         $at, $zero, L_801385E0
    if (ctx->r1 == 0) {
        // 0x801385D4: addiu       $t7, $t2, 0x2
        ctx->r15 = ADD32(ctx->r10, 0X2);
            goto L_801385E0;
    }
    // 0x801385D4: addiu       $t7, $t2, 0x2
    ctx->r15 = ADD32(ctx->r10, 0X2);
    // 0x801385D8: b           L_801386AC
    // 0x801385DC: sb          $t7, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r15;
        goto L_801386AC;
    // 0x801385DC: sb          $t7, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r15;
L_801385E0:
    // 0x801385E0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801385E4: bne         $at, $zero, L_801385FC
    if (ctx->r1 != 0) {
        // 0x801385E8: nop
    
            goto L_801385FC;
    }
    // 0x801385E8: nop

    // 0x801385EC: bne         $v1, $a1, L_801385FC
    if (ctx->r3 != ctx->r5) {
        // 0x801385F0: addiu       $t8, $t1, -0x2
        ctx->r24 = ADD32(ctx->r9, -0X2);
            goto L_801385FC;
    }
    // 0x801385F0: addiu       $t8, $t1, -0x2
    ctx->r24 = ADD32(ctx->r9, -0X2);
    // 0x801385F4: b           L_801386AC
    // 0x801385F8: sb          $t8, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r24;
        goto L_801386AC;
    // 0x801385F8: sb          $t8, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r24;
L_801385FC:
    // 0x801385FC: bne         $v0, $t3, L_80138654
    if (ctx->r2 != ctx->r11) {
        // 0x80138600: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80138654;
    }
    // 0x80138600: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80138604: bnel        $v1, $at, L_80138658
    if (ctx->r3 != ctx->r1) {
        // 0x80138608: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80138658;
    }
    goto skip_1;
    // 0x80138608: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8013860C: jal         0x80137E34
    // 0x80138610: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    mnVSResultsGetBestManExcept(rdram, ctx);
        goto after_0;
    // 0x80138610: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80138614: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80138618: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x8013861C: addiu       $t4, $t4, 0x4D08
    ctx->r12 = ADD32(ctx->r12, 0X4D08);
    // 0x80138620: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80138624: beq         $v0, $at, L_801386AC
    if (ctx->r2 == ctx->r1) {
        // 0x80138628: addiu       $t5, $zero, 0x74
        ctx->r13 = ADD32(0, 0X74);
            goto L_801386AC;
    }
    // 0x80138628: addiu       $t5, $zero, 0x74
    ctx->r13 = ADD32(0, 0X74);
    // 0x8013862C: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138630: mflo        $t9
    ctx->r25 = lo;
    // 0x80138634: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x80138638: lbu         $t6, 0x21($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X21);
    // 0x8013863C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80138640: sb          $t7, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r15;
    // 0x80138644: lbu         $t8, 0x21($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X21);
    // 0x80138648: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8013864C: b           L_801386AC
    // 0x80138650: sb          $t9, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r25;
        goto L_801386AC;
    // 0x80138650: sb          $t9, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r25;
L_80138654:
    // 0x80138654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80138658:
    // 0x80138658: bnel        $v0, $at, L_801386B0
    if (ctx->r2 != ctx->r1) {
        // 0x8013865C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801386B0;
    }
    goto skip_2;
    // 0x8013865C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80138660: bnel        $v1, $a1, L_801386B0
    if (ctx->r3 != ctx->r5) {
        // 0x80138664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801386B0;
    }
    goto skip_3;
    // 0x80138664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80138668: jal         0x80137E34
    // 0x8013866C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    mnVSResultsGetBestManExcept(rdram, ctx);
        goto after_1;
    // 0x8013866C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_1:
    // 0x80138670: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80138674: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x80138678: addiu       $t4, $t4, 0x4D08
    ctx->r12 = ADD32(ctx->r12, 0X4D08);
    // 0x8013867C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80138680: beq         $v0, $at, L_801386AC
    if (ctx->r2 == ctx->r1) {
        // 0x80138684: addiu       $t5, $zero, 0x74
        ctx->r13 = ADD32(0, 0X74);
            goto L_801386AC;
    }
    // 0x80138684: addiu       $t5, $zero, 0x74
    ctx->r13 = ADD32(0, 0X74);
    // 0x80138688: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013868C: lbu         $t6, 0x21($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X21);
    // 0x80138690: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80138694: sb          $t7, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r15;
    // 0x80138698: mflo        $t8
    ctx->r24 = lo;
    // 0x8013869C: addu        $v1, $t4, $t8
    ctx->r3 = ADD32(ctx->r12, ctx->r24);
    // 0x801386A0: lbu         $t9, 0x21($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X21);
    // 0x801386A4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x801386A8: sb          $t6, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r14;
L_801386AC:
    // 0x801386AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801386B0:
    // 0x801386B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801386B4: jr          $ra
    // 0x801386B8: nop

    return;
    // 0x801386B8: nop

;}

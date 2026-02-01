#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnBackupClearInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324D4: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    // 0x801324D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324DC: sw          $zero, 0x30C0($at)
    MEM_W(0X30C0, ctx->r1) = 0;
    // 0x801324E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801324E8: sw          $zero, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = 0;
    // 0x801324EC: addiu       $v0, $v0, 0x30E0
    ctx->r2 = ADD32(ctx->r2, 0X30E0);
    // 0x801324F0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801324F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324F8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801324FC: sw          $t6, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r14;
    // 0x80132500: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132504: sw          $zero, 0x30E8($at)
    MEM_W(0X30E8, ctx->r1) = 0;
    // 0x80132508: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8013250C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132510: addiu       $t8, $t7, 0x4650
    ctx->r24 = ADD32(ctx->r15, 0X4650);
    // 0x80132514: jr          $ra
    // 0x80132518: sw          $t8, 0x30EC($at)
    MEM_W(0X30EC, ctx->r1) = ctx->r24;
    return;
    // 0x80132518: sw          $t8, 0x30EC($at)
    MEM_W(0X30EC, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void scAutoDemoResetFocusPlayerAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D528: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018D52C: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018D530: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018D534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D53C: lw          $t7, 0xEC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XEC);
    // 0x8018D540: jal         0x8010CF20
    // 0x8018D544: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    gmCameraSetStatusDefault(rdram, ctx);
        goto after_0;
    // 0x8018D544: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8018D548: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018D54C: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018D550: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018D554: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D558: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8018D55C: lw          $t0, 0x1D4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1D4);
    // 0x8018D560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D564: lw          $t1, 0x84($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X84);
    // 0x8018D568: sb          $t8, 0x13($t1)
    MEM_B(0X13, ctx->r9) = ctx->r24;
    // 0x8018D56C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8018D570: lw          $t2, 0x1D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X1D4);
    // 0x8018D574: lw          $t4, 0x160($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X160);
    // 0x8018D578: lw          $t3, 0x84($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X84);
    // 0x8018D57C: lw          $t5, 0x84($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X84);
    // 0x8018D580: lbu         $v0, 0x13($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X13);
    // 0x8018D584: sb          $v0, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r2;
    // 0x8018D588: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018D58C: sb          $v0, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r2;
    // 0x8018D590: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8018D594: lw          $t9, 0x78($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X78);
    // 0x8018D598: lw          $t0, 0x84($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X84);
    // 0x8018D59C: jal         0x800E9198
    // 0x8018D5A0: sb          $v0, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r2;
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_1;
    // 0x8018D5A0: sb          $v0, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r2;
    after_1:
    // 0x8018D5A4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D5A8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8018D5AC: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018D5B0: lw          $t2, 0x84($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X84);
    // 0x8018D5B4: sb          $t8, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r24;
    // 0x8018D5B8: lw          $t3, -0x1B18($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X1B18);
    // 0x8018D5BC: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x8018D5C0: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x8018D5C4: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D5C8: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x8018D5CC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8018D5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D5D8: jr          $ra
    // 0x8018D5DC: nop

    return;
    // 0x8018D5DC: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNDestroyChargeShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156E68: lw          $a1, 0xB20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XB20);
    // 0x80156E6C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80156E70: beq         $a1, $zero, L_80156E88
    if (ctx->r5 == 0) {
        // 0x80156E74: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80156E88;
    }
    // 0x80156E74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80156E78: jal         0x8016800C
    // 0x80156E7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x80156E7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80156E80: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80156E84: sw          $zero, 0xB20($a2)
    MEM_W(0XB20, ctx->r6) = 0;
L_80156E88:
    // 0x80156E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156E90: jr          $ra
    // 0x80156E94: nop

    return;
    // 0x80156E94: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNCatchSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F4B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F4B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F4B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F4BC: jal         0x800DEE98
    // 0x8015F4C0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015F4C0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F4C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015F4C8: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015F4CC: addiu       $a1, $zero, 0x12A
    ctx->r5 = ADD32(0, 0X12A);
    // 0x8015F4D0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F4D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F4D8: jal         0x800E6F24
    // 0x8015F4DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F4DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F4E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F4E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F4E8: jr          $ra
    // 0x8015F4EC: nop

    return;
    // 0x8015F4EC: nop

;}
RECOMP_FUNC void mvOpeningYoshiMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA90: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA98: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA9C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DAA0: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DAA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DAA8: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DAAC: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DAB0:
    // 0x8018DAB0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAB4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DAB8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DABC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DAC0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DAC4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DAC8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DACC: bne         $t6, $t0, L_8018DAB0
    if (ctx->r14 != ctx->r8) {
        // 0x8018DAD0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DAB0;
    }
    // 0x8018DAD0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAD4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAD8: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x8018DADC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8018DAE0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAE4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DAE8: jal         0x800EC0EC
    // 0x8018DAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAF4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAF8: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x8018DAFC: lw          $t2, -0x1DC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1DC4);
    // 0x8018DB00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DB04: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DB08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB0C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB10: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB14: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DB18: jal         0x800D7F3C
    // 0x8018DB1C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DB1C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DB20: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DB24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB28: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DB2C: jal         0x803905CC
    // 0x8018DB30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DB30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB38: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB3C: jal         0x8000A0D0
    // 0x8018DB40: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB40: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB44: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB48: addiu       $a1, $a1, -0x2640
    ctx->r5 = ADD32(ctx->r5, -0X2640);
    // 0x8018DB4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB54: jal         0x80008188
    // 0x8018DB58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB64: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB68: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB6C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB70: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB74: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB78: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB84: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB88: jr          $ra
    // 0x8018DB8C: nop

    return;
    // 0x8018DB8C: nop

;}
RECOMP_FUNC void syTaskmanResetGraphicsHeap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049B0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800049B4: lw          $t6, 0x6630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6630);
    // 0x800049B8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800049BC: addiu       $t8, $t8, 0x6648
    ctx->r24 = ADD32(ctx->r24, 0X6648);
    // 0x800049C0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800049C4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800049C8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800049CC: addiu       $a0, $a0, 0x65D8
    ctx->r4 = ADD32(ctx->r4, 0X65D8);
    // 0x800049D0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800049D4: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800049D8: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800049DC: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800049E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800049EC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800049F0: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800049F4: jal         0x80006CE0
    // 0x800049F8: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    syMallocReset(rdram, ctx);
        goto after_0;
    // 0x800049F8: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    after_0:
    // 0x800049FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004A04: jr          $ra
    // 0x80004A08: nop

    return;
    // 0x80004A08: nop

;}
RECOMP_FUNC void wpLinkBoomerangGetDistUpdateAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D0E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8016D0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D0EC: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8016D0F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016D0F4: lw          $a2, 0x29C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X29C);
    // 0x8016D0F8: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8016D0FC: beql        $a2, $zero, L_8016D30C
    if (ctx->r6 == 0) {
        // 0x8016D100: mov.s       $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
            goto L_8016D30C;
    }
    goto skip_0;
    // 0x8016D100: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    skip_0:
    // 0x8016D104: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x8016D108: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8016D10C: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x8016D110: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8016D114: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8016D118: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8016D11C: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8016D120: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016D124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016D128: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8016D12C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8016D130: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8016D134: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8016D138: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016D13C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8016D140: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8016D144: jal         0x80033510
    // 0x8016D148: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016D148: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8016D14C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8016D150: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016D154: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016D158: lbu         $v0, 0x2A2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2A2);
    // 0x8016D15C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8016D160: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8016D164: beql        $t6, $zero, L_8016D19C
    if (ctx->r14 == 0) {
        // 0x8016D168: andi        $t8, $v0, 0x10
        ctx->r24 = ctx->r2 & 0X10;
            goto L_8016D19C;
    }
    goto skip_1;
    // 0x8016D168: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    skip_1:
    // 0x8016D16C: lbu         $v1, 0x2A0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2A0);
    // 0x8016D170: blez        $v1, L_8016D188
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8016D174: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8016D188;
    }
    // 0x8016D174: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8016D178: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8016D17C: sb          $t7, 0x2A0($a1)
    MEM_B(0X2A0, ctx->r5) = ctx->r15;
    // 0x8016D180: b           L_8016D198
    // 0x8016D184: lbu         $v0, 0x2A2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2A2);
        goto L_8016D198;
    // 0x8016D184: lbu         $v0, 0x2A2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2A2);
L_8016D188:
    // 0x8016D188: bnel        $a0, $zero, L_8016D19C
    if (ctx->r4 != 0) {
        // 0x8016D18C: andi        $t8, $v0, 0x10
        ctx->r24 = ctx->r2 & 0X10;
            goto L_8016D19C;
    }
    goto skip_2;
    // 0x8016D18C: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
    skip_2:
    // 0x8016D190: b           L_8016D30C
    // 0x8016D194: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8016D30C;
    // 0x8016D194: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8016D198:
    // 0x8016D198: andi        $t8, $v0, 0x10
    ctx->r24 = ctx->r2 & 0X10;
L_8016D19C:
    // 0x8016D19C: beq         $t8, $zero, L_8016D1EC
    if (ctx->r24 == 0) {
        // 0x8016D1A0: lwc1        $f12, 0x28($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8016D1EC;
    }
    // 0x8016D1A0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8016D1A4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8016D1A8: nop

    // 0x8016D1AC: bc1fl       L_8016D1C8
    if (!c1cs) {
        // 0x8016D1B0: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_8016D1C8;
    }
    goto skip_3;
    // 0x8016D1B0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_3:
    // 0x8016D1B4: lw          $t9, 0x18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X18);
    // 0x8016D1B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016D1BC: beq         $t9, $at, L_8016D1E4
    if (ctx->r25 == ctx->r1) {
        // 0x8016D1C0: nop
    
            goto L_8016D1E4;
    }
    // 0x8016D1C0: nop

    // 0x8016D1C4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_8016D1C8:
    // 0x8016D1C8: nop

    // 0x8016D1CC: bc1fl       L_8016D1F0
    if (!c1cs) {
        // 0x8016D1D0: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8016D1F0;
    }
    goto skip_4;
    // 0x8016D1D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_4:
    // 0x8016D1D4: lw          $t0, 0x18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X18);
    // 0x8016D1D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016D1DC: bnel        $t0, $at, L_8016D1F0
    if (ctx->r8 != ctx->r1) {
        // 0x8016D1E0: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8016D1F0;
    }
    goto skip_5;
    // 0x8016D1E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_5:
L_8016D1E4:
    // 0x8016D1E4: b           L_8016D30C
    // 0x8016D1E8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8016D30C;
    // 0x8016D1E8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8016D1EC:
    // 0x8016D1EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_8016D1F0:
    // 0x8016D1F0: jal         0x8001863C
    // 0x8016D1F4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8016D1F4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8016D1F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D1FC: lwc1        $f12, -0x3450($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3450);
    // 0x8016D200: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8016D204: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016D208: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8016D20C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8016D210: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D214: bc1f        L_8016D22C
    if (!c1cs) {
        // 0x8016D218: nop
    
            goto L_8016D22C;
    }
    // 0x8016D218: nop

    // 0x8016D21C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D220: lwc1        $f18, -0x344C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X344C);
    // 0x8016D224: b           L_8016D24C
    // 0x8016D228: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
        goto L_8016D24C;
    // 0x8016D228: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
L_8016D22C:
    // 0x8016D22C: lwc1        $f4, -0x3448($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3448);
    // 0x8016D230: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D234: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8016D238: nop

    // 0x8016D23C: bc1fl       L_8016D250
    if (!c1cs) {
        // 0x8016D240: lwc1        $f14, 0x2A4($a1)
        ctx->f14.u32l = MEM_W(ctx->r5, 0X2A4);
            goto L_8016D250;
    }
    goto skip_6;
    // 0x8016D240: lwc1        $f14, 0x2A4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X2A4);
    skip_6:
    // 0x8016D244: lwc1        $f18, -0x3444($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3444);
    // 0x8016D248: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
L_8016D24C:
    // 0x8016D24C: lwc1        $f14, 0x2A4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X2A4);
L_8016D250:
    // 0x8016D250: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D254: lwc1        $f18, -0x3440($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x8016D258: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8016D25C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D260: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8016D264: nop

    // 0x8016D268: bc1f        L_8016D278
    if (!c1cs) {
        // 0x8016D26C: nop
    
            goto L_8016D278;
    }
    // 0x8016D26C: nop

    // 0x8016D270: b           L_8016D290
    // 0x8016D274: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_8016D290;
    // 0x8016D274: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8016D278:
    // 0x8016D278: lwc1        $f6, -0x343C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X343C);
    // 0x8016D27C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8016D280: nop

    // 0x8016D284: bc1fl       L_8016D294
    if (!c1cs) {
        // 0x8016D288: lwc1        $f0, 0x2A8($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X2A8);
            goto L_8016D294;
    }
    goto skip_7;
    // 0x8016D288: lwc1        $f0, 0x2A8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2A8);
    skip_7:
    // 0x8016D28C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
L_8016D290:
    // 0x8016D290: lwc1        $f0, 0x2A8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2A8);
L_8016D294:
    // 0x8016D294: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8016D298: nop

    // 0x8016D29C: bc1fl       L_8016D2B0
    if (!c1cs) {
        // 0x8016D2A0: neg.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
            goto L_8016D2B0;
    }
    goto skip_8;
    // 0x8016D2A0: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    skip_8:
    // 0x8016D2A4: b           L_8016D2C4
    // 0x8016D2A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8016D2C4;
    // 0x8016D2A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8016D2AC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8016D2B0:
    // 0x8016D2B0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8016D2B4: nop

    // 0x8016D2B8: bc1fl       L_8016D2C8
    if (!c1cs) {
        // 0x8016D2BC: add.s       $f8, $f14, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
            goto L_8016D2C8;
    }
    goto skip_9;
    // 0x8016D2BC: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    skip_9:
    // 0x8016D2C0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8016D2C4:
    // 0x8016D2C4: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
L_8016D2C8:
    // 0x8016D2C8: addiu       $a0, $a1, 0x2A4
    ctx->r4 = ADD32(ctx->r5, 0X2A4);
    // 0x8016D2CC: swc1        $f8, 0x2A4($a1)
    MEM_W(0X2A4, ctx->r5) = ctx->f8.u32l;
    // 0x8016D2D0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8016D2D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8016D2D8: jal         0x8016CC50
    // 0x8016D2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpLinkBoomerangClampAngle360(rdram, ctx);
        goto after_2;
    // 0x8016D2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8016D2E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8016D2E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016D2E8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016D2EC: lbu         $t1, 0x2A2($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X2A2);
    // 0x8016D2F0: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8016D2F4: beql        $t2, $zero, L_8016D30C
    if (ctx->r10 == 0) {
        // 0x8016D2F8: mov.s       $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
            goto L_8016D30C;
    }
    goto skip_10;
    // 0x8016D2F8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    skip_10:
    // 0x8016D2FC: jal         0x8016CFFC
    // 0x8016D300: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    wpLinkBoomerangClampAngleForward(rdram, ctx);
        goto after_3;
    // 0x8016D300: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8016D304: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016D308: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8016D30C:
    // 0x8016D30C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016D310: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8016D314: jr          $ra
    // 0x8016D318: nop

    return;
    // 0x8016D318: nop

;}
RECOMP_FUNC void wpProcessProcWeaponMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801662BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801662C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801662C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801662C8: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801662CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801662D0: lw          $t6, 0x260($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X260);
    // 0x801662D4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x801662D8: bltzl       $t8, L_80166584
    if (SIGNED(ctx->r24) < 0) {
        // 0x801662DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80166584;
    }
    goto skip_0;
    // 0x801662DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801662E0: jal         0x8000DF34
    // 0x801662E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x801662E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x801662E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801662EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801662F0: lw          $v0, 0x278($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X278);
    // 0x801662F4: beql        $v0, $zero, L_80166320
    if (ctx->r2 == 0) {
        // 0x801662F8: lw          $v1, 0x74($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X74);
            goto L_80166320;
    }
    goto skip_1;
    // 0x801662F8: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    skip_1:
    // 0x801662FC: jalr        $v0
    // 0x80166300: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80166300: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80166304: beq         $v0, $zero, L_8016631C
    if (ctx->r2 == 0) {
        // 0x80166308: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016631C;
    }
    // 0x80166308: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016630C: jal         0x8016800C
    // 0x80166310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_2;
    // 0x80166310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80166314: b           L_80166584
    // 0x80166318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80166584;
    // 0x80166318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016631C:
    // 0x8016631C: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
L_80166320:
    // 0x80166320: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80166324: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x80166328: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8016632C: sw          $t0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r8;
    // 0x80166330: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80166334: sw          $t9, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r25;
    // 0x80166338: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8016633C: sw          $t0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r8;
    // 0x80166340: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80166344: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80166348: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016634C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80166350: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80166354: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80166358: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016635C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80166360: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80166364: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x80166368: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016636C: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x80166370: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80166374: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80166378: lw          $t1, 0xFC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XFC);
    // 0x8016637C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80166380: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x80166384: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
    // 0x80166388: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8016638C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80166390: swc1        $f8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f8.u32l;
    // 0x80166394: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80166398: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8016639C: bne         $t1, $zero, L_80166424
    if (ctx->r9 != 0) {
        // 0x801663A0: swc1        $f18, 0x48($a2)
        MEM_W(0X48, ctx->r6) = ctx->f18.u32l;
            goto L_80166424;
    }
    // 0x801663A0: swc1        $f18, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f18.u32l;
    // 0x801663A4: lw          $a0, 0xA0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XA0);
    // 0x801663A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801663AC: beq         $a0, $at, L_80166424
    if (ctx->r4 == ctx->r1) {
        // 0x801663B0: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80166424;
    }
    // 0x801663B0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x801663B4: beql        $a0, $at, L_80166428
    if (ctx->r4 == ctx->r1) {
        // 0x801663B8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80166428;
    }
    goto skip_2;
    // 0x801663B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x801663BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801663C0: jal         0x800FC67C
    // 0x801663C4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_3;
    // 0x801663C4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x801663C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801663CC: beq         $v0, $zero, L_80166424
    if (ctx->r2 == 0) {
        // 0x801663D0: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80166424;
    }
    // 0x801663D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801663D4: lw          $a0, 0xA0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XA0);
    // 0x801663D8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x801663DC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801663E0: jal         0x800FA7B8
    // 0x801663E4: addiu       $a1, $a2, 0x4C
    ctx->r5 = ADD32(ctx->r6, 0X4C);
    mpCollisionGetSpeedLineID(rdram, ctx);
        goto after_4;
    // 0x801663E4: addiu       $a1, $a2, 0x4C
    ctx->r5 = ADD32(ctx->r6, 0X4C);
    after_4:
    // 0x801663E8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801663EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801663F0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801663F4: lwc1        $f6, 0x4C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4C);
    // 0x801663F8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801663FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80166400: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80166404: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80166408: lwc1        $f16, 0x50($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8016640C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80166410: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80166414: lwc1        $f6, 0x54($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X54);
    // 0x80166418: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016641C: b           L_80166438
    // 0x80166420: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_80166438;
    // 0x80166420: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
L_80166424:
    // 0x80166424: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80166428:
    // 0x80166428: nop

    // 0x8016642C: swc1        $f0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f0.u32l;
    // 0x80166430: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    // 0x80166434: swc1        $f0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f0.u32l;
L_80166438:
    // 0x80166438: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8016643C: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x80166440: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80166444: lh          $t2, 0x76($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X76);
    // 0x80166448: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8016644C: nop

    // 0x80166450: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80166454: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80166458: nop

    // 0x8016645C: bc1tl       L_80166500
    if (c1cs) {
        // 0x80166460: lw          $v0, 0x298($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X298);
            goto L_80166500;
    }
    goto skip_3;
    // 0x80166460: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
    skip_3:
    // 0x80166464: lh          $t3, 0x78($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X78);
    // 0x80166468: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8016646C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80166470: nop

    // 0x80166474: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80166478: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8016647C: nop

    // 0x80166480: bc1tl       L_80166500
    if (c1cs) {
        // 0x80166484: lw          $v0, 0x298($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X298);
            goto L_80166500;
    }
    goto skip_4;
    // 0x80166484: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
    skip_4:
    // 0x80166488: lh          $t4, 0x7A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X7A);
    // 0x8016648C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80166490: nop

    // 0x80166494: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80166498: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8016649C: nop

    // 0x801664A0: bc1tl       L_80166500
    if (c1cs) {
        // 0x801664A4: lw          $v0, 0x298($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X298);
            goto L_80166500;
    }
    goto skip_5;
    // 0x801664A4: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
    skip_5:
    // 0x801664A8: lh          $t5, 0x74($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X74);
    // 0x801664AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801664B0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x801664B4: nop

    // 0x801664B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801664BC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x801664C0: nop

    // 0x801664C4: bc1tl       L_80166500
    if (c1cs) {
        // 0x801664C8: lw          $v0, 0x298($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X298);
            goto L_80166500;
    }
    goto skip_6;
    // 0x801664C8: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
    skip_6:
    // 0x801664CC: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801664D0: lwc1        $f18, -0x35D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X35D0);
    // 0x801664D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801664D8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801664DC: nop

    // 0x801664E0: bc1tl       L_80166500
    if (c1cs) {
        // 0x801664E4: lw          $v0, 0x298($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X298);
            goto L_80166500;
    }
    goto skip_7;
    // 0x801664E4: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
    skip_7:
    // 0x801664E8: lwc1        $f4, -0x35CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X35CC);
    // 0x801664EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801664F0: nop

    // 0x801664F4: bc1fl       L_80166530
    if (!c1cs) {
        // 0x801664F8: lw          $v0, 0x27C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X27C);
            goto L_80166530;
    }
    goto skip_8;
    // 0x801664F8: lw          $v0, 0x27C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X27C);
    skip_8:
    // 0x801664FC: lw          $v0, 0x298($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X298);
L_80166500:
    // 0x80166500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80166504: beq         $v0, $zero, L_8016651C
    if (ctx->r2 == 0) {
        // 0x80166508: nop
    
            goto L_8016651C;
    }
    // 0x80166508: nop

    // 0x8016650C: jalr        $v0
    // 0x80166510: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80166510: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_5:
    // 0x80166514: beq         $v0, $zero, L_8016652C
    if (ctx->r2 == 0) {
        // 0x80166518: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_8016652C;
    }
    // 0x80166518: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8016651C:
    // 0x8016651C: jal         0x8016800C
    // 0x80166520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_6;
    // 0x80166520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80166524: b           L_80166584
    // 0x80166528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80166584;
    // 0x80166528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016652C:
    // 0x8016652C: lw          $v0, 0x27C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X27C);
L_80166530:
    // 0x80166530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80166534: beq         $v0, $zero, L_80166570
    if (ctx->r2 == 0) {
        // 0x80166538: nop
    
            goto L_80166570;
    }
    // 0x80166538: nop

    // 0x8016653C: lhu         $t6, 0x82($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X82);
    // 0x80166540: sh          $zero, 0x82($a2)
    MEM_H(0X82, ctx->r6) = 0;
    // 0x80166544: sw          $zero, 0x90($a2)
    MEM_W(0X90, ctx->r6) = 0;
    // 0x80166548: sh          $zero, 0x86($a2)
    MEM_H(0X86, ctx->r6) = 0;
    // 0x8016654C: sh          $zero, 0x84($a2)
    MEM_H(0X84, ctx->r6) = 0;
    // 0x80166550: jalr        $v0
    // 0x80166554: sh          $t6, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x80166554: sh          $t6, 0x80($a2)
    MEM_H(0X80, ctx->r6) = ctx->r14;
    after_7:
    // 0x80166558: beq         $v0, $zero, L_80166570
    if (ctx->r2 == 0) {
        // 0x8016655C: nop
    
            goto L_80166570;
    }
    // 0x8016655C: nop

    // 0x80166560: jal         0x8016800C
    // 0x80166564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_8;
    // 0x80166564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80166568: b           L_80166584
    // 0x8016656C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80166584;
    // 0x8016656C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80166570:
    // 0x80166570: jal         0x80165F60
    // 0x80166574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_9;
    // 0x80166574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80166578: jal         0x801661E0
    // 0x8016657C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpProcessUpdateAttackRecords(rdram, ctx);
        goto after_10;
    // 0x8016657C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80166580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80166584:
    // 0x80166584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80166588: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016658C: jr          $ra
    // 0x80166590: nop

    return;
    // 0x80166590: nop

;}
RECOMP_FUNC void stringCopyCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377044: beq         $a0, $zero, L_80377094
    if (ctx->r4 == 0) {
        // 0x80377048: nop
    
            goto L_80377094;
    }
    // 0x80377048: nop

    // 0x8037704C: beq         $a1, $zero, L_80377094
    if (ctx->r5 == 0) {
        // 0x80377050: nop
    
            goto L_80377094;
    }
    // 0x80377050: nop

    // 0x80377054: beql        $a2, $zero, L_80377094
    if (ctx->r6 == 0) {
        // 0x80377058: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80377094;
    }
    goto skip_0;
    // 0x80377058: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    skip_0:
    // 0x8037705C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80377060: beq         $t6, $zero, L_80377090
    if (ctx->r14 == 0) {
        // 0x80377064: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80377090;
    }
    // 0x80377064: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80377068:
    // 0x80377068: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8037706C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80377070: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80377074: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80377078: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037707C: beq         $a2, $zero, L_80377090
    if (ctx->r6 == 0) {
        // 0x80377080: sb          $t7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r15;
            goto L_80377090;
    }
    // 0x80377080: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80377084: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80377088: bnel        $t8, $zero, L_80377068
    if (ctx->r24 != 0) {
        // 0x8037708C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80377068;
    }
    goto skip_1;
    // 0x8037708C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    skip_1:
L_80377090:
    // 0x80377090: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80377094:
    // 0x80377094: jr          $ra
    // 0x80377098: nop

    return;
    // 0x80377098: nop

;}
RECOMP_FUNC void func_80000B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B54: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000B58: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x80000B5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80000B60: beq         $v0, $zero, L_80000B80
    if (ctx->r2 == 0) {
        // 0x80000B64: nop
    
            goto L_80000B80;
    }
    // 0x80000B64: nop

    // 0x80000B68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000B6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80000B70: bne         $v1, $t6, L_80000B80
    if (ctx->r3 != ctx->r14) {
        // 0x80000B74: nop
    
            goto L_80000B80;
    }
    // 0x80000B74: nop

    // 0x80000B78: jr          $ra
    // 0x80000B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80000B80:
    // 0x80000B80: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000B84: lw          $v0, 0x4ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ED4);
    // 0x80000B88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80000B8C: beq         $v0, $zero, L_80000BB4
    if (ctx->r2 == 0) {
        // 0x80000B90: nop
    
            goto L_80000BB4;
    }
    // 0x80000B90: nop

    // 0x80000B94: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_80000B98:
    // 0x80000B98: bnel        $v1, $t7, L_80000BAC
    if (ctx->r3 != ctx->r15) {
        // 0x80000B9C: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80000BAC;
    }
    goto skip_0;
    // 0x80000B9C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x80000BA0: jr          $ra
    // 0x80000BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000BA8: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80000BAC:
    // 0x80000BAC: bnel        $v0, $zero, L_80000B98
    if (ctx->r2 != 0) {
        // 0x80000BB0: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_80000B98;
    }
    goto skip_1;
    // 0x80000BB0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_80000BB4:
    // 0x80000BB4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000BB8: lw          $v0, 0x4EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EC4);
    // 0x80000BBC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80000BC0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80000BC4: beq         $v0, $zero, L_80000BEC
    if (ctx->r2 == 0) {
        // 0x80000BC8: nop
    
            goto L_80000BEC;
    }
    // 0x80000BC8: nop

    // 0x80000BCC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_80000BD0:
    // 0x80000BD0: bnel        $v1, $t8, L_80000BE4
    if (ctx->r3 != ctx->r24) {
        // 0x80000BD4: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80000BE4;
    }
    goto skip_2;
    // 0x80000BD4: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_2:
    // 0x80000BD8: jr          $ra
    // 0x80000BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000BDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000BE0: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80000BE4:
    // 0x80000BE4: bnel        $v0, $zero, L_80000BD0
    if (ctx->r2 != 0) {
        // 0x80000BE8: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_80000BD0;
    }
    goto skip_3;
    // 0x80000BE8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_3:
L_80000BEC:
    // 0x80000BEC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000BF0: lw          $v0, 0x4EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE4);
    // 0x80000BF4: beq         $v0, $zero, L_80000C10
    if (ctx->r2 == 0) {
        // 0x80000BF8: nop
    
            goto L_80000C10;
    }
    // 0x80000BF8: nop

    // 0x80000BFC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000C00: bne         $v1, $t9, L_80000C10
    if (ctx->r3 != ctx->r25) {
        // 0x80000C04: nop
    
            goto L_80000C10;
    }
    // 0x80000C04: nop

    // 0x80000C08: jr          $ra
    // 0x80000C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80000C10:
    // 0x80000C10: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000C14: lw          $v0, 0x4EDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EDC);
    // 0x80000C18: beq         $v0, $zero, L_80000C40
    if (ctx->r2 == 0) {
        // 0x80000C1C: nop
    
            goto L_80000C40;
    }
    // 0x80000C1C: nop

    // 0x80000C20: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
L_80000C24:
    // 0x80000C24: bnel        $v1, $t0, L_80000C38
    if (ctx->r3 != ctx->r8) {
        // 0x80000C28: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80000C38;
    }
    goto skip_4;
    // 0x80000C28: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_4:
    // 0x80000C2C: jr          $ra
    // 0x80000C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000C34: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80000C38:
    // 0x80000C38: bnel        $v0, $zero, L_80000C24
    if (ctx->r2 != 0) {
        // 0x80000C3C: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_80000C24;
    }
    goto skip_5;
    // 0x80000C3C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_5:
L_80000C40:
    // 0x80000C40: lbu         $t1, 0x5035($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5035);
    // 0x80000C44: lbu         $t2, 0x5034($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X5034);
    // 0x80000C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80000C4C: beq         $t1, $t2, L_80000C5C
    if (ctx->r9 == ctx->r10) {
        // 0x80000C50: nop
    
            goto L_80000C5C;
    }
    // 0x80000C50: nop

    // 0x80000C54: jr          $ra
    // 0x80000C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80000C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80000C5C:
    // 0x80000C5C: jr          $ra
    // 0x80000C60: nop

    return;
    // 0x80000C60: nop

;}
RECOMP_FUNC void grHyruleTwisterGetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A52C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010A530: addiu       $a2, $a2, 0x13F0
    ctx->r6 = ADD32(ctx->r6, 0X13F0);
    // 0x8010A534: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x8010A538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A53C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8010A540: lw          $v1, 0x66FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66FC);
    // 0x8010A544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A548: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010A54C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010A550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010A554: beq         $v1, $zero, L_8010A5AC
    if (ctx->r3 == 0) {
        // 0x8010A558: lwc1        $f0, 0x1C($t7)
        ctx->f0.u32l = MEM_W(ctx->r15, 0X1C);
            goto L_8010A5AC;
    }
    // 0x8010A558: lwc1        $f0, 0x1C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8010A55C: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
L_8010A560:
    // 0x8010A560: lw          $t8, 0x14C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14C);
    // 0x8010A564: bnel        $t8, $zero, L_8010A5A4
    if (ctx->r24 != 0) {
        // 0x8010A568: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8010A5A4;
    }
    goto skip_0;
    // 0x8010A568: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8010A56C: lhu         $t9, 0x26($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X26);
    // 0x8010A570: lw          $t0, 0xEC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XEC);
    // 0x8010A574: bnel        $t9, $t0, L_8010A5A4
    if (ctx->r25 != ctx->r8) {
        // 0x8010A578: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8010A5A4;
    }
    goto skip_1;
    // 0x8010A578: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8010A57C: lw          $t1, 0x8E8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8E8);
    // 0x8010A580: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8010A584: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8010A588: nop

    // 0x8010A58C: bc1fl       L_8010A5A0
    if (!c1cs) {
        // 0x8010A590: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8010A5A0;
    }
    goto skip_2;
    // 0x8010A590: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x8010A594: b           L_8010A5A0
    // 0x8010A598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8010A5A0;
    // 0x8010A598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8010A59C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8010A5A0:
    // 0x8010A5A0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_8010A5A4:
    // 0x8010A5A4: bnel        $v1, $zero, L_8010A560
    if (ctx->r3 != 0) {
        // 0x8010A5A8: lw          $v0, 0x84($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X84);
            goto L_8010A560;
    }
    goto skip_3;
    // 0x8010A5A8: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    skip_3:
L_8010A5AC:
    // 0x8010A5AC: bne         $a1, $zero, L_8010A5BC
    if (ctx->r5 != 0) {
        // 0x8010A5B0: nop
    
            goto L_8010A5BC;
    }
    // 0x8010A5B0: nop

    // 0x8010A5B4: beq         $a0, $zero, L_8010A600
    if (ctx->r4 == 0) {
        // 0x8010A5B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A600;
    }
    // 0x8010A5B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A5BC:
    // 0x8010A5BC: bne         $a1, $a0, L_8010A5E8
    if (ctx->r5 != ctx->r4) {
        // 0x8010A5C0: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8010A5E8;
    }
    // 0x8010A5C0: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8010A5C4: jal         0x80018910
    // 0x8010A5C8: nop

    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x8010A5C8: nop

    after_0:
    // 0x8010A5CC: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x8010A5D0: beq         $t2, $zero, L_8010A5E0
    if (ctx->r10 == 0) {
        // 0x8010A5D4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8010A5E0;
    }
    // 0x8010A5D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010A5D8: b           L_8010A600
    // 0x8010A5DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010A600;
    // 0x8010A5DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010A5E0:
    // 0x8010A5E0: b           L_8010A600
    // 0x8010A5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8010A600;
    // 0x8010A5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8010A5E8:
    // 0x8010A5E8: beq         $at, $zero, L_8010A5F8
    if (ctx->r1 == 0) {
        // 0x8010A5EC: nop
    
            goto L_8010A5F8;
    }
    // 0x8010A5EC: nop

    // 0x8010A5F0: b           L_8010A600
    // 0x8010A5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8010A600;
    // 0x8010A5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010A5F8:
    // 0x8010A5F8: b           L_8010A600
    // 0x8010A5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A600;
    // 0x8010A5FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A600:
    // 0x8010A600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A608: jr          $ra
    // 0x8010A60C: nop

    return;
    // 0x8010A60C: nop

;}
RECOMP_FUNC void gmCameraDefaultFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C734: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010C738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010C73C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010C740: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8010C744: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010C748: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8010C74C: jal         0x8010BC54
    // 0x8010C750: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    gmCameraUpdateInterests(rdram, ctx);
        goto after_0;
    // 0x8010C750: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8010C754: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8010C758: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010C75C: jal         0x8010C70C
    // 0x8010C760: nop

    gmCameraAdjustFOV(rdram, ctx);
        goto after_1;
    // 0x8010C760: nop

    after_1:
    // 0x8010C764: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010C768: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010C76C: jal         0x8010C200
    // 0x8010C770: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    gmCameraGetClampDimensionsMax(rdram, ctx);
        goto after_2;
    // 0x8010C770: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8010C774: jal         0x8010C670
    // 0x8010C778: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_ovl2_8010C670(rdram, ctx);
        goto after_3;
    // 0x8010C778: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8010C77C: jal         0x8010C4D0
    // 0x8010C780: nop

    func_ovl2_8010C4D0(rdram, ctx);
        goto after_4;
    // 0x8010C780: nop

    after_4:
    // 0x8010C784: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010C788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C78C: jal         0x8010C55C
    // 0x8010C790: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    gmCameraPan(rdram, ctx);
        goto after_5;
    // 0x8010C790: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8010C794: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8010C798: jal         0x8010C3C0
    // 0x8010C79C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_ovl2_8010C3C0(rdram, ctx);
        goto after_6;
    // 0x8010C79C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8010C7A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C7A4: jal         0x8010C5C0
    // 0x8010C7A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_ovl2_8010C5C0(rdram, ctx);
        goto after_7;
    // 0x8010C7A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x8010C7AC: jal         0x8010C6B8
    // 0x8010C7B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_8;
    // 0x8010C7B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010C7B4: jal         0x8010C6FC
    // 0x8010C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_9;
    // 0x8010C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8010C7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C7C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010C7C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010C7C8: jr          $ra
    // 0x8010C7CC: nop

    return;
    // 0x8010C7CC: nop

;}
RECOMP_FUNC void mnVSOptionsMakeDamageDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132478: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013247C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132480: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132484: addiu       $t7, $t7, 0x4768
    ctx->r15 = ADD32(ctx->r15, 0X4768);
    // 0x80132488: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013248C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132490: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80132494: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132498: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013249C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801324A0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801324A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801324A8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801324AC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801324B0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801324B4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801324B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801324BC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801324C0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801324C4: lw          $t0, 0x4904($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4904);
    // 0x801324C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801324CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801324D0: beq         $t0, $zero, L_801324E0
    if (ctx->r8 == 0) {
        // 0x801324D4: lui         $a3, 0x8000
        ctx->r7 = S32(0X8000 << 16);
            goto L_801324E0;
    }
    // 0x801324D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801324D8: b           L_801324E4
    // 0x801324DC: addiu       $v1, $zero, 0x97
    ctx->r3 = ADD32(0, 0X97);
        goto L_801324E4;
    // 0x801324DC: addiu       $v1, $zero, 0x97
    ctx->r3 = ADD32(0, 0X97);
L_801324E0:
    // 0x801324E0: addiu       $v1, $zero, 0xA4
    ctx->r3 = ADD32(0, 0XA4);
L_801324E4:
    // 0x801324E4: jal         0x80009968
    // 0x801324E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801324E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801324EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324F0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801324F4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801324F8: sw          $v0, 0x48F8($at)
    MEM_W(0X48F8, ctx->r1) = ctx->r2;
    // 0x801324FC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132500: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132504: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013250C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132510: jal         0x80009DF4
    // 0x80132514: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132514: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132518: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8013251C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132520: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80132524: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80132528: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8013252C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80132530: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132534: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132538: lw          $a1, 0x48F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48F0);
    // 0x8013253C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132540: lui         $a2, 0x435C
    ctx->r6 = S32(0X435C << 16);
    // 0x80132544: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80132548: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8013254C: jal         0x80131CC8
    // 0x80132550: nop

    mnVSOptionsMakeDamageDigitSObjs(rdram, ctx);
        goto after_2;
    // 0x80132550: nop

    after_2:
    // 0x80132554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132558: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013255C: jr          $ra
    // 0x80132560: nop

    return;
    // 0x80132560: nop

;}
RECOMP_FUNC void ftBossCommonSetDisableFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158620: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80158624: lbu         $t6, 0x192($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X192);
    // 0x80158628: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8015862C: jr          $ra
    // 0x80158630: sb          $t7, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r15;
    return;
    // 0x80158630: sb          $t7, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void gcAddDObjRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B4F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B500: jal         0x800092D0
    // 0x8000B504: nop

    gcAddDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8000B504: nop

    after_0:
    // 0x8000B508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B50C: jal         0x8000B3EC
    // 0x8000B510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyD(rdram, ctx);
        goto after_1;
    // 0x8000B510: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B518: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B51C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B520: jr          $ra
    // 0x8000B524: nop

    return;
    // 0x8000B524: nop

;}
RECOMP_FUNC void mpCommonUpdateFighterKinetics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEDF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DEDF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DEDF8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800DEDFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DEE00: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x800DEE04: bne         $t6, $at, L_800DEE2C
    if (ctx->r14 != ctx->r1) {
        // 0x800DEE08: nop
    
            goto L_800DEE2C;
    }
    // 0x800DEE08: nop

    // 0x800DEE0C: jal         0x800DE6B0
    // 0x800DEE10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x800DEE10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DEE14: beq         $v0, $zero, L_800DEE44
    if (ctx->r2 == 0) {
        // 0x800DEE18: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800DEE44;
    }
    // 0x800DEE18: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800DEE1C: jal         0x800DEE98
    // 0x800DEE20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x800DEE20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800DEE24: b           L_800DEE48
    // 0x800DEE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEE48;
    // 0x800DEE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEE2C:
    // 0x800DEE2C: jal         0x800DDDA8
    // 0x800DEE30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_2;
    // 0x800DEE30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x800DEE34: bne         $v0, $zero, L_800DEE44
    if (ctx->r2 != 0) {
        // 0x800DEE38: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800DEE44;
    }
    // 0x800DEE38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800DEE3C: jal         0x800DEEC8
    // 0x800DEE40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_3;
    // 0x800DEE40: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
L_800DEE44:
    // 0x800DEE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEE48:
    // 0x800DEE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DEE4C: jr          $ra
    // 0x800DEE50: nop

    return;
    // 0x800DEE50: nop

;}
RECOMP_FUNC void sc1PStageClearWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339C0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801339C4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801339C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801339CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801339D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801339D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801339D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801339DC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801339E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801339E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801339E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801339EC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801339F0: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801339F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801339F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801339FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133A00: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133A04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A08: lui         $t4, 0x8080
    ctx->r12 = S32(0X8080 << 16);
    // 0x80133A0C: ori         $t4, $t4, 0x80FF
    ctx->r12 = ctx->r12 | 0X80FF;
    // 0x80133A10: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80133A14: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80133A18: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80133A1C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80133A20: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80133A24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A28: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x80133A2C: ori         $t6, $t6, 0xFE23
    ctx->r14 = ctx->r14 | 0XFE23;
    // 0x80133A30: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80133A34: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80133A38: addiu       $t7, $zero, -0x805
    ctx->r15 = ADD32(0, -0X805);
    // 0x80133A3C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133A40: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133A44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A48: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x80133A4C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80133A50: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133A54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133A58: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80133A5C: ori         $t2, $t2, 0x4000
    ctx->r10 = ctx->r10 | 0X4000;
    // 0x80133A60: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80133A64: jal         0x800CCF74
    // 0x80133A68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80133A68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80133A6C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133A70: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133A74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A78: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80133A7C: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80133A80: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80133A84: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80133A88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133A8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80133A90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A94: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80133A98: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80133A9C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80133AA0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80133AA4: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80133AA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133AAC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133AB8: jr          $ra
    // 0x80133ABC: nop

    return;
    // 0x80133ABC: nop

;}
RECOMP_FUNC void mvOpeningSamusMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D318: lw          $t6, -0x1D88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1D88);
    // 0x8018D31C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D320: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D324: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D328: bne         $at, $zero, L_8018D404
    if (ctx->r1 != 0) {
        // 0x8018D32C: addiu       $v1, $v1, -0x1D48
        ctx->r3 = ADD32(ctx->r3, -0X1D48);
            goto L_8018D404;
    }
    // 0x8018D32C: addiu       $v1, $v1, -0x1D48
    ctx->r3 = ADD32(ctx->r3, -0X1D48);
    // 0x8018D330: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D334: addiu       $a0, $a0, -0x1D68
    ctx->r4 = ADD32(ctx->r4, -0X1D68);
    // 0x8018D338: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D33C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D340: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D348: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D34C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D350: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D354: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D358: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D35C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D360: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D364: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D368: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D36C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D370: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D374: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D378: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D37C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D380: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D384: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D388: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D38C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D390: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D394: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D398: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D39C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D3A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3AC: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D3B0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3B8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3C0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3C8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3CC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3D0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3D4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3DC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3E4: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3E8: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3EC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D3F0: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D3F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3F8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3FC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D400: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D404:
    // 0x8018D404: jr          $ra
    // 0x8018D408: nop

    return;
    // 0x8018D408: nop

;}
RECOMP_FUNC void efManagerSamusGrappleBeamGlowMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101E84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101E8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101E90: jal         0x800FDAFC
    // 0x80101E94: addiu       $a0, $a0, -0x1D64
    ctx->r4 = ADD32(ctx->r4, -0X1D64);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101E94: addiu       $a0, $a0, -0x1D64
    ctx->r4 = ADD32(ctx->r4, -0X1D64);
    after_0:
    // 0x80101E98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101E9C: bne         $v0, $zero, L_80101EAC
    if (ctx->r2 != 0) {
        // 0x80101EA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80101EAC;
    }
    // 0x80101EA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80101EA4: b           L_80101EC8
    // 0x80101EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101EC8;
    // 0x80101EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101EAC:
    // 0x80101EAC: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80101EB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101EB4: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80101EB8: lw          $t6, 0x84($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X84);
    // 0x80101EBC: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x80101EC0: lw          $t7, 0x944($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X944);
    // 0x80101EC4: sw          $t7, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r15;
L_80101EC8:
    // 0x80101EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101ED0: jr          $ra
    // 0x80101ED4: nop

    return;
    // 0x80101ED4: nop

;}
RECOMP_FUNC void ifCommonBattlePauseProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113AA8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80113AAC: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80113AB0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113ABC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80113AC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80113AC4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80113AC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80113ACC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80113AD0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80113AD4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113AD8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80113ADC: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80113AE0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80113AE4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80113AE8: lui         $t0, 0x30
    ctx->r8 = S32(0X30 << 16);
    // 0x80113AEC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80113AF0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80113AF4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113AF8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80113AFC: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x80113B00: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80113B04: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80113B08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80113B0C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80113B10: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113B14: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x80113B18: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80113B1C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80113B20: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80113B24: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80113B28: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80113B2C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113B30: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80113B34: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80113B38: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80113B3C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80113B40: lw          $t7, -0xF50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XF50);
    // 0x80113B44: lw          $t1, -0xF54($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XF54);
    // 0x80113B48: lui         $a2, 0xF600
    ctx->r6 = S32(0XF600 << 16);
    // 0x80113B4C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80113B50: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80113B54: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80113B58: sll         $t3, $t2, 14
    ctx->r11 = S32(ctx->r10 << 14);
    // 0x80113B5C: or          $t0, $t9, $a2
    ctx->r8 = ctx->r25 | ctx->r6;
    // 0x80113B60: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80113B64: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80113B68: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80113B6C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80113B70: lw          $t5, -0xF58($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XF58);
    // 0x80113B74: lw          $t8, -0xF5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XF5C);
    // 0x80113B78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80113B7C: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x80113B80: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80113B84: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80113B88: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80113B8C: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x80113B90: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80113B94: addiu       $t4, $t4, -0xF5C
    ctx->r12 = ADD32(ctx->r12, -0XF5C);
    // 0x80113B98: sll         $t3, $a3, 4
    ctx->r11 = S32(ctx->r7 << 4);
    // 0x80113B9C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80113BA0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80113BA4: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x80113BA8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80113BAC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113BB0: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x80113BB4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80113BB8: andi        $t1, $t7, 0x3FF
    ctx->r9 = ctx->r15 & 0X3FF;
    // 0x80113BBC: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80113BC0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80113BC4: sll         $t2, $t1, 14
    ctx->r10 = S32(ctx->r9 << 14);
    // 0x80113BC8: or          $t9, $t8, $a2
    ctx->r25 = ctx->r24 | ctx->r6;
    // 0x80113BCC: or          $t0, $t9, $t2
    ctx->r8 = ctx->r25 | ctx->r10;
    // 0x80113BD0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80113BD4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80113BD8: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80113BDC: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80113BE0: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80113BE4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80113BE8: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80113BEC: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x80113BF0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80113BF4: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x80113BF8: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80113BFC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113C00: andi        $t0, $t2, 0x3FF
    ctx->r8 = ctx->r10 & 0X3FF;
    // 0x80113C04: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80113C08: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80113C0C: sll         $t5, $t8, 14
    ctx->r13 = S32(ctx->r24 << 14);
    // 0x80113C10: or          $t4, $t3, $a2
    ctx->r12 = ctx->r11 | ctx->r6;
    // 0x80113C14: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80113C18: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80113C1C: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80113C20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80113C24: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x80113C28: lw          $t1, 0x14($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14);
    // 0x80113C2C: andi        $t3, $t0, 0x3FF
    ctx->r11 = ctx->r8 & 0X3FF;
    // 0x80113C30: andi        $t9, $t1, 0x3FF
    ctx->r25 = ctx->r9 & 0X3FF;
    // 0x80113C34: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80113C38: sll         $t6, $t3, 14
    ctx->r14 = S32(ctx->r11 << 14);
    // 0x80113C3C: or          $t8, $t2, $t6
    ctx->r24 = ctx->r10 | ctx->r14;
    // 0x80113C40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80113C44: lw          $t5, 0x2C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X2C);
    // 0x80113C48: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x80113C4C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113C50: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x80113C54: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80113C58: andi        $t3, $t0, 0x3FF
    ctx->r11 = ctx->r8 & 0X3FF;
    // 0x80113C5C: sll         $t2, $t3, 14
    ctx->r10 = S32(ctx->r11 << 14);
    // 0x80113C60: or          $t9, $t1, $a2
    ctx->r25 = ctx->r9 | ctx->r6;
    // 0x80113C64: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80113C68: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80113C6C: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x80113C70: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80113C74: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80113C78: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80113C7C: andi        $t1, $t7, 0x3FF
    ctx->r9 = ctx->r15 & 0X3FF;
    // 0x80113C80: andi        $t4, $t8, 0x3FF
    ctx->r12 = ctx->r24 & 0X3FF;
    // 0x80113C84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80113C88: sll         $t0, $t1, 14
    ctx->r8 = S32(ctx->r9 << 14);
    // 0x80113C8C: or          $t3, $t5, $t0
    ctx->r11 = ctx->r13 | ctx->r8;
    // 0x80113C90: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80113C94: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x80113C98: lw          $t7, 0x38($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X38);
    // 0x80113C9C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80113CA0: andi        $t6, $t2, 0x3FF
    ctx->r14 = ctx->r10 & 0X3FF;
    // 0x80113CA4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80113CA8: andi        $t1, $t7, 0x3FF
    ctx->r9 = ctx->r15 & 0X3FF;
    // 0x80113CAC: sll         $t5, $t1, 14
    ctx->r13 = S32(ctx->r9 << 14);
    // 0x80113CB0: or          $t4, $t8, $a2
    ctx->r12 = ctx->r24 | ctx->r6;
    // 0x80113CB4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80113CB8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80113CBC: or          $t0, $t4, $t5
    ctx->r8 = ctx->r12 | ctx->r13;
    // 0x80113CC0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80113CC4: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80113CC8: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x80113CCC: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80113CD0: andi        $t9, $t3, 0x3FF
    ctx->r25 = ctx->r11 & 0X3FF;
    // 0x80113CD4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80113CD8: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80113CDC: or          $t1, $t2, $t7
    ctx->r9 = ctx->r10 | ctx->r15;
    // 0x80113CE0: jal         0x800CCEAC
    // 0x80113CE4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80113CE4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    after_0:
    // 0x80113CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113CF0: jr          $ra
    // 0x80113CF4: nop

    return;
    // 0x80113CF4: nop

;}
RECOMP_FUNC void ftBossOkupunch3ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AA10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AA18: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AA1C: jal         0x800D9480
    // 0x8015AA20: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AA20: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x8015AA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AA28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AA2C: jr          $ra
    // 0x8015AA30: nop

    return;
    // 0x8015AA30: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EE18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010EE1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010EE20: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8010EE24: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010EE28: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010EE2C: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8010EE30: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8010EE34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010EE38: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8010EE3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010EE40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010EE44: lb          $t9, 0x2B($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X2B);
    // 0x8010EE48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010EE4C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010EE50: bne         $t9, $at, L_8010EEB0
    if (ctx->r25 != ctx->r1) {
        // 0x8010EE54: sll         $t4, $v1, 3
        ctx->r12 = S32(ctx->r3 << 3);
            goto L_8010EEB0;
    }
    // 0x8010EE54: sll         $t4, $v1, 3
    ctx->r12 = S32(ctx->r3 << 3);
    // 0x8010EE58: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x8010EE5C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x8010EE60: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010EE64: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x8010EE68: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8010EE6C: addiu       $t1, $t1, 0x1598
    ctx->r9 = ADD32(ctx->r9, 0X1598);
    // 0x8010EE70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010EE74: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8010EE78: lbu         $a0, 0x68($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X68);
    // 0x8010EE7C: beql        $a0, $zero, L_8010EEF0
    if (ctx->r4 == 0) {
        // 0x8010EE80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010EEF0;
    }
    goto skip_0;
    // 0x8010EE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010EE84: lbu         $t2, 0x65($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X65);
    // 0x8010EE88: beql        $t2, $zero, L_8010EEA8
    if (ctx->r10 == 0) {
        // 0x8010EE8C: addiu       $t3, $a0, -0x1
        ctx->r11 = ADD32(ctx->r4, -0X1);
            goto L_8010EEA8;
    }
    goto skip_1;
    // 0x8010EE8C: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    skip_1:
    // 0x8010EE90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010EE94: jal         0x8010EC50
    // 0x8010EE98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    ifCommonPlayerDamageUpdateAnim(rdram, ctx);
        goto after_0;
    // 0x8010EE98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8010EE9C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8010EEA0: lbu         $a0, 0x68($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X68);
    // 0x8010EEA4: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
L_8010EEA8:
    // 0x8010EEA8: b           L_8010EEEC
    // 0x8010EEAC: sb          $t3, 0x68($v0)
    MEM_B(0X68, ctx->r2) = ctx->r11;
        goto L_8010EEEC;
    // 0x8010EEAC: sb          $t3, 0x68($v0)
    MEM_B(0X68, ctx->r2) = ctx->r11;
L_8010EEB0:
    // 0x8010EEB0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8010EEB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8010EEB8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8010EEBC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8010EEC0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8010EEC4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8010EEC8: lbu         $t5, 0x15FD($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X15FD);
    // 0x8010EECC: beq         $t5, $zero, L_8010EEE4
    if (ctx->r13 == 0) {
        // 0x8010EED0: nop
    
            goto L_8010EEE4;
    }
    // 0x8010EED0: nop

    // 0x8010EED4: jal         0x8010EC50
    // 0x8010EED8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ifCommonPlayerDamageUpdateAnim(rdram, ctx);
        goto after_1;
    // 0x8010EED8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8010EEDC: b           L_8010EEF0
    // 0x8010EEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010EEF0;
    // 0x8010EEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010EEE4:
    // 0x8010EEE4: jal         0x8010E8F4
    // 0x8010EEE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ifCommonPlayerDamageUpdateDigits(rdram, ctx);
        goto after_2;
    // 0x8010EEE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_8010EEEC:
    // 0x8010EEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010EEF0:
    // 0x8010EEF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010EEF4: jr          $ra
    // 0x8010EEF8: nop

    return;
    // 0x8010EEF8: nop

;}
RECOMP_FUNC void ftParamClearAnimLocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB7F4: lw          $v1, 0x8E8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8E8);
    // 0x800EB7F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800EB7FC: addiu       $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
    // 0x800EB800: beql        $v1, $zero, L_800EB838
    if (ctx->r3 == 0) {
        // 0x800EB804: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800EB838;
    }
    goto skip_0;
    // 0x800EB804: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_0:
    // 0x800EB808: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x800EB80C: beql        $a1, $zero, L_800EB838
    if (ctx->r5 == 0) {
        // 0x800EB810: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800EB838;
    }
    goto skip_1;
    // 0x800EB810: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_1:
    // 0x800EB814: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EB818: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800EB81C: bnel        $a3, $t6, L_800EB838
    if (ctx->r7 != ctx->r14) {
        // 0x800EB820: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800EB838;
    }
    goto skip_2;
    // 0x800EB820: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    skip_2:
    // 0x800EB824: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800EB828: lw          $t7, 0x8E8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8E8);
    // 0x800EB82C: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x800EB830: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x800EB834: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800EB838:
    // 0x800EB838: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800EB83C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
L_800EB840:
    // 0x800EB840: lw          $v0, 0x8E8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8E8);
    // 0x800EB844: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EB848: beql        $v0, $zero, L_800EB87C
    if (ctx->r2 == 0) {
        // 0x800EB84C: lw          $v0, 0x8EC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8EC);
            goto L_800EB87C;
    }
    goto skip_3;
    // 0x800EB84C: lw          $v0, 0x8EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8EC);
    skip_3:
    // 0x800EB850: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x800EB854: beql        $a0, $zero, L_800EB87C
    if (ctx->r4 == 0) {
        // 0x800EB858: lw          $v0, 0x8EC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8EC);
            goto L_800EB87C;
    }
    goto skip_4;
    // 0x800EB858: lw          $v0, 0x8EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8EC);
    skip_4:
    // 0x800EB85C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800EB860: bnel        $a3, $t9, L_800EB87C
    if (ctx->r7 != ctx->r25) {
        // 0x800EB864: lw          $v0, 0x8EC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8EC);
            goto L_800EB87C;
    }
    goto skip_5;
    // 0x800EB864: lw          $v0, 0x8EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8EC);
    skip_5:
    // 0x800EB868: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800EB86C: lw          $t1, 0x8E8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8E8);
    // 0x800EB870: lw          $t2, 0x58($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X58);
    // 0x800EB874: sb          $zero, 0x5($t2)
    MEM_B(0X5, ctx->r10) = 0;
    // 0x800EB878: lw          $v0, 0x8EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8EC);
L_800EB87C:
    // 0x800EB87C: beql        $v0, $zero, L_800EB8B0
    if (ctx->r2 == 0) {
        // 0x800EB880: lw          $v0, 0x8F0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F0);
            goto L_800EB8B0;
    }
    goto skip_6;
    // 0x800EB880: lw          $v0, 0x8F0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F0);
    skip_6:
    // 0x800EB884: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x800EB888: beql        $a2, $zero, L_800EB8B0
    if (ctx->r6 == 0) {
        // 0x800EB88C: lw          $v0, 0x8F0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F0);
            goto L_800EB8B0;
    }
    goto skip_7;
    // 0x800EB88C: lw          $v0, 0x8F0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F0);
    skip_7:
    // 0x800EB890: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800EB894: bnel        $a3, $t3, L_800EB8B0
    if (ctx->r7 != ctx->r11) {
        // 0x800EB898: lw          $v0, 0x8F0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F0);
            goto L_800EB8B0;
    }
    goto skip_8;
    // 0x800EB898: lw          $v0, 0x8F0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F0);
    skip_8:
    // 0x800EB89C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800EB8A0: lw          $t4, 0x8EC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8EC);
    // 0x800EB8A4: lw          $t5, 0x58($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X58);
    // 0x800EB8A8: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x800EB8AC: lw          $v0, 0x8F0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F0);
L_800EB8B0:
    // 0x800EB8B0: beql        $v0, $zero, L_800EB8E4
    if (ctx->r2 == 0) {
        // 0x800EB8B4: lw          $v0, 0x8F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F4);
            goto L_800EB8E4;
    }
    goto skip_9;
    // 0x800EB8B4: lw          $v0, 0x8F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F4);
    skip_9:
    // 0x800EB8B8: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x800EB8BC: beql        $a2, $zero, L_800EB8E4
    if (ctx->r6 == 0) {
        // 0x800EB8C0: lw          $v0, 0x8F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F4);
            goto L_800EB8E4;
    }
    goto skip_10;
    // 0x800EB8C0: lw          $v0, 0x8F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F4);
    skip_10:
    // 0x800EB8C4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800EB8C8: bnel        $a3, $t6, L_800EB8E4
    if (ctx->r7 != ctx->r14) {
        // 0x800EB8CC: lw          $v0, 0x8F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X8F4);
            goto L_800EB8E4;
    }
    goto skip_11;
    // 0x800EB8CC: lw          $v0, 0x8F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F4);
    skip_11:
    // 0x800EB8D0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800EB8D4: lw          $t7, 0x8F0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8F0);
    // 0x800EB8D8: lw          $t8, 0x58($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X58);
    // 0x800EB8DC: sb          $zero, 0x5($t8)
    MEM_B(0X5, ctx->r24) = 0;
    // 0x800EB8E0: lw          $v0, 0x8F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8F4);
L_800EB8E4:
    // 0x800EB8E4: beq         $v0, $zero, L_800EB914
    if (ctx->r2 == 0) {
        // 0x800EB8E8: nop
    
            goto L_800EB914;
    }
    // 0x800EB8E8: nop

    // 0x800EB8EC: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x800EB8F0: beq         $a2, $zero, L_800EB914
    if (ctx->r6 == 0) {
        // 0x800EB8F4: nop
    
            goto L_800EB914;
    }
    // 0x800EB8F4: nop

    // 0x800EB8F8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800EB8FC: bne         $a3, $t9, L_800EB914
    if (ctx->r7 != ctx->r25) {
        // 0x800EB900: nop
    
            goto L_800EB914;
    }
    // 0x800EB900: nop

    // 0x800EB904: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800EB908: lw          $t1, 0x8F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8F4);
    // 0x800EB90C: lw          $t2, 0x58($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X58);
    // 0x800EB910: sb          $zero, 0x5($t2)
    MEM_B(0X5, ctx->r10) = 0;
L_800EB914:
    // 0x800EB914: bne         $v1, $t0, L_800EB840
    if (ctx->r3 != ctx->r8) {
        // 0x800EB918: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800EB840;
    }
    // 0x800EB918: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EB91C: jr          $ra
    // 0x800EB920: nop

    return;
    // 0x800EB920: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckPuckInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013464C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80134650: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80134654: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134658: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013465C: lw          $t6, 0x764C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X764C);
    // 0x80134660: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80134664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134668: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013466C: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80134670: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80134674: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80134678: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8013467C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134680: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80134684: nop

    // 0x80134688: bc1f        L_801346B4
    if (!c1cs) {
        // 0x8013468C: nop
    
            goto L_801346B4;
    }
    // 0x8013468C: nop

    // 0x80134690: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134694: nop

    // 0x80134698: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8013469C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801346A0: nop

    // 0x801346A4: bc1f        L_801346B4
    if (!c1cs) {
        // 0x801346A8: nop
    
            goto L_801346B4;
    }
    // 0x801346A8: nop

    // 0x801346AC: b           L_801346B4
    // 0x801346B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801346B4;
    // 0x801346B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801346B4:
    // 0x801346B4: beq         $a0, $zero, L_80134718
    if (ctx->r4 == 0) {
        // 0x801346B8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80134718;
    }
    // 0x801346B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801346BC: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801346C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801346C4: lwc1        $f2, 0x5C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801346C8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801346CC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801346D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801346D4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801346D8: nop

    // 0x801346DC: bc1f        L_80134708
    if (!c1cs) {
        // 0x801346E0: nop
    
            goto L_80134708;
    }
    // 0x801346E0: nop

    // 0x801346E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801346E8: nop

    // 0x801346EC: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x801346F0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801346F4: nop

    // 0x801346F8: bc1f        L_80134708
    if (!c1cs) {
        // 0x801346FC: nop
    
            goto L_80134708;
    }
    // 0x801346FC: nop

    // 0x80134700: b           L_80134708
    // 0x80134704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80134708;
    // 0x80134704: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80134708:
    // 0x80134708: beql        $a0, $zero, L_8013471C
    if (ctx->r4 == 0) {
        // 0x8013470C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013471C;
    }
    goto skip_0;
    // 0x8013470C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80134710: jr          $ra
    // 0x80134714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80134714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134718:
    // 0x80134718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013471C:
    // 0x8013471C: jr          $ra
    // 0x80134720: nop

    return;
    // 0x80134720: nop

;}
RECOMP_FUNC void mpProcessRunCeilCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD160: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DD164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DD168: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DD16C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DD170: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x800DD174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DD178: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x800DD17C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DD180: addiu       $v0, $s0, 0x94
    ctx->r2 = ADD32(ctx->r16, 0X94);
    // 0x800DD184: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD188: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800DD18C: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800DD190: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DD194: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800DD198: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DD19C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800DD1A0: lw          $a0, 0x8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8C);
    // 0x800DD1A4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800DD1A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800DD1AC: jal         0x800F3E04
    // 0x800DD1B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_0;
    // 0x800DD1B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800DD1B4: beq         $v0, $zero, L_800DD1DC
    if (ctx->r2 == 0) {
        // 0x800DD1B8: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DD1DC;
    }
    // 0x800DD1B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD1BC: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DD1C0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800DD1C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DD1C8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800DD1CC: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DD1D0: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x800DD1D4: b           L_800DD2B4
    // 0x800DD1D8: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
        goto L_800DD2B4;
    // 0x800DD1D8: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
L_800DD1DC:
    // 0x800DD1DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800DD1E0: jal         0x800F4468
    // 0x800DD1E4: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    mpCollisionGetCeilEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DD1E4: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    after_1:
    // 0x800DD1E8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DD1EC: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DD1F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD1F4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800DD1F8: nop

    // 0x800DD1FC: bc1f        L_800DD234
    if (!c1cs) {
        // 0x800DD200: nop
    
            goto L_800DD234;
    }
    // 0x800DD200: nop

    // 0x800DD204: jal         0x800FABA4
    // 0x800DD208: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    mpCollisionGetEdgeUpperLLineID(rdram, ctx);
        goto after_2;
    // 0x800DD208: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    after_2:
    // 0x800DD20C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD210: beq         $v0, $at, L_800DD268
    if (ctx->r2 == ctx->r1) {
        // 0x800DD214: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD268;
    }
    // 0x800DD214: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD218: jal         0x800FA8A4
    // 0x800DD21C: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_3;
    // 0x800DD21C: nop

    after_3:
    // 0x800DD220: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DD224: bne         $v0, $at, L_800DD268
    if (ctx->r2 != ctx->r1) {
        // 0x800DD228: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800DD268;
    }
    // 0x800DD228: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DD22C: b           L_800DD268
    // 0x800DD230: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800DD268;
    // 0x800DD230: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800DD234:
    // 0x800DD234: jal         0x800F4448
    // 0x800DD238: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    mpCollisionGetCeilEdgeR(rdram, ctx);
        goto after_4;
    // 0x800DD238: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    after_4:
    // 0x800DD23C: jal         0x800FAAE4
    // 0x800DD240: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    mpCollisionGetEdgeUpperRLineID(rdram, ctx);
        goto after_5;
    // 0x800DD240: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    after_5:
    // 0x800DD244: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD248: beq         $v0, $at, L_800DD268
    if (ctx->r2 == ctx->r1) {
        // 0x800DD24C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD268;
    }
    // 0x800DD24C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD250: jal         0x800FA8A4
    // 0x800DD254: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_6;
    // 0x800DD254: nop

    after_6:
    // 0x800DD258: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DD25C: bne         $v0, $at, L_800DD268
    if (ctx->r2 != ctx->r1) {
        // 0x800DD260: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800DD268;
    }
    // 0x800DD260: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DD264: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800DD268:
    // 0x800DD268: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800DD26C: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800DD270: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DD278: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800DD27C: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x800DD280: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800DD284: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DD288: beql        $t0, $zero, L_800DD2B8
    if (ctx->r8 == 0) {
        // 0x800DD28C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DD2B8;
    }
    goto skip_0;
    // 0x800DD28C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DD290: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x800DD294: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800DD298: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    // 0x800DD29C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD2A0: jal         0x800F3E04
    // 0x800DD2A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_7;
    // 0x800DD2A4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_7:
    // 0x800DD2A8: lhu         $t2, 0x5A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DD2AC: ori         $t3, $t2, 0x400
    ctx->r11 = ctx->r10 | 0X400;
    // 0x800DD2B0: sh          $t3, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r11;
L_800DD2B4:
    // 0x800DD2B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DD2B8:
    // 0x800DD2B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD2BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DD2C0: jr          $ra
    // 0x800DD2C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800DD2C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ifCommonAnnounceGameSetMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011341C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80113420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80113424: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80113428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8011342C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80113430: jal         0x80009968
    // 0x80113434: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80113434: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80113438: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8011343C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80113440: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80113444: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80113448: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8011344C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80113450: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80113454: jal         0x80009DF4
    // 0x80113458: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80113458: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8011345C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80113460: addiu       $a2, $a2, -0x11EC
    ctx->r6 = ADD32(ctx->r6, -0X11EC);
    // 0x80113464: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80113468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8011346C: jal         0x80112024
    // 0x80113470: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    ifCommonAnnounceSetAttr(rdram, ctx);
        goto after_2;
    // 0x80113470: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x80113474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80113478: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8011347C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80113480: jr          $ra
    // 0x80113484: nop

    return;
    // 0x80113484: nop

;}
RECOMP_FUNC void mvOpeningMarioPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D990: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D994: lw          $v1, -0x1DF8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1DF8);
    // 0x8018D998: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D99C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9A0: beq         $v1, $at, L_8018D9C8
    if (ctx->r3 == ctx->r1) {
        // 0x8018D9A4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9C8;
    }
    // 0x8018D9A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D9A8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D9AC: beq         $v0, $at, L_8018D9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9B0: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9DC;
    }
    // 0x8018D9B0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9B4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9B8: beq         $v0, $at, L_8018D9F0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9BC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9F0;
    }
    // 0x8018D9BC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9C0: b           L_8018DA00
    // 0x8018D9C4: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
        goto L_8018DA00;
    // 0x8018D9C4: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
L_8018D9C8:
    // 0x8018D9C8: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9D0: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
    // 0x8018D9D4: b           L_8018DA00
    // 0x8018D9D8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA00;
    // 0x8018D9D8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018D9DC:
    // 0x8018D9DC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D9E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D9E4: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
    // 0x8018D9E8: b           L_8018DA00
    // 0x8018D9EC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA00;
    // 0x8018D9EC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018D9F0:
    // 0x8018D9F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D9F4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9F8: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
    // 0x8018D9FC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA00:
    // 0x8018DA00: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA04: bne         $at, $zero, L_8018DA24
    if (ctx->r1 != 0) {
        // 0x8018DA08: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA24;
    }
    // 0x8018DA08: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA0C: beq         $at, $zero, L_8018DA24
    if (ctx->r1 == 0) {
        // 0x8018DA10: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA24;
    }
    // 0x8018DA10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA14: lwc1        $f16, -0x1E10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E10);
    // 0x8018DA18: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA20: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA24:
    // 0x8018DA24: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA28: bne         $at, $zero, L_8018DA48
    if (ctx->r1 != 0) {
        // 0x8018DA2C: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA48;
    }
    // 0x8018DA2C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA30: beq         $at, $zero, L_8018DA48
    if (ctx->r1 == 0) {
        // 0x8018DA34: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA48;
    }
    // 0x8018DA34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA3C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA44: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA48:
    // 0x8018DA48: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA4C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA50: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DA54: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018DA58: jr          $ra
    // 0x8018DA5C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA5C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mnMapsGetSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132498: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x8013249C: bne         $at, $zero, L_801324B4
    if (ctx->r1 != 0) {
        // 0x801324A0: addiu       $at, $zero, 0xDE
        ctx->r1 = ADD32(0, 0XDE);
            goto L_801324B4;
    }
    // 0x801324A0: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x801324A4: beql        $a0, $at, L_80132520
    if (ctx->r4 == ctx->r1) {
        // 0x801324A8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80132520;
    }
    goto skip_0;
    // 0x801324A8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    skip_0:
    // 0x801324AC: jr          $ra
    // 0x801324B0: nop

    return;
    // 0x801324B0: nop

L_801324B4:
    // 0x801324B4: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x801324B8: beq         $at, $zero, L_80132520
    if (ctx->r1 == 0) {
        // 0x801324BC: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80132520;
    }
    // 0x801324BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801324C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324C4: addu        $at, $at, $t6
    gpr jr_addend_801324CC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801324C8: lw          $t6, 0x4B98($at)
    ctx->r14 = ADD32(ctx->r1, 0X4B98);
    // 0x801324CC: jr          $t6
    // 0x801324D0: nop

    switch (jr_addend_801324CC >> 2) {
        case 0: goto L_801324D4; break;
        case 1: goto L_8013250C; break;
        case 2: goto L_801324DC; break;
        case 3: goto L_801324EC; break;
        case 4: goto L_801324E4; break;
        case 5: goto L_801324FC; break;
        case 6: goto L_80132504; break;
        case 7: goto L_80132514; break;
        case 8: goto L_801324F4; break;
        default: switch_error(__func__, 0x801324CC, 0x80134B98);
    }
    // 0x801324D0: nop

L_801324D4:
    // 0x801324D4: jr          $ra
    // 0x801324D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801324D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801324DC:
    // 0x801324DC: jr          $ra
    // 0x801324E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801324E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801324E4:
    // 0x801324E4: jr          $ra
    // 0x801324E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x801324E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801324EC:
    // 0x801324EC: jr          $ra
    // 0x801324F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x801324F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_801324F4:
    // 0x801324F4: jr          $ra
    // 0x801324F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801324F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801324FC:
    // 0x801324FC: jr          $ra
    // 0x80132500: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80132500: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80132504:
    // 0x80132504: jr          $ra
    // 0x80132508: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80132508: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8013250C:
    // 0x8013250C: jr          $ra
    // 0x80132510: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x80132510: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80132514:
    // 0x80132514: jr          $ra
    // 0x80132518: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80132518: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8013251C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80132520:
    // 0x80132520: jr          $ra
    // 0x80132524: nop

    return;
    // 0x80132524: nop

;}
RECOMP_FUNC void unref_80014A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014A84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014A88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014A8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80014A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014A98: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80014A9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014AA0: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80014AA4: lbu         $t6, 0x54($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X54);
    // 0x80014AA8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80014AAC: bnel        $t7, $zero, L_80014C28
    if (ctx->r15 != 0) {
        // 0x80014AB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014C28;
    }
    goto skip_0;
    // 0x80014AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80014AB4: lw          $v1, 0x50($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X50);
    // 0x80014AB8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80014ABC: addiu       $s0, $s0, 0x72A8
    ctx->r16 = ADD32(ctx->r16, 0X72A8);
    // 0x80014AC0: beq         $v1, $zero, L_80014C24
    if (ctx->r3 == 0) {
        // 0x80014AC4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80014C24;
    }
    // 0x80014AC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80014AC8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80014ACC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80014AD0: jal         0x80014798
    // 0x80014AD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80014AD4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80014AD8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80014ADC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80014AE0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80014AE4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80014AE8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80014AEC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80014AF0: nop

    // 0x80014AF4: bc1f        L_80014B20
    if (!c1cs) {
        // 0x80014AF8: nop
    
            goto L_80014B20;
    }
    // 0x80014AF8: nop

    // 0x80014AFC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80014B00:
    // 0x80014B00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80014B04: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80014B08: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80014B0C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80014B10: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80014B14: nop

    // 0x80014B18: bc1tl       L_80014B00
    if (c1cs) {
        // 0x80014B1C: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80014B00;
    }
    goto skip_1;
    // 0x80014B1C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80014B20:
    // 0x80014B20: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80014B24: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80014B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014B2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80014B30: jal         0x80010D70
    // 0x80014B34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_1;
    // 0x80014B34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80014B38: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80014B3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80014B40: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80014B44: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80014B48: beql        $t0, $zero, L_80014B9C
    if (ctx->r8 == 0) {
        // 0x80014B4C: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80014B9C;
    }
    goto skip_2;
    // 0x80014B4C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_2:
    // 0x80014B50: lbu         $t1, 0x54($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X54);
    // 0x80014B54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80014B58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80014B5C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80014B60: bnel        $t2, $zero, L_80014B9C
    if (ctx->r10 != 0) {
        // 0x80014B64: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80014B9C;
    }
    goto skip_3;
    // 0x80014B64: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_3:
    // 0x80014B68: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80014B6C: jal         0x80012D90
    // 0x80014B70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x80014B70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80014B74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80014B78: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80014B7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80014B80: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80014B84: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80014B88: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80014B8C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80014B90: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80014B94: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80014B98: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_80014B9C:
    // 0x80014B9C: beql        $a0, $zero, L_80014BB4
    if (ctx->r4 == 0) {
        // 0x80014BA0: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80014BB4;
    }
    goto skip_4;
    // 0x80014BA0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x80014BA4: jal         0x8001490C
    // 0x80014BA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcDrawDObjTreeMultiList(rdram, ctx);
        goto after_3;
    // 0x80014BA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80014BAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80014BB0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_80014BB4:
    // 0x80014BB4: beql        $t6, $zero, L_80014BFC
    if (ctx->r14 == 0) {
        // 0x80014BB8: lw          $t2, 0xC($a2)
        ctx->r10 = MEM_W(ctx->r6, 0XC);
            goto L_80014BFC;
    }
    goto skip_5;
    // 0x80014BB8: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    skip_5:
    // 0x80014BBC: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80014BC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014BC4: lui         $t0, 0xD838
    ctx->r8 = S32(0XD838 << 16);
    // 0x80014BC8: beql        $t7, $at, L_80014BE0
    if (ctx->r15 == ctx->r1) {
        // 0x80014BCC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80014BE0;
    }
    goto skip_6;
    // 0x80014BCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x80014BD0: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80014BD4: beql        $t8, $zero, L_80014BFC
    if (ctx->r24 == 0) {
        // 0x80014BD8: lw          $t2, 0xC($a2)
        ctx->r10 = MEM_W(ctx->r6, 0XC);
            goto L_80014BFC;
    }
    goto skip_7;
    // 0x80014BD8: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    skip_7:
    // 0x80014BDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80014BE0:
    // 0x80014BE0: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x80014BE4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80014BE8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80014BEC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80014BF0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80014BF4: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80014BF8: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
L_80014BFC:
    // 0x80014BFC: bnel        $t2, $zero, L_80014C28
    if (ctx->r10 != 0) {
        // 0x80014C00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014C28;
    }
    goto skip_8;
    // 0x80014C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80014C04: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x80014C08: beql        $s0, $zero, L_80014C28
    if (ctx->r16 == 0) {
        // 0x80014C0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014C28;
    }
    goto skip_9;
    // 0x80014C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
L_80014C10:
    // 0x80014C10: jal         0x8001490C
    // 0x80014C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeMultiList(rdram, ctx);
        goto after_4;
    // 0x80014C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80014C18: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80014C1C: bne         $s0, $zero, L_80014C10
    if (ctx->r16 != 0) {
        // 0x80014C20: nop
    
            goto L_80014C10;
    }
    // 0x80014C20: nop

L_80014C24:
    // 0x80014C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80014C28:
    // 0x80014C28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014C2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014C30: jr          $ra
    // 0x80014C34: nop

    return;
    // 0x80014C34: nop

;}
RECOMP_FUNC void ftParamTryPlayItemMusic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7B04: jal         0x800E7AD0
    // 0x800E7B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftParamGetItemMusicLength(rdram, ctx);
        goto after_0;
    // 0x800E7B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E7B0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E7B10: lw          $a0, 0x139C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X139C);
    // 0x800E7B14: jal         0x800E7AD0
    // 0x800E7B18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamGetItemMusicLength(rdram, ctx);
        goto after_1;
    // 0x800E7B18: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E7B1C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7B20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E7B24: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E7B28: bnel        $at, $zero, L_800E7B48
    if (ctx->r1 != 0) {
        // 0x800E7B2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E7B48;
    }
    goto skip_0;
    // 0x800E7B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E7B30: jal         0x80020AB4
    // 0x800E7B34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    syAudioPlayBGM(rdram, ctx);
        goto after_2;
    // 0x800E7B34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800E7B38: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800E7B3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E7B40: sw          $t7, 0x139C($at)
    MEM_W(0X139C, ctx->r1) = ctx->r15;
    // 0x800E7B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E7B48:
    // 0x800E7B48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7B4C: jr          $ra
    // 0x800E7B50: nop

    return;
    // 0x800E7B50: nop

;}
RECOMP_FUNC void func_ovl8_803835C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803835C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803835C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803835CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803835D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803835D4: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x803835D8: beql        $a2, $zero, L_803835EC
    if (ctx->r6 == 0) {
        // 0x803835DC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_803835EC;
    }
    goto skip_0;
    // 0x803835DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803835E0: jal         0x80371764
    // 0x803835E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x803835E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x803835E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_803835EC:
    // 0x803835EC: jal         0x803716D8
    // 0x803835F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_ovl8_803716D8(rdram, ctx);
        goto after_1;
    // 0x803835F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_1:
    // 0x803835F4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x803835F8: sw          $v0, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r2;
    // 0x803835FC: beq         $v0, $zero, L_8038360C
    if (ctx->r2 == 0) {
        // 0x80383600: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8038360C;
    }
    // 0x80383600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383604: b           L_80383610
    // 0x80383608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80383610;
    // 0x80383608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8038360C:
    // 0x8038360C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80383610:
    // 0x80383610: jr          $ra
    // 0x80383614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80383614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void syVectorReflectAcross3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019818: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001981C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019820: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019824: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019828: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001982C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019830: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019834: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80019838: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8001983C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80019840: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019844: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80019848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001984C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019850: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80019854: nop

    // 0x80019858: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001985C: add.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x80019860: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80019864: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019868: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001986C: add.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80019870: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80019874: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019878: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001987C: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80019880: jr          $ra
    // 0x80019884: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80019884: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftMarioSpecialAirLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156910: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80156914: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80156918: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015691C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80156920: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80156924: jal         0x801567A4
    // 0x80156928: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    ftMarioSpecialAirLwSetDisableRise(rdram, ctx);
        goto after_0;
    // 0x80156928: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015692C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156930: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80156934: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156938: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015693C: jal         0x800E6F24
    // 0x80156940: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80156940: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80156944: jal         0x800E0830
    // 0x80156948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80156948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015694C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80156950: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80156954: lw          $t7, 0xADC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XADC);
    // 0x80156958: beql        $t7, $zero, L_80156970
    if (ctx->r15 == 0) {
        // 0x8015695C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80156970;
    }
    goto skip_0;
    // 0x8015695C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80156960: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80156964: b           L_80156978
    // 0x80156968: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
        goto L_80156978;
    // 0x80156968: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8015696C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80156970:
    // 0x80156970: nop

    // 0x80156974: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80156978:
    // 0x80156978: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015697C: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    // 0x80156980: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80156984: jal         0x800D8E78
    // 0x80156988: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_3;
    // 0x80156988: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    after_3:
    // 0x8015698C: jal         0x8015686C
    // 0x80156990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMarioSpecialLwInitStatusVars(rdram, ctx);
        goto after_4;
    // 0x80156990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80156994: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80156998: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015699C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801569A0: jr          $ra
    // 0x801569A4: nop

    return;
    // 0x801569A4: nop

;}
RECOMP_FUNC void scSubsysControllerCheckConnected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390700: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80390704: lb          $t6, 0x51A4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X51A4);
    // 0x80390708: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8039070C: bne         $a0, $t6, L_8039071C
    if (ctx->r4 != ctx->r14) {
        // 0x80390710: nop
    
            goto L_8039071C;
    }
    // 0x80390710: nop

    // 0x80390714: jr          $ra
    // 0x80390718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80390718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8039071C:
    // 0x8039071C: lb          $t7, 0x51A5($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X51A5);
    // 0x80390720: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80390724: bne         $a0, $t7, L_80390734
    if (ctx->r4 != ctx->r15) {
        // 0x80390728: nop
    
            goto L_80390734;
    }
    // 0x80390728: nop

    // 0x8039072C: jr          $ra
    // 0x80390730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80390730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390734:
    // 0x80390734: lb          $t8, 0x51A6($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X51A6);
    // 0x80390738: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8039073C: bne         $a0, $t8, L_8039074C
    if (ctx->r4 != ctx->r24) {
        // 0x80390740: nop
    
            goto L_8039074C;
    }
    // 0x80390740: nop

    // 0x80390744: jr          $ra
    // 0x80390748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80390748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8039074C:
    // 0x8039074C: lb          $t9, 0x51A7($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X51A7);
    // 0x80390750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80390754: bne         $a0, $t9, L_80390764
    if (ctx->r4 != ctx->r25) {
        // 0x80390758: nop
    
            goto L_80390764;
    }
    // 0x80390758: nop

    // 0x8039075C: jr          $ra
    // 0x80390760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80390760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390764:
    // 0x80390764: jr          $ra
    // 0x80390768: nop

    return;
    // 0x80390768: nop

;}
RECOMP_FUNC void itFFlowerWeaponFlameMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175F48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80175F4C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80175F50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80175F54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80175F58: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80175F5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175F60: addiu       $a1, $a1, -0x62CC
    ctx->r5 = ADD32(ctx->r5, -0X62CC);
    // 0x80175F64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80175F68: jal         0x801655C8
    // 0x80175F6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80175F6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80175F70: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80175F74: bne         $v0, $zero, L_80175F84
    if (ctx->r2 != 0) {
        // 0x80175F78: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80175F84;
    }
    // 0x80175F78: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80175F7C: b           L_80176038
    // 0x80175F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80176038;
    // 0x80175F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80175F84:
    // 0x80175F84: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x80175F88: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80175F8C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80175F90: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    // 0x80175F94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80175F98: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80175F9C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80175FA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80175FA4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80175FA8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80175FAC: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80175FB0: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80175FB4: swc1        $f16, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f16.u32l;
    // 0x80175FB8: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80175FBC: sw          $t7, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r15;
    // 0x80175FC0: swc1        $f18, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f18.u32l;
    // 0x80175FC4: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80175FC8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80175FCC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80175FD0: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80175FD4: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80175FD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80175FDC: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80175FE0: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80175FE4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80175FE8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80175FEC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x80175FF0: jal         0x800CE8C0
    // 0x80175FF4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x80175FF4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80175FF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80175FFC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80176000: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80176004: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80176008: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8017600C: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80176010: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80176014: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80176018: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017601C: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80176020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80176024: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80176028: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8017602C: jal         0x800CE8C0
    // 0x80176030: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x80176030: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80176034: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_80176038:
    // 0x80176038: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017603C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80176040: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80176044: jr          $ra
    // 0x80176048: nop

    return;
    // 0x80176048: nop

;}
RECOMP_FUNC void itEggDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801818B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801818BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801818C0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801818C4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801818C8: addiu       $a3, $a3, 0x16E0
    ctx->r7 = ADD32(ctx->r7, 0X16E0);
    // 0x801818CC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801818D0: jal         0x80173B24
    // 0x801818D4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801818D4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x801818D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801818DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801818E0: jr          $ra
    // 0x801818E4: nop

    return;
    // 0x801818E4: nop

;}
RECOMP_FUNC void ftKirbySpecialNThrowUpdateCheckThrowStar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162260: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80162264: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80162268: lw          $t6, 0x184($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X184);
    // 0x8016226C: beql        $t6, $zero, L_801622D0
    if (ctx->r14 == 0) {
        // 0x80162270: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801622D0;
    }
    goto skip_0;
    // 0x80162270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80162274: lw          $a0, 0x840($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X840);
    // 0x80162278: beql        $a0, $zero, L_801622D0
    if (ctx->r4 == 0) {
        // 0x8016227C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801622D0;
    }
    goto skip_1;
    // 0x8016227C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80162280: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80162284: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80162288: jal         0x8014C508
    // 0x8016228C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftCommonThrownKirbyStarSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016228C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80162290: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80162294: jal         0x800E80C4
    // 0x80162298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftParamSetThrowParams(rdram, ctx);
        goto after_1;
    // 0x80162298: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016229C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801622A0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801622A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801622A8: lw          $t7, 0x44($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X44);
    // 0x801622AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801622B0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x801622B4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801622B8: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    // 0x801622BC: swc1        $f0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f0.u32l;
    // 0x801622C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801622C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801622C8: swc1        $f10, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f10.u32l;
    // 0x801622CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801622D0:
    // 0x801622D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801622D4: jr          $ra
    // 0x801622D8: nop

    return;
    // 0x801622D8: nop

;}
RECOMP_FUNC void ftComputerProcessTrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A63C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013A640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A644: lbu         $t6, 0x1D1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D1);
    // 0x8013A648: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x8013A64C: beq         $at, $zero, L_8013A824
    if (ctx->r1 == 0) {
        // 0x8013A650: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8013A824;
    }
    // 0x8013A650: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013A654: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013A658: addu        $at, $at, $t6
    gpr jr_addend_8013A660 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013A65C: lw          $t6, -0x4004($at)
    ctx->r14 = ADD32(ctx->r1, -0X4004);
    // 0x8013A660: jr          $t6
    // 0x8013A664: nop

    switch (jr_addend_8013A660 >> 2) {
        case 0: goto L_8013A668; break;
        case 1: goto L_8013A784; break;
        case 2: goto L_8013A7B8; break;
        case 3: goto L_8013A7C4; break;
        case 4: goto L_8013A7D0; break;
        case 5: goto L_8013A7DC; break;
        case 6: goto L_8013A7FC; break;
        case 7: goto L_8013A804; break;
        case 8: goto L_8013A810; break;
        case 9: goto L_8013A81C; break;
        case 10: goto L_8013A824; break;
        default: switch_error(__func__, 0x8013A660, 0x8018BFFC);
    }
    // 0x8013A664: nop

L_8013A668:
    // 0x8013A668: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A66C: lhu         $t7, 0x14($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X14);
    // 0x8013A670: bnel        $t7, $zero, L_8013A828
    if (ctx->r15 != 0) {
        // 0x8013A674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013A828;
    }
    goto skip_0;
    // 0x8013A674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013A678: jal         0x80018948
    // 0x8013A67C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8013A67C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013A680: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8013A684: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8013A688: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013A68C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013A690: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8013A694: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A698: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8013A69C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8013A6A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8013A6A4: nop

    // 0x8013A6A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8013A6AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8013A6B0: nop

    // 0x8013A6B4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8013A6B8: beql        $t9, $zero, L_8013A708
    if (ctx->r25 == 0) {
        // 0x8013A6BC: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_8013A708;
    }
    goto skip_1;
    // 0x8013A6BC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8013A6C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013A6C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013A6C8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8013A6CC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8013A6D0: nop

    // 0x8013A6D4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8013A6D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8013A6DC: nop

    // 0x8013A6E0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8013A6E4: bne         $t9, $zero, L_8013A6FC
    if (ctx->r25 != 0) {
        // 0x8013A6E8: nop
    
            goto L_8013A6FC;
    }
    // 0x8013A6E8: nop

    // 0x8013A6EC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8013A6F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A6F4: b           L_8013A714
    // 0x8013A6F8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8013A714;
    // 0x8013A6F8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8013A6FC:
    // 0x8013A6FC: b           L_8013A714
    // 0x8013A700: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8013A714;
    // 0x8013A700: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8013A704: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_8013A708:
    // 0x8013A708: nop

    // 0x8013A70C: bltz        $t9, L_8013A6FC
    if (SIGNED(ctx->r25) < 0) {
        // 0x8013A710: nop
    
            goto L_8013A6FC;
    }
    // 0x8013A710: nop

L_8013A714:
    // 0x8013A714: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8013A718: jal         0x80018910
    // 0x8013A71C: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    syUtilsRandUShort(rdram, ctx);
        goto after_1;
    // 0x8013A71C: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    after_1:
    // 0x8013A720: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
    // 0x8013A724: beq         $a0, $zero, L_8013A754
    if (ctx->r4 == 0) {
        // 0x8013A728: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8013A754;
    }
    // 0x8013A728: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A72C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A730: beq         $a0, $at, L_8013A75C
    if (ctx->r4 == ctx->r1) {
        // 0x8013A734: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_8013A75C;
    }
    // 0x8013A734: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013A738: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013A73C: beq         $a0, $at, L_8013A764
    if (ctx->r4 == ctx->r1) {
        // 0x8013A740: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8013A764;
    }
    // 0x8013A740: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013A744: beq         $a0, $at, L_8013A77C
    if (ctx->r4 == ctx->r1) {
        // 0x8013A748: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8013A77C;
    }
    // 0x8013A748: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8013A74C: b           L_8013A828
    // 0x8013A750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A828;
    // 0x8013A750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A754:
    // 0x8013A754: b           L_8013A824
    // 0x8013A758: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
        goto L_8013A824;
    // 0x8013A758: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
L_8013A75C:
    // 0x8013A75C: b           L_8013A824
    // 0x8013A760: sb          $t0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r8;
        goto L_8013A824;
    // 0x8013A760: sb          $t0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r8;
L_8013A764:
    // 0x8013A764: lhu         $t2, 0x14($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X14);
    // 0x8013A768: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8013A76C: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x8013A770: srl         $t3, $t2, 2
    ctx->r11 = S32(U32(ctx->r10) >> 2);
    // 0x8013A774: b           L_8013A824
    // 0x8013A778: sh          $t3, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r11;
        goto L_8013A824;
    // 0x8013A778: sh          $t3, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r11;
L_8013A77C:
    // 0x8013A77C: b           L_8013A824
    // 0x8013A780: sb          $t4, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r12;
        goto L_8013A824;
    // 0x8013A780: sb          $t4, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r12;
L_8013A784:
    // 0x8013A784: lw          $t5, 0x2C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2C);
    // 0x8013A788: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A78C: slti        $at, $t5, 0xE
    ctx->r1 = SIGNED(ctx->r13) < 0XE ? 1 : 0;
    // 0x8013A790: beq         $at, $zero, L_8013A7A8
    if (ctx->r1 == 0) {
        // 0x8013A794: nop
    
            goto L_8013A7A8;
    }
    // 0x8013A794: nop

    // 0x8013A798: lhu         $t6, 0x14($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X14);
    // 0x8013A79C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8013A7A0: bne         $t6, $zero, L_8013A7B0
    if (ctx->r14 != 0) {
        // 0x8013A7A4: nop
    
            goto L_8013A7B0;
    }
    // 0x8013A7A4: nop

L_8013A7A8:
    // 0x8013A7A8: b           L_8013A824
    // 0x8013A7AC: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
        goto L_8013A824;
    // 0x8013A7AC: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
L_8013A7B0:
    // 0x8013A7B0: b           L_8013A824
    // 0x8013A7B4: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
        goto L_8013A824;
    // 0x8013A7B4: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
L_8013A7B8:
    // 0x8013A7B8: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8013A7BC: b           L_8013A824
    // 0x8013A7C0: sb          $t8, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r24;
        goto L_8013A824;
    // 0x8013A7C0: sb          $t8, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r24;
L_8013A7C4:
    // 0x8013A7C4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8013A7C8: b           L_8013A824
    // 0x8013A7CC: sb          $t9, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r25;
        goto L_8013A824;
    // 0x8013A7CC: sb          $t9, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r25;
L_8013A7D0:
    // 0x8013A7D0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8013A7D4: b           L_8013A824
    // 0x8013A7D8: sb          $t0, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r8;
        goto L_8013A824;
    // 0x8013A7D8: sb          $t0, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r8;
L_8013A7DC:
    // 0x8013A7DC: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8013A7E0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8013A7E4: bne         $t1, $zero, L_8013A7F4
    if (ctx->r9 != 0) {
        // 0x8013A7E8: nop
    
            goto L_8013A7F4;
    }
    // 0x8013A7E8: nop

    // 0x8013A7EC: b           L_8013A824
    // 0x8013A7F0: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
        goto L_8013A824;
    // 0x8013A7F0: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
L_8013A7F4:
    // 0x8013A7F4: b           L_8013A824
    // 0x8013A7F8: sb          $t2, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r10;
        goto L_8013A824;
    // 0x8013A7F8: sb          $t2, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r10;
L_8013A7FC:
    // 0x8013A7FC: b           L_8013A824
    // 0x8013A800: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
        goto L_8013A824;
    // 0x8013A800: sb          $zero, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = 0;
L_8013A804:
    // 0x8013A804: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8013A808: b           L_8013A824
    // 0x8013A80C: sb          $t3, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r11;
        goto L_8013A824;
    // 0x8013A80C: sb          $t3, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r11;
L_8013A810:
    // 0x8013A810: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x8013A814: b           L_8013A824
    // 0x8013A818: sb          $t4, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r12;
        goto L_8013A824;
    // 0x8013A818: sb          $t4, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r12;
L_8013A81C:
    // 0x8013A81C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8013A820: sb          $t5, 0x1CF($a0)
    MEM_B(0X1CF, ctx->r4) = ctx->r13;
L_8013A824:
    // 0x8013A824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A828:
    // 0x8013A828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013A82C: jr          $ra
    // 0x8013A830: nop

    return;
    // 0x8013A830: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeTotalTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C1C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80133C20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133C24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80133C28: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133C2C: addiu       $t7, $t7, 0x73EC
    ctx->r15 = ADD32(ctx->r15, 0X73EC);
    // 0x80133C30: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133C34: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80133C38: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133C3C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133C40: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133C44: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133C48: addiu       $t2, $t2, 0x73F8
    ctx->r10 = ADD32(ctx->r10, 0X73F8);
    // 0x80133C4C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133C50: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133C54: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80133C58: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80133C5C: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x80133C60: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80133C64: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80133C68: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80133C6C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80133C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133C74: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80133C78: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80133C7C: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80133C80: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80133C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C88: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80133C8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133C90: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80133C94: jal         0x80009968
    // 0x80133C98: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133C98: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    after_0:
    // 0x80133C9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CA0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133CA4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133CA8: sw          $v0, 0x771C($at)
    MEM_W(0X771C, ctx->r1) = ctx->r2;
    // 0x80133CAC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133CB0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80133CB4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133CBC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80133CC0: jal         0x80009DF4
    // 0x80133CC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133CC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133CC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133CCC: lw          $t6, 0x7E0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E0C);
    // 0x80133CD0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133CD4: addiu       $t7, $t7, 0x1410
    ctx->r15 = ADD32(ctx->r15, 0X1410);
    // 0x80133CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CDC: jal         0x800CCFDC
    // 0x80133CE0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133CE0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80133CE4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80133CE8: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x80133CEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133CF0: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x80133CF4: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80133CF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133CFC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133D00: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133D04: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x80133D08: addiu       $t4, $zero, 0x7C
    ctx->r12 = ADD32(0, 0X7C);
    // 0x80133D0C: addiu       $t5, $zero, 0x77
    ctx->r13 = ADD32(0, 0X77);
    // 0x80133D10: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133D14: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133D18: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80133D1C: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133D20: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133D24: jal         0x80133648
    // 0x80133D28: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    mnPlayers1PBonusGetTotalCSec(rdram, ctx);
        goto after_3;
    // 0x80133D28: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x80133D2C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80133D30: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80133D34: mflo        $t6
    ctx->r14 = lo;
    // 0x80133D38: mfhi        $a1
    ctx->r5 = hi;
    // 0x80133D3C: lui         $a2, 0x438D
    ctx->r6 = S32(0X438D << 16);
    // 0x80133D40: bne         $v1, $zero, L_80133D4C
    if (ctx->r3 != 0) {
        // 0x80133D44: nop
    
            goto L_80133D4C;
    }
    // 0x80133D44: nop

    // 0x80133D48: break       7
    do_break(2148744520);
L_80133D4C:
    // 0x80133D4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133D50: bne         $v1, $at, L_80133D64
    if (ctx->r3 != ctx->r1) {
        // 0x80133D54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133D64;
    }
    // 0x80133D54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133D58: bne         $v0, $at, L_80133D64
    if (ctx->r2 != ctx->r1) {
        // 0x80133D5C: nop
    
            goto L_80133D64;
    }
    // 0x80133D5C: nop

    // 0x80133D60: break       6
    do_break(2148744544);
L_80133D64:
    // 0x80133D64: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80133D68: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80133D6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133D70: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80133D74: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80133D78: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80133D7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133D80: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133D88: jal         0x80131CEC
    // 0x80133D8C: lui         $a3, 0x434E
    ctx->r7 = S32(0X434E << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_4;
    // 0x80133D8C: lui         $a3, 0x434E
    ctx->r7 = S32(0X434E << 16);
    after_4:
    // 0x80133D90: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133D94: lw          $t1, 0x7E0C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7E0C);
    // 0x80133D98: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80133D9C: addiu       $t2, $t2, 0x1FC8
    ctx->r10 = ADD32(ctx->r10, 0X1FC8);
    // 0x80133DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133DA4: jal         0x800CCFDC
    // 0x80133DA8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80133DA8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_5:
    // 0x80133DAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DB0: lwc1        $f8, 0x75E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75E8);
    // 0x80133DB4: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80133DB8: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x80133DBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133DC0: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80133DC4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80133DC8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80133DCC: addiu       $t7, $zero, 0x7E
    ctx->r15 = ADD32(0, 0X7E);
    // 0x80133DD0: addiu       $t8, $zero, 0x7C
    ctx->r24 = ADD32(0, 0X7C);
    // 0x80133DD4: addiu       $t9, $zero, 0x77
    ctx->r25 = ADD32(0, 0X77);
    // 0x80133DD8: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80133DDC: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80133DE0: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80133DE4: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80133DE8: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80133DEC: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80133DF0: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80133DF4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80133DF8: jal         0x801335DC
    // 0x80133DFC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    mnPlayers1PBonusGetTotalSec(rdram, ctx);
        goto after_6;
    // 0x80133DFC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_6:
    // 0x80133E00: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80133E04: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80133E08: lui         $a2, 0x4381
    ctx->r6 = S32(0X4381 << 16);
    // 0x80133E0C: addiu       $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x80133E10: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x80133E14: div         $zero, $v1, $t0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r8)));
    // 0x80133E18: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80133E1C: mflo        $t2
    ctx->r10 = lo;
    // 0x80133E20: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80133E24: bne         $t0, $zero, L_80133E30
    if (ctx->r8 != 0) {
        // 0x80133E28: nop
    
            goto L_80133E30;
    }
    // 0x80133E28: nop

    // 0x80133E2C: break       7
    do_break(2148744748);
L_80133E30:
    // 0x80133E30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133E34: bne         $t0, $at, L_80133E48
    if (ctx->r8 != ctx->r1) {
        // 0x80133E38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133E48;
    }
    // 0x80133E38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133E3C: bne         $v1, $at, L_80133E48
    if (ctx->r3 != ctx->r1) {
        // 0x80133E40: nop
    
            goto L_80133E48;
    }
    // 0x80133E40: nop

    // 0x80133E44: break       6
    do_break(2148744772);
L_80133E48:
    // 0x80133E48: div         $zero, $a1, $t0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r8)));
    // 0x80133E4C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80133E50: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80133E54: bne         $t0, $zero, L_80133E60
    if (ctx->r8 != 0) {
        // 0x80133E58: nop
    
            goto L_80133E60;
    }
    // 0x80133E58: nop

    // 0x80133E5C: break       7
    do_break(2148744796);
L_80133E60:
    // 0x80133E60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133E64: bne         $t0, $at, L_80133E78
    if (ctx->r8 != ctx->r1) {
        // 0x80133E68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133E78;
    }
    // 0x80133E68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133E6C: bne         $a1, $at, L_80133E78
    if (ctx->r5 != ctx->r1) {
        // 0x80133E70: nop
    
            goto L_80133E78;
    }
    // 0x80133E70: nop

    // 0x80133E74: break       6
    do_break(2148744820);
L_80133E78:
    // 0x80133E78: mfhi        $a1
    ctx->r5 = hi;
    // 0x80133E7C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80133E80: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133E84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80133E88: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E90: jal         0x80131CEC
    // 0x80133E94: lui         $a3, 0x434E
    ctx->r7 = S32(0X434E << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_7;
    // 0x80133E94: lui         $a3, 0x434E
    ctx->r7 = S32(0X434E << 16);
    after_7:
    // 0x80133E98: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133E9C: lw          $t6, 0x7E0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E0C);
    // 0x80133EA0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133EA4: addiu       $t7, $t7, 0x1F48
    ctx->r15 = ADD32(ctx->r15, 0X1F48);
    // 0x80133EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EAC: jal         0x800CCFDC
    // 0x80133EB0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x80133EB0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_8:
    // 0x80133EB4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80133EB8: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x80133EBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133EC0: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x80133EC4: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80133EC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133ECC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133ED0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133ED4: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x80133ED8: addiu       $t4, $zero, 0x7C
    ctx->r12 = ADD32(0, 0X7C);
    // 0x80133EDC: addiu       $t5, $zero, 0x77
    ctx->r13 = ADD32(0, 0X77);
    // 0x80133EE0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133EE4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80133EE8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80133EEC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80133EF0: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133EF4: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80133EF8: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133EFC: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80133F00: jal         0x80133570
    // 0x80133F04: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    mnPlayers1PBonusGetTotalMins(rdram, ctx);
        goto after_9;
    // 0x80133F04: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    after_9:
    // 0x80133F08: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80133F0C: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80133F10: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80133F14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133F18: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80133F1C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80133F20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F28: lui         $a2, 0x436D
    ctx->r6 = S32(0X436D << 16);
    // 0x80133F2C: lui         $a3, 0x434E
    ctx->r7 = S32(0X434E << 16);
    // 0x80133F30: jal         0x80131CEC
    // 0x80133F34: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_10;
    // 0x80133F34: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    after_10:
    // 0x80133F38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80133F3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133F40: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80133F44: jr          $ra
    // 0x80133F48: nop

    return;
    // 0x80133F48: nop

;}
RECOMP_FUNC void func_ovl8_80375050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80375054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375058: jal         0x80373160
    // 0x8037505C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x8037505C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80375060: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80375064: beq         $v0, $zero, L_803750BC
    if (ctx->r2 == 0) {
        // 0x80375068: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_803750BC;
    }
    // 0x80375068: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8037506C: beql        $v0, $zero, L_803750C0
    if (ctx->r2 == 0) {
        // 0x80375070: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803750C0;
    }
    goto skip_0;
    // 0x80375070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80375074: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
L_80375078:
    // 0x80375078: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8037507C: sw          $t8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r24;
    // 0x80375080: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80375084: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x80375088: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8037508C: sw          $t8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r24;
    // 0x80375090: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80375094: sw          $t7, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r15;
    // 0x80375098: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x8037509C: sw          $t8, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r24;
    // 0x803750A0: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x803750A4: sw          $t7, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r15;
    // 0x803750A8: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    // 0x803750AC: sw          $t8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r24;
    // 0x803750B0: lw          $v1, 0x28($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X28);
    // 0x803750B4: bnel        $v1, $zero, L_80375078
    if (ctx->r3 != 0) {
        // 0x803750B8: lw          $t6, 0x38($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X38);
            goto L_80375078;
    }
    goto skip_1;
    // 0x803750B8: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    skip_1:
L_803750BC:
    // 0x803750BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803750C0:
    // 0x803750C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803750C4: jr          $ra
    // 0x803750C8: nop

    return;
    // 0x803750C8: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137EFC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80137F00: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80137F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137F08: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80137F0C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80137F10: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137F14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137F18: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x80137F1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80137F20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80137F24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80137F28: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80137F2C: jal         0x800EC0EC
    // 0x80137F30: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80137F30: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x80137F34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80137F38: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80137F3C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80137F40: jal         0x80134674
    // 0x80137F44: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnPlayersVSCheckCostumeUsed(rdram, ctx);
        goto after_1;
    // 0x80137F44: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80137F48: beq         $v0, $zero, L_80137F60
    if (ctx->r2 == 0) {
        // 0x80137F4C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80137F60;
    }
    // 0x80137F4C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80137F50: jal         0x800269C0
    // 0x80137F54: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80137F54: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_2:
    // 0x80137F58: b           L_80137F8C
    // 0x80137F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80137F8C;
    // 0x80137F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80137F60:
    // 0x80137F60: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    // 0x80137F64: jal         0x80131B78
    // 0x80137F68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    mnPlayersVSGetShade(rdram, ctx);
        goto after_3;
    // 0x80137F68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80137F6C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80137F70: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80137F74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80137F78: jal         0x800E9248
    // 0x80137F7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_4;
    // 0x80137F7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80137F80: jal         0x800269C0
    // 0x80137F84: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80137F84: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_5:
    // 0x80137F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80137F8C:
    // 0x80137F8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137F90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80137F94: jr          $ra
    // 0x80137F98: nop

    return;
    // 0x80137F98: nop

;}
RECOMP_FUNC void func_ovl8_8037CA48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CA48: jr          $ra
    // 0x8037CA4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8037CA4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mvOpeningPikachuMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D634: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D638: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D63C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D640: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D644: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D648: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D64C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D650: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D654: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D658: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D65C: jal         0x80104BDC
    // 0x8018D660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D664: jal         0x80105600
    // 0x8018D668: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D668: nop

    after_1:
    // 0x8018D66C: jal         0x800FC7A4
    // 0x8018D670: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D670: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D678: beq         $v0, $at, L_8018D6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D67C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D6A0;
    }
    // 0x8018D67C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D680: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D684: addiu       $s0, $s0, -0x1E10
    ctx->r16 = ADD32(ctx->r16, -0X1E10);
L_8018D688:
    // 0x8018D688: jal         0x80023624
    // 0x8018D68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D68C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D690: jal         0x800A3040
    // 0x8018D694: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D694: nop

    after_4:
    // 0x8018D698: b           L_8018D688
    // 0x8018D69C: nop

        goto L_8018D688;
    // 0x8018D69C: nop

L_8018D6A0:
    // 0x8018D6A0: jal         0x800FC814
    // 0x8018D6A4: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D6A4: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D6A8: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D6AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D6B0: jal         0x800FC894
    // 0x8018D6B4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D6B4: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D6B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6BC: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D6C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D6C4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D6C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D6CC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6D0: jal         0x8018D42C
    // 0x8018D6D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningPikachuMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6D8: jal         0x801156E4
    // 0x8018D6DC: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6DC: nop

    after_8:
    // 0x8018D6E0: jal         0x801653E0
    // 0x8018D6E4: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6E4: nop

    after_9:
    // 0x8018D6E8: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6EC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6F0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D6F4: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D6F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D6FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D700: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D704: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D708: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D70C:
    // 0x8018D70C: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D710: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D714: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D718:
    // 0x8018D718: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D71C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D720: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D724: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D728: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D72C: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D730: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D734: bne         $t0, $t2, L_8018D718
    if (ctx->r8 != ctx->r10) {
        // 0x8018D738: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D718;
    }
    // 0x8018D738: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D73C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D740: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D744: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D748: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D74C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D750: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D754: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D758: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D75C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D760: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D764: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D768: beql        $s7, $t4, L_8018D82C
    if (ctx->r23 == ctx->r12) {
        // 0x8018D76C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D82C;
    }
    goto skip_0;
    // 0x8018D76C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D770: jal         0x800D786C
    // 0x8018D774: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D774: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D778: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D77C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D780: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D784: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D788: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D78C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D790: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D794: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D798: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8018D79C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018D7A0: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D7A4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D7A8: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D7AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D7B0: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D7B4: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D7B8: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D7BC: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D7C0: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D7C4: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D7C8: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D7CC: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7D0: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D7D4: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7D8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D7DC: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7E0: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7E4: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7E8: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7EC: jal         0x800D78B4
    // 0x8018D7F0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7F0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7F4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D7F8: jal         0x800D7F3C
    // 0x8018D7FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D7FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D800: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D804: sw          $v0, -0x1DD0($at)
    MEM_W(-0X1DD0, ctx->r1) = ctx->r2;
    // 0x8018D808: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D80C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D810: jal         0x800E7C4C
    // 0x8018D814: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D814: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D818: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D81C: addiu       $a1, $a1, -0x1F08
    ctx->r5 = ADD32(ctx->r5, -0X1F08);
    // 0x8018D820: jal         0x800E9B30
    // 0x8018D824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D828: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D82C:
    // 0x8018D82C: bne         $s1, $fp, L_8018D70C
    if (ctx->r17 != ctx->r30) {
        // 0x8018D830: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D70C;
    }
    // 0x8018D830: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D834: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D83C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D840: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D844: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D848: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D84C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D850: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D854: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D858: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D85C: jr          $ra
    // 0x8018D860: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D860: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void ftCommonLandingFallSpecialSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142E3C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80142E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142E48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80142E4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80142E50: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80142E54: jal         0x80142D44
    // 0x80142E58: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    ftCommonLandingSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80142E58: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_0:
    // 0x80142E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142E64: jr          $ra
    // 0x80142E68: nop

    return;
    // 0x80142E68: nop

;}
RECOMP_FUNC void __n_CSPVoiceHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD2C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002BD30: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002BD34: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002BD38: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x8002BD3C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8002BD40: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002BD44: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002BD48: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002BD4C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002BD50: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002BD54: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002BD58: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002BD5C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002BD60: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8002BD64: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8002BD68: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8002BD6C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8002BD70: addiu       $s4, $a0, 0x50
    ctx->r20 = ADD32(ctx->r4, 0X50);
L_8002BD74:
    // 0x8002BD74: lhu         $t7, 0x40($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X40);
    // 0x8002BD78: sltiu       $at, $t7, 0x1A
    ctx->r1 = ctx->r15 < 0X1A ? 1 : 0;
    // 0x8002BD7C: beq         $at, $zero, L_8002C350
    if (ctx->r1 == 0) {
        // 0x8002BD80: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8002C350;
    }
    // 0x8002BD80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002BD84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002BD88: addu        $at, $at, $t7
    gpr jr_addend_8002BD90 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8002BD8C: lw          $t7, -0x126C($at)
    ctx->r15 = ADD32(ctx->r1, -0X126C);
    // 0x8002BD90: jr          $t7
    // 0x8002BD94: nop

    switch (jr_addend_8002BD90 >> 2) {
        case 0: goto L_8002BD98; break;
        case 1: goto L_8002C350; break;
        case 2: goto L_8002C0F4; break;
        case 3: goto L_8002C350; break;
        case 4: goto L_8002C350; break;
        case 5: goto L_8002BE80; break;
        case 6: goto L_8002BEC4; break;
        case 7: goto L_8002C114; break;
        case 8: goto L_8002C350; break;
        case 9: goto L_8002BE60; break;
        case 10: goto L_8002C12C; break;
        case 11: goto L_8002C350; break;
        case 12: goto L_8002C2B8; break;
        case 13: goto L_8002C2DC; break;
        case 14: goto L_8002C310; break;
        case 15: goto L_8002C184; break;
        case 16: goto L_8002C1B0; break;
        case 17: goto L_8002C21C; break;
        case 18: goto L_8002C350; break;
        case 19: goto L_8002C350; break;
        case 20: goto L_8002C350; break;
        case 21: goto L_8002C0F4; break;
        case 22: goto L_8002BF20; break;
        case 23: goto L_8002C020; break;
        case 24: goto L_8002C328; break;
        case 25: goto L_8002C340; break;
        default: switch_error(__func__, 0x8002BD90, 0x8003ED94);
    }
    // 0x8002BD94: nop

L_8002BD98:
    // 0x8002BD98: lw          $a0, 0x18($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X18);
    // 0x8002BD9C: beql        $a0, $zero, L_8002C354
    if (ctx->r4 == 0) {
        // 0x8002BDA0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8002C354;
    }
    goto skip_0;
    // 0x8002BDA0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x8002BDA4: jal         0x8002858C
    // 0x8002BDA8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    n_alCSeqNextEvent(rdram, ctx);
        goto after_0;
    // 0x8002BDA8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_0:
    // 0x8002BDAC: lh          $t8, 0x68($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X68);
    // 0x8002BDB0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002BDB4: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x8002BDB8: beq         $at, $zero, L_8002C350
    if (ctx->r1 == 0) {
        // 0x8002BDBC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8002C350;
    }
    // 0x8002BDBC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002BDC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002BDC4: addu        $at, $at, $t9
    gpr jr_addend_8002BDCC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002BDC8: lw          $t9, -0x1204($at)
    ctx->r25 = ADD32(ctx->r1, -0X1204);
    // 0x8002BDCC: jr          $t9
    // 0x8002BDD0: nop

    switch (jr_addend_8002BDCC >> 2) {
        case 0: goto L_8002BDD4; break;
        case 1: goto L_8002C350; break;
        case 2: goto L_8002BE00; break;
        case 3: goto L_8002BE24; break;
        case 4: goto L_8002C350; break;
        case 5: goto L_8002C350; break;
        case 6: goto L_8002C350; break;
        case 7: goto L_8002C350; break;
        case 8: goto L_8002C350; break;
        case 9: goto L_8002C350; break;
        case 10: goto L_8002C350; break;
        case 11: goto L_8002C350; break;
        case 12: goto L_8002C350; break;
        case 13: goto L_8002C350; break;
        case 14: goto L_8002C350; break;
        case 15: goto L_8002C350; break;
        case 16: goto L_8002C350; break;
        case 17: goto L_8002BE50; break;
        case 18: goto L_8002BE50; break;
        case 19: goto L_8002BE50; break;
        default: switch_error(__func__, 0x8002BDCC, 0x8003EDFC);
    }
    // 0x8002BDD0: nop

L_8002BDD4:
    // 0x8002BDD4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
    // 0x8002BDD8: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
    // 0x8002BDDC: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8002BDE0: jal         0x8002B308
    // 0x8002BDE4: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    __n_CSPHandleMIDIMsg(rdram, ctx);
        goto after_1;
    // 0x8002BDE4: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    after_1:
    // 0x8002BDE8: lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB0);
    // 0x8002BDEC: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002BDF0: jal         0x80029100
    // 0x8002BDF4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80029100_29D00(rdram, ctx);
        goto after_2;
    // 0x8002BDF4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x8002BDF8: b           L_8002C354
    // 0x8002BDFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BDFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BE00:
    // 0x8002BE00: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
    // 0x8002BE04: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8002BE08: jal         0x800291AC
    // 0x8002BE0C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    __CSPHandleMetaMsg(rdram, ctx);
        goto after_3;
    // 0x8002BE0C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    after_3:
    // 0x8002BE10: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002BE14: jal         0x80029100
    // 0x8002BE18: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80029100_29D00(rdram, ctx);
        goto after_4;
    // 0x8002BE18: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_4:
    // 0x8002BE1C: b           L_8002C354
    // 0x8002BE20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BE20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BE24:
    // 0x8002BE24: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8002BE28: sw          $t6, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r14;
    // 0x8002BE2C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002BE30: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x8002BE34: sh          $t7, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r15;
    // 0x8002BE38: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8002BE3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002BE40: jal         0x80028D70
    // 0x8002BE44: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x8002BE44: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_5:
    // 0x8002BE48: b           L_8002C354
    // 0x8002BE4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BE4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BE50:
    // 0x8002BE50: jal         0x80029100
    // 0x8002BE54: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80029100_29D00(rdram, ctx);
        goto after_6;
    // 0x8002BE54: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_6:
    // 0x8002BE58: b           L_8002C354
    // 0x8002BE5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BE5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BE60:
    // 0x8002BE60: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8002BE64: sh          $t8, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r24;
    // 0x8002BE68: lw          $a2, 0x64($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X64);
    // 0x8002BE6C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002BE70: jal         0x80028D70
    // 0x8002BE74: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x8002BE74: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_7:
    // 0x8002BE78: b           L_8002C354
    // 0x8002BE7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BE7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BE80:
    // 0x8002BE80: lw          $s0, 0x44($fp)
    ctx->r16 = MEM_W(ctx->r30, 0X44);
    // 0x8002BE84: jal         0x8002D780
    // 0x8002BE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynStopVoice(rdram, ctx);
        goto after_8;
    // 0x8002BE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8002BE8C: jal         0x8002FEC0
    // 0x8002BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynFreeVoice(rdram, ctx);
        goto after_9;
    // 0x8002BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8002BE94: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8002BE98: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002BE9C: lbu         $t9, 0x37($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X37);
    // 0x8002BEA0: beql        $t9, $zero, L_8002BEB4
    if (ctx->r25 == 0) {
        // 0x8002BEA4: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002BEB4;
    }
    goto skip_1;
    // 0x8002BEA4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    skip_1:
    // 0x8002BEA8: jal         0x8002F39C
    // 0x8002BEAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __n_seqpStopOsc(rdram, ctx);
        goto after_10;
    // 0x8002BEAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x8002BEB0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8002BEB4:
    // 0x8002BEB4: jal         0x8002E1C4
    // 0x8002BEB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __n_unmapVoice(rdram, ctx);
        goto after_11;
    // 0x8002BEB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8002BEBC: b           L_8002C354
    // 0x8002BEC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BEC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BEC4:
    // 0x8002BEC4: lw          $s0, 0x44($fp)
    ctx->r16 = MEM_W(ctx->r30, 0X44);
    // 0x8002BEC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002BECC: lw          $s1, 0x10($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X10);
    // 0x8002BED0: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x8002BED4: bnel        $t6, $zero, L_8002BEE4
    if (ctx->r14 != 0) {
        // 0x8002BED8: lw          $s2, 0x48($fp)
        ctx->r18 = MEM_W(ctx->r30, 0X48);
            goto L_8002BEE4;
    }
    goto skip_2;
    // 0x8002BED8: lw          $s2, 0x48($fp)
    ctx->r18 = MEM_W(ctx->r30, 0X48);
    skip_2:
    // 0x8002BEDC: sb          $t7, 0x34($s1)
    MEM_B(0X34, ctx->r17) = ctx->r15;
    // 0x8002BEE0: lw          $s2, 0x48($fp)
    ctx->r18 = MEM_W(ctx->r30, 0X48);
L_8002BEE4:
    // 0x8002BEE4: lw          $t8, 0x1C($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X1C);
    // 0x8002BEE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002BEEC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8002BEF0: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002BEF4: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x8002BEF8: lbu         $t6, 0x4C($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X4C);
    // 0x8002BEFC: jal         0x8002DF48
    // 0x8002BF00: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    __n_vsVol(rdram, ctx);
        goto after_12;
    // 0x8002BF00: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    after_12:
    // 0x8002BF04: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8002BF08: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002BF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002BF10: jal         0x8002FF60
    // 0x8002BF14: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    n_alSynSetVol(rdram, ctx);
        goto after_13;
    // 0x8002BF14: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x8002BF18: b           L_8002C354
    // 0x8002BF1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002BF1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002BF20:
    // 0x8002BF20: lw          $t9, 0x80($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X80);
    // 0x8002BF24: lw          $s3, 0x48($fp)
    ctx->r19 = MEM_W(ctx->r30, 0X48);
    // 0x8002BF28: lw          $s1, 0x44($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X44);
    // 0x8002BF2C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8002BF30: jalr        $t9
    // 0x8002BF34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8002BF34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x8002BF38: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002BF3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002BF40: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002BF44: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002BF48: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002BF4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002BF50: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002BF54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002BF58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8002BF5C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002BF60: nop

    // 0x8002BF64: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002BF68: beql        $t8, $zero, L_8002BFB8
    if (ctx->r24 == 0) {
        // 0x8002BF6C: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_8002BFB8;
    }
    goto skip_3;
    // 0x8002BF6C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8002BF70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002BF74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002BF78: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002BF7C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002BF80: nop

    // 0x8002BF84: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002BF88: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002BF8C: nop

    // 0x8002BF90: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002BF94: bne         $t8, $zero, L_8002BFAC
    if (ctx->r24 != 0) {
        // 0x8002BF98: nop
    
            goto L_8002BFAC;
    }
    // 0x8002BF98: nop

    // 0x8002BF9C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002BFA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002BFA4: b           L_8002BFC4
    // 0x8002BFA8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002BFC4;
    // 0x8002BFA8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8002BFAC:
    // 0x8002BFAC: b           L_8002BFC4
    // 0x8002BFB0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002BFC4;
    // 0x8002BFB0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002BFB4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_8002BFB8:
    // 0x8002BFB8: nop

    // 0x8002BFBC: bltz        $t8, L_8002BFAC
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002BFC0: nop
    
            goto L_8002BFAC;
    }
    // 0x8002BFC0: nop

L_8002BFC4:
    // 0x8002BFC4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002BFC8: jal         0x8002DF48
    // 0x8002BFCC: sb          $t8, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r24;
    __n_vsVol(rdram, ctx);
        goto after_15;
    // 0x8002BFCC: sb          $t8, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r24;
    after_15:
    // 0x8002BFD0: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002BFD4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002BFD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002BFDC: jal         0x8002DF24
    // 0x8002BFE0: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    __n_vsDelta(rdram, ctx);
        goto after_16;
    // 0x8002BFE0: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    after_16:
    // 0x8002BFE4: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8002BFE8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002BFEC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8002BFF0: jal         0x8002FF60
    // 0x8002BFF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    n_alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x8002BFF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_17:
    // 0x8002BFF8: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x8002BFFC: sh          $t6, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r14;
    // 0x8002C000: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
    // 0x8002C004: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8002C008: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C00C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x8002C010: jal         0x80028D70
    // 0x8002C014: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x8002C014: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_18:
    // 0x8002C018: b           L_8002C354
    // 0x8002C01C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C01C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C020:
    // 0x8002C020: lw          $t9, 0x80($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X80);
    // 0x8002C024: lw          $s3, 0x48($fp)
    ctx->r19 = MEM_W(ctx->r30, 0X48);
    // 0x8002C028: lw          $s1, 0x44($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X44);
    // 0x8002C02C: lbu         $s0, 0x4C($fp)
    ctx->r16 = MEM_BU(ctx->r30, 0X4C);
    // 0x8002C030: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8002C034: jalr        $t9
    // 0x8002C038: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x8002C038: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x8002C03C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002C040: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8002C044: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8002C048: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
    // 0x8002C04C: lw          $t7, 0x68($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X68);
    // 0x8002C050: lwc1        $f24, 0x2C($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8002C054: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002C058: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8002C05C: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x8002C060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002C068: mtc1        $t6, $f22
    ctx->f22.u32l = ctx->r14;
    // 0x8002C06C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002C070: sub.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8002C074: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8002C078: bgez        $t6, L_8002C090
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002C07C: cvt.s.w     $f8, $f22
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.fl = CVT_S_W(ctx->f22.u32l);
            goto L_8002C090;
    }
    // 0x8002C07C: cvt.s.w     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8002C080: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002C084: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C088: nop

    // 0x8002C08C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8002C090:
    // 0x8002C090: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002C094: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8002C098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C09C: nop

    // 0x8002C0A0: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C0A4: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8002C0A8: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002C0AC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002C0B0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002C0B4: nop

    // 0x8002C0B8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8002C0BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8002C0C0: jal         0x8002FAB0
    // 0x8002C0C4: nop

    n_alSynSetPitch(rdram, ctx);
        goto after_20;
    // 0x8002C0C4: nop

    after_20:
    // 0x8002C0C8: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x8002C0CC: sh          $t9, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r25;
    // 0x8002C0D0: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
    // 0x8002C0D4: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8002C0D8: sb          $s0, 0xA8($sp)
    MEM_B(0XA8, ctx->r29) = ctx->r16;
    // 0x8002C0DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C0E0: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x8002C0E4: jal         0x80028D70
    // 0x8002C0E8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_21;
    // 0x8002C0E8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_21:
    // 0x8002C0EC: b           L_8002C354
    // 0x8002C0F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C0F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C0F4:
    // 0x8002C0F4: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
    // 0x8002C0F8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8002C0FC: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8002C100: jal         0x8002B308
    // 0x8002C104: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    __n_CSPHandleMIDIMsg(rdram, ctx);
        goto after_22;
    // 0x8002C104: sw          $fp, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r30;
    after_22:
    // 0x8002C108: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002C10C: b           L_8002C350
    // 0x8002C110: lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB0);
        goto L_8002C350;
    // 0x8002C110: lw          $fp, 0xB0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB0);
L_8002C114:
    // 0x8002C114: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
    // 0x8002C118: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8002C11C: jal         0x800291AC
    // 0x8002C120: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    __CSPHandleMetaMsg(rdram, ctx);
        goto after_23;
    // 0x8002C120: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    after_23:
    // 0x8002C124: b           L_8002C350
    // 0x8002C128: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
        goto L_8002C350;
    // 0x8002C128: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
L_8002C12C:
    // 0x8002C12C: lw          $s1, 0x6C($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X6C);
    // 0x8002C130: lh          $t7, 0x44($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X44);
    // 0x8002C134: beq         $s1, $zero, L_8002C350
    if (ctx->r17 == 0) {
        // 0x8002C138: sh          $t7, 0x3A($fp)
        MEM_H(0X3A, ctx->r30) = ctx->r15;
            goto L_8002C350;
    }
    // 0x8002C138: sh          $t7, 0x3A($fp)
    MEM_H(0X3A, ctx->r30) = ctx->r15;
    // 0x8002C13C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8002C140:
    // 0x8002C140: jal         0x8002DF48
    // 0x8002C144: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    __n_vsVol(rdram, ctx);
        goto after_24;
    // 0x8002C144: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_24:
    // 0x8002C148: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002C14C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002C150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002C154: jal         0x8002DF24
    // 0x8002C158: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    __n_vsDelta(rdram, ctx);
        goto after_25;
    // 0x8002C158: lw          $a1, 0x1C($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X1C);
    after_25:
    // 0x8002C15C: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8002C160: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002C164: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8002C168: jal         0x8002FF60
    // 0x8002C16C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    n_alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x8002C16C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_26:
    // 0x8002C170: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x8002C174: bnel        $s1, $zero, L_8002C140
    if (ctx->r17 != 0) {
        // 0x8002C178: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002C140;
    }
    goto skip_4;
    // 0x8002C178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x8002C17C: b           L_8002C354
    // 0x8002C180: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C180: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C184:
    // 0x8002C184: lw          $t6, 0x34($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X34);
    // 0x8002C188: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8002C18C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002C190: beq         $t6, $at, L_8002C350
    if (ctx->r14 == ctx->r1) {
        // 0x8002C194: sb          $t8, 0x78($fp)
        MEM_B(0X78, ctx->r30) = ctx->r24;
            goto L_8002C350;
    }
    // 0x8002C194: sb          $t8, 0x78($fp)
    MEM_B(0X78, ctx->r30) = ctx->r24;
    // 0x8002C198: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002C19C: sw          $t9, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r25;
    // 0x8002C1A0: jal         0x80029100
    // 0x8002C1A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80029100_29D00(rdram, ctx);
        goto after_27;
    // 0x8002C1A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_27:
    // 0x8002C1A8: b           L_8002C354
    // 0x8002C1AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C1AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C1B0:
    // 0x8002C1B0: lw          $t7, 0x34($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X34);
    // 0x8002C1B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002C1B8: bnel        $t7, $at, L_8002C354
    if (ctx->r15 != ctx->r1) {
        // 0x8002C1BC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8002C354;
    }
    goto skip_5;
    // 0x8002C1BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_5:
    // 0x8002C1C0: lw          $s1, 0x6C($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X6C);
    // 0x8002C1C4: beq         $s1, $zero, L_8002C20C
    if (ctx->r17 == 0) {
        // 0x8002C1C8: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_8002C20C;
    }
    // 0x8002C1C8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_8002C1CC:
    // 0x8002C1CC: jal         0x8002D780
    // 0x8002C1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynStopVoice(rdram, ctx);
        goto after_28;
    // 0x8002C1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8002C1D4: jal         0x8002FEC0
    // 0x8002C1D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynFreeVoice(rdram, ctx);
        goto after_29;
    // 0x8002C1D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8002C1DC: lbu         $t8, 0x37($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X37);
    // 0x8002C1E0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C1E4: beql        $t8, $zero, L_8002C1F8
    if (ctx->r24 == 0) {
        // 0x8002C1E8: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002C1F8;
    }
    goto skip_6;
    // 0x8002C1E8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    skip_6:
    // 0x8002C1EC: jal         0x8002F39C
    // 0x8002C1F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    __n_seqpStopOsc(rdram, ctx);
        goto after_30;
    // 0x8002C1F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x8002C1F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_8002C1F8:
    // 0x8002C1F8: jal         0x8002E1C4
    // 0x8002C1FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __n_unmapVoice(rdram, ctx);
        goto after_31;
    // 0x8002C1FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_31:
    // 0x8002C200: lw          $s1, 0x6C($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X6C);
    // 0x8002C204: bnel        $s1, $zero, L_8002C1CC
    if (ctx->r17 != 0) {
        // 0x8002C208: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_8002C1CC;
    }
    goto skip_7;
    // 0x8002C208: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_7:
L_8002C20C:
    // 0x8002C20C: jal         0x8002F4A0
    // 0x8002C210: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    __n_initChanState(rdram, ctx);
        goto after_32;
    // 0x8002C210: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_32:
    // 0x8002C214: b           L_8002C350
    // 0x8002C218: sw          $zero, 0x34($fp)
    MEM_W(0X34, ctx->r30) = 0;
        goto L_8002C350;
    // 0x8002C218: sw          $zero, 0x34($fp)
    MEM_W(0X34, ctx->r30) = 0;
L_8002C21C:
    // 0x8002C21C: lw          $t6, 0x34($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X34);
    // 0x8002C220: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002C224: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C228: bnel        $t6, $at, L_8002C354
    if (ctx->r14 != ctx->r1) {
        // 0x8002C22C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8002C354;
    }
    goto skip_8;
    // 0x8002C22C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_8:
    // 0x8002C230: jal         0x80028CB4
    // 0x8002C234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    alEvtqFlushType(rdram, ctx);
        goto after_33;
    // 0x8002C234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x8002C238: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C23C: jal         0x80028CB4
    // 0x8002C240: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    alEvtqFlushType(rdram, ctx);
        goto after_34;
    // 0x8002C240: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_34:
    // 0x8002C244: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C248: jal         0x80028CB4
    // 0x8002C24C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alEvtqFlushType(rdram, ctx);
        goto after_35;
    // 0x8002C24C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x8002C250: lw          $s1, 0x6C($fp)
    ctx->r17 = MEM_W(ctx->r30, 0X6C);
    // 0x8002C254: beq         $s1, $zero, L_8002C28C
    if (ctx->r17 == 0) {
        // 0x8002C258: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_8002C28C;
    }
    // 0x8002C258: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_8002C25C:
    // 0x8002C25C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C260: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C264: jal         0x8002E11C
    // 0x8002C268: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __voiceNeedsNoteKill(rdram, ctx);
        goto after_36;
    // 0x8002C268: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_36:
    // 0x8002C26C: beq         $v0, $zero, L_8002C280
    if (ctx->r2 == 0) {
        // 0x8002C270: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_8002C280;
    }
    // 0x8002C270: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C278: jal         0x8002DFF8
    // 0x8002C27C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    __n_seqpReleaseVoice(rdram, ctx);
        goto after_37;
    // 0x8002C27C: ori         $a2, $zero, 0xC350
    ctx->r6 = 0 | 0XC350;
    after_37:
L_8002C280:
    // 0x8002C280: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x8002C284: bnel        $s1, $zero, L_8002C25C
    if (ctx->r17 != 0) {
        // 0x8002C288: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_8002C25C;
    }
    goto skip_9;
    // 0x8002C288: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    skip_9:
L_8002C28C:
    // 0x8002C28C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002C290: sw          $t9, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r25;
    // 0x8002C294: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002C298: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x8002C29C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    // 0x8002C2A0: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8002C2A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002C2A8: jal         0x80028D70
    // 0x8002C2AC: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    alEvtqPostEvent(rdram, ctx);
        goto after_38;
    // 0x8002C2AC: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_38:
    // 0x8002C2B0: b           L_8002C354
    // 0x8002C2B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C2B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C2B8:
    // 0x8002C2B8: lbu         $s0, 0x44($fp)
    ctx->r16 = MEM_BU(ctx->r30, 0X44);
    // 0x8002C2BC: lw          $t6, 0x68($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X68);
    // 0x8002C2C0: lbu         $t8, 0x45($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X45);
    // 0x8002C2C4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8002C2C8: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x8002C2CC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002C2D0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8002C2D4: b           L_8002C350
    // 0x8002C2D8: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
        goto L_8002C350;
    // 0x8002C2D8: sb          $t8, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r24;
L_8002C2DC:
    // 0x8002C2DC: lw          $t6, 0x44($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X44);
    // 0x8002C2E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002C2E4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C2E8: sw          $t6, 0x18($fp)
    MEM_W(0X18, ctx->r30) = ctx->r14;
    // 0x8002C2EC: jal         0x80029170
    // 0x8002C2F0: lwc1        $f12, -0x11B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X11B4);
    __setUsptFromTempo(rdram, ctx);
        goto after_39;
    // 0x8002C2F0: lwc1        $f12, -0x11B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X11B4);
    after_39:
    // 0x8002C2F4: lw          $a1, 0x20($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X20);
    // 0x8002C2F8: beql        $a1, $zero, L_8002C354
    if (ctx->r5 == 0) {
        // 0x8002C2FC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8002C354;
    }
    goto skip_10;
    // 0x8002C2FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_10:
    // 0x8002C300: jal         0x8002DE68
    // 0x8002C304: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    __initFromBank(rdram, ctx);
        goto after_40;
    // 0x8002C304: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_40:
    // 0x8002C308: b           L_8002C354
    // 0x8002C30C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C30C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C310:
    // 0x8002C310: lw          $a1, 0x44($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X44);
    // 0x8002C314: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C318: jal         0x8002DE68
    // 0x8002C31C: sw          $a1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_41;
    // 0x8002C31C: sw          $a1, 0x20($fp)
    MEM_W(0X20, ctx->r30) = ctx->r5;
    after_41:
    // 0x8002C320: b           L_8002C354
    // 0x8002C324: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C324: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C328:
    // 0x8002C328: lw          $a1, 0x44($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X44);
    // 0x8002C32C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C330: jal         0x8002DE68
    // 0x8002C334: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_42;
    // 0x8002C334: sw          $a1, 0x24($fp)
    MEM_W(0X24, ctx->r30) = ctx->r5;
    after_42:
    // 0x8002C338: b           L_8002C354
    // 0x8002C33C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8002C354;
    // 0x8002C33C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C340:
    // 0x8002C340: lw          $a1, 0x44($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X44);
    // 0x8002C344: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002C348: jal         0x8002DE68
    // 0x8002C34C: sw          $a1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r5;
    __initFromBank(rdram, ctx);
        goto after_43;
    // 0x8002C34C: sw          $a1, 0x28($fp)
    MEM_W(0X28, ctx->r30) = ctx->r5;
    after_43:
L_8002C350:
    // 0x8002C350: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8002C354:
    // 0x8002C354: jal         0x80028EC0
    // 0x8002C358: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    alEvtqNextEvent(rdram, ctx);
        goto after_44;
    // 0x8002C358: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_44:
    // 0x8002C35C: beq         $v0, $zero, L_8002BD74
    if (ctx->r2 == 0) {
        // 0x8002C360: sw          $v0, 0x30($fp)
        MEM_W(0X30, ctx->r30) = ctx->r2;
            goto L_8002BD74;
    }
    // 0x8002C360: sw          $v0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r2;
    // 0x8002C364: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002C368: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002C36C: lw          $t9, 0x1C($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X1C);
    // 0x8002C370: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002C374: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002C378: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C37C: sw          $t8, 0x1C($fp)
    MEM_W(0X1C, ctx->r30) = ctx->r24;
    // 0x8002C380: lwc1        $f10, -0x2CE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2CE8);
    // 0x8002C384: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002C388: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002C38C: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8002C390: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002C394: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002C398: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002C39C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002C3A0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C3A4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002C3A8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002C3AC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002C3B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8002C3B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8002C3B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8002C3BC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8002C3C0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8002C3C4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8002C3C8: jr          $ra
    // 0x8002C3CC: nop

    return;
    // 0x8002C3CC: nop

;}
RECOMP_FUNC void mnVSResultsMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EA8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80132EAC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132EB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132EB4: addiu       $t7, $t7, -0x6F80
    ctx->r15 = ADD32(ctx->r15, -0X6F80);
    // 0x80132EB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132EBC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132EC0: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x80132EC4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132EC8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132ECC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132ED0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132ED4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132ED8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132EDC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132EE0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80132EE4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80132EE8: addiu       $t1, $t1, -0x6F68
    ctx->r9 = ADD32(ctx->r9, -0X6F68);
    // 0x80132EEC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80132EF0: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80132EF4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80132EF8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132EFC: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x80132F00: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132F04: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80132F08: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80132F0C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132F10: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80132F14: addiu       $t5, $t5, -0x6F58
    ctx->r13 = ADD32(ctx->r13, -0X6F58);
    // 0x80132F18: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132F1C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80132F20: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80132F24: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
    // 0x80132F28: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80132F2C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80132F30: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80132F34: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80132F38: addiu       $t9, $t9, -0x6F4C
    ctx->r25 = ADD32(ctx->r25, -0X6F4C);
    // 0x80132F3C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132F40: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80132F44: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80132F48: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80132F4C: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80132F50: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80132F54: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80132F58: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80132F5C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80132F60: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80132F64: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80132F68: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80132F6C: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80132F70: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80132F74: addiu       $t2, $t2, -0x2D34
    ctx->r10 = ADD32(ctx->r10, -0X2D34);
    // 0x80132F78: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x80132F7C: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x80132F80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132F84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132F88: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80132F8C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132F90: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80132F94: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80132F98: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80132F9C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80132FA0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80132FA4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80132FA8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80132FAC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80132FB0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132FB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132FB8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132FBC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132FC0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FC8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132FCC: jal         0x8000B93C
    // 0x80132FD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132FD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132FD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132FD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132FDC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132FE0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132FE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132FE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132FEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132FF0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132FF4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132FF8: jal         0x80007080
    // 0x80132FFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132FFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133000: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133004: lw          $t9, -0x63F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63F0);
    // 0x80133008: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013300C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80133010: bne         $t9, $at, L_80133028
    if (ctx->r25 != ctx->r1) {
        // 0x80133014: nop
    
            goto L_80133028;
    }
    // 0x80133014: nop

    // 0x80133018: jal         0x80018994
    // 0x8013301C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8013301C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80133020: b           L_8013306C
    // 0x80133024: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
        goto L_8013306C;
    // 0x80133024: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
L_80133028:
    // 0x80133028: lbu         $v1, -0x63EC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X63EC);
    // 0x8013302C: bnel        $v1, $zero, L_8013304C
    if (ctx->r3 != 0) {
        // 0x80133030: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013304C;
    }
    goto skip_0;
    // 0x80133030: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80133034: jal         0x8013234C
    // 0x80133038: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_3;
    // 0x80133038: nop

    after_3:
    // 0x8013303C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80133040: lbu         $v1, -0x63EC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X63EC);
    // 0x80133044: sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // 0x80133048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8013304C:
    // 0x8013304C: bnel        $v1, $at, L_80133070
    if (ctx->r3 != ctx->r1) {
        // 0x80133050: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80133070;
    }
    goto skip_1;
    // 0x80133050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80133054: jal         0x80132A2C
    // 0x80133058: nop

    mnVSResultsGetWinTeam(rdram, ctx);
        goto after_4;
    // 0x80133058: nop

    after_4:
    // 0x8013305C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80133060: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80133064: lw          $t1, 0x64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X64);
    // 0x80133068: sw          $t1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r9;
L_8013306C:
    // 0x8013306C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80133070:
    // 0x80133070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133074: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80133078: jal         0x80009968
    // 0x8013307C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x8013307C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80133080: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133084: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80133088: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x8013308C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80133090: addiu       $a1, $a1, 0x2D84
    ctx->r5 = ADD32(ctx->r5, 0X2D84);
    // 0x80133094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133098: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8013309C: jal         0x80009DF4
    // 0x801330A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x801330A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x801330A4: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801330A8: lw          $t3, -0x5FB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5FB8);
    // 0x801330AC: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x801330B0: addiu       $t4, $t4, -0x2A38
    ctx->r12 = ADD32(ctx->r12, -0X2A38);
    // 0x801330B4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x801330B8: jal         0x800CCFDC
    // 0x801330BC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x801330BC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_7:
    // 0x801330C0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x801330C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801330C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801330CC: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x801330D0: addiu       $t9, $sp, 0x4C
    ctx->r25 = ADD32(ctx->r29, 0X4C);
    // 0x801330D4: swc1        $f0, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f0.u32l;
    // 0x801330D8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x801330DC: swc1        $f0, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f0.u32l;
    // 0x801330E0: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x801330E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801330E8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801330EC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801330F0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x801330F4: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801330F8: sb          $t0, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r8;
    // 0x801330FC: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x80133100: sb          $t1, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r9;
    // 0x80133104: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x80133108: sb          $t2, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r10;
    // 0x8013310C: lbu         $t3, 0x3($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3);
    // 0x80133110: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133114: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x80133118: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x8013311C: lbu         $t5, 0x5($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X5);
    // 0x80133120: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133124: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133128: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8013312C: jr          $ra
    // 0x80133130: nop

    return;
    // 0x80133130: nop

;}
RECOMP_FUNC void mnVSResultsOrderResults(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80136C30: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80136C34: blez        $a1, L_80136D20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80136C38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136D20;
    }
    // 0x80136C38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136C3C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80136C40: addiu       $t2, $t2, 0x4AD0
    ctx->r10 = ADD32(ctx->r10, 0X4AD0);
    // 0x80136C44: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
L_80136C48:
    // 0x80136C48: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80136C4C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80136C50: beq         $at, $zero, L_80136D18
    if (ctx->r1 == 0) {
        // 0x80136C54: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80136D18;
    }
    // 0x80136C54: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80136C58: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80136C5C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80136C60: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80136C64: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80136C68: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80136C6C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80136C70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80136C74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80136C78: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80136C7C: addu        $t1, $t8, $a2
    ctx->r9 = ADD32(ctx->r24, ctx->r6);
    // 0x80136C80: addu        $t0, $a2, $t7
    ctx->r8 = ADD32(ctx->r6, ctx->r15);
    // 0x80136C84: addu        $a3, $a2, $t6
    ctx->r7 = ADD32(ctx->r6, ctx->r14);
    // 0x80136C88: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80136C8C:
    // 0x80136C8C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80136C90: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80136C94: bnel        $at, $zero, L_80136CC8
    if (ctx->r1 != 0) {
        // 0x80136C98: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_80136CC8;
    }
    goto skip_0;
    // 0x80136C98: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80136C9C: lbu         $t9, 0x10($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X10);
    // 0x80136CA0: beql        $t9, $zero, L_80136D10
    if (ctx->r25 == 0) {
        // 0x80136CA4: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_80136D10;
    }
    goto skip_1;
    // 0x80136CA4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    skip_1:
    // 0x80136CA8: bnel        $v0, $v1, L_80136D10
    if (ctx->r2 != ctx->r3) {
        // 0x80136CAC: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_80136D10;
    }
    goto skip_2;
    // 0x80136CAC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    skip_2:
    // 0x80136CB0: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x80136CB4: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x80136CB8: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80136CBC: beql        $at, $zero, L_80136D10
    if (ctx->r1 == 0) {
        // 0x80136CC0: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_80136D10;
    }
    goto skip_3;
    // 0x80136CC0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    skip_3:
    // 0x80136CC4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_80136CC8:
    // 0x80136CC8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80136CCC: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x80136CD0: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80136CD4: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x80136CD8: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x80136CDC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80136CE0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80136CE4: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80136CE8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80136CEC: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x80136CF0: sw          $t9, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r25;
    // 0x80136CF4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80136CF8: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80136CFC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80136D00: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80136D04: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80136D08: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x80136D0C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
L_80136D10:
    // 0x80136D10: bnel        $t0, $t1, L_80136C8C
    if (ctx->r8 != ctx->r9) {
        // 0x80136D14: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_80136C8C;
    }
    goto skip_4;
    // 0x80136D14: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_4:
L_80136D18:
    // 0x80136D18: bne         $a0, $a1, L_80136C48
    if (ctx->r4 != ctx->r5) {
        // 0x80136D1C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80136C48;
    }
    // 0x80136D1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80136D20:
    // 0x80136D20: jr          $ra
    // 0x80136D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80136D24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itFushigibanaWeaponRazorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184828: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8018482C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80184830: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80184834: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80184838: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8018483C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80184840: nop

    // 0x80184844: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80184848: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018484C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80184850: jal         0x80167FE8
    // 0x80184854: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80184854: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    after_0:
    // 0x80184858: beq         $v0, $zero, L_80184868
    if (ctx->r2 == 0) {
        // 0x8018485C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80184868;
    }
    // 0x8018485C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184860: b           L_8018486C
    // 0x80184864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018486C;
    // 0x80184864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80184868:
    // 0x80184868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018486C:
    // 0x8018486C: jr          $ra
    // 0x80184870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80184870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gcPlayAnimAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DF34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000DF38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000DF3C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000DF40: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000DF44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DF48: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8000DF4C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8000DF50: beql        $s1, $zero, L_8000DFF4
    if (ctx->r17 == 0) {
        // 0x8000DF54: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000DFF4;
    }
    goto skip_0;
    // 0x8000DF54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8000DF58:
    // 0x8000DF58: jal         0x8000BFE8
    // 0x8000DF5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8000DF5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8000DF60: jal         0x8000CCBC
    // 0x8000DF64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8000DF64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8000DF68: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x8000DF6C: beql        $s0, $zero, L_8000DF94
    if (ctx->r16 == 0) {
        // 0x8000DF70: lw          $v0, 0x10($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X10);
            goto L_8000DF94;
    }
    goto skip_1;
    // 0x8000DF70: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    skip_1:
L_8000DF74:
    // 0x8000DF74: jal         0x8000CF6C
    // 0x8000DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8000DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000DF7C: jal         0x8000DA40
    // 0x8000DF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_3;
    // 0x8000DF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000DF84: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000DF88: bne         $s0, $zero, L_8000DF74
    if (ctx->r16 != 0) {
        // 0x8000DF8C: nop
    
            goto L_8000DF74;
    }
    // 0x8000DF8C: nop

    // 0x8000DF90: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
L_8000DF94:
    // 0x8000DF94: beql        $v0, $zero, L_8000DFA8
    if (ctx->r2 == 0) {
        // 0x8000DF98: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_8000DFA8;
    }
    goto skip_2;
    // 0x8000DF98: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x8000DF9C: b           L_8000DFE8
    // 0x8000DFA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8000DFE8;
    // 0x8000DFA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000DFA4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_8000DFA8:
    // 0x8000DFA8: beql        $v0, $zero, L_8000DFBC
    if (ctx->r2 == 0) {
        // 0x8000DFAC: lw          $v0, 0x14($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X14);
            goto L_8000DFBC;
    }
    goto skip_3;
    // 0x8000DFAC: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    skip_3:
    // 0x8000DFB0: b           L_8000DFE8
    // 0x8000DFB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8000DFE8;
    // 0x8000DFB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000DFB8:
    // 0x8000DFB8: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
L_8000DFBC:
    // 0x8000DFBC: bnel        $s2, $v0, L_8000DFD0
    if (ctx->r18 != ctx->r2) {
        // 0x8000DFC0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_8000DFD0;
    }
    goto skip_4;
    // 0x8000DFC0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_4:
    // 0x8000DFC4: b           L_8000DFE8
    // 0x8000DFC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8000DFE8;
    // 0x8000DFC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000DFCC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_8000DFD0:
    // 0x8000DFD0: beq         $v1, $zero, L_8000DFE0
    if (ctx->r3 == 0) {
        // 0x8000DFD4: nop
    
            goto L_8000DFE0;
    }
    // 0x8000DFD4: nop

    // 0x8000DFD8: b           L_8000DFE8
    // 0x8000DFDC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_8000DFE8;
    // 0x8000DFDC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_8000DFE0:
    // 0x8000DFE0: b           L_8000DFB8
    // 0x8000DFE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_8000DFB8;
    // 0x8000DFE4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8000DFE8:
    // 0x8000DFE8: bne         $s1, $zero, L_8000DF58
    if (ctx->r17 != 0) {
        // 0x8000DFEC: nop
    
            goto L_8000DF58;
    }
    // 0x8000DFEC: nop

    // 0x8000DFF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000DFF4:
    // 0x8000DFF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DFF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DFFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E000: jr          $ra
    // 0x8000E004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000E004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSResultsGetPresentLowerCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320B8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801320BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801320C0: addiu       $a2, $a2, -0x6430
    ctx->r6 = ADD32(ctx->r6, -0X6430);
    // 0x801320C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801320C8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801320CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801320D0:
    // 0x801320D0: beq         $a0, $v0, L_801320F8
    if (ctx->r4 == ctx->r2) {
        // 0x801320D4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801320F8;
    }
    // 0x801320D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801320D8: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801320DC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801320E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801320E4: bne         $a1, $t8, L_801320F0
    if (ctx->r5 != ctx->r24) {
        // 0x801320E8: nop
    
            goto L_801320F0;
    }
    // 0x801320E8: nop

    // 0x801320EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801320F0:
    // 0x801320F0: bne         $v0, $a3, L_801320D0
    if (ctx->r2 != ctx->r7) {
        // 0x801320F4: nop
    
            goto L_801320D0;
    }
    // 0x801320F4: nop

L_801320F8:
    // 0x801320F8: jr          $ra
    // 0x801320FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801320FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wpYoshiStarProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C6A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8016C6A4: jr          $ra
    // 0x8016C6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016C6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mvOpeningRoomStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801349BC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801349C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801349C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801349C8: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801349CC: addiu       $a0, $a0, 0x4BD0
    ctx->r4 = ADD32(ctx->r4, 0X4BD0);
    // 0x801349D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801349D4: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801349D8: jal         0x80007024
    // 0x801349DC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801349DC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801349E0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801349E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801349E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801349EC: addiu       $t9, $t9, 0x50D0
    ctx->r25 = ADD32(ctx->r25, 0X50D0);
    // 0x801349F0: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801349F4: addiu       $a0, $a0, 0x4BEC
    ctx->r4 = ADD32(ctx->r4, 0X4BEC);
    // 0x801349F8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801349FC: jal         0x800A2698
    // 0x80134A00: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80134A00: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80134A04: jal         0x800048D0
    // 0x80134A08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syTaskmanSetFuncSwapBuffer(rdram, ctx);
        goto after_2;
    // 0x80134A08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80134A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134A14: jr          $ra
    // 0x80134A18: nop

    return;
    // 0x80134A18: nop

;}
RECOMP_FUNC void func_ovl8_803771CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803771CC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x803771D0: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x803771D4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x803771D8: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x803771DC: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x803771E0: lhu         $t9, 0x4($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X4);
    // 0x803771E4: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x803771E8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x803771EC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x803771F0: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x803771F4: lhu         $t3, 0x6($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X6);
    // 0x803771F8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x803771FC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80377200: jr          $ra
    // 0x80377204: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    return;
    // 0x80377204: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
;}
RECOMP_FUNC void mnPlayersVSGetArrowSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136998: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8013699C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801369A0: beq         $v1, $zero, L_801369DC
    if (ctx->r3 == 0) {
        // 0x801369A4: nop
    
            goto L_801369DC;
    }
    // 0x801369A4: nop

    // 0x801369A8: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x801369AC: bnel        $a1, $t6, L_801369C0
    if (ctx->r5 != ctx->r14) {
        // 0x801369B0: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_801369C0;
    }
    goto skip_0;
    // 0x801369B0: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x801369B4: jr          $ra
    // 0x801369B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801369B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801369BC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_801369C0:
    // 0x801369C0: beq         $a0, $zero, L_801369DC
    if (ctx->r4 == 0) {
        // 0x801369C4: nop
    
            goto L_801369DC;
    }
    // 0x801369C4: nop

    // 0x801369C8: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x801369CC: bne         $a1, $t7, L_801369DC
    if (ctx->r5 != ctx->r15) {
        // 0x801369D0: nop
    
            goto L_801369DC;
    }
    // 0x801369D0: nop

    // 0x801369D4: jr          $ra
    // 0x801369D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x801369D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_801369DC:
    // 0x801369DC: jr          $ra
    // 0x801369E0: nop

    return;
    // 0x801369E0: nop

;}
RECOMP_FUNC void gmCollisionGetItemAttackFighterAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0E78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0E7C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0E80: jal         0x800F095C
    // 0x800F0E84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0E84: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0E88: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0E8C: jal         0x800F0850
    // 0x800F0E90: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0E90: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800F0E94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0E98: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0E9C: jal         0x800F0A48
    // 0x800F0EA0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0EA0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0EA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0EAC: jr          $ra
    // 0x800F0EB0: nop

    return;
    // 0x800F0EB0: nop

;}
RECOMP_FUNC void mnPlayersVSGetFreeCostumeRoyal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013473C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80134740: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80134744: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80134748: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013474C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80134750: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80134754: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80134758: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8013475C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80134760: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134764: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013476C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80134770: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80134774: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
L_80134778:
    // 0x80134778: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8013477C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80134780: bne         $at, $zero, L_80134778
    if (ctx->r1 != 0) {
        // 0x80134784: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80134778;
    }
    // 0x80134784: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80134788: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x8013478C: addiu       $s7, $s7, -0x4578
    ctx->r23 = ADD32(ctx->r23, -0X4578);
    // 0x80134790: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80134794: addiu       $fp, $zero, 0xBC
    ctx->r30 = ADD32(0, 0XBC);
    // 0x80134798: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x8013479C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801347A0: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x801347A4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
L_801347A8:
    // 0x801347A8: beql        $s6, $t6, L_801347FC
    if (ctx->r22 == ctx->r14) {
        // 0x801347AC: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_801347FC;
    }
    goto skip_0;
    // 0x801347AC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_0:
    // 0x801347B0: multu       $s6, $fp
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801347B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801347B8: mflo        $t7
    ctx->r15 = lo;
    // 0x801347BC: addu        $s1, $s7, $t7
    ctx->r17 = ADD32(ctx->r23, ctx->r15);
    // 0x801347C0: lw          $t8, 0x48($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X48);
    // 0x801347C4: bne         $s5, $t8, L_801347F8
    if (ctx->r21 != ctx->r24) {
        // 0x801347C8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_801347F8;
    }
    // 0x801347C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_801347CC:
    // 0x801347CC: jal         0x800EC0EC
    // 0x801347D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801347D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801347D4: lw          $t9, 0x4C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4C);
    // 0x801347D8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x801347DC: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x801347E0: bnel        $v0, $t9, L_801347F0
    if (ctx->r2 != ctx->r25) {
        // 0x801347E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801347F0;
    }
    goto skip_1;
    // 0x801347E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801347E8: sw          $s3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r19;
    // 0x801347EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801347F0:
    // 0x801347F0: bnel        $s0, $s4, L_801347CC
    if (ctx->r16 != ctx->r20) {
        // 0x801347F4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_801347CC;
    }
    goto skip_2;
    // 0x801347F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_2:
L_801347F8:
    // 0x801347F8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_801347FC:
    // 0x801347FC: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x80134800: bnel        $at, $zero, L_801347A8
    if (ctx->r1 != 0) {
        // 0x80134804: lw          $t6, 0x6C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X6C);
            goto L_801347A8;
    }
    goto skip_3;
    // 0x80134804: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    skip_3:
    // 0x80134808: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8013480C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134810: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134814: bne         $t2, $zero, L_80134824
    if (ctx->r10 != 0) {
        // 0x80134818: lw          $s2, 0x20($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X20);
            goto L_80134824;
    }
    // 0x80134818: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8013481C: b           L_80134858
    // 0x80134820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134858;
    // 0x80134820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134824:
    // 0x80134824: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80134828: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8013482C: bne         $t3, $zero, L_8013483C
    if (ctx->r11 != 0) {
        // 0x80134830: nop
    
            goto L_8013483C;
    }
    // 0x80134830: nop

    // 0x80134834: b           L_80134858
    // 0x80134838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134858;
    // 0x80134838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013483C:
    // 0x8013483C: bne         $t4, $zero, L_8013484C
    if (ctx->r12 != 0) {
        // 0x80134840: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_8013484C;
    }
    // 0x80134840: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80134844: b           L_80134858
    // 0x80134848: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80134858;
    // 0x80134848: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8013484C:
    // 0x8013484C: bnel        $t5, $zero, L_8013485C
    if (ctx->r13 != 0) {
        // 0x80134850: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8013485C;
    }
    goto skip_4;
    // 0x80134850: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80134854: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80134858:
    // 0x80134858: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8013485C:
    // 0x8013485C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80134860: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80134864: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80134868: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8013486C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80134870: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80134874: jr          $ra
    // 0x80134878: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80134878: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mvOpeningMarioSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018D0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018D0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018D0E0: addiu       $t8, $t8, -0x1D98
    ctx->r24 = ADD32(ctx->r24, -0X1D98);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1C18
    ctx->r8 = ADD32(ctx->r8, -0X1C18);
    // 0x8018D0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018D0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018D0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018D0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018D104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018D10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D110: jal         0x800CDF78
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018D118: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D11C: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8018D128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D12C: jal         0x80004980
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D134: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018D13C: addiu       $a2, $a2, -0x1BE0
    ctx->r6 = ADD32(ctx->r6, -0X1BE0);
    // 0x8018D140: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    // 0x8018D144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D148: jal         0x800CDE04
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D158: jr          $ra
    // 0x8018D15C: nop

    return;
    // 0x8018D15C: nop

;}
RECOMP_FUNC void ftBossCommonCheckPlayerInvertLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80158034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80158038: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015803C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80158040: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x80158044: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x80158048: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8015804C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80158050: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80158054: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80158058: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8015805C: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80158060: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80158064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80158068: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8015806C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80158070: nop

    // 0x80158074: bc1fl       L_80158088
    if (!c1cs) {
        // 0x80158078: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80158088;
    }
    goto skip_0;
    // 0x80158078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015807C: jal         0x80157F60
    // 0x80158080: nop

    ftBossCommonInvertLR(rdram, ctx);
        goto after_0;
    // 0x80158080: nop

    after_0:
    // 0x80158084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158088:
    // 0x80158088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015808C: jr          $ra
    // 0x80158090: nop

    return;
    // 0x80158090: nop

;}
RECOMP_FUNC void itFFlowerWeaponFlameProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175DE4: jal         0x80167FE8
    // 0x80175DE8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80175DE8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80175DEC: beq         $v0, $zero, L_80175DFC
    if (ctx->r2 == 0) {
        // 0x80175DF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80175DFC;
    }
    // 0x80175DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175DF4: b           L_80175E00
    // 0x80175DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80175E00;
    // 0x80175DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80175DFC:
    // 0x80175DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80175E00:
    // 0x80175E00: jr          $ra
    // 0x80175E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80175E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnVSRecordMakeRowIcons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013388C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80133890: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80133894: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133898: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8013389C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801338A0: addiu       $t6, $t6, 0x686C
    ctx->r14 = ADD32(ctx->r14, 0X686C);
    // 0x801338A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801338A8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801338AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801338B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801338B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801338B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801338BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801338C0: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x801338C4: or          $t9, $s6, $zero
    ctx->r25 = ctx->r22 | 0;
L_801338C8:
    // 0x801338C8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801338CC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801338D0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801338D4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801338D8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801338DC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801338E0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801338E4: bne         $t6, $t0, L_801338C8
    if (ctx->r14 != ctx->r8) {
        // 0x801338E8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801338C8;
    }
    // 0x801338E8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801338EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801338F0: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x801338F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801338F8: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x801338FC: beq         $v0, $zero, L_80133918
    if (ctx->r2 == 0) {
        // 0x80133900: addiu       $s4, $zero, -0x21
        ctx->r20 = ADD32(0, -0X21);
            goto L_80133918;
    }
    // 0x80133900: addiu       $s4, $zero, -0x21
    ctx->r20 = ADD32(0, -0X21);
    // 0x80133904: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133908: beq         $v0, $at, L_80133928
    if (ctx->r2 == ctx->r1) {
        // 0x8013390C: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80133928;
    }
    // 0x8013390C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133910: b           L_80133930
    // 0x80133914: nop

        goto L_80133930;
    // 0x80133914: nop

L_80133918:
    // 0x80133918: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013391C: addiu       $t1, $t1, 0x6C28
    ctx->r9 = ADD32(ctx->r9, 0X6C28);
    // 0x80133920: b           L_80133930
    // 0x80133924: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_80133930;
    // 0x80133924: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80133928:
    // 0x80133928: addiu       $t2, $t2, 0x6C58
    ctx->r10 = ADD32(ctx->r10, 0X6C58);
    // 0x8013392C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80133930:
    // 0x80133930: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80133934: addiu       $s3, $s3, 0x6D88
    ctx->r19 = ADD32(ctx->r19, 0X6D88);
    // 0x80133938: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
L_8013393C:
    // 0x8013393C: jal         0x801326EC
    // 0x80133940: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x80133940: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x80133944: beq         $v0, $zero, L_80133988
    if (ctx->r2 == 0) {
        // 0x80133948: nop
    
            goto L_80133988;
    }
    // 0x80133948: nop

    // 0x8013394C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80133950: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80133954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133958: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8013395C: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80133960: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80133964: jal         0x800CCFDC
    // 0x80133968: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133968: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    after_1:
    // 0x8013396C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133974: and         $t8, $t9, $s4
    ctx->r24 = ctx->r25 & ctx->r20;
    // 0x80133978: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x8013397C: ori         $t1, $t8, 0x1
    ctx->r9 = ctx->r24 | 0X1;
    // 0x80133980: b           L_80133994
    // 0x80133984: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
        goto L_80133994;
    // 0x80133984: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
L_80133988:
    // 0x80133988: jal         0x801335A0
    // 0x8013398C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordMakeLockedIcon(rdram, ctx);
        goto after_2;
    // 0x8013398C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80133990: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80133994:
    // 0x80133994: jal         0x80133740
    // 0x80133998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSRecordSetRowIconPosition(rdram, ctx);
        goto after_3;
    // 0x80133998: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8013399C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801339A0: bne         $s0, $s5, L_8013393C
    if (ctx->r16 != ctx->r21) {
        // 0x801339A4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8013393C;
    }
    // 0x801339A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801339A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801339AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801339B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801339B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801339B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801339BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801339C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801339C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801339C8: jr          $ra
    // 0x801339CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801339CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void scSubsysFighterGetLightAngleY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390528: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8039052C: jr          $ra
    // 0x80390530: lwc1        $f0, 0x29DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X29DC);
    return;
    // 0x80390530: lwc1        $f0, 0x29DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X29DC);
;}
RECOMP_FUNC void ftMarioSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155FFC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156000: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80156004: addiu       $t6, $t6, 0x5E64
    ctx->r14 = ADD32(ctx->r14, 0X5E64);
    // 0x80156008: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015600C: jr          $ra
    // 0x80156010: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x80156010: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void sc1PIntroGetFighterPositionZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C44: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132C48: addiu       $t6, $t6, 0x4FA8
    ctx->r14 = ADD32(ctx->r14, 0X4FA8);
    // 0x80132C4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132C54: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x80132C58: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132C5C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132C60: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80132C64: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80132C68: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132C6C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132C70: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80132C74: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80132C78: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80132C7C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80132C80: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80132C84: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80132C88: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80132C8C: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80132C90: jr          $ra
    // 0x80132C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftBossDeadLeftProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AD50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AD58: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AD5C: jal         0x800D9480
    // 0x8015AD60: addiu       $a1, $a1, -0x5218
    ctx->r5 = ADD32(ctx->r5, -0X5218);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AD60: addiu       $a1, $a1, -0x5218
    ctx->r5 = ADD32(ctx->r5, -0X5218);
    after_0:
    // 0x8015AD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AD6C: jr          $ra
    // 0x8015AD70: nop

    return;
    // 0x8015AD70: nop

;}
RECOMP_FUNC void func_ovl2_800EBB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EBB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBB44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EBB48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EBB4C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800EBB50: jal         0x800EBA6C
    // 0x800EBB54: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_ovl2_800EBA6C(rdram, ctx);
        goto after_0;
    // 0x800EBB54: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800EBB58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBB5C: lwc1        $f4, 0xDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDC);
    // 0x800EBB60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBB64: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800EBB68: nop

    // 0x800EBB6C: bc1f        L_800EBB80
    if (!c1cs) {
        // 0x800EBB70: nop
    
            goto L_800EBB80;
    }
    // 0x800EBB70: nop

    // 0x800EBB74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EBB78: b           L_800EBC00
    // 0x800EBB7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EBC00;
    // 0x800EBB7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EBB80:
    // 0x800EBB80: jal         0x800EBA6C
    // 0x800EBB84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_ovl2_800EBA6C(rdram, ctx);
        goto after_1;
    // 0x800EBB84: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800EBB88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBB8C: lwc1        $f6, 0xE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE0);
    // 0x800EBB90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800EBB94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBB98: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800EBB9C: nop

    // 0x800EBBA0: bc1f        L_800EBBB4
    if (!c1cs) {
        // 0x800EBBA4: nop
    
            goto L_800EBBB4;
    }
    // 0x800EBBA4: nop

    // 0x800EBBA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EBBAC: b           L_800EBC00
    // 0x800EBBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EBC00;
    // 0x800EBBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EBBB4:
    // 0x800EBBB4: jal         0x800CD5AC
    // 0x800EBBB8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    lbCommonCross3D(rdram, ctx);
        goto after_2;
    // 0x800EBBB8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800EBBBC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800EBBC0: jal         0x800C7B58
    // 0x800EBBC4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    lbCommonSim3D(rdram, ctx);
        goto after_3;
    // 0x800EBBC4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800EBBC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800EBBCC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800EBBD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBBD4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800EBBD8: nop

    // 0x800EBBDC: bc1f        L_800EBBF4
    if (!c1cs) {
        // 0x800EBBE0: nop
    
            goto L_800EBBF4;
    }
    // 0x800EBBE0: nop

    // 0x800EBBE4: jal         0x800191FC
    // 0x800EBBE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_4;
    // 0x800EBBE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800EBBEC: b           L_800EBBFC
    // 0x800EBBF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800EBBFC;
    // 0x800EBBF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800EBBF4:
    // 0x800EBBF4: jal         0x800191FC
    // 0x800EBBF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_5;
    // 0x800EBBF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
L_800EBBFC:
    // 0x800EBBFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EBC00:
    // 0x800EBC00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EBC04: jr          $ra
    // 0x800EBC08: nop

    return;
    // 0x800EBC08: nop

;}
RECOMP_FUNC void itTosakintoAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017E82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E830: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017E834: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017E838: addiu       $t6, $zero, 0x168
    ctx->r14 = ADD32(0, 0X168);
    // 0x8017E83C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8017E840: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8017E844: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x8017E848: bne         $t7, $at, L_8017E85C
    if (ctx->r15 != ctx->r1) {
        // 0x8017E84C: sh          $t6, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r14;
            goto L_8017E85C;
    }
    // 0x8017E84C: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x8017E850: jal         0x800269C0
    // 0x8017E854: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017E854: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017E858: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8017E85C:
    // 0x8017E85C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017E860: addiu       $a1, $a1, -0x540C
    ctx->r5 = ADD32(ctx->r5, -0X540C);
    // 0x8017E864: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017E868: jal         0x80172EC8
    // 0x8017E86C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017E86C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017E870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017E878: jr          $ra
    // 0x8017E87C: nop

    return;
    // 0x8017E87C: nop

;}
RECOMP_FUNC void scStaffrollMakeNameGObjAndDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F68: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80133F6C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80133F70: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x80133F74: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80133F78: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80133F7C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80133F80: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80133F84: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80133F88: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80133F8C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80133F90: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80133F94: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80133F98: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80133F9C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80133FA0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80133FA4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80133FA8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80133FAC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80133FB0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80133FB4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80133FB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133FC0: jal         0x80009968
    // 0x80133FC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133FC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80133FC8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133FCC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133FD0: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80133FD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133FD8: addiu       $a1, $a1, 0x3930
    ctx->r5 = ADD32(ctx->r5, 0X3930);
    // 0x80133FDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133FE4: jal         0x80009DF4
    // 0x80133FE8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133FE8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80133FEC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80133FF0: jal         0x800092D0
    // 0x80133FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80133FF8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80133FFC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80134000: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134004: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80134008: jal         0x80008CC0
    // 0x8013400C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8013400C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80134010: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134014: lw          $t7, -0x5748($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5748);
    // 0x80134018: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013401C: addiu       $t9, $t9, 0x64F4
    ctx->r25 = ADD32(ctx->r25, 0X64F4);
    // 0x80134020: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80134024: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80134028: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8013402C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80134030: lw          $s3, 0x0($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X0);
    // 0x80134034: blez        $v1, L_80134334
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80134038: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80134334;
    }
    // 0x80134038: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8013403C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80134040: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80134044: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80134048: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8013404C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80134050: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134054: addiu       $t1, $t1, 0x5260
    ctx->r9 = ADD32(ctx->r9, 0X5260);
    // 0x80134058: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x8013405C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80134060: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x80134064: addiu       $fp, $zero, 0x1E
    ctx->r30 = ADD32(0, 0X1E);
    // 0x80134068: addiu       $s7, $zero, 0x1A
    ctx->r23 = ADD32(0, 0X1A);
    // 0x8013406C: addiu       $s6, $zero, 0x32
    ctx->r22 = ADD32(0, 0X32);
    // 0x80134070: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
L_80134074:
    // 0x80134074: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80134078: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8013407C: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80134080: bne         $v0, $at, L_80134098
    if (ctx->r2 != ctx->r1) {
        // 0x80134084: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80134098;
    }
    // 0x80134084: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80134088: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8013408C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134090: b           L_8013431C
    // 0x80134094: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
        goto L_8013431C;
    // 0x80134094: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_80134098:
    // 0x80134098: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8013409C: addiu       $t4, $t4, -0x5E78
    ctx->r12 = ADD32(ctx->r12, -0X5E78);
    // 0x801340A0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x801340A4: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x801340A8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801340AC: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x801340B0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801340B4: lw          $a1, -0x5828($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5828);
    // 0x801340B8: bgez        $t5, L_801340D0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801340BC: cvt.s.w     $f22, $f6
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
            goto L_801340D0;
    }
    // 0x801340BC: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801340C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801340C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801340C8: nop

    // 0x801340CC: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
L_801340D0:
    // 0x801340D0: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x801340D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801340D8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801340DC: bgez        $t6, L_801340F0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801340E0: cvt.s.w     $f24, $f10
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801340F0;
    }
    // 0x801340E0: cvt.s.w     $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801340E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801340E8: nop

    // 0x801340EC: add.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f16.fl;
L_801340F0:
    // 0x801340F0: jal         0x800093F4
    // 0x801340F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    gcAddChildForDObj(rdram, ctx);
        goto after_4;
    // 0x801340F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_4:
    // 0x801340F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801340FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134100: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80134104: jal         0x80008CC0
    // 0x80134108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_5;
    // 0x80134108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8013410C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80134110: beq         $s0, $at, L_8013426C
    if (ctx->r16 == ctx->r1) {
        // 0x80134114: sub.s       $f18, $f24, $f30
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f30.fl;
            goto L_8013426C;
    }
    // 0x80134114: sub.s       $f18, $f24, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x80134118: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8013411C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134120: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80134124: lw          $v1, 0x5260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5260);
    // 0x80134128: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013412C: beq         $v1, $at, L_80134154
    if (ctx->r3 == ctx->r1) {
        // 0x80134130: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80134154;
    }
    // 0x80134130: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80134134: beq         $v1, $at, L_80134154
    if (ctx->r3 == ctx->r1) {
        // 0x80134138: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80134154;
    }
    // 0x80134138: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8013413C: beq         $v1, $at, L_80134154
    if (ctx->r3 == ctx->r1) {
        // 0x80134140: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80134154;
    }
    // 0x80134140: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80134144: beq         $v1, $at, L_80134154
    if (ctx->r3 == ctx->r1) {
        // 0x80134148: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80134154;
    }
    // 0x80134148: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8013414C: bnel        $v1, $at, L_801341F0
    if (ctx->r3 != ctx->r1) {
        // 0x80134150: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_801341F0;
    }
    goto skip_0;
    // 0x80134150: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_0:
L_80134154:
    // 0x80134154: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80134158: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013415C: beq         $s7, $v0, L_801341E4
    if (ctx->r23 == ctx->r2) {
        // 0x80134160: nop
    
            goto L_801341E4;
    }
    // 0x80134160: nop

    // 0x80134164: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x80134168: nop
    
            goto L_801341E4;
    }
    // 0x80134168: nop

    // 0x8013416C: beq         $fp, $v0, L_801341E4
    if (ctx->r30 == ctx->r2) {
        // 0x80134170: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_801341E4;
    }
    // 0x80134170: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80134174: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x80134178: addiu       $at, $zero, 0x26
        ctx->r1 = ADD32(0, 0X26);
            goto L_801341E4;
    }
    // 0x80134178: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8013417C: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x80134180: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_801341E4;
    }
    // 0x80134180: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80134184: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x80134188: nop
    
            goto L_801341E4;
    }
    // 0x80134188: nop

    // 0x8013418C: beq         $s5, $v0, L_801341E4
    if (ctx->r21 == ctx->r2) {
        // 0x80134190: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_801341E4;
    }
    // 0x80134190: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80134194: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x80134198: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_801341E4;
    }
    // 0x80134198: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8013419C: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341A0: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_801341E4;
    }
    // 0x801341A0: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x801341A4: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341A8: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_801341E4;
    }
    // 0x801341A8: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x801341AC: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341B0: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_801341E4;
    }
    // 0x801341B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x801341B4: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341B8: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_801341E4;
    }
    // 0x801341B8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x801341BC: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341C0: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_801341E4;
    }
    // 0x801341C0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x801341C4: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341C8: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_801341E4;
    }
    // 0x801341C8: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x801341CC: beq         $v0, $at, L_801341E4
    if (ctx->r2 == ctx->r1) {
        // 0x801341D0: nop
    
            goto L_801341E4;
    }
    // 0x801341D0: nop

    // 0x801341D4: beq         $s6, $v0, L_801341E4
    if (ctx->r22 == ctx->r2) {
        // 0x801341D8: addiu       $at, $zero, 0x33
        ctx->r1 = ADD32(0, 0X33);
            goto L_801341E4;
    }
    // 0x801341D8: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801341DC: bnel        $v0, $at, L_801341F0
    if (ctx->r2 != ctx->r1) {
        // 0x801341E0: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_801341F0;
    }
    goto skip_1;
    // 0x801341E0: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_1:
L_801341E4:
    // 0x801341E4: b           L_8013426C
    // 0x801341E8: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
        goto L_8013426C;
    // 0x801341E8: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
    // 0x801341EC: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
L_801341F0:
    // 0x801341F0: beq         $v1, $at, L_80134208
    if (ctx->r3 == ctx->r1) {
        // 0x801341F4: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_80134208;
    }
    // 0x801341F4: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x801341F8: beql        $v1, $at, L_8013420C
    if (ctx->r3 == ctx->r1) {
        // 0x801341FC: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8013420C;
    }
    goto skip_2;
    // 0x801341FC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80134200: bne         $s6, $v1, L_8013422C
    if (ctx->r22 != ctx->r3) {
        // 0x80134204: nop
    
            goto L_8013422C;
    }
    // 0x80134204: nop

L_80134208:
    // 0x80134208: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8013420C:
    // 0x8013420C: beq         $s7, $v0, L_80134224
    if (ctx->r23 == ctx->r2) {
        // 0x80134210: nop
    
            goto L_80134224;
    }
    // 0x80134210: nop

    // 0x80134214: beq         $fp, $v0, L_80134224
    if (ctx->r30 == ctx->r2) {
        // 0x80134218: nop
    
            goto L_80134224;
    }
    // 0x80134218: nop

    // 0x8013421C: bne         $s5, $v0, L_8013422C
    if (ctx->r21 != ctx->r2) {
        // 0x80134220: nop
    
            goto L_8013422C;
    }
    // 0x80134220: nop

L_80134224:
    // 0x80134224: b           L_8013426C
    // 0x80134228: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
        goto L_8013426C;
    // 0x80134228: sub.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f28.fl;
L_8013422C:
    // 0x8013422C: bnel        $s5, $v1, L_80134250
    if (ctx->r21 != ctx->r3) {
        // 0x80134230: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80134250;
    }
    goto skip_3;
    // 0x80134230: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_3:
    // 0x80134234: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80134238: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8013423C: bnel        $t8, $at, L_80134250
    if (ctx->r24 != ctx->r1) {
        // 0x80134240: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80134250;
    }
    goto skip_4;
    // 0x80134240: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    skip_4:
    // 0x80134244: b           L_8013426C
    // 0x80134248: sub.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f26.fl;
        goto L_8013426C;
    // 0x80134248: sub.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x8013424C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
L_80134250:
    // 0x80134250: bnel        $v1, $at, L_80134270
    if (ctx->r3 != ctx->r1) {
        // 0x80134254: add.s       $f0, $f20, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80134270;
    }
    goto skip_5;
    // 0x80134254: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
    skip_5:
    // 0x80134258: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8013425C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80134260: bnel        $t9, $at, L_80134270
    if (ctx->r25 != ctx->r1) {
        // 0x80134264: add.s       $f0, $f20, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_80134270;
    }
    goto skip_6;
    // 0x80134264: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
    skip_6:
    // 0x80134268: sub.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f26.fl;
L_8013426C:
    // 0x8013426C: add.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f22.fl;
L_80134270:
    // 0x80134270: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
    // 0x80134274: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80134278: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013427C: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x80134280: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80134284: add.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80134288: bne         $v0, $at, L_801342A4
    if (ctx->r2 != ctx->r1) {
        // 0x8013428C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801342A4;
    }
    // 0x8013428C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134290: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134294: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80134298: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013429C: swc1        $f8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f8.u32l;
    // 0x801342A0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_801342A4:
    // 0x801342A4: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x801342A8: bnel        $v0, $at, L_801342C0
    if (ctx->r2 != ctx->r1) {
        // 0x801342AC: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_801342C0;
    }
    goto skip_7;
    // 0x801342AC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_7:
    // 0x801342B0: sub.s       $f10, $f30, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f24.fl;
    // 0x801342B4: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    // 0x801342B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801342BC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_801342C0:
    // 0x801342C0: beq         $v0, $at, L_801342DC
    if (ctx->r2 == ctx->r1) {
        // 0x801342C4: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_801342DC;
    }
    // 0x801342C4: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x801342C8: beq         $v0, $at, L_801342DC
    if (ctx->r2 == ctx->r1) {
        // 0x801342CC: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_801342DC;
    }
    // 0x801342CC: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x801342D0: beql        $v0, $at, L_801342E0
    if (ctx->r2 == ctx->r1) {
        // 0x801342D4: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_801342E0;
    }
    goto skip_8;
    // 0x801342D4: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    skip_8:
    // 0x801342D8: bne         $s6, $v0, L_801342F0
    if (ctx->r22 != ctx->r2) {
        // 0x801342DC: lui         $at, 0xC100
        ctx->r1 = S32(0XC100 << 16);
            goto L_801342F0;
    }
L_801342DC:
    // 0x801342DC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
L_801342E0:
    // 0x801342E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801342E4: nop

    // 0x801342E8: swc1        $f16, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f16.u32l;
    // 0x801342EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_801342F0:
    // 0x801342F0: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x801342F4: bne         $v0, $at, L_80134308
    if (ctx->r2 != ctx->r1) {
        // 0x801342F8: nop
    
            goto L_80134308;
    }
    // 0x801342F8: nop

    // 0x801342FC: lwc1        $f18, 0x20($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80134300: sub.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f26.fl;
    // 0x80134304: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
L_80134308:
    // 0x80134308: lw          $t0, -0x5748($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5748);
    // 0x8013430C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134310: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80134314: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80134318: lw          $v1, 0x64F8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X64F8);
L_8013431C:
    // 0x8013431C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80134320: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80134324: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80134328: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8013432C: bne         $at, $zero, L_80134074
    if (ctx->r1 != 0) {
        // 0x80134330: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80134074;
    }
    // 0x80134330: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80134334:
    // 0x80134334: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80134338: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8013433C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80134340: jal         0x80133A0C
    // 0x80134344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    scStaffrollJobAndNameInitStruct(rdram, ctx);
        goto after_6;
    // 0x80134344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80134348: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013434C: addiu       $a1, $a1, 0x369C
    ctx->r5 = ADD32(ctx->r5, 0X369C);
    // 0x80134350: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80134354: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134358: jal         0x80008188
    // 0x8013435C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x8013435C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80134360: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80134364: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x80134368: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8013436C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80134370: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80134374: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80134378: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8013437C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80134380: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80134384: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80134388: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8013438C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80134390: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80134394: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80134398: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8013439C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x801343A0: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x801343A4: jr          $ra
    // 0x801343A8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x801343A8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void ftComputerCheckTargetItemOrTwister(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B4C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80134B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134B54: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80134B58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134B5C: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80134B60: lwc1        $f16, 0x4C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80134B64: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80134B68: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80134B6C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80134B70: lw          $a1, 0x6700($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6700);
    // 0x80134B74: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80134B78: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80134B7C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80134B80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80134B84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134B88: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80134B8C: beq         $a1, $zero, L_80134D40
    if (ctx->r5 == 0) {
        // 0x80134B90: add.s       $f14, $f10, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
            goto L_80134D40;
    }
    // 0x80134B90: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80134B94: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x80134B98: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80134B9C: addiu       $t0, $t0, 0x50E8
    ctx->r8 = ADD32(ctx->r8, 0X50E8);
    // 0x80134BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80134BA4: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80134BA8: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
L_80134BAC:
    // 0x80134BAC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80134BB0: beql        $a2, $t6, L_80134D38
    if (ctx->r6 == ctx->r14) {
        // 0x80134BB4: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80134D38;
    }
    goto skip_0;
    // 0x80134BB4: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80134BB8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80134BBC: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80134BC0: bnel        $a0, $t7, L_80134BE8
    if (ctx->r4 != ctx->r15) {
        // 0x80134BC4: lw          $t4, 0xC($v0)
        ctx->r12 = MEM_W(ctx->r2, 0XC);
            goto L_80134BE8;
    }
    goto skip_1;
    // 0x80134BC4: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    skip_1:
    // 0x80134BC8: lbu         $t8, 0x9($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X9);
    // 0x80134BCC: bnel        $t8, $zero, L_80134BE8
    if (ctx->r24 != 0) {
        // 0x80134BD0: lw          $t4, 0xC($v0)
        ctx->r12 = MEM_W(ctx->r2, 0XC);
            goto L_80134BE8;
    }
    goto skip_2;
    // 0x80134BD0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    skip_2:
    // 0x80134BD4: lbu         $t9, 0xC($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XC);
    // 0x80134BD8: lbu         $t3, 0x14($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X14);
    // 0x80134BDC: beql        $t9, $t3, L_80134D38
    if (ctx->r25 == ctx->r11) {
        // 0x80134BE0: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80134D38;
    }
    goto skip_3;
    // 0x80134BE0: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_3:
    // 0x80134BE4: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
L_80134BE8:
    // 0x80134BE8: bnel        $t1, $t4, L_80134C04
    if (ctx->r9 != ctx->r12) {
        // 0x80134BEC: lw          $v1, 0x10C($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10C);
            goto L_80134C04;
    }
    goto skip_4;
    // 0x80134BEC: lw          $v1, 0x10C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10C);
    skip_4:
    // 0x80134BF0: lbu         $t5, 0x2CF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2CF);
    // 0x80134BF4: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80134BF8: beql        $t2, $t6, L_80134C28
    if (ctx->r10 == ctx->r14) {
        // 0x80134BFC: lw          $t9, 0x160($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X160);
            goto L_80134C28;
    }
    goto skip_5;
    // 0x80134BFC: lw          $t9, 0x160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X160);
    skip_5:
    // 0x80134C00: lw          $v1, 0x10C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10C);
L_80134C04:
    // 0x80134C04: beql        $v1, $zero, L_80134D38
    if (ctx->r3 == 0) {
        // 0x80134C08: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80134D38;
    }
    goto skip_6;
    // 0x80134C08: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_6:
    // 0x80134C0C: beql        $a0, $v1, L_80134D38
    if (ctx->r4 == ctx->r3) {
        // 0x80134C10: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80134D38;
    }
    goto skip_7;
    // 0x80134C10: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_7:
    // 0x80134C14: lbu         $t7, 0x154($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X154);
    // 0x80134C18: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80134C1C: beql        $t8, $zero, L_80134D38
    if (ctx->r24 == 0) {
        // 0x80134C20: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80134D38;
    }
    goto skip_8;
    // 0x80134C20: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_8:
    // 0x80134C24: lw          $t9, 0x160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X160);
L_80134C28:
    // 0x80134C28: blez        $t9, L_80134D34
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80134C2C: addiu       $v1, $v0, 0x10C
        ctx->r3 = ADD32(ctx->r2, 0X10C);
            goto L_80134D34;
    }
    // 0x80134C2C: addiu       $v1, $v0, 0x10C
    ctx->r3 = ADD32(ctx->r2, 0X10C);
    // 0x80134C30: lwc1        $f0, 0x58($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80134C34: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80134C38: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80134C3C: nop

    // 0x80134C40: bc1fl       L_80134C58
    if (!c1cs) {
        // 0x80134C44: sub.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80134C58;
    }
    goto skip_9;
    // 0x80134C44: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    skip_9:
    // 0x80134C48: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80134C4C: b           L_80134C58
    // 0x80134C50: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80134C58;
    // 0x80134C50: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80134C54: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
L_80134C58:
    // 0x80134C58: lwc1        $f12, 0x2C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80134C5C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80134C60: nop

    // 0x80134C64: bc1f        L_80134D2C
    if (!c1cs) {
        // 0x80134C68: nop
    
            goto L_80134D2C;
    }
    // 0x80134C68: nop

    // 0x80134C6C: lwc1        $f0, 0x5C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x80134C70: addiu       $v0, $a3, 0x1CC
    ctx->r2 = ADD32(ctx->r7, 0X1CC);
    // 0x80134C74: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80134C78: nop

    // 0x80134C7C: bc1fl       L_80134C94
    if (!c1cs) {
        // 0x80134C80: sub.s       $f2, $f14, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_80134C94;
    }
    goto skip_10;
    // 0x80134C80: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
    skip_10:
    // 0x80134C84: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80134C88: b           L_80134C94
    // 0x80134C8C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80134C94;
    // 0x80134C8C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80134C90: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
L_80134C94:
    // 0x80134C94: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80134C98: nop

    // 0x80134C9C: bc1f        L_80134D2C
    if (!c1cs) {
        // 0x80134CA0: nop
    
            goto L_80134D2C;
    }
    // 0x80134CA0: nop

    // 0x80134CA4: lbu         $t3, 0x4A($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4A);
    // 0x80134CA8: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80134CAC: sb          $t4, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r12;
    // 0x80134CB0: lw          $t5, 0x14C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X14C);
    // 0x80134CB4: beql        $t5, $zero, L_80134D0C
    if (ctx->r13 == 0) {
        // 0x80134CB8: lw          $t6, 0x8E8($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X8E8);
            goto L_80134D0C;
    }
    goto skip_11;
    // 0x80134CB8: lw          $t6, 0x8E8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8E8);
    skip_11:
    // 0x80134CBC: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80134CC0: lwc1        $f6, 0x60($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80134CC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134CC8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80134CCC: nop

    // 0x80134CD0: bc1f        L_80134CEC
    if (!c1cs) {
        // 0x80134CD4: nop
    
            goto L_80134CEC;
    }
    // 0x80134CD4: nop

    // 0x80134CD8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134CDC: lwc1        $f4, -0x4258($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4258);
    // 0x80134CE0: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80134CE4: b           L_80134CF8
    // 0x80134CE8: swc1        $f8, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f8.u32l;
        goto L_80134CF8;
    // 0x80134CE8: swc1        $f8, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f8.u32l;
L_80134CEC:
    // 0x80134CEC: lwc1        $f16, -0x4254($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4254);
    // 0x80134CF0: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80134CF4: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
L_80134CF8:
    // 0x80134CF8: lwc1        $f18, 0x5C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x80134CFC: swc1        $f18, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f18.u32l;
    // 0x80134D00: b           L_80134E88
    // 0x80134D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134E88;
    // 0x80134D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80134D08: lw          $t6, 0x8E8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8E8);
L_80134D0C:
    // 0x80134D0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134D10: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80134D14: swc1        $f6, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f6.u32l;
    // 0x80134D18: lw          $t7, 0x8E8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8E8);
    // 0x80134D1C: lwc1        $f8, -0x4250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4250);
    // 0x80134D20: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80134D24: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80134D28: swc1        $f16, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f16.u32l;
L_80134D2C:
    // 0x80134D2C: b           L_80134E88
    // 0x80134D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134E88;
    // 0x80134D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134D34:
    // 0x80134D34: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_80134D38:
    // 0x80134D38: bnel        $a1, $zero, L_80134BAC
    if (ctx->r5 != 0) {
        // 0x80134D3C: lw          $v0, 0x84($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X84);
            goto L_80134BAC;
    }
    goto skip_12;
    // 0x80134D3C: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    skip_12:
L_80134D40:
    // 0x80134D40: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80134D44: addiu       $t0, $t0, 0x50E8
    ctx->r8 = ADD32(ctx->r8, 0X50E8);
    // 0x80134D48: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80134D4C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80134D50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80134D54: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80134D58: bnel        $t9, $at, L_80134E88
    if (ctx->r25 != ctx->r1) {
        // 0x80134D5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134E88;
    }
    goto skip_13;
    // 0x80134D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_13:
    // 0x80134D60: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80134D64: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x80134D68: jal         0x8010AC70
    // 0x80134D6C: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    grHyruleTwisterCheckGetPosition(rdram, ctx);
        goto after_0;
    // 0x80134D6C: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80134D70: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80134D74: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80134D78: beq         $v0, $zero, L_80134E84
    if (ctx->r2 == 0) {
        // 0x80134D7C: lwc1        $f14, 0x4C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80134E84;
    }
    // 0x80134D7C: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80134D80: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80134D84: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80134D88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134D8C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80134D90: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80134D94: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134D98: bc1fl       L_80134DB0
    if (!c1cs) {
        // 0x80134D9C: sub.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80134DB0;
    }
    goto skip_14;
    // 0x80134D9C: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    skip_14:
    // 0x80134DA0: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80134DA4: b           L_80134DB0
    // 0x80134DA8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80134DB0;
    // 0x80134DA8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80134DAC: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
L_80134DB0:
    // 0x80134DB0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80134DB4: nop

    // 0x80134DB8: bc1fl       L_80134E88
    if (!c1cs) {
        // 0x80134DBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134E88;
    }
    goto skip_15;
    // 0x80134DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_15:
    // 0x80134DC0: sub.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80134DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134DC8: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80134DCC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80134DD0: nop

    // 0x80134DD4: bc1fl       L_80134E88
    if (!c1cs) {
        // 0x80134DD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134E88;
    }
    goto skip_16;
    // 0x80134DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_16:
    // 0x80134DDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134DE0: addiu       $v0, $a3, 0x1CC
    ctx->r2 = ADD32(ctx->r7, 0X1CC);
    // 0x80134DE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80134DE8: nop

    // 0x80134DEC: bc1fl       L_80134E88
    if (!c1cs) {
        // 0x80134DF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134E88;
    }
    goto skip_17;
    // 0x80134DF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_17:
    // 0x80134DF4: lbu         $t3, 0x4A($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4A);
    // 0x80134DF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80134DFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134E00: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80134E04: sb          $t4, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r12;
    // 0x80134E08: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80134E0C: lw          $t5, 0x8E8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8E8);
    // 0x80134E10: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80134E14: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80134E18: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x80134E1C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80134E20: nop

    // 0x80134E24: bc1fl       L_80134E5C
    if (!c1cs) {
        // 0x80134E28: lwc1        $f16, 0x30($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80134E5C;
    }
    goto skip_18;
    // 0x80134E28: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    skip_18:
    // 0x80134E2C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80134E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134E34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134E38: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80134E3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80134E40: lwc1        $f8, -0x424C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X424C);
    // 0x80134E44: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134E48: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80134E4C: swc1        $f18, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f18.u32l;
    // 0x80134E50: b           L_80134E88
    // 0x80134E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134E88;
    // 0x80134E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80134E58: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
L_80134E5C:
    // 0x80134E5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134E60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134E64: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80134E68: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80134E6C: lwc1        $f8, -0x4248($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4248);
    // 0x80134E70: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134E74: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80134E78: swc1        $f18, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f18.u32l;
    // 0x80134E7C: b           L_80134E88
    // 0x80134E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134E88;
    // 0x80134E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134E84:
    // 0x80134E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134E88:
    // 0x80134E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134E8C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80134E90: jr          $ra
    // 0x80134E94: nop

    return;
    // 0x80134E94: nop

;}
RECOMP_FUNC void mvOpeningSectorMakeArwings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132290: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80132294: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132298: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8013229C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801322A0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801322A4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801322A8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801322AC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801322B0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801322B4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801322B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801322BC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801322C0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801322C4: addiu       $t7, $t7, 0x2930
    ctx->r15 = ADD32(ctx->r15, 0X2930);
    // 0x801322C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801322CC: addiu       $t6, $sp, 0x68
    ctx->r14 = ADD32(ctx->r29, 0X68);
    // 0x801322D0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801322D4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801322D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801322DC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801322E0: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801322E4: lui         $s5, 0x0
    ctx->r21 = S32(0X0 << 16);
    // 0x801322E8: lui         $s6, 0x8001
    ctx->r22 = S32(0X8001 << 16);
    // 0x801322EC: lui         $s7, 0x8001
    ctx->r23 = S32(0X8001 << 16);
    // 0x801322F0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801322F4: addiu       $s7, $s7, -0x20CC
    ctx->r23 = ADD32(ctx->r23, -0X20CC);
    // 0x801322F8: addiu       $s6, $s6, 0x4768
    ctx->r22 = ADD32(ctx->r22, 0X4768);
    // 0x801322FC: addiu       $s5, $s5, 0x2C30
    ctx->r21 = ADD32(ctx->r21, 0X2C30);
    // 0x80132300: addiu       $s4, $s4, 0x2C00
    ctx->r20 = ADD32(ctx->r20, 0X2C00);
    // 0x80132304: addiu       $s2, $s2, 0x2A28
    ctx->r18 = ADD32(ctx->r18, 0X2A28);
    // 0x80132308: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x8013230C: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80132310: addiu       $fp, $sp, 0x74
    ctx->r30 = ADD32(ctx->r29, 0X74);
    // 0x80132314: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132318: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
L_8013231C:
    // 0x8013231C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132324: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80132328: jal         0x80009968
    // 0x8013232C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013232C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80132330: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x80132334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132338: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8013233C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132344: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80132348: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013234C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80132350: jal         0x8000F590
    // 0x80132354: addu        $a1, $t0, $s5
    ctx->r5 = ADD32(ctx->r8, ctx->r21);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80132354: addu        $a1, $t0, $s5
    ctx->r5 = ADD32(ctx->r8, ctx->r21);
    after_1:
    // 0x80132358: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8013235C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132364: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80132368: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8013236C: jal         0x80009DF4
    // 0x80132370: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132370: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x80132374: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80132378: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8013237C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80132380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132384: jal         0x8000BD8C
    // 0x80132388: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80132388: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x8013238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132390: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80132394: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132398: jal         0x80008188
    // 0x8013239C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8013239C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801323A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801323A4: bne         $s1, $fp, L_8013231C
    if (ctx->r17 != ctx->r30) {
        // 0x801323A8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8013231C;
    }
    // 0x801323A8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801323AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801323B0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801323B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801323B8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801323BC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801323C0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801323C4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801323C8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801323CC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801323D0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801323D4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801323D8: jr          $ra
    // 0x801323DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801323DC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void itHitokageDamagedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183F20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80183F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183F28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80183F2C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80183F30: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80183F34: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80183F38: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80183F3C: jal         0x80172558
    // 0x80183F40: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80183F40: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80183F44: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80183F48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80183F4C: lwc1        $f4, -0x30EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30EC);
    // 0x80183F50: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80183F54: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80183F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80183F5C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80183F60: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x80183F64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80183F68: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80183F6C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80183F70: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80183F74: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
    // 0x80183F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80183F80: jr          $ra
    // 0x80183F84: nop

    return;
    // 0x80183F84: nop

;}
RECOMP_FUNC void func_ovl29_80133210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133210: jr          $ra
    // 0x80133214: nop

    return;
    // 0x80133214: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133EFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80133F00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133F04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133F08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133F10: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133F14: jal         0x80009968
    // 0x80133F18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133F18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133F1C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133F20: lw          $t6, 0x50B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B4);
    // 0x80133F24: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133F28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F2C: addiu       $t7, $t7, 0xF40
    ctx->r15 = ADD32(ctx->r15, 0XF40);
    // 0x80133F30: sw          $v0, 0x4D48($at)
    MEM_W(0X4D48, ctx->r1) = ctx->r2;
    // 0x80133F34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133F38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133F3C: jal         0x800092D0
    // 0x80133F40: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133F40: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80133F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80133F48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133F4C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80133F50: jal         0x80008CC0
    // 0x80133F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80133F54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80133F58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F5C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80133F60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80133F64: addiu       $a1, $a1, 0x3CEC
    ctx->r5 = ADD32(ctx->r5, 0X3CEC);
    // 0x80133F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F6C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80133F70: jal         0x80009DF4
    // 0x80133F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80133F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133F78: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133F7C: lw          $t9, 0x50B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B4);
    // 0x80133F80: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80133F84: addiu       $t0, $t0, 0x11C4
    ctx->r8 = ADD32(ctx->r8, 0X11C4);
    // 0x80133F88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80133F8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133F90: jal         0x8000BD1C
    // 0x80133F94: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x80133F94: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80133F98: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133F9C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80133FA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80133FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133FA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133FAC: jal         0x80008188
    // 0x80133FB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80133FB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80133FB4: jal         0x8000DF34
    // 0x80133FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x80133FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80133FBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133FC4: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133FC8: jal         0x80009968
    // 0x80133FCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_7;
    // 0x80133FCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_7:
    // 0x80133FD0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133FD4: lw          $t1, 0x50B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50B4);
    // 0x80133FD8: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80133FDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FE0: addiu       $t2, $t2, 0x5A0
    ctx->r10 = ADD32(ctx->r10, 0X5A0);
    // 0x80133FE4: sw          $v0, 0x4D4C($at)
    MEM_W(0X4D4C, ctx->r1) = ctx->r2;
    // 0x80133FE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133FEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133FF0: jal         0x800092D0
    // 0x80133FF4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjForGObj(rdram, ctx);
        goto after_8;
    // 0x80133FF4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_8:
    // 0x80133FF8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80133FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134000: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80134004: jal         0x80008CC0
    // 0x80134008: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_9;
    // 0x80134008: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8013400C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134010: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80134014: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80134018: addiu       $a1, $a1, 0x3B58
    ctx->r5 = ADD32(ctx->r5, 0X3B58);
    // 0x8013401C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134020: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80134024: jal         0x80009DF4
    // 0x80134028: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_10;
    // 0x80134028: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_10:
    // 0x8013402C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134030: lw          $t4, 0x50B4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50B4);
    // 0x80134034: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80134038: addiu       $t5, $t5, 0x714
    ctx->r13 = ADD32(ctx->r13, 0X714);
    // 0x8013403C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80134040: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80134044: jal         0x8000BD1C
    // 0x80134048: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_11;
    // 0x80134048: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_11:
    // 0x8013404C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134050: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80134054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80134058: jal         0x80008188
    // 0x8013405C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_12;
    // 0x8013405C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80134060: jal         0x8000DF34
    // 0x80134064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_13;
    // 0x80134064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80134068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013406C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80134070: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80134074: jr          $ra
    // 0x80134078: nop

    return;
    // 0x80134078: nop

;}
RECOMP_FUNC void ftCommonCaptureKirbyProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B914: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014B918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014B91C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014B920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014B924: jal         0x8014B774
    // 0x8014B928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonCaptureKirbyUpdatePositionsAll(rdram, ctx);
        goto after_0;
    // 0x8014B928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014B92C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8014B930: addiu       $at, $zero, 0xAD
    ctx->r1 = ADD32(0, 0XAD);
    // 0x8014B934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014B938: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8014B93C: bnel        $t6, $at, L_8014B95C
    if (ctx->r14 != ctx->r1) {
        // 0x8014B940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B95C;
    }
    goto skip_0;
    // 0x8014B940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014B944: lh          $t7, 0xB18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB18);
    // 0x8014B948: beql        $t7, $zero, L_8014B95C
    if (ctx->r15 == 0) {
        // 0x8014B94C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014B95C;
    }
    goto skip_1;
    // 0x8014B94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014B950: jal         0x8014BDB4
    // 0x8014B954: nop

    ftCommonCaptureWaitKirbySetStatus(rdram, ctx);
        goto after_1;
    // 0x8014B954: nop

    after_1:
    // 0x8014B958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014B95C:
    // 0x8014B95C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014B960: jr          $ra
    // 0x8014B964: nop

    return;
    // 0x8014B964: nop

;}
RECOMP_FUNC void itNBumperThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B728: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8017B72C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8017B730: addiu       $a2, $a2, -0x42B4
    ctx->r6 = ADD32(ctx->r6, -0X42B4);
    // 0x8017B734: jal         0x80173EE8
    // 0x8017B738: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckMapReboundProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017B738: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x8017B73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B744: jr          $ra
    // 0x8017B748: nop

    return;
    // 0x8017B748: nop

;}
RECOMP_FUNC void mnVSResultsGetTeamFirstPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137108: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013710C: lbu         $t6, 0x4D2C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D2C);
    // 0x80137110: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80137114: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80137118: bne         $a0, $t6, L_80137138
    if (ctx->r4 != ctx->r14) {
        // 0x8013711C: nop
    
            goto L_80137138;
    }
    // 0x8013711C: nop

    // 0x80137120: lbu         $t7, 0x4D2A($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D2A);
    // 0x80137124: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80137128: beq         $v0, $t7, L_80137138
    if (ctx->r2 == ctx->r15) {
        // 0x8013712C: nop
    
            goto L_80137138;
    }
    // 0x8013712C: nop

    // 0x80137130: jr          $ra
    // 0x80137134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80137134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137138:
    // 0x80137138: lbu         $t8, 0x4DA0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4DA0);
    // 0x8013713C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80137140: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80137144: bne         $a0, $t8, L_80137160
    if (ctx->r4 != ctx->r24) {
        // 0x80137148: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80137160;
    }
    // 0x80137148: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8013714C: lbu         $t9, 0x4D9E($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4D9E);
    // 0x80137150: beq         $v0, $t9, L_80137160
    if (ctx->r2 == ctx->r25) {
        // 0x80137154: nop
    
            goto L_80137160;
    }
    // 0x80137154: nop

    // 0x80137158: jr          $ra
    // 0x8013715C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8013715C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80137160:
    // 0x80137160: lbu         $t0, 0x4E14($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4E14);
    // 0x80137164: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80137168: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8013716C: bne         $a0, $t0, L_80137188
    if (ctx->r4 != ctx->r8) {
        // 0x80137170: nop
    
            goto L_80137188;
    }
    // 0x80137170: nop

    // 0x80137174: lbu         $t1, 0x4E12($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4E12);
    // 0x80137178: beq         $v0, $t1, L_80137188
    if (ctx->r2 == ctx->r9) {
        // 0x8013717C: nop
    
            goto L_80137188;
    }
    // 0x8013717C: nop

    // 0x80137180: jr          $ra
    // 0x80137184: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80137184: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80137188:
    // 0x80137188: lbu         $t2, 0x4E88($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4E88);
    // 0x8013718C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80137190: bnel        $a0, $t2, L_801371B0
    if (ctx->r4 != ctx->r10) {
        // 0x80137194: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801371B0;
    }
    goto skip_0;
    // 0x80137194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80137198: lbu         $t3, 0x4E86($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4E86);
    // 0x8013719C: beql        $v0, $t3, L_801371B0
    if (ctx->r2 == ctx->r11) {
        // 0x801371A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801371B0;
    }
    goto skip_1;
    // 0x801371A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801371A4: jr          $ra
    // 0x801371A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x801371A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801371AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801371B0:
    // 0x801371B0: jr          $ra
    // 0x801371B4: nop

    return;
    // 0x801371B4: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNCopySwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162F10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162F14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162F18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162F1C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162F20: jal         0x800DEE98
    // 0x80162F24: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162F24: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162F28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162F2C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162F30: addiu       $a1, $zero, 0x115
    ctx->r5 = ADD32(0, 0X115);
    // 0x80162F34: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162F38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162F3C: jal         0x800E6F24
    // 0x80162F40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162F40: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162F44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162F48: jal         0x800E8098
    // 0x80162F4C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162F4C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162F54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162F58: jr          $ra
    // 0x80162F5C: nop

    return;
    // 0x80162F5C: nop

;}
RECOMP_FUNC void gcAddSiblingForDObjTraRotSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F0C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F0C8: jal         0x80009380
    // 0x8000F0CC: nop

    gcAddSiblingForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F0CC: nop

    after_0:
    // 0x8000F0D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000F0D4: jal         0x8000F058
    // 0x8000F0D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjTransformTraRotSca(rdram, ctx);
        goto after_1;
    // 0x8000F0D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000F0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F0E0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F0E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F0E8: jr          $ra
    // 0x8000F0EC: nop

    return;
    // 0x8000F0EC: nop

;}
RECOMP_FUNC void n_alSynSetPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002F6A4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002F6A8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002F6AC: jr          $ra
    // 0x8002F6B0: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
    return;
    // 0x8002F6B0: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void ftCommonGuardUpdateShieldCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148408: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8014840C: lw          $v0, 0x8F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8F4);
    // 0x80148410: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148414: bne         $t6, $at, L_8014842C
    if (ctx->r14 != ctx->r1) {
        // 0x80148418: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_8014842C;
    }
    // 0x80148418: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8014841C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80148420: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80148424: b           L_80148448
    // 0x80148428: nop

        goto L_80148448;
    // 0x80148428: nop

L_8014842C:
    // 0x8014842C: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80148430: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80148434: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80148438: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8014843C: nop

    // 0x80148440: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80148444: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_80148448:
    // 0x80148448: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014844C: lwc1        $f10, -0x3E20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E20);
    // 0x80148450: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80148454: lwc1        $f18, -0x3E1C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3E1C);
    // 0x80148458: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8014845C: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
    // 0x80148460: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80148464: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80148468: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8014846C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80148470: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80148474: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80148478: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8014847C: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80148480: jr          $ra
    // 0x80148484: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    return;
    // 0x80148484: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
;}
RECOMP_FUNC void itBombHeiWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017747C: jal         0x80172E74
    // 0x80177480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80177480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80177484: jal         0x80177208
    // 0x80177488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_1;
    // 0x80177488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017748C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177490: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177498: jal         0x80172EC8
    // 0x8017749C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017749C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801774A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801774A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801774A8: jr          $ra
    // 0x801774AC: nop

    return;
    // 0x801774AC: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152898: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015289C: jal         0x800DE80C
    // 0x801528A0: addiu       $a1, $a1, 0x28B4
    ctx->r5 = ADD32(ctx->r5, 0X28B4);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x801528A0: addiu       $a1, $a1, 0x28B4
    ctx->r5 = ADD32(ctx->r5, 0X28B4);
    after_0:
    // 0x801528A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801528A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801528AC: jr          $ra
    // 0x801528B0: nop

    return;
    // 0x801528B0: nop

;}
RECOMP_FUNC void ftCommonThrownSetStatusDamageRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B330: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8014B334: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014B338: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8014B33C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8014B340: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8014B344: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014B348: lw          $t7, 0x844($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X844);
    // 0x8014B34C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x8014B350: lwc1        $f2, 0x7E4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7E4);
    // 0x8014B354: lwc1        $f0, 0x7E8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7E8);
    // 0x8014B358: lw          $s1, 0x84($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X84);
    // 0x8014B35C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8014B360: nop

    // 0x8014B364: bc1fl       L_8014B378
    if (!c1cs) {
        // 0x8014B368: swc1        $f0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
            goto L_8014B378;
    }
    goto skip_0;
    // 0x8014B368: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    skip_0:
    // 0x8014B36C: b           L_8014B378
    // 0x8014B370: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
        goto L_8014B378;
    // 0x8014B370: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8014B374: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_8014B378:
    // 0x8014B378: lw          $t9, 0x5B8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5B8);
    // 0x8014B37C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014B380: beql        $t9, $at, L_8014B398
    if (ctx->r25 == ctx->r1) {
        // 0x8014B384: lw          $t1, 0x190($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X190);
            goto L_8014B398;
    }
    goto skip_1;
    // 0x8014B384: lw          $t1, 0x190($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X190);
    skip_1:
    // 0x8014B388: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8014B38C: jal         0x800E8A24
    // 0x8014B390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_0;
    // 0x8014B390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8014B394: lw          $t1, 0x190($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X190);
L_8014B398:
    // 0x8014B398: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x8014B39C: bltzl       $t3, L_8014B3B0
    if (SIGNED(ctx->r11) < 0) {
        // 0x8014B3A0: lw          $t4, 0x14C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X14C);
            goto L_8014B3B0;
    }
    goto skip_2;
    // 0x8014B3A0: lw          $t4, 0x14C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C);
    skip_2:
    // 0x8014B3A4: jal         0x8014ADB0
    // 0x8014B3A8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_1;
    // 0x8014B3A8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8014B3AC: lw          $t4, 0x14C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C);
L_8014B3B0:
    // 0x8014B3B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014B3B4: bnel        $t4, $at, L_8014B3C8
    if (ctx->r12 != ctx->r1) {
        // 0x8014B3B8: lw          $v1, 0x848($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X848);
            goto L_8014B3C8;
    }
    goto skip_3;
    // 0x8014B3B8: lw          $v1, 0x848($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X848);
    skip_3:
    // 0x8014B3BC: jal         0x800DEEC8
    // 0x8014B3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_2;
    // 0x8014B3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8014B3C4: lw          $v1, 0x848($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X848);
L_8014B3C8:
    // 0x8014B3C8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8014B3CC: lw          $t5, 0x28($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X28);
    // 0x8014B3D0: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    // 0x8014B3D4: lw          $a3, 0x2C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X2C);
    // 0x8014B3D8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8014B3DC: lw          $t6, 0x30($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X30);
    // 0x8014B3E0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8014B3E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8014B3E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8014B3EC: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014B3F0: lwc1        $f4, 0x68($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8014B3F4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8014B3F8: lbu         $t8, 0x12($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X12);
    // 0x8014B3FC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8014B400: lbu         $t9, 0x12($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X12);
    // 0x8014B404: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8014B408: jal         0x800E9D78
    // 0x8014B40C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_3;
    // 0x8014B40C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_3:
    // 0x8014B410: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8014B414: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8014B418: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8014B41C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8014B420: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8014B424: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8014B428: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8014B42C: bc1fl       L_8014B440
    if (!c1cs) {
        // 0x8014B430: lw          $t2, 0x74($t1)
        ctx->r10 = MEM_W(ctx->r9, 0X74);
            goto L_8014B440;
    }
    goto skip_4;
    // 0x8014B430: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    skip_4:
    // 0x8014B434: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8014B438: nop

    // 0x8014B43C: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
L_8014B440:
    // 0x8014B440: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x8014B444: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8014B448: lwc1        $f10, 0x1C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8014B44C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8014B450: nop

    // 0x8014B454: bc1f        L_8014B464
    if (!c1cs) {
        // 0x8014B458: nop
    
            goto L_8014B464;
    }
    // 0x8014B458: nop

    // 0x8014B45C: b           L_8014B464
    // 0x8014B460: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8014B464;
    // 0x8014B460: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8014B464:
    // 0x8014B464: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B468: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8014B46C: lw          $a2, 0x288($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X288);
    // 0x8014B470: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    // 0x8014B474: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8014B478: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8014B47C: jal         0x800EA54C
    // 0x8014B480: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    ftParamGetStaledDamage(rdram, ctx);
        goto after_4;
    // 0x8014B480: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_4:
    // 0x8014B484: lw          $t5, 0x190($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X190);
    // 0x8014B488: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8014B48C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8014B490: sll         $t7, $t5, 21
    ctx->r15 = S32(ctx->r13 << 21);
    // 0x8014B494: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8014B498: bgez        $t7, L_8014B4CC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8014B49C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8014B4CC;
    }
    // 0x8014B49C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014B4A0: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8014B4A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014B4A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014B4AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014B4B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014B4B4: lwc1        $f8, -0x3DEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3DEC);
    // 0x8014B4B8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8014B4BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014B4C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8014B4C4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8014B4C8: nop

L_8014B4CC:
    // 0x8014B4CC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8014B4D0: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8014B4D4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014B4D8: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8014B4DC: jal         0x800E8AAC
    // 0x8014B4E0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_5;
    // 0x8014B4E0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8014B4E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014B4E8: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8014B4EC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8014B4F0: beq         $v0, $at, L_8014B4FC
    if (ctx->r2 == ctx->r1) {
        // 0x8014B4F4: lwc1        $f2, 0x4C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_8014B4FC;
    }
    // 0x8014B4F4: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8014B4F8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8014B4FC:
    // 0x8014B4FC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8014B500: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8014B504: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8014B508: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8014B50C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014B510: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8014B514: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014B518: lw          $t2, 0x18($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X18);
    // 0x8014B51C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8014B520: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014B524: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8014B528: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8014B52C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8014B530: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8014B534: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8014B538: jal         0x80140EE4
    // 0x8014B53C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_6;
    // 0x8014B53C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_6:
    // 0x8014B540: lhu         $t4, 0x28E($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X28E);
    // 0x8014B544: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B548: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8014B54C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8014B550: lhu         $t5, 0x290($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X290);
    // 0x8014B554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014B558: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014B55C: jal         0x800EAA2C
    // 0x8014B560: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_7;
    // 0x8014B560: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_7:
    // 0x8014B564: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8014B568: beql        $a1, $zero, L_8014B5A0
    if (ctx->r5 == 0) {
        // 0x8014B56C: sw          $zero, 0x844($s0)
        MEM_W(0X844, ctx->r16) = 0;
            goto L_8014B5A0;
    }
    goto skip_5;
    // 0x8014B56C: sw          $zero, 0x844($s0)
    MEM_W(0X844, ctx->r16) = 0;
    skip_5:
    // 0x8014B570: jal         0x800EA248
    // 0x8014B574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamUpdateDamage(rdram, ctx);
        goto after_8;
    // 0x8014B574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8014B578: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B57C: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B580: jal         0x800EA98C
    // 0x8014B584: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_9;
    // 0x8014B584: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x8014B588: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014B58C: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B590: lw          $a2, 0x288($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X288);
    // 0x8014B594: jal         0x800EA614
    // 0x8014B598: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_10;
    // 0x8014B598: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    after_10:
    // 0x8014B59C: sw          $zero, 0x844($s0)
    MEM_W(0X844, ctx->r16) = 0;
L_8014B5A0:
    // 0x8014B5A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014B5A4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8014B5A8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8014B5AC: jr          $ra
    // 0x8014B5B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8014B5B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnPlayers1PTrainingPuckAdjustPlaced(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136A44: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136A48: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80136A4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80136A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136A54: bne         $a0, $v0, L_80136A68
    if (ctx->r4 != ctx->r2) {
        // 0x80136A58: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80136A68;
    }
    // 0x80136A58: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80136A5C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80136A60: b           L_80136A6C
    // 0x80136A64: lw          $a1, -0x7768($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7768);
        goto L_80136A6C;
    // 0x80136A64: lw          $a1, -0x7768($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7768);
L_80136A68:
    // 0x80136A68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80136A6C:
    // 0x80136A6C: beq         $a3, $a1, L_80136ADC
    if (ctx->r7 == ctx->r5) {
        // 0x80136A70: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_80136ADC;
    }
    // 0x80136A70: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80136A74: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80136A78: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80136A7C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136A80: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80136A84: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136A88: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80136A8C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136A90: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80136A94: lw          $t8, 0x54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X54);
    // 0x80136A98: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80136A9C: beql        $t8, $zero, L_80136AD0
    if (ctx->r24 == 0) {
        // 0x80136AA0: sll         $t1, $a1, 2
        ctx->r9 = S32(ctx->r5 << 2);
            goto L_80136AD0;
    }
    goto skip_0;
    // 0x80136AA0: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    skip_0:
    // 0x80136AA4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80136AA8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80136AAC: jal         0x801366D0
    // 0x80136AB0: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    mnPlayers1PTrainingGetPuckDistance(rdram, ctx);
        goto after_0;
    // 0x80136AB0: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80136AB4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80136AB8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80136ABC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80136AC0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80136AC4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x80136AC8: swc1        $f0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f0.u32l;
    // 0x80136ACC: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
L_80136AD0:
    // 0x80136AD0: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x80136AD4: b           L_80136B10
    // 0x80136AD8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
        goto L_80136B10;
    // 0x80136AD8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_80136ADC:
    // 0x80136ADC: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80136AE0: subu        $t5, $t5, $a3
    ctx->r13 = SUB32(ctx->r13, ctx->r7);
    // 0x80136AE4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80136AE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136AEC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80136AF0: subu        $t5, $t5, $a3
    ctx->r13 = SUB32(ctx->r13, ctx->r7);
    // 0x80136AF4: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x80136AF8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136AFC: addiu       $t6, $t6, -0x7AA8
    ctx->r14 = ADD32(ctx->r14, -0X7AA8);
    // 0x80136B00: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80136B04: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80136B08: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80136B0C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_80136B10:
    // 0x80136B10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80136B14: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80136B18: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80136B1C: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80136B20: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80136B24: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80136B28: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80136B2C: swc1        $f0, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f0.u32l;
    // 0x80136B30: bc1f        L_80136B58
    if (!c1cs) {
        // 0x80136B34: swc1        $f0, 0x90($v1)
        MEM_W(0X90, ctx->r3) = ctx->f0.u32l;
            goto L_80136B58;
    }
    // 0x80136B34: swc1        $f0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f0.u32l;
    // 0x80136B38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136B3C: nop

    // 0x80136B40: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80136B44: nop

    // 0x80136B48: bc1fl       L_80136B5C
    if (!c1cs) {
        // 0x80136B4C: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80136B5C;
    }
    goto skip_1;
    // 0x80136B4C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_1:
    // 0x80136B50: b           L_80136B64
    // 0x80136B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136B64;
    // 0x80136B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136B58:
    // 0x80136B58: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80136B5C:
    // 0x80136B5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136B64:
    // 0x80136B64: beq         $v0, $zero, L_80136BC8
    if (ctx->r2 == 0) {
        // 0x80136B68: subu        $t7, $t7, $a1
        ctx->r15 = SUB32(ctx->r15, ctx->r5);
            goto L_80136BC8;
    }
    // 0x80136B68: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80136B6C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136B70: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80136B74: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80136B78: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80136B7C: lw          $t9, 0x48($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X48);
    // 0x80136B80: lw          $v0, 0x48($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X48);
    // 0x80136B84: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80136B88: bne         $v0, $t9, L_80136BC8
    if (ctx->r2 != ctx->r25) {
        // 0x80136B8C: nop
    
            goto L_80136BC8;
    }
    // 0x80136B8C: nop

    // 0x80136B90: beq         $v0, $at, L_80136BC8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B94: nop
    
            goto L_80136BC8;
    }
    // 0x80136B94: nop

    // 0x80136B98: lw          $t0, 0x54($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X54);
    // 0x80136B9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136BA0: bne         $t0, $at, L_80136BC8
    if (ctx->r8 != ctx->r1) {
        // 0x80136BA4: nop
    
            goto L_80136BC8;
    }
    // 0x80136BA4: nop

    // 0x80136BA8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80136BAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80136BB0: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80136BB4: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80136BB8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80136BBC: jal         0x80136748
    // 0x80136BC0: nop

    mnPlayers1PTrainingPuckAdjustOverlap(rdram, ctx);
        goto after_1;
    // 0x80136BC0: nop

    after_1:
    // 0x80136BC4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
L_80136BC8:
    // 0x80136BC8: jal         0x80136888
    // 0x80136BCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    mnPlayers1PTrainingPuckAdjustPortraitEdge(rdram, ctx);
        goto after_2;
    // 0x80136BCC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80136BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136BD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80136BD8: jr          $ra
    // 0x80136BDC: nop

    return;
    // 0x80136BDC: nop

;}
RECOMP_FUNC void mvOpeningDonkeyStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E018: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E020: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E024: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E028: addiu       $a0, $a0, -0x1F20
    ctx->r4 = ADD32(ctx->r4, -0X1F20);
    // 0x8018E02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E030: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E034: jal         0x80007024
    // 0x8018E038: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E038: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E03C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E040: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E044: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E048: addiu       $t9, $t9, -0x1A20
    ctx->r25 = ADD32(ctx->r25, -0X1A20);
    // 0x8018E04C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E050: addiu       $a0, $a0, -0x1F04
    ctx->r4 = ADD32(ctx->r4, -0X1F04);
    // 0x8018E054: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E058: jal         0x8000683C
    // 0x8018E05C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E05C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E068: jr          $ra
    // 0x8018E06C: nop

    return;
    // 0x8018E06C: nop

;}
RECOMP_FUNC void mnVSItemSwitchStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331B0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801331B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801331B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331BC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801331C0: addiu       $a0, $a0, 0x3320
    ctx->r4 = ADD32(ctx->r4, 0X3320);
    // 0x801331C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801331C8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801331CC: jal         0x80007024
    // 0x801331D0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801331D0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801331D4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801331D8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801331DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331E0: addiu       $t9, $t9, 0x3540
    ctx->r25 = ADD32(ctx->r25, 0X3540);
    // 0x801331E4: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801331E8: addiu       $a0, $a0, 0x333C
    ctx->r4 = ADD32(ctx->r4, 0X333C);
    // 0x801331EC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801331F0: jal         0x8000683C
    // 0x801331F4: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801331F4: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801331F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801331FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133200: jr          $ra
    // 0x80133204: nop

    return;
    // 0x80133204: nop

;}
RECOMP_FUNC void dbBattleFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013239C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x801323A0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801323A4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801323A8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801323AC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801323B0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801323B4: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801323B8: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801323BC: addiu       $t8, $t8, 0x2C28
    ctx->r24 = ADD32(ctx->r24, 0X2C28);
    // 0x801323C0: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801323C4: addiu       $t0, $t0, 0x30D8
    ctx->r8 = ADD32(ctx->r8, 0X30D8);
    // 0x801323C8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801323CC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801323D0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801323D4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801323D8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801323DC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801323E0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801323E4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801323E8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801323EC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801323F0: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x801323F4: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x801323F8: sw          $zero, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = 0;
    // 0x801323FC: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x80132400: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x80132404: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x80132408: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x8013240C: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x80132410: jal         0x800CDF78
    // 0x80132414: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132414: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    after_0:
    // 0x80132418: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013241C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132420: addiu       $a1, $a1, 0x1F3C
    ctx->r5 = ADD32(ctx->r5, 0X1F3C);
    // 0x80132424: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013242C: jal         0x80009968
    // 0x80132430: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80132430: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x80132434: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132438: addiu       $a1, $a1, 0x2238
    ctx->r5 = ADD32(ctx->r5, 0X2238);
    // 0x8013243C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132440: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132444: jal         0x80008188
    // 0x80132448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132448: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8013244C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132450: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132454: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80132458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013245C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132460: jal         0x8000B9FC
    // 0x80132464: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_3;
    // 0x80132464: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80132468: jal         0x80115890
    // 0x8013246C: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8013246C: nop

    after_4:
    // 0x80132470: jal         0x801322DC
    // 0x80132474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dbBattleMakeCamera(rdram, ctx);
        goto after_5;
    // 0x80132474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80132478: jal         0x800FD300
    // 0x8013247C: nop

    efManagerInitEffects(rdram, ctx);
        goto after_6;
    // 0x8013247C: nop

    after_6:
    // 0x80132480: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80132484: jal         0x800D7194
    // 0x80132488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_7;
    // 0x80132488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8013248C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80132490:
    // 0x80132490: jal         0x800D786C
    // 0x80132494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_8;
    // 0x80132494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80132498: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013249C: slti        $at, $s0, 0x1B
    ctx->r1 = SIGNED(ctx->r16) < 0X1B ? 1 : 0;
    // 0x801324A0: bne         $at, $zero, L_80132490
    if (ctx->r1 != 0) {
        // 0x801324A4: nop
    
            goto L_80132490;
    }
    // 0x801324A4: nop

    // 0x801324A8: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x801324AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801324B0: addiu       $v0, $v0, 0x2924
    ctx->r2 = ADD32(ctx->r2, 0X2924);
    // 0x801324B4: addiu       $s1, $s1, 0x4D08
    ctx->r17 = ADD32(ctx->r17, 0X4D08);
    // 0x801324B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801324BC:
    // 0x801324BC: sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    // 0x801324C0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801324C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801324C8: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801324CC: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x801324D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801324D4: sb          $zero, -0x52($s1)
    MEM_B(-0X52, ctx->r17) = 0;
    // 0x801324D8: sb          $zero, -0x4D($s1)
    MEM_B(-0X4D, ctx->r17) = 0;
    // 0x801324DC: bne         $at, $zero, L_801324BC
    if (ctx->r1 != 0) {
        // 0x801324E0: sb          $t3, -0x51($s1)
        MEM_B(-0X51, ctx->r17) = ctx->r11;
            goto L_801324BC;
    }
    // 0x801324E0: sb          $t3, -0x51($s1)
    MEM_B(-0X51, ctx->r17) = ctx->r11;
    // 0x801324E4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x801324E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801324EC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801324F0: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x801324F4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801324F8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801324FC: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80132500: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132504: addiu       $s4, $s4, 0x6DD0
    ctx->r20 = ADD32(ctx->r20, 0X6DD0);
    // 0x80132508: addiu       $s5, $s5, 0xD9C
    ctx->r21 = ADD32(ctx->r21, 0XD9C);
    // 0x8013250C: addiu       $s2, $s2, 0x3110
    ctx->r18 = ADD32(ctx->r18, 0X3110);
    // 0x80132510: addiu       $s1, $s1, 0x4D08
    ctx->r17 = ADD32(ctx->r17, 0X4D08);
    // 0x80132514: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132518: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8013251C: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
L_80132520:
    // 0x80132520: or          $t6, $s4, $zero
    ctx->r14 = ctx->r20 | 0;
    // 0x80132524: or          $t7, $s3, $zero
    ctx->r15 = ctx->r19 | 0;
    // 0x80132528: addiu       $t8, $s4, 0x3C
    ctx->r24 = ADD32(ctx->r20, 0X3C);
L_8013252C:
    // 0x8013252C: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80132530: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132534: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132538: sw          $t5, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r13;
    // 0x8013253C: lw          $t4, -0x8($t6)
    ctx->r12 = MEM_W(ctx->r14, -0X8);
    // 0x80132540: sw          $t4, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r12;
    // 0x80132544: lw          $t5, -0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, -0X4);
    // 0x80132548: bne         $t6, $t8, L_8013252C
    if (ctx->r14 != ctx->r24) {
        // 0x8013254C: sw          $t5, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r13;
            goto L_8013252C;
    }
    // 0x8013254C: sw          $t5, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r13;
    // 0x80132550: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80132554: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80132558: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8013255C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132560: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80132564: lbu         $t9, 0x23($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X23);
    // 0x80132568: lbu         $t0, 0x26($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X26);
    // 0x8013256C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80132570: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80132574: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80132578: sb          $t0, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r8;
    // 0x8013257C: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80132580: jal         0x80004980
    // 0x80132584: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    syTaskmanMalloc(rdram, ctx);
        goto after_9;
    // 0x80132584: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80132588: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8013258C: jal         0x800D7F3C
    // 0x80132590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_10;
    // 0x80132590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x80132594: lbu         $t1, 0x23($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X23);
    // 0x80132598: lbu         $t2, 0x26($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X26);
    // 0x8013259C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801325A0: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x801325A4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x801325A8: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x801325AC: sb          $t1, -0x8($s2)
    MEM_B(-0X8, ctx->r18) = ctx->r9;
    // 0x801325B0: bne         $s0, $s6, L_80132520
    if (ctx->r16 != ctx->r22) {
        // 0x801325B4: sb          $t2, -0x7($s2)
        MEM_B(-0X7, ctx->r18) = ctx->r10;
            goto L_80132520;
    }
    // 0x801325B4: sb          $t2, -0x7($s2)
    MEM_B(-0X7, ctx->r18) = ctx->r10;
    // 0x801325B8: jal         0x80369EE0
    // 0x801325BC: nop

    dbMenuInitMenu(rdram, ctx);
        goto after_11;
    // 0x801325BC: nop

    after_11:
    // 0x801325C0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801325C4: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x801325C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801325CC: addiu       $a3, $a3, 0x2780
    ctx->r7 = ADD32(ctx->r7, 0X2780);
    // 0x801325D0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801325D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801325D8: jal         0x80369D78
    // 0x801325DC: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    dbMenuMakeMenu(rdram, ctx);
        goto after_12;
    // 0x801325DC: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    after_12:
    // 0x801325E0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801325E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801325E8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801325EC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801325F0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801325F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801325F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801325FC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132600: jal         0x803904E0
    // 0x80132604: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_13;
    // 0x80132604: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_13:
    // 0x80132608: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8013260C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80132610: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80132614: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80132618: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8013261C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80132620: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80132624: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80132628: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8013262C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80132630: jr          $ra
    // 0x80132634: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80132634: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_ovl8_803840C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803840C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803840C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803840C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803840CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803840D0: jal         0x803717A0
    // 0x803840D4: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803840D4: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    after_0:
    // 0x803840D8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803840DC: beq         $v0, $zero, L_8038410C
    if (ctx->r2 == 0) {
        // 0x803840E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8038410C;
    }
    // 0x803840E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803840E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803840E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803840EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803840F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803840F4: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x803840F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803840FC: jal         0x803841E0
    // 0x80384100: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_803841E0(rdram, ctx);
        goto after_1;
    // 0x80384100: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x80384104: b           L_80384110
    // 0x80384108: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80384110;
    // 0x80384108: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8038410C:
    // 0x8038410C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80384110:
    // 0x80384110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80384114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80384118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8038411C: jr          $ra
    // 0x80384120: nop

    return;
    // 0x80384120: nop

;}
RECOMP_FUNC void ftNessSpecialLw_InitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155454: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155458: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8015545C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80155460: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x80155464: sw          $zero, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = 0;
    // 0x80155468: jr          $ra
    // 0x8015546C: sw          $t7, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r15;
    return;
    // 0x8015546C: sw          $t7, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mnMapsModelPriProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EF0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132EF4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132EF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132F04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132F08: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132F0C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132F10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132F14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132F18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132F1C: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x80132F20: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80132F24: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132F28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132F2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132F30: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80132F34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132F38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132F3C: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80132F40: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x80132F44: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80132F48: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80132F4C: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x80132F50: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x80132F54: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80132F58: jal         0x80014038
    // 0x80132F5C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80132F5C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    after_0:
    // 0x80132F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132F68: jr          $ra
    // 0x80132F6C: nop

    return;
    // 0x80132F6C: nop

;}
RECOMP_FUNC void ftCommonGuardUpdateShieldAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014848C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148490: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80148494: lb          $t7, 0x1C2($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1C2);
    // 0x80148498: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8014849C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801484A0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801484A4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801484A8: nop

    // 0x801484AC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801484B0: mflo        $t9
    ctx->r25 = lo;
    // 0x801484B4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x801484B8: jal         0x8001863C
    // 0x801484BC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x801484BC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x801484C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801484C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801484C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801484CC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801484D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801484D4: bc1f        L_801484E4
    if (!c1cs) {
        // 0x801484D8: nop
    
            goto L_801484E4;
    }
    // 0x801484D8: nop

    // 0x801484DC: lwc1        $f8, -0x3E18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3E18);
    // 0x801484E0: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
L_801484E4:
    // 0x801484E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801484E8: lwc1        $f10, -0x3E14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E14);
    // 0x801484EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801484F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801484F4: div.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801484F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801484FC: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80148500: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80148504: nop

    // 0x80148508: bc1f        L_80148514
    if (!c1cs) {
        // 0x8014850C: nop
    
            goto L_80148514;
    }
    // 0x8014850C: nop

    // 0x80148510: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80148514:
    // 0x80148514: lwc1        $f2, -0x3E10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3E10);
    // 0x80148518: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8014851C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80148520: nop

    // 0x80148524: bc1fl       L_80148534
    if (!c1cs) {
        // 0x80148528: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80148534;
    }
    goto skip_0;
    // 0x80148528: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8014852C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80148530: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80148534:
    // 0x80148534: lb          $v1, 0x1C2($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C2);
    // 0x80148538: lb          $v0, 0x1C3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C3);
    // 0x8014853C: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80148540: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80148544: mflo        $t1
    ctx->r9 = lo;
    // 0x80148548: nop

    // 0x8014854C: nop

    // 0x80148550: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80148554: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80148558: mflo        $t2
    ctx->r10 = lo;
    // 0x8014855C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80148560: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80148564: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80148568: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014856C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80148570: sw          $a0, 0xB28($a1)
    MEM_W(0XB28, ctx->r5) = ctx->r4;
    // 0x80148574: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80148578: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8014857C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80148580: swc1        $f18, 0xB2C($a1)
    MEM_W(0XB2C, ctx->r5) = ctx->f18.u32l;
    // 0x80148584: jal         0x80033510
    // 0x80148588: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80148588: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8014858C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80148590: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80148594: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80148598: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014859C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801485A0: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801485A4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x801485A8: nop

    // 0x801485AC: bc1fl       L_801485BC
    if (!c1cs) {
        // 0x801485B0: swc1        $f12, 0xB30($a1)
        MEM_W(0XB30, ctx->r5) = ctx->f12.u32l;
            goto L_801485BC;
    }
    goto skip_1;
    // 0x801485B0: swc1        $f12, 0xB30($a1)
    MEM_W(0XB30, ctx->r5) = ctx->f12.u32l;
    skip_1:
    // 0x801485B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x801485B8: swc1        $f12, 0xB30($a1)
    MEM_W(0XB30, ctx->r5) = ctx->f12.u32l;
L_801485BC:
    // 0x801485BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801485C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801485C4: jr          $ra
    // 0x801485C8: nop

    return;
    // 0x801485C8: nop

;}
RECOMP_FUNC void efManagerImpactShockMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE068: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE06C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FE070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FE074: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FE078: jal         0x800FD4B8
    // 0x800FE07C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE07C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FE080: bne         $v0, $zero, L_800FE090
    if (ctx->r2 != 0) {
        // 0x800FE084: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FE090;
    }
    // 0x800FE084: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FE088: b           L_800FE24C
    // 0x800FE08C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE24C;
    // 0x800FE08C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE090:
    // 0x800FE090: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FE094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE098: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FE09C: jal         0x80009968
    // 0x800FE0A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FE0A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FE0A4: bne         $v0, $zero, L_800FE0BC
    if (ctx->r2 != 0) {
        // 0x800FE0A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FE0BC;
    }
    // 0x800FE0A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FE0AC: jal         0x800FD4F8
    // 0x800FE0B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FE0B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FE0B4: b           L_800FE24C
    // 0x800FE0B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE24C;
    // 0x800FE0B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE0BC:
    // 0x800FE0BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FE0C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE0C4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x800FE0C8: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FE0CC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FE0D0: jal         0x800CE9E8
    // 0x800FE0D4: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FE0D4: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FE0D8: beq         $v0, $zero, L_800FE23C
    if (ctx->r2 == 0) {
        // 0x800FE0DC: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FE23C;
    }
    // 0x800FE0DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FE0E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FE0E4: jal         0x800CE1DC
    // 0x800FE0E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FE0E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FE0EC: beq         $v0, $zero, L_800FE228
    if (ctx->r2 == 0) {
        // 0x800FE0F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FE228;
    }
    // 0x800FE0F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FE0F4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FE0F8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FE0FC: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FE100: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FE104: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FE108: jal         0x800CEA14
    // 0x800FE10C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FE10C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FE110: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FE114: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FE118: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FE11C: bne         $t9, $zero, L_800FE12C
    if (ctx->r25 != 0) {
        // 0x800FE120: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FE12C;
    }
    // 0x800FE120: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FE124: b           L_800FE24C
    // 0x800FE128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE24C;
    // 0x800FE128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE12C:
    // 0x800FE12C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FE130: jal         0x80008188
    // 0x800FE134: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FE134: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FE138: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FE13C: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FE140: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FE144: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FE148: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FE14C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FE150: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FE154: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FE158: jal         0x80018948
    // 0x800FE15C: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FE15C: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FE160: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800FE164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE168: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FE16C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FE170: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE174: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FE178: jal         0x80018948
    // 0x800FE17C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FE17C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800FE180: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE184: lwc1        $f16, 0x92C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X92C);
    // 0x800FE188: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800FE18C: jal         0x80035CD0
    // 0x800FE190: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FE190: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x800FE194: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE198: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FE19C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FE1A0: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x800FE1A4: jal         0x800303F0
    // 0x800FE1A8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FE1A8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x800FE1AC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE1B0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE1B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FE1B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE1BC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800FE1C0: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800FE1C4: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800FE1C8: addiu       $t8, $v0, -0xA
    ctx->r24 = ADD32(ctx->r2, -0XA);
    // 0x800FE1CC: beq         $at, $zero, L_800FE1F8
    if (ctx->r1 == 0) {
        // 0x800FE1D0: swc1        $f8, 0x1C($t5)
        MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
            goto L_800FE1F8;
    }
    // 0x800FE1D0: swc1        $f8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
    // 0x800FE1D4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800FE1D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE1DC: lwc1        $f18, 0x930($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X930);
    // 0x800FE1E0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE1E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE1E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FE1EC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800FE1F0: b           L_800FE218
    // 0x800FE1F4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_800FE218;
    // 0x800FE1F4: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800FE1F8:
    // 0x800FE1F8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800FE1FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE200: lwc1        $f16, 0x934($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X934);
    // 0x800FE204: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FE208: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE20C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE210: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800FE214: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_800FE218:
    // 0x800FE218: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800FE21C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800FE220: b           L_800FE248
    // 0x800FE224: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_800FE248;
    // 0x800FE224: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_800FE228:
    // 0x800FE228: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FE22C: jal         0x800FDB3C
    // 0x800FE230: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x800FE230: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x800FE234: b           L_800FE248
    // 0x800FE238: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FE248;
    // 0x800FE238: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FE23C:
    // 0x800FE23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FE240: jal         0x800FDB3C
    // 0x800FE244: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FE244: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_800FE248:
    // 0x800FE248: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FE24C:
    // 0x800FE24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FE254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FE258: jr          $ra
    // 0x800FE25C: nop

    return;
    // 0x800FE25C: nop

;}
RECOMP_FUNC void ftParamCheckSetSkeletonColAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9AFC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9B00: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E9B04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9B08: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800E9B0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E9B10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800E9B14: lw          $t8, -0x484C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X484C);
    // 0x800E9B18: jal         0x800E9814
    // 0x800E9B1C: addu        $a1, $t8, $a1
    ctx->r5 = ADD32(ctx->r24, ctx->r5);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800E9B1C: addu        $a1, $t8, $a1
    ctx->r5 = ADD32(ctx->r24, ctx->r5);
    after_0:
    // 0x800E9B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9B28: jr          $ra
    // 0x800E9B2C: nop

    return;
    // 0x800E9B2C: nop

;}
RECOMP_FUNC void itMainUpdateAttackEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173180: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80173184: lw          $v1, 0x340($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X340);
    // 0x80173188: lhu         $t7, 0x33E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X33E);
    // 0x8017318C: srl         $v1, $v1, 28
    ctx->r3 = S32(U32(ctx->r3) >> 28);
    // 0x80173190: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80173194: addu        $a2, $a1, $t6
    ctx->r6 = ADD32(ctx->r5, ctx->r14);
    // 0x80173198: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8017319C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x801731A0: bne         $t7, $t8, L_80173220
    if (ctx->r15 != ctx->r24) {
        // 0x801731A4: nop
    
            goto L_80173220;
    }
    // 0x801731A4: nop

    // 0x801731A8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x801731AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801731B0: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801731B4: sra         $t1, $t0, 22
    ctx->r9 = S32(SIGNED(ctx->r8) >> 22);
    // 0x801731B8: sw          $t1, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r9;
    // 0x801731BC: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x801731C0: sll         $t3, $t2, 18
    ctx->r11 = S32(ctx->r10 << 18);
    // 0x801731C4: srl         $t4, $t3, 24
    ctx->r12 = S32(U32(ctx->r11) >> 24);
    // 0x801731C8: sw          $t4, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r12;
    // 0x801731CC: lhu         $t5, 0x4($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X4);
    // 0x801731D0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801731D4: bgez        $t5, L_801731E8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801731D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801731E8;
    }
    // 0x801731D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801731DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801731E0: nop

    // 0x801731E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801731E8:
    // 0x801731E8: lbu         $t9, 0x340($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X340);
    // 0x801731EC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801731F0: andi        $t8, $t7, 0xF0
    ctx->r24 = ctx->r15 & 0XF0;
    // 0x801731F4: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x801731F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x801731FC: sb          $t1, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r9;
    // 0x80173200: lw          $t2, 0x340($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X340);
    // 0x80173204: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80173208: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x8017320C: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x80173210: bne         $t3, $at, L_80173220
    if (ctx->r11 != ctx->r1) {
        // 0x80173214: andi        $t5, $t1, 0xF
        ctx->r13 = ctx->r9 & 0XF;
            goto L_80173220;
    }
    // 0x80173214: andi        $t5, $t1, 0xF
    ctx->r13 = ctx->r9 & 0XF;
    // 0x80173218: ori         $t6, $t5, 0x30
    ctx->r14 = ctx->r13 | 0X30;
    // 0x8017321C: sb          $t6, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r14;
L_80173220:
    // 0x80173220: jr          $ra
    // 0x80173224: nop

    return;
    // 0x80173224: nop

;}
RECOMP_FUNC void func_ovl3_801397F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801397F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801397F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801397FC: jal         0x8013837C
    // 0x80139800: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_8013837C(rdram, ctx);
        goto after_0;
    // 0x80139800: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80139804: beq         $v0, $zero, L_80139A48
    if (ctx->r2 == 0) {
        // 0x80139808: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139A48;
    }
    // 0x80139808: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013980C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139810: beql        $v0, $at, L_80139A54
    if (ctx->r2 == ctx->r1) {
        // 0x80139814: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80139A54;
    }
    goto skip_0;
    // 0x80139814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80139818: jal         0x80018948
    // 0x8013981C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x8013981C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x80139820: jal         0x80018948
    // 0x80139824: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80139824: nop

    after_2:
    // 0x80139828: jal         0x80018948
    // 0x8013982C: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x8013982C: nop

    after_3:
    // 0x80139830: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139834: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80139838: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013983C: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139840: lwc1        $f2, 0x1C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80139844: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80139848: nop

    // 0x8013984C: bc1fl       L_80139868
    if (!c1cs) {
        // 0x80139850: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80139868;
    }
    goto skip_1;
    // 0x80139850: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x80139854: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80139858: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013985C: beq         $t7, $at, L_80139884
    if (ctx->r15 == ctx->r1) {
        // 0x80139860: nop
    
            goto L_80139884;
    }
    // 0x80139860: nop

    // 0x80139864: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80139868:
    // 0x80139868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013986C: bc1f        L_8013988C
    if (!c1cs) {
        // 0x80139870: nop
    
            goto L_8013988C;
    }
    // 0x80139870: nop

    // 0x80139874: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80139878: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013987C: bne         $t8, $at, L_8013988C
    if (ctx->r24 != ctx->r1) {
        // 0x80139880: nop
    
            goto L_8013988C;
    }
    // 0x80139880: nop

L_80139884:
    // 0x80139884: b           L_8013988C
    // 0x80139888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8013988C;
    // 0x80139888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8013988C:
    // 0x8013988C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80139890: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139894: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80139898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013989C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801398A0: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x801398A4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801398A8: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x801398AC: nop

    // 0x801398B0: bc1fl       L_801399CC
    if (!c1cs) {
        // 0x801398B4: sb          $zero, 0x34($v1)
        MEM_B(0X34, ctx->r3) = 0;
            goto L_801399CC;
    }
    goto skip_2;
    // 0x801398B4: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    skip_2:
    // 0x801398B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801398BC: jal         0x80138EE4
    // 0x801398C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_80138EE4(rdram, ctx);
        goto after_4;
    // 0x801398C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_4:
    // 0x801398C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801398C8: beq         $v0, $zero, L_801398D8
    if (ctx->r2 == 0) {
        // 0x801398CC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801398D8;
    }
    // 0x801398CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801398D0: b           L_80139A50
    // 0x801398D4: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_80139A50;
    // 0x801398D4: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_801398D8:
    // 0x801398D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801398DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801398E0: jal         0x80132EC8
    // 0x801398E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    ftComputerCheckDetectTarget(rdram, ctx);
        goto after_5;
    // 0x801398E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x801398E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801398EC: beq         $v0, $zero, L_801398FC
    if (ctx->r2 == 0) {
        // 0x801398F0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801398FC;
    }
    // 0x801398F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801398F4: b           L_80139A50
    // 0x801398F8: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_80139A50;
    // 0x801398F8: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_801398FC:
    // 0x801398FC: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x80139900: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80139904: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139908: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8013990C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80139910: nop

    // 0x80139914: bc1f        L_801399B4
    if (!c1cs) {
        // 0x80139918: nop
    
            goto L_801399B4;
    }
    // 0x80139918: nop

    // 0x8013991C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80139920: jal         0x80018948
    // 0x80139924: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x80139924: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_6:
    // 0x80139928: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013992C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80139930: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139934: lbu         $t0, 0x13($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X13);
    // 0x80139938: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013993C: addiu       $t1, $t0, 0x5
    ctx->r9 = ADD32(ctx->r8, 0X5);
    // 0x80139940: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80139944: nop

    // 0x80139948: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013994C: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80139950: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80139954: nop

    // 0x80139958: bc1f        L_801399B4
    if (!c1cs) {
        // 0x8013995C: nop
    
            goto L_801399B4;
    }
    // 0x8013995C: nop

    // 0x80139960: lw          $t2, 0x6C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X6C);
    // 0x80139964: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80139968: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8013996C: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x80139970: beq         $v0, $at, L_801399A0
    if (ctx->r2 == ctx->r1) {
        // 0x80139974: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_801399A0;
    }
    // 0x80139974: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80139978: beq         $v0, $at, L_801399A0
    if (ctx->r2 == ctx->r1) {
        // 0x8013997C: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_801399A0;
    }
    // 0x8013997C: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80139980: beq         $v0, $at, L_801399A0
    if (ctx->r2 == ctx->r1) {
        // 0x80139984: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_801399A0;
    }
    // 0x80139984: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80139988: beq         $v0, $at, L_801399A0
    if (ctx->r2 == ctx->r1) {
        // 0x8013998C: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_801399A0;
    }
    // 0x8013998C: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80139990: beq         $v0, $at, L_801399A0
    if (ctx->r2 == ctx->r1) {
        // 0x80139994: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_801399A0;
    }
    // 0x80139994: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80139998: bne         $v0, $at, L_801399B4
    if (ctx->r2 != ctx->r1) {
        // 0x8013999C: nop
    
            goto L_801399B4;
    }
    // 0x8013999C: nop

L_801399A0:
    // 0x801399A0: jal         0x80132758
    // 0x801399A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_7;
    // 0x801399A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_7:
    // 0x801399A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801399AC: b           L_80139A50
    // 0x801399B0: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139A50;
    // 0x801399B0: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_801399B4:
    // 0x801399B4: jal         0x80134E98
    // 0x801399B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_8;
    // 0x801399B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_8:
    // 0x801399BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801399C0: b           L_80139A50
    // 0x801399C4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139A50;
    // 0x801399C4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x801399C8: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
L_801399CC:
    // 0x801399CC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801399D0: jal         0x80138AA8
    // 0x801399D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_ovl3_80138AA8(rdram, ctx);
        goto after_9;
    // 0x801399D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_9:
    // 0x801399D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801399DC: beq         $v0, $zero, L_801399EC
    if (ctx->r2 == 0) {
        // 0x801399E0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801399EC;
    }
    // 0x801399E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801399E4: b           L_80139A50
    // 0x801399E8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139A50;
    // 0x801399E8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_801399EC:
    // 0x801399EC: lw          $t3, 0x5B4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X5B4);
    // 0x801399F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801399F4: beq         $t3, $at, L_80139A1C
    if (ctx->r11 == ctx->r1) {
        // 0x801399F8: nop
    
            goto L_80139A1C;
    }
    // 0x801399F8: nop

    // 0x801399FC: lw          $v0, 0x84C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84C);
    // 0x80139A00: beql        $v0, $zero, L_80139A34
    if (ctx->r2 == 0) {
        // 0x80139A04: sb          $zero, 0x35($v1)
        MEM_B(0X35, ctx->r3) = 0;
            goto L_80139A34;
    }
    goto skip_3;
    // 0x80139A04: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    skip_3:
    // 0x80139A08: lw          $t4, 0x84($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X84);
    // 0x80139A0C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80139A10: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80139A14: bnel        $t5, $at, L_80139A34
    if (ctx->r13 != ctx->r1) {
        // 0x80139A18: sb          $zero, 0x35($v1)
        MEM_B(0X35, ctx->r3) = 0;
            goto L_80139A34;
    }
    goto skip_4;
    // 0x80139A18: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    skip_4:
L_80139A1C:
    // 0x80139A1C: jal         0x80134E98
    // 0x80139A20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_10;
    // 0x80139A20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_10:
    // 0x80139A24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80139A28: b           L_80139A50
    // 0x80139A2C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139A50;
    // 0x80139A2C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139A30: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_80139A34:
    // 0x80139A34: jal         0x80134E98
    // 0x80139A38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_11;
    // 0x80139A38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_11:
    // 0x80139A3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80139A40: b           L_80139A50
    // 0x80139A44: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80139A50;
    // 0x80139A44: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_80139A48:
    // 0x80139A48: jal         0x8013877C
    // 0x80139A4C: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_12;
    // 0x80139A4C: nop

    after_12:
L_80139A50:
    // 0x80139A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80139A54:
    // 0x80139A54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80139A58: jr          $ra
    // 0x80139A5C: nop

    return;
    // 0x80139A5C: nop

;}
RECOMP_FUNC void func_ovl8_80375920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80375924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375928: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037592C: bne         $a0, $zero, L_80375944
    if (ctx->r4 != 0) {
        // 0x80375930: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80375944;
    }
    // 0x80375930: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80375934: jal         0x803717A0
    // 0x80375938: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80375938: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_0:
    // 0x8037593C: beq         $v0, $zero, L_803759DC
    if (ctx->r2 == 0) {
        // 0x80375940: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_803759DC;
    }
    // 0x80375940: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80375944:
    // 0x80375944: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80375948: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    // 0x8037594C: bnel        $t6, $zero, L_80375968
    if (ctx->r14 != 0) {
        // 0x80375950: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80375968;
    }
    goto skip_0;
    // 0x80375950: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80375954: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80375958: jal         0x803717E0
    // 0x8037595C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037595C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80375960: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80375964: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80375968:
    // 0x80375968: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8037596C: jal         0x80371FB0
    // 0x80375970: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_80371FB0(rdram, ctx);
        goto after_2;
    // 0x80375970: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80375974: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80375978: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037597C: addiu       $t7, $t7, -0x67D0
    ctx->r15 = ADD32(ctx->r15, -0X67D0);
    // 0x80375980: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x80375984: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80375988: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037598C: addiu       $t8, $t8, -0x6768
    ctx->r24 = ADD32(ctx->r24, -0X6768);
    // 0x80375990: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80375994: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80375998: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x8037599C: sh          $zero, 0x16($a2)
    MEM_H(0X16, ctx->r6) = 0;
    // 0x803759A0: lw          $t0, 0x6678($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6678);
    // 0x803759A4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803759A8: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x803759AC: bgez        $t0, L_803759BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x803759B0: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_803759BC;
    }
    // 0x803759B0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x803759B4: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x803759B8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_803759BC:
    // 0x803759BC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x803759C0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x803759C4: lw          $t2, 0x667C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X667C);
    // 0x803759C8: bgez        $t2, L_803759D8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x803759CC: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_803759D8;
    }
    // 0x803759CC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x803759D0: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x803759D4: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_803759D8:
    // 0x803759D8: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
L_803759DC:
    // 0x803759DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803759E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803759E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x803759E8: jr          $ra
    // 0x803759EC: nop

    return;
    // 0x803759EC: nop

;}
RECOMP_FUNC void itTosakintoBounceSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017EA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EA1C: jal         0x8017E93C
    // 0x8017EA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itTosakintoBounceInitVars(rdram, ctx);
        goto after_0;
    // 0x8017EA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017EA24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017EA28: addiu       $a1, $a1, -0x540C
    ctx->r5 = ADD32(ctx->r5, -0X540C);
    // 0x8017EA2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017EA30: jal         0x80172EC8
    // 0x8017EA34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017EA34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017EA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EA3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017EA40: jr          $ra
    // 0x8017EA44: nop

    return;
    // 0x8017EA44: nop

;}
RECOMP_FUNC void lbParticleEjectStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CEA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEA48: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    // 0x800CEA4C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CEA50: addiu       $t7, $t7, 0x6358
    ctx->r15 = ADD32(ctx->r15, 0X6358);
    // 0x800CEA54: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800CEA58: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800CEA5C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800CEA60: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800CEA64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CEA68: beql        $v0, $zero, L_800CEB44
    if (ctx->r2 == 0) {
        // 0x800CEA6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CEB44;
    }
    goto skip_0;
    // 0x800CEA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800CEA70:
    // 0x800CEA70: bnel        $v0, $a0, L_800CEB34
    if (ctx->r2 != ctx->r4) {
        // 0x800CEA74: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CEB34;
    }
    goto skip_1;
    // 0x800CEA74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_1:
    // 0x800CEA78: bnel        $v1, $zero, L_800CEA90
    if (ctx->r3 != 0) {
        // 0x800CEA7C: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_800CEA90;
    }
    goto skip_2;
    // 0x800CEA7C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x800CEA80: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CEA84: b           L_800CEA94
    // 0x800CEA88: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_800CEA94;
    // 0x800CEA88: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800CEA8C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_800CEA90:
    // 0x800CEA90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800CEA94:
    // 0x800CEA94: lw          $v1, 0x58($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X58);
    // 0x800CEA98: beql        $v1, $zero, L_800CEAD0
    if (ctx->r3 == 0) {
        // 0x800CEA9C: lw          $a1, 0x5C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X5C);
            goto L_800CEAD0;
    }
    goto skip_3;
    // 0x800CEA9C: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    skip_3:
    // 0x800CEAA0: lhu         $t0, 0x6($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X6);
    // 0x800CEAA4: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800CEAA8: beql        $t1, $zero, L_800CEAD0
    if (ctx->r9 == 0) {
        // 0x800CEAAC: lw          $a1, 0x5C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X5C);
            goto L_800CEAD0;
    }
    goto skip_4;
    // 0x800CEAAC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    skip_4:
    // 0x800CEAB0: lbu         $t2, 0x8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X8);
    // 0x800CEAB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CEAB8: bnel        $t2, $at, L_800CEAD0
    if (ctx->r10 != ctx->r1) {
        // 0x800CEABC: lw          $a1, 0x5C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X5C);
            goto L_800CEAD0;
    }
    goto skip_5;
    // 0x800CEABC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    skip_5:
    // 0x800CEAC0: lhu         $t3, 0x54($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X54);
    // 0x800CEAC4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800CEAC8: sh          $t4, 0x54($v1)
    MEM_H(0X54, ctx->r3) = ctx->r12;
    // 0x800CEACC: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
L_800CEAD0:
    // 0x800CEAD0: beq         $a1, $zero, L_800CEB04
    if (ctx->r5 == 0) {
        // 0x800CEAD4: nop
    
            goto L_800CEB04;
    }
    // 0x800CEAD4: nop

    // 0x800CEAD8: lhu         $t5, 0x2A($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X2A);
    // 0x800CEADC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800CEAE0: sh          $t6, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = ctx->r14;
    // 0x800CEAE4: lw          $a1, 0x5C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X5C);
    // 0x800CEAE8: lhu         $t7, 0x2A($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X2A);
    // 0x800CEAEC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CEAF0: bne         $t7, $zero, L_800CEB04
    if (ctx->r15 != 0) {
        // 0x800CEAF4: nop
    
            goto L_800CEB04;
    }
    // 0x800CEAF4: nop

    // 0x800CEAF8: jal         0x800CE188
    // 0x800CEAFC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    lbParticleEjectTransform(rdram, ctx);
        goto after_0;
    // 0x800CEAFC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CEB00: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_800CEB04:
    // 0x800CEB04: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CEB08: addiu       $v1, $v1, 0x6350
    ctx->r3 = ADD32(ctx->r3, 0X6350);
    // 0x800CEB0C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800CEB10: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CEB14: addiu       $a0, $a0, 0x6448
    ctx->r4 = ADD32(ctx->r4, 0X6448);
    // 0x800CEB18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800CEB1C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x800CEB20: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800CEB24: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800CEB28: b           L_800CEB40
    // 0x800CEB2C: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
        goto L_800CEB40;
    // 0x800CEB2C: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800CEB30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800CEB34:
    // 0x800CEB34: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800CEB38: bne         $v0, $zero, L_800CEA70
    if (ctx->r2 != 0) {
        // 0x800CEB3C: nop
    
            goto L_800CEA70;
    }
    // 0x800CEB3C: nop

L_800CEB40:
    // 0x800CEB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CEB44:
    // 0x800CEB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CEB48: jr          $ra
    // 0x800CEB4C: nop

    return;
    // 0x800CEB4C: nop

;}
RECOMP_FUNC void ftCommonEscapeCheckInterruptGuard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801493EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801493F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801493F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801493F8: jal         0x801492F8
    // 0x801493FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonEscapeGetStatus(rdram, ctx);
        goto after_0;
    // 0x801493FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80149400: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80149404: beq         $v0, $at, L_80149420
    if (ctx->r2 == ctx->r1) {
        // 0x80149408: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80149420;
    }
    // 0x80149408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014940C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80149410: jal         0x80149294
    // 0x80149414: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    ftCommonEscapeSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149414: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80149418: b           L_80149424
    // 0x8014941C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149424;
    // 0x8014941C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149420:
    // 0x80149420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80149424:
    // 0x80149424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014942C: jr          $ra
    // 0x80149430: nop

    return;
    // 0x80149430: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicapArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358F8: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x801358FC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80135900: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80135904: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80135908: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013590C: addiu       $t6, $v1, 0x44
    ctx->r14 = ADD32(ctx->r3, 0X44);
    // 0x80135910: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80135914: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013591C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135920: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135924: addiu       $t7, $v1, 0x5A
    ctx->r15 = ADD32(ctx->r3, 0X5A);
    // 0x80135928: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013592C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135930: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135934: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80135938: nop

    // 0x8013593C: bc1f        L_80135968
    if (!c1cs) {
        // 0x80135940: nop
    
            goto L_80135968;
    }
    // 0x80135940: nop

    // 0x80135944: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80135948: nop

    // 0x8013594C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80135950: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80135954: nop

    // 0x80135958: bc1f        L_80135968
    if (!c1cs) {
        // 0x8013595C: nop
    
            goto L_80135968;
    }
    // 0x8013595C: nop

    // 0x80135960: b           L_80135968
    // 0x80135964: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135968;
    // 0x80135964: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135968:
    // 0x80135968: beql        $v1, $zero, L_801359D0
    if (ctx->r3 == 0) {
        // 0x8013596C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801359D0;
    }
    goto skip_0;
    // 0x8013596C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80135970: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135974: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135978: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x8013597C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135980: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135984: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80135988: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013598C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80135990: nop

    // 0x80135994: bc1f        L_801359BC
    if (!c1cs) {
        // 0x80135998: nop
    
            goto L_801359BC;
    }
    // 0x80135998: nop

    // 0x8013599C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801359A0: nop

    // 0x801359A4: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801359A8: nop

    // 0x801359AC: bc1f        L_801359BC
    if (!c1cs) {
        // 0x801359B0: nop
    
            goto L_801359BC;
    }
    // 0x801359B0: nop

    // 0x801359B4: b           L_801359BC
    // 0x801359B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801359BC;
    // 0x801359B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801359BC:
    // 0x801359BC: beql        $v1, $zero, L_801359D0
    if (ctx->r3 == 0) {
        // 0x801359C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801359D0;
    }
    goto skip_1;
    // 0x801359C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801359C4: jr          $ra
    // 0x801359C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801359C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801359CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801359D0:
    // 0x801359D0: jr          $ra
    // 0x801359D4: nop

    return;
    // 0x801359D4: nop

;}
RECOMP_FUNC void efManagerNoStructProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD52C: jal         0x8000DF34
    // 0x800FD530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FD530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FD534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FD538: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FD53C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800FD540: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FD544: nop

    // 0x800FD548: bc1fl       L_800FD55C
    if (!c1cs) {
        // 0x800FD54C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD55C;
    }
    goto skip_0;
    // 0x800FD54C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FD550: jal         0x80009A84
    // 0x800FD554: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800FD554: nop

    after_1:
    // 0x800FD558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FD55C:
    // 0x800FD55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD560: jr          $ra
    // 0x800FD564: nop

    return;
    // 0x800FD564: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itStarRodThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178008: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017800C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80178010: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    // 0x80178014: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80178018: jal         0x80173B24
    // 0x8017801C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x8017801C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80178020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178028: jr          $ra
    // 0x8017802C: nop

    return;
    // 0x8017802C: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ED18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015ED1C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015ED20: addiu       $t6, $t6, -0x1680
    ctx->r14 = ADD32(ctx->r14, -0X1680);
    // 0x8015ED24: sw          $t6, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r14;
    // 0x8015ED28: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8015ED2C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015ED30: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x8015ED34: jr          $ra
    // 0x8015ED38: sh          $zero, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = 0;
    return;
    // 0x8015ED38: sh          $zero, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = 0;
;}
RECOMP_FUNC void mnPlayers1PBonusCheckBonusComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B7C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133B80: lw          $t6, 0x7714($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7714);
    // 0x80133B84: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x80133B88: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133B8C: bne         $t6, $zero, L_80133BA8
    if (ctx->r14 != 0) {
        // 0x80133B90: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80133BA8;
    }
    // 0x80133B90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80133B94: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x80133B98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133B9C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80133BA0: b           L_80133BB0
    // 0x80133BA4: lbu         $v0, 0x4950($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4950);
        goto L_80133BB0;
    // 0x80133BA4: lbu         $v0, 0x4950($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4950);
L_80133BA8:
    // 0x80133BA8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80133BAC: lbu         $v0, 0x4958($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4958);
L_80133BB0:
    // 0x80133BB0: bnel        $v0, $at, L_80133BC4
    if (ctx->r2 != ctx->r1) {
        // 0x80133BB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133BC4;
    }
    goto skip_0;
    // 0x80133BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80133BB8: jr          $ra
    // 0x80133BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80133BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133BC4:
    // 0x80133BC4: jr          $ra
    // 0x80133BC8: nop

    return;
    // 0x80133BC8: nop

;}
RECOMP_FUNC void lbRelocAddForceStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD798: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CD79C: addiu       $v1, $v1, 0x62E0
    ctx->r3 = ADD32(ctx->r3, 0X62E0);
    // 0x800CD7A0: lw          $a2, 0x24($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X24);
    // 0x800CD7A4: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x800CD7A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD7AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD7B0: sltu        $at, $a2, $t6
    ctx->r1 = ctx->r6 < ctx->r14 ? 1 : 0;
    // 0x800CD7B4: bne         $at, $zero, L_800CD7DC
    if (ctx->r1 != 0) {
        // 0x800CD7B8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800CD7DC;
    }
    // 0x800CD7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CD7BC: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CD7C0: addiu       $s0, $s0, 0x5F14
    ctx->r16 = ADD32(ctx->r16, 0X5F14);
L_800CD7C4:
    // 0x800CD7C4: jal         0x80023624
    // 0x800CD7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800CD7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CD7CC: jal         0x800A3040
    // 0x800CD7D0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800CD7D0: nop

    after_1:
    // 0x800CD7D4: b           L_800CD7C4
    // 0x800CD7D8: nop

        goto L_800CD7C4;
    // 0x800CD7D8: nop

L_800CD7DC:
    // 0x800CD7DC: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x800CD7E0: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800CD7E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800CD7E8: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800CD7EC: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x800CD7F0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800CD7F4: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x800CD7F8: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x800CD7FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CD804: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CD808: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
    // 0x800CD80C: jr          $ra
    // 0x800CD810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CD810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnTitleSetColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013282C: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80132830: beql        $at, $zero, L_80132880
    if (ctx->r1 == 0) {
        // 0x80132834: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80132880;
    }
    goto skip_0;
    // 0x80132834: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_0:
    // 0x80132838: beq         $a1, $zero, L_80132848
    if (ctx->r5 == 0) {
        // 0x8013283C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80132848;
    }
    // 0x8013283C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80132840: bne         $a1, $at, L_80132858
    if (ctx->r5 != ctx->r1) {
        // 0x80132844: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80132858;
    }
    // 0x80132844: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80132848:
    // 0x80132848: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x8013284C: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    // 0x80132850: jr          $ra
    // 0x80132854: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
    return;
    // 0x80132854: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
L_80132858:
    // 0x80132858: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x8013285C: addiu       $t7, $zero, 0x2A
    ctx->r15 = ADD32(0, 0X2A);
    // 0x80132860: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80132864: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x80132868: sb          $t7, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r15;
    // 0x8013286C: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80132870: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132874: jr          $ra
    // 0x80132878: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    return;
    // 0x80132878: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x8013287C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80132880:
    // 0x80132880: beq         $a1, $at, L_801328B4
    if (ctx->r5 == ctx->r1) {
        // 0x80132884: addiu       $t8, $zero, 0xB7
        ctx->r24 = ADD32(0, 0XB7);
            goto L_801328B4;
    }
    // 0x80132884: addiu       $t8, $zero, 0xB7
    ctx->r24 = ADD32(0, 0XB7);
    // 0x80132888: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013288C: beq         $a1, $at, L_801328E4
    if (ctx->r5 == ctx->r1) {
        // 0x80132890: addiu       $t4, $zero, 0x14
        ctx->r12 = ADD32(0, 0X14);
            goto L_801328E4;
    }
    // 0x80132890: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80132894: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132898: beq         $a1, $at, L_801328FC
    if (ctx->r5 == ctx->r1) {
        // 0x8013289C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_801328FC;
    }
    // 0x8013289C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801328A0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801328A4: beq         $a1, $at, L_80132924
    if (ctx->r5 == ctx->r1) {
        // 0x801328A8: addiu       $t0, $zero, 0x15
        ctx->r8 = ADD32(0, 0X15);
            goto L_80132924;
    }
    // 0x801328A8: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x801328AC: jr          $ra
    // 0x801328B0: nop

    return;
    // 0x801328B0: nop

L_801328B4:
    // 0x801328B4: addiu       $t9, $zero, 0xAE
    ctx->r25 = ADD32(0, 0XAE);
    // 0x801328B8: addiu       $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
    // 0x801328BC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801328C0: addiu       $t2, $zero, 0x12
    ctx->r10 = ADD32(0, 0X12);
    // 0x801328C4: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801328C8: sb          $t8, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r24;
    // 0x801328CC: sb          $t9, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r25;
    // 0x801328D0: sb          $t0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r8;
    // 0x801328D4: sb          $t1, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r9;
    // 0x801328D8: sb          $t2, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r10;
    // 0x801328DC: jr          $ra
    // 0x801328E0: sb          $t3, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r11;
    return;
    // 0x801328E0: sb          $t3, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r11;
L_801328E4:
    // 0x801328E4: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x801328E8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x801328EC: sb          $t4, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r12;
    // 0x801328F0: sb          $t5, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r13;
    // 0x801328F4: jr          $ra
    // 0x801328F8: sb          $t6, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r14;
    return;
    // 0x801328F8: sb          $t6, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r14;
L_801328FC:
    // 0x801328FC: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80132900: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80132904: addiu       $t9, $zero, 0xA4
    ctx->r25 = ADD32(0, 0XA4);
    // 0x80132908: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8013290C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80132910: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80132914: sb          $t7, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r15;
    // 0x80132918: sb          $t8, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r24;
    // 0x8013291C: jr          $ra
    // 0x80132920: sb          $t9, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r25;
    return;
    // 0x80132920: sb          $t9, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r25;
L_80132924:
    // 0x80132924: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x80132928: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8013292C: sb          $t0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r8;
    // 0x80132930: sb          $t1, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r9;
    // 0x80132934: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
    // 0x80132938: jr          $ra
    // 0x8013293C: nop

    return;
    // 0x8013293C: nop

;}
RECOMP_FUNC void ftMarioSpecialAirLwSetDisableRise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801567A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801567A8: jr          $ra
    // 0x801567AC: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    return;
    // 0x801567AC: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
;}
RECOMP_FUNC void mpProcessSetLastWallCollideRight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9590: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D9594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9598: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D959C: jr          $ra
    // 0x800D95A0: swc1        $f4, 0xDFC($at)
    MEM_W(0XDFC, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x800D95A0: swc1        $f4, 0xDFC($at)
    MEM_W(0XDFC, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftKirbySpecialNLoopCheckContinueLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162424: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80162428: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016242C: lh          $a1, 0xB1A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XB1A);
    // 0x80162430: beq         $a1, $zero, L_80162440
    if (ctx->r5 == 0) {
        // 0x80162434: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80162440;
    }
    // 0x80162434: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80162438: jr          $ra
    // 0x8016243C: sh          $t6, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r14;
    return;
    // 0x8016243C: sh          $t6, 0xB1A($v1)
    MEM_H(0XB1A, ctx->r3) = ctx->r14;
L_80162440:
    // 0x80162440: lhu         $t7, 0x1BC($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1BC);
    // 0x80162444: lhu         $t8, 0x1B6($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1B6);
    // 0x80162448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016244C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80162450: beq         $t9, $zero, L_80162460
    if (ctx->r25 == 0) {
        // 0x80162454: nop
    
            goto L_80162460;
    }
    // 0x80162454: nop

    // 0x80162458: jr          $ra
    // 0x8016245C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8016245C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80162460:
    // 0x80162460: jr          $ra
    // 0x80162464: nop

    return;
    // 0x80162464: nop

;}
RECOMP_FUNC void gcSetMaxNumGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A328: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A32C: jr          $ra
    // 0x8000A330: sh          $a0, 0x6A12($at)
    MEM_H(0X6A12, ctx->r1) = ctx->r4;
    return;
    // 0x8000A330: sh          $a0, 0x6A12($at)
    MEM_H(0X6A12, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void syTaskmanSwitchContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005AE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005AE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005AEC: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80005AF0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005AF4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005AF8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80005AFC: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
    // 0x80005B00: addiu       $s3, $s3, 0x5500
    ctx->r19 = ADD32(ctx->r19, 0X5500);
    // 0x80005B04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80005B08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005B0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005B10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005B14: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80005B18: jal         0x80030210
    // 0x80005B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80005B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80005B20: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80005B24: beq         $v0, $s0, L_80005B58
    if (ctx->r2 == ctx->r16) {
        // 0x80005B28: lui         $s1, 0x8004
        ctx->r17 = S32(0X8004 << 16);
            goto L_80005B58;
    }
    // 0x80005B28: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80005B2C: addiu       $s1, $s1, 0x6638
    ctx->r17 = ADD32(ctx->r17, 0X6638);
    // 0x80005B30: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
L_80005B34:
    // 0x80005B34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005B38: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80005B3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80005B40: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80005B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005B48: jal         0x80030210
    // 0x80005B4C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80005B4C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_1:
    // 0x80005B50: bnel        $v0, $s0, L_80005B34
    if (ctx->r2 != ctx->r16) {
        // 0x80005B54: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80005B34;
    }
    goto skip_0;
    // 0x80005B54: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_80005B58:
    // 0x80005B58: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80005B5C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005B60: addiu       $s1, $s1, 0x6638
    ctx->r17 = ADD32(ctx->r17, 0X6638);
    // 0x80005B64: addiu       $s0, $s0, 0x6640
    ctx->r16 = ADD32(ctx->r16, 0X6640);
    // 0x80005B68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80005B6C:
    // 0x80005B6C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005B70: addiu       $a0, $a0, 0x6638
    ctx->r4 = ADD32(ctx->r4, 0X6638);
    // 0x80005B74: blez        $v0, L_80005BAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80005B78: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80005BAC;
    }
    // 0x80005B78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80005B7C:
    // 0x80005B7C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80005B80: bne         $t9, $zero, L_80005B9C
    if (ctx->r25 != 0) {
        // 0x80005B84: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80005B9C;
    }
    // 0x80005B84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005B88: sw          $v1, 0x6630($at)
    MEM_W(0X6630, ctx->r1) = ctx->r3;
    // 0x80005B8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80005B90: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80005B94: b           L_80005BDC
    // 0x80005B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005BDC;
    // 0x80005B98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005B9C:
    // 0x80005B9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80005BA0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005BA4: bne         $at, $zero, L_80005B7C
    if (ctx->r1 != 0) {
        // 0x80005BA8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80005B7C;
    }
    // 0x80005BA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80005BAC:
    // 0x80005BAC: bne         $s2, $zero, L_80005BD0
    if (ctx->r18 != 0) {
        // 0x80005BB0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80005BD0;
    }
    // 0x80005BB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005BB4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80005BB8: jal         0x80030210
    // 0x80005BBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005BBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80005BC0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80005BC4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80005BC8: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80005BCC: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80005BD0:
    // 0x80005BD0: beql        $s2, $zero, L_80005B6C
    if (ctx->r18 == 0) {
        // 0x80005BD4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80005B6C;
    }
    goto skip_1;
    // 0x80005BD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80005BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005BDC:
    // 0x80005BDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80005BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005BE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005BE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005BEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80005BF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80005BF4: jr          $ra
    // 0x80005BF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80005BF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itMapSetAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80173F7C: jr          $ra
    // 0x80173F80: sw          $t6, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r14;
    return;
    // 0x80173F80: sw          $t6, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void gcGetInterpValueCubic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CA28: mul.s       $f2, $f14, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000CA2C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000CA30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000CA34: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8000CA38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000CA3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CA40: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000CA44: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8000CA48: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8000CA4C: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000CA50: add.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x8000CA54: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000CA58: nop

    // 0x8000CA5C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8000CA60: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x8000CA64: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8000CA68: nop

    // 0x8000CA6C: mul.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000CA70: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8000CA74: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8000CA78: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000CA7C: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8000CA80: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x8000CA84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000CA88: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8000CA8C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000CA90: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8000CA94: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8000CA98: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000CA9C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000CAA0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8000CAA4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CAA8: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8000CAAC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000CAB0: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8000CAB4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000CAB8: add.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8000CABC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8000CAC0: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8000CAC4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8000CAC8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000CACC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000CAD0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CAD4: jr          $ra
    // 0x8000CAD8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    return;
    // 0x8000CAD8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
;}
RECOMP_FUNC void func_ovl8_8037481C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037481C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374824: jal         0x80373158
    // 0x80374828: nop

    func_ovl8_80373158(rdram, ctx);
        goto after_0;
    // 0x80374828: nop

    after_0:
    // 0x8037482C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374834: jr          $ra
    // 0x80374838: nop

    return;
    // 0x80374838: nop

;}
RECOMP_FUNC void func_ovl29_80136980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136980: jr          $ra
    // 0x80136984: nop

    return;
    // 0x80136984: nop

;}
RECOMP_FUNC void mnTitleLoadFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134140: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134144: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80134148: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013414C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134154: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80134158: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8013415C: addiu       $t8, $t8, 0x44A0
    ctx->r24 = ADD32(ctx->r24, 0X44A0);
    // 0x80134160: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80134164: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80134168: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8013416C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80134170: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134174: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80134178: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8013417C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80134180: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80134184: jal         0x800CDF78
    // 0x80134188: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80134188: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8013418C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134190: addiu       $a0, $a0, 0x4420
    ctx->r4 = ADD32(ctx->r4, 0X4420);
    // 0x80134194: jal         0x800CDEEC
    // 0x80134198: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80134198: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8013419C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801341A0: jal         0x80004980
    // 0x801341A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801341A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801341A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341AC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801341B0: addiu       $a2, $a2, 0x45A0
    ctx->r6 = ADD32(ctx->r6, 0X45A0);
    // 0x801341B4: addiu       $a0, $a0, 0x4420
    ctx->r4 = ADD32(ctx->r4, 0X4420);
    // 0x801341B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801341BC: jal         0x800CDE04
    // 0x801341C0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801341C0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801341C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801341C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801341CC: jr          $ra
    // 0x801341D0: nop

    return;
    // 0x801341D0: nop

;}
RECOMP_FUNC void syMallocSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006CF4: beq         $a2, $zero, L_80006D14
    if (ctx->r6 == 0) {
        // 0x80006CF8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80006D14;
    }
    // 0x80006CF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80006CFC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80006D00: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80006D04: nor         $t8, $v0, $zero
    ctx->r24 = ~(ctx->r2 | 0);
    // 0x80006D08: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80006D0C: b           L_80006D18
    // 0x80006D10: and         $v1, $t7, $t8
    ctx->r3 = ctx->r15 & ctx->r24;
        goto L_80006D18;
    // 0x80006D10: and         $v1, $t7, $t8
    ctx->r3 = ctx->r15 & ctx->r24;
L_80006D14:
    // 0x80006D14: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
L_80006D18:
    // 0x80006D18: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80006D1C: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x80006D20: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80006D24: sltu        $at, $t9, $v0
    ctx->r1 = ctx->r25 < ctx->r2 ? 1 : 0;
    // 0x80006D28: beq         $at, $zero, L_80006D48
    if (ctx->r1 == 0) {
        // 0x80006D2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006D48;
    }
    // 0x80006D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006D30: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006D34: addiu       $a0, $a0, -0x26F0
    ctx->r4 = ADD32(ctx->r4, -0X26F0);
    // 0x80006D38: jal         0x80023624
    // 0x80006D3C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80006D3C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    after_0:
L_80006D40:
    // 0x80006D40: b           L_80006D40
    pause_self(rdram);
    // 0x80006D44: nop

L_80006D48:
    // 0x80006D48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80006D4C: jr          $ra
    // 0x80006D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void grCastleInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B378: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010B37C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010B380: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8010B384: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010B388: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8010B38C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8010B390: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8010B394: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8010B398: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x8010B39C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B3A0: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x8010B3A4: sw          $v0, 0x13F0($at)
    MEM_W(0X13F0, ctx->r1) = ctx->r2;
    // 0x8010B3A8: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010B3AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010B3B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B3B4: jal         0x80009968
    // 0x8010B3B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010B3B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010B3BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010B3C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010B3C4: addiu       $a1, $a1, -0x4CC0
    ctx->r5 = ADD32(ctx->r5, -0X4CC0);
    // 0x8010B3C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010B3CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B3D0: jal         0x80008188
    // 0x8010B3D4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8010B3D4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010B3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B3DC: jal         0x800092D0
    // 0x8010B3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8010B3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8010B3E4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010B3E8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8010B3EC: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x8010B3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B3F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B3F8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8010B3FC: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x8010B400: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8010B404: jal         0x80008188
    // 0x8010B408: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8010B408: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    after_3:
    // 0x8010B40C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010B410: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x8010B414: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010B418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B41C: jal         0x8000BD8C
    // 0x8010B420: lw          $a1, 0x80($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X80);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x8010B420: lw          $a1, 0x80($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X80);
    after_4:
    // 0x8010B424: jal         0x8000DF34
    // 0x8010B428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x8010B428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8010B42C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8010B430: jal         0x800FC814
    // 0x8010B434: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_6;
    // 0x8010B434: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8010B438: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8010B43C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010B440: jal         0x800FC894
    // 0x8010B444: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_7;
    // 0x8010B444: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x8010B448: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8010B44C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010B450: addiu       $t0, $t0, 0x13FC
    ctx->r8 = ADD32(ctx->r8, 0X13FC);
    // 0x8010B454: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8010B458: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8010B45C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8010B460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010B464: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x8010B468: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8010B46C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8010B470: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8010B474: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8010B478: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x8010B47C: swc1        $f20, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f20.u32l;
    // 0x8010B480: swc1        $f20, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f20.u32l;
    // 0x8010B484: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8010B488: jal         0x8016EA78
    // 0x8010B48C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_8;
    // 0x8010B48C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x8010B490: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B494: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B498: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8010B49C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8010B4A0: sw          $v0, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = ctx->r2;
    // 0x8010B4A4: jr          $ra
    // 0x8010B4A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010B4A8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftManagerSetupFilesMainKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D7698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D769C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800D76A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D76A4: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800D76A8: lw          $s0, 0x6E10($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6E10);
    // 0x800D76AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D76B0: jal         0x800CDBD0
    // 0x800D76B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x800D76B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800D76B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D76BC: jal         0x80004980
    // 0x800D76C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x800D76C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800D76C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800D76C8: jal         0x800CDC88
    // 0x800D76CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x800D76CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800D76D0: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x800D76D4: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800D76D8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800D76DC: beql        $a0, $zero, L_800D7700
    if (ctx->r4 == 0) {
        // 0x800D76E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D7700;
    }
    goto skip_0;
    // 0x800D76E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D76E4: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x800D76E8: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x800D76EC: jal         0x801159F8
    // 0x800D76F0: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_3;
    // 0x800D76F0: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    after_3:
    // 0x800D76F4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x800D76F8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800D76FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D7700:
    // 0x800D7700: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D7704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D7708: jr          $ra
    // 0x800D770C: nop

    return;
    // 0x800D770C: nop

;}
RECOMP_FUNC void func_ovl8_803866AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803866AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803866B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x803866B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803866B8: beq         $a1, $at, L_803866FC
    if (ctx->r5 == ctx->r1) {
        // 0x803866BC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_803866FC;
    }
    // 0x803866BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x803866C0: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x803866C4: beq         $a1, $at, L_8038670C
    if (ctx->r5 == ctx->r1) {
        // 0x803866C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8038670C;
    }
    // 0x803866C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803866CC: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    // 0x803866D0: beq         $a1, $at, L_8038671C
    if (ctx->r5 == ctx->r1) {
        // 0x803866D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8038671C;
    }
    // 0x803866D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803866D8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x803866DC: beq         $a1, $at, L_8038672C
    if (ctx->r5 == ctx->r1) {
        // 0x803866E0: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_8038672C;
    }
    // 0x803866E0: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x803866E4: beq         $a1, $at, L_80386774
    if (ctx->r5 == ctx->r1) {
        // 0x803866E8: addiu       $at, $zero, 0x83
        ctx->r1 = ADD32(0, 0X83);
            goto L_80386774;
    }
    // 0x803866E8: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x803866EC: beql        $a1, $at, L_803867C0
    if (ctx->r5 == ctx->r1) {
        // 0x803866F0: lw          $v1, 0xAC($a3)
        ctx->r3 = MEM_W(ctx->r7, 0XAC);
            goto L_803867C0;
    }
    goto skip_0;
    // 0x803866F0: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
    skip_0:
    // 0x803866F4: b           L_803867D8
    // 0x803866F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803867D8;
    // 0x803866F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803866FC:
    // 0x803866FC: jal         0x8037486C
    // 0x80386700: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_8037486C(rdram, ctx);
        goto after_0;
    // 0x80386700: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80386704: b           L_803867D8
    // 0x80386708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803867D8;
    // 0x80386708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8038670C:
    // 0x8038670C: sw          $v0, 0xA8($a3)
    MEM_W(0XA8, ctx->r7) = ctx->r2;
    // 0x80386710: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386714: b           L_803867D4
    // 0x80386718: sw          $v0, 0x3D0($at)
    MEM_W(0X3D0, ctx->r1) = ctx->r2;
        goto L_803867D4;
    // 0x80386718: sw          $v0, 0x3D0($at)
    MEM_W(0X3D0, ctx->r1) = ctx->r2;
L_8038671C:
    // 0x8038671C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80386720: sw          $v0, 0x3D0($at)
    MEM_W(0X3D0, ctx->r1) = ctx->r2;
    // 0x80386724: b           L_803867D4
    // 0x80386728: sw          $zero, 0xA8($a3)
    MEM_W(0XA8, ctx->r7) = 0;
        goto L_803867D4;
    // 0x80386728: sw          $zero, 0xA8($a3)
    MEM_W(0XA8, ctx->r7) = 0;
L_8038672C:
    // 0x8038672C: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
    // 0x80386730: lbu         $a1, 0xC($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0XC);
    // 0x80386734: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x80386738: lh          $t6, 0xD8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD8);
    // 0x8038673C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80386740: lw          $t9, 0xDC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XDC);
    // 0x80386744: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x80386748: jalr        $t9
    // 0x8038674C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8038674C: nop

    after_1:
    // 0x80386750: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80386754: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
    // 0x80386758: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8038675C: lw          $t9, 0xE4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE4);
    // 0x80386760: lh          $t7, 0xE0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE0);
    // 0x80386764: jalr        $t9
    // 0x80386768: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80386768: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_2:
    // 0x8038676C: b           L_803867D8
    // 0x80386770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803867D8;
    // 0x80386770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80386774:
    // 0x80386774: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
    // 0x80386778: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8038677C: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x80386780: lh          $t8, 0xD0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XD0);
    // 0x80386784: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80386788: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x8038678C: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x80386790: jalr        $t9
    // 0x80386794: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80386794: nop

    after_3:
    // 0x80386798: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8038679C: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
    // 0x803867A0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x803867A4: lw          $t9, 0xE4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE4);
    // 0x803867A8: lh          $t0, 0xE0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE0);
    // 0x803867AC: jalr        $t9
    // 0x803867B0: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x803867B0: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    after_4:
    // 0x803867B4: b           L_803867D8
    // 0x803867B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803867D8;
    // 0x803867B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803867BC: lw          $v1, 0xAC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XAC);
L_803867C0:
    // 0x803867C0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x803867C4: lw          $t9, 0x104($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X104);
    // 0x803867C8: lh          $t1, 0x100($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X100);
    // 0x803867CC: jalr        $t9
    // 0x803867D0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x803867D0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    after_5:
L_803867D4:
    // 0x803867D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803867D8:
    // 0x803867D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803867DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x803867E0: jr          $ra
    // 0x803867E4: nop

    return;
    // 0x803867E4: nop

;}
RECOMP_FUNC void ftCommonFireFlowerShootSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801477C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801477CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801477D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801477D4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801477D8: jal         0x800DEEC8
    // 0x801477DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801477DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801477E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801477E4: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    // 0x801477E8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801477EC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801477F0: lw          $a3, 0x78($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X78);
    // 0x801477F4: jal         0x800E6F24
    // 0x801477F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801477F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801477FC: jal         0x800D8EB8
    // 0x80147800: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80147800: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80147804: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80147808: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8014780C: addiu       $t8, $t8, 0x7434
    ctx->r24 = ADD32(ctx->r24, 0X7434);
    // 0x80147810: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80147814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014781C: jr          $ra
    // 0x80147820: nop

    return;
    // 0x80147820: nop

;}
RECOMP_FUNC void ftCommonCatchCheckInterruptDashRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149D80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149D88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80149D8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80149D90: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x80149D94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80149D98: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80149D9C: jal         0x80146A8C
    // 0x80149DA0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x80149DA0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80149DA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80149DA8: beq         $v0, $zero, L_80149DC4
    if (ctx->r2 == 0) {
        // 0x80149DAC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80149DC4;
    }
    // 0x80149DAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80149DB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80149DB4: jal         0x80146690
    // 0x80149DB8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149DB8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_1:
    // 0x80149DBC: b           L_80149E14
    // 0x80149DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149E14;
    // 0x80149DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149DC4:
    // 0x80149DC4: lhu         $t7, 0x1BC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80149DC8: lhu         $t8, 0x1B8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80149DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80149DD0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80149DD4: beq         $t9, $zero, L_80149E14
    if (ctx->r25 == 0) {
        // 0x80149DD8: nop
    
            goto L_80149E14;
    }
    // 0x80149DD8: nop

    // 0x80149DDC: lhu         $t0, 0x1BE($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X1BE);
    // 0x80149DE0: lhu         $t1, 0x1B4($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X1B4);
    // 0x80149DE4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80149DE8: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80149DEC: beq         $t2, $zero, L_80149E14
    if (ctx->r10 == 0) {
        // 0x80149DF0: nop
    
            goto L_80149E14;
    }
    // 0x80149DF0: nop

    // 0x80149DF4: lw          $t4, 0x100($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X100);
    // 0x80149DF8: sll         $t6, $t4, 20
    ctx->r14 = S32(ctx->r12 << 20);
    // 0x80149DFC: bgez        $t6, L_80149E14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80149E00: nop
    
            goto L_80149E14;
    }
    // 0x80149E00: nop

    // 0x80149E04: jal         0x80149BA8
    // 0x80149E08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x80149E08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80149E0C: b           L_80149E14
    // 0x80149E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149E14;
    // 0x80149E10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149E14:
    // 0x80149E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149E1C: jr          $ra
    // 0x80149E20: nop

    return;
    // 0x80149E20: nop

;}
RECOMP_FUNC void itLizardonAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F810: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017F814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F818: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8017F81C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017F820: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017F824: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x8017F828: sh          $t7, 0x35C($v0)
    MEM_H(0X35C, ctx->r2) = ctx->r15;
    // 0x8017F82C: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x8017F830: addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // 0x8017F834: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8017F838: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8017F83C: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8017F840: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8017F844: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8017F848: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8017F84C: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x8017F850: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8017F854: addiu       $t6, $t6, -0x2A40
    ctx->r14 = ADD32(ctx->r14, -0X2A40);
    // 0x8017F858: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8017F85C: sw          $t1, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r9;
    // 0x8017F860: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8017F864: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8017F868: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017F86C: sw          $t0, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r8;
    // 0x8017F870: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8017F874: sh          $zero, 0x35E($v0)
    MEM_H(0X35E, ctx->r2) = 0;
    // 0x8017F878: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x8017F87C: bne         $t3, $at, L_8017F8D4
    if (ctx->r11 != ctx->r1) {
        // 0x8017F880: sw          $t1, 0x358($v0)
        MEM_W(0X358, ctx->r2) = ctx->r9;
            goto L_8017F8D4;
    }
    // 0x8017F880: sw          $t1, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r9;
    // 0x8017F884: lw          $t4, 0x2D4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017F888: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8017F88C: addiu       $t7, $t7, -0x29A8
    ctx->r15 = ADD32(ctx->r15, -0X29A8);
    // 0x8017F890: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8017F894: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8017F898: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017F89C: subu        $v1, $t5, $t6
    ctx->r3 = SUB32(ctx->r13, ctx->r14);
    // 0x8017F8A0: addu        $a1, $v1, $t7
    ctx->r5 = ADD32(ctx->r3, ctx->r15);
    // 0x8017F8A4: jal         0x8000BD1C
    // 0x8017F8A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017F8A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017F8AC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8017F8B0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017F8B4: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8017F8B8: addiu       $t8, $t8, -0x2978
    ctx->r24 = ADD32(ctx->r24, -0X2978);
    // 0x8017F8BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017F8C0: addu        $a1, $v1, $t8
    ctx->r5 = ADD32(ctx->r3, ctx->r24);
    // 0x8017F8C4: jal         0x8000BD54
    // 0x8017F8C8: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017F8C8: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
    after_1:
    // 0x8017F8CC: jal         0x8000DF34
    // 0x8017F8D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8017F8D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
L_8017F8D4:
    // 0x8017F8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F8D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017F8DC: jr          $ra
    // 0x8017F8E0: nop

    return;
    // 0x8017F8E0: nop

;}
RECOMP_FUNC void ftCaptainSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FB5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015FB60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015FB64: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015FB68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015FB6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015FB70: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015FB74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015FB78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015FB7C: jal         0x800E6F24
    // 0x8015FB80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015FB80: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015FB84: jal         0x800E0830
    // 0x8015FB88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015FB88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015FB8C: jal         0x8015FB40
    // 0x8015FB90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCaptainSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015FB90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015FB94: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015FB98: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8015FB9C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8015FBA0: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x8015FBA4: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x8015FBA8: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x8015FBAC: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x8015FBB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FBB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015FBB8: jr          $ra
    // 0x8015FBBC: nop

    return;
    // 0x8015FBBC: nop

;}
RECOMP_FUNC void func_ovl8_80372E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372E98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372EA0: beq         $a0, $zero, L_80372EAC
    if (ctx->r4 == 0) {
        // 0x80372EA4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80372EAC;
    }
    // 0x80372EA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80372EA8: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80372EAC:
    // 0x80372EAC: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x80372EB0: addiu       $at, $zero, -0x1FD
    ctx->r1 = ADD32(0, -0X1FD);
    // 0x80372EB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80372EB8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80372EBC: bne         $t7, $at, L_80372ECC
    if (ctx->r15 != ctx->r1) {
        // 0x80372EC0: nop
    
            goto L_80372ECC;
    }
    // 0x80372EC0: nop

    // 0x80372EC4: b           L_80372ECC
    // 0x80372EC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80372ECC;
    // 0x80372EC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80372ECC:
    // 0x80372ECC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80372ED0: beq         $a0, $zero, L_80372EDC
    if (ctx->r4 == 0) {
        // 0x80372ED4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80372EDC;
    }
    // 0x80372ED4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80372ED8: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
L_80372EDC:
    // 0x80372EDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80372EE0: jal         0x8037C584
    // 0x80372EE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_ovl8_8037C584(rdram, ctx);
        goto after_0;
    // 0x80372EE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80372EE8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80372EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372EF0: lw          $t8, 0x48($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X48);
    // 0x80372EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80372EF8: xor         $v0, $v0, $t8
    ctx->r2 = ctx->r2 ^ ctx->r24;
    // 0x80372EFC: jr          $ra
    // 0x80372F00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80372F00: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void ftManagerSetPrevPartsAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D767C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D7680: addiu       $v0, $v0, 0xD88
    ctx->r2 = ADD32(ctx->r2, 0XD88);
    // 0x800D7684: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D7688: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800D768C: jr          $ra
    // 0x800D7690: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x800D7690: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void ftNessSpecialLwStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015540C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155410: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155414: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155418: jal         0x800DEEC8
    // 0x8015541C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015541C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155420: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155424: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80155428: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8015542C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155430: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155434: jal         0x800E6F24
    // 0x80155438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015543C: jal         0x800D8EB8
    // 0x80155440: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80155440: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80155444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155448: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015544C: jr          $ra
    // 0x80155450: nop

    return;
    // 0x80155450: nop

;}
RECOMP_FUNC void mnTitleMakeLogoFireParticles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E68: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80133E6C: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80133E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133E74: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80133E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133E7C: bne         $t6, $at, L_80133F28
    if (ctx->r14 != ctx->r1) {
        // 0x80133E80: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80133F28;
    }
    // 0x80133E80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133E84: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80133E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E8C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80133E90: jal         0x80009968
    // 0x80133E94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133E94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133E98: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133E9C: lw          $t7, 0x45A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X45A0);
    // 0x80133EA0: lui         $t8, 0x3
    ctx->r24 = S32(0X3 << 16);
    // 0x80133EA4: addiu       $t8, $t8, -0x7150
    ctx->r24 = ADD32(ctx->r24, -0X7150);
    // 0x80133EA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133EB4: jal         0x8000F120
    // 0x80133EB8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80133EB8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133EBC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133EC0: lw          $t9, 0x45A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X45A0);
    // 0x80133EC4: lui         $t0, 0x3
    ctx->r8 = S32(0X3 << 16);
    // 0x80133EC8: addiu       $t0, $t0, -0x6FF0
    ctx->r8 = ADD32(ctx->r8, -0X6FF0);
    // 0x80133ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133ED0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133ED4: jal         0x8000BD8C
    // 0x80133ED8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_2;
    // 0x80133ED8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x80133EDC: jal         0x8000DF34
    // 0x80133EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x80133EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80133EE4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133EE8: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80133EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133EF4: jal         0x80008188
    // 0x80133EF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80133EF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80133EFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133F00: lw          $a0, 0x444C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X444C);
    // 0x80133F04: jal         0x800D35DC
    // 0x80133F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleMakeGenerator(rdram, ctx);
        goto after_5;
    // 0x80133F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80133F0C: beql        $v0, $zero, L_80133F2C
    if (ctx->r2 == 0) {
        // 0x80133F10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80133F2C;
    }
    goto skip_0;
    // 0x80133F10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80133F14: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80133F18: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80133F1C: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80133F20: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80133F24: sw          $t4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r12;
L_80133F28:
    // 0x80133F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80133F2C:
    // 0x80133F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133F34: jr          $ra
    // 0x80133F38: nop

    return;
    // 0x80133F38: nop

;}
RECOMP_FUNC void ftParamGetStickAngleRads(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8008: lb          $v0, 0x1C2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1C2);
    // 0x800E800C: bgez        $v0, L_800E801C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E8010: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800E801C;
    }
    // 0x800E8010: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E8014: b           L_800E801C
    // 0x800E8018: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_800E801C;
    // 0x800E8018: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800E801C:
    // 0x800E801C: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x800E8020: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800E8024: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E8028: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E802C: jal         0x8001863C
    // 0x800E8030: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x800E8030: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800E8034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E803C: jr          $ra
    // 0x800E8040: nop

    return;
    // 0x800E8040: nop

;}
RECOMP_FUNC void func_ovl3_80138EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138EE4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80138EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138EEC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80138EF0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80138EF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80138EF8: bne         $a1, $v0, L_80138F08
    if (ctx->r5 != ctx->r2) {
        // 0x80138EFC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80138F08;
    }
    // 0x80138EFC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80138F00: b           L_801392B8
    // 0x80138F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x80138F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138F08:
    // 0x80138F08: bne         $v0, $at, L_80138F18
    if (ctx->r2 != ctx->r1) {
        // 0x80138F0C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80138F18;
    }
    // 0x80138F0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80138F10: b           L_80138F18
    // 0x80138F14: lw          $v1, 0xADC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XADC);
        goto L_80138F18;
    // 0x80138F14: lw          $v1, 0xADC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XADC);
L_80138F18:
    // 0x80138F18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80138F1C: bnel        $v1, $at, L_80138F78
    if (ctx->r3 != ctx->r1) {
        // 0x80138F20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80138F78;
    }
    goto skip_0;
    // 0x80138F20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80138F24: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80138F28: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80138F2C: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F30: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80138F6C;
    }
    // 0x80138F30: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80138F34: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F38: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80138F6C;
    }
    // 0x80138F38: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80138F3C: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F40: addiu       $at, $zero, 0xE2
        ctx->r1 = ADD32(0, 0XE2);
            goto L_80138F6C;
    }
    // 0x80138F40: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x80138F44: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F48: addiu       $at, $zero, 0xED
        ctx->r1 = ADD32(0, 0XED);
            goto L_80138F6C;
    }
    // 0x80138F48: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80138F4C: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F50: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80138F6C;
    }
    // 0x80138F50: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80138F54: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F58: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_80138F6C;
    }
    // 0x80138F58: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x80138F5C: beq         $v0, $at, L_80138F6C
    if (ctx->r2 == ctx->r1) {
        // 0x80138F60: addiu       $at, $zero, 0xF1
        ctx->r1 = ADD32(0, 0XF1);
            goto L_80138F6C;
    }
    // 0x80138F60: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x80138F64: bnel        $v0, $at, L_80138F78
    if (ctx->r2 != ctx->r1) {
        // 0x80138F68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80138F78;
    }
    goto skip_1;
    // 0x80138F68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
L_80138F6C:
    // 0x80138F6C: b           L_801392B8
    // 0x80138F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x80138F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138F74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80138F78:
    // 0x80138F78: beq         $v1, $at, L_80138F90
    if (ctx->r3 == ctx->r1) {
        // 0x80138F7C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80138F90;
    }
    // 0x80138F7C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80138F80: beql        $v1, $at, L_80138F94
    if (ctx->r3 == ctx->r1) {
        // 0x80138F84: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_80138F94;
    }
    goto skip_2;
    // 0x80138F84: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_2:
    // 0x80138F88: bnel        $v1, $a1, L_8013900C
    if (ctx->r3 != ctx->r5) {
        // 0x80138F8C: addiu       $v1, $a2, 0x1CC
        ctx->r3 = ADD32(ctx->r6, 0X1CC);
            goto L_8013900C;
    }
    goto skip_3;
    // 0x80138F8C: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    skip_3:
L_80138F90:
    // 0x80138F90: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_80138F94:
    // 0x80138F94: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80138F98: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138F9C: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80139000;
    }
    // 0x80138F9C: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80138FA0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FA4: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80139000;
    }
    // 0x80138FA4: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80138FA8: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FAC: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80139000;
    }
    // 0x80138FAC: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80138FB0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FB4: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_80139000;
    }
    // 0x80138FB4: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x80138FB8: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FBC: addiu       $at, $zero, 0xF3
        ctx->r1 = ADD32(0, 0XF3);
            goto L_80139000;
    }
    // 0x80138FBC: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x80138FC0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FC4: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80139000;
    }
    // 0x80138FC4: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80138FC8: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FCC: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80139000;
    }
    // 0x80138FCC: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80138FD0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FD4: addiu       $at, $zero, 0xEB
        ctx->r1 = ADD32(0, 0XEB);
            goto L_80139000;
    }
    // 0x80138FD4: addiu       $at, $zero, 0xEB
    ctx->r1 = ADD32(0, 0XEB);
    // 0x80138FD8: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FDC: addiu       $at, $zero, 0xEC
        ctx->r1 = ADD32(0, 0XEC);
            goto L_80139000;
    }
    // 0x80138FDC: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x80138FE0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FE4: addiu       $at, $zero, 0xED
        ctx->r1 = ADD32(0, 0XED);
            goto L_80139000;
    }
    // 0x80138FE4: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80138FE8: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FEC: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_80139000;
    }
    // 0x80138FEC: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x80138FF0: beq         $v0, $at, L_80139000
    if (ctx->r2 == ctx->r1) {
        // 0x80138FF4: addiu       $at, $zero, 0xEF
        ctx->r1 = ADD32(0, 0XEF);
            goto L_80139000;
    }
    // 0x80138FF4: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x80138FF8: bnel        $v0, $at, L_8013900C
    if (ctx->r2 != ctx->r1) {
        // 0x80138FFC: addiu       $v1, $a2, 0x1CC
        ctx->r3 = ADD32(ctx->r6, 0X1CC);
            goto L_8013900C;
    }
    goto skip_4;
    // 0x80138FFC: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    skip_4:
L_80139000:
    // 0x80139000: b           L_801392B8
    // 0x80139004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x80139004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80139008: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
L_8013900C:
    // 0x8013900C: lw          $t6, 0x48($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X48);
    // 0x80139010: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80139014: bgezl       $t8, L_80139044
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80139018: sw          $v1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r3;
            goto L_80139044;
    }
    goto skip_5;
    // 0x80139018: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    skip_5:
    // 0x8013901C: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x80139020: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80139024: lw          $v0, 0x24($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X24);
    // 0x80139028: beq         $v0, $at, L_80139038
    if (ctx->r2 == ctx->r1) {
        // 0x8013902C: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_80139038;
    }
    // 0x8013902C: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80139030: bnel        $v0, $at, L_80139044
    if (ctx->r2 != ctx->r1) {
        // 0x80139034: sw          $v1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r3;
            goto L_80139044;
    }
    goto skip_6;
    // 0x80139034: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    skip_6:
L_80139038:
    // 0x80139038: b           L_801392B8
    // 0x8013903C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x8013903C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80139040: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
L_80139044:
    // 0x80139044: jal         0x80018948
    // 0x80139048: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80139048: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013904C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80139050: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80139054: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80139058: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
    // 0x8013905C: bnel        $t0, $zero, L_801392B8
    if (ctx->r8 != 0) {
        // 0x80139060: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801392B8;
    }
    goto skip_7;
    // 0x80139060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x80139064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139068: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8013906C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139070: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80139074: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80139078: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013907C: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80139080: nop

    // 0x80139084: bc1fl       L_80139120
    if (!c1cs) {
        // 0x80139088: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80139120;
    }
    goto skip_8;
    // 0x80139088: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    skip_8:
    // 0x8013908C: lbu         $v0, 0x13($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X13);
    // 0x80139090: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80139094: bnel        $at, $zero, L_801390E4
    if (ctx->r1 != 0) {
        // 0x80139098: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_801390E4;
    }
    goto skip_9;
    // 0x80139098: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    skip_9:
    // 0x8013909C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801390A0: jal         0x80018948
    // 0x801390A4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x801390A4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_1:
    // 0x801390A8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801390AC: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x801390B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801390B4: lbu         $v0, 0x13($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X13);
    // 0x801390B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801390BC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801390C0: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x801390C4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801390C8: nop

    // 0x801390CC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801390D0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801390D4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801390D8: nop

    // 0x801390DC: bc1t        L_801391C8
    if (c1cs) {
        // 0x801390E0: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_801391C8;
    }
    // 0x801390E0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_801390E4:
    // 0x801390E4: bnel        $at, $zero, L_80139120
    if (ctx->r1 != 0) {
        // 0x801390E8: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80139120;
    }
    goto skip_10;
    // 0x801390E8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    skip_10:
    // 0x801390EC: lw          $t4, 0x44($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X44);
    // 0x801390F0: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    // 0x801390F4: lwc1        $f4, 0x60($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X60);
    // 0x801390F8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801390FC: lwc1        $f16, 0x1C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80139100: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80139104: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80139108: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013910C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80139110: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80139114: nop

    // 0x80139118: bc1t        L_801391C8
    if (c1cs) {
        // 0x8013911C: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_801391C8;
    }
    // 0x8013911C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_80139120:
    // 0x80139120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139124: lwc1        $f16, 0x68($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80139128: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8013912C: nop

    // 0x80139130: bc1fl       L_801392B8
    if (!c1cs) {
        // 0x80139134: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801392B8;
    }
    goto skip_11;
    // 0x80139134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x80139138: lbu         $t5, 0x13($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X13);
    // 0x8013913C: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x80139140: bnel        $at, $zero, L_801392B8
    if (ctx->r1 != 0) {
        // 0x80139144: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801392B8;
    }
    goto skip_12;
    // 0x80139144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x80139148: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8013914C: jal         0x80018948
    // 0x80139150: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80139150: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_2:
    // 0x80139154: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80139158: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8013915C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80139160: lbu         $t6, 0x13($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X13);
    // 0x80139164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139168: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8013916C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80139170: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80139174: nop

    // 0x80139178: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013917C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80139180: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80139184: nop

    // 0x80139188: bc1fl       L_801392B8
    if (!c1cs) {
        // 0x8013918C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801392B8;
    }
    goto skip_13;
    // 0x8013918C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_13:
    // 0x80139190: lw          $t0, 0x6C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X6C);
    // 0x80139194: lw          $t9, 0x8E8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8E8);
    // 0x80139198: lwc1        $f16, 0x60($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X60);
    // 0x8013919C: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x801391A0: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x801391A4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x801391A8: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801391AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801391B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801391B4: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801391B8: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x801391BC: nop

    // 0x801391C0: bc1fl       L_801392B8
    if (!c1cs) {
        // 0x801391C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801392B8;
    }
    goto skip_14;
    // 0x801391C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_14:
L_801391C8:
    // 0x801391C8: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    // 0x801391CC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801391D0: bltzl       $a0, L_80139274
    if (SIGNED(ctx->r4) < 0) {
        // 0x801391D4: lw          $t3, 0x8E8($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X8E8);
            goto L_80139274;
    }
    goto skip_15;
    // 0x801391D4: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    skip_15:
    // 0x801391D8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x801391DC: jal         0x800F4428
    // 0x801391E0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x801391E0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_3:
    // 0x801391E4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801391E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801391EC: jal         0x800F4408
    // 0x801391F0: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x801391F0: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    after_4:
    // 0x801391F4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801391F8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801391FC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80139200: lw          $t2, 0x8E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8E8);
    // 0x80139204: lwc1        $f6, 0x60($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139208: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8013920C: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80139210: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80139214: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80139218: nop

    // 0x8013921C: bc1fl       L_80139250
    if (!c1cs) {
        // 0x80139220: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80139250;
    }
    goto skip_16;
    // 0x80139220: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_16:
    // 0x80139224: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80139228: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013922C: nop

    // 0x80139230: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80139234: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80139238: nop

    // 0x8013923C: bc1fl       L_80139274
    if (!c1cs) {
        // 0x80139240: lw          $t3, 0x8E8($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X8E8);
            goto L_80139274;
    }
    goto skip_17;
    // 0x80139240: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    skip_17:
    // 0x80139244: b           L_801392B8
    // 0x80139248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x80139248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013924C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80139250:
    // 0x80139250: nop

    // 0x80139254: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80139258: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8013925C: nop

    // 0x80139260: bc1fl       L_80139274
    if (!c1cs) {
        // 0x80139264: lw          $t3, 0x8E8($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X8E8);
            goto L_80139274;
    }
    goto skip_18;
    // 0x80139264: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    skip_18:
    // 0x80139268: b           L_801392B8
    // 0x8013926C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801392B8;
    // 0x8013926C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80139270: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
L_80139274:
    // 0x80139274: lwc1        $f8, 0x60($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139278: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x8013927C: lwc1        $f18, 0x1C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80139280: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80139284: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80139288: nop

    // 0x8013928C: bc1f        L_801392A4
    if (!c1cs) {
        // 0x80139290: nop
    
            goto L_801392A4;
    }
    // 0x80139290: nop

    // 0x80139294: jal         0x80132564
    // 0x80139298: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_5;
    // 0x80139298: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x8013929C: b           L_801392B8
    // 0x801392A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801392B8;
    // 0x801392A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801392A4:
    // 0x801392A4: jal         0x80132564
    // 0x801392A8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_6;
    // 0x801392A8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_6:
    // 0x801392AC: b           L_801392B8
    // 0x801392B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801392B8;
    // 0x801392B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801392B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801392B8:
    // 0x801392B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801392BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801392C0: jr          $ra
    // 0x801392C4: nop

    return;
    // 0x801392C4: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133918: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013391C: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x80133920: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133924: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80133928: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8013392C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80133930: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80133934: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80133938: sw          $zero, 0x42FC($at)
    MEM_W(0X42FC, ctx->r1) = 0;
    // 0x8013393C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80133940: addiu       $t8, $t8, 0x4B18
    ctx->r24 = ADD32(ctx->r24, 0X4B18);
    // 0x80133944: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80133948: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013394C: lbu         $t9, 0x23($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X23);
    // 0x80133950: lbu         $t0, 0x26($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X26);
    // 0x80133954: lbu         $t1, 0x27($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X27);
    // 0x80133958: addiu       $v1, $v1, 0x4348
    ctx->r3 = ADD32(ctx->r3, 0X4348);
    // 0x8013395C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133960: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133964: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80133968: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8013396C: sw          $zero, 0x4338($at)
    MEM_W(0X4338, ctx->r1) = 0;
    // 0x80133970: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133974: sw          $zero, 0x433C($at)
    MEM_W(0X433C, ctx->r1) = 0;
    // 0x80133978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013397C: sw          $zero, 0x4354($at)
    MEM_W(0X4354, ctx->r1) = 0;
    // 0x80133980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133984: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80133988: jr          $ra
    // 0x8013398C: sw          $t2, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r10;
    return;
    // 0x8013398C: sw          $t2, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void ftSamusSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DC94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015DC98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015DC9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015DCA0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015DCA4: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8015DCA8: beql        $t6, $zero, L_8015DCD4
    if (ctx->r14 == 0) {
        // 0x8015DCAC: lw          $t8, 0x14C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X14C);
            goto L_8015DCD4;
    }
    goto skip_0;
    // 0x8015DCAC: lw          $t8, 0x14C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14C);
    skip_0:
    // 0x8015DCB0: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x8015DCB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8015DCB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015DCBC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8015DCC0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8015DCC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015DCC8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015DCCC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x8015DCD0: lw          $t8, 0x14C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14C);
L_8015DCD4:
    // 0x8015DCD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015DCD8: bne         $t8, $at, L_8015DD04
    if (ctx->r24 != ctx->r1) {
        // 0x8015DCDC: nop
    
            goto L_8015DD04;
    }
    // 0x8015DCDC: nop

    // 0x8015DCE0: jal         0x800D9414
    // 0x8015DCE4: nop

    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x8015DCE4: nop

    after_0:
    // 0x8015DCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015DCEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015DCF0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8015DCF4: jal         0x800D8FC8
    // 0x8015DCF8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_1;
    // 0x8015DCF8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_1:
    // 0x8015DCFC: b           L_8015DD10
    // 0x8015DD00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015DD10;
    // 0x8015DD00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015DD04:
    // 0x8015DD04: jal         0x800D8BB4
    // 0x8015DD08: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_2;
    // 0x8015DD08: nop

    after_2:
    // 0x8015DD0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015DD10:
    // 0x8015DD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015DD14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015DD18: jr          $ra
    // 0x8015DD1C: nop

    return;
    // 0x8015DD1C: nop

;}
RECOMP_FUNC void ifScreenFlashMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115DE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80115DEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80115DF0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80115DF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80115DFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80115E00: sb          $a1, 0x1AA4($at)
    MEM_B(0X1AA4, ctx->r1) = ctx->r5;
    // 0x80115E04: jal         0x800E9838
    // 0x80115E08: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    ftParamResetColAnim(rdram, ctx);
        goto after_0;
    // 0x80115E08: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    after_0:
    // 0x80115E0C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80115E10: lbu         $t6, 0x4930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4930);
    // 0x80115E14: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80115E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80115E1C: beq         $t6, $zero, L_80115E68
    if (ctx->r14 == 0) {
        // 0x80115E20: addiu       $a2, $zero, 0xB
        ctx->r6 = ADD32(0, 0XB);
            goto L_80115E68;
    }
    // 0x80115E20: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80115E24: jal         0x80009968
    // 0x80115E28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80115E28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80115E2C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80115E30: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80115E34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80115E38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80115E3C: addiu       $a1, $a1, 0x5C20
    ctx->r5 = ADD32(ctx->r5, 0X5C20);
    // 0x80115E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80115E44: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80115E48: jal         0x80009DF4
    // 0x80115E4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80115E4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80115E50: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80115E54: addiu       $a1, $a1, 0x5DA8
    ctx->r5 = ADD32(ctx->r5, 0X5DA8);
    // 0x80115E58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80115E5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80115E60: jal         0x80008188
    // 0x80115E64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80115E64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_80115E68:
    // 0x80115E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80115E6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80115E70: jr          $ra
    // 0x80115E74: nop

    return;
    // 0x80115E74: nop

;}
RECOMP_FUNC void syMainSetDmemStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800004B0: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x800004B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800004B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800004BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800004C0: bne         $t7, $at, L_800004D0
    if (ctx->r15 != ctx->r1) {
        // 0x800004C4: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_800004D0;
    }
    // 0x800004C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800004C8: jr          $ra
    // 0x800004CC: sb          $t8, 0x4D41($at)
    MEM_B(0X4D41, ctx->r1) = ctx->r24;
    return;
    // 0x800004CC: sb          $t8, 0x4D41($at)
    MEM_B(0X4D41, ctx->r1) = ctx->r24;
L_800004D0:
    // 0x800004D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800004D4: sb          $zero, 0x4D41($at)
    MEM_B(0X4D41, ctx->r1) = 0;
    // 0x800004D8: jr          $ra
    // 0x800004DC: nop

    return;
    // 0x800004DC: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltAirProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016956C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169574: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80169578: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016957C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80169580: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80169584: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80169588: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016958C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80169590: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80169594: jal         0x80019438
    // 0x80169598: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80169598: nop

    after_0:
    // 0x8016959C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801695A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801695A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801695A8: jr          $ra
    // 0x801695AC: nop

    return;
    // 0x801695AC: nop

;}
RECOMP_FUNC void mnPlayersVSCheckSingleTeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A470: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A474: lw          $t6, -0x44F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44F0);
    // 0x8013A478: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8013A47C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A480: beq         $t6, $zero, L_8013A490
    if (ctx->r14 == 0) {
        // 0x8013A484: lui         $t9, 0x8014
        ctx->r25 = S32(0X8014 << 16);
            goto L_8013A490;
    }
    // 0x8013A484: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013A488: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013A48C: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
L_8013A490:
    // 0x8013A490: lw          $t7, -0x4434($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4434);
    // 0x8013A494: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8013A498: beq         $t7, $zero, L_8013A4C8
    if (ctx->r15 == 0) {
        // 0x8013A49C: nop
    
            goto L_8013A4C8;
    }
    // 0x8013A49C: nop

    // 0x8013A4A0: bne         $v0, $v1, L_8013A4B4
    if (ctx->r2 != ctx->r3) {
        // 0x8013A4A4: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_8013A4B4;
    }
    // 0x8013A4A4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A4A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013A4AC: b           L_8013A4C8
    // 0x8013A4B0: lw          $v0, -0x447C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X447C);
        goto L_8013A4C8;
    // 0x8013A4B0: lw          $v0, -0x447C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X447C);
L_8013A4B4:
    // 0x8013A4B4: lw          $t8, -0x447C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X447C);
    // 0x8013A4B8: beq         $v0, $t8, L_8013A4C8
    if (ctx->r2 == ctx->r24) {
        // 0x8013A4BC: nop
    
            goto L_8013A4C8;
    }
    // 0x8013A4BC: nop

    // 0x8013A4C0: jr          $ra
    // 0x8013A4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A4C8:
    // 0x8013A4C8: lw          $t9, -0x4378($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4378);
    // 0x8013A4CC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013A4D0: beq         $t9, $zero, L_8013A500
    if (ctx->r25 == 0) {
        // 0x8013A4D4: nop
    
            goto L_8013A500;
    }
    // 0x8013A4D4: nop

    // 0x8013A4D8: bne         $v0, $v1, L_8013A4EC
    if (ctx->r2 != ctx->r3) {
        // 0x8013A4DC: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_8013A4EC;
    }
    // 0x8013A4DC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013A4E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013A4E4: b           L_8013A500
    // 0x8013A4E8: lw          $v0, -0x43C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X43C0);
        goto L_8013A500;
    // 0x8013A4E8: lw          $v0, -0x43C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X43C0);
L_8013A4EC:
    // 0x8013A4EC: lw          $t0, -0x43C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X43C0);
    // 0x8013A4F0: beq         $v0, $t0, L_8013A500
    if (ctx->r2 == ctx->r8) {
        // 0x8013A4F4: nop
    
            goto L_8013A500;
    }
    // 0x8013A4F4: nop

    // 0x8013A4F8: jr          $ra
    // 0x8013A4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A500:
    // 0x8013A500: lw          $t1, -0x42BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X42BC);
    // 0x8013A504: beql        $t1, $zero, L_8013A52C
    if (ctx->r9 == 0) {
        // 0x8013A508: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8013A52C;
    }
    goto skip_0;
    // 0x8013A508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8013A50C: beq         $v0, $v1, L_8013A528
    if (ctx->r2 == ctx->r3) {
        // 0x8013A510: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_8013A528;
    }
    // 0x8013A510: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013A514: lw          $t2, -0x4304($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4304);
    // 0x8013A518: beql        $v0, $t2, L_8013A52C
    if (ctx->r2 == ctx->r10) {
        // 0x8013A51C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8013A52C;
    }
    goto skip_1;
    // 0x8013A51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8013A520: jr          $ra
    // 0x8013A524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013A524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013A528:
    // 0x8013A528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013A52C:
    // 0x8013A52C: jr          $ra
    // 0x8013A530: nop

    return;
    // 0x8013A530: nop

;}
RECOMP_FUNC void func_ovl3_80137E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137E78: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80137E7C: jal         0x80136D0C
    // 0x80137E80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137E80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80137E84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80137E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137E8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137E90: addiu       $v1, $a1, 0x1CC
    ctx->r3 = ADD32(ctx->r5, 0X1CC);
    // 0x80137E94: lbu         $t6, 0x4A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4A);
    // 0x80137E98: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80137E9C: beq         $v0, $zero, L_80137EAC
    if (ctx->r2 == 0) {
        // 0x80137EA0: sb          $t7, 0x4A($v1)
        MEM_B(0X4A, ctx->r3) = ctx->r15;
            goto L_80137EAC;
    }
    // 0x80137EA0: sb          $t7, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r15;
    // 0x80137EA4: bne         $v0, $at, L_80137EB4
    if (ctx->r2 != ctx->r1) {
        // 0x80137EA8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80137EB4;
    }
    // 0x80137EA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80137EAC:
    // 0x80137EAC: b           L_80137F14
    // 0x80137EB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80137F14;
    // 0x80137EB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80137EB4:
    // 0x80137EB4: lwc1        $f0, 0x70($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80137EB8: lwc1        $f2, 0x74($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80137EBC: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x80137EC0: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80137EC4: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
    // 0x80137EC8: swc1        $f2, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f2.u32l;
    // 0x80137ECC: sw          $t8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r24;
    // 0x80137ED0: lw          $v0, 0x8E8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8E8);
    // 0x80137ED4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137ED8: lwc1        $f18, -0x4104($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4104);
    // 0x80137EDC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80137EE0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80137EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137EE8: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80137EEC: sub.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80137EF0: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80137EF4: nop

    // 0x80137EF8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80137EFC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80137F00: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80137F04: nop

    // 0x80137F08: bc1f        L_80137F14
    if (!c1cs) {
        // 0x80137F0C: nop
    
            goto L_80137F14;
    }
    // 0x80137F0C: nop

    // 0x80137F10: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80137F14:
    // 0x80137F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80137F1C: jr          $ra
    // 0x80137F20: nop

    return;
    // 0x80137F20: nop

;}
RECOMP_FUNC void mnPlayers1PGameSetCursorGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135DA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80135DA4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80135DA8: addiu       $s0, $s0, -0x7118
    ctx->r16 = ADD32(ctx->r16, -0X7118);
    // 0x80135DAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135DB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80135DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80135DB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80135DBC: sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    // 0x80135DC0: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80135DC4: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80135DC8: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    // 0x80135DCC: jal         0x80135804
    // 0x80135DD0: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    mnPlayers1PGameUpdateFighter(rdram, ctx);
        goto after_0;
    // 0x80135DD0: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    after_0:
    // 0x80135DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80135DD8: jal         0x80135C88
    // 0x80135DDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameUpdateCursorGrabPriorities(rdram, ctx);
        goto after_1;
    // 0x80135DDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80135DE0: jal         0x80135D58
    // 0x80135DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PGameSetCursorPuckOffset(rdram, ctx);
        goto after_2;
    // 0x80135DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80135DE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80135DEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80135DF0: jal         0x801352BC
    // 0x80135DF4: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_3;
    // 0x80135DF4: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x80135DF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80135DFC: sw          $t7, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r15;
    // 0x80135E00: jal         0x800269C0
    // 0x80135E04: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80135E04: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_4:
    // 0x80135E08: jal         0x80135924
    // 0x80135E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PGameDestroyPortraitFlash(rdram, ctx);
        goto after_5;
    // 0x80135E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80135E10: jal         0x801358C4
    // 0x80135E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PGameUpdateNameAndEmblem(rdram, ctx);
        goto after_6;
    // 0x80135E14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80135E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135E1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80135E20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80135E24: jr          $ra
    // 0x80135E28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80135E28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void efManagerPikachuThunderTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101A10: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80101A14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101A18: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80101A1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80101A20: bne         $v0, $zero, L_80101A40
    if (ctx->r2 != 0) {
        // 0x80101A24: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80101A40;
    }
    // 0x80101A24: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80101A28: jal         0x800FD4F8
    // 0x80101A2C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x80101A2C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80101A30: jal         0x80009A84
    // 0x80101A34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80101A34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80101A38: b           L_80101A9C
    // 0x80101A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80101A9C;
    // 0x80101A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101A40:
    // 0x80101A40: sw          $t6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r14;
    // 0x80101A44: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80101A48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80101A4C: lw          $v0, 0x80($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X80);
    // 0x80101A50: lhu         $t8, 0x80($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X80);
    // 0x80101A54: beql        $t8, $at, L_80101A9C
    if (ctx->r24 == ctx->r1) {
        // 0x80101A58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80101A9C;
    }
    goto skip_0;
    // 0x80101A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80101A5C: bne         $t6, $zero, L_80101A80
    if (ctx->r14 != 0) {
        // 0x80101A60: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80101A80;
    }
    // 0x80101A60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101A64: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80101A68: sh          $t0, 0x80($v0)
    MEM_H(0X80, ctx->r2) = ctx->r8;
    // 0x80101A6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101A70: lwc1        $f4, 0x9DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9DC);
    // 0x80101A74: lw          $t1, 0x74($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X74);
    // 0x80101A78: b           L_80101A98
    // 0x80101A7C: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
        goto L_80101A98;
    // 0x80101A7C: swc1        $f4, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f4.u32l;
L_80101A80:
    // 0x80101A80: jal         0x80018994
    // 0x80101A84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80101A84: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80101A88: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101A8C: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80101A90: lw          $t3, 0x80($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X80);
    // 0x80101A94: sh          $v0, 0x80($t3)
    MEM_H(0X80, ctx->r11) = ctx->r2;
L_80101A98:
    // 0x80101A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101A9C:
    // 0x80101A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101AA0: jr          $ra
    // 0x80101AA4: nop

    return;
    // 0x80101AA4: nop

;}
RECOMP_FUNC void ftFoxSpecialLwHitDecideSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015CE0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CE10: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015CE14: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8015CE18: bgtzl       $t6, L_8015CE5C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8015CE1C: lw          $t9, 0x14C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X14C);
            goto L_8015CE5C;
    }
    goto skip_0;
    // 0x8015CE1C: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    skip_0:
    // 0x8015CE20: lw          $t7, 0xB20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB20);
    // 0x8015CE24: beql        $t7, $zero, L_8015CE5C
    if (ctx->r15 == 0) {
        // 0x8015CE28: lw          $t9, 0x14C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X14C);
            goto L_8015CE5C;
    }
    goto skip_1;
    // 0x8015CE28: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    skip_1:
    // 0x8015CE2C: lw          $t8, 0x14C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14C);
    // 0x8015CE30: bne         $t8, $zero, L_8015CE48
    if (ctx->r24 != 0) {
        // 0x8015CE34: nop
    
            goto L_8015CE48;
    }
    // 0x8015CE34: nop

    // 0x8015CE38: jal         0x8015D180
    // 0x8015CE3C: nop

    ftFoxSpecialLwEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CE3C: nop

    after_0:
    // 0x8015CE40: b           L_8015CE80
    // 0x8015CE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CE80;
    // 0x8015CE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CE48:
    // 0x8015CE48: jal         0x8015D1B0
    // 0x8015CE4C: nop

    ftFoxSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015CE4C: nop

    after_1:
    // 0x8015CE50: b           L_8015CE80
    // 0x8015CE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CE80;
    // 0x8015CE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015CE58: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
L_8015CE5C:
    // 0x8015CE5C: bne         $t9, $zero, L_8015CE74
    if (ctx->r25 != 0) {
        // 0x8015CE60: nop
    
            goto L_8015CE74;
    }
    // 0x8015CE60: nop

    // 0x8015CE64: jal         0x8015CD90
    // 0x8015CE68: nop

    ftFoxSpecialLwLoopSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015CE68: nop

    after_2:
    // 0x8015CE6C: b           L_8015CE80
    // 0x8015CE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015CE80;
    // 0x8015CE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CE74:
    // 0x8015CE74: jal         0x8015CDCC
    // 0x8015CE78: nop

    ftFoxSpecialAirLwLoopSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015CE78: nop

    after_3:
    // 0x8015CE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CE80:
    // 0x8015CE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015CE84: jr          $ra
    // 0x8015CE88: nop

    return;
    // 0x8015CE88: nop

;}
RECOMP_FUNC void syMatrixRotPitchRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D14C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D150: jal         0x800303F0
    // 0x8001D154: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D154: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001D158: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D15C: jal         0x80035CD0
    // 0x8001D160: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D160: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8001D164: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001D168: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D16C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D178: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8001D17C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8001D180: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8001D184: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8001D188: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x8001D18C: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8001D190: swc1        $f14, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f14.u32l;
    // 0x8001D194: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x8001D198: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8001D19C: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1A0: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1A4: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1A8: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1AC: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1B0: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1B4: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1B8: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x8001D1BC: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8001D1C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D1C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D1C8: jr          $ra
    // 0x8001D1CC: nop

    return;
    // 0x8001D1CC: nop

;}
RECOMP_FUNC void ftNessSpecialHiProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801549B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801549B4: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x801549B8: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x801549BC: beq         $t7, $zero, L_801549EC
    if (ctx->r15 == 0) {
        // 0x801549C0: nop
    
            goto L_801549EC;
    }
    // 0x801549C0: nop

    // 0x801549C4: lw          $t8, 0xB28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB28);
    // 0x801549C8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801549CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801549D0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801549D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801549D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801549DC: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x801549E0: nop

    // 0x801549E4: bc1f        L_801549F4
    if (!c1cs) {
        // 0x801549E8: nop
    
            goto L_801549F4;
    }
    // 0x801549E8: nop

L_801549EC:
    // 0x801549EC: jr          $ra
    // 0x801549F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801549F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801549F4:
    // 0x801549F4: jr          $ra
    // 0x801549F8: nop

    return;
    // 0x801549F8: nop

;}
RECOMP_FUNC void mnMapsMakePreviewWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801335F0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801335F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801335F8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801335FC: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80133600: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133604: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80133608: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013360C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133610: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133614: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133618: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013361C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133620: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133624: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133628: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013362C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133630: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133634: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133638: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013363C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133648: jal         0x8000B93C
    // 0x8013364C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013364C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133650: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133654: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133658: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013365C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133664: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133668: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013366C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133670: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133674: jal         0x80007080
    // 0x80133678: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133678: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013367C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133680: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133684: jr          $ra
    // 0x80133688: nop

    return;
    // 0x80133688: nop

;}
RECOMP_FUNC void dbBattleMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801322E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801322E4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801322E8: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801322EC: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x801322F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801322F4: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x801322F8: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x801322FC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132300: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80132304: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132308: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013230C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132310: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132314: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80132318: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8013231C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132320: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132324: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132328: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x8013232C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132330: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132334: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80132338: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8013233C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132340: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80132344: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132348: jal         0x8000B93C
    // 0x8013234C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013234C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_0:
    // 0x80132350: bne         $v0, $zero, L_80132360
    if (ctx->r2 != 0) {
        // 0x80132354: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80132360;
    }
    // 0x80132354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132358: b           L_8013238C
    // 0x8013235C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013238C;
    // 0x8013235C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132360:
    // 0x80132360: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80132364: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80132368: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013236C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80132370: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132374: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x80132378: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x8013237C: lwc1        $f4, 0x2C1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2C1C);
    // 0x80132380: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80132384: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80132388: swc1        $f4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f4.u32l;
L_8013238C:
    // 0x8013238C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132390: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132394: jr          $ra
    // 0x80132398: nop

    return;
    // 0x80132398: nop

;}
RECOMP_FUNC void itMSBombExplodeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176934: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80176938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017693C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176940: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x80176944: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x80176948: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017694C: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80176950: beql        $t7, $zero, L_801769A0
    if (ctx->r15 == 0) {
        // 0x80176954: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801769A0;
    }
    goto skip_0;
    // 0x80176954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80176958: lw          $t9, 0x1C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X1C);
    // 0x8017695C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80176960: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80176964: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80176968: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8017696C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80176970: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x80176974: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80176978: lh          $t0, 0x2E($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2E);
    // 0x8017697C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80176980: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80176984: nop

    // 0x80176988: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017698C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80176990: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80176994: jal         0x800FF3F4
    // 0x80176998: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80176998: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    after_0:
    // 0x8017699C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801769A0:
    // 0x801769A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801769A4: jr          $ra
    // 0x801769A8: nop

    return;
    // 0x801769A8: nop

;}
RECOMP_FUNC void mvOpeningMarioInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE5C: jr          $ra
    // 0x8018DE60: sw          $zero, -0x1DF8($at)
    MEM_W(-0X1DF8, ctx->r1) = 0;
    return;
    // 0x8018DE60: sw          $zero, -0x1DF8($at)
    MEM_W(-0X1DF8, ctx->r1) = 0;
;}
RECOMP_FUNC void func_ovl8_80384F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384F3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80384F40: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80384F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384F48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80384F4C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80384F50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80384F54: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80384F58: addiu       $t6, $t6, -0x29C0
    ctx->r14 = ADD32(ctx->r14, -0X29C0);
    // 0x80384F5C: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x80384F60: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x80384F64: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80384F68: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80384F6C: swl         $t8, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r24);
    // 0x80384F70: swr         $t8, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r24);
    // 0x80384F74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80384F78: jal         0x80378064
    // 0x80384F7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_80378064(rdram, ctx);
        goto after_0;
    // 0x80384F7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80384F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80384F88: jr          $ra
    // 0x80384F8C: nop

    return;
    // 0x80384F8C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPortraitProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132430: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132434: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132438: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013243C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132444: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132448: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013244C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132450: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132454: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132458: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013245C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132460: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132464: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132468: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013246C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132470: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132478: lui         $t4, 0x3030
    ctx->r12 = S32(0X3030 << 16);
    // 0x8013247C: ori         $t4, $t4, 0x30FF
    ctx->r12 = ctx->r12 | 0X30FF;
    // 0x80132480: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80132484: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80132488: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8013248C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80132490: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132494: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132498: lui         $t7, 0x11FC
    ctx->r15 = S32(0X11FC << 16);
    // 0x8013249C: lui         $t6, 0xFC71
    ctx->r14 = S32(0XFC71 << 16);
    // 0x801324A0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801324A4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801324A8: ori         $t6, $t6, 0xFEE3
    ctx->r14 = ctx->r14 | 0XFEE3;
    // 0x801324AC: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x801324B0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801324B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801324B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801324BC: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x801324C0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801324C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801324C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801324CC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801324D0: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x801324D4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801324D8: jal         0x800CCF74
    // 0x801324DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x801324DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x801324E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801324E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801324E8: jr          $ra
    // 0x801324EC: nop

    return;
    // 0x801324EC: nop

;}
RECOMP_FUNC void itBoxWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017974C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179754: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179758: lwc1        $f12, 0xBC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x8017975C: jal         0x8001863C
    // 0x80179760: lwc1        $f14, 0xB8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XB8);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80179760: lwc1        $f14, 0xB8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XB8);
    after_0:
    // 0x80179764: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179768: lwc1        $f4, -0x3298($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3298);
    // 0x8017976C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179770: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80179774: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80179778: jal         0x80172E74
    // 0x8017977C: swc1        $f6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f6.u32l;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_1;
    // 0x8017977C: swc1        $f6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f6.u32l;
    after_1:
    // 0x80179780: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179784: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x80179788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017978C: jal         0x80172EC8
    // 0x80179790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80179790: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80179794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017979C: jr          $ra
    // 0x801797A0: nop

    return;
    // 0x801797A0: nop

;}
RECOMP_FUNC void mnPlayersVSMakeGameRuleNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133BB0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80133BB4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80133BB8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133BBC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80133BC0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80133BC4: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80133BC8: addiu       $t6, $t6, -0x48FC
    ctx->r14 = ADD32(ctx->r14, -0X48FC);
    // 0x80133BCC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80133BD0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80133BD4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80133BD8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80133BDC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80133BE0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80133BE4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80133BE8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80133BEC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80133BF0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80133BF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133BF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80133BFC: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80133C00: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80133C04: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80133C08:
    // 0x80133C08: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133C0C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133C10: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133C14: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133C18: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133C1C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133C20: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133C24: bne         $t6, $t0, L_80133C08
    if (ctx->r14 != ctx->r8) {
        // 0x80133C28: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133C08;
    }
    // 0x80133C28: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133C2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133C30: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80133C34: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80133C38: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80133C3C: bgez        $s3, L_80133C48
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80133C40: lwc1        $f20, 0x98($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0X98);
            goto L_80133C48;
    }
    // 0x80133C40: lwc1        $f20, 0x98($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80133C44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80133C48:
    // 0x80133C48: div         $zero, $s3, $s6
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r22)));
    // 0x80133C4C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80133C50: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80133C54: addiu       $s7, $s7, -0x3B60
    ctx->r23 = ADD32(ctx->r23, -0X3B60);
    // 0x80133C58: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80133C5C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80133C60: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x80133C64: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80133C68: bne         $s6, $zero, L_80133C74
    if (ctx->r22 != 0) {
        // 0x80133C6C: nop
    
            goto L_80133C74;
    }
    // 0x80133C6C: nop

    // 0x80133C70: break       7
    do_break(2148744304);
L_80133C74:
    // 0x80133C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133C78: bne         $s6, $at, L_80133C8C
    if (ctx->r22 != ctx->r1) {
        // 0x80133C7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133C8C;
    }
    // 0x80133C7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133C80: bne         $s3, $at, L_80133C8C
    if (ctx->r19 != ctx->r1) {
        // 0x80133C84: nop
    
            goto L_80133C8C;
    }
    // 0x80133C84: nop

    // 0x80133C88: break       6
    do_break(2148744328);
L_80133C8C:
    // 0x80133C8C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80133C90: jal         0x800CCFDC
    // 0x80133C94: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80133C94: nop

    after_0:
    // 0x80133C98: lw          $s4, 0xA0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA0);
    // 0x80133C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133CA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133CA4: jal         0x80133ABC
    // 0x80133CA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayersVSSetDigitColors(rdram, ctx);
        goto after_1;
    // 0x80133CA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80133CAC: lh          $t0, 0x14($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X14);
    // 0x80133CB0: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80133CB4: lw          $s5, 0xA8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA8);
    // 0x80133CB8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80133CBC: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x80133CC0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80133CC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133CC8: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80133CCC: beq         $s5, $zero, L_80133CE0
    if (ctx->r21 == 0) {
        // 0x80133CD0: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80133CE0;
    }
    // 0x80133CD0: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80133CD4: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x80133CD8: b           L_80133CF4
    // 0x80133CDC: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80133CF4;
    // 0x80133CDC: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80133CE0:
    // 0x80133CE0: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x80133CE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80133CE8: jal         0x80133B04
    // 0x80133CEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayersVSGetNumberDigitCount(rdram, ctx);
        goto after_2;
    // 0x80133CEC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80133CF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133CF4:
    // 0x80133CF4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80133CF8: bne         $at, $zero, L_80133DF0
    if (ctx->r1 != 0) {
        // 0x80133CFC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80133DF0;
    }
    // 0x80133CFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80133D00:
    // 0x80133D00: jal         0x80133A1C
    // 0x80133D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSGetPowerOf(rdram, ctx);
        goto after_3;
    // 0x80133D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80133D08: beq         $v0, $zero, L_80133D50
    if (ctx->r2 == 0) {
        // 0x80133D0C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80133D50;
    }
    // 0x80133D0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80133D10: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80133D14: jal         0x80133A1C
    // 0x80133D18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80133D18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80133D1C: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80133D20: mflo        $v1
    ctx->r3 = lo;
    // 0x80133D24: bne         $v0, $zero, L_80133D30
    if (ctx->r2 != 0) {
        // 0x80133D28: nop
    
            goto L_80133D30;
    }
    // 0x80133D28: nop

    // 0x80133D2C: break       7
    do_break(2148744492);
L_80133D30:
    // 0x80133D30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133D34: bne         $v0, $at, L_80133D48
    if (ctx->r2 != ctx->r1) {
        // 0x80133D38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133D48;
    }
    // 0x80133D38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133D3C: bne         $s3, $at, L_80133D48
    if (ctx->r19 != ctx->r1) {
        // 0x80133D40: nop
    
            goto L_80133D48;
    }
    // 0x80133D40: nop

    // 0x80133D44: break       6
    do_break(2148744516);
L_80133D48:
    // 0x80133D48: b           L_80133D50
    // 0x80133D4C: nop

        goto L_80133D50;
    // 0x80133D4C: nop

L_80133D50:
    // 0x80133D50: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80133D54: mfhi        $t6
    ctx->r14 = hi;
    // 0x80133D58: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80133D5C: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x80133D60: lw          $t7, 0x68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68);
    // 0x80133D64: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80133D68: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80133D6C: bne         $s6, $zero, L_80133D78
    if (ctx->r22 != 0) {
        // 0x80133D70: nop
    
            goto L_80133D78;
    }
    // 0x80133D70: nop

    // 0x80133D74: break       7
    do_break(2148744564);
L_80133D78:
    // 0x80133D78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133D7C: bne         $s6, $at, L_80133D90
    if (ctx->r22 != ctx->r1) {
        // 0x80133D80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133D90;
    }
    // 0x80133D80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133D84: bne         $v1, $at, L_80133D90
    if (ctx->r3 != ctx->r1) {
        // 0x80133D88: nop
    
            goto L_80133D90;
    }
    // 0x80133D88: nop

    // 0x80133D8C: break       6
    do_break(2148744588);
L_80133D90:
    // 0x80133D90: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80133D94: jal         0x800CCFDC
    // 0x80133D98: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80133D98: nop

    after_5:
    // 0x80133D9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133DA4: jal         0x80133ABC
    // 0x80133DA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnPlayersVSSetDigitColors(rdram, ctx);
        goto after_6;
    // 0x80133DA8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80133DAC: lh          $t1, 0x14($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X14);
    // 0x80133DB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80133DB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80133DB8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80133DBC: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x80133DC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133DC4: sub.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f16.fl;
    // 0x80133DC8: beq         $s5, $zero, L_80133DD8
    if (ctx->r21 == 0) {
        // 0x80133DCC: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80133DD8;
    }
    // 0x80133DCC: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80133DD0: b           L_80133DE4
    // 0x80133DD4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80133DE4;
    // 0x80133DD4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80133DD8:
    // 0x80133DD8: jal         0x80133B04
    // 0x80133DDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayersVSGetNumberDigitCount(rdram, ctx);
        goto after_7;
    // 0x80133DDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80133DE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133DE4:
    // 0x80133DE4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80133DE8: bnel        $at, $zero, L_80133D00
    if (ctx->r1 != 0) {
        // 0x80133DEC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80133D00;
    }
    goto skip_0;
    // 0x80133DEC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
L_80133DF0:
    // 0x80133DF0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80133DF4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133DF8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133DFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133E00: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80133E04: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80133E08: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80133E0C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80133E10: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80133E14: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80133E18: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80133E1C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80133E20: jr          $ra
    // 0x80133E24: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80133E24: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void mvOpeningYoshiMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D318: lw          $t6, -0x1DD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1DD8);
    // 0x8018D31C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D320: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D324: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D328: bne         $at, $zero, L_8018D404
    if (ctx->r1 != 0) {
        // 0x8018D32C: addiu       $v1, $v1, -0x1D98
        ctx->r3 = ADD32(ctx->r3, -0X1D98);
            goto L_8018D404;
    }
    // 0x8018D32C: addiu       $v1, $v1, -0x1D98
    ctx->r3 = ADD32(ctx->r3, -0X1D98);
    // 0x8018D330: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D334: addiu       $a0, $a0, -0x1DB8
    ctx->r4 = ADD32(ctx->r4, -0X1DB8);
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

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonLandingAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80150E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80150E88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80150E8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80150E90: jal         0x800DEE98
    // 0x80150E94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80150E94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150E98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80150E9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80150EA0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80150EA4: lw          $a1, 0x24($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X24);
    // 0x80150EA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80150EAC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80150EB0: jal         0x800E6F24
    // 0x80150EB4: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80150EB4: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    after_1:
    // 0x80150EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80150EBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80150EC0: jr          $ra
    // 0x80150EC4: nop

    return;
    // 0x80150EC4: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036834: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80036838: blez        $a1, L_80036894
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8003683C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80036894;
    }
    // 0x8003683C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80036840: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x80036844: beq         $a3, $zero, L_80036868
    if (ctx->r7 == 0) {
        // 0x80036848: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80036868;
    }
    // 0x80036848: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003684C:
    // 0x8003684C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80036850: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80036854: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80036858: bne         $a0, $a2, L_8003684C
    if (ctx->r4 != ctx->r6) {
        // 0x8003685C: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_8003684C;
    }
    // 0x8003685C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80036860: beql        $a2, $a1, L_80036898
    if (ctx->r6 == ctx->r5) {
        // 0x80036864: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80036898;
    }
    goto skip_0;
    // 0x80036864: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_80036868:
    // 0x80036868: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8003686C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80036870: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x80036874: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80036878: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x8003687C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80036880: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80036884: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80036888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8003688C: bne         $a2, $a1, L_80036868
    if (ctx->r6 != ctx->r5) {
        // 0x80036890: addu        $v1, $v1, $t0
        ctx->r3 = ADD32(ctx->r3, ctx->r8);
            goto L_80036868;
    }
    // 0x80036890: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_80036894:
    // 0x80036894: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80036898:
    // 0x80036898: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8003689C: jr          $ra
    // 0x800368A0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800368A0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void ftPurinSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151504: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015150C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151510: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151514: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80151518: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015151C: jal         0x800E6F24
    // 0x80151520: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151520: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151524: jal         0x80151260
    // 0x80151528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPurinSpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80151528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015152C: jal         0x800E0830
    // 0x80151530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80151530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015153C: jr          $ra
    // 0x80151540: nop

    return;
    // 0x80151540: nop

;}
RECOMP_FUNC void mvOpeningMarioStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E030: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E038: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E03C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E040: addiu       $a0, $a0, -0x1EE4
    ctx->r4 = ADD32(ctx->r4, -0X1EE4);
    // 0x8018E044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E048: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E04C: jal         0x80007024
    // 0x8018E050: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E050: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E054: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E058: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E05C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E060: addiu       $t9, $t9, -0x19E0
    ctx->r25 = ADD32(ctx->r25, -0X19E0);
    // 0x8018E064: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E068: addiu       $a0, $a0, -0x1EC8
    ctx->r4 = ADD32(ctx->r4, -0X1EC8);
    // 0x8018E06C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E070: jal         0x8000683C
    // 0x8018E074: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E074: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E080: jr          $ra
    // 0x8018E084: nop

    return;
    // 0x8018E084: nop

;}
RECOMP_FUNC void func_ovl8_80374F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374F8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80374F90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80374F94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80374F98: jal         0x8037C0CC
    // 0x80374F9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_ovl8_8037C0CC(rdram, ctx);
        goto after_0;
    // 0x80374F9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80374FA0: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80374FA4: sh          $t6, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = ctx->r14;
    // 0x80374FA8: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80374FAC: sh          $t7, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = ctx->r15;
    // 0x80374FB0: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x80374FB4: sh          $t8, 0x60($v0)
    MEM_H(0X60, ctx->r2) = ctx->r24;
    // 0x80374FB8: lhu         $t9, 0x26($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X26);
    // 0x80374FBC: sh          $t9, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r25;
    // 0x80374FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374FC8: jr          $ra
    // 0x80374FCC: nop

    return;
    // 0x80374FCC: nop

;}
RECOMP_FUNC void ftLinkSpecialLwCheckGotoItemThrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016452C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164530: lw          $v1, 0x84C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84C);
    // 0x80164534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80164538: beq         $v1, $zero, L_8016457C
    if (ctx->r3 == 0) {
        // 0x8016453C: nop
    
            goto L_8016457C;
    }
    // 0x8016453C: nop

    // 0x80164540: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80164544: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80164548: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8016454C: bne         $t6, $at, L_80164574
    if (ctx->r14 != ctx->r1) {
        // 0x80164550: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80164574;
    }
    // 0x80164550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80164554: bne         $a1, $at, L_8016456C
    if (ctx->r5 != ctx->r1) {
        // 0x80164558: nop
    
            goto L_8016456C;
    }
    // 0x80164558: nop

    // 0x8016455C: jal         0x80146690
    // 0x80164560: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164560: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_0:
    // 0x80164564: b           L_8016457C
    // 0x80164568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016457C;
    // 0x80164568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016456C:
    // 0x8016456C: jal         0x80146690
    // 0x80164570: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80164570: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    after_1:
L_80164574:
    // 0x80164574: b           L_8016457C
    // 0x80164578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016457C;
    // 0x80164578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016457C:
    // 0x8016457C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164584: jr          $ra
    // 0x80164588: nop

    return;
    // 0x80164588: nop

;}
RECOMP_FUNC void ftBossCommonGotoTargetEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801580E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801580E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801580E8: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x801580EC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801580F0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x801580F4: lw          $a2, 0xADC($a3)
    ctx->r6 = MEM_W(ctx->r7, 0XADC);
    // 0x801580F8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801580FC: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x80158100: lw          $v0, 0xEC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XEC);
    // 0x80158104: beql        $t0, $v0, L_80158120
    if (ctx->r8 == ctx->r2) {
        // 0x80158108: lw          $v1, 0xEC($a3)
        ctx->r3 = MEM_W(ctx->r7, 0XEC);
            goto L_80158120;
    }
    goto skip_0;
    // 0x80158108: lw          $v1, 0xEC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XEC);
    skip_0:
    // 0x8015810C: beql        $v0, $at, L_80158120
    if (ctx->r2 == ctx->r1) {
        // 0x80158110: lw          $v1, 0xEC($a3)
        ctx->r3 = MEM_W(ctx->r7, 0XEC);
            goto L_80158120;
    }
    goto skip_1;
    // 0x80158110: lw          $v1, 0xEC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XEC);
    skip_1:
    // 0x80158114: b           L_80158144
    // 0x80158118: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
        goto L_80158144;
    // 0x80158118: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8015811C: lw          $v1, 0xEC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XEC);
L_80158120:
    // 0x80158120: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80158124: beql        $t0, $v1, L_80158140
    if (ctx->r8 == ctx->r3) {
        // 0x80158128: lw          $t7, 0x8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X8);
            goto L_80158140;
    }
    goto skip_2;
    // 0x80158128: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    skip_2:
    // 0x8015812C: beql        $v0, $at, L_80158140
    if (ctx->r2 == ctx->r1) {
        // 0x80158130: lw          $t7, 0x8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X8);
            goto L_80158140;
    }
    goto skip_3;
    // 0x80158130: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    skip_3:
    // 0x80158134: b           L_80158144
    // 0x80158138: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
        goto L_80158144;
    // 0x80158138: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8015813C: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
L_80158140:
    // 0x80158140: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80158144:
    // 0x80158144: lw          $t8, 0xADC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XADC);
    // 0x80158148: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x8015814C: jal         0x80158094
    // 0x80158150: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftBossCommonRandEdgeLR(rdram, ctx);
        goto after_0;
    // 0x80158150: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80158154: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80158158: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8015815C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80158160: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80158164: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80158168: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x8015816C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80158170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80158174: jr          $ra
    // 0x80158178: nop

    return;
    // 0x80158178: nop

;}
RECOMP_FUNC void ftNessSpecialHiJibakuProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801547B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801547BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801547C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801547C4: lw          $t6, 0xB28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB28);
    // 0x801547C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801547CC: bne         $t7, $zero, L_801547DC
    if (ctx->r15 != 0) {
        // 0x801547D0: sw          $t7, 0xB28($v0)
        MEM_W(0XB28, ctx->r2) = ctx->r15;
            goto L_801547DC;
    }
    // 0x801547D0: sw          $t7, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->r15;
    // 0x801547D4: jal         0x80154518
    // 0x801547D8: nop

    ftNessSpecialHiEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x801547D8: nop

    after_0:
L_801547DC:
    // 0x801547DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801547E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801547E4: jr          $ra
    // 0x801547E8: nop

    return;
    // 0x801547E8: nop

;}
RECOMP_FUNC void itTomatoFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017452C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80174530: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174534: addiu       $a3, $a3, 0x4554
    ctx->r7 = ADD32(ctx->r7, 0X4554);
    // 0x80174538: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8017453C: jal         0x80173B24
    // 0x80174540: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174540: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017454C: jr          $ra
    // 0x80174550: nop

    return;
    // 0x80174550: nop

;}
RECOMP_FUNC void mpProcessGetLastWallCollideStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D95E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D95E4: lwc1        $f4, 0xDFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDFC);
    // 0x800D95E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D95EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D95F0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800D95F4: lw          $t6, 0xE00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE00);
    // 0x800D95F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D95FC: addiu       $t8, $t8, 0xE08
    ctx->r24 = ADD32(ctx->r24, 0XE08);
    // 0x800D9600: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D9604: lw          $t7, 0xE04($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE04);
    // 0x800D9608: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D960C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800D9610: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x800D9614: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800D9618: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800D961C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800D9620: jr          $ra
    // 0x800D9624: sw          $t0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r8;
    return;
    // 0x800D9624: sw          $t0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_ovl8_80377108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377108: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8037710C: beq         $a2, $zero, L_8037712C
    if (ctx->r6 == 0) {
        // 0x80377110: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8037712C;
    }
    // 0x80377110: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80377114:
    // 0x80377114: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80377118: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8037711C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80377120: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80377124: bne         $a2, $zero, L_80377114
    if (ctx->r6 != 0) {
        // 0x80377128: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80377114;
    }
    // 0x80377128: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8037712C:
    // 0x8037712C: jr          $ra
    // 0x80377130: nop

    return;
    // 0x80377130: nop

;}
RECOMP_FUNC void grHyruleTwisterInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A9C8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010A9CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010A9D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010A9D4: jal         0x800FC7A4
    // 0x8010A9D8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_0;
    // 0x8010A9D8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x8010A9DC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010A9E0: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x8010A9E4: sb          $v0, 0x29($t0)
    MEM_B(0X29, ctx->r8) = ctx->r2;
    // 0x8010A9E8: beq         $v0, $zero, L_8010A9FC
    if (ctx->r2 == 0) {
        // 0x8010A9EC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010A9FC;
    }
    // 0x8010A9EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010A9F0: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8010A9F4: bne         $at, $zero, L_8010AA1C
    if (ctx->r1 != 0) {
        // 0x8010A9F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010AA1C;
    }
    // 0x8010A9F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8010A9FC:
    // 0x8010A9FC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010AA00: addiu       $s0, $s0, 0xB70
    ctx->r16 = ADD32(ctx->r16, 0XB70);
L_8010AA04:
    // 0x8010AA04: jal         0x80023624
    // 0x8010AA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8010AA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010AA0C: jal         0x800A3040
    // 0x8010AA10: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x8010AA10: nop

    after_2:
    // 0x8010AA14: b           L_8010AA04
    // 0x8010AA18: nop

        goto L_8010AA04;
    // 0x8010AA18: nop

L_8010AA1C:
    // 0x8010AA1C: jal         0x80004980
    // 0x8010AA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syTaskmanMalloc(rdram, ctx);
        goto after_3;
    // 0x8010AA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8010AA24: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010AA28: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x8010AA2C: sw          $v0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r2;
    // 0x8010AA30: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x8010AA34: jal         0x800FC814
    // 0x8010AA38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_4;
    // 0x8010AA38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x8010AA3C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010AA40: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x8010AA44: blez        $s0, L_8010AADC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8010AA48: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8010AADC;
    }
    // 0x8010AA48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010AA4C: andi        $a1, $s0, 0x3
    ctx->r5 = ctx->r16 & 0X3;
    // 0x8010AA50: beq         $a1, $zero, L_8010AA84
    if (ctx->r5 == 0) {
        // 0x8010AA54: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8010AA84;
    }
    // 0x8010AA54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010AA58: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8010AA5C: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8010AA60: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8010AA64:
    // 0x8010AA64: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x8010AA68: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8010AA6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8010AA70: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8010AA74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8010AA78: bne         $a0, $v1, L_8010AA64
    if (ctx->r4 != ctx->r3) {
        // 0x8010AA7C: sb          $t8, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r24;
            goto L_8010AA64;
    }
    // 0x8010AA7C: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x8010AA80: beq         $v1, $s0, L_8010AADC
    if (ctx->r3 == ctx->r16) {
        // 0x8010AA84: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8010AADC;
    }
L_8010AA84:
    // 0x8010AA84: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8010AA88: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x8010AA8C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
L_8010AA90:
    // 0x8010AA90: lw          $t5, 0x18($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X18);
    // 0x8010AA94: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8010AA98: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8010AA9C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8010AAA0: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8010AAA4: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x8010AAA8: lw          $t7, -0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, -0XC);
    // 0x8010AAAC: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8010AAB0: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x8010AAB4: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x8010AAB8: lw          $t1, -0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, -0X8);
    // 0x8010AABC: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8010AAC0: sb          $t1, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r9;
    // 0x8010AAC4: lw          $t4, 0x18($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X18);
    // 0x8010AAC8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8010AACC: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x8010AAD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8010AAD4: bne         $v1, $s0, L_8010AA90
    if (ctx->r3 != ctx->r16) {
        // 0x8010AAD8: sb          $t5, 0x3($t6)
        MEM_B(0X3, ctx->r14) = ctx->r13;
            goto L_8010AA90;
    }
    // 0x8010AAD8: sb          $t5, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r13;
L_8010AADC:
    // 0x8010AADC: lui         $a0, 0xB2
    ctx->r4 = S32(0XB2 << 16);
    // 0x8010AAE0: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x8010AAE4: lui         $a2, 0xB2
    ctx->r6 = S32(0XB2 << 16);
    // 0x8010AAE8: lui         $a3, 0xB2
    ctx->r7 = S32(0XB2 << 16);
    // 0x8010AAEC: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
    // 0x8010AAF0: addiu       $a3, $a3, 0x2980
    ctx->r7 = ADD32(ctx->r7, 0X2980);
    // 0x8010AAF4: addiu       $a2, $a2, -0x380
    ctx->r6 = ADD32(ctx->r6, -0X380);
    // 0x8010AAF8: addiu       $a1, $a1, -0x380
    ctx->r5 = ADD32(ctx->r5, -0X380);
    // 0x8010AAFC: jal         0x801159F8
    // 0x8010AB00: addiu       $a0, $a0, -0x6A0
    ctx->r4 = ADD32(ctx->r4, -0X6A0);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_5;
    // 0x8010AB00: addiu       $a0, $a0, -0x6A0
    ctx->r4 = ADD32(ctx->r4, -0X6A0);
    after_5:
    // 0x8010AB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AB08: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010AB0C: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x8010AB10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010AB14: sw          $v0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r2;
    // 0x8010AB18: jr          $ra
    // 0x8010AB1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010AB1C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mvOpeningLinkPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D970: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D974: lw          $v1, -0x1E38($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1E38);
    // 0x8018D978: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D97C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D980: beq         $v1, $at, L_8018D9A8
    if (ctx->r3 == ctx->r1) {
        // 0x8018D984: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9A8;
    }
    // 0x8018D984: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D988: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D98C: beq         $v0, $at, L_8018D9BC
    if (ctx->r2 == ctx->r1) {
        // 0x8018D990: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9BC;
    }
    // 0x8018D990: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D994: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D998: beq         $v0, $at, L_8018D9D0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D99C: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9D0;
    }
    // 0x8018D99C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9A0: b           L_8018D9E0
    // 0x8018D9A4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
        goto L_8018D9E0;
    // 0x8018D9A4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
L_8018D9A8:
    // 0x8018D9A8: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9B0: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9B4: b           L_8018D9E0
    // 0x8018D9B8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018D9E0;
    // 0x8018D9B8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018D9BC:
    // 0x8018D9BC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D9C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D9C4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9C8: b           L_8018D9E0
    // 0x8018D9CC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018D9E0;
    // 0x8018D9CC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018D9D0:
    // 0x8018D9D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D9D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9D8: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9DC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018D9E0:
    // 0x8018D9E0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018D9E4: bne         $at, $zero, L_8018DA04
    if (ctx->r1 != 0) {
        // 0x8018D9E8: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA04;
    }
    // 0x8018D9E8: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018D9EC: beq         $at, $zero, L_8018DA04
    if (ctx->r1 == 0) {
        // 0x8018D9F0: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA04;
    }
    // 0x8018D9F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D9F4: lwc1        $f16, -0x1E50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E50);
    // 0x8018D9F8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018D9FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA00: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA04:
    // 0x8018DA04: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA08: bne         $at, $zero, L_8018DA28
    if (ctx->r1 != 0) {
        // 0x8018DA0C: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA28;
    }
    // 0x8018DA0C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA10: beq         $at, $zero, L_8018DA28
    if (ctx->r1 == 0) {
        // 0x8018DA14: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA28;
    }
    // 0x8018DA14: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA1C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA24: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA28:
    // 0x8018DA28: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA2C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA30: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8018DA34: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018DA38: jr          $ra
    // 0x8018DA3C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA3C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mvEndingSetupOperatorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132590: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132594: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132598: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013259C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801325A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801325A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801325A8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801325AC: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x801325B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801325B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801325BC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801325C0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801325C4: jal         0x80007080
    // 0x801325C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x801325C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801325CC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801325D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801325D4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x801325D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801325DC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801325E0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x801325E4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x801325E8: lw          $t7, 0x2F74($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2F74);
    // 0x801325EC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801325F0: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x801325F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801325F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801325FC: jal         0x8000FA3C
    // 0x80132600: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80132600: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80132604: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132608: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8013260C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80132610: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132614: jal         0x80008188
    // 0x80132618: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132618: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8013261C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132620: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132624: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132628: jr          $ra
    // 0x8013262C: nop

    return;
    // 0x8013262C: nop

;}
RECOMP_FUNC void mvOpeningPortraitsMakeSet2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CAC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80131CB0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131CB4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80131CB8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80131CBC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80131CC0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80131CC4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80131CC8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80131CCC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80131CD0: addiu       $t7, $t7, 0x2908
    ctx->r15 = ADD32(ctx->r15, 0X2908);
    // 0x80131CD4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131CD8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131CDC: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x80131CE0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131CE4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131CE8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131CEC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131CF0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131CF4: addiu       $t1, $t1, 0x2918
    ctx->r9 = ADD32(ctx->r9, 0X2918);
    // 0x80131CF8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131CFC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131D00: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80131D04: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131D08: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x80131D0C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80131D10: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131D14: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80131D18: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80131D1C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80131D20: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80131D24: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80131D28: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80131D2C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80131D30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80131D34: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80131D38: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80131D3C: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80131D40: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80131D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D4C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131D50: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80131D54: jal         0x80009968
    // 0x80131D58: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D58: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    after_0:
    // 0x80131D5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D60: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D64: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80131D68: sw          $v0, 0x29F0($at)
    MEM_W(0X29F0, ctx->r1) = ctx->r2;
    // 0x80131D6C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80131D70: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80131D74: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D7C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131D80: jal         0x80009DF4
    // 0x80131D84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80131D88: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80131D8C: addiu       $s3, $s3, 0x2BB0
    ctx->r19 = ADD32(ctx->r19, 0X2BB0);
    // 0x80131D90: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x80131D94: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80131D98: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80131D9C: addiu       $s4, $zero, -0x21
    ctx->r20 = ADD32(0, -0X21);
L_80131DA0:
    // 0x80131DA0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80131DA4: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x80131DA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80131DAC: jal         0x800CCFDC
    // 0x80131DB0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DB0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80131DB4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80131DB8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80131DBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80131DC0: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x80131DC4: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131DC8: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
    // 0x80131DCC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131DD0: lwc1        $f6, -0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X4);
    // 0x80131DD4: bne         $s0, $s5, L_80131DA0
    if (ctx->r16 != ctx->r21) {
        // 0x80131DD8: swc1        $f6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
            goto L_80131DA0;
    }
    // 0x80131DD8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131DDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80131DE0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DE4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80131DE8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80131DEC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80131DF0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80131DF4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80131DF8: jr          $ra
    // 0x80131DFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80131DFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftBossOkuhikouki3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801597A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801597A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801597AC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801597B0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801597B4: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x801597B8: sw          $t6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r14;
    // 0x801597BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801597C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801597C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801597C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801597CC: jal         0x800E6F24
    // 0x801597D0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801597D0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x801597D4: jal         0x800E0830
    // 0x801597D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801597D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801597DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801597E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801597E4: lwc1        $f6, -0x3820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3820);
    // 0x801597E8: lwc1        $f4, 0xB18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x801597EC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801597F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801597F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801597F8: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x801597FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159800: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80159804: lwc1        $f16, -0x381C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X381C);
    // 0x80159808: lwc1        $f10, 0xB1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB1C);
    // 0x8015980C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80159810: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80159814: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80159818: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8015981C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159824: jr          $ra
    // 0x80159828: nop

    return;
    // 0x80159828: nop

;}
RECOMP_FUNC void mnPlayers1PGameMovePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801370EC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801370F0: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x801370F4: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x801370F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801370FC: lwc1        $f6, 0x60($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137100: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80137104: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80137108: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013710C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80137110: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80137114: lwc1        $f16, 0x64($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80137118: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x8013711C: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80137120: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80137124: jr          $ra
    // 0x80137128: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x80137128: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void sc1PTrainingModeMakeViewOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F4EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F4F4: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018F4F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F4FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018F500: jal         0x80009968
    // 0x8018F504: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018F504: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018F508: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F50C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018F510: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018F514: sw          $v0, 0xBBC($at)
    MEM_W(0XBBC, ctx->r1) = ctx->r2;
    // 0x8018F518: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018F51C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F520: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018F524: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F528: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018F52C: jal         0x80009DF4
    // 0x8018F530: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018F530: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018F534: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F538: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F53C: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x8018F540: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8018F544: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F548: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F54C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F550: jal         0x800CCFDC
    // 0x8018F554: lw          $a1, 0x68($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X68);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018F554: lw          $a1, 0x68($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X68);
    after_2:
    // 0x8018F558: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8018F55C: addiu       $t3, $zero, 0xBF
    ctx->r11 = ADD32(0, 0XBF);
    // 0x8018F560: addiu       $t5, $zero, 0x4A
    ctx->r13 = ADD32(0, 0X4A);
    // 0x8018F564: bgez        $t1, L_8018F574
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018F568: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8018F574;
    }
    // 0x8018F568: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8018F56C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8018F570: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8018F574:
    // 0x8018F574: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8018F578: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F57C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x8018F580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F584: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F588: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8018F58C: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x8018F590: sb          $t5, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r13;
    // 0x8018F594: sb          $t6, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r14;
    // 0x8018F598: sb          $t8, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r24;
    // 0x8018F59C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F5A0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F5A4: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8018F5A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F5AC: addiu       $a1, $a1, -0xB4C
    ctx->r5 = ADD32(ctx->r5, -0XB4C);
    // 0x8018F5B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F5B4: jal         0x80008188
    // 0x8018F5B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018F5B8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_3:
    // 0x8018F5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F5C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F5C4: jr          $ra
    // 0x8018F5C8: nop

    return;
    // 0x8018F5C8: nop

;}
RECOMP_FUNC void mvOpeningRoomFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void ftCommonSpecialNCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015109C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801510A0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801510A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801510A8: lhu         $t6, 0x1BE($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1BE);
    // 0x801510AC: lhu         $t7, 0x1B6($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1B6);
    // 0x801510B0: lw          $v0, 0x9C8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X9C8);
    // 0x801510B4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801510B8: beql        $t8, $zero, L_80151148
    if (ctx->r24 == 0) {
        // 0x801510BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80151148;
    }
    goto skip_0;
    // 0x801510BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801510C0: lw          $t9, 0x100($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X100);
    // 0x801510C4: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x801510C8: bgezl       $t1, L_80151148
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801510CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80151148;
    }
    goto skip_1;
    // 0x801510CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801510D0: lb          $v0, 0x1C3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C3);
    // 0x801510D4: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x801510D8: beq         $at, $zero, L_80151144
    if (ctx->r1 == 0) {
        // 0x801510DC: slti        $at, $v0, -0x27
        ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
            goto L_80151144;
    }
    // 0x801510DC: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    // 0x801510E0: bnel        $at, $zero, L_80151148
    if (ctx->r1 != 0) {
        // 0x801510E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80151148;
    }
    goto skip_2;
    // 0x801510E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801510E8: lb          $t2, 0x1C2($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1C2);
    // 0x801510EC: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x801510F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801510F4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801510F8: mflo        $t4
    ctx->r12 = lo;
    // 0x801510FC: slti        $at, $t4, -0x14
    ctx->r1 = SIGNED(ctx->r12) < -0X14 ? 1 : 0;
    // 0x80151100: beql        $at, $zero, L_80151120
    if (ctx->r1 == 0) {
        // 0x80151104: lw          $t5, 0x8($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X8);
            goto L_80151120;
    }
    goto skip_3;
    // 0x80151104: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    skip_3:
    // 0x80151108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8015110C: jal         0x800E8044
    // 0x80151110: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamSetStickLR(rdram, ctx);
        goto after_0;
    // 0x80151110: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80151114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80151118: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8015111C: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
L_80151120:
    // 0x80151120: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80151124: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80151128: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8015112C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80151130: lw          $t9, -0x7394($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7394);
    // 0x80151134: jalr        $t9
    // 0x80151138: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80151138: nop

    after_1:
    // 0x8015113C: b           L_80151148
    // 0x80151140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80151148;
    // 0x80151140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151144:
    // 0x80151144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80151148:
    // 0x80151148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015114C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151150: jr          $ra
    // 0x80151154: nop

    return;
    // 0x80151154: nop

;}
RECOMP_FUNC void syRdpSetFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007168: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000716C: jr          $ra
    // 0x80007170: sw          $a0, -0x48B0($at)
    MEM_W(-0X48B0, ctx->r1) = ctx->r4;
    return;
    // 0x80007170: sw          $a0, -0x48B0($at)
    MEM_W(-0X48B0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void ftCommonFireFlowerShootInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80147828: sw          $zero, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = 0;
    // 0x8014782C: sw          $v0, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = ctx->r2;
    // 0x80147830: sw          $v0, 0xB20($a0)
    MEM_W(0XB20, ctx->r4) = ctx->r2;
    // 0x80147834: sw          $zero, 0xB24($a0)
    MEM_W(0XB24, ctx->r4) = 0;
    // 0x80147838: sw          $zero, 0xB28($a0)
    MEM_W(0XB28, ctx->r4) = 0;
    // 0x8014783C: jr          $ra
    // 0x80147840: sw          $zero, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = 0;
    return;
    // 0x80147840: sw          $zero, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = 0;
;}
RECOMP_FUNC void ftDonkeySpecialNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AF94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AF9C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AFA0: jal         0x800DDE84
    // 0x8015AFA4: addiu       $a1, $a1, -0x4FD0
    ctx->r5 = ADD32(ctx->r5, -0X4FD0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015AFA4: addiu       $a1, $a1, -0x4FD0
    ctx->r5 = ADD32(ctx->r5, -0X4FD0);
    after_0:
    // 0x8015AFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AFAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AFB0: jr          $ra
    // 0x8015AFB4: nop

    return;
    // 0x8015AFB4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingInitPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013784C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137850: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137854: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80137858: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013785C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137860: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80137864: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80137868: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8013786C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80137870: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80137874: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80137878: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x8013787C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80137880: sw          $zero, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = 0;
    // 0x80137884: sh          $zero, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = 0;
    // 0x80137888: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8013788C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137890: lw          $t8, -0x776C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X776C);
    // 0x80137894: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80137898: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013789C: bne         $a0, $t8, L_801378D8
    if (ctx->r4 != ctx->r24) {
        // 0x801378A0: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_801378D8;
    }
    // 0x801378A0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801378A4: lbu         $t1, 0x3B($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3B);
    // 0x801378A8: lbu         $t2, 0x3C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3C);
    // 0x801378AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801378B0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801378B4: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x801378B8: sw          $t9, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r25;
    // 0x801378BC: sw          $t0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r8;
    // 0x801378C0: sw          $a0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r4;
    // 0x801378C4: sw          $a0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r4;
    // 0x801378C8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x801378CC: sw          $t1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r9;
    // 0x801378D0: jr          $ra
    // 0x801378D4: sw          $t2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r10;
    return;
    // 0x801378D4: sw          $t2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r10;
L_801378D8:
    // 0x801378D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801378DC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801378E0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801378E4: sw          $t3, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r11;
    // 0x801378E8: sw          $t4, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r12;
    // 0x801378EC: sw          $a0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r4;
    // 0x801378F0: sw          $a0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r4;
    // 0x801378F4: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x801378F8: jr          $ra
    // 0x801378FC: nop

    return;
    // 0x801378FC: nop

;}
RECOMP_FUNC void func_ovl8_80380C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380C30: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80380C34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80380C38: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80380C3C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80380C40: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80380C44: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80380C48: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80380C4C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80380C50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80380C54: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80380C58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80380C5C: lw          $s3, 0xB4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0XB4);
    // 0x80380C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380C64: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80380C68: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x80380C6C: beq         $a1, $zero, L_80380C84
    if (ctx->r5 == 0) {
        // 0x80380C70: nop
    
            goto L_80380C84;
    }
    // 0x80380C70: nop

    // 0x80380C74: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80380C78: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x80380C7C: jal         0x800343E0
    // 0x80380C80: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80380C80: lw          $a0, 0x20($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20);
    after_0:
L_80380C84:
    // 0x80380C84: beq         $s0, $zero, L_80380C90
    if (ctx->r16 == 0) {
        // 0x80380C88: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80380C90;
    }
    // 0x80380C88: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380C8C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80380C90:
    // 0x80380C90: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80380C94: addiu       $fp, $zero, 0x6
    ctx->r30 = ADD32(0, 0X6);
    // 0x80380C98: bnel        $fp, $t7, L_80380CC0
    if (ctx->r30 != ctx->r15) {
        // 0x80380C9C: lw          $t0, 0xB0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XB0);
            goto L_80380CC0;
    }
    goto skip_0;
    // 0x80380C9C: lw          $t0, 0xB0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB0);
    skip_0:
    // 0x80380CA0: lh          $t8, 0x2($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2);
    // 0x80380CA4: lw          $t9, 0xBC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XBC);
    // 0x80380CA8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380CAC: mflo        $a0
    ctx->r4 = lo;
    // 0x80380CB0: jal         0x803716D8
    // 0x80380CB4: nop

    func_ovl8_803716D8(rdram, ctx);
        goto after_1;
    // 0x80380CB4: nop

    after_1:
    // 0x80380CB8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80380CBC: lw          $t0, 0xB0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB0);
L_80380CC0:
    // 0x80380CC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80380CC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80380CC8: blez        $t0, L_80380D98
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80380CCC: addiu       $s7, $sp, 0x4C
        ctx->r23 = ADD32(ctx->r29, 0X4C);
            goto L_80380D98;
    }
    // 0x80380CCC: addiu       $s7, $sp, 0x4C
    ctx->r23 = ADD32(ctx->r29, 0X4C);
    // 0x80380CD0: addiu       $s6, $sp, 0x5C
    ctx->r22 = ADD32(ctx->r29, 0X5C);
    // 0x80380CD4: addiu       $s5, $sp, 0x60
    ctx->r21 = ADD32(ctx->r29, 0X60);
    // 0x80380CD8: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
L_80380CDC:
    // 0x80380CDC: lw          $t1, 0xBC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XBC);
    // 0x80380CE0: addiu       $t3, $s2, 0x1
    ctx->r11 = ADD32(ctx->r18, 0X1);
    // 0x80380CE4: multu       $s2, $t1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380CE8: mflo        $t2
    ctx->r10 = lo;
    // 0x80380CEC: sh          $t2, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r10;
    // 0x80380CF0: lw          $t4, 0xAC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XAC);
    // 0x80380CF4: bnel        $t3, $t4, L_80380D10
    if (ctx->r11 != ctx->r12) {
        // 0x80380CF8: lw          $t7, 0xC($s3)
        ctx->r15 = MEM_W(ctx->r19, 0XC);
            goto L_80380D10;
    }
    goto skip_1;
    // 0x80380CF8: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    skip_1:
    // 0x80380CFC: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x80380D00: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80380D04: b           L_80380D18
    // 0x80380D08: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
        goto L_80380D18;
    // 0x80380D08: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80380D0C: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
L_80380D10:
    // 0x80380D10: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80380D14: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
L_80380D18:
    // 0x80380D18: beq         $v0, $zero, L_80380D80
    if (ctx->r2 == 0) {
        // 0x80380D1C: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80380D80;
    }
    // 0x80380D1C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80380D20: beq         $s0, $zero, L_80380D2C
    if (ctx->r16 == 0) {
        // 0x80380D24: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80380D2C;
    }
    // 0x80380D24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380D28: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80380D2C:
    // 0x80380D2C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80380D30: bnel        $fp, $t9, L_80380D64
    if (ctx->r30 != ctx->r25) {
        // 0x80380D34: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_80380D64;
    }
    goto skip_2;
    // 0x80380D34: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_2:
    // 0x80380D38: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80380D3C: lw          $t1, 0xBC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XBC);
    // 0x80380D40: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    // 0x80380D44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80380D48: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80380D4C: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380D50: mflo        $a2
    ctx->r6 = lo;
    // 0x80380D54: jal         0x8037C1D4
    // 0x80380D58: nop

    func_ovl8_8037C1D4(rdram, ctx);
        goto after_2;
    // 0x80380D58: nop

    after_2:
    // 0x80380D5C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80380D60: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_80380D64:
    // 0x80380D64: lw          $a2, 0xB8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB8);
    // 0x80380D68: lw          $a3, 0xBC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XBC);
    // 0x80380D6C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80380D70: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80380D74: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80380D78: jal         0x803798A0
    // 0x80380D7C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_ovl8_803798A0(rdram, ctx);
        goto after_3;
    // 0x80380D7C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_3:
L_80380D80:
    // 0x80380D80: lw          $t3, 0xB0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XB0);
    // 0x80380D84: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80380D88: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80380D8C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80380D90: bnel        $at, $zero, L_80380CDC
    if (ctx->r1 != 0) {
        // 0x80380D94: sh          $zero, 0x4C($sp)
        MEM_H(0X4C, ctx->r29) = 0;
            goto L_80380CDC;
    }
    goto skip_3;
    // 0x80380D94: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    skip_3:
L_80380D98:
    // 0x80380D98: beql        $s4, $zero, L_80380DAC
    if (ctx->r20 == 0) {
        // 0x80380D9C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80380DAC;
    }
    goto skip_4;
    // 0x80380D9C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80380DA0: jal         0x80371764
    // 0x80380DA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_ovl8_80371764(rdram, ctx);
        goto after_4;
    // 0x80380DA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80380DA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80380DAC:
    // 0x80380DAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80380DB0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80380DB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80380DB8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80380DBC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80380DC0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80380DC4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80380DC8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80380DCC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80380DD0: jr          $ra
    // 0x80380DD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80380DD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ftKirbyCopyNessSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155B40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80155B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155B48: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80155B4C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155B50: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x80155B54: beql        $t7, $zero, L_80155CA0
    if (ctx->r15 == 0) {
        // 0x80155B58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80155CA0;
    }
    goto skip_0;
    // 0x80155B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80155B5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80155B60: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80155B64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80155B68: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80155B6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80155B70: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80155B74: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x80155B78: jal         0x800EDF24
    // 0x80155B7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80155B7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80155B80: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80155B84: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80155B88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80155B8C: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80155B90: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80155B94: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80155B98: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80155B9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80155BA0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80155BA4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80155BA8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80155BAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80155BB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80155BB4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80155BB8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80155BBC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80155BC0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80155BC4: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x80155BC8: bne         $t9, $at, L_80155C2C
    if (ctx->r25 != ctx->r1) {
        // 0x80155BCC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80155C2C;
    }
    // 0x80155BCC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155BD0: lwc1        $f12, -0x39E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X39E0);
    // 0x80155BD4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80155BD8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80155BDC: jal         0x80035CD0
    // 0x80155BE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80155BE0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80155BE4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80155BE8: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80155BEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80155BF0: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x80155BF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155BF8: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80155BFC: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80155C00: lwc1        $f12, -0x39DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X39DC);
    // 0x80155C04: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80155C08: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80155C0C: jal         0x800303F0
    // 0x80155C10: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80155C10: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80155C14: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80155C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80155C1C: nop

    // 0x80155C20: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80155C24: b           L_80155C88
    // 0x80155C28: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
        goto L_80155C88;
    // 0x80155C28: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
L_80155C2C:
    // 0x80155C2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155C30: lwc1        $f12, -0x39D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X39D8);
    // 0x80155C34: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80155C38: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80155C3C: jal         0x80035CD0
    // 0x80155C40: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80155C40: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80155C44: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80155C48: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x80155C4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80155C50: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x80155C54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155C58: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80155C5C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80155C60: lwc1        $f12, -0x39D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X39D4);
    // 0x80155C64: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80155C68: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80155C6C: jal         0x800303F0
    // 0x80155C70: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80155C70: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80155C74: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x80155C78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80155C7C: nop

    // 0x80155C80: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80155C84: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_80155C88:
    // 0x80155C88: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80155C8C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80155C90: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80155C94: jal         0x8016AC78
    // 0x80155C98: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    wpNessPKFireMakeWeapon(rdram, ctx);
        goto after_5;
    // 0x80155C98: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80155C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155CA0:
    // 0x80155CA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80155CA4: jr          $ra
    // 0x80155CA8: nop

    return;
    // 0x80155CA8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCenterPuckInPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135CD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80135CD8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80135CDC: jal         0x80132020
    // 0x80135CE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PTrainingGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80135CE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80135CE4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80135CE8: bne         $at, $zero, L_80135D30
    if (ctx->r1 != 0) {
        // 0x80135CEC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80135D30;
    }
    // 0x80135CEC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80135CF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80135CF4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80135CF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80135CFC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80135D00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80135D04: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80135D08: addiu       $t7, $t6, -0xEA
    ctx->r15 = ADD32(ctx->r14, -0XEA);
    // 0x80135D0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80135D10: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80135D14: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x80135D18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135D1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135D20: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80135D24: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x80135D28: b           L_80135D6C
    // 0x80135D2C: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
        goto L_80135D6C;
    // 0x80135D2C: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
L_80135D30:
    // 0x80135D30: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80135D34: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80135D38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135D3C: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80135D40: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135D44: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80135D48: addiu       $t1, $t0, 0x24
    ctx->r9 = ADD32(ctx->r8, 0X24);
    // 0x80135D4C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80135D50: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80135D54: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80135D58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80135D5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135D60: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x80135D64: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x80135D68: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_80135D6C:
    // 0x80135D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135D74: jr          $ra
    // 0x80135D78: nop

    return;
    // 0x80135D78: nop

;}
RECOMP_FUNC void mnCharactersMakeWorks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013239C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801323A0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801323A4: addiu       $t7, $t7, 0x6400
    ctx->r15 = ADD32(ctx->r15, 0X6400);
    // 0x801323A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801323AC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801323B0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x801323B4: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
L_801323B8:
    // 0x801323B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801323BC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801323C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801323C4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801323C8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801323CC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801323D0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801323D4: bne         $t7, $t0, L_801323B8
    if (ctx->r15 != ctx->r8) {
        // 0x801323D8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801323B8;
    }
    // 0x801323D8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801323DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323E4: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x801323E8: jal         0x80009968
    // 0x801323EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801323EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801323F8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801323FC: sw          $v0, 0x6608($at)
    MEM_W(0X6608, ctx->r1) = ctx->r2;
    // 0x80132400: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80132404: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132408: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013240C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132410: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80132414: jal         0x80009DF4
    // 0x80132418: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132418: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013241C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80132420: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132424: lw          $t5, 0x6A78($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A78);
    // 0x80132428: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8013242C: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80132430: lw          $t4, 0x20($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X20);
    // 0x80132434: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80132438: jal         0x800CCFDC
    // 0x8013243C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013243C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80132440: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132444: lui         $at, 0x430B
    ctx->r1 = S32(0X430B << 16);
    // 0x80132448: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013244C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80132450: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132454: andi        $t6, $t0, 0xFFDF
    ctx->r14 = ctx->r8 & 0XFFDF;
    // 0x80132458: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013245C: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x80132460: addiu       $t9, $zero, 0xBC
    ctx->r25 = ADD32(0, 0XBC);
    // 0x80132464: addiu       $t1, $zero, 0xBF
    ctx->r9 = ADD32(0, 0XBF);
    // 0x80132468: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8013246C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132470: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132474: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80132478: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x8013247C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132480: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132488: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8013248C: jr          $ra
    // 0x80132490: nop

    return;
    // 0x80132490: nop

;}
RECOMP_FUNC void itRShellFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A7F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A7F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A7F8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x8017A7FC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8017A800: lbu         $t6, 0x352($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X352);
    // 0x8017A804: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017A808: bne         $t6, $zero, L_8017A820
    if (ctx->r14 != 0) {
        // 0x8017A80C: nop
    
            goto L_8017A820;
    }
    // 0x8017A80C: nop

    // 0x8017A810: jal         0x80173DF4
    // 0x8017A814: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x8017A814: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_0:
    // 0x8017A818: b           L_8017A830
    // 0x8017A81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017A830;
    // 0x8017A81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017A820:
    // 0x8017A820: jal         0x80173B24
    // 0x8017A824: addiu       $a3, $a3, -0x569C
    ctx->r7 = ADD32(ctx->r7, -0X569C);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x8017A824: addiu       $a3, $a3, -0x569C
    ctx->r7 = ADD32(ctx->r7, -0X569C);
    after_1:
    // 0x8017A828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017A82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017A830:
    // 0x8017A830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A834: jr          $ra
    // 0x8017A838: nop

    return;
    // 0x8017A838: nop

;}
RECOMP_FUNC void lbCommonReflect2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B08: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7B0C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7B10: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7B14: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7B18: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800C7B1C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800C7B20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C7B24: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800C7B28: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C7B2C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800C7B30: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C7B34: nop

    // 0x800C7B38: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C7B3C: add.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x800C7B40: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800C7B44: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7B48: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C7B4C: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800C7B50: jr          $ra
    // 0x800C7B54: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800C7B54: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void sc1PTrainingModeUpdateItemOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D518: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D51C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D520: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D524: addiu       $a0, $a0, 0xB68
    ctx->r4 = ADD32(ctx->r4, 0XB68);
    // 0x8018D528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D52C: jal         0x8018D40C
    // 0x8018D530: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    sc1PTrainingModeCheckUpdateOptionID(rdram, ctx);
        goto after_0;
    // 0x8018D530: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_0:
    // 0x8018D534: beq         $v0, $zero, L_8018D54C
    if (ctx->r2 == 0) {
        // 0x8018D538: nop
    
            goto L_8018D54C;
    }
    // 0x8018D538: nop

    // 0x8018D53C: jal         0x8018F040
    // 0x8018D540: nop

    sc1PTrainingModeUpdateItemOptionSprite(rdram, ctx);
        goto after_1;
    // 0x8018D540: nop

    after_1:
    // 0x8018D544: jal         0x8018D3DC
    // 0x8018D548: nop

    sc1PTrainingModeUpdateScroll(rdram, ctx);
        goto after_2;
    // 0x8018D548: nop

    after_2:
L_8018D54C:
    // 0x8018D54C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D550: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018D554: lbu         $v0, 0xD5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD5);
    // 0x8018D558: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D55C: bne         $v0, $zero, L_8018D66C
    if (ctx->r2 != 0) {
        // 0x8018D560: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8018D66C;
    }
    // 0x8018D560: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8018D564: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x8018D568: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8018D56C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018D570: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018D574: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018D578: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D57C: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x8018D580: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8018D584: beql        $t9, $zero, L_8018D674
    if (ctx->r25 == 0) {
        // 0x8018D588: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018D674;
    }
    goto skip_0;
    // 0x8018D588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8018D58C: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x8018D590: beql        $t0, $zero, L_8018D674
    if (ctx->r8 == 0) {
        // 0x8018D594: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018D674;
    }
    goto skip_1;
    // 0x8018D594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8018D598: jal         0x8018D4D0
    // 0x8018D59C: nop

    sc1PTrainingModeGetItemCount(rdram, ctx);
        goto after_3;
    // 0x8018D59C: nop

    after_3:
    // 0x8018D5A0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8018D5A4: beq         $at, $zero, L_8018D65C
    if (ctx->r1 == 0) {
        // 0x8018D5A8: lui         $t1, 0x800A
        ctx->r9 = S32(0X800A << 16);
            goto L_8018D65C;
    }
    // 0x8018D5A8: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018D5AC: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018D5B0: lbu         $t2, 0x4AE3($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4AE3);
    // 0x8018D5B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D5B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018D5BC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8018D5C0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018D5C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D5C8: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50E8);
    // 0x8018D5CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018D5D0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018D5D4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018D5D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018D5DC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018D5E0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D5E4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8018D5E8: lw          $t5, 0x78($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X78);
    // 0x8018D5EC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8018D5F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018D5F4: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x8018D5F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D5FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D600: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8018D604: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8018D608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D60C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8018D610: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8018D614: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8018D618: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8018D61C: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8018D620: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8018D624: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D628: lw          $a1, 0xB68($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB68);
    // 0x8018D62C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018D630: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018D634: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8018D638: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8018D63C: jal         0x8016EA78
    // 0x8018D640: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_4;
    // 0x8018D640: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8018D644: jal         0x800269C0
    // 0x8018D648: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8018D648: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_5:
    // 0x8018D64C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8018D650: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D654: b           L_8018D670
    // 0x8018D658: sb          $t0, 0xC2D($at)
    MEM_B(0XC2D, ctx->r1) = ctx->r8;
        goto L_8018D670;
    // 0x8018D658: sb          $t0, 0xC2D($at)
    MEM_B(0XC2D, ctx->r1) = ctx->r8;
L_8018D65C:
    // 0x8018D65C: jal         0x800269C0
    // 0x8018D660: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x8018D660: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_6:
    // 0x8018D664: b           L_8018D674
    // 0x8018D668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018D674;
    // 0x8018D668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018D66C:
    // 0x8018D66C: sb          $t2, 0xD5($v1)
    MEM_B(0XD5, ctx->r3) = ctx->r10;
L_8018D670:
    // 0x8018D670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018D674:
    // 0x8018D674: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D67C: jr          $ra
    // 0x8018D680: nop

    return;
    // 0x8018D680: nop

;}
RECOMP_FUNC void ftKirbySpecialNTurnSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162E20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162E28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162E2C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162E30: jal         0x800DEEC8
    // 0x80162E34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162E34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162E38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162E3C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162E40: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // 0x80162E44: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162E48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162E4C: jal         0x800E6F24
    // 0x80162E50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162E50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162E54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162E58: jal         0x800E8098
    // 0x80162E5C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162E5C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162E68: jr          $ra
    // 0x80162E6C: nop

    return;
    // 0x80162E6C: nop

;}
RECOMP_FUNC void ftFoxSpecialLwTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CFC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CFC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CFC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015CFCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CFD0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015CFD4: jal         0x8015CBA4
    // 0x8015CFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015CFD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015CFDC: jal         0x8015CB80
    // 0x8015CFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwCheckSetRelease(rdram, ctx);
        goto after_1;
    // 0x8015CFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015CFE4: jal         0x8015CBD4
    // 0x8015CFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialLwDecReleaseLag(rdram, ctx);
        goto after_2;
    // 0x8015CFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015CFEC: jal         0x8015CF50
    // 0x8015CFF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwTurnDecTurnFrames(rdram, ctx);
        goto after_3;
    // 0x8015CFF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8015CFF4: lw          $t7, 0xB1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB1C);
    // 0x8015CFF8: bgtzl       $t7, L_8015D00C
    if (SIGNED(ctx->r15) > 0) {
        // 0x8015CFFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015D00C;
    }
    goto skip_0;
    // 0x8015CFFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8015D000: jal         0x8015CE08
    // 0x8015D004: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwHitDecideSetStatus(rdram, ctx);
        goto after_4;
    // 0x8015D004: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8015D008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015D00C:
    // 0x8015D00C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015D010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D014: jr          $ra
    // 0x8015D018: nop

    return;
    // 0x8015D018: nop

;}
RECOMP_FUNC void mnPlayers1PGamePortraitAddCross(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132634: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013263C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132640: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132644: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132648: lw          $t6, -0x6950($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6950);
    // 0x8013264C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132650: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132654: addiu       $t7, $t7, 0x2B8
    ctx->r15 = ADD32(ctx->r15, 0X2B8);
    // 0x80132658: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8013265C: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80132660: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80132664: jal         0x800CCFDC
    // 0x80132668: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132668: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8013266C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132670: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132674: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80132678: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8013267C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132680: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132684: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132688: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8013268C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132690: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80132694: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132698: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8013269C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801326A0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801326A4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801326A8: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801326AC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801326B0: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801326B4: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801326B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801326BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801326C0: jr          $ra
    // 0x801326C4: nop

    return;
    // 0x801326C4: nop

;}
RECOMP_FUNC void itBoxContainerSmashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801791F4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801791F8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x801791FC: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80179200: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80179204: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80179208: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8017920C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80179210: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80179214: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80179218: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8017921C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80179220: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80179224: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80179228: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8017922C: jal         0x800FD4B8
    // 0x80179230: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80179230: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80179234: beq         $v0, $zero, L_801793E8
    if (ctx->r2 == 0) {
        // 0x80179238: sw          $v0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r2;
            goto L_801793E8;
    }
    // 0x80179238: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8017923C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80179240: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80179244: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80179248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017924C: jal         0x80009968
    // 0x80179250: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80179250: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80179254: beq         $v0, $zero, L_801793E8
    if (ctx->r2 == 0) {
        // 0x80179258: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_801793E8;
    }
    // 0x80179258: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8017925C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80179260: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80179264: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80179268: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x8017926C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80179270: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80179274: jal         0x80009DF4
    // 0x80179278: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80179278: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x8017927C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80179280: addiu       $v0, $v0, -0x5CB0
    ctx->r2 = ADD32(ctx->r2, -0X5CB0);
    // 0x80179284: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x80179288: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8017928C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80179290: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80179294: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80179298: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8017929C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801792A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801792A4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801792A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801792AC: lwc1        $f24, -0x329C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X329C);
    // 0x801792B0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801792B4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801792B8: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x801792BC: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801792C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801792C4: addiu       $t2, $t2, 0x6778
    ctx->r10 = ADD32(ctx->r10, 0X6778);
    // 0x801792C8: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801792CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801792D0: addiu       $t4, $t4, 0x68F0
    ctx->r12 = ADD32(ctx->r12, 0X68F0);
    // 0x801792D4: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x801792D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801792DC: addu        $s4, $t3, $t4
    ctx->r20 = ADD32(ctx->r11, ctx->r12);
    // 0x801792E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801792E4: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_801792E8:
    // 0x801792E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801792EC: jal         0x800092D0
    // 0x801792F0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801792F0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x801792F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801792F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801792FC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80179300: jal         0x80008CC0
    // 0x80179304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80179304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80179308: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x8017930C: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x80179310: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x80179314: sw          $t5, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r13;
    // 0x80179318: lw          $t6, 0x8($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X8);
    // 0x8017931C: jal         0x80018948
    // 0x80179320: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    syUtilsRandFloat(rdram, ctx);
        goto after_5;
    // 0x80179320: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    after_5:
    // 0x80179324: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80179328: add.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x8017932C: jal         0x80018948
    // 0x80179330: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x80179330: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80179334: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80179338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017933C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80179340: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80179344: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80179348: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017934C: jal         0x80018948
    // 0x80179350: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x80179350: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x80179354: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80179358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017935C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80179360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179364: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80179368: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017936C: jal         0x80018948
    // 0x80179370: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x80179370: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80179374: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80179378: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8017937C: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80179380: div.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80179384: jal         0x80018948
    // 0x80179388: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x80179388: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    after_9:
    // 0x8017938C: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80179390: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80179394: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80179398: div.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8017939C: jal         0x80018948
    // 0x801793A0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x801793A0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x801793A4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801793A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801793AC: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x801793B0: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x801793B4: div.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801793B8: bne         $s1, $s2, L_801792E8
    if (ctx->r17 != ctx->r18) {
        // 0x801793BC: swc1        $f10, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
            goto L_801792E8;
    }
    // 0x801793BC: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x801793C0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x801793C4: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x801793C8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801793CC: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x801793D0: addiu       $a1, $a1, -0x6EE0
    ctx->r5 = ADD32(ctx->r5, -0X6EE0);
    // 0x801793D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801793D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801793DC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801793E0: jal         0x80008188
    // 0x801793E4: sw          $v0, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x801793E4: sw          $v0, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->r2;
    after_11:
L_801793E8:
    // 0x801793E8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x801793EC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801793F0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801793F4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801793F8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801793FC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80179400: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80179404: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80179408: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8017940C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80179410: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80179414: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80179418: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8017941C: jr          $ra
    // 0x80179420: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80179420: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mnTitleMakeFire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B70: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132B74: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80132B78: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80132B7C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80132B80: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B84: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80132B88: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80132B8C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80132B90: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80132B94: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80132B98: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80132B9C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80132BA0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80132BA4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80132BA8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80132BAC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80132BB0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80132BB4: addiu       $a1, $a1, 0x2A20
    ctx->r5 = ADD32(ctx->r5, 0X2A20);
    // 0x80132BB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132BBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80132BC0: jal         0x80009968
    // 0x80132BC4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132BC4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80132BC8: beq         $v0, $zero, L_80132D1C
    if (ctx->r2 == 0) {
        // 0x80132BCC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80132D1C;
    }
    // 0x80132BCC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80132BD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132BD4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132BD8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132BDC: addiu       $a1, $a1, 0x2940
    ctx->r5 = ADD32(ctx->r5, 0X2940);
    // 0x80132BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132BE8: jal         0x80009DF4
    // 0x80132BEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132BEC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80132BF0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132BF4: addiu       $a1, $a1, 0x2B38
    ctx->r5 = ADD32(ctx->r5, 0X2B38);
    // 0x80132BF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80132BFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132C00: jal         0x80008188
    // 0x80132C04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132C04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132C08: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80132C0C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80132C10: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80132C14: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80132C18: lui         $at, 0x4108
    ctx->r1 = S32(0X4108 << 16);
    // 0x80132C1C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80132C20: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80132C24: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80132C28: lui         $at, 0x4118
    ctx->r1 = S32(0X4118 << 16);
    // 0x80132C2C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80132C30: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80132C34: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80132C38: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80132C3C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132C40: addiu       $s3, $s3, 0x41F0
    ctx->r19 = ADD32(ctx->r19, 0X41F0);
    // 0x80132C44: addiu       $s4, $s4, 0x45A0
    ctx->r20 = ADD32(ctx->r20, 0X45A0);
    // 0x80132C48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132C4C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80132C50: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80132C54:
    // 0x80132C54: beq         $s0, $zero, L_80132C64
    if (ctx->r16 == 0) {
        // 0x80132C58: addiu       $s1, $zero, 0xC
        ctx->r17 = ADD32(0, 0XC);
            goto L_80132C64;
    }
    // 0x80132C58: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x80132C5C: b           L_80132C64
    // 0x80132C60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80132C64;
    // 0x80132C60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80132C64:
    // 0x80132C64: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80132C68: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80132C6C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80132C70: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x80132C74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80132C78: jal         0x800CCFDC
    // 0x80132C7C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132C7C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80132C80: beq         $s0, $zero, L_80132C90
    if (ctx->r16 == 0) {
        // 0x80132C84: sh          $s6, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r22;
            goto L_80132C90;
    }
    // 0x80132C84: sh          $s6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r22;
    // 0x80132C88: b           L_80132CA0
    // 0x80132C8C: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
        goto L_80132CA0;
    // 0x80132C8C: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
L_80132C90:
    // 0x80132C90: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x80132C94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132C98: nop

    // 0x80132C9C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
L_80132CA0:
    // 0x80132CA0: beql        $s0, $zero, L_80132CB4
    if (ctx->r16 == 0) {
        // 0x80132CA4: swc1        $f30, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f30.u32l;
            goto L_80132CB4;
    }
    goto skip_0;
    // 0x80132CA4: swc1        $f30, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f30.u32l;
    skip_0:
    // 0x80132CA8: b           L_80132CB4
    // 0x80132CAC: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
        goto L_80132CB4;
    // 0x80132CAC: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132CB0: swc1        $f30, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f30.u32l;
L_80132CB4:
    // 0x80132CB4: beql        $s0, $zero, L_80132CC8
    if (ctx->r16 == 0) {
        // 0x80132CB8: swc1        $f28, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f28.u32l;
            goto L_80132CC8;
    }
    goto skip_1;
    // 0x80132CB8: swc1        $f28, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f28.u32l;
    skip_1:
    // 0x80132CBC: b           L_80132CC8
    // 0x80132CC0: swc1        $f22, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f22.u32l;
        goto L_80132CC8;
    // 0x80132CC0: swc1        $f22, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f22.u32l;
    // 0x80132CC4: swc1        $f28, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f28.u32l;
L_80132CC8:
    // 0x80132CC8: beql        $s0, $zero, L_80132CDC
    if (ctx->r16 == 0) {
        // 0x80132CCC: swc1        $f26, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f26.u32l;
            goto L_80132CDC;
    }
    goto skip_2;
    // 0x80132CCC: swc1        $f26, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f26.u32l;
    skip_2:
    // 0x80132CD0: b           L_80132CDC
    // 0x80132CD4: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
        goto L_80132CDC;
    // 0x80132CD4: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
    // 0x80132CD8: swc1        $f26, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f26.u32l;
L_80132CDC:
    // 0x80132CDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132CE0: bne         $s0, $s5, L_80132C54
    if (ctx->r16 != ctx->r21) {
        // 0x80132CE4: sw          $s1, 0x54($v0)
        MEM_W(0X54, ctx->r2) = ctx->r17;
            goto L_80132C54;
    }
    // 0x80132CE4: sw          $s1, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r17;
    // 0x80132CE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132CEC: addiu       $v0, $v0, 0x4468
    ctx->r2 = ADD32(ctx->r2, 0X4468);
    // 0x80132CF0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80132CF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CF8: sw          $zero, 0x4464($at)
    MEM_W(0X4464, ctx->r1) = 0;
    // 0x80132CFC: sw          $s6, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r22;
    // 0x80132D00: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80132D04: lbu         $t2, 0x4AD1($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4AD1);
    // 0x80132D08: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132D0C: beql        $t2, $at, L_80132D20
    if (ctx->r10 == ctx->r1) {
        // 0x80132D10: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80132D20;
    }
    goto skip_3;
    // 0x80132D10: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_3:
    // 0x80132D14: jal         0x80132A58
    // 0x80132D18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnTitleShowFire(rdram, ctx);
        goto after_4;
    // 0x80132D18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_80132D1C:
    // 0x80132D1C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80132D20:
    // 0x80132D20: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80132D24: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80132D28: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80132D2C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80132D30: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80132D34: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80132D38: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80132D3C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80132D40: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80132D44: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80132D48: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80132D4C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80132D50: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80132D54: jr          $ra
    // 0x80132D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80132D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_ovl8_80376010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376010: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80376014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80376018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037601C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80376020: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80376024: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80376028: bne         $a0, $zero, L_80376040
    if (ctx->r4 != 0) {
        // 0x8037602C: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80376040;
    }
    // 0x8037602C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80376030: jal         0x803717A0
    // 0x80376034: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80376034: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80376038: beq         $v0, $zero, L_80376150
    if (ctx->r2 == 0) {
        // 0x8037603C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80376150;
    }
    // 0x8037603C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80376040:
    // 0x80376040: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80376044: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80376048: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    // 0x8037604C: bnel        $t6, $zero, L_80376070
    if (ctx->r14 != 0) {
        // 0x80376050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80376070;
    }
    goto skip_0;
    // 0x80376050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80376054: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80376058: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8037605C: jal         0x803717E0
    // 0x80376060: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80376060: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80376064: jal         0x8037C2D0
    // 0x80376068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80376068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8037606C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80376070:
    // 0x80376070: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80376074: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80376078: jal         0x80372844
    // 0x8037607C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_ovl8_80372844(rdram, ctx);
        goto after_3;
    // 0x8037607C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80376080: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x80376084: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80376088: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8037608C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80376090: jal         0x8037203C
    // 0x80376094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_ovl8_8037203C(rdram, ctx);
        goto after_4;
    // 0x80376094: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80376098: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037609C: addiu       $t7, $t7, -0x6610
    ctx->r15 = ADD32(ctx->r15, -0X6610);
    // 0x803760A0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x803760A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x803760A8: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803760AC: addiu       $t8, $t8, -0x6558
    ctx->r24 = ADD32(ctx->r24, -0X6558);
    // 0x803760B0: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x803760B4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x803760B8: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803760BC: addiu       $t0, $t0, -0x6400
    ctx->r8 = ADD32(ctx->r8, -0X6400);
    // 0x803760C0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803760C4: addiu       $t2, $t2, -0x63D8
    ctx->r10 = ADD32(ctx->r10, -0X63D8);
    // 0x803760C8: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x803760CC: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x803760D0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x803760D4: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x803760D8: ori         $at, $at, 0x574E
    ctx->r1 = ctx->r1 | 0X574E;
    // 0x803760DC: lw          $v1, 0x14($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X14);
    // 0x803760E0: beq         $v1, $at, L_803760F4
    if (ctx->r3 == ctx->r1) {
        // 0x803760E4: lui         $at, 0x4646
        ctx->r1 = S32(0X4646 << 16);
            goto L_803760F4;
    }
    // 0x803760E4: lui         $at, 0x4646
    ctx->r1 = S32(0X4646 << 16);
    // 0x803760E8: ori         $at, $at, 0x4857
    ctx->r1 = ctx->r1 | 0X4857;
    // 0x803760EC: bnel        $v1, $at, L_8037610C
    if (ctx->r3 != ctx->r1) {
        // 0x803760F0: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_8037610C;
    }
    goto skip_1;
    // 0x803760F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    skip_1:
L_803760F4:
    // 0x803760F4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x803760F8: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x803760FC: lh          $t4, 0x20($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X20);
    // 0x80376100: jalr        $t9
    // 0x80376104: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80376104: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_5:
    // 0x80376108: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
L_8037610C:
    // 0x8037610C: lui         $t5, 0x8038
    ctx->r13 = S32(0X8038 << 16);
    // 0x80376110: addiu       $t5, $t5, -0x416C
    ctx->r13 = ADD32(ctx->r13, -0X416C);
    // 0x80376114: lui         $a3, 0x8038
    ctx->r7 = S32(0X8038 << 16);
    // 0x80376118: addiu       $a3, $a3, -0x41CC
    ctx->r7 = ADD32(ctx->r7, -0X41CC);
    // 0x8037611C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80376120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80376124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80376128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037612C: jal         0x803723AC
    // 0x80376130: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_ovl8_803723AC(rdram, ctx);
        goto after_6;
    // 0x80376130: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80376134: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80376138: addiu       $at, $zero, -0x2710
    ctx->r1 = ADD32(0, -0X2710);
    // 0x8037613C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80376140: bnel        $t8, $at, L_80376154
    if (ctx->r24 != ctx->r1) {
        // 0x80376144: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80376154;
    }
    goto skip_2;
    // 0x80376144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80376148: jal         0x803772AC
    // 0x8037614C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803772AC(rdram, ctx);
        goto after_7;
    // 0x8037614C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80376150:
    // 0x80376150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80376154:
    // 0x80376154: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80376158: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037615C: jr          $ra
    // 0x80376160: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80376160: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void scStaffrollTryHideUnlocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132958: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8013295C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132964: addiu       $t6, $t6, -0x5A20
    ctx->r14 = ADD32(ctx->r14, -0X5A20);
    // 0x80132968: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013296C: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80132970: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80132974: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80132978: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013297C: addiu       $t0, $t0, -0x5A0C
    ctx->r8 = ADD32(ctx->r8, -0X5A0C);
    // 0x80132980: addiu       $t3, $t0, 0x24
    ctx->r11 = ADD32(ctx->r8, 0X24);
    // 0x80132984: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80132988: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013298C: addiu       $t9, $sp, 0xC8
    ctx->r25 = ADD32(ctx->r29, 0XC8);
    // 0x80132990: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x80132994: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80132998: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013299C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801329A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801329A4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x801329A8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801329AC: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
L_801329B0:
    // 0x801329B0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801329B4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x801329B8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801329BC: sw          $t2, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r10;
    // 0x801329C0: lw          $t1, -0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X8);
    // 0x801329C4: sw          $t1, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r9;
    // 0x801329C8: lw          $t2, -0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, -0X4);
    // 0x801329CC: bne         $t0, $t3, L_801329B0
    if (ctx->r8 != ctx->r11) {
        // 0x801329D0: sw          $t2, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r10;
            goto L_801329B0;
    }
    // 0x801329D0: sw          $t2, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r10;
    // 0x801329D4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801329D8: addiu       $t5, $t5, -0x59E4
    ctx->r13 = ADD32(ctx->r13, -0X59E4);
    // 0x801329DC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801329E0: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x801329E4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801329E8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801329EC: addiu       $t3, $t3, -0x59C4
    ctx->r11 = ADD32(ctx->r11, -0X59C4);
    // 0x801329F0: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801329F4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801329F8: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801329FC: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80132A00: addiu       $t8, $sp, 0x98
    ctx->r24 = ADD32(ctx->r29, 0X98);
    // 0x80132A04: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80132A08: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x80132A0C: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x80132A10: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x80132A14: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132A18: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x80132A1C: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x80132A20: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80132A24: lw          $t6, 0x1C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1C);
    // 0x80132A28: addiu       $t2, $t2, -0x59B4
    ctx->r10 = ADD32(ctx->r10, -0X59B4);
    // 0x80132A2C: sw          $t7, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r15;
    // 0x80132A30: sw          $t6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r14;
    // 0x80132A34: lw          $t0, 0x4($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X4);
    // 0x80132A38: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80132A3C: addiu       $t6, $t2, 0x24
    ctx->r14 = ADD32(ctx->r10, 0X24);
    // 0x80132A40: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80132A44: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80132A48: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x80132A4C: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x80132A50: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x80132A54: sw          $t9, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r25;
    // 0x80132A58: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
L_80132A5C:
    // 0x80132A5C: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80132A60: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132A64: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132A68: sw          $t5, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r13;
    // 0x80132A6C: lw          $t4, -0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X8);
    // 0x80132A70: sw          $t4, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r12;
    // 0x80132A74: lw          $t5, -0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, -0X4);
    // 0x80132A78: bne         $t2, $t6, L_80132A5C
    if (ctx->r10 != ctx->r14) {
        // 0x80132A7C: sw          $t5, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r13;
            goto L_80132A5C;
    }
    // 0x80132A7C: sw          $t5, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r13;
    // 0x80132A80: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80132A84: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132A88: addiu       $t8, $t8, -0x598C
    ctx->r24 = ADD32(ctx->r24, -0X598C);
    // 0x80132A8C: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80132A90: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x80132A94: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80132A98: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x80132A9C: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80132AA0: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80132AA4: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80132AA8: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x80132AAC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132AB0: sw          $t0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r8;
    // 0x80132AB4: sw          $t3, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r11;
    // 0x80132AB8: lw          $t3, 0x14($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X14);
    // 0x80132ABC: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80132AC0: addiu       $t6, $t6, -0x596C
    ctx->r14 = ADD32(ctx->r14, -0X596C);
    // 0x80132AC4: sw          $t3, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r11;
    // 0x80132AC8: sw          $t0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r8;
    // 0x80132ACC: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x80132AD0: lw          $t3, 0x1C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X1C);
    // 0x80132AD4: addiu       $t4, $t6, 0x30
    ctx->r12 = ADD32(ctx->r14, 0X30);
    // 0x80132AD8: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80132ADC: sw          $t0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r8;
    // 0x80132AE0: sw          $t3, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r11;
L_80132AE4:
    // 0x80132AE4: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x80132AE8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132AEC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132AF0: sw          $t1, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r9;
    // 0x80132AF4: lw          $t2, -0x8($t6)
    ctx->r10 = MEM_W(ctx->r14, -0X8);
    // 0x80132AF8: sw          $t2, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r10;
    // 0x80132AFC: lw          $t1, -0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, -0X4);
    // 0x80132B00: bne         $t6, $t4, L_80132AE4
    if (ctx->r14 != ctx->r12) {
        // 0x80132B04: sw          $t1, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r9;
            goto L_80132AE4;
    }
    // 0x80132B04: sw          $t1, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r9;
    // 0x80132B08: lbu         $v0, 0x4937($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4937);
    // 0x80132B0C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80132B10: bnel        $t5, $zero, L_80132B2C
    if (ctx->r13 != 0) {
        // 0x80132B14: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_80132B2C;
    }
    goto skip_0;
    // 0x80132B14: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    skip_0:
    // 0x80132B18: jal         0x80132860
    // 0x80132B1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_0;
    // 0x80132B1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80132B20: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B24: lbu         $v0, 0x4937($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4937);
    // 0x80132B28: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
L_80132B2C:
    // 0x80132B2C: bne         $t7, $zero, L_80132B44
    if (ctx->r15 != 0) {
        // 0x80132B30: addiu       $a0, $sp, 0xC8
        ctx->r4 = ADD32(ctx->r29, 0XC8);
            goto L_80132B44;
    }
    // 0x80132B30: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x80132B34: jal         0x80132860
    // 0x80132B38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_1;
    // 0x80132B38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x80132B3C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B40: lbu         $v0, 0x4937($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4937);
L_80132B44:
    // 0x80132B44: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80132B48: bne         $t8, $zero, L_80132B6C
    if (ctx->r24 != 0) {
        // 0x80132B4C: addiu       $a0, $sp, 0xA8
        ctx->r4 = ADD32(ctx->r29, 0XA8);
            goto L_80132B6C;
    }
    // 0x80132B4C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80132B50: jal         0x80132860
    // 0x80132B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_2;
    // 0x80132B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80132B58: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80132B5C: jal         0x80132860
    // 0x80132B60: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_3;
    // 0x80132B60: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80132B64: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B68: lbu         $v0, 0x4937($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4937);
L_80132B6C:
    // 0x80132B6C: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x80132B70: bne         $t3, $zero, L_80132B94
    if (ctx->r11 != 0) {
        // 0x80132B74: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_80132B94;
    }
    // 0x80132B74: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80132B78: jal         0x80132860
    // 0x80132B7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_4;
    // 0x80132B7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80132B80: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80132B84: jal         0x80132860
    // 0x80132B88: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_5;
    // 0x80132B88: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x80132B8C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B90: lbu         $v0, 0x4937($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4937);
L_80132B94:
    // 0x80132B94: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x80132B98: bne         $t0, $zero, L_80132BA8
    if (ctx->r8 != 0) {
        // 0x80132B9C: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_80132BA8;
    }
    // 0x80132B9C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80132BA0: jal         0x80132860
    // 0x80132BA4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    scStaffrollSetTextQuetions(rdram, ctx);
        goto after_6;
    // 0x80132BA4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_6:
L_80132BA8:
    // 0x80132BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132BAC: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x80132BB0: jr          $ra
    // 0x80132BB4: nop

    return;
    // 0x80132BB4: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeTimeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333D4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x801333D8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801333DC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801333E0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801333E4: addiu       $v0, $sp, 0x90
    ctx->r2 = ADD32(ctx->r29, 0X90);
    // 0x801333E8: addiu       $t6, $t6, -0x75CC
    ctx->r14 = ADD32(ctx->r14, -0X75CC);
    // 0x801333EC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x801333F0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801333F4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801333F8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801333FC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80133400: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80133404: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80133408: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8013340C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80133410: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80133414: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133418: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013341C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x80133420: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x80133424: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80133428: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8013342C:
    // 0x8013342C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133430: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133434: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133438: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013343C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133440: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133444: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133448: bne         $t6, $t0, L_8013342C
    if (ctx->r14 != ctx->r8) {
        // 0x8013344C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013342C;
    }
    // 0x8013344C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133450: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133454: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133458: addiu       $t2, $t2, -0x75A4
    ctx->r10 = ADD32(ctx->r10, -0X75A4);
    // 0x8013345C: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x80133460: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x80133464: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80133468:
    // 0x80133468: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8013346C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80133470: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80133474: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80133478: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x8013347C: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80133480: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80133484: bne         $t2, $t5, L_80133468
    if (ctx->r10 != ctx->r13) {
        // 0x80133488: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80133468;
    }
    // 0x80133488: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x8013348C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80133490: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x80133494: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x80133498: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8013349C: bgez        $s4, L_801334A8
    if (SIGNED(ctx->r20) >= 0) {
        // 0x801334A0: lwc1        $f20, 0xC0($sp)
        ctx->f20.u32l = MEM_W(ctx->r29, 0XC0);
            goto L_801334A8;
    }
    // 0x801334A0: lwc1        $f20, 0xC0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801334A4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_801334A8:
    // 0x801334A8: div         $zero, $s4, $s7
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r23)));
    // 0x801334AC: mfhi        $s1
    ctx->r17 = hi;
    // 0x801334B0: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x801334B4: addiu       $fp, $fp, -0x6960
    ctx->r30 = ADD32(ctx->r30, -0X6960);
    // 0x801334B8: addu        $t0, $v0, $s1
    ctx->r8 = ADD32(ctx->r2, ctx->r17);
    // 0x801334BC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801334C0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x801334C4: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x801334C8: bne         $s7, $zero, L_801334D4
    if (ctx->r23 != 0) {
        // 0x801334CC: nop
    
            goto L_801334D4;
    }
    // 0x801334CC: nop

    // 0x801334D0: break       7
    do_break(2148742352);
L_801334D4:
    // 0x801334D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801334D8: bne         $s7, $at, L_801334EC
    if (ctx->r23 != ctx->r1) {
        // 0x801334DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801334EC;
    }
    // 0x801334DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801334E0: bne         $s4, $at, L_801334EC
    if (ctx->r20 != ctx->r1) {
        // 0x801334E4: nop
    
            goto L_801334EC;
    }
    // 0x801334E4: nop

    // 0x801334E8: break       6
    do_break(2148742376);
L_801334EC:
    // 0x801334EC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x801334F0: jal         0x800CCFDC
    // 0x801334F4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x801334F4: nop

    after_0:
    // 0x801334F8: lw          $s5, 0xC8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC8);
    // 0x801334FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133504: jal         0x80131BF8
    // 0x80133508: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayers1PGameSetDigitColors(rdram, ctx);
        goto after_1;
    // 0x80133508: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x8013350C: addu        $t7, $sp, $s1
    ctx->r15 = ADD32(ctx->r29, ctx->r17);
    // 0x80133510: lwc1        $f6, 0x68($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X68);
    // 0x80133514: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80133518: lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD0);
    // 0x8013351C: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x80133520: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80133524: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80133528: beq         $s6, $zero, L_8013353C
    if (ctx->r22 == 0) {
        // 0x8013352C: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_8013353C;
    }
    // 0x8013352C: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80133530: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x80133534: b           L_80133550
    // 0x80133538: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_80133550;
    // 0x80133538: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_8013353C:
    // 0x8013353C: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x80133540: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80133544: jal         0x80131C40
    // 0x80133548: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnPlayers1PGameGetNumberDigitCount(rdram, ctx);
        goto after_2;
    // 0x80133548: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8013354C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133550:
    // 0x80133550: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80133554: bne         $at, $zero, L_80133648
    if (ctx->r1 != 0) {
        // 0x80133558: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80133648;
    }
    // 0x80133558: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_8013355C:
    // 0x8013355C: jal         0x80131B58
    // 0x80133560: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_3;
    // 0x80133560: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80133564: beq         $v0, $zero, L_801335AC
    if (ctx->r2 == 0) {
        // 0x80133568: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801335AC;
    }
    // 0x80133568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013356C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80133570: jal         0x80131B58
    // 0x80133574: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80133574: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80133578: div         $zero, $s4, $v0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r2)));
    // 0x8013357C: mflo        $v1
    ctx->r3 = lo;
    // 0x80133580: bne         $v0, $zero, L_8013358C
    if (ctx->r2 != 0) {
        // 0x80133584: nop
    
            goto L_8013358C;
    }
    // 0x80133584: nop

    // 0x80133588: break       7
    do_break(2148742536);
L_8013358C:
    // 0x8013358C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133590: bne         $v0, $at, L_801335A4
    if (ctx->r2 != ctx->r1) {
        // 0x80133594: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801335A4;
    }
    // 0x80133594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133598: bne         $s4, $at, L_801335A4
    if (ctx->r20 != ctx->r1) {
        // 0x8013359C: nop
    
            goto L_801335A4;
    }
    // 0x8013359C: nop

    // 0x801335A0: break       6
    do_break(2148742560);
L_801335A4:
    // 0x801335A4: b           L_801335AC
    // 0x801335A8: nop

        goto L_801335AC;
    // 0x801335A8: nop

L_801335AC:
    // 0x801335AC: div         $zero, $v1, $s7
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r23)));
    // 0x801335B0: mfhi        $s1
    ctx->r17 = hi;
    // 0x801335B4: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x801335B8: addu        $t8, $sp, $s1
    ctx->r24 = ADD32(ctx->r29, ctx->r17);
    // 0x801335BC: lw          $t8, 0x90($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X90);
    // 0x801335C0: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x801335C4: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x801335C8: bne         $s7, $zero, L_801335D4
    if (ctx->r23 != 0) {
        // 0x801335CC: nop
    
            goto L_801335D4;
    }
    // 0x801335CC: nop

    // 0x801335D0: break       7
    do_break(2148742608);
L_801335D4:
    // 0x801335D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801335D8: bne         $s7, $at, L_801335EC
    if (ctx->r23 != ctx->r1) {
        // 0x801335DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801335EC;
    }
    // 0x801335DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801335E0: bne         $v1, $at, L_801335EC
    if (ctx->r3 != ctx->r1) {
        // 0x801335E4: nop
    
            goto L_801335EC;
    }
    // 0x801335E4: nop

    // 0x801335E8: break       6
    do_break(2148742632);
L_801335EC:
    // 0x801335EC: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    // 0x801335F0: jal         0x800CCFDC
    // 0x801335F4: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801335F4: nop

    after_5:
    // 0x801335F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801335FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133600: jal         0x80131BF8
    // 0x80133604: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayers1PGameSetDigitColors(rdram, ctx);
        goto after_6;
    // 0x80133604: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80133608: addu        $t2, $sp, $s1
    ctx->r10 = ADD32(ctx->r29, ctx->r17);
    // 0x8013360C: lwc1        $f8, 0x68($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X68);
    // 0x80133610: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80133614: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80133618: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8013361C: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x80133620: beq         $s6, $zero, L_80133630
    if (ctx->r22 == 0) {
        // 0x80133624: swc1        $f20, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
            goto L_80133630;
    }
    // 0x80133624: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80133628: b           L_8013363C
    // 0x8013362C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
        goto L_8013363C;
    // 0x8013362C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
L_80133630:
    // 0x80133630: jal         0x80131C40
    // 0x80133634: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnPlayers1PGameGetNumberDigitCount(rdram, ctx);
        goto after_7;
    // 0x80133634: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x80133638: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013363C:
    // 0x8013363C: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80133640: bnel        $at, $zero, L_8013355C
    if (ctx->r1 != 0) {
        // 0x80133644: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8013355C;
    }
    goto skip_0;
    // 0x80133644: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
L_80133648:
    // 0x80133648: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8013364C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133650: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133654: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133658: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8013365C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80133660: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80133664: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80133668: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8013366C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80133670: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80133674: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80133678: jr          $ra
    // 0x8013367C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8013367C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void mnOptionMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132C24: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132C28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132C2C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132C30: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132C34: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132C38: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80132C3C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132C40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132C44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132C48: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132C4C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132C50: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132C54: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132C58: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132C5C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132C60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132C64: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132C68: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132C6C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132C70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132C7C: jal         0x8000B93C
    // 0x80132C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132C84: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132C88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132C8C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132C90: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132C94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132C98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132C9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132CA0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132CA4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132CA8: jal         0x80007080
    // 0x80132CAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132CAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132CB0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132CB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132CB8: jr          $ra
    // 0x80132CBC: nop

    return;
    // 0x80132CBC: nop

;}
RECOMP_FUNC void mvOpeningRunMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132138: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013213C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80132140: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80132144: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132148: ori         $t9, $t9, 0x8640
    ctx->r25 = ctx->r25 | 0X8640;
    // 0x8013214C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80132150: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132154: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132158: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013215C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132160: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132164: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132168: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8013216C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80132170: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80132174: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132178: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013217C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132180: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132184: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132188: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013218C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132190: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132198: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013219C: jal         0x8000B93C
    // 0x801321A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801321A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801321A4: jal         0x801320B4
    // 0x801321A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRunInitMainCamera(rdram, ctx);
        goto after_1;
    // 0x801321A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801321AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801321B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801321B4: jr          $ra
    // 0x801321B8: nop

    return;
    // 0x801321B8: nop

;}
RECOMP_FUNC void efManagerSortZNeg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD60C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD614: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x800FD618: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FD61C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800FD620: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FD624: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800FD628: nop

    // 0x800FD62C: bc1fl       L_800FD660
    if (!c1cs) {
        // 0x800FD630: lw          $a0, 0x4($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X4);
            goto L_800FD660;
    }
    goto skip_0;
    // 0x800FD630: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x800FD634: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x800FD638: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FD63C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD640: lbu         $t6, 0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD);
    // 0x800FD644: beql        $t6, $at, L_800FD680
    if (ctx->r14 == ctx->r1) {
        // 0x800FD648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD680;
    }
    goto skip_1;
    // 0x800FD648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FD64C: jal         0x8000A0D0
    // 0x800FD650: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x800FD650: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800FD654: b           L_800FD680
    // 0x800FD658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FD680;
    // 0x800FD658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD65C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
L_800FD660:
    // 0x800FD660: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800FD664: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800FD668: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x800FD66C: beql        $t7, $at, L_800FD680
    if (ctx->r15 == ctx->r1) {
        // 0x800FD670: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD680;
    }
    goto skip_2;
    // 0x800FD670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FD674: jal         0x8000A0D0
    // 0x800FD678: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x800FD678: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800FD67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FD680:
    // 0x800FD680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD684: jr          $ra
    // 0x800FD688: nop

    return;
    // 0x800FD688: nop

;}
RECOMP_FUNC void itIwarkAttackUpdateRock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D740: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017D744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D748: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D74C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017D750: lw          $t6, 0x354($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X354);
    // 0x8017D754: bgtzl       $t6, L_8017D814
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017D758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017D814;
    }
    goto skip_0;
    // 0x8017D758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017D75C: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8017D760: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8017D764: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8017D768: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x8017D76C: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8017D770: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8017D774: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8017D778: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8017D77C: jal         0x80018948
    // 0x8017D780: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8017D780: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017D784: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8017D788: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D78C: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8017D790: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D794: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8017D798: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017D79C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8017D7A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017D7A4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8017D7A8: jal         0x80018994
    // 0x8017D7AC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8017D7AC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8017D7B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8017D7B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8017D7B8: jal         0x8017DF28
    // 0x8017D7BC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    itIwarkWeaponRockMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8017D7BC: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_2:
    // 0x8017D7C0: beq         $v0, $zero, L_8017D810
    if (ctx->r2 == 0) {
        // 0x8017D7C4: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8017D810;
    }
    // 0x8017D7C4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D7C8: lhu         $t0, 0x358($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X358);
    // 0x8017D7CC: lhu         $t1, 0x350($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X350);
    // 0x8017D7D0: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8017D7D4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8017D7D8: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8017D7DC: sw          $t2, 0x2A8($a0)
    MEM_W(0X2A8, ctx->r4) = ctx->r10;
    // 0x8017D7E0: lhu         $t3, 0x350($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X350);
    // 0x8017D7E4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8017D7E8: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8017D7EC: bne         $t5, $zero, L_8017D7F8
    if (ctx->r13 != 0) {
        // 0x8017D7F0: sh          $t4, 0x350($v1)
        MEM_H(0X350, ctx->r3) = ctx->r12;
            goto L_8017D7F8;
    }
    // 0x8017D7F0: sh          $t4, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r12;
    // 0x8017D7F4: sw          $t6, 0x2A8($a0)
    MEM_W(0X2A8, ctx->r4) = ctx->r14;
L_8017D7F8:
    // 0x8017D7F8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8017D7FC: jal         0x80018994
    // 0x8017D800: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8017D800: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8017D804: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D808: addiu       $t7, $v0, 0xF
    ctx->r15 = ADD32(ctx->r2, 0XF);
    // 0x8017D80C: sw          $t7, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r15;
L_8017D810:
    // 0x8017D810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017D814:
    // 0x8017D814: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017D818: jr          $ra
    // 0x8017D81C: nop

    return;
    // 0x8017D81C: nop

;}
RECOMP_FUNC void mvOpeningKirbyStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E058: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E05C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E060: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E064: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E068: addiu       $a0, $a0, -0x1EC4
    ctx->r4 = ADD32(ctx->r4, -0X1EC4);
    // 0x8018E06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E070: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E074: jal         0x80007024
    // 0x8018E078: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E078: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E07C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E080: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E084: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E088: addiu       $t9, $t9, -0x19C0
    ctx->r25 = ADD32(ctx->r25, -0X19C0);
    // 0x8018E08C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E090: addiu       $a0, $a0, -0x1EA8
    ctx->r4 = ADD32(ctx->r4, -0X1EA8);
    // 0x8018E094: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E098: jal         0x8000683C
    // 0x8018E09C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E09C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0A8: jr          $ra
    // 0x8018E0AC: nop

    return;
    // 0x8018E0AC: nop

;}
RECOMP_FUNC void ftParamSetStarHitStatusInvincible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA8B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA8B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA8B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EA8BC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800EA8C0: sw          $t6, 0x5B4($a0)
    MEM_W(0X5B4, ctx->r4) = ctx->r14;
    // 0x800EA8C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800EA8C8: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800EA8CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EA8D0: sw          $t7, 0x5B0($a0)
    MEM_W(0X5B0, ctx->r4) = ctx->r15;
    // 0x800EA8D4: jal         0x800E9814
    // 0x800EA8D8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800EA8D8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x800EA8DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA8E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA8E4: jr          $ra
    // 0x800EA8E8: nop

    return;
    // 0x800EA8E8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135FE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135FEC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135FF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135FF4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135FF8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80135FFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80136000: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80136004: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80136008: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013600C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80136010: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80136014: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80136018: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013601C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136020: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80136024: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013602C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80136030: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80136034: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136038: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013603C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136040: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80136044: jal         0x8000B93C
    // 0x80136048: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136048: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013604C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136050: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136054: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80136058: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013605C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136060: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80136064: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80136068: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013606C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80136070: jal         0x80007080
    // 0x80136074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80136074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80136078: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013607C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80136080: jr          $ra
    // 0x80136084: nop

    return;
    // 0x80136084: nop

;}
RECOMP_FUNC void ftCommonShieldBreakFlyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014946C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80149470: jal         0x800DE6E4
    // 0x80149474: addiu       $a1, $a1, -0x695C
    ctx->r5 = ADD32(ctx->r5, -0X695C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80149474: addiu       $a1, $a1, -0x695C
    ctx->r5 = ADD32(ctx->r5, -0X695C);
    after_0:
    // 0x80149478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014947C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149480: jr          $ra
    // 0x80149484: nop

    return;
    // 0x80149484: nop

;}
RECOMP_FUNC void syInterpQuadBezier4Points(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC88: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001DC8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001DC90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DC94: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001DC98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DC9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001DCA0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8001DCA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001DCA8: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8001DCAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DCB0: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001DCB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DCB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001DCBC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DCC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001DCC4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001DCC8: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001DCCC: nop

    // 0x8001DCD0: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8001DCD4: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001DCD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DCDC: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8001DCE0: add.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8001DCE4: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8001DCE8: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001DCEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001DCF0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001DCF4: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001DCF8: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001DCFC: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001DD00: nop

    // 0x8001DD04: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8001DD08: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001DD0C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001DD10: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001DD14: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001DD18: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001DD1C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001DD20: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001DD24: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8001DD28: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001DD2C: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001DD30: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001DD34: nop

    // 0x8001DD38: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001DD3C: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001DD40: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001DD44: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001DD48: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001DD4C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001DD50: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8001DD54: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001DD58: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8001DD5C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001DD60: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001DD64: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001DD68: nop

    // 0x8001DD6C: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001DD70: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001DD74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001DD78: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001DD7C: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001DD80: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001DD84: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001DD88: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001DD8C: jr          $ra
    // 0x8001DD90: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8001DD90: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void mvOpeningDonkeySetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, -0x1DD8
    ctx->r24 = ADD32(ctx->r24, -0X1DD8);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1C58
    ctx->r8 = ADD32(ctx->r8, -0X1C58);
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
    // 0x8018D11C: addiu       $a0, $a0, -0x1F44
    ctx->r4 = ADD32(ctx->r4, -0X1F44);
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
    // 0x8018D13C: addiu       $a2, $a2, -0x1C20
    ctx->r6 = ADD32(ctx->r6, -0X1C20);
    // 0x8018D140: addiu       $a0, $a0, -0x1F44
    ctx->r4 = ADD32(ctx->r4, -0X1F44);
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
RECOMP_FUNC void ftKirbySpecialAirNEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162A6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162A70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162A74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162A78: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162A7C: jal         0x800DEE98
    // 0x80162A80: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162A80: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162A84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162A88: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162A8C: addiu       $a1, $zero, 0x10F
    ctx->r5 = ADD32(0, 0X10F);
    // 0x80162A90: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162A94: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162A98: jal         0x800E6F24
    // 0x80162A9C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162A9C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162AA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162AA4: jal         0x800E8098
    // 0x80162AA8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162AA8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162AB4: jr          $ra
    // 0x80162AB8: nop

    return;
    // 0x80162AB8: nop

;}

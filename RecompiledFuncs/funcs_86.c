#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void efManagerQuakeFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801008B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801008BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801008C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801008C4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801008C8: addiu       $a1, $a1, 0x7D8
    ctx->r5 = ADD32(ctx->r5, 0X7D8);
    // 0x801008CC: lbu         $a3, 0x18($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X18);
    // 0x801008D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801008D4: jal         0x80008188
    // 0x801008D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_0;
    // 0x801008D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x801008DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801008E0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x801008E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801008E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801008EC: jr          $ra
    // 0x801008F0: nop

    return;
    // 0x801008F0: nop

;}
RECOMP_FUNC void ftCommonSquatCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014310C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143114: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143118: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014311C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80143120: slti        $at, $t6, -0x36
    ctx->r1 = SIGNED(ctx->r14) < -0X36 ? 1 : 0;
    // 0x80143124: beq         $at, $zero, L_8014313C
    if (ctx->r1 == 0) {
        // 0x80143128: nop
    
            goto L_8014313C;
    }
    // 0x80143128: nop

    // 0x8014312C: jal         0x80143024
    // 0x80143130: nop

    ftCommonSquatSetStatusNoPass(rdram, ctx);
        goto after_0;
    // 0x80143130: nop

    after_0:
    // 0x80143134: b           L_8014313C
    // 0x80143138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014313C;
    // 0x80143138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014313C:
    // 0x8014313C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143144: jr          $ra
    // 0x80143148: nop

    return;
    // 0x80143148: nop

;}
RECOMP_FUNC void mnPlayersVSSpotlightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139B90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80139B94: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80139B98: addiu       $a1, $sp, 0x4
    ctx->r5 = ADD32(ctx->r29, 0X4);
    // 0x80139B9C: addiu       $t6, $t6, -0x46F4
    ctx->r14 = ADD32(ctx->r14, -0X46F4);
    // 0x80139BA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80139BA4: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80139BA8: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
L_80139BAC:
    // 0x80139BAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80139BB0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80139BB4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80139BB8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80139BBC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80139BC0: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80139BC4: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80139BC8: bne         $t6, $t0, L_80139BAC
    if (ctx->r14 != ctx->r8) {
        // 0x80139BCC: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80139BAC;
    }
    // 0x80139BCC: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80139BD0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80139BD4: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80139BD8: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80139BDC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80139BE0: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80139BE4: addiu       $t2, $t2, -0x4578
    ctx->r10 = ADD32(ctx->r10, -0X4578);
    // 0x80139BE8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80139BEC: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80139BF0: lw          $t3, 0x88($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X88);
    // 0x80139BF4: bnel        $t3, $zero, L_80139C78
    if (ctx->r11 != 0) {
        // 0x80139BF8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80139C78;
    }
    goto skip_0;
    // 0x80139BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80139BFC: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x80139C00: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80139C04: beql        $t4, $at, L_80139C78
    if (ctx->r12 == ctx->r1) {
        // 0x80139C08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80139C78;
    }
    goto skip_1;
    // 0x80139C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80139C0C: lw          $t5, 0x7C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X7C);
    // 0x80139C10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80139C14: bnel        $v0, $t5, L_80139C28
    if (ctx->r2 != ctx->r13) {
        // 0x80139C18: sw          $v0, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r2;
            goto L_80139C28;
    }
    goto skip_2;
    // 0x80139C18: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
    skip_2:
    // 0x80139C1C: b           L_80139C28
    // 0x80139C20: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80139C28;
    // 0x80139C20: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80139C24: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
L_80139C28:
    // 0x80139C28: lw          $t0, 0x48($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X48);
    // 0x80139C2C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80139C30: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80139C34: addu        $t9, $a1, $t6
    ctx->r25 = ADD32(ctx->r5, ctx->r14);
    // 0x80139C38: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80139C3C: swc1        $f4, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f4.u32l;
    // 0x80139C40: lw          $t8, 0x48($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X48);
    // 0x80139C44: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80139C48: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80139C4C: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80139C50: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80139C54: swc1        $f6, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f6.u32l;
    // 0x80139C58: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x80139C5C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80139C60: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80139C64: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x80139C68: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80139C6C: b           L_80139C7C
    // 0x80139C70: swc1        $f8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f8.u32l;
        goto L_80139C7C;
    // 0x80139C70: swc1        $f8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f8.u32l;
    // 0x80139C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80139C78:
    // 0x80139C78: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
L_80139C7C:
    // 0x80139C7C: jr          $ra
    // 0x80139C80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80139C80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftMainProcPhysicsMapCapture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E2664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2668: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E266C: lw          $t6, 0x844($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X844);
    // 0x800E2670: beql        $t6, $zero, L_800E268C
    if (ctx->r14 == 0) {
        // 0x800E2674: lw          $t0, 0x840($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X840);
            goto L_800E268C;
    }
    goto skip_0;
    // 0x800E2674: lw          $t0, 0x840($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X840);
    skip_0:
    // 0x800E2678: lw          $t7, 0x190($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X190);
    // 0x800E267C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x800E2680: bgez        $t9, L_800E26A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E2684: nop
    
            goto L_800E26A4;
    }
    // 0x800E2684: nop

    // 0x800E2688: lw          $t0, 0x840($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X840);
L_800E268C:
    // 0x800E268C: beql        $t0, $zero, L_800E26B0
    if (ctx->r8 == 0) {
        // 0x800E2690: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E26B0;
    }
    goto skip_1;
    // 0x800E2690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800E2694: lw          $t1, 0x190($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X190);
    // 0x800E2698: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x800E269C: bgezl       $t3, L_800E26B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E26A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E26B0;
    }
    goto skip_2;
    // 0x800E26A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_800E26A4:
    // 0x800E26A4: jal         0x800E2048
    // 0x800E26A8: nop

    ftMainProcPhysicsMap(rdram, ctx);
        goto after_0;
    // 0x800E26A8: nop

    after_0:
    // 0x800E26AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E26B0:
    // 0x800E26B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E26B4: jr          $ra
    // 0x800E26B8: nop

    return;
    // 0x800E26B8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusUpdateCursorPlacementPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134C20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134C28: addiu       $t6, $t6, 0x7484
    ctx->r14 = ADD32(ctx->r14, 0X7484);
    // 0x80134C2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134C30: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80134C34: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80134C38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80134C3C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80134C40: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80134C44: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80134C48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80134C4C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80134C50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134C54: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80134C58: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80134C5C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80134C60: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80134C64: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80134C68: jal         0x8000A0D0
    // 0x80134C6C: lw          $a0, 0x764C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X764C);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80134C6C: lw          $a0, 0x764C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X764C);
    after_0:
    // 0x80134C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134C74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80134C78: jr          $ra
    // 0x80134C7C: nop

    return;
    // 0x80134C7C: nop

;}
RECOMP_FUNC void syVideoSetFramebuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006DC4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80006DC8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006DCC: addiu       $v0, $v0, 0x6688
    ctx->r2 = ADD32(ctx->r2, 0X6688);
    // 0x80006DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006DD4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80006DD8: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80006DDC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80006DE0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80006DE4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80006DE8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80006DEC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80006DF0: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x80006DF4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80006DF8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80006DFC: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80006E00: jal         0x80000970
    // 0x80006E04: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    func_80000970(rdram, ctx);
        goto after_0;
    // 0x80006E04: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_0:
    // 0x80006E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006E0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006E10: jr          $ra
    // 0x80006E14: nop

    return;
    // 0x80006E14: nop

;}
RECOMP_FUNC void ftCommonPassCheckInterruptSquat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141F14: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80141F18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80141F1C: jal         0x800F3794
    // 0x80141F20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x80141F20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80141F24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80141F28: beq         $v0, $zero, L_80141F40
    if (ctx->r2 == 0) {
        // 0x80141F2C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80141F40;
    }
    // 0x80141F2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80141F30: jal         0x80147E7C
    // 0x80141F34: nop

    ftCommonHammerFallCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80141F34: nop

    after_1:
    // 0x80141F38: b           L_80141F80
    // 0x80141F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141F80;
    // 0x80141F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141F40:
    // 0x80141F40: lw          $t6, 0xB18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XB18);
    // 0x80141F44: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80141F48: bnel        $t6, $zero, L_80141F7C
    if (ctx->r14 != 0) {
        // 0x80141F4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141F7C;
    }
    goto skip_0;
    // 0x80141F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80141F50: jal         0x80141E60
    // 0x80141F54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftCommonPassCheckInputSuccess(rdram, ctx);
        goto after_2;
    // 0x80141F54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80141F58: beq         $v0, $zero, L_80141F78
    if (ctx->r2 == 0) {
        // 0x80141F5C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80141F78;
    }
    // 0x80141F5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80141F60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80141F64: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80141F68: sw          $t7, 0xB18($a1)
    MEM_W(0XB18, ctx->r5) = ctx->r15;
    // 0x80141F6C: sw          $t8, 0xB1C($a1)
    MEM_W(0XB1C, ctx->r5) = ctx->r24;
    // 0x80141F70: b           L_80141F7C
    // 0x80141F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141F7C;
    // 0x80141F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141F78:
    // 0x80141F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80141F7C:
    // 0x80141F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141F80:
    // 0x80141F80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80141F84: jr          $ra
    // 0x80141F88: nop

    return;
    // 0x80141F88: nop

;}
RECOMP_FUNC void ftCommonYoshiEggProcTrap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CD7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014CD80: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x8014CD84: bnel        $t6, $zero, L_8014CDD0
    if (ctx->r14 != 0) {
        // 0x8014CD88: lw          $t1, 0x820($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X820);
            goto L_8014CDD0;
    }
    goto skip_0;
    // 0x8014CD88: lw          $t1, 0x820($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X820);
    skip_0:
    // 0x8014CD8C: lw          $t7, 0x7F0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7F0);
    // 0x8014CD90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014CD94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014CD98: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8014CD9C: lh          $t8, 0xB1E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB1E);
    // 0x8014CDA0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014CDA4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8014CDA8: nop

    // 0x8014CDAC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014CDB0: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8014CDB4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014CDB8: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8014CDBC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8014CDC0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8014CDC4: nop

    // 0x8014CDC8: sh          $t0, 0xB1E($v0)
    MEM_H(0XB1E, ctx->r2) = ctx->r8;
    // 0x8014CDCC: lw          $t1, 0x820($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X820);
L_8014CDD0:
    // 0x8014CDD0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8014CDD4: bne         $v1, $t1, L_8014CDF4
    if (ctx->r3 != ctx->r9) {
        // 0x8014CDD8: nop
    
            goto L_8014CDF4;
    }
    // 0x8014CDD8: nop

    // 0x8014CDDC: lw          $t2, 0x824($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X824);
    // 0x8014CDE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014CDE4: bne         $t2, $zero, L_8014CDF4
    if (ctx->r10 != 0) {
        // 0x8014CDE8: nop
    
            goto L_8014CDF4;
    }
    // 0x8014CDE8: nop

    // 0x8014CDEC: sh          $zero, 0xB1E($v0)
    MEM_H(0XB1E, ctx->r2) = 0;
    // 0x8014CDF0: sb          $t3, 0xB21($v0)
    MEM_B(0XB21, ctx->r2) = ctx->r11;
L_8014CDF4:
    // 0x8014CDF4: jr          $ra
    // 0x8014CDF8: sw          $v1, 0x814($v0)
    MEM_W(0X814, ctx->r2) = ctx->r3;
    return;
    // 0x8014CDF8: sw          $v1, 0x814($v0)
    MEM_W(0X814, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void ftCommonDamageAirCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014053C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80140540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140544: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80140548: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014054C: jal         0x80140454
    // 0x80140550: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonDamageUpdateDustEffect(rdram, ctx);
        goto after_0;
    // 0x80140550: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80140554: jal         0x801404B8
    // 0x80140558: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDamageDecHitStunSetPublic(rdram, ctx);
        goto after_1;
    // 0x80140558: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8014055C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80140560: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80140564: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80140568: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8014056C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80140570: nop

    // 0x80140574: bc1fl       L_80140594
    if (!c1cs) {
        // 0x80140578: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140594;
    }
    goto skip_0;
    // 0x80140578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014057C: lw          $t8, 0xB18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XB18);
    // 0x80140580: bnel        $t8, $zero, L_80140594
    if (ctx->r24 != 0) {
        // 0x80140584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140594;
    }
    goto skip_1;
    // 0x80140584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80140588: jal         0x80143664
    // 0x8014058C: nop

    ftCommonDamageFallSetStatusFromDamage(rdram, ctx);
        goto after_2;
    // 0x8014058C: nop

    after_2:
    // 0x80140590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140594:
    // 0x80140594: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80140598: jr          $ra
    // 0x8014059C: nop

    return;
    // 0x8014059C: nop

;}
RECOMP_FUNC void ftCommonRunBrakeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F05C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013F060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013F064: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013F068: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013F06C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013F070: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8013F074: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013F078: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013F07C: jal         0x800E6F24
    // 0x8013F080: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F080: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013F084: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8013F088: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8013F08C: sw          $t7, 0x180($t8)
    MEM_W(0X180, ctx->r24) = ctx->r15;
    // 0x8013F090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013F098: jr          $ra
    // 0x8013F09C: nop

    return;
    // 0x8013F09C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingResetPlayerNot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137960: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137964: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137968: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8013796C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137970: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137974: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80137978: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8013797C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80137980: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x80137984: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80137988: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8013798C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80137990: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80137994: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80137998: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8013799C: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x801379A0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x801379A4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801379A8: sw          $zero, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = 0;
    // 0x801379AC: sh          $zero, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = 0;
    // 0x801379B0: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x801379B4: sw          $t8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r24;
    // 0x801379B8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x801379BC: sw          $t9, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r25;
    // 0x801379C0: sw          $t0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r8;
    // 0x801379C4: jr          $ra
    // 0x801379C8: sw          $t1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r9;
    return;
    // 0x801379C8: sw          $t1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void ftFoxSpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015D25C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015D260: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x8015D264: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D268: jal         0x800E6F24
    // 0x8015D26C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D26C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D270: jal         0x800E0830
    // 0x8015D274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015D274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015D278: jal         0x8015D1E0
    // 0x8015D27C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwStartInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015D27C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015D280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D288: jr          $ra
    // 0x8015D28C: nop

    return;
    // 0x8015D28C: nop

;}
RECOMP_FUNC void itBatThrownProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174FE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80174FE4: jal         0x80172FE0
    // 0x80174FE8: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80174FE8: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80174FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174FF8: jr          $ra
    // 0x80174FFC: nop

    return;
    // 0x80174FFC: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitFlashCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132904: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132908: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013290C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132910: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132914: addiu       $t7, $zero, 0x49
    ctx->r15 = ADD32(0, 0X49);
    // 0x80132918: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8013291C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132920: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132924: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132928: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013292C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132930: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132934: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132938: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013293C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132940: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132944: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132948: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013294C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132950: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132954: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013295C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132960: jal         0x8000B93C
    // 0x80132964: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132964: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132968: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013296C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132970: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132974: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132978: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013297C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132980: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132984: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132988: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013298C: jal         0x80007080
    // 0x80132990: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132990: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132994: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132998: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013299C: jr          $ra
    // 0x801329A0: nop

    return;
    // 0x801329A0: nop

;}
RECOMP_FUNC void mvOpeningSamusStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E0C8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E0CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E0D0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E0D4: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E0D8: addiu       $a0, $a0, -0x1E68
    ctx->r4 = ADD32(ctx->r4, -0X1E68);
    // 0x8018E0DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E0E0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E0E4: jal         0x80007024
    // 0x8018E0E8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E0E8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E0EC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E0F0: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E0F4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E0F8: addiu       $t9, $t9, -0x1970
    ctx->r25 = ADD32(ctx->r25, -0X1970);
    // 0x8018E0FC: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E100: addiu       $a0, $a0, -0x1E4C
    ctx->r4 = ADD32(ctx->r4, -0X1E4C);
    // 0x8018E104: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E108: jal         0x8000683C
    // 0x8018E10C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E10C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E118: jr          $ra
    // 0x8018E11C: nop

    return;
    // 0x8018E11C: nop

;}
RECOMP_FUNC void sc1PBonusStageGetPlayerStartPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E0E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E0E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018E0EC: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x8018E0F0: jal         0x800FC814
    // 0x8018E0F4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x8018E0F4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8018E0F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E0FC: jal         0x800FC894
    // 0x8018E100: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x8018E100: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8018E104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E10C: jr          $ra
    // 0x8018E110: nop

    return;
    // 0x8018E110: nop

;}
RECOMP_FUNC void efManagerSamusEntryPointMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010347C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103484: jal         0x800FDAFC
    // 0x80103488: addiu       $a0, $a0, -0x1984
    ctx->r4 = ADD32(ctx->r4, -0X1984);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103488: addiu       $a0, $a0, -0x1984
    ctx->r4 = ADD32(ctx->r4, -0X1984);
    after_0:
    // 0x8010348C: bne         $v0, $zero, L_8010349C
    if (ctx->r2 != 0) {
        // 0x80103490: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010349C;
    }
    // 0x80103490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103494: b           L_801034C0
    // 0x80103498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801034C0;
    // 0x80103498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010349C:
    // 0x8010349C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801034A0: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801034A4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801034A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801034AC: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x801034B0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801034B4: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x801034B8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801034BC: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_801034C0:
    // 0x801034C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801034C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801034C8: jr          $ra
    // 0x801034CC: nop

    return;
    // 0x801034CC: nop

;}
RECOMP_FUNC void syInterpQuadSplineTimeFrac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E020: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001E024: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001E028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E02C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E030: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001E034: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001E038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E03C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001E040: bc1tl       L_8001E198
    if (c1cs) {
        // 0x8001E044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E198;
    }
    goto skip_0;
    // 0x8001E044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001E048: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001E04C: nop

    // 0x8001E050: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001E054: nop

    // 0x8001E058: bc1tl       L_8001E198
    if (c1cs) {
        // 0x8001E05C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E198;
    }
    goto skip_1;
    // 0x8001E05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8001E060: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8001E064: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8001E068: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8001E06C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001E070: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001E074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E078: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001E07C: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001E080: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001E084: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8001E088: nop

    // 0x8001E08C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001E090: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001E094: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8001E098: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8001E09C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001E0A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001E0A4: beq         $v1, $zero, L_8001E0D4
    if (ctx->r3 == 0) {
        // 0x8001E0A8: sub.s       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
            goto L_8001E0D4;
    }
    // 0x8001E0A8: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8001E0AC: beq         $v1, $at, L_8001E138
    if (ctx->r3 == ctx->r1) {
        // 0x8001E0B0: sll         $t5, $t0, 3
        ctx->r13 = S32(ctx->r8 << 3);
            goto L_8001E138;
    }
    // 0x8001E0B0: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x8001E0B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E0B8: beq         $v1, $at, L_8001E158
    if (ctx->r3 == ctx->r1) {
        // 0x8001E0BC: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_8001E158;
    }
    // 0x8001E0BC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001E0C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001E0C4: beq         $v1, $at, L_8001E178
    if (ctx->r3 == ctx->r1) {
        // 0x8001E0C8: sll         $t9, $t0, 2
        ctx->r25 = S32(ctx->r8 << 2);
            goto L_8001E178;
    }
    // 0x8001E0C8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8001E0CC: b           L_8001E198
    // 0x8001E0D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E198;
    // 0x8001E0D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E0D4:
    // 0x8001E0D4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8001E0D8: nop

    // 0x8001E0DC: bc1fl       L_8001E0F4
    if (!c1cs) {
        // 0x8001E0E0: lw          $t2, 0x8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X8);
            goto L_8001E0F4;
    }
    goto skip_2;
    // 0x8001E0E0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x8001E0E4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8001E0E8: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8001E0EC: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001E0F0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
L_8001E0F4:
    // 0x8001E0F4: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001E0F8: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8001E0FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001E100: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8001E104: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001E108: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E10C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001E110: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8001E114: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001E118: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001E11C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001E120: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8001E124: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001E128: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001E12C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001E130: b           L_8001E194
    // 0x8001E134: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
        goto L_8001E194;
    // 0x8001E134: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8001E138:
    // 0x8001E138: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8001E13C: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8001E140: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8001E144: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001E148: jal         0x8001DC88
    // 0x8001E14C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    syInterpQuadBezier4Points(rdram, ctx);
        goto after_0;
    // 0x8001E14C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x8001E150: b           L_8001E198
    // 0x8001E154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E198;
    // 0x8001E154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E158:
    // 0x8001E158: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8001E15C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8001E160: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001E164: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001E168: jal         0x8001DA40
    // 0x8001E16C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    syInterpBezier4Points(rdram, ctx);
        goto after_1;
    // 0x8001E16C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8001E170: b           L_8001E198
    // 0x8001E174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E198;
    // 0x8001E174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E178:
    // 0x8001E178: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8001E17C: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x8001E180: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001E184: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8001E188: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8001E18C: jal         0x8001D754
    // 0x8001E190: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    syInterpQuadSpline(rdram, ctx);
        goto after_2;
    // 0x8001E190: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
L_8001E194:
    // 0x8001E194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E198:
    // 0x8001E198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E19C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E1A0: jr          $ra
    // 0x8001E1A4: nop

    return;
    // 0x8001E1A4: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D994: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015D998: jal         0x800DE6E4
    // 0x8015D99C: addiu       $a1, $a1, -0x2650
    ctx->r5 = ADD32(ctx->r5, -0X2650);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015D99C: addiu       $a1, $a1, -0x2650
    ctx->r5 = ADD32(ctx->r5, -0X2650);
    after_0:
    // 0x8015D9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D9A8: jr          $ra
    // 0x8015D9AC: nop

    return;
    // 0x8015D9AC: nop

;}
RECOMP_FUNC void _n_timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C54C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002C550: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002C554: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8002C558: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002C55C: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8002C560: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002C564: lwc1        $f18, -0x11B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X11B0);
    // 0x8002C568: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8002C56C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002C570: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002C574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C578: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8002C57C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C580: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8002C584: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002C588: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002C58C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002C590: jr          $ra
    // 0x8002C594: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    return;
    // 0x8002C594: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
;}
RECOMP_FUNC void func_ovl8_80371D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371D78: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80371D7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80371D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371D84: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x80371D88: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80371D8C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80371D90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80371D94: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80371D98: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x80371D9C: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x80371DA0: lw          $t9, 0xE4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XE4);
    // 0x80371DA4: lh          $t6, 0xE0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE0);
    // 0x80371DA8: jalr        $t9
    // 0x80371DAC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371DAC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80371DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371DB8: jr          $ra
    // 0x80371DBC: nop

    return;
    // 0x80371DBC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNReleaseInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F73C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015F740: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8015F744: jal         0x800E8098
    // 0x8015F748: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015F748: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015F74C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F750: sw          $zero, 0x184($a0)
    MEM_W(0X184, ctx->r4) = 0;
    // 0x8015F754: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    // 0x8015F758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F760: jr          $ra
    // 0x8015F764: nop

    return;
    // 0x8015F764: nop

;}
RECOMP_FUNC void func_ovl2_800FD70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD70C: jr          $ra
    // 0x800FD710: nop

    return;
    // 0x800FD710: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueRoomFadeInProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132338: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013233C: addiu       $t3, $t3, 0x431C
    ctx->r11 = ADD32(ctx->r11, 0X431C);
    // 0x80132340: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80132344: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80132348: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8013234C: blez        $v0, L_80132364
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80132350: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80132364;
    }
    // 0x80132350: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132354: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x80132358: bgez        $t6, L_80132364
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8013235C: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_80132364;
    }
    // 0x8013235C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80132360: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80132364:
    // 0x80132364: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132368: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8013236C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80132370: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132374: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132378: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8013237C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132380: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132384: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132388: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8013238C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132390: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80132394: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132398: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013239C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801323A0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801323A4: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801323A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801323AC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x801323B0: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x801323B4: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x801323B8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x801323BC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801323C0: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801323C4: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x801323C8: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x801323CC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801323D0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801323D4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801323D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801323DC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801323E0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x801323E4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801323E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801323EC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801323F0: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801323F4: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x801323F8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801323FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132400: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132404: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132408: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8013240C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132410: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80132414: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x80132418: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8013241C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80132420: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132424: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132428: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x8013242C: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80132430: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132434: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132438: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8013243C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132440: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132444: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80132448: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x8013244C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132450: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80132454: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80132458: jr          $ra
    // 0x8013245C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x8013245C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void mnMapsCheckLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BAC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80131BB0: bne         $a0, $at, L_80131BDC
    if (ctx->r4 != ctx->r1) {
        // 0x80131BB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131BDC;
    }
    // 0x80131BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131BB8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131BBC: lbu         $t6, 0x4C1C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4C1C);
    // 0x80131BC0: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80131BC4: beq         $t7, $zero, L_80131BD4
    if (ctx->r15 == 0) {
        // 0x80131BC8: nop
    
            goto L_80131BD4;
    }
    // 0x80131BC8: nop

    // 0x80131BCC: jr          $ra
    // 0x80131BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131BD4:
    // 0x80131BD4: jr          $ra
    // 0x80131BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131BDC:
    // 0x80131BDC: jr          $ra
    // 0x80131BE0: nop

    return;
    // 0x80131BE0: nop

;}
RECOMP_FUNC void mnPlayers1PGameSetSceneData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137F10: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137F14: lw          $t6, -0x7080($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7080);
    // 0x80137F18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80137F1C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80137F20: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137F24: sb          $t6, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r14;
    // 0x80137F28: lw          $t7, -0x7058($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7058);
    // 0x80137F2C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137F30: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80137F34: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x80137F38: lw          $t8, -0x704C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X704C);
    // 0x80137F3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80137F40: addiu       $a0, $a0, -0x7118
    ctx->r4 = ADD32(ctx->r4, -0X7118);
    // 0x80137F44: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x80137F48: lw          $t0, 0x58($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X58);
    // 0x80137F4C: sb          $zero, 0x17($v0)
    MEM_B(0X17, ctx->r2) = 0;
    // 0x80137F50: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137F54: sb          $t8, 0x45A($v1)
    MEM_B(0X45A, ctx->r3) = ctx->r24;
    // 0x80137F58: lw          $t9, -0x7048($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7048);
    // 0x80137F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137F64: beq         $t0, $zero, L_80137F78
    if (ctx->r8 == 0) {
        // 0x80137F68: sb          $t9, 0x45B($v1)
        MEM_B(0X45B, ctx->r3) = ctx->r25;
            goto L_80137F78;
    }
    // 0x80137F68: sb          $t9, 0x45B($v1)
    MEM_B(0X45B, ctx->r3) = ctx->r25;
    // 0x80137F6C: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x80137F70: b           L_80137F80
    // 0x80137F74: sb          $t1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r9;
        goto L_80137F80;
    // 0x80137F74: sb          $t1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r9;
L_80137F78:
    // 0x80137F78: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80137F7C: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
L_80137F80:
    // 0x80137F80: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x80137F84: jal         0x800D45F4
    // 0x80137F88: sb          $t3, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r11;
    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x80137F88: sb          $t3, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r11;
    after_0:
    // 0x80137F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137F94: jr          $ra
    // 0x80137F98: nop

    return;
    // 0x80137F98: nop

;}
RECOMP_FUNC void func_ovl8_8037C7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C7D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037C7D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037C7DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037C7E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037C7E4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037C7E8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8037C7EC: bne         $a0, $zero, L_8037C804
    if (ctx->r4 != 0) {
        // 0x8037C7F0: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8037C804;
    }
    // 0x8037C7F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8037C7F4: jal         0x803717A0
    // 0x8037C7F8: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037C7F8: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x8037C7FC: beq         $v0, $zero, L_8037C918
    if (ctx->r2 == 0) {
        // 0x8037C800: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037C918;
    }
    // 0x8037C800: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037C804:
    // 0x8037C804: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8037C808: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8037C80C: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    // 0x8037C810: bnel        $t6, $zero, L_8037C834
    if (ctx->r14 != 0) {
        // 0x8037C814: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_8037C834;
    }
    goto skip_0;
    // 0x8037C814: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x8037C818: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037C81C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8037C820: jal         0x803717E0
    // 0x8037C824: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037C824: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037C828: jal         0x8037C2D0
    // 0x8037C82C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037C82C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8037C830: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_8037C834:
    // 0x8037C834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C838: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037C83C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8037C840: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037C844: jal         0x80373CC4
    // 0x8037C848: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80373CC4(rdram, ctx);
        goto after_3;
    // 0x8037C848: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037C84C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8037C850: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8037C854: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037C858: beq         $v1, $zero, L_8037C868
    if (ctx->r3 == 0) {
        // 0x8037C85C: lw          $a2, 0x44($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X44);
            goto L_8037C868;
    }
    // 0x8037C85C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8037C860: b           L_8037C86C
    // 0x8037C864: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8037C86C;
    // 0x8037C864: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037C868:
    // 0x8037C868: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8037C86C:
    // 0x8037C86C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8037C870: jal         0x803724B4
    // 0x8037C874: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_ovl8_803724B4(rdram, ctx);
        goto after_4;
    // 0x8037C874: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x8037C878: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037C87C: addiu       $t8, $t8, -0x5E30
    ctx->r24 = ADD32(ctx->r24, -0X5E30);
    // 0x8037C880: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x8037C884: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8037C888: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037C88C: addiu       $t9, $t9, -0x5D50
    ctx->r25 = ADD32(ctx->r25, -0X5D50);
    // 0x8037C890: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x8037C894: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8037C898: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037C89C: addiu       $t1, $t1, -0x5BF8
    ctx->r9 = ADD32(ctx->r9, -0X5BF8);
    // 0x8037C8A0: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037C8A4: addiu       $t3, $t3, -0x5BD0
    ctx->r11 = ADD32(ctx->r11, -0X5BD0);
    // 0x8037C8A8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8037C8AC: sw          $t3, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r11;
    // 0x8037C8B0: jal         0x8037CA50
    // 0x8037C8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037CA50(rdram, ctx);
        goto after_5;
    // 0x8037C8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8037C8B8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8037C8BC: lui         $at, 0x5342
    ctx->r1 = S32(0X5342 << 16);
    // 0x8037C8C0: ori         $at, $at, 0x544E
    ctx->r1 = ctx->r1 | 0X544E;
    // 0x8037C8C4: sw          $t4, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r12;
    // 0x8037C8C8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8037C8CC: sw          $t5, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r13;
    // 0x8037C8D0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8037C8D4: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x8037C8D8: beq         $v0, $at, L_8037C900
    if (ctx->r2 == ctx->r1) {
        // 0x8037C8DC: lui         $at, 0x5354
        ctx->r1 = S32(0X5354 << 16);
            goto L_8037C900;
    }
    // 0x8037C8DC: lui         $at, 0x5354
    ctx->r1 = S32(0X5354 << 16);
    // 0x8037C8E0: ori         $at, $at, 0x4742
    ctx->r1 = ctx->r1 | 0X4742;
    // 0x8037C8E4: beq         $v0, $at, L_8037C908
    if (ctx->r2 == ctx->r1) {
        // 0x8037C8E8: lui         $at, 0x534F
        ctx->r1 = S32(0X534F << 16);
            goto L_8037C908;
    }
    // 0x8037C8E8: lui         $at, 0x534F
    ctx->r1 = S32(0X534F << 16);
    // 0x8037C8EC: ori         $at, $at, 0x5042
    ctx->r1 = ctx->r1 | 0X5042;
    // 0x8037C8F0: beql        $v0, $at, L_8037C914
    if (ctx->r2 == ctx->r1) {
        // 0x8037C8F4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8037C914;
    }
    goto skip_1;
    // 0x8037C8F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8037C8F8: b           L_8037C914
    // 0x8037C8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C914;
    // 0x8037C8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037C900:
    // 0x8037C900: b           L_8037C914
    // 0x8037C904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C914;
    // 0x8037C904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037C908:
    // 0x8037C908: b           L_8037C914
    // 0x8037C90C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037C914;
    // 0x8037C90C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037C910: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8037C914:
    // 0x8037C914: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
L_8037C918:
    // 0x8037C918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037C91C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037C920: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037C924: jr          $ra
    // 0x8037C928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037C928: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void syTaskmanScheduleGfxEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004E98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004E9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80004EA0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004EA4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80004EA8: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80004EAC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80004EB0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80004EB4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80004EB8: sw          $a3, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r7;
    // 0x80004EBC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80004EC0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80004EC4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80004EC8: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x80004ECC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80004ED0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004ED4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80004ED8: lw          $t0, 0x6630($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6630);
    // 0x80004EDC: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x80004EE0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004EE4: jal         0x80030000
    // 0x80004EE8: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004EE8: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    after_0:
    // 0x80004EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004EF4: jr          $ra
    // 0x80004EF8: nop

    return;
    // 0x80004EF8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132A5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132A60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132A64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132A68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132A6C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_80132A70:
    // 0x80132A70: jal         0x80132798
    // 0x80132A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusMakePortrait(rdram, ctx);
        goto after_0;
    // 0x80132A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80132A78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132A7C: bne         $s0, $s1, L_80132A70
    if (ctx->r16 != ctx->r17) {
        // 0x80132A80: nop
    
            goto L_80132A70;
    }
    // 0x80132A80: nop

    // 0x80132A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80132A8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80132A90: jr          $ra
    // 0x80132A94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132A94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80374B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374B80: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374B84: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80374B88: lh          $t6, 0x30($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X30);
    // 0x80374B8C: jalr        $t9
    // 0x80374B90: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374B90: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374B9C: jr          $ra
    // 0x80374BA0: nop

    return;
    // 0x80374BA0: nop

;}
RECOMP_FUNC void mpCommonProcFighterCliff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE80C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DE810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DE818: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800DE81C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DE820: jal         0x800DE7D8
    // 0x800DE824: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterCliff(rdram, ctx);
        goto after_0;
    // 0x800DE824: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DE828: beq         $v0, $zero, L_800DE868
    if (ctx->r2 == 0) {
        // 0x800DE82C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800DE868;
    }
    // 0x800DE82C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DE830: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE834: lhu         $t8, 0xD2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XD2);
    // 0x800DE838: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x800DE83C: beql        $t9, $zero, L_800DE858
    if (ctx->r25 == 0) {
        // 0x800DE840: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800DE858;
    }
    goto skip_0;
    // 0x800DE840: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DE844: jal         0x80144C24
    // 0x800DE848: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DE848: nop

    after_1:
    // 0x800DE84C: b           L_800DE86C
    // 0x800DE850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DE86C;
    // 0x800DE850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DE854: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_800DE858:
    // 0x800DE858: jalr        $t9
    // 0x800DE85C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800DE85C: nop

    after_2:
    // 0x800DE860: b           L_800DE86C
    // 0x800DE864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DE86C;
    // 0x800DE864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DE868:
    // 0x800DE868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE86C:
    // 0x800DE86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DE874: jr          $ra
    // 0x800DE878: nop

    return;
    // 0x800DE878: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801338F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801338F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801338F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801338FC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80133900: jal         0x80009968
    // 0x80133904: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133904: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133908: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013390C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133910: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133914: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133918: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013391C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133920: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80133924: jal         0x80009DF4
    // 0x80133928: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133928: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013392C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133930: lw          $t7, -0x6958($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6958);
    // 0x80133934: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133938: addiu       $t8, $t8, 0x440
    ctx->r24 = ADD32(ctx->r24, 0X440);
    // 0x8013393C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133940: jal         0x800CCFDC
    // 0x80133944: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133944: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80133948: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013394C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133950: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80133954: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80133958: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x8013395C: addiu       $t2, $zero, 0xDC
    ctx->r10 = ADD32(0, 0XDC);
    // 0x80133960: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80133964: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80133968: sb          $t9, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r25;
    // 0x8013396C: sb          $t0, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r8;
    // 0x80133970: sh          $t1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r9;
    // 0x80133974: sh          $t2, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r10;
    // 0x80133978: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013397C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133988: jr          $ra
    // 0x8013398C: nop

    return;
    // 0x8013398C: nop

;}
RECOMP_FUNC void mvOpeningMarioMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D944: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D94C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D954: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D958: jal         0x80009968
    // 0x8018D95C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D95C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D960: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D964: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D968: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D96C: addiu       $a1, $a1, -0x27BC
    ctx->r5 = ADD32(ctx->r5, -0X27BC);
    // 0x8018D970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D974: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D978: jal         0x80009DF4
    // 0x8018D97C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D97C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D984: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D988: jr          $ra
    // 0x8018D98C: nop

    return;
    // 0x8018D98C: nop

;}
RECOMP_FUNC void dbCubeMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131F2C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80131F30: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80131F34: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80131F38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131F3C: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x80131F40: lui         $a0, 0x1000
    ctx->r4 = S32(0X1000 << 16);
    // 0x80131F44: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F48: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80131F4C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131F50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80131F54: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131F5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80131F60: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80131F64: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80131F68: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131F6C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131F70: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131F74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131F78: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x80131F7C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80131F80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F84: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80131F88: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131F90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131F94: jal         0x8000B93C
    // 0x80131F98: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131F98: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_0:
    // 0x80131F9C: bne         $v0, $zero, L_80131FAC
    if (ctx->r2 != 0) {
        // 0x80131FA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80131FAC;
    }
    // 0x80131FA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80131FA4: b           L_80131FCC
    // 0x80131FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80131FCC;
    // 0x80131FA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131FAC:
    // 0x80131FAC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80131FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FB4: lw          $t4, 0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X74);
    // 0x80131FB8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80131FBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131FC0: swc1        $f4, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f4.u32l;
    // 0x80131FC4: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x80131FC8: sw          $t5, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->r13;
L_80131FCC:
    // 0x80131FCC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131FD0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80131FD4: jr          $ra
    // 0x80131FD8: nop

    return;
    // 0x80131FD8: nop

;}
RECOMP_FUNC void itHarisenMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80175464: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80175468: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017546C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80175470: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80175474: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80175478: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017547C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175480: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80175484: addiu       $a1, $a1, -0x6588
    ctx->r5 = ADD32(ctx->r5, -0X6588);
    // 0x80175488: jal         0x8016E174
    // 0x8017548C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017548C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80175490: beq         $v0, $zero, L_801754D0
    if (ctx->r2 == 0) {
        // 0x80175494: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801754D0;
    }
    // 0x80175494: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80175498: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017549C: lwc1        $f4, -0x3318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3318);
    // 0x801754A0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x801754A4: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801754A8: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x801754AC: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x801754B0: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x801754B4: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x801754B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801754BC: jal         0x80111EC0
    // 0x801754C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x801754C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x801754C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801754C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801754CC: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_801754D0:
    // 0x801754D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801754D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801754D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801754DC: jr          $ra
    // 0x801754E0: nop

    return;
    // 0x801754E0: nop

;}
RECOMP_FUNC void __alSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F9FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FA04: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8002FA08: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002FA0C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8002FA10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FA14: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002FA18: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x8002FA1C: bne         $at, $zero, L_8002FA2C
    if (ctx->r1 != 0) {
        // 0x8002FA20: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_8002FA2C;
    }
    // 0x8002FA20: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8002FA24: b           L_8002FA44
    // 0x8002FA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002FA44;
    // 0x8002FA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002FA2C:
    // 0x8002FA2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8002FA30: jal         0x8002F70C
    // 0x8002FA34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    static_5_8002F70C(rdram, ctx);
        goto after_0;
    // 0x8002FA34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8002FA38: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8002FA3C: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x8002FA40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002FA44:
    // 0x8002FA44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FA48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FA4C: jr          $ra
    // 0x8002FA50: nop

    return;
    // 0x8002FA50: nop

;}
RECOMP_FUNC void mpCollisionPlayYakumonoAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBAD0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800FBAD4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800FBAD8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800FBADC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800FBAE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800FBAE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800FBAE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FBAEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FBAF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FBAF4: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x800FBAF8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800FBAFC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800FBB00: beq         $s1, $zero, L_800FBCAC
    if (ctx->r17 == 0) {
        // 0x800FBB04: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800FBCAC;
    }
    // 0x800FBB04: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800FBB08: addiu       $s6, $s6, 0x137C
    ctx->r22 = ADD32(ctx->r22, 0X137C);
    // 0x800FBB0C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800FBB10:
    // 0x800FBB10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FBB14: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800FBB18: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x800FBB1C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800FBB20: bne         $s1, $t8, L_800FBC14
    if (ctx->r17 != ctx->r24) {
        // 0x800FBB24: nop
    
            goto L_800FBC14;
    }
    // 0x800FBB24: nop

    // 0x800FBB28: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
    // 0x800FBB2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FBB30: beq         $v0, $at, L_800FBBF0
    if (ctx->r2 == ctx->r1) {
        // 0x800FBB34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FBBF0;
    }
    // 0x800FBB34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FBB38: beq         $v0, $at, L_800FBBF0
    if (ctx->r2 == ctx->r1) {
        // 0x800FBB3C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800FBBF0;
    }
    // 0x800FBB3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FBB40: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x800FBB44: subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
    // 0x800FBB48: lbu         $s2, 0x54($s1)
    ctx->r18 = MEM_BU(ctx->r17, 0X54);
    // 0x800FBB4C: jal         0x8000BFE8
    // 0x800FBB50: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800FBB50: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    after_0:
    // 0x800FBB54: lw          $t1, 0x1C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1C);
    // 0x800FBB58: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800FBB5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FBB60: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800FBB64: lw          $t0, 0x20($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X20);
    // 0x800FBB68: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800FBB6C: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x800FBB70: jal         0x8000CCBC
    // 0x800FBB74: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x800FBB74: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    after_1:
    // 0x800FBB78: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800FBB7C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FBB80: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x800FBB84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FBB88: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800FBB8C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800FBB90: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800FBB94: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800FBB98: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x800FBB9C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800FBBA0: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800FBBA4: swc1        $f18, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f18.u32l;
    // 0x800FBBA8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800FBBAC: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800FBBB0: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800FBBB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FBBB8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800FBBBC: bne         $s2, $zero, L_800FBBDC
    if (ctx->r18 != 0) {
        // 0x800FBBC0: swc1        $f8, 0x8($t7)
        MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
            goto L_800FBBDC;
    }
    // 0x800FBBC0: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x800FBBC4: lbu         $t8, 0x54($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X54);
    // 0x800FBBC8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800FBBCC: beq         $t8, $zero, L_800FBBF0
    if (ctx->r24 == 0) {
        // 0x800FBBD0: nop
    
            goto L_800FBBF0;
    }
    // 0x800FBBD0: nop

    // 0x800FBBD4: b           L_800FBBF0
    // 0x800FBBD8: sw          $t9, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r25;
        goto L_800FBBF0;
    // 0x800FBBD8: sw          $t9, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r25;
L_800FBBDC:
    // 0x800FBBDC: lbu         $t0, 0x54($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X54);
    // 0x800FBBE0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800FBBE4: bne         $t0, $zero, L_800FBBF0
    if (ctx->r8 != 0) {
        // 0x800FBBE8: nop
    
            goto L_800FBBF0;
    }
    // 0x800FBBE8: nop

    // 0x800FBBEC: sw          $t1, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r9;
L_800FBBF0:
    // 0x800FBBF0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800FBBF4: lw          $t2, 0x138C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X138C);
    // 0x800FBBF8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800FBBFC: slt         $at, $s4, $t3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800FBC00: beql        $at, $zero, L_800FBC28
    if (ctx->r1 == 0) {
        // 0x800FBC04: lw          $s0, 0x80($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X80);
            goto L_800FBC28;
    }
    goto skip_0;
    // 0x800FBC04: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    skip_0:
    // 0x800FBC08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800FBC0C: b           L_800FBC24
    // 0x800FBC10: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
        goto L_800FBC24;
    // 0x800FBC10: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800FBC14:
    // 0x800FBC14: jal         0x8000BFE8
    // 0x800FBC18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x800FBC18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800FBC1C: jal         0x8000CCBC
    // 0x800FBC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_3;
    // 0x800FBC20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_800FBC24:
    // 0x800FBC24: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
L_800FBC28:
    // 0x800FBC28: beql        $s0, $zero, L_800FBC50
    if (ctx->r16 == 0) {
        // 0x800FBC2C: lw          $v0, 0x10($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X10);
            goto L_800FBC50;
    }
    goto skip_1;
    // 0x800FBC2C: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    skip_1:
L_800FBC30:
    // 0x800FBC30: jal         0x8000CF6C
    // 0x800FBC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_4;
    // 0x800FBC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800FBC38: jal         0x8000DA40
    // 0x800FBC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_5;
    // 0x800FBC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800FBC40: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800FBC44: bne         $s0, $zero, L_800FBC30
    if (ctx->r16 != 0) {
        // 0x800FBC48: nop
    
            goto L_800FBC30;
    }
    // 0x800FBC48: nop

    // 0x800FBC4C: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
L_800FBC50:
    // 0x800FBC50: beql        $v0, $zero, L_800FBC64
    if (ctx->r2 == 0) {
        // 0x800FBC54: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800FBC64;
    }
    goto skip_2;
    // 0x800FBC54: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x800FBC58: b           L_800FBCA4
    // 0x800FBC5C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800FBCA4;
    // 0x800FBC5C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FBC60: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800FBC64:
    // 0x800FBC64: beql        $v0, $zero, L_800FBC78
    if (ctx->r2 == 0) {
        // 0x800FBC68: lw          $v0, 0x14($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X14);
            goto L_800FBC78;
    }
    goto skip_3;
    // 0x800FBC68: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    skip_3:
    // 0x800FBC6C: b           L_800FBCA4
    // 0x800FBC70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800FBCA4;
    // 0x800FBC70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800FBC74:
    // 0x800FBC74: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
L_800FBC78:
    // 0x800FBC78: bnel        $s3, $v0, L_800FBC8C
    if (ctx->r19 != ctx->r2) {
        // 0x800FBC7C: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800FBC8C;
    }
    goto skip_4;
    // 0x800FBC7C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_4:
    // 0x800FBC80: b           L_800FBCA4
    // 0x800FBC84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800FBCA4;
    // 0x800FBC84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FBC88: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800FBC8C:
    // 0x800FBC8C: beq         $v1, $zero, L_800FBC9C
    if (ctx->r3 == 0) {
        // 0x800FBC90: nop
    
            goto L_800FBC9C;
    }
    // 0x800FBC90: nop

    // 0x800FBC94: b           L_800FBCA4
    // 0x800FBC98: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_800FBCA4;
    // 0x800FBC98: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800FBC9C:
    // 0x800FBC9C: b           L_800FBC74
    // 0x800FBCA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800FBC74;
    // 0x800FBCA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800FBCA4:
    // 0x800FBCA4: bne         $s1, $zero, L_800FBB10
    if (ctx->r17 != 0) {
        // 0x800FBCA8: nop
    
            goto L_800FBB10;
    }
    // 0x800FBCA8: nop

L_800FBCAC:
    // 0x800FBCAC: jal         0x800FB808
    // 0x800FBCB0: nop

    mpCollisionUpdateBoundsCurrent(rdram, ctx);
        goto after_6;
    // 0x800FBCB0: nop

    after_6:
    // 0x800FBCB4: jal         0x800FBA84
    // 0x800FBCB8: nop

    mpCollisionUpdateBoundsDiff(rdram, ctx);
        goto after_7;
    // 0x800FBCB8: nop

    after_7:
    // 0x800FBCBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FBCC0: addiu       $v0, $v0, 0x1398
    ctx->r2 = ADD32(ctx->r2, 0X1398);
    // 0x800FBCC4: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x800FBCC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800FBCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FBCD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FBCD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FBCD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800FBCDC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800FBCE0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800FBCE4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800FBCE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800FBCEC: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800FBCF0: jr          $ra
    // 0x800FBCF4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800FBCF4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mvOpeningKirbyInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE7C: jr          $ra
    // 0x8018DE80: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
    return;
    // 0x8018DE80: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
;}
RECOMP_FUNC void mvOpeningStandoffMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B6C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131B70: jal         0x80009968
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B7C: lw          $t6, 0x2B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2B98);
    // 0x80131B80: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131B84: addiu       $t7, $t7, 0x1C10
    ctx->r15 = ADD32(ctx->r15, 0X1C10);
    // 0x80131B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B90: jal         0x800092D0
    // 0x80131B94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131B94: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131B98: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80131B9C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131BA0: jal         0x80008CC0
    // 0x80131BA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80131BA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80131BA8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131BAC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131BB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131BB4: addiu       $a1, $a1, 0x3E68
    ctx->r5 = ADD32(ctx->r5, 0X3E68);
    // 0x80131BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131BBC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80131BC0: jal         0x80009DF4
    // 0x80131BC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80131BC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131BC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131BCC: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131BD0: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131BD4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131BD8: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131BDC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131BE0: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131BE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131BE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131BEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: nop

    return;
    // 0x80131BF4: nop

;}
RECOMP_FUNC void ftCommonGuardOffSetHitStatusYoshi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801482E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801482E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801482EC: jal         0x800E880C
    // 0x801482F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetHitStatusPartAll(rdram, ctx);
        goto after_0;
    // 0x801482F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801482F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801482F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801482FC: jr          $ra
    // 0x80148300: nop

    return;
    // 0x80148300: nop

;}
RECOMP_FUNC void func_ovl8_80381A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381A88: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80381A8C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80381A90: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80381A94: beq         $at, $zero, L_80381AE8
    if (ctx->r1 == 0) {
        // 0x80381A98: nop
    
            goto L_80381AE8;
    }
    // 0x80381A98: nop

    // 0x80381A9C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80381AA0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80381AA4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80381AA8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80381AAC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80381AB0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80381AB4: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80381AB8: sw          $t8, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r24;
    // 0x80381ABC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80381AC0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80381AC4: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x80381AC8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381ACC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80381AD0: addu        $t0, $t7, $t2
    ctx->r8 = ADD32(ctx->r15, ctx->r10);
    // 0x80381AD4: sw          $t5, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r13;
    // 0x80381AD8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80381ADC: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x80381AE0: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80381AE4: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_80381AE8:
    // 0x80381AE8: jr          $ra
    // 0x80381AEC: nop

    return;
    // 0x80381AEC: nop

;}
RECOMP_FUNC void lbBackupWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D45F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D45F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D45FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D4600: jal         0x800D4520
    // 0x800D4604: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    lbBackupCreateChecksum(rdram, ctx);
        goto after_0;
    // 0x800D4604: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    after_0:
    // 0x800D4608: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D460C: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x800D4610: sw          $v0, 0x5E8($a0)
    MEM_W(0X5E8, ctx->r4) = ctx->r2;
    // 0x800D4614: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D4618: jal         0x80002DE0
    // 0x800D461C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    syDmaWriteSram(rdram, ctx);
        goto after_1;
    // 0x800D461C: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    after_1:
    // 0x800D4620: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D4624: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x800D4628: addiu       $a1, $zero, 0x5F0
    ctx->r5 = ADD32(0, 0X5F0);
    // 0x800D462C: jal         0x80002DE0
    // 0x800D4630: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    syDmaWriteSram(rdram, ctx);
        goto after_2;
    // 0x800D4630: addiu       $a2, $zero, 0x5EC
    ctx->r6 = ADD32(0, 0X5EC);
    after_2:
    // 0x800D4634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D463C: jr          $ra
    // 0x800D4640: nop

    return;
    // 0x800D4640: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D1B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1BC: addiu       $t7, $t7, -0x1F04
    ctx->r15 = ADD32(ctx->r15, -0X1F04);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: addiu       $t6, $sp, 0x80
    ctx->r14 = ADD32(ctx->r29, 0X80);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1DC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1E8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1EC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018D1F0: addiu       $t1, $t1, -0x1EEC
    ctx->r9 = ADD32(ctx->r9, -0X1EEC);
    // 0x8018D1F4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D1F8: addiu       $t4, $t1, 0x24
    ctx->r12 = ADD32(ctx->r9, 0X24);
    // 0x8018D1FC: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x8018D200: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D204: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
L_8018D208:
    // 0x8018D208: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D20C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D210: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D214: sw          $t3, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r11;
    // 0x8018D218: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018D21C: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x8018D220: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018D224: bne         $t1, $t4, L_8018D208
    if (ctx->r9 != ctx->r12) {
        // 0x8018D228: sw          $t3, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r11;
            goto L_8018D208;
    }
    // 0x8018D228: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x8018D22C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D238: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D23C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D240: jal         0x80009968
    // 0x8018D244: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D244: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D248: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D24C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D250: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8018D254: sw          $v0, -0x1DD4($at)
    MEM_W(-0X1DD4, ctx->r1) = ctx->r2;
    // 0x8018D258: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D25C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018D260: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D268: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D26C: jal         0x80009DF4
    // 0x8018D270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D274: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8018D278: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
    // 0x8018D27C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8018D280: beq         $t6, $zero, L_8018D2FC
    if (ctx->r14 == 0) {
        // 0x8018D284: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2FC;
    }
    // 0x8018D284: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D288: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D28C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D290: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D294: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D298: addiu       $s2, $s2, -0x1BC0
    ctx->r18 = ADD32(ctx->r18, -0X1BC0);
    // 0x8018D29C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018D2A0: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D2A4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_8018D2A8:
    // 0x8018D2A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D2AC: jal         0x800CCFDC
    // 0x8018D2B0: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D2B0: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    after_2:
    // 0x8018D2B4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D2B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D2BC: and         $t1, $t9, $s3
    ctx->r9 = ctx->r25 & ctx->r19;
    // 0x8018D2C0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2C4: ori         $t0, $t1, 0x1
    ctx->r8 = ctx->r9 | 0X1;
    // 0x8018D2C8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2CC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D2D0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2D4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018D2D8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D2DC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8018D2E0: jal         0x8018D160
    // 0x8018D2E4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    mvOpeningKirbyInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2E4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_3:
    // 0x8018D2E8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8018D2EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8018D2F4: bnel        $v0, $zero, L_8018D2A8
    if (ctx->r2 != 0) {
        // 0x8018D2F8: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_8018D2A8;
    }
    goto skip_0;
    // 0x8018D2F8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2FC:
    // 0x8018D2FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D300: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D304: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D308: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D30C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D310: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D314: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D318: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D31C: jr          $ra
    // 0x8018D320: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8018D320: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void ftNessSpecialLwCheckRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801551E0: lhu         $t6, 0x1BC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BC);
    // 0x801551E4: lhu         $t7, 0x1B6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1B6);
    // 0x801551E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801551EC: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801551F0: bne         $t8, $zero, L_801551FC
    if (ctx->r24 != 0) {
        // 0x801551F4: nop
    
            goto L_801551FC;
    }
    // 0x801551F4: nop

    // 0x801551F8: sw          $t9, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = ctx->r25;
L_801551FC:
    // 0x801551FC: jr          $ra
    // 0x80155200: nop

    return;
    // 0x80155200: nop

;}
RECOMP_FUNC void scStaffrollFuncDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013511C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135120: jal         0x8000A340
    // 0x80135124: nop

    gcDrawAll(rdram, ctx);
        goto after_0;
    // 0x80135124: nop

    after_0:
    // 0x80135128: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013512C: addiu       $a0, $a0, -0x56F8
    ctx->r4 = ADD32(ctx->r4, -0X56F8);
    // 0x80135130: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80135134: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135138: beq         $v0, $zero, L_80135164
    if (ctx->r2 == 0) {
        // 0x8013513C: nop
    
            goto L_80135164;
    }
    // 0x8013513C: nop

    // 0x80135140: lw          $v1, -0x5740($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5740);
    // 0x80135144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80135148: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8013514C: beq         $v1, $at, L_8013515C
    if (ctx->r3 == ctx->r1) {
        // 0x80135150: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8013515C;
    }
    // 0x80135150: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80135154: bne         $v1, $at, L_80135164
    if (ctx->r3 != ctx->r1) {
        // 0x80135158: nop
    
            goto L_80135164;
    }
    // 0x80135158: nop

L_8013515C:
    // 0x8013515C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80135160: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80135164:
    // 0x80135164: bne         $v0, $zero, L_80135174
    if (ctx->r2 != 0) {
        // 0x80135168: nop
    
            goto L_80135174;
    }
    // 0x80135168: nop

    // 0x8013516C: jal         0x80005C74
    // 0x80135170: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80135170: nop

    after_1:
L_80135174:
    // 0x80135174: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135178: lw          $t7, -0x5740($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5740);
    // 0x8013517C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80135180: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x80135184: bne         $t7, $at, L_801351A8
    if (ctx->r15 != ctx->r1) {
        // 0x80135188: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_801351A8;
    }
    // 0x80135188: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8013518C: jal         0x80020A74
    // 0x80135190: sb          $t8, 0x4AD0($at)
    MEM_B(0X4AD0, ctx->r1) = ctx->r24;
    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x80135190: sb          $t8, 0x4AD0($at)
    MEM_B(0X4AD0, ctx->r1) = ctx->r24;
    after_2:
    // 0x80135194: jal         0x80006E18
    // 0x80135198: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    syVideoSetFlags(rdram, ctx);
        goto after_3;
    // 0x80135198: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x8013519C: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x801351A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801351A4: sw          $t9, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r25;
L_801351A8:
    // 0x801351A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801351AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801351B0: jr          $ra
    // 0x801351B4: nop

    return;
    // 0x801351B4: nop

;}
RECOMP_FUNC void wpPikachuThunderHeadMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A80C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016A810: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016A814: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016A818: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8016A81C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A820: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016A824: addiu       $a1, $a1, -0x6EE0
    ctx->r5 = ADD32(ctx->r5, -0X6EE0);
    // 0x8016A828: jal         0x801655C8
    // 0x8016A82C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016A82C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8016A830: bne         $v0, $zero, L_8016A840
    if (ctx->r2 != 0) {
        // 0x8016A834: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8016A840;
    }
    // 0x8016A834: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8016A838: b           L_8016A8C8
    // 0x8016A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016A8C8;
    // 0x8016A83C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A840:
    // 0x8016A840: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x8016A844: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8016A848: addiu       $t6, $t6, -0x5818
    ctx->r14 = ADD32(ctx->r14, -0X5818);
    // 0x8016A84C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8016A850: sw          $t6, 0x298($a0)
    MEM_W(0X298, ctx->r4) = ctx->r14;
    // 0x8016A854: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    // 0x8016A858: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8016A85C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8016A860: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8016A864: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8016A868: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8016A86C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8016A870: sw          $zero, 0x100($a0)
    MEM_W(0X100, ctx->r4) = 0;
    // 0x8016A874: sw          $zero, 0x29C($a0)
    MEM_W(0X29C, ctx->r4) = 0;
    // 0x8016A878: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x8016A87C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8016A880: jal         0x801655A0
    // 0x8016A884: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpManagerGetGroupID(rdram, ctx);
        goto after_1;
    // 0x8016A884: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8016A888: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A88C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8016A890: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8016A894: sw          $v0, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r2;
    // 0x8016A898: lw          $t2, 0x74($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X74);
    // 0x8016A89C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8016A8A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016A8A4: lw          $t3, 0x80($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X80);
    // 0x8016A8A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8016A8AC: sh          $t1, 0x80($t3)
    MEM_H(0X80, ctx->r11) = ctx->r9;
    // 0x8016A8B0: lw          $t4, 0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X74);
    // 0x8016A8B4: swc1        $f0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f0.u32l;
    // 0x8016A8B8: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x8016A8BC: swc1        $f0, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f0.u32l;
    // 0x8016A8C0: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x8016A8C4: swc1        $f0, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f0.u32l;
L_8016A8C8:
    // 0x8016A8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A8CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016A8D0: jr          $ra
    // 0x8016A8D4: nop

    return;
    // 0x8016A8D4: nop

;}
RECOMP_FUNC void ftMarioSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015605C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80156060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80156064: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80156068: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015606C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156070: jal         0x800E6F24
    // 0x80156074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80156078: jal         0x800E0830
    // 0x8015607C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015607C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80156080: jal         0x80155FFC
    // 0x80156084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMarioSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015608C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156090: jr          $ra
    // 0x80156094: nop

    return;
    // 0x80156094: nop

;}
RECOMP_FUNC void itNessPKFireWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185710: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80185714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185718: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018571C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80185720: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80185724: jal         0x80173F54
    // 0x80185728: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    itMapSetGround(rdram, ctx);
        goto after_0;
    // 0x80185728: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8018572C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80185730: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80185734: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x80185738: addiu       $v0, $a3, 0x15C
    ctx->r2 = ADD32(ctx->r7, 0X15C);
    // 0x8018573C: swc1        $f0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f0.u32l;
    // 0x80185740: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x80185744: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x80185748: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8018574C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80185750: addiu       $a1, $a1, -0x498C
    ctx->r5 = ADD32(ctx->r5, -0X498C);
    // 0x80185754: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80185758: lhu         $t0, 0x15E($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X15E);
    // 0x8018575C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80185760: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80185764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80185768: jal         0x80172EC8
    // 0x8018576C: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018576C: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    after_1:
    // 0x80185770: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80185774: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80185778: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8018577C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80185780: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80185784: lhu         $t4, 0x1E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1E);
    // 0x80185788: sh          $t4, 0x15E($a3)
    MEM_H(0X15E, ctx->r7) = ctx->r12;
    // 0x8018578C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80185794: jr          $ra
    // 0x80185798: nop

    return;
    // 0x80185798: nop

;}
RECOMP_FUNC void ftDisplayMainDecideFogDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1C08: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800F1C0C: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800F1C10: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800F1C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1C18: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x800F1C1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800F1C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F1C28: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800F1C2C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800F1C30: andi        $t8, $a2, 0x40
    ctx->r24 = ctx->r6 & 0X40;
    // 0x800F1C34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800F1C38: beq         $t8, $zero, L_800F1C68
    if (ctx->r24 == 0) {
        // 0x800F1C3C: sw          $zero, 0x4($v0)
        MEM_W(0X4, ctx->r2) = 0;
            goto L_800F1C68;
    }
    // 0x800F1C3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800F1C40: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800F1C44: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x800F1C48: lui         $t1, 0xC19
    ctx->r9 = S32(0XC19 << 16);
    // 0x800F1C4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800F1C50: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800F1C54: ori         $t1, $t1, 0x2078
    ctx->r9 = ctx->r9 | 0X2078;
    // 0x800F1C58: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x800F1C5C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800F1C60: b           L_800F1D34
    // 0x800F1C64: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800F1D34;
    // 0x800F1C64: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800F1C68:
    // 0x800F1C68: lw          $t2, 0xA88($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XA88);
    // 0x800F1C6C: andi        $t4, $a2, 0x80
    ctx->r12 = ctx->r6 & 0X80;
    // 0x800F1C70: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x800F1C74: beq         $t3, $zero, L_800F1CD8
    if (ctx->r11 == 0) {
        // 0x800F1C78: nop
    
            goto L_800F1CD8;
    }
    // 0x800F1C78: nop

    // 0x800F1C7C: beq         $t4, $zero, L_800F1CB4
    if (ctx->r12 == 0) {
        // 0x800F1C80: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800F1CB4;
    }
    // 0x800F1C80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F1C84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F1C88: addiu       $v0, $v0, 0x12F1
    ctx->r2 = ADD32(ctx->r2, 0X12F1);
    // 0x800F1C8C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x800F1C90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800F1C94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F1C98: bne         $t5, $zero, L_800F1CD8
    if (ctx->r13 != 0) {
        // 0x800F1C9C: nop
    
            goto L_800F1CD8;
    }
    // 0x800F1C9C: nop

    // 0x800F1CA0: jal         0x800F1B7C
    // 0x800F1CA4: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    ftDisplayMainDecideFogColor(rdram, ctx);
        goto after_0;
    // 0x800F1CA4: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x800F1CA8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800F1CAC: b           L_800F1CD8
    // 0x800F1CB0: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
        goto L_800F1CD8;
    // 0x800F1CB0: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
L_800F1CB4:
    // 0x800F1CB4: addiu       $v0, $v0, 0x12F1
    ctx->r2 = ADD32(ctx->r2, 0X12F1);
    // 0x800F1CB8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800F1CBC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800F1CC0: beq         $t7, $zero, L_800F1CD8
    if (ctx->r15 == 0) {
        // 0x800F1CC4: nop
    
            goto L_800F1CD8;
    }
    // 0x800F1CC4: nop

    // 0x800F1CC8: jal         0x800F1B24
    // 0x800F1CCC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    ftDisplayMainSetFogColor(rdram, ctx);
        goto after_1;
    // 0x800F1CCC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_1:
    // 0x800F1CD0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800F1CD4: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
L_800F1CD8:
    // 0x800F1CD8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F1CDC: lbu         $t8, 0x12F0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X12F0);
    // 0x800F1CE0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800F1CE4: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x800F1CE8: bne         $t8, $at, L_800F1D18
    if (ctx->r24 != ctx->r1) {
        // 0x800F1CEC: ori         $t3, $t3, 0x1C
        ctx->r11 = ctx->r11 | 0X1C;
            goto L_800F1D18;
    }
    // 0x800F1CEC: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x800F1CF0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800F1CF4: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x800F1CF8: lui         $t1, 0xC411
    ctx->r9 = S32(0XC411 << 16);
    // 0x800F1CFC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800F1D00: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800F1D04: ori         $t1, $t1, 0x2078
    ctx->r9 = ctx->r9 | 0X2078;
    // 0x800F1D08: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x800F1D0C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800F1D10: b           L_800F1D34
    // 0x800F1D14: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800F1D34;
    // 0x800F1D14: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800F1D18:
    // 0x800F1D18: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800F1D1C: lui         $t4, 0xC410
    ctx->r12 = S32(0XC410 << 16);
    // 0x800F1D20: ori         $t4, $t4, 0x49D8
    ctx->r12 = ctx->r12 | 0X49D8;
    // 0x800F1D24: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800F1D28: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800F1D2C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800F1D30: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800F1D34:
    // 0x800F1D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1D3C: jr          $ra
    // 0x800F1D40: nop

    return;
    // 0x800F1D40: nop

;}
RECOMP_FUNC void func_ovl8_8037D470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D470: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8037D474: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8037D478: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D47C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8037D480: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8037D484: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8037D488: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8037D48C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D490: beq         $a0, $zero, L_8037D50C
    if (ctx->r4 == 0) {
        // 0x8037D494: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037D50C;
    }
    // 0x8037D494: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037D498: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8037D49C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8037D4A0:
    // 0x8037D4A0: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8037D4A4: beq         $t6, $zero, L_8037D4B8
    if (ctx->r14 == 0) {
        // 0x8037D4A8: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8037D4B8;
    }
    // 0x8037D4A8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8037D4AC: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x8037D4B0: b           L_8037D4C4
    // 0x8037D4B4: andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
        goto L_8037D4C4;
    // 0x8037D4B4: andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
L_8037D4B8:
    // 0x8037D4B8: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x8037D4BC: sra         $a2, $a2, 4
    ctx->r6 = S32(SIGNED(ctx->r6) >> 4);
    // 0x8037D4C0: andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
L_8037D4C4:
    // 0x8037D4C4: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    // 0x8037D4C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037D4CC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8037D4D0: beq         $t7, $zero, L_8037D4E0
    if (ctx->r15 == 0) {
        // 0x8037D4D4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037D4E0;
    }
    // 0x8037D4D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D4D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D4DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037D4E0:
    // 0x8037D4E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037D4E4: bne         $v1, $t0, L_8037D500
    if (ctx->r3 != ctx->r8) {
        // 0x8037D4E8: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8037D500;
    }
    // 0x8037D4E8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8037D4EC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8037D4F0: beq         $v1, $zero, L_8037D4FC
    if (ctx->r3 == 0) {
        // 0x8037D4F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8037D4FC;
    }
    // 0x8037D4F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D4F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8037D4FC:
    // 0x8037D4FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037D500:
    // 0x8037D500: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D504: bnel        $a0, $zero, L_8037D4A0
    if (ctx->r4 != 0) {
        // 0x8037D508: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8037D4A0;
    }
    goto skip_0;
    // 0x8037D508: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    skip_0:
L_8037D50C:
    // 0x8037D50C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8037D510: jr          $ra
    // 0x8037D514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8037D514: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}

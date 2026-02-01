#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void scStaffrollSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801349DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801349E0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801349E4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801349E8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801349EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801349F0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801349F4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801349F8: addiu       $t8, $t8, -0x56F0
    ctx->r24 = ADD32(ctx->r24, -0X56F0);
    // 0x801349FC: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80134A00: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80134A04: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80134A08: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80134A0C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134A10: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80134A14: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80134A18: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80134A1C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80134A20: jal         0x800CDF78
    // 0x80134A24: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80134A24: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80134A28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134A2C: addiu       $a0, $a0, -0x5E7C
    ctx->r4 = ADD32(ctx->r4, -0X5E7C);
    // 0x80134A30: jal         0x800CDEEC
    // 0x80134A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80134A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80134A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134A3C: jal         0x80004980
    // 0x80134A40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134A40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80134A44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134A48: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80134A4C: addiu       $a2, $a2, -0x55F0
    ctx->r6 = ADD32(ctx->r6, -0X55F0);
    // 0x80134A50: addiu       $a0, $a0, -0x5E7C
    ctx->r4 = ADD32(ctx->r4, -0X5E7C);
    // 0x80134A54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80134A58: jal         0x800CDE04
    // 0x80134A5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134A5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134A64: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134A68: jr          $ra
    // 0x80134A6C: nop

    return;
    // 0x80134A6C: nop

;}
RECOMP_FUNC void func_ovl8_80377F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377F94: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80377F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377F9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377FA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377FA4: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80377FA8: addiu       $a2, $a2, -0x60A4
    ctx->r6 = ADD32(ctx->r6, -0X60A4);
    // 0x80377FAC: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    // 0x80377FB0: jal         0x80376B60
    // 0x80377FB4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_ovl8_80376B60(rdram, ctx);
        goto after_0;
    // 0x80377FB4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80377FB8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80377FBC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377FC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80377FC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80377FC8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80377FCC: jal         0x80377FE4
    // 0x80377FD0: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    func_ovl8_80377FE4(rdram, ctx);
        goto after_1;
    // 0x80377FD0: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    after_1:
    // 0x80377FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377FDC: jr          $ra
    // 0x80377FE0: nop

    return;
    // 0x80377FE0: nop

;}
RECOMP_FUNC void ftParamSetVelPush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E86B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E86B8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800E86BC: sw          $t7, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r15;
    // 0x800E86C0: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800E86C4: sw          $t6, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r14;
    // 0x800E86C8: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800E86CC: jr          $ra
    // 0x800E86D0: sw          $t7, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r15;
    return;
    // 0x800E86D0: sw          $t7, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mpCommonRunFighterAllCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDC50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DDC54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDC58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DDC5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DDC60: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800DDC64: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x800DDC68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DDC6C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800DDC70: jal         0x800DA294
    // 0x800DDC74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpProcessCheckTestLWallCollision(rdram, ctx);
        goto after_0;
    // 0x800DDC74: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DDC78: beq         $v0, $zero, L_800DDC90
    if (ctx->r2 == 0) {
        // 0x800DDC7C: nop
    
            goto L_800DDC90;
    }
    // 0x800DDC7C: nop

    // 0x800DDC80: jal         0x800DA658
    // 0x800DDC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollision(rdram, ctx);
        goto after_1;
    // 0x800DDC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800DDC88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DDC8C: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_800DDC90:
    // 0x800DDC90: jal         0x800DAAA8
    // 0x800DDC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollision(rdram, ctx);
        goto after_2;
    // 0x800DDC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800DDC98: beq         $v0, $zero, L_800DDCB0
    if (ctx->r2 == 0) {
        // 0x800DDC9C: nop
    
            goto L_800DDCB0;
    }
    // 0x800DDC9C: nop

    // 0x800DDCA0: jal         0x800DAE6C
    // 0x800DDCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollision(rdram, ctx);
        goto after_3;
    // 0x800DDCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800DDCA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DDCAC: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_800DDCB0:
    // 0x800DDCB0: jal         0x800DB2BC
    // 0x800DDCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestFloorCollisionNew(rdram, ctx);
        goto after_4;
    // 0x800DDCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800DDCB8: beql        $v0, $zero, L_800DDCE8
    if (ctx->r2 == 0) {
        // 0x800DDCBC: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_800DDCE8;
    }
    goto skip_0;
    // 0x800DDCBC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x800DDCC0: lhu         $t9, 0x5A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DDCC4: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x800DDCC8: beql        $t0, $zero, L_800DDD44
    if (ctx->r8 == 0) {
        // 0x800DDCCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800DDD44;
    }
    goto skip_1;
    // 0x800DDCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800DDCD0: jal         0x800D9F84
    // 0x800DDCD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_5;
    // 0x800DDCD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800DDCD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DDCDC: b           L_800DDD40
    // 0x800DDCE0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_800DDD40;
    // 0x800DDCE0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800DDCE4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800DDCE8:
    // 0x800DDCE8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800DDCEC: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x800DDCF0: beq         $t2, $zero, L_800DDD0C
    if (ctx->r10 == 0) {
        // 0x800DDCF4: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_800DDD0C;
    }
    // 0x800DDCF4: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x800DDCF8: jal         0x800DD820
    // 0x800DDCFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mpCommonCheckSetFighterCliffEdge(rdram, ctx);
        goto after_6;
    // 0x800DDCFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x800DDD00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DDD04: b           L_800DDD40
    // 0x800DDD08: sw          $t3, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r11;
        goto L_800DDD40;
    // 0x800DDD08: sw          $t3, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r11;
L_800DDD0C:
    // 0x800DDD0C: beq         $t4, $zero, L_800DDD3C
    if (ctx->r12 == 0) {
        // 0x800DDD10: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800DDD3C;
    }
    // 0x800DDD10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DDD14: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800DDD18: jal         0x800DDA6C
    // 0x800DDD1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mpCommonCheckSetFighterEdge(rdram, ctx);
        goto after_7;
    // 0x800DDD1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x800DDD20: beq         $v0, $zero, L_800DDD34
    if (ctx->r2 == 0) {
        // 0x800DDD24: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800DDD34;
    }
    // 0x800DDD24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DDD28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DDD2C: b           L_800DDD40
    // 0x800DDD30: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
        goto L_800DDD40;
    // 0x800DDD30: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_800DDD34:
    // 0x800DDD34: b           L_800DDD40
    // 0x800DDD38: sw          $t6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r14;
        goto L_800DDD40;
    // 0x800DDD38: sw          $t6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r14;
L_800DDD3C:
    // 0x800DDD3C: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_800DDD40:
    // 0x800DDD40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800DDD44:
    // 0x800DDD44: jal         0x800DB474
    // 0x800DDD48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mpProcessCheckTestFloorCollision(rdram, ctx);
        goto after_8;
    // 0x800DDD48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x800DDD4C: beql        $v0, $zero, L_800DDD98
    if (ctx->r2 == 0) {
        // 0x800DDD50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDD98;
    }
    goto skip_2;
    // 0x800DDD50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800DDD54: jal         0x800DD59C
    // 0x800DDD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_9;
    // 0x800DDD58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800DDD5C: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DDD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DDD64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DDD68: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x800DDD6C: beql        $t8, $zero, L_800DDD84
    if (ctx->r24 == 0) {
        // 0x800DDD70: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800DDD84;
    }
    goto skip_3;
    // 0x800DDD70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    skip_3:
    // 0x800DDD74: jal         0x800D9F84
    // 0x800DDD78: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_10;
    // 0x800DDD78: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_10:
    // 0x800DDD7C: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DDD80: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
L_800DDD84:
    // 0x800DDD84: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800DDD88: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x800DDD8C: sh          $t0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r8;
    // 0x800DDD90: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x800DDD94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DDD98:
    // 0x800DDD98: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800DDD9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DDDA0: jr          $ra
    // 0x800DDDA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DDDA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayers1PBonusMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801365B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801365BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801365C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801365C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801365C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801365CC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x801365D0: jal         0x80009968
    // 0x801365D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801365D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801365D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801365DC: lw          $t6, 0x7E20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E20);
    // 0x801365E0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801365E4: addiu       $t7, $t7, 0x568
    ctx->r15 = ADD32(ctx->r15, 0X568);
    // 0x801365E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801365EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801365F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801365F4: jal         0x8000F120
    // 0x801365F8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x801365F8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x801365FC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80136600: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80136604: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80136608: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x8013660C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136610: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80136614: jal         0x80009DF4
    // 0x80136618: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80136618: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x8013661C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80136620: lw          $t9, 0x7E20($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E20);
    // 0x80136624: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80136628: addiu       $t0, $t0, 0x408
    ctx->r8 = ADD32(ctx->r8, 0X408);
    // 0x8013662C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136630: jal         0x8000F8F4
    // 0x80136634: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80136634: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80136638: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013663C: addiu       $a1, $a1, 0x64E0
    ctx->r5 = ADD32(ctx->r5, 0X64E0);
    // 0x80136640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136648: jal         0x80008188
    // 0x8013664C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8013664C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80136650: jal         0x8000DF34
    // 0x80136654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80136654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80136658: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x8013665C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136660: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80136664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136668: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8013666C: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x80136670: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80136674: lwc1        $f6, 0x7638($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7638);
    // 0x80136678: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x8013667C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80136680: swc1        $f8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f8.u32l;
    // 0x80136684: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136688: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013668C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80136690: jr          $ra
    // 0x80136694: nop

    return;
    // 0x80136694: nop

;}
RECOMP_FUNC void efManagerFoxEntryArwingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103788: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8010378C: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x80103790: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80103794: jal         0x8000DF34
    // 0x80103798: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80103798: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010379C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801037A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801037A4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801037A8: lwc1        $f6, 0x7C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X7C);
    // 0x801037AC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801037B0: nop

    // 0x801037B4: bc1f        L_801037D4
    if (!c1cs) {
        // 0x801037B8: nop
    
            goto L_801037D4;
    }
    // 0x801037B8: nop

    // 0x801037BC: jal         0x800FD4F8
    // 0x801037C0: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x801037C0: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    after_1:
    // 0x801037C4: jal         0x80009A84
    // 0x801037C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x801037C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801037CC: b           L_801037E0
    // 0x801037D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801037E0;
    // 0x801037D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801037D4:
    // 0x801037D4: jal         0x800FD60C
    // 0x801037D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    efManagerSortZNeg(rdram, ctx);
        goto after_3;
    // 0x801037D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x801037DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801037E0:
    // 0x801037E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801037E4: jr          $ra
    // 0x801037E8: nop

    return;
    // 0x801037E8: nop

;}
RECOMP_FUNC void efManagerKirbyEntryStarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102BA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80102BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102BA8: bne         $a1, $at, L_80102BC8
    if (ctx->r5 != ctx->r1) {
        // 0x80102BAC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80102BC8;
    }
    // 0x80102BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102BB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102BB4: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80102BB8: addiu       $t6, $t6, 0x1EA0
    ctx->r14 = ADD32(ctx->r14, 0X1EA0);
    // 0x80102BBC: addiu       $a0, $a0, -0x1ACC
    ctx->r4 = ADD32(ctx->r4, -0X1ACC);
    // 0x80102BC0: b           L_80102BDC
    // 0x80102BC4: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
        goto L_80102BDC;
    // 0x80102BC4: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
L_80102BC8:
    // 0x80102BC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102BCC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80102BD0: addiu       $t7, $t7, 0x1E30
    ctx->r15 = ADD32(ctx->r15, 0X1E30);
    // 0x80102BD4: addiu       $a0, $a0, -0x1ACC
    ctx->r4 = ADD32(ctx->r4, -0X1ACC);
    // 0x80102BD8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
L_80102BDC:
    // 0x80102BDC: jal         0x800FDAFC
    // 0x80102BE0: nop

    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102BE0: nop

    after_0:
    // 0x80102BE4: bne         $v0, $zero, L_80102BF4
    if (ctx->r2 != 0) {
        // 0x80102BE8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102BF4;
    }
    // 0x80102BE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102BEC: b           L_80102C18
    // 0x80102BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102C18;
    // 0x80102BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102BF4:
    // 0x80102BF4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80102BF8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102BFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102C00: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80102C04: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x80102C08: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80102C0C: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80102C10: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80102C14: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
L_80102C18:
    // 0x80102C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102C20: jr          $ra
    // 0x80102C24: nop

    return;
    // 0x80102C24: nop

;}
RECOMP_FUNC void syDmaReadVpk0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003690: addiu       $sp, $sp, -0x418
    ctx->r29 = ADD32(ctx->r29, -0X418);
    // 0x80003694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003698: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8000369C: jal         0x80003648
    // 0x800036A0: addiu       $a3, $zero, 0x400
    ctx->r7 = ADD32(0, 0X400);
    syDmaReadVpk0Buf(rdram, ctx);
        goto after_0;
    // 0x800036A0: addiu       $a3, $zero, 0x400
    ctx->r7 = ADD32(0, 0X400);
    after_0:
    // 0x800036A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800036A8: addiu       $sp, $sp, 0x418
    ctx->r29 = ADD32(ctx->r29, 0X418);
    // 0x800036AC: jr          $ra
    // 0x800036B0: nop

    return;
    // 0x800036B0: nop

;}
RECOMP_FUNC void lbCommonPrepSObjAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC118: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CC11C: addiu       $t0, $t0, 0x62B0
    ctx->r8 = ADD32(ctx->r8, 0X62B0);
    // 0x800CC120: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x800CC124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CC128: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CC12C: andi        $t7, $a2, 0x800
    ctx->r15 = ctx->r6 & 0X800;
    // 0x800CC130: beq         $t7, $zero, L_800CC27C
    if (ctx->r15 == 0) {
        // 0x800CC134: addiu       $v1, $a1, 0x10
        ctx->r3 = ADD32(ctx->r5, 0X10);
            goto L_800CC27C;
    }
    // 0x800CC134: addiu       $v1, $a1, 0x10
    ctx->r3 = ADD32(ctx->r5, 0X10);
    // 0x800CC138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC13C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800CC140: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800CC144: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CC148: addiu       $v1, $a1, 0x10
    ctx->r3 = ADD32(ctx->r5, 0X10);
    // 0x800CC14C: lhu         $t8, 0x14($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC150: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC158: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800CC15C: beq         $t9, $zero, L_800CC184
    if (ctx->r25 == 0) {
        // 0x800CC160: lui         $t7, 0xE300
        ctx->r15 = S32(0XE300 << 16);
            goto L_800CC184;
    }
    // 0x800CC160: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800CC164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC168: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800CC16C: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x800CC170: lui         $t6, 0x20
    ctx->r14 = S32(0X20 << 16);
    // 0x800CC174: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CC178: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CC17C: b           L_800CC194
    // 0x800CC180: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC194;
    // 0x800CC180: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC184:
    // 0x800CC184: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x800CC188: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC18C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC190: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800CC194:
    // 0x800CC194: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC198: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800CC19C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800CC1A0: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // 0x800CC1A4: beq         $a0, $zero, L_800CC1C4
    if (ctx->r4 == 0) {
        // 0x800CC1A8: lui         $t9, 0x50
        ctx->r25 = S32(0X50 << 16);
            goto L_800CC1C4;
    }
    // 0x800CC1A8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x800CC1AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC1B0: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x800CC1B4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC1B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC1BC: b           L_800CC20C
    // 0x800CC1C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC20C;
    // 0x800CC1C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC1C4:
    // 0x800CC1C4: beq         $a0, $zero, L_800CC1F0
    if (ctx->r4 == 0) {
        // 0x800CC1C8: lui         $t7, 0xE200
        ctx->r15 = S32(0XE200 << 16);
            goto L_800CC1F0;
    }
    // 0x800CC1C8: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800CC1CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC1D0: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x800CC1D4: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800CC1D8: ori         $t6, $t6, 0x4340
    ctx->r14 = ctx->r14 | 0X4340;
    // 0x800CC1DC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x800CC1E0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CC1E4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CC1E8: b           L_800CC20C
    // 0x800CC1EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC20C;
    // 0x800CC1EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC1F0:
    // 0x800CC1F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC1F4: lui         $t8, 0xF0A
    ctx->r24 = S32(0XF0A << 16);
    // 0x800CC1F8: ori         $t8, $t8, 0x4000
    ctx->r24 = ctx->r24 | 0X4000;
    // 0x800CC1FC: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x800CC200: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC204: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CC208: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC20C:
    // 0x800CC20C: lhu         $t9, 0x14($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC210: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CC214: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800CC218: andi        $t5, $t9, 0x80
    ctx->r13 = ctx->r25 & 0X80;
    // 0x800CC21C: beq         $t5, $zero, L_800CC244
    if (ctx->r13 == 0) {
        // 0x800CC220: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC244;
    }
    // 0x800CC220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC228: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800CC22C: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x800CC230: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x800CC234: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC238: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CC23C: b           L_800CC254
    // 0x800CC240: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC254;
    // 0x800CC240: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC244:
    // 0x800CC244: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800CC248: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC24C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC250: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800CC254:
    // 0x800CC254: lbu         $t5, 0x30($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X30);
    // 0x800CC258: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800CC25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC260: beq         $a2, $t5, L_800CC430
    if (ctx->r6 == ctx->r13) {
        // 0x800CC264: lui         $t6, 0xE300
        ctx->r14 = S32(0XE300 << 16);
            goto L_800CC430;
    }
    // 0x800CC264: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800CC268: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x800CC26C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CC270: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC274: b           L_800CC430
    // 0x800CC278: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
        goto L_800CC430;
    // 0x800CC278: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_800CC27C:
    // 0x800CC27C: andi        $t7, $a2, 0x400
    ctx->r15 = ctx->r6 & 0X400;
    // 0x800CC280: beql        $t7, $zero, L_800CC29C
    if (ctx->r15 == 0) {
        // 0x800CC284: lhu         $a0, 0x14($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X14);
            goto L_800CC29C;
    }
    goto skip_0;
    // 0x800CC284: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
    skip_0:
    // 0x800CC288: lhu         $t8, 0x24($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X24);
    // 0x800CC28C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC290: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x800CC294: sh          $t9, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r25;
    // 0x800CC298: lhu         $a0, 0x14($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X14);
L_800CC29C:
    // 0x800CC29C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC2A0: andi        $t5, $a0, 0x400
    ctx->r13 = ctx->r4 & 0X400;
    // 0x800CC2A4: beq         $t5, $zero, L_800CC2B4
    if (ctx->r13 == 0) {
        // 0x800CC2A8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CC2B4;
    }
    // 0x800CC2A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CC2AC: sh          $a0, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r4;
    // 0x800CC2B0: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
L_800CC2B4:
    // 0x800CC2B4: lhu         $a2, 0x0($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X0);
    // 0x800CC2B8: andi        $t6, $a3, 0x20
    ctx->r14 = ctx->r7 & 0X20;
    // 0x800CC2BC: beq         $a2, $a3, L_800CC430
    if (ctx->r6 == ctx->r7) {
        // 0x800CC2C0: nop
    
            goto L_800CC430;
    }
    // 0x800CC2C0: nop

    // 0x800CC2C4: beq         $t6, $zero, L_800CC300
    if (ctx->r14 == 0) {
        // 0x800CC2C8: andi        $t5, $a2, 0x20
        ctx->r13 = ctx->r6 & 0X20;
            goto L_800CC300;
    }
    // 0x800CC2C8: andi        $t5, $a2, 0x20
    ctx->r13 = ctx->r6 & 0X20;
    // 0x800CC2CC: andi        $t7, $a2, 0x20
    ctx->r15 = ctx->r6 & 0X20;
    // 0x800CC2D0: bne         $t7, $zero, L_800CC328
    if (ctx->r15 != 0) {
        // 0x800CC2D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC328;
    }
    // 0x800CC2D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC2D8: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CC2DC: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800CC2E0: lui         $t9, 0x20
    ctx->r25 = S32(0X20 << 16);
    // 0x800CC2E4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC2E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC2EC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC2F0: lhu         $a2, 0x62B0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X62B0);
    // 0x800CC2F4: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC2F8: b           L_800CC328
    // 0x800CC2FC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC328;
    // 0x800CC2FC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC300:
    // 0x800CC300: beq         $t5, $zero, L_800CC328
    if (ctx->r13 == 0) {
        // 0x800CC304: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC328;
    }
    // 0x800CC304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC308: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800CC30C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x800CC310: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CC314: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CC318: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC31C: lhu         $a2, 0x62B0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X62B0);
    // 0x800CC320: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC324: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC328:
    // 0x800CC328: andi        $t7, $a3, 0x1
    ctx->r15 = ctx->r7 & 0X1;
    // 0x800CC32C: beq         $t7, $zero, L_800CC36C
    if (ctx->r15 == 0) {
        // 0x800CC330: andi        $t6, $a3, 0x1000
        ctx->r14 = ctx->r7 & 0X1000;
            goto L_800CC36C;
    }
    // 0x800CC330: andi        $t6, $a3, 0x1000
    ctx->r14 = ctx->r7 & 0X1000;
    // 0x800CC334: andi        $t8, $a2, 0x1
    ctx->r24 = ctx->r6 & 0X1;
    // 0x800CC338: bne         $t8, $zero, L_800CC3DC
    if (ctx->r24 != 0) {
        // 0x800CC33C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC3DC;
    }
    // 0x800CC33C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC340: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800CC344: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x800CC348: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x800CC34C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800CC350: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CC354: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800CC358: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC35C: lhu         $a2, 0x62B0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X62B0);
    // 0x800CC360: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC364: b           L_800CC3DC
    // 0x800CC368: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC3DC;
    // 0x800CC368: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC36C:
    // 0x800CC36C: beq         $t6, $zero, L_800CC3AC
    if (ctx->r14 == 0) {
        // 0x800CC370: andi        $t5, $a2, 0x1001
        ctx->r13 = ctx->r6 & 0X1001;
            goto L_800CC3AC;
    }
    // 0x800CC370: andi        $t5, $a2, 0x1001
    ctx->r13 = ctx->r6 & 0X1001;
    // 0x800CC374: andi        $t7, $a2, 0x1000
    ctx->r15 = ctx->r6 & 0X1000;
    // 0x800CC378: bne         $t7, $zero, L_800CC3DC
    if (ctx->r15 != 0) {
        // 0x800CC37C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC3DC;
    }
    // 0x800CC37C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC380: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800CC384: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x800CC388: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x800CC38C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800CC390: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC394: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC398: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC39C: lhu         $a2, 0x62B0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X62B0);
    // 0x800CC3A0: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC3A4: b           L_800CC3DC
    // 0x800CC3A8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC3DC;
    // 0x800CC3A8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC3AC:
    // 0x800CC3AC: beq         $t5, $zero, L_800CC3DC
    if (ctx->r13 == 0) {
        // 0x800CC3B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC3DC;
    }
    // 0x800CC3B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC3B4: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800CC3B8: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x800CC3BC: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x800CC3C0: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x800CC3C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CC3C8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC3CC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CC3D0: lhu         $a2, 0x62B0($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X62B0);
    // 0x800CC3D4: lhu         $a3, 0x14($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X14);
    // 0x800CC3D8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC3DC:
    // 0x800CC3DC: andi        $t8, $a3, 0x80
    ctx->r24 = ctx->r7 & 0X80;
    // 0x800CC3E0: beq         $t8, $zero, L_800CC410
    if (ctx->r24 == 0) {
        // 0x800CC3E4: andi        $t7, $a2, 0x80
        ctx->r15 = ctx->r6 & 0X80;
            goto L_800CC410;
    }
    // 0x800CC3E4: andi        $t7, $a2, 0x80
    ctx->r15 = ctx->r6 & 0X80;
    // 0x800CC3E8: andi        $t9, $a2, 0x80
    ctx->r25 = ctx->r6 & 0X80;
    // 0x800CC3EC: bne         $t9, $zero, L_800CC430
    if (ctx->r25 != 0) {
        // 0x800CC3F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC430;
    }
    // 0x800CC3F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC3F4: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800CC3F8: ori         $t5, $t5, 0x1201
    ctx->r13 = ctx->r13 | 0X1201;
    // 0x800CC3FC: addiu       $t6, $zero, 0x3000
    ctx->r14 = ADD32(0, 0X3000);
    // 0x800CC400: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CC404: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CC408: b           L_800CC430
    // 0x800CC40C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC430;
    // 0x800CC40C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC410:
    // 0x800CC410: beq         $t7, $zero, L_800CC430
    if (ctx->r15 == 0) {
        // 0x800CC414: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC430;
    }
    // 0x800CC414: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC418: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CC41C: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800CC420: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800CC424: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC428: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC42C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC430:
    // 0x800CC430: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800CC434: addiu       $a3, $a3, 0x62B2
    ctx->r7 = ADD32(ctx->r7, 0X62B2);
    // 0x800CC438: lhu         $t5, 0x0($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X0);
    // 0x800CC43C: lbu         $t1, 0x30($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X30);
    // 0x800CC440: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800CC444: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800CC448: beq         $t5, $t1, L_800CC67C
    if (ctx->r13 == ctx->r9) {
        // 0x800CC44C: nop
    
            goto L_800CC67C;
    }
    // 0x800CC44C: nop

    // 0x800CC450: beq         $t1, $a2, L_800CC564
    if (ctx->r9 == ctx->r6) {
        // 0x800CC454: lui         $a0, 0x700
        ctx->r4 = S32(0X700 << 16);
            goto L_800CC564;
    }
    // 0x800CC454: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x800CC458: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC45C: beq         $t1, $at, L_800CC4CC
    if (ctx->r9 == ctx->r1) {
        // 0x800CC460: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC4CC;
    }
    // 0x800CC460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC464: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CC468: bne         $t1, $at, L_800CC62C
    if (ctx->r9 != ctx->r1) {
        // 0x800CC46C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC62C;
    }
    // 0x800CC46C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC470: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800CC474: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CC478: lbu         $t6, 0x19($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X19);
    // 0x800CC47C: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    // 0x800CC480: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC484: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800CC488: lbu         $t6, 0x1A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1A);
    // 0x800CC48C: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800CC490: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800CC494: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x800CC498: lbu         $t6, 0x1B($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1B);
    // 0x800CC49C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800CC4A0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800CC4A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CC4A8: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x800CC4AC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800CC4B0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CC4B4: ori         $t5, $t5, 0xF2F9
    ctx->r13 = ctx->r13 | 0XF2F9;
    // 0x800CC4B8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800CC4BC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800CC4C0: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800CC4C4: b           L_800CC64C
    // 0x800CC4C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC64C;
    // 0x800CC4C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC4CC:
    // 0x800CC4CC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800CC4D0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC4D4: lbu         $t7, 0x19($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X19);
    // 0x800CC4D8: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    // 0x800CC4DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC4E0: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CC4E4: lbu         $t7, 0x1A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1A);
    // 0x800CC4E8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800CC4EC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800CC4F0: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800CC4F4: lbu         $t7, 0x1B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1B);
    // 0x800CC4F8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800CC4FC: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800CC500: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800CC504: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CC508: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800CC50C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800CC510: lbu         $t9, 0x61($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X61);
    // 0x800CC514: lbu         $t6, 0x60($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X60);
    // 0x800CC518: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC51C: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800CC520: lbu         $t9, 0x62($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X62);
    // 0x800CC524: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800CC528: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x800CC52C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800CC530: lbu         $t9, 0x63($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X63);
    // 0x800CC534: or          $t5, $t6, $t7
    ctx->r13 = ctx->r14 | ctx->r15;
    // 0x800CC538: lui         $t7, 0xFC30
    ctx->r15 = S32(0XFC30 << 16);
    // 0x800CC53C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CC540: lui         $t8, 0x552E
    ctx->r24 = S32(0X552E << 16);
    // 0x800CC544: or          $t6, $t5, $t9
    ctx->r14 = ctx->r13 | ctx->r25;
    // 0x800CC548: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800CC54C: ori         $t8, $t8, 0xFF7F
    ctx->r24 = ctx->r24 | 0XFF7F;
    // 0x800CC550: ori         $t7, $t7, 0x9661
    ctx->r15 = ctx->r15 | 0X9661;
    // 0x800CC554: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800CC558: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800CC55C: b           L_800CC64C
    // 0x800CC560: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
        goto L_800CC64C;
    // 0x800CC560: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC564:
    // 0x800CC564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CC568: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800CC56C: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x800CC570: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC574: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x800CC578: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CC57C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800CC580: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CC584: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x800CC588: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800CC58C: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x800CC590: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC594: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC598: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800CC59C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800CC5A0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800CC5A4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800CC5A8: lh          $t5, 0x1C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1C);
    // 0x800CC5AC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC5B0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800CC5B4: addiu       $t9, $t5, 0x100
    ctx->r25 = ADD32(ctx->r13, 0X100);
    // 0x800CC5B8: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x800CC5BC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC5C0: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800CC5C4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC5C8: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x800CC5CC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x800CC5D0: sw          $a0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r4;
    // 0x800CC5D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC5D8: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x800CC5DC: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
    // 0x800CC5E0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CC5E4: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800CC5E8: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x800CC5EC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800CC5F0: lh          $t5, 0x1E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1E);
    // 0x800CC5F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC5F8: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC5FC: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x800CC600: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x800CC604: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800CC608: or          $t8, $t7, $a0
    ctx->r24 = ctx->r15 | ctx->r4;
    // 0x800CC60C: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800CC610: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC614: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800CC618: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800CC61C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800CC620: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800CC624: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x800CC628: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC62C:
    // 0x800CC62C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC630: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800CC634: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x800CC638: ori         $t9, $t9, 0xF279
    ctx->r25 = ctx->r25 | 0XF279;
    // 0x800CC63C: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x800CC640: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CC644: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC648: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC64C:
    // 0x800CC64C: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x800CC650: beql        $a2, $t6, L_800CC810
    if (ctx->r6 == ctx->r14) {
        // 0x800CC654: lw          $t7, 0x0($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X0);
            goto L_800CC810;
    }
    goto skip_1;
    // 0x800CC654: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    skip_1:
    // 0x800CC658: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x800CC65C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800CC660: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x800CC664: bne         $a2, $t7, L_800CC80C
    if (ctx->r6 != ctx->r15) {
        // 0x800CC668: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CC80C;
    }
    // 0x800CC668: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CC66C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC670: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CC674: b           L_800CC80C
    // 0x800CC678: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_800CC80C;
    // 0x800CC678: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800CC67C:
    // 0x800CC67C: beq         $t1, $a2, L_800CC750
    if (ctx->r9 == ctx->r6) {
        // 0x800CC680: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_800CC750;
    }
    // 0x800CC680: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CC684: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CC688: beq         $t1, $at, L_800CC6D8
    if (ctx->r9 == ctx->r1) {
        // 0x800CC68C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC6D8;
    }
    // 0x800CC68C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC690: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CC694: bne         $t1, $at, L_800CC80C
    if (ctx->r9 != ctx->r1) {
        // 0x800CC698: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CC80C;
    }
    // 0x800CC698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CC69C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800CC6A0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CC6A4: lbu         $t5, 0x19($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X19);
    // 0x800CC6A8: lbu         $t6, 0x18($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18);
    // 0x800CC6AC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC6B0: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800CC6B4: lbu         $t5, 0x1A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1A);
    // 0x800CC6B8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800CC6BC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800CC6C0: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800CC6C4: lbu         $t5, 0x1B($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1B);
    // 0x800CC6C8: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800CC6CC: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800CC6D0: b           L_800CC80C
    // 0x800CC6D4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
        goto L_800CC80C;
    // 0x800CC6D4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_800CC6D8:
    // 0x800CC6D8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800CC6DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC6E0: lbu         $t7, 0x19($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X19);
    // 0x800CC6E4: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x800CC6E8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC6EC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800CC6F0: lbu         $t7, 0x1A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1A);
    // 0x800CC6F4: sll         $t5, $t9, 24
    ctx->r13 = S32(ctx->r25 << 24);
    // 0x800CC6F8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800CC6FC: sll         $t5, $t7, 8
    ctx->r13 = S32(ctx->r15 << 8);
    // 0x800CC700: lbu         $t7, 0x1B($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1B);
    // 0x800CC704: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800CC708: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800CC70C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800CC710: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800CC714: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CC718: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800CC71C: lbu         $t5, 0x61($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X61);
    // 0x800CC720: lbu         $t8, 0x60($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X60);
    // 0x800CC724: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC728: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800CC72C: lbu         $t5, 0x62($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X62);
    // 0x800CC730: sll         $t7, $t8, 24
    ctx->r15 = S32(ctx->r24 << 24);
    // 0x800CC734: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800CC738: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800CC73C: lbu         $t5, 0x63($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X63);
    // 0x800CC740: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800CC744: or          $t8, $t6, $t5
    ctx->r24 = ctx->r14 | ctx->r13;
    // 0x800CC748: b           L_800CC80C
    // 0x800CC74C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
        goto L_800CC80C;
    // 0x800CC74C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_800CC750:
    // 0x800CC750: lw          $t7, 0x62B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62B8);
    // 0x800CC754: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x800CC758: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x800CC75C: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x800CC760: beq         $t7, $t9, L_800CC80C
    if (ctx->r15 == ctx->r25) {
        // 0x800CC764: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CC80C;
    }
    // 0x800CC764: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CC768: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x800CC76C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800CC770: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x800CC774: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC778: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CC77C: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800CC780: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800CC784: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800CC788: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800CC78C: lh          $t7, 0x1C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1C);
    // 0x800CC790: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC794: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800CC798: addiu       $t9, $t7, 0x100
    ctx->r25 = ADD32(ctx->r15, 0X100);
    // 0x800CC79C: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x800CC7A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC7A4: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800CC7A8: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800CC7AC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC7B0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800CC7B4: sw          $a0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r4;
    // 0x800CC7B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC7BC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800CC7C0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800CC7C4: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
    // 0x800CC7C8: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x800CC7CC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800CC7D0: lh          $t7, 0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1E);
    // 0x800CC7D4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC7D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CC7DC: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800CC7E0: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x800CC7E4: sll         $t5, $t6, 14
    ctx->r13 = S32(ctx->r14 << 14);
    // 0x800CC7E8: or          $t8, $t5, $a0
    ctx->r24 = ctx->r13 | ctx->r4;
    // 0x800CC7EC: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x800CC7F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CC7F4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800CC7F8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800CC7FC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800CC800: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800CC804: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800CC808: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CC80C:
    // 0x800CC80C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
L_800CC810:
    // 0x800CC810: jr          $ra
    // 0x800CC814: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    return;
    // 0x800CC814: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
;}
RECOMP_FUNC void gmCameraSetStatusPlayerFollow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CFA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CFB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010CFB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010CFB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010CFBC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010CFC0: jal         0x8010CEF4
    // 0x8010CFC4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010CFC4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8010CFC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010CFCC: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010CFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CFD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010CFD8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010CFDC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010CFE0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010CFE4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010CFE8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010CFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CFF0: sw          $t6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r14;
    // 0x8010CFF4: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x8010CFF8: swc1        $f6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f6.u32l;
    // 0x8010CFFC: swc1        $f8, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f8.u32l;
    // 0x8010D000: swc1        $f10, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f10.u32l;
    // 0x8010D004: jr          $ra
    // 0x8010D008: swc1        $f16, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8010D008: swc1        $f16, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void scExplainMakeSObjOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DC10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DC14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018DC18: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC20: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018DC24: jal         0x80009968
    // 0x8018DC28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DC28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC2C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018DC30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DC34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018DC38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC3C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018DC40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DC44: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8018DC48: jal         0x80009DF4
    // 0x8018DC4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018DC4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DC50: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DC54: lw          $t7, -0x1620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1620);
    // 0x8018DC58: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8018DC5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018DC60: jal         0x800CCFDC
    // 0x8018DC64: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018DC64: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8018DC68: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8018DC6C: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8018DC70: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018DC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DC78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018DC7C: jr          $ra
    // 0x8018DC80: nop

    return;
    // 0x8018DC80: nop

;}
RECOMP_FUNC void mnMapsMakeModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801331B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801331B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801331B8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801331BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801331C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801331C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x801331C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x801331CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801331D0: bne         $a2, $zero, L_801331E4
    if (ctx->r6 != 0) {
        // 0x801331D4: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_801331E4;
    }
    // 0x801331D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801331D8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801331DC: b           L_801331EC
    // 0x801331E0: addiu       $s3, $s3, 0x4C00
    ctx->r19 = ADD32(ctx->r19, 0X4C00);
        goto L_801331EC;
    // 0x801331E0: addiu       $s3, $s3, 0x4C00
    ctx->r19 = ADD32(ctx->r19, 0X4C00);
L_801331E4:
    // 0x801331E4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801331E8: addiu       $s3, $s3, 0x4BF0
    ctx->r19 = ADD32(ctx->r19, 0X4BF0);
L_801331EC:
    // 0x801331EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801331F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801331F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801331F8: jal         0x8013303C
    // 0x801331FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    mnMapsMakeLayer(rdram, ctx);
        goto after_0;
    // 0x801331FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80133200: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80133204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133208: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013320C: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x80133210: jal         0x8013303C
    // 0x80133214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    mnMapsMakeLayer(rdram, ctx);
        goto after_1;
    // 0x80133214: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80133218: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8013321C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80133224: addiu       $a2, $s0, 0x20
    ctx->r6 = ADD32(ctx->r16, 0X20);
    // 0x80133228: jal         0x8013303C
    // 0x8013322C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    mnMapsMakeLayer(rdram, ctx);
        goto after_2;
    // 0x8013322C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80133230: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x80133234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133238: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013323C: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    // 0x80133240: jal         0x8013303C
    // 0x80133244: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    mnMapsMakeLayer(rdram, ctx);
        goto after_3;
    // 0x80133244: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80133248: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013324C: bne         $s1, $at, L_80133268
    if (ctx->r17 != ctx->r1) {
        // 0x80133250: sw          $v0, 0xC($s3)
        MEM_W(0XC, ctx->r19) = ctx->r2;
            goto L_80133268;
    }
    // 0x80133250: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x80133254: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80133258: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8013325C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80133260: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80133264: sb          $s5, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r21;
L_80133268:
    // 0x80133268: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013326C: bne         $s1, $at, L_801332B8
    if (ctx->r17 != ctx->r1) {
        // 0x80133270: addiu       $s5, $zero, 0x2
        ctx->r21 = ADD32(0, 0X2);
            goto L_801332B8;
    }
    // 0x80133270: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80133274: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80133278: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x8013327C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80133280: lw          $s2, 0x74($t0)
    ctx->r18 = MEM_W(ctx->r8, 0X74);
    // 0x80133284: addiu       $s4, $zero, 0x11
    ctx->r20 = ADD32(0, 0X11);
    // 0x80133288: beq         $s2, $zero, L_801332B8
    if (ctx->r18 == 0) {
        // 0x8013328C: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_801332B8;
    }
    // 0x8013328C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80133290:
    // 0x80133290: beq         $s0, $s3, L_801332A0
    if (ctx->r16 == ctx->r19) {
        // 0x80133294: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801332A0;
    }
    // 0x80133294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133298: bne         $s0, $s4, L_801332A4
    if (ctx->r16 != ctx->r20) {
        // 0x8013329C: nop
    
            goto L_801332A4;
    }
    // 0x8013329C: nop

L_801332A0:
    // 0x801332A0: sb          $s5, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r21;
L_801332A4:
    // 0x801332A4: jal         0x800C86E8
    // 0x801332A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_4;
    // 0x801332A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x801332AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801332B0: bne         $v0, $zero, L_80133290
    if (ctx->r2 != 0) {
        // 0x801332B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133290;
    }
    // 0x801332B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801332B8:
    // 0x801332B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801332BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801332C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801332C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801332C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801332CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801332D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801332D4: jr          $ra
    // 0x801332D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801332D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonShieldBreakFlyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149448: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014944C: jal         0x800D9480
    // 0x80149450: addiu       $a1, $a1, -0x68BC
    ctx->r5 = ADD32(ctx->r5, -0X68BC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149450: addiu       $a1, $a1, -0x68BC
    ctx->r5 = ADD32(ctx->r5, -0X68BC);
    after_0:
    // 0x80149454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014945C: jr          $ra
    // 0x80149460: nop

    return;
    // 0x80149460: nop

;}
RECOMP_FUNC void sc1PTrainingModeSetVScrollOptionSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FC7C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018FC80: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018FC84: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8018FC88: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x8018FC8C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8018FC90: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x8018FC94: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8018FC98: sw          $t9, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r25;
    // 0x8018FC9C: sw          $v0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r2;
    // 0x8018FCA0: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018FCA4: sw          $v0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r2;
    // 0x8018FCA8: sw          $t1, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r9;
    // 0x8018FCAC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018FCB0: sw          $v0, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->r2;
    // 0x8018FCB4: sw          $t3, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r11;
    // 0x8018FCB8: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8018FCBC: sw          $v0, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->r2;
    // 0x8018FCC0: sw          $t5, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->r13;
    // 0x8018FCC4: lw          $v1, 0x8($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X8);
    // 0x8018FCC8: sw          $v1, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->r3;
    // 0x8018FCCC: sw          $v1, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->r3;
    // 0x8018FCD0: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8018FCD4: sw          $v1, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->r3;
    // 0x8018FCD8: jr          $ra
    // 0x8018FCDC: sw          $v1, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r3;
    return;
    // 0x8018FCDC: sw          $v1, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void mvOpeningYosterMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E84: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80131E88: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80131E8C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80131E90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131E94: ori         $t9, $t9, 0x8640
    ctx->r25 = ctx->r25 | 0X8640;
    // 0x80131E98: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80131E9C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80131EA0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131EA4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131EA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131EAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131EB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80131EB4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80131EB8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80131EBC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80131EC0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80131EC4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131EC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131ECC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131ED0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131ED4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131ED8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131EDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131EE0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80131EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131EE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80131EEC: jal         0x8000B93C
    // 0x80131EF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131EF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131EF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131EFC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80131F00: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131F04: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80131F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131F10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131F14: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131F18: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80131F1C: jal         0x80007080
    // 0x80131F20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131F20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131F24: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80131F28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F2C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80131F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131F34: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131F38: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80131F3C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80131F40: lw          $t4, 0x25F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X25F8);
    // 0x80131F44: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80131F48: addiu       $t5, $t5, -0x36C0
    ctx->r13 = ADD32(ctx->r13, -0X36C0);
    // 0x80131F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131F54: jal         0x8000FA3C
    // 0x80131F58: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80131F58: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80131F5C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F60: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80131F64: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F6C: jal         0x80008188
    // 0x80131F70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80131F70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80131F74: jal         0x80010580
    // 0x80131F78: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    gcPlayCamAnim(rdram, ctx);
        goto after_4;
    // 0x80131F78: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80131F7C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80131F80: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80131F84: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80131F88: jr          $ra
    // 0x80131F8C: nop

    return;
    // 0x80131F8C: nop

;}
RECOMP_FUNC void itLinkBombCommonProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018649C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801864A0: jal         0x80172FE0
    // 0x801864A4: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x801864A4: nop

    after_0:
    // 0x801864A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801864AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801864B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801864B4: jr          $ra
    // 0x801864B8: nop

    return;
    // 0x801864B8: nop

;}
RECOMP_FUNC void syMatrixTraRotYawRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D0AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D0B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D0B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001D0B8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001D0BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001D0C0: jal         0x8001CFE0
    // 0x8001D0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotYawRF(rdram, ctx);
        goto after_0;
    // 0x8001D0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001D0C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001D0CC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D0D0: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001D0D4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001D0D8: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001D0DC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D0E0: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001D0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D0E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D0EC: jr          $ra
    // 0x8001D0F0: nop

    return;
    // 0x8001D0F0: nop

;}
RECOMP_FUNC void func_ovl8_80380B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380B6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80380B70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80380B74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380B78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80380B7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80380B80: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80380B84: bne         $a0, $zero, L_80380B9C
    if (ctx->r4 != 0) {
        // 0x80380B88: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80380B9C;
    }
    // 0x80380B88: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80380B8C: jal         0x803717A0
    // 0x80380B90: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80380B90: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_0:
    // 0x80380B94: beq         $v0, $zero, L_80380C1C
    if (ctx->r2 == 0) {
        // 0x80380B98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80380C1C;
    }
    // 0x80380B98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80380B9C:
    // 0x80380B9C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80380BA0: addiu       $a0, $s0, 0xD4
    ctx->r4 = ADD32(ctx->r16, 0XD4);
    // 0x80380BA4: addiu       $a1, $s0, 0xC8
    ctx->r5 = ADD32(ctx->r16, 0XC8);
    // 0x80380BA8: bnel        $t6, $zero, L_80380BCC
    if (ctx->r14 != 0) {
        // 0x80380BAC: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80380BCC;
    }
    goto skip_0;
    // 0x80380BAC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80380BB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80380BB4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80380BB8: jal         0x803717E0
    // 0x80380BBC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80380BBC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80380BC0: jal         0x8037C2D0
    // 0x80380BC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80380BC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80380BC8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80380BCC:
    // 0x80380BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80380BD0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80380BD4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80380BD8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80380BDC: jal         0x80380048
    // 0x80380BE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80380048(rdram, ctx);
        goto after_3;
    // 0x80380BE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80380BE4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80380BE8: addiu       $t8, $t8, -0x48E0
    ctx->r24 = ADD32(ctx->r24, -0X48E0);
    // 0x80380BEC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x80380BF0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80380BF4: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80380BF8: addiu       $t9, $t9, -0x4810
    ctx->r25 = ADD32(ctx->r25, -0X4810);
    // 0x80380BFC: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80380C00: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80380C04: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80380C08: addiu       $t1, $t1, -0x46B8
    ctx->r9 = ADD32(ctx->r9, -0X46B8);
    // 0x80380C0C: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80380C10: addiu       $t3, $t3, -0x4690
    ctx->r11 = ADD32(ctx->r11, -0X4690);
    // 0x80380C14: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80380C18: sw          $t3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r11;
L_80380C1C:
    // 0x80380C1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80380C20: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380C24: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80380C28: jr          $ra
    // 0x80380C2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80380C2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80374B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374B4C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374B50: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80374B54: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80374B58: lh          $t6, 0x58($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X58);
    // 0x80374B5C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80374B60: jalr        $t9
    // 0x80374B64: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374B64: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374B70: jr          $ra
    // 0x80374B74: nop

    return;
    // 0x80374B74: nop

;}
RECOMP_FUNC void mnVSResultsDrawResultsStockRoyal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136358: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013635C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136364: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80136368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013636C: bne         $v0, $at, L_80136384
    if (ctx->r2 != ctx->r1) {
        // 0x80136370: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80136384;
    }
    // 0x80136370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136374: jal         0x80134DA0
    // 0x80136378: nop

    mnVSResultsMakeTint(rdram, ctx);
        goto after_0;
    // 0x80136378: nop

    after_0:
    // 0x8013637C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136380: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_80136384:
    // 0x80136384: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80136388: bnel        $v0, $at, L_801363A4
    if (ctx->r2 != ctx->r1) {
        // 0x8013638C: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_801363A4;
    }
    goto skip_0;
    // 0x8013638C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    skip_0:
    // 0x80136390: jal         0x80136100
    // 0x80136394: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    mnVSResultsMakePlaceRow(rdram, ctx);
        goto after_1;
    // 0x80136394: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_1:
    // 0x80136398: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013639C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801363A0: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
L_801363A4:
    // 0x801363A4: bnel        $v0, $at, L_801363C0
    if (ctx->r2 != ctx->r1) {
        // 0x801363A8: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_801363C0;
    }
    goto skip_1;
    // 0x801363A8: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    skip_1:
    // 0x801363AC: jal         0x80135D58
    // 0x801363B0: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    mnVSResultsMakeBar(rdram, ctx);
        goto after_2;
    // 0x801363B0: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    after_2:
    // 0x801363B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801363B8: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801363BC: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
L_801363C0:
    // 0x801363C0: bnel        $v0, $at, L_801363DC
    if (ctx->r2 != ctx->r1) {
        // 0x801363C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801363DC;
    }
    goto skip_2;
    // 0x801363C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801363C8: jal         0x8013549C
    // 0x801363CC: nop

    mnVSResultsMakeHeader(rdram, ctx);
        goto after_3;
    // 0x801363CC: nop

    after_3:
    // 0x801363D0: jal         0x8013569C
    // 0x801363D4: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    mnVSResultsMakeKOs(rdram, ctx);
        goto after_4;
    // 0x801363D4: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_4:
    // 0x801363D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801363DC:
    // 0x801363DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801363E0: jr          $ra
    // 0x801363E4: nop

    return;
    // 0x801363E4: nop

;}
RECOMP_FUNC void gcDrawDObjForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013DA0: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80013DA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013DA8: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80013DAC: lw          $t6, 0x50($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X50);
    // 0x80013DB0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80013DB4: beql        $t6, $zero, L_80013E5C
    if (ctx->r14 == 0) {
        // 0x80013DB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013E5C;
    }
    goto skip_0;
    // 0x80013DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80013DBC: lbu         $t7, 0x54($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X54);
    // 0x80013DC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80013DC4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80013DC8: bnel        $t7, $zero, L_80013E5C
    if (ctx->r15 != 0) {
        // 0x80013DCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013E5C;
    }
    goto skip_1;
    // 0x80013DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80013DD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80013DD4: jal         0x80010D70
    // 0x80013DD8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x80013DD8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80013DDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80013DE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80013DE4: jal         0x80012D90
    // 0x80013DE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80013DE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80013DEC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80013DF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80013DF4: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x80013DF8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80013DFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80013E00: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80013E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80013E08: lw          $t0, 0x50($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X50);
    // 0x80013E0C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80013E10: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80013E14: beql        $t1, $zero, L_80013E5C
    if (ctx->r9 == 0) {
        // 0x80013E18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013E5C;
    }
    goto skip_2;
    // 0x80013E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80013E1C: lw          $t2, 0x14($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14);
    // 0x80013E20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013E24: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x80013E28: beql        $t2, $at, L_80013E40
    if (ctx->r10 == ctx->r1) {
        // 0x80013E2C: lw          $v1, 0x0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X0);
            goto L_80013E40;
    }
    goto skip_3;
    // 0x80013E2C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    skip_3:
    // 0x80013E30: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x80013E34: beql        $t3, $zero, L_80013E5C
    if (ctx->r11 == 0) {
        // 0x80013E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013E5C;
    }
    goto skip_4;
    // 0x80013E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80013E3C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_80013E40:
    // 0x80013E40: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x80013E44: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80013E48: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80013E4C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80013E50: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80013E54: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80013E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80013E5C:
    // 0x80013E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80013E60: jr          $ra
    // 0x80013E64: nop

    return;
    // 0x80013E64: nop

;}
RECOMP_FUNC void sySchedulerAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800009D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800009DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800009E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800009E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800009E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800009EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800009F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800009F4: jal         0x80034480
    // 0x800009F8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800009F8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800009FC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80000A00: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80000A04: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80000A08: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80000A0C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80000A10: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80000A14: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80000A18: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80000A1C: jal         0x80000970
    // 0x80000A20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80000970(rdram, ctx);
        goto after_1;
    // 0x80000A20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80000A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000A28: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80000A2C: jr          $ra
    // 0x80000A30: nop

    return;
    // 0x80000A30: nop

;}
RECOMP_FUNC void func_ovl8_80384DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384DC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384DCC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384DD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384DD4: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x80384DD8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384DDC: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80384DE0: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x80384DE4: jalr        $t9
    // 0x80384DE8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384DE8: nop

    after_0:
    // 0x80384DEC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80384DF0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80384DF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80384DF8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80384DFC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384E00: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80384E04: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384E08: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80384E0C: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80384E10: lh          $t7, 0xF0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XF0);
    // 0x80384E14: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80384E18: jalr        $t9
    // 0x80384E1C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384E1C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80384E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384E28: jr          $ra
    // 0x80384E2C: nop

    return;
    // 0x80384E2C: nop

;}
RECOMP_FUNC void ftCommonThrownKirbyStarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014BE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014BE98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8014BE9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8014BEA0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014BEA4: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x8014BEA8: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x8014BEAC: bltzl       $t8, L_8014BED4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8014BEB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014BED4;
    }
    goto skip_0;
    // 0x8014BEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014BEB4: jal         0x80103CF8
    // 0x8014BEB8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerCaptureKirbyStarMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8014BEB8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014BEBC: beq         $v0, $zero, L_8014BED0
    if (ctx->r2 == 0) {
        // 0x8014BEC0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8014BED0;
    }
    // 0x8014BEC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BEC4: lbu         $t0, 0x18F($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18F);
    // 0x8014BEC8: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8014BECC: sb          $t1, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r9;
L_8014BED0:
    // 0x8014BED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014BED4:
    // 0x8014BED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014BED8: jr          $ra
    // 0x8014BEDC: nop

    return;
    // 0x8014BEDC: nop

;}
RECOMP_FUNC void lbParticleMakeCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE870: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE878: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CE87C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CE880: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800CE884: jal         0x800CE6B8
    // 0x800CE888: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    lbParticleMakeChildScriptID(rdram, ctx);
        goto after_0;
    // 0x800CE888: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CE88C: beq         $v0, $zero, L_800CE8AC
    if (ctx->r2 == 0) {
        // 0x800CE890: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CE8AC;
    }
    // 0x800CE890: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CE894: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800CE898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE89C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800CE8A0: jal         0x800CEF4C
    // 0x800CE8A4: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_1;
    // 0x800CE8A4: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_1:
    // 0x800CE8A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800CE8AC:
    // 0x800CE8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE8B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE8B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CE8B8: jr          $ra
    // 0x800CE8BC: nop

    return;
    // 0x800CE8BC: nop

;}
RECOMP_FUNC void wpMapTestAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167A60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167A64: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80167A68: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80167A6C: addiu       $a1, $a1, 0x79A0
    ctx->r5 = ADD32(ctx->r5, 0X79A0);
    // 0x80167A70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80167A74: jal         0x800DA034
    // 0x80167A78: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x80167A78: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80167A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167A84: jr          $ra
    // 0x80167A88: nop

    return;
    // 0x80167A88: nop

;}
RECOMP_FUNC void mnPlayers1PBonusFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133FF0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133FF4: addiu       $s0, $s0, 0x7648
    ctx->r16 = ADD32(ctx->r16, 0X7648);
    // 0x80133FF8: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x80133FFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134004: bnel        $t6, $at, L_801340B8
    if (ctx->r14 != ctx->r1) {
        // 0x80134008: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_801340B8;
    }
    goto skip_0;
    // 0x80134008: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x8013400C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134010: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134014: lwc1        $f4, 0x761C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X761C);
    // 0x80134018: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8013401C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134020: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80134024: nop

    // 0x80134028: bc1f        L_8013405C
    if (!c1cs) {
        // 0x8013402C: nop
    
            goto L_8013405C;
    }
    // 0x8013402C: nop

    // 0x80134030: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
    // 0x80134034: bnel        $t7, $zero, L_801340F8
    if (ctx->r15 != 0) {
        // 0x80134038: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801340F8;
    }
    goto skip_1;
    // 0x80134038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013403C: jal         0x80133F88
    // 0x80134040: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PBonusGetStatusSelected(rdram, ctx);
        goto after_0;
    // 0x80134040: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_0:
    // 0x80134044: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80134048: jal         0x803905CC
    // 0x8013404C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013404C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80134050: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134054: b           L_801340F4
    // 0x80134058: sw          $t8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r24;
        goto L_801340F4;
    // 0x80134058: sw          $t8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r24;
L_8013405C:
    // 0x8013405C: lwc1        $f2, 0x7620($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7620);
    // 0x80134060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134064: lwc1        $f6, 0x7624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7624);
    // 0x80134068: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8013406C: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80134070: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134074: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80134078: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8013407C: nop

    // 0x80134080: bc1fl       L_801340F8
    if (!c1cs) {
        // 0x80134084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801340F8;
    }
    goto skip_2;
    // 0x80134084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80134088: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8013408C: nop

    // 0x80134090: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x80134094: jal         0x80133F88
    // 0x80134098: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PBonusGetStatusSelected(rdram, ctx);
        goto after_2;
    // 0x80134098: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x8013409C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801340A0: jal         0x803905CC
    // 0x801340A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_3;
    // 0x801340A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x801340A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801340AC: b           L_801340F4
    // 0x801340B0: sw          $t9, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r25;
        goto L_801340F4;
    // 0x801340B0: sw          $t9, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r25;
    // 0x801340B4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
L_801340B8:
    // 0x801340B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340BC: lwc1        $f2, 0x7628($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7628);
    // 0x801340C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340C4: lwc1        $f4, 0x762C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X762C);
    // 0x801340C8: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801340CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801340D0: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x801340D4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801340D8: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801340DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801340E0: nop

    // 0x801340E4: bc1fl       L_801340F8
    if (!c1cs) {
        // 0x801340E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801340F8;
    }
    goto skip_3;
    // 0x801340E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801340EC: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801340F0: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
L_801340F4:
    // 0x801340F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801340F8:
    // 0x801340F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801340FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134100: jr          $ra
    // 0x80134104: nop

    return;
    // 0x80134104: nop

;}
RECOMP_FUNC void func_ovl3_801346D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801346D4: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x801346D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801346DC: addiu       $t6, $sp, 0x10
    ctx->r14 = ADD32(ctx->r29, 0X10);
    // 0x801346E0: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x801346E4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801346E8: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x801346EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801346F0: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x801346F4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801346F8: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
    // 0x801346FC: lbu         $t2, 0x148($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X148);
    // 0x80134700: lwc1        $f0, 0x25C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X25C);
    // 0x80134704: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x80134708: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8013470C: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80134710: bnel        $t1, $t2, L_80134760
    if (ctx->r9 != ctx->r10) {
        // 0x80134714: lw          $v1, 0x8($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X8);
            goto L_80134760;
    }
    goto skip_0;
    // 0x80134714: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80134718: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8013471C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134720: beq         $v0, $at, L_8013473C
    if (ctx->r2 == ctx->r1) {
        // 0x80134724: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013473C;
    }
    // 0x80134724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80134728: beq         $v0, $at, L_8013473C
    if (ctx->r2 == ctx->r1) {
        // 0x8013472C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8013473C;
    }
    // 0x8013472C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80134730: beq         $v0, $at, L_80134754
    if (ctx->r2 == ctx->r1) {
        // 0x80134734: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80134754;
    }
    // 0x80134734: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80134738: bne         $v0, $at, L_8013475C
    if (ctx->r2 != ctx->r1) {
        // 0x8013473C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8013475C;
    }
L_8013473C:
    // 0x8013473C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80134740: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134744: nop

    // 0x80134748: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8013474C: b           L_80134760
    // 0x80134750: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
        goto L_80134760;
    // 0x80134750: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
L_80134754:
    // 0x80134754: lwc1        $f0, 0x25C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X25C);
    // 0x80134758: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8013475C:
    // 0x8013475C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
L_80134760:
    // 0x80134760: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80134764: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x80134768: bne         $v1, $at, L_80134778
    if (ctx->r3 != ctx->r1) {
        // 0x8013476C: lwc1        $f16, 0x10($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
            goto L_80134778;
    }
    // 0x8013476C: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80134770: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134774: nop

L_80134778:
    // 0x80134778: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8013477C: bne         $v1, $at, L_8013478C
    if (ctx->r3 != ctx->r1) {
        // 0x80134780: nop
    
            goto L_8013478C;
    }
    // 0x80134780: nop

    // 0x80134784: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134788: nop

L_8013478C:
    // 0x8013478C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134790: addiu       $v1, $v1, 0x1308
    ctx->r3 = ADD32(ctx->r3, 0X1308);
    // 0x80134794: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80134798: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8013479C: nop

    // 0x801347A0: bc1fl       L_80134888
    if (!c1cs) {
        // 0x801347A4: lw          $t8, 0x44($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X44);
            goto L_80134888;
    }
    goto skip_1;
    // 0x801347A4: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    skip_1:
    // 0x801347A8: lw          $t3, 0x44($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X44);
    // 0x801347AC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801347B0: blez        $t3, L_801347C8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x801347B4: nop
    
            goto L_801347C8;
    }
    // 0x801347B4: nop

    // 0x801347B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801347BC: nop

    // 0x801347C0: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801347C4: nop

L_801347C8:
    // 0x801347C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801347CC: lwc1        $f2, -0x426C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X426C);
    // 0x801347D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801347D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801347D8: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x801347DC: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x801347E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801347E4: swc1        $f18, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f18.u32l;
    // 0x801347E8: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801347EC: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801347F0: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x801347F4: nop

    // 0x801347F8: bc1fl       L_8013480C
    if (!c1cs) {
        // 0x801347FC: lw          $t5, 0x9C8($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X9C8);
            goto L_8013480C;
    }
    goto skip_2;
    // 0x801347FC: lw          $t5, 0x9C8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X9C8);
    skip_2:
    // 0x80134800: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134804: nop

    // 0x80134808: lw          $t5, 0x9C8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X9C8);
L_8013480C:
    // 0x8013480C: lbu         $t4, 0x148($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X148);
    // 0x80134810: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x80134814: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80134818: beql        $at, $zero, L_80134844
    if (ctx->r1 == 0) {
        // 0x8013481C: lw          $t7, 0x8E8($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X8E8);
            goto L_80134844;
    }
    goto skip_3;
    // 0x8013481C: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    skip_3:
    // 0x80134820: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80134824: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134828: lwc1        $f16, -0x4268($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4268);
    // 0x8013482C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80134830: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80134834: nop

    // 0x80134838: bc1tl       L_80134870
    if (c1cs) {
        // 0x8013483C: lwc1        $f8, 0x14($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
            goto L_80134870;
    }
    goto skip_4;
    // 0x8013483C: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80134840: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
L_80134844:
    // 0x80134844: lwc1        $f10, 0x4C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80134848: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013484C: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80134850: sub.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80134854: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80134858: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8013485C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80134860: nop

    // 0x80134864: bc1f        L_8013487C
    if (!c1cs) {
        // 0x80134868: nop
    
            goto L_8013487C;
    }
    // 0x80134868: nop

    // 0x8013486C: lwc1        $f8, 0x14($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14);
L_80134870:
    // 0x80134870: add.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80134874: b           L_8013495C
    // 0x80134878: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
        goto L_8013495C;
    // 0x80134878: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
L_8013487C:
    // 0x8013487C: b           L_8013495C
    // 0x80134880: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
        goto L_8013495C;
    // 0x80134880: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    // 0x80134884: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
L_80134888:
    // 0x80134888: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8013488C: bgez        $t8, L_801348A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80134890: nop
    
            goto L_801348A4;
    }
    // 0x80134890: nop

    // 0x80134894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134898: nop

    // 0x8013489C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801348A0: nop

L_801348A4:
    // 0x801348A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801348A8: lwc1        $f2, -0x4264($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4264);
    // 0x801348AC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801348B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801348B4: add.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x801348B8: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801348BC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801348C0: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    // 0x801348C4: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801348C8: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801348CC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x801348D0: nop

    // 0x801348D4: bc1fl       L_801348E8
    if (!c1cs) {
        // 0x801348D8: lw          $t0, 0x9C8($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X9C8);
            goto L_801348E8;
    }
    goto skip_5;
    // 0x801348D8: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
    skip_5:
    // 0x801348DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801348E0: nop

    // 0x801348E4: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
L_801348E8:
    // 0x801348E8: lbu         $t9, 0x148($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X148);
    // 0x801348EC: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x801348F0: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801348F4: beql        $at, $zero, L_80134920
    if (ctx->r1 == 0) {
        // 0x801348F8: lw          $t2, 0x8E8($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X8E8);
            goto L_80134920;
    }
    goto skip_6;
    // 0x801348F8: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
    skip_6:
    // 0x801348FC: lwc1        $f16, 0x2C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80134900: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80134904: lwc1        $f18, -0x4260($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4260);
    // 0x80134908: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8013490C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80134910: nop

    // 0x80134914: bc1tl       L_8013494C
    if (c1cs) {
        // 0x80134918: lwc1        $f4, 0x14($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
            goto L_8013494C;
    }
    goto skip_7;
    // 0x80134918: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8013491C: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
L_80134920:
    // 0x80134920: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80134924: lwc1        $f8, 0x50($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X50);
    // 0x80134928: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8013492C: sub.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80134930: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80134934: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80134938: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8013493C: nop

    // 0x80134940: bc1fl       L_8013495C
    if (!c1cs) {
        // 0x80134944: swc1        $f6, 0x64($v0)
        MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
            goto L_8013495C;
    }
    goto skip_8;
    // 0x80134944: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
    skip_8:
    // 0x80134948: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
L_8013494C:
    // 0x8013494C: add.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80134950: b           L_8013495C
    // 0x80134954: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
        goto L_8013495C;
    // 0x80134954: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    // 0x80134958: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
L_8013495C:
    // 0x8013495C: jr          $ra
    // 0x80134960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80134960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpMarioFireballProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016874C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80168754: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80168758: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8016875C: lw          $t8, 0x29C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X29C);
    // 0x80168760: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80168764: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80168768: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8016876C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80168770: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80168774: lw          $t0, -0x71D0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X71D0);
    // 0x80168778: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8016877C: jal         0x801680EC
    // 0x80168780: sw          $t0, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r8;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80168780: sw          $t0, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r8;
    after_0:
    // 0x80168784: jal         0x80167FA0
    // 0x80168788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_1;
    // 0x80168788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016878C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168798: jr          $ra
    // 0x8016879C: nop

    return;
    // 0x8016879C: nop

;}
RECOMP_FUNC void itStarmieMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801822B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801822B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801822B8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801822BC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801822C0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801822C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801822C8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801822CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801822D0: addiu       $a1, $a1, -0x4E90
    ctx->r5 = ADD32(ctx->r5, -0X4E90);
    // 0x801822D4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x801822D8: jal         0x8016E174
    // 0x801822DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801822DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x801822E0: beq         $v0, $zero, L_801823A0
    if (ctx->r2 == 0) {
        // 0x801822E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801823A0;
    }
    // 0x801822E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801822E8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801822EC: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801822F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801822F4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801822F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801822FC: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x80182300: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182304: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80182308: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8018230C: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80182310: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80182314: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80182318: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8018231C: jal         0x80008CC0
    // 0x80182320: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80182320: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80182324: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80182328: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8018232C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80182330: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80182334: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80182338: addiu       $t4, $t4, 0x12A0
    ctx->r12 = ADD32(ctx->r12, 0X12A0);
    // 0x8018233C: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x80182340: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80182344: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80182348: addiu       $t6, $t6, 0x3624
    ctx->r14 = ADD32(ctx->r14, 0X3624);
    // 0x8018234C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80182350: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80182354: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80182358: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018235C: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80182360: lw          $t0, 0x2D4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2D4);
    // 0x80182364: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80182368: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8018236C: nop

    // 0x80182370: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80182374: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80182378: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8018237C: lw          $t2, 0x2D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2D4);
    // 0x80182380: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80182384: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80182388: jal         0x8000BD1C
    // 0x8018238C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018238C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80182390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80182394: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80182398: jal         0x8000A14C
    // 0x8018239C: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    gcMoveGObjDLHead(rdram, ctx);
        goto after_3;
    // 0x8018239C: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_3:
L_801823A0:
    // 0x801823A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801823A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801823A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801823AC: jr          $ra
    // 0x801823B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801823B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_8037C344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C344: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037C348: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037C34C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037C350: jr          $ra
    // 0x8037C354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8037C354: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_ovl8_8037C518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C51C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037C524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037C528: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8037C52C: addiu       $a1, $zero, -0x1FD
    ctx->r5 = ADD32(0, -0X1FD);
    // 0x8037C530: jal         0x8000B16C
    // 0x8037C534: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_0;
    // 0x8037C534: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_0:
    // 0x8037C538: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C53C: sw          $v0, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = ctx->r2;
    // 0x8037C540: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8037C544: jal         0x8000B16C
    // 0x8037C548: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_1;
    // 0x8037C548: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    after_1:
    // 0x8037C54C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8037C550: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C554: sw          $v0, -0x5E38($at)
    MEM_W(-0X5E38, ctx->r1) = ctx->r2;
    // 0x8037C558: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x8037C55C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C560: sw          $t6, -0x5E40($at)
    MEM_W(-0X5E40, ctx->r1) = ctx->r14;
    // 0x8037C564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C568: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C56C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8037C570: sb          $t7, -0x1030($at)
    MEM_B(-0X1030, ctx->r1) = ctx->r15;
    // 0x8037C574: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C57C: jr          $ra
    // 0x8037C580: sw          $t8, -0x102C($at)
    MEM_W(-0X102C, ctx->r1) = ctx->r24;
    return;
    // 0x8037C580: sw          $t8, -0x102C($at)
    MEM_W(-0X102C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void syDebugStartRmonThread5Hang(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800235D4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800235D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800235DC: addiu       $t6, $t6, -0x1248
    ctx->r14 = ADD32(ctx->r14, -0X1248);
    // 0x800235E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800235E4: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x800235E8: addiu       $t7, $zero, 0x69
    ctx->r15 = ADD32(0, 0X69);
    // 0x800235EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800235F0: addiu       $a2, $a2, 0x33A4
    ctx->r6 = ADD32(ctx->r6, 0X33A4);
    // 0x800235F4: addiu       $a0, $a0, -0x1BF8
    ctx->r4 = ADD32(ctx->r4, -0X1BF8);
    // 0x800235F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800235FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80023600: jal         0x80031E20
    // 0x80023604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80023604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80023608: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002360C: jal         0x80039190
    // 0x80023610: addiu       $a0, $a0, -0x1BF8
    ctx->r4 = ADD32(ctx->r4, -0X1BF8);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80023610: addiu       $a0, $a0, -0x1BF8
    ctx->r4 = ADD32(ctx->r4, -0X1BF8);
    after_1:
    // 0x80023614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002361C: jr          $ra
    // 0x80023620: nop

    return;
    // 0x80023620: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingAdjustCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135074: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135078: addiu       $t6, $t6, -0x7C80
    ctx->r14 = ADD32(ctx->r14, -0X7C80);
    // 0x8013507C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80135080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80135084: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80135088: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8013508C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80135090: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80135094: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80135098: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8013509C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801350A0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801350A4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x801350A8: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x801350AC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801350B0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801350B4: addiu       $t1, $t1, -0x7AA8
    ctx->r9 = ADD32(ctx->r9, -0X7AA8);
    // 0x801350B8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x801350BC: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801350C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801350C4: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x801350C8: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x801350CC: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x801350D0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801350D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801350D8: beq         $t2, $zero, L_8013525C
    if (ctx->r10 == 0) {
        // 0x801350DC: sw          $t7, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->r15;
            goto L_8013525C;
    }
    // 0x801350DC: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x801350E0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801350E4: lwc1        $f2, 0x94($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X94);
    // 0x801350E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801350EC: lw          $v1, 0x74($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X74);
    // 0x801350F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801350F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801350F8: lwc1        $f12, 0x58($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801350FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80135104: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80135108: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013510C: div.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80135110: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80135114: nop

    // 0x80135118: bc1f        L_80135140
    if (!c1cs) {
        // 0x8013511C: nop
    
            goto L_80135140;
    }
    // 0x8013511C: nop

    // 0x80135120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135124: nop

    // 0x80135128: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8013512C: nop

    // 0x80135130: bc1f        L_80135140
    if (!c1cs) {
        // 0x80135134: nop
    
            goto L_80135140;
    }
    // 0x80135134: nop

    // 0x80135138: b           L_80135140
    // 0x8013513C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80135140;
    // 0x8013513C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80135140:
    // 0x80135140: beq         $a0, $zero, L_80135150
    if (ctx->r4 == 0) {
        // 0x80135144: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80135150;
    }
    // 0x80135144: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80135148: b           L_80135158
    // 0x8013514C: swc1        $f2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f2.u32l;
        goto L_80135158;
    // 0x8013514C: swc1        $f2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f2.u32l;
L_80135150:
    // 0x80135150: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80135154: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
L_80135158:
    // 0x80135158: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8013515C: lwc1        $f2, 0x98($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X98);
    // 0x80135160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135164: lw          $v1, 0x74($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X74);
    // 0x80135168: lwc1        $f12, 0x5C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8013516C: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80135170: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80135174: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80135178: nop

    // 0x8013517C: bc1f        L_801351A4
    if (!c1cs) {
        // 0x80135180: nop
    
            goto L_801351A4;
    }
    // 0x80135180: nop

    // 0x80135184: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135188: nop

    // 0x8013518C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80135190: nop

    // 0x80135194: bc1f        L_801351A4
    if (!c1cs) {
        // 0x80135198: nop
    
            goto L_801351A4;
    }
    // 0x80135198: nop

    // 0x8013519C: b           L_801351A4
    // 0x801351A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801351A4;
    // 0x801351A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801351A4:
    // 0x801351A4: beql        $a0, $zero, L_801351B8
    if (ctx->r4 == 0) {
        // 0x801351A8: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_801351B8;
    }
    goto skip_0;
    // 0x801351A8: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_0:
    // 0x801351AC: b           L_801351BC
    // 0x801351B0: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
        goto L_801351BC;
    // 0x801351B0: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
    // 0x801351B4: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
L_801351B8:
    // 0x801351B8: swc1        $f4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f4.u32l;
L_801351BC:
    // 0x801351BC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801351C0: lwc1        $f8, 0x94($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X94);
    // 0x801351C4: lw          $v1, 0x74($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X74);
    // 0x801351C8: lwc1        $f6, 0x58($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801351CC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801351D0: nop

    // 0x801351D4: bc1fl       L_801351FC
    if (!c1cs) {
        // 0x801351D8: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_801351FC;
    }
    goto skip_1;
    // 0x801351D8: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x801351DC: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801351E0: lwc1        $f18, 0x98($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X98);
    // 0x801351E4: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x801351E8: nop

    // 0x801351EC: bc1fl       L_801351FC
    if (!c1cs) {
        // 0x801351F0: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_801351FC;
    }
    goto skip_2;
    // 0x801351F0: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x801351F4: sw          $zero, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = 0;
    // 0x801351F8: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
L_801351FC:
    // 0x801351FC: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80135200: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80135204: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x80135208: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013520C: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80135210: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x80135214: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80135218: nop

    // 0x8013521C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135220: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135224: swc1        $f10, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f10.u32l;
    // 0x80135228: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    // 0x8013522C: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80135230: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80135234: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80135238: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8013523C: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80135240: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80135244: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80135248: nop

    // 0x8013524C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80135250: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135254: b           L_80135428
    // 0x80135258: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
        goto L_80135428;
    // 0x80135258: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
L_8013525C:
    // 0x8013525C: lw          $t7, 0x58($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X58);
    // 0x80135260: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135264: bne         $t7, $zero, L_80135428
    if (ctx->r15 != 0) {
        // 0x80135268: nop
    
            goto L_80135428;
    }
    // 0x80135268: nop

    // 0x8013526C: lw          $t8, -0x776C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X776C);
    // 0x80135270: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80135274: addiu       $t1, $t1, 0x5228
    ctx->r9 = ADD32(ctx->r9, 0X5228);
    // 0x80135278: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8013527C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80135280: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80135284: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x80135288: lb          $a3, 0x8($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X8);
    // 0x8013528C: slti        $at, $a3, -0x8
    ctx->r1 = SIGNED(ctx->r7) < -0X8 ? 1 : 0;
    // 0x80135290: bne         $at, $zero, L_801352A0
    if (ctx->r1 != 0) {
        // 0x80135294: slti        $at, $a3, 0x9
        ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
            goto L_801352A0;
    }
    // 0x80135294: slti        $at, $a3, 0x9
    ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x80135298: bne         $at, $zero, L_801352A8
    if (ctx->r1 != 0) {
        // 0x8013529C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801352A8;
    }
    // 0x8013529C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_801352A0:
    // 0x801352A0: b           L_801352A8
    // 0x801352A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801352A8;
    // 0x801352A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801352A8:
    // 0x801352A8: beql        $a0, $zero, L_80135368
    if (ctx->r4 == 0) {
        // 0x801352AC: lb          $a3, 0x9($a1)
        ctx->r7 = MEM_B(ctx->r5, 0X9);
            goto L_80135368;
    }
    goto skip_3;
    // 0x801352AC: lb          $a3, 0x9($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X9);
    skip_3:
    // 0x801352B0: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x801352B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801352B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801352BC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801352C0: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x801352C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801352C8: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x801352CC: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801352D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801352D4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801352D8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801352DC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x801352E0: nop

    // 0x801352E4: bc1f        L_8013530C
    if (!c1cs) {
        // 0x801352E8: nop
    
            goto L_8013530C;
    }
    // 0x801352E8: nop

    // 0x801352EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801352F0: nop

    // 0x801352F4: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801352F8: nop

    // 0x801352FC: bc1f        L_8013530C
    if (!c1cs) {
        // 0x80135300: nop
    
            goto L_8013530C;
    }
    // 0x80135300: nop

    // 0x80135304: b           L_8013530C
    // 0x80135308: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8013530C;
    // 0x80135308: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8013530C:
    // 0x8013530C: beql        $a0, $zero, L_80135368
    if (ctx->r4 == 0) {
        // 0x80135310: lb          $a3, 0x9($a1)
        ctx->r7 = MEM_B(ctx->r5, 0X9);
            goto L_80135368;
    }
    goto skip_4;
    // 0x80135310: lb          $a3, 0x9($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X9);
    skip_4:
    // 0x80135314: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80135318: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    // 0x8013531C: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80135320: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135324: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80135328: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8013532C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80135330: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80135334: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80135338: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8013533C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80135340: addiu       $t9, $t9, 0x5228
    ctx->r25 = ADD32(ctx->r25, 0X5228);
    // 0x80135344: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135348: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013534C: swc1        $f10, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f10.u32l;
    // 0x80135350: lw          $t7, -0x776C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X776C);
    // 0x80135354: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80135358: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013535C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80135360: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80135364: lb          $a3, 0x9($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X9);
L_80135368:
    // 0x80135368: slti        $at, $a3, -0x8
    ctx->r1 = SIGNED(ctx->r7) < -0X8 ? 1 : 0;
    // 0x8013536C: bne         $at, $zero, L_8013537C
    if (ctx->r1 != 0) {
        // 0x80135370: slti        $at, $a3, 0x9
        ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
            goto L_8013537C;
    }
    // 0x80135370: slti        $at, $a3, 0x9
    ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x80135374: bne         $at, $zero, L_80135384
    if (ctx->r1 != 0) {
        // 0x80135378: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80135384;
    }
    // 0x80135378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8013537C:
    // 0x8013537C: b           L_80135384
    // 0x80135380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80135384;
    // 0x80135380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80135384:
    // 0x80135384: beq         $a0, $zero, L_80135428
    if (ctx->r4 == 0) {
        // 0x80135388: nop
    
            goto L_80135428;
    }
    // 0x80135388: nop

    // 0x8013538C: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x80135390: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80135394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135398: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013539C: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x801353A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801353A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801353A8: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801353AC: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x801353B0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801353B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801353B8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801353BC: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x801353C0: nop

    // 0x801353C4: bc1f        L_801353EC
    if (!c1cs) {
        // 0x801353C8: nop
    
            goto L_801353EC;
    }
    // 0x801353C8: nop

    // 0x801353CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801353D0: nop

    // 0x801353D4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801353D8: nop

    // 0x801353DC: bc1f        L_801353EC
    if (!c1cs) {
        // 0x801353E0: nop
    
            goto L_801353EC;
    }
    // 0x801353E0: nop

    // 0x801353E4: b           L_801353EC
    // 0x801353E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801353EC;
    // 0x801353E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801353EC:
    // 0x801353EC: beq         $a0, $zero, L_80135428
    if (ctx->r4 == 0) {
        // 0x801353F0: nop
    
            goto L_80135428;
    }
    // 0x801353F0: nop

    // 0x801353F4: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x801353F8: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
    // 0x801353FC: lw          $v1, 0x74($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X74);
    // 0x80135400: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80135404: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80135408: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8013540C: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80135410: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80135414: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80135418: nop

    // 0x8013541C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80135420: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80135424: swc1        $f18, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f18.u32l;
L_80135428:
    // 0x80135428: jr          $ra
    // 0x8013542C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8013542C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayers1PGamePortraitProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013283C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132840: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132844: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132850: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132854: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132858: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8013285C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132860: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132864: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132868: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8013286C: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132870: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132874: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132878: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013287C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132880: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132884: lui         $t4, 0x3030
    ctx->r12 = S32(0X3030 << 16);
    // 0x80132888: ori         $t4, $t4, 0x30FF
    ctx->r12 = ctx->r12 | 0X30FF;
    // 0x8013288C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80132890: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80132894: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80132898: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8013289C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801328A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328A4: lui         $t7, 0x11FC
    ctx->r15 = S32(0X11FC << 16);
    // 0x801328A8: lui         $t6, 0xFC71
    ctx->r14 = S32(0XFC71 << 16);
    // 0x801328AC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801328B0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801328B4: ori         $t6, $t6, 0xFEE3
    ctx->r14 = ctx->r14 | 0XFEE3;
    // 0x801328B8: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x801328BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801328C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801328C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328C8: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x801328CC: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801328D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801328D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801328D8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801328DC: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x801328E0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801328E4: jal         0x800CCF74
    // 0x801328E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x801328E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x801328EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328F4: jr          $ra
    // 0x801328F8: nop

    return;
    // 0x801328F8: nop

;}
RECOMP_FUNC void func_ovl8_80374E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374E1C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80374E20: lw          $t6, -0x1038($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1038);
    // 0x80374E24: jr          $ra
    // 0x80374E28: sw          $a0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r4;
    return;
    // 0x80374E28: sw          $a0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_803749BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803749BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803749C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803749C4: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x803749C8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803749CC: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x803749D0: lh          $t6, 0xB8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB8);
    // 0x803749D4: jalr        $t9
    // 0x803749D8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803749D8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x803749DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803749E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803749E4: jr          $ra
    // 0x803749E8: nop

    return;
    // 0x803749E8: nop

;}
RECOMP_FUNC void func_ovl8_8037A67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A67C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037A680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037A684: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037A688: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8037A68C: jal         0x8037A9F4
    // 0x8037A690: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037A9F4(rdram, ctx);
        goto after_0;
    // 0x8037A690: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8037A694: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A698: jal         0x8037A9F4
    // 0x8037A69C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_ovl8_8037A9F4(rdram, ctx);
        goto after_1;
    // 0x8037A69C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8037A6A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8037A6A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037A6A8: jal         0x8037A6D4
    // 0x8037A6AC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_ovl8_8037A6D4(rdram, ctx);
        goto after_2;
    // 0x8037A6AC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8037A6B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8037A6B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8037A6B8: jal         0x8037AA28
    // 0x8037A6BC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_ovl8_8037AA28(rdram, ctx);
        goto after_3;
    // 0x8037A6BC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x8037A6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037A6C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8037A6C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037A6CC: jr          $ra
    // 0x8037A6D0: nop

    return;
    // 0x8037A6D0: nop

;}
RECOMP_FUNC void mvOpeningStandoffMakeLightning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801320C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801320C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801320CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801320D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801320D4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801320D8: jal         0x80009968
    // 0x801320DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801320DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801320E0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801320E4: lw          $t6, 0x2B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2B98);
    // 0x801320E8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801320EC: addiu       $t7, $t7, 0x6950
    ctx->r15 = ADD32(ctx->r15, 0X6950);
    // 0x801320F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801320F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801320F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801320FC: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80132100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132104: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80132108: jal         0x8000F590
    // 0x8013210C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x8013210C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132110: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132114: lw          $t8, 0x2B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2B98);
    // 0x80132118: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8013211C: addiu       $t9, $t9, 0x6140
    ctx->r25 = ADD32(ctx->r25, 0X6140);
    // 0x80132120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132124: jal         0x8000F8F4
    // 0x80132128: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddMObjAll(rdram, ctx);
        goto after_2;
    // 0x80132128: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8013212C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132130: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132134: lw          $t0, 0x2B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2B98);
    // 0x80132138: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8013213C: addiu       $t1, $t1, 0x6BB8
    ctx->r9 = ADD32(ctx->r9, 0X6BB8);
    // 0x80132140: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132148: jal         0x8000BE28
    // 0x8013214C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x8013214C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x80132150: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132154: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80132158: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8013215C: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80132160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132164: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132168: jal         0x80009DF4
    // 0x8013216C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8013216C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132170: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132174: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80132178: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013217C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132180: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
    // 0x80132184: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80132188: addiu       $t7, $t7, 0x6D60
    ctx->r15 = ADD32(ctx->r15, 0X6D60);
    // 0x8013218C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132190: swc1        $f0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f0.u32l;
    // 0x80132194: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80132198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013219C: swc1        $f0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f0.u32l;
    // 0x801321A0: lw          $t6, 0x2B98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2B98);
    // 0x801321A4: jal         0x8000BD8C
    // 0x801321A8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddAnimJointAll(rdram, ctx);
        goto after_5;
    // 0x801321A8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_5:
    // 0x801321AC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801321B0: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x801321B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801321BC: jal         0x80008188
    // 0x801321C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x801321C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x801321C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801321C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801321CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801321D0: jr          $ra
    // 0x801321D4: nop

    return;
    // 0x801321D4: nop

;}
RECOMP_FUNC void gmCameraGetTargetAtY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BBE4: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8010BBE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010BBEC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010BBF0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8010BBF4: nop

    // 0x8010BBF8: bc1fl       L_8010BC10
    if (!c1cs) {
        // 0x8010BBFC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8010BC10;
    }
    goto skip_0;
    // 0x8010BBFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8010BC00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010BC04: jr          $ra
    // 0x8010BC08: lwc1        $f0, 0xBF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBF0);
    return;
    // 0x8010BC08: lwc1        $f0, 0xBF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBF0);
    // 0x8010BC0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8010BC10:
    // 0x8010BC10: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010BC14: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8010BC18: nop

    // 0x8010BC1C: bc1fl       L_8010BC34
    if (!c1cs) {
        // 0x8010BC20: sub.s       $f6, $f12, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8010BC34;
    }
    goto skip_1;
    // 0x8010BC20: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x8010BC24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010BC28: jr          $ra
    // 0x8010BC2C: nop

    return;
    // 0x8010BC2C: nop

    // 0x8010BC30: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
L_8010BC34:
    // 0x8010BC34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010BC38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010BC3C: lwc1        $f16, 0xBF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XBF4);
    // 0x8010BC40: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010BC44: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010BC48: nop

    // 0x8010BC4C: jr          $ra
    // 0x8010BC50: nop

    return;
    // 0x8010BC50: nop

;}
RECOMP_FUNC void itProcessUpdateAttackStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FE4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016FE50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016FE54: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8016FE58: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8016FE5C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8016FE60: jal         0x80168128
    // 0x8016FE64: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x8016FE64: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8016FE68: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8016FE6C: jal         0x801727F4
    // 0x8016FE70: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    itMainGetDamageOutput(rdram, ctx);
        goto after_1;
    // 0x8016FE70: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8016FE74: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8016FE78: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8016FE7C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8016FE80: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8016FE84: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8016FE88: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8016FE8C: jal         0x800F0CDC
    // 0x8016FE90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gmCollisionGetWeaponAttackItemAttackPosition(rdram, ctx);
        goto after_2;
    // 0x8016FE90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8016FE94: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8016FE98: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8016FE9C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8016FEA0: lw          $v1, 0x40($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X40);
    // 0x8016FEA4: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x8016FEA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8016FEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016FEB0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8016FEB4: bnel        $at, $zero, L_8016FEFC
    if (ctx->r1 != 0) {
        // 0x8016FEB8: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8016FEFC;
    }
    goto skip_0;
    // 0x8016FEB8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x8016FEBC: jal         0x8016F930
    // 0x8016FEC0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_3;
    // 0x8016FEC0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x8016FEC4: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8016FEC8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8016FECC: lw          $t9, 0x270($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X270);
    // 0x8016FED0: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016FED4: beq         $at, $zero, L_8016FEE0
    if (ctx->r1 == 0) {
        // 0x8016FED8: nop
    
            goto L_8016FEE0;
    }
    // 0x8016FED8: nop

    // 0x8016FEDC: sw          $a1, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->r5;
L_8016FEE0:
    // 0x8016FEE0: jal         0x80100BF0
    // 0x8016FEE4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8016FEE4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8016FEE8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8016FEEC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8016FEF0: lw          $v1, 0x40($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X40);
    // 0x8016FEF4: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x8016FEF8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8016FEFC:
    // 0x8016FEFC: bne         $at, $zero, L_8016FF3C
    if (ctx->r1 != 0) {
        // 0x8016FF00: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8016FF3C;
    }
    // 0x8016FF00: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8016FF04: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8016FF08: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8016FF0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8016FF10: jal         0x8016679C
    // 0x8016FF14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_5;
    // 0x8016FF14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8016FF18: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8016FF1C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8016FF20: lw          $t3, 0x23C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X23C);
    // 0x8016FF24: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016FF28: beq         $at, $zero, L_8016FF34
    if (ctx->r1 == 0) {
        // 0x8016FF2C: nop
    
            goto L_8016FF34;
    }
    // 0x8016FF2C: nop

    // 0x8016FF30: sw          $a1, 0x23C($t2)
    MEM_W(0X23C, ctx->r10) = ctx->r5;
L_8016FF34:
    // 0x8016FF34: jal         0x80100BF0
    // 0x8016FF38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8016FF38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_6:
L_8016FF3C:
    // 0x8016FF3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016FF40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016FF44: jr          $ra
    // 0x8016FF48: nop

    return;
    // 0x8016FF48: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicapOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801370F8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801370FC: lbu         $t6, 0x4D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D10);
    // 0x80137100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137104: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80137108: bne         $t6, $at, L_80137118
    if (ctx->r14 != ctx->r1) {
        // 0x8013710C: nop
    
            goto L_80137118;
    }
    // 0x8013710C: nop

    // 0x80137110: jr          $ra
    // 0x80137114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80137114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137118:
    // 0x80137118: jr          $ra
    // 0x8013711C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013711C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl33_80131BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: jr          $ra
    // 0x80131BFC: nop

    return;
    // 0x80131BFC: nop

;}
RECOMP_FUNC void func_ovl8_80381934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8038193C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80381940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381944: bne         $a0, $zero, L_80381964
    if (ctx->r4 != 0) {
        // 0x80381948: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80381964;
    }
    // 0x80381948: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8038194C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80381950: jal         0x803717A0
    // 0x80381954: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80381954: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80381958: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8038195C: beq         $v0, $zero, L_803819E0
    if (ctx->r2 == 0) {
        // 0x80381960: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803819E0;
    }
    // 0x80381960: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80381964:
    // 0x80381964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80381968: jal         0x80381130
    // 0x8038196C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_ovl8_80381130(rdram, ctx);
        goto after_1;
    // 0x8038196C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_1:
    // 0x80381970: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80381974: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80381978: addiu       $t6, $t6, -0x4374
    ctx->r14 = ADD32(ctx->r14, -0X4374);
    // 0x8038197C: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x80381980: sw          $a2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r6;
    // 0x80381984: lw          $v1, 0x30($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X30);
    // 0x80381988: lui         $a1, 0x4CBE
    ctx->r5 = S32(0X4CBE << 16);
    // 0x8038198C: ori         $a1, $a1, 0xBC20
    ctx->r5 = ctx->r5 | 0XBC20;
    // 0x80381990: lw          $t9, 0x5C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X5C);
    // 0x80381994: lh          $t7, 0x58($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X58);
    // 0x80381998: jalr        $t9
    // 0x8038199C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8038199C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_2:
    // 0x803819A0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x803819A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803819A8: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
    // 0x803819AC: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x803819B0: sll         $a2, $v1, 3
    ctx->r6 = S32(ctx->r3 << 3);
    // 0x803819B4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x803819B8: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x803819BC: sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // 0x803819C0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x803819C4: jal         0x803716D8
    // 0x803819C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803716D8(rdram, ctx);
        goto after_3;
    // 0x803819C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x803819CC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x803819D0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x803819D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803819D8: jal         0x800343E0
    // 0x803819DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x803819DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
L_803819E0:
    // 0x803819E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803819E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803819E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803819EC: jr          $ra
    // 0x803819F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803819F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itSawamuraAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018276C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80182770: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80182774: lw          $v0, 0x74($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X74);
    // 0x80182778: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x8018277C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80182780: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80182784: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80182788: jal         0x80172558
    // 0x8018278C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8018278C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80182790: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80182794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80182798: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8018279C: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x801827A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801827A4: bnel        $v1, $at, L_801827EC
    if (ctx->r3 != ctx->r1) {
        // 0x801827A8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_801827EC;
    }
    goto skip_0;
    // 0x801827A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x801827AC: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x801827B0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801827B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801827B8: lh          $t7, 0x78($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X78);
    // 0x801827BC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801827C0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801827C4: nop

    // 0x801827C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801827CC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801827D0: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x801827D4: nop

    // 0x801827D8: bc1fl       L_801827EC
    if (!c1cs) {
        // 0x801827DC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_801827EC;
    }
    goto skip_1;
    // 0x801827DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x801827E0: b           L_8018284C
    // 0x801827E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018284C;
    // 0x801827E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801827E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_801827EC:
    // 0x801827EC: bne         $v1, $at, L_80182830
    if (ctx->r3 != ctx->r1) {
        // 0x801827F0: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80182830;
    }
    // 0x801827F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801827F4: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x801827F8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801827FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80182800: lh          $t9, 0x7A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X7A);
    // 0x80182804: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80182808: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8018280C: nop

    // 0x80182810: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80182814: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80182818: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8018281C: nop

    // 0x80182820: bc1fl       L_80182834
    if (!c1cs) {
        // 0x80182824: lhu         $v1, 0x33E($a0)
        ctx->r3 = MEM_HU(ctx->r4, 0X33E);
            goto L_80182834;
    }
    goto skip_2;
    // 0x80182824: lhu         $v1, 0x33E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X33E);
    skip_2:
    // 0x80182828: b           L_8018284C
    // 0x8018282C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018284C;
    // 0x8018282C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80182830:
    // 0x80182830: lhu         $v1, 0x33E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X33E);
L_80182834:
    // 0x80182834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182838: bne         $v1, $zero, L_80182848
    if (ctx->r3 != 0) {
        // 0x8018283C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80182848;
    }
    // 0x8018283C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80182840: b           L_8018284C
    // 0x80182844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018284C;
    // 0x80182844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80182848:
    // 0x80182848: sh          $t0, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r8;
L_8018284C:
    // 0x8018284C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182854: jr          $ra
    // 0x80182858: nop

    return;
    // 0x80182858: nop

;}
RECOMP_FUNC void itHammerThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017627C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80176280: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80176284: jal         0x80172558
    // 0x80176288: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80176288: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_0:
    // 0x8017628C: jal         0x801713F4
    // 0x80176290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80176290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80176294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017629C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801762A0: jr          $ra
    // 0x801762A4: nop

    return;
    // 0x801762A4: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164748: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016474C: jal         0x800DDDDC
    // 0x80164750: addiu       $a1, $a1, 0x4820
    ctx->r5 = ADD32(ctx->r5, 0X4820);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80164750: addiu       $a1, $a1, 0x4820
    ctx->r5 = ADD32(ctx->r5, 0X4820);
    after_0:
    // 0x80164754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016475C: jr          $ra
    // 0x80164760: nop

    return;
    // 0x80164760: nop

;}
RECOMP_FUNC void ifCommonAnnounceCompleteMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114AC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80114AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80114ACC: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80114AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80114AD4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80114AD8: jal         0x80009968
    // 0x80114ADC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80114ADC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80114AE0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80114AE4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80114AE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80114AEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80114AF0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80114AF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80114AF8: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80114AFC: jal         0x80009DF4
    // 0x80114B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80114B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80114B04: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80114B08: addiu       $a2, $a2, -0xECC
    ctx->r6 = ADD32(ctx->r6, -0XECC);
    // 0x80114B0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80114B10: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80114B14: jal         0x80112024
    // 0x80114B18: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    ifCommonAnnounceSetAttr(rdram, ctx);
        goto after_2;
    // 0x80114B18: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_2:
    // 0x80114B1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80114B20: addiu       $a1, $a1, -0xE84
    ctx->r5 = ADD32(ctx->r5, -0XE84);
    // 0x80114B24: jal         0x80112B24
    // 0x80114B28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ifCommonAnnounceSetColors(rdram, ctx);
        goto after_3;
    // 0x80114B28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80114B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80114B30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80114B34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80114B38: jr          $ra
    // 0x80114B3C: nop

    return;
    // 0x80114B3C: nop

;}
RECOMP_FUNC void dbFallsMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6544: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D6548: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800D654C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800D6550: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x800D6554: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D6558: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x800D655C: lui         $a0, 0x1000
    ctx->r4 = S32(0X1000 << 16);
    // 0x800D6560: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x800D6564: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800D6568: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D656C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6570: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D6574: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D6578: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D657C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800D6580: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800D6584: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800D6588: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800D658C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800D6590: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D6594: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x800D6598: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x800D659C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D65A0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D65A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800D65A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D65AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800D65B0: jal         0x8000B93C
    // 0x800D65B4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x800D65B4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_0:
    // 0x800D65B8: bne         $v0, $zero, L_800D65C8
    if (ctx->r2 != 0) {
        // 0x800D65BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D65C8;
    }
    // 0x800D65BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D65C0: b           L_800D65FC
    // 0x800D65C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D65FC;
    // 0x800D65C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D65C8:
    // 0x800D65C8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x800D65CC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800D65D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D65D4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800D65D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D65DC: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x800D65E0: swc1        $f4, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f4.u32l;
    // 0x800D65E4: lwc1        $f6, 0x69EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x800D65E8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800D65EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D65F0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D65F4: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x800D65F8: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
L_800D65FC:
    // 0x800D65FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6600: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D6604: jr          $ra
    // 0x800D6608: nop

    return;
    // 0x800D6608: nop

;}
RECOMP_FUNC void itLGunWeaponAmmoProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80175A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175A08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80175A0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175A10: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80175A14: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80175A18: jal         0x801680EC
    // 0x80175A1C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80175A1C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175A20: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80175A24: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80175A28: jal         0x8001863C
    // 0x80175A2C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80175A2C: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x80175A30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80175A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175A38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80175A3C: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80175A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175A44: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80175A48: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80175A4C: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80175A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175A54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80175A58: jr          $ra
    // 0x80175A5C: nop

    return;
    // 0x80175A5C: nop

;}

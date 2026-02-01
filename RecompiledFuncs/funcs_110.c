#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PTrainingCheckCostumeUsed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133350: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133354: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80133358: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013335C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133360: bne         $a1, $v0, L_801333B4
    if (ctx->r5 != ctx->r2) {
        // 0x80133364: nop
    
            goto L_801333B4;
    }
    // 0x80133364: nop

    // 0x80133368: lw          $t6, -0x7768($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7768);
    // 0x8013336C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80133370: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80133374: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80133378: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8013337C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80133380: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80133384: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80133388: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8013338C: lw          $t9, 0x48($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X48);
    // 0x80133390: bne         $a0, $t9, L_801333AC
    if (ctx->r4 != ctx->r25) {
        // 0x80133394: nop
    
            goto L_801333AC;
    }
    // 0x80133394: nop

    // 0x80133398: lw          $t0, 0x4C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4C);
    // 0x8013339C: bne         $a2, $t0, L_801333AC
    if (ctx->r6 != ctx->r8) {
        // 0x801333A0: nop
    
            goto L_801333AC;
    }
    // 0x801333A0: nop

    // 0x801333A4: jr          $ra
    // 0x801333A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801333A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801333AC:
    // 0x801333AC: jr          $ra
    // 0x801333B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801333B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801333B4:
    // 0x801333B4: lw          $t1, -0x7768($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7768);
    // 0x801333B8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801333BC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x801333C0: bne         $a1, $t1, L_80133400
    if (ctx->r5 != ctx->r9) {
        // 0x801333C4: sll         $t2, $t2, 3
        ctx->r10 = S32(ctx->r10 << 3);
            goto L_80133400;
    }
    // 0x801333C4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801333C8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x801333CC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801333D0: addiu       $t3, $t3, -0x7AA8
    ctx->r11 = ADD32(ctx->r11, -0X7AA8);
    // 0x801333D4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801333D8: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x801333DC: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x801333E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801333E4: bne         $a0, $t4, L_80133400
    if (ctx->r4 != ctx->r12) {
        // 0x801333E8: nop
    
            goto L_80133400;
    }
    // 0x801333E8: nop

    // 0x801333EC: lw          $t5, 0x4C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4C);
    // 0x801333F0: bne         $a2, $t5, L_80133400
    if (ctx->r6 != ctx->r13) {
        // 0x801333F4: nop
    
            goto L_80133400;
    }
    // 0x801333F4: nop

    // 0x801333F8: jr          $ra
    // 0x801333FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801333FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133400:
    // 0x80133400: jr          $ra
    // 0x80133404: nop

    return;
    // 0x80133404: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E648: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8001E64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E650: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001E654: blez        $t6, L_8001E680
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001E658: nop
    
            goto L_8001E680;
    }
    // 0x8001E658: nop

    // 0x8001E65C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_8001E660:
    // 0x8001E660: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E664: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001E668: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8001E66C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x8001E670: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001E674: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001E678: bnel        $at, $zero, L_8001E660
    if (ctx->r1 != 0) {
        // 0x8001E67C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_8001E660;
    }
    goto skip_0;
    // 0x8001E67C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_8001E680:
    // 0x8001E680: jr          $ra
    // 0x8001E684: nop

    return;
    // 0x8001E684: nop

;}
RECOMP_FUNC void func_ovl8_80381274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381274: bne         $a1, $zero, L_8038128C
    if (ctx->r5 != 0) {
        // 0x80381278: sll         $t1, $a1, 2
        ctx->r9 = S32(ctx->r5 << 2);
            goto L_8038128C;
    }
    // 0x80381278: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8038127C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80381280: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80381284: jr          $ra
    // 0x80381288: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    return;
    // 0x80381288: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_8038128C:
    // 0x8038128C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80381290: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80381294: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80381298: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8038129C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x803812A0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x803812A4: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x803812A8: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    // 0x803812AC: subu        $t5, $t4, $a1
    ctx->r13 = SUB32(ctx->r12, ctx->r5);
    // 0x803812B0: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x803812B4: jr          $ra
    // 0x803812B8: nop

    return;
    // 0x803812B8: nop

;}
RECOMP_FUNC void efGroundSetupRandomWeights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801169CC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801169D0: addiu       $t4, $t4, 0x1AD8
    ctx->r12 = ADD32(ctx->r12, 0X1AD8);
    // 0x801169D4: lw          $v1, 0x18($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X18);
    // 0x801169D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801169DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801169E0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x801169E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801169E8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801169EC: blez        $v0, L_80116A24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801169F0: lw          $t2, 0x4($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X4);
            goto L_80116A24;
    }
    // 0x801169F0: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x801169F4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
L_801169F8:
    // 0x801169F8: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801169FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80116A00: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80116A04: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80116A08: mflo        $t6
    ctx->r14 = lo;
    // 0x80116A0C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80116A10: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x80116A14: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80116A18: bne         $at, $zero, L_801169F8
    if (ctx->r1 != 0) {
        // 0x80116A1C: andi        $t0, $t0, 0xFF
        ctx->r8 = ctx->r8 & 0XFF;
            goto L_801169F8;
    }
    // 0x80116A1C: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x80116A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80116A24:
    // 0x80116A24: or          $t3, $t0, $zero
    ctx->r11 = ctx->r8 | 0;
    // 0x80116A28: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80116A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80116A30: sb          $a2, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r6;
    // 0x80116A34: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x80116A38: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80116A3C: jal         0x80004980
    // 0x80116A40: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80116A40: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x80116A44: lbu         $t0, 0x23($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X23);
    // 0x80116A48: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80116A4C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80116A50: addiu       $t4, $t4, 0x1AD8
    ctx->r12 = ADD32(ctx->r12, 0X1AD8);
    // 0x80116A54: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80116A58: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x80116A5C: sb          $t0, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r8;
    // 0x80116A60: lbu         $a2, 0x22($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X22);
    // 0x80116A64: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80116A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80116A6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80116A70: blez        $t3, L_80116AC0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80116A74: lbu         $a3, 0x8($t2)
        ctx->r7 = MEM_BU(ctx->r10, 0X8);
            goto L_80116AC0;
    }
    // 0x80116A74: lbu         $a3, 0x8($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X8);
    // 0x80116A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80116A7C:
    // 0x80116A7C: bne         $v0, $a3, L_80116AA4
    if (ctx->r2 != ctx->r7) {
        // 0x80116A80: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80116AA4;
    }
    // 0x80116A80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80116A84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80116A88: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80116A8C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80116A90: mflo        $t9
    ctx->r25 = lo;
    // 0x80116A94: addu        $t5, $t2, $t9
    ctx->r13 = ADD32(ctx->r10, ctx->r25);
    // 0x80116A98: lbu         $t6, 0x8($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X8);
    // 0x80116A9C: addu        $a3, $a1, $t6
    ctx->r7 = ADD32(ctx->r5, ctx->r14);
    // 0x80116AA0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_80116AA4:
    // 0x80116AA4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80116AA8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80116AAC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80116AB0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80116AB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80116AB8: bne         $at, $zero, L_80116A7C
    if (ctx->r1 != 0) {
        // 0x80116ABC: sb          $v1, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r3;
            goto L_80116A7C;
    }
    // 0x80116ABC: sb          $v1, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r3;
L_80116AC0:
    // 0x80116AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80116AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80116AC8: jr          $ra
    // 0x80116ACC: nop

    return;
    // 0x80116ACC: nop

;}
RECOMP_FUNC void itGShellSpinSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178EE4: jal         0x80178E04
    // 0x80178EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itGShellSpinInitVars(rdram, ctx);
        goto after_0;
    // 0x80178EE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80178EEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178EF0: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178EF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80178EF8: jal         0x80172EC8
    // 0x80178EFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80178EFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80178F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178F08: jr          $ra
    // 0x80178F0C: nop

    return;
    // 0x80178F0C: nop

;}
RECOMP_FUNC void grDisplayLayer2SecProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801051D0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x801051D4: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x801051D8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801051DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801051E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801051E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801051E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801051EC: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801051F0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801051F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801051F8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801051FC: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x80105200: ori         $t5, $t5, 0xFFFE
    ctx->r13 = ctx->r13 | 0XFFFE;
    // 0x80105204: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80105208: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010520C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80105210: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80105214: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80105218: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x8010521C: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80105220: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80105224: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80105228: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x8010522C: ori         $t9, $t9, 0x2048
    ctx->r25 = ctx->r25 | 0X2048;
    // 0x80105230: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80105234: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80105238: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8010523C: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80105240: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80105244: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80105248: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010524C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80105250: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80105254: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80105258: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8010525C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80105260: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80105264: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80105268: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8010526C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80105270: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80105274: sw          $ra, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r31;
    // 0x80105278: jal         0x80014768
    // 0x8010527C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x8010527C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_0:
    // 0x80105280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105288: jr          $ra
    // 0x8010528C: nop

    return;
    // 0x8010528C: nop

;}
RECOMP_FUNC void ftSamusSpecialNGetChargeShotPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D35C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015D360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D364: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8015D368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015D36C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D370: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8015D374: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8015D378: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8015D37C: jal         0x800EDF24
    // 0x8015D380: lw          $a0, 0x928($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X928);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015D380: lw          $a0, 0x928($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X928);
    after_0:
    // 0x8015D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D38C: jr          $ra
    // 0x8015D390: nop

    return;
    // 0x8015D390: nop

;}
RECOMP_FUNC void sSC1PIntroCheckCostumeUsed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133934: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013393C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80133940: beq         $a0, $at, L_8013395C
    if (ctx->r4 == ctx->r1) {
        // 0x80133944: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8013395C;
    }
    // 0x80133944: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80133948: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013394C: beq         $a0, $at, L_801339D4
    if (ctx->r4 == ctx->r1) {
        // 0x80133950: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_801339D4;
    }
    // 0x80133950: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133954: b           L_80133A84
    // 0x80133958: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
        goto L_80133A84;
    // 0x80133958: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_8013395C:
    // 0x8013395C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133960: lw          $t6, 0x5CC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CC8);
    // 0x80133964: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80133968: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8013396C: bne         $a3, $t6, L_80133998
    if (ctx->r7 != ctx->r14) {
        // 0x80133970: nop
    
            goto L_80133998;
    }
    // 0x80133970: nop

    // 0x80133974: jal         0x800EC0EC
    // 0x80133978: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80133978: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013397C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133980: lw          $t7, 0x5CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5CCC);
    // 0x80133984: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80133988: bne         $v0, $t7, L_80133998
    if (ctx->r2 != ctx->r15) {
        // 0x8013398C: nop
    
            goto L_80133998;
    }
    // 0x8013398C: nop

    // 0x80133990: b           L_80133AB8
    // 0x80133994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x80133994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133998:
    // 0x80133998: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013399C: lw          $t8, 0x5CD8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5CD8);
    // 0x801339A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801339A4: bne         $a3, $t8, L_801339CC
    if (ctx->r7 != ctx->r24) {
        // 0x801339A8: nop
    
            goto L_801339CC;
    }
    // 0x801339A8: nop

    // 0x801339AC: jal         0x800EC0EC
    // 0x801339B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x801339B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801339B4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801339B8: lw          $t9, 0x5CDC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5CDC);
    // 0x801339BC: bne         $v0, $t9, L_801339CC
    if (ctx->r2 != ctx->r25) {
        // 0x801339C0: nop
    
            goto L_801339CC;
    }
    // 0x801339C0: nop

    // 0x801339C4: b           L_80133AB8
    // 0x801339C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x801339C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801339CC:
    // 0x801339CC: b           L_80133AB8
    // 0x801339D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133AB8;
    // 0x801339D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801339D4:
    // 0x801339D4: lw          $t0, 0x5CC8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5CC8);
    // 0x801339D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801339DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801339E0: bne         $a3, $t0, L_80133A0C
    if (ctx->r7 != ctx->r8) {
        // 0x801339E4: nop
    
            goto L_80133A0C;
    }
    // 0x801339E4: nop

    // 0x801339E8: jal         0x800EC0EC
    // 0x801339EC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_2;
    // 0x801339EC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x801339F0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801339F4: lw          $t1, 0x5CCC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5CCC);
    // 0x801339F8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801339FC: bne         $v0, $t1, L_80133A0C
    if (ctx->r2 != ctx->r9) {
        // 0x80133A00: nop
    
            goto L_80133A0C;
    }
    // 0x80133A00: nop

    // 0x80133A04: b           L_80133AB8
    // 0x80133A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x80133A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133A0C:
    // 0x80133A0C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133A10: lw          $t2, 0x5CD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5CD8);
    // 0x80133A14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80133A18: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80133A1C: bne         $a3, $t2, L_80133A48
    if (ctx->r7 != ctx->r10) {
        // 0x80133A20: nop
    
            goto L_80133A48;
    }
    // 0x80133A20: nop

    // 0x80133A24: jal         0x800EC0EC
    // 0x80133A28: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_3;
    // 0x80133A28: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80133A2C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133A30: lw          $t3, 0x5CDC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5CDC);
    // 0x80133A34: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80133A38: bne         $v0, $t3, L_80133A48
    if (ctx->r2 != ctx->r11) {
        // 0x80133A3C: nop
    
            goto L_80133A48;
    }
    // 0x80133A3C: nop

    // 0x80133A40: b           L_80133AB8
    // 0x80133A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x80133A44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133A48:
    // 0x80133A48: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133A4C: lw          $t4, 0x5CE8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5CE8);
    // 0x80133A50: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80133A54: bne         $a3, $t4, L_80133A7C
    if (ctx->r7 != ctx->r12) {
        // 0x80133A58: nop
    
            goto L_80133A7C;
    }
    // 0x80133A58: nop

    // 0x80133A5C: jal         0x800EC0EC
    // 0x80133A60: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_4;
    // 0x80133A60: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80133A64: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133A68: lw          $t5, 0x5CEC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5CEC);
    // 0x80133A6C: bne         $v0, $t5, L_80133A7C
    if (ctx->r2 != ctx->r13) {
        // 0x80133A70: nop
    
            goto L_80133A7C;
    }
    // 0x80133A70: nop

    // 0x80133A74: b           L_80133AB8
    // 0x80133A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x80133A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133A7C:
    // 0x80133A7C: b           L_80133AB8
    // 0x80133A80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133AB8;
    // 0x80133A80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133A84:
    // 0x80133A84: lw          $t6, 0x5CC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CC8);
    // 0x80133A88: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80133A8C: bnel        $a3, $t6, L_80133AB8
    if (ctx->r7 != ctx->r14) {
        // 0x80133A90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133AB8;
    }
    goto skip_0;
    // 0x80133A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80133A94: jal         0x800EC0EC
    // 0x80133A98: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_5;
    // 0x80133A98: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80133A9C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133AA0: lw          $t7, 0x5CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5CCC);
    // 0x80133AA4: bnel        $v0, $t7, L_80133AB8
    if (ctx->r2 != ctx->r15) {
        // 0x80133AA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133AB8;
    }
    goto skip_1;
    // 0x80133AA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80133AAC: b           L_80133AB8
    // 0x80133AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133AB8;
    // 0x80133AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80133AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133AB8:
    // 0x80133AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133AC0: jr          $ra
    // 0x80133AC4: nop

    return;
    // 0x80133AC4: nop

;}
RECOMP_FUNC void mnVSItemSwitchLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CA4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131CA8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131CAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131CB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131CBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131CC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131CC4: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80131CC8: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131CCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131CD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CD4: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80131CD8: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80131CDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131CE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131CE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131CE8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131CEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131CF0: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80131CF4: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80131CF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131CFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131D00: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80131D04: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80131D08: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131D0C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131D10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D14: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80131D18: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80131D1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131D20: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131D24: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80131D28: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80131D2C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131D30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131D34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D38: lui         $t9, 0x8080
    ctx->r25 = S32(0X8080 << 16);
    // 0x80131D3C: ori         $t9, $t9, 0x80FF
    ctx->r25 = ctx->r25 | 0X80FF;
    // 0x80131D40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131D44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131D48: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80131D4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131D50: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131D54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D58: lui         $t8, 0x13
    ctx->r24 = S32(0X13 << 16);
    // 0x80131D5C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80131D60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131D64: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131D68: ori         $t7, $t7, 0x809C
    ctx->r15 = ctx->r15 | 0X809C;
    // 0x80131D6C: ori         $t8, $t8, 0xC088
    ctx->r24 = ctx->r24 | 0XC088;
    // 0x80131D70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131D74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131D78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D7C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80131D80: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80131D84: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131D88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131D8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131D90: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131D94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131D98: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80131D9C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80131DA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131DA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131DA8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131DAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131DB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131DB4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80131DB8: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80131DBC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131DC0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131DC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131DC8: jal         0x800CCEAC
    // 0x80131DCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80131DCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80131DD0: jal         0x800CCF00
    // 0x80131DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80131DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80131DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131DE0: jr          $ra
    // 0x80131DE4: nop

    return;
    // 0x80131DE4: nop

;}
RECOMP_FUNC void efManagerSparkleWhiteMultiMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100528: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010052C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100530: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80100534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010053C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80100540: jal         0x800CE9E8
    // 0x80100544: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80100544: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x80100548: beq         $v0, $zero, L_801005B0
    if (ctx->r2 == 0) {
        // 0x8010054C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801005B0;
    }
    // 0x8010054C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100554: jal         0x800CE1DC
    // 0x80100558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80100558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8010055C: beq         $v0, $zero, L_801005A4
    if (ctx->r2 == 0) {
        // 0x80100560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801005A4;
    }
    // 0x80100560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100564: jal         0x800CEA14
    // 0x80100568: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80100568: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010056C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80100570: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80100574: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80100578: bnel        $t6, $zero, L_8010058C
    if (ctx->r14 != 0) {
        // 0x8010057C: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_8010058C;
    }
    goto skip_0;
    // 0x8010057C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80100580: b           L_801005B4
    // 0x80100584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801005B4;
    // 0x80100584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100588: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_8010058C:
    // 0x8010058C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80100590: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80100594: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80100598: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8010059C: b           L_801005B0
    // 0x801005A0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_801005B0;
    // 0x801005A0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_801005A4:
    // 0x801005A4: jal         0x800CEA40
    // 0x801005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x801005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801005AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801005B0:
    // 0x801005B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_801005B4:
    // 0x801005B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801005B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801005BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801005C0: jr          $ra
    // 0x801005C4: nop

    return;
    // 0x801005C4: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateSpeedDisplaySprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E714: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E718: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018E71C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8018E720: lw          $t7, 0x28($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X28);
    // 0x8018E724: lw          $t6, 0x48($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X48);
    // 0x8018E728: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018E72C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018E730: lw          $t1, 0x6C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6C);
    // 0x8018E734: lw          $t4, 0x74($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X74);
    // 0x8018E738: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
L_8018E73C:
    // 0x8018E73C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018E740: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018E744: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018E748: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018E74C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018E750: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018E754: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018E758: bne         $t1, $t5, L_8018E73C
    if (ctx->r9 != ctx->r13) {
        // 0x8018E75C: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018E73C;
    }
    // 0x8018E75C: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018E760: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018E764: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018E768: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018E76C: jr          $ra
    // 0x8018E770: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    return;
    // 0x8018E770: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
;}
RECOMP_FUNC void lbParticleEjectTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE190: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x800CE194: beq         $v0, $zero, L_800CE1A8
    if (ctx->r2 == 0) {
        // 0x800CE198: nop
    
            goto L_800CE1A8;
    }
    // 0x800CE198: nop

    // 0x800CE19C: jalr        $v0
    // 0x800CE1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800CE1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CE1A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800CE1A8:
    // 0x800CE1A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CE1AC: addiu       $v0, $v0, 0x6454
    ctx->r2 = ADD32(ctx->r2, 0X6454);
    // 0x800CE1B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800CE1B4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CE1B8: addiu       $v1, $v1, 0x644C
    ctx->r3 = ADD32(ctx->r3, 0X644C);
    // 0x800CE1BC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CE1C0: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800CE1C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE1C8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800CE1CC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800CE1D0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800CE1D4: jr          $ra
    // 0x800CE1D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CE1D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnMapsGetCharacterID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131BE8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80131BEC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80131BF0: beq         $a0, $at, L_80131C34
    if (ctx->r4 == ctx->r1) {
        // 0x80131BF4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131C34;
    }
    // 0x80131BF4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131BF8: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80131BFC: beq         $a0, $at, L_80131C24
    if (ctx->r4 == ctx->r1) {
        // 0x80131C00: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_80131C24;
    }
    // 0x80131C00: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80131C04: beq         $a0, $at, L_80131C1C
    if (ctx->r4 == ctx->r1) {
        // 0x80131C08: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80131C1C;
    }
    // 0x80131C08: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80131C0C: beq         $a0, $at, L_80131C2C
    if (ctx->r4 == ctx->r1) {
        // 0x80131C10: nop
    
            goto L_80131C2C;
    }
    // 0x80131C10: nop

    // 0x80131C14: b           L_80131C3C
    // 0x80131C18: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
        goto L_80131C3C;
    // 0x80131C18: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
L_80131C1C:
    // 0x80131C1C: jr          $ra
    // 0x80131C20: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    return;
    // 0x80131C20: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_80131C24:
    // 0x80131C24: jr          $ra
    // 0x80131C28: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80131C28: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80131C2C:
    // 0x80131C2C: jr          $ra
    // 0x80131C30: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80131C30: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80131C34:
    // 0x80131C34: jr          $ra
    // 0x80131C38: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80131C38: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80131C3C:
    // 0x80131C3C: bne         $at, $zero, L_80131C4C
    if (ctx->r1 != 0) {
        // 0x80131C40: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_80131C4C;
    }
    // 0x80131C40: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x80131C44: bne         $at, $zero, L_80131C54
    if (ctx->r1 != 0) {
        // 0x80131C48: addiu       $v0, $v1, -0x41
        ctx->r2 = ADD32(ctx->r3, -0X41);
            goto L_80131C54;
    }
    // 0x80131C48: addiu       $v0, $v1, -0x41
    ctx->r2 = ADD32(ctx->r3, -0X41);
L_80131C4C:
    // 0x80131C4C: jr          $ra
    // 0x80131C50: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    return;
    // 0x80131C50: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_80131C54:
    // 0x80131C54: jr          $ra
    // 0x80131C58: nop

    return;
    // 0x80131C58: nop

;}
RECOMP_FUNC void syMainThread1Idle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800007CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800007D0: jal         0x80023338
    // 0x800007D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    syDebugStartRmonThread8(rdram, ctx);
        goto after_0;
    // 0x800007D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800007D8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800007DC: addiu       $t6, $t6, 0x4290
    ctx->r14 = ADD32(ctx->r14, 0X4290);
    // 0x800007E0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800007E4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800007E8: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800007EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800007F0: addiu       $a2, $a2, 0x5D8
    ctx->r6 = ADD32(ctx->r6, 0X5D8);
    // 0x800007F4: addiu       $a0, $a0, 0xCE0
    ctx->r4 = ADD32(ctx->r4, 0XCE0);
    // 0x800007F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800007FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80000800: jal         0x80031E20
    // 0x80000804: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80000804: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80000808: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8000080C: lw          $t0, -0x492C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X492C);
    // 0x80000810: lui         $t9, 0xFEDC
    ctx->r25 = S32(0XFEDC << 16);
    // 0x80000814: ori         $t9, $t9, 0xBA98
    ctx->r25 = ctx->r25 | 0XBA98;
    // 0x80000818: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8000081C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000820: sw          $t8, 0xEC8($at)
    MEM_W(0XEC8, ctx->r1) = ctx->r24;
    // 0x80000824: bne         $t0, $zero, L_80000838
    if (ctx->r8 != 0) {
        // 0x80000828: sw          $t9, 0xECC($at)
        MEM_W(0XECC, ctx->r1) = ctx->r25;
            goto L_80000838;
    }
    // 0x80000828: sw          $t9, 0xECC($at)
    MEM_W(0XECC, ctx->r1) = ctx->r25;
    // 0x8000082C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000830: jal         0x80039190
    // 0x80000834: addiu       $a0, $a0, 0xCE0
    ctx->r4 = ADD32(ctx->r4, 0XCE0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80000834: addiu       $a0, $a0, 0xCE0
    ctx->r4 = ADD32(ctx->r4, 0XCE0);
    after_2:
L_80000838:
    // 0x80000838: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000083C: jal         0x80034790
    // 0x80000840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x80000840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80000844:
    // 0x80000844: b           L_80000844
    pause_self(rdram);
    // 0x80000848: nop

    // 0x8000084C: nop

    // 0x80000850: nop

    // 0x80000854: nop

    // 0x80000858: nop

    // 0x8000085C: nop

    // 0x80000860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80000864: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000868: jr          $ra
    // 0x8000086C: nop

    return;
    // 0x8000086C: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetNextPortraitX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013243C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132440: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132444: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80132448: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8013244C: addiu       $t6, $t6, -0x7860
    ctx->r14 = ADD32(ctx->r14, -0X7860);
    // 0x80132450: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80132454: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80132458: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8013245C:
    // 0x8013245C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132460: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132464: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132468: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013246C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132470: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132474: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132478: bne         $t6, $t0, L_8013245C
    if (ctx->r14 != ctx->r8) {
        // 0x8013247C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013245C;
    }
    // 0x8013247C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132480: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132484: addiu       $t1, $t1, -0x7830
    ctx->r9 = ADD32(ctx->r9, -0X7830);
    // 0x80132488: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x8013248C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_80132490:
    // 0x80132490: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132494: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132498: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8013249C: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x801324A0: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x801324A4: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x801324A8: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x801324AC: bne         $t1, $t5, L_80132490
    if (ctx->r9 != ctx->r13) {
        // 0x801324B0: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_80132490;
    }
    // 0x801324B0: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x801324B4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x801324B8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x801324BC: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801324C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801324C4: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x801324C8: nop

    // 0x801324CC: bc1fl       L_801324E4
    if (!c1cs) {
        // 0x801324D0: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_801324E4;
    }
    goto skip_0;
    // 0x801324D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x801324D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324D8: b           L_80132548
    // 0x801324DC: nop

        goto L_80132548;
    // 0x801324DC: nop

    // 0x801324E0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_801324E4:
    // 0x801324E4: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x801324E8: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x801324EC: bc1fl       L_80132524
    if (!c1cs) {
        // 0x801324F0: lwc1        $f6, 0x0($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
            goto L_80132524;
    }
    goto skip_1;
    // 0x801324F0: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    skip_1:
    // 0x801324F4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801324F8: add.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x801324FC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80132500: nop

    // 0x80132504: bc1fl       L_80132518
    if (!c1cs) {
        // 0x80132508: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80132518;
    }
    goto skip_2;
    // 0x80132508: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x8013250C: b           L_80132548
    // 0x80132510: nop

        goto L_80132548;
    // 0x80132510: nop

    // 0x80132514: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80132518:
    // 0x80132518: b           L_80132548
    // 0x8013251C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80132548;
    // 0x8013251C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80132520: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
L_80132524:
    // 0x80132524: add.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80132528: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8013252C: nop

    // 0x80132530: bc1fl       L_80132544
    if (!c1cs) {
        // 0x80132534: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80132544;
    }
    goto skip_3;
    // 0x80132534: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_3:
    // 0x80132538: b           L_80132544
    // 0x8013253C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80132544;
    // 0x8013253C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80132540: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80132544:
    // 0x80132544: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80132548:
    // 0x80132548: jr          $ra
    // 0x8013254C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8013254C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void syTaskmanSetLoadScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80005C78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005C7C: jr          $ra
    // 0x80005C80: sw          $t6, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = ctx->r14;
    return;
    // 0x80005C80: sw          $t6, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void ftSamusSpecialLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E220: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E228: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E22C: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015E230: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E234: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
    // 0x8015E238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015E23C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015E240: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E244: jal         0x800E6F24
    // 0x8015E248: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E248: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015E24C: jal         0x800E0830
    // 0x8015E250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015E254: jal         0x8015E218
    // 0x8015E258: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftSamusSpecialLwInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E258: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015E25C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8015E260: sw          $zero, 0xB18($t6)
    MEM_W(0XB18, ctx->r14) = 0;
    // 0x8015E264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015E26C: jr          $ra
    // 0x8015E270: nop

    return;
    // 0x8015E270: nop

;}
RECOMP_FUNC void func_ovl53_80132928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132928: jr          $ra
    // 0x8013292C: nop

    return;
    // 0x8013292C: nop

;}
RECOMP_FUNC void mpCommonCheckFighterOnFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDDA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDDB0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DDDB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DDDB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDDBC: addiu       $a1, $a1, -0x23B0
    ctx->r5 = ADD32(ctx->r5, -0X23B0);
    // 0x800DDDC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DDDC4: jal         0x800DA034
    // 0x800DDDC8: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DDDC8: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DDDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDDD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDDD4: jr          $ra
    // 0x800DDDD8: nop

    return;
    // 0x800DDDD8: nop

;}
RECOMP_FUNC void func_ovl8_80383E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383E98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80383E9C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80383EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80383EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80383EA8: addiu       $at, $at, -0x3274
    ctx->r1 = ADD32(ctx->r1, -0X3274);
    // 0x80383EAC: lwl         $t6, 0x0($at)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r1, 0X0);
    // 0x80383EB0: lwr         $t6, 0x3($at)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r1, 0X3);
    // 0x80383EB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80383EB8: swl         $t6, 0x28($sp)
    do_swl(rdram, 0X28, ctx->r29, ctx->r14);
    // 0x80383EBC: swr         $t6, 0x2B($sp)
    do_swr(rdram, 0X2B, ctx->r29, ctx->r14);
    // 0x80383EC0: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80383EC4: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383EC8: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x80383ECC: lh          $t7, 0xB8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB8);
    // 0x80383ED0: jalr        $t9
    // 0x80383ED4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383ED4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x80383ED8: beq         $v0, $zero, L_80383F60
    if (ctx->r2 == 0) {
        // 0x80383EDC: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80383F60;
    }
    // 0x80383EDC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80383EE0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80383EE4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80383EE8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383EEC: lw          $t9, 0xAC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XAC);
    // 0x80383EF0: lh          $t8, 0xA8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA8);
    // 0x80383EF4: jalr        $t9
    // 0x80383EF8: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383EF8: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    after_1:
    // 0x80383EFC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80383F00: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80383F04: lh          $a2, 0x42($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X42);
    // 0x80383F08: lw          $t9, 0x12C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X12C);
    // 0x80383F0C: lh          $t0, 0x128($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X128);
    // 0x80383F10: jalr        $t9
    // 0x80383F14: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80383F14: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    after_2:
    // 0x80383F18: lh          $t1, 0x2C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2C);
    // 0x80383F1C: lh          $t2, 0x34($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X34);
    // 0x80383F20: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80383F24: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80383F28: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80383F2C: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
    // 0x80383F30: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80383F34: sh          $t6, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r14;
    // 0x80383F38: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80383F3C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80383F40: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80383F44: jal         0x80377AEC
    // 0x80383F48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_3;
    // 0x80383F48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80383F4C: jal         0x80034D50
    // 0x80383F50: nop

    osGetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x80383F50: nop

    after_4:
    // 0x80383F54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80383F58: sw          $v1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r3;
    // 0x80383F5C: sw          $t8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r24;
L_80383F60:
    // 0x80383F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80383F64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80383F68: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80383F6C: jr          $ra
    // 0x80383F70: nop

    return;
    // 0x80383F70: nop

;}
RECOMP_FUNC void ftYoshiSpecialNReleaseProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E44C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015E458: jal         0x8015E3D8
    // 0x8015E45C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftYoshiSpecialNCatchUpdateCaptureVars(rdram, ctx);
        goto after_0;
    // 0x8015E45C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E460: jal         0x800D94C4
    // 0x8015E464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x8015E464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015E468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E470: jr          $ra
    // 0x8015E474: nop

    return;
    // 0x8015E474: nop

;}
RECOMP_FUNC void ftCommonCliffCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144B38: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80144B3C: jal         0x800D9480
    // 0x80144B40: addiu       $a1, $a1, 0x4DF4
    ctx->r5 = ADD32(ctx->r5, 0X4DF4);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144B40: addiu       $a1, $a1, 0x4DF4
    ctx->r5 = ADD32(ctx->r5, 0X4DF4);
    after_0:
    // 0x80144B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144B4C: jr          $ra
    // 0x80144B50: nop

    return;
    // 0x80144B50: nop

;}
RECOMP_FUNC void ifCommonAnnounceCompleteInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80114D60: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x80114D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114D68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114D6C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114D70: addiu       $a1, $a1, 0x42B4
    ctx->r5 = ADD32(ctx->r5, 0X42B4);
    // 0x80114D74: addiu       $a0, $a0, 0x4B40
    ctx->r4 = ADD32(ctx->r4, 0X4B40);
    // 0x80114D78: jal         0x80114B80
    // 0x80114D7C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_0;
    // 0x80114D7C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_0:
    // 0x80114D80: jal         0x80114AC4
    // 0x80114D84: nop

    ifCommonAnnounceCompleteMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80114D84: nop

    after_1:
    // 0x80114D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114D90: jr          $ra
    // 0x80114D94: nop

    return;
    // 0x80114D94: nop

;}
RECOMP_FUNC void ftKirbySpecialNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162000: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162004: jal         0x800D9480
    // 0x80162008: addiu       $a1, $a1, 0x31A0
    ctx->r5 = ADD32(ctx->r5, 0X31A0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80162008: addiu       $a1, $a1, 0x31A0
    ctx->r5 = ADD32(ctx->r5, 0X31A0);
    after_0:
    // 0x8016200C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162014: jr          $ra
    // 0x80162018: nop

    return;
    // 0x80162018: nop

;}
RECOMP_FUNC void lbParticleGetTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE0D8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CE0DC: addiu       $v0, $v0, 0x6454
    ctx->r2 = ADD32(ctx->r2, 0X6454);
    // 0x800CE0E0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800CE0E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CE0E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800CE0EC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800CE0F0: beq         $v1, $zero, L_800CE180
    if (ctx->r3 == 0) {
        // 0x800CE0F4: andi        $a0, $a0, 0xFF
        ctx->r4 = ctx->r4 & 0XFF;
            goto L_800CE180;
    }
    // 0x800CE0F4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800CE0F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800CE0FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CE100: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800CE104: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CE108: sh          $t7, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r15;
    // 0x800CE10C: lbu         $t8, 0x5D5C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5D5C);
    // 0x800CE110: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CE114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CE118: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CE11C: sb          $a0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r4;
    // 0x800CE120: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CE124: sh          $a1, 0xB8($v1)
    MEM_H(0XB8, ctx->r3) = ctx->r5;
    // 0x800CE128: sw          $zero, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = 0;
    // 0x800CE12C: addiu       $a0, $a0, 0x644C
    ctx->r4 = ADD32(ctx->r4, 0X644C);
    // 0x800CE130: sb          $t8, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r24;
    // 0x800CE134: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800CE138: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800CE13C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800CE140: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x800CE144: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x800CE148: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x800CE14C: swc1        $f2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f2.u32l;
    // 0x800CE150: swc1        $f2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f2.u32l;
    // 0x800CE154: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x800CE158: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x800CE15C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CE160: addiu       $a1, $a1, 0x6452
    ctx->r5 = ADD32(ctx->r5, 0X6452);
    // 0x800CE164: lhu         $t1, 0x0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X0);
    // 0x800CE168: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CE16C: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x800CE170: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CE174: beq         $at, $zero, L_800CE180
    if (ctx->r1 == 0) {
        // 0x800CE178: sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
            goto L_800CE180;
    }
    // 0x800CE178: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800CE17C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800CE180:
    // 0x800CE180: jr          $ra
    // 0x800CE184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800CE184: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PBonusPortraitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132158: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013215C: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x80132160: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80132164: lw          $a1, 0x58($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X58);
    // 0x80132168: jal         0x80132030
    // 0x8013216C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    mnPlayers1PBonusGetNextPortraitX(rdram, ctx);
        goto after_0;
    // 0x8013216C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80132170: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80132174: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132178: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8013217C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80132180: nop

    // 0x80132184: bc1tl       L_801321C0
    if (c1cs) {
        // 0x80132188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801321C0;
    }
    goto skip_0;
    // 0x80132188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013218C: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80132190: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132194: swc1        $f0, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f0.u32l;
    // 0x80132198: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x8013219C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801321A0: beql        $v1, $zero, L_801321C0
    if (ctx->r3 == 0) {
        // 0x801321A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801321C0;
    }
    goto skip_1;
    // 0x801321A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801321A8: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801321AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801321B0: nop

    // 0x801321B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801321B8: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x801321BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801321C0:
    // 0x801321C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801321C4: jr          $ra
    // 0x801321C8: nop

    return;
    // 0x801321C8: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801340FC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134104: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134108: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013410C: addiu       $a0, $a0, 0x4238
    ctx->r4 = ADD32(ctx->r4, 0X4238);
    // 0x80134110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134114: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134118: jal         0x80007024
    // 0x8013411C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013411C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80134120: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134124: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134128: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013412C: addiu       $t9, $t9, 0x4540
    ctx->r25 = ADD32(ctx->r25, 0X4540);
    // 0x80134130: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80134134: addiu       $a0, $a0, 0x4254
    ctx->r4 = ADD32(ctx->r4, 0X4254);
    // 0x80134138: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8013413C: jal         0x800A2698
    // 0x80134140: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80134140: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80134144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134148: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013414C: lw          $t1, 0x4360($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4360);
    // 0x80134150: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80134154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134158: jr          $ra
    // 0x8013415C: sb          $t1, 0x4AE1($at)
    MEM_B(0X4AE1, ctx->r1) = ctx->r9;
    return;
    // 0x8013415C: sb          $t1, 0x4AE1($at)
    MEM_B(0X4AE1, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void func_ovl2_800EBD08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBD08: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800EBD0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EBD10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800EBD14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EBD18: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800EBD1C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800EBD20: lw          $s0, 0x10($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X10);
    // 0x800EBD24: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800EBD28: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800EBD2C: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800EBD30: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EBD34: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EBD38: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EBD3C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EBD40: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800EBD44: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x800EBD48: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800EBD4C: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EBD50: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EBD54: jal         0x80033510
    // 0x800EBD58: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EBD58: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    after_0:
    // 0x800EBD5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800EBD60: jal         0x80033510
    // 0x800EBD64: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800EBD64: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800EBD68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800EBD6C: jal         0x800C7840
    // 0x800EBD70: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x800EBD70: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    after_2:
    // 0x800EBD74: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x800EBD78: jal         0x800C78B8
    // 0x800EBD7C: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x800EBD7C: lwc1        $f12, 0xB4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB4);
    after_3:
    // 0x800EBD80: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EBD84: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800EBD88: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800EBD8C: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EBD90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800EBD94: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800EBD98: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800EBD9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EBDA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800EBDA4: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800EBDA8: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800EBDAC: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EBDB0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800EBDB4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800EBDB8: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x800EBDBC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EBDC0: div.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800EBDC4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800EBDC8: nop

    // 0x800EBDCC: bc1fl       L_800EBDDC
    if (!c1cs) {
        // 0x800EBDD0: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_800EBDDC;
    }
    goto skip_0;
    // 0x800EBDD0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x800EBDD4: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x800EBDD8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_800EBDDC:
    // 0x800EBDDC: nop

    // 0x800EBDE0: bc1f        L_800EBDEC
    if (!c1cs) {
        // 0x800EBDE4: nop
    
            goto L_800EBDEC;
    }
    // 0x800EBDE4: nop

    // 0x800EBDE8: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800EBDEC:
    // 0x800EBDEC: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800EBDF0: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x800EBDF4: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800EBDF8: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x800EBDFC: jal         0x80033510
    // 0x800EBE00: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800EBE00: sub.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f8.fl;
    after_4:
    // 0x800EBE04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EBE08: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EBE0C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800EBE10: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800EBE14: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x800EBE18: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800EBE1C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EBE20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBE24: bc1f        L_800EBE38
    if (!c1cs) {
        // 0x800EBE28: swc1        $f6, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
            goto L_800EBE38;
    }
    // 0x800EBE28: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x800EBE2C: lwc1        $f14, 0xE4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XE4);
    // 0x800EBE30: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EBE34: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_800EBE38:
    // 0x800EBE38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EBE3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EBE40: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x800EBE44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBE48: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800EBE4C: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x800EBE50: bc1f        L_800EBE5C
    if (!c1cs) {
        // 0x800EBE54: swc1        $f10, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
            goto L_800EBE5C;
    }
    // 0x800EBE54: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800EBE58: lwc1        $f20, 0xE8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0XE8);
L_800EBE5C:
    // 0x800EBE5C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EBE60: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EBE64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EBE68: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800EBE6C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800EBE70: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EBE74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EBE78: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800EBE7C: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800EBE80: div.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800EBE84: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800EBE88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EBE8C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800EBE90: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EBE94: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EBE98: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800EBE9C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800EBEA0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800EBEA4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800EBEA8: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EBEAC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800EBEB0: nop

    // 0x800EBEB4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800EBEB8: nop

    // 0x800EBEBC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800EBEC0: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800EBEC4: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800EBEC8: nop

    // 0x800EBECC: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800EBED0: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EBED4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EBED8: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800EBEDC: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800EBEE0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800EBEE4: nop

    // 0x800EBEE8: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EBEEC: nop

    // 0x800EBEF0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EBEF4: nop

    // 0x800EBEF8: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800EBEFC: nop

    // 0x800EBF00: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EBF04: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EBF08: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EBF0C: mul.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800EBF10: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x800EBF14: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EBF18: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800EBF1C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EBF20: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800EBF24: nop

    // 0x800EBF28: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800EBF2C: add.s       $f0, $f14, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800EBF30: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800EBF34: nop

    // 0x800EBF38: bc1t        L_800EBF58
    if (c1cs) {
        // 0x800EBF3C: nop
    
            goto L_800EBF58;
    }
    // 0x800EBF3C: nop

    // 0x800EBF40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EBF44: nop

    // 0x800EBF48: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x800EBF4C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EBF50: bc1f        L_800EC000
    if (!c1cs) {
        // 0x800EBF54: nop
    
            goto L_800EC000;
    }
    // 0x800EBF54: nop

L_800EBF58:
    // 0x800EBF58: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800EBF5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBF60: bc1f        L_800EBFB0
    if (!c1cs) {
        // 0x800EBF64: nop
    
            goto L_800EBFB0;
    }
    // 0x800EBF64: nop

    // 0x800EBF68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EBF6C: lwc1        $f4, 0xEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEC);
    // 0x800EBF70: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x800EBF74: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EBF78: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EBF7C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800EBF80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EBF84: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800EBF88: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EBF8C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800EBF90: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800EBF94: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800EBF98: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EBF9C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800EBFA0: jal         0x8001863C
    // 0x800EBFA4: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_5;
    // 0x800EBFA4: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    after_5:
    // 0x800EBFA8: b           L_800EBFF4
    // 0x800EBFAC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
        goto L_800EBFF4;
    // 0x800EBFAC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
L_800EBFB0:
    // 0x800EBFB0: lwc1        $f6, 0xF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF0);
    // 0x800EBFB4: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x800EBFB8: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EBFBC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EBFC0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800EBFC4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EBFC8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EBFCC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EBFD0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EBFD4: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EBFD8: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EBFDC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EBFE0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800EBFE4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800EBFE8: jal         0x8001863C
    // 0x800EBFEC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_6;
    // 0x800EBFEC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_6:
    // 0x800EBFF0: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
L_800EBFF4:
    // 0x800EBFF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800EBFF8: b           L_800EC094
    // 0x800EBFFC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
        goto L_800EC094;
    // 0x800EBFFC: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
L_800EC000:
    // 0x800EC000: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800EC004: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800EC008: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x800EC00C: add.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800EC010: jal         0x8001873C
    // 0x800EC014: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcSin(rdram, ctx);
        goto after_7;
    // 0x800EC014: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_7:
    // 0x800EC018: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800EC01C: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800EC020: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800EC024: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EC028: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EC02C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800EC030: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EC034: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800EC038: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800EC03C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EC040: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800EC044: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EC048: mul.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800EC04C: jal         0x8001863C
    // 0x800EC050: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_8;
    // 0x800EC050: nop

    after_8:
    // 0x800EC054: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800EC058: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x800EC05C: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EC060: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EC064: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EC068: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EC06C: nop

    // 0x800EC070: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EC074: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800EC078: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EC07C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800EC080: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800EC084: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800EC088: jal         0x8001863C
    // 0x800EC08C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_9;
    // 0x800EC08C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x800EC090: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_800EC094:
    // 0x800EC094: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800EC098: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800EC09C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800EC0A0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EC0A4: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800EC0A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EC0AC: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800EC0B0: add.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f10.fl;
    // 0x800EC0B4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800EC0B8: jal         0x800187C0
    // 0x800EC0BC: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    syUtilsArcCos(rdram, ctx);
        goto after_10;
    // 0x800EC0BC: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_10:
    // 0x800EC0C0: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x800EC0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EC0C8: jal         0x800EB528
    // 0x800EC0CC: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_11;
    // 0x800EC0CC: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    after_11:
    // 0x800EC0D0: jal         0x800EB528
    // 0x800EC0D4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_12;
    // 0x800EC0D4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_12:
    // 0x800EC0D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EC0DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EC0E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800EC0E4: jr          $ra
    // 0x800EC0E8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800EC0E8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void mvOpeningFoxPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D84C: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D850: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D854: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D858: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D85C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D860: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D864: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D868: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D86C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D870: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D874: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D878: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D87C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D880: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D884: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D888: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D88C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D890: lui         $t7, 0x3C
    ctx->r15 = S32(0X3C << 16);
    // 0x8018D894: ori         $t7, $t7, 0x28FF
    ctx->r15 = ctx->r15 | 0X28FF;
    // 0x8018D898: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D89C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8A0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D8A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8A8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8AC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8B0: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D8B4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8BC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8C0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8C4: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8C8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8CC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8D0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8D4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8D8: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D8DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8E0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8E4: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D8E8: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D8EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D8F0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D8F4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8F8: lui         $t7, 0x34
    ctx->r15 = S32(0X34 << 16);
    // 0x8018D8FC: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8018D900: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D904: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D908: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D90C: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D910: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D914: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D918: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D91C: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D920: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D924: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D928: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D92C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D930: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D934: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D938: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D93C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D940: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D944: jr          $ra
    // 0x8018D948: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D948: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void func_ovl8_803839D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803839D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803839D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803839D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x803839DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x803839E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x803839E4: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    // 0x803839E8: sh          $zero, 0x42($a0)
    MEM_H(0X42, ctx->r4) = 0;
    // 0x803839EC: sh          $zero, 0x44($a0)
    MEM_H(0X44, ctx->r4) = 0;
    // 0x803839F0: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x803839F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803839F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803839FC: beql        $t7, $zero, L_80383A40
    if (ctx->r15 == 0) {
        // 0x80383A00: lw          $v0, 0x38($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X38);
            goto L_80383A40;
    }
    goto skip_0;
    // 0x80383A00: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    skip_0:
    // 0x80383A04: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
L_80383A08:
    // 0x80383A08: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80383A0C: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80383A10: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80383A14: lh          $t8, 0xD0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XD0);
    // 0x80383A18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80383A1C: jalr        $t9
    // 0x80383A20: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383A20: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    after_0:
    // 0x80383A24: lh          $t0, 0x42($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X42);
    // 0x80383A28: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80383A2C: sh          $t1, 0x42($s1)
    MEM_H(0X42, ctx->r17) = ctx->r9;
    // 0x80383A30: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80383A34: bnel        $t2, $zero, L_80383A08
    if (ctx->r10 != 0) {
        // 0x80383A38: lw          $v0, 0x30($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X30);
            goto L_80383A08;
    }
    goto skip_1;
    // 0x80383A38: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    skip_1:
    // 0x80383A3C: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
L_80383A40:
    // 0x80383A40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80383A44: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
    // 0x80383A48: sw          $t3, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r11;
    // 0x80383A4C: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x80383A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383A54: lw          $t9, 0x11C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X11C);
    // 0x80383A58: lh          $t4, 0x118($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X118);
    // 0x80383A5C: jalr        $t9
    // 0x80383A60: addu        $a0, $t4, $v0
    ctx->r4 = ADD32(ctx->r12, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383A60: addu        $a0, $t4, $v0
    ctx->r4 = ADD32(ctx->r12, ctx->r2);
    after_1:
    // 0x80383A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80383A68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80383A6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80383A70: jr          $ra
    // 0x80383A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80383A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbyThrowFProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014A458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A45C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014A460: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014A464: jal         0x800DE6B0
    // 0x8014A468: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8014A468: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014A46C: beq         $v0, $zero, L_8014A498
    if (ctx->r2 == 0) {
        // 0x8014A470: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014A498;
    }
    // 0x8014A470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014A474: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A478: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8014A47C: lwc1        $f4, 0x4C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8014A480: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8014A484: nop

    // 0x8014A488: bc1fl       L_8014A49C
    if (!c1cs) {
        // 0x8014A48C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014A49C;
    }
    goto skip_0;
    // 0x8014A48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014A490: jal         0x8014A5AC
    // 0x8014A494: nop

    ftKirbyThrowFLandingSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014A494: nop

    after_1:
L_8014A498:
    // 0x8014A498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014A49C:
    // 0x8014A49C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014A4A0: jr          $ra
    // 0x8014A4A4: nop

    return;
    // 0x8014A4A4: nop

;}
RECOMP_FUNC void ftNessAppearStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DE60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013DE64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DE68: jal         0x8013DA14
    // 0x8013DE6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonAppearUpdateEffects(rdram, ctx);
        goto after_0;
    // 0x8013DE6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013DE70: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013DE74: addiu       $a1, $a1, -0x2140
    ctx->r5 = ADD32(ctx->r5, -0X2140);
    // 0x8013DE78: jal         0x800D9480
    // 0x8013DE7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013DE7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013DE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DE88: jr          $ra
    // 0x8013DE8C: nop

    return;
    // 0x8013DE8C: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157A94: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157A98: jal         0x800DDE84
    // 0x80157A9C: addiu       $a1, $a1, 0x7B5C
    ctx->r5 = ADD32(ctx->r5, 0X7B5C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80157A9C: addiu       $a1, $a1, 0x7B5C
    ctx->r5 = ADD32(ctx->r5, 0X7B5C);
    after_0:
    // 0x80157AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157AA8: jr          $ra
    // 0x80157AAC: nop

    return;
    // 0x80157AAC: nop

;}
RECOMP_FUNC void mvOpeningRoomWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DE8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132DEC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132DF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132DFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132E00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132E04: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132E08: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132E0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132E10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E14: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132E18: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132E1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132E20: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132E24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132E28: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132E2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E30: lui         $t5, 0x8FFF
    ctx->r13 = S32(0X8FFF << 16);
    // 0x80132E34: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80132E38: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80132E3C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80132E40: lui         $t4, 0xEE00
    ctx->r12 = S32(0XEE00 << 16);
    // 0x80132E44: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80132E48: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80132E4C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E50: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132E54: ori         $t7, $t7, 0x1D00
    ctx->r15 = ctx->r15 | 0X1D00;
    // 0x80132E58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132E5C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132E60: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80132E64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132E68: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132E6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E70: lui         $t4, 0x55
    ctx->r12 = S32(0X55 << 16);
    // 0x80132E74: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x80132E78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132E7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132E80: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x80132E84: ori         $t4, $t4, 0x2058
    ctx->r12 = ctx->r12 | 0X2058;
    // 0x80132E88: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132E8C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80132E90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132E94: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x80132E98: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132E9C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80132EA0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132EA4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132EA8: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x80132EAC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132EB0: jal         0x800CCF74
    // 0x80132EB4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80132EB4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132EB8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132EBC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132EC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132EC4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80132EC8: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x80132ECC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132ED0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132ED4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132ED8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132EDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132EE0: ori         $t4, $t4, 0xA01
    ctx->r12 = ctx->r12 | 0XA01;
    // 0x80132EE4: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80132EE8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80132EEC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80132EF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132EF4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80132EF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132EFC: ori         $t6, $t6, 0x1D00
    ctx->r14 = ctx->r14 | 0X1D00;
    // 0x80132F00: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80132F04: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80132F08: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132F0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132F10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132F14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132F18: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132F1C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132F20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132F24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132F28: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80132F2C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132F30: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132F3C: jr          $ra
    // 0x80132F40: nop

    return;
    // 0x80132F40: nop

;}
RECOMP_FUNC void ftLinkSpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801641D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801641D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801641D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801641DC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801641E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801641E4: jal         0x800DE87C
    // 0x801641E8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_0;
    // 0x801641E8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801641EC: beql        $v0, $zero, L_8016425C
    if (ctx->r2 == 0) {
        // 0x801641F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8016425C;
    }
    goto skip_0;
    // 0x801641F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801641F4: jal         0x80163EFC
    // 0x801641F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftLinkSpecialHiProcDamage(rdram, ctx);
        goto after_1;
    // 0x801641F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801641FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80164200: lhu         $v0, 0xD2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XD2);
    // 0x80164204: andi        $t7, $v0, 0x3000
    ctx->r15 = ctx->r2 & 0X3000;
    // 0x80164208: beq         $t7, $zero, L_80164220
    if (ctx->r15 == 0) {
        // 0x8016420C: andi        $t8, $v0, 0x800
        ctx->r24 = ctx->r2 & 0X800;
            goto L_80164220;
    }
    // 0x8016420C: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x80164210: jal         0x80144C24
    // 0x80164214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x80164214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80164218: b           L_8016425C
    // 0x8016421C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8016425C;
    // 0x8016421C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80164220:
    // 0x80164220: beql        $t8, $zero, L_8016425C
    if (ctx->r24 == 0) {
        // 0x80164224: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8016425C;
    }
    goto skip_1;
    // 0x80164224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80164228: jal         0x800DEE98
    // 0x8016422C: nop

    mpCommonSetFighterGround(rdram, ctx);
        goto after_3;
    // 0x8016422C: nop

    after_3:
    // 0x80164230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80164234: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x80164238: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016423C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164240: jal         0x800E6F24
    // 0x80164244: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x80164244: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80164248: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8016424C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80164250: addiu       $t9, $t9, 0x3EFC
    ctx->r25 = ADD32(ctx->r25, 0X3EFC);
    // 0x80164254: sw          $t9, 0x9EC($t0)
    MEM_W(0X9EC, ctx->r8) = ctx->r25;
    // 0x80164258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8016425C:
    // 0x8016425C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80164260: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80164264: jr          $ra
    // 0x80164268: nop

    return;
    // 0x80164268: nop

;}
RECOMP_FUNC void func_ovl0_800C9A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9A38: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800C9A3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9A40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9A44: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C9A48: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800C9A4C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800C9A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C9A54: lw          $a3, 0x84($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X84);
    // 0x800C9A58: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x800C9A5C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800C9A60: lw          $t8, 0x190($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X190);
    // 0x800C9A64: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x800C9A68: bltz        $t0, L_800C9A84
    if (SIGNED(ctx->r8) < 0) {
        // 0x800C9A6C: nop
    
            goto L_800C9A84;
    }
    // 0x800C9A6C: nop

    // 0x800C9A70: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x800C9A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C9A78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800C9A7C: bne         $v0, $at, L_800C9C0C
    if (ctx->r2 != ctx->r1) {
        // 0x800C9A80: addiu       $a2, $a3, 0x10
        ctx->r6 = ADD32(ctx->r7, 0X10);
            goto L_800C9C0C;
    }
    // 0x800C9A80: addiu       $a2, $a3, 0x10
    ctx->r6 = ADD32(ctx->r7, 0X10);
L_800C9A84:
    // 0x800C9A84: jal         0x800EDBA4
    // 0x800C9A88: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800C9A88: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C9A8C: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x800C9A90: lwc1        $f2, 0x50($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800C9A94: lwc1        $f14, 0x54($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800C9A98: lwc1        $f0, 0x58($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X58);
    // 0x800C9A9C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9AA0: nop

    // 0x800C9AA4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9AA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C9AAC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9AB0: jal         0x80033510
    // 0x800C9AB4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C9AB4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_1:
    // 0x800C9AB8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9ABC: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x800C9AC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9AC4: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9AC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9ACC: addiu       $v0, $a3, 0x50
    ctx->r2 = ADD32(ctx->r7, 0X50);
    // 0x800C9AD0: bc1tl       L_800C9AE8
    if (c1cs) {
        // 0x800C9AD4: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800C9AE8;
    }
    goto skip_0;
    // 0x800C9AD4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800C9AD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C9ADC: nop

    // 0x800C9AE0: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C9AE4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_800C9AE8:
    // 0x800C9AE8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C9AEC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800C9AF0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C9AF4: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C9AF8: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800C9AFC: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C9B00: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9B04: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800C9B08: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800C9B0C: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800C9B10: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800C9B14: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9B18: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C9B1C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9B20: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C9B24: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9B28: jal         0x80033510
    // 0x800C9B2C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C9B2C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800C9B30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9B34: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800C9B38: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9B3C: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9B40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9B44: bc1tl       L_800C9B5C
    if (c1cs) {
        // 0x800C9B48: lwc1        $f4, 0x10($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
            goto L_800C9B5C;
    }
    goto skip_1;
    // 0x800C9B48: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x800C9B4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C9B50: nop

    // 0x800C9B54: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C9B58: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
L_800C9B5C:
    // 0x800C9B5C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C9B60: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800C9B64: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800C9B68: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9B6C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800C9B70: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800C9B74: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9B78: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800C9B7C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800C9B80: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800C9B84: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800C9B88: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9B8C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C9B90: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9B94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C9B98: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9B9C: jal         0x80033510
    // 0x800C9BA0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800C9BA0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_3:
    // 0x800C9BA4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9BA8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800C9BAC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9BB0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9BB8: bc1tl       L_800C9BD0
    if (c1cs) {
        // 0x800C9BBC: lwc1        $f4, 0x20($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
            goto L_800C9BD0;
    }
    goto skip_2;
    // 0x800C9BBC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    skip_2:
    // 0x800C9BC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C9BC4: nop

    // 0x800C9BC8: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C9BCC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
L_800C9BD0:
    // 0x800C9BD0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C9BD4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800C9BD8: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800C9BDC: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C9BE0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800C9BE4: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800C9BE8: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9BEC: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x800C9BF0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800C9BF4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800C9BF8: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800C9BFC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x800C9C00: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800C9C04: b           L_800C9F1C
    // 0x800C9C08: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
        goto L_800C9F1C;
    // 0x800C9C08: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
L_800C9C0C:
    // 0x800C9C0C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800C9C10: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x800C9C14: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800C9C18: jal         0x800ECDE4
    // 0x800C9C1C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    gmCollisionTransformMatrixAll(rdram, ctx);
        goto after_4;
    // 0x800C9C1C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800C9C20: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x800C9C24: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800C9C28: lwc1        $f14, 0x14($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800C9C2C: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x800C9C30: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9C34: nop

    // 0x800C9C38: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9C3C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C9C40: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9C44: jal         0x80033510
    // 0x800C9C48: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x800C9C48: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_5:
    // 0x800C9C4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C9C50: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C9C54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9C58: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800C9C5C: nop

    // 0x800C9C60: bc1t        L_800C9C74
    if (c1cs) {
        // 0x800C9C64: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C9C74;
    }
    // 0x800C9C64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9C68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C9C6C: nop

    // 0x800C9C70: div.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
L_800C9C74:
    // 0x800C9C74: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C9C78: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9C7C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x800C9C80: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C9C84: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C9C88: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800C9C8C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800C9C90: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C9C94: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800C9C98: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800C9C9C: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800C9CA0: lwc1        $f14, 0x18($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800C9CA4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9CA8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800C9CAC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9CB0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C9CB4: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9CB8: jal         0x80033510
    // 0x800C9CBC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800C9CBC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_6:
    // 0x800C9CC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C9CC4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C9CC8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9CCC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800C9CD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9CD4: bc1tl       L_800C9CEC
    if (c1cs) {
        // 0x800C9CD8: lwc1        $f8, 0x10($a2)
        ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
            goto L_800C9CEC;
    }
    goto skip_3;
    // 0x800C9CD8: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    skip_3:
    // 0x800C9CDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C9CE0: nop

    // 0x800C9CE4: div.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C9CE8: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
L_800C9CEC:
    // 0x800C9CEC: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9CF0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800C9CF4: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800C9CF8: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800C9CFC: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x800C9D00: lwc1        $f6, 0x18($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800C9D04: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C9D08: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800C9D0C: lwc1        $f0, 0x20($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800C9D10: lwc1        $f2, 0x24($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800C9D14: lwc1        $f14, 0x28($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800C9D18: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9D1C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800C9D20: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9D24: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800C9D28: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9D2C: jal         0x80033510
    // 0x800C9D30: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x800C9D30: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_7:
    // 0x800C9D34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C9D38: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800C9D3C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9D40: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800C9D44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9D48: bc1tl       L_800C9D60
    if (c1cs) {
        // 0x800C9D4C: lwc1        $f8, 0x20($a2)
        ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
            goto L_800C9D60;
    }
    goto skip_4;
    // 0x800C9D4C: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    skip_4:
    // 0x800C9D50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C9D54: nop

    // 0x800C9D58: div.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C9D5C: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
L_800C9D60:
    // 0x800C9D60: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x800C9D64: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9D68: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800C9D6C: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800C9D70: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800C9D74: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x800C9D78: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800C9D7C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800C9D80: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x800C9D84: lwc1        $f8, 0x30($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800C9D88: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800C9D8C: lwc1        $f16, 0x34($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800C9D90: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x800C9D94: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800C9D98: jal         0x800EDBA4
    // 0x800C9D9C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_8;
    // 0x800C9D9C: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x800C9DA0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800C9DA4: lw          $a1, 0x84($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X84);
    // 0x800C9DA8: lwc1        $f0, 0x50($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X50);
    // 0x800C9DAC: lwc1        $f2, 0x54($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X54);
    // 0x800C9DB0: lwc1        $f14, 0x58($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X58);
    // 0x800C9DB4: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9DB8: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x800C9DBC: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800C9DC0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9DC4: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C9DC8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9DCC: jal         0x80033510
    // 0x800C9DD0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x800C9DD0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_9:
    // 0x800C9DD4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9DD8: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800C9DDC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9DE0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9DE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9DE8: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C9DEC: bc1t        L_800C9E00
    if (c1cs) {
        // 0x800C9DF0: nop
    
            goto L_800C9E00;
    }
    // 0x800C9DF0: nop

    // 0x800C9DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C9DF8: nop

    // 0x800C9DFC: div.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_800C9E00:
    // 0x800C9E00: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800C9E04: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C9E08: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C9E0C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9E10: nop

    // 0x800C9E14: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9E18: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800C9E1C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800C9E20: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800C9E24: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800C9E28: lwc1        $f14, 0x14($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800C9E2C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800C9E30: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9E34: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800C9E38: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9E3C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C9E40: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9E44: jal         0x80033510
    // 0x800C9E48: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x800C9E48: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_10:
    // 0x800C9E4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9E50: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800C9E54: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9E58: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9E5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9E60: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C9E64: bc1t        L_800C9E78
    if (c1cs) {
        // 0x800C9E68: nop
    
            goto L_800C9E78;
    }
    // 0x800C9E68: nop

    // 0x800C9E6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C9E70: nop

    // 0x800C9E74: div.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_800C9E78:
    // 0x800C9E78: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800C9E7C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C9E80: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C9E84: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800C9E88: nop

    // 0x800C9E8C: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9E90: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800C9E94: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x800C9E98: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x800C9E9C: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800C9EA0: lwc1        $f14, 0x24($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800C9EA4: lwc1        $f0, 0x28($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800C9EA8: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C9EAC: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800C9EB0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C9EB4: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C9EB8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9EBC: jal         0x80033510
    // 0x800C9EC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800C9EC0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_11:
    // 0x800C9EC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C9EC8: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800C9ECC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C9ED0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800C9ED4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C9ED8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C9EDC: bc1t        L_800C9EF0
    if (c1cs) {
        // 0x800C9EE0: nop
    
            goto L_800C9EF0;
    }
    // 0x800C9EE0: nop

    // 0x800C9EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C9EE8: nop

    // 0x800C9EEC: div.s       $f20, $f4, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
L_800C9EF0:
    // 0x800C9EF0: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800C9EF4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C9EF8: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C9EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9F00: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C9F04: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800C9F08: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800C9F0C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800C9F10: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800C9F14: jal         0x800ED490
    // 0x800C9F18: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_ovl2_800ED490(rdram, ctx);
        goto after_12;
    // 0x800C9F18: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_12:
L_800C9F1C:
    // 0x800C9F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9F20: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C9F24: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9F28: jr          $ra
    // 0x800C9F2C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800C9F2C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNReleaseProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F2E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015F2F4: jal         0x8015F248
    // 0x8015F2F8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftKirbyCopyYoshiSpecialAirNCatchUpdateCaptureVars(rdram, ctx);
        goto after_0;
    // 0x8015F2F8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F2FC: jal         0x800D94E8
    // 0x8015F300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x8015F300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015F304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F30C: jr          $ra
    // 0x8015F310: nop

    return;
    // 0x8015F310: nop

;}
RECOMP_FUNC void mnOptionWriteBackup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132E14: lw          $t6, 0x37C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X37C0);
    // 0x80132E18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132E1C: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x80132E20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132E24: sb          $t6, 0x450($v0)
    MEM_B(0X450, ctx->r2) = ctx->r14;
    // 0x80132E28: lw          $t7, 0x37BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X37BC);
    // 0x80132E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E34: jal         0x800D45F4
    // 0x80132E38: sb          $t7, 0x451($v0)
    MEM_B(0X451, ctx->r2) = ctx->r15;
    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x80132E38: sb          $t7, 0x451($v0)
    MEM_B(0X451, ctx->r2) = ctx->r15;
    after_0:
    // 0x80132E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132E44: jr          $ra
    // 0x80132E48: nop

    return;
    // 0x80132E48: nop

;}
RECOMP_FUNC void func_ovl46_80131CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CA4: jr          $ra
    // 0x80131CA8: nop

    return;
    // 0x80131CA8: nop

;}
RECOMP_FUNC void guNormalize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035388: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003538C: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80035390: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80035394: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035398: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003539C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800353A0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800353A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800353A8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800353AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800353B0: jal         0x80033510
    // 0x800353B4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800353B4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800353B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800353BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800353C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800353C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800353C8: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800353CC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800353D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800353D4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800353D8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800353DC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800353E0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800353E4: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800353E8: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800353EC: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800353F0: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800353F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800353F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800353FC: jr          $ra
    // 0x80035400: nop

    return;
    // 0x80035400: nop

;}
RECOMP_FUNC void mnBackupClearUpdateOptionMainMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801325D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801325DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325E0: addiu       $t7, $t7, 0x2FA0
    ctx->r15 = ADD32(ctx->r15, 0X2FA0);
    // 0x801325E4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801325E8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801325EC: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x801325F0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801325F4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801325F8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801325FC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132600: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    // 0x80132604: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132608: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8013260C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80132610: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80132614: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80132618: jal         0x8039076C
    // 0x8013261C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8013261C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    after_0:
    // 0x80132620: beq         $v0, $zero, L_8013268C
    if (ctx->r2 == 0) {
        // 0x80132624: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_8013268C;
    }
    // 0x80132624: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132628: lw          $t0, 0x30C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30C0);
    // 0x8013262C: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x80132630: beq         $at, $zero, L_8013268C
    if (ctx->r1 == 0) {
        // 0x80132634: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8013268C;
    }
    // 0x80132634: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132638: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013263C: addu        $at, $at, $t0
    gpr jr_addend_80132644 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80132640: lw          $t0, 0x3088($at)
    ctx->r8 = ADD32(ctx->r1, 0X3088);
    // 0x80132644: jr          $t0
    // 0x80132648: nop

    switch (jr_addend_80132644 >> 2) {
        case 0: goto L_8013264C; break;
        case 1: goto L_8013264C; break;
        case 2: goto L_8013264C; break;
        case 3: goto L_8013264C; break;
        case 4: goto L_8013264C; break;
        case 5: goto L_8013264C; break;
        default: switch_error(__func__, 0x80132644, 0x80133088);
    }
    // 0x80132648: nop

L_8013264C:
    // 0x8013264C: jal         0x800269C0
    // 0x80132650: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80132650: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_1:
    // 0x80132654: jal         0x80131F38
    // 0x80132658: nop

    mnBackupClearEjectOptionGObjs(rdram, ctx);
        goto after_2;
    // 0x80132658: nop

    after_2:
    // 0x8013265C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132660: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132668: addiu       $v1, $v1, 0x30CC
    ctx->r3 = ADD32(ctx->r3, 0X30CC);
    // 0x8013266C: sw          $a1, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = ctx->r5;
    // 0x80132670: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80132674: jal         0x80132148
    // 0x80132678: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnBackupClearMakeOptionConfirm(rdram, ctx);
        goto after_3;
    // 0x80132678: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8013267C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80132680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132684: b           L_80132918
    // 0x80132688: sw          $t1, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r9;
        goto L_80132918;
    // 0x80132688: sw          $t1, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r9;
L_8013268C:
    // 0x8013268C: jal         0x8039076C
    // 0x80132690: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_4;
    // 0x80132690: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_4:
    // 0x80132694: beq         $v0, $zero, L_801326C8
    if (ctx->r2 == 0) {
        // 0x80132698: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_801326C8;
    }
    // 0x80132698: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013269C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801326A0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801326A4: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x801326A8: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x801326AC: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x801326B0: jal         0x801325CC
    // 0x801326B4: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    func_ovl53_801325CC(rdram, ctx);
        goto after_5;
    // 0x801326B4: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    after_5:
    // 0x801326B8: jal         0x80005C74
    // 0x801326BC: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x801326BC: nop

    after_6:
    // 0x801326C0: b           L_8013291C
    // 0x801326C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013291C;
    // 0x801326C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801326C8:
    // 0x801326C8: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x801326CC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801326D0: bne         $v0, $zero, L_801326F4
    if (ctx->r2 != 0) {
        // 0x801326D4: nop
    
            goto L_801326F4;
    }
    // 0x801326D4: nop

    // 0x801326D8: jal         0x80390804
    // 0x801326DC: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x801326DC: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_7:
    // 0x801326E0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801326E4: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x801326E8: bne         $v0, $zero, L_80132714
    if (ctx->r2 != 0) {
        // 0x801326EC: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132714;
    }
    // 0x801326EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801326F0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_801326F4:
    // 0x801326F4: bne         $v0, $zero, L_801327FC
    if (ctx->r2 != 0) {
        // 0x801326F8: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801327FC;
    }
    // 0x801326F8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801326FC: jal         0x80390950
    // 0x80132700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_8;
    // 0x80132700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80132704: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132708: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x8013270C: beq         $v0, $zero, L_801327FC
    if (ctx->r2 == 0) {
        // 0x80132710: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_801327FC;
    }
    // 0x80132710: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80132714:
    // 0x80132714: jal         0x800269C0
    // 0x80132718: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80132718: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_9:
    // 0x8013271C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80132720: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132724: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x80132728: beq         $t4, $zero, L_8013273C
    if (ctx->r12 == 0) {
        // 0x8013272C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_8013273C;
    }
    // 0x8013272C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132730: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132734: b           L_8013275C
    // 0x80132738: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
        goto L_8013275C;
    // 0x80132738: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_8013273C:
    // 0x8013273C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80132740: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80132744: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132748: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8013274C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80132750: mflo        $t9
    ctx->r25 = lo;
    // 0x80132754: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80132758: nop

L_8013275C:
    // 0x8013275C: lw          $t0, 0x30C0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30C0);
    // 0x80132760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132764: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80132768: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x8013276C: lw          $t2, 0x24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X24);
    // 0x80132770: jal         0x80131CE4
    // 0x80132774: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_10;
    // 0x80132774: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_10:
    // 0x80132778: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013277C: addiu       $v1, $v1, 0x30C0
    ctx->r3 = ADD32(ctx->r3, 0X30C0);
    // 0x80132780: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132784: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132788: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x8013278C: bne         $v0, $zero, L_801327A0
    if (ctx->r2 != 0) {
        // 0x80132790: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_801327A0;
    }
    // 0x80132790: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80132794: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80132798: b           L_801327A4
    // 0x8013279C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_801327A4;
    // 0x8013279C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_801327A0:
    // 0x801327A0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_801327A4:
    // 0x801327A4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801327A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327AC: bne         $t4, $zero, L_801327C0
    if (ctx->r12 != 0) {
        // 0x801327B0: nop
    
            goto L_801327C0;
    }
    // 0x801327B0: nop

    // 0x801327B4: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x801327B8: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x801327BC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_801327C0:
    // 0x801327C0: jal         0x80009A84
    // 0x801327C4: lw          $a0, 0x30C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C4);
    gcEjectGObj(rdram, ctx);
        goto after_11;
    // 0x801327C4: lw          $a0, 0x30C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C4);
    after_11:
    // 0x801327C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327CC: jal         0x80131B24
    // 0x801327D0: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    mnBackupClearMakeUnused(rdram, ctx);
        goto after_12;
    // 0x801327D0: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    after_12:
    // 0x801327D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801327D8: lw          $t6, 0x30C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30C0);
    // 0x801327DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801327E0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801327E4: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x801327E8: lw          $t9, 0x24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X24);
    // 0x801327EC: jal         0x80131CE4
    // 0x801327F0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_13;
    // 0x801327F0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_13:
    // 0x801327F4: b           L_8013291C
    // 0x801327F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013291C;
    // 0x801327F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801327FC:
    // 0x801327FC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132800: bne         $v0, $zero, L_80132824
    if (ctx->r2 != 0) {
        // 0x80132804: nop
    
            goto L_80132824;
    }
    // 0x80132804: nop

    // 0x80132808: jal         0x80390804
    // 0x8013280C: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_14;
    // 0x8013280C: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_14:
    // 0x80132810: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132814: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x80132818: bne         $v0, $zero, L_8013283C
    if (ctx->r2 != 0) {
        // 0x8013281C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_8013283C;
    }
    // 0x8013281C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132820: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80132824:
    // 0x80132824: bne         $v0, $zero, L_80132918
    if (ctx->r2 != 0) {
        // 0x80132828: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132918;
    }
    // 0x80132828: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x8013282C: jal         0x80390950
    // 0x80132830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_15;
    // 0x80132830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80132834: beq         $v0, $zero, L_80132918
    if (ctx->r2 == 0) {
        // 0x80132838: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80132918;
    }
    // 0x80132838: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8013283C:
    // 0x8013283C: jal         0x800269C0
    // 0x80132840: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_16;
    // 0x80132840: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_16:
    // 0x80132844: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80132848: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013284C: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x80132850: beq         $t0, $zero, L_80132864
    if (ctx->r8 == 0) {
        // 0x80132854: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80132864;
    }
    // 0x80132854: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132858: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8013285C: b           L_80132880
    // 0x80132860: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80132880;
    // 0x80132860: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_80132864:
    // 0x80132864: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80132868: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013286C: addiu       $t3, $t2, 0xA0
    ctx->r11 = ADD32(ctx->r10, 0XA0);
    // 0x80132870: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80132874: mflo        $t4
    ctx->r12 = lo;
    // 0x80132878: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8013287C: nop

L_80132880:
    // 0x80132880: lw          $t5, 0x30C0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30C0);
    // 0x80132884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132888: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8013288C: addu        $t6, $sp, $t7
    ctx->r14 = ADD32(ctx->r29, ctx->r15);
    // 0x80132890: lw          $t6, 0x24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24);
    // 0x80132894: jal         0x80131CE4
    // 0x80132898: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_17;
    // 0x80132898: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_17:
    // 0x8013289C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328A0: addiu       $v1, $v1, 0x30C0
    ctx->r3 = ADD32(ctx->r3, 0X30C0);
    // 0x801328A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328A8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801328AC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801328B0: bne         $a0, $v0, L_801328C0
    if (ctx->r4 != ctx->r2) {
        // 0x801328B4: addiu       $a2, $a2, 0x30DC
        ctx->r6 = ADD32(ctx->r6, 0X30DC);
            goto L_801328C0;
    }
    // 0x801328B4: addiu       $a2, $a2, 0x30DC
    ctx->r6 = ADD32(ctx->r6, 0X30DC);
    // 0x801328B8: b           L_801328C8
    // 0x801328BC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801328C8;
    // 0x801328BC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801328C0:
    // 0x801328C0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801328C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801328C8:
    // 0x801328C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801328CC: bne         $a0, $t9, L_801328E0
    if (ctx->r4 != ctx->r25) {
        // 0x801328D0: nop
    
            goto L_801328E0;
    }
    // 0x801328D0: nop

    // 0x801328D4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x801328D8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801328DC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
L_801328E0:
    // 0x801328E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328E4: jal         0x80009A84
    // 0x801328E8: lw          $a0, 0x30C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C4);
    gcEjectGObj(rdram, ctx);
        goto after_18;
    // 0x801328E8: lw          $a0, 0x30C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C4);
    after_18:
    // 0x801328EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328F0: jal         0x80131B24
    // 0x801328F4: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    mnBackupClearMakeUnused(rdram, ctx);
        goto after_19;
    // 0x801328F4: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    after_19:
    // 0x801328F8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801328FC: lw          $t2, 0x30C0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30C0);
    // 0x80132900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132904: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80132908: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8013290C: lw          $t4, 0x24($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X24);
    // 0x80132910: jal         0x80131CE4
    // 0x80132914: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    mnBackupClearUpdateOptionTabColors(rdram, ctx);
        goto after_20;
    // 0x80132914: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_20:
L_80132918:
    // 0x80132918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013291C:
    // 0x8013291C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132920: jr          $ra
    // 0x80132924: nop

    return;
    // 0x80132924: nop

;}
RECOMP_FUNC void scStaffrollMakeJobGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80133E6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80133E70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133E74: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80133E78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133E7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80133E88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133E8C: jal         0x80009968
    // 0x80133E90: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133E90: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80133E94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133E98: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133E9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133EA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133EA4: addiu       $a1, $a1, 0x3854
    ctx->r5 = ADD32(ctx->r5, 0X3854);
    // 0x80133EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80133EB0: jal         0x80009DF4
    // 0x80133EB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133EB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EBC: jal         0x800092D0
    // 0x80133EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80133EC4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80133EC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133ECC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80133ED0: jal         0x80008CC0
    // 0x80133ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80133ED4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80133ED8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80133EDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133EE0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80133EE4: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80133EE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80133EEC: beql        $a2, $at, L_80133F14
    if (ctx->r6 == ctx->r1) {
        // 0x80133EF0: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_80133F14;
    }
    goto skip_0;
    // 0x80133EF0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80133EF4: jal         0x80133A78
    // 0x80133EF8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    scStaffrollMakeJobDObjs(rdram, ctx);
        goto after_4;
    // 0x80133EF8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x80133EFC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80133F00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133F04: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80133F08: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80133F0C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80133F10: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_80133F14:
    // 0x80133F14: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80133F18: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80133F1C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80133F20: jal         0x80133A78
    // 0x80133F24: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    scStaffrollMakeJobDObjs(rdram, ctx);
        goto after_5;
    // 0x80133F24: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    after_5:
    // 0x80133F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F2C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80133F30: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80133F34: jal         0x80133A0C
    // 0x80133F38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    scStaffrollJobAndNameInitStruct(rdram, ctx);
        goto after_6;
    // 0x80133F38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80133F3C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F40: addiu       $a1, $a1, 0x369C
    ctx->r5 = ADD32(ctx->r5, 0X369C);
    // 0x80133F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133F4C: jal         0x80008188
    // 0x80133F50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80133F50: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80133F54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133F58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80133F5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133F60: jr          $ra
    // 0x80133F64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80133F64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void wpManagerGetNextStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165558: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8016555C: addiu       $a0, $a0, -0x3010
    ctx->r4 = ADD32(ctx->r4, -0X3010);
    // 0x80165560: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80165564: bnel        $v1, $zero, L_80165578
    if (ctx->r3 != 0) {
        // 0x80165568: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80165578;
    }
    goto skip_0;
    // 0x80165568: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8016556C: jr          $ra
    // 0x80165570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80165570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80165574: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80165578:
    // 0x80165578: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8016557C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80165580: jr          $ra
    // 0x80165584: nop

    return;
    // 0x80165584: nop

;}
RECOMP_FUNC void ftParamGetBestHitStatusPart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8A48: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E8A50: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x800E8A54: lw          $a1, 0x5BC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X5BC);
    // 0x800E8A58: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x800E8A5C: lw          $v1, 0x5B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5B8);
    // 0x800E8A60: beq         $a1, $at, L_800E8A94
    if (ctx->r5 == ctx->r1) {
        // 0x800E8A64: addiu       $a3, $v0, 0x2C
        ctx->r7 = ADD32(ctx->r2, 0X2C);
            goto L_800E8A94;
    }
    // 0x800E8A64: addiu       $a3, $v0, 0x2C
    ctx->r7 = ADD32(ctx->r2, 0X2C);
L_800E8A68:
    // 0x800E8A68: lw          $t6, 0x5BC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X5BC);
    // 0x800E8A6C: addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
    // 0x800E8A70: beql        $t6, $zero, L_800E8A98
    if (ctx->r14 == 0) {
        // 0x800E8A74: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800E8A98;
    }
    goto skip_0;
    // 0x800E8A74: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    skip_0:
    // 0x800E8A78: lw          $v0, 0x5BC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X5BC);
    // 0x800E8A7C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800E8A80: beq         $at, $zero, L_800E8A8C
    if (ctx->r1 == 0) {
        // 0x800E8A84: nop
    
            goto L_800E8A8C;
    }
    // 0x800E8A84: nop

    // 0x800E8A88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800E8A8C:
    // 0x800E8A8C: bne         $a2, $a0, L_800E8A68
    if (ctx->r6 != ctx->r4) {
        // 0x800E8A90: addiu       $a3, $a3, 0x2C
        ctx->r7 = ADD32(ctx->r7, 0X2C);
            goto L_800E8A68;
    }
    // 0x800E8A90: addiu       $a3, $a3, 0x2C
    ctx->r7 = ADD32(ctx->r7, 0X2C);
L_800E8A94:
    // 0x800E8A94: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
L_800E8A98:
    // 0x800E8A98: beq         $at, $zero, L_800E8AA4
    if (ctx->r1 == 0) {
        // 0x800E8A9C: nop
    
            goto L_800E8AA4;
    }
    // 0x800E8A9C: nop

    // 0x800E8AA0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800E8AA4:
    // 0x800E8AA4: jr          $ra
    // 0x800E8AA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E8AA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void syVectorReflectFacing3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019888: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001988C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019890: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019894: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019898: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001989C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800198A0: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800198A4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800198A8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800198AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800198B0: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800198B4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800198B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800198BC: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800198C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800198C4: nop

    // 0x800198C8: bc1f        L_8001990C
    if (!c1cs) {
        // 0x800198CC: nop
    
            goto L_8001990C;
    }
    // 0x800198CC: nop

    // 0x800198D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800198D4: nop

    // 0x800198D8: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800198DC: nop

    // 0x800198E0: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800198E4: add.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x800198E8: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800198EC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800198F0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800198F4: add.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800198F8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800198FC: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019900: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80019904: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80019908: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_8001990C:
    // 0x8001990C: jr          $ra
    // 0x80019910: nop

    return;
    // 0x80019910: nop

;}
RECOMP_FUNC void lbCommonDrawSObjNoAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCF74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CCF78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCF7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CCF80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CCF84: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x800CCF88: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800CCF8C: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800CCF90: beql        $s0, $zero, L_800CCFCC
    if (ctx->r16 == 0) {
        // 0x800CCF94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CCFCC;
    }
    goto skip_0;
    // 0x800CCF94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800CCF98: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
L_800CCF9C:
    // 0x800CCF9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CCFA0: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800CCFA4: bnel        $t7, $zero, L_800CCFC0
    if (ctx->r15 != 0) {
        // 0x800CCFA8: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_800CCFC0;
    }
    goto skip_1;
    // 0x800CCFA8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x800CCFAC: jal         0x800CC818
    // 0x800CCFB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_0;
    // 0x800CCFB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800CCFB4: jal         0x800CCEAC
    // 0x800CCFB8: nop

    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x800CCFB8: nop

    after_1:
    // 0x800CCFBC: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
L_800CCFC0:
    // 0x800CCFC0: bnel        $s0, $zero, L_800CCF9C
    if (ctx->r16 != 0) {
        // 0x800CCFC4: lhu         $t6, 0x24($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X24);
            goto L_800CCF9C;
    }
    goto skip_2;
    // 0x800CCFC4: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
    skip_2:
    // 0x800CCFC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CCFCC:
    // 0x800CCFCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CCFD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CCFD4: jr          $ra
    // 0x800CCFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CCFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002668C_2728C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002668C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80026690: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x80026694: sb          $t6, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r14;
    // 0x80026698: jr          $ra
    // 0x8002669C: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    return;
    // 0x8002669C: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
;}
RECOMP_FUNC void lbBackupClearBonusStageTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4B60: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D4B64: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D4B68: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D4B6C: addiu       $v0, $v0, 0x3B14
    ctx->r2 = ADD32(ctx->r2, 0X3B14);
    // 0x800D4B70: addiu       $a0, $a0, 0x3994
    ctx->r4 = ADD32(ctx->r4, 0X3994);
    // 0x800D4B74: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
L_800D4B78:
    // 0x800D4B78: lw          $t0, 0x48C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X48C);
    // 0x800D4B7C: lbu         $t1, 0x490($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X490);
    // 0x800D4B80: lw          $t6, 0x46C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X46C);
    // 0x800D4B84: lbu         $t7, 0x470($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X470);
    // 0x800D4B88: lw          $t8, 0x474($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X474);
    // 0x800D4B8C: lbu         $t9, 0x478($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X478);
    // 0x800D4B90: sw          $t0, 0x48C($v1)
    MEM_W(0X48C, ctx->r3) = ctx->r8;
    // 0x800D4B94: sb          $t1, 0x490($v1)
    MEM_B(0X490, ctx->r3) = ctx->r9;
    // 0x800D4B98: sw          $t6, 0x46C($v1)
    MEM_W(0X46C, ctx->r3) = ctx->r14;
    // 0x800D4B9C: sb          $t7, 0x470($v1)
    MEM_B(0X470, ctx->r3) = ctx->r15;
    // 0x800D4BA0: sw          $t8, 0x474($v1)
    MEM_W(0X474, ctx->r3) = ctx->r24;
    // 0x800D4BA4: sb          $t9, 0x478($v1)
    MEM_B(0X478, ctx->r3) = ctx->r25;
    // 0x800D4BA8: lbu         $t9, 0x4D0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4D0);
    // 0x800D4BAC: lw          $t8, 0x4CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4CC);
    // 0x800D4BB0: lbu         $t7, 0x4B8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4B8);
    // 0x800D4BB4: lw          $t6, 0x4B4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4B4);
    // 0x800D4BB8: lbu         $t1, 0x4D8($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X4D8);
    // 0x800D4BBC: lw          $t0, 0x4D4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4D4);
    // 0x800D4BC0: lw          $t2, 0x494($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X494);
    // 0x800D4BC4: lbu         $t3, 0x498($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X498);
    // 0x800D4BC8: lw          $t4, 0x4AC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4AC);
    // 0x800D4BCC: lbu         $t5, 0x4B0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X4B0);
    // 0x800D4BD0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800D4BD4: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800D4BD8: sb          $t9, 0x450($v1)
    MEM_B(0X450, ctx->r3) = ctx->r25;
    // 0x800D4BDC: sw          $t8, 0x44C($v1)
    MEM_W(0X44C, ctx->r3) = ctx->r24;
    // 0x800D4BE0: sb          $t7, 0x438($v1)
    MEM_B(0X438, ctx->r3) = ctx->r15;
    // 0x800D4BE4: sw          $t6, 0x434($v1)
    MEM_W(0X434, ctx->r3) = ctx->r14;
    // 0x800D4BE8: sb          $t1, 0x458($v1)
    MEM_B(0X458, ctx->r3) = ctx->r9;
    // 0x800D4BEC: sw          $t0, 0x454($v1)
    MEM_W(0X454, ctx->r3) = ctx->r8;
    // 0x800D4BF0: sw          $t2, 0x414($v1)
    MEM_W(0X414, ctx->r3) = ctx->r10;
    // 0x800D4BF4: sb          $t3, 0x418($v1)
    MEM_B(0X418, ctx->r3) = ctx->r11;
    // 0x800D4BF8: sw          $t4, 0x42C($v1)
    MEM_W(0X42C, ctx->r3) = ctx->r12;
    // 0x800D4BFC: bne         $a0, $v0, L_800D4B78
    if (ctx->r4 != ctx->r2) {
        // 0x800D4C00: sb          $t5, 0x430($v1)
        MEM_B(0X430, ctx->r3) = ctx->r13;
            goto L_800D4B78;
    }
    // 0x800D4C00: sb          $t5, 0x430($v1)
    MEM_B(0X430, ctx->r3) = ctx->r13;
    // 0x800D4C04: jr          $ra
    // 0x800D4C08: nop

    return;
    // 0x800D4C08: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNCopyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801623F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801623F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801623FC: jal         0x80161F0C
    // 0x80162400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNCopyInitCopyVars(rdram, ctx);
        goto after_0;
    // 0x80162400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162404: jal         0x801622DC
    // 0x80162408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialNCopyUpdateCheckCopyStar(rdram, ctx);
        goto after_1;
    // 0x80162408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016240C: jal         0x800D94E8
    // 0x80162410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_2;
    // 0x80162410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80162414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016241C: jr          $ra
    // 0x80162420: nop

    return;
    // 0x80162420: nop

;}
RECOMP_FUNC void mnPlayersVSShutter2PProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801331CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801331D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801331D4: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x801331D8: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    // 0x801331DC: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x801331E0: jal         0x800CD1F0
    // 0x801331E4: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_0;
    // 0x801331E4: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    after_0:
    // 0x801331E8: jal         0x800CCF00
    // 0x801331EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x801331EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801331F0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801331F4: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x801331F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801331FC: jal         0x800CD1F0
    // 0x80133200: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_2;
    // 0x80133200: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_2:
    // 0x80133204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013320C: jr          $ra
    // 0x80133210: nop

    return;
    // 0x80133210: nop

;}

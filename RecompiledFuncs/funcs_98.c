#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayersVSHideFighterName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801368C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801368C8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801368CC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801368D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801368D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801368D8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801368DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801368E0: lw          $t7, -0x4568($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4568);
    // 0x801368E4: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x801368E8: beq         $v0, $zero, L_80136908
    if (ctx->r2 == 0) {
        // 0x801368EC: nop
    
            goto L_80136908;
    }
    // 0x801368EC: nop

    // 0x801368F0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801368F4: beq         $v1, $zero, L_80136908
    if (ctx->r3 == 0) {
        // 0x801368F8: nop
    
            goto L_80136908;
    }
    // 0x801368F8: nop

    // 0x801368FC: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80136900: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80136904: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
L_80136908:
    // 0x80136908: jr          $ra
    // 0x8013690C: nop

    return;
    // 0x8013690C: nop

;}
RECOMP_FUNC void itCapsuleWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017406C: jal         0x80172E74
    // 0x80174070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80174070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174074: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174078: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x8017407C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174080: jal         0x80172EC8
    // 0x80174084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80174088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017408C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174090: jr          $ra
    // 0x80174094: nop

    return;
    // 0x80174094: nop

;}
RECOMP_FUNC void itProcessSearchHitWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80170C84: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80170C88: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80170C8C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80170C90: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80170C94: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80170C98: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80170C9C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80170CA0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80170CA4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80170CA8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80170CAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80170CB0: lw          $s4, 0x84($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X84);
    // 0x80170CB4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80170CB8: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80170CBC: lbu         $t6, 0x244($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X244);
    // 0x80170CC0: addiu       $s5, $s4, 0x10C
    ctx->r21 = ADD32(ctx->r20, 0X10C);
    // 0x80170CC4: or          $fp, $s5, $zero
    ctx->r30 = ctx->r21 | 0;
    // 0x80170CC8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80170CCC: beql        $t7, $zero, L_80171054
    if (ctx->r15 == 0) {
        // 0x80170CD0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80171054;
    }
    goto skip_0;
    // 0x80170CD0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80170CD4: lw          $s7, 0x6704($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X6704);
    // 0x80170CD8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80170CDC: beql        $s7, $zero, L_80171054
    if (ctx->r23 == 0) {
        // 0x80170CE0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80171054;
    }
    goto skip_1;
    // 0x80170CE0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80170CE4: lw          $s3, 0x84($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X84);
L_80170CE8:
    // 0x80170CE8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80170CEC: addiu       $s2, $s3, 0x100
    ctx->r18 = ADD32(ctx->r19, 0X100);
    // 0x80170CF0: sw          $s2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r18;
    // 0x80170CF4: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x80170CF8: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80170CFC: bne         $t8, $t9, L_80170D10
    if (ctx->r24 != ctx->r25) {
        // 0x80170D00: nop
    
            goto L_80170D10;
    }
    // 0x80170D00: nop

    // 0x80170D04: lb          $t1, 0x2CF($s4)
    ctx->r9 = MEM_B(ctx->r20, 0X2CF);
    // 0x80170D08: bgezl       $t1, L_80171048
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80170D0C: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80171048;
    }
    goto skip_2;
    // 0x80170D0C: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_2:
L_80170D10:
    // 0x80170D10: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x80170D14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170D18: lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2);
    // 0x80170D1C: bnel        $t2, $at, L_80170D50
    if (ctx->r10 != ctx->r1) {
        // 0x80170D20: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80170D50;
    }
    goto skip_3;
    // 0x80170D20: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x80170D24: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x80170D28: bnel        $t3, $zero, L_80170D50
    if (ctx->r11 != 0) {
        // 0x80170D2C: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80170D50;
    }
    goto skip_4;
    // 0x80170D2C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x80170D30: lbu         $t4, 0x10($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X10);
    // 0x80170D34: lbu         $t5, 0x14($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X14);
    // 0x80170D38: bnel        $t4, $t5, L_80170D50
    if (ctx->r12 != ctx->r13) {
        // 0x80170D3C: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80170D50;
    }
    goto skip_5;
    // 0x80170D3C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x80170D40: lb          $t7, 0x2CF($s4)
    ctx->r15 = MEM_B(ctx->r20, 0X2CF);
    // 0x80170D44: bgezl       $t7, L_80171048
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80170D48: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80171048;
    }
    goto skip_6;
    // 0x80170D48: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_6:
    // 0x80170D4C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80170D50:
    // 0x80170D50: beql        $t8, $zero, L_80171048
    if (ctx->r24 == 0) {
        // 0x80170D54: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80171048;
    }
    goto skip_7;
    // 0x80170D54: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_7:
    // 0x80170D58: lbu         $t9, 0x44($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X44);
    // 0x80170D5C: lbu         $t1, 0x7C($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X7C);
    // 0x80170D60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80170D64: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80170D68: beq         $t0, $zero, L_80171044
    if (ctx->r8 == 0) {
        // 0x80170D6C: andi        $t8, $t1, 0xFFBF
        ctx->r24 = ctx->r9 & 0XFFBF;
            goto L_80171044;
    }
    // 0x80170D6C: andi        $t8, $t1, 0xFFBF
    ctx->r24 = ctx->r9 & 0XFFBF;
    // 0x80170D70: sb          $t8, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r24;
    // 0x80170D74: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80170D78: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80170D7C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80170D80: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80170D84: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80170D88: sll         $t7, $t5, 7
    ctx->r15 = S32(ctx->r13 << 7);
    // 0x80170D8C: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x80170D90: sb          $t3, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r11;
    // 0x80170D94: ori         $t4, $t3, 0xE
    ctx->r12 = ctx->r11 | 0XE;
    // 0x80170D98: sb          $t4, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r12;
L_80170D9C:
    // 0x80170D9C: lw          $t5, 0x114($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X114);
    // 0x80170DA0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80170DA4: bne         $s6, $t5, L_80170DBC
    if (ctx->r22 != ctx->r13) {
        // 0x80170DA8: nop
    
            goto L_80170DBC;
    }
    // 0x80170DA8: nop

    // 0x80170DAC: lw          $t8, 0x118($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X118);
    // 0x80170DB0: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x80170DB4: b           L_80170DC4
    // 0x80170DB8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_80170DC4;
    // 0x80170DB8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_80170DBC:
    // 0x80170DBC: bne         $v1, $a2, L_80170D9C
    if (ctx->r3 != ctx->r6) {
        // 0x80170DC0: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80170D9C;
    }
    // 0x80170DC0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80170DC4:
    // 0x80170DC4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80170DC8: srl         $t9, $t7, 31
    ctx->r25 = S32(U32(ctx->r15) >> 31);
    // 0x80170DCC: bne         $t9, $zero, L_80171044
    if (ctx->r25 != 0) {
        // 0x80170DD0: sll         $t1, $t7, 1
        ctx->r9 = S32(ctx->r15 << 1);
            goto L_80171044;
    }
    // 0x80170DD0: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x80170DD4: bltz        $t1, L_80171044
    if (SIGNED(ctx->r9) < 0) {
        // 0x80170DD8: sll         $t3, $t7, 4
        ctx->r11 = S32(ctx->r15 << 4);
            goto L_80171044;
    }
    // 0x80170DD8: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x80170DDC: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x80170DE0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80170DE4: bnel        $t4, $at, L_80171048
    if (ctx->r12 != ctx->r1) {
        // 0x80170DE8: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80171048;
    }
    goto skip_8;
    // 0x80170DE8: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_8:
    // 0x80170DEC: lw          $t5, 0x4C($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4C);
    // 0x80170DF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80170DF4: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80170DF8: beql        $t6, $zero, L_80170FB4
    if (ctx->r14 == 0) {
        // 0x80170DFC: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_9;
    // 0x80170DFC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_9:
    // 0x80170E00: lw          $t2, 0x48($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X48);
    // 0x80170E04: srl         $t8, $t2, 31
    ctx->r24 = S32(U32(ctx->r10) >> 31);
    // 0x80170E08: beql        $t8, $zero, L_80170FB4
    if (ctx->r24 == 0) {
        // 0x80170E0C: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_10;
    // 0x80170E0C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_10:
    // 0x80170E10: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80170E14: lw          $t0, 0x8($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X8);
    // 0x80170E18: beql        $t9, $t0, L_80170FB4
    if (ctx->r25 == ctx->r8) {
        // 0x80170E1C: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_11;
    // 0x80170E1C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_11:
    // 0x80170E20: lbu         $t1, 0x2($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X2);
    // 0x80170E24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170E28: bnel        $t1, $at, L_80170E50
    if (ctx->r9 != ctx->r1) {
        // 0x80170E2C: lw          $t5, 0x0($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X0);
            goto L_80170E50;
    }
    goto skip_12;
    // 0x80170E2C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    skip_12:
    // 0x80170E30: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80170E34: bnel        $t7, $zero, L_80170E50
    if (ctx->r15 != 0) {
        // 0x80170E38: lw          $t5, 0x0($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X0);
            goto L_80170E50;
    }
    goto skip_13;
    // 0x80170E38: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    skip_13:
    // 0x80170E3C: lbu         $t3, 0x10($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X10);
    // 0x80170E40: lbu         $t4, 0x14($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X14);
    // 0x80170E44: beql        $t3, $t4, L_80170FB4
    if (ctx->r11 == ctx->r12) {
        // 0x80170E48: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_14;
    // 0x80170E48: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_14:
    // 0x80170E4C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
L_80170E50:
    // 0x80170E50: beql        $t5, $zero, L_80170FB4
    if (ctx->r13 == 0) {
        // 0x80170E54: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_15;
    // 0x80170E54: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_15:
    // 0x80170E58: lbu         $t6, 0x48($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X48);
    // 0x80170E5C: lbu         $t8, 0x80($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X80);
    // 0x80170E60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80170E64: andi        $t2, $t6, 0x2
    ctx->r10 = ctx->r14 & 0X2;
    // 0x80170E68: beq         $t2, $zero, L_80170FB0
    if (ctx->r10 == 0) {
        // 0x80170E6C: andi        $t5, $t8, 0xFFBF
        ctx->r13 = ctx->r24 & 0XFFBF;
            goto L_80170FB0;
    }
    // 0x80170E6C: andi        $t5, $t8, 0xFFBF
    ctx->r13 = ctx->r24 & 0XFFBF;
    // 0x80170E70: sb          $t5, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r13;
    // 0x80170E74: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80170E78: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80170E7C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80170E80: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80170E84: srl         $t7, $t1, 31
    ctx->r15 = S32(U32(ctx->r9) >> 31);
    // 0x80170E88: sll         $t4, $t7, 7
    ctx->r12 = S32(ctx->r15 << 7);
    // 0x80170E8C: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x80170E90: sb          $t0, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r8;
    // 0x80170E94: ori         $t1, $t0, 0xE
    ctx->r9 = ctx->r8 | 0XE;
    // 0x80170E98: sb          $t1, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r9;
L_80170E9C:
    // 0x80170E9C: lw          $t7, 0x118($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X118);
    // 0x80170EA0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80170EA4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80170EA8: bne         $s7, $t7, L_80170EC0
    if (ctx->r23 != ctx->r15) {
        // 0x80170EAC: nop
    
            goto L_80170EC0;
    }
    // 0x80170EAC: nop

    // 0x80170EB0: lw          $t5, 0x11C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X11C);
    // 0x80170EB4: addiu       $t3, $sp, 0x80
    ctx->r11 = ADD32(ctx->r29, 0X80);
    // 0x80170EB8: b           L_80170EC8
    // 0x80170EBC: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
        goto L_80170EC8;
    // 0x80170EBC: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
L_80170EC0:
    // 0x80170EC0: bne         $v1, $at, L_80170E9C
    if (ctx->r3 != ctx->r1) {
        // 0x80170EC4: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80170E9C;
    }
    // 0x80170EC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80170EC8:
    // 0x80170EC8: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80170ECC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80170ED0: srl         $t6, $t4, 31
    ctx->r14 = S32(U32(ctx->r12) >> 31);
    // 0x80170ED4: bne         $t6, $zero, L_80170EF4
    if (ctx->r14 != 0) {
        // 0x80170ED8: sll         $t8, $t4, 1
        ctx->r24 = S32(ctx->r12 << 1);
            goto L_80170EF4;
    }
    // 0x80170ED8: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x80170EDC: bltz        $t8, L_80170EF4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80170EE0: sll         $t0, $t4, 4
        ctx->r8 = S32(ctx->r12 << 4);
            goto L_80170EF4;
    }
    // 0x80170EE0: sll         $t0, $t4, 4
    ctx->r8 = S32(ctx->r12 << 4);
    // 0x80170EE4: srl         $t1, $t0, 29
    ctx->r9 = S32(U32(ctx->r8) >> 29);
    // 0x80170EE8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80170EEC: beql        $t1, $at, L_80170F00
    if (ctx->r9 == ctx->r1) {
        // 0x80170EF0: lw          $t7, 0x50($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X50);
            goto L_80170F00;
    }
    goto skip_16;
    // 0x80170EF0: lw          $t7, 0x50($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X50);
    skip_16:
L_80170EF4:
    // 0x80170EF4: b           L_80170FB8
    // 0x80170EF8: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
        goto L_80170FB8;
    // 0x80170EF8: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x80170EFC: lw          $t7, 0x50($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X50);
L_80170F00:
    // 0x80170F00: blezl       $t7, L_80170FB4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80170F04: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80170FB4;
    }
    goto skip_17;
    // 0x80170F04: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    skip_17:
    // 0x80170F08: lw          $t3, 0x54($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X54);
L_80170F0C:
    // 0x80170F0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80170F10: blez        $t3, L_80170F94
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80170F14: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80170F94;
    }
    // 0x80170F14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80170F18:
    // 0x80170F18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80170F1C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80170F20: jal         0x800F019C
    // 0x80170F24: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gmCollisionCheckWeaponAttackItemAttackCollide(rdram, ctx);
        goto after_0;
    // 0x80170F24: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80170F28: beq         $v0, $zero, L_80170F80
    if (ctx->r2 == 0) {
        // 0x80170F2C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80170F80;
    }
    // 0x80170F2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80170F30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80170F34: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80170F38: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80170F3C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80170F40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80170F44: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80170F48: jal         0x8016FE4C
    // 0x80170F4C: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    itProcessUpdateAttackStatWeapon(rdram, ctx);
        goto after_1;
    // 0x80170F4C: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    after_1:
    // 0x80170F50: lw          $t9, 0x23C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X23C);
    // 0x80170F54: beql        $t9, $zero, L_80170F68
    if (ctx->r25 == 0) {
        // 0x80170F58: lw          $t5, 0x270($s4)
        ctx->r13 = MEM_W(ctx->r20, 0X270);
            goto L_80170F68;
    }
    goto skip_18;
    // 0x80170F58: lw          $t5, 0x270($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X270);
    skip_18:
    // 0x80170F5C: b           L_80171044
    // 0x80170F60: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
        goto L_80171044;
    // 0x80170F60: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80170F64: lw          $t5, 0x270($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X270);
L_80170F68:
    // 0x80170F68: beql        $t5, $zero, L_80170F84
    if (ctx->r13 == 0) {
        // 0x80170F6C: lw          $t6, 0x54($fp)
        ctx->r14 = MEM_W(ctx->r30, 0X54);
            goto L_80170F84;
    }
    goto skip_19;
    // 0x80170F6C: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    skip_19:
    // 0x80170F70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80170F74: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
    // 0x80170F78: b           L_80170FB8
    // 0x80170F7C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
        goto L_80170FB8;
    // 0x80170F7C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_80170F80:
    // 0x80170F80: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
L_80170F84:
    // 0x80170F84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80170F88: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80170F8C: bnel        $at, $zero, L_80170F18
    if (ctx->r1 != 0) {
        // 0x80170F90: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80170F18;
    }
    goto skip_20;
    // 0x80170F90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_20:
L_80170F94:
    // 0x80170F94: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80170F98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80170F9C: lw          $t8, 0x50($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X50);
    // 0x80170FA0: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80170FA4: bnel        $at, $zero, L_80170F0C
    if (ctx->r1 != 0) {
        // 0x80170FA8: lw          $t3, 0x54($s5)
        ctx->r11 = MEM_W(ctx->r21, 0X54);
            goto L_80170F0C;
    }
    goto skip_21;
    // 0x80170FA8: lw          $t3, 0x54($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X54);
    skip_21:
    // 0x80170FAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80170FB0:
    // 0x80170FB0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_80170FB4:
    // 0x80170FB4: lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X50);
L_80170FB8:
    // 0x80170FB8: blezl       $v0, L_80171048
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80170FBC: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80171048;
    }
    goto skip_22;
    // 0x80170FBC: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_22:
    // 0x80170FC0: lw          $t4, 0x248($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X248);
L_80170FC4:
    // 0x80170FC4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80170FC8: addiu       $s0, $s4, 0x244
    ctx->r16 = ADD32(ctx->r20, 0X244);
    // 0x80170FCC: beq         $t4, $zero, L_80171044
    if (ctx->r12 == 0) {
        // 0x80170FD0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80171044;
    }
    // 0x80170FD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80170FD4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80170FD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80170FDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80170FE0: bne         $t0, $at, L_80170FF4
    if (ctx->r8 != ctx->r1) {
        // 0x80170FE4: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80170FF4;
    }
    // 0x80170FE4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80170FE8: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80170FEC: b           L_80171030
    // 0x80170FF0: lw          $v0, 0x50($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X50);
        goto L_80171030;
    // 0x80170FF0: lw          $v0, 0x50($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X50);
L_80170FF4:
    // 0x80170FF4: jal         0x800F079C
    // 0x80170FF8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gmCollisionCheckWeaponAttackItemDamageCollide(rdram, ctx);
        goto after_2;
    // 0x80170FF8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_2:
    // 0x80170FFC: beq         $v0, $zero, L_8017102C
    if (ctx->r2 == 0) {
        // 0x80171000: lw          $t7, 0x84($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X84);
            goto L_8017102C;
    }
    // 0x80171000: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80171004: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80171008: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8017100C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80171010: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80171014: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80171018: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8017101C: jal         0x801702C8
    // 0x80171020: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    itProcessUpdateDamageStatWeapon(rdram, ctx);
        goto after_3;
    // 0x80171020: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_3:
    // 0x80171024: b           L_80171044
    // 0x80171028: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
        goto L_80171044;
    // 0x80171028: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_8017102C:
    // 0x8017102C: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
L_80171030:
    // 0x80171030: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80171034: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80171038: bnel        $at, $zero, L_80170FC4
    if (ctx->r1 != 0) {
        // 0x8017103C: lw          $t4, 0x248($s4)
        ctx->r12 = MEM_W(ctx->r20, 0X248);
            goto L_80170FC4;
    }
    goto skip_23;
    // 0x8017103C: lw          $t4, 0x248($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X248);
    skip_23:
    // 0x80171040: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_80171044:
    // 0x80171044: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
L_80171048:
    // 0x80171048: bnel        $s7, $zero, L_80170CE8
    if (ctx->r23 != 0) {
        // 0x8017104C: lw          $s3, 0x84($s7)
        ctx->r19 = MEM_W(ctx->r23, 0X84);
            goto L_80170CE8;
    }
    goto skip_24;
    // 0x8017104C: lw          $s3, 0x84($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X84);
    skip_24:
    // 0x80171050: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80171054:
    // 0x80171054: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80171058: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8017105C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80171060: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80171064: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80171068: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8017106C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80171070: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80171074: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80171078: jr          $ra
    // 0x8017107C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8017107C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_ovl8_80372908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037290C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372910: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80372914: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80372918: jal         0x803717A0
    // 0x8037291C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037291C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_0:
    // 0x80372920: beq         $v0, $zero, L_80372944
    if (ctx->r2 == 0) {
        // 0x80372924: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80372944;
    }
    // 0x80372924: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80372928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037292C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80372930: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80372934: jal         0x80372844
    // 0x80372938: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_ovl8_80372844(rdram, ctx);
        goto after_1;
    // 0x80372938: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8037293C: b           L_80372948
    // 0x80372940: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80372948;
    // 0x80372940: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80372944:
    // 0x80372944: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80372948:
    // 0x80372948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037294C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80372950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80372954: jr          $ra
    // 0x80372958: nop

    return;
    // 0x80372958: nop

;}
RECOMP_FUNC void ftCommonDeadCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013CB7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013CB80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013CB84: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013CB88: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013CB8C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8013CB90: lw          $a1, 0x8E8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8E8);
    // 0x8013CB94: bne         $t6, $at, L_8013CBA4
    if (ctx->r14 != ctx->r1) {
        // 0x8013CB98: addiu       $a1, $a1, 0x1C
        ctx->r5 = ADD32(ctx->r5, 0X1C);
            goto L_8013CBA4;
    }
    // 0x8013CB98: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8013CB9C: b           L_8013CF44
    // 0x8013CBA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CF44;
    // 0x8013CBA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CBA4:
    // 0x8013CBA4: lw          $v1, 0x190($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X190);
    // 0x8013CBA8: sll         $t8, $v1, 17
    ctx->r24 = S32(ctx->r3 << 17);
    // 0x8013CBAC: bgezl       $t8, L_8013CBC0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8013CBB0: lw          $t9, 0x18C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X18C);
            goto L_8013CBC0;
    }
    goto skip_0;
    // 0x8013CBB0: lw          $t9, 0x18C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18C);
    skip_0:
    // 0x8013CBB4: b           L_8013CF44
    // 0x8013CBB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CF44;
    // 0x8013CBB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CBBC: lw          $t9, 0x18C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18C);
L_8013CBC0:
    // 0x8013CBC0: sll         $t7, $v1, 9
    ctx->r15 = S32(ctx->r3 << 9);
    // 0x8013CBC4: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x8013CBC8: bgez        $t1, L_8013CCF4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8013CBCC: nop
    
            goto L_8013CCF4;
    }
    // 0x8013CBCC: nop

    // 0x8013CBD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013CBD4: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x8013CBD8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8013CBDC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8013CBE0: lh          $t2, 0x76($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X76);
    // 0x8013CBE4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013CBE8: nop

    // 0x8013CBEC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013CBF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8013CBF4: nop

    // 0x8013CBF8: bc1fl       L_8013CC2C
    if (!c1cs) {
        // 0x8013CBFC: lh          $t3, 0x74($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X74);
            goto L_8013CC2C;
    }
    goto skip_1;
    // 0x8013CBFC: lh          $t3, 0x74($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X74);
    skip_1:
    // 0x8013CC00: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8013CC04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013CC08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013CC0C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8013CC10: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8013CC14: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC18: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC1C: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC20: b           L_8013CC70
    // 0x8013CC24: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
        goto L_8013CC70;
    // 0x8013CC24: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x8013CC28: lh          $t3, 0x74($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X74);
L_8013CC2C:
    // 0x8013CC2C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8013CC30: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013CC34: nop

    // 0x8013CC38: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013CC3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8013CC40: nop

    // 0x8013CC44: bc1fl       L_8013CC74
    if (!c1cs) {
        // 0x8013CC48: lh          $t4, 0x78($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X78);
            goto L_8013CC74;
    }
    goto skip_2;
    // 0x8013CC48: lh          $t4, 0x78($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X78);
    skip_2:
    // 0x8013CC4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8013CC50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013CC54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013CC58: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8013CC5C: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8013CC60: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC64: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC68: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x8013CC6C: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
L_8013CC70:
    // 0x8013CC70: lh          $t4, 0x78($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X78);
L_8013CC74:
    // 0x8013CC74: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8013CC78: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8013CC7C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8013CC80: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8013CC84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013CC88: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013CC8C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8013CC90: nop

    // 0x8013CC94: bc1fl       L_8013CCBC
    if (!c1cs) {
        // 0x8013CC98: lh          $t5, 0x7A($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X7A);
            goto L_8013CCBC;
    }
    goto skip_3;
    // 0x8013CC98: lh          $t5, 0x7A($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X7A);
    skip_3:
    // 0x8013CC9C: sub.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8013CCA0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8013CCA4: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8013CCA8: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x8013CCAC: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
    // 0x8013CCB0: b           L_8013CF44
    // 0x8013CCB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CF44;
    // 0x8013CCB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013CCB8: lh          $t5, 0x7A($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X7A);
L_8013CCBC:
    // 0x8013CCBC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8013CCC0: nop

    // 0x8013CCC4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013CCC8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8013CCCC: nop

    // 0x8013CCD0: bc1f        L_8013CCEC
    if (!c1cs) {
        // 0x8013CCD4: nop
    
            goto L_8013CCEC;
    }
    // 0x8013CCD4: nop

    // 0x8013CCD8: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8013CCDC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8013CCE0: swc1        $f2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f2.u32l;
    // 0x8013CCE4: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x8013CCE8: swc1        $f2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f2.u32l;
L_8013CCEC:
    // 0x8013CCEC: b           L_8013CF44
    // 0x8013CCF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013CF44;
    // 0x8013CCF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CCF4:
    // 0x8013CCF4: bltz        $t7, L_8013CF40
    if (SIGNED(ctx->r15) < 0) {
        // 0x8013CCF8: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8013CF40;
    }
    // 0x8013CCF8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013CCFC: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8013CD00: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013CD04: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8013CD08: bne         $t8, $at, L_8013CE3C
    if (ctx->r24 != ctx->r1) {
        // 0x8013CD0C: nop
    
            goto L_8013CE3C;
    }
    // 0x8013CD0C: nop

    // 0x8013CD10: lbu         $t9, 0xD($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XD);
    // 0x8013CD14: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8013CD18: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8013CD1C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013CD20: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8013CD24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013CD28: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8013CD2C: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x8013CD30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013CD34: beq         $t2, $zero, L_8013CE3C
    if (ctx->r10 == 0) {
        // 0x8013CD38: nop
    
            goto L_8013CE3C;
    }
    // 0x8013CD38: nop

    // 0x8013CD3C: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x8013CD40: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8013CD44: lh          $t3, 0x94($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X94);
    // 0x8013CD48: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013CD4C: nop

    // 0x8013CD50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013CD54: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8013CD58: nop

    // 0x8013CD5C: bc1fl       L_8013CD78
    if (!c1cs) {
        // 0x8013CD60: lh          $t4, 0x96($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X96);
            goto L_8013CD78;
    }
    goto skip_4;
    // 0x8013CD60: lh          $t4, 0x96($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X96);
    skip_4:
    // 0x8013CD64: jal         0x8013C1C4
    // 0x8013CD68: nop

    ftCommonDeadDownSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013CD68: nop

    after_0:
    // 0x8013CD6C: b           L_8013CF44
    // 0x8013CD70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CD70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CD74: lh          $t4, 0x96($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X96);
L_8013CD78:
    // 0x8013CD78: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8013CD7C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8013CD80: nop

    // 0x8013CD84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013CD88: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8013CD8C: nop

    // 0x8013CD90: bc1fl       L_8013CDAC
    if (!c1cs) {
        // 0x8013CD94: lh          $t5, 0x98($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X98);
            goto L_8013CDAC;
    }
    goto skip_5;
    // 0x8013CD94: lh          $t5, 0x98($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X98);
    skip_5:
    // 0x8013CD98: jal         0x8013C30C
    // 0x8013CD9C: nop

    ftCommonDeadRightSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013CD9C: nop

    after_1:
    // 0x8013CDA0: b           L_8013CF44
    // 0x8013CDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CDA8: lh          $t5, 0x98($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X98);
L_8013CDAC:
    // 0x8013CDAC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8013CDB0: nop

    // 0x8013CDB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013CDB8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013CDBC: nop

    // 0x8013CDC0: bc1fl       L_8013CDDC
    if (!c1cs) {
        // 0x8013CDC4: lh          $t6, 0x92($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X92);
            goto L_8013CDDC;
    }
    goto skip_6;
    // 0x8013CDC4: lh          $t6, 0x92($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X92);
    skip_6:
    // 0x8013CDC8: jal         0x8013C454
    // 0x8013CDCC: nop

    ftCommonDeadLeftSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013CDCC: nop

    after_2:
    // 0x8013CDD0: b           L_8013CF44
    // 0x8013CDD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CDD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CDD8: lh          $t6, 0x92($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X92);
L_8013CDDC:
    // 0x8013CDDC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8013CDE0: nop

    // 0x8013CDE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013CDE8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8013CDEC: nop

    // 0x8013CDF0: bc1fl       L_8013CF44
    if (!c1cs) {
        // 0x8013CDF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013CF44;
    }
    goto skip_7;
    // 0x8013CDF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x8013CDF8: jal         0x80018948
    // 0x8013CDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x8013CDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x8013CE00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013CE04: lwc1        $f16, -0x3FC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3FC4);
    // 0x8013CE08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013CE0C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013CE10: nop

    // 0x8013CE14: bc1f        L_8013CE2C
    if (!c1cs) {
        // 0x8013CE18: nop
    
            goto L_8013CE2C;
    }
    // 0x8013CE18: nop

    // 0x8013CE1C: jal         0x8013CAAC
    // 0x8013CE20: nop

    ftCommonDeadUpFallSetStatus(rdram, ctx);
        goto after_4;
    // 0x8013CE20: nop

    after_4:
    // 0x8013CE24: b           L_8013CF44
    // 0x8013CE28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CE28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CE2C:
    // 0x8013CE2C: jal         0x8013C740
    // 0x8013CE30: nop

    ftCommonDeadUpStarSetStatus(rdram, ctx);
        goto after_5;
    // 0x8013CE30: nop

    after_5:
    // 0x8013CE34: b           L_8013CF44
    // 0x8013CE38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CE38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CE3C:
    // 0x8013CE3C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013CE40: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x8013CE44: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8013CE48: lh          $t7, 0x76($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X76);
    // 0x8013CE4C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8013CE50: nop

    // 0x8013CE54: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013CE58: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8013CE5C: nop

    // 0x8013CE60: bc1fl       L_8013CE7C
    if (!c1cs) {
        // 0x8013CE64: lh          $t8, 0x78($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X78);
            goto L_8013CE7C;
    }
    goto skip_8;
    // 0x8013CE64: lh          $t8, 0x78($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X78);
    skip_8:
    // 0x8013CE68: jal         0x8013C1C4
    // 0x8013CE6C: nop

    ftCommonDeadDownSetStatus(rdram, ctx);
        goto after_6;
    // 0x8013CE6C: nop

    after_6:
    // 0x8013CE70: b           L_8013CF44
    // 0x8013CE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CE74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CE78: lh          $t8, 0x78($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X78);
L_8013CE7C:
    // 0x8013CE7C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8013CE80: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8013CE84: nop

    // 0x8013CE88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013CE8C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8013CE90: nop

    // 0x8013CE94: bc1fl       L_8013CEB0
    if (!c1cs) {
        // 0x8013CE98: lh          $t9, 0x7A($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X7A);
            goto L_8013CEB0;
    }
    goto skip_9;
    // 0x8013CE98: lh          $t9, 0x7A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X7A);
    skip_9:
    // 0x8013CE9C: jal         0x8013C30C
    // 0x8013CEA0: nop

    ftCommonDeadRightSetStatus(rdram, ctx);
        goto after_7;
    // 0x8013CEA0: nop

    after_7:
    // 0x8013CEA4: b           L_8013CF44
    // 0x8013CEA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CEA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CEAC: lh          $t9, 0x7A($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X7A);
L_8013CEB0:
    // 0x8013CEB0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8013CEB4: nop

    // 0x8013CEB8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013CEBC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013CEC0: nop

    // 0x8013CEC4: bc1fl       L_8013CEE0
    if (!c1cs) {
        // 0x8013CEC8: lh          $t0, 0x74($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X74);
            goto L_8013CEE0;
    }
    goto skip_10;
    // 0x8013CEC8: lh          $t0, 0x74($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X74);
    skip_10:
    // 0x8013CECC: jal         0x8013C454
    // 0x8013CED0: nop

    ftCommonDeadLeftSetStatus(rdram, ctx);
        goto after_8;
    // 0x8013CED0: nop

    after_8:
    // 0x8013CED4: b           L_8013CF44
    // 0x8013CED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013CEDC: lh          $t0, 0x74($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X74);
L_8013CEE0:
    // 0x8013CEE0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8013CEE4: nop

    // 0x8013CEE8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013CEEC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8013CEF0: nop

    // 0x8013CEF4: bc1fl       L_8013CF44
    if (!c1cs) {
        // 0x8013CEF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013CF44;
    }
    goto skip_11;
    // 0x8013CEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x8013CEFC: jal         0x80018948
    // 0x8013CF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x8013CF00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_9:
    // 0x8013CF04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013CF08: lwc1        $f6, -0x3FC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3FC0);
    // 0x8013CF0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013CF10: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013CF14: nop

    // 0x8013CF18: bc1f        L_8013CF30
    if (!c1cs) {
        // 0x8013CF1C: nop
    
            goto L_8013CF30;
    }
    // 0x8013CF1C: nop

    // 0x8013CF20: jal         0x8013CAAC
    // 0x8013CF24: nop

    ftCommonDeadUpFallSetStatus(rdram, ctx);
        goto after_10;
    // 0x8013CF24: nop

    after_10:
    // 0x8013CF28: b           L_8013CF44
    // 0x8013CF2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CF2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CF30:
    // 0x8013CF30: jal         0x8013C740
    // 0x8013CF34: nop

    ftCommonDeadUpStarSetStatus(rdram, ctx);
        goto after_11;
    // 0x8013CF34: nop

    after_11:
    // 0x8013CF38: b           L_8013CF44
    // 0x8013CF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013CF44;
    // 0x8013CF3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013CF40:
    // 0x8013CF40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013CF44:
    // 0x8013CF44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013CF48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013CF4C: jr          $ra
    // 0x8013CF50: nop

    return;
    // 0x8013CF50: nop

;}
RECOMP_FUNC void syUtilsTan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800184E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800184E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800184E8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800184EC: jal         0x800303F0
    // 0x800184F0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800184F0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800184F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800184F8: jal         0x80035CD0
    // 0x800184FC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800184FC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80018500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018504: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80018508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001850C: jr          $ra
    // 0x80018510: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x80018510: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void ftCommonWallDamageSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141B08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80141B0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80141B10: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80141B14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80141B18: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80141B1C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80141B20: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80141B24: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80141B28: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80141B2C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80141B30: jal         0x8001863C
    // 0x80141B34: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80141B34: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80141B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80141B3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80141B40: jal         0x800FFD58
    // 0x80141B44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    efManagerImpactWaveMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80141B44: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80141B48: jal         0x801008F4
    // 0x80141B4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80141B4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80141B50: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    // 0x80141B54: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x80141B58: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80141B5C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80141B60: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x80141B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80141B68: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80141B6C: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80141B70: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x80141B74: jal         0x800C7AB8
    // 0x80141B78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    lbCommonAdd2D(rdram, ctx);
        goto after_3;
    // 0x80141B78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80141B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80141B80: jal         0x800C7B08
    // 0x80141B84: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    lbCommonReflect2D(rdram, ctx);
        goto after_4;
    // 0x80141B84: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80141B88: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80141B8C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80141B90: jal         0x800C7AE0
    // 0x80141B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbCommonScale2D(rdram, ctx);
        goto after_5;
    // 0x80141B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80141B98: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80141B9C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80141BA0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80141BA4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80141BA8: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80141BAC: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x80141BB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80141BB4: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80141BB8: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80141BBC: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x80141BC0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80141BC4: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    // 0x80141BC8: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
    // 0x80141BCC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80141BD0: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x80141BD4: bc1fl       L_80141BE8
    if (!c1cs) {
        // 0x80141BD8: sw          $t3, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r11;
            goto L_80141BE8;
    }
    goto skip_0;
    // 0x80141BD8: sw          $t3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r11;
    skip_0:
    // 0x80141BDC: b           L_80141BE8
    // 0x80141BE0: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
        goto L_80141BE8;
    // 0x80141BE0: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x80141BE4: sw          $t3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r11;
L_80141BE8:
    // 0x80141BE8: jal         0x800C7A84
    // 0x80141BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbCommonMag2D(rdram, ctx);
        goto after_6;
    // 0x80141BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80141BF0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80141BF4: jal         0x800EA1B0
    // 0x80141BF8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    ftParamGetHitStun(rdram, ctx);
        goto after_7;
    // 0x80141BF8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80141BFC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80141C00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80141C04: addiu       $t6, $zero, 0x1100
    ctx->r14 = ADD32(0, 0X1100);
    // 0x80141C08: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80141C0C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80141C10: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80141C14: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80141C18: sw          $t5, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r13;
    // 0x80141C1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80141C20: jal         0x800E6F24
    // 0x80141C24: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    ftMainSetStatus(rdram, ctx);
        goto after_8;
    // 0x80141C24: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80141C28: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80141C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141C30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80141C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80141C38: jal         0x800E806C
    // 0x80141C3C: swc1        $f8, 0x7EC($s0)
    MEM_W(0X7EC, ctx->r16) = ctx->f8.u32l;
    ftParamMakeRumble(rdram, ctx);
        goto after_9;
    // 0x80141C3C: swc1        $f8, 0x7EC($s0)
    MEM_W(0X7EC, ctx->r16) = ctx->f8.u32l;
    after_9:
    // 0x80141C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141C44: jal         0x800EA948
    // 0x80141C48: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    ftParamSetTimedHitStatusIntangible(rdram, ctx);
        goto after_10;
    // 0x80141C48: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_10:
    // 0x80141C4C: lbu         $t7, 0x18F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18F);
    // 0x80141C50: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80141C54: sb          $t8, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r24;
    // 0x80141C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80141C5C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80141C60: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80141C64: jr          $ra
    // 0x80141C68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80141C68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftPikachuSpecialAirLwEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152628: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8015262C: jal         0x800D9480
    // 0x80152630: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152630: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    after_0:
    // 0x80152634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015263C: jr          $ra
    // 0x80152640: nop

    return;
    // 0x80152640: nop

;}
RECOMP_FUNC void itGShellMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178FDC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80178FE0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80178FE4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80178FE8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80178FEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80178FF0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80178FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80178FF8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178FFC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80179000: addiu       $a1, $a1, -0x5E00
    ctx->r5 = ADD32(ctx->r5, -0X5E00);
    // 0x80179004: jal         0x8016E174
    // 0x80179008: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80179008: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017900C: beq         $v0, $zero, L_801790E0
    if (ctx->r2 == 0) {
        // 0x80179010: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_801790E0;
    }
    // 0x80179010: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80179014: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80179018: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x8017901C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179020: addiu       $v0, $a0, 0x1C
    ctx->r2 = ADD32(ctx->r4, 0X1C);
    // 0x80179024: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80179028: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017902C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80179030: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80179034: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80179038: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8017903C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80179040: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x80179044: lwc1        $f4, -0x32B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32B0);
    // 0x80179048: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8017904C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80179050: jal         0x80008CC0
    // 0x80179054: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80179054: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x80179058: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8017905C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80179060: jal         0x80008CC0
    // 0x80179064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80179064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80179068: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x8017906C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80179070: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80179074: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80179078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017907C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80179080: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80179084: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80179088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017908C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80179090: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80179094: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80179098: lw          $t5, 0x80($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X80);
    // 0x8017909C: swc1        $f6, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f6.u32l;
    // 0x801790A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801790A4: lw          $a0, 0x84($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X84);
    // 0x801790A8: lbu         $t8, 0x158($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X158);
    // 0x801790AC: lbu         $t2, 0x2D3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2D3);
    // 0x801790B0: sb          $t0, 0x352($a0)
    MEM_B(0X352, ctx->r4) = ctx->r8;
    // 0x801790B4: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x801790B8: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x801790BC: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    // 0x801790C0: sb          $zero, 0x353($a0)
    MEM_B(0X353, ctx->r4) = 0;
    // 0x801790C4: sb          $t3, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r11;
    // 0x801790C8: jal         0x80111EC0
    // 0x801790CC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_3;
    // 0x801790CC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_3:
    // 0x801790D0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801790D4: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x801790D8: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
    // 0x801790DC: sw          $t4, 0x2C0($a0)
    MEM_W(0X2C0, ctx->r4) = ctx->r12;
L_801790E0:
    // 0x801790E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801790E4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x801790E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801790EC: jr          $ra
    // 0x801790F0: nop

    return;
    // 0x801790F0: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160568: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016056C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80160570: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80160574: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80160578: nop

    // 0x8016057C: bc1fl       L_801605C0
    if (!c1cs) {
        // 0x80160580: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_801605C0;
    }
    goto skip_0;
    // 0x80160580: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x80160584: lw          $t6, 0x184($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X184);
    // 0x80160588: bne         $t6, $zero, L_801605A0
    if (ctx->r14 != 0) {
        // 0x8016058C: nop
    
            goto L_801605A0;
    }
    // 0x8016058C: nop

    // 0x80160590: jal         0x800DE978
    // 0x80160594: nop

    mpCommonProcFighterCliffWaitOrLanding(rdram, ctx);
        goto after_0;
    // 0x80160594: nop

    after_0:
    // 0x80160598: b           L_801605F0
    // 0x8016059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801605F0;
    // 0x8016059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801605A0:
    // 0x801605A0: jal         0x800DE958
    // 0x801605A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonProcFighterProject(rdram, ctx);
        goto after_1;
    // 0x801605A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x801605A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801605AC: lw          $t7, 0x184($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X184);
    // 0x801605B0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801605B4: b           L_801605EC
    // 0x801605B8: sw          $t8, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->r24;
        goto L_801605EC;
    // 0x801605B8: sw          $t8, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->r24;
    // 0x801605BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_801605C0:
    // 0x801605C0: jal         0x800DE87C
    // 0x801605C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_2;
    // 0x801605C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x801605C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801605CC: beq         $v0, $zero, L_801605EC
    if (ctx->r2 == 0) {
        // 0x801605D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801605EC;
    }
    // 0x801605D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801605D4: lhu         $t9, 0xD2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XD2);
    // 0x801605D8: andi        $t0, $t9, 0x3000
    ctx->r8 = ctx->r25 & 0X3000;
    // 0x801605DC: beql        $t0, $zero, L_801605F0
    if (ctx->r8 == 0) {
        // 0x801605E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801605F0;
    }
    goto skip_1;
    // 0x801605E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801605E4: jal         0x80144C24
    // 0x801605E8: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_3;
    // 0x801605E8: nop

    after_3:
L_801605EC:
    // 0x801605EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801605F0:
    // 0x801605F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801605F4: jr          $ra
    // 0x801605F8: nop

    return;
    // 0x801605F8: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackSpecialCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFFCC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800EFFD0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EFFD4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800EFFD8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800EFFDC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800EFFE0: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800EFFE4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800EFFE8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800EFFEC: lw          $a0, 0x8E8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8E8);
    // 0x800EFFF0: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    // 0x800EFFF4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x800EFFF8: jal         0x800EDE00
    // 0x800EFFFC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EFFFC: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    after_0:
    // 0x800F0000: jal         0x800EDE5C
    // 0x800F0004: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800F0004: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800F0008: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800F000C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800F0010: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0014: lw          $a2, 0x28($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X28);
    // 0x800F0018: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800F001C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800F0020: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800F0024: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800F0028: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800F002C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800F0030: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
    // 0x800F0034: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x800F0038: addiu       $t7, $t0, 0x14
    ctx->r15 = ADD32(ctx->r8, 0X14);
    // 0x800F003C: addiu       $t5, $t1, 0x9C
    ctx->r13 = ADD32(ctx->r9, 0X9C);
    // 0x800F0040: addiu       $t8, $t1, 0x90
    ctx->r24 = ADD32(ctx->r9, 0X90);
    // 0x800F0044: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F0048: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800F004C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800F0050: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800F0054: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800F0058: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800F005C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800F0060: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800F0064: jal         0x800EE750
    // 0x800F0068: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    gmCollisionTestSphere(rdram, ctx);
        goto after_2;
    // 0x800F0068: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x800F006C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F0070: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800F0074: jr          $ra
    // 0x800F0078: nop

    return;
    // 0x800F0078: nop

;}
RECOMP_FUNC void ftKirbySpecialAirHiFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801612D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801612DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801612E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801612E4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801612E8: addiu       $a1, $zero, 0x103
    ctx->r5 = ADD32(0, 0X103);
    // 0x801612EC: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801612F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801612F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801612F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801612FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161300: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80161304: jal         0x800E6F24
    // 0x80161308: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161308: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8016130C: jal         0x800E0830
    // 0x80161310: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161310: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161314: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80161318: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8016131C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80161320: lw          $t9, 0x9C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C8);
    // 0x80161324: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x80161328: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x8016132C: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x80161330: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x80161334: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80161338: sb          $t0, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r8;
    // 0x8016133C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80161340: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x80161344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016134C: jr          $ra
    // 0x80161350: nop

    return;
    // 0x80161350: nop

;}
RECOMP_FUNC void ftCommonGuardOnCheckInterruptDashRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148D34: jal         0x80148CBC
    // 0x80148D38: nop

    ftCommonGuardOnCheckInterruptSuccess(rdram, ctx);
        goto after_0;
    // 0x80148D38: nop

    after_0:
    // 0x80148D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148D44: jr          $ra
    // 0x80148D48: nop

    return;
    // 0x80148D48: nop

;}
RECOMP_FUNC void syInterpCubicBezierScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DB74: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001DB78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DB7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DB80: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001DB84: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001DB88: sub.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8001DB8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001DB90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DB94: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001DB98: nop

    // 0x8001DB9C: mul.s       $f14, $f0, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001DBA0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x8001DBA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DBA8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001DBAC: nop

    // 0x8001DBB0: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8001DBB4: nop

    // 0x8001DBB8: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001DBBC: nop

    // 0x8001DBC0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001DBC4: nop

    // 0x8001DBC8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001DBCC: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8001DBD0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001DBD4: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001DBD8: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001DBDC: nop

    // 0x8001DBE0: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8001DBE4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001DBE8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001DBEC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001DBF0: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001DBF4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001DBF8: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001DBFC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001DC00: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001DC04: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8001DC08: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001DC0C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001DC10: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001DC14: nop

    // 0x8001DC18: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001DC1C: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001DC20: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001DC24: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001DC28: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8001DC2C: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001DC30: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001DC34: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001DC38: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001DC3C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001DC40: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8001DC44: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001DC48: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001DC4C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001DC50: nop

    // 0x8001DC54: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001DC58: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001DC5C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001DC60: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001DC64: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001DC68: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001DC6C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001DC70: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001DC74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DC78: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001DC7C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001DC80: jr          $ra
    // 0x8001DC84: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8001DC84: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void itLGunWeaponAmmoProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175988: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017598C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175990: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80175994: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175998: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017599C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801759A0: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x801759A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801759A8: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x801759AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801759B0: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x801759B4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801759B8: jal         0x80019438
    // 0x801759BC: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x801759BC: nop

    after_0:
    // 0x801759C0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801759C4: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801759C8: jal         0x8001863C
    // 0x801759CC: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x801759CC: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x801759D0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801759D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801759D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801759DC: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x801759E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801759E4: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x801759E8: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x801759EC: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x801759F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801759F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801759F8: jr          $ra
    // 0x801759FC: nop

    return;
    // 0x801759FC: nop

;}
RECOMP_FUNC void ftFoxSpecialHiHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BFCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BFD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BFD4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015BFD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015BFDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015BFE0: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015BFE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BFE8: jal         0x800E6F24
    // 0x8015BFEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BFEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015BFF0: jal         0x800E0830
    // 0x8015BFF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015BFF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015BFF8: jal         0x8015BFBC
    // 0x8015BFFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialHiHoldInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015BFFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015C000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C008: jr          $ra
    // 0x8015C00C: nop

    return;
    // 0x8015C00C: nop

;}
RECOMP_FUNC void itBoxFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801797A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801797A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801797AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801797B0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801797B4: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x801797B8: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801797BC: jal         0x80173F78
    // 0x801797C0: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801797C0: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x801797C4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801797C8: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x801797CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801797D0: jal         0x80172EC8
    // 0x801797D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801797D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801797D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801797DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801797E0: jr          $ra
    // 0x801797E4: nop

    return;
    // 0x801797E4: nop

;}
RECOMP_FUNC void itMainClearAttackRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801725F8: lbu         $t6, 0x228($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X228);
    // 0x801725FC: lbu         $t3, 0x230($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X230);
    // 0x80172600: sw          $zero, 0x22C($a0)
    MEM_W(0X22C, ctx->r4) = 0;
    // 0x80172604: andi        $t0, $t6, 0xFFDF
    ctx->r8 = ctx->r14 & 0XFFDF;
    // 0x80172608: sb          $t0, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r8;
    // 0x8017260C: lw          $v0, 0x228($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X228);
    // 0x80172610: andi        $t1, $t0, 0xBF
    ctx->r9 = ctx->r8 & 0XBF;
    // 0x80172614: sw          $zero, 0x234($a0)
    MEM_W(0X234, ctx->r4) = 0;
    // 0x80172618: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8017261C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80172620: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x80172624: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x80172628: or          $t5, $t9, $t1
    ctx->r13 = ctx->r25 | ctx->r9;
    // 0x8017262C: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80172630: sll         $t4, $v0, 7
    ctx->r12 = S32(ctx->r2 << 7);
    // 0x80172634: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80172638: sb          $t5, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r13;
    // 0x8017263C: sb          $t7, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r15;
    // 0x80172640: lhu         $t8, 0x228($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X228);
    // 0x80172644: andi        $t7, $t3, 0xFFDF
    ctx->r15 = ctx->r11 & 0XFFDF;
    // 0x80172648: sb          $t7, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r15;
    // 0x8017264C: lw          $v0, 0x230($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X230);
    // 0x80172650: andi        $t0, $t8, 0xFE07
    ctx->r8 = ctx->r24 & 0XFE07;
    // 0x80172654: sh          $t0, 0x228($a0)
    MEM_H(0X228, ctx->r4) = ctx->r8;
    // 0x80172658: lbu         $t1, 0x228($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X228);
    // 0x8017265C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80172660: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80172664: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x80172668: ori         $t2, $t1, 0xE
    ctx->r10 = ctx->r9 | 0XE;
    // 0x8017266C: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x80172670: andi        $t8, $t7, 0xBF
    ctx->r24 = ctx->r15 & 0XBF;
    // 0x80172674: sb          $t2, 0x228($a0)
    MEM_B(0X228, ctx->r4) = ctx->r10;
    // 0x80172678: or          $t2, $t6, $t8
    ctx->r10 = ctx->r14 | ctx->r24;
    // 0x8017267C: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80172680: sll         $t1, $v0, 7
    ctx->r9 = S32(ctx->r2 << 7);
    // 0x80172684: lbu         $t9, 0x238($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X238);
    // 0x80172688: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x8017268C: sb          $t2, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r10;
    // 0x80172690: sb          $t5, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r13;
    // 0x80172694: lhu         $t4, 0x230($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X230);
    // 0x80172698: andi        $t5, $t9, 0xFFDF
    ctx->r13 = ctx->r25 & 0XFFDF;
    // 0x8017269C: sb          $t5, 0x238($a0)
    MEM_B(0X238, ctx->r4) = ctx->r13;
    // 0x801726A0: lw          $v0, 0x238($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X238);
    // 0x801726A4: andi        $t7, $t4, 0xFE07
    ctx->r15 = ctx->r12 & 0XFE07;
    // 0x801726A8: sh          $t7, 0x230($a0)
    MEM_H(0X230, ctx->r4) = ctx->r15;
    // 0x801726AC: lbu         $t8, 0x230($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X230);
    // 0x801726B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801726B4: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x801726B8: sll         $t1, $v0, 6
    ctx->r9 = S32(ctx->r2 << 6);
    // 0x801726BC: ori         $t0, $t8, 0xE
    ctx->r8 = ctx->r24 | 0XE;
    // 0x801726C0: sb          $t0, 0x230($a0)
    MEM_B(0X230, ctx->r4) = ctx->r8;
    // 0x801726C4: andi        $t3, $t1, 0x40
    ctx->r11 = ctx->r9 & 0X40;
    // 0x801726C8: andi        $t4, $t5, 0xBF
    ctx->r12 = ctx->r13 & 0XBF;
    // 0x801726CC: or          $t0, $t3, $t4
    ctx->r8 = ctx->r11 | ctx->r12;
    // 0x801726D0: andi        $t9, $t0, 0x7F
    ctx->r25 = ctx->r8 & 0X7F;
    // 0x801726D4: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x801726D8: lbu         $t6, 0x240($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X240);
    // 0x801726DC: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x801726E0: sb          $t0, 0x238($a0)
    MEM_B(0X238, ctx->r4) = ctx->r8;
    // 0x801726E4: sb          $t2, 0x238($a0)
    MEM_B(0X238, ctx->r4) = ctx->r10;
    // 0x801726E8: lhu         $t1, 0x238($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X238);
    // 0x801726EC: andi        $t2, $t6, 0xFFDF
    ctx->r10 = ctx->r14 & 0XFFDF;
    // 0x801726F0: sb          $t2, 0x240($a0)
    MEM_B(0X240, ctx->r4) = ctx->r10;
    // 0x801726F4: lw          $v0, 0x240($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X240);
    // 0x801726F8: andi        $t5, $t1, 0xFE07
    ctx->r13 = ctx->r9 & 0XFE07;
    // 0x801726FC: sh          $t5, 0x238($a0)
    MEM_H(0X238, ctx->r4) = ctx->r13;
    // 0x80172700: lbu         $t4, 0x238($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X238);
    // 0x80172704: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80172708: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x8017270C: sll         $t8, $v0, 6
    ctx->r24 = S32(ctx->r2 << 6);
    // 0x80172710: ori         $t7, $t4, 0xE
    ctx->r15 = ctx->r12 | 0XE;
    // 0x80172714: sb          $t7, 0x238($a0)
    MEM_B(0X238, ctx->r4) = ctx->r15;
    // 0x80172718: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8017271C: andi        $t1, $t2, 0xBF
    ctx->r9 = ctx->r10 & 0XBF;
    // 0x80172720: or          $t7, $t9, $t1
    ctx->r15 = ctx->r25 | ctx->r9;
    // 0x80172724: andi        $t6, $t7, 0x7F
    ctx->r14 = ctx->r15 & 0X7F;
    // 0x80172728: sll         $t4, $v0, 7
    ctx->r12 = S32(ctx->r2 << 7);
    // 0x8017272C: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x80172730: sb          $t7, 0x240($a0)
    MEM_B(0X240, ctx->r4) = ctx->r15;
    // 0x80172734: sb          $t0, 0x240($a0)
    MEM_B(0X240, ctx->r4) = ctx->r8;
    // 0x80172738: lhu         $t8, 0x240($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X240);
    // 0x8017273C: sw          $zero, 0x23C($a0)
    MEM_W(0X23C, ctx->r4) = 0;
    // 0x80172740: sw          $zero, 0x224($a0)
    MEM_W(0X224, ctx->r4) = 0;
    // 0x80172744: andi        $t2, $t8, 0xFE07
    ctx->r10 = ctx->r24 & 0XFE07;
    // 0x80172748: sh          $t2, 0x240($a0)
    MEM_H(0X240, ctx->r4) = ctx->r10;
    // 0x8017274C: lbu         $t1, 0x240($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X240);
    // 0x80172750: ori         $t5, $t1, 0xE
    ctx->r13 = ctx->r9 | 0XE;
    // 0x80172754: jr          $ra
    // 0x80172758: sb          $t5, 0x240($a0)
    MEM_B(0X240, ctx->r4) = ctx->r13;
    return;
    // 0x80172758: sb          $t5, 0x240($a0)
    MEM_B(0X240, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void gmRumbleUpdateEventLinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80115174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115178: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8011517C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80115180: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x80115184: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80115188: beql        $s0, $zero, L_801151E4
    if (ctx->r16 == 0) {
        // 0x8011518C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801151E4;
    }
    goto skip_0;
    // 0x8011518C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80115190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80115194:
    // 0x80115194: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80115198: beql        $t6, $zero, L_801151E4
    if (ctx->r14 == 0) {
        // 0x8011519C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801151E4;
    }
    goto skip_1;
    // 0x8011519C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801151A0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x801151A4: beql        $v0, $zero, L_801151C4
    if (ctx->r2 == 0) {
        // 0x801151A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801151C4;
    }
    goto skip_2;
    // 0x801151A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x801151AC: bgezl       $v0, L_801151D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801151B0: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_801151D8;
    }
    goto skip_3;
    // 0x801151B0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x801151B4: jal         0x801150F0
    // 0x801151B8: nop

    gmRumbleUpdateEventCheckEnd(rdram, ctx);
        goto after_0;
    // 0x801151B8: nop

    after_0:
    // 0x801151BC: beq         $v0, $zero, L_801151D4
    if (ctx->r2 == 0) {
        // 0x801151C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801151D4;
    }
    // 0x801151C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_801151C4:
    // 0x801151C4: jal         0x80115090
    // 0x801151C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmRumbleAddLinkAfter(rdram, ctx);
        goto after_1;
    // 0x801151C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x801151CC: b           L_801151D8
    // 0x801151D0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_801151D8;
    // 0x801151D0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
L_801151D4:
    // 0x801151D4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_801151D8:
    // 0x801151D8: bnel        $s0, $zero, L_80115194
    if (ctx->r16 != 0) {
        // 0x801151DC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80115194;
    }
    goto skip_4;
    // 0x801151DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x801151E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801151E4:
    // 0x801151E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801151E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801151EC: jr          $ra
    // 0x801151F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801151F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PTrainingModeInitSpriteEnvColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E300: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x8018E304: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x8018E308: jr          $ra
    // 0x8018E30C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    return;
    // 0x8018E30C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
;}
RECOMP_FUNC void ftKirbySpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161A94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161A98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161A9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161AA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161AA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80161AA8: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x80161AAC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161AB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161AB4: jal         0x800E6F24
    // 0x80161AB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161AB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80161ABC: jal         0x800E0830
    // 0x80161AC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161AC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161AC4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80161AC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80161ACC: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80161AD0: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x80161AD4: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80161AD8: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80161ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161AE4: jr          $ra
    // 0x80161AE8: nop

    return;
    // 0x80161AE8: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153F40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153F44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153F48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153F4C: jal         0x800DEE98
    // 0x80153F50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80153F50: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80153F54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80153F58: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80153F5C: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80153F60: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153F64: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80153F68: jal         0x800E6F24
    // 0x80153F6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153F6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153F70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153F78: jr          $ra
    // 0x80153F7C: nop

    return;
    // 0x80153F7C: nop

;}
RECOMP_FUNC void sc1PTrainingModeUnderlineProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FCE0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8018FCE4: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8018FCE8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FCEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018FCF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018FCF4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018FCF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018FCFC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018FD00: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8018FD04: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018FD08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018FD0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FD10: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8018FD14: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x8018FD18: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018FD1C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8018FD20: lui         $t3, 0x30
    ctx->r11 = S32(0X30 << 16);
    // 0x8018FD24: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018FD28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018FD2C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FD30: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018FD34: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018FD38: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018FD3C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8018FD40: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018FD44: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018FD48: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FD4C: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x8018FD50: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x8018FD54: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018FD58: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018FD5C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018FD60: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x8018FD64: jal         0x80006D70
    // 0x8018FD68: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x8018FD68: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018FD6C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8018FD70: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8018FD74: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018FD78: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x8018FD7C: addiu       $t1, $t1, 0xB58
    ctx->r9 = ADD32(ctx->r9, 0XB58);
    // 0x8018FD80: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8018FD84: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FD88: lw          $t9, 0xBC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XBC);
    // 0x8018FD8C: lw          $t6, 0xC0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC0);
    // 0x8018FD90: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018FD94: andi        $t3, $t9, 0x3FF
    ctx->r11 = ctx->r25 & 0X3FF;
    // 0x8018FD98: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x8018FD9C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8018FDA0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8018FDA4: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8018FDA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018FDAC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8018FDB0: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8018FDB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018FDB8: lw          $t7, 0xB8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XB8);
    // 0x8018FDBC: lw          $t3, 0xB4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XB4);
    // 0x8018FDC0: andi        $t5, $t7, 0x3FF
    ctx->r13 = ctx->r15 & 0X3FF;
    // 0x8018FDC4: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x8018FDC8: sll         $t6, $t4, 14
    ctx->r14 = S32(ctx->r12 << 14);
    // 0x8018FDCC: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8018FDD0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8018FDD4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018FDD8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FDDC: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018FDE0: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x8018FDE4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8018FDE8: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8018FDEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018FDF0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018FDF4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FDF8: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x8018FDFC: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x8018FE00: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018FE04: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8018FE08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018FE0C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018FE10: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018FE14: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x8018FE18: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x8018FE1C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018FE20: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018FE24: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x8018FE28: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8018FE2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018FE30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018FE34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018FE38: jr          $ra
    // 0x8018FE3C: nop

    return;
    // 0x8018FE3C: nop

;}
RECOMP_FUNC void func_ovl8_80385640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80385644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385648: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038564C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80385650: jal         0x803717A0
    // 0x80385654: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385654: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80385658: beq         $v0, $zero, L_80385684
    if (ctx->r2 == 0) {
        // 0x8038565C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80385684;
    }
    // 0x8038565C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80385660: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80385664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8038566C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80385670: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80385674: jal         0x80385758
    // 0x80385678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_80385758(rdram, ctx);
        goto after_1;
    // 0x80385678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8038567C: b           L_80385688
    // 0x80385680: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80385688;
    // 0x80385680: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80385684:
    // 0x80385684: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80385688:
    // 0x80385688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8038568C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80385690: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80385694: jr          $ra
    // 0x80385698: nop

    return;
    // 0x80385698: nop

;}
RECOMP_FUNC void grWallpaperMakeCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104850: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80104854: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80104858: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x8010485C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80104860: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80104864: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x80104868: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8010486C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80104870: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80104874: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80104878: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8010487C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80104880: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x80104884: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80104888: addiu       $t1, $t1, 0x4830
    ctx->r9 = ADD32(ctx->r9, 0X4830);
    // 0x8010488C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80104890: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80104894: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80104898: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8010489C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801048A0: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x801048A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801048A8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x801048AC: jal         0x800CD050
    // 0x801048B0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x801048B0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_0:
    // 0x801048B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801048B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801048BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801048C0: lwc1        $f2, 0xA40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XA40);
    // 0x801048C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801048C8: sw          $v0, 0x13D8($at)
    MEM_W(0X13D8, ctx->r1) = ctx->r2;
    // 0x801048CC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801048D0: addiu       $t3, $zero, 0x200
    ctx->r11 = ADD32(0, 0X200);
    // 0x801048D4: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x801048D8: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x801048DC: sh          $t3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r11;
    // 0x801048E0: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x801048E4: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
    // 0x801048E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801048EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801048F0: jr          $ra
    // 0x801048F4: nop

    return;
    // 0x801048F4: nop

;}
RECOMP_FUNC void mvOpeningKirbyMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D324: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D328: lw          $t6, -0x1DD8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1DD8);
    // 0x8018D32C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D330: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D334: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D338: bne         $at, $zero, L_8018D414
    if (ctx->r1 != 0) {
        // 0x8018D33C: addiu       $v1, $v1, -0x1D98
        ctx->r3 = ADD32(ctx->r3, -0X1D98);
            goto L_8018D414;
    }
    // 0x8018D33C: addiu       $v1, $v1, -0x1D98
    ctx->r3 = ADD32(ctx->r3, -0X1D98);
    // 0x8018D340: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D344: addiu       $a0, $a0, -0x1DB8
    ctx->r4 = ADD32(ctx->r4, -0X1DB8);
    // 0x8018D348: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D34C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D350: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D354: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D358: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D35C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D360: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D364: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D368: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D36C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D370: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D374: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D378: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D37C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D380: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D384: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D388: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D38C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D390: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D394: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D398: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D39C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3A0: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D3A4: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3A8: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D3AC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D3B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3B4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3BC: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D3C0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3C4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3C8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3D0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3D4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3D8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3DC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3E0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3E4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3EC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3F4: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3F8: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3FC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D400: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D404: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D408: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D40C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D410: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D414:
    // 0x8018D414: jr          $ra
    // 0x8018D418: nop

    return;
    // 0x8018D418: nop

;}
RECOMP_FUNC void ftDonkeyThrowFWaitCheckInterruptThrowFWalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D4EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D4F4: jal         0x8013E258
    // 0x8014D4F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWaitCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8014D4F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014D4FC: beql        $v0, $zero, L_8014D518
    if (ctx->r2 == 0) {
        // 0x8014D500: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014D518;
    }
    goto skip_0;
    // 0x8014D500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014D504: jal         0x8014D49C
    // 0x8014D508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014D508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014D50C: b           L_8014D518
    // 0x8014D510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D518;
    // 0x8014D510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014D514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014D518:
    // 0x8014D518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D520: jr          $ra
    // 0x8014D524: nop

    return;
    // 0x8014D524: nop

;}
RECOMP_FUNC void mvOpeningClashFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013267C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80132680: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132684: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132688: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013268C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132690: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132694: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132698: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8013269C: addiu       $t8, $t8, 0x2A18
    ctx->r24 = ADD32(ctx->r24, 0X2A18);
    // 0x801326A0: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801326A4: addiu       $t0, $t0, 0x2D38
    ctx->r8 = ADD32(ctx->r8, 0X2D38);
    // 0x801326A8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801326AC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801326B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801326B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801326B8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801326BC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801326C0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801326C4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x801326C8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x801326CC: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x801326D0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801326D4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x801326D8: jal         0x800CDF78
    // 0x801326DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801326DC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x801326E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801326E4: addiu       $s0, $s0, 0x28D0
    ctx->r16 = ADD32(ctx->r16, 0X28D0);
    // 0x801326E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326EC: jal         0x800CDEEC
    // 0x801326F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801326F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x801326F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326F8: jal         0x80004980
    // 0x801326FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801326FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132700: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132704: addiu       $a2, $a2, 0x2D70
    ctx->r6 = ADD32(ctx->r6, 0X2D70);
    // 0x80132708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013270C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132710: jal         0x800CDE04
    // 0x80132714: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132714: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132718: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013271C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132720: addiu       $a1, $a1, 0x255C
    ctx->r5 = ADD32(ctx->r5, 0X255C);
    // 0x80132724: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013272C: jal         0x80009968
    // 0x80132730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80132734: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132738: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8013273C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132740: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80132744: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132748: jal         0x8000B9FC
    // 0x8013274C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013274C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80132750: jal         0x80115890
    // 0x80132754: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80132754: nop

    after_6:
    // 0x80132758: jal         0x80132550
    // 0x8013275C: nop

    mvOpeningClashInitTotalTimeTics(rdram, ctx);
        goto after_7;
    // 0x8013275C: nop

    after_7:
    // 0x80132760: jal         0x800FD300
    // 0x80132764: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80132764: nop

    after_8:
    // 0x80132768: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013276C: jal         0x800D7194
    // 0x80132770: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x80132770: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80132774: jal         0x800D786C
    // 0x80132778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80132778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8013277C: jal         0x800D786C
    // 0x80132780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x80132780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80132784: jal         0x800D786C
    // 0x80132788: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_12;
    // 0x80132788: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x8013278C: jal         0x800D786C
    // 0x80132790: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x80132790: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80132794: jal         0x800D786C
    // 0x80132798: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_14;
    // 0x80132798: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_14:
    // 0x8013279C: jal         0x800D786C
    // 0x801327A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_15;
    // 0x801327A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_15:
    // 0x801327A4: jal         0x800D786C
    // 0x801327A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_16;
    // 0x801327A8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_16:
    // 0x801327AC: jal         0x800D786C
    // 0x801327B0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_17;
    // 0x801327B0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_17:
    // 0x801327B4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801327B8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801327BC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801327C0: addiu       $s1, $s1, 0xD9C
    ctx->r17 = ADD32(ctx->r17, 0XD9C);
    // 0x801327C4: addiu       $s2, $s2, 0x29F8
    ctx->r18 = ADD32(ctx->r18, 0X29F8);
    // 0x801327C8: addiu       $s0, $s0, 0x29D8
    ctx->r16 = ADD32(ctx->r16, 0X29D8);
L_801327CC:
    // 0x801327CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801327D0: jal         0x80004980
    // 0x801327D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_18;
    // 0x801327D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_18:
    // 0x801327D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801327DC: bne         $s0, $s2, L_801327CC
    if (ctx->r16 != ctx->r18) {
        // 0x801327E0: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_801327CC;
    }
    // 0x801327E0: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x801327E4: jal         0x80132204
    // 0x801327E8: nop

    mvOpeningClashMakeFightersCamera(rdram, ctx);
        goto after_19;
    // 0x801327E8: nop

    after_19:
    // 0x801327EC: jal         0x80132314
    // 0x801327F0: nop

    mvOpeningClashMakeVoidCamera(rdram, ctx);
        goto after_20;
    // 0x801327F0: nop

    after_20:
    // 0x801327F4: jal         0x8013246C
    // 0x801327F8: nop

    mvOpeningClashMakeWallpaperCamera(rdram, ctx);
        goto after_21;
    // 0x801327F8: nop

    after_21:
    // 0x801327FC: jal         0x80131B60
    // 0x80132800: nop

    mvOpeningClashMakeFighters(rdram, ctx);
        goto after_22;
    // 0x80132800: nop

    after_22:
    // 0x80132804: jal         0x80131E5C
    // 0x80132808: nop

    mvOpeningClashMakeWallpaper(rdram, ctx);
        goto after_23;
    // 0x80132808: nop

    after_23:
    // 0x8013280C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132814: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132818: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013281C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132820: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80132824: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132828: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8013282C: jal         0x803904E0
    // 0x80132830: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_24;
    // 0x80132830: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_24:
    // 0x80132834: jal         0x8000092C
    // 0x80132838: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_25;
    // 0x80132838: nop

    after_25:
    // 0x8013283C: sltiu       $at, $v0, 0xF87
    ctx->r1 = ctx->r2 < 0XF87 ? 1 : 0;
    // 0x80132840: beql        $at, $zero, L_80132860
    if (ctx->r1 == 0) {
        // 0x80132844: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80132860;
    }
    goto skip_0;
    // 0x80132844: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80132848:
    // 0x80132848: jal         0x8000092C
    // 0x8013284C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_26;
    // 0x8013284C: nop

    after_26:
    // 0x80132850: sltiu       $at, $v0, 0xF87
    ctx->r1 = ctx->r2 < 0XF87 ? 1 : 0;
    // 0x80132854: bne         $at, $zero, L_80132848
    if (ctx->r1 != 0) {
        // 0x80132858: nop
    
            goto L_80132848;
    }
    // 0x80132858: nop

    // 0x8013285C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80132860:
    // 0x80132860: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132864: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80132868: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8013286C: jr          $ra
    // 0x80132870: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80132870: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftCommonCliffQuickOrSlowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144FE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80144FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144FF0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80144FF4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144FF8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x80144FFC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80145000: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80145004: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014500C: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x80145010: beq         $at, $zero, L_80145024
    if (ctx->r1 == 0) {
        // 0x80145014: nop
    
            goto L_80145024;
    }
    // 0x80145014: nop

    // 0x80145018: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x8014501C: b           L_80145024
    // 0x80145020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80145024;
    // 0x80145020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80145024:
    // 0x80145024: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80145028: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8014502C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80145030: jal         0x800E6F24
    // 0x80145034: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145034: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80145038: jal         0x800E0830
    // 0x8014503C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014503C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80145040: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80145044: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80145048: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8014504C: lbu         $t1, 0x190($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X190);
    // 0x80145050: lw          $t9, 0x140($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X140);
    // 0x80145054: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80145058: addiu       $t3, $t3, 0x4CF8
    ctx->r11 = ADD32(ctx->r11, 0X4CF8);
    // 0x8014505C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80145060: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80145064: sw          $t8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r24;
    // 0x80145068: sb          $t2, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r10;
    // 0x8014506C: sw          $t3, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r11;
    // 0x80145070: sw          $t9, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r25;
    // 0x80145074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145078: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014507C: jr          $ra
    // 0x80145080: nop

    return;
    // 0x80145080: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwHitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801525C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801525CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801525D0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801525D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801525D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801525DC: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x801525E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801525E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801525E8: jal         0x800E6F24
    // 0x801525EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801525EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801525F0: jal         0x800E0830
    // 0x801525F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801525F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801525F8: jal         0x80152578
    // 0x801525FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftPikachuSpecialLwHitInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801525FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80152600: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80152604: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80152608: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8015260C: swc1        $f4, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->f4.u32l;
    // 0x80152610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152618: jr          $ra
    // 0x8015261C: nop

    return;
    // 0x8015261C: nop

;}
RECOMP_FUNC void mnVSRecordInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D10: sw          $zero, 0x6C18($at)
    MEM_W(0X6C18, ctx->r1) = 0;
    // 0x80135D14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D18: sw          $zero, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = 0;
    // 0x80135D1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D20: sw          $zero, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = 0;
    // 0x80135D24: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80135D28: lhu         $t6, 0x4938($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4938);
    // 0x80135D2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D30: sw          $zero, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = 0;
    // 0x80135D34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D38: sh          $t6, 0x6CBC($at)
    MEM_H(0X6CBC, ctx->r1) = ctx->r14;
    // 0x80135D3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135D40: jr          $ra
    // 0x80135D44: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    return;
    // 0x80135D44: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
;}
RECOMP_FUNC void alSeqpGetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6C0: lh          $t6, 0x3A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3A);
    // 0x8002F6C4: lbu         $t7, 0x78($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X78);
    // 0x8002F6C8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002F6CC: mflo        $v0
    ctx->r2 = lo;
    // 0x8002F6D0: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8002F6D4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002F6D8: jr          $ra
    // 0x8002F6DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8002F6DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void itSwordWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174B94: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80174B98: jal         0x801735A0
    // 0x80174B9C: addiu       $a1, $a1, 0x4C18
    ctx->r5 = ADD32(ctx->r5, 0X4C18);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80174B9C: addiu       $a1, $a1, 0x4C18
    ctx->r5 = ADD32(ctx->r5, 0X4C18);
    after_0:
    // 0x80174BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174BAC: jr          $ra
    // 0x80174BB0: nop

    return;
    // 0x80174BB0: nop

;}
RECOMP_FUNC void scAutoDemoInitSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB18: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018DB1C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8018DB20: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018DB24: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8018DB28: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8018DB2C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8018DB30: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8018DB34: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8018DB38: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8018DB3C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8018DB40: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8018DB44: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8018DB48: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8018DB4C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8018DB50: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018DB54: jal         0x800CDBD0
    // 0x8018DB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018DB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018DB5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DB60: jal         0x80004980
    // 0x8018DB64: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018DB64: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018DB68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB6C: jal         0x800CDC88
    // 0x8018DB70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018DB70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018DB74: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018DB78: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8018DB7C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018DB80: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DB84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DB88: jal         0x80009968
    // 0x8018DB8C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8018DB8C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
    // 0x8018DB90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DB94: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018DB98: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DB9C: sw          $v0, -0x1B18($at)
    MEM_W(-0X1B18, ctx->r1) = ctx->r2;
    // 0x8018DBA0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8018DBA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBA8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018DBAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DBB0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018DBB4: jal         0x80009DF4
    // 0x8018DBB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8018DBB8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8018DBBC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018DBC0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018DBC4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8018DBC8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018DBCC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018DBD0: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018DBD4: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8018DBD8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018DBDC: addiu       $s4, $s4, -0x1E00
    ctx->r20 = ADD32(ctx->r20, -0X1E00);
    // 0x8018DBE0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018DBE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DBE8: addiu       $s7, $zero, 0xE8
    ctx->r23 = ADD32(0, 0XE8);
    // 0x8018DBEC: addiu       $s6, $zero, 0x205
    ctx->r22 = ADD32(0, 0X205);
    // 0x8018DBF0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_8018DBF4:
    // 0x8018DBF4: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8018DBF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018DBFC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8018DC00: lbu         $t9, 0x23($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X23);
    // 0x8018DC04: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018DC08: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8018DC0C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8018DC10: jal         0x800CCFDC
    // 0x8018DC14: addu        $a1, $t2, $s2
    ctx->r5 = ADD32(ctx->r10, ctx->r18);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8018DC14: addu        $a1, $t2, $s2
    ctx->r5 = ADD32(ctx->r10, ctx->r18);
    after_5:
    // 0x8018DC18: lh          $t3, 0x14($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X14);
    // 0x8018DC1C: lh          $t6, 0x16($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X16);
    // 0x8018DC20: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x8018DC24: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8018DC28: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x8018DC2C: sb          $s1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r17;
    // 0x8018DC30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DC34: sb          $s1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r17;
    // 0x8018DC38: sh          $s6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r22;
    // 0x8018DC3C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8018DC40: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8018DC44: sub.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x8018DC48: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018DC4C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018DC50: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018DC54: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8018DC58: nop

    // 0x8018DC5C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8018DC60: sub.s       $f16, $f24, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x8018DC64: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018DC68: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018DC6C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018DC70: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8018DC74: nop

    // 0x8018DC78: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018DC7C: nop

    // 0x8018DC80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DC84: bne         $s0, $s7, L_8018DBF4
    if (ctx->r16 != ctx->r23) {
        // 0x8018DC88: swc1        $f6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
            goto L_8018DBF4;
    }
    // 0x8018DC88: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8018DC8C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8018DC90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018DC94: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8018DC98: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8018DC9C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8018DCA0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8018DCA4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DCA8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCAC: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCB0: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8018DCB4: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8018DCB8: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8018DCBC: jr          $ra
    // 0x8018DCC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8018DCC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80028C88: beql        $v0, $zero, L_80028C9C
    if (ctx->r2 == 0) {
        // 0x80028C8C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_80028C9C;
    }
    goto skip_0;
    // 0x80028C8C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x80028C90: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80028C94: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80028C98: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_80028C9C:
    // 0x80028C9C: beq         $v0, $zero, L_80028CAC
    if (ctx->r2 == 0) {
        // 0x80028CA0: nop
    
            goto L_80028CAC;
    }
    // 0x80028CA0: nop

    // 0x80028CA4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80028CA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80028CAC:
    // 0x80028CAC: jr          $ra
    // 0x80028CB0: nop

    return;
    // 0x80028CB0: nop

;}
RECOMP_FUNC void gcInitGObjCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800098A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800098AC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800098B0: slti        $at, $a2, 0x21
    ctx->r1 = SIGNED(ctx->r6) < 0X21 ? 1 : 0;
    // 0x800098B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800098B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800098BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800098C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800098C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800098C8: bne         $at, $zero, L_800098EC
    if (ctx->r1 != 0) {
        // 0x800098CC: or          $t6, $a2, $zero
        ctx->r14 = ctx->r6 | 0;
            goto L_800098EC;
    }
    // 0x800098CC: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x800098D0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800098D4: addiu       $a0, $a0, -0x250C
    ctx->r4 = ADD32(ctx->r4, -0X250C);
    // 0x800098D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800098DC: jal         0x80023624
    // 0x800098E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800098E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_0:
L_800098E4:
    // 0x800098E4: b           L_800098E4
    pause_self(rdram);
    // 0x800098E8: nop

L_800098EC:
    // 0x800098EC: jal         0x800078FC
    // 0x800098F0: sb          $a2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r6;
    gcGetGObjSetNextAlloc(rdram, ctx);
        goto after_1;
    // 0x800098F0: sb          $a2, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r6;
    after_1:
    // 0x800098F4: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    // 0x800098F8: bne         $v0, $zero, L_80009908
    if (ctx->r2 != 0) {
        // 0x800098FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80009908;
    }
    // 0x800098FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80009900: b           L_80009958
    // 0x80009904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009958;
    // 0x80009904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009908:
    // 0x80009908: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000990C: sb          $a2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r6;
    // 0x80009910: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009914: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80009918: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000991C: addiu       $t0, $zero, 0x41
    ctx->r8 = ADD32(0, 0X41);
    // 0x80009920: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009924: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x80009928: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000992C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80009930: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x80009934: sw          $zero, 0x70($v1)
    MEM_W(0X70, ctx->r3) = 0;
    // 0x80009938: sw          $zero, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = 0;
    // 0x8000993C: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x80009940: sw          $zero, 0x74($v1)
    MEM_W(0X74, ctx->r3) = 0;
    // 0x80009944: sb          $t0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r8;
    // 0x80009948: sw          $zero, 0x80($v1)
    MEM_W(0X80, ctx->r3) = 0;
    // 0x8000994C: sw          $zero, 0x84($v1)
    MEM_W(0X84, ctx->r3) = 0;
    // 0x80009950: swc1        $f4, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f4.u32l;
    // 0x80009954: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
L_80009958:
    // 0x80009958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000995C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009960: jr          $ra
    // 0x80009964: nop

    return;
    // 0x80009964: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeFighterRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134B44: jal         0x8013476C
    // 0x80134B48: nop

    mnPlayers1PGameMakeHiScore(rdram, ctx);
        goto after_0;
    // 0x80134B48: nop

    after_0:
    // 0x80134B4C: jal         0x8013497C
    // 0x80134B50: nop

    mnPlayers1PGameMakeBonusCount(rdram, ctx);
        goto after_1;
    // 0x80134B50: nop

    after_1:
    // 0x80134B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134B5C: jr          $ra
    // 0x80134B60: nop

    return;
    // 0x80134B60: nop

;}
RECOMP_FUNC void func_ovl7_8018F804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F804: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018F808: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018F80C: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8018F810: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    // 0x8018F814: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8018F818: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018F81C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8018F820: sh          $a1, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r5;
    // 0x8018F824: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x8018F828: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8018F82C: sh          $a1, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r5;
    // 0x8018F830: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8018F834: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x8018F838: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018F83C: sh          $a1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r5;
    // 0x8018F840: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8018F844: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8018F848: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8018F84C: sh          $a1, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r5;
    // 0x8018F850: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8018F854: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8018F858: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018F85C: sh          $a1, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r5;
    // 0x8018F860: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x8018F864: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8018F868: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x8018F86C: jr          $ra
    // 0x8018F870: sh          $a1, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r5;
    return;
    // 0x8018F870: sh          $a1, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r5;
;}
RECOMP_FUNC void ftFoxSpecialLwTurnCheckInterruptLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D0CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D0D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D0D4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015D0D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015D0DC: jal         0x8013E9D0
    // 0x8015D0E0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8015D0E0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015D0E4: beq         $v0, $zero, L_8015D11C
    if (ctx->r2 == 0) {
        // 0x8015D0E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8015D11C;
    }
    // 0x8015D0E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015D0EC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D0F0: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x8015D0F4: bne         $t8, $zero, L_8015D10C
    if (ctx->r24 != 0) {
        // 0x8015D0F8: nop
    
            goto L_8015D10C;
    }
    // 0x8015D0F8: nop

    // 0x8015D0FC: jal         0x8015D054
    // 0x8015D100: nop

    ftFoxSpecialLwTurnSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D100: nop

    after_1:
    // 0x8015D104: b           L_8015D120
    // 0x8015D108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015D120;
    // 0x8015D108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015D10C:
    // 0x8015D10C: jal         0x8015D090
    // 0x8015D110: nop

    ftFox_SpecialAirLwTurn_SetStatus(rdram, ctx);
        goto after_2;
    // 0x8015D110: nop

    after_2:
    // 0x8015D114: b           L_8015D120
    // 0x8015D118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015D120;
    // 0x8015D118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015D11C:
    // 0x8015D11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015D120:
    // 0x8015D120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D128: jr          $ra
    // 0x8015D12C: nop

    return;
    // 0x8015D12C: nop

;}
RECOMP_FUNC void mvOpeningLinkInitName(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void __n_vsDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DF24: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8002DF28: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x8002DF2C: subu        $v1, $t6, $a1
    ctx->r3 = SUB32(ctx->r14, ctx->r5);
    // 0x8002DF30: bltz        $v1, L_8002DF40
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002DF34: nop
    
            goto L_8002DF40;
    }
    // 0x8002DF34: nop

    // 0x8002DF38: jr          $ra
    // 0x8002DF3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002DF3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002DF40:
    // 0x8002DF40: jr          $ra
    // 0x8002DF44: nop

    return;
    // 0x8002DF44: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueGameOverProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133210: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80133214: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133218: addiu       $a0, $a0, 0x4340
    ctx->r4 = ADD32(ctx->r4, 0X4340);
    // 0x8013321C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133220: lwc1        $f2, 0x42E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X42E8);
    // 0x80133224: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133228: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013322C: lw          $t6, 0x4318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4318);
    // 0x80133230: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80133234: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80133238: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8013323C: bc1f        L_80133360
    if (!c1cs) {
        // 0x80133240: nop
    
            goto L_80133360;
    }
    // 0x80133240: nop

    // 0x80133244: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80133248: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8013324C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133250: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80133254: nop

    // 0x80133258: bc1fl       L_8013326C
    if (!c1cs) {
        // 0x8013325C: swc1        $f0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
            goto L_8013326C;
    }
    goto skip_0;
    // 0x8013325C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x80133260: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x80133264: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133268: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
L_8013326C:
    // 0x8013326C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133270: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80133274: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x80133278: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8013327C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133280: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133284: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80133288: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013328C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80133290: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x80133294: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133298: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8013329C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801332A0: addiu       $a1, $a1, 0x4300
    ctx->r5 = ADD32(ctx->r5, 0X4300);
    // 0x801332A4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801332A8: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801332AC: addiu       $a3, $a3, 0x4348
    ctx->r7 = ADD32(ctx->r7, 0X4348);
    // 0x801332B0: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x801332B4: addiu       $a2, $a2, 0xD90
    ctx->r6 = ADD32(ctx->r6, 0XD90);
    // 0x801332B8: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801332BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801332C0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801332C4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801332C8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801332CC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801332D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801332D4: div.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x801332D8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801332DC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801332E0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x801332E4: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x801332E8: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801332EC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801332F0: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x801332F4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x801332F8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801332FC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80133300: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80133304: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80133308: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8013330C: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80133310: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80133314: swc1        $f6, 0x40($t2)
    MEM_W(0X40, ctx->r10) = ctx->f6.u32l;
    // 0x80133318: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8013331C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133320: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80133324: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80133328: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8013332C: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80133330: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80133334: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80133338: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
    // 0x8013333C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80133340: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133344: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80133348: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8013334C: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80133350: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80133354: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80133358: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8013335C: swc1        $f6, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f6.u32l;
L_80133360:
    // 0x80133360: jr          $ra
    // 0x80133364: nop

    return;
    // 0x80133364: nop

;}
RECOMP_FUNC void lbRelocGetForceExternHeapFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDDD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CDDE0: sw          $a1, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r5;
    // 0x800CDDE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CDDE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDDEC: jal         0x800CDD5C
    // 0x800CDDF0: sw          $zero, 0x6304($at)
    MEM_W(0X6304, ctx->r1) = 0;
    lbRelocGetForceExternBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDDF0: sw          $zero, 0x6304($at)
    MEM_W(0X6304, ctx->r1) = 0;
    after_0:
    // 0x800CDDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CDDF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CDDFC: jr          $ra
    // 0x800CDE00: nop

    return;
    // 0x800CDE00: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153654: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015365C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153660: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153664: jal         0x801535C4
    // 0x80153668: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftPikachuSpecialHiEndBackupVel(rdram, ctx);
        goto after_0;
    // 0x80153668: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015366C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80153670: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153674: lwc1        $f0, -0x3A78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3A78);
    // 0x80153678: lwc1        $f4, 0xB30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB30);
    // 0x8015367C: lwc1        $f8, 0xB34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB34);
    // 0x80153680: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x80153684: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80153688: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015368C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80153690: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80153694: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80153698: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    // 0x8015369C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801536A0: jal         0x800E6F24
    // 0x801536A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801536A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801536A8: jal         0x800E0830
    // 0x801536AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801536AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801536B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801536B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801536B8: jr          $ra
    // 0x801536BC: nop

    return;
    // 0x801536BC: nop

;}
RECOMP_FUNC void func_ovl59_80131F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131F3C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80131F40: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80131F44: lwc1        $f6, -0x5744($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5744);
    // 0x80131F48: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x80131F4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131F50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131F54: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80131F58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131F5C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131F60: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80131F64: nop

    // 0x80131F68: bc1fl       L_80131F9C
    if (!c1cs) {
        // 0x80131F6C: lw          $t6, 0x74($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X74);
            goto L_80131F9C;
    }
    goto skip_0;
    // 0x80131F6C: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    skip_0:
    // 0x80131F70: jal         0x80009A84
    // 0x80131F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80131F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80131F78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80131F7C: jal         0x80009A84
    // 0x80131F80: lw          $a0, -0x5708($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5708);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80131F80: lw          $a0, -0x5708($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5708);
    after_1:
    // 0x80131F84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80131F88: jal         0x80009A84
    // 0x80131F8C: lw          $a0, -0x5704($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5704);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80131F8C: lw          $a0, -0x5704($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5704);
    after_2:
    // 0x80131F90: b           L_80132020
    // 0x80131F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132020;
    // 0x80131F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131F98: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
L_80131F9C:
    // 0x80131F9C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131FA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80131FA4: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x80131FA8: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x80131FAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131FB0: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x80131FB4: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80131FB8: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x80131FBC: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x80131FC0: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x80131FC4: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x80131FC8: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80131FCC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x80131FD0: sw          $t2, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r10;
    // 0x80131FD4: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x80131FD8: sw          $t1, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r9;
    // 0x80131FDC: lw          $t2, 0x38($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X38);
    // 0x80131FE0: sw          $t2, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r10;
    // 0x80131FE4: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80131FE8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80131FEC: nop

    // 0x80131FF0: bc1fl       L_80132004
    if (!c1cs) {
        // 0x80131FF4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80132004;
    }
    goto skip_1;
    // 0x80131FF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x80131FF8: b           L_80132004
    // 0x80131FFC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80132004;
    // 0x80131FFC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80132000: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80132004:
    // 0x80132004: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80132008: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8013200C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132010: nop

    // 0x80132014: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132018: swc1        $f8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f8.u32l;
    // 0x8013201C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132020:
    // 0x80132020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132024: jr          $ra
    // 0x80132028: nop

    return;
    // 0x80132028: nop

;}
RECOMP_FUNC void itNessPKFireCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801856BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801856C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801856C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801856C8: lw          $v1, 0x2C0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C0);
    // 0x801856CC: blez        $v1, L_801856E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801856D0: nop
    
            goto L_801856E8;
    }
    // 0x801856D0: nop

    // 0x801856D4: lw          $t6, 0x290($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X290);
    // 0x801856D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801856DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801856E0: subu        $t8, $v1, $t7
    ctx->r24 = SUB32(ctx->r3, ctx->r15);
    // 0x801856E4: sw          $t8, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r24;
L_801856E8:
    // 0x801856E8: jal         0x80185374
    // 0x801856EC: nop

    itNessPKFireCommonUpdateAllCheckDestroy(rdram, ctx);
        goto after_0;
    // 0x801856EC: nop

    after_0:
    // 0x801856F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801856F4: bne         $v0, $at, L_80185704
    if (ctx->r2 != ctx->r1) {
        // 0x801856F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80185704;
    }
    // 0x801856F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801856FC: b           L_80185708
    // 0x80185700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80185708;
    // 0x80185700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80185704:
    // 0x80185704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80185708:
    // 0x80185708: jr          $ra
    // 0x8018570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8018570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itStarmieCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018221C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182224: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182228: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8018222C: bnel        $a1, $zero, L_80182258
    if (ctx->r5 != 0) {
        // 0x80182230: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80182258;
    }
    goto skip_0;
    // 0x80182230: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80182234: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80182238: nop

    // 0x8018223C: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80182240: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80182244: jal         0x801821E8
    // 0x80182248: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itStarmieNFollowSetStatus(rdram, ctx);
        goto after_0;
    // 0x80182248: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018224C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80182250: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182254: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_80182258:
    // 0x80182258: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8018225C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182268: jr          $ra
    // 0x8018226C: nop

    return;
    // 0x8018226C: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeStatDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DEDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DEE4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8018DEE8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x8018DEEC: jal         0x800CCFDC
    // 0x8018DEF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8018DEF0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8018DEF4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DEF8: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8018DEFC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8018DF00: nop

    // 0x8018DF04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DF08: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018DF0C: lh          $t7, 0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2);
    // 0x8018DF10: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8018DF14: nop

    // 0x8018DF18: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DF1C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8018DF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DF28: jr          $ra
    // 0x8018DF2C: nop

    return;
    // 0x8018DF2C: nop

;}
RECOMP_FUNC void ftCommonKneeBendCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F4D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F4D8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013F4DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013F4E0: jal         0x800F3794
    // 0x8013F4E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x8013F4E4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013F4E8: beq         $v0, $zero, L_8013F500
    if (ctx->r2 == 0) {
        // 0x8013F4EC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8013F500;
    }
    // 0x8013F4EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8013F4F0: jal         0x8014800C
    // 0x8013F4F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonHammerKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013F4F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8013F4F8: b           L_8013F530
    // 0x8013F4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013F530;
    // 0x8013F4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F500:
    // 0x8013F500: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F504: jal         0x8013F474
    // 0x8013F508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_2;
    // 0x8013F508: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8013F50C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8013F510: beq         $v0, $zero, L_8013F528
    if (ctx->r2 == 0) {
        // 0x8013F514: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8013F528;
    }
    // 0x8013F514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013F518: jal         0x8013F408
    // 0x8013F51C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonKneeBendSetStatus(rdram, ctx);
        goto after_3;
    // 0x8013F51C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8013F520: b           L_8013F52C
    // 0x8013F524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F52C;
    // 0x8013F524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F528:
    // 0x8013F528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F52C:
    // 0x8013F52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F530:
    // 0x8013F530: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F534: jr          $ra
    // 0x8013F538: nop

    return;
    // 0x8013F538: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160A80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160A88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80160A8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80160A90: jal         0x800DEEC8
    // 0x80160A94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80160A94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160A98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80160A9C: addiu       $t7, $zero, 0x4006
    ctx->r15 = ADD32(0, 0X4006);
    // 0x80160AA0: addiu       $a1, $zero, 0x128
    ctx->r5 = ADD32(0, 0X128);
    // 0x80160AA4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80160AA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80160AAC: jal         0x800E6F24
    // 0x80160AB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80160AB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80160AB4: jal         0x800D8EB8
    // 0x80160AB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80160AB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80160ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160AC4: jr          $ra
    // 0x80160AC8: nop

    return;
    // 0x80160AC8: nop

;}

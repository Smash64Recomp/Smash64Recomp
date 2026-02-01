#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itKamexAppearProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018090C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80180910: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80180914: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80180918: jal         0x801737B8
    // 0x8018091C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8018091C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80180920: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80180924: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x80180928: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8018092C: beql        $t7, $zero, L_80180954
    if (ctx->r15 == 0) {
        // 0x80180930: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80180954;
    }
    goto skip_0;
    // 0x80180930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80180934: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80180938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018093C: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x80180940: jal         0x80180A58
    // 0x80180944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itKamexAttackInitVars(rdram, ctx);
        goto after_1;
    // 0x80180944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80180948: jal         0x80180AF4
    // 0x8018094C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itKamexAttackSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018094C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80180950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80180954:
    // 0x80180954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018095C: jr          $ra
    // 0x80180960: nop

    return;
    // 0x80180960: nop

;}
RECOMP_FUNC void ftMainSearchHitWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4ED4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800E4ED8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800E4EDC: lw          $t7, 0x6704($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6704);
    // 0x800E4EE0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E4EE4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800E4EE8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800E4EEC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E4EF0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E4EF4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E4EF8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E4EFC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E4F00: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E4F04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E4F08: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800E4F0C: lw          $s7, 0x84($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X84);
    // 0x800E4F10: beq         $t7, $zero, L_800E55AC
    if (ctx->r15 == 0) {
        // 0x800E4F14: sw          $t7, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r15;
            goto L_800E55AC;
    }
    // 0x800E4F14: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
L_800E4F18:
    // 0x800E4F18: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x800E4F1C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800E4F20: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800E4F24: lw          $fp, 0x84($t8)
    ctx->r30 = MEM_W(ctx->r24, 0X84);
    // 0x800E4F28: addiu       $s6, $fp, 0x100
    ctx->r22 = ADD32(ctx->r30, 0X100);
    // 0x800E4F2C: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x800E4F30: lw          $t1, 0x8($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X8);
    // 0x800E4F34: beql        $t9, $t1, L_800E55A0
    if (ctx->r25 == ctx->r9) {
        // 0x800E4F38: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_0;
    // 0x800E4F38: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_0:
    // 0x800E4F3C: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x800E4F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E4F44: lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2);
    // 0x800E4F48: bnel        $t2, $at, L_800E4F70
    if (ctx->r10 != ctx->r1) {
        // 0x800E4F4C: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_800E4F70;
    }
    goto skip_1;
    // 0x800E4F4C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800E4F50: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x800E4F54: bnel        $t3, $zero, L_800E4F70
    if (ctx->r11 != 0) {
        // 0x800E4F58: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_800E4F70;
    }
    goto skip_2;
    // 0x800E4F58: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_2:
    // 0x800E4F5C: lbu         $t4, 0x10($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X10);
    // 0x800E4F60: lbu         $t5, 0xC($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0XC);
    // 0x800E4F64: beql        $t4, $t5, L_800E55A0
    if (ctx->r12 == ctx->r13) {
        // 0x800E4F68: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_3;
    // 0x800E4F68: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_3:
    // 0x800E4F6C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
L_800E4F70:
    // 0x800E4F70: beql        $t6, $zero, L_800E55A0
    if (ctx->r14 == 0) {
        // 0x800E4F74: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_4;
    // 0x800E4F74: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_4:
    // 0x800E4F78: lbu         $t7, 0x44($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X44);
    // 0x800E4F7C: lbu         $t9, 0x94($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X94);
    // 0x800E4F80: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800E4F84: beq         $t8, $zero, L_800E559C
    if (ctx->r24 == 0) {
        // 0x800E4F88: andi        $t7, $t9, 0xFFEF
        ctx->r15 = ctx->r25 & 0XFFEF;
            goto L_800E559C;
    }
    // 0x800E4F88: andi        $t7, $t9, 0xFFEF
    ctx->r15 = ctx->r25 & 0XFFEF;
    // 0x800E4F8C: sb          $t7, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r15;
    // 0x800E4F90: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800E4F94: andi        $t8, $t7, 0xDF
    ctx->r24 = ctx->r15 & 0XDF;
    // 0x800E4F98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E4F9C: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800E4FA0: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800E4FA4: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800E4FA8: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x800E4FAC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800E4FB0: sb          $t7, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r15;
    // 0x800E4FB4: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800E4FB8: andi        $t6, $t7, 0xBF
    ctx->r14 = ctx->r15 & 0XBF;
    // 0x800E4FBC: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x800E4FC0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E4FC4: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800E4FC8: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800E4FCC: andi        $t1, $t5, 0x40
    ctx->r9 = ctx->r13 & 0X40;
    // 0x800E4FD0: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x800E4FD4: sb          $t7, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r15;
    // 0x800E4FD8: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800E4FDC: andi        $t1, $t7, 0x7F
    ctx->r9 = ctx->r15 & 0X7F;
    // 0x800E4FE0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800E4FE4: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800E4FE8: sll         $t9, $t4, 7
    ctx->r25 = S32(ctx->r12 << 7);
    // 0x800E4FEC: or          $t3, $t9, $t1
    ctx->r11 = ctx->r25 | ctx->r9;
    // 0x800E4FF0: sb          $t3, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r11;
    // 0x800E4FF4: ori         $t4, $t3, 0xE
    ctx->r12 = ctx->r11 | 0XE;
    // 0x800E4FF8: sb          $t4, 0x94($sp)
    MEM_B(0X94, ctx->r29) = ctx->r12;
L_800E4FFC:
    // 0x800E4FFC: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5000: lw          $t8, 0x114($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X114);
    // 0x800E5004: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E5008: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800E500C: bne         $t5, $t8, L_800E5024
    if (ctx->r13 != ctx->r24) {
        // 0x800E5010: nop
    
            goto L_800E5024;
    }
    // 0x800E5010: nop

    // 0x800E5014: lw          $t1, 0x118($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X118);
    // 0x800E5018: addiu       $t7, $sp, 0x94
    ctx->r15 = ADD32(ctx->r29, 0X94);
    // 0x800E501C: b           L_800E502C
    // 0x800E5020: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
        goto L_800E502C;
    // 0x800E5020: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
L_800E5024:
    // 0x800E5024: bne         $v1, $at, L_800E4FFC
    if (ctx->r3 != ctx->r1) {
        // 0x800E5028: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E4FFC;
    }
    // 0x800E5028: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E502C:
    // 0x800E502C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800E5030: srl         $t2, $t6, 31
    ctx->r10 = S32(U32(ctx->r14) >> 31);
    // 0x800E5034: bne         $t2, $zero, L_800E559C
    if (ctx->r10 != 0) {
        // 0x800E5038: sll         $t4, $t6, 1
        ctx->r12 = S32(ctx->r14 << 1);
            goto L_800E559C;
    }
    // 0x800E5038: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800E503C: bltz        $t4, L_800E559C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800E5040: sll         $t8, $t6, 2
        ctx->r24 = S32(ctx->r14 << 2);
            goto L_800E559C;
    }
    // 0x800E5040: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800E5044: bltz        $t8, L_800E559C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E5048: sll         $t9, $t6, 3
        ctx->r25 = S32(ctx->r14 << 3);
            goto L_800E559C;
    }
    // 0x800E5048: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x800E504C: bltz        $t9, L_800E559C
    if (SIGNED(ctx->r25) < 0) {
        // 0x800E5050: sll         $t1, $t6, 4
        ctx->r9 = S32(ctx->r14 << 4);
            goto L_800E559C;
    }
    // 0x800E5050: sll         $t1, $t6, 4
    ctx->r9 = S32(ctx->r14 << 4);
    // 0x800E5054: srl         $t2, $t1, 29
    ctx->r10 = S32(U32(ctx->r9) >> 29);
    // 0x800E5058: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E505C: bnel        $t2, $at, L_800E55A0
    if (ctx->r10 != ctx->r1) {
        // 0x800E5060: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_5;
    // 0x800E5060: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_5:
    // 0x800E5064: lw          $v1, 0x48($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X48);
    // 0x800E5068: srl         $t3, $v1, 31
    ctx->r11 = S32(U32(ctx->r3) >> 31);
    // 0x800E506C: beql        $t3, $zero, L_800E526C
    if (ctx->r11 == 0) {
        // 0x800E5070: lw          $t5, 0x50($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X50);
            goto L_800E526C;
    }
    goto skip_6;
    // 0x800E5070: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    skip_6:
    // 0x800E5074: lw          $t4, 0x190($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X190);
    // 0x800E5078: sll         $t8, $t4, 18
    ctx->r24 = S32(ctx->r12 << 18);
    // 0x800E507C: bltzl       $t8, L_800E526C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E5080: lw          $t5, 0x50($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X50);
            goto L_800E526C;
    }
    goto skip_7;
    // 0x800E5080: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    skip_7:
    // 0x800E5084: lw          $v0, 0x278($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X278);
    // 0x800E5088: beql        $v0, $zero, L_800E50CC
    if (ctx->r2 == 0) {
        // 0x800E508C: lw          $t3, 0x18C($s7)
        ctx->r11 = MEM_W(ctx->r23, 0X18C);
            goto L_800E50CC;
    }
    goto skip_8;
    // 0x800E508C: lw          $t3, 0x18C($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X18C);
    skip_8:
    // 0x800E5090: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x800E5094: beql        $t7, $v0, L_800E526C
    if (ctx->r15 == ctx->r2) {
        // 0x800E5098: lw          $t5, 0x50($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X50);
            goto L_800E526C;
    }
    goto skip_9;
    // 0x800E5098: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    skip_9:
    // 0x800E509C: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800E50A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E50A4: bnel        $t9, $at, L_800E50CC
    if (ctx->r25 != ctx->r1) {
        // 0x800E50A8: lw          $t3, 0x18C($s7)
        ctx->r11 = MEM_W(ctx->r23, 0X18C);
            goto L_800E50CC;
    }
    goto skip_10;
    // 0x800E50A8: lw          $t3, 0x18C($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X18C);
    skip_10:
    // 0x800E50AC: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x800E50B0: bnel        $t6, $zero, L_800E50CC
    if (ctx->r14 != 0) {
        // 0x800E50B4: lw          $t3, 0x18C($s7)
        ctx->r11 = MEM_W(ctx->r23, 0X18C);
            goto L_800E50CC;
    }
    goto skip_11;
    // 0x800E50B4: lw          $t3, 0x18C($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X18C);
    skip_11:
    // 0x800E50B8: lbu         $t1, 0x10($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X10);
    // 0x800E50BC: lbu         $t2, 0x280($s7)
    ctx->r10 = MEM_BU(ctx->r23, 0X280);
    // 0x800E50C0: beql        $t1, $t2, L_800E526C
    if (ctx->r9 == ctx->r10) {
        // 0x800E50C4: lw          $t5, 0x50($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X50);
            goto L_800E526C;
    }
    goto skip_12;
    // 0x800E50C4: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    skip_12:
    // 0x800E50C8: lw          $t3, 0x18C($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X18C);
L_800E50CC:
    // 0x800E50CC: sll         $t7, $v1, 5
    ctx->r15 = S32(ctx->r3 << 5);
    // 0x800E50D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E50D4: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x800E50D8: bgez        $t5, L_800E50E4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800E50DC: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_800E50E4;
    }
    // 0x800E50DC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800E50E0: bltz        $t7, L_800E5268
    if (SIGNED(ctx->r15) < 0) {
        // 0x800E50E4: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800E5268;
    }
L_800E50E4:
    // 0x800E50E4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E50E8: addiu       $a2, $a2, 0x11B0
    ctx->r6 = ADD32(ctx->r6, 0X11B0);
L_800E50EC:
    // 0x800E50EC: lw          $t9, 0x294($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X294);
    // 0x800E50F0: beql        $t9, $zero, L_800E51A0
    if (ctx->r25 == 0) {
        // 0x800E50F4: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E51A0;
    }
    goto skip_13;
    // 0x800E50F4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_13:
    // 0x800E50F8: lw          $v0, 0xFC($fp)
    ctx->r2 = MEM_W(ctx->r30, 0XFC);
    // 0x800E50FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E5100: addiu       $a0, $a1, 0x294
    ctx->r4 = ADD32(ctx->r5, 0X294);
    // 0x800E5104: bne         $v0, $at, L_800E511C
    if (ctx->r2 != ctx->r1) {
        // 0x800E5108: nop
    
            goto L_800E511C;
    }
    // 0x800E5108: nop

    // 0x800E510C: lbu         $t6, 0x3C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3C);
    // 0x800E5110: andi        $t1, $t6, 0x1
    ctx->r9 = ctx->r14 & 0X1;
    // 0x800E5114: bnel        $t1, $zero, L_800E5134
    if (ctx->r9 != 0) {
        // 0x800E5118: lbu         $t5, 0x98($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X98);
            goto L_800E5134;
    }
    goto skip_14;
    // 0x800E5118: lbu         $t5, 0x98($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X98);
    skip_14:
L_800E511C:
    // 0x800E511C: bne         $v0, $zero, L_800E519C
    if (ctx->r2 != 0) {
        // 0x800E5120: addiu       $a0, $a1, 0x294
        ctx->r4 = ADD32(ctx->r5, 0X294);
            goto L_800E519C;
    }
    // 0x800E5120: addiu       $a0, $a1, 0x294
    ctx->r4 = ADD32(ctx->r5, 0X294);
    // 0x800E5124: lb          $t3, 0x3D($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X3D);
    // 0x800E5128: bgezl       $t3, L_800E51A0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E512C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E51A0;
    }
    goto skip_15;
    // 0x800E512C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_15:
    // 0x800E5130: lbu         $t5, 0x98($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X98);
L_800E5134:
    // 0x800E5134: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E5138: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x800E513C: ori         $t8, $t5, 0xE
    ctx->r24 = ctx->r13 | 0XE;
    // 0x800E5140: sb          $t8, 0x98($sp)
    MEM_B(0X98, ctx->r29) = ctx->r24;
    // 0x800E5144: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E5148: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_800E514C:
    // 0x800E514C: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x800E5150: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E5154: bne         $a0, $t7, L_800E516C
    if (ctx->r4 != ctx->r15) {
        // 0x800E5158: nop
    
            goto L_800E516C;
    }
    // 0x800E5158: nop

    // 0x800E515C: lw          $t1, 0x60($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X60);
    // 0x800E5160: addiu       $t9, $sp, 0x98
    ctx->r25 = ADD32(ctx->r29, 0X98);
    // 0x800E5164: b           L_800E5174
    // 0x800E5168: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
        goto L_800E5174;
    // 0x800E5168: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
L_800E516C:
    // 0x800E516C: bne         $v1, $a3, L_800E514C
    if (ctx->r3 != ctx->r7) {
        // 0x800E5170: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E514C;
    }
    // 0x800E5170: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E5174:
    // 0x800E5174: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800E5178: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E517C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E5180: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800E5184: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x800E5188: bnel        $t4, $at, L_800E51A0
    if (ctx->r12 != ctx->r1) {
        // 0x800E518C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_800E51A0;
    }
    goto skip_16;
    // 0x800E518C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    skip_16:
    // 0x800E5190: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800E5194: b           L_800E51A0
    // 0x800E5198: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800E51A0;
    // 0x800E5198: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800E519C:
    // 0x800E519C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800E51A0:
    // 0x800E51A0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E51A4: addiu       $t8, $t8, 0x11C0
    ctx->r24 = ADD32(ctx->r24, 0X11C0);
    // 0x800E51A8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800E51AC: sltu        $at, $a2, $t8
    ctx->r1 = ctx->r6 < ctx->r24 ? 1 : 0;
    // 0x800E51B0: bne         $at, $zero, L_800E50EC
    if (ctx->r1 != 0) {
        // 0x800E51B4: addiu       $a1, $a1, 0xC4
        ctx->r5 = ADD32(ctx->r5, 0XC4);
            goto L_800E50EC;
    }
    // 0x800E51B4: addiu       $a1, $a1, 0xC4
    ctx->r5 = ADD32(ctx->r5, 0XC4);
    // 0x800E51B8: beql        $t0, $zero, L_800E526C
    if (ctx->r8 == 0) {
        // 0x800E51BC: lw          $t5, 0x50($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X50);
            goto L_800E526C;
    }
    goto skip_17;
    // 0x800E51BC: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    skip_17:
    // 0x800E51C0: lw          $t7, 0x50($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X50);
    // 0x800E51C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E51C8: blez        $t7, L_800E5268
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800E51CC: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800E5268;
    }
L_800E51CC:
    // 0x800E51CC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E51D0: addiu       $s1, $s1, 0x11B0
    ctx->r17 = ADD32(ctx->r17, 0X11B0);
    // 0x800E51D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800E51D8:
    // 0x800E51D8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800E51DC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E51E0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E51E4: beq         $t9, $zero, L_800E5240
    if (ctx->r25 == 0) {
        // 0x800E51E8: sll         $t6, $s2, 2
        ctx->r14 = S32(ctx->r18 << 2);
            goto L_800E5240;
    }
    // 0x800E51E8: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x800E51EC: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x800E51F0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800E51F4: addu        $t6, $t6, $s2
    ctx->r14 = ADD32(ctx->r14, ctx->r18);
    // 0x800E51F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E51FC: addu        $s0, $s7, $t6
    ctx->r16 = ADD32(ctx->r23, ctx->r14);
    // 0x800E5200: addiu       $s0, $s0, 0x294
    ctx->r16 = ADD32(ctx->r16, 0X294);
    // 0x800E5204: jal         0x800EFD70
    // 0x800E5208: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    gmCollisionCheckWeaponAttackFighterAttackCollide(rdram, ctx);
        goto after_0;
    // 0x800E5208: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800E520C: beq         $v0, $zero, L_800E5240
    if (ctx->r2 == 0) {
        // 0x800E5210: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_800E5240;
    }
    // 0x800E5210: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5214: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5218: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800E521C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5220: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5224: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E5228: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E522C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800E5230: jal         0x800E2F04
    // 0x800E5234: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    ftMainUpdateAttackStatWeapon(rdram, ctx);
        goto after_1;
    // 0x800E5234: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_1:
    // 0x800E5238: lw          $t3, 0x23C($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X23C);
    // 0x800E523C: bne         $t3, $zero, L_800E559C
    if (ctx->r11 != 0) {
        // 0x800E5240: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800E559C;
    }
L_800E5240:
    // 0x800E5240: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E5244: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E5248: bne         $s2, $at, L_800E51D8
    if (ctx->r18 != ctx->r1) {
        // 0x800E524C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800E51D8;
    }
    // 0x800E524C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800E5250: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E5254: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5258: lw          $v0, 0x50($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X50);
    // 0x800E525C: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5260: bne         $at, $zero, L_800E51CC
    if (ctx->r1 != 0) {
        // 0x800E5264: nop
    
            goto L_800E51CC;
    }
    // 0x800E5264: nop

L_800E5268:
    // 0x800E5268: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
L_800E526C:
    // 0x800E526C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E5270: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E5274: blez        $t5, L_800E52B8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E5278: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_800E52B8;
    }
    // 0x800E5278: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E527C: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E5280: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_800E5284:
    // 0x800E5284: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5288: jal         0x800EF414
    // 0x800E528C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    gmCollisionCheckWeaponInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800E528C: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    after_2:
    // 0x800E5290: beq         $v0, $zero, L_800E529C
    if (ctx->r2 == 0) {
        // 0x800E5294: sw          $v0, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r2;
            goto L_800E529C;
    }
    // 0x800E5294: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800E5298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800E529C:
    // 0x800E529C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800E52A0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E52A4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800E52A8: lw          $t7, 0x50($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X50);
    // 0x800E52AC: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800E52B0: bnel        $at, $zero, L_800E5284
    if (ctx->r1 != 0) {
        // 0x800E52B4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800E5284;
    }
    goto skip_18;
    // 0x800E52B4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_18:
L_800E52B8:
    // 0x800E52B8: beql        $s0, $zero, L_800E55A0
    if (ctx->r16 == 0) {
        // 0x800E52BC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_19;
    // 0x800E52BC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_19:
    // 0x800E52C0: lw          $t9, 0x18C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X18C);
    // 0x800E52C4: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x800E52C8: bgezl       $t1, L_800E5358
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E52CC: lb          $t1, 0x18D($s7)
        ctx->r9 = MEM_B(ctx->r23, 0X18D);
            goto L_800E5358;
    }
    goto skip_20;
    // 0x800E52CC: lb          $t1, 0x18D($s7)
    ctx->r9 = MEM_B(ctx->r23, 0X18D);
    skip_20:
    // 0x800E52D0: lw          $t2, 0x48($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X48);
    // 0x800E52D4: sll         $t4, $t2, 5
    ctx->r12 = S32(ctx->r10 << 5);
    // 0x800E52D8: bgezl       $t4, L_800E5358
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E52DC: lb          $t1, 0x18D($s7)
        ctx->r9 = MEM_B(ctx->r23, 0X18D);
            goto L_800E5358;
    }
    goto skip_21;
    // 0x800E52DC: lb          $t1, 0x18D($s7)
    ctx->r9 = MEM_B(ctx->r23, 0X18D);
    skip_21:
    // 0x800E52E0: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x800E52E4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E52E8: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E52EC: blez        $t5, L_800E5354
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E52F0: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E5354;
    }
    // 0x800E52F0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E52F4:
    // 0x800E52F4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800E52F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E52FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5300: bne         $t8, $zero, L_800E5314
    if (ctx->r24 != 0) {
        // 0x800E5304: or          $a2, $s7, $zero
        ctx->r6 = ctx->r23 | 0;
            goto L_800E5314;
    }
    // 0x800E5304: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E5308: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800E530C: b           L_800E5344
    // 0x800E5310: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
        goto L_800E5344;
    // 0x800E5310: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
L_800E5314:
    // 0x800E5314: jal         0x800EFFCC
    // 0x800E5318: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    gmCollisionCheckWeaponAttackSpecialCollide(rdram, ctx);
        goto after_3;
    // 0x800E5318: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    after_3:
    // 0x800E531C: beq         $v0, $zero, L_800E5340
    if (ctx->r2 == 0) {
        // 0x800E5320: lw          $t9, 0x88($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X88);
            goto L_800E5340;
    }
    // 0x800E5320: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800E5324: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5328: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E532C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E5330: jal         0x800E31B4
    // 0x800E5334: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    ftMainUpdateReflectorStatWeapon(rdram, ctx);
        goto after_4;
    // 0x800E5334: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    after_4:
    // 0x800E5338: b           L_800E55A0
    // 0x800E533C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
        goto L_800E55A0;
    // 0x800E533C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800E5340:
    // 0x800E5340: lw          $v0, 0x50($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X50);
L_800E5344:
    // 0x800E5344: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5348: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E534C: bne         $at, $zero, L_800E52F4
    if (ctx->r1 != 0) {
        // 0x800E5350: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E52F4;
    }
    // 0x800E5350: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E5354:
    // 0x800E5354: lb          $t1, 0x18D($s7)
    ctx->r9 = MEM_B(ctx->r23, 0X18D);
L_800E5358:
    // 0x800E5358: bgezl       $t1, L_800E53E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E535C: lw          $t6, 0x18C($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X18C);
            goto L_800E53E8;
    }
    goto skip_22;
    // 0x800E535C: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
    skip_22:
    // 0x800E5360: lw          $t2, 0x48($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X48);
    // 0x800E5364: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x800E5368: bgezl       $t4, L_800E53E8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E536C: lw          $t6, 0x18C($s7)
        ctx->r14 = MEM_W(ctx->r23, 0X18C);
            goto L_800E53E8;
    }
    goto skip_23;
    // 0x800E536C: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
    skip_23:
    // 0x800E5370: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x800E5374: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E5378: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E537C: blez        $t5, L_800E53E4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E5380: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E53E4;
    }
    // 0x800E5380: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E5384:
    // 0x800E5384: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800E5388: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E538C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5390: bne         $t8, $zero, L_800E53A4
    if (ctx->r24 != 0) {
        // 0x800E5394: or          $a2, $s7, $zero
        ctx->r6 = ctx->r23 | 0;
            goto L_800E53A4;
    }
    // 0x800E5394: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E5398: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800E539C: b           L_800E53D4
    // 0x800E53A0: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
        goto L_800E53D4;
    // 0x800E53A0: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
L_800E53A4:
    // 0x800E53A4: jal         0x800EFFCC
    // 0x800E53A8: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    gmCollisionCheckWeaponAttackSpecialCollide(rdram, ctx);
        goto after_5;
    // 0x800E53A8: lw          $a3, 0x850($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X850);
    after_5:
    // 0x800E53AC: beq         $v0, $zero, L_800E53D0
    if (ctx->r2 == 0) {
        // 0x800E53B0: lw          $t9, 0x88($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X88);
            goto L_800E53D0;
    }
    // 0x800E53B0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800E53B4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E53B8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E53BC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800E53C0: jal         0x800E3308
    // 0x800E53C4: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    ftMainUpdateAbsorbStatWeapon(rdram, ctx);
        goto after_6;
    // 0x800E53C4: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    after_6:
    // 0x800E53C8: b           L_800E55A0
    // 0x800E53CC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
        goto L_800E55A0;
    // 0x800E53CC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800E53D0:
    // 0x800E53D0: lw          $v0, 0x50($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X50);
L_800E53D4:
    // 0x800E53D4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E53D8: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E53DC: bne         $at, $zero, L_800E5384
    if (ctx->r1 != 0) {
        // 0x800E53E0: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E5384;
    }
    // 0x800E53E0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E53E4:
    // 0x800E53E4: lw          $t6, 0x18C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18C);
L_800E53E8:
    // 0x800E53E8: sll         $t2, $t6, 26
    ctx->r10 = S32(ctx->r14 << 26);
    // 0x800E53EC: bgezl       $t2, L_800E54A8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800E53F0: lw          $t5, 0x5AC($s7)
        ctx->r13 = MEM_W(ctx->r23, 0X5AC);
            goto L_800E54A8;
    }
    goto skip_24;
    // 0x800E53F0: lw          $t5, 0x5AC($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X5AC);
    skip_24:
    // 0x800E53F4: lb          $t4, 0x49($s6)
    ctx->r12 = MEM_B(ctx->r22, 0X49);
    // 0x800E53F8: bgezl       $t4, L_800E54A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E53FC: lw          $t5, 0x5AC($s7)
        ctx->r13 = MEM_W(ctx->r23, 0X5AC);
            goto L_800E54A8;
    }
    goto skip_25;
    // 0x800E53FC: lw          $t5, 0x5AC($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X5AC);
    skip_25:
    // 0x800E5400: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x800E5404: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E5408: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E540C: blez        $t5, L_800E54A4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800E5410: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E54A4;
    }
    // 0x800E5410: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E5414:
    // 0x800E5414: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800E5418: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E541C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5420: bne         $t8, $zero, L_800E5434
    if (ctx->r24 != 0) {
        // 0x800E5424: lw          $a2, 0xB8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB8);
            goto L_800E5434;
    }
    // 0x800E5424: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x800E5428: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800E542C: b           L_800E5494
    // 0x800E5430: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
        goto L_800E5494;
    // 0x800E5430: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
L_800E5434:
    // 0x800E5434: lw          $a3, 0x8F4($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X8F4);
    // 0x800E5438: addiu       $t9, $sp, 0x84
    ctx->r25 = ADD32(ctx->r29, 0X84);
    // 0x800E543C: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x800E5440: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800E5444: jal         0x800EFF00
    // 0x800E5448: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    gmCollisionCheckWeaponAttackShieldCollide(rdram, ctx);
        goto after_7;
    // 0x800E5448: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x800E544C: beq         $v0, $zero, L_800E5490
    if (ctx->r2 == 0) {
        // 0x800E5450: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800E5490;
    }
    // 0x800E5450: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800E5454: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5458: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800E545C: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800E5460: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x800E5464: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800E5468: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E546C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5470: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5474: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E5478: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800E547C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800E5480: jal         0x800E3048
    // 0x800E5484: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    ftMainUpdateShieldStatWeapon(rdram, ctx);
        goto after_8;
    // 0x800E5484: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x800E5488: b           L_800E55A0
    // 0x800E548C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
        goto L_800E55A0;
    // 0x800E548C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800E5490:
    // 0x800E5490: lw          $v0, 0x50($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X50);
L_800E5494:
    // 0x800E5494: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5498: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E549C: bne         $at, $zero, L_800E5414
    if (ctx->r1 != 0) {
        // 0x800E54A0: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E5414;
    }
    // 0x800E54A0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E54A4:
    // 0x800E54A4: lw          $t5, 0x5AC($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X5AC);
L_800E54A8:
    // 0x800E54A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E54AC: beql        $t5, $at, L_800E55A0
    if (ctx->r13 == ctx->r1) {
        // 0x800E54B0: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_26;
    // 0x800E54B0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_26:
    // 0x800E54B4: lw          $t8, 0x5B4($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X5B4);
    // 0x800E54B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E54BC: beql        $t8, $at, L_800E55A0
    if (ctx->r24 == ctx->r1) {
        // 0x800E54C0: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_27;
    // 0x800E54C0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_27:
    // 0x800E54C4: lw          $t7, 0x5B8($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X5B8);
    // 0x800E54C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E54CC: beql        $t7, $at, L_800E55A0
    if (ctx->r15 == ctx->r1) {
        // 0x800E54D0: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800E55A0;
    }
    goto skip_28;
    // 0x800E54D0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_28:
    // 0x800E54D4: lw          $t9, 0x50($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X50);
    // 0x800E54D8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E54DC: addiu       $s5, $s5, 0x11A0
    ctx->r21 = ADD32(ctx->r21, 0X11A0);
    // 0x800E54E0: blez        $t9, L_800E559C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800E54E4: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800E559C;
    }
    // 0x800E54E4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800E54E8:
    // 0x800E54E8: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x800E54EC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800E54F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E54F4: bne         $t6, $zero, L_800E5504
    if (ctx->r14 != 0) {
        // 0x800E54F8: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_800E5504;
    }
    // 0x800E54F8: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x800E54FC: b           L_800E558C
    // 0x800E5500: lw          $v0, 0x50($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X50);
        goto L_800E558C;
    // 0x800E5500: lw          $v0, 0x50($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X50);
L_800E5504:
    // 0x800E5504: lw          $t2, 0x5BC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X5BC);
    // 0x800E5508: addiu       $s0, $s1, 0x5BC
    ctx->r16 = ADD32(ctx->r17, 0X5BC);
    // 0x800E550C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800E5510: bne         $t2, $zero, L_800E5524
    if (ctx->r10 != 0) {
        // 0x800E5514: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800E5524;
    }
    // 0x800E5514: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E5518: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800E551C: b           L_800E558C
    // 0x800E5520: lw          $v0, 0x50($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X50);
        goto L_800E558C;
    // 0x800E5520: lw          $v0, 0x50($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X50);
L_800E5524:
    // 0x800E5524: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E5528: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E552C: beql        $t4, $at, L_800E5578
    if (ctx->r12 == ctx->r1) {
        // 0x800E5530: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_800E5578;
    }
    goto skip_29;
    // 0x800E5530: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    skip_29:
    // 0x800E5534: jal         0x800EFE6C
    // 0x800E5538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    gmCollisionCheckWeaponAttackFighterDamageCollide(rdram, ctx);
        goto after_9;
    // 0x800E5538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800E553C: beql        $v0, $zero, L_800E5578
    if (ctx->r2 == 0) {
        // 0x800E5540: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_800E5578;
    }
    goto skip_30;
    // 0x800E5540: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    skip_30:
    // 0x800E5544: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5548: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x800E554C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E5550: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800E5554: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5558: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800E555C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E5560: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800E5564: jal         0x800E3418
    // 0x800E5568: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    ftMainUpdateDamageStatWeapon(rdram, ctx);
        goto after_10;
    // 0x800E5568: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_10:
    // 0x800E556C: b           L_800E55A0
    // 0x800E5570: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
        goto L_800E55A0;
    // 0x800E5570: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800E5574: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
L_800E5578:
    // 0x800E5578: addiu       $at, $zero, 0x1E4
    ctx->r1 = ADD32(0, 0X1E4);
    // 0x800E557C: bne         $s3, $at, L_800E5504
    if (ctx->r19 != ctx->r1) {
        // 0x800E5580: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E5504;
    }
    // 0x800E5580: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x800E5584: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800E5588: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
L_800E558C:
    // 0x800E558C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E5590: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E5594: bne         $at, $zero, L_800E54E8
    if (ctx->r1 != 0) {
        // 0x800E5598: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800E54E8;
    }
    // 0x800E5598: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800E559C:
    // 0x800E559C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800E55A0:
    // 0x800E55A0: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800E55A4: bne         $t6, $zero, L_800E4F18
    if (ctx->r14 != 0) {
        // 0x800E55A8: sw          $t6, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r14;
            goto L_800E4F18;
    }
    // 0x800E55A8: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
L_800E55AC:
    // 0x800E55AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E55B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E55B4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E55B8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E55BC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E55C0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E55C4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E55C8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E55CC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800E55D0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800E55D4: jr          $ra
    // 0x800E55D8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800E55D8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801536C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801536C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801536C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801536CC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801536D0: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x801536D4: beql        $t7, $zero, L_801537AC
    if (ctx->r15 == 0) {
        // 0x801536D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801537AC;
    }
    goto skip_0;
    // 0x801536D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801536DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801536E0: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x801536E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801536E8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801536EC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801536F0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801536F4: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x801536F8: jal         0x800EDF24
    // 0x801536FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x801536FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80153700: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80153704: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80153708: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015370C: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80153710: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80153714: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80153718: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8015371C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153720: lwc1        $f12, -0x3A70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A70);
    // 0x80153724: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80153728: add.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8015372C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80153730: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80153734: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80153738: jal         0x80035CD0
    // 0x8015373C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015373C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80153740: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80153744: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80153748: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015374C: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80153750: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153754: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80153758: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8015375C: lwc1        $f12, -0x3A6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A6C);
    // 0x80153760: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80153764: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80153768: jal         0x800303F0
    // 0x8015376C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8015376C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80153770: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80153774: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80153778: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8015377C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80153780: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80153784: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80153788: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8015378C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80153790: jal         0x801695E4
    // 0x80153794: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    wpPikachuThunderJoltAirMakeWeapon(rdram, ctx);
        goto after_3;
    // 0x80153794: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80153798: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8015379C: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x801537A0: jal         0x800E9814
    // 0x801537A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_4;
    // 0x801537A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801537A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801537AC:
    // 0x801537AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801537B0: jr          $ra
    // 0x801537B4: nop

    return;
    // 0x801537B4: nop

;}
RECOMP_FUNC void ftDisplayMainSetFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1B24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800F1B28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F1B2C: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F1B30: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800F1B34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F1B38: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800F1B3C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800F1B40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F1B44: addiu       $a1, $a1, 0x12F4
    ctx->r5 = ADD32(ctx->r5, 0X12F4);
    // 0x800F1B48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800F1B4C: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    // 0x800F1B50: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800F1B54: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800F1B58: lbu         $t1, 0x3($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X3);
    // 0x800F1B5C: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800F1B60: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800F1B64: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800F1B68: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800F1B6C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800F1B70: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800F1B74: jr          $ra
    // 0x800F1B78: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x800F1B78: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void func_ovl8_80373CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373CC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80373CC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80373CCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80373CD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80373CD4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80373CD8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80373CDC: bne         $a0, $zero, L_80373CF4
    if (ctx->r4 != 0) {
        // 0x80373CE0: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80373CF4;
    }
    // 0x80373CE0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80373CE4: jal         0x803717A0
    // 0x80373CE8: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80373CE8: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80373CEC: beq         $v0, $zero, L_80373D74
    if (ctx->r2 == 0) {
        // 0x80373CF0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373D74;
    }
    // 0x80373CF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80373CF4:
    // 0x80373CF4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80373CF8: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80373CFC: addiu       $a1, $s0, 0x9C
    ctx->r5 = ADD32(ctx->r16, 0X9C);
    // 0x80373D00: bnel        $t6, $zero, L_80373D24
    if (ctx->r14 != 0) {
        // 0x80373D04: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80373D24;
    }
    goto skip_0;
    // 0x80373D04: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80373D08: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373D0C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80373D10: jal         0x803717E0
    // 0x80373D14: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80373D14: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80373D18: jal         0x8037C2D0
    // 0x80373D1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80373D1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80373D20: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80373D24:
    // 0x80373D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80373D28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80373D2C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80373D30: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80373D34: jal         0x8037345C
    // 0x80373D38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037345C(rdram, ctx);
        goto after_3;
    // 0x80373D38: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80373D3C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80373D40: addiu       $t8, $t8, -0x6D10
    ctx->r24 = ADD32(ctx->r24, -0X6D10);
    // 0x80373D44: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80373D48: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80373D4C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80373D50: addiu       $t9, $t9, -0x6C38
    ctx->r25 = ADD32(ctx->r25, -0X6C38);
    // 0x80373D54: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80373D58: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80373D5C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80373D60: addiu       $t1, $t1, -0x6AE0
    ctx->r9 = ADD32(ctx->r9, -0X6AE0);
    // 0x80373D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80373D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373D6C: jal         0x803743CC
    // 0x80373D70: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    func_ovl8_803743CC(rdram, ctx);
        goto after_4;
    // 0x80373D70: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    after_4:
L_80373D74:
    // 0x80373D74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80373D78: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80373D7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80373D80: jr          $ra
    // 0x80373D84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80373D84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gmCameraUpdateInterests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BC54: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8010BC58: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8010BC5C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8010BC60: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8010BC64: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8010BC68: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8010BC6C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8010BC70: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8010BC74: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8010BC78: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8010BC7C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8010BC80: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010BC84: sw          $a0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r4;
    // 0x8010BC88: sw          $a1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r5;
    // 0x8010BC8C: sw          $a2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r6;
    // 0x8010BC90: beq         $s0, $zero, L_8010BE08
    if (ctx->r16 == 0) {
        // 0x8010BC94: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8010BE08;
    }
    // 0x8010BC94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8010BC98: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_8010BC9C:
    // 0x8010BC9C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8010BCA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010BCA4: lhu         $t6, 0x190($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X190);
    // 0x8010BCA8: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8010BCAC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010BCB0: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8010BCB4: beq         $t7, $at, L_8010BDFC
    if (ctx->r15 == ctx->r1) {
        // 0x8010BCB8: addiu       $t9, $sp, 0xD8
        ctx->r25 = ADD32(ctx->r29, 0XD8);
            goto L_8010BDFC;
    }
    // 0x8010BCB8: addiu       $t9, $sp, 0xD8
    ctx->r25 = ADD32(ctx->r29, 0XD8);
    // 0x8010BCBC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8010BCC0: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8010BCC4: bne         $at, $zero, L_8010BCEC
    if (ctx->r1 != 0) {
        // 0x8010BCC8: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_8010BCEC;
    }
    // 0x8010BCC8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8010BCCC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010BCD0: addiu       $s0, $s0, 0xBD0
    ctx->r16 = ADD32(ctx->r16, 0XBD0);
L_8010BCD4:
    // 0x8010BCD4: jal         0x80023624
    // 0x8010BCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x8010BCD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010BCDC: jal         0x800A3040
    // 0x8010BCE0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x8010BCE0: nop

    after_1:
    // 0x8010BCE4: b           L_8010BCD4
    // 0x8010BCE8: nop

        goto L_8010BCD4;
    // 0x8010BCE8: nop

L_8010BCEC:
    // 0x8010BCEC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8010BCF0: lhu         $v1, 0x190($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X190);
    // 0x8010BCF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8010BCF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010BCFC: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8010BD00: beql        $v1, $a2, L_8010BD58
    if (ctx->r3 == ctx->r6) {
        // 0x8010BD04: lw          $t6, 0xB1C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0XB1C);
            goto L_8010BD58;
    }
    goto skip_0;
    // 0x8010BD04: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x8010BD08: beq         $v1, $at, L_8010BD38
    if (ctx->r3 == ctx->r1) {
        // 0x8010BD0C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8010BD38;
    }
    // 0x8010BD0C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010BD10: beql        $v1, $at, L_8010BD3C
    if (ctx->r3 == ctx->r1) {
        // 0x8010BD14: lw          $t4, 0x854($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X854);
            goto L_8010BD3C;
    }
    goto skip_1;
    // 0x8010BD14: lw          $t4, 0x854($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X854);
    skip_1:
    // 0x8010BD18: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x8010BD1C: lw          $t2, 0x1C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1C);
    // 0x8010BD20: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8010BD24: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x8010BD28: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x8010BD2C: lw          $t2, 0x24($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X24);
    // 0x8010BD30: b           L_8010BD6C
    // 0x8010BD34: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
        goto L_8010BD6C;
    // 0x8010BD34: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
L_8010BD38:
    // 0x8010BD38: lw          $t4, 0x854($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X854);
L_8010BD3C:
    // 0x8010BD3C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8010BD40: lw          $t3, 0x858($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X858);
    // 0x8010BD44: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x8010BD48: lw          $t4, 0x85C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X85C);
    // 0x8010BD4C: b           L_8010BD6C
    // 0x8010BD50: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
        goto L_8010BD6C;
    // 0x8010BD50: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x8010BD54: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
L_8010BD58:
    // 0x8010BD58: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8010BD5C: lw          $t5, 0xB20($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XB20);
    // 0x8010BD60: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8010BD64: lw          $t6, 0xB24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB24);
    // 0x8010BD68: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
L_8010BD6C:
    // 0x8010BD6C: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x8010BD70: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8010BD74: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8010BD78: lwc1        $f6, 0x8C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8C);
    // 0x8010BD7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8010BD80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010BD84: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8010BD88: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8010BD8C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8010BD90: bnel        $t8, $at, L_8010BDD4
    if (ctx->r24 != ctx->r1) {
        // 0x8010BD94: lhu         $t3, 0x190($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X190);
            goto L_8010BDD4;
    }
    goto skip_2;
    // 0x8010BD94: lhu         $t3, 0x190($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X190);
    skip_2:
    // 0x8010BD98: lbu         $t9, 0xD($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XD);
    // 0x8010BD9C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8010BDA0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8010BDA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010BDA8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8010BDAC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8010BDB0: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8010BDB4: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x8010BDB8: beql        $t2, $zero, L_8010BDD4
    if (ctx->r10 == 0) {
        // 0x8010BDBC: lhu         $t3, 0x190($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X190);
            goto L_8010BDD4;
    }
    goto skip_3;
    // 0x8010BDBC: lhu         $t3, 0x190($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X190);
    skip_3:
    // 0x8010BDC0: jal         0x8010BA38
    // 0x8010BDC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gmCameraSetTeamBoundsPosition(rdram, ctx);
        goto after_2;
    // 0x8010BDC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8010BDC8: b           L_8010BDFC
    // 0x8010BDCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8010BDFC;
    // 0x8010BDCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8010BDD0: lhu         $t3, 0x190($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X190);
L_8010BDD4:
    // 0x8010BDD4: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8010BDD8: bne         $a2, $t4, L_8010BDF0
    if (ctx->r6 != ctx->r12) {
        // 0x8010BDDC: nop
    
            goto L_8010BDF0;
    }
    // 0x8010BDDC: nop

    // 0x8010BDE0: jal         0x8010BB08
    // 0x8010BDE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gmCameraSetDeadUpStarPosition(rdram, ctx);
        goto after_3;
    // 0x8010BDE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8010BDE8: b           L_8010BDFC
    // 0x8010BDEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8010BDFC;
    // 0x8010BDEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8010BDF0:
    // 0x8010BDF0: jal         0x8010B8BC
    // 0x8010BDF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gmCameraSetBoundsPosition(rdram, ctx);
        goto after_4;
    // 0x8010BDF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8010BDF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8010BDFC:
    // 0x8010BDFC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8010BE00: bnel        $s0, $zero, L_8010BC9C
    if (ctx->r16 != 0) {
        // 0x8010BE04: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_8010BC9C;
    }
    goto skip_4;
    // 0x8010BE04: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_4:
L_8010BE08:
    // 0x8010BE08: beq         $s1, $zero, L_8010C1A4
    if (ctx->r17 == 0) {
        // 0x8010BE0C: lw          $t9, 0x130($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X130);
            goto L_8010C1A4;
    }
    // 0x8010BE0C: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x8010BE10: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8010BE14: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8010BE18: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x8010BE1C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010BE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010BE24: mov.s       $f30, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    ctx->f30.fl = ctx->f22.fl;
    // 0x8010BE28: swc1        $f22, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f22.u32l;
    // 0x8010BE2C: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x8010BE30: swc1        $f24, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f24.u32l;
    // 0x8010BE34: swc1        $f24, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f24.u32l;
    // 0x8010BE38: jal         0x8010BB58
    // 0x8010BE3C: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    gmCameraGetPlayerNumZoomRange(rdram, ctx);
        goto after_5;
    // 0x8010BE3C: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    after_5:
    // 0x8010BE40: blez        $s1, L_8010BFB8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8010BE44: swc1        $f0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
            goto L_8010BFB8;
    }
    // 0x8010BE44: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8010BE48: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8010BE4C: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x8010BE50: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010BE54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010BE58: addiu       $v1, $sp, 0xD8
    ctx->r3 = ADD32(ctx->r29, 0XD8);
    // 0x8010BE5C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010BE60: addu        $s0, $t6, $v1
    ctx->r16 = ADD32(ctx->r14, ctx->r3);
L_8010BE64:
    // 0x8010BE64: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8010BE68: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x8010BE6C: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x8010BE70: jal         0x8010BB98
    // 0x8010BE74: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    gmCameraCalcFighterZoomRange(rdram, ctx);
        goto after_6;
    // 0x8010BE74: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    after_6:
    // 0x8010BE78: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8010BE7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010BE80: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8010BE84: lhu         $v0, 0x190($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X190);
    // 0x8010BE88: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8010BE8C: beq         $v0, $at, L_8010BE9C
    if (ctx->r2 == ctx->r1) {
        // 0x8010BE90: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8010BE9C;
    }
    // 0x8010BE90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010BE94: bnel        $v0, $at, L_8010BEA8
    if (ctx->r2 != ctx->r1) {
        // 0x8010BE98: lw          $v0, 0x44($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X44);
            goto L_8010BEA8;
    }
    goto skip_5;
    // 0x8010BE98: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    skip_5:
L_8010BE9C:
    // 0x8010BE9C: b           L_8010BEA8
    // 0x8010BEA0: lw          $v0, 0xB1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB1C);
        goto L_8010BEA8;
    // 0x8010BEA0: lw          $v0, 0xB1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB1C);
    // 0x8010BEA4: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
L_8010BEA8:
    // 0x8010BEA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010BEAC: bne         $v0, $at, L_8010BED0
    if (ctx->r2 != ctx->r1) {
        // 0x8010BEB0: lui         $at, 0x442F
        ctx->r1 = S32(0X442F << 16);
            goto L_8010BED0;
    }
    // 0x8010BEB0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8010BEB4: mul.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8010BEB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010BEBC: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8010BEC0: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8010BEC4: sub.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8010BEC8: b           L_8010BEF0
    // 0x8010BECC: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
        goto L_8010BEF0;
    // 0x8010BECC: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
L_8010BED0:
    // 0x8010BED0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8010BED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010BED8: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8010BEDC: mul.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010BEE0: nop

    // 0x8010BEE4: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8010BEE8: sub.s       $f2, $f12, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8010BEEC: add.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f8.fl;
L_8010BEF0:
    // 0x8010BEF0: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x8010BEF4: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x8010BEF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010BEFC: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8010BF00: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010BF04: bc1fl       L_8010BF14
    if (!c1cs) {
        // 0x8010BF08: c.lt.s      $f24, $f16
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
            goto L_8010BF14;
    }
    goto skip_6;
    // 0x8010BF08: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
    skip_6:
    // 0x8010BF0C: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x8010BF10: c.lt.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl < ctx->f16.fl;
L_8010BF14:
    // 0x8010BF14: nop

    // 0x8010BF18: bc1fl       L_8010BF28
    if (!c1cs) {
        // 0x8010BF1C: lwc1        $f2, 0x8($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
            goto L_8010BF28;
    }
    goto skip_7;
    // 0x8010BF1C: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    skip_7:
    // 0x8010BF20: mov.s       $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    ctx->f24.fl = ctx->f16.fl;
    // 0x8010BF24: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
L_8010BF28:
    // 0x8010BF28: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8010BF2C: add.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8010BF30: c.lt.s      $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f18.fl < ctx->f26.fl;
    // 0x8010BF34: nop

    // 0x8010BF38: bc1fl       L_8010BF48
    if (!c1cs) {
        // 0x8010BF3C: c.lt.s      $f28, $f16
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f28.fl < ctx->f16.fl;
            goto L_8010BF48;
    }
    goto skip_8;
    // 0x8010BF3C: c.lt.s      $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f28.fl < ctx->f16.fl;
    skip_8:
    // 0x8010BF40: mov.s       $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    ctx->f26.fl = ctx->f18.fl;
    // 0x8010BF44: c.lt.s      $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f28.fl < ctx->f16.fl;
L_8010BF48:
    // 0x8010BF48: nop

    // 0x8010BF4C: bc1fl       L_8010BF5C
    if (!c1cs) {
        // 0x8010BF50: c.lt.s      $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
            goto L_8010BF5C;
    }
    goto skip_9;
    // 0x8010BF50: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    skip_9:
    // 0x8010BF54: mov.s       $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    ctx->f28.fl = ctx->f16.fl;
    // 0x8010BF58: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
L_8010BF5C:
    // 0x8010BF5C: nop

    // 0x8010BF60: bc1fl       L_8010BF70
    if (!c1cs) {
        // 0x8010BF64: lwc1        $f8, 0xB8($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
            goto L_8010BF70;
    }
    goto skip_10;
    // 0x8010BF64: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    skip_10:
    // 0x8010BF68: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x8010BF6C: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
L_8010BF70:
    // 0x8010BF70: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8010BF74: nop

    // 0x8010BF78: bc1fl       L_8010BF88
    if (!c1cs) {
        // 0x8010BF7C: c.lt.s      $f2, $f30
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f2.fl < ctx->f30.fl;
            goto L_8010BF88;
    }
    goto skip_11;
    // 0x8010BF7C: c.lt.s      $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f2.fl < ctx->f30.fl;
    skip_11:
    // 0x8010BF80: swc1        $f12, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f12.u32l;
    // 0x8010BF84: c.lt.s      $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f2.fl < ctx->f30.fl;
L_8010BF88:
    // 0x8010BF88: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8010BF8C: bc1fl       L_8010BF9C
    if (!c1cs) {
        // 0x8010BF90: c.lt.s      $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
            goto L_8010BF9C;
    }
    goto skip_12;
    // 0x8010BF90: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    skip_12:
    // 0x8010BF94: mov.s       $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    ctx->f30.fl = ctx->f2.fl;
    // 0x8010BF98: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
L_8010BF9C:
    // 0x8010BF9C: nop

    // 0x8010BFA0: bc1fl       L_8010BFB0
    if (!c1cs) {
        // 0x8010BFA4: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8010BFB0;
    }
    goto skip_13;
    // 0x8010BFA4: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_13:
    // 0x8010BFA8: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    // 0x8010BFAC: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_8010BFB0:
    // 0x8010BFB0: bne         $v1, $s0, L_8010BE64
    if (ctx->r3 != ctx->r16) {
        // 0x8010BFB4: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_8010BE64;
    }
    // 0x8010BFB4: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
L_8010BFB8:
    // 0x8010BFB8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8010BFBC: lw          $v1, 0x6704($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6704);
    // 0x8010BFC0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8010BFC4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010BFC8: beq         $v1, $zero, L_8010C114
    if (ctx->r3 == 0) {
        // 0x8010BFCC: addiu       $s0, $sp, 0x6C
        ctx->r16 = ADD32(ctx->r29, 0X6C);
            goto L_8010C114;
    }
    // 0x8010BFCC: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x8010BFD0: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
L_8010BFD4:
    // 0x8010BFD4: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8010BFD8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8010BFDC: beql        $t8, $zero, L_8010C10C
    if (ctx->r24 == 0) {
        // 0x8010BFE0: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8010C10C;
    }
    goto skip_14;
    // 0x8010BFE0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_14:
    // 0x8010BFE4: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8010BFE8: sub.s       $f12, $f30, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f30.fl - ctx->f20.fl;
    // 0x8010BFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010BFF0: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x8010BFF4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8010BFF8: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8010BFFC: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x8010C000: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x8010C004: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x8010C008: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8010C00C: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8010C010: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8010C014: add.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8010C018: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x8010C01C: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x8010C020: add.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8010C024: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8010C028: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x8010C02C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x8010C030: jal         0x8010B8BC
    // 0x8010C034: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    gmCameraSetBoundsPosition(rdram, ctx);
        goto after_7;
    // 0x8010C034: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8010C038: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8010C03C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8010C040: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8010C044: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010C048: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8010C04C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010C050: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010C054: bc1fl       L_8010C064
    if (!c1cs) {
        // 0x8010C058: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8010C064;
    }
    goto skip_15;
    // 0x8010C058: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_15:
    // 0x8010C05C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8010C060: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8010C064:
    // 0x8010C064: nop

    // 0x8010C068: bc1fl       L_8010C078
    if (!c1cs) {
        // 0x8010C06C: lwc1        $f2, 0x70($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8010C078;
    }
    goto skip_16;
    // 0x8010C06C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    skip_16:
    // 0x8010C070: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x8010C074: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
L_8010C078:
    // 0x8010C078: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x8010C07C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8010C080: nop

    // 0x8010C084: bc1fl       L_8010C094
    if (!c1cs) {
        // 0x8010C088: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8010C094;
    }
    goto skip_17;
    // 0x8010C088: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_17:
    // 0x8010C08C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8010C090: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8010C094:
    // 0x8010C094: nop

    // 0x8010C098: bc1fl       L_8010C0A8
    if (!c1cs) {
        // 0x8010C09C: c.lt.s      $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
            goto L_8010C0A8;
    }
    goto skip_18;
    // 0x8010C09C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    skip_18:
    // 0x8010C0A0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8010C0A4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_8010C0A8:
    // 0x8010C0A8: nop

    // 0x8010C0AC: bc1fl       L_8010C0BC
    if (!c1cs) {
        // 0x8010C0B0: add.s       $f0, $f16, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f20.fl;
            goto L_8010C0BC;
    }
    goto skip_19;
    // 0x8010C0B0: add.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f20.fl;
    skip_19:
    // 0x8010C0B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8010C0B8: add.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f20.fl;
L_8010C0BC:
    // 0x8010C0BC: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x8010C0C0: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x8010C0C4: nop

    // 0x8010C0C8: bc1fl       L_8010C0D8
    if (!c1cs) {
        // 0x8010C0CC: sub.s       $f0, $f2, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_8010C0D8;
    }
    goto skip_20;
    // 0x8010C0CC: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
    skip_20:
    // 0x8010C0D0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8010C0D4: sub.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f20.fl;
L_8010C0D8:
    // 0x8010C0D8: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x8010C0DC: nop

    // 0x8010C0E0: bc1fl       L_8010C0F0
    if (!c1cs) {
        // 0x8010C0E4: add.s       $f0, $f2, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f20.fl;
            goto L_8010C0F0;
    }
    goto skip_21;
    // 0x8010C0E4: add.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f20.fl;
    skip_21:
    // 0x8010C0E8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8010C0EC: add.s       $f0, $f2, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f20.fl;
L_8010C0F0:
    // 0x8010C0F0: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x8010C0F4: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x8010C0F8: nop

    // 0x8010C0FC: bc1fl       L_8010C10C
    if (!c1cs) {
        // 0x8010C100: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8010C10C;
    }
    goto skip_22;
    // 0x8010C100: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_22:
    // 0x8010C104: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8010C108: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_8010C10C:
    // 0x8010C10C: bnel        $v1, $zero, L_8010BFD4
    if (ctx->r3 != 0) {
        // 0x8010C110: lw          $v0, 0x84($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X84);
            goto L_8010BFD4;
    }
    goto skip_23;
    // 0x8010C110: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    skip_23:
L_8010C114:
    // 0x8010C114: sub.s       $f10, $f24, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x8010C118: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010C11C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010C120: sub.s       $f6, $f28, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f26.fl;
    // 0x8010C124: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x8010C128: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8010C12C: add.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x8010C130: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8010C134: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8010C138: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8010C13C: lw          $t3, 0x138($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X138);
    // 0x8010C140: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8010C144: lw          $t4, 0x130($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X130);
    // 0x8010C148: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8010C14C: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x8010C150: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x8010C154: lwc1        $f2, 0x0($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8010C158: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8010C15C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010C160: nop

    // 0x8010C164: bc1fl       L_8010C178
    if (!c1cs) {
        // 0x8010C168: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8010C178;
    }
    goto skip_24;
    // 0x8010C168: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_24:
    // 0x8010C16C: b           L_8010C178
    // 0x8010C170: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8010C178;
    // 0x8010C170: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8010C174: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8010C178:
    // 0x8010C178: jal         0x8010BBE4
    // 0x8010C17C: nop

    gmCameraGetTargetAtY(rdram, ctx);
        goto after_8;
    // 0x8010C17C: nop

    after_8:
    // 0x8010C180: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8010C184: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8010C188: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010C18C: add.s       $f8, $f26, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x8010C190: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010C194: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x8010C198: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8010C19C: b           L_8010C1D4
    // 0x8010C1A0: swc1        $f2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f2.u32l;
        goto L_8010C1D4;
    // 0x8010C1A0: swc1        $f2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f2.u32l;
L_8010C1A4:
    // 0x8010C1A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8010C1A8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8010C1AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010C1B0: swc1        $f2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f2.u32l;
    // 0x8010C1B4: lw          $t0, 0x130($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X130);
    // 0x8010C1B8: swc1        $f2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f2.u32l;
    // 0x8010C1BC: lw          $t1, 0x130($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X130);
    // 0x8010C1C0: swc1        $f2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f2.u32l;
    // 0x8010C1C4: lw          $t2, 0x138($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X138);
    // 0x8010C1C8: swc1        $f0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f0.u32l;
    // 0x8010C1CC: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x8010C1D0: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
L_8010C1D4:
    // 0x8010C1D4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8010C1D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010C1DC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8010C1E0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8010C1E4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8010C1E8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8010C1EC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8010C1F0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8010C1F4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8010C1F8: jr          $ra
    // 0x8010C1FC: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x8010C1FC: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void mnVSResultsSetNumberColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134770: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80134774: addiu       $t6, $t6, -0x6A38
    ctx->r14 = ADD32(ctx->r14, -0X6A38);
    // 0x80134778: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013477C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134780: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80134784: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134788: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013478C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80134790: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80134794: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80134798: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013479C: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x801347A0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x801347A4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801347A8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801347AC: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x801347B0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801347B4: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x801347B8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801347BC: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x801347C0: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x801347C4: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x801347C8: lhu         $t8, 0x1C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X1C);
    // 0x801347CC: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
    // 0x801347D0: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801347D4: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x801347D8: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x801347DC: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x801347E0: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x801347E4: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x801347E8: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x801347EC: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x801347F0: lbu         $t4, 0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4);
    // 0x801347F4: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x801347F8: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x801347FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134800: jr          $ra
    // 0x80134804: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
    return;
    // 0x80134804: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void mnVSResultsGetPlayerCountAhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133718: beq         $a0, $zero, L_80133758
    if (ctx->r4 == 0) {
        // 0x8013371C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80133758;
    }
    // 0x8013371C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80133720: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133724: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80133728: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013372C: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x80133730: beq         $t6, $zero, L_80133758
    if (ctx->r14 == 0) {
        // 0x80133734: lui         $t7, 0x8014
        ctx->r15 = S32(0X8014 << 16);
            goto L_80133758;
    }
    // 0x80133734: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133738: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8013373C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80133740: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80133744: lw          $t7, -0x6450($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6450);
    // 0x80133748: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8013374C: beql        $at, $zero, L_8013375C
    if (ctx->r1 == 0) {
        // 0x80133750: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8013375C;
    }
    goto skip_0;
    // 0x80133750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80133754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80133758:
    // 0x80133758: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8013375C:
    // 0x8013375C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133760: beq         $a0, $at, L_80133798
    if (ctx->r4 == ctx->r1) {
        // 0x80133764: addiu       $v0, $v0, -0x6450
        ctx->r2 = ADD32(ctx->r2, -0X6450);
            goto L_80133798;
    }
    // 0x80133764: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x80133768: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013376C: lw          $t1, -0x642C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X642C);
    // 0x80133770: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80133774: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80133778: beq         $t1, $zero, L_80133798
    if (ctx->r9 == 0) {
        // 0x8013377C: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80133798;
    }
    // 0x8013377C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133780: lw          $t2, -0x644C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X644C);
    // 0x80133784: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80133788: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8013378C: beql        $at, $zero, L_8013379C
    if (ctx->r1 == 0) {
        // 0x80133790: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013379C;
    }
    goto skip_1;
    // 0x80133790: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x80133794: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80133798:
    // 0x80133798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8013379C:
    // 0x8013379C: beq         $a0, $at, L_801337D0
    if (ctx->r4 == ctx->r1) {
        // 0x801337A0: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_801337D0;
    }
    // 0x801337A0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801337A4: lw          $t6, -0x6428($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6428);
    // 0x801337A8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x801337AC: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x801337B0: beq         $t6, $zero, L_801337D0
    if (ctx->r14 == 0) {
        // 0x801337B4: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_801337D0;
    }
    // 0x801337B4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801337B8: lw          $t8, -0x6448($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6448);
    // 0x801337BC: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x801337C0: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801337C4: beql        $at, $zero, L_801337D4
    if (ctx->r1 == 0) {
        // 0x801337C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801337D4;
    }
    goto skip_2;
    // 0x801337C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x801337CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801337D0:
    // 0x801337D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_801337D4:
    // 0x801337D4: beq         $a0, $at, L_80133808
    if (ctx->r4 == ctx->r1) {
        // 0x801337D8: lui         $t1, 0x8014
        ctx->r9 = S32(0X8014 << 16);
            goto L_80133808;
    }
    // 0x801337D8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801337DC: lw          $t1, -0x6424($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6424);
    // 0x801337E0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x801337E4: addu        $t2, $v0, $t4
    ctx->r10 = ADD32(ctx->r2, ctx->r12);
    // 0x801337E8: beq         $t1, $zero, L_80133808
    if (ctx->r9 == 0) {
        // 0x801337EC: lui         $t3, 0x8014
        ctx->r11 = S32(0X8014 << 16);
            goto L_80133808;
    }
    // 0x801337EC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801337F0: lw          $t3, -0x6444($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6444);
    // 0x801337F4: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x801337F8: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801337FC: beq         $at, $zero, L_80133808
    if (ctx->r1 == 0) {
        // 0x80133800: nop
    
            goto L_80133808;
    }
    // 0x80133800: nop

    // 0x80133804: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80133808:
    // 0x80133808: jr          $ra
    // 0x8013380C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013380C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void dbCubeStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013214C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132150: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132154: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132158: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013215C: addiu       $a0, $a0, 0x2F6C
    ctx->r4 = ADD32(ctx->r4, 0X2F6C);
    // 0x80132160: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132164: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132168: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013216C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80132174: jal         0x80007024
    // 0x80132178: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132178: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013217C: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x80132180: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132184: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80132188: addiu       $t9, $t9, 0x3170
    ctx->r25 = ADD32(ctx->r25, 0X3170);
    // 0x8013218C: addiu       $t8, $t8, -0x6DC0
    ctx->r24 = ADD32(ctx->r24, -0X6DC0);
    // 0x80132190: addiu       $s1, $s1, 0x2F88
    ctx->r17 = ADD32(ctx->r17, 0X2F88);
    // 0x80132194: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132198: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8013219C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801321A0: sw          $t0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r8;
    // 0x801321A4: addiu       $s0, $s0, 0x313C
    ctx->r16 = ADD32(ctx->r16, 0X313C);
    // 0x801321A8: addiu       $s2, $s2, 0x3138
    ctx->r18 = ADD32(ctx->r18, 0X3138);
    // 0x801321AC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_801321B0:
    // 0x801321B0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x801321B4: jal         0x8000683C
    // 0x801321B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801321B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801321BC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x801321C0: bnel        $t1, $zero, L_801321B0
    if (ctx->r9 != 0) {
        // 0x801321C4: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_801321B0;
    }
    goto skip_0;
    // 0x801321C4: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_0:
    // 0x801321C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801321CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801321D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801321D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801321D8: jr          $ra
    // 0x801321DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801321DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80384774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038477C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384780: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80384784: lh          $t6, 0xF0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XF0);
    // 0x80384788: jalr        $t9
    // 0x8038478C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038478C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80384790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384798: jr          $ra
    // 0x8038479C: nop

    return;
    // 0x8038479C: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D9B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015D9B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D9B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015D9BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015D9C0: jal         0x800DEE98
    // 0x8015D9C4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015D9C4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015D9C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015D9CC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015D9D0: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015D9D4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015D9D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015D9DC: jal         0x800E6F24
    // 0x8015D9E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D9E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015D9E4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015D9E8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015D9EC: addiu       $t8, $t8, -0x2CC8
    ctx->r24 = ADD32(ctx->r24, -0X2CC8);
    // 0x8015D9F0: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015D9F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D9F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015D9FC: jr          $ra
    // 0x8015DA00: nop

    return;
    // 0x8015DA00: nop

;}
RECOMP_FUNC void sc1PGameWaitStageBonus3Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E8F8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018E8FC: lbu         $t7, 0x4AE3($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AE3);
    // 0x8018E900: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E904: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E908: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E90C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E910: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E914: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E918: lwc1        $f4, 0x2EDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2EDC);
    // 0x8018E91C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E920: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E924: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E928: lui         $at, 0x41FC
    ctx->r1 = S32(0X41FC << 16);
    // 0x8018E92C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E934: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018E938: lw          $a0, 0x78($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X78);
    // 0x8018E93C: lui         $a2, 0xBE86
    ctx->r6 = S32(0XBE86 << 16);
    // 0x8018E940: lui         $a3, 0x45DA
    ctx->r7 = S32(0X45DA << 16);
    // 0x8018E944: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8018E948: ori         $a2, $a2, 0xA92
    ctx->r6 = ctx->r6 | 0XA92;
    // 0x8018E94C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018E950: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018E954: jal         0x8010CFA8
    // 0x8018E958: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    gmCameraSetStatusPlayerFollow(rdram, ctx);
        goto after_0;
    // 0x8018E958: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8018E95C: jal         0x8000B1E8
    // 0x8018E960: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8018E960: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // 0x8018E964: jal         0x801120D4
    // 0x8018E968: nop

    ifCommonAnnounceGoMakeInterface(rdram, ctx);
        goto after_2;
    // 0x8018E968: nop

    after_2:
    // 0x8018E96C: jal         0x8010E690
    // 0x8018E970: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_3;
    // 0x8018E970: nop

    after_3:
    // 0x8018E974: jal         0x800269C0
    // 0x8018E978: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8018E978: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_4:
    // 0x8018E97C: jal         0x801121C4
    // 0x8018E980: nop

    ifCommonAnnounceGoSetStatus(rdram, ctx);
        goto after_5;
    // 0x8018E980: nop

    after_5:
    // 0x8018E984: jal         0x80009A84
    // 0x8018E988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_6;
    // 0x8018E988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8018E98C: jal         0x8000B1E8
    // 0x8018E990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_7;
    // 0x8018E990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8018E994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E99C: jr          $ra
    // 0x8018E9A0: nop

    return;
    // 0x8018E9A0: nop

;}
RECOMP_FUNC void mpProcessSetCollideFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD6A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DD6AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DD6B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DD6B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DD6B8: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x800DD6BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DD6C0: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800DD6C4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DD6C8: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800DD6CC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD6D0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800DD6D4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800DD6D8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DD6DC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800DD6E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DD6E4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800DD6E8: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x800DD6EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800DD6F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800DD6F4: jal         0x800F3DD8
    // 0x800DD6F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x800DD6F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800DD6FC: beq         $v0, $zero, L_800DD72C
    if (ctx->r2 == 0) {
        // 0x800DD700: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DD72C;
    }
    // 0x800DD700: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD704: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DD708: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800DD70C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800DD710: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DD714: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800DD718: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DD71C: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800DD720: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x800DD724: b           L_800DD80C
    // 0x800DD728: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
        goto L_800DD80C;
    // 0x800DD728: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
L_800DD72C:
    // 0x800DD72C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800DD730: jal         0x800F4428
    // 0x800DD734: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DD734: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_1:
    // 0x800DD738: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DD73C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DD740: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD744: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800DD748: nop

    // 0x800DD74C: bc1f        L_800DD784
    if (!c1cs) {
        // 0x800DD750: nop
    
            goto L_800DD784;
    }
    // 0x800DD750: nop

    // 0x800DD754: jal         0x800FAA24
    // 0x800DD758: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_2;
    // 0x800DD758: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_2:
    // 0x800DD75C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD760: beq         $v0, $at, L_800DD7B8
    if (ctx->r2 == ctx->r1) {
        // 0x800DD764: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD7B8;
    }
    // 0x800DD764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD768: jal         0x800FA8A4
    // 0x800DD76C: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_3;
    // 0x800DD76C: nop

    after_3:
    // 0x800DD770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DD774: bne         $v0, $at, L_800DD7B8
    if (ctx->r2 != ctx->r1) {
        // 0x800DD778: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800DD7B8;
    }
    // 0x800DD778: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DD77C: b           L_800DD7B8
    // 0x800DD780: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800DD7B8;
    // 0x800DD780: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800DD784:
    // 0x800DD784: jal         0x800F4408
    // 0x800DD788: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x800DD788: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_4:
    // 0x800DD78C: jal         0x800FA964
    // 0x800DD790: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_5;
    // 0x800DD790: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_5:
    // 0x800DD794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD798: beq         $v0, $at, L_800DD7B8
    if (ctx->r2 == ctx->r1) {
        // 0x800DD79C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD7B8;
    }
    // 0x800DD79C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD7A0: jal         0x800FA8A4
    // 0x800DD7A4: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_6;
    // 0x800DD7A4: nop

    after_6:
    // 0x800DD7A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DD7AC: bne         $v0, $at, L_800DD7B8
    if (ctx->r2 != ctx->r1) {
        // 0x800DD7B0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800DD7B8;
    }
    // 0x800DD7B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DD7B4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800DD7B8:
    // 0x800DD7B8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800DD7BC: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800DD7C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DD7C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DD7C8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DD7CC: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800DD7D0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800DD7D4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DD7D8: beql        $t0, $zero, L_800DD810
    if (ctx->r8 == 0) {
        // 0x800DD7DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DD810;
    }
    goto skip_0;
    // 0x800DD7DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DD7E0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800DD7E4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800DD7E8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DD7EC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD7F0: jal         0x800F3DD8
    // 0x800DD7F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_7;
    // 0x800DD7F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_7:
    // 0x800DD7F8: lhu         $t2, 0x5A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DD7FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800DD800: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x800DD804: sh          $t3, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r11;
    // 0x800DD808: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
L_800DD80C:
    // 0x800DD80C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DD810:
    // 0x800DD810: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD814: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DD818: jr          $ra
    // 0x800DD81C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800DD81C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void __n_getRate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800295A8: bnel        $a0, $zero, L_800295DC
    if (ctx->r4 != 0) {
        // 0x800295AC: mtc1        $a0, $f4
        ctx->f4.u32l = ctx->r4;
            goto L_800295DC;
    }
    goto skip_0;
    // 0x800295AC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    skip_0:
    // 0x800295B0: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x800295B4: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800295B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800295BC: bc1f        L_800295D0
    if (!c1cs) {
        // 0x800295C0: nop
    
            goto L_800295D0;
    }
    // 0x800295C0: nop

    // 0x800295C4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800295C8: jr          $ra
    // 0x800295CC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    return;
    // 0x800295CC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800295D0:
    // 0x800295D0: jr          $ra
    // 0x800295D4: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    return;
    // 0x800295D4: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800295D8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800295DC:
    // 0x800295DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800295E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800295E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800295E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800295EC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x800295F0: div.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800295F4: bc1fl       L_80029604
    if (!c1cs) {
        // 0x800295F8: c.le.s      $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl <= ctx->f8.fl;
            goto L_80029604;
    }
    goto skip_1;
    // 0x800295F8: c.le.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl <= ctx->f8.fl;
    skip_1:
    // 0x800295FC: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x80029600: c.le.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl <= ctx->f8.fl;
L_80029604:
    // 0x80029604: nop

    // 0x80029608: bc1fl       L_80029618
    if (!c1cs) {
        // 0x8002960C: sub.s       $f10, $f12, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_80029618;
    }
    goto skip_2;
    // 0x8002960C: sub.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
    skip_2:
    // 0x80029610: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
    // 0x80029614: sub.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
L_80029618:
    // 0x80029618: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002961C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029620: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80029624: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80029628: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002962C: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80029630: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80029634: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80029638: nop

    // 0x8002963C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80029640: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80029644: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80029648: nop

    // 0x8002964C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80029650: lwc1        $f10, -0x148C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X148C);
    // 0x80029654: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80029658: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8002965C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80029660: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80029664: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80029668: nop

    // 0x8002966C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80029670: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80029674: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80029678: nop

    // 0x8002967C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029680: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80029684: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80029688: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002968C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80029690: nop

    // 0x80029694: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029698: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002969C: nop

    // 0x800296A0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800296A4: beql        $t6, $zero, L_800296F4
    if (ctx->r14 == 0) {
        // 0x800296A8: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_800296F4;
    }
    goto skip_3;
    // 0x800296A8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800296AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800296B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800296B4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800296B8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800296BC: nop

    // 0x800296C0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800296C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800296C8: nop

    // 0x800296CC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800296D0: bne         $t6, $zero, L_800296E8
    if (ctx->r14 != 0) {
        // 0x800296D4: nop
    
            goto L_800296E8;
    }
    // 0x800296D4: nop

    // 0x800296D8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800296DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800296E0: b           L_80029700
    // 0x800296E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80029700;
    // 0x800296E4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800296E8:
    // 0x800296E8: b           L_80029700
    // 0x800296EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80029700;
    // 0x800296EC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800296F0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_800296F4:
    // 0x800296F4: nop

    // 0x800296F8: bltz        $t6, L_800296E8
    if (SIGNED(ctx->r14) < 0) {
        // 0x800296FC: nop
    
            goto L_800296E8;
    }
    // 0x800296FC: nop

L_80029700:
    // 0x80029700: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80029704: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80029708: addu        $v0, $t9, $a0
    ctx->r2 = ADD32(ctx->r25, ctx->r4);
    // 0x8002970C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80029710: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80029714: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80029718: jr          $ra
    // 0x8002971C: nop

    return;
    // 0x8002971C: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A0DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013A0E0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A0E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8013A0E8: lw          $t7, -0x4270($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4270);
    // 0x8013A0EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013A0F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013A0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8013A0F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013A0FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A100: beq         $v0, $t7, L_8013A198
    if (ctx->r2 == ctx->r15) {
        // 0x8013A104: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8013A198;
    }
    // 0x8013A104: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013A108: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8013A10C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8013A110: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8013A114: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8013A118: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013A11C: addiu       $t9, $t9, -0x4578
    ctx->r25 = ADD32(ctx->r25, -0X4578);
    // 0x8013A120: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013A124: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8013A128: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8013A12C: bnel        $t0, $zero, L_8013A294
    if (ctx->r8 != 0) {
        // 0x8013A130: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013A294;
    }
    goto skip_0;
    // 0x8013A130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013A134: jal         0x80138DEC
    // 0x8013A138: nop

    mnPlayersVSMakeCursor(rdram, ctx);
        goto after_0;
    // 0x8013A138: nop

    after_0:
    // 0x8013A13C: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x8013A140: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013A148: beql        $t1, $at, L_8013A294
    if (ctx->r9 == ctx->r1) {
        // 0x8013A14C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013A294;
    }
    goto skip_1;
    // 0x8013A14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013A150: jal         0x80135C84
    // 0x8013A154: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    mnPlayersVSUpdatePlayerKind(rdram, ctx);
        goto after_1;
    // 0x8013A154: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    after_1:
    // 0x8013A158: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8013A15C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013A160: jal         0x8013295C
    // 0x8013A164: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSUpdatePlayerKindSelect(rdram, ctx);
        goto after_2;
    // 0x8013A164: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_2:
    // 0x8013A168: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8013A16C: jal         0x80136038
    // 0x8013A170: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdatePuckDisplay(rdram, ctx);
        goto after_3;
    // 0x8013A170: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8013A174: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8013A178: jal         0x801361F8
    // 0x8013A17C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdateCursorDisplay(rdram, ctx);
        goto after_4;
    // 0x8013A17C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8013A180: jal         0x80136128
    // 0x8013A184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateFighter(rdram, ctx);
        goto after_5;
    // 0x8013A184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8013A188: jal         0x80136300
    // 0x8013A18C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_6;
    // 0x8013A18C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8013A190: b           L_8013A294
    // 0x8013A194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013A294;
    // 0x8013A194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013A198:
    // 0x8013A198: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8013A19C: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8013A1A0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8013A1A4: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8013A1A8: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x8013A1AC: addiu       $t3, $t3, -0x4578
    ctx->r11 = ADD32(ctx->r11, -0X4578);
    // 0x8013A1B0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8013A1B4: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x8013A1B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8013A1BC: beql        $a0, $zero, L_8013A294
    if (ctx->r4 == 0) {
        // 0x8013A1C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013A294;
    }
    goto skip_2;
    // 0x8013A1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013A1C4: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x8013A1C8: beq         $v0, $a2, L_8013A230
    if (ctx->r2 == ctx->r6) {
        // 0x8013A1CC: nop
    
            goto L_8013A230;
    }
    // 0x8013A1CC: nop

    // 0x8013A1D0: bne         $s1, $a2, L_8013A1E8
    if (ctx->r17 != ctx->r6) {
        // 0x8013A1D4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8013A1E8;
    }
    // 0x8013A1D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013A1D8: lw          $t4, 0x84($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X84);
    // 0x8013A1DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A1E0: bne         $t4, $at, L_8013A230
    if (ctx->r12 != ctx->r1) {
        // 0x8013A1E4: nop
    
            goto L_8013A230;
    }
    // 0x8013A1E4: nop

L_8013A1E8:
    // 0x8013A1E8: jal         0x8013718C
    // 0x8013A1EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    mnPlayersVSSelectFighter(rdram, ctx);
        goto after_7;
    // 0x8013A1EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_7:
    // 0x8013A1F0: bne         $v0, $zero, L_8013A230
    if (ctx->r2 != 0) {
        // 0x8013A1F4: nop
    
            goto L_8013A230;
    }
    // 0x8013A1F4: nop

    // 0x8013A1F8: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x8013A1FC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A200: addiu       $t6, $t6, -0x4578
    ctx->r14 = ADD32(ctx->r14, -0X4578);
    // 0x8013A204: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8013A208: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8013A20C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8013A210: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8013A214: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8013A218: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8013A21C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8013A220: jal         0x80138848
    // 0x8013A224: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    mnPlayersVSRandFighterKind(rdram, ctx);
        goto after_8;
    // 0x8013A224: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_8:
    // 0x8013A228: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013A22C: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
L_8013A230:
    // 0x8013A230: jal         0x80009A84
    // 0x8013A234: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    gcEjectGObj(rdram, ctx);
        goto after_9;
    // 0x8013A234: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x8013A238: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x8013A23C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A240: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8013A244: beq         $t7, $at, L_8013A290
    if (ctx->r15 == ctx->r1) {
        // 0x8013A248: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8013A290;
    }
    // 0x8013A248: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013A24C: sw          $t8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r24;
    // 0x8013A250: jal         0x80135C84
    // 0x8013A254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdatePlayerKind(rdram, ctx);
        goto after_10;
    // 0x8013A254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8013A258: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8013A25C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8013A260: jal         0x8013295C
    // 0x8013A264: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSUpdatePlayerKindSelect(rdram, ctx);
        goto after_11;
    // 0x8013A264: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_11:
    // 0x8013A268: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8013A26C: jal         0x80136038
    // 0x8013A270: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdatePuckDisplay(rdram, ctx);
        goto after_12;
    // 0x8013A270: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x8013A274: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8013A278: jal         0x801361F8
    // 0x8013A27C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdateCursorDisplay(rdram, ctx);
        goto after_13;
    // 0x8013A27C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8013A280: jal         0x80136128
    // 0x8013A284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateFighter(rdram, ctx);
        goto after_14;
    // 0x8013A284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8013A288: jal         0x80136300
    // 0x8013A28C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_15;
    // 0x8013A28C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
L_8013A290:
    // 0x8013A290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013A294:
    // 0x8013A294: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013A298: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013A29C: jr          $ra
    // 0x8013A2A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013A2A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbyThrowFLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A5AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014A5B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A5B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014A5B8: jal         0x800DEE98
    // 0x8014A5BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014A5BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014A5C0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8014A5C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014A5C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014A5CC: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8014A5D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014A5D4: jal         0x800E6F24
    // 0x8014A5D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014A5D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014A5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A5E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014A5E4: jr          $ra
    // 0x8014A5E8: nop

    return;
    // 0x8014A5E8: nop

;}
RECOMP_FUNC void ftCommonCliffClimbOrFallCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014508C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80145090: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80145094: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x80145098: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014509C: bgez        $v0, L_801450AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801450A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801450AC;
    }
    // 0x801450A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801450A4: b           L_801450AC
    // 0x801450A8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801450AC;
    // 0x801450A8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801450AC:
    // 0x801450AC: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801450B0: beql        $at, $zero, L_801450E0
    if (ctx->r1 == 0) {
        // 0x801450B4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_801450E0;
    }
    goto skip_0;
    // 0x801450B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x801450B8: lb          $v0, 0x1C3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C3);
    // 0x801450BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801450C0: bgez        $v0, L_801450D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801450C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801450D0;
    }
    // 0x801450C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801450C8: b           L_801450D0
    // 0x801450CC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801450D0;
    // 0x801450CC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801450D0:
    // 0x801450D0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801450D4: bne         $at, $zero, L_80145194
    if (ctx->r1 != 0) {
        // 0x801450D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80145194;
    }
    // 0x801450D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801450DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_801450E0:
    // 0x801450E0: jal         0x800E8000
    // 0x801450E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x801450E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x801450E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801450EC: lwc1        $f4, -0x3E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3E80);
    // 0x801450F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801450F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801450F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801450FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80145100: bc1tl       L_80145138
    if (c1cs) {
        // 0x80145104: lw          $t9, 0xB18($a1)
        ctx->r25 = MEM_W(ctx->r5, 0XB18);
            goto L_80145138;
    }
    goto skip_1;
    // 0x80145104: lw          $t9, 0xB18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XB18);
    skip_1:
    // 0x80145108: lwc1        $f6, -0x3E7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3E7C);
    // 0x8014510C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80145110: nop

    // 0x80145114: bc1fl       L_80145160
    if (!c1cs) {
        // 0x80145118: lw          $t0, 0xB18($a1)
        ctx->r8 = MEM_W(ctx->r5, 0XB18);
            goto L_80145160;
    }
    goto skip_2;
    // 0x80145118: lw          $t0, 0xB18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XB18);
    skip_2:
    // 0x8014511C: lb          $t6, 0x1C2($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C2);
    // 0x80145120: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x80145124: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80145128: mflo        $t8
    ctx->r24 = lo;
    // 0x8014512C: bltzl       $t8, L_80145160
    if (SIGNED(ctx->r24) < 0) {
        // 0x80145130: lw          $t0, 0xB18($a1)
        ctx->r8 = MEM_W(ctx->r5, 0XB18);
            goto L_80145160;
    }
    goto skip_3;
    // 0x80145130: lw          $t0, 0xB18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XB18);
    skip_3:
    // 0x80145134: lw          $t9, 0xB18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XB18);
L_80145138:
    // 0x80145138: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014513C: beq         $t9, $zero, L_80145154
    if (ctx->r25 == 0) {
        // 0x80145140: nop
    
            goto L_80145154;
    }
    // 0x80145140: nop

    // 0x80145144: jal         0x80144FE8
    // 0x80145148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftCommonCliffQuickOrSlowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80145148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8014514C: b           L_80145198
    // 0x80145150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80145198;
    // 0x80145150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80145154:
    // 0x80145154: b           L_80145198
    // 0x80145158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80145198;
    // 0x80145158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014515C: lw          $t0, 0xB18($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XB18);
L_80145160:
    // 0x80145160: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80145164: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80145168: beq         $t0, $zero, L_8014518C
    if (ctx->r8 == 0) {
        // 0x8014516C: nop
    
            goto L_8014518C;
    }
    // 0x8014516C: nop

    // 0x80145170: sw          $t1, 0x15C($a1)
    MEM_W(0X15C, ctx->r5) = ctx->r9;
    // 0x80145174: jal         0x80144CF8
    // 0x80145178: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonCliffCommonProcDamage(rdram, ctx);
        goto after_2;
    // 0x80145178: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014517C: jal         0x8013F9E0
    // 0x80145180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_3;
    // 0x80145180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80145184: b           L_80145198
    // 0x80145188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80145198;
    // 0x80145188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014518C:
    // 0x8014518C: b           L_80145198
    // 0x80145190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80145198;
    // 0x80145190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80145194:
    // 0x80145194: sw          $t2, 0xB18($a1)
    MEM_W(0XB18, ctx->r5) = ctx->r10;
L_80145198:
    // 0x80145198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014519C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801451A0: jr          $ra
    // 0x801451A4: nop

    return;
    // 0x801451A4: nop

;}
RECOMP_FUNC void func_ovl26_801345F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345F8: jr          $ra
    // 0x801345FC: nop

    return;
    // 0x801345FC: nop

;}
RECOMP_FUNC void func_ovl8_8037D9EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D9EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D9F0: sh          $a0, -0xFBC($at)
    MEM_H(-0XFBC, ctx->r1) = ctx->r4;
    // 0x8037D9F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D9F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037D9FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037DA00: jr          $ra
    // 0x8037DA04: sh          $a1, -0xFBA($at)
    MEM_H(-0XFBA, ctx->r1) = ctx->r5;
    return;
    // 0x8037DA04: sh          $a1, -0xFBA($at)
    MEM_H(-0XFBA, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void lbCommonFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C863C: jal         0x8000A5E4
    // 0x800C8640: nop

    gcRunAll(rdram, ctx);
        goto after_0;
    // 0x800C8640: nop

    after_0:
    // 0x800C8644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C864C: jr          $ra
    // 0x800C8650: nop

    return;
    // 0x800C8650: nop

;}
RECOMP_FUNC void gmCameraGetBoundsMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B810: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B814: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8010B818: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8010B81C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010B820: lh          $t6, 0x72($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X72);
    // 0x8010B824: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010B828: nop

    // 0x8010B82C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B830: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8010B834: nop

    // 0x8010B838: bc1fl       L_8010B848
    if (!c1cs) {
        // 0x8010B83C: lh          $t7, 0x70($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X70);
            goto L_8010B848;
    }
    goto skip_0;
    // 0x8010B83C: lh          $t7, 0x70($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X70);
    skip_0:
    // 0x8010B840: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010B844: lh          $t7, 0x70($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X70);
L_8010B848:
    // 0x8010B848: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010B84C: nop

    // 0x8010B850: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010B854: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8010B858: nop

    // 0x8010B85C: bc1fl       L_8010B86C
    if (!c1cs) {
        // 0x8010B860: lh          $t8, 0x6E($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X6E);
            goto L_8010B86C;
    }
    goto skip_1;
    // 0x8010B860: lh          $t8, 0x6E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6E);
    skip_1:
    // 0x8010B864: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8010B868: lh          $t8, 0x6E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6E);
L_8010B86C:
    // 0x8010B86C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010B870: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8010B874: nop

    // 0x8010B878: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010B87C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8010B880: nop

    // 0x8010B884: bc1fl       L_8010B894
    if (!c1cs) {
        // 0x8010B888: lh          $t9, 0x6C($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X6C);
            goto L_8010B894;
    }
    goto skip_2;
    // 0x8010B888: lh          $t9, 0x6C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6C);
    skip_2:
    // 0x8010B88C: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8010B890: lh          $t9, 0x6C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6C);
L_8010B894:
    // 0x8010B894: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8010B898: nop

    // 0x8010B89C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B8A0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8010B8A4: nop

    // 0x8010B8A8: bc1f        L_8010B8B4
    if (!c1cs) {
        // 0x8010B8AC: nop
    
            goto L_8010B8B4;
    }
    // 0x8010B8AC: nop

    // 0x8010B8B0: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_8010B8B4:
    // 0x8010B8B4: jr          $ra
    // 0x8010B8B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010B8B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_8037D000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D000: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037D004: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8037D008: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8037D00C: lhu         $t6, 0x5472($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5472);
    // 0x8037D010: lhu         $t7, 0x5474($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X5474);
    // 0x8037D014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D018: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8037D01C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8037D020: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8037D024: jal         0x8037726C
    // 0x8037D028: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    func_ovl8_8037726C(rdram, ctx);
        goto after_0;
    // 0x8037D028: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    after_0:
    // 0x8037D02C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037D030: lw          $t8, -0x5798($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5798);
    // 0x8037D034: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037D038: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8037D03C: bne         $t8, $zero, L_8037D04C
    if (ctx->r24 != 0) {
        // 0x8037D040: lw          $t9, -0x5794($t9)
        ctx->r25 = MEM_W(ctx->r25, -0X5794);
            goto L_8037D04C;
    }
    // 0x8037D040: lw          $t9, -0x5794($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5794);
    // 0x8037D044: beql        $t9, $zero, L_8037D0D4
    if (ctx->r25 == 0) {
        // 0x8037D048: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8037D0D4;
    }
    goto skip_0;
    // 0x8037D048: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    skip_0:
L_8037D04C:
    // 0x8037D04C: jal         0x80034D50
    // 0x8037D050: nop

    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8037D050: nop

    after_1:
    // 0x8037D054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D058: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D05C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D060: jal         0x80030B18
    // 0x8037D064: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_2;
    // 0x8037D064: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_2:
    // 0x8037D068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D06C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D070: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D074: jal         0x80030A18
    // 0x8037D078: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x8037D078: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_3:
    // 0x8037D07C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037D080: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037D084: lw          $t3, -0x5794($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5794);
    // 0x8037D088: lw          $t2, -0x5798($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5798);
    // 0x8037D08C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037D090: lw          $t0, -0x5788($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5788);
    // 0x8037D094: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8037D098: subu        $t4, $v0, $t2
    ctx->r12 = SUB32(ctx->r2, ctx->r10);
    // 0x8037D09C: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x8037D0A0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037D0A4: sltu        $at, $t4, $t0
    ctx->r1 = ctx->r12 < ctx->r8 ? 1 : 0;
    // 0x8037D0A8: lw          $t1, -0x5784($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5784);
    // 0x8037D0AC: bne         $at, $zero, L_8037D0D0
    if (ctx->r1 != 0) {
        // 0x8037D0B0: subu        $t5, $v1, $t3
        ctx->r13 = SUB32(ctx->r3, ctx->r11);
            goto L_8037D0D0;
    }
    // 0x8037D0B0: subu        $t5, $v1, $t3
    ctx->r13 = SUB32(ctx->r3, ctx->r11);
    // 0x8037D0B4: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x8037D0B8: bne         $at, $zero, L_8037D0CC
    if (ctx->r1 != 0) {
        // 0x8037D0BC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8037D0CC;
    }
    // 0x8037D0BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037D0C0: sltu        $at, $t1, $t5
    ctx->r1 = ctx->r9 < ctx->r13 ? 1 : 0;
    // 0x8037D0C4: beql        $at, $zero, L_8037D0D4
    if (ctx->r1 == 0) {
        // 0x8037D0C8: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8037D0D4;
    }
    goto skip_1;
    // 0x8037D0C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    skip_1:
L_8037D0CC:
    // 0x8037D0CC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
L_8037D0D0:
    // 0x8037D0D0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_8037D0D4:
    // 0x8037D0D4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8037D0D8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8037D0DC: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8037D0E0: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8037D0E4: jal         0x8037D28C
    // 0x8037D0E8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    func_ovl8_8037D28C(rdram, ctx);
        goto after_4;
    // 0x8037D0E8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    after_4:
    // 0x8037D0EC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8037D0F0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8037D0F4: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037D0F8: sltu        $t0, $zero, $t3
    ctx->r8 = 0 < ctx->r11 ? 1 : 0;
    // 0x8037D0FC: beq         $t0, $zero, L_8037D1C0
    if (ctx->r8 == 0) {
        // 0x8037D100: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8037D1C0;
    }
    // 0x8037D100: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8037D104: jal         0x80034D50
    // 0x8037D108: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x8037D108: nop

    after_5:
    // 0x8037D10C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D110: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D118: jal         0x80030B18
    // 0x8037D11C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x8037D11C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x8037D120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D124: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D128: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D12C: jal         0x80030A18
    // 0x8037D130: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x8037D130: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_7:
    // 0x8037D134: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037D138: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D13C: lw          $t6, -0x5798($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5798);
    // 0x8037D140: lw          $t4, -0x5790($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5790);
    // 0x8037D144: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037D148: lw          $t5, -0x578C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X578C);
    // 0x8037D14C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037D150: lw          $t7, -0x5794($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5794);
    // 0x8037D154: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8037D158: bne         $t4, $t6, L_8037D164
    if (ctx->r12 != ctx->r14) {
        // 0x8037D15C: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_8037D164;
    }
    // 0x8037D15C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8037D160: beq         $t5, $t7, L_8037D1A0
    if (ctx->r13 == ctx->r15) {
        // 0x8037D164: lui         $t8, 0x8039
        ctx->r24 = S32(0X8039 << 16);
            goto L_8037D1A0;
    }
L_8037D164:
    // 0x8037D164: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037D168: lw          $t8, -0x5780($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5780);
    // 0x8037D16C: sltu        $at, $v1, $t5
    ctx->r1 = ctx->r3 < ctx->r13 ? 1 : 0;
    // 0x8037D170: subu        $t2, $v0, $t4
    ctx->r10 = SUB32(ctx->r2, ctx->r12);
    // 0x8037D174: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8037D178: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037D17C: sltu        $at, $t2, $t8
    ctx->r1 = ctx->r10 < ctx->r24 ? 1 : 0;
    // 0x8037D180: lw          $t9, -0x577C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X577C);
    // 0x8037D184: bne         $at, $zero, L_8037D1F0
    if (ctx->r1 != 0) {
        // 0x8037D188: subu        $t3, $v1, $t5
        ctx->r11 = SUB32(ctx->r3, ctx->r13);
            goto L_8037D1F0;
    }
    // 0x8037D188: subu        $t3, $v1, $t5
    ctx->r11 = SUB32(ctx->r3, ctx->r13);
    // 0x8037D18C: sltu        $at, $t8, $t2
    ctx->r1 = ctx->r24 < ctx->r10 ? 1 : 0;
    // 0x8037D190: bne         $at, $zero, L_8037D1A0
    if (ctx->r1 != 0) {
        // 0x8037D194: sltu        $at, $t9, $t3
        ctx->r1 = ctx->r25 < ctx->r11 ? 1 : 0;
            goto L_8037D1A0;
    }
    // 0x8037D194: sltu        $at, $t9, $t3
    ctx->r1 = ctx->r25 < ctx->r11 ? 1 : 0;
    // 0x8037D198: beql        $at, $zero, L_8037D1F4
    if (ctx->r1 == 0) {
        // 0x8037D19C: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8037D1F4;
    }
    goto skip_2;
    // 0x8037D19C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_8037D1A0:
    // 0x8037D1A0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8037D1A4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8037D1A8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D1AC: sw          $v0, -0x5790($at)
    MEM_W(-0X5790, ctx->r1) = ctx->r2;
    // 0x8037D1B0: or          $t6, $t1, $t0
    ctx->r14 = ctx->r9 | ctx->r8;
    // 0x8037D1B4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x8037D1B8: b           L_8037D1F0
    // 0x8037D1BC: sw          $v1, -0x578C($at)
    MEM_W(-0X578C, ctx->r1) = ctx->r3;
        goto L_8037D1F0;
    // 0x8037D1BC: sw          $v1, -0x578C($at)
    MEM_W(-0X578C, ctx->r1) = ctx->r3;
L_8037D1C0:
    // 0x8037D1C0: lw          $t4, -0x5798($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5798);
    // 0x8037D1C4: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037D1C8: lw          $t5, -0x5794($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5794);
    // 0x8037D1CC: bnel        $t4, $zero, L_8037D1F4
    if (ctx->r12 != 0) {
        // 0x8037D1D0: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8037D1F4;
    }
    goto skip_3;
    // 0x8037D1D0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8037D1D4: bne         $t5, $zero, L_8037D1F0
    if (ctx->r13 != 0) {
        // 0x8037D1D8: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8037D1F0;
    }
    // 0x8037D1D8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8037D1DC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8037D1E0: or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // 0x8037D1E4: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8037D1E8: or          $t2, $t9, $v0
    ctx->r10 = ctx->r25 | ctx->r2;
    // 0x8037D1EC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_8037D1F0:
    // 0x8037D1F0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8037D1F4:
    // 0x8037D1F4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8037D1F8: bne         $t3, $zero, L_8037D258
    if (ctx->r11 != 0) {
        // 0x8037D1FC: srl         $t0, $t1, 16
        ctx->r8 = S32(U32(ctx->r9) >> 16);
            goto L_8037D258;
    }
    // 0x8037D1FC: srl         $t0, $t1, 16
    ctx->r8 = S32(U32(ctx->r9) >> 16);
    // 0x8037D200: beql        $t0, $zero, L_8037D25C
    if (ctx->r8 == 0) {
        // 0x8037D204: lw          $t4, 0x4C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X4C);
            goto L_8037D25C;
    }
    goto skip_4;
    // 0x8037D204: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x8037D208: jal         0x80034D50
    // 0x8037D20C: nop

    osGetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8037D20C: nop

    after_8:
    // 0x8037D210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D214: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D218: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D21C: jal         0x80030B18
    // 0x8037D220: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_9;
    // 0x8037D220: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_9:
    // 0x8037D224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037D228: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8037D22C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8037D230: jal         0x80030A18
    // 0x8037D234: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_10;
    // 0x8037D234: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_10:
    // 0x8037D238: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037D23C: addiu       $a0, $a0, -0x5790
    ctx->r4 = ADD32(ctx->r4, -0X5790);
    // 0x8037D240: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8037D244: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8037D248: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D24C: sw          $v0, -0x5798($at)
    MEM_W(-0X5798, ctx->r1) = ctx->r2;
    // 0x8037D250: b           L_8037D274
    // 0x8037D254: sw          $v1, -0x5794($at)
    MEM_W(-0X5794, ctx->r1) = ctx->r3;
        goto L_8037D274;
    // 0x8037D254: sw          $v1, -0x5794($at)
    MEM_W(-0X5794, ctx->r1) = ctx->r3;
L_8037D258:
    // 0x8037D258: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
L_8037D25C:
    // 0x8037D25C: bne         $t4, $zero, L_8037D274
    if (ctx->r12 != 0) {
        // 0x8037D260: lui         $at, 0x8039
        ctx->r1 = S32(0X8039 << 16);
            goto L_8037D274;
    }
    // 0x8037D260: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D264: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8037D268: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8037D26C: sw          $t9, -0x5794($at)
    MEM_W(-0X5794, ctx->r1) = ctx->r25;
    // 0x8037D270: sw          $t8, -0x5798($at)
    MEM_W(-0X5798, ctx->r1) = ctx->r24;
L_8037D274:
    // 0x8037D274: jal         0x8037D3DC
    // 0x8037D278: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_ovl8_8037D3DC(rdram, ctx);
        goto after_11;
    // 0x8037D278: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_11:
    // 0x8037D27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037D280: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8037D284: jr          $ra
    // 0x8037D288: nop

    return;
    // 0x8037D288: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157614: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80157618: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015761C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157620: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80157624: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80157628: bnel        $t7, $zero, L_80157644
    if (ctx->r15 != 0) {
        // 0x8015762C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80157644;
    }
    goto skip_0;
    // 0x8015762C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    skip_0:
    // 0x80157630: jal         0x800DEEC8
    // 0x80157634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80157634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80157638: jal         0x800D8EB8
    // 0x8015763C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_1;
    // 0x8015763C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80157640: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_80157644:
    // 0x80157644: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80157648: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015764C: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x80157650: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157654: jal         0x800E6F24
    // 0x80157658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80157658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8015765C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80157660: addiu       $t9, $t9, 0x6E98
    ctx->r25 = ADD32(ctx->r25, 0X6E98);
    // 0x80157664: sw          $t9, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r25;
    // 0x80157668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015766C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80157670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157674: jr          $ra
    // 0x80157678: nop

    return;
    // 0x80157678: nop

;}
RECOMP_FUNC void mnVSOptionsMakeTintCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133558: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013355C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133560: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133564: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133568: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x8013356C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133570: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80133574: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133578: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013357C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133580: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133584: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133588: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013358C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133590: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133594: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133598: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013359C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801335A0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801335A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801335A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801335AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801335B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335B4: jal         0x8000B93C
    // 0x801335B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801335B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801335BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801335C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801335C4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801335C8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801335CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801335D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335D8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801335DC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801335E0: jal         0x80007080
    // 0x801335E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801335E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801335E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801335EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801335F0: jr          $ra
    // 0x801335F4: nop

    return;
    // 0x801335F4: nop

;}
RECOMP_FUNC void mvOpeningRoomEjectRoomGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801331B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801331B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331BC: jal         0x80009A84
    // 0x801331C0: lw          $a0, 0x4D18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D18);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801331C0: lw          $a0, 0x4D18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D18);
    after_0:
    // 0x801331C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331C8: jal         0x80009A84
    // 0x801331CC: lw          $a0, 0x4D1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D1C);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x801331CC: lw          $a0, 0x4D1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D1C);
    after_1:
    // 0x801331D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331D4: jal         0x80009A84
    // 0x801331D8: lw          $a0, 0x4D20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x801331D8: lw          $a0, 0x4D20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D20);
    after_2:
    // 0x801331DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331E0: jal         0x80009A84
    // 0x801331E4: lw          $a0, 0x4D24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D24);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x801331E4: lw          $a0, 0x4D24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D24);
    after_3:
    // 0x801331E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331EC: jal         0x80009A84
    // 0x801331F0: lw          $a0, 0x4D28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D28);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x801331F0: lw          $a0, 0x4D28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D28);
    after_4:
    // 0x801331F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801331F8: jal         0x80009A84
    // 0x801331FC: lw          $a0, 0x4D2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D2C);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x801331FC: lw          $a0, 0x4D2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D2C);
    after_5:
    // 0x80133200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133208: jr          $ra
    // 0x8013320C: nop

    return;
    // 0x8013320C: nop

;}
RECOMP_FUNC void mnScreenAdjustMakeInstruction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131DD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131DD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131DE0: jal         0x80009968
    // 0x80131DE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131DE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131DE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131DEC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131DF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131DF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131DF8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131DFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E04: jal         0x80009DF4
    // 0x80131E08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131E0C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131E10: lw          $t7, 0x2A38($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2A38);
    // 0x80131E14: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131E18: addiu       $t8, $t8, 0x918
    ctx->r24 = ADD32(ctx->r24, 0X918);
    // 0x80131E1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E20: jal         0x800CCFDC
    // 0x80131E24: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131E24: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131E28: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E2C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80131E30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131E34: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x80131E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E3C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131E40: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131E44: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131E48: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131E4C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131E50: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131E54: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131E58: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131E5C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131E60: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E6C: jr          $ra
    // 0x80131E70: nop

    return;
    // 0x80131E70: nop

;}
RECOMP_FUNC void ftNessSpecialHiHoldInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801542F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801542F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801542FC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80154300: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80154304: jal         0x80153C88
    // 0x80154308: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftNessSpecialHiMakePKThunder(rdram, ctx);
        goto after_0;
    // 0x80154308: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015430C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80154310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154314: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x80154318: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x8015431C: bltzl       $t8, L_80154344
    if (SIGNED(ctx->r24) < 0) {
        // 0x80154320: lw          $t2, 0x9C8($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X9C8);
            goto L_80154344;
    }
    goto skip_0;
    // 0x80154320: lw          $t2, 0x9C8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X9C8);
    skip_0:
    // 0x80154324: jal         0x801029F8
    // 0x80154328: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerNessPKThunderWaveMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80154328: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8015432C: beq         $v0, $zero, L_80154340
    if (ctx->r2 == 0) {
        // 0x80154330: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80154340;
    }
    // 0x80154330: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80154334: lbu         $t0, 0x18F($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18F);
    // 0x80154338: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8015433C: sb          $t1, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r9;
L_80154340:
    // 0x80154340: lw          $t2, 0x9C8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X9C8);
L_80154344:
    // 0x80154344: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x80154348: sb          $t3, 0x148($v1)
    MEM_B(0X148, ctx->r3) = ctx->r11;
    // 0x8015434C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154354: jr          $ra
    // 0x80154358: nop

    return;
    // 0x80154358: nop

;}
RECOMP_FUNC void itMSBombFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801764D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801764D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801764D8: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x801764DC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801764E0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801764E4: addiu       $a3, $a3, 0x6504
    ctx->r7 = ADD32(ctx->r7, 0X6504);
    // 0x801764E8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801764EC: jal         0x80173B24
    // 0x801764F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801764F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x801764F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801764F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801764FC: jr          $ra
    // 0x80176500: nop

    return;
    // 0x80176500: nop

;}
RECOMP_FUNC void ftMainUpdateDamageStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3418: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E341C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E3420: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E3424: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E3428: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E342C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E3430: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E3434: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800E3438: jal         0x80168128
    // 0x800E343C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x800E343C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E3440: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800E3444: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x800E3448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E344C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E3450: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800E3454: bgez        $t8, L_800E3464
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E3458: lw          $a2, 0x60($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X60);
            goto L_800E3464;
    }
    // 0x800E3458: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800E345C: b           L_800E3468
    // 0x800E3460: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
        goto L_800E3468;
    // 0x800E3460: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_800E3464:
    // 0x800E3464: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800E3468:
    // 0x800E3468: jal         0x8016679C
    // 0x800E346C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E346C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800E3470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E3474: jal         0x800EA40C
    // 0x800E3478: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    ftParamGetCapturedDamage(rdram, ctx);
        goto after_2;
    // 0x800E3478: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x800E347C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800E3480: lw          $t9, 0x48($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X48);
    // 0x800E3484: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E3488: bgezl       $t1, L_800E34AC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E348C: lw          $t3, 0x234($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X234);
            goto L_800E34AC;
    }
    goto skip_0;
    // 0x800E348C: lw          $t3, 0x234($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X234);
    skip_0:
    // 0x800E3490: lw          $t2, 0x238($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X238);
    // 0x800E3494: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E3498: beql        $at, $zero, L_800E34C0
    if (ctx->r1 == 0) {
        // 0x800E349C: lw          $t4, 0x5AC($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X5AC);
            goto L_800E34C0;
    }
    goto skip_1;
    // 0x800E349C: lw          $t4, 0x5AC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X5AC);
    skip_1:
    // 0x800E34A0: b           L_800E34BC
    // 0x800E34A4: sw          $v0, 0x238($s0)
    MEM_W(0X238, ctx->r16) = ctx->r2;
        goto L_800E34BC;
    // 0x800E34A4: sw          $v0, 0x238($s0)
    MEM_W(0X238, ctx->r16) = ctx->r2;
    // 0x800E34A8: lw          $t3, 0x234($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X234);
L_800E34AC:
    // 0x800E34AC: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E34B0: beql        $at, $zero, L_800E34C0
    if (ctx->r1 == 0) {
        // 0x800E34B4: lw          $t4, 0x5AC($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X5AC);
            goto L_800E34C0;
    }
    goto skip_2;
    // 0x800E34B4: lw          $t4, 0x5AC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X5AC);
    skip_2:
    // 0x800E34B8: sw          $v0, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r2;
L_800E34BC:
    // 0x800E34BC: lw          $t4, 0x5AC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X5AC);
L_800E34C0:
    // 0x800E34C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E34C4: bne         $v0, $t4, L_800E359C
    if (ctx->r2 != ctx->r12) {
        // 0x800E34C8: nop
    
            goto L_800E359C;
    }
    // 0x800E34C8: nop

    // 0x800E34CC: lw          $t5, 0x5B4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X5B4);
    // 0x800E34D0: bne         $v0, $t5, L_800E359C
    if (ctx->r2 != ctx->r13) {
        // 0x800E34D4: nop
    
            goto L_800E359C;
    }
    // 0x800E34D4: nop

    // 0x800E34D8: lw          $t6, 0x5B8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X5B8);
    // 0x800E34DC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800E34E0: bne         $v0, $t6, L_800E359C
    if (ctx->r2 != ctx->r14) {
        // 0x800E34E4: nop
    
            goto L_800E359C;
    }
    // 0x800E34E4: nop

    // 0x800E34E8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800E34EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E34F0: bne         $v0, $t8, L_800E359C
    if (ctx->r2 != ctx->r24) {
        // 0x800E34F4: nop
    
            goto L_800E359C;
    }
    // 0x800E34F4: nop

    // 0x800E34F8: jal         0x800E2CC0
    // 0x800E34FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    ftMainCheckGetUpdateDamage(rdram, ctx);
        goto after_3;
    // 0x800E34FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x800E3500: beq         $v0, $zero, L_800E359C
    if (ctx->r2 == 0) {
        // 0x800E3504: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E359C;
    }
    // 0x800E3504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3508: addiu       $a0, $a0, 0x11C0
    ctx->r4 = ADD32(ctx->r4, 0X11C0);
    // 0x800E350C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E3510: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800E3514: addiu       $t0, $t0, 0x11C8
    ctx->r8 = ADD32(ctx->r8, 0X11C8);
    // 0x800E3518: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800E351C: beq         $at, $zero, L_800E3570
    if (ctx->r1 == 0) {
        // 0x800E3520: sll         $t9, $v1, 3
        ctx->r25 = S32(ctx->r3 << 3);
            goto L_800E3570;
    }
    // 0x800E3520: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800E3524: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x800E3528: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E352C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800E3530: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800E3534: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800E3538: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x800E353C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800E3540: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800E3544: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800E3548: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800E354C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800E3550: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x800E3554: lbu         $t5, 0x11($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X11);
    // 0x800E3558: sb          $t5, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r13;
    // 0x800E355C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800E3560: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x800E3564: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800E3568: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E356C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800E3570:
    // 0x800E3570: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    // 0x800E3574: lbu         $a1, 0xD($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XD);
    // 0x800E3578: jal         0x800EA98C
    // 0x800E357C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_4;
    // 0x800E357C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800E3580: lw          $a2, 0x48($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X48);
    // 0x800E3584: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    // 0x800E3588: lbu         $a1, 0xD($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XD);
    // 0x800E358C: sll         $a2, $a2, 9
    ctx->r6 = S32(ctx->r6 << 9);
    // 0x800E3590: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    // 0x800E3594: jal         0x800EA614
    // 0x800E3598: lhu         $a3, 0x4A($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X4A);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_5;
    // 0x800E3598: lhu         $a3, 0x4A($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X4A);
    after_5:
L_800E359C:
    // 0x800E359C: jal         0x800269C0
    // 0x800E35A0: lhu         $a0, 0x46($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X46);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x800E35A0: lhu         $a0, 0x46($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X46);
    after_6:
    // 0x800E35A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E35A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E35AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E35B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E35B4: jr          $ra
    // 0x800E35B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E35B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void n_alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FCF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FCF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FCFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002FD00: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002FD04: beql        $t6, $zero, L_8002FD70
    if (ctx->r14 == 0) {
        // 0x8002FD08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FD70;
    }
    goto skip_0;
    // 0x8002FD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FD0C: jal         0x8002C618
    // 0x8002FD10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002FD10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FD14: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002FD18: beq         $v0, $zero, L_8002FD6C
    if (ctx->r2 == 0) {
        // 0x8002FD1C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002FD6C;
    }
    // 0x8002FD1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002FD20: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002FD24: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002FD28: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002FD2C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8002FD30: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002FD34: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002FD38: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002FD3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FD40: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002FD44: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002FD48: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002FD4C: bgez        $v1, L_8002FD5C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002FD50: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_8002FD5C;
    }
    // 0x8002FD50: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x8002FD54: b           L_8002FD60
    // 0x8002FD58: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_8002FD60;
    // 0x8002FD58: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_8002FD5C:
    // 0x8002FD5C: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_8002FD60:
    // 0x8002FD60: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002FD64: jal         0x8002A230
    // 0x8002FD68: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002FD68: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    after_1:
L_8002FD6C:
    // 0x8002FD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FD70:
    // 0x8002FD70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FD74: jr          $ra
    // 0x8002FD78: nop

    return;
    // 0x8002FD78: nop

;}
RECOMP_FUNC void scExplainUpdatePhase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DFFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018E000: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018E004: addiu       $s1, $s1, -0x1610
    ctx->r17 = ADD32(ctx->r17, -0X1610);
    // 0x8018E008: lw          $v1, 0x28($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X28);
    // 0x8018E00C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E010: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018E014: bnel        $v1, $zero, L_8018E0FC
    if (ctx->r3 != 0) {
        // 0x8018E018: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8018E0FC;
    }
    goto skip_0;
    // 0x8018E018: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8018E01C: jal         0x8018DF80
    // 0x8018E020: nop

    scExplainTryMakeFireFlower(rdram, ctx);
        goto after_0;
    // 0x8018E020: nop

    after_0:
    // 0x8018E024: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x8018E028: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018E02C: slti        $at, $t7, 0x17
    ctx->r1 = SIGNED(ctx->r15) < 0X17 ? 1 : 0;
    // 0x8018E030: bne         $at, $zero, L_8018E05C
    if (ctx->r1 != 0) {
        // 0x8018E034: sw          $t7, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r15;
            goto L_8018E05C;
    }
    // 0x8018E034: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
    // 0x8018E038: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E03C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018E040: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8018E044: addiu       $t0, $zero, 0x1A
    ctx->r8 = ADD32(0, 0X1A);
    // 0x8018E048: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8018E04C: jal         0x80005C74
    // 0x8018E050: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018E050: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    after_1:
    // 0x8018E054: b           L_8018E104
    // 0x8018E058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8018E104;
    // 0x8018E058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E05C:
    // 0x8018E05C: jal         0x8018DD18
    // 0x8018E060: nop

    scExplainUpdateTextBoxSprite(rdram, ctx);
        goto after_2;
    // 0x8018E060: nop

    after_2:
    // 0x8018E064: jal         0x8018DDBC
    // 0x8018E068: nop

    func_ovl63_8018DDBC(rdram, ctx);
        goto after_3;
    // 0x8018E068: nop

    after_3:
    // 0x8018E06C: jal         0x8018DEA0
    // 0x8018E070: nop

    scExplainHideTapSpark(rdram, ctx);
        goto after_4;
    // 0x8018E070: nop

    after_4:
    // 0x8018E074: jal         0x8018DACC
    // 0x8018E078: nop

    scExplainSpecialMoveRGBProcUpdate(rdram, ctx);
        goto after_5;
    // 0x8018E078: nop

    after_5:
    // 0x8018E07C: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018E080: addiu       $s0, $s0, -0x1618
    ctx->r16 = ADD32(ctx->r16, -0X1618);
    // 0x8018E084: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E088: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x8018E08C: jal         0x8018DEB4
    // 0x8018E090: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_6;
    // 0x8018E090: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_6:
    // 0x8018E094: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E098: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x8018E09C: jal         0x8018DEB4
    // 0x8018E0A0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_7;
    // 0x8018E0A0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_7:
    // 0x8018E0A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E0A8: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x8018E0AC: jal         0x8018DEB4
    // 0x8018E0B0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_8;
    // 0x8018E0B0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_8:
    // 0x8018E0B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E0B8: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8018E0BC: jal         0x8018DEB4
    // 0x8018E0C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_9;
    // 0x8018E0C0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_9:
    // 0x8018E0C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E0C8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x8018E0CC: jal         0x8018DEB4
    // 0x8018E0D0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_10;
    // 0x8018E0D0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_10:
    // 0x8018E0D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018E0D8: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    // 0x8018E0DC: jal         0x8018DEB4
    // 0x8018E0E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    scExplainUpdateArgsSObj(rdram, ctx);
        goto after_11;
    // 0x8018E0E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_11:
    // 0x8018E0E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018E0E8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8018E0EC: addiu       $t2, $v0, 0x2C
    ctx->r10 = ADD32(ctx->r2, 0X2C);
    // 0x8018E0F0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8018E0F4: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    // 0x8018E0F8: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
L_8018E0FC:
    // 0x8018E0FC: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
    // 0x8018E100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E104:
    // 0x8018E104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018E108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018E10C: jr          $ra
    // 0x8018E110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018E110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnStartupFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CB8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80131CBC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80131CC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CC4: sw          $t6, 0x2070($at)
    MEM_W(0X2070, ctx->r1) = ctx->r14;
    // 0x80131CC8: lui         $t7, 0x1B
    ctx->r15 = S32(0X1B << 16);
    // 0x80131CCC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131CD0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131CD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131CD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CDC: addiu       $t7, $t7, -0x3790
    ctx->r15 = ADD32(ctx->r15, -0X3790);
    // 0x80131CE0: addiu       $t8, $t8, 0x854
    ctx->r24 = ADD32(ctx->r24, 0X854);
    // 0x80131CE4: addiu       $t9, $t9, 0x2048
    ctx->r25 = ADD32(ctx->r25, 0X2048);
    // 0x80131CE8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80131CEC: sw          $zero, 0x2074($at)
    MEM_W(0X2074, ctx->r1) = 0;
    // 0x80131CF0: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x80131CF4: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x80131CF8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80131CFC: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80131D00: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x80131D04: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x80131D08: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80131D0C: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x80131D10: jal         0x800CDF78
    // 0x80131D14: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80131D14: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x80131D18: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131D1C: addiu       $a1, $a1, 0x1C20
    ctx->r5 = ADD32(ctx->r5, 0X1C20);
    // 0x80131D20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131D28: jal         0x80009968
    // 0x80131D2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80131D2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D30: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80131D34: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131D38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D3C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80131D40: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80131D44: jal         0x8000B9FC
    // 0x80131D48: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x80131D48: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80131D4C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80131D50: addiu       $t2, $t2, -0x2D34
    ctx->r10 = ADD32(ctx->r10, -0X2D34);
    // 0x80131D54: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80131D58: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80131D5C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80131D60: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131D68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80131D6C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80131D70: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80131D74: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80131D78: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80131D7C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80131D80: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80131D84: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80131D88: addiu       $a0, $zero, 0x3EB
    ctx->r4 = ADD32(0, 0X3EB);
    // 0x80131D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D90: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80131D94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131D98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131D9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131DA0: jal         0x8000B93C
    // 0x80131DA4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_3;
    // 0x80131DA4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_3:
    // 0x80131DA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131DAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131DB0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131DB4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131DB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131DC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131DC4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131DC8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131DCC: jal         0x80007080
    // 0x80131DD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_4;
    // 0x80131DD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80131DD4: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80131DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DDC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80131DE0: jal         0x80009968
    // 0x80131DE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80131DE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131DE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131DEC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80131DF0: addiu       $a1, $a1, 0x1B00
    ctx->r5 = ADD32(ctx->r5, 0X1B00);
    // 0x80131DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131DFC: jal         0x80008188
    // 0x80131E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80131E00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80131E04: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131E08: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80131E0C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80131E10: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131E14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80131E18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131E1C: jal         0x80009DF4
    // 0x80131E20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_7;
    // 0x80131E20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_7:
    // 0x80131E24: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x80131E28: addiu       $a0, $a0, 0xC2
    ctx->r4 = ADD32(ctx->r4, 0XC2);
    // 0x80131E2C: jal         0x800CDBD0
    // 0x80131E30: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_8;
    // 0x80131E30: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_8:
    // 0x80131E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E38: jal         0x80004980
    // 0x80131E3C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_9;
    // 0x80131E3C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_9:
    // 0x80131E40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80131E44: jal         0x800CDC88
    // 0x80131E48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_10;
    // 0x80131E48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80131E4C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131E50: addiu       $t0, $t0, 0x73C0
    ctx->r8 = ADD32(ctx->r8, 0X73C0);
    // 0x80131E54: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // 0x80131E58: jal         0x800CCFDC
    // 0x80131E5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_11;
    // 0x80131E5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_11:
    // 0x80131E60: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80131E64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E68: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E6C: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80131E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E74: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131E78: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80131E7C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131E80: addiu       $t3, $t3, 0x1F54
    ctx->r11 = ADD32(ctx->r11, 0X1F54);
    // 0x80131E84: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131E88: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80131E8C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80131E90: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x80131E94: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80131E98: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80131E9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131EA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131EA4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80131EA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131EAC: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x80131EB0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80131EB4: jal         0x800D4060
    // 0x80131EB8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_12;
    // 0x80131EB8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_12:
    // 0x80131EBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131EC0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80131EC4: jr          $ra
    // 0x80131EC8: nop

    return;
    // 0x80131EC8: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137EF0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137EF4: lw          $t6, -0x70C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X70C0);
    // 0x80137EF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80137EFC: bne         $t6, $zero, L_80137F08
    if (ctx->r14 != 0) {
        // 0x80137F00: nop
    
            goto L_80137F08;
    }
    // 0x80137F00: nop

    // 0x80137F04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80137F08:
    // 0x80137F08: jr          $ra
    // 0x80137F0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80137F0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void dbMenuDrawBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8036944C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80369450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369454: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80369458: jal         0x803749BC
    // 0x8036945C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_ovl8_803749BC(rdram, ctx);
        goto after_0;
    // 0x8036945C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80369460: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369464: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80369468: addiu       $a1, $a1, -0x6084
    ctx->r5 = ADD32(ctx->r5, -0X6084);
    // 0x8036946C: jal         0x80374A54
    // 0x80369470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_80374A54(rdram, ctx);
        goto after_1;
    // 0x80369470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80369474: lui         $v0, 0x8037
    ctx->r2 = S32(0X8037 << 16);
    // 0x80369478: addiu       $v0, $v0, -0x6084
    ctx->r2 = ADD32(ctx->r2, -0X6084);
    // 0x8036947C: lhu         $t8, 0x4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X4);
    // 0x80369480: lhu         $t0, 0x6($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X6);
    // 0x80369484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80369488: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8036948C: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80369490: addiu       $t1, $t0, -0x2
    ctx->r9 = ADD32(ctx->r8, -0X2);
    // 0x80369494: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x80369498: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x8036949C: sh          $t9, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r25;
    // 0x803694A0: sh          $t1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r9;
    // 0x803694A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x803694A8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x803694AC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x803694B0: jal         0x80377AEC
    // 0x803694B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_2;
    // 0x803694B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x803694B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803694BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803694C0: jr          $ra
    // 0x803694C4: nop

    return;
    // 0x803694C4: nop

;}
RECOMP_FUNC void func_ovl8_80375BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375BEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80375BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375BF4: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80375BF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80375BFC: lw          $v0, 0x74($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X74);
    // 0x80375C00: beq         $t6, $zero, L_80375C1C
    if (ctx->r14 == 0) {
        // 0x80375C04: nop
    
            goto L_80375C1C;
    }
    // 0x80375C04: nop

    // 0x80375C08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80375C0C: jal         0x80375E60
    // 0x80375C10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_ovl8_80375E60(rdram, ctx);
        goto after_0;
    // 0x80375C10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80375C14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80375C18: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_80375C1C:
    // 0x80375C1C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375C20: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x80375C24: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80375C28: lhu         $t8, 0x14($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X14);
    // 0x80375C2C: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80375C30: lhu         $t0, 0x16($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X16);
    // 0x80375C34: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80375C38: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x80375C3C: jal         0x80023888
    // 0x80375C40: subu        $a2, $t9, $t0
    ctx->r6 = SUB32(ctx->r25, ctx->r8);
    spMove(rdram, ctx);
        goto after_1;
    // 0x80375C40: subu        $a2, $t9, $t0
    ctx->r6 = SUB32(ctx->r25, ctx->r8);
    after_1:
    // 0x80375C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80375C48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80375C4C: jr          $ra
    // 0x80375C50: nop

    return;
    // 0x80375C50: nop

;}
RECOMP_FUNC void lbCommonCross3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD5AC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CD5B0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800CD5B4: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800CD5B8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CD5BC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CD5C0: nop

    // 0x800CD5C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CD5C8: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800CD5CC: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800CD5D0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800CD5D4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800CD5D8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CD5DC: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800CD5E0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800CD5E4: nop

    // 0x800CD5E8: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800CD5EC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800CD5F0: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800CD5F4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CD5F8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CD5FC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800CD600: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CD604: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800CD608: nop

    // 0x800CD60C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800CD610: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800CD614: jr          $ra
    // 0x800CD618: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    return;
    // 0x800CD618: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
;}
RECOMP_FUNC void ftCommonAttack100EndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F45C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014F460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F464: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014F468: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8014F46C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8014F470: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x8014F474: beq         $at, $zero, L_8014F4C8
    if (ctx->r1 == 0) {
        // 0x8014F478: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8014F4C8;
    }
    // 0x8014F478: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014F47C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F480: addu        $at, $at, $t7
    gpr jr_addend_8014F488 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014F484: lw          $t7, -0x3C20($at)
    ctx->r15 = ADD32(ctx->r1, -0X3C20);
    // 0x8014F488: jr          $t7
    // 0x8014F48C: nop

    switch (jr_addend_8014F488 >> 2) {
        case 0: goto L_8014F490; break;
        case 1: goto L_8014F4C8; break;
        case 2: goto L_8014F4C8; break;
        case 3: goto L_8014F4C8; break;
        case 4: goto L_8014F49C; break;
        case 5: goto L_8014F4C8; break;
        case 6: goto L_8014F4C0; break;
        case 7: goto L_8014F4A8; break;
        case 8: goto L_8014F4C8; break;
        case 9: goto L_8014F4B4; break;
        case 10: goto L_8014F4C8; break;
        case 11: goto L_8014F4C8; break;
        case 12: goto L_8014F4C8; break;
        case 13: goto L_8014F4C8; break;
        case 14: goto L_8014F490; break;
        case 15: goto L_8014F4C8; break;
        case 16: goto L_8014F4C8; break;
        case 17: goto L_8014F4C8; break;
        case 18: goto L_8014F49C; break;
        case 19: goto L_8014F4C8; break;
        case 20: goto L_8014F4C0; break;
        case 21: goto L_8014F4A8; break;
        case 22: goto L_8014F4C8; break;
        case 23: goto L_8014F4B4; break;
        default: switch_error(__func__, 0x8014F488, 0x8018C3E0);
    }
    // 0x8014F48C: nop

L_8014F490:
    // 0x8014F490: addiu       $t8, $zero, 0xDE
    ctx->r24 = ADD32(0, 0XDE);
    // 0x8014F494: b           L_8014F4C8
    // 0x8014F498: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8014F4C8;
    // 0x8014F498: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8014F49C:
    // 0x8014F49C: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x8014F4A0: b           L_8014F4C8
    // 0x8014F4A4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8014F4C8;
    // 0x8014F4A4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8014F4A8:
    // 0x8014F4A8: addiu       $t0, $zero, 0xDE
    ctx->r8 = ADD32(0, 0XDE);
    // 0x8014F4AC: b           L_8014F4C8
    // 0x8014F4B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8014F4C8;
    // 0x8014F4B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8014F4B4:
    // 0x8014F4B4: addiu       $t1, $zero, 0xDE
    ctx->r9 = ADD32(0, 0XDE);
    // 0x8014F4B8: b           L_8014F4C8
    // 0x8014F4BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_8014F4C8;
    // 0x8014F4BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_8014F4C0:
    // 0x8014F4C0: addiu       $t2, $zero, 0xDF
    ctx->r10 = ADD32(0, 0XDF);
    // 0x8014F4C4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8014F4C8:
    // 0x8014F4C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8014F4CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014F4D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014F4D4: jal         0x800E6F24
    // 0x8014F4D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F4D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8014F4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F4E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014F4E4: jr          $ra
    // 0x8014F4E8: nop

    return;
    // 0x8014F4E8: nop

;}
RECOMP_FUNC void mpCommonProcFighterOnEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDE84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDE8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DDE90: jal         0x800DDE50
    // 0x800DDE94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x800DDE94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DDE98: bne         $v0, $zero, L_800DDEB0
    if (ctx->r2 != 0) {
        // 0x800DDE9C: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDEB0;
    }
    // 0x800DDE9C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDEA0: jalr        $t9
    // 0x800DDEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DDEA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800DDEA8: b           L_800DDEB4
    // 0x800DDEAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDEB4;
    // 0x800DDEAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DDEB0:
    // 0x800DDEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DDEB4:
    // 0x800DDEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDEB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDEBC: jr          $ra
    // 0x800DDEC0: nop

    return;
    // 0x800DDEC0: nop

;}
RECOMP_FUNC void func_ovl0_800CB140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB140: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800CB144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CB14C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800CB150: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800CB154: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x800CB158: jal         0x800EDBA4
    // 0x800CB15C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800CB15C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x800CB160: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800CB164: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800CB168: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800CB16C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CB170: nop

    // 0x800CB174: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800CB178: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CB17C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CB180: jal         0x80033510
    // 0x800CB184: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CB184: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_1:
    // 0x800CB188: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800CB18C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800CB190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CB194: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800CB198: nop

    // 0x800CB19C: bc1fl       L_800CB1C8
    if (!c1cs) {
        // 0x800CB1A0: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_800CB1C8;
    }
    goto skip_0;
    // 0x800CB1A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x800CB1A4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CB1A8: addiu       $s0, $s0, 0x5E10
    ctx->r16 = ADD32(ctx->r16, 0X5E10);
L_800CB1AC:
    // 0x800CB1AC: jal         0x80023624
    // 0x800CB1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800CB1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800CB1B4: jal         0x800A3040
    // 0x800CB1B8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800CB1B8: nop

    after_3:
    // 0x800CB1BC: b           L_800CB1AC
    // 0x800CB1C0: nop

        goto L_800CB1AC;
    // 0x800CB1C0: nop

    // 0x800CB1C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_800CB1C8:
    // 0x800CB1C8: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800CB1CC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800CB1D0: div.s       $f2, $f16, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CB1D4: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x800CB1D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800CB1DC: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CB1E0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800CB1E4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800CB1E8: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800CB1EC: mul.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CB1F0: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x800CB1F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800CB1F8: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800CB1FC: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CB200: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x800CB204: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800CB208: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x800CB20C: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x800CB210: jal         0x8001902C
    // 0x800CB214: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    syVectorDiff3D(rdram, ctx);
        goto after_4;
    // 0x800CB214: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    after_4:
    // 0x800CB218: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x800CB21C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CB220: jal         0x800C7B58
    // 0x800CB224: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    lbCommonSim3D(rdram, ctx);
        goto after_5;
    // 0x800CB224: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x800CB228: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CB22C: lwc1        $f10, 0x5EC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5EC0);
    // 0x800CB230: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800CB234: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800CB238: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CB23C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CB240: bc1fl       L_800CB270
    if (!c1cs) {
        // 0x800CB244: swc1        $f12, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
            goto L_800CB270;
    }
    goto skip_1;
    // 0x800CB244: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    skip_1:
    // 0x800CB248: jal         0x80019980
    // 0x800CB24C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    syVectorNormCross3D(rdram, ctx);
        goto after_6;
    // 0x800CB24C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x800CB250: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800CB254: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800CB258: jal         0x800CD5AC
    // 0x800CB25C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    lbCommonCross3D(rdram, ctx);
        goto after_7;
    // 0x800CB25C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800CB260: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800CB264: b           L_800CB298
    // 0x800CB268: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
        goto L_800CB298;
    // 0x800CB268: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CB26C: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800CB270:
    // 0x800CB270: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800CB274: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    // 0x800CB278: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800CB27C: addiu       $t7, $sp, 0x38
    ctx->r15 = ADD32(ctx->r29, 0X38);
    // 0x800CB280: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800CB284: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800CB288: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800CB28C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800CB290: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x800CB294: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_800CB298:
    // 0x800CB298: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800CB29C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800CB2A0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800CB2A4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800CB2A8: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800CB2AC: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x800CB2B0: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x800CB2B4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800CB2B8: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800CB2BC: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x800CB2C0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800CB2C4: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x800CB2C8: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800CB2CC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x800CB2D0: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800CB2D4: jal         0x80019EA0
    // 0x800CB2D8: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    syMatrixF2LFixedW(rdram, ctx);
        goto after_8;
    // 0x800CB2D8: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x800CB2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB2E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB2E4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800CB2E8: jr          $ra
    // 0x800CB2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CB2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnTitleProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801326D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801326DC: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x801326E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801326E4: beql        $t6, $at, L_801326F8
    if (ctx->r14 == ctx->r1) {
        // 0x801326E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801326F8;
    }
    goto skip_0;
    // 0x801326E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801326EC: jal         0x801325D4
    // 0x801326F0: nop

    mnTitlePlayAnim(rdram, ctx);
        goto after_0;
    // 0x801326F0: nop

    after_0:
    // 0x801326F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801326F8:
    // 0x801326F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801326FC: jr          $ra
    // 0x80132700: nop

    return;
    // 0x80132700: nop

;}
RECOMP_FUNC void ftParamSetModelPartDetailAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9198: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E919C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E91A0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E91A4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E91A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E91AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E91B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E91B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E91B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E91BC: lw          $s3, 0x84($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X84);
    // 0x800E91C0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800E91C4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800E91C8: lbu         $t6, 0xE($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0XE);
    // 0x800E91CC: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800E91D0: addiu       $s4, $zero, 0x25
    ctx->r20 = ADD32(0, 0X25);
    // 0x800E91D4: beq         $t6, $a1, L_800E9224
    if (ctx->r14 == ctx->r5) {
        // 0x800E91D8: addiu       $s1, $s3, 0x10
        ctx->r17 = ADD32(ctx->r19, 0X10);
            goto L_800E9224;
    }
    // 0x800E91D8: addiu       $s1, $s3, 0x10
    ctx->r17 = ADD32(ctx->r19, 0X10);
    // 0x800E91DC: sb          $a1, 0xE($s3)
    MEM_B(0XE, ctx->r19) = ctx->r5;
    // 0x800E91E0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800E91E4:
    // 0x800E91E4: lw          $v0, 0x8E8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E91E8: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800E91EC: beq         $v0, $zero, L_800E9210
    if (ctx->r2 == 0) {
        // 0x800E91F0: addu        $v0, $s3, $t7
        ctx->r2 = ADD32(ctx->r19, ctx->r15);
            goto L_800E9210;
    }
    // 0x800E91F0: addu        $v0, $s3, $t7
    ctx->r2 = ADD32(ctx->r19, ctx->r15);
    // 0x800E91F4: lb          $a2, 0x975($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X975);
    // 0x800E91F8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E91FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E9200: beql        $a2, $s2, L_800E9214
    if (ctx->r6 == ctx->r18) {
        // 0x800E9204: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800E9214;
    }
    goto skip_0;
    // 0x800E9204: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800E9208: jal         0x800E8C70
    // 0x800E920C: sb          $s2, 0x975($v0)
    MEM_B(0X975, ctx->r2) = ctx->r18;
    ftParamSetModelPartID(rdram, ctx);
        goto after_0;
    // 0x800E920C: sb          $s2, 0x975($v0)
    MEM_B(0X975, ctx->r2) = ctx->r18;
    after_0:
L_800E9210:
    // 0x800E9210: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800E9214:
    // 0x800E9214: bne         $s0, $s4, L_800E91E4
    if (ctx->r16 != ctx->r20) {
        // 0x800E9218: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800E91E4;
    }
    // 0x800E9218: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800E921C: jal         0x800E9598
    // 0x800E9220: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    ftParamInitTexturePartAll(rdram, ctx);
        goto after_1;
    // 0x800E9220: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
L_800E9224:
    // 0x800E9224: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E9228: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E922C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E9230: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9234: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E9238: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E923C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E9240: jr          $ra
    // 0x800E9244: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E9244: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPhysicsCheckClampAirVelXDecMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8FB0: jal         0x800D8EDC
    // 0x800D8FB4: lw          $a1, 0x50($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50);
    ftPhysicsCheckClampAirVelXDec(rdram, ctx);
        goto after_0;
    // 0x800D8FB4: lw          $a1, 0x50($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50);
    after_0:
    // 0x800D8FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8FC0: jr          $ra
    // 0x800D8FC4: nop

    return;
    // 0x800D8FC4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdatePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135C18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135C1C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135C24: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80135C28: addiu       $t7, $t7, -0x7C68
    ctx->r15 = ADD32(ctx->r15, -0X7C68);
    // 0x80135C2C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135C30: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80135C34: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135C38: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135C3C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80135C40: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135C44: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80135C48: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135C4C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80135C50: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135C54: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80135C58: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135C5C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135C60: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80135C64: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135C68: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80135C6C: jal         0x8000B760
    // 0x80135C70: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80135C70: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80135C74: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80135C78: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80135C7C: lw          $t3, -0x7368($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7368);
    // 0x80135C80: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80135C84: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80135C88: lw          $t2, 0x20($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20);
    // 0x80135C8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135C90: jal         0x800CCFDC
    // 0x80135C94: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80135C94: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80135C98: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80135C9C: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80135CA0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80135CA4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80135CA8: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80135CAC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80135CB0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80135CB4: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80135CB8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80135CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135CC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135CC4: jr          $ra
    // 0x80135CC8: nop

    return;
    // 0x80135CC8: nop

;}
RECOMP_FUNC void syMatrixTraRotRpyRScaF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C52C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C530: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001C534: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001C538: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8001C53C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C540: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001C544: jal         0x8001BDEC
    // 0x8001C548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001C548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001C54C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001C550: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001C554: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001C558: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001C55C: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001C560: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C564: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001C568: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C56C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8001C570: jal         0x8001B824
    // 0x8001C574: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    syMatrixRowscaleF(rdram, ctx);
        goto after_1;
    // 0x8001C574: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001C578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C57C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C580: jr          $ra
    // 0x8001C584: nop

    return;
    // 0x8001C584: nop

;}
RECOMP_FUNC void mnTitleMakeSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133200: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133204: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80133208: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013320C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80133210: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80133214: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80133218: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8013321C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80133220: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80133224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80133228: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8013322C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133230: jal         0x80009968
    // 0x80133234: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133234: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80133238: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013323C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133240: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80133244: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133248: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013324C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133250: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133254: jal         0x80009DF4
    // 0x80133258: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133258: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8013325C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133260: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80133264: addiu       $s3, $s3, 0x45A0
    ctx->r19 = ADD32(ctx->r19, 0X45A0);
    // 0x80133268: addiu       $s1, $s1, 0x4268
    ctx->r17 = ADD32(ctx->r17, 0X4268);
    // 0x8013326C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133270: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x80133274: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80133278:
    // 0x80133278: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8013327C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80133280: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80133284: jal         0x800CCFDC
    // 0x80133288: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133288: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013328C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133290: sh          $s4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r20;
    // 0x80133294: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013329C: jal         0x80132764
    // 0x801332A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnTitleSetPosition(rdram, ctx);
        goto after_3;
    // 0x801332A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x801332A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801332A8: jal         0x8013282C
    // 0x801332AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnTitleSetColors(rdram, ctx);
        goto after_4;
    // 0x801332AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x801332B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801332B4: bne         $s0, $s5, L_80133278
    if (ctx->r16 != ctx->r21) {
        // 0x801332B8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80133278;
    }
    // 0x801332B8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801332BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801332C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801332C4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801332C8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801332CC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801332D0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801332D4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801332D8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801332DC: jr          $ra
    // 0x801332E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801332E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayersVSUpdatePuckGlowColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139970: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80139974: addiu       $v1, $v1, -0x4248
    ctx->r3 = ADD32(ctx->r3, -0X4248);
    // 0x80139978: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013997C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80139980: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80139984: bne         $v0, $zero, L_801399B0
    if (ctx->r2 != 0) {
        // 0x80139988: addiu       $a0, $a0, -0x424C
        ctx->r4 = ADD32(ctx->r4, -0X424C);
            goto L_801399B0;
    }
    // 0x80139988: addiu       $a0, $a0, -0x424C
    ctx->r4 = ADD32(ctx->r4, -0X424C);
    // 0x8013998C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80139990: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80139994: addiu       $t7, $t6, 0x9
    ctx->r15 = ADD32(ctx->r14, 0X9);
    // 0x80139998: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x8013999C: bne         $at, $zero, L_801399B0
    if (ctx->r1 != 0) {
        // 0x801399A0: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_801399B0;
    }
    // 0x801399A0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801399A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801399A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801399AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801399B0:
    // 0x801399B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801399B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801399B8: bne         $v0, $at, L_801399E0
    if (ctx->r2 != ctx->r1) {
        // 0x801399BC: addiu       $a0, $a0, -0x424C
        ctx->r4 = ADD32(ctx->r4, -0X424C);
            goto L_801399E0;
    }
    // 0x801399BC: addiu       $a0, $a0, -0x424C
    ctx->r4 = ADD32(ctx->r4, -0X424C);
    // 0x801399C0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x801399C4: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x801399C8: addiu       $t2, $t1, -0x9
    ctx->r10 = ADD32(ctx->r9, -0X9);
    // 0x801399CC: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x801399D0: beq         $at, $zero, L_801399E0
    if (ctx->r1 == 0) {
        // 0x801399D4: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_801399E0;
    }
    // 0x801399D4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801399D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x801399DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801399E0:
    // 0x801399E0: jr          $ra
    // 0x801399E4: nop

    return;
    // 0x801399E4: nop

;}
RECOMP_FUNC void wpLinkBoomerangCheckOffCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CCA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8016CCA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016CCA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8016CCAC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016CCB0: lbu         $v1, 0x2A1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2A1);
    // 0x8016CCB4: blez        $v1, L_8016CCC4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8016CCB8: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8016CCC4;
    }
    // 0x8016CCB8: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8016CCBC: b           L_8016CDB4
    // 0x8016CCC0: sb          $t7, 0x2A1($v0)
    MEM_B(0X2A1, ctx->r2) = ctx->r15;
        goto L_8016CDB4;
    // 0x8016CCC0: sb          $t7, 0x2A1($v0)
    MEM_B(0X2A1, ctx->r2) = ctx->r15;
L_8016CCC4:
    // 0x8016CCC4: lbu         $t8, 0x2A3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A3);
    // 0x8016CCC8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8016CCCC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8016CCD0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8016CCD4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8016CCD8: slti        $at, $t0, 0x9
    ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
    // 0x8016CCDC: bne         $at, $zero, L_8016CDB4
    if (ctx->r1 != 0) {
        // 0x8016CCE0: sb          $t9, 0x2A3($v0)
        MEM_B(0X2A3, ctx->r2) = ctx->r25;
            goto L_8016CDB4;
    }
    // 0x8016CCE0: sb          $t9, 0x2A3($v0)
    MEM_B(0X2A3, ctx->r2) = ctx->r25;
    // 0x8016CCE4: sb          $zero, 0x2A3($v0)
    MEM_B(0X2A3, ctx->r2) = 0;
    // 0x8016CCE8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8016CCEC: lw          $t1, 0x1460($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1460);
    // 0x8016CCF0: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x8016CCF4: lw          $a2, 0x74($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X74);
    // 0x8016CCF8: lw          $a0, 0x74($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X74);
    // 0x8016CCFC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8016CD00: addiu       $a1, $a1, 0x1470
    ctx->r5 = ADD32(ctx->r5, 0X1470);
    // 0x8016CD04: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8016CD08: jal         0x800EB924
    // 0x8016CD0C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    func_ovl2_800EB924(rdram, ctx);
        goto after_0;
    // 0x8016CD0C: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_0:
    // 0x8016CD10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8016CD14: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8016CD18: lw          $t4, 0x38($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X38);
    // 0x8016CD1C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8016CD20: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8016CD24: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x8016CD28: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8016CD2C: bgez        $t4, L_8016CD3C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8016CD30: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8016CD3C;
    }
    // 0x8016CD30: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8016CD34: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8016CD38: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8016CD3C:
    // 0x8016CD3C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8016CD40: nop

    // 0x8016CD44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016CD48: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8016CD4C: bgez        $t6, L_8016CD5C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8016CD50: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8016CD5C;
    }
    // 0x8016CD50: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8016CD54: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8016CD58: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8016CD5C:
    // 0x8016CD5C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8016CD60: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8016CD64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016CD68: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8016CD6C: add.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8016CD70: bc1t        L_8016CDAC
    if (c1cs) {
        // 0x8016CD74: nop
    
            goto L_8016CDAC;
    }
    // 0x8016CD74: nop

    // 0x8016CD78: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8016CD7C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016CD80: bc1t        L_8016CDAC
    if (c1cs) {
        // 0x8016CD84: nop
    
            goto L_8016CDAC;
    }
    // 0x8016CD84: nop

    // 0x8016CD88: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8016CD8C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8016CD90: nop

    // 0x8016CD94: bc1t        L_8016CDAC
    if (c1cs) {
        // 0x8016CD98: nop
    
            goto L_8016CDAC;
    }
    // 0x8016CD98: nop

    // 0x8016CD9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016CDA0: nop

    // 0x8016CDA4: bc1fl       L_8016CDB8
    if (!c1cs) {
        // 0x8016CDA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016CDB8;
    }
    goto skip_0;
    // 0x8016CDA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8016CDAC:
    // 0x8016CDAC: b           L_8016CDB8
    // 0x8016CDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016CDB8;
    // 0x8016CDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016CDB4:
    // 0x8016CDB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016CDB8:
    // 0x8016CDB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016CDBC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8016CDC0: jr          $ra
    // 0x8016CDC4: nop

    return;
    // 0x8016CDC4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCostumeSyncProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80136EDC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80136EE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136EE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80136EE8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80136EEC: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80136EF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80136EF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136EF8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80136EFC: addiu       $s3, $s3, -0x77C8
    ctx->r19 = ADD32(ctx->r19, -0X77C8);
    // 0x80136F00: addiu       $s0, $s0, -0x7AA8
    ctx->r16 = ADD32(ctx->r16, -0X7AA8);
    // 0x80136F04: addiu       $s2, $zero, 0x1C
    ctx->r18 = ADD32(0, 0X1C);
    // 0x80136F08: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
L_80136F0C:
    // 0x80136F0C: beql        $s2, $a0, L_80136F60
    if (ctx->r18 == ctx->r4) {
        // 0x80136F10: addiu       $s0, $s0, 0xB8
        ctx->r16 = ADD32(ctx->r16, 0XB8);
            goto L_80136F60;
    }
    goto skip_0;
    // 0x80136F10: addiu       $s0, $s0, 0xB8
    ctx->r16 = ADD32(ctx->r16, 0XB8);
    skip_0:
    // 0x80136F14: jal         0x801332DC
    // 0x80136F18: nop

    mnPlayers1PTrainingGetFighterKindCount(rdram, ctx);
        goto after_0;
    // 0x80136F18: nop

    after_0:
    // 0x80136F1C: bne         $v0, $zero, L_80136F5C
    if (ctx->r2 != 0) {
        // 0x80136F20: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80136F5C;
    }
    // 0x80136F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136F24: jal         0x800EC0EC
    // 0x80136F28: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x80136F28: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_1:
    // 0x80136F2C: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x80136F30: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80136F34: beql        $v0, $t6, L_80136F60
    if (ctx->r2 == ctx->r14) {
        // 0x80136F38: addiu       $s0, $s0, 0xB8
        ctx->r16 = ADD32(ctx->r16, 0XB8);
            goto L_80136F60;
    }
    goto skip_1;
    // 0x80136F38: addiu       $s0, $s0, 0xB8
    ctx->r16 = ADD32(ctx->r16, 0XB8);
    skip_1:
    // 0x80136F3C: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x80136F40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80136F44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80136F48: bnel        $t7, $zero, L_80136F60
    if (ctx->r15 != 0) {
        // 0x80136F4C: addiu       $s0, $s0, 0xB8
        ctx->r16 = ADD32(ctx->r16, 0XB8);
            goto L_80136F60;
    }
    goto skip_2;
    // 0x80136F4C: addiu       $s0, $s0, 0xB8
    ctx->r16 = ADD32(ctx->r16, 0XB8);
    skip_2:
    // 0x80136F50: jal         0x800E9248
    // 0x80136F54: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    ftParamInitAllParts(rdram, ctx);
        goto after_2;
    // 0x80136F54: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x80136F58: sw          $s1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r17;
L_80136F5C:
    // 0x80136F5C: addiu       $s0, $s0, 0xB8
    ctx->r16 = ADD32(ctx->r16, 0XB8);
L_80136F60:
    // 0x80136F60: bnel        $s0, $s3, L_80136F0C
    if (ctx->r16 != ctx->r19) {
        // 0x80136F64: lw          $a0, 0x48($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X48);
            goto L_80136F0C;
    }
    goto skip_3;
    // 0x80136F64: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    skip_3:
    // 0x80136F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136F6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136F70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136F74: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80136F78: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80136F7C: jr          $ra
    // 0x80136F80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80136F80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itBoxThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017987C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179884: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80179888: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017988C: lwc1        $f4, -0x3294($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3294);
    // 0x80179890: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80179894: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179898: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x8017989C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801798A0: jal         0x80172EC8
    // 0x801798A4: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801798A4: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    after_0:
    // 0x801798A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801798AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801798B0: jr          $ra
    // 0x801798B4: nop

    return;
    // 0x801798B4: nop

;}
RECOMP_FUNC void itMainSetFighterDrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172AEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80172AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80172AF4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80172AF8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80172AFC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172B00: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80172B04: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80172B08: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80172B0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80172B10: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80172B14: lw          $a2, -0x6AE0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6AE0);
    // 0x80172B18: lw          $t0, 0x84($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X84);
    // 0x80172B1C: beql        $a2, $zero, L_80172B44
    if (ctx->r6 == 0) {
        // 0x80172B20: lhu         $t8, 0x290($t0)
        ctx->r24 = MEM_HU(ctx->r8, 0X290);
            goto L_80172B44;
    }
    goto skip_0;
    // 0x80172B20: lhu         $t8, 0x290($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X290);
    skip_0:
    // 0x80172B24: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80172B28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80172B2C: jalr        $a2
    // 0x80172B30: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x80172B30: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80172B34: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80172B38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80172B3C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80172B40: lhu         $t8, 0x290($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X290);
L_80172B44:
    // 0x80172B44: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80172B48: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80172B4C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80172B50: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    // 0x80172B54: jal         0x80172984
    // 0x80172B58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    itMainSetFighterRelease(rdram, ctx);
        goto after_1;
    // 0x80172B58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x80172B5C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80172B60: jal         0x800269C0
    // 0x80172B64: lhu         $a0, 0x2C8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2C8);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80172B64: lhu         $a0, 0x2C8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2C8);
    after_2:
    // 0x80172B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80172B6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80172B70: jr          $ra
    // 0x80172B74: nop

    return;
    // 0x80172B74: nop

;}

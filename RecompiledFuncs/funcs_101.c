#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl3_8014C770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C770: jr          $ra
    // 0x8014C774: nop

    return;
    // 0x8014C774: nop

;}
RECOMP_FUNC void sc1PGameGetNextFreeCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D29C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018D2A0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8018D2A4: addiu       $s4, $zero, 0x74
    ctx->r20 = ADD32(0, 0X74);
    // 0x8018D2A8: multu       $a0, $s4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D2AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8018D2B0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018D2B4: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x8018D2B8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8018D2BC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8018D2C0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8018D2C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8018D2C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018D2CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018D2D0: mflo        $t7
    ctx->r15 = lo;
    // 0x8018D2D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D2D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018D2DC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D2E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018D2E4: lbu         $s1, 0x23($t8)
    ctx->r17 = MEM_BU(ctx->r24, 0X23);
    // 0x8018D2E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D2EC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8018D2F0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8018D2F4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8018D2F8:
    // 0x8018D2F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D2FC: jal         0x800EC0EC
    // 0x8018D300: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018D300: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_0:
    // 0x8018D304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8018D308:
    // 0x8018D308: beql        $s0, $s2, L_8018D354
    if (ctx->r16 == ctx->r18) {
        // 0x8018D30C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D354;
    }
    goto skip_0;
    // 0x8018D30C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8018D310: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D314: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8018D318: mflo        $t0
    ctx->r8 = lo;
    // 0x8018D31C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D320: lbu         $t1, 0x22($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X22);
    // 0x8018D324: beql        $s6, $t1, L_8018D354
    if (ctx->r22 == ctx->r9) {
        // 0x8018D328: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D354;
    }
    goto skip_1;
    // 0x8018D328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8018D32C: lbu         $t2, 0x23($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X23);
    // 0x8018D330: bnel        $s1, $t2, L_8018D354
    if (ctx->r17 != ctx->r10) {
        // 0x8018D334: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D354;
    }
    goto skip_2;
    // 0x8018D334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8018D338: lbu         $t3, 0x26($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X26);
    // 0x8018D33C: bnel        $v0, $t3, L_8018D354
    if (ctx->r2 != ctx->r11) {
        // 0x8018D340: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D354;
    }
    goto skip_3;
    // 0x8018D340: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x8018D344: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8018D348: b           L_8018D2F8
    // 0x8018D34C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8018D2F8;
    // 0x8018D34C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D350: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8018D354:
    // 0x8018D354: bne         $s0, $s5, L_8018D308
    if (ctx->r16 != ctx->r21) {
        // 0x8018D358: nop
    
            goto L_8018D308;
    }
    // 0x8018D358: nop

    // 0x8018D35C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D360: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018D364: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018D368: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D36C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8018D370: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8018D374: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8018D378: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D37C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8018D380: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018D384: jr          $ra
    // 0x8018D388: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8018D388: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80017DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017DBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017DC4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80017DC8: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80017DCC: jal         0x80017D3C
    // 0x80017DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80017D3C(rdram, ctx);
        goto after_0;
    // 0x80017DD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80017DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017DDC: jr          $ra
    // 0x80017DE0: nop

    return;
    // 0x80017DE0: nop

;}
RECOMP_FUNC void func_ovl8_8037CBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CBA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037CBA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037CBA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037CBAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037CBB0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037CBB4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8037CBB8: bne         $a0, $zero, L_8037CBD0
    if (ctx->r4 != 0) {
        // 0x8037CBBC: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8037CBD0;
    }
    // 0x8037CBBC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8037CBC0: jal         0x803717A0
    // 0x8037CBC4: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037CBC4: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x8037CBC8: beq         $v0, $zero, L_8037CCB4
    if (ctx->r2 == 0) {
        // 0x8037CBCC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037CCB4;
    }
    // 0x8037CBCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037CBD0:
    // 0x8037CBD0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8037CBD4: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x8037CBD8: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x8037CBDC: bnel        $t6, $zero, L_8037CC00
    if (ctx->r14 != 0) {
        // 0x8037CBE0: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_8037CC00;
    }
    goto skip_0;
    // 0x8037CBE0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x8037CBE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037CBE8: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8037CBEC: jal         0x803717E0
    // 0x8037CBF0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037CBF0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037CBF4: jal         0x8037C2D0
    // 0x8037CBF8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037CBF8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8037CBFC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_8037CC00:
    // 0x8037CC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037CC04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037CC08: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8037CC0C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037CC10: jal         0x80373CC4
    // 0x8037CC14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80373CC4(rdram, ctx);
        goto after_3;
    // 0x8037CC14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037CC18: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037CC1C: addiu       $t8, $t8, -0x5B60
    ctx->r24 = ADD32(ctx->r24, -0X5B60);
    // 0x8037CC20: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x8037CC24: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8037CC28: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037CC2C: addiu       $t9, $t9, -0x5A88
    ctx->r25 = ADD32(ctx->r25, -0X5A88);
    // 0x8037CC30: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x8037CC34: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8037CC38: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037CC3C: addiu       $t1, $t1, -0x5930
    ctx->r9 = ADD32(ctx->r9, -0X5930);
    // 0x8037CC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037CC44: jal         0x8037CE30
    // 0x8037CC48: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    func_ovl8_8037CE30(rdram, ctx);
        goto after_4;
    // 0x8037CC48: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    after_4:
    // 0x8037CC4C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8037CC50: lui         $at, 0x4242
    ctx->r1 = S32(0X4242 << 16);
    // 0x8037CC54: ori         $at, $at, 0x544E
    ctx->r1 = ctx->r1 | 0X544E;
    // 0x8037CC58: sw          $t3, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r11;
    // 0x8037CC5C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8037CC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037CC64: sw          $t4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r12;
    // 0x8037CC68: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8037CC6C: lw          $v0, 0x14($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X14);
    // 0x8037CC70: beq         $v0, $at, L_8037CC98
    if (ctx->r2 == ctx->r1) {
        // 0x8037CC74: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_8037CC98;
    }
    // 0x8037CC74: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x8037CC78: ori         $at, $at, 0x4742
    ctx->r1 = ctx->r1 | 0X4742;
    // 0x8037CC7C: beq         $v0, $at, L_8037CCA0
    if (ctx->r2 == ctx->r1) {
        // 0x8037CC80: lui         $at, 0x424F
        ctx->r1 = S32(0X424F << 16);
            goto L_8037CCA0;
    }
    // 0x8037CC80: lui         $at, 0x424F
    ctx->r1 = S32(0X424F << 16);
    // 0x8037CC84: ori         $at, $at, 0x5042
    ctx->r1 = ctx->r1 | 0X5042;
    // 0x8037CC88: beql        $v0, $at, L_8037CCAC
    if (ctx->r2 == ctx->r1) {
        // 0x8037CC8C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8037CCAC;
    }
    goto skip_1;
    // 0x8037CC8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8037CC90: b           L_8037CCAC
    // 0x8037CC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037CCAC;
    // 0x8037CC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037CC98:
    // 0x8037CC98: b           L_8037CCAC
    // 0x8037CC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037CCAC;
    // 0x8037CC9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037CCA0:
    // 0x8037CCA0: b           L_8037CCAC
    // 0x8037CCA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037CCAC;
    // 0x8037CCA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037CCA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8037CCAC:
    // 0x8037CCAC: jal         0x8037CD64
    // 0x8037CCB0: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    func_ovl8_8037CD64(rdram, ctx);
        goto after_5;
    // 0x8037CCB0: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    after_5:
L_8037CCB4:
    // 0x8037CCB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037CCB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037CCBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037CCC0: jr          $ra
    // 0x8037CCC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037CCC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnTitleMakeActors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133F44: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F48: addiu       $a1, $a1, 0x20F0
    ctx->r5 = ADD32(ctx->r5, 0X20F0);
    // 0x80133F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133F50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133F54: jal         0x80009968
    // 0x80133F58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133F58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133F5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F64: sw          $v0, 0x4458($at)
    MEM_W(0X4458, ctx->r1) = ctx->r2;
    // 0x80133F68: addiu       $a1, $a1, 0x2448
    ctx->r5 = ADD32(ctx->r5, 0X2448);
    // 0x80133F6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133F70: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80133F74: jal         0x80009968
    // 0x80133F78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80133F78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133F80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F84: sw          $v0, 0x4454($at)
    MEM_W(0X4454, ctx->r1) = ctx->r2;
    // 0x80133F88: jr          $ra
    // 0x80133F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80133F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftCommonShieldBreakFlySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149488: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014948C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80149490: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80149494: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80149498: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014949C: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x801494A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801494A4: jal         0x800DEEC8
    // 0x801494A8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801494A8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x801494AC: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x801494B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801494B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801494B8: addiu       $a1, $zero, 0x9E
    ctx->r5 = ADD32(0, 0X9E);
    // 0x801494BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801494C0: jal         0x800E6F24
    // 0x801494C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801494C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801494C8: jal         0x800E0830
    // 0x801494CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801494CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x801494D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801494D4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x801494D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801494DC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x801494E0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801494E4: lwc1        $f6, 0x78($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X78);
    // 0x801494E8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x801494EC: jal         0x800E9814
    // 0x801494F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x801494F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x801494F4: jal         0x800269C0
    // 0x801494F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x801494F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x801494FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80149500: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80149504: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80149508: jr          $ra
    // 0x8014950C: nop

    return;
    // 0x8014950C: nop

;}
RECOMP_FUNC void itIwarkFlyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DA94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DA9C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017DAA0: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017DAA4: bnel        $a1, $zero, L_8017DAC0
    if (ctx->r5 != 0) {
        // 0x8017DAA8: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017DAC0;
    }
    goto skip_0;
    // 0x8017DAA8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017DAAC: jal         0x8017DA60
    // 0x8017DAB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itIwarkAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017DAB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017DAB4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DAB8: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017DABC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017DAC0:
    // 0x8017DAC0: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017DAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DAD0: jr          $ra
    // 0x8017DAD4: nop

    return;
    // 0x8017DAD4: nop

;}
RECOMP_FUNC void mnSoundTestMakeAFunctionSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132D94: lw          $t6, 0x4478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4478);
    // 0x80132D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132D9C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132DA4: addiu       $t7, $t7, 0x1450
    ctx->r15 = ADD32(ctx->r15, 0X1450);
    // 0x80132DA8: jal         0x800CCFDC
    // 0x80132DAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132DAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132DB0: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80132DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DB8: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x80132DBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DC0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132DC4: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80132DC8: addiu       $t0, $zero, 0x6B
    ctx->r8 = ADD32(0, 0X6B);
    // 0x80132DCC: addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // 0x80132DD0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132DD4: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132DD8: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132DDC: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132DE0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132DE4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132DF0: jr          $ra
    // 0x80132DF4: nop

    return;
    // 0x80132DF4: nop

;}
RECOMP_FUNC void ftCommonGuardSetOffSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149108: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014910C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80149110: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80149114: addiu       $t6, $zero, 0x34
    ctx->r14 = ADD32(0, 0X34);
    // 0x80149118: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014911C: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    // 0x80149120: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80149124: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80149128: jal         0x800E6F24
    // 0x8014912C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014912C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80149130: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80149134: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80149138: lwc1        $f8, -0x3E00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3E00);
    // 0x8014913C: lw          $t7, 0x7C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C8);
    // 0x80149140: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80149144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80149148: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8014914C: lw          $t8, 0x7D0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7D0);
    // 0x80149150: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80149154: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80149158: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014915C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80149160: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80149164: bne         $t8, $t9, L_80149174
    if (ctx->r24 != ctx->r25) {
        // 0x80149168: swc1        $f18, 0xB34($v0)
        MEM_W(0XB34, ctx->r2) = ctx->f18.u32l;
            goto L_80149174;
    }
    // 0x80149168: swc1        $f18, 0xB34($v0)
    MEM_W(0XB34, ctx->r2) = ctx->f18.u32l;
    // 0x8014916C: b           L_80149174
    // 0x80149170: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80149174;
    // 0x80149170: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80149174:
    // 0x80149174: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80149178: lwc1        $f0, 0xB34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB34);
    // 0x8014917C: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    // 0x80149180: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80149184: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80149188: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014918C: beq         $a0, $zero, L_801491A0
    if (ctx->r4 == 0) {
        // 0x80149190: swc1        $f10, 0x60($v0)
        MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
            goto L_801491A0;
    }
    // 0x80149190: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    // 0x80149194: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80149198: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014919C: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
L_801491A0:
    // 0x801491A0: lbu         $t2, 0x18F($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18F);
    // 0x801491A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801491A8: sw          $t4, 0xB3C($v0)
    MEM_W(0XB3C, ctx->r2) = ctx->r12;
    // 0x801491AC: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x801491B0: sb          $t3, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r11;
    // 0x801491B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801491B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801491BC: jr          $ra
    // 0x801491C0: nop

    return;
    // 0x801491C0: nop

;}
RECOMP_FUNC void gmCameraApplyVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C6B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C6C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010C6C4: addiu       $a1, $a1, 0x14C4
    ctx->r5 = ADD32(ctx->r5, 0X14C4);
    // 0x8010C6C8: jal         0x80018FBC
    // 0x8010C6CC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    syVectorAdd3D(rdram, ctx);
        goto after_0;
    // 0x8010C6CC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x8010C6D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C6D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010C6D8: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010C6DC: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8010C6E0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8010C6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C6E8: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x8010C6EC: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8010C6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C6F4: jr          $ra
    // 0x8010C6F8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8010C6F8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void ftPhysicsClampAirVelXStickRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FC8: lb          $v0, 0x1C2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1C2);
    // 0x800D8FCC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800D8FD0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800D8FD4: bgez        $v0, L_800D8FE4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D8FD8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D8FE4;
    }
    // 0x800D8FD8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D8FDC: b           L_800D8FE4
    // 0x800D8FE0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_800D8FE4;
    // 0x800D8FE0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_800D8FE4:
    // 0x800D8FE4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D8FE8: bne         $at, $zero, L_800D903C
    if (ctx->r1 != 0) {
        // 0x800D8FEC: nop
    
            goto L_800D903C;
    }
    // 0x800D8FEC: nop

    // 0x800D8FF0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D8FF4: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D8FF8: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x800D8FFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D9000: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800D9004: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D9008: swc1        $f16, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f16.u32l;
    // 0x800D900C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D9010: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D9014: nop

    // 0x800D9018: bc1fl       L_800D902C
    if (!c1cs) {
        // 0x800D901C: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_800D902C;
    }
    goto skip_0;
    // 0x800D901C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_0:
    // 0x800D9020: jr          $ra
    // 0x800D9024: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D9024: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x800D9028: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_800D902C:
    // 0x800D902C: nop

    // 0x800D9030: bc1f        L_800D903C
    if (!c1cs) {
        // 0x800D9034: nop
    
            goto L_800D903C;
    }
    // 0x800D9034: nop

    // 0x800D9038: swc1        $f14, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f14.u32l;
L_800D903C:
    // 0x800D903C: jr          $ra
    // 0x800D9040: nop

    return;
    // 0x800D9040: nop

;}
RECOMP_FUNC void mpProcessCheckTestLWallCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB838: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800DB83C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DB840: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DB844: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DB848: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x800DB84C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800DB850: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DB854: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800DB858: lhu         $t7, 0x58($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X58);
    // 0x800DB85C: lhu         $t9, 0x5A($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X5A);
    // 0x800DB860: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x800DB864: andi        $t1, $t9, 0xFFFE
    ctx->r9 = ctx->r25 & 0XFFFE;
    // 0x800DB868: sh          $t8, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r24;
    // 0x800DB86C: sh          $t1, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r9;
    // 0x800DB870: jal         0x800D9510
    // 0x800DB874: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    mpProcessResetMultiWallCount(rdram, ctx);
        goto after_0;
    // 0x800DB874: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DB878: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800DB87C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800DB880: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DB884: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x800DB888: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB88C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800DB890: addiu       $s1, $t0, 0x38
    ctx->r17 = ADD32(ctx->r8, 0X38);
    // 0x800DB894: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DB898: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DB89C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DB8A0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB8A4: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DB8A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB8AC: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DB8B0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DB8B4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DB8B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DB8BC: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DB8C0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DB8C4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DB8C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB8CC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DB8D0: lhu         $t3, 0x5C($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X5C);
    // 0x800DB8D4: beq         $t2, $t3, L_800DB900
    if (ctx->r10 == ctx->r11) {
        // 0x800DB8D8: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DB900;
    }
    // 0x800DB8D8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DB8DC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DB8E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB8E4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DB8E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DB8EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DB8F0: jal         0x800F8974
    // 0x800DB8F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_1;
    // 0x800DB8F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800DB8F8: b           L_800DB920
    // 0x800DB8FC: nop

        goto L_800DB920;
    // 0x800DB8FC: nop

L_800DB900:
    // 0x800DB900: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DB904: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DB908: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB90C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DB910: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DB914: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DB918: jal         0x800F7F00
    // 0x800DB91C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_2;
    // 0x800DB91C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
L_800DB920:
    // 0x800DB920: beql        $v0, $zero, L_800DB93C
    if (ctx->r2 == 0) {
        // 0x800DB924: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_800DB93C;
    }
    goto skip_0;
    // 0x800DB924: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800DB928: jal         0x800D951C
    // 0x800DB92C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_3;
    // 0x800DB92C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800DB930: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DB934: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800DB938: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800DB93C:
    // 0x800DB93C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800DB940: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800DB944: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB948: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DB94C: lhu         $t6, 0x1398($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1398);
    // 0x800DB950: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DB954: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB958: lwc1        $f8, 0x8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800DB95C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DB960: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DB964: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DB968: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DB96C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DB970: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DB974: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DB978: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DB97C: lhu         $t8, 0x5C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X5C);
    // 0x800DB980: beq         $t6, $t8, L_800DB9A8
    if (ctx->r14 == ctx->r24) {
        // 0x800DB984: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DB9A8;
    }
    // 0x800DB984: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DB988: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DB98C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB990: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DB994: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DB998: jal         0x800F8974
    // 0x800DB99C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_4;
    // 0x800DB99C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x800DB9A0: b           L_800DB9C4
    // 0x800DB9A4: nop

        goto L_800DB9C4;
    // 0x800DB9A4: nop

L_800DB9A8:
    // 0x800DB9A8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DB9AC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DB9B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB9B4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DB9B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DB9BC: jal         0x800F7F00
    // 0x800DB9C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_5;
    // 0x800DB9C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
L_800DB9C4:
    // 0x800DB9C4: beq         $v0, $zero, L_800DB9D8
    if (ctx->r2 == 0) {
        // 0x800DB9C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800DB9D8;
    }
    // 0x800DB9C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DB9CC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800DB9D0: jal         0x800D951C
    // 0x800DB9D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_6;
    // 0x800DB9D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
L_800DB9D8:
    // 0x800DB9D8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800DB9DC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800DB9E0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800DB9E4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB9E8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DB9EC: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DB9F0: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DB9F4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB9F8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800DB9FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBA00: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBA04: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBA08: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800DBA0C: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DBA10: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBA14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DBA18: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800DBA1C: lhu         $t4, 0x5C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X5C);
    // 0x800DBA20: beq         $t2, $t4, L_800DBA48
    if (ctx->r10 == ctx->r12) {
        // 0x800DBA24: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DBA48;
    }
    // 0x800DBA24: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBA28: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBA2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBA30: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBA34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBA38: jal         0x800F8974
    // 0x800DBA3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_7;
    // 0x800DBA3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x800DBA40: b           L_800DBA64
    // 0x800DBA44: nop

        goto L_800DBA64;
    // 0x800DBA44: nop

L_800DBA48:
    // 0x800DBA48: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBA4C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBA50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBA54: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBA58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBA5C: jal         0x800F7F00
    // 0x800DBA60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_8;
    // 0x800DBA60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
L_800DBA64:
    // 0x800DBA64: beq         $v0, $zero, L_800DBA78
    if (ctx->r2 == 0) {
        // 0x800DBA68: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DBA78;
    }
    // 0x800DBA68: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DBA6C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DBA70: jal         0x800D951C
    // 0x800DBA74: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_9;
    // 0x800DBA74: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    after_9:
L_800DBA78:
    // 0x800DBA78: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBA7C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBA80: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBA84: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x800DBA88: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBA8C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DBA90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBA94: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBA98: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DBA9C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800DBAA0: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBAA4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBAA8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800DBAAC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DBAB0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBAB4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBAB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DBABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBAC0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DBAC4: jal         0x800F7F00
    // 0x800DBAC8: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_10;
    // 0x800DBAC8: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x800DBACC: beq         $v0, $zero, L_800DBAE0
    if (ctx->r2 == 0) {
        // 0x800DBAD0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DBAE0;
    }
    // 0x800DBAD0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DBAD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DBAD8: jal         0x800D951C
    // 0x800DBADC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_11;
    // 0x800DBADC: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    after_11:
L_800DBAE0:
    // 0x800DBAE0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBAE4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBAE8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBAEC: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DBAF0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBAF4: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DBAF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBAFC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBB00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBB04: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBB08: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBB0C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBB10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBB14: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DBB18: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBB1C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBB20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DBB24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBB28: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBB2C: jal         0x800F7F00
    // 0x800DBB30: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_12;
    // 0x800DBB30: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x800DBB34: beq         $v0, $zero, L_800DBB48
    if (ctx->r2 == 0) {
        // 0x800DBB38: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DBB48;
    }
    // 0x800DBB38: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DBB3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DBB40: jal         0x800D951C
    // 0x800DBB44: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_13;
    // 0x800DBB44: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_13:
L_800DBB48:
    // 0x800DBB48: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800DBB4C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800DBB50: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800DBB54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DBB58: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800DBB5C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DBB60: lhu         $t9, 0x1398($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1398);
    // 0x800DBB64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBB68: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBB6C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBB70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBB74: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DBB78: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DBB7C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800DBB80: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBB84: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBB88: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBB8C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBB90: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBB94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBB98: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DBB9C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBBA0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBBA4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBBA8: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DBBAC: lhu         $t3, 0x5C($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X5C);
    // 0x800DBBB0: beql        $t9, $t3, L_800DBBE0
    if (ctx->r25 == ctx->r11) {
        // 0x800DBBB4: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DBBE0;
    }
    goto skip_1;
    // 0x800DBBB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_1:
    // 0x800DBBB8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBBBC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBBC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBBC4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBBC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBBCC: jal         0x800F64D4
    // 0x800DBBD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_14;
    // 0x800DBBD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_14:
    // 0x800DBBD4: b           L_800DBBE8
    // 0x800DBBD8: nop

        goto L_800DBBE8;
    // 0x800DBBD8: nop

    // 0x800DBBDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DBBE0:
    // 0x800DBBE0: jal         0x800F5E90
    // 0x800DBBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_15;
    // 0x800DBBE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_15:
L_800DBBE8:
    // 0x800DBBE8: beql        $v0, $zero, L_800DBD30
    if (ctx->r2 == 0) {
        // 0x800DBBEC: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DBD30;
    }
    goto skip_2;
    // 0x800DBBEC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x800DBBF0: jal         0x800FABA4
    // 0x800DBBF4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpCollisionGetEdgeUpperLLineID(rdram, ctx);
        goto after_16;
    // 0x800DBBF4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x800DBBF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DBBFC: beq         $v0, $at, L_800DBD2C
    if (ctx->r2 == ctx->r1) {
        // 0x800DBC00: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DBD2C;
    }
    // 0x800DBC00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DBC04: jal         0x800FA8A4
    // 0x800DBC08: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_17;
    // 0x800DBC08: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_17:
    // 0x800DBC0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DBC10: bne         $v0, $at, L_800DBD2C
    if (ctx->r2 != ctx->r1) {
        // 0x800DBC14: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_800DBD2C;
    }
    // 0x800DBC14: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800DBC18: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800DBC1C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800DBC20: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800DBC24: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DBC28: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800DBC2C: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DBC30: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DBC34: lhu         $t5, 0x1398($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1398);
    // 0x800DBC38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DBC3C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBC40: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBC44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBC48: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DBC4C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBC50: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBC54: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DBC58: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DBC5C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBC60: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DBC64: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DBC68: lhu         $t6, 0x5C($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X5C);
    // 0x800DBC6C: beql        $t5, $t6, L_800DBC9C
    if (ctx->r13 == ctx->r14) {
        // 0x800DBC70: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DBC9C;
    }
    goto skip_3;
    // 0x800DBC70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_3:
    // 0x800DBC74: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBC78: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBC7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBC80: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBC84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBC88: jal         0x800F64D4
    // 0x800DBC8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_18;
    // 0x800DBC8C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_18:
    // 0x800DBC90: b           L_800DBCA4
    // 0x800DBC94: nop

        goto L_800DBCA4;
    // 0x800DBC94: nop

    // 0x800DBC98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DBC9C:
    // 0x800DBC9C: jal         0x800F5E90
    // 0x800DBCA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_19;
    // 0x800DBCA0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_19:
L_800DBCA4:
    // 0x800DBCA4: beq         $v0, $zero, L_800DBCB8
    if (ctx->r2 == 0) {
        // 0x800DBCA8: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_800DBCB8;
    }
    // 0x800DBCA8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800DBCAC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800DBCB0: beql        $t8, $t1, L_800DBD30
    if (ctx->r24 == ctx->r9) {
        // 0x800DBCB4: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DBD30;
    }
    goto skip_4;
    // 0x800DBCB4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_4:
L_800DBCB8:
    // 0x800DBCB8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBCBC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBCC0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBCC4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DBCC8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBCCC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DBCD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBCD4: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBCD8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBCDC: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBCE0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBCE4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBCE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBCEC: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DBCF0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBCF4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBCF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DBCFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBD00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBD04: jal         0x800F5E90
    // 0x800DBD08: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_20;
    // 0x800DBD08: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x800DBD0C: beq         $v0, $zero, L_800DBD1C
    if (ctx->r2 == 0) {
        // 0x800DBD10: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800DBD1C;
    }
    // 0x800DBD10: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800DBD14: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800DBD18: beq         $t9, $t3, L_800DBD2C
    if (ctx->r25 == ctx->r11) {
        // 0x800DBD1C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800DBD2C;
    }
L_800DBD1C:
    // 0x800DBD1C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DBD20: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800DBD24: jal         0x800D951C
    // 0x800DBD28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_21;
    // 0x800DBD28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_21:
L_800DBD2C:
    // 0x800DBD2C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_800DBD30:
    // 0x800DBD30: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DBD34: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800DBD38: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DBD3C: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800DBD40: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DBD44: lhu         $t5, 0x1398($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1398);
    // 0x800DBD48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBD4C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBD50: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBD54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBD58: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DBD5C: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DBD60: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800DBD64: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBD68: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800DBD6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBD70: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x800DBD74: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBD78: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBD7C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBD80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBD84: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DBD88: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBD8C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBD90: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBD94: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DBD98: lhu         $t8, 0x5C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X5C);
    // 0x800DBD9C: beql        $t5, $t8, L_800DBDCC
    if (ctx->r13 == ctx->r24) {
        // 0x800DBDA0: sw          $t9, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r25;
            goto L_800DBDCC;
    }
    goto skip_5;
    // 0x800DBDA0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    skip_5:
    // 0x800DBDA4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBDA8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBDAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBDB0: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DBDB4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800DBDB8: jal         0x800F521C
    // 0x800DBDBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_22;
    // 0x800DBDBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_22:
    // 0x800DBDC0: b           L_800DBDD4
    // 0x800DBDC4: nop

        goto L_800DBDD4;
    // 0x800DBDC4: nop

    // 0x800DBDC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
L_800DBDCC:
    // 0x800DBDCC: jal         0x800F4BD8
    // 0x800DBDD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_23;
    // 0x800DBDD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_23:
L_800DBDD4:
    // 0x800DBDD4: beq         $v0, $zero, L_800DBF24
    if (ctx->r2 == 0) {
        // 0x800DBDD8: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800DBF24;
    }
    // 0x800DBDD8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800DBDDC: andi        $t2, $t3, 0x4000
    ctx->r10 = ctx->r11 & 0X4000;
    // 0x800DBDE0: bnel        $t2, $zero, L_800DBF28
    if (ctx->r10 != 0) {
        // 0x800DBDE4: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800DBF28;
    }
    goto skip_6;
    // 0x800DBDE4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x800DBDE8: jal         0x800FAA24
    // 0x800DBDEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_24;
    // 0x800DBDEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_24:
    // 0x800DBDF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DBDF4: beq         $v0, $at, L_800DBF24
    if (ctx->r2 == ctx->r1) {
        // 0x800DBDF8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DBF24;
    }
    // 0x800DBDF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DBDFC: jal         0x800FA8A4
    // 0x800DBE00: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_25;
    // 0x800DBE00: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_25:
    // 0x800DBE04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DBE08: bne         $v0, $at, L_800DBF24
    if (ctx->r2 != ctx->r1) {
        // 0x800DBE0C: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DBF24;
    }
    // 0x800DBE0C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800DBE10: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DBE14: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DBE18: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800DBE1C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DBE20: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DBE24: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800DBE28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DBE2C: lhu         $t6, 0x1398($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1398);
    // 0x800DBE30: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DBE34: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBE38: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBE3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBE40: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DBE44: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBE48: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBE4C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DBE50: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DBE54: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBE58: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DBE5C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DBE60: lhu         $t8, 0x5C($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X5C);
    // 0x800DBE64: beql        $t6, $t8, L_800DBE94
    if (ctx->r14 == ctx->r24) {
        // 0x800DBE68: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DBE94;
    }
    goto skip_7;
    // 0x800DBE68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_7:
    // 0x800DBE6C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBE70: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBE74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBE78: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBE7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBE80: jal         0x800F521C
    // 0x800DBE84: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_26;
    // 0x800DBE84: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_26:
    // 0x800DBE88: b           L_800DBE9C
    // 0x800DBE8C: nop

        goto L_800DBE9C;
    // 0x800DBE8C: nop

    // 0x800DBE90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DBE94:
    // 0x800DBE94: jal         0x800F4BD8
    // 0x800DBE98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_27;
    // 0x800DBE98: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
L_800DBE9C:
    // 0x800DBE9C: beq         $v0, $zero, L_800DBEB0
    if (ctx->r2 == 0) {
        // 0x800DBEA0: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_800DBEB0;
    }
    // 0x800DBEA0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800DBEA4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800DBEA8: beql        $t1, $t9, L_800DBF28
    if (ctx->r9 == ctx->r25) {
        // 0x800DBEAC: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800DBF28;
    }
    goto skip_8;
    // 0x800DBEAC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_8:
L_800DBEB0:
    // 0x800DBEB0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBEB4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DBEB8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DBEBC: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DBEC0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBEC4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DBEC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DBECC: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DBED0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBED4: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DBED8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DBEDC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DBEE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DBEE4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DBEE8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DBEEC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DBEF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DBEF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DBEF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DBEFC: jal         0x800F4BD8
    // 0x800DBF00: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_28;
    // 0x800DBF00: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_28:
    // 0x800DBF04: beq         $v0, $zero, L_800DBF14
    if (ctx->r2 == 0) {
        // 0x800DBF08: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_800DBF14;
    }
    // 0x800DBF08: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800DBF0C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800DBF10: beq         $t3, $t2, L_800DBF24
    if (ctx->r11 == ctx->r10) {
        // 0x800DBF14: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800DBF24;
    }
L_800DBF14:
    // 0x800DBF14: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DBF18: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800DBF1C: jal         0x800D951C
    // 0x800DBF20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_29;
    // 0x800DBF20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
L_800DBF24:
    // 0x800DBF24: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800DBF28:
    // 0x800DBF28: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800DBF2C: beql        $t7, $zero, L_800DBF44
    if (ctx->r15 == 0) {
        // 0x800DBF30: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DBF44;
    }
    goto skip_9;
    // 0x800DBF30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x800DBF34: lhu         $t6, 0x56($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X56);
    // 0x800DBF38: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x800DBF3C: sh          $t8, 0x56($t5)
    MEM_H(0X56, ctx->r13) = ctx->r24;
    // 0x800DBF40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DBF44:
    // 0x800DBF44: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800DBF48: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DBF4C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DBF50: jr          $ra
    // 0x800DBF54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800DBF54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mnPlayersVSMakeHandicapLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C8C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80136C90: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80136C94: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80136C98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80136C9C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80136CA0: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136CA4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80136CA8: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x80136CAC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80136CB0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x80136CB4: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80136CB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80136CBC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80136CC0: beq         $a1, $zero, L_80136CD4
    if (ctx->r5 == 0) {
        // 0x80136CC4: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80136CD4;
    }
    // 0x80136CC4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80136CC8: jal         0x80009A84
    // 0x80136CCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80136CCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80136CD0: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
L_80136CD4:
    // 0x80136CD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136CD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136CDC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80136CE0: jal         0x80009968
    // 0x80136CE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80136CE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80136CE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80136CEC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80136CF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80136CF4: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
    // 0x80136CF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80136CFC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80136D00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136D04: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80136D08: jal         0x80009DF4
    // 0x80136D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80136D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80136D10: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80136D14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136D18: addiu       $a1, $a1, 0x6C18
    ctx->r5 = ADD32(ctx->r5, 0X6C18);
    // 0x80136D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136D24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80136D28: jal         0x80008188
    // 0x80136D2C: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80136D2C: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    after_3:
    // 0x80136D30: lw          $t1, 0x84($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X84);
    // 0x80136D34: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80136D38: addiu       $s1, $s1, -0x3B60
    ctx->r17 = ADD32(ctx->r17, -0X3B60);
    // 0x80136D3C: bne         $t1, $zero, L_80136D9C
    if (ctx->r9 != 0) {
        // 0x80136D40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80136D9C;
    }
    // 0x80136D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136D44: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80136D48: addiu       $s1, $s1, -0x3B60
    ctx->r17 = ADD32(ctx->r17, -0X3B60);
    // 0x80136D4C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80136D50: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80136D54: addiu       $t3, $t3, 0x1108
    ctx->r11 = ADD32(ctx->r11, 0X1108);
    // 0x80136D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136D5C: jal         0x800CCFDC
    // 0x80136D60: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80136D60: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_4:
    // 0x80136D64: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80136D68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80136D6C: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80136D70: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80136D74: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80136D78: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80136D7C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80136D80: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80136D84: addiu       $t4, $a2, 0x23
    ctx->r12 = ADD32(ctx->r6, 0X23);
    // 0x80136D88: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80136D8C: nop

    // 0x80136D90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136D94: b           L_80136DE4
    // 0x80136D98: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_80136DE4;
    // 0x80136D98: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_80136D9C:
    // 0x80136D9C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80136DA0: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80136DA4: addiu       $t6, $t6, 0x1218
    ctx->r14 = ADD32(ctx->r14, 0X1218);
    // 0x80136DA8: jal         0x800CCFDC
    // 0x80136DAC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80136DAC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x80136DB0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80136DB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80136DB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80136DBC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x80136DC0: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80136DC4: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80136DC8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80136DCC: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x80136DD0: addiu       $t7, $a2, 0x22
    ctx->r15 = ADD32(ctx->r6, 0X22);
    // 0x80136DD4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80136DD8: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x80136DDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80136DE0: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
L_80136DE4:
    // 0x80136DE4: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    // 0x80136DE8: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x80136DEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136DF0: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80136DF4: addiu       $t9, $zero, 0xC2
    ctx->r25 = ADD32(0, 0XC2);
    // 0x80136DF8: addiu       $t0, $zero, 0xBD
    ctx->r8 = ADD32(0, 0XBD);
    // 0x80136DFC: addiu       $t1, $zero, 0xAD
    ctx->r9 = ADD32(0, 0XAD);
    // 0x80136E00: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x80136E04: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80136E08: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
    // 0x80136E0C: sb          $t0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r8;
    // 0x80136E10: sb          $t1, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r9;
    // 0x80136E14: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x80136E18: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
    // 0x80136E1C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80136E20: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80136E24: addiu       $t7, $t7, -0x2310
    ctx->r15 = ADD32(ctx->r15, -0X2310);
    // 0x80136E28: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80136E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136E30: jal         0x800CCFDC
    // 0x80136E34: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80136E34: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x80136E38: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80136E3C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80136E40: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x80136E44: addiu       $t8, $a2, 0x3D
    ctx->r24 = ADD32(ctx->r6, 0X3D);
    // 0x80136E48: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80136E4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136E50: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80136E54: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80136E58: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80136E5C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80136E60: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80136E64: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80136E68: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80136E6C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80136E70: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80136E74: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80136E78: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80136E7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136E80: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80136E84: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80136E88: jr          $ra
    // 0x80136E8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80136E8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itGShellSpinInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178E0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178E10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80178E14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80178E18: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178E1C: lhu         $t8, 0x2D2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2D2);
    // 0x80178E20: lbu         $t6, 0x2CE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2CE);
    // 0x80178E24: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80178E28: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80178E2C: ori         $t0, $t9, 0x5780
    ctx->r8 = ctx->r25 | 0X5780;
    // 0x80178E30: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x80178E34: sb          $t7, 0x2CE($v0)
    MEM_B(0X2CE, ctx->r2) = ctx->r15;
    // 0x80178E38: bc1f        L_80178E48
    if (!c1cs) {
        // 0x80178E3C: sh          $t0, 0x2D2($v0)
        MEM_H(0X2D2, ctx->r2) = ctx->r8;
            goto L_80178E48;
    }
    // 0x80178E3C: sh          $t0, 0x2D2($v0)
    MEM_H(0X2D2, ctx->r2) = ctx->r8;
    // 0x80178E40: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80178E44: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_80178E48:
    // 0x80178E48: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80178E4C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80178E50: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80178E54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80178E58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80178E5C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80178E60: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80178E64: bc1fl       L_80178E78
    if (!c1cs) {
        // 0x80178E68: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80178E78;
    }
    goto skip_0;
    // 0x80178E68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80178E6C: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80178E70: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80178E74: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80178E78:
    // 0x80178E78: nop

    // 0x80178E7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80178E80: swc1        $f2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f2.u32l;
    // 0x80178E84: bc1fl       L_80178E98
    if (!c1cs) {
        // 0x80178E88: sw          $t2, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r10;
            goto L_80178E98;
    }
    goto skip_1;
    // 0x80178E88: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    skip_1:
    // 0x80178E8C: b           L_80178E98
    // 0x80178E90: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
        goto L_80178E98;
    // 0x80178E90: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x80178E94: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
L_80178E98:
    // 0x80178E98: sb          $t3, 0x351($v0)
    MEM_B(0X351, ctx->r2) = ctx->r11;
    // 0x80178E9C: sb          $t4, 0x350($v0)
    MEM_B(0X350, ctx->r2) = ctx->r12;
    // 0x80178EA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178EA4: jal         0x80178670
    // 0x80178EA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itGShellSpinAddAnim(rdram, ctx);
        goto after_0;
    // 0x80178EA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80178EAC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178EB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80178EB4: lbu         $t5, 0x2CF($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2CF);
    // 0x80178EB8: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x80178EBC: jal         0x8017275C
    // 0x80178EC0: sb          $t6, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r14;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_1;
    // 0x80178EC0: sb          $t6, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r14;
    after_1:
    // 0x80178EC4: jal         0x800269C0
    // 0x80178EC8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80178EC8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_2:
    // 0x80178ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178ED4: jr          $ra
    // 0x80178ED8: nop

    return;
    // 0x80178ED8: nop

;}
RECOMP_FUNC void ftCommonKneeBendSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F3A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013F3A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013F3A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8013F3AC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F3B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013F3B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013F3B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013F3BC: jal         0x800E6F24
    // 0x8013F3C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F3C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013F3C4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013F3C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8013F3CC: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x8013F3D0: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x8013F3D4: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x8013F3D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013F3DC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8013F3E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013F3E4: swc1        $f6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f6.u32l;
    // 0x8013F3E8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8013F3EC: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
    // 0x8013F3F0: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
    // 0x8013F3F4: sw          $t7, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r15;
    // 0x8013F3F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F3FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013F400: jr          $ra
    // 0x8013F404: nop

    return;
    // 0x8013F404: nop

;}
RECOMP_FUNC void itManagerMakeItemKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016F23C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8016F240: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F244: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8016F248: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8016F24C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016F250: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8016F254: lw          $t9, -0x6B94($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6B94);
    // 0x8016F258: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8016F25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016F260: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8016F264: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8016F268: jalr        $t9
    // 0x8016F26C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8016F26C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x8016F270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016F274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016F278: jr          $ra
    // 0x8016F27C: nop

    return;
    // 0x8016F27C: nop

;}
RECOMP_FUNC void func_ovl8_80382D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382D90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80382D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382D98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80382D9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80382DA0: jal         0x803717A0
    // 0x80382DA4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382DA4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80382DA8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80382DAC: beq         $v0, $zero, L_80382DDC
    if (ctx->r2 == 0) {
        // 0x80382DB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80382DDC;
    }
    // 0x80382DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80382DB4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80382DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80382DC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80382DC4: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80382DC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80382DCC: jal         0x80382EA8
    // 0x80382DD0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_80382EA8(rdram, ctx);
        goto after_1;
    // 0x80382DD0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x80382DD4: b           L_80382DE0
    // 0x80382DD8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80382DE0;
    // 0x80382DD8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80382DDC:
    // 0x80382DDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80382DE0:
    // 0x80382DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382DE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80382DE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80382DEC: jr          $ra
    // 0x80382DF0: nop

    return;
    // 0x80382DF0: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BE08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BE0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BE10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015BE14: jal         0x800DEE98
    // 0x8015BE18: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015BE18: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015BE1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015BE20: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015BE24: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015BE28: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015BE2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015BE30: jal         0x800E6F24
    // 0x8015BE34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BE34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015BE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BE40: jr          $ra
    // 0x8015BE44: nop

    return;
    // 0x8015BE44: nop

;}
RECOMP_FUNC void itDisplayColAnimOPAProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171F4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80171F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171F54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80171F58: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80171F5C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80171F60: jal         0x80171C10
    // 0x80171F64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x80171F64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80171F68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80171F6C: beq         $v0, $zero, L_80171FF8
    if (ctx->r2 == 0) {
        // 0x80171F70: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80171FF8;
    }
    // 0x80171F70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80171F74: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x80171F78: beq         $v0, $zero, L_80171F94
    if (ctx->r2 == 0) {
        // 0x80171F7C: nop
    
            goto L_80171F94;
    }
    // 0x80171F7C: nop

    // 0x80171F80: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    // 0x80171F84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80171F88: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80171F8C: bgez        $t8, L_80171FA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80171F90: nop
    
            goto L_80171FA4;
    }
    // 0x80171F90: nop

L_80171F94:
    // 0x80171F94: jal         0x80171DF4
    // 0x80171F98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayColAnimOPA(rdram, ctx);
        goto after_1;
    // 0x80171F98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80171F9C: b           L_80171FFC
    // 0x80171FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171FFC;
    // 0x80171FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171FA4:
    // 0x80171FA4: bnel        $v0, $at, L_80171FCC
    if (ctx->r2 != ctx->r1) {
        // 0x80171FA8: lw          $t9, 0x248($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X248);
            goto L_80171FCC;
    }
    goto skip_0;
    // 0x80171FA8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
    skip_0:
    // 0x80171FAC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80171FB0: jal         0x80171DF4
    // 0x80171FB4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    itDisplayColAnimOPA(rdram, ctx);
        goto after_2;
    // 0x80171FB4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80171FB8: jal         0x801719AC
    // 0x80171FBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80171FBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80171FC0: b           L_80171FFC
    // 0x80171FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171FFC;
    // 0x80171FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171FC8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
L_80171FCC:
    // 0x80171FCC: bne         $t9, $zero, L_80171FF0
    if (ctx->r25 != 0) {
        // 0x80171FD0: nop
    
            goto L_80171FF0;
    }
    // 0x80171FD0: nop

    // 0x80171FD4: lw          $t0, 0x10C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10C);
    // 0x80171FD8: bne         $t0, $zero, L_80171FF0
    if (ctx->r8 != 0) {
        // 0x80171FDC: nop
    
            goto L_80171FF0;
    }
    // 0x80171FDC: nop

    // 0x80171FE0: jal         0x80171DF4
    // 0x80171FE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayColAnimOPA(rdram, ctx);
        goto after_4;
    // 0x80171FE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80171FE8: b           L_80171FFC
    // 0x80171FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171FFC;
    // 0x80171FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171FF0:
    // 0x80171FF0: jal         0x80171410
    // 0x80171FF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x80171FF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_80171FF8:
    // 0x80171FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171FFC:
    // 0x80171FFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80172000: jr          $ra
    // 0x80172004: nop

    return;
    // 0x80172004: nop

;}
RECOMP_FUNC void ftBossOkupunch1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A7A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A7A8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015A7AC: jal         0x800D9480
    // 0x8015A7B0: addiu       $a1, $a1, -0x56B0
    ctx->r5 = ADD32(ctx->r5, -0X56B0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A7B0: addiu       $a1, $a1, -0x56B0
    ctx->r5 = ADD32(ctx->r5, -0X56B0);
    after_0:
    // 0x8015A7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A7BC: jr          $ra
    // 0x8015A7C0: nop

    return;
    // 0x8015A7C0: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801621F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801621F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801621F8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801621FC: jal         0x800D9480
    // 0x80162200: addiu       $a1, $a1, 0x2FE0
    ctx->r5 = ADD32(ctx->r5, 0X2FE0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80162200: addiu       $a1, $a1, 0x2FE0
    ctx->r5 = ADD32(ctx->r5, 0X2FE0);
    after_0:
    // 0x80162204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016220C: jr          $ra
    // 0x80162210: nop

    return;
    // 0x80162210: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitItemOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F0FC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F100: addiu       $a1, $a1, 0xB58
    ctx->r5 = ADD32(ctx->r5, 0XB58);
    // 0x8018F104: lw          $t6, 0x30($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X30);
    // 0x8018F108: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8018F10C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018F110: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8018F114: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
    // 0x8018F118: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018F11C: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018F120: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
L_8018F124:
    // 0x8018F124: lw          $t7, 0x30($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X30);
    // 0x8018F128: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8018F12C: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8018F130: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018F134: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018F138: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018F13C: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
    // 0x8018F140: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x8018F144: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8018F148: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018F14C: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018F150: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018F154: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8018F158: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x8018F15C: lw          $v1, 0x8($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X8);
    // 0x8018F160: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018F164: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018F168: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018F16C: lw          $t3, 0x30($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X30);
    // 0x8018F170: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x8018F174: lw          $v1, 0xC($t4)
    ctx->r3 = MEM_W(ctx->r12, 0XC);
    // 0x8018F178: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8018F17C: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018F180: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018F184: bne         $a0, $v0, L_8018F124
    if (ctx->r4 != ctx->r2) {
        // 0x8018F188: sb          $a2, 0x1A($v1)
        MEM_B(0X1A, ctx->r3) = ctx->r6;
            goto L_8018F124;
    }
    // 0x8018F188: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018F18C: jr          $ra
    // 0x8018F190: nop

    return;
    // 0x8018F190: nop

;}
RECOMP_FUNC void scExplainFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E570: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E574: jal         0x800188E8
    // 0x8018E578: addiu       $a0, $a0, -0x18DC
    ctx->r4 = ADD32(ctx->r4, -0X18DC);
    syUtilsSetRandomSeedPtr(rdram, ctx);
        goto after_0;
    // 0x8018E578: addiu       $a0, $a0, -0x18DC
    ctx->r4 = ADD32(ctx->r4, -0X18DC);
    after_0:
    // 0x8018E57C: jal         0x8000A5E4
    // 0x8018E580: nop

    gcRunAll(rdram, ctx);
        goto after_1;
    // 0x8018E580: nop

    after_1:
    // 0x8018E584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E58C: jr          $ra
    // 0x8018E590: nop

    return;
    // 0x8018E590: nop

;}
RECOMP_FUNC void itLinkBombFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80185FE4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80185FE8: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80185FEC: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80185FF0: jal         0x80173F78
    // 0x80185FF4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80185FF4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80185FF8: jal         0x80185CD4
    // 0x80185FFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itLinkBombCommonSetHitStatusNormal(rdram, ctx);
        goto after_1;
    // 0x80185FFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80186000: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80186004: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80186008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018600C: jal         0x80172EC8
    // 0x80186010: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80186010: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80186014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018601C: jr          $ra
    // 0x80186020: nop

    return;
    // 0x80186020: nop

;}
RECOMP_FUNC void ftLinkSpecialLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016443C: jal         0x801643D0
    // 0x80164440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftLinkSpecialLwMakeBomb(rdram, ctx);
        goto after_0;
    // 0x80164440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164444: jal         0x800D94C4
    // 0x80164448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x80164448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016444C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164454: jr          $ra
    // 0x80164458: nop

    return;
    // 0x80164458: nop

;}
RECOMP_FUNC void wpYoshiStarMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C834: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016C838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C83C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8016C840: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8016C844: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x8016C848: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8016C84C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8016C850: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8016C854: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C858: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016C85C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8016C860: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8016C864: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016C868: addiu       $a1, $a1, -0x6CE0
    ctx->r5 = ADD32(ctx->r5, -0X6CE0);
    // 0x8016C86C: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8016C870: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016C874: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8016C878: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8016C87C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016C880: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8016C884: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8016C888: bne         $t9, $at, L_8016C8A8
    if (ctx->r25 != ctx->r1) {
        // 0x8016C88C: swc1        $f8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
            goto L_8016C8A8;
    }
    // 0x8016C88C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8016C890: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8016C894: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016C898: nop

    // 0x8016C89C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016C8A0: b           L_8016C8BC
    // 0x8016C8A4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
        goto L_8016C8BC;
    // 0x8016C8A4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
L_8016C8A8:
    // 0x8016C8A8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8016C8AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016C8B0: nop

    // 0x8016C8B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016C8B8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_8016C8BC:
    // 0x8016C8BC: jal         0x801655C8
    // 0x8016C8C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016C8C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8016C8C4: bne         $v0, $zero, L_8016C8D4
    if (ctx->r2 != 0) {
        // 0x8016C8C8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8016C8D4;
    }
    // 0x8016C8C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8016C8CC: b           L_8016C944
    // 0x8016C8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016C944;
    // 0x8016C8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016C8D4:
    // 0x8016C8D4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8016C8D8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8016C8DC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8016C8E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C8E4: sw          $t1, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r9;
    // 0x8016C8E8: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x8016C8EC: lwc1        $f12, -0x34B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X34B0);
    // 0x8016C8F0: jal         0x80035CD0
    // 0x8016C8F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016C8F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x8016C8F8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8016C8FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8016C900: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016C904: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x8016C908: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C90C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8016C910: nop

    // 0x8016C914: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016C918: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8016C91C: nop

    // 0x8016C920: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8016C924: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8016C928: jal         0x800303F0
    // 0x8016C92C: lwc1        $f12, -0x34AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X34AC);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016C92C: lwc1        $f12, -0x34AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X34AC);
    after_2:
    // 0x8016C930: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8016C934: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016C938: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8016C93C: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016C940: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
L_8016C944:
    // 0x8016C944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C948: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8016C94C: jr          $ra
    // 0x8016C950: nop

    return;
    // 0x8016C950: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPortraitFlashThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133FB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133FB8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80133FBC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80133FC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133FC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133FC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80133FCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133FD0: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80133FD4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80133FD8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80133FDC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80133FE0:
    // 0x80133FE0: bne         $s2, $zero, L_80133FF0
    if (ctx->r18 != 0) {
        // 0x80133FE4: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80133FF0;
    }
    // 0x80133FE4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80133FE8: jal         0x80133F68
    // 0x80133FEC: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    mnPlayers1PTrainingDestroyPortraitFlash(rdram, ctx);
        goto after_0;
    // 0x80133FEC: lw          $a0, 0x84($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X84);
    after_0:
L_80133FF0:
    // 0x80133FF0: bne         $s0, $zero, L_80134014
    if (ctx->r16 != 0) {
        // 0x80133FF4: nop
    
            goto L_80134014;
    }
    // 0x80133FF4: nop

    // 0x80133FF8: lw          $t6, 0x7C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X7C);
    // 0x80133FFC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80134000: bnel        $s3, $t6, L_80134014
    if (ctx->r19 != ctx->r14) {
        // 0x80134004: sw          $s3, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->r19;
            goto L_80134014;
    }
    goto skip_0;
    // 0x80134004: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
    skip_0:
    // 0x80134008: b           L_80134014
    // 0x8013400C: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
        goto L_80134014;
    // 0x8013400C: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x80134010: sw          $s3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r19;
L_80134014:
    // 0x80134014: jal         0x8000B1E8
    // 0x80134018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x80134018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8013401C: b           L_80133FE0
    // 0x80134020: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80133FE0;
    // 0x80134020: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80134024: nop

    // 0x80134028: nop

    // 0x8013402C: nop

    // 0x80134030: nop

    // 0x80134034: nop

    // 0x80134038: nop

    // 0x8013403C: nop

    // 0x80134040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134044: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134048: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013404C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80134050: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80134054: jr          $ra
    // 0x80134058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80134058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gcGetSObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008030: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80008034: addiu       $a2, $a2, 0x6A3C
    ctx->r6 = ADD32(ctx->r6, 0X6A3C);
    // 0x80008038: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000803C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008044: bne         $v1, $zero, L_8000806C
    if (ctx->r3 != 0) {
        // 0x80008048: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_8000806C;
    }
    // 0x80008048: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000804C: lhu         $a0, 0x6A44($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6A44);
    // 0x80008050: jal         0x80004980
    // 0x80008054: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80008054: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80008058: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000805C: addiu       $a2, $a2, 0x6A3C
    ctx->r6 = ADD32(ctx->r6, 0X6A3C);
    // 0x80008060: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80008064: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80008068: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_8000806C:
    // 0x8000806C: bne         $v1, $zero, L_80008088
    if (ctx->r3 != 0) {
        // 0x80008070: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80008088;
    }
    // 0x80008070: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80008074: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80008078: jal         0x80023624
    // 0x8000807C: addiu       $a0, $a0, -0x2608
    ctx->r4 = ADD32(ctx->r4, -0X2608);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8000807C: addiu       $a0, $a0, -0x2608
    ctx->r4 = ADD32(ctx->r4, -0X2608);
    after_1:
L_80008080:
    // 0x80008080: b           L_80008080
    pause_self(rdram);
    // 0x80008084: nop

L_80008088:
    // 0x80008088: addiu       $a1, $a1, 0x6A40
    ctx->r5 = ADD32(ctx->r5, 0X6A40);
    // 0x8000808C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80008090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008094: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80008098: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000809C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800080A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800080A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800080A8: jr          $ra
    // 0x800080AC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x800080AC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void ftPhysicsCheckClampAirVelXDec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8EDC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800D8EE0: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D8EE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D8EEC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800D8EF0: nop

    // 0x800D8EF4: bc1fl       L_800D8F08
    if (!c1cs) {
        // 0x800D8EF8: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D8F08;
    }
    goto skip_0;
    // 0x800D8EF8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x800D8EFC: b           L_800D8F08
    // 0x800D8F00: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800D8F08;
    // 0x800D8F00: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800D8F04: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800D8F08:
    // 0x800D8F08: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D8F0C: nop

    // 0x800D8F10: bc1f        L_800D8FA0
    if (!c1cs) {
        // 0x800D8F14: nop
    
            goto L_800D8FA0;
    }
    // 0x800D8F14: nop

    // 0x800D8F18: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800D8F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D8F20: bc1fl       L_800D8F3C
    if (!c1cs) {
        // 0x800D8F24: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800D8F3C;
    }
    goto skip_1;
    // 0x800D8F24: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x800D8F28: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800D8F2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D8F30: b           L_800D8F44
    // 0x800D8F34: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800D8F44;
    // 0x800D8F34: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800D8F38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800D8F3C:
    // 0x800D8F3C: nop

    // 0x800D8F40: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
L_800D8F44:
    // 0x800D8F44: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x800D8F48: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D8F4C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800D8F50: nop

    // 0x800D8F54: bc1fl       L_800D8F68
    if (!c1cs) {
        // 0x800D8F58: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D8F68;
    }
    goto skip_2;
    // 0x800D8F58: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_2:
    // 0x800D8F5C: b           L_800D8F68
    // 0x800D8F60: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800D8F68;
    // 0x800D8F60: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800D8F64: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800D8F68:
    // 0x800D8F68: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D8F6C: nop

    // 0x800D8F70: bc1f        L_800D8F98
    if (!c1cs) {
        // 0x800D8F74: nop
    
            goto L_800D8F98;
    }
    // 0x800D8F74: nop

    // 0x800D8F78: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800D8F7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D8F80: bc1fl       L_800D8F94
    if (!c1cs) {
        // 0x800D8F84: neg.s       $f6, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
            goto L_800D8F94;
    }
    goto skip_3;
    // 0x800D8F84: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    skip_3:
    // 0x800D8F88: jr          $ra
    // 0x800D8F8C: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800D8F8C: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
    // 0x800D8F90: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
L_800D8F94:
    // 0x800D8F94: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
L_800D8F98:
    // 0x800D8F98: jr          $ra
    // 0x800D8F9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D8F9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D8FA0:
    // 0x800D8FA0: jr          $ra
    // 0x800D8FA4: nop

    return;
    // 0x800D8FA4: nop

;}
RECOMP_FUNC void efManagerMBallThrownMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102D18: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80102D1C: addiu       $a2, $a2, -0x1A7C
    ctx->r6 = ADD32(ctx->r6, -0X1A7C);
    // 0x80102D20: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x80102D24: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80102D28: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80102D2C: lw          $t7, -0x2FC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2FC0);
    // 0x80102D30: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80102D34: addiu       $t8, $t8, 0x6E4
    ctx->r24 = ADD32(ctx->r24, 0X6E4);
    // 0x80102D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102D3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80102D40: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80102D44: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80102D48: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80102D4C: addiu       $t0, $t0, -0x6BD0
    ctx->r8 = ADD32(ctx->r8, -0X6BD0);
    // 0x80102D50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80102D54: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80102D58: bne         $a1, $at, L_80102D7C
    if (ctx->r5 != ctx->r1) {
        // 0x80102D5C: sw          $t1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r9;
            goto L_80102D7C;
    }
    // 0x80102D5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80102D60: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80102D64: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80102D68: addiu       $t2, $t2, -0x6970
    ctx->r10 = ADD32(ctx->r10, -0X6970);
    // 0x80102D6C: addiu       $t3, $t3, -0x67F0
    ctx->r11 = ADD32(ctx->r11, -0X67F0);
    // 0x80102D70: sw          $t2, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r10;
    // 0x80102D74: b           L_80102D94
    // 0x80102D78: sw          $t3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r11;
        goto L_80102D94;
    // 0x80102D78: sw          $t3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r11;
L_80102D7C:
    // 0x80102D7C: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80102D80: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80102D84: addiu       $t4, $t4, -0x6A20
    ctx->r12 = ADD32(ctx->r12, -0X6A20);
    // 0x80102D88: addiu       $t5, $t5, -0x68C0
    ctx->r13 = ADD32(ctx->r13, -0X68C0);
    // 0x80102D8C: sw          $t4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r12;
    // 0x80102D90: sw          $t5, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r13;
L_80102D94:
    // 0x80102D94: jal         0x800FDAFC
    // 0x80102D98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102D98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80102D9C: bne         $v0, $zero, L_80102DAC
    if (ctx->r2 != 0) {
        // 0x80102DA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80102DAC;
    }
    // 0x80102DA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80102DA4: b           L_80102DDC
    // 0x80102DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102DDC;
    // 0x80102DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102DAC:
    // 0x80102DAC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80102DB0: lw          $v0, 0x74($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X74);
    // 0x80102DB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102DB8: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80102DBC: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x80102DC0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102DC4: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x80102DC8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102DCC: sw          $t8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r24;
    // 0x80102DD0: jal         0x800FD60C
    // 0x80102DD4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    efManagerSortZNeg(rdram, ctx);
        goto after_1;
    // 0x80102DD4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80102DD8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80102DDC:
    // 0x80102DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102DE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80102DE4: jr          $ra
    // 0x80102DE8: nop

    return;
    // 0x80102DE8: nop

;}
RECOMP_FUNC void wpFoxBlasterProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016898C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168994: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168998: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016899C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801689A0: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x801689A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801689A8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801689AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801689B0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x801689B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801689B8: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x801689BC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801689C0: jal         0x80019438
    // 0x801689C4: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x801689C4: nop

    after_0:
    // 0x801689C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801689CC: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801689D0: jal         0x8001863C
    // 0x801689D4: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x801689D4: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x801689D8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801689DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801689E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801689E4: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x801689E8: swc1        $f0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f0.u32l;
    // 0x801689EC: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x801689F0: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x801689F4: lw          $a0, 0x74($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X74);
    // 0x801689F8: jal         0x80103320
    // 0x801689FC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerFoxBlasterGlowMakeEffect(rdram, ctx);
        goto after_2;
    // 0x801689FC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x80168A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168A04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80168A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168A0C: jr          $ra
    // 0x80168A10: nop

    return;
    // 0x80168A10: nop

;}
RECOMP_FUNC void func_ovl8_80387540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80387544: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80387548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038754C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80387550: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80387554: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80387558: jal         0x8003935C
    // 0x8038755C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __f_to_ll_recomp(rdram, ctx);
        goto after_0;
    // 0x8038755C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80387560: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387564: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80387568: jal         0x8038746C
    // 0x8038756C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    stringFromNumber(rdram, ctx);
        goto after_1;
    // 0x8038756C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x80387570: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80387574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80387578: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8038757C: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80387580: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80387584: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80387588: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8038758C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80387590: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80387594: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x80387598: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8038759C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803875A0: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x803875A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x803875A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x803875AC: sub.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x803875B0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x803875B4: beq         $s0, $zero, L_803875C4
    if (ctx->r16 == 0) {
        // 0x803875B8: nop
    
            goto L_803875C4;
    }
    // 0x803875B8: nop

    // 0x803875BC: b           L_803875C4
    // 0x803875C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
        goto L_803875C4;
    // 0x803875C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_803875C4:
    // 0x803875C4: beq         $a1, $zero, L_80387980
    if (ctx->r5 == 0) {
        // 0x803875C8: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80387980;
    }
    // 0x803875C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803875CC: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x803875D0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x803875D4: beq         $v1, $zero, L_803876A4
    if (ctx->r3 == 0) {
        // 0x803875D8: addu        $v0, $v1, $a1
        ctx->r2 = ADD32(ctx->r3, ctx->r5);
            goto L_803876A4;
    }
    // 0x803875D8: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x803875DC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_803875E0:
    // 0x803875E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803875E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x803875E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803875EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803875F0: cvt.w.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = CVT_W_S(ctx->f12.fl);
    // 0x803875F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x803875F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x803875FC: nop

    // 0x80387600: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80387604: beql        $t0, $zero, L_80387654
    if (ctx->r8 == 0) {
        // 0x80387608: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_80387654;
    }
    goto skip_0;
    // 0x80387608: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8038760C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80387610: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80387614: sub.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80387618: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8038761C: nop

    // 0x80387620: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80387624: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80387628: nop

    // 0x8038762C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80387630: bne         $t0, $zero, L_80387648
    if (ctx->r8 != 0) {
        // 0x80387634: nop
    
            goto L_80387648;
    }
    // 0x80387634: nop

    // 0x80387638: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8038763C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80387640: b           L_80387660
    // 0x80387644: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80387660;
    // 0x80387644: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80387648:
    // 0x80387648: b           L_80387660
    // 0x8038764C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80387660;
    // 0x8038764C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80387650: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_80387654:
    // 0x80387654: nop

    // 0x80387658: bltz        $t0, L_80387648
    if (SIGNED(ctx->r8) < 0) {
        // 0x8038765C: nop
    
            goto L_80387648;
    }
    // 0x8038765C: nop

L_80387660:
    // 0x80387660: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80387664: addiu       $t1, $t0, 0x30
    ctx->r9 = ADD32(ctx->r8, 0X30);
    // 0x80387668: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8038766C: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80387670: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x80387674: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80387678: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8038767C: nop

    // 0x80387680: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80387684: nop

    // 0x80387688: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8038768C: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80387690: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80387694: bnel        $v0, $s0, L_803875E0
    if (ctx->r2 != ctx->r16) {
        // 0x80387698: cfc1        $t9, $FpcCsr
        ctx->r25 = get_cop1_cs();
            goto L_803875E0;
    }
    goto skip_1;
    // 0x80387698: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    skip_1:
    // 0x8038769C: beql        $s0, $zero, L_80387984
    if (ctx->r16 == 0) {
        // 0x803876A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80387984;
    }
    goto skip_2;
    // 0x803876A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_803876A4:
    // 0x803876A4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
L_803876A8:
    // 0x803876A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x803876AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x803876B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803876B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803876B8: cvt.w.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = CVT_W_S(ctx->f12.fl);
    // 0x803876BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x803876C0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x803876C4: nop

    // 0x803876C8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x803876CC: beql        $t5, $zero, L_8038771C
    if (ctx->r13 == 0) {
        // 0x803876D0: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_8038771C;
    }
    goto skip_3;
    // 0x803876D0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x803876D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x803876D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x803876DC: sub.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x803876E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x803876E4: nop

    // 0x803876E8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x803876EC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x803876F0: nop

    // 0x803876F4: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x803876F8: bne         $t5, $zero, L_80387710
    if (ctx->r13 != 0) {
        // 0x803876FC: nop
    
            goto L_80387710;
    }
    // 0x803876FC: nop

    // 0x80387700: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80387704: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80387708: b           L_80387728
    // 0x8038770C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80387728;
    // 0x8038770C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80387710:
    // 0x80387710: b           L_80387728
    // 0x80387714: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80387728;
    // 0x80387714: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80387718: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_8038771C:
    // 0x8038771C: nop

    // 0x80387720: bltz        $t5, L_80387710
    if (SIGNED(ctx->r13) < 0) {
        // 0x80387724: nop
    
            goto L_80387710;
    }
    // 0x80387724: nop

L_80387728:
    // 0x80387728: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8038772C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80387730: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x80387734: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80387738: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x8038773C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80387740: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80387744: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80387748: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8038774C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80387750: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80387754: nop

    // 0x80387758: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8038775C: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80387760: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80387764: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80387768: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8038776C: nop

    // 0x80387770: cvt.w.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80387774: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80387778: nop

    // 0x8038777C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80387780: beql        $t0, $zero, L_803877D0
    if (ctx->r8 == 0) {
        // 0x80387784: mfc1        $t0, $f6
        ctx->r8 = (int32_t)ctx->f6.u32l;
            goto L_803877D0;
    }
    goto skip_4;
    // 0x80387784: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    skip_4:
    // 0x80387788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8038778C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80387790: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80387794: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80387798: nop

    // 0x8038779C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x803877A0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x803877A4: nop

    // 0x803877A8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x803877AC: bne         $t0, $zero, L_803877C4
    if (ctx->r8 != 0) {
        // 0x803877B0: nop
    
            goto L_803877C4;
    }
    // 0x803877B0: nop

    // 0x803877B4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x803877B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803877BC: b           L_803877DC
    // 0x803877C0: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_803877DC;
    // 0x803877C0: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_803877C4:
    // 0x803877C4: b           L_803877DC
    // 0x803877C8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_803877DC;
    // 0x803877C8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x803877CC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
L_803877D0:
    // 0x803877D0: nop

    // 0x803877D4: bltz        $t0, L_803877C4
    if (SIGNED(ctx->r8) < 0) {
        // 0x803877D8: nop
    
            goto L_803877C4;
    }
    // 0x803877D8: nop

L_803877DC:
    // 0x803877DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x803877E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x803877E4: addiu       $t1, $t0, 0x30
    ctx->r9 = ADD32(ctx->r8, 0X30);
    // 0x803877E8: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x803877EC: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x803877F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803877F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803877F8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x803877FC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80387800: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80387804: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80387808: nop

    // 0x8038780C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80387810: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80387814: mul.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80387818: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8038781C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80387820: nop

    // 0x80387824: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80387828: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8038782C: nop

    // 0x80387830: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80387834: beql        $t5, $zero, L_80387884
    if (ctx->r13 == 0) {
        // 0x80387838: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_80387884;
    }
    goto skip_5;
    // 0x80387838: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_5:
    // 0x8038783C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80387840: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80387844: sub.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80387848: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8038784C: nop

    // 0x80387850: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80387854: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80387858: nop

    // 0x8038785C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80387860: bne         $t5, $zero, L_80387878
    if (ctx->r13 != 0) {
        // 0x80387864: nop
    
            goto L_80387878;
    }
    // 0x80387864: nop

    // 0x80387868: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8038786C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80387870: b           L_80387890
    // 0x80387874: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80387890;
    // 0x80387874: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80387878:
    // 0x80387878: b           L_80387890
    // 0x8038787C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80387890;
    // 0x8038787C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80387880: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_80387884:
    // 0x80387884: nop

    // 0x80387888: bltz        $t5, L_80387878
    if (SIGNED(ctx->r13) < 0) {
        // 0x8038788C: nop
    
            goto L_80387878;
    }
    // 0x8038788C: nop

L_80387890:
    // 0x80387890: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80387894: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80387898: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x8038789C: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x803878A0: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x803878A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803878A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803878AC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x803878B0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x803878B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x803878B8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x803878BC: nop

    // 0x803878C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x803878C4: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x803878C8: mul.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x803878CC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x803878D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x803878D4: nop

    // 0x803878D8: cvt.w.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = CVT_W_S(ctx->f12.fl);
    // 0x803878DC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x803878E0: nop

    // 0x803878E4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x803878E8: beql        $t0, $zero, L_80387938
    if (ctx->r8 == 0) {
        // 0x803878EC: mfc1        $t0, $f18
        ctx->r8 = (int32_t)ctx->f18.u32l;
            goto L_80387938;
    }
    goto skip_6;
    // 0x803878EC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x803878F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x803878F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x803878F8: sub.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x803878FC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80387900: nop

    // 0x80387904: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80387908: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8038790C: nop

    // 0x80387910: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80387914: bne         $t0, $zero, L_8038792C
    if (ctx->r8 != 0) {
        // 0x80387918: nop
    
            goto L_8038792C;
    }
    // 0x80387918: nop

    // 0x8038791C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80387920: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80387924: b           L_80387944
    // 0x80387928: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80387944;
    // 0x80387928: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8038792C:
    // 0x8038792C: b           L_80387944
    // 0x80387930: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80387944;
    // 0x80387930: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80387934: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
L_80387938:
    // 0x80387938: nop

    // 0x8038793C: bltz        $t0, L_8038792C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80387940: nop
    
            goto L_8038792C;
    }
    // 0x80387940: nop

L_80387944:
    // 0x80387944: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80387948: addiu       $t1, $t0, 0x30
    ctx->r9 = ADD32(ctx->r8, 0X30);
    // 0x8038794C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x80387950: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80387954: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x80387958: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8038795C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80387960: nop

    // 0x80387964: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80387968: nop

    // 0x8038796C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80387970: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80387974: mul.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80387978: bnel        $s0, $zero, L_803876A8
    if (ctx->r16 != 0) {
        // 0x8038797C: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_803876A8;
    }
    goto skip_7;
    // 0x8038797C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_7:
L_80387980:
    // 0x80387980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80387984:
    // 0x80387984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80387988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038798C: jr          $ra
    // 0x80387990: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80387990: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80387994: nop

    // 0x80387998: nop

    // 0x8038799C: nop

;}
RECOMP_FUNC void ftFoxSpecialHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BDC8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BDCC: jal         0x800DDDDC
    // 0x8015BDD0: addiu       $a1, $a1, -0x41B8
    ctx->r5 = ADD32(ctx->r5, -0X41B8);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015BDD0: addiu       $a1, $a1, -0x41B8
    ctx->r5 = ADD32(ctx->r5, -0X41B8);
    after_0:
    // 0x8015BDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BDDC: jr          $ra
    // 0x8015BDE0: nop

    return;
    // 0x8015BDE0: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueCursorSetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AE8: bne         $a1, $zero, L_80132B0C
    if (ctx->r5 != 0) {
        // 0x80132AEC: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80132B0C;
    }
    // 0x80132AEC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132AF0: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x80132AF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132AF8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132AFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132B00: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132B04: jr          $ra
    // 0x80132B08: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80132B08: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132B0C:
    // 0x80132B0C: lui         $at, 0x4331
    ctx->r1 = S32(0X4331 << 16);
    // 0x80132B10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132B14: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132B18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132B1C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132B20: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132B24: jr          $ra
    // 0x80132B28: nop

    return;
    // 0x80132B28: nop

;}
RECOMP_FUNC void mpProcessCheckTestRWallCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC3C8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800DC3CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DC3D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DC3D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DC3D8: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x800DC3DC: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800DC3E0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DC3E4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800DC3E8: lhu         $t7, 0x58($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X58);
    // 0x800DC3EC: lhu         $t9, 0x5A($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X5A);
    // 0x800DC3F0: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x800DC3F4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x800DC3F8: sh          $t8, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r24;
    // 0x800DC3FC: sh          $t1, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r9;
    // 0x800DC400: jal         0x800D9510
    // 0x800DC404: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    mpProcessResetMultiWallCount(rdram, ctx);
        goto after_0;
    // 0x800DC404: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DC408: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800DC40C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800DC410: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DC414: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x800DC418: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC41C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800DC420: addiu       $s1, $t0, 0x38
    ctx->r17 = ADD32(ctx->r8, 0X38);
    // 0x800DC424: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DC428: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC42C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC430: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DC434: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DC438: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC43C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC440: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC444: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC448: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC44C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DC450: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC454: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC458: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC45C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DC460: lhu         $t3, 0x5C($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X5C);
    // 0x800DC464: beq         $t2, $t3, L_800DC490
    if (ctx->r10 == ctx->r11) {
        // 0x800DC468: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DC490;
    }
    // 0x800DC468: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC46C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC474: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC478: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC47C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC480: jal         0x800F769C
    // 0x800DC484: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_1;
    // 0x800DC484: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800DC488: b           L_800DC4B0
    // 0x800DC48C: nop

        goto L_800DC4B0;
    // 0x800DC48C: nop

L_800DC490:
    // 0x800DC490: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC494: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC49C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC4A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC4A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC4A8: jal         0x800F6B58
    // 0x800DC4AC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_2;
    // 0x800DC4AC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
L_800DC4B0:
    // 0x800DC4B0: beql        $v0, $zero, L_800DC4CC
    if (ctx->r2 == 0) {
        // 0x800DC4B4: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_800DC4CC;
    }
    goto skip_0;
    // 0x800DC4B4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800DC4B8: jal         0x800D951C
    // 0x800DC4BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_3;
    // 0x800DC4BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800DC4C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DC4C4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800DC4C8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800DC4CC:
    // 0x800DC4CC: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800DC4D0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800DC4D4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC4D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DC4DC: lhu         $t6, 0x1398($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1398);
    // 0x800DC4E0: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DC4E4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DC4E8: lwc1        $f8, 0x8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800DC4EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DC4F0: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DC4F4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC4F8: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DC4FC: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DC500: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC504: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DC508: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DC50C: lhu         $t8, 0x5C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X5C);
    // 0x800DC510: beq         $t6, $t8, L_800DC538
    if (ctx->r14 == ctx->r24) {
        // 0x800DC514: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DC538;
    }
    // 0x800DC514: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC518: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC51C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC520: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC524: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC528: jal         0x800F769C
    // 0x800DC52C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_4;
    // 0x800DC52C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_4:
    // 0x800DC530: b           L_800DC554
    // 0x800DC534: nop

        goto L_800DC554;
    // 0x800DC534: nop

L_800DC538:
    // 0x800DC538: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC53C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC544: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC548: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC54C: jal         0x800F6B58
    // 0x800DC550: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_5;
    // 0x800DC550: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
L_800DC554:
    // 0x800DC554: beq         $v0, $zero, L_800DC568
    if (ctx->r2 == 0) {
        // 0x800DC558: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800DC568;
    }
    // 0x800DC558: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DC55C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800DC560: jal         0x800D951C
    // 0x800DC564: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_6;
    // 0x800DC564: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
L_800DC568:
    // 0x800DC568: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800DC56C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800DC570: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800DC574: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC578: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DC57C: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DC580: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC584: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DC588: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800DC58C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC590: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC594: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC598: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800DC59C: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DC5A0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC5A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DC5A8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800DC5AC: lhu         $t4, 0x5C($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X5C);
    // 0x800DC5B0: beq         $t2, $t4, L_800DC5D8
    if (ctx->r10 == ctx->r12) {
        // 0x800DC5B4: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_800DC5D8;
    }
    // 0x800DC5B4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC5B8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC5BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC5C0: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC5C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC5C8: jal         0x800F769C
    // 0x800DC5CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_7;
    // 0x800DC5CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x800DC5D0: b           L_800DC5F4
    // 0x800DC5D4: nop

        goto L_800DC5F4;
    // 0x800DC5D4: nop

L_800DC5D8:
    // 0x800DC5D8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC5DC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC5E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC5E4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC5E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC5EC: jal         0x800F6B58
    // 0x800DC5F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_8;
    // 0x800DC5F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_8:
L_800DC5F4:
    // 0x800DC5F4: beq         $v0, $zero, L_800DC608
    if (ctx->r2 == 0) {
        // 0x800DC5F8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DC608;
    }
    // 0x800DC5F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DC5FC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DC600: jal         0x800D951C
    // 0x800DC604: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_9;
    // 0x800DC604: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    after_9:
L_800DC608:
    // 0x800DC608: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC60C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC610: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC614: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x800DC618: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC61C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DC620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC624: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC628: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DC62C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800DC630: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC634: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC638: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DC63C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DC640: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC644: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC648: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC64C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC650: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DC654: jal         0x800F6B58
    // 0x800DC658: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_10;
    // 0x800DC658: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x800DC65C: beq         $v0, $zero, L_800DC670
    if (ctx->r2 == 0) {
        // 0x800DC660: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DC670;
    }
    // 0x800DC660: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DC664: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DC668: jal         0x800D951C
    // 0x800DC66C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_11;
    // 0x800DC66C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    after_11:
L_800DC670:
    // 0x800DC670: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC674: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC678: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC67C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC680: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC684: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DC688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC68C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC690: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC694: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC698: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC69C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC6A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC6A4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DC6A8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC6AC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC6B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC6B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC6B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC6BC: jal         0x800F6B58
    // 0x800DC6C0: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_12;
    // 0x800DC6C0: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x800DC6C4: beq         $v0, $zero, L_800DC6D8
    if (ctx->r2 == 0) {
        // 0x800DC6C8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800DC6D8;
    }
    // 0x800DC6C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DC6CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DC6D0: jal         0x800D951C
    // 0x800DC6D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_13;
    // 0x800DC6D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_13:
L_800DC6D8:
    // 0x800DC6D8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800DC6DC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800DC6E0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800DC6E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC6E8: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800DC6EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DC6F0: lhu         $t9, 0x1398($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1398);
    // 0x800DC6F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC6F8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC6FC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC700: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC704: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC708: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DC70C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800DC710: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC714: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC718: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC71C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC720: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC724: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC728: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DC72C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC730: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC734: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC738: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DC73C: lhu         $t3, 0x5C($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X5C);
    // 0x800DC740: beql        $t9, $t3, L_800DC770
    if (ctx->r25 == ctx->r11) {
        // 0x800DC744: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DC770;
    }
    goto skip_1;
    // 0x800DC744: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_1:
    // 0x800DC748: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC74C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC754: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC75C: jal         0x800F64D4
    // 0x800DC760: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_14;
    // 0x800DC760: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_14:
    // 0x800DC764: b           L_800DC778
    // 0x800DC768: nop

        goto L_800DC778;
    // 0x800DC768: nop

    // 0x800DC76C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DC770:
    // 0x800DC770: jal         0x800F5E90
    // 0x800DC774: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_15;
    // 0x800DC774: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_15:
L_800DC778:
    // 0x800DC778: beql        $v0, $zero, L_800DC8C0
    if (ctx->r2 == 0) {
        // 0x800DC77C: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DC8C0;
    }
    goto skip_2;
    // 0x800DC77C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x800DC780: jal         0x800FAAE4
    // 0x800DC784: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpCollisionGetEdgeUpperRLineID(rdram, ctx);
        goto after_16;
    // 0x800DC784: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_16:
    // 0x800DC788: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DC78C: beq         $v0, $at, L_800DC8BC
    if (ctx->r2 == ctx->r1) {
        // 0x800DC790: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DC8BC;
    }
    // 0x800DC790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DC794: jal         0x800FA8A4
    // 0x800DC798: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_17;
    // 0x800DC798: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_17:
    // 0x800DC79C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DC7A0: bne         $v0, $at, L_800DC8BC
    if (ctx->r2 != ctx->r1) {
        // 0x800DC7A4: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_800DC8BC;
    }
    // 0x800DC7A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800DC7A8: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800DC7AC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800DC7B0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800DC7B4: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DC7B8: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800DC7BC: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DC7C0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DC7C4: lhu         $t5, 0x1398($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1398);
    // 0x800DC7C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DC7CC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC7D0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC7D8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DC7DC: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC7E0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DC7E4: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DC7E8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DC7EC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC7F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DC7F4: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DC7F8: lhu         $t6, 0x5C($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X5C);
    // 0x800DC7FC: beql        $t5, $t6, L_800DC82C
    if (ctx->r13 == ctx->r14) {
        // 0x800DC800: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DC82C;
    }
    goto skip_3;
    // 0x800DC800: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_3:
    // 0x800DC804: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC808: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC80C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC810: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DC814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC818: jal         0x800F64D4
    // 0x800DC81C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_18;
    // 0x800DC81C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_18:
    // 0x800DC820: b           L_800DC834
    // 0x800DC824: nop

        goto L_800DC834;
    // 0x800DC824: nop

    // 0x800DC828: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DC82C:
    // 0x800DC82C: jal         0x800F5E90
    // 0x800DC830: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_19;
    // 0x800DC830: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_19:
L_800DC834:
    // 0x800DC834: beq         $v0, $zero, L_800DC848
    if (ctx->r2 == 0) {
        // 0x800DC838: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_800DC848;
    }
    // 0x800DC838: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800DC83C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800DC840: beql        $t8, $t1, L_800DC8C0
    if (ctx->r24 == ctx->r9) {
        // 0x800DC844: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DC8C0;
    }
    goto skip_4;
    // 0x800DC844: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    skip_4:
L_800DC848:
    // 0x800DC848: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC84C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC850: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC854: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC858: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC85C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DC860: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC864: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DC868: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC86C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC870: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC874: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC878: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC87C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DC880: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC884: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC888: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC88C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DC890: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC894: jal         0x800F5E90
    // 0x800DC898: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_20;
    // 0x800DC898: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x800DC89C: beq         $v0, $zero, L_800DC8AC
    if (ctx->r2 == 0) {
        // 0x800DC8A0: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800DC8AC;
    }
    // 0x800DC8A0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800DC8A4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800DC8A8: beq         $t9, $t3, L_800DC8BC
    if (ctx->r25 == ctx->r11) {
        // 0x800DC8AC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800DC8BC;
    }
L_800DC8AC:
    // 0x800DC8AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DC8B0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800DC8B4: jal         0x800D951C
    // 0x800DC8B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_21;
    // 0x800DC8B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_21:
L_800DC8BC:
    // 0x800DC8BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_800DC8C0:
    // 0x800DC8C0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DC8C4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800DC8C8: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DC8CC: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800DC8D0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DC8D4: lhu         $t5, 0x1398($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1398);
    // 0x800DC8D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC8DC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC8E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC8E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC8E8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DC8EC: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DC8F0: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800DC8F4: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC8F8: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800DC8FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC900: addiu       $t1, $sp, 0x34
    ctx->r9 = ADD32(ctx->r29, 0X34);
    // 0x800DC904: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DC908: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC90C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC910: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC914: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DC918: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DC91C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC920: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DC924: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DC928: lhu         $t8, 0x5C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X5C);
    // 0x800DC92C: beql        $t5, $t8, L_800DC95C
    if (ctx->r13 == ctx->r24) {
        // 0x800DC930: sw          $t9, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r25;
            goto L_800DC95C;
    }
    goto skip_5;
    // 0x800DC930: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    skip_5:
    // 0x800DC934: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC938: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC93C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC940: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800DC944: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800DC948: jal         0x800F521C
    // 0x800DC94C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_22;
    // 0x800DC94C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_22:
    // 0x800DC950: b           L_800DC964
    // 0x800DC954: nop

        goto L_800DC964;
    // 0x800DC954: nop

    // 0x800DC958: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
L_800DC95C:
    // 0x800DC95C: jal         0x800F4BD8
    // 0x800DC960: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_23;
    // 0x800DC960: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_23:
L_800DC964:
    // 0x800DC964: beq         $v0, $zero, L_800DCAB4
    if (ctx->r2 == 0) {
        // 0x800DC968: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800DCAB4;
    }
    // 0x800DC968: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800DC96C: andi        $t2, $t3, 0x4000
    ctx->r10 = ctx->r11 & 0X4000;
    // 0x800DC970: bnel        $t2, $zero, L_800DCAB8
    if (ctx->r10 != 0) {
        // 0x800DC974: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800DCAB8;
    }
    goto skip_6;
    // 0x800DC974: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x800DC978: jal         0x800FA964
    // 0x800DC97C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_24;
    // 0x800DC97C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_24:
    // 0x800DC980: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DC984: beq         $v0, $at, L_800DCAB4
    if (ctx->r2 == ctx->r1) {
        // 0x800DC988: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DCAB4;
    }
    // 0x800DC988: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DC98C: jal         0x800FA8A4
    // 0x800DC990: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_25;
    // 0x800DC990: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_25:
    // 0x800DC994: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DC998: bne         $v0, $at, L_800DCAB4
    if (ctx->r2 != ctx->r1) {
        // 0x800DC99C: lw          $t4, 0x28($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X28);
            goto L_800DCAB4;
    }
    // 0x800DC99C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800DC9A0: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800DC9A4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DC9A8: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800DC9AC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x800DC9B0: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DC9B4: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800DC9B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DC9BC: lhu         $t6, 0x1398($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1398);
    // 0x800DC9C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DC9C4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DC9C8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DC9CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC9D0: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800DC9D4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC9D8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DC9DC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800DC9E0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DC9E4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC9E8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DC9EC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DC9F0: lhu         $t8, 0x5C($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X5C);
    // 0x800DC9F4: beql        $t6, $t8, L_800DCA24
    if (ctx->r14 == ctx->r24) {
        // 0x800DC9F8: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DCA24;
    }
    goto skip_7;
    // 0x800DC9F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_7:
    // 0x800DC9FC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DCA00: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DCA04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DCA08: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DCA0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DCA10: jal         0x800F521C
    // 0x800DCA14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_26;
    // 0x800DCA14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_26:
    // 0x800DCA18: b           L_800DCA2C
    // 0x800DCA1C: nop

        goto L_800DCA2C;
    // 0x800DCA1C: nop

    // 0x800DCA20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DCA24:
    // 0x800DCA24: jal         0x800F4BD8
    // 0x800DCA28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_27;
    // 0x800DCA28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
L_800DCA2C:
    // 0x800DCA2C: beq         $v0, $zero, L_800DCA40
    if (ctx->r2 == 0) {
        // 0x800DCA30: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_800DCA40;
    }
    // 0x800DCA30: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800DCA34: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800DCA38: beql        $t1, $t9, L_800DCAB8
    if (ctx->r9 == ctx->r25) {
        // 0x800DCA3C: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_800DCAB8;
    }
    goto skip_8;
    // 0x800DCA3C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_8:
L_800DCA40:
    // 0x800DCA40: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DCA44: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800DCA48: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800DCA4C: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800DCA50: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DCA54: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800DCA58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DCA5C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DCA60: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DCA64: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800DCA68: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DCA6C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DCA70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DCA74: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DCA78: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DCA7C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DCA80: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DCA84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DCA88: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DCA8C: jal         0x800F4BD8
    // 0x800DCA90: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_28;
    // 0x800DCA90: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_28:
    // 0x800DCA94: beq         $v0, $zero, L_800DCAA4
    if (ctx->r2 == 0) {
        // 0x800DCA98: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_800DCAA4;
    }
    // 0x800DCA98: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800DCA9C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800DCAA0: beq         $t3, $t2, L_800DCAB4
    if (ctx->r11 == ctx->r10) {
        // 0x800DCAA4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800DCAB4;
    }
L_800DCAA4:
    // 0x800DCAA4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DCAA8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800DCAAC: jal         0x800D951C
    // 0x800DCAB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_29;
    // 0x800DCAB0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
L_800DCAB4:
    // 0x800DCAB4: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_800DCAB8:
    // 0x800DCAB8: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800DCABC: beql        $t7, $zero, L_800DCAD4
    if (ctx->r15 == 0) {
        // 0x800DCAC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DCAD4;
    }
    goto skip_9;
    // 0x800DCAC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x800DCAC4: lhu         $t6, 0x56($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X56);
    // 0x800DCAC8: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x800DCACC: sh          $t8, 0x56($t5)
    MEM_H(0X56, ctx->r13) = ctx->r24;
    // 0x800DCAD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DCAD4:
    // 0x800DCAD4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800DCAD8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DCADC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DCAE0: jr          $ra
    // 0x800DCAE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800DCAE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void syUtilsRandTimeUChar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800189D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800189D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800189DC: jal         0x80034D50
    // 0x800189E0: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800189E0: nop

    after_0:
    // 0x800189E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800189E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800189EC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800189F0: jr          $ra
    // 0x800189F4: nop

    return;
    // 0x800189F4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeDesk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D18: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131D1C: jal         0x80009968
    // 0x80131D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D24: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D28: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131D2C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131D30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D34: addiu       $t7, $t7, -0x7208
    ctx->r15 = ADD32(ctx->r15, -0X7208);
    // 0x80131D38: sw          $v0, 0x4D14($at)
    MEM_W(0X4D14, ctx->r1) = ctx->r2;
    // 0x80131D3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131D48: jal         0x8000F120
    // 0x80131D4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131D4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131D50: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131D54: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131D58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131D5C: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131D60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131D64: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131D68: jal         0x80009DF4
    // 0x80131D6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131D6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D78: jr          $ra
    // 0x80131D7C: nop

    return;
    // 0x80131D7C: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156BB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156BBC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80156BC0: addiu       $t6, $t6, 0x69D4
    ctx->r14 = ADD32(ctx->r14, 0X69D4);
    // 0x80156BC4: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80156BC8: jr          $ra
    // 0x80156BCC: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x80156BCC: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void efManagerImpactWaveProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFCA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFCAC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FFCB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FFCB4: jal         0x8000DF34
    // 0x800FFCB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FFCB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800FFCBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800FFCC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FFCC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFCC8: lwc1        $f6, 0x78($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X78);
    // 0x800FFCCC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FFCD0: nop

    // 0x800FFCD4: bc1fl       L_800FFCFC
    if (!c1cs) {
        // 0x800FFCD8: lwc1        $f8, 0x1C($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800FFCFC;
    }
    goto skip_0;
    // 0x800FFCD8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x800FFCDC: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x800FFCE0: jal         0x800FD4F8
    // 0x800FFCE4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FFCE4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x800FFCE8: jal         0x80009A84
    // 0x800FFCEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FFCEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FFCF0: b           L_800FFD4C
    // 0x800FFCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FFD4C;
    // 0x800FFCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFCF8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
L_800FFCFC:
    // 0x800FFCFC: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FFD00: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800FFD04: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800FFD08: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800FFD0C: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x800FFD10: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FFD14: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800FFD18: nop

    // 0x800FFD1C: bc1fl       L_800FFD30
    if (!c1cs) {
        // 0x800FFD20: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_800FFD30;
    }
    goto skip_1;
    // 0x800FFD20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_1:
    // 0x800FFD24: b           L_800FFD48
    // 0x800FFD28: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
        goto L_800FFD48;
    // 0x800FFD28: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x800FFD2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800FFD30:
    // 0x800FFD30: nop

    // 0x800FFD34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800FFD38: nop

    // 0x800FFD3C: bc1fl       L_800FFD4C
    if (!c1cs) {
        // 0x800FFD40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FFD4C;
    }
    goto skip_2;
    // 0x800FFD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FFD44: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
L_800FFD48:
    // 0x800FFD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FFD4C:
    // 0x800FFD4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FFD50: jr          $ra
    // 0x800FFD54: nop

    return;
    // 0x800FFD54: nop

;}
RECOMP_FUNC void func_ovl8_803746DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803746DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803746E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803746E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x803746E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803746EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803746F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803746F4: jal         0x803717A0
    // 0x803746F8: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803746F8: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x803746FC: beq         $v0, $zero, L_80374738
    if (ctx->r2 == 0) {
        // 0x80374700: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80374738;
    }
    // 0x80374700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374704: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80374708: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8037470C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80374710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80374714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374718: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8037471C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80374720: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80374724: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80374728: jal         0x80382870
    // 0x8037472C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_80382870(rdram, ctx);
        goto after_1;
    // 0x8037472C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x80374730: b           L_8037473C
    // 0x80374734: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_8037473C;
    // 0x80374734: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80374738:
    // 0x80374738: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037473C:
    // 0x8037473C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80374740: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80374744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80374748: jr          $ra
    // 0x8037474C: nop

    return;
    // 0x8037474C: nop

;}
RECOMP_FUNC void ftMainSearchGroundHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E5D20: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800E5D24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E5D28: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E5D2C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E5D30: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E5D34: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E5D38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E5D3C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E5D40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E5D44: lw          $s6, 0x84($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X84);
    // 0x800E5D48: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E5D4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E5D50: lw          $t6, 0x40($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X40);
    // 0x800E5D54: addiu       $s1, $s1, 0x1190
    ctx->r17 = ADD32(ctx->r17, 0X1190);
    // 0x800E5D58: bne         $t6, $zero, L_800E5D80
    if (ctx->r14 != 0) {
        // 0x800E5D5C: nop
    
            goto L_800E5D80;
    }
    // 0x800E5D5C: nop

    // 0x800E5D60: lw          $v0, 0x164($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X164);
    // 0x800E5D64: beq         $v0, $zero, L_800E5D70
    if (ctx->r2 == 0) {
        // 0x800E5D68: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800E5D70;
    }
    // 0x800E5D68: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800E5D6C: sw          $t7, 0x164($s6)
    MEM_W(0X164, ctx->r22) = ctx->r15;
L_800E5D70:
    // 0x800E5D70: lw          $v0, 0x170($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X170);
    // 0x800E5D74: beq         $v0, $zero, L_800E5D80
    if (ctx->r2 == 0) {
        // 0x800E5D78: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800E5D80;
    }
    // 0x800E5D78: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800E5D7C: sw          $t8, 0x170($s6)
    MEM_W(0X170, ctx->r22) = ctx->r24;
L_800E5D80:
    // 0x800E5D80: jal         0x800E8AAC
    // 0x800E5D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_0;
    // 0x800E5D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800E5D88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E5D8C: bne         $v0, $at, L_800E5E30
    if (ctx->r2 != ctx->r1) {
        // 0x800E5D90: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_800E5E30;
    }
    // 0x800E5D90: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800E5D94: addiu       $s3, $s3, 0x119C
    ctx->r19 = ADD32(ctx->r19, 0X119C);
    // 0x800E5D98: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800E5D9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800E5DA0: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x800E5DA4: blez        $t9, L_800E5E04
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800E5DA8: addiu       $s4, $sp, 0x48
        ctx->r20 = ADD32(ctx->r29, 0X48);
            goto L_800E5E04;
    }
    // 0x800E5DA8: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x800E5DAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_800E5DB0:
    // 0x800E5DB0: beql        $a0, $zero, L_800E5DF0
    if (ctx->r4 == 0) {
        // 0x800E5DB4: lw          $t1, 0x0($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X0);
            goto L_800E5DF0;
    }
    goto skip_0;
    // 0x800E5DB4: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x800E5DB8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E5DBC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E5DC0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800E5DC4: jalr        $t9
    // 0x800E5DC8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800E5DC8: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_1:
    // 0x800E5DCC: beq         $v0, $zero, L_800E5DEC
    if (ctx->r2 == 0) {
        // 0x800E5DD0: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800E5DEC;
    }
    // 0x800E5DD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E5DD4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800E5DD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800E5DDC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800E5DE0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800E5DE4: jal         0x800E3CAC
    // 0x800E5DE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    ftMainUpdateDamageStatGround(rdram, ctx);
        goto after_2;
    // 0x800E5DE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
L_800E5DEC:
    // 0x800E5DEC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
L_800E5DF0:
    // 0x800E5DF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800E5DF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800E5DF8: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800E5DFC: bnel        $at, $zero, L_800E5DB0
    if (ctx->r1 != 0) {
        // 0x800E5E00: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_800E5DB0;
    }
    goto skip_1;
    // 0x800E5E00: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
L_800E5E04:
    // 0x800E5E04: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800E5E08: jal         0x800E5C30
    // 0x800E5E0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    ftMainGetGroundHitObstacle(rdram, ctx);
        goto after_3;
    // 0x800E5E0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x800E5E10: beq         $v0, $zero, L_800E5E30
    if (ctx->r2 == 0) {
        // 0x800E5E14: lw          $a3, 0x48($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X48);
            goto L_800E5E30;
    }
    // 0x800E5E14: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800E5E18: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800E5E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E5E20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E5E24: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800E5E28: jal         0x800E3CAC
    // 0x800E5E2C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    ftMainUpdateDamageStatGround(rdram, ctx);
        goto after_4;
    // 0x800E5E2C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
L_800E5E30:
    // 0x800E5E30: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E5E34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E5E38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E5E3C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E5E40: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E5E44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E5E48: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E5E4C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E5E50: jr          $ra
    // 0x800E5E54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800E5E54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftCommonDamageCheckMakeScreenFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140C54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140C58: beq         $a1, $at, L_80140C7C
    if (ctx->r5 == ctx->r1) {
        // 0x80140C5C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80140C7C;
    }
    // 0x80140C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140C60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80140C64: beq         $a1, $at, L_80140CA8
    if (ctx->r5 == ctx->r1) {
        // 0x80140C68: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80140CA8;
    }
    // 0x80140C68: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80140C6C: beql        $a1, $at, L_80140CD8
    if (ctx->r5 == ctx->r1) {
        // 0x80140C70: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80140CD8;
    }
    goto skip_0;
    // 0x80140C70: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x80140C74: b           L_80140D00
    // 0x80140C78: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
        goto L_80140D00;
    // 0x80140C78: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80140C7C:
    // 0x80140C7C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80140C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80140C84: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x80140C88: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80140C8C: nop

    // 0x80140C90: bc1fl       L_80140D24
    if (!c1cs) {
        // 0x80140C94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140D24;
    }
    goto skip_1;
    // 0x80140C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80140C98: jal         0x80115BF0
    // 0x80140C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x80140C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80140CA0: b           L_80140D24
    // 0x80140CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140D24;
    // 0x80140CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140CA8:
    // 0x80140CA8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80140CAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80140CB0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x80140CB4: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80140CB8: nop

    // 0x80140CBC: bc1fl       L_80140D24
    if (!c1cs) {
        // 0x80140CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140D24;
    }
    goto skip_2;
    // 0x80140CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80140CC4: jal         0x80115BF0
    // 0x80140CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_1;
    // 0x80140CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80140CCC: b           L_80140D24
    // 0x80140CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140D24;
    // 0x80140CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140CD4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80140CD8:
    // 0x80140CD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80140CDC: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80140CE0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80140CE4: nop

    // 0x80140CE8: bc1fl       L_80140D24
    if (!c1cs) {
        // 0x80140CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140D24;
    }
    goto skip_3;
    // 0x80140CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80140CF0: jal         0x80115BF0
    // 0x80140CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_2;
    // 0x80140CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80140CF8: b           L_80140D24
    // 0x80140CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140D24;
    // 0x80140CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140D00:
    // 0x80140D00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80140D04: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x80140D08: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80140D0C: nop

    // 0x80140D10: bc1fl       L_80140D24
    if (!c1cs) {
        // 0x80140D14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140D24;
    }
    goto skip_4;
    // 0x80140D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80140D18: jal         0x80115BF0
    // 0x80140D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_3;
    // 0x80140D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80140D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140D24:
    // 0x80140D24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140D28: jr          $ra
    // 0x80140D2C: nop

    return;
    // 0x80140D2C: nop

;}
RECOMP_FUNC void sc1PIntroSetNamePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013294C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132954: jal         0x8013291C
    // 0x80132958: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    sc1PIntroGetTotalNameOffsetX(rdram, ctx);
        goto after_0;
    // 0x80132958: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013295C: lui         $at, 0x4344
    ctx->r1 = S32(0X4344 << 16);
    // 0x80132960: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132964: bgez        $v0, L_80132974
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80132968: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80132974;
    }
    // 0x80132968: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8013296C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80132970: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80132974:
    // 0x80132974: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80132978: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    // 0x8013297C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80132980: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132984: lw          $t8, 0x5C30($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C30);
    // 0x80132988: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013298C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80132990: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    // 0x80132994: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
    // 0x80132998: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x8013299C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801329A0: jal         0x80132634
    // 0x801329A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    sc1PIntroGetAlliesNum(rdram, ctx);
        goto after_1;
    // 0x801329A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x801329A8: lui         $at, 0x4344
    ctx->r1 = S32(0X4344 << 16);
    // 0x801329AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801329B0: beq         $v0, $zero, L_80132A78
    if (ctx->r2 == 0) {
        // 0x801329B4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80132A78;
    }
    // 0x801329B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801329B8: lh          $t9, 0x14($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X14);
    // 0x801329BC: lwc1        $f8, 0x58($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801329C0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x801329C4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801329C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801329CC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801329D0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801329D4: swc1        $f18, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f18.u32l;
    // 0x801329D8: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x801329DC: bne         $v0, $at, L_80132A14
    if (ctx->r2 != ctx->r1) {
        // 0x801329E0: swc1        $f2, 0x5C($t1)
        MEM_W(0X5C, ctx->r9) = ctx->f2.u32l;
            goto L_80132A14;
    }
    // 0x801329E0: swc1        $f2, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f2.u32l;
    // 0x801329E4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x801329E8: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x801329EC: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801329F0: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801329F4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801329F8: nop

    // 0x801329FC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80132A00: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80132A04: swc1        $f8, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f8.u32l;
    // 0x80132A08: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80132A0C: b           L_80132A78
    // 0x80132A10: swc1        $f2, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f2.u32l;
        goto L_80132A78;
    // 0x80132A10: swc1        $f2, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f2.u32l;
L_80132A14:
    // 0x80132A14: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80132A18: lui         $at, 0x433C
    ctx->r1 = S32(0X433C << 16);
    // 0x80132A1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132A20: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x80132A24: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132A28: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80132A2C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80132A30: lui         $at, 0x434C
    ctx->r1 = S32(0X434C << 16);
    // 0x80132A34: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132A38: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80132A3C: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x80132A40: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80132A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132A48: swc1        $f10, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f10.u32l;
    // 0x80132A4C: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x80132A50: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80132A54: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80132A58: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80132A5C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80132A60: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132A64: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80132A68: swc1        $f6, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f6.u32l;
    // 0x80132A6C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80132A70: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80132A74: swc1        $f4, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f4.u32l;
L_80132A78:
    // 0x80132A78: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132A7C: lw          $t3, 0x5C2C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5C2C);
    // 0x80132A80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80132A84: lw          $v1, 0x74($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X74);
    // 0x80132A88: jal         0x8013283C
    // 0x80132A8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    sc1PIntroGetPlayerNameOffsetX(rdram, ctx);
        goto after_2;
    // 0x80132A8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80132A90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A94: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80132A98: lui         $at, 0x4344
    ctx->r1 = S32(0X4344 << 16);
    // 0x80132A9C: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80132AA0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80132AA4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80132AA8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80132AAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132AB0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132AB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132AB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132ABC: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80132AC0: swc1        $f2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f2.u32l;
    // 0x80132AC4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132AC8: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80132ACC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80132AD0: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80132AD4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80132AD8: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x80132ADC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80132AE0: bne         $t8, $at, L_80132AF8
    if (ctx->r24 != ctx->r1) {
        // 0x80132AE4: lui         $at, 0x433E
        ctx->r1 = S32(0X433E << 16);
            goto L_80132AF8;
    }
    // 0x80132AE4: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80132AE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132AEC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80132AF0: b           L_80132B00
    // 0x80132AF4: swc1        $f10, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f10.u32l;
        goto L_80132B00;
    // 0x80132AF4: swc1        $f10, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f10.u32l;
L_80132AF8:
    // 0x80132AF8: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80132AFC: swc1        $f2, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = ctx->f2.u32l;
L_80132B00:
    // 0x80132B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132B08: jr          $ra
    // 0x80132B0C: nop

    return;
    // 0x80132B0C: nop

;}
RECOMP_FUNC void func_ovl16_800D64BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64BC: jr          $ra
    // 0x800D64C0: nop

    return;
    // 0x800D64C0: nop

;}
RECOMP_FUNC void mnSoundTestArrowsThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801334C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801334C4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801334C8: addiu       $s4, $s4, 0x4308
    ctx->r20 = ADD32(ctx->r20, 0X4308);
    // 0x801334CC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801334D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801334D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801334D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801334DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801334E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801334E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801334E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801334EC: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x801334F0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801334F4: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x801334F8: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
    // 0x801334FC: addiu       $s6, $s6, 0x4180
    ctx->r22 = ADD32(ctx->r22, 0X4180);
    // 0x80133500: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80133504: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80133508:
    // 0x80133508: beq         $s3, $v0, L_8013351C
    if (ctx->r19 == ctx->r2) {
        // 0x8013350C: nop
    
            goto L_8013351C;
    }
    // 0x8013350C: nop

    // 0x80133510: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80133514: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
    // 0x80133518: sw          $zero, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = 0;
L_8013351C:
    // 0x8013351C: bnel        $s0, $zero, L_80133538
    if (ctx->r16 != 0) {
        // 0x80133520: lw          $t8, 0x0($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X0);
            goto L_80133538;
    }
    goto skip_0;
    // 0x80133520: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    skip_0:
    // 0x80133524: lw          $t6, 0x7C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7C);
    // 0x80133528: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
    // 0x8013352C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80133530: sw          $t7, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r15;
    // 0x80133534: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
L_80133538:
    // 0x80133538: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x8013353C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80133540: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133548: mflo        $v1
    ctx->r3 = lo;
    // 0x8013354C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80133550: addu        $v0, $s6, $t9
    ctx->r2 = ADD32(ctx->r22, ctx->r25);
    // 0x80133554: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133558: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    // 0x8013355C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80133560: swc1        $f6, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f6.u32l;
    // 0x80133564: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80133568: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    // 0x8013356C: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80133570: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80133574: jal         0x8000B1E8
    // 0x80133578: swc1        $f10, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f10.u32l;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80133578: swc1        $f10, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f10.u32l;
    after_0:
    // 0x8013357C: b           L_80133508
    // 0x80133580: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
        goto L_80133508;
    // 0x80133580: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80133584: nop

    // 0x80133588: nop

    // 0x8013358C: nop

    // 0x80133590: nop

    // 0x80133594: nop

    // 0x80133598: nop

    // 0x8013359C: nop

    // 0x801335A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801335A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801335A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801335AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801335B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801335B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801335B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801335BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801335C0: jr          $ra
    // 0x801335C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801335C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnCharactersSetMotion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013286C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132870: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80132874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132878: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013287C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80132880: jal         0x80131B58
    // 0x80132884: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132884: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_0:
    // 0x80132888: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013288C: lw          $t6, 0x66FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X66FC);
    // 0x80132890: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132894: lw          $a3, 0x66D4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X66D4);
    // 0x80132898: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8013289C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801328A0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801328A4: jal         0x80132500
    // 0x801328A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mnCharactersGetMotion(rdram, ctx);
        goto after_1;
    // 0x801328A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x801328AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801328B0: lui         $at, 0xA
    ctx->r1 = S32(0XA << 16);
    // 0x801328B4: ori         $at, $at, 0x2C2A
    ctx->r1 = ctx->r1 | 0X2C2A;
    // 0x801328B8: bne         $t7, $at, L_80132958
    if (ctx->r15 != ctx->r1) {
        // 0x801328BC: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_80132958;
    }
    // 0x801328BC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801328C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328C4: addiu       $v1, $v1, 0x6704
    ctx->r3 = ADD32(ctx->r3, 0X6704);
    // 0x801328C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801328CC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801328D0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801328D4: bne         $t0, $t9, L_801328FC
    if (ctx->r8 != ctx->r25) {
        // 0x801328D8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_801328FC;
    }
    // 0x801328D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801328DC: jal         0x801327FC
    // 0x801328E0: nop

    mnCharactersRandMotionKind(rdram, ctx);
        goto after_2;
    // 0x801328E0: nop

    after_2:
    // 0x801328E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801328EC: sw          $v0, 0x66C4($at)
    MEM_W(0X66C4, ctx->r1) = ctx->r2;
    // 0x801328F0: addiu       $v1, $v1, 0x6704
    ctx->r3 = ADD32(ctx->r3, 0X6704);
    // 0x801328F4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801328F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801328FC:
    // 0x801328FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132904: sw          $zero, 0x66FC($at)
    MEM_W(0X66FC, ctx->r1) = 0;
    // 0x80132908: jal         0x80131B58
    // 0x8013290C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x8013290C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_3:
    // 0x80132910: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132914: lw          $t2, 0x66FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X66FC);
    // 0x80132918: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8013291C: lw          $a3, 0x66D4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X66D4);
    // 0x80132920: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80132924: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80132928: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8013292C: jal         0x80132500
    // 0x80132930: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    mnCharactersGetMotion(rdram, ctx);
        goto after_4;
    // 0x80132930: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_4:
    // 0x80132934: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x80132938: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8013293C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80132940: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80132944: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80132948: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8013294C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80132950: b           L_80132974
    // 0x80132954: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
        goto L_80132974;
    // 0x80132954: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
L_80132958:
    // 0x80132958: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8013295C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132960: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132964: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132968: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013296C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132970: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_80132974:
    // 0x80132974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013297C: jr          $ra
    // 0x80132980: nop

    return;
    // 0x80132980: nop

;}
RECOMP_FUNC void func_ovl8_80385428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038542C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385430: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80385434: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80385438: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8038543C: jalr        $t9
    // 0x80385440: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80385440: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80385444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038544C: jr          $ra
    // 0x80385450: nop

    return;
    // 0x80385450: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueSpotlightFadeProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324C0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801324C4: addiu       $t3, $t3, 0x4324
    ctx->r11 = ADD32(ctx->r11, 0X4324);
    // 0x801324C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801324CC: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x801324D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801324D4: blez        $v0, L_801324EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801324D8: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_801324EC;
    }
    // 0x801324D8: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x801324DC: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x801324E0: bgez        $t6, L_801324EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801324E4: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_801324EC;
    }
    // 0x801324E4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801324E8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_801324EC:
    // 0x801324EC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801324F0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801324F4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x801324F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801324FC: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132500: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132504: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132508: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x8013250C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132510: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80132514: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132518: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8013251C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132520: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132524: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132528: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8013252C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80132530: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132534: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80132538: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x8013253C: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80132540: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80132544: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80132548: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x8013254C: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80132550: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80132554: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80132558: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8013255C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80132560: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132564: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132568: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8013256C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132570: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132574: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132578: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8013257C: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80132580: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80132584: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132588: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x8013258C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132590: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80132594: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132598: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8013259C: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x801325A0: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x801325A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801325A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801325AC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801325B0: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801325B4: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x801325B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801325BC: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801325C0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801325C4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801325C8: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801325CC: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x801325D0: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x801325D4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801325D8: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x801325DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801325E0: jr          $ra
    // 0x801325E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x801325E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void func_ovl27_801357FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801357FC: jr          $ra
    // 0x80135800: nop

    return;
    // 0x80135800: nop

;}
RECOMP_FUNC void syVectorSub3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018FF4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018FF8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018FFC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019000: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80019004: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019008: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001900C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80019010: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019014: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80019018: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8001901C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019020: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019024: jr          $ra
    // 0x80019028: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80019028: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}

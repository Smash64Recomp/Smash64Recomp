#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C60: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80033C64: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80033C68: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80033C6C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80033C70: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80033C74: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80033C78: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80033C7C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80033C80: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80033C84: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80033C88: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80033C8C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80033C90: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80033C94: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80033C98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80033C9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80033CA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80033CA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80033CA8: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80033CAC: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x80033CB0: addiu       $s7, $s7, -0x2BB0
    ctx->r23 = ADD32(ctx->r23, -0X2BB0);
    // 0x80033CB4: addiu       $s6, $s6, -0xDDC
    ctx->r22 = ADD32(ctx->r22, -0XDDC);
    // 0x80033CB8: addiu       $s5, $s5, -0x2B8C
    ctx->r21 = ADD32(ctx->r21, -0X2B8C);
    // 0x80033CBC: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_80033CC0:
    // 0x80033CC0: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80033CC4: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80033CC8: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x80033CCC: beq         $v0, $zero, L_80033CF4
    if (ctx->r2 == 0) {
        // 0x80033CD0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80033CF4;
    }
    // 0x80033CD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80033CD4: beql        $v1, $v0, L_80033CF8
    if (ctx->r3 == ctx->r2) {
        // 0x80033CD8: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_80033CF8;
    }
    goto skip_0;
    // 0x80033CD8: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x80033CDC: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_80033CE0:
    // 0x80033CE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033CE4: beq         $v0, $zero, L_80033CF4
    if (ctx->r2 == 0) {
        // 0x80033CE8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80033CF4;
    }
    // 0x80033CE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80033CEC: bnel        $v1, $v0, L_80033CE0
    if (ctx->r3 != ctx->r2) {
        // 0x80033CF0: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_80033CE0;
    }
    goto skip_1;
    // 0x80033CF0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_80033CF4:
    // 0x80033CF4: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_80033CF8:
    // 0x80033CF8: blez        $v0, L_80033D30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80033CFC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80033D30;
    }
    // 0x80033CFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80033D00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80033D04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80033D08: jalr        $s4
    // 0x80033D0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80033D0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x80033D10: beq         $v0, $zero, L_80033D28
    if (ctx->r2 == 0) {
        // 0x80033D14: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80033D28;
    }
    // 0x80033D14: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80033D18: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80033D1C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80033D20: b           L_80033D30
    // 0x80033D24: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80033D30;
    // 0x80033D24: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80033D28:
    // 0x80033D28: b           L_80034278
    // 0x80033D2C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80033D2C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80033D30:
    // 0x80033D30: bne         $s0, $zero, L_80033D40
    if (ctx->r16 != 0) {
        // 0x80033D34: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80033D40;
    }
    // 0x80033D34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033D38: b           L_80034278
    // 0x80033D3C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80033D3C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80033D40:
    // 0x80033D40: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x80033D44: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80033D48: jal         0x80034434
    // 0x80033D4C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x80033D4C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80033D50: beq         $v0, $zero, L_80033D90
    if (ctx->r2 == 0) {
        // 0x80033D54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80033D90;
    }
    // 0x80033D54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80033D58:
    // 0x80033D58: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x80033D5C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80033D60: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80033D64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80033D68: lw          $t7, -0xDD4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XDD4);
    // 0x80033D6C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80033D70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033D74: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80033D78: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80033D7C: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x80033D80: jal         0x80034434
    // 0x80033D84: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x80033D84: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x80033D88: bne         $v0, $zero, L_80033D58
    if (ctx->r2 != 0) {
        // 0x80033D8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80033D58;
    }
    // 0x80033D8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80033D90:
    // 0x80033D90: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80033D94: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80033D98: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80033D9C: bne         $v0, $t6, L_80033DE4
    if (ctx->r2 != ctx->r14) {
        // 0x80033DA0: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80033DE4;
    }
    // 0x80033DA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80033DA4: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x80033DA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033DAC: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80033DB0: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x80033DB4: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80033DB8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80033DBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033DC0: bgez        $t8, L_80033DDC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80033DC4: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_80033DDC;
    }
    // 0x80033DC4: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80033DC8: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x80033DCC: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x80033DD0: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80033DD4: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80033DD8: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_80033DDC:
    // 0x80033DDC: b           L_80033E40
    // 0x80033DE0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80033E40;
    // 0x80033DE0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80033DE4:
    // 0x80033DE4: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80033DE8: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80033DEC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80033DF0: bne         $at, $zero, L_80033E40
    if (ctx->r1 != 0) {
        // 0x80033DF4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80033E40;
    }
    // 0x80033DF4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80033DF8: beql        $at, $zero, L_80033E44
    if (ctx->r1 == 0) {
        // 0x80033DFC: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80033E44;
    }
    goto skip_2;
    // 0x80033DFC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80033E00: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_80033E04:
    // 0x80033E04: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x80033E08: beql        $at, $zero, L_80033E28
    if (ctx->r1 == 0) {
        // 0x80033E0C: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80033E28;
    }
    goto skip_3;
    // 0x80033E0C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x80033E10: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033E14: mflo        $t7
    ctx->r15 = lo;
    // 0x80033E18: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x80033E1C: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x80033E20: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80033E24: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80033E28:
    // 0x80033E28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033E2C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80033E30: bne         $at, $zero, L_80033E40
    if (ctx->r1 != 0) {
        // 0x80033E34: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80033E40;
    }
    // 0x80033E34: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80033E38: bnel        $at, $zero, L_80033E04
    if (ctx->r1 != 0) {
        // 0x80033E3C: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_80033E04;
    }
    goto skip_4;
    // 0x80033E3C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_80033E40:
    // 0x80033E40: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_80033E44:
    // 0x80033E44: beq         $a1, $at, L_80033E58
    if (ctx->r5 == ctx->r1) {
        // 0x80033E48: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80033E58;
    }
    // 0x80033E48: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80033E4C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x80033E50: b           L_80033EEC
    // 0x80033E54: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80033EEC;
    // 0x80033E54: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80033E58:
    // 0x80033E58: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x80033E5C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80033E60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033E64: bne         $v0, $t7, L_80033E90
    if (ctx->r2 != ctx->r15) {
        // 0x80033E68: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_80033E90;
    }
    // 0x80033E68: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x80033E6C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033E70: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80033E74: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x80033E78: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80033E7C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80033E80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033E84: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x80033E88: b           L_80033EEC
    // 0x80033E8C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80033EEC;
    // 0x80033E8C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80033E90:
    // 0x80033E90: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80033E94: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80033E98: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80033E9C: bne         $at, $zero, L_80033EEC
    if (ctx->r1 != 0) {
        // 0x80033EA0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80033EEC;
    }
    // 0x80033EA0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80033EA4: beq         $at, $zero, L_80033EEC
    if (ctx->r1 == 0) {
        // 0x80033EA8: nop
    
            goto L_80033EEC;
    }
    // 0x80033EA8: nop

    // 0x80033EAC: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_80033EB0:
    // 0x80033EB0: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x80033EB4: beql        $at, $zero, L_80033ED4
    if (ctx->r1 == 0) {
        // 0x80033EB8: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80033ED4;
    }
    goto skip_5;
    // 0x80033EB8: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x80033EBC: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033EC0: mflo        $t7
    ctx->r15 = lo;
    // 0x80033EC4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80033EC8: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x80033ECC: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x80033ED0: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80033ED4:
    // 0x80033ED4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033ED8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80033EDC: bne         $at, $zero, L_80033EEC
    if (ctx->r1 != 0) {
        // 0x80033EE0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80033EEC;
    }
    // 0x80033EE0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80033EE4: bnel        $at, $zero, L_80033EB0
    if (ctx->r1 != 0) {
        // 0x80033EE8: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_80033EB0;
    }
    goto skip_6;
    // 0x80033EE8: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_80033EEC:
    // 0x80033EEC: jal         0x80034434
    // 0x80033EF0: addiu       $a0, $a0, -0xDE0
    ctx->r4 = ADD32(ctx->r4, -0XDE0);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x80033EF0: addiu       $a0, $a0, -0xDE0
    ctx->r4 = ADD32(ctx->r4, -0XDE0);
    after_3:
    // 0x80033EF4: beq         $v0, $zero, L_80033F0C
    if (ctx->r2 == 0) {
        // 0x80033EF8: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_80033F0C;
    }
    // 0x80033EF8: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x80033EFC: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80033F00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80033F04: b           L_80033F10
    // 0x80033F08: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_80033F10;
    // 0x80033F08: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_80033F0C:
    // 0x80033F0C: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_80033F10:
    // 0x80033F10: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x80033F14: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80033F18: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x80033F1C: bne         $v0, $t7, L_80033F3C
    if (ctx->r2 != ctx->r15) {
        // 0x80033F20: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_80033F3C;
    }
    // 0x80033F20: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x80033F24: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80033F28: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x80033F2C: bne         $v0, $t8, L_80033F3C
    if (ctx->r2 != ctx->r24) {
        // 0x80033F30: nop
    
            goto L_80033F3C;
    }
    // 0x80033F30: nop

    // 0x80033F34: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x80033F38: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80033F3C:
    // 0x80033F3C: jal         0x800335F0
    // 0x80033F40: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_5_800335F0(rdram, ctx);
        goto after_4;
    // 0x80033F40: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x80033F44: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80033F48: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80033F4C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80033F50: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x80033F54: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80033F58: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x80033F5C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80033F60: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x80033F64: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80033F68: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x80033F6C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x80033F70: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x80033F74: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80033F78: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x80033F7C: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80033F80: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80033F84: bne         $t8, $zero, L_80033FF0
    if (ctx->r24 != 0) {
        // 0x80033F88: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_80033FF0;
    }
    // 0x80033F88: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033F8C: beql        $t6, $zero, L_80033FF4
    if (ctx->r14 == 0) {
        // 0x80033F90: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80033FF4;
    }
    goto skip_7;
    // 0x80033F90: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x80033F94: beq         $t6, $zero, L_80033FF0
    if (ctx->r14 == 0) {
        // 0x80033F98: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80033FF0;
    }
    // 0x80033F98: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80033F9C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80033FA0:
    // 0x80033FA0: bne         $at, $zero, L_80033FB0
    if (ctx->r1 != 0) {
        // 0x80033FA4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80033FB0;
    }
    // 0x80033FA4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80033FA8: b           L_80033FB0
    // 0x80033FAC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80033FB0;
    // 0x80033FAC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80033FB0:
    // 0x80033FB0: blez        $s0, L_80033FE4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80033FB4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80033FE4;
    }
    // 0x80033FB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80033FB8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80033FBC: jalr        $s4
    // 0x80033FC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80033FC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80033FC4: beq         $v0, $zero, L_80033FDC
    if (ctx->r2 == 0) {
        // 0x80033FC8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80033FDC;
    }
    // 0x80033FC8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80033FCC: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80033FD0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80033FD4: b           L_80033FE4
    // 0x80033FD8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80033FE4;
    // 0x80033FD8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80033FDC:
    // 0x80033FDC: b           L_80034278
    // 0x80033FE0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80033FE0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80033FE4:
    // 0x80033FE4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80033FE8: bgtzl       $s1, L_80033FA0
    if (SIGNED(ctx->r17) > 0) {
        // 0x80033FEC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80033FA0;
    }
    goto skip_8;
    // 0x80033FEC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_80033FF0:
    // 0x80033FF0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80033FF4:
    // 0x80033FF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80033FF8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80033FFC: blezl       $t9, L_80034034
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80034000: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_80034034;
    }
    goto skip_9;
    // 0x80034000: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x80034004: jalr        $s4
    // 0x80034008: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x80034008: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x8003400C: beq         $v0, $zero, L_80034028
    if (ctx->r2 == 0) {
        // 0x80034010: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80034028;
    }
    // 0x80034010: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80034014: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80034018: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8003401C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80034020: b           L_80034030
    // 0x80034024: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80034030;
    // 0x80034024: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80034028:
    // 0x80034028: b           L_80034278
    // 0x8003402C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x8003402C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80034030:
    // 0x80034030: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_80034034:
    // 0x80034034: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80034038: beql        $t6, $zero, L_800340A0
    if (ctx->r14 == 0) {
        // 0x8003403C: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800340A0;
    }
    goto skip_10;
    // 0x8003403C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x80034040: beq         $t6, $zero, L_8003409C
    if (ctx->r14 == 0) {
        // 0x80034044: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003409C;
    }
    // 0x80034044: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80034048: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8003404C:
    // 0x8003404C: bne         $at, $zero, L_8003405C
    if (ctx->r1 != 0) {
        // 0x80034050: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003405C;
    }
    // 0x80034050: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80034054: b           L_8003405C
    // 0x80034058: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8003405C;
    // 0x80034058: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8003405C:
    // 0x8003405C: blez        $s0, L_80034090
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80034060: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80034090;
    }
    // 0x80034060: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80034064: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80034068: jalr        $s4
    // 0x8003406C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x8003406C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80034070: beq         $v0, $zero, L_80034088
    if (ctx->r2 == 0) {
        // 0x80034074: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80034088;
    }
    // 0x80034074: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80034078: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8003407C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80034080: b           L_80034090
    // 0x80034084: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80034090;
    // 0x80034084: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80034088:
    // 0x80034088: b           L_80034278
    // 0x8003408C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x8003408C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80034090:
    // 0x80034090: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80034094: bgtzl       $s1, L_8003404C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80034098: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8003404C;
    }
    goto skip_11;
    // 0x80034098: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_8003409C:
    // 0x8003409C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800340A0:
    // 0x800340A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800340A4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800340A8: blezl       $t9, L_800340E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800340AC: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_800340E0;
    }
    goto skip_12;
    // 0x800340AC: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x800340B0: jalr        $s4
    // 0x800340B4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x800340B4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x800340B8: beq         $v0, $zero, L_800340D4
    if (ctx->r2 == 0) {
        // 0x800340BC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800340D4;
    }
    // 0x800340BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800340C0: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800340C4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800340C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800340CC: b           L_800340DC
    // 0x800340D0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800340DC;
    // 0x800340D0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800340D4:
    // 0x800340D4: b           L_80034278
    // 0x800340D8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x800340D8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800340DC:
    // 0x800340DC: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_800340E0:
    // 0x800340E0: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800340E4: beql        $t6, $zero, L_8003414C
    if (ctx->r14 == 0) {
        // 0x800340E8: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_8003414C;
    }
    goto skip_13;
    // 0x800340E8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x800340EC: beq         $t6, $zero, L_80034148
    if (ctx->r14 == 0) {
        // 0x800340F0: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80034148;
    }
    // 0x800340F0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800340F4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800340F8:
    // 0x800340F8: bne         $at, $zero, L_80034108
    if (ctx->r1 != 0) {
        // 0x800340FC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80034108;
    }
    // 0x800340FC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80034100: b           L_80034108
    // 0x80034104: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80034108;
    // 0x80034104: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80034108:
    // 0x80034108: blez        $s0, L_8003413C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003410C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003413C;
    }
    // 0x8003410C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80034110: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80034114: jalr        $s4
    // 0x80034118: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x80034118: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x8003411C: beq         $v0, $zero, L_80034134
    if (ctx->r2 == 0) {
        // 0x80034120: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80034134;
    }
    // 0x80034120: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80034124: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80034128: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003412C: b           L_8003413C
    // 0x80034130: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003413C;
    // 0x80034130: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80034134:
    // 0x80034134: b           L_80034278
    // 0x80034138: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80034138: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003413C:
    // 0x8003413C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80034140: bgtzl       $s1, L_800340F8
    if (SIGNED(ctx->r17) > 0) {
        // 0x80034144: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800340F8;
    }
    goto skip_14;
    // 0x80034144: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_80034148:
    // 0x80034148: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_8003414C:
    // 0x8003414C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80034150: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80034154: blez        $t9, L_8003418C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80034158: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8003418C;
    }
    // 0x80034158: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8003415C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80034160: jalr        $s4
    // 0x80034164: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x80034164: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x80034168: beq         $v0, $zero, L_80034184
    if (ctx->r2 == 0) {
        // 0x8003416C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80034184;
    }
    // 0x8003416C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80034170: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x80034174: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80034178: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8003417C: b           L_8003418C
    // 0x80034180: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8003418C;
    // 0x80034180: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80034184:
    // 0x80034184: b           L_80034278
    // 0x80034188: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80034188: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003418C:
    // 0x8003418C: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80034190: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80034194: beql        $t8, $zero, L_800341FC
    if (ctx->r24 == 0) {
        // 0x80034198: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800341FC;
    }
    goto skip_15;
    // 0x80034198: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x8003419C: beq         $t8, $zero, L_800341F8
    if (ctx->r24 == 0) {
        // 0x800341A0: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800341F8;
    }
    // 0x800341A0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800341A4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800341A8:
    // 0x800341A8: bne         $at, $zero, L_800341B8
    if (ctx->r1 != 0) {
        // 0x800341AC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800341B8;
    }
    // 0x800341AC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800341B0: b           L_800341B8
    // 0x800341B4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800341B8;
    // 0x800341B4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800341B8:
    // 0x800341B8: blez        $s0, L_800341EC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800341BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800341EC;
    }
    // 0x800341BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800341C0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800341C4: jalr        $s4
    // 0x800341C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x800341C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x800341CC: beq         $v0, $zero, L_800341E4
    if (ctx->r2 == 0) {
        // 0x800341D0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800341E4;
    }
    // 0x800341D0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800341D4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800341D8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800341DC: b           L_800341EC
    // 0x800341E0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800341EC;
    // 0x800341E0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_800341E4:
    // 0x800341E4: b           L_80034278
    // 0x800341E8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x800341E8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800341EC:
    // 0x800341EC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800341F0: bgtzl       $s1, L_800341A8
    if (SIGNED(ctx->r17) > 0) {
        // 0x800341F4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800341A8;
    }
    goto skip_16;
    // 0x800341F4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800341F8:
    // 0x800341F8: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_800341FC:
    // 0x800341FC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80034200: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x80034204: beq         $t8, $zero, L_80034270
    if (ctx->r24 == 0) {
        // 0x80034208: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_80034270;
    }
    // 0x80034208: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003420C: beq         $t7, $zero, L_80034270
    if (ctx->r15 == 0) {
        // 0x80034210: nop
    
            goto L_80034270;
    }
    // 0x80034210: nop

    // 0x80034214: beq         $t7, $zero, L_80034270
    if (ctx->r15 == 0) {
        // 0x80034218: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_80034270;
    }
    // 0x80034218: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8003421C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80034220:
    // 0x80034220: bne         $at, $zero, L_80034230
    if (ctx->r1 != 0) {
        // 0x80034224: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80034230;
    }
    // 0x80034224: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80034228: b           L_80034230
    // 0x8003422C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80034230;
    // 0x8003422C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80034230:
    // 0x80034230: blez        $s0, L_80034264
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80034234: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80034264;
    }
    // 0x80034234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80034238: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003423C: jalr        $s4
    // 0x80034240: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x80034240: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80034244: beq         $v0, $zero, L_8003425C
    if (ctx->r2 == 0) {
        // 0x80034248: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003425C;
    }
    // 0x80034248: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003424C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80034250: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x80034254: b           L_80034264
    // 0x80034258: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80034264;
    // 0x80034258: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003425C:
    // 0x8003425C: b           L_80034278
    // 0x80034260: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80034278;
    // 0x80034260: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80034264:
    // 0x80034264: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80034268: bgtzl       $s1, L_80034220
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003426C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80034220;
    }
    goto skip_17;
    // 0x8003426C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_80034270:
    // 0x80034270: b           L_80033CC0
    // 0x80034274: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_80033CC0;
    // 0x80034274: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_80034278:
    // 0x80034278: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003427C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80034280: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80034284: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80034288: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003428C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80034290: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80034294: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80034298: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003429C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800342A0: jr          $ra
    // 0x800342A4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800342A4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void mvOpeningYoshiInitName(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void grHyruleTwisterCheckGetDamageKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AB74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AB78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AB7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010AB80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010AB84: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x8010AB88: lw          $t6, 0x168($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X168);
    // 0x8010AB8C: bnel        $t6, $zero, L_8010AC60
    if (ctx->r14 != 0) {
        // 0x8010AB90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010AC60;
    }
    goto skip_0;
    // 0x8010AB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8010AB94: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x8010AB98: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8010AB9C: beql        $t7, $at, L_8010AC60
    if (ctx->r15 == ctx->r1) {
        // 0x8010ABA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010AC60;
    }
    goto skip_1;
    // 0x8010ABA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8010ABA4: lbu         $t8, 0x193($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X193);
    // 0x8010ABA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010ABAC: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8010ABB0: bnel        $t9, $zero, L_8010AC60
    if (ctx->r25 != 0) {
        // 0x8010ABB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010AC60;
    }
    goto skip_2;
    // 0x8010ABB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8010ABB8: jal         0x800E8AAC
    // 0x8010ABBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_0;
    // 0x8010ABBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010ABC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010ABC4: bne         $v0, $at, L_8010AC5C
    if (ctx->r2 != ctx->r1) {
        // 0x8010ABC8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8010AC5C;
    }
    // 0x8010ABC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010ABCC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8010ABD0: lw          $v1, 0x74($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X74);
    // 0x8010ABD4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010ABD8: lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X74);
    // 0x8010ABDC: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8010ABE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010ABE4: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8010ABE8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8010ABEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010ABF0: nop

    // 0x8010ABF4: bc1fl       L_8010AC0C
    if (!c1cs) {
        // 0x8010ABF8: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8010AC0C;
    }
    goto skip_3;
    // 0x8010ABF8: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x8010ABFC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8010AC00: b           L_8010AC0C
    // 0x8010AC04: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8010AC0C;
    // 0x8010AC04: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8010AC08: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_8010AC0C:
    // 0x8010AC0C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8010AC10: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8010AC14: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8010AC18: bc1f        L_8010AC5C
    if (!c1cs) {
        // 0x8010AC1C: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_8010AC5C;
    }
    // 0x8010AC1C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010AC20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010AC24: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8010AC28: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8010AC2C: nop

    // 0x8010AC30: bc1fl       L_8010AC60
    if (!c1cs) {
        // 0x8010AC34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010AC60;
    }
    goto skip_4;
    // 0x8010AC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8010AC38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010AC3C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8010AC40: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8010AC44: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8010AC48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010AC4C: bc1fl       L_8010AC60
    if (!c1cs) {
        // 0x8010AC50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010AC60;
    }
    goto skip_5;
    // 0x8010AC50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x8010AC54: b           L_8010AC60
    // 0x8010AC58: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_8010AC60;
    // 0x8010AC58: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8010AC5C:
    // 0x8010AC5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010AC60:
    // 0x8010AC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AC68: jr          $ra
    // 0x8010AC6C: nop

    return;
    // 0x8010AC6C: nop

;}
RECOMP_FUNC void unref_80015F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F6C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80015F70: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80015F74: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80015F78: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80015F7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80015F80: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80015F84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015F88: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x80015F8C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015F90: lbu         $t6, 0x54($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X54);
    // 0x80015F94: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80015F98: bnel        $t7, $zero, L_800162AC
    if (ctx->r15 != 0) {
        // 0x80015F9C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800162AC;
    }
    goto skip_0;
    // 0x80015F9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80015FA0: lw          $s0, 0x50($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X50);
    // 0x80015FA4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015FA8: addiu       $s1, $s1, 0x72A8
    ctx->r17 = ADD32(ctx->r17, 0X72A8);
    // 0x80015FAC: beq         $s0, $zero, L_800162A8
    if (ctx->r16 == 0) {
        // 0x80015FB0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800162A8;
    }
    // 0x80015FB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015FB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015FB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015FBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015FC0: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80015FC4: jal         0x80014798
    // 0x80015FC8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80015FC8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_0:
    // 0x80015FCC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80015FD0: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80015FD4: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x80015FD8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015FDC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80015FE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015FE4: bc1fl       L_80016014
    if (!c1cs) {
        // 0x80015FE8: lw          $a2, 0x4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X4);
            goto L_80016014;
    }
    goto skip_1;
    // 0x80015FE8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80015FEC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_80015FF0:
    // 0x80015FF0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80015FF4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80015FF8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80015FFC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80016000: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80016004: nop

    // 0x80016008: bc1tl       L_80015FF0
    if (c1cs) {
        // 0x8001600C: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_80015FF0;
    }
    goto skip_2;
    // 0x8001600C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80016010: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
L_80016014:
    // 0x80016014: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80016018: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001601C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80016020: jal         0x80010D70
    // 0x80016024: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_1;
    // 0x80016024: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    after_1:
    // 0x80016028: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8001602C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80016030: beql        $a2, $zero, L_80016190
    if (ctx->r6 == 0) {
        // 0x80016034: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80016190;
    }
    goto skip_3;
    // 0x80016034: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_3:
    // 0x80016038: lbu         $t6, 0x54($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X54);
    // 0x8001603C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016040: bnel        $t7, $zero, L_80016190
    if (ctx->r15 != 0) {
        // 0x80016044: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80016190;
    }
    goto skip_4;
    // 0x80016044: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_4:
    // 0x80016048: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001604C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80016050: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80016054: beq         $v0, $at, L_8001618C
    if (ctx->r2 == ctx->r1) {
        // 0x80016058: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_8001618C;
    }
    // 0x80016058: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x8001605C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80016060: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80016064: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
L_80016068:
    // 0x80016068: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x8001606C: addu        $t9, $a3, $s0
    ctx->r25 = ADD32(ctx->r7, ctx->r16);
    // 0x80016070: beql        $t8, $zero, L_8001617C
    if (ctx->r24 == 0) {
        // 0x80016074: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_8001617C;
    }
    goto skip_5;
    // 0x80016074: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_5:
    // 0x80016078: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001607C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80016080: beq         $t5, $a0, L_800160E8
    if (ctx->r13 == ctx->r4) {
        // 0x80016084: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_800160E8;
    }
    // 0x80016084: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
L_80016088:
    // 0x80016088: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001608C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80016090: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80016094: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80016098: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8001609C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800160A0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800160A4: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x800160A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800160AC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800160B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800160B4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800160B8: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800160BC: addu        $v0, $a3, $t5
    ctx->r2 = ADD32(ctx->r7, ctx->r13);
    // 0x800160C0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800160C4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800160C8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800160CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800160D0: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800160D4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800160D8: addu        $t8, $a3, $s0
    ctx->r24 = ADD32(ctx->r7, ctx->r16);
    // 0x800160DC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800160E0: bnel        $t9, $a0, L_80016088
    if (ctx->r25 != ctx->r4) {
        // 0x800160E4: addu        $t6, $s1, $s0
        ctx->r14 = ADD32(ctx->r17, ctx->r16);
            goto L_80016088;
    }
    goto skip_6;
    // 0x800160E4: addu        $t6, $s1, $s0
    ctx->r14 = ADD32(ctx->r17, ctx->r16);
    skip_6:
L_800160E8:
    // 0x800160E8: lw          $t5, 0x80($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X80);
    // 0x800160EC: beql        $t5, $zero, L_8001615C
    if (ctx->r13 == 0) {
        // 0x800160F0: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_8001615C;
    }
    goto skip_7;
    // 0x800160F0: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_7:
    // 0x800160F4: bne         $s4, $zero, L_80016134
    if (ctx->r20 != 0) {
        // 0x800160F8: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_80016134;
    }
    // 0x800160F8: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x800160FC: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80016100: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80016104: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80016108: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x8001610C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80016110: jal         0x80012D90
    // 0x80016114: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x80016114: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_2:
    // 0x80016118: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8001611C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80016120: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80016124: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80016128: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8001612C: b           L_80016158
    // 0x80016130: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_80016158;
    // 0x80016130: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80016134:
    // 0x80016134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80016138: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x8001613C: ori         $t7, $t7, 0x38
    ctx->r15 = ctx->r15 | 0X38;
    // 0x80016140: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80016144: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80016148: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8001614C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80016150: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80016154: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80016158:
    // 0x80016158: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_8001615C:
    // 0x8001615C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80016160: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x80016164: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80016168: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001616C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80016170: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x80016174: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80016178: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_8001617C:
    // 0x8001617C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80016180: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80016184: bnel        $v0, $at, L_80016068
    if (ctx->r2 != ctx->r1) {
        // 0x80016188: lw          $t8, 0x4($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X4);
            goto L_80016068;
    }
    goto skip_8;
    // 0x80016188: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    skip_8:
L_8001618C:
    // 0x8001618C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_80016190:
    // 0x80016190: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80016194: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80016198: beql        $a0, $zero, L_800161B0
    if (ctx->r4 == 0) {
        // 0x8001619C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_800161B0;
    }
    goto skip_9;
    // 0x8001619C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    skip_9:
    // 0x800161A0: jal         0x80015C0C
    // 0x800161A4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    func_80015C0C(rdram, ctx);
        goto after_3;
    // 0x800161A4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_3:
    // 0x800161A8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800161AC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_800161B0:
    // 0x800161B0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800161B4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800161B8: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x800161BC: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x800161C0: addiu       $t4, $t4, 0x70C8
    ctx->r12 = ADD32(ctx->r12, 0X70C8);
    // 0x800161C4: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x800161C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800161CC: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800161D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800161D4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_800161D8:
    // 0x800161D8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800161DC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800161E0: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x800161E4: beql        $at, $zero, L_8001622C
    if (ctx->r1 == 0) {
        // 0x800161E8: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_8001622C;
    }
    goto skip_10;
    // 0x800161E8: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_10:
    // 0x800161EC: beq         $t3, $zero, L_80016228
    if (ctx->r11 == 0) {
        // 0x800161F0: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_80016228;
    }
    // 0x800161F0: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x800161F4: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x800161F8: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x800161FC: beql        $t0, $t8, L_80016214
    if (ctx->r8 == ctx->r24) {
        // 0x80016200: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_80016214;
    }
    goto skip_11;
    // 0x80016200: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_11:
    // 0x80016204: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80016208: beql        $t9, $zero, L_8001622C
    if (ctx->r25 == 0) {
        // 0x8001620C: lw          $t6, 0x4($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X4);
            goto L_8001622C;
    }
    goto skip_12;
    // 0x8001620C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    skip_12:
    // 0x80016210: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_80016214:
    // 0x80016214: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80016218: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8001621C: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80016220: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80016224: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_80016228:
    // 0x80016228: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
L_8001622C:
    // 0x8001622C: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x80016230: beql        $at, $zero, L_80016274
    if (ctx->r1 == 0) {
        // 0x80016234: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80016274;
    }
    goto skip_13;
    // 0x80016234: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_13:
    // 0x80016238: beq         $t3, $zero, L_80016270
    if (ctx->r11 == 0) {
        // 0x8001623C: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_80016270;
    }
    // 0x8001623C: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x80016240: lw          $t7, 0x14($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X14);
    // 0x80016244: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80016248: beql        $t0, $t7, L_80016260
    if (ctx->r8 == ctx->r15) {
        // 0x8001624C: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_80016260;
    }
    goto skip_14;
    // 0x8001624C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_14:
    // 0x80016250: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80016254: beql        $t8, $zero, L_80016274
    if (ctx->r24 == 0) {
        // 0x80016258: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80016274;
    }
    goto skip_15;
    // 0x80016258: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_15:
    // 0x8001625C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_80016260:
    // 0x80016260: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80016264: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80016268: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8001626C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80016270:
    // 0x80016270: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80016274:
    // 0x80016274: bne         $a2, $t4, L_800161D8
    if (ctx->r6 != ctx->r12) {
        // 0x80016278: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800161D8;
    }
    // 0x80016278: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8001627C: lw          $t5, 0xC($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XC);
    // 0x80016280: bnel        $t5, $zero, L_800162AC
    if (ctx->r13 != 0) {
        // 0x80016284: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800162AC;
    }
    goto skip_16;
    // 0x80016284: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x80016288: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x8001628C: beql        $s0, $zero, L_800162AC
    if (ctx->r16 == 0) {
        // 0x80016290: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800162AC;
    }
    goto skip_17;
    // 0x80016290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
L_80016294:
    // 0x80016294: jal         0x80015C0C
    // 0x80016298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80015C0C(rdram, ctx);
        goto after_4;
    // 0x80016298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001629C: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800162A0: bne         $s0, $zero, L_80016294
    if (ctx->r16 != 0) {
        // 0x800162A4: nop
    
            goto L_80016294;
    }
    // 0x800162A4: nop

L_800162A8:
    // 0x800162A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800162AC:
    // 0x800162AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800162B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800162B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800162B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800162BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800162C0: jr          $ra
    // 0x800162C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800162C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80009CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009CC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009CCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009CD0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80009CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009CD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009CDC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80009CE0: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x80009CE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80009CE8: jal         0x80009B48
    // 0x80009CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMoveGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80009CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009CF8: jr          $ra
    // 0x80009CFC: nop

    return;
    // 0x80009CFC: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FBC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132FC0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132FC4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132FC8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132FCC: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132FD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132FD4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132FD8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132FDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132FE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132FE4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132FE8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132FEC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132FF0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132FF4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132FF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132FFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133000: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133004: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133008: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013300C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133014: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133018: jal         0x8000B93C
    // 0x8013301C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013301C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133020: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133024: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133028: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013302C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133034: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133038: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013303C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133040: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133044: jal         0x80007080
    // 0x80133048: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133048: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013304C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133050: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133054: jr          $ra
    // 0x80133058: nop

    return;
    // 0x80133058: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetNextTimeValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138118: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8013811C: bne         $a0, $at, L_8013812C
    if (ctx->r4 != ctx->r1) {
        // 0x80138120: addiu       $v1, $zero, 0x5
        ctx->r3 = ADD32(0, 0X5);
            goto L_8013812C;
    }
    // 0x80138120: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80138124: jr          $ra
    // 0x80138128: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x80138128: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_8013812C:
    // 0x8013812C: jr          $ra
    // 0x80138130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80138130: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftPikachuSpecialAirLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801523B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801523B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801523B8: jal         0x80152328
    // 0x801523BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwLoopUpdateThunder(rdram, ctx);
        goto after_0;
    // 0x801523BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801523C0: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x801523C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801523C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801523CC: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x801523D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801523D4: jal         0x800E6F24
    // 0x801523D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801523D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801523DC: jal         0x800E0830
    // 0x801523E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801523E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801523E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801523E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801523EC: jr          $ra
    // 0x801523F0: nop

    return;
    // 0x801523F0: nop

;}
RECOMP_FUNC void lbParticleSetupBankID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE254: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800CE258: beq         $at, $zero, L_800CE410
    if (ctx->r1 == 0) {
        // 0x800CE25C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800CE410;
    }
    // 0x800CE25C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800CE260: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800CE264: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CE268: addiu       $t6, $t6, 0x63C0
    ctx->r14 = ADD32(ctx->r14, 0X63C0);
    // 0x800CE26C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800CE270: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800CE274: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CE278: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800CE27C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800CE280: addiu       $t8, $t8, 0x63E0
    ctx->r24 = ADD32(ctx->r24, 0X63E0);
    // 0x800CE284: addu        $a2, $v0, $t8
    ctx->r6 = ADD32(ctx->r2, ctx->r24);
    // 0x800CE288: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE28C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800CE290: addiu       $t5, $a1, 0x4
    ctx->r13 = ADD32(ctx->r5, 0X4);
    // 0x800CE294: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CE298: sw          $t5, 0x6400($at)
    MEM_W(0X6400, ctx->r1) = ctx->r13;
    // 0x800CE29C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800CE2A0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CE2A4: addiu       $t6, $t6, 0x6420
    ctx->r14 = ADD32(ctx->r14, 0X6420);
    // 0x800CE2A8: addu        $t0, $v0, $t6
    ctx->r8 = ADD32(ctx->r2, ctx->r14);
    // 0x800CE2AC: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x800CE2B0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800CE2B4: blez        $t8, L_800CE2E8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CE2B8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800CE2E8;
    }
    // 0x800CE2B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CE2BC: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800CE2C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_800CE2C4:
    // 0x800CE2C4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800CE2C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CE2CC: addu        $t5, $t9, $a1
    ctx->r13 = ADD32(ctx->r25, ctx->r5);
    // 0x800CE2D0: sw          $t5, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r13;
    // 0x800CE2D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800CE2D8: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CE2DC: beql        $at, $zero, L_800CE2C4
    if (ctx->r1 == 0) {
        // 0x800CE2E0: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_800CE2C4;
    }
    goto skip_0;
    // 0x800CE2E0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800CE2E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800CE2E8:
    // 0x800CE2E8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800CE2EC: addiu       $v1, $a3, 0x4
    ctx->r3 = ADD32(ctx->r7, 0X4);
    // 0x800CE2F0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800CE2F4: blez        $v0, L_800CE320
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CE2F8: nop
    
            goto L_800CE320;
    }
    // 0x800CE2F8: nop

    // 0x800CE2FC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800CE300:
    // 0x800CE300: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800CE304: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CE308: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800CE30C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800CE310: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800CE314: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CE318: beql        $at, $zero, L_800CE300
    if (ctx->r1 == 0) {
        // 0x800CE31C: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800CE300;
    }
    goto skip_1;
    // 0x800CE31C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_800CE320:
    // 0x800CE320: blez        $v0, L_800CE410
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CE324: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800CE410;
    }
    // 0x800CE324: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800CE328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE32C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
L_800CE330:
    // 0x800CE330: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CE334: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800CE338: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800CE33C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800CE340: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800CE344: beq         $a1, $zero, L_800CE37C
    if (ctx->r5 == 0) {
        // 0x800CE348: addu        $t3, $a0, $t2
        ctx->r11 = ADD32(ctx->r4, ctx->r10);
            goto L_800CE37C;
    }
    // 0x800CE348: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
L_800CE34C:
    // 0x800CE34C: lw          $t6, 0x18($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X18);
    // 0x800CE350: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE354: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800CE358: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800CE35C: sw          $t7, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r15;
    // 0x800CE360: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800CE364: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CE368: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800CE36C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800CE370: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800CE374: bnel        $at, $zero, L_800CE34C
    if (ctx->r1 != 0) {
        // 0x800CE378: addu        $t3, $a0, $t2
        ctx->r11 = ADD32(ctx->r4, ctx->r10);
            goto L_800CE34C;
    }
    goto skip_2;
    // 0x800CE378: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    skip_2:
L_800CE37C:
    // 0x800CE37C: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800CE380: bnel        $t4, $t5, L_800CE3FC
    if (ctx->r12 != ctx->r13) {
        // 0x800CE384: lw          $t8, 0x0($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X0);
            goto L_800CE3FC;
    }
    goto skip_3;
    // 0x800CE384: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    skip_3:
    // 0x800CE388: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800CE38C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800CE390: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x800CE394: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800CE398: beq         $t7, $zero, L_800CE3B0
    if (ctx->r15 == 0) {
        // 0x800CE39C: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_800CE3B0;
    }
    // 0x800CE39C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800CE3A0: lw          $t9, 0x18($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X18);
    // 0x800CE3A4: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x800CE3A8: b           L_800CE3F8
    // 0x800CE3AC: sw          $t5, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r13;
        goto L_800CE3F8;
    // 0x800CE3AC: sw          $t5, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r13;
L_800CE3B0:
    // 0x800CE3B0: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800CE3B4: beq         $at, $zero, L_800CE3F8
    if (ctx->r1 == 0) {
        // 0x800CE3B8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800CE3F8;
    }
    // 0x800CE3B8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CE3BC: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x800CE3C0: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
L_800CE3C4:
    // 0x800CE3C4: lw          $t7, 0x18($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X18);
    // 0x800CE3C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE3CC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800CE3D0: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800CE3D4: sw          $t8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r24;
    // 0x800CE3D8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800CE3DC: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800CE3E0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800CE3E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CE3E8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CE3EC: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x800CE3F0: bnel        $at, $zero, L_800CE3C4
    if (ctx->r1 != 0) {
        // 0x800CE3F4: addu        $t3, $a0, $t2
        ctx->r11 = ADD32(ctx->r4, ctx->r10);
            goto L_800CE3C4;
    }
    goto skip_4;
    // 0x800CE3F4: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    skip_4:
L_800CE3F8:
    // 0x800CE3F8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
L_800CE3FC:
    // 0x800CE3FC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800CE400: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CE404: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CE408: bnel        $at, $zero, L_800CE330
    if (ctx->r1 != 0) {
        // 0x800CE40C: lw          $t9, 0x0($t0)
        ctx->r25 = MEM_W(ctx->r8, 0X0);
            goto L_800CE330;
    }
    goto skip_5;
    // 0x800CE40C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    skip_5:
L_800CE410:
    // 0x800CE410: jr          $ra
    // 0x800CE414: nop

    return;
    // 0x800CE414: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801553A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801553A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801553AC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801553B0: jal         0x800DE80C
    // 0x801553B4: addiu       $a1, $a1, 0x53C8
    ctx->r5 = ADD32(ctx->r5, 0X53C8);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x801553B4: addiu       $a1, $a1, 0x53C8
    ctx->r5 = ADD32(ctx->r5, 0X53C8);
    after_0:
    // 0x801553B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801553BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801553C0: jr          $ra
    // 0x801553C4: nop

    return;
    // 0x801553C4: nop

;}
RECOMP_FUNC void gmCameraScreenFlashProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DC24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010DC28: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010DC2C: lbu         $t8, 0x1581($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1581);
    // 0x8010DC30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DC34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010DC38: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8010DC3C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8010DC40: beq         $t8, $zero, L_8010DD84
    if (ctx->r24 == 0) {
        // 0x8010DC44: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8010DD84;
    }
    // 0x8010DC44: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8010DC48: addiu       $t2, $t2, 0x65B0
    ctx->r10 = ADD32(ctx->r10, 0X65B0);
    // 0x8010DC4C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8010DC50: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x8010DC54: ori         $t6, $t6, 0x8
    ctx->r14 = ctx->r14 | 0X8;
    // 0x8010DC58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010DC5C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8010DC60: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010DC64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010DC68: lw          $t7, 0x1460($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1460);
    // 0x8010DC6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010DC70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010DC74: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8010DC78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010DC7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010DC80: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8010DC84: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010DC88: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x8010DC8C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8010DC90: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x8010DC94: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010DC98: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x8010DC9C: lh          $a2, 0x8($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X8);
    // 0x8010DCA0: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x8010DCA4: lh          $t0, 0xA($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XA);
    // 0x8010DCA8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8010DCAC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8010DCB0: bgez        $a1, L_8010DCBC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8010DCB4: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_8010DCBC;
    }
    // 0x8010DCB4: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x8010DCB8: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_8010DCBC:
    // 0x8010DCBC: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8010DCC0: bgez        $a2, L_8010DCCC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8010DCC4: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_8010DCCC;
    }
    // 0x8010DCC4: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8010DCC8: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_8010DCCC:
    // 0x8010DCCC: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8010DCD0: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x8010DCD4: bgez        $a3, L_8010DCE0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8010DCD8: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_8010DCE0;
    }
    // 0x8010DCD8: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x8010DCDC: addiu       $at, $a3, 0x3
    ctx->r1 = ADD32(ctx->r7, 0X3);
L_8010DCE0:
    // 0x8010DCE0: sra         $a3, $at, 2
    ctx->r7 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8010DCE4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8010DCE8: bgez        $t0, L_8010DCF4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8010DCEC: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_8010DCF4;
    }
    // 0x8010DCEC: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x8010DCF0: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
L_8010DCF4:
    // 0x8010DCF4: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
    // 0x8010DCF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010DCFC: subu        $t4, $a3, $t0
    ctx->r12 = SUB32(ctx->r7, ctx->r8);
    // 0x8010DD00: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8010DD04: addu        $t5, $a2, $a1
    ctx->r13 = ADD32(ctx->r6, ctx->r5);
    // 0x8010DD08: addu        $ra, $t0, $a3
    ctx->r31 = ADD32(ctx->r8, ctx->r7);
    // 0x8010DD0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010DD10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010DD14: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x8010DD18: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8010DD1C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8010DD20: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8010DD24: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010DD28: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8010DD2C: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    // 0x8010DD30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010DD34: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8010DD38: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8010DD3C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8010DD40: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8010DD44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010DD48: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010DD4C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8010DD50: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8010DD54: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010DD58: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010DD5C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010DD60: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8010DD64: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8010DD68: nop

    // 0x8010DD6C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8010DD70: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8010DD74: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8010DD78: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8010DD7C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8010DD80: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8010DD84:
    // 0x8010DD84: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010DD8C: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8010DD90: andi        $t7, $t9, 0x8
    ctx->r15 = ctx->r25 & 0X8;
    // 0x8010DD94: beq         $t7, $zero, L_8010DDA4
    if (ctx->r15 == 0) {
        // 0x8010DD98: nop
    
            goto L_8010DDA4;
    }
    // 0x8010DD98: nop

    // 0x8010DD9C: b           L_8010DDA4
    // 0x8010DDA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010DDA4;
    // 0x8010DDA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010DDA4:
    // 0x8010DDA4: jal         0x80017B80
    // 0x8010DDA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcCaptureCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010DDA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8010DDAC: jal         0x80017CC8
    // 0x8010DDB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80017CC8(rdram, ctx);
        goto after_1;
    // 0x8010DDB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8010DDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DDB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010DDBC: jr          $ra
    // 0x8010DDC0: nop

    return;
    // 0x8010DDC0: nop

;}
RECOMP_FUNC void func_8002D1F4_2DDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D1F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D1FC: jal         0x8002A070
    // 0x8002D200: nop

    n_alLoadParam(rdram, ctx);
        goto after_0;
    // 0x8002D200: nop

    after_0:
    // 0x8002D204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D20C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D210: jr          $ra
    // 0x8002D214: nop

    return;
    // 0x8002D214: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EBD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015EBD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EBDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015EBE0: jal         0x8015E9E0
    // 0x8015EBE4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftYoshiSpecialHiUpdateEggVectors(rdram, ctx);
        goto after_0;
    // 0x8015EBE4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015EBE8: jal         0x800D91EC
    // 0x8015EBEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_1;
    // 0x8015EBEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015EBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EBF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015EBF8: jr          $ra
    // 0x8015EBFC: nop

    return;
    // 0x8015EBFC: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C404: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016C408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C40C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016C410: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016C414: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x8016C418: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8016C41C: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8016C420: jal         0x801680EC
    // 0x8016C424: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016C424: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    after_0:
    // 0x8016C428: jal         0x80167FA0
    // 0x8016C42C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_1;
    // 0x8016C42C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016C430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016C438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C43C: jr          $ra
    // 0x8016C440: nop

    return;
    // 0x8016C440: nop

;}
RECOMP_FUNC void grZebesAcidUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108240: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80108244: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80108248: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8010824C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108250: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80108254: beq         $t7, $zero, L_80108260
    if (ctx->r15 == 0) {
        // 0x80108258: nop
    
            goto L_80108260;
    }
    // 0x80108258: nop

    // 0x8010825C: sb          $t8, 0x1406($at)
    MEM_B(0X1406, ctx->r1) = ctx->r24;
L_80108260:
    // 0x80108260: jr          $ra
    // 0x80108264: nop

    return;
    // 0x80108264: nop

;}
RECOMP_FUNC void ftMarioSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156428: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015642C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156430: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80156434: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80156438: jal         0x80156418
    // 0x8015643C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMarioSpecialHiInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x8015643C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80156440: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80156444: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x80156448: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015644C: sw          $zero, 0xB18($t7)
    MEM_W(0XB18, ctx->r15) = 0;
    // 0x80156450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80156458: jal         0x800E6F24
    // 0x8015645C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015645C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80156460: jal         0x800E0830
    // 0x80156464: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80156464: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80156468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015646C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156470: jr          $ra
    // 0x80156474: nop

    return;
    // 0x80156474: nop

;}
RECOMP_FUNC void spDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025100: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x80025104: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80025108: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8002510C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80025110: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80025114: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80025118: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8002511C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80025120: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80025124: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80025128: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8002512C: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x80025130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025134: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80025138: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8002513C: beq         $t7, $zero, L_8002514C
    if (ctx->r15 == 0) {
        // 0x80025140: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_8002514C;
    }
    // 0x80025140: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80025144: b           L_80025E00
    // 0x80025148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80025E00;
    // 0x80025148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002514C:
    // 0x8002514C: sw          $zero, -0x2F90($at)
    MEM_W(-0X2F90, ctx->r1) = 0;
    // 0x80025150: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80025154: addiu       $a1, $a1, -0x2F8C
    ctx->r5 = ADD32(ctx->r5, -0X2F8C);
    // 0x80025158: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002515C: bne         $t8, $zero, L_8002516C
    if (ctx->r24 != 0) {
        // 0x80025160: sw          $t8, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r24;
            goto L_8002516C;
    }
    // 0x80025160: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025164: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x80025168: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
L_8002516C:
    // 0x8002516C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025170: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x80025174: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80025178: sw          $t7, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r15;
    // 0x8002517C: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80025180: beq         $t9, $zero, L_80025194
    if (ctx->r25 == 0) {
        // 0x80025184: lw          $s4, 0x34($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X34);
            goto L_80025194;
    }
    // 0x80025184: lw          $s4, 0x34($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X34);
    // 0x80025188: lhu         $t6, 0x14($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X14);
    // 0x8002518C: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x80025190: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_80025194:
    // 0x80025194: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x80025198: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8002519C: andi        $t8, $a0, 0x400
    ctx->r24 = ctx->r4 & 0X400;
    // 0x800251A0: beq         $t8, $zero, L_800251B4
    if (ctx->r24 == 0) {
        // 0x800251A4: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800251B4;
    }
    // 0x800251A4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800251A8: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x800251AC: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800251B0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800251B4:
    // 0x800251B4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800251B8: andi        $v1, $s3, 0x1
    ctx->r3 = ctx->r19 & 0X1;
    // 0x800251BC: beql        $v0, $s3, L_8002534C
    if (ctx->r2 == ctx->r19) {
        // 0x800251C0: andi        $t7, $a0, 0x8
        ctx->r15 = ctx->r4 & 0X8;
            goto L_8002534C;
    }
    goto skip_0;
    // 0x800251C0: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
    skip_0:
    // 0x800251C4: beq         $v1, $zero, L_80025200
    if (ctx->r3 == 0) {
        // 0x800251C8: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_80025200;
    }
    // 0x800251C8: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800251CC: bne         $t9, $zero, L_80025200
    if (ctx->r25 != 0) {
        // 0x800251D0: lw          $t6, 0x18C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18C);
            goto L_80025200;
    }
    // 0x800251D0: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800251D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800251D8: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800251DC: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800251E0: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x800251E4: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x800251E8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800251EC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800251F0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800251F4: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800251F8: b           L_80025238
    // 0x800251FC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
        goto L_80025238;
    // 0x800251FC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_80025200:
    // 0x80025200: bne         $v1, $zero, L_80025238
    if (ctx->r3 != 0) {
        // 0x80025204: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80025238;
    }
    // 0x80025204: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80025208: beq         $t6, $zero, L_80025238
    if (ctx->r14 == 0) {
        // 0x8002520C: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_80025238;
    }
    // 0x8002520C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025210: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80025214: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025218: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8002521C: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x80025220: ori         $t6, $t6, 0x7008
    ctx->r14 = ctx->r14 | 0X7008;
    // 0x80025224: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80025228: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8002522C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80025230: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x80025234: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_80025238:
    // 0x80025238: andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // 0x8002523C: beq         $v0, $zero, L_80025298
    if (ctx->r2 == 0) {
        // 0x80025240: nop
    
            goto L_80025298;
    }
    // 0x80025240: nop

    // 0x80025244: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80025248: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x8002524C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80025250: bne         $t8, $zero, L_80025298
    if (ctx->r24 != 0) {
        // 0x80025254: addiu       $t6, $t9, 0x8
        ctx->r14 = ADD32(ctx->r25, 0X8);
            goto L_80025298;
    }
    // 0x80025254: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80025258: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x8002525C: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x80025260: addiu       $t8, $zero, -0xFF
    ctx->r24 = ADD32(0, -0XFF);
    // 0x80025264: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80025268: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8002526C: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x80025270: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80025274: ori         $t7, $t7, 0x1E01
    ctx->r15 = ctx->r15 | 0X1E01;
    // 0x80025278: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8002527C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025280: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025284: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80025288: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8002528C: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x80025290: b           L_800252D0
    // 0x80025294: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
        goto L_800252D0;
    // 0x80025294: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_80025298:
    // 0x80025298: bnel        $v0, $zero, L_800252D4
    if (ctx->r2 != 0) {
        // 0x8002529C: andi        $t3, $s3, 0x80
        ctx->r11 = ctx->r19 & 0X80;
            goto L_800252D4;
    }
    goto skip_1;
    // 0x8002529C: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
    skip_1:
    // 0x800252A0: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x800252A4: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800252A8: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x800252AC: beq         $t6, $zero, L_800252D0
    if (ctx->r14 == 0) {
        // 0x800252B0: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_800252D0;
    }
    // 0x800252B0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800252B4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800252B8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800252BC: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x800252C0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800252C4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800252C8: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800252CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800252D0:
    // 0x800252D0: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
L_800252D4:
    // 0x800252D4: beq         $t3, $zero, L_80025310
    if (ctx->r11 == 0) {
        // 0x800252D8: nop
    
            goto L_80025310;
    }
    // 0x800252D8: nop

    // 0x800252DC: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800252E0: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800252E4: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800252E8: bne         $t7, $zero, L_80025310
    if (ctx->r15 != 0) {
        // 0x800252EC: addiu       $t9, $t8, 0x8
        ctx->r25 = ADD32(ctx->r24, 0X8);
            goto L_80025310;
    }
    // 0x800252EC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800252F0: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800252F4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800252F8: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x800252FC: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x80025300: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80025304: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80025308: b           L_80025348
    // 0x8002530C: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
        goto L_80025348;
    // 0x8002530C: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
L_80025310:
    // 0x80025310: bnel        $t3, $zero, L_8002534C
    if (ctx->r11 != 0) {
        // 0x80025314: andi        $t7, $a0, 0x8
        ctx->r15 = ctx->r4 & 0X8;
            goto L_8002534C;
    }
    goto skip_2;
    // 0x80025314: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
    skip_2:
    // 0x80025318: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x8002531C: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x80025320: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80025324: beq         $t9, $zero, L_80025348
    if (ctx->r25 == 0) {
        // 0x80025328: addiu       $t7, $t6, 0x8
        ctx->r15 = ADD32(ctx->r14, 0X8);
            goto L_80025348;
    }
    // 0x80025328: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002532C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x80025330: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80025334: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x80025338: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8002533C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80025340: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80025344: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
L_80025348:
    // 0x80025348: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
L_8002534C:
    // 0x8002534C: beq         $t7, $zero, L_80025374
    if (ctx->r15 == 0) {
        // 0x80025350: sh          $a0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r4;
            goto L_80025374;
    }
    // 0x80025350: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x80025354: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x80025358: lui         $t6, 0xEE00
    ctx->r14 = S32(0XEE00 << 16);
    // 0x8002535C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80025360: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025364: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80025368: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
    // 0x8002536C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80025370: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80025374:
    // 0x80025374: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x80025378: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8002537C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025380: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025384: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x80025388: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002538C: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x80025390: lbu         $t9, 0x19($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X19);
    // 0x80025394: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80025398: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8002539C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800253A0: lbu         $t7, 0x1A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1A);
    // 0x800253A4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800253A8: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800253AC: lbu         $t8, 0x1B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1B);
    // 0x800253B0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800253B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800253B8: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800253BC: beq         $v1, $at, L_800253CC
    if (ctx->r3 == ctx->r1) {
        // 0x800253C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800253CC;
    }
    // 0x800253C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800253C4: bnel        $v1, $at, L_80025428
    if (ctx->r3 != ctx->r1) {
        // 0x800253C8: lbu         $t9, 0x1B($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X1B);
            goto L_80025428;
    }
    goto skip_3;
    // 0x800253C8: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
    skip_3:
L_800253CC:
    // 0x800253CC: lbu         $t7, 0x1B($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1B);
    // 0x800253D0: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800253D4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800253D8: bne         $t7, $at, L_80025404
    if (ctx->r15 != ctx->r1) {
        // 0x800253DC: addiu       $t8, $t9, 0x8
        ctx->r24 = ADD32(ctx->r25, 0X8);
            goto L_80025404;
    }
    // 0x800253DC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800253E0: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800253E4: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x800253E8: ori         $t6, $t6, 0xFE23
    ctx->r14 = ctx->r14 | 0XFE23;
    // 0x800253EC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800253F0: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800253F4: addiu       $t7, $zero, -0xC07
    ctx->r15 = ADD32(0, -0XC07);
    // 0x800253F8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800253FC: b           L_80025478
    // 0x80025400: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
        goto L_80025478;
    // 0x80025400: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_80025404:
    // 0x80025404: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x80025408: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x8002540C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80025410: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x80025414: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025418: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8002541C: b           L_80025478
    // 0x80025420: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
        goto L_80025478;
    // 0x80025420: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80025424: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
L_80025428:
    // 0x80025428: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x8002542C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80025430: bne         $t9, $at, L_8002545C
    if (ctx->r25 != ctx->r1) {
        // 0x80025434: addiu       $t6, $t8, 0x8
        ctx->r14 = ADD32(ctx->r24, 0X8);
            goto L_8002545C;
    }
    // 0x80025434: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025438: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x8002543C: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x80025440: ori         $t7, $t7, 0xFE23
    ctx->r15 = ctx->r15 | 0XFE23;
    // 0x80025444: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025448: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x8002544C: addiu       $t9, $zero, -0xC07
    ctx->r25 = ADD32(0, -0XC07);
    // 0x80025450: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80025454: b           L_80025478
    // 0x80025458: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80025478;
    // 0x80025458: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_8002545C:
    // 0x8002545C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025460: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x80025464: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x80025468: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8002546C: ori         $t7, $t7, 0x9623
    ctx->r15 = ctx->r15 | 0X9623;
    // 0x80025470: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025474: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_80025478:
    // 0x80025478: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x8002547C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80025484: bne         $v1, $at, L_80025578
    if (ctx->r3 != ctx->r1) {
        // 0x80025488: addiu       $t6, $t8, 0x8
        ctx->r14 = ADD32(ctx->r24, 0X8);
            goto L_80025578;
    }
    // 0x80025488: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8002548C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025490: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80025494: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x80025498: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x8002549C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800254A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800254A4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800254A8: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800254AC: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800254B0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800254B4: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800254B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800254BC: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x800254C0: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800254C4: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x800254C8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800254CC: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800254D0: lui         $a3, 0xE600
    ctx->r7 = S32(0XE600 << 16);
    // 0x800254D4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800254D8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800254DC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800254E0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800254E4: lw          $a1, 0x18C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18C);
    // 0x800254E8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800254EC: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800254F0: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
    // 0x800254F4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800254F8: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x800254FC: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80025500: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80025504: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025508: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x8002550C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80025510: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x80025514: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80025518: sw          $a3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r7;
    // 0x8002551C: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x80025520: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80025524: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025528: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x8002552C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80025530: lh          $t7, 0x1E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E);
    // 0x80025534: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80025538: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8002553C: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x80025540: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x80025544: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80025548: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x8002554C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80025550: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80025554: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025558: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8002555C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80025560: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025564: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80025568: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x8002556C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80025570: sw          $a3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r7;
    // 0x80025574: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_80025578:
    // 0x80025578: bne         $s6, $v1, L_80025610
    if (ctx->r22 != ctx->r3) {
        // 0x8002557C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80025610;
    }
    // 0x8002557C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80025580: lhu         $t8, 0x14($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X14);
    // 0x80025584: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025588: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x8002558C: beq         $t6, $zero, L_80025610
    if (ctx->r14 == 0) {
        // 0x80025590: addiu       $t9, $t7, 0x8
        ctx->r25 = ADD32(ctx->r15, 0X8);
            goto L_80025610;
    }
    // 0x80025590: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80025594: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025598: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8002559C: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800255A0: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800255A4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800255A8: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800255AC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800255B0: ori         $t9, $t9, 0x1201
    ctx->r25 = ctx->r25 | 0X1201;
    // 0x800255B4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800255B8: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800255BC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800255C0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800255C4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800255C8: lui         $t9, 0x77FC
    ctx->r25 = S32(0X77FC << 16);
    // 0x800255CC: lui         $t7, 0xFC17
    ctx->r15 = S32(0XFC17 << 16);
    // 0x800255D0: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800255D4: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800255D8: ori         $t7, $t7, 0xFE2F
    ctx->r15 = ctx->r15 | 0XFE2F;
    // 0x800255DC: ori         $t9, $t9, 0xF87C
    ctx->r25 = ctx->r25 | 0XF87C;
    // 0x800255E0: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800255E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800255E8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800255EC: lui         $t7, 0xEC15
    ctx->r15 = S32(0XEC15 << 16);
    // 0x800255F0: lui         $t9, 0x3B78
    ctx->r25 = S32(0X3B78 << 16);
    // 0x800255F4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800255F8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800255FC: ori         $t9, $t9, 0xE42A
    ctx->r25 = ctx->r25 | 0XE42A;
    // 0x80025600: ori         $t7, $t7, 0xFD5D
    ctx->r15 = ctx->r15 | 0XFD5D;
    // 0x80025604: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025608: b           L_800256BC
    // 0x8002560C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
        goto L_800256BC;
    // 0x8002560C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_80025610:
    // 0x80025610: bne         $s6, $v1, L_800256BC
    if (ctx->r22 != ctx->r3) {
        // 0x80025614: lw          $t8, 0x18C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18C);
            goto L_800256BC;
    }
    // 0x80025614: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025618: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8002561C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025620: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80025624: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80025628: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x8002562C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80025630: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025634: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025638: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8002563C: ori         $t7, $t7, 0x1201
    ctx->r15 = ctx->r15 | 0X1201;
    // 0x80025640: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025644: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025648: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8002564C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80025650: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025654: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025658: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x8002565C: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x80025660: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025664: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025668: addiu       $t9, $zero, 0xA00
    ctx->r25 = ADD32(0, 0XA00);
    // 0x8002566C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80025670: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025674: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025678: lui         $t7, 0xEC15
    ctx->r15 = S32(0XEC15 << 16);
    // 0x8002567C: lui         $t9, 0x3B78
    ctx->r25 = S32(0X3B78 << 16);
    // 0x80025680: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025684: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025688: ori         $t9, $t9, 0xE42A
    ctx->r25 = ctx->r25 | 0XE42A;
    // 0x8002568C: ori         $t7, $t7, 0xFD5D
    ctx->r15 = ctx->r15 | 0XFD5D;
    // 0x80025690: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025694: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80025698: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x8002569C: lui         $t9, 0x7FFD
    ctx->r25 = S32(0X7FFD << 16);
    // 0x800256A0: lui         $t7, 0xFC27
    ctx->r15 = S32(0XFC27 << 16);
    // 0x800256A4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800256A8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800256AC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800256B0: ori         $t9, $t9, 0x7E38
    ctx->r25 = ctx->r25 | 0X7E38;
    // 0x800256B4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800256B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800256BC:
    // 0x800256BC: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x800256C0: andi        $t8, $s3, 0x10
    ctx->r24 = ctx->r19 & 0X10;
    // 0x800256C4: beq         $t8, $zero, L_800256D8
    if (ctx->r24 == 0) {
        // 0x800256C8: andi        $s2, $s3, 0x20
        ctx->r18 = ctx->r19 & 0X20;
            goto L_800256D8;
    }
    // 0x800256C8: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
    // 0x800256CC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800256D0: b           L_800256E4
    // 0x800256D4: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
        goto L_800256E4;
    // 0x800256D4: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
L_800256D8:
    // 0x800256D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800256DC: nop

    // 0x800256E0: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800256E4:
    // 0x800256E4: beql        $s4, $zero, L_80025BA4
    if (ctx->r20 == 0) {
        // 0x800256E8: lh          $t7, 0x4($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X4);
            goto L_80025BA4;
    }
    goto skip_4;
    // 0x800256E8: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x800256EC: beql        $s2, $zero, L_80025728
    if (ctx->r18 == 0) {
        // 0x800256F0: lh          $t7, 0x2($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2);
            goto L_80025728;
    }
    goto skip_5;
    // 0x800256F0: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x800256F4: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x800256F8: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800256FC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80025700: beq         $s6, $t6, L_80025724
    if (ctx->r22 == ctx->r14) {
        // 0x80025704: addiu       $t9, $t7, 0x8
        ctx->r25 = ADD32(ctx->r15, 0X8);
            goto L_80025724;
    }
    // 0x80025704: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80025708: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x8002570C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80025710: lui         $t6, 0x20
    ctx->r14 = S32(0X20 << 16);
    // 0x80025714: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80025718: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8002571C: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x80025720: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
L_80025724:
    // 0x80025724: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
L_80025728:
    // 0x80025728: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002572C: lwc1        $f12, -0x17A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X17A0);
    // 0x80025730: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80025734: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80025738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002573C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025740: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80025744: andi        $t9, $s3, 0x80
    ctx->r25 = ctx->r19 & 0X80;
    // 0x80025748: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002574C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80025750: div.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80025754: andi        $t8, $s3, 0x100
    ctx->r24 = ctx->r19 & 0X100;
    // 0x80025758: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8002575C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80025760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80025764: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80025768: nop

    // 0x8002576C: sw          $v0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r2;
    // 0x80025770: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80025774: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80025778: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8002577C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80025780: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80025784: nop

    // 0x80025788: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002578C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x80025790: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80025794: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025798: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8002579C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800257A0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800257A4: nop

    // 0x800257A8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800257AC: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800257B0: beq         $t9, $zero, L_800257BC
    if (ctx->r25 == 0) {
        // 0x800257B4: or          $t5, $v1, $zero
        ctx->r13 = ctx->r3 | 0;
            goto L_800257BC;
    }
    // 0x800257B4: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800257B8: addiu       $t5, $v1, 0x10
    ctx->r13 = ADD32(ctx->r3, 0X10);
L_800257BC:
    // 0x800257BC: beql        $t8, $zero, L_800257D0
    if (ctx->r24 == 0) {
        // 0x800257C0: lh          $a3, 0x2C($s0)
        ctx->r7 = MEM_H(ctx->r16, 0X2C);
            goto L_800257D0;
    }
    goto skip_6;
    // 0x800257C0: lh          $a3, 0x2C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2C);
    skip_6:
    // 0x800257C4: lh          $t6, 0x42($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X42);
    // 0x800257C8: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800257CC: lh          $a3, 0x2C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2C);
L_800257D0:
    // 0x800257D0: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800257D4: nop

    // 0x800257D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800257DC: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800257E0: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800257E4: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800257E8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800257EC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800257F0: beql        $s2, $zero, L_8002580C
    if (ctx->r18 == 0) {
        // 0x800257F4: lh          $v0, 0x28($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X28);
            goto L_8002580C;
    }
    goto skip_7;
    // 0x800257F4: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
    skip_7:
    // 0x800257F8: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x800257FC: beql        $s6, $t9, L_8002580C
    if (ctx->r22 == ctx->r25) {
        // 0x80025800: lh          $v0, 0x28($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X28);
            goto L_8002580C;
    }
    goto skip_8;
    // 0x80025800: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
    skip_8:
    // 0x80025804: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80025808: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
L_8002580C:
    // 0x8002580C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80025810: blez        $v0, L_80025B14
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80025814: nop
    
            goto L_80025B14;
    }
    // 0x80025814: nop

    // 0x80025818: lh          $a1, 0x0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X0);
    // 0x8002581C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80025820: blez        $a1, L_80025B14
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80025824: nop
    
            goto L_80025B14;
    }
    // 0x80025824: nop

    // 0x80025828: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8002582C: lwc1        $f12, -0x179C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X179C);
    // 0x80025830: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
L_80025834:
    // 0x80025834: addu        $t6, $a1, $s1
    ctx->r14 = ADD32(ctx->r5, ctx->r17);
    // 0x80025838: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
    // 0x8002583C: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80025840: beq         $at, $zero, L_80025938
    if (ctx->r1 == 0) {
        // 0x80025844: andi        $t4, $s3, 0x100
        ctx->r12 = ctx->r19 & 0X100;
            goto L_80025938;
    }
    // 0x80025844: andi        $t4, $s3, 0x100
    ctx->r12 = ctx->r19 & 0X100;
    // 0x80025848: lh          $a0, 0x2C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2C);
    // 0x8002584C: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x80025850: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x80025854: addu        $ra, $ra, $a0
    ctx->r31 = ADD32(ctx->r31, ctx->r4);
    // 0x80025858: mtc1        $ra, $f6
    ctx->f6.u32l = ctx->r31;
    // 0x8002585C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80025860: addu        $a3, $a0, $ra
    ctx->r7 = ADD32(ctx->r4, ctx->r31);
    // 0x80025864: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80025868: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002586C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80025870: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x80025874: addu        $fp, $fp, $t7
    ctx->r30 = ADD32(ctx->r30, ctx->r15);
    // 0x80025878: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002587C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80025880: add.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80025884: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80025888: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002588C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80025890: nop

    // 0x80025894: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80025898: nop

    // 0x8002589C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800258A0: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800258A4: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800258A8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800258AC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800258B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800258B4: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800258B8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800258BC: nop

    // 0x800258C0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800258C4: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800258C8: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800258CC: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800258D0: beq         $t3, $zero, L_800258DC
    if (ctx->r11 == 0) {
        // 0x800258D4: add.s       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
            goto L_800258DC;
    }
    // 0x800258D4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800258D8: addiu       $t5, $v1, 0x10
    ctx->r13 = ADD32(ctx->r3, 0X10);
L_800258DC:
    // 0x800258DC: beq         $t4, $zero, L_800258EC
    if (ctx->r12 == 0) {
        // 0x800258E0: trunc.w.s   $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
            goto L_800258EC;
    }
    // 0x800258E0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800258E4: lh          $t7, 0x42($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X42);
    // 0x800258E8: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
L_800258EC:
    // 0x800258EC: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800258F0: addu        $t8, $v0, $fp
    ctx->r24 = ADD32(ctx->r2, ctx->r30);
    // 0x800258F4: sw          $t8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r24;
    // 0x800258F8: beq         $s2, $zero, L_80025910
    if (ctx->r18 == 0) {
        // 0x800258FC: addu        $t0, $t0, $fp
        ctx->r8 = ADD32(ctx->r8, ctx->r30);
            goto L_80025910;
    }
    // 0x800258FC: addu        $t0, $t0, $fp
    ctx->r8 = ADD32(ctx->r8, ctx->r30);
    // 0x80025900: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x80025904: beql        $s6, $t6, L_80025914
    if (ctx->r22 == ctx->r14) {
        // 0x80025908: lh          $v0, 0xC($s4)
        ctx->r2 = MEM_H(ctx->r20, 0XC);
            goto L_80025914;
    }
    goto skip_9;
    // 0x80025908: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
    skip_9:
    // 0x8002590C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80025910:
    // 0x80025910: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
L_80025914:
    // 0x80025914: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80025918: beq         $v0, $zero, L_80025928
    if (ctx->r2 == 0) {
        // 0x8002591C: nop
    
            goto L_80025928;
    }
    // 0x8002591C: nop

    // 0x80025920: b           L_80025928
    // 0x80025924: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80025928;
    // 0x80025924: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80025928:
    // 0x80025928: addu        $t7, $v1, $ra
    ctx->r15 = ADD32(ctx->r3, ctx->r31);
    // 0x8002592C: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80025930: bne         $at, $zero, L_80025B14
    if (ctx->r1 != 0) {
        // 0x80025934: nop
    
            goto L_80025B14;
    }
    // 0x80025934: nop

L_80025938:
    // 0x80025938: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8002593C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80025940: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80025944: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80025948: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002594C: addu        $a2, $a1, $s1
    ctx->r6 = ADD32(ctx->r5, ctx->r17);
    // 0x80025950: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
    // 0x80025954: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80025958: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x8002595C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80025960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80025964: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80025968: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002596C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80025970: addu        $a3, $v0, $ra
    ctx->r7 = ADD32(ctx->r2, ctx->r31);
    // 0x80025974: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80025978: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8002597C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80025980: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80025984: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80025988: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8002598C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80025990: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80025994: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80025998: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x8002599C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800259A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800259A4: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800259A8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800259AC: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800259B0: nop

    // 0x800259B4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800259B8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800259BC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800259C0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800259C4: nop

    // 0x800259C8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800259CC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800259D0: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800259D4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800259D8: beq         $t3, $zero, L_800259E4
    if (ctx->r11 == 0) {
        // 0x800259DC: add.s       $f6, $f10, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
            goto L_800259E4;
    }
    // 0x800259DC: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800259E0: addiu       $t1, $v1, 0x10
    ctx->r9 = ADD32(ctx->r3, 0X10);
L_800259E4:
    // 0x800259E4: beq         $t4, $zero, L_800259F4
    if (ctx->r12 == 0) {
        // 0x800259E8: trunc.w.s   $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_800259F4;
    }
    // 0x800259E8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800259EC: lh          $t9, 0x40($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X40);
    // 0x800259F0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
L_800259F4:
    // 0x800259F4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800259F8: beql        $v0, $zero, L_80025A48
    if (ctx->r2 == 0) {
        // 0x800259FC: addu        $a3, $a0, $s7
        ctx->r7 = ADD32(ctx->r4, ctx->r23);
            goto L_80025A48;
    }
    goto skip_10;
    // 0x800259FC: addu        $a3, $a0, $s7
    ctx->r7 = ADD32(ctx->r4, ctx->r23);
    skip_10:
    // 0x80025A00: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80025A04: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80025A08: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80025A0C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80025A10: nop

    // 0x80025A14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80025A18: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80025A1C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80025A20: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80025A24: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80025A28: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80025A2C: beq         $s2, $zero, L_80025A44
    if (ctx->r18 == 0) {
        // 0x80025A30: addu        $t0, $t0, $fp
        ctx->r8 = ADD32(ctx->r8, ctx->r30);
            goto L_80025A44;
    }
    // 0x80025A30: addu        $t0, $t0, $fp
    ctx->r8 = ADD32(ctx->r8, ctx->r30);
    // 0x80025A34: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x80025A38: beql        $s6, $t9, L_80025A48
    if (ctx->r22 == ctx->r25) {
        // 0x80025A3C: addu        $a3, $a0, $s7
        ctx->r7 = ADD32(ctx->r4, ctx->r23);
            goto L_80025A48;
    }
    goto skip_11;
    // 0x80025A3C: addu        $a3, $a0, $s7
    ctx->r7 = ADD32(ctx->r4, ctx->r23);
    skip_11:
    // 0x80025A40: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80025A44:
    // 0x80025A44: addu        $a3, $a0, $s7
    ctx->r7 = ADD32(ctx->r4, ctx->r23);
L_80025A48:
    // 0x80025A48: beq         $s2, $zero, L_80025A60
    if (ctx->r18 == 0) {
        // 0x80025A4C: addu        $v1, $v1, $s7
        ctx->r3 = ADD32(ctx->r3, ctx->r23);
            goto L_80025A60;
    }
    // 0x80025A4C: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x80025A50: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x80025A54: beql        $s6, $t8, L_80025A64
    if (ctx->r22 == ctx->r24) {
        // 0x80025A58: lw          $t6, 0x8($s4)
        ctx->r14 = MEM_W(ctx->r20, 0X8);
            goto L_80025A64;
    }
    goto skip_12;
    // 0x80025A58: lw          $t6, 0x8($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X8);
    skip_12:
    // 0x80025A5C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80025A60:
    // 0x80025A60: lw          $t6, 0x8($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X8);
L_80025A64:
    // 0x80025A64: addiu       $a0, $sp, 0x18C
    ctx->r4 = ADD32(ctx->r29, 0X18C);
    // 0x80025A68: beql        $t6, $zero, L_80025AEC
    if (ctx->r14 == 0) {
        // 0x80025A6C: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80025AEC;
    }
    goto skip_13;
    // 0x80025A6C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    skip_13:
    // 0x80025A70: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80025A74: sw          $ra, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r31;
    // 0x80025A78: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80025A7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80025A80: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80025A84: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80025A88: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80025A8C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80025A90: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80025A94: sw          $t0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r8;
    // 0x80025A98: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
    // 0x80025A9C: swc1        $f14, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f14.u32l;
    // 0x80025AA0: swc1        $f16, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->f16.u32l;
    // 0x80025AA4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80025AA8: jal         0x800238B8
    // 0x80025AAC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    drawbitmap(rdram, ctx);
        goto after_0;
    // 0x80025AAC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_0:
    // 0x80025AB0: lh          $t8, 0x28($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X28);
    // 0x80025AB4: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x80025AB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80025ABC: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80025AC0: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x80025AC4: lwc1        $f12, -0x1798($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1798);
    // 0x80025AC8: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x80025ACC: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x80025AD0: lw          $ra, 0x19C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X19C);
    // 0x80025AD4: lwc1        $f14, 0x194($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X194);
    // 0x80025AD8: lwc1        $f16, 0x198($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X198);
    // 0x80025ADC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80025AE0: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
    // 0x80025AE4: addu        $a2, $t6, $s1
    ctx->r6 = ADD32(ctx->r14, ctx->r17);
    // 0x80025AE8: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_80025AEC:
    // 0x80025AEC: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x80025AF0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80025AF4: slt         $at, $s5, $t9
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80025AF8: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x80025AFC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80025B00: beq         $at, $zero, L_80025B14
    if (ctx->r1 == 0) {
        // 0x80025B04: addu        $s7, $s7, $t7
        ctx->r23 = ADD32(ctx->r23, ctx->r15);
            goto L_80025B14;
    }
    // 0x80025B04: addu        $s7, $s7, $t7
    ctx->r23 = ADD32(ctx->r23, ctx->r15);
    // 0x80025B08: lh          $a1, 0x0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X0);
    // 0x80025B0C: bgtzl       $a1, L_80025834
    if (SIGNED(ctx->r5) > 0) {
        // 0x80025B10: lh          $t8, 0x4($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X4);
            goto L_80025834;
    }
    goto skip_14;
    // 0x80025B10: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    skip_14:
L_80025B14:
    // 0x80025B14: beq         $s2, $zero, L_80025B34
    if (ctx->r18 == 0) {
        // 0x80025B18: lw          $t8, 0x18C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18C);
            goto L_80025B34;
    }
    // 0x80025B18: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025B1C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025B20: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025B24: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80025B28: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80025B2C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025B30: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_80025B34:
    // 0x80025B34: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x80025B38: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x80025B3C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80025B40: bne         $s6, $v1, L_80025DB8
    if (ctx->r22 != ctx->r3) {
        // 0x80025B44: addiu       $t8, $t9, 0x8
        ctx->r24 = ADD32(ctx->r25, 0X8);
            goto L_80025DB8;
    }
    // 0x80025B44: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80025B48: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025B4C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80025B50: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80025B54: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80025B58: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025B5C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80025B60: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x80025B64: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80025B68: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025B6C: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80025B70: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80025B74: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80025B78: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025B7C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80025B80: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80025B84: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80025B88: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025B8C: addiu       $t6, $zero, 0xC00
    ctx->r14 = ADD32(0, 0XC00);
    // 0x80025B90: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80025B94: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80025B98: b           L_80025DB8
    // 0x80025B9C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_80025DB8;
    // 0x80025B9C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x80025BA0: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
L_80025BA4:
    // 0x80025BA4: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x80025BA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80025BAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80025BB0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80025BB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80025BB8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025BBC: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80025BC0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x80025BC4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80025BC8: lw          $a0, -0x1240($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1240);
    // 0x80025BCC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80025BD0: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80025BD4: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80025BD8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80025BDC: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x80025BE0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80025BE4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80025BE8: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80025BEC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80025BF0: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80025BF4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80025BF8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80025BFC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025C00: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80025C04: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80025C08: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80025C0C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80025C10: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80025C14: beq         $at, $zero, L_80025C30
    if (ctx->r1 == 0) {
        // 0x80025C18: nop
    
            goto L_80025C30;
    }
    // 0x80025C18: nop

    // 0x80025C1C: lw          $a2, -0x123C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X123C);
    // 0x80025C20: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80025C24: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80025C28: bne         $at, $zero, L_80025C38
    if (ctx->r1 != 0) {
        // 0x80025C2C: nop
    
            goto L_80025C38;
    }
    // 0x80025C2C: nop

L_80025C30:
    // 0x80025C30: b           L_80025DB8
    // 0x80025C34: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_80025DB8;
    // 0x80025C34: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_80025C38:
    // 0x80025C38: lw          $v0, -0x1238($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1238);
    // 0x80025C3C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80025C40: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80025C44: bne         $at, $zero, L_80025C60
    if (ctx->r1 != 0) {
        // 0x80025C48: nop
    
            goto L_80025C60;
    }
    // 0x80025C48: nop

    // 0x80025C4C: lw          $v1, -0x1234($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1234);
    // 0x80025C50: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80025C54: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80025C58: beql        $at, $zero, L_80025C6C
    if (ctx->r1 == 0) {
        // 0x80025C5C: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80025C6C;
    }
    goto skip_15;
    // 0x80025C5C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    skip_15:
L_80025C60:
    // 0x80025C60: b           L_80025DB8
    // 0x80025C64: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_80025DB8;
    // 0x80025C64: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x80025C68: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
L_80025C6C:
    // 0x80025C6C: beql        $at, $zero, L_80025C7C
    if (ctx->r1 == 0) {
        // 0x80025C70: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80025C7C;
    }
    goto skip_16;
    // 0x80025C70: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    skip_16:
    // 0x80025C74: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80025C78: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80025C7C:
    // 0x80025C7C: bnel        $at, $zero, L_80025C8C
    if (ctx->r1 != 0) {
        // 0x80025C80: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80025C8C;
    }
    goto skip_17;
    // 0x80025C80: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    skip_17:
    // 0x80025C84: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80025C88: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
L_80025C8C:
    // 0x80025C8C: beql        $at, $zero, L_80025C9C
    if (ctx->r1 == 0) {
        // 0x80025C90: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80025C9C;
    }
    goto skip_18;
    // 0x80025C90: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    skip_18:
    // 0x80025C94: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x80025C98: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
L_80025C9C:
    // 0x80025C9C: bnel        $at, $zero, L_80025CAC
    if (ctx->r1 != 0) {
        // 0x80025CA0: lbu         $t7, 0x18($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X18);
            goto L_80025CAC;
    }
    goto skip_19;
    // 0x80025CA0: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    skip_19:
    // 0x80025CA4: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x80025CA8: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
L_80025CAC:
    // 0x80025CAC: lbu         $t6, 0x19($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X19);
    // 0x80025CB0: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x80025CB4: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80025CB8: andi        $t8, $t9, 0xF800
    ctx->r24 = ctx->r25 & 0XF800;
    // 0x80025CBC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80025CC0: andi        $t9, $t7, 0x7C0
    ctx->r25 = ctx->r15 & 0X7C0;
    // 0x80025CC4: lbu         $t7, 0x1A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1A);
    // 0x80025CC8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80025CCC: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x80025CD0: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80025CD4: andi        $t9, $t8, 0x3E
    ctx->r25 = ctx->r24 & 0X3E;
    // 0x80025CD8: lbu         $t8, 0x1B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1B);
    // 0x80025CDC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80025CE0: ori         $t2, $t2, 0xA01
    ctx->r10 = ctx->r10 | 0XA01;
    // 0x80025CE4: sra         $t6, $t8, 7
    ctx->r14 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80025CE8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025CEC: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x80025CF0: or          $v0, $t7, $t9
    ctx->r2 = ctx->r15 | ctx->r25;
    // 0x80025CF4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80025CF8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x80025CFC: lui         $t7, 0xD700
    ctx->r15 = S32(0XD700 << 16);
    // 0x80025D00: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80025D04: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80025D08: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x80025D0C: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x80025D10: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80025D14: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80025D18: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025D1C: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80025D20: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80025D24: lw          $a2, 0x18C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18C);
    // 0x80025D28: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80025D2C: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x80025D30: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80025D34: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025D38: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x80025D3C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80025D40: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80025D44: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x80025D48: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x80025D4C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80025D50: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80025D54: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025D58: andi        $t8, $a3, 0x3FF
    ctx->r24 = ctx->r7 & 0X3FF;
    // 0x80025D5C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80025D60: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80025D64: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80025D68: andi        $t6, $ra, 0x3FF
    ctx->r14 = ctx->r31 & 0X3FF;
    // 0x80025D6C: andi        $t8, $s1, 0x3FF
    ctx->r24 = ctx->r17 & 0X3FF;
    // 0x80025D70: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80025D74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80025D78: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80025D7C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80025D80: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80025D84: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x80025D88: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80025D8C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025D90: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80025D94: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x80025D98: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x80025D9C: lui         $t6, 0xD700
    ctx->r14 = S32(0XD700 << 16);
    // 0x80025DA0: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x80025DA4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80025DA8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x80025DAC: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80025DB0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80025DB4: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_80025DB8:
    // 0x80025DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80025DBC: bne         $v1, $at, L_80025DDC
    if (ctx->r3 != ctx->r1) {
        // 0x80025DC0: lw          $t9, 0x18C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18C);
            goto L_80025DDC;
    }
    // 0x80025DC0: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x80025DC4: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80025DC8: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x80025DCC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80025DD0: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x80025DD4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80025DD8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_80025DDC:
    // 0x80025DDC: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x80025DE0: lui         $t7, 0xDF00
    ctx->r15 = S32(0XDF00 << 16);
    // 0x80025DE4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80025DE8: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x80025DEC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80025DF0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80025DF4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x80025DF8: sw          $t8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r24;
    // 0x80025DFC: lw          $v0, 0x188($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X188);
L_80025E00:
    // 0x80025E00: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80025E04: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80025E08: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80025E0C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80025E10: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80025E14: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80025E18: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80025E1C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80025E20: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80025E24: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80025E28: jr          $ra
    // 0x80025E2C: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x80025E2C: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void unref_800036B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800036B4: addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // 0x800036B8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800036BC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800036C0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800036C4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800036C8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800036CC: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800036D0: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x800036D4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800036D8: or          $v1, $v1, $t6
    ctx->r3 = ctx->r3 | ctx->r14;
    // 0x800036DC: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x800036E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800036E4: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
    // 0x800036E8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800036EC: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800036F0: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x800036F4: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x800036F8: addu        $t5, $v1, $a1
    ctx->r13 = ADD32(ctx->r3, ctx->r5);
    // 0x800036FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003700: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80003704: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003708: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x8000370C: subu        $t6, $t3, $v0
    ctx->r14 = SUB32(ctx->r11, ctx->r2);
    // 0x80003710: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x80003714: sllv        $t7, $v1, $t6
    ctx->r15 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x80003718: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x8000371C: addiu       $a0, $t1, 0xA
    ctx->r4 = ADD32(ctx->r9, 0XA);
    // 0x80003720: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    // 0x80003724: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80003728: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
    // 0x8000372C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80003730: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x80003734: addiu       $a3, $zero, 0x1F
    ctx->r7 = ADD32(0, 0X1F);
L_80003738:
    // 0x80003738: bgtz        $v0, L_80003754
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000373C: slti        $at, $t1, 0x2
        ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
            goto L_80003754;
    }
    // 0x8000373C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80003740: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80003744: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003748: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000374C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003750: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
L_80003754:
    // 0x80003754: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003758: subu        $t6, $a3, $v0
    ctx->r14 = SUB32(ctx->r7, ctx->r2);
    // 0x8000375C: sllv        $t2, $v1, $t6
    ctx->r10 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x80003760: srl         $t2, $t2, 31
    ctx->r10 = S32(U32(ctx->r10) >> 31);
    // 0x80003764: beq         $t2, $zero, L_80003770
    if (ctx->r10 == 0) {
        // 0x80003768: sll         $t7, $t1, 2
        ctx->r15 = S32(ctx->r9 << 2);
            goto L_80003770;
    }
    // 0x80003768: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8000376C: bne         $at, $zero, L_800037FC
    if (ctx->r1 != 0) {
        // 0x80003770: addiu       $t8, $sp, 0xBC
        ctx->r24 = ADD32(ctx->r29, 0XBC);
            goto L_800037FC;
    }
L_80003770:
    // 0x80003770: addiu       $t8, $sp, 0xBC
    ctx->r24 = ADD32(ctx->r29, 0XBC);
    // 0x80003774: beq         $t2, $zero, L_800037AC
    if (ctx->r10 == 0) {
        // 0x80003778: addu        $t4, $t7, $t8
        ctx->r12 = ADD32(ctx->r15, ctx->r24);
            goto L_800037AC;
    }
    // 0x80003778: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8000377C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80003780: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80003784: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x80003788: lw          $t9, -0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, -0X8);
    // 0x8000378C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80003790: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80003794: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80003798: lw          $t6, -0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, -0X4);
    // 0x8000379C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800037A0: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800037A4: b           L_80003738
    // 0x800037A8: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
        goto L_80003738;
    // 0x800037A8: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
L_800037AC:
    // 0x800037AC: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800037B0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800037B4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x800037B8: sw          $zero, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = 0;
    // 0x800037BC: sw          $zero, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = 0;
    // 0x800037C0: beq         $at, $zero, L_800037DC
    if (ctx->r1 == 0) {
        // 0x800037C4: sw          $zero, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = 0;
            goto L_800037DC;
    }
    // 0x800037C4: sw          $zero, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = 0;
    // 0x800037C8: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800037CC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800037D0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800037D4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800037D8: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
L_800037DC:
    // 0x800037DC: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x800037E0: subu        $t8, $t3, $v0
    ctx->r24 = SUB32(ctx->r11, ctx->r2);
    // 0x800037E4: sllv        $t9, $v1, $t8
    ctx->r25 = S32(ctx->r3 << (ctx->r24 & 31));
    // 0x800037E8: srl         $t6, $t9, 24
    ctx->r14 = S32(U32(ctx->r25) >> 24);
    // 0x800037EC: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x800037F0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800037F4: b           L_80003738
    // 0x800037F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80003738;
    // 0x800037F8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800037FC:
    // 0x800037FC: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x80003800: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80003804: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
L_80003808:
    // 0x80003808: bgtz        $v0, L_80003824
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000380C: slti        $at, $t4, 0x2
        ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
            goto L_80003824;
    }
    // 0x8000380C: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80003810: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80003814: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003818: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000381C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003820: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
L_80003824:
    // 0x80003824: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003828: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x8000382C: sllv        $t2, $v1, $t8
    ctx->r10 = S32(ctx->r3 << (ctx->r24 & 31));
    // 0x80003830: srl         $t2, $t2, 31
    ctx->r10 = S32(U32(ctx->r10) >> 31);
    // 0x80003834: beq         $t2, $zero, L_80003840
    if (ctx->r10 == 0) {
        // 0x80003838: sll         $t9, $t4, 2
        ctx->r25 = S32(ctx->r12 << 2);
            goto L_80003840;
    }
    // 0x80003838: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8000383C: bne         $at, $zero, L_800038CC
    if (ctx->r1 != 0) {
        // 0x80003840: addiu       $t6, $sp, 0x5C
        ctx->r14 = ADD32(ctx->r29, 0X5C);
            goto L_800038CC;
    }
L_80003840:
    // 0x80003840: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80003844: beq         $t2, $zero, L_8000387C
    if (ctx->r10 == 0) {
        // 0x80003848: addu        $s0, $t9, $t6
        ctx->r16 = ADD32(ctx->r25, ctx->r14);
            goto L_8000387C;
    }
    // 0x80003848: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x8000384C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80003850: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80003854: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x80003858: lw          $t7, -0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X8);
    // 0x8000385C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80003860: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80003864: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80003868: lw          $t8, -0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X4);
    // 0x8000386C: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80003870: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80003874: b           L_80003808
    // 0x80003878: sw          $t2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r10;
        goto L_80003808;
    // 0x80003878: sw          $t2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r10;
L_8000387C:
    // 0x8000387C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80003880: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80003884: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80003888: sw          $zero, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = 0;
    // 0x8000388C: sw          $zero, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = 0;
    // 0x80003890: beq         $at, $zero, L_800038AC
    if (ctx->r1 == 0) {
        // 0x80003894: sw          $zero, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = 0;
            goto L_800038AC;
    }
    // 0x80003894: sw          $zero, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = 0;
    // 0x80003898: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x8000389C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800038A0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800038A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800038A8: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
L_800038AC:
    // 0x800038AC: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x800038B0: subu        $t6, $t3, $v0
    ctx->r14 = SUB32(ctx->r11, ctx->r2);
    // 0x800038B4: sllv        $t7, $v1, $t6
    ctx->r15 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x800038B8: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x800038BC: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x800038C0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800038C4: b           L_80003808
    // 0x800038C8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
        goto L_80003808;
    // 0x800038C8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800038CC:
    // 0x800038CC: sltu        $at, $a1, $t5
    ctx->r1 = ctx->r5 < ctx->r13 ? 1 : 0;
    // 0x800038D0: beq         $at, $zero, L_80003BE8
    if (ctx->r1 == 0) {
        // 0x800038D4: lw          $t4, 0x5C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X5C);
            goto L_80003BE8;
    }
    // 0x800038D4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800038D8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_800038DC:
    // 0x800038DC: bgtzl       $v0, L_800038FC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800038E0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800038FC;
    }
    goto skip_0;
    // 0x800038E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x800038E4: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x800038E8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800038EC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800038F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800038F4: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x800038F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800038FC:
    // 0x800038FC: subu        $t6, $a3, $v0
    ctx->r14 = SUB32(ctx->r7, ctx->r2);
    // 0x80003900: sllv        $t7, $v1, $t6
    ctx->r15 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x80003904: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80003908: bne         $t8, $zero, L_8000394C
    if (ctx->r24 != 0) {
        // 0x8000390C: lw          $t9, 0x10C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X10C);
            goto L_8000394C;
    }
    // 0x8000390C: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x80003910: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80003914: beql        $at, $zero, L_80003934
    if (ctx->r1 == 0) {
        // 0x80003918: addiu       $v0, $v0, -0x8
        ctx->r2 = ADD32(ctx->r2, -0X8);
            goto L_80003934;
    }
    goto skip_1;
    // 0x80003918: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    skip_1:
    // 0x8000391C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80003920: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003924: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003928: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000392C: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x80003930: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
L_80003934:
    // 0x80003934: subu        $t6, $t3, $v0
    ctx->r14 = SUB32(ctx->r11, ctx->r2);
    // 0x80003938: sllv        $t7, $v1, $t6
    ctx->r15 = S32(ctx->r3 << (ctx->r14 & 31));
    // 0x8000393C: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x80003940: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80003944: b           L_80003BDC
    // 0x80003948: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_80003BDC;
    // 0x80003948: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8000394C:
    // 0x8000394C: lw          $s2, 0x0($t1)
    ctx->r18 = MEM_W(ctx->r9, 0X0);
    // 0x80003950: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80003954: beq         $t9, $zero, L_80003A98
    if (ctx->r25 == 0) {
        // 0x80003958: lw          $t2, 0x0($t4)
        ctx->r10 = MEM_W(ctx->r12, 0X0);
            goto L_80003A98;
    }
    // 0x80003958: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8000395C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80003960: beq         $s2, $zero, L_800039B4
    if (ctx->r18 == 0) {
        // 0x80003964: or          $s1, $t1, $zero
        ctx->r17 = ctx->r9 | 0;
            goto L_800039B4;
    }
    // 0x80003964: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_80003968:
    // 0x80003968: bgtzl       $v0, L_80003988
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000396C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80003988;
    }
    goto skip_2;
    // 0x8000396C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_2:
    // 0x80003970: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80003974: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003978: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000397C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003980: or          $v1, $v1, $t6
    ctx->r3 = ctx->r3 | ctx->r14;
    // 0x80003984: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80003988:
    // 0x80003988: subu        $t7, $a3, $v0
    ctx->r15 = SUB32(ctx->r7, ctx->r2);
    // 0x8000398C: sllv        $t8, $v1, $t7
    ctx->r24 = S32(ctx->r3 << (ctx->r15 & 31));
    // 0x80003990: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80003994: bnel        $t9, $zero, L_800039A8
    if (ctx->r25 != 0) {
        // 0x80003998: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_800039A8;
    }
    goto skip_3;
    // 0x80003998: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_3:
    // 0x8000399C: b           L_800039A8
    // 0x800039A0: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
        goto L_800039A8;
    // 0x800039A0: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800039A4: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_800039A8:
    // 0x800039A8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800039AC: bne         $t6, $zero, L_80003968
    if (ctx->r14 != 0) {
        // 0x800039B0: nop
    
            goto L_80003968;
    }
    // 0x800039B0: nop

L_800039B4:
    // 0x800039B4: lw          $s3, 0x8($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X8);
    // 0x800039B8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800039BC: beq         $at, $zero, L_800039D8
    if (ctx->r1 == 0) {
        // 0x800039C0: subu        $t8, $a2, $s3
        ctx->r24 = SUB32(ctx->r6, ctx->r19);
            goto L_800039D8;
    }
    // 0x800039C0: subu        $t8, $a2, $s3
    ctx->r24 = SUB32(ctx->r6, ctx->r19);
    // 0x800039C4: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800039C8: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800039CC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800039D0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800039D4: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
L_800039D8:
    // 0x800039D8: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x800039DC: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800039E0: sllv        $t6, $v1, $t9
    ctx->r14 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x800039E4: subu        $t7, $a2, $s3
    ctx->r15 = SUB32(ctx->r6, ctx->r19);
    // 0x800039E8: srlv        $s1, $t6, $t7
    ctx->r17 = S32(U32(ctx->r14) >> (ctx->r15 & 31));
    // 0x800039EC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800039F0: beq         $at, $zero, L_80003A84
    if (ctx->r1 == 0) {
        // 0x800039F4: or          $s3, $t1, $zero
        ctx->r19 = ctx->r9 | 0;
            goto L_80003A84;
    }
    // 0x800039F4: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x800039F8: beq         $s2, $zero, L_80003A4C
    if (ctx->r18 == 0) {
        // 0x800039FC: addiu       $s0, $s1, 0x1
        ctx->r16 = ADD32(ctx->r17, 0X1);
            goto L_80003A4C;
    }
    // 0x800039FC: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
L_80003A00:
    // 0x80003A00: bgtzl       $v0, L_80003A20
    if (SIGNED(ctx->r2) > 0) {
        // 0x80003A04: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80003A20;
    }
    goto skip_4;
    // 0x80003A04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_4:
    // 0x80003A08: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80003A0C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003A10: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003A14: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003A18: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x80003A1C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80003A20:
    // 0x80003A20: subu        $t9, $a3, $v0
    ctx->r25 = SUB32(ctx->r7, ctx->r2);
    // 0x80003A24: sllv        $t6, $v1, $t9
    ctx->r14 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x80003A28: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003A2C: bnel        $t7, $zero, L_80003A40
    if (ctx->r15 != 0) {
        // 0x80003A30: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_80003A40;
    }
    goto skip_5;
    // 0x80003A30: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_5:
    // 0x80003A34: b           L_80003A40
    // 0x80003A38: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
        goto L_80003A40;
    // 0x80003A38: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    // 0x80003A3C: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
L_80003A40:
    // 0x80003A40: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80003A44: bne         $t8, $zero, L_80003A00
    if (ctx->r24 != 0) {
        // 0x80003A48: nop
    
            goto L_80003A00;
    }
    // 0x80003A48: nop

L_80003A4C:
    // 0x80003A4C: lw          $s2, 0x8($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X8);
    // 0x80003A50: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80003A54: beq         $at, $zero, L_80003A70
    if (ctx->r1 == 0) {
        // 0x80003A58: subu        $t6, $a2, $s2
        ctx->r14 = SUB32(ctx->r6, ctx->r18);
            goto L_80003A70;
    }
    // 0x80003A58: subu        $t6, $a2, $s2
    ctx->r14 = SUB32(ctx->r6, ctx->r18);
    // 0x80003A5C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80003A60: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003A64: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003A68: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003A6C: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
L_80003A70:
    // 0x80003A70: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x80003A74: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80003A78: sllv        $t8, $v1, $t7
    ctx->r24 = S32(ctx->r3 << (ctx->r15 & 31));
    // 0x80003A7C: subu        $t9, $a2, $s2
    ctx->r25 = SUB32(ctx->r6, ctx->r18);
    // 0x80003A80: srlv        $s1, $t8, $t9
    ctx->r17 = S32(U32(ctx->r24) >> (ctx->r25 & 31));
L_80003A84:
    // 0x80003A84: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80003A88: subu        $t7, $t0, $t6
    ctx->r15 = SUB32(ctx->r8, ctx->r14);
    // 0x80003A8C: subu        $s2, $t7, $s0
    ctx->r18 = SUB32(ctx->r15, ctx->r16);
    // 0x80003A90: b           L_80003B28
    // 0x80003A94: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_80003B28;
    // 0x80003A94: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80003A98:
    // 0x80003A98: beq         $s2, $zero, L_80003AEC
    if (ctx->r18 == 0) {
        // 0x80003A9C: or          $s0, $t1, $zero
        ctx->r16 = ctx->r9 | 0;
            goto L_80003AEC;
    }
    // 0x80003A9C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_80003AA0:
    // 0x80003AA0: bgtzl       $v0, L_80003AC0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80003AA4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80003AC0;
    }
    goto skip_6;
    // 0x80003AA4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_6:
    // 0x80003AA8: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80003AAC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003AB0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003AB4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003AB8: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x80003ABC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80003AC0:
    // 0x80003AC0: subu        $t9, $a3, $v0
    ctx->r25 = SUB32(ctx->r7, ctx->r2);
    // 0x80003AC4: sllv        $t6, $v1, $t9
    ctx->r14 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x80003AC8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003ACC: bnel        $t7, $zero, L_80003AE0
    if (ctx->r15 != 0) {
        // 0x80003AD0: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80003AE0;
    }
    goto skip_7;
    // 0x80003AD0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_7:
    // 0x80003AD4: b           L_80003AE0
    // 0x80003AD8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_80003AE0;
    // 0x80003AD8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80003ADC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80003AE0:
    // 0x80003AE0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80003AE4: bne         $t8, $zero, L_80003AA0
    if (ctx->r24 != 0) {
        // 0x80003AE8: nop
    
            goto L_80003AA0;
    }
    // 0x80003AE8: nop

L_80003AEC:
    // 0x80003AEC: lw          $s3, 0x8($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X8);
    // 0x80003AF0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80003AF4: beq         $at, $zero, L_80003B10
    if (ctx->r1 == 0) {
        // 0x80003AF8: subu        $t6, $a2, $s3
        ctx->r14 = SUB32(ctx->r6, ctx->r19);
            goto L_80003B10;
    }
    // 0x80003AF8: subu        $t6, $a2, $s3
    ctx->r14 = SUB32(ctx->r6, ctx->r19);
    // 0x80003AFC: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80003B00: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003B04: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003B08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003B0C: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
L_80003B10:
    // 0x80003B10: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x80003B14: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80003B18: sllv        $t8, $v1, $t7
    ctx->r24 = S32(ctx->r3 << (ctx->r15 & 31));
    // 0x80003B1C: subu        $t9, $a2, $s3
    ctx->r25 = SUB32(ctx->r6, ctx->r19);
    // 0x80003B20: srlv        $s1, $t8, $t9
    ctx->r17 = S32(U32(ctx->r24) >> (ctx->r25 & 31));
    // 0x80003B24: subu        $s2, $t0, $s1
    ctx->r18 = SUB32(ctx->r8, ctx->r17);
L_80003B28:
    // 0x80003B28: beql        $t2, $zero, L_80003B80
    if (ctx->r10 == 0) {
        // 0x80003B2C: lw          $t2, 0x8($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X8);
            goto L_80003B80;
    }
    goto skip_8;
    // 0x80003B2C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    skip_8:
L_80003B30:
    // 0x80003B30: bgtzl       $v0, L_80003B50
    if (SIGNED(ctx->r2) > 0) {
        // 0x80003B34: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80003B50;
    }
    goto skip_9;
    // 0x80003B34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_9:
    // 0x80003B38: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80003B3C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003B40: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003B44: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003B48: or          $v1, $v1, $t6
    ctx->r3 = ctx->r3 | ctx->r14;
    // 0x80003B4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80003B50:
    // 0x80003B50: subu        $t7, $a3, $v0
    ctx->r15 = SUB32(ctx->r7, ctx->r2);
    // 0x80003B54: sllv        $t8, $v1, $t7
    ctx->r24 = S32(ctx->r3 << (ctx->r15 & 31));
    // 0x80003B58: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80003B5C: bnel        $t9, $zero, L_80003B70
    if (ctx->r25 != 0) {
        // 0x80003B60: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80003B70;
    }
    goto skip_10;
    // 0x80003B60: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_10:
    // 0x80003B64: b           L_80003B70
    // 0x80003B68: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
        goto L_80003B70;
    // 0x80003B68: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80003B6C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_80003B70:
    // 0x80003B70: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80003B74: bne         $t6, $zero, L_80003B30
    if (ctx->r14 != 0) {
        // 0x80003B78: nop
    
            goto L_80003B30;
    }
    // 0x80003B78: nop

    // 0x80003B7C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
L_80003B80:
    // 0x80003B80: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80003B84: beq         $at, $zero, L_80003BA0
    if (ctx->r1 == 0) {
        // 0x80003B88: subu        $t8, $a2, $t2
        ctx->r24 = SUB32(ctx->r6, ctx->r10);
            goto L_80003BA0;
    }
    // 0x80003B88: subu        $t8, $a2, $t2
    ctx->r24 = SUB32(ctx->r6, ctx->r10);
    // 0x80003B8C: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80003B90: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80003B94: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003B98: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80003B9C: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
L_80003BA0:
    // 0x80003BA0: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80003BA4: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x80003BA8: sllv        $t6, $v1, $t9
    ctx->r14 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x80003BAC: subu        $t7, $a2, $t2
    ctx->r15 = SUB32(ctx->r6, ctx->r10);
    // 0x80003BB0: srlv        $a1, $t6, $t7
    ctx->r5 = S32(U32(ctx->r14) >> (ctx->r15 & 31));
    // 0x80003BB4: slt         $s0, $zero, $a1
    ctx->r16 = SIGNED(0) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003BB8: beq         $s0, $zero, L_80003BDC
    if (ctx->r16 == 0) {
        // 0x80003BBC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80003BDC;
    }
    // 0x80003BBC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80003BC0:
    // 0x80003BC0: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80003BC4: slt         $s0, $zero, $a1
    ctx->r16 = SIGNED(0) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003BC8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80003BCC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80003BD0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80003BD4: bne         $s0, $zero, L_80003BC0
    if (ctx->r16 != 0) {
        // 0x80003BD8: sb          $t8, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r24;
            goto L_80003BC0;
    }
    // 0x80003BD8: sb          $t8, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r24;
L_80003BDC:
    // 0x80003BDC: sltu        $at, $t0, $t5
    ctx->r1 = ctx->r8 < ctx->r13 ? 1 : 0;
    // 0x80003BE0: bne         $at, $zero, L_800038DC
    if (ctx->r1 != 0) {
        // 0x80003BE4: nop
    
            goto L_800038DC;
    }
    // 0x80003BE4: nop

L_80003BE8:
    // 0x80003BE8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80003BEC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80003BF0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80003BF4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80003BF8: jr          $ra
    // 0x80003BFC: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    return;
    // 0x80003BFC: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
;}
RECOMP_FUNC void syUtilsCot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800188A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800188A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800188A8: jal         0x800184E0
    // 0x800188AC: nop

    syUtilsTan(rdram, ctx);
        goto after_0;
    // 0x800188AC: nop

    after_0:
    // 0x800188B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800188B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800188B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800188BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800188C0: jr          $ra
    // 0x800188C4: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x800188C4: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void mnPlayers1PBonusCheckCursorPuckGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134D54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134D58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80134D5C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80134D60: addiu       $s1, $s1, 0x7648
    ctx->r17 = ADD32(ctx->r17, 0X7648);
    // 0x80134D64: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134D68: lw          $t6, 0x7724($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7724);
    // 0x80134D6C: lw          $t7, 0x34($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X34);
    // 0x80134D70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80134D74: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80134D78: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80134D7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134D80: beq         $at, $zero, L_80134D90
    if (ctx->r1 == 0) {
        // 0x80134D84: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80134D90;
    }
    // 0x80134D84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80134D88: b           L_80134E3C
    // 0x80134D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134E3C;
    // 0x80134D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134D90:
    // 0x80134D90: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80134D94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80134D98: beql        $t8, $at, L_80134DAC
    if (ctx->r24 == ctx->r1) {
        // 0x80134D9C: lw          $t9, 0x50($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X50);
            goto L_80134DAC;
    }
    goto skip_0;
    // 0x80134D9C: lw          $t9, 0x50($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X50);
    skip_0:
    // 0x80134DA0: b           L_80134E3C
    // 0x80134DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134E3C;
    // 0x80134DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134DA8: lw          $t9, 0x50($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X50);
L_80134DAC:
    // 0x80134DAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80134DB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80134DB4: bne         $t9, $at, L_80134E38
    if (ctx->r25 != ctx->r1) {
        // 0x80134DB8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80134E38;
    }
    // 0x80134DB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80134DBC: jal         0x8013464C
    // 0x80134DC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayers1PBonusCheckPuckInRange(rdram, ctx);
        goto after_0;
    // 0x80134DC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80134DC4: beq         $v0, $zero, L_80134E38
    if (ctx->r2 == 0) {
        // 0x80134DC8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80134E38;
    }
    // 0x80134DC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80134DCC: sw          $s0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r16;
    // 0x80134DD0: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x80134DD4: sw          $t0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r8;
    // 0x80134DD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134DDC: sw          $s0, 0x769C($at)
    MEM_W(0X769C, ctx->r1) = ctx->r16;
    // 0x80134DE0: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x80134DE4: jal         0x8013476C
    // 0x80134DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusUpdateFighter(rdram, ctx);
        goto after_1;
    // 0x80134DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80134DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134DF0: jal         0x80134BB0
    // 0x80134DF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusUpdateCursorGrabPriorities(rdram, ctx);
        goto after_2;
    // 0x80134DF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80134DF8: jal         0x80134C80
    // 0x80134DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusSetCursorPuckOffset(rdram, ctx);
        goto after_3;
    // 0x80134DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80134E00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80134E04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80134E08: jal         0x80134364
    // 0x80134E0C: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x80134E0C: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    after_4:
    // 0x80134E10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134E14: sw          $t1, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r9;
    // 0x80134E18: jal         0x800269C0
    // 0x80134E1C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80134E1C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_5:
    // 0x80134E20: jal         0x80134858
    // 0x80134E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusDestroyPortraitFlash(rdram, ctx);
        goto after_6;
    // 0x80134E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80134E28: jal         0x801347F8
    // 0x80134E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusUpdateNameAndEmblem(rdram, ctx);
        goto after_7;
    // 0x80134E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80134E30: b           L_80134E3C
    // 0x80134E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134E3C;
    // 0x80134E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134E38:
    // 0x80134E38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134E3C:
    // 0x80134E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134E40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134E44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80134E48: jr          $ra
    // 0x80134E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80134E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl3_80132EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EC0: jr          $ra
    // 0x80132EC4: nop

    return;
    // 0x80132EC4: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155A20: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155A24: jal         0x800DE80C
    // 0x80155A28: addiu       $a1, $a1, 0x5A3C
    ctx->r5 = ADD32(ctx->r5, 0X5A3C);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x80155A28: addiu       $a1, $a1, 0x5A3C
    ctx->r5 = ADD32(ctx->r5, 0X5A3C);
    after_0:
    // 0x80155A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155A34: jr          $ra
    // 0x80155A38: nop

    return;
    // 0x80155A38: nop

;}
RECOMP_FUNC void syMatrixTraRotRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C21C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001C220: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001C224: lwc1        $f0, -0x1C44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C44);
    // 0x8001C228: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001C22C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001C230: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001C234: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C238: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001C23C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8001C240: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C244: addiu       $t4, $t4, -0x46B0
    ctx->r12 = ADD32(ctx->r12, -0X46B0);
    // 0x8001C248: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8001C24C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8001C250: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001C254: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001C258: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C25C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8001C260: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001C264: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001C268: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8001C26C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001C270: andi        $t7, $a2, 0x7FF
    ctx->r15 = ctx->r6 & 0X7FF;
    // 0x8001C274: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001C278: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001C27C: andi        $t6, $a2, 0x800
    ctx->r14 = ctx->r6 & 0X800;
    // 0x8001C280: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8001C284: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8001C288: beq         $t6, $zero, L_8001C294
    if (ctx->r14 == 0) {
        // 0x8001C28C: lhu         $a3, 0x0($t9)
        ctx->r7 = MEM_HU(ctx->r25, 0X0);
            goto L_8001C294;
    }
    // 0x8001C28C: lhu         $a3, 0x0($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X0);
    // 0x8001C290: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_8001C294:
    // 0x8001C294: addiu       $v0, $a2, 0x400
    ctx->r2 = ADD32(ctx->r6, 0X400);
    // 0x8001C298: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8001C29C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001C2A0: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001C2A4: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8001C2A8: beq         $t6, $zero, L_8001C2B4
    if (ctx->r14 == 0) {
        // 0x8001C2AC: lhu         $a1, 0x0($t9)
        ctx->r5 = MEM_HU(ctx->r25, 0X0);
            goto L_8001C2B4;
    }
    // 0x8001C2AC: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x8001C2B0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8001C2B4:
    // 0x8001C2B4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001C2B8: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x8001C2BC: andi        $t8, $t0, 0x7FF
    ctx->r24 = ctx->r8 & 0X7FF;
    // 0x8001C2C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001C2C4: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001C2C8: andi        $t7, $t0, 0x800
    ctx->r15 = ctx->r8 & 0X800;
    // 0x8001C2CC: beq         $t7, $zero, L_8001C2D8
    if (ctx->r15 == 0) {
        // 0x8001C2D0: lhu         $a2, 0x0($t6)
        ctx->r6 = MEM_HU(ctx->r14, 0X0);
            goto L_8001C2D8;
    }
    // 0x8001C2D0: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x8001C2D4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_8001C2D8:
    // 0x8001C2D8: addiu       $v0, $t0, 0x400
    ctx->r2 = ADD32(ctx->r8, 0X400);
    // 0x8001C2DC: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x8001C2E0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001C2E4: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001C2E8: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x8001C2EC: beq         $t7, $zero, L_8001C2F8
    if (ctx->r15 == 0) {
        // 0x8001C2F0: lhu         $v1, 0x0($t6)
        ctx->r3 = MEM_HU(ctx->r14, 0X0);
            goto L_8001C2F8;
    }
    // 0x8001C2F0: lhu         $v1, 0x0($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X0);
    // 0x8001C2F4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8001C2F8:
    // 0x8001C2F8: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x8001C2FC: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8001C300: andi        $t9, $t2, 0x7FF
    ctx->r25 = ctx->r10 & 0X7FF;
    // 0x8001C304: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C308: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C30C: andi        $t8, $t2, 0x800
    ctx->r24 = ctx->r10 & 0X800;
    // 0x8001C310: beq         $t8, $zero, L_8001C31C
    if (ctx->r24 == 0) {
        // 0x8001C314: lhu         $v0, 0x0($t7)
        ctx->r2 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C31C;
    }
    // 0x8001C314: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C318: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8001C31C:
    // 0x8001C31C: addiu       $t0, $t2, 0x400
    ctx->r8 = ADD32(ctx->r10, 0X400);
    // 0x8001C320: andi        $t9, $t0, 0x7FF
    ctx->r25 = ctx->r8 & 0X7FF;
    // 0x8001C324: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C328: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C32C: andi        $t8, $t0, 0x800
    ctx->r24 = ctx->r8 & 0X800;
    // 0x8001C330: beq         $t8, $zero, L_8001C33C
    if (ctx->r24 == 0) {
        // 0x8001C334: lhu         $t3, 0x0($t7)
        ctx->r11 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C33C;
    }
    // 0x8001C334: lhu         $t3, 0x0($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C338: negu        $t3, $t3
    ctx->r11 = SUB32(0, ctx->r11);
L_8001C33C:
    // 0x8001C33C: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C340: lui         $s0, 0xFFFF
    ctx->r16 = S32(0XFFFF << 16);
    // 0x8001C344: negu        $t2, $a2
    ctx->r10 = SUB32(0, ctx->r6);
    // 0x8001C348: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001C34C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8001C350: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C354: nop

    // 0x8001C358: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001C35C: mflo        $t0
    ctx->r8 = lo;
    // 0x8001C360: sra         $t0, $t0, 14
    ctx->r8 = S32(SIGNED(ctx->r8) >> 14);
    // 0x8001C364: and         $t9, $t0, $s0
    ctx->r25 = ctx->r8 & ctx->r16;
    // 0x8001C368: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C36C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8001C370: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001C374: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001C378: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001C37C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C380: sra         $t1, $t1, 14
    ctx->r9 = S32(SIGNED(ctx->r9) >> 14);
    // 0x8001C384: srl         $t6, $t1, 16
    ctx->r14 = S32(U32(ctx->r9) >> 16);
    // 0x8001C388: multu       $a3, $a2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C38C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8001C390: andi        $t9, $t1, 0xFFFF
    ctx->r25 = ctx->r9 & 0XFFFF;
    // 0x8001C394: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8001C398: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C39C: and         $t7, $t2, $s0
    ctx->r15 = ctx->r10 & ctx->r16;
    // 0x8001C3A0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8001C3A4: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8001C3A8: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8001C3AC: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x8001C3B0: mflo        $t4
    ctx->r12 = lo;
    // 0x8001C3B4: sra         $t4, $t4, 15
    ctx->r12 = S32(SIGNED(ctx->r12) >> 15);
    // 0x8001C3B8: nop

    // 0x8001C3BC: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C3C0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C3C4: sra         $t6, $t9, 14
    ctx->r14 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C3C8: nop

    // 0x8001C3CC: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C3D0: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C3D4: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C3D8: subu        $t5, $t6, $t8
    ctx->r13 = SUB32(ctx->r14, ctx->r24);
    // 0x8001C3DC: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C3E0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C3E4: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C3E8: nop

    // 0x8001C3EC: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C3F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C3F4: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C3F8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001C3FC: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C400: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8001C404: and         $t7, $t5, $s0
    ctx->r15 = ctx->r13 & ctx->r16;
    // 0x8001C408: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8001C40C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8001C410: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001C414: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8001C418: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001C41C: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8001C420: mflo        $t0
    ctx->r8 = lo;
    // 0x8001C424: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C428: sra         $t0, $t0, 14
    ctx->r8 = S32(SIGNED(ctx->r8) >> 14);
    // 0x8001C42C: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C430: and         $t7, $t0, $s0
    ctx->r15 = ctx->r8 & ctx->r16;
    // 0x8001C434: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8001C438: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x8001C43C: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8001C440: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8001C444: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8001C448: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C44C: sra         $t1, $t1, 15
    ctx->r9 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8001C450: nop

    // 0x8001C454: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C458: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C45C: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C460: nop

    // 0x8001C464: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C468: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C46C: sra         $t9, $t7, 14
    ctx->r25 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C470: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C474: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C478: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C47C: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C480: and         $t6, $t4, $s0
    ctx->r14 = ctx->r12 & ctx->r16;
    // 0x8001C484: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C488: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8001C48C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C490: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x8001C494: subu        $t2, $t7, $t9
    ctx->r10 = SUB32(ctx->r15, ctx->r25);
    // 0x8001C498: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C49C: srl         $t8, $t2, 16
    ctx->r24 = S32(U32(ctx->r10) >> 16);
    // 0x8001C4A0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001C4A4: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x8001C4A8: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8001C4AC: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x8001C4B0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001C4B4: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8001C4B8: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001C4BC: mflo        $v0
    ctx->r2 = lo;
    // 0x8001C4C0: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8001C4C4: and         $t7, $v0, $s0
    ctx->r15 = ctx->r2 & ctx->r16;
    // 0x8001C4C8: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001C4CC: sw          $t7, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r15;
    // 0x8001C4D0: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x8001C4D4: srl         $t9, $a2, 16
    ctx->r25 = S32(U32(ctx->r6) >> 16);
    // 0x8001C4D8: and         $t7, $a3, $s0
    ctx->r15 = ctx->r7 & ctx->r16;
    // 0x8001C4DC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001C4E0: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x8001C4E4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8001C4E8: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8001C4EC: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x8001C4F0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001C4F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001C4F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001C4FC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8001C500: nop

    // 0x8001C504: and         $t8, $t0, $s0
    ctx->r24 = ctx->r8 & ctx->r16;
    // 0x8001C508: ori         $t7, $t8, 0x1
    ctx->r15 = ctx->r24 | 0X1;
    // 0x8001C50C: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8001C510: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8001C514: sw          $t9, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r25;
    // 0x8001C518: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001C51C: jr          $ra
    // 0x8001C520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001C520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sc1PStageClearGetAppendBonusStatPoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801331EC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801331F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801331F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801331F8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801331FC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80133200: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80133204: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80133208: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8013320C: addiu       $t7, $t7, 0x51D0
    ctx->r15 = ADD32(ctx->r15, 0X51D0);
    // 0x80133210: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133214: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80133218: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013321C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133220: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133224: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133228: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013322C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133230: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133234: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133238: addiu       $t1, $t1, 0x51E4
    ctx->r9 = ADD32(ctx->r9, 0X51E4);
    // 0x8013323C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133240: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80133244: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133248: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x8013324C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80133250: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133254: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x80133258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013325C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133260: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80133264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133268: jal         0x80009968
    // 0x8013326C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013326C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    after_0:
    // 0x80133270: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80133274: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133278: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013327C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133280: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80133284: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133288: sw          $v0, 0x5350($at)
    MEM_W(0X5350, ctx->r1) = ctx->r2;
    // 0x8013328C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133290: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133294: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80133298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013329C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801332A0: jal         0x80009DF4
    // 0x801332A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801332A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801332A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801332AC: addiu       $a1, $a1, 0x3188
    ctx->r5 = ADD32(ctx->r5, 0X3188);
    // 0x801332B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801332B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801332B8: jal         0x80008188
    // 0x801332BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801332BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801332C0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x801332C4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801332C8: lw          $t9, 0x52CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52CC);
    // 0x801332CC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801332D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801332D4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801332D8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x801332DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801332E0: bne         $s1, $at, L_8013332C
    if (ctx->r17 != ctx->r1) {
        // 0x801332E4: sw          $t0, 0x84($s0)
        MEM_W(0X84, ctx->r16) = ctx->r8;
            goto L_8013332C;
    }
    // 0x801332E4: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    // 0x801332E8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801332EC: lw          $t1, 0x52E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X52E4);
    // 0x801332F0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801332F4: lw          $t4, 0x5588($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5588);
    // 0x801332F8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801332FC: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x80133300: lw          $t3, 0x50($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50);
    // 0x80133304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133308: jal         0x800CCFDC
    // 0x8013330C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013330C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80133310: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133314: addiu       $t6, $t6, 0x4EFC
    ctx->r14 = ADD32(ctx->r14, 0X4EFC);
    // 0x80133318: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x8013331C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80133320: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80133324: b           L_8013335C
    // 0x80133328: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8013335C;
    // 0x80133328: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013332C:
    // 0x8013332C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133330: addiu       $t9, $t9, 0x4EFC
    ctx->r25 = ADD32(ctx->r25, 0X4EFC);
    // 0x80133334: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80133338: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8013333C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133340: lw          $t1, 0x5588($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5588);
    // 0x80133344: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80133348: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8013334C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133350: jal         0x800CCFDC
    // 0x80133354: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80133354: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x80133358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013335C:
    // 0x8013335C: lhu         $t2, 0x24($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X24);
    // 0x80133360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133364: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80133368: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x8013336C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80133370: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x80133374: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80133378: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x8013337C: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80133380: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80133384: jal         0x801330F0
    // 0x80133388: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    sc1PStageClearCheckGameClearBonus(rdram, ctx);
        goto after_5;
    // 0x80133388: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    after_5:
    // 0x8013338C: beq         $v0, $zero, L_801333A8
    if (ctx->r2 == 0) {
        // 0x80133390: lw          $v1, 0x68($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X68);
            goto L_801333A8;
    }
    // 0x80133390: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80133394: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80133398: sb          $t6, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r14;
    // 0x8013339C: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    // 0x801333A0: b           L_801333BC
    // 0x801333A4: sb          $zero, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = 0;
        goto L_801333BC;
    // 0x801333A4: sb          $zero, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = 0;
L_801333A8:
    // 0x801333A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801333AC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801333B0: sb          $t7, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r15;
    // 0x801333B4: sb          $t8, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r24;
    // 0x801333B8: sb          $zero, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = 0;
L_801333BC:
    // 0x801333BC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801333C0: bne         $s1, $at, L_80133488
    if (ctx->r17 != ctx->r1) {
        // 0x801333C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80133488;
    }
    // 0x801333C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801333C8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801333CC: lw          $t9, 0x5598($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5598);
    // 0x801333D0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801333D4: addiu       $t0, $t0, 0x828
    ctx->r8 = ADD32(ctx->r8, 0X828);
    // 0x801333D8: jal         0x800CCFDC
    // 0x801333DC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x801333DC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_6:
    // 0x801333E0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801333E4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801333E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801333EC: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801333F0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801333F4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801333F8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801333FC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80133400: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133404: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133408: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013340C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80133410: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133414: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80133418: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8013341C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80133420: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80133424: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80133428: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013342C: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80133430: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80133434: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80133438: jal         0x80133128
    // 0x8013343C: lw          $a0, 0x52EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52EC);
    sc1PStageClearGetNoMissMultiplier(rdram, ctx);
        goto after_7;
    // 0x8013343C: lw          $a0, 0x52EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52EC);
    after_7:
    // 0x80133440: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80133444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133448: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013344C: addiu       $t5, $sp, 0x48
    ctx->r13 = ADD32(ctx->r29, 0X48);
    // 0x80133450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133454: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80133458: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8013345C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80133460: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133464: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80133468: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8013346C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133470: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133474: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80133478: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8013347C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80133480: jal         0x80131E10
    // 0x80133484: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_8;
    // 0x80133484: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_8:
L_80133488:
    // 0x80133488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013348C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133490: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80133494: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133498: lw          $t8, 0x5598($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5598);
    // 0x8013349C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801334A0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801334A4: addiu       $t9, $t9, 0x8D8
    ctx->r25 = ADD32(ctx->r25, 0X8D8);
    // 0x801334A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801334AC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801334B0: jal         0x800CCFDC
    // 0x801334B4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x801334B4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x801334B8: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801334BC: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x801334C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801334C4: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x801334C8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801334CC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801334D0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801334D4: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x801334D8: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801334DC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801334E0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801334E4: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801334E8: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801334EC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801334F0: beq         $s1, $at, L_8013350C
    if (ctx->r17 == ctx->r1) {
        // 0x801334F4: swc1        $f4, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
            goto L_8013350C;
    }
    // 0x801334F4: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x801334F8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x801334FC: beq         $s1, $at, L_80133530
    if (ctx->r17 == ctx->r1) {
        // 0x80133500: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_80133530;
    }
    // 0x80133500: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80133504: b           L_80133550
    // 0x80133508: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
        goto L_80133550;
    // 0x80133508: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_8013350C:
    // 0x8013350C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133510: jal         0x80133128
    // 0x80133514: lw          $a0, 0x52EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52EC);
    sc1PStageClearGetNoMissMultiplier(rdram, ctx);
        goto after_10;
    // 0x80133514: lw          $a0, 0x52EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52EC);
    after_10:
    // 0x80133518: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8013351C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80133520: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133524: mflo        $a1
    ctx->r5 = lo;
    // 0x80133528: b           L_80133558
    // 0x8013352C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80133558;
    // 0x8013352C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80133530:
    // 0x80133530: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133534: lw          $t8, 0x52E4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X52E4);
    // 0x80133538: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013353C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80133540: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133544: mflo        $a1
    ctx->r5 = lo;
    // 0x80133548: b           L_80133558
    // 0x8013354C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80133558;
    // 0x8013354C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80133550:
    // 0x80133550: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80133554: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80133558:
    // 0x80133558: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8013355C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80133560: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80133564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133568: lui         $a2, 0x4371
    ctx->r6 = S32(0X4371 << 16);
    // 0x8013356C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80133570: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80133574: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133578: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8013357C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133580: jal         0x80131E10
    // 0x80133584: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_11;
    // 0x80133584: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_11:
    // 0x80133588: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8013358C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80133590: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80133594: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80133598: jr          $ra
    // 0x8013359C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8013359C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void itKamexWeaponHydroProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180E6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180E74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80180E78: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80180E7C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80180E80: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80180E84: jal         0x801680EC
    // 0x80180E88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80180E88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80180E8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80180E90: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80180E94: jal         0x8001863C
    // 0x80180E98: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80180E98: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x80180E9C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80180EA0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80180EA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80180EA8: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80180EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80180EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180EB4: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80180EB8: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80180EBC: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80180EC0: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x80180EC4: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80180EC8: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x80180ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180ED4: jr          $ra
    // 0x80180ED8: nop

    return;
    // 0x80180ED8: nop

;}
RECOMP_FUNC void mnScreenAdjustFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326CC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801326D0: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801326D4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801326D8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801326DC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801326E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801326E4: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801326E8: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801326EC: addiu       $t8, $t8, 0x2978
    ctx->r24 = ADD32(ctx->r24, 0X2978);
    // 0x801326F0: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x801326F4: addiu       $t0, $t0, 0x2940
    ctx->r8 = ADD32(ctx->r8, 0X2940);
    // 0x801326F8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801326FC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80132700: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80132704: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132708: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8013270C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132710: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132714: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80132718: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8013271C: jal         0x800CDF78
    // 0x80132720: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132720: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132724: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132728: addiu       $a0, $a0, 0x2830
    ctx->r4 = ADD32(ctx->r4, 0X2830);
    // 0x8013272C: jal         0x800CDEEC
    // 0x80132730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80132734: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132738: jal         0x80004980
    // 0x8013273C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8013273C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132740: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132744: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132748: addiu       $a2, $a2, 0x2A38
    ctx->r6 = ADD32(ctx->r6, 0X2A38);
    // 0x8013274C: addiu       $a0, $a0, 0x2830
    ctx->r4 = ADD32(ctx->r4, 0X2830);
    // 0x80132750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132754: jal         0x800CDE04
    // 0x80132758: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132758: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8013275C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132760: addiu       $a1, $a1, 0x209C
    ctx->r5 = ADD32(ctx->r5, 0X209C);
    // 0x80132764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013276C: jal         0x80009968
    // 0x80132770: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132770: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132774: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132778: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8013277C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132780: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132784: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132788: jal         0x8000B9FC
    // 0x8013278C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013278C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80132790: jal         0x80131FF8
    // 0x80132794: nop

    mnScreenAdjustInitVars(rdram, ctx);
        goto after_6;
    // 0x80132794: nop

    after_6:
    // 0x80132798: jal         0x80131E74
    // 0x8013279C: nop

    mnScreenAdjustMakeFrameCamera(rdram, ctx);
        goto after_7;
    // 0x8013279C: nop

    after_7:
    // 0x801327A0: jal         0x80131F14
    // 0x801327A4: nop

    mnScreenAdjustMakeSpriteCamera(rdram, ctx);
        goto after_8;
    // 0x801327A4: nop

    after_8:
    // 0x801327A8: jal         0x80131D4C
    // 0x801327AC: nop

    mnScreenAdjustMakeGuide(rdram, ctx);
        goto after_9;
    // 0x801327AC: nop

    after_9:
    // 0x801327B0: jal         0x80131D00
    // 0x801327B4: nop

    mnScreenAdjustMakeFrame(rdram, ctx);
        goto after_10;
    // 0x801327B4: nop

    after_10:
    // 0x801327B8: jal         0x80131DCC
    // 0x801327BC: nop

    mnScreenAdjustMakeInstruction(rdram, ctx);
        goto after_11;
    // 0x801327BC: nop

    after_11:
    // 0x801327C0: jal         0x80020A74
    // 0x801327C4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_12;
    // 0x801327C4: nop

    after_12:
    // 0x801327C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801327CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801327D0: jr          $ra
    // 0x801327D4: nop

    return;
    // 0x801327D4: nop

;}
RECOMP_FUNC void mnPlayersVSMakePortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801326E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801326E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801326E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801326EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801326F0: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_801326F4:
    // 0x801326F4: jal         0x80132520
    // 0x801326F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakePortrait(rdram, ctx);
        goto after_0;
    // 0x801326F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801326FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132700: bne         $s0, $s1, L_801326F4
    if (ctx->r16 != ctx->r17) {
        // 0x80132704: nop
    
            goto L_801326F4;
    }
    // 0x80132704: nop

    // 0x80132708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013270C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80132710: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80132714: jr          $ra
    // 0x80132718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void alHeapDBAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E5F4: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8001E5F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001E5FC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001E600: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001E604: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8001E608: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001E60C: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x8001E610: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8001E614: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E618: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E61C: mflo        $v0
    ctx->r2 = lo;
    // 0x8001E620: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x8001E624: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x8001E628: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x8001E62C: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8001E630: bne         $at, $zero, L_8001E640
    if (ctx->r1 != 0) {
        // 0x8001E634: addu        $t1, $a0, $v0
        ctx->r9 = ADD32(ctx->r4, ctx->r2);
            goto L_8001E640;
    }
    // 0x8001E634: addu        $t1, $a0, $v0
    ctx->r9 = ADD32(ctx->r4, ctx->r2);
    // 0x8001E638: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001E63C: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
L_8001E640:
    // 0x8001E640: jr          $ra
    // 0x8001E644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001E644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnNoControllerStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6604: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D6608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D660C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6610: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x800D6614: addiu       $a0, $a0, 0x6700
    ctx->r4 = ADD32(ctx->r4, 0X6700);
    // 0x800D6618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D661C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x800D6620: jal         0x80007024
    // 0x800D6624: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x800D6624: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x800D6628: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x800D662C: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D6630: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6634: addiu       $t9, $t9, 0x6B30
    ctx->r25 = ADD32(ctx->r25, 0X6B30);
    // 0x800D6638: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x800D663C: addiu       $a0, $a0, 0x671C
    ctx->r4 = ADD32(ctx->r4, 0X671C);
    // 0x800D6640: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6644: jal         0x8000683C
    // 0x800D6648: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x800D6648: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x800D664C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6654: jr          $ra
    // 0x800D6658: nop

    return;
    // 0x800D6658: nop

;}
RECOMP_FUNC void mnVSItemSwitchFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133090: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133094: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80133098: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013309C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801330A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801330A4: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801330A8: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801330AC: addiu       $t8, $t8, 0x3470
    ctx->r24 = ADD32(ctx->r24, 0X3470);
    // 0x801330B0: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x801330B4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801330B8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801330BC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801330C0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801330C4: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x801330C8: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801330CC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801330D0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801330D4: jal         0x800CDF78
    // 0x801330D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801330D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801330DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801330E0: addiu       $a0, $a0, 0x3250
    ctx->r4 = ADD32(ctx->r4, 0X3250);
    // 0x801330E4: jal         0x800CDEEC
    // 0x801330E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801330E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801330EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801330F0: jal         0x80004980
    // 0x801330F4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801330F4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801330F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801330FC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133100: addiu       $a2, $a2, 0x3530
    ctx->r6 = ADD32(ctx->r6, 0X3530);
    // 0x80133104: addiu       $a0, $a0, 0x3250
    ctx->r4 = ADD32(ctx->r4, 0X3250);
    // 0x80133108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013310C: jal         0x800CDE04
    // 0x80133110: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80133110: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80133114: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133118: addiu       $a1, $a1, 0x2AF0
    ctx->r5 = ADD32(ctx->r5, 0X2AF0);
    // 0x8013311C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133124: jal         0x80009968
    // 0x80133128: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80133128: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x8013312C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80133130: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80133134: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133138: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8013313C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80133140: jal         0x8000B9FC
    // 0x80133144: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80133144: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80133148: jal         0x80132948
    // 0x8013314C: nop

    mnVSItemSwitchInitVars(rdram, ctx);
        goto after_6;
    // 0x8013314C: nop

    after_6:
    // 0x80133150: jal         0x80132468
    // 0x80133154: nop

    mnVSItemSwitchMakeCursorCamera(rdram, ctx);
        goto after_7;
    // 0x80133154: nop

    after_7:
    // 0x80133158: jal         0x80132508
    // 0x8013315C: nop

    mnVSItemSwitchMakeLabelsCamera(rdram, ctx);
        goto after_8;
    // 0x8013315C: nop

    after_8:
    // 0x80133160: jal         0x801325B0
    // 0x80133164: nop

    mnVSItemSwitchMakeDecalCamera(rdram, ctx);
        goto after_9;
    // 0x80133164: nop

    after_9:
    // 0x80133168: jal         0x80131DE8
    // 0x8013316C: nop

    mnVSItemSwitchMakeLabels(rdram, ctx);
        goto after_10;
    // 0x8013316C: nop

    after_10:
    // 0x80133170: jal         0x80131FDC
    // 0x80133174: nop

    mnVSItemSwitchMakeDecal(rdram, ctx);
        goto after_11;
    // 0x80133174: nop

    after_11:
    // 0x80133178: jal         0x80132084
    // 0x8013317C: nop

    mnVSItemSwitchMakeItemList(rdram, ctx);
        goto after_12;
    // 0x8013317C: nop

    after_12:
    // 0x80133180: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133184: jal         0x80132178
    // 0x80133188: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnVSItemSwitchMakeCursor(rdram, ctx);
        goto after_13;
    // 0x80133188: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_13:
    // 0x8013318C: jal         0x80132368
    // 0x80133190: nop

    mnVSItemSwitchInitToggles(rdram, ctx);
        goto after_14;
    // 0x80133190: nop

    after_14:
    // 0x80133194: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133198: jal         0x80131F30
    // 0x8013319C: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    mnItemSwitchMakeSubtitle(rdram, ctx);
        goto after_15;
    // 0x8013319C: lw          $a0, 0x33D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X33D8);
    after_15:
    // 0x801331A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801331A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801331A8: jr          $ra
    // 0x801331AC: nop

    return;
    // 0x801331AC: nop

;}
RECOMP_FUNC void wpNessPKFireProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016AA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AA90: jal         0x80167C04
    // 0x8016AA94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016AA94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016AA98: beq         $v0, $zero, L_8016AAB8
    if (ctx->r2 == 0) {
        // 0x8016AA9C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8016AAB8;
    }
    // 0x8016AA9C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016AAA0: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016AAA4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016AAA8: jal         0x800FF648
    // 0x8016AAAC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016AAAC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016AAB0: b           L_8016AABC
    // 0x8016AAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016AABC;
    // 0x8016AAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016AAB8:
    // 0x8016AAB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016AABC:
    // 0x8016AABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AAC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016AAC4: jr          $ra
    // 0x8016AAC8: nop

    return;
    // 0x8016AAC8: nop

;}
RECOMP_FUNC void itRShellHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017AAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AAC4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017AAC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017AACC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017AAD0: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017AAD4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8017AAD8: jal         0x80172EC8
    // 0x8017AADC: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017AADC: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x8017AAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AAE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017AAE8: jr          $ra
    // 0x8017AAEC: nop

    return;
    // 0x8017AAEC: nop

;}
RECOMP_FUNC void syMatrixPerspFast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B474: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001B478: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B47C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001B480: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001B484: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B488: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001B48C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001B490: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001B494: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001B498: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001B49C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B4A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001B4A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001B4A8: jal         0x8001B248
    // 0x8001B4AC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_0;
    // 0x8001B4AC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8001B4B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001B4B4: jal         0x80019C70
    // 0x8001B4B8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001B4B8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001B4BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001B4C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001B4C4: jr          $ra
    // 0x8001B4C8: nop

    return;
    // 0x8001B4C8: nop

;}
RECOMP_FUNC void mnVSRecordMakeTableValuesCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801359EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801359F0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801359F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801359F8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801359FC: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80135A00: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135A04: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80135A08: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135A0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135A10: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135A14: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135A18: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135A1C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135A20: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135A24: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135A28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135A2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135A30: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135A34: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135A38: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135A3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80135A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135A44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135A48: jal         0x8000B93C
    // 0x80135A4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135A4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135A50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135A54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135A58: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135A5C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135A60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135A64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135A68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135A6C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135A70: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135A74: jal         0x80007080
    // 0x80135A78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135A78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135A7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135A80: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135A84: jr          $ra
    // 0x80135A88: nop

    return;
    // 0x80135A88: nop

;}
RECOMP_FUNC void dbMapsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D65AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D65B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D65B4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D65B8: addiu       $a1, $a1, 0x64A0
    ctx->r5 = ADD32(ctx->r5, 0X64A0);
    // 0x800D65BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D65C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D65C4: jal         0x80009968
    // 0x800D65C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D65C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D65CC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800D65D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D65D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D65D8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800D65DC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800D65E0: jal         0x8000B9FC
    // 0x800D65E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x800D65E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x800D65E8: jal         0x80369EE0
    // 0x800D65EC: nop

    dbMenuInitMenu(rdram, ctx);
        goto after_2;
    // 0x800D65EC: nop

    after_2:
    // 0x800D65F0: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800D65F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800D65F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D65FC: addiu       $a3, $a3, 0x672C
    ctx->r7 = ADD32(ctx->r7, 0X672C);
    // 0x800D6600: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800D6604: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800D6608: jal         0x80369D78
    // 0x800D660C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    dbMenuMakeMenu(rdram, ctx);
        goto after_3;
    // 0x800D660C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_3:
    // 0x800D6610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6614: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D6618: jr          $ra
    // 0x800D661C: nop

    return;
    // 0x800D661C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusUpdateCursorGrabPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134BB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134BB4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134BBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80134BC0: addiu       $t6, $t6, 0x7474
    ctx->r14 = ADD32(ctx->r14, 0X7474);
    // 0x80134BC4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134BC8: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80134BCC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80134BD0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80134BD4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80134BD8: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80134BDC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80134BE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80134BE4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80134BE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134BEC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80134BF0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80134BF4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80134BF8: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80134BFC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80134C00: lw          $a0, 0x764C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X764C);
    // 0x80134C04: jal         0x8000A0D0
    // 0x80134C08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80134C08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_0:
    // 0x80134C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134C10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80134C14: jr          $ra
    // 0x80134C18: nop

    return;
    // 0x80134C18: nop

;}
RECOMP_FUNC void scAutoDemoExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D5F4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D5F8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8018D5FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D604: addiu       $t7, $zero, 0x1B
    ctx->r15 = ADD32(0, 0X1B);
    // 0x8018D608: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8018D60C: jal         0x80005C74
    // 0x8018D610: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x8018D610: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_0:
    // 0x8018D614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D61C: jr          $ra
    // 0x8018D620: nop

    return;
    // 0x8018D620: nop

;}
RECOMP_FUNC void mvOpeningSamusSetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, -0x1D28
    ctx->r24 = ADD32(ctx->r24, -0X1D28);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1BA8
    ctx->r8 = ADD32(ctx->r8, -0X1BA8);
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
    // 0x8018D11C: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
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
    // 0x8018D13C: addiu       $a2, $a2, -0x1B70
    ctx->r6 = ADD32(ctx->r6, -0X1B70);
    // 0x8018D140: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
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
RECOMP_FUNC void sc1PGameBossAddBossInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F57C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018F580: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8018F584: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018F588: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8018F58C: bnel        $t6, $at, L_8018F5A0
    if (ctx->r14 != ctx->r1) {
        // 0x8018F590: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018F5A0;
    }
    goto skip_0;
    // 0x8018F590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018F594: jal         0x80114968
    // 0x8018F598: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ifCommonPlayerStockMakeStockSnap(rdram, ctx);
        goto after_0;
    // 0x8018F598: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8018F59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F5A0:
    // 0x8018F5A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F5A4: jr          $ra
    // 0x8018F5A8: nop

    return;
    // 0x8018F5A8: nop

;}
RECOMP_FUNC void gcAddDObjForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800092D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800092D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800092D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800092DC: bne         $a0, $zero, L_800092EC
    if (ctx->r4 != 0) {
        // 0x800092E0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800092EC;
    }
    // 0x800092E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800092E4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800092E8: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
L_800092EC:
    // 0x800092EC: jal         0x80007F84
    // 0x800092F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcGetDObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x800092F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800092F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800092F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800092FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80009300: lw          $a3, 0x74($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X74);
    // 0x80009304: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80009308: beql        $a3, $zero, L_80009340
    if (ctx->r7 == 0) {
        // 0x8000930C: sb          $t6, 0xF($a2)
        MEM_B(0XF, ctx->r6) = ctx->r14;
            goto L_80009340;
    }
    goto skip_0;
    // 0x8000930C: sb          $t6, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r14;
    skip_0:
    // 0x80009310: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x80009314: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80009318: beql        $v1, $zero, L_80009334
    if (ctx->r3 == 0) {
        // 0x8000931C: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_80009334;
    }
    goto skip_1;
    // 0x8000931C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    skip_1:
    // 0x80009320: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80009324:
    // 0x80009324: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80009328: bnel        $v1, $zero, L_80009324
    if (ctx->r3 != 0) {
        // 0x8000932C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80009324;
    }
    goto skip_2;
    // 0x8000932C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_2:
    // 0x80009330: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_80009334:
    // 0x80009334: b           L_80009348
    // 0x80009338: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80009348;
    // 0x80009338: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8000933C: sb          $t6, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r14;
L_80009340:
    // 0x80009340: sw          $v0, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r2;
    // 0x80009344: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_80009348:
    // 0x80009348: sw          $a2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r6;
    // 0x8000934C: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x80009350: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80009354: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80009358: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000935C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80009360: sw          $t8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->r24;
    // 0x80009364: jal         0x8000926C
    // 0x80009368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcInitDObj(rdram, ctx);
        goto after_1;
    // 0x80009368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8000936C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009370: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80009374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009378: jr          $ra
    // 0x8000937C: nop

    return;
    // 0x8000937C: nop

;}
RECOMP_FUNC void func_ovl8_8038185C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038185C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80381860: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80381864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80381868: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038186C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80381870: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80381874: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80381878: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8038187C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80381880: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80381884: jal         0x8037FF40
    // 0x80381888: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    func_ovl8_8037FF40(rdram, ctx);
        goto after_0;
    // 0x80381888: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8038188C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80381890: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80381894: jal         0x803716D8
    // 0x80381898: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_ovl8_803716D8(rdram, ctx);
        goto after_1;
    // 0x80381898: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8038189C: beq         $v0, $zero, L_803818F4
    if (ctx->r2 == 0) {
        // 0x803818A0: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_803818F4;
    }
    // 0x803818A0: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x803818A4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x803818A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x803818AC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x803818B0: beql        $a0, $zero, L_803818F8
    if (ctx->r4 == 0) {
        // 0x803818B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_803818F8;
    }
    goto skip_0;
    // 0x803818B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803818B8: blez        $a0, L_803818E8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x803818BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_803818E8;
    }
    // 0x803818BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x803818C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x803818C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_803818C8:
    // 0x803818C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x803818CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x803818D0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x803818D4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x803818D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x803818DC: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x803818E0: bnel        $at, $zero, L_803818C8
    if (ctx->r1 != 0) {
        // 0x803818E4: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_803818C8;
    }
    goto skip_1;
    // 0x803818E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_803818E8:
    // 0x803818E8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x803818EC: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x803818F0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_803818F4:
    // 0x803818F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803818F8:
    // 0x803818F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803818FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80381900: jr          $ra
    // 0x80381904: nop

    return;
    // 0x80381904: nop

;}
RECOMP_FUNC void mnDataMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132714: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132718: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013271C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132720: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132724: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80132728: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013272C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132730: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132734: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132738: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013273C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132740: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132744: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132748: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013274C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132750: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132758: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013275C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132760: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132764: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013276C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132770: jal         0x8000B93C
    // 0x80132774: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132774: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132778: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013277C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132780: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132784: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132788: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013278C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132790: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132794: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132798: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013279C: jal         0x80007080
    // 0x801327A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801327A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801327A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801327A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801327AC: jr          $ra
    // 0x801327B0: nop

    return;
    // 0x801327B0: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105BE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105BEC: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105BF0: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x80105BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105BFC: beq         $v0, $zero, L_80105C0C
    if (ctx->r2 == 0) {
        // 0x80105C00: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80105C0C;
    }
    // 0x80105C00: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80105C04: b           L_80105C60
    // 0x80105C08: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
        goto L_80105C60;
    // 0x80105C08: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
L_80105C0C:
    // 0x80105C0C: jal         0x801058E0
    // 0x80105C10: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    grPupupuWhispyGetLR(rdram, ctx);
        goto after_0;
    // 0x80105C10: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_0:
    // 0x80105C14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105C18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80105C1C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105C20: bne         $v0, $at, L_80105C2C
    if (ctx->r2 != ctx->r1) {
        // 0x80105C24: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80105C2C;
    }
    // 0x80105C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80105C28: lb          $a0, 0x2A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X2A);
L_80105C2C:
    // 0x80105C2C: lb          $t7, 0x2A($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X2A);
    // 0x80105C30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80105C34: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80105C38: beq         $a0, $t7, L_80105C58
    if (ctx->r4 == ctx->r15) {
        // 0x80105C3C: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80105C58;
    }
    // 0x80105C3C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80105C40: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80105C44: sb          $zero, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = 0;
    // 0x80105C48: sb          $t8, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r24;
    // 0x80105C4C: sb          $t9, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r25;
    // 0x80105C50: b           L_80105C60
    // 0x80105C54: sb          $a0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r4;
        goto L_80105C60;
    // 0x80105C54: sb          $a0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r4;
L_80105C58:
    // 0x80105C58: sb          $t0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r8;
    // 0x80105C5C: sb          $t1, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r9;
L_80105C60:
    // 0x80105C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105C68: jr          $ra
    // 0x80105C6C: nop

    return;
    // 0x80105C6C: nop

;}
RECOMP_FUNC void ftBossDeadLeftSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AD74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015AD78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015AD7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015AD80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015AD84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015AD88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015AD8C: addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
    // 0x8015AD90: jal         0x800E6F24
    // 0x8015AD94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AD94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015AD98: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8015AD9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015ADA0: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015ADA4: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x8015ADA8: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x8015ADAC: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8015ADB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015ADB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015ADB8: jr          $ra
    // 0x8015ADBC: nop

    return;
    // 0x8015ADBC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePortraitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132C18: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132C1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132C20: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132C24: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132C28: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132C2C: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80132C30: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132C34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132C38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132C3C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132C40: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132C44: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132C48: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132C4C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132C50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132C54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132C58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132C5C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132C60: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132C64: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C6C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132C70: jal         0x8000B93C
    // 0x80132C74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132C74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132C78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132C7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132C80: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132C84: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132C8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132C90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132C94: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132C98: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132C9C: jal         0x80007080
    // 0x80132CA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132CA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132CA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132CA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132CAC: jr          $ra
    // 0x80132CB0: nop

    return;
    // 0x80132CB0: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeBonus2Ground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DAE8: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8018DAEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DAF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DAF4: jal         0x80009968
    // 0x8018DAF8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DAF8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DAFC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB00: addiu       $a1, $a1, -0x25D4
    ctx->r5 = ADD32(ctx->r5, -0X25D4);
    // 0x8018DB04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DB08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB0C: jal         0x80008188
    // 0x8018DB10: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8018DB10: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8018DB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DB18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DB1C: jr          $ra
    // 0x8018DB20: nop

    return;
    // 0x8018DB20: nop

;}
RECOMP_FUNC void itMewCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EDA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EDA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EDAC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017EDB0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8017EDB4: jal         0x801737B8
    // 0x8017EDB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017EDB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017EDBC: beq         $v0, $zero, L_8017EDD0
    if (ctx->r2 == 0) {
        // 0x8017EDC0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8017EDD0;
    }
    // 0x8017EDC0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EDC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017EDC8: nop

    // 0x8017EDCC: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8017EDD0:
    // 0x8017EDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EDD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017EDD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017EDDC: jr          $ra
    // 0x8017EDE0: nop

    return;
    // 0x8017EDE0: nop

;}
RECOMP_FUNC void ftKirbySpecialHiUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160BB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80160BBC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160BC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80160BC4: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
    // 0x80160BC8: beql        $a1, $zero, L_80160C1C
    if (ctx->r5 == 0) {
        // 0x80160BCC: lw          $a1, 0x184($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X184);
            goto L_80160C1C;
    }
    goto skip_0;
    // 0x80160BCC: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x80160BD0: bne         $a1, $at, L_80160BFC
    if (ctx->r5 != ctx->r1) {
        // 0x80160BD4: nop
    
            goto L_80160BFC;
    }
    // 0x80160BD4: nop

    // 0x80160BD8: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x80160BDC: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x80160BE0: bgezl       $t8, L_80160C1C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80160BE4: lw          $a1, 0x184($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X184);
            goto L_80160C1C;
    }
    goto skip_1;
    // 0x80160BE4: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    skip_1:
    // 0x80160BE8: jal         0x800E9C3C
    // 0x80160BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftParamProcStopEffect(rdram, ctx);
        goto after_0;
    // 0x80160BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160BF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80160BF4: b           L_80160C18
    // 0x80160BF8: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
        goto L_80160C18;
    // 0x80160BF8: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80160BFC:
    // 0x80160BFC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80160C00: jal         0x80023624
    // 0x80160C04: addiu       $a0, $a0, -0x36D0
    ctx->r4 = ADD32(ctx->r4, -0X36D0);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80160C04: addiu       $a0, $a0, -0x36D0
    ctx->r4 = ADD32(ctx->r4, -0X36D0);
    after_1:
    // 0x80160C08: jal         0x800A3040
    // 0x80160C0C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x80160C0C: nop

    after_2:
    // 0x80160C10: b           L_80160BFC
    // 0x80160C14: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
        goto L_80160BFC;
    // 0x80160C14: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
L_80160C18:
    // 0x80160C18: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
L_80160C1C:
    // 0x80160C1C: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x80160C20: beq         $at, $zero, L_80160CEC
    if (ctx->r1 == 0) {
        // 0x80160C24: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80160CEC;
    }
    // 0x80160C24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80160C28: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80160C2C: addu        $at, $at, $t9
    gpr jr_addend_80160C34 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80160C30: lw          $t9, -0x3658($at)
    ctx->r25 = ADD32(ctx->r1, -0X3658);
    // 0x80160C34: jr          $t9
    // 0x80160C38: nop

    switch (jr_addend_80160C34 >> 2) {
        case 0: goto L_80160D08; break;
        case 1: goto L_80160C3C; break;
        case 2: goto L_80160C5C; break;
        case 3: goto L_80160C80; break;
        case 4: goto L_80160CA4; break;
        case 5: goto L_80160CC8; break;
        default: switch_error(__func__, 0x80160C34, 0x8018C9A8);
    }
    // 0x80160C38: nop

L_80160C3C:
    // 0x80160C3C: lw          $t0, 0x18C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18C);
    // 0x80160C40: sll         $t2, $t0, 27
    ctx->r10 = S32(ctx->r8 << 27);
    // 0x80160C44: bgezl       $t2, L_80160D0C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80160C48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80160D0C;
    }
    goto skip_2;
    // 0x80160C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80160C4C: jal         0x800E9C3C
    // 0x80160C50: nop

    ftParamProcStopEffect(rdram, ctx);
        goto after_3;
    // 0x80160C50: nop

    after_3:
    // 0x80160C54: b           L_80160D08
    // 0x80160C58: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
        goto L_80160D08;
    // 0x80160C58: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
L_80160C5C:
    // 0x80160C5C: jal         0x80102508
    // 0x80160C60: nop

    efManagerKirbyCutterDrawMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80160C60: nop

    after_4:
    // 0x80160C64: beql        $v0, $zero, L_80160D0C
    if (ctx->r2 == 0) {
        // 0x80160C68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80160D0C;
    }
    goto skip_3;
    // 0x80160C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80160C6C: lbu         $t4, 0x18F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18F);
    // 0x80160C70: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80160C74: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80160C78: b           L_80160D08
    // 0x80160C7C: sb          $t5, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r13;
        goto L_80160D08;
    // 0x80160C7C: sb          $t5, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r13;
L_80160C80:
    // 0x80160C80: jal         0x80102418
    // 0x80160C84: nop

    efManagerKirbyCutterUpMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80160C84: nop

    after_5:
    // 0x80160C88: beql        $v0, $zero, L_80160D0C
    if (ctx->r2 == 0) {
        // 0x80160C8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80160D0C;
    }
    goto skip_4;
    // 0x80160C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80160C90: lbu         $t7, 0x18F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18F);
    // 0x80160C94: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80160C98: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80160C9C: b           L_80160D08
    // 0x80160CA0: sb          $t8, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r24;
        goto L_80160D08;
    // 0x80160CA0: sb          $t8, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r24;
L_80160CA4:
    // 0x80160CA4: jal         0x80102490
    // 0x80160CA8: nop

    efManagerKirbyCutterDownMakeEffect(rdram, ctx);
        goto after_6;
    // 0x80160CA8: nop

    after_6:
    // 0x80160CAC: beql        $v0, $zero, L_80160D0C
    if (ctx->r2 == 0) {
        // 0x80160CB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80160D0C;
    }
    goto skip_5;
    // 0x80160CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80160CB4: lbu         $t0, 0x18F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18F);
    // 0x80160CB8: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80160CBC: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80160CC0: b           L_80160D08
    // 0x80160CC4: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
        goto L_80160D08;
    // 0x80160CC4: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
L_80160CC8:
    // 0x80160CC8: jal         0x80102560
    // 0x80160CCC: nop

    efManagerKirbyCutterTrailMakeEffect(rdram, ctx);
        goto after_7;
    // 0x80160CCC: nop

    after_7:
    // 0x80160CD0: beql        $v0, $zero, L_80160D0C
    if (ctx->r2 == 0) {
        // 0x80160CD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80160D0C;
    }
    goto skip_6;
    // 0x80160CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80160CD8: lbu         $t3, 0x18F($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18F);
    // 0x80160CDC: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80160CE0: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80160CE4: b           L_80160D08
    // 0x80160CE8: sb          $t4, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r12;
        goto L_80160D08;
    // 0x80160CE8: sb          $t4, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r12;
L_80160CEC:
    // 0x80160CEC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80160CF0: jal         0x80023624
    // 0x80160CF4: addiu       $a0, $a0, -0x3694
    ctx->r4 = ADD32(ctx->r4, -0X3694);
    syDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x80160CF4: addiu       $a0, $a0, -0x3694
    ctx->r4 = ADD32(ctx->r4, -0X3694);
    after_8:
    // 0x80160CF8: jal         0x800A3040
    // 0x80160CFC: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_9;
    // 0x80160CFC: nop

    after_9:
    // 0x80160D00: b           L_80160CEC
    // 0x80160D04: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
        goto L_80160CEC;
    // 0x80160D04: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
L_80160D08:
    // 0x80160D08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80160D0C:
    // 0x80160D0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80160D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80160D14: jr          $ra
    // 0x80160D18: nop

    return;
    // 0x80160D18: nop

;}
RECOMP_FUNC void wpMarioFireballProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801686C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801686C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801686C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801686CC: jal         0x800269C0
    // 0x801686D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801686D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801686D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801686D8: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x801686DC: jal         0x80100480
    // 0x801686E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801686E0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801686E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801686E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801686EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801686F0: jr          $ra
    // 0x801686F4: nop

    return;
    // 0x801686F4: nop

;}
RECOMP_FUNC void mnVSOptionsMakeItemSwitchOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801326F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801326F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801326FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132700: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132704: jal         0x80009968
    // 0x80132708: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132708: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013270C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132710: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132714: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132718: sw          $v0, 0x48D0($at)
    MEM_W(0X48D0, ctx->r1) = ctx->r2;
    // 0x8013271C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132720: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132724: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013272C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132730: jal         0x80009DF4
    // 0x80132734: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132734: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132738: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013273C: lw          $t7, 0x49DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49DC);
    // 0x80132740: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132744: addiu       $t8, $t8, 0x33D8
    ctx->r24 = ADD32(ctx->r24, 0X33D8);
    // 0x80132748: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013274C: jal         0x800CCFDC
    // 0x80132750: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132750: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132754: addiu       $t3, $zero, 0xB1
    ctx->r11 = ADD32(0, 0XB1);
    // 0x80132758: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8013275C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132760: lui         $at, 0x42A4
    ctx->r1 = S32(0X42A4 << 16);
    // 0x80132764: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80132768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013276C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132770: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132774: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132778: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013277C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132780: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132784: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132788: lw          $a1, 0x48E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E0);
    // 0x8013278C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132790: xori        $a1, $a1, 0x4
    ctx->r5 = ctx->r5 ^ 0X4;
    // 0x80132794: jal         0x80131F74
    // 0x80132798: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132798: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x8013279C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801327A0: lw          $t4, 0x49DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49DC);
    // 0x801327A4: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x801327A8: addiu       $t5, $t5, 0x3FC8
    ctx->r13 = ADD32(ctx->r13, 0X3FC8);
    // 0x801327AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801327B0: jal         0x800CCFDC
    // 0x801327B4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801327B4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x801327B8: addiu       $t0, $zero, 0xB3
    ctx->r8 = ADD32(0, 0XB3);
    // 0x801327BC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801327C0: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x801327C4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801327C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801327CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801327D0: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x801327D4: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x801327D8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801327DC: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801327E0: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801327E4: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801327E8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801327EC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801327F0: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x801327F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801327F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801327FC: jr          $ra
    // 0x80132800: nop

    return;
    // 0x80132800: nop

;}

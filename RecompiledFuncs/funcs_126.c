#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034434: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80034438: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8003443C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80034440: beql        $t6, $v1, L_8003446C
    if (ctx->r14 == ctx->r3) {
        // 0x80034444: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003446C;
    }
    goto skip_0;
    // 0x80034444: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_80034448:
    // 0x80034448: bnel        $v1, $zero, L_8003445C
    if (ctx->r3 != 0) {
        // 0x8003444C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8003445C;
    }
    goto skip_1;
    // 0x8003444C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x80034450: jr          $ra
    // 0x80034454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80034454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034458: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8003445C:
    // 0x8003445C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034460: bne         $v0, $v1, L_80034448
    if (ctx->r2 != ctx->r3) {
        // 0x80034464: nop
    
            goto L_80034448;
    }
    // 0x80034464: nop

    // 0x80034468: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003446C:
    // 0x8003446C: jr          $ra
    // 0x80034470: nop

    return;
    // 0x80034470: nop

;}
RECOMP_FUNC void lbBackupClearVSRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D49E0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D49E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D49E8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800D49EC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800D49F0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800D49F4: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800D49F8: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800D49FC: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800D4A00: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D4A04: addiu       $v0, $v0, 0x3EF8
    ctx->r2 = ADD32(ctx->r2, 0X3EF8);
    // 0x800D4A08: addiu       $t2, $t2, 0x3AA8
    ctx->r10 = ADD32(ctx->r10, 0X3AA8);
    // 0x800D4A0C: addiu       $t1, $t1, 0x45F4
    ctx->r9 = ADD32(ctx->r9, 0X45F4);
    // 0x800D4A10: addiu       $t0, $t0, 0x3A4C
    ctx->r8 = ADD32(ctx->r8, 0X3A4C);
    // 0x800D4A14: addiu       $a3, $a3, 0x4598
    ctx->r7 = ADD32(ctx->r7, 0X4598);
    // 0x800D4A18: addiu       $a2, $a2, 0x39F0
    ctx->r6 = ADD32(ctx->r6, 0X39F0);
    // 0x800D4A1C: addiu       $a1, $a1, 0x453C
    ctx->r5 = ADD32(ctx->r5, 0X453C);
    // 0x800D4A20: addiu       $a0, $a0, 0x3994
    ctx->r4 = ADD32(ctx->r4, 0X3994);
    // 0x800D4A24: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
L_800D4A28:
    // 0x800D4A28: or          $t8, $a0, $zero
    ctx->r24 = ctx->r4 | 0;
    // 0x800D4A2C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x800D4A30: addiu       $t3, $a0, 0x54
    ctx->r11 = ADD32(ctx->r4, 0X54);
L_800D4A34:
    // 0x800D4A34: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800D4A38: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800D4A3C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800D4A40: sw          $t7, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r15;
    // 0x800D4A44: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x800D4A48: sw          $t6, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r14;
    // 0x800D4A4C: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x800D4A50: bne         $t8, $t3, L_800D4A34
    if (ctx->r24 != ctx->r11) {
        // 0x800D4A54: sw          $t7, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r15;
            goto L_800D4A34;
    }
    // 0x800D4A54: sw          $t7, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r15;
    // 0x800D4A58: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800D4A5C: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x800D4A60: addiu       $v1, $v1, 0x170
    ctx->r3 = ADD32(ctx->r3, 0X170);
    // 0x800D4A64: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800D4A68: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x800D4A6C: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x800D4A70: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    // 0x800D4A74: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800D4A78: addiu       $t9, $a2, 0x54
    ctx->r25 = ADD32(ctx->r6, 0X54);
L_800D4A7C:
    // 0x800D4A7C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800D4A80: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800D4A84: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800D4A88: sw          $t5, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r13;
    // 0x800D4A8C: lw          $t4, -0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X8);
    // 0x800D4A90: sw          $t4, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r12;
    // 0x800D4A94: lw          $t5, -0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, -0X4);
    // 0x800D4A98: bne         $t3, $t9, L_800D4A7C
    if (ctx->r11 != ctx->r25) {
        // 0x800D4A9C: sw          $t5, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r13;
            goto L_800D4A7C;
    }
    // 0x800D4A9C: sw          $t5, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r13;
    // 0x800D4AA0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800D4AA4: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
    // 0x800D4AA8: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x800D4AAC: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800D4AB0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800D4AB4: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800D4AB8: addiu       $a2, $a2, 0x170
    ctx->r6 = ADD32(ctx->r6, 0X170);
    // 0x800D4ABC: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800D4AC0: addiu       $t8, $t0, 0x54
    ctx->r24 = ADD32(ctx->r8, 0X54);
L_800D4AC4:
    // 0x800D4AC4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800D4AC8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800D4ACC: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800D4AD0: sw          $t7, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r15;
    // 0x800D4AD4: lw          $t6, -0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X8);
    // 0x800D4AD8: sw          $t6, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r14;
    // 0x800D4ADC: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800D4AE0: bne         $t9, $t8, L_800D4AC4
    if (ctx->r25 != ctx->r24) {
        // 0x800D4AE4: sw          $t7, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r15;
            goto L_800D4AC4;
    }
    // 0x800D4AE4: sw          $t7, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r15;
    // 0x800D4AE8: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800D4AEC: or          $t8, $t2, $zero
    ctx->r24 = ctx->r10 | 0;
    // 0x800D4AF0: addiu       $a3, $a3, 0x170
    ctx->r7 = ADD32(ctx->r7, 0X170);
    // 0x800D4AF4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x800D4AF8: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800D4AFC: or          $t9, $t1, $zero
    ctx->r25 = ctx->r9 | 0;
    // 0x800D4B00: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800D4B04: addiu       $t3, $t2, 0x54
    ctx->r11 = ADD32(ctx->r10, 0X54);
L_800D4B08:
    // 0x800D4B08: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x800D4B0C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800D4B10: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800D4B14: sw          $t5, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r13;
    // 0x800D4B18: lw          $t4, -0x8($t8)
    ctx->r12 = MEM_W(ctx->r24, -0X8);
    // 0x800D4B1C: sw          $t4, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r12;
    // 0x800D4B20: lw          $t5, -0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, -0X4);
    // 0x800D4B24: bne         $t8, $t3, L_800D4B08
    if (ctx->r24 != ctx->r11) {
        // 0x800D4B28: sw          $t5, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r13;
            goto L_800D4B08;
    }
    // 0x800D4B28: sw          $t5, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r13;
    // 0x800D4B2C: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x800D4B30: addiu       $t2, $t2, 0x170
    ctx->r10 = ADD32(ctx->r10, 0X170);
    // 0x800D4B34: addiu       $t0, $t0, 0x170
    ctx->r8 = ADD32(ctx->r8, 0X170);
    // 0x800D4B38: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800D4B3C: lw          $t4, 0x4($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X4);
    // 0x800D4B40: addiu       $t1, $t1, 0x170
    ctx->r9 = ADD32(ctx->r9, 0X170);
    // 0x800D4B44: bne         $t2, $v0, L_800D4A28
    if (ctx->r10 != ctx->r2) {
        // 0x800D4B48: sw          $t4, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r12;
            goto L_800D4A28;
    }
    // 0x800D4B48: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800D4B4C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D4B50: lhu         $t6, 0x3F74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X3F74);
    // 0x800D4B54: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4B58: jr          $ra
    // 0x800D4B5C: sh          $t6, 0x4AC0($at)
    MEM_H(0X4AC0, ctx->r1) = ctx->r14;
    return;
    // 0x800D4B5C: sh          $t6, 0x4AC0($at)
    MEM_H(0X4AC0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void ftFoxSpecialAirHiSetStatusFromGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C60C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015C610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015C614: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015C618: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015C61C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015C620: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015C624: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8015C628: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
    // 0x8015C62C: bgez        $v0, L_8015C63C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015C630: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8015C63C;
    }
    // 0x8015C630: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8015C634: b           L_8015C63C
    // 0x8015C638: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
        goto L_8015C63C;
    // 0x8015C638: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
L_8015C63C:
    // 0x8015C63C: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x8015C640: bgez        $a0, L_8015C650
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8015C644: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8015C650;
    }
    // 0x8015C644: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8015C648: b           L_8015C650
    // 0x8015C64C: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
        goto L_8015C650;
    // 0x8015C64C: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
L_8015C650:
    // 0x8015C650: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x8015C654: slti        $at, $t8, 0x2D
    ctx->r1 = SIGNED(ctx->r24) < 0X2D ? 1 : 0;
    // 0x8015C658: bne         $at, $zero, L_8015C6B4
    if (ctx->r1 != 0) {
        // 0x8015C65C: nop
    
            goto L_8015C6B4;
    }
    // 0x8015C65C: nop

    // 0x8015C660: bgez        $v0, L_8015C670
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015C664: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8015C670;
    }
    // 0x8015C664: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8015C668: b           L_8015C670
    // 0x8015C66C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8015C670;
    // 0x8015C66C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8015C670:
    // 0x8015C670: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8015C674: bnel        $at, $zero, L_8015C690
    if (ctx->r1 != 0) {
        // 0x8015C678: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_8015C690;
    }
    goto skip_0;
    // 0x8015C678: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x8015C67C: jal         0x800E8044
    // 0x8015C680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_0;
    // 0x8015C680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015C684: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
    // 0x8015C688: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x8015C68C: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
L_8015C690:
    // 0x8015C690: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8015C694: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8015C698: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015C69C: mflo        $t0
    ctx->r8 = lo;
    // 0x8015C6A0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8015C6A4: jal         0x8001863C
    // 0x8015C6A8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8015C6A8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x8015C6AC: b           L_8015C6C0
    // 0x8015C6B0: swc1        $f0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f0.u32l;
        goto L_8015C6C0;
    // 0x8015C6B0: swc1        $f0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f0.u32l;
L_8015C6B4:
    // 0x8015C6B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C6B8: lwc1        $f8, -0x3768($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3768);
    // 0x8015C6BC: swc1        $f8, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f8.u32l;
L_8015C6C0:
    // 0x8015C6C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8015C6C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8015C6C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015C6CC: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8015C6D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015C6D4: jal         0x800E6F24
    // 0x8015C6D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015C6D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8015C6DC: jal         0x8015C4C8
    // 0x8015C6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialHiInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015C6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015C6E4: jal         0x80035CD0
    // 0x8015C6E8: lwc1        $f12, 0xB20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB20);
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x8015C6E8: lwc1        $f12, 0xB20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB20);
    after_4:
    // 0x8015C6EC: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8015C6F0: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x8015C6F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8015C6F8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8015C6FC: lwc1        $f12, 0xB20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XB20);
    // 0x8015C700: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8015C704: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8015C708: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8015C70C: jal         0x800303F0
    // 0x8015C710: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8015C710: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x8015C714: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x8015C718: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015C71C: nop

    // 0x8015C720: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8015C724: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x8015C728: jal         0x8015C054
    // 0x8015C72C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftFoxSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_6;
    // 0x8015C72C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x8015C730: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8015C734: lw          $t4, 0x64($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X64);
    // 0x8015C738: sb          $t4, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r12;
    // 0x8015C73C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015C740: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015C744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015C748: jr          $ra
    // 0x8015C74C: nop

    return;
    // 0x8015C74C: nop

;}
RECOMP_FUNC void itLizardonMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F9CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017F9D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017F9D4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017F9D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017F9DC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8017F9E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017F9E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017F9E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F9EC: addiu       $a1, $a1, -0x52D0
    ctx->r5 = ADD32(ctx->r5, -0X52D0);
    // 0x8017F9F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8017F9F4: jal         0x8016E174
    // 0x8017F9F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017F9F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017F9FC: beq         $v0, $zero, L_8017FAB8
    if (ctx->r2 == 0) {
        // 0x8017FA00: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8017FAB8;
    }
    // 0x8017FA00: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017FA04: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017FA08: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017FA0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017FA10: jal         0x80008CC0
    // 0x8017FA14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8017FA14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017FA18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017FA1C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8017FA20: jal         0x80008CC0
    // 0x8017FA24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017FA24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8017FA28: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017FA2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017FA30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017FA34: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8017FA38: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017FA3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017FA40: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x8017FA44: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017FA48: addiu       $t2, $zero, 0x16
    ctx->r10 = ADD32(0, 0X16);
    // 0x8017FA4C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8017FA50: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8017FA54: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8017FA58: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8017FA5C: addiu       $t7, $t7, -0x2A40
    ctx->r15 = ADD32(ctx->r15, -0X2A40);
    // 0x8017FA60: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x8017FA64: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017FA68: addiu       $t9, $t9, 0x3624
    ctx->r25 = ADD32(ctx->r25, 0X3624);
    // 0x8017FA6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017FA70: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x8017FA74: lw          $t3, 0x2D4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017FA78: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x8017FA7C: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8017FA80: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017FA84: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017FA88: lh          $t4, 0x2E($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2E);
    // 0x8017FA8C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017FA90: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8017FA94: nop

    // 0x8017FA98: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017FA9C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017FAA0: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8017FAA4: lw          $t5, 0x2D4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017FAA8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8017FAAC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8017FAB0: jal         0x8000BD1C
    // 0x8017FAB4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_3;
    // 0x8017FAB4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
L_8017FAB8:
    // 0x8017FAB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017FABC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8017FAC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017FAC4: jr          $ra
    // 0x8017FAC8: nop

    return;
    // 0x8017FAC8: nop

;}
RECOMP_FUNC void ftBossCommonRandEdgeLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80158098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015809C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801580A0: jal         0x80018910
    // 0x801580A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x801580A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801580A8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x801580AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801580B0: beq         $t6, $zero, L_801580C8
    if (ctx->r14 == 0) {
        // 0x801580B4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_801580C8;
    }
    // 0x801580B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801580B8: jal         0x800F4428
    // 0x801580BC: nop

    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x801580BC: nop

    after_1:
    // 0x801580C0: b           L_801580D4
    // 0x801580C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801580D4;
    // 0x801580C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801580C8:
    // 0x801580C8: jal         0x800F4408
    // 0x801580CC: nop

    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x801580CC: nop

    after_2:
    // 0x801580D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801580D4:
    // 0x801580D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801580D8: jr          $ra
    // 0x801580DC: nop

    return;
    // 0x801580DC: nop

;}
RECOMP_FUNC void mpCollisionGetRWallEdgeD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F46B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F46B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F46B8: jal         0x800F4488
    // 0x800F46BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    mpCollisionGetUDEdge(rdram, ctx);
        goto after_0;
    // 0x800F46BC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x800F46C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F46C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F46C8: jr          $ra
    // 0x800F46CC: nop

    return;
    // 0x800F46CC: nop

;}
RECOMP_FUNC void wpYoshiEggHitInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BFA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016BFA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016BFA8: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x8016BFAC: lbu         $t7, 0x148($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X148);
    // 0x8016BFB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016BFB4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8016BFB8: andi        $t9, $t7, 0xFFF7
    ctx->r25 = ctx->r15 & 0XFFF7;
    // 0x8016BFBC: andi        $t0, $t9, 0xFB
    ctx->r8 = ctx->r25 & 0XFB;
    // 0x8016BFC0: sb          $t9, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r25;
    // 0x8016BFC4: sw          $t6, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r14;
    // 0x8016BFC8: sb          $t0, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r8;
    // 0x8016BFCC: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8016BFD0: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8016BFD4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8016BFD8: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x8016BFDC: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8016BFE0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8016BFE4: addiu       $t2, $t2, -0x408C
    ctx->r10 = ADD32(ctx->r10, -0X408C);
    // 0x8016BFE8: sw          $zero, 0x50($t1)
    MEM_W(0X50, ctx->r9) = 0;
    // 0x8016BFEC: sw          $t2, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->r10;
    // 0x8016BFF0: sw          $zero, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = 0;
    // 0x8016BFF4: sw          $zero, 0x280($v0)
    MEM_W(0X280, ctx->r2) = 0;
    // 0x8016BFF8: sw          $zero, 0x284($v0)
    MEM_W(0X284, ctx->r2) = 0;
    // 0x8016BFFC: sw          $zero, 0x288($v0)
    MEM_W(0X288, ctx->r2) = 0;
    // 0x8016C000: sw          $zero, 0x28C($v0)
    MEM_W(0X28C, ctx->r2) = 0;
    // 0x8016C004: jr          $ra
    // 0x8016C008: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
    return;
    // 0x8016C008: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
;}
RECOMP_FUNC void mnDataMakeCharacters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D5C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D60: lw          $t6, 0x3088($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3088);
    // 0x80131D64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D6C: beq         $t6, $zero, L_80131D88
    if (ctx->r14 == 0) {
        // 0x80131D70: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80131D88;
    }
    // 0x80131D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D74: addiu       $t7, $zero, 0x85
    ctx->r15 = ADD32(0, 0X85);
    // 0x80131D78: addiu       $t8, $zero, 0x2A
    ctx->r24 = ADD32(0, 0X2A);
    // 0x80131D7C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80131D80: b           L_80131D98
    // 0x80131D84: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_80131D98;
    // 0x80131D84: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80131D88:
    // 0x80131D88: addiu       $t9, $zero, 0x71
    ctx->r25 = ADD32(0, 0X71);
    // 0x80131D8C: addiu       $t0, $zero, 0x39
    ctx->r8 = ADD32(0, 0X39);
    // 0x80131D90: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80131D94: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80131D98:
    // 0x80131D98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D9C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131DA0: jal         0x80009968
    // 0x80131DA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131DA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131DA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131DAC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131DB0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80131DB4: sw          $v0, 0x3060($at)
    MEM_W(0X3060, ctx->r1) = ctx->r2;
    // 0x80131DB8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131DBC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131DC0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DC8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131DCC: jal         0x80009DF4
    // 0x80131DD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131DD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131DD4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80131DD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80131DDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131DE0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80131DE4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80131DE8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80131DEC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131DF0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80131DF4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80131DF8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80131DFC: jal         0x80131C24
    // 0x80131E00: nop

    mnDataMakeOptionTab(rdram, ctx);
        goto after_2;
    // 0x80131E00: nop

    after_2:
    // 0x80131E04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E08: lw          $a1, 0x3078($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3078);
    // 0x80131E0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131E10: jal         0x80131B4C
    // 0x80131E14: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80131E14: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80131E18: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131E1C: lw          $t4, 0x3164($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3164);
    // 0x80131E20: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131E24: addiu       $t5, $t5, 0x14E0
    ctx->r13 = ADD32(ctx->r13, 0X14E0);
    // 0x80131E28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131E2C: jal         0x800CCFDC
    // 0x80131E30: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131E30: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80131E34: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E38: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131E3C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131E40: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131E44: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131E48: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80131E4C: addiu       $t1, $t0, 0x1A
    ctx->r9 = ADD32(ctx->r8, 0X1A);
    // 0x80131E50: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80131E54: nop

    // 0x80131E58: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131E5C: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80131E60: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80131E64: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131E68: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131E6C: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x80131E70: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80131E74: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131E78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80131E7C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131E88: jr          $ra
    // 0x80131E8C: nop

    return;
    // 0x80131E8C: nop

;}
RECOMP_FUNC void func_ovl2_8010C4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C4D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C4D4: lwc1        $f2, 0x14C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X14C0);
    // 0x8010C4D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C4DC: lwc1        $f4, 0xC1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC1C);
    // 0x8010C4E0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8010C4E4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8010C4E8: nop

    // 0x8010C4EC: bc1fl       L_8010C504
    if (!c1cs) {
        // 0x8010C4F0: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8010C504;
    }
    goto skip_0;
    // 0x8010C4F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8010C4F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C4F8: jr          $ra
    // 0x8010C4FC: lwc1        $f0, 0xC20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC20);
    return;
    // 0x8010C4FC: lwc1        $f0, 0xC20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC20);
    // 0x8010C500: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8010C504:
    // 0x8010C504: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C508: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8010C50C: nop

    // 0x8010C510: bc1fl       L_8010C528
    if (!c1cs) {
        // 0x8010C514: sub.s       $f6, $f2, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_8010C528;
    }
    goto skip_1;
    // 0x8010C514: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    skip_1:
    // 0x8010C518: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C51C: jr          $ra
    // 0x8010C520: lwc1        $f0, 0xC24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC24);
    return;
    // 0x8010C520: lwc1        $f0, 0xC24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC24);
    // 0x8010C524: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
L_8010C528:
    // 0x8010C528: lwc1        $f8, 0xC28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC28);
    // 0x8010C52C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010C530: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010C534: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010C538: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C53C: lwc1        $f4, 0xC2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC2C);
    // 0x8010C540: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C544: lwc1        $f8, 0xC30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC30);
    // 0x8010C548: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8010C54C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010C550: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010C554: jr          $ra
    // 0x8010C558: nop

    return;
    // 0x8010C558: nop

;}
RECOMP_FUNC void grWallpaperRunProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104CD0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80104CD4: lw          $t6, 0x13D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13D8);
    // 0x80104CD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104CDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104CE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104CE4: lw          $s0, 0x18($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X18);
    // 0x80104CE8: beql        $s0, $zero, L_80104D20
    if (ctx->r16 == 0) {
        // 0x80104CEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80104D20;
    }
    goto skip_0;
    // 0x80104CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80104CF0: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
L_80104CF4:
    // 0x80104CF4: bnel        $t7, $zero, L_80104D14
    if (ctx->r15 != 0) {
        // 0x80104CF8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80104D14;
    }
    goto skip_1;
    // 0x80104CF8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80104CFC: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80104D00: beql        $v0, $zero, L_80104D14
    if (ctx->r2 == 0) {
        // 0x80104D04: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80104D14;
    }
    goto skip_2;
    // 0x80104D04: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80104D08: jalr        $v0
    // 0x80104D0C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80104D0C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x80104D10: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80104D14:
    // 0x80104D14: bnel        $s0, $zero, L_80104CF4
    if (ctx->r16 != 0) {
        // 0x80104D18: lbu         $t7, 0x15($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X15);
            goto L_80104CF4;
    }
    goto skip_3;
    // 0x80104D18: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    skip_3:
    // 0x80104D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80104D20:
    // 0x80104D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80104D28: jr          $ra
    // 0x80104D2C: nop

    return;
    // 0x80104D2C: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicapArrowInRangeAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801357A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801357A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801357AC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801357B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801357B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801357B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801357BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801357C0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801357C4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801357C8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801357CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801357D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801357D4: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x801357D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801357DC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801357E0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_801357E4:
    // 0x801357E4: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x801357E8: addiu       $s2, $s0, 0x38
    ctx->r18 = ADD32(ctx->r16, 0X38);
    // 0x801357EC: bne         $v0, $zero, L_801357FC
    if (ctx->r2 != 0) {
        // 0x801357F0: nop
    
            goto L_801357FC;
    }
    // 0x801357F0: nop

    // 0x801357F4: b           L_801357FC
    // 0x801357F8: addiu       $s2, $s0, 0x3C
    ctx->r18 = ADD32(ctx->r16, 0X3C);
        goto L_801357FC;
    // 0x801357F8: addiu       $s2, $s0, 0x3C
    ctx->r18 = ADD32(ctx->r16, 0X3C);
L_801357FC:
    // 0x801357FC: beql        $s5, $v0, L_8013582C
    if (ctx->r21 == ctx->r2) {
        // 0x80135800: lw          $t7, 0x88($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X88);
            goto L_8013582C;
    }
    goto skip_0;
    // 0x80135800: lw          $t7, 0x88($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X88);
    skip_0:
    // 0x80135804: jal         0x801370F8
    // 0x80135808: nop

    mnPlayersVSCheckHandicapOn(rdram, ctx);
        goto after_0;
    // 0x80135808: nop

    after_0:
    // 0x8013580C: beql        $v0, $zero, L_801358C4
    if (ctx->r2 == 0) {
        // 0x80135810: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801358C4;
    }
    goto skip_1;
    // 0x80135810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80135814: lw          $t6, 0x84($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84);
    // 0x80135818: bnel        $t6, $zero, L_801358C4
    if (ctx->r14 != 0) {
        // 0x8013581C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801358C4;
    }
    goto skip_2;
    // 0x8013581C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80135820: bnel        $s1, $s4, L_801358C4
    if (ctx->r17 != ctx->r20) {
        // 0x80135824: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801358C4;
    }
    goto skip_3;
    // 0x80135824: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x80135828: lw          $t7, 0x88($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X88);
L_8013582C:
    // 0x8013582C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80135830: beql        $t7, $zero, L_801358C4
    if (ctx->r15 == 0) {
        // 0x80135834: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801358C4;
    }
    goto skip_4;
    // 0x80135834: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80135838: jal         0x801358F8
    // 0x8013583C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSCheckHandicapArrowRInRange(rdram, ctx);
        goto after_1;
    // 0x8013583C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80135840: beq         $v0, $zero, L_8013587C
    if (ctx->r2 == 0) {
        // 0x80135844: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8013587C;
    }
    // 0x80135844: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80135848: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8013584C: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x80135850: beq         $at, $zero, L_80135874
    if (ctx->r1 == 0) {
        // 0x80135854: nop
    
            goto L_80135874;
    }
    // 0x80135854: nop

    // 0x80135858: jal         0x800269C0
    // 0x8013585C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8013585C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_2:
    // 0x80135860: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80135864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80135868: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8013586C: jal         0x80136E90
    // 0x80135870: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    mnPlayersVSMakeHandicapLevelValue(rdram, ctx);
        goto after_3;
    // 0x80135870: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    after_3:
L_80135874:
    // 0x80135874: b           L_801358D0
    // 0x80135878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801358D0;
    // 0x80135878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013587C:
    // 0x8013587C: jal         0x801359D8
    // 0x80135880: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSCheckHandicapArrowLInRange(rdram, ctx);
        goto after_4;
    // 0x80135880: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80135884: beql        $v0, $zero, L_801358C4
    if (ctx->r2 == 0) {
        // 0x80135888: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801358C4;
    }
    goto skip_5;
    // 0x80135888: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8013588C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80135890: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80135894: bne         $at, $zero, L_801358B8
    if (ctx->r1 != 0) {
        // 0x80135898: nop
    
            goto L_801358B8;
    }
    // 0x80135898: nop

    // 0x8013589C: jal         0x800269C0
    // 0x801358A0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x801358A0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_5:
    // 0x801358A4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x801358A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801358AC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x801358B0: jal         0x80136E90
    // 0x801358B4: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    mnPlayersVSMakeHandicapLevelValue(rdram, ctx);
        goto after_6;
    // 0x801358B4: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    after_6:
L_801358B8:
    // 0x801358B8: b           L_801358D0
    // 0x801358BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801358D0;
    // 0x801358BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801358C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801358C4:
    // 0x801358C4: bne         $s1, $s6, L_801357E4
    if (ctx->r17 != ctx->r22) {
        // 0x801358C8: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_801357E4;
    }
    // 0x801358C8: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    // 0x801358CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801358D0:
    // 0x801358D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801358D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801358D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801358DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801358E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801358E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801358E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801358EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801358F0: jr          $ra
    // 0x801358F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801358F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftParamCheckHaveKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9B40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9B44: lw          $t6, 0xA98($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA98);
    // 0x800E9B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E9B4C: beq         $t6, $zero, L_800E9B5C
    if (ctx->r14 == 0) {
        // 0x800E9B50: nop
    
            goto L_800E9B5C;
    }
    // 0x800E9B50: nop

    // 0x800E9B54: jr          $ra
    // 0x800E9B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E9B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E9B5C:
    // 0x800E9B5C: jr          $ra
    // 0x800E9B60: nop

    return;
    // 0x800E9B60: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016090C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160914: jal         0x80160810
    // 0x80160918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbyCopyCaptainSpecialNUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80160918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016091C: jal         0x800D8C14
    // 0x80160920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_1;
    // 0x80160920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80160924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80160928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016092C: jr          $ra
    // 0x80160930: nop

    return;
    // 0x80160930: nop

;}
RECOMP_FUNC void itMapCheckLRWallProcNoFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801735A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801735A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801735A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801735AC: jal         0x8017356C
    // 0x801735B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    itMapTestLRWallCheckFloor(rdram, ctx);
        goto after_0;
    // 0x801735B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801735B4: bne         $v0, $zero, L_801735CC
    if (ctx->r2 != 0) {
        // 0x801735B8: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_801735CC;
    }
    // 0x801735B8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801735BC: jalr        $t9
    // 0x801735C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x801735C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801735C4: b           L_801735D0
    // 0x801735C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801735D0;
    // 0x801735C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801735CC:
    // 0x801735CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801735D0:
    // 0x801735D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801735D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801735D8: jr          $ra
    // 0x801735DC: nop

    return;
    // 0x801735DC: nop

;}
RECOMP_FUNC void mvOpeningRoomInitScene1Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133210: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133214: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013321C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133220: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133224: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80133228: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013322C: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x80133230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013323C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133240: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133244: jal         0x80007080
    // 0x80133248: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x80133248: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8013324C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80133250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133254: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133258: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013325C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80133260: lwc1        $f8, 0x4C8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C8C);
    // 0x80133264: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133268: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x8013326C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80133270: lw          $t7, 0x50B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50B8);
    // 0x80133274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133278: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013327C: jal         0x8000FA3C
    // 0x80133280: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80133280: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133284: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133288: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8013328C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80133290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133294: jal         0x80008188
    // 0x80133298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80133298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8013329C: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x801332A0: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x801332A4: sw          $t0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r8;
    // 0x801332A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801332AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801332B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801332B4: jr          $ra
    // 0x801332B8: nop

    return;
    // 0x801332B8: nop

;}
RECOMP_FUNC void mnVSRecordGetTotalTKO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131CD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131CDC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131CE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131CE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131CE8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131CEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131CF0: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80131CF4:
    // 0x80131CF4: jal         0x801326EC
    // 0x80131CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x80131CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80131CFC: beql        $v0, $zero, L_80131D14
    if (ctx->r2 == 0) {
        // 0x80131D00: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80131D14;
    }
    goto skip_0;
    // 0x80131D00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80131D04: jal         0x80131C0C
    // 0x80131D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSRecordGetTKO(rdram, ctx);
        goto after_1;
    // 0x80131D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80131D0C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80131D10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80131D14:
    // 0x80131D14: bne         $s0, $s2, L_80131CF4
    if (ctx->r16 != ctx->r18) {
        // 0x80131D18: nop
    
            goto L_80131CF4;
    }
    // 0x80131D18: nop

    // 0x80131D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131D20: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80131D24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131D2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131D30: jr          $ra
    // 0x80131D34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131D34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80375E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375E60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80375E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375E68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80375E6C: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x80375E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80375E74: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80375E78: beql        $t7, $at, L_80376004
    if (ctx->r15 == ctx->r1) {
        // 0x80375E7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80376004;
    }
    goto skip_0;
    // 0x80375E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80375E80: lhu         $v0, -0x60D0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X60D0);
    // 0x80375E84: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80375E88: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375E8C: bne         $v0, $at, L_80375EF0
    if (ctx->r2 != ctx->r1) {
        // 0x80375E90: addiu       $v1, $v1, -0x1050
        ctx->r3 = ADD32(ctx->r3, -0X1050);
            goto L_80375EF0;
    }
    // 0x80375E90: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x80375E94: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80375E98: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80375E9C: lb          $t0, 0x5478($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X5478);
    // 0x80375EA0: lw          $t8, 0x6678($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6678);
    // 0x80375EA4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80375EA8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80375EAC: bgez        $t8, L_80375EBC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80375EB0: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80375EBC;
    }
    // 0x80375EB0: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80375EB4: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80375EB8: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80375EBC:
    // 0x80375EBC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80375EC0: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80375EC4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x80375EC8: lb          $t5, 0x5479($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X5479);
    // 0x80375ECC: lw          $t3, 0x667C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X667C);
    // 0x80375ED0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80375ED4: bgez        $t3, L_80375EE4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80375ED8: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_80375EE4;
    }
    // 0x80375ED8: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80375EDC: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x80375EE0: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80375EE4:
    // 0x80375EE4: subu        $t7, $t4, $t6
    ctx->r15 = SUB32(ctx->r12, ctx->r14);
    // 0x80375EE8: b           L_80375FF8
    // 0x80375EEC: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
        goto L_80375FF8;
    // 0x80375EEC: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
L_80375EF0:
    // 0x80375EF0: ori         $at, $zero, 0xFFFE
    ctx->r1 = 0 | 0XFFFE;
    // 0x80375EF4: bne         $v0, $at, L_80375F44
    if (ctx->r2 != ctx->r1) {
        // 0x80375EF8: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80375F44;
    }
    // 0x80375EF8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80375EFC: lb          $a1, 0x5478($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X5478);
    // 0x80375F00: jal         0x80375CB8
    // 0x80375F04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_ovl8_80375CB8(rdram, ctx);
        goto after_0;
    // 0x80375F04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80375F08: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375F0C: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x80375F10: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80375F14: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80375F18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80375F1C: addu        $t0, $t8, $v0
    ctx->r8 = ADD32(ctx->r24, ctx->r2);
    // 0x80375F20: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x80375F24: jal         0x80375CB8
    // 0x80375F28: lb          $a1, 0x5479($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X5479);
    func_ovl8_80375CB8(rdram, ctx);
        goto after_1;
    // 0x80375F28: lb          $a1, 0x5479($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X5479);
    after_1:
    // 0x80375F2C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375F30: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x80375F34: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80375F38: subu        $t1, $t9, $v0
    ctx->r9 = SUB32(ctx->r25, ctx->r2);
    // 0x80375F3C: b           L_80375FF8
    // 0x80375F40: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
        goto L_80375FF8;
    // 0x80375F40: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
L_80375F44:
    // 0x80375F44: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // 0x80375F48: jal         0x80377244
    // 0x80375F4C: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    func_ovl8_80377244(rdram, ctx);
        goto after_2;
    // 0x80375F4C: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    after_2:
    // 0x80375F50: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80375F54: lhu         $t2, -0x60D0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X60D0);
    // 0x80375F58: lh          $a0, 0x18($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X18);
    // 0x80375F5C: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x80375F60: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x80375F64: beq         $t3, $zero, L_80375F80
    if (ctx->r11 == 0) {
        // 0x80375F68: lui         $t5, 0x8039
        ctx->r13 = S32(0X8039 << 16);
            goto L_80375F80;
    }
    // 0x80375F68: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80375F6C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80375F70: lh          $a0, -0x60BC($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X60BC);
    // 0x80375F74: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80375F78: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80375F7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
L_80375F80:
    // 0x80375F80: lhu         $t5, -0x60CC($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X60CC);
    // 0x80375F84: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375F88: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80375F8C: and         $t4, $v0, $t5
    ctx->r12 = ctx->r2 & ctx->r13;
    // 0x80375F90: beq         $t4, $zero, L_80375FA0
    if (ctx->r12 == 0) {
        // 0x80375F94: lui         $v1, 0x8039
        ctx->r3 = S32(0X8039 << 16);
            goto L_80375FA0;
    }
    // 0x80375F94: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375F98: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80375F9C: lh          $a0, -0x60BC($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X60BC);
L_80375FA0:
    // 0x80375FA0: lhu         $t6, -0x60C4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X60C4);
    // 0x80375FA4: addiu       $v1, $v1, -0x1050
    ctx->r3 = ADD32(ctx->r3, -0X1050);
    // 0x80375FA8: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80375FAC: beq         $t7, $zero, L_80375FC8
    if (ctx->r15 == 0) {
        // 0x80375FB0: nop
    
            goto L_80375FC8;
    }
    // 0x80375FB0: nop

    // 0x80375FB4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80375FB8: lh          $a1, -0x60C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X60C0);
    // 0x80375FBC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80375FC0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80375FC4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_80375FC8:
    // 0x80375FC8: lhu         $t8, -0x60C8($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X60C8);
    // 0x80375FCC: and         $t0, $v0, $t8
    ctx->r8 = ctx->r2 & ctx->r24;
    // 0x80375FD0: beql        $t0, $zero, L_80375FE4
    if (ctx->r8 == 0) {
        // 0x80375FD4: lh          $t9, 0x0($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X0);
            goto L_80375FE4;
    }
    goto skip_1;
    // 0x80375FD4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    skip_1:
    // 0x80375FD8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80375FDC: lh          $a1, -0x60C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X60C0);
    // 0x80375FE0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
L_80375FE4:
    // 0x80375FE4: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x80375FE8: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x80375FEC: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80375FF0: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80375FF4: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_80375FF8:
    // 0x80375FF8: jal         0x80375D84
    // 0x80375FFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_ovl8_80375D84(rdram, ctx);
        goto after_3;
    // 0x80375FFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80376000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80376004:
    // 0x80376004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376008: jr          $ra
    // 0x8037600C: nop

    return;
    // 0x8037600C: nop

;}
RECOMP_FUNC void itRShellDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AB48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017AB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AB50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017AB54: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017AB58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017AB5C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8017AB60: lbu         $t8, 0x2CE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017AB64: sb          $v0, 0x352($a0)
    MEM_B(0X352, ctx->r4) = ctx->r2;
    // 0x8017AB68: sb          $v0, 0x353($a0)
    MEM_B(0X353, ctx->r4) = ctx->r2;
    // 0x8017AB6C: andi        $t9, $t8, 0xFFF1
    ctx->r25 = ctx->r24 & 0XFFF1;
    // 0x8017AB70: sb          $t7, 0x350($a0)
    MEM_B(0X350, ctx->r4) = ctx->r15;
    // 0x8017AB74: jal         0x80173F78
    // 0x8017AB78: sb          $t9, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r25;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017AB78: sb          $t9, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r25;
    after_0:
    // 0x8017AB7C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017AB80: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017AB84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017AB88: jal         0x80172EC8
    // 0x8017AB8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017AB8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8017AB90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AB94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017AB98: jr          $ra
    // 0x8017AB9C: nop

    return;
    // 0x8017AB9C: nop

;}
RECOMP_FUNC void dbCubeStopRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C0C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131C10: lw          $a1, 0x2D40($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2D40);
    // 0x80131C14: jal         0x80115630
    // 0x80131C18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gmRumbleStopRumbleID(rdram, ctx);
        goto after_0;
    // 0x80131C18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80131C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131C24: jr          $ra
    // 0x80131C28: nop

    return;
    // 0x80131C28: nop

;}
RECOMP_FUNC void ftComputerCheckFindTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013295C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80132960: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80132964: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80132968: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x8013296C: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80132970: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80132974: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80132978: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8013297C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80132980: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80132984: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80132988: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8013298C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80132990: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80132994: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80132998: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8013299C: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x801329A0: lw          $s2, 0x66FC($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X66FC);
    // 0x801329A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801329A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801329AC: lwc1        $f24, -0x447C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X447C);
    // 0x801329B0: lwc1        $f26, 0x1C($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801329B4: beq         $s2, $zero, L_80132B00
    if (ctx->r18 == 0) {
        // 0x801329B8: lwc1        $f28, 0x20($v0)
        ctx->f28.u32l = MEM_W(ctx->r2, 0X20);
            goto L_80132B00;
    }
    // 0x801329B8: lwc1        $f28, 0x20($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801329BC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801329C0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801329C4: addiu       $s3, $s3, 0x1308
    ctx->r19 = ADD32(ctx->r19, 0X1308);
    // 0x801329C8: addiu       $s4, $s4, 0x1300
    ctx->r20 = ADD32(ctx->r20, 0X1300);
    // 0x801329CC: addiu       $s7, $zero, 0xD
    ctx->r23 = ADD32(0, 0XD);
    // 0x801329D0: addiu       $s6, $zero, 0x55
    ctx->r22 = ADD32(0, 0X55);
    // 0x801329D4: addiu       $s5, $zero, 0x54
    ctx->r21 = ADD32(0, 0X54);
    // 0x801329D8: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
L_801329DC:
    // 0x801329DC: beql        $s2, $t6, L_80132AF8
    if (ctx->r18 == ctx->r14) {
        // 0x801329E0: lw          $s2, 0x4($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X4);
            goto L_80132AF8;
    }
    goto skip_0;
    // 0x801329E0: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
    skip_0:
    // 0x801329E4: lw          $s0, 0x84($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X84);
    // 0x801329E8: lbu         $t8, 0xC($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XC);
    // 0x801329EC: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x801329F0: beql        $t7, $t8, L_80132AF8
    if (ctx->r15 == ctx->r24) {
        // 0x801329F4: lw          $s2, 0x4($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X4);
            goto L_80132AF8;
    }
    goto skip_1;
    // 0x801329F4: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
    skip_1:
    // 0x801329F8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x801329FC: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132A00: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80132A04: lwc1        $f20, 0x1C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80132A08: bne         $at, $zero, L_80132AF4
    if (ctx->r1 != 0) {
        // 0x80132A0C: lwc1        $f22, 0x20($v0)
        ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
            goto L_80132AF4;
    }
    // 0x80132A0C: lwc1        $f22, 0x20($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80132A10: jal         0x800F8FFC
    // 0x80132A14: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_0;
    // 0x80132A14: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_0:
    // 0x80132A18: beql        $v0, $zero, L_80132A84
    if (ctx->r2 == 0) {
        // 0x80132A1C: lw          $t2, 0x14C($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X14C);
            goto L_80132A84;
    }
    goto skip_2;
    // 0x80132A1C: lw          $t2, 0x14C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14C);
    skip_2:
    // 0x80132A20: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80132A24: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x80132A28: nop

    // 0x80132A2C: bc1fl       L_80132A84
    if (!c1cs) {
        // 0x80132A30: lw          $t2, 0x14C($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X14C);
            goto L_80132A84;
    }
    goto skip_3;
    // 0x80132A30: lw          $t2, 0x14C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14C);
    skip_3:
    // 0x80132A34: lwc1        $f6, 0x2C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x80132A38: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x80132A3C: nop

    // 0x80132A40: bc1fl       L_80132A84
    if (!c1cs) {
        // 0x80132A44: lw          $t2, 0x14C($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X14C);
            goto L_80132A84;
    }
    goto skip_4;
    // 0x80132A44: lw          $t2, 0x14C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14C);
    skip_4:
    // 0x80132A48: lwc1        $f8, 0x24($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80132A4C: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x80132A50: nop

    // 0x80132A54: bc1fl       L_80132A84
    if (!c1cs) {
        // 0x80132A58: lw          $t2, 0x14C($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X14C);
            goto L_80132A84;
    }
    goto skip_5;
    // 0x80132A58: lw          $t2, 0x14C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14C);
    skip_5:
    // 0x80132A5C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80132A60: lh          $t1, 0x6C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6C);
    // 0x80132A64: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80132A68: nop

    // 0x80132A6C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132A70: c.lt.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl < ctx->f16.fl;
    // 0x80132A74: nop

    // 0x80132A78: bc1tl       L_80132AA4
    if (c1cs) {
        // 0x80132A7C: lw          $t3, 0x8($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X8);
            goto L_80132AA4;
    }
    goto skip_6;
    // 0x80132A7C: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    skip_6:
    // 0x80132A80: lw          $t2, 0x14C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14C);
L_80132A84:
    // 0x80132A84: bnel        $t2, $zero, L_80132AF8
    if (ctx->r10 != 0) {
        // 0x80132A88: lw          $s2, 0x4($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X4);
            goto L_80132AF8;
    }
    goto skip_7;
    // 0x80132A88: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
    skip_7:
    // 0x80132A8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80132A90: beql        $s5, $v0, L_80132AA4
    if (ctx->r21 == ctx->r2) {
        // 0x80132A94: lw          $t3, 0x8($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X8);
            goto L_80132AA4;
    }
    goto skip_8;
    // 0x80132A94: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    skip_8:
    // 0x80132A98: bnel        $s6, $v0, L_80132AF8
    if (ctx->r22 != ctx->r2) {
        // 0x80132A9C: lw          $s2, 0x4($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X4);
            goto L_80132AF8;
    }
    goto skip_9;
    // 0x80132A9C: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
    skip_9:
    // 0x80132AA0: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
L_80132AA4:
    // 0x80132AA4: bnel        $s7, $t3, L_80132ABC
    if (ctx->r23 != ctx->r11) {
        // 0x80132AA8: sub.s       $f0, $f26, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f20.fl;
            goto L_80132ABC;
    }
    goto skip_10;
    // 0x80132AA8: sub.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f20.fl;
    skip_10:
    // 0x80132AAC: lw          $t4, 0x14C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C);
    // 0x80132AB0: bnel        $t4, $zero, L_80132AF8
    if (ctx->r12 != 0) {
        // 0x80132AB4: lw          $s2, 0x4($s2)
        ctx->r18 = MEM_W(ctx->r18, 0X4);
            goto L_80132AF8;
    }
    goto skip_11;
    // 0x80132AB4: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
    skip_11:
    // 0x80132AB8: sub.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f20.fl;
L_80132ABC:
    // 0x80132ABC: addiu       $v1, $s1, 0x1CC
    ctx->r3 = ADD32(ctx->r17, 0X1CC);
    // 0x80132AC0: sub.s       $f2, $f28, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f28.fl - ctx->f22.fl;
    // 0x80132AC4: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80132AC8: nop

    // 0x80132ACC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80132AD0: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80132AD4: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x80132AD8: nop

    // 0x80132ADC: bc1f        L_80132AF4
    if (!c1cs) {
        // 0x80132AE0: nop
    
            goto L_80132AF4;
    }
    // 0x80132AE0: nop

    // 0x80132AE4: swc1        $f20, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f20.u32l;
    // 0x80132AE8: swc1        $f22, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f22.u32l;
    // 0x80132AEC: sw          $s0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r16;
    // 0x80132AF0: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_80132AF4:
    // 0x80132AF4: lw          $s2, 0x4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4);
L_80132AF8:
    // 0x80132AF8: bnel        $s2, $zero, L_801329DC
    if (ctx->r18 != 0) {
        // 0x80132AFC: lw          $t6, 0x4($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X4);
            goto L_801329DC;
    }
    goto skip_12;
    // 0x80132AFC: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    skip_12:
L_80132B00:
    // 0x80132B00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80132B04: lwc1        $f6, -0x4478($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4478);
    // 0x80132B08: addiu       $v1, $s1, 0x1CC
    ctx->r3 = ADD32(ctx->r17, 0X1CC);
    // 0x80132B0C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80132B10: c.eq.s      $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f24.fl == ctx->f6.fl;
    // 0x80132B14: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80132B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132B1C: bc1fl       L_80132B44
    if (!c1cs) {
        // 0x80132B20: lbu         $t9, 0x4A($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X4A);
            goto L_80132B44;
    }
    goto skip_13;
    // 0x80132B20: lbu         $t9, 0x4A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4A);
    skip_13:
    // 0x80132B24: lbu         $t6, 0x4A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4A);
    // 0x80132B28: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    // 0x80132B2C: lwc1        $f8, -0x4474($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4474);
    // 0x80132B30: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80132B34: sb          $t7, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r15;
    // 0x80132B38: b           L_80132B88
    // 0x80132B3C: swc1        $f8, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f8.u32l;
        goto L_80132B88;
    // 0x80132B3C: swc1        $f8, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f8.u32l;
    // 0x80132B40: lbu         $t9, 0x4A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4A);
L_80132B44:
    // 0x80132B44: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80132B48: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80132B4C: sb          $t0, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r8;
    // 0x80132B50: jal         0x80033510
    // 0x80132B54: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80132B54: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    after_1:
    // 0x80132B58: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80132B5C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80132B60: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80132B64: swc1        $f0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f0.u32l;
    // 0x80132B68: lw          $t1, 0x14C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X14C);
    // 0x80132B6C: bnel        $t1, $zero, L_80132B84
    if (ctx->r9 != 0) {
        // 0x80132B70: sw          $t3, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r11;
            goto L_80132B84;
    }
    goto skip_14;
    // 0x80132B70: sw          $t3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r11;
    skip_14:
    // 0x80132B74: lw          $t2, 0xEC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XEC);
    // 0x80132B78: b           L_80132B84
    // 0x80132B7C: sw          $t2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r10;
        goto L_80132B84;
    // 0x80132B7C: sw          $t2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r10;
    // 0x80132B80: sw          $t3, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r11;
L_80132B84:
    // 0x80132B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132B88:
    // 0x80132B88: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80132B8C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80132B90: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80132B94: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80132B98: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80132B9C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80132BA0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80132BA4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80132BA8: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80132BAC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80132BB0: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x80132BB4: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x80132BB8: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x80132BBC: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80132BC0: jr          $ra
    // 0x80132BC4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80132BC4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void mvOpeningJungleStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D818: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D820: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D824: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018D828: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    // 0x8018D82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D830: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018D834: jal         0x80007024
    // 0x8018D838: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018D838: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018D83C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018D840: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D844: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D848: addiu       $t9, $t9, -0x21A0
    ctx->r25 = ADD32(ctx->r25, -0X21A0);
    // 0x8018D84C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018D850: addiu       $a0, $a0, -0x26A8
    ctx->r4 = ADD32(ctx->r4, -0X26A8);
    // 0x8018D854: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018D858: jal         0x8000683C
    // 0x8018D85C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018D85C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018D860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D868: jr          $ra
    // 0x8018D86C: nop

    return;
    // 0x8018D86C: nop

;}
RECOMP_FUNC void syMainGetThread4StackStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000460: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000464: jr          $ra
    // 0x80000468: addiu       $v0, $v0, 0xCE0
    ctx->r2 = ADD32(ctx->r2, 0XCE0);
    return;
    // 0x80000468: addiu       $v0, $v0, 0xCE0
    ctx->r2 = ADD32(ctx->r2, 0XCE0);
;}
RECOMP_FUNC void func_ovl7_8018F984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F984: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F988: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F98C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018F990: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8018F994: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
L_8018F998:
    // 0x8018F998: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8018F99C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8018F9A0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018F9A4: sh          $a0, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r4;
    // 0x8018F9A8: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x8018F9AC: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8018F9B0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8018F9B4: sh          $a0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r4;
    // 0x8018F9B8: lw          $t2, 0x38($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X38);
    // 0x8018F9BC: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8018F9C0: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8018F9C4: sh          $a0, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r4;
    // 0x8018F9C8: lw          $t5, 0x38($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X38);
    // 0x8018F9CC: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8018F9D0: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8018F9D4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8018F9D8: bne         $v1, $a1, L_8018F998
    if (ctx->r3 != ctx->r5) {
        // 0x8018F9DC: sh          $a0, 0x14($t7)
        MEM_H(0X14, ctx->r15) = ctx->r4;
            goto L_8018F998;
    }
    // 0x8018F9DC: sh          $a0, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r4;
    // 0x8018F9E0: jr          $ra
    // 0x8018F9E4: nop

    return;
    // 0x8018F9E4: nop

;}
RECOMP_FUNC void ftCommonSpecialAirCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150F08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150F10: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80150F14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80150F18: lhu         $t6, 0x1BE($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1BE);
    // 0x80150F1C: lhu         $t7, 0x1B6($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1B6);
    // 0x80150F20: lw          $v1, 0x9C8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X9C8);
    // 0x80150F24: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80150F28: beql        $t8, $zero, L_8015104C
    if (ctx->r24 == 0) {
        // 0x80150F2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015104C;
    }
    goto skip_0;
    // 0x80150F2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80150F30: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80150F34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80150F38: jal         0x800F3794
    // 0x80150F3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x80150F3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80150F40: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80150F44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80150F48: bne         $v0, $zero, L_80151048
    if (ctx->r2 != 0) {
        // 0x80150F4C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80151048;
    }
    // 0x80150F4C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80150F50: lb          $v0, 0x1C3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C3);
    // 0x80150F54: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80150F58: bnel        $at, $zero, L_80150F9C
    if (ctx->r1 != 0) {
        // 0x80150F5C: slti        $at, $v0, -0x27
        ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
            goto L_80150F9C;
    }
    goto skip_1;
    // 0x80150F5C: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    skip_1:
    // 0x80150F60: lw          $t9, 0x100($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X100);
    // 0x80150F64: sll         $t1, $t9, 17
    ctx->r9 = S32(ctx->r25 << 17);
    // 0x80150F68: bgezl       $t1, L_8015104C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80150F6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015104C;
    }
    goto skip_2;
    // 0x80150F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80150F70: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80150F74: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80150F78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80150F7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80150F80: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80150F84: lw          $t9, -0x74D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X74D8);
    // 0x80150F88: jalr        $t9
    // 0x80150F8C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80150F8C: nop

    after_1:
    // 0x80150F90: b           L_8015104C
    // 0x80150F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015104C;
    // 0x80150F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80150F98: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
L_80150F9C:
    // 0x80150F9C: beql        $at, $zero, L_80150FE0
    if (ctx->r1 == 0) {
        // 0x80150FA0: lhu         $t0, 0x100($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X100);
            goto L_80150FE0;
    }
    goto skip_3;
    // 0x80150FA0: lhu         $t0, 0x100($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X100);
    skip_3:
    // 0x80150FA4: lw          $t4, 0x100($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X100);
    // 0x80150FA8: sll         $t6, $t4, 19
    ctx->r14 = S32(ctx->r12 << 19);
    // 0x80150FAC: bgezl       $t6, L_8015104C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80150FB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015104C;
    }
    goto skip_4;
    // 0x80150FB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80150FB4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80150FB8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80150FBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80150FC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80150FC4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80150FC8: lw          $t9, -0x746C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X746C);
    // 0x80150FCC: jalr        $t9
    // 0x80150FD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80150FD0: nop

    after_2:
    // 0x80150FD4: b           L_8015104C
    // 0x80150FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015104C;
    // 0x80150FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80150FDC: lhu         $t0, 0x100($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X100);
L_80150FE0:
    // 0x80150FE0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80150FE4: beql        $t1, $zero, L_8015104C
    if (ctx->r9 == 0) {
        // 0x80150FE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015104C;
    }
    goto skip_5;
    // 0x80150FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80150FEC: lb          $t2, 0x1C2($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1C2);
    // 0x80150FF0: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x80150FF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80150FF8: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80150FFC: mflo        $t4
    ctx->r12 = lo;
    // 0x80151000: slti        $at, $t4, -0x14
    ctx->r1 = SIGNED(ctx->r12) < -0X14 ? 1 : 0;
    // 0x80151004: beql        $at, $zero, L_80151024
    if (ctx->r1 == 0) {
        // 0x80151008: lw          $t5, 0x8($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X8);
            goto L_80151024;
    }
    goto skip_6;
    // 0x80151008: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    skip_6:
    // 0x8015100C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80151010: jal         0x800E8044
    // 0x80151014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamSetStickLR(rdram, ctx);
        goto after_3;
    // 0x80151014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80151018: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015101C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80151020: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
L_80151024:
    // 0x80151024: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80151028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015102C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80151030: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80151034: lw          $t9, -0x7544($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7544);
    // 0x80151038: jalr        $t9
    // 0x8015103C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8015103C: nop

    after_4:
    // 0x80151040: b           L_8015104C
    // 0x80151044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015104C;
    // 0x80151044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80151048:
    // 0x80151048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015104C:
    // 0x8015104C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151054: jr          $ra
    // 0x80151058: nop

    return;
    // 0x80151058: nop

;}
RECOMP_FUNC void mvOpeningYoshiFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE88: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DE8C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE90: addiu       $v1, $v1, -0x1BB8
    ctx->r3 = ADD32(ctx->r3, -0X1BB8);
    // 0x8018DE94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE9C: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DEA0: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DEA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DEA8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DEAC: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DEB0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DEB4:
    // 0x8018DEB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEB8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DEBC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DEC0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DEC4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DEC8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DECC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DED0: bne         $t6, $t0, L_8018DEB4
    if (ctx->r14 != ctx->r8) {
        // 0x8018DED4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DEB4;
    }
    // 0x8018DED4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DED8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEDC: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8018DEE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018DEE4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEE8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8018DEEC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DEF0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DEF4: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x8018DEF8: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
    // 0x8018DEFC: sb          $t0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r8;
    // 0x8018DF00: jal         0x8018D0C0
    // 0x8018DF04: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningYoshiSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DF04: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DF08: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DF0C: addiu       $a1, $a1, -0x2240
    ctx->r5 = ADD32(ctx->r5, -0X2240);
    // 0x8018DF10: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DF14: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DF18: jal         0x80009968
    // 0x8018DF1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DF1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DF20: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018DF24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DF28: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DF2C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF30: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF34: jal         0x8000B9FC
    // 0x8018DF38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF3C: jal         0x8018DE7C
    // 0x8018DF40: nop

    mvOpeningYoshiInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF40: nop

    after_3:
    // 0x8018DF44: jal         0x80115890
    // 0x8018DF48: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF48: nop

    after_4:
    // 0x8018DF4C: jal         0x800EC130
    // 0x8018DF50: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF50: nop

    after_5:
    // 0x8018DF54: jal         0x800FC284
    // 0x8018DF58: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF58: nop

    after_6:
    // 0x8018DF5C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF64: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF68: jal         0x8010E598
    // 0x8018DF6C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF6C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF70: jal         0x8010DB54
    // 0x8018DF74: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF74: nop

    after_8:
    // 0x8018DF78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF7C: jal         0x800D7194
    // 0x8018DF80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF84: jal         0x801654B0
    // 0x8018DF88: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF88: nop

    after_10:
    // 0x8018DF8C: jal         0x8016DEA0
    // 0x8018DF90: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF90: nop

    after_11:
    // 0x8018DF94: jal         0x800FD300
    // 0x8018DF98: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF98: nop

    after_12:
    // 0x8018DF9C: jal         0x800D786C
    // 0x8018DFA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DFA0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_13:
    // 0x8018DFA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DFA8: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DFAC: jal         0x80004980
    // 0x8018DFB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DFB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DFB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DFB8: jal         0x8018DB90
    // 0x8018DFBC: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    mvOpeningYoshiMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DFBC: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DFC0: jal         0x8018DD18
    // 0x8018DFC4: nop

    mvOpeningYoshiMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DFC4: nop

    after_16:
    // 0x8018DFC8: jal         0x8018DC30
    // 0x8018DFCC: nop

    mvOpeningYoshiMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DFCC: nop

    after_17:
    // 0x8018DFD0: jal         0x8018D194
    // 0x8018DFD4: nop

    mvOpeningYoshiMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DFD4: nop

    after_18:
    // 0x8018DFD8: jal         0x8000092C
    // 0x8018DFDC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DFDC: nop

    after_19:
    // 0x8018DFE0: sltiu       $at, $v0, 0x753
    ctx->r1 = ctx->r2 < 0X753 ? 1 : 0;
    // 0x8018DFE4: beql        $at, $zero, L_8018E004
    if (ctx->r1 == 0) {
        // 0x8018DFE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018E004;
    }
    goto skip_0;
    // 0x8018DFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFEC:
    // 0x8018DFEC: jal         0x8000092C
    // 0x8018DFF0: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFF0: nop

    after_20:
    // 0x8018DFF4: sltiu       $at, $v0, 0x753
    ctx->r1 = ctx->r2 < 0X753 ? 1 : 0;
    // 0x8018DFF8: bne         $at, $zero, L_8018DFEC
    if (ctx->r1 != 0) {
        // 0x8018DFFC: nop
    
            goto L_8018DFEC;
    }
    // 0x8018DFFC: nop

    // 0x8018E000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E004:
    // 0x8018E004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E008: jr          $ra
    // 0x8018E00C: nop

    return;
    // 0x8018E00C: nop

;}
RECOMP_FUNC void scStaffrollSetTextQuetions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132860: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80132864: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80132868: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8013286C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132870: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80132874: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013287C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80132880: addiu       $v0, $v0, 0x6BA0
    ctx->r2 = ADD32(ctx->r2, 0X6BA0);
    // 0x80132884: addiu       $t2, $t2, -0x6200
    ctx->r10 = ADD32(ctx->r10, -0X6200);
    // 0x80132888: addiu       $a2, $a2, -0x6498
    ctx->r6 = ADD32(ctx->r6, -0X6498);
    // 0x8013288C: addiu       $t1, $zero, 0x46
    ctx->r9 = ADD32(0, 0X46);
    // 0x80132890: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
L_80132894:
    // 0x80132894: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80132898: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013289C: blez        $a3, L_8013293C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x801328A0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8013293C;
    }
    // 0x801328A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801328A4:
    // 0x801328A4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x801328A8: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x801328AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801328B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801328B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801328B8: bnel        $t6, $t9, L_801328D8
    if (ctx->r14 != ctx->r25) {
        // 0x801328BC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801328D8;
    }
    goto skip_0;
    // 0x801328BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x801328C0: bne         $a1, $zero, L_801328CC
    if (ctx->r5 != 0) {
        // 0x801328C4: nop
    
            goto L_801328CC;
    }
    // 0x801328C4: nop

    // 0x801328C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801328CC:
    // 0x801328CC: b           L_801328D8
    // 0x801328D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_801328D8;
    // 0x801328D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801328D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801328D8:
    // 0x801328D8: bnel        $a1, $s1, L_80132934
    if (ctx->r5 != ctx->r17) {
        // 0x801328DC: slt         $at, $a0, $a3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80132934;
    }
    goto skip_1;
    // 0x801328DC: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    skip_1:
    // 0x801328E0: beq         $a1, $zero, L_80132928
    if (ctx->r5 == 0) {
        // 0x801328E4: andi        $t0, $a1, 0x3
        ctx->r8 = ctx->r5 & 0X3;
            goto L_80132928;
    }
    // 0x801328E4: andi        $t0, $a1, 0x3
    ctx->r8 = ctx->r5 & 0X3;
    // 0x801328E8: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x801328EC: beq         $t0, $zero, L_80132908
    if (ctx->r8 == 0) {
        // 0x801328F0: addu        $a3, $t0, $a1
        ctx->r7 = ADD32(ctx->r8, ctx->r5);
            goto L_80132908;
    }
    // 0x801328F0: addu        $a3, $t0, $a1
    ctx->r7 = ADD32(ctx->r8, ctx->r5);
L_801328F4:
    // 0x801328F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x801328F8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801328FC: bne         $a3, $a1, L_801328F4
    if (ctx->r7 != ctx->r5) {
        // 0x80132900: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801328F4;
    }
    // 0x80132900: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80132904: beq         $a1, $zero, L_80132924
    if (ctx->r5 == 0) {
        // 0x80132908: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_80132924;
    }
L_80132908:
    // 0x80132908: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8013290C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80132910: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80132914: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80132918: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8013291C: bne         $a1, $zero, L_80132908
    if (ctx->r5 != 0) {
        // 0x80132920: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80132908;
    }
    // 0x80132920: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80132924:
    // 0x80132924: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
L_80132928:
    // 0x80132928: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013292C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132930: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
L_80132934:
    // 0x80132934: bne         $at, $zero, L_801328A4
    if (ctx->r1 != 0) {
        // 0x80132938: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801328A4;
    }
    // 0x80132938: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8013293C:
    // 0x8013293C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80132940: bnel        $a2, $t2, L_80132894
    if (ctx->r6 != ctx->r10) {
        // 0x80132944: lw          $a3, 0x4($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X4);
            goto L_80132894;
    }
    goto skip_2;
    // 0x80132944: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
    skip_2:
    // 0x80132948: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8013294C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80132950: jr          $ra
    // 0x80132954: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80132954: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void mnPlayersVSMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134284: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134288: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013428C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134290: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80134294: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80134298: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013429C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801342A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801342A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801342A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801342AC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801342B0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801342B4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801342B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801342BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801342C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801342C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801342C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801342CC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801342D0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801342D4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801342D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801342DC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801342E0: jal         0x8000B93C
    // 0x801342E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801342E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801342E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801342EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801342F0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801342F4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801342F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801342FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134300: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134304: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134308: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013430C: jal         0x80007080
    // 0x80134310: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134310: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013431C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80134320: jal         0x80009968
    // 0x80134324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80134324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80134328: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013432C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80134330: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80134334: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80134338: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013433C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134340: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80134344: jal         0x80009DF4
    // 0x80134348: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80134348: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x8013434C: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80134350: lw          $t4, -0x3B54($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3B54);
    // 0x80134354: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80134358: addiu       $t5, $t5, 0x440
    ctx->r13 = ADD32(ctx->r13, 0X440);
    // 0x8013435C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80134360: jal         0x800CCFDC
    // 0x80134364: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80134364: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80134368: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013436C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134370: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80134374: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80134378: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x8013437C: addiu       $t9, $zero, 0xDC
    ctx->r25 = ADD32(0, 0XDC);
    // 0x80134380: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80134384: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80134388: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x8013438C: sb          $t7, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r15;
    // 0x80134390: sh          $t8, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r24;
    // 0x80134394: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x80134398: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013439C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x801343A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801343A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801343A8: jr          $ra
    // 0x801343AC: nop

    return;
    // 0x801343AC: nop

;}
RECOMP_FUNC void itMSBombAttachedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176B9C: jal         0x80176840
    // 0x80176BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMSBombAttachedInitVars(rdram, ctx);
        goto after_0;
    // 0x80176BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80176BA4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176BA8: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x80176BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176BB0: jal         0x80172EC8
    // 0x80176BB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176BB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80176BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176BC0: jr          $ra
    // 0x80176BC4: nop

    return;
    // 0x80176BC4: nop

;}
RECOMP_FUNC void n_alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FF60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FF68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002FF6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002FF70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002FF74: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8002FF78: beql        $t7, $zero, L_8002FFE8
    if (ctx->r15 == 0) {
        // 0x8002FF7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FFE8;
    }
    goto skip_0;
    // 0x8002FF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FF80: jal         0x8002C618
    // 0x8002FF84: nop

    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002FF84: nop

    after_0:
    // 0x8002FF88: beq         $v0, $zero, L_8002FFE4
    if (ctx->r2 == 0) {
        // 0x8002FF8C: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_8002FFE4;
    }
    // 0x8002FF8C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002FF90: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002FF94: lw          $t8, -0x2CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CEC);
    // 0x8002FF98: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8002FF9C: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8002FFA0: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8002FFA4: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x8002FFA8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x8002FFAC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8002FFB0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8002FFB4: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x8002FFB8: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8002FFBC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002FFC0: jal         0x8002C54C
    // 0x8002FFC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _n_timeToSamples(rdram, ctx);
        goto after_1;
    // 0x8002FFC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8002FFC8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FFCC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FFD0: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x8002FFD4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002FFD8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002FFDC: jal         0x8002A230
    // 0x8002FFE0: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_2;
    // 0x8002FFE0: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    after_2:
L_8002FFE4:
    // 0x8002FFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FFE8:
    // 0x8002FFE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FFEC: jr          $ra
    // 0x8002FFF0: nop

    return;
    // 0x8002FFF0: nop

;}
RECOMP_FUNC void ftCommonGuardUpdateJoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148714: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80148718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014871C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80148720: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80148724: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80148728: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014872C: lw          $s1, 0x8F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X8F4);
    // 0x80148730: addiu       $v1, $s0, 0x8F0
    ctx->r3 = ADD32(ctx->r16, 0X8F0);
    // 0x80148734: lw          $t7, 0x324($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X324);
    // 0x80148738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014873C: addiu       $t8, $t7, 0x24
    ctx->r24 = ADD32(ctx->r15, 0X24);
    // 0x80148740: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80148744: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x80148748: sll         $t2, $t9, 26
    ctx->r10 = S32(ctx->r25 << 26);
    // 0x8014874C: bgezl       $t2, L_8014888C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80148750: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014888C;
    }
    goto skip_0;
    // 0x80148750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80148754: jal         0x80148488
    // 0x80148758: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    ftCommonGuardUpdateShieldAngle(rdram, ctx);
        goto after_0;
    // 0x80148758: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014875C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80148760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80148764: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80148768: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
L_8014876C:
    // 0x8014876C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80148770: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80148774: beq         $t3, $zero, L_80148780
    if (ctx->r11 == 0) {
        // 0x80148778: nop
    
            goto L_80148780;
    }
    // 0x80148778: nop

    // 0x8014877C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80148780:
    // 0x80148780: bne         $v0, $a0, L_8014876C
    if (ctx->r2 != ctx->r4) {
        // 0x80148784: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8014876C;
    }
    // 0x80148784: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80148788: lw          $t5, 0xB28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB28);
    // 0x8014878C: lw          $t4, 0x9C8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X9C8);
    // 0x80148790: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80148794: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80148798: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8014879C: lw          $t8, 0x2DC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2DC);
    // 0x801487A0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801487A4: lw          $a2, 0xB2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB2C);
    // 0x801487A8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x801487AC: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x801487B0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801487B4: jal         0x8000BD1C
    // 0x801487B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x801487B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801487BC: jal         0x8000BFE8
    // 0x801487C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x801487C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801487C4: lw          $t2, 0x18C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X18C);
    // 0x801487C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801487CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801487D0: sll         $t5, $t2, 29
    ctx->r13 = S32(ctx->r10 << 29);
    // 0x801487D4: bgez        $t5, L_801487F0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801487D8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801487F0;
    }
    // 0x801487D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801487DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801487E0: jal         0x800C9488
    // 0x801487E4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    lbCommonPlayTranslateScaledDObjAnim(rdram, ctx);
        goto after_3;
    // 0x801487E4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x801487E8: b           L_801487FC
    // 0x801487EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_801487FC;
    // 0x801487EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_801487F0:
    // 0x801487F0: jal         0x8000CCBC
    // 0x801487F4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x801487F4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_4:
    // 0x801487F8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_801487FC:
    // 0x801487FC: lw          $t4, 0x18C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18C);
    // 0x80148800: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80148804: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80148808: sll         $t7, $t4, 29
    ctx->r15 = S32(ctx->r12 << 29);
    // 0x8014880C: bgez        $t7, L_8014884C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80148810: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8014884C;
    }
    // 0x80148810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80148814: lw          $t8, 0x9C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C8);
    // 0x80148818: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8014881C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80148820: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80148824: lw          $t9, 0x2D8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2D8);
    // 0x80148828: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8014882C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80148830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80148834: lw          $a2, 0xB30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB30);
    // 0x80148838: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8014883C: jal         0x80148664
    // 0x80148840: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    ftCommonGuardGetJointTransformScale(rdram, ctx);
        goto after_5;
    // 0x80148840: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_5:
    // 0x80148844: b           L_8014886C
    // 0x80148848: nop

        goto L_8014886C;
    // 0x80148848: nop

L_8014884C:
    // 0x8014884C: lw          $t2, 0x9C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X9C8);
    // 0x80148850: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80148854: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80148858: lw          $t3, 0x2D8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2D8);
    // 0x8014885C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80148860: lw          $a2, 0xB30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB30);
    // 0x80148864: jal         0x801485CC
    // 0x80148868: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    ftCommonGuardGetJointTransform(rdram, ctx);
        goto after_6;
    // 0x80148868: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    after_6:
L_8014886C:
    // 0x8014886C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80148870: lwc1        $f4, -0x3E0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3E0C);
    // 0x80148874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148878: jal         0x80148408
    // 0x8014887C: swc1        $f4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
    ftCommonGuardUpdateShieldCollision(rdram, ctx);
        goto after_7;
    // 0x8014887C: swc1        $f4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
    after_7:
    // 0x80148880: jal         0x800EB528
    // 0x80148884: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_8;
    // 0x80148884: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    after_8:
    // 0x80148888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014888C:
    // 0x8014888C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80148890: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80148894: jr          $ra
    // 0x80148898: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80148898: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void scManagerFuncDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A26BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A26C0: jal         0x8000A340
    // 0x800A26C4: nop

    gcDrawAll(rdram, ctx);
        goto after_0;
    // 0x800A26C4: nop

    after_0:
    // 0x800A26C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A26CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A26D0: jr          $ra
    // 0x800A26D4: nop

    return;
    // 0x800A26D4: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BA4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132BA8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132BAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132BB0: addiu       $t7, $t7, -0x76EC
    ctx->r15 = ADD32(ctx->r15, -0X76EC);
    // 0x80132BB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80132BB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132BBC: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80132BC0: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_80132BC4:
    // 0x80132BC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132BC8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132BCC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132BD0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132BD4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132BD8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132BDC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132BE0: bne         $t7, $t0, L_80132BC4
    if (ctx->r15 != ctx->r8) {
        // 0x80132BE4: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132BC4;
    }
    // 0x80132BE4: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132BE8: jal         0x8013279C
    // 0x80132BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80132BF0: jal         0x801326C8
    // 0x80132BF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameCheckFighterLocked(rdram, ctx);
        goto after_1;
    // 0x80132BF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80132BF8: beq         $v0, $zero, L_80132C10
    if (ctx->r2 == 0) {
        // 0x80132BFC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132C10;
    }
    // 0x80132BFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132C00: jal         0x801328FC
    // 0x80132C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameMakePortraitShadow(rdram, ctx);
        goto after_2;
    // 0x80132C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80132C08: b           L_80132D50
    // 0x80132C0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132D50;
    // 0x80132C0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132C10:
    // 0x80132C10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C14: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80132C18: jal         0x80009968
    // 0x80132C1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132C1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132C20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132C24: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132C28: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132C2C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80132C30: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132C34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132C38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132C3C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80132C40: jal         0x80009DF4
    // 0x80132C44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132C44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132C48: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80132C4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132C50: addiu       $a1, $a1, 0x255C
    ctx->r5 = ADD32(ctx->r5, 0X255C);
    // 0x80132C54: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    // 0x80132C58: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80132C5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132C60: jal         0x80008188
    // 0x80132C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132C68: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132C6C: lw          $t2, -0x6950($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6950);
    // 0x80132C70: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132C74: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x80132C78: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80132C7C: jal         0x800CCFDC
    // 0x80132C80: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132C80: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132C88: jal         0x801325D8
    // 0x80132C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGameSetPortraitWallpaperPosition(rdram, ctx);
        goto after_7;
    // 0x80132C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80132C90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C98: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132C9C: jal         0x80009968
    // 0x80132CA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x80132CA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80132CA4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80132CA8: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80132CAC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80132CB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132CB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132CB8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132CBC: jal         0x80009DF4
    // 0x80132CC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x80132CC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x80132CC4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132CC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80132CCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132CD0: jal         0x80008188
    // 0x80132CD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x80132CD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80132CD8: jal         0x8013279C
    // 0x80132CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x80132CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80132CE0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80132CE4: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x80132CE8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132CEC: lw          $t7, -0x6950($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6950);
    // 0x80132CF0: lw          $t0, 0x34($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X34);
    // 0x80132CF4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132CF8: jal         0x800CCFDC
    // 0x80132CFC: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_12;
    // 0x80132CFC: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_12:
    // 0x80132D00: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80132D04: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D0C: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x80132D10: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132D14: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80132D18: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132D1C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80132D20: jal         0x8013279C
    // 0x80132D24: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_13;
    // 0x80132D24: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    after_13:
    // 0x80132D28: jal         0x80132550
    // 0x80132D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameCheckFighterCrossed(rdram, ctx);
        goto after_14;
    // 0x80132D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80132D30: beq         $v0, $zero, L_80132D40
    if (ctx->r2 == 0) {
        // 0x80132D34: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_80132D40;
    }
    // 0x80132D34: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132D38: jal         0x80132634
    // 0x80132D3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGamePortraitAddCross(rdram, ctx);
        goto after_15;
    // 0x80132D3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
L_80132D40:
    // 0x80132D40: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80132D44: jal         0x801325D8
    // 0x80132D48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGameSetPortraitWallpaperPosition(rdram, ctx);
        goto after_16;
    // 0x80132D48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80132D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132D50:
    // 0x80132D50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132D54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80132D58: jr          $ra
    // 0x80132D5C: nop

    return;
    // 0x80132D5C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSetGateLUT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E94: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132E98: addiu       $t6, $t6, 0x7324
    ctx->r14 = ADD32(ctx->r14, 0X7324);
    // 0x80132E9C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132EA4: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x80132EA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132EAC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132EB0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80132EB4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80132EB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80132EBC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132EC0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132EC4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80132EC8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80132ECC: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80132ED0: lw          $t2, 0x7DF8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DF8);
    // 0x80132ED4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80132ED8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132EE0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80132EE4: jr          $ra
    // 0x80132EE8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
    return;
    // 0x80132EE8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void gcAddDObjChildRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B5E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B5EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B5F0: jal         0x800093F4
    // 0x8000B5F4: nop

    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000B5F4: nop

    after_0:
    // 0x8000B5F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B5FC: jal         0x8000B434
    // 0x8000B600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyR(rdram, ctx);
        goto after_1;
    // 0x8000B600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B608: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B60C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B610: jr          $ra
    // 0x8000B614: nop

    return;
    // 0x8000B614: nop

;}
RECOMP_FUNC void mnVSResultsGetWinTeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132A34: jal         0x8013234C
    // 0x80132A38: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x80132A38: nop

    after_0:
    // 0x80132A3C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80132A40: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80132A44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132A48: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80132A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132A50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132A54: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132A58: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80132A5C: lbu         $v0, 0x4D2C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4D2C);
    // 0x80132A60: jr          $ra
    // 0x80132A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mpCollisionGetMapObjIDsKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC814: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC818: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800FC81C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FC820: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800FC824: lhu         $v0, 0x14($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X14);
    // 0x800FC828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FC82C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FC830: beq         $v0, $zero, L_800FC88C
    if (ctx->r2 == 0) {
        // 0x800FC834: nop
    
            goto L_800FC88C;
    }
    // 0x800FC834: nop

    // 0x800FC838: blez        $v0, L_800FC88C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FC83C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800FC88C;
    }
    // 0x800FC83C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FC840: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800FC844: addiu       $t0, $t0, 0x1380
    ctx->r8 = ADD32(ctx->r8, 0X1380);
    // 0x800FC848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FC84C:
    // 0x800FC84C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800FC850: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800FC854: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x800FC858: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800FC85C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800FC860: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FC864: bnel        $a2, $t9, L_800FC880
    if (ctx->r6 != ctx->r25) {
        // 0x800FC868: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800FC880;
    }
    goto skip_0;
    // 0x800FC868: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800FC86C: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    // 0x800FC870: lw          $t3, 0x1368($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1368);
    // 0x800FC874: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FC878: lhu         $a1, 0x14($t3)
    ctx->r5 = MEM_HU(ctx->r11, 0X14);
    // 0x800FC87C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800FC880:
    // 0x800FC880: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800FC884: bne         $at, $zero, L_800FC84C
    if (ctx->r1 != 0) {
        // 0x800FC888: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_800FC84C;
    }
    // 0x800FC888: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
L_800FC88C:
    // 0x800FC88C: jr          $ra
    // 0x800FC890: nop

    return;
    // 0x800FC890: nop

;}
RECOMP_FUNC void mpCollisionAllocVertexInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB010: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FB014: lw          $a0, 0x1384($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1384);
    // 0x800FB018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB020: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x800FB024: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800FB028: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800FB02C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800FB030: jal         0x80004980
    // 0x800FB034: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800FB034: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800FB038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB03C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB040: sw          $v0, 0x136C($at)
    MEM_W(0X136C, ctx->r1) = ctx->r2;
    // 0x800FB044: jr          $ra
    // 0x800FB048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FB048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mvOpeningPikachuPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D864: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D868: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D86C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D870: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D874: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D878: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D87C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D880: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D884: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D888: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D88C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D890: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D894: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D898: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D89C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D8A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D8A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8A8: lui         $t7, 0x6EAA
    ctx->r15 = S32(0X6EAA << 16);
    // 0x8018D8AC: ori         $t7, $t7, 0x6EFF
    ctx->r15 = ctx->r15 | 0X6EFF;
    // 0x8018D8B0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8B4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8B8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D8BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8C4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8C8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D8CC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8D0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8D4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8D8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8DC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8E0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8E4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8E8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8EC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8F0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D8F4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8F8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8FC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D900: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D904: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D908: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D90C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D910: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8018D914: lui         $t6, 0xF61B
    ctx->r14 = S32(0XF61B << 16);
    // 0x8018D918: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D91C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D920: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D924: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D928: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D92C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D930: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D934: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D938: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D93C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D940: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D944: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D948: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D94C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D950: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D954: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D958: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D95C: jr          $ra
    // 0x8018D960: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D960: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void ftBossWaitProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158FB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80158FB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80158FBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80158FC0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80158FC4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80158FC8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80158FCC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80158FD0: beql        $t6, $zero, L_80159030
    if (ctx->r14 == 0) {
        // 0x80158FD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80159030;
    }
    goto skip_0;
    // 0x80158FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80158FD8: lw          $a2, 0x74($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X74);
    // 0x80158FDC: addiu       $a1, $s0, 0xB18
    ctx->r5 = ADD32(ctx->r16, 0XB18);
    // 0x80158FE0: jal         0x8001902C
    // 0x80158FE4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80158FE4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_0:
    // 0x80158FE8: jal         0x80018F7C
    // 0x80158FEC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x80158FEC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80158FF0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80158FF4: jal         0x80018EE0
    // 0x80158FF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x80158FF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80158FFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159000: lwc1        $f6, -0x384C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X384C);
    // 0x80159004: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80159008: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8015900C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80159010: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80159014: jal         0x800190B0
    // 0x80159018: nop

    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x80159018: nop

    after_3:
    // 0x8015901C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80159020: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80159024: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80159028: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x8015902C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80159030:
    // 0x80159030: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80159034: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80159038: jr          $ra
    // 0x8015903C: nop

    return;
    // 0x8015903C: nop

;}
RECOMP_FUNC void itCapsuleWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173FD4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80173FD8: jal         0x801735A0
    // 0x80173FDC: addiu       $a1, $a1, 0x4098
    ctx->r5 = ADD32(ctx->r5, 0X4098);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80173FDC: addiu       $a1, $a1, 0x4098
    ctx->r5 = ADD32(ctx->r5, 0X4098);
    after_0:
    // 0x80173FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173FEC: jr          $ra
    // 0x80173FF0: nop

    return;
    // 0x80173FF0: nop

;}
RECOMP_FUNC void unref_80009D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009D04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80009D08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80009D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009D10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009D14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80009D18: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x80009D1C: lbu         $a2, 0xC($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XC);
    // 0x80009D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80009D24: jal         0x80009B48
    // 0x80009D28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcMoveGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009D28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80009D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009D34: jr          $ra
    // 0x80009D38: nop

    return;
    // 0x80009D38: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNCatchSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E648: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E64C: jal         0x800DEE98
    // 0x8015E650: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015E650: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E654: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E658: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015E65C: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015E660: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E664: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E668: jal         0x800E6F24
    // 0x8015E66C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E66C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E678: jr          $ra
    // 0x8015E67C: nop

    return;
    // 0x8015E67C: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeSnap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013268C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132694: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80132698: jal         0x80009968
    // 0x8013269C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013269C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801326A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801326A4: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x801326A8: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x801326AC: addiu       $t7, $t7, -0x3598
    ctx->r15 = ADD32(ctx->r15, -0X3598);
    // 0x801326B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801326B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801326BC: jal         0x8000F120
    // 0x801326C0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x801326C0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x801326C4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801326C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801326CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801326D0: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x801326D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326D8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801326DC: jal         0x80009DF4
    // 0x801326E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801326E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801326E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801326E8: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x801326EC: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x801326F0: addiu       $t0, $t0, -0x3510
    ctx->r8 = ADD32(ctx->r8, -0X3510);
    // 0x801326F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801326FC: jal         0x8000BD8C
    // 0x80132700: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80132700: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80132704: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132708: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x8013270C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132714: jal         0x80008188
    // 0x80132718: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80132718: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8013271C: jal         0x8000DF34
    // 0x80132720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80132720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80132724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132728: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013272C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132730: jr          $ra
    // 0x80132734: nop

    return;
    // 0x80132734: nop

;}
RECOMP_FUNC void ftShadowGetAltitude(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AE10: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013AE14: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8013AE18: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8013AE1C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8013AE20: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8013AE24: nop

    // 0x8013AE28: bc1fl       L_8013AE3C
    if (!c1cs) {
        // 0x8013AE2C: lwc1        $f14, 0x4($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8013AE3C;
    }
    goto skip_0;
    // 0x8013AE2C: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x8013AE30: jr          $ra
    // 0x8013AE34: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    return;
    // 0x8013AE34: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8013AE38: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
L_8013AE3C:
    // 0x8013AE3C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8013AE40: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8013AE44: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8013AE48: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8013AE4C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8013AE50: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8013AE54: add.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8013AE58: jr          $ra
    // 0x8013AE5C: nop

    return;
    // 0x8013AE5C: nop

;}
RECOMP_FUNC void lbParticleAddTransformForStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE1DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE1E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE1E4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CE1E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE1EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CE1F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CE1F4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800CE1F8: jal         0x800CE0D8
    // 0x800CE1FC: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    lbParticleGetTransform(rdram, ctx);
        goto after_0;
    // 0x800CE1FC: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    after_0:
    // 0x800CE200: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CE204: sw          $v0, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->r2;
    // 0x800CE208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE210: jr          $ra
    // 0x800CE214: nop

    return;
    // 0x800CE214: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateBlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105E38: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105E3C: lb          $t6, 0x2D($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X2D);
    // 0x80105E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80105E48: bne         $t6, $at, L_80105EE4
    if (ctx->r14 != ctx->r1) {
        // 0x80105E4C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80105EE4;
    }
    // 0x80105E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105E50: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80105E54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80105E58: lwc1        $f4, 0x78($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X78);
    // 0x80105E5C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80105E60: nop

    // 0x80105E64: bc1fl       L_80105EE8
    if (!c1cs) {
        // 0x80105E68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105EE8;
    }
    goto skip_0;
    // 0x80105E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105E6C: lh          $t8, 0x24($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X24);
    // 0x80105E70: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x80105E74: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80105E78: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80105E7C: lh          $v0, 0x24($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X24);
    // 0x80105E80: beql        $v0, $zero, L_80105E94
    if (ctx->r2 == 0) {
        // 0x80105E84: lw          $t1, 0x8($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X8);
            goto L_80105E94;
    }
    goto skip_1;
    // 0x80105E84: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x80105E88: bnel        $v0, $at, L_80105EE8
    if (ctx->r2 != ctx->r1) {
        // 0x80105E8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105EE8;
    }
    goto skip_2;
    // 0x80105E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80105E90: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
L_80105E94:
    // 0x80105E94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80105E98: sb          $t0, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = ctx->r8;
    // 0x80105E9C: lwc1        $f6, 0x78($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X78);
    // 0x80105EA0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80105EA4: nop

    // 0x80105EA8: bc1f        L_80105EC4
    if (!c1cs) {
        // 0x80105EAC: nop
    
            goto L_80105EC4;
    }
    // 0x80105EAC: nop

    // 0x80105EB0: lbu         $t2, 0x26($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X26);
    // 0x80105EB4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80105EB8: beq         $t2, $at, L_80105EC4
    if (ctx->r10 == ctx->r1) {
        // 0x80105EBC: nop
    
            goto L_80105EC4;
    }
    // 0x80105EBC: nop

    // 0x80105EC0: sb          $zero, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = 0;
L_80105EC4:
    // 0x80105EC4: beql        $v0, $zero, L_80105EE8
    if (ctx->r2 == 0) {
        // 0x80105EC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105EE8;
    }
    goto skip_3;
    // 0x80105EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80105ECC: jal         0x80018994
    // 0x80105ED0: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80105ED0: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_0:
    // 0x80105ED4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105ED8: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105EDC: addiu       $t3, $v0, 0x1E
    ctx->r11 = ADD32(ctx->r2, 0X1E);
    // 0x80105EE0: sh          $t3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r11;
L_80105EE4:
    // 0x80105EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105EE8:
    // 0x80105EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105EEC: jr          $ra
    // 0x80105EF0: nop

    return;
    // 0x80105EF0: nop

;}
RECOMP_FUNC void gcAddChildForDObjTraRotSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F0F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F0F8: jal         0x800093F4
    // 0x8000F0FC: nop

    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F0FC: nop

    after_0:
    // 0x8000F100: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000F104: jal         0x8000F058
    // 0x8000F108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjTransformTraRotSca(rdram, ctx);
        goto after_1;
    // 0x8000F108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000F10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F110: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F118: jr          $ra
    // 0x8000F11C: nop

    return;
    // 0x8000F11C: nop

;}
RECOMP_FUNC void gcFuncGObjByLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AEF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000AEF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AEF8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8000AEFC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000AF00: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x8000AF04: lw          $s0, 0x66F0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66F0);
    // 0x8000AF08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000AF0C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000AF10: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8000AF14: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000AF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000AF1C: beq         $s0, $zero, L_8000AF3C
    if (ctx->r16 == 0) {
        // 0x8000AF20: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_8000AF3C;
    }
    // 0x8000AF20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
L_8000AF24:
    // 0x8000AF24: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000AF28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AF2C: jalr        $s3
    // 0x8000AF30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_0;
    // 0x8000AF30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8000AF34: bne         $s1, $zero, L_8000AF24
    if (ctx->r17 != 0) {
        // 0x8000AF38: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AF24;
    }
    // 0x8000AF38: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000AF3C:
    // 0x8000AF3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AF40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AF44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AF48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AF4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AF50: jr          $ra
    // 0x8000AF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efManagerMBallRaysMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102C34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102C38: jal         0x800FDAFC
    // 0x80102C3C: addiu       $a0, $a0, -0x1AA4
    ctx->r4 = ADD32(ctx->r4, -0X1AA4);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102C3C: addiu       $a0, $a0, -0x1AA4
    ctx->r4 = ADD32(ctx->r4, -0X1AA4);
    after_0:
    // 0x80102C40: bne         $v0, $zero, L_80102C50
    if (ctx->r2 != 0) {
        // 0x80102C44: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102C50;
    }
    // 0x80102C44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102C48: b           L_80102C74
    // 0x80102C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102C74;
    // 0x80102C4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102C50:
    // 0x80102C50: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102C54: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102C58: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102C5C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102C60: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80102C64: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102C68: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80102C6C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102C70: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80102C74:
    // 0x80102C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102C7C: jr          $ra
    // 0x80102C80: nop

    return;
    // 0x80102C80: nop

;}
RECOMP_FUNC void mvOpeningYoshiInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE80: jr          $ra
    // 0x8018DE84: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
    return;
    // 0x8018DE84: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
;}

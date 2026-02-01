#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordMakePortraitStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C60: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80133C64: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133C68: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80133C6C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80133C70: addiu       $t7, $t7, 0x689C
    ctx->r15 = ADD32(ctx->r15, 0X689C);
    // 0x80133C74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133C78: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80133C7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133C80: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80133C84: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80133C88: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
L_80133C8C:
    // 0x80133C8C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133C90: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133C94: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133C98: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133C9C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133CA0: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133CA4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133CA8: bne         $t7, $t0, L_80133C8C
    if (ctx->r15 != ctx->r8) {
        // 0x80133CAC: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133C8C;
    }
    // 0x80133CAC: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133CB0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133CB4: addiu       $t2, $t2, 0x68CC
    ctx->r10 = ADD32(ctx->r10, 0X68CC);
    // 0x80133CB8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80133CBC: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x80133CC0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80133CC4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80133CC8: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80133CCC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133CD0: addiu       $t5, $t5, 0x68D8
    ctx->r13 = ADD32(ctx->r13, 0X68D8);
    // 0x80133CD4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80133CD8: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80133CDC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80133CE0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133CE4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133CE8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80133CEC: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x80133CF0: addiu       $t8, $t8, 0x4D30
    ctx->r24 = ADD32(ctx->r24, 0X4D30);
    // 0x80133CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CF8: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x80133CFC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80133D00: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x80133D04: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x80133D08: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x80133D0C: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x80133D10: sw          $t7, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r15;
    // 0x80133D14: lw          $t0, 0x14($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X14);
    // 0x80133D18: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x80133D1C: lw          $t6, 0x6D88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D88);
    // 0x80133D20: jal         0x800CCFDC
    // 0x80133D24: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80133D24: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    after_0:
    // 0x80133D28: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133D2C: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80133D30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133D34: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80133D38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133D3C: andi        $t2, $t9, 0xFFDF
    ctx->r10 = ctx->r25 & 0XFFDF;
    // 0x80133D40: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133D44: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133D48: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133D4C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133D50: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133D54: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80133D58: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133D5C: lw          $t7, 0x6D90($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D90);
    // 0x80133D60: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133D64: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x80133D68: lw          $t0, 0x6C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C);
    // 0x80133D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133D70: jal         0x800CCFDC
    // 0x80133D74: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133D74: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_1:
    // 0x80133D78: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80133D7C: lui         $at, 0x4264
    ctx->r1 = S32(0X4264 << 16);
    // 0x80133D80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133D84: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80133D88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133D8C: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x80133D90: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80133D94: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80133D98: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133D9C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133DA0: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x80133DA4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80133DA8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80133DAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80133DB0: addiu       $a1, $a1, 0x6A80
    ctx->r5 = ADD32(ctx->r5, 0X6A80);
    // 0x80133DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133DB8: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80133DBC: jal         0x801324C8
    // 0x80133DC0: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    mnVSRecordMakeString(rdram, ctx);
        goto after_2;
    // 0x80133DC0: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    after_2:
    // 0x80133DC4: lui         $a2, 0x4384
    ctx->r6 = S32(0X4384 << 16);
    // 0x80133DC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133DCC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80133DD0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80133DD4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80133DD8: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133DE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80133DE4: lui         $a3, 0x4268
    ctx->r7 = S32(0X4268 << 16);
    // 0x80133DE8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80133DEC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133DF0: jal         0x80131F34
    // 0x80133DF4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_3;
    // 0x80133DF4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // 0x80133DF8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133DFC: lw          $t5, 0x6D88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D88);
    // 0x80133E00: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80133E04: addiu       $t0, $t0, 0x11D0
    ctx->r8 = ADD32(ctx->r8, 0X11D0);
    // 0x80133E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E0C: jal         0x800CCFDC
    // 0x80133E10: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80133E10: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    after_4:
    // 0x80133E14: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80133E18: lui         $at, 0x437B
    ctx->r1 = S32(0X437B << 16);
    // 0x80133E1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133E20: lui         $at, 0x426C
    ctx->r1 = S32(0X426C << 16);
    // 0x80133E24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133E28: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80133E2C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80133E30: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133E34: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80133E38: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80133E3C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133E40: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80133E44: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80133E48: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80133E4C: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x80133E50: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80133E54: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80133E58: jal         0x801339D0
    // 0x80133E5C: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    mnVSRecordGetRanking(rdram, ctx);
        goto after_5;
    // 0x80133E5C: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_5:
    // 0x80133E60: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133E64: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80133E68: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80133E6C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80133E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133E74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133E78: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x80133E7C: lui         $a3, 0x4268
    ctx->r7 = S32(0X4268 << 16);
    // 0x80133E80: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80133E84: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133E88: jal         0x80131F34
    // 0x80133E8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_6;
    // 0x80133E8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
    // 0x80133E90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133E94: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x80133E98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80133E9C: addiu       $a1, $a1, 0x6A88
    ctx->r5 = ADD32(ctx->r5, 0X6A88);
    // 0x80133EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EA4: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80133EA8: jal         0x801324C8
    // 0x80133EAC: lui         $a3, 0x4288
    ctx->r7 = S32(0X4288 << 16);
    mnVSRecordMakeString(rdram, ctx);
        goto after_7;
    // 0x80133EAC: lui         $a3, 0x4288
    ctx->r7 = S32(0X4288 << 16);
    after_7:
    // 0x80133EB0: jal         0x80134978
    // 0x80133EB4: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    mnVSRecordGetUsePercent(rdram, ctx);
        goto after_8;
    // 0x80133EB4: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    after_8:
    // 0x80133EB8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133EBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133EC0: lui         $a2, 0x4384
    ctx->r6 = S32(0X4384 << 16);
    // 0x80133EC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133EC8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80133ECC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133ED0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80133ED4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133ED8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133EDC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80133EE0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133EE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80133EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133EEC: lui         $a3, 0x4284
    ctx->r7 = S32(0X4284 << 16);
    // 0x80133EF0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80133EF4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80133EF8: jal         0x80131F34
    // 0x80133EFC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_9;
    // 0x80133EFC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_9:
    // 0x80133F00: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F04: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x80133F08: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80133F0C: addiu       $a1, $a1, 0x6A90
    ctx->r5 = ADD32(ctx->r5, 0X6A90);
    // 0x80133F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F14: lui         $a2, 0x4315
    ctx->r6 = S32(0X4315 << 16);
    // 0x80133F18: jal         0x801324C8
    // 0x80133F1C: lui         $a3, 0x429C
    ctx->r7 = S32(0X429C << 16);
    mnVSRecordMakeString(rdram, ctx);
        goto after_10;
    // 0x80133F1C: lui         $a3, 0x429C
    ctx->r7 = S32(0X429C << 16);
    after_10:
    // 0x80133F20: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x80133F24: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80133F28: addiu       $t4, $t4, 0x44E0
    ctx->r12 = ADD32(ctx->r12, 0X44E0);
    // 0x80133F2C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80133F30: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80133F34: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80133F38: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80133F3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80133F40: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80133F44: lui         $a2, 0x4384
    ctx->r6 = S32(0X4384 << 16);
    // 0x80133F48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80133F4C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80133F50: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80133F54: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80133F58: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133F5C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x80133F60: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80133F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F68: lui         $a3, 0x4298
    ctx->r7 = S32(0X4298 << 16);
    // 0x80133F6C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80133F70: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133F74: jal         0x80131F34
    // 0x80133F78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_11;
    // 0x80133F78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_11:
    // 0x80133F7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F80: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x80133F84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133F88: addiu       $a1, $a1, 0x6AA0
    ctx->r5 = ADD32(ctx->r5, 0X6AA0);
    // 0x80133F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133F90: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80133F94: jal         0x801324C8
    // 0x80133F98: lui         $a3, 0x42AC
    ctx->r7 = S32(0X42AC << 16);
    mnVSRecordMakeString(rdram, ctx);
        goto after_12;
    // 0x80133F98: lui         $a3, 0x42AC
    ctx->r7 = S32(0X42AC << 16);
    after_12:
    // 0x80133F9C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80133FA0: lui         $a2, 0x4384
    ctx->r6 = S32(0X4384 << 16);
    // 0x80133FA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133FA8: lw          $a1, 0x20($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X20);
    // 0x80133FAC: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80133FB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133FB4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80133FB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133FBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133FC0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80133FC4: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80133FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133FCC: jal         0x80131F34
    // 0x80133FD0: lui         $a3, 0x42A8
    ctx->r7 = S32(0X42A8 << 16);
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_13;
    // 0x80133FD0: lui         $a3, 0x42A8
    ctx->r7 = S32(0X42A8 << 16);
    after_13:
    // 0x80133FD4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80133FD8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80133FDC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80133FE0: jr          $ra
    // 0x80133FE4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80133FE4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void itPakkunCommonCheckNoFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CFDC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8017CFE0: beq         $a0, $zero, L_8017D094
    if (ctx->r4 == 0) {
        // 0x8017CFE4: sdc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
            goto L_8017D094;
    }
    // 0x8017CFE4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8017CFE8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8017CFEC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017CFF0: lw          $v1, 0x66FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66FC);
    // 0x8017CFF4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8017CFF8: lwc1        $f0, 0x350($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X350);
    // 0x8017CFFC: beq         $v1, $zero, L_8017D094
    if (ctx->r3 == 0) {
        // 0x8017D000: lwc1        $f2, 0x354($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X354);
            goto L_8017D094;
    }
    // 0x8017D000: lwc1        $f2, 0x354($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X354);
    // 0x8017D004: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8017D008: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017D00C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D010: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8017D014: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D018: nop

    // 0x8017D01C: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
L_8017D020:
    // 0x8017D020: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x8017D024: lwc1        $f12, 0x1C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8017D028: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8017D02C: nop

    // 0x8017D030: bc1fl       L_8017D048
    if (!c1cs) {
        // 0x8017D034: sub.s       $f14, $f12, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8017D048;
    }
    goto skip_0;
    // 0x8017D034: sub.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
    skip_0:
    // 0x8017D038: sub.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8017D03C: b           L_8017D048
    // 0x8017D040: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_8017D048;
    // 0x8017D040: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8017D044: sub.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f0.fl;
L_8017D048:
    // 0x8017D048: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8017D04C: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017D050: bc1fl       L_8017D08C
    if (!c1cs) {
        // 0x8017D054: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8017D08C;
    }
    goto skip_1;
    // 0x8017D054: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8017D058: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8017D05C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8017D060: nop

    // 0x8017D064: bc1fl       L_8017D08C
    if (!c1cs) {
        // 0x8017D068: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8017D08C;
    }
    goto skip_2;
    // 0x8017D068: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x8017D06C: add.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8017D070: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8017D074: nop

    // 0x8017D078: bc1fl       L_8017D08C
    if (!c1cs) {
        // 0x8017D07C: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_8017D08C;
    }
    goto skip_3;
    // 0x8017D07C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x8017D080: b           L_8017D098
    // 0x8017D084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017D098;
    // 0x8017D084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017D088: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_8017D08C:
    // 0x8017D08C: bnel        $v1, $zero, L_8017D020
    if (ctx->r3 != 0) {
        // 0x8017D090: lw          $v0, 0x84($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X84);
            goto L_8017D020;
    }
    goto skip_4;
    // 0x8017D090: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    skip_4:
L_8017D094:
    // 0x8017D094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017D098:
    // 0x8017D098: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8017D09C: jr          $ra
    // 0x8017D0A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8017D0A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void itMLuckyMakeEggSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801813A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801813AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801813B0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801813B4: addiu       $a1, $a1, -0x501C
    ctx->r5 = ADD32(ctx->r5, -0X501C);
    // 0x801813B8: jal         0x80172EC8
    // 0x801813BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801813BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x801813C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801813C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801813C8: jr          $ra
    // 0x801813CC: nop

    return;
    // 0x801813CC: nop

;}
RECOMP_FUNC void itNessPKFireCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185358: jal         0x8018579C
    // 0x8018535C: nop

    itNessPKFireFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x8018535C: nop

    after_0:
    // 0x80185360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185368: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018536C: jr          $ra
    // 0x80185370: nop

    return;
    // 0x80185370: nop

;}
RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80000404: lui         $t1, 0x6
    ctx->r9 = S32(0X6 << 16);
    // 0x80000408: addiu       $t0, $t0, -0x530
    ctx->r8 = ADD32(ctx->r8, -0X530);
    // 0x8000040C: ori         $t1, $t1, 0x1EA0
    ctx->r9 = ctx->r9 | 0X1EA0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80000428: lui         $sp, 0x8004
    ctx->r29 = S32(0X8004 << 16);
    // 0x8000042C: addiu       $t2, $t2, 0x870
    ctx->r10 = ADD32(ctx->r10, 0X870);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, -0x330
    ctx->r29 = ADD32(ctx->r29, -0X330);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, -0x330
    ctx->r29 = ADD32(ctx->r29, -0X330);
    // 0x80000438: nop

    // 0x8000043C: nop

    // 0x80000440: nop

    // 0x80000444: nop

    // 0x80000448: nop

    // 0x8000044C: nop

    // 0x80000450: nop

    // 0x80000454: nop

    // 0x80000458: nop

    // 0x8000045C: nop

;}
RECOMP_FUNC void mnVSResultsGetManCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801379C4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801379C8: lbu         $t6, 0x4D2A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D2A);
    // 0x801379CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801379D0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x801379D4: bne         $t6, $zero, L_801379E0
    if (ctx->r14 != 0) {
        // 0x801379D8: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_801379E0;
    }
    // 0x801379D8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x801379DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801379E0:
    // 0x801379E0: lbu         $t7, 0x4D9E($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D9E);
    // 0x801379E4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x801379E8: bne         $t7, $zero, L_801379F4
    if (ctx->r15 != 0) {
        // 0x801379EC: nop
    
            goto L_801379F4;
    }
    // 0x801379EC: nop

    // 0x801379F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801379F4:
    // 0x801379F4: lbu         $t8, 0x4E12($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4E12);
    // 0x801379F8: bne         $t8, $zero, L_80137A04
    if (ctx->r24 != 0) {
        // 0x801379FC: nop
    
            goto L_80137A04;
    }
    // 0x801379FC: nop

    // 0x80137A00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80137A04:
    // 0x80137A04: lbu         $t9, 0x4E86($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4E86);
    // 0x80137A08: bne         $t9, $zero, L_80137A14
    if (ctx->r25 != 0) {
        // 0x80137A0C: nop
    
            goto L_80137A14;
    }
    // 0x80137A0C: nop

    // 0x80137A10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80137A14:
    // 0x80137A14: jr          $ra
    // 0x80137A18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80137A18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8002AD90_2B990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD90: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8002AD94: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002AD98: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002AD9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002ADA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002ADA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002ADA8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002ADAC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002ADB0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002ADB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002ADB8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8002ADBC: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002ADC0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8002ADC4: nop

    // 0x8002ADC8: bc1fl       L_8002ADE8
    if (!c1cs) {
        // 0x8002ADCC: swc1        $f0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
            goto L_8002ADE8;
    }
    goto skip_0;
    // 0x8002ADCC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8002ADD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002ADD4: nop

    // 0x8002ADD8: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002ADDC: b           L_8002ADE8
    // 0x8002ADE0: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
        goto L_8002ADE8;
    // 0x8002ADE0: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8002ADE4: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_8002ADE8:
    // 0x8002ADE8: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002ADEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002ADF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002ADF4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002ADF8: nop

    // 0x8002ADFC: bc1fl       L_8002AE0C
    if (!c1cs) {
        // 0x8002AE00: sub.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
            goto L_8002AE0C;
    }
    goto skip_1;
    // 0x8002AE00: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    skip_1:
    // 0x8002AE04: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002AE08: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
L_8002AE0C:
    // 0x8002AE0C: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8002AE10: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8002AE14: jr          $ra
    // 0x8002AE18: nop

    return;
    // 0x8002AE18: nop

;}
RECOMP_FUNC void gcLinkGObjDLCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009D7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009D80: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80009D84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009D88: slti        $at, $a2, 0x40
    ctx->r1 = SIGNED(ctx->r6) < 0X40 ? 1 : 0;
    // 0x80009D8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009D90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009D94: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80009D98: bne         $at, $zero, L_80009DBC
    if (ctx->r1 != 0) {
        // 0x80009D9C: or          $t6, $a2, $zero
        ctx->r14 = ctx->r6 | 0;
            goto L_80009DBC;
    }
    // 0x80009D9C: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x80009DA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009DA4: addiu       $a0, $a0, -0x249C
    ctx->r4 = ADD32(ctx->r4, -0X249C);
    // 0x80009DA8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80009DAC: jal         0x80023624
    // 0x80009DB0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80009DB0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80009DB4:
    // 0x80009DB4: b           L_80009DB4
    pause_self(rdram);
    // 0x80009DB8: nop

L_80009DBC:
    // 0x80009DBC: sb          $a2, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r6;
    // 0x80009DC0: sw          $a3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r7;
    // 0x80009DC4: sw          $a1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r5;
    // 0x80009DC8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80009DCC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80009DD0: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
    // 0x80009DD4: lw          $t8, -0x4918($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4918);
    // 0x80009DD8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80009DDC: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
    // 0x80009DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80009DEC: jr          $ra
    // 0x80009DF0: nop

    return;
    // 0x80009DF0: nop

;}
RECOMP_FUNC void func_ovl8_803745BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803745BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803745C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803745C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803745C8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803745CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803745D0: jal         0x803717A0
    // 0x803745D4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803745D4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x803745D8: beq         $v0, $zero, L_8037460C
    if (ctx->r2 == 0) {
        // 0x803745DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037460C;
    }
    // 0x803745DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803745E0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x803745E4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x803745E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803745EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803745F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803745F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803745F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803745FC: jal         0x8037EF0C
    // 0x80374600: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8037EF0C(rdram, ctx);
        goto after_1;
    // 0x80374600: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x80374604: b           L_80374610
    // 0x80374608: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80374610;
    // 0x80374608: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8037460C:
    // 0x8037460C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80374610:
    // 0x80374610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80374614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80374618: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037461C: jr          $ra
    // 0x80374620: nop

    return;
    // 0x80374620: nop

;}
RECOMP_FUNC void sc1PGameBossSetBossPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801926F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801926FC: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80192700: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80192704: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80192708: lbu         $t6, 0x23($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X23);
    // 0x8019270C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80192710: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80192714: bne         $v1, $t6, L_80192720
    if (ctx->r3 != ctx->r14) {
        // 0x80192718: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80192720;
    }
    // 0x80192718: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8019271C: sw          $zero, 0x38EC($at)
    MEM_W(0X38EC, ctx->r1) = 0;
L_80192720:
    // 0x80192720: lbu         $t7, 0x97($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X97);
    // 0x80192724: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80192728: bnel        $v1, $t7, L_80192738
    if (ctx->r3 != ctx->r15) {
        // 0x8019272C: lbu         $t9, 0x10B($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X10B);
            goto L_80192738;
    }
    goto skip_0;
    // 0x8019272C: lbu         $t9, 0x10B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10B);
    skip_0:
    // 0x80192730: sw          $t8, 0x38EC($at)
    MEM_W(0X38EC, ctx->r1) = ctx->r24;
    // 0x80192734: lbu         $t9, 0x10B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10B);
L_80192738:
    // 0x80192738: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8019273C: bnel        $v1, $t9, L_8019274C
    if (ctx->r3 != ctx->r25) {
        // 0x80192740: lbu         $t1, 0x17F($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X17F);
            goto L_8019274C;
    }
    goto skip_1;
    // 0x80192740: lbu         $t1, 0x17F($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17F);
    skip_1:
    // 0x80192744: sw          $t0, 0x38EC($at)
    MEM_W(0X38EC, ctx->r1) = ctx->r8;
    // 0x80192748: lbu         $t1, 0x17F($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17F);
L_8019274C:
    // 0x8019274C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80192750: bne         $v1, $t1, L_8019275C
    if (ctx->r3 != ctx->r9) {
        // 0x80192754: nop
    
            goto L_8019275C;
    }
    // 0x80192754: nop

    // 0x80192758: sw          $t2, 0x38EC($at)
    MEM_W(0X38EC, ctx->r1) = ctx->r10;
L_8019275C:
    // 0x8019275C: jr          $ra
    // 0x80192760: nop

    return;
    // 0x80192760: nop

;}
RECOMP_FUNC void syMatrixRotR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BBF8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001BBFC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BC00: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001BC04: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001BC08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BC0C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001BC10: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001BC14: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001BC18: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001BC1C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001BC20: jal         0x8001BA78
    // 0x8001BC24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixRotRF(rdram, ctx);
        goto after_0;
    // 0x8001BC24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001BC28: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001BC2C: jal         0x80019EA0
    // 0x8001BC30: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001BC30: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001BC34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BC38: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001BC3C: jr          $ra
    // 0x8001BC40: nop

    return;
    // 0x8001BC40: nop

;}
RECOMP_FUNC void ftCommonAttack100StartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F0D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014F0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F0D8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014F0DC: jal         0x800D9480
    // 0x8014F0E0: addiu       $a1, $a1, -0xC40
    ctx->r5 = ADD32(ctx->r5, -0XC40);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F0E0: addiu       $a1, $a1, -0xC40
    ctx->r5 = ADD32(ctx->r5, -0XC40);
    after_0:
    // 0x8014F0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F0E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014F0EC: jr          $ra
    // 0x8014F0F0: nop

    return;
    // 0x8014F0F0: nop

;}
RECOMP_FUNC void ftFoxSpecialLwLoopSetReflectFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CD7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015CD80: lbu         $t7, 0x18C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18C);
    // 0x8015CD84: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8015CD88: jr          $ra
    // 0x8015CD8C: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    return;
    // 0x8015CD8C: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void syDebugDebugPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002315C: or          $a1, $sp, $zero
    ctx->r5 = ctx->r29 | 0;
    // 0x80023160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023164: addiu       $a1, $a1, 0x27
    ctx->r5 = ADD32(ctx->r5, 0X27);
    // 0x80023168: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002316C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80023170: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80023174: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80023178: jal         0x80023024
    // 0x8002317C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    syDebugFramebufferVPrintfNewLine(rdram, ctx);
        goto after_0;
    // 0x8002317C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    after_0:
    // 0x80023180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80023188: jr          $ra
    // 0x8002318C: nop

    return;
    // 0x8002318C: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320F8: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x801320FC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80132100: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80132104: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132108: addiu       $s7, $sp, 0x10C
    ctx->r23 = ADD32(ctx->r29, 0X10C);
    // 0x8013210C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80132110: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80132114: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80132118: addiu       $t6, $t6, -0x7948
    ctx->r14 = ADD32(ctx->r14, -0X7948);
    // 0x8013211C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80132120: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80132124: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80132128: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8013212C: addiu       $fp, $sp, 0x98
    ctx->r30 = ADD32(ctx->r29, 0X98);
    // 0x80132130: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80132134: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80132138: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8013213C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80132140: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80132144: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80132148: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8013214C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80132150: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80132154: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80132158: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013215C: addiu       $t0, $t6, 0x6C
    ctx->r8 = ADD32(ctx->r14, 0X6C);
    // 0x80132160: or          $t9, $s7, $zero
    ctx->r25 = ctx->r23 | 0;
L_80132164:
    // 0x80132164: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132168: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013216C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132170: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132174: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132178: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013217C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132180: bne         $t6, $t0, L_80132164
    if (ctx->r14 != ctx->r8) {
        // 0x80132184: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132164;
    }
    // 0x80132184: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132188: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013218C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132190: addiu       $t1, $t1, -0x78D4
    ctx->r9 = ADD32(ctx->r9, -0X78D4);
    // 0x80132194: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80132198: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013219C: addiu       $t5, $t1, 0x6C
    ctx->r13 = ADD32(ctx->r9, 0X6C);
    // 0x801321A0: or          $t4, $fp, $zero
    ctx->r12 = ctx->r30 | 0;
    // 0x801321A4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
L_801321A8:
    // 0x801321A8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801321AC: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x801321B0: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x801321B4: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x801321B8: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x801321BC: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x801321C0: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x801321C4: bne         $t1, $t5, L_801321A8
    if (ctx->r9 != ctx->r13) {
        // 0x801321C8: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_801321A8;
    }
    // 0x801321C8: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x801321CC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801321D0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x801321D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801321D8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801321DC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801321E0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x801321E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801321E8: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x801321EC: lbu         $t0, 0x0($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X0);
    // 0x801321F0: lw          $s3, 0x190($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X190);
    // 0x801321F4: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x801321F8: beq         $t0, $zero, L_8013233C
    if (ctx->r8 == 0) {
        // 0x801321FC: andi        $a0, $t0, 0xFF
        ctx->r4 = ctx->r8 & 0XFF;
            goto L_8013233C;
    }
    // 0x801321FC: andi        $a0, $t0, 0xFF
    ctx->r4 = ctx->r8 & 0XFF;
    // 0x80132200: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80132204: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132208: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8013220C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132210: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80132214: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80132218:
    // 0x80132218: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x8013221C: bne         $at, $zero, L_80132238
    if (ctx->r1 != 0) {
        // 0x80132220: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80132238;
    }
    // 0x80132220: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80132224: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80132228: beq         $at, $zero, L_80132238
    if (ctx->r1 == 0) {
        // 0x8013222C: nop
    
            goto L_80132238;
    }
    // 0x8013222C: nop

    // 0x80132230: b           L_80132238
    // 0x80132234: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132238;
    // 0x80132234: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80132238:
    // 0x80132238: bne         $v1, $zero, L_80132248
    if (ctx->r3 != 0) {
        // 0x8013223C: nop
    
            goto L_80132248;
    }
    // 0x8013223C: nop

    // 0x80132240: bne         $s4, $v0, L_8013226C
    if (ctx->r20 != ctx->r2) {
        // 0x80132244: nop
    
            goto L_8013226C;
    }
    // 0x80132244: nop

L_80132248:
    // 0x80132248: bne         $s4, $v0, L_80132258
    if (ctx->r20 != ctx->r2) {
        // 0x8013224C: addiu       $t6, $v0, -0x30
        ctx->r14 = ADD32(ctx->r2, -0X30);
            goto L_80132258;
    }
    // 0x8013224C: addiu       $t6, $v0, -0x30
    ctx->r14 = ADD32(ctx->r2, -0X30);
    // 0x80132250: b           L_80132328
    // 0x80132254: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
        goto L_80132328;
    // 0x80132254: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
L_80132258:
    // 0x80132258: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013225C: nop

    // 0x80132260: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132264: b           L_80132328
    // 0x80132268: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
        goto L_80132328;
    // 0x80132268: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_8013226C:
    // 0x8013226C: jal         0x80131F5C
    // 0x80132270: nop

    mnPlayers1PGameGetCharacterID(rdram, ctx);
        goto after_0;
    // 0x80132270: nop

    after_0:
    // 0x80132274: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80132278: addu        $t7, $s7, $t9
    ctx->r15 = ADD32(ctx->r23, ctx->r25);
    // 0x8013227C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80132280: lw          $t5, -0x6940($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6940);
    // 0x80132284: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132288: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8013228C: jal         0x800CCFDC
    // 0x80132290: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132290: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    after_1:
    // 0x80132294: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132298: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x8013229C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801322A0: jal         0x80131FD4
    // 0x801322A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameGetCharacterSpacing(rdram, ctx);
        goto after_2;
    // 0x801322A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x801322A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801322AC: jal         0x80131F5C
    // 0x801322B0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    mnPlayers1PGameGetCharacterID(rdram, ctx);
        goto after_3;
    // 0x801322B0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_3:
    // 0x801322B4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801322B8: addu        $t4, $fp, $t1
    ctx->r12 = ADD32(ctx->r30, ctx->r9);
    // 0x801322BC: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801322C0: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x801322C4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x801322C8: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x801322CC: beq         $v1, $at, L_801322E8
    if (ctx->r3 == ctx->r1) {
        // 0x801322D0: add.s       $f20, $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
            goto L_801322E8;
    }
    // 0x801322D0: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x801322D4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x801322D8: beql        $v1, $at, L_801322F8
    if (ctx->r3 == ctx->r1) {
        // 0x801322DC: add.s       $f18, $f24, $f28
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f28.fl;
            goto L_801322F8;
    }
    goto skip_0;
    // 0x801322DC: add.s       $f18, $f24, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f28.fl;
    skip_0:
    // 0x801322E0: b           L_801322FC
    // 0x801322E4: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
        goto L_801322FC;
    // 0x801322E4: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
L_801322E8:
    // 0x801322E8: sub.s       $f16, $f24, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f30.fl;
    // 0x801322EC: b           L_801322FC
    // 0x801322F0: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
        goto L_801322FC;
    // 0x801322F0: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
    // 0x801322F4: add.s       $f18, $f24, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f28.fl;
L_801322F8:
    // 0x801322F8: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
L_801322FC:
    // 0x801322FC: lhu         $t2, 0x24($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X24);
    // 0x80132300: andi        $t0, $t2, 0xFFDF
    ctx->r8 = ctx->r10 & 0XFFDF;
    // 0x80132304: sh          $t0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r8;
    // 0x80132308: ori         $t6, $t0, 0x1
    ctx->r14 = ctx->r8 | 0X1;
    // 0x8013230C: sh          $t6, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r14;
    // 0x80132310: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80132314: sb          $t9, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r25;
    // 0x80132318: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x8013231C: sb          $t7, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r15;
    // 0x80132320: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
    // 0x80132324: sb          $t8, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r24;
L_80132328:
    // 0x80132328: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8013232C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80132330: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80132334: bne         $a0, $zero, L_80132218
    if (ctx->r4 != 0) {
        // 0x80132338: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80132218;
    }
    // 0x80132338: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8013233C:
    // 0x8013233C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80132340: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132344: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80132348: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8013234C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80132350: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80132354: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80132358: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8013235C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80132360: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80132364: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80132368: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8013236C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80132370: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80132374: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80132378: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8013237C: jr          $ra
    // 0x80132380: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    return;
    // 0x80132380: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
;}
RECOMP_FUNC void ftBossCommonUpdateDamageStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801586A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801586A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801586A8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801586AC: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x801586B0: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x801586B4: beq         $v0, $at, L_80158738
    if (ctx->r2 == ctx->r1) {
        // 0x801586B8: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80158738;
    }
    // 0x801586B8: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x801586BC: beq         $v0, $at, L_80158738
    if (ctx->r2 == ctx->r1) {
        // 0x801586C0: addiu       $at, $zero, 0xFB
        ctx->r1 = ADD32(0, 0XFB);
            goto L_80158738;
    }
    // 0x801586C0: addiu       $at, $zero, 0xFB
    ctx->r1 = ADD32(0, 0XFB);
    // 0x801586C4: beql        $v0, $at, L_8015873C
    if (ctx->r2 == ctx->r1) {
        // 0x801586C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015873C;
    }
    goto skip_0;
    // 0x801586C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801586CC: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x801586D0: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x801586D4: bnel        $at, $zero, L_80158724
    if (ctx->r1 != 0) {
        // 0x801586D8: slti        $at, $v0, 0xC8
        ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
            goto L_80158724;
    }
    goto skip_1;
    // 0x801586D8: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    skip_1:
    // 0x801586DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801586E0: jal         0x8018F75C
    // 0x801586E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    sc1PGameBossDefeatInitInterface(rdram, ctx);
        goto after_0;
    // 0x801586E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801586E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801586EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801586F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801586F4: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x801586F8: bne         $t6, $at, L_80158710
    if (ctx->r14 != ctx->r1) {
        // 0x801586FC: nop
    
            goto L_80158710;
    }
    // 0x801586FC: nop

    // 0x80158700: jal         0x8015AD74
    // 0x80158704: nop

    ftBossDeadLeftSetStatus(rdram, ctx);
        goto after_1;
    // 0x80158704: nop

    after_1:
    // 0x80158708: b           L_8015873C
    // 0x8015870C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015873C;
    // 0x8015870C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158710:
    // 0x80158710: jal         0x8015AE80
    // 0x80158714: nop

    ftBossDeadRightSetStatus(rdram, ctx);
        goto after_2;
    // 0x80158714: nop

    after_2:
    // 0x80158718: b           L_8015873C
    // 0x8015871C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015873C;
    // 0x8015871C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80158720: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
L_80158724:
    // 0x80158724: bne         $at, $zero, L_80158738
    if (ctx->r1 != 0) {
        // 0x80158728: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80158738;
    }
    // 0x80158728: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8015872C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80158730: lw          $t7, 0xADC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XADC);
    // 0x80158734: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
L_80158738:
    // 0x80158738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015873C:
    // 0x8015873C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80158740: jr          $ra
    // 0x80158744: nop

    return;
    // 0x80158744: nop

;}
RECOMP_FUNC void func_80020EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EF8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80020EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020F00: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80020F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020F08: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020F0C: bne         $at, $zero, L_80020F18
    if (ctx->r1 != 0) {
        // 0x80020F10: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80020F18;
    }
    // 0x80020F10: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80020F14: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_80020F18:
    // 0x80020F18: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020F1C: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x80020F20: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80020F24: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80020F28: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80020F2C: beql        $a0, $zero, L_80020F40
    if (ctx->r4 == 0) {
        // 0x80020F30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020F40;
    }
    goto skip_0;
    // 0x80020F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80020F34: jal         0x80026104
    // 0x80020F38: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    func_80026104_26D04(rdram, ctx);
        goto after_0;
    // 0x80020F38: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x80020F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80020F40:
    // 0x80020F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020F44: jr          $ra
    // 0x80020F48: nop

    return;
    // 0x80020F48: nop

;}
RECOMP_FUNC void func_8002C700_2D300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C700: jr          $ra
    // 0x8002C704: nop

    return;
    // 0x8002C704: nop

;}
RECOMP_FUNC void ftCommonHammerKneeBendCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014800C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80148010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80148018: jal         0x8013F474
    // 0x8014801C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_0;
    // 0x8014801C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80148020: beq         $v0, $zero, L_80148038
    if (ctx->r2 == 0) {
        // 0x80148024: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80148038;
    }
    // 0x80148024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80148028: jal         0x80147F88
    // 0x8014802C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerKneeBendSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014802C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80148030: b           L_8014803C
    // 0x80148034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014803C;
    // 0x80148034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80148038:
    // 0x80148038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014803C:
    // 0x8014803C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80148044: jr          $ra
    // 0x80148048: nop

    return;
    // 0x80148048: nop

;}
RECOMP_FUNC void func_ovl8_80382DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382DF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80382DF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80382DFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382E04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80382E08: bne         $a0, $zero, L_80382E20
    if (ctx->r4 != 0) {
        // 0x80382E0C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80382E20;
    }
    // 0x80382E0C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80382E10: jal         0x803717A0
    // 0x80382E14: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382E14: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80382E18: beq         $v0, $zero, L_80382E94
    if (ctx->r2 == 0) {
        // 0x80382E1C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382E94;
    }
    // 0x80382E1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80382E20:
    // 0x80382E20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80382E24: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80382E28: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80382E2C: bnel        $t6, $zero, L_80382E50
    if (ctx->r14 != 0) {
        // 0x80382E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80382E50;
    }
    goto skip_0;
    // 0x80382E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80382E34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382E38: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80382E3C: jal         0x803717E0
    // 0x80382E40: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80382E40: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80382E44: jal         0x8037C2D0
    // 0x80382E48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80382E48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80382E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80382E50:
    // 0x80382E50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80382E54: jal         0x80373C10
    // 0x80382E58: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_80373C10(rdram, ctx);
        goto after_3;
    // 0x80382E58: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80382E5C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382E60: addiu       $t7, $t7, -0x3870
    ctx->r15 = ADD32(ctx->r15, -0X3870);
    // 0x80382E64: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80382E68: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80382E6C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80382E70: addiu       $t8, $t8, -0x3770
    ctx->r24 = ADD32(ctx->r24, -0X3770);
    // 0x80382E74: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80382E78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80382E7C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80382E80: addiu       $t0, $t0, -0x3618
    ctx->r8 = ADD32(ctx->r8, -0X3618);
    // 0x80382E84: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x80382E88: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80382E8C: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80382E90: sh          $t2, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r10;
L_80382E94:
    // 0x80382E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382E98: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382E9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382EA0: jr          $ra
    // 0x80382EA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80382EA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void syTaskmanInitGeneralHeap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004954: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80004958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000495C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80004960: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004964: addiu       $a0, $a0, 0x65E8
    ctx->r4 = ADD32(ctx->r4, 0X65E8);
    // 0x80004968: jal         0x80006D54
    // 0x8000496C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    syMallocInit(rdram, ctx);
        goto after_0;
    // 0x8000496C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x80004970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004978: jr          $ra
    // 0x8000497C: nop

    return;
    // 0x8000497C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801337C0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801337C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801337C8: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x801337CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801337D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801337D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801337D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x801337DC: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x801337E0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_801337E4:
    // 0x801337E4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801337E8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801337EC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801337F0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801337F4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801337F8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801337FC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133800: bne         $t7, $t0, L_801337E4
    if (ctx->r15 != ctx->r8) {
        // 0x80133804: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801337E4;
    }
    // 0x80133804: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133808: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013380C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80133810: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133814: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80133818: beql        $t1, $at, L_80133990
    if (ctx->r9 == ctx->r1) {
        // 0x8013381C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80133990;
    }
    goto skip_0;
    // 0x8013381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80133820: beql        $s0, $zero, L_8013384C
    if (ctx->r16 == 0) {
        // 0x80133824: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8013384C;
    }
    goto skip_1;
    // 0x80133824: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x80133828: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x8013382C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133830: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x80133834: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80133838: jal         0x800D78E8
    // 0x8013383C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    ftManagerDestroyFighter(rdram, ctx);
        goto after_0;
    // 0x8013383C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80133840: b           L_80133854
    // 0x80133844: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
        goto L_80133854;
    // 0x80133844: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80133848: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8013384C:
    // 0x8013384C: nop

    // 0x80133850: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_80133854:
    // 0x80133854: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80133858: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013385C: addiu       $t0, $t0, -0x7AA8
    ctx->r8 = ADD32(ctx->r8, -0X7AA8);
    // 0x80133860: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133864: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80133868: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8013386C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80133870: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80133874: addu        $v1, $t5, $t0
    ctx->r3 = ADD32(ctx->r13, ctx->r8);
    // 0x80133878: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8013387C: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x80133880: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80133884: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80133888: sw          $t7, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r15;
    // 0x8013388C: sb          $a3, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r7;
    // 0x80133890: sb          $zero, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = 0;
    // 0x80133894: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80133898: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8013389C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801338A0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x801338A4: jal         0x800D7F3C
    // 0x801338A8: sb          $t8, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r24;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801338A8: sb          $t8, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r24;
    after_1:
    // 0x801338AC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801338B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801338B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801338B8: addiu       $a1, $a1, 0x367C
    ctx->r5 = ADD32(ctx->r5, 0X367C);
    // 0x801338BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801338C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801338C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801338C8: jal         0x80008188
    // 0x801338CC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801338CC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    after_2:
    // 0x801338D0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801338D4: lw          $t1, -0x776C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X776C);
    // 0x801338D8: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x801338DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801338E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801338E4: bne         $t9, $t1, L_80133910
    if (ctx->r25 != ctx->r9) {
        // 0x801338E8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80133910;
    }
    // 0x801338E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801338EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801338F0: lwc1        $f8, -0x7ADC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7ADC);
    // 0x801338F4: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801338F8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801338FC: swc1        $f8, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f8.u32l;
    // 0x80133900: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80133904: lwc1        $f10, -0x7AD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7AD8);
    // 0x80133908: b           L_8013392C
    // 0x8013390C: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
        goto L_8013392C;
    // 0x8013390C: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
L_80133910:
    // 0x80133910: lwc1        $f16, -0x7AD4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7AD4);
    // 0x80133914: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80133918: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013391C: swc1        $f16, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f16.u32l;
    // 0x80133920: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80133924: lwc1        $f18, -0x7AD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7AD0);
    // 0x80133928: swc1        $f18, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f18.u32l;
L_8013392C:
    // 0x8013392C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80133930: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80133934: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80133938: addiu       $t8, $t8, 0xD90
    ctx->r24 = ADD32(ctx->r24, 0XD90);
    // 0x8013393C: swc1        $f4, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f4.u32l;
    // 0x80133940: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80133944: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80133948: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x8013394C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80133950: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80133954: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133958: swc1        $f6, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f6.u32l;
    // 0x8013395C: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80133960: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133964: swc1        $f8, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f8.u32l;
    // 0x80133968: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x8013396C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133970: swc1        $f10, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f10.u32l;
    // 0x80133974: lw          $t4, -0x7768($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7768);
    // 0x80133978: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8013397C: bnel        $t3, $t4, L_80133990
    if (ctx->r11 != ctx->r12) {
        // 0x80133980: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80133990;
    }
    goto skip_2;
    // 0x80133980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80133984: jal         0x800E9814
    // 0x80133988: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x80133988: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8013398C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80133990:
    // 0x80133990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133994: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80133998: jr          $ra
    // 0x8013399C: nop

    return;
    // 0x8013399C: nop

;}
RECOMP_FUNC void efManagerSparkleWhiteDeadMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100720: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100724: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80100728: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010072C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80100730: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100734: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80100738: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010073C: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x80100740: jal         0x800CE9E8
    // 0x80100744: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80100744: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    after_0:
    // 0x80100748: beq         $v0, $zero, L_801007C0
    if (ctx->r2 == 0) {
        // 0x8010074C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801007C0;
    }
    // 0x8010074C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100750: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100754: jal         0x800CE1DC
    // 0x80100758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80100758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8010075C: beq         $v0, $zero, L_801007B4
    if (ctx->r2 == 0) {
        // 0x80100760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801007B4;
    }
    // 0x80100760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100764: jal         0x800CEA14
    // 0x80100768: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80100768: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010076C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80100770: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80100774: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80100778: bnel        $t6, $zero, L_8010078C
    if (ctx->r14 != 0) {
        // 0x8010077C: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_8010078C;
    }
    goto skip_0;
    // 0x8010077C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80100780: b           L_801007C4
    // 0x80100784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801007C4;
    // 0x80100784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100788: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_8010078C:
    // 0x8010078C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80100790: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80100794: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80100798: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8010079C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801007A0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801007A4: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x801007A8: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x801007AC: b           L_801007C0
    // 0x801007B0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_801007C0;
    // 0x801007B0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_801007B4:
    // 0x801007B4: jal         0x800CEA40
    // 0x801007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x801007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801007BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801007C0:
    // 0x801007C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_801007C4:
    // 0x801007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801007C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801007CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801007D0: jr          $ra
    // 0x801007D4: nop

    return;
    // 0x801007D4: nop

;}
RECOMP_FUNC void mnSoundTestUpdateOptionColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131B04: lw          $v1, 0x4308($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4308);
    // 0x80131B08: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B0C: addiu       $a3, $t7, 0x4330
    ctx->r7 = ADD32(ctx->r15, 0X4330);
    // 0x80131B10: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80131B14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131B18: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131B1C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131B20: addiu       $t0, $t0, 0x433C
    ctx->r8 = ADD32(ctx->r8, 0X433C);
    // 0x80131B24: addiu       $a2, $a2, 0x4320
    ctx->r6 = ADD32(ctx->r6, 0X4320);
    // 0x80131B28: addiu       $a1, $a1, 0x4310
    ctx->r5 = ADD32(ctx->r5, 0X4310);
    // 0x80131B2C: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    // 0x80131B30: addiu       $v1, $zero, 0xA8
    ctx->r3 = ADD32(0, 0XA8);
    // 0x80131B34: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80131B38: addiu       $t2, $zero, 0x45
    ctx->r10 = ADD32(0, 0X45);
    // 0x80131B3C: addiu       $t1, $zero, 0x7D
    ctx->r9 = ADD32(0, 0X7D);
    // 0x80131B40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80131B44:
    // 0x80131B44: bnel        $a3, $a0, L_80131B60
    if (ctx->r7 != ctx->r4) {
        // 0x80131B48: sw          $t1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r9;
            goto L_80131B60;
    }
    goto skip_0;
    // 0x80131B48: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    skip_0:
    // 0x80131B4C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80131B50: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80131B54: b           L_80131B68
    // 0x80131B58: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80131B68;
    // 0x80131B58: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80131B5C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80131B60:
    // 0x80131B60: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80131B64: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
L_80131B68:
    // 0x80131B68: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80131B6C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80131B70: bne         $a3, $t0, L_80131B44
    if (ctx->r7 != ctx->r8) {
        // 0x80131B74: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80131B44;
    }
    // 0x80131B74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80131B78: jr          $ra
    // 0x80131B7C: nop

    return;
    // 0x80131B7C: nop

;}
RECOMP_FUNC void grYamabukiInitGroundVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B250: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010B254: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8010B258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B25C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B264: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8010B268: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8010B26C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010B270: addiu       $t8, $t8, 0x8A0
    ctx->r24 = ADD32(ctx->r24, 0X8A0);
    // 0x8010B274: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x8010B278: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8010B27C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8010B280: jal         0x800FC58C
    // 0x8010B284: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_0;
    // 0x8010B284: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8010B288: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8010B28C: sh          $t0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r8;
    // 0x8010B290: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8010B294: lw          $t1, 0x1300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1300);
    // 0x8010B298: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x8010B29C: addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // 0x8010B2A0: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8010B2A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010B2A8: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x8010B2AC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8010B2B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B2B4: sw          $t4, -0x14A0($at)
    MEM_W(-0X14A0, ctx->r1) = ctx->r12;
    // 0x8010B2B8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8010B2BC: sb          $t5, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r13;
    // 0x8010B2C0: jal         0x8010AE68
    // 0x8010B2C4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    grYamabukiGateSetPositionNear(rdram, ctx);
        goto after_1;
    // 0x8010B2C4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8010B2C8: jal         0x8010B1AC
    // 0x8010B2CC: nop

    grYamabukiMakeGate(rdram, ctx);
        goto after_2;
    // 0x8010B2CC: nop

    after_2:
    // 0x8010B2D0: jal         0x8010B108
    // 0x8010B2D4: nop

    grYamabukiGateUpdateYakumonoPos(rdram, ctx);
        goto after_3;
    // 0x8010B2D4: nop

    after_3:
    // 0x8010B2D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B2DC: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x8010B2E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B2E4: jr          $ra
    // 0x8010B2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010B2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PGameCheckCursorPuckGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135E30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80135E34: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80135E38: addiu       $s1, $s1, -0x7118
    ctx->r17 = ADD32(ctx->r17, -0X7118);
    // 0x80135E3C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135E40: lw          $t6, -0x708C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X708C);
    // 0x80135E44: lw          $t7, 0x34($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X34);
    // 0x80135E48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80135E4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80135E50: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80135E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135E58: bne         $at, $zero, L_80135E6C
    if (ctx->r1 != 0) {
        // 0x80135E5C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80135E6C;
    }
    // 0x80135E5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80135E60: lw          $t8, 0x30($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X30);
    // 0x80135E64: beql        $t8, $zero, L_80135E78
    if (ctx->r24 == 0) {
        // 0x80135E68: lw          $t9, 0x28($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X28);
            goto L_80135E78;
    }
    goto skip_0;
    // 0x80135E68: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    skip_0:
L_80135E6C:
    // 0x80135E6C: b           L_80135F20
    // 0x80135E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135F20;
    // 0x80135E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135E74: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
L_80135E78:
    // 0x80135E78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80135E7C: beql        $t9, $at, L_80135E90
    if (ctx->r25 == ctx->r1) {
        // 0x80135E80: lw          $t0, 0x50($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X50);
            goto L_80135E90;
    }
    goto skip_1;
    // 0x80135E80: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
    skip_1:
    // 0x80135E84: b           L_80135F20
    // 0x80135E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80135F20;
    // 0x80135E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135E8C: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
L_80135E90:
    // 0x80135E90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135E94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80135E98: bne         $t0, $at, L_80135F1C
    if (ctx->r8 != ctx->r1) {
        // 0x80135E9C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80135F1C;
    }
    // 0x80135E9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135EA0: jal         0x80135724
    // 0x80135EA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayers1PGameCheckPuckInRange(rdram, ctx);
        goto after_0;
    // 0x80135EA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80135EA8: beq         $v0, $zero, L_80135F1C
    if (ctx->r2 == 0) {
        // 0x80135EAC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80135F1C;
    }
    // 0x80135EAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135EB0: sw          $s0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->r16;
    // 0x80135EB4: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x80135EB8: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x80135EBC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135EC0: sw          $s0, -0x70C4($at)
    MEM_W(-0X70C4, ctx->r1) = ctx->r16;
    // 0x80135EC4: sw          $zero, 0x58($s1)
    MEM_W(0X58, ctx->r17) = 0;
    // 0x80135EC8: jal         0x80135804
    // 0x80135ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameUpdateFighter(rdram, ctx);
        goto after_1;
    // 0x80135ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80135ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135ED4: jal         0x80135C88
    // 0x80135ED8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGameUpdateCursorGrabPriorities(rdram, ctx);
        goto after_2;
    // 0x80135ED8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80135EDC: jal         0x80135D58
    // 0x80135EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameSetCursorPuckOffset(rdram, ctx);
        goto after_3;
    // 0x80135EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80135EE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80135EE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135EEC: jal         0x801352BC
    // 0x80135EF0: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x80135EF0: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    after_4:
    // 0x80135EF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135EF8: sw          $t2, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r10;
    // 0x80135EFC: jal         0x800269C0
    // 0x80135F00: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80135F00: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_5:
    // 0x80135F04: jal         0x80135924
    // 0x80135F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameDestroyPortraitFlash(rdram, ctx);
        goto after_6;
    // 0x80135F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80135F0C: jal         0x801358C4
    // 0x80135F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameUpdateNameAndEmblem(rdram, ctx);
        goto after_7;
    // 0x80135F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80135F14: b           L_80135F20
    // 0x80135F18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135F20;
    // 0x80135F18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135F1C:
    // 0x80135F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135F20:
    // 0x80135F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135F24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80135F28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80135F2C: jr          $ra
    // 0x80135F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80135F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ifCommonBattleSetGameStatusWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114958: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8011495C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80114960: jr          $ra
    // 0x80114964: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    return;
    // 0x80114964: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
;}
RECOMP_FUNC void func_ovl8_8037D518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D518: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037D51C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D520: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037D524: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8037D528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D52C: beq         $a0, $zero, L_8037D5A4
    if (ctx->r4 == 0) {
        // 0x8037D530: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037D5A4;
    }
    // 0x8037D530: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037D534: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8037D538: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8037D53C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_8037D540:
    // 0x8037D540: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8037D544: subu        $t8, $t1, $t7
    ctx->r24 = SUB32(ctx->r9, ctx->r15);
    // 0x8037D548: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8037D54C: srav        $t2, $t6, $t9
    ctx->r10 = S32(SIGNED(ctx->r14) >> (ctx->r25 & 31));
    // 0x8037D550: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8037D554: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037D558: sb          $t3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r11;
    // 0x8037D55C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037D560: andi        $t4, $a1, 0x3
    ctx->r12 = ctx->r5 & 0X3;
    // 0x8037D564: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8037D568: bne         $t1, $t4, L_8037D578
    if (ctx->r9 != ctx->r12) {
        // 0x8037D56C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037D578;
    }
    // 0x8037D56C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D574: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8037D578:
    // 0x8037D578: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037D57C: bne         $v1, $t0, L_8037D598
    if (ctx->r3 != ctx->r8) {
        // 0x8037D580: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8037D598;
    }
    // 0x8037D580: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8037D584: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8037D588: beq         $v1, $zero, L_8037D594
    if (ctx->r3 == 0) {
        // 0x8037D58C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8037D594;
    }
    // 0x8037D58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D590: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8037D594:
    // 0x8037D594: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037D598:
    // 0x8037D598: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037D59C: bnel        $a0, $zero, L_8037D540
    if (ctx->r4 != 0) {
        // 0x8037D5A0: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_8037D540;
    }
    goto skip_0;
    // 0x8037D5A0: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_0:
L_8037D5A4:
    // 0x8037D5A4: jr          $ra
    // 0x8037D5A8: nop

    return;
    // 0x8037D5A8: nop

;}
RECOMP_FUNC void func_ovl8_8037E6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E6F4: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037E6F8: addiu       $a1, $a1, -0xFB8
    ctx->r5 = ADD32(ctx->r5, -0XFB8);
    // 0x8037E6FC: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x8037E700: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037E704: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037E708: andi        $t7, $t6, 0xFF00
    ctx->r15 = ctx->r14 & 0XFF00;
    // 0x8037E70C: beq         $t7, $zero, L_8037E724
    if (ctx->r15 == 0) {
        // 0x8037E710: andi        $t8, $a0, 0x80
        ctx->r24 = ctx->r4 & 0X80;
            goto L_8037E724;
    }
    // 0x8037E710: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x8037E714: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8037E718: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037E71C: jr          $ra
    // 0x8037E720: lhu         $v0, -0xFDE($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0XFDE);
    return;
    // 0x8037E720: lhu         $v0, -0xFDE($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0XFDE);
L_8037E724:
    // 0x8037E724: beq         $t8, $zero, L_8037E73C
    if (ctx->r24 == 0) {
        // 0x8037E728: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8037E73C;
    }
    // 0x8037E728: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037E72C: sll         $t0, $a0, 8
    ctx->r8 = S32(ctx->r4 << 8);
    // 0x8037E730: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8037E734: jr          $ra
    // 0x8037E738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8037E738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037E73C:
    // 0x8037E73C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8037E740: bne         $at, $zero, L_8037E74C
    if (ctx->r1 != 0) {
        // 0x8037E744: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_8037E74C;
    }
    // 0x8037E744: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8037E748: bne         $at, $zero, L_8037E75C
    if (ctx->r1 != 0) {
        // 0x8037E74C: slti        $at, $v0, 0xA0
        ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
            goto L_8037E75C;
    }
L_8037E74C:
    // 0x8037E74C: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // 0x8037E750: bne         $at, $zero, L_8037E79C
    if (ctx->r1 != 0) {
        // 0x8037E754: slti        $at, $v0, 0xE0
        ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
            goto L_8037E79C;
    }
    // 0x8037E754: slti        $at, $v0, 0xE0
    ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
    // 0x8037E758: beq         $at, $zero, L_8037E79C
    if (ctx->r1 == 0) {
        // 0x8037E75C: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_8037E79C;
    }
L_8037E75C:
    // 0x8037E75C: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8037E760: bne         $at, $zero, L_8037E770
    if (ctx->r1 != 0) {
        // 0x8037E764: lui         $a1, 0x8039
        ctx->r5 = S32(0X8039 << 16);
            goto L_8037E770;
    }
    // 0x8037E764: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037E768: b           L_8037E774
    // 0x8037E76C: addiu       $a0, $v0, -0x41
    ctx->r4 = ADD32(ctx->r2, -0X41);
        goto L_8037E774;
    // 0x8037E76C: addiu       $a0, $v0, -0x41
    ctx->r4 = ADD32(ctx->r2, -0X41);
L_8037E770:
    // 0x8037E770: addiu       $a0, $v0, -0x20
    ctx->r4 = ADD32(ctx->r2, -0X20);
L_8037E774:
    // 0x8037E774: addiu       $a1, $a1, -0xFF8
    ctx->r5 = ADD32(ctx->r5, -0XFF8);
    // 0x8037E778: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x8037E77C: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8037E780: lhu         $t3, 0x2($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X2);
    // 0x8037E784: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8037E788: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8037E78C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8037E790: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8037E794: jr          $ra
    // 0x8037E798: subu        $v0, $t5, $t6
    ctx->r2 = SUB32(ctx->r13, ctx->r14);
    return;
    // 0x8037E798: subu        $v0, $t5, $t6
    ctx->r2 = SUB32(ctx->r13, ctx->r14);
L_8037E79C:
    // 0x8037E79C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037E7A0: jr          $ra
    // 0x8037E7A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8037E7A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void scStaffrollHighlightProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132144: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80132148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013214C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80132150: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80132154: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80132158: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8013215C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80132160: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132164: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80132168: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013216C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132170: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80132174: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80132178: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8013217C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132180: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132184: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80132188: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8013218C: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132190: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132194: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80132198: lui         $t0, 0x30
    ctx->r8 = S32(0X30 << 16);
    // 0x8013219C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801321A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801321A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801321A8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801321AC: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801321B0: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x801321B4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801321B8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801321BC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801321C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801321C4: lui         $t5, 0x8001
    ctx->r13 = S32(0X8001 << 16);
    // 0x801321C8: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801321CC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801321D0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801321D4: ori         $t5, $t5, 0x8001
    ctx->r13 = ctx->r13 | 0X8001;
    // 0x801321D8: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x801321DC: addiu       $s2, $s2, -0x5714
    ctx->r18 = ADD32(ctx->r18, -0X5714);
    // 0x801321E0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801321E4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x801321E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x801321EC: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x801321F0: addiu       $s3, $s3, -0x5710
    ctx->r19 = ADD32(ctx->r19, -0X5710);
    // 0x801321F4: negu        $at, $t7
    ctx->r1 = SUB32(0, ctx->r15);
    // 0x801321F8: sll         $t8, $at, 4
    ctx->r24 = S32(ctx->r1 << 4);
    // 0x801321FC: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x80132200: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80132204: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x80132208: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8013220C: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80132210: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80132214: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132218: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8013221C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80132220: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80132224: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80132228: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8013222C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80132230: jal         0x801320F4
    // 0x80132234: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_0;
    // 0x80132234: nop

    after_0:
    // 0x80132238: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8013223C: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80132240: addiu       $s4, $s4, -0x570C
    ctx->r20 = ADD32(ctx->r20, -0X570C);
    // 0x80132244: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132248: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8013224C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80132250: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80132254: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80132258: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8013225C: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80132260: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80132264: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80132268: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013226C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132270: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132274: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132278: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8013227C: jal         0x8013211C
    // 0x80132280: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_1;
    // 0x80132280: nop

    after_1:
    // 0x80132284: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x80132288: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8013228C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80132290: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80132294: andi        $t8, $s1, 0x3FF
    ctx->r24 = ctx->r17 & 0X3FF;
    // 0x80132298: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8013229C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801322A0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x801322A4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x801322A8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x801322AC: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801322B0: negu        $at, $t2
    ctx->r1 = SUB32(0, ctx->r10);
    // 0x801322B4: sll         $t3, $at, 4
    ctx->r11 = S32(ctx->r1 << 4);
    // 0x801322B8: subu        $t3, $t3, $at
    ctx->r11 = SUB32(ctx->r11, ctx->r1);
    // 0x801322BC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801322C0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x801322C4: nop

    // 0x801322C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801322CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801322D0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801322D4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801322D8: jal         0x801320F4
    // 0x801322DC: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_2;
    // 0x801322DC: nop

    after_2:
    // 0x801322E0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x801322E4: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801322E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801322EC: negu        $at, $t5
    ctx->r1 = SUB32(0, ctx->r13);
    // 0x801322F0: sll         $t6, $at, 2
    ctx->r14 = S32(ctx->r1 << 2);
    // 0x801322F4: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x801322F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801322FC: addu        $t6, $t6, $at
    ctx->r14 = ADD32(ctx->r14, ctx->r1);
    // 0x80132300: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80132304: nop

    // 0x80132308: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013230C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80132310: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132314: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80132318: jal         0x8013211C
    // 0x8013231C: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_3;
    // 0x8013231C: nop

    after_3:
    // 0x80132320: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80132324: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x80132328: andi        $t0, $s1, 0x3FF
    ctx->r8 = ctx->r17 & 0X3FF;
    // 0x8013232C: sll         $t1, $t0, 14
    ctx->r9 = S32(ctx->r8 << 14);
    // 0x80132330: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80132334: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80132338: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8013233C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80132340: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80132344: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80132348: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8013234C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80132350: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x80132354: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80132358: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8013235C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80132360: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132364: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80132368: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013236C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80132370: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80132374: jal         0x801320F4
    // 0x80132378: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_4;
    // 0x80132378: nop

    after_4:
    // 0x8013237C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80132380: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80132384: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80132388: negu        $at, $t0
    ctx->r1 = SUB32(0, ctx->r8);
    // 0x8013238C: sll         $t9, $at, 2
    ctx->r25 = S32(ctx->r1 << 2);
    // 0x80132390: subu        $t9, $t9, $at
    ctx->r25 = SUB32(ctx->r25, ctx->r1);
    // 0x80132394: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80132398: addu        $t9, $t9, $at
    ctx->r25 = ADD32(ctx->r25, ctx->r1);
    // 0x8013239C: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x801323A0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801323A4: nop

    // 0x801323A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801323AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801323B0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801323B4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801323B8: jal         0x8013211C
    // 0x801323BC: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_5;
    // 0x801323BC: nop

    after_5:
    // 0x801323C0: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x801323C4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x801323C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801323CC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x801323D0: andi        $t6, $s1, 0x3FF
    ctx->r14 = ctx->r17 & 0X3FF;
    // 0x801323D4: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x801323D8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801323DC: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x801323E0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x801323E4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x801323E8: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801323EC: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x801323F0: sll         $t1, $at, 4
    ctx->r9 = S32(ctx->r1 << 4);
    // 0x801323F4: subu        $t1, $t1, $at
    ctx->r9 = SUB32(ctx->r9, ctx->r1);
    // 0x801323F8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801323FC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80132400: nop

    // 0x80132404: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132408: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013240C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80132410: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80132414: jal         0x801320F4
    // 0x80132418: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_6;
    // 0x80132418: nop

    after_6:
    // 0x8013241C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80132420: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80132424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80132428: negu        $at, $t3
    ctx->r1 = SUB32(0, ctx->r11);
    // 0x8013242C: sll         $t4, $at, 2
    ctx->r12 = S32(ctx->r1 << 2);
    // 0x80132430: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x80132434: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80132438: addu        $t4, $t4, $at
    ctx->r12 = ADD32(ctx->r12, ctx->r1);
    // 0x8013243C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80132440: nop

    // 0x80132444: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132448: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013244C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132450: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80132454: jal         0x8013211C
    // 0x80132458: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_7;
    // 0x80132458: nop

    after_7:
    // 0x8013245C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80132460: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x80132464: andi        $t7, $s1, 0x3FF
    ctx->r15 = ctx->r17 & 0X3FF;
    // 0x80132468: sll         $t0, $t7, 14
    ctx->r8 = S32(ctx->r15 << 14);
    // 0x8013246C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80132470: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x80132474: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80132478: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8013247C: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80132480: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80132484: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80132488: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8013248C: addiu       $t6, $t4, 0x2
    ctx->r14 = ADD32(ctx->r12, 0X2);
    // 0x80132490: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80132494: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80132498: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8013249C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801324A0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x801324A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801324A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801324AC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801324B0: jal         0x801320F4
    // 0x801324B4: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_8;
    // 0x801324B4: nop

    after_8:
    // 0x801324B8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x801324BC: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801324C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801324C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801324C8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801324CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801324D0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801324D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801324D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801324DC: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x801324E0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801324E4: nop

    // 0x801324E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801324EC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801324F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801324F4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801324F8: jal         0x8013211C
    // 0x801324FC: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_9;
    // 0x801324FC: nop

    after_9:
    // 0x80132500: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x80132504: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80132508: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8013250C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80132510: andi        $t4, $s1, 0x3FF
    ctx->r12 = ctx->r17 & 0X3FF;
    // 0x80132514: sll         $t6, $t4, 14
    ctx->r14 = S32(ctx->r12 << 14);
    // 0x80132518: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8013251C: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x80132520: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80132524: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80132528: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8013252C: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x80132530: sll         $t0, $at, 4
    ctx->r8 = S32(ctx->r1 << 4);
    // 0x80132534: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x80132538: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8013253C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80132540: nop

    // 0x80132544: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132548: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8013254C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80132550: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80132554: jal         0x801320F4
    // 0x80132558: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_10;
    // 0x80132558: nop

    after_10:
    // 0x8013255C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80132560: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80132564: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80132568: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8013256C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80132570: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80132574: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80132578: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8013257C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80132580: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80132584: nop

    // 0x80132588: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013258C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132590: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80132594: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80132598: jal         0x8013211C
    // 0x8013259C: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_11;
    // 0x8013259C: nop

    after_11:
    // 0x801325A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801325A4: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x801325A8: andi        $t5, $s1, 0x3FF
    ctx->r13 = ctx->r17 & 0X3FF;
    // 0x801325AC: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x801325B0: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801325B4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x801325B8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x801325BC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x801325C0: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801325C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801325C8: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x801325CC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801325D0: addiu       $t4, $t2, 0x2
    ctx->r12 = ADD32(ctx->r10, 0X2);
    // 0x801325D4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801325D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801325DC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801325E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801325E4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x801325E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801325EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801325F0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x801325F4: jal         0x801320F4
    // 0x801325F8: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_12;
    // 0x801325F8: nop

    after_12:
    // 0x801325FC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80132600: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80132604: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80132608: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8013260C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80132610: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132614: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80132618: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013261C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80132620: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80132624: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80132628: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013262C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132630: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132634: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132638: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8013263C: jal         0x8013211C
    // 0x80132640: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_13;
    // 0x80132640: nop

    after_13:
    // 0x80132644: andi        $t0, $v0, 0x3FF
    ctx->r8 = ctx->r2 & 0X3FF;
    // 0x80132648: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8013264C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80132650: andi        $t2, $s1, 0x3FF
    ctx->r10 = ctx->r17 & 0X3FF;
    // 0x80132654: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x80132658: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x8013265C: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x80132660: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80132664: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80132668: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8013266C: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x80132670: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80132674: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80132678: nop

    // 0x8013267C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132680: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80132684: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80132688: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8013268C: jal         0x801320F4
    // 0x80132690: nop

    scStaffrollGetLockOnPositionX(rdram, ctx);
        goto after_14;
    // 0x80132690: nop

    after_14:
    // 0x80132694: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80132698: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8013269C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801326A0: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x801326A4: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x801326A8: subu        $t0, $t0, $at
    ctx->r8 = SUB32(ctx->r8, ctx->r1);
    // 0x801326AC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801326B0: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x801326B4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801326B8: nop

    // 0x801326BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801326C0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801326C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801326C8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801326CC: jal         0x8013211C
    // 0x801326D0: nop

    scStaffrollGetLockOnPositionY(rdram, ctx);
        goto after_15;
    // 0x801326D0: nop

    after_15:
    // 0x801326D4: andi        $t2, $v0, 0x3FF
    ctx->r10 = ctx->r2 & 0X3FF;
    // 0x801326D8: andi        $t4, $s1, 0x3FF
    ctx->r12 = ctx->r17 & 0X3FF;
    // 0x801326DC: sll         $t3, $t4, 14
    ctx->r11 = S32(ctx->r12 << 14);
    // 0x801326E0: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x801326E4: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x801326E8: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x801326EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801326F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801326F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801326F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801326FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80132700: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132704: jr          $ra
    // 0x80132708: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80132708: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mvOpeningRunInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013225C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132260: jr          $ra
    // 0x80132264: sw          $zero, 0x273C($at)
    MEM_W(0X273C, ctx->r1) = 0;
    return;
    // 0x80132264: sw          $zero, 0x273C($at)
    MEM_W(0X273C, ctx->r1) = 0;
;}
RECOMP_FUNC void ftMainUpdateCatchStatFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E2B8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2B90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E2B94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E2B98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800E2B9C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x800E2BA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E2BA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E2BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E2BAC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E2BB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E2BB4: jal         0x800E26BC
    // 0x800E2BB8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_0;
    // 0x800E2BB8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x800E2BBC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800E2BC0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E2BC8: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800E2BCC: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x800E2BD0: lwc1        $f0, 0x1C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E2BD4: lwc1        $f2, 0x1C($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x800E2BD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800E2BDC: nop

    // 0x800E2BE0: bc1fl       L_800E2BF8
    if (!c1cs) {
        // 0x800E2BE4: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800E2BF8;
    }
    goto skip_0;
    // 0x800E2BE4: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x800E2BE8: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800E2BEC: b           L_800E2BF8
    // 0x800E2BF0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800E2BF8;
    // 0x800E2BF0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800E2BF4: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_800E2BF8:
    // 0x800E2BF8: lwc1        $f4, 0x834($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X834);
    // 0x800E2BFC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800E2C00: nop

    // 0x800E2C04: bc1fl       L_800E2C18
    if (!c1cs) {
        // 0x800E2C08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E2C18;
    }
    goto skip_1;
    // 0x800E2C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800E2C0C: swc1        $f12, 0x834($a0)
    MEM_W(0X834, ctx->r4) = ctx->f12.u32l;
    // 0x800E2C10: sw          $v0, 0x830($a0)
    MEM_W(0X830, ctx->r4) = ctx->r2;
    // 0x800E2C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E2C18:
    // 0x800E2C18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E2C1C: jr          $ra
    // 0x800E2C20: nop

    return;
    // 0x800E2C20: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttackFighterDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F03B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F03BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F03C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F03C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F03C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800F03CC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x800F03D0: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800F03D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F03D8: jal         0x800EDE00
    // 0x800F03DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800F03DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800F03E0: jal         0x800EDE5C
    // 0x800F03E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800F03E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F03E8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800F03EC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800F03F0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800F03F4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800F03F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800F03FC: lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X2C);
    // 0x800F0400: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800F0404: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800F0408: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800F040C: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x800F0410: addiu       $t3, $t0, 0x14
    ctx->r11 = ADD32(ctx->r8, 0X14);
    // 0x800F0414: addiu       $t4, $t0, 0x20
    ctx->r12 = ADD32(ctx->r8, 0X20);
    // 0x800F0418: addiu       $t2, $t1, 0x9C
    ctx->r10 = ADD32(ctx->r9, 0X9C);
    // 0x800F041C: addiu       $t5, $t1, 0x90
    ctx->r13 = ADD32(ctx->r9, 0X90);
    // 0x800F0420: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800F0424: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800F0428: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800F042C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800F0430: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F0434: jal         0x800EE300
    // 0x800F0438: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    gmCollisionTestRectangle(rdram, ctx);
        goto after_2;
    // 0x800F0438: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    after_2:
    // 0x800F043C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F0440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0444: jr          $ra
    // 0x800F0448: nop

    return;
    // 0x800F0448: nop

;}
RECOMP_FUNC void mnNoControllerSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6660: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D6664: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x800D6668: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x800D666C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D6670: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D6674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6678: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x800D667C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x800D6680: addiu       $t8, $t8, 0x67D8
    ctx->r24 = ADD32(ctx->r24, 0X67D8);
    // 0x800D6684: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x800D6688: addiu       $t0, $t0, 0x6AF8
    ctx->r8 = ADD32(ctx->r8, 0X6AF8);
    // 0x800D668C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x800D6690: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800D6694: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800D6698: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D669C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D66A0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800D66A4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800D66A8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800D66AC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800D66B0: jal         0x800CDF78
    // 0x800D66B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x800D66B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800D66B8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D66BC: addiu       $a0, $a0, 0x67B0
    ctx->r4 = ADD32(ctx->r4, 0X67B0);
    // 0x800D66C0: jal         0x800CDEEC
    // 0x800D66C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x800D66C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800D66C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D66CC: jal         0x80004980
    // 0x800D66D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x800D66D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x800D66D4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D66D8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D66DC: addiu       $a2, $a2, 0x67D0
    ctx->r6 = ADD32(ctx->r6, 0X67D0);
    // 0x800D66E0: addiu       $a0, $a0, 0x67B0
    ctx->r4 = ADD32(ctx->r4, 0X67B0);
    // 0x800D66E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D66E8: jal         0x800CDE04
    // 0x800D66EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x800D66EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x800D66F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D66F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D66F8: jr          $ra
    // 0x800D66FC: nop

    return;
    // 0x800D66FC: nop

;}
RECOMP_FUNC void wpMainReflectorSetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801680EC: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x801680F0: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801680F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801680F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801680FC: nop

    // 0x80168100: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80168104: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80168108: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8016810C: nop

    // 0x80168110: bc1f        L_80168120
    if (!c1cs) {
        // 0x80168114: nop
    
            goto L_80168120;
    }
    // 0x80168114: nop

    // 0x80168118: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8016811C: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
L_80168120:
    // 0x80168120: jr          $ra
    // 0x80168124: nop

    return;
    // 0x80168124: nop

;}
RECOMP_FUNC void mn1PModeMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801323B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801323B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801323C4: jal         0x80009968
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801323D0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801323D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801323D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323DC: addiu       $a1, $a1, 0x226C
    ctx->r5 = ADD32(ctx->r5, 0X226C);
    // 0x801323E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801323E8: jal         0x80009DF4
    // 0x801323EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801323EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801323F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801323F4: lw          $t7, 0x3290($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3290);
    // 0x801323F8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801323FC: addiu       $t8, $t8, 0x31F8
    ctx->r24 = ADD32(ctx->r24, 0X31F8);
    // 0x80132400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132404: jal         0x800CCFDC
    // 0x80132408: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132408: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013240C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132410: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80132414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132418: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x8013241C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132420: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132424: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132428: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013242C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132430: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132434: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132438: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013243C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132440: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132444: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132448: lw          $t3, 0x3294($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3294);
    // 0x8013244C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132450: addiu       $t4, $t4, 0x5338
    ctx->r12 = ADD32(ctx->r12, 0X5338);
    // 0x80132454: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132458: jal         0x800CCFDC
    // 0x8013245C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013245C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80132460: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80132464: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x80132468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013246C: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80132470: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132474: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80132478: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x8013247C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80132480: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132484: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132488: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013248C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132490: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132494: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132498: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8013249C: lw          $t9, 0x3290($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3290);
    // 0x801324A0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801324A4: addiu       $t0, $t0, -0x2DC0
    ctx->r8 = ADD32(ctx->r8, -0X2DC0);
    // 0x801324A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801324AC: jal         0x800CCFDC
    // 0x801324B0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801324B0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x801324B4: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801324B8: lui         $at, 0x433C
    ctx->r1 = S32(0X433C << 16);
    // 0x801324BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801324C0: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x801324C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801324C8: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801324CC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801324D0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801324D4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801324D8: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801324DC: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801324E0: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801324E4: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801324E8: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801324EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801324F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801324F4: jr          $ra
    // 0x801324F8: nop

    return;
    // 0x801324F8: nop

;}
RECOMP_FUNC void dbMenuUpdateMenuInputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369240: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80369244: lb          $v1, 0x5478($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5478);
    // 0x80369248: lui         $a2, 0x8037
    ctx->r6 = S32(0X8037 << 16);
    // 0x8036924C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80369250: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80369254: bne         $at, $zero, L_80369260
    if (ctx->r1 != 0) {
        // 0x80369258: addiu       $a2, $a2, -0x6034
        ctx->r6 = ADD32(ctx->r6, -0X6034);
            goto L_80369260;
    }
    // 0x80369258: addiu       $a2, $a2, -0x6034
    ctx->r6 = ADD32(ctx->r6, -0X6034);
    // 0x8036925C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80369260:
    // 0x80369260: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
    // 0x80369264: beq         $at, $zero, L_80369274
    if (ctx->r1 == 0) {
        // 0x80369268: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_80369274;
    }
    // 0x80369268: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8036926C: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // 0x80369270: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80369274:
    // 0x80369274: lb          $v1, 0x5479($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5479);
    // 0x80369278: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8036927C: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x80369280: bnel        $at, $zero, L_80369294
    if (ctx->r1 != 0) {
        // 0x80369284: slti        $at, $v1, -0x28
        ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
            goto L_80369294;
    }
    goto skip_0;
    // 0x80369284: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
    skip_0:
    // 0x80369288: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // 0x8036928C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80369290: slti        $at, $v1, -0x28
    ctx->r1 = SIGNED(ctx->r3) < -0X28 ? 1 : 0;
L_80369294:
    // 0x80369294: beq         $at, $zero, L_803692A4
    if (ctx->r1 == 0) {
        // 0x80369298: lui         $v1, 0x8037
        ctx->r3 = S32(0X8037 << 16);
            goto L_803692A4;
    }
    // 0x80369298: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x8036929C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x803692A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_803692A4:
    // 0x803692A4: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x803692A8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803692AC: addiu       $a1, $a1, -0x6030
    ctx->r5 = ADD32(ctx->r5, -0X6030);
    // 0x803692B0: xor         $a0, $v0, $t6
    ctx->r4 = ctx->r2 ^ ctx->r14;
    // 0x803692B4: and         $t7, $a0, $v0
    ctx->r15 = ctx->r4 & ctx->r2;
    // 0x803692B8: beq         $a0, $zero, L_803692D4
    if (ctx->r4 == 0) {
        // 0x803692BC: sh          $t7, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r15;
            goto L_803692D4;
    }
    // 0x803692BC: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x803692C0: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x803692C4: addiu       $v1, $v1, -0x6028
    ctx->r3 = ADD32(ctx->r3, -0X6028);
    // 0x803692C8: sh          $t7, -0x602C($at)
    MEM_H(-0X602C, ctx->r1) = ctx->r15;
    // 0x803692CC: b           L_80369308
    // 0x803692D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80369308;
    // 0x803692D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_803692D4:
    // 0x803692D4: lui         $v1, 0x8037
    ctx->r3 = S32(0X8037 << 16);
    // 0x803692D8: addiu       $v1, $v1, -0x6028
    ctx->r3 = ADD32(ctx->r3, -0X6028);
    // 0x803692DC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x803692E0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x803692E4: blez        $t1, L_803692F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x803692E8: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_803692F8;
    }
    // 0x803692E8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x803692EC: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x803692F0: b           L_80369308
    // 0x803692F4: sh          $zero, -0x602C($at)
    MEM_H(-0X602C, ctx->r1) = 0;
        goto L_80369308;
    // 0x803692F4: sh          $zero, -0x602C($at)
    MEM_H(-0X602C, ctx->r1) = 0;
L_803692F8:
    // 0x803692F8: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x803692FC: sh          $v0, -0x602C($at)
    MEM_H(-0X602C, ctx->r1) = ctx->r2;
    // 0x80369300: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80369304: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80369308:
    // 0x80369308: jr          $ra
    // 0x8036930C: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    return;
    // 0x8036930C: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
;}
RECOMP_FUNC void func_8000A24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A24C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A254: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A258: jal         0x80007CF4
    // 0x8000A25C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A25C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000A260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A264: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A268: jal         0x80007C00
    // 0x8000A26C: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    gcDLLinkGObjTail(rdram, ctx);
        goto after_1;
    // 0x8000A26C: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    after_1:
    // 0x8000A270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A278: jr          $ra
    // 0x8000A27C: nop

    return;
    // 0x8000A27C: nop

;}
RECOMP_FUNC void func_80020E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020E30: jal         0x800266A0
    // 0x80020E34: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_0;
    // 0x80020E34: nop

    after_0:
    // 0x80020E38: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80020E3C: lbu         $v1, -0x2645($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2645);
    // 0x80020E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020E48: blez        $v1, L_80020E5C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020E4C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80020E5C;
    }
    // 0x80020E4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80020E50:
    // 0x80020E50: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020E54: bnel        $at, $zero, L_80020E50
    if (ctx->r1 != 0) {
        // 0x80020E58: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80020E50;
    }
    goto skip_0;
    // 0x80020E58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_80020E5C:
    // 0x80020E5C: jr          $ra
    // 0x80020E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80020E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftComputerProcJump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137CD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80137CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137CE0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80137CE4: jal         0x80136D0C
    // 0x80137CE8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137CE8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80137CEC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80137CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137CF8: lbu         $t7, 0x216($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X216);
    // 0x80137CFC: addiu       $v1, $v1, 0x1CC
    ctx->r3 = ADD32(ctx->r3, 0X1CC);
    // 0x80137D00: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80137D04: beq         $v0, $zero, L_80137D14
    if (ctx->r2 == 0) {
        // 0x80137D08: sb          $t8, 0x4A($v1)
        MEM_B(0X4A, ctx->r3) = ctx->r24;
            goto L_80137D14;
    }
    // 0x80137D08: sb          $t8, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r24;
    // 0x80137D0C: bnel        $v0, $at, L_80137D20
    if (ctx->r2 != ctx->r1) {
        // 0x80137D10: lhu         $v0, 0x10($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X10);
            goto L_80137D20;
    }
    goto skip_0;
    // 0x80137D10: lhu         $v0, 0x10($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X10);
    skip_0:
L_80137D14:
    // 0x80137D14: b           L_80137E60
    // 0x80137D18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80137E60;
    // 0x80137D18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80137D1C: lhu         $v0, 0x10($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X10);
L_80137D20:
    // 0x80137D20: lwc1        $f4, 0x70($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80137D24: bne         $v0, $zero, L_80137DF0
    if (ctx->r2 != 0) {
        // 0x80137D28: swc1        $f4, 0x60($v1)
        MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
            goto L_80137DF0;
    }
    // 0x80137D28: swc1        $f4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
    // 0x80137D2C: jal         0x80018948
    // 0x80137D30: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80137D30: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80137D34: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80137D38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80137D3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80137D40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80137D44: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80137D48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80137D4C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80137D50: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80137D54: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80137D58: nop

    // 0x80137D5C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80137D60: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80137D64: nop

    // 0x80137D68: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80137D6C: beql        $t0, $zero, L_80137DBC
    if (ctx->r8 == 0) {
        // 0x80137D70: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_80137DBC;
    }
    goto skip_1;
    // 0x80137D70: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80137D74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137D78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80137D7C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80137D80: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80137D84: nop

    // 0x80137D88: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80137D8C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80137D90: nop

    // 0x80137D94: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80137D98: bne         $t0, $zero, L_80137DB0
    if (ctx->r8 != 0) {
        // 0x80137D9C: nop
    
            goto L_80137DB0;
    }
    // 0x80137D9C: nop

    // 0x80137DA0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80137DA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80137DA8: b           L_80137DC8
    // 0x80137DAC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80137DC8;
    // 0x80137DAC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80137DB0:
    // 0x80137DB0: b           L_80137DC8
    // 0x80137DB4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80137DC8;
    // 0x80137DB4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80137DB8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_80137DBC:
    // 0x80137DBC: nop

    // 0x80137DC0: bltz        $t0, L_80137DB0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80137DC4: nop
    
            goto L_80137DB0;
    }
    // 0x80137DC4: nop

L_80137DC8:
    // 0x80137DC8: sh          $t0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r8;
    // 0x80137DCC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137DD0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80137DD4: lwc1        $f18, -0x410C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X410C);
    // 0x80137DD8: lwc1        $f16, 0x74($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80137DDC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80137DE0: sw          $t1, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r9;
    // 0x80137DE4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80137DE8: b           L_80137E08
    // 0x80137DEC: swc1        $f4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f4.u32l;
        goto L_80137E08;
    // 0x80137DEC: swc1        $f4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f4.u32l;
L_80137DF0:
    // 0x80137DF0: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80137DF4: lw          $t2, 0x88($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X88);
    // 0x80137DF8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80137DFC: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x80137E00: swc1        $f6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f6.u32l;
    // 0x80137E04: sw          $t2, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r10;
L_80137E08:
    // 0x80137E08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80137E0C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80137E10: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80137E14: lwc1        $f8, 0x64($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80137E18: lwc1        $f16, 0x60($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137E1C: lw          $v0, 0x8E8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8E8);
    // 0x80137E20: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137E24: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80137E28: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80137E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137E30: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80137E34: lwc1        $f8, -0x4108($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4108);
    // 0x80137E38: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80137E3C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80137E40: nop

    // 0x80137E44: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80137E48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80137E4C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80137E50: nop

    // 0x80137E54: bc1f        L_80137E60
    if (!c1cs) {
        // 0x80137E58: nop
    
            goto L_80137E60;
    }
    // 0x80137E58: nop

    // 0x80137E5C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80137E60:
    // 0x80137E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137E64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80137E68: jr          $ra
    // 0x80137E6C: nop

    return;
    // 0x80137E6C: nop

;}
RECOMP_FUNC void ftCommonAttack100LoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F2A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014F2AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F2B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014F2B4: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8014F2B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014F2BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014F2C0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014F2C4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014F2C8: nop

    // 0x8014F2CC: bc1fl       L_8014F324
    if (!c1cs) {
        // 0x8014F2D0: lw          $t8, 0x180($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X180);
            goto L_8014F324;
    }
    goto skip_0;
    // 0x8014F2D0: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x8014F2D4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014F2D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014F2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014F2E0: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8014F2E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8014F2E8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8014F2EC: nop

    // 0x8014F2F0: bc1fl       L_8014F324
    if (!c1cs) {
        // 0x8014F2F4: lw          $t8, 0x180($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X180);
            goto L_8014F324;
    }
    goto skip_1;
    // 0x8014F2F4: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x8014F2F8: sw          $t7, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r15;
    // 0x8014F2FC: jal         0x800EA5E8
    // 0x8014F300: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamSetMotionID(rdram, ctx);
        goto after_0;
    // 0x8014F300: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014F304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014F308: jal         0x800EA778
    // 0x8014F30C: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_1;
    // 0x8014F30C: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    after_1:
    // 0x8014F310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014F314: jal         0x800EA7B0
    // 0x8014F318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_2;
    // 0x8014F318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014F31C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014F320: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
L_8014F324:
    // 0x8014F324: beq         $t8, $zero, L_8014F36C
    if (ctx->r24 == 0) {
        // 0x8014F328: nop
    
            goto L_8014F36C;
    }
    // 0x8014F328: nop

    // 0x8014F32C: lw          $t9, 0xB18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB18);
    // 0x8014F330: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8014F334: beq         $t9, $zero, L_8014F358
    if (ctx->r25 == 0) {
        // 0x8014F338: nop
    
            goto L_8014F358;
    }
    // 0x8014F338: nop

    // 0x8014F33C: lw          $t0, 0xB1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB1C);
    // 0x8014F340: bne         $t0, $zero, L_8014F358
    if (ctx->r8 != 0) {
        // 0x8014F344: nop
    
            goto L_8014F358;
    }
    // 0x8014F344: nop

    // 0x8014F348: jal         0x8014F45C
    // 0x8014F34C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttack100EndSetStatus(rdram, ctx);
        goto after_3;
    // 0x8014F34C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8014F350: b           L_8014F378
    // 0x8014F354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014F378;
    // 0x8014F354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014F358:
    // 0x8014F358: jal         0x80146064
    // 0x8014F35C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8014F35C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8014F360: bnel        $v0, $zero, L_8014F378
    if (ctx->r2 != 0) {
        // 0x8014F364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014F378;
    }
    goto skip_2;
    // 0x8014F364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8014F368: sw          $zero, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = 0;
L_8014F36C:
    // 0x8014F36C: jal         0x8014F1BC
    // 0x8014F370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack100LoopKirbyUpdateEffect(rdram, ctx);
        goto after_5;
    // 0x8014F370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8014F374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014F378:
    // 0x8014F378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014F37C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014F380: jr          $ra
    // 0x8014F384: nop

    return;
    // 0x8014F384: nop

;}
RECOMP_FUNC void gcEjectAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B7B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B7B8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000B7BC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000B7C0: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8000B7C4: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8000B7C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B7CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B7D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B7D4: addiu       $s3, $s3, 0x6774
    ctx->r19 = ADD32(ctx->r19, 0X6774);
    // 0x8000B7D8: addiu       $s2, $s2, 0x66F0
    ctx->r18 = ADD32(ctx->r18, 0X66F0);
    // 0x8000B7DC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_8000B7E0:
    // 0x8000B7E0: beql        $s0, $zero, L_8000B800
    if (ctx->r16 == 0) {
        // 0x8000B7E4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000B800;
    }
    goto skip_0;
    // 0x8000B7E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
L_8000B7E8:
    // 0x8000B7E8: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000B7EC: jal         0x80009A84
    // 0x8000B7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8000B7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000B7F4: bne         $s1, $zero, L_8000B7E8
    if (ctx->r17 != 0) {
        // 0x8000B7F8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000B7E8;
    }
    // 0x8000B7F8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000B7FC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000B800:
    // 0x8000B800: bnel        $s2, $s3, L_8000B7E0
    if (ctx->r18 != ctx->r19) {
        // 0x8000B804: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_8000B7E0;
    }
    goto skip_1;
    // 0x8000B804: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x8000B808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B80C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B814: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B818: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000B81C: jr          $ra
    // 0x8000B820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000B820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ifCommonPlayerStockStealMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801102B0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x801102B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801102B8: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x801102BC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801102C0: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x801102C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801102C8: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x801102CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801102D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801102D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801102D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801102DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801102E0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801102E4: lw          $t3, 0x78($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X78);
    // 0x801102E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801102EC: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x801102F0: lw          $t4, 0x84($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X84);
    // 0x801102F4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x801102F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801102FC: jal         0x80009968
    // 0x80110300: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80110300: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x80110304: beq         $v0, $zero, L_80110500
    if (ctx->r2 == 0) {
        // 0x80110308: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80110500;
    }
    // 0x80110308: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8011030C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80110310: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80110314: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80110318: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8011031C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110320: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80110324: jal         0x80009DF4
    // 0x80110328: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80110328: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8011032C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80110330: addiu       $a1, $a1, 0x138
    ctx->r5 = ADD32(ctx->r5, 0X138);
    // 0x80110334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8011033C: jal         0x80008188
    // 0x80110340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80110340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80110344: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80110348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011034C: lw          $t6, 0x9C8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X9C8);
    // 0x80110350: lw          $t8, 0x340($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X340);
    // 0x80110354: jal         0x800CCFDC
    // 0x80110358: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80110358: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_3:
    // 0x8011035C: bne         $v0, $zero, L_80110374
    if (ctx->r2 != 0) {
        // 0x80110360: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80110374;
    }
    // 0x80110360: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80110364: jal         0x80009A84
    // 0x80110368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80110368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8011036C: b           L_80110504
    // 0x80110370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80110504;
    // 0x80110370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80110374:
    // 0x80110374: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80110378: addiu       $t9, $zero, 0x201
    ctx->r25 = ADD32(0, 0X201);
    // 0x8011037C: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80110380: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80110384: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80110388: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8011038C: lw          $t4, 0x9C8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X9C8);
    // 0x80110390: lbu         $t6, 0x10($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X10);
    // 0x80110394: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80110398: lw          $t5, 0x340($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X340);
    // 0x8011039C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801103A0: addiu       $t0, $t0, 0x1580
    ctx->r8 = ADD32(ctx->r8, 0X1580);
    // 0x801103A4: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x801103A8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801103AC: addiu       $t1, $t1, -0x1378
    ctx->r9 = ADD32(ctx->r9, -0X1378);
    // 0x801103B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801103B4: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x801103B8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801103BC: addiu       $t3, $t3, 0x1838
    ctx->r11 = ADD32(ctx->r11, 0X1838);
    // 0x801103C0: sw          $t4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r12;
    // 0x801103C4: lh          $t4, 0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X14);
    // 0x801103C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801103CC: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x801103D0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801103D4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x801103D8: addu        $a1, $t1, $a0
    ctx->r5 = ADD32(ctx->r9, ctx->r4);
    // 0x801103DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801103E0: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x801103E4: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    // 0x801103E8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801103EC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801103F0: addu        $v0, $t5, $t3
    ctx->r2 = ADD32(ctx->r13, ctx->r11);
    // 0x801103F4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801103F8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801103FC: lhu         $t6, 0xC($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0XC);
    // 0x80110400: sll         $a3, $t2, 2
    ctx->r7 = S32(ctx->r10 << 2);
    // 0x80110404: addu        $t4, $a2, $a3
    ctx->r12 = ADD32(ctx->r6, ctx->r7);
    // 0x80110408: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8011040C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80110410: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80110414: nop

    // 0x80110418: subu        $t7, $t9, $t3
    ctx->r15 = SUB32(ctx->r25, ctx->r11);
    // 0x8011041C: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80110420: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x80110424: addu        $t7, $t1, $a3
    ctx->r15 = ADD32(ctx->r9, ctx->r7);
    // 0x80110428: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8011042C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80110430: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80110434: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80110438: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8011043C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80110440: nop

    // 0x80110444: subu        $t9, $t6, $t5
    ctx->r25 = SUB32(ctx->r14, ctx->r13);
    // 0x80110448: addiu       $t3, $t9, -0x14
    ctx->r11 = ADD32(ctx->r25, -0X14);
    // 0x8011044C: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x80110450: lh          $t9, 0x14($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X14);
    // 0x80110454: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80110458: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8011045C: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x80110460: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x80110464: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80110468: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8011046C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80110470: nop

    // 0x80110474: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80110478: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8011047C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80110480: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80110484: nop

    // 0x80110488: subu        $t4, $t5, $t7
    ctx->r12 = SUB32(ctx->r13, ctx->r15);
    // 0x8011048C: bgez        $t8, L_801104A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80110490: sh          $t4, 0x6($v0)
        MEM_H(0X6, ctx->r2) = ctx->r12;
            goto L_801104A0;
    }
    // 0x80110490: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
    // 0x80110494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80110498: nop

    // 0x8011049C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801104A0:
    // 0x801104A0: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x801104A4: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x801104A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801104AC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801104B0: bgez        $t6, L_801104C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801104B4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801104C4;
    }
    // 0x801104B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801104B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801104BC: nop

    // 0x801104C0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801104C4:
    // 0x801104C4: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
    // 0x801104C8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801104CC: sw          $t2, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r10;
    // 0x801104D0: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x801104D4: lhu         $t6, 0xC($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0XC);
    // 0x801104D8: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x801104DC: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x801104E0: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x801104E4: addiu       $t9, $t6, -0x14
    ctx->r25 = ADD32(ctx->r14, -0X14);
    // 0x801104E8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801104EC: addu        $t8, $t3, $t4
    ctx->r24 = ADD32(ctx->r11, ctx->r12);
    // 0x801104F0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801104F4: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801104F8: jal         0x80103994
    // 0x801104FC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    efManagerStockStealStartMakeEffect(rdram, ctx);
        goto after_5;
    // 0x801104FC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_5:
L_80110500:
    // 0x80110500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80110504:
    // 0x80110504: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80110508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8011050C: jr          $ra
    // 0x80110510: nop

    return;
    // 0x80110510: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032AC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80032ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032AD0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80032AD4: jal         0x80032A40
    // 0x80032AD8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80032AD8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80032ADC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80032AE0: jal         0x80032940
    // 0x80032AE4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80032AE4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80032AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032AEC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80032AF0: jr          $ra
    // 0x80032AF4: nop

    return;
    // 0x80032AF4: nop

;}
RECOMP_FUNC void wpLinkBoomerangSubVelSqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CEEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016CEF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016CEF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8016CEF8: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8016CEFC: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8016CF00: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8016CF04: nop

    // 0x8016CF08: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016CF0C: jal         0x80033510
    // 0x8016CF10: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8016CF10: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8016CF14: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8016CF18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8016CF1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8016CF20: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8016CF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016CF28: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8016CF2C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8016CF30: bc1fl       L_8016CF40
    if (!c1cs) {
        // 0x8016CF34: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8016CF40;
    }
    goto skip_0;
    // 0x8016CF34: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8016CF38: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8016CF3C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8016CF40:
    // 0x8016CF40: jr          $ra
    // 0x8016CF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8016CF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void wpMapProcAllCheckCollEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80167B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80167B94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80167B98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80167B9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80167BA0: jal         0x800DB838
    // 0x80167BA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x80167BA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80167BA8: beq         $v0, $zero, L_80167BB4
    if (ctx->r2 == 0) {
        // 0x80167BAC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80167BB4;
    }
    // 0x80167BAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80167BB0: sw          $t6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r14;
L_80167BB4:
    // 0x80167BB4: jal         0x800DC3C8
    // 0x80167BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x80167BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80167BBC: beq         $v0, $zero, L_80167BC8
    if (ctx->r2 == 0) {
        // 0x80167BC0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80167BC8;
    }
    // 0x80167BC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80167BC4: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_80167BC8:
    // 0x80167BC8: jal         0x800DCF58
    // 0x80167BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x80167BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80167BD0: beq         $v0, $zero, L_80167BDC
    if (ctx->r2 == 0) {
        // 0x80167BD4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80167BDC;
    }
    // 0x80167BD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80167BD8: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_80167BDC:
    // 0x80167BDC: jal         0x800DD578
    // 0x80167BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_3;
    // 0x80167BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80167BE4: beq         $v0, $zero, L_80167BF0
    if (ctx->r2 == 0) {
        // 0x80167BE8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80167BF0;
    }
    // 0x80167BE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80167BEC: sw          $t9, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r25;
L_80167BF0:
    // 0x80167BF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80167BF4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80167BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80167BFC: jr          $ra
    // 0x80167C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80167C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCaptainSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160630: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160638: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016063C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80160640: jal         0x800DEEC8
    // 0x80160644: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80160644: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160648: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8016064C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80160650: addiu       $t7, $t7, 0x5FC
    ctx->r15 = ADD32(ctx->r15, 0X5FC);
    // 0x80160654: sw          $t7, 0xA0C($t8)
    MEM_W(0XA0C, ctx->r24) = ctx->r15;
    // 0x80160658: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8016065C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80160660: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80160664: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160668: jal         0x800E6F24
    // 0x8016066C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016066C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80160670: jal         0x80160280
    // 0x80160674: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftCaptainSpecialHiSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80160674: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80160678: jal         0x800E0830
    // 0x8016067C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x8016067C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80160680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160688: jr          $ra
    // 0x8016068C: nop

    return;
    // 0x8016068C: nop

;}
RECOMP_FUNC void itSawamuraFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801826A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801826AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801826B0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801826B4: addiu       $a1, $a1, -0x4DAC
    ctx->r5 = ADD32(ctx->r5, -0X4DAC);
    // 0x801826B8: jal         0x80172EC8
    // 0x801826BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801826BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801826C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801826C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801826C8: jr          $ra
    // 0x801826CC: nop

    return;
    // 0x801826CC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F35C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F364: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F368: jal         0x800DDDDC
    // 0x8015F36C: addiu       $a1, $a1, -0xB10
    ctx->r5 = ADD32(ctx->r5, -0XB10);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015F36C: addiu       $a1, $a1, -0xB10
    ctx->r5 = ADD32(ctx->r5, -0XB10);
    after_0:
    // 0x8015F370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F378: jr          $ra
    // 0x8015F37C: nop

    return;
    // 0x8015F37C: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNEmptyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801647AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801647B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801647B4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801647B8: jal         0x800DE6E4
    // 0x801647BC: addiu       $a1, $a1, 0x48F0
    ctx->r5 = ADD32(ctx->r5, 0X48F0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801647BC: addiu       $a1, $a1, 0x48F0
    ctx->r5 = ADD32(ctx->r5, 0X48F0);
    after_0:
    // 0x801647C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801647C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801647C8: jr          $ra
    // 0x801647CC: nop

    return;
    // 0x801647CC: nop

;}

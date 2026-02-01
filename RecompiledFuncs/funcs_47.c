#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PGameMakeTotalHiScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134BB4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80134BB8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134BBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134BC0: addiu       $t7, $t7, -0x74CC
    ctx->r15 = ADD32(ctx->r15, -0X74CC);
    // 0x80134BC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134BC8: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x80134BCC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134BD0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134BD4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134BD8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134BDC: addiu       $t1, $t1, -0x74C0
    ctx->r9 = ADD32(ctx->r9, -0X74C0);
    // 0x80134BE0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134BE4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80134BE8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80134BEC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80134BF0: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80134BF4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80134BF8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80134BFC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80134C00: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80134C04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134C08: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80134C0C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80134C10: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80134C14: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80134C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134C1C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80134C20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134C24: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80134C28: jal         0x80009968
    // 0x80134C2C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134C2C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x80134C30: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134C34: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80134C38: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80134C3C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80134C40: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134C44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134C48: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80134C4C: jal         0x80009DF4
    // 0x80134C50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134C50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134C54: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80134C58: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x80134C5C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80134C60: addiu       $a1, $a1, -0x72B4
    ctx->r5 = ADD32(ctx->r5, -0X72B4);
    // 0x80134C64: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80134C68: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    // 0x80134C6C: jal         0x801320F8
    // 0x80134C70: lui         $a3, 0x4353
    ctx->r7 = S32(0X4353 << 16);
    mnPlayers1PGameMakeString(rdram, ctx);
        goto after_2;
    // 0x80134C70: lui         $a3, 0x4353
    ctx->r7 = S32(0X4353 << 16);
    after_2:
    // 0x80134C74: jal         0x80134B64
    // 0x80134C78: nop

    mnPlayers1PGameGetTotalHiScore(rdram, ctx);
        goto after_3;
    // 0x80134C78: nop

    after_3:
    // 0x80134C7C: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80134C80: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80134C84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134C88: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134C8C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134C90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134C94: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80134C98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134C9C: lui         $a2, 0x4380
    ctx->r6 = S32(0X4380 << 16);
    // 0x80134CA0: jal         0x80131CEC
    // 0x80134CA4: lui         $a3, 0x4350
    ctx->r7 = S32(0X4350 << 16);
    mnPlayers1PGameMakeNumber(rdram, ctx);
        goto after_4;
    // 0x80134CA4: lui         $a3, 0x4350
    ctx->r7 = S32(0X4350 << 16);
    after_4:
    // 0x80134CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134CAC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80134CB0: jr          $ra
    // 0x80134CB4: nop

    return;
    // 0x80134CB4: nop

;}
RECOMP_FUNC void mnVSResultsSetTKO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B1C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136B20: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80136B24: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136B28: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136B2C: beq         $t6, $zero, L_80136B44
    if (ctx->r14 == 0) {
        // 0x80136B30: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80136B44;
    }
    // 0x80136B30: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136B34: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80136B38: lw          $t7, 0x4D38($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4D38);
    // 0x80136B3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136B40: sw          $t7, -0x6470($at)
    MEM_W(-0X6470, ctx->r1) = ctx->r15;
L_80136B44:
    // 0x80136B44: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x80136B48: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80136B4C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80136B50: beq         $t8, $zero, L_80136B64
    if (ctx->r24 == 0) {
        // 0x80136B54: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_80136B64;
    }
    // 0x80136B54: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80136B58: lw          $t9, 0x4DAC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4DAC);
    // 0x80136B5C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136B60: sw          $t9, -0x646C($at)
    MEM_W(-0X646C, ctx->r1) = ctx->r25;
L_80136B64:
    // 0x80136B64: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x80136B68: beq         $t0, $zero, L_80136B7C
    if (ctx->r8 == 0) {
        // 0x80136B6C: nop
    
            goto L_80136B7C;
    }
    // 0x80136B6C: nop

    // 0x80136B70: lw          $t1, 0x4E20($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4E20);
    // 0x80136B74: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136B78: sw          $t1, -0x6468($at)
    MEM_W(-0X6468, ctx->r1) = ctx->r9;
L_80136B7C:
    // 0x80136B7C: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x80136B80: beq         $t2, $zero, L_80136B94
    if (ctx->r10 == 0) {
        // 0x80136B84: nop
    
            goto L_80136B94;
    }
    // 0x80136B84: nop

    // 0x80136B88: lw          $t3, 0x4E94($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4E94);
    // 0x80136B8C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136B90: sw          $t3, -0x6464($at)
    MEM_W(-0X6464, ctx->r1) = ctx->r11;
L_80136B94:
    // 0x80136B94: jr          $ra
    // 0x80136B98: nop

    return;
    // 0x80136B98: nop

;}
RECOMP_FUNC void efManagerShockSmallMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEEB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FEEB4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FEEB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800FEEBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FEEC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEEC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FEEC8: jal         0x800FDAFC
    // 0x800FEECC: addiu       $a0, $a0, -0x20B4
    ctx->r4 = ADD32(ctx->r4, -0X20B4);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FEECC: addiu       $a0, $a0, -0x20B4
    ctx->r4 = ADD32(ctx->r4, -0X20B4);
    after_0:
    // 0x800FEED0: bne         $v0, $zero, L_800FEEE0
    if (ctx->r2 != 0) {
        // 0x800FEED4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FEEE0;
    }
    // 0x800FEED4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FEED8: b           L_800FEFCC
    // 0x800FEEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEFCC;
    // 0x800FEEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEEE0:
    // 0x800FEEE0: lw          $t6, 0x84($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X84);
    // 0x800FEEE4: lw          $s1, 0x74($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X74);
    // 0x800FEEE8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FEEEC: jal         0x80018948
    // 0x800FEEF0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x800FEEF0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_1:
    // 0x800FEEF4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800FEEF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEEFC: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FEF00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FEF04: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEF08: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FEF0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEF10: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800FEF14: jal         0x80018948
    // 0x800FEF18: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x800FEF18: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x800FEF1C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800FEF20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEF24: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FEF28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FEF2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEF30: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FEF34: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800FEF38: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEF3C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FEF40: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800FEF44: sw          $t8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r24;
    // 0x800FEF48: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800FEF4C: sw          $t7, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r15;
    // 0x800FEF50: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800FEF54: jal         0x80018948
    // 0x800FEF58: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x800FEF58: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    after_3:
    // 0x800FEF5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEF60: lwc1        $f4, 0x96C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X96C);
    // 0x800FEF64: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEF68: jal         0x80035CD0
    // 0x800FEF6C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x800FEF6C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x800FEF70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FEF74: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800FEF78: swc1        $f6, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f6.u32l;
    // 0x800FEF7C: jal         0x800303F0
    // 0x800FEF80: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800FEF80: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x800FEF84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800FEF88: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800FEF8C: jal         0x80018948
    // 0x800FEF90: swc1        $f8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f8.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x800FEF90: swc1        $f8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f8.u32l;
    after_6:
    // 0x800FEF94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FEF98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FEF9C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800FEFA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FEFA4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FEFA8: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800FEFAC: swc1        $f2, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f2.u32l;
    // 0x800FEFB0: jal         0x80018948
    // 0x800FEFB4: swc1        $f2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FEFB4: swc1        $f2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f2.u32l;
    after_7:
    // 0x800FEFB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEFBC: lwc1        $f4, 0x970($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X970);
    // 0x800FEFC0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEFC4: swc1        $f6, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f6.u32l;
    // 0x800FEFC8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_800FEFCC:
    // 0x800FEFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FEFD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FEFD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FEFD8: jr          $ra
    // 0x800FEFDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800FEFDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftBossMoveProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159268: jal         0x800DE324
    // 0x8015926C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_0;
    // 0x8015926C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80159274: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80159278: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015927C: lwc1        $f4, 0xB28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB28);
    // 0x80159280: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80159284: nop

    // 0x80159288: bc1fl       L_801592A8
    if (!c1cs) {
        // 0x8015928C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801592A8;
    }
    goto skip_0;
    // 0x8015928C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80159290: lw          $t9, 0xB18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB18);
    // 0x80159294: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80159298: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x8015929C: jalr        $t9
    // 0x801592A0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x801592A0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x801592A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801592A8:
    // 0x801592A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801592AC: jr          $ra
    // 0x801592B0: nop

    return;
    // 0x801592B0: nop

;}
RECOMP_FUNC void mpCommonRunFighterSpecialCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE45C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DE460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DE464: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DE468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DE46C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800DE470: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800DE474: lw          $s0, 0x84($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X84);
    // 0x800DE478: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800DE47C: jal         0x800DB838
    // 0x800DE480: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x800DE480: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x800DE484: beq         $v0, $zero, L_800DE494
    if (ctx->r2 == 0) {
        // 0x800DE488: nop
    
            goto L_800DE494;
    }
    // 0x800DE488: nop

    // 0x800DE48C: jal         0x800DBF58
    // 0x800DE490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x800DE490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_800DE494:
    // 0x800DE494: jal         0x800DC3C8
    // 0x800DE498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x800DE498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800DE49C: beq         $v0, $zero, L_800DE4AC
    if (ctx->r2 == 0) {
        // 0x800DE4A0: nop
    
            goto L_800DE4AC;
    }
    // 0x800DE4A0: nop

    // 0x800DE4A4: jal         0x800DCAE8
    // 0x800DE4A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_3;
    // 0x800DE4A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_800DE4AC:
    // 0x800DE4AC: jal         0x800DCF58
    // 0x800DE4B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x800DE4B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800DE4B4: beql        $v0, $zero, L_800DE52C
    if (ctx->r2 == 0) {
        // 0x800DE4B8: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800DE52C;
    }
    goto skip_0;
    // 0x800DE4B8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800DE4BC: jal         0x800DD160
    // 0x800DE4C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x800DE4C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800DE4C4: lhu         $t7, 0x5A($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X5A);
    // 0x800DE4C8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x800DE4CC: beql        $t8, $zero, L_800DE4E0
    if (ctx->r24 == 0) {
        // 0x800DE4D0: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800DE4E0;
    }
    goto skip_1;
    // 0x800DE4D0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x800DE4D4: jal         0x800D99B8
    // 0x800DE4D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_6;
    // 0x800DE4D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800DE4DC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_800DE4E0:
    // 0x800DE4E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800DE4E4: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x800DE4E8: beql        $t0, $zero, L_800DE52C
    if (ctx->r8 == 0) {
        // 0x800DE4EC: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800DE52C;
    }
    goto skip_2;
    // 0x800DE4EC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x800DE4F0: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800DE4F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE4F8: nop

    // 0x800DE4FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800DE500: nop

    // 0x800DE504: bc1fl       L_800DE52C
    if (!c1cs) {
        // 0x800DE508: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800DE52C;
    }
    goto skip_3;
    // 0x800DE508: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_3:
    // 0x800DE50C: lhu         $t1, 0x56($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X56);
    // 0x800DE510: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DE514: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DE518: ori         $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 | 0X4000;
    // 0x800DE51C: sh          $t2, 0x56($s1)
    MEM_H(0X56, ctx->r17) = ctx->r10;
    // 0x800DE520: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800DE524: sw          $t4, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r12;
    // 0x800DE528: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800DE52C:
    // 0x800DE52C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DE530: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DE534: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x800DE538: beq         $t6, $zero, L_800DE550
    if (ctx->r14 == 0) {
        // 0x800DE53C: lw          $a2, 0x3C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3C);
            goto L_800DE550;
    }
    // 0x800DE53C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800DE540: jal         0x800DD2C8
    // 0x800DE544: lw          $a1, 0xE20($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE20);
    mpProcessCheckTestFloorCollisionAdjNew(rdram, ctx);
        goto after_7;
    // 0x800DE544: lw          $a1, 0xE20($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XE20);
    after_7:
    // 0x800DE548: b           L_800DE558
    // 0x800DE54C: nop

        goto L_800DE558;
    // 0x800DE54C: nop

L_800DE550:
    // 0x800DE550: jal         0x800DD578
    // 0x800DE554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_8;
    // 0x800DE554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_800DE558:
    // 0x800DE558: beq         $v0, $zero, L_800DE5DC
    if (ctx->r2 == 0) {
        // 0x800DE55C: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_800DE5DC;
    }
    // 0x800DE55C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800DE560: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800DE564: beq         $t8, $zero, L_800DE5A4
    if (ctx->r24 == 0) {
        // 0x800DE568: nop
    
            goto L_800DE5A4;
    }
    // 0x800DE568: nop

    // 0x800DE56C: jal         0x800DD6A8
    // 0x800DE570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessSetCollideFloor(rdram, ctx);
        goto after_9;
    // 0x800DE570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800DE574: lhu         $t9, 0x5A($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X5A);
    // 0x800DE578: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x800DE57C: beq         $t0, $zero, L_800DE594
    if (ctx->r8 == 0) {
        // 0x800DE580: nop
    
            goto L_800DE594;
    }
    // 0x800DE580: nop

    // 0x800DE584: jal         0x800D9F84
    // 0x800DE588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_10;
    // 0x800DE588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800DE58C: b           L_800DE5E8
    // 0x800DE590: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
        goto L_800DE5E8;
    // 0x800DE590: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_800DE594:
    // 0x800DE594: jal         0x800D9FCC
    // 0x800DE598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_11;
    // 0x800DE598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800DE59C: b           L_800DE5E8
    // 0x800DE5A0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
        goto L_800DE5E8;
    // 0x800DE5A0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_800DE5A4:
    // 0x800DE5A4: jal         0x800DD59C
    // 0x800DE5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_12;
    // 0x800DE5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800DE5AC: jal         0x800DE368
    // 0x800DE5B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mpCommonSetFighterLandingParams(rdram, ctx);
        goto after_13;
    // 0x800DE5B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x800DE5B4: lhu         $t1, 0x5A($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X5A);
    // 0x800DE5B8: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x800DE5BC: beql        $t2, $zero, L_800DE5E8
    if (ctx->r10 == 0) {
        // 0x800DE5C0: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_800DE5E8;
    }
    goto skip_4;
    // 0x800DE5C0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    skip_4:
    // 0x800DE5C4: jal         0x800D9F84
    // 0x800DE5C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_14;
    // 0x800DE5C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x800DE5CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DE5D0: sw          $t3, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r11;
    // 0x800DE5D4: b           L_800DE69C
    // 0x800DE5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DE69C;
    // 0x800DE5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DE5DC:
    // 0x800DE5DC: jal         0x800D9FCC
    // 0x800DE5E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_15;
    // 0x800DE5E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x800DE5E4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_800DE5E8:
    // 0x800DE5E8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800DE5EC: beql        $t5, $zero, L_800DE69C
    if (ctx->r13 == 0) {
        // 0x800DE5F0: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_800DE69C;
    }
    goto skip_5;
    // 0x800DE5F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800DE5F4: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x800DE5F8: bnel        $t6, $zero, L_800DE69C
    if (ctx->r14 != 0) {
        // 0x800DE5FC: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_800DE69C;
    }
    goto skip_6;
    // 0x800DE5FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x800DE600: jal         0x800DB590
    // 0x800DE604: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessCheckTestLCliffCollision(rdram, ctx);
        goto after_16;
    // 0x800DE604: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x800DE608: bne         $v0, $zero, L_800DE61C
    if (ctx->r2 != 0) {
        // 0x800DE60C: nop
    
            goto L_800DE61C;
    }
    // 0x800DE60C: nop

    // 0x800DE610: jal         0x800DB6F0
    // 0x800DE614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpProcessCheckTestRCliffCollision(rdram, ctx);
        goto after_17;
    // 0x800DE614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800DE618: beq         $v0, $zero, L_800DE698
    if (ctx->r2 == 0) {
        // 0x800DE61C: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_800DE698;
    }
L_800DE61C:
    // 0x800DE61C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800DE620: lw          $v1, 0x66FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66FC);
    // 0x800DE624: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800DE628: beq         $v1, $zero, L_800DE680
    if (ctx->r3 == 0) {
        // 0x800DE62C: nop
    
            goto L_800DE680;
    }
    // 0x800DE62C: nop

L_800DE630:
    // 0x800DE630: beql        $v1, $a0, L_800DE678
    if (ctx->r3 == ctx->r4) {
        // 0x800DE634: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800DE678;
    }
    goto skip_7;
    // 0x800DE634: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_7:
    // 0x800DE638: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800DE63C: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x800DE640: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800DE644: beql        $t8, $zero, L_800DE678
    if (ctx->r24 == 0) {
        // 0x800DE648: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800DE678;
    }
    goto skip_8;
    // 0x800DE648: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_8:
    // 0x800DE64C: lw          $t9, 0x140($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X140);
    // 0x800DE650: lw          $t0, 0x140($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X140);
    // 0x800DE654: bnel        $t9, $t0, L_800DE678
    if (ctx->r25 != ctx->r8) {
        // 0x800DE658: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800DE678;
    }
    goto skip_9;
    // 0x800DE658: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_9:
    // 0x800DE65C: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x800DE660: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x800DE664: bnel        $t1, $t2, L_800DE678
    if (ctx->r9 != ctx->r10) {
        // 0x800DE668: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800DE678;
    }
    goto skip_10;
    // 0x800DE668: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_10:
    // 0x800DE66C: b           L_800DE69C
    // 0x800DE670: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_800DE69C;
    // 0x800DE670: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800DE674: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_800DE678:
    // 0x800DE678: bne         $v1, $zero, L_800DE630
    if (ctx->r3 != 0) {
        // 0x800DE67C: nop
    
            goto L_800DE630;
    }
    // 0x800DE67C: nop

L_800DE680:
    // 0x800DE680: jal         0x800DE368
    // 0x800DE684: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mpCommonSetFighterLandingParams(rdram, ctx);
        goto after_18;
    // 0x800DE684: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_18:
    // 0x800DE688: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DE68C: sw          $t3, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r11;
    // 0x800DE690: b           L_800DE69C
    // 0x800DE694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DE69C;
    // 0x800DE694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DE698:
    // 0x800DE698: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800DE69C:
    // 0x800DE69C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE6A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DE6A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DE6A8: jr          $ra
    // 0x800DE6AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800DE6AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftCommonDokanStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142164: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80142168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014216C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80142170: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80142174: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80142178: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8014217C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142180: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80142184: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80142188: jal         0x800E6F24
    // 0x8014218C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014218C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80142190: jal         0x800E0830
    // 0x80142194: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80142194: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80142198: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x8014219C: sb          $t6, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r14;
    // 0x801421A0: jal         0x800D9444
    // 0x801421A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_2;
    // 0x801421A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x801421A8: lbu         $t8, 0x18F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18F);
    // 0x801421AC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x801421B0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801421B4: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x801421B8: sb          $t9, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r25;
    // 0x801421BC: bne         $v0, $at, L_801421CC
    if (ctx->r2 != ctx->r1) {
        // 0x801421C0: sw          $v0, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = ctx->r2;
            goto L_801421CC;
    }
    // 0x801421C0: sw          $v0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r2;
    // 0x801421C4: b           L_801421D0
    // 0x801421C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_801421D0;
    // 0x801421C8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_801421CC:
    // 0x801421CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_801421D0:
    // 0x801421D0: jal         0x800FC814
    // 0x801421D4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_3;
    // 0x801421D4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x801421D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801421DC: jal         0x800FC894
    // 0x801421E0: addiu       $a1, $s0, 0xB20
    ctx->r5 = ADD32(ctx->r16, 0XB20);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_4;
    // 0x801421E0: addiu       $a1, $s0, 0xB20
    ctx->r5 = ADD32(ctx->r16, 0XB20);
    after_4:
    // 0x801421E4: jal         0x800269C0
    // 0x801421E8: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x801421E8: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    after_5:
    // 0x801421EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801421F0: jal         0x800E7F7C
    // 0x801421F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_6;
    // 0x801421F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x801421F8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x801421FC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80142200: beq         $v0, $zero, L_80142228
    if (ctx->r2 == 0) {
        // 0x80142204: nop
    
            goto L_80142228;
    }
    // 0x80142204: nop

    // 0x80142208: beq         $v0, $at, L_80142228
    if (ctx->r2 == ctx->r1) {
        // 0x8014220C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80142228;
    }
    // 0x8014220C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80142210: beq         $v0, $at, L_80142228
    if (ctx->r2 == ctx->r1) {
        // 0x80142214: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80142228;
    }
    // 0x80142214: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80142218: beq         $v0, $at, L_80142228
    if (ctx->r2 == ctx->r1) {
        // 0x8014221C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80142228;
    }
    // 0x8014221C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80142220: bne         $v0, $at, L_80142230
    if (ctx->r2 != ctx->r1) {
        // 0x80142224: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_80142230;
    }
    // 0x80142224: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
L_80142228:
    // 0x80142228: b           L_80142234
    // 0x8014222C: sw          $zero, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = 0;
        goto L_80142234;
    // 0x8014222C: sw          $zero, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = 0;
L_80142230:
    // 0x80142230: sw          $t0, 0xB40($s0)
    MEM_W(0XB40, ctx->r16) = ctx->r8;
L_80142234:
    // 0x80142234: jal         0x80141FF0
    // 0x80142238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartUpdateModelYaw(rdram, ctx);
        goto after_7;
    // 0x80142238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8014223C: jal         0x8010972C
    // 0x80142240: nop

    grInishiePakkunSetWaitFighter(rdram, ctx);
        goto after_8;
    // 0x80142240: nop

    after_8:
    // 0x80142244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80142248: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014224C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80142250: jr          $ra
    // 0x80142254: nop

    return;
    // 0x80142254: nop

;}
RECOMP_FUNC void func_ovl8_80375D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375D54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80375D58: lwl         $t8, 0x0($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X0);
    // 0x80375D5C: lwr         $t8, 0x3($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X3);
    // 0x80375D60: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375D64: addiu       $t6, $t6, -0x1048
    ctx->r14 = ADD32(ctx->r14, -0X1048);
    // 0x80375D68: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x80375D6C: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    // 0x80375D70: lwl         $t7, 0x4($a1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r5, 0X4);
    // 0x80375D74: lwr         $t7, 0x7($a1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r5, 0X7);
    // 0x80375D78: swl         $t7, 0x4($t6)
    do_swl(rdram, 0X4, ctx->r14, ctx->r15);
    // 0x80375D7C: jr          $ra
    // 0x80375D80: swr         $t7, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r15);
    return;
    // 0x80375D80: swr         $t7, 0x7($t6)
    do_swr(rdram, 0X7, ctx->r14, ctx->r15);
;}
RECOMP_FUNC void itMBallOpenInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CB84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017CB88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017CB8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017CB90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017CB94: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017CB98: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017CB9C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017CBA0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8017CBA4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8017CBA8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8017CBAC: lw          $v0, 0x10($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X10);
    // 0x8017CBB0: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    // 0x8017CBB4: lbu         $t6, 0x54($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X54);
    // 0x8017CBB8: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x8017CBBC: sb          $t7, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r15;
    // 0x8017CBC0: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x8017CBC4: lw          $v1, 0x8($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X8);
    // 0x8017CBC8: lbu         $t9, 0x54($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X54);
    // 0x8017CBCC: xori        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 ^ 0X2;
    // 0x8017CBD0: sb          $t0, 0x54($v1)
    MEM_B(0X54, ctx->r3) = ctx->r8;
    // 0x8017CBD4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8017CBD8: jal         0x800269C0
    // 0x8017CBDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017CBDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017CBE0: lbu         $t3, 0x2CF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2CF);
    // 0x8017CBE4: lbu         $v1, 0x15($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X15);
    // 0x8017CBE8: lw          $t1, 0xAC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XAC);
    // 0x8017CBEC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8017CBF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017CBF4: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x8017CBF8: sb          $t4, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r12;
    // 0x8017CBFC: beq         $v1, $at, L_8017CC50
    if (ctx->r3 == ctx->r1) {
        // 0x8017CC00: sh          $t1, 0x2D0($s0)
        MEM_H(0X2D0, ctx->r16) = ctx->r9;
            goto L_8017CC50;
    }
    // 0x8017CC00: sh          $t1, 0x2D0($s0)
    MEM_H(0X2D0, ctx->r16) = ctx->r9;
    // 0x8017CC04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017CC08: beq         $v1, $at, L_8017CC50
    if (ctx->r3 == ctx->r1) {
        // 0x8017CC0C: lui         $t5, 0x800A
        ctx->r13 = S32(0X800A << 16);
            goto L_8017CC50;
    }
    // 0x8017CC0C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8017CC10: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8017CC14: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8017CC18: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8017CC1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017CC20: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8017CC24: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017CC28: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017CC2C: lw          $v0, 0x78($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X78);
    // 0x8017CC30: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8017CC34: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8017CC38: beq         $v0, $zero, L_8017CC50
    if (ctx->r2 == 0) {
        // 0x8017CC3C: nop
    
            goto L_8017CC50;
    }
    // 0x8017CC3C: nop

    // 0x8017CC40: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8017CC44: jal         0x800E806C
    // 0x8017CC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    ftParamMakeRumble(rdram, ctx);
        goto after_1;
    // 0x8017CC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017CC4C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_8017CC50:
    // 0x8017CC50: jal         0x80102C28
    // 0x8017CC54: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    efManagerMBallRaysMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8017CC54: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    after_2:
    // 0x8017CC58: sw          $v0, 0x358($s0)
    MEM_W(0X358, ctx->r16) = ctx->r2;
    // 0x8017CC5C: jal         0x8017C6F8
    // 0x8017CC60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    itMBallOpenClearAnim(rdram, ctx);
        goto after_3;
    // 0x8017CC60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8017CC64: lbu         $t8, 0x158($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X158);
    // 0x8017CC68: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8017CC6C: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x8017CC70: sb          $t9, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r25;
    // 0x8017CC74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CC78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017CC7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017CC80: jr          $ra
    // 0x8017CC84: nop

    return;
    // 0x8017CC84: nop

;}
RECOMP_FUNC void mnCharactersMakeStory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C00: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80131C04: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131C08: addiu       $t7, $t7, 0x62B0
    ctx->r15 = ADD32(ctx->r15, 0X62B0);
    // 0x80131C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C10: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80131C14: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80131C18: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
L_80131C1C:
    // 0x80131C1C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C20: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131C24: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131C28: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131C2C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131C30: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131C34: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131C38: bne         $t7, $t0, L_80131C1C
    if (ctx->r15 != ctx->r8) {
        // 0x80131C3C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131C1C;
    }
    // 0x80131C3C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C48: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131C4C: jal         0x80009968
    // 0x80131C50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C58: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131C5C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80131C60: sw          $v0, 0x6604($at)
    MEM_W(0X6604, ctx->r1) = ctx->r2;
    // 0x80131C64: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80131C68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131C6C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C74: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80131C78: jal         0x80009DF4
    // 0x80131C7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131C7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131C80: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131C84: lw          $t2, 0x6A78($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A78);
    // 0x80131C88: lui         $t3, 0x3
    ctx->r11 = S32(0X3 << 16);
    // 0x80131C8C: addiu       $t3, $t3, 0x888
    ctx->r11 = ADD32(ctx->r11, 0X888);
    // 0x80131C90: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80131C94: jal         0x800CCFDC
    // 0x80131C98: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C98: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80131C9C: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CA0: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80131CA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131CA8: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80131CAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131CB0: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80131CB4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131CB8: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x80131CBC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131CC0: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131CC4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131CC8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131CCC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131CD0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131CD4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80131CD8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131CDC: lw          $t1, 0x6A78($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A78);
    // 0x80131CE0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80131CE4: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80131CE8: lw          $t9, 0x20($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X20);
    // 0x80131CEC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80131CF0: jal         0x800CCFDC
    // 0x80131CF4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131CF4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_3:
    // 0x80131CF8: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CFC: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80131D00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131D04: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80131D08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131D0C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131D10: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80131D14: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131D18: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80131D1C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131D20: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131D24: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131D28: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131D2C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131D30: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D38: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80131D3C: jr          $ra
    // 0x80131D40: nop

    return;
    // 0x80131D40: nop

;}
RECOMP_FUNC void ftSamusSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015DE98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015DE9C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015DEA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DEA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015DEA8: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015DEAC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DEB0: jal         0x800E6F24
    // 0x8015DEB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015DEB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015DEB8: jal         0x800E0830
    // 0x8015DEBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015DEBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015DEC0: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015DEC4: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x8015DEC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015DECC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x8015DED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015DED4: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8015DED8: sb          $t7, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r15;
    // 0x8015DEDC: jal         0x800D8E78
    // 0x8015DEE0: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_2;
    // 0x8015DEE0: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8015DEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015DEE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015DEEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DEF0: jr          $ra
    // 0x8015DEF4: nop

    return;
    // 0x8015DEF4: nop

;}
RECOMP_FUNC void wpNessPKReflectTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B9E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016B9E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016B9E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016B9EC: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016B9F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016B9F4: lw          $t6, 0x29C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X29C);
    // 0x8016B9F8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8016B9FC: beql        $t7, $zero, L_8016BA10
    if (ctx->r15 == 0) {
        // 0x8016BA00: lw          $t8, 0x2A0($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X2A0);
            goto L_8016BA10;
    }
    goto skip_0;
    // 0x8016BA00: lw          $t8, 0x2A0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2A0);
    skip_0:
    // 0x8016BA04: b           L_8016BB28
    // 0x8016BA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016BB28;
    // 0x8016BA08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016BA0C: lw          $t8, 0x2A0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2A0);
L_8016BA10:
    // 0x8016BA10: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8016BA14: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8016BA18: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8016BA1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016BA20: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8016BA24: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8016BA28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016BA2C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8016BA30: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016BA34: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8016BA38: add.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d + ctx->f0.d;
    // 0x8016BA3C: lw          $t9, 0x2A8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X2A8);
    // 0x8016BA40: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x8016BA44: mul.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x8016BA48: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8016BA4C: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8016BA50: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8016BA54: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8016BA58: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8016BA5C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8016BA60: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x8016BA64: lw          $t2, 0x2A0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X2A0);
    // 0x8016BA68: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x8016BA6C: lw          $t3, 0x2A8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X2A8);
    // 0x8016BA70: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8016BA74: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8016BA78: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x8016BA7C: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8016BA80: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8016BA84: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8016BA88: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x8016BA8C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8016BA90: mul.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8016BA94: nop

    // 0x8016BA98: mul.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x8016BA9C: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x8016BAA0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8016BAA4: swc1        $f6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f6.u32l;
    // 0x8016BAA8: lw          $v0, 0x2A0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2A0);
    // 0x8016BAAC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8016BAB0: beq         $at, $zero, L_8016BADC
    if (ctx->r1 == 0) {
        // 0x8016BAB4: nop
    
            goto L_8016BADC;
    }
    // 0x8016BAB4: nop

    // 0x8016BAB8: lw          $t6, 0x268($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X268);
    // 0x8016BABC: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016BAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016BAC4: bne         $t6, $at, L_8016BADC
    if (ctx->r14 != ctx->r1) {
        // 0x8016BAC8: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_8016BADC;
    }
    // 0x8016BAC8: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x8016BACC: jal         0x8016B65C
    // 0x8016BAD0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    wpNessPKReflectHeadMakeTrail(rdram, ctx);
        goto after_0;
    // 0x8016BAD0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8016BAD4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016BAD8: lw          $v0, 0x2A0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2A0);
L_8016BADC:
    // 0x8016BADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016BAE0: bne         $v0, $at, L_8016BB08
    if (ctx->r2 != ctx->r1) {
        // 0x8016BAE4: nop
    
            goto L_8016BB08;
    }
    // 0x8016BAE4: nop

    // 0x8016BAE8: lw          $t7, 0x268($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X268);
    // 0x8016BAEC: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016BAF0: bne         $t7, $at, L_8016BB08
    if (ctx->r15 != ctx->r1) {
        // 0x8016BAF4: nop
    
            goto L_8016BB08;
    }
    // 0x8016BAF4: nop

    // 0x8016BAF8: lw          $a0, 0x2A8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X2A8);
    // 0x8016BAFC: jal         0x80102968
    // 0x8016BB00: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    efManagerNessPKReflectTrailMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016BB00: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8016BB04: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8016BB08:
    // 0x8016BB08: jal         0x80167FE8
    // 0x8016BB0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_2;
    // 0x8016BB0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8016BB10: jal         0x80018994
    // 0x8016BB14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8016BB14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8016BB18: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8016BB1C: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x8016BB20: sh          $v0, 0x80($t9)
    MEM_H(0X80, ctx->r25) = ctx->r2;
    // 0x8016BB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BB28:
    // 0x8016BB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016BB2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016BB30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016BB34: jr          $ra
    // 0x8016BB38: nop

    return;
    // 0x8016BB38: nop

;}
RECOMP_FUNC void mnVSResultsSetFighterStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334DC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801334E0: lw          $t6, -0x63F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63F0);
    // 0x801334E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801334E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801334EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801334F0: bne         $t6, $at, L_8013351C
    if (ctx->r14 != ctx->r1) {
        // 0x801334F4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8013351C;
    }
    // 0x801334F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801334F8: jal         0x80133148
    // 0x801334FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x801334FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80133500: jal         0x801334CC
    // 0x80133504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusLose(rdram, ctx);
        goto after_1;
    // 0x80133504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80133508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013350C: jal         0x803905CC
    // 0x80133510: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80133510: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80133514: b           L_80133678
    // 0x80133518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x80133518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013351C:
    // 0x8013351C: jal         0x8013205C
    // 0x80133520: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_3;
    // 0x80133520: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80133524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133528: beq         $v0, $at, L_80133550
    if (ctx->r2 == ctx->r1) {
        // 0x8013352C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80133550;
    }
    // 0x8013352C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80133530: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133534: beq         $v0, $at, L_801335C4
    if (ctx->r2 == ctx->r1) {
        // 0x80133538: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_801335C4;
    }
    // 0x80133538: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8013353C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133540: beq         $v0, $at, L_80133620
    if (ctx->r2 == ctx->r1) {
        // 0x80133544: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80133620;
    }
    // 0x80133544: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80133548: b           L_80133620
    // 0x8013354C: nop

        goto L_80133620;
    // 0x8013354C: nop

L_80133550:
    // 0x80133550: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80133554: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133558: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8013355C: lw          $v0, -0x6450($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6450);
    // 0x80133560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133564: beq         $v0, $zero, L_8013357C
    if (ctx->r2 == 0) {
        // 0x80133568: nop
    
            goto L_8013357C;
    }
    // 0x80133568: nop

    // 0x8013356C: beq         $v0, $at, L_801335A0
    if (ctx->r2 == ctx->r1) {
        // 0x80133570: nop
    
            goto L_801335A0;
    }
    // 0x80133570: nop

    // 0x80133574: b           L_80133678
    // 0x80133578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x80133578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013357C:
    // 0x8013357C: jal         0x80133148
    // 0x80133580: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_4;
    // 0x80133580: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80133584: jal         0x8013345C
    // 0x80133588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusWin(rdram, ctx);
        goto after_5;
    // 0x80133588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8013358C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133590: jal         0x803905CC
    // 0x80133594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_6;
    // 0x80133594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80133598: b           L_80133678
    // 0x8013359C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x8013359C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801335A0:
    // 0x801335A0: jal         0x80133148
    // 0x801335A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_7;
    // 0x801335A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
    // 0x801335A8: jal         0x801334CC
    // 0x801335AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusLose(rdram, ctx);
        goto after_8;
    // 0x801335AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x801335B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801335B4: jal         0x803905CC
    // 0x801335B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_9;
    // 0x801335B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x801335BC: b           L_80133678
    // 0x801335C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x801335C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801335C4:
    // 0x801335C4: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801335C8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801335CC: lw          $t9, -0x6450($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6450);
    // 0x801335D0: bne         $t9, $zero, L_801335FC
    if (ctx->r25 != 0) {
        // 0x801335D4: nop
    
            goto L_801335FC;
    }
    // 0x801335D4: nop

    // 0x801335D8: jal         0x80133148
    // 0x801335DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_10;
    // 0x801335DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
    // 0x801335E0: jal         0x8013345C
    // 0x801335E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusWin(rdram, ctx);
        goto after_11;
    // 0x801335E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x801335E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801335EC: jal         0x803905CC
    // 0x801335F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_12;
    // 0x801335F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x801335F4: b           L_80133678
    // 0x801335F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x801335F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801335FC:
    // 0x801335FC: jal         0x80133148
    // 0x80133600: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_13;
    // 0x80133600: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_13:
    // 0x80133604: jal         0x801334CC
    // 0x80133608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusLose(rdram, ctx);
        goto after_14;
    // 0x80133608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x8013360C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133610: jal         0x803905CC
    // 0x80133614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_15;
    // 0x80133614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x80133618: b           L_80133678
    // 0x8013361C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x8013361C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133620:
    // 0x80133620: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133624: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80133628: lw          $t1, -0x6450($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6450);
    // 0x8013362C: bne         $t1, $zero, L_80133658
    if (ctx->r9 != 0) {
        // 0x80133630: nop
    
            goto L_80133658;
    }
    // 0x80133630: nop

    // 0x80133634: jal         0x80133148
    // 0x80133638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_16;
    // 0x80133638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_16:
    // 0x8013363C: jal         0x8013345C
    // 0x80133640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusWin(rdram, ctx);
        goto after_17;
    // 0x80133640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80133644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133648: jal         0x803905CC
    // 0x8013364C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_18;
    // 0x8013364C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80133650: b           L_80133678
    // 0x80133654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133678;
    // 0x80133654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133658:
    // 0x80133658: jal         0x80133148
    // 0x8013365C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_19;
    // 0x8013365C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_19:
    // 0x80133660: jal         0x801334CC
    // 0x80133664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetStatusLose(rdram, ctx);
        goto after_20;
    // 0x80133664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80133668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013366C: jal         0x803905CC
    // 0x80133670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_21;
    // 0x80133670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
    // 0x80133674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133678:
    // 0x80133678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013367C: jr          $ra
    // 0x80133680: nop

    return;
    // 0x80133680: nop

;}
RECOMP_FUNC void func_80021734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021734: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80021738: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8002173C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80021740: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80021744: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80021748: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002174C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80021750: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80021754: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80021758: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8002175C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80021760: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80021764: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80021768: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002176C: blez        $a3, L_800218B4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80021770: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800218B4;
    }
    // 0x80021770: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80021774: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80021778: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x8002177C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80021780: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80021784: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x80021788: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8002178C: bne         $v0, $zero, L_80021798
    if (ctx->r2 != 0) {
        // 0x80021790: nop
    
            goto L_80021798;
    }
    // 0x80021790: nop

    // 0x80021794: break       7
    do_break(2147620756);
L_80021798:
    // 0x80021798: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002179C: bne         $v0, $at, L_800217B0
    if (ctx->r2 != ctx->r1) {
        // 0x800217A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800217B0;
    }
    // 0x800217A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800217A4: bne         $t7, $at, L_800217B0
    if (ctx->r15 != ctx->r1) {
        // 0x800217A8: nop
    
            goto L_800217B0;
    }
    // 0x800217A8: nop

    // 0x800217AC: break       6
    do_break(2147620780);
L_800217B0:
    // 0x800217B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800217B4: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800217B8: beql        $at, $zero, L_800218B8
    if (ctx->r1 == 0) {
        // 0x800217BC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800218B8;
    }
    goto skip_0;
    // 0x800217BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800217C0: multu       $s3, $v0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800217C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800217C8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x800217CC: mflo        $t9
    ctx->r25 = lo;
    // 0x800217D0: addu        $s4, $s4, $t9
    ctx->r20 = ADD32(ctx->r20, ctx->r25);
    // 0x800217D4: bgez        $s1, L_800217E4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800217D8: addiu       $s4, $s4, -0x7
        ctx->r20 = ADD32(ctx->r20, -0X7);
            goto L_800217E4;
    }
    // 0x800217D8: addiu       $s4, $s4, -0x7
    ctx->r20 = ADD32(ctx->r20, -0X7);
    // 0x800217DC: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x800217E0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800217E4:
    // 0x800217E4: bgtz        $s0, L_800217F0
    if (SIGNED(ctx->r16) > 0) {
        // 0x800217E8: slt         $at, $s6, $s3
        ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800217F0;
    }
    // 0x800217E8: slt         $at, $s6, $s3
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800217EC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
L_800217F0:
    // 0x800217F0: beq         $at, $zero, L_8002189C
    if (ctx->r1 == 0) {
        // 0x800217F4: nop
    
            goto L_8002189C;
    }
    // 0x800217F4: nop

L_800217F8:
    // 0x800217F8: div         $zero, $s1, $s2
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r18)));
    // 0x800217FC: mfhi        $a2
    ctx->r6 = hi;
    // 0x80021800: sltiu       $a3, $s0, 0x1
    ctx->r7 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80021804: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80021808: andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
    // 0x8002180C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80021810: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80021814: bne         $s2, $zero, L_80021820
    if (ctx->r18 != 0) {
        // 0x80021818: nop
    
            goto L_80021820;
    }
    // 0x80021818: nop

    // 0x8002181C: break       7
    do_break(2147620892);
L_80021820:
    // 0x80021820: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021824: bne         $s2, $at, L_80021838
    if (ctx->r18 != ctx->r1) {
        // 0x80021828: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021838;
    }
    // 0x80021828: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002182C: bne         $s1, $at, L_80021838
    if (ctx->r17 != ctx->r1) {
        // 0x80021830: nop
    
            goto L_80021838;
    }
    // 0x80021830: nop

    // 0x80021834: break       6
    do_break(2147620916);
L_80021838:
    // 0x80021838: jal         0x800210C0
    // 0x8002183C: nop

    func_800210C0(rdram, ctx);
        goto after_0;
    // 0x8002183C: nop

    after_0:
    // 0x80021840: div         $zero, $s1, $s2
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r18)));
    // 0x80021844: bne         $s2, $zero, L_80021850
    if (ctx->r18 != 0) {
        // 0x80021848: nop
    
            goto L_80021850;
    }
    // 0x80021848: nop

    // 0x8002184C: break       7
    do_break(2147620940);
L_80021850:
    // 0x80021850: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021854: bne         $s2, $at, L_80021868
    if (ctx->r18 != ctx->r1) {
        // 0x80021858: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021868;
    }
    // 0x80021858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002185C: bne         $s1, $at, L_80021868
    if (ctx->r17 != ctx->r1) {
        // 0x80021860: nop
    
            goto L_80021868;
    }
    // 0x80021860: nop

    // 0x80021864: break       6
    do_break(2147620964);
L_80021868:
    // 0x80021868: mflo        $s1
    ctx->r17 = lo;
    // 0x8002186C: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80021870: beql        $s5, $zero, L_80021894
    if (ctx->r21 == 0) {
        // 0x80021874: slt         $at, $s6, $s3
        ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80021894;
    }
    goto skip_1;
    // 0x80021874: slt         $at, $s6, $s3
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
    skip_1:
    // 0x80021878: bnel        $s1, $zero, L_80021894
    if (ctx->r17 != 0) {
        // 0x8002187C: slt         $at, $s6, $s3
        ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80021894;
    }
    goto skip_2;
    // 0x8002187C: slt         $at, $s6, $s3
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
    skip_2:
    // 0x80021880: bgezl       $s0, L_80021894
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80021884: slt         $at, $s6, $s3
        ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80021894;
    }
    goto skip_3;
    // 0x80021884: slt         $at, $s6, $s3
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
    // 0x80021888: b           L_8002189C
    // 0x8002188C: addiu       $s4, $s4, -0x7
    ctx->r20 = ADD32(ctx->r20, -0X7);
        goto L_8002189C;
    // 0x8002188C: addiu       $s4, $s4, -0x7
    ctx->r20 = ADD32(ctx->r20, -0X7);
    // 0x80021890: slt         $at, $s6, $s3
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r19) ? 1 : 0;
L_80021894:
    // 0x80021894: bne         $at, $zero, L_800217F8
    if (ctx->r1 != 0) {
        // 0x80021898: addiu       $s4, $s4, -0x7
        ctx->r20 = ADD32(ctx->r20, -0X7);
            goto L_800217F8;
    }
    // 0x80021898: addiu       $s4, $s4, -0x7
    ctx->r20 = ADD32(ctx->r20, -0X7);
L_8002189C:
    // 0x8002189C: beq         $s6, $zero, L_800218B4
    if (ctx->r22 == 0) {
        // 0x800218A0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800218B4;
    }
    // 0x800218A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800218A4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800218A8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800218AC: jal         0x800210C0
    // 0x800218B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800210C0(rdram, ctx);
        goto after_1;
    // 0x800218B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_800218B4:
    // 0x800218B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800218B8:
    // 0x800218B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800218BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800218C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800218C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800218C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800218CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800218D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800218D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800218D8: jr          $ra
    // 0x800218DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800218DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void n_alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D788: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002D78C: beql        $t6, $zero, L_8002D7E0
    if (ctx->r14 == 0) {
        // 0x8002D790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002D7E0;
    }
    goto skip_0;
    // 0x8002D790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002D794: jal         0x8002C618
    // 0x8002D798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002D798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002D79C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002D7A0: beq         $v0, $zero, L_8002D7DC
    if (ctx->r2 == 0) {
        // 0x8002D7A4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002D7DC;
    }
    // 0x8002D7A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002D7A8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002D7AC: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002D7B0: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002D7B4: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8002D7B8: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002D7BC: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002D7C0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002D7C4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002D7C8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002D7CC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002D7D0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x8002D7D4: jal         0x8002A230
    // 0x8002D7D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002D7D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_8002D7DC:
    // 0x8002D7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002D7E0:
    // 0x8002D7E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D7E4: jr          $ra
    // 0x8002D7E8: nop

    return;
    // 0x8002D7E8: nop

;}
RECOMP_FUNC void ftKirbySpecialLwUnkDecideNextStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801615E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801615E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801615EC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801615F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801615F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801615F8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801615FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80161600: lw          $t6, 0x190($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X190);
    // 0x80161604: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x80161608: bltzl       $t8, L_80161650
    if (SIGNED(ctx->r24) < 0) {
        // 0x8016160C: lw          $t3, 0x184($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X184);
            goto L_80161650;
    }
    goto skip_0;
    // 0x8016160C: lw          $t3, 0x184($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x80161610: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x80161614: beql        $t9, $zero, L_80161650
    if (ctx->r25 == 0) {
        // 0x80161618: lw          $t3, 0x184($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X184);
            goto L_80161650;
    }
    goto skip_1;
    // 0x80161618: lw          $t3, 0x184($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X184);
    skip_1:
    // 0x8016161C: bne         $a1, $zero, L_80161638
    if (ctx->r5 != 0) {
        // 0x80161620: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80161638;
    }
    // 0x80161620: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161624: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80161628: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8016162C: addiu       $a1, $zero, 0x106
    ctx->r5 = ADD32(0, 0X106);
    // 0x80161630: jal         0x800E6F24
    // 0x80161634: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161634: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
L_80161638:
    // 0x80161638: jal         0x8016141C
    // 0x8016163C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftKirbySpecialLwSetDamageResist(rdram, ctx);
        goto after_1;
    // 0x8016163C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80161640: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80161644: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x80161648: sw          $t2, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->r10;
    // 0x8016164C: lw          $t3, 0x184($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X184);
L_80161650:
    // 0x80161650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80161654: beql        $t3, $zero, L_801616A0
    if (ctx->r11 == 0) {
        // 0x80161658: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801616A0;
    }
    goto skip_2;
    // 0x80161658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8016165C: jal         0x801614B4
    // 0x80161660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftKirbySpecialLwCheckRelease(rdram, ctx);
        goto after_2;
    // 0x80161660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80161664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80161668: bne         $v0, $at, L_80161694
    if (ctx->r2 != ctx->r1) {
        // 0x8016166C: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_80161694;
    }
    // 0x8016166C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80161670: bne         $t4, $zero, L_80161688
    if (ctx->r12 != 0) {
        // 0x80161674: nop
    
            goto L_80161688;
    }
    // 0x80161674: nop

    // 0x80161678: jal         0x80161B2C
    // 0x8016167C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftKirbySpecialLwEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x8016167C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80161680: b           L_80161694
    // 0x80161684: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
        goto L_80161694;
    // 0x80161684: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
L_80161688:
    // 0x80161688: jal         0x80161C5C
    // 0x8016168C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftKirbySpecialAirLwEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x8016168C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80161690: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
L_80161694:
    // 0x80161694: jal         0x80161368
    // 0x80161698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftKirbySpecialLwUpdateColAnim(rdram, ctx);
        goto after_5;
    // 0x80161698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8016169C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801616A0:
    // 0x801616A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801616A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801616A8: jr          $ra
    // 0x801616AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801616AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gcGetAnimTotalLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800105AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800105B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800105B4: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x800105B8: bnel        $v0, $zero, L_800105D4
    if (ctx->r2 != 0) {
        // 0x800105BC: lw          $a1, 0x0($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X0);
            goto L_800105D4;
    }
    goto skip_0;
    // 0x800105BC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800105C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800105C4:
    // 0x800105C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800105C8: beql        $v0, $zero, L_800105C4
    if (ctx->r2 == 0) {
        // 0x800105CC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800105C4;
    }
    goto skip_1;
    // 0x800105CC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x800105D0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
L_800105D4:
    // 0x800105D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800105D8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800105DC: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_800105E0:
    // 0x800105E0: sltiu       $at, $a2, 0x12
    ctx->r1 = ctx->r6 < 0X12 ? 1 : 0;
L_800105E4:
    // 0x800105E4: beql        $at, $zero, L_800105E4
    if (ctx->r1 == 0) {
        // 0x800105E8: sltiu       $at, $a2, 0x12
        ctx->r1 = ctx->r6 < 0X12 ? 1 : 0;
            goto L_800105E4;
    }
    goto skip_2;
    // 0x800105E8: sltiu       $at, $a2, 0x12
    ctx->r1 = ctx->r6 < 0X12 ? 1 : 0;
    skip_2:
    // 0x800105EC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800105F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800105F4: addu        $at, $at, $t6
    gpr jr_addend_800105FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800105F8: lw          $t6, -0x1F3C($at)
    ctx->r14 = ADD32(ctx->r1, -0X1F3C);
    // 0x800105FC: jr          $t6
    // 0x80010600: nop

    switch (jr_addend_800105FC >> 2) {
        case 0: goto L_800106FC; break;
        case 1: goto L_80010704; break;
        case 2: goto L_80010684; break;
        case 3: goto L_80010604; break;
        case 4: goto L_8001060C; break;
        case 5: goto L_80010644; break;
        case 6: goto L_8001064C; break;
        case 7: goto L_8001060C; break;
        case 8: goto L_80010604; break;
        case 9: goto L_8001060C; break;
        case 10: goto L_80010604; break;
        case 11: goto L_8001060C; break;
        case 12: goto L_8001069C; break;
        case 13: goto L_800106AC; break;
        case 14: goto L_80010704; break;
        case 15: goto L_80010684; break;
        case 16: goto L_800105E0; break;
        case 17: goto L_800106BC; break;
        default: switch_error(__func__, 0x800105FC, 0x8003E0C4);
    }
    // 0x80010600: nop

L_80010604:
    // 0x80010604: andi        $t7, $a1, 0x7FFF
    ctx->r15 = ctx->r5 & 0X7FFF;
    // 0x80010608: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
L_8001060C:
    // 0x8001060C: sll         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5 << 7);
    // 0x80010610: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x80010614: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001061C:
    // 0x8001061C: beq         $v0, $zero, L_80010638
    if (ctx->r2 == 0) {
        // 0x80010620: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_80010638;
    }
    // 0x80010620: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80010624: beq         $t8, $zero, L_80010630
    if (ctx->r24 == 0) {
        // 0x80010628: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80010630;
    }
    // 0x80010628: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001062C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80010630:
    // 0x80010630: bne         $a2, $a3, L_8001061C
    if (ctx->r6 != ctx->r7) {
        // 0x80010634: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_8001061C;
    }
    // 0x80010634: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
L_80010638:
    // 0x80010638: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001063C: b           L_800105E0
    // 0x80010640: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x80010640: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_80010644:
    // 0x80010644: andi        $t9, $a1, 0x7FFF
    ctx->r25 = ctx->r5 & 0X7FFF;
    // 0x80010648: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
L_8001064C:
    // 0x8001064C: sll         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5 << 7);
    // 0x80010650: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x80010654: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8001065C:
    // 0x8001065C: beq         $v0, $zero, L_80010678
    if (ctx->r2 == 0) {
        // 0x80010660: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_80010678;
    }
    // 0x80010660: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80010664: beq         $t1, $zero, L_80010670
    if (ctx->r9 == 0) {
        // 0x80010668: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80010670;
    }
    // 0x80010668: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001066C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80010670:
    // 0x80010670: bne         $a2, $a3, L_8001065C
    if (ctx->r6 != ctx->r7) {
        // 0x80010674: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_8001065C;
    }
    // 0x80010674: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
L_80010678:
    // 0x80010678: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001067C: b           L_800105E0
    // 0x80010680: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x80010680: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_80010684:
    // 0x80010684: andi        $t2, $a1, 0x7FFF
    ctx->r10 = ctx->r5 & 0X7FFF;
    // 0x80010688: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8001068C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80010690: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010694: b           L_800105E0
    // 0x80010698: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x80010698: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_8001069C:
    // 0x8001069C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800106A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800106A4: b           L_800105E0
    // 0x800106A8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x800106A8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_800106AC:
    // 0x800106AC: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800106B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800106B4: b           L_800105E0
    // 0x800106B8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x800106B8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_800106BC:
    // 0x800106BC: andi        $t3, $a1, 0x7FFF
    ctx->r11 = ctx->r5 & 0X7FFF;
    // 0x800106C0: sll         $v0, $a1, 7
    ctx->r2 = S32(ctx->r5 << 7);
    // 0x800106C4: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800106C8: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x800106CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800106D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_800106D4:
    // 0x800106D4: beq         $v0, $zero, L_800106F0
    if (ctx->r2 == 0) {
        // 0x800106D8: andi        $t4, $v0, 0x1
        ctx->r12 = ctx->r2 & 0X1;
            goto L_800106F0;
    }
    // 0x800106D8: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800106DC: beq         $t4, $zero, L_800106E8
    if (ctx->r12 == 0) {
        // 0x800106E0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800106E8;
    }
    // 0x800106E0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800106E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800106E8:
    // 0x800106E8: bne         $a2, $t0, L_800106D4
    if (ctx->r6 != ctx->r8) {
        // 0x800106EC: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_800106D4;
    }
    // 0x800106EC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
L_800106F0:
    // 0x800106F0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800106F4: b           L_800105E0
    // 0x800106F8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
        goto L_800105E0;
    // 0x800106F8: srl         $a2, $a1, 25
    ctx->r6 = S32(U32(ctx->r5) >> 25);
L_800106FC:
    // 0x800106FC: jr          $ra
    // 0x80010700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80010700: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80010704:
    // 0x80010704: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80010708: jr          $ra
    // 0x8001070C: nop

    return;
    // 0x8001070C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusInitSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C14: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80136C18: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80136C1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80136C20: lw          $t7, 0x76D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X76D8);
    // 0x80136C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136C28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80136C30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80136C34: beq         $t7, $at, L_80136C4C
    if (ctx->r15 == ctx->r1) {
        // 0x80136C38: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80136C4C;
    }
    // 0x80136C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136C3C: jal         0x80135EE8
    // 0x80136C40: nop

    mnPlayers1PBonusMakeCursor(rdram, ctx);
        goto after_0;
    // 0x80136C40: nop

    after_0:
    // 0x80136C44: b           L_80136C54
    // 0x80136C48: nop

        goto L_80136C54;
    // 0x80136C48: nop

L_80136C4C:
    // 0x80136C4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136C50: sw          $zero, 0x7648($at)
    MEM_W(0X7648, ctx->r1) = 0;
L_80136C54:
    // 0x80136C54: jal         0x80136034
    // 0x80136C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusMakePuck(rdram, ctx);
        goto after_1;
    // 0x80136C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80136C5C: jal         0x80132EEC
    // 0x80136C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusMakeGate(rdram, ctx);
        goto after_2;
    // 0x80136C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80136C64: jal         0x80134724
    // 0x80136C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusResetPlayer(rdram, ctx);
        goto after_3;
    // 0x80136C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80136C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80136C70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80136C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80136C78: jr          $ra
    // 0x80136C7C: nop

    return;
    // 0x80136C7C: nop

;}
RECOMP_FUNC void wpPikachuThunderTrailMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016A984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A988: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8016A98C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016A990: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016A994: addiu       $a1, $a1, -0x6EAC
    ctx->r5 = ADD32(ctx->r5, -0X6EAC);
    // 0x8016A998: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8016A99C: jal         0x801655C8
    // 0x8016A9A0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016A9A0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8016A9A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A9A8: bne         $v0, $zero, L_8016A9B8
    if (ctx->r2 != 0) {
        // 0x8016A9AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8016A9B8;
    }
    // 0x8016A9AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8016A9B0: b           L_8016AA30
    // 0x8016A9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016AA30;
    // 0x8016A9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016A9B8:
    // 0x8016A9B8: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8016A9BC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8016A9C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8016A9C4: sw          $t6, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r14;
    // 0x8016A9C8: lw          $t7, 0x264($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X264);
    // 0x8016A9CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016A9D0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8016A9D4: sw          $t7, 0x264($a0)
    MEM_W(0X264, ctx->r4) = ctx->r15;
    // 0x8016A9D8: lw          $t9, 0x214($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X214);
    // 0x8016A9DC: sw          $t9, 0x214($a0)
    MEM_W(0X214, ctx->r4) = ctx->r25;
    // 0x8016A9E0: lw          $t8, 0x218($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X218);
    // 0x8016A9E4: sw          $t8, 0x218($a0)
    MEM_W(0X218, ctx->r4) = ctx->r24;
    // 0x8016A9E8: lw          $t2, 0x21C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X21C);
    // 0x8016A9EC: sw          $t2, 0x21C($a0)
    MEM_W(0X21C, ctx->r4) = ctx->r10;
    // 0x8016A9F0: lw          $t1, 0x220($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X220);
    // 0x8016A9F4: sw          $t1, 0x220($a0)
    MEM_W(0X220, ctx->r4) = ctx->r9;
    // 0x8016A9F8: lw          $t4, 0x224($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X224);
    // 0x8016A9FC: sw          $t4, 0x224($a0)
    MEM_W(0X224, ctx->r4) = ctx->r12;
    // 0x8016AA00: lw          $t3, 0x228($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X228);
    // 0x8016AA04: sw          $t3, 0x228($a0)
    MEM_W(0X228, ctx->r4) = ctx->r11;
    // 0x8016AA08: lw          $t6, 0x22C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X22C);
    // 0x8016AA0C: sw          $t6, 0x22C($a0)
    MEM_W(0X22C, ctx->r4) = ctx->r14;
    // 0x8016AA10: lw          $t5, 0x230($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X230);
    // 0x8016AA14: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8016AA18: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x8016AA1C: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
    // 0x8016AA20: lw          $t8, 0x74($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X74);
    // 0x8016AA24: swc1        $f0, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f0.u32l;
    // 0x8016AA28: lw          $t9, 0x74($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X74);
    // 0x8016AA2C: swc1        $f0, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f0.u32l;
L_8016AA30:
    // 0x8016AA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AA34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016AA38: jr          $ra
    // 0x8016AA3C: nop

    return;
    // 0x8016AA3C: nop

;}
RECOMP_FUNC void mpCollisionGetLRCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3E30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800F3E34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F3E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3E3C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800F3E40: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800F3E44: beq         $a0, $at, L_800F3E58
    if (ctx->r4 == ctx->r1) {
        // 0x800F3E48: sw          $a3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r7;
            goto L_800F3E58;
    }
    // 0x800F3E48: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800F3E4C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800F3E50: bne         $a0, $at, L_800F3E78
    if (ctx->r4 != ctx->r1) {
        // 0x800F3E54: lw          $t8, 0x48($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X48);
            goto L_800F3E78;
    }
    // 0x800F3E54: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
L_800F3E58:
    // 0x800F3E58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3E5C: addiu       $a0, $a0, 0x2CC
    ctx->r4 = ADD32(ctx->r4, 0X2CC);
    // 0x800F3E60: jal         0x80023624
    // 0x800F3E64: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800F3E64: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800F3E68: jal         0x800A3040
    // 0x800F3E6C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800F3E6C: nop

    after_1:
    // 0x800F3E70: b           L_800F3E58
    // 0x800F3E74: nop

        goto L_800F3E58;
    // 0x800F3E74: nop

L_800F3E78:
    // 0x800F3E78: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F3E7C: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F3E80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800F3E84: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800F3E88: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800F3E8C: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x800F3E90: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800F3E94: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F3E98: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F3E9C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800F3EA0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F3EA4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800F3EA8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800F3EAC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800F3EB0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F3EB4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F3EB8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F3EBC: bne         $at, $zero, L_800F3EDC
    if (ctx->r1 != 0) {
        // 0x800F3EC0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800F3EDC;
    }
L_800F3EC0:
    // 0x800F3EC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3EC4: jal         0x80023624
    // 0x800F3EC8: addiu       $a0, $a0, 0x2E8
    ctx->r4 = ADD32(ctx->r4, 0X2E8);
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800F3EC8: addiu       $a0, $a0, 0x2E8
    ctx->r4 = ADD32(ctx->r4, 0X2E8);
    after_2:
    // 0x800F3ECC: jal         0x800A3040
    // 0x800F3ED0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800F3ED0: nop

    after_3:
    // 0x800F3ED4: b           L_800F3EC0
    // 0x800F3ED8: nop

        goto L_800F3EC0;
    // 0x800F3ED8: nop

L_800F3EDC:
    // 0x800F3EDC: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F3EE0: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F3EE4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800F3EE8: bne         $t8, $zero, L_800F3EF8
    if (ctx->r24 != 0) {
        // 0x800F3EEC: addu        $t3, $t4, $t5
        ctx->r11 = ADD32(ctx->r12, ctx->r13);
            goto L_800F3EF8;
    }
    // 0x800F3EEC: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800F3EF0: beql        $v1, $zero, L_800F3F18
    if (ctx->r3 == 0) {
        // 0x800F3EF4: lwc1        $f16, 0x0($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
            goto L_800F3F18;
    }
    goto skip_0;
    // 0x800F3EF4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
L_800F3EF8:
    // 0x800F3EF8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F3EFC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F3F00: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F3F04: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F3F08: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F3F0C: b           L_800F3F1C
    // 0x800F3F10: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_800F3F1C;
    // 0x800F3F10: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F3F14: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
L_800F3F18:
    // 0x800F3F18: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
L_800F3F1C:
    // 0x800F3F1C: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
    // 0x800F3F20: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800F3F24: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800F3F28: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800F3F2C: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x800F3F30: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F3F34: lhu         $t2, 0x2($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X2);
    // 0x800F3F38: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800F3F3C: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3F40: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800F3F44: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800F3F48: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800F3F4C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x800F3F50: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F3F54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3F58: lw          $a0, 0x1370($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1370);
    // 0x800F3F5C: mflo        $t9
    ctx->r25 = lo;
    // 0x800F3F60: addu        $a1, $a0, $t9
    ctx->r5 = ADD32(ctx->r4, ctx->r25);
    // 0x800F3F64: lh          $a2, 0x2($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X2);
    // 0x800F3F68: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3F6C: mflo        $t9
    ctx->r25 = lo;
    // 0x800F3F70: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x800F3F74: lh          $t0, 0x2($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X2);
    // 0x800F3F78: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800F3F7C: beql        $at, $zero, L_800F3F9C
    if (ctx->r1 == 0) {
        // 0x800F3F80: mtc1        $t0, $f6
        ctx->f6.u32l = ctx->r8;
            goto L_800F3F9C;
    }
    goto skip_1;
    // 0x800F3F80: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    skip_1:
    // 0x800F3F84: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x800F3F88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800F3F8C: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F3F90: b           L_800F3FA8
    // 0x800F3F94: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
        goto L_800F3FA8;
    // 0x800F3F94: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3F98: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800F3F9C:
    // 0x800F3F9C: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800F3FA0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F3FA4: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
L_800F3FA8:
    // 0x800F3FA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F3FAC: lwc1        $f0, 0x774($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X774);
    // 0x800F3FB0: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800F3FB4: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x800F3FB8: nop

    // 0x800F3FBC: bc1t        L_800F3FDC
    if (c1cs) {
        // 0x800F3FC0: nop
    
            goto L_800F3FDC;
    }
    // 0x800F3FC0: nop

    // 0x800F3FC4: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3FC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F3FCC: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800F3FD0: nop

    // 0x800F3FD4: bc1fl       L_800F3FE8
    if (!c1cs) {
        // 0x800F3FD8: c.le.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
            goto L_800F3FE8;
    }
    goto skip_2;
    // 0x800F3FD8: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    skip_2:
L_800F3FDC:
    // 0x800F3FDC: b           L_800F4184
    // 0x800F3FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4184;
    // 0x800F3FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3FE4: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
L_800F3FE8:
    // 0x800F3FE8: nop

    // 0x800F3FEC: bc1fl       L_800F4000
    if (!c1cs) {
        // 0x800F3FF0: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_800F4000;
    }
    goto skip_3;
    // 0x800F3FF0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_3:
    // 0x800F3FF4: b           L_800F4010
    // 0x800F3FF8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_800F4010;
    // 0x800F3FF8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800F3FFC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_800F4000:
    // 0x800F4000: nop

    // 0x800F4004: bc1f        L_800F4010
    if (!c1cs) {
        // 0x800F4008: nop
    
            goto L_800F4010;
    }
    // 0x800F4008: nop

    // 0x800F400C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800F4010:
    // 0x800F4010: beql        $t2, $at, L_800F40F0
    if (ctx->r10 == ctx->r1) {
        // 0x800F4014: lh          $t8, 0x0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X0);
            goto L_800F40F0;
    }
    goto skip_4;
    // 0x800F4014: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    skip_4:
    // 0x800F4018: blez        $t2, L_800F40EC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800F401C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F40EC;
    }
    // 0x800F401C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4020:
    // 0x800F4020: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800F4024: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F4028: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F402C: mflo        $t8
    ctx->r24 = lo;
    // 0x800F4030: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x800F4034: lh          $a2, 0x2($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X2);
    // 0x800F4038: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F403C: mflo        $t7
    ctx->r15 = lo;
    // 0x800F4040: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800F4044: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x800F4048: bnel        $t0, $a2, L_800F4070
    if (ctx->r8 != ctx->r6) {
        // 0x800F404C: mtc1        $a2, $f4
        ctx->f4.u32l = ctx->r6;
            goto L_800F4070;
    }
    goto skip_5;
    // 0x800F404C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    skip_5:
L_800F4050:
    // 0x800F4050: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4054: jal         0x80023624
    // 0x800F4058: addiu       $a0, $a0, 0x308
    ctx->r4 = ADD32(ctx->r4, 0X308);
    syDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x800F4058: addiu       $a0, $a0, 0x308
    ctx->r4 = ADD32(ctx->r4, 0X308);
    after_4:
    // 0x800F405C: jal         0x800A3040
    // 0x800F4060: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_5;
    // 0x800F4060: nop

    after_5:
    // 0x800F4064: b           L_800F4050
    // 0x800F4068: nop

        goto L_800F4050;
    // 0x800F4068: nop

    // 0x800F406C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
L_800F4070:
    // 0x800F4070: nop

    // 0x800F4074: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F4078: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800F407C: nop

    // 0x800F4080: bc1fl       L_800F40A8
    if (!c1cs) {
        // 0x800F4084: mtc1        $t0, $f10
        ctx->f10.u32l = ctx->r8;
            goto L_800F40A8;
    }
    goto skip_6;
    // 0x800F4084: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    skip_6:
    // 0x800F4088: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800F408C: nop

    // 0x800F4090: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4094: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800F4098: nop

    // 0x800F409C: bc1tl       L_800F40F0
    if (c1cs) {
        // 0x800F40A0: lh          $t8, 0x0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X0);
            goto L_800F40F0;
    }
    goto skip_7;
    // 0x800F40A0: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    skip_7:
    // 0x800F40A4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
L_800F40A8:
    // 0x800F40A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F40AC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F40B0: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800F40B4: nop

    // 0x800F40B8: bc1f        L_800F40D0
    if (!c1cs) {
        // 0x800F40BC: nop
    
            goto L_800F40D0;
    }
    // 0x800F40BC: nop

    // 0x800F40C0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800F40C4: nop

    // 0x800F40C8: bc1tl       L_800F40F0
    if (c1cs) {
        // 0x800F40CC: lh          $t8, 0x0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X0);
            goto L_800F40F0;
    }
    goto skip_8;
    // 0x800F40CC: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    skip_8:
L_800F40D0:
    // 0x800F40D0: bne         $v0, $t2, L_800F4020
    if (ctx->r2 != ctx->r10) {
        // 0x800F40D4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800F4020;
    }
    // 0x800F40D4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800F40D8: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F40DC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800F40E0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800F40E4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800F40E8: addu        $a1, $a0, $t5
    ctx->r5 = ADD32(ctx->r4, ctx->r13);
L_800F40EC:
    // 0x800F40EC: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
L_800F40F0:
    // 0x800F40F0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800F40F4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800F40F8: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F40FC: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4100: mflo        $t7
    ctx->r15 = lo;
    // 0x800F4104: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800F4108: lh          $t4, 0x0($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X0);
    // 0x800F410C: beq         $t5, $zero, L_800F411C
    if (ctx->r13 == 0) {
        // 0x800F4110: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800F411C;
    }
    // 0x800F4110: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800F4114: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x800F4118: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
L_800F411C:
    // 0x800F411C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800F4120: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800F4124: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800F4128: beql        $t6, $zero, L_800F4160
    if (ctx->r14 == 0) {
        // 0x800F412C: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_800F4160;
    }
    goto skip_9;
    // 0x800F412C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    skip_9:
    // 0x800F4130: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800F4134: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F4138: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800F413C: jal         0x800F3A34
    // 0x800F4140: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    mpCollisionGetLineDistanceLR(rdram, ctx);
        goto after_6;
    // 0x800F4140: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x800F4144: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F4148: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800F414C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800F4150: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800F4154: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800F4158: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x800F415C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_800F4160:
    // 0x800F4160: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800F4164: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800F4168: beql        $a0, $zero, L_800F4184
    if (ctx->r4 == 0) {
        // 0x800F416C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F4184;
    }
    goto skip_10;
    // 0x800F416C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_10:
    // 0x800F4170: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800F4174: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800F4178: jal         0x800F71A0
    // 0x800F417C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    mpCollisionGetLRAngle(rdram, ctx);
        goto after_7;
    // 0x800F417C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_7:
    // 0x800F4180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F4184:
    // 0x800F4184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800F418C: jr          $ra
    // 0x800F4190: nop

    return;
    // 0x800F4190: nop

;}
RECOMP_FUNC void ftBossWalkLoopProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015996C: jal         0x801598C0
    // 0x80159970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftBossWalkLoopCheckPlayerInRange(rdram, ctx);
        goto after_0;
    // 0x80159970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159974: beql        $v0, $zero, L_80159988
    if (ctx->r2 == 0) {
        // 0x80159978: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80159988;
    }
    goto skip_0;
    // 0x80159978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015997C: jal         0x80159AC4
    // 0x80159980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossWalkShootSetStatus(rdram, ctx);
        goto after_1;
    // 0x80159980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80159984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159988:
    // 0x80159988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015998C: jr          $ra
    // 0x80159990: nop

    return;
    // 0x80159990: nop

;}
RECOMP_FUNC void ftPublicCommonCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164F2C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80164F30: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80164F34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80164F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164F40: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80164F44: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80164F48: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164F4C: bc1fl       L_80164F64
    if (!c1cs) {
        // 0x80164F50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164F64;
    }
    goto skip_0;
    // 0x80164F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80164F54: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80164F58: jal         0x80164DE4
    // 0x80164F5C: lw          $a1, 0x808($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X808);
    ftPublicDecideCommon(rdram, ctx);
        goto after_0;
    // 0x80164F5C: lw          $a1, 0x808($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X808);
    after_0:
    // 0x80164F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164F64:
    // 0x80164F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164F68: jr          $ra
    // 0x80164F6C: nop

    return;
    // 0x80164F6C: nop

;}
RECOMP_FUNC void gmCameraSetViewportDimensions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E598: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E59C: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010E5A0: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x8010E5A4: addu        $t8, $a1, $a3
    ctx->r24 = ADD32(ctx->r5, ctx->r7);
    // 0x8010E5A8: subu        $t0, $a2, $a0
    ctx->r8 = SUB32(ctx->r6, ctx->r4);
    // 0x8010E5AC: subu        $t1, $a3, $a1
    ctx->r9 = SUB32(ctx->r7, ctx->r5);
    // 0x8010E5B0: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    // 0x8010E5B4: sw          $a1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r5;
    // 0x8010E5B8: sw          $a2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r6;
    // 0x8010E5BC: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x8010E5C0: bgez        $t6, L_8010E5D0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8010E5C4: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8010E5D0;
    }
    // 0x8010E5C4: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8010E5C8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8010E5CC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8010E5D0:
    // 0x8010E5D0: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x8010E5D4: bgez        $t8, L_8010E5E4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010E5D8: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8010E5E4;
    }
    // 0x8010E5D8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8010E5DC: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8010E5E0: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8010E5E4:
    // 0x8010E5E4: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
    // 0x8010E5E8: sw          $t0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r8;
    // 0x8010E5EC: jr          $ra
    // 0x8010E5F0: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    return;
    // 0x8010E5F0: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void itMainSetGroundAllowPickup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80172E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172E7C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80172E80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80172E84: lbu         $t7, 0x2CE($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2CE);
    // 0x80172E88: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x80172E8C: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
    // 0x80172E90: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x80172E94: andi        $t0, $t9, 0xCF
    ctx->r8 = ctx->r25 & 0XCF;
    // 0x80172E98: sb          $t9, 0x2CE($a1)
    MEM_B(0X2CE, ctx->r5) = ctx->r25;
    // 0x80172E9C: sb          $t0, 0x2CE($a1)
    MEM_B(0X2CE, ctx->r5) = ctx->r8;
    // 0x80172EA0: swc1        $f0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f0.u32l;
    // 0x80172EA4: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x80172EA8: jal         0x801725BC
    // 0x80172EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    itMainResetPlayerVars(rdram, ctx);
        goto after_0;
    // 0x80172EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80172EB0: jal         0x80173F54
    // 0x80172EB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    itMapSetGround(rdram, ctx);
        goto after_1;
    // 0x80172EB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80172EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172EBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80172EC0: jr          $ra
    // 0x80172EC4: nop

    return;
    // 0x80172EC4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeHaze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E14: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131E18: jal         0x80009968
    // 0x80131E1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E24: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131E28: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131E2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E30: addiu       $t7, $t7, -0x6708
    ctx->r15 = ADD32(ctx->r15, -0X6708);
    // 0x80131E34: sw          $v0, 0x4D1C($at)
    MEM_W(0X4D1C, ctx->r1) = ctx->r2;
    // 0x80131E38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131E3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E40: jal         0x800092D0
    // 0x80131E44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131E44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E4C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131E50: jal         0x80008CC0
    // 0x80131E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80131E54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80131E58: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E5C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131E60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131E64: addiu       $a1, $a1, 0x43FC
    ctx->r5 = ADD32(ctx->r5, 0X43FC);
    // 0x80131E68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131E70: jal         0x80009DF4
    // 0x80131E74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80131E74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E80: jr          $ra
    // 0x80131E84: nop

    return;
    // 0x80131E84: nop

;}
RECOMP_FUNC void mnTitleMakeSlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013366C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80133670: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80133674: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80133678: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8013367C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80133680: bne         $t6, $at, L_8013375C
    if (ctx->r14 != ctx->r1) {
        // 0x80133684: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8013375C;
    }
    // 0x80133684: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133688: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8013368C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133690: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80133694: jal         0x80009968
    // 0x80133698: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133698: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013369C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801336A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801336A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801336A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801336AC: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x801336B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801336B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801336B8: jal         0x80009DF4
    // 0x801336BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801336BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801336C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801336C4: lw          $v0, 0x45A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X45A0);
    // 0x801336C8: lui         $t8, 0x3
    ctx->r24 = S32(0X3 << 16);
    // 0x801336CC: lui         $t9, 0x3
    ctx->r25 = S32(0X3 << 16);
    // 0x801336D0: addiu       $t9, $t9, -0x7828
    ctx->r25 = ADD32(ctx->r25, -0X7828);
    // 0x801336D4: addiu       $t8, $t8, -0x7258
    ctx->r24 = ADD32(ctx->r24, -0X7258);
    // 0x801336D8: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x801336DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801336E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801336E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801336E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801336EC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801336F0: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x801336F4: jal         0x8000F720
    // 0x801336F8: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    gcSetupCustomDObjsWithMObj(rdram, ctx);
        goto after_2;
    // 0x801336F8: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    after_2:
    // 0x801336FC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133700: lw          $t1, 0x45A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X45A0);
    // 0x80133704: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80133708: addiu       $t2, $t2, 0x5E70
    ctx->r10 = ADD32(ctx->r10, 0X5E70);
    // 0x8013370C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133710: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133714: jal         0x8000BD8C
    // 0x80133718: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80133718: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x8013371C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133720: lw          $t3, 0x45A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X45A0);
    // 0x80133724: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x80133728: addiu       $t4, $t4, 0x5F60
    ctx->r12 = ADD32(ctx->r12, 0X5F60);
    // 0x8013372C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133730: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133734: jal         0x8000BE28
    // 0x80133738: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80133738: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x8013373C: jal         0x8000DF34
    // 0x80133740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80133740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80133744: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133748: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x8013374C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133754: jal         0x80008188
    // 0x80133758: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80133758: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
L_8013375C:
    // 0x8013375C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80133760: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133764: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80133768: jr          $ra
    // 0x8013376C: nop

    return;
    // 0x8013376C: nop

;}
RECOMP_FUNC void mvOpeningLinkMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB44: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB4C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB50: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DB54: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DB58: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DB5C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DB60: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DB64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DB68: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DB6C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DB70: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DB74: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DB78: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DB7C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DB80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DB84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DB88: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DB8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DB90: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DB94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DB98: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DB9C: jal         0x8000B93C
    // 0x8018DBA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBAC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBB0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DBB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DBB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DBBC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DBC0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DBC4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DBC8: jal         0x80007080
    // 0x8018DBCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DBCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DBD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DBD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DBD8: jr          $ra
    // 0x8018DBDC: nop

    return;
    // 0x8018DBDC: nop

;}
RECOMP_FUNC void ftCommonDeadUpdateScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BD64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013BD68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BD6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013BD70: jal         0x8010F76C
    // 0x8013BD74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ifCommonPlayerDamageStartBreakAnim(rdram, ctx);
        goto after_0;
    // 0x8013BD74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8013BD78: jal         0x80114968
    // 0x8013BD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ifCommonPlayerStockMakeStockSnap(rdram, ctx);
        goto after_1;
    // 0x8013BD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013BD80: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x8013BD84: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013BD88: addiu       $a3, $a3, 0x50E8
    ctx->r7 = ADD32(ctx->r7, 0X50E8);
    // 0x8013BD8C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8013BD90: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8013BD94: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8013BD98: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013BD9C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013BDA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013BDA4: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8013BDA8: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x8013BDAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013BDB0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8013BDB4: sw          $t1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r9;
    // 0x8013BDB8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8013BDBC: lb          $t3, 0x1D($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1D);
    // 0x8013BDC0: bgezl       $t3, L_8013BDE0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8013BDC4: lw          $a0, 0x80C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X80C);
            goto L_8013BDE0;
    }
    goto skip_0;
    // 0x8013BDC4: lw          $a0, 0x80C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80C);
    skip_0:
    // 0x8013BDC8: jal         0x801149CC
    // 0x8013BDCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    ifCommonPlayerScoreMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8013BDCC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8013BDD0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013BDD4: addiu       $a3, $a3, 0x50E8
    ctx->r7 = ADD32(ctx->r7, 0X50E8);
    // 0x8013BDD8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8013BDDC: lw          $a0, 0x80C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80C);
L_8013BDE0:
    // 0x8013BDE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013BDE4: beq         $a0, $at, L_8013BE84
    if (ctx->r4 == ctx->r1) {
        // 0x8013BDE8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8013BE84;
    }
    // 0x8013BDE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013BDEC: beq         $a0, $at, L_8013BE84
    if (ctx->r4 == ctx->r1) {
        // 0x8013BDF0: addiu       $t0, $zero, 0x74
        ctx->r8 = ADD32(0, 0X74);
            goto L_8013BE84;
    }
    // 0x8013BDF0: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
    // 0x8013BDF4: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013BDF8: mflo        $t4
    ctx->r12 = lo;
    // 0x8013BDFC: addu        $v0, $a2, $t4
    ctx->r2 = ADD32(ctx->r6, ctx->r12);
    // 0x8013BE00: lw          $t5, 0x34($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X34);
    // 0x8013BE04: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8013BE08: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
    // 0x8013BE0C: lw          $t8, 0x80C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80C);
    // 0x8013BE10: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8013BE14: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x8013BE18: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8013BE1C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8013BE20: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013BE24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8013BE28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013BE2C: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x8013BE30: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8013BE34: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x8013BE38: lw          $t4, 0x38($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X38);
    // 0x8013BE3C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8013BE40: sw          $t5, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r13;
    // 0x8013BE44: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8013BE48: lb          $t8, 0x1D($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1D);
    // 0x8013BE4C: bgezl       $t8, L_8013BEB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8013BE50: lbu         $v0, 0x3($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X3);
            goto L_8013BEB4;
    }
    goto skip_1;
    // 0x8013BE50: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
    skip_1:
    // 0x8013BE54: lw          $t6, 0x80C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80C);
    // 0x8013BE58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013BE5C: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013BE60: mflo        $t9
    ctx->r25 = lo;
    // 0x8013BE64: addu        $t2, $a2, $t9
    ctx->r10 = ADD32(ctx->r6, ctx->r25);
    // 0x8013BE68: lw          $t1, 0x78($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X78);
    // 0x8013BE6C: jal         0x801149CC
    // 0x8013BE70: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    ifCommonPlayerScoreMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8013BE70: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    after_3:
    // 0x8013BE74: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013BE78: addiu       $a3, $a3, 0x50E8
    ctx->r7 = ADD32(ctx->r7, 0X50E8);
    // 0x8013BE7C: b           L_8013BEB0
    // 0x8013BE80: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
        goto L_8013BEB0;
    // 0x8013BE80: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
L_8013BE84:
    // 0x8013BE84: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x8013BE88: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8013BE8C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8013BE90: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8013BE94: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8013BE98: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8013BE9C: addu        $v0, $a2, $t4
    ctx->r2 = ADD32(ctx->r6, ctx->r12);
    // 0x8013BEA0: lw          $t5, 0x50($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X50);
    // 0x8013BEA4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8013BEA8: sw          $t7, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r15;
    // 0x8013BEAC: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
L_8013BEB0:
    // 0x8013BEB0: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
L_8013BEB4:
    // 0x8013BEB4: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8013BEB8: beql        $t8, $zero, L_8013BF14
    if (ctx->r24 == 0) {
        // 0x8013BEBC: andi        $t8, $v0, 0x8
        ctx->r24 = ctx->r2 & 0X8;
            goto L_8013BF14;
    }
    goto skip_2;
    // 0x8013BEBC: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
    skip_2:
    // 0x8013BEC0: lb          $t6, 0x14($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X14);
    // 0x8013BEC4: lbu         $t1, 0xD($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XD);
    // 0x8013BEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013BECC: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8013BED0: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x8013BED4: sb          $t9, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r25;
    // 0x8013BED8: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8013BEDC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8013BEE0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8013BEE4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8013BEE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8013BEEC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8013BEF0: lb          $t4, 0x2B($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2B);
    // 0x8013BEF4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8013BEF8: jal         0x8011388C
    // 0x8013BEFC: sb          $t5, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r13;
    ifCommonBattleUpdateScoreStocks(rdram, ctx);
        goto after_4;
    // 0x8013BEFC: sb          $t5, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r13;
    after_4:
    // 0x8013BF00: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013BF04: addiu       $a3, $a3, 0x50E8
    ctx->r7 = ADD32(ctx->r7, 0X50E8);
    // 0x8013BF08: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8013BF0C: lbu         $v0, 0x3($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X3);
    // 0x8013BF10: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
L_8013BF14:
    // 0x8013BF14: beql        $t8, $zero, L_8013BF70
    if (ctx->r24 == 0) {
        // 0x8013BF18: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_8013BF70;
    }
    goto skip_3;
    // 0x8013BF18: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    skip_3:
    // 0x8013BF1C: lb          $t6, 0x14($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X14);
    // 0x8013BF20: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x8013BF24: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x8013BF28: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8013BF2C: sb          $t9, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r25;
    // 0x8013BF30: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8013BF34: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8013BF38: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8013BF3C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8013BF40: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8013BF44: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x8013BF48: lb          $t4, 0x2B($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2B);
    // 0x8013BF4C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8013BF50: sb          $t5, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r13;
    // 0x8013BF54: lbu         $a1, 0x15($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X15);
    // 0x8013BF58: jal         0x8018EFFC
    // 0x8013BF5C: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    sc1PGameSetPlayerDefeatStats(rdram, ctx);
        goto after_5;
    // 0x8013BF5C: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_5:
    // 0x8013BF60: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8013BF64: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8013BF68: lbu         $v0, 0x3($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X3);
    // 0x8013BF6C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_8013BF70:
    // 0x8013BF70: beql        $t8, $zero, L_8013BF84
    if (ctx->r24 == 0) {
        // 0x8013BF74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013BF84;
    }
    goto skip_4;
    // 0x8013BF74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8013BF78: jal         0x80114C80
    // 0x8013BF7C: nop

    ifCommonAnnounceEndMessage(rdram, ctx);
        goto after_6;
    // 0x8013BF7C: nop

    after_6:
    // 0x8013BF80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013BF84:
    // 0x8013BF84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013BF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013BF8C: jr          $ra
    // 0x8013BF90: nop

    return;
    // 0x8013BF90: nop

;}
RECOMP_FUNC void mvOpeningSamusMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D40C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D410: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D418: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D41C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D424: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D428: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D42C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D430: addiu       $t6, $t6, -0x1EE0
    ctx->r14 = ADD32(ctx->r14, -0X1EE0);
    // 0x8018D434: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D438: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D43C: addiu       $s0, $s0, -0x1D68
    ctx->r16 = ADD32(ctx->r16, -0X1D68);
    // 0x8018D440: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D444: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D448: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D44C: addiu       $t9, $t9, -0x1EC4
    ctx->r25 = ADD32(ctx->r25, -0X1EC4);
    // 0x8018D450: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D454: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D458: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D45C: addiu       $s1, $s1, -0x1D48
    ctx->r17 = ADD32(ctx->r17, -0X1D48);
    // 0x8018D460: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D464: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D46C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D470: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D474: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D478: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D47C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D480: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D484: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D488: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D48C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D490: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D494: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D498: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D49C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D4A0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D4A4: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D4A8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D4AC: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D4B0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D4B4: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D4B8: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D4BC: jal         0x8010DB2C
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4C0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4C4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4C8: addiu       $v1, $v1, -0x1D78
    ctx->r3 = ADD32(ctx->r3, -0X1D78);
    // 0x8018D4CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4D0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4D4: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4DC: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    // 0x8018D4E0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018D4E4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D4E8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4EC: jal         0x80007080
    // 0x8018D4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D4F8: lwc1        $f6, -0x1DA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DA4);
    // 0x8018D4FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D500: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D504: jal         0x8000B39C
    // 0x8018D508: lw          $a0, -0x1D78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D78);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D508: lw          $a0, -0x1D78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D78);
    after_2:
    // 0x8018D50C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D510: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D514: addiu       $a1, $a1, -0x2CEC
    ctx->r5 = ADD32(ctx->r5, -0X2CEC);
    // 0x8018D518: lw          $a0, -0x1D78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D78);
    // 0x8018D51C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D520: jal         0x80008188
    // 0x8018D524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D524: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D528: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D52C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D530: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D534: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D538: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D53C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D540: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D544: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D548: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D54C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D550: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D554: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D558: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D55C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D560: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D564: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D568: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D56C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D570: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D574: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D578: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D57C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D580: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D584: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D588: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D58C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D590: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D594: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D598: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D59C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5A0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D5A4: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5A8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D5AC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5B0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D5B4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D5B8: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D5BC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5C0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5C4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5C8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5CC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5D0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5D4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5D8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5DC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5E0: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5E4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5E8: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5EC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5F0: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5F4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D5F8: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D600: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D604: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D60C: jr          $ra
    // 0x8018D610: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D610: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftManagerSetPrevStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D75EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D75F0: addiu       $v0, $v0, 0xD80
    ctx->r2 = ADD32(ctx->r2, 0XD80);
    // 0x800D75F4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D75F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D75FC: jr          $ra
    // 0x800D7600: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x800D7600: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void n_alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A380: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8002A384: addiu       $t6, $zero, 0xB8
    ctx->r14 = ADD32(0, 0XB8);
    // 0x8002A388: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002A38C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002A390: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002A394: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002A398: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002A39C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002A3A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002A3A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002A3A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002A3AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002A3B0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8002A3B4: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8002A3B8: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x8002A3BC: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x8002A3C0: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8002A3C4: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x8002A3C8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002A3CC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8002A3D0: beq         $t7, $zero, L_8002A958
    if (ctx->r15 == 0) {
        // 0x8002A3D4: addiu       $s6, $zero, 0x1
        ctx->r22 = ADD32(0, 0X1);
            goto L_8002A958;
    }
    // 0x8002A3D4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8002A3D8: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x8002A3DC: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8002A3E0: addiu       $a3, $a3, -0x2CEC
    ctx->r7 = ADD32(ctx->r7, -0X2CEC);
    // 0x8002A3E4: addiu       $fp, $fp, -0x2CF0
    ctx->r30 = ADD32(ctx->r30, -0X2CF0);
    // 0x8002A3E8: lw          $v1, 0x7C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7C);
L_8002A3EC:
    // 0x8002A3EC: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x8002A3F0: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x8002A3F4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8002A3F8: addiu       $t9, $t8, 0x5C
    ctx->r25 = ADD32(ctx->r24, 0X5C);
    // 0x8002A3FC: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8002A400: mflo        $t6
    ctx->r14 = lo;
    // 0x8002A404: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8002A408: bne         $a1, $zero, L_8002A414
    if (ctx->r5 != 0) {
        // 0x8002A40C: nop
    
            goto L_8002A414;
    }
    // 0x8002A40C: nop

    // 0x8002A410: break       7
    do_break(2147656720);
L_8002A414:
    // 0x8002A414: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002A418: bne         $a1, $at, L_8002A42C
    if (ctx->r5 != ctx->r1) {
        // 0x8002A41C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002A42C;
    }
    // 0x8002A41C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002A420: bne         $t9, $at, L_8002A42C
    if (ctx->r25 != ctx->r1) {
        // 0x8002A424: nop
    
            goto L_8002A42C;
    }
    // 0x8002A424: nop

    // 0x8002A428: break       6
    do_break(2147656744);
L_8002A42C:
    // 0x8002A42C: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A430: mflo        $t7
    ctx->r15 = lo;
    // 0x8002A434: subu        $s7, $t7, $v0
    ctx->r23 = SUB32(ctx->r15, ctx->r2);
    // 0x8002A438: slt         $at, $t8, $s7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8002A43C: bne         $at, $zero, L_8002A958
    if (ctx->r1 != 0) {
        // 0x8002A440: sw          $t7, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r15;
            goto L_8002A958;
    }
    // 0x8002A440: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8002A444: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x8002A448: sltiu       $at, $t9, 0x12
    ctx->r1 = ctx->r25 < 0X12 ? 1 : 0;
    // 0x8002A44C: beq         $at, $zero, L_8002A8C8
    if (ctx->r1 == 0) {
        // 0x8002A450: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8002A8C8;
    }
    // 0x8002A450: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002A454: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002A458: addu        $at, $at, $t9
    gpr jr_addend_8002A460 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002A45C: lw          $t9, -0x1484($at)
    ctx->r25 = ADD32(ctx->r1, -0X1484);
    // 0x8002A460: jr          $t9
    // 0x8002A464: nop

    switch (jr_addend_8002A460 >> 2) {
        case 0: goto L_8002A7F0; break;
        case 1: goto L_8002A8C8; break;
        case 2: goto L_8002A8C8; break;
        case 3: goto L_8002A8C8; break;
        case 4: goto L_8002A8C8; break;
        case 5: goto L_8002A88C; break;
        case 6: goto L_8002A8C8; break;
        case 7: goto L_8002A834; break;
        case 8: goto L_8002A864; break;
        case 9: goto L_8002A8C8; break;
        case 10: goto L_8002A8C8; break;
        case 11: goto L_8002A5B8; break;
        case 12: goto L_8002A5B8; break;
        case 13: goto L_8002A468; break;
        case 14: goto L_8002A790; break;
        case 15: goto L_8002A7B8; break;
        case 16: goto L_8002A5B8; break;
        case 17: goto L_8002A5B8; break;
        default: switch_error(__func__, 0x8002A460, 0x8003EB7C);
    }
    // 0x8002A464: nop

L_8002A468:
    // 0x8002A468: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x8002A46C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8002A470: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002A474: beq         $t6, $zero, L_8002A480
    if (ctx->r14 == 0) {
        // 0x8002A478: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8002A480;
    }
    // 0x8002A478: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002A47C: sw          $s6, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r22;
L_8002A480:
    // 0x8002A480: jal         0x8002A070
    // 0x8002A484: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    n_alLoadParam(rdram, ctx);
        goto after_0;
    // 0x8002A484: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x8002A488: sw          $s6, 0x84($s4)
    MEM_W(0X84, ctx->r20) = ctx->r22;
    // 0x8002A48C: sw          $s6, 0x78($s4)
    MEM_W(0X78, ctx->r20) = ctx->r22;
    // 0x8002A490: sw          $zero, 0x70($s4)
    MEM_W(0X70, ctx->r20) = 0;
    // 0x8002A494: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8002A498: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002A49C: addiu       $t8, $t7, 0x5C
    ctx->r24 = ADD32(ctx->r15, 0X5C);
    // 0x8002A4A0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x8002A4A4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002A4A8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8002A4AC: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8002A4B0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002A4B4: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8002A4B8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002A4BC: sw          $t6, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->r14;
    // 0x8002A4C0: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x8002A4C4: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A4C8: mflo        $a0
    ctx->r4 = lo;
    // 0x8002A4CC: sra         $a0, $a0, 15
    ctx->r4 = S32(SIGNED(ctx->r4) >> 15);
    // 0x8002A4D0: sh          $a0, 0x5A($s4)
    MEM_H(0X5A, ctx->r20) = ctx->r4;
    // 0x8002A4D4: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x8002A4D8: sh          $t7, 0x58($s4)
    MEM_H(0X58, ctx->r20) = ctx->r15;
    // 0x8002A4DC: lbu         $a1, 0x1C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C);
    // 0x8002A4E0: bne         $a1, $zero, L_8002A4F4
    if (ctx->r5 != 0) {
        // 0x8002A4E4: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_8002A4F4;
    }
    // 0x8002A4E4: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8002A4E8: lbu         $t8, 0x1D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1D);
    // 0x8002A4EC: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8002A4F0: beq         $t8, $at, L_8002A520
    if (ctx->r24 == ctx->r1) {
        // 0x8002A4F4: negu        $t6, $t9
        ctx->r14 = SUB32(0, ctx->r25);
            goto L_8002A520;
    }
L_8002A4F4:
    // 0x8002A4F4: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8002A4F8: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8002A4FC: lh          $t8, -0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, -0X2);
    // 0x8002A500: sh          $t8, 0x62($s4)
    MEM_H(0X62, ctx->r20) = ctx->r24;
    // 0x8002A504: lbu         $t9, 0x1D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D);
    // 0x8002A508: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8002A50C: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8002A510: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8002A514: lh          $t9, -0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, -0X2);
    // 0x8002A518: b           L_8002A550
    // 0x8002A51C: sh          $t9, 0x60($s4)
    MEM_H(0X60, ctx->r20) = ctx->r25;
        goto L_8002A550;
    // 0x8002A51C: sh          $t9, 0x60($s4)
    MEM_H(0X60, ctx->r20) = ctx->r25;
L_8002A520:
    // 0x8002A520: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x8002A524: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002A528: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002A52C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002A530: lh          $t8, -0x2DF0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2DF0);
    // 0x8002A534: sh          $t8, 0x60($s4)
    MEM_H(0X60, ctx->r20) = ctx->r24;
    // 0x8002A538: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x8002A53C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8002A540: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8002A544: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8002A548: lh          $t9, -0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, -0X2);
    // 0x8002A54C: sh          $t9, 0x62($s4)
    MEM_H(0X62, ctx->r20) = ctx->r25;
L_8002A550:
    // 0x8002A550: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8002A554: beql        $t6, $zero, L_8002A56C
    if (ctx->r14 == 0) {
        // 0x8002A558: lh          $v0, 0x58($s4)
        ctx->r2 = MEM_H(ctx->r20, 0X58);
            goto L_8002A56C;
    }
    goto skip_0;
    // 0x8002A558: lh          $v0, 0x58($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X58);
    skip_0:
    // 0x8002A55C: sh          $s6, 0x5C($s4)
    MEM_H(0X5C, ctx->r20) = ctx->r22;
    // 0x8002A560: b           L_8002A5AC
    // 0x8002A564: sh          $s6, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r22;
        goto L_8002A5AC;
    // 0x8002A564: sh          $s6, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r22;
    // 0x8002A568: lh          $v0, 0x58($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X58);
L_8002A56C:
    // 0x8002A56C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002A570: lh          $v1, 0x5A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X5A);
    // 0x8002A574: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002A578: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8002A57C: lh          $t7, -0x2DF0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DF0);
    // 0x8002A580: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x8002A584: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A588: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8002A58C: mflo        $t8
    ctx->r24 = lo;
    // 0x8002A590: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x8002A594: sh          $t9, 0x5C($s4)
    MEM_H(0X5C, ctx->r20) = ctx->r25;
    // 0x8002A598: lh          $t8, -0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, -0X2);
    // 0x8002A59C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A5A0: mflo        $t9
    ctx->r25 = lo;
    // 0x8002A5A4: sra         $t6, $t9, 15
    ctx->r14 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8002A5A8: sh          $t6, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r14;
L_8002A5AC:
    // 0x8002A5AC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002A5B0: b           L_8002A8FC
    // 0x8002A5B4: swc1        $f4, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f4.u32l;
        goto L_8002A8FC;
    // 0x8002A5B4: swc1        $f4, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f4.u32l;
L_8002A5B8:
    // 0x8002A5B8: addiu       $t7, $sp, 0x8E
    ctx->r15 = ADD32(ctx->r29, 0X8E);
    // 0x8002A5BC: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8002A5C0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A5C4: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A5C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A5CC: jal         0x80029E5C
    // 0x8002A5D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_1;
    // 0x8002A5D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_1:
    // 0x8002A5D4: lw          $t0, 0x70($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X70);
    // 0x8002A5D8: lw          $a0, 0x74($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X74);
    // 0x8002A5DC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A5E0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A5E4: bnel        $at, $zero, L_8002A64C
    if (ctx->r1 != 0) {
        // 0x8002A5E8: lh          $a1, 0x5C($s4)
        ctx->r5 = MEM_H(ctx->r20, 0X5C);
            goto L_8002A64C;
    }
    goto skip_1;
    // 0x8002A5E8: lh          $a1, 0x5C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X5C);
    skip_1:
    // 0x8002A5EC: lh          $v0, 0x58($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X58);
    // 0x8002A5F0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002A5F4: lh          $v1, 0x5A($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X5A);
    // 0x8002A5F8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002A5FC: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8002A600: lh          $t8, -0x2DF0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2DF0);
    // 0x8002A604: negu        $t7, $v0
    ctx->r15 = SUB32(0, ctx->r2);
    // 0x8002A608: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A60C: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8002A610: mflo        $t9
    ctx->r25 = lo;
    // 0x8002A614: sra         $t6, $t9, 15
    ctx->r14 = S32(SIGNED(ctx->r25) >> 15);
    // 0x8002A618: sh          $t6, 0x68($s4)
    MEM_H(0X68, ctx->r20) = ctx->r14;
    // 0x8002A61C: lh          $t9, -0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, -0X2);
    // 0x8002A620: lh          $t8, 0x68($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X68);
    // 0x8002A624: sw          $a0, 0x70($s4)
    MEM_W(0X70, ctx->r20) = ctx->r4;
    // 0x8002A628: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A62C: sh          $t8, 0x5C($s4)
    MEM_H(0X5C, ctx->r20) = ctx->r24;
    // 0x8002A630: mflo        $t6
    ctx->r14 = lo;
    // 0x8002A634: sra         $t7, $t6, 15
    ctx->r15 = S32(SIGNED(ctx->r14) >> 15);
    // 0x8002A638: sh          $t7, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r15;
    // 0x8002A63C: lh          $t9, 0x6E($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X6E);
    // 0x8002A640: b           L_8002A678
    // 0x8002A644: sh          $t9, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r25;
        goto L_8002A678;
    // 0x8002A644: sh          $t9, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r25;
    // 0x8002A648: lh          $a1, 0x5C($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X5C);
L_8002A64C:
    // 0x8002A64C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8002A650: lh          $a3, 0x66($s4)
    ctx->r7 = MEM_H(ctx->r20, 0X66);
    // 0x8002A654: jal         0x8002A320
    // 0x8002A658: lhu         $a2, 0x64($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X64);
    __n_getVol(rdram, ctx);
        goto after_2;
    // 0x8002A658: lhu         $a2, 0x64($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X64);
    after_2:
    // 0x8002A65C: sh          $v0, 0x5C($s4)
    MEM_H(0X5C, ctx->r20) = ctx->r2;
    // 0x8002A660: lh          $a1, 0x5E($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X5E);
    // 0x8002A664: lw          $a0, 0x70($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X70);
    // 0x8002A668: lh          $a3, 0x6C($s4)
    ctx->r7 = MEM_H(ctx->r20, 0X6C);
    // 0x8002A66C: jal         0x8002A320
    // 0x8002A670: lhu         $a2, 0x6A($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X6A);
    __n_getVol(rdram, ctx);
        goto after_3;
    // 0x8002A670: lhu         $a2, 0x6A($s4)
    ctx->r6 = MEM_HU(ctx->r20, 0X6A);
    after_3:
    // 0x8002A674: sh          $v0, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r2;
L_8002A678:
    // 0x8002A678: lh          $t6, 0x5C($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X5C);
    // 0x8002A67C: bnel        $t6, $zero, L_8002A68C
    if (ctx->r14 != 0) {
        // 0x8002A680: lh          $t7, 0x5E($s4)
        ctx->r15 = MEM_H(ctx->r20, 0X5E);
            goto L_8002A68C;
    }
    goto skip_2;
    // 0x8002A680: lh          $t7, 0x5E($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X5E);
    skip_2:
    // 0x8002A684: sh          $s6, 0x5C($s4)
    MEM_H(0X5C, ctx->r20) = ctx->r22;
    // 0x8002A688: lh          $t7, 0x5E($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X5E);
L_8002A68C:
    // 0x8002A68C: bnel        $t7, $zero, L_8002A69C
    if (ctx->r15 != 0) {
        // 0x8002A690: lw          $v1, 0x7C($s4)
        ctx->r3 = MEM_W(ctx->r20, 0X7C);
            goto L_8002A69C;
    }
    goto skip_3;
    // 0x8002A690: lw          $v1, 0x7C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7C);
    skip_3:
    // 0x8002A694: sh          $s6, 0x5E($s4)
    MEM_H(0X5E, ctx->r20) = ctx->r22;
    // 0x8002A698: lw          $v1, 0x7C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7C);
L_8002A69C:
    // 0x8002A69C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8002A6A0: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002A6A4: bnel        $a0, $at, L_8002A6BC
    if (ctx->r4 != ctx->r1) {
        // 0x8002A6A8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8002A6BC;
    }
    goto skip_4;
    // 0x8002A6A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_4:
    // 0x8002A6AC: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8002A6B0: sh          $t8, 0x58($s4)
    MEM_H(0X58, ctx->r20) = ctx->r24;
    // 0x8002A6B4: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002A6B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8002A6BC:
    // 0x8002A6BC: bnel        $a0, $at, L_8002A710
    if (ctx->r4 != ctx->r1) {
        // 0x8002A6C0: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8002A710;
    }
    goto skip_5;
    // 0x8002A6C0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_5:
    // 0x8002A6C4: sw          $zero, 0x70($s4)
    MEM_W(0X70, ctx->r20) = 0;
    // 0x8002A6C8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8002A6CC: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002A6D0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A6D4: mflo        $v0
    ctx->r2 = lo;
    // 0x8002A6D8: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8002A6DC: sh          $v0, 0x5A($s4)
    MEM_H(0X5A, ctx->r20) = ctx->r2;
    // 0x8002A6E0: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x8002A6E4: addiu       $t6, $t9, 0x5C
    ctx->r14 = ADD32(ctx->r25, 0X5C);
    // 0x8002A6E8: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x8002A6EC: mflo        $t7
    ctx->r15 = lo;
    // 0x8002A6F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002A6F4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002A6F8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A6FC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002A700: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A704: sw          $t8, 0x74($s4)
    MEM_W(0X74, ctx->r20) = ctx->r24;
    // 0x8002A708: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002A70C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8002A710:
    // 0x8002A710: bnel        $a0, $at, L_8002A750
    if (ctx->r4 != ctx->r1) {
        // 0x8002A714: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8002A750;
    }
    goto skip_6;
    // 0x8002A714: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_6:
    // 0x8002A718: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8002A71C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002A720: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8002A724: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002A728: lh          $t7, -0x2DF0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DF0);
    // 0x8002A72C: sh          $t7, 0x60($s4)
    MEM_H(0X60, ctx->r20) = ctx->r15;
    // 0x8002A730: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8002A734: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002A738: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8002A73C: addu        $t7, $fp, $t6
    ctx->r15 = ADD32(ctx->r30, ctx->r14);
    // 0x8002A740: lh          $t8, -0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, -0X2);
    // 0x8002A744: sh          $t8, 0x62($s4)
    MEM_H(0X62, ctx->r20) = ctx->r24;
    // 0x8002A748: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8002A74C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_8002A750:
    // 0x8002A750: bne         $a0, $at, L_8002A788
    if (ctx->r4 != ctx->r1) {
        // 0x8002A754: nop
    
            goto L_8002A788;
    }
    // 0x8002A754: nop

    // 0x8002A758: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x8002A75C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8002A760: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8002A764: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x8002A768: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002A76C: sh          $t9, 0x60($s4)
    MEM_H(0X60, ctx->r20) = ctx->r25;
    // 0x8002A770: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8002A774: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002A778: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8002A77C: addu        $t9, $fp, $t8
    ctx->r25 = ADD32(ctx->r30, ctx->r24);
    // 0x8002A780: lh          $t6, -0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, -0X2);
    // 0x8002A784: sh          $t6, 0x62($s4)
    MEM_H(0X62, ctx->r20) = ctx->r14;
L_8002A788:
    // 0x8002A788: b           L_8002A8FC
    // 0x8002A78C: sw          $s6, 0x78($s4)
    MEM_W(0X78, ctx->r20) = ctx->r22;
        goto L_8002A8FC;
    // 0x8002A78C: sw          $s6, 0x78($s4)
    MEM_W(0X78, ctx->r20) = ctx->r22;
L_8002A790:
    // 0x8002A790: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x8002A794: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002A798: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002A79C: beq         $t7, $zero, L_8002A7A8
    if (ctx->r15 == 0) {
        // 0x8002A7A0: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8002A7A8;
    }
    // 0x8002A7A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002A7A4: sw          $s6, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r22;
L_8002A7A8:
    // 0x8002A7A8: jal         0x8002A070
    // 0x8002A7AC: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    n_alLoadParam(rdram, ctx);
        goto after_4;
    // 0x8002A7AC: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_4:
    // 0x8002A7B0: b           L_8002A8FC
    // 0x8002A7B4: sw          $s6, 0x84($s4)
    MEM_W(0X84, ctx->r20) = ctx->r22;
        goto L_8002A8FC;
    // 0x8002A7B4: sw          $s6, 0x84($s4)
    MEM_W(0X84, ctx->r20) = ctx->r22;
L_8002A7B8:
    // 0x8002A7B8: addiu       $t8, $sp, 0x8E
    ctx->r24 = ADD32(ctx->r29, 0X8E);
    // 0x8002A7BC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8002A7C0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A7C4: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A7C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A7CC: jal         0x80029E5C
    // 0x8002A7D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_5;
    // 0x8002A7D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x8002A7D4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A7D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002A7DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002A7E0: jal         0x8002A230
    // 0x8002A7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    n_alEnvmixerParam(rdram, ctx);
        goto after_6;
    // 0x8002A7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8002A7E8: b           L_8002A900
    // 0x8002A7EC: lh          $t9, 0x8E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8E);
        goto L_8002A900;
    // 0x8002A7EC: lh          $t9, 0x8E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8E);
L_8002A7F0:
    // 0x8002A7F0: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8002A7F4: sw          $zero, 0x88($t9)
    MEM_W(0X88, ctx->r25) = 0;
    // 0x8002A7F8: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x8002A7FC: jal         0x80028C84
    // 0x8002A800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_7;
    // 0x8002A800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8002A804: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002A808: lw          $v0, -0x2CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2CEC);
    // 0x8002A80C: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x8002A810: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8002A814: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8002A818: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002A81C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002A820: beq         $v1, $zero, L_8002A82C
    if (ctx->r3 == 0) {
        // 0x8002A824: nop
    
            goto L_8002A82C;
    }
    // 0x8002A824: nop

    // 0x8002A828: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
L_8002A82C:
    // 0x8002A82C: b           L_8002A8FC
    // 0x8002A830: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
        goto L_8002A8FC;
    // 0x8002A830: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8002A834:
    // 0x8002A834: addiu       $t7, $sp, 0x8E
    ctx->r15 = ADD32(ctx->r29, 0X8E);
    // 0x8002A838: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8002A83C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A840: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A844: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A848: jal         0x80029E5C
    // 0x8002A84C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_8;
    // 0x8002A84C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_8:
    // 0x8002A850: lw          $t8, 0x7C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X7C);
    // 0x8002A854: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A858: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002A85C: b           L_8002A8FC
    // 0x8002A860: swc1        $f6, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f6.u32l;
        goto L_8002A8FC;
    // 0x8002A860: swc1        $f6, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f6.u32l;
L_8002A864:
    // 0x8002A864: addiu       $t9, $sp, 0x8E
    ctx->r25 = ADD32(ctx->r29, 0X8E);
    // 0x8002A868: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8002A86C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A870: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A874: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A878: jal         0x80029E5C
    // 0x8002A87C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_9;
    // 0x8002A87C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_9:
    // 0x8002A880: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A884: b           L_8002A8FC
    // 0x8002A888: sw          $s6, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r22;
        goto L_8002A8FC;
    // 0x8002A888: sw          $s6, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r22;
L_8002A88C:
    // 0x8002A88C: addiu       $t6, $sp, 0x8E
    ctx->r14 = ADD32(ctx->r29, 0X8E);
    // 0x8002A890: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8002A894: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A898: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A89C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A8A0: jal         0x80029E5C
    // 0x8002A8A4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_10;
    // 0x8002A8A4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_10:
    // 0x8002A8A8: lw          $t7, 0x7C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X7C);
    // 0x8002A8AC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A8B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002A8B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002A8B8: jal         0x8002A070
    // 0x8002A8BC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    n_alLoadParam(rdram, ctx);
        goto after_11;
    // 0x8002A8BC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    after_11:
    // 0x8002A8C0: b           L_8002A900
    // 0x8002A8C4: lh          $t9, 0x8E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8E);
        goto L_8002A900;
    // 0x8002A8C4: lh          $t9, 0x8E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8E);
L_8002A8C8:
    // 0x8002A8C8: addiu       $t8, $sp, 0x8E
    ctx->r24 = ADD32(ctx->r29, 0X8E);
    // 0x8002A8CC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8002A8D0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A8D4: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A8D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8002A8DC: jal         0x80029E5C
    // 0x8002A8E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_12;
    // 0x8002A8E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_12:
    // 0x8002A8E4: lw          $v1, 0x7C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7C);
    // 0x8002A8E8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A8EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8002A8F0: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x8002A8F4: jal         0x8002A230
    // 0x8002A8F8: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    n_alEnvmixerParam(rdram, ctx);
        goto after_13;
    // 0x8002A8F8: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_13:
L_8002A8FC:
    // 0x8002A8FC: lh          $t9, 0x8E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8E);
L_8002A900:
    // 0x8002A900: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8002A904: sll         $t6, $s7, 1
    ctx->r14 = S32(ctx->r23 << 1);
    // 0x8002A908: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002A90C: subu        $t9, $t8, $s7
    ctx->r25 = SUB32(ctx->r24, ctx->r23);
    // 0x8002A910: sh          $t7, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r15;
    // 0x8002A914: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x8002A918: lw          $v0, 0x7C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X7C);
    // 0x8002A91C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8002A920: addiu       $a3, $a3, -0x2CEC
    ctx->r7 = ADD32(ctx->r7, -0X2CEC);
    // 0x8002A924: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002A928: bne         $t6, $zero, L_8002A934
    if (ctx->r14 != 0) {
        // 0x8002A92C: sw          $t6, 0x7C($s4)
        MEM_W(0X7C, ctx->r20) = ctx->r14;
            goto L_8002A934;
    }
    // 0x8002A92C: sw          $t6, 0x7C($s4)
    MEM_W(0X7C, ctx->r20) = ctx->r14;
    // 0x8002A930: sw          $zero, 0x80($s4)
    MEM_W(0X80, ctx->r20) = 0;
L_8002A934:
    // 0x8002A934: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8002A938: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x8002A93C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A940: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8002A944: sw          $v0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r2;
    // 0x8002A948: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x8002A94C: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x8002A950: bnel        $t8, $zero, L_8002A3EC
    if (ctx->r24 != 0) {
        // 0x8002A954: lw          $v1, 0x7C($s4)
        ctx->r3 = MEM_W(ctx->r20, 0X7C);
            goto L_8002A3EC;
    }
    goto skip_7;
    // 0x8002A954: lw          $v1, 0x7C($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X7C);
    skip_7:
L_8002A958:
    // 0x8002A958: addiu       $t9, $sp, 0x8E
    ctx->r25 = ADD32(ctx->r29, 0X8E);
    // 0x8002A95C: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8002A960: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8002A964: addiu       $s3, $sp, 0x9E
    ctx->r19 = ADD32(ctx->r29, 0X9E);
    // 0x8002A968: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8002A96C: jal         0x80029E5C
    // 0x8002A970: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _pullSubFrame(rdram, ctx);
        goto after_14;
    // 0x8002A970: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x8002A974: lw          $a0, 0x74($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X74);
    // 0x8002A978: lw          $t6, 0x70($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X70);
    // 0x8002A97C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8002A980: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x8002A984: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002A988: beql        $at, $zero, L_8002A998
    if (ctx->r1 == 0) {
        // 0x8002A98C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8002A998;
    }
    goto skip_8;
    // 0x8002A98C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x8002A990: sw          $a0, 0x70($s4)
    MEM_W(0X70, ctx->r20) = ctx->r4;
    // 0x8002A994: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8002A998:
    // 0x8002A998: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002A99C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002A9A0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002A9A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A9A8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002A9AC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002A9B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002A9B4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A9B8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002A9BC: jr          $ra
    // 0x8002A9C0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8002A9C0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itTaruWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179C00: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80179C04: jal         0x801735A0
    // 0x80179C08: addiu       $a1, $a1, -0x62E4
    ctx->r5 = ADD32(ctx->r5, -0X62E4);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80179C08: addiu       $a1, $a1, -0x62E4
    ctx->r5 = ADD32(ctx->r5, -0X62E4);
    after_0:
    // 0x80179C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179C18: jr          $ra
    // 0x80179C1C: nop

    return;
    // 0x80179C1C: nop

;}
RECOMP_FUNC void mnOptionMakeSoundUnderlineCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132A44: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132A48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132A4C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132A50: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80132A54: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132A58: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80132A5C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132A60: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132A64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132A68: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132A6C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132A70: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132A74: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132A78: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132A7C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132A80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132A88: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132A8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132A90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132A9C: jal         0x8000B93C
    // 0x80132AA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132AA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132AA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132AA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132AAC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132AB0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132AB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132AB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132ABC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132AC0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132AC4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132AC8: jal         0x80007080
    // 0x80132ACC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132ACC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132AD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132AD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132AD8: jr          $ra
    // 0x80132ADC: nop

    return;
    // 0x80132ADC: nop

;}
RECOMP_FUNC void mvOpeningClashMakeVoidCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132314: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80132318: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013231C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132320: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132324: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132328: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013232C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132330: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132334: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132338: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013233C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132340: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132344: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132348: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013234C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132350: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132354: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132358: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013235C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132360: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132364: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013236C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132370: jal         0x8000B93C
    // 0x80132374: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132374: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132378: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013237C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132380: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132384: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132388: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013238C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132390: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132394: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132398: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013239C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x801323A0: jal         0x80007080
    // 0x801323A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801323A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801323A8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x801323AC: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x801323B0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801323B4: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x801323B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801323BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801323C0: jr          $ra
    // 0x801323C4: nop

    return;
    // 0x801323C4: nop

;}
RECOMP_FUNC void mnVSRecordMakeDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F34: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80131F38: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80131F3C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80131F40: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131F44: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x80131F48: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80131F4C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80131F50: addiu       $t6, $t6, 0x66D0
    ctx->r14 = ADD32(ctx->r14, 0X66D0);
    // 0x80131F54: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80131F58: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80131F5C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131F60: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80131F64: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131F68: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80131F6C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80131F70: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80131F74: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80131F78: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131F7C: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80131F80: or          $t9, $s6, $zero
    ctx->r25 = ctx->r22 | 0;
L_80131F84:
    // 0x80131F84: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F88: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131F8C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131F90: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131F94: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131F98: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131F9C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131FA0: bne         $t6, $t0, L_80131F84
    if (ctx->r14 != ctx->r8) {
        // 0x80131FA4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131F84;
    }
    // 0x80131FA4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131FA8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131FAC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80131FB0: bgez        $s3, L_80131FBC
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80131FB4: sw          $t8, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r24;
            goto L_80131FBC;
    }
    // 0x80131FB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131FB8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131FBC:
    // 0x80131FBC: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80131FC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80131FC4: beq         $v0, $zero, L_80132010
    if (ctx->r2 == 0) {
        // 0x80131FC8: nop
    
            goto L_80132010;
    }
    // 0x80131FC8: nop

    // 0x80131FCC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80131FD0: bne         $s3, $at, L_80132010
    if (ctx->r19 != ctx->r1) {
        // 0x80131FD4: addiu       $s4, $zero, 0xA
        ctx->r20 = ADD32(0, 0XA);
            goto L_80132010;
    }
    // 0x80131FD4: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80131FD8: div         $zero, $s3, $s4
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r20)));
    // 0x80131FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131FE0: bne         $s4, $zero, L_80131FEC
    if (ctx->r20 != 0) {
        // 0x80131FE4: nop
    
            goto L_80131FEC;
    }
    // 0x80131FE4: nop

    // 0x80131FE8: break       7
    do_break(2148737000);
L_80131FEC:
    // 0x80131FEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131FF0: bne         $s4, $at, L_80132004
    if (ctx->r20 != ctx->r1) {
        // 0x80131FF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80132004;
    }
    // 0x80131FF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131FF8: bne         $s3, $at, L_80132004
    if (ctx->r19 != ctx->r1) {
        // 0x80131FFC: nop
    
            goto L_80132004;
    }
    // 0x80131FFC: nop

    // 0x80132000: break       6
    do_break(2148737024);
L_80132004:
    // 0x80132004: mflo        $s3
    ctx->r19 = lo;
    // 0x80132008: nop

    // 0x8013200C: nop

L_80132010:
    // 0x80132010: beq         $v0, $zero, L_80132118
    if (ctx->r2 == 0) {
        // 0x80132014: addiu       $s4, $zero, 0xA
        ctx->r20 = ADD32(0, 0XA);
            goto L_80132118;
    }
    // 0x80132014: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80132018: div         $zero, $s3, $s4
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r20)));
    // 0x8013201C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80132020: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80132024: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x80132028: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8013202C: lw          $t4, 0x6D88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D88);
    // 0x80132030: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80132034: bne         $s4, $zero, L_80132040
    if (ctx->r20 != 0) {
        // 0x80132038: nop
    
            goto L_80132040;
    }
    // 0x80132038: nop

    // 0x8013203C: break       7
    do_break(2148737084);
L_80132040:
    // 0x80132040: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80132044: bne         $s4, $at, L_80132058
    if (ctx->r20 != ctx->r1) {
        // 0x80132048: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80132058;
    }
    // 0x80132048: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013204C: bne         $s3, $at, L_80132058
    if (ctx->r19 != ctx->r1) {
        // 0x80132050: nop
    
            goto L_80132058;
    }
    // 0x80132050: nop

    // 0x80132054: break       6
    do_break(2148737108);
L_80132058:
    // 0x80132058: mflo        $s3
    ctx->r19 = lo;
    // 0x8013205C: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x80132060: jal         0x800CCFDC
    // 0x80132064: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132064: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x80132068: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013206C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132070: jal         0x80131E40
    // 0x80132074: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    mnVSRecordSetSpriteColors(rdram, ctx);
        goto after_1;
    // 0x80132074: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_1:
    // 0x80132078: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x8013207C: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80132080: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132084: beq         $t5, $zero, L_8013209C
    if (ctx->r13 == 0) {
        // 0x80132088: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_8013209C;
    }
    // 0x80132088: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013208C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80132090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132094: b           L_801320AC
    // 0x80132098: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
        goto L_801320AC;
    // 0x80132098: sub.s       $f20, $f12, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f4.fl;
L_8013209C:
    // 0x8013209C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801320A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801320A4: nop

    // 0x801320A8: sub.s       $f20, $f12, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f6.fl;
L_801320AC:
    // 0x801320AC: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x801320B0: swc1        $f22, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f22.u32l;
    // 0x801320B4: lw          $t0, 0x6D88($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6D88);
    // 0x801320B8: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801320BC: addiu       $t6, $t6, 0x910
    ctx->r14 = ADD32(ctx->r14, 0X910);
    // 0x801320C0: jal         0x800CCFDC
    // 0x801320C4: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801320C4: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    after_2:
    // 0x801320C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801320CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801320D0: jal         0x80131E40
    // 0x801320D4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    mnVSRecordSetSpriteColors(rdram, ctx);
        goto after_3;
    // 0x801320D4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_3:
    // 0x801320D8: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x801320DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801320E0: beql        $t9, $zero, L_801320FC
    if (ctx->r25 == 0) {
        // 0x801320E4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_801320FC;
    }
    goto skip_0;
    // 0x801320E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x801320E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801320EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801320F0: b           L_80132104
    // 0x801320F4: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
        goto L_80132104;
    // 0x801320F4: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x801320F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_801320FC:
    // 0x801320FC: nop

    // 0x80132100: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_80132104:
    // 0x80132104: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132108: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013210C: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x80132110: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x80132114: swc1        $f18, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f18.u32l;
L_80132118:
    // 0x80132118: div         $zero, $s3, $s4
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r20)));
    // 0x8013211C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80132120: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80132124: addu        $t1, $s6, $t8
    ctx->r9 = ADD32(ctx->r22, ctx->r24);
    // 0x80132128: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013212C: lw          $t3, 0x6D88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6D88);
    // 0x80132130: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80132134: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132138: bne         $s4, $zero, L_80132144
    if (ctx->r20 != 0) {
        // 0x8013213C: nop
    
            goto L_80132144;
    }
    // 0x8013213C: nop

    // 0x80132140: break       7
    do_break(2148737344);
L_80132144:
    // 0x80132144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80132148: bne         $s4, $at, L_8013215C
    if (ctx->r20 != ctx->r1) {
        // 0x8013214C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8013215C;
    }
    // 0x8013214C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132150: bne         $s3, $at, L_8013215C
    if (ctx->r19 != ctx->r1) {
        // 0x80132154: nop
    
            goto L_8013215C;
    }
    // 0x80132154: nop

    // 0x80132158: break       6
    do_break(2148737368);
L_8013215C:
    // 0x8013215C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x80132160: jal         0x800CCFDC
    // 0x80132164: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132164: nop

    after_4:
    // 0x80132168: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8013216C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132170: jal         0x80131E40
    // 0x80132174: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    mnVSRecordSetSpriteColors(rdram, ctx);
        goto after_5;
    // 0x80132174: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_5:
    // 0x80132178: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8013217C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80132180: beql        $t4, $zero, L_8013219C
    if (ctx->r12 == 0) {
        // 0x80132184: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8013219C;
    }
    goto skip_1;
    // 0x80132184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80132188: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8013218C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132190: b           L_801321A4
    // 0x80132194: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
        goto L_801321A4;
    // 0x80132194: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x80132198: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8013219C:
    // 0x8013219C: nop

    // 0x801321A0: sub.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f6.fl;
L_801321A4:
    // 0x801321A4: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x801321A8: swc1        $f22, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f22.u32l;
    // 0x801321AC: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x801321B0: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x801321B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801321B8: beq         $t5, $zero, L_801321CC
    if (ctx->r13 == 0) {
        // 0x801321BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801321CC;
    }
    // 0x801321BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801321C0: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x801321C4: b           L_801321D8
    // 0x801321C8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_801321D8;
    // 0x801321C8: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_801321CC:
    // 0x801321CC: jal         0x80131E88
    // 0x801321D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSRecordGetDigitCount(rdram, ctx);
        goto after_6;
    // 0x801321D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x801321D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801321D8:
    // 0x801321D8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x801321DC: bne         $at, $zero, L_801322FC
    if (ctx->r1 != 0) {
        // 0x801321E0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801322FC;
    }
    // 0x801321E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_801321E4:
    // 0x801321E4: jal         0x80131DA0
    // 0x801321E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSRecordGetPowerOf(rdram, ctx);
        goto after_7;
    // 0x801321E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x801321EC: beq         $v0, $zero, L_80132234
    if (ctx->r2 == 0) {
        // 0x801321F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80132234;
    }
    // 0x801321F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801321F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801321F8: jal         0x80131DA0
    // 0x801321FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSRecordGetPowerOf(rdram, ctx);
        goto after_8;
    // 0x801321FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80132200: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80132204: mflo        $v1
    ctx->r3 = lo;
    // 0x80132208: bne         $v0, $zero, L_80132214
    if (ctx->r2 != 0) {
        // 0x8013220C: nop
    
            goto L_80132214;
    }
    // 0x8013220C: nop

    // 0x80132210: break       7
    do_break(2148737552);
L_80132214:
    // 0x80132214: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80132218: bne         $v0, $at, L_8013222C
    if (ctx->r2 != ctx->r1) {
        // 0x8013221C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8013222C;
    }
    // 0x8013221C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132220: bne         $s3, $at, L_8013222C
    if (ctx->r19 != ctx->r1) {
        // 0x80132224: nop
    
            goto L_8013222C;
    }
    // 0x80132224: nop

    // 0x80132228: break       6
    do_break(2148737576);
L_8013222C:
    // 0x8013222C: b           L_80132234
    // 0x80132230: nop

        goto L_80132234;
    // 0x80132230: nop

L_80132234:
    // 0x80132234: div         $zero, $v1, $s4
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r20)));
    // 0x80132238: mfhi        $t0
    ctx->r8 = hi;
    // 0x8013223C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80132240: addu        $t9, $s6, $t6
    ctx->r25 = ADD32(ctx->r22, ctx->r14);
    // 0x80132244: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132248: lw          $t8, 0x6D88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D88);
    // 0x8013224C: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80132250: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132254: bne         $s4, $zero, L_80132260
    if (ctx->r20 != 0) {
        // 0x80132258: nop
    
            goto L_80132260;
    }
    // 0x80132258: nop

    // 0x8013225C: break       7
    do_break(2148737628);
L_80132260:
    // 0x80132260: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80132264: bne         $s4, $at, L_80132278
    if (ctx->r20 != ctx->r1) {
        // 0x80132268: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80132278;
    }
    // 0x80132268: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013226C: bne         $v1, $at, L_80132278
    if (ctx->r3 != ctx->r1) {
        // 0x80132270: nop
    
            goto L_80132278;
    }
    // 0x80132270: nop

    // 0x80132274: break       6
    do_break(2148737652);
L_80132278:
    // 0x80132278: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8013227C: jal         0x800CCFDC
    // 0x80132280: nop

    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x80132280: nop

    after_9:
    // 0x80132284: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80132288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013228C: jal         0x80131E40
    // 0x80132290: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    mnVSRecordSetSpriteColors(rdram, ctx);
        goto after_10;
    // 0x80132290: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_10:
    // 0x80132294: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80132298: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8013229C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801322A0: beql        $t1, $zero, L_801322BC
    if (ctx->r9 == 0) {
        // 0x801322A4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_801322BC;
    }
    goto skip_2;
    // 0x801322A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x801322A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801322AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322B0: b           L_801322C4
    // 0x801322B4: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
        goto L_801322C4;
    // 0x801322B4: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x801322B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_801322BC:
    // 0x801322BC: nop

    // 0x801322C0: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_801322C4:
    // 0x801322C4: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x801322C8: swc1        $f22, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f22.u32l;
    // 0x801322CC: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x801322D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801322D4: beq         $t2, $zero, L_801322E4
    if (ctx->r10 == 0) {
        // 0x801322D8: nop
    
            goto L_801322E4;
    }
    // 0x801322D8: nop

    // 0x801322DC: b           L_801322F0
    // 0x801322E0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_801322F0;
    // 0x801322E0: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_801322E4:
    // 0x801322E4: jal         0x80131E88
    // 0x801322E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSRecordGetDigitCount(rdram, ctx);
        goto after_11;
    // 0x801322E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x801322EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801322F0:
    // 0x801322F0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801322F4: bnel        $at, $zero, L_801321E4
    if (ctx->r1 != 0) {
        // 0x801322F8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801321E4;
    }
    goto skip_3;
    // 0x801322F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_3:
L_801322FC:
    // 0x801322FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132300: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132304: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80132308: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8013230C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80132310: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80132314: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80132318: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8013231C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80132320: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80132324: jr          $ra
    // 0x80132328: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80132328: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void mnTitleShowGObjLinkID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801323B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x801323B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x801323B8: lw          $v0, 0x66F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66F0);
    // 0x801323BC: beq         $v0, $zero, L_801323D4
    if (ctx->r2 == 0) {
        // 0x801323C0: nop
    
            goto L_801323D4;
    }
    // 0x801323C0: nop

    // 0x801323C4: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
L_801323C8:
    // 0x801323C8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x801323CC: bnel        $v0, $zero, L_801323C8
    if (ctx->r2 != 0) {
        // 0x801323D0: sw          $zero, 0x7C($v0)
        MEM_W(0X7C, ctx->r2) = 0;
            goto L_801323C8;
    }
    goto skip_0;
    // 0x801323D0: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    skip_0:
L_801323D4:
    // 0x801323D4: jr          $ra
    // 0x801323D8: nop

    return;
    // 0x801323D8: nop

;}
RECOMP_FUNC void lbBackupCorrectErrors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D473C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D4740: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x800D4744: lhu         $v0, 0x458($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X458);
    // 0x800D4748: lbu         $t6, 0x456($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X456);
    // 0x800D474C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D4750: ori         $v0, $v0, 0x36F
    ctx->r2 = ctx->r2 | 0X36F;
    // 0x800D4754: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800D4758: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x800D475C: bne         $t9, $zero, L_800D4770
    if (ctx->r25 != 0) {
        // 0x800D4760: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800D4770;
    }
    // 0x800D4760: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D4764: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800D4768: lbu         $t0, 0x3DEA($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3DEA);
    // 0x800D476C: sb          $t0, 0x456($v1)
    MEM_B(0X456, ctx->r3) = ctx->r8;
L_800D4770:
    // 0x800D4770: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x800D4774: lbu         $t1, 0x14($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X14);
    // 0x800D4778: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D477C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x800D4780: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x800D4784: and         $t4, $v0, $t3
    ctx->r12 = ctx->r2 & ctx->r11;
    // 0x800D4788: bne         $t4, $zero, L_800D4794
    if (ctx->r12 != 0) {
        // 0x800D478C: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_800D4794;
    }
    // 0x800D478C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800D4790: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
L_800D4794:
    // 0x800D4794: lbu         $t5, 0x3B($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X3B);
    // 0x800D4798: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D479C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x800D47A0: sllv        $t6, $t7, $t5
    ctx->r14 = S32(ctx->r15 << (ctx->r13 & 31));
    // 0x800D47A4: and         $t8, $v0, $t6
    ctx->r24 = ctx->r2 & ctx->r14;
    // 0x800D47A8: bne         $t8, $zero, L_800D47B4
    if (ctx->r24 != 0) {
        // 0x800D47AC: addiu       $t6, $zero, 0x1C
        ctx->r14 = ADD32(0, 0X1C);
            goto L_800D47B4;
    }
    // 0x800D47AC: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x800D47B0: sb          $a1, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r5;
L_800D47B4:
    // 0x800D47B4: lbu         $t9, 0x3D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3D);
    // 0x800D47B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D47BC: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800D47C0: sllv        $t2, $t0, $t9
    ctx->r10 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x800D47C4: and         $t1, $v0, $t2
    ctx->r9 = ctx->r2 & ctx->r10;
    // 0x800D47C8: bne         $t1, $zero, L_800D47D4
    if (ctx->r9 != 0) {
        // 0x800D47CC: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_800D47D4;
    }
    // 0x800D47CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D47D0: sb          $a1, 0x3D($a0)
    MEM_B(0X3D, ctx->r4) = ctx->r5;
L_800D47D4:
    // 0x800D47D4: lbu         $t3, 0x4D2B($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4D2B);
    // 0x800D47D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D47DC: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x800D47E0: sllv        $t7, $t4, $t3
    ctx->r15 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x800D47E4: and         $t5, $t7, $v0
    ctx->r13 = ctx->r15 & ctx->r2;
    // 0x800D47E8: bne         $t5, $zero, L_800D47FC
    if (ctx->r13 != 0) {
        // 0x800D47EC: lui         $t4, 0x800A
        ctx->r12 = S32(0X800A << 16);
            goto L_800D47FC;
    }
    // 0x800D47EC: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800D47F0: sb          $t6, 0x4D2B($at)
    MEM_B(0X4D2B, ctx->r1) = ctx->r14;
    // 0x800D47F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D47F8: sb          $zero, 0x4D2A($at)
    MEM_B(0X4D2A, ctx->r1) = 0;
L_800D47FC:
    // 0x800D47FC: lbu         $t8, 0x4D9F($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4D9F);
    // 0x800D4800: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D4804: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4808: sllv        $t9, $t0, $t8
    ctx->r25 = S32(ctx->r8 << (ctx->r24 & 31));
    // 0x800D480C: and         $t2, $t9, $v0
    ctx->r10 = ctx->r25 & ctx->r2;
    // 0x800D4810: bne         $t2, $zero, L_800D4824
    if (ctx->r10 != 0) {
        // 0x800D4814: lui         $t0, 0x800A
        ctx->r8 = S32(0X800A << 16);
            goto L_800D4824;
    }
    // 0x800D4814: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800D4818: sb          $t1, 0x4D9F($at)
    MEM_B(0X4D9F, ctx->r1) = ctx->r9;
    // 0x800D481C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4820: sb          $zero, 0x4D9E($at)
    MEM_B(0X4D9E, ctx->r1) = 0;
L_800D4824:
    // 0x800D4824: lbu         $t4, 0x4E13($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4E13);
    // 0x800D4828: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D482C: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x800D4830: sllv        $t7, $t3, $t4
    ctx->r15 = S32(ctx->r11 << (ctx->r12 & 31));
    // 0x800D4834: and         $t5, $t7, $v0
    ctx->r13 = ctx->r15 & ctx->r2;
    // 0x800D4838: bne         $t5, $zero, L_800D484C
    if (ctx->r13 != 0) {
        // 0x800D483C: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_800D484C;
    }
    // 0x800D483C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4840: sb          $t6, 0x4E13($at)
    MEM_B(0X4E13, ctx->r1) = ctx->r14;
    // 0x800D4844: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4848: sb          $zero, 0x4E12($at)
    MEM_B(0X4E12, ctx->r1) = 0;
L_800D484C:
    // 0x800D484C: lbu         $t0, 0x4E87($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4E87);
    // 0x800D4850: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D4854: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x800D4858: sllv        $t9, $t8, $t0
    ctx->r25 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x800D485C: and         $t2, $t9, $v0
    ctx->r10 = ctx->r25 & ctx->r2;
    // 0x800D4860: bne         $t2, $zero, L_800D4874
    if (ctx->r10 != 0) {
        // 0x800D4864: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_800D4874;
    }
    // 0x800D4864: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4868: sb          $t1, 0x4E87($at)
    MEM_B(0X4E87, ctx->r1) = ctx->r9;
    // 0x800D486C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800D4870: sb          $zero, 0x4E86($at)
    MEM_B(0X4E86, ctx->r1) = 0;
L_800D4874:
    // 0x800D4874: lbu         $v0, 0x457($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X457);
    // 0x800D4878: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x800D487C: bne         $t3, $zero, L_800D48B4
    if (ctx->r11 != 0) {
        // 0x800D4880: andi        $t8, $v0, 0x40
        ctx->r24 = ctx->r2 & 0X40;
            goto L_800D48B4;
    }
    // 0x800D4880: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x800D4884: lbu         $t4, 0x41($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X41);
    // 0x800D4888: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800D488C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800D4890: bne         $v1, $t4, L_800D48A0
    if (ctx->r3 != ctx->r12) {
        // 0x800D4894: lui         $t6, 0x800A
        ctx->r14 = S32(0X800A << 16);
            goto L_800D48A0;
    }
    // 0x800D4894: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D4898: lbu         $t7, 0x3FC1($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3FC1);
    // 0x800D489C: sb          $t7, 0x41($a0)
    MEM_B(0X41, ctx->r4) = ctx->r15;
L_800D48A0:
    // 0x800D48A0: lbu         $t5, 0x42($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X42);
    // 0x800D48A4: bne         $v1, $t5, L_800D48B4
    if (ctx->r3 != ctx->r13) {
        // 0x800D48A8: nop
    
            goto L_800D48B4;
    }
    // 0x800D48A8: nop

    // 0x800D48AC: lbu         $t6, 0x3FC2($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3FC2);
    // 0x800D48B0: sb          $t6, 0x42($a0)
    MEM_B(0X42, ctx->r4) = ctx->r14;
L_800D48B4:
    // 0x800D48B4: bne         $t8, $zero, L_800D48D8
    if (ctx->r24 != 0) {
        // 0x800D48B8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800D48D8;
    }
    // 0x800D48B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D48BC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D48C0: addiu       $v1, $v1, 0x3FC8
    ctx->r3 = ADD32(ctx->r3, 0X3FC8);
    // 0x800D48C4: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x800D48C8: lbu         $t9, 0x1C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1C);
    // 0x800D48CC: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x800D48D0: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x800D48D4: sb          $t9, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r25;
L_800D48D8:
    // 0x800D48D8: jr          $ra
    // 0x800D48DC: nop

    return;
    // 0x800D48DC: nop

;}
RECOMP_FUNC void func_ovl8_80373158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373158: jr          $ra
    // 0x8037315C: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    return;
    // 0x8037315C: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mvOpeningPortraitsBlockRow0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E00: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80131E04: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80131E08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131E0C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80131E10: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131E14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131E18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131E1C: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80131E20: ori         $t7, $t7, 0x8104
    ctx->r15 = ctx->r15 | 0X8104;
    // 0x80131E24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E28: jr          $ra
    // 0x80131E2C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131E2C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void grPupupuMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801066D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801066D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801066DC: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x801066E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801066E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801066E8: jal         0x80009968
    // 0x801066EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801066EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801066F0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801066F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801066F8: addiu       $a1, $a1, 0x6490
    ctx->r5 = ADD32(ctx->r5, 0X6490);
    // 0x801066FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80106700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80106704: jal         0x80008188
    // 0x80106708: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80106708: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010670C: jal         0x8010658C
    // 0x80106710: nop

    grPupupuInitAll(rdram, ctx);
        goto after_2;
    // 0x80106710: nop

    after_2:
    // 0x80106714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106718: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8010671C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80106720: jr          $ra
    // 0x80106724: nop

    return;
    // 0x80106724: nop

;}
RECOMP_FUNC void mpProcessCheckTestLCliffCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB590: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800DB594: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DB598: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DB59C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800DB5A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DB5A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DB5A8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800DB5AC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800DB5B0: addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // 0x800DB5B4: beq         $t7, $at, L_800DB5C4
    if (ctx->r15 == ctx->r1) {
        // 0x800DB5B8: addiu       $v0, $s0, 0x4C
        ctx->r2 = ADD32(ctx->r16, 0X4C);
            goto L_800DB5C4;
    }
    // 0x800DB5B8: addiu       $v0, $s0, 0x4C
    ctx->r2 = ADD32(ctx->r16, 0X4C);
    // 0x800DB5BC: b           L_800DB6DC
    // 0x800DB5C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DB6DC;
    // 0x800DB5C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB5C4:
    // 0x800DB5C4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DB5C8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB5CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DB5D0: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DB5D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DB5D8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800DB5DC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB5E0: addiu       $a3, $s0, 0xC8
    ctx->r7 = ADD32(ctx->r16, 0XC8);
    // 0x800DB5E4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DB5E8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB5EC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DB5F0: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800DB5F4: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800DB5F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB5FC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DB600: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB604: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB608: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DB60C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800DB610: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB614: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DB618: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB61C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB620: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800DB624: lhu         $t9, 0x5C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X5C);
    // 0x800DB628: beql        $t8, $t9, L_800DB658
    if (ctx->r24 == ctx->r25) {
        // 0x800DB62C: sw          $t1, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r9;
            goto L_800DB658;
    }
    goto skip_0;
    // 0x800DB62C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    skip_0:
    // 0x800DB630: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800DB634: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB638: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB63C: addiu       $a3, $s0, 0xC8
    ctx->r7 = ADD32(ctx->r16, 0XC8);
    // 0x800DB640: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800DB644: jal         0x800F521C
    // 0x800DB648: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x800DB648: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800DB64C: b           L_800DB660
    // 0x800DB650: nop

        goto L_800DB660;
    // 0x800DB650: nop

    // 0x800DB654: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
L_800DB658:
    // 0x800DB658: jal         0x800F4BD8
    // 0x800DB65C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800DB65C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
L_800DB660:
    // 0x800DB660: beql        $v0, $zero, L_800DB6DC
    if (ctx->r2 == 0) {
        // 0x800DB664: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DB6DC;
    }
    goto skip_1;
    // 0x800DB664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800DB668: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800DB66C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800DB670: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800DB674: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800DB678: beq         $t2, $zero, L_800DB6D8
    if (ctx->r10 == 0) {
        // 0x800DB67C: and         $t3, $v0, $at
        ctx->r11 = ctx->r2 & ctx->r1;
            goto L_800DB6D8;
    }
    // 0x800DB67C: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x800DB680: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800DB684: beq         $t3, $at, L_800DB6D8
    if (ctx->r11 == ctx->r1) {
        // 0x800DB688: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DB6D8;
    }
    // 0x800DB688: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB68C: jal         0x800F4428
    // 0x800DB690: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x800DB690: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    after_2:
    // 0x800DB694: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800DB698: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DB69C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800DB6A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB6A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB6A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DB6AC: nop

    // 0x800DB6B0: bc1fl       L_800DB6DC
    if (!c1cs) {
        // 0x800DB6B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DB6DC;
    }
    goto skip_2;
    // 0x800DB6B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800DB6B8: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
    // 0x800DB6BC: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DB6C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DB6C4: ori         $t5, $t4, 0x1000
    ctx->r13 = ctx->r12 | 0X1000;
    // 0x800DB6C8: ori         $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 | 0X1000;
    // 0x800DB6CC: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
    // 0x800DB6D0: b           L_800DB6DC
    // 0x800DB6D4: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
        goto L_800DB6DC;
    // 0x800DB6D4: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
L_800DB6D8:
    // 0x800DB6D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB6DC:
    // 0x800DB6DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DB6E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DB6E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800DB6E8: jr          $ra
    // 0x800DB6EC: nop

    return;
    // 0x800DB6EC: nop

;}
RECOMP_FUNC void ftCommonLightThrowDecideSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801466EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801466F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801466F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801466F8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801466FC: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x80146700: bgez        $v0, L_80146710
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80146704: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80146710;
    }
    // 0x80146704: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80146708: b           L_80146710
    // 0x8014670C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80146710;
    // 0x8014670C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80146710:
    // 0x80146710: slti        $at, $v1, 0x38
    ctx->r1 = SIGNED(ctx->r3) < 0X38 ? 1 : 0;
    // 0x80146714: bnel        $at, $zero, L_80146754
    if (ctx->r1 != 0) {
        // 0x80146718: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_80146754;
    }
    goto skip_0;
    // 0x80146718: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_0:
    // 0x8014671C: lbu         $t7, 0x26A($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X26A);
    // 0x80146720: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80146724: beql        $at, $zero, L_80146754
    if (ctx->r1 == 0) {
        // 0x80146728: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_80146754;
    }
    goto skip_1;
    // 0x80146728: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_1:
    // 0x8014672C: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x80146730: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146734: mflo        $t9
    ctx->r25 = lo;
    // 0x80146738: bltz        $t9, L_80146748
    if (SIGNED(ctx->r25) < 0) {
        // 0x8014673C: nop
    
            goto L_80146748;
    }
    // 0x8014673C: nop

    // 0x80146740: b           L_80146918
    // 0x80146744: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
        goto L_80146918;
    // 0x80146744: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
L_80146748:
    // 0x80146748: b           L_80146918
    // 0x8014674C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
        goto L_80146918;
    // 0x8014674C: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80146750: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
L_80146754:
    // 0x80146754: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    // 0x80146758: bnel        $at, $zero, L_801467B0
    if (ctx->r1 != 0) {
        // 0x8014675C: slti        $at, $v1, -0x34
        ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
            goto L_801467B0;
    }
    goto skip_2;
    // 0x8014675C: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
    skip_2:
    // 0x80146760: lbu         $t0, 0x26B($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X26B);
    // 0x80146764: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80146768: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8014676C: bgez        $t0, L_80146780
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80146770: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80146780;
    }
    // 0x80146770: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80146774: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80146778: nop

    // 0x8014677C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80146780:
    // 0x80146780: lw          $t1, 0x9C8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X9C8);
    // 0x80146784: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80146788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014678C: lwc1        $f16, 0x34($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X34);
    // 0x80146790: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80146794: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80146798: nop

    // 0x8014679C: bc1fl       L_801467B0
    if (!c1cs) {
        // 0x801467A0: slti        $at, $v1, -0x34
        ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
            goto L_801467B0;
    }
    goto skip_3;
    // 0x801467A0: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
    skip_3:
    // 0x801467A4: b           L_80146918
    // 0x801467A8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
        goto L_80146918;
    // 0x801467A8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x801467AC: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
L_801467B0:
    // 0x801467B0: beq         $at, $zero, L_801467D0
    if (ctx->r1 == 0) {
        // 0x801467B4: nop
    
            goto L_801467D0;
    }
    // 0x801467B4: nop

    // 0x801467B8: lbu         $t2, 0x26B($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X26B);
    // 0x801467BC: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x801467C0: beq         $at, $zero, L_801467D0
    if (ctx->r1 == 0) {
        // 0x801467C4: nop
    
            goto L_801467D0;
    }
    // 0x801467C4: nop

    // 0x801467C8: b           L_80146918
    // 0x801467CC: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
        goto L_80146918;
    // 0x801467CC: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
L_801467D0:
    // 0x801467D0: bgez        $v0, L_801467E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801467D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801467E0;
    }
    // 0x801467D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801467D8: b           L_801467E0
    // 0x801467DC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801467E0;
    // 0x801467DC: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801467E0:
    // 0x801467E0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801467E4: bne         $at, $zero, L_80146874
    if (ctx->r1 != 0) {
        // 0x801467E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80146874;
    }
    // 0x801467E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801467EC: jal         0x800E8000
    // 0x801467F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x801467F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801467F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801467F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801467FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80146800: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80146804: bc1f        L_80146824
    if (!c1cs) {
        // 0x80146808: nop
    
            goto L_80146824;
    }
    // 0x80146808: nop

    // 0x8014680C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80146810: jal         0x800E8000
    // 0x80146814: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x80146814: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80146818: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014681C: b           L_80146834
    // 0x80146820: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80146834;
    // 0x80146820: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80146824:
    // 0x80146824: jal         0x800E8000
    // 0x80146828: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_2;
    // 0x80146828: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8014682C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80146830: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80146834:
    // 0x80146834: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146838: lwc1        $f8, -0x3E50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3E50);
    // 0x8014683C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80146840: nop

    // 0x80146844: bc1fl       L_80146878
    if (!c1cs) {
        // 0x80146848: lb          $t6, 0x1C3($a1)
        ctx->r14 = MEM_B(ctx->r5, 0X1C3);
            goto L_80146878;
    }
    goto skip_4;
    // 0x80146848: lb          $t6, 0x1C3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C3);
    skip_4:
    // 0x8014684C: lb          $t3, 0x1C2($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1C2);
    // 0x80146850: lw          $t4, 0x44($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X44);
    // 0x80146854: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146858: mflo        $t5
    ctx->r13 = lo;
    // 0x8014685C: bltz        $t5, L_8014686C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80146860: nop
    
            goto L_8014686C;
    }
    // 0x80146860: nop

    // 0x80146864: b           L_80146918
    // 0x80146868: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
        goto L_80146918;
    // 0x80146868: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
L_8014686C:
    // 0x8014686C: b           L_80146918
    // 0x80146870: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
        goto L_80146918;
    // 0x80146870: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
L_80146874:
    // 0x80146874: lb          $t6, 0x1C3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C3);
L_80146878:
    // 0x80146878: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014687C: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80146880: bnel        $at, $zero, L_801468B8
    if (ctx->r1 != 0) {
        // 0x80146884: lb          $t7, 0x1C3($a1)
        ctx->r15 = MEM_B(ctx->r5, 0X1C3);
            goto L_801468B8;
    }
    goto skip_5;
    // 0x80146884: lb          $t7, 0x1C3($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1C3);
    skip_5:
    // 0x80146888: jal         0x800E8000
    // 0x8014688C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_3;
    // 0x8014688C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80146890: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146894: lwc1        $f10, -0x3E4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E4C);
    // 0x80146898: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014689C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801468A0: nop

    // 0x801468A4: bc1fl       L_801468B8
    if (!c1cs) {
        // 0x801468A8: lb          $t7, 0x1C3($a1)
        ctx->r15 = MEM_B(ctx->r5, 0X1C3);
            goto L_801468B8;
    }
    goto skip_6;
    // 0x801468A8: lb          $t7, 0x1C3($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1C3);
    skip_6:
    // 0x801468AC: b           L_80146918
    // 0x801468B0: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
        goto L_80146918;
    // 0x801468B0: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x801468B4: lb          $t7, 0x1C3($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1C3);
L_801468B8:
    // 0x801468B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801468BC: slti        $at, $t7, -0x13
    ctx->r1 = SIGNED(ctx->r15) < -0X13 ? 1 : 0;
    // 0x801468C0: beql        $at, $zero, L_801468F8
    if (ctx->r1 == 0) {
        // 0x801468C4: lw          $t8, 0x84C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X84C);
            goto L_801468F8;
    }
    goto skip_7;
    // 0x801468C4: lw          $t8, 0x84C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X84C);
    skip_7:
    // 0x801468C8: jal         0x800E8000
    // 0x801468CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_4;
    // 0x801468CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_4:
    // 0x801468D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801468D4: lwc1        $f16, -0x3E48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3E48);
    // 0x801468D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801468DC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801468E0: nop

    // 0x801468E4: bc1fl       L_801468F8
    if (!c1cs) {
        // 0x801468E8: lw          $t8, 0x84C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X84C);
            goto L_801468F8;
    }
    goto skip_8;
    // 0x801468E8: lw          $t8, 0x84C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X84C);
    skip_8:
    // 0x801468EC: b           L_80146918
    // 0x801468F0: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
        goto L_80146918;
    // 0x801468F0: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
    // 0x801468F4: lw          $t8, 0x84C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X84C);
L_801468F8:
    // 0x801468F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801468FC: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x80146900: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x80146904: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80146908: bne         $t0, $at, L_80146918
    if (ctx->r8 != ctx->r1) {
        // 0x8014690C: nop
    
            goto L_80146918;
    }
    // 0x8014690C: nop

    // 0x80146910: b           L_80146918
    // 0x80146914: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
        goto L_80146918;
    // 0x80146914: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
L_80146918:
    // 0x80146918: jal         0x80146690
    // 0x8014691C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_5;
    // 0x8014691C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80146920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146928: jr          $ra
    // 0x8014692C: nop

    return;
    // 0x8014692C: nop

;}
RECOMP_FUNC void ftCommonCatchCheckInterruptAttack11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149E24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149E2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80149E30: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80149E34: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x80149E38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80149E3C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80149E40: jal         0x80146A8C
    // 0x80149E44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x80149E44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80149E48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80149E4C: beq         $v0, $zero, L_80149E68
    if (ctx->r2 == 0) {
        // 0x80149E50: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80149E68;
    }
    // 0x80149E50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80149E54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80149E58: jal         0x80146690
    // 0x80149E5C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149E5C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_1:
    // 0x80149E60: b           L_80149EA4
    // 0x80149E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149EA4;
    // 0x80149E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149E68:
    // 0x80149E68: lhu         $t7, 0x1BE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BE);
    // 0x80149E6C: lhu         $t8, 0x1B8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80149E70: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80149E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80149E78: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80149E7C: beq         $t9, $zero, L_80149EA4
    if (ctx->r25 == 0) {
        // 0x80149E80: nop
    
            goto L_80149EA4;
    }
    // 0x80149E80: nop

    // 0x80149E84: lw          $t1, 0x100($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X100);
    // 0x80149E88: sll         $t3, $t1, 20
    ctx->r11 = S32(ctx->r9 << 20);
    // 0x80149E8C: bgez        $t3, L_80149EA4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80149E90: nop
    
            goto L_80149EA4;
    }
    // 0x80149E90: nop

    // 0x80149E94: jal         0x80149BA8
    // 0x80149E98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x80149E98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80149E9C: b           L_80149EA4
    // 0x80149EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149EA4;
    // 0x80149EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149EA4:
    // 0x80149EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149EA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149EAC: jr          $ra
    // 0x80149EB0: nop

    return;
    // 0x80149EB0: nop

;}
RECOMP_FUNC void itDogasCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182F40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182F48: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182F4C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182F50: bnel        $a1, $zero, L_80182F7C
    if (ctx->r5 != 0) {
        // 0x80182F54: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80182F7C;
    }
    goto skip_0;
    // 0x80182F54: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80182F58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80182F5C: nop

    // 0x80182F60: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80182F64: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80182F68: jal         0x80182F0C
    // 0x80182F6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itDogasAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x80182F6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80182F70: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80182F74: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182F78: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_80182F7C:
    // 0x80182F7C: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182F8C: jr          $ra
    // 0x80182F90: nop

    return;
    // 0x80182F90: nop

;}
RECOMP_FUNC void mnUnusedFightersFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D65C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800D65C8: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x800D65CC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x800D65D0: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D65D4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D65D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x800D65DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x800D65E0: addiu       $t8, $t8, 0x7118
    ctx->r24 = ADD32(ctx->r24, 0X7118);
    // 0x800D65E4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800D65E8: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x800D65EC: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x800D65F0: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800D65F4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800D65F8: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x800D65FC: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800D6600: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800D6604: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x800D6608: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x800D660C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800D6610: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800D6614: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x800D6618: jal         0x800CDF78
    // 0x800D661C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x800D661C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_0:
    // 0x800D6620: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800D6624: addiu       $s0, $s0, 0x7010
    ctx->r16 = ADD32(ctx->r16, 0X7010);
    // 0x800D6628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D662C: jal         0x800CDEEC
    // 0x800D6630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x800D6630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800D6634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D6638: jal         0x80004980
    // 0x800D663C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x800D663C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x800D6640: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800D6644: addiu       $s3, $s3, 0x7168
    ctx->r19 = ADD32(ctx->r19, 0X7168);
    // 0x800D6648: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D664C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D6650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D6654: jal         0x800CDE04
    // 0x800D6658: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x800D6658: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x800D665C: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x800D6660: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D6664: addiu       $a1, $a1, 0x655C
    ctx->r5 = ADD32(ctx->r5, 0X655C);
    // 0x800D6668: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D666C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6670: jal         0x80009968
    // 0x800D6674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x800D6674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800D6678: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800D667C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800D6680: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D6684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6688: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800D668C: jal         0x8000B9FC
    // 0x800D6690: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x800D6690: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x800D6694: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800D6698: addiu       $t1, $t1, -0x2D34
    ctx->r9 = ADD32(ctx->r9, -0X2D34);
    // 0x800D669C: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x800D66A0: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x800D66A4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800D66A8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800D66AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D66B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D66B4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800D66B8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800D66BC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800D66C0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800D66C4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800D66C8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800D66CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800D66D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D66D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D66D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D66DC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D66E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800D66E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D66E8: jal         0x8000B93C
    // 0x800D66EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_6;
    // 0x800D66EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_6:
    // 0x800D66F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800D66F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D66F8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800D66FC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x800D6700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D6704: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800D6708: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800D670C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x800D6710: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800D6714: jal         0x80007080
    // 0x800D6718: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_7;
    // 0x800D6718: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x800D671C: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x800D6720: addiu       $t8, $t8, 0x7DBC
    ctx->r24 = ADD32(ctx->r24, 0X7DBC);
    // 0x800D6724: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800D6728: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800D672C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800D6730: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800D6734: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D6738: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D673C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6740: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800D6744: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800D6748: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800D674C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D6750: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800D6754: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800D6758: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800D675C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D6760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D6764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D676C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D6770: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D6774: jal         0x8000B93C
    // 0x800D6778: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_8;
    // 0x800D6778: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_8:
    // 0x800D677C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D6780: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x800D6784: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D6788: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x800D678C: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x800D6790: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x800D6794: lwc1        $f6, 0x7108($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7108);
    // 0x800D6798: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D679C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D67A0: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x800D67A4: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x800D67A8: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x800D67AC: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x800D67B0: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x800D67B4: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x800D67B8: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x800D67BC: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800D67C0: addiu       $t9, $t9, 0x4728
    ctx->r25 = ADD32(ctx->r25, 0X4728);
    // 0x800D67C4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800D67C8: addiu       $s2, $s2, -0x3100
    ctx->r18 = ADD32(ctx->r18, -0X3100);
    // 0x800D67CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D67D0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D67D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D67D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D67DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D67E0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800D67E4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800D67E8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800D67EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800D67F0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800D67F4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D67F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D67FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6800: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6808: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D680C: jal         0x8000B8BC
    // 0x800D6810: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_9;
    // 0x800D6810: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_9:
    // 0x800D6814: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800D6818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D681C: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x800D6820: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D6824: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D6828: swc1        $f10, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f10.u32l;
    // 0x800D682C: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x800D6830: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x800D6834: addiu       $t8, $t8, 0x6978
    ctx->r24 = ADD32(ctx->r24, 0X6978);
    // 0x800D6838: swc1        $f16, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f16.u32l;
    // 0x800D683C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800D6840: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6844: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D6848: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D684C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D6850: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D6854: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800D6858: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800D685C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800D6860: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800D6864: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800D6868: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D686C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6870: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6874: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D687C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6880: jal         0x8000B8BC
    // 0x800D6884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_10;
    // 0x800D6884: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x800D6888: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800D688C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D6890: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x800D6894: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D6898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D689C: swc1        $f18, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f18.u32l;
    // 0x800D68A0: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x800D68A4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800D68A8: addiu       $t7, $t7, -0x7438
    ctx->r15 = ADD32(ctx->r15, -0X7438);
    // 0x800D68AC: swc1        $f4, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f4.u32l;
    // 0x800D68B0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800D68B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D68B8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800D68BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D68C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D68C4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D68C8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800D68CC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800D68D0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800D68D4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800D68D8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800D68DC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D68E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D68E4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D68E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D68EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D68F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D68F4: jal         0x8000B8BC
    // 0x800D68F8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_11;
    // 0x800D68F8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_11:
    // 0x800D68FC: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x800D6900: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D6904: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x800D6908: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D690C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D6910: swc1        $f6, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f6.u32l;
    // 0x800D6914: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x800D6918: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800D691C: addiu       $t6, $t6, -0x51E8
    ctx->r14 = ADD32(ctx->r14, -0X51E8);
    // 0x800D6920: swc1        $f8, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f8.u32l;
    // 0x800D6924: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800D6928: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D692C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800D6930: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D6934: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6938: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800D693C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800D6940: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D6944: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800D6948: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800D694C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D6950: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6954: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6958: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D695C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6968: jal         0x8000B8BC
    // 0x800D696C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_12;
    // 0x800D696C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x800D6970: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800D6974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6978: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x800D697C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D6980: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D6984: swc1        $f10, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f10.u32l;
    // 0x800D6988: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x800D698C: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x800D6990: addiu       $t3, $t3, -0x2F98
    ctx->r11 = ADD32(ctx->r11, -0X2F98);
    // 0x800D6994: swc1        $f16, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f16.u32l;
    // 0x800D6998: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800D699C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D69A0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800D69A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D69A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D69AC: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x800D69B0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800D69B4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800D69B8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800D69BC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800D69C0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800D69C4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D69C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D69CC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D69D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D69D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D69D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D69DC: jal         0x8000B8BC
    // 0x800D69E0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_13;
    // 0x800D69E0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_13:
    // 0x800D69E4: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x800D69E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D69EC: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x800D69F0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D69F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D69F8: swc1        $f18, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f18.u32l;
    // 0x800D69FC: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x800D6A00: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x800D6A04: addiu       $t5, $t5, -0xD48
    ctx->r13 = ADD32(ctx->r13, -0XD48);
    // 0x800D6A08: swc1        $f4, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = ctx->f4.u32l;
    // 0x800D6A0C: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800D6A10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D6A14: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800D6A18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6A1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D6A20: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800D6A24: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800D6A28: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D6A2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D6A30: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800D6A34: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800D6A38: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6A3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6A40: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6A44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6A4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6A50: jal         0x8000B8BC
    // 0x800D6A54: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_14;
    // 0x800D6A54: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_14:
    // 0x800D6A58: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800D6A5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D6A60: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6A64: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800D6A68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D6A6C: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x800D6A70: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x800D6A74: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x800D6A78: addiu       $t4, $t4, 0x1508
    ctx->r12 = ADD32(ctx->r12, 0X1508);
    // 0x800D6A7C: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
    // 0x800D6A80: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800D6A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D6A88: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D6A8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6A90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6A94: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800D6A98: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800D6A9C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800D6AA0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D6AA4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800D6AA8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800D6AAC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6AB0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6AB4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6AC4: jal         0x8000B8BC
    // 0x800D6AC8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_15;
    // 0x800D6AC8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_15:
    // 0x800D6ACC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800D6AD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6AD4: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800D6AD8: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x800D6ADC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D6AE0: swc1        $f10, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f10.u32l;
    // 0x800D6AE4: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6AE8: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800D6AEC: addiu       $t2, $t2, 0x3758
    ctx->r10 = ADD32(ctx->r10, 0X3758);
    // 0x800D6AF0: swc1        $f16, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f16.u32l;
    // 0x800D6AF4: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800D6AF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6AFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D6B00: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D6B04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6B08: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800D6B0C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800D6B10: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800D6B14: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800D6B18: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800D6B1C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800D6B20: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6B24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6B28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6B2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6B34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6B38: jal         0x8000B8BC
    // 0x800D6B3C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_16;
    // 0x800D6B3C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x800D6B40: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800D6B44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D6B48: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800D6B4C: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x800D6B50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D6B54: swc1        $f18, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f18.u32l;
    // 0x800D6B58: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800D6B5C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x800D6B60: addiu       $t1, $t1, 0x59A8
    ctx->r9 = ADD32(ctx->r9, 0X59A8);
    // 0x800D6B64: swc1        $f4, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f4.u32l;
    // 0x800D6B68: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800D6B6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D6B70: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D6B74: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D6B78: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D6B7C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800D6B80: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D6B84: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800D6B88: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800D6B8C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800D6B90: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800D6B94: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6B98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6B9C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6BA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6BAC: jal         0x8000B8BC
    // 0x800D6BB0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_17;
    // 0x800D6BB0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_17:
    // 0x800D6BB4: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x800D6BB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D6BBC: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x800D6BC0: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x800D6BC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D6BC8: swc1        $f6, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f6.u32l;
    // 0x800D6BCC: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800D6BD0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x800D6BD4: addiu       $t0, $t0, 0x1838
    ctx->r8 = ADD32(ctx->r8, 0X1838);
    // 0x800D6BD8: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
    // 0x800D6BDC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800D6BE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D6BE4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D6BE8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D6BEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D6BF0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800D6BF4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800D6BF8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800D6BFC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800D6C00: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800D6C04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D6C08: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6C0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6C10: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6C14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6C20: jal         0x8000B8BC
    // 0x800D6C24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_18;
    // 0x800D6C24: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x800D6C28: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x800D6C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6C30: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x800D6C34: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x800D6C38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D6C3C: swc1        $f10, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f10.u32l;
    // 0x800D6C40: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x800D6C44: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x800D6C48: addiu       $t4, $t4, 0x2358
    ctx->r12 = ADD32(ctx->r12, 0X2358);
    // 0x800D6C4C: swc1        $f16, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f16.u32l;
    // 0x800D6C50: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6C54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6C58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D6C5C: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6C60: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D6C64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6C68: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x800D6C6C: sh          $t7, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r15;
    // 0x800D6C70: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6C74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6C7C: lhu         $t8, 0x24($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6C80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6C84: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D6C88: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800D6C8C: sh          $t9, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r25;
    // 0x800D6C90: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800D6C94: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800D6C98: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6C9C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800D6CA0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800D6CA4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D6CA8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800D6CAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6CB0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800D6CB4: jal         0x8000B8BC
    // 0x800D6CB8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_19;
    // 0x800D6CB8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_19:
    // 0x800D6CBC: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x800D6CC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D6CC4: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800D6CC8: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x800D6CCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D6CD0: swc1        $f18, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f18.u32l;
    // 0x800D6CD4: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6CD8: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x800D6CDC: addiu       $t6, $t6, 0x32F8
    ctx->r14 = ADD32(ctx->r14, 0X32F8);
    // 0x800D6CE0: swc1        $f4, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f4.u32l;
    // 0x800D6CE4: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6CE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D6CEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D6CF0: lhu         $t9, 0x24($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6CF4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800D6CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6CFC: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x800D6D00: sh          $t0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r8;
    // 0x800D6D04: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6D08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6D10: lhu         $t1, 0x24($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6D14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6D18: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D6D1C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800D6D20: sh          $t2, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r10;
    // 0x800D6D24: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800D6D28: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D6D2C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6D30: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800D6D34: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800D6D38: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800D6D3C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800D6D40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6D44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D6D48: jal         0x8000B8BC
    // 0x800D6D4C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_20;
    // 0x800D6D4C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_20:
    // 0x800D6D50: lui         $at, 0x4323
    ctx->r1 = S32(0X4323 << 16);
    // 0x800D6D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D6D58: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x800D6D5C: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x800D6D60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D6D64: swc1        $f6, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f6.u32l;
    // 0x800D6D68: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x800D6D6C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x800D6D70: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x800D6D74: swc1        $f8, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f8.u32l;
    // 0x800D6D78: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6D7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D6D80: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6D84: lhu         $t2, 0x24($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6D88: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D6D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6D90: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x800D6D94: sh          $t4, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r12;
    // 0x800D6D98: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6D9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D6DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6DA4: lhu         $t5, 0x24($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6DA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6DAC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800D6DB0: ori         $t3, $t5, 0x1
    ctx->r11 = ctx->r13 | 0X1;
    // 0x800D6DB4: sh          $t3, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r11;
    // 0x800D6DB8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800D6DBC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800D6DC0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6DC4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D6DC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800D6DCC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800D6DD0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800D6DD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6DD8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800D6DDC: jal         0x8000B8BC
    // 0x800D6DE0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_21;
    // 0x800D6DE0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_21:
    // 0x800D6DE4: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
    // 0x800D6DE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6DEC: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x800D6DF0: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x800D6DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D6DF8: swc1        $f10, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f10.u32l;
    // 0x800D6DFC: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x800D6E00: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x800D6E04: addiu       $t2, $t2, 0x48B0
    ctx->r10 = ADD32(ctx->r10, 0X48B0);
    // 0x800D6E08: swc1        $f16, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f16.u32l;
    // 0x800D6E0C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6E10: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D6E14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6E18: lhu         $t3, 0x24($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6E1C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D6E20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6E24: andi        $t6, $t3, 0xFFDF
    ctx->r14 = ctx->r11 & 0XFFDF;
    // 0x800D6E28: sh          $t6, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r14;
    // 0x800D6E2C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6E30: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800D6E34: addiu       $t3, $t3, 0x64C4
    ctx->r11 = ADD32(ctx->r11, 0X64C4);
    // 0x800D6E38: lhu         $t7, 0x24($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6E3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6E44: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800D6E48: sh          $t8, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r24;
    // 0x800D6E4C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800D6E50: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800D6E54: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800D6E58: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800D6E5C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800D6E60: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800D6E64: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800D6E68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6E6C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800D6E70: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6E74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6E78: jal         0x8000B8BC
    // 0x800D6E7C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_22;
    // 0x800D6E7C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x800D6E80: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x800D6E84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D6E88: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D6E8C: addiu       $v1, $v1, 0x716C
    ctx->r3 = ADD32(ctx->r3, 0X716C);
    // 0x800D6E90: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800D6E94: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800D6E98: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D6E9C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800D6EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D6EA4: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x800D6EA8: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6EAC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x800D6EB0: addiu       $t5, $t5, 0x3EF0
    ctx->r13 = ADD32(ctx->r13, 0X3EF0);
    // 0x800D6EB4: swc1        $f6, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f6.u32l;
    // 0x800D6EB8: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6EBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D6EC0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D6EC4: lhu         $t9, 0x24($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6EC8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800D6ECC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6ED0: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x800D6ED4: sh          $t0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r8;
    // 0x800D6ED8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800D6EDC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D6EE0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D6EE4: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800D6EE8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800D6EEC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D6EF0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800D6EF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D6EF8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800D6EFC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800D6F00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6F04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6F0C: jal         0x8000B8BC
    // 0x800D6F10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeSpriteGObj(rdram, ctx);
        goto after_23;
    // 0x800D6F10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_23:
    // 0x800D6F14: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x800D6F18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D6F1C: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F20: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x800D6F24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6F28: swc1        $f8, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f8.u32l;
    // 0x800D6F2C: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F30: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800D6F34: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800D6F38: swc1        $f10, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f10.u32l;
    // 0x800D6F3C: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F40: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x800D6F44: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800D6F48: sb          $t0, 0x60($t1)
    MEM_B(0X60, ctx->r9) = ctx->r8;
    // 0x800D6F4C: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F50: sb          $t2, 0x61($t4)
    MEM_B(0X61, ctx->r12) = ctx->r10;
    // 0x800D6F54: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F58: sb          $t5, 0x62($t3)
    MEM_B(0X62, ctx->r11) = ctx->r13;
    // 0x800D6F5C: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F60: sb          $v1, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r3;
    // 0x800D6F64: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F68: sb          $v1, 0x29($t7)
    MEM_B(0X29, ctx->r15) = ctx->r3;
    // 0x800D6F6C: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F70: sb          $v1, 0x2A($t8)
    MEM_B(0X2A, ctx->r24) = ctx->r3;
    // 0x800D6F74: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F78: lhu         $t9, 0x24($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6F7C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x800D6F80: sh          $t0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r8;
    // 0x800D6F84: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x800D6F88: lhu         $t1, 0x24($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X24);
    // 0x800D6F8C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800D6F90: sh          $t2, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r10;
    // 0x800D6F94: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6F98: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800D6F9C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800D6FA0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800D6FA4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6FA8: jr          $ra
    // 0x800D6FAC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800D6FAC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void efManagerMusicNoteMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801039D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801039D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801039DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801039E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801039E4: jal         0x80018994
    // 0x801039E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x801039E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x801039EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801039F0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801039F4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801039F8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x801039FC: lbu         $a1, -0x18E4($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X18E4);
    // 0x80103A00: jal         0x800CE9E8
    // 0x80103A04: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_1;
    // 0x80103A04: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_1:
    // 0x80103A08: beq         $v0, $zero, L_80103A70
    if (ctx->r2 == 0) {
        // 0x80103A0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80103A70;
    }
    // 0x80103A0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80103A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103A14: jal         0x800CE1DC
    // 0x80103A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_2;
    // 0x80103A18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80103A1C: beq         $v0, $zero, L_80103A64
    if (ctx->r2 == 0) {
        // 0x80103A20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80103A64;
    }
    // 0x80103A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103A24: jal         0x800CEA14
    // 0x80103A28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x80103A28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80103A2C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80103A30: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80103A34: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80103A38: bnel        $t6, $zero, L_80103A4C
    if (ctx->r14 != 0) {
        // 0x80103A3C: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80103A4C;
    }
    goto skip_0;
    // 0x80103A3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80103A40: b           L_80103A74
    // 0x80103A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103A74;
    // 0x80103A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80103A48: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80103A4C:
    // 0x80103A4C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80103A50: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80103A54: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80103A58: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80103A5C: b           L_80103A70
    // 0x80103A60: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80103A70;
    // 0x80103A60: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80103A64:
    // 0x80103A64: jal         0x800CEA40
    // 0x80103A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_4;
    // 0x80103A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80103A6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80103A70:
    // 0x80103A70: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80103A74:
    // 0x80103A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103A7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103A80: jr          $ra
    // 0x80103A84: nop

    return;
    // 0x80103A84: nop

;}
RECOMP_FUNC void mvOpeningMarioMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D614: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8018D618: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D61C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D620: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D624: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D628: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D62C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D630: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D634: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D638: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D63C: jal         0x80104BDC
    // 0x8018D640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D644: jal         0x80105600
    // 0x8018D648: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D648: nop

    after_1:
    // 0x8018D64C: jal         0x800FC7A4
    // 0x8018D650: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D650: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D654: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D658: beq         $v0, $at, L_8018D680
    if (ctx->r2 == ctx->r1) {
        // 0x8018D65C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D680;
    }
    // 0x8018D65C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D660: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D664: addiu       $s0, $s0, -0x1E30
    ctx->r16 = ADD32(ctx->r16, -0X1E30);
L_8018D668:
    // 0x8018D668: jal         0x80023624
    // 0x8018D66C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D66C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D670: jal         0x800A3040
    // 0x8018D674: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D674: nop

    after_4:
    // 0x8018D678: b           L_8018D668
    // 0x8018D67C: nop

        goto L_8018D668;
    // 0x8018D67C: nop

L_8018D680:
    // 0x8018D680: jal         0x800FC814
    // 0x8018D684: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D684: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_5:
    // 0x8018D688: addiu       $s0, $sp, 0x8C
    ctx->r16 = ADD32(ctx->r29, 0X8C);
    // 0x8018D68C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D690: jal         0x800FC894
    // 0x8018D694: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D694: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    after_6:
    // 0x8018D698: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D69C: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D6A0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D6A4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D6A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D6AC: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6B0: jal         0x8018D40C
    // 0x8018D6B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningMarioMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6B8: jal         0x801156E4
    // 0x8018D6BC: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6BC: nop

    after_8:
    // 0x8018D6C0: jal         0x801653E0
    // 0x8018D6C4: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6C4: nop

    after_9:
    // 0x8018D6C8: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6CC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6D0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D6D4: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D6D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D6DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D6E0: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D6E4: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D6E8: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
L_8018D6EC:
    // 0x8018D6EC: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D6F0: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D6F4: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D6F8:
    // 0x8018D6F8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D6FC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D700: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D704: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D708: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D70C: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D710: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D714: bne         $t0, $t2, L_8018D6F8
    if (ctx->r8 != ctx->r10) {
        // 0x8018D718: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D6F8;
    }
    // 0x8018D718: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D71C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D720: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D724: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D728: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D72C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D730: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D734: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D738: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D73C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D740: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D744: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D748: beql        $s7, $t4, L_8018D80C
    if (ctx->r23 == ctx->r12) {
        // 0x8018D74C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D80C;
    }
    goto skip_0;
    // 0x8018D74C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D750: jal         0x800D786C
    // 0x8018D754: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D754: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D758: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D75C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8018D760: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D764: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D768: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D76C: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D770: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D774: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018D778: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8018D77C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8018D780: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8018D784: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x8018D788: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D78C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D790: sb          $s1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r17;
    // 0x8018D794: sb          $t1, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r9;
    // 0x8018D798: sb          $t0, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r8;
    // 0x8018D79C: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D7A0: sb          $t8, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r24;
    // 0x8018D7A4: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D7A8: sb          $t9, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r25;
    // 0x8018D7AC: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7B0: sb          $t3, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r11;
    // 0x8018D7B4: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7B8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8018D7BC: sb          $t4, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r12;
    // 0x8018D7C0: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7C4: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x8018D7C8: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8018D7CC: jal         0x800D78B4
    // 0x8018D7D0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7D0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7D4: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8018D7D8: jal         0x800D7F3C
    // 0x8018D7DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D7DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D7E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D7E4: sw          $v0, -0x1DF0($at)
    MEM_W(-0X1DF0, ctx->r1) = ctx->r2;
    // 0x8018D7E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D7EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D7F0: jal         0x800E7C4C
    // 0x8018D7F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D7F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D7F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D7FC: addiu       $a1, $a1, -0x1F38
    ctx->r5 = ADD32(ctx->r5, -0X1F38);
    // 0x8018D800: jal         0x800E9B30
    // 0x8018D804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D808: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D80C:
    // 0x8018D80C: bne         $s1, $fp, L_8018D6EC
    if (ctx->r17 != ctx->r30) {
        // 0x8018D810: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D6EC;
    }
    // 0x8018D810: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D814: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D81C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D820: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D824: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D828: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D82C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D830: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D834: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D838: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D83C: jr          $ra
    // 0x8018D840: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8018D840: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ftCommonItemThrowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014634C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80146350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80146354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80146358: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014635C: jal         0x801462A0
    // 0x80146360: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    ftCommonItemThrowUpdateModelYaw(rdram, ctx);
        goto after_0;
    // 0x80146360: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x80146364: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    // 0x80146368: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014636C: beq         $v0, $zero, L_801463B4
    if (ctx->r2 == 0) {
        // 0x80146370: sll         $t6, $v0, 8
        ctx->r14 = S32(ctx->r2 << 8);
            goto L_801463B4;
    }
    // 0x80146370: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x80146374: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80146378: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8014637C: lwc1        $f0, -0x3E5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3E5C);
    // 0x80146380: bgez        $t7, L_80146398
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80146384: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80146398;
    }
    // 0x80146384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80146388: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8014638C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80146390: nop

    // 0x80146394: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80146398:
    // 0x80146398: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8014639C: lw          $t8, 0x184($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X184);
    // 0x801463A0: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x801463A4: sll         $t9, $t8, 20
    ctx->r25 = S32(ctx->r24 << 20);
    // 0x801463A8: sra         $t0, $t9, 20
    ctx->r8 = S32(SIGNED(ctx->r25) >> 20);
    // 0x801463AC: sw          $t0, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r8;
    // 0x801463B0: swc1        $f10, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->f10.u32l;
L_801463B4:
    // 0x801463B4: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x801463B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801463BC: lwc1        $f0, -0x3E58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3E58);
    // 0x801463C0: beq         $v0, $zero, L_801463F8
    if (ctx->r2 == 0) {
        // 0x801463C4: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_801463F8;
    }
    // 0x801463C4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801463C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801463CC: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x801463D0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801463D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801463D8: bgez        $t1, L_801463EC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801463DC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801463EC;
    }
    // 0x801463DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801463E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801463E4: nop

    // 0x801463E8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801463EC:
    // 0x801463EC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801463F0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x801463F4: swc1        $f8, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->f8.u32l;
L_801463F8:
    // 0x801463F8: lw          $t2, 0x84C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84C);
    // 0x801463FC: beql        $t2, $zero, L_801465E4
    if (ctx->r10 == 0) {
        // 0x80146400: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_801465E4;
    }
    goto skip_0;
    // 0x80146400: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x80146404: lw          $t3, 0x17C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X17C);
    // 0x80146408: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8014640C: addiu       $t5, $t5, -0x3620
    ctx->r13 = ADD32(ctx->r13, -0X3620);
    // 0x80146410: beql        $t3, $zero, L_801465E4
    if (ctx->r11 == 0) {
        // 0x80146414: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_801465E4;
    }
    goto skip_1;
    // 0x80146414: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x80146418: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014641C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80146420: beq         $v0, $at, L_80146438
    if (ctx->r2 == ctx->r1) {
        // 0x80146424: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80146438;
    }
    // 0x80146424: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80146428: beq         $v0, $at, L_80146438
    if (ctx->r2 == ctx->r1) {
        // 0x8014642C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80146438;
    }
    // 0x8014642C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80146430: bnel        $v0, $at, L_8014645C
    if (ctx->r2 != ctx->r1) {
        // 0x80146434: lw          $v1, 0x24($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X24);
            goto L_8014645C;
    }
    goto skip_2;
    // 0x80146434: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_80146438:
    // 0x80146438: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8014643C: slti        $at, $v0, 0xF6
    ctx->r1 = SIGNED(ctx->r2) < 0XF6 ? 1 : 0;
    // 0x80146440: bne         $at, $zero, L_80146458
    if (ctx->r1 != 0) {
        // 0x80146444: slti        $at, $v0, 0xFA
        ctx->r1 = SIGNED(ctx->r2) < 0XFA ? 1 : 0;
            goto L_80146458;
    }
    // 0x80146444: slti        $at, $v0, 0xFA
    ctx->r1 = SIGNED(ctx->r2) < 0XFA ? 1 : 0;
    // 0x80146448: beql        $at, $zero, L_8014645C
    if (ctx->r1 == 0) {
        // 0x8014644C: lw          $v1, 0x24($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X24);
            goto L_8014645C;
    }
    goto skip_3;
    // 0x8014644C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x80146450: b           L_8014645C
    // 0x80146454: addiu       $v1, $v0, -0x7C
    ctx->r3 = ADD32(ctx->r2, -0X7C);
        goto L_8014645C;
    // 0x80146454: addiu       $v1, $v0, -0x7C
    ctx->r3 = ADD32(ctx->r2, -0X7C);
L_80146458:
    // 0x80146458: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
L_8014645C:
    // 0x8014645C: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80146460: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80146464: lw          $a0, -0x1A0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X1A0);
    // 0x80146468: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014646C: lwc1        $f16, 0xB24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB24);
    // 0x80146470: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80146474: sra         $t7, $t6, 22
    ctx->r15 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80146478: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8014647C: lhu         $t8, 0xE4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE4);
    // 0x80146480: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80146484: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80146488: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8014648C: sll         $v1, $a0, 11
    ctx->r3 = S32(ctx->r4 << 11);
    // 0x80146490: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80146494: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80146498: bgez        $t8, L_801464AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8014649C: nop
    
            goto L_801464AC;
    }
    // 0x8014649C: nop

    // 0x801464A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801464A4: nop

    // 0x801464A8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_801464AC:
    // 0x801464AC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801464B0: addiu       $at, $zero, 0x169
    ctx->r1 = ADD32(0, 0X169);
    // 0x801464B4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801464B8: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x801464BC: lw          $a2, 0xB28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB28);
    // 0x801464C0: bnel        $a2, $at, L_801464D4
    if (ctx->r6 != ctx->r1) {
        // 0x801464C4: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_801464D4;
    }
    goto skip_4;
    // 0x801464C4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    skip_4:
    // 0x801464C8: b           L_801464D4
    // 0x801464CC: sra         $v1, $v1, 21
    ctx->r3 = S32(SIGNED(ctx->r3) >> 21);
        goto L_801464D4;
    // 0x801464CC: sra         $v1, $v1, 21
    ctx->r3 = S32(SIGNED(ctx->r3) >> 21);
    // 0x801464D0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_801464D4:
    // 0x801464D4: lw          $t9, -0x1A0($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X1A0);
    // 0x801464D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801464DC: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x801464E0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801464E4: bgez        $t0, L_801464F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801464E8: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_801464F8;
    }
    // 0x801464E8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801464EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801464F0: nop

    // 0x801464F4: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_801464F8:
    // 0x801464F8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801464FC: lhu         $t1, 0xE6($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0XE6);
    // 0x80146500: lwc1        $f10, 0xB2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB2C);
    // 0x80146504: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80146508: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8014650C: nop

    // 0x80146510: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80146514: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80146518: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8014651C: bgez        $t1, L_80146530
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80146520: nop
    
            goto L_80146530;
    }
    // 0x80146520: nop

    // 0x80146524: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80146528: nop

    // 0x8014652C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80146530:
    // 0x80146530: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80146534: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146538: lwc1        $f16, -0x3E54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3E54);
    // 0x8014653C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80146540: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80146544: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80146548: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8014654C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80146550: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80146554: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80146558: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8014655C: jal         0x80035CD0
    // 0x80146560: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80146560: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80146564: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x80146568: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8014656C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80146570: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80146574: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80146578: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8014657C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80146580: jal         0x800303F0
    // 0x80146584: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80146584: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80146588: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8014658C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80146590: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80146594: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80146598: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8014659C: addiu       $t3, $t3, -0x3480
    ctx->r11 = ADD32(ctx->r11, -0X3480);
    // 0x801465A0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801465A4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x801465A8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x801465AC: bne         $v0, $t3, L_801465CC
    if (ctx->r2 != ctx->r11) {
        // 0x801465B0: swc1        $f10, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
            goto L_801465CC;
    }
    // 0x801465B0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x801465B4: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    // 0x801465B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801465BC: jal         0x80172AEC
    // 0x801465C0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    itMainSetFighterDrop(rdram, ctx);
        goto after_3;
    // 0x801465C0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x801465C4: b           L_801465E0
    // 0x801465C8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
        goto L_801465E0;
    // 0x801465C8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_801465CC:
    // 0x801465CC: lw          $a3, -0x1A0($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X1A0);
    // 0x801465D0: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    // 0x801465D4: jal         0x80172B78
    // 0x801465D8: sra         $a3, $a3, 31
    ctx->r7 = S32(SIGNED(ctx->r7) >> 31);
    itMainSetFighterThrow(rdram, ctx);
        goto after_4;
    // 0x801465D8: sra         $a3, $a3, 31
    ctx->r7 = S32(SIGNED(ctx->r7) >> 31);
    after_4:
    // 0x801465DC: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_801465E0:
    // 0x801465E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_801465E4:
    // 0x801465E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801465E8: lwc1        $f16, 0x78($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801465EC: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x801465F0: nop

    // 0x801465F4: bc1fl       L_80146608
    if (!c1cs) {
        // 0x801465F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80146608;
    }
    goto skip_5;
    // 0x801465F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x801465FC: jal         0x800DEE54
    // 0x80146600: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_5;
    // 0x80146600: nop

    after_5:
    // 0x80146604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80146608:
    // 0x80146608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014660C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80146610: jr          $ra
    // 0x80146614: nop

    return;
    // 0x80146614: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingCheckManFighterSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135674: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80135678: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013567C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135680: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135684: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135688: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x8013568C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135690: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80135694: lw          $t8, 0x54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X54);
    // 0x80135698: beql        $t8, $zero, L_801356C8
    if (ctx->r24 == 0) {
        // 0x8013569C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801356C8;
    }
    goto skip_0;
    // 0x8013569C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801356A0: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x801356A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801356A8: bnel        $t9, $at, L_801356C8
    if (ctx->r25 != ctx->r1) {
        // 0x801356AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801356C8;
    }
    goto skip_1;
    // 0x801356AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801356B0: lw          $t0, 0x80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X80);
    // 0x801356B4: bnel        $t0, $zero, L_801356C8
    if (ctx->r8 != 0) {
        // 0x801356B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801356C8;
    }
    goto skip_2;
    // 0x801356B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801356BC: jr          $ra
    // 0x801356C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801356C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801356C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801356C8:
    // 0x801356C8: jr          $ra
    // 0x801356CC: nop

    return;
    // 0x801356CC: nop

;}
RECOMP_FUNC void sc1PManagerTrySetChallengers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6590: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D6594: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x800D6598: lbu         $v0, 0x457($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X457);
    // 0x800D659C: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800D65A0: bne         $t6, $zero, L_800D65E8
    if (ctx->r14 != 0) {
        // 0x800D65A4: andi        $t1, $v0, 0x4
        ctx->r9 = ctx->r2 & 0X4;
            goto L_800D65E8;
    }
    // 0x800D65A4: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800D65A8: lbu         $t7, 0x45A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X45A);
    // 0x800D65AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D65B0: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x800D65B4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800D65B8: bne         $at, $zero, L_800D65E8
    if (ctx->r1 != 0) {
        // 0x800D65BC: nop
    
            goto L_800D65E8;
    }
    // 0x800D65BC: nop

    // 0x800D65C0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x800D65C4: bne         $t8, $zero, L_800D65E8
    if (ctx->r24 != 0) {
        // 0x800D65C8: nop
    
            goto L_800D65E8;
    }
    // 0x800D65C8: nop

    // 0x800D65CC: lbu         $t9, 0x45B($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X45B);
    // 0x800D65D0: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x800D65D4: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800D65D8: beq         $at, $zero, L_800D65E8
    if (ctx->r1 == 0) {
        // 0x800D65DC: nop
    
            goto L_800D65E8;
    }
    // 0x800D65DC: nop

    // 0x800D65E0: jr          $ra
    // 0x800D65E4: sb          $t0, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r8;
    return;
    // 0x800D65E4: sb          $t0, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r8;
L_800D65E8:
    // 0x800D65E8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D65EC: bne         $t1, $zero, L_800D6618
    if (ctx->r9 != 0) {
        // 0x800D65F0: addiu       $a0, $a0, 0x4AD0
        ctx->r4 = ADD32(ctx->r4, 0X4AD0);
            goto L_800D6618;
    }
    // 0x800D65F0: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x800D65F4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D65F8: lw          $t2, 0xD64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XD64);
    // 0x800D65FC: ori         $at, $zero, 0xA8C0
    ctx->r1 = 0 | 0XA8C0;
    // 0x800D6600: addiu       $t3, $zero, 0x11
    ctx->r11 = ADD32(0, 0X11);
    // 0x800D6604: sltu        $at, $t2, $at
    ctx->r1 = ctx->r10 < ctx->r1 ? 1 : 0;
    // 0x800D6608: beql        $at, $zero, L_800D661C
    if (ctx->r1 == 0) {
        // 0x800D660C: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_800D661C;
    }
    goto skip_0;
    // 0x800D660C: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    skip_0:
    // 0x800D6610: jr          $ra
    // 0x800D6614: sb          $t3, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r11;
    return;
    // 0x800D6614: sb          $t3, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r11;
L_800D6618:
    // 0x800D6618: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
L_800D661C:
    // 0x800D661C: bne         $t4, $zero, L_800D6628
    if (ctx->r12 != 0) {
        // 0x800D6620: addiu       $t5, $zero, 0x10
        ctx->r13 = ADD32(0, 0X10);
            goto L_800D6628;
    }
    // 0x800D6620: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x800D6624: sb          $t5, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r13;
L_800D6628:
    // 0x800D6628: jr          $ra
    // 0x800D662C: nop

    return;
    // 0x800D662C: nop

;}
RECOMP_FUNC void func_80017EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80017EC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017EC8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80017ECC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80017ED0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80017ED4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80017ED8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80017EDC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80017EE0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80017EE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80017EE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80017EEC: lw          $s5, 0x74($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X74);
    // 0x80017EF0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80017EF4: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80017EF8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80017EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017F00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80017F04: jal         0x8001663C
    // 0x80017F08: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_8001663C(rdram, ctx);
        goto after_0;
    // 0x80017F08: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x80017F0C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80017F10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017F14: lui         $s6, 0xDE00
    ctx->r22 = S32(0XDE00 << 16);
    // 0x80017F18: addiu       $t6, $s1, 0x8
    ctx->r14 = ADD32(ctx->r17, 0X8);
    // 0x80017F1C: sw          $t6, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r14;
    // 0x80017F20: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
    // 0x80017F24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80017F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80017F2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80017F30: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80017F34: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80017F38: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80017F3C: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80017F40: jal         0x80016EDC
    // 0x80017F44: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_1;
    // 0x80017F44: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    after_1:
    // 0x80017F48: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80017F4C: lui         $t2, 0xDF00
    ctx->r10 = S32(0XDF00 << 16);
    // 0x80017F50: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80017F54: addiu       $t1, $s1, 0x8
    ctx->r9 = ADD32(ctx->r17, 0X8);
    // 0x80017F58: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80017F5C: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80017F60: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80017F64: lw          $v1, 0x72C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72C0);
    // 0x80017F68: lui         $t3, 0xDE01
    ctx->r11 = S32(0XDE01 << 16);
    // 0x80017F6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80017F70: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80017F74: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80017F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017F7C: jal         0x8001783C
    // 0x80017F80: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    gcRunFuncCamera(rdram, ctx);
        goto after_2;
    // 0x80017F80: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    after_2:
    // 0x80017F84: lw          $t5, 0x80($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X80);
    // 0x80017F88: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80017F8C: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    // 0x80017F90: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80017F94: beq         $t6, $zero, L_80017FA4
    if (ctx->r14 == 0) {
        // 0x80017F98: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80017FA4;
    }
    // 0x80017F98: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80017F9C: jal         0x80016338
    // 0x80017FA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80016338(rdram, ctx);
        goto after_3;
    // 0x80017FA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_80017FA4:
    // 0x80017FA4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80017FA8: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80017FAC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80017FB0: addiu       $v0, $v0, 0x72C0
    ctx->r2 = ADD32(ctx->r2, 0X72C0);
    // 0x80017FB4: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    // 0x80017FB8: addiu       $s1, $s1, 0x65B4
    ctx->r17 = ADD32(ctx->r17, 0X65B4);
L_80017FBC:
    // 0x80017FBC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80017FC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80017FC4: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x80017FC8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80017FCC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80017FD0: sw          $t8, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r24;
    // 0x80017FD4: bne         $at, $zero, L_80017FBC
    if (ctx->r1 != 0) {
        // 0x80017FD8: sw          $t8, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r24;
            goto L_80017FBC;
    }
    // 0x80017FD8: sw          $t8, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r24;
    // 0x80017FDC: lw          $t0, 0x80($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X80);
    // 0x80017FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80017FE4: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80017FE8: beq         $t1, $zero, L_80017FF8
    if (ctx->r9 == 0) {
        // 0x80017FEC: nop
    
            goto L_80017FF8;
    }
    // 0x80017FEC: nop

    // 0x80017FF0: b           L_80017FF8
    // 0x80017FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80017FF8;
    // 0x80017FF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80017FF8:
    // 0x80017FF8: jal         0x80017B80
    // 0x80017FFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_4;
    // 0x80017FFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80018000: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80018004: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80018008: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    // 0x8001800C: addiu       $s1, $s1, 0x65B4
    ctx->r17 = ADD32(ctx->r17, 0X65B4);
    // 0x80018010: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80018014: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80018018: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
L_8001801C:
    // 0x8001801C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80018020: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80018024: addiu       $v0, $v1, -0x8
    ctx->r2 = ADD32(ctx->r3, -0X8);
    // 0x80018028: bne         $v1, $s0, L_8001803C
    if (ctx->r3 != ctx->r16) {
        // 0x8001802C: addiu       $t3, $s0, 0x8
        ctx->r11 = ADD32(ctx->r16, 0X8);
            goto L_8001803C;
    }
    // 0x8001802C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80018030: addiu       $t2, $s0, -0x8
    ctx->r10 = ADD32(ctx->r16, -0X8);
    // 0x80018034: b           L_800180C4
    // 0x80018038: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
        goto L_800180C4;
    // 0x80018038: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
L_8001803C:
    // 0x8001803C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80018040: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80018044: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80018048: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8001804C: bne         $s3, $fp, L_80018060
    if (ctx->r19 != ctx->r30) {
        // 0x80018050: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_80018060;
    }
    // 0x80018050: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80018054: lw          $t5, 0x80($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X80);
    // 0x80018058: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8001805C: bne         $t6, $zero, L_80018070
    if (ctx->r14 != 0) {
        // 0x80018060: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80018070;
    }
L_80018060:
    // 0x80018060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80018064: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80018068: jal         0x80016338
    // 0x8001806C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80016338(rdram, ctx);
        goto after_5;
    // 0x8001806C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
L_80018070:
    // 0x80018070: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80018074: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80018078: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001807C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80018080: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80018084: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80018088: lw          $t8, 0x72C0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72C0);
    // 0x8001808C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80018090: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80018094: jal         0x8001783C
    // 0x80018098: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    gcRunFuncCamera(rdram, ctx);
        goto after_6;
    // 0x80018098: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    after_6:
    // 0x8001809C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800180A0: lui         $t1, 0xDF00
    ctx->r9 = S32(0XDF00 << 16);
    // 0x800180A4: lui         $t2, 0xDE01
    ctx->r10 = S32(0XDE01 << 16);
    // 0x800180A8: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x800180AC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800180B0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800180B4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800180B8: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x800180BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800180C0: sw          $t3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r11;
L_800180C4:
    // 0x800180C4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800180C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800180CC: bne         $s3, $s7, L_8001801C
    if (ctx->r19 != ctx->r23) {
        // 0x800180D0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001801C;
    }
    // 0x800180D0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800180D4: jal         0x80017CC8
    // 0x800180D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80017CC8(rdram, ctx);
        goto after_7;
    // 0x800180D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x800180DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800180E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800180E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800180E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800180EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800180F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800180F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800180F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800180FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80018100: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80018104: jr          $ra
    // 0x80018108: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80018108: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}

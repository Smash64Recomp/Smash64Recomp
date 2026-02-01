#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonDeadUpFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C80C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C814: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8013C818: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013C81C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013C820: lw          $t6, 0x180($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X180);
    // 0x8013C824: addiu       $a1, $a1, 0x1300
    ctx->r5 = ADD32(ctx->r5, 0X1300);
    // 0x8013C828: bne         $v1, $t6, L_8013C868
    if (ctx->r3 != ctx->r14) {
        // 0x8013C82C: nop
    
            goto L_8013C868;
    }
    // 0x8013C82C: nop

    // 0x8013C830: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8013C834: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8013C838: lh          $t9, 0x76($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X76);
    // 0x8013C83C: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8013C840: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8013C844: nop

    // 0x8013C848: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013C84C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8013C850: nop

    // 0x8013C854: bc1fl       L_8013C874
    if (!c1cs) {
        // 0x8013C858: lw          $v0, 0xB18($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XB18);
            goto L_8013C874;
    }
    goto skip_0;
    // 0x8013C858: lw          $v0, 0xB18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB18);
    skip_0:
    // 0x8013C85C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8013C860: b           L_8013C870
    // 0x8013C864: swc1        $f10, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f10.u32l;
        goto L_8013C870;
    // 0x8013C864: swc1        $f10, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f10.u32l;
L_8013C868:
    // 0x8013C868: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013C86C: addiu       $a1, $a1, 0x1300
    ctx->r5 = ADD32(ctx->r5, 0X1300);
L_8013C870:
    // 0x8013C870: lw          $v0, 0xB18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB18);
L_8013C874:
    // 0x8013C874: beq         $v0, $zero, L_8013C884
    if (ctx->r2 == 0) {
        // 0x8013C878: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8013C884;
    }
    // 0x8013C878: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8013C87C: sw          $t0, 0xB18($a2)
    MEM_W(0XB18, ctx->r6) = ctx->r8;
    // 0x8013C880: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8013C884:
    // 0x8013C884: bnel        $v0, $zero, L_8013CAA0
    if (ctx->r2 != 0) {
        // 0x8013C888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013CAA0;
    }
    goto skip_1;
    // 0x8013C888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013C88C: lw          $v0, 0x180($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X180);
    // 0x8013C890: beql        $v0, $zero, L_8013C8B4
    if (ctx->r2 == 0) {
        // 0x8013C894: lw          $t1, 0x0($a1)
        ctx->r9 = MEM_W(ctx->r5, 0X0);
            goto L_8013C8B4;
    }
    goto skip_2;
    // 0x8013C894: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x8013C898: beq         $v0, $v1, L_8013C99C
    if (ctx->r2 == ctx->r3) {
        // 0x8013C89C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013C99C;
    }
    // 0x8013C89C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C8A0: beq         $v0, $at, L_8013CA94
    if (ctx->r2 == ctx->r1) {
        // 0x8013C8A4: nop
    
            goto L_8013CA94;
    }
    // 0x8013C8A4: nop

    // 0x8013C8A8: b           L_8013CAA0
    // 0x8013C8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013CAA0;
    // 0x8013C8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C8B0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
L_8013C8B4:
    // 0x8013C8B4: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x8013C8B8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8013C8BC: lh          $t2, 0x6E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X6E);
    // 0x8013C8C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013C8C4: lwc1        $f6, 0x20($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8013C8C8: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8013C8CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C8D0: lwc1        $f2, -0x3FC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3FC8);
    // 0x8013C8D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013C8D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8013C8DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013C8E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013C8E4: addiu       $v1, $v1, 0x1460
    ctx->r3 = ADD32(ctx->r3, 0X1460);
    // 0x8013C8E8: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8013C8EC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8013C8F0: swc1        $f10, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f10.u32l;
    // 0x8013C8F4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8013C8F8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8013C8FC: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x8013C900: lwc1        $f16, 0x44($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8013C904: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8013C908: swc1        $f18, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f18.u32l;
    // 0x8013C90C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013C910: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8013C914: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8013C918: nop

    // 0x8013C91C: bc1fl       L_8013C930
    if (!c1cs) {
        // 0x8013C920: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_8013C930;
    }
    goto skip_3;
    // 0x8013C920: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x8013C924: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8013C928: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013C92C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_8013C930:
    // 0x8013C930: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8013C934: lwc1        $f4, 0x3C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x8013C938: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8013C93C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8013C940: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8013C944: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8013C948: lwc1        $f8, 0x40($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8013C94C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8013C950: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
    // 0x8013C954: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8013C958: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013C95C: lh          $t3, 0x74($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X74);
    // 0x8013C960: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013C964: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8013C968: nop

    // 0x8013C96C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013C970: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8013C974: nop

    // 0x8013C978: bc1fl       L_8013C988
    if (!c1cs) {
        // 0x8013C97C: lw          $t5, 0x180($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X180);
            goto L_8013C988;
    }
    goto skip_4;
    // 0x8013C97C: lw          $t5, 0x180($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X180);
    skip_4:
    // 0x8013C980: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8013C984: lw          $t5, 0x180($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X180);
L_8013C988:
    // 0x8013C988: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8013C98C: sw          $t4, 0xB18($a2)
    MEM_W(0XB18, ctx->r6) = ctx->r12;
    // 0x8013C990: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8013C994: b           L_8013CA9C
    // 0x8013C998: sw          $t6, 0x180($a2)
    MEM_W(0X180, ctx->r6) = ctx->r14;
        goto L_8013CA9C;
    // 0x8013C998: sw          $t6, 0x180($a2)
    MEM_W(0X180, ctx->r6) = ctx->r14;
L_8013C99C:
    // 0x8013C99C: jal         0x800D9444
    // 0x8013C9A0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_0;
    // 0x8013C9A0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013C9A4: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8013C9A8: jal         0x80115BF0
    // 0x8013C9AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_1;
    // 0x8013C9AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8013C9B0: jal         0x801008F4
    // 0x8013C9B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8013C9B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8013C9B8: jal         0x8013BC8C
    // 0x8013C9BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftCommonDeadUpdateRumble(rdram, ctx);
        goto after_3;
    // 0x8013C9BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8013C9C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C9C4: lbu         $t8, 0x18E($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18E);
    // 0x8013C9C8: lbu         $t1, 0x18D($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X18D);
    // 0x8013C9CC: lbu         $t4, 0x191($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X191);
    // 0x8013C9D0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8013C9D4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013C9D8: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8013C9DC: sb          $t9, 0x18E($a0)
    MEM_B(0X18E, ctx->r4) = ctx->r25;
    // 0x8013C9E0: sb          $t2, 0x18D($a0)
    MEM_B(0X18D, ctx->r4) = ctx->r10;
    // 0x8013C9E4: jal         0x8013BD64
    // 0x8013C9E8: sb          $t5, 0x191($a0)
    MEM_B(0X191, ctx->r4) = ctx->r13;
    ftCommonDeadUpdateScore(rdram, ctx);
        goto after_4;
    // 0x8013C9E8: sb          $t5, 0x191($a0)
    MEM_B(0X191, ctx->r4) = ctx->r13;
    after_4:
    // 0x8013C9EC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013C9F0: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8013C9F4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C9F8: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    // 0x8013C9FC: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8013CA00: bne         $at, $zero, L_8013CA0C
    if (ctx->r1 != 0) {
        // 0x8013CA04: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013CA0C;
    }
    // 0x8013CA04: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013CA08: bne         $at, $zero, L_8013CA20
    if (ctx->r1 != 0) {
        // 0x8013CA0C: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013CA20;
    }
L_8013CA0C:
    // 0x8013CA0C: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013CA10: bne         $at, $zero, L_8013CA28
    if (ctx->r1 != 0) {
        // 0x8013CA14: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_8013CA28;
    }
    // 0x8013CA14: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8013CA18: beql        $at, $zero, L_8013CA2C
    if (ctx->r1 == 0) {
        // 0x8013CA1C: addiu       $v0, $zero, 0x9A
        ctx->r2 = ADD32(0, 0X9A);
            goto L_8013CA2C;
    }
    goto skip_5;
    // 0x8013CA1C: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
    skip_5:
L_8013CA20:
    // 0x8013CA20: b           L_8013CA2C
    // 0x8013CA24: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
        goto L_8013CA2C;
    // 0x8013CA24: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
L_8013CA28:
    // 0x8013CA28: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
L_8013CA2C:
    // 0x8013CA2C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8013CA30: jal         0x8013BC60
    // 0x8013CA34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_5;
    // 0x8013CA34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_5:
    // 0x8013CA38: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013CA3C: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013CA40: lw          $v0, 0x9C8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9C8);
    // 0x8013CA44: lhu         $a0, 0xB4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB4);
    // 0x8013CA48: beql        $a0, $at, L_8013CA64
    if (ctx->r4 == ctx->r1) {
        // 0x8013CA4C: lhu         $a0, 0xB6($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0XB6);
            goto L_8013CA64;
    }
    goto skip_6;
    // 0x8013CA4C: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
    skip_6:
    // 0x8013CA50: jal         0x8013BC60
    // 0x8013CA54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_6;
    // 0x8013CA54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_6:
    // 0x8013CA58: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013CA5C: lw          $v0, 0x9C8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9C8);
    // 0x8013CA60: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
L_8013CA64:
    // 0x8013CA64: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013CA68: beql        $a0, $at, L_8013CA80
    if (ctx->r4 == ctx->r1) {
        // 0x8013CA6C: lw          $t8, 0x180($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X180);
            goto L_8013CA80;
    }
    goto skip_7;
    // 0x8013CA6C: lw          $t8, 0x180($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X180);
    skip_7:
    // 0x8013CA70: jal         0x8013BC60
    // 0x8013CA74: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_7;
    // 0x8013CA74: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_7:
    // 0x8013CA78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013CA7C: lw          $t8, 0x180($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X180);
L_8013CA80:
    // 0x8013CA80: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x8013CA84: sw          $t7, 0xB18($a2)
    MEM_W(0XB18, ctx->r6) = ctx->r15;
    // 0x8013CA88: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8013CA8C: b           L_8013CA9C
    // 0x8013CA90: sw          $t9, 0x180($a2)
    MEM_W(0X180, ctx->r6) = ctx->r25;
        goto L_8013CA9C;
    // 0x8013CA90: sw          $t9, 0x180($a2)
    MEM_W(0X180, ctx->r6) = ctx->r25;
L_8013CA94:
    // 0x8013CA94: jal         0x8013BF94
    // 0x8013CA98: nop

    ftCommonDeadCheckRebirth(rdram, ctx);
        goto after_8;
    // 0x8013CA98: nop

    after_8:
L_8013CA9C:
    // 0x8013CA9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013CAA0:
    // 0x8013CAA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013CAA4: jr          $ra
    // 0x8013CAA8: nop

    return;
    // 0x8013CAA8: nop

;}
RECOMP_FUNC void mnModeSelectMakeVSMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131C58: jal         0x80009968
    // 0x80131C5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C64: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131C68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131C6C: sw          $v0, 0x2C90($at)
    MEM_W(0X2C90, ctx->r1) = ctx->r2;
    // 0x80131C70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131C74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131C78: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131C7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131C84: jal         0x80009DF4
    // 0x80131C88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131C88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131C8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131C90: lw          $t7, 0x2C88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C88);
    // 0x80131C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131C98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C9C: bne         $t7, $at, L_80131D08
    if (ctx->r15 != ctx->r1) {
        // 0x80131CA0: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80131D08;
    }
    // 0x80131CA0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131CA4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131CA8: lw          $t8, 0x2D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D6C);
    // 0x80131CAC: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131CB0: addiu       $t9, $t9, 0x2520
    ctx->r25 = ADD32(ctx->r25, 0X2520);
    // 0x80131CB4: jal         0x800CCFDC
    // 0x80131CB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131CB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131CBC: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CC0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80131CC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131CC8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80131CCC: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80131CD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131CD4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131CD8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131CDC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80131CE0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131CE4: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131CE8: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131CEC: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131CF0: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131CF4: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131CF8: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131CFC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131D00: b           L_80131D58
    // 0x80131D04: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80131D58;
    // 0x80131D04: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80131D08:
    // 0x80131D08: lw          $t4, 0x2D6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D6C);
    // 0x80131D0C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131D10: addiu       $t5, $t5, 0x6708
    ctx->r13 = ADD32(ctx->r13, 0X6708);
    // 0x80131D14: jal         0x800CCFDC
    // 0x80131D18: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131D18: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80131D1C: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131D20: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80131D24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131D28: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80131D2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131D30: addiu       $v1, $zero, 0x96
    ctx->r3 = ADD32(0, 0X96);
    // 0x80131D34: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131D38: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131D3C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131D40: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131D44: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131D48: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131D4C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131D50: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131D54: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80131D58:
    // 0x80131D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D60: jr          $ra
    // 0x80131D64: nop

    return;
    // 0x80131D64: nop

;}
RECOMP_FUNC void itLizardonAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F8EC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F8F0: addiu       $a1, $a1, -0x529C
    ctx->r5 = ADD32(ctx->r5, -0X529C);
    // 0x8017F8F4: jal         0x80172EC8
    // 0x8017F8F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017F8F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8017F8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F904: jr          $ra
    // 0x8017F908: nop

    return;
    // 0x8017F908: nop

;}
RECOMP_FUNC void mpCollisionGetMapObjPositionID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC894: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FC898: addiu       $v1, $v1, 0x1380
    ctx->r3 = ADD32(ctx->r3, 0X1380);
    // 0x800FC89C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800FC8A0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800FC8A4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800FC8A8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800FC8AC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800FC8B0: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800FC8B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800FC8B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800FC8BC: nop

    // 0x800FC8C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FC8C4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800FC8C8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800FC8CC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800FC8D0: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x800FC8D4: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x800FC8D8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800FC8DC: nop

    // 0x800FC8E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FC8E4: jr          $ra
    // 0x800FC8E8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    return;
    // 0x800FC8E8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
;}
RECOMP_FUNC void efManagerDamageSpawnMDustProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100258: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010025C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100260: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80100264: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80100268: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8010026C: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x80100270: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80100274: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100278: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x8010027C: addiu       $a0, $a0, -0x1F9C
    ctx->r4 = ADD32(ctx->r4, -0X1F9C);
    // 0x80100280: bgez        $v1, L_80100294
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80100284: andi        $t7, $v1, 0x3
        ctx->r15 = ctx->r3 & 0X3;
            goto L_80100294;
    }
    // 0x80100284: andi        $t7, $v1, 0x3
    ctx->r15 = ctx->r3 & 0X3;
    // 0x80100288: beq         $t7, $zero, L_80100294
    if (ctx->r15 == 0) {
        // 0x8010028C: nop
    
            goto L_80100294;
    }
    // 0x8010028C: nop

    // 0x80100290: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_80100294:
    // 0x80100294: bnel        $t7, $zero, L_801003A0
    if (ctx->r15 != 0) {
        // 0x80100298: lw          $t5, 0x18($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X18);
            goto L_801003A0;
    }
    goto skip_0;
    // 0x80100298: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    skip_0:
    // 0x8010029C: jal         0x800FDAFC
    // 0x801002A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x801002A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x801002A4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x801002A8: beq         $v0, $zero, L_8010039C
    if (ctx->r2 == 0) {
        // 0x801002AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010039C;
    }
    // 0x801002AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801002B0: lw          $v0, 0x74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74);
    // 0x801002B4: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x801002B8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801002BC: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x801002C0: lw          $t8, 0x20($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X20);
    // 0x801002C4: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x801002C8: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801002CC: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801002D0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x801002D4: jal         0x80018948
    // 0x801002D8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x801002D8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x801002DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801002E0: lwc1        $f4, 0x9BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9BC);
    // 0x801002E4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x801002E8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x801002EC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801002F0: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x801002F4: bgez        $v1, L_80100304
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801002F8: sra         $t0, $v1, 2
        ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
            goto L_80100304;
    }
    // 0x801002F8: sra         $t0, $v1, 2
    ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
    // 0x801002FC: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
    // 0x80100300: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
L_80100304:
    // 0x80100304: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80100308: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8010030C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100310: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80100314: lwc1        $f2, -0x216C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X216C);
    // 0x80100318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010031C: lwc1        $f8, 0x9C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9C0);
    // 0x80100320: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80100324: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80100328: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8010032C: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80100330: jal         0x80035CD0
    // 0x80100334: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80100334: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80100338: lw          $t3, 0x28($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X28);
    // 0x8010033C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80100340: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80100344: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80100348: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010034C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80100350: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80100354: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80100358: jal         0x800303F0
    // 0x8010035C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8010035C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80100360: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100364: lwc1        $f12, 0x9C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X9C4);
    // 0x80100368: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8010036C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80100370: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80100374: addiu       $t4, $zero, 0xFA
    ctx->r12 = ADD32(0, 0XFA);
    // 0x80100378: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8010037C: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80100380: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x80100384: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80100388: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8010038C: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x80100390: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80100394: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80100398: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_8010039C:
    // 0x8010039C: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
L_801003A0:
    // 0x801003A0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801003A4: bgez        $t6, L_801003BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801003A8: sw          $t6, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r14;
            goto L_801003BC;
    }
    // 0x801003A8: sw          $t6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r14;
    // 0x801003AC: jal         0x800FD4F8
    // 0x801003B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_4;
    // 0x801003B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801003B4: jal         0x80009A84
    // 0x801003B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x801003B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
L_801003BC:
    // 0x801003BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801003C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801003C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801003C8: jr          $ra
    // 0x801003CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801003CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void wpLinkBoomerangSetReturnVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CDC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016CDCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016CDD0: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016CDD4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8016CDD8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CDDC: lbu         $t6, 0x2A2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2A2);
    // 0x8016CDE0: sw          $t8, 0x104($a2)
    MEM_W(0X104, ctx->r6) = ctx->r24;
    // 0x8016CDE4: lwc1        $f4, 0x2A4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2A4);
    // 0x8016CDE8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8016CDEC: sb          $t7, 0x2A2($a2)
    MEM_B(0X2A2, ctx->r6) = ctx->r15;
    // 0x8016CDF0: lwc1        $f6, -0x3488($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3488);
    // 0x8016CDF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8016CDF8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8016CDFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016CE00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CE04: addiu       $t1, $zero, 0x8C
    ctx->r9 = ADD32(0, 0X8C);
    // 0x8016CE08: swc1        $f8, 0x2A4($a2)
    MEM_W(0X2A4, ctx->r6) = ctx->f8.u32l;
    // 0x8016CE0C: lwc1        $f0, 0x2A4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X2A4);
    // 0x8016CE10: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8016CE14: nop

    // 0x8016CE18: bc1fl       L_8016CE30
    if (!c1cs) {
        // 0x8016CE1C: lw          $t9, 0x18($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X18);
            goto L_8016CE30;
    }
    goto skip_0;
    // 0x8016CE1C: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x8016CE20: lwc1        $f16, -0x3484($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3484);
    // 0x8016CE24: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8016CE28: swc1        $f18, 0x2A4($a2)
    MEM_W(0X2A4, ctx->r6) = ctx->f18.u32l;
    // 0x8016CE2C: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
L_8016CE30:
    // 0x8016CE30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016CE34: sb          $t1, 0x2A0($a2)
    MEM_B(0X2A0, ctx->r6) = ctx->r9;
    // 0x8016CE38: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8016CE3C: bne         $a1, $at, L_8016CE54
    if (ctx->r5 != ctx->r1) {
        // 0x8016CE40: sw          $t0, 0x18($a2)
        MEM_W(0X18, ctx->r6) = ctx->r8;
            goto L_8016CE54;
    }
    // 0x8016CE40: sw          $t0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r8;
    // 0x8016CE44: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CE48: lwc1        $f4, -0x3480($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3480);
    // 0x8016CE4C: b           L_8016CE60
    // 0x8016CE50: swc1        $f4, 0x2A8($a2)
    MEM_W(0X2A8, ctx->r6) = ctx->f4.u32l;
        goto L_8016CE60;
    // 0x8016CE50: swc1        $f4, 0x2A8($a2)
    MEM_W(0X2A8, ctx->r6) = ctx->f4.u32l;
L_8016CE54:
    // 0x8016CE54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CE58: lwc1        $f6, -0x347C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X347C);
    // 0x8016CE5C: swc1        $f6, 0x2A8($a2)
    MEM_W(0X2A8, ctx->r6) = ctx->f6.u32l;
L_8016CE60:
    // 0x8016CE60: lw          $t3, 0x74($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X74);
    // 0x8016CE64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8016CE68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8016CE6C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8016CE70: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
    // 0x8016CE74: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8016CE78: jal         0x80167F08
    // 0x8016CE7C: sb          $t2, 0x54($t5)
    MEM_B(0X54, ctx->r13) = ctx->r10;
    wpMainPlayFGM(rdram, ctx);
        goto after_0;
    // 0x8016CE7C: sb          $t2, 0x54($t5)
    MEM_B(0X54, ctx->r13) = ctx->r10;
    after_0:
    // 0x8016CE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016CE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016CE88: jr          $ra
    // 0x8016CE8C: nop

    return;
    // 0x8016CE8C: nop

;}
RECOMP_FUNC void ftCommonItemShootSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147844: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80147848: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014784C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80147850: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80147854: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80147858: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8014785C: lw          $t6, 0x84C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84C);
    // 0x80147860: addiu       $t7, $zero, 0x8E
    ctx->r15 = ADD32(0, 0X8E);
    // 0x80147864: addiu       $t8, $t8, 0x6FD4
    ctx->r24 = ADD32(ctx->r24, 0X6FD4);
    // 0x80147868: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8014786C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80147870: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80147874: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80147878: beq         $v1, $at, L_80147890
    if (ctx->r3 == ctx->r1) {
        // 0x8014787C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80147890;
    }
    // 0x8014787C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80147880: beq         $v1, $at, L_8014789C
    if (ctx->r3 == ctx->r1) {
        // 0x80147884: addiu       $t9, $zero, 0x90
        ctx->r25 = ADD32(0, 0X90);
            goto L_8014789C;
    }
    // 0x80147884: addiu       $t9, $zero, 0x90
    ctx->r25 = ADD32(0, 0X90);
    // 0x80147888: b           L_801478B0
    // 0x8014788C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
        goto L_801478B0;
    // 0x8014788C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_80147890:
    // 0x80147890: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80147894: b           L_801478AC
    // 0x80147898: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_801478AC;
    // 0x80147898: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8014789C:
    // 0x8014789C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801478A0: addiu       $t0, $t0, 0x7434
    ctx->r8 = ADD32(ctx->r8, 0X7434);
    // 0x801478A4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801478A8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_801478AC:
    // 0x801478AC: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_801478B0:
    // 0x801478B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801478B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801478B8: jal         0x800E6F24
    // 0x801478BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801478BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x801478C0: jal         0x800E0830
    // 0x801478C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801478C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x801478C8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801478CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801478D0: jal         0x80147824
    // 0x801478D4: sw          $t1, 0x9D8($s0)
    MEM_W(0X9D8, ctx->r16) = ctx->r9;
    ftCommonFireFlowerShootInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801478D4: sw          $t1, 0x9D8($s0)
    MEM_W(0X9D8, ctx->r16) = ctx->r9;
    after_2:
    // 0x801478D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801478DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801478E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801478E4: jr          $ra
    // 0x801478E8: nop

    return;
    // 0x801478E8: nop

;}
RECOMP_FUNC void efManagerSparkleWhiteMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100480: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100484: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80100488: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010048C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80100490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100494: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100498: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8010049C: jal         0x800CE9E8
    // 0x801004A0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801004A0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x801004A4: beq         $v0, $zero, L_8010050C
    if (ctx->r2 == 0) {
        // 0x801004A8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010050C;
    }
    // 0x801004A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801004AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801004B0: jal         0x800CE1DC
    // 0x801004B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801004B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801004B8: beq         $v0, $zero, L_80100500
    if (ctx->r2 == 0) {
        // 0x801004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80100500;
    }
    // 0x801004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801004C0: jal         0x800CEA14
    // 0x801004C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x801004C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801004C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801004CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801004D0: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x801004D4: bnel        $t6, $zero, L_801004E8
    if (ctx->r14 != 0) {
        // 0x801004D8: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_801004E8;
    }
    goto skip_0;
    // 0x801004D8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x801004DC: b           L_80100510
    // 0x801004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100510;
    // 0x801004E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801004E4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_801004E8:
    // 0x801004E8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801004EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801004F0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801004F4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801004F8: b           L_8010050C
    // 0x801004FC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_8010050C;
    // 0x801004FC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80100500:
    // 0x80100500: jal         0x800CEA40
    // 0x80100504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80100504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80100508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8010050C:
    // 0x8010050C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80100510:
    // 0x80100510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010051C: jr          $ra
    // 0x80100520: nop

    return;
    // 0x80100520: nop

;}
RECOMP_FUNC void itHammerWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017616C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176174: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80176178: jal         0x801735A0
    // 0x8017617C: addiu       $a1, $a1, 0x61F8
    ctx->r5 = ADD32(ctx->r5, 0X61F8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017617C: addiu       $a1, $a1, 0x61F8
    ctx->r5 = ADD32(ctx->r5, 0X61F8);
    after_0:
    // 0x80176180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017618C: jr          $ra
    // 0x80176190: nop

    return;
    // 0x80176190: nop

;}
RECOMP_FUNC void SCStaffrollNameUpdateAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133618: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013361C: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x80133620: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80133624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013362C: bne         $v0, $zero, L_80133648
    if (ctx->r2 != 0) {
        // 0x80133630: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80133648;
    }
    // 0x80133630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133634: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80133638: jal         0x80004980
    // 0x8013363C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x8013363C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80133640: b           L_80133654
    // 0x80133644: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80133654;
    // 0x80133644: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133648:
    // 0x80133648: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8013364C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80133650: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80133654:
    // 0x80133654: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133658: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x8013365C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80133660: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x80133664: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80133668: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8013366C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80133670: sw          $v1, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r3;
    // 0x80133674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013367C: jr          $ra
    // 0x80133680: nop

    return;
    // 0x80133680: nop

;}
RECOMP_FUNC void itMBallFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C7FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017C808: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017C80C: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017C810: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x8017C814: jal         0x80173F78
    // 0x8017C818: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017C818: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x8017C81C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C820: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017C824: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017C828: jal         0x80172EC8
    // 0x8017C82C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017C82C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017C830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C838: jr          $ra
    // 0x8017C83C: nop

    return;
    // 0x8017C83C: nop

;}
RECOMP_FUNC void mnPlayersVSInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AEC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013AECC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013AED0: addiu       $v0, $v0, -0x4234
    ctx->r2 = ADD32(ctx->r2, -0X4234);
    // 0x8013AED4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013AED8: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8013AEDC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8013AEE0: addiu       $t7, $zero, 0x4650
    ctx->r15 = ADD32(0, 0X4650);
    // 0x8013AEE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AEE8: addiu       $s2, $s2, 0x4D08
    ctx->r18 = ADD32(ctx->r18, 0X4D08);
    // 0x8013AEEC: sw          $t7, -0x4230($at)
    MEM_W(-0X4230, ctx->r1) = ctx->r15;
    // 0x8013AEF0: lbu         $t8, 0x6($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X6);
    // 0x8013AEF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AEF8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8013AEFC: sw          $t8, -0x4284($at)
    MEM_W(-0X4284, ctx->r1) = ctx->r24;
    // 0x8013AF00: lbu         $t9, 0x7($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X7);
    // 0x8013AF04: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AF08: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8013AF0C: sw          $t9, -0x4280($at)
    MEM_W(-0X4280, ctx->r1) = ctx->r25;
    // 0x8013AF10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AF14: sw          $zero, -0x425C($at)
    MEM_W(-0X425C, ctx->r1) = 0;
    // 0x8013AF18: lbu         $t0, 0x2($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X2);
    // 0x8013AF1C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AF20: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8013AF24: sw          $t0, -0x4258($at)
    MEM_W(-0X4258, ctx->r1) = ctx->r8;
    // 0x8013AF28: lbu         $t1, 0x3($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X3);
    // 0x8013AF2C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AF30: addiu       $s3, $s3, -0x4238
    ctx->r19 = ADD32(ctx->r19, -0X4238);
    // 0x8013AF34: sw          $t1, -0x4254($at)
    MEM_W(-0X4254, ctx->r1) = ctx->r9;
    // 0x8013AF38: lbu         $t2, 0x10($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X10);
    // 0x8013AF3C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8013AF40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013AF44: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8013AF48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8013AF4C: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x8013AF50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013AF54: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x8013AF58: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
L_8013AF5C:
    // 0x8013AF5C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8013AF60: beq         $t3, $zero, L_8013AF78
    if (ctx->r11 == 0) {
        // 0x8013AF64: nop
    
            goto L_8013AF78;
    }
    // 0x8013AF64: nop

    // 0x8013AF68: jal         0x8013ADE0
    // 0x8013AF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSResetPlayer(rdram, ctx);
        goto after_0;
    // 0x8013AF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013AF70: b           L_8013AF80
    // 0x8013AF74: sb          $zero, 0x10($s2)
    MEM_B(0X10, ctx->r18) = 0;
        goto L_8013AF80;
    // 0x8013AF74: sb          $zero, 0x10($s2)
    MEM_B(0X10, ctx->r18) = 0;
L_8013AF78:
    // 0x8013AF78: jal         0x8013AC7C
    // 0x8013AF7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSInitPlayer(rdram, ctx);
        goto after_1;
    // 0x8013AF7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8013AF80:
    // 0x8013AF80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013AF84: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x8013AF88: bne         $s0, $s4, L_8013AF5C
    if (ctx->r16 != ctx->r20) {
        // 0x8013AF8C: sw          $zero, -0x5C($s1)
        MEM_W(-0X5C, ctx->r17) = 0;
            goto L_8013AF5C;
    }
    // 0x8013AF8C: sw          $zero, -0x5C($s1)
    MEM_W(-0X5C, ctx->r17) = 0;
    // 0x8013AF90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8013AF94: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8013AF98: lhu         $t4, 0x4938($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X4938);
    // 0x8013AF9C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AFA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013AFA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013AFA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8013AFAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8013AFB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8013AFB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013AFB8: jr          $ra
    // 0x8013AFBC: sh          $t4, -0x4244($at)
    MEM_H(-0X4244, ctx->r1) = ctx->r12;
    return;
    // 0x8013AFBC: sh          $t4, -0x4244($at)
    MEM_H(-0X4244, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void mpCommonUpdateFighterSlopeContour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE150: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800DE154: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DE158: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DE15C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DE160: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800DE164: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800DE168: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x800DE16C: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x800DE170: bnel        $t7, $zero, L_800DE314
    if (ctx->r15 != 0) {
        // 0x800DE174: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE314;
    }
    goto skip_0;
    // 0x800DE174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800DE178: lw          $v0, 0xEC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XEC);
    // 0x800DE17C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DE180: beq         $v0, $at, L_800DE310
    if (ctx->r2 == ctx->r1) {
        // 0x800DE184: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_800DE310;
    }
    // 0x800DE184: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800DE188: beql        $v0, $at, L_800DE314
    if (ctx->r2 == ctx->r1) {
        // 0x800DE18C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE314;
    }
    goto skip_1;
    // 0x800DE18C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800DE190: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800DE194: bnel        $t8, $zero, L_800DE314
    if (ctx->r24 != 0) {
        // 0x800DE198: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE314;
    }
    goto skip_2;
    // 0x800DE198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800DE19C: lw          $t9, 0x190($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X190);
    // 0x800DE1A0: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800DE1A4: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800DE1A8: beql        $t1, $zero, L_800DE23C
    if (ctx->r9 == 0) {
        // 0x800DE1AC: lw          $t2, 0x190($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X190);
            goto L_800DE23C;
    }
    goto skip_3;
    // 0x800DE1AC: lw          $t2, 0x190($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X190);
    skip_3:
    // 0x800DE1B0: lw          $t2, 0x2FC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2FC);
    // 0x800DE1B4: lw          $a3, 0x300($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X300);
    // 0x800DE1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DE1BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800DE1C0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800DE1C4: lw          $v0, 0x8E8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8E8);
    // 0x800DE1C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800DE1CC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800DE1D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DE1D4: jal         0x800EBC0C
    // 0x800DE1D8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_ovl2_800EBC0C(rdram, ctx);
        goto after_0;
    // 0x800DE1D8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800DE1DC: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x800DE1E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800DE1E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800DE1E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DE1EC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800DE1F0: jal         0x800DDF74
    // 0x800DE1F4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_ovl2_800DDF74(rdram, ctx);
        goto after_1;
    // 0x800DE1F4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800DE1F8: beql        $v0, $zero, L_800DE23C
    if (ctx->r2 == 0) {
        // 0x800DE1FC: lw          $t2, 0x190($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X190);
            goto L_800DE23C;
    }
    goto skip_4;
    // 0x800DE1FC: lw          $t2, 0x190($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X190);
    skip_4:
    // 0x800DE200: lw          $t6, 0x2FC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2FC);
    // 0x800DE204: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800DE208: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DE20C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800DE210: jal         0x800EE018
    // 0x800DE214: lw          $a0, 0x8E8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8E8);
    func_ovl2_800EE018(rdram, ctx);
        goto after_2;
    // 0x800DE214: lw          $a0, 0x8E8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8E8);
    after_2:
    // 0x800DE218: lw          $t9, 0x2FC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2FC);
    // 0x800DE21C: lw          $a1, 0x300($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X300);
    // 0x800DE220: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800DE224: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800DE228: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800DE22C: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    // 0x800DE230: jal         0x800EBD08
    // 0x800DE234: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_ovl2_800EBD08(rdram, ctx);
        goto after_3;
    // 0x800DE234: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800DE238: lw          $t2, 0x190($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X190);
L_800DE23C:
    // 0x800DE23C: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x800DE240: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800DE244: beql        $t4, $zero, L_800DE2D8
    if (ctx->r12 == 0) {
        // 0x800DE248: lw          $t5, 0x190($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X190);
            goto L_800DE2D8;
    }
    goto skip_5;
    // 0x800DE248: lw          $t5, 0x190($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X190);
    skip_5:
    // 0x800DE24C: lw          $t5, 0x304($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X304);
    // 0x800DE250: lw          $a3, 0x308($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X308);
    // 0x800DE254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DE258: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800DE25C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800DE260: lw          $v0, 0x8E8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8E8);
    // 0x800DE264: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800DE268: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800DE26C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DE270: jal         0x800EBC0C
    // 0x800DE274: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_ovl2_800EBC0C(rdram, ctx);
        goto after_4;
    // 0x800DE274: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800DE278: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x800DE27C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800DE280: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800DE284: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DE288: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800DE28C: jal         0x800DDF74
    // 0x800DE290: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_ovl2_800DDF74(rdram, ctx);
        goto after_5;
    // 0x800DE290: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x800DE294: beql        $v0, $zero, L_800DE2D8
    if (ctx->r2 == 0) {
        // 0x800DE298: lw          $t5, 0x190($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X190);
            goto L_800DE2D8;
    }
    goto skip_6;
    // 0x800DE298: lw          $t5, 0x190($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X190);
    skip_6:
    // 0x800DE29C: lw          $t9, 0x304($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X304);
    // 0x800DE2A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800DE2A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800DE2A8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800DE2AC: jal         0x800EE018
    // 0x800DE2B0: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    func_ovl2_800EE018(rdram, ctx);
        goto after_6;
    // 0x800DE2B0: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    after_6:
    // 0x800DE2B4: lw          $t2, 0x304($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X304);
    // 0x800DE2B8: lw          $a1, 0x308($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X308);
    // 0x800DE2BC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800DE2C0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800DE2C4: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800DE2C8: lw          $a0, 0x8E8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8E8);
    // 0x800DE2CC: jal         0x800EBD08
    // 0x800DE2D0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_ovl2_800EBD08(rdram, ctx);
        goto after_7;
    // 0x800DE2D0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x800DE2D4: lw          $t5, 0x190($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X190);
L_800DE2D8:
    // 0x800DE2D8: srl         $t6, $t5, 29
    ctx->r14 = S32(U32(ctx->r13) >> 29);
    // 0x800DE2DC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800DE2E0: beql        $t7, $zero, L_800DE314
    if (ctx->r15 == 0) {
        // 0x800DE2E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DE314;
    }
    goto skip_7;
    // 0x800DE2E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800DE2E8: lwc1        $f12, 0xF8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800DE2EC: jal         0x8001863C
    // 0x800DE2F0: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    syUtilsArcTan2(rdram, ctx);
        goto after_8;
    // 0x800DE2F0: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    after_8:
    // 0x800DE2F4: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x800DE2F8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800DE2FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800DE300: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x800DE304: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DE308: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800DE30C: swc1        $f8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f8.u32l;
L_800DE310:
    // 0x800DE310: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DE314:
    // 0x800DE314: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE318: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DE31C: jr          $ra
    // 0x800DE320: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800DE320: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnBackupClearMakeUnused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80131B28: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B30: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80131B34: addiu       $t7, $t7, 0x2EF0
    ctx->r15 = ADD32(ctx->r15, 0X2EF0);
    // 0x80131B38: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131B3C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131B40: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80131B44: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131B48: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131B4C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131B50: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131B54: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131B58: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131B5C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131B60: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80131B64: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80131B68: addiu       $t1, $t1, 0x2F08
    ctx->r9 = ADD32(ctx->r9, 0X2F08);
    // 0x80131B6C: addiu       $t4, $t1, 0x30
    ctx->r12 = ADD32(ctx->r9, 0X30);
    // 0x80131B70: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x80131B74: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80131B78: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
L_80131B7C:
    // 0x80131B7C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131B80: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131B84: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80131B88: sw          $t3, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r11;
    // 0x80131B8C: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80131B90: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x80131B94: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80131B98: bne         $t1, $t4, L_80131B7C
    if (ctx->r9 != ctx->r12) {
        // 0x80131B9C: sw          $t3, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r11;
            goto L_80131B7C;
    }
    // 0x80131B9C: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x80131BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131BA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BA8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131BAC: jal         0x80009968
    // 0x80131BB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131BB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131BB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131BBC: sw          $v0, 0x30C4($at)
    MEM_W(0X30C4, ctx->r1) = ctx->r2;
    // 0x80131BC0: jr          $ra
    // 0x80131BC4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80131BC4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mnPlayersVSSetDigitColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133ABC: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80133AC0: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80133AC4: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80133AC8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133ACC: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80133AD0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80133AD4: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80133AD8: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80133ADC: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80133AE0: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80133AE4: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x80133AE8: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80133AEC: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x80133AF0: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x80133AF4: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x80133AF8: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80133AFC: jr          $ra
    // 0x80133B00: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
    return;
    // 0x80133B00: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void alCSPSetChlPriority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025FC8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025FCC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80025FD0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80025FD4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80025FD8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80025FDC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025FE0: sb          $a3, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r7;
    // 0x80025FE4: sb          $t0, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r8;
    // 0x80025FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025FEC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80025FF0: jal         0x80028D70
    // 0x80025FF4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80025FF4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x80025FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026000: jr          $ra
    // 0x80026004: nop

    return;
    // 0x80026004: nop

;}
RECOMP_FUNC void gmRumbleSetPlayerRumbleParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80115534: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80115538: addiu       $t7, $t7, 0x19F0
    ctx->r15 = ADD32(ctx->r15, 0X19F0);
    // 0x8011553C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80115540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115544: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80115548: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8011554C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80115550: jal         0x801153B8
    // 0x80115554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gmRumbleCheckSetEventID(rdram, ctx);
        goto after_0;
    // 0x80115554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80115558: bne         $v0, $zero, L_801155B4
    if (ctx->r2 != 0) {
        // 0x8011555C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801155B4;
    }
    // 0x8011555C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80115560: jal         0x80115458
    // 0x80115564: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    gmRumbleGetEventPriorityRelink(rdram, ctx);
        goto after_1;
    // 0x80115564: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80115568: beq         $v0, $zero, L_801155B4
    if (ctx->r2 == 0) {
        // 0x8011556C: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_801155B4;
    }
    // 0x8011556C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80115570: bne         $v1, $zero, L_80115580
    if (ctx->r3 != 0) {
        // 0x80115574: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_80115580;
    }
    // 0x80115574: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80115578: b           L_80115584
    // 0x8011557C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
        goto L_80115584;
    // 0x8011557C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_80115580:
    // 0x80115580: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
L_80115584:
    // 0x80115584: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80115588: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8011558C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80115590: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80115594: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80115598: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8011559C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801155A0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801155A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801155A8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801155AC: lw          $t3, -0xE00($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XE00);
    // 0x801155B0: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
L_801155B4:
    // 0x801155B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801155B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801155BC: jr          $ra
    // 0x801155C0: nop

    return;
    // 0x801155C0: nop

;}
RECOMP_FUNC void sc1PChallengerDecalsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131B28: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131B2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131B3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131B40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131B44: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80131B48: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80131B4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B54: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80131B58: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80131B5C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131B60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131B6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B70: addiu       $t7, $zero, 0x3BFF
    ctx->r15 = ADD32(0, 0X3BFF);
    // 0x80131B74: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80131B78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131B7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131B80: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131B84: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131B88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B8C: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80131B90: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80131B94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131B98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B9C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80131BA0: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80131BA4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131BA8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131BAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BB0: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80131BB4: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80131BB8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131BBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131BC0: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80131BC4: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80131BC8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131BCC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131BD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BD4: lui         $t7, 0x33
    ctx->r15 = S32(0X33 << 16);
    // 0x80131BD8: lui         $t6, 0xF647
    ctx->r14 = S32(0XF647 << 16);
    // 0x80131BDC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131BE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131BE4: ori         $t6, $t6, 0xC360
    ctx->r14 = ctx->r14 | 0XC360;
    // 0x80131BE8: ori         $t7, $t7, 0xC170
    ctx->r15 = ctx->r15 | 0XC170;
    // 0x80131BEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131BF0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131BF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BF8: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80131BFC: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80131C00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131C04: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131C08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131C0C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80131C10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131C18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131C1C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80131C20: jal         0x800CCEAC
    // 0x80131C24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80131C24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_0:
    // 0x80131C28: jal         0x800CCF00
    // 0x80131C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80131C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80131C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131C38: jr          $ra
    // 0x80131C3C: nop

    return;
    // 0x80131C3C: nop

;}
RECOMP_FUNC void itEggExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181B64: jal         0x80181AA8
    // 0x80181B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itEggExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80181B68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80181B6C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181B70: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80181B74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80181B78: jal         0x80172EC8
    // 0x80181B7C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80181B7C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80181B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181B88: jr          $ra
    // 0x80181B8C: nop

    return;
    // 0x80181B8C: nop

;}
RECOMP_FUNC void ftNessSpecialLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801552E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801552EC: lw          $v1, 0xB20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB20);
    // 0x801552F0: beq         $v1, $zero, L_801552FC
    if (ctx->r3 == 0) {
        // 0x801552F4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_801552FC;
    }
    // 0x801552F4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x801552F8: sw          $t6, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r14;
L_801552FC:
    // 0x801552FC: jr          $ra
    // 0x80155300: nop

    return;
    // 0x80155300: nop

;}
RECOMP_FUNC void itTargetCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EE14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EE18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018EE1C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8018EE20: jal         0x80101790
    // 0x8018EE24: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerShieldBreakMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8018EE24: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8018EE28: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8018EE2C: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8018EE30: jal         0x80102DEC
    // 0x8018EE34: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerFireGrindMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8018EE34: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8018EE38: jal         0x800269C0
    // 0x8018EE3C: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8018EE3C: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_2:
    // 0x8018EE40: jal         0x8018D510
    // 0x8018EE44: nop

    sc1PBonusStageUpdateTargetCount(rdram, ctx);
        goto after_3;
    // 0x8018EE44: nop

    after_3:
    // 0x8018EE48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EE50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018EE54: jr          $ra
    // 0x8018EE58: nop

    return;
    // 0x8018EE58: nop

;}
RECOMP_FUNC void mnPlayersVSInitSlotAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013B094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B098: jal         0x8013AFC0
    // 0x8013B09C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnPlayersVSInitSlot(rdram, ctx);
        goto after_0;
    // 0x8013B09C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8013B0A0: jal         0x8013AFC0
    // 0x8013B0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnPlayersVSInitSlot(rdram, ctx);
        goto after_1;
    // 0x8013B0A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8013B0A8: jal         0x8013AFC0
    // 0x8013B0AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnPlayersVSInitSlot(rdram, ctx);
        goto after_2;
    // 0x8013B0AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8013B0B0: jal         0x8013AFC0
    // 0x8013B0B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnPlayersVSInitSlot(rdram, ctx);
        goto after_3;
    // 0x8013B0B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8013B0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013B0C0: jr          $ra
    // 0x8013B0C4: nop

    return;
    // 0x8013B0C4: nop

;}
RECOMP_FUNC void mnVSResultsMakeWallpaperTint2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013520C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80135210: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135214: sw          $t6, -0x6438($at)
    MEM_W(-0X6438, ctx->r1) = ctx->r14;
    // 0x80135218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013521C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135220: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80135224: jal         0x80009968
    // 0x80135228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013522C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135230: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80135234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80135238: addiu       $a1, $a1, 0x50C8
    ctx->r5 = ADD32(ctx->r5, 0X50C8);
    // 0x8013523C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135240: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80135244: jal         0x80009DF4
    // 0x80135248: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135248: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013524C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80135254: jr          $ra
    // 0x80135258: nop

    return;
    // 0x80135258: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801326D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801326DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801326E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326E4: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x801326E8: jal         0x80009968
    // 0x801326EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801326EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801326F0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801326F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326F8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801326FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132700: sw          $v0, 0x4308($at)
    MEM_W(0X4308, ctx->r1) = ctx->r2;
    // 0x80132704: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80132708: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013270C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80132710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132714: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80132718: jal         0x80009DF4
    // 0x8013271C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013271C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132720: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132724: lw          $t7, 0x4528($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4528);
    // 0x80132728: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013272C: addiu       $t8, $t8, 0x24F8
    ctx->r24 = ADD32(ctx->r24, 0X24F8);
    // 0x80132730: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80132734: jal         0x800CCFDC
    // 0x80132738: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132738: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013273C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132740: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80132744: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132748: lui         $at, 0x431C
    ctx->r1 = S32(0X431C << 16);
    // 0x8013274C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132750: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132754: addiu       $v1, $zero, 0xBE
    ctx->r3 = ADD32(0, 0XBE);
    // 0x80132758: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013275C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132760: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132764: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132768: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013276C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132770: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80132774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013277C: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80132780: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132784: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132788: jal         0x80009968
    // 0x8013278C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8013278C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x80132790: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132794: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80132798: sw          $v0, 0x430C($at)
    MEM_W(0X430C, ctx->r1) = ctx->r2;
    // 0x8013279C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801327A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801327A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801327AC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x801327B0: jal         0x80009DF4
    // 0x801327B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801327B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801327B8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801327BC: lw          $t5, 0x4528($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4528);
    // 0x801327C0: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x801327C4: addiu       $t6, $t6, 0x1900
    ctx->r14 = ADD32(ctx->r14, 0X1900);
    // 0x801327C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801327CC: jal         0x800CCFDC
    // 0x801327D0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801327D0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x801327D4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801327D8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801327DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801327E0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801327E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801327E8: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801327EC: addiu       $v1, $zero, 0xBE
    ctx->r3 = ADD32(0, 0XBE);
    // 0x801327F0: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801327F4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801327F8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801327FC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132800: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132804: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132808: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x8013280C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132810: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132818: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013281C: jr          $ra
    // 0x80132820: nop

    return;
    // 0x80132820: nop

;}
RECOMP_FUNC void unref_8000A208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A20C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000A214: jal         0x80007CF4
    // 0x8000A218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000A21C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A224: lbu         $t6, 0xD($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XD);
    // 0x8000A228: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x8000A22C: lw          $t7, 0x28($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X28);
    // 0x8000A230: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    // 0x8000A234: jal         0x80007B98
    // 0x8000A238: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A238: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    after_1:
    // 0x8000A23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A244: jr          $ra
    // 0x8000A248: nop

    return;
    // 0x8000A248: nop

;}
RECOMP_FUNC void func_ovl8_8037FEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FEF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037FEF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037FEFC: jal         0x803725DC
    // 0x8037FF00: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x8037FF00: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_0:
    // 0x8037FF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037FF08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037FF0C: jr          $ra
    // 0x8037FF10: nop

    return;
    // 0x8037FF10: nop

;}
RECOMP_FUNC void sc1PBonusStageBonus2LoadFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D5EC: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8018D5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D5F4: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
    // 0x8018D5F8: jal         0x800CDBD0
    // 0x8018D5FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018D5FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D604: jal         0x80004980
    // 0x8018D608: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018D608: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018D60C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D610: jal         0x800CDC88
    // 0x8018D614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018D614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018D618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D61C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018D620: sw          $v0, 0x13F4($at)
    MEM_W(0X13F4, ctx->r1) = ctx->r2;
    // 0x8018D624: jr          $ra
    // 0x8018D628: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D628: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itLizardonWeaponFlameProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017FAD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FAD4: jal         0x80167FE8
    // 0x8017FAD8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8017FAD8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8017FADC: beq         $v0, $zero, L_8017FAEC
    if (ctx->r2 == 0) {
        // 0x8017FAE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017FAEC;
    }
    // 0x8017FAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FAE4: b           L_8017FAF0
    // 0x8017FAE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017FAF0;
    // 0x8017FAE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017FAEC:
    // 0x8017FAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017FAF0:
    // 0x8017FAF0: jr          $ra
    // 0x8017FAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8017FAF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void syDebugMakeMeterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022368: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002236C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80022370: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80022374: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80022378: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8002237C: jal         0x8000B198
    // 0x80022380: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    gcFindGObjByID(rdram, ctx);
        goto after_0;
    // 0x80022380: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    after_0:
    // 0x80022384: beq         $v0, $zero, L_80022394
    if (ctx->r2 == 0) {
        // 0x80022388: addiu       $a0, $zero, -0x2
        ctx->r4 = ADD32(0, -0X2);
            goto L_80022394;
    }
    // 0x80022388: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8002238C: b           L_800223E4
    // 0x80022390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800223E4;
    // 0x80022390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022394:
    // 0x80022394: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80022398: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002239C: addiu       $t6, $t6, 0x1B30
    ctx->r14 = ADD32(ctx->r14, 0X1B30);
    // 0x800223A0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x800223A4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800223A8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800223AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800223B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800223B4: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x800223B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800223BC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800223C0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800223C4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800223C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800223CC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800223D0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800223D4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800223D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800223DC: jal         0x8000B93C
    // 0x800223E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    gcMakeCameraGObj(rdram, ctx);
        goto after_1;
    // 0x800223E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
L_800223E4:
    // 0x800223E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800223E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800223EC: jr          $ra
    // 0x800223F0: nop

    return;
    // 0x800223F0: nop

;}
RECOMP_FUNC void mvOpeningFoxFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE60: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE64: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE68: addiu       $a0, $a0, -0x1BE8
    ctx->r4 = ADD32(ctx->r4, -0X1BE8);
    // 0x8018DE6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE74: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DE78: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DE7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DE80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018DE84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8018DE88: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DE8C: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8018DE90:
    // 0x8018DE90: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DE94: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DE98: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DE9C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DEA0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DEA4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DEA8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DEAC: bne         $t6, $t0, L_8018DE90
    if (ctx->r14 != ctx->r8) {
        // 0x8018DEB0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DE90;
    }
    // 0x8018DEB0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DEB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEBC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8018DEC0: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8018DEC4: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x8018DEC8: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    // 0x8018DECC: sb          $v1, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r3;
    // 0x8018DED0: jal         0x8018D0C0
    // 0x8018DED4: sb          $a1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r5;
    mvOpeningFoxSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DED4: sb          $a1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r5;
    after_0:
    // 0x8018DED8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DEDC: addiu       $a1, $a1, -0x2268
    ctx->r5 = ADD32(ctx->r5, -0X2268);
    // 0x8018DEE0: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DEE4: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DEE8: jal         0x80009968
    // 0x8018DEEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DEEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DEF0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8018DEF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018DEF8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DEFC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF00: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF04: jal         0x8000B9FC
    // 0x8018DF08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF0C: jal         0x8018DE54
    // 0x8018DF10: nop

    mvOpeningFoxInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF10: nop

    after_3:
    // 0x8018DF14: jal         0x80115890
    // 0x8018DF18: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF18: nop

    after_4:
    // 0x8018DF1C: jal         0x800EC130
    // 0x8018DF20: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF20: nop

    after_5:
    // 0x8018DF24: jal         0x800FC284
    // 0x8018DF28: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF28: nop

    after_6:
    // 0x8018DF2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF34: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF38: jal         0x8010E598
    // 0x8018DF3C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF3C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF40: jal         0x8010DB54
    // 0x8018DF44: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF44: nop

    after_8:
    // 0x8018DF48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF4C: jal         0x800D7194
    // 0x8018DF50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF54: jal         0x801654B0
    // 0x8018DF58: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF58: nop

    after_10:
    // 0x8018DF5C: jal         0x8016DEA0
    // 0x8018DF60: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF60: nop

    after_11:
    // 0x8018DF64: jal         0x800FD300
    // 0x8018DF68: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF68: nop

    after_12:
    // 0x8018DF6C: jal         0x800D786C
    // 0x8018DF70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DF70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8018DF74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DF78: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DF7C: jal         0x80004980
    // 0x8018DF80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DF80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DF84: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DF88: jal         0x8018DB68
    // 0x8018DF8C: sw          $v0, -0x1DF4($at)
    MEM_W(-0X1DF4, ctx->r1) = ctx->r2;
    mvOpeningFoxMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DF8C: sw          $v0, -0x1DF4($at)
    MEM_W(-0X1DF4, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DF90: jal         0x8018DCF0
    // 0x8018DF94: nop

    mvOpeningFoxMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DF94: nop

    after_16:
    // 0x8018DF98: jal         0x8018DC08
    // 0x8018DF9C: nop

    mvOpeningFoxMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DF9C: nop

    after_17:
    // 0x8018DFA0: jal         0x8018D194
    // 0x8018DFA4: nop

    mvOpeningFoxMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DFA4: nop

    after_18:
    // 0x8018DFA8: jal         0x8000092C
    // 0x8018DFAC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DFAC: nop

    after_19:
    // 0x8018DFB0: sltiu       $at, $v0, 0x807
    ctx->r1 = ctx->r2 < 0X807 ? 1 : 0;
    // 0x8018DFB4: beql        $at, $zero, L_8018DFD4
    if (ctx->r1 == 0) {
        // 0x8018DFB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DFD4;
    }
    goto skip_0;
    // 0x8018DFB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFBC:
    // 0x8018DFBC: jal         0x8000092C
    // 0x8018DFC0: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFC0: nop

    after_20:
    // 0x8018DFC4: sltiu       $at, $v0, 0x807
    ctx->r1 = ctx->r2 < 0X807 ? 1 : 0;
    // 0x8018DFC8: bne         $at, $zero, L_8018DFBC
    if (ctx->r1 != 0) {
        // 0x8018DFCC: nop
    
            goto L_8018DFBC;
    }
    // 0x8018DFCC: nop

    // 0x8018DFD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DFD4:
    // 0x8018DFD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DFD8: jr          $ra
    // 0x8018DFDC: nop

    return;
    // 0x8018DFDC: nop

;}
RECOMP_FUNC void sc1PIntroCheckNotBonusStage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80131F70: beq         $a0, $at, L_80131F88
    if (ctx->r4 == ctx->r1) {
        // 0x80131F74: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80131F88;
    }
    // 0x80131F74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80131F78: beq         $a0, $at, L_80131F88
    if (ctx->r4 == ctx->r1) {
        // 0x80131F7C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80131F88;
    }
    // 0x80131F7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80131F80: bne         $a0, $at, L_80131F90
    if (ctx->r4 != ctx->r1) {
        // 0x80131F84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80131F90;
    }
    // 0x80131F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131F88:
    // 0x80131F88: jr          $ra
    // 0x80131F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131F90:
    // 0x80131F90: jr          $ra
    // 0x80131F94: nop

    return;
    // 0x80131F94: nop

;}
RECOMP_FUNC void ftCommonLiftWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801460E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801460EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801460F0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801460F4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x801460F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801460FC: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x80146100: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80146104: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80146108: jal         0x800E6F24
    // 0x8014610C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014610C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80146110: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80146114: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80146118: addiu       $t8, $t8, 0x5D28
    ctx->r24 = ADD32(ctx->r24, 0X5D28);
    // 0x8014611C: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x80146120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80146124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80146128: jr          $ra
    // 0x8014612C: nop

    return;
    // 0x8014612C: nop

;}
RECOMP_FUNC void func_800293A8_29FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800293AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800293B0: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800293B4: addiu       $s2, $s2, -0x1230
    ctx->r18 = ADD32(ctx->r18, -0X1230);
    // 0x800293B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800293BC: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    // 0x800293C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800293C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800293C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800293CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800293D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800293D4: beq         $s1, $zero, L_800294A0
    if (ctx->r17 == 0) {
        // 0x800293D8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800294A0;
    }
    // 0x800293D8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800293DC:
    // 0x800293DC: lbu         $t6, 0x2A($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X2A);
    // 0x800293E0: lw          $s3, 0x0($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X0);
    // 0x800293E4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x800293E8: bnel        $t6, $zero, L_80029498
    if (ctx->r14 != 0) {
        // 0x800293EC: or          $s4, $s1, $zero
        ctx->r20 = ctx->r17 | 0;
            goto L_80029498;
    }
    goto skip_0;
    // 0x800293EC: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    skip_0:
    // 0x800293F0: jal         0x8002D780
    // 0x800293F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynStopVoice(rdram, ctx);
        goto after_0;
    // 0x800293F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800293F8: jal         0x8002FEC0
    // 0x800293FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynFreeVoice(rdram, ctx);
        goto after_1;
    // 0x800293FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80029400: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x80029404: beql        $s0, $zero, L_8002942C
    if (ctx->r16 == 0) {
        // 0x80029408: lw          $a0, 0x44($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X44);
            goto L_8002942C;
    }
    goto skip_1;
    // 0x80029408: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    skip_1:
    // 0x8002940C: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
L_80029410:
    // 0x80029410: bnel        $s1, $t7, L_80029420
    if (ctx->r17 != ctx->r15) {
        // 0x80029414: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_80029420;
    }
    goto skip_2;
    // 0x80029414: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80029418: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8002941C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_80029420:
    // 0x80029420: bnel        $s0, $zero, L_80029410
    if (ctx->r16 != 0) {
        // 0x80029424: lw          $t7, 0x28($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X28);
            goto L_80029410;
    }
    goto skip_3;
    // 0x80029424: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    skip_3:
    // 0x80029428: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
L_8002942C:
    // 0x8002942C: beq         $a0, $zero, L_80029468
    if (ctx->r4 == 0) {
        // 0x80029430: nop
    
            goto L_80029468;
    }
    // 0x80029430: nop

    // 0x80029434: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80029438: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8002943C: beql        $v0, $zero, L_80029458
    if (ctx->r2 == 0) {
        // 0x80029440: lw          $t8, 0x30($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X30);
            goto L_80029458;
    }
    goto skip_4;
    // 0x80029440: lw          $t8, 0x30($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X30);
    skip_4:
    // 0x80029444: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80029448:
    // 0x80029448: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002944C: bnel        $v0, $zero, L_80029448
    if (ctx->r2 != 0) {
        // 0x80029450: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80029448;
    }
    goto skip_5;
    // 0x80029450: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_5:
    // 0x80029454: lw          $t8, 0x30($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X30);
L_80029458:
    // 0x80029458: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002945C: lw          $t9, 0x44($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X44);
    // 0x80029460: sw          $t9, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r25;
    // 0x80029464: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
L_80029468:
    // 0x80029468: beq         $s4, $zero, L_8002947C
    if (ctx->r20 == 0) {
        // 0x8002946C: sh          $zero, 0x48($s1)
        MEM_H(0X48, ctx->r17) = 0;
            goto L_8002947C;
    }
    // 0x8002946C: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
    // 0x80029470: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80029474: b           L_80029484
    // 0x80029478: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
        goto L_80029484;
    // 0x80029478: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
L_8002947C:
    // 0x8002947C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80029480: sw          $t1, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r9;
L_80029484:
    // 0x80029484: lw          $t2, 0x34($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X34);
    // 0x80029488: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8002948C: b           L_80029498
    // 0x80029490: sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
        goto L_80029498;
    // 0x80029490: sw          $s1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r17;
    // 0x80029494: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
L_80029498:
    // 0x80029498: bne         $s3, $zero, L_800293DC
    if (ctx->r19 != 0) {
        // 0x8002949C: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_800293DC;
    }
    // 0x8002949C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_800294A0:
    // 0x800294A0: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x800294A4: beql        $s0, $zero, L_800294C4
    if (ctx->r16 == 0) {
        // 0x800294A8: lw          $s1, 0x3C($s2)
        ctx->r17 = MEM_W(ctx->r18, 0X3C);
            goto L_800294C4;
    }
    goto skip_6;
    // 0x800294A8: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
    skip_6:
L_800294AC:
    // 0x800294AC: jal         0x80026B90
    // 0x800294B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80026B90_27790(rdram, ctx);
        goto after_2;
    // 0x800294B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800294B4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800294B8: bne         $s0, $zero, L_800294AC
    if (ctx->r16 != 0) {
        // 0x800294BC: nop
    
            goto L_800294AC;
    }
    // 0x800294BC: nop

    // 0x800294C0: lw          $s1, 0x3C($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X3C);
L_800294C4:
    // 0x800294C4: beql        $s1, $zero, L_800294E4
    if (ctx->r17 == 0) {
        // 0x800294C8: lw          $s0, 0x40($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X40);
            goto L_800294E4;
    }
    goto skip_7;
    // 0x800294C8: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    skip_7:
L_800294CC:
    // 0x800294CC: jal         0x80027460
    // 0x800294D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80027460_28060(rdram, ctx);
        goto after_3;
    // 0x800294D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800294D4: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x800294D8: bne         $s1, $zero, L_800294CC
    if (ctx->r17 != 0) {
        // 0x800294DC: nop
    
            goto L_800294CC;
    }
    // 0x800294DC: nop

    // 0x800294E0: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
L_800294E4:
    // 0x800294E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800294E8: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x800294EC: beq         $s0, $zero, L_80029540
    if (ctx->r16 == 0) {
        // 0x800294F0: nop
    
            goto L_80029540;
    }
    // 0x800294F0: nop

L_800294F4:
    // 0x800294F4: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
    // 0x800294F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800294FC: bnel        $a0, $t3, L_80029538
    if (ctx->r4 != ctx->r11) {
        // 0x80029500: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80029538;
    }
    goto skip_8;
    // 0x80029500: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_8:
    // 0x80029504: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x80029508: beq         $v0, $zero, L_8002951C
    if (ctx->r2 == 0) {
        // 0x8002950C: sh          $zero, 0x26($s0)
        MEM_H(0X26, ctx->r16) = 0;
            goto L_8002951C;
    }
    // 0x8002950C: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x80029510: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80029514: b           L_80029524
    // 0x80029518: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_80029524;
    // 0x80029518: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8002951C:
    // 0x8002951C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80029520: sw          $t5, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r13;
L_80029524:
    // 0x80029524: lw          $t6, 0x38($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X38);
    // 0x80029528: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002952C: b           L_80029538
    // 0x80029530: sw          $s0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r16;
        goto L_80029538;
    // 0x80029530: sw          $s0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r16;
    // 0x80029534: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80029538:
    // 0x80029538: bne         $v1, $zero, L_800294F4
    if (ctx->r3 != 0) {
        // 0x8002953C: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_800294F4;
    }
    // 0x8002953C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80029540:
    // 0x80029540: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80029544: addiu       $v0, $v0, -0x2CDC
    ctx->r2 = ADD32(ctx->r2, -0X2CDC);
    // 0x80029548: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002954C: lui         $at, 0x26
    ctx->r1 = S32(0X26 << 16);
    // 0x80029550: ori         $at, $at, 0x9EC3
    ctx->r1 = ctx->r1 | 0X9EC3;
    // 0x80029554: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80029558: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8002955C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80029560: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80029564: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80029568: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002956C: sll         $t8, $t8, 8
    ctx->r24 = S32(ctx->r24 << 8);
    // 0x80029570: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80029574: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80029578: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002957C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80029580: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029584: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80029588: lw          $v0, 0x44($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X44);
    // 0x8002958C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029590: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80029594: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80029598: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002959C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800295A0: jr          $ra
    // 0x800295A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800295A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mvOpeningRoomMakeCloseUpOverlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132CEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132CF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132CF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CF8: sw          $zero, 0x4D38($at)
    MEM_W(0X4D38, ctx->r1) = 0;
    // 0x80132CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D04: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132D08: jal         0x80009968
    // 0x80132D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D18: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132D1C: sw          $v0, 0x4D3C($at)
    MEM_W(0X4D3C, ctx->r1) = ctx->r2;
    // 0x80132D20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D24: addiu       $a1, $a1, 0x2BB8
    ctx->r5 = ADD32(ctx->r5, 0X2BB8);
    // 0x80132D28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D2C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132D30: jal         0x80009DF4
    // 0x80132D34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132D34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132D40: jr          $ra
    // 0x80132D44: nop

    return;
    // 0x80132D44: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801534BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801534C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801534C4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801534C8: jal         0x800DDDDC
    // 0x801534CC: addiu       $a1, $a1, 0x3584
    ctx->r5 = ADD32(ctx->r5, 0X3584);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801534CC: addiu       $a1, $a1, 0x3584
    ctx->r5 = ADD32(ctx->r5, 0X3584);
    after_0:
    // 0x801534D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801534D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801534D8: jr          $ra
    // 0x801534DC: nop

    return;
    // 0x801534DC: nop

;}
RECOMP_FUNC void func_ovl8_80384340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80384344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80384348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038434C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80384350: beq         $a0, $zero, L_803843F8
    if (ctx->r4 == 0) {
        // 0x80384354: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803843F8;
    }
    // 0x80384354: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80384358: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8038435C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80384360: addiu       $t6, $t6, -0x3270
    ctx->r14 = ADD32(ctx->r14, -0X3270);
    // 0x80384364: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80384368: addiu       $t7, $t7, -0x3120
    ctx->r15 = ADD32(ctx->r15, -0X3120);
    // 0x8038436C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80384370: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80384374: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80384378: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8038437C: addiu       $t9, $t9, -0x2FC8
    ctx->r25 = ADD32(ctx->r25, -0X2FC8);
    // 0x80384380: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80384384: addiu       $t1, $t1, -0x2FA0
    ctx->r9 = ADD32(ctx->r9, -0X2FA0);
    // 0x80384388: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8038438C: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x80384390: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x80384394: beql        $a0, $zero, L_803843A8
    if (ctx->r4 == 0) {
        // 0x80384398: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_803843A8;
    }
    goto skip_0;
    // 0x80384398: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    skip_0:
    // 0x8038439C: jal         0x8037B3E4
    // 0x803843A0: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x803843A0: nop

    after_0:
    // 0x803843A4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
L_803843A8:
    // 0x803843A8: jal         0x80372554
    // 0x803843AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80372554(rdram, ctx);
        goto after_1;
    // 0x803843AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x803843B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803843B4: jal         0x80383510
    // 0x803843B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80383510(rdram, ctx);
        goto after_2;
    // 0x803843B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x803843BC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x803843C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803843C4: beql        $t2, $zero, L_803843E4
    if (ctx->r10 == 0) {
        // 0x803843C8: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_803843E4;
    }
    goto skip_1;
    // 0x803843C8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x803843CC: jal         0x8037C30C
    // 0x803843D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x803843D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x803843D4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803843D8: jal         0x803718C4
    // 0x803843DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x803843DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x803843E0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_803843E4:
    // 0x803843E4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x803843E8: beql        $t4, $zero, L_803843FC
    if (ctx->r12 == 0) {
        // 0x803843EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803843FC;
    }
    goto skip_2;
    // 0x803843EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803843F0: jal         0x803717C0
    // 0x803843F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x803843F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_803843F8:
    // 0x803843F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803843FC:
    // 0x803843FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80384400: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80384404: jr          $ra
    // 0x80384408: nop

    return;
    // 0x80384408: nop

;}
RECOMP_FUNC void mnVSOptionsMakeDecal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801334B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801334B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801334BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801334C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801334C4: jal         0x80009968
    // 0x801334C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801334C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801334CC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801334D0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801334D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801334D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801334DC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801334E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801334E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801334E8: jal         0x80009DF4
    // 0x801334EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801334EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801334F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801334F4: lw          $t7, 0x49DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49DC);
    // 0x801334F8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801334FC: addiu       $t8, $t8, 0x5F60
    ctx->r24 = ADD32(ctx->r24, 0X5F60);
    // 0x80133500: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133504: jal         0x800CCFDC
    // 0x80133508: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133508: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013350C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133510: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133514: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133518: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013351C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133520: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133524: addiu       $t3, $zero, 0x4A
    ctx->r11 = ADD32(0, 0X4A);
    // 0x80133528: addiu       $t4, $zero, 0x2A
    ctx->r12 = ADD32(0, 0X2A);
    // 0x8013352C: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x80133530: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133534: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133538: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x8013353C: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133540: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80133544: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013354C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133550: jr          $ra
    // 0x80133554: nop

    return;
    // 0x80133554: nop

;}
RECOMP_FUNC void func_ovl29_801369C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369C8: jr          $ra
    // 0x801369CC: nop

    return;
    // 0x801369CC: nop

;}
RECOMP_FUNC void mnSoundTestMakeAllSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801336DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801336E0: jal         0x8013234C
    // 0x801336E4: nop

    mnSoundTestMakeHeaderSObjs(rdram, ctx);
        goto after_0;
    // 0x801336E4: nop

    after_0:
    // 0x801336E8: jal         0x80132638
    // 0x801336EC: nop

    mnSoundTestMakeMusicSObjs(rdram, ctx);
        goto after_1;
    // 0x801336EC: nop

    after_1:
    // 0x801336F0: jal         0x80132894
    // 0x801336F4: nop

    mnSoundTestMakeSoundSObjs(rdram, ctx);
        goto after_2;
    // 0x801336F4: nop

    after_2:
    // 0x801336F8: jal         0x80132AF4
    // 0x801336FC: nop

    mnSoundTestMakeVoiceSObjs(rdram, ctx);
        goto after_3;
    // 0x801336FC: nop

    after_3:
    // 0x80133700: jal         0x80133398
    // 0x80133704: nop

    mnSoundTestMakeSelectIDGObjs(rdram, ctx);
        goto after_4;
    // 0x80133704: nop

    after_4:
    // 0x80133708: jal         0x801335C8
    // 0x8013370C: nop

    mnSoundTestMakeArrowSObjs(rdram, ctx);
        goto after_5;
    // 0x8013370C: nop

    after_5:
    // 0x80133710: jal         0x80132EC8
    // 0x80133714: nop

    mnSoundTestMakeButtonSObjs(rdram, ctx);
        goto after_6;
    // 0x80133714: nop

    after_6:
    // 0x80133718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013371C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133720: jr          $ra
    // 0x80133724: nop

    return;
    // 0x80133724: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BF14: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BF18: jal         0x800DE6E4
    // 0x8015BF1C: addiu       $a1, $a1, -0x40D0
    ctx->r5 = ADD32(ctx->r5, -0X40D0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015BF1C: addiu       $a1, $a1, -0x40D0
    ctx->r5 = ADD32(ctx->r5, -0X40D0);
    after_0:
    // 0x8015BF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BF28: jr          $ra
    // 0x8015BF2C: nop

    return;
    // 0x8015BF2C: nop

;}
RECOMP_FUNC void func_ovl3_80185B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185B18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80185B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185B20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80185B24: lw          $t0, 0x74($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X74);
    // 0x80185B28: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x80185B2C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80185B30: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x80185B34: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
    // 0x80185B38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80185B3C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80185B40: lw          $t6, 0x20($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X20);
    // 0x80185B44: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80185B48: lw          $t7, 0x24($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X24);
    // 0x80185B4C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80185B50: lh          $t8, 0x2E($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2E);
    // 0x80185B54: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80185B58: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80185B5C: nop

    // 0x80185B60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80185B64: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80185B68: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80185B6C: jal         0x800FF3F4
    // 0x80185B70: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    efManagerDustHeavyDoubleMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80185B70: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    after_0:
    // 0x80185B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185B78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80185B7C: jr          $ra
    // 0x80185B80: nop

    return;
    // 0x80185B80: nop

;}
RECOMP_FUNC void ftFoxSpecialHiHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BEE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BEF0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BEF4: jal         0x800DDDDC
    // 0x8015BEF8: addiu       $a1, $a1, -0x4090
    ctx->r5 = ADD32(ctx->r5, -0X4090);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015BEF8: addiu       $a1, $a1, -0x4090
    ctx->r5 = ADD32(ctx->r5, -0X4090);
    after_0:
    // 0x8015BEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BF00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BF04: jr          $ra
    // 0x8015BF08: nop

    return;
    // 0x8015BF08: nop

;}
RECOMP_FUNC void ftCommonKneeBendSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F40C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F410: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8013F414: jal         0x8013F3A0
    // 0x8013F418: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ftCommonKneeBendSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8013F418: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x8013F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F424: jr          $ra
    // 0x8013F428: nop

    return;
    // 0x8013F428: nop

;}
RECOMP_FUNC void LBParticleProcessStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEA18: beq         $a0, $zero, L_800CEA30
    if (ctx->r4 == 0) {
        // 0x800CEA1C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CEA30;
    }
    // 0x800CEA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEA20: lbu         $a2, 0x8($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X8);
    // 0x800CEA24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CEA28: jal         0x800CEF4C
    // 0x800CEA2C: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_0;
    // 0x800CEA2C: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_0:
L_800CEA30:
    // 0x800CEA30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEA38: jr          $ra
    // 0x800CEA3C: nop

    return;
    // 0x800CEA3C: nop

;}
RECOMP_FUNC void ftMarioSpecialAirLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801566C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801566C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801566CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801566D0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801566D4: lw          $t6, 0xADC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XADC);
    // 0x801566D8: lw          $a3, 0x9C8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X9C8);
    // 0x801566DC: bnel        $t6, $zero, L_8015671C
    if (ctx->r14 != 0) {
        // 0x801566E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015671C;
    }
    goto skip_0;
    // 0x801566E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801566E4: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x801566E8: beql        $t7, $zero, L_8015671C
    if (ctx->r15 == 0) {
        // 0x801566EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015671C;
    }
    goto skip_1;
    // 0x801566EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801566F0: lhu         $t8, 0x1BE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1BE);
    // 0x801566F4: lhu         $t9, 0x1B6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X1B6);
    // 0x801566F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801566FC: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    // 0x80156700: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80156704: beq         $t0, $zero, L_80156718
    if (ctx->r8 == 0) {
        // 0x80156708: lui         $a2, 0x4220
        ctx->r6 = S32(0X4220 << 16);
            goto L_80156718;
    }
    // 0x80156708: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x8015670C: jal         0x800D8D34
    // 0x80156710: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    ftPhysicsAddClampAirVelY(rdram, ctx);
        goto after_0;
    // 0x80156710: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80156714: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80156718:
    // 0x80156718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8015671C:
    // 0x8015671C: jal         0x800D8E50
    // 0x80156720: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_1;
    // 0x80156720: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80156724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156728: jal         0x801565E4
    // 0x8015672C: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    ftMarioSpecialLwUpdateFriction(rdram, ctx);
        goto after_2;
    // 0x8015672C: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    after_2:
    // 0x80156730: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80156734: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80156738: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8015673C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156740: jal         0x800D8FC8
    // 0x80156744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_3;
    // 0x80156744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80156748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015674C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80156750: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156754: jr          $ra
    // 0x80156758: nop

    return;
    // 0x80156758: nop

;}
RECOMP_FUNC void gcGetGObjThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800073E0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800073E4: addiu       $a2, $a2, 0x66B0
    ctx->r6 = ADD32(ctx->r6, 0X66B0);
    // 0x800073E8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800073EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800073F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800073F4: bne         $v1, $zero, L_80007418
    if (ctx->r3 != 0) {
        // 0x800073F8: addiu       $a0, $zero, 0x1C0
        ctx->r4 = ADD32(0, 0X1C0);
            goto L_80007418;
    }
    // 0x800073F8: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x800073FC: jal         0x80004980
    // 0x80007400: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007400: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80007404: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007408: addiu       $a2, $a2, 0x66B0
    ctx->r6 = ADD32(ctx->r6, 0X66B0);
    // 0x8000740C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007410: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007414: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007418:
    // 0x80007418: bne         $v1, $zero, L_80007434
    if (ctx->r3 != 0) {
        // 0x8000741C: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007434;
    }
    // 0x8000741C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007420: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007424: jal         0x80023624
    // 0x80007428: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80007428: addiu       $a0, $a0, -0x26D0
    ctx->r4 = ADD32(ctx->r4, -0X26D0);
    after_1:
L_8000742C:
    // 0x8000742C: b           L_8000742C
    pause_self(rdram);
    // 0x80007430: nop

L_80007434:
    // 0x80007434: addiu       $a1, $a1, 0x66B4
    ctx->r5 = ADD32(ctx->r5, 0X66B4);
    // 0x80007438: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000743C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007440: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007444: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007448: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8000744C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007450: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007454: jr          $ra
    // 0x80007458: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80007458: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void func_ovl0_800C96DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C96DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C96E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C96E4: jr          $ra
    // 0x800C96E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800C96E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void ftCommonLightThrowCheckInterruptGuardOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146AF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80146AF4: lw          $t6, 0x84C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84C);
    // 0x80146AF8: beql        $t6, $zero, L_80146B44
    if (ctx->r14 == 0) {
        // 0x80146AFC: lw          $v1, 0xB38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XB38);
            goto L_80146B44;
    }
    goto skip_0;
    // 0x80146AFC: lw          $v1, 0xB38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB38);
    skip_0:
    // 0x80146B00: lhu         $t7, 0x1BE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80146B04: lhu         $t8, 0x1B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80146B08: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80146B0C: beql        $t9, $zero, L_80146B44
    if (ctx->r25 == 0) {
        // 0x80146B10: lw          $v1, 0xB38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XB38);
            goto L_80146B44;
    }
    goto skip_1;
    // 0x80146B10: lw          $v1, 0xB38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB38);
    skip_1:
    // 0x80146B14: lw          $t0, 0xB38($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB38);
    // 0x80146B18: beq         $t0, $zero, L_80146B30
    if (ctx->r8 == 0) {
        // 0x80146B1C: nop
    
            goto L_80146B30;
    }
    // 0x80146B1C: nop

    // 0x80146B20: jal         0x80146690
    // 0x80146B24: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_0;
    // 0x80146B24: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_0:
    // 0x80146B28: b           L_80146B54
    // 0x80146B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80146B54;
    // 0x80146B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80146B30:
    // 0x80146B30: jal         0x801466EC
    // 0x80146B34: nop

    ftCommonLightThrowDecideSetStatus(rdram, ctx);
        goto after_1;
    // 0x80146B34: nop

    after_1:
    // 0x80146B38: b           L_80146B54
    // 0x80146B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80146B54;
    // 0x80146B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80146B40: lw          $v1, 0xB38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB38);
L_80146B44:
    // 0x80146B44: beq         $v1, $zero, L_80146B50
    if (ctx->r3 == 0) {
        // 0x80146B48: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80146B50;
    }
    // 0x80146B48: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80146B4C: sw          $t1, 0xB38($v0)
    MEM_W(0XB38, ctx->r2) = ctx->r9;
L_80146B50:
    // 0x80146B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146B54:
    // 0x80146B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146B5C: jr          $ra
    // 0x80146B60: nop

    return;
    // 0x80146B60: nop

;}
RECOMP_FUNC void sySchedulerRemoveMainQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000CF4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80000CF8: beql        $v0, $zero, L_80000D10
    if (ctx->r2 == 0) {
        // 0x80000CFC: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_80000D10;
    }
    goto skip_0;
    // 0x80000CFC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x80000D00: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80000D04: b           L_80000D18
    // 0x80000D08: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
        goto L_80000D18;
    // 0x80000D08: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80000D0C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_80000D10:
    // 0x80000D10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000D14: sw          $t7, 0x4EC4($at)
    MEM_W(0X4EC4, ctx->r1) = ctx->r15;
L_80000D18:
    // 0x80000D18: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000D1C: beql        $v0, $zero, L_80000D34
    if (ctx->r2 == 0) {
        // 0x80000D20: lw          $t9, 0x10($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X10);
            goto L_80000D34;
    }
    goto skip_1;
    // 0x80000D20: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x80000D24: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80000D28: jr          $ra
    // 0x80000D2C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    return;
    // 0x80000D2C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80000D30: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
L_80000D34:
    // 0x80000D34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000D38: sw          $t9, 0x4EC8($at)
    MEM_W(0X4EC8, ctx->r1) = ctx->r25;
    // 0x80000D3C: jr          $ra
    // 0x80000D40: nop

    return;
    // 0x80000D40: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC2C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC30: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC38: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC3C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC40: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC44: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC48: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC58: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC5C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC60: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC64: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC68: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC6C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC70: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC7C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC80: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC88: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC8C: jal         0x8000B93C
    // 0x8018DC90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC94: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC98: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC9C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DCA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DCA4: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DCA8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DCAC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DCB0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DCB4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DCB8: jal         0x80007080
    // 0x8018DCBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DCBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DCC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DCC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCC8: lwc1        $f6, -0x1DEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DEC);
    // 0x8018DCCC: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DCD0: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DCD4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DCD8: lw          $t4, -0x1BBC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1BBC);
    // 0x8018DCDC: addiu       $t5, $t5, 0x150
    ctx->r13 = ADD32(ctx->r13, 0X150);
    // 0x8018DCE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCE4: jal         0x8000FA3C
    // 0x8018DCE8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCE8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCEC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCF0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCF4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCFC: jal         0x80008188
    // 0x8018DD00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DD00: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DD04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD0C: jr          $ra
    // 0x8018DD10: nop

    return;
    // 0x8018DD10: nop

;}

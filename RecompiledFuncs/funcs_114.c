#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonAppealProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E6A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E6A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E6AC: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014E6B0: beql        $t6, $zero, L_8014E6D4
    if (ctx->r14 == 0) {
        // 0x8014E6B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014E6D4;
    }
    goto skip_0;
    // 0x8014E6B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014E6B8: jal         0x80149CE0
    // 0x8014E6BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014E6BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014E6C0: bne         $v0, $zero, L_8014E6D0
    if (ctx->r2 != 0) {
        // 0x8014E6C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8014E6D0;
    }
    // 0x8014E6C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8014E6C8: jal         0x80148D0C
    // 0x8014E6CC: nop

    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014E6CC: nop

    after_1:
L_8014E6D0:
    // 0x8014E6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E6D4:
    // 0x8014E6D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E6D8: jr          $ra
    // 0x8014E6DC: nop

    return;
    // 0x8014E6DC: nop

;}
RECOMP_FUNC void efManagerKirbyInhaleWindProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104240: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80104244: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80104248: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010424C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80104250: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80104254: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80104258: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010425C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x80104260: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80104264: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80104268: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8010426C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80104270: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x80104274: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x80104278: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8010427C: lw          $t1, 0x84($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X84);
    // 0x80104280: lw          $t2, 0x44($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X44);
    // 0x80104284: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80104288: nop

    // 0x8010428C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80104290: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80104294: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80104298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010429C: nop

    // 0x801042A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801042A4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801042A8: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x801042AC: jr          $ra
    // 0x801042B0: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x801042B0: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void syUtilsArcTan2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001863C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018640: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80018644: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80018648: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8001864C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80018650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018654: bc1fl       L_80018670
    if (!c1cs) {
        // 0x80018658: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80018670;
    }
    goto skip_0;
    // 0x80018658: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x8001865C: jal         0x80018514
    // 0x80018660: div.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    syUtilsArcTan(rdram, ctx);
        goto after_0;
    // 0x80018660: div.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    after_0:
    // 0x80018664: b           L_8001872C
    // 0x80018668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001872C;
    // 0x80018668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001866C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80018670:
    // 0x80018670: nop

    // 0x80018674: bc1fl       L_800186E4
    if (!c1cs) {
        // 0x80018678: c.eq.s      $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
            goto L_800186E4;
    }
    goto skip_1;
    // 0x80018678: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    skip_1:
    // 0x8001867C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80018680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018684: div.s       $f0, $f20, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80018688: bc1f        L_80018698
    if (!c1cs) {
        // 0x8001868C: nop
    
            goto L_80018698;
    }
    // 0x8001868C: nop

    // 0x80018690: b           L_80018698
    // 0x80018694: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80018698;
    // 0x80018694: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80018698:
    // 0x80018698: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001869C: nop

    // 0x800186A0: bc1fl       L_800186B4
    if (!c1cs) {
        // 0x800186A4: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_800186B4;
    }
    goto skip_2;
    // 0x800186A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_2:
    // 0x800186A8: b           L_800186B4
    // 0x800186AC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_800186B4;
    // 0x800186AC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x800186B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800186B4:
    // 0x800186B4: jal         0x80018514
    // 0x800186B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    syUtilsArcTan(rdram, ctx);
        goto after_1;
    // 0x800186B8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x800186BC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800186C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800186C4: lwc1        $f4, -0x1C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C90);
    // 0x800186C8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800186CC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800186D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800186D4: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800186D8: b           L_8001872C
    // 0x800186DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001872C;
    // 0x800186DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800186E0: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
L_800186E4:
    // 0x800186E4: nop

    // 0x800186E8: bc1tl       L_80018728
    if (c1cs) {
        // 0x800186EC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80018728;
    }
    goto skip_3;
    // 0x800186EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x800186F0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x800186F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800186F8: bc1f        L_80018708
    if (!c1cs) {
        // 0x800186FC: nop
    
            goto L_80018708;
    }
    // 0x800186FC: nop

    // 0x80018700: b           L_80018708
    // 0x80018704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80018708;
    // 0x80018704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80018708:
    // 0x80018708: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8001870C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018710: lwc1        $f4, -0x1C8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C8C);
    // 0x80018714: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80018718: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001871C: b           L_8001872C
    // 0x80018720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001872C;
    // 0x80018720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018724: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80018728:
    // 0x80018728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001872C:
    // 0x8001872C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80018730: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80018734: jr          $ra
    // 0x80018738: nop

    return;
    // 0x80018738: nop

;}
RECOMP_FUNC void func_ovl29_80135BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BAC: jr          $ra
    // 0x80135BB0: nop

    return;
    // 0x80135BB0: nop

;}
RECOMP_FUNC void itIwarkAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017DA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DA68: jal         0x8017D948
    // 0x8017DA6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itIwarkAttackInitVars(rdram, ctx);
        goto after_0;
    // 0x8017DA6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017DA70: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017DA74: addiu       $a1, $a1, -0x553C
    ctx->r5 = ADD32(ctx->r5, -0X553C);
    // 0x8017DA78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017DA7C: jal         0x80172EC8
    // 0x8017DA80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017DA80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017DA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DA88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017DA8C: jr          $ra
    // 0x8017DA90: nop

    return;
    // 0x8017DA90: nop

;}
RECOMP_FUNC void func_80010C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010C2C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80010C30: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80010C34: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80010C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010C3C: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80010C40: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80010C44: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80010C48: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010C4C: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80010C50: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80010C54: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80010C58: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80010C5C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80010C60: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80010C64: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80010C68: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80010C6C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80010C70: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80010C74: jal         0x80033510
    // 0x80010C78: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80010C78: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80010C7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80010C80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010C88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80010C8C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80010C90: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80010C94: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80010C98: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80010C9C: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x80010CA0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80010CA4: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80010CA8: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80010CAC: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x80010CB0: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80010CB4: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x80010CB8: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x80010CBC: bc1t        L_80010CFC
    if (c1cs) {
        // 0x80010CC0: swc1        $f18, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
            goto L_80010CFC;
    }
    // 0x80010CC0: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x80010CC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010CC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010CCC: nop

    // 0x80010CD0: div.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80010CD4: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80010CD8: nop

    // 0x80010CDC: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80010CE0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80010CE4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80010CE8: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80010CEC: neg.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = -ctx->f16.fl;
    // 0x80010CF0: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x80010CF4: b           L_80010D18
    // 0x80010CF8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
        goto L_80010D18;
    // 0x80010CF8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
L_80010CFC:
    // 0x80010CFC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010D00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80010D04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80010D08: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x80010D0C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80010D10: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80010D14: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
L_80010D18:
    // 0x80010D18: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80010D1C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80010D20: beql        $t7, $zero, L_80010D48
    if (ctx->r15 == 0) {
        // 0x80010D24: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80010D48;
    }
    goto skip_0;
    // 0x80010D24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80010D28: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80010D2C: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80010D30: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80010D34: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80010D38: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80010D3C: b           L_80010D58
    // 0x80010D40: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
        goto L_80010D58;
    // 0x80010D40: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80010D44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80010D48:
    // 0x80010D48: nop

    // 0x80010D4C: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80010D50: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80010D54: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
L_80010D58:
    // 0x80010D58: jal         0x80019EA0
    // 0x80010D5C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x80010D5C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_1:
    // 0x80010D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010D64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80010D68: jr          $ra
    // 0x80010D6C: nop

    return;
    // 0x80010D6C: nop

;}
RECOMP_FUNC void grBonus3InitHeaders(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B4D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B4D4: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8010B4D8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8010B4DC: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8010B4E0: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x8010B4E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010B4E8: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x8010B4EC: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8010B4F0: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010B4F4: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8010B4F8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8010B4FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8010B500: jr          $ra
    // 0x8010B504: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    return;
    // 0x8010B504: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void func_ovl8_803723AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803723AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803723B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x803723B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803723B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803723BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x803723C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x803723C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803723C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x803723CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x803723D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803723D4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x803723D8: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x803723DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x803723E0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x803723E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x803723E8: jal         0x8037BF68
    // 0x803723EC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_ovl8_8037BF68(rdram, ctx);
        goto after_0;
    // 0x803723EC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x803723F0: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x803723F4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x803723F8: sw          $t8, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r24;
    // 0x803723FC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80372400: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x80372404: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x80372408: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x8037240C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80372410: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80372414: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80372418: jr          $ra
    // 0x8037241C: nop

    return;
    // 0x8037241C: nop

;}
RECOMP_FUNC void ftMainPlayAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E07D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E07D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E07DC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E07E0: lw          $t6, 0x198($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X198);
    // 0x800E07E4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800E07E8: bgez        $t8, L_800E080C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E07EC: nop
    
            goto L_800E080C;
    }
    // 0x800E07EC: nop

    // 0x800E07F0: lw          $t9, 0x8EC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8EC);
    // 0x800E07F4: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x800E07F8: sw          $t1, 0x19C($v0)
    MEM_W(0X19C, ctx->r2) = ctx->r9;
    // 0x800E07FC: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x800E0800: sw          $t0, 0x1A0($v0)
    MEM_W(0X1A0, ctx->r2) = ctx->r8;
    // 0x800E0804: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x800E0808: sw          $t1, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r9;
L_800E080C:
    // 0x800E080C: jal         0x800E82B8
    // 0x800E0810: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamUpdateAnimKeys(rdram, ctx);
        goto after_0;
    // 0x800E0810: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E0814: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E0818: jal         0x800EB648
    // 0x800E081C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    ftParamsUpdateFighterPartsTransform(rdram, ctx);
        goto after_1;
    // 0x800E081C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_1:
    // 0x800E0820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0824: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E0828: jr          $ra
    // 0x800E082C: nop

    return;
    // 0x800E082C: nop

;}
RECOMP_FUNC void grSectorArwingGetLaserAmmoCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106F5C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106F60: addiu       $a0, $a0, 0x13F0
    ctx->r4 = ADD32(ctx->r4, 0X13F0);
    // 0x80106F64: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80106F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106F6C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80106F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106F74: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80106F78: lw          $v1, 0x66FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X66FC);
    // 0x80106F7C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80106F80: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80106F84: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80106F88: lwc1        $f8, 0x20($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80106F8C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80106F90: beq         $v1, $zero, L_8010701C
    if (ctx->r3 == 0) {
        // 0x80106F94: add.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_8010701C;
    }
    // 0x80106F94: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80106F98: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80106F9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80106FA0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80106FA4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80106FA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80106FAC: lbu         $a2, 0x1445($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X1445);
    // 0x80106FB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80106FB4:
    // 0x80106FB4: bne         $a1, $a2, L_80107010
    if (ctx->r5 != ctx->r6) {
        // 0x80106FB8: lw          $a0, 0x84($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X84);
            goto L_80107010;
    }
    // 0x80106FB8: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80106FBC: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80106FC0: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80106FC4: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80106FC8: nop

    // 0x80106FCC: bc1fl       L_80107014
    if (!c1cs) {
        // 0x80106FD0: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_80107014;
    }
    goto skip_0;
    // 0x80106FD0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80106FD4: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80106FD8: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80106FDC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80106FE0: nop

    // 0x80106FE4: bc1fl       L_80107014
    if (!c1cs) {
        // 0x80106FE8: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_80107014;
    }
    goto skip_1;
    // 0x80106FE8: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x80106FEC: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80106FF0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80106FF4: nop

    // 0x80106FF8: bc1fl       L_80107014
    if (!c1cs) {
        // 0x80106FFC: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_80107014;
    }
    goto skip_2;
    // 0x80106FFC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x80107000: jal         0x80106F2C
    // 0x80107004: nop

    grSectorArwingPrepareLaserCount(rdram, ctx);
        goto after_0;
    // 0x80107004: nop

    after_0:
    // 0x80107008: b           L_80107024
    // 0x8010700C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80107024;
    // 0x8010700C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80107010:
    // 0x80107010: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_80107014:
    // 0x80107014: bne         $v1, $zero, L_80106FB4
    if (ctx->r3 != 0) {
        // 0x80107018: nop
    
            goto L_80106FB4;
    }
    // 0x80107018: nop

L_8010701C:
    // 0x8010701C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80107020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80107024:
    // 0x80107024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107028: jr          $ra
    // 0x8010702C: nop

    return;
    // 0x8010702C: nop

;}
RECOMP_FUNC void ftKirbySpecialNCopyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162878: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016287C: jal         0x800DDDDC
    // 0x80162880: addiu       $a1, $a1, 0x2EC0
    ctx->r5 = ADD32(ctx->r5, 0X2EC0);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80162880: addiu       $a1, $a1, 0x2EC0
    ctx->r5 = ADD32(ctx->r5, 0X2EC0);
    after_0:
    // 0x80162884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016288C: jr          $ra
    // 0x80162890: nop

    return;
    // 0x80162890: nop

;}
RECOMP_FUNC void ftNessSpecialHiEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801544C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801544C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801544C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801544CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801544D0: jal         0x800DEEC8
    // 0x801544D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801544D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801544D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801544DC: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x801544E0: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x801544E4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801544E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801544EC: jal         0x800E6F24
    // 0x801544F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801544F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801544F4: jal         0x800D8EB8
    // 0x801544F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801544F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801544FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80154504: jr          $ra
    // 0x80154508: nop

    return;
    // 0x80154508: nop

;}
RECOMP_FUNC void itGBumperCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D590: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017D594: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017D598: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8017D59C: lhu         $a1, 0x350($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X350);
    // 0x8017D5A0: bne         $a1, $zero, L_8017D5D4
    if (ctx->r5 != 0) {
        // 0x8017D5A4: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017D5D4;
    }
    // 0x8017D5A4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8017D5A8: lw          $a0, 0x80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X80);
    // 0x8017D5AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D5B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D5B4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8017D5B8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017D5BC: nop

    // 0x8017D5C0: bc1fl       L_8017D5D8
    if (!c1cs) {
        // 0x8017D5C4: sh          $t6, 0x350($v0)
        MEM_H(0X350, ctx->r2) = ctx->r14;
            goto L_8017D5D8;
    }
    goto skip_0;
    // 0x8017D5C4: sh          $t6, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r14;
    skip_0:
    // 0x8017D5C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D5CC: b           L_8017D5D8
    // 0x8017D5D0: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
        goto L_8017D5D8;
    // 0x8017D5D0: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
L_8017D5D4:
    // 0x8017D5D4: sh          $t6, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r14;
L_8017D5D8:
    // 0x8017D5D8: lhu         $a0, 0x33E($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X33E);
    // 0x8017D5DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D5E0: beq         $a0, $zero, L_8017D624
    if (ctx->r4 == 0) {
        // 0x8017D5E4: subu        $t8, $t7, $a0
        ctx->r24 = SUB32(ctx->r15, ctx->r4);
            goto L_8017D624;
    }
    // 0x8017D5E4: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8017D5E8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8017D5EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D5F0: lwc1        $f18, -0x31E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X31E0);
    // 0x8017D5F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017D5F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D5FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D600: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017D604: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8017D608: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x8017D60C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017D610: lhu         $t9, 0x33E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X33E);
    // 0x8017D614: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017D618: sh          $t0, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r8;
    // 0x8017D61C: jr          $ra
    // 0x8017D620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017D620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017D624:
    // 0x8017D624: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017D628: nop

    // 0x8017D62C: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x8017D630: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017D634: jr          $ra
    // 0x8017D638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017D638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftDonkeySpecialNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AF1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AF20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AF24: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AF28: jal         0x800D9480
    // 0x8015AF2C: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AF2C: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    after_0:
    // 0x8015AF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AF38: jr          $ra
    // 0x8015AF3C: nop

    return;
    // 0x8015AF3C: nop

;}
RECOMP_FUNC void ftBossOkutsubushiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ACB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015ACB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015ACB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015ACBC: jal         0x800D9480
    // 0x8015ACC0: addiu       $a1, $a1, -0x5414
    ctx->r5 = ADD32(ctx->r5, -0X5414);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015ACC0: addiu       $a1, $a1, -0x5414
    ctx->r5 = ADD32(ctx->r5, -0X5414);
    after_0:
    // 0x8015ACC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015ACC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015ACCC: jr          $ra
    // 0x8015ACD0: nop

    return;
    // 0x8015ACD0: nop

;}
RECOMP_FUNC void gcDrawDObjTreeDLArray(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001535C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015364: lbu         $v0, 0x54($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X54);
    // 0x80015368: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001536C: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80015370: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80015374: bne         $t6, $zero, L_800154B0
    if (ctx->r14 != 0) {
        // 0x80015378: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_800154B0;
    }
    // 0x80015378: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001537C: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80015380: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80015384: beq         $s0, $zero, L_800153C4
    if (ctx->r16 == 0) {
        // 0x80015388: swc1        $f4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
            goto L_800153C4;
    }
    // 0x80015388: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8001538C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80015390: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80015394: beq         $t7, $zero, L_800153C4
    if (ctx->r15 == 0) {
        // 0x80015398: nop
    
            goto L_800153C4;
    }
    // 0x80015398: nop

    // 0x8001539C: bne         $t8, $zero, L_800153C4
    if (ctx->r24 != 0) {
        // 0x800153A0: lui         $a3, 0x8004
        ctx->r7 = S32(0X8004 << 16);
            goto L_800153C4;
    }
    // 0x800153A0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800153A4: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800153A8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800153AC: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800153B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800153B4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800153B8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800153BC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800153C0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800153C4:
    // 0x800153C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800153C8: addiu       $a0, $a3, 0x65B0
    ctx->r4 = ADD32(ctx->r7, 0X65B0);
    // 0x800153CC: jal         0x80010D70
    // 0x800153D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800153D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800153D4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800153D8: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x800153DC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800153E0: beq         $s0, $zero, L_8001543C
    if (ctx->r16 == 0) {
        // 0x800153E4: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_8001543C;
    }
    // 0x800153E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800153E8: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800153EC: beql        $t2, $zero, L_80015440
    if (ctx->r10 == 0) {
        // 0x800153F0: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80015440;
    }
    goto skip_0;
    // 0x800153F0: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x800153F4: lbu         $t3, 0x54($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X54);
    // 0x800153F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800153FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80015400: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80015404: bnel        $t4, $zero, L_80015440
    if (ctx->r12 != 0) {
        // 0x80015408: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80015440;
    }
    goto skip_1;
    // 0x80015408: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x8001540C: jal         0x80012D90
    // 0x80015410: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80015410: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x80015414: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015418: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x8001541C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80015420: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80015424: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x80015428: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001542C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80015430: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80015434: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80015438: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8001543C:
    // 0x8001543C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_80015440:
    // 0x80015440: beql        $a0, $zero, L_80015460
    if (ctx->r4 == 0) {
        // 0x80015444: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80015460;
    }
    goto skip_2;
    // 0x80015444: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80015448: jal         0x80015358
    // 0x8001544C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawDObjTreeDLArray(rdram, ctx);
        goto after_2;
    // 0x8001544C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80015450: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80015454: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80015458: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001545C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80015460:
    // 0x80015460: beql        $t8, $zero, L_800154A8
    if (ctx->r24 == 0) {
        // 0x80015464: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800154A8;
    }
    goto skip_3;
    // 0x80015464: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80015468: lw          $t9, 0x14($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X14);
    // 0x8001546C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015470: lui         $t2, 0xD838
    ctx->r10 = S32(0XD838 << 16);
    // 0x80015474: beql        $t9, $at, L_8001548C
    if (ctx->r25 == ctx->r1) {
        // 0x80015478: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_8001548C;
    }
    goto skip_4;
    // 0x80015478: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_4:
    // 0x8001547C: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    // 0x80015480: beql        $t0, $zero, L_800154A8
    if (ctx->r8 == 0) {
        // 0x80015484: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800154A8;
    }
    goto skip_5;
    // 0x80015484: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80015488: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_8001548C:
    // 0x8001548C: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x80015490: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80015494: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80015498: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8001549C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800154A0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800154A4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_800154A8:
    // 0x800154A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800154AC: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_800154B0:
    // 0x800154B0: lw          $t4, 0xC($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XC);
    // 0x800154B4: bnel        $t4, $zero, L_800154E0
    if (ctx->r12 != 0) {
        // 0x800154B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800154E0;
    }
    goto skip_6;
    // 0x800154B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800154BC: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x800154C0: beql        $s0, $zero, L_800154E0
    if (ctx->r16 == 0) {
        // 0x800154C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800154E0;
    }
    goto skip_7;
    // 0x800154C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_800154C8:
    // 0x800154C8: jal         0x80015358
    // 0x800154CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeDLArray(rdram, ctx);
        goto after_3;
    // 0x800154CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800154D0: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800154D4: bne         $s0, $zero, L_800154C8
    if (ctx->r16 != 0) {
        // 0x800154D8: nop
    
            goto L_800154C8;
    }
    // 0x800154D8: nop

    // 0x800154DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800154E0:
    // 0x800154E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800154E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800154E8: jr          $ra
    // 0x800154EC: nop

    return;
    // 0x800154EC: nop

;}
RECOMP_FUNC void wpMainStopFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167EB8: lw          $a1, 0x270($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X270);
    // 0x80167EBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167EC0: beql        $a1, $zero, L_80167EF4
    if (ctx->r5 == 0) {
        // 0x80167EC4: sw          $zero, 0x270($a2)
        MEM_W(0X270, ctx->r6) = 0;
            goto L_80167EF4;
    }
    goto skip_0;
    // 0x80167EC4: sw          $zero, 0x270($a2)
    MEM_W(0X270, ctx->r6) = 0;
    skip_0:
    // 0x80167EC8: lhu         $v0, 0x26($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X26);
    // 0x80167ECC: beql        $v0, $zero, L_80167EF4
    if (ctx->r2 == 0) {
        // 0x80167ED0: sw          $zero, 0x270($a2)
        MEM_W(0X270, ctx->r6) = 0;
            goto L_80167EF4;
    }
    goto skip_1;
    // 0x80167ED0: sw          $zero, 0x270($a2)
    MEM_W(0X270, ctx->r6) = 0;
    skip_1:
    // 0x80167ED4: lhu         $t6, 0x274($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X274);
    // 0x80167ED8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80167EDC: bnel        $t6, $v0, L_80167EF4
    if (ctx->r14 != ctx->r2) {
        // 0x80167EE0: sw          $zero, 0x270($a2)
        MEM_W(0X270, ctx->r6) = 0;
            goto L_80167EF4;
    }
    goto skip_2;
    // 0x80167EE0: sw          $zero, 0x270($a2)
    MEM_W(0X270, ctx->r6) = 0;
    skip_2:
    // 0x80167EE4: jal         0x80026738
    // 0x80167EE8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80167EE8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80167EEC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80167EF0: sw          $zero, 0x270($a2)
    MEM_W(0X270, ctx->r6) = 0;
L_80167EF4:
    // 0x80167EF4: sh          $zero, 0x274($a2)
    MEM_H(0X274, ctx->r6) = 0;
    // 0x80167EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167F00: jr          $ra
    // 0x80167F04: nop

    return;
    // 0x80167F04: nop

;}
RECOMP_FUNC void mnDataMakeSoundTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131FDC: jal         0x80009968
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FEC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FF0: sw          $v0, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = ctx->r2;
    // 0x80131FF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131FF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FFC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132000: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132004: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132008: jal         0x80009DF4
    // 0x8013200C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013200C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132010: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132014: lui         $a1, 0x428A
    ctx->r5 = S32(0X428A << 16);
    // 0x80132018: lui         $a2, 0x4308
    ctx->r6 = S32(0X4308 << 16);
    // 0x8013201C: jal         0x80131C24
    // 0x80132020: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    mnDataMakeOptionTab(rdram, ctx);
        goto after_2;
    // 0x80132020: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80132024: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132028: lw          $a1, 0x3078($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3078);
    // 0x8013202C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132030: xori        $a1, $a1, 0x2
    ctx->r5 = ctx->r5 ^ 0X2;
    // 0x80132034: jal         0x80131B4C
    // 0x80132038: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132038: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x8013203C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132040: lw          $t7, 0x3164($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3164);
    // 0x80132044: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132048: addiu       $t8, $t8, 0x1D20
    ctx->r24 = ADD32(ctx->r24, 0X1D20);
    // 0x8013204C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132050: jal         0x800CCFDC
    // 0x80132054: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132054: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80132058: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8013205C: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80132060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132064: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80132068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013206C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132070: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132074: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132078: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013207C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132080: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132084: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132088: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013208C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132098: jr          $ra
    // 0x8013209C: nop

    return;
    // 0x8013209C: nop

;}
RECOMP_FUNC void ftCommonAttack100StartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F0F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014F0F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F0FC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014F100: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014F104: jal         0x80146064
    // 0x8014F108: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014F108: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014F10C: bne         $v0, $zero, L_8014F1AC
    if (ctx->r2 != 0) {
        // 0x8014F110: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8014F1AC;
    }
    // 0x8014F110: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014F114: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8014F118: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8014F11C: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x8014F120: beq         $at, $zero, L_8014F174
    if (ctx->r1 == 0) {
        // 0x8014F124: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8014F174;
    }
    // 0x8014F124: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014F128: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F12C: addu        $at, $at, $t7
    gpr jr_addend_8014F134 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014F130: lw          $t7, -0x3CE0($at)
    ctx->r15 = ADD32(ctx->r1, -0X3CE0);
    // 0x8014F134: jr          $t7
    // 0x8014F138: nop

    switch (jr_addend_8014F134 >> 2) {
        case 0: goto L_8014F13C; break;
        case 1: goto L_8014F174; break;
        case 2: goto L_8014F174; break;
        case 3: goto L_8014F174; break;
        case 4: goto L_8014F148; break;
        case 5: goto L_8014F174; break;
        case 6: goto L_8014F16C; break;
        case 7: goto L_8014F154; break;
        case 8: goto L_8014F174; break;
        case 9: goto L_8014F160; break;
        case 10: goto L_8014F174; break;
        case 11: goto L_8014F174; break;
        case 12: goto L_8014F174; break;
        case 13: goto L_8014F174; break;
        case 14: goto L_8014F13C; break;
        case 15: goto L_8014F174; break;
        case 16: goto L_8014F174; break;
        case 17: goto L_8014F174; break;
        case 18: goto L_8014F148; break;
        case 19: goto L_8014F174; break;
        case 20: goto L_8014F16C; break;
        case 21: goto L_8014F154; break;
        case 22: goto L_8014F174; break;
        case 23: goto L_8014F160; break;
        default: switch_error(__func__, 0x8014F134, 0x8018C320);
    }
    // 0x8014F138: nop

L_8014F13C:
    // 0x8014F13C: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x8014F140: b           L_8014F174
    // 0x8014F144: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8014F174;
    // 0x8014F144: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8014F148:
    // 0x8014F148: addiu       $t9, $zero, 0xDD
    ctx->r25 = ADD32(0, 0XDD);
    // 0x8014F14C: b           L_8014F174
    // 0x8014F150: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8014F174;
    // 0x8014F150: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8014F154:
    // 0x8014F154: addiu       $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
    // 0x8014F158: b           L_8014F174
    // 0x8014F15C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8014F174;
    // 0x8014F15C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8014F160:
    // 0x8014F160: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x8014F164: b           L_8014F174
    // 0x8014F168: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_8014F174;
    // 0x8014F168: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_8014F16C:
    // 0x8014F16C: addiu       $t2, $zero, 0xDD
    ctx->r10 = ADD32(0, 0XDD);
    // 0x8014F170: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8014F174:
    // 0x8014F174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014F178: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8014F17C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014F180: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014F184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014F188: jal         0x800E6F24
    // 0x8014F18C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014F18C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014F190: jal         0x800E0830
    // 0x8014F194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014F194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014F198: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014F19C: sw          $zero, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = 0;
    // 0x8014F1A0: sw          $zero, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = 0;
    // 0x8014F1A4: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8014F1A8: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
L_8014F1AC:
    // 0x8014F1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F1B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014F1B4: jr          $ra
    // 0x8014F1B8: nop

    return;
    // 0x8014F1B8: nop

;}
RECOMP_FUNC void ftMarioSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155E64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80155E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155E6C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155E70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80155E74: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x80155E78: beql        $t6, $zero, L_80155EF8
    if (ctx->r14 == 0) {
        // 0x80155E7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80155EF8;
    }
    goto skip_0;
    // 0x80155E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80155E80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80155E84: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80155E88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80155E8C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80155E90: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80155E94: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80155E98: lw          $a0, 0x928($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X928);
    // 0x80155E9C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80155EA0: jal         0x800EDF24
    // 0x80155EA4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80155EA4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80155EA8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80155EAC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80155EB0: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80155EB4: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x80155EB8: beq         $at, $zero, L_80155EE4
    if (ctx->r1 == 0) {
        // 0x80155EBC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80155EE4;
    }
    // 0x80155EBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80155EC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80155EC4: addu        $at, $at, $t7
    gpr jr_addend_80155ECC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80155EC8: lw          $t7, -0x39D0($at)
    ctx->r15 = ADD32(ctx->r1, -0X39D0);
    // 0x80155ECC: jr          $t7
    // 0x80155ED0: nop

    switch (jr_addend_80155ECC >> 2) {
        case 0: goto L_80155ED4; break;
        case 1: goto L_80155EE4; break;
        case 2: goto L_80155EE4; break;
        case 3: goto L_80155EE4; break;
        case 4: goto L_80155EDC; break;
        case 5: goto L_80155EE4; break;
        case 6: goto L_80155EE4; break;
        case 7: goto L_80155EE4; break;
        case 8: goto L_80155EE4; break;
        case 9: goto L_80155EE4; break;
        case 10: goto L_80155EE4; break;
        case 11: goto L_80155EE4; break;
        case 12: goto L_80155EE4; break;
        case 13: goto L_80155ED4; break;
        case 14: goto L_80155ED4; break;
        case 15: goto L_80155EE4; break;
        case 16: goto L_80155EE4; break;
        case 17: goto L_80155EE4; break;
        case 18: goto L_80155EDC; break;
        default: switch_error(__func__, 0x80155ECC, 0x8018C630);
    }
    // 0x80155ED0: nop

L_80155ED4:
    // 0x80155ED4: b           L_80155EE4
    // 0x80155ED8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_80155EE4;
    // 0x80155ED8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80155EDC:
    // 0x80155EDC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80155EE0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80155EE4:
    // 0x80155EE4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80155EE8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80155EEC: jal         0x801687A0
    // 0x80155EF0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    wpMarioFireballMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80155EF0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80155EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155EF8:
    // 0x80155EF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80155EFC: jr          $ra
    // 0x80155F00: nop

    return;
    // 0x80155F00: nop

;}
RECOMP_FUNC void func_ovl8_80373930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373938: beq         $a1, $zero, L_80373958
    if (ctx->r5 == 0) {
        // 0x8037393C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80373958;
    }
    // 0x8037393C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80373940: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80373944: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80373948: jal         0x80377044
    // 0x8037394C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    stringCopyCount(rdram, ctx);
        goto after_0;
    // 0x8037394C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80373950: b           L_8037395C
    // 0x80373954: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_8037395C;
    // 0x80373954: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80373958:
    // 0x80373958: sb          $zero, 0xC($a3)
    MEM_B(0XC, ctx->r7) = 0;
L_8037395C:
    // 0x8037395C: lw          $v0, 0x30($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X30);
    // 0x80373960: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80373964: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80373968: jalr        $t9
    // 0x8037396C: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037396C: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    after_1:
    // 0x80373970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373978: jr          $ra
    // 0x8037397C: nop

    return;
    // 0x8037397C: nop

;}
RECOMP_FUNC void ftDonkeySpecialNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B51C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B524: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B528: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8015B52C: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015B530: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B534: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B538: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B53C: bne         $t6, $at, L_8015B54C
    if (ctx->r14 != ctx->r1) {
        // 0x8015B540: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8015B54C;
    }
    // 0x8015B540: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015B544: b           L_8015B54C
    // 0x8015B548: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
        goto L_8015B54C;
    // 0x8015B548: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
L_8015B54C:
    // 0x8015B54C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B550: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8015B554: jal         0x800E6F24
    // 0x8015B558: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B558: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B55C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015B560: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8015B564: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015B568: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
    // 0x8015B56C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B570: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8015B574: nop

    // 0x8015B578: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015B57C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015B580: jal         0x8015B508
    // 0x8015B584: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    ftDonkeySpecialNGetStatusChargeLevelReset(rdram, ctx);
        goto after_1;
    // 0x8015B584: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    after_1:
    // 0x8015B588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B58C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B590: jr          $ra
    // 0x8015B594: nop

    return;
    // 0x8015B594: nop

;}
RECOMP_FUNC void mnPlayersVSShutter3PProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013321C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133220: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x80133224: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x80133228: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x8013322C: jal         0x800CD1F0
    // 0x80133230: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_0;
    // 0x80133230: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    after_0:
    // 0x80133234: jal         0x800CCF00
    // 0x80133238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80133238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013323C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80133240: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x80133244: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80133248: jal         0x800CD1F0
    // 0x8013324C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_2;
    // 0x8013324C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_2:
    // 0x80133250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133258: jr          $ra
    // 0x8013325C: nop

    return;
    // 0x8013325C: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiBoundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C8BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015C8C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015C8C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015C8C8: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8015C8CC: beql        $t6, $zero, L_8015C914
    if (ctx->r14 == 0) {
        // 0x8015C8D0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8015C914;
    }
    goto skip_0;
    // 0x8015C8D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8015C8D4: lw          $t7, 0x14C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14C);
    // 0x8015C8D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C8DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8015C8E0: bne         $t7, $at, L_8015C910
    if (ctx->r15 != ctx->r1) {
        // 0x8015C8E4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8015C910;
    }
    // 0x8015C8E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8015C8E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C8EC: lwc1        $f4, -0x3760($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3760);
    // 0x8015C8F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8015C8F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8015C8F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015C8FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015C900: jal         0x801438F0
    // 0x8015C904: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015C904: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8015C908: b           L_8015C970
    // 0x8015C90C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8015C970;
    // 0x8015C90C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015C910:
    // 0x8015C910: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8015C914:
    // 0x8015C914: lwc1        $f8, 0x78($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015C918: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8015C91C: nop

    // 0x8015C920: bc1fl       L_8015C970
    if (!c1cs) {
        // 0x8015C924: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015C970;
    }
    goto skip_1;
    // 0x8015C924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8015C928: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x8015C92C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C930: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8015C934: bne         $t9, $at, L_8015C964
    if (ctx->r25 != ctx->r1) {
        // 0x8015C938: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8015C964;
    }
    // 0x8015C938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8015C93C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C940: lwc1        $f10, -0x375C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X375C);
    // 0x8015C944: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8015C948: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8015C94C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015C950: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015C954: jal         0x801438F0
    // 0x8015C958: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015C958: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8015C95C: b           L_8015C970
    // 0x8015C960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8015C970;
    // 0x8015C960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015C964:
    // 0x8015C964: jal         0x8013E1C8
    // 0x8015C968: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015C968: nop

    after_2:
    // 0x8015C96C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015C970:
    // 0x8015C970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015C974: jr          $ra
    // 0x8015C978: nop

    return;
    // 0x8015C978: nop

;}
RECOMP_FUNC void mnVSRecordGetUsePercent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013497C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134980: jal         0x80134934
    // 0x80134984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnVSRecordGetGamesPlayedSum(rdram, ctx);
        goto after_0;
    // 0x80134984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80134988: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8013498C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134990: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134994: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80134998: nop

    // 0x8013499C: bc1tl       L_80134A00
    if (c1cs) {
        // 0x801349A0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80134A00;
    }
    goto skip_0;
    // 0x801349A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x801349A4: jal         0x80134934
    // 0x801349A8: nop

    mnVSRecordGetGamesPlayedSum(rdram, ctx);
        goto after_1;
    // 0x801349A8: nop

    after_1:
    // 0x801349AC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801349B0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x801349B4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801349B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801349BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801349C0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801349C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801349C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801349CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801349D0: lhu         $t8, 0x4508($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X4508);
    // 0x801349D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801349D8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801349DC: bgez        $t8, L_801349F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801349E0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801349F4;
    }
    // 0x801349E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801349E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801349E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801349EC: nop

    // 0x801349F0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801349F4:
    // 0x801349F4: b           L_80134A00
    // 0x801349F8: div.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
        goto L_80134A00;
    // 0x801349F8: div.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801349FC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80134A00:
    // 0x80134A00: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80134A04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134A10: mul.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80134A14: jr          $ra
    // 0x80134A18: nop

    return;
    // 0x80134A18: nop

;}
RECOMP_FUNC void ifCommonBattlePauseDecalMakeSObjID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113D60: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80113D64: addiu       $t7, $t7, -0x103C
    ctx->r15 = ADD32(ctx->r15, -0X103C);
    // 0x80113D68: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80113D6C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80113D70: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80113D74: lw          $t9, 0xD54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD54);
    // 0x80113D78: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80113D7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80113D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113D84: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80113D88: jal         0x800CCFDC
    // 0x80113D8C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80113D8C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80113D90: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80113D94: addiu       $t8, $zero, 0x201
    ctx->r24 = ADD32(0, 0X201);
    // 0x80113D98: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80113D9C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80113DA0: nop

    // 0x80113DA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80113DA8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80113DAC: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80113DB0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80113DB4: nop

    // 0x80113DB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80113DBC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80113DC0: lbu         $t2, 0x8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X8);
    // 0x80113DC4: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80113DC8: lbu         $t3, 0x9($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X9);
    // 0x80113DCC: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80113DD0: lbu         $t4, 0xA($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XA);
    // 0x80113DD4: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80113DD8: lbu         $t5, 0xB($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XB);
    // 0x80113DDC: sb          $t5, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r13;
    // 0x80113DE0: lbu         $t6, 0xC($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XC);
    // 0x80113DE4: sb          $t6, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r14;
    // 0x80113DE8: lbu         $t7, 0xD($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XD);
    // 0x80113DEC: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80113DF0: sb          $t7, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r15;
    // 0x80113DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80113DFC: jr          $ra
    // 0x80113E00: nop

    return;
    // 0x80113E00: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePlayerKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132CA4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132CA8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132CAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132CB0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80132CB4: addiu       $t7, $t7, -0x7DDC
    ctx->r15 = ADD32(ctx->r15, -0X7DDC);
    // 0x80132CB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132CBC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132CC0: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80132CC4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132CC8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132CCC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132CD0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132CD4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132CD8: addiu       $t1, $t1, -0x7DCC
    ctx->r9 = ADD32(ctx->r9, -0X7DCC);
    // 0x80132CDC: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132CE0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132CE4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80132CE8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132CEC: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80132CF0: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132CF4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80132CF8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80132CFC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D08: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80132D0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132D10: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132D14: jal         0x80009968
    // 0x80132D18: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132D18: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x80132D1C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80132D20: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132D24: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132D28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80132D2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80132D30: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80132D34: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80132D38: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80132D3C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80132D40: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132D44: sw          $v0, -0x7A78($at)
    MEM_W(-0X7A78, ctx->r1) = ctx->r2;
    // 0x80132D48: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132D4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D50: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D58: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132D5C: jal         0x80009DF4
    // 0x80132D60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132D60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132D64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132D68: lw          $v0, -0x776C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X776C);
    // 0x80132D6C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80132D70: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132D74: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80132D78: bne         $t7, $v0, L_80132DCC
    if (ctx->r15 != ctx->r2) {
        // 0x80132D7C: lui         $t5, 0x0
        ctx->r13 = S32(0X0 << 16);
            goto L_80132DCC;
    }
    // 0x80132D7C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132D80: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80132D84: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80132D88: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80132D8C: lw          $t0, -0x7368($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7368);
    // 0x80132D90: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x80132D94: jal         0x800CCFDC
    // 0x80132D98: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132D98: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x80132D9C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80132DA0: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x80132DA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DA8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132DAC: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x80132DB0: lwc1        $f4, 0x28($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X28);
    // 0x80132DB4: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x80132DB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132DBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132DC0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132DC4: b           L_80132DF4
    // 0x80132DC8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
        goto L_80132DF4;
    // 0x80132DC8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
L_80132DCC:
    // 0x80132DCC: lw          $t4, -0x7368($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7368);
    // 0x80132DD0: addiu       $t5, $t5, 0xFF8
    ctx->r13 = ADD32(ctx->r13, 0XFF8);
    // 0x80132DD4: jal         0x800CCFDC
    // 0x80132DD8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132DD8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80132DDC: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80132DE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132DE4: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80132DE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132DEC: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132DF0: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_80132DF4:
    // 0x80132DF4: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132DF8: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132DFC: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132E00: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132E04: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132E08: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132E0C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132E10: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132E18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132E1C: jr          $ra
    // 0x80132E20: nop

    return;
    // 0x80132E20: nop

;}
RECOMP_FUNC void itLizardonAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F5EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017F5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F5F4: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017F5F8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017F5FC: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8017F600: addiu       $t0, $a3, 0x1C
    ctx->r8 = ADD32(ctx->r7, 0X1C);
    // 0x8017F604: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8017F608: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8017F60C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8017F610: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017F614: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8017F618: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8017F61C: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8017F620: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8017F624: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8017F628: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017F62C: bne         $t9, $at, L_8017F66C
    if (ctx->r25 != ctx->r1) {
        // 0x8017F630: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8017F66C;
    }
    // 0x8017F630: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8017F634: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F638: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017F63C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F640: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017F644: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017F648: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017F64C: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    // 0x8017F650: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8017F654: nop

    // 0x8017F658: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017F65C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017F660: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8017F664: b           L_8017F690
    // 0x8017F668: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
        goto L_8017F690;
    // 0x8017F668: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_8017F66C:
    // 0x8017F66C: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x8017F670: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017F674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F678: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8017F67C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017F680: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017F684: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017F688: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017F68C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_8017F690:
    // 0x8017F690: lhu         $v0, 0x35E($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X35E);
    // 0x8017F694: bnel        $v0, $zero, L_8017F6CC
    if (ctx->r2 != 0) {
        // 0x8017F698: lhu         $t5, 0x33E($v1)
        ctx->r13 = MEM_HU(ctx->r3, 0X33E);
            goto L_8017F6CC;
    }
    goto skip_0;
    // 0x8017F698: lhu         $t5, 0x33E($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X33E);
    skip_0:
    // 0x8017F69C: lw          $a2, 0x24($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X24);
    // 0x8017F6A0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8017F6A4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8017F6A8: jal         0x8017FD2C
    // 0x8017F6AC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    itLizardonAttackMakeFlame(rdram, ctx);
        goto after_0;
    // 0x8017F6AC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017F6B0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8017F6B4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8017F6B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017F6BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017F6C0: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x8017F6C4: sh          $t3, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r11;
    // 0x8017F6C8: lhu         $t5, 0x33E($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X33E);
L_8017F6CC:
    // 0x8017F6CC: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8017F6D0: sh          $t4, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = ctx->r12;
    // 0x8017F6D4: bnel        $t5, $zero, L_8017F6E8
    if (ctx->r13 != 0) {
        // 0x8017F6D8: lhu         $t6, 0x35C($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X35C);
            goto L_8017F6E8;
    }
    goto skip_1;
    // 0x8017F6D8: lhu         $t6, 0x35C($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X35C);
    skip_1:
    // 0x8017F6DC: b           L_8017F7D8
    // 0x8017F6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017F7D8;
    // 0x8017F6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017F6E4: lhu         $t6, 0x35C($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X35C);
L_8017F6E8:
    // 0x8017F6E8: bnel        $t6, $zero, L_8017F7C0
    if (ctx->r14 != 0) {
        // 0x8017F6EC: lhu         $t2, 0x35C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X35C);
            goto L_8017F7C0;
    }
    goto skip_2;
    // 0x8017F6EC: lhu         $t2, 0x35C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X35C);
    skip_2:
    // 0x8017F6F0: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x8017F6F4: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x8017F6F8: sh          $t7, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r15;
    // 0x8017F6FC: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8017F700: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x8017F704: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8017F708: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x8017F70C: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8017F710: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8017F714: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8017F718: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8017F71C: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x8017F720: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8017F724: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x8017F728: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017F72C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017F730: lh          $t5, 0x2E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2E);
    // 0x8017F734: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8017F738: nop

    // 0x8017F73C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017F740: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F744: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8017F748: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017F74C: lw          $t6, 0x2D4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017F750: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x8017F754: lh          $t7, 0x30($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X30);
    // 0x8017F758: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8017F75C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8017F760: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8017F764: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017F768: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017F76C: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8017F770: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017F774: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8017F778: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8017F77C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017F780: lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X24);
    // 0x8017F784: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8017F788: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8017F78C: jal         0x800FF278
    // 0x8017F790: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerDustHeavyMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017F790: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_1:
    // 0x8017F794: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8017F798: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8017F79C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017F7A0: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8017F7A4: bne         $t1, $at, L_8017F7BC
    if (ctx->r9 != ctx->r1) {
        // 0x8017F7A8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8017F7BC;
    }
    // 0x8017F7A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017F7AC: lwc1        $f10, -0x3190($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3190);
    // 0x8017F7B0: lwc1        $f18, 0x34($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8017F7B4: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017F7B8: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
L_8017F7BC:
    // 0x8017F7BC: lhu         $t2, 0x35C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X35C);
L_8017F7C0:
    // 0x8017F7C0: lhu         $t4, 0x33E($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017F7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F7C8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8017F7CC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8017F7D0: sh          $t3, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r11;
    // 0x8017F7D4: sh          $t5, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r13;
L_8017F7D8:
    // 0x8017F7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F7DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017F7E0: jr          $ra
    // 0x8017F7E4: nop

    return;
    // 0x8017F7E4: nop

;}
RECOMP_FUNC void itSpearFlySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180168: jal         0x8018010C
    // 0x8018016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itSpearFlyInitVars(rdram, ctx);
        goto after_0;
    // 0x8018016C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80180170: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80180174: addiu       $a1, $a1, -0x51CC
    ctx->r5 = ADD32(ctx->r5, -0X51CC);
    // 0x80180178: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018017C: jal         0x80172EC8
    // 0x80180180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80180180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80180184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018018C: jr          $ra
    // 0x80180190: nop

    return;
    // 0x80180190: nop

;}
RECOMP_FUNC void sc1PIntroVSFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132F88: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132F8C: lw          $a3, 0x5C28($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5C28);
    // 0x80132F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132F94: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80132F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132F9C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132FA0: beq         $a3, $at, L_80132FC8
    if (ctx->r7 == ctx->r1) {
        // 0x80132FA4: lw          $a1, 0x178($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X178);
            goto L_80132FC8;
    }
    // 0x80132FA4: lw          $a1, 0x178($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X178);
    // 0x80132FA8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80132FAC: beq         $a3, $at, L_80132FF4
    if (ctx->r7 == ctx->r1) {
        // 0x80132FB0: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80132FF4;
    }
    // 0x80132FB0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80132FB4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80132FB8: beql        $a3, $at, L_80133074
    if (ctx->r7 == ctx->r1) {
        // 0x80132FBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133074;
    }
    goto skip_0;
    // 0x80132FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132FC0: b           L_80133020
    // 0x80132FC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_80133020;
    // 0x80132FC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80132FC8:
    // 0x80132FC8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132FCC: lw          $t7, 0x5CF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5CF8);
    // 0x80132FD0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80132FD4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80132FD8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80132FDC: beq         $at, $zero, L_80132FEC
    if (ctx->r1 == 0) {
        // 0x80132FE0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80132FEC;
    }
    // 0x80132FE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132FE4: b           L_80133070
    // 0x80132FE8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80133070;
    // 0x80132FE8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80132FEC:
    // 0x80132FEC: b           L_80133070
    // 0x80132FF0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
        goto L_80133070;
    // 0x80132FF0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80132FF4:
    // 0x80132FF4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132FF8: lw          $t0, 0x5CF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5CF8);
    // 0x80132FFC: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80133000: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80133004: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80133008: beq         $at, $zero, L_80133018
    if (ctx->r1 == 0) {
        // 0x8013300C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80133018;
    }
    // 0x8013300C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133010: b           L_80133070
    // 0x80133014: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80133070;
    // 0x80133014: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80133018:
    // 0x80133018: b           L_80133070
    // 0x8013301C: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
        goto L_80133070;
    // 0x8013301C: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
L_80133020:
    // 0x80133020: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80133024: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80133028: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8013302C: nop

    // 0x80133030: bc1fl       L_80133074
    if (!c1cs) {
        // 0x80133034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133074;
    }
    goto skip_1;
    // 0x80133034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80133038: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    // 0x8013303C: jal         0x80132F40
    // 0x80133040: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sc1PIntroGetVSFighterVelocityZ(rdram, ctx);
        goto after_0;
    // 0x80133040: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80133044: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80133048: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8013304C: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80133050: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80133054: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80133058: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8013305C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80133060: nop

    // 0x80133064: bc1fl       L_80133074
    if (!c1cs) {
        // 0x80133068: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133074;
    }
    goto skip_2;
    // 0x80133068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8013306C: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
L_80133070:
    // 0x80133070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133074:
    // 0x80133074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133078: jr          $ra
    // 0x8013307C: nop

    return;
    // 0x8013307C: nop

;}
RECOMP_FUNC void itTosakintoBounceInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E93C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017E940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E944: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017E948: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017E94C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8017E950: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x8017E954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E958: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017E95C: sw          $t7, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r15;
    // 0x8017E960: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x8017E964: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E968: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8017E96C: sw          $t6, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r14;
    // 0x8017E970: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x8017E974: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8017E978: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017E97C: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017E980: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x8017E984: bne         $t8, $at, L_8017EA04
    if (ctx->r24 != ctx->r1) {
        // 0x8017E988: sw          $t7, 0x358($v0)
        MEM_W(0X358, ctx->r2) = ctx->r15;
            goto L_8017EA04;
    }
    // 0x8017E988: sw          $t7, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r15;
    // 0x8017E98C: lw          $t9, 0x2D4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017E990: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8017E994: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8017E998: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8017E99C: addiu       $t0, $t0, -0x48F8
    ctx->r8 = ADD32(ctx->r8, -0X48F8);
    // 0x8017E9A0: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x8017E9A4: addiu       $t3, $t3, -0x4834
    ctx->r11 = ADD32(ctx->r11, -0X4834);
    // 0x8017E9A8: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x8017E9AC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x8017E9B0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8017E9B4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8017E9B8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8017E9BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017E9C0: jal         0x8000BD1C
    // 0x8017E9C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017E9C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x8017E9C8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017E9CC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8017E9D0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017E9D4: lw          $t4, 0x2D4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017E9D8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8017E9DC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8017E9E0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8017E9E4: addiu       $t7, $t7, -0x46F4
    ctx->r15 = ADD32(ctx->r15, -0X46F4);
    // 0x8017E9E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017E9EC: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x8017E9F0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8017E9F4: jal         0x8000BD54
    // 0x8017E9F8: lw          $a0, 0x80($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X80);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017E9F8: lw          $a0, 0x80($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X80);
    after_1:
    // 0x8017E9FC: jal         0x8000DF34
    // 0x8017EA00: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8017EA00: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
L_8017EA04:
    // 0x8017EA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EA08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017EA0C: jr          $ra
    // 0x8017EA10: nop

    return;
    // 0x8017EA10: nop

;}
RECOMP_FUNC void ftParamInitPlayerBattleStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7C4C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800E7C50: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800E7C54: addiu       $t0, $t0, 0x50E8
    ctx->r8 = ADD32(ctx->r8, 0X50E8);
    // 0x800E7C58: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800E7C5C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800E7C60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E7C64: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800E7C68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E7C6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E7C70: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800E7C74: sb          $zero, 0x2D($t7)
    MEM_B(0X2D, ctx->r15) = 0;
    // 0x800E7C78: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800E7C7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E7C80: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800E7C84: sw          $zero, 0x34($t9)
    MEM_W(0X34, ctx->r25) = 0;
    // 0x800E7C88: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800E7C8C: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x800E7C90: lw          $t2, 0x34($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X34);
    // 0x800E7C94: sw          $t2, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r10;
L_800E7C98:
    // 0x800E7C98: sll         $t4, $a0, 3
    ctx->r12 = S32(ctx->r4 << 3);
    // 0x800E7C9C: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800E7CA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800E7CA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E7CA8: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800E7CAC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E7CB0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800E7CB4: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x800E7CB8: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800E7CBC: sw          $zero, 0x38($t6)
    MEM_W(0X38, ctx->r14) = 0;
    // 0x800E7CC0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800E7CC4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800E7CC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E7CCC: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800E7CD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E7CD4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800E7CD8: addu        $t1, $t9, $a3
    ctx->r9 = ADD32(ctx->r25, ctx->r7);
    // 0x800E7CDC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800E7CE0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800E7CE4: bne         $at, $zero, L_800E7C98
    if (ctx->r1 != 0) {
        // 0x800E7CE8: sw          $zero, 0x5C($t1)
        MEM_W(0X5C, ctx->r9) = 0;
            goto L_800E7C98;
    }
    // 0x800E7CE8: sw          $zero, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = 0;
    // 0x800E7CEC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800E7CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800E7CF4: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x800E7CF8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800E7CFC: sw          $zero, 0x50($t3)
    MEM_W(0X50, ctx->r11) = 0;
    // 0x800E7D00: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D04: addu        $v1, $t4, $v0
    ctx->r3 = ADD32(ctx->r12, ctx->r2);
    // 0x800E7D08: lw          $a1, 0x50($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X50);
    // 0x800E7D0C: sw          $a1, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r5;
    // 0x800E7D10: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D14: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800E7D18: sw          $a1, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r5;
    // 0x800E7D1C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D20: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E7D24: sw          $zero, 0x58($t8)
    MEM_W(0X58, ctx->r24) = 0;
    // 0x800E7D28: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D2C: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x800E7D30: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800E7D34: sw          $t1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r9;
    // 0x800E7D38: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D3C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800E7D40: sw          $zero, 0x74($t3)
    MEM_W(0X74, ctx->r11) = 0;
    // 0x800E7D44: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D48: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800E7D4C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800E7D50: addu        $v1, $t4, $v0
    ctx->r3 = ADD32(ctx->r12, ctx->r2);
    // 0x800E7D54: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x800E7D58: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E7D5C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x800E7D60: sw          $t5, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r13;
    // 0x800E7D64: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D68: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800E7D6C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E7D70: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E7D74: sw          $t6, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->r14;
    // 0x800E7D78: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D7C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800E7D80: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800E7D84: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800E7D88: sw          $zero, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = 0;
    // 0x800E7D8C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800E7D90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E7D94: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800E7D98: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800E7D9C: sh          $zero, 0x80($t4)
    MEM_H(0X80, ctx->r12) = 0;
    // 0x800E7DA0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800E7DA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E7DA8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800E7DAC: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800E7DB0: sh          $zero, 0x82($t6)
    MEM_H(0X82, ctx->r14) = 0;
    // 0x800E7DB4: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800E7DB8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800E7DBC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E7DC0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800E7DC4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E7DC8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800E7DCC: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x800E7DD0: sll         $t4, $a0, 3
    ctx->r12 = S32(ctx->r4 << 3);
    // 0x800E7DD4: sh          $zero, 0x80($t2)
    MEM_H(0X80, ctx->r10) = 0;
    // 0x800E7DD8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800E7DDC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800E7DE0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E7DE4: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800E7DE8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E7DEC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800E7DF0: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800E7DF4: addu        $t7, $t5, $a3
    ctx->r15 = ADD32(ctx->r13, ctx->r7);
    // 0x800E7DF8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800E7DFC: sh          $zero, 0x82($t7)
    MEM_H(0X82, ctx->r15) = 0;
    // 0x800E7E00: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800E7E04: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E7E08: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800E7E0C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E7E10: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800E7E14: addu        $t1, $t9, $a3
    ctx->r9 = ADD32(ctx->r25, ctx->r7);
    // 0x800E7E18: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800E7E1C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800E7E20: sh          $zero, 0x84($t1)
    MEM_H(0X84, ctx->r9) = 0;
    // 0x800E7E24: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800E7E28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E7E2C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x800E7E30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E7E34: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800E7E38: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x800E7E3C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800E7E40: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E7E44: sh          $zero, 0x86($t5)
    MEM_H(0X86, ctx->r13) = 0;
    // 0x800E7E48: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800E7E4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E7E50: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800E7E54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E7E58: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800E7E5C: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800E7E60: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x800E7E64: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x800E7E68: sh          $zero, 0x88($t9)
    MEM_H(0X88, ctx->r25) = 0;
    // 0x800E7E6C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800E7E70: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800E7E74: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x800E7E78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800E7E7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800E7E80: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x800E7E84: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800E7E88: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800E7E8C: sh          $zero, 0x8A($t4)
    MEM_H(0X8A, ctx->r12) = 0;
    // 0x800E7E90: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800E7E94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E7E98: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800E7E9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E7EA0: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800E7EA4: addu        $t8, $t6, $a3
    ctx->r24 = ADD32(ctx->r14, ctx->r7);
    // 0x800E7EA8: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x800E7EAC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800E7EB0: sh          $zero, 0x8C($t8)
    MEM_H(0X8C, ctx->r24) = 0;
    // 0x800E7EB4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800E7EB8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E7EBC: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800E7EC0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800E7EC4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800E7EC8: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x800E7ECC: jr          $ra
    // 0x800E7ED0: sh          $zero, 0x8E($t3)
    MEM_H(0X8E, ctx->r11) = 0;
    return;
    // 0x800E7ED0: sh          $zero, 0x8E($t3)
    MEM_H(0X8E, ctx->r11) = 0;
;}
RECOMP_FUNC void itTomatoMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174624: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80174628: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8017462C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80174630: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80174634: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80174638: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8017463C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80174640: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174644: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80174648: addiu       $a1, $a1, -0x68D0
    ctx->r5 = ADD32(ctx->r5, -0X68D0);
    // 0x8017464C: jal         0x8016E174
    // 0x80174650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80174650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80174654: beq         $v0, $zero, L_801746DC
    if (ctx->r2 == 0) {
        // 0x80174658: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801746DC;
    }
    // 0x80174658: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017465C: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80174660: lw          $a3, 0x84($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X84);
    // 0x80174664: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80174668: addiu       $t0, $a0, 0x1C
    ctx->r8 = ADD32(ctx->r4, 0X1C);
    // 0x8017466C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80174670: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80174674: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80174678: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8017467C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80174680: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80174684: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x80174688: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8017468C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80174690: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80174694: jal         0x80008CC0
    // 0x80174698: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80174698: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017469C: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x801746A0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801746A4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801746A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801746AC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801746B0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801746B4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801746B8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801746BC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801746C0: lbu         $t5, 0x2D3($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X2D3);
    // 0x801746C4: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x801746C8: jal         0x80111EC0
    // 0x801746CC: sb          $t6, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r14;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_2;
    // 0x801746CC: sb          $t6, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r14;
    after_2:
    // 0x801746D0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801746D4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x801746D8: sw          $v0, 0x348($a3)
    MEM_W(0X348, ctx->r7) = ctx->r2;
L_801746DC:
    // 0x801746DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801746E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801746E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801746E8: jr          $ra
    // 0x801746EC: nop

    return;
    // 0x801746EC: nop

;}
RECOMP_FUNC void func_ovl8_80373D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373D88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80373D8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80373D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80373D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373D98: beq         $a0, $zero, L_80373E10
    if (ctx->r4 == 0) {
        // 0x80373D9C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80373E10;
    }
    // 0x80373D9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80373DA0: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80373DA4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80373DA8: addiu       $t6, $t6, -0x6D10
    ctx->r14 = ADD32(ctx->r14, -0X6D10);
    // 0x80373DAC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80373DB0: addiu       $t7, $t7, -0x6C38
    ctx->r15 = ADD32(ctx->r15, -0X6C38);
    // 0x80373DB4: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80373DB8: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80373DBC: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80373DC0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80373DC4: addiu       $t9, $t9, -0x6AE0
    ctx->r25 = ADD32(ctx->r25, -0X6AE0);
    // 0x80373DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373DCC: jal         0x8037354C
    // 0x80373DD0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_8037354C(rdram, ctx);
        goto after_0;
    // 0x80373DD0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x80373DD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80373DD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373DDC: beql        $t1, $zero, L_80373DFC
    if (ctx->r9 == 0) {
        // 0x80373DE0: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80373DFC;
    }
    goto skip_0;
    // 0x80373DE0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80373DE4: jal         0x8037C30C
    // 0x80373DE8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x80373DE8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80373DEC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80373DF0: jal         0x803718C4
    // 0x80373DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80373DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80373DF8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_80373DFC:
    // 0x80373DFC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80373E00: beql        $t3, $zero, L_80373E14
    if (ctx->r11 == 0) {
        // 0x80373E04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80373E14;
    }
    goto skip_1;
    // 0x80373E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80373E08: jal         0x803717C0
    // 0x80373E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80373E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80373E10:
    // 0x80373E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80373E14:
    // 0x80373E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80373E1C: jr          $ra
    // 0x80373E20: nop

    return;
    // 0x80373E20: nop

;}
RECOMP_FUNC void ftCommonCliffCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144CF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80144CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144D00: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80144D04: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80144D08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144D0C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80144D10: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x80144D14: bnel        $t7, $at, L_80144D38
    if (ctx->r15 != ctx->r1) {
        // 0x80144D18: lw          $a0, 0x140($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X140);
            goto L_80144D38;
    }
    goto skip_0;
    // 0x80144D18: lw          $a0, 0x140($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X140);
    skip_0:
    // 0x80144D1C: lw          $a0, 0x140($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X140);
    // 0x80144D20: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80144D24: jal         0x800F4428
    // 0x80144D28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x80144D28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80144D2C: b           L_80144D44
    // 0x80144D30: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_80144D44;
    // 0x80144D30: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80144D34: lw          $a0, 0x140($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X140);
L_80144D38:
    // 0x80144D38: jal         0x800F4408
    // 0x80144D3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x80144D3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80144D40: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80144D44:
    // 0x80144D44: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    // 0x80144D48: addiu       $v0, $v1, 0xB0
    ctx->r2 = ADD32(ctx->r3, 0XB0);
    // 0x80144D4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80144D50: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80144D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80144D58: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80144D5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80144D60: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80144D64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80144D68: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80144D6C: addiu       $a2, $v1, 0x78
    ctx->r6 = ADD32(ctx->r3, 0X78);
    // 0x80144D70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80144D74: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80144D78: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80144D7C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80144D80: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80144D84: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80144D88: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80144D8C: jal         0x800DF014
    // 0x80144D90: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    mpCommonRunFighterCollisionDefault(rdram, ctx);
        goto after_2;
    // 0x80144D90: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80144D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80144D9C: jr          $ra
    // 0x80144DA0: nop

    return;
    // 0x80144DA0: nop

;}
RECOMP_FUNC void ftParamSetStickLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8044: lb          $t6, 0x1C2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C2);
    // 0x800E8048: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800E804C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E8050: bltzl       $t6, L_800E8064
    if (SIGNED(ctx->r14) < 0) {
        // 0x800E8054: sw          $t8, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->r24;
            goto L_800E8064;
    }
    goto skip_0;
    // 0x800E8054: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
    skip_0:
    // 0x800E8058: jr          $ra
    // 0x800E805C: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    return;
    // 0x800E805C: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800E8060: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
L_800E8064:
    // 0x800E8064: jr          $ra
    // 0x800E8068: nop

    return;
    // 0x800E8068: nop

;}
RECOMP_FUNC void itHitokageWeaponFlameProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801841CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801841D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801841D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801841D8: jal         0x800269C0
    // 0x801841DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801841DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801841E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801841E4: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x801841E8: jal         0x80100480
    // 0x801841EC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801841EC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801841F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801841F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801841F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801841FC: jr          $ra
    // 0x80184200: nop

    return;
    // 0x80184200: nop

;}
RECOMP_FUNC void ftCommonReboundWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144AB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144AB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144AC0: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80144AC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144AC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80144ACC: jal         0x800E6F24
    // 0x80144AD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144AD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80144AD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80144AD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80144ADC: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x80144AE0: lwc1        $f0, 0x7C0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C0);
    // 0x80144AE4: lw          $t7, 0x7C4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C4);
    // 0x80144AE8: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80144AEC: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x80144AF0: swc1        $f0, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f0.u32l;
    // 0x80144AF4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80144AF8: bne         $t7, $t8, L_80144B08
    if (ctx->r15 != ctx->r24) {
        // 0x80144AFC: swc1        $f6, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->f6.u32l;
            goto L_80144B08;
    }
    // 0x80144AFC: swc1        $f6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f6.u32l;
    // 0x80144B00: b           L_80144B08
    // 0x80144B04: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80144B08;
    // 0x80144B04: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80144B08:
    // 0x80144B08: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80144B0C: lwc1        $f0, 0xB1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80144B10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80144B14: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80144B18: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80144B1C: swc1        $f18, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f18.u32l;
    // 0x80144B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144B28: jr          $ra
    // 0x80144B2C: nop

    return;
    // 0x80144B2C: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageUpdateAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EC50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010EC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010EC58: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010EC5C: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8010EC60: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010EC64: addiu       $t8, $t8, 0x1598
    ctx->r24 = ADD32(ctx->r24, 0X1598);
    // 0x8010EC68: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x8010EC6C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8010EC70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010EC74: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8010EC78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010EC7C: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8010EC80: lbu         $v0, 0x67($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X67);
    // 0x8010EC84: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8010EC88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8010EC8C: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8010EC90: beq         $at, $zero, L_8010ED90
    if (ctx->r1 == 0) {
        // 0x8010EC94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010ED90;
    }
    // 0x8010EC94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010EC98: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x8010EC9C: mflo        $a0
    ctx->r4 = lo;
    // 0x8010ECA0: bne         $a1, $zero, L_8010ECAC
    if (ctx->r5 != 0) {
        // 0x8010ECA4: nop
    
            goto L_8010ECAC;
    }
    // 0x8010ECA4: nop

    // 0x8010ECA8: break       7
    do_break(2148592808);
L_8010ECAC:
    // 0x8010ECAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010ECB0: bne         $a1, $at, L_8010ECC4
    if (ctx->r5 != ctx->r1) {
        // 0x8010ECB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010ECC4;
    }
    // 0x8010ECB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010ECB8: bne         $v1, $at, L_8010ECC4
    if (ctx->r3 != ctx->r1) {
        // 0x8010ECBC: nop
    
            goto L_8010ECC4;
    }
    // 0x8010ECBC: nop

    // 0x8010ECC0: break       6
    do_break(2148592832);
L_8010ECC4:
    // 0x8010ECC4: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010ECC8: mflo        $t9
    ctx->r25 = lo;
    // 0x8010ECCC: subu        $t1, $v1, $t9
    ctx->r9 = SUB32(ctx->r3, ctx->r25);
    // 0x8010ECD0: bnel        $t1, $zero, L_8010ED8C
    if (ctx->r9 != 0) {
        // 0x8010ECD4: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_8010ED8C;
    }
    goto skip_0;
    // 0x8010ECD4: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8010ECD8: lbu         $t2, 0x66($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X66);
    // 0x8010ECDC: subu        $a1, $t2, $a0
    ctx->r5 = SUB32(ctx->r10, ctx->r4);
    // 0x8010ECE0: blez        $a1, L_8010ED88
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8010ECE4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8010ED88;
    }
    // 0x8010ECE4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010ECE8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8010ECEC: jal         0x80018994
    // 0x8010ECF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010ECF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8010ECF4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8010ECF8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8010ECFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010ED00: lbu         $a2, 0x66($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X66);
    // 0x8010ED04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010ED08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8010ED0C: blez        $a2, L_8010ED58
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8010ED10: sll         $t7, $t0, 3
        ctx->r15 = S32(ctx->r8 << 3);
            goto L_8010ED58;
    }
    // 0x8010ED10: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x8010ED14: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x8010ED18: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8010ED1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8010ED20: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8010ED24: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8010ED28: addiu       $t4, $t4, 0x1598
    ctx->r12 = ADD32(ctx->r12, 0X1598);
    // 0x8010ED2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8010ED30: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
L_8010ED34:
    // 0x8010ED34: lbu         $t5, 0x21($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X21);
    // 0x8010ED38: bnel        $t5, $zero, L_8010ED4C
    if (ctx->r13 != 0) {
        // 0x8010ED3C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8010ED4C;
    }
    goto skip_1;
    // 0x8010ED3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8010ED40: beq         $a1, $v0, L_8010ED58
    if (ctx->r5 == ctx->r2) {
        // 0x8010ED44: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8010ED58;
    }
    // 0x8010ED44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8010ED48: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8010ED4C:
    // 0x8010ED4C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8010ED50: bne         $at, $zero, L_8010ED34
    if (ctx->r1 != 0) {
        // 0x8010ED54: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_8010ED34;
    }
    // 0x8010ED54: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_8010ED58:
    // 0x8010ED58: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8010ED5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010ED60: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8010ED64: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8010ED68: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8010ED6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010ED70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010ED74: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010ED78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010ED7C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8010ED80: sb          $t6, 0x15B9($at)
    MEM_B(0X15B9, ctx->r1) = ctx->r14;
    // 0x8010ED84: lbu         $v0, 0x67($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X67);
L_8010ED88:
    // 0x8010ED88: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
L_8010ED8C:
    // 0x8010ED8C: sb          $t1, 0x67($a3)
    MEM_B(0X67, ctx->r7) = ctx->r9;
L_8010ED90:
    // 0x8010ED90: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8010ED94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010ED98: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8010ED9C: lw          $v1, 0x8($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X8);
    // 0x8010EDA0: beql        $v1, $zero, L_8010EE0C
    if (ctx->r3 == 0) {
        // 0x8010EDA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010EE0C;
    }
    goto skip_2;
    // 0x8010EDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010EDA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010EDAC: nop

    // 0x8010EDB0: lhu         $t4, 0x24($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X24);
L_8010EDB4:
    // 0x8010EDB4: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8010EDB8: bnel        $t5, $zero, L_8010EE00
    if (ctx->r13 != 0) {
        // 0x8010EDBC: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_8010EE00;
    }
    goto skip_3;
    // 0x8010EDBC: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    skip_3:
    // 0x8010EDC0: lw          $v0, 0x54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X54);
    // 0x8010EDC4: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x8010EDC8: beql        $t7, $zero, L_8010EE00
    if (ctx->r15 == 0) {
        // 0x8010EDCC: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_8010EE00;
    }
    goto skip_4;
    // 0x8010EDCC: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    skip_4:
    // 0x8010EDD0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8010EDD4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010EDD8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010EDDC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8010EDE0: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010EDE4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010EDE8: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8010EDEC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8010EDF0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8010EDF4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8010EDF8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8010EDFC: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
L_8010EE00:
    // 0x8010EE00: bnel        $v1, $zero, L_8010EDB4
    if (ctx->r3 != 0) {
        // 0x8010EE04: lhu         $t4, 0x24($v1)
        ctx->r12 = MEM_HU(ctx->r3, 0X24);
            goto L_8010EDB4;
    }
    goto skip_5;
    // 0x8010EE04: lhu         $t4, 0x24($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X24);
    skip_5:
    // 0x8010EE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010EE0C:
    // 0x8010EE0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010EE10: jr          $ra
    // 0x8010EE14: nop

    return;
    // 0x8010EE14: nop

;}
RECOMP_FUNC void lbCommonDrawSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD2CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CD2D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD2D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CD2D8: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x800CD2DC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800CD2E0: lw          $t1, 0x6678($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6678);
    // 0x800CD2E4: lh          $v0, 0x10($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X10);
    // 0x800CD2E8: lh          $v1, 0x8($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X8);
    // 0x800CD2EC: lh          $a1, 0x12($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X12);
    // 0x800CD2F0: lh          $a2, 0xA($t0)
    ctx->r6 = MEM_H(ctx->r8, 0XA);
    // 0x800CD2F4: addiu       $ra, $zero, 0xA
    ctx->r31 = ADD32(0, 0XA);
    // 0x800CD2F8: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800CD2FC: bgez        $v0, L_800CD308
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800CD300: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_800CD308;
    }
    // 0x800CD300: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x800CD304: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
L_800CD308:
    // 0x800CD308: sra         $v0, $at, 2
    ctx->r2 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800CD30C: bgez        $v1, L_800CD318
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CD310: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_800CD318;
    }
    // 0x800CD310: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x800CD314: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
L_800CD318:
    // 0x800CD318: sra         $v1, $at, 2
    ctx->r3 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800CD31C: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800CD320: bgez        $a1, L_800CD32C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800CD324: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_800CD32C;
    }
    // 0x800CD324: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x800CD328: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_800CD32C:
    // 0x800CD32C: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800CD330: bgez        $a2, L_800CD33C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800CD334: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_800CD33C;
    }
    // 0x800CD334: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x800CD338: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_800CD33C:
    // 0x800CD33C: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800CD340: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x800CD344: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800CD348: mflo        $t7
    ctx->r15 = lo;
    // 0x800CD34C: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x800CD350: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x800CD354: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CD358: addu        $t5, $a2, $a1
    ctx->r13 = ADD32(ctx->r6, ctx->r5);
    // 0x800CD35C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800CD360: mflo        $a3
    ctx->r7 = lo;
    // 0x800CD364: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800CD368: beq         $at, $zero, L_800CD374
    if (ctx->r1 == 0) {
        // 0x800CD36C: subu        $a0, $t1, $a3
        ctx->r4 = SUB32(ctx->r9, ctx->r7);
            goto L_800CD374;
    }
    // 0x800CD36C: subu        $a0, $t1, $a3
    ctx->r4 = SUB32(ctx->r9, ctx->r7);
    // 0x800CD370: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_800CD374:
    // 0x800CD374: lw          $v1, 0x667C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X667C);
    // 0x800CD378: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800CD37C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800CD380: mflo        $t8
    ctx->r24 = lo;
    // 0x800CD384: nop

    // 0x800CD388: nop

    // 0x800CD38C: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CD390: mflo        $v0
    ctx->r2 = lo;
    // 0x800CD394: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD398: beql        $at, $zero, L_800CD3A8
    if (ctx->r1 == 0) {
        // 0x800CD39C: slt         $at, $a0, $t4
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
            goto L_800CD3A8;
    }
    goto skip_0;
    // 0x800CD39C: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    skip_0:
    // 0x800CD3A0: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800CD3A4: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
L_800CD3A8:
    // 0x800CD3A8: beql        $at, $zero, L_800CD3B8
    if (ctx->r1 == 0) {
        // 0x800CD3AC: subu        $a0, $v1, $v0
        ctx->r4 = SUB32(ctx->r3, ctx->r2);
            goto L_800CD3B8;
    }
    goto skip_1;
    // 0x800CD3AC: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    skip_1:
    // 0x800CD3B0: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800CD3B4: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
L_800CD3B8:
    // 0x800CD3B8: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800CD3BC: beq         $at, $zero, L_800CD3C8
    if (ctx->r1 == 0) {
        // 0x800CD3C0: nop
    
            goto L_800CD3C8;
    }
    // 0x800CD3C0: nop

    // 0x800CD3C4: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
L_800CD3C8:
    // 0x800CD3C8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800CD3CC: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800CD3D0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800CD3D4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800CD3D8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800CD3DC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800CD3E0: jal         0x800CD0D0
    // 0x800CD3E4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    lbCommonStartSprite(rdram, ctx);
        goto after_0;
    // 0x800CD3E4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_0:
    // 0x800CD3E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800CD3EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD3F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800CD3F4: jal         0x800CD1F0
    // 0x800CD3F8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_1;
    // 0x800CD3F8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800CD3FC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CD404: lw          $t9, 0x80($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X80);
    // 0x800CD408: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800CD40C: beq         $t6, $zero, L_800CD41C
    if (ctx->r14 == 0) {
        // 0x800CD410: nop
    
            goto L_800CD41C;
    }
    // 0x800CD410: nop

    // 0x800CD414: b           L_800CD41C
    // 0x800CD418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800CD41C;
    // 0x800CD418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800CD41C:
    // 0x800CD41C: jal         0x80017B80
    // 0x800CD420: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcCaptureCameraGObj(rdram, ctx);
        goto after_2;
    // 0x800CD420: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800CD424: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800CD428: jal         0x800CD214
    // 0x800CD42C: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    lbCommonFinishSprite(rdram, ctx);
        goto after_3;
    // 0x800CD42C: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    after_3:
    // 0x800CD430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD434: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CD438: jr          $ra
    // 0x800CD43C: nop

    return;
    // 0x800CD43C: nop

;}
RECOMP_FUNC void itLizardonWeaponFlameProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FB74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017FB78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017FB7C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8017FB80: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8017FB84: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017FB88: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8017FB8C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8017FB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017FB94: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8017FB98: jal         0x801680EC
    // 0x8017FB9C: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8017FB9C: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    after_0:
    // 0x8017FBA0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8017FBA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017FBA8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017FBAC: lw          $v0, 0x74($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X74);
    // 0x8017FBB0: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x8017FBB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8017FBB8: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x8017FBBC: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8017FBC0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8017FBC4: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8017FBC8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8017FBCC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8017FBD0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017FBD4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8017FBD8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8017FBDC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8017FBE0: jal         0x800CE8C0
    // 0x8017FBE4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x8017FBE4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017FBE8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8017FBEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017FBF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017FBF4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8017FBF8: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8017FBFC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8017FC00: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8017FC04: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x8017FC08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017FC0C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017FC10: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8017FC14: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8017FC18: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8017FC1C: jal         0x800CE8C0
    // 0x8017FC20: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x8017FC20: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8017FC24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017FC28: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8017FC2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017FC30: jr          $ra
    // 0x8017FC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017FC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftCommonKneeBendProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F33C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013F340: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013F344: jal         0x80151160
    // 0x8013F348: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013F348: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013F34C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F350: bne         $v0, $zero, L_8013F390
    if (ctx->r2 != 0) {
        // 0x8013F354: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8013F390;
    }
    // 0x8013F354: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013F358: jal         0x801506CC
    // 0x8013F35C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonAttackHi4CheckInterruptKneeBend(rdram, ctx);
        goto after_1;
    // 0x8013F35C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8013F360: bne         $v0, $zero, L_8013F390
    if (ctx->r2 != 0) {
        // 0x8013F364: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8013F390;
    }
    // 0x8013F364: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F368: lb          $t6, 0x1C3($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1C3);
    // 0x8013F36C: lwc1        $f6, 0xB18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x8013F370: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013F374: nop

    // 0x8013F378: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013F37C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8013F380: nop

    // 0x8013F384: bc1fl       L_8013F394
    if (!c1cs) {
        // 0x8013F388: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F394;
    }
    goto skip_0;
    // 0x8013F388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013F38C: swc1        $f0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->f0.u32l;
L_8013F390:
    // 0x8013F390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F394:
    // 0x8013F394: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F398: jr          $ra
    // 0x8013F39C: nop

    return;
    // 0x8013F39C: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuBoundProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801550AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801550B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801550B4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801550B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801550BC: jal         0x800DE7D8
    // 0x801550C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterCliff(rdram, ctx);
        goto after_0;
    // 0x801550C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801550C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801550C8: beq         $v0, $zero, L_80155104
    if (ctx->r2 == 0) {
        // 0x801550CC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80155104;
    }
    // 0x801550CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801550D0: lhu         $t6, 0xD2($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XD2);
    // 0x801550D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801550D8: andi        $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 & 0X3000;
    // 0x801550DC: beq         $t7, $zero, L_801550F4
    if (ctx->r15 == 0) {
        // 0x801550E0: nop
    
            goto L_801550F4;
    }
    // 0x801550E0: nop

    // 0x801550E4: jal         0x80144C24
    // 0x801550E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x801550E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x801550EC: b           L_80155108
    // 0x801550F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80155108;
    // 0x801550F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801550F4:
    // 0x801550F4: jal         0x800DEE98
    // 0x801550F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_2;
    // 0x801550F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x801550FC: jal         0x80144498
    // 0x80155100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_3;
    // 0x80155100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_80155104:
    // 0x80155104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155108:
    // 0x80155108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015510C: jr          $ra
    // 0x80155110: nop

    return;
    // 0x80155110: nop

;}
RECOMP_FUNC void func_ovl8_80374680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80374684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80374688: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037468C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80374690: jal         0x803717A0
    // 0x80374694: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80374694: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80374698: beq         $v0, $zero, L_803746C4
    if (ctx->r2 == 0) {
        // 0x8037469C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803746C4;
    }
    // 0x8037469C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803746A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803746A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803746A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803746AC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803746B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803746B4: jal         0x80380FC4
    // 0x803746B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_80380FC4(rdram, ctx);
        goto after_1;
    // 0x803746B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x803746BC: b           L_803746C8
    // 0x803746C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803746C8;
    // 0x803746C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803746C4:
    // 0x803746C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803746C8:
    // 0x803746C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803746CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803746D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803746D4: jr          $ra
    // 0x803746D8: nop

    return;
    // 0x803746D8: nop

;}
RECOMP_FUNC void itMSBombDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801766B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801766BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801766C0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801766C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801766C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801766CC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x801766D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801766D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801766D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801766DC: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x801766E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801766E4: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x801766E8: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x801766EC: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x801766F0: jal         0x80172EC8
    // 0x801766F4: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801766F4: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x801766F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801766FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176700: jr          $ra
    // 0x80176704: nop

    return;
    // 0x80176704: nop

;}
RECOMP_FUNC void mvOpeningKirbyFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDBC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDC0: addiu       $v0, $v0, -0x1DD8
    ctx->r2 = ADD32(ctx->r2, -0X1DD8);
    // 0x8018DDC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DDD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DDD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDDC: jal         0x8039076C
    // 0x8018DDE0: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDE0: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDE4: beq         $v0, $zero, L_8018DE04
    if (ctx->r2 == 0) {
        // 0x8018DDE8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DE04;
    }
    // 0x8018DDE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDEC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDF0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDF4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDF8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DDFC: jal         0x80005C74
    // 0x8018DE00: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DE00: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DE04:
    // 0x8018DE04: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE08: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE0C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DE10: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE14: bnel        $v0, $at, L_8018DE48
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE18: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE48;
    }
    goto skip_0;
    // 0x8018DE18: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DE1C: jal         0x80009A84
    // 0x8018DE20: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DE20: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    after_2:
    // 0x8018DE24: jal         0x8018D62C
    // 0x8018DE28: nop

    mvOpeningKirbyMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE28: nop

    after_3:
    // 0x8018DE2C: jal         0x8018D970
    // 0x8018DE30: nop

    mvOpeningKirbyMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE30: nop

    after_4:
    // 0x8018DE34: jal         0x8018DA8C
    // 0x8018DE38: nop

    mvOpeningKirbyMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE38: nop

    after_5:
    // 0x8018DE3C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE40: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE44: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE48:
    // 0x8018DE48: bne         $v0, $at, L_8018DE68
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE4C: addiu       $t1, $zero, 0x21
        ctx->r9 = ADD32(0, 0X21);
            goto L_8018DE68;
    }
    // 0x8018DE4C: addiu       $t1, $zero, 0x21
    ctx->r9 = ADD32(0, 0X21);
    // 0x8018DE50: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE54: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE58: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE5C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE60: jal         0x80005C74
    // 0x8018DE64: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE64: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE68:
    // 0x8018DE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE70: jr          $ra
    // 0x8018DE74: nop

    return;
    // 0x8018DE74: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E7F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E804: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015E808: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8015E80C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015E810: jal         0x800E8098
    // 0x8015E814: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015E814: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015E818: jal         0x800D9444
    // 0x8015E81C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_1;
    // 0x8015E81C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015E820: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E824: lw          $t7, 0x830($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X830);
    // 0x8015E828: sw          $t7, 0x840($a2)
    MEM_W(0X840, ctx->r6) = ctx->r15;
    // 0x8015E82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E834: jr          $ra
    // 0x8015E838: nop

    return;
    // 0x8015E838: nop

;}
RECOMP_FUNC void itNBumperFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B548: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017B54C: lwc1        $f0, -0x324C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X324C);
    // 0x8017B550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B558: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017B55C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8017B560: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017B564: jal         0x80173B24
    // 0x8017B568: addiu       $a3, $a3, -0x4A00
    ctx->r7 = ADD32(ctx->r7, -0X4A00);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x8017B568: addiu       $a3, $a3, -0x4A00
    ctx->r7 = ADD32(ctx->r7, -0X4A00);
    after_0:
    // 0x8017B56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B574: jr          $ra
    // 0x8017B578: nop

    return;
    // 0x8017B578: nop

;}
RECOMP_FUNC void mnCongraFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CA4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80131CA8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80131CAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CB0: sw          $t6, 0x22E4($at)
    MEM_W(0X22E4, ctx->r1) = ctx->r14;
    // 0x80131CB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CB8: sw          $zero, 0x22E8($at)
    MEM_W(0X22E8, ctx->r1) = 0;
    // 0x80131CBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CC0: sw          $zero, 0x22EC($at)
    MEM_W(0X22EC, ctx->r1) = 0;
    // 0x80131CC4: lui         $t7, 0x1B
    ctx->r15 = S32(0X1B << 16);
    // 0x80131CC8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131CCC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131CD0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131CD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CD8: addiu       $t7, $t7, -0x3790
    ctx->r15 = ADD32(ctx->r15, -0X3790);
    // 0x80131CDC: addiu       $t8, $t8, 0x854
    ctx->r24 = ADD32(ctx->r24, 0X854);
    // 0x80131CE0: addiu       $t9, $t9, 0x22B8
    ctx->r25 = ADD32(ctx->r25, 0X22B8);
    // 0x80131CE4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80131CE8: sw          $zero, 0x22F0($at)
    MEM_W(0X22F0, ctx->r1) = 0;
    // 0x80131CEC: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80131CF0: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x80131CF4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80131CF8: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80131CFC: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80131D00: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80131D04: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80131D08: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80131D0C: jal         0x800CDF78
    // 0x80131D10: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80131D10: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80131D14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131D18: addiu       $a1, $a1, 0x1C04
    ctx->r5 = ADD32(ctx->r5, 0X1C04);
    // 0x80131D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131D24: jal         0x80009968
    // 0x80131D28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80131D28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D2C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80131D30: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D38: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80131D3C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80131D40: jal         0x8000B9FC
    // 0x80131D44: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x80131D44: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80131D48: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80131D4C: addiu       $t2, $t2, -0x2D34
    ctx->r10 = ADD32(ctx->r10, -0X2D34);
    // 0x80131D50: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80131D54: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80131D58: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80131D5C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131D64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80131D68: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80131D6C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80131D70: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80131D74: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80131D78: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80131D7C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80131D80: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80131D84: addiu       $a0, $zero, 0x3EB
    ctx->r4 = ADD32(0, 0X3EB);
    // 0x80131D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D8C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80131D90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131D94: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131D98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131D9C: jal         0x8000B93C
    // 0x80131DA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_3;
    // 0x80131DA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_3:
    // 0x80131DA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131DA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131DAC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131DB0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131DBC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131DC0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131DC4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131DC8: jal         0x80007080
    // 0x80131DCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_4;
    // 0x80131DCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80131DD0: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80131DD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DD8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80131DDC: jal         0x80009968
    // 0x80131DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80131DE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131DE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131DE8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80131DEC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80131DF0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80131DF4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131DF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131E00: jal         0x80009DF4
    // 0x80131E04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80131E04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x80131E08: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131E0C: lw          $t0, 0x22E0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X22E0);
    // 0x80131E10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131E14: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80131E18: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80131E1C: jal         0x800CDBD0
    // 0x80131E20: lw          $a0, 0x2100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2100);
    lbRelocGetFileSize(rdram, ctx);
        goto after_7;
    // 0x80131E20: lw          $a0, 0x2100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2100);
    after_7:
    // 0x80131E24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E28: jal         0x80004980
    // 0x80131E2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_8;
    // 0x80131E2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_8:
    // 0x80131E30: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131E34: lw          $t2, 0x22E0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X22E0);
    // 0x80131E38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131E3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80131E40: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80131E44: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80131E48: jal         0x800CDC88
    // 0x80131E4C: lw          $a0, 0x2100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2100);
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_9;
    // 0x80131E4C: lw          $a0, 0x2100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2100);
    after_9:
    // 0x80131E50: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131E54: lw          $t4, 0x22E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X22E0);
    // 0x80131E58: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E5C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80131E60: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80131E64: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80131E68: lw          $t6, 0x2104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2104);
    // 0x80131E6C: jal         0x800CCFDC
    // 0x80131E70: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_10;
    // 0x80131E70: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
    after_10:
    // 0x80131E74: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E7C: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E80: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80131E84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E88: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80131E8C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131E90: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131E94: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131E98: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80131E9C: lw          $t9, 0x22E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X22E0);
    // 0x80131EA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131EA4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80131EA8: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80131EAC: jal         0x800CDBD0
    // 0x80131EB0: lw          $a0, 0x2108($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2108);
    lbRelocGetFileSize(rdram, ctx);
        goto after_11;
    // 0x80131EB0: lw          $a0, 0x2108($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2108);
    after_11:
    // 0x80131EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EB8: jal         0x80004980
    // 0x80131EBC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_12;
    // 0x80131EBC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_12:
    // 0x80131EC0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131EC4: lw          $t1, 0x22E0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X22E0);
    // 0x80131EC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80131ED0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80131ED4: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80131ED8: jal         0x800CDC88
    // 0x80131EDC: lw          $a0, 0x2108($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2108);
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_13;
    // 0x80131EDC: lw          $a0, 0x2108($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2108);
    after_13:
    // 0x80131EE0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80131EE4: lw          $t3, 0x22E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X22E0);
    // 0x80131EE8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80131EEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80131EF0: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80131EF4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80131EF8: lw          $t5, 0x210C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X210C);
    // 0x80131EFC: jal         0x800CCFDC
    // 0x80131F00: addu        $a1, $t5, $v0
    ctx->r5 = ADD32(ctx->r13, ctx->r2);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_14;
    // 0x80131F00: addu        $a1, $t5, $v0
    ctx->r5 = ADD32(ctx->r13, ctx->r2);
    after_14:
    // 0x80131F04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131F08: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131F10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131F14: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80131F18: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131F1C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80131F20: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80131F24: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x80131F28: lw          $t8, 0x4AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4AF0);
    // 0x80131F2C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80131F30: ori         $at, $at, 0x4240
    ctx->r1 = ctx->r1 | 0X4240;
    // 0x80131F34: sltu        $at, $t8, $at
    ctx->r1 = ctx->r24 < ctx->r1 ? 1 : 0;
    // 0x80131F38: bne         $at, $zero, L_80131F48
    if (ctx->r1 != 0) {
        // 0x80131F3C: addiu       $v0, $zero, 0x1D1
        ctx->r2 = ADD32(0, 0X1D1);
            goto L_80131F48;
    }
    // 0x80131F3C: addiu       $v0, $zero, 0x1D1
    ctx->r2 = ADD32(0, 0X1D1);
    // 0x80131F40: b           L_80131F48
    // 0x80131F44: addiu       $v0, $zero, 0x1D2
    ctx->r2 = ADD32(0, 0X1D2);
        goto L_80131F48;
    // 0x80131F44: addiu       $v0, $zero, 0x1D2
    ctx->r2 = ADD32(0, 0X1D2);
L_80131F48:
    // 0x80131F48: jal         0x800269C0
    // 0x80131F4C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_15;
    // 0x80131F4C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_15:
    // 0x80131F50: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F54: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80131F58: jr          $ra
    // 0x80131F5C: nop

    return;
    // 0x80131F5C: nop

;}
RECOMP_FUNC void syDmaWriteRom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002CDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002CE0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80002CE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80002CE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80002CEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002CF0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002CF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80002CF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80002CFC: jal         0x80002A90
    // 0x80002D00: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    syDmaCopy(rdram, ctx);
        goto after_0;
    // 0x80002D00: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    after_0:
    // 0x80002D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002D0C: jr          $ra
    // 0x80002D10: nop

    return;
    // 0x80002D10: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningDonkeyPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D980: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D984: lw          $v1, -0x1E38($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1E38);
    // 0x8018D988: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D98C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D990: beq         $v1, $at, L_8018D9B8
    if (ctx->r3 == ctx->r1) {
        // 0x8018D994: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9B8;
    }
    // 0x8018D994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D998: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D99C: beq         $v0, $at, L_8018D9CC
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9A0: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9CC;
    }
    // 0x8018D9A0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9A4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9A8: beq         $v0, $at, L_8018D9E0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9AC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9E0;
    }
    // 0x8018D9AC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9B0: b           L_8018D9F0
    // 0x8018D9B4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
        goto L_8018D9F0;
    // 0x8018D9B4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
L_8018D9B8:
    // 0x8018D9B8: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9C0: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9C4: b           L_8018D9F0
    // 0x8018D9C8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018D9F0;
    // 0x8018D9C8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018D9CC:
    // 0x8018D9CC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D9D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D9D4: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9D8: b           L_8018D9F0
    // 0x8018D9DC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018D9F0;
    // 0x8018D9DC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018D9E0:
    // 0x8018D9E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018D9E4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9E8: addiu       $a1, $a1, -0x1E20
    ctx->r5 = ADD32(ctx->r5, -0X1E20);
    // 0x8018D9EC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018D9F0:
    // 0x8018D9F0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018D9F4: bne         $at, $zero, L_8018DA14
    if (ctx->r1 != 0) {
        // 0x8018D9F8: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA14;
    }
    // 0x8018D9F8: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018D9FC: beq         $at, $zero, L_8018DA14
    if (ctx->r1 == 0) {
        // 0x8018DA00: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA14;
    }
    // 0x8018DA00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA04: lwc1        $f16, -0x1E50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E50);
    // 0x8018DA08: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA10: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA14:
    // 0x8018DA14: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA18: bne         $at, $zero, L_8018DA38
    if (ctx->r1 != 0) {
        // 0x8018DA1C: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA38;
    }
    // 0x8018DA1C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA20: beq         $at, $zero, L_8018DA38
    if (ctx->r1 == 0) {
        // 0x8018DA24: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA38;
    }
    // 0x8018DA24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA2C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA34: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA38:
    // 0x8018DA38: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA3C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA40: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DA44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA48: jr          $ra
    // 0x8018DA4C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA4C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftMarioSpecialLwInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015686C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156870: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80156874: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80156878: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015687C: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80156880: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
    // 0x80156884: jr          $ra
    // 0x80156888: swc1        $f4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80156888: swc1        $f4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftCommonCliffClimbQuick1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801451A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801451AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801451B0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801451B4: jal         0x800D9480
    // 0x801451B8: addiu       $a1, $a1, 0x55A0
    ctx->r5 = ADD32(ctx->r5, 0X55A0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801451B8: addiu       $a1, $a1, 0x55A0
    ctx->r5 = ADD32(ctx->r5, 0X55A0);
    after_0:
    // 0x801451BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801451C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801451C4: jr          $ra
    // 0x801451C8: nop

    return;
    // 0x801451C8: nop

;}
RECOMP_FUNC void func_ovl8_80387BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387BD8: jal         0x80381308
    // 0x80387BDC: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_80381308(rdram, ctx);
        goto after_0;
    // 0x80387BDC: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80387BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80387BE8: jr          $ra
    // 0x80387BEC: nop

    return;
    // 0x80387BEC: nop

;}
RECOMP_FUNC void ftKirbySpecialNGetCaptureDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161D6C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80161D70: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80161D74: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80161D78: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80161D7C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80161D80: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80161D84: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80161D88: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80161D8C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80161D90: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80161D94: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80161D98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80161D9C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80161DA0: jr          $ra
    // 0x80161DA4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    return;
    // 0x80161DA4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
;}
RECOMP_FUNC void itPakkunDamagedProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D468: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D46C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017D470: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017D474: lw          $t7, 0x350($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X350);
    // 0x8017D478: addiu       $t8, $zero, 0x4B0
    ctx->r24 = ADD32(0, 0X4B0);
    // 0x8017D47C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D480: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8017D484: lw          $t6, 0x354($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X354);
    // 0x8017D488: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8017D48C: lw          $t7, 0x358($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X358);
    // 0x8017D490: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8017D494: sh          $t8, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r24;
    // 0x8017D498: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017D49C: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x8017D4A0: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8017D4A4: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x8017D4A8: lwc1        $f4, -0x31F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X31F0);
    // 0x8017D4AC: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x8017D4B0: swc1        $f4, 0x98($t9)
    MEM_W(0X98, ctx->r25) = ctx->f4.u32l;
    // 0x8017D4B4: jal         0x8017CF20
    // 0x8017D4B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itPakkunWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017D4B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017D4BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017D4C4: sb          $zero, 0x35C($v1)
    MEM_B(0X35C, ctx->r3) = 0;
    // 0x8017D4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D4CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D4D0: jr          $ra
    // 0x8017D4D4: nop

    return;
    // 0x8017D4D4: nop

;}
RECOMP_FUNC void mnVSResultsInitFightersAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801375AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801375B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801375B4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801375B8: addiu       $s0, $s0, -0x6430
    ctx->r16 = ADD32(ctx->r16, -0X6430);
    // 0x801375BC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801375C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801375C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801375C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801375CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801375D0: beq         $t6, $zero, L_801375E0
    if (ctx->r14 == 0) {
        // 0x801375D4: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_801375E0;
    }
    // 0x801375D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801375D8: jal         0x801374F4
    // 0x801375DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsInitFighter(rdram, ctx);
        goto after_0;
    // 0x801375DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
L_801375E0:
    // 0x801375E0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x801375E4: beql        $t7, $zero, L_801375F8
    if (ctx->r15 == 0) {
        // 0x801375E8: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_801375F8;
    }
    goto skip_0;
    // 0x801375E8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x801375EC: jal         0x801374F4
    // 0x801375F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsInitFighter(rdram, ctx);
        goto after_1;
    // 0x801375F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801375F4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_801375F8:
    // 0x801375F8: beql        $t8, $zero, L_8013760C
    if (ctx->r24 == 0) {
        // 0x801375FC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8013760C;
    }
    goto skip_1;
    // 0x801375FC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x80137600: jal         0x801374F4
    // 0x80137604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsInitFighter(rdram, ctx);
        goto after_2;
    // 0x80137604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80137608: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8013760C:
    // 0x8013760C: beq         $t9, $zero, L_8013761C
    if (ctx->r25 == 0) {
        // 0x80137610: nop
    
            goto L_8013761C;
    }
    // 0x80137610: nop

    // 0x80137614: jal         0x801374F4
    // 0x80137618: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsInitFighter(rdram, ctx);
        goto after_3;
    // 0x80137618: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
L_8013761C:
    // 0x8013761C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137620: lw          $t0, -0x63F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63F0);
    // 0x80137624: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80137628: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013762C: beq         $s4, $t0, L_80137678
    if (ctx->r20 == ctx->r8) {
        // 0x80137630: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80137678;
    }
    // 0x80137630: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80137634: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80137638: addiu       $s2, $s2, -0x6430
    ctx->r18 = ADD32(ctx->r18, -0X6430);
L_8013763C:
    // 0x8013763C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80137640: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80137644: addiu       $t2, $t2, -0x6420
    ctx->r10 = ADD32(ctx->r10, -0X6420);
    // 0x80137648: beq         $t1, $zero, L_80137668
    if (ctx->r9 == 0) {
        // 0x8013764C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80137668;
    }
    // 0x8013764C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137650: jal         0x80133134
    // 0x80137654: addu        $s3, $s1, $t2
    ctx->r19 = ADD32(ctx->r17, ctx->r10);
    mnVSResultsGetPlace(rdram, ctx);
        goto after_4;
    // 0x80137654: addu        $s3, $s1, $t2
    ctx->r19 = ADD32(ctx->r17, ctx->r10);
    after_4:
    // 0x80137658: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8013765C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80137660: jal         0x801333E4
    // 0x80137664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnVSResultsFaceWinner(rdram, ctx);
        goto after_5;
    // 0x80137664: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
L_80137668:
    // 0x80137668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013766C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80137670: bne         $s0, $s4, L_8013763C
    if (ctx->r16 != ctx->r20) {
        // 0x80137674: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8013763C;
    }
    // 0x80137674: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80137678:
    // 0x80137678: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8013767C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137680: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80137684: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137688: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8013768C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80137690: jr          $ra
    // 0x80137694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80137694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayersVSResetPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ADE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8013ADE4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013ADE8: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8013ADEC: addiu       $t6, $t6, -0x4684
    ctx->r14 = ADD32(ctx->r14, -0X4684);
    // 0x8013ADF0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8013ADF4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013ADF8: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8013ADFC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013AE00: addiu       $t0, $t0, -0x4578
    ctx->r8 = ADD32(ctx->r8, -0X4578);
    // 0x8013AE04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013AE08: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8013AE0C: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x8013AE10: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8013AE14: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013AE18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8013AE1C: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8013AE20: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8013AE24: addiu       $a1, $sp, 0x4
    ctx->r5 = ADD32(ctx->r29, 0X4);
    // 0x8013AE28: addiu       $t2, $t2, 0x4D08
    ctx->r10 = ADD32(ctx->r10, 0X4D08);
    // 0x8013AE2C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013AE30: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x8013AE34: addu        $t6, $a1, $a0
    ctx->r14 = ADD32(ctx->r5, ctx->r4);
    // 0x8013AE38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8013AE3C: lbu         $t3, 0x20($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X20);
    // 0x8013AE40: lbu         $t4, 0x21($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X21);
    // 0x8013AE44: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8013AE48: addiu       $t5, $zero, 0x1C
    ctx->r13 = ADD32(0, 0X1C);
    // 0x8013AE4C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8013AE50: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013AE54: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8013AE58: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8013AE5C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8013AE60: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x8013AE64: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8013AE68: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8013AE6C: sw          $zero, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = 0;
    // 0x8013AE70: sh          $zero, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = 0;
    // 0x8013AE74: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8013AE78: sw          $t5, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r13;
    // 0x8013AE7C: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8013AE80: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8013AE84: sw          $t3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r11;
    // 0x8013AE88: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
    // 0x8013AE8C: sw          $t7, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r15;
    // 0x8013AE90: lw          $t9, -0x4270($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4270);
    // 0x8013AE94: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8013AE98: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8013AE9C: bne         $a2, $t9, L_8013AEB4
    if (ctx->r6 != ctx->r25) {
        // 0x8013AEA0: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_8013AEB4;
    }
    // 0x8013AEA0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8013AEA4: sw          $t0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r8;
    // 0x8013AEA8: sw          $t1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r9;
    // 0x8013AEAC: b           L_8013AEC0
    // 0x8013AEB0: sw          $a2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r6;
        goto L_8013AEC0;
    // 0x8013AEB0: sw          $a2, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r6;
L_8013AEB4:
    // 0x8013AEB4: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x8013AEB8: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    // 0x8013AEBC: sw          $a0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r4;
L_8013AEC0:
    // 0x8013AEC0: jr          $ra
    // 0x8013AEC4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8013AEC4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void n_alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029CB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80029CBC: addiu       $t6, $zero, 0x170
    ctx->r14 = ADD32(0, 0X170);
    // 0x80029CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029CC4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80029CC8: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
    // 0x80029CCC: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x80029CD0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80029CD4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80029CD8: beq         $t7, $zero, L_80029D24
    if (ctx->r15 == 0) {
        // 0x80029CDC: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80029D24;
    }
    // 0x80029CDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80029CE0: addiu       $a1, $sp, 0x3A
    ctx->r5 = ADD32(ctx->r29, 0X3A);
    // 0x80029CE4: jal         0x8002983C
    // 0x80029CE8: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    n_alAdpcmPull(rdram, ctx);
        goto after_0;
    // 0x80029CE8: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    after_0:
    // 0x80029CEC: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x80029CF0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80029CF4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80029CF8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80029CFC: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80029D00: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80029D04: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80029D08: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80029D0C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80029D10: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80029D14: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80029D18: ori         $t6, $t5, 0x170
    ctx->r14 = ctx->r13 | 0X170;
    // 0x80029D1C: b           L_80029E48
    // 0x80029D20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80029E48;
    // 0x80029D20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80029D24:
    // 0x80029D24: lwc1        $f0, -0x1488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1488);
    // 0x80029D28: lwc1        $f2, 0x44($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80029D2C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80029D30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80029D34: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80029D38: nop

    // 0x80029D3C: bc1f        L_80029D4C
    if (!c1cs) {
        // 0x80029D40: nop
    
            goto L_80029D4C;
    }
    // 0x80029D40: nop

    // 0x80029D44: swc1        $f0, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f0.u32l;
    // 0x80029D48: lwc1        $f2, 0x44($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X44);
L_80029D4C:
    // 0x80029D4C: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80029D50: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x80029D54: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80029D58: addiu       $a1, $sp, 0x3A
    ctx->r5 = ADD32(ctx->r29, 0X3A);
    // 0x80029D5C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80029D60: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80029D64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029D68: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80029D6C: nop

    // 0x80029D70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80029D74: swc1        $f10, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f10.u32l;
    // 0x80029D78: lwc1        $f16, 0x44($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80029D7C: lwc1        $f10, 0x4C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x80029D80: div.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80029D84: swc1        $f18, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f18.u32l;
    // 0x80029D88: lwc1        $f4, 0x44($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80029D8C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80029D90: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80029D94: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029D98: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80029D9C: nop

    // 0x80029DA0: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x80029DA4: nop

    // 0x80029DA8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80029DAC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80029DB0: swc1        $f6, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f6.u32l;
    // 0x80029DB4: jal         0x8002983C
    // 0x80029DB8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    n_alAdpcmPull(rdram, ctx);
        goto after_1;
    // 0x80029DB8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_1:
    // 0x80029DBC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80029DC0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80029DC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80029DC8: lwc1        $f10, 0x44($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80029DCC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80029DD0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80029DD4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80029DD8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80029DDC: nop

    // 0x80029DE0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80029DE4: lw          $a0, 0x40($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X40);
    // 0x80029DE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80029DEC: jal         0x80032150
    // 0x80029DF0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80029DF0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80029DF4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80029DF8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80029DFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80029E00: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80029E04: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029E08: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80029E0C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80029E10: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80029E14: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80029E18: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80029E1C: lh          $t3, 0x3A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X3A);
    // 0x80029E20: lw          $t6, 0x50($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X50);
    // 0x80029E24: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80029E28: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80029E2C: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x80029E30: sll         $t7, $t6, 30
    ctx->r15 = S32(ctx->r14 << 30);
    // 0x80029E34: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x80029E38: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80029E3C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80029E40: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80029E44: sw          $zero, 0x50($t0)
    MEM_W(0X50, ctx->r8) = 0;
L_80029E48:
    // 0x80029E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029E4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80029E50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80029E54: jr          $ra
    // 0x80029E58: nop

    return;
    // 0x80029E58: nop

;}
RECOMP_FUNC void mpCollisionGetMapObjCountKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC7A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC7A8: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800FC7AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FC7B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FC7B4: lhu         $v0, 0x14($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X14);
    // 0x800FC7B8: bne         $v0, $zero, L_800FC7C8
    if (ctx->r2 != 0) {
        // 0x800FC7BC: nop
    
            goto L_800FC7C8;
    }
    // 0x800FC7BC: nop

    // 0x800FC7C0: jr          $ra
    // 0x800FC7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800FC7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FC7C8:
    // 0x800FC7C8: blez        $v0, L_800FC808
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FC7CC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800FC808;
    }
    // 0x800FC7CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FC7D0: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x800FC7D4: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x800FC7D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC7DC: lw          $a0, 0x1380($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1380);
    // 0x800FC7E0: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x800FC7E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FC7E8:
    // 0x800FC7E8: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800FC7EC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x800FC7F0: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800FC7F4: bne         $a2, $t7, L_800FC800
    if (ctx->r6 != ctx->r15) {
        // 0x800FC7F8: nop
    
            goto L_800FC800;
    }
    // 0x800FC7F8: nop

    // 0x800FC7FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800FC800:
    // 0x800FC800: bne         $at, $zero, L_800FC7E8
    if (ctx->r1 != 0) {
        // 0x800FC804: addiu       $a0, $a0, 0x6
        ctx->r4 = ADD32(ctx->r4, 0X6);
            goto L_800FC7E8;
    }
    // 0x800FC804: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
L_800FC808:
    // 0x800FC808: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FC80C: jr          $ra
    // 0x800FC810: nop

    return;
    // 0x800FC810: nop

;}
RECOMP_FUNC void func_800053CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800053CC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800053D0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800053D4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800053D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800053DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800053E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800053E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800053E8: addiu       $a0, $a0, 0x65D0
    ctx->r4 = ADD32(ctx->r4, 0X65D0);
    // 0x800053EC: addiu       $v0, $v0, 0x65C0
    ctx->r2 = ADD32(ctx->r2, 0X65C0);
    // 0x800053F0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
L_800053F4:
    // 0x800053F4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800053F8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800053FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005400: sra         $a2, $a2, 1
    ctx->r6 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80005404: beq         $t6, $t7, L_80005410
    if (ctx->r14 == ctx->r15) {
        // 0x80005408: nop
    
            goto L_80005410;
    }
    // 0x80005408: nop

    // 0x8000540C: ori         $a2, $a2, 0x8
    ctx->r6 = ctx->r6 | 0X8;
L_80005410:
    // 0x80005410: bne         $v0, $a0, L_800053F4
    if (ctx->r2 != ctx->r4) {
        // 0x80005414: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800053F4;
    }
    // 0x80005414: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005418: beq         $a2, $zero, L_800057AC
    if (ctx->r6 == 0) {
        // 0x8000541C: andi        $t8, $a2, 0x1
        ctx->r24 = ctx->r6 & 0X1;
            goto L_800057AC;
    }
    // 0x8000541C: andi        $t8, $a2, 0x1
    ctx->r24 = ctx->r6 & 0X1;
    // 0x80005420: beq         $t8, $zero, L_80005568
    if (ctx->r24 == 0) {
        // 0x80005424: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80005568;
    }
    // 0x80005424: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80005428: andi        $t3, $a2, 0x4
    ctx->r11 = ctx->r6 & 0X4;
    // 0x8000542C: beql        $t3, $zero, L_80005480
    if (ctx->r11 == 0) {
        // 0x80005430: andi        $t7, $a2, 0x2
        ctx->r15 = ctx->r6 & 0X2;
            goto L_80005480;
    }
    goto skip_0;
    // 0x80005430: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    skip_0:
    // 0x80005434: jal         0x800051E4
    // 0x80005438: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    syTaskmanGetUcodeID(rdram, ctx);
        goto after_0;
    // 0x80005438: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000543C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005440: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80005444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005448: jal         0x80005344
    // 0x8000544C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_1;
    // 0x8000544C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80005450: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80005454: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80005458: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8000545C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80005460: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80005464: lui         $t5, 0xDE01
    ctx->r13 = S32(0XDE01 << 16);
    // 0x80005468: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x8000546C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80005470: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x80005474: b           L_80005568
    // 0x80005478: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80005568;
    // 0x80005478: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000547C: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
L_80005480:
    // 0x80005480: beq         $t7, $zero, L_800054DC
    if (ctx->r15 == 0) {
        // 0x80005484: lui         $t8, 0x8004
        ctx->r24 = S32(0X8004 << 16);
            goto L_800054DC;
    }
    // 0x80005484: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80005488: lhu         $t8, 0x6628($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X6628);
    // 0x8000548C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005490: addiu       $a0, $s0, 0x65B0
    ctx->r4 = ADD32(ctx->r16, 0X65B0);
    // 0x80005494: beq         $t8, $zero, L_800054AC
    if (ctx->r24 == 0) {
        // 0x80005498: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_800054AC;
    }
    // 0x80005498: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000549C: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x800054A0: jal         0x80005344
    // 0x800054A4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_2;
    // 0x800054A4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_2:
    // 0x800054A8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
L_800054AC:
    // 0x800054AC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800054B0: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800054B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800054B8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800054BC: lui         $t3, 0xDE01
    ctx->r11 = S32(0XDE01 << 16);
    // 0x800054C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800054C4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800054C8: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x800054CC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800054D0: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x800054D4: b           L_80005568
    // 0x800054D8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80005568;
    // 0x800054D8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_800054DC:
    // 0x800054DC: andi        $t5, $a2, 0x8
    ctx->r13 = ctx->r6 & 0X8;
    // 0x800054E0: beq         $t5, $zero, L_80005530
    if (ctx->r13 == 0) {
        // 0x800054E4: nop
    
            goto L_80005530;
    }
    // 0x800054E4: nop

    // 0x800054E8: jal         0x800051E4
    // 0x800054EC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    syTaskmanGetUcodeID(rdram, ctx);
        goto after_3;
    // 0x800054EC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_3:
    // 0x800054F0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800054F4: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800054F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800054FC: jal         0x80005344
    // 0x80005500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_4;
    // 0x80005500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80005504: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80005508: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x8000550C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80005510: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80005514: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80005518: lui         $t7, 0xDE01
    ctx->r15 = S32(0XDE01 << 16);
    // 0x8000551C: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x80005520: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005524: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x80005528: b           L_80005568
    // 0x8000552C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80005568;
    // 0x8000552C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80005530:
    // 0x80005530: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005534: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80005538: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000553C: lui         $t3, 0xE900
    ctx->r11 = S32(0XE900 << 16);
    // 0x80005540: lui         $t5, 0xDF00
    ctx->r13 = S32(0XDF00 << 16);
    // 0x80005544: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80005548: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000554C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80005550: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80005554: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80005558: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000555C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80005560: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80005564: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80005568:
    // 0x80005568: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8000556C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005570: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x80005574: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80005578: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x8000557C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80005580: andi        $t0, $a2, 0x2
    ctx->r8 = ctx->r6 & 0X2;
    // 0x80005584: beq         $t6, $zero, L_80005634
    if (ctx->r14 == 0) {
        // 0x80005588: andi        $a3, $a2, 0x8
        ctx->r7 = ctx->r6 & 0X8;
            goto L_80005634;
    }
    // 0x80005588: andi        $a3, $a2, 0x8
    ctx->r7 = ctx->r6 & 0X8;
    // 0x8000558C: beq         $t0, $zero, L_800055DC
    if (ctx->r8 == 0) {
        // 0x80005590: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_800055DC;
    }
    // 0x80005590: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005594: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80005598: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x8000559C: addiu       $a0, $a0, 0x65B8
    ctx->r4 = ADD32(ctx->r4, 0X65B8);
    // 0x800055A0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800055A4: jal         0x80005344
    // 0x800055A8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_5;
    // 0x800055A8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_5:
    // 0x800055AC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800055B0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800055B4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800055B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800055BC: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800055C0: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800055C4: lui         $t9, 0xDE01
    ctx->r25 = S32(0XDE01 << 16);
    // 0x800055C8: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x800055CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800055D0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800055D4: b           L_80005634
    // 0x800055D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
        goto L_80005634;
    // 0x800055D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800055DC:
    // 0x800055DC: beql        $a3, $zero, L_80005608
    if (ctx->r7 == 0) {
        // 0x800055E0: lw          $v0, 0x8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X8);
            goto L_80005608;
    }
    goto skip_1;
    // 0x800055E0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x800055E4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800055E8: lui         $t5, 0xDE01
    ctx->r13 = S32(0XDE01 << 16);
    // 0x800055EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800055F0: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x800055F4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800055F8: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800055FC: b           L_80005634
    // 0x80005600: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80005634;
    // 0x80005600: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80005604: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_80005608:
    // 0x80005608: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x8000560C: lui         $t3, 0xDF00
    ctx->r11 = S32(0XDF00 << 16);
    // 0x80005610: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80005614: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x80005618: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000561C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80005620: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80005624: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80005628: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x8000562C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80005630: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80005634:
    // 0x80005634: beq         $t0, $zero, L_800056BC
    if (ctx->r8 == 0) {
        // 0x80005638: nop
    
            goto L_800056BC;
    }
    // 0x80005638: nop

    // 0x8000563C: beql        $a3, $zero, L_80005690
    if (ctx->r7 == 0) {
        // 0x80005640: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_80005690;
    }
    goto skip_2;
    // 0x80005640: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80005644: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80005648: jal         0x800051E4
    // 0x8000564C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    syTaskmanGetUcodeID(rdram, ctx);
        goto after_6;
    // 0x8000564C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_6:
    // 0x80005650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005654: jal         0x80005344
    // 0x80005658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_7;
    // 0x80005658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8000565C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80005660: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80005664: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80005668: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000566C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80005670: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80005674: lui         $t5, 0xDE01
    ctx->r13 = S32(0XDE01 << 16);
    // 0x80005678: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x8000567C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80005680: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80005684: b           L_800056BC
    // 0x80005688: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800056BC;
    // 0x80005688: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000568C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_80005690:
    // 0x80005690: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x80005694: lui         $t3, 0xDF00
    ctx->r11 = S32(0XDF00 << 16);
    // 0x80005698: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000569C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800056A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800056A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800056A8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800056AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800056B0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800056B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800056B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800056BC:
    // 0x800056BC: beql        $a3, $zero, L_800056F8
    if (ctx->r7 == 0) {
        // 0x800056C0: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_800056F8;
    }
    goto skip_3;
    // 0x800056C0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x800056C4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800056C8: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x800056CC: lui         $t7, 0xDF00
    ctx->r15 = S32(0XDF00 << 16);
    // 0x800056D0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800056D4: sw          $t4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r12;
    // 0x800056D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800056DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800056E0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800056E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800056E8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x800056EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800056F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800056F4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_800056F8:
    // 0x800056F8: beq         $t8, $zero, L_80005708
    if (ctx->r24 == 0) {
        // 0x800056FC: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80005708;
    }
    // 0x800056FC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80005700: b           L_80005738
    // 0x80005704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80005738;
    // 0x80005704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80005708:
    // 0x80005708: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000570C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80005710: beq         $t9, $zero, L_80005720
    if (ctx->r25 == 0) {
        // 0x80005714: nop
    
            goto L_80005720;
    }
    // 0x80005714: nop

    // 0x80005718: b           L_80005738
    // 0x8000571C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80005738;
    // 0x8000571C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80005720:
    // 0x80005720: beq         $t0, $zero, L_80005734
    if (ctx->r8 == 0) {
        // 0x80005724: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80005734;
    }
    // 0x80005724: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80005728: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000572C: b           L_80005738
    // 0x80005730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80005738;
    // 0x80005730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80005734:
    // 0x80005734: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80005738:
    // 0x80005738: sll         $a2, $t1, 2
    ctx->r6 = S32(ctx->r9 << 2);
    // 0x8000573C: addu        $v1, $s0, $a2
    ctx->r3 = ADD32(ctx->r16, ctx->r6);
    // 0x80005740: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80005744: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80005748: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8000574C: addiu       $t3, $a1, 0x8
    ctx->r11 = ADD32(ctx->r5, 0X8);
    // 0x80005750: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80005754: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80005758: lw          $t5, 0x662C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X662C);
    // 0x8000575C: lui         $t7, 0xDE01
    ctx->r15 = S32(0XDE01 << 16);
    // 0x80005760: addu        $t8, $t2, $a2
    ctx->r24 = ADD32(ctx->r10, ctx->r6);
    // 0x80005764: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80005768: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000576C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80005770: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80005774: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005778: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000577C: jal         0x80005240
    // 0x80005780: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_80005240(rdram, ctx);
        goto after_8;
    // 0x80005780: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_8:
    // 0x80005784: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80005788: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x8000578C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80005790: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x80005794: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80005798: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8000579C: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800057A0: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x800057A4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x800057A8: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
L_800057AC:
    // 0x800057AC: jal         0x80004B9C
    // 0x800057B0: nop

    syTaskmanCheckBufferLengths(rdram, ctx);
        goto after_9;
    // 0x800057B0: nop

    after_9:
    // 0x800057B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800057B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800057BC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800057C0: jr          $ra
    // 0x800057C4: nop

    return;
    // 0x800057C4: nop

;}
RECOMP_FUNC void sc1PTrainingModeLoadWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDB0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DDB4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018DDB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDC0: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    // 0x8018DDC4: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DDC8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8018DDCC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8018DDD0: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8018DDD4: lw          $t7, 0x848($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X848);
    // 0x8018DDD8: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x8018DDDC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018DDE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018DDE4: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x8018DDE8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018DDEC: lw          $t1, 0x7B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B8);
    // 0x8018DDF0: lw          $t0, 0x48($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X48);
    // 0x8018DDF4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DDF8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDFC: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8018DE00: lw          $a0, 0x824($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X824);
    // 0x8018DE04: jal         0x800CDDD8
    // 0x8018DE08: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    lbRelocGetForceExternHeapFile(rdram, ctx);
        goto after_0;
    // 0x8018DE08: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    after_0:
    // 0x8018DE0C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018DE10: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x8018DE14: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018DE18: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DE1C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8018DE20: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8018DE24: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x8018DE28: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018DE2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018DE30: lw          $t5, 0x848($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X848);
    // 0x8018DE34: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018DE38: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018DE3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DE40: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018DE44: lw          $t7, 0x828($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X828);
    // 0x8018DE48: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8018DE4C: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
    // 0x8018DE50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE58: jr          $ra
    // 0x8018DE5C: nop

    return;
    // 0x8018DE5C: nop

;}
RECOMP_FUNC void itCapsuleExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017442C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174430: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80174434: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80174438: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017443C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80174440: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x80174444: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80174448: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8017444C: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80174450: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80174454: jal         0x801005C8
    // 0x80174458: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80174458: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_0:
    // 0x8017445C: beq         $v0, $zero, L_80174488
    if (ctx->r2 == 0) {
        // 0x80174460: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80174488;
    }
    // 0x80174460: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80174464: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80174468: lwc1        $f4, -0x3350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3350);
    // 0x8017446C: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x80174470: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80174474: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80174478: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8017447C: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80174480: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x80174484: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_80174488:
    // 0x80174488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017448C: jal         0x801008F4
    // 0x80174490: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80174490: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80174494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174498: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8017449C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x801744A0: jal         0x801743F4
    // 0x801744A4: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    itCapsuleExplodeSetStatus(rdram, ctx);
        goto after_2;
    // 0x801744A4: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    after_2:
    // 0x801744A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801744AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801744B0: jr          $ra
    // 0x801744B4: nop

    return;
    // 0x801744B4: nop

;}
RECOMP_FUNC void ftNessSpecialHiMakePKThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153C88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80153C8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80153C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153C94: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80153C98: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153C9C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80153CA0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80153CA4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80153CA8: lw          $a0, 0x918($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X918);
    // 0x80153CAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80153CB0: jal         0x800EDF24
    // 0x80153CB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80153CB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80153CB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80153CBC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80153CC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80153CC4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80153CC8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80153CCC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80153CD0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80153CD4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80153CD8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80153CDC: jal         0x8016B2C4
    // 0x80153CE0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    wpNessPKThunderHeadMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80153CE0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80153CE4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80153CE8: sw          $v0, 0xB24($t7)
    MEM_W(0XB24, ctx->r15) = ctx->r2;
    // 0x80153CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153CF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80153CF4: jr          $ra
    // 0x80153CF8: nop

    return;
    // 0x80153CF8: nop

;}
RECOMP_FUNC void efManagerSortZPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD68C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD694: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800FD698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FD69C: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800FD6A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FD6A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800FD6A8: nop

    // 0x800FD6AC: bc1fl       L_800FD6E0
    if (!c1cs) {
        // 0x800FD6B0: lw          $a0, 0x4($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X4);
            goto L_800FD6E0;
    }
    goto skip_0;
    // 0x800FD6B0: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x800FD6B4: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x800FD6B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FD6BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD6C0: lbu         $t6, 0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD);
    // 0x800FD6C4: beql        $t6, $at, L_800FD700
    if (ctx->r14 == ctx->r1) {
        // 0x800FD6C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD700;
    }
    goto skip_1;
    // 0x800FD6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FD6CC: jal         0x8000A0D0
    // 0x800FD6D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x800FD6D0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800FD6D4: b           L_800FD700
    // 0x800FD6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FD700;
    // 0x800FD6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD6DC: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
L_800FD6E0:
    // 0x800FD6E0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800FD6E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800FD6E8: lbu         $t7, 0xD($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XD);
    // 0x800FD6EC: beql        $t7, $at, L_800FD700
    if (ctx->r15 == ctx->r1) {
        // 0x800FD6F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD700;
    }
    goto skip_2;
    // 0x800FD6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FD6F4: jal         0x8000A0D0
    // 0x800FD6F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x800FD6F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800FD6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FD700:
    // 0x800FD700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD704: jr          $ra
    // 0x800FD708: nop

    return;
    // 0x800FD708: nop

;}
RECOMP_FUNC void n_alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A9C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002A9C8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002A9CC: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002A9D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A9D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002A9D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002A9DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002A9E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002A9E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002A9E8: lw          $s3, 0x40($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X40);
    // 0x8002A9EC: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8002A9F0: ori         $t7, $t7, 0x7C0
    ctx->r15 = ctx->r15 | 0X7C0;
    // 0x8002A9F4: lw          $v0, 0x1C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1C);
    // 0x8002A9F8: addiu       $t8, $zero, 0x2E0
    ctx->r24 = ADD32(0, 0X2E0);
    // 0x8002A9FC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8002AA00: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8002AA04: lw          $t9, 0x14($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X14);
    // 0x8002AA08: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002AA0C: addiu       $s2, $a1, 0x8
    ctx->r18 = ADD32(ctx->r5, 0X8);
    // 0x8002AA10: blez        $t9, L_8002AA44
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002AA14: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8002AA44;
    }
    // 0x8002AA14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002AA18: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8002AA1C:
    // 0x8002AA1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002AA20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002AA24: jal         0x8002A380
    // 0x8002AA28: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    n_alEnvmixerPull(rdram, ctx);
        goto after_0;
    // 0x8002AA28: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8002AA2C: lw          $t0, 0x14($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X14);
    // 0x8002AA30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002AA34: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002AA38: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002AA3C: bne         $at, $zero, L_8002AA1C
    if (ctx->r1 != 0) {
        // 0x8002AA40: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8002AA1C;
    }
    // 0x8002AA40: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8002AA44:
    // 0x8002AA44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AA48: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002AA4C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002AA50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002AA54: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AA58: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002AA5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002AA60: jr          $ra
    // 0x8002AA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002AA64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DA94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013DA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DA9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DAA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013DAA4: jal         0x8013DA14
    // 0x8013DAA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonAppearUpdateEffects(rdram, ctx);
        goto after_0;
    // 0x8013DAA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013DAAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013DAB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013DAB4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DAB8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013DABC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013DAC0: nop

    // 0x8013DAC4: bc1fl       L_8013DB20
    if (!c1cs) {
        // 0x8013DAC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013DB20;
    }
    goto skip_0;
    // 0x8013DAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013DACC: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x8013DAD0: lw          $t9, 0x854($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X854);
    // 0x8013DAD4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013DAD8: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
    // 0x8013DADC: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8013DAE0: sw          $t9, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r25;
    // 0x8013DAE4: lw          $t8, 0x858($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X858);
    // 0x8013DAE8: sw          $t8, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r24;
    // 0x8013DAEC: lw          $t9, 0x85C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X85C);
    // 0x8013DAF0: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
    // 0x8013DAF4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8013DAF8: lw          $t0, 0xB20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB20);
    // 0x8013DAFC: bne         $t1, $at, L_8013DB14
    if (ctx->r9 != ctx->r1) {
        // 0x8013DB00: sw          $t0, 0xEC($v0)
        MEM_W(0XEC, ctx->r2) = ctx->r8;
            goto L_8013DB14;
    }
    // 0x8013DB00: sw          $t0, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r8;
    // 0x8013DB04: jal         0x80159040
    // 0x8013DB08: nop

    ftBossWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013DB08: nop

    after_1:
    // 0x8013DB0C: b           L_8013DB20
    // 0x8013DB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013DB20;
    // 0x8013DB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013DB14:
    // 0x8013DB14: jal         0x8013E1C8
    // 0x8013DB18: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013DB18: nop

    after_2:
    // 0x8013DB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013DB20:
    // 0x8013DB20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013DB24: jr          $ra
    // 0x8013DB28: nop

    return;
    // 0x8013DB28: nop

;}
RECOMP_FUNC void mvOpeningRoomTissuesProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320FC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132100: lw          $t6, 0x4CE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CE4);
    // 0x80132104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013210C: slti        $at, $t6, 0x230
    ctx->r1 = SIGNED(ctx->r14) < 0X230 ? 1 : 0;
    // 0x80132110: bnel        $at, $zero, L_80132124
    if (ctx->r1 != 0) {
        // 0x80132114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132124;
    }
    goto skip_0;
    // 0x80132114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132118: jal         0x8000DF34
    // 0x8013211C: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x8013211C: nop

    after_0:
    // 0x80132120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132124:
    // 0x80132124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132128: jr          $ra
    // 0x8013212C: nop

    return;
    // 0x8013212C: nop

;}
RECOMP_FUNC void scExplainFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E524: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E528: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E52C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E530: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E534: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E538: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E53C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E540: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E544: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E548: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E54C: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E550: jal         0x800FCB70
    // 0x8018E554: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E554: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E560: jr          $ra
    // 0x8018E564: nop

    return;
    // 0x8018E564: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801343C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801343CC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801343D0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801343D4: addiu       $s1, $s1, -0x6960
    ctx->r17 = ADD32(ctx->r17, -0X6960);
    // 0x801343D8: lw          $t9, 0x14($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X14);
    // 0x801343DC: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801343E0: addiu       $t0, $t0, 0x228
    ctx->r8 = ADD32(ctx->r8, 0X228);
    // 0x801343E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801343E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801343EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801343F0: addiu       $t6, $t6, 0x3A30
    ctx->r14 = ADD32(ctx->r14, 0X3A30);
    // 0x801343F4: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x801343F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801343FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134400: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80134404: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80134408: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8013440C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80134410: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80134414: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80134418: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8013441C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80134420: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134424: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134428: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8013442C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80134430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134438: jal         0x800CD050
    // 0x8013443C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x8013443C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_0:
    // 0x80134440: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80134444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134448: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x8013444C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80134450: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134454: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80134458: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x8013445C: addiu       $t0, $zero, 0xE3
    ctx->r8 = ADD32(0, 0XE3);
    // 0x80134460: addiu       $t2, $zero, 0xAC
    ctx->r10 = ADD32(0, 0XAC);
    // 0x80134464: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x80134468: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013446C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80134470: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134474: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80134478: addiu       $s2, $zero, -0x21
    ctx->r18 = ADD32(0, -0X21);
    // 0x8013447C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80134480: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80134484: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x80134488: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013448C: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80134490: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80134494: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80134498: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x8013449C: sb          $t0, 0x28($t1)
    MEM_B(0X28, ctx->r9) = ctx->r8;
    // 0x801344A0: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x801344A4: sb          $t2, 0x29($t3)
    MEM_B(0X29, ctx->r11) = ctx->r10;
    // 0x801344A8: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801344AC: sb          $t4, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r12;
    // 0x801344B0: jal         0x80133804
    // 0x801344B4: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    mnPlayers1PGameMakeTimeSelect(rdram, ctx);
        goto after_1;
    // 0x801344B4: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_1:
    // 0x801344B8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801344BC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801344C0: addiu       $t7, $t7, 0x15C8
    ctx->r15 = ADD32(ctx->r15, 0X15C8);
    // 0x801344C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801344C8: jal         0x800CCFDC
    // 0x801344CC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801344CC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x801344D0: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801344D4: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801344D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801344DC: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801344E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801344E4: and         $t0, $t8, $s2
    ctx->r8 = ctx->r24 & ctx->r18;
    // 0x801344E8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801344EC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801344F0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801344F4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801344F8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801344FC: lw          $t2, 0x14($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14);
    // 0x80134500: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80134504: addiu       $t3, $t3, 0x1EC8
    ctx->r11 = ADD32(ctx->r11, 0X1EC8);
    // 0x80134508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013450C: jal         0x800CCFDC
    // 0x80134510: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80134510: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80134514: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80134518: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8013451C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134520: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80134524: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134528: and         $t6, $t4, $s2
    ctx->r14 = ctx->r12 & ctx->r18;
    // 0x8013452C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80134530: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80134534: addiu       $t8, $zero, 0xAF
    ctx->r24 = ADD32(0, 0XAF);
    // 0x80134538: addiu       $t9, $zero, 0xB1
    ctx->r25 = ADD32(0, 0XB1);
    // 0x8013453C: addiu       $t0, $zero, 0xCC
    ctx->r8 = ADD32(0, 0XCC);
    // 0x80134540: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80134544: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80134548: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8013454C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80134550: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x80134554: sb          $t9, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r25;
    // 0x80134558: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    // 0x8013455C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80134560: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80134564: lw          $t1, 0x14($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X14);
    // 0x80134568: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x8013456C: addiu       $t2, $t2, 0x1208
    ctx->r10 = ADD32(ctx->r10, 0X1208);
    // 0x80134570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134574: jal         0x800CCFDC
    // 0x80134578: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80134578: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x8013457C: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80134580: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80134584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134588: lui         $at, 0x430D
    ctx->r1 = S32(0X430D << 16);
    // 0x8013458C: and         $t5, $t3, $s2
    ctx->r13 = ctx->r11 & ctx->r18;
    // 0x80134590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134594: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80134598: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8013459C: addiu       $t7, $zero, 0x57
    ctx->r15 = ADD32(0, 0X57);
    // 0x801345A0: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x801345A4: addiu       $t9, $zero, 0x88
    ctx->r25 = ADD32(0, 0X88);
    // 0x801345A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801345AC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801345B0: addiu       $t2, $zero, 0xB8
    ctx->r10 = ADD32(0, 0XB8);
    // 0x801345B4: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x801345B8: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801345BC: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x801345C0: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x801345C4: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x801345C8: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x801345CC: sb          $t0, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r8;
    // 0x801345D0: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
    // 0x801345D4: sb          $t1, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r9;
    // 0x801345D8: sh          $t2, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r10;
    // 0x801345DC: sh          $t3, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r11;
    // 0x801345E0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801345E4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801345E8: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x801345EC: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x801345F0: addiu       $t5, $t5, 0x488
    ctx->r13 = ADD32(ctx->r13, 0X488);
    // 0x801345F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801345F8: jal         0x800CCFDC
    // 0x801345FC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801345FC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80134600: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80134604: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x80134608: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013460C: lui         $at, 0x431F
    ctx->r1 = S32(0X431F << 16);
    // 0x80134610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134614: and         $t8, $t6, $s2
    ctx->r24 = ctx->r14 & ctx->r18;
    // 0x80134618: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x8013461C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80134620: addiu       $t0, $zero, 0xC5
    ctx->r8 = ADD32(0, 0XC5);
    // 0x80134624: addiu       $t1, $zero, 0xB6
    ctx->r9 = ADD32(0, 0XB6);
    // 0x80134628: addiu       $t2, $zero, 0xA7
    ctx->r10 = ADD32(0, 0XA7);
    // 0x8013462C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80134630: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80134634: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80134638: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x8013463C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80134640: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80134644: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
    // 0x80134648: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x8013464C: addiu       $t4, $t4, 0x5A8
    ctx->r12 = ADD32(ctx->r12, 0X5A8);
    // 0x80134650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134654: jal         0x800CCFDC
    // 0x80134658: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80134658: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_6:
    // 0x8013465C: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80134660: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80134664: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134668: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x8013466C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134670: and         $t7, $t5, $s2
    ctx->r15 = ctx->r13 & ctx->r18;
    // 0x80134674: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80134678: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013467C: addiu       $t9, $zero, 0xC5
    ctx->r25 = ADD32(0, 0XC5);
    // 0x80134680: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x80134684: addiu       $t1, $zero, 0xA7
    ctx->r9 = ADD32(0, 0XA7);
    // 0x80134688: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x8013468C: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80134690: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80134694: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80134698: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013469C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801346A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801346A4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801346A8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801346AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801346B0: jr          $ra
    // 0x801346B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801346B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftCommonHarisenSwingProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146C40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80146C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146C48: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80146C4C: lw          $a2, 0x84C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X84C);
    // 0x80146C50: beql        $a2, $zero, L_80146C8C
    if (ctx->r6 == 0) {
        // 0x80146C54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146C8C;
    }
    goto skip_0;
    // 0x80146C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80146C58: lw          $v0, 0x84($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84);
    // 0x80146C5C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80146C60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80146C64: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80146C68: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80146C6C: bnel        $t6, $at, L_80146C8C
    if (ctx->r14 != ctx->r1) {
        // 0x80146C70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146C8C;
    }
    goto skip_1;
    // 0x80146C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80146C74: jal         0x80175140
    // 0x80146C78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itHarisenCommonSetScale(rdram, ctx);
        goto after_0;
    // 0x80146C78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80146C7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80146C80: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80146C84: sw          $t7, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r15;
    // 0x80146C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146C8C:
    // 0x80146C8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146C90: jr          $ra
    // 0x80146C94: nop

    return;
    // 0x80146C94: nop

;}
RECOMP_FUNC void mnPlayersVSRecallPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137FF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137FFC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80138000: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80138004: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80138008: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013800C: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80138010: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80138014: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80138018: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8013801C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80138020: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x80138024: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x80138028: sw          $t8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r24;
    // 0x8013802C: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x80138030: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80138034: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80138038: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8013803C: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80138040: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80138044: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80138048: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
    // 0x8013804C: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x80138050: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80138054: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80138058: lwc1        $f6, 0x5C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x8013805C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80138060: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80138064: lw          $t1, 0x74($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X74);
    // 0x80138068: lwc1        $f8, 0x58($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8013806C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80138070: swc1        $f10, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f10.u32l;
    // 0x80138074: lwc1        $f16, 0x68($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68);
    // 0x80138078: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013807C: nop

    // 0x80138080: bc1fl       L_80138094
    if (!c1cs) {
        // 0x80138084: lw          $t2, 0x74($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X74);
            goto L_80138094;
    }
    goto skip_0;
    // 0x80138084: lw          $t2, 0x74($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X74);
    skip_0:
    // 0x80138088: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x8013808C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80138090: lw          $t2, 0x74($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X74);
L_80138094:
    // 0x80138094: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80138098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013809C: lwc1        $f18, 0x5C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x801380A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801380A4: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
    // 0x801380A8: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801380AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801380B0: nop

    // 0x801380B4: bc1fl       L_801380C8
    if (!c1cs) {
        // 0x801380B8: lwc1        $f2, 0x6C($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
            goto L_801380C8;
    }
    goto skip_1;
    // 0x801380B8: lwc1        $f2, 0x6C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
    skip_1:
    // 0x801380BC: swc1        $f2, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f2.u32l;
    // 0x801380C0: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801380C4: lwc1        $f2, 0x6C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X6C);
L_801380C8:
    // 0x801380C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801380CC: nop

    // 0x801380D0: bc1fl       L_801380E8
    if (!c1cs) {
        // 0x801380D4: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_801380E8;
    }
    goto skip_2;
    // 0x801380D4: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x801380D8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801380DC: jr          $ra
    // 0x801380E0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x801380E0: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x801380E4: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_801380E8:
    // 0x801380E8: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
    // 0x801380EC: jr          $ra
    // 0x801380F0: nop

    return;
    // 0x801380F0: nop

;}
RECOMP_FUNC void wpMainVelSetModelPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167FA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80167FA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80167FA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80167FAC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80167FB0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80167FB4: nop

    // 0x80167FB8: bc1f        L_80167FD4
    if (!c1cs) {
        // 0x80167FBC: nop
    
            goto L_80167FD4;
    }
    // 0x80167FBC: nop

    // 0x80167FC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80167FC4: lwc1        $f8, -0x3580($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3580);
    // 0x80167FC8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80167FCC: jr          $ra
    // 0x80167FD0: swc1        $f8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f8.u32l;
    return;
    // 0x80167FD0: swc1        $f8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f8.u32l;
L_80167FD4:
    // 0x80167FD4: lwc1        $f10, -0x357C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X357C);
    // 0x80167FD8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80167FDC: swc1        $f10, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f10.u32l;
    // 0x80167FE0: jr          $ra
    // 0x80167FE4: nop

    return;
    // 0x80167FE4: nop

;}
RECOMP_FUNC void ftKirbyCopyNessSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155DFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155E04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155E08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80155E0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80155E10: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155E14: jal         0x800E6F24
    // 0x80155E18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155E18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155E1C: jal         0x800E0830
    // 0x80155E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155E20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155E24: jal         0x80155DA4
    // 0x80155E28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyNessSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80155E28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80155E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155E34: jr          $ra
    // 0x80155E38: nop

    return;
    // 0x80155E38: nop

;}
RECOMP_FUNC void func_ovl8_8038440C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038440C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384414: jal         0x803725DC
    // 0x80384418: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x80384418: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8038441C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384424: jr          $ra
    // 0x80384428: nop

    return;
    // 0x80384428: nop

;}
RECOMP_FUNC void itRShellSpinEdgeInvertVelLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AC40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8017AC44: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017AC48: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8017AC4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017AC50: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017AC54: lwc1        $f8, 0x358($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X358);
    // 0x8017AC58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8017AC5C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8017AC60: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8017AC64: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x8017AC68: beq         $a1, $zero, L_8017AC78
    if (ctx->r5 == 0) {
        // 0x8017AC6C: swc1        $f10, 0x358($v0)
        MEM_W(0X358, ctx->r2) = ctx->f10.u32l;
            goto L_8017AC78;
    }
    // 0x8017AC6C: swc1        $f10, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->f10.u32l;
    // 0x8017AC70: jr          $ra
    // 0x8017AC74: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    return;
    // 0x8017AC74: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
L_8017AC78:
    // 0x8017AC78: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8017AC7C: jr          $ra
    // 0x8017AC80: nop

    return;
    // 0x8017AC80: nop

;}
RECOMP_FUNC void func_ovl34_80132328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132328: jr          $ra
    // 0x8013232C: nop

    return;
    // 0x8013232C: nop

;}
RECOMP_FUNC void ftFoxSpecialLwTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D05C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015D060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015D064: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015D068: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x8015D06C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D070: jal         0x800E6F24
    // 0x8015D074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015D078: jal         0x8015D01C
    // 0x8015D07C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwTurnInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8015D07C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015D080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D088: jr          $ra
    // 0x8015D08C: nop

    return;
    // 0x8015D08C: nop

;}
RECOMP_FUNC void itLinkBombExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018636C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80186370: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80186374: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80186378: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8018637C: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80186380: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80186384: jal         0x8017279C
    // 0x80186388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x80186388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018638C: jal         0x80185A80
    // 0x80186390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itLinkBombExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_1;
    // 0x80186390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80186394: jal         0x800269C0
    // 0x80186398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80186398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8018639C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801863A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801863A4: jr          $ra
    // 0x801863A8: nop

    return;
    // 0x801863A8: nop

;}
RECOMP_FUNC void itSpearFlyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FFA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017FFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FFB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017FFB4: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8017FFB8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8017FFBC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8017FFC0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8017FFC4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8017FFC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017FFCC: jal         0x80172558
    // 0x8017FFD0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017FFD0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8017FFD4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017FFD8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8017FFDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017FFE0: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x8017FFE4: lwc1        $f16, 0x2C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8017FFE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017FFEC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8017FFF0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8017FFF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017FFF8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017FFFC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80180000: bne         $v0, $at, L_8018007C
    if (ctx->r2 != ctx->r1) {
        // 0x80180004: swc1        $f18, 0x2C($a3)
        MEM_W(0X2C, ctx->r7) = ctx->f18.u32l;
            goto L_8018007C;
    }
    // 0x80180004: swc1        $f18, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f18.u32l;
    // 0x80180008: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x8018000C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80180010: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80180014: lh          $t0, 0x78($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X78);
    // 0x80180018: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8018001C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80180020: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80180024: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80180028: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018002C: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x80180030: nop

    // 0x80180034: bc1fl       L_80180080
    if (!c1cs) {
        // 0x80180038: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80180080;
    }
    goto skip_0;
    // 0x80180038: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8018003C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80180040: lhu         $t1, 0x350($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X350);
    // 0x80180044: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x80180048: beq         $t1, $zero, L_80180064
    if (ctx->r9 == 0) {
        // 0x8018004C: swc1        $f0, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
            goto L_80180064;
    }
    // 0x8018004C: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x80180050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80180054: jal         0x8017FDC0
    // 0x80180058: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itSpearFlyCallSwarmMember(rdram, ctx);
        goto after_1;
    // 0x80180058: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8018005C: b           L_8018006C
    // 0x80180060: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_8018006C;
    // 0x80180060: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80180064:
    // 0x80180064: b           L_801800FC
    // 0x80180068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801800FC;
    // 0x80180068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018006C:
    // 0x8018006C: lw          $t2, 0x354($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X354);
    // 0x80180070: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x80180074: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80180078: sw          $t3, 0x354($a3)
    MEM_W(0X354, ctx->r7) = ctx->r11;
L_8018007C:
    // 0x8018007C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80180080:
    // 0x80180080: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80180084: bne         $v0, $at, L_801800F8
    if (ctx->r2 != ctx->r1) {
        // 0x80180088: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_801800F8;
    }
    // 0x80180088: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8018008C: lw          $t4, 0x1300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1300);
    // 0x80180090: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80180094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80180098: lh          $t5, 0x7A($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X7A);
    // 0x8018009C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801800A0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801800A4: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x801800A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801800AC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801800B0: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x801800B4: nop

    // 0x801800B8: bc1fl       L_801800FC
    if (!c1cs) {
        // 0x801800BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801800FC;
    }
    goto skip_1;
    // 0x801800BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801800C0: lhu         $t7, 0x350($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X350);
    // 0x801800C4: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x801800C8: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x801800CC: beq         $t7, $zero, L_801800E4
    if (ctx->r15 == 0) {
        // 0x801800D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801800E4;
    }
    // 0x801800D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801800D4: jal         0x8017FDC0
    // 0x801800D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itSpearFlyCallSwarmMember(rdram, ctx);
        goto after_2;
    // 0x801800D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x801800DC: b           L_801800EC
    // 0x801800E0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_801800EC;
    // 0x801800E0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_801800E4:
    // 0x801800E4: b           L_801800FC
    // 0x801800E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801800FC;
    // 0x801800E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801800EC:
    // 0x801800EC: lw          $t8, 0x354($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X354);
    // 0x801800F0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801800F4: sw          $t9, 0x354($a3)
    MEM_W(0X354, ctx->r7) = ctx->r25;
L_801800F8:
    // 0x801800F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801800FC:
    // 0x801800FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180104: jr          $ra
    // 0x80180108: nop

    return;
    // 0x80180108: nop

;}
RECOMP_FUNC void ftSamusSpecialLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DF64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015DF68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DF6C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015DF70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015DF74: jal         0x8015DF00
    // 0x8015DF78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftSamusSpecialLwMakeBomb(rdram, ctx);
        goto after_0;
    // 0x8015DF78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015DF7C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DF80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015DF84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015DF88: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x8015DF8C: bne         $t8, $at, L_8015DFA4
    if (ctx->r24 != ctx->r1) {
        // 0x8015DF90: nop
    
            goto L_8015DFA4;
    }
    // 0x8015DF90: nop

    // 0x8015DF94: jal         0x8015E170
    // 0x8015DF98: nop

    ftSamusSpecialLwTransferStatusAir(rdram, ctx);
        goto after_1;
    // 0x8015DF98: nop

    after_1:
    // 0x8015DF9C: b           L_8015DFB0
    // 0x8015DFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015DFB0;
    // 0x8015DFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DFA4:
    // 0x8015DFA4: jal         0x800D94C4
    // 0x8015DFA8: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_2;
    // 0x8015DFA8: nop

    after_2:
    // 0x8015DFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DFB0:
    // 0x8015DFB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015DFB4: jr          $ra
    // 0x8015DFB8: nop

    return;
    // 0x8015DFB8: nop

;}
RECOMP_FUNC void ftCommonLiftTurnUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146138: lw          $t6, 0xB18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB18);
    // 0x8014613C: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80146140: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146144: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80146148: sw          $t7, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r15;
    // 0x8014614C: lwc1        $f6, -0x3E6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3E6C);
    // 0x80146150: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80146154: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80146158: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014615C: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80146160: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    // 0x80146164: jal         0x800EB528
    // 0x80146168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x80146168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014616C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80146170: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80146174: lw          $t8, 0xB18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XB18);
    // 0x80146178: bnel        $t8, $at, L_8014619C
    if (ctx->r24 != ctx->r1) {
        // 0x8014617C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014619C;
    }
    goto skip_0;
    // 0x8014617C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80146180: lwc1        $f10, 0x60($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X60);
    // 0x80146184: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x80146188: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8014618C: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80146190: sw          $t0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r8;
    // 0x80146194: swc1        $f16, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f16.u32l;
    // 0x80146198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014619C:
    // 0x8014619C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801461A0: jr          $ra
    // 0x801461A4: nop

    return;
    // 0x801461A4: nop

;}
RECOMP_FUNC void func_ovl8_8037E80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E80C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037E810: jr          $ra
    // 0x8037E814: lhu         $v0, -0xFF4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFF4);
    return;
    // 0x8037E814: lhu         $v0, -0xFF4($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFF4);
;}
RECOMP_FUNC void itMLuckyMakeEggProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018136C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181370: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80181374: jal         0x801735A0
    // 0x80181378: addiu       $a1, $a1, 0x10E0
    ctx->r5 = ADD32(ctx->r5, 0X10E0);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80181378: addiu       $a1, $a1, 0x10E0
    ctx->r5 = ADD32(ctx->r5, 0X10E0);
    after_0:
    // 0x8018137C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181388: jr          $ra
    // 0x8018138C: nop

    return;
    // 0x8018138C: nop

;}
RECOMP_FUNC void func_ovl52_80131C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C28: jr          $ra
    // 0x80131C2C: nop

    return;
    // 0x80131C2C: nop

;}
RECOMP_FUNC void func_ovl27_801381D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801381D0: jr          $ra
    // 0x801381D4: nop

    return;
    // 0x801381D4: nop

;}
RECOMP_FUNC void mnDataSetOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B50: addiu       $t6, $t6, 0x2F68
    ctx->r14 = ADD32(ctx->r14, 0X2F68);
    // 0x80131B54: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B5C: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80131B60: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B64: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80131B68: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131B6C: addiu       $t9, $t9, 0x2F70
    ctx->r25 = ADD32(ctx->r25, 0X2F70);
    // 0x80131B70: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80131B74: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131B78: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80131B7C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131B80: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80131B84: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80131B88: addiu       $t2, $t2, 0x2F78
    ctx->r10 = ADD32(ctx->r10, 0X2F78);
    // 0x80131B8C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x80131B90: sh          $t1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r9;
    // 0x80131B94: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131B98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131B9C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80131BA0: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x80131BA4: beq         $a1, $zero, L_80131BCC
    if (ctx->r5 == 0) {
        // 0x80131BA8: sh          $t4, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r12;
            goto L_80131BCC;
    }
    // 0x80131BA8: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x80131BAC: beq         $a1, $at, L_80131BC4
    if (ctx->r5 == ctx->r1) {
        // 0x80131BB0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80131BC4;
    }
    // 0x80131BB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131BB4: beq         $a1, $at, L_80131BD4
    if (ctx->r5 == ctx->r1) {
        // 0x80131BB8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80131BD4;
    }
    // 0x80131BB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BBC: b           L_80131BD4
    // 0x80131BC0: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
        goto L_80131BD4;
    // 0x80131BC0: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_80131BC4:
    // 0x80131BC4: b           L_80131BD4
    // 0x80131BC8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80131BD4;
    // 0x80131BC8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80131BCC:
    // 0x80131BCC: b           L_80131BD4
    // 0x80131BD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80131BD4;
    // 0x80131BD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80131BD4:
    // 0x80131BD4: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80131BD8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80131BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80131BE0:
    // 0x80131BE0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80131BE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80131BE8: sb          $t5, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r13;
    // 0x80131BEC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80131BF0: sb          $t6, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r14;
    // 0x80131BF4: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x80131BF8: sb          $t7, 0x62($v1)
    MEM_B(0X62, ctx->r3) = ctx->r15;
    // 0x80131BFC: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80131C00: sb          $t8, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r24;
    // 0x80131C04: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80131C08: sb          $t9, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r25;
    // 0x80131C0C: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    // 0x80131C10: sb          $t0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r8;
    // 0x80131C14: bne         $a1, $a0, L_80131BE0
    if (ctx->r5 != ctx->r4) {
        // 0x80131C18: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_80131BE0;
    }
    // 0x80131C18: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80131C1C: jr          $ra
    // 0x80131C20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131C20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl34_80132320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132320: jr          $ra
    // 0x80132324: nop

    return;
    // 0x80132324: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015560C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155610: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155614: jal         0x800DE80C
    // 0x80155618: addiu       $a1, $a1, 0x562C
    ctx->r5 = ADD32(ctx->r5, 0X562C);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x80155618: addiu       $a1, $a1, 0x562C
    ctx->r5 = ADD32(ctx->r5, 0X562C);
    after_0:
    // 0x8015561C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155624: jr          $ra
    // 0x80155628: nop

    return;
    // 0x80155628: nop

;}
RECOMP_FUNC void itMarumineExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80183A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183A28: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80183A2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80183A30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80183A34: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80183A38: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80183A3C: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80183A40: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80183A44: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    // 0x80183A48: jal         0x80183830
    // 0x80183A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMarumineExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80183A4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80183A50: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80183A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80183A58: addiu       $a1, $a1, -0x4BCC
    ctx->r5 = ADD32(ctx->r5, -0X4BCC);
    // 0x80183A5C: jal         0x80172EC8
    // 0x80183A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80183A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80183A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80183A6C: jr          $ra
    // 0x80183A70: nop

    return;
    // 0x80183A70: nop

;}
RECOMP_FUNC void unref_80015A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015A58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80015A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015A60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80015A64: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80015A68: lbu         $t6, 0x54($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X54);
    // 0x80015A6C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80015A70: bnel        $t7, $zero, L_80015BFC
    if (ctx->r15 != 0) {
        // 0x80015A74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80015BFC;
    }
    goto skip_0;
    // 0x80015A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80015A78: lw          $v1, 0x50($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X50);
    // 0x80015A7C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80015A80: addiu       $s0, $s0, 0x72A8
    ctx->r16 = ADD32(ctx->r16, 0X72A8);
    // 0x80015A84: beq         $v1, $zero, L_80015BF8
    if (ctx->r3 == 0) {
        // 0x80015A88: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80015BF8;
    }
    // 0x80015A88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015A8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015A90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015A94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80015A98: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80015A9C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80015AA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80015AA4: jal         0x80014798
    // 0x80015AA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80015AA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80015AAC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80015AB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80015AB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80015AB8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80015ABC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80015AC0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80015AC4: nop

    // 0x80015AC8: bc1f        L_80015AF4
    if (!c1cs) {
        // 0x80015ACC: nop
    
            goto L_80015AF4;
    }
    // 0x80015ACC: nop

    // 0x80015AD0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80015AD4:
    // 0x80015AD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80015AD8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80015ADC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80015AE0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80015AE4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80015AE8: nop

    // 0x80015AEC: bc1tl       L_80015AD4
    if (c1cs) {
        // 0x80015AF0: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80015AD4;
    }
    goto skip_1;
    // 0x80015AF0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80015AF4:
    // 0x80015AF4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80015AF8: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80015AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80015B00: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80015B04: jal         0x80010D70
    // 0x80015B08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_1;
    // 0x80015B08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80015B0C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80015B10: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80015B14: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80015B18: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80015B1C: beql        $t0, $zero, L_80015B70
    if (ctx->r8 == 0) {
        // 0x80015B20: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80015B70;
    }
    goto skip_2;
    // 0x80015B20: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_2:
    // 0x80015B24: lbu         $t1, 0x54($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X54);
    // 0x80015B28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80015B2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015B30: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80015B34: bnel        $t2, $zero, L_80015B70
    if (ctx->r10 != 0) {
        // 0x80015B38: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80015B70;
    }
    goto skip_3;
    // 0x80015B38: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_3:
    // 0x80015B3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80015B40: jal         0x80012D90
    // 0x80015B44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x80015B44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80015B48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80015B4C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80015B50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80015B54: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80015B58: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80015B5C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80015B60: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80015B64: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80015B68: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80015B6C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_80015B70:
    // 0x80015B70: beql        $a0, $zero, L_80015B88
    if (ctx->r4 == 0) {
        // 0x80015B74: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80015B88;
    }
    goto skip_4;
    // 0x80015B74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x80015B78: jal         0x80015890
    // 0x80015B7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcDrawDObjTreeDLDoubleArray(rdram, ctx);
        goto after_3;
    // 0x80015B7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80015B80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80015B84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_80015B88:
    // 0x80015B88: beql        $t6, $zero, L_80015BD0
    if (ctx->r14 == 0) {
        // 0x80015B8C: lw          $t2, 0xC($a2)
        ctx->r10 = MEM_W(ctx->r6, 0XC);
            goto L_80015BD0;
    }
    goto skip_5;
    // 0x80015B8C: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    skip_5:
    // 0x80015B90: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80015B94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80015B98: lui         $t0, 0xD838
    ctx->r8 = S32(0XD838 << 16);
    // 0x80015B9C: beql        $t7, $at, L_80015BB4
    if (ctx->r15 == ctx->r1) {
        // 0x80015BA0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80015BB4;
    }
    goto skip_6;
    // 0x80015BA0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x80015BA4: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x80015BA8: beql        $t8, $zero, L_80015BD0
    if (ctx->r24 == 0) {
        // 0x80015BAC: lw          $t2, 0xC($a2)
        ctx->r10 = MEM_W(ctx->r6, 0XC);
            goto L_80015BD0;
    }
    goto skip_7;
    // 0x80015BAC: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    skip_7:
    // 0x80015BB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80015BB4:
    // 0x80015BB4: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x80015BB8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80015BBC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80015BC0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80015BC4: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80015BC8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80015BCC: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
L_80015BD0:
    // 0x80015BD0: bnel        $t2, $zero, L_80015BFC
    if (ctx->r10 != 0) {
        // 0x80015BD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80015BFC;
    }
    goto skip_8;
    // 0x80015BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80015BD8: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x80015BDC: beql        $s0, $zero, L_80015BFC
    if (ctx->r16 == 0) {
        // 0x80015BE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80015BFC;
    }
    goto skip_9;
    // 0x80015BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
L_80015BE4:
    // 0x80015BE4: jal         0x80015890
    // 0x80015BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTreeDLDoubleArray(rdram, ctx);
        goto after_4;
    // 0x80015BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80015BEC: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80015BF0: bne         $s0, $zero, L_80015BE4
    if (ctx->r16 != 0) {
        // 0x80015BF4: nop
    
            goto L_80015BE4;
    }
    // 0x80015BF4: nop

L_80015BF8:
    // 0x80015BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80015BFC:
    // 0x80015BFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015C00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80015C04: jr          $ra
    // 0x80015C08: nop

    return;
    // 0x80015C08: nop

;}
RECOMP_FUNC void efManagerShieldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101008: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8010100C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80101010: beq         $t6, $zero, L_8010101C
    if (ctx->r14 == 0) {
        // 0x80101014: nop
    
            goto L_8010101C;
    }
    // 0x80101014: nop

    // 0x80101018: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
L_8010101C:
    // 0x8010101C: jr          $ra
    // 0x80101020: nop

    return;
    // 0x80101020: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CB10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015CB14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015CB18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015CB1C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015CB20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015CB24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015CB28: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015CB2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CB30: jal         0x800E6F24
    // 0x8015CB34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CB34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015CB38: jal         0x800E0830
    // 0x8015CB3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015CB3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015CB40: jal         0x8015CAA4
    // 0x8015CB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftFoxSpecialHiStartInitGravity(rdram, ctx);
        goto after_2;
    // 0x8015CB44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015CB48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8015CB4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015CB50: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8015CB54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015CB58: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015CB5C: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8015CB60: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x8015CB64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015CB68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015CB6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015CB70: jr          $ra
    // 0x8015CB74: nop

    return;
    // 0x8015CB74: nop

;}
RECOMP_FUNC void ftLinkSpecialAirLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801644D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801644D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801644DC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801644E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801644E4: jal         0x800DE6B0
    // 0x801644E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801644E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801644EC: beql        $v0, $zero, L_80164518
    if (ctx->r2 == 0) {
        // 0x801644F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80164518;
    }
    goto skip_0;
    // 0x801644F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801644F4: jal         0x800DEE98
    // 0x801644F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x801644F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801644FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80164500: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80164504: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164508: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8016450C: jal         0x800E6F24
    // 0x80164510: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80164510: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80164514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80164518:
    // 0x80164518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016451C: jr          $ra
    // 0x80164520: nop

    return;
    // 0x80164520: nop

;}
RECOMP_FUNC void gcSetDObjAnimLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E044: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8000E048: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8000E04C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8000E050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E054: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8000E058: beq         $v0, $zero, L_8000E07C
    if (ctx->r2 == 0) {
        // 0x8000E05C: swc1        $f6, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->f6.u32l;
            goto L_8000E07C;
    }
    // 0x8000E05C: swc1        $f6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f6.u32l;
    // 0x8000E060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000E064: nop

    // 0x8000E068: div.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8000E06C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_8000E070:
    // 0x8000E070: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000E074: bnel        $v0, $zero, L_8000E070
    if (ctx->r2 != 0) {
        // 0x8000E078: swc1        $f0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
            goto L_8000E070;
    }
    goto skip_0;
    // 0x8000E078: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    skip_0:
L_8000E07C:
    // 0x8000E07C: jr          $ra
    // 0x8000E080: nop

    return;
    // 0x8000E080: nop

;}
RECOMP_FUNC void itLizardonFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F5C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F5C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F5CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F5D0: addiu       $a1, $a1, -0x529C
    ctx->r5 = ADD32(ctx->r5, -0X529C);
    // 0x8017F5D4: jal         0x80172EC8
    // 0x8017F5D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017F5D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8017F5DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F5E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F5E4: jr          $ra
    // 0x8017F5E8: nop

    return;
    // 0x8017F5E8: nop

;}
RECOMP_FUNC void func_ovl2_801017E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801017E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801017EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801017F0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801017F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801017F8: jal         0x8000DF34
    // 0x801017FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x801017FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101800: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80101804: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80101808: bne         $v0, $zero, L_80101828
    if (ctx->r2 != 0) {
        // 0x8010180C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80101828;
    }
    // 0x8010180C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80101810: jal         0x800FD4F8
    // 0x80101814: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x80101814: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80101818: jal         0x80009A84
    // 0x8010181C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8010181C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80101820: b           L_80101830
    // 0x80101824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80101830;
    // 0x80101824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101828:
    // 0x80101828: sw          $t6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r14;
    // 0x8010182C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101830:
    // 0x80101830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80101834: jr          $ra
    // 0x80101838: nop

    return;
    // 0x80101838: nop

;}
RECOMP_FUNC void mvOpeningRoomFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134400: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134404: addiu       $v1, $v1, 0x4CE4
    ctx->r3 = ADD32(ctx->r3, 0X4CE4);
    // 0x80134408: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013440C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134414: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80134418: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x8013441C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134420: bne         $at, $zero, L_80134778
    if (ctx->r1 != 0) {
        // 0x80134424: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80134778;
    }
    // 0x80134424: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134428: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013442C: addiu       $a2, $a2, 0x4D54
    ctx->r6 = ADD32(ctx->r6, 0X4D54);
    // 0x80134430: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80134434: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80134438: beq         $v0, $zero, L_80134444
    if (ctx->r2 == 0) {
        // 0x8013443C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80134444;
    }
    // 0x8013443C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80134440: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80134444:
    // 0x80134444: jal         0x80390A04
    // 0x80134448: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80134448: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x8013444C: beq         $v0, $zero, L_80134468
    if (ctx->r2 == 0) {
        // 0x80134450: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_80134468;
    }
    // 0x80134450: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80134454: jal         0x80390AC0
    // 0x80134458: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80134458: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x8013445C: beq         $v0, $zero, L_80134468
    if (ctx->r2 == 0) {
        // 0x80134460: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80134468;
    }
    // 0x80134460: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134464: sw          $zero, 0x4D54($at)
    MEM_W(0X4D54, ctx->r1) = 0;
L_80134468:
    // 0x80134468: jal         0x8039076C
    // 0x8013446C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x8013446C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80134470: beq         $v0, $zero, L_80134490
    if (ctx->r2 == 0) {
        // 0x80134474: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80134490;
    }
    // 0x80134474: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134478: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013447C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80134480: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134484: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80134488: jal         0x80005C74
    // 0x8013448C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x8013448C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
L_80134490:
    // 0x80134490: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134494: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x80134498: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x8013449C: bne         $v0, $at, L_801344E0
    if (ctx->r2 != ctx->r1) {
        // 0x801344A0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801344E0;
    }
    // 0x801344A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344A4: jal         0x80132330
    // 0x801344A8: lw          $a0, 0x4CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF8);
    mvOpeningRoomMakePulledFighter(rdram, ctx);
        goto after_4;
    // 0x801344A8: lw          $a0, 0x4CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF8);
    after_4:
    // 0x801344AC: jal         0x80131F7C
    // 0x801344B0: nop

    mvOpeningRoomMakePencils(rdram, ctx);
        goto after_5;
    // 0x801344B0: nop

    after_5:
    // 0x801344B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344B8: jal         0x80009A84
    // 0x801344BC: lw          $a0, 0x4D00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D00);
    gcEjectGObj(rdram, ctx);
        goto after_6;
    // 0x801344BC: lw          $a0, 0x4D00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D00);
    after_6:
    // 0x801344C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344C4: jal         0x80009A84
    // 0x801344C8: lw          $a0, 0x4D3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D3C);
    gcEjectGObj(rdram, ctx);
        goto after_7;
    // 0x801344C8: lw          $a0, 0x4D3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D3C);
    after_7:
    // 0x801344CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344D0: jal         0x80009A84
    // 0x801344D4: lw          $a0, 0x4D30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D30);
    gcEjectGObj(rdram, ctx);
        goto after_8;
    // 0x801344D4: lw          $a0, 0x4D30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D30);
    after_8:
    // 0x801344D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801344DC: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_801344E0:
    // 0x801344E0: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x801344E4: bne         $v0, $at, L_801344FC
    if (ctx->r2 != ctx->r1) {
        // 0x801344E8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801344FC;
    }
    // 0x801344E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344EC: jal         0x80132928
    // 0x801344F0: lw          $a0, 0x4CFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CFC);
    mvOpeningRoomMakeDroppedFighter(rdram, ctx);
        goto after_9;
    // 0x801344F0: lw          $a0, 0x4CFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CFC);
    after_9:
    // 0x801344F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801344F8: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_801344FC:
    // 0x801344FC: addiu       $at, $zero, 0x17C
    ctx->r1 = ADD32(0, 0X17C);
    // 0x80134500: bne         $v0, $at, L_8013455C
    if (ctx->r2 != ctx->r1) {
        // 0x80134504: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8013455C;
    }
    // 0x80134504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134508: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8013450C: ori         $a1, $a1, 0x9
    ctx->r5 = ctx->r5 | 0X9;
    // 0x80134510: jal         0x803905CC
    // 0x80134514: lw          $a0, 0x4D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D04);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_10;
    // 0x80134514: lw          $a0, 0x4D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D04);
    after_10:
    // 0x80134518: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013451C: lw          $t2, 0x4D04($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4D04);
    // 0x80134520: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80134524: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134528: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8013452C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80134530: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134534: swc1        $f4, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f4.u32l;
    // 0x80134538: lw          $t4, 0x4D04($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4D04);
    // 0x8013453C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80134540: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134544: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80134548: swc1        $f6, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f6.u32l;
    // 0x8013454C: lw          $t6, 0x4D04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4D04);
    // 0x80134550: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80134554: swc1        $f8, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f8.u32l;
    // 0x80134558: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_8013455C:
    // 0x8013455C: addiu       $at, $zero, 0x1C2
    ctx->r1 = ADD32(0, 0X1C2);
    // 0x80134560: bnel        $v0, $at, L_80134588
    if (ctx->r2 != ctx->r1) {
        // 0x80134564: addiu       $at, $zero, 0x230
        ctx->r1 = ADD32(0, 0X230);
            goto L_80134588;
    }
    goto skip_0;
    // 0x80134564: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
    skip_0:
    // 0x80134568: jal         0x80132CEC
    // 0x8013456C: nop

    mvOpeningRoomMakeCloseUpOverlay(rdram, ctx);
        goto after_11;
    // 0x8013456C: nop

    after_11:
    // 0x80134570: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134574: jal         0x80009A84
    // 0x80134578: lw          $a0, 0x4D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D10);
    gcEjectGObj(rdram, ctx);
        goto after_12;
    // 0x80134578: lw          $a0, 0x4D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D10);
    after_12:
    // 0x8013457C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134580: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x80134584: addiu       $at, $zero, 0x230
    ctx->r1 = ADD32(0, 0X230);
L_80134588:
    // 0x80134588: bnel        $v0, $at, L_801345C0
    if (ctx->r2 != ctx->r1) {
        // 0x8013458C: addiu       $at, $zero, 0x1F4
        ctx->r1 = ADD32(0, 0X1F4);
            goto L_801345C0;
    }
    goto skip_1;
    // 0x8013458C: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    skip_1:
    // 0x80134590: jal         0x80134184
    // 0x80134594: nop

    mvOpeningRoomEjectCameraGObjs(rdram, ctx);
        goto after_13;
    // 0x80134594: nop

    after_13:
    // 0x80134598: jal         0x80133470
    // 0x8013459C: nop

    mvOpeningRoomMakeScene2Cameras(rdram, ctx);
        goto after_14;
    // 0x8013459C: nop

    after_14:
    // 0x801345A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801345A4: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x801345A8: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    // 0x801345AC: jal         0x803905CC
    // 0x801345B0: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_15;
    // 0x801345B0: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    after_15:
    // 0x801345B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801345B8: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x801345BC: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
L_801345C0:
    // 0x801345C0: bne         $v0, $at, L_801345E8
    if (ctx->r2 != ctx->r1) {
        // 0x801345C4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801345E8;
    }
    // 0x801345C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801345C8: lw          $a0, 0x4D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D04);
    // 0x801345CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x801345D0: jal         0x8000A0D0
    // 0x801345D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_16;
    // 0x801345D4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_16:
    // 0x801345D8: jal         0x801330B8
    // 0x801345DC: nop

    mvOpeningRoomMakeSpotlight(rdram, ctx);
        goto after_17;
    // 0x801345DC: nop

    after_17:
    // 0x801345E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801345E4: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_801345E8:
    // 0x801345E8: addiu       $at, $zero, 0x35C
    ctx->r1 = ADD32(0, 0X35C);
    // 0x801345EC: bnel        $v0, $at, L_8013462C
    if (ctx->r2 != ctx->r1) {
        // 0x801345F0: addiu       $at, $zero, 0x40D
        ctx->r1 = ADD32(0, 0X40D);
            goto L_8013462C;
    }
    goto skip_2;
    // 0x801345F0: addiu       $at, $zero, 0x40D
    ctx->r1 = ADD32(0, 0X40D);
    skip_2:
    // 0x801345F4: jal         0x80134184
    // 0x801345F8: nop

    mvOpeningRoomEjectCameraGObjs(rdram, ctx);
        goto after_18;
    // 0x801345F8: nop

    after_18:
    // 0x801345FC: jal         0x801336A8
    // 0x80134600: nop

    mvOpeningRoomMakeScene3Cameras(rdram, ctx);
        goto after_19;
    // 0x80134600: nop

    after_19:
    // 0x80134604: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134608: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8013460C: ori         $a1, $a1, 0x11
    ctx->r5 = ctx->r5 | 0X11;
    // 0x80134610: jal         0x803905CC
    // 0x80134614: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_20;
    // 0x80134614: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    after_20:
    // 0x80134618: jal         0x80132680
    // 0x8013461C: nop

    mvOpeningRoomMakeSnap(rdram, ctx);
        goto after_21;
    // 0x8013461C: nop

    after_21:
    // 0x80134620: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134624: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x80134628: addiu       $at, $zero, 0x40D
    ctx->r1 = ADD32(0, 0X40D);
L_8013462C:
    // 0x8013462C: bne         $v0, $at, L_80134654
    if (ctx->r2 != ctx->r1) {
        // 0x80134630: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80134654;
    }
    // 0x80134630: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134634: lw          $t8, 0x4D50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4D50);
    // 0x80134638: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8013463C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134640: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    // 0x80134644: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x80134648: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8013464C: sw          $t0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r8;
    // 0x80134650: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_80134654:
    // 0x80134654: addiu       $at, $zero, 0x410
    ctx->r1 = ADD32(0, 0X410);
    // 0x80134658: bne         $v0, $at, L_801346B0
    if (ctx->r2 != ctx->r1) {
        // 0x8013465C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801346B0;
    }
    // 0x8013465C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134660: jal         0x80009A84
    // 0x80134664: lw          $a0, 0x4D3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D3C);
    gcEjectGObj(rdram, ctx);
        goto after_22;
    // 0x80134664: lw          $a0, 0x4D3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D3C);
    after_22:
    // 0x80134668: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013466C: jal         0x80009A84
    // 0x80134670: lw          $a0, 0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D40);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80134670: lw          $a0, 0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D40);
    after_23:
    // 0x80134674: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134678: jal         0x80009A84
    // 0x8013467C: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    gcEjectGObj(rdram, ctx);
        goto after_24;
    // 0x8013467C: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    after_24:
    // 0x80134680: jal         0x8013407C
    // 0x80134684: nop

    mvOpeningRoomMakeTransitionCamera(rdram, ctx);
        goto after_25;
    // 0x80134684: nop

    after_25:
    // 0x80134688: jal         0x80133EFC
    // 0x8013468C: nop

    mvOpeningRoomMakeTransition(rdram, ctx);
        goto after_26;
    // 0x8013468C: nop

    after_26:
    // 0x80134690: jal         0x801331B0
    // 0x80134694: nop

    mvOpeningRoomEjectRoomGObjs(rdram, ctx);
        goto after_27;
    // 0x80134694: nop

    after_27:
    // 0x80134698: jal         0x80132AE4
    // 0x8013469C: nop

    mvOpeningRoomMakeDeskGround(rdram, ctx);
        goto after_28;
    // 0x8013469C: nop

    after_28:
    // 0x801346A0: jal         0x80132F44
    // 0x801346A4: nop

    mvOpeningRoomMakeWallpaper(rdram, ctx);
        goto after_29;
    // 0x801346A4: nop

    after_29:
    // 0x801346A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801346AC: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_801346B0:
    // 0x801346B0: addiu       $at, $zero, 0x474
    ctx->r1 = ADD32(0, 0X474);
    // 0x801346B4: bnel        $v0, $at, L_80134730
    if (ctx->r2 != ctx->r1) {
        // 0x801346B8: addiu       $at, $zero, 0x438
        ctx->r1 = ADD32(0, 0X438);
            goto L_80134730;
    }
    goto skip_3;
    // 0x801346B8: addiu       $at, $zero, 0x438
    ctx->r1 = ADD32(0, 0X438);
    skip_3:
    // 0x801346BC: jal         0x80134184
    // 0x801346C0: nop

    mvOpeningRoomEjectCameraGObjs(rdram, ctx);
        goto after_30;
    // 0x801346C0: nop

    after_30:
    // 0x801346C4: jal         0x80132738
    // 0x801346C8: nop

    mvOpeningRoomMakeCloseUpEffect(rdram, ctx);
        goto after_31;
    // 0x801346C8: nop

    after_31:
    // 0x801346CC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801346D0: lw          $t1, 0x4D04($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4D04);
    // 0x801346D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801346D8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801346DC: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x801346E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801346E4: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801346E8: swc1        $f10, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f10.u32l;
    // 0x801346EC: lw          $t3, 0x4D04($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4D04);
    // 0x801346F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801346F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801346F8: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x801346FC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80134700: ori         $a1, $a1, 0xA
    ctx->r5 = ctx->r5 | 0XA;
    // 0x80134704: swc1        $f16, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f16.u32l;
    // 0x80134708: lw          $t5, 0x4D04($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4D04);
    // 0x8013470C: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x80134710: swc1        $f18, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f18.u32l;
    // 0x80134714: jal         0x803905CC
    // 0x80134718: lw          $a0, 0x4D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D04);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_32;
    // 0x80134718: lw          $a0, 0x4D04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D04);
    after_32:
    // 0x8013471C: jal         0x801338D4
    // 0x80134720: nop

    mvOpeningRoomMakeScene4Cameras(rdram, ctx);
        goto after_33;
    // 0x80134720: nop

    after_33:
    // 0x80134724: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134728: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x8013472C: addiu       $at, $zero, 0x438
    ctx->r1 = ADD32(0, 0X438);
L_80134730:
    // 0x80134730: bne         $v0, $at, L_80134754
    if (ctx->r2 != ctx->r1) {
        // 0x80134734: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134754;
    }
    // 0x80134734: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134738: jal         0x80009A84
    // 0x8013473C: lw          $a0, 0x4D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D4C);
    gcEjectGObj(rdram, ctx);
        goto after_34;
    // 0x8013473C: lw          $a0, 0x4D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D4C);
    after_34:
    // 0x80134740: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134744: jal         0x80009A84
    // 0x80134748: lw          $a0, 0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D48);
    gcEjectGObj(rdram, ctx);
        goto after_35;
    // 0x80134748: lw          $a0, 0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4D48);
    after_35:
    // 0x8013474C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134750: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_80134754:
    // 0x80134754: addiu       $at, $zero, 0x528
    ctx->r1 = ADD32(0, 0X528);
    // 0x80134758: bne         $v0, $at, L_80134778
    if (ctx->r2 != ctx->r1) {
        // 0x8013475C: addiu       $t8, $zero, 0x1D
        ctx->r24 = ADD32(0, 0X1D);
            goto L_80134778;
    }
    // 0x8013475C: addiu       $t8, $zero, 0x1D
    ctx->r24 = ADD32(0, 0X1D);
    // 0x80134760: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134764: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80134768: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8013476C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80134770: jal         0x80005C74
    // 0x80134774: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_36;
    // 0x80134774: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_36:
L_80134778:
    // 0x80134778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013477C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134780: jr          $ra
    // 0x80134784: nop

    return;
    // 0x80134784: nop

;}
RECOMP_FUNC void itVisualsUpdateSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801713F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801713F8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801713FC: lwc1        $f6, 0x344($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X344);
    // 0x80171400: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80171404: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171408: jr          $ra
    // 0x8017140C: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    return;
    // 0x8017140C: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameCheckTimeArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135594: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135598: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013559C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801355A0: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801355A4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801355A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801355AC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801355B0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801355B4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801355B8: nop

    // 0x801355BC: bc1t        L_801355DC
    if (c1cs) {
        // 0x801355C0: nop
    
            goto L_801355DC;
    }
    // 0x801355C0: nop

    // 0x801355C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801355C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801355CC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801355D0: nop

    // 0x801355D4: bc1f        L_801355E4
    if (!c1cs) {
        // 0x801355D8: nop
    
            goto L_801355E4;
    }
    // 0x801355D8: nop

L_801355DC:
    // 0x801355DC: b           L_801355E4
    // 0x801355E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801355E4;
    // 0x801355E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801355E4:
    // 0x801355E4: beq         $v1, $zero, L_801355F4
    if (ctx->r3 == 0) {
        // 0x801355E8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801355F4;
    }
    // 0x801355E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801355EC: jr          $ra
    // 0x801355F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801355F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801355F4:
    // 0x801355F4: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801355F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801355FC: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80135600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135604: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80135608: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8013560C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135614: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80135618: nop

    // 0x8013561C: bc1f        L_80135644
    if (!c1cs) {
        // 0x80135620: nop
    
            goto L_80135644;
    }
    // 0x80135620: nop

    // 0x80135624: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135628: nop

    // 0x8013562C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135630: nop

    // 0x80135634: bc1f        L_80135644
    if (!c1cs) {
        // 0x80135638: nop
    
            goto L_80135644;
    }
    // 0x80135638: nop

    // 0x8013563C: b           L_80135644
    // 0x80135640: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135644;
    // 0x80135640: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135644:
    // 0x80135644: beq         $v1, $zero, L_80135654
    if (ctx->r3 == 0) {
        // 0x80135648: nop
    
            goto L_80135654;
    }
    // 0x80135648: nop

    // 0x8013564C: jr          $ra
    // 0x80135650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135654:
    // 0x80135654: jr          $ra
    // 0x80135658: nop

    return;
    // 0x80135658: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftNessSpecialHiUpdateModelPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015475C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154760: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154764: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80154768: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8015476C: jal         0x8001863C
    // 0x80154770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80154770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80154774: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80154778: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015477C: lwc1        $f10, -0x3A24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A24);
    // 0x80154780: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80154784: lw          $t7, 0x8F8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8F8);
    // 0x80154788: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8015478C: nop

    // 0x80154790: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80154794: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80154798: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8015479C: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x801547A0: jal         0x800EB528
    // 0x801547A4: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_1;
    // 0x801547A4: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    after_1:
    // 0x801547A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801547AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801547B0: jr          $ra
    // 0x801547B4: nop

    return;
    // 0x801547B4: nop

;}
RECOMP_FUNC void mnPlayersVSCheckFighterCrossed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131ED8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131EDC: jr          $ra
    // 0x80131EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void lbCommonAddDObjAnimJointAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8758: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C875C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C8760: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C8764: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C8768: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C876C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C8770: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C8774: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800C8778: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C877C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8780: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C8784: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C8788: beq         $a0, $zero, L_800C87D4
    if (ctx->r4 == 0) {
        // 0x800C878C: swc1        $f20, 0x78($t6)
        MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
            goto L_800C87D4;
    }
    // 0x800C878C: swc1        $f20, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
    // 0x800C8790: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C8794: lwc1        $f22, 0x5E7C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5E7C);
L_800C8798:
    // 0x800C8798: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800C879C: beql        $a1, $zero, L_800C87BC
    if (ctx->r5 == 0) {
        // 0x800C87A0: swc1        $f22, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
            goto L_800C87BC;
    }
    goto skip_0;
    // 0x800C87A0: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
    skip_0:
    // 0x800C87A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C87A8: jal         0x8000BD1C
    // 0x800C87AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800C87AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C87B0: b           L_800C87C0
    // 0x800C87B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_800C87C0;
    // 0x800C87B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C87B8: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
L_800C87BC:
    // 0x800C87BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800C87C0:
    // 0x800C87C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C87C4: jal         0x800C86E8
    // 0x800C87C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_1;
    // 0x800C87C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C87CC: bne         $v0, $zero, L_800C8798
    if (ctx->r2 != 0) {
        // 0x800C87D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8798;
    }
    // 0x800C87D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C87D4:
    // 0x800C87D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C87D8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C87DC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C87E0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C87E4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C87E8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C87EC: jr          $ra
    // 0x800C87F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C87F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcAddDObjSiblingRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B5B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B5BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B5C0: jal         0x80009380
    // 0x8000B5C4: nop

    gcAddSiblingForDObj(rdram, ctx);
        goto after_0;
    // 0x8000B5C4: nop

    after_0:
    // 0x8000B5C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B5CC: jal         0x8000B434
    // 0x8000B5D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyR(rdram, ctx);
        goto after_1;
    // 0x8000B5D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B5D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B5DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B5E0: jr          $ra
    // 0x8000B5E4: nop

    return;
    // 0x8000B5E4: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoomFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132468: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8013246C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132470: sw          $t6, 0x431C($at)
    MEM_W(0X431C, ctx->r1) = ctx->r14;
    // 0x80132474: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013247C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132480: jal         0x80009968
    // 0x80132484: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132484: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132488: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013248C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132490: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132494: sw          $v0, 0x4320($at)
    MEM_W(0X4320, ctx->r1) = ctx->r2;
    // 0x80132498: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8013249C: addiu       $a1, $a1, 0x2338
    ctx->r5 = ADD32(ctx->r5, 0X2338);
    // 0x801324A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801324A4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801324A8: jal         0x80009DF4
    // 0x801324AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801324AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801324B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801324B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801324B8: jr          $ra
    // 0x801324BC: nop

    return;
    // 0x801324BC: nop

;}
RECOMP_FUNC void func_ovl56_80132DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132DC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132DC8: addiu       $v0, $v0, 0x52CC
    ctx->r2 = ADD32(ctx->r2, 0X52CC);
    // 0x80132DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132DD0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80132DD4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80132DD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132DDC: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80132DE0: beql        $at, $zero, L_80132DF4
    if (ctx->r1 == 0) {
        // 0x80132DE4: sw          $t8, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r24;
            goto L_80132DF4;
    }
    goto skip_0;
    // 0x80132DE4: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    skip_0:
    // 0x80132DE8: b           L_80132DF4
    // 0x80132DEC: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80132DF4;
    // 0x80132DEC: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80132DF0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80132DF4:
    // 0x80132DF4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80132DF8: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x80132DFC: bnel        $t9, $t0, L_80132E34
    if (ctx->r25 != ctx->r8) {
        // 0x80132E00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132E34;
    }
    goto skip_1;
    // 0x80132E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132E04: jal         0x800269C0
    // 0x80132E08: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80132E08: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80132E0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E10: jal         0x80009A84
    // 0x80132E14: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80132E14: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_1:
    // 0x80132E18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132E1C: addiu       $v0, $v0, 0x52E8
    ctx->r2 = ADD32(ctx->r2, 0X52E8);
    // 0x80132E20: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80132E24: addiu       $t2, $t1, 0x3E8
    ctx->r10 = ADD32(ctx->r9, 0X3E8);
    // 0x80132E28: jal         0x801323F8
    // 0x80132E2C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    sc1PStageClearMakeScoreSObjs(rdram, ctx);
        goto after_2;
    // 0x80132E2C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_2:
    // 0x80132E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132E34:
    // 0x80132E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132E38: jr          $ra
    // 0x80132E3C: nop

    return;
    // 0x80132E3C: nop

;}
RECOMP_FUNC void lbParticleMakeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE7A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800CE7AC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800CE7B0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800CE7B4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800CE7B8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800CE7BC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800CE7C0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800CE7C4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800CE7C8: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800CE7CC: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800CE7D0: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800CE7D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800CE7D8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800CE7DC: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800CE7E0: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800CE7E4: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CE7E8: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800CE7EC: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x800CE7F0: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800CE7F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CE7F8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CE7FC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800CE800: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800CE804: lhu         $a3, 0x62($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X62);
    // 0x800CE808: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800CE80C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CE810: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800CE814: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800CE818: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800CE81C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CE820: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800CE824: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800CE828: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800CE82C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800CE830: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800CE834: jal         0x800CE4E4
    // 0x800CE838: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    lbParticleMakeStruct(rdram, ctx);
        goto after_0;
    // 0x800CE838: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    after_0:
    // 0x800CE83C: beq         $v0, $zero, L_800CE85C
    if (ctx->r2 == 0) {
        // 0x800CE840: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CE85C;
    }
    // 0x800CE840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CE844: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800CE848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE84C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800CE850: jal         0x800CEF4C
    // 0x800CE854: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_1;
    // 0x800CE854: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_1:
    // 0x800CE858: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800CE85C:
    // 0x800CE85C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CE860: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800CE864: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CE868: jr          $ra
    // 0x800CE86C: nop

    return;
    // 0x800CE86C: nop

;}
RECOMP_FUNC void ftCommonDokanStartCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142258: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142260: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142264: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80142268: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014226C: slti        $at, $t6, -0x34
    ctx->r1 = SIGNED(ctx->r14) < -0X34 ? 1 : 0;
    // 0x80142270: beql        $at, $zero, L_801423A4
    if (ctx->r1 == 0) {
        // 0x80142274: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801423A4;
    }
    goto skip_0;
    // 0x80142274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80142278: lbu         $t7, 0x269($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X269);
    // 0x8014227C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80142280: beql        $at, $zero, L_801423A4
    if (ctx->r1 == 0) {
        // 0x80142284: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801423A4;
    }
    goto skip_1;
    // 0x80142284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80142288: lw          $v1, 0xF4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF4);
    // 0x8014228C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80142290: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x80142294: and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // 0x80142298: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8014229C: bne         $v1, $at, L_8014231C
    if (ctx->r3 != ctx->r1) {
        // 0x801422A0: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8014231C;
    }
    // 0x801422A0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801422A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801422A8: jal         0x800FC814
    // 0x801422AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x801422AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x801422B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801422B4: jal         0x800FC894
    // 0x801422B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x801422B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x801422BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x801422C0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801422C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801422C8: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x801422CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801422D0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801422D4: lwc1        $f0, 0x1C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x801422D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801422DC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801422E0: nop

    // 0x801422E4: bc1fl       L_801422FC
    if (!c1cs) {
        // 0x801422E8: sub.s       $f2, $f6, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
            goto L_801422FC;
    }
    goto skip_2;
    // 0x801422E8: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
    skip_2:
    // 0x801422EC: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801422F0: b           L_801422FC
    // 0x801422F4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_801422FC;
    // 0x801422F4: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x801422F8: sub.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f0.fl;
L_801422FC:
    // 0x801422FC: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80142300: nop

    // 0x80142304: bc1fl       L_801423A4
    if (!c1cs) {
        // 0x80142308: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801423A4;
    }
    goto skip_3;
    // 0x80142308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8014230C: jal         0x80142164
    // 0x80142310: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    ftCommonDokanStartSetStatus(rdram, ctx);
        goto after_2;
    // 0x80142310: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
    // 0x80142314: b           L_801423A4
    // 0x80142318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801423A4;
    // 0x80142318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014231C:
    // 0x8014231C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80142320: bne         $v1, $at, L_801423A0
    if (ctx->r3 != ctx->r1) {
        // 0x80142324: addiu       $a0, $zero, 0xB
        ctx->r4 = ADD32(0, 0XB);
            goto L_801423A0;
    }
    // 0x80142324: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80142328: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8014232C: jal         0x800FC814
    // 0x80142330: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_3;
    // 0x80142330: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_3:
    // 0x80142334: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80142338: jal         0x800FC894
    // 0x8014233C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_4;
    // 0x8014233C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80142340: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80142344: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80142348: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8014234C: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x80142350: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80142354: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80142358: lwc1        $f0, 0x1C($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8014235C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80142360: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80142364: nop

    // 0x80142368: bc1fl       L_80142380
    if (!c1cs) {
        // 0x8014236C: sub.s       $f2, $f16, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
            goto L_80142380;
    }
    goto skip_4;
    // 0x8014236C: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    skip_4:
    // 0x80142370: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80142374: b           L_80142380
    // 0x80142378: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80142380;
    // 0x80142378: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8014237C: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
L_80142380:
    // 0x80142380: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x80142384: nop

    // 0x80142388: bc1fl       L_801423A4
    if (!c1cs) {
        // 0x8014238C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801423A4;
    }
    goto skip_5;
    // 0x8014238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80142390: jal         0x80142164
    // 0x80142394: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    ftCommonDokanStartSetStatus(rdram, ctx);
        goto after_5;
    // 0x80142394: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
    // 0x80142398: b           L_801423A4
    // 0x8014239C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801423A4;
    // 0x8014239C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801423A0:
    // 0x801423A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801423A4:
    // 0x801423A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801423A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801423AC: jr          $ra
    // 0x801423B0: nop

    return;
    // 0x801423B0: nop

;}
RECOMP_FUNC void itIwarkWeaponRockProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DEB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DEC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017DEC4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017DEC8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8017DECC: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8017DED0: jal         0x801680EC
    // 0x8017DED4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8017DED4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017DED8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DEDC: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8017DEE0: jal         0x8001863C
    // 0x8017DEE4: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8017DEE4: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x8017DEE8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8017DEEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DEF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017DEF4: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8017DEF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017DEFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DF00: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8017DF04: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8017DF08: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x8017DF0C: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x8017DF10: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8017DF14: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8017DF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DF1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DF20: jr          $ra
    // 0x8017DF24: nop

    return;
    // 0x8017DF24: nop

;}
RECOMP_FUNC void ftKirbySpecialAirHiFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161104: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8016110C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80161110: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80161114: jal         0x800DE87C
    // 0x80161118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_0;
    // 0x80161118: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016111C: beql        $v0, $zero, L_80161184
    if (ctx->r2 == 0) {
        // 0x80161120: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80161184;
    }
    goto skip_0;
    // 0x80161120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80161124: lhu         $v0, 0xD2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD2);
    // 0x80161128: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8016112C: beq         $t6, $zero, L_80161170
    if (ctx->r14 == 0) {
        // 0x80161130: andi        $t9, $v0, 0x3000
        ctx->r25 = ctx->r2 & 0X3000;
            goto L_80161170;
    }
    // 0x80161130: andi        $t9, $v0, 0x3000
    ctx->r25 = ctx->r2 & 0X3000;
    // 0x80161134: jal         0x800DEE98
    // 0x80161138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x80161138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8016113C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80161140: addiu       $a1, $zero, 0x101
    ctx->r5 = ADD32(0, 0X101);
    // 0x80161144: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161148: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8016114C: jal         0x800E6F24
    // 0x80161150: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161150: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80161154: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80161158: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8016115C: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x80161160: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x80161164: sw          $t7, 0xA04($s0)
    MEM_W(0XA04, ctx->r16) = ctx->r15;
    // 0x80161168: b           L_80161180
    // 0x8016116C: sw          $t8, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r24;
        goto L_80161180;
    // 0x8016116C: sw          $t8, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r24;
L_80161170:
    // 0x80161170: beql        $t9, $zero, L_80161184
    if (ctx->r25 == 0) {
        // 0x80161174: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80161184;
    }
    goto skip_1;
    // 0x80161174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80161178: jal         0x80144C24
    // 0x8016117C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_3;
    // 0x8016117C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80161180:
    // 0x80161180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80161184:
    // 0x80161184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80161188: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016118C: jr          $ra
    // 0x80161190: nop

    return;
    // 0x80161190: nop

;}
RECOMP_FUNC void itManagerInitItems(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DEA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016DEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DEA8: addiu       $a0, $zero, 0x39C0
    ctx->r4 = ADD32(0, 0X39C0);
    // 0x8016DEAC: jal         0x80004980
    // 0x8016DEB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x8016DEB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8016DEB4: addiu       $t1, $v0, 0xAD4
    ctx->r9 = ADD32(ctx->r2, 0XAD4);
    // 0x8016DEB8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DEBC: sw          $v0, -0x2F6C($at)
    MEM_W(-0X2F6C, ctx->r1) = ctx->r2;
    // 0x8016DEC0: addiu       $a1, $t1, 0x39C
    ctx->r5 = ADD32(ctx->r9, 0X39C);
    // 0x8016DEC4: addiu       $a2, $t1, 0x738
    ctx->r6 = ADD32(ctx->r9, 0X738);
    // 0x8016DEC8: addiu       $a3, $t1, 0xAD4
    ctx->r7 = ADD32(ctx->r9, 0XAD4);
    // 0x8016DECC: addiu       $t0, $t1, 0xE70
    ctx->r8 = ADD32(ctx->r9, 0XE70);
    // 0x8016DED0: addiu       $t6, $v0, 0x39C
    ctx->r14 = ADD32(ctx->r2, 0X39C);
    // 0x8016DED4: addiu       $t7, $v0, 0x738
    ctx->r15 = ADD32(ctx->r2, 0X738);
    // 0x8016DED8: addiu       $t8, $v0, 0xAD4
    ctx->r24 = ADD32(ctx->r2, 0XAD4);
    // 0x8016DEDC: sw          $t8, 0x738($v0)
    MEM_W(0X738, ctx->r2) = ctx->r24;
    // 0x8016DEE0: sw          $t7, 0x39C($v0)
    MEM_W(0X39C, ctx->r2) = ctx->r15;
    // 0x8016DEE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8016DEE8: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8016DEEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8016DEF0: addiu       $v1, $v0, 0xAD4
    ctx->r3 = ADD32(ctx->r2, 0XAD4);
L_8016DEF4:
    // 0x8016DEF4: sw          $a2, 0x39C($v1)
    MEM_W(0X39C, ctx->r3) = ctx->r6;
    // 0x8016DEF8: sw          $a3, 0x738($v1)
    MEM_W(0X738, ctx->r3) = ctx->r7;
    // 0x8016DEFC: sw          $t0, 0xAD4($v1)
    MEM_W(0XAD4, ctx->r3) = ctx->r8;
    // 0x8016DF00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8016DF04: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8016DF08: addiu       $a1, $a1, 0xE70
    ctx->r5 = ADD32(ctx->r5, 0XE70);
    // 0x8016DF0C: addiu       $t0, $t0, 0xE70
    ctx->r8 = ADD32(ctx->r8, 0XE70);
    // 0x8016DF10: addiu       $a3, $a3, 0xE70
    ctx->r7 = ADD32(ctx->r7, 0XE70);
    // 0x8016DF14: addiu       $a2, $a2, 0xE70
    ctx->r6 = ADD32(ctx->r6, 0XE70);
    // 0x8016DF18: bne         $a0, $t1, L_8016DEF4
    if (ctx->r4 != ctx->r9) {
        // 0x8016DF1C: addiu       $v1, $v1, 0xE70
        ctx->r3 = ADD32(ctx->r3, 0XE70);
            goto L_8016DEF4;
    }
    // 0x8016DF1C: addiu       $v1, $v1, 0xE70
    ctx->r3 = ADD32(ctx->r3, 0XE70);
    // 0x8016DF20: beq         $v0, $zero, L_8016DF2C
    if (ctx->r2 == 0) {
        // 0x8016DF24: lui         $a0, 0x0
        ctx->r4 = S32(0X0 << 16);
            goto L_8016DF2C;
    }
    // 0x8016DF24: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8016DF28: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8016DF2C:
    // 0x8016DF2C: addiu       $a0, $a0, 0xFB
    ctx->r4 = ADD32(ctx->r4, 0XFB);
    // 0x8016DF30: jal         0x800CDBD0
    // 0x8016DF34: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_1;
    // 0x8016DF34: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8016DF38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016DF3C: jal         0x80004980
    // 0x8016DF40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8016DF40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8016DF44: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016DF48: jal         0x800CDC88
    // 0x8016DF4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_3;
    // 0x8016DF4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8016DF50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DF54: lui         $a0, 0xB2
    ctx->r4 = S32(0XB2 << 16);
    // 0x8016DF58: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x8016DF5C: lui         $a2, 0xB2
    ctx->r6 = S32(0XB2 << 16);
    // 0x8016DF60: lui         $a3, 0xB2
    ctx->r7 = S32(0XB2 << 16);
    // 0x8016DF64: sw          $v0, -0x2FC0($at)
    MEM_W(-0X2FC0, ctx->r1) = ctx->r2;
    // 0x8016DF68: addiu       $a3, $a3, -0x19C0
    ctx->r7 = ADD32(ctx->r7, -0X19C0);
    // 0x8016DF6C: addiu       $a2, $a2, -0x4220
    ctx->r6 = ADD32(ctx->r6, -0X4220);
    // 0x8016DF70: addiu       $a1, $a1, -0x4220
    ctx->r5 = ADD32(ctx->r5, -0X4220);
    // 0x8016DF74: jal         0x801159F8
    // 0x8016DF78: addiu       $a0, $a0, -0x4360
    ctx->r4 = ADD32(ctx->r4, -0X4360);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_4;
    // 0x8016DF78: addiu       $a0, $a0, -0x4360
    ctx->r4 = ADD32(ctx->r4, -0X4360);
    after_4:
    // 0x8016DF7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DF80: jal         0x8016EF40
    // 0x8016DF84: sw          $v0, -0x2FBC($at)
    MEM_W(-0X2FBC, ctx->r1) = ctx->r2;
    itManagerSetupContainerDrops(rdram, ctx);
        goto after_5;
    // 0x8016DF84: sw          $v0, -0x2FBC($at)
    MEM_W(-0X2FBC, ctx->r1) = ctx->r2;
    after_5:
    // 0x8016DF88: jal         0x8016F218
    // 0x8016DF8C: nop

    itManagerInitMonsterVars(rdram, ctx);
        goto after_6;
    // 0x8016DF8C: nop

    after_6:
    // 0x8016DF90: jal         0x80111F80
    // 0x8016DF94: nop

    ifCommonItemArrowSetAttr(rdram, ctx);
        goto after_7;
    // 0x8016DF94: nop

    after_7:
    // 0x8016DF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DF9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016DFA0: sw          $zero, -0x2F70($at)
    MEM_W(-0X2F70, ctx->r1) = 0;
    // 0x8016DFA4: jr          $ra
    // 0x8016DFA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8016DFA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnNoControllerFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D65B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D65BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D65C0: jal         0x800D6660
    // 0x800D65C4: nop

    mnNoControllerSetupFiles(rdram, ctx);
        goto after_0;
    // 0x800D65C4: nop

    after_0:
    // 0x800D65C8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800D65CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D65D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D65D4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800D65D8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800D65DC: jal         0x8000B9FC
    // 0x800D65E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x800D65E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800D65E4: jal         0x800D6490
    // 0x800D65E8: nop

    mnNoControllerMakeCamera(rdram, ctx);
        goto after_2;
    // 0x800D65E8: nop

    after_2:
    // 0x800D65EC: jal         0x800D6538
    // 0x800D65F0: nop

    mnNoControllerMakeImage(rdram, ctx);
        goto after_3;
    // 0x800D65F0: nop

    after_3:
    // 0x800D65F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D65F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D65FC: jr          $ra
    // 0x800D6600: nop

    return;
    // 0x800D6600: nop

;}
RECOMP_FUNC void mpCommonProcFighterProject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE960: jal         0x800DE724
    // 0x800DE964: nop

    mpCommonCheckFighterProject(rdram, ctx);
        goto after_0;
    // 0x800DE964: nop

    after_0:
    // 0x800DE968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE970: jr          $ra
    // 0x800DE974: nop

    return;
    // 0x800DE974: nop

;}
RECOMP_FUNC void itHitokageDamagedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183DA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80183DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183DA8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80183DAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80183DB0: addiu       $a1, $a1, -0x4B2C
    ctx->r5 = ADD32(ctx->r5, -0X4B2C);
    // 0x80183DB4: jal         0x80172EC8
    // 0x80183DB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80183DB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80183DBC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80183DC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80183DC4: addiu       $t6, $t6, 0x3F88
    ctx->r14 = ADD32(ctx->r14, 0X3F88);
    // 0x80183DC8: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x80183DCC: sw          $t6, 0x398($t8)
    MEM_W(0X398, ctx->r24) = ctx->r14;
    // 0x80183DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80183DD8: jr          $ra
    // 0x80183DDC: nop

    return;
    // 0x80183DDC: nop

;}
RECOMP_FUNC void scExplainSetPlayerInterfacePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D440: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018D444: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D448: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8018D44C: addiu       $t6, $t6, -0x1920
    ctx->r14 = ADD32(ctx->r14, -0X1920);
    // 0x8018D450: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x8018D454: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8018D458: jr          $ra
    // 0x8018D45C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    return;
    // 0x8018D45C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mvOpeningClashMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131E60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80131E64: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80131E68: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80131E6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80131E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E78: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80131E7C: jal         0x80009968
    // 0x80131E80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E84: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E88: addiu       $a1, $a1, 0x3E68
    ctx->r5 = ADD32(ctx->r5, 0X3E68);
    // 0x80131E8C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131E90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131E94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131E98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80131E9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EA0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131EA4: jal         0x80009DF4
    // 0x80131EA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131EA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131EAC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80131EB0: addiu       $s1, $s1, 0x2D70
    ctx->r17 = ADD32(ctx->r17, 0X2D70);
    // 0x80131EB4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80131EB8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131EBC: addiu       $t8, $t8, 0x32A8
    ctx->r24 = ADD32(ctx->r24, 0X32A8);
    // 0x80131EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EC4: jal         0x800092D0
    // 0x80131EC8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131EC8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131ECC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131ED0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131ED4: jal         0x80008CC0
    // 0x80131ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80131ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80131EDC: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80131EE0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131EE4: addiu       $t0, $t0, 0x3050
    ctx->r8 = ADD32(ctx->r8, 0X3050);
    // 0x80131EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EEC: jal         0x8000F8F4
    // 0x80131EF0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_4;
    // 0x80131EF0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80131EF4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80131EF8: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80131EFC: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80131F00: addiu       $t2, $t2, 0x3458
    ctx->r10 = ADD32(ctx->r10, 0X3458);
    // 0x80131F04: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80131F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F0C: jal         0x8000BE28
    // 0x80131F10: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_5;
    // 0x80131F10: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_5:
    // 0x80131F14: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80131F18: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131F1C: addiu       $t7, $t7, 0x36D0
    ctx->r15 = ADD32(ctx->r15, 0X36D0);
    // 0x80131F20: swc1        $f20, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f20.u32l;
    // 0x80131F24: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80131F28: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80131F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F30: swc1        $f20, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f20.u32l;
    // 0x80131F34: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80131F38: swc1        $f20, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f20.u32l;
    // 0x80131F3C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x80131F40: jal         0x8000BD8C
    // 0x80131F44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddAnimJointAll(rdram, ctx);
        goto after_6;
    // 0x80131F44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x80131F48: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F4C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131F50: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80131F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F5C: jal         0x80008188
    // 0x80131F60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131F60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131F64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F6C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80131F70: jal         0x80009968
    // 0x80131F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x80131F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80131F78: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131F7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131F80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F88: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80131F8C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131F90: jal         0x80009DF4
    // 0x80131F94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x80131F94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x80131F98: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80131F9C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131FA0: addiu       $t0, $t0, 0x3938
    ctx->r8 = ADD32(ctx->r8, 0X3938);
    // 0x80131FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FA8: jal         0x800092D0
    // 0x80131FAC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjForGObj(rdram, ctx);
        goto after_10;
    // 0x80131FAC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_10:
    // 0x80131FB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FB4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131FB8: jal         0x80008CC0
    // 0x80131FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_11;
    // 0x80131FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80131FC0: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80131FC4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80131FC8: addiu       $t2, $t2, 0x36E0
    ctx->r10 = ADD32(ctx->r10, 0X36E0);
    // 0x80131FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FD0: jal         0x8000F8F4
    // 0x80131FD4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMObjAll(rdram, ctx);
        goto after_12;
    // 0x80131FD4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_12:
    // 0x80131FD8: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80131FDC: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80131FE0: addiu       $t4, $t4, 0x3AE8
    ctx->r12 = ADD32(ctx->r12, 0X3AE8);
    // 0x80131FE4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80131FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FEC: jal         0x8000BE28
    // 0x80131FF0: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_13;
    // 0x80131FF0: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_13:
    // 0x80131FF4: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80131FF8: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131FFC: addiu       $t9, $t9, 0x3D60
    ctx->r25 = ADD32(ctx->r25, 0X3D60);
    // 0x80132000: swc1        $f20, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f20.u32l;
    // 0x80132004: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80132008: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8013200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132010: swc1        $f20, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f20.u32l;
    // 0x80132014: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80132018: swc1        $f20, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f20.u32l;
    // 0x8013201C: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80132020: jal         0x8000BD8C
    // 0x80132024: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimJointAll(rdram, ctx);
        goto after_14;
    // 0x80132024: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_14:
    // 0x80132028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013202C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80132030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132034: jal         0x80008188
    // 0x80132038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_15;
    // 0x80132038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_15:
    // 0x8013203C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132044: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132048: jal         0x80009968
    // 0x8013204C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_16;
    // 0x8013204C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_16:
    // 0x80132050: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132058: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8013205C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132060: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80132064: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132068: jal         0x80009DF4
    // 0x8013206C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_17;
    // 0x8013206C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_17:
    // 0x80132070: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80132074: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80132078: addiu       $t2, $t2, 0x3FC8
    ctx->r10 = ADD32(ctx->r10, 0X3FC8);
    // 0x8013207C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132080: jal         0x800092D0
    // 0x80132084: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjForGObj(rdram, ctx);
        goto after_18;
    // 0x80132084: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_18:
    // 0x80132088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013208C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80132090: jal         0x80008CC0
    // 0x80132094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_19;
    // 0x80132094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80132098: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8013209C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801320A0: addiu       $t4, $t4, 0x3D70
    ctx->r12 = ADD32(ctx->r12, 0X3D70);
    // 0x801320A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320A8: jal         0x8000F8F4
    // 0x801320AC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMObjAll(rdram, ctx);
        goto after_20;
    // 0x801320AC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_20:
    // 0x801320B0: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x801320B4: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801320B8: addiu       $t6, $t6, 0x4180
    ctx->r14 = ADD32(ctx->r14, 0X4180);
    // 0x801320BC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801320C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320C4: jal         0x8000BE28
    // 0x801320C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_21;
    // 0x801320C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_21:
    // 0x801320CC: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x801320D0: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801320D4: addiu       $t1, $t1, 0x4400
    ctx->r9 = ADD32(ctx->r9, 0X4400);
    // 0x801320D8: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x801320DC: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x801320E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801320E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320E8: swc1        $f20, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f20.u32l;
    // 0x801320EC: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x801320F0: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x801320F4: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x801320F8: jal         0x8000BD8C
    // 0x801320FC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    gcAddAnimJointAll(rdram, ctx);
        goto after_22;
    // 0x801320FC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_22:
    // 0x80132100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132104: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80132108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013210C: jal         0x80008188
    // 0x80132110: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_23;
    // 0x80132110: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_23:
    // 0x80132114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013211C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132120: jal         0x80009968
    // 0x80132124: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_24;
    // 0x80132124: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_24:
    // 0x80132128: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8013212C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132130: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132138: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8013213C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132140: jal         0x80009DF4
    // 0x80132144: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_25;
    // 0x80132144: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_25:
    // 0x80132148: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8013214C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132150: addiu       $t4, $t4, 0x4668
    ctx->r12 = ADD32(ctx->r12, 0X4668);
    // 0x80132154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132158: jal         0x800092D0
    // 0x8013215C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddDObjForGObj(rdram, ctx);
        goto after_26;
    // 0x8013215C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_26:
    // 0x80132160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132164: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80132168: jal         0x80008CC0
    // 0x8013216C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_27;
    // 0x8013216C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80132170: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80132174: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132178: addiu       $t6, $t6, 0x4410
    ctx->r14 = ADD32(ctx->r14, 0X4410);
    // 0x8013217C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132180: jal         0x8000F8F4
    // 0x80132184: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddMObjAll(rdram, ctx);
        goto after_28;
    // 0x80132184: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_28:
    // 0x80132188: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8013218C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132190: addiu       $t8, $t8, 0x4820
    ctx->r24 = ADD32(ctx->r24, 0X4820);
    // 0x80132194: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80132198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013219C: jal         0x8000BE28
    // 0x801321A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_29;
    // 0x801321A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_29:
    // 0x801321A4: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x801321A8: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801321AC: addiu       $t3, $t3, 0x4AA0
    ctx->r11 = ADD32(ctx->r11, 0X4AA0);
    // 0x801321B0: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x801321B4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x801321B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801321BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321C0: swc1        $f20, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f20.u32l;
    // 0x801321C4: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801321C8: swc1        $f20, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f20.u32l;
    // 0x801321CC: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x801321D0: jal         0x8000BD8C
    // 0x801321D4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_30;
    // 0x801321D4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_30:
    // 0x801321D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801321DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801321E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801321E4: jal         0x80008188
    // 0x801321E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_31;
    // 0x801321E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_31:
    // 0x801321EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801321F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801321F4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801321F8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801321FC: jr          $ra
    // 0x80132200: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80132200: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayers1PGameCheckManFighterSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136BAC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136BB0: lw          $t6, -0x70EC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X70EC);
    // 0x80136BB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80136BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136BBC: beq         $t6, $zero, L_80136BCC
    if (ctx->r14 == 0) {
        // 0x80136BC0: nop
    
            goto L_80136BCC;
    }
    // 0x80136BC0: nop

    // 0x80136BC4: jr          $ra
    // 0x80136BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80136BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136BCC:
    // 0x80136BCC: jr          $ra
    // 0x80136BD0: nop

    return;
    // 0x80136BD0: nop

;}
RECOMP_FUNC void sySchedulerSpTaskDone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020D0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800020D4: lw          $v0, 0x4ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ED0);
    // 0x800020D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800020DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020E0: beq         $v0, $zero, L_8000213C
    if (ctx->r2 == 0) {
        // 0x800020E4: nop
    
            goto L_8000213C;
    }
    // 0x800020E4: nop

    // 0x800020E8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800020EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800020F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800020F4: bne         $t6, $at, L_8000213C
    if (ctx->r14 != ctx->r1) {
        // 0x800020F8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000213C;
    }
    // 0x800020F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800020FC: jal         0x80030000
    // 0x80002100: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80002100: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_0:
    // 0x80002104: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002108: jal         0x80001E64
    // 0x8000210C: sw          $zero, 0x4ED0($at)
    MEM_W(0X4ED0, ctx->r1) = 0;
    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_1;
    // 0x8000210C: sw          $zero, 0x4ED0($at)
    MEM_W(0X4ED0, ctx->r1) = 0;
    after_1:
    // 0x80002110: jal         0x80033490
    // 0x80002114: nop

    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x80002114: nop

    after_2:
    // 0x80002118: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000211C: lw          $t7, 0x4FB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4FB0);
    // 0x80002120: addiu       $at, $zero, 0xB9B
    ctx->r1 = ADD32(0, 0XB9B);
    // 0x80002124: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x80002128: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x8000212C: mflo        $t9
    ctx->r25 = lo;
    // 0x80002130: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002134: b           L_80002330
    // 0x80002138: sw          $t9, 0x4FB8($at)
    MEM_W(0X4FB8, ctx->r1) = ctx->r25;
        goto L_80002330;
    // 0x80002138: sw          $t9, 0x4FB8($at)
    MEM_W(0X4FB8, ctx->r1) = ctx->r25;
L_8000213C:
    // 0x8000213C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002140: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x80002144: beq         $v0, $zero, L_800021DC
    if (ctx->r2 == 0) {
        // 0x80002148: nop
    
            goto L_800021DC;
    }
    // 0x80002148: nop

    // 0x8000214C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80002150: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80002154: bne         $t0, $at, L_800021DC
    if (ctx->r8 != ctx->r1) {
        // 0x80002158: nop
    
            goto L_800021DC;
    }
    // 0x80002158: nop

    // 0x8000215C: jal         0x80034CD0
    // 0x80002160: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    osSpTaskYielded_recomp(rdram, ctx);
        goto after_3;
    // 0x80002160: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    after_3:
    // 0x80002164: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002168: bne         $v0, $at, L_80002198
    if (ctx->r2 != ctx->r1) {
        // 0x8000216C: lui         $t4, 0x8004
        ctx->r12 = S32(0X8004 << 16);
            goto L_80002198;
    }
    // 0x8000216C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80002170: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002174: addiu       $v0, $v0, 0x4ECC
    ctx->r2 = ADD32(ctx->r2, 0X4ECC);
    // 0x80002178: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000217C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80002180: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80002184: jal         0x80000D44
    // 0x80002188: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    sySchedulerAddPausedQueue(rdram, ctx);
        goto after_4;
    // 0x80002188: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_4:
    // 0x8000218C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002190: b           L_800021A4
    // 0x80002194: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
        goto L_800021A4;
    // 0x80002194: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
L_80002198:
    // 0x80002198: lw          $t4, 0x4ECC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4ECC);
    // 0x8000219C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800021A0: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_800021A4:
    // 0x800021A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800021A8: lw          $a0, 0x4ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4ED0);
    // 0x800021AC: jal         0x800306CC
    // 0x800021B0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_5;
    // 0x800021B0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800021B4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800021B8: lw          $a0, 0x4ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4ED0);
    // 0x800021BC: jal         0x8003085C
    // 0x800021C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_6;
    // 0x800021C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x800021C4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800021C8: lw          $t6, 0x4ED0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4ED0);
    // 0x800021CC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800021D0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800021D4: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x800021D8: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
L_800021DC:
    // 0x800021DC: beq         $v0, $zero, L_800022E8
    if (ctx->r2 == 0) {
        // 0x800021E0: nop
    
            goto L_800022E8;
    }
    // 0x800021E0: nop

    // 0x800021E4: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x800021E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800021EC: bne         $a2, $t7, L_800022E8
    if (ctx->r6 != ctx->r15) {
        // 0x800021F0: nop
    
            goto L_800022E8;
    }
    // 0x800021F0: nop

    // 0x800021F4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800021F8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800021FC: beq         $t8, $at, L_800022E8
    if (ctx->r24 == ctx->r1) {
        // 0x80002200: nop
    
            goto L_800022E8;
    }
    // 0x80002200: nop

    // 0x80002204: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80002208: bne         $a2, $t9, L_800022D4
    if (ctx->r6 != ctx->r25) {
        // 0x8000220C: nop
    
            goto L_800022D4;
    }
    // 0x8000220C: nop

    // 0x80002210: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x80002214: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002218: addiu       $a0, $a0, 0x4FC0
    ctx->r4 = ADD32(ctx->r4, 0X4FC0);
    // 0x8000221C: bne         $a2, $t0, L_800022D4
    if (ctx->r6 != ctx->r8) {
        // 0x80002220: nop
    
            goto L_800022D4;
    }
    // 0x80002220: nop

    // 0x80002224: jal         0x80034530
    // 0x80002228: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_7;
    // 0x80002228: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x8000222C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80002230: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80002234: addiu       $a3, $a3, 0x4ECC
    ctx->r7 = ADD32(ctx->r7, 0X4ECC);
    // 0x80002238: addiu       $v1, $v1, 0x4FC0
    ctx->r3 = ADD32(ctx->r3, 0X4FC0);
    // 0x8000223C: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x80002240: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80002244: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002248: addiu       $v0, $v0, 0x4FC8
    ctx->r2 = ADD32(ctx->r2, 0X4FC8);
    // 0x8000224C: sw          $t3, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->r11;
    // 0x80002250: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80002254: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80002258: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000225C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80002260: addu        $t2, $t5, $t7
    ctx->r10 = ADD32(ctx->r13, ctx->r15);
    // 0x80002264: addiu       $t1, $t2, 0xF
    ctx->r9 = ADD32(ctx->r10, 0XF);
    // 0x80002268: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8000226C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80002270: srl         $t4, $t1, 4
    ctx->r12 = S32(U32(ctx->r9) >> 4);
    // 0x80002274: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80002278: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8000227C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80002280: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x80002284: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80002288: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000228C: bne         $at, $zero, L_800022BC
    if (ctx->r1 != 0) {
        // 0x80002290: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_800022BC;
    }
    // 0x80002290: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80002294: sltu        $at, $t8, $t0
    ctx->r1 = ctx->r24 < ctx->r8 ? 1 : 0;
    // 0x80002298: bne         $at, $zero, L_800022AC
    if (ctx->r1 != 0) {
        // 0x8000229C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_800022AC;
    }
    // 0x8000229C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800022A0: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x800022A4: beql        $at, $zero, L_800022C0
    if (ctx->r1 == 0) {
        // 0x800022A8: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_800022C0;
    }
    goto skip_0;
    // 0x800022A8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_0:
L_800022AC:
    // 0x800022AC: jal         0x80023624
    // 0x800022B0: addiu       $a0, $a0, -0x2990
    ctx->r4 = ADD32(ctx->r4, -0X2990);
    syDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x800022B0: addiu       $a0, $a0, -0x2990
    ctx->r4 = ADD32(ctx->r4, -0X2990);
    after_8:
L_800022B4:
    // 0x800022B4: b           L_800022B4
    pause_self(rdram);
    // 0x800022B8: nop

L_800022BC:
    // 0x800022BC: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_800022C0:
    // 0x800022C0: sw          $a2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r6;
    // 0x800022C4: jal         0x80000E24
    // 0x800022C8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_80000E24(rdram, ctx);
        goto after_9;
    // 0x800022C8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_9:
    // 0x800022CC: jal         0x80001FF4
    // 0x800022D0: nop

    func_80001FF4(rdram, ctx);
        goto after_10;
    // 0x800022D0: nop

    after_10:
L_800022D4:
    // 0x800022D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800022D8: jal         0x80001E64
    // 0x800022DC: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_11;
    // 0x800022DC: sw          $zero, 0x4ECC($at)
    MEM_W(0X4ECC, ctx->r1) = 0;
    after_11:
    // 0x800022E0: b           L_80002334
    // 0x800022E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80002334;
    // 0x800022E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800022E8:
    // 0x800022E8: beq         $v0, $zero, L_80002330
    if (ctx->r2 == 0) {
        // 0x800022EC: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80002330;
    }
    // 0x800022EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800022F0: lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X18);
    // 0x800022F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800022F8: bnel        $t5, $at, L_80002334
    if (ctx->r13 != ctx->r1) {
        // 0x800022FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80002334;
    }
    goto skip_1;
    // 0x800022FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80002300: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80002304: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80002308: bnel        $a2, $t2, L_80002334
    if (ctx->r6 != ctx->r10) {
        // 0x8000230C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80002334;
    }
    goto skip_2;
    // 0x8000230C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80002310: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x80002314: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002318: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
    // 0x8000231C: lw          $v1, 0x7C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7C);
    // 0x80002320: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x80002324: bne         $t4, $zero, L_80002330
    if (ctx->r12 != 0) {
        // 0x80002328: ori         $t6, $v1, 0x1
        ctx->r14 = ctx->r3 | 0X1;
            goto L_80002330;
    }
    // 0x80002328: ori         $t6, $v1, 0x1
    ctx->r14 = ctx->r3 | 0X1;
    // 0x8000232C: sw          $t6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r14;
L_80002330:
    // 0x80002330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002334:
    // 0x80002334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80002338: jr          $ra
    // 0x8000233C: nop

    return;
    // 0x8000233C: nop

;}
RECOMP_FUNC void mnMapsMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132288: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013228C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80132290: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80132294: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132298: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8013229C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801322A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801322A4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801322A8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801322AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801322B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322B8: jal         0x80009968
    // 0x801322BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801322BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x801322C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801322C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801322C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801322CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801322D0: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x801322D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801322D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801322DC: jal         0x80009DF4
    // 0x801322E0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801322E0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x801322E4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801322E8: addiu       $s4, $s4, 0x4E10
    ctx->r20 = ADD32(ctx->r20, 0X4E10);
    // 0x801322EC: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
    // 0x801322F0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801322F4: addiu       $t8, $t8, 0x26A0
    ctx->r24 = ADD32(ctx->r24, 0X26A0);
    // 0x801322F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801322FC: jal         0x800CCFDC
    // 0x80132300: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132300: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132304: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132308: lui         $at, 0x432C
    ctx->r1 = S32(0X432C << 16);
    // 0x8013230C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132310: lui         $at, 0x42F4
    ctx->r1 = S32(0X42F4 << 16);
    // 0x80132314: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132318: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013231C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132320: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132324: addiu       $t3, $zero, 0xAF
    ctx->r11 = ADD32(0, 0XAF);
    // 0x80132328: addiu       $t4, $zero, 0xB1
    ctx->r12 = ADD32(0, 0XB1);
    // 0x8013232C: addiu       $t5, $zero, 0xCC
    ctx->r13 = ADD32(0, 0XCC);
    // 0x80132330: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132334: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132338: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8013233C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132340: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132344: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132348: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x8013234C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132350: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132354: lw          $t6, 0x8($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X8);
    // 0x80132358: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013235C: addiu       $t7, $t7, 0x3FA8
    ctx->r15 = ADD32(ctx->r15, 0X3FA8);
    // 0x80132360: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80132364: jal         0x800CCFDC
    // 0x80132368: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132368: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x8013236C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132370: lui         $at, 0x433F
    ctx->r1 = S32(0X433F << 16);
    // 0x80132374: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132378: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x8013237C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132380: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132384: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132388: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8013238C: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x80132390: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132394: addiu       $s1, $s1, 0x3D68
    ctx->r17 = ADD32(ctx->r17, 0X3D68);
    // 0x80132398: addiu       $s0, $zero, 0xBA
    ctx->r16 = ADD32(0, 0XBA);
    // 0x8013239C: addiu       $s2, $zero, 0x106
    ctx->r18 = ADD32(0, 0X106);
    // 0x801323A0: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801323A4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
L_801323A8:
    // 0x801323A8: lw          $t2, 0x8($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X8);
    // 0x801323AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801323B0: jal         0x800CCFDC
    // 0x801323B4: addu        $a1, $t2, $s1
    ctx->r5 = ADD32(ctx->r10, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801323B4: addu        $a1, $t2, $s1
    ctx->r5 = ADD32(ctx->r10, ctx->r17);
    after_4:
    // 0x801323B8: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x801323BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801323C0: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801323C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801323C8: bne         $s0, $s2, L_801323A8
    if (ctx->r16 != ctx->r18) {
        // 0x801323CC: swc1        $f16, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
            goto L_801323A8;
    }
    // 0x801323CC: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801323D0: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x801323D4: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801323D8: addiu       $t4, $t4, 0x3C68
    ctx->r12 = ADD32(ctx->r12, 0X3C68);
    // 0x801323DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801323E0: jal         0x800CCFDC
    // 0x801323E4: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801323E4: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_5:
    // 0x801323E8: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x801323EC: lui         $at, 0x4383
    ctx->r1 = S32(0X4383 << 16);
    // 0x801323F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801323F4: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x801323F8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801323FC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80132400: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132404: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132408: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x8013240C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132410: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80132414: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80132418: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8013241C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80132420: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80132424: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80132428: jr          $ra
    // 0x8013242C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8013242C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void wpNessPKThunderTrailUpdatePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016ADF4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016ADF8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8016ADFC: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x8016AE00: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x8016AE04: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8016AE08: bne         $t7, $t8, L_8016AE5C
    if (ctx->r15 != ctx->r24) {
        // 0x8016AE0C: nop
    
            goto L_8016AE5C;
    }
    // 0x8016AE0C: nop

    // 0x8016AE10: lw          $v0, 0xAE0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XAE0);
    // 0x8016AE14: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8016AE18: bgezl       $v0, L_8016AE28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8016AE1C: lw          $t0, 0x74($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X74);
            goto L_8016AE28;
    }
    goto skip_0;
    // 0x8016AE1C: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x8016AE20: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8016AE24: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
L_8016AE28:
    // 0x8016AE28: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8016AE2C: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x8016AE30: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8016AE34: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8016AE38: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8016AE3C: nop

    // 0x8016AE40: sh          $t2, 0xAE4($a1)
    MEM_H(0XAE4, ctx->r5) = ctx->r10;
    // 0x8016AE44: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x8016AE48: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8016AE4C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8016AE50: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8016AE54: nop

    // 0x8016AE58: sh          $t5, 0xAFC($a1)
    MEM_H(0XAFC, ctx->r5) = ctx->r13;
L_8016AE5C:
    // 0x8016AE5C: jr          $ra
    // 0x8016AE60: nop

    return;
    // 0x8016AE60: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016020C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160214: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160218: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8016021C: addiu       $t6, $t6, 0x38
    ctx->r14 = ADD32(ctx->r14, 0X38);
    // 0x80160220: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80160224: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80160228: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8016022C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80160230: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160234: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80160238: jal         0x800E6F24
    // 0x8016023C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016023C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80160240: jal         0x800E0830
    // 0x80160244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80160244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80160248: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8016024C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80160250: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80160254: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x80160258: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x8016025C: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x80160260: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x80160264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016026C: jr          $ra
    // 0x80160270: nop

    return;
    // 0x80160270: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B6F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B6F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015B6F8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015B6FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015B700: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8015B704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8015B708: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015B70C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015B710: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015B714: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015B718: bc1fl       L_8015B738
    if (!c1cs) {
        // 0x8015B71C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015B738;
    }
    goto skip_0;
    // 0x8015B71C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8015B720: lwc1        $f8, -0x3790($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3790);
    // 0x8015B724: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015B728: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015B72C: jal         0x801438F0
    // 0x8015B730: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B730: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8015B734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015B738:
    // 0x8015B738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B73C: jr          $ra
    // 0x8015B740: nop

    return;
    // 0x8015B740: nop

;}
RECOMP_FUNC void grModelSetupGroundDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105760: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80105764: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80105768: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010576C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80105770: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80105774: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80105778: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8010577C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80105780: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80105784: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80105788: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010578C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80105790: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80105794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80105798: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x8010579C: addiu       $v1, $sp, 0x94
    ctx->r3 = ADD32(ctx->r29, 0X94);
L_801057A0:
    // 0x801057A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801057A4: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801057A8: bne         $at, $zero, L_801057A0
    if (ctx->r1 != 0) {
        // 0x801057AC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801057A0;
    }
    // 0x801057AC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801057B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801057B4: addiu       $s6, $zero, 0x12
    ctx->r22 = ADD32(0, 0X12);
    // 0x801057B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801057BC: beq         $s6, $v0, L_801058A0
    if (ctx->r22 == ctx->r2) {
        // 0x801057C0: or          $s3, $a3, $zero
        ctx->r19 = ctx->r7 | 0;
            goto L_801058A0;
    }
    // 0x801057C0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x801057C4: addiu       $s7, $sp, 0x4C
    ctx->r23 = ADD32(ctx->r29, 0X4C);
L_801057C8:
    // 0x801057C8: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // 0x801057CC: beq         $v1, $zero, L_801057F0
    if (ctx->r3 == 0) {
        // 0x801057D0: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_801057F0;
    }
    // 0x801057D0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801057D4: addu        $s1, $s7, $t6
    ctx->r17 = ADD32(ctx->r23, ctx->r14);
    // 0x801057D8: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    // 0x801057DC: jal         0x800093F4
    // 0x801057E0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x801057E0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_0:
    // 0x801057E4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x801057E8: b           L_80105804
    // 0x801057EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80105804;
    // 0x801057EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_801057F0:
    // 0x801057F0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x801057F4: jal         0x800092D0
    // 0x801057F8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801057F8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_1:
    // 0x801057FC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80105800: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80105804:
    // 0x80105804: lbu         $a1, 0x0($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X0);
    // 0x80105808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010580C: beql        $a1, $zero, L_80105820
    if (ctx->r5 == 0) {
        // 0x80105810: lbu         $a1, 0x1($s3)
        ctx->r5 = MEM_BU(ctx->r19, 0X1);
            goto L_80105820;
    }
    goto skip_0;
    // 0x80105810: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
    skip_0:
    // 0x80105814: jal         0x80008CC0
    // 0x80105818: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80105818: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    after_2:
    // 0x8010581C: lbu         $a1, 0x1($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X1);
L_80105820:
    // 0x80105820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105824: beql        $a1, $zero, L_80105838
    if (ctx->r5 == 0) {
        // 0x80105828: lw          $t8, 0x8($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X8);
            goto L_80105838;
    }
    goto skip_1;
    // 0x80105828: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    skip_1:
    // 0x8010582C: jal         0x80008CC0
    // 0x80105830: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80105830: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80105834: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
L_80105838:
    // 0x80105838: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x8010583C: addu        $t4, $s5, $t3
    ctx->r12 = ADD32(ctx->r21, ctx->r11);
    // 0x80105840: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x80105844: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80105848: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8010584C: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x80105850: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80105854: lw          $t0, 0x14($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X14);
    // 0x80105858: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x8010585C: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80105860: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x80105864: lw          $t0, 0x1C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X1C);
    // 0x80105868: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x8010586C: lw          $t2, 0x20($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X20);
    // 0x80105870: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x80105874: lw          $t1, 0x24($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X24);
    // 0x80105878: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x8010587C: lw          $t2, 0x28($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X28);
    // 0x80105880: beq         $s5, $zero, L_8010588C
    if (ctx->r21 == 0) {
        // 0x80105884: sw          $t2, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r10;
            goto L_8010588C;
    }
    // 0x80105884: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x80105888: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
L_8010588C:
    // 0x8010588C: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    // 0x80105890: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80105894: addiu       $s3, $s3, 0x3
    ctx->r19 = ADD32(ctx->r19, 0X3);
    // 0x80105898: bne         $s6, $v0, L_801057C8
    if (ctx->r22 != ctx->r2) {
        // 0x8010589C: addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
            goto L_801057C8;
    }
    // 0x8010589C: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
L_801058A0:
    // 0x801058A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801058A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801058A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801058AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801058B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801058B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801058B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801058BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801058C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x801058C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x801058C8: jr          $ra
    // 0x801058CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801058CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void itRShellSpinProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017AF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AF20: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017AF24: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017AF28: lbu         $t6, 0x355($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X355);
    // 0x8017AF2C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017AF30: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8017AF34: bne         $t8, $zero, L_8017AF44
    if (ctx->r24 != 0) {
        // 0x8017AF38: sb          $t7, 0x355($v0)
        MEM_B(0X355, ctx->r2) = ctx->r15;
            goto L_8017AF44;
    }
    // 0x8017AF38: sb          $t7, 0x355($v0)
    MEM_B(0X355, ctx->r2) = ctx->r15;
    // 0x8017AF3C: b           L_8017AFDC
    // 0x8017AF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017AFDC;
    // 0x8017AF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017AF44:
    // 0x8017AF44: lw          $t9, 0x298($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X298);
    // 0x8017AF48: lw          $t0, 0x2A4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2A4);
    // 0x8017AF4C: lwc1        $f18, 0x2C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017AF50: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8017AF54: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8017AF58: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8017AF5C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017AF60: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8017AF64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017AF68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017AF6C: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8017AF70: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017AF74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017AF78: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8017AF7C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x8017AF80: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8017AF84: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8017AF88: nop

    // 0x8017AF8C: bc1fl       L_8017AFA0
    if (!c1cs) {
        // 0x8017AF90: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8017AFA0;
    }
    goto skip_0;
    // 0x8017AF90: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x8017AF94: b           L_8017AFA0
    // 0x8017AF98: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8017AFA0;
    // 0x8017AF98: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8017AF9C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8017AFA0:
    // 0x8017AFA0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8017AFA4: nop

    // 0x8017AFA8: bc1fl       L_8017AFD8
    if (!c1cs) {
        // 0x8017AFAC: sw          $zero, 0x10C($v0)
        MEM_W(0X10C, ctx->r2) = 0;
            goto L_8017AFD8;
    }
    goto skip_1;
    // 0x8017AFAC: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    skip_1:
    // 0x8017AFB0: sw          $t2, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r10;
    // 0x8017AFB4: jal         0x8016F280
    // 0x8017AFB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_0;
    // 0x8017AFB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017AFBC: jal         0x801727BC
    // 0x8017AFC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainCopyDamageStats(rdram, ctx);
        goto after_1;
    // 0x8017AFC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017AFC4: jal         0x8017B0D4
    // 0x8017AFC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itRShellSpinSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017AFC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8017AFCC: b           L_8017AFDC
    // 0x8017AFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017AFDC;
    // 0x8017AFD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017AFD4: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
L_8017AFD8:
    // 0x8017AFD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017AFDC:
    // 0x8017AFDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017AFE4: jr          $ra
    // 0x8017AFE8: nop

    return;
    // 0x8017AFE8: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeDroppedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132928: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013292C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80132930: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80132934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132938: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x8013293C: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80132940:
    // 0x80132940: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132944: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132948: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013294C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132950: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132954: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132958: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013295C: bne         $t7, $t0, L_80132940
    if (ctx->r15 != ctx->r8) {
        // 0x80132960: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132940;
    }
    // 0x80132960: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132964: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013296C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132970: jal         0x800EC0EC
    // 0x80132974: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80132974: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013297C: lwc1        $f4, 0x4C80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C80);
    // 0x80132980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132984: lwc1        $f6, 0x4C84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C84);
    // 0x80132988: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013298C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132990: lw          $t1, 0x4CE0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4CE0);
    // 0x80132994: lwc1        $f8, 0x4C88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C88);
    // 0x80132998: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x8013299C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801329A0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801329A4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801329A8: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x801329AC: jal         0x800D7F3C
    // 0x801329B0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801329B0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801329B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329B8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x801329BC: sw          $v0, 0x4D08($at)
    MEM_W(0X4D08, ctx->r1) = ctx->r2;
    // 0x801329C0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x801329C4: ori         $a1, $a1, 0x9
    ctx->r5 = ctx->r5 | 0X9;
    // 0x801329C8: jal         0x803905CC
    // 0x801329CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x801329CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x801329D0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801329D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801329D8: jal         0x8000A0D0
    // 0x801329DC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x801329DC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x801329E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801329E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801329E8: jr          $ra
    // 0x801329EC: nop

    return;
    // 0x801329EC: nop

;}
RECOMP_FUNC void func_ovl28_801332C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332C4: jr          $ra
    // 0x801332C8: nop

    return;
    // 0x801332C8: nop

;}
RECOMP_FUNC void ftManagerSetupFilesAllKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D786C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D7870: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800D7874: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D7878: lw          $v0, 0x6E10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E10);
    // 0x800D787C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7884: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800D7888: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D788C: bnel        $t8, $zero, L_800D78A8
    if (ctx->r24 != 0) {
        // 0x800D7890: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D78A8;
    }
    goto skip_0;
    // 0x800D7890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D7894: jal         0x800D7694
    // 0x800D7898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftManagerSetupFilesMainKind(rdram, ctx);
        goto after_0;
    // 0x800D7898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D789C: jal         0x800D7710
    // 0x800D78A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftManagerSetupFilesKind(rdram, ctx);
        goto after_1;
    // 0x800D78A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D78A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D78A8:
    // 0x800D78A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D78AC: jr          $ra
    // 0x800D78B0: nop

    return;
    // 0x800D78B0: nop

;}
RECOMP_FUNC void syMatrixF2LFixedW(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019EA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80019EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019EA8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019EAC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019EB0: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x80019EB4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019EB8: nop

    // 0x80019EBC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019EC0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019EC4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019EC8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019ECC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019ED0: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x80019ED4: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80019ED8: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x80019EDC: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80019EE0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80019EE4: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80019EE8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80019EEC: sw          $t3, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r11;
    // 0x80019EF0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019EF4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019EF8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019EFC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019F00: nop

    // 0x80019F04: and         $t5, $v0, $a2
    ctx->r13 = ctx->r2 & ctx->r6;
    // 0x80019F08: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80019F0C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80019F10: sw          $t6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r14;
    // 0x80019F14: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80019F18: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80019F1C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019F20: nop

    // 0x80019F24: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019F28: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019F2C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019F30: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80019F34: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80019F38: and         $t9, $v0, $a2
    ctx->r25 = ctx->r2 & ctx->r6;
    // 0x80019F3C: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80019F40: srl         $t0, $v1, 16
    ctx->r8 = S32(U32(ctx->r3) >> 16);
    // 0x80019F44: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x80019F48: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80019F4C: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80019F50: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80019F54: sw          $t4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r12;
    // 0x80019F58: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80019F5C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019F60: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019F64: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80019F68: nop

    // 0x80019F6C: and         $t6, $v0, $a2
    ctx->r14 = ctx->r2 & ctx->r6;
    // 0x80019F70: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80019F74: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x80019F78: sw          $t7, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r15;
    // 0x80019F7C: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80019F80: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80019F84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019F88: nop

    // 0x80019F8C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019F90: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019F94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019F98: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019F9C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019FA0: and         $t0, $v0, $a2
    ctx->r8 = ctx->r2 & ctx->r6;
    // 0x80019FA4: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80019FA8: srl         $t1, $v1, 16
    ctx->r9 = S32(U32(ctx->r3) >> 16);
    // 0x80019FAC: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x80019FB0: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80019FB4: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80019FB8: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x80019FBC: sw          $t5, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r13;
    // 0x80019FC0: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80019FC4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019FC8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019FCC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019FD0: nop

    // 0x80019FD4: and         $t7, $v0, $a2
    ctx->r15 = ctx->r2 & ctx->r6;
    // 0x80019FD8: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80019FDC: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x80019FE0: sw          $t8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r24;
    // 0x80019FE4: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80019FE8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80019FEC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019FF0: nop

    // 0x80019FF4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019FF8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019FFC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001A000: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8001A004: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8001A008: and         $t1, $v0, $a2
    ctx->r9 = ctx->r2 & ctx->r6;
    // 0x8001A00C: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8001A010: srl         $t2, $v1, 16
    ctx->r10 = S32(U32(ctx->r3) >> 16);
    // 0x8001A014: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x8001A018: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8001A01C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8001A020: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x8001A024: sw          $t6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r14;
    // 0x8001A028: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001A02C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001A030: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001A034: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8001A038: nop

    // 0x8001A03C: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x8001A040: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8001A044: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x8001A048: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
    // 0x8001A04C: jr          $ra
    // 0x8001A050: sw          $t0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r8;
    return;
    // 0x8001A050: sw          $t0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r8;
;}
RECOMP_FUNC void ftCommonCliffEscapeQuick2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014590C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145910: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80145914: jal         0x80145490
    // 0x80145918: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x80145918: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014591C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80145920: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80145924: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145928: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014592C: jal         0x800E6F24
    // 0x80145930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80145930: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80145934: jal         0x8014557C
    // 0x80145938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80145938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014593C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145944: jr          $ra
    // 0x80145948: nop

    return;
    // 0x80145948: nop

;}
RECOMP_FUNC void __n_seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DFF8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8002DFFC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002E000: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002E004: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002E008: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002E00C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002E010: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002E014: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002E018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E01C: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8002E020: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x8002E024: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002E028: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8002E02C: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x8002E030: bnel        $t6, $zero, L_8002E09C
    if (ctx->r14 != 0) {
        // 0x8002E034: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8002E09C;
    }
    goto skip_0;
    // 0x8002E034: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_0:
    // 0x8002E038: lw          $s0, 0x58($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X58);
    // 0x8002E03C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8002E040: beql        $s0, $zero, L_8002E09C
    if (ctx->r16 == 0) {
        // 0x8002E044: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8002E09C;
    }
    goto skip_1;
    // 0x8002E044: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    skip_1:
L_8002E048:
    // 0x8002E048: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8002E04C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8002E050: bne         $s3, $t7, L_8002E090
    if (ctx->r19 != ctx->r15) {
        // 0x8002E054: nop
    
            goto L_8002E090;
    }
    // 0x8002E054: nop

    // 0x8002E058: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8002E05C: bne         $s5, $t8, L_8002E090
    if (ctx->r21 != ctx->r24) {
        // 0x8002E060: nop
    
            goto L_8002E090;
    }
    // 0x8002E060: nop

    // 0x8002E064: beq         $s1, $zero, L_8002E07C
    if (ctx->r17 == 0) {
        // 0x8002E068: addiu       $s2, $s4, 0x50
        ctx->r18 = ADD32(ctx->r20, 0X50);
            goto L_8002E07C;
    }
    // 0x8002E068: addiu       $s2, $s4, 0x50
    ctx->r18 = ADD32(ctx->r20, 0X50);
    // 0x8002E06C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8002E070: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8002E074: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002E078: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_8002E07C:
    // 0x8002E07C: jal         0x80028C84
    // 0x8002E080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8002E080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8002E084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E088: jal         0x80028C60
    // 0x8002E08C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x8002E08C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_8002E090:
    // 0x8002E090: bne         $s1, $zero, L_8002E048
    if (ctx->r17 != 0) {
        // 0x8002E094: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8002E048;
    }
    // 0x8002E094: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8002E098: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8002E09C:
    // 0x8002E09C: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x8002E0A0: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x8002E0A4: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x8002E0A8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8002E0AC: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x8002E0B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8002E0B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002E0B8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002E0BC: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x8002E0C0: jal         0x8002F6A0
    // 0x8002E0C4: addiu       $s2, $s4, 0x50
    ctx->r18 = ADD32(ctx->r20, 0X50);
    n_alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x8002E0C4: addiu       $s2, $s4, 0x50
    ctx->r18 = ADD32(ctx->r20, 0X50);
    after_2:
    // 0x8002E0C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8002E0CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002E0D0: jal         0x8002FF60
    // 0x8002E0D4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    n_alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x8002E0D4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x8002E0D8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8002E0DC: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8002E0E0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8002E0E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002E0E8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8002E0EC: jal         0x80028D70
    // 0x8002E0F0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x8002E0F0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x8002E0F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002E0F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E0FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E100: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002E104: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002E108: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002E10C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002E110: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002E114: jr          $ra
    // 0x8002E118: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8002E118: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftFoxSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BCB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BCBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BCC0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8015BCC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015BCC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015BCCC: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015BCD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BCD4: jal         0x800E6F24
    // 0x8015BCD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BCD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015BCDC: jal         0x800E0830
    // 0x8015BCE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015BCE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015BCE4: jal         0x8015BC68
    // 0x8015BCE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015BCE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015BCEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BCF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BCF4: jr          $ra
    // 0x8015BCF8: nop

    return;
    // 0x8015BCF8: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B48C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B490: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B494: jal         0x800DE6E4
    // 0x8015B498: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, -0X4B54);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015B498: addiu       $a1, $a1, -0x4B54
    ctx->r5 = ADD32(ctx->r5, -0X4B54);
    after_0:
    // 0x8015B49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B4A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B4A4: jr          $ra
    // 0x8015B4A8: nop

    return;
    // 0x8015B4A8: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152BF4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152BF8: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x80152BFC: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80152C00: beq         $t7, $zero, L_80152C1C
    if (ctx->r15 == 0) {
        // 0x80152C04: nop
    
            goto L_80152C1C;
    }
    // 0x80152C04: nop

    // 0x80152C08: lw          $t8, 0xB2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB2C);
    // 0x80152C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80152C10: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80152C14: bne         $at, $zero, L_80152C24
    if (ctx->r1 != 0) {
        // 0x80152C18: nop
    
            goto L_80152C24;
    }
    // 0x80152C18: nop

L_80152C1C:
    // 0x80152C1C: jr          $ra
    // 0x80152C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80152C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80152C24:
    // 0x80152C24: jr          $ra
    // 0x80152C28: nop

    return;
    // 0x80152C28: nop

;}
RECOMP_FUNC void ftCommonDamageCheckElementSetColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140BD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140BD8: beq         $a1, $at, L_80140BFC
    if (ctx->r5 == ctx->r1) {
        // 0x80140BDC: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80140BFC;
    }
    // 0x80140BDC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80140BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80140BE4: beq         $a1, $at, L_80140C10
    if (ctx->r5 == ctx->r1) {
        // 0x80140BE8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80140C10;
    }
    // 0x80140BE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80140BEC: beq         $a1, $at, L_80140C20
    if (ctx->r5 == ctx->r1) {
        // 0x80140BF0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80140C20;
    }
    // 0x80140BF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80140BF4: b           L_80140C30
    // 0x80140BF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80140C30;
    // 0x80140BF8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80140BFC:
    // 0x80140BFC: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    // 0x80140C00: jal         0x800E9814
    // 0x80140C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x80140C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80140C08: b           L_80140C3C
    // 0x80140C0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80140C3C;
    // 0x80140C0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80140C10:
    // 0x80140C10: jal         0x800E9AF4
    // 0x80140C14: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    ftParamCheckSetSkeletonColAnimID(rdram, ctx);
        goto after_1;
    // 0x80140C14: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80140C18: b           L_80140C3C
    // 0x80140C1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80140C3C;
    // 0x80140C1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80140C20:
    // 0x80140C20: jal         0x800E9814
    // 0x80140C24: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x80140C24: addiu       $a1, $a3, 0x20
    ctx->r5 = ADD32(ctx->r7, 0X20);
    after_2:
    // 0x80140C28: b           L_80140C3C
    // 0x80140C2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80140C3C;
    // 0x80140C2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80140C30:
    // 0x80140C30: jal         0x800E9814
    // 0x80140C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x80140C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80140C38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80140C3C:
    // 0x80140C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140C44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80140C48: jr          $ra
    // 0x80140C4C: nop

    return;
    // 0x80140C4C: nop

;}
RECOMP_FUNC void mvOpeningKirbySetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, -0x1D78
    ctx->r24 = ADD32(ctx->r24, -0X1D78);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1BF8
    ctx->r8 = ADD32(ctx->r8, -0X1BF8);
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
    // 0x8018D11C: addiu       $a0, $a0, -0x1F0C
    ctx->r4 = ADD32(ctx->r4, -0X1F0C);
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
    // 0x8018D13C: addiu       $a2, $a2, -0x1BC0
    ctx->r6 = ADD32(ctx->r6, -0X1BC0);
    // 0x8018D140: addiu       $a0, $a0, -0x1F0C
    ctx->r4 = ADD32(ctx->r4, -0X1F0C);
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
RECOMP_FUNC void efParticleGetBankID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801159B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801159B4: lw          $v0, 0x1A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1A18);
    // 0x801159B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801159BC: addiu       $a1, $a1, 0x1A20
    ctx->r5 = ADD32(ctx->r5, 0X1A20);
    // 0x801159C0: blez        $v0, L_801159EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801159C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801159EC;
    }
    // 0x801159C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801159C8:
    // 0x801159C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x801159CC: bnel        $a0, $t6, L_801159E0
    if (ctx->r4 != ctx->r14) {
        // 0x801159D0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801159E0;
    }
    goto skip_0;
    // 0x801159D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x801159D4: jr          $ra
    // 0x801159D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801159D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801159DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801159E0:
    // 0x801159E0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801159E4: bne         $at, $zero, L_801159C8
    if (ctx->r1 != 0) {
        // 0x801159E8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_801159C8;
    }
    // 0x801159E8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_801159EC:
    // 0x801159EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801159F0: jr          $ra
    // 0x801159F4: nop

    return;
    // 0x801159F4: nop

;}
RECOMP_FUNC void syVectorNorm3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018EE8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018EEC: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018EF0: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018EF4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80018EFC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018F00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018F04: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018F08: jal         0x80033510
    // 0x80018F0C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018F0C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80018F10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018F14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80018F18: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80018F1C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80018F20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018F24: bc1fl       L_80018F38
    if (!c1cs) {
        // 0x80018F28: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80018F38;
    }
    goto skip_0;
    // 0x80018F28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x80018F2C: b           L_80018F6C
    // 0x80018F30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80018F6C;
    // 0x80018F30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80018F34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80018F38:
    // 0x80018F38: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018F3C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018F40: div.s       $f2, $f16, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80018F44: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018F48: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80018F4C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80018F50: nop

    // 0x80018F54: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80018F58: nop

    // 0x80018F5C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80018F60: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80018F64: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80018F68: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
L_80018F6C:
    // 0x80018F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018F74: jr          $ra
    // 0x80018F78: nop

    return;
    // 0x80018F78: nop

;}
RECOMP_FUNC void mnVSRecordGetGamesPlayedSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134934: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80134938: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8013493C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80134940: addiu       $v0, $v0, 0x4930
    ctx->r2 = ADD32(ctx->r2, 0X4930);
    // 0x80134944: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
L_80134948:
    // 0x80134948: lhu         $t6, 0x28($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X28);
    // 0x8013494C: lhu         $t7, 0x84($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X84);
    // 0x80134950: lhu         $t8, 0xE0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XE0);
    // 0x80134954: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80134958: lhu         $t9, 0x13C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X13C);
    // 0x8013495C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80134960: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    // 0x80134964: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80134968: bne         $a0, $v0, L_80134948
    if (ctx->r4 != ctx->r2) {
        // 0x8013496C: addu        $v1, $v1, $t9
        ctx->r3 = ADD32(ctx->r3, ctx->r25);
            goto L_80134948;
    }
    // 0x8013496C: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80134970: jr          $ra
    // 0x80134974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80134974: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mpCommonProcFighterOnFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDDE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DDDE8: jal         0x800DDDA8
    // 0x800DDDEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x800DDDEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800DDDF0: bne         $v0, $zero, L_800DDE08
    if (ctx->r2 != 0) {
        // 0x800DDDF4: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDE08;
    }
    // 0x800DDDF4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDDF8: jalr        $t9
    // 0x800DDDFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DDDFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800DDE00: b           L_800DDE0C
    // 0x800DDE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDE0C;
    // 0x800DDE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DDE08:
    // 0x800DDE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DDE0C:
    // 0x800DDE0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDE10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDE14: jr          $ra
    // 0x800DDE18: nop

    return;
    // 0x800DDE18: nop

;}
RECOMP_FUNC void itHarisenThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801752C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801752C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801752C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801752CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801752D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801752D4: jal         0x80172558
    // 0x801752D8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801752D8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_0:
    // 0x801752DC: jal         0x801713F4
    // 0x801752E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x801752E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801752E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801752E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801752EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801752F0: jr          $ra
    // 0x801752F4: nop

    return;
    // 0x801752F4: nop

;}
RECOMP_FUNC void ftMainUpdateShieldStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3048: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E304C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E3050: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E3054: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E3058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E305C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800E3060: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E3064: jal         0x80168128
    // 0x800E3068: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x800E3068: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E306C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800E3070: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E3074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E3078: lw          $t6, 0x48($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X48);
    // 0x800E307C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E3080: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800E3084: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800E3088: bgez        $t8, L_800E3098
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E308C: nop
    
            goto L_800E3098;
    }
    // 0x800E308C: nop

    // 0x800E3090: b           L_800E3098
    // 0x800E3094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_800E3098;
    // 0x800E3094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800E3098:
    // 0x800E3098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E309C: jal         0x8016679C
    // 0x800E30A0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E30A0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_1:
    // 0x800E30A4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E30A8: lw          $t9, 0x240($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X240);
    // 0x800E30AC: addiu       $a0, $s0, 0x248
    ctx->r4 = ADD32(ctx->r16, 0X248);
    // 0x800E30B0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E30B4: beql        $at, $zero, L_800E3110
    if (ctx->r1 == 0) {
        // 0x800E30B8: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_800E3110;
    }
    goto skip_0;
    // 0x800E30B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x800E30BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E30C0: sw          $v1, 0x240($s0)
    MEM_W(0X240, ctx->r16) = ctx->r3;
    // 0x800E30C4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800E30C8: swc1        $f0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->f0.u32l;
    // 0x800E30CC: swc1        $f0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->f0.u32l;
    // 0x800E30D0: swc1        $f4, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->f4.u32l;
    // 0x800E30D4: lw          $t0, 0x44($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X44);
    // 0x800E30D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E30DC: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800E30E0: bne         $t0, $at, L_800E30F8
    if (ctx->r8 != ctx->r1) {
        // 0x800E30E4: lw          $t1, 0x5C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X5C);
            goto L_800E30F8;
    }
    // 0x800E30E4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800E30E8: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800E30EC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800E30F0: b           L_800E3100
    // 0x800E30F4: swc1        $f8, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->f8.u32l;
        goto L_800E3100;
    // 0x800E30F4: swc1        $f8, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->f8.u32l;
L_800E30F8:
    // 0x800E30F8: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800E30FC: swc1        $f10, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->f10.u32l;
L_800E3100:
    // 0x800E3100: jal         0x80018EE0
    // 0x800E3104: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x800E3104: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800E3108: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E310C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
L_800E3110:
    // 0x800E3110: lw          $t3, 0x7CC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X7CC);
    // 0x800E3114: lw          $t7, 0x7C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C8);
    // 0x800E3118: lw          $t5, 0x3C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X3C);
    // 0x800E311C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800E3120: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E3124: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800E3128: beq         $at, $zero, L_800E3168
    if (ctx->r1 == 0) {
        // 0x800E312C: sw          $t6, 0x7CC($s1)
        MEM_W(0X7CC, ctx->r17) = ctx->r14;
            goto L_800E3168;
    }
    // 0x800E312C: sw          $t6, 0x7CC($s1)
    MEM_W(0X7CC, ctx->r17) = ctx->r14;
    // 0x800E3130: sw          $v1, 0x7C8($s1)
    MEM_W(0X7C8, ctx->r17) = ctx->r3;
    // 0x800E3134: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800E3138: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800E313C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800E3140: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E3144: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800E3148: nop

    // 0x800E314C: bc1fl       L_800E3160
    if (!c1cs) {
        // 0x800E3150: sw          $t9, 0x7D0($s1)
        MEM_W(0X7D0, ctx->r17) = ctx->r25;
            goto L_800E3160;
    }
    goto skip_1;
    // 0x800E3150: sw          $t9, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r25;
    skip_1:
    // 0x800E3154: b           L_800E3160
    // 0x800E3158: sw          $t8, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r24;
        goto L_800E3160;
    // 0x800E3158: sw          $t8, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r24;
    // 0x800E315C: sw          $t9, 0x7D0($s1)
    MEM_W(0X7D0, ctx->r17) = ctx->r25;
L_800E3160:
    // 0x800E3160: lbu         $t0, 0x11($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X11);
    // 0x800E3164: sw          $t0, 0x7D4($s1)
    MEM_W(0X7D4, ctx->r17) = ctx->r8;
L_800E3168:
    // 0x800E3168: lw          $t1, 0x8F4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8F4);
    // 0x800E316C: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x800E3170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E3174: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800E3178: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E317C: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800E3180: jal         0x800F0C4C
    // 0x800E3184: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    gmCollisionGetWeaponAttackShieldPosition(rdram, ctx);
        goto after_3;
    // 0x800E3184: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x800E3188: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800E318C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E3194: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800E3198: jal         0x80100BF0
    // 0x800E319C: addu        $a1, $t3, $v1
    ctx->r5 = ADD32(ctx->r11, ctx->r3);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x800E319C: addu        $a1, $t3, $v1
    ctx->r5 = ADD32(ctx->r11, ctx->r3);
    after_4:
    // 0x800E31A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E31A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E31A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E31AC: jr          $ra
    // 0x800E31B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E31B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftPikachuSpecialAirHiEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153340: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80153344: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80153348: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015334C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80153350: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x80153354: bnel        $t6, $at, L_8015339C
    if (ctx->r14 != ctx->r1) {
        // 0x80153358: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8015339C;
    }
    goto skip_0;
    // 0x80153358: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8015335C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80153360: jal         0x801531AC
    // 0x80153364: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    ftPikachuSpecialHiCheckGotoSubZip(rdram, ctx);
        goto after_0;
    // 0x80153364: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80153368: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8015336C: beq         $v0, $zero, L_8015338C
    if (ctx->r2 == 0) {
        // 0x80153370: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8015338C;
    }
    // 0x80153370: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80153374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80153378: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8015337C: jal         0x80152FEC
    // 0x80153380: sw          $t7, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = ctx->r15;
    ftPikachuSpecialAirHiSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153380: sw          $t7, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = ctx->r15;
    after_1:
    // 0x80153384: b           L_801533D8
    // 0x80153388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801533D8;
    // 0x80153388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015338C:
    // 0x8015338C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80153390: b           L_801533D4
    // 0x80153394: sw          $t8, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->r24;
        goto L_801533D4;
    // 0x80153394: sw          $t8, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->r24;
    // 0x80153398: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8015339C:
    // 0x8015339C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801533A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801533A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801533A8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801533AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801533B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801533B4: bc1fl       L_801533D8
    if (!c1cs) {
        // 0x801533B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801533D8;
    }
    goto skip_1;
    // 0x801533B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801533BC: lwc1        $f0, -0x3A80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3A80);
    // 0x801533C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801533C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801533C8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801533CC: jal         0x801438F0
    // 0x801533D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_2;
    // 0x801533D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
L_801533D4:
    // 0x801533D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801533D8:
    // 0x801533D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801533DC: jr          $ra
    // 0x801533E0: nop

    return;
    // 0x801533E0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136CD8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80136CDC: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80136CE0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80136CE4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80136CE8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80136CEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80136CF0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80136CF4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80136CF8: addiu       $t8, $t8, 0x7A38
    ctx->r24 = ADD32(ctx->r24, 0X7A38);
    // 0x80136CFC: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80136D00: addiu       $t0, $t0, 0x7A00
    ctx->r8 = ADD32(ctx->r8, 0X7A00);
    // 0x80136D04: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80136D08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80136D0C: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80136D10: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80136D14: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80136D18: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80136D1C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80136D20: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80136D24: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80136D28: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80136D2C: jal         0x800CDF78
    // 0x80136D30: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80136D30: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80136D34: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80136D38: addiu       $s0, $s0, 0x6F50
    ctx->r16 = ADD32(ctx->r16, 0X6F50);
    // 0x80136D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136D40: jal         0x800CDEEC
    // 0x80136D44: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80136D44: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80136D48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136D4C: jal         0x80004980
    // 0x80136D50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80136D50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80136D54: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80136D58: addiu       $a2, $a2, 0x7DF8
    ctx->r6 = ADD32(ctx->r6, 0X7DF8);
    // 0x80136D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136D60: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80136D64: jal         0x800CDE04
    // 0x80136D68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80136D68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80136D6C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80136D70: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136D74: addiu       $a1, $a1, 0x69D0
    ctx->r5 = ADD32(ctx->r5, 0X69D0);
    // 0x80136D78: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80136D7C: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80136D80: jal         0x80009968
    // 0x80136D84: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80136D84: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_4:
    // 0x80136D88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80136D8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80136D90: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80136D94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80136D98: jal         0x8000B9FC
    // 0x80136D9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80136D9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80136DA0: jal         0x80115890
    // 0x80136DA4: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80136DA4: nop

    after_6:
    // 0x80136DA8: jal         0x800FD300
    // 0x80136DAC: nop

    efManagerInitEffects(rdram, ctx);
        goto after_7;
    // 0x80136DAC: nop

    after_7:
    // 0x80136DB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80136DB4: jal         0x800D7194
    // 0x80136DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_8;
    // 0x80136DB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80136DBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80136DC0:
    // 0x80136DC0: jal         0x800D786C
    // 0x80136DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_9;
    // 0x80136DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80136DC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80136DCC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80136DD0: bne         $s0, $at, L_80136DC0
    if (ctx->r16 != ctx->r1) {
        // 0x80136DD4: nop
    
            goto L_80136DC0;
    }
    // 0x80136DD4: nop

    // 0x80136DD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136DDC: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x80136DE0: jal         0x80004980
    // 0x80136DE4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_10;
    // 0x80136DE4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_10:
    // 0x80136DE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136DEC: jal         0x80136B54
    // 0x80136DF0: sw          $v0, 0x7710($at)
    MEM_W(0X7710, ctx->r1) = ctx->r2;
    mnPlayers1PBonusInitVars(rdram, ctx);
        goto after_11;
    // 0x80136DF0: sw          $v0, 0x7710($at)
    MEM_W(0X7710, ctx->r1) = ctx->r2;
    after_11:
    // 0x80136DF4: jal         0x80132C14
    // 0x80136DF8: nop

    mnPlayers1PBonusMakePortraitCamera(rdram, ctx);
        goto after_12;
    // 0x80136DF8: nop

    after_12:
    // 0x80136DFC: jal         0x80135DA8
    // 0x80136E00: nop

    mnPlayers1PBonusMakeCursorCamera(rdram, ctx);
        goto after_13;
    // 0x80136E00: nop

    after_13:
    // 0x80136E04: jal         0x80135E48
    // 0x80136E08: nop

    mnPlayers1PBonusMakePuckCamera(rdram, ctx);
        goto after_14;
    // 0x80136E08: nop

    after_14:
    // 0x80136E0C: jal         0x80132DF4
    // 0x80136E10: nop

    mnPlayers1PBonusMakeGateCamera(rdram, ctx);
        goto after_15;
    // 0x80136E10: nop

    after_15:
    // 0x80136E14: jal         0x80134274
    // 0x80136E18: nop

    mnPlayers1PBonusMakeFighterCamera(rdram, ctx);
        goto after_16;
    // 0x80136E18: nop

    after_16:
    // 0x80136E1C: jal         0x80132CB4
    // 0x80136E20: nop

    mnPlayers1PBonusMakePortraitWallpaperCamera(rdram, ctx);
        goto after_17;
    // 0x80136E20: nop

    after_17:
    // 0x80136E24: jal         0x80132D54
    // 0x80136E28: nop

    mnPlayers1PBonusMakePortraitFlashCamera(rdram, ctx);
        goto after_18;
    // 0x80136E28: nop

    after_18:
    // 0x80136E2C: jal         0x80133170
    // 0x80136E30: nop

    mnPlayers1PBonusMakeWallpaperCamera(rdram, ctx);
        goto after_19;
    // 0x80136E30: nop

    after_19:
    // 0x80136E34: jal         0x80133370
    // 0x80136E38: nop

    mnPlayers1PBonusMakeLabelsCamera(rdram, ctx);
        goto after_20;
    // 0x80136E38: nop

    after_20:
    // 0x80136E3C: jal         0x80135D08
    // 0x80136E40: nop

    mnPlayers1PBonusMakeReadyCamera(rdram, ctx);
        goto after_21;
    // 0x80136E40: nop

    after_21:
    // 0x80136E44: jal         0x801330CC
    // 0x80136E48: nop

    mnPlayers1PBonusMakeWallpaper(rdram, ctx);
        goto after_22;
    // 0x80136E48: nop

    after_22:
    // 0x80136E4C: jal         0x80132A58
    // 0x80136E50: nop

    mnPlayers1PBonusMakePortraitAll(rdram, ctx);
        goto after_23;
    // 0x80136E50: nop

    after_23:
    // 0x80136E54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136E58: jal         0x80136C14
    // 0x80136E5C: lw          $a0, 0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76F8);
    mnPlayers1PBonusInitSlot(rdram, ctx);
        goto after_24;
    // 0x80136E5C: lw          $a0, 0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76F8);
    after_24:
    // 0x80136E60: jal         0x80133218
    // 0x80136E64: nop

    mnPlayers1PBonusMakeLabels(rdram, ctx);
        goto after_25;
    // 0x80136E64: nop

    after_25:
    // 0x80136E68: jal         0x80136C88
    // 0x80136E6C: nop

    mnPlayers1PBonusCheckBonusCompleteAll(rdram, ctx);
        goto after_26;
    // 0x80136E6C: nop

    after_26:
    // 0x80136E70: beq         $v0, $zero, L_80136E80
    if (ctx->r2 == 0) {
        // 0x80136E74: nop
    
            goto L_80136E80;
    }
    // 0x80136E74: nop

    // 0x80136E78: jal         0x80133C1C
    // 0x80136E7C: nop

    mnPlayers1PBonusMakeTotalTime(rdram, ctx);
        goto after_27;
    // 0x80136E7C: nop

    after_27:
L_80136E80:
    // 0x80136E80: jal         0x8013649C
    // 0x80136E84: nop

    mnPlayers1PBonusMakePuckAdjust(rdram, ctx);
        goto after_28;
    // 0x80136E84: nop

    after_28:
    // 0x80136E88: jal         0x801365B8
    // 0x80136E8C: nop

    mnPlayers1PBonusMakeSpotlight(rdram, ctx);
        goto after_29;
    // 0x80136E8C: nop

    after_29:
    // 0x80136E90: jal         0x80136704
    // 0x80136E94: nop

    mnPlayers1PBonusMakeReady(rdram, ctx);
        goto after_30;
    // 0x80136E94: nop

    after_30:
    // 0x80136E98: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80136E9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80136EA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80136EA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80136EA8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80136EAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80136EB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80136EB4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80136EB8: jal         0x803904E0
    // 0x80136EBC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_31;
    // 0x80136EBC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_31:
    // 0x80136EC0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80136EC4: lbu         $t4, 0x4AD1($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AD1);
    // 0x80136EC8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80136ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136ED0: beql        $t4, $at, L_80136EE4
    if (ctx->r12 == ctx->r1) {
        // 0x80136ED4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80136EE4;
    }
    goto skip_0;
    // 0x80136ED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80136ED8: jal         0x80020AB4
    // 0x80136EDC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    syAudioPlayBGM(rdram, ctx);
        goto after_32;
    // 0x80136EDC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_32:
    // 0x80136EE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80136EE4:
    // 0x80136EE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80136EE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80136EEC: jr          $ra
    // 0x80136EF0: nop

    return;
    // 0x80136EF0: nop

;}
RECOMP_FUNC void mnVSRecordGetFighterKindByIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131B28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B2C: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131B30: addiu       $t6, $t6, 0x66A0
    ctx->r14 = ADD32(ctx->r14, 0X66A0);
    // 0x80131B34: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131B38: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131B3C:
    // 0x80131B3C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131B40: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131B44: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131B48: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131B4C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131B50: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131B54: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131B58: bne         $t6, $t0, L_80131B3C
    if (ctx->r14 != ctx->r8) {
        // 0x80131B5C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131B3C;
    }
    // 0x80131B5C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131B60: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80131B64: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80131B68: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80131B6C: jr          $ra
    // 0x80131B70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131B70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ifCommonBonusInterfaceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114B48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114B4C: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x80114B50: jal         0x8000AF58
    // 0x80114B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_0;
    // 0x80114B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80114B58: jal         0x801157EC
    // 0x80114B5C: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_1;
    // 0x80114B5C: nop

    after_1:
    // 0x80114B60: jal         0x800266A0
    // 0x80114B64: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x80114B64: nop

    after_2:
    // 0x80114B68: jal         0x8011379C
    // 0x80114B6C: nop

    ifCommonBattleEndPlaySoundQueue(rdram, ctx);
        goto after_3;
    // 0x80114B6C: nop

    after_3:
    // 0x80114B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114B78: jr          $ra
    // 0x80114B7C: nop

    return;
    // 0x80114B7C: nop

;}
RECOMP_FUNC void mpCollisionCheckFloorSurfaceTilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F47AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F47B0: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F47B4: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F47B8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800F47BC: subu        $v0, $a3, $a1
    ctx->r2 = SUB32(ctx->r7, ctx->r5);
    // 0x800F47C0: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F47C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F47C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F47CC: bgez        $v0, L_800F47E0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F47D0: swc1        $f0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
            goto L_800F47E0;
    }
    // 0x800F47D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800F47D4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800F47D8: b           L_800F47E4
    // 0x800F47DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_800F47E4;
    // 0x800F47DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800F47E0:
    // 0x800F47E0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800F47E4:
    // 0x800F47E4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F47E8: nop

    // 0x800F47EC: bc1fl       L_800F4848
    if (!c1cs) {
        // 0x800F47F0: mtc1        $a0, $f6
        ctx->f6.u32l = ctx->r4;
            goto L_800F4848;
    }
    goto skip_0;
    // 0x800F47F0: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    skip_0:
    // 0x800F47F4: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800F47F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F47FC: lwc1        $f10, 0x778($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X778);
    // 0x800F4800: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4804: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F4808: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F480C: nop

    // 0x800F4810: bc1t        L_800F483C
    if (c1cs) {
        // 0x800F4814: nop
    
            goto L_800F483C;
    }
    // 0x800F4814: nop

    // 0x800F4818: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F481C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4820: lwc1        $f10, 0x77C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77C);
    // 0x800F4824: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4828: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F482C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F4830: nop

    // 0x800F4834: bc1fl       L_800F4898
    if (!c1cs) {
        // 0x800F4838: lwc1        $f16, 0x78($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
            goto L_800F4898;
    }
    goto skip_1;
    // 0x800F4838: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    skip_1:
L_800F483C:
    // 0x800F483C: b           L_800F4BD0
    // 0x800F4840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4844: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
L_800F4848:
    // 0x800F4848: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F484C: lwc1        $f10, 0x780($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X780);
    // 0x800F4850: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4854: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F4858: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800F485C: nop

    // 0x800F4860: bc1t        L_800F488C
    if (c1cs) {
        // 0x800F4864: nop
    
            goto L_800F488C;
    }
    // 0x800F4864: nop

    // 0x800F4868: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F486C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4870: lwc1        $f10, 0x784($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X784);
    // 0x800F4874: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4878: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F487C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F4880: nop

    // 0x800F4884: bc1fl       L_800F4898
    if (!c1cs) {
        // 0x800F4888: lwc1        $f16, 0x78($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
            goto L_800F4898;
    }
    goto skip_2;
    // 0x800F4888: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    skip_2:
L_800F488C:
    // 0x800F488C: b           L_800F4BD0
    // 0x800F4890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4894: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
L_800F4898:
    // 0x800F4898: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F489C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800F48A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F48A4: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F48A8: subu        $v1, $a2, $t6
    ctx->r3 = SUB32(ctx->r6, ctx->r14);
    // 0x800F48AC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800F48B0: bgez        $v1, L_800F48C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F48B4: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_800F48C4;
    }
    // 0x800F48B4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800F48B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F48BC: b           L_800F48C8
    // 0x800F48C0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
        goto L_800F48C8;
    // 0x800F48C0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800F48C4:
    // 0x800F48C4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
L_800F48C8:
    // 0x800F48C8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F48CC: nop

    // 0x800F48D0: bc1fl       L_800F491C
    if (!c1cs) {
        // 0x800F48D4: mtc1        $a3, $f4
        ctx->f4.u32l = ctx->r7;
            goto L_800F491C;
    }
    goto skip_3;
    // 0x800F48D4: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    skip_3:
    // 0x800F48D8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800F48DC: nop

    // 0x800F48E0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F48E4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800F48E8: nop

    // 0x800F48EC: bc1t        L_800F4910
    if (c1cs) {
        // 0x800F48F0: nop
    
            goto L_800F4910;
    }
    // 0x800F48F0: nop

    // 0x800F48F4: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800F48F8: nop

    // 0x800F48FC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F4900: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800F4904: nop

    // 0x800F4908: bc1fl       L_800F495C
    if (!c1cs) {
        // 0x800F490C: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_800F495C;
    }
    goto skip_4;
    // 0x800F490C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_4:
L_800F4910:
    // 0x800F4910: b           L_800F4BD0
    // 0x800F4914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4918: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
L_800F491C:
    // 0x800F491C: nop

    // 0x800F4920: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F4924: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800F4928: nop

    // 0x800F492C: bc1t        L_800F4950
    if (c1cs) {
        // 0x800F4930: nop
    
            goto L_800F4950;
    }
    // 0x800F4930: nop

    // 0x800F4934: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800F4938: nop

    // 0x800F493C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4940: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800F4944: nop

    // 0x800F4948: bc1fl       L_800F495C
    if (!c1cs) {
        // 0x800F494C: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_800F495C;
    }
    goto skip_5;
    // 0x800F494C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_5:
L_800F4950:
    // 0x800F4950: b           L_800F4BD0
    // 0x800F4954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4958: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_800F495C:
    // 0x800F495C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800F4960: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800F4964: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F4968: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F496C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F4970: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F4974: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F497C: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F4980: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F4984: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800F4988: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F498C: swc1        $f14, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f14.u32l;
    // 0x800F4990: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800F4994: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F4998: lwc1        $f8, 0x788($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X788);
    // 0x800F499C: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800F49A0: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F49A4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800F49A8: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800F49AC: add.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800F49B0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F49B4: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F49B8: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800F49BC: nop

    // 0x800F49C0: bc1f        L_800F4BD0
    if (!c1cs) {
        // 0x800F49C4: nop
    
            goto L_800F4BD0;
    }
    // 0x800F49C4: nop

    // 0x800F49C8: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800F49CC: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F49D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F49D4: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
    // 0x800F49D8: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F49DC: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F49E0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F49E4: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800F49E8: lwc1        $f6, 0x78C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X78C);
    // 0x800F49EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F49F0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F49F4: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F49F8: sub.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800F49FC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F4A00: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x800F4A04: nop

    // 0x800F4A08: bc1fl       L_800F4A5C
    if (!c1cs) {
        // 0x800F4A0C: sub.s       $f0, $f10, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
            goto L_800F4A5C;
    }
    goto skip_6;
    // 0x800F4A0C: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    skip_6:
    // 0x800F4A10: lwc1        $f4, 0x790($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X790);
    // 0x800F4A14: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F4A18: nop

    // 0x800F4A1C: bc1f        L_800F4BD0
    if (!c1cs) {
        // 0x800F4A20: nop
    
            goto L_800F4BD0;
    }
    // 0x800F4A20: nop

    // 0x800F4A24: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800F4A28: nop

    // 0x800F4A2C: bc1f        L_800F4BD0
    if (!c1cs) {
        // 0x800F4A30: nop
    
            goto L_800F4BD0;
    }
    // 0x800F4A30: nop

    // 0x800F4A34: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x800F4A38: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800F4A3C: bc1f        L_800F4BD0
    if (!c1cs) {
        // 0x800F4A40: nop
    
            goto L_800F4BD0;
    }
    // 0x800F4A40: nop

    // 0x800F4A44: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800F4A48: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F4A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F4A50: b           L_800F4BD0
    // 0x800F4A54: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
        goto L_800F4BD0;
    // 0x800F4A54: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
    // 0x800F4A58: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
L_800F4A5C:
    // 0x800F4A5C: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F4A60: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F4A64: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F4A68: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F4A6C: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F4A70: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800F4A74: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800F4A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F4A7C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F4A80: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F4A84: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800F4A88: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F4A8C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F4A90: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F4A94: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F4A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800F4A9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F4AA0: div.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F4AA4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800F4AA8: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x800F4AAC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x800F4AB0: bc1fl       L_800F4AEC
    if (!c1cs) {
        // 0x800F4AB4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800F4AEC;
    }
    goto skip_7;
    // 0x800F4AB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_7:
    // 0x800F4AB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4ABC: lwc1        $f4, 0x794($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X794);
    // 0x800F4AC0: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
    // 0x800F4AC4: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F4AC8: nop

    // 0x800F4ACC: bc1fl       L_800F4AE0
    if (!c1cs) {
        // 0x800F4AD0: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800F4AE0;
    }
    goto skip_8;
    // 0x800F4AD0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_8:
    // 0x800F4AD4: b           L_800F4BD0
    // 0x800F4AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4ADC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800F4AE0:
    // 0x800F4AE0: b           L_800F4B28
    // 0x800F4AE4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
        goto L_800F4B28;
    // 0x800F4AE4: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F4AE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800F4AEC:
    // 0x800F4AEC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F4AF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4AF4: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800F4AF8: nop

    // 0x800F4AFC: bc1fl       L_800F4B28
    if (!c1cs) {
        // 0x800F4B00: lwc1        $f8, 0x4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800F4B28;
    }
    goto skip_9;
    // 0x800F4B00: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    skip_9:
    // 0x800F4B04: lwc1        $f10, 0x798($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X798);
    // 0x800F4B08: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800F4B0C: nop

    // 0x800F4B10: bc1fl       L_800F4B24
    if (!c1cs) {
        // 0x800F4B14: mov.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
            goto L_800F4B24;
    }
    goto skip_10;
    // 0x800F4B14: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    skip_10:
    // 0x800F4B18: b           L_800F4BD0
    // 0x800F4B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4B20: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800F4B24:
    // 0x800F4B24: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
L_800F4B28:
    // 0x800F4B28: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F4B2C: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F4B30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4B34: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800F4B38: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F4B3C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800F4B40: lwc1        $f8, 0x79C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C);
    // 0x800F4B44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4B48: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F4B4C: div.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800F4B50: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800F4B54: nop

    // 0x800F4B58: bc1t        L_800F4B78
    if (c1cs) {
        // 0x800F4B5C: nop
    
            goto L_800F4B78;
    }
    // 0x800F4B5C: nop

    // 0x800F4B60: lwc1        $f6, 0x7A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A0);
    // 0x800F4B64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F4B68: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800F4B6C: nop

    // 0x800F4B70: bc1fl       L_800F4B84
    if (!c1cs) {
        // 0x800F4B74: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800F4B84;
    }
    goto skip_11;
    // 0x800F4B74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_11:
L_800F4B78:
    // 0x800F4B78: b           L_800F4BD0
    // 0x800F4B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F4BD0;
    // 0x800F4B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F4B80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800F4B84:
    // 0x800F4B84: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F4B88: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F4B8C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F4B90: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800F4B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F4B98: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F4B9C: nop

    // 0x800F4BA0: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F4BA4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800F4BA8: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800F4BAC: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F4BB0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F4BB4: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800F4BB8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800F4BBC: nop

    // 0x800F4BC0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F4BC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F4BC8: b           L_800F4BD0
    // 0x800F4BCC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
        goto L_800F4BD0;
    // 0x800F4BCC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
L_800F4BD0:
    // 0x800F4BD0: jr          $ra
    // 0x800F4BD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F4BD4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void alCSPSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002FC1C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002FC20: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002FC24: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8002FC28: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    // 0x8002FC2C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8002FC30: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FC34: jal         0x80028D70
    // 0x8002FC38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FC38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FC3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FC40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002FC44: jr          $ra
    // 0x8002FC48: nop

    return;
    // 0x8002FC48: nop

;}
RECOMP_FUNC void func_ovl3_80135B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135B78: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80135B7C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80135B80: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80135B84: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80135B88: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80135B8C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80135B90: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80135B94: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80135B98: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80135B9C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80135BA0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80135BA4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80135BA8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80135BAC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80135BB0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80135BB4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80135BB8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80135BBC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80135BC0: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80135BC4: lw          $a1, 0x66FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66FC);
    // 0x80135BC8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80135BCC: lwc1        $f30, 0x1C($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80135BD0: beq         $a1, $zero, L_80135C24
    if (ctx->r5 == 0) {
        // 0x80135BD4: lwc1        $f22, 0x20($v0)
        ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
            goto L_80135C24;
    }
    // 0x80135BD4: lwc1        $f22, 0x20($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80135BD8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x80135BDC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80135BE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80135BE4:
    // 0x80135BE4: beql        $a1, $a0, L_80135C1C
    if (ctx->r5 == ctx->r4) {
        // 0x80135BE8: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80135C1C;
    }
    goto skip_0;
    // 0x80135BE8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80135BEC: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x80135BF0: lbu         $t7, 0xC($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC);
    // 0x80135BF4: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x80135BF8: beql        $t6, $t7, L_80135C1C
    if (ctx->r14 == ctx->r15) {
        // 0x80135BFC: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80135C1C;
    }
    goto skip_1;
    // 0x80135BFC: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x80135C00: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80135C04: bnel        $a2, $t8, L_80135C1C
    if (ctx->r6 != ctx->r24) {
        // 0x80135C08: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80135C1C;
    }
    goto skip_2;
    // 0x80135C08: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_2:
    // 0x80135C0C: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    // 0x80135C10: bnel        $a3, $t9, L_80135C1C
    if (ctx->r7 != ctx->r25) {
        // 0x80135C14: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_80135C1C;
    }
    goto skip_3;
    // 0x80135C14: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_3:
    // 0x80135C18: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_80135C1C:
    // 0x80135C1C: bne         $a1, $zero, L_80135BE4
    if (ctx->r5 != 0) {
        // 0x80135C20: nop
    
            goto L_80135BE4;
    }
    // 0x80135C20: nop

L_80135C24:
    // 0x80135C24: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80135C28: lw          $s7, 0x6704($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X6704);
    // 0x80135C2C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80135C30: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80135C34: beql        $s7, $zero, L_80135ED0
    if (ctx->r23 == 0) {
        // 0x80135C38: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80135ED0;
    }
    goto skip_4;
    // 0x80135C38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_4:
    // 0x80135C3C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80135C40: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80135C44: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80135C48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80135C4C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80135C50: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80135C54: addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // 0x80135C58: lw          $s4, 0x84($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X84);
L_80135C5C:
    // 0x80135C5C: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x80135C60: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80135C64: lw          $t1, 0x8($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X8);
    // 0x80135C68: beql        $t0, $t1, L_80135EC4
    if (ctx->r8 == ctx->r9) {
        // 0x80135C6C: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80135EC4;
    }
    goto skip_5;
    // 0x80135C6C: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_5:
    // 0x80135C70: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80135C74: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x80135C78: bnel        $fp, $t2, L_80135CA0
    if (ctx->r30 != ctx->r10) {
        // 0x80135C7C: lw          $v0, 0x100($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X100);
            goto L_80135CA0;
    }
    goto skip_6;
    // 0x80135C7C: lw          $v0, 0x100($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X100);
    skip_6:
    // 0x80135C80: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x80135C84: bnel        $t3, $zero, L_80135CA0
    if (ctx->r11 != 0) {
        // 0x80135C88: lw          $v0, 0x100($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X100);
            goto L_80135CA0;
    }
    goto skip_7;
    // 0x80135C88: lw          $v0, 0x100($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X100);
    skip_7:
    // 0x80135C8C: lbu         $t4, 0xC($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XC);
    // 0x80135C90: lbu         $t5, 0x10($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X10);
    // 0x80135C94: beql        $t4, $t5, L_80135EC4
    if (ctx->r12 == ctx->r13) {
        // 0x80135C98: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80135EC4;
    }
    goto skip_8;
    // 0x80135C98: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_8:
    // 0x80135C9C: lw          $v0, 0x100($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X100);
L_80135CA0:
    // 0x80135CA0: beql        $v0, $zero, L_80135EC4
    if (ctx->r2 == 0) {
        // 0x80135CA4: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80135EC4;
    }
    goto skip_9;
    // 0x80135CA4: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_9:
    // 0x80135CA8: beql        $fp, $v0, L_80135EC4
    if (ctx->r30 == ctx->r2) {
        // 0x80135CAC: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80135EC4;
    }
    goto skip_10;
    // 0x80135CAC: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_10:
    // 0x80135CB0: lbu         $t6, 0x144($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X144);
    // 0x80135CB4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80135CB8: beql        $t7, $zero, L_80135EC4
    if (ctx->r15 == 0) {
        // 0x80135CBC: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80135EC4;
    }
    goto skip_11;
    // 0x80135CBC: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_11:
    // 0x80135CC0: lw          $t8, 0x150($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X150);
    // 0x80135CC4: addiu       $s3, $s4, 0x100
    ctx->r19 = ADD32(ctx->r20, 0X100);
    // 0x80135CC8: or          $s5, $s3, $zero
    ctx->r21 = ctx->r19 | 0;
    // 0x80135CCC: blez        $t8, L_80135EC0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80135CD0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80135EC0;
    }
    // 0x80135CD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80135CD4: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
L_80135CD8:
    // 0x80135CD8: lwc1        $f6, 0x20($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X20);
    // 0x80135CDC: lwc1        $f8, 0x48($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80135CE0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80135CE4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80135CE8: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135CEC: mul.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80135CF0: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80135CF4: nop

    // 0x80135CF8: bc1fl       L_80135EB0
    if (!c1cs) {
        // 0x80135CFC: lw          $t2, 0x50($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X50);
            goto L_80135EB0;
    }
    goto skip_12;
    // 0x80135CFC: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    skip_12:
    // 0x80135D00: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135D04: lwc1        $f8, 0x28($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80135D08: lwc1        $f10, 0x260($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X260);
    // 0x80135D0C: mflo        $t0
    ctx->r8 = lo;
    // 0x80135D10: addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // 0x80135D14: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80135D18: sub.s       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f4.fl;
    // 0x80135D1C: mul.s       $f0, $f6, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80135D20: nop

    // 0x80135D24: mul.s       $f12, $f8, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80135D28: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80135D2C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80135D30: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80135D34: nop

    // 0x80135D38: bc1f        L_80135EAC
    if (!c1cs) {
        // 0x80135D3C: nop
    
            goto L_80135EAC;
    }
    // 0x80135D3C: nop

    // 0x80135D40: div.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80135D44: c.lt.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl < ctx->f26.fl;
    // 0x80135D48: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x80135D4C: bc1fl       L_80135EB0
    if (!c1cs) {
        // 0x80135D50: lw          $t2, 0x50($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X50);
            goto L_80135EB0;
    }
    goto skip_13;
    // 0x80135D50: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    skip_13:
    // 0x80135D54: lw          $t1, 0x14C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X14C);
    // 0x80135D58: lwc1        $f18, 0x264($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X264);
    // 0x80135D5C: beql        $t1, $zero, L_80135D78
    if (ctx->r9 == 0) {
        // 0x80135D60: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_80135D78;
    }
    goto skip_14;
    // 0x80135D60: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_14:
    // 0x80135D64: lwc1        $f6, 0x4C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x80135D68: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80135D6C: b           L_80135D78
    // 0x80135D70: add.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f22.fl;
        goto L_80135D78;
    // 0x80135D70: add.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80135D74: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_80135D78:
    // 0x80135D78: lwc1        $f2, 0x58($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135D7C: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80135D80: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80135D84: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80135D88: nop

    // 0x80135D8C: bc1fl       L_80135EB0
    if (!c1cs) {
        // 0x80135D90: lw          $t2, 0x50($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X50);
            goto L_80135EB0;
    }
    goto skip_15;
    // 0x80135D90: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    skip_15:
    // 0x80135D94: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80135D98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80135D9C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80135DA0: nop

    // 0x80135DA4: bc1fl       L_80135EB0
    if (!c1cs) {
        // 0x80135DA8: lw          $t2, 0x50($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X50);
            goto L_80135EB0;
    }
    goto skip_16;
    // 0x80135DA8: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    skip_16:
    // 0x80135DAC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80135DB0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80135DB4: addiu       $s1, $s2, 0x1CC
    ctx->r17 = ADD32(ctx->r18, 0X1CC);
    // 0x80135DB8: swc1        $f0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f0.u32l;
    // 0x80135DBC: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80135DC0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80135DC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80135DC8: nop

    // 0x80135DCC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80135DD0: beql        $t3, $zero, L_80135E20
    if (ctx->r11 == 0) {
        // 0x80135DD4: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_80135E20;
    }
    goto skip_17;
    // 0x80135DD4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_17:
    // 0x80135DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135DDC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80135DE0: sub.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80135DE4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80135DE8: nop

    // 0x80135DEC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80135DF0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80135DF4: nop

    // 0x80135DF8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80135DFC: bne         $t3, $zero, L_80135E14
    if (ctx->r11 != 0) {
        // 0x80135E00: nop
    
            goto L_80135E14;
    }
    // 0x80135E00: nop

    // 0x80135E04: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80135E08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80135E0C: b           L_80135E2C
    // 0x80135E10: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80135E2C;
    // 0x80135E10: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80135E14:
    // 0x80135E14: b           L_80135E2C
    // 0x80135E18: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80135E2C;
    // 0x80135E18: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80135E1C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_80135E20:
    // 0x80135E20: nop

    // 0x80135E24: bltz        $t3, L_80135E14
    if (SIGNED(ctx->r11) < 0) {
        // 0x80135E28: nop
    
            goto L_80135E14;
    }
    // 0x80135E28: nop

L_80135E2C:
    // 0x80135E2C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80135E30: jal         0x80018948
    // 0x80135E34: sb          $t3, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80135E34: sb          $t3, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r11;
    after_0:
    // 0x80135E38: lbu         $t4, 0x13($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X13);
    // 0x80135E3C: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80135E40: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80135E44: nop

    // 0x80135E48: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80135E4C: div.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f28.fl);
    // 0x80135E50: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80135E54: nop

    // 0x80135E58: bc1fl       L_80135EB0
    if (!c1cs) {
        // 0x80135E5C: lw          $t2, 0x50($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X50);
            goto L_80135EB0;
    }
    goto skip_18;
    // 0x80135E5C: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
    skip_18:
    // 0x80135E60: lw          $t6, 0x48($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X48);
    // 0x80135E64: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x80135E68: bltz        $t8, L_80135EA4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80135E6C: nop
    
            goto L_80135EA4;
    }
    // 0x80135E6C: nop

    // 0x80135E70: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x80135E74: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80135E78: beql        $v0, $fp, L_80135E9C
    if (ctx->r2 == ctx->r30) {
        // 0x80135E7C: lbu         $t0, 0x49($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X49);
            goto L_80135E9C;
    }
    goto skip_19;
    // 0x80135E7C: lbu         $t0, 0x49($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X49);
    skip_19:
    // 0x80135E80: beq         $v0, $at, L_80135E98
    if (ctx->r2 == ctx->r1) {
        // 0x80135E84: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80135E98;
    }
    // 0x80135E84: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80135E88: beq         $v0, $at, L_80135E98
    if (ctx->r2 == ctx->r1) {
        // 0x80135E8C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80135E98;
    }
    // 0x80135E8C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80135E90: bne         $v0, $at, L_80135EA4
    if (ctx->r2 != ctx->r1) {
        // 0x80135E94: nop
    
            goto L_80135EA4;
    }
    // 0x80135E94: nop

L_80135E98:
    // 0x80135E98: lbu         $t0, 0x49($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X49);
L_80135E9C:
    // 0x80135E9C: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80135EA0: sb          $t1, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r9;
L_80135EA4:
    // 0x80135EA4: b           L_80136174
    // 0x80135EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136174;
    // 0x80135EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135EAC:
    // 0x80135EAC: lw          $t2, 0x50($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X50);
L_80135EB0:
    // 0x80135EB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80135EB4: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80135EB8: bnel        $at, $zero, L_80135CD8
    if (ctx->r1 != 0) {
        // 0x80135EBC: lw          $t9, 0x18($s4)
        ctx->r25 = MEM_W(ctx->r20, 0X18);
            goto L_80135CD8;
    }
    goto skip_20;
    // 0x80135EBC: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
    skip_20:
L_80135EC0:
    // 0x80135EC0: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
L_80135EC4:
    // 0x80135EC4: bnel        $s7, $zero, L_80135C5C
    if (ctx->r23 != 0) {
        // 0x80135EC8: lw          $s4, 0x84($s7)
        ctx->r20 = MEM_W(ctx->r23, 0X84);
            goto L_80135C5C;
    }
    goto skip_21;
    // 0x80135EC8: lw          $s4, 0x84($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X84);
    skip_21:
    // 0x80135ECC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80135ED0:
    // 0x80135ED0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80135ED4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80135ED8: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80135EDC: lw          $s7, 0x6700($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X6700);
    // 0x80135EE0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80135EE4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80135EE8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80135EEC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80135EF0: addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // 0x80135EF4: beq         $s7, $zero, L_80136170
    if (ctx->r23 == 0) {
        // 0x80135EF8: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80136170;
    }
    // 0x80135EF8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80135EFC: lw          $s4, 0x84($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X84);
L_80135F00:
    // 0x80135F00: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x80135F04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80135F08: lw          $t4, 0x8($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X8);
    // 0x80135F0C: beql        $t3, $t4, L_80136168
    if (ctx->r11 == ctx->r12) {
        // 0x80135F10: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80136168;
    }
    goto skip_22;
    // 0x80135F10: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_22:
    // 0x80135F14: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80135F18: lbu         $t5, 0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2);
    // 0x80135F1C: bnel        $fp, $t5, L_80135F44
    if (ctx->r30 != ctx->r13) {
        // 0x80135F20: lw          $v0, 0x10C($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X10C);
            goto L_80135F44;
    }
    goto skip_23;
    // 0x80135F20: lw          $v0, 0x10C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10C);
    skip_23:
    // 0x80135F24: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x80135F28: bnel        $t6, $zero, L_80135F44
    if (ctx->r14 != 0) {
        // 0x80135F2C: lw          $v0, 0x10C($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X10C);
            goto L_80135F44;
    }
    goto skip_24;
    // 0x80135F2C: lw          $v0, 0x10C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10C);
    skip_24:
    // 0x80135F30: lbu         $t7, 0xC($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC);
    // 0x80135F34: lbu         $t8, 0x14($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X14);
    // 0x80135F38: beql        $t7, $t8, L_80136168
    if (ctx->r15 == ctx->r24) {
        // 0x80135F3C: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80136168;
    }
    goto skip_25;
    // 0x80135F3C: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_25:
    // 0x80135F40: lw          $v0, 0x10C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10C);
L_80135F44:
    // 0x80135F44: beql        $v0, $zero, L_80136168
    if (ctx->r2 == 0) {
        // 0x80135F48: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80136168;
    }
    goto skip_26;
    // 0x80135F48: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_26:
    // 0x80135F4C: beql        $fp, $v0, L_80136168
    if (ctx->r30 == ctx->r2) {
        // 0x80135F50: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80136168;
    }
    goto skip_27;
    // 0x80135F50: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_27:
    // 0x80135F54: lbu         $t9, 0x154($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X154);
    // 0x80135F58: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80135F5C: beql        $t0, $zero, L_80136168
    if (ctx->r8 == 0) {
        // 0x80135F60: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80136168;
    }
    goto skip_28;
    // 0x80135F60: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_28:
    // 0x80135F64: lw          $t1, 0x160($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X160);
    // 0x80135F68: addiu       $s3, $s4, 0x10C
    ctx->r19 = ADD32(ctx->r20, 0X10C);
    // 0x80135F6C: or          $s5, $s3, $zero
    ctx->r21 = ctx->r19 | 0;
    // 0x80135F70: blez        $t1, L_80136164
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80135F74: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80136164;
    }
    // 0x80135F74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80135F78: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
L_80135F7C:
    // 0x80135F7C: lwc1        $f10, 0x2C($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x80135F80: lwc1        $f4, 0x48($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80135F84: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80135F88: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80135F8C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135F90: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80135F94: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80135F98: nop

    // 0x80135F9C: bc1fl       L_80136154
    if (!c1cs) {
        // 0x80135FA0: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80136154;
    }
    goto skip_29;
    // 0x80135FA0: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_29:
    // 0x80135FA4: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135FA8: lwc1        $f4, 0x2C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x80135FAC: lwc1        $f6, 0x260($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X260);
    // 0x80135FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x80135FB4: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
    // 0x80135FB8: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135FBC: sub.s       $f10, $f30, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x80135FC0: mul.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80135FC4: nop

    // 0x80135FC8: mul.s       $f12, $f4, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80135FCC: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80135FD0: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80135FD4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80135FD8: nop

    // 0x80135FDC: bc1f        L_80136150
    if (!c1cs) {
        // 0x80135FE0: nop
    
            goto L_80136150;
    }
    // 0x80135FE0: nop

    // 0x80135FE4: div.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80135FE8: c.lt.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl < ctx->f26.fl;
    // 0x80135FEC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x80135FF0: bc1fl       L_80136154
    if (!c1cs) {
        // 0x80135FF4: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80136154;
    }
    goto skip_30;
    // 0x80135FF4: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_30:
    // 0x80135FF8: lw          $t4, 0x14C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14C);
    // 0x80135FFC: lwc1        $f18, 0x264($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X264);
    // 0x80136000: beql        $t4, $zero, L_8013601C
    if (ctx->r12 == 0) {
        // 0x80136004: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8013601C;
    }
    goto skip_31;
    // 0x80136004: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_31:
    // 0x80136008: lwc1        $f10, 0x4C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x8013600C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80136010: b           L_8013601C
    // 0x80136014: add.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f22.fl;
        goto L_8013601C;
    // 0x80136014: add.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80136018: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_8013601C:
    // 0x8013601C: lwc1        $f2, 0x5C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136020: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80136024: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80136028: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8013602C: nop

    // 0x80136030: bc1fl       L_80136154
    if (!c1cs) {
        // 0x80136034: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80136154;
    }
    goto skip_32;
    // 0x80136034: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_32:
    // 0x80136038: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8013603C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136040: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80136044: nop

    // 0x80136048: bc1fl       L_80136154
    if (!c1cs) {
        // 0x8013604C: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80136154;
    }
    goto skip_33;
    // 0x8013604C: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_33:
    // 0x80136050: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80136054: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80136058: addiu       $s1, $s2, 0x1CC
    ctx->r17 = ADD32(ctx->r18, 0X1CC);
    // 0x8013605C: swc1        $f0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f0.u32l;
    // 0x80136060: cvt.w.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80136064: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80136068: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8013606C: nop

    // 0x80136070: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80136074: beql        $t6, $zero, L_801360C4
    if (ctx->r14 == 0) {
        // 0x80136078: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_801360C4;
    }
    goto skip_34;
    // 0x80136078: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_34:
    // 0x8013607C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136080: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80136084: sub.s       $f4, $f14, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80136088: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8013608C: nop

    // 0x80136090: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80136094: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80136098: nop

    // 0x8013609C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801360A0: bne         $t6, $zero, L_801360B8
    if (ctx->r14 != 0) {
        // 0x801360A4: nop
    
            goto L_801360B8;
    }
    // 0x801360A4: nop

    // 0x801360A8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801360AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801360B0: b           L_801360D0
    // 0x801360B4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_801360D0;
    // 0x801360B4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_801360B8:
    // 0x801360B8: b           L_801360D0
    // 0x801360BC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_801360D0;
    // 0x801360BC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801360C0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_801360C4:
    // 0x801360C4: nop

    // 0x801360C8: bltz        $t6, L_801360B8
    if (SIGNED(ctx->r14) < 0) {
        // 0x801360CC: nop
    
            goto L_801360B8;
    }
    // 0x801360CC: nop

L_801360D0:
    // 0x801360D0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x801360D4: jal         0x80018948
    // 0x801360D8: sb          $t6, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r14;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x801360D8: sb          $t6, 0x38($s1)
    MEM_B(0X38, ctx->r17) = ctx->r14;
    after_1:
    // 0x801360DC: lbu         $t7, 0x13($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X13);
    // 0x801360E0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x801360E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801360E8: nop

    // 0x801360EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801360F0: div.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f28.fl);
    // 0x801360F4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801360F8: nop

    // 0x801360FC: bc1fl       L_80136154
    if (!c1cs) {
        // 0x80136100: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80136154;
    }
    goto skip_35;
    // 0x80136100: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_35:
    // 0x80136104: lw          $t9, 0x48($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X48);
    // 0x80136108: sll         $t1, $t9, 10
    ctx->r9 = S32(ctx->r25 << 10);
    // 0x8013610C: bltz        $t1, L_80136148
    if (SIGNED(ctx->r9) < 0) {
        // 0x80136110: nop
    
            goto L_80136148;
    }
    // 0x80136110: nop

    // 0x80136114: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x80136118: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8013611C: beql        $v0, $fp, L_80136140
    if (ctx->r2 == ctx->r30) {
        // 0x80136120: lbu         $t3, 0x49($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X49);
            goto L_80136140;
    }
    goto skip_36;
    // 0x80136120: lbu         $t3, 0x49($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X49);
    skip_36:
    // 0x80136124: beq         $v0, $at, L_8013613C
    if (ctx->r2 == ctx->r1) {
        // 0x80136128: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8013613C;
    }
    // 0x80136128: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8013612C: beq         $v0, $at, L_8013613C
    if (ctx->r2 == ctx->r1) {
        // 0x80136130: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8013613C;
    }
    // 0x80136130: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80136134: bne         $v0, $at, L_80136148
    if (ctx->r2 != ctx->r1) {
        // 0x80136138: nop
    
            goto L_80136148;
    }
    // 0x80136138: nop

L_8013613C:
    // 0x8013613C: lbu         $t3, 0x49($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X49);
L_80136140:
    // 0x80136140: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80136144: sb          $t4, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r12;
L_80136148:
    // 0x80136148: b           L_80136174
    // 0x8013614C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136174;
    // 0x8013614C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136150:
    // 0x80136150: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
L_80136154:
    // 0x80136154: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80136158: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8013615C: bnel        $at, $zero, L_80135F7C
    if (ctx->r1 != 0) {
        // 0x80136160: lw          $t2, 0x24($s4)
        ctx->r10 = MEM_W(ctx->r20, 0X24);
            goto L_80135F7C;
    }
    goto skip_37;
    // 0x80136160: lw          $t2, 0x24($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X24);
    skip_37:
L_80136164:
    // 0x80136164: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
L_80136168:
    // 0x80136168: bnel        $s7, $zero, L_80135F00
    if (ctx->r23 != 0) {
        // 0x8013616C: lw          $s4, 0x84($s7)
        ctx->r20 = MEM_W(ctx->r23, 0X84);
            goto L_80135F00;
    }
    goto skip_38;
    // 0x8013616C: lw          $s4, 0x84($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X84);
    skip_38:
L_80136170:
    // 0x80136170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136174:
    // 0x80136174: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80136178: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013617C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80136180: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80136184: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80136188: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8013618C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80136190: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80136194: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80136198: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8013619C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801361A0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801361A4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801361A8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801361AC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x801361B0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x801361B4: jr          $ra
    // 0x801361B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801361B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void itBombHeiThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017756C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177574: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80177578: jal         0x80173E58
    // 0x8017757C: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    itMapCheckMapProcAll(rdram, ctx);
        goto after_0;
    // 0x8017757C: addiu       $a1, $a1, 0x7B78
    ctx->r5 = ADD32(ctx->r5, 0X7B78);
    after_0:
    // 0x80177580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177588: jr          $ra
    // 0x8017758C: nop

    return;
    // 0x8017758C: nop

;}
RECOMP_FUNC void ftMarioSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155E48: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80155E4C: jal         0x800D9480
    // 0x80155E50: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155E50: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    after_0:
    // 0x80155E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155E5C: jr          $ra
    // 0x80155E60: nop

    return;
    // 0x80155E60: nop

;}

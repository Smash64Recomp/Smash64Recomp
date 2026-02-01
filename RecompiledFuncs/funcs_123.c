#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syMatrixRotPyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD4C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CD50: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CD54: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001CD58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CD5C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001CD60: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CD64: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CD68: jal         0x8001CC80
    // 0x8001CD6C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syMatrixRotPyRF(rdram, ctx);
        goto after_0;
    // 0x8001CD6C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8001CD70: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001CD74: jal         0x80019EA0
    // 0x8001CD78: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CD78: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001CD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CD80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001CD84: jr          $ra
    // 0x8001CD88: nop

    return;
    // 0x8001CD88: nop

;}
RECOMP_FUNC void ftHammerGetStatUpdateFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F385C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3864: jal         0x800F37FC
    // 0x800F3868: nop

    ftHammerCheckMotionWaitOrWalk(rdram, ctx);
        goto after_0;
    // 0x800F3868: nop

    after_0:
    // 0x800F386C: beq         $v0, $zero, L_800F387C
    if (ctx->r2 == 0) {
        // 0x800F3870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F387C;
    }
    // 0x800F3870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3874: b           L_800F3880
    // 0x800F3878: addiu       $v1, $zero, 0x40E3
    ctx->r3 = ADD32(0, 0X40E3);
        goto L_800F3880;
    // 0x800F3878: addiu       $v1, $zero, 0x40E3
    ctx->r3 = ADD32(0, 0X40E3);
L_800F387C:
    // 0x800F387C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F3880:
    // 0x800F3880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F3884: jr          $ra
    // 0x800F3888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F3888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnCharactersFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void mnScreenAdjustMakeFrameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131E78: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80131E7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131E80: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80131E84: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80131E88: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131E8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80131E90: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131E94: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131E98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131E9C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80131EA0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80131EA4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131EA8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131EAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131EB0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131EB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131EB8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131EBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131EC0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131EC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131ECC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131ED0: jal         0x8000B93C
    // 0x80131ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131ED8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131EDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131EE0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131EE4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131EEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131EF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131EF4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131EF8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131EFC: jal         0x80007080
    // 0x80131F00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131F00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131F04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F08: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80131F0C: jr          $ra
    // 0x80131F10: nop

    return;
    // 0x80131F10: nop

;}
RECOMP_FUNC void ftParamSetPlayerTagWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E7F80: jr          $ra
    // 0x800E7F84: sw          $a1, 0x174($v0)
    MEM_W(0X174, ctx->r2) = ctx->r5;
    return;
    // 0x800E7F84: sw          $a1, 0x174($v0)
    MEM_W(0X174, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void ftLinkSpecialAirNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016379C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801637A0: jal         0x80163708
    // 0x801637A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftLinkSpecialNMakeBoomerang(rdram, ctx);
        goto after_0;
    // 0x801637A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801637A8: jal         0x800D94E8
    // 0x801637AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x801637AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801637B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801637B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801637B8: jr          $ra
    // 0x801637BC: nop

    return;
    // 0x801637BC: nop

;}
RECOMP_FUNC void efGroundSetStepPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801161A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801161A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801161A8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801161AC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x801161B0: bne         $t6, $at, L_801161CC
    if (ctx->r14 != ctx->r1) {
        // 0x801161B4: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_801161CC;
    }
    // 0x801161B4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801161B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801161BC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801161C0: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x801161C4: b           L_801161E8
    // 0x801161C8: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_801161E8;
    // 0x801161C8: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
L_801161CC:
    // 0x801161CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801161D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801161D4: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x801161D8: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801161DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801161E0: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x801161E4: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
L_801161E8:
    // 0x801161E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801161EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801161F0: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801161F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801161F8: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801161FC: jr          $ra
    // 0x80116200: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80116200: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void mnMessageFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013223C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132240: addiu       $v0, $v0, 0x2664
    ctx->r2 = ADD32(ctx->r2, 0X2664);
    // 0x80132244: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013224C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132250: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132254: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x80132258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013225C: bne         $at, $zero, L_801322C4
    if (ctx->r1 != 0) {
        // 0x80132260: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801322C4;
    }
    // 0x80132260: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132264: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132268: addiu       $v1, $v1, 0x2660
    ctx->r3 = ADD32(ctx->r3, 0X2660);
    // 0x8013226C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132270: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80132274: beq         $v0, $zero, L_80132280
    if (ctx->r2 == 0) {
        // 0x80132278: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132280;
    }
    // 0x80132278: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013227C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80132280:
    // 0x80132280: jal         0x80390A04
    // 0x80132284: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132284: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x80132288: beq         $v0, $zero, L_801322A4
    if (ctx->r2 == 0) {
        // 0x8013228C: addiu       $a0, $zero, -0x1E
        ctx->r4 = ADD32(0, -0X1E);
            goto L_801322A4;
    }
    // 0x8013228C: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80132290: jal         0x80390AC0
    // 0x80132294: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132294: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x80132298: beq         $v0, $zero, L_801322A4
    if (ctx->r2 == 0) {
        // 0x8013229C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801322A4;
    }
    // 0x8013229C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322A0: sw          $zero, 0x2660($at)
    MEM_W(0X2660, ctx->r1) = 0;
L_801322A4:
    // 0x801322A4: jal         0x8039076C
    // 0x801322A8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x801322A8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x801322AC: beql        $v0, $zero, L_801322C8
    if (ctx->r2 == 0) {
        // 0x801322B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801322C8;
    }
    goto skip_0;
    // 0x801322B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801322B4: jal         0x801321A4
    // 0x801322B8: nop

    mnMessageApplyUnlock(rdram, ctx);
        goto after_3;
    // 0x801322B8: nop

    after_3:
    // 0x801322BC: jal         0x80005C74
    // 0x801322C0: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x801322C0: nop

    after_4:
L_801322C4:
    // 0x801322C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801322C8:
    // 0x801322C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801322CC: jr          $ra
    // 0x801322D0: nop

    return;
    // 0x801322D0: nop

;}
RECOMP_FUNC void ftCommonEntrySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013D938: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D93C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8013D940: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8013D944: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013D948: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013D94C: jal         0x800E6F24
    // 0x8013D950: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D950: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013D954: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013D958: lbu         $t0, 0x18E($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013D95C: lbu         $t7, 0x18D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18D);
    // 0x8013D960: lbu         $t3, 0x191($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X191);
    // 0x8013D964: ori         $t6, $t0, 0x80
    ctx->r14 = ctx->r8 | 0X80;
    // 0x8013D968: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013D96C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8013D970: sb          $t6, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r14;
    // 0x8013D974: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x8013D978: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    // 0x8013D97C: sb          $t4, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r12;
    // 0x8013D980: sb          $t7, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r15;
    // 0x8013D984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D988: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013D98C: jr          $ra
    // 0x8013D990: nop

    return;
    // 0x8013D990: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFCheckInterruptThrowFCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DFA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DFB0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014DFB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014DFB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014DFBC: lhu         $t6, 0x1B4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1B4);
    // 0x8014DFC0: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
    // 0x8014DFC4: lhu         $t9, 0x1BE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1BE);
    // 0x8014DFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014DFCC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8014DFD0: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x8014DFD4: beq         $t0, $zero, L_8014E034
    if (ctx->r8 == 0) {
        // 0x8014DFD8: nop
    
            goto L_8014E034;
    }
    // 0x8014DFD8: nop

    // 0x8014DFDC: lb          $v0, 0x1C2($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1C2);
    // 0x8014DFE0: bgez        $v0, L_8014DFF0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8014DFE4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8014DFF0;
    }
    // 0x8014DFE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8014DFE8: b           L_8014DFF0
    // 0x8014DFEC: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_8014DFF0;
    // 0x8014DFEC: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8014DFF0:
    // 0x8014DFF0: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x8014DFF4: bne         $at, $zero, L_8014E024
    if (ctx->r1 != 0) {
        // 0x8014DFF8: nop
    
            goto L_8014E024;
    }
    // 0x8014DFF8: nop

    // 0x8014DFFC: lw          $t1, 0x44($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X44);
    // 0x8014E000: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014E004: mflo        $t2
    ctx->r10 = lo;
    // 0x8014E008: bgez        $t2, L_8014E024
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014E00C: nop
    
            goto L_8014E024;
    }
    // 0x8014E00C: nop

    // 0x8014E010: lw          $t3, 0x14C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X14C);
    // 0x8014E014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014E018: bne         $t3, $at, L_8014E024
    if (ctx->r11 != ctx->r1) {
        // 0x8014E01C: nop
    
            goto L_8014E024;
    }
    // 0x8014E01C: nop

    // 0x8014E020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8014E024:
    // 0x8014E024: jal         0x8014DF14
    // 0x8014E028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftDonkeyThrowFFSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8014E02C: b           L_8014E034
    // 0x8014E030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014E034;
    // 0x8014E030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E034:
    // 0x8014E034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014E038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E03C: jr          $ra
    // 0x8014E040: nop

    return;
    // 0x8014E040: nop

;}
RECOMP_FUNC void func_ovl8_803854C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803854C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803854C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803854CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803854D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803854D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803854D8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803854DC: bne         $a0, $zero, L_803854F4
    if (ctx->r4 != 0) {
        // 0x803854E0: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_803854F4;
    }
    // 0x803854E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803854E4: jal         0x803717A0
    // 0x803854E8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803854E8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x803854EC: beq         $v0, $zero, L_80385584
    if (ctx->r2 == 0) {
        // 0x803854F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385584;
    }
    // 0x803854F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803854F4:
    // 0x803854F4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x803854F8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x803854FC: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x80385500: bnel        $t6, $zero, L_80385524
    if (ctx->r14 != 0) {
        // 0x80385504: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80385524;
    }
    goto skip_0;
    // 0x80385504: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80385508: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8038550C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80385510: jal         0x803717E0
    // 0x80385514: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80385514: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80385518: jal         0x8037C2D0
    // 0x8038551C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8038551C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80385520: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80385524:
    // 0x80385524: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80385528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038552C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80385530: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80385534: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80385538: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8038553C: jal         0x803847A0
    // 0x80385540: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_ovl8_803847A0(rdram, ctx);
        goto after_3;
    // 0x80385540: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_3:
    // 0x80385544: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80385548: addiu       $t9, $t9, -0x26A0
    ctx->r25 = ADD32(ctx->r25, -0X26A0);
    // 0x8038554C: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x80385550: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80385554: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80385558: addiu       $t0, $t0, -0x2580
    ctx->r8 = ADD32(ctx->r8, -0X2580);
    // 0x8038555C: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x80385560: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80385564: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80385568: addiu       $t2, $t2, -0x2428
    ctx->r10 = ADD32(ctx->r10, -0X2428);
    // 0x8038556C: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80385570: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80385574: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80385578: lh          $t4, 0x10($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X10);
    // 0x8038557C: jalr        $t9
    // 0x80385580: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80385580: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_4:
L_80385584:
    // 0x80385584: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80385588: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8038558C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80385590: jr          $ra
    // 0x80385594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80385594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPikachuSpecialAirLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151FFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152008: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015200C: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80152010: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80152014: jal         0x800E6F24
    // 0x80152018: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152018: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015201C: jal         0x800E0830
    // 0x80152020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80152020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80152024: jal         0x80151FA8
    // 0x80152028: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialLwStartInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80152028: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015202C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152030: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152034: jr          $ra
    // 0x80152038: nop

    return;
    // 0x80152038: nop

;}
RECOMP_FUNC void func_ovl28_80135D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D7C: jr          $ra
    // 0x80135D80: nop

    return;
    // 0x80135D80: nop

;}
RECOMP_FUNC void func_ovl8_80371E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E04: jr          $ra
    // 0x80371E08: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    return;
    // 0x80371E08: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void ftFoxSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BB50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015BB54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BB58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BB5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015BB60: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8015BB64: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x8015BB68: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8015BB6C: beql        $t6, $zero, L_8015BBAC
    if (ctx->r14 == 0) {
        // 0x8015BB70: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8015BBAC;
    }
    goto skip_0;
    // 0x8015BB70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8015BB74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015BB78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015BB7C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015BB80: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8015BB84: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8015BB88: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8015BB8C: lw          $a0, 0x92C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X92C);
    // 0x8015BB90: jal         0x800EDF24
    // 0x8015BB94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015BB94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015BB98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015BB9C: jal         0x80168A74
    // 0x8015BBA0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpFoxBlasterMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8015BBA0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8015BBA4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8015BBA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8015BBAC:
    // 0x8015BBAC: lwc1        $f8, 0x78($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X78);
    // 0x8015BBB0: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8015BBB4: nop

    // 0x8015BBB8: bc1fl       L_8015BBCC
    if (!c1cs) {
        // 0x8015BBBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015BBCC;
    }
    goto skip_1;
    // 0x8015BBBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015BBC0: jal         0x800DEE54
    // 0x8015BBC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x8015BBC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8015BBC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015BBCC:
    // 0x8015BBCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015BBD0: jr          $ra
    // 0x8015BBD4: nop

    return;
    // 0x8015BBD4: nop

;}
RECOMP_FUNC void ftBossGootsubusuDownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159E50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80159E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159E58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159E5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159E60: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80159E64: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159E68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80159E6C: jal         0x800E6F24
    // 0x80159E70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159E70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80159E74: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80159E78: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80159E7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159E80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80159E84: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x80159E88: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x80159E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159E94: jr          $ra
    // 0x80159E98: nop

    return;
    // 0x80159E98: nop

;}
RECOMP_FUNC void itMLuckyFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801810E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801810E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801810E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801810EC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801810F0: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x801810F4: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801810F8: jal         0x80173F78
    // 0x801810FC: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801810FC: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80181100: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181104: addiu       $a1, $a1, -0x501C
    ctx->r5 = ADD32(ctx->r5, -0X501C);
    // 0x80181108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018110C: jal         0x80172EC8
    // 0x80181110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80181110: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80181114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018111C: jr          $ra
    // 0x80181120: nop

    return;
    // 0x80181120: nop

;}
RECOMP_FUNC void efManagerStockStealEndMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801039B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801039B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801039BC: jal         0x80103918
    // 0x801039C0: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    efManagerStockCommonMakeEffectID(rdram, ctx);
        goto after_0;
    // 0x801039C0: addiu       $a2, $zero, 0x76
    ctx->r6 = ADD32(0, 0X76);
    after_0:
    // 0x801039C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801039C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801039CC: jr          $ra
    // 0x801039D0: nop

    return;
    // 0x801039D0: nop

;}
RECOMP_FUNC void ftCommonDownStandCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801445D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801445DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801445E0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801445E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801445E8: lb          $t6, 0x1C3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C3);
    // 0x801445EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801445F0: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x801445F4: bnel        $at, $zero, L_8014462C
    if (ctx->r1 != 0) {
        // 0x801445F8: lhu         $t7, 0x1BE($a1)
        ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
            goto L_8014462C;
    }
    goto skip_0;
    // 0x801445F8: lhu         $t7, 0x1BE($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
    skip_0:
    // 0x801445FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80144600: jal         0x800E8000
    // 0x80144604: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x80144604: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80144608: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014460C: lwc1        $f4, -0x3EA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EA0);
    // 0x80144610: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80144614: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80144618: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8014461C: nop

    // 0x80144620: bc1t        L_80144640
    if (c1cs) {
        // 0x80144624: nop
    
            goto L_80144640;
    }
    // 0x80144624: nop

    // 0x80144628: lhu         $t7, 0x1BE($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
L_8014462C:
    // 0x8014462C: lhu         $t8, 0x1B8($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B8);
    // 0x80144630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80144634: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80144638: beq         $t9, $zero, L_80144650
    if (ctx->r25 == 0) {
        // 0x8014463C: nop
    
            goto L_80144650;
    }
    // 0x8014463C: nop

L_80144640:
    // 0x80144640: jal         0x80144580
    // 0x80144644: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonDownStandSetStatus(rdram, ctx);
        goto after_1;
    // 0x80144644: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80144648: b           L_80144650
    // 0x8014464C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80144650;
    // 0x8014464C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80144650:
    // 0x80144650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80144658: jr          $ra
    // 0x8014465C: nop

    return;
    // 0x8014465C: nop

;}
RECOMP_FUNC void func_ovl8_803718C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803718C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803718C8: beq         $a0, $zero, L_803718EC
    if (ctx->r4 == 0) {
        // 0x803718CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_803718EC;
    }
    // 0x803718CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803718D0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803718D4: addiu       $t6, $t6, -0x7680
    ctx->r14 = ADD32(ctx->r14, -0X7680);
    // 0x803718D8: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x803718DC: beq         $t7, $zero, L_803718EC
    if (ctx->r15 == 0) {
        // 0x803718E0: sw          $t6, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->r14;
            goto L_803718EC;
    }
    // 0x803718E0: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    // 0x803718E4: jal         0x803717C0
    // 0x803718E8: nop

    func_ovl8_803717C0(rdram, ctx);
        goto after_0;
    // 0x803718E8: nop

    after_0:
L_803718EC:
    // 0x803718EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803718F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803718F4: jr          $ra
    // 0x803718F8: nop

    return;
    // 0x803718F8: nop

;}
RECOMP_FUNC void mpCommonCheckFighterPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE75C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DE764: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE768: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE76C: sw          $a1, 0xE20($at)
    MEM_W(0XE20, ctx->r1) = ctx->r5;
    // 0x800DE770: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE774: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE778: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE77C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800DE780: jal         0x800DA034
    // 0x800DE784: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE784: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE790: jr          $ra
    // 0x800DE794: nop

    return;
    // 0x800DE794: nop

;}
RECOMP_FUNC void wpSamusChargeShotProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168BFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168C04: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80168C08: lw          $t6, 0x29C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X29C);
    // 0x80168C0C: bnel        $t6, $zero, L_80168C8C
    if (ctx->r14 != 0) {
        // 0x80168C10: lw          $t4, 0x18($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X18);
            goto L_80168C8C;
    }
    goto skip_0;
    // 0x80168C10: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    skip_0:
    // 0x80168C14: lw          $t7, 0x2A4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2A4);
    // 0x80168C18: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80168C1C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80168C20: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80168C24: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80168C28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80168C2C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80168C30: lwc1        $f4, -0x70F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X70F0);
    // 0x80168C34: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80168C38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80168C3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80168C40: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80168C44: swc1        $f0, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f0.u32l;
    // 0x80168C48: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80168C4C: swc1        $f0, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f0.u32l;
    // 0x80168C50: lw          $t1, 0x2A0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X2A0);
    // 0x80168C54: beql        $t1, $zero, L_80168C8C
    if (ctx->r9 == 0) {
        // 0x80168C58: lw          $t4, 0x18($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X18);
            goto L_80168C8C;
    }
    goto skip_1;
    // 0x80168C58: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    skip_1:
    // 0x80168C5C: sw          $t2, 0x29C($a1)
    MEM_W(0X29C, ctx->r5) = ctx->r10;
    // 0x80168C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80168C64: jal         0x80168B00
    // 0x80168C68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    wpSamusChargeShotLaunch(rdram, ctx);
        goto after_0;
    // 0x80168C68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168C6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80168C70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80168C74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80168C78: jal         0x80165F60
    // 0x80168C7C: sw          $t3, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r11;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_1;
    // 0x80168C7C: sw          $t3, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r11;
    after_1:
    // 0x80168C80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80168C84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80168C88: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
L_80168C8C:
    // 0x80168C8C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80168C90: lwc1        $f8, -0x3550($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3550);
    // 0x80168C94: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80168C98: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80168C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168CA0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80168CA4: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80168CA8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80168CAC: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80168CB0: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x80168CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168CB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80168CBC: jr          $ra
    // 0x80168CC0: nop

    return;
    // 0x80168CC0: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015FC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FC38: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015FC3C: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x8015FC40: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x8015FC44: bltzl       $t8, L_8015FC84
    if (SIGNED(ctx->r24) < 0) {
        // 0x8015FC48: lw          $t3, 0x184($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X184);
            goto L_8015FC84;
    }
    goto skip_0;
    // 0x8015FC48: lw          $t3, 0x184($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X184);
    skip_0:
    // 0x8015FC4C: lw          $t9, 0x184($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X184);
    // 0x8015FC50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015FC54: bnel        $t9, $at, L_8015FCA4
    if (ctx->r25 != ctx->r1) {
        // 0x8015FC58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015FCA4;
    }
    goto skip_1;
    // 0x8015FC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015FC5C: jal         0x80101ED8
    // 0x8015FC60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerCaptainFalconKickMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8015FC60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015FC64: beq         $v0, $zero, L_8015FC78
    if (ctx->r2 == 0) {
        // 0x8015FC68: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8015FC78;
    }
    // 0x8015FC68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FC6C: lbu         $t1, 0x18F($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X18F);
    // 0x8015FC70: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8015FC74: sb          $t2, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r10;
L_8015FC78:
    // 0x8015FC78: b           L_8015FCA0
    // 0x8015FC7C: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
        goto L_8015FCA0;
    // 0x8015FC7C: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
    // 0x8015FC80: lw          $t3, 0x184($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X184);
L_8015FC84:
    // 0x8015FC84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015FC88: bnel        $t3, $at, L_8015FCA4
    if (ctx->r11 != ctx->r1) {
        // 0x8015FC8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015FCA4;
    }
    goto skip_2;
    // 0x8015FC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8015FC90: jal         0x800E9C3C
    // 0x8015FC94: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftParamProcStopEffect(rdram, ctx);
        goto after_1;
    // 0x8015FC94: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8015FC98: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FC9C: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
L_8015FCA0:
    // 0x8015FCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FCA4:
    // 0x8015FCA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015FCA8: jr          $ra
    // 0x8015FCAC: nop

    return;
    // 0x8015FCAC: nop

;}
RECOMP_FUNC void ftKirbySpecialNDamageCheckLoseCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016364C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163650: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163654: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80163658: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8016365C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80163660: beql        $a1, $v1, L_80163674
    if (ctx->r5 == ctx->r3) {
        // 0x80163664: lw          $t6, 0xADC($v0)
        ctx->r14 = MEM_W(ctx->r2, 0XADC);
            goto L_80163674;
    }
    goto skip_0;
    // 0x80163664: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x80163668: bnel        $v1, $at, L_801636B8
    if (ctx->r3 != ctx->r1) {
        // 0x8016366C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801636B8;
    }
    goto skip_1;
    // 0x8016366C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80163670: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
L_80163674:
    // 0x80163674: beql        $a1, $t6, L_801636B8
    if (ctx->r5 == ctx->r14) {
        // 0x80163678: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801636B8;
    }
    goto skip_2;
    // 0x80163678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8016367C: lw          $t7, 0xAF4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAF4);
    // 0x80163680: bnel        $t7, $zero, L_801636B8
    if (ctx->r15 != 0) {
        // 0x80163684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801636B8;
    }
    goto skip_3;
    // 0x80163684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80163688: jal         0x80018948
    // 0x8016368C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8016368C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163690: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80163694: lwc1        $f4, -0x3618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3618);
    // 0x80163698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016369C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801636A0: nop

    // 0x801636A4: bc1fl       L_801636B8
    if (!c1cs) {
        // 0x801636A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801636B8;
    }
    goto skip_4;
    // 0x801636A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801636AC: jal         0x801635EC
    // 0x801636B0: nop

    ftKirbySpecialNLoseCopy(rdram, ctx);
        goto after_1;
    // 0x801636B0: nop

    after_1:
    // 0x801636B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801636B8:
    // 0x801636B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801636BC: jr          $ra
    // 0x801636C0: nop

    return;
    // 0x801636C0: nop

;}
RECOMP_FUNC void scVSBattleSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E330: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E334: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018E338: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018E33C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E340: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E348: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018E34C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018E350: addiu       $t8, $t8, -0x1B80
    ctx->r24 = ADD32(ctx->r24, -0X1B80);
    // 0x8018E354: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018E358: addiu       $t0, $t0, -0x1860
    ctx->r8 = ADD32(ctx->r8, -0X1860);
    // 0x8018E35C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018E360: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018E364: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018E368: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018E36C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018E370: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018E374: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018E378: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018E37C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018E380: jal         0x800CDF78
    // 0x8018E384: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018E384: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018E388: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E38C: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E390: jal         0x800CDEEC
    // 0x8018E394: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018E394: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8018E398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E39C: jal         0x80004980
    // 0x8018E3A0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018E3A0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018E3A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018E3A8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E3AC: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018E3B0: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018E3B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018E3B8: jal         0x800CDE04
    // 0x8018E3BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018E3BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018E3C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E3C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018E3C8: jr          $ra
    // 0x8018E3CC: nop

    return;
    // 0x8018E3CC: nop

;}
RECOMP_FUNC void gmCameraMakeBattleCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DB00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010DB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DB08: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8010DB0C: addiu       $a2, $a2, -0x3134
    ctx->r6 = ADD32(ctx->r6, -0X3134);
    // 0x8010DB10: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8010DB14: jal         0x8010D7E8
    // 0x8010DB18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gmCameraMakeDefaultCamera(rdram, ctx);
        goto after_0;
    // 0x8010DB18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8010DB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010DB24: jr          $ra
    // 0x8010DB28: nop

    return;
    // 0x8010DB28: nop

;}
RECOMP_FUNC void syAudioStopBGMAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80020A78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80020A7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80020A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80020A84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020A88: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80020A8C:
    // 0x80020A8C: jal         0x80020B08
    // 0x80020A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syAudioStopBGM(rdram, ctx);
        goto after_0;
    // 0x80020A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80020A94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020A98: bne         $s0, $s1, L_80020A8C
    if (ctx->r16 != ctx->r17) {
        // 0x80020A9C: nop
    
            goto L_80020A8C;
    }
    // 0x80020A9C: nop

    // 0x80020AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80020AA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80020AA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80020AAC: jr          $ra
    // 0x80020AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80020AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itBoxWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017967C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80179680: jal         0x801735A0
    // 0x80179684: addiu       $a1, $a1, -0x685C
    ctx->r5 = ADD32(ctx->r5, -0X685C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80179684: addiu       $a1, $a1, -0x685C
    ctx->r5 = ADD32(ctx->r5, -0X685C);
    after_0:
    // 0x80179688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017968C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179694: jr          $ra
    // 0x80179698: nop

    return;
    // 0x80179698: nop

;}
RECOMP_FUNC void mnPlayersVSSelectFighterPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C74: addiu       $v1, $zero, 0xBC
    ctx->r3 = ADD32(0, 0XBC);
    // 0x80131C78: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131C7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131C80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131C84: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x80131C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80131C90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80131C94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80131C98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131C9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80131CA0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80131CA4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80131CA8: beq         $a1, $at, L_80131D1C
    if (ctx->r5 == ctx->r1) {
        // 0x80131CAC: lw          $s1, 0x80($t8)
        ctx->r17 = MEM_W(ctx->r24, 0X80);
            goto L_80131D1C;
    }
    // 0x80131CAC: lw          $s1, 0x80($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X80);
    // 0x80131CB0: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131CB4: mflo        $t0
    ctx->r8 = lo;
    // 0x80131CB8: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // 0x80131CBC: jal         0x800EC0EC
    // 0x80131CC0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131CC0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x80131CC4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80131CC8: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80131CCC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80131CD0: jal         0x80134674
    // 0x80131CD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnPlayersVSCheckCostumeUsed(rdram, ctx);
        goto after_1;
    // 0x80131CD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80131CD8: beq         $v0, $zero, L_80131CF0
    if (ctx->r2 == 0) {
        // 0x80131CDC: nop
    
            goto L_80131CF0;
    }
    // 0x80131CDC: nop

    // 0x80131CE0: jal         0x800269C0
    // 0x80131CE4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80131CE4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_2:
    // 0x80131CE8: b           L_80131DB4
    // 0x80131CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80131DB4;
    // 0x80131CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80131CF0:
    // 0x80131CF0: jal         0x80131B78
    // 0x80131CF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_3;
    // 0x80131CF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80131CF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80131CFC: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80131D00: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80131D04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80131D08: jal         0x800E9248
    // 0x80131D0C: sw          $a1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r5;
    ftParamInitAllParts(rdram, ctx);
        goto after_4;
    // 0x80131D0C: sw          $a1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r5;
    after_4:
    // 0x80131D10: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80131D14: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x80131D18: addiu       $v1, $zero, 0xBC
    ctx->r3 = ADD32(0, 0XBC);
L_80131D1C:
    // 0x80131D1C: multu       $s1, $v1
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131D20: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131D24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80131D28: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80131D2C: mflo        $t1
    ctx->r9 = lo;
    // 0x80131D30: addu        $s0, $v0, $t1
    ctx->r16 = ADD32(ctx->r2, ctx->r9);
    // 0x80131D34: jal         0x80137390
    // 0x80131D38: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    mnPlayersVSUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_5;
    // 0x80131D38: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    after_5:
    // 0x80131D3C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80131D40: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80131D44: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80131D48: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80131D4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80131D50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131D54: sw          $t4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r12;
    // 0x80131D58: jal         0x80134D54
    // 0x80131D5C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_6;
    // 0x80131D5C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_6:
    // 0x80131D60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80131D64: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80131D68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131D6C: sw          $t5, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->r13;
    // 0x80131D70: sw          $t7, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r15;
    // 0x80131D74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80131D78: jal         0x801367F0
    // 0x80131D7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSAnnounceFighter(rdram, ctx);
        goto after_7;
    // 0x80131D7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80131D80: jal         0x80137148
    // 0x80131D84: nop

    mnPlayersVSCheckHandicap(rdram, ctx);
        goto after_8;
    // 0x80131D84: nop

    after_8:
    // 0x80131D88: bne         $v0, $zero, L_80131DA0
    if (ctx->r2 != 0) {
        // 0x80131D8C: nop
    
            goto L_80131DA0;
    }
    // 0x80131D8C: nop

    // 0x80131D90: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x80131D94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131D98: bne         $t8, $at, L_80131DA8
    if (ctx->r24 != ctx->r1) {
        // 0x80131D9C: nop
    
            goto L_80131DA8;
    }
    // 0x80131D9C: nop

L_80131DA0:
    // 0x80131DA0: jal         0x80137004
    // 0x80131DA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_9;
    // 0x80131DA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_80131DA8:
    // 0x80131DA8: jal         0x8013647C
    // 0x80131DAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSMakePortraitFlash(rdram, ctx);
        goto after_10;
    // 0x80131DAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80131DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80131DB4:
    // 0x80131DB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80131DB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80131DBC: jr          $ra
    // 0x80131DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonWalkProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E54C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E550: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013E554: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8013E558: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x8013E55C: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x8013E560: jal         0x800D8A70
    // 0x8013E564: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    ftPhysicsSetGroundVelAbsStickRange(rdram, ctx);
        goto after_0;
    // 0x8013E564: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    after_0:
    // 0x8013E568: jal         0x800D87D0
    // 0x8013E56C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8013E56C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013E570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E578: jr          $ra
    // 0x8013E57C: nop

    return;
    // 0x8013E57C: nop

;}
RECOMP_FUNC void func_ovl8_803717E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803717E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803717E4: bne         $a0, $zero, L_803717FC
    if (ctx->r4 != 0) {
        // 0x803717E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_803717FC;
    }
    // 0x803717E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803717EC: jal         0x803717A0
    // 0x803717F0: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803717F0: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x803717F4: beq         $v0, $zero, L_80371814
    if (ctx->r2 == 0) {
        // 0x803717F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80371814;
    }
    // 0x803717F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_803717FC:
    // 0x803717FC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80371800: addiu       $t6, $t6, -0x7680
    ctx->r14 = ADD32(ctx->r14, -0X7680);
    // 0x80371804: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    // 0x80371808: jal         0x80371EA0
    // 0x8037180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl8_80371EA0(rdram, ctx);
        goto after_1;
    // 0x8037180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80371810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80371814:
    // 0x80371814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037181C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80371820: jr          $ra
    // 0x80371824: nop

    return;
    // 0x80371824: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNThrowSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162D38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162D3C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162D40: jal         0x800DEE98
    // 0x80162D44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162D44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162D48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162D4C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162D50: addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // 0x80162D54: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162D58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162D5C: jal         0x800E6F24
    // 0x80162D60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162D60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162D64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162D68: jal         0x800E8098
    // 0x80162D6C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162D6C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162D74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162D78: jr          $ra
    // 0x80162D7C: nop

    return;
    // 0x80162D7C: nop

;}
RECOMP_FUNC void syControllerUpdateRumbleEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800043C4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800043C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800043CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800043D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800043D4: addiu       $v0, $v0, 0x5268
    ctx->r2 = ADD32(ctx->r2, 0X5268);
    // 0x800043D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800043DC:
    // 0x800043DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800043E0: beql        $t6, $zero, L_800043FC
    if (ctx->r14 == 0) {
        // 0x800043E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800043FC;
    }
    goto skip_0;
    // 0x800043E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
    // 0x800043E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800043EC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800043F0: bne         $at, $zero, L_800043DC
    if (ctx->r1 != 0) {
        // 0x800043F4: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_800043DC;
    }
    // 0x800043F4: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x800043F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800043FC:
    // 0x800043FC: bne         $v1, $at, L_80004438
    if (ctx->r3 != ctx->r1) {
        // 0x80004400: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_80004438;
    }
    // 0x80004400: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80004404: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004408: addiu       $a0, $a0, 0x5160
    ctx->r4 = ADD32(ctx->r4, 0X5160);
    // 0x8000440C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80004410: jal         0x80030210
    // 0x80004414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80004414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80004418: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000441C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004420: addiu       $t8, $t8, 0x5268
    ctx->r24 = ADD32(ctx->r24, 0X5268);
    // 0x80004424: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80004428: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8000442C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004430: b           L_80004440
    // 0x80004434: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
        goto L_80004440;
    // 0x80004434: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80004438:
    // 0x80004438: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000443C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80004440:
    // 0x80004440: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80004444: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80004448: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000444C: addiu       $a0, $a0, 0x5138
    ctx->r4 = ADD32(ctx->r4, 0X5138);
    // 0x80004450: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80004454: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004458: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x8000445C: jal         0x80030000
    // 0x80004460: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80004460: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    after_1:
    // 0x80004464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000446C: jr          $ra
    // 0x80004470: nop

    return;
    // 0x80004470: nop

;}
RECOMP_FUNC void func_ovl8_80379070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80379070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80379074: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80379078: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8037907C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80379080: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80379084: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80379088: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8037908C: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80379090: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80379094: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80379098: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8037909C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x803790A0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x803790A4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x803790A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803790AC: sltiu       $at, $a3, 0x4
    ctx->r1 = ctx->r7 < 0X4 ? 1 : 0;
    // 0x803790B0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x803790B4: beq         $at, $zero, L_80379870
    if (ctx->r1 == 0) {
        // 0x803790B8: lh          $t4, 0x2($a2)
        ctx->r12 = MEM_H(ctx->r6, 0X2);
            goto L_80379870;
    }
    // 0x803790B8: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x803790BC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x803790C0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803790C4: addu        $at, $at, $t6
    gpr jr_addend_803790CC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x803790C8: lw          $t6, -0x11D8($at)
    ctx->r14 = ADD32(ctx->r1, -0X11D8);
    // 0x803790CC: jr          $t6
    // 0x803790D0: nop

    switch (jr_addend_803790CC >> 2) {
        case 0: goto L_80379870; break;
        case 1: goto L_803790D4; break;
        case 2: goto L_80379330; break;
        case 3: goto L_803795D8; break;
        default: switch_error(__func__, 0x803790CC, 0x8038EE28);
    }
    // 0x803790D0: nop

L_803790D4:
    // 0x803790D4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x803790D8: lui         $ra, 0x8039
    ctx->r31 = S32(0X8039 << 16);
    // 0x803790DC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x803790E0: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
    // 0x803790E4: addiu       $ra, $ra, -0x609C
    ctx->r31 = ADD32(ctx->r31, -0X609C);
    // 0x803790E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x803790EC: blez        $v0, L_80379870
    if (SIGNED(ctx->r2) <= 0) {
        // 0x803790F0: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80379870;
    }
    // 0x803790F0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x803790F4: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x803790F8: addiu       $s3, $s3, -0x60A0
    ctx->r19 = ADD32(ctx->r19, -0X60A0);
    // 0x803790FC: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x80379100: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80379104: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80379108: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x8037910C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80379110:
    // 0x80379110: blez        $v1, L_80379308
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80379114: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80379308;
    }
    // 0x80379114: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80379118: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_8037911C:
    // 0x8037911C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80379120: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80379124: bne         $a0, $s4, L_8037915C
    if (ctx->r4 != ctx->r20) {
        // 0x80379128: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8037915C;
    }
    // 0x80379128: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8037912C: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x80379130: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80379134: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379138: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x8037913C: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379140: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80379144: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x80379148: mflo        $t9
    ctx->r25 = lo;
    // 0x8037914C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80379150: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80379154: b           L_80379248
    // 0x80379158: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
        goto L_80379248;
    // 0x80379158: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
L_8037915C:
    // 0x8037915C: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x80379160: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80379164: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80379168: beq         $t5, $zero, L_803791C8
    if (ctx->r13 == 0) {
        // 0x8037916C: nop
    
            goto L_803791C8;
    }
    // 0x8037916C: nop

    // 0x80379170: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379174: addu        $t9, $a3, $t3
    ctx->r25 = ADD32(ctx->r7, ctx->r11);
    // 0x80379178: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x8037917C: beq         $t6, $zero, L_803791A4
    if (ctx->r14 == 0) {
        // 0x80379180: nop
    
            goto L_803791A4;
    }
    // 0x80379180: nop

    // 0x80379184: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379188: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8037918C: mflo        $t8
    ctx->r24 = lo;
    // 0x80379190: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80379194: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x80379198: addu        $a1, $t6, $t3
    ctx->r5 = ADD32(ctx->r14, ctx->r11);
    // 0x8037919C: b           L_803791E8
    // 0x803791A0: lbu         $v1, -0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X4);
        goto L_803791E8;
    // 0x803791A0: lbu         $v1, -0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X4);
L_803791A4:
    // 0x803791A4: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803791A8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803791AC: mflo        $t8
    ctx->r24 = lo;
    // 0x803791B0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803791B4: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x803791B8: addu        $a1, $t6, $t3
    ctx->r5 = ADD32(ctx->r14, ctx->r11);
    // 0x803791BC: lbu         $t2, 0x4($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X4);
    // 0x803791C0: b           L_803791E8
    // 0x803791C4: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
        goto L_803791E8;
    // 0x803791C4: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
L_803791C8:
    // 0x803791C8: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803791CC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803791D0: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x803791D4: mflo        $t8
    ctx->r24 = lo;
    // 0x803791D8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x803791DC: addu        $t6, $t9, $a3
    ctx->r14 = ADD32(ctx->r25, ctx->r7);
    // 0x803791E0: addu        $a1, $t6, $t3
    ctx->r5 = ADD32(ctx->r14, ctx->r11);
    // 0x803791E4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
L_803791E8:
    // 0x803791E8: beq         $s5, $a0, L_80379210
    if (ctx->r21 == ctx->r4) {
        // 0x803791EC: andi        $t2, $v1, 0xFF
        ctx->r10 = ctx->r3 & 0XFF;
            goto L_80379210;
    }
    // 0x803791EC: andi        $t2, $v1, 0xFF
    ctx->r10 = ctx->r3 & 0XFF;
    // 0x803791F0: beq         $s6, $a0, L_80379224
    if (ctx->r22 == ctx->r4) {
        // 0x803791F4: nop
    
            goto L_80379224;
    }
    // 0x803791F4: nop

    // 0x803791F8: beql        $s7, $a0, L_80379238
    if (ctx->r23 == ctx->r4) {
        // 0x803791FC: or          $t2, $v1, $a2
        ctx->r10 = ctx->r3 | ctx->r6;
            goto L_80379238;
    }
    goto skip_0;
    // 0x803791FC: or          $t2, $v1, $a2
    ctx->r10 = ctx->r3 | ctx->r6;
    skip_0:
    // 0x80379200: beql        $fp, $a0, L_80379244
    if (ctx->r30 == ctx->r4) {
        // 0x80379204: xor         $t2, $v1, $a2
        ctx->r10 = ctx->r3 ^ ctx->r6;
            goto L_80379244;
    }
    goto skip_1;
    // 0x80379204: xor         $t2, $v1, $a2
    ctx->r10 = ctx->r3 ^ ctx->r6;
    skip_1:
    // 0x80379208: b           L_80379248
    // 0x8037920C: nop

        goto L_80379248;
    // 0x8037920C: nop

L_80379210:
    // 0x80379210: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x80379214: beq         $a2, $t7, L_80379248
    if (ctx->r6 == ctx->r15) {
        // 0x80379218: nop
    
            goto L_80379248;
    }
    // 0x80379218: nop

    // 0x8037921C: b           L_80379248
    // 0x80379220: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
        goto L_80379248;
    // 0x80379220: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
L_80379224:
    // 0x80379224: beq         $a2, $zero, L_80379248
    if (ctx->r6 == 0) {
        // 0x80379228: nop
    
            goto L_80379248;
    }
    // 0x80379228: nop

    // 0x8037922C: b           L_80379248
    // 0x80379230: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
        goto L_80379248;
    // 0x80379230: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x80379234: or          $t2, $v1, $a2
    ctx->r10 = ctx->r3 | ctx->r6;
L_80379238:
    // 0x80379238: b           L_80379248
    // 0x8037923C: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
        goto L_80379248;
    // 0x8037923C: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x80379240: xor         $t2, $v1, $a2
    ctx->r10 = ctx->r3 ^ ctx->r6;
L_80379244:
    // 0x80379244: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
L_80379248:
    // 0x80379248: beq         $t5, $zero, L_803792E4
    if (ctx->r13 == 0) {
        // 0x8037924C: addu        $t8, $a3, $t3
        ctx->r24 = ADD32(ctx->r7, ctx->r11);
            goto L_803792E4;
    }
    // 0x8037924C: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x80379250: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80379254: beql        $t9, $zero, L_803792B8
    if (ctx->r25 == 0) {
        // 0x80379258: sb          $t2, 0x4($a1)
        MEM_B(0X4, ctx->r5) = ctx->r10;
            goto L_803792B8;
    }
    goto skip_2;
    // 0x80379258: sb          $t2, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r10;
    skip_2:
    // 0x8037925C: sb          $t2, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r10;
    // 0x80379260: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x80379264: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80379268: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8037926C: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379270: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x80379274: mflo        $t9
    ctx->r25 = lo;
    // 0x80379278: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8037927C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80379280: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80379284: sb          $t2, -0x4($t9)
    MEM_B(-0X4, ctx->r25) = ctx->r10;
    // 0x80379288: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x8037928C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80379290: addu        $t6, $t8, $s1
    ctx->r14 = ADD32(ctx->r24, ctx->r17);
    // 0x80379294: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379298: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8037929C: mflo        $t9
    ctx->r25 = lo;
    // 0x803792A0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x803792A4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x803792A8: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x803792AC: b           L_803792E8
    // 0x803792B0: sb          $t2, -0x4($t9)
    MEM_B(-0X4, ctx->r25) = ctx->r10;
        goto L_803792E8;
    // 0x803792B0: sb          $t2, -0x4($t9)
    MEM_B(-0X4, ctx->r25) = ctx->r10;
    // 0x803792B4: sb          $t2, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r10;
L_803792B8:
    // 0x803792B8: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x803792BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803792C0: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x803792C4: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803792C8: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x803792CC: mflo        $t9
    ctx->r25 = lo;
    // 0x803792D0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x803792D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x803792D8: addu        $t9, $t8, $t3
    ctx->r25 = ADD32(ctx->r24, ctx->r11);
    // 0x803792DC: b           L_803792E8
    // 0x803792E0: sb          $t2, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r10;
        goto L_803792E8;
    // 0x803792E0: sb          $t2, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r10;
L_803792E4:
    // 0x803792E4: sb          $t2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r10;
L_803792E8:
    // 0x803792E8: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x803792EC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x803792F0: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x803792F4: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x803792F8: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x803792FC: bnel        $at, $zero, L_8037911C
    if (ctx->r1 != 0) {
        // 0x80379300: lw          $a0, 0x0($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X0);
            goto L_8037911C;
    }
    goto skip_3;
    // 0x80379300: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x80379304: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
L_80379308:
    // 0x80379308: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8037930C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80379310: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80379314: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80379318: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037931C: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x80379320: bne         $at, $zero, L_80379110
    if (ctx->r1 != 0) {
        // 0x80379324: addu        $t0, $t0, $t7
        ctx->r8 = ADD32(ctx->r8, ctx->r15);
            goto L_80379110;
    }
    // 0x80379324: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80379328: b           L_80379874
    // 0x8037932C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80379874;
    // 0x8037932C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80379330:
    // 0x80379330: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80379334: lui         $ra, 0x8039
    ctx->r31 = S32(0X8039 << 16);
    // 0x80379338: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037933C: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
    // 0x80379340: addiu       $ra, $ra, -0x609C
    ctx->r31 = ADD32(ctx->r31, -0X609C);
    // 0x80379344: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80379348: blez        $v0, L_80379870
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8037934C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80379870;
    }
    // 0x8037934C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80379350: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x80379354: addiu       $s3, $s3, -0x60A0
    ctx->r19 = ADD32(ctx->r19, -0X60A0);
    // 0x80379358: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x8037935C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80379360: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80379364: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80379368: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_8037936C:
    // 0x8037936C: blez        $v1, L_803795AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80379370: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_803795AC;
    }
    // 0x80379370: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80379374: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80379378:
    // 0x80379378: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8037937C: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x80379380: bne         $a0, $s4, L_803793C4
    if (ctx->r4 != ctx->r20) {
        // 0x80379384: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_803793C4;
    }
    // 0x80379384: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80379388: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x8037938C: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379390: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80379394: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80379398: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037939C: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x803793A0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x803793A4: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
    // 0x803793A8: mflo        $t6
    ctx->r14 = lo;
    // 0x803793AC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x803793B0: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x803793B4: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x803793B8: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x803793BC: b           L_803794D4
    // 0x803793C0: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
        goto L_803794D4;
    // 0x803793C0: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
L_803793C4:
    // 0x803793C4: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x803793C8: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x803793CC: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x803793D0: beq         $t5, $zero, L_80379448
    if (ctx->r13 == 0) {
        // 0x803793D4: nop
    
            goto L_80379448;
    }
    // 0x803793D4: nop

    // 0x803793D8: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x803793DC: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x803793E0: andi        $t6, $t8, 0x2
    ctx->r14 = ctx->r24 & 0X2;
    // 0x803793E4: beq         $t6, $zero, L_80379418
    if (ctx->r14 == 0) {
        // 0x803793E8: nop
    
            goto L_80379418;
    }
    // 0x803793E8: nop

    // 0x803793EC: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803793F0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803793F4: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x803793F8: mflo        $t7
    ctx->r15 = lo;
    // 0x803793FC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80379400: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80379404: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80379408: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8037940C: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x80379410: b           L_80379474
    // 0x80379414: lhu         $a1, -0x4($t0)
    ctx->r5 = MEM_HU(ctx->r8, -0X4);
        goto L_80379474;
    // 0x80379414: lhu         $a1, -0x4($t0)
    ctx->r5 = MEM_HU(ctx->r8, -0X4);
L_80379418:
    // 0x80379418: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037941C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80379420: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80379424: mflo        $t6
    ctx->r14 = lo;
    // 0x80379428: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8037942C: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80379430: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80379434: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80379438: addu        $t0, $t8, $a2
    ctx->r8 = ADD32(ctx->r24, ctx->r6);
    // 0x8037943C: lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X4);
    // 0x80379440: b           L_80379474
    // 0x80379444: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
        goto L_80379474;
    // 0x80379444: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
L_80379448:
    // 0x80379448: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037944C: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379450: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80379454: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x80379458: mflo        $t9
    ctx->r25 = lo;
    // 0x8037945C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80379460: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x80379464: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80379468: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8037946C: addu        $t0, $t7, $a2
    ctx->r8 = ADD32(ctx->r15, ctx->r6);
    // 0x80379470: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
L_80379474:
    // 0x80379474: beq         $s5, $a0, L_8037949C
    if (ctx->r21 == ctx->r4) {
        // 0x80379478: andi        $v1, $a1, 0xFFFF
        ctx->r3 = ctx->r5 & 0XFFFF;
            goto L_8037949C;
    }
    // 0x80379478: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8037947C: beq         $s6, $a0, L_803794B0
    if (ctx->r22 == ctx->r4) {
        // 0x80379480: nop
    
            goto L_803794B0;
    }
    // 0x80379480: nop

    // 0x80379484: beql        $s7, $a0, L_803794C4
    if (ctx->r23 == ctx->r4) {
        // 0x80379488: or          $v1, $a1, $t2
        ctx->r3 = ctx->r5 | ctx->r10;
            goto L_803794C4;
    }
    goto skip_4;
    // 0x80379488: or          $v1, $a1, $t2
    ctx->r3 = ctx->r5 | ctx->r10;
    skip_4:
    // 0x8037948C: beql        $fp, $a0, L_803794D0
    if (ctx->r30 == ctx->r4) {
        // 0x80379490: xor         $v1, $a1, $t2
        ctx->r3 = ctx->r5 ^ ctx->r10;
            goto L_803794D0;
    }
    goto skip_5;
    // 0x80379490: xor         $v1, $a1, $t2
    ctx->r3 = ctx->r5 ^ ctx->r10;
    skip_5:
    // 0x80379494: b           L_803794D4
    // 0x80379498: nop

        goto L_803794D4;
    // 0x80379498: nop

L_8037949C:
    // 0x8037949C: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x803794A0: beq         $t2, $t6, L_803794D4
    if (ctx->r10 == ctx->r14) {
        // 0x803794A4: nop
    
            goto L_803794D4;
    }
    // 0x803794A4: nop

    // 0x803794A8: b           L_803794D4
    // 0x803794AC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
        goto L_803794D4;
    // 0x803794AC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
L_803794B0:
    // 0x803794B0: beq         $t2, $zero, L_803794D4
    if (ctx->r10 == 0) {
        // 0x803794B4: nop
    
            goto L_803794D4;
    }
    // 0x803794B4: nop

    // 0x803794B8: b           L_803794D4
    // 0x803794BC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
        goto L_803794D4;
    // 0x803794BC: andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
    // 0x803794C0: or          $v1, $a1, $t2
    ctx->r3 = ctx->r5 | ctx->r10;
L_803794C4:
    // 0x803794C4: b           L_803794D4
    // 0x803794C8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_803794D4;
    // 0x803794C8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x803794CC: xor         $v1, $a1, $t2
    ctx->r3 = ctx->r5 ^ ctx->r10;
L_803794D0:
    // 0x803794D0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_803794D4:
    // 0x803794D4: beq         $t5, $zero, L_80379588
    if (ctx->r13 == 0) {
        // 0x803794D8: addu        $t8, $a3, $t3
        ctx->r24 = ADD32(ctx->r7, ctx->r11);
            goto L_80379588;
    }
    // 0x803794D8: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x803794DC: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x803794E0: beql        $t9, $zero, L_80379554
    if (ctx->r25 == 0) {
        // 0x803794E4: sh          $v1, 0x4($t0)
        MEM_H(0X4, ctx->r8) = ctx->r3;
            goto L_80379554;
    }
    goto skip_6;
    // 0x803794E4: sh          $v1, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r3;
    skip_6:
    // 0x803794E8: sh          $v1, -0x4($t0)
    MEM_H(-0X4, ctx->r8) = ctx->r3;
    // 0x803794EC: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x803794F0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x803794F4: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x803794F8: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803794FC: mflo        $t9
    ctx->r25 = lo;
    // 0x80379500: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80379504: lh          $t9, 0x0($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X0);
    // 0x80379508: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8037950C: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80379510: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80379514: addu        $t9, $t6, $a2
    ctx->r25 = ADD32(ctx->r14, ctx->r6);
    // 0x80379518: sh          $v1, -0x4($t9)
    MEM_H(-0X4, ctx->r25) = ctx->r3;
    // 0x8037951C: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x80379520: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80379524: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x80379528: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037952C: mflo        $t9
    ctx->r25 = lo;
    // 0x80379530: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80379534: lh          $t9, 0x0($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X0);
    // 0x80379538: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8037953C: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80379540: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80379544: addu        $t9, $t7, $a2
    ctx->r25 = ADD32(ctx->r15, ctx->r6);
    // 0x80379548: b           L_8037958C
    // 0x8037954C: sh          $v1, -0x4($t9)
    MEM_H(-0X4, ctx->r25) = ctx->r3;
        goto L_8037958C;
    // 0x8037954C: sh          $v1, -0x4($t9)
    MEM_H(-0X4, ctx->r25) = ctx->r3;
    // 0x80379550: sh          $v1, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r3;
L_80379554:
    // 0x80379554: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x80379558: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8037955C: addu        $t7, $t8, $s1
    ctx->r15 = ADD32(ctx->r24, ctx->r17);
    // 0x80379560: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379564: mflo        $t9
    ctx->r25 = lo;
    // 0x80379568: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8037956C: lh          $t9, 0x0($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X0);
    // 0x80379570: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80379574: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80379578: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8037957C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x80379580: b           L_8037958C
    // 0x80379584: sh          $v1, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r3;
        goto L_8037958C;
    // 0x80379584: sh          $v1, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r3;
L_80379588:
    // 0x80379588: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
L_8037958C:
    // 0x8037958C: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x80379590: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80379594: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x80379598: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8037959C: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x803795A0: bnel        $at, $zero, L_80379378
    if (ctx->r1 != 0) {
        // 0x803795A4: lw          $a0, 0x0($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X0);
            goto L_80379378;
    }
    goto skip_7;
    // 0x803795A4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    skip_7:
    // 0x803795A8: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
L_803795AC:
    // 0x803795AC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x803795B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x803795B4: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x803795B8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x803795BC: subu        $t6, $t7, $v1
    ctx->r14 = SUB32(ctx->r15, ctx->r3);
    // 0x803795C0: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x803795C4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x803795C8: bne         $at, $zero, L_8037936C
    if (ctx->r1 != 0) {
        // 0x803795CC: addu        $s2, $s2, $t8
        ctx->r18 = ADD32(ctx->r18, ctx->r24);
            goto L_8037936C;
    }
    // 0x803795CC: addu        $s2, $s2, $t8
    ctx->r18 = ADD32(ctx->r18, ctx->r24);
    // 0x803795D0: b           L_80379874
    // 0x803795D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80379874;
    // 0x803795D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_803795D8:
    // 0x803795D8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x803795DC: lui         $ra, 0x8039
    ctx->r31 = S32(0X8039 << 16);
    // 0x803795E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x803795E4: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
    // 0x803795E8: addiu       $ra, $ra, -0x609C
    ctx->r31 = ADD32(ctx->r31, -0X609C);
    // 0x803795EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x803795F0: blez        $v0, L_80379870
    if (SIGNED(ctx->r2) <= 0) {
        // 0x803795F4: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80379870;
    }
    // 0x803795F4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x803795F8: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x803795FC: addiu       $s3, $s3, -0x60A0
    ctx->r19 = ADD32(ctx->r19, -0X60A0);
    // 0x80379600: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x80379604: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80379608: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x8037960C: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80379610: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80379614:
    // 0x80379614: blez        $v1, L_8037984C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80379618: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8037984C;
    }
    // 0x80379618: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8037961C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80379620:
    // 0x80379620: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80379624: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80379628: bne         $a0, $s4, L_8037966C
    if (ctx->r4 != ctx->r20) {
        // 0x8037962C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8037966C;
    }
    // 0x8037962C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80379630: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x80379634: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379638: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8037963C: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80379640: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379644: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x80379648: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8037964C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80379650: mflo        $t6
    ctx->r14 = lo;
    // 0x80379654: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80379658: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8037965C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80379660: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80379664: b           L_80379774
    // 0x80379668: addu        $t0, $t7, $a2
    ctx->r8 = ADD32(ctx->r15, ctx->r6);
        goto L_80379774;
    // 0x80379668: addu        $t0, $t7, $a2
    ctx->r8 = ADD32(ctx->r15, ctx->r6);
L_8037966C:
    // 0x8037966C: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x80379670: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80379674: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80379678: beq         $t5, $zero, L_803796F0
    if (ctx->r13 == 0) {
        // 0x8037967C: nop
    
            goto L_803796F0;
    }
    // 0x8037967C: nop

    // 0x80379680: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80379684: addu        $t9, $a3, $t3
    ctx->r25 = ADD32(ctx->r7, ctx->r11);
    // 0x80379688: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x8037968C: beq         $t6, $zero, L_803796C0
    if (ctx->r14 == 0) {
        // 0x80379690: nop
    
            goto L_803796C0;
    }
    // 0x80379690: nop

    // 0x80379694: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379698: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8037969C: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x803796A0: mflo        $t8
    ctx->r24 = lo;
    // 0x803796A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x803796A8: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x803796AC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x803796B0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x803796B4: addu        $t0, $t7, $a2
    ctx->r8 = ADD32(ctx->r15, ctx->r6);
    // 0x803796B8: b           L_8037971C
    // 0x803796BC: lw          $v1, -0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, -0X8);
        goto L_8037971C;
    // 0x803796BC: lw          $v1, -0x8($t0)
    ctx->r3 = MEM_W(ctx->r8, -0X8);
L_803796C0:
    // 0x803796C0: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803796C4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803796C8: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x803796CC: mflo        $t6
    ctx->r14 = lo;
    // 0x803796D0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x803796D4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x803796D8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x803796DC: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x803796E0: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x803796E4: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x803796E8: b           L_8037971C
    // 0x803796EC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_8037971C;
    // 0x803796EC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_803796F0:
    // 0x803796F0: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803796F4: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x803796F8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x803796FC: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x80379700: mflo        $t7
    ctx->r15 = lo;
    // 0x80379704: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80379708: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8037970C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80379710: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80379714: addu        $t0, $t8, $a2
    ctx->r8 = ADD32(ctx->r24, ctx->r6);
    // 0x80379718: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
L_8037971C:
    // 0x8037971C: beq         $s5, $a0, L_80379744
    if (ctx->r21 == ctx->r4) {
        // 0x80379720: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80379744;
    }
    // 0x80379720: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80379724: beq         $s6, $a0, L_80379758
    if (ctx->r22 == ctx->r4) {
        // 0x80379728: nop
    
            goto L_80379758;
    }
    // 0x80379728: nop

    // 0x8037972C: beq         $s7, $a0, L_80379768
    if (ctx->r23 == ctx->r4) {
        // 0x80379730: nop
    
            goto L_80379768;
    }
    // 0x80379730: nop

    // 0x80379734: beql        $fp, $a0, L_80379774
    if (ctx->r30 == ctx->r4) {
        // 0x80379738: xor         $a1, $v1, $t2
        ctx->r5 = ctx->r3 ^ ctx->r10;
            goto L_80379774;
    }
    goto skip_8;
    // 0x80379738: xor         $a1, $v1, $t2
    ctx->r5 = ctx->r3 ^ ctx->r10;
    skip_8:
    // 0x8037973C: b           L_80379774
    // 0x80379740: nop

        goto L_80379774;
    // 0x80379740: nop

L_80379744:
    // 0x80379744: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80379748: beq         $t2, $t6, L_80379774
    if (ctx->r10 == ctx->r14) {
        // 0x8037974C: nop
    
            goto L_80379774;
    }
    // 0x8037974C: nop

    // 0x80379750: b           L_80379774
    // 0x80379754: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_80379774;
    // 0x80379754: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80379758:
    // 0x80379758: beq         $t2, $zero, L_80379774
    if (ctx->r10 == 0) {
        // 0x8037975C: nop
    
            goto L_80379774;
    }
    // 0x8037975C: nop

    // 0x80379760: b           L_80379774
    // 0x80379764: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_80379774;
    // 0x80379764: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80379768:
    // 0x80379768: b           L_80379774
    // 0x8037976C: or          $a1, $v1, $t2
    ctx->r5 = ctx->r3 | ctx->r10;
        goto L_80379774;
    // 0x8037976C: or          $a1, $v1, $t2
    ctx->r5 = ctx->r3 | ctx->r10;
    // 0x80379770: xor         $a1, $v1, $t2
    ctx->r5 = ctx->r3 ^ ctx->r10;
L_80379774:
    // 0x80379774: beq         $t5, $zero, L_80379828
    if (ctx->r13 == 0) {
        // 0x80379778: addu        $t9, $a3, $t3
        ctx->r25 = ADD32(ctx->r7, ctx->r11);
            goto L_80379828;
    }
    // 0x80379778: addu        $t9, $a3, $t3
    ctx->r25 = ADD32(ctx->r7, ctx->r11);
    // 0x8037977C: andi        $t7, $t9, 0x2
    ctx->r15 = ctx->r25 & 0X2;
    // 0x80379780: beql        $t7, $zero, L_803797F4
    if (ctx->r15 == 0) {
        // 0x80379784: sw          $a1, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r5;
            goto L_803797F4;
    }
    goto skip_9;
    // 0x80379784: sw          $a1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r5;
    skip_9:
    // 0x80379788: sw          $a1, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r5;
    // 0x8037978C: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x80379790: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80379794: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x80379798: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037979C: mflo        $t7
    ctx->r15 = lo;
    // 0x803797A0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x803797A4: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x803797A8: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x803797AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x803797B0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x803797B4: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x803797B8: sw          $a1, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r5;
    // 0x803797BC: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x803797C0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x803797C4: addu        $t6, $t8, $s1
    ctx->r14 = ADD32(ctx->r24, ctx->r17);
    // 0x803797C8: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803797CC: mflo        $t7
    ctx->r15 = lo;
    // 0x803797D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x803797D4: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x803797D8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x803797DC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x803797E0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x803797E4: addu        $t7, $t8, $a2
    ctx->r15 = ADD32(ctx->r24, ctx->r6);
    // 0x803797E8: b           L_8037982C
    // 0x803797EC: sw          $a1, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r5;
        goto L_8037982C;
    // 0x803797EC: sw          $a1, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r5;
    // 0x803797F0: sw          $a1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r5;
L_803797F4:
    // 0x803797F4: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x803797F8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x803797FC: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x80379800: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379804: mflo        $t7
    ctx->r15 = lo;
    // 0x80379808: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8037980C: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80379810: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80379814: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80379818: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8037981C: addu        $t7, $t9, $a2
    ctx->r15 = ADD32(ctx->r25, ctx->r6);
    // 0x80379820: b           L_8037982C
    // 0x80379824: sw          $a1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r5;
        goto L_8037982C;
    // 0x80379824: sw          $a1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r5;
L_80379828:
    // 0x80379828: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
L_8037982C:
    // 0x8037982C: lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X4);
    // 0x80379830: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80379834: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x80379838: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8037983C: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80379840: bnel        $at, $zero, L_80379620
    if (ctx->r1 != 0) {
        // 0x80379844: lw          $a0, 0x0($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X0);
            goto L_80379620;
    }
    goto skip_10;
    // 0x80379844: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    skip_10:
    // 0x80379848: lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X6);
L_8037984C:
    // 0x8037984C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80379850: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80379854: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80379858: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8037985C: subu        $t6, $t8, $v1
    ctx->r14 = SUB32(ctx->r24, ctx->r3);
    // 0x80379860: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80379864: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80379868: bne         $at, $zero, L_80379614
    if (ctx->r1 != 0) {
        // 0x8037986C: addu        $s2, $s2, $t9
        ctx->r18 = ADD32(ctx->r18, ctx->r25);
            goto L_80379614;
    }
    // 0x8037986C: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
L_80379870:
    // 0x80379870: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80379874:
    // 0x80379874: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80379878: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8037987C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80379880: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80379884: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80379888: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8037988C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80379890: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80379894: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80379898: jr          $ra
    // 0x8037989C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8037989C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameMakeNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DA0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80132DA4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132DA8: addiu       $t7, $t7, -0x76BC
    ctx->r15 = ADD32(ctx->r15, -0X76BC);
    // 0x80132DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132DB0: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80132DB4: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80132DB8: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x80132DBC: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
L_80132DC0:
    // 0x80132DC0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132DC4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132DC8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132DCC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132DD0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132DD4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132DD8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132DDC: bne         $t7, $t0, L_80132DC0
    if (ctx->r15 != ctx->r8) {
        // 0x80132DE0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132DC0;
    }
    // 0x80132DE0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132DE4: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132DE8: addiu       $t2, $t2, -0x765C
    ctx->r10 = ADD32(ctx->r10, -0X765C);
    // 0x80132DEC: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132DF0: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
L_80132DF4:
    // 0x80132DF4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132DF8: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132DFC: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132E00: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132E04: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132E08: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132E0C: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132E10: bne         $t2, $t5, L_80132DF4
    if (ctx->r10 != ctx->r13) {
        // 0x80132E14: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132DF4;
    }
    // 0x80132E14: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132E18: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132E1C: addiu       $t7, $t7, -0x762C
    ctx->r15 = ADD32(ctx->r15, -0X762C);
    // 0x80132E20: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80132E24: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
L_80132E28:
    // 0x80132E28: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132E2C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132E30: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80132E34: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80132E38: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80132E3C: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80132E40: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80132E44: bne         $t7, $t9, L_80132E28
    if (ctx->r15 != ctx->r25) {
        // 0x80132E48: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80132E28;
    }
    // 0x80132E48: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80132E4C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80132E50: beq         $a2, $at, L_80132F0C
    if (ctx->r6 == ctx->r1) {
        // 0x80132E54: lw          $a0, 0xE0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE0);
            goto L_80132F0C;
    }
    // 0x80132E54: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132E58: jal         0x8000B760
    // 0x80132E5C: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132E5C: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80132E60: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x80132E64: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132E68: lw          $t2, -0x695C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X695C);
    // 0x80132E6C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132E70: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x80132E74: lw          $t5, 0x4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4C);
    // 0x80132E78: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80132E7C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132E80: jal         0x800CCFDC
    // 0x80132E84: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132E84: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_1:
    // 0x80132E88: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80132E8C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80132E90: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80132E94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E98: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80132E9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132EA0: andi        $t4, $t1, 0xFFDF
    ctx->r12 = ctx->r9 & 0XFFDF;
    // 0x80132EA4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132EA8: ori         $t9, $t4, 0x1
    ctx->r25 = ctx->r12 | 0X1;
    // 0x80132EAC: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132EB0: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132EB4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132EB8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132EBC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132EC0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132EC4: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80132EC8: addu        $t7, $sp, $v1
    ctx->r15 = ADD32(ctx->r29, ctx->r3);
    // 0x80132ECC: lw          $t7, 0x1C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1C);
    // 0x80132ED0: lw          $t0, -0x6960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6960);
    // 0x80132ED4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132ED8: jal         0x800CCFDC
    // 0x80132EDC: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132EDC: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_2:
    // 0x80132EE0: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132EE4: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80132EE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132EEC: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x80132EF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132EF4: andi        $t5, $t6, 0xFFDF
    ctx->r13 = ctx->r14 & 0XFFDF;
    // 0x80132EF8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132EFC: ori         $t2, $t5, 0x1
    ctx->r10 = ctx->r13 | 0X1;
    // 0x80132F00: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132F04: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132F08: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132F0C:
    // 0x80132F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F10: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80132F14: jr          $ra
    // 0x80132F18: nop

    return;
    // 0x80132F18: nop

;}
RECOMP_FUNC void ifCommonBattleSetUpdateInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801147BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801147C0: addiu       $v1, $v1, 0x17E6
    ctx->r3 = ADD32(ctx->r3, 0X17E6);
    // 0x801147C4: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x801147C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801147CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801147D0: beq         $v0, $zero, L_801147E0
    if (ctx->r2 == 0) {
        // 0x801147D4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801147E0;
    }
    // 0x801147D4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801147D8: b           L_801147E8
    // 0x801147DC: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
        goto L_801147E8;
    // 0x801147DC: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_801147E0:
    // 0x801147E0: jal         0x80005C74
    // 0x801147E4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x801147E4: nop

    after_0:
L_801147E8:
    // 0x801147E8: jal         0x8000A5E4
    // 0x801147EC: nop

    gcRunAll(rdram, ctx);
        goto after_1;
    // 0x801147EC: nop

    after_1:
    // 0x801147F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801147F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801147F8: jr          $ra
    // 0x801147FC: nop

    return;
    // 0x801147FC: nop

;}
RECOMP_FUNC void dbCubeMakeGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131EA4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80131EA8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80131EAC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80131EB0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80131EB4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80131EB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131EBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131EC0: addiu       $t6, $t6, 0x3E68
    ctx->r14 = ADD32(ctx->r14, 0X3E68);
    // 0x80131EC4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131EC8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80131ECC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80131ED0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131ED4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80131ED8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80131EDC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80131EE0: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x80131EE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131EE8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80131EEC: lui         $a0, 0x1000
    ctx->r4 = S32(0X1000 << 16);
    // 0x80131EF0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131EF4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80131EF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131EFC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80131F00: jal         0x8000B824
    // 0x80131F04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    gcMakeModelGObj(rdram, ctx);
        goto after_0;
    // 0x80131F04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80131F08: beq         $v0, $zero, L_80131F18
    if (ctx->r2 == 0) {
        // 0x80131F0C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80131F18;
    }
    // 0x80131F0C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F10: b           L_80131F1C
    // 0x80131F14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80131F1C;
    // 0x80131F14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F18:
    // 0x80131F18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80131F1C:
    // 0x80131F1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131F20: jr          $ra
    // 0x80131F24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80131F24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sc1PStageClearMakeScoreDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80131E14: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80131E18: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80131E1C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80131E20: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80131E24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131E28: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80131E2C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80131E30: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80131E34: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80131E38: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80131E3C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80131E40: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80131E44: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80131E48: bgez        $a1, L_80131E74
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80131E4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131E74;
    }
    // 0x80131E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131E50: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x80131E54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131E58: beq         $s5, $at, L_80131E68
    if (ctx->r21 == ctx->r1) {
        // 0x80131E5C: nop
    
            goto L_80131E68;
    }
    // 0x80131E5C: nop

    // 0x80131E60: bne         $s5, $zero, L_80131E70
    if (ctx->r21 != 0) {
        // 0x80131E64: negu        $s3, $s3
        ctx->r19 = SUB32(0, ctx->r19);
            goto L_80131E70;
    }
    // 0x80131E64: negu        $s3, $s3
    ctx->r19 = SUB32(0, ctx->r19);
L_80131E68:
    // 0x80131E68: b           L_80131E74
    // 0x80131E6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80131E74;
    // 0x80131E6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80131E70:
    // 0x80131E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131E74:
    // 0x80131E74: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80131E78: div         $zero, $s3, $at
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r1)));
    // 0x80131E7C: lw          $s5, 0x68($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X68);
    // 0x80131E80: mfhi        $a1
    ctx->r5 = hi;
    // 0x80131E84: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80131E88: jal         0x80131D70
    // 0x80131E8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    sc1PStageClearGetScoreDigitSprite(rdram, ctx);
        goto after_0;
    // 0x80131E8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80131E90: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80131E94: jal         0x800CCFDC
    // 0x80131E98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131E98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80131E9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EA4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80131EA8: jal         0x80131BF8
    // 0x80131EAC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    sc1PStageClearSetDigitSpriteColors(rdram, ctx);
        goto after_2;
    // 0x80131EAC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x80131EB0: lw          $s4, 0x6C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X6C);
    // 0x80131EB4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80131EB8: beql        $s4, $zero, L_80131ED8
    if (ctx->r20 == 0) {
        // 0x80131EBC: lh          $t6, 0x14($s1)
        ctx->r14 = MEM_H(ctx->r17, 0X14);
            goto L_80131ED8;
    }
    goto skip_0;
    // 0x80131EBC: lh          $t6, 0x14($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X14);
    skip_0:
    // 0x80131EC0: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x80131EC4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131EC8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80131ECC: b           L_80131EF0
    // 0x80131ED0: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
        goto L_80131EF0;
    // 0x80131ED0: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80131ED4: lh          $t6, 0x14($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X14);
L_80131ED8:
    // 0x80131ED8: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131EDC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80131EE0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80131EE4: nop

    // 0x80131EE8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80131EEC: sub.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f16.fl;
L_80131EF0:
    // 0x80131EF0: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x80131EF4: swc1        $f22, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f22.u32l;
    // 0x80131EF8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80131EFC: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80131F00: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80131F04: beq         $t9, $zero, L_80131F18
    if (ctx->r25 == 0) {
        // 0x80131F08: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80131F18;
    }
    // 0x80131F08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80131F0C: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80131F10: b           L_80131F24
    // 0x80131F14: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F24;
    // 0x80131F14: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131F18:
    // 0x80131F18: jal         0x80131CC4
    // 0x80131F1C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    sc1PStageClearGetScoreDigitCount(rdram, ctx);
        goto after_3;
    // 0x80131F1C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80131F20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F24:
    // 0x80131F24: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131F28: bne         $at, $zero, L_80132028
    if (ctx->r1 != 0) {
        // 0x80131F2C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80132028;
    }
    // 0x80131F2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80131F30:
    // 0x80131F30: jal         0x80131B58
    // 0x80131F34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PStageClearGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80131F34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80131F38: beq         $v0, $zero, L_80131F80
    if (ctx->r2 == 0) {
        // 0x80131F3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131F80;
    }
    // 0x80131F3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131F40: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131F44: jal         0x80131B58
    // 0x80131F48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PStageClearGetPowerOf(rdram, ctx);
        goto after_5;
    // 0x80131F48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80131F4C: div         $zero, $s3, $v0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r2)));
    // 0x80131F50: mflo        $v1
    ctx->r3 = lo;
    // 0x80131F54: bne         $v0, $zero, L_80131F60
    if (ctx->r2 != 0) {
        // 0x80131F58: nop
    
            goto L_80131F60;
    }
    // 0x80131F58: nop

    // 0x80131F5C: break       7
    do_break(2148736860);
L_80131F60:
    // 0x80131F60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131F64: bne         $v0, $at, L_80131F78
    if (ctx->r2 != ctx->r1) {
        // 0x80131F68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131F78;
    }
    // 0x80131F68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131F6C: bne         $s3, $at, L_80131F78
    if (ctx->r19 != ctx->r1) {
        // 0x80131F70: nop
    
            goto L_80131F78;
    }
    // 0x80131F70: nop

    // 0x80131F74: break       6
    do_break(2148736884);
L_80131F78:
    // 0x80131F78: b           L_80131F84
    // 0x80131F7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
        goto L_80131F84;
    // 0x80131F7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80131F80:
    // 0x80131F80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80131F84:
    // 0x80131F84: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80131F88: mfhi        $a1
    ctx->r5 = hi;
    // 0x80131F8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80131F90: jal         0x80131D70
    // 0x80131F94: nop

    sc1PStageClearGetScoreDigitSprite(rdram, ctx);
        goto after_6;
    // 0x80131F94: nop

    after_6:
    // 0x80131F98: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80131F9C: jal         0x800CCFDC
    // 0x80131FA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80131FA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80131FA4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80131FA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FAC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80131FB0: jal         0x80131BF8
    // 0x80131FB4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    sc1PStageClearSetDigitSpriteColors(rdram, ctx);
        goto after_8;
    // 0x80131FB4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_8:
    // 0x80131FB8: beq         $s4, $zero, L_80131FD4
    if (ctx->r20 == 0) {
        // 0x80131FBC: lw          $t1, 0x64($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X64);
            goto L_80131FD4;
    }
    // 0x80131FBC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80131FC0: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x80131FC4: nop

    // 0x80131FC8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80131FCC: b           L_80131FEC
    // 0x80131FD0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
        goto L_80131FEC;
    // 0x80131FD0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
L_80131FD4:
    // 0x80131FD4: lh          $t0, 0x14($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X14);
    // 0x80131FD8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80131FDC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80131FE0: nop

    // 0x80131FE4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131FE8: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_80131FEC:
    // 0x80131FEC: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x80131FF0: swc1        $f22, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f22.u32l;
    // 0x80131FF4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80131FF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80131FFC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80132000: beq         $t3, $zero, L_80132010
    if (ctx->r11 == 0) {
        // 0x80132004: nop
    
            goto L_80132010;
    }
    // 0x80132004: nop

    // 0x80132008: b           L_8013201C
    // 0x8013200C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_8013201C;
    // 0x8013200C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80132010:
    // 0x80132010: jal         0x80131CC4
    // 0x80132014: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    sc1PStageClearGetScoreDigitCount(rdram, ctx);
        goto after_9;
    // 0x80132014: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80132018: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8013201C:
    // 0x8013201C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80132020: bnel        $at, $zero, L_80131F30
    if (ctx->r1 != 0) {
        // 0x80132024: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80131F30;
    }
    goto skip_1;
    // 0x80132024: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    skip_1:
L_80132028:
    // 0x80132028: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8013202C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132030: beql        $t4, $zero, L_801320B8
    if (ctx->r12 == 0) {
        // 0x80132034: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801320B8;
    }
    goto skip_2;
    // 0x80132034: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80132038: bne         $s5, $at, L_8013205C
    if (ctx->r21 != ctx->r1) {
        // 0x8013203C: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_8013205C;
    }
    // 0x8013203C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80132040: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132044: lw          $t5, 0x5598($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5598);
    // 0x80132048: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8013204C: addiu       $t6, $t6, 0x710
    ctx->r14 = ADD32(ctx->r14, 0X710);
    // 0x80132050: jal         0x800CCFDC
    // 0x80132054: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_10;
    // 0x80132054: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_10:
    // 0x80132058: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8013205C:
    // 0x8013205C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132060: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80132064: jal         0x80131BF8
    // 0x80132068: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    sc1PStageClearSetDigitSpriteColors(rdram, ctx);
        goto after_11;
    // 0x80132068: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_11:
    // 0x8013206C: beq         $s4, $zero, L_80132088
    if (ctx->r20 == 0) {
        // 0x80132070: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80132088;
    }
    // 0x80132070: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132074: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x80132078: nop

    // 0x8013207C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132080: b           L_801320A4
    // 0x80132084: sub.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f16.fl;
        goto L_801320A4;
    // 0x80132084: sub.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f16.fl;
L_80132088:
    // 0x80132088: lh          $t7, 0x14($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X14);
    // 0x8013208C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80132090: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80132094: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80132098: nop

    // 0x8013209C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801320A0: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
L_801320A4:
    // 0x801320A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801320A8: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x801320AC: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x801320B0: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
    // 0x801320B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801320B8:
    // 0x801320B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801320BC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801320C0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801320C4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801320C8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x801320CC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x801320D0: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x801320D4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x801320D8: jr          $ra
    // 0x801320DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801320DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F3EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F3F0: jr          $ra
    // 0x8015F3F4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015F3F4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void mpCommonSetFighterWaitOrFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DEE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DEE5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DEE60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DEE64: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x800DEE68: bne         $t6, $at, L_800DEE80
    if (ctx->r14 != ctx->r1) {
        // 0x800DEE6C: nop
    
            goto L_800DEE80;
    }
    // 0x800DEE6C: nop

    // 0x800DEE70: jal         0x8013F9E0
    // 0x800DEE74: nop

    ftCommonFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x800DEE74: nop

    after_0:
    // 0x800DEE78: b           L_800DEE8C
    // 0x800DEE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEE8C;
    // 0x800DEE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEE80:
    // 0x800DEE80: jal         0x8013E1C8
    // 0x800DEE84: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DEE84: nop

    after_1:
    // 0x800DEE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEE8C:
    // 0x800DEE8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DEE90: jr          $ra
    // 0x800DEE94: nop

    return;
    // 0x800DEE94: nop

;}
RECOMP_FUNC void mvOpeningYosterMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131DBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131DC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131DC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DCC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131DD0: jal         0x80009968
    // 0x80131DD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131DD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131DD8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131DDC: lw          $t6, 0x25F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25F8);
    // 0x80131DE0: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131DE4: addiu       $t7, $t7, -0x4670
    ctx->r15 = ADD32(ctx->r15, -0X4670);
    // 0x80131DE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131DF4: jal         0x8000F120
    // 0x80131DF8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131DF8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131DFC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E00: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131E04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131E08: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E10: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131E14: jal         0x80009DF4
    // 0x80131E18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131E18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131E1C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131E20: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131E24: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131E28: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80131E2C: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131E30: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131E34: addiu       $t3, $t3, -0x4090
    ctx->r11 = ADD32(ctx->r11, -0X4090);
    // 0x80131E38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131E3C: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131E40: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E48: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131E4C: lw          $t2, 0x25F8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X25F8);
    // 0x80131E50: jal         0x8000BD8C
    // 0x80131E54: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131E54: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80131E58: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E5C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131E64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131E68: jal         0x80008188
    // 0x80131E6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80131E6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80131E70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131E74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131E78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E7C: jr          $ra
    // 0x80131E80: nop

    return;
    // 0x80131E80: nop

;}
RECOMP_FUNC void itIwarkWeaponRockMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DF28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017DF2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017DF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DF34: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017DF38: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017DF3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017DF40: addiu       $a1, $a1, -0x54FC
    ctx->r5 = ADD32(ctx->r5, -0X54FC);
    // 0x8017DF44: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8017DF48: jal         0x801655C8
    // 0x8017DF4C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8017DF4C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x8017DF50: bne         $v0, $zero, L_8017DF60
    if (ctx->r2 != 0) {
        // 0x8017DF54: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8017DF60;
    }
    // 0x8017DF54: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8017DF58: b           L_8017E054
    // 0x8017DF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017E054;
    // 0x8017DF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017DF60:
    // 0x8017DF60: lbu         $a1, 0x3B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3B);
    // 0x8017DF64: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017DF68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8017DF6C: bne         $a1, $zero, L_8017DF84
    if (ctx->r5 != 0) {
        // 0x8017DF70: sw          $t6, 0x2A0($v1)
        MEM_W(0X2A0, ctx->r3) = ctx->r14;
            goto L_8017DF84;
    }
    // 0x8017DF70: sw          $t6, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->r14;
    // 0x8017DF74: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8017DF78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017DF7C: b           L_8017DFA8
    // 0x8017DF80: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
        goto L_8017DFA8;
    // 0x8017DF80: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
L_8017DF84:
    // 0x8017DF84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017DF88: bne         $a1, $at, L_8017DF9C
    if (ctx->r5 != ctx->r1) {
        // 0x8017DF8C: lui         $at, 0xC248
        ctx->r1 = S32(0XC248 << 16);
            goto L_8017DF9C;
    }
    // 0x8017DF8C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8017DF90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017DF94: b           L_8017DFA8
    // 0x8017DF98: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
        goto L_8017DFA8;
    // 0x8017DF98: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
L_8017DF9C:
    // 0x8017DF9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017DFA0: nop

    // 0x8017DFA4: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
L_8017DFA8:
    // 0x8017DFA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8017DFAC: jal         0x80018994
    // 0x8017DFB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8017DFB0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017DFB4: bne         $v0, $zero, L_8017DFC8
    if (ctx->r2 != 0) {
        // 0x8017DFB8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8017DFC8;
    }
    // 0x8017DFB8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DFBC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8017DFC0: b           L_8017DFD0
    // 0x8017DFC4: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
        goto L_8017DFD0;
    // 0x8017DFC4: sw          $t7, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r15;
L_8017DFC8:
    // 0x8017DFC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017DFCC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
L_8017DFD0:
    // 0x8017DFD0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017DFD4: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017DFD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DFDC: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x8017DFE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017DFE4: jal         0x80008CC0
    // 0x8017DFE8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017DFE8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8017DFEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017DFF0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8017DFF4: jal         0x80008CC0
    // 0x8017DFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8017DFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8017DFFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8017E000: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017E004: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E008: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8017E00C: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    // 0x8017E010: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x8017E014: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8017E018: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8017E01C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8017E020: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8017E024: addiu       $t0, $t0, -0x2354
    ctx->r8 = ADD32(ctx->r8, -0X2354);
    // 0x8017E028: sw          $t2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r10;
    // 0x8017E02C: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x8017E030: lw          $t5, 0x80($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X80);
    // 0x8017E034: sh          $t3, 0x80($t5)
    MEM_H(0X80, ctx->r13) = ctx->r11;
    // 0x8017E038: lbu         $t8, 0x260($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X260);
    // 0x8017E03C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8017E040: sw          $t0, 0x298($v1)
    MEM_W(0X298, ctx->r3) = ctx->r8;
    // 0x8017E044: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8017E048: sb          $t9, 0x260($v1)
    MEM_B(0X260, ctx->r3) = ctx->r25;
    // 0x8017E04C: sw          $t6, 0x2AC($v1)
    MEM_W(0X2AC, ctx->r3) = ctx->r14;
    // 0x8017E050: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8017E054:
    // 0x8017E054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E058: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017E05C: jr          $ra
    // 0x8017E060: nop

    return;
    // 0x8017E060: nop

;}
RECOMP_FUNC void mnVSResultsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138B70: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80138B74: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80138B78: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80138B7C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80138B80: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80138B84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80138B88: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80138B8C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80138B90: addiu       $t8, $t8, -0x63B0
    ctx->r24 = ADD32(ctx->r24, -0X63B0);
    // 0x80138B94: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80138B98: addiu       $t0, $t0, -0x5FF0
    ctx->r8 = ADD32(ctx->r8, -0X5FF0);
    // 0x80138B9C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80138BA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80138BA4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80138BA8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80138BAC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80138BB0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80138BB4: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80138BB8: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80138BBC: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80138BC0: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80138BC4: jal         0x800CDF78
    // 0x80138BC8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80138BC8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80138BCC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80138BD0: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80138BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138BD8: jal         0x800CDEEC
    // 0x80138BDC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80138BDC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80138BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80138BE4: jal         0x80004980
    // 0x80138BE8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80138BE8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80138BEC: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80138BF0: addiu       $a2, $a2, -0x5FB8
    ctx->r6 = ADD32(ctx->r6, -0X5FB8);
    // 0x80138BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138BF8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80138BFC: jal         0x800CDE04
    // 0x80138C00: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80138C00: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80138C04: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80138C08: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80138C0C: addiu       $a1, $a1, -0x7754
    ctx->r5 = ADD32(ctx->r5, -0X7754);
    // 0x80138C10: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80138C14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138C18: jal         0x80009968
    // 0x80138C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80138C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80138C20: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80138C24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80138C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138C2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80138C30: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80138C34: jal         0x8000B9FC
    // 0x80138C38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80138C38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80138C3C: jal         0x80115890
    // 0x80138C40: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80138C40: nop

    after_6:
    // 0x80138C44: jal         0x800FD300
    // 0x80138C48: nop

    efManagerInitEffects(rdram, ctx);
        goto after_7;
    // 0x80138C48: nop

    after_7:
    // 0x80138C4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80138C50: jal         0x800D7194
    // 0x80138C54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_8;
    // 0x80138C54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80138C58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80138C5C:
    // 0x80138C5C: jal         0x800D786C
    // 0x80138C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_9;
    // 0x80138C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80138C64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80138C68: slti        $at, $s0, 0xC
    ctx->r1 = SIGNED(ctx->r16) < 0XC ? 1 : 0;
    // 0x80138C6C: bne         $at, $zero, L_80138C5C
    if (ctx->r1 != 0) {
        // 0x80138C70: nop
    
            goto L_80138C5C;
    }
    // 0x80138C70: nop

    // 0x80138C74: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138C78: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80138C7C: addiu       $s0, $s0, 0xD9C
    ctx->r16 = ADD32(ctx->r16, 0XD9C);
    // 0x80138C80: addiu       $v1, $v1, -0x6400
    ctx->r3 = ADD32(ctx->r3, -0X6400);
L_80138C84:
    // 0x80138C84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80138C88: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80138C8C: jal         0x80004980
    // 0x80138C90: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    syTaskmanMalloc(rdram, ctx);
        goto after_10;
    // 0x80138C90: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_10:
    // 0x80138C94: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80138C98: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138C9C: addiu       $t3, $t3, -0x63F0
    ctx->r11 = ADD32(ctx->r11, -0X63F0);
    // 0x80138CA0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80138CA4: bne         $v1, $t3, L_80138C84
    if (ctx->r3 != ctx->r11) {
        // 0x80138CA8: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_80138C84;
    }
    // 0x80138CA8: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x80138CAC: jal         0x80131B90
    // 0x80138CB0: nop

    mnVSResultsSaveBackup(rdram, ctx);
        goto after_11;
    // 0x80138CB0: nop

    after_11:
    // 0x80138CB4: jal         0x80137698
    // 0x80138CB8: nop

    mnVSResultsInitVars(rdram, ctx);
        goto after_12;
    // 0x80138CB8: nop

    after_12:
    // 0x80138CBC: jal         0x80137454
    // 0x80138CC0: nop

    mnVSResultsSetIsPresent(rdram, ctx);
        goto after_13;
    // 0x80138CC0: nop

    after_13:
    // 0x80138CC4: jal         0x801373B4
    // 0x80138CC8: nop

    mnVSResultsInitRankings(rdram, ctx);
        goto after_14;
    // 0x80138CC8: nop

    after_14:
    // 0x80138CCC: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80138CD0: lbu         $t4, 0x4D10($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4D10);
    // 0x80138CD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80138CD8: bne         $t4, $at, L_80138CE8
    if (ctx->r12 != ctx->r1) {
        // 0x80138CDC: nop
    
            goto L_80138CE8;
    }
    // 0x80138CDC: nop

    // 0x80138CE0: jal         0x801386BC
    // 0x80138CE4: nop

    mnVSResultsUpdateAutoHandicap(rdram, ctx);
        goto after_15;
    // 0x80138CE4: nop

    after_15:
L_80138CE8:
    // 0x80138CE8: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80138CEC: lw          $t5, -0x63F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63F0);
    // 0x80138CF0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80138CF4: beq         $s0, $t5, L_80138D5C
    if (ctx->r16 == ctx->r13) {
        // 0x80138CF8: nop
    
            goto L_80138D5C;
    }
    // 0x80138CF8: nop

    // 0x80138CFC: jal         0x800D4404
    // 0x80138D00: nop

    lbTransitionSetupTransition(rdram, ctx);
        goto after_16;
    // 0x80138D00: nop

    after_16:
    // 0x80138D04: lui         $a0, 0x2000
    ctx->r4 = S32(0X2000 << 16);
    // 0x80138D08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80138D0C: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x80138D10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80138D14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80138D18: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80138D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138D20: jal         0x800D4130
    // 0x80138D24: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbTransitionMakeCamera(rdram, ctx);
        goto after_17;
    // 0x80138D24: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_17:
    // 0x80138D28: jal         0x80018994
    // 0x80138D2C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    syUtilsRandIntRange(rdram, ctx);
        goto after_18;
    // 0x80138D2C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_18:
    // 0x80138D30: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80138D34: addiu       $t9, $t9, 0x42C8
    ctx->r25 = ADD32(ctx->r25, 0X42C8);
    // 0x80138D38: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80138D3C: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80138D40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80138D44: addiu       $a3, $a3, 0x4248
    ctx->r7 = ADD32(ctx->r7, 0X4248);
    // 0x80138D48: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80138D4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80138D50: lui         $a1, 0x2000
    ctx->r5 = S32(0X2000 << 16);
    // 0x80138D54: jal         0x800D430C
    // 0x80138D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    lbTransitionMakeTransition(rdram, ctx);
        goto after_19;
    // 0x80138D58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
L_80138D5C:
    // 0x80138D5C: jal         0x801368D0
    // 0x80138D60: nop

    mnVSResultsMakeEmblemCamera(rdram, ctx);
        goto after_20;
    // 0x80138D60: nop

    after_20:
    // 0x80138D64: jal         0x801369B4
    // 0x80138D68: nop

    mnVSResultsMakeFighterCamera(rdram, ctx);
        goto after_21;
    // 0x80138D68: nop

    after_21:
    // 0x80138D6C: jal         0x80133E7C
    // 0x80138D70: nop

    mnVSResultsMakePlayerTagCamera(rdram, ctx);
        goto after_22;
    // 0x80138D70: nop

    after_22:
    // 0x80138D74: jal         0x801345E8
    // 0x80138D78: nop

    mnVSResultsMakeResultsTextCamera(rdram, ctx);
        goto after_23;
    // 0x80138D78: nop

    after_23:
    // 0x80138D7C: jal         0x80134DF4
    // 0x80138D80: nop

    mnVSResultsMakeTintCamera(rdram, ctx);
        goto after_24;
    // 0x80138D80: nop

    after_24:
    // 0x80138D84: jal         0x80136830
    // 0x80138D88: nop

    mnVSResultsMakeHeaderCamera(rdram, ctx);
        goto after_25;
    // 0x80138D88: nop

    after_25:
    // 0x80138D8C: jal         0x80135028
    // 0x80138D90: nop

    mnVSResultsMakeWallpaperTintCamera(rdram, ctx);
        goto after_26;
    // 0x80138D90: nop

    after_26:
    // 0x80138D94: jal         0x8013525C
    // 0x80138D98: nop

    mnVSResultsMakeWallpaperTint2Camera(rdram, ctx);
        goto after_27;
    // 0x80138D98: nop

    after_27:
    // 0x80138D9C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80138DA0: lw          $t0, -0x63F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63F0);
    // 0x80138DA4: beq         $s0, $t0, L_80138DB4
    if (ctx->r16 == ctx->r8) {
        // 0x80138DA8: nop
    
            goto L_80138DB4;
    }
    // 0x80138DA8: nop

    // 0x80138DAC: jal         0x80132B20
    // 0x80138DB0: nop

    mnVSResultsMakeEmblem(rdram, ctx);
        goto after_28;
    // 0x80138DB0: nop

    after_28:
L_80138DB4:
    // 0x80138DB4: jal         0x80134FD0
    // 0x80138DB8: nop

    mnVSResultsMakeWallpaperTint(rdram, ctx);
        goto after_29;
    // 0x80138DB8: nop

    after_29:
    // 0x80138DBC: jal         0x8013797C
    // 0x80138DC0: nop

    func_ovl31_8013797C(rdram, ctx);
        goto after_30;
    // 0x80138DC0: nop

    after_30:
    // 0x80138DC4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80138DC8: lw          $t1, -0x63F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X63F0);
    // 0x80138DCC: beql        $s0, $t1, L_80138E10
    if (ctx->r16 == ctx->r9) {
        // 0x80138DD0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80138E10;
    }
    goto skip_0;
    // 0x80138DD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x80138DD4: jal         0x8013234C
    // 0x80138DD8: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_31;
    // 0x80138DD8: nop

    after_31:
    // 0x80138DDC: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x80138DE0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80138DE4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80138DE8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80138DEC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80138DF0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80138DF4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80138DF8: lbu         $t3, 0x4D2A($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4D2A);
    // 0x80138DFC: bnel        $t3, $zero, L_80138E10
    if (ctx->r11 != 0) {
        // 0x80138E00: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80138E10;
    }
    goto skip_1;
    // 0x80138E00: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_1:
    // 0x80138E04: jal         0x80137938
    // 0x80138E08: nop

    func_ovl31_80137938(rdram, ctx);
        goto after_32;
    // 0x80138E08: nop

    after_32:
    // 0x80138E0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80138E10:
    // 0x80138E10: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80138E14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80138E18: lw          $t5, -0x63C0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63C0);
    // 0x80138E1C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80138E20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80138E24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80138E28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80138E2C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80138E30: jal         0x803904E0
    // 0x80138E34: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_33;
    // 0x80138E34: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_33:
    // 0x80138E38: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80138E3C: lw          $t6, -0x63F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63F0);
    // 0x80138E40: beql        $s0, $t6, L_80138E54
    if (ctx->r16 == ctx->r14) {
        // 0x80138E44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80138E54;
    }
    goto skip_2;
    // 0x80138E44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80138E48: jal         0x800269C0
    // 0x80138E4C: addiu       $a0, $zero, 0x26D
    ctx->r4 = ADD32(0, 0X26D);
    func_800269C0_275C0(rdram, ctx);
        goto after_34;
    // 0x80138E4C: addiu       $a0, $zero, 0x26D
    ctx->r4 = ADD32(0, 0X26D);
    after_34:
    // 0x80138E50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80138E54:
    // 0x80138E54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80138E58: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80138E5C: jr          $ra
    // 0x80138E60: nop

    return;
    // 0x80138E60: nop

;}
RECOMP_FUNC void mpCollisionUpdateBoundsDiff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBA84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FBA88: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    // 0x800FBA8C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FBA90: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FBA94: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800FBA98: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800FBA9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FBAA0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800FBAA4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800FBAA8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800FBAAC: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800FBAB0: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800FBAB4: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x800FBAB8: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x800FBABC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FBAC0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800FBAC4: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x800FBAC8: jr          $ra
    // 0x800FBACC: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x800FBACC: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void ftMainUpdateAbsorbStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3308: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E330C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E3310: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E3314: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E3318: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E331C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E3320: jal         0x80168128
    // 0x800E3324: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x800E3324: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E3328: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800E332C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E3330: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800E3334: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3338: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800E333C: jal         0x8016679C
    // 0x800E3340: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E3340: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x800E3344: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800E3348: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800E334C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800E3350: sw          $v1, 0x25C($v0)
    MEM_W(0X25C, ctx->r2) = ctx->r3;
    // 0x800E3354: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x800E3358: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x800E335C: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E3360: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E3364: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E3368: nop

    // 0x800E336C: bc1fl       L_800E338C
    if (!c1cs) {
        // 0x800E3370: lb          $t3, 0x18D($s0)
        ctx->r11 = MEM_B(ctx->r16, 0X18D);
            goto L_800E338C;
    }
    goto skip_0;
    // 0x800E3370: lb          $t3, 0x18D($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18D);
    skip_0:
    // 0x800E3374: lb          $t9, 0x18D($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X18D);
    // 0x800E3378: andi        $t0, $t9, 0xFF9F
    ctx->r8 = ctx->r25 & 0XFF9F;
    // 0x800E337C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x800E3380: b           L_800E3394
    // 0x800E3384: sb          $t1, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r9;
        goto L_800E3394;
    // 0x800E3384: sb          $t1, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r9;
    // 0x800E3388: lb          $t3, 0x18D($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18D);
L_800E338C:
    // 0x800E338C: ori         $t4, $t3, 0x60
    ctx->r12 = ctx->r11 | 0X60;
    // 0x800E3390: sb          $t4, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r12;
L_800E3394:
    // 0x800E3394: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800E3398: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800E339C: lbu         $t6, 0x48($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X48);
    // 0x800E33A0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800E33A4: bnel        $t7, $zero, L_800E3408
    if (ctx->r15 != 0) {
        // 0x800E33A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E3408;
    }
    goto skip_1;
    // 0x800E33A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800E33AC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800E33B0: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x800E33B4: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E33B8: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800E33BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800E33C0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800E33C4: nop

    // 0x800E33C8: subu        $v0, $t9, $t1
    ctx->r2 = SUB32(ctx->r25, ctx->r9);
    // 0x800E33CC: bgez        $v0, L_800E33DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E33D0: sw          $v0, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->r2;
            goto L_800E33DC;
    }
    // 0x800E33D0: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x800E33D4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x800E33D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E33DC:
    // 0x800E33DC: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x800E33E0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800E33E4: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x800E33E8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800E33EC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800E33F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800E33F4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800E33F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800E33FC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800E3400: sw          $v0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r2;
    // 0x800E3404: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E3408:
    // 0x800E3408: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E340C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E3410: jr          $ra
    // 0x800E3414: nop

    return;
    // 0x800E3414: nop

;}
RECOMP_FUNC void gcLinkGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007680: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80007684: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80007688: addiu       $t1, $t1, 0x6778
    ctx->r9 = ADD32(ctx->r9, 0X6778);
    // 0x8000768C: lw          $a3, 0x10($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X10);
    // 0x80007690: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80007694: lbu         $a1, 0xC($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0XC);
L_80007698:
    // 0x80007698: beq         $a2, $zero, L_800076E4
    if (ctx->r6 == 0) {
        // 0x8000769C: addiu       $t0, $a1, -0x1
        ctx->r8 = ADD32(ctx->r5, -0X1);
            goto L_800076E4;
    }
    // 0x8000769C: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x800076A0: lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1C);
L_800076A4:
    // 0x800076A4: beql        $v1, $zero, L_800076DC
    if (ctx->r3 == 0) {
        // 0x800076A8: lw          $a2, 0x8($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X8);
            goto L_800076DC;
    }
    goto skip_0;
    // 0x800076A8: lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x800076AC: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
L_800076B0:
    // 0x800076B0: bnel        $a3, $t6, L_800076D0
    if (ctx->r7 != ctx->r14) {
        // 0x800076B4: lw          $v1, 0x4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X4);
            goto L_800076D0;
    }
    goto skip_1;
    // 0x800076B4: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x800076B8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800076BC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800076C0: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x800076C4: b           L_8000771C
    // 0x800076C8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
        goto L_8000771C;
    // 0x800076C8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800076CC: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
L_800076D0:
    // 0x800076D0: bnel        $v1, $zero, L_800076B0
    if (ctx->r3 != 0) {
        // 0x800076D4: lw          $t6, 0x10($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X10);
            goto L_800076B0;
    }
    goto skip_2;
    // 0x800076D4: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x800076D8: lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X8);
L_800076DC:
    // 0x800076DC: bnel        $a2, $zero, L_800076A4
    if (ctx->r6 != 0) {
        // 0x800076E0: lw          $v1, 0x1C($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X1C);
            goto L_800076A4;
    }
    goto skip_3;
    // 0x800076E0: lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1C);
    skip_3:
L_800076E4:
    // 0x800076E4: beq         $a1, $zero, L_800076FC
    if (ctx->r5 == 0) {
        // 0x800076E8: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_800076FC;
    }
    // 0x800076E8: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800076EC: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x800076F0: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x800076F4: b           L_80007698
    // 0x800076F8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_80007698;
    // 0x800076F8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800076FC:
    // 0x800076FC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80007700: addiu       $t3, $t3, 0x66D0
    ctx->r11 = ADD32(ctx->r11, 0X66D0);
    // 0x80007704: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x80007708: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8000770C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80007710: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x80007714: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80007718: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_8000771C:
    // 0x8000771C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80007720: beql        $v1, $zero, L_80007730
    if (ctx->r3 == 0) {
        // 0x80007724: lw          $v1, 0x1C($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X1C);
            goto L_80007730;
    }
    goto skip_4;
    // 0x80007724: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    skip_4:
    // 0x80007728: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x8000772C: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
L_80007730:
    // 0x80007730: beql        $v1, $zero, L_80007744
    if (ctx->r3 == 0) {
        // 0x80007734: sw          $a0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r4;
            goto L_80007744;
    }
    goto skip_5;
    // 0x80007734: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    skip_5:
    // 0x80007738: b           L_80007744
    // 0x8000773C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80007744;
    // 0x8000773C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80007740: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
L_80007744:
    // 0x80007744: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x80007748: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000774C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80007750: jr          $ra
    // 0x80007754: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    return;
    // 0x80007754: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F188: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8015F18C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8015F190: addiu       $a3, $a3, -0x37C4
    ctx->r7 = ADD32(ctx->r7, -0X37C4);
    // 0x8015F194: jal         0x800E80A4
    // 0x8015F198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetCatchParams(rdram, ctx);
        goto after_0;
    // 0x8015F198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8015F19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F1A4: jr          $ra
    // 0x8015F1A8: nop

    return;
    // 0x8015F1A8: nop

;}
RECOMP_FUNC void mnVSOptionsInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133878: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013387C: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80133880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133884: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80133888: bne         $t6, $at, L_801338A0
    if (ctx->r14 != ctx->r1) {
        // 0x8013388C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801338A0;
    }
    // 0x8013388C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133890: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80133894: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133898: b           L_801338A8
    // 0x8013389C: sw          $t7, 0x48E0($at)
    MEM_W(0X48E0, ctx->r1) = ctx->r15;
        goto L_801338A8;
    // 0x8013389C: sw          $t7, 0x48E0($at)
    MEM_W(0X48E0, ctx->r1) = ctx->r15;
L_801338A0:
    // 0x801338A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338A4: sw          $zero, 0x48E0($at)
    MEM_W(0X48E0, ctx->r1) = 0;
L_801338A8:
    // 0x801338A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801338AC: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x801338B0: lbu         $t8, 0x8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8);
    // 0x801338B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338B8: sw          $t8, 0x48E4($at)
    MEM_W(0X48E4, ctx->r1) = ctx->r24;
    // 0x801338BC: lbu         $t9, 0x9($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X9);
    // 0x801338C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338C4: sw          $t9, 0x48E8($at)
    MEM_W(0X48E8, ctx->r1) = ctx->r25;
    // 0x801338C8: lbu         $t0, 0xA($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XA);
    // 0x801338CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338D0: sw          $t0, 0x48EC($at)
    MEM_W(0X48EC, ctx->r1) = ctx->r8;
    // 0x801338D4: lbu         $t1, 0xB($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XB);
    // 0x801338D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338DC: sw          $t1, 0x48F0($at)
    MEM_W(0X48F0, ctx->r1) = ctx->r9;
    // 0x801338E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338E4: jal         0x80131B24
    // 0x801338E8: sw          $zero, 0x48FC($at)
    MEM_W(0X48FC, ctx->r1) = 0;
    mnVSOptionsCheckHaveItemSwitch(rdram, ctx);
        goto after_0;
    // 0x801338E8: sw          $zero, 0x48FC($at)
    MEM_W(0X48FC, ctx->r1) = 0;
    after_0:
    // 0x801338EC: beq         $v0, $zero, L_80133910
    if (ctx->r2 == 0) {
        // 0x801338F0: addiu       $t6, $zero, 0x4650
        ctx->r14 = ADD32(0, 0X4650);
            goto L_80133910;
    }
    // 0x801338F0: addiu       $t6, $zero, 0x4650
    ctx->r14 = ADD32(0, 0X4650);
    // 0x801338F4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801338F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338FC: sw          $t2, 0x4900($at)
    MEM_W(0X4900, ctx->r1) = ctx->r10;
    // 0x80133900: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133904: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133908: b           L_80133924
    // 0x8013390C: sw          $t3, 0x4904($at)
    MEM_W(0X4904, ctx->r1) = ctx->r11;
        goto L_80133924;
    // 0x8013390C: sw          $t3, 0x4904($at)
    MEM_W(0X4904, ctx->r1) = ctx->r11;
L_80133910:
    // 0x80133910: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80133914: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133918: sw          $t4, 0x4900($at)
    MEM_W(0X4900, ctx->r1) = ctx->r12;
    // 0x8013391C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133920: sw          $zero, 0x4904($at)
    MEM_W(0X4904, ctx->r1) = 0;
L_80133924:
    // 0x80133924: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013392C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133930: sw          $zero, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = 0;
    // 0x80133934: addiu       $v0, $v0, 0x490C
    ctx->r2 = ADD32(ctx->r2, 0X490C);
    // 0x80133938: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8013393C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133940: sw          $t6, 0x4910($at)
    MEM_W(0X4910, ctx->r1) = ctx->r14;
    // 0x80133944: jr          $ra
    // 0x80133948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80133948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnOptionMakeSoundUnderline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801329F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801329FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A04: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132A08: jal         0x80009968
    // 0x80132A0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132A0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A14: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132A18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A1C: addiu       $a1, $a1, 0x27D4
    ctx->r5 = ADD32(ctx->r5, 0X27D4);
    // 0x80132A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A24: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132A28: jal         0x80009DF4
    // 0x80132A2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132A2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132A38: jr          $ra
    // 0x80132A3C: nop

    return;
    // 0x80132A3C: nop

;}
RECOMP_FUNC void ftCommonEscapeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801491D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801491D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801491D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801491DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801491E0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801491E4: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x801491E8: beql        $t6, $zero, L_80149204
    if (ctx->r14 == 0) {
        // 0x801491EC: lwc1        $f4, 0x78($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
            goto L_80149204;
    }
    goto skip_0;
    // 0x801491EC: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    skip_0:
    // 0x801491F0: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x801491F4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x801491F8: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x801491FC: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x80149200: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
L_80149204:
    // 0x80149204: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80149208: nop

    // 0x8014920C: bc1fl       L_8014925C
    if (!c1cs) {
        // 0x80149210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014925C;
    }
    goto skip_1;
    // 0x80149210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80149214: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80149218: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x8014921C: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80149220: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80149224: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x80149228: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x8014922C: beq         $v1, $at, L_80149240
    if (ctx->r3 == ctx->r1) {
        // 0x80149230: swc1        $f0, 0x60($v0)
        MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
            goto L_80149240;
    }
    // 0x80149230: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80149234: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80149238: bne         $v1, $at, L_80149250
    if (ctx->r3 != ctx->r1) {
        // 0x8014923C: nop
    
            goto L_80149250;
    }
    // 0x8014923C: nop

L_80149240:
    // 0x80149240: jal         0x80148F24
    // 0x80149244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonGuardCheckInterruptEscape(rdram, ctx);
        goto after_0;
    // 0x80149244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80149248: bne         $v0, $zero, L_80149258
    if (ctx->r2 != 0) {
        // 0x8014924C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80149258;
    }
    // 0x8014924C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80149250:
    // 0x80149250: jal         0x8013E1C8
    // 0x80149254: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149254: nop

    after_1:
L_80149258:
    // 0x80149258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014925C:
    // 0x8014925C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149260: jr          $ra
    // 0x80149264: nop

    return;
    // 0x80149264: nop

;}

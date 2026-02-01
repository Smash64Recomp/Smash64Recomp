#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftParamGetHitLag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA1C0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800EA1C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA1C8: lwc1        $f8, -0xB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XB0);
    // 0x800EA1CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EA1D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800EA1D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800EA1D8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EA1DC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800EA1E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EA1E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EA1E8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800EA1EC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800EA1F0: nop

    // 0x800EA1F4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800EA1F8: nop

    // 0x800EA1FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EA200: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EA204: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800EA208: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800EA20C: beq         $a1, $at, L_800EA220
    if (ctx->r5 == ctx->r1) {
        // 0x800EA210: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800EA220;
    }
    // 0x800EA210: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EA214: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800EA218: bne         $a1, $at, L_800EA240
    if (ctx->r5 != ctx->r1) {
        // 0x800EA21C: nop
    
            goto L_800EA240;
    }
    // 0x800EA21C: nop

L_800EA220:
    // 0x800EA220: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800EA224: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA228: lwc1        $f6, -0xAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XAC);
    // 0x800EA22C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800EA230: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800EA234: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800EA238: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800EA23C: nop

L_800EA240:
    // 0x800EA240: jr          $ra
    // 0x800EA244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EA244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameGetPrevTimeValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138134: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80138138: bne         $a0, $at, L_80138148
    if (ctx->r4 != ctx->r1) {
        // 0x8013813C: addiu       $v1, $zero, 0x5
        ctx->r3 = ADD32(0, 0X5);
            goto L_80138148;
    }
    // 0x8013813C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80138140: jr          $ra
    // 0x80138144: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    return;
    // 0x80138144: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_80138148:
    // 0x80138148: jr          $ra
    // 0x8013814C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013814C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void grInishieScaleUpdateRetract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010929C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801092A0: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801092A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801092A8: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801092AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801092B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801092B4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x801092B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801092BC: bc1tl       L_80109330
    if (c1cs) {
        // 0x801092C0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80109330;
    }
    goto skip_0;
    // 0x801092C0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x801092C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801092C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801092CC: bc1fl       L_80109308
    if (!c1cs) {
        // 0x801092D0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80109308;
    }
    goto skip_1;
    // 0x801092D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x801092D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801092D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801092DC: nop

    // 0x801092E0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801092E4: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x801092E8: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801092EC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801092F0: nop

    // 0x801092F4: bc1fl       L_80109330
    if (!c1cs) {
        // 0x801092F8: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80109330;
    }
    goto skip_2;
    // 0x801092F8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x801092FC: b           L_8010932C
    // 0x80109300: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8010932C;
    // 0x80109300: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80109304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80109308:
    // 0x80109308: nop

    // 0x8010930C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80109310: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80109314: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80109318: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8010931C: nop

    // 0x80109320: bc1fl       L_80109330
    if (!c1cs) {
        // 0x80109324: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_80109330;
    }
    goto skip_3;
    // 0x80109324: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_3:
    // 0x80109328: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8010932C:
    // 0x8010932C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_80109330:
    // 0x80109330: beq         $a0, $zero, L_80109398
    if (ctx->r4 == 0) {
        // 0x80109334: lw          $a1, 0x18($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X18);
            goto L_80109398;
    }
    // 0x80109334: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x80109338: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x8010933C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109340: lwc1        $f16, 0xB4C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XB4C);
    // 0x80109344: sb          $zero, 0x54($v1)
    MEM_B(0X54, ctx->r3) = 0;
    // 0x80109348: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010934C: swc1        $f16, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f16.u32l;
    // 0x80109350: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80109354: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80109358: jal         0x800FC58C
    // 0x8010935C: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_0;
    // 0x8010935C: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    after_0:
    // 0x80109360: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80109364: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109368: lwc1        $f18, 0xB50($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XB50);
    // 0x8010936C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80109370: sb          $zero, 0x54($a1)
    MEM_B(0X54, ctx->r5) = 0;
    // 0x80109374: swc1        $f18, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f18.u32l;
    // 0x80109378: jal         0x800FC58C
    // 0x8010937C: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_1;
    // 0x8010937C: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    after_1:
    // 0x80109380: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109384: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109388: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010938C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80109390: sb          $zero, 0x32($v0)
    MEM_B(0X32, ctx->r2) = 0;
    // 0x80109394: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
L_80109398:
    // 0x80109398: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8010939C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801093A0: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x801093A4: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801093A8: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801093AC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801093B0: swc1        $f16, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f16.u32l;
    // 0x801093B4: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801093B8: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801093BC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801093C0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801093C4: swc1        $f6, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f6.u32l;
    // 0x801093C8: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801093CC: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801093D0: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x801093D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801093D8: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x801093DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801093E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801093E4: jr          $ra
    // 0x801093E8: nop

    return;
    // 0x801093E8: nop

;}
RECOMP_FUNC void syAudioInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F44C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001F450: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001F454: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8001F458: addiu       $a2, $a2, -0x2CC0
    ctx->r6 = ADD32(ctx->r6, -0X2CC0);
    // 0x8001F45C: addiu       $a1, $a1, -0x2D08
    ctx->r5 = ADD32(ctx->r5, -0X2D08);
    // 0x8001F460: addiu       $a0, $a0, -0x2D10
    ctx->r4 = ADD32(ctx->r4, -0X2D10);
    // 0x8001F464: jal         0x800009D8
    // 0x8001F468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sySchedulerAddClient(rdram, ctx);
        goto after_0;
    // 0x8001F468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8001F46C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001F470: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001F474: addiu       $a1, $a1, -0x2CB8
    ctx->r5 = ADD32(ctx->r5, -0X2CB8);
    // 0x8001F478: addiu       $a0, $a0, -0x2CD8
    ctx->r4 = ADD32(ctx->r4, -0X2CD8);
    // 0x8001F47C: jal         0x80034480
    // 0x8001F480: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8001F480: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_1:
    // 0x8001F484: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001F488: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001F48C: addiu       $a1, $a1, -0x2CBC
    ctx->r5 = ADD32(ctx->r5, -0X2CBC);
    // 0x8001F490: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8001F494: jal         0x80034480
    // 0x8001F498: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8001F498: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8001F49C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001F4A0: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8001F4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F4A8: jal         0x80030000
    // 0x8001F4AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8001F4AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8001F4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F4B8: jr          $ra
    // 0x8001F4BC: nop

    return;
    // 0x8001F4BC: nop

;}
RECOMP_FUNC void ftCommonDokanEndUpdatePlayerTag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142668: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014266C: lw          $v1, 0xB3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB3C);
    // 0x80142670: beq         $v1, $zero, L_80142688
    if (ctx->r3 == 0) {
        // 0x80142674: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80142688;
    }
    // 0x80142674: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80142678: bne         $t6, $zero, L_80142688
    if (ctx->r14 != 0) {
        // 0x8014267C: sw          $t6, 0xB3C($v0)
        MEM_W(0XB3C, ctx->r2) = ctx->r14;
            goto L_80142688;
    }
    // 0x8014267C: sw          $t6, 0xB3C($v0)
    MEM_W(0XB3C, ctx->r2) = ctx->r14;
    // 0x80142680: jal         0x800E7F7C
    // 0x80142684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_0;
    // 0x80142684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_80142688:
    // 0x80142688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014268C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142690: jr          $ra
    // 0x80142694: nop

    return;
    // 0x80142694: nop

;}
RECOMP_FUNC void func_ovl8_80387154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387154: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80387158: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x8038715C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80387160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80387164: sltu        $t4, $zero, $t4
    ctx->r12 = 0 < ctx->r12 ? 1 : 0;
    // 0x80387168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038716C: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x80387170: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x80387174: beq         $t4, $zero, L_80387184
    if (ctx->r12 == 0) {
        // 0x80387178: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80387184;
    }
    // 0x80387178: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8038717C: b           L_80387188
    // 0x80387180: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
        goto L_80387188;
    // 0x80387180: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
L_80387184:
    // 0x80387184: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
L_80387188:
    // 0x80387188: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8038718C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80387190: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80387194: bne         $v0, $at, L_803871B4
    if (ctx->r2 != ctx->r1) {
        // 0x80387198: lw          $t6, 0xBC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XBC);
            goto L_803871B4;
    }
    // 0x80387198: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8038719C: beql        $t6, $zero, L_803871B8
    if (ctx->r14 == 0) {
        // 0x803871A0: addiu       $t2, $zero, 0x20
        ctx->r10 = ADD32(0, 0X20);
            goto L_803871B8;
    }
    goto skip_0;
    // 0x803871A0: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    skip_0:
    // 0x803871A4: beql        $t4, $zero, L_803871B8
    if (ctx->r12 == 0) {
        // 0x803871A8: addiu       $t2, $zero, 0x20
        ctx->r10 = ADD32(0, 0X20);
            goto L_803871B8;
    }
    goto skip_1;
    // 0x803871A8: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    skip_1:
    // 0x803871AC: b           L_803871B8
    // 0x803871B0: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
        goto L_803871B8;
    // 0x803871B0: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
L_803871B4:
    // 0x803871B4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
L_803871B8:
    // 0x803871B8: bne         $v0, $zero, L_8038723C
    if (ctx->r2 != 0) {
        // 0x803871BC: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8038723C;
    }
    // 0x803871BC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x803871C0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x803871C4: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x803871C8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x803871CC: bgtzl       $t8, L_80387204
    if (SIGNED(ctx->r24) > 0) {
        // 0x803871D0: lw          $a2, 0xB0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB0);
            goto L_80387204;
    }
    goto skip_2;
    // 0x803871D0: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    skip_2:
    // 0x803871D4: bltz        $t8, L_803871E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x803871D8: sltiu       $at, $t9, 0x1
        ctx->r1 = ctx->r25 < 0X1 ? 1 : 0;
            goto L_803871E4;
    }
    // 0x803871D8: sltiu       $at, $t9, 0x1
    ctx->r1 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x803871DC: b           L_80387204
    // 0x803871E0: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
        goto L_80387204;
    // 0x803871E0: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
L_803871E4:
    // 0x803871E4: nor         $t6, $t8, $zero
    ctx->r14 = ~(ctx->r24 | 0);
    // 0x803871E8: addu        $t6, $t6, $at
    ctx->r14 = ADD32(ctx->r14, ctx->r1);
    // 0x803871EC: negu        $t7, $t9
    ctx->r15 = SUB32(0, ctx->r25);
    // 0x803871F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x803871F4: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x803871F8: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x803871FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80387200: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
L_80387204:
    // 0x80387204: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80387208: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x8038720C: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x80387210: sb          $t2, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r10;
    // 0x80387214: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x80387218: jal         0x8038746C
    // 0x8038721C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    stringFromNumber(rdram, ctx);
        goto after_0;
    // 0x8038721C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x80387220: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80387224: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80387228: lbu         $t2, 0x3C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3C);
    // 0x8038722C: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x80387230: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80387234: b           L_803872B0
    // 0x80387238: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_803872B0;
    // 0x80387238: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8038723C:
    // 0x8038723C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80387240: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80387244: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80387248: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8038724C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80387250: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80387254: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80387258: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8038725C: nop

    // 0x80387260: bc1fl       L_8038727C
    if (!c1cs) {
        // 0x80387264: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_8038727C;
    }
    goto skip_3;
    // 0x80387264: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    skip_3:
    // 0x80387268: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8038726C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80387270: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80387274: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80387278: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_8038727C:
    // 0x8038727C: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x80387280: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x80387284: sw          $t1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r9;
    // 0x80387288: sb          $t2, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r10;
    // 0x8038728C: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x80387290: jal         0x80387540
    // 0x80387294: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    func_ovl8_80387540(rdram, ctx);
        goto after_1;
    // 0x80387294: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_1:
    // 0x80387298: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8038729C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x803872A0: lbu         $t2, 0x3C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3C);
    // 0x803872A4: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x803872A8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x803872AC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_803872B0:
    // 0x803872B0: beq         $t3, $zero, L_803872CC
    if (ctx->r11 == 0) {
        // 0x803872B4: addu        $t1, $t1, $v0
        ctx->r9 = ADD32(ctx->r9, ctx->r2);
            goto L_803872CC;
    }
    // 0x803872B4: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x803872B8: beq         $t4, $zero, L_803872CC
    if (ctx->r12 == 0) {
        // 0x803872BC: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_803872CC;
    }
    // 0x803872BC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803872C0: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x803872C4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x803872C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_803872CC:
    // 0x803872CC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x803872D0: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x803872D4: bne         $t7, $zero, L_80387340
    if (ctx->r15 != 0) {
        // 0x803872D8: subu        $a2, $t5, $t1
        ctx->r6 = SUB32(ctx->r13, ctx->r9);
            goto L_80387340;
    }
    // 0x803872D8: subu        $a2, $t5, $t1
    ctx->r6 = SUB32(ctx->r13, ctx->r9);
    // 0x803872DC: blez        $a2, L_80387340
    if (SIGNED(ctx->r6) <= 0) {
        // 0x803872E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80387340;
    }
    // 0x803872E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x803872E4: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x803872E8: beq         $v1, $zero, L_80387308
    if (ctx->r3 == 0) {
        // 0x803872EC: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80387308;
    }
    // 0x803872EC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_803872F0:
    // 0x803872F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803872F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803872F8: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x803872FC: bne         $a1, $a0, L_803872F0
    if (ctx->r5 != ctx->r4) {
        // 0x80387300: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803872F0;
    }
    // 0x80387300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387304: beq         $a0, $a2, L_80387340
    if (ctx->r4 == ctx->r6) {
        // 0x80387308: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80387340;
    }
L_80387308:
    // 0x80387308: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8038730C: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80387310: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387314: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387318: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x8038731C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387320: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387324: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80387328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8038732C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387330: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80387334: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80387338: bne         $a0, $a2, L_80387308
    if (ctx->r4 != ctx->r6) {
        // 0x8038733C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80387308;
    }
    // 0x8038733C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80387340:
    // 0x80387340: beq         $t3, $zero, L_8038735C
    if (ctx->r11 == 0) {
        // 0x80387344: lw          $t5, 0xC4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XC4);
            goto L_8038735C;
    }
    // 0x80387344: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80387348: bne         $t4, $zero, L_8038735C
    if (ctx->r12 != 0) {
        // 0x8038734C: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8038735C;
    }
    // 0x8038734C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80387350: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80387354: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80387358: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8038735C:
    // 0x8038735C: blez        $v0, L_8038737C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80387360: addiu       $v1, $sp, 0x4C
        ctx->r3 = ADD32(ctx->r29, 0X4C);
            goto L_8038737C;
    }
    // 0x80387360: addiu       $v1, $sp, 0x4C
    ctx->r3 = ADD32(ctx->r29, 0X4C);
L_80387364:
    // 0x80387364: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80387368: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8038736C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80387370: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80387374: bgtz        $a3, L_80387364
    if (SIGNED(ctx->r7) > 0) {
        // 0x80387378: sb          $t9, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r25;
            goto L_80387364;
    }
    // 0x80387378: sb          $t9, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r25;
L_8038737C:
    // 0x8038737C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x80387380: subu        $a2, $t5, $t1
    ctx->r6 = SUB32(ctx->r13, ctx->r9);
    // 0x80387384: slt         $at, $t5, $t1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80387388: beq         $t6, $zero, L_803873FC
    if (ctx->r14 == 0) {
        // 0x8038738C: nop
    
            goto L_803873FC;
    }
    // 0x8038738C: nop

    // 0x80387390: blez        $a2, L_803873FC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80387394: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_803873FC;
    }
    // 0x80387394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80387398: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x8038739C: beq         $v1, $zero, L_803873C0
    if (ctx->r3 == 0) {
        // 0x803873A0: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_803873C0;
    }
    // 0x803873A0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x803873A4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_803873A8:
    // 0x803873A8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803873AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803873B0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x803873B4: bne         $a1, $a0, L_803873A8
    if (ctx->r5 != ctx->r4) {
        // 0x803873B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803873A8;
    }
    // 0x803873B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803873BC: beq         $a0, $a2, L_803873FC
    if (ctx->r4 == ctx->r6) {
        // 0x803873C0: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_803873FC;
    }
L_803873C0:
    // 0x803873C0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_803873C4:
    // 0x803873C4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803873C8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x803873CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803873D0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803873D4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x803873D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803873DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803873E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x803873E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803873E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x803873EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x803873F0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x803873F4: bne         $a0, $a2, L_803873C4
    if (ctx->r4 != ctx->r6) {
        // 0x803873F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803873C4;
    }
    // 0x803873F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_803873FC:
    // 0x803873FC: beq         $at, $zero, L_8038740C
    if (ctx->r1 == 0) {
        // 0x80387400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8038740C;
    }
    // 0x80387400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80387404: b           L_80387410
    // 0x80387408: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
        goto L_80387410;
    // 0x80387408: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8038740C:
    // 0x8038740C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80387410:
    // 0x80387410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80387414: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x80387418: jr          $ra
    // 0x8038741C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8038741C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itFFlowerShootFlame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017604C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80176050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176054: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80176058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017605C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80176060: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80176064: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80176068: lw          $t0, -0x639C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X639C);
    // 0x8017606C: lw          $t8, 0x84C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84C);
    // 0x80176070: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80176074: addiu       $t2, $t2, 0x360
    ctx->r10 = ADD32(ctx->r10, 0X360);
    // 0x80176078: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8017607C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80176080: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80176084: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80176088: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8017608C: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x80176090: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80176094: jal         0x80035CD0
    // 0x80176098: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x80176098: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017609C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801760A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801760A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801760A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801760AC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801760B0: jal         0x800303F0
    // 0x801760B4: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801760B4: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x801760B8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801760BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801760C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801760C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801760C8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801760CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801760D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x801760D4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801760D8: jal         0x80175F48
    // 0x801760DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    itFFlowerWeaponFlameMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x801760DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801760E0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x801760E4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801760E8: lhu         $t4, 0x33E($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X33E);
    // 0x801760EC: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x801760F0: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x801760F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801760F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801760FC: jr          $ra
    // 0x80176100: nop

    return;
    // 0x80176100: nop

;}
RECOMP_FUNC void ftCommonLightThrowCheckInterruptEscape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146B64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80146B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146B6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80146B70: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80146B74: jal         0x80146A8C
    // 0x80146B78: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x80146B78: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80146B7C: beq         $v0, $zero, L_80146BBC
    if (ctx->r2 == 0) {
        // 0x80146B80: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80146BBC;
    }
    // 0x80146B80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80146B84: lw          $t7, 0xB18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB18);
    // 0x80146B88: beql        $t7, $zero, L_80146BC0
    if (ctx->r15 == 0) {
        // 0x80146B8C: lw          $v0, 0xB18($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XB18);
            goto L_80146BC0;
    }
    goto skip_0;
    // 0x80146B8C: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    skip_0:
    // 0x80146B90: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80146B94: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x80146B98: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80146B9C: bne         $t8, $at, L_80146BAC
    if (ctx->r24 != ctx->r1) {
        // 0x80146BA0: nop
    
            goto L_80146BAC;
    }
    // 0x80146BA0: nop

    // 0x80146BA4: b           L_80146BAC
    // 0x80146BA8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
        goto L_80146BAC;
    // 0x80146BA8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
L_80146BAC:
    // 0x80146BAC: jal         0x80146690
    // 0x80146BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x80146BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80146BB4: b           L_80146BD0
    // 0x80146BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80146BD0;
    // 0x80146BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80146BBC:
    // 0x80146BBC: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
L_80146BC0:
    // 0x80146BC0: beq         $v0, $zero, L_80146BCC
    if (ctx->r2 == 0) {
        // 0x80146BC4: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80146BCC;
    }
    // 0x80146BC4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80146BC8: sw          $t9, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r25;
L_80146BCC:
    // 0x80146BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146BD0:
    // 0x80146BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146BD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146BD8: jr          $ra
    // 0x80146BDC: nop

    return;
    // 0x80146BDC: nop

;}
RECOMP_FUNC void itGShellFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017893C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80178940: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80178944: sw          $zero, 0x248($a0)
    MEM_W(0X248, ctx->r4) = 0;
    // 0x80178948: sw          $zero, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = 0;
    // 0x8017894C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80178950: jal         0x80173F78
    // 0x80178954: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80178954: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80178958: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017895C: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178960: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80178964: jal         0x80172EC8
    // 0x80178968: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80178968: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017896C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178974: jr          $ra
    // 0x80178978: nop

    return;
    // 0x80178978: nop

;}
RECOMP_FUNC void wpSamusBombProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169108: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016910C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80169110: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80169114: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80169118: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x8016911C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80169124: lw          $t6, 0xFC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XFC);
    // 0x80169128: bne         $t6, $at, L_801691CC
    if (ctx->r14 != ctx->r1) {
        // 0x8016912C: nop
    
            goto L_801691CC;
    }
    // 0x8016912C: nop

    // 0x80169130: jal         0x80167B58
    // 0x80169134: nop

    wpMapTestAllCheckFloor(rdram, ctx);
        goto after_0;
    // 0x80169134: nop

    after_0:
    // 0x80169138: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8016913C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80169140: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80169144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80169148: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x8016914C: jal         0x80167C38
    // 0x80169150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    wpMapCheckAllRebound(rdram, ctx);
        goto after_1;
    // 0x80169150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80169154: beql        $v0, $zero, L_80169168
    if (ctx->r2 == 0) {
        // 0x80169158: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80169168;
    }
    goto skip_0;
    // 0x80169158: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8016915C: jal         0x80167F68
    // 0x80169160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainVelSetLR(rdram, ctx);
        goto after_2;
    // 0x80169160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80169164: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80169168:
    // 0x80169168: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    // 0x8016916C: addiu       $a1, $s1, 0xAC
    ctx->r5 = ADD32(ctx->r17, 0XAC);
    // 0x80169170: beql        $t7, $zero, L_801691E8
    if (ctx->r15 == 0) {
        // 0x80169174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801691E8;
    }
    goto skip_1;
    // 0x80169174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80169178: jal         0x800C7B08
    // 0x8016917C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x8016917C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80169180: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80169184: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80169188: jal         0x800C7AE0
    // 0x8016918C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonScale2D(rdram, ctx);
        goto after_4;
    // 0x8016918C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80169190: jal         0x80167F68
    // 0x80169194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainVelSetLR(rdram, ctx);
        goto after_5;
    // 0x80169194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80169198: jal         0x800C7A84
    // 0x8016919C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonMag2D(rdram, ctx);
        goto after_6;
    // 0x8016919C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x801691A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801691A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801691A8: nop

    // 0x801691AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801691B0: nop

    // 0x801691B4: bc1fl       L_801691E8
    if (!c1cs) {
        // 0x801691B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801691E8;
    }
    goto skip_2;
    // 0x801691B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801691BC: jal         0x80167E78
    // 0x801691C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wpMapSetGround(rdram, ctx);
        goto after_7;
    // 0x801691C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801691C4: b           L_801691E8
    // 0x801691C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801691E8;
    // 0x801691C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801691CC:
    // 0x801691CC: jal         0x8016796C
    // 0x801691D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMapTestLRWallCheckFloor(rdram, ctx);
        goto after_8;
    // 0x801691D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801691D4: bnel        $v0, $zero, L_801691E8
    if (ctx->r2 != 0) {
        // 0x801691D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801691E8;
    }
    goto skip_3;
    // 0x801691D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801691DC: jal         0x80167E9C
    // 0x801691E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wpMapSetAir(rdram, ctx);
        goto after_9;
    // 0x801691E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x801691E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801691E8:
    // 0x801691E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801691EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801691F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801691F4: jr          $ra
    // 0x801691F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801691F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameCheckStockArrowPress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136A8C: jal         0x801368FC
    // 0x80136A90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayers1PGameCheckStockArrowRInRange(rdram, ctx);
        goto after_0;
    // 0x80136A90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80136A94: beq         $v0, $zero, L_80136AE0
    if (ctx->r2 == 0) {
        // 0x80136A98: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80136AE0;
    }
    // 0x80136A98: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136A9C: addiu       $v1, $v1, -0x7048
    ctx->r3 = ADD32(ctx->r3, -0X7048);
    // 0x80136AA0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80136AA4: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80136AA8: beq         $at, $zero, L_80136AD8
    if (ctx->r1 == 0) {
        // 0x80136AAC: nop
    
            goto L_80136AD8;
    }
    // 0x80136AAC: nop

    // 0x80136AB0: jal         0x800269C0
    // 0x80136AB4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80136AB4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_1:
    // 0x80136AB8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136ABC: addiu       $v1, $v1, -0x7048
    ctx->r3 = ADD32(ctx->r3, -0X7048);
    // 0x80136AC0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80136AC4: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80136AC8: addiu       $a0, $t7, 0x1
    ctx->r4 = ADD32(ctx->r15, 0X1);
    // 0x80136ACC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80136AD0: jal         0x8013419C
    // 0x80136AD4: lw          $a1, -0x70F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X70F8);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_2;
    // 0x80136AD4: lw          $a1, -0x70F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X70F8);
    after_2:
L_80136AD8:
    // 0x80136AD8: b           L_80136B34
    // 0x80136ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136B34;
    // 0x80136ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136AE0:
    // 0x80136AE0: jal         0x801369C0
    // 0x80136AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameCheckStockArrowLInRange(rdram, ctx);
        goto after_3;
    // 0x80136AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80136AE8: beq         $v0, $zero, L_80136B30
    if (ctx->r2 == 0) {
        // 0x80136AEC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80136B30;
    }
    // 0x80136AEC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136AF0: addiu       $v1, $v1, -0x7048
    ctx->r3 = ADD32(ctx->r3, -0X7048);
    // 0x80136AF4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80136AF8: blez        $t9, L_80136B28
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80136AFC: nop
    
            goto L_80136B28;
    }
    // 0x80136AFC: nop

    // 0x80136B00: jal         0x800269C0
    // 0x80136B04: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80136B04: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_4:
    // 0x80136B08: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136B0C: addiu       $v1, $v1, -0x7048
    ctx->r3 = ADD32(ctx->r3, -0X7048);
    // 0x80136B10: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80136B14: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80136B18: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // 0x80136B1C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80136B20: jal         0x8013419C
    // 0x80136B24: lw          $a1, -0x70F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X70F8);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_5;
    // 0x80136B24: lw          $a1, -0x70F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X70F8);
    after_5:
L_80136B28:
    // 0x80136B28: b           L_80136B34
    // 0x80136B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136B34;
    // 0x80136B2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136B30:
    // 0x80136B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136B34:
    // 0x80136B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136B3C: jr          $ra
    // 0x80136B40: nop

    return;
    // 0x80136B40: nop

;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035420: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80035424: jr          $ra
    // 0x80035428: lw          $v0, -0x2C44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2C44);
    return;
    // 0x80035428: lw          $v0, -0x2C44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2C44);
;}
RECOMP_FUNC void __postNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002DC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DC78: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8002DC7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DC80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002DC84: bne         $t6, $at, L_8002DD3C
    if (ctx->r14 != ctx->r1) {
        // 0x8002DC88: lw          $a2, 0x18($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X18);
            goto L_8002DD3C;
    }
    // 0x8002DC88: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x8002DC8C: beq         $a2, $zero, L_8002DD3C
    if (ctx->r6 == 0) {
        // 0x8002DC90: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8002DD3C;
    }
    // 0x8002DC90: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002DC94: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8002DC98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002DC9C: jal         0x8002F9FC
    // 0x8002DCA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    __alSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x8002DCA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8002DCA4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002DCA8: beq         $v0, $zero, L_8002DD3C
    if (ctx->r2 == 0) {
        // 0x8002DCAC: lw          $a3, 0x38($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X38);
            goto L_8002DD3C;
    }
    // 0x8002DCAC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8002DCB0: lw          $t7, 0x90($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X90);
    // 0x8002DCB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002DCB8: beql        $t7, $zero, L_8002DD1C
    if (ctx->r15 == 0) {
        // 0x8002DCBC: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_8002DD1C;
    }
    goto skip_0;
    // 0x8002DCBC: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_0:
    // 0x8002DCC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002DCC4: jal         0x8002F6FC
    // 0x8002DCC8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqGetTicks(rdram, ctx);
        goto after_1;
    // 0x8002DCC8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8002DCCC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8002DCD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002DCD4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002DCD8: lw          $t0, 0x8C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8C);
    // 0x8002DCDC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8002DCE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002DCE4: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8002DCE8: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002DCEC: bnel        $at, $zero, L_8002DD1C
    if (ctx->r1 != 0) {
        // 0x8002DCF0: sh          $zero, 0x28($sp)
        MEM_H(0X28, ctx->r29) = 0;
            goto L_8002DD1C;
    }
    goto skip_1;
    // 0x8002DCF0: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    skip_1:
    // 0x8002DCF4: lw          $a1, 0x88($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X88);
    // 0x8002DCF8: jal         0x8002F6E0
    // 0x8002DCFC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    alSeqSetLoc(rdram, ctx);
        goto after_2;
    // 0x8002DCFC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8002DD00: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8002DD04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002DD08: lw          $v0, 0x90($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X90);
    // 0x8002DD0C: beq         $v0, $at, L_8002DD18
    if (ctx->r2 == ctx->r1) {
        // 0x8002DD10: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8002DD18;
    }
    // 0x8002DD10: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8002DD14: sw          $t2, 0x90($a3)
    MEM_W(0X90, ctx->r7) = ctx->r10;
L_8002DD18:
    // 0x8002DD18: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
L_8002DD1C:
    // 0x8002DD1C: lw          $t3, 0x2C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X2C);
    // 0x8002DD20: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002DD24: addiu       $a0, $a3, 0x50
    ctx->r4 = ADD32(ctx->r7, 0X50);
    // 0x8002DD28: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8002DD2C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DD30: mflo        $a2
    ctx->r6 = lo;
    // 0x8002DD34: jal         0x80028D70
    // 0x8002DD38: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x8002DD38: nop

    after_3:
L_8002DD3C:
    // 0x8002DD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DD40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002DD44: jr          $ra
    // 0x8002DD48: nop

    return;
    // 0x8002DD48: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckStockArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801368FC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80136900: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80136904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136908: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013690C: lui         $at, 0x4381
    ctx->r1 = S32(0X4381 << 16);
    // 0x80136910: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136914: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80136918: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8013691C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136920: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80136924: nop

    // 0x80136928: bc1f        L_80136950
    if (!c1cs) {
        // 0x8013692C: nop
    
            goto L_80136950;
    }
    // 0x8013692C: nop

    // 0x80136930: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80136934: nop

    // 0x80136938: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8013693C: nop

    // 0x80136940: bc1f        L_80136950
    if (!c1cs) {
        // 0x80136944: nop
    
            goto L_80136950;
    }
    // 0x80136944: nop

    // 0x80136948: b           L_80136950
    // 0x8013694C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136950;
    // 0x8013694C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136950:
    // 0x80136950: beq         $v1, $zero, L_801369B4
    if (ctx->r3 == 0) {
        // 0x80136954: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801369B4;
    }
    // 0x80136954: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80136958: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013695C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136960: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80136964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136968: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8013696C: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80136970: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136974: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80136978: nop

    // 0x8013697C: bc1f        L_801369A4
    if (!c1cs) {
        // 0x80136980: nop
    
            goto L_801369A4;
    }
    // 0x80136980: nop

    // 0x80136984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136988: nop

    // 0x8013698C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80136990: nop

    // 0x80136994: bc1f        L_801369A4
    if (!c1cs) {
        // 0x80136998: nop
    
            goto L_801369A4;
    }
    // 0x80136998: nop

    // 0x8013699C: b           L_801369A4
    // 0x801369A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801369A4;
    // 0x801369A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801369A4:
    // 0x801369A4: beql        $v1, $zero, L_801369B8
    if (ctx->r3 == 0) {
        // 0x801369A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801369B8;
    }
    goto skip_0;
    // 0x801369A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801369AC: jr          $ra
    // 0x801369B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801369B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801369B4:
    // 0x801369B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801369B8:
    // 0x801369B8: jr          $ra
    // 0x801369BC: nop

    return;
    // 0x801369BC: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154488: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015448C: jal         0x800DEE98
    // 0x80154490: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80154490: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80154494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154498: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x8015449C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x801544A0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801544A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801544A8: jal         0x800E6F24
    // 0x801544AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801544AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801544B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801544B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801544B8: jr          $ra
    // 0x801544BC: nop

    return;
    // 0x801544BC: nop

;}
RECOMP_FUNC void grYamabukiGateProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B130: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B134: lbu         $v0, 0x140C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X140C);
    // 0x8010B138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B13C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B140: beq         $v0, $zero, L_8010B164
    if (ctx->r2 == 0) {
        // 0x8010B144: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8010B164;
    }
    // 0x8010B144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010B14C: beq         $v0, $at, L_8010B174
    if (ctx->r2 == ctx->r1) {
        // 0x8010B150: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8010B174;
    }
    // 0x8010B150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010B154: beq         $v0, $at, L_8010B18C
    if (ctx->r2 == ctx->r1) {
        // 0x8010B158: nop
    
            goto L_8010B18C;
    }
    // 0x8010B158: nop

    // 0x8010B15C: b           L_8010B1A0
    // 0x8010B160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010B1A0;
    // 0x8010B160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B164:
    // 0x8010B164: jal         0x8010ACD0
    // 0x8010B168: nop

    grYamabukiGateUpdateSleep(rdram, ctx);
        goto after_0;
    // 0x8010B168: nop

    after_0:
    // 0x8010B16C: b           L_8010B1A0
    // 0x8010B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010B1A0;
    // 0x8010B170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B174:
    // 0x8010B174: jal         0x8010AF48
    // 0x8010B178: nop

    grYamabukiGateUpdateWait(rdram, ctx);
        goto after_1;
    // 0x8010B178: nop

    after_1:
    // 0x8010B17C: jal         0x8010B108
    // 0x8010B180: nop

    grYamabukiGateUpdateYakumonoPos(rdram, ctx);
        goto after_2;
    // 0x8010B180: nop

    after_2:
    // 0x8010B184: b           L_8010B1A0
    // 0x8010B188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010B1A0;
    // 0x8010B188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B18C:
    // 0x8010B18C: jal         0x8010AFF4
    // 0x8010B190: nop

    grYamabukiGateUpdateOpen(rdram, ctx);
        goto after_3;
    // 0x8010B190: nop

    after_3:
    // 0x8010B194: jal         0x8010B108
    // 0x8010B198: nop

    grYamabukiGateUpdateYakumonoPos(rdram, ctx);
        goto after_4;
    // 0x8010B198: nop

    after_4:
    // 0x8010B19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010B1A0:
    // 0x8010B1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B1A4: jr          $ra
    // 0x8010B1A8: nop

    return;
    // 0x8010B1A8: nop

;}
RECOMP_FUNC void lbCommonEjectTreeDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C942C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800C9430: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x800C9434: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C9438: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C943C: jal         0x8000948C
    // 0x800C9440: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    gcEjectDObj(rdram, ctx);
        goto after_0;
    // 0x800C9440: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C9444: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800C9448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C944C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9450: bnel        $v1, $at, L_800C9474
    if (ctx->r3 != ctx->r1) {
        // 0x800C9454: sw          $v0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r2;
            goto L_800C9474;
    }
    goto skip_0;
    // 0x800C9454: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    skip_0:
    // 0x800C9458: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800C945C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C9460: sw          $v0, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r2;
    // 0x800C9464: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800C9468: b           L_800C9474
    // 0x800C946C: sb          $t7, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r15;
        goto L_800C9474;
    // 0x800C946C: sb          $t7, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r15;
    // 0x800C9470: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
L_800C9474:
    // 0x800C9474: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800C9478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C947C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9480: jr          $ra
    // 0x800C9484: nop

    return;
    // 0x800C9484: nop

;}
RECOMP_FUNC void gcAppendAObjToDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007E80: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80007E84: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80007E88: jr          $ra
    // 0x80007E8C: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
    return;
    // 0x80007E8C: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mvOpeningMarioInitName(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void ftKirbyCopyPikachuSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153854: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015385C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153860: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80153864: jal         0x800DEEC8
    // 0x80153868: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80153868: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015386C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80153870: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80153874: addiu       $a1, $zero, 0xFD
    ctx->r5 = ADD32(0, 0XFD);
    // 0x80153878: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015387C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80153880: jal         0x800E6F24
    // 0x80153884: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153884: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153888: jal         0x800D8EB8
    // 0x8015388C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015388C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80153890: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80153894: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80153898: addiu       $t8, $t8, 0x36C0
    ctx->r24 = ADD32(ctx->r24, 0X36C0);
    // 0x8015389C: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x801538A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801538A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801538A8: jr          $ra
    // 0x801538AC: nop

    return;
    // 0x801538AC: nop

;}
RECOMP_FUNC void ftBossCommonSetPosOffsetY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015817C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80158180: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80158184: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80158188: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015818C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80158190: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80158194: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80158198: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8015819C: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    // 0x801581A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801581A4: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x801581A8: lwc1        $f6, 0x20($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X20);
    // 0x801581AC: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x801581B0: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x801581B4: jr          $ra
    // 0x801581B8: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x801581B8: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void sc1PStageClearUpdateStageClearScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134348: jal         0x80133F28
    // 0x8013434C: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_0;
    // 0x8013434C: nop

    after_0:
    // 0x80134350: bne         $v0, $zero, L_80134418
    if (ctx->r2 != 0) {
        // 0x80134354: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80134418;
    }
    // 0x80134354: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134358: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013435C: lw          $t6, 0x53A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X53A8);
    // 0x80134360: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
    // 0x80134364: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134368: bne         $v1, $t6, L_80134384
    if (ctx->r3 != ctx->r14) {
        // 0x8013436C: nop
    
            goto L_80134384;
    }
    // 0x8013436C: nop

    // 0x80134370: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80134374: jal         0x801324FC
    // 0x80134378: nop

    sc1PStageClearMakeTimerTextSObjs(rdram, ctx);
        goto after_1;
    // 0x80134378: nop

    after_1:
    // 0x8013437C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134380: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_80134384:
    // 0x80134384: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134388: lw          $t7, 0x53AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X53AC);
    // 0x8013438C: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134390: bne         $v1, $t7, L_801343AC
    if (ctx->r3 != ctx->r15) {
        // 0x80134394: nop
    
            goto L_801343AC;
    }
    // 0x80134394: nop

    // 0x80134398: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013439C: jal         0x8013263C
    // 0x801343A0: nop

    sc1PStageClearMakeTimerDigits(rdram, ctx);
        goto after_2;
    // 0x801343A0: nop

    after_2:
    // 0x801343A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801343A8: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801343AC:
    // 0x801343AC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801343B0: lw          $t8, 0x53B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X53B0);
    // 0x801343B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801343B8: bne         $v1, $t8, L_801343F4
    if (ctx->r3 != ctx->r24) {
        // 0x801343BC: nop
    
            goto L_801343F4;
    }
    // 0x801343BC: nop

    // 0x801343C0: jal         0x80009A84
    // 0x801343C4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x801343C4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_3:
    // 0x801343C8: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x801343CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801343D0: jal         0x801327D4
    // 0x801343D4: nop

    sc1PStageClearGetAppendTotalTimeScore(rdram, ctx);
        goto after_4;
    // 0x801343D4: nop

    after_4:
    // 0x801343D8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801343DC: lw          $t9, 0x52E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52E8);
    // 0x801343E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801343E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801343E8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x801343EC: sw          $t0, 0x52E8($at)
    MEM_W(0X52E8, ctx->r1) = ctx->r8;
    // 0x801343F0: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801343F4:
    // 0x801343F4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801343F8: lw          $t1, 0x53B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X53B4);
    // 0x801343FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134400: bne         $v1, $t1, L_80134418
    if (ctx->r3 != ctx->r9) {
        // 0x80134404: nop
    
            goto L_80134418;
    }
    // 0x80134404: nop

    // 0x80134408: jal         0x80009A84
    // 0x8013440C: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x8013440C: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_5:
    // 0x80134410: jal         0x80133F00
    // 0x80134414: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_6;
    // 0x80134414: nop

    after_6:
L_80134418:
    // 0x80134418: jal         0x80133F28
    // 0x8013441C: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_7;
    // 0x8013441C: nop

    after_7:
    // 0x80134420: bne         $v0, $zero, L_80134438
    if (ctx->r2 != 0) {
        // 0x80134424: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80134438;
    }
    // 0x80134424: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134428: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x8013442C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134430: b           L_80134448
    // 0x80134434: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_80134448;
    // 0x80134434: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_80134438:
    // 0x80134438: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x8013443C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134440: nop

    // 0x80134444: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
L_80134448:
    // 0x80134448: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013444C: lw          $t2, 0x53B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X53B8);
    // 0x80134450: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
    // 0x80134454: bne         $v1, $t2, L_8013446C
    if (ctx->r3 != ctx->r10) {
        // 0x80134458: nop
    
            goto L_8013446C;
    }
    // 0x80134458: nop

    // 0x8013445C: jal         0x801328CC
    // 0x80134460: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearMakeDamageTextSObjs(rdram, ctx);
        goto after_8;
    // 0x80134460: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x80134464: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134468: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_8013446C:
    // 0x8013446C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80134470: lw          $t3, 0x53BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X53BC);
    // 0x80134474: bne         $v1, $t3, L_8013448C
    if (ctx->r3 != ctx->r11) {
        // 0x80134478: nop
    
            goto L_8013448C;
    }
    // 0x80134478: nop

    // 0x8013447C: jal         0x80132A20
    // 0x80134480: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearMakeDamageDigits(rdram, ctx);
        goto after_9;
    // 0x80134480: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x80134484: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134488: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_8013448C:
    // 0x8013448C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134490: lw          $t4, 0x53C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X53C0);
    // 0x80134494: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134498: bne         $v1, $t4, L_801344CC
    if (ctx->r3 != ctx->r12) {
        // 0x8013449C: nop
    
            goto L_801344CC;
    }
    // 0x8013449C: nop

    // 0x801344A0: jal         0x80009A84
    // 0x801344A4: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    gcEjectGObj(rdram, ctx);
        goto after_10;
    // 0x801344A4: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    after_10:
    // 0x801344A8: jal         0x80132BB4
    // 0x801344AC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearGetAppendTotalDamageScore(rdram, ctx);
        goto after_11;
    // 0x801344AC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_11:
    // 0x801344B0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801344B4: lw          $t5, 0x52E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X52E8);
    // 0x801344B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801344BC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801344C0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x801344C4: sw          $t6, 0x52E8($at)
    MEM_W(0X52E8, ctx->r1) = ctx->r14;
    // 0x801344C8: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801344CC:
    // 0x801344CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801344D0: lw          $t7, 0x53C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X53C4);
    // 0x801344D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344D8: bne         $v1, $t7, L_80134538
    if (ctx->r3 != ctx->r15) {
        // 0x801344DC: nop
    
            goto L_80134538;
    }
    // 0x801344DC: nop

    // 0x801344E0: jal         0x80009A84
    // 0x801344E4: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_12;
    // 0x801344E4: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_12:
    // 0x801344E8: jal         0x80133F00
    // 0x801344EC: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_13;
    // 0x801344EC: nop

    after_13:
    // 0x801344F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801344F4: lw          $t8, 0x52D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X52D8);
    // 0x801344F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801344FC: addiu       $v0, $v0, 0x5348
    ctx->r2 = ADD32(ctx->r2, 0X5348);
    // 0x80134500: beq         $t8, $zero, L_8013452C
    if (ctx->r24 == 0) {
        // 0x80134504: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_8013452C;
    }
    // 0x80134504: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134508: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013450C: lw          $t9, 0x52CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52CC);
    // 0x80134510: addiu       $v1, $v1, 0x5344
    ctx->r3 = ADD32(ctx->r3, 0X5344);
    // 0x80134514: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134518: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x8013451C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80134520: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134524: b           L_80134538
    // 0x80134528: sw          $t0, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r8;
        goto L_80134538;
    // 0x80134528: sw          $t0, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r8;
L_8013452C:
    // 0x8013452C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80134530: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134534: sw          $t3, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r11;
L_80134538:
    // 0x80134538: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013453C: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
    // 0x80134540: beq         $v0, $zero, L_801345E4
    if (ctx->r2 == 0) {
        // 0x80134544: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801345E4;
    }
    // 0x80134544: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134548: lw          $a0, 0x5314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5314);
    // 0x8013454C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134550: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134554: beq         $a0, $zero, L_801345E4
    if (ctx->r4 == 0) {
        // 0x80134558: nop
    
            goto L_801345E4;
    }
    // 0x80134558: nop

    // 0x8013455C: lw          $t4, 0x52CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X52CC);
    // 0x80134560: lw          $t5, 0x5340($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5340);
    // 0x80134564: bne         $t4, $t5, L_801345E4
    if (ctx->r12 != ctx->r13) {
        // 0x80134568: nop
    
            goto L_801345E4;
    }
    // 0x80134568: nop

    // 0x8013456C: jal         0x80009A84
    // 0x80134570: nop

    gcEjectGObj(rdram, ctx);
        goto after_14;
    // 0x80134570: nop

    after_14:
    // 0x80134574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134578: lw          $a0, 0x52F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52F8);
    // 0x8013457C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134580: sw          $zero, 0x5314($at)
    MEM_W(0X5314, ctx->r1) = 0;
    // 0x80134584: beq         $a0, $zero, L_801345B0
    if (ctx->r4 == 0) {
        // 0x80134588: nop
    
            goto L_801345B0;
    }
    // 0x80134588: nop

    // 0x8013458C: jal         0x80009A84
    // 0x80134590: nop

    gcEjectGObj(rdram, ctx);
        goto after_15;
    // 0x80134590: nop

    after_15:
    // 0x80134594: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134598: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013459C: sw          $zero, 0x52F8($at)
    MEM_W(0X52F8, ctx->r1) = 0;
    // 0x801345A0: jal         0x80009A84
    // 0x801345A4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_16;
    // 0x801345A4: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_16:
    // 0x801345A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801345AC: sw          $zero, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = 0;
L_801345B0:
    // 0x801345B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801345B4: jal         0x80009A84
    // 0x801345B8: lw          $a0, 0x5300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5300);
    gcEjectGObj(rdram, ctx);
        goto after_17;
    // 0x801345B8: lw          $a0, 0x5300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5300);
    after_17:
    // 0x801345BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801345C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801345C4: sw          $zero, 0x5300($at)
    MEM_W(0X5300, ctx->r1) = 0;
    // 0x801345C8: jal         0x80009A84
    // 0x801345CC: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    gcEjectGObj(rdram, ctx);
        goto after_18;
    // 0x801345CC: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    after_18:
    // 0x801345D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801345D4: jal         0x801338A0
    // 0x801345D8: sw          $zero, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = 0;
    sc1PStageClearMakeBonusTable(rdram, ctx);
        goto after_19;
    // 0x801345D8: sw          $zero, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = 0;
    after_19:
    // 0x801345DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801345E0: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
L_801345E4:
    // 0x801345E4: beql        $v0, $zero, L_801345F8
    if (ctx->r2 == 0) {
        // 0x801345E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801345F8;
    }
    goto skip_0;
    // 0x801345E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801345EC: jal         0x80133F50
    // 0x801345F0: nop

    sc1PStageUpdateBonusStatAll(rdram, ctx);
        goto after_20;
    // 0x801345F0: nop

    after_20:
    // 0x801345F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801345F8:
    // 0x801345F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801345FC: jr          $ra
    // 0x80134600: nop

    return;
    // 0x80134600: nop

;}
RECOMP_FUNC void func_80026B90_27790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B90: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80026B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026B98: lhu         $v0, 0x10($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X10);
    // 0x80026B9C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80026BA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80026BA4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80026BA8: beq         $v0, $at, L_80027328
    if (ctx->r2 == ctx->r1) {
        // 0x80026BAC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80027328;
    }
    // 0x80026BAC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80026BB0: beq         $v0, $zero, L_80027328
    if (ctx->r2 == 0) {
        // 0x80026BB4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80027328;
    }
    // 0x80026BB4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80026BB8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80026BBC: bne         $t7, $zero, L_80027328
    if (ctx->r15 != 0) {
        // 0x80026BC0: sh          $t6, 0x10($a0)
        MEM_H(0X10, ctx->r4) = ctx->r14;
            goto L_80027328;
    }
    // 0x80026BC0: sh          $t6, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r14;
    // 0x80026BC4: lbu         $t8, 0x21($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X21);
    // 0x80026BC8: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80026BCC: addiu       $t4, $t4, -0x1230
    ctx->r12 = ADD32(ctx->r12, -0X1230);
    // 0x80026BD0: beq         $t8, $zero, L_80026C04
    if (ctx->r24 == 0) {
        // 0x80026BD4: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_80026C04;
    }
    // 0x80026BD4: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80026BD8: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80026BDC: sb          $zero, 0x21($a3)
    MEM_B(0X21, ctx->r7) = 0;
    // 0x80026BE0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80026BE4: beq         $a0, $zero, L_80026BFC
    if (ctx->r4 == 0) {
        // 0x80026BE8: addiu       $ra, $zero, 0x1
        ctx->r31 = ADD32(0, 0X1);
            goto L_80026BFC;
    }
    // 0x80026BE8: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80026BEC: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x80026BF0: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x80026BF4: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x80026BF8: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
L_80026BFC:
    // 0x80026BFC: b           L_80027328
    // 0x80026C00: sh          $ra, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r31;
        goto L_80027328;
    // 0x80026C00: sh          $ra, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r31;
L_80026C04:
    // 0x80026C04: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x80026C08: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80026C0C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80026C10: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_80026C14:
    // 0x80026C14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026C18: andi        $t2, $v0, 0xF8
    ctx->r10 = ctx->r2 & 0XF8;
    // 0x80026C1C: slti        $at, $t2, 0xD0
    ctx->r1 = SIGNED(ctx->r10) < 0XD0 ? 1 : 0;
    // 0x80026C20: bne         $at, $zero, L_80027120
    if (ctx->r1 != 0) {
        // 0x80026C24: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80027120;
    }
    // 0x80026C24: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80026C28: addiu       $t9, $v0, -0xD0
    ctx->r25 = ADD32(ctx->r2, -0XD0);
    // 0x80026C2C: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x80026C30: beq         $at, $zero, L_80027118
    if (ctx->r1 == 0) {
        // 0x80026C34: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80027118;
    }
    // 0x80026C34: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80026C38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80026C3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80026C40: addu        $at, $at, $t9
    gpr jr_addend_80026C48 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80026C44: lw          $t9, -0x1790($at)
    ctx->r25 = ADD32(ctx->r1, -0X1790);
    // 0x80026C48: jr          $t9
    // 0x80026C4C: nop

    switch (jr_addend_80026C48 >> 2) {
        case 0: goto L_80026C50; break;
        case 1: goto L_80026C78; break;
        case 2: goto L_80026CB0; break;
        case 3: goto L_80026CE0; break;
        case 4: goto L_80026CF4; break;
        case 5: goto L_80026E2C; break;
        case 6: goto L_80026E40; break;
        case 7: goto L_80026E80; break;
        case 8: goto L_80026E94; break;
        case 9: goto L_80026ED4; break;
        case 10: goto L_80026FF0; break;
        case 11: goto L_80026FFC; break;
        case 12: goto L_80027008; break;
        case 13: goto L_8002701C; break;
        case 14: goto L_8002705C; break;
        case 15: goto L_80027108; break;
        case 16: goto L_80027114; break;
        default: switch_error(__func__, 0x80026C48, 0x8003E870);
    }
    // 0x80026C4C: nop

L_80026C50:
    // 0x80026C50: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80026C54: andi        $t0, $t3, 0xFFFF
    ctx->r8 = ctx->r11 & 0XFFFF;
    // 0x80026C58: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026C5C: beq         $a0, $zero, L_80027118
    if (ctx->r4 == 0) {
        // 0x80026C60: nop
    
            goto L_80027118;
    }
    // 0x80026C60: nop

    // 0x80026C64: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x80026C68: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x80026C6C: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x80026C70: b           L_80027318
    // 0x80026C74: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
        goto L_80027318;
    // 0x80026C74: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
L_80026C78:
    // 0x80026C78: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026C7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026C80: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026C84: andi        $t6, $a0, 0x80
    ctx->r14 = ctx->r4 & 0X80;
    // 0x80026C88: beq         $t6, $zero, L_80026CA8
    if (ctx->r14 == 0) {
        // 0x80026C8C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026CA8;
    }
    // 0x80026C8C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026C90: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80026C94: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80026C98: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80026C9C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80026CA0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026CA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026CA8:
    // 0x80026CA8: b           L_80027318
    // 0x80026CAC: sh          $a0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r4;
        goto L_80027318;
    // 0x80026CAC: sh          $a0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r4;
L_80026CB0:
    // 0x80026CB0: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026CB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026CB8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026CBC: andi        $t6, $a0, 0x7F
    ctx->r14 = ctx->r4 & 0X7F;
    // 0x80026CC0: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x80026CC4: beq         $t8, $zero, L_80026CD8
    if (ctx->r24 == 0) {
        // 0x80026CC8: sb          $t6, 0x1E($a3)
        MEM_B(0X1E, ctx->r7) = ctx->r14;
            goto L_80026CD8;
    }
    // 0x80026CC8: sb          $t6, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = ctx->r14;
    // 0x80026CCC: sb          $ra, 0x20($a3)
    MEM_B(0X20, ctx->r7) = ctx->r31;
    // 0x80026CD0: b           L_80027318
    // 0x80026CD4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80026CD4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80026CD8:
    // 0x80026CD8: b           L_80027318
    // 0x80026CDC: sb          $zero, 0x20($a3)
    MEM_B(0X20, ctx->r7) = 0;
        goto L_80027318;
    // 0x80026CDC: sb          $zero, 0x20($a3)
    MEM_B(0X20, ctx->r7) = 0;
L_80026CE0:
    // 0x80026CE0: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80026CE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026CE8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026CEC: b           L_80027318
    // 0x80026CF0: sb          $t7, 0x1F($a3)
    MEM_B(0X1F, ctx->r7) = ctx->r15;
        goto L_80027318;
    // 0x80026CF0: sb          $t7, 0x1F($a3)
    MEM_B(0X1F, ctx->r7) = ctx->r15;
L_80026CF4:
    // 0x80026CF4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026CF8: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80026CFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026D00: andi        $t9, $a0, 0x80
    ctx->r25 = ctx->r4 & 0X80;
    // 0x80026D04: beq         $t9, $zero, L_80026D24
    if (ctx->r25 == 0) {
        // 0x80026D08: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026D24;
    }
    // 0x80026D08: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026D0C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D10: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80026D14: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80026D18: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80026D1C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026D20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026D24:
    // 0x80026D24: sh          $a0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r4;
    // 0x80026D28: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026D30: andi        $t9, $a0, 0x80
    ctx->r25 = ctx->r4 & 0X80;
    // 0x80026D34: beq         $t9, $zero, L_80026D54
    if (ctx->r25 == 0) {
        // 0x80026D38: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026D54;
    }
    // 0x80026D38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026D3C: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D40: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x80026D44: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80026D48: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x80026D4C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026D50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026D54:
    // 0x80026D54: sh          $a0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r4;
    // 0x80026D58: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D5C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80026D60: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026D64: andi        $t9, $a0, 0x80
    ctx->r25 = ctx->r4 & 0X80;
    // 0x80026D68: beq         $t9, $zero, L_80026D88
    if (ctx->r25 == 0) {
        // 0x80026D6C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026D88;
    }
    // 0x80026D6C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026D70: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D74: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80026D78: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80026D7C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80026D80: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026D84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026D88:
    // 0x80026D88: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80026D8C: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x80026D90: sh          $a0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r4;
    // 0x80026D94: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026D98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026D9C: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x80026DA0: beq         $t8, $zero, L_80026DC0
    if (ctx->r24 == 0) {
        // 0x80026DA4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026DC0;
    }
    // 0x80026DA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026DA8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80026DAC: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x80026DB0: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80026DB4: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x80026DB8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026DBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026DC0:
    // 0x80026DC0: sh          $a0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r4;
    // 0x80026DC4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026DC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026DCC: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x80026DD0: beq         $t8, $zero, L_80026DF0
    if (ctx->r24 == 0) {
        // 0x80026DD4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026DF0;
    }
    // 0x80026DD4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026DD8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80026DDC: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x80026DE0: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x80026DE4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80026DE8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026DEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026DF0:
    // 0x80026DF0: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x80026DF4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026DF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026DFC: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x80026E00: beq         $t8, $zero, L_80026E20
    if (ctx->r24 == 0) {
        // 0x80026E04: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026E20;
    }
    // 0x80026E04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026E08: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80026E0C: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x80026E10: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80026E14: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x80026E18: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026E1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026E20:
    // 0x80026E20: sh          $a0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r4;
    // 0x80026E24: b           L_80027318
    // 0x80026E28: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80026E28: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80026E2C:
    // 0x80026E2C: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x80026E30: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026E34: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026E38: b           L_80027318
    // 0x80026E3C: sb          $t8, 0x22($a3)
    MEM_B(0X22, ctx->r7) = ctx->r24;
        goto L_80027318;
    // 0x80026E3C: sb          $t8, 0x22($a3)
    MEM_B(0X22, ctx->r7) = ctx->r24;
L_80026E40:
    // 0x80026E40: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x80026E44: lbu         $t6, 0x22($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X22);
    // 0x80026E48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026E4C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026E50: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80026E54: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80026E58: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80026E5C: bgezl       $v0, L_80026E6C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80026E60: slti        $at, $v0, 0x100
        ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
            goto L_80026E6C;
    }
    goto skip_0;
    // 0x80026E60: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    skip_0:
    // 0x80026E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026E68: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
L_80026E6C:
    // 0x80026E6C: bne         $at, $zero, L_80026E78
    if (ctx->r1 != 0) {
        // 0x80026E70: nop
    
            goto L_80026E78;
    }
    // 0x80026E70: nop

    // 0x80026E74: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80026E78:
    // 0x80026E78: b           L_80027318
    // 0x80026E7C: sb          $v0, 0x22($a3)
    MEM_B(0X22, ctx->r7) = ctx->r2;
        goto L_80027318;
    // 0x80026E7C: sb          $v0, 0x22($a3)
    MEM_B(0X22, ctx->r7) = ctx->r2;
L_80026E80:
    // 0x80026E80: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80026E84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026E88: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026E8C: b           L_80027318
    // 0x80026E90: sb          $t9, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r25;
        goto L_80027318;
    // 0x80026E90: sb          $t9, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r25;
L_80026E94:
    // 0x80026E94: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x80026E98: lbu         $t7, 0x23($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X23);
    // 0x80026E9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026EA0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026EA4: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x80026EA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80026EAC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80026EB0: bgezl       $v0, L_80026EC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80026EB4: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80026EC0;
    }
    goto skip_1;
    // 0x80026EB4: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    skip_1:
    // 0x80026EB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026EBC: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_80026EC0:
    // 0x80026EC0: bne         $at, $zero, L_80026ECC
    if (ctx->r1 != 0) {
        // 0x80026EC4: nop
    
            goto L_80026ECC;
    }
    // 0x80026EC4: nop

    // 0x80026EC8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80026ECC:
    // 0x80026ECC: b           L_80027318
    // 0x80026ED0: sb          $v0, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r2;
        goto L_80027318;
    // 0x80026ED0: sb          $v0, 0x23($a3)
    MEM_B(0X23, ctx->r7) = ctx->r2;
L_80026ED4:
    // 0x80026ED4: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80026ED8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026EDC: lhu         $v1, 0x28($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0X28);
    // 0x80026EE0: andi        $t6, $a0, 0x80
    ctx->r14 = ctx->r4 & 0X80;
    // 0x80026EE4: beq         $t6, $zero, L_80026F08
    if (ctx->r14 == 0) {
        // 0x80026EE8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80026F08;
    }
    // 0x80026EE8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026EEC: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80026EF0: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80026EF4: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80026EF8: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x80026EFC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80026F00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80026F04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80026F08:
    // 0x80026F08: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80026F0C: bnel        $at, $zero, L_80026F20
    if (ctx->r1 != 0) {
        // 0x80026F10: lw          $a2, 0x38($t4)
        ctx->r6 = MEM_W(ctx->r12, 0X38);
            goto L_80026F20;
    }
    goto skip_2;
    // 0x80026F10: lw          $a2, 0x38($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X38);
    skip_2:
    // 0x80026F14: b           L_80026F20
    // 0x80026F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80026F20;
    // 0x80026F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026F1C: lw          $a2, 0x38($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X38);
L_80026F20:
    // 0x80026F20: beq         $a2, $zero, L_80027118
    if (ctx->r6 == 0) {
        // 0x80026F24: nop
    
            goto L_80027118;
    }
    // 0x80026F24: nop

    // 0x80026F28: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80026F2C: or          $t7, $a3, $zero
    ctx->r15 = ctx->r7 | 0;
    // 0x80026F30: addiu       $at, $a3, 0x30
    ctx->r1 = ADD32(ctx->r7, 0X30);
    // 0x80026F34: sw          $t6, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r14;
    // 0x80026F38: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
L_80026F3C:
    // 0x80026F3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80026F40: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80026F44: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80026F48: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80026F4C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80026F50: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80026F54: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80026F58: bne         $t7, $at, L_80026F3C
    if (ctx->r15 != ctx->r1) {
        // 0x80026F5C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80026F3C;
    }
    // 0x80026F5C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80026F60: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80026F64: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80026F68: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80026F6C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80026F70: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80026F74: beql        $t7, $zero, L_80026F94
    if (ctx->r15 == 0) {
        // 0x80026F78: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_80026F94;
    }
    goto skip_3;
    // 0x80026F78: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    skip_3:
    // 0x80026F7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80026F80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80026F84:
    // 0x80026F84: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80026F88: bnel        $v0, $zero, L_80026F84
    if (ctx->r2 != 0) {
        // 0x80026F8C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80026F84;
    }
    goto skip_4;
    // 0x80026F8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_4:
    // 0x80026F90: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_80026F94:
    // 0x80026F94: sh          $ra, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r31;
    // 0x80026F98: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x80026F9C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80026FA0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80026FA4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80026FA8: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80026FAC: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x80026FB0: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x80026FB4: lhu         $t8, 0x4A($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X4A);
    // 0x80026FB8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80026FBC: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x80026FC0: bne         $v0, $zero, L_80026FD4
    if (ctx->r2 != 0) {
        // 0x80026FC4: sh          $t9, 0x4A($t4)
        MEM_H(0X4A, ctx->r12) = ctx->r25;
            goto L_80026FD4;
    }
    // 0x80026FC4: sh          $t9, 0x4A($t4)
    MEM_H(0X4A, ctx->r12) = ctx->r25;
    // 0x80026FC8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80026FCC: sh          $t7, 0x4A($t4)
    MEM_H(0X4A, ctx->r12) = ctx->r15;
    // 0x80026FD0: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
L_80026FD4:
    // 0x80026FD4: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80026FD8: sh          $v0, 0x26($a2)
    MEM_H(0X26, ctx->r6) = ctx->r2;
    // 0x80026FDC: sw          $zero, 0x28($a2)
    MEM_W(0X28, ctx->r6) = 0;
    // 0x80026FE0: bne         $t6, $zero, L_80027118
    if (ctx->r14 != 0) {
        // 0x80026FE4: nop
    
            goto L_80027118;
    }
    // 0x80026FE4: nop

    // 0x80026FE8: b           L_80027318
    // 0x80026FEC: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
        goto L_80027318;
    // 0x80026FEC: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
L_80026FF0:
    // 0x80026FF0: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80026FF4: b           L_80027318
    // 0x80026FF8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80026FF8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80026FFC:
    // 0x80026FFC: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x80027000: b           L_80027318
    // 0x80027004: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80027004: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80027008:
    // 0x80027008: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x8002700C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027010: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80027014: b           L_80027318
    // 0x80027018: sb          $t8, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r24;
        goto L_80027318;
    // 0x80027018: sb          $t8, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r24;
L_8002701C:
    // 0x8002701C: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    // 0x80027020: lbu         $t7, 0x2C($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2C);
    // 0x80027024: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027028: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8002702C: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80027030: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80027034: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80027038: bgezl       $v0, L_80027048
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002703C: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80027048;
    }
    goto skip_5;
    // 0x8002703C: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    skip_5:
    // 0x80027040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027044: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_80027048:
    // 0x80027048: bne         $at, $zero, L_80027054
    if (ctx->r1 != 0) {
        // 0x8002704C: nop
    
            goto L_80027054;
    }
    // 0x8002704C: nop

    // 0x80027050: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80027054:
    // 0x80027054: b           L_80027318
    // 0x80027058: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
        goto L_80027318;
    // 0x80027058: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
L_8002705C:
    // 0x8002705C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80027060: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027064: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80027068: beq         $t8, $zero, L_80027118
    if (ctx->r24 == 0) {
        // 0x8002706C: sb          $t6, 0x2D($a3)
        MEM_B(0X2D, ctx->r7) = ctx->r14;
            goto L_80027118;
    }
    // 0x8002706C: sb          $t6, 0x2D($a3)
    MEM_B(0X2D, ctx->r7) = ctx->r14;
    // 0x80027070: lw          $v1, 0x40($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X40);
    // 0x80027074: beq         $v1, $zero, L_80027118
    if (ctx->r3 == 0) {
        // 0x80027078: nop
    
            goto L_80027118;
    }
    // 0x80027078: nop

L_8002707C:
    // 0x8002707C: beql        $v1, $a3, L_800270F8
    if (ctx->r3 == ctx->r7) {
        // 0x80027080: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800270F8;
    }
    goto skip_6;
    // 0x80027080: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_6:
    // 0x80027084: lbu         $t9, 0x2D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2D);
    // 0x80027088: lbu         $t7, 0x2D($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2D);
    // 0x8002708C: bnel        $t9, $t7, L_800270F8
    if (ctx->r25 != ctx->r15) {
        // 0x80027090: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800270F8;
    }
    goto skip_7;
    // 0x80027090: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x80027094: lbu         $t6, 0x1F($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1F);
    // 0x80027098: lbu         $t9, 0x1F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1F);
    // 0x8002709C: andi        $t8, $t6, 0x7F
    ctx->r24 = ctx->r14 & 0X7F;
    // 0x800270A0: andi        $t7, $t9, 0x7F
    ctx->r15 = ctx->r25 & 0X7F;
    // 0x800270A4: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800270A8: bnel        $at, $zero, L_800270D8
    if (ctx->r1 != 0) {
        // 0x800270AC: lw          $a0, 0x28($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X28);
            goto L_800270D8;
    }
    goto skip_8;
    // 0x800270AC: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    skip_8:
    // 0x800270B0: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x800270B4: sh          $t3, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r11;
    // 0x800270B8: beql        $a0, $zero, L_800270F8
    if (ctx->r4 == 0) {
        // 0x800270BC: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800270F8;
    }
    goto skip_9;
    // 0x800270BC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_9:
    // 0x800270C0: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x800270C4: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x800270C8: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x800270CC: b           L_800270F4
    // 0x800270D0: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
        goto L_800270F4;
    // 0x800270D0: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x800270D4: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
L_800270D8:
    // 0x800270D8: andi        $t0, $t3, 0xFFFF
    ctx->r8 = ctx->r11 & 0XFFFF;
    // 0x800270DC: beql        $a0, $zero, L_800270F8
    if (ctx->r4 == 0) {
        // 0x800270E0: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800270F8;
    }
    goto skip_10;
    // 0x800270E0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_10:
    // 0x800270E4: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x800270E8: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x800270EC: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x800270F0: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
L_800270F4:
    // 0x800270F4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800270F8:
    // 0x800270F8: bne         $v1, $zero, L_8002707C
    if (ctx->r3 != 0) {
        // 0x800270FC: nop
    
            goto L_8002707C;
    }
    // 0x800270FC: nop

    // 0x80027100: b           L_80027318
    // 0x80027104: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80027104: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80027108:
    // 0x80027108: addiu       $t5, $zero, -0x960
    ctx->r13 = ADD32(0, -0X960);
    // 0x8002710C: b           L_80027318
    // 0x80027110: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x80027110: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80027114:
    // 0x80027114: addiu       $t5, $zero, -0x12C0
    ctx->r13 = ADD32(0, -0X12C0);
L_80027118:
    // 0x80027118: b           L_80027318
    // 0x8002711C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80027318;
    // 0x8002711C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80027120:
    // 0x80027120: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x80027124: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80027128: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x8002712C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80027130: beq         $at, $zero, L_80027194
    if (ctx->r1 == 0) {
        // 0x80027134: lw          $a0, 0x28($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X28);
            goto L_80027194;
    }
    // 0x80027134: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80027138: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8002713C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027140: addu        $at, $at, $t6
    gpr jr_addend_80027148 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80027144: lw          $t6, -0x174C($at)
    ctx->r14 = ADD32(ctx->r1, -0X174C);
    // 0x80027148: jr          $t6
    // 0x8002714C: nop

    switch (jr_addend_80027148 >> 2) {
        case 0: goto L_80027150; break;
        case 1: goto L_80027158; break;
        case 2: goto L_80027158; break;
        case 3: goto L_80027158; break;
        case 4: goto L_80027158; break;
        case 5: goto L_80027158; break;
        case 6: goto L_80027158; break;
        case 7: goto L_80027168; break;
        default: switch_error(__func__, 0x80027148, 0x8003E8B4);
    }
    // 0x8002714C: nop

L_80027150:
    // 0x80027150: b           L_80027194
    // 0x80027154: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80027194;
    // 0x80027154: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80027158:
    // 0x80027158: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8002715C: addu        $t8, $a3, $t9
    ctx->r24 = ADD32(ctx->r7, ctx->r25);
    // 0x80027160: b           L_80027194
    // 0x80027164: lhu         $t0, 0x10($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X10);
        goto L_80027194;
    // 0x80027164: lhu         $t0, 0x10($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X10);
L_80027168:
    // 0x80027168: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x8002716C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80027170: andi        $t7, $t0, 0x80
    ctx->r15 = ctx->r8 & 0X80;
    // 0x80027174: beq         $t7, $zero, L_80027194
    if (ctx->r15 == 0) {
        // 0x80027178: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80027194;
    }
    // 0x80027178: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8002717C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80027180: andi        $t9, $v1, 0x7F
    ctx->r25 = ctx->r3 & 0X7F;
    // 0x80027184: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80027188: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x8002718C: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // 0x80027190: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80027194:
    // 0x80027194: bne         $t2, $zero, L_800271B8
    if (ctx->r10 != 0) {
        // 0x80027198: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800271B8;
    }
    // 0x80027198: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8002719C: beq         $a0, $zero, L_80027318
    if (ctx->r4 == 0) {
        // 0x800271A0: nop
    
            goto L_80027318;
    }
    // 0x800271A0: nop

    // 0x800271A4: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x800271A8: sb          $t1, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r9;
    // 0x800271AC: sh          $zero, 0x48($a0)
    MEM_H(0X48, ctx->r4) = 0;
    // 0x800271B0: b           L_80027318
    // 0x800271B4: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
        goto L_80027318;
    // 0x800271B4: sw          $zero, 0x28($a3)
    MEM_W(0X28, ctx->r7) = 0;
L_800271B8:
    // 0x800271B8: beq         $a0, $zero, L_800271F8
    if (ctx->r4 == 0) {
        // 0x800271BC: sra         $t7, $a2, 3
        ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
            goto L_800271F8;
    }
    // 0x800271BC: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800271C0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800271C4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800271C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800271CC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800271D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800271D4: addiu       $t7, $t9, -0x514
    ctx->r15 = ADD32(ctx->r25, -0X514);
    // 0x800271D8: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x800271DC: sh          $t9, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r25;
    // 0x800271E0: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x800271E4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800271E8: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x800271EC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800271F0: b           L_800272F0
    // 0x800271F4: sh          $t8, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r24;
        goto L_800272F0;
    // 0x800271F4: sh          $t8, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r24;
L_800271F8:
    // 0x800271F8: lhu         $a0, 0x24($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X24);
    // 0x800271FC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80027200: sh          $t0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r8;
    // 0x80027204: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80027208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002720C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80027210: jal         0x80026B40
    // 0x80027214: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80026B40_27740(rdram, ctx);
        goto after_0;
    // 0x80027214: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80027218: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8002721C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80027220: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80027224: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80027228: lhu         $t0, 0x68($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X68);
    // 0x8002722C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80027230: lh          $t5, 0x52($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X52);
    // 0x80027234: addiu       $t4, $t4, -0x1230
    ctx->r12 = ADD32(ctx->r12, -0X1230);
    // 0x80027238: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8002723C: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80027240: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80027244: beq         $v0, $zero, L_800272F0
    if (ctx->r2 == 0) {
        // 0x80027248: sw          $v0, 0x28($a3)
        MEM_W(0X28, ctx->r7) = ctx->r2;
            goto L_800272F0;
    }
    // 0x80027248: sw          $v0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r2;
    // 0x8002724C: sra         $t6, $a2, 3
    ctx->r14 = S32(SIGNED(ctx->r6) >> 3);
    // 0x80027250: lbu         $t7, 0x1F($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1F);
    // 0x80027254: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80027258: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8002725C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80027260: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80027264: sb          $t7, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r15;
    // 0x80027268: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x8002726C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80027270: addiu       $t6, $t8, -0x514
    ctx->r14 = ADD32(ctx->r24, -0X514);
    // 0x80027274: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x80027278: sh          $t8, 0x30($t7)
    MEM_H(0X30, ctx->r15) = ctx->r24;
    // 0x8002727C: lbu         $t6, 0x2E($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2E);
    // 0x80027280: lbu         $t9, 0x22($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X22);
    // 0x80027284: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80027288: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8002728C: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027290: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    // 0x80027294: mflo        $t8
    ctx->r24 = lo;
    // 0x80027298: sra         $t7, $t8, 7
    ctx->r15 = S32(SIGNED(ctx->r24) >> 7);
    // 0x8002729C: sb          $t7, 0x38($t9)
    MEM_B(0X38, ctx->r25) = ctx->r15;
    // 0x800272A0: lbu         $v0, 0x2F($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2F);
    // 0x800272A4: beql        $v0, $at, L_800272BC
    if (ctx->r2 == ctx->r1) {
        // 0x800272A8: lbu         $t8, 0x23($a3)
        ctx->r24 = MEM_BU(ctx->r7, 0X23);
            goto L_800272BC;
    }
    goto skip_11;
    // 0x800272A8: lbu         $t8, 0x23($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X23);
    skip_11:
    // 0x800272AC: lw          $t6, 0x28($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X28);
    // 0x800272B0: b           L_800272C4
    // 0x800272B4: sb          $v0, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r2;
        goto L_800272C4;
    // 0x800272B4: sb          $v0, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r2;
    // 0x800272B8: lbu         $t8, 0x23($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X23);
L_800272BC:
    // 0x800272BC: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800272C0: sb          $t8, 0x3A($t7)
    MEM_B(0X3A, ctx->r15) = ctx->r24;
L_800272C4:
    // 0x800272C4: lbu         $v0, 0x30($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X30);
    // 0x800272C8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800272CC: beql        $v0, $at, L_800272E8
    if (ctx->r2 == ctx->r1) {
        // 0x800272D0: lbu         $t8, 0x2C($a3)
        ctx->r24 = MEM_BU(ctx->r7, 0X2C);
            goto L_800272E8;
    }
    goto skip_12;
    // 0x800272D0: lbu         $t8, 0x2C($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X2C);
    skip_12:
    // 0x800272D4: lw          $t6, 0x28($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X28);
    // 0x800272D8: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800272DC: b           L_800272F0
    // 0x800272E0: sb          $t9, 0x3C($t6)
    MEM_B(0X3C, ctx->r14) = ctx->r25;
        goto L_800272F0;
    // 0x800272E0: sb          $t9, 0x3C($t6)
    MEM_B(0X3C, ctx->r14) = ctx->r25;
    // 0x800272E4: lbu         $t8, 0x2C($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X2C);
L_800272E8:
    // 0x800272E8: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800272EC: sb          $t8, 0x3C($t7)
    MEM_B(0X3C, ctx->r15) = ctx->r24;
L_800272F0:
    // 0x800272F0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800272F4: bne         $at, $zero, L_80027318
    if (ctx->r1 != 0) {
        // 0x800272F8: nop
    
            goto L_80027318;
    }
    // 0x800272F8: nop

    // 0x800272FC: lbu         $t9, 0x20($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X20);
    // 0x80027300: beq         $t9, $zero, L_80027318
    if (ctx->r25 == 0) {
        // 0x80027304: nop
    
            goto L_80027318;
    }
    // 0x80027304: nop

    // 0x80027308: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8002730C: andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // 0x80027310: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80027314: sb          $ra, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r31;
L_80027318:
    // 0x80027318: beql        $v1, $zero, L_80026C14
    if (ctx->r3 == 0) {
        // 0x8002731C: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_80026C14;
    }
    goto skip_13;
    // 0x8002731C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_13:
    // 0x80027320: sw          $a1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r5;
    // 0x80027324: sh          $t0, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r8;
L_80027328:
    // 0x80027328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002732C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80027330: jr          $ra
    // 0x80027334: nop

    return;
    // 0x80027334: nop

;}
RECOMP_FUNC void itProcessSearchHitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801705C4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801705C8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801705CC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x801705D0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x801705D4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801705D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801705DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801705E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801705E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801705E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801705EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801705F0: lw          $s6, 0x84($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X84);
    // 0x801705F4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x801705F8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x801705FC: lbu         $t6, 0x244($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X244);
    // 0x80170600: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80170604: beql        $t7, $zero, L_80170860
    if (ctx->r15 == 0) {
        // 0x80170608: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80170860;
    }
    goto skip_0;
    // 0x80170608: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8017060C: lw          $t8, 0x66FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X66FC);
    // 0x80170610: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80170614: addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
    // 0x80170618: beq         $t8, $zero, L_8017085C
    if (ctx->r24 == 0) {
        // 0x8017061C: sw          $t8, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r24;
            goto L_8017085C;
    }
    // 0x8017061C: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
L_80170620:
    // 0x80170620: lw          $v1, 0x8($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X8);
    // 0x80170624: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80170628: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8017062C: bne         $t9, $v1, L_80170640
    if (ctx->r25 != ctx->r3) {
        // 0x80170630: nop
    
            goto L_80170640;
    }
    // 0x80170630: nop

    // 0x80170634: lb          $t1, 0x2CF($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X2CF);
    // 0x80170638: bgezl       $t1, L_80170850
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8017063C: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_80170850;
    }
    goto skip_1;
    // 0x8017063C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    skip_1:
L_80170640:
    // 0x80170640: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80170644: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80170648: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x8017064C: lw          $s7, 0x84($t2)
    ctx->r23 = MEM_W(ctx->r10, 0X84);
    // 0x80170650: bnel        $fp, $t3, L_80170698
    if (ctx->r30 != ctx->r11) {
        // 0x80170654: lw          $t8, 0x190($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X190);
            goto L_80170698;
    }
    goto skip_2;
    // 0x80170654: lw          $t8, 0x190($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X190);
    skip_2:
    // 0x80170658: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x8017065C: bnel        $t4, $zero, L_80170698
    if (ctx->r12 != 0) {
        // 0x80170660: lw          $t8, 0x190($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X190);
            goto L_80170698;
    }
    goto skip_3;
    // 0x80170660: lw          $t8, 0x190($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X190);
    skip_3:
    // 0x80170664: lw          $t5, 0x278($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X278);
    // 0x80170668: lbu         $a0, 0x14($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X14);
    // 0x8017066C: beql        $t5, $zero, L_80170680
    if (ctx->r13 == 0) {
        // 0x80170670: lbu         $v0, 0xC($s7)
        ctx->r2 = MEM_BU(ctx->r23, 0XC);
            goto L_80170680;
    }
    goto skip_4;
    // 0x80170670: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
    skip_4:
    // 0x80170674: b           L_80170680
    // 0x80170678: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
        goto L_80170680;
    // 0x80170678: lbu         $v0, 0x280($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X280);
    // 0x8017067C: lbu         $v0, 0xC($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0XC);
L_80170680:
    // 0x80170680: bnel        $v0, $a0, L_80170698
    if (ctx->r2 != ctx->r4) {
        // 0x80170684: lw          $t8, 0x190($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X190);
            goto L_80170698;
    }
    goto skip_5;
    // 0x80170684: lw          $t8, 0x190($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X190);
    skip_5:
    // 0x80170688: lb          $t7, 0x2CF($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X2CF);
    // 0x8017068C: bgezl       $t7, L_80170850
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80170690: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_80170850;
    }
    goto skip_6;
    // 0x80170690: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    skip_6:
    // 0x80170694: lw          $t8, 0x190($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X190);
L_80170698:
    // 0x80170698: sll         $t0, $t8, 18
    ctx->r8 = S32(ctx->r24 << 18);
    // 0x8017069C: bltzl       $t0, L_80170850
    if (SIGNED(ctx->r8) < 0) {
        // 0x801706A0: lw          $t6, 0x94($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X94);
            goto L_80170850;
    }
    goto skip_7;
    // 0x801706A0: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    skip_7:
    // 0x801706A4: beq         $v1, $zero, L_801706BC
    if (ctx->r3 == 0) {
        // 0x801706A8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_801706BC;
    }
    // 0x801706A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801706AC: lw          $v0, 0x278($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X278);
    // 0x801706B0: beq         $v0, $zero, L_801706BC
    if (ctx->r2 == 0) {
        // 0x801706B4: nop
    
            goto L_801706BC;
    }
    // 0x801706B4: nop

    // 0x801706B8: beq         $v1, $v0, L_8017084C
    if (ctx->r3 == ctx->r2) {
        // 0x801706BC: lui         $s3, 0x8013
        ctx->r19 = S32(0X8013 << 16);
            goto L_8017084C;
    }
L_801706BC:
    // 0x801706BC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801706C0: addiu       $s3, $s3, 0x11A0
    ctx->r19 = ADD32(ctx->r19, 0X11A0);
    // 0x801706C4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
L_801706C8:
    // 0x801706C8: lw          $t1, 0x294($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X294);
    // 0x801706CC: beql        $t1, $zero, L_801707A0
    if (ctx->r9 == 0) {
        // 0x801706D0: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_801707A0;
    }
    goto skip_8;
    // 0x801706D0: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_8:
    // 0x801706D4: lw          $v0, 0x108($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X108);
    // 0x801706D8: addiu       $s0, $a1, 0x294
    ctx->r16 = ADD32(ctx->r5, 0X294);
    // 0x801706DC: bne         $fp, $v0, L_801706F4
    if (ctx->r30 != ctx->r2) {
        // 0x801706E0: nop
    
            goto L_801706F4;
    }
    // 0x801706E0: nop

    // 0x801706E4: lbu         $t2, 0x3C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3C);
    // 0x801706E8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801706EC: bnel        $t3, $zero, L_8017070C
    if (ctx->r11 != 0) {
        // 0x801706F0: lbu         $t6, 0x70($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X70);
            goto L_8017070C;
    }
    goto skip_9;
    // 0x801706F0: lbu         $t6, 0x70($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X70);
    skip_9:
L_801706F4:
    // 0x801706F4: bne         $v0, $zero, L_8017079C
    if (ctx->r2 != 0) {
        // 0x801706F8: addiu       $s0, $a1, 0x294
        ctx->r16 = ADD32(ctx->r5, 0X294);
            goto L_8017079C;
    }
    // 0x801706F8: addiu       $s0, $a1, 0x294
    ctx->r16 = ADD32(ctx->r5, 0X294);
    // 0x801706FC: lb          $t5, 0x3D($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X3D);
    // 0x80170700: bgezl       $t5, L_801707A0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80170704: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_801707A0;
    }
    goto skip_10;
    // 0x80170704: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_10:
    // 0x80170708: lbu         $t6, 0x70($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X70);
L_8017070C:
    // 0x8017070C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80170710: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80170714: andi        $t3, $t6, 0xFFBF
    ctx->r11 = ctx->r14 & 0XFFBF;
    // 0x80170718: sb          $t3, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r11;
    // 0x8017071C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80170720: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x80170724: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80170728: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x8017072C: sll         $t2, $t0, 7
    ctx->r10 = S32(ctx->r8 << 7);
    // 0x80170730: or          $t8, $t2, $t4
    ctx->r24 = ctx->r10 | ctx->r12;
    // 0x80170734: sb          $t8, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r24;
    // 0x80170738: ori         $t9, $t8, 0xE
    ctx->r25 = ctx->r24 | 0XE;
    // 0x8017073C: sb          $t9, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r25;
L_80170740:
    // 0x80170740: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x80170744: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80170748: bne         $s4, $t0, L_80170760
    if (ctx->r20 != ctx->r8) {
        // 0x8017074C: nop
    
            goto L_80170760;
    }
    // 0x8017074C: nop

    // 0x80170750: lw          $t3, 0x60($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X60);
    // 0x80170754: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x80170758: b           L_80170768
    // 0x8017075C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
        goto L_80170768;
    // 0x8017075C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80170760:
    // 0x80170760: bne         $v1, $s5, L_80170740
    if (ctx->r3 != ctx->r21) {
        // 0x80170764: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80170740;
    }
    // 0x80170764: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80170768:
    // 0x80170768: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8017076C: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x80170770: bne         $t4, $zero, L_8017079C
    if (ctx->r12 != 0) {
        // 0x80170774: sll         $t6, $t2, 1
        ctx->r14 = S32(ctx->r10 << 1);
            goto L_8017079C;
    }
    // 0x80170774: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x80170778: bltz        $t6, L_8017079C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8017077C: sll         $t8, $t2, 4
        ctx->r24 = S32(ctx->r10 << 4);
            goto L_8017079C;
    }
    // 0x8017077C: sll         $t8, $t2, 4
    ctx->r24 = S32(ctx->r10 << 4);
    // 0x80170780: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x80170784: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80170788: bnel        $t9, $at, L_801707A0
    if (ctx->r25 != ctx->r1) {
        // 0x8017078C: sw          $zero, 0x0($s3)
        MEM_W(0X0, ctx->r19) = 0;
            goto L_801707A0;
    }
    goto skip_11;
    // 0x8017078C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    skip_11:
    // 0x80170790: sw          $fp, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r30;
    // 0x80170794: b           L_801707A0
    // 0x80170798: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_801707A0;
    // 0x80170798: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8017079C:
    // 0x8017079C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_801707A0:
    // 0x801707A0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801707A4: addiu       $t0, $t0, 0x11B0
    ctx->r8 = ADD32(ctx->r8, 0X11B0);
    // 0x801707A8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801707AC: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x801707B0: bne         $at, $zero, L_801706C8
    if (ctx->r1 != 0) {
        // 0x801707B4: addiu       $a1, $a1, 0xC4
        ctx->r5 = ADD32(ctx->r5, 0XC4);
            goto L_801706C8;
    }
    // 0x801707B4: addiu       $a1, $a1, 0xC4
    ctx->r5 = ADD32(ctx->r5, 0XC4);
    // 0x801707B8: beq         $a2, $zero, L_8017084C
    if (ctx->r6 == 0) {
        // 0x801707BC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8017084C;
    }
    // 0x801707BC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801707C0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801707C4: addiu       $s3, $s3, 0x11A0
    ctx->r19 = ADD32(ctx->r19, 0X11A0);
L_801707C8:
    // 0x801707C8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x801707CC: addiu       $s1, $s6, 0x244
    ctx->r17 = ADD32(ctx->r22, 0X244);
    // 0x801707D0: beql        $t1, $zero, L_80170840
    if (ctx->r9 == 0) {
        // 0x801707D4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80170840;
    }
    goto skip_12;
    // 0x801707D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_12:
    // 0x801707D8: lw          $t7, 0x248($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X248);
    // 0x801707DC: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x801707E0: subu        $t4, $t4, $s2
    ctx->r12 = SUB32(ctx->r12, ctx->r18);
    // 0x801707E4: beq         $t7, $zero, L_8017084C
    if (ctx->r15 == 0) {
        // 0x801707E8: sll         $t4, $t4, 4
        ctx->r12 = S32(ctx->r12 << 4);
            goto L_8017084C;
    }
    // 0x801707E8: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x801707EC: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x801707F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801707F4: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x801707F8: beq         $t3, $at, L_8017083C
    if (ctx->r11 == ctx->r1) {
        // 0x801707FC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8017083C;
    }
    // 0x801707FC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170800: addu        $s0, $s7, $t4
    ctx->r16 = ADD32(ctx->r23, ctx->r12);
    // 0x80170804: addiu       $s0, $s0, 0x294
    ctx->r16 = ADD32(ctx->r16, 0X294);
    // 0x80170808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017080C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80170810: jal         0x800EFC20
    // 0x80170814: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    gmCollisionCheckFighterAttackItemDamageCollide(rdram, ctx);
        goto after_0;
    // 0x80170814: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x80170818: beq         $v0, $zero, L_8017083C
    if (ctx->r2 == 0) {
        // 0x8017081C: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8017083C;
    }
    // 0x8017081C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80170820: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80170824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80170828: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8017082C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80170830: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80170834: jal         0x8016FB18
    // 0x80170838: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    itProcessUpdateDamageStatFighter(rdram, ctx);
        goto after_1;
    // 0x80170838: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
L_8017083C:
    // 0x8017083C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80170840:
    // 0x80170840: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80170844: bne         $s2, $at, L_801707C8
    if (ctx->r18 != ctx->r1) {
        // 0x80170848: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_801707C8;
    }
    // 0x80170848: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8017084C:
    // 0x8017084C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
L_80170850:
    // 0x80170850: lw          $t2, 0x4($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X4);
    // 0x80170854: bne         $t2, $zero, L_80170620
    if (ctx->r10 != 0) {
        // 0x80170858: sw          $t2, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r10;
            goto L_80170620;
    }
    // 0x80170858: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
L_8017085C:
    // 0x8017085C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80170860:
    // 0x80170860: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80170864: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80170868: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8017086C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80170870: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80170874: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80170878: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8017087C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80170880: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80170884: jr          $ra
    // 0x80170888: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80170888: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void efManagerNoEjectProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD5E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FD5E4: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800FD5E8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800FD5EC: bnel        $t7, $zero, L_800FD600
    if (ctx->r15 != 0) {
        // 0x800FD5F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD600;
    }
    goto skip_0;
    // 0x800FD5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FD5F4: jal         0x8000DF34
    // 0x800FD5F8: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FD5F8: nop

    after_0:
    // 0x800FD5FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FD600:
    // 0x800FD600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD604: jr          $ra
    // 0x800FD608: nop

    return;
    // 0x800FD608: nop

;}
RECOMP_FUNC void ifCommonPlayerStockInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110514: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80110518: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8011051C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80110520: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80110524: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80110528: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8011052C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80110530: jal         0x8010FD2C
    // 0x80110534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    ifCommonPlayerStockSetIconAttr(rdram, ctx);
        goto after_0;
    // 0x80110534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80110538: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8011053C: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x80110540: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80110544: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80110548: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8011054C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80110550: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80110554:
    // 0x80110554: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80110558: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x8011055C: lbu         $t7, 0x22($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X22);
    // 0x80110560: beql        $s2, $t7, L_801105A0
    if (ctx->r18 == ctx->r15) {
        // 0x80110564: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801105A0;
    }
    goto skip_0;
    // 0x80110564: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80110568: lbu         $v1, 0x29($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X29);
    // 0x8011056C: beq         $v1, $zero, L_80110584
    if (ctx->r3 == 0) {
        // 0x80110570: nop
    
            goto L_80110584;
    }
    // 0x80110570: nop

    // 0x80110574: beq         $v1, $s4, L_80110594
    if (ctx->r3 == ctx->r20) {
        // 0x80110578: nop
    
            goto L_80110594;
    }
    // 0x80110578: nop

    // 0x8011057C: b           L_801105A0
    // 0x80110580: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_801105A0;
    // 0x80110580: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80110584:
    // 0x80110584: jal         0x8010FDD4
    // 0x80110588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ifCommonPlayerStockMultiMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80110588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8011058C: b           L_801105A0
    // 0x80110590: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_801105A0;
    // 0x80110590: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80110594:
    // 0x80110594: jal         0x8010FFA8
    // 0x80110598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ifCommonPlayerStockSingleMakeInterface(rdram, ctx);
        goto after_2;
    // 0x80110598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8011059C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801105A0:
    // 0x801105A0: bne         $s0, $s5, L_80110554
    if (ctx->r16 != ctx->r21) {
        // 0x801105A4: addiu       $s1, $s1, 0x74
        ctx->r17 = ADD32(ctx->r17, 0X74);
            goto L_80110554;
    }
    // 0x801105A4: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x801105A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801105AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801105B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801105B4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801105B8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801105BC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801105C0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801105C4: jr          $ra
    // 0x801105C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801105C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gmCameraGetAdjustAtAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010C324: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C328: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8010C32C: lwc1        $f4, 0x1464($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1464);
    // 0x8010C330: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010C334: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8010C338: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8010C33C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010C340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010C344: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010C348: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010C34C: lwc1        $f8, 0x68($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X68);
    // 0x8010C350: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8010C354: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010C358: jal         0x800C7840
    // 0x8010C35C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_0;
    // 0x8010C35C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8010C360: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8010C364: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010C368: jal         0x800C78B8
    // 0x8010C36C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    lbCommonCos(rdram, ctx);
        goto after_1;
    // 0x8010C36C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8010C370: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8010C374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C378: lwc1        $f16, 0x1468($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8010C37C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010C380: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8010C384: jal         0x800C7840
    // 0x8010C388: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x8010C388: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8010C38C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010C390: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010C394: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C398: jal         0x800C78B8
    // 0x8010C39C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x8010C39C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x8010C3A0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010C3A4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010C3A8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8010C3AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C3B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010C3B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010C3B8: jr          $ra
    // 0x8010C3BC: nop

    return;
    // 0x8010C3BC: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeLogo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801325A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801325AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801325B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801325B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801325B8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x801325BC: jal         0x80009968
    // 0x801325C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801325C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801325C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801325C8: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x801325CC: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x801325D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325D4: addiu       $t7, $t7, -0x3B58
    ctx->r15 = ADD32(ctx->r15, -0X3B58);
    // 0x801325D8: sw          $v0, 0x4D00($at)
    MEM_W(0X4D00, ctx->r1) = ctx->r2;
    // 0x801325DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801325E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801325E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801325E8: jal         0x8000F120
    // 0x801325EC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x801325EC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x801325F0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801325F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801325F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801325FC: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80132600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132604: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132608: jal         0x80009DF4
    // 0x8013260C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x8013260C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132610: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132614: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80132618: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x8013261C: addiu       $t0, $t0, -0x43A0
    ctx->r8 = ADD32(ctx->r8, -0X43A0);
    // 0x80132620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132624: jal         0x8000F8F4
    // 0x80132628: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80132628: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x8013262C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132630: lw          $t1, 0x50B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50B0);
    // 0x80132634: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80132638: addiu       $t2, $t2, -0x3AD4
    ctx->r10 = ADD32(ctx->r10, -0X3AD4);
    // 0x8013263C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132640: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132644: jal         0x8000BE28
    // 0x80132648: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80132648: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x8013264C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132650: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013265C: jal         0x80008188
    // 0x80132660: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132660: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132664: jal         0x8000DF34
    // 0x80132668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x80132668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013266C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132670: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132674: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132678: jr          $ra
    // 0x8013267C: nop

    return;
    // 0x8013267C: nop

;}
RECOMP_FUNC void lbParticleRotateVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEC34: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800CEC38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CEC3C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800CEC40: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800CEC44: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800CEC48: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800CEC4C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800CEC50: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800CEC54: lwc1        $f20, 0x30($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800CEC58: lwc1        $f24, 0x34($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800CEC5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CEC60: lwc1        $f22, 0x2C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CEC64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800CEC68: jal         0x8001863C
    // 0x800CEC6C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x800CEC6C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_0:
    // 0x800CEC70: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800CEC74: jal         0x800303F0
    // 0x800CEC78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CEC78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800CEC7C: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800CEC80: jal         0x80035CD0
    // 0x800CEC84: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CEC84: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x800CEC88: mul.s       $f4, $f20, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x800CEC8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800CEC90: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800CEC94: mul.s       $f6, $f24, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800CEC98: jal         0x8001863C
    // 0x800CEC9C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x800CEC9C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x800CECA0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800CECA4: jal         0x800303F0
    // 0x800CECA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800CECA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x800CECAC: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800CECB0: jal         0x80035CD0
    // 0x800CECB4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x800CECB4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_5:
    // 0x800CECB8: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800CECBC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800CECC0: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800CECC4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CECC8: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800CECCC: jal         0x80033510
    // 0x800CECD0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800CECD0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_6:
    // 0x800CECD4: jal         0x80018948
    // 0x800CECD8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800CECD8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800CECDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CECE0: lwc1        $f8, 0x5FC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5FC0);
    // 0x800CECE4: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800CECE8: mul.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800CECEC: jal         0x800303F0
    // 0x800CECF0: nop

    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x800CECF0: nop

    after_8:
    // 0x800CECF4: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800CECF8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800CECFC: mul.s       $f24, $f0, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800CED00: jal         0x80035CD0
    // 0x800CED04: nop

    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800CED04: nop

    after_9:
    // 0x800CED08: mul.s       $f22, $f0, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800CED0C: jal         0x800303F0
    // 0x800CED10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800CED10: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_10:
    // 0x800CED14: mul.s       $f20, $f0, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800CED18: jal         0x80035CD0
    // 0x800CED1C: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    __cosf_recomp(rdram, ctx);
        goto after_11;
    // 0x800CED1C: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    after_11:
    // 0x800CED20: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800CED24: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800CED28: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800CED2C: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800CED30: neg.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = -ctx->f22.fl;
    // 0x800CED34: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800CED38: mul.s       $f6, $f22, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x800CED3C: nop

    // 0x800CED40: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800CED44: nop

    // 0x800CED48: mul.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f26.fl);
    // 0x800CED4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CED50: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CED54: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x800CED58: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800CED5C: nop

    // 0x800CED60: mul.s       $f4, $f2, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x800CED64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CED68: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CED6C: nop

    // 0x800CED70: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800CED74: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CED78: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CED7C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x800CED80: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x800CED84: nop

    // 0x800CED88: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800CED8C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800CED90: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CED94: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CED98: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x800CED9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CEDA0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800CEDA4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800CEDA8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800CEDAC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800CEDB0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800CEDB4: jr          $ra
    // 0x800CEDB8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800CEDB8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void wpLinkBoomerangCheckBound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D40C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016D410: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016D414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016D418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016D41C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8016D420: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8016D424: jal         0x800C7C0C
    // 0x8016D428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    lbCommonSim2D(rdram, ctx);
        goto after_0;
    // 0x8016D428: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016D42C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016D430: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8016D434: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D438: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8016D43C: nop

    // 0x8016D440: bc1fl       L_8016D4A4
    if (!c1cs) {
        // 0x8016D444: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016D4A4;
    }
    goto skip_0;
    // 0x8016D444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8016D448: lwc1        $f12, -0x3438($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3438);
    // 0x8016D44C: jal         0x800303F0
    // 0x8016D450: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016D450: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8016D454: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8016D458: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8016D45C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016D460: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8016D464: nop

    // 0x8016D468: bc1f        L_8016D498
    if (!c1cs) {
        // 0x8016D46C: nop
    
            goto L_8016D498;
    }
    // 0x8016D46C: nop

    // 0x8016D470: jal         0x800C7B08
    // 0x8016D474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    lbCommonReflect2D(rdram, ctx);
        goto after_2;
    // 0x8016D474: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8016D478: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8016D47C: jal         0x8001863C
    // 0x8016D480: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8016D480: lwc1        $f14, 0x20($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X20);
    after_3:
    // 0x8016D484: swc1        $f0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f0.u32l;
    // 0x8016D488: jal         0x8016CC50
    // 0x8016D48C: addiu       $a0, $s0, 0x2A4
    ctx->r4 = ADD32(ctx->r16, 0X2A4);
    wpLinkBoomerangClampAngle360(rdram, ctx);
        goto after_4;
    // 0x8016D48C: addiu       $a0, $s0, 0x2A4
    ctx->r4 = ADD32(ctx->r16, 0X2A4);
    after_4:
    // 0x8016D490: b           L_8016D4A4
    // 0x8016D494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016D4A4;
    // 0x8016D494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016D498:
    // 0x8016D498: b           L_8016D4A4
    // 0x8016D49C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016D4A4;
    // 0x8016D49C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016D4A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016D4A4:
    // 0x8016D4A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016D4A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016D4AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016D4B0: jr          $ra
    // 0x8016D4B4: nop

    return;
    // 0x8016D4B4: nop

;}
RECOMP_FUNC void gmCameraMakeMovieCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010DB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010DB34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8010DB38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8010DB3C: jal         0x8010D7E8
    // 0x8010DB40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    gmCameraMakeDefaultCamera(rdram, ctx);
        goto after_0;
    // 0x8010DB40: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8010DB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010DB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010DB4C: jr          $ra
    // 0x8010DB50: nop

    return;
    // 0x8010DB50: nop

;}
RECOMP_FUNC void itPakkunAppearProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D334: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017D338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D33C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8017D340: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8017D344: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017D348: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017D34C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D350: lwc1        $f4, 0x294($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017D354: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017D358: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8017D35C: nop

    // 0x8017D360: bc1fl       L_8017D420
    if (!c1cs) {
        // 0x8017D364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017D420;
    }
    goto skip_0;
    // 0x8017D364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017D368: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8017D36C: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x8017D370: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D374: lw          $t7, 0x5C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X5C);
    // 0x8017D378: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x8017D37C: lwc1        $f8, -0x31F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X31F8);
    // 0x8017D380: swc1        $f8, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f8.u32l;
    // 0x8017D384: lw          $a2, 0x294($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X294);
    // 0x8017D388: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x8017D38C: lw          $a0, 0x29C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X29C);
    // 0x8017D390: jal         0x801409BC
    // 0x8017D394: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    ftCommonDamageGetKnockbackAngle(rdram, ctx);
        goto after_0;
    // 0x8017D394: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017D398: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8017D39C: jal         0x80035CD0
    // 0x8017D3A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017D3A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8017D3A4: lw          $t8, 0x2A4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2A4);
    // 0x8017D3A8: lwc1        $f10, 0x294($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017D3AC: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8017D3B0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8017D3B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8017D3B8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017D3BC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017D3C0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x8017D3C4: jal         0x800303F0
    // 0x8017D3C8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017D3C8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8017D3CC: lwc1        $f8, 0x294($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017D3D0: sw          $zero, 0x248($s0)
    MEM_W(0X248, ctx->r16) = 0;
    // 0x8017D3D4: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8017D3D8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8017D3DC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8017D3E0: jal         0x8017CF80
    // 0x8017D3E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    itPakkunDamagedSetStatus(rdram, ctx);
        goto after_3;
    // 0x8017D3E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8017D3E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D3EC: lwc1        $f18, -0x31F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X31F4);
    // 0x8017D3F0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8017D3F4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8017D3F8: swc1        $f18, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f18.u32l;
    // 0x8017D3FC: lw          $t0, 0x13F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X13F0);
    // 0x8017D400: addiu       $t1, $t1, 0xE04
    ctx->r9 = ADD32(ctx->r9, 0XE04);
    // 0x8017D404: lw          $a0, 0x80($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X80);
    // 0x8017D408: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017D40C: jal         0x8000BD54
    // 0x8017D410: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_4;
    // 0x8017D410: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x8017D414: jal         0x8000DF34
    // 0x8017D418: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x8017D418: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8017D41C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017D420:
    // 0x8017D420: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8017D424: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8017D428: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017D42C: jr          $ra
    // 0x8017D430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017D430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayers1PBonusMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133370: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133374: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133378: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013337C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133380: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80133384: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80133388: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8013338C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133390: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133394: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133398: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013339C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801333A0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801333A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801333A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801333AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801333B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801333B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801333B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801333BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801333C0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801333C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801333CC: jal         0x8000B93C
    // 0x801333D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801333D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801333D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801333D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801333DC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801333E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801333E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801333E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801333EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801333F0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801333F4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801333F8: jal         0x80007080
    // 0x801333FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801333FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133404: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133408: jr          $ra
    // 0x8013340C: nop

    return;
    // 0x8013340C: nop

;}
RECOMP_FUNC void sc1PStageClearGetAppendTotalDamageScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132BB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132BBC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80132BC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132BC8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132BCC: jal         0x80009968
    // 0x80132BD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132BD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132BD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BD8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132BDC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132BE0: sw          $v0, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = ctx->r2;
    // 0x80132BE4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80132BE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132BEC: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132BF4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132BF8: jal         0x80009DF4
    // 0x80132BFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132BFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132C00: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80132C04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132C08: lw          $a1, 0x52E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X52E0);
    // 0x80132C0C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132C10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132C14: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x80132C18: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80132C1C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80132C20: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80132C24: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80132C28: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80132C2C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80132C30: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80132C34: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80132C38: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132C3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80132C40: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80132C44: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80132C48: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80132C4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132C50: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80132C54: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80132C58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80132C5C: jal         0x80131E10
    // 0x80132C60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_2;
    // 0x80132C60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x80132C64: jal         0x800269C0
    // 0x80132C68: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80132C68: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_3:
    // 0x80132C6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80132C70: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80132C74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132C78: jr          $ra
    // 0x80132C7C: nop

    return;
    // 0x80132C7C: nop

;}
RECOMP_FUNC void ftCommonAttackAirCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150B00: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80150B04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80150B08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80150B0C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80150B10: lhu         $t6, 0x1BE($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1BE);
    // 0x80150B14: lhu         $t7, 0x1B4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1B4);
    // 0x80150B18: lw          $a2, 0x9C8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C8);
    // 0x80150B1C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80150B20: beql        $t8, $zero, L_80150E6C
    if (ctx->r24 == 0) {
        // 0x80150B24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80150E6C;
    }
    goto skip_0;
    // 0x80150B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80150B28: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80150B2C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80150B30: jal         0x800F3794
    // 0x80150B34: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x80150B34: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    after_0:
    // 0x80150B38: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80150B3C: bne         $v0, $zero, L_80150E68
    if (ctx->r2 != 0) {
        // 0x80150B40: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_80150E68;
    }
    // 0x80150B40: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80150B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80150B48: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80150B4C: jal         0x80146A8C
    // 0x80150B50: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_1;
    // 0x80150B50: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x80150B54: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80150B58: beq         $v0, $zero, L_80150CD0
    if (ctx->r2 == 0) {
        // 0x80150B5C: lw          $a3, 0x40($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X40);
            goto L_80150CD0;
    }
    // 0x80150B5C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80150B60: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
    // 0x80150B64: bgez        $v0, L_80150B74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80150B68: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80150B74;
    }
    // 0x80150B68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80150B6C: b           L_80150B74
    // 0x80150B70: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80150B74;
    // 0x80150B70: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80150B74:
    // 0x80150B74: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80150B78: beq         $at, $zero, L_80150BF4
    if (ctx->r1 == 0) {
        // 0x80150B7C: nop
    
            goto L_80150BF4;
    }
    // 0x80150B7C: nop

    // 0x80150B80: lb          $v0, 0x1C3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C3);
    // 0x80150B84: bgez        $v0, L_80150B94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80150B88: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80150B94;
    }
    // 0x80150B88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80150B8C: b           L_80150B94
    // 0x80150B90: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80150B94;
    // 0x80150B90: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80150B94:
    // 0x80150B94: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80150B98: beq         $at, $zero, L_80150BF4
    if (ctx->r1 == 0) {
        // 0x80150B9C: nop
    
            goto L_80150BF4;
    }
    // 0x80150B9C: nop

    // 0x80150BA0: lw          $t9, 0x84C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84C);
    // 0x80150BA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80150BA8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80150BAC: lw          $t0, 0x84($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X84);
    // 0x80150BB0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80150BB4: bnel        $t1, $at, L_80150BD0
    if (ctx->r9 != ctx->r1) {
        // 0x80150BB8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80150BD0;
    }
    goto skip_1;
    // 0x80150BB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80150BBC: jal         0x80146690
    // 0x80150BC0: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_2;
    // 0x80150BC0: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    after_2:
    // 0x80150BC4: b           L_80150E6C
    // 0x80150BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150E6C;
    // 0x80150BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80150BCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80150BD0:
    // 0x80150BD0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80150BD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80150BD8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80150BDC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80150BE0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80150BE4: jal         0x80172AEC
    // 0x80150BE8: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_3;
    // 0x80150BE8: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_3:
    // 0x80150BEC: b           L_80150E6C
    // 0x80150BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80150E6C;
    // 0x80150BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80150BF4:
    // 0x80150BF4: jal         0x800E8000
    // 0x80150BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_4;
    // 0x80150BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80150BFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150C00: lwc1        $f4, -0x3AFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3AFC);
    // 0x80150C04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150C08: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80150C0C: nop

    // 0x80150C10: bc1f        L_80150C38
    if (!c1cs) {
        // 0x80150C14: nop
    
            goto L_80150C38;
    }
    // 0x80150C14: nop

    // 0x80150C18: lbu         $t2, 0x26B($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X26B);
    // 0x80150C1C: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x80150C20: beq         $at, $zero, L_80150C30
    if (ctx->r1 == 0) {
        // 0x80150C24: nop
    
            goto L_80150C30;
    }
    // 0x80150C24: nop

    // 0x80150C28: b           L_80150CC0
    // 0x80150C2C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
        goto L_80150CC0;
    // 0x80150C2C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
L_80150C30:
    // 0x80150C30: b           L_80150CC0
    // 0x80150C34: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
        goto L_80150CC0;
    // 0x80150C34: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
L_80150C38:
    // 0x80150C38: lwc1        $f6, -0x3AF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3AF8);
    // 0x80150C3C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80150C40: nop

    // 0x80150C44: bc1fl       L_80150C70
    if (!c1cs) {
        // 0x80150C48: lb          $t4, 0x1C2($s0)
        ctx->r12 = MEM_B(ctx->r16, 0X1C2);
            goto L_80150C70;
    }
    goto skip_2;
    // 0x80150C48: lb          $t4, 0x1C2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1C2);
    skip_2:
    // 0x80150C4C: lbu         $t3, 0x26B($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X26B);
    // 0x80150C50: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x80150C54: beq         $at, $zero, L_80150C64
    if (ctx->r1 == 0) {
        // 0x80150C58: nop
    
            goto L_80150C64;
    }
    // 0x80150C58: nop

    // 0x80150C5C: b           L_80150CC0
    // 0x80150C60: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
        goto L_80150CC0;
    // 0x80150C60: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
L_80150C64:
    // 0x80150C64: b           L_80150CC0
    // 0x80150C68: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
        goto L_80150CC0;
    // 0x80150C68: addiu       $a1, $zero, 0x75
    ctx->r5 = ADD32(0, 0X75);
    // 0x80150C6C: lb          $t4, 0x1C2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1C2);
L_80150C70:
    // 0x80150C70: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80150C74: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80150C78: mflo        $t6
    ctx->r14 = lo;
    // 0x80150C7C: bltzl       $t6, L_80150CA8
    if (SIGNED(ctx->r14) < 0) {
        // 0x80150C80: lbu         $t8, 0x26A($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X26A);
            goto L_80150CA8;
    }
    goto skip_3;
    // 0x80150C80: lbu         $t8, 0x26A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26A);
    skip_3:
    // 0x80150C84: lbu         $t7, 0x26A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X26A);
    // 0x80150C88: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80150C8C: beq         $at, $zero, L_80150C9C
    if (ctx->r1 == 0) {
        // 0x80150C90: nop
    
            goto L_80150C9C;
    }
    // 0x80150C90: nop

    // 0x80150C94: b           L_80150CC0
    // 0x80150C98: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
        goto L_80150CC0;
    // 0x80150C98: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
L_80150C9C:
    // 0x80150C9C: b           L_80150CC0
    // 0x80150CA0: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
        goto L_80150CC0;
    // 0x80150CA0: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    // 0x80150CA4: lbu         $t8, 0x26A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26A);
L_80150CA8:
    // 0x80150CA8: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x80150CAC: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80150CB0: beq         $at, $zero, L_80150CC0
    if (ctx->r1 == 0) {
        // 0x80150CB4: nop
    
            goto L_80150CC0;
    }
    // 0x80150CB4: nop

    // 0x80150CB8: b           L_80150CC0
    // 0x80150CBC: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
        goto L_80150CC0;
    // 0x80150CBC: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
L_80150CC0:
    // 0x80150CC0: jal         0x80146690
    // 0x80150CC4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_5;
    // 0x80150CC4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x80150CC8: b           L_80150E6C
    // 0x80150CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150E6C;
    // 0x80150CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150CD0:
    // 0x80150CD0: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
    // 0x80150CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80150CD8: bgez        $v0, L_80150CE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80150CDC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80150CE8;
    }
    // 0x80150CDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80150CE0: b           L_80150CE8
    // 0x80150CE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80150CE8;
    // 0x80150CE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80150CE8:
    // 0x80150CE8: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80150CEC: beql        $at, $zero, L_80150D30
    if (ctx->r1 == 0) {
        // 0x80150CF0: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80150D30;
    }
    goto skip_4;
    // 0x80150CF0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    skip_4:
    // 0x80150CF4: lb          $v0, 0x1C3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C3);
    // 0x80150CF8: bgez        $v0, L_80150D08
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80150CFC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80150D08;
    }
    // 0x80150CFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80150D00: b           L_80150D08
    // 0x80150D04: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80150D08;
    // 0x80150D04: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80150D08:
    // 0x80150D08: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80150D0C: beql        $at, $zero, L_80150D30
    if (ctx->r1 == 0) {
        // 0x80150D10: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80150D30;
    }
    goto skip_5;
    // 0x80150D10: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    skip_5:
    // 0x80150D14: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
    // 0x80150D18: addiu       $a1, $zero, 0xD1
    ctx->r5 = ADD32(0, 0XD1);
    // 0x80150D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80150D20: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80150D24: b           L_80150DD4
    // 0x80150D28: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
        goto L_80150DD4;
    // 0x80150D28: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80150D2C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
L_80150D30:
    // 0x80150D30: jal         0x800E8000
    // 0x80150D34: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_6;
    // 0x80150D34: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_6:
    // 0x80150D38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150D3C: lwc1        $f8, -0x3AF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3AF4);
    // 0x80150D40: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80150D44: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80150D48: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80150D4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150D50: bc1f        L_80150D6C
    if (!c1cs) {
        // 0x80150D54: nop
    
            goto L_80150D6C;
    }
    // 0x80150D54: nop

    // 0x80150D58: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
    // 0x80150D5C: addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    // 0x80150D60: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80150D64: b           L_80150DD4
    // 0x80150D68: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
        goto L_80150DD4;
    // 0x80150D68: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
L_80150D6C:
    // 0x80150D6C: lwc1        $f10, -0x3AF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3AF0);
    // 0x80150D70: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80150D74: nop

    // 0x80150D78: bc1fl       L_80150D98
    if (!c1cs) {
        // 0x80150D7C: lb          $t9, 0x1C2($s0)
        ctx->r25 = MEM_B(ctx->r16, 0X1C2);
            goto L_80150D98;
    }
    goto skip_6;
    // 0x80150D7C: lb          $t9, 0x1C2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1C2);
    skip_6:
    // 0x80150D80: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
    // 0x80150D84: addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // 0x80150D88: sll         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2 << 13);
    // 0x80150D8C: b           L_80150DD4
    // 0x80150D90: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
        goto L_80150DD4;
    // 0x80150D90: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80150D94: lb          $t9, 0x1C2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1C2);
L_80150D98:
    // 0x80150D98: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80150D9C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80150DA0: mflo        $t1
    ctx->r9 = lo;
    // 0x80150DA4: bltzl       $t1, L_80150DC8
    if (SIGNED(ctx->r9) < 0) {
        // 0x80150DA8: lw          $v0, 0x100($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X100);
            goto L_80150DC8;
    }
    goto skip_7;
    // 0x80150DA8: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
    skip_7:
    // 0x80150DAC: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
    // 0x80150DB0: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80150DB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80150DB8: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x80150DBC: b           L_80150DD4
    // 0x80150DC0: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
        goto L_80150DD4;
    // 0x80150DC0: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80150DC4: lw          $v0, 0x100($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X100);
L_80150DC8:
    // 0x80150DC8: addiu       $a1, $zero, 0xD3
    ctx->r5 = ADD32(0, 0XD3);
    // 0x80150DCC: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x80150DD0: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
L_80150DD4:
    // 0x80150DD4: beq         $a3, $zero, L_80150E0C
    if (ctx->r7 == 0) {
        // 0x80150DD8: nop
    
            goto L_80150E0C;
    }
    // 0x80150DD8: nop

    // 0x80150DDC: lw          $v1, 0x84C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84C);
    // 0x80150DE0: beq         $v1, $zero, L_80150E0C
    if (ctx->r3 == 0) {
        // 0x80150DE4: nop
    
            goto L_80150E0C;
    }
    // 0x80150DE4: nop

    // 0x80150DE8: lw          $t2, 0x84($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X84);
    // 0x80150DEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80150DF0: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80150DF4: bne         $t3, $at, L_80150E0C
    if (ctx->r11 != ctx->r1) {
        // 0x80150DF8: nop
    
            goto L_80150E0C;
    }
    // 0x80150DF8: nop

    // 0x80150DFC: jal         0x801478EC
    // 0x80150E00: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    ftCommonItemShootAirSetStatus(rdram, ctx);
        goto after_7;
    // 0x80150E00: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_7:
    // 0x80150E04: b           L_80150E6C
    // 0x80150E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150E6C;
    // 0x80150E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150E0C:
    // 0x80150E0C: beq         $v0, $zero, L_80150E68
    if (ctx->r2 == 0) {
        // 0x80150E10: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80150E68;
    }
    // 0x80150E10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80150E14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80150E18: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x80150E1C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80150E20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80150E24: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80150E28: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80150E2C: jal         0x800E6F24
    // 0x80150E30: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    ftMainSetStatus(rdram, ctx);
        goto after_8;
    // 0x80150E30: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x80150E34: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80150E38: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x80150E3C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80150E40: bne         $a1, $at, L_80150E50
    if (ctx->r5 != ctx->r1) {
        // 0x80150E44: addiu       $t5, $t5, 0x8E0
        ctx->r13 = ADD32(ctx->r13, 0X8E0);
            goto L_80150E50;
    }
    // 0x80150E44: addiu       $t5, $t5, 0x8E0
    ctx->r13 = ADD32(ctx->r13, 0X8E0);
    // 0x80150E48: sw          $t5, 0x9F8($s0)
    MEM_W(0X9F8, ctx->r16) = ctx->r13;
    // 0x80150E4C: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
L_80150E50:
    // 0x80150E50: jal         0x800E0830
    // 0x80150E54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_9;
    // 0x80150E54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x80150E58: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80150E5C: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    // 0x80150E60: b           L_80150E6C
    // 0x80150E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150E6C;
    // 0x80150E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150E68:
    // 0x80150E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80150E6C:
    // 0x80150E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80150E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80150E74: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80150E78: jr          $ra
    // 0x80150E7C: nop

    return;
    // 0x80150E7C: nop

;}
RECOMP_FUNC void itStarmieNFollowInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801820CC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801820D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801820D4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801820D8: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x801820DC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801820E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801820E4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801820E8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801820EC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801820F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801820F4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x801820F8: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x801820FC: lw          $s4, 0x74($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X74);
    // 0x80182100: beq         $s0, $zero, L_801821A0
    if (ctx->r16 == 0) {
        // 0x80182104: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801821A0;
    }
    // 0x80182104: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80182108: lwc1        $f20, 0x54($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018210C: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x80182110: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
L_80182114:
    // 0x80182114: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80182118: beql        $s0, $t7, L_80182194
    if (ctx->r16 == ctx->r15) {
        // 0x8018211C: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80182194;
    }
    goto skip_0;
    // 0x8018211C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80182120: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x80182124: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x80182128: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018212C: beql        $t8, $t9, L_80182194
    if (ctx->r24 == ctx->r25) {
        // 0x80182130: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80182194;
    }
    goto skip_1;
    // 0x80182130: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80182134: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80182138: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    // 0x8018213C: jal         0x8001902C
    // 0x80182140: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80182140: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x80182144: bne         $s1, $zero, L_8018215C
    if (ctx->r17 != 0) {
        // 0x80182148: lwc1        $f2, 0x48($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
            goto L_8018215C;
    }
    // 0x80182148: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018214C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80182150: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80182154: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80182158: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
L_8018215C:
    // 0x8018215C: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80182160: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80182164: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80182168: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018216C: nop

    // 0x80182170: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80182174: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80182178: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8018217C: nop

    // 0x80182180: bc1f        L_80182190
    if (!c1cs) {
        // 0x80182184: nop
    
            goto L_80182190;
    }
    // 0x80182184: nop

    // 0x80182188: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018218C: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
L_80182190:
    // 0x80182190: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80182194:
    // 0x80182194: bnel        $s0, $zero, L_80182114
    if (ctx->r16 != 0) {
        // 0x80182198: lw          $t7, 0x8($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X8);
            goto L_80182114;
    }
    goto skip_2;
    // 0x80182198: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    skip_2:
    // 0x8018219C: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
L_801821A0:
    // 0x801821A0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x801821A4: jal         0x80181EF4
    // 0x801821A8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    itStarmieNFollowFindFollowPlayerLR(rdram, ctx);
        goto after_1;
    // 0x801821A8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_1:
    // 0x801821AC: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x801821B0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801821B4: bnel        $t0, $at, L_801821C8
    if (ctx->r8 != ctx->r1) {
        // 0x801821B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801821C8;
    }
    goto skip_3;
    // 0x801821B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x801821BC: jal         0x800269C0
    // 0x801821C0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801821C0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_2:
    // 0x801821C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801821C8:
    // 0x801821C8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801821CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801821D0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801821D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801821D8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801821DC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801821E0: jr          $ra
    // 0x801821E4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801821E4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_ovl10_80133634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133634: jr          $ra
    // 0x80133638: nop

    return;
    // 0x80133638: nop

;}
RECOMP_FUNC void func_ovl8_80373790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373798: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8037379C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x803737A0: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x803737A4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x803737A8: nop

    // 0x803737AC: bc1fl       L_803737D0
    if (!c1cs) {
        // 0x803737B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803737D0;
    }
    goto skip_0;
    // 0x803737B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803737B4: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x803737B8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x803737BC: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x803737C0: lh          $t6, 0x40($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X40);
    // 0x803737C4: jalr        $t9
    // 0x803737C8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803737C8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x803737CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803737D0:
    // 0x803737D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803737D4: jr          $ra
    // 0x803737D8: nop

    return;
    // 0x803737D8: nop

;}
RECOMP_FUNC void syVectorNormScaleAddScaled3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001917C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80019180: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019184: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019188: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001918C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80019190: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80019194: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80019198: nop

    // 0x8001919C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800191A0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800191A4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800191A8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800191AC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800191B0: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800191B4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800191B8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800191BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800191C0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800191C4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800191C8: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800191CC: mul.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800191D0: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800191D4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800191D8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800191DC: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800191E0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800191E4: jal         0x80018EE0
    // 0x800191E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x800191E8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    after_0:
    // 0x800191EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800191F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800191F4: jr          $ra
    // 0x800191F8: nop

    return;
    // 0x800191F8: nop

;}
RECOMP_FUNC void mvEndingMakeRoomFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013214C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132150: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132154: sw          $t6, 0x2BF8($at)
    MEM_W(0X2BF8, ctx->r1) = ctx->r14;
    // 0x80132158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013215C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132160: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132164: jal         0x80009968
    // 0x80132168: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132168: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013216C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132170: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132174: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132178: sw          $v0, 0x2C00($at)
    MEM_W(0X2C00, ctx->r1) = ctx->r2;
    // 0x8013217C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132180: addiu       $a1, $a1, 0x1FE8
    ctx->r5 = ADD32(ctx->r5, 0X1FE8);
    // 0x80132184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132188: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8013218C: jal         0x80009DF4
    // 0x80132190: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132190: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013219C: jr          $ra
    // 0x801321A0: nop

    return;
    // 0x801321A0: nop

;}
RECOMP_FUNC void syAudioSetQuality(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020A38: jr          $ra
    // 0x80020A3C: sw          $a0, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = ctx->r4;
    return;
    // 0x80020A3C: sw          $a0, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void mvOpeningSamusMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DD5C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DD60: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DD64: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DD68: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD6C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD70: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD74: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD7C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD80: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD84: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD88: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD8C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD90: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD94: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD9C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DDA0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DDA4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DDA8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DDAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DDB0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DDB4: jal         0x8000B93C
    // 0x8018DDB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DDB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DDBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DDC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DDC4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DDC8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DDCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DDD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DDD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DDD8: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DDDC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DDE0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DDE4: jal         0x80007080
    // 0x8018DDE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DDE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DDEC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DDF0: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DDF4: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DDF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DE00: jr          $ra
    // 0x8018DE04: nop

    return;
    // 0x8018DE04: nop

;}
RECOMP_FUNC void func_ovl8_80372D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372D74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80372D78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80372D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372D80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80372D84: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80372D88: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80372D8C: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x80372D90: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80372D94: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80372D98: jal         0x80371D08
    // 0x80372D9C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_ovl8_80371D08(rdram, ctx);
        goto after_0;
    // 0x80372D9C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80372DA0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80372DA4: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x80372DA8: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x80372DAC: lh          $t6, 0x78($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X78);
    // 0x80372DB0: jalr        $t9
    // 0x80372DB4: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372DB4: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    after_1:
    // 0x80372DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372DC0: jr          $ra
    // 0x80372DC4: nop

    return;
    // 0x80372DC4: nop

;}
RECOMP_FUNC void syDebugFileLoaderThread8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800233A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800233A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800233AC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x800233B0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800233B4: addiu       $s5, $s5, -0x1C10
    ctx->r21 = ADD32(ctx->r21, -0X1C10);
    // 0x800233B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800233BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800233C0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800233C4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800233C8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800233CC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800233D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800233D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800233D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800233DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800233E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800233E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800233E8: addiu       $a2, $a2, -0x1C18
    ctx->r6 = ADD32(ctx->r6, -0X1C18);
    // 0x800233EC: addiu       $a0, $a0, -0x1C20
    ctx->r4 = ADD32(ctx->r4, -0X1C20);
    // 0x800233F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800233F4: jal         0x800009D8
    // 0x800233F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sySchedulerAddClient(rdram, ctx);
        goto after_0;
    // 0x800233F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800233FC: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80023400: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80023404: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80023408: addiu       $s1, $s1, -0x3188
    ctx->r17 = ADD32(ctx->r17, -0X3188);
    // 0x8002340C: addiu       $s3, $s3, -0x1C28
    ctx->r19 = ADD32(ctx->r19, -0X1C28);
    // 0x80023410: addiu       $s7, $s7, -0x491C
    ctx->r23 = ADD32(ctx->r23, -0X491C);
    // 0x80023414: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80023418: addiu       $s6, $sp, 0x54
    ctx->r22 = ADD32(ctx->r29, 0X54);
    // 0x8002341C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
L_80023420:
    // 0x80023420: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80023424:
    // 0x80023424: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80023428: jal         0x80030210
    // 0x8002342C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8002342C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80023430: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80023434: bnel        $t6, $zero, L_80023424
    if (ctx->r14 != 0) {
        // 0x80023438: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80023424;
    }
    goto skip_0;
    // 0x80023438: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x8002343C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80023440: bnel        $s4, $v0, L_80023454
    if (ctx->r20 != ctx->r2) {
        // 0x80023444: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80023454;
    }
    goto skip_1;
    // 0x80023444: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x80023448: b           L_80023454
    // 0x8002344C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80023454;
    // 0x8002344C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80023450: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80023454:
    // 0x80023454: slti        $at, $s0, 0x12C
    ctx->r1 = SIGNED(ctx->r16) < 0X12C ? 1 : 0;
    // 0x80023458: bne         $at, $zero, L_80023420
    if (ctx->r1 != 0) {
        // 0x8002345C: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80023420;
    }
    // 0x8002345C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80023460: sb          $fp, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r30;
    // 0x80023464: jal         0x80034870
    // 0x80023468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_2;
    // 0x80023468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8002346C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80023470: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023474: jal         0x80034790
    // 0x80023478: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x80023478: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    after_3:
    // 0x8002347C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023480: jal         0x80022908
    // 0x80023484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_4;
    // 0x80023484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80023488: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x8002348C: jal         0x80022908
    // 0x80023490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_5;
    // 0x80023490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80023494: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023498: jal         0x80022908
    // 0x8002349C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_6;
    // 0x8002349C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800234A0: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    // 0x800234A4: jal         0x80022908
    // 0x800234A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_7;
    // 0x800234A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800234AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800234B0: jal         0x80022908
    // 0x800234B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_8;
    // 0x800234B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800234B8: ori         $a0, $zero, 0x8200
    ctx->r4 = 0 | 0X8200;
    // 0x800234BC: jal         0x80022908
    // 0x800234C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_9;
    // 0x800234C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800234C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800234C8: jal         0x80022908
    // 0x800234CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_10;
    // 0x800234CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800234D0: addiu       $a0, $zero, 0x4100
    ctx->r4 = ADD32(0, 0X4100);
    // 0x800234D4: jal         0x80022908
    // 0x800234D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_11;
    // 0x800234D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800234DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800234E0: jal         0x80022908
    // 0x800234E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_12;
    // 0x800234E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x800234E8: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    // 0x800234EC: jal         0x80022908
    // 0x800234F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_13;
    // 0x800234F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x800234F4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800234F8: addiu       $a0, $a0, 0xCE0
    ctx->r4 = ADD32(ctx->r4, 0XCE0);
    // 0x800234FC: jal         0x80022984
    // 0x80023500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    syDebugFramebufferPrintThreadStatus(rdram, ctx);
        goto after_14;
    // 0x80023500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80023504: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80023508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002350C: beql        $t7, $zero, L_80023558
    if (ctx->r15 == 0) {
        // 0x80023510: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80023558;
    }
    goto skip_2;
    // 0x80023510: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_2:
    // 0x80023514: jal         0x80022908
    // 0x80023518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_15;
    // 0x80023518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8002351C: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80023520: jal         0x80022908
    // 0x80023524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_16;
    // 0x80023524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80023528: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8002352C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80023530: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80023534: jal         0x800223F4
    // 0x80023538: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_17;
    // 0x80023538: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    after_17:
    // 0x8002353C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80023540: jal         0x80023010
    // 0x80023544: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    syDebugResetMesgCursor(rdram, ctx);
        goto after_18;
    // 0x80023544: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_18:
    // 0x80023548: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002354C: jalr        $t9
    // 0x80023550: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x80023550: nop

    after_19:
    // 0x80023554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80023558:
    // 0x80023558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002355C: jal         0x80022908
    // 0x80023560: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_20;
    // 0x80023560: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_20:
    // 0x80023564: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80023568: jal         0x80022908
    // 0x8002356C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_21;
    // 0x8002356C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80023570: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023574: jal         0x80034790
    // 0x80023578: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_22;
    // 0x80023578: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_22:
    // 0x8002357C: b           L_80023420
    // 0x80023580: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
        goto L_80023420;
    // 0x80023580: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80023584: nop

    // 0x80023588: nop

    // 0x8002358C: nop

    // 0x80023590: nop

    // 0x80023594: nop

    // 0x80023598: nop

    // 0x8002359C: nop

    // 0x800235A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800235A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800235A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800235AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800235B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800235B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800235B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800235BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800235C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800235C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800235C8: jr          $ra
    // 0x800235CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800235CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void syVideoGetFillColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006D70: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80006D74: lw          $t6, 0x6674($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6674);
    // 0x80006D78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80006D7C: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x80006D80: bne         $t6, $at, L_80006D90
    if (ctx->r14 != ctx->r1) {
        // 0x80006D84: andi        $t8, $t7, 0xF800
        ctx->r24 = ctx->r15 & 0XF800;
            goto L_80006D90;
    }
    // 0x80006D84: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x80006D88: jr          $ra
    // 0x80006D8C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80006D8C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80006D90:
    // 0x80006D90: srl         $t9, $a0, 13
    ctx->r25 = S32(U32(ctx->r4) >> 13);
    // 0x80006D94: andi        $t0, $t9, 0x7C0
    ctx->r8 = ctx->r25 & 0X7C0;
    // 0x80006D98: srl         $t2, $a0, 10
    ctx->r10 = S32(U32(ctx->r4) >> 10);
    // 0x80006D9C: andi        $t3, $t2, 0x3E
    ctx->r11 = ctx->r10 & 0X3E;
    // 0x80006DA0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80006DA4: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x80006DA8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80006DAC: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80006DB0: or          $v0, $t4, $t6
    ctx->r2 = ctx->r12 | ctx->r14;
    // 0x80006DB4: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80006DB8: or          $v1, $t7, $v0
    ctx->r3 = ctx->r15 | ctx->r2;
    // 0x80006DBC: jr          $ra
    // 0x80006DC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80006DC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_8037CFAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CFAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037CFB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CFB4: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8037CFB8: beql        $v0, $zero, L_8037CFCC
    if (ctx->r2 == 0) {
        // 0x8037CFBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037CFCC;
    }
    goto skip_0;
    // 0x8037CFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037CFC0: jalr        $v0
    // 0x8037CFC4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8037CFC4: nop

    after_0:
    // 0x8037CFC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037CFCC:
    // 0x8037CFCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CFD0: jr          $ra
    // 0x8037CFD4: nop

    return;
    // 0x8037CFD4: nop

;}
RECOMP_FUNC void gcAddCameraForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009768: bne         $a0, $zero, L_80009778
    if (ctx->r4 != 0) {
        // 0x8000976C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80009778;
    }
    // 0x8000976C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80009770: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80009774: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
L_80009778:
    // 0x80009778: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000977C: sb          $t6, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r14;
    // 0x80009780: jal         0x800080DC
    // 0x80009784: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gcGetCObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80009784: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80009788: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8000978C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80009790: sw          $v0, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r2;
    // 0x80009794: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80009798: jal         0x8000711C
    // 0x8000979C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    syRdpSetDefaultViewport(rdram, ctx);
        goto after_1;
    // 0x8000979C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800097A0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800097A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800097A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800097AC: sw          $zero, 0x60($a1)
    MEM_W(0X60, ctx->r5) = 0;
    // 0x800097B0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800097B4:
    // 0x800097B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800097B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800097BC: bne         $v0, $a0, L_800097B4
    if (ctx->r2 != ctx->r4) {
        // 0x800097C0: sw          $zero, 0x60($v1)
        MEM_W(0X60, ctx->r3) = 0;
            goto L_800097B4;
    }
    // 0x800097C0: sw          $zero, 0x60($v1)
    MEM_W(0X60, ctx->r3) = 0;
    // 0x800097C4: sw          $zero, 0x80($a1)
    MEM_W(0X80, ctx->r5) = 0;
    // 0x800097C8: sw          $zero, 0x84($a1)
    MEM_W(0X84, ctx->r5) = 0;
    // 0x800097CC: sw          $zero, 0x88($a1)
    MEM_W(0X88, ctx->r5) = 0;
    // 0x800097D0: sw          $zero, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = 0;
    // 0x800097D4: sw          $zero, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = 0;
    // 0x800097D8: sw          $zero, 0x70($a1)
    MEM_W(0X70, ctx->r5) = 0;
    // 0x800097DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800097E0: lwc1        $f4, -0x2288($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2288);
    // 0x800097E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800097E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800097EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800097F0: swc1        $f4, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f4.u32l;
    // 0x800097F4: swc1        $f6, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f6.u32l;
    // 0x800097F8: swc1        $f8, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f8.u32l;
    // 0x800097FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009804: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80009808: jr          $ra
    // 0x8000980C: nop

    return;
    // 0x8000980C: nop

;}
RECOMP_FUNC void ftParamSetMotionID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA5E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA5EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA5F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EA5F4: jal         0x800EA5BC
    // 0x800EA5F8: sw          $a1, 0x288($a0)
    MEM_W(0X288, ctx->r4) = ctx->r5;
    ftParamGetMotionCount(rdram, ctx);
        goto after_0;
    // 0x800EA5F8: sw          $a1, 0x288($a0)
    MEM_W(0X288, ctx->r4) = ctx->r5;
    after_0:
    // 0x800EA5FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800EA600: sh          $v0, 0x28C($t7)
    MEM_H(0X28C, ctx->r15) = ctx->r2;
    // 0x800EA604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA60C: jr          $ra
    // 0x800EA610: nop

    return;
    // 0x800EA610: nop

;}
RECOMP_FUNC void func_ovl8_80376AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80376AA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80376AAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80376AB0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80376AB4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80376AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376ABC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80376AC0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80376AC4: jal         0x80023888
    // 0x80376AC8: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    spMove(rdram, ctx);
        goto after_0;
    // 0x80376AC8: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    after_0:
    // 0x80376ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80376AD4: jr          $ra
    // 0x80376AD8: nop

    return;
    // 0x80376AD8: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801569D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801569D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801569DC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801569E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801569E4: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x801569E8: beql        $t6, $zero, L_80156A68
    if (ctx->r14 == 0) {
        // 0x801569EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156A68;
    }
    goto skip_0;
    // 0x801569EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801569F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801569F4: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x801569F8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x801569FC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80156A00: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80156A04: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80156A08: lw          $a0, 0x92C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X92C);
    // 0x80156A0C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80156A10: jal         0x800EDF24
    // 0x80156A14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80156A14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80156A18: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80156A1C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80156A20: lw          $t7, 0xADC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XADC);
    // 0x80156A24: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x80156A28: beq         $at, $zero, L_80156A54
    if (ctx->r1 == 0) {
        // 0x80156A2C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80156A54;
    }
    // 0x80156A2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80156A30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80156A34: addu        $at, $at, $t7
    gpr jr_addend_80156A3C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80156A38: lw          $t7, -0x3960($at)
    ctx->r15 = ADD32(ctx->r1, -0X3960);
    // 0x80156A3C: jr          $t7
    // 0x80156A40: nop

    switch (jr_addend_80156A3C >> 2) {
        case 0: goto L_80156A44; break;
        case 1: goto L_80156A54; break;
        case 2: goto L_80156A54; break;
        case 3: goto L_80156A54; break;
        case 4: goto L_80156A4C; break;
        case 5: goto L_80156A54; break;
        case 6: goto L_80156A54; break;
        case 7: goto L_80156A54; break;
        case 8: goto L_80156A54; break;
        case 9: goto L_80156A54; break;
        case 10: goto L_80156A54; break;
        case 11: goto L_80156A54; break;
        case 12: goto L_80156A54; break;
        case 13: goto L_80156A44; break;
        case 14: goto L_80156A44; break;
        case 15: goto L_80156A54; break;
        case 16: goto L_80156A54; break;
        case 17: goto L_80156A54; break;
        case 18: goto L_80156A4C; break;
        default: switch_error(__func__, 0x80156A3C, 0x8018C6A0);
    }
    // 0x80156A40: nop

L_80156A44:
    // 0x80156A44: b           L_80156A54
    // 0x80156A48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_80156A54;
    // 0x80156A48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80156A4C:
    // 0x80156A4C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80156A50: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80156A54:
    // 0x80156A54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80156A58: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80156A5C: jal         0x801687A0
    // 0x80156A60: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    wpMarioFireballMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80156A60: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80156A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156A68:
    // 0x80156A68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80156A6C: jr          $ra
    // 0x80156A70: nop

    return;
    // 0x80156A70: nop

;}

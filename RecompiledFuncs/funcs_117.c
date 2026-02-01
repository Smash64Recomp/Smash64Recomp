#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syVectorDistPlaneToPoint3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019B00: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80019B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019B08: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019B0C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019B10: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80019B14: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80019B18: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019B1C: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019B20: sub.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x80019B24: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80019B28: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80019B2C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019B30: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019B34: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80019B38: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80019B3C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80019B40: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80019B44: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80019B48: sub.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80019B4C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80019B50: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80019B54: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80019B58: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80019B5C: sub.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80019B60: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80019B64: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80019B68: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80019B6C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80019B70: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80019B74: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80019B78: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80019B7C: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x80019B80: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80019B84: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80019B88: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80019B8C: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019B90: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80019B94: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80019B98: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80019B9C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019BA0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019BA4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80019BA8: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80019BAC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80019BB0: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80019BB4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80019BB8: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80019BBC: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80019BC0: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80019BC4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80019BC8: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80019BCC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80019BD0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80019BD4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80019BD8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80019BDC: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80019BE0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80019BE4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019BE8: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80019BEC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019BF0: add.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80019BF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80019BF8: nop

    // 0x80019BFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80019C00: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80019C04: bc1fl       L_80019C24
    if (!c1cs) {
        // 0x80019C08: lwc1        $f10, 0x4C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80019C24;
    }
    goto skip_0;
    // 0x80019C08: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80019C0C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80019C10: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80019C14: add.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80019C18: b           L_80019C38
    // 0x80019C1C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_80019C38;
    // 0x80019C1C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80019C20: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
L_80019C24:
    // 0x80019C24: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019C28: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80019C2C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019C30: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019C34: add.s       $f14, $f10, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f2.fl;
L_80019C38:
    // 0x80019C38: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80019C3C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80019C40: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80019C44: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019C48: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019C4C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80019C50: jal         0x80033510
    // 0x80019C54: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80019C54: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_0:
    // 0x80019C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019C5C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80019C60: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80019C64: jr          $ra
    // 0x80019C68: div.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    return;
    // 0x80019C68: div.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
;}
RECOMP_FUNC void ftDonkeyThrowFCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D480: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014D484: jal         0x800DDDDC
    // 0x8014D488: addiu       $a1, $a1, -0x2568
    ctx->r5 = ADD32(ctx->r5, -0X2568);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8014D488: addiu       $a1, $a1, -0x2568
    ctx->r5 = ADD32(ctx->r5, -0X2568);
    after_0:
    // 0x8014D48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D494: jr          $ra
    // 0x8014D498: nop

    return;
    // 0x8014D498: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeDeskGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132AE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132AEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132AF8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132AFC: jal         0x80009968
    // 0x80132B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B04: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132B08: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80132B0C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132B10: addiu       $t7, $t7, 0x2440
    ctx->r15 = ADD32(ctx->r15, 0X2440);
    // 0x80132B14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132B20: jal         0x8000F120
    // 0x80132B24: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80132B24: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132B28: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132B2C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132B30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132B34: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80132B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B3C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80132B40: jal         0x80009DF4
    // 0x80132B44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132B44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132B48: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132B4C: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80132B50: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x80132B54: addiu       $t0, $t0, 0x480
    ctx->r8 = ADD32(ctx->r8, 0X480);
    // 0x80132B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B5C: jal         0x8000F8F4
    // 0x80132B60: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80132B60: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80132B64: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132B68: lw          $t1, 0x50B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50B0);
    // 0x80132B6C: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80132B70: addiu       $t2, $t2, 0x25CC
    ctx->r10 = ADD32(ctx->r10, 0X25CC);
    // 0x80132B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132B7C: jal         0x8000BE28
    // 0x80132B80: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80132B80: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80132B84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B88: addiu       $a1, $a1, 0x2AB0
    ctx->r5 = ADD32(ctx->r5, 0X2AB0);
    // 0x80132B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132B94: jal         0x80008188
    // 0x80132B98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132B98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132B9C: jal         0x8000DF34
    // 0x80132BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x80132BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80132BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132BA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132BB0: jr          $ra
    // 0x80132BB4: nop

    return;
    // 0x80132BB4: nop

;}
RECOMP_FUNC void func_ovl8_80372A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372A94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80372A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372A9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80372AA0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80372AA4: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x80372AA8: jal         0x80371E2C
    // 0x80372AAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_80371E2C(rdram, ctx);
        goto after_0;
    // 0x80372AAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80372AB0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80372AB4: lw          $t6, -0x5E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E44);
    // 0x80372AB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80372ABC: bnel        $t6, $zero, L_80372B34
    if (ctx->r14 != 0) {
        // 0x80372AC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80372B34;
    }
    goto skip_0;
    // 0x80372AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80372AC4: jal         0x8037D384
    // 0x80372AC8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_8037D384(rdram, ctx);
        goto after_1;
    // 0x80372AC8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80372ACC: beq         $v0, $zero, L_80372B30
    if (ctx->r2 == 0) {
        // 0x80372AD0: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80372B30;
    }
    // 0x80372AD0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80372AD4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80372AD8: jal         0x8037D3AC
    // 0x80372ADC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_8037D3AC(rdram, ctx);
        goto after_2;
    // 0x80372ADC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80372AE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80372AE4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80372AE8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80372AEC: beq         $a2, $zero, L_80372AF8
    if (ctx->r6 == 0) {
        // 0x80372AF0: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80372AF8;
    }
    // 0x80372AF0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80372AF4: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
L_80372AF8:
    // 0x80372AF8: lw          $t8, 0x30($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30);
    // 0x80372AFC: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80372B00: beq         $t9, $zero, L_80372B28
    if (ctx->r25 == 0) {
        // 0x80372B04: nop
    
            goto L_80372B28;
    }
    // 0x80372B04: nop

    // 0x80372B08: jal         0x80372B98
    // 0x80372B0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_80372B98(rdram, ctx);
        goto after_3;
    // 0x80372B0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80372B10: bnel        $v0, $zero, L_80372B34
    if (ctx->r2 != 0) {
        // 0x80372B14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80372B34;
    }
    goto skip_1;
    // 0x80372B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80372B18: jal         0x8037D434
    // 0x80372B1C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_ovl8_8037D434(rdram, ctx);
        goto after_4;
    // 0x80372B1C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x80372B20: b           L_80372B34
    // 0x80372B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80372B34;
    // 0x80372B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80372B28:
    // 0x80372B28: jal         0x8037D434
    // 0x80372B2C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_ovl8_8037D434(rdram, ctx);
        goto after_5;
    // 0x80372B2C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_5:
L_80372B30:
    // 0x80372B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80372B34:
    // 0x80372B34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80372B38: jr          $ra
    // 0x80372B3C: nop

    return;
    // 0x80372B3C: nop

;}
RECOMP_FUNC void func_ovl8_803721E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803721E8: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x803721EC: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x803721F0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x803721F4: beql        $v0, $zero, L_80372218
    if (ctx->r2 == 0) {
        // 0x803721F8: sh          $zero, 0x6($a1)
        MEM_H(0X6, ctx->r5) = 0;
            goto L_80372218;
    }
    goto skip_0;
    // 0x803721F8: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    skip_0:
    // 0x803721FC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80372200: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x80372204: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80372208: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8037220C: jr          $ra
    // 0x80372210: sh          $t8, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r24;
    return;
    // 0x80372210: sh          $t8, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r24;
    // 0x80372214: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
L_80372218:
    // 0x80372218: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8037221C: jr          $ra
    // 0x80372220: nop

    return;
    // 0x80372220: nop

;}
RECOMP_FUNC void mnVSRecordMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013299C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801329A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801329A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801329A8: jal         0x80009968
    // 0x801329AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801329AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801329B0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801329B4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801329B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801329BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801329C0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801329C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801329C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801329CC: jal         0x80009DF4
    // 0x801329D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801329D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801329D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329D8: addiu       $a1, $a1, 0x28D4
    ctx->r5 = ADD32(ctx->r5, 0X28D4);
    // 0x801329DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801329E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801329E4: jal         0x80008188
    // 0x801329E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801329E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801329EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801329F0: lw          $t7, 0x6D88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D88);
    // 0x801329F4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801329F8: addiu       $t8, $t8, 0x15D0
    ctx->r24 = ADD32(ctx->r24, 0X15D0);
    // 0x801329FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132A00: jal         0x800CCFDC
    // 0x80132A04: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132A04: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132A08: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132A0C: lui         $at, 0x435E
    ctx->r1 = S32(0X435E << 16);
    // 0x80132A10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132A14: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80132A18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132A1C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132A20: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132A24: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132A28: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132A2C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132A30: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132A34: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132A38: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132A3C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132A48: jr          $ra
    // 0x80132A4C: nop

    return;
    // 0x80132A4C: nop

;}
RECOMP_FUNC void sc1PGameGetRandomStartPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D45C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018D460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D464: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018D468: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8018D46C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8018D470: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018D474: jal         0x800FC7A4
    // 0x8018D478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_0;
    // 0x8018D478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8018D47C: beq         $v0, $zero, L_8018D490
    if (ctx->r2 == 0) {
        // 0x8018D480: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8018D490;
    }
    // 0x8018D480: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D484: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8018D488: bne         $at, $zero, L_8018D4B4
    if (ctx->r1 != 0) {
        // 0x8018D48C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018D4B4;
    }
    // 0x8018D48C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8018D490:
    // 0x8018D490: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D494: addiu       $s0, $s0, 0x2E38
    ctx->r16 = ADD32(ctx->r16, 0X2E38);
    // 0x8018D498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8018D49C:
    // 0x8018D49C: jal         0x80023624
    // 0x8018D4A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8018D4A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8018D4A4: jal         0x800A3040
    // 0x8018D4A8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_2;
    // 0x8018D4A8: nop

    after_2:
    // 0x8018D4AC: b           L_8018D49C
    // 0x8018D4B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8018D49C;
    // 0x8018D4B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8018D4B4:
    // 0x8018D4B4: jal         0x800FC814
    // 0x8018D4B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_3;
    // 0x8018D4B8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x8018D4BC: jal         0x80018994
    // 0x8018D4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_4;
    // 0x8018D4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8018D4C4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8018D4C8: addu        $a0, $sp, $t6
    ctx->r4 = ADD32(ctx->r29, ctx->r14);
    // 0x8018D4CC: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x8018D4D0: jal         0x800FC894
    // 0x8018D4D4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_5;
    // 0x8018D4D4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x8018D4D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D4DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018D4E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018D4E4: jr          $ra
    // 0x8018D4E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018D4E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnVSModeMakeTimeStockArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132964: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132968: lw          $a0, 0x4968($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4968);
    // 0x8013296C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132970: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132974: beq         $a0, $zero, L_8013298C
    if (ctx->r4 == 0) {
        // 0x80132978: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8013298C;
    }
    // 0x80132978: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013297C: jal         0x80009A84
    // 0x80132980: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132980: nop

    after_0:
    // 0x80132984: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132988: sw          $zero, 0x4968($at)
    MEM_W(0X4968, ctx->r1) = 0;
L_8013298C:
    // 0x8013298C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132994: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132998: jal         0x80009968
    // 0x8013299C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8013299C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801329A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801329A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801329AC: sw          $v0, 0x4968($at)
    MEM_W(0X4968, ctx->r1) = ctx->r2;
    // 0x801329B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801329B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801329B8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801329BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801329C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801329C4: jal         0x80009DF4
    // 0x801329C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801329C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801329CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329D0: addiu       $a1, $a1, 0x28A8
    ctx->r5 = ADD32(ctx->r5, 0X28A8);
    // 0x801329D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801329DC: jal         0x80008188
    // 0x801329E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801329E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801329E4: jal         0x80132B38
    // 0x801329E8: nop

    mnVSModeIsTime(rdram, ctx);
        goto after_4;
    // 0x801329E8: nop

    after_4:
    // 0x801329EC: beq         $v0, $zero, L_80132A1C
    if (ctx->r2 == 0) {
        // 0x801329F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132A1C;
    }
    // 0x801329F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329F8: lui         $a1, 0x431B
    ctx->r5 = S32(0X431B << 16);
    // 0x801329FC: jal         0x80132570
    // 0x80132A00: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    mnVSModeMakeLeftArrow(rdram, ctx);
        goto after_5;
    // 0x80132A00: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    after_5:
    // 0x80132A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A08: lui         $a1, 0x4366
    ctx->r5 = S32(0X4366 << 16);
    // 0x80132A0C: jal         0x801325E4
    // 0x80132A10: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    mnVSModeMakeRightArrow(rdram, ctx);
        goto after_6;
    // 0x80132A10: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    after_6:
    // 0x80132A14: b           L_80132A3C
    // 0x80132A18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132A3C;
    // 0x80132A18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132A1C:
    // 0x80132A1C: lui         $a1, 0x4325
    ctx->r5 = S32(0X4325 << 16);
    // 0x80132A20: jal         0x80132570
    // 0x80132A24: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    mnVSModeMakeLeftArrow(rdram, ctx);
        goto after_7;
    // 0x80132A24: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    after_7:
    // 0x80132A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A2C: lui         $a1, 0x4366
    ctx->r5 = S32(0X4366 << 16);
    // 0x80132A30: jal         0x801325E4
    // 0x80132A34: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    mnVSModeMakeRightArrow(rdram, ctx);
        goto after_8;
    // 0x80132A34: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    after_8:
    // 0x80132A38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132A3C:
    // 0x80132A3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132A44: jr          $ra
    // 0x80132A48: nop

    return;
    // 0x80132A48: nop

;}
RECOMP_FUNC void ftCommonDamageCommonProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014067C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80140680: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80140684: bnel        $t6, $zero, L_80140700
    if (ctx->r14 != 0) {
        // 0x80140688: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80140700;
    }
    goto skip_0;
    // 0x80140688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014068C: lbu         $t7, 0x18F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18F);
    // 0x80140690: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x80140694: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140698: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8014069C: bne         $t9, $at, L_801406D4
    if (ctx->r25 != ctx->r1) {
        // 0x801406A0: sb          $t8, 0x18F($v0)
        MEM_B(0X18F, ctx->r2) = ctx->r24;
            goto L_801406D4;
    }
    // 0x801406A0: sb          $t8, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r24;
    // 0x801406A4: jal         0x800F3794
    // 0x801406A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x801406A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801406AC: beq         $v0, $zero, L_801406C4
    if (ctx->r2 == 0) {
        // 0x801406B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801406C4;
    }
    // 0x801406B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801406B4: jal         0x80147BE0
    // 0x801406B8: nop

    ftCommonHammerFallProcInterrupt(rdram, ctx);
        goto after_1;
    // 0x801406B8: nop

    after_1:
    // 0x801406BC: b           L_80140700
    // 0x801406C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140700;
    // 0x801406C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801406C4:
    // 0x801406C4: jal         0x8013F9A0
    // 0x801406C8: nop

    ftCommonFallProcInterrupt(rdram, ctx);
        goto after_2;
    // 0x801406C8: nop

    after_2:
    // 0x801406CC: b           L_80140700
    // 0x801406D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140700;
    // 0x801406D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801406D4:
    // 0x801406D4: jal         0x800F3794
    // 0x801406D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_3;
    // 0x801406D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x801406DC: beq         $v0, $zero, L_801406F4
    if (ctx->r2 == 0) {
        // 0x801406E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801406F4;
    }
    // 0x801406E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801406E4: jal         0x800F38C4
    // 0x801406E8: nop

    ftHammerProcInterrupt(rdram, ctx);
        goto after_4;
    // 0x801406E8: nop

    after_4:
    // 0x801406EC: b           L_80140700
    // 0x801406F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80140700;
    // 0x801406F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801406F4:
    // 0x801406F4: jal         0x8013E070
    // 0x801406F8: nop

    ftCommonWaitProcInterrupt(rdram, ctx);
        goto after_5;
    // 0x801406F8: nop

    after_5:
    // 0x801406FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80140700:
    // 0x80140700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140704: jr          $ra
    // 0x80140708: nop

    return;
    // 0x80140708: nop

;}
RECOMP_FUNC void lbCommonAddMObjForTreeDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C922C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C9230: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C9234: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C9238: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C923C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C9240: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C9244: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C9248: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C924C: beq         $a0, $zero, L_800C92A8
    if (ctx->r4 == 0) {
        // 0x800C9250: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800C92A8;
    }
    // 0x800C9250: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
L_800C9254:
    // 0x800C9254: beql        $s3, $zero, L_800C9298
    if (ctx->r19 == 0) {
        // 0x800C9258: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9298;
    }
    goto skip_0;
    // 0x800C9258: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x800C925C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800C9260: beql        $v0, $zero, L_800C9294
    if (ctx->r2 == 0) {
        // 0x800C9264: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800C9294;
    }
    goto skip_1;
    // 0x800C9264: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    skip_1:
    // 0x800C9268: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x800C926C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C9270: beq         $s1, $zero, L_800C9290
    if (ctx->r17 == 0) {
        // 0x800C9274: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9290;
    }
    // 0x800C9274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9278:
    // 0x800C9278: jal         0x800090DC
    // 0x800C927C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_0;
    // 0x800C927C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800C9280: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x800C9284: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C9288: bnel        $s1, $zero, L_800C9278
    if (ctx->r17 != 0) {
        // 0x800C928C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C9278;
    }
    goto skip_2;
    // 0x800C928C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_800C9290:
    // 0x800C9290: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_800C9294:
    // 0x800C9294: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800C9298:
    // 0x800C9298: jal         0x800C86E8
    // 0x800C929C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_1;
    // 0x800C929C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800C92A0: bne         $v0, $zero, L_800C9254
    if (ctx->r2 != 0) {
        // 0x800C92A4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800C9254;
    }
    // 0x800C92A4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800C92A8:
    // 0x800C92A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C92AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C92B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C92B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C92B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C92BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C92C0: jr          $ra
    // 0x800C92C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C92C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonCaptureWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AA58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014AA5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014AA60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014AA64: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014AA68: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x8014AA6C: addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    // 0x8014AA70: lw          $t6, 0x844($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X844);
    // 0x8014AA74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014AA78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014AA7C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8014AA80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014AA84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8014AA88: jal         0x800E6F24
    // 0x8014AA8C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014AA8C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x8014AA90: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8014AA94: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8014AA98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014AA9C: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8014AAA0: beq         $v0, $at, L_8014AAB0
    if (ctx->r2 == ctx->r1) {
        // 0x8014AAA4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8014AAB0;
    }
    // 0x8014AAA4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8014AAA8: bnel        $v0, $at, L_8014AAC8
    if (ctx->r2 != ctx->r1) {
        // 0x8014AAAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014AAC8;
    }
    goto skip_0;
    // 0x8014AAAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8014AAB0:
    // 0x8014AAB0: lbu         $t1, 0x18D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014AAB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014AAB8: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8014AABC: jal         0x800E8A24
    // 0x8014AAC0: sb          $t2, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r10;
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_1;
    // 0x8014AAC0: sb          $t2, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r10;
    after_1:
    // 0x8014AAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8014AAC8:
    // 0x8014AAC8: jal         0x800E8098
    // 0x8014AACC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014AACC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x8014AAD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014AAD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014AAD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014AADC: jr          $ra
    // 0x8014AAE0: nop

    return;
    // 0x8014AAE0: nop

;}
RECOMP_FUNC void itMBallOpenProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CB38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017CB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CB40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017CB44: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017CB48: lhu         $a0, 0x2D0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2D0);
    // 0x8017CB4C: jal         0x800FC67C
    // 0x8017CB50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x8017CB50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017CB54: bne         $v0, $zero, L_8017CB70
    if (ctx->r2 != 0) {
        // 0x8017CB58: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8017CB70;
    }
    // 0x8017CB58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CB5C: lbu         $t7, 0x2CF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2CF);
    // 0x8017CB60: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x8017CB64: sb          $t8, 0x2CF($v1)
    MEM_B(0X2CF, ctx->r3) = ctx->r24;
    // 0x8017CB68: jal         0x8017CDE4
    // 0x8017CB6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMBallOpenAirSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017CB6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_8017CB70:
    // 0x8017CB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CB74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017CB78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017CB7C: jr          $ra
    // 0x8017CB80: nop

    return;
    // 0x8017CB80: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D5EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8016D5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016D5F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016D5F8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8016D5FC: lbu         $t6, 0x2A2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2A2);
    // 0x8016D600: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x8016D604: bnel        $t7, $zero, L_8016D704
    if (ctx->r15 != 0) {
        // 0x8016D608: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016D704;
    }
    goto skip_0;
    // 0x8016D608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8016D60C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8016D610: jal         0x80167A58
    // 0x8016D614: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    wpMapTestAll(rdram, ctx);
        goto after_0;
    // 0x8016D614: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    after_0:
    // 0x8016D618: lhu         $v1, 0x82($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X82);
    // 0x8016D61C: lhu         $t8, 0x80($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X80);
    // 0x8016D620: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016D624: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8016D628: xor         $t9, $t8, $v1
    ctx->r25 = ctx->r24 ^ ctx->r3;
    // 0x8016D62C: and         $a1, $t9, $v1
    ctx->r5 = ctx->r25 & ctx->r3;
    // 0x8016D630: andi        $a1, $a1, 0xC21
    ctx->r5 = ctx->r5 & 0XC21;
    // 0x8016D634: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8016D638: beql        $a1, $zero, L_8016D704
    if (ctx->r5 == 0) {
        // 0x8016D63C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016D704;
    }
    goto skip_1;
    // 0x8016D63C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8016D640: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    // 0x8016D644: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016D648: sh          $a1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r5;
    // 0x8016D64C: jal         0x800FECBC
    // 0x8016D650: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustCollideMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016D650: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016D654: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x8016D658: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016D65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D660: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x8016D664: beq         $t1, $zero, L_8016D67C
    if (ctx->r9 == 0) {
        // 0x8016D668: addiu       $a1, $s0, 0xD4
        ctx->r5 = ADD32(ctx->r16, 0XD4);
            goto L_8016D67C;
    }
    // 0x8016D668: addiu       $a1, $s0, 0xD4
    ctx->r5 = ADD32(ctx->r16, 0XD4);
    // 0x8016D66C: jal         0x8016D40C
    // 0x8016D670: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    wpLinkBoomerangCheckBound(rdram, ctx);
        goto after_2;
    // 0x8016D670: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8016D674: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016D678: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8016D67C:
    // 0x8016D67C: andi        $t2, $v1, 0x20
    ctx->r10 = ctx->r3 & 0X20;
    // 0x8016D680: beq         $t2, $zero, L_8016D6A4
    if (ctx->r10 == 0) {
        // 0x8016D684: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016D6A4;
    }
    // 0x8016D684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D688: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    // 0x8016D68C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8016D690: jal         0x8016D40C
    // 0x8016D694: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    wpLinkBoomerangCheckBound(rdram, ctx);
        goto after_3;
    // 0x8016D694: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x8016D698: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016D69C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016D6A0: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_8016D6A4:
    // 0x8016D6A4: andi        $t3, $v1, 0x400
    ctx->r11 = ctx->r3 & 0X400;
    // 0x8016D6A8: beq         $t3, $zero, L_8016D6CC
    if (ctx->r11 == 0) {
        // 0x8016D6AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016D6CC;
    }
    // 0x8016D6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D6B0: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    // 0x8016D6B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8016D6B8: jal         0x8016D40C
    // 0x8016D6BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    wpLinkBoomerangCheckBound(rdram, ctx);
        goto after_4;
    // 0x8016D6BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_4:
    // 0x8016D6C0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016D6C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016D6C8: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_8016D6CC:
    // 0x8016D6CC: andi        $t4, $v1, 0x800
    ctx->r12 = ctx->r3 & 0X800;
    // 0x8016D6D0: beq         $t4, $zero, L_8016D6EC
    if (ctx->r12 == 0) {
        // 0x8016D6D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016D6EC;
    }
    // 0x8016D6D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016D6D8: addiu       $a1, $s0, 0xAC
    ctx->r5 = ADD32(ctx->r16, 0XAC);
    // 0x8016D6DC: jal         0x8016D40C
    // 0x8016D6E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    wpLinkBoomerangCheckBound(rdram, ctx);
        goto after_5;
    // 0x8016D6E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_5:
    // 0x8016D6E4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8016D6E8: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_8016D6EC:
    // 0x8016D6EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016D6F0: bne         $a2, $at, L_8016D700
    if (ctx->r6 != ctx->r1) {
        // 0x8016D6F4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8016D700;
    }
    // 0x8016D6F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8016D6F8: jal         0x8016CDC8
    // 0x8016D6FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpLinkBoomerangSetReturnVars(rdram, ctx);
        goto after_6;
    // 0x8016D6FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_8016D700:
    // 0x8016D700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016D704:
    // 0x8016D704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016D708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8016D70C: jr          $ra
    // 0x8016D710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016D710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftComputerFollowObjectiveCounterAttack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137FD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137FDC: jal         0x801361BC
    // 0x80137FE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_ovl3_801361BC(rdram, ctx);
        goto after_0;
    // 0x80137FE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80137FE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80137FE8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80137FEC: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80137FF0: lw          $v0, 0x48($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X48);
    // 0x80137FF4: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x80137FF8: bgez        $t7, L_8013801C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80137FFC: sll         $t1, $v0, 14
        ctx->r9 = S32(ctx->r2 << 14);
            goto L_8013801C;
    }
    // 0x80137FFC: sll         $t1, $v0, 14
    ctx->r9 = S32(ctx->r2 << 14);
    // 0x80138000: jal         0x80132758
    // 0x80138004: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_1;
    // 0x80138004: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80138008: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013800C: lbu         $t8, 0x49($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X49);
    // 0x80138010: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x80138014: b           L_801380F4
    // 0x80138018: sb          $t9, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r25;
        goto L_801380F4;
    // 0x80138018: sb          $t9, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r25;
L_8013801C:
    // 0x8013801C: bgez        $t1, L_801380B0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80138020: sll         $t5, $v0, 13
        ctx->r13 = S32(ctx->r2 << 13);
            goto L_801380B0;
    }
    // 0x80138020: sll         $t5, $v0, 13
    ctx->r13 = S32(ctx->r2 << 13);
    // 0x80138024: lbu         $t2, 0x49($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X49);
    // 0x80138028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013802C: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x80138030: sb          $t3, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r11;
    // 0x80138034: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80138038: beq         $v0, $at, L_80138060
    if (ctx->r2 == ctx->r1) {
        // 0x8013803C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80138060;
    }
    // 0x8013803C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80138040: beq         $v0, $at, L_80138088
    if (ctx->r2 == ctx->r1) {
        // 0x80138044: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80138088;
    }
    // 0x80138044: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80138048: beq         $v0, $at, L_80138060
    if (ctx->r2 == ctx->r1) {
        // 0x8013804C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80138060;
    }
    // 0x8013804C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80138050: beql        $v0, $at, L_8013808C
    if (ctx->r2 == ctx->r1) {
        // 0x80138054: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_8013808C;
    }
    goto skip_0;
    // 0x80138054: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x80138058: b           L_801380F8
    // 0x8013805C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801380F8;
    // 0x8013805C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138060:
    // 0x80138060: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80138064: slti        $at, $v0, 0xEC
    ctx->r1 = SIGNED(ctx->r2) < 0XEC ? 1 : 0;
    // 0x80138068: bne         $at, $zero, L_80138078
    if (ctx->r1 != 0) {
        // 0x8013806C: slti        $at, $v0, 0xF6
        ctx->r1 = SIGNED(ctx->r2) < 0XF6 ? 1 : 0;
            goto L_80138078;
    }
    // 0x8013806C: slti        $at, $v0, 0xF6
    ctx->r1 = SIGNED(ctx->r2) < 0XF6 ? 1 : 0;
    // 0x80138070: bnel        $at, $zero, L_801380F8
    if (ctx->r1 != 0) {
        // 0x80138074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801380F8;
    }
    goto skip_1;
    // 0x80138074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80138078:
    // 0x80138078: jal         0x80132758
    // 0x8013807C: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_2;
    // 0x8013807C: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_2:
    // 0x80138080: b           L_801380F8
    // 0x80138084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801380F8;
    // 0x80138084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138088:
    // 0x80138088: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_8013808C:
    // 0x8013808C: slti        $at, $v0, 0xED
    ctx->r1 = SIGNED(ctx->r2) < 0XED ? 1 : 0;
    // 0x80138090: bne         $at, $zero, L_801380A0
    if (ctx->r1 != 0) {
        // 0x80138094: slti        $at, $v0, 0xF5
        ctx->r1 = SIGNED(ctx->r2) < 0XF5 ? 1 : 0;
            goto L_801380A0;
    }
    // 0x80138094: slti        $at, $v0, 0xF5
    ctx->r1 = SIGNED(ctx->r2) < 0XF5 ? 1 : 0;
    // 0x80138098: bnel        $at, $zero, L_801380F8
    if (ctx->r1 != 0) {
        // 0x8013809C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801380F8;
    }
    goto skip_2;
    // 0x8013809C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_801380A0:
    // 0x801380A0: jal         0x80132758
    // 0x801380A4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_3;
    // 0x801380A4: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_3:
    // 0x801380A8: b           L_801380F8
    // 0x801380AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801380F8;
    // 0x801380AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801380B0:
    // 0x801380B0: bgez        $t5, L_801380EC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x801380B4: nop
    
            goto L_801380EC;
    }
    // 0x801380B4: nop

    // 0x801380B8: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    // 0x801380BC: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x801380C0: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x801380C4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x801380C8: slti        $at, $v0, 0x98
    ctx->r1 = SIGNED(ctx->r2) < 0X98 ? 1 : 0;
    // 0x801380CC: bne         $at, $zero, L_801380DC
    if (ctx->r1 != 0) {
        // 0x801380D0: slti        $at, $v0, 0x9C
        ctx->r1 = SIGNED(ctx->r2) < 0X9C ? 1 : 0;
            goto L_801380DC;
    }
    // 0x801380D0: slti        $at, $v0, 0x9C
    ctx->r1 = SIGNED(ctx->r2) < 0X9C ? 1 : 0;
    // 0x801380D4: bnel        $at, $zero, L_801380F8
    if (ctx->r1 != 0) {
        // 0x801380D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801380F8;
    }
    goto skip_3;
    // 0x801380D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_801380DC:
    // 0x801380DC: jal         0x80132758
    // 0x801380E0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_4;
    // 0x801380E0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_4:
    // 0x801380E4: b           L_801380F8
    // 0x801380E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801380F8;
    // 0x801380E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801380EC:
    // 0x801380EC: jal         0x80134E98
    // 0x801380F0: nop

    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_5;
    // 0x801380F0: nop

    after_5:
L_801380F4:
    // 0x801380F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801380F8:
    // 0x801380F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801380FC: jr          $ra
    // 0x80138100: nop

    return;
    // 0x80138100: nop

;}
RECOMP_FUNC void alCSPSetChlFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026010: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026014: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80026018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002601C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80026020: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80026024: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80026028: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8002602C: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x80026030: addiu       $t8, $zero, 0x5B
    ctx->r24 = ADD32(0, 0X5B);
    // 0x80026034: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80026038: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002603C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80026040: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80026044: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x80026048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002604C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80026050: jal         0x80028D70
    // 0x80026054: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80026054: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x80026058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002605C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80026060: jr          $ra
    // 0x80026064: nop

    return;
    // 0x80026064: nop

;}
RECOMP_FUNC void grZebesAcidSetRandomWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108088: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010808C: lbu         $v0, 0x1407($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1407);
    // 0x80108090: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80108094: addiu       $t7, $t7, -0x15A0
    ctx->r15 = ADD32(ctx->r15, -0X15A0);
    // 0x80108098: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8010809C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801080A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801080A4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801080A8: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    // 0x801080AC: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x801080B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801080B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801080B8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801080BC: jal         0x80018994
    // 0x801080C0: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x801080C0: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    after_0:
    // 0x801080C4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801080C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801080CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801080D0: lhu         $t0, 0x0($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X0);
    // 0x801080D4: lhu         $t2, 0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2);
    // 0x801080D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801080DC: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x801080E0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801080E4: jr          $ra
    // 0x801080E8: sh          $t3, 0x1404($at)
    MEM_H(0X1404, ctx->r1) = ctx->r11;
    return;
    // 0x801080E8: sh          $t3, 0x1404($at)
    MEM_H(0X1404, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void ftYoshiSpecialNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E4EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E4F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E4F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E4F8: jal         0x800DDDDC
    // 0x8015E4FC: addiu       $a1, $a1, -0x1980
    ctx->r5 = ADD32(ctx->r5, -0X1980);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015E4FC: addiu       $a1, $a1, -0x1980
    ctx->r5 = ADD32(ctx->r5, -0X1980);
    after_0:
    // 0x8015E500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E508: jr          $ra
    // 0x8015E50C: nop

    return;
    // 0x8015E50C: nop

;}
RECOMP_FUNC void gmCameraMakeDefaultCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D7E8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010D7EC: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8010D7F0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010D7F4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8010D7F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8010D7FC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8010D800: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8010D804: addiu       $t6, $t6, -0x2B40
    ctx->r14 = ADD32(ctx->r14, -0X2B40);
    // 0x8010D808: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8010D80C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010D810: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8010D814: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8010D818: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8010D81C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8010D820: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8010D824: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8010D828: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8010D82C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8010D830: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010D834: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010D838: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010D83C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010D840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010D844: addiu       $a0, $zero, 0x3EA
    ctx->r4 = ADD32(0, 0X3EA);
    // 0x8010D848: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8010D84C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010D850: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010D854: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010D858: jal         0x8000B93C
    // 0x8010D85C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010D85C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010D860: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D864: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8010D868: sw          $v0, 0x1460($at)
    MEM_W(0X1460, ctx->r1) = ctx->r2;
    // 0x8010D86C: lw          $s1, 0x74($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X74);
    // 0x8010D870: lbu         $s0, 0x67($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0X67);
    // 0x8010D874: lbu         $a1, 0x63($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X63);
    // 0x8010D878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010D87C: jal         0x80008CF0
    // 0x8010D880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x8010D880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8010D884: beq         $s0, $zero, L_8010D898
    if (ctx->r16 == 0) {
        // 0x8010D888: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010D898;
    }
    // 0x8010D888: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010D88C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8010D890: jal         0x80008CF0
    // 0x8010D894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x8010D894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8010D898:
    // 0x8010D898: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8010D89C: addiu       $t3, $t3, -0x1490
    ctx->r11 = ADD32(ctx->r11, -0X1490);
    // 0x8010D8A0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8010D8A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010D8A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010D8AC: sw          $t5, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r13;
    // 0x8010D8B0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8010D8B4: addiu       $t6, $t6, -0x1474
    ctx->r14 = ADD32(ctx->r14, -0X1474);
    // 0x8010D8B8: addiu       $s0, $s0, 0x14B0
    ctx->r16 = ADD32(ctx->r16, 0X14B0);
    // 0x8010D8BC: sw          $t4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r12;
    // 0x8010D8C0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8010D8C4: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x8010D8C8: or          $t9, $s1, $zero
    ctx->r25 = ctx->r17 | 0;
    // 0x8010D8CC: sw          $t5, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r13;
    // 0x8010D8D0: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8010D8D4: sw          $t4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r12;
    // 0x8010D8D8: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x8010D8DC: sw          $t5, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r13;
    // 0x8010D8E0: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8010D8E4: sw          $t4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r12;
    // 0x8010D8E8: lw          $t5, 0x18($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X18);
    // 0x8010D8EC: sw          $t5, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r13;
L_8010D8F0:
    // 0x8010D8F0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010D8F4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8010D8F8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8010D8FC: sw          $t8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r24;
    // 0x8010D900: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8010D904: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x8010D908: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8010D90C: bne         $t6, $t0, L_8010D8F0
    if (ctx->r14 != ctx->r8) {
        // 0x8010D910: sw          $t8, 0x34($t9)
        MEM_W(0X34, ctx->r25) = ctx->r24;
            goto L_8010D8F0;
    }
    // 0x8010D910: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x8010D914: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010D918: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x8010D91C: sw          $t8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r24;
    // 0x8010D920: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x8010D924: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8010D928: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8010D92C: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x8010D930: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8010D934: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8010D938: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8010D93C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8010D940: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010D944: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D948: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010D94C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010D950: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010D954: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010D958: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010D95C: jal         0x80007080
    // 0x8010D960: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x8010D960: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8010D964: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x8010D968: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x8010D96C: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8010D970: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x8010D974: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x8010D978: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8010D97C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8010D980: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010D984: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010D988: lw          $t1, 0x80($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X80);
    // 0x8010D98C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8010D990: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D994: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8010D998: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010D99C: sw          $t2, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r10;
    // 0x8010D9A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D9A4: addiu       $v0, $v0, 0x1468
    ctx->r2 = ADD32(ctx->r2, 0X1468);
    // 0x8010D9A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010D9AC: addiu       $v1, $v1, 0x1464
    ctx->r3 = ADD32(ctx->r3, 0X1464);
    // 0x8010D9B0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8010D9B4: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8010D9B8: lwc1        $f16, 0xC50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC50);
    // 0x8010D9BC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8010D9C0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010D9C4: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8010D9C8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8010D9CC: jal         0x800C7840
    // 0x8010D9D0: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    lbCommonSin(rdram, ctx);
        goto after_4;
    // 0x8010D9D0: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    after_4:
    // 0x8010D9D4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8010D9D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D9DC: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8010D9E0: jal         0x800C78B8
    // 0x8010D9E4: lwc1        $f12, 0x1464($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1464);
    lbCommonCos(rdram, ctx);
        goto after_5;
    // 0x8010D9E4: lwc1        $f12, 0x1464($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1464);
    after_5:
    // 0x8010D9E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D9EC: lwc1        $f12, 0x1468($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8010D9F0: jal         0x800C7840
    // 0x8010D9F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    lbCommonSin(rdram, ctx);
        goto after_6;
    // 0x8010D9F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8010D9F8: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010D9FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010DA00: lwc1        $f12, 0x1468($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8010DA04: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8010DA08: jal         0x800C78B8
    // 0x8010DA0C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    lbCommonCos(rdram, ctx);
        goto after_7;
    // 0x8010DA0C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8010DA10: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010DA14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8010DA18: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010DA1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010DA20: swc1        $f14, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f14.u32l;
    // 0x8010DA24: swc1        $f14, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f14.u32l;
    // 0x8010DA28: swc1        $f12, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f12.u32l;
    // 0x8010DA2C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8010DA30: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8010DA34: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8010DA38: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8010DA3C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8010DA40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010DA44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8010DA48: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8010DA4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010DA50: swc1        $f18, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f18.u32l;
    // 0x8010DA54: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8010DA58: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010DA5C: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8010DA60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010DA64: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8010DA68: swc1        $f10, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f10.u32l;
    // 0x8010DA6C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8010DA70: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8010DA74: swc1        $f18, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f18.u32l;
    // 0x8010DA78: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x8010DA7C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8010DA80: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8010DA84: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8010DA88: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8010DA8C: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x8010DA90: lbu         $v0, 0x1($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X1);
    // 0x8010DA94: beq         $v0, $v1, L_8010DAAC
    if (ctx->r2 == ctx->r3) {
        // 0x8010DA98: nop
    
            goto L_8010DAAC;
    }
    // 0x8010DA98: nop

    // 0x8010DA9C: beq         $v0, $at, L_8010DAB4
    if (ctx->r2 == ctx->r1) {
        // 0x8010DAA0: nop
    
            goto L_8010DAB4;
    }
    // 0x8010DAA0: nop

    // 0x8010DAA4: b           L_8010DAC0
    // 0x8010DAA8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
        goto L_8010DAC0;
    // 0x8010DAA8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8010DAAC:
    // 0x8010DAAC: b           L_8010DAC0
    // 0x8010DAB0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
        goto L_8010DAC0;
    // 0x8010DAB0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_8010DAB4:
    // 0x8010DAB4: b           L_8010DAC0
    // 0x8010DAB8: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
        goto L_8010DAC0;
    // 0x8010DAB8: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8010DABC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8010DAC0:
    // 0x8010DAC0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010DAC4: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8010DAC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010DACC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8010DAD0: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8010DAD4: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x8010DAD8: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x8010DADC: lw          $t6, -0x144C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X144C);
    // 0x8010DAE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8010DAE4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x8010DAE8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8010DAEC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8010DAF0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8010DAF4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8010DAF8: jr          $ra
    // 0x8010DAFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010DAFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void efDisplayZPerspAAXLUProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD0AC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FD0B0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FD0B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD0BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD0C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FD0C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FD0C8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FD0CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FD0D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FD0D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD0D8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FD0DC: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800FD0E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FD0E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FD0E8: ori         $t0, $t0, 0x49D8
    ctx->r8 = ctx->r8 | 0X49D8;
    // 0x800FD0EC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FD0F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FD0F4: jal         0x800D0D34
    // 0x800FD0F8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    lbParticleDrawTextures(rdram, ctx);
        goto after_0;
    // 0x800FD0F8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x800FD0FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FD100: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FD104: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD108: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800FD10C: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800FD110: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800FD114: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800FD118: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FD11C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800FD120: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD124: ori         $t4, $t4, 0xC00
    ctx->r12 = ctx->r12 | 0XC00;
    // 0x800FD128: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800FD12C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800FD130: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800FD134: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800FD138: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800FD13C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD140: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800FD144: ori         $t7, $t7, 0x1D00
    ctx->r15 = ctx->r15 | 0X1D00;
    // 0x800FD148: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FD14C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FD150: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FD154: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FD158: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD15C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FD160: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x800FD164: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FD168: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FD16C: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x800FD170: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FD174: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FD178: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800FD17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD184: jr          $ra
    // 0x800FD188: nop

    return;
    // 0x800FD188: nop

;}
RECOMP_FUNC void ftCommonPassCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141EA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141EAC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80141EB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80141EB4: jal         0x800F3794
    // 0x80141EB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x80141EB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80141EBC: beq         $v0, $zero, L_80141ED4
    if (ctx->r2 == 0) {
        // 0x80141EC0: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80141ED4;
    }
    // 0x80141EC0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80141EC4: jal         0x80147E7C
    // 0x80141EC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonHammerFallCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80141EC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80141ECC: b           L_80141F00
    // 0x80141ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80141F00;
    // 0x80141ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141ED4:
    // 0x80141ED4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80141ED8: jal         0x80141E60
    // 0x80141EDC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    ftCommonPassCheckInputSuccess(rdram, ctx);
        goto after_2;
    // 0x80141EDC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80141EE0: beq         $v0, $zero, L_80141EF8
    if (ctx->r2 == 0) {
        // 0x80141EE4: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80141EF8;
    }
    // 0x80141EE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80141EE8: jal         0x80141E18
    // 0x80141EEC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonPassSetStatusSquat(rdram, ctx);
        goto after_3;
    // 0x80141EEC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80141EF0: b           L_80141EFC
    // 0x80141EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141EFC;
    // 0x80141EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141EF8:
    // 0x80141EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80141EFC:
    // 0x80141EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141F00:
    // 0x80141F00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80141F04: jr          $ra
    // 0x80141F08: nop

    return;
    // 0x80141F08: nop

;}
RECOMP_FUNC void mnCharactersMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133224: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133228: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013322C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133230: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133234: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80133238: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013323C: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80133240: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133244: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133248: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013324C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133250: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133254: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133258: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013325C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133260: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133264: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133268: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013326C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133270: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133274: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013327C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133280: jal         0x8000B93C
    // 0x80133284: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133284: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133288: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013328C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133290: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133294: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133298: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013329C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801332A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801332A4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801332A8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801332AC: jal         0x80007080
    // 0x801332B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801332B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801332B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801332B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801332BC: jr          $ra
    // 0x801332C0: nop

    return;
    // 0x801332C0: nop

;}
RECOMP_FUNC void itPakkunDamagedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017D438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D43C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017D440: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8017D444: jal         0x80172558
    // 0x8017D448: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017D448: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x8017D44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017D454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017D458: jr          $ra
    // 0x8017D45C: nop

    return;
    // 0x8017D45C: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateResetOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D7B8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D7BC: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x8018D7C0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8018D7C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D7C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018D7CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018D7D0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018D7D4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D7D8: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x8018D7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D7E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018D7E4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8018D7E8: beq         $t9, $zero, L_8018D820
    if (ctx->r25 == 0) {
        // 0x8018D7EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018D820;
    }
    // 0x8018D7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D7F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D7F4: jal         0x800266A0
    // 0x8018D7F8: sb          $t0, 0xC2A($at)
    MEM_B(0XC2A, ctx->r1) = ctx->r8;
    func_800266A0_272A0(rdram, ctx);
        goto after_0;
    // 0x8018D7F8: sb          $t0, 0xC2A($at)
    MEM_B(0XC2A, ctx->r1) = ctx->r8;
    after_0:
    // 0x8018D7FC: jal         0x800269C0
    // 0x8018D800: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8018D800: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_1:
    // 0x8018D804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D808: jal         0x80020B38
    // 0x8018D80C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_2;
    // 0x8018D80C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_2:
    // 0x8018D810: jal         0x80005C74
    // 0x8018D814: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x8018D814: nop

    after_3:
    // 0x8018D818: b           L_8018D820
    // 0x8018D81C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018D820;
    // 0x8018D81C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D820:
    // 0x8018D820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D828: jr          $ra
    // 0x8018D82C: nop

    return;
    // 0x8018D82C: nop

;}
RECOMP_FUNC void ftHammerSetColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F388C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3894: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800F3898: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800F389C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x800F38A0: lw          $t6, 0xA64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA64);
    // 0x800F38A4: beql        $t6, $at, L_800F38B8
    if (ctx->r14 == ctx->r1) {
        // 0x800F38A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F38B8;
    }
    goto skip_0;
    // 0x800F38A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F38AC: jal         0x800E9814
    // 0x800F38B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800F38B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800F38B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F38B8:
    // 0x800F38B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F38BC: jr          $ra
    // 0x800F38C0: nop

    return;
    // 0x800F38C0: nop

;}
RECOMP_FUNC void func_ovl8_8038388C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038388C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383894: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80383898: lh          $a1, 0x42($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X42);
    // 0x8038389C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    // 0x803838A0: jal         0x8037B7F0
    // 0x803838A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_ovl8_8037B7F0(rdram, ctx);
        goto after_0;
    // 0x803838A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x803838A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803838AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803838B0: jr          $ra
    // 0x803838B4: nop

    return;
    // 0x803838B4: nop

;}
RECOMP_FUNC void mnPlayersVSMakeGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013365C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80133660: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133664: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133668: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8013366C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80133670: addiu       $t7, $t7, -0x493C
    ctx->r15 = ADD32(ctx->r15, -0X493C);
    // 0x80133674: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133678: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013367C: addiu       $t6, $sp, 0x88
    ctx->r14 = ADD32(ctx->r29, 0X88);
    // 0x80133680: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133684: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133688: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013368C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133690: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133694: addiu       $t1, $t1, -0x492C
    ctx->r9 = ADD32(ctx->r9, -0X492C);
    // 0x80133698: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013369C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801336A0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801336A4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801336A8: addiu       $t0, $sp, 0x78
    ctx->r8 = ADD32(ctx->r29, 0X78);
    // 0x801336AC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801336B0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801336B4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801336B8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801336BC: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801336C0: addiu       $t5, $t5, -0x491C
    ctx->r13 = ADD32(ctx->r13, -0X491C);
    // 0x801336C4: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801336C8: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x801336CC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801336D0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801336D4: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x801336D8: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801336DC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801336E0: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801336E4: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x801336E8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801336EC: addiu       $t9, $t9, -0x490C
    ctx->r25 = ADD32(ctx->r25, -0X490C);
    // 0x801336F0: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x801336F4: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x801336F8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801336FC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80133700: addiu       $t8, $sp, 0x58
    ctx->r24 = ADD32(ctx->r29, 0X58);
    // 0x80133704: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80133708: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8013370C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80133710: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80133714: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80133718: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x8013371C: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80133720: lw          $t4, -0x3B60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3B60);
    // 0x80133724: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80133728: addiu       $t5, $t5, 0x4B0
    ctx->r13 = ADD32(ctx->r13, 0X4B0);
    // 0x8013372C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80133730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133734: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133738: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x8013373C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133740: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133744: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80133748: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8013374C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80133750: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80133754: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80133758: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8013375C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80133760: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80133764: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133768: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8013376C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80133770: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133774: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80133778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013377C: jal         0x800CD050
    // 0x80133780: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80133780: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80133784: sll         $t1, $s0, 4
    ctx->r9 = S32(ctx->r16 << 4);
    // 0x80133788: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x8013378C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80133790: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x80133794: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80133798: addiu       $t3, $t1, 0x16
    ctx->r11 = ADD32(ctx->r9, 0X16);
    // 0x8013379C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801337A0: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x801337A4: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x801337A8: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x801337AC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801337B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801337B4: addiu       $t0, $t0, -0x4578
    ctx->r8 = ADD32(ctx->r8, -0X4578);
    // 0x801337B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801337BC: addu        $s1, $t9, $t0
    ctx->r17 = ADD32(ctx->r25, ctx->r8);
    // 0x801337C0: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x801337C4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x801337C8: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x801337CC: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x801337D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801337D4: swc1        $f6, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f6.u32l;
    // 0x801337D8: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801337DC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801337E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801337E4: swc1        $f8, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f8.u32l;
    // 0x801337E8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801337EC: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801337F0: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801337F4: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801337F8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801337FC: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80133800: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133804: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80133808: lw          $t0, -0x4258($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4258);
    // 0x8013380C: bne         $t0, $zero, L_80133830
    if (ctx->r8 != 0) {
        // 0x80133810: sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16 << 2);
            goto L_80133830;
    }
    // 0x80133810: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80133814: addu        $a1, $sp, $v0
    ctx->r5 = ADD32(ctx->r29, ctx->r2);
    // 0x80133818: lw          $a1, 0x58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X58);
    // 0x8013381C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80133820: jal         0x801332AC
    // 0x80133824: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_1;
    // 0x80133824: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    after_1:
    // 0x80133828: b           L_80133854
    // 0x8013382C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
        goto L_80133854;
    // 0x8013382C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_80133830:
    // 0x80133830: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80133834: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133838: bne         $v0, $at, L_80133848
    if (ctx->r2 != ctx->r1) {
        // 0x8013383C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80133848;
    }
    // 0x8013383C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133840: b           L_80133848
    // 0x80133844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80133848;
    // 0x80133844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80133848:
    // 0x80133848: jal         0x801332AC
    // 0x8013384C: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_2;
    // 0x8013384C: lw          $a2, 0x84($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X84);
    after_2:
    // 0x80133850: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_80133854:
    // 0x80133854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133858: jal         0x801334A8
    // 0x8013385C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    mnPlayersVSMakePlayerKind(rdram, ctx);
        goto after_3;
    // 0x8013385C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_3:
    // 0x80133860: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80133864: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80133868: lw          $t4, -0x3B60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3B60);
    // 0x8013386C: addu        $t1, $sp, $v0
    ctx->r9 = ADD32(ctx->r29, ctx->r2);
    // 0x80133870: lw          $t1, 0x68($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X68);
    // 0x80133874: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80133878: addiu       $t5, $t5, -0x3250
    ctx->r13 = ADD32(ctx->r13, -0X3250);
    // 0x8013387C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133880: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133884: addiu       $t8, $t8, 0x2C6C
    ctx->r24 = ADD32(ctx->r24, 0X2C6C);
    // 0x80133888: addiu       $t2, $zero, 0x1D
    ctx->r10 = ADD32(0, 0X1D);
    // 0x8013388C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80133890: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133894: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133898: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8013389C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801338A0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801338A4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801338A8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801338AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801338B0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801338B4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801338B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801338BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801338C0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x801338C4: jal         0x800CD050
    // 0x801338C8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_4;
    // 0x801338C8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_4:
    // 0x801338CC: sw          $s0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r16;
    // 0x801338D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x801338D4: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801338D8: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x801338DC: addiu       $t1, $t0, -0x13
    ctx->r9 = ADD32(ctx->r8, -0X13);
    // 0x801338E0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801338E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801338E8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801338EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801338F0: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801338F4: addiu       $t9, $t9, -0x2060
    ctx->r25 = ADD32(ctx->r25, -0X2060);
    // 0x801338F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801338FC: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x80133900: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80133904: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
    // 0x80133908: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013390C: lhu         $t4, 0x24($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X24);
    // 0x80133910: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x80133914: sh          $t5, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r13;
    // 0x80133918: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013391C: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80133920: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80133924: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x80133928: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8013392C: lw          $t8, -0x3B60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3B60);
    // 0x80133930: jal         0x800CCFDC
    // 0x80133934: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80133934: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x80133938: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8013393C: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80133940: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80133944: addiu       $t1, $t0, 0x58
    ctx->r9 = ADD32(ctx->r8, 0X58);
    // 0x80133948: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8013394C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133950: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80133954: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133958: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013395C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80133960: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80133964: addiu       $t6, $zero, 0x29
    ctx->r14 = ADD32(0, 0X29);
    // 0x80133968: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8013396C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80133970: sw          $t6, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->r14;
    // 0x80133974: jal         0x80132BF4
    // 0x80133978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSUpdateShutter(rdram, ctx);
        goto after_6;
    // 0x80133978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013397C: jal         0x80133378
    // 0x80133980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakePlayerKindSelect(rdram, ctx);
        goto after_7;
    // 0x80133980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80133984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013398C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133990: jal         0x80009968
    // 0x80133994: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x80133994: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80133998: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013399C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x801339A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801339A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801339A8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x801339AC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x801339B0: jal         0x80009DF4
    // 0x801339B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x801339B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x801339B8: jal         0x80136300
    // 0x801339BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_10;
    // 0x801339BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801339C0: jal         0x80137148
    // 0x801339C4: nop

    mnPlayersVSCheckHandicap(rdram, ctx);
        goto after_11;
    // 0x801339C4: nop

    after_11:
    // 0x801339C8: bne         $v0, $zero, L_801339E0
    if (ctx->r2 != 0) {
        // 0x801339CC: nop
    
            goto L_801339E0;
    }
    // 0x801339CC: nop

    // 0x801339D0: lw          $t8, 0x84($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X84);
    // 0x801339D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801339D8: bne         $t8, $at, L_801339E8
    if (ctx->r24 != ctx->r1) {
        // 0x801339DC: nop
    
            goto L_801339E8;
    }
    // 0x801339DC: nop

L_801339E0:
    // 0x801339E0: jal         0x80137004
    // 0x801339E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_12;
    // 0x801339E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_801339E8:
    // 0x801339E8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801339EC: lw          $t9, -0x4258($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4258);
    // 0x801339F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801339F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801339F8: bnel        $t9, $at, L_80133A0C
    if (ctx->r25 != ctx->r1) {
        // 0x801339FC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80133A0C;
    }
    goto skip_0;
    // 0x801339FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80133A00: jal         0x8013271C
    // 0x80133A04: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    mnPlayersVSMakeTeamSelect(rdram, ctx);
        goto after_13;
    // 0x80133A04: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    after_13:
    // 0x80133A08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133A0C:
    // 0x80133A0C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80133A10: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80133A14: jr          $ra
    // 0x80133A18: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80133A18: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void efManagerCaptureKirbyStarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103CF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80103CFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103D00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80103D04: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80103D08: lw          $t6, 0x1074($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1074);
    // 0x80103D0C: addiu       $a0, $a0, -0x18E0
    ctx->r4 = ADD32(ctx->r4, -0X18E0);
    // 0x80103D10: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x80103D14: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80103D18: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80103D1C: lw          $t0, -0x2FC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2FC0);
    // 0x80103D20: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80103D24: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x80103D28: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80103D2C: addiu       $t1, $t1, 0x4D4
    ctx->r9 = ADD32(ctx->r9, 0X4D4);
    // 0x80103D30: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80103D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103D38: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80103D3C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80103D40: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80103D44: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80103D48: addiu       $t3, $t3, 0x5458
    ctx->r11 = ADD32(ctx->r11, 0X5458);
    // 0x80103D4C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80103D50: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80103D54: jal         0x800FDAFC
    // 0x80103D58: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103D58: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80103D5C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80103D60: bne         $v0, $zero, L_80103D70
    if (ctx->r2 != 0) {
        // 0x80103D64: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80103D70;
    }
    // 0x80103D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80103D68: b           L_80103DE8
    // 0x80103D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103DE8;
    // 0x80103D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103D70:
    // 0x80103D70: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x80103D74: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80103D78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80103D7C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80103D80: lw          $v1, 0x74($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X74);
    // 0x80103D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80103D88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80103D8C: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80103D90: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x80103D94: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80103D98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80103D9C: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x80103DA0: lw          $t5, 0x84($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X84);
    // 0x80103DA4: lw          $t6, 0x8E8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8E8);
    // 0x80103DA8: sw          $t6, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r14;
    // 0x80103DAC: lw          $t9, 0x84($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X84);
    // 0x80103DB0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80103DB4: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x80103DB8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80103DBC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80103DC0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80103DC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80103DC8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80103DCC: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80103DD0: swc1        $f0, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f0.u32l;
    // 0x80103DD4: lw          $t4, 0x10($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X10);
    // 0x80103DD8: swc1        $f0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f0.u32l;
    // 0x80103DDC: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x80103DE0: swc1        $f10, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f10.u32l;
    // 0x80103DE4: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_80103DE8:
    // 0x80103DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103DEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80103DF0: jr          $ra
    // 0x80103DF4: nop

    return;
    // 0x80103DF4: nop

;}
RECOMP_FUNC void mnVSModeFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801345C8: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801345CC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801345D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801345D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801345D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801345DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801345E0: addiu       $t8, $t8, 0x4988
    ctx->r24 = ADD32(ctx->r24, 0X4988);
    // 0x801345E4: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x801345E8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801345EC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801345F0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801345F4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801345F8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x801345FC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80134600: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80134604: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80134608: jal         0x800CDF78
    // 0x8013460C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013460C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80134610: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80134614: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x80134618: lbu         $v0, 0x5E2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5E2);
    // 0x8013461C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134620: addiu       $a0, $a0, 0x47B0
    ctx->r4 = ADD32(ctx->r4, 0X47B0);
    // 0x80134624: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80134628: beq         $t0, $zero, L_80134658
    if (ctx->r8 == 0) {
        // 0x8013462C: nop
    
            goto L_80134658;
    }
    // 0x8013462C: nop

    // 0x80134630: lbu         $t1, 0x5E3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5E3);
    // 0x80134634: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80134638: slti        $at, $t1, 0x16
    ctx->r1 = SIGNED(ctx->r9) < 0X16 ? 1 : 0;
    // 0x8013463C: bne         $at, $zero, L_80134658
    if (ctx->r1 != 0) {
        // 0x80134640: nop
    
            goto L_80134658;
    }
    // 0x80134640: nop

    // 0x80134644: lbu         $t2, 0x4D40($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4D40);
    // 0x80134648: ori         $t3, $v0, 0x1
    ctx->r11 = ctx->r2 | 0X1;
    // 0x8013464C: bne         $t2, $zero, L_80134658
    if (ctx->r10 != 0) {
        // 0x80134650: nop
    
            goto L_80134658;
    }
    // 0x80134650: nop

    // 0x80134654: sb          $t3, 0x5E2($v1)
    MEM_B(0X5E2, ctx->r3) = ctx->r11;
L_80134658:
    // 0x80134658: jal         0x800CDEEC
    // 0x8013465C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013465C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80134660: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134664: jal         0x80004980
    // 0x80134668: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134668: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013466C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134670: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134674: addiu       $a2, $a2, 0x4A48
    ctx->r6 = ADD32(ctx->r6, 0X4A48);
    // 0x80134678: addiu       $a0, $a0, 0x47B0
    ctx->r4 = ADD32(ctx->r4, 0X47B0);
    // 0x8013467C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80134680: jal         0x800CDE04
    // 0x80134684: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134684: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134688: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013468C: addiu       $a1, $a1, 0x3B8C
    ctx->r5 = ADD32(ctx->r5, 0X3B8C);
    // 0x80134690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134694: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134698: jal         0x80009968
    // 0x8013469C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013469C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801346A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801346A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801346A8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801346AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801346B0: jal         0x8000B9FC
    // 0x801346B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801346B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801346B8: jal         0x801336AC
    // 0x801346BC: nop

    mnVSModeFuncStartVars(rdram, ctx);
        goto after_6;
    // 0x801346BC: nop

    after_6:
    // 0x801346C0: jal         0x8013360C
    // 0x801346C4: nop

    mnVSModeMakeBackgroundViewport(rdram, ctx);
        goto after_7;
    // 0x801346C4: nop

    after_7:
    // 0x801346C8: jal         0x8013356C
    // 0x801346CC: nop

    mnVSModeMakeMenuNameViewport(rdram, ctx);
        goto after_8;
    // 0x801346CC: nop

    after_8:
    // 0x801346D0: jal         0x801334CC
    // 0x801346D4: nop

    mnVSModeMakeButtonViewport(rdram, ctx);
        goto after_9;
    // 0x801346D4: nop

    after_9:
    // 0x801346D8: jal         0x8013342C
    // 0x801346DC: nop

    mnVSModeMakeButtonValuegSYRdpViewport(rdram, ctx);
        goto after_10;
    // 0x801346DC: nop

    after_10:
    // 0x801346E0: jal         0x80133298
    // 0x801346E4: nop

    mnVSModeMakeBackground(rdram, ctx);
        goto after_11;
    // 0x801346E4: nop

    after_11:
    // 0x801346E8: jal         0x8013314C
    // 0x801346EC: nop

    mnVSModeMakeMenuName(rdram, ctx);
        goto after_12;
    // 0x801346EC: nop

    after_12:
    // 0x801346F0: jal         0x80132154
    // 0x801346F4: nop

    mnVSModeMakeVSStartButton(rdram, ctx);
        goto after_13;
    // 0x801346F4: nop

    after_13:
    // 0x801346F8: jal         0x80132A4C
    // 0x801346FC: nop

    mnVSModeMakeRuleButton(rdram, ctx);
        goto after_14;
    // 0x801346FC: nop

    after_14:
    // 0x80134700: jal         0x80132238
    // 0x80134704: nop

    mnVSModeMakeRuleValue(rdram, ctx);
        goto after_15;
    // 0x80134704: nop

    after_15:
    // 0x80134708: jal         0x80132D04
    // 0x8013470C: nop

    mnVSModeMakeTimeStockButton(rdram, ctx);
        goto after_16;
    // 0x8013470C: nop

    after_16:
    // 0x80134710: jal         0x80132BA0
    // 0x80134714: nop

    mnVSModeMakeTimeStockValue(rdram, ctx);
        goto after_17;
    // 0x80134714: nop

    after_17:
    // 0x80134718: jal         0x80132EBC
    // 0x8013471C: nop

    mnVSModeMakeVSOptionsButton(rdram, ctx);
        goto after_18;
    // 0x8013471C: nop

    after_18:
    // 0x80134720: jal         0x80132FD8
    // 0x80134724: nop

    mnVSModeMakeSubtitle(rdram, ctx);
        goto after_19;
    // 0x80134724: nop

    after_19:
    // 0x80134728: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8013472C: lbu         $t4, 0x4AD1($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AD1);
    // 0x80134730: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80134734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134738: bnel        $t4, $at, L_8013474C
    if (ctx->r12 != ctx->r1) {
        // 0x8013473C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013474C;
    }
    goto skip_0;
    // 0x8013473C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80134740: jal         0x80020AB4
    // 0x80134744: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    syAudioPlayBGM(rdram, ctx);
        goto after_20;
    // 0x80134744: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_20:
    // 0x80134748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013474C:
    // 0x8013474C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80134750: jr          $ra
    // 0x80134754: nop

    return;
    // 0x80134754: nop

;}
RECOMP_FUNC void ftHammerProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F391C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800F3920: jal         0x800DDDDC
    // 0x800F3924: addiu       $a1, $a1, 0x7C50
    ctx->r5 = ADD32(ctx->r5, 0X7C50);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x800F3924: addiu       $a1, $a1, 0x7C50
    ctx->r5 = ADD32(ctx->r5, 0X7C50);
    after_0:
    // 0x800F3928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F392C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3930: jr          $ra
    // 0x800F3934: nop

    return;
    // 0x800F3934: nop

;}
RECOMP_FUNC void func_ovl33_801324F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324F8: jr          $ra
    // 0x801324FC: nop

    return;
    // 0x801324FC: nop

;}
RECOMP_FUNC void ftMarioSpecialLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801564F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801564F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801564F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801564FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156500: lw          $t7, 0x188($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X188);
    // 0x80156504: beq         $t7, $zero, L_80156590
    if (ctx->r15 == 0) {
        // 0x80156508: nop
    
            goto L_80156590;
    }
    // 0x80156508: nop

    // 0x8015650C: lw          $t8, 0xB1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB1C);
    // 0x80156510: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80156514: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80156518: addiu       $v1, $t8, -0x1
    ctx->r3 = ADD32(ctx->r24, -0X1);
    // 0x8015651C: bne         $v1, $at, L_80156554
    if (ctx->r3 != ctx->r1) {
        // 0x80156520: sw          $v1, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->r3;
            goto L_80156554;
    }
    // 0x80156520: sw          $v1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r3;
    // 0x80156524: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156528: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x8015652C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80156530: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80156534: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80156538: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8015653C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80156540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80156544: jal         0x800EABDC
    // 0x80156548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftParamMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80156548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8015654C: b           L_80156590
    // 0x80156550: nop

        goto L_80156590;
    // 0x80156550: nop

L_80156554:
    // 0x80156554: bne         $v1, $zero, L_80156590
    if (ctx->r3 != 0) {
        // 0x80156558: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80156590;
    }
    // 0x80156558: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015655C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156560: lw          $t2, 0x44($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X44);
    // 0x80156564: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80156568: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8015656C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80156570: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80156574: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80156578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8015657C: jal         0x800EABDC
    // 0x80156580: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    ftParamMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80156580: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_1:
    // 0x80156584: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80156588: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8015658C: sw          $t3, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r11;
L_80156590:
    // 0x80156590: jal         0x800D94C4
    // 0x80156594: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftAnimEndSetWait(rdram, ctx);
        goto after_2;
    // 0x80156594: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80156598: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015659C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801565A0: jr          $ra
    // 0x801565A4: nop

    return;
    // 0x801565A4: nop

;}
RECOMP_FUNC void ftCommonHeavyThrowDecideSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80146934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146938: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014693C: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80146940: lb          $v0, 0x1C2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C2);
    // 0x80146944: bgez        $v0, L_80146954
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80146948: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80146954;
    }
    // 0x80146948: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014694C: b           L_80146954
    // 0x80146950: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80146954;
    // 0x80146950: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80146954:
    // 0x80146954: slti        $at, $v1, 0x38
    ctx->r1 = SIGNED(ctx->r3) < 0X38 ? 1 : 0;
    // 0x80146958: bne         $at, $zero, L_80146994
    if (ctx->r1 != 0) {
        // 0x8014695C: nop
    
            goto L_80146994;
    }
    // 0x8014695C: nop

    // 0x80146960: lbu         $t7, 0x26A($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X26A);
    // 0x80146964: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80146968: beq         $at, $zero, L_80146994
    if (ctx->r1 == 0) {
        // 0x8014696C: nop
    
            goto L_80146994;
    }
    // 0x8014696C: nop

    // 0x80146970: lw          $t8, 0x44($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X44);
    // 0x80146974: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146978: mflo        $t9
    ctx->r25 = lo;
    // 0x8014697C: bltz        $t9, L_8014698C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80146980: nop
    
            goto L_8014698C;
    }
    // 0x80146980: nop

    // 0x80146984: b           L_80146A3C
    // 0x80146988: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
        goto L_80146A3C;
    // 0x80146988: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
L_8014698C:
    // 0x8014698C: b           L_80146A3C
    // 0x80146990: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
        goto L_80146A3C;
    // 0x80146990: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
L_80146994:
    // 0x80146994: bgez        $v0, L_801469A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80146998: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801469A4;
    }
    // 0x80146998: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014699C: b           L_801469A4
    // 0x801469A0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_801469A4;
    // 0x801469A0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_801469A4:
    // 0x801469A4: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x801469A8: bne         $at, $zero, L_80146A38
    if (ctx->r1 != 0) {
        // 0x801469AC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80146A38;
    }
    // 0x801469AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801469B0: jal         0x800E8000
    // 0x801469B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x801469B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801469B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801469BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801469C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801469C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801469C8: bc1f        L_801469E8
    if (!c1cs) {
        // 0x801469CC: nop
    
            goto L_801469E8;
    }
    // 0x801469CC: nop

    // 0x801469D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801469D4: jal         0x800E8000
    // 0x801469D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x801469D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x801469DC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801469E0: b           L_801469F8
    // 0x801469E4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801469F8;
    // 0x801469E4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_801469E8:
    // 0x801469E8: jal         0x800E8000
    // 0x801469EC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_2;
    // 0x801469EC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x801469F0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801469F4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801469F8:
    // 0x801469F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801469FC: lwc1        $f6, -0x3E44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3E44);
    // 0x80146A00: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80146A04: nop

    // 0x80146A08: bc1fl       L_80146A3C
    if (!c1cs) {
        // 0x80146A0C: addiu       $a1, $zero, 0x7A
        ctx->r5 = ADD32(0, 0X7A);
            goto L_80146A3C;
    }
    goto skip_0;
    // 0x80146A0C: addiu       $a1, $zero, 0x7A
    ctx->r5 = ADD32(0, 0X7A);
    skip_0:
    // 0x80146A10: lb          $t0, 0x1C2($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1C2);
    // 0x80146A14: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
    // 0x80146A18: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80146A1C: mflo        $t2
    ctx->r10 = lo;
    // 0x80146A20: bltz        $t2, L_80146A30
    if (SIGNED(ctx->r10) < 0) {
        // 0x80146A24: nop
    
            goto L_80146A30;
    }
    // 0x80146A24: nop

    // 0x80146A28: b           L_80146A3C
    // 0x80146A2C: addiu       $a1, $zero, 0x7A
    ctx->r5 = ADD32(0, 0X7A);
        goto L_80146A3C;
    // 0x80146A2C: addiu       $a1, $zero, 0x7A
    ctx->r5 = ADD32(0, 0X7A);
L_80146A30:
    // 0x80146A30: b           L_80146A3C
    // 0x80146A34: addiu       $a1, $zero, 0x7B
    ctx->r5 = ADD32(0, 0X7B);
        goto L_80146A3C;
    // 0x80146A34: addiu       $a1, $zero, 0x7B
    ctx->r5 = ADD32(0, 0X7B);
L_80146A38:
    // 0x80146A38: addiu       $a1, $zero, 0x7A
    ctx->r5 = ADD32(0, 0X7A);
L_80146A3C:
    // 0x80146A3C: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80146A40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80146A44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80146A48: beq         $v0, $at, L_80146A60
    if (ctx->r2 == ctx->r1) {
        // 0x80146A4C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80146A60;
    }
    // 0x80146A4C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80146A50: beq         $v0, $at, L_80146A60
    if (ctx->r2 == ctx->r1) {
        // 0x80146A54: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80146A60;
    }
    // 0x80146A54: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80146A58: bne         $v0, $at, L_80146A64
    if (ctx->r2 != ctx->r1) {
        // 0x80146A5C: nop
    
            goto L_80146A64;
    }
    // 0x80146A5C: nop

L_80146A60:
    // 0x80146A60: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
L_80146A64:
    // 0x80146A64: jal         0x80146690
    // 0x80146A68: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_3;
    // 0x80146A68: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x80146A6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80146A70: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80146A74: addiu       $t3, $t3, 0x5D28
    ctx->r11 = ADD32(ctx->r11, 0X5D28);
    // 0x80146A78: sw          $t3, 0x9EC($a2)
    MEM_W(0X9EC, ctx->r6) = ctx->r11;
    // 0x80146A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80146A84: jr          $ra
    // 0x80146A88: nop

    return;
    // 0x80146A88: nop

;}
RECOMP_FUNC void itHarisenWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801751F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801751F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801751FC: jal         0x80172E74
    // 0x80175200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80175200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175204: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175208: addiu       $a1, $a1, -0x6554
    ctx->r5 = ADD32(ctx->r5, -0X6554);
    // 0x8017520C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80175210: jal         0x80172EC8
    // 0x80175214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80175214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80175218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017521C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175220: jr          $ra
    // 0x80175224: nop

    return;
    // 0x80175224: nop

;}
RECOMP_FUNC void ftCommonCaptureTrappedUpdateBreakoutVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E400: lhu         $v0, 0x1BE($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1BE);
    // 0x8014E404: lhu         $t6, 0x1B4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1B4);
    // 0x8014E408: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8014E40C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8014E410: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x8014E414: bne         $t7, $zero, L_8014E43C
    if (ctx->r15 != 0) {
        // 0x8014E418: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8014E43C;
    }
    // 0x8014E418: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8014E41C: lhu         $t8, 0x1B6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B6);
    // 0x8014E420: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x8014E424: bnel        $t9, $zero, L_8014E440
    if (ctx->r25 != 0) {
        // 0x8014E428: lw          $t2, 0x26C($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X26C);
            goto L_8014E440;
    }
    goto skip_0;
    // 0x8014E428: lw          $t2, 0x26C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X26C);
    skip_0:
    // 0x8014E42C: lhu         $t0, 0x1B8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X1B8);
    // 0x8014E430: and         $t1, $v0, $t0
    ctx->r9 = ctx->r2 & ctx->r8;
    // 0x8014E434: beql        $t1, $zero, L_8014E450
    if (ctx->r9 == 0) {
        // 0x8014E438: lb          $a2, 0x1C2($a0)
        ctx->r6 = MEM_B(ctx->r4, 0X1C2);
            goto L_8014E450;
    }
    goto skip_1;
    // 0x8014E438: lb          $a2, 0x1C2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X1C2);
    skip_1:
L_8014E43C:
    // 0x8014E43C: lw          $t2, 0x26C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X26C);
L_8014E440:
    // 0x8014E440: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014E444: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8014E448: sw          $t3, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r11;
    // 0x8014E44C: lb          $a2, 0x1C2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X1C2);
L_8014E450:
    // 0x8014E450: lb          $v0, 0x270($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X270);
    // 0x8014E454: lb          $a1, 0x271($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X271);
    // 0x8014E458: slti        $at, $a2, -0x28
    ctx->r1 = SIGNED(ctx->r6) < -0X28 ? 1 : 0;
    // 0x8014E45C: beq         $at, $zero, L_8014E46C
    if (ctx->r1 == 0) {
        // 0x8014E460: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8014E46C;
    }
    // 0x8014E460: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8014E464: sb          $t4, 0x270($a0)
    MEM_B(0X270, ctx->r4) = ctx->r12;
    // 0x8014E468: lb          $a2, 0x1C2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X1C2);
L_8014E46C:
    // 0x8014E46C: slti        $at, $a2, 0x29
    ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
    // 0x8014E470: bne         $at, $zero, L_8014E47C
    if (ctx->r1 != 0) {
        // 0x8014E474: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8014E47C;
    }
    // 0x8014E474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014E478: sb          $t5, 0x270($a0)
    MEM_B(0X270, ctx->r4) = ctx->r13;
L_8014E47C:
    // 0x8014E47C: lb          $a2, 0x1C3($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X1C3);
    // 0x8014E480: slti        $at, $a2, -0x28
    ctx->r1 = SIGNED(ctx->r6) < -0X28 ? 1 : 0;
    // 0x8014E484: beql        $at, $zero, L_8014E498
    if (ctx->r1 == 0) {
        // 0x8014E488: slti        $at, $a2, 0x29
        ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
            goto L_8014E498;
    }
    goto skip_2;
    // 0x8014E488: slti        $at, $a2, 0x29
    ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
    skip_2:
    // 0x8014E48C: sb          $t6, 0x271($a0)
    MEM_B(0X271, ctx->r4) = ctx->r14;
    // 0x8014E490: lb          $a2, 0x1C3($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X1C3);
    // 0x8014E494: slti        $at, $a2, 0x29
    ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
L_8014E498:
    // 0x8014E498: bnel        $at, $zero, L_8014E4A8
    if (ctx->r1 != 0) {
        // 0x8014E49C: lb          $t8, 0x270($a0)
        ctx->r24 = MEM_B(ctx->r4, 0X270);
            goto L_8014E4A8;
    }
    goto skip_3;
    // 0x8014E49C: lb          $t8, 0x270($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X270);
    skip_3:
    // 0x8014E4A0: sb          $t7, 0x271($a0)
    MEM_B(0X271, ctx->r4) = ctx->r15;
    // 0x8014E4A4: lb          $t8, 0x270($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X270);
L_8014E4A8:
    // 0x8014E4A8: bnel        $v0, $t8, L_8014E4C0
    if (ctx->r2 != ctx->r24) {
        // 0x8014E4AC: lw          $t0, 0x26C($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X26C);
            goto L_8014E4C0;
    }
    goto skip_4;
    // 0x8014E4AC: lw          $t0, 0x26C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X26C);
    skip_4:
    // 0x8014E4B0: lb          $t9, 0x271($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X271);
    // 0x8014E4B4: beq         $a1, $t9, L_8014E4CC
    if (ctx->r5 == ctx->r25) {
        // 0x8014E4B8: nop
    
            goto L_8014E4CC;
    }
    // 0x8014E4B8: nop

    // 0x8014E4BC: lw          $t0, 0x26C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X26C);
L_8014E4C0:
    // 0x8014E4C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8014E4C4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8014E4C8: sw          $t1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r9;
L_8014E4CC:
    // 0x8014E4CC: jr          $ra
    // 0x8014E4D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8014E4D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void grSectorArwingWeaponLaser2DMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107330: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80107334: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x80107338: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8010733C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80107340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107344: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x80107348: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8010734C: lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XC);
    // 0x80107350: lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X10);
    // 0x80107354: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80107358: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8010735C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80107360: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80107364: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80107368: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8010736C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80107370: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80107374: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x80107378: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8010737C: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80107380: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80107384: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x80107388: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8010738C: jal         0x800192D0
    // 0x80107390: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    syVectorRotate3D(rdram, ctx);
        goto after_0;
    // 0x80107390: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_0:
    // 0x80107394: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80107398: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010739C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801073A0: lwc1        $f10, 0xAE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XAE4);
    // 0x801073A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801073A8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801073AC: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801073B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801073B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801073B8: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801073BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801073C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801073C4: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x801073C8: addiu       $a1, $a1, -0x1610
    ctx->r5 = ADD32(ctx->r5, -0X1610);
    // 0x801073CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801073D0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x801073D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801073D8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x801073DC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x801073E0: jal         0x801655C8
    // 0x801073E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x801073E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801073E8: beq         $v0, $zero, L_80107508
    if (ctx->r2 == 0) {
        // 0x801073EC: lui         $at, 0xC366
        ctx->r1 = S32(0XC366 << 16);
            goto L_80107508;
    }
    // 0x801073EC: lui         $at, 0xC366
    ctx->r1 = S32(0XC366 << 16);
    // 0x801073F0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801073F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801073F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801073FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80107400: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x80107404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80107408: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8010740C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80107410: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80107414: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80107418: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8010741C: jal         0x8010719C
    // 0x80107420: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_ovl2_8010719C(rdram, ctx);
        goto after_2;
    // 0x80107420: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80107424: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80107428: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x8010742C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80107430: lw          $t9, 0x74($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X74);
    // 0x80107434: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80107438: addiu       $t0, $t0, 0x13F0
    ctx->r8 = ADD32(ctx->r8, 0X13F0);
    // 0x8010743C: sw          $t3, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r11;
    // 0x80107440: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80107444: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80107448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8010744C: sw          $t2, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r10;
    // 0x80107450: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80107454: sw          $t3, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r11;
    // 0x80107458: lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X14);
    // 0x8010745C: lw          $t7, 0xC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XC);
    // 0x80107460: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x80107464: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80107468: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x8010746C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80107470: lw          $t6, 0x24($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X24);
    // 0x80107474: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80107478: jal         0x800192D0
    // 0x8010747C: lw          $a2, 0x38($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X38);
    syVectorRotate3D(rdram, ctx);
        goto after_3;
    // 0x8010747C: lw          $a2, 0x38($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X38);
    after_3:
    // 0x80107480: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80107484: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80107488: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010748C: lwc1        $f16, 0xAE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XAE8);
    // 0x80107490: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80107494: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80107498: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010749C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801074A0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801074A4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801074A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801074AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801074B0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x801074B4: addiu       $a1, $a1, -0x1610
    ctx->r5 = ADD32(ctx->r5, -0X1610);
    // 0x801074B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801074BC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x801074C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801074C4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x801074C8: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x801074CC: jal         0x801655C8
    // 0x801074D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_4;
    // 0x801074D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801074D4: beq         $v0, $zero, L_80107508
    if (ctx->r2 == 0) {
        // 0x801074D8: lui         $at, 0xC366
        ctx->r1 = S32(0XC366 << 16);
            goto L_80107508;
    }
    // 0x801074D8: lui         $at, 0xC366
    ctx->r1 = S32(0XC366 << 16);
    // 0x801074DC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801074E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801074E4: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x801074E8: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x801074EC: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x801074F0: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x801074F4: sw          $t2, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r10;
    // 0x801074F8: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x801074FC: sw          $t1, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r9;
    // 0x80107500: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80107504: sw          $t2, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r10;
L_80107508:
    // 0x80107508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010750C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80107510: jr          $ra
    // 0x80107514: nop

    return;
    // 0x80107514: nop

;}
RECOMP_FUNC void itHitokageWeaponFlameProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184204: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80184208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018420C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80184210: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80184214: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80184218: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8018421C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80184220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80184224: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80184228: jal         0x801680EC
    // 0x8018422C: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8018422C: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    after_0:
    // 0x80184230: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80184234: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80184238: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018423C: lw          $v0, 0x74($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X74);
    // 0x80184240: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80184244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80184248: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x8018424C: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x80184250: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80184254: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80184258: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8018425C: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x80184260: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80184264: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80184268: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8018426C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80184270: jal         0x800CE8C0
    // 0x80184274: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x80184274: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80184278: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8018427C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80184280: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80184284: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80184288: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8018428C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80184290: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80184294: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80184298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018429C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801842A0: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801842A4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801842A8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x801842AC: jal         0x800CE8C0
    // 0x801842B0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x801842B0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801842B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801842B8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801842BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801842C0: jr          $ra
    // 0x801842C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801842C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void grSectorArwingPrepareLaserCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106F34: jal         0x80018994
    // 0x80106F38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80106F38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80106F3C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80106F40: bne         $at, $zero, L_80106F50
    if (ctx->r1 != 0) {
        // 0x80106F44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106F50;
    }
    // 0x80106F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106F48: b           L_80106F54
    // 0x80106F4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80106F54;
    // 0x80106F4C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80106F50:
    // 0x80106F50: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80106F54:
    // 0x80106F54: jr          $ra
    // 0x80106F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftFoxSpecialAirLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015D294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D298: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015D29C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015D2A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015D2A4: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x8015D2A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015D2AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015D2B0: jal         0x800E6F24
    // 0x8015D2B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D2B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015D2B8: jal         0x800E0830
    // 0x8015D2BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015D2BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015D2C0: jal         0x8015D1E0
    // 0x8015D2C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftFoxSpecialLwStartInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015D2C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015D2C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015D2CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8015D2D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015D2D4: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015D2D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015D2DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015D2E0: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    // 0x8015D2E4: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x8015D2E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D2EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015D2F0: jr          $ra
    // 0x8015D2F4: nop

    return;
    // 0x8015D2F4: nop

;}
RECOMP_FUNC void ftCaptainSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FA8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015FA90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015FA94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015FA98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015FA9C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015FAA0: jal         0x800DEEC8
    // 0x8015FAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015FAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015FAA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015FAAC: addiu       $t7, $zero, 0x4006
    ctx->r15 = ADD32(0, 0X4006);
    // 0x8015FAB0: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015FAB4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015FAB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015FABC: jal         0x800E6F24
    // 0x8015FAC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015FAC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015FAC4: jal         0x800D8EB8
    // 0x8015FAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015FAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015FACC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8015FAD0: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8015FAD4: addiu       $t8, $t8, -0x6374
    ctx->r24 = ADD32(ctx->r24, -0X6374);
    // 0x8015FAD8: addiu       $t9, $t9, -0x633C
    ctx->r25 = ADD32(ctx->r25, -0X633C);
    // 0x8015FADC: sw          $t8, 0xA04($s0)
    MEM_W(0XA04, ctx->r16) = ctx->r24;
    // 0x8015FAE0: sw          $t9, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r25;
    // 0x8015FAE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015FAE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015FAEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015FAF0: jr          $ra
    // 0x8015FAF4: nop

    return;
    // 0x8015FAF4: nop

;}
RECOMP_FUNC void gmCollisionCheckItemInFighterRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF4F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EF4F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF4FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EF500: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EF504: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800EF508: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800EF50C: lw          $v0, 0x84($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84);
    // 0x800EF510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EF514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF518: bne         $t7, $at, L_800EF550
    if (ctx->r15 != ctx->r1) {
        // 0x800EF51C: lw          $v1, 0x9C8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X9C8);
            goto L_800EF550;
    }
    // 0x800EF51C: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x800EF520: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800EF524: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800EF528: lw          $a1, 0x74($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X74);
    // 0x800EF52C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800EF530: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800EF534: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x800EF538: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF53C: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x800EF540: jal         0x800EF2D0
    // 0x800EF544: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_0;
    // 0x800EF544: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x800EF548: b           L_800EF5C4
    // 0x800EF54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800EF5C4;
    // 0x800EF54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF550:
    // 0x800EF550: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800EF554: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800EF558: addiu       $a2, $v1, 0x290
    ctx->r6 = ADD32(ctx->r3, 0X290);
    // 0x800EF55C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800EF560: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800EF564: lw          $a1, 0x74($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X74);
    // 0x800EF568: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800EF56C: addu        $t0, $s0, $t2
    ctx->r8 = ADD32(ctx->r16, ctx->r10);
    // 0x800EF570: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x800EF574: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800EF578: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EF57C: addiu       $a0, $t0, 0x58
    ctx->r4 = ADD32(ctx->r8, 0X58);
    // 0x800EF580: jal         0x800EF2D0
    // 0x800EF584: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_1;
    // 0x800EF584: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x800EF588: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EF58C: bne         $v0, $zero, L_800EF5B4
    if (ctx->r2 != 0) {
        // 0x800EF590: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_800EF5B4;
    }
    // 0x800EF590: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800EF594: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800EF598: addiu       $a0, $t0, 0x64
    ctx->r4 = ADD32(ctx->r8, 0X64);
    // 0x800EF59C: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    // 0x800EF5A0: lw          $a1, 0x74($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X74);
    // 0x800EF5A4: jal         0x800EF2D0
    // 0x800EF5A8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionCheckAttackInFighterRange(rdram, ctx);
        goto after_2;
    // 0x800EF5A8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x800EF5AC: beql        $v0, $zero, L_800EF5C0
    if (ctx->r2 == 0) {
        // 0x800EF5B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800EF5C0;
    }
    goto skip_0;
    // 0x800EF5B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800EF5B4:
    // 0x800EF5B4: b           L_800EF5C0
    // 0x800EF5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EF5C0;
    // 0x800EF5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF5BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF5C0:
    // 0x800EF5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EF5C4:
    // 0x800EF5C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF5C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EF5CC: jr          $ra
    // 0x800EF5D0: nop

    return;
    // 0x800EF5D0: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNEatProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016292C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162930: jal         0x800DE6E4
    // 0x80162934: addiu       $a1, $a1, 0x2C90
    ctx->r5 = ADD32(ctx->r5, 0X2C90);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80162934: addiu       $a1, $a1, 0x2C90
    ctx->r5 = ADD32(ctx->r5, 0X2C90);
    after_0:
    // 0x80162938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016293C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162940: jr          $ra
    // 0x80162944: nop

    return;
    // 0x80162944: nop

;}
RECOMP_FUNC void lbParticleSetDitherModes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2748: sb          $a0, 0x5D50($at)
    MEM_B(0X5D50, ctx->r1) = ctx->r4;
    // 0x800D274C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D2750: jr          $ra
    // 0x800D2754: sb          $a1, 0x5D54($at)
    MEM_B(0X5D54, ctx->r1) = ctx->r5;
    return;
    // 0x800D2754: sb          $a1, 0x5D54($at)
    MEM_B(0X5D54, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void mpCollisionCheckFloorLineCollisionSame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4BD8: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800F4BDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F4BE0: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F4BE4: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F4BE8: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F4BEC: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F4BF0: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F4BF4: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F4BF8: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F4BFC: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F4C00: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F4C04: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F4C08: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F4C0C: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F4C10: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F4C14: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F4C18: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F4C1C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F4C20: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F4C24: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F4C28: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800F4C2C: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800F4C30: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800F4C34: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    // 0x800F4C38: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F4C3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4C40: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F4C44: blez        $t0, L_800F51B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F4C48: lwc1        $f22, 0x7A4($at)
        ctx->f22.u32l = MEM_W(ctx->r1, 0X7A4);
            goto L_800F51B8;
    }
    // 0x800F4C48: lwc1        $f22, 0x7A4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7A4);
    // 0x800F4C4C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F4C50: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F4C54: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F4C58: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F4C5C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F4C60: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x800F4C64: lw          $s6, 0x114($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X114);
    // 0x800F4C68: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F4C6C:
    // 0x800F4C6C: addiu       $a0, $t4, 0x2
    ctx->r4 = ADD32(ctx->r12, 0X2);
    // 0x800F4C70: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800F4C74: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F4C78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F4C7C: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800F4C80: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800F4C84: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F4C88: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800F4C8C: beq         $t5, $zero, L_800F51A0
    if (ctx->r13 == 0) {
        // 0x800F4C90: lw          $v0, 0x0($t9)
        ctx->r2 = MEM_W(ctx->r25, 0X0);
            goto L_800F51A0;
    }
    // 0x800F4C90: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800F4C94: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F4C98: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800F4C9C: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800F4CA0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F4CA4: beql        $at, $zero, L_800F51A4
    if (ctx->r1 == 0) {
        // 0x800F4CA8: lw          $t8, 0xF0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XF0);
            goto L_800F51A4;
    }
    goto skip_0;
    // 0x800F4CA8: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    skip_0:
    // 0x800F4CAC: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F4CB0: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800F4CB4: lwc1        $f2, 0x4($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F4CB8: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F4CBC: bne         $t8, $zero, L_800F4CCC
    if (ctx->r24 != 0) {
        // 0x800F4CC0: lwc1        $f14, 0x4($t6)
        ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
            goto L_800F4CCC;
    }
    // 0x800F4CC0: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F4CC4: beql        $v1, $zero, L_800F4CF4
    if (ctx->r3 == 0) {
        // 0x800F4CC8: mov.s       $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
            goto L_800F4CF4;
    }
    goto skip_1;
    // 0x800F4CC8: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    skip_1:
L_800F4CCC:
    // 0x800F4CCC: lwc1        $f28, 0x1C($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F4CD0: lwc1        $f30, 0x20($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F4CD4: sub.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800F4CD8: sub.s       $f6, $f12, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f28.fl;
    // 0x800F4CDC: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800F4CE0: sub.s       $f20, $f2, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F4CE4: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x800F4CE8: b           L_800F4D08
    // 0x800F4CEC: sub.s       $f26, $f14, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f30.fl;
        goto L_800F4D08;
    // 0x800F4CEC: sub.s       $f26, $f14, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F4CF0: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
L_800F4CF4:
    // 0x800F4CF4: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    // 0x800F4CF8: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x800F4CFC: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800F4D00: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x800F4D04: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
L_800F4D08:
    // 0x800F4D08: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F4D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4D10: bc1f        L_800F4D3C
    if (!c1cs) {
        // 0x800F4D14: nop
    
            goto L_800F4D3C;
    }
    // 0x800F4D14: nop

    // 0x800F4D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4D1C: lwc1        $f8, 0x7A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A8);
    // 0x800F4D20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4D24: lwc1        $f16, 0x7AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7AC);
    // 0x800F4D28: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800F4D2C: add.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x800F4D30: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x800F4D34: b           L_800F4D58
    // 0x800F4D38: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_800F4D58;
    // 0x800F4D38: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800F4D3C:
    // 0x800F4D3C: lwc1        $f4, 0x7B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7B0);
    // 0x800F4D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F4D44: lwc1        $f8, 0x7B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B4);
    // 0x800F4D48: sub.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x800F4D4C: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x800F4D50: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x800F4D54: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F4D58:
    // 0x800F4D58: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F4D5C: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800F4D60: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800F4D64: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F4D68: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F4D6C: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x800F4D70: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F4D74: beq         $at, $zero, L_800F519C
    if (ctx->r1 == 0) {
        // 0x800F4D78: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F519C;
    }
    // 0x800F4D78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F4D7C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800F4D80: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
L_800F4D84:
    // 0x800F4D84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F4D88: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F4D8C: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F4D90: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800F4D94: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800F4D98: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800F4D9C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800F4DA0: nop

    // 0x800F4DA4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F4DA8: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800F4DAC: nop

    // 0x800F4DB0: bc1fl       L_800F4DCC
    if (!c1cs) {
        // 0x800F4DB4: sw          $v1, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r3;
            goto L_800F4DCC;
    }
    goto skip_2;
    // 0x800F4DB4: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
    skip_2:
    // 0x800F4DB8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F4DBC: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800F4DC0: b           L_800F5180
    // 0x800F4DC4: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
        goto L_800F5180;
    // 0x800F4DC4: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x800F4DC8: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
L_800F4DCC:
    // 0x800F4DCC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800F4DD0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800F4DD4: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F4DD8: lw          $s7, 0xC8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC8);
    // 0x800F4DDC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800F4DE0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F4DE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F4DE8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800F4DEC: nop

    // 0x800F4DF0: bc1f        L_800F4E08
    if (!c1cs) {
        // 0x800F4DF4: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F4E08;
    }
    // 0x800F4DF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F4DF8: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F4DFC: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x800F4E00: b           L_800F51A0
    // 0x800F4E04: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
        goto L_800F51A0;
    // 0x800F4E04: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F4E08:
    // 0x800F4E08: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F4E0C: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F4E10: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F4E14: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F4E18: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F4E1C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F4E20: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F4E24: addu        $t7, $t5, $s2
    ctx->r15 = ADD32(ctx->r13, ctx->r18);
    // 0x800F4E28: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F4E2C: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x800F4E30: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4E34: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800F4E38: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800F4E3C: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F4E40: mflo        $t8
    ctx->r24 = lo;
    // 0x800F4E44: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800F4E48: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F4E4C: beq         $at, $zero, L_800F5168
    if (ctx->r1 == 0) {
        // 0x800F4E50: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F5168;
    }
    // 0x800F4E50: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F4E54: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
L_800F4E58:
    // 0x800F4E58: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F4E5C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800F4E60: addu        $t5, $t8, $s2
    ctx->r13 = ADD32(ctx->r24, ctx->r18);
    // 0x800F4E64: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x800F4E68: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800F4E6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F4E70: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4E74: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F4E78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F4E7C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F4E80: mflo        $t6
    ctx->r14 = lo;
    // 0x800F4E84: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800F4E88: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F4E8C: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F4E90: addiu       $t6, $sp, 0xB0
    ctx->r14 = ADD32(ctx->r29, 0XB0);
    // 0x800F4E94: bne         $s0, $s4, L_800F4FE8
    if (ctx->r16 != ctx->r20) {
        // 0x800F4E98: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F4FE8;
    }
    // 0x800F4E98: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F4E9C: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x800F4EA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F4EA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F4EA8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F4EAC: bc1f        L_800F5138
    if (!c1cs) {
        // 0x800F4EB0: lw          $a3, 0xE4($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XE4);
            goto L_800F5138;
    }
    // 0x800F4EB0: lw          $a3, 0xE4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE4);
    // 0x800F4EB4: lwc1        $f18, 0xDC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800F4EB8: addiu       $t8, $sp, 0xB0
    ctx->r24 = ADD32(ctx->r29, 0XB0);
    // 0x800F4EBC: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F4EC0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800F4EC4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F4EC8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800F4ECC: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x800F4ED0: jal         0x800F58A0
    // 0x800F4ED4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckFCSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F4ED4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800F4ED8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F4EDC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F4EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F4EE4: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F4EE8: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F4EEC: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F4EF0: bne         $v0, $at, L_800F5138
    if (ctx->r2 != ctx->r1) {
        // 0x800F4EF4: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F5138;
    }
    // 0x800F4EF4: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F4EF8: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F4EFC: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F4F00: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F4F04: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x800F4F08: nop

    // 0x800F4F0C: bc1fl       L_800F4F24
    if (!c1cs) {
        // 0x800F4F10: sub.s       $f0, $f4, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
            goto L_800F4F24;
    }
    goto skip_3;
    // 0x800F4F10: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    skip_3:
    // 0x800F4F14: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800F4F18: b           L_800F4F24
    // 0x800F4F1C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F4F24;
    // 0x800F4F1C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F4F20: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
L_800F4F24:
    // 0x800F4F24: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F4F28: nop

    // 0x800F4F2C: bc1f        L_800F4F54
    if (!c1cs) {
        // 0x800F4F30: nop
    
            goto L_800F4F54;
    }
    // 0x800F4F30: nop

    // 0x800F4F34: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F4F38: addu        $v0, $t7, $s7
    ctx->r2 = ADD32(ctx->r15, ctx->r23);
    // 0x800F4F3C: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F4F40: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F4F44: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F4F48: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F4F4C: b           L_800F5158
    // 0x800F4F50: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F5158;
    // 0x800F4F50: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F4F54:
    // 0x800F4F54: beq         $s5, $zero, L_800F4F74
    if (ctx->r21 == 0) {
        // 0x800F4F58: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F4F74;
    }
    // 0x800F4F58: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F4F5C: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x800F4F60: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F4F64: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F4F68: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F4F6C: add.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x800F4F70: swc1        $f18, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f18.u32l;
L_800F4F74:
    // 0x800F4F74: beq         $t0, $zero, L_800F4F80
    if (ctx->r8 == 0) {
        // 0x800F4F78: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800F4F80;
    }
    // 0x800F4F78: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800F4F7C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800F4F80:
    // 0x800F4F80: beq         $s6, $zero, L_800F4F98
    if (ctx->r22 == 0) {
        // 0x800F4F84: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800F4F98;
    }
    // 0x800F4F84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F4F88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F4F8C: swc1        $f24, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f24.u32l;
    // 0x800F4F90: swc1        $f24, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f24.u32l;
    // 0x800F4F94: swc1        $f16, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f16.u32l;
L_800F4F98:
    // 0x800F4F98: beql        $fp, $zero, L_800F4FC8
    if (ctx->r30 == 0) {
        // 0x800F4F9C: lwc1        $f4, 0xAC($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
            goto L_800F4FC8;
    }
    goto skip_4;
    // 0x800F4F9C: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    skip_4:
    // 0x800F4FA0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F4FA4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F4FA8: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F4FAC: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F4FB0: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4FB4: mflo        $t8
    ctx->r24 = lo;
    // 0x800F4FB8: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800F4FBC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F4FC0: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F4FC4: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
L_800F4FC8:
    // 0x800F4FC8: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F4FCC: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F4FD0: bc1f        L_800F4FE0
    if (!c1cs) {
        // 0x800F4FD4: nop
    
            goto L_800F4FE0;
    }
    // 0x800F4FD4: nop

    // 0x800F4FD8: b           L_800F5138
    // 0x800F4FDC: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F5138;
    // 0x800F4FDC: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F4FE0:
    // 0x800F4FE0: b           L_800F5138
    // 0x800F4FE4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F5138;
    // 0x800F4FE4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F4FE8:
    // 0x800F4FE8: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800F4FEC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F4FF0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800F4FF4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800F4FF8: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x800F4FFC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800F5000: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800F5004: jal         0x800F47AC
    // 0x800F5008: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    mpCollisionCheckFloorSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F5008: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F500C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F5010: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F5014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F5018: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F501C: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F5020: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F5024: bne         $v0, $at, L_800F5138
    if (ctx->r2 != ctx->r1) {
        // 0x800F5028: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F5138;
    }
    // 0x800F5028: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F502C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F5030: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F5034: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F5038: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F503C: nop

    // 0x800F5040: bc1fl       L_800F5058
    if (!c1cs) {
        // 0x800F5044: sub.s       $f0, $f18, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
            goto L_800F5058;
    }
    goto skip_5;
    // 0x800F5044: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
    skip_5:
    // 0x800F5048: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F504C: b           L_800F5058
    // 0x800F5050: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F5058;
    // 0x800F5050: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5054: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
L_800F5058:
    // 0x800F5058: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F505C: nop

    // 0x800F5060: bc1f        L_800F5088
    if (!c1cs) {
        // 0x800F5064: nop
    
            goto L_800F5088;
    }
    // 0x800F5064: nop

    // 0x800F5068: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F506C: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F5070: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F5074: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F5078: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F507C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F5080: b           L_800F5158
    // 0x800F5084: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F5158;
    // 0x800F5084: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F5088:
    // 0x800F5088: beq         $s5, $zero, L_800F50A8
    if (ctx->r21 == 0) {
        // 0x800F508C: lwc1        $f16, 0xB0($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F50A8;
    }
    // 0x800F508C: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F5090: add.s       $f4, $f16, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f28.fl;
    // 0x800F5094: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    // 0x800F5098: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F509C: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F50A0: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F50A4: swc1        $f8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f8.u32l;
L_800F50A8:
    // 0x800F50A8: beq         $t0, $zero, L_800F50B4
    if (ctx->r8 == 0) {
        // 0x800F50AC: lw          $t6, 0xC8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC8);
            goto L_800F50B4;
    }
    // 0x800F50AC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800F50B0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_800F50B4:
    // 0x800F50B4: beq         $s6, $zero, L_800F50EC
    if (ctx->r22 == 0) {
        // 0x800F50B8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F50EC;
    }
    // 0x800F50B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F50BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800F50C0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F50C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F50C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800F50CC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F50D0: jal         0x800F46D0
    // 0x800F50D4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_2;
    // 0x800F50D4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F50D8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F50DC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F50E0: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F50E4: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F50E8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F50EC:
    // 0x800F50EC: beql        $fp, $zero, L_800F511C
    if (ctx->r30 == 0) {
        // 0x800F50F0: lwc1        $f10, 0xAC($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
            goto L_800F511C;
    }
    goto skip_6;
    // 0x800F50F0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    skip_6:
    // 0x800F50F4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F50F8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800F50FC: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F5100: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F5104: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F5108: mflo        $t5
    ctx->r13 = lo;
    // 0x800F510C: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800F5110: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F5114: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F5118: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
L_800F511C:
    // 0x800F511C: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F5120: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F5124: bc1fl       L_800F5138
    if (!c1cs) {
        // 0x800F5128: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F5138;
    }
    goto skip_7;
    // 0x800F5128: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_7:
    // 0x800F512C: b           L_800F5138
    // 0x800F5130: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F5138;
    // 0x800F5130: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F5134: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F5138:
    // 0x800F5138: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F513C: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F5140: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F5144: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F5148: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800F514C: addu        $v1, $t8, $t5
    ctx->r3 = ADD32(ctx->r24, ctx->r13);
    // 0x800F5150: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F5154: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F5158:
    // 0x800F5158: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F515C: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F5160: bnel        $at, $zero, L_800F4E58
    if (ctx->r1 != 0) {
        // 0x800F5164: lw          $t8, 0x0($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X0);
            goto L_800F4E58;
    }
    goto skip_8;
    // 0x800F5164: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    skip_8:
L_800F5168:
    // 0x800F5168: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800F516C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800F5170: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F5174: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x800F5178: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x800F517C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
L_800F5180:
    // 0x800F5180: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F5184: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F5188: bne         $at, $zero, L_800F4D84
    if (ctx->r1 != 0) {
        // 0x800F518C: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F4D84;
    }
    // 0x800F518C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F5190: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F5194: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F5198: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F519C:
    // 0x800F519C: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
L_800F51A0:
    // 0x800F51A0: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
L_800F51A4:
    // 0x800F51A4: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x800F51A8: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800F51AC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F51B0: bne         $at, $zero, L_800F4C6C
    if (ctx->r1 != 0) {
        // 0x800F51B4: sw          $t5, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->r13;
            goto L_800F4C6C;
    }
    // 0x800F51B4: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
L_800F51B8:
    // 0x800F51B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F51BC: lwc1        $f18, 0x7B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7B8);
    // 0x800F51C0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F51C4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F51C8: c.eq.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl == ctx->f18.fl;
    // 0x800F51CC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F51D0: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F51D4: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F51D8: bc1f        L_800F51E8
    if (!c1cs) {
        // 0x800F51DC: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F51E8;
    }
    // 0x800F51DC: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F51E0: b           L_800F51EC
    // 0x800F51E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F51EC;
    // 0x800F51E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F51E8:
    // 0x800F51E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F51EC:
    // 0x800F51EC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F51F0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F51F4: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F51F8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F51FC: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F5200: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F5204: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F5208: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F520C: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F5210: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F5214: jr          $ra
    // 0x800F5218: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800F5218: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void ftPikachuSpecialLwEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801526CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801526D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801526D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801526D8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801526DC: jal         0x800DEEC8
    // 0x801526E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801526E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801526E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801526E8: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x801526EC: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x801526F0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801526F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801526F8: jal         0x800E6F24
    // 0x801526FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801526FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80152700: jal         0x800D8EB8
    // 0x80152704: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80152704: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80152708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015270C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152710: jr          $ra
    // 0x80152714: nop

    return;
    // 0x80152714: nop

;}
RECOMP_FUNC void mnTitleFireProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132940: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132944: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80132948: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8013294C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80132950: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80132954: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80132958: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013295C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132960: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80132964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132968: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8013296C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80132970: lui         $s5, 0xFCFF
    ctx->r21 = S32(0XFCFF << 16);
    // 0x80132974: lui         $s6, 0xFF2C
    ctx->r22 = S32(0XFF2C << 16);
    // 0x80132978: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8013297C: ori         $s6, $s6, 0xFE7F
    ctx->r22 = ctx->r22 | 0XFE7F;
    // 0x80132980: ori         $s5, $s5, 0x97FF
    ctx->r21 = ctx->r21 | 0X97FF;
    // 0x80132984: addiu       $s4, $s4, 0x4464
    ctx->r20 = ADD32(ctx->r20, 0X4464);
    // 0x80132988: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8013298C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80132990: lui         $s3, 0xFA00
    ctx->r19 = S32(0XFA00 << 16);
    // 0x80132994: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_80132998:
    // 0x80132998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013299C: jal         0x800CC118
    // 0x801329A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    lbCommonPrepSObjAttr(rdram, ctx);
        goto after_0;
    // 0x801329A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x801329A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801329A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801329B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801329B4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801329B8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801329BC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x801329C0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801329C4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801329C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801329CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801329D0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801329D4: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x801329D8: jal         0x800CC818
    // 0x801329DC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    lbCommonPrepSObjDraw(rdram, ctx);
        goto after_1;
    // 0x801329DC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    after_1:
    // 0x801329E0: jal         0x800CCEAC
    // 0x801329E4: nop

    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_2;
    // 0x801329E4: nop

    after_2:
    // 0x801329E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801329EC: bne         $s2, $s7, L_80132998
    if (ctx->r18 != ctx->r23) {
        // 0x801329F0: lw          $s1, 0x8($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X8);
            goto L_80132998;
    }
    // 0x801329F0: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x801329F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801329F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801329FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80132A00: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A04: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80132A08: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80132A0C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80132A10: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80132A14: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80132A18: jr          $ra
    // 0x80132A1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80132A1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void grYamabukiGateUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AF48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010AF4C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010AF50: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x8010AF54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AF58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AF5C: bne         $v0, $zero, L_8010AF88
    if (ctx->r2 != 0) {
        // 0x8010AF60: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8010AF88;
    }
    // 0x8010AF60: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8010AF64: jal         0x8010AD18
    // 0x8010AF68: nop

    grYamabukiGateCheckPlayersNear(rdram, ctx);
        goto after_0;
    // 0x8010AF68: nop

    after_0:
    // 0x8010AF6C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010AF70: beq         $v0, $zero, L_8010AFAC
    if (ctx->r2 == 0) {
        // 0x8010AF74: addiu       $v1, $v1, 0x13F0
        ctx->r3 = ADD32(ctx->r3, 0X13F0);
            goto L_8010AFAC;
    }
    // 0x8010AF74: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010AF78: jal         0x8010AD70
    // 0x8010AF7C: nop

    grYamabukiGateMakeMonster(rdram, ctx);
        goto after_1;
    // 0x8010AF7C: nop

    after_1:
    // 0x8010AF80: b           L_8010AFE8
    // 0x8010AF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010AFE8;
    // 0x8010AF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010AF88:
    // 0x8010AF88: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8010AF8C: bne         $t7, $zero, L_8010AFAC
    if (ctx->r15 != 0) {
        // 0x8010AF90: sh          $t6, 0x20($v1)
        MEM_H(0X20, ctx->r3) = ctx->r14;
            goto L_8010AFAC;
    }
    // 0x8010AF90: sh          $t6, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r14;
    // 0x8010AF94: jal         0x8010AF20
    // 0x8010AF98: nop

    grYamabukiGateAddAnimOpenEntry(rdram, ctx);
        goto after_2;
    // 0x8010AF98: nop

    after_2:
    // 0x8010AF9C: jal         0x800269C0
    // 0x8010AFA0: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8010AFA0: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_3:
    // 0x8010AFA4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010AFA8: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
L_8010AFAC:
    // 0x8010AFAC: lhu         $t8, 0x1E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1E);
    // 0x8010AFB0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8010AFB4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8010AFB8: bne         $t0, $zero, L_8010AFE4
    if (ctx->r8 != 0) {
        // 0x8010AFBC: sh          $t9, 0x1E($v1)
        MEM_H(0X1E, ctx->r3) = ctx->r25;
            goto L_8010AFE4;
    }
    // 0x8010AFBC: sh          $t9, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r25;
    // 0x8010AFC0: lhu         $t1, 0x20($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X20);
    // 0x8010AFC4: beq         $t1, $zero, L_8010AFDC
    if (ctx->r9 == 0) {
        // 0x8010AFC8: nop
    
            goto L_8010AFDC;
    }
    // 0x8010AFC8: nop

    // 0x8010AFCC: jal         0x8010AED8
    // 0x8010AFD0: nop

    grYamabukiGateAddAnimOpen(rdram, ctx);
        goto after_4;
    // 0x8010AFD0: nop

    after_4:
    // 0x8010AFD4: jal         0x800269C0
    // 0x8010AFD8: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8010AFD8: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_5:
L_8010AFDC:
    // 0x8010AFDC: jal         0x8010AD70
    // 0x8010AFE0: nop

    grYamabukiGateMakeMonster(rdram, ctx);
        goto after_6;
    // 0x8010AFE0: nop

    after_6:
L_8010AFE4:
    // 0x8010AFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010AFE8:
    // 0x8010AFE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AFEC: jr          $ra
    // 0x8010AFF0: nop

    return;
    // 0x8010AFF0: nop

;}
RECOMP_FUNC void mnPlayersVSGetNextTimeValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AAF8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013AAFC: addiu       $t7, $t7, -0x46C4
    ctx->r15 = ADD32(ctx->r15, -0X46C4);
    // 0x8013AB00: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013AB04: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013AB08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013AB0C: addiu       $t6, $sp, 0xC
    ctx->r14 = ADD32(ctx->r29, 0XC);
    // 0x8013AB10: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013AB14: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013AB18: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013AB1C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013AB20: addiu       $v1, $sp, 0xC
    ctx->r3 = ADD32(ctx->r29, 0XC);
    // 0x8013AB24: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013AB28: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8013AB2C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8013AB30: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8013AB34: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x8013AB38: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8013AB3C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8013AB40: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8013AB44: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8013AB48: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x8013AB4C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8013AB50: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8013AB54: bne         $a0, $t0, L_8013AB64
    if (ctx->r4 != ctx->r8) {
        // 0x8013AB58: nop
    
            goto L_8013AB64;
    }
    // 0x8013AB58: nop

    // 0x8013AB5C: b           L_8013ABD4
    // 0x8013AB60: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
        goto L_8013ABD4;
    // 0x8013AB60: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_8013AB64:
    // 0x8013AB64: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_8013AB68:
    // 0x8013AB68: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8013AB6C: beql        $at, $zero, L_8013AB80
    if (ctx->r1 == 0) {
        // 0x8013AB70: lw          $a1, 0x4($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X4);
            goto L_8013AB80;
    }
    goto skip_0;
    // 0x8013AB70: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8013AB74: b           L_8013ABD4
    // 0x8013AB78: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8013ABD4;
    // 0x8013AB78: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8013AB7C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
L_8013AB80:
    // 0x8013AB80: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8013AB84: beql        $at, $zero, L_8013AB98
    if (ctx->r1 == 0) {
        // 0x8013AB88: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_8013AB98;
    }
    goto skip_1;
    // 0x8013AB88: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x8013AB8C: b           L_8013ABD4
    // 0x8013AB90: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8013ABD4;
    // 0x8013AB90: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8013AB94: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_8013AB98:
    // 0x8013AB98: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8013AB9C: beql        $at, $zero, L_8013ABB0
    if (ctx->r1 == 0) {
        // 0x8013ABA0: lw          $a1, 0xC($v1)
        ctx->r5 = MEM_W(ctx->r3, 0XC);
            goto L_8013ABB0;
    }
    goto skip_2;
    // 0x8013ABA0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x8013ABA4: b           L_8013ABD4
    // 0x8013ABA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8013ABD4;
    // 0x8013ABA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8013ABAC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
L_8013ABB0:
    // 0x8013ABB0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8013ABB4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8013ABB8: beq         $at, $zero, L_8013ABC8
    if (ctx->r1 == 0) {
        // 0x8013ABBC: nop
    
            goto L_8013ABC8;
    }
    // 0x8013ABBC: nop

    // 0x8013ABC0: b           L_8013ABD4
    // 0x8013ABC4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8013ABD4;
    // 0x8013ABC4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8013ABC8:
    // 0x8013ABC8: bnel        $v1, $v0, L_8013AB68
    if (ctx->r3 != ctx->r2) {
        // 0x8013ABCC: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_8013AB68;
    }
    goto skip_3;
    // 0x8013ABCC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x8013ABD0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8013ABD4:
    // 0x8013ABD4: jr          $ra
    // 0x8013ABD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013ABD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbySpecialAirNWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016268C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80162694: jal         0x801624C8
    // 0x80162698: addiu       $a1, $a1, 0x3470
    ctx->r5 = ADD32(ctx->r5, 0X3470);
    ftKirbySpecialNThrowCheckGotoThrow(rdram, ctx);
        goto after_0;
    // 0x80162698: addiu       $a1, $a1, 0x3470
    ctx->r5 = ADD32(ctx->r5, 0X3470);
    after_0:
    // 0x8016269C: bne         $v0, $zero, L_801626B0
    if (ctx->r2 != 0) {
        // 0x801626A0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_801626B0;
    }
    // 0x801626A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801626A4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801626A8: jal         0x80162534
    // 0x801626AC: addiu       $a1, $a1, 0x3560
    ctx->r5 = ADD32(ctx->r5, 0X3560);
    ftKirbySpecialNCopyCheckGotoCopy(rdram, ctx);
        goto after_1;
    // 0x801626AC: addiu       $a1, $a1, 0x3560
    ctx->r5 = ADD32(ctx->r5, 0X3560);
    after_1:
L_801626B0:
    // 0x801626B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801626B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801626B8: jr          $ra
    // 0x801626BC: nop

    return;
    // 0x801626BC: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingInitSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137BB0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137BB4: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x80137BB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137BBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137BC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80137BC4: bne         $a0, $t6, L_80137BF8
    if (ctx->r4 != ctx->r14) {
        // 0x80137BC8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80137BF8;
    }
    // 0x80137BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80137BCC: jal         0x80136268
    // 0x80137BD0: nop

    mnPlayers1PTrainingMakeCursor(rdram, ctx);
        goto after_0;
    // 0x80137BD0: nop

    after_0:
    // 0x80137BD4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80137BD8: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80137BDC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80137BE0: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80137BE4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137BE8: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80137BEC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80137BF0: b           L_80137C1C
    // 0x80137BF4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
        goto L_80137C1C;
    // 0x80137BF4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80137BF8:
    // 0x80137BF8: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80137BFC: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80137C00: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80137C04: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80137C08: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137C0C: addiu       $t0, $t0, -0x7AA8
    ctx->r8 = ADD32(ctx->r8, -0X7AA8);
    // 0x80137C10: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80137C14: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80137C18: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80137C1C:
    // 0x80137C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137C20: jal         0x801364C0
    // 0x80137C24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    mnPlayers1PTrainingMakePuck(rdram, ctx);
        goto after_1;
    // 0x80137C24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80137C28: jal         0x80132E24
    // 0x80137C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingMakeGate(rdram, ctx);
        goto after_2;
    // 0x80137C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80137C30: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80137C34: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    // 0x80137C38: beql        $t1, $zero, L_80137C64
    if (ctx->r9 == 0) {
        // 0x80137C3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80137C64;
    }
    goto skip_0;
    // 0x80137C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80137C40: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x80137C44: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80137C48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80137C4C: beql        $a2, $at, L_80137C64
    if (ctx->r6 == ctx->r1) {
        // 0x80137C50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80137C64;
    }
    goto skip_1;
    // 0x80137C50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80137C54: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80137C58: jal         0x801337BC
    // 0x80137C5C: lw          $a3, 0x4C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4C);
    mnPlayers1PTrainingMakeFighter(rdram, ctx);
        goto after_3;
    // 0x80137C5C: lw          $a3, 0x4C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4C);
    after_3:
    // 0x80137C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80137C64:
    // 0x80137C64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137C68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80137C6C: jr          $ra
    // 0x80137C70: nop

    return;
    // 0x80137C70: nop

;}
RECOMP_FUNC void ftBossWaitDecideStatusComputer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158C34: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80158C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80158C3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80158C40: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80158C44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80158C48: lw          $v1, 0xADC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XADC);
    // 0x80158C4C: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80158C50: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80158C54: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x80158C58: lw          $v1, 0xADC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XADC);
    // 0x80158C5C: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80158C60: bnel        $t8, $zero, L_80158F64
    if (ctx->r24 != 0) {
        // 0x80158C64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80158F64;
    }
    goto skip_0;
    // 0x80158C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80158C68: lbu         $t9, 0x16($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X16);
    // 0x80158C6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80158C70: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80158C74: bne         $t9, $at, L_80158C84
    if (ctx->r25 != ctx->r1) {
        // 0x80158C78: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80158C84;
    }
    // 0x80158C78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80158C7C: b           L_80158CD0
    // 0x80158C80: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
        goto L_80158CD0;
    // 0x80158C80: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
L_80158C84:
    // 0x80158C84: jal         0x80018994
    // 0x80158C88: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80158C88: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80158C8C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80158C90: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80158C94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80158C98: lw          $v1, 0xADC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XADC);
    // 0x80158C9C: lb          $t0, 0x14($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X14);
    // 0x80158CA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80158CA4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80158CA8: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80158CAC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80158CB0: lbu         $a2, -0x7214($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7214);
    // 0x80158CB4: bnel        $a2, $at, L_80158CC8
    if (ctx->r6 != ctx->r1) {
        // 0x80158CB8: lbu         $t3, 0x16($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X16);
            goto L_80158CC8;
    }
    goto skip_1;
    // 0x80158CB8: lbu         $t3, 0x16($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X16);
    skip_1:
    // 0x80158CBC: b           L_80158CD0
    // 0x80158CC0: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
        goto L_80158CD0;
    // 0x80158CC0: sb          $zero, 0x16($v1)
    MEM_B(0X16, ctx->r3) = 0;
    // 0x80158CC4: lbu         $t3, 0x16($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X16);
L_80158CC8:
    // 0x80158CC8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80158CCC: sb          $t4, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r12;
L_80158CD0:
    // 0x80158CD0: lw          $t5, 0xADC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XADC);
    // 0x80158CD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80158CD8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80158CDC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80158CE0: addiu       $t9, $t9, -0x721C
    ctx->r25 = ADD32(ctx->r25, -0X721C);
    // 0x80158CE4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80158CE8: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x80158CEC: lw          $v0, 0xEC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XEC);
    // 0x80158CF0: beq         $v0, $at, L_80158D00
    if (ctx->r2 == ctx->r1) {
        // 0x80158CF4: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80158D00;
    }
    // 0x80158CF4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80158CF8: bne         $v0, $at, L_80158D08
    if (ctx->r2 != ctx->r1) {
        // 0x80158CFC: sll         $t0, $a2, 1
        ctx->r8 = S32(ctx->r6 << 1);
            goto L_80158D08;
    }
    // 0x80158CFC: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
L_80158D00:
    // 0x80158D00: b           L_80158D14
    // 0x80158D04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
        goto L_80158D14;
    // 0x80158D04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_80158D08:
    // 0x80158D08: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x80158D0C: addiu       $t1, $t1, -0x7224
    ctx->r9 = ADD32(ctx->r9, -0X7224);
    // 0x80158D10: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
L_80158D14:
    // 0x80158D14: lbu         $a0, 0x1($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1);
    // 0x80158D18: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80158D1C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80158D20: jal         0x80018994
    // 0x80158D24: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80158D24: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80158D28: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80158D2C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80158D30: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80158D34: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x80158D38: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80158D3C: lw          $t4, 0xADC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XADC);
    // 0x80158D40: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80158D44: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80158D48: lbu         $v1, -0x7234($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7234);
    // 0x80158D4C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80158D50: sb          $a2, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r6;
    // 0x80158D54: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80158D58: lbu         $a0, -0x7240($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7240);
    // 0x80158D5C: lw          $t5, 0xADC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XADC);
    // 0x80158D60: addiu       $t6, $a0, -0xDF
    ctx->r14 = ADD32(ctx->r4, -0XDF);
    // 0x80158D64: sltiu       $at, $t6, 0x1A
    ctx->r1 = ctx->r14 < 0X1A ? 1 : 0;
    // 0x80158D68: beq         $at, $zero, L_80158F58
    if (ctx->r1 == 0) {
        // 0x80158D6C: sb          $v1, 0x15($t5)
        MEM_B(0X15, ctx->r13) = ctx->r3;
            goto L_80158F58;
    }
    // 0x80158D6C: sb          $v1, 0x15($t5)
    MEM_B(0X15, ctx->r13) = ctx->r3;
    // 0x80158D70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80158D74: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158D78: addu        $at, $at, $t6
    gpr jr_addend_80158D80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80158D7C: lw          $t6, -0x38B4($at)
    ctx->r14 = ADD32(ctx->r1, -0X38B4);
    // 0x80158D80: jr          $t6
    // 0x80158D84: nop

    switch (jr_addend_80158D80 >> 2) {
        case 0: goto L_80158D88; break;
        case 1: goto L_80158F0C; break;
        case 2: goto L_80158DB0; break;
        case 3: goto L_80158F58; break;
        case 4: goto L_80158F58; break;
        case 5: goto L_80158DEC; break;
        case 6: goto L_80158F58; break;
        case 7: goto L_80158F58; break;
        case 8: goto L_80158F58; break;
        case 9: goto L_80158DC0; break;
        case 10: goto L_80158F58; break;
        case 11: goto L_80158F58; break;
        case 12: goto L_80158F58; break;
        case 13: goto L_80158F34; break;
        case 14: goto L_80158F58; break;
        case 15: goto L_80158F58; break;
        case 16: goto L_80158EDC; break;
        case 17: goto L_80158EA8; break;
        case 18: goto L_80158E14; break;
        case 19: goto L_80158F58; break;
        case 20: goto L_80158F58; break;
        case 21: goto L_80158E48; break;
        case 22: goto L_80158F58; break;
        case 23: goto L_80158F58; break;
        case 24: goto L_80158F58; break;
        case 25: goto L_80158E78; break;
        default: switch_error(__func__, 0x80158D80, 0x8018C74C);
    }
    // 0x80158D84: nop

L_80158D88:
    // 0x80158D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158D8C: jal         0x801580E0
    // 0x80158D90: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_2;
    // 0x80158D90: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80158D94: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158D98: addiu       $a1, $a1, -0x6C5C
    ctx->r5 = ADD32(ctx->r5, -0X6C5C);
    // 0x80158D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158DA0: jal         0x801592B4
    // 0x80158DA4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_3;
    // 0x80158DA4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80158DA8: b           L_80158F58
    // 0x80158DAC: nop

        goto L_80158F58;
    // 0x80158DAC: nop

L_80158DB0:
    // 0x80158DB0: jal         0x80159524
    // 0x80158DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossOkuhikouki1SetStatus(rdram, ctx);
        goto after_4;
    // 0x80158DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80158DB8: b           L_80158F58
    // 0x80158DBC: nop

        goto L_80158F58;
    // 0x80158DBC: nop

L_80158DC0:
    // 0x80158DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158DC4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158DC8: jal         0x8015817C
    // 0x80158DCC: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    ftBossCommonSetPosOffsetY(rdram, ctx);
        goto after_5;
    // 0x80158DCC: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_5:
    // 0x80158DD0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158DD4: addiu       $a1, $a1, -0x6464
    ctx->r5 = ADD32(ctx->r5, -0X6464);
    // 0x80158DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158DDC: jal         0x801592B4
    // 0x80158DE0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_6;
    // 0x80158DE0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80158DE4: b           L_80158F58
    // 0x80158DE8: nop

        goto L_80158F58;
    // 0x80158DE8: nop

L_80158DEC:
    // 0x80158DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158DF0: jal         0x801580E0
    // 0x80158DF4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_7;
    // 0x80158DF4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x80158DF8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158DFC: addiu       $a1, $a1, -0x67AC
    ctx->r5 = ADD32(ctx->r5, -0X67AC);
    // 0x80158E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E04: jal         0x801592B4
    // 0x80158E08: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_8;
    // 0x80158E08: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80158E0C: b           L_80158F58
    // 0x80158E10: nop

        goto L_80158F58;
    // 0x80158E10: nop

L_80158E14:
    // 0x80158E14: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80158E18: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80158E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E20: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158E24: jal         0x80158310
    // 0x80158E28: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_9;
    // 0x80158E28: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x80158E2C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158E30: addiu       $a1, $a1, -0x5C8C
    ctx->r5 = ADD32(ctx->r5, -0X5C8C);
    // 0x80158E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E38: jal         0x801592B4
    // 0x80158E3C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_10;
    // 0x80158E3C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_10:
    // 0x80158E40: b           L_80158F58
    // 0x80158E44: nop

        goto L_80158F58;
    // 0x80158E44: nop

L_80158E48:
    // 0x80158E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E4C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158E50: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80158E54: jal         0x80158310
    // 0x80158E58: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_11;
    // 0x80158E58: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x80158E5C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158E60: addiu       $a1, $a1, -0x583C
    ctx->r5 = ADD32(ctx->r5, -0X583C);
    // 0x80158E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E68: jal         0x801592B4
    // 0x80158E6C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_12;
    // 0x80158E6C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x80158E70: b           L_80158F58
    // 0x80158E74: nop

        goto L_80158F58;
    // 0x80158E74: nop

L_80158E78:
    // 0x80158E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E7C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158E80: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80158E84: jal         0x80158310
    // 0x80158E88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_13;
    // 0x80158E88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_13:
    // 0x80158E8C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158E90: addiu       $a1, $a1, -0x532C
    ctx->r5 = ADD32(ctx->r5, -0X532C);
    // 0x80158E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158E98: jal         0x801592B4
    // 0x80158E9C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_14;
    // 0x80158E9C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_14:
    // 0x80158EA0: b           L_80158F58
    // 0x80158EA4: nop

        goto L_80158F58;
    // 0x80158EA4: nop

L_80158EA8:
    // 0x80158EA8: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80158EAC: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80158EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158EB4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158EB8: jal         0x80158310
    // 0x80158EBC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_15;
    // 0x80158EBC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_15:
    // 0x80158EC0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158EC4: addiu       $a1, $a1, -0x5CEC
    ctx->r5 = ADD32(ctx->r5, -0X5CEC);
    // 0x80158EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158ECC: jal         0x801592B4
    // 0x80158ED0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_16;
    // 0x80158ED0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_16:
    // 0x80158ED4: b           L_80158F58
    // 0x80158ED8: nop

        goto L_80158F58;
    // 0x80158ED8: nop

L_80158EDC:
    // 0x80158EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158EE0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158EE4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80158EE8: jal         0x801581BC
    // 0x80158EEC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    ftBossCommonSetPosAddVelPlayer(rdram, ctx);
        goto after_17;
    // 0x80158EEC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_17:
    // 0x80158EF0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158EF4: addiu       $a1, $a1, -0x5D98
    ctx->r5 = ADD32(ctx->r5, -0X5D98);
    // 0x80158EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158EFC: jal         0x801592B4
    // 0x80158F00: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_18;
    // 0x80158F00: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_18:
    // 0x80158F04: b           L_80158F58
    // 0x80158F08: nop

        goto L_80158F58;
    // 0x80158F08: nop

L_80158F0C:
    // 0x80158F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158F10: jal         0x801580E0
    // 0x80158F14: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_19;
    // 0x80158F14: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_19:
    // 0x80158F18: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158F1C: addiu       $a1, $a1, -0x6B44
    ctx->r5 = ADD32(ctx->r5, -0X6B44);
    // 0x80158F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158F24: jal         0x801592B4
    // 0x80158F28: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_20;
    // 0x80158F28: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_20:
    // 0x80158F2C: b           L_80158F58
    // 0x80158F30: nop

        goto L_80158F58;
    // 0x80158F30: nop

L_80158F34:
    // 0x80158F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158F38: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80158F3C: jal         0x8015817C
    // 0x80158F40: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    ftBossCommonSetPosOffsetY(rdram, ctx);
        goto after_21;
    // 0x80158F40: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_21:
    // 0x80158F44: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158F48: addiu       $a1, $a1, -0x613C
    ctx->r5 = ADD32(ctx->r5, -0X613C);
    // 0x80158F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158F50: jal         0x801592B4
    // 0x80158F54: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_22;
    // 0x80158F54: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_22:
L_80158F58:
    // 0x80158F58: jal         0x80158428
    // 0x80158F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetNextAttackWait(rdram, ctx);
        goto after_23;
    // 0x80158F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80158F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158F64:
    // 0x80158F64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80158F68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80158F6C: jr          $ra
    // 0x80158F70: nop

    return;
    // 0x80158F70: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopyFoxSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156E18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156E20: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80156E24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80156E28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80156E2C: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80156E30: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156E34: jal         0x800E6F24
    // 0x80156E38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156E38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80156E3C: jal         0x800E0830
    // 0x80156E40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80156E40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80156E44: jal         0x80156DC8
    // 0x80156E48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyFoxSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156E48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156E54: jr          $ra
    // 0x80156E58: nop

    return;
    // 0x80156E58: nop

;}
RECOMP_FUNC void syMatrixModLookAtReflectF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ABA4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001ABA8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8001ABAC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001ABB0: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001ABB4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001ABB8: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001ABBC: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001ABC0: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001ABC4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001ABC8: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001ABCC: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001ABD0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001ABD4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001ABD8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001ABDC: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8001ABE0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001ABE4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8001ABE8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001ABEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001ABF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8001ABF4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001ABF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001ABFC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001AC00: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8001AC04: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8001AC08: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8001AC0C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001AC10: jal         0x80033510
    // 0x8001AC14: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001AC14: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8001AC18: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001AC1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001AC20: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AC24: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001AC28: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001AC2C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001AC30: lwc1        $f20, 0x90($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001AC34: lwc1        $f22, 0x94($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001AC38: lwc1        $f24, 0x8C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001AC3C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001AC40: nop

    // 0x8001AC44: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001AC48: nop

    // 0x8001AC4C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001AC50: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8001AC54: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8001AC58: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8001AC5C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001AC60: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8001AC64: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001AC68: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x8001AC6C: nop

    // 0x8001AC70: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8001AC74: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x8001AC78: mul.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8001AC7C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001AC80: mul.s       $f10, $f20, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8001AC84: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8001AC88: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8001AC8C: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8001AC90: nop

    // 0x8001AC94: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001AC98: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8001AC9C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001ACA0: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001ACA4: jal         0x80033510
    // 0x8001ACA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001ACA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8001ACAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001ACB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001ACB4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001ACB8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001ACBC: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001ACC0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8001ACC4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8001ACC8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8001ACCC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001ACD0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001ACD4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001ACD8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8001ACDC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001ACE0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8001ACE4: jal         0x80019438
    // 0x8001ACE8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    syVectorRotateAbout3D(rdram, ctx);
        goto after_2;
    // 0x8001ACE8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8001ACEC: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001ACF0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001ACF4: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001ACF8: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001ACFC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001AD00: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8001AD04: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AD08: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8001AD0C: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001AD10: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001AD14: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001AD18: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8001AD1C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001AD20: nop

    // 0x8001AD24: mul.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8001AD28: sub.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001AD2C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8001AD30: nop

    // 0x8001AD34: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8001AD38: sub.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001AD3C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001AD40: nop

    // 0x8001AD44: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8001AD48: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001AD4C: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001AD50: jal         0x80033510
    // 0x8001AD54: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001AD54: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_3:
    // 0x8001AD58: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001AD5C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001AD60: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8001AD64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001AD68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001AD6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001AD70: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001AD74: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8001AD78: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001AD7C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8001AD80: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8001AD84: nop

    // 0x8001AD88: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001AD8C: nop

    // 0x8001AD90: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001AD94: nop

    // 0x8001AD98: mul.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001AD9C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8001ADA0: nop

    // 0x8001ADA4: bc1f        L_8001ADB4
    if (!c1cs) {
        // 0x8001ADA8: nop
    
            goto L_8001ADB4;
    }
    // 0x8001ADA8: nop

    // 0x8001ADAC: b           L_8001ADB8
    // 0x8001ADB0: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8001ADB8;
    // 0x8001ADB0: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_8001ADB4:
    // 0x8001ADB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001ADB8:
    // 0x8001ADB8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001ADBC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8001ADC0: nop

    // 0x8001ADC4: sb          $t6, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r14;
    // 0x8001ADC8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001ADCC: mul.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001ADD0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001ADD4: nop

    // 0x8001ADD8: bc1fl       L_8001ADEC
    if (!c1cs) {
        // 0x8001ADDC: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001ADEC;
    }
    goto skip_0;
    // 0x8001ADDC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8001ADE0: b           L_8001ADEC
    // 0x8001ADE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001ADEC;
    // 0x8001ADE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001ADE8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001ADEC:
    // 0x8001ADEC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001ADF0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8001ADF4: nop

    // 0x8001ADF8: sb          $t9, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r25;
    // 0x8001ADFC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001AE00: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001AE04: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001AE08: nop

    // 0x8001AE0C: bc1fl       L_8001AE20
    if (!c1cs) {
        // 0x8001AE10: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001AE20;
    }
    goto skip_1;
    // 0x8001AE10: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x8001AE14: b           L_8001AE20
    // 0x8001AE18: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001AE20;
    // 0x8001AE18: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001AE1C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AE20:
    // 0x8001AE20: mul.s       $f2, $f24, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x8001AE24: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AE28: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001AE2C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8001AE30: bc1f        L_8001AE40
    if (!c1cs) {
        // 0x8001AE34: sb          $t2, 0xA($a3)
        MEM_B(0XA, ctx->r7) = ctx->r10;
            goto L_8001AE40;
    }
    // 0x8001AE34: sb          $t2, 0xA($a3)
    MEM_B(0XA, ctx->r7) = ctx->r10;
    // 0x8001AE38: b           L_8001AE44
    // 0x8001AE3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001AE44;
    // 0x8001AE3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001AE40:
    // 0x8001AE40: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AE44:
    // 0x8001AE44: mul.s       $f2, $f20, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8001AE48: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AE4C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001AE50: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8001AE54: bc1f        L_8001AE64
    if (!c1cs) {
        // 0x8001AE58: sb          $t5, 0x18($a3)
        MEM_B(0X18, ctx->r7) = ctx->r13;
            goto L_8001AE64;
    }
    // 0x8001AE58: sb          $t5, 0x18($a3)
    MEM_B(0X18, ctx->r7) = ctx->r13;
    // 0x8001AE5C: b           L_8001AE68
    // 0x8001AE60: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001AE68;
    // 0x8001AE60: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001AE64:
    // 0x8001AE64: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AE68:
    // 0x8001AE68: mul.s       $f2, $f22, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x8001AE6C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AE70: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8001AE74: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001AE78: bc1f        L_8001AE88
    if (!c1cs) {
        // 0x8001AE7C: sb          $t8, 0x19($a3)
        MEM_B(0X19, ctx->r7) = ctx->r24;
            goto L_8001AE88;
    }
    // 0x8001AE7C: sb          $t8, 0x19($a3)
    MEM_B(0X19, ctx->r7) = ctx->r24;
    // 0x8001AE80: b           L_8001AE8C
    // 0x8001AE84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001AE8C;
    // 0x8001AE84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001AE88:
    // 0x8001AE88: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AE8C:
    // 0x8001AE8C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AE90: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x8001AE94: sb          $zero, 0x1($a3)
    MEM_B(0X1, ctx->r7) = 0;
    // 0x8001AE98: sb          $zero, 0x2($a3)
    MEM_B(0X2, ctx->r7) = 0;
    // 0x8001AE9C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8001AEA0: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x8001AEA4: sb          $zero, 0x4($a3)
    MEM_B(0X4, ctx->r7) = 0;
    // 0x8001AEA8: sb          $zero, 0x5($a3)
    MEM_B(0X5, ctx->r7) = 0;
    // 0x8001AEAC: sb          $zero, 0x6($a3)
    MEM_B(0X6, ctx->r7) = 0;
    // 0x8001AEB0: sb          $zero, 0x7($a3)
    MEM_B(0X7, ctx->r7) = 0;
    // 0x8001AEB4: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
    // 0x8001AEB8: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x8001AEBC: sb          $zero, 0x12($a3)
    MEM_B(0X12, ctx->r7) = 0;
    // 0x8001AEC0: sb          $zero, 0x13($a3)
    MEM_B(0X13, ctx->r7) = 0;
    // 0x8001AEC4: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
    // 0x8001AEC8: sb          $v0, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r2;
    // 0x8001AECC: sb          $zero, 0x16($a3)
    MEM_B(0X16, ctx->r7) = 0;
    // 0x8001AED0: sb          $zero, 0x17($a3)
    MEM_B(0X17, ctx->r7) = 0;
    // 0x8001AED4: sb          $t1, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r9;
    // 0x8001AED8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001AEDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001AEE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001AEE4: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8001AEE8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001AEEC: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001AEF0: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001AEF4: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001AEF8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8001AEFC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001AF00: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8001AF04: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001AF08: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001AF0C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8001AF10: nop

    // 0x8001AF14: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001AF18: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001AF1C: swc1        $f24, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f24.u32l;
    // 0x8001AF20: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x8001AF24: swc1        $f22, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f22.u32l;
    // 0x8001AF28: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001AF2C: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8001AF30: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001AF34: mul.s       $f6, $f2, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8001AF38: nop

    // 0x8001AF3C: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8001AF40: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8001AF44: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8001AF48: mul.s       $f8, $f14, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x8001AF4C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001AF50: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001AF54: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8001AF58: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x8001AF5C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AF60: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001AF64: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001AF68: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8001AF6C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001AF70: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8001AF74: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001AF78: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001AF7C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8001AF80: nop

    // 0x8001AF84: mul.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001AF88: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001AF8C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001AF90: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8001AF94: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8001AF98: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001AF9C: mul.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8001AFA0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001AFA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001AFA8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001AFAC: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8001AFB0: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x8001AFB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001AFB8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001AFBC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8001AFC0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001AFC4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001AFC8: jr          $ra
    // 0x8001AFCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8001AFCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ftCommonCaptureShoulderedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E558: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014E55C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014E560: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8014E564: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8014E568: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8014E56C: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x8014E570: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x8014E574: lw          $v0, 0x844($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X844);
    // 0x8014E578: lw          $s1, 0x84($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X84);
    // 0x8014E57C: jal         0x8014ACB4
    // 0x8014E580: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    ftCommonThrownSetStatusImmediate(rdram, ctx);
        goto after_0;
    // 0x8014E580: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014E584: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x8014E588: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014E58C: lwc1        $f8, -0x3DC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3DC0);
    // 0x8014E590: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8014E594: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8014E598: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014E59C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014E5A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8014E5A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014E5A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8014E5AC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8014E5B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8014E5B4: jal         0x8014E3EC
    // 0x8014E5B8: nop

    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_1;
    // 0x8014E5B8: nop

    after_1:
    // 0x8014E5BC: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014E5C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8014E5C4: lw          $a2, 0x288($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X288);
    // 0x8014E5C8: jal         0x800EA54C
    // 0x8014E5CC: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    ftParamGetStaledDamage(rdram, ctx);
        goto after_2;
    // 0x8014E5CC: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    after_2:
    // 0x8014E5D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8014E5D4: jal         0x800E8AAC
    // 0x8014E5D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    ftParamGetBestHitStatusAll(rdram, ctx);
        goto after_3;
    // 0x8014E5D8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x8014E5DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014E5E0: beq         $v0, $at, L_8014E5EC
    if (ctx->r2 == ctx->r1) {
        // 0x8014E5E4: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_8014E5EC;
    }
    // 0x8014E5E4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8014E5E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8014E5EC:
    // 0x8014E5EC: beql        $s0, $zero, L_8014E670
    if (ctx->r16 == 0) {
        // 0x8014E5F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8014E670;
    }
    goto skip_0;
    // 0x8014E5F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8014E5F4: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x8014E5F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8014E5FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8014E600: lw          $t9, 0x9C8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X9C8);
    // 0x8014E604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8014E608: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8014E60C: lwc1        $f6, 0x68($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X68);
    // 0x8014E610: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014E614: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8014E618: lbu         $t0, 0x12($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X12);
    // 0x8014E61C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8014E620: lbu         $t1, 0x12($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X12);
    // 0x8014E624: jal         0x800E9D78
    // 0x8014E628: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_4;
    // 0x8014E628: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_4:
    // 0x8014E62C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8014E630: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014E634: jal         0x801415F8
    // 0x8014E638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftCommonDamageUpdateDamageColAnim(rdram, ctx);
        goto after_5;
    // 0x8014E638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8014E63C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8014E640: jal         0x800EA248
    // 0x8014E644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamUpdateDamage(rdram, ctx);
        goto after_6;
    // 0x8014E644: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8014E648: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014E64C: lbu         $a1, 0xD($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XD);
    // 0x8014E650: jal         0x800EA98C
    // 0x8014E654: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_7;
    // 0x8014E654: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8014E658: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x8014E65C: lbu         $a1, 0xD($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0XD);
    // 0x8014E660: lw          $a2, 0x288($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X288);
    // 0x8014E664: jal         0x800EA614
    // 0x8014E668: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_8;
    // 0x8014E668: lhu         $a3, 0x28C($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X28C);
    after_8:
    // 0x8014E66C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8014E670:
    // 0x8014E670: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8014E674: jal         0x800E806C
    // 0x8014E678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_9;
    // 0x8014E678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8014E67C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014E680: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8014E684: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8014E688: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8014E68C: jr          $ra
    // 0x8014E690: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014E690: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayers1PBonusUpdateFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013476C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134774: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80134778: addiu       $s0, $s0, 0x7648
    ctx->r16 = ADD32(ctx->r16, 0X7648);
    // 0x8013477C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80134780: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80134784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134788: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013478C: bne         $t6, $at, L_801347B4
    if (ctx->r14 != ctx->r1) {
        // 0x80134790: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801347B4;
    }
    // 0x80134790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134794: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80134798: bne         $t7, $zero, L_801347B4
    if (ctx->r15 != 0) {
        // 0x8013479C: nop
    
            goto L_801347B4;
    }
    // 0x8013479C: nop

    // 0x801347A0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801347A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801347A8: jal         0x80133BCC
    // 0x801347AC: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
    mnPlayers1PBonusMakeHiScore(rdram, ctx);
        goto after_0;
    // 0x801347AC: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
    after_0:
    // 0x801347B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801347B4:
    // 0x801347B4: bne         $v0, $zero, L_801347DC
    if (ctx->r2 != 0) {
        // 0x801347B8: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_801347DC;
    }
    // 0x801347B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801347BC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801347C0: jal         0x80134108
    // 0x801347C4: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PBonusMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801347C4: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x801347C8: jal         0x80133BCC
    // 0x801347CC: nop

    mnPlayers1PBonusMakeHiScore(rdram, ctx);
        goto after_2;
    // 0x801347CC: nop

    after_2:
    // 0x801347D0: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801347D4: sw          $zero, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = 0;
    // 0x801347D8: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_801347DC:
    // 0x801347DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801347E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801347E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801347E8: jr          $ra
    // 0x801347EC: nop

    return;
    // 0x801347EC: nop

;}
RECOMP_FUNC void syInterpGetFracFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E344: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001E348: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001E34C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8001E350: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8001E354: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8001E358: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8001E35C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8001E360: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8001E364: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8001E368: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001E36C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001E370: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x8001E374: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001E378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001E37C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001E380: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001E384: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8001E388: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8001E38C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001E390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001E394: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E398: bc1f        L_8001E3BC
    if (!c1cs) {
        // 0x8001E39C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001E3BC;
    }
    // 0x8001E39C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001E3A0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
L_8001E3A4:
    // 0x8001E3A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E3A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001E3AC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8001E3B0: nop

    // 0x8001E3B4: bc1tl       L_8001E3A4
    if (c1cs) {
        // 0x8001E3B8: lwc1        $f6, 0x8($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8001E3A4;
    }
    goto skip_0;
    // 0x8001E3B8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
L_8001E3BC:
    // 0x8001E3BC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001E3C0: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001E3C4: beql        $v0, $zero, L_8001E3F4
    if (ctx->r2 == 0) {
        // 0x8001E3C8: addu        $v0, $v1, $t6
        ctx->r2 = ADD32(ctx->r3, ctx->r14);
            goto L_8001E3F4;
    }
    goto skip_1;
    // 0x8001E3C8: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    skip_1:
    // 0x8001E3CC: beq         $v0, $at, L_8001E40C
    if (ctx->r2 == ctx->r1) {
        // 0x8001E3D0: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_8001E40C;
    }
    // 0x8001E3D0: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8001E3D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E3D8: beq         $v0, $at, L_8001E40C
    if (ctx->r2 == ctx->r1) {
        // 0x8001E3DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001E40C;
    }
    // 0x8001E3DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001E3E0: beql        $v0, $at, L_8001E410
    if (ctx->r2 == ctx->r1) {
        // 0x8001E3E4: addu        $t8, $v1, $t7
        ctx->r24 = ADD32(ctx->r3, ctx->r15);
            goto L_8001E410;
    }
    goto skip_2;
    // 0x8001E3E4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    skip_2:
    // 0x8001E3E8: b           L_8001E4D8
    // 0x8001E3EC: lwc1        $f28, 0x5C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_8001E4D8;
    // 0x8001E3EC: lwc1        $f28, 0x5C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001E3F0: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
L_8001E3F4:
    // 0x8001E3F4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001E3F8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001E3FC: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8001E400: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8001E404: b           L_8001E4D8
    // 0x8001E408: div.s       $f28, $f8, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
        goto L_8001E4D8;
    // 0x8001E408: div.s       $f28, $f8, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
L_8001E40C:
    // 0x8001E40C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
L_8001E410:
    // 0x8001E410: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8001E414: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001E418: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001E41C: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8001E420: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8001E424: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8001E428: addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
    // 0x8001E42C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001E430: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001E434: lwc1        $f24, -0x1BFC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X1BFC);
    // 0x8001E438: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8001E43C: add.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f26.fl;
L_8001E440:
    // 0x8001E440: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x8001E444: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8001E448: mul.s       $f14, $f10, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8001E44C: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x8001E450: jal         0x8001E240
    // 0x8001E454: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    syInterpGetCubicIntegralApprox(rdram, ctx);
        goto after_0;
    // 0x8001E454: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    after_0:
    // 0x8001E458: add.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x8001E45C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001E460: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x8001E464: nop

    // 0x8001E468: bc1fl       L_8001E47C
    if (!c1cs) {
        // 0x8001E46C: mov.s       $f22, $f28
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    ctx->f22.fl = ctx->f28.fl;
            goto L_8001E47C;
    }
    goto skip_3;
    // 0x8001E46C: mov.s       $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    ctx->f22.fl = ctx->f28.fl;
    skip_3:
    // 0x8001E470: b           L_8001E480
    // 0x8001E474: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
        goto L_8001E480;
    // 0x8001E474: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8001E478: mov.s       $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    ctx->f22.fl = ctx->f28.fl;
L_8001E47C:
    // 0x8001E47C: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
L_8001E480:
    // 0x8001E480: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x8001E484: nop

    // 0x8001E488: bc1fl       L_8001E4A0
    if (!c1cs) {
        // 0x8001E48C: sub.s       $f0, $f22, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f26.fl;
            goto L_8001E4A0;
    }
    goto skip_4;
    // 0x8001E48C: sub.s       $f0, $f22, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f26.fl;
    skip_4:
    // 0x8001E490: sub.s       $f0, $f22, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x8001E494: b           L_8001E4A0
    // 0x8001E498: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8001E4A0;
    // 0x8001E498: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001E49C: sub.s       $f0, $f22, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f26.fl;
L_8001E4A0:
    // 0x8001E4A0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8001E4A4: nop

    // 0x8001E4A8: bc1tl       L_8001E4DC
    if (c1cs) {
        // 0x8001E4AC: lh          $t0, 0x2($s2)
        ctx->r8 = MEM_H(ctx->r18, 0X2);
            goto L_8001E4DC;
    }
    goto skip_5;
    // 0x8001E4AC: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
    skip_5:
    // 0x8001E4B0: add.s       $f16, $f2, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x8001E4B4: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8001E4B8: nop

    // 0x8001E4BC: bc1tl       L_8001E440
    if (c1cs) {
        // 0x8001E4C0: add.s       $f10, $f22, $f26
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_8001E440;
    }
    goto skip_6;
    // 0x8001E4C0: add.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f26.fl;
    skip_6:
    // 0x8001E4C4: sub.s       $f18, $f2, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f24.fl;
    // 0x8001E4C8: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x8001E4CC: nop

    // 0x8001E4D0: bc1tl       L_8001E440
    if (c1cs) {
        // 0x8001E4D4: add.s       $f10, $f22, $f26
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_8001E440;
    }
    goto skip_7;
    // 0x8001E4D4: add.s       $f10, $f22, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f26.fl;
    skip_7:
L_8001E4D8:
    // 0x8001E4D8: lh          $t0, 0x2($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X2);
L_8001E4DC:
    // 0x8001E4DC: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x8001E4E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001E4E4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001E4E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001E4EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001E4F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8001E4F4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8001E4F8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8001E4FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001E500: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001E504: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001E508: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8001E50C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8001E510: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x8001E514: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8001E518: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8001E51C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8001E520: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8001E524: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001E528: jr          $ra
    // 0x8001E52C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    return;
    // 0x8001E52C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
;}
RECOMP_FUNC void mnPlayers1PTrainingPuckGlowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136E1C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136E20: addiu       $v1, $v1, -0x7788
    ctx->r3 = ADD32(ctx->r3, -0X7788);
    // 0x80136E24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80136E28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80136E2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136E30: bne         $v0, $zero, L_80136E5C
    if (ctx->r2 != 0) {
        // 0x80136E34: addiu       $a0, $a0, -0x778C
        ctx->r4 = ADD32(ctx->r4, -0X778C);
            goto L_80136E5C;
    }
    // 0x80136E34: addiu       $a0, $a0, -0x778C
    ctx->r4 = ADD32(ctx->r4, -0X778C);
    // 0x80136E38: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80136E3C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80136E40: addiu       $t7, $t6, 0x9
    ctx->r15 = ADD32(ctx->r14, 0X9);
    // 0x80136E44: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80136E48: bne         $at, $zero, L_80136E5C
    if (ctx->r1 != 0) {
        // 0x80136E4C: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_80136E5C;
    }
    // 0x80136E4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80136E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80136E54: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80136E58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80136E5C:
    // 0x80136E5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136E60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136E64: bne         $v0, $at, L_80136E8C
    if (ctx->r2 != ctx->r1) {
        // 0x80136E68: addiu       $a0, $a0, -0x778C
        ctx->r4 = ADD32(ctx->r4, -0X778C);
            goto L_80136E8C;
    }
    // 0x80136E68: addiu       $a0, $a0, -0x778C
    ctx->r4 = ADD32(ctx->r4, -0X778C);
    // 0x80136E6C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80136E70: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80136E74: addiu       $t2, $t1, -0x9
    ctx->r10 = ADD32(ctx->r9, -0X9);
    // 0x80136E78: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x80136E7C: beq         $at, $zero, L_80136E8C
    if (ctx->r1 == 0) {
        // 0x80136E80: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_80136E8C;
    }
    // 0x80136E80: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80136E84: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80136E88: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80136E8C:
    // 0x80136E8C: jr          $ra
    // 0x80136E90: nop

    return;
    // 0x80136E90: nop

;}
RECOMP_FUNC void mnVSResultsMakeEmblemCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801368D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801368D4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801368D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801368DC: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x801368E0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801368E4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801368E8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801368EC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801368F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801368F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801368F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801368FC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80136900: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80136904: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80136908: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013690C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136910: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80136914: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136918: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013691C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80136920: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136924: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80136928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013692C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80136930: jal         0x8000B93C
    // 0x80136934: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136934: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136938: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013693C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136940: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136944: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80136948: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013694C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80136950: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80136954: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80136958: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013695C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80136960: jal         0x80007080
    // 0x80136964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80136964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80136968: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8013696C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80136970: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80136974: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013697C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136980: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80136984: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80136988: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8013698C: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80136990: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80136994: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80136998: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8013699C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x801369A0: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x801369A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801369A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801369AC: jr          $ra
    // 0x801369B0: nop

    return;
    // 0x801369B0: nop

;}
RECOMP_FUNC void grHyruleTwisterMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010A144: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010A148: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010A14C: lw          $a0, 0x140C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X140C);
    // 0x8010A150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A154: jal         0x800CE9E8
    // 0x8010A158: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x8010A158: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x8010A15C: beq         $v0, $zero, L_8010A1D0
    if (ctx->r2 == 0) {
        // 0x8010A160: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010A1D0;
    }
    // 0x8010A160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010A164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010A168: jal         0x800CE1DC
    // 0x8010A16C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x8010A16C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8010A170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A174: bne         $v0, $zero, L_8010A18C
    if (ctx->r2 != 0) {
        // 0x8010A178: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010A18C;
    }
    // 0x8010A178: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010A17C: jal         0x800CEA40
    // 0x8010A180: nop

    lbParticleEjectStruct(rdram, ctx);
        goto after_2;
    // 0x8010A180: nop

    after_2:
    // 0x8010A184: b           L_8010A1D4
    // 0x8010A188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A1D4;
    // 0x8010A188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A18C:
    // 0x8010A18C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8010A190: jal         0x800CEA14
    // 0x8010A194: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x8010A194: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x8010A198: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8010A19C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A1A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8010A1A4: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x8010A1A8: bnel        $t6, $zero, L_8010A1BC
    if (ctx->r14 != 0) {
        // 0x8010A1AC: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_8010A1BC;
    }
    goto skip_0;
    // 0x8010A1AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x8010A1B0: b           L_8010A1D4
    // 0x8010A1B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A1D4;
    // 0x8010A1B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010A1B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_8010A1BC:
    // 0x8010A1BC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8010A1C0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010A1C4: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8010A1C8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8010A1CC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_8010A1D0:
    // 0x8010A1D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8010A1D4:
    // 0x8010A1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A1D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010A1DC: jr          $ra
    // 0x8010A1E0: nop

    return;
    // 0x8010A1E0: nop

;}
RECOMP_FUNC void mnVSResultsMakeTintCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134DF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134DF8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80134DFC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134E00: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80134E04: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x80134E08: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134E0C: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80134E10: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134E14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134E18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134E1C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80134E20: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80134E24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134E28: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134E2C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134E30: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134E34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134E38: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134E3C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134E40: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134E44: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80134E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134E4C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134E50: jal         0x8000B93C
    // 0x80134E54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80134E54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134E58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134E5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134E60: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80134E64: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134E68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134E6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134E70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134E74: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134E78: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134E7C: jal         0x80007080
    // 0x80134E80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134E80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134E84: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134E88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134E8C: jr          $ra
    // 0x80134E90: nop

    return;
    // 0x80134E90: nop

;}
RECOMP_FUNC void efManagerDefaultProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDBCC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FDBD0: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x800FDBD4: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800FDBD8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800FDBDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FDBE0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x800FDBE4: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x800FDBE8: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FDBEC: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FDBF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FDBF4: jr          $ra
    // 0x800FDBF8: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x800FDBF8: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_ovl8_8037D3AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D3AC: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037D3B0: addiu       $v1, $v1, -0x1020
    ctx->r3 = ADD32(ctx->r3, -0X1020);
    // 0x8037D3B4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8037D3B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037D3BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8037D3C0: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8037D3C4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8037D3C8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8037D3CC: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8037D3D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8037D3D4: jr          $ra
    // 0x8037D3D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x8037D3D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void scExplainSetBattleState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D14C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D150: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D154: addiu       $v0, $v0, -0x1810
    ctx->r2 = ADD32(ctx->r2, -0X1810);
    // 0x8018D158: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018D15C: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018D160: addiu       $v1, $v1, 0x50E8
    ctx->r3 = ADD32(ctx->r3, 0X50E8);
    // 0x8018D164: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8018D168: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018D16C: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8018D170:
    // 0x8018D170: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D174: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D178: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018D17C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018D180: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018D184: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018D188: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018D18C: bne         $t6, $t0, L_8018D170
    if (ctx->r14 != ctx->r8) {
        // 0x8018D190: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018D170;
    }
    // 0x8018D190: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018D194: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D198: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018D19C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8018D1A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D1A4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8018D1A8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8018D1AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D1B0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018D1B4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    // 0x8018D1B8: sb          $t5, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r13;
    // 0x8018D1BC: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8018D1C0: sb          $zero, 0x23($v0)
    MEM_B(0X23, ctx->r2) = 0;
    // 0x8018D1C4: sb          $t7, 0x97($v0)
    MEM_B(0X97, ctx->r2) = ctx->r15;
    // 0x8018D1C8: sb          $a0, 0x22($v0)
    MEM_B(0X22, ctx->r2) = ctx->r4;
    // 0x8018D1CC: jr          $ra
    // 0x8018D1D0: sb          $a0, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r4;
    return;
    // 0x8018D1D0: sb          $a0, 0x96($v0)
    MEM_B(0X96, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80027458_28058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027458: jr          $ra
    // 0x8002745C: nop

    return;
    // 0x8002745C: nop

;}
RECOMP_FUNC void ifCommonTimerSetAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112EBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80112EC0: addiu       $a0, $a0, 0xD40
    ctx->r4 = ADD32(ctx->r4, 0XD40);
    // 0x80112EC4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80112EC8: lw          $t7, -0x116C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X116C);
    // 0x80112ECC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80112ED0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    // 0x80112ED4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80112ED8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80112EDC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80112EE0: sh          $a1, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r5;
    // 0x80112EE4: addiu       $v0, $v0, -0x1138
    ctx->r2 = ADD32(ctx->r2, -0X1138);
    // 0x80112EE8: addiu       $v1, $v1, -0x1168
    ctx->r3 = ADD32(ctx->r3, -0X1168);
L_80112EEC:
    // 0x80112EEC: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80112EF0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80112EF4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80112EF8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80112EFC: sh          $a1, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r5;
    // 0x80112F00: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x80112F04: lw          $t3, -0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, -0XC);
    // 0x80112F08: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80112F0C: sh          $a1, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r5;
    // 0x80112F10: lw          $t5, 0xC($a0)
    ctx->r13 = MEM_W(ctx->r4, 0XC);
    // 0x80112F14: lw          $t6, -0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X8);
    // 0x80112F18: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80112F1C: sh          $a1, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r5;
    // 0x80112F20: lw          $t9, -0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X4);
    // 0x80112F24: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80112F28: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80112F2C: bne         $v1, $v0, L_80112EEC
    if (ctx->r3 != ctx->r2) {
        // 0x80112F30: sh          $a1, 0x14($t0)
        MEM_H(0X14, ctx->r8) = ctx->r5;
            goto L_80112EEC;
    }
    // 0x80112F30: sh          $a1, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r5;
    // 0x80112F34: jr          $ra
    // 0x80112F38: nop

    return;
    // 0x80112F38: nop

;}
RECOMP_FUNC void mvOpeningYosterMakeNest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B6C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131B70: jal         0x80009968
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B78: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B7C: lw          $t6, 0x25F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25F8);
    // 0x80131B80: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131B84: addiu       $t7, $t7, -0x67F8
    ctx->r15 = ADD32(ctx->r15, -0X67F8);
    // 0x80131B88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131B94: jal         0x8000F120
    // 0x80131B98: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131B98: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131B9C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131BA0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131BA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131BA8: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131BB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131BB4: jal         0x80009DF4
    // 0x80131BB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131BB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131BBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131BC0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131BC4: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131BC8: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131BCC: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131BD0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131BD4: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131BD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131BDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131BE4: jr          $ra
    // 0x80131BE8: nop

    return;
    // 0x80131BE8: nop

;}
RECOMP_FUNC void ftCommonAttackLw4CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015088C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80150890: jal         0x80150798
    // 0x80150894: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonAttackLw4CheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80150894: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150898: beq         $v0, $zero, L_801508C0
    if (ctx->r2 == 0) {
        // 0x8015089C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_801508C0;
    }
    // 0x8015089C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801508A0: lbu         $t6, 0x269($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X269);
    // 0x801508A4: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x801508A8: beql        $at, $zero, L_801508C4
    if (ctx->r1 == 0) {
        // 0x801508AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801508C4;
    }
    goto skip_0;
    // 0x801508AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801508B0: jal         0x801507D0
    // 0x801508B4: nop

    ftCommonAttackLw4CheckInterruptMain(rdram, ctx);
        goto after_1;
    // 0x801508B4: nop

    after_1:
    // 0x801508B8: b           L_801508C8
    // 0x801508BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801508C8;
    // 0x801508BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801508C0:
    // 0x801508C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801508C4:
    // 0x801508C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801508C8:
    // 0x801508C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801508CC: jr          $ra
    // 0x801508D0: nop

    return;
    // 0x801508D0: nop

;}
RECOMP_FUNC void ftMarioSpecialLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015688C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156890: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80156894: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80156898: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8015689C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801568A0: jal         0x801567A4
    // 0x801568A4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftMarioSpecialAirLwSetDisableRise(rdram, ctx);
        goto after_0;
    // 0x801568A4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801568A8: jal         0x800DEEC8
    // 0x801568AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x801568AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801568B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801568B4: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x801568B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801568BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801568C0: jal         0x800E6F24
    // 0x801568C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801568C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801568C8: jal         0x800E0830
    // 0x801568CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x801568CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801568D0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x801568D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801568D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801568DC: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    // 0x801568E0: jal         0x800D8E78
    // 0x801568E4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_4;
    // 0x801568E4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x801568E8: jal         0x8015686C
    // 0x801568EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMarioSpecialLwInitStatusVars(rdram, ctx);
        goto after_5;
    // 0x801568EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801568F0: lbu         $t6, 0x28E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X28E);
    // 0x801568F4: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x801568F8: sb          $t7, 0x28E($s0)
    MEM_B(0X28E, ctx->r16) = ctx->r15;
    // 0x801568FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80156900: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80156904: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80156908: jr          $ra
    // 0x8015690C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8015690C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSModeSetTextureColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BC4: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131BC8: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131BCC: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131BD0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131BD4: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131BD8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80131BDC: sb          $t0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r8;
    // 0x80131BE0: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80131BE4: sb          $t1, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r9;
    // 0x80131BE8: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80131BEC: jr          $ra
    // 0x80131BF0: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
    return;
    // 0x80131BF0: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void mnPlayers1PBonusCheckManFighterSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135634: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80135638: lw          $t6, 0x7674($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7674);
    // 0x8013563C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80135640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135644: beq         $t6, $zero, L_80135654
    if (ctx->r14 == 0) {
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
RECOMP_FUNC void mnPlayersVSFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A920: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A924: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013A928: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8013A92C: addiu       $s0, $s0, -0x4234
    ctx->r16 = ADD32(ctx->r16, -0X4234);
    // 0x8013A930: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8013A934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A938: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013A93C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013A940: jal         0x8013A2A4
    // 0x8013A944: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    mnPlayersVSUpdateControllerOrders(rdram, ctx);
        goto after_0;
    // 0x8013A944: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_0:
    // 0x8013A948: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A94C: lw          $t8, -0x4230($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4230);
    // 0x8013A950: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8013A954: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013A958: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013A95C: bne         $t8, $t9, L_8013A984
    if (ctx->r24 != ctx->r25) {
        // 0x8013A960: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8013A984;
    }
    // 0x8013A960: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013A964: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8013A968: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8013A96C: jal         0x8013A664
    // 0x8013A970: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    mnPlayersVSSetSceneData(rdram, ctx);
        goto after_1;
    // 0x8013A970: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_1:
    // 0x8013A974: jal         0x80005C74
    // 0x8013A978: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x8013A978: nop

    after_2:
    // 0x8013A97C: b           L_8013AAE8
    // 0x8013A980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013AAE8;
    // 0x8013A980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013A984:
    // 0x8013A984: jal         0x80390B7C
    // 0x8013A988: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_3;
    // 0x8013A988: nop

    after_3:
    // 0x8013A98C: bne         $v0, $zero, L_8013A9A4
    if (ctx->r2 != 0) {
        // 0x8013A990: lui         $t4, 0x8014
        ctx->r12 = S32(0X8014 << 16);
            goto L_8013A9A4;
    }
    // 0x8013A990: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x8013A994: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8013A998: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013A99C: addiu       $t3, $t2, 0x4650
    ctx->r11 = ADD32(ctx->r10, 0X4650);
    // 0x8013A9A0: sw          $t3, -0x4230($at)
    MEM_W(-0X4230, ctx->r1) = ctx->r11;
L_8013A9A4:
    // 0x8013A9A4: lw          $t4, -0x425C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X425C);
    // 0x8013A9A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013A9AC: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x8013A9B0: beq         $t4, $zero, L_8013AA58
    if (ctx->r12 == 0) {
        // 0x8013A9B4: nop
    
            goto L_8013AA58;
    }
    // 0x8013A9B4: nop

    // 0x8013A9B8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8013A9BC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013A9C0: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013A9C4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8013A9C8: bne         $t6, $zero, L_8013AAE4
    if (ctx->r14 != 0) {
        // 0x8013A9CC: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8013AAE4;
    }
    // 0x8013A9CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013A9D0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8013A9D4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8013A9D8: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x8013A9DC: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x8013A9E0: lbu         $t9, 0x4D12($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4D12);
    // 0x8013A9E4: addiu       $t1, $zero, 0x16
    ctx->r9 = ADD32(0, 0X16);
    // 0x8013A9E8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8013A9EC: beql        $t9, $zero, L_8013AA00
    if (ctx->r25 == 0) {
        // 0x8013A9F0: sb          $t1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r9;
            goto L_8013AA00;
    }
    goto skip_0;
    // 0x8013A9F0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    skip_0:
    // 0x8013A9F4: b           L_8013AA40
    // 0x8013A9F8: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
        goto L_8013AA40;
    // 0x8013A9F8: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x8013A9FC: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_8013AA00:
    // 0x8013AA00: lbu         $t2, 0x4937($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4937);
    // 0x8013AA04: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x8013AA08: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8013AA0C: beq         $t3, $zero, L_8013AA1C
    if (ctx->r11 == 0) {
        // 0x8013AA10: nop
    
            goto L_8013AA1C;
    }
    // 0x8013AA10: nop

    // 0x8013AA14: b           L_8013AA1C
    // 0x8013AA18: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_8013AA1C;
    // 0x8013AA18: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8013AA1C:
    // 0x8013AA1C: jal         0x80018A30
    // 0x8013AA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_4;
    // 0x8013AA20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013AA24: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013AA28: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013AA2C: lbu         $t4, 0xF($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF);
    // 0x8013AA30: beq         $v0, $t4, L_8013AA1C
    if (ctx->r2 == ctx->r12) {
        // 0x8013AA34: nop
    
            goto L_8013AA1C;
    }
    // 0x8013AA34: nop

    // 0x8013AA38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8013AA3C: sb          $v0, 0x4ADF($at)
    MEM_B(0X4ADF, ctx->r1) = ctx->r2;
L_8013AA40:
    // 0x8013AA40: jal         0x8013A664
    // 0x8013AA44: nop

    mnPlayersVSSetSceneData(rdram, ctx);
        goto after_5;
    // 0x8013AA44: nop

    after_5:
    // 0x8013AA48: jal         0x80005C74
    // 0x8013AA4C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8013AA4C: nop

    after_6:
    // 0x8013AA50: b           L_8013AAE8
    // 0x8013AA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013AAE8;
    // 0x8013AA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013AA58:
    // 0x8013AA58: jal         0x8039076C
    // 0x8013AA5C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x8013AA5C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_7:
    // 0x8013AA60: beql        $v0, $zero, L_8013AACC
    if (ctx->r2 == 0) {
        // 0x8013AA64: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8013AACC;
    }
    goto skip_1;
    // 0x8013AA64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_1:
    // 0x8013AA68: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8013AA6C: slti        $at, $t5, 0x3D
    ctx->r1 = SIGNED(ctx->r13) < 0X3D ? 1 : 0;
    // 0x8013AA70: bnel        $at, $zero, L_8013AACC
    if (ctx->r1 != 0) {
        // 0x8013AA74: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8013AACC;
    }
    goto skip_2;
    // 0x8013AA74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_2:
    // 0x8013AA78: jal         0x8013A5E4
    // 0x8013AA7C: nop

    mnPlayersVSCheckReady(rdram, ctx);
        goto after_8;
    // 0x8013AA7C: nop

    after_8:
    // 0x8013AA80: beq         $v0, $zero, L_8013AAC0
    if (ctx->r2 == 0) {
        // 0x8013AA84: nop
    
            goto L_8013AAC0;
    }
    // 0x8013AA84: nop

    // 0x8013AA88: jal         0x800269C0
    // 0x8013AA8C: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x8013AA8C: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_9:
    // 0x8013AA90: jal         0x8013A40C
    // 0x8013AA94: nop

    mnPlayersVSSetIdlePlayerNotAll(rdram, ctx);
        goto after_10;
    // 0x8013AA94: nop

    after_10:
    // 0x8013AA98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013AA9C: addiu       $v0, $v0, -0x4260
    ctx->r2 = ADD32(ctx->r2, -0X4260);
    // 0x8013AAA0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8013AAA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013AAA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013AAAC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013AAB0: jal         0x8013A8B8
    // 0x8013AAB4: sw          $t7, -0x425C($at)
    MEM_W(-0X425C, ctx->r1) = ctx->r15;
    mnPlayersVSPauseSlotProcesses(rdram, ctx);
        goto after_11;
    // 0x8013AAB4: sw          $t7, -0x425C($at)
    MEM_W(-0X425C, ctx->r1) = ctx->r15;
    after_11:
    // 0x8013AAB8: b           L_8013AACC
    // 0x8013AABC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8013AACC;
    // 0x8013AABC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8013AAC0:
    // 0x8013AAC0: jal         0x800269C0
    // 0x8013AAC4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x8013AAC4: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_12:
    // 0x8013AAC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8013AACC:
    // 0x8013AACC: jal         0x8013A0DC
    // 0x8013AAD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSUpdateGate(rdram, ctx);
        goto after_13;
    // 0x8013AAD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8013AAD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013AAD8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013AADC: bne         $s0, $at, L_8013AACC
    if (ctx->r16 != ctx->r1) {
        // 0x8013AAE0: nop
    
            goto L_8013AACC;
    }
    // 0x8013AAE0: nop

L_8013AAE4:
    // 0x8013AAE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013AAE8:
    // 0x8013AAE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013AAEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013AAF0: jr          $ra
    // 0x8013AAF4: nop

    return;
    // 0x8013AAF4: nop

;}
RECOMP_FUNC void itBombHeiExplodeWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177C64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80177C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177C6C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80177C70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80177C74: jal         0x8017761C
    // 0x80177C78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itBombHeiWalkUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80177C78: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80177C7C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80177C80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80177C84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177C88: lhu         $v1, 0x33E($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X33E);
    // 0x80177C8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80177C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80177C94: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80177C98: bgez        $v1, L_80177CAC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80177C9C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80177CAC;
    }
    // 0x80177C9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80177CA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80177CA4: nop

    // 0x80177CA8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80177CAC:
    // 0x80177CAC: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x80177CB0: nop

    // 0x80177CB4: bc1fl       L_80177CE4
    if (!c1cs) {
        // 0x80177CB8: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80177CE4;
    }
    goto skip_0;
    // 0x80177CB8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80177CBC: jal         0x80177180
    // 0x80177CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonCheckMakeDustEffect(rdram, ctx);
        goto after_1;
    // 0x80177CC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80177CC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80177CC8: jal         0x801779E4
    // 0x80177CCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonClearVelSetExplode(rdram, ctx);
        goto after_2;
    // 0x80177CCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80177CD0: jal         0x800269C0
    // 0x80177CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80177CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80177CD8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80177CDC: lhu         $v1, 0x33E($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X33E);
    // 0x80177CE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_80177CE4:
    // 0x80177CE4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80177CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177CEC: sh          $t9, 0x33E($t0)
    MEM_H(0X33E, ctx->r8) = ctx->r25;
    // 0x80177CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80177CF8: jr          $ra
    // 0x80177CFC: nop

    return;
    // 0x80177CFC: nop

;}
RECOMP_FUNC void sySchedulerSetTicCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000920: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000924: jr          $ra
    // 0x80000928: sw          $a0, 0x501C($at)
    MEM_W(0X501C, ctx->r1) = ctx->r4;
    return;
    // 0x80000928: sw          $a0, 0x501C($at)
    MEM_W(0X501C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void ftParamGetStatUpdateCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA74C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA750: addiu       $a0, $a0, 0xD96
    ctx->r4 = ADD32(ctx->r4, 0XD96);
    // 0x800EA754: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800EA758: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EA75C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800EA760: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800EA764: bne         $t7, $zero, L_800EA770
    if (ctx->r15 != 0) {
        // 0x800EA768: sh          $t6, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r14;
            goto L_800EA770;
    }
    // 0x800EA768: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800EA76C: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_800EA770:
    // 0x800EA770: jr          $ra
    // 0x800EA774: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EA774: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mvOpeningStandoffFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801326AC: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801326B0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801326B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801326B8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801326BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801326C0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801326C4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801326C8: addiu       $t8, $t8, 0x29E0
    ctx->r24 = ADD32(ctx->r24, 0X29E0);
    // 0x801326CC: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x801326D0: addiu       $t0, $t0, 0x2B60
    ctx->r8 = ADD32(ctx->r8, 0X2B60);
    // 0x801326D4: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801326D8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801326DC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801326E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801326E4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801326E8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801326EC: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801326F0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801326F4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x801326F8: jal         0x800CDF78
    // 0x801326FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801326FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132700: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132704: addiu       $a0, $a0, 0x28D0
    ctx->r4 = ADD32(ctx->r4, 0X28D0);
    // 0x80132708: jal         0x800CDEEC
    // 0x8013270C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013270C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132714: jal         0x80004980
    // 0x80132718: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132718: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013271C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132720: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132724: addiu       $a2, $a2, 0x2B98
    ctx->r6 = ADD32(ctx->r6, 0X2B98);
    // 0x80132728: addiu       $a0, $a0, 0x28D0
    ctx->r4 = ADD32(ctx->r4, 0X28D0);
    // 0x8013272C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132730: jal         0x800CDE04
    // 0x80132734: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132734: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132738: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013273C: addiu       $a1, $a1, 0x25DC
    ctx->r5 = ADD32(ctx->r5, 0X25DC);
    // 0x80132740: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132748: jal         0x80009968
    // 0x8013274C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013274C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132750: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132754: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013275C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132760: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132764: jal         0x8000B9FC
    // 0x80132768: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132768: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x8013276C: jal         0x80115890
    // 0x80132770: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80132770: nop

    after_6:
    // 0x80132774: jal         0x801325D0
    // 0x80132778: nop

    mvOpeningStandoffInitTotalTimeTics(rdram, ctx);
        goto after_7;
    // 0x80132778: nop

    after_7:
    // 0x8013277C: jal         0x800FD300
    // 0x80132780: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80132780: nop

    after_8:
    // 0x80132784: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132788: jal         0x800D7194
    // 0x8013278C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8013278C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80132790: jal         0x800D786C
    // 0x80132794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80132794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80132798: jal         0x800D786C
    // 0x8013279C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x8013279C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_11:
    // 0x801327A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327A4: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801327A8: jal         0x80004980
    // 0x801327AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_12;
    // 0x801327AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_12:
    // 0x801327B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327B8: sw          $v0, 0x29C8($at)
    MEM_W(0X29C8, ctx->r1) = ctx->r2;
    // 0x801327BC: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801327C0: jal         0x80004980
    // 0x801327C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_13;
    // 0x801327C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_13:
    // 0x801327C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327CC: jal         0x8013242C
    // 0x801327D0: sw          $v0, 0x29CC($at)
    MEM_W(0X29CC, ctx->r1) = ctx->r2;
    mvOpeningStandoffMakeMainCamera(rdram, ctx);
        goto after_14;
    // 0x801327D0: sw          $v0, 0x29CC($at)
    MEM_W(0X29CC, ctx->r1) = ctx->r2;
    after_14:
    // 0x801327D4: jal         0x80132530
    // 0x801327D8: nop

    mvOpeningStandoffMakeWallpaperCamera(rdram, ctx);
        goto after_15;
    // 0x801327D8: nop

    after_15:
    // 0x801327DC: jal         0x80132384
    // 0x801327E0: nop

    mvOpeningStandoffMakeLightningFlashCamera(rdram, ctx);
        goto after_16;
    // 0x801327E0: nop

    after_16:
    // 0x801327E4: jal         0x80131FC8
    // 0x801327E8: nop

    mvOpeningStandoffMakeWallpaper(rdram, ctx);
        goto after_17;
    // 0x801327E8: nop

    after_17:
    // 0x801327EC: jal         0x80131C00
    // 0x801327F0: nop

    mvOpeningStandoffMakeFighters(rdram, ctx);
        goto after_18;
    // 0x801327F0: nop

    after_18:
    // 0x801327F4: jal         0x80131B58
    // 0x801327F8: nop

    mvOpeningStandoffMakeGround(rdram, ctx);
        goto after_19;
    // 0x801327F8: nop

    after_19:
    // 0x801327FC: jal         0x801320C0
    // 0x80132800: nop

    mvOpeningStandoffMakeLightning(rdram, ctx);
        goto after_20;
    // 0x80132800: nop

    after_20:
    // 0x80132804: jal         0x80132338
    // 0x80132808: nop

    mvOpeningStandoffMakeLightningFlash(rdram, ctx);
        goto after_21;
    // 0x80132808: nop

    after_21:
    // 0x8013280C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132814: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132818: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013281C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132820: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80132824: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132828: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8013282C: jal         0x803904E0
    // 0x80132830: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_22;
    // 0x80132830: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_22:
    // 0x80132834: jal         0x8000092C
    // 0x80132838: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_23;
    // 0x80132838: nop

    after_23:
    // 0x8013283C: sltiu       $at, $v0, 0xE1A
    ctx->r1 = ctx->r2 < 0XE1A ? 1 : 0;
    // 0x80132840: beql        $at, $zero, L_80132860
    if (ctx->r1 == 0) {
        // 0x80132844: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132860;
    }
    goto skip_0;
    // 0x80132844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80132848:
    // 0x80132848: jal         0x8000092C
    // 0x8013284C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_24;
    // 0x8013284C: nop

    after_24:
    // 0x80132850: sltiu       $at, $v0, 0xE1A
    ctx->r1 = ctx->r2 < 0XE1A ? 1 : 0;
    // 0x80132854: bne         $at, $zero, L_80132848
    if (ctx->r1 != 0) {
        // 0x80132858: nop
    
            goto L_80132848;
    }
    // 0x80132858: nop

    // 0x8013285C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132860:
    // 0x80132860: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132864: jr          $ra
    // 0x80132868: nop

    return;
    // 0x80132868: nop

;}
RECOMP_FUNC void mnMapsSetLogoPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801327F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801327F8: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801327FC: addiu       $t6, $t6, 0x47E4
    ctx->r14 = ADD32(ctx->r14, 0X47E4);
    // 0x80132800: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x80132804: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132808:
    // 0x80132808: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013280C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132810: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132814: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132818: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013281C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132820: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132824: bne         $t6, $t0, L_80132808
    if (ctx->r14 != ctx->r8) {
        // 0x80132828: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132808;
    }
    // 0x80132828: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013282C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132830: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80132834: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x80132838: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8013283C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132840: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x80132844: bne         $a1, $at, L_80132870
    if (ctx->r5 != ctx->r1) {
        // 0x80132848: sw          $t7, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r15;
            goto L_80132870;
    }
    // 0x80132848: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8013284C: lui         $at, 0x435F
    ctx->r1 = S32(0X435F << 16);
    // 0x80132850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132854: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x80132858: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x8013285C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132860: swc1        $f4, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f4.u32l;
    // 0x80132864: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80132868: b           L_801328A0
    // 0x8013286C: swc1        $f6, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f6.u32l;
        goto L_801328A0;
    // 0x8013286C: swc1        $f6, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f6.u32l;
L_80132870:
    // 0x80132870: lui         $at, 0x433D
    ctx->r1 = S32(0X433D << 16);
    // 0x80132874: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132878: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8013287C: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x80132880: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80132884: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132888: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013288C: swc1        $f16, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f16.u32l;
    // 0x80132890: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80132894: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x80132898: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013289C: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
L_801328A0:
    // 0x801328A0: jr          $ra
    // 0x801328A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801328A4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftComputerCheckSetEvadeTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801366F0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801366F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801366F8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801366FC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80136700: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80136704: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80136708: lbu         $t6, 0x216($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X216);
    // 0x8013670C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136710: lwc1        $f20, -0x4220($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4220);
    // 0x80136714: lwc1        $f24, 0x1C($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80136718: lwc1        $f22, 0x20($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013671C: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80136720: sb          $t7, 0x216($a0)
    MEM_B(0X216, ctx->r4) = ctx->r15;
    // 0x80136724: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80136728: lw          $a1, 0x66FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66FC);
    // 0x8013672C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80136730: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80136734: beq         $a1, $zero, L_80136854
    if (ctx->r5 == 0) {
        // 0x80136738: addiu       $t0, $zero, 0xD
        ctx->r8 = ADD32(0, 0XD);
            goto L_80136854;
    }
    // 0x80136738: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x8013673C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136740: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136744: addiu       $a0, $a0, 0x1308
    ctx->r4 = ADD32(ctx->r4, 0X1308);
    // 0x80136748: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8013674C: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
L_80136750:
    // 0x80136750: beql        $a1, $t8, L_8013684C
    if (ctx->r5 == ctx->r24) {
        // 0x80136754: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_0;
    // 0x80136754: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80136758: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8013675C: lbu         $t1, 0xC($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0XC);
    // 0x80136760: lbu         $t9, 0xC($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XC);
    // 0x80136764: beql        $t9, $t1, L_8013684C
    if (ctx->r25 == ctx->r9) {
        // 0x80136768: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_1;
    // 0x80136768: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x8013676C: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80136770: lw          $v0, 0x8E8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8E8);
    // 0x80136774: lw          $t2, 0x5B4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5B4);
    // 0x80136778: mul.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8013677C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80136780: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80136784: add.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80136788: beq         $a3, $t2, L_801367AC
    if (ctx->r7 == ctx->r10) {
        // 0x8013678C: add.s       $f16, $f8, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
            goto L_801367AC;
    }
    // 0x8013678C: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80136790: lw          $v0, 0x84C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84C);
    // 0x80136794: beql        $v0, $zero, L_801367D0
    if (ctx->r2 == 0) {
        // 0x80136798: lw          $t5, 0x24($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X24);
            goto L_801367D0;
    }
    goto skip_2;
    // 0x80136798: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    skip_2:
    // 0x8013679C: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x801367A0: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x801367A4: bnel        $t0, $t4, L_801367D0
    if (ctx->r8 != ctx->r12) {
        // 0x801367A8: lw          $t5, 0x24($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X24);
            goto L_801367D0;
    }
    goto skip_3;
    // 0x801367A8: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    skip_3:
L_801367AC:
    // 0x801367AC: sub.s       $f0, $f24, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x801367B0: sw          $v1, 0x238($a2)
    MEM_W(0X238, ctx->r6) = ctx->r3;
    // 0x801367B4: sub.s       $f2, $f22, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x801367B8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801367BC: nop

    // 0x801367C0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801367C4: b           L_80136854
    // 0x801367C8: add.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f4.fl;
        goto L_80136854;
    // 0x801367C8: add.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801367CC: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
L_801367D0:
    // 0x801367D0: slti        $at, $t5, 0xA
    ctx->r1 = SIGNED(ctx->r13) < 0XA ? 1 : 0;
    // 0x801367D4: bnel        $at, $zero, L_8013684C
    if (ctx->r1 != 0) {
        // 0x801367D8: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_4;
    // 0x801367D8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_4:
    // 0x801367DC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x801367E0: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    // 0x801367E4: nop

    // 0x801367E8: bc1fl       L_8013684C
    if (!c1cs) {
        // 0x801367EC: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_5;
    // 0x801367EC: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_5:
    // 0x801367F0: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x801367F4: c.le.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl <= ctx->f14.fl;
    // 0x801367F8: nop

    // 0x801367FC: bc1fl       L_8013684C
    if (!c1cs) {
        // 0x80136800: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_6;
    // 0x80136800: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_6:
    // 0x80136804: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80136808: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x8013680C: nop

    // 0x80136810: bc1fl       L_8013684C
    if (!c1cs) {
        // 0x80136814: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_8013684C;
    }
    goto skip_7;
    // 0x80136814: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_7:
    // 0x80136818: sub.s       $f0, $f24, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x8013681C: sub.s       $f2, $f22, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x80136820: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80136824: nop

    // 0x80136828: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8013682C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80136830: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80136834: nop

    // 0x80136838: bc1f        L_80136848
    if (!c1cs) {
        // 0x8013683C: nop
    
            goto L_80136848;
    }
    // 0x8013683C: nop

    // 0x80136840: sw          $v1, 0x238($a2)
    MEM_W(0X238, ctx->r6) = ctx->r3;
    // 0x80136844: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_80136848:
    // 0x80136848: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_8013684C:
    // 0x8013684C: bnel        $a1, $zero, L_80136750
    if (ctx->r5 != 0) {
        // 0x80136850: lw          $t8, 0x4($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X4);
            goto L_80136750;
    }
    goto skip_8;
    // 0x80136850: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    skip_8:
L_80136854:
    // 0x80136854: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136858: lwc1        $f8, -0x421C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X421C);
    // 0x8013685C: addiu       $a3, $a2, 0x1CC
    ctx->r7 = ADD32(ctx->r6, 0X1CC);
    // 0x80136860: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80136864: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80136868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013686C: bc1fl       L_80136888
    if (!c1cs) {
        // 0x80136870: lw          $v1, 0x6C($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X6C);
            goto L_80136888;
    }
    goto skip_9;
    // 0x80136870: lw          $v1, 0x6C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X6C);
    skip_9:
    // 0x80136874: swc1        $f24, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f24.u32l;
    // 0x80136878: swc1        $f22, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f22.u32l;
    // 0x8013687C: b           L_80136A08
    // 0x80136880: sw          $t6, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r14;
        goto L_80136A08;
    // 0x80136880: sw          $t6, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r14;
    // 0x80136884: lw          $v1, 0x6C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X6C);
L_80136888:
    // 0x80136888: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    // 0x8013688C: lw          $v0, 0x8E8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8E8);
    // 0x80136890: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80136894: bltz        $a0, L_80136918
    if (SIGNED(ctx->r4) < 0) {
        // 0x80136898: lwc1        $f16, 0x20($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
            goto L_80136918;
    }
    // 0x80136898: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013689C: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x801368A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801368A4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x801368A8: bc1fl       L_801368E8
    if (!c1cs) {
        // 0x801368AC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_801368E8;
    }
    goto skip_10;
    // 0x801368AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_10:
    // 0x801368B0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x801368B4: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x801368B8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801368BC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801368C0: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x801368C4: jal         0x800F4428
    // 0x801368C8: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x801368C8: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801368CC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x801368D0: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x801368D4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801368D8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801368DC: b           L_80136938
    // 0x801368E0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80136938;
    // 0x801368E0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801368E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_801368E8:
    // 0x801368E8: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x801368EC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801368F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801368F4: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x801368F8: jal         0x800F4408
    // 0x801368FC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x801368FC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80136900: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80136904: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80136908: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8013690C: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80136910: b           L_80136938
    // 0x80136914: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80136938;
    // 0x80136914: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
L_80136918:
    // 0x80136918: lw          $t8, 0x8E8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8E8);
    // 0x8013691C: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x80136920: lw          $t1, 0x1C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X1C);
    // 0x80136924: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x80136928: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8013692C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80136930: lw          $t1, 0x24($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X24);
    // 0x80136934: sw          $t1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r9;
L_80136938:
    // 0x80136938: lw          $t2, 0x14C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14C);
    // 0x8013693C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136940: bnel        $t2, $zero, L_80136954
    if (ctx->r10 != 0) {
        // 0x80136944: swc1        $f22, 0x64($a3)
        MEM_W(0X64, ctx->r7) = ctx->f22.u32l;
            goto L_80136954;
    }
    goto skip_11;
    // 0x80136944: swc1        $f22, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f22.u32l;
    skip_11:
    // 0x80136948: b           L_80136954
    // 0x8013694C: swc1        $f16, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f16.u32l;
        goto L_80136954;
    // 0x8013694C: swc1        $f16, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f16.u32l;
    // 0x80136950: swc1        $f22, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->f22.u32l;
L_80136954:
    // 0x80136954: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x80136958: nop

    // 0x8013695C: bc1f        L_801369A4
    if (!c1cs) {
        // 0x80136960: nop
    
            goto L_801369A4;
    }
    // 0x80136960: nop

    // 0x80136964: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136968: lwc1        $f2, -0x4218($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4218);
    // 0x8013696C: sub.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80136970: swc1        $f0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f0.u32l;
    // 0x80136974: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80136978: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8013697C: nop

    // 0x80136980: bc1fl       L_801369E4
    if (!c1cs) {
        // 0x80136984: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_801369E4;
    }
    goto skip_12;
    // 0x80136984: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_12:
    // 0x80136988: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8013698C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136990: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80136994: jal         0x80132564
    // 0x80136998: swc1        $f4, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f4.u32l;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_2;
    // 0x80136998: swc1        $f4, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f4.u32l;
    after_2:
    // 0x8013699C: b           L_80136A08
    // 0x801369A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136A08;
    // 0x801369A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801369A4:
    // 0x801369A4: lwc1        $f2, -0x4214($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4214);
    // 0x801369A8: add.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x801369AC: swc1        $f0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f0.u32l;
    // 0x801369B0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801369B4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801369B8: nop

    // 0x801369BC: bc1fl       L_801369E4
    if (!c1cs) {
        // 0x801369C0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_801369E4;
    }
    goto skip_13;
    // 0x801369C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_13:
    // 0x801369C4: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x801369C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801369CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801369D0: jal         0x80132564
    // 0x801369D4: swc1        $f8, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f8.u32l;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_3;
    // 0x801369D4: swc1        $f8, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f8.u32l;
    after_3:
    // 0x801369D8: b           L_80136A08
    // 0x801369DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136A08;
    // 0x801369DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801369E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_801369E4:
    // 0x801369E4: jal         0x80033510
    // 0x801369E8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x801369E8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x801369EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801369F0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801369F4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801369F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801369FC: swc1        $f0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->f0.u32l;
    // 0x80136A00: sw          $t3, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r11;
    // 0x80136A04: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
L_80136A08:
    // 0x80136A08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80136A0C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80136A10: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80136A14: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80136A18: jr          $ra
    // 0x80136A1C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80136A1C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void sc1PStageClearCheckHaveBonusStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013305C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133060: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80133064: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80133068: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013306C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133070: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80133074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133078: addiu       $s2, $s2, 0x5320
    ctx->r18 = ADD32(ctx->r18, 0X5320);
    // 0x8013307C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133080: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x80133084: addiu       $s3, $zero, 0x60
    ctx->r19 = ADD32(0, 0X60);
    // 0x80133088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8013308C:
    // 0x8013308C: jal         0x80132FF8
    // 0x80133090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PStageClearSetupBonusStats(rdram, ctx);
        goto after_0;
    // 0x80133090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80133094: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80133098: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8013309C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801330A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801330A4: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801330A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801330AC: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x801330B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801330B4: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x801330B8: beq         $t3, $zero, L_801330C8
    if (ctx->r11 == 0) {
        // 0x801330BC: nop
    
            goto L_801330C8;
    }
    // 0x801330BC: nop

    // 0x801330C0: b           L_801330D4
    // 0x801330C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801330D4;
    // 0x801330C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801330C8:
    // 0x801330C8: bnel        $s0, $s3, L_8013308C
    if (ctx->r16 != ctx->r19) {
        // 0x801330CC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013308C;
    }
    goto skip_0;
    // 0x801330CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x801330D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801330D4:
    // 0x801330D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801330D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801330DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801330E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801330E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801330E8: jr          $ra
    // 0x801330EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801330EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonFireFlowerShootProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147434: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80147438: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8014743C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80147440: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80147444: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80147448: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014744C: lhu         $t7, 0x1BC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1BC);
    // 0x80147450: lhu         $t8, 0x1B4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1B4);
    // 0x80147454: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80147458: bnel        $t9, $zero, L_80147468
    if (ctx->r25 != 0) {
        // 0x8014745C: lw          $v0, 0xB2C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XB2C);
            goto L_80147468;
    }
    goto skip_0;
    // 0x8014745C: lw          $v0, 0xB2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB2C);
    skip_0:
    // 0x80147460: sw          $t0, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r8;
    // 0x80147464: lw          $v0, 0xB2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB2C);
L_80147468:
    // 0x80147468: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8014746C: beq         $at, $zero, L_8014747C
    if (ctx->r1 == 0) {
        // 0x80147470: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_8014747C;
    }
    // 0x80147470: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80147474: sw          $t1, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r9;
    // 0x80147478: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8014747C:
    // 0x8014747C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80147480: beql        $at, $zero, L_801474A4
    if (ctx->r1 == 0) {
        // 0x80147484: lw          $v0, 0x84C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84C);
            goto L_801474A4;
    }
    goto skip_1;
    // 0x80147484: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    skip_1:
    // 0x80147488: lhu         $t2, 0x1BE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X1BE);
    // 0x8014748C: lhu         $t3, 0x1B4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1B4);
    // 0x80147490: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80147494: beql        $t4, $zero, L_801474A4
    if (ctx->r12 == 0) {
        // 0x80147498: lw          $v0, 0x84C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84C);
            goto L_801474A4;
    }
    goto skip_2;
    // 0x80147498: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    skip_2:
    // 0x8014749C: sw          $zero, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = 0;
    // 0x801474A0: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
L_801474A4:
    // 0x801474A4: beql        $v0, $zero, L_8014771C
    if (ctx->r2 == 0) {
        // 0x801474A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8014771C;
    }
    goto skip_3;
    // 0x801474A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x801474AC: lw          $t5, 0x17C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X17C);
    // 0x801474B0: beql        $t5, $zero, L_801476E0
    if (ctx->r13 == 0) {
        // 0x801474B4: lw          $t1, 0xB24($s0)
        ctx->r9 = MEM_W(ctx->r16, 0XB24);
            goto L_801476E0;
    }
    goto skip_4;
    // 0x801474B4: lw          $t1, 0xB24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB24);
    skip_4:
    // 0x801474B8: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x801474BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801474C0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801474C4: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x801474C8: lw          $t7, 0xB24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB24);
    // 0x801474CC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x801474D0: bnel        $t7, $zero, L_801474E4
    if (ctx->r15 != 0) {
        // 0x801474D4: sw          $t9, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r25;
            goto L_801474E4;
    }
    goto skip_5;
    // 0x801474D4: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    skip_5:
    // 0x801474D8: b           L_801474E4
    // 0x801474DC: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
        goto L_801474E4;
    // 0x801474DC: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x801474E0: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
L_801474E4:
    // 0x801474E4: lw          $t0, 0xB20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB20);
    // 0x801474E8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801474EC: bne         $t1, $zero, L_801475C0
    if (ctx->r9 != 0) {
        // 0x801474F0: sw          $t1, 0xB20($s0)
        MEM_W(0XB20, ctx->r16) = ctx->r9;
            goto L_801475C0;
    }
    // 0x801474F0: sw          $t1, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r9;
    // 0x801474F4: sw          $t3, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r11;
    // 0x801474F8: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x801474FC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80147500: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80147504: lhu         $t5, 0x33E($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X33E);
    // 0x80147508: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8014750C: addiu       $t7, $t7, -0x797C
    ctx->r15 = ADD32(ctx->r15, -0X797C);
    // 0x80147510: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80147514: beq         $at, $zero, L_80147578
    if (ctx->r1 == 0) {
        // 0x80147518: addiu       $t4, $t4, -0x7970
        ctx->r12 = ADD32(ctx->r12, -0X7970);
            goto L_80147578;
    }
    // 0x80147518: addiu       $t4, $t4, -0x7970
    ctx->r12 = ADD32(ctx->r12, -0X7970);
    // 0x8014751C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80147520: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    // 0x80147524: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80147528: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8014752C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80147530: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80147534: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80147538: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8014753C: sw          $t9, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r25;
    // 0x80147540: lw          $t0, 0x9C8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X9C8);
    // 0x80147544: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80147548: lw          $a2, 0x33C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X33C);
    // 0x8014754C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80147550: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x80147554: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80147558: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8014755C: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80147560: jal         0x800EABDC
    // 0x80147564: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    ftParamMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80147564: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_0:
    // 0x80147568: jal         0x800269C0
    // 0x8014756C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8014756C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x80147570: b           L_801475C4
    // 0x80147574: lw          $t8, 0xB1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB1C);
        goto L_801475C4;
    // 0x80147574: lw          $t8, 0xB1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB1C);
L_80147578:
    // 0x80147578: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8014757C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    // 0x80147580: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80147584: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80147588: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8014758C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80147590: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80147594: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80147598: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x8014759C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801475A0: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x801475A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801475A8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801475AC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801475B0: jal         0x800EABDC
    // 0x801475B4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    ftParamMakeEffect(rdram, ctx);
        goto after_2;
    // 0x801475B4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x801475B8: jal         0x800269C0
    // 0x801475BC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x801475BC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_3:
L_801475C0:
    // 0x801475C0: lw          $t8, 0xB1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB1C);
L_801475C4:
    // 0x801475C4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x801475C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801475CC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801475D0: bne         $t9, $zero, L_801475E4
    if (ctx->r25 != 0) {
        // 0x801475D4: sw          $t9, 0xB1C($s0)
        MEM_W(0XB1C, ctx->r16) = ctx->r25;
            goto L_801475E4;
    }
    // 0x801475D4: sw          $t9, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r25;
    // 0x801475D8: sw          $t1, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r9;
    // 0x801475DC: jal         0x801472D4
    // 0x801475E0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    ftCommonFireFlowerShootUpdateAmmoStats(rdram, ctx);
        goto after_4;
    // 0x801475E0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_4:
L_801475E4:
    // 0x801475E4: lw          $t2, 0x17C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X17C);
    // 0x801475E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801475EC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x801475F0: bne         $t2, $at, L_801476DC
    if (ctx->r10 != ctx->r1) {
        // 0x801475F4: lw          $t5, 0x74($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X74);
            goto L_801476DC;
    }
    // 0x801475F4: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x801475F8: lhu         $t4, 0x33E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X33E);
    // 0x801475FC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80147600: addiu       $t6, $t6, -0x7964
    ctx->r14 = ADD32(ctx->r14, -0X7964);
    // 0x80147604: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80147608: bnel        $at, $zero, L_801476CC
    if (ctx->r1 != 0) {
        // 0x8014760C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_801476CC;
    }
    goto skip_6;
    // 0x8014760C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    skip_6:
    // 0x80147610: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80147614: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80147618: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8014761C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80147620: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80147624: addiu       $t9, $t9, -0x7958
    ctx->r25 = ADD32(ctx->r25, -0X7958);
    // 0x80147628: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x8014762C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80147630: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80147634: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80147638: addiu       $t3, $t3, -0x794C
    ctx->r11 = ADD32(ctx->r11, -0X794C);
    // 0x8014763C: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
    // 0x80147640: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80147644: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x80147648: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014764C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80147650: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80147654: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80147658: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8014765C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80147660: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x80147664: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80147668: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8014766C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80147670: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80147674: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80147678: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x8014767C: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x80147680: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80147684: lw          $a2, 0x33C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X33C);
    // 0x80147688: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8014768C: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80147690: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80147694: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80147698: jal         0x800EABDC
    // 0x8014769C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    ftParamMakeEffect(rdram, ctx);
        goto after_5;
    // 0x8014769C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_5:
    // 0x801476A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801476A4: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x801476A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801476AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801476B0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801476B4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x801476B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801476BC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x801476C0: jal         0x800EABDC
    // 0x801476C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    ftParamMakeEffect(rdram, ctx);
        goto after_6;
    // 0x801476C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_6:
    // 0x801476C8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_801476CC:
    // 0x801476CC: sw          $t0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r8;
    // 0x801476D0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x801476D4: jal         0x8000BB04
    // 0x801476D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    gcSetAnimSpeed(rdram, ctx);
        goto after_7;
    // 0x801476D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
L_801476DC:
    // 0x801476DC: lw          $t1, 0xB24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB24);
L_801476E0:
    // 0x801476E0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x801476E4: bnel        $at, $zero, L_8014771C
    if (ctx->r1 != 0) {
        // 0x801476E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8014771C;
    }
    goto skip_7;
    // 0x801476E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x801476EC: lw          $t2, 0xB28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB28);
    // 0x801476F0: beql        $t2, $zero, L_8014771C
    if (ctx->r10 == 0) {
        // 0x801476F4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8014771C;
    }
    goto skip_8;
    // 0x801476F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x801476F8: lw          $t3, 0xB2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XB2C);
    // 0x801476FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80147700: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x80147704: bnel        $at, $zero, L_8014771C
    if (ctx->r1 != 0) {
        // 0x80147708: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8014771C;
    }
    goto skip_9;
    // 0x80147708: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_9:
    // 0x8014770C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x80147710: jal         0x8000BB04
    // 0x80147714: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    gcSetAnimSpeed(rdram, ctx);
        goto after_8;
    // 0x80147714: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_8:
    // 0x80147718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8014771C:
    // 0x8014771C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80147720: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80147724: jr          $ra
    // 0x80147728: nop

    return;
    // 0x80147728: nop

;}
RECOMP_FUNC void mnModeSelectEjectOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132518: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013251C: jal         0x80009A84
    // 0x80132520: lw          $a0, 0x2C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C8C);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132520: lw          $a0, 0x2C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C8C);
    after_0:
    // 0x80132524: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132528: jal         0x80009A84
    // 0x8013252C: lw          $a0, 0x2C90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C90);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8013252C: lw          $a0, 0x2C90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C90);
    after_1:
    // 0x80132530: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132534: jal         0x80009A84
    // 0x80132538: lw          $a0, 0x2C94($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C94);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80132538: lw          $a0, 0x2C94($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C94);
    after_2:
    // 0x8013253C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132540: jal         0x80009A84
    // 0x80132544: lw          $a0, 0x2C98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C98);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80132544: lw          $a0, 0x2C98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C98);
    after_3:
    // 0x80132548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013254C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132550: jr          $ra
    // 0x80132554: nop

    return;
    // 0x80132554: nop

;}
RECOMP_FUNC void itSawamuraFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182668: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018266C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80182670: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80182674: jal         0x801737B8
    // 0x80182678: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80182678: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018267C: beq         $v0, $zero, L_80182694
    if (ctx->r2 == 0) {
        // 0x80182680: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80182694;
    }
    // 0x80182680: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80182684: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182688: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8018268C: jal         0x8018273C
    // 0x80182690: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    itSawamuraWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80182690: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
    after_1:
L_80182694:
    // 0x80182694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018269C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801826A0: jr          $ra
    // 0x801826A4: nop

    return;
    // 0x801826A4: nop

;}
RECOMP_FUNC void mnPlayersVSCheckTimeArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134F64: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134F68: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80134F6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134F70: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134F74: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80134F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134F7C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80134F80: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80134F84: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80134F88: nop

    // 0x80134F8C: bc1t        L_80134FAC
    if (c1cs) {
        // 0x80134F90: nop
    
            goto L_80134FAC;
    }
    // 0x80134F90: nop

    // 0x80134F94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134F98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80134F9C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80134FA0: nop

    // 0x80134FA4: bc1f        L_80134FB4
    if (!c1cs) {
        // 0x80134FA8: nop
    
            goto L_80134FB4;
    }
    // 0x80134FA8: nop

L_80134FAC:
    // 0x80134FAC: b           L_80134FB4
    // 0x80134FB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80134FB4;
    // 0x80134FB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80134FB4:
    // 0x80134FB4: beq         $v1, $zero, L_80134FC4
    if (ctx->r3 == 0) {
        // 0x80134FB8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80134FC4;
    }
    // 0x80134FB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80134FBC: jr          $ra
    // 0x80134FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80134FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134FC4:
    // 0x80134FC4: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134FC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134FCC: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80134FD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134FD4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80134FD8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80134FDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80134FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134FE4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80134FE8: nop

    // 0x80134FEC: bc1f        L_80135014
    if (!c1cs) {
        // 0x80134FF0: nop
    
            goto L_80135014;
    }
    // 0x80134FF0: nop

    // 0x80134FF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134FF8: nop

    // 0x80134FFC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135000: nop

    // 0x80135004: bc1f        L_80135014
    if (!c1cs) {
        // 0x80135008: nop
    
            goto L_80135014;
    }
    // 0x80135008: nop

    // 0x8013500C: b           L_80135014
    // 0x80135010: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135014;
    // 0x80135010: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135014:
    // 0x80135014: beq         $v1, $zero, L_80135024
    if (ctx->r3 == 0) {
        // 0x80135018: nop
    
            goto L_80135024;
    }
    // 0x80135018: nop

    // 0x8013501C: jr          $ra
    // 0x80135020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135024:
    // 0x80135024: jr          $ra
    // 0x80135028: nop

    return;
    // 0x80135028: nop

;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033510: jr          $ra
    // 0x80033514: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x80033514: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_ovl8_803750CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803750CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803750D0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x803750D4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x803750D8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803750DC: jr          $ra
    // 0x803750E0: sh          $a0, -0x579C($at)
    MEM_H(-0X579C, ctx->r1) = ctx->r4;
    return;
    // 0x803750E0: sh          $a0, -0x579C($at)
    MEM_H(-0X579C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void syDmaReadSram(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002DA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80002DAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80002DB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80002DB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002DB8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80002DBC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002DC0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80002DC4: addiu       $a0, $a0, 0x5048
    ctx->r4 = ADD32(ctx->r4, 0X5048);
    // 0x80002DC8: jal         0x80002A90
    // 0x80002DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    syDmaCopy(rdram, ctx);
        goto after_0;
    // 0x80002DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80002DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002DD8: jr          $ra
    // 0x80002DDC: nop

    return;
    // 0x80002DDC: nop

;}
RECOMP_FUNC void scExplainUpdateTapSparkEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D8E8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D8EC: addiu       $a0, $a0, -0x1610
    ctx->r4 = ADD32(ctx->r4, -0X1610);
    // 0x8018D8F0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8018D8F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D8F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D8FC: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x8018D900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D904: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x8018D908: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x8018D90C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018D910: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8018D914: bne         $t7, $at, L_8018D948
    if (ctx->r15 != ctx->r1) {
        // 0x8018D918: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_8018D948;
    }
    // 0x8018D918: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8018D91C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D924: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D928: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D92C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D930: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D934: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8018D938: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D93C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D940: b           L_8018D970
    // 0x8018D944: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
        goto L_8018D970;
    // 0x8018D944: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
L_8018D948:
    // 0x8018D948: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018D94C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D950: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D954: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D958: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D95C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D960: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8018D964: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D968: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D96C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
L_8018D970:
    // 0x8018D970: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D974: lw          $t8, -0x1620($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1620);
    // 0x8018D978: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8018D97C: addiu       $t9, $t9, 0x5C20
    ctx->r25 = ADD32(ctx->r25, 0X5C20);
    // 0x8018D980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D988: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018D98C: jal         0x8000BED8
    // 0x8018D990: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimAll(rdram, ctx);
        goto after_0;
    // 0x8018D990: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8018D994: jal         0x8000DF34
    // 0x8018D998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8018D998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D99C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8018D9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D9AC: jr          $ra
    // 0x8018D9B0: nop

    return;
    // 0x8018D9B0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingInitSlotAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137C7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80137C80: jal         0x80137BB0
    // 0x80137C84: lw          $a0, -0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X776C);
    mnPlayers1PTrainingInitSlot(rdram, ctx);
        goto after_0;
    // 0x80137C84: lw          $a0, -0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X776C);
    after_0:
    // 0x80137C88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80137C8C: jal         0x80137BB0
    // 0x80137C90: lw          $a0, -0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7768);
    mnPlayers1PTrainingInitSlot(rdram, ctx);
        goto after_1;
    // 0x80137C90: lw          $a0, -0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7768);
    after_1:
    // 0x80137C94: jal         0x80133CA8
    // 0x80137C98: nop

    mnPlayers1PTrainingSetGateLUTAll(rdram, ctx);
        goto after_2;
    // 0x80137C98: nop

    after_2:
    // 0x80137C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137CA4: jr          $ra
    // 0x80137CA8: nop

    return;
    // 0x80137CA8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetPuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134F6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134F70: lw          $t6, 0x764C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X764C);
    // 0x80134F74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134F7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80134F80: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80134F84: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134F88: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134F90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80134F94: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80134F98: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80134F9C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80134FA0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80134FA4: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x80134FA8: bne         $at, $zero, L_80134FC4
    if (ctx->r1 != 0) {
        // 0x80134FAC: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80134FC4;
    }
    // 0x80134FAC: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80134FB0: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80134FB4: beq         $at, $zero, L_80134FC4
    if (ctx->r1 == 0) {
        // 0x80134FB8: nop
    
            goto L_80134FC4;
    }
    // 0x80134FB8: nop

    // 0x80134FBC: b           L_80134FC4
    // 0x80134FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134FC4;
    // 0x80134FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134FC4:
    // 0x80134FC4: beq         $v0, $zero, L_80135038
    if (ctx->r2 == 0) {
        // 0x80134FC8: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80135038;
    }
    // 0x80134FC8: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80134FCC: bne         $at, $zero, L_80134FE8
    if (ctx->r1 != 0) {
        // 0x80134FD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134FE8;
    }
    // 0x80134FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134FD4: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80134FD8: beq         $at, $zero, L_80134FE8
    if (ctx->r1 == 0) {
        // 0x80134FDC: nop
    
            goto L_80134FE8;
    }
    // 0x80134FDC: nop

    // 0x80134FE0: b           L_80134FE8
    // 0x80134FE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134FE8;
    // 0x80134FE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134FE8:
    // 0x80134FE8: beq         $v0, $zero, L_80135038
    if (ctx->r2 == 0) {
        // 0x80134FEC: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80135038;
    }
    // 0x80134FEC: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80134FF0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80134FF4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134FF8: mflo        $a0
    ctx->r4 = lo;
    // 0x80134FFC: jal         0x80132390
    // 0x80135000: nop

    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80135000: nop

    after_0:
    // 0x80135004: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80135008: jal         0x80132144
    // 0x8013500C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusCheckFighterCrossed(rdram, ctx);
        goto after_1;
    // 0x8013500C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80135010: bne         $v0, $zero, L_80135028
    if (ctx->r2 != 0) {
        // 0x80135014: nop
    
            goto L_80135028;
    }
    // 0x80135014: nop

    // 0x80135018: jal         0x801322BC
    // 0x8013501C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_2;
    // 0x8013501C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80135020: beq         $v0, $zero, L_80135030
    if (ctx->r2 == 0) {
        // 0x80135024: nop
    
            goto L_80135030;
    }
    // 0x80135024: nop

L_80135028:
    // 0x80135028: b           L_801350D4
    // 0x8013502C: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801350D4;
    // 0x8013502C: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80135030:
    // 0x80135030: b           L_801350D4
    // 0x80135034: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801350D4;
    // 0x80135034: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80135038:
    // 0x80135038: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x8013503C: bne         $at, $zero, L_80135058
    if (ctx->r1 != 0) {
        // 0x80135040: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135058;
    }
    // 0x80135040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135044: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
    // 0x80135048: beq         $at, $zero, L_80135058
    if (ctx->r1 == 0) {
        // 0x8013504C: nop
    
            goto L_80135058;
    }
    // 0x8013504C: nop

    // 0x80135050: b           L_80135058
    // 0x80135054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135058;
    // 0x80135054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135058:
    // 0x80135058: beq         $v0, $zero, L_801350D0
    if (ctx->r2 == 0) {
        // 0x8013505C: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_801350D0;
    }
    // 0x8013505C: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80135060: bne         $at, $zero, L_8013507C
    if (ctx->r1 != 0) {
        // 0x80135064: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013507C;
    }
    // 0x80135064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135068: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x8013506C: beq         $at, $zero, L_8013507C
    if (ctx->r1 == 0) {
        // 0x80135070: nop
    
            goto L_8013507C;
    }
    // 0x80135070: nop

    // 0x80135074: b           L_8013507C
    // 0x80135078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013507C;
    // 0x80135078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013507C:
    // 0x8013507C: beq         $v0, $zero, L_801350D0
    if (ctx->r2 == 0) {
        // 0x80135080: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_801350D0;
    }
    // 0x80135080: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80135084: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80135088: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8013508C: mflo        $a0
    ctx->r4 = lo;
    // 0x80135090: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80135094: jal         0x80132390
    // 0x80135098: nop

    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80135098: nop

    after_3:
    // 0x8013509C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801350A0: jal         0x80132144
    // 0x801350A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusCheckFighterCrossed(rdram, ctx);
        goto after_4;
    // 0x801350A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x801350A8: bne         $v0, $zero, L_801350C0
    if (ctx->r2 != 0) {
        // 0x801350AC: nop
    
            goto L_801350C0;
    }
    // 0x801350AC: nop

    // 0x801350B0: jal         0x801322BC
    // 0x801350B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_5;
    // 0x801350B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x801350B8: beq         $v0, $zero, L_801350C8
    if (ctx->r2 == 0) {
        // 0x801350BC: nop
    
            goto L_801350C8;
    }
    // 0x801350BC: nop

L_801350C0:
    // 0x801350C0: b           L_801350D4
    // 0x801350C4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801350D4;
    // 0x801350C4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801350C8:
    // 0x801350C8: b           L_801350D4
    // 0x801350CC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801350D4;
    // 0x801350CC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_801350D0:
    // 0x801350D0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801350D4:
    // 0x801350D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801350D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801350DC: jr          $ra
    // 0x801350E0: nop

    return;
    // 0x801350E0: nop

;}
RECOMP_FUNC void itEggHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181780: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181784: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80181788: jal         0x80172EC8
    // 0x8018178C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8018178C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80181790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181798: jr          $ra
    // 0x8018179C: nop

    return;
    // 0x8018179C: nop

;}
RECOMP_FUNC void func_ovl8_80374F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374F20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80374F24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80374F28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80374F2C: jal         0x8037C0CC
    // 0x80374F30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_ovl8_8037C0CC(rdram, ctx);
        goto after_0;
    // 0x80374F30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80374F34: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80374F38: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80374F3C: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80374F40: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x80374F44: lhu         $t8, 0x22($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X22);
    // 0x80374F48: lwl         $t1, 0x2($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r2, 0X2);
    // 0x80374F4C: lwr         $t1, 0x5($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r2, 0X5);
    // 0x80374F50: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80374F54: lhu         $t9, 0x26($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X26);
    // 0x80374F58: swl         $t1, 0x5C($v0)
    do_swl(rdram, 0X5C, ctx->r2, ctx->r9);
    // 0x80374F5C: swr         $t1, 0x5F($v0)
    do_swr(rdram, 0X5F, ctx->r2, ctx->r9);
    // 0x80374F60: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x80374F64: lwl         $t0, 0x6($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r2, 0X6);
    // 0x80374F68: lwr         $t0, 0x9($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r2, 0X9);
    // 0x80374F6C: swl         $t0, 0x60($v0)
    do_swl(rdram, 0X60, ctx->r2, ctx->r8);
    // 0x80374F70: swr         $t0, 0x63($v0)
    do_swr(rdram, 0X63, ctx->r2, ctx->r8);
    // 0x80374F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374F7C: jr          $ra
    // 0x80374F80: nop

    return;
    // 0x80374F80: nop

;}
RECOMP_FUNC void mvOpeningNewcomersFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132490: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132494: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132498: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013249C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801324A0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801324A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801324A8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801324AC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801324B0: addiu       $t8, $t8, 0x2758
    ctx->r24 = ADD32(ctx->r24, 0X2758);
    // 0x801324B4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x801324B8: addiu       $t0, $t0, 0x28D8
    ctx->r8 = ADD32(ctx->r8, 0X28D8);
    // 0x801324BC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801324C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801324C4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801324C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801324CC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801324D0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801324D4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801324D8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801324DC: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x801324E0: jal         0x800CDF78
    // 0x801324E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801324E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x801324E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801324EC: addiu       $a0, $a0, 0x2640
    ctx->r4 = ADD32(ctx->r4, 0X2640);
    // 0x801324F0: jal         0x800CDEEC
    // 0x801324F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801324F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x801324F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801324FC: jal         0x80004980
    // 0x80132500: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132500: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132504: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132508: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013250C: addiu       $a2, $a2, 0x2910
    ctx->r6 = ADD32(ctx->r6, 0X2910);
    // 0x80132510: addiu       $a0, $a0, 0x2640
    ctx->r4 = ADD32(ctx->r4, 0X2640);
    // 0x80132514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132518: jal         0x800CDE04
    // 0x8013251C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8013251C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132520: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132524: addiu       $a1, $a1, 0x23A4
    ctx->r5 = ADD32(ctx->r5, 0X23A4);
    // 0x80132528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013252C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132530: jal         0x80009968
    // 0x80132534: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132534: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132538: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8013253C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132544: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132548: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013254C: jal         0x8000B9FC
    // 0x80132550: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132550: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80132554: jal         0x80132388
    // 0x80132558: nop

    mvOpeningNewcomersInitVars(rdram, ctx);
        goto after_6;
    // 0x80132558: nop

    after_6:
    // 0x8013255C: jal         0x801321B8
    // 0x80132560: nop

    mvOpeningNewcomersMakeNewcomersCamera(rdram, ctx);
        goto after_7;
    // 0x80132560: nop

    after_7:
    // 0x80132564: jal         0x801322E8
    // 0x80132568: nop

    mvOpeningNewcomersMakeHideCamera(rdram, ctx);
        goto after_8;
    // 0x80132568: nop

    after_8:
    // 0x8013256C: jal         0x80131FF8
    // 0x80132570: nop

    mvOpeningNewcomersMakeAll(rdram, ctx);
        goto after_9;
    // 0x80132570: nop

    after_9:
    // 0x80132574: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80132578: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8013257C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80132580: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132584: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80132588: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8013258C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132590: jal         0x803904E0
    // 0x80132594: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_10;
    // 0x80132594: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_10:
    // 0x80132598: jal         0x800269C0
    // 0x8013259C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800269C0_275C0(rdram, ctx);
        goto after_11;
    // 0x8013259C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_11:
    // 0x801325A0: jal         0x800269C0
    // 0x801325A4: addiu       $a0, $zero, 0x1CF
    ctx->r4 = ADD32(0, 0X1CF);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x801325A4: addiu       $a0, $zero, 0x1CF
    ctx->r4 = ADD32(0, 0X1CF);
    after_12:
    // 0x801325A8: jal         0x8000092C
    // 0x801325AC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_13;
    // 0x801325AC: nop

    after_13:
    // 0x801325B0: sltiu       $at, $v0, 0x103B
    ctx->r1 = ctx->r2 < 0X103B ? 1 : 0;
    // 0x801325B4: beql        $at, $zero, L_801325D4
    if (ctx->r1 == 0) {
        // 0x801325B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801325D4;
    }
    goto skip_0;
    // 0x801325B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_801325BC:
    // 0x801325BC: jal         0x8000092C
    // 0x801325C0: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_14;
    // 0x801325C0: nop

    after_14:
    // 0x801325C4: sltiu       $at, $v0, 0x103B
    ctx->r1 = ctx->r2 < 0X103B ? 1 : 0;
    // 0x801325C8: bne         $at, $zero, L_801325BC
    if (ctx->r1 != 0) {
        // 0x801325CC: nop
    
            goto L_801325BC;
    }
    // 0x801325CC: nop

    // 0x801325D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801325D4:
    // 0x801325D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801325D8: jr          $ra
    // 0x801325DC: nop

    return;
    // 0x801325DC: nop

;}
RECOMP_FUNC void ifCommonBattleSetInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114B84: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80114B88: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80114B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114B90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80114B94: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80114B98: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80114B9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114BA0: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80114BA4: sh          $a3, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r7;
    // 0x80114BA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114BAC: sw          $a0, 0x182C($at)
    MEM_W(0X182C, ctx->r1) = ctx->r4;
    // 0x80114BB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114BB4: jal         0x80113790
    // 0x80114BB8: sw          $a1, 0x1830($at)
    MEM_W(0X1830, ctx->r1) = ctx->r5;
    ifCommonBattleEndInitSoundNum(rdram, ctx);
        goto after_0;
    // 0x80114BB8: sw          $a1, 0x1830($at)
    MEM_W(0X1830, ctx->r1) = ctx->r5;
    after_0:
    // 0x80114BBC: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x80114BC0: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x80114BC4: beql        $a0, $at, L_80114BD8
    if (ctx->r4 == ctx->r1) {
        // 0x80114BC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80114BD8;
    }
    goto skip_0;
    // 0x80114BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80114BCC: jal         0x80113804
    // 0x80114BD0: nop

    ifCommonBattleEndAddSoundQueueID(rdram, ctx);
        goto after_1;
    // 0x80114BD0: nop

    after_1:
    // 0x80114BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114BD8:
    // 0x80114BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114BDC: jr          $ra
    // 0x80114BE0: nop

    return;
    // 0x80114BE0: nop

;}
RECOMP_FUNC void func_ovl8_80373C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373C10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373C14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80373C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80373C1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373C20: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373C24: bne         $a0, $zero, L_80373C3C
    if (ctx->r4 != 0) {
        // 0x80373C28: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80373C3C;
    }
    // 0x80373C28: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80373C2C: jal         0x803717A0
    // 0x80373C30: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80373C30: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80373C34: beq         $v0, $zero, L_80373CB0
    if (ctx->r2 == 0) {
        // 0x80373C38: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373CB0;
    }
    // 0x80373C38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80373C3C:
    // 0x80373C3C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80373C40: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80373C44: addiu       $a1, $s0, 0x9C
    ctx->r5 = ADD32(ctx->r16, 0X9C);
    // 0x80373C48: bnel        $t6, $zero, L_80373C6C
    if (ctx->r14 != 0) {
        // 0x80373C4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80373C6C;
    }
    goto skip_0;
    // 0x80373C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80373C50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80373C54: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80373C58: jal         0x803717E0
    // 0x80373C5C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80373C5C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80373C60: jal         0x8037C2D0
    // 0x80373C64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80373C64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80373C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80373C6C:
    // 0x80373C6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80373C70: jal         0x803733AC
    // 0x80373C74: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803733AC(rdram, ctx);
        goto after_3;
    // 0x80373C74: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80373C78: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80373C7C: addiu       $t7, $t7, -0x6D10
    ctx->r15 = ADD32(ctx->r15, -0X6D10);
    // 0x80373C80: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80373C84: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80373C88: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80373C8C: addiu       $t8, $t8, -0x6C38
    ctx->r24 = ADD32(ctx->r24, -0X6C38);
    // 0x80373C90: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80373C94: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80373C98: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80373C9C: addiu       $t0, $t0, -0x6AE0
    ctx->r8 = ADD32(ctx->r8, -0X6AE0);
    // 0x80373CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80373CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373CA8: jal         0x803743CC
    // 0x80373CAC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    func_ovl8_803743CC(rdram, ctx);
        goto after_4;
    // 0x80373CAC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    after_4:
L_80373CB0:
    // 0x80373CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80373CB4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80373CB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373CBC: jr          $ra
    // 0x80373CC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80373CC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftKirbyCopyNessSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155CD8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155CDC: jal         0x800DE6E4
    // 0x80155CE0: addiu       $a1, $a1, 0x5CF4
    ctx->r5 = ADD32(ctx->r5, 0X5CF4);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80155CE0: addiu       $a1, $a1, 0x5CF4
    ctx->r5 = ADD32(ctx->r5, 0X5CF4);
    after_0:
    // 0x80155CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155CEC: jr          $ra
    // 0x80155CF0: nop

    return;
    // 0x80155CF0: nop

;}
RECOMP_FUNC void syAudioSetSettingsUpdated(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002102C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021030: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021034: jr          $ra
    // 0x80021038: sw          $t6, -0x34E4($at)
    MEM_W(-0X34E4, ctx->r1) = ctx->r14;
    return;
    // 0x80021038: sw          $t6, -0x34E4($at)
    MEM_W(-0X34E4, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80026B40_27740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B40: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80026B44: addiu       $v0, $v0, -0x1230
    ctx->r2 = ADD32(ctx->r2, -0X1230);
    // 0x80026B48: lhu         $t6, 0x2A($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2A);
    // 0x80026B4C: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80026B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026B54: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026B5C: bne         $at, $zero, L_80026B6C
    if (ctx->r1 != 0) {
        // 0x80026B60: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80026B6C;
    }
    // 0x80026B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80026B64: b           L_80026B80
    // 0x80026B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80026B80;
    // 0x80026B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026B6C:
    // 0x80026B6C: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80026B70: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80026B74: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80026B78: jal         0x80026A6C
    // 0x80026B7C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_80026A6C_2766C(rdram, ctx);
        goto after_0;
    // 0x80026B7C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
L_80026B80:
    // 0x80026B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026B88: jr          $ra
    // 0x80026B8C: nop

    return;
    // 0x80026B8C: nop

;}
RECOMP_FUNC void mnCharactersCheckRecentMotionKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801327C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801327C8: addiu       $v0, $v0, 0x6714
    ctx->r2 = ADD32(ctx->r2, 0X6714);
    // 0x801327CC: addiu       $v1, $v1, 0x6708
    ctx->r3 = ADD32(ctx->r3, 0X6708);
    // 0x801327D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_801327D4:
    // 0x801327D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801327D8: bne         $a0, $t6, L_801327E8
    if (ctx->r4 != ctx->r14) {
        // 0x801327DC: nop
    
            goto L_801327E8;
    }
    // 0x801327DC: nop

    // 0x801327E0: jr          $ra
    // 0x801327E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801327E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801327E8:
    // 0x801327E8: bnel        $v1, $v0, L_801327D4
    if (ctx->r3 != ctx->r2) {
        // 0x801327EC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_801327D4;
    }
    goto skip_0;
    // 0x801327EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x801327F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801327F4: jr          $ra
    // 0x801327F8: nop

    return;
    // 0x801327F8: nop

;}
RECOMP_FUNC void scAutoDemoCheckStopFocusPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D1EC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8018D1F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D1F4: beq         $v0, $zero, L_8018D20C
    if (ctx->r2 == 0) {
        // 0x8018D1F8: nop
    
            goto L_8018D20C;
    }
    // 0x8018D1F8: nop

    // 0x8018D1FC: beq         $v0, $at, L_8018D20C
    if (ctx->r2 == ctx->r1) {
        // 0x8018D200: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018D20C;
    }
    // 0x8018D200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018D204: bnel        $v0, $at, L_8018D218
    if (ctx->r2 != ctx->r1) {
        // 0x8018D208: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018D218;
    }
    goto skip_0;
    // 0x8018D208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8018D20C:
    // 0x8018D20C: jr          $ra
    // 0x8018D210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8018D210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018D214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018D218:
    // 0x8018D218: jr          $ra
    // 0x8018D21C: nop

    return;
    // 0x8018D21C: nop

;}
RECOMP_FUNC void func_ovl8_80373828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373828: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037382C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80373830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80373834: jr          $ra
    // 0x80373838: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80373838: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void mnSoundTestOptionThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132454: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132458: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8013245C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80132460: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132464: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132468: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013246C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132470: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132474: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80132478: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013247C: addiu       $t8, $t8, 0x4330
    ctx->r24 = ADD32(ctx->r24, 0X4330);
    // 0x80132480: addiu       $t7, $t7, 0x4320
    ctx->r15 = ADD32(ctx->r15, 0X4320);
    // 0x80132484: addiu       $t6, $t6, 0x4310
    ctx->r14 = ADD32(ctx->r14, 0X4310);
    // 0x80132488: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8013248C: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
    // 0x80132490: addu        $s2, $v0, $t7
    ctx->r18 = ADD32(ctx->r2, ctx->r15);
    // 0x80132494: addu        $s3, $v0, $t8
    ctx->r19 = ADD32(ctx->r2, ctx->r24);
    // 0x80132498: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
L_8013249C:
    // 0x8013249C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x801324A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801324A4: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x801324A8: sb          $v0, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r2;
    // 0x801324AC: lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X3);
    // 0x801324B0: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x801324B4: sb          $v0, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r2;
    // 0x801324B8: sb          $v0, 0x29($t0)
    MEM_B(0X29, ctx->r8) = ctx->r2;
    // 0x801324BC: lbu         $v0, 0x3($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X3);
    // 0x801324C0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801324C4: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x801324C8: jal         0x8000B1E8
    // 0x801324CC: sb          $v0, 0x2A($t1)
    MEM_B(0X2A, ctx->r9) = ctx->r2;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x801324CC: sb          $v0, 0x2A($t1)
    MEM_B(0X2A, ctx->r9) = ctx->r2;
    after_0:
    // 0x801324D0: b           L_8013249C
    // 0x801324D4: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
        goto L_8013249C;
    // 0x801324D4: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x801324D8: nop

    // 0x801324DC: nop

    // 0x801324E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801324E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801324E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801324EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801324F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801324F4: jr          $ra
    // 0x801324F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801324F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningYamabukiFuncLights(uint8_t* rdram, recomp_context* ctx) {
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

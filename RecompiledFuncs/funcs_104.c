#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_8037F3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F3A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037F3AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037F3B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F3B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037F3B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8037F3BC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8037F3C0: bne         $a0, $zero, L_8037F3D8
    if (ctx->r4 != 0) {
        // 0x8037F3C4: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_8037F3D8;
    }
    // 0x8037F3C4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8037F3C8: jal         0x803717A0
    // 0x8037F3CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037F3CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x8037F3D0: beq         $v0, $zero, L_8037F4E0
    if (ctx->r2 == 0) {
        // 0x8037F3D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037F4E0;
    }
    // 0x8037F3D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037F3D8:
    // 0x8037F3D8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8037F3DC: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037F3E0: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    // 0x8037F3E4: bnel        $t6, $zero, L_8037F408
    if (ctx->r14 != 0) {
        // 0x8037F3E8: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_8037F408;
    }
    goto skip_0;
    // 0x8037F3E8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8037F3EC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8037F3F0: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8037F3F4: jal         0x803717E0
    // 0x8037F3F8: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037F3F8: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037F3FC: jal         0x8037C2D0
    // 0x8037F400: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037F400: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8037F404: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_8037F408:
    // 0x8037F408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037F40C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037F410: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8037F414: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037F418: jal         0x8037345C
    // 0x8037F41C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037345C(rdram, ctx);
        goto after_3;
    // 0x8037F41C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037F420: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037F424: addiu       $t8, $t8, -0x50C8
    ctx->r24 = ADD32(ctx->r24, -0X50C8);
    // 0x8037F428: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x8037F42C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8037F430: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037F434: addiu       $t9, $t9, -0x4FE8
    ctx->r25 = ADD32(ctx->r25, -0X4FE8);
    // 0x8037F438: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x8037F43C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8037F440: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037F444: addiu       $t1, $t1, -0x4E90
    ctx->r9 = ADD32(ctx->r9, -0X4E90);
    // 0x8037F448: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8037F44C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8037F450: sh          $t3, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r11;
    // 0x8037F454: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8037F458: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037F45C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037F460: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8037F464: lhu         $t6, 0x4($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X4);
    // 0x8037F468: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037F46C: addiu       $t7, $t7, -0x5230
    ctx->r15 = ADD32(ctx->r15, -0X5230);
    // 0x8037F470: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8037F474: beq         $at, $zero, L_8037F484
    if (ctx->r1 == 0) {
        // 0x8037F478: addiu       $t8, $t8, -0x517C
        ctx->r24 = ADD32(ctx->r24, -0X517C);
            goto L_8037F484;
    }
    // 0x8037F478: addiu       $t8, $t8, -0x517C
    ctx->r24 = ADD32(ctx->r24, -0X517C);
    // 0x8037F47C: b           L_8037F488
    // 0x8037F480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037F488;
    // 0x8037F480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037F484:
    // 0x8037F484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037F488:
    // 0x8037F488: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x8037F48C: beq         $v0, $zero, L_8037F4A8
    if (ctx->r2 == 0) {
        // 0x8037F490: swc1        $f4, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
            goto L_8037F4A8;
    }
    // 0x8037F490: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8037F494: beq         $s0, $zero, L_8037F4A0
    if (ctx->r16 == 0) {
        // 0x8037F498: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037F4A0;
    }
    // 0x8037F498: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037F49C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_8037F4A0:
    // 0x8037F4A0: b           L_8037F4B8
    // 0x8037F4A4: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
        goto L_8037F4B8;
    // 0x8037F4A4: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
L_8037F4A8:
    // 0x8037F4A8: beq         $s0, $zero, L_8037F4B4
    if (ctx->r16 == 0) {
        // 0x8037F4AC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037F4B4;
    }
    // 0x8037F4AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037F4B0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_8037F4B4:
    // 0x8037F4B4: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
L_8037F4B8:
    // 0x8037F4B8: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8037F4BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037F4C0: bgez        $v1, L_8037F4D4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8037F4C4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8037F4D4;
    }
    // 0x8037F4C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037F4C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037F4CC: nop

    // 0x8037F4D0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8037F4D4:
    // 0x8037F4D4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8037F4D8: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x8037F4DC: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
L_8037F4E0:
    // 0x8037F4E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037F4E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037F4E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037F4EC: jr          $ra
    // 0x8037F4F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037F4F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80154878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015487C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80154880: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154884: lwc1        $f14, 0x48($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80154888: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8015488C: lwc1        $f12, 0xB2C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB2C);
    // 0x80154890: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80154894: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80154898: jal         0x80035CD0
    // 0x8015489C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8015489C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801548A0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801548A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801548A8: lwc1        $f4, -0x3A1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A1C);
    // 0x801548AC: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x801548B0: lwc1        $f12, 0xB2C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XB2C);
    // 0x801548B4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801548B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801548BC: nop

    // 0x801548C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801548C4: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801548C8: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801548CC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x801548D0: jal         0x800303F0
    // 0x801548D4: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801548D4: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x801548D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801548DC: lwc1        $f8, -0x3A18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A18);
    // 0x801548E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801548E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801548E8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801548EC: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801548F0: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801548F4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801548F8: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801548FC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80154900: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80154904: bc1f        L_80154914
    if (!c1cs) {
        // 0x80154908: swc1        $f6, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
            goto L_80154914;
    }
    // 0x80154908: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x8015490C: b           L_80154918
    // 0x80154910: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
        goto L_80154918;
    // 0x80154910: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
L_80154914:
    // 0x80154914: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80154918:
    // 0x80154918: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x8015491C: nop

    // 0x80154920: bc1fl       L_80154934
    if (!c1cs) {
        // 0x80154924: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_80154934;
    }
    goto skip_0;
    // 0x80154924: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_0:
    // 0x80154928: b           L_80154934
    // 0x8015492C: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
        goto L_80154934;
    // 0x8015492C: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x80154930: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80154934:
    // 0x80154934: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80154938: nop

    // 0x8015493C: bc1fl       L_8015494C
    if (!c1cs) {
        // 0x80154940: lwc1        $f0, 0x4C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
            goto L_8015494C;
    }
    goto skip_1;
    // 0x80154940: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    skip_1:
    // 0x80154944: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
    // 0x80154948: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
L_8015494C:
    // 0x8015494C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80154950: nop

    // 0x80154954: bc1fl       L_80154968
    if (!c1cs) {
        // 0x80154958: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80154968;
    }
    goto skip_2;
    // 0x80154958: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_2:
    // 0x8015495C: b           L_80154968
    // 0x80154960: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_80154968;
    // 0x80154960: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80154964: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80154968:
    // 0x80154968: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8015496C: nop

    // 0x80154970: bc1fl       L_80154984
    if (!c1cs) {
        // 0x80154974: mov.s       $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
            goto L_80154984;
    }
    goto skip_3;
    // 0x80154974: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    skip_3:
    // 0x80154978: b           L_80154984
    // 0x8015497C: neg.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = -ctx->f16.fl;
        goto L_80154984;
    // 0x8015497C: neg.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = -ctx->f16.fl;
    // 0x80154980: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_80154984:
    // 0x80154984: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80154988: nop

    // 0x8015498C: bc1f        L_80154998
    if (!c1cs) {
        // 0x80154990: nop
    
            goto L_80154998;
    }
    // 0x80154990: nop

    // 0x80154994: swc1        $f16, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f16.u32l;
L_80154998:
    // 0x80154998: jal         0x80154758
    // 0x8015499C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftNessSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_2;
    // 0x8015499C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801549A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801549A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801549A8: jr          $ra
    // 0x801549AC: nop

    return;
    // 0x801549AC: nop

;}
RECOMP_FUNC void ftKirbySpecialLwHoldProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016178C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80161790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161794: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80161798: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016179C: lw          $t7, 0x9C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C8);
    // 0x801617A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x801617A4: jal         0x80161478
    // 0x801617A8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    ftKirbySpecialLwGetGroundAxisYaw(rdram, ctx);
        goto after_0;
    // 0x801617A8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x801617AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801617B0: lwc1        $f2, -0x3630($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3630);
    // 0x801617B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801617B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801617BC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801617C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801617C4: bc1f        L_801617D4
    if (!c1cs) {
        // 0x801617C8: nop
    
            goto L_801617D4;
    }
    // 0x801617C8: nop

    // 0x801617CC: b           L_801617EC
    // 0x801617D0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_801617EC;
    // 0x801617D0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_801617D4:
    // 0x801617D4: lwc1        $f2, -0x362C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X362C);
    // 0x801617D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801617DC: nop

    // 0x801617E0: bc1f        L_801617EC
    if (!c1cs) {
        // 0x801617E4: nop
    
            goto L_801617EC;
    }
    // 0x801617E4: nop

    // 0x801617E8: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_801617EC:
    // 0x801617EC: jal         0x800303F0
    // 0x801617F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801617F0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x801617F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801617F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801617FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80161800: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80161804: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80161808: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016180C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80161810: lwc1        $f18, 0x60($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X60);
    // 0x80161814: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80161818: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8016181C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80161820: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80161824: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80161828: swc1        $f4, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f4.u32l;
    // 0x8016182C: lwc1        $f2, 0x60($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X60);
    // 0x80161830: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80161834: nop

    // 0x80161838: bc1fl       L_8016184C
    if (!c1cs) {
        // 0x8016183C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8016184C;
    }
    goto skip_0;
    // 0x8016183C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80161840: b           L_80161864
    // 0x80161844: swc1        $f12, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f12.u32l;
        goto L_80161864;
    // 0x80161844: swc1        $f12, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f12.u32l;
    // 0x80161848: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8016184C:
    // 0x8016184C: nop

    // 0x80161850: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80161854: nop

    // 0x80161858: bc1fl       L_80161868
    if (!c1cs) {
        // 0x8016185C: lw          $t9, 0xF4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XF4);
            goto L_80161868;
    }
    goto skip_1;
    // 0x8016185C: lw          $t9, 0xF4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XF4);
    skip_1:
    // 0x80161860: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
L_80161864:
    // 0x80161864: lw          $t9, 0xF4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XF4);
L_80161868:
    // 0x80161868: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8016186C: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x80161870: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80161874: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80161878: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8016187C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80161880: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80161884: lwc1        $f8, -0x3B20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B20);
    // 0x80161888: lwc1        $f6, 0x24($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X24);
    // 0x8016188C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80161890: lwc1        $f18, -0x3628($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3628);
    // 0x80161894: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80161898: nop

    // 0x8016189C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801618A0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801618A4: jal         0x800D8978
    // 0x801618A8: nop

    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_2;
    // 0x801618A8: nop

    after_2:
    // 0x801618AC: jal         0x800D87D0
    // 0x801618B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_3;
    // 0x801618B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801618B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801618B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801618BC: jr          $ra
    // 0x801618C0: nop

    return;
    // 0x801618C0: nop

;}
RECOMP_FUNC void sySchedulerRemovePausedQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000DD4: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80000DD8: beql        $v0, $zero, L_80000DF0
    if (ctx->r2 == 0) {
        // 0x80000DDC: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_80000DF0;
    }
    goto skip_0;
    // 0x80000DDC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x80000DE0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80000DE4: b           L_80000DF8
    // 0x80000DE8: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
        goto L_80000DF8;
    // 0x80000DE8: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80000DEC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_80000DF0:
    // 0x80000DF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000DF4: sw          $t7, 0x4ED4($at)
    MEM_W(0X4ED4, ctx->r1) = ctx->r15;
L_80000DF8:
    // 0x80000DF8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80000DFC: beql        $v0, $zero, L_80000E14
    if (ctx->r2 == 0) {
        // 0x80000E00: lw          $t9, 0x10($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X10);
            goto L_80000E14;
    }
    goto skip_1;
    // 0x80000E00: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x80000E04: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80000E08: jr          $ra
    // 0x80000E0C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    return;
    // 0x80000E0C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80000E10: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
L_80000E14:
    // 0x80000E14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000E18: sw          $t9, 0x4ED8($at)
    MEM_W(0X4ED8, ctx->r1) = ctx->r25;
    // 0x80000E1C: jr          $ra
    // 0x80000E20: nop

    return;
    // 0x80000E20: nop

;}
RECOMP_FUNC void scSubsysFighterGetLightAngleX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8039051C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80390520: jr          $ra
    // 0x80390524: lwc1        $f0, 0x29D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X29D8);
    return;
    // 0x80390524: lwc1        $f0, 0x29D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X29D8);
;}
RECOMP_FUNC void mvOpeningCliffFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void itProcessSearchHitItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017088C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80170890: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80170894: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80170898: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8017089C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801708A0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801708A4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801708A8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801708AC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801708B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801708B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801708B8: lw          $s4, 0x84($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X84);
    // 0x801708BC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801708C0: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x801708C4: lbu         $t6, 0x244($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X244);
    // 0x801708C8: addiu       $s5, $s4, 0x10C
    ctx->r21 = ADD32(ctx->r20, 0X10C);
    // 0x801708CC: or          $fp, $s5, $zero
    ctx->r30 = ctx->r21 | 0;
    // 0x801708D0: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x801708D4: beql        $t7, $zero, L_80170C58
    if (ctx->r15 == 0) {
        // 0x801708D8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80170C58;
    }
    goto skip_0;
    // 0x801708D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801708DC: lw          $s7, 0x6700($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X6700);
    // 0x801708E0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x801708E4: beql        $s7, $zero, L_80170C58
    if (ctx->r23 == 0) {
        // 0x801708E8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80170C58;
    }
    goto skip_1;
    // 0x801708E8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
L_801708EC:
    // 0x801708EC: bne         $s7, $s6, L_801708FC
    if (ctx->r23 != ctx->r22) {
        // 0x801708F0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801708FC;
    }
    // 0x801708F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801708F4: b           L_80170C48
    // 0x801708F8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
        goto L_80170C48;
    // 0x801708F8: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
L_801708FC:
    // 0x801708FC: lw          $s3, 0x84($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X84);
    // 0x80170900: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80170904: addiu       $s2, $s3, 0x10C
    ctx->r18 = ADD32(ctx->r19, 0X10C);
    // 0x80170908: sw          $s2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r18;
    // 0x8017090C: lw          $t0, 0x8($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X8);
    // 0x80170910: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80170914: bne         $t9, $t0, L_80170928
    if (ctx->r25 != ctx->r8) {
        // 0x80170918: nop
    
            goto L_80170928;
    }
    // 0x80170918: nop

    // 0x8017091C: lb          $t2, 0x2CF($s4)
    ctx->r10 = MEM_B(ctx->r20, 0X2CF);
    // 0x80170920: bgezl       $t2, L_80170C4C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80170924: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80170C4C;
    }
    goto skip_2;
    // 0x80170924: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_2:
L_80170928:
    // 0x80170928: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x8017092C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170930: lbu         $t3, 0x2($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2);
    // 0x80170934: bnel        $t3, $at, L_80170968
    if (ctx->r11 != ctx->r1) {
        // 0x80170938: lw          $t9, 0x0($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X0);
            goto L_80170968;
    }
    goto skip_3;
    // 0x80170938: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x8017093C: lbu         $t4, 0x9($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X9);
    // 0x80170940: bnel        $t4, $zero, L_80170968
    if (ctx->r12 != 0) {
        // 0x80170944: lw          $t9, 0x0($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X0);
            goto L_80170968;
    }
    goto skip_4;
    // 0x80170944: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x80170948: lbu         $t5, 0x14($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X14);
    // 0x8017094C: lbu         $t6, 0x14($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X14);
    // 0x80170950: bnel        $t5, $t6, L_80170968
    if (ctx->r13 != ctx->r14) {
        // 0x80170954: lw          $t9, 0x0($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X0);
            goto L_80170968;
    }
    goto skip_5;
    // 0x80170954: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x80170958: lb          $t8, 0x2CF($s4)
    ctx->r24 = MEM_B(ctx->r20, 0X2CF);
    // 0x8017095C: bgezl       $t8, L_80170C4C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80170960: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80170C4C;
    }
    goto skip_6;
    // 0x80170960: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_6:
    // 0x80170964: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
L_80170968:
    // 0x80170968: beql        $t9, $zero, L_80170C4C
    if (ctx->r25 == 0) {
        // 0x8017096C: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80170C4C;
    }
    goto skip_7;
    // 0x8017096C: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_7:
    // 0x80170970: lbu         $t0, 0x48($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X48);
    // 0x80170974: lbu         $t2, 0x7C($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X7C);
    // 0x80170978: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8017097C: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80170980: beq         $t1, $zero, L_80170C48
    if (ctx->r9 == 0) {
        // 0x80170984: andi        $t9, $t2, 0xFFBF
        ctx->r25 = ctx->r10 & 0XFFBF;
            goto L_80170C48;
    }
    // 0x80170984: andi        $t9, $t2, 0xFFBF
    ctx->r25 = ctx->r10 & 0XFFBF;
    // 0x80170988: sb          $t9, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r25;
    // 0x8017098C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80170990: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80170994: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80170998: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8017099C: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x801709A0: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x801709A4: or          $t4, $t8, $t0
    ctx->r12 = ctx->r24 | ctx->r8;
    // 0x801709A8: sb          $t4, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r12;
    // 0x801709AC: ori         $t5, $t4, 0xE
    ctx->r13 = ctx->r12 | 0XE;
    // 0x801709B0: sb          $t5, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r13;
L_801709B4:
    // 0x801709B4: lw          $t6, 0x118($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X118);
    // 0x801709B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801709BC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x801709C0: bne         $s6, $t6, L_801709D8
    if (ctx->r22 != ctx->r14) {
        // 0x801709C4: nop
    
            goto L_801709D8;
    }
    // 0x801709C4: nop

    // 0x801709C8: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x801709CC: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x801709D0: b           L_801709E0
    // 0x801709D4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
        goto L_801709E0;
    // 0x801709D4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_801709D8:
    // 0x801709D8: bne         $v1, $at, L_801709B4
    if (ctx->r3 != ctx->r1) {
        // 0x801709DC: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_801709B4;
    }
    // 0x801709DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_801709E0:
    // 0x801709E0: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x801709E4: srl         $t0, $t8, 31
    ctx->r8 = S32(U32(ctx->r24) >> 31);
    // 0x801709E8: bne         $t0, $zero, L_80170C48
    if (ctx->r8 != 0) {
        // 0x801709EC: sll         $t2, $t8, 1
        ctx->r10 = S32(ctx->r24 << 1);
            goto L_80170C48;
    }
    // 0x801709EC: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x801709F0: bltz        $t2, L_80170C48
    if (SIGNED(ctx->r10) < 0) {
        // 0x801709F4: sll         $t4, $t8, 4
        ctx->r12 = S32(ctx->r24 << 4);
            goto L_80170C48;
    }
    // 0x801709F4: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x801709F8: srl         $t5, $t4, 29
    ctx->r13 = S32(U32(ctx->r12) >> 29);
    // 0x801709FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80170A00: bne         $t5, $at, L_80170C48
    if (ctx->r13 != ctx->r1) {
        // 0x80170A04: lw          $t6, 0x68($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X68);
            goto L_80170C48;
    }
    // 0x80170A04: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80170A08: beq         $t6, $zero, L_80170BC0
    if (ctx->r14 == 0) {
        // 0x80170A0C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80170BC0;
    }
    // 0x80170A0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80170A10: lw          $t7, 0x4C($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4C);
    // 0x80170A14: srl         $t3, $t7, 31
    ctx->r11 = S32(U32(ctx->r15) >> 31);
    // 0x80170A18: beql        $t3, $zero, L_80170BC4
    if (ctx->r11 == 0) {
        // 0x80170A1C: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_8;
    // 0x80170A1C: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_8:
    // 0x80170A20: lw          $t9, 0x4C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4C);
    // 0x80170A24: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80170A28: beql        $t0, $zero, L_80170BC4
    if (ctx->r8 == 0) {
        // 0x80170A2C: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_9;
    // 0x80170A2C: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_9:
    // 0x80170A30: lw          $t1, 0x8($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X8);
    // 0x80170A34: lw          $t2, 0x8($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X8);
    // 0x80170A38: beql        $t1, $t2, L_80170BC4
    if (ctx->r9 == ctx->r10) {
        // 0x80170A3C: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_10;
    // 0x80170A3C: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_10:
    // 0x80170A40: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x80170A44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170A48: bnel        $t8, $at, L_80170A70
    if (ctx->r24 != ctx->r1) {
        // 0x80170A4C: lw          $t7, 0x0($s5)
        ctx->r15 = MEM_W(ctx->r21, 0X0);
            goto L_80170A70;
    }
    goto skip_11;
    // 0x80170A4C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    skip_11:
    // 0x80170A50: lbu         $t4, 0x9($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X9);
    // 0x80170A54: bnel        $t4, $zero, L_80170A70
    if (ctx->r12 != 0) {
        // 0x80170A58: lw          $t7, 0x0($s5)
        ctx->r15 = MEM_W(ctx->r21, 0X0);
            goto L_80170A70;
    }
    goto skip_12;
    // 0x80170A58: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    skip_12:
    // 0x80170A5C: lbu         $t5, 0x14($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X14);
    // 0x80170A60: lbu         $t6, 0x14($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X14);
    // 0x80170A64: beql        $t5, $t6, L_80170BC4
    if (ctx->r13 == ctx->r14) {
        // 0x80170A68: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_13;
    // 0x80170A68: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_13:
    // 0x80170A6C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
L_80170A70:
    // 0x80170A70: beql        $t7, $zero, L_80170BC4
    if (ctx->r15 == 0) {
        // 0x80170A74: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_14;
    // 0x80170A74: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_14:
    // 0x80170A78: lbu         $t3, 0x48($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X48);
    // 0x80170A7C: lbu         $t0, 0x80($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X80);
    // 0x80170A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80170A84: andi        $t9, $t3, 0x4
    ctx->r25 = ctx->r11 & 0X4;
    // 0x80170A88: beq         $t9, $zero, L_80170BC0
    if (ctx->r25 == 0) {
        // 0x80170A8C: andi        $t7, $t0, 0xFFBF
        ctx->r15 = ctx->r8 & 0XFFBF;
            goto L_80170BC0;
    }
    // 0x80170A8C: andi        $t7, $t0, 0xFFBF
    ctx->r15 = ctx->r8 & 0XFFBF;
    // 0x80170A90: sb          $t7, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r15;
    // 0x80170A94: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80170A98: andi        $t3, $t7, 0x7F
    ctx->r11 = ctx->r15 & 0X7F;
    // 0x80170A9C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80170AA0: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x80170AA4: srl         $t4, $t8, 31
    ctx->r12 = S32(U32(ctx->r24) >> 31);
    // 0x80170AA8: sll         $t6, $t4, 7
    ctx->r14 = S32(ctx->r12 << 7);
    // 0x80170AAC: or          $t2, $t6, $t3
    ctx->r10 = ctx->r14 | ctx->r11;
    // 0x80170AB0: sb          $t2, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r10;
    // 0x80170AB4: ori         $t8, $t2, 0xE
    ctx->r24 = ctx->r10 | 0XE;
    // 0x80170AB8: sb          $t8, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r24;
L_80170ABC:
    // 0x80170ABC: lw          $t4, 0x118($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X118);
    // 0x80170AC0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80170AC4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80170AC8: bne         $s7, $t4, L_80170AE0
    if (ctx->r23 != ctx->r12) {
        // 0x80170ACC: nop
    
            goto L_80170AE0;
    }
    // 0x80170ACC: nop

    // 0x80170AD0: lw          $t7, 0x11C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X11C);
    // 0x80170AD4: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x80170AD8: b           L_80170AE8
    // 0x80170ADC: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
        goto L_80170AE8;
    // 0x80170ADC: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
L_80170AE0:
    // 0x80170AE0: bne         $v1, $at, L_80170ABC
    if (ctx->r3 != ctx->r1) {
        // 0x80170AE4: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80170ABC;
    }
    // 0x80170AE4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80170AE8:
    // 0x80170AE8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80170AEC: srl         $t3, $t6, 31
    ctx->r11 = S32(U32(ctx->r14) >> 31);
    // 0x80170AF0: bne         $t3, $zero, L_80170B10
    if (ctx->r11 != 0) {
        // 0x80170AF4: sll         $t0, $t6, 1
        ctx->r8 = S32(ctx->r14 << 1);
            goto L_80170B10;
    }
    // 0x80170AF4: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x80170AF8: bltz        $t0, L_80170B10
    if (SIGNED(ctx->r8) < 0) {
        // 0x80170AFC: sll         $t2, $t6, 4
        ctx->r10 = S32(ctx->r14 << 4);
            goto L_80170B10;
    }
    // 0x80170AFC: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x80170B00: srl         $t8, $t2, 29
    ctx->r24 = S32(U32(ctx->r10) >> 29);
    // 0x80170B04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80170B08: beql        $t8, $at, L_80170B1C
    if (ctx->r24 == ctx->r1) {
        // 0x80170B0C: lw          $t4, 0x54($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X54);
            goto L_80170B1C;
    }
    goto skip_15;
    // 0x80170B0C: lw          $t4, 0x54($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X54);
    skip_15:
L_80170B10:
    // 0x80170B10: b           L_80170BC4
    // 0x80170B14: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
        goto L_80170BC4;
    // 0x80170B14: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    // 0x80170B18: lw          $t4, 0x54($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X54);
L_80170B1C:
    // 0x80170B1C: blezl       $t4, L_80170BC4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80170B20: lw          $v0, 0x54($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X54);
            goto L_80170BC4;
    }
    goto skip_16;
    // 0x80170B20: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
    skip_16:
    // 0x80170B24: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
L_80170B28:
    // 0x80170B28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80170B2C: blez        $t5, L_80170BA4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80170B30: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80170BA4;
    }
    // 0x80170B30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80170B34:
    // 0x80170B34: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80170B38: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80170B3C: jal         0x800F05C8
    // 0x80170B40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gmCollisionCheckItemAttacksCollide(rdram, ctx);
        goto after_0;
    // 0x80170B40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80170B44: beq         $v0, $zero, L_80170B90
    if (ctx->r2 == 0) {
        // 0x80170B48: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80170B90;
    }
    // 0x80170B48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80170B4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80170B50: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80170B54: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80170B58: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80170B5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80170B60: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80170B64: jal         0x8016FD4C
    // 0x80170B68: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    itProcessUpdateAttackStatItem(rdram, ctx);
        goto after_1;
    // 0x80170B68: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    after_1:
    // 0x80170B6C: lw          $t1, 0x270($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X270);
    // 0x80170B70: bnel        $t1, $zero, L_80170C4C
    if (ctx->r9 != 0) {
        // 0x80170B74: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80170C4C;
    }
    goto skip_17;
    // 0x80170B74: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_17:
    // 0x80170B78: lw          $t7, 0x270($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X270);
    // 0x80170B7C: beql        $t7, $zero, L_80170B94
    if (ctx->r15 == 0) {
        // 0x80170B80: lw          $t3, 0x54($fp)
        ctx->r11 = MEM_W(ctx->r30, 0X54);
            goto L_80170B94;
    }
    goto skip_18;
    // 0x80170B80: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    skip_18:
    // 0x80170B84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80170B88: b           L_80170BC4
    // 0x80170B8C: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
        goto L_80170BC4;
    // 0x80170B8C: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
L_80170B90:
    // 0x80170B90: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
L_80170B94:
    // 0x80170B94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80170B98: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80170B9C: bnel        $at, $zero, L_80170B34
    if (ctx->r1 != 0) {
        // 0x80170BA0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80170B34;
    }
    goto skip_19;
    // 0x80170BA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_19:
L_80170BA4:
    // 0x80170BA4: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80170BA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80170BAC: lw          $t0, 0x54($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X54);
    // 0x80170BB0: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80170BB4: bnel        $at, $zero, L_80170B28
    if (ctx->r1 != 0) {
        // 0x80170BB8: lw          $t5, 0x54($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X54);
            goto L_80170B28;
    }
    goto skip_20;
    // 0x80170BB8: lw          $t5, 0x54($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X54);
    skip_20:
    // 0x80170BBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80170BC0:
    // 0x80170BC0: lw          $v0, 0x54($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X54);
L_80170BC4:
    // 0x80170BC4: blezl       $v0, L_80170C4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80170BC8: lw          $s7, 0x4($s7)
        ctx->r23 = MEM_W(ctx->r23, 0X4);
            goto L_80170C4C;
    }
    goto skip_21;
    // 0x80170BC8: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
    skip_21:
    // 0x80170BCC: lw          $t6, 0x248($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X248);
L_80170BD0:
    // 0x80170BD0: addiu       $s0, $s4, 0x244
    ctx->r16 = ADD32(ctx->r20, 0X244);
    // 0x80170BD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80170BD8: beq         $t6, $zero, L_80170C48
    if (ctx->r14 == 0) {
        // 0x80170BDC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80170C48;
    }
    // 0x80170BDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80170BE0: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80170BE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80170BE8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80170BEC: bne         $t2, $at, L_80170BFC
    if (ctx->r10 != ctx->r1) {
        // 0x80170BF0: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80170BFC;
    }
    // 0x80170BF0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80170BF4: b           L_80170C38
    // 0x80170BF8: lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X54);
        goto L_80170C38;
    // 0x80170BF8: lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X54);
L_80170BFC:
    // 0x80170BFC: jal         0x800F06E8
    // 0x80170C00: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gmCollisionCheckItemAttackDamageCollide(rdram, ctx);
        goto after_2;
    // 0x80170C00: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_2:
    // 0x80170C04: beq         $v0, $zero, L_80170C34
    if (ctx->r2 == 0) {
        // 0x80170C08: lw          $t4, 0x84($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X84);
            goto L_80170C34;
    }
    // 0x80170C08: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80170C0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80170C10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80170C14: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80170C18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80170C1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80170C20: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x80170C24: jal         0x8016FF4C
    // 0x80170C28: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    itProcessUpdateDamageStatItem(rdram, ctx);
        goto after_3;
    // 0x80170C28: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_3:
    // 0x80170C2C: b           L_80170C4C
    // 0x80170C30: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
        goto L_80170C4C;
    // 0x80170C30: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
L_80170C34:
    // 0x80170C34: lw          $v0, 0x54($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X54);
L_80170C38:
    // 0x80170C38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80170C3C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80170C40: bnel        $at, $zero, L_80170BD0
    if (ctx->r1 != 0) {
        // 0x80170C44: lw          $t6, 0x248($s4)
        ctx->r14 = MEM_W(ctx->r20, 0X248);
            goto L_80170BD0;
    }
    goto skip_22;
    // 0x80170C44: lw          $t6, 0x248($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X248);
    skip_22:
L_80170C48:
    // 0x80170C48: lw          $s7, 0x4($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X4);
L_80170C4C:
    // 0x80170C4C: bne         $s7, $zero, L_801708EC
    if (ctx->r23 != 0) {
        // 0x80170C50: nop
    
            goto L_801708EC;
    }
    // 0x80170C50: nop

    // 0x80170C54: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80170C58:
    // 0x80170C58: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80170C5C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80170C60: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80170C64: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80170C68: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80170C6C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80170C70: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80170C74: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80170C78: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80170C7C: jr          $ra
    // 0x80170C80: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80170C80: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void syMatrixRotRpRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CE30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CE34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CE38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001CE3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001CE40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001CE44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001CE48: jal         0x800303F0
    // 0x8001CE4C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CE4C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x8001CE50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001CE54: jal         0x80035CD0
    // 0x8001CE58: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CE58: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001CE5C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001CE60: jal         0x800303F0
    // 0x8001CE64: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001CE64: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8001CE68: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001CE6C: jal         0x80035CD0
    // 0x8001CE70: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001CE70: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8001CE74: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001CE78: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001CE7C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CE80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001CE84: mul.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8001CE88: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x8001CE8C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001CE90: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8001CE94: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001CE98: swc1        $f12, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f12.u32l;
    // 0x8001CE9C: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001CEA0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8001CEA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001CEA8: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001CEAC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001CEB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001CEB4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8001CEB8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8001CEBC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8001CEC0: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8001CEC4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8001CEC8: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8001CECC: swc1        $f12, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f12.u32l;
    // 0x8001CED0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001CED4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8001CED8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8001CEDC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8001CEE0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001CEE4: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8001CEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CEEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001CEF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001CEF4: jr          $ra
    // 0x8001CEF8: nop

    return;
    // 0x8001CEF8: nop

;}
RECOMP_FUNC void gcSetMObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F58: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007F5C: addiu       $v0, $v0, 0x6A28
    ctx->r2 = ADD32(ctx->r2, 0X6A28);
    // 0x80007F60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007F64: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80007F68: addiu       $v1, $v1, 0x6A2C
    ctx->r3 = ADD32(ctx->r3, 0X6A2C);
    // 0x80007F6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80007F70: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007F74: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80007F78: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80007F7C: jr          $ra
    // 0x80007F80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80007F80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftCommonAttackHi3CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FB1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014FB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FB24: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014FB28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014FB2C: lw          $t6, 0x9C8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X9C8);
    // 0x8014FB30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8014FB34: lhu         $t8, 0x1B4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B4);
    // 0x8014FB38: lhu         $t7, 0x1BE($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
    // 0x8014FB3C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014FB40: beql        $t9, $zero, L_8014FBD4
    if (ctx->r25 == 0) {
        // 0x8014FB44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FBD4;
    }
    goto skip_0;
    // 0x8014FB44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014FB48: lb          $t0, 0x1C3($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1C3);
    // 0x8014FB4C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014FB50: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x8014FB54: bnel        $at, $zero, L_8014FBD4
    if (ctx->r1 != 0) {
        // 0x8014FB58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FBD4;
    }
    goto skip_1;
    // 0x8014FB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014FB5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014FB60: jal         0x800E8000
    // 0x8014FB64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x8014FB64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014FB68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FB6C: lwc1        $f4, -0x3B38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B38);
    // 0x8014FB70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FB74: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014FB78: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8014FB7C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014FB80: bc1fl       L_8014FBD4
    if (!c1cs) {
        // 0x8014FB84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FBD4;
    }
    goto skip_2;
    // 0x8014FB84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8014FB88: jal         0x80146A8C
    // 0x8014FB8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_1;
    // 0x8014FB8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014FB90: beq         $v0, $zero, L_8014FBAC
    if (ctx->r2 == 0) {
        // 0x8014FB94: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8014FBAC;
    }
    // 0x8014FB94: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014FB98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014FB9C: jal         0x80146690
    // 0x8014FBA0: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014FBA0: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    after_2:
    // 0x8014FBA4: b           L_8014FBD4
    // 0x8014FBA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FBD4;
    // 0x8014FBA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014FBAC:
    // 0x8014FBAC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8014FBB0: lw          $t2, 0x100($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X100);
    // 0x8014FBB4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x8014FBB8: bgezl       $t4, L_8014FBD4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8014FBBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FBD4;
    }
    goto skip_3;
    // 0x8014FBBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8014FBC0: jal         0x8014FA50
    // 0x8014FBC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttackHi3SetStatus(rdram, ctx);
        goto after_3;
    // 0x8014FBC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8014FBC8: b           L_8014FBD4
    // 0x8014FBCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FBD4;
    // 0x8014FBCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014FBD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014FBD4:
    // 0x8014FBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014FBDC: jr          $ra
    // 0x8014FBE0: nop

    return;
    // 0x8014FBE0: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156A7C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80156A80: jal         0x800DDE84
    // 0x80156A84: addiu       $a1, $a1, 0x6B38
    ctx->r5 = ADD32(ctx->r5, 0X6B38);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80156A84: addiu       $a1, $a1, 0x6B38
    ctx->r5 = ADD32(ctx->r5, 0X6B38);
    after_0:
    // 0x80156A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156A90: jr          $ra
    // 0x80156A94: nop

    return;
    // 0x80156A94: nop

;}
RECOMP_FUNC void wpYoshiStarGetScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C540: lw          $t6, 0x268($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X268);
    // 0x8016C544: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016C548: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016C54C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016C550: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C554: lwc1        $f8, -0x34C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X34C0);
    // 0x8016C558: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016C55C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C560: lwc1        $f16, -0x34BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X34BC);
    // 0x8016C564: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016C568: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016C56C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8016C570: nop

    // 0x8016C574: bc1f        L_8016C580
    if (!c1cs) {
        // 0x8016C578: nop
    
            goto L_8016C580;
    }
    // 0x8016C578: nop

    // 0x8016C57C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8016C580:
    // 0x8016C580: jr          $ra
    // 0x8016C584: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8016C584: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void scManagerMeterProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26D8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800A26DC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A26E0: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800A26E4: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800A26E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A26EC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A26F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A26F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A26F8: lw          $a1, 0x74($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X74);
    // 0x800A26FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2700: jal         0x80016338
    // 0x800A2704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80016338(rdram, ctx);
        goto after_0;
    // 0x800A2704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800A2708: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A270C: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x800A2710: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800A2714: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800A2718: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800A271C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2720: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2724: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2728: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800A272C: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x800A2730: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800A2734: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800A2738: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800A273C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A2740: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2744: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x800A2748: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x800A274C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800A2750: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800A2754: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800A2758: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A275C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800A2760: lhu         $t5, 0x6448($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X6448);
    // 0x800A2764: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A2768: bgez        $t5, L_800A2780
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A276C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A2780;
    }
    // 0x800A276C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2770: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A2774: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2778: nop

    // 0x800A277C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800A2780:
    // 0x800A2780: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x800A2784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2788: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A278C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A2790: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800A2794: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A2798: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800A279C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A27A0: nop

    // 0x800A27A4: bgezl       $v1, L_800A27B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A27A8: slti        $at, $v1, 0x101
        ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
            goto L_800A27B4;
    }
    goto skip_0;
    // 0x800A27A8: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    skip_0:
    // 0x800A27AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A27B0: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
L_800A27B4:
    // 0x800A27B4: bnel        $at, $zero, L_800A27C4
    if (ctx->r1 != 0) {
        // 0x800A27B8: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800A27C4;
    }
    goto skip_1;
    // 0x800A27B8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800A27BC: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x800A27C0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800A27C4:
    // 0x800A27C4: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x800A27C8: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x800A27CC: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800A27D0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800A27D4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A27D8: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x800A27DC: jal         0x80006D70
    // 0x800A27E0: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    syVideoGetFillColor(rdram, ctx);
        goto after_1;
    // 0x800A27E0: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    after_1:
    // 0x800A27E4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800A27E8: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800A27EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800A27F0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800A27F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A27F8: addiu       $t3, $v1, 0x1E
    ctx->r11 = ADD32(ctx->r3, 0X1E);
    // 0x800A27FC: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x800A2800: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x800A2804: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800A2808: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800A280C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800A2810: lui         $t8, 0x7
    ctx->r24 = S32(0X7 << 16);
    // 0x800A2814: ori         $t8, $t8, 0x832C
    ctx->r24 = ctx->r24 | 0X832C;
    // 0x800A2818: ori         $t7, $t6, 0x330
    ctx->r15 = ctx->r14 | 0X330;
    // 0x800A281C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800A2820: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800A2824: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2828: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A282C: addiu       $a3, $zero, 0xCD
    ctx->r7 = ADD32(0, 0XCD);
    // 0x800A2830: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800A2834: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800A2838: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A283C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2840: lhu         $t3, 0x644A($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X644A);
    // 0x800A2844: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A2848: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x800A284C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A2850: bgez        $t3, L_800A2864
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A2854: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A2864;
    }
    // 0x800A2854: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2858: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A285C: nop

    // 0x800A2860: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800A2864:
    // 0x800A2864: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A2868: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A286C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A2870: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A2874: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A2878: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A287C: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800A2880: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A2884: nop

    // 0x800A2888: bgezl       $v1, L_800A2898
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A288C: slti        $at, $v1, 0x101
        ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
            goto L_800A2898;
    }
    goto skip_2;
    // 0x800A288C: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    skip_2:
    // 0x800A2890: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A2894: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
L_800A2898:
    // 0x800A2898: bnel        $at, $zero, L_800A28A8
    if (ctx->r1 != 0) {
        // 0x800A289C: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800A28A8;
    }
    goto skip_3;
    // 0x800A289C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x800A28A0: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x800A28A4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800A28A8:
    // 0x800A28A8: lui         $a0, 0xFF40
    ctx->r4 = S32(0XFF40 << 16);
    // 0x800A28AC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x800A28B0: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800A28B4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800A28B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800A28BC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800A28C0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x800A28C4: jal         0x80006D70
    // 0x800A28C8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    syVideoGetFillColor(rdram, ctx);
        goto after_2;
    // 0x800A28C8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    after_2:
    // 0x800A28CC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800A28D0: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800A28D4: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800A28D8: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800A28DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A28E0: addiu       $t8, $v1, 0x1E
    ctx->r24 = ADD32(ctx->r3, 0X1E);
    // 0x800A28E4: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800A28E8: sll         $t3, $t9, 14
    ctx->r11 = S32(ctx->r25 << 14);
    // 0x800A28EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800A28F0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800A28F4: addiu       $t5, $a3, 0x1
    ctx->r13 = ADD32(ctx->r7, 0X1);
    // 0x800A28F8: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800A28FC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800A2900: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x800A2904: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x800A2908: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800A290C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800A2910: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x800A2914: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A2918: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800A291C: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x800A2920: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800A2924: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A2928: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A292C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800A2930: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A2934: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800A2938: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800A293C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2940: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2944: lhu         $t4, 0x644C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X644C);
    // 0x800A2948: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800A294C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800A2950: bgez        $t4, L_800A2964
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A2954: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800A2964;
    }
    // 0x800A2954: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A295C: nop

    // 0x800A2960: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800A2964:
    // 0x800A2964: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800A2968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A296C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A2970: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2974: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800A2978: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800A297C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800A2980: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800A2984: nop

    // 0x800A2988: bgezl       $v1, L_800A2998
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A298C: slti        $at, $v1, 0x101
        ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
            goto L_800A2998;
    }
    goto skip_4;
    // 0x800A298C: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    skip_4:
    // 0x800A2990: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A2994: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
L_800A2998:
    // 0x800A2998: bnel        $at, $zero, L_800A29A8
    if (ctx->r1 != 0) {
        // 0x800A299C: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800A29A8;
    }
    goto skip_5;
    // 0x800A299C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x800A29A0: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x800A29A4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800A29A8:
    // 0x800A29A8: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x800A29AC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A29B0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800A29B4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800A29B8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A29BC: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800A29C0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x800A29C4: jal         0x80006D70
    // 0x800A29C8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    syVideoGetFillColor(rdram, ctx);
        goto after_3;
    // 0x800A29C8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    after_3:
    // 0x800A29CC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800A29D0: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800A29D4: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x800A29D8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800A29DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A29E0: addiu       $t5, $v1, 0x1E
    ctx->r13 = ADD32(ctx->r3, 0X1E);
    // 0x800A29E4: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x800A29E8: sll         $t4, $t6, 14
    ctx->r12 = S32(ctx->r14 << 14);
    // 0x800A29EC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800A29F0: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800A29F4: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800A29F8: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800A29FC: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800A2A00: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800A2A04: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x800A2A08: andi        $t6, $a3, 0x3FF
    ctx->r14 = ctx->r7 & 0X3FF;
    // 0x800A2A0C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800A2A10: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x800A2A14: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800A2A18: or          $t5, $t7, $t3
    ctx->r13 = ctx->r15 | ctx->r11;
    // 0x800A2A1C: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x800A2A20: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800A2A24: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800A2A28: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2A2C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800A2A30: addiu       $t2, $t2, 0x65E8
    ctx->r10 = ADD32(ctx->r10, 0X65E8);
    // 0x800A2A34: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800A2A38: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800A2A3C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2A40: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2A44: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800A2A48: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x800A2A4C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2A50: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800A2A54: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x800A2A58: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800A2A5C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800A2A60: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800A2A64: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800A2A68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A2A6C: jal         0x80006D70
    // 0x800A2A70: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    syVideoGetFillColor(rdram, ctx);
        goto after_4;
    // 0x800A2A70: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    after_4:
    // 0x800A2A74: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800A2A78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A2A7C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800A2A80: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800A2A84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A2A88: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800A2A8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800A2A90: jal         0x800218E0
    // 0x800A2A94: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_800218E0(rdram, ctx);
        goto after_5;
    // 0x800A2A94: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_5:
    // 0x800A2A98: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2A9C: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800A2AA0: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x800A2AA4: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800A2AA8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800A2AAC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2AB0: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2AB4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2AB8: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x800A2ABC: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x800A2AC0: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800A2AC4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800A2AC8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2ACC: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800A2AD0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2AD4: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x800A2AD8: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x800A2ADC: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800A2AE0: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800A2AE4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A2AE8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800A2AEC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800A2AF0: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800A2AF4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800A2AF8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800A2AFC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800A2B00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2B04: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A2B08: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A2B0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A2B10: jr          $ra
    // 0x800A2B14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800A2B14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_ovl8_803848CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803848CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803848D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803848D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803848D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803848DC: beq         $a0, $zero, L_80384954
    if (ctx->r4 == 0) {
        // 0x803848E0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80384954;
    }
    // 0x803848E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803848E4: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x803848E8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803848EC: addiu       $t6, $t6, -0x2C60
    ctx->r14 = ADD32(ctx->r14, -0X2C60);
    // 0x803848F0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803848F4: addiu       $t7, $t7, -0x2B40
    ctx->r15 = ADD32(ctx->r15, -0X2B40);
    // 0x803848F8: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x803848FC: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80384900: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80384904: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80384908: addiu       $t9, $t9, -0x29E8
    ctx->r25 = ADD32(ctx->r25, -0X29E8);
    // 0x8038490C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80384910: jal         0x8037354C
    // 0x80384914: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_8037354C(rdram, ctx);
        goto after_0;
    // 0x80384914: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x80384918: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8038491C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80384920: beql        $t1, $zero, L_80384940
    if (ctx->r9 == 0) {
        // 0x80384924: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80384940;
    }
    goto skip_0;
    // 0x80384924: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80384928: jal         0x8037C30C
    // 0x8038492C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x8038492C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80384930: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80384934: jal         0x803718C4
    // 0x80384938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80384938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8038493C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_80384940:
    // 0x80384940: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80384944: beql        $t3, $zero, L_80384958
    if (ctx->r11 == 0) {
        // 0x80384948: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80384958;
    }
    goto skip_1;
    // 0x80384948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8038494C: jal         0x803717C0
    // 0x80384950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80384950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80384954:
    // 0x80384954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80384958:
    // 0x80384958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8038495C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80384960: jr          $ra
    // 0x80384964: nop

    return;
    // 0x80384964: nop

;}
RECOMP_FUNC void mnVSResultsGetTeamTotalPoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136FB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80136FBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80136FC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80136FC4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80136FC8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80136FCC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80136FD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80136FD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136FD8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80136FDC: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80136FE0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80136FE4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80136FE8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80136FEC: addiu       $s3, $s3, 0x4D08
    ctx->r19 = ADD32(ctx->r19, 0X4D08);
    // 0x80136FF0: addiu       $s1, $s1, -0x6430
    ctx->r17 = ADD32(ctx->r17, -0X6430);
    // 0x80136FF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80136FF8: addiu       $s4, $zero, 0x74
    ctx->r20 = ADD32(0, 0X74);
    // 0x80136FFC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_80137000:
    // 0x80137000: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80137004: beql        $t6, $zero, L_80137034
    if (ctx->r14 == 0) {
        // 0x80137008: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137034;
    }
    goto skip_0;
    // 0x80137008: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8013700C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137010: mflo        $t7
    ctx->r15 = lo;
    // 0x80137014: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80137018: lbu         $t9, 0x24($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X24);
    // 0x8013701C: bnel        $s6, $t9, L_80137034
    if (ctx->r22 != ctx->r25) {
        // 0x80137020: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137034;
    }
    goto skip_1;
    // 0x80137020: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80137024: jal         0x80136C08
    // 0x80137028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetPointsDirect(rdram, ctx);
        goto after_0;
    // 0x80137028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013702C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80137030: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80137034:
    // 0x80137034: bne         $s0, $s5, L_80137000
    if (ctx->r16 != ctx->r21) {
        // 0x80137038: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80137000;
    }
    // 0x80137038: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8013703C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80137040: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80137044: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013704C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80137050: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80137054: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80137058: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8013705C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80137060: jr          $ra
    // 0x80137064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80137064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftCommonCliffClimbQuick1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801451F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801451F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801451F8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801451FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80145200: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x80145204: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145208: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014520C: jal         0x800E6F24
    // 0x80145210: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145210: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80145214: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80145218: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8014521C: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x80145220: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x80145224: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x80145228: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8014522C: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x80145230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145238: jr          $ra
    // 0x8014523C: nop

    return;
    // 0x8014523C: nop

;}
RECOMP_FUNC void itEggExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181AA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181AB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80181AB4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181AB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80181ABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181AC0: lbu         $t7, 0x340($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X340);
    // 0x80181AC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80181AC8: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80181ACC: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x80181AD0: sb          $t8, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r24;
    // 0x80181AD4: sh          $t9, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r25;
    // 0x80181AD8: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80181ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80181AE0: jal         0x800269C0
    // 0x80181AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80181AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80181AE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80181AEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80181AF0: lbu         $t1, 0x158($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X158);
    // 0x80181AF4: sw          $t9, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r25;
    // 0x80181AF8: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x80181AFC: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x80181B00: andi        $t5, $t3, 0xF7
    ctx->r13 = ctx->r11 & 0XF7;
    // 0x80181B04: andi        $t7, $t5, 0xFB
    ctx->r15 = ctx->r13 & 0XFB;
    // 0x80181B08: sb          $t3, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r11;
    // 0x80181B0C: sb          $t5, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r13;
    // 0x80181B10: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80181B14: sb          $t7, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r15;
    // 0x80181B18: sb          $t8, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r24;
    // 0x80181B1C: jal         0x8017279C
    // 0x80181B20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x80181B20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80181B24: jal         0x8017275C
    // 0x80181B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainRefreshAttackColl(rdram, ctx);
        goto after_2;
    // 0x80181B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80181B2C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80181B30: lw          $t0, -0x4F8C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4F8C);
    // 0x80181B34: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80181B38: addiu       $t2, $t2, 0x98
    ctx->r10 = ADD32(ctx->r10, 0X98);
    // 0x80181B3C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80181B40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80181B44: jal         0x80173180
    // 0x80181B48: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_3;
    // 0x80181B48: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x80181B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181B54: jr          $ra
    // 0x80181B58: nop

    return;
    // 0x80181B58: nop

;}
RECOMP_FUNC void func_ovl8_80375D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375D44: jr          $ra
    // 0x80375D48: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    return;
    // 0x80375D48: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_ovl59_80131C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C88: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80131C8C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131C90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80131C94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80131C98: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80131C9C: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80131CA0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80131CA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80131CA8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80131CAC: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80131CB0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80131CB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80131CB8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80131CBC: jal         0x8001B248
    // 0x80131CC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_0;
    // 0x80131CC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80131CC4: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80131CC8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80131CCC: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80131CD0: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x80131CD4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80131CD8: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80131CDC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80131CE0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80131CE4: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80131CE8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80131CEC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80131CF0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80131CF4: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80131CF8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80131CFC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80131D00: jal         0x8001A0F0
    // 0x80131D04: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_1;
    // 0x80131D04: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80131D08: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80131D0C: addiu       $a2, $a2, -0x55E8
    ctx->r6 = ADD32(ctx->r6, -0X55E8);
    // 0x80131D10: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80131D14: jal         0x80034980
    // 0x80131D18: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x80131D18: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80131D1C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80131D20: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131D24: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x80131D28: jr          $ra
    // 0x80131D2C: nop

    return;
    // 0x80131D2C: nop

;}
RECOMP_FUNC void lbCommonCos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C78BC: lwc1        $f4, 0x5E64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E64);
    // 0x800C78C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C78C4: lwc1        $f8, 0x5E68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E68);
    // 0x800C78C8: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800C78CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C78D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C78D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C78D8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C78DC: nop

    // 0x800C78E0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C78E4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C78E8: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
    // 0x800C78EC: beq         $t7, $zero, L_800C7910
    if (ctx->r15 == 0) {
        // 0x800C78F0: andi        $t3, $v0, 0x800
        ctx->r11 = ctx->r2 & 0X800;
            goto L_800C7910;
    }
    // 0x800C78F0: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x800C78F4: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x800C78F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C78FC: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x800C7900: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7904: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C7908: b           L_800C7920
    // 0x800C790C: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
        goto L_800C7920;
    // 0x800C790C: lwc1        $f2, 0x5C9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5C9C);
L_800C7910:
    // 0x800C7910: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x800C7914: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800C7918: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800C791C: lwc1        $f2, 0x4CA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4CA0);
L_800C7920:
    // 0x800C7920: beql        $t3, $zero, L_800C7934
    if (ctx->r11 == 0) {
        // 0x800C7924: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800C7934;
    }
    goto skip_0;
    // 0x800C7924: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x800C7928: jr          $ra
    // 0x800C792C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    return;
    // 0x800C792C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800C7930: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800C7934:
    // 0x800C7934: jr          $ra
    // 0x800C7938: nop

    return;
    // 0x800C7938: nop

;}
RECOMP_FUNC void func_ovl8_80386228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8038622C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80386230: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80386234: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80386238: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8038623C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80386240: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80386244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80386248: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8038624C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80386250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80386254: jal         0x803863A4
    // 0x80386258: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    func_ovl8_803863A4(rdram, ctx);
        goto after_0;
    // 0x80386258: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x8038625C: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x80386260: addiu       $s1, $s1, -0x1D2C
    ctx->r17 = ADD32(ctx->r17, -0X1D2C);
    // 0x80386264: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80386268: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038626C: addiu       $a1, $a1, -0x1DF8
    ctx->r5 = ADD32(ctx->r5, -0X1DF8);
    // 0x80386270: addiu       $t6, $t6, -0x1A70
    ctx->r14 = ADD32(ctx->r14, -0X1A70);
    // 0x80386274: sw          $t6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r14;
    // 0x80386278: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8038627C: or          $t9, $s1, $zero
    ctx->r25 = ctx->r17 | 0;
    // 0x80386280: addiu       $t1, $s1, 0x24
    ctx->r9 = ADD32(ctx->r17, 0X24);
L_80386284:
    // 0x80386284: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80386288: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8038628C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80386290: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80386294: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x80386298: sw          $t7, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r15;
    // 0x8038629C: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x803862A0: bne         $t9, $t1, L_80386284
    if (ctx->r25 != ctx->r9) {
        // 0x803862A4: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80386284;
    }
    // 0x803862A4: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x803862A8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x803862AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x803862B0: jal         0x803864CC
    // 0x803862B4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    func_ovl8_803864CC(rdram, ctx);
        goto after_1;
    // 0x803862B4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_1:
    // 0x803862B8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x803862BC: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x803862C0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803862C4: addiu       $s2, $s2, -0x1E20
    ctx->r18 = ADD32(ctx->r18, -0X1E20);
    // 0x803862C8: addiu       $a1, $a1, -0x1DD0
    ctx->r5 = ADD32(ctx->r5, -0X1DD0);
    // 0x803862CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x803862D0: addiu       $t2, $t2, -0x1A6C
    ctx->r10 = ADD32(ctx->r10, -0X1A6C);
    // 0x803862D4: sw          $s0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r16;
    // 0x803862D8: sw          $t2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r10;
    // 0x803862DC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x803862E0: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x803862E4: addiu       $t1, $s1, 0x24
    ctx->r9 = ADD32(ctx->r17, 0X24);
L_803862E8:
    // 0x803862E8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x803862EC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x803862F0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x803862F4: sw          $t4, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r12;
    // 0x803862F8: lw          $t3, -0x8($t5)
    ctx->r11 = MEM_W(ctx->r13, -0X8);
    // 0x803862FC: sw          $t3, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r11;
    // 0x80386300: lw          $t4, -0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, -0X4);
    // 0x80386304: bne         $t5, $t1, L_803862E8
    if (ctx->r13 != ctx->r9) {
        // 0x80386308: sw          $t4, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r12;
            goto L_803862E8;
    }
    // 0x80386308: sw          $t4, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r12;
    // 0x8038630C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80386310: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80386314: jal         0x803864CC
    // 0x80386318: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    func_ovl8_803864CC(rdram, ctx);
        goto after_2;
    // 0x80386318: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    after_2:
    // 0x8038631C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80386320: sw          $s1, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r17;
    // 0x80386324: jal         0x80381C80
    // 0x80386328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_80381C80(rdram, ctx);
        goto after_3;
    // 0x80386328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8038632C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80386330: addiu       $v1, $v1, 0x3C0
    ctx->r3 = ADD32(ctx->r3, 0X3C0);
    // 0x80386334: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80386338: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8038633C: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x80386340: jal         0x8037481C
    // 0x80386344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_ovl8_8037481C(rdram, ctx);
        goto after_4;
    // 0x80386344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80386348: lui         $s2, 0x8039
    ctx->r18 = S32(0X8039 << 16);
    // 0x8038634C: addiu       $s2, $s2, 0x3C8
    ctx->r18 = ADD32(ctx->r18, 0X3C8);
    // 0x80386350: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80386354: beq         $v0, $s0, L_80386380
    if (ctx->r2 == ctx->r16) {
        // 0x80386358: nop
    
            goto L_80386380;
    }
    // 0x80386358: nop

    // 0x8038635C: beq         $v0, $s1, L_80386380
    if (ctx->r2 == ctx->r17) {
        // 0x80386360: nop
    
            goto L_80386380;
    }
    // 0x80386360: nop

L_80386364:
    // 0x80386364: jal         0x8000B1E8
    // 0x80386368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80386368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8038636C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80386370: beq         $v0, $s0, L_80386380
    if (ctx->r2 == ctx->r16) {
        // 0x80386374: nop
    
            goto L_80386380;
    }
    // 0x80386374: nop

    // 0x80386378: bne         $v0, $s1, L_80386364
    if (ctx->r2 != ctx->r17) {
        // 0x8038637C: nop
    
            goto L_80386364;
    }
    // 0x8038637C: nop

L_80386380:
    // 0x80386380: jal         0x8038649C
    // 0x80386384: nop

    func_ovl8_8038649C(rdram, ctx);
        goto after_6;
    // 0x80386384: nop

    after_6:
    // 0x80386388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8038638C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80386390: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80386394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80386398: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8038639C: jr          $ra
    // 0x803863A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803863A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sc1PStageClearMakeScoreSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801323FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132400: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132408: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8013240C: jal         0x80009968
    // 0x80132410: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132410: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132418: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013241C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132420: sw          $v0, 0x5310($at)
    MEM_W(0X5310, ctx->r1) = ctx->r2;
    // 0x80132424: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80132428: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013242C: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132434: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132438: jal         0x80009DF4
    // 0x8013243C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013243C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132440: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132444: lw          $t7, 0x558C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X558C);
    // 0x80132448: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8013244C: addiu       $t8, $t8, 0x408
    ctx->r24 = ADD32(ctx->r24, 0X408);
    // 0x80132450: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80132454: jal         0x800CCFDC
    // 0x80132458: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132458: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013245C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132460: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80132464: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132468: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8013246C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132470: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132474: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132478: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013247C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132480: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x80132484: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132488: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x8013248C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132490: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132494: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132498: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x8013249C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801324A0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801324A4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801324A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801324AC: lui         $a2, 0x4393
    ctx->r6 = S32(0X4393 << 16);
    // 0x801324B0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801324B4: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x801324B8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x801324BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801324C0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801324C4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801324C8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x801324CC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801324D0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x801324D4: lw          $a1, 0x52E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X52E8);
    // 0x801324D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801324DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801324E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801324E4: jal         0x80131E10
    // 0x801324E8: lui         $a3, 0x4345
    ctx->r7 = S32(0X4345 << 16);
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_3;
    // 0x801324E8: lui         $a3, 0x4345
    ctx->r7 = S32(0X4345 << 16);
    after_3:
    // 0x801324EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801324F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801324F4: jr          $ra
    // 0x801324F8: nop

    return;
    // 0x801324F8: nop

;}
RECOMP_FUNC void _n_filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AB94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002AB98: lui         $t6, 0xB00
    ctx->r14 = S32(0XB00 << 16);
    // 0x8002AB9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ABA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002ABA4: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x8002ABA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002ABAC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8002ABB0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8002ABB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002ABB8: jal         0x80032150
    // 0x8002ABBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8002ABBC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8002ABC0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002ABC4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002ABC8: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x8002ABCC: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x8002ABD0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8002ABD4: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8002ABD8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8002ABDC: lw          $t8, 0x2C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X2C);
    // 0x8002ABE0: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x8002ABE4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8002ABE8: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8002ABEC: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8002ABF0: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8002ABF4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8002ABF8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002ABFC: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x8002AC00: jal         0x80032150
    // 0x8002AC04: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8002AC04: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002AC08: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AC0C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002AC10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002AC14: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002AC18: sra         $t0, $t6, 8
    ctx->r8 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8002AC1C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002AC20: sll         $t2, $t0, 24
    ctx->r10 = S32(ctx->r8 << 24);
    // 0x8002AC24: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8002AC28: or          $t1, $t5, $t2
    ctx->r9 = ctx->r13 | ctx->r10;
    // 0x8002AC2C: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x8002AC30: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x8002AC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AC38: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002AC3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002AC40: jr          $ra
    // 0x8002AC44: nop

    return;
    // 0x8002AC44: nop

;}
RECOMP_FUNC void mnVSResultsGetOnesDigit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134718: bgez        $a0, L_80134748
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8013471C: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80134748;
    }
    // 0x8013471C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134720: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134724: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134728: mfhi        $v0
    ctx->r2 = hi;
    // 0x8013472C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80134730: nop

    // 0x80134734: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80134738: mfhi        $v0
    ctx->r2 = hi;
    // 0x8013473C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80134740: jr          $ra
    // 0x80134744: nop

    return;
    // 0x80134744: nop

L_80134748:
    // 0x80134748: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8013474C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80134750: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80134754: nop

    // 0x80134758: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8013475C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80134760: nop

    // 0x80134764: nop

    // 0x80134768: jr          $ra
    // 0x8013476C: nop

    return;
    // 0x8013476C: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015784C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157850: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157854: jal         0x800DE6E4
    // 0x80157858: addiu       $a1, $a1, 0x786C
    ctx->r5 = ADD32(ctx->r5, 0X786C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80157858: addiu       $a1, $a1, 0x786C
    ctx->r5 = ADD32(ctx->r5, 0X786C);
    after_0:
    // 0x8015785C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157864: jr          $ra
    // 0x80157868: nop

    return;
    // 0x80157868: nop

;}
RECOMP_FUNC void itBombHeiCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017741C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177424: jal         0x801779E4
    // 0x80177428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonClearVelSetExplode(rdram, ctx);
        goto after_0;
    // 0x80177428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8017742C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177438: jr          $ra
    // 0x8017743C: nop

    return;
    // 0x8017743C: nop

;}
RECOMP_FUNC void func_ovl29_80131F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F64: jr          $ra
    // 0x80131F68: nop

    return;
    // 0x80131F68: nop

;}
RECOMP_FUNC void scStaffrollFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013505C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135064: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135068: addiu       $a1, $a1, 0x34E4
    ctx->r5 = ADD32(ctx->r5, 0X34E4);
    // 0x8013506C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135074: jal         0x80009968
    // 0x80135078: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135078: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013507C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80135080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135084: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80135088: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8013508C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80135090: jal         0x8000B9FC
    // 0x80135094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x80135094: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80135098: jal         0x801349DC
    // 0x8013509C: nop

    scStaffrollSetupFiles(rdram, ctx);
        goto after_2;
    // 0x8013509C: nop

    after_2:
    // 0x801350A0: jal         0x80134A70
    // 0x801350A4: nop

    scStaffrollInitNameAndJobDisplayLists(rdram, ctx);
        goto after_3;
    // 0x801350A4: nop

    after_3:
    // 0x801350A8: jal         0x80132958
    // 0x801350AC: nop

    scStaffrollTryHideUnlocks(rdram, ctx);
        goto after_4;
    // 0x801350AC: nop

    after_4:
    // 0x801350B0: jal         0x80134E08
    // 0x801350B4: nop

    scStaffrollInitVars(rdram, ctx);
        goto after_5;
    // 0x801350B4: nop

    after_5:
    // 0x801350B8: jal         0x801345FC
    // 0x801350BC: nop

    scStaffrollMakeCrosshairGObj(rdram, ctx);
        goto after_6;
    // 0x801350BC: nop

    after_6:
    // 0x801350C0: jal         0x8013498C
    // 0x801350C4: nop

    scStaffrollMakeScrollGObj(rdram, ctx);
        goto after_7;
    // 0x801350C4: nop

    after_7:
    // 0x801350C8: jal         0x80134EE8
    // 0x801350CC: nop

    scStaffrollMakeCamera(rdram, ctx);
        goto after_8;
    // 0x801350CC: nop

    after_8:
    // 0x801350D0: jal         0x80020A74
    // 0x801350D4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_9;
    // 0x801350D4: nop

    after_9:
    // 0x801350D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801350DC: jal         0x80020AB4
    // 0x801350E0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    syAudioPlayBGM(rdram, ctx);
        goto after_10;
    // 0x801350E0: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_10:
    // 0x801350E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801350E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801350EC: jr          $ra
    // 0x801350F0: nop

    return;
    // 0x801350F0: nop

;}
RECOMP_FUNC void func_ovl8_8037F654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F654: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037F658: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037F65C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8037F660: jr          $ra
    // 0x8037F664: sh          $a1, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r5;
    return;
    // 0x8037F664: sh          $a1, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mnMapsMakeIcons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132528: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8013252C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80132530: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132534: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x80132538: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8013253C: addiu       $t6, $t6, 0x466C
    ctx->r14 = ADD32(ctx->r14, 0X466C);
    // 0x80132540: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80132544: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80132548: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x8013254C: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80132550: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80132554: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80132558: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8013255C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80132560: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80132564: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80132568: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x8013256C: or          $t9, $s7, $zero
    ctx->r25 = ctx->r23 | 0;
L_80132570:
    // 0x80132570: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132574: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132578: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013257C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132580: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132584: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132588: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013258C: bne         $t6, $t0, L_80132570
    if (ctx->r14 != ctx->r8) {
        // 0x80132590: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132570;
    }
    // 0x80132590: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132594: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132598: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013259C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801325A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801325A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801325A8: jal         0x80009968
    // 0x801325AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801325AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_0:
    // 0x801325B0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801325B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801325B8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801325BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801325C0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801325C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801325C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801325CC: jal         0x80009DF4
    // 0x801325D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801325D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x801325D4: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x801325D8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801325DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801325E0: lui         $s5, 0x1
    ctx->r21 = S32(0X1 << 16);
    // 0x801325E4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801325E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801325EC: addiu       $s2, $s2, 0x4E10
    ctx->r18 = ADD32(ctx->r18, 0X4E10);
    // 0x801325F0: addiu       $s5, $s5, -0x34F0
    ctx->r21 = ADD32(ctx->r21, -0X34F0);
    // 0x801325F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801325F8: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x801325FC: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
L_80132600:
    // 0x80132600: jal         0x80132430
    // 0x80132604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnMapsGetGroundKind(rdram, ctx);
        goto after_2;
    // 0x80132604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80132608: jal         0x80131BAC
    // 0x8013260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_3;
    // 0x8013260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80132610: bne         $v0, $zero, L_8013269C
    if (ctx->r2 != 0) {
        // 0x80132614: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_8013269C;
    }
    // 0x80132614: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80132618: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8013261C: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x80132620: addu        $s1, $s1, $s0
    ctx->r17 = ADD32(ctx->r17, ctx->r16);
    // 0x80132624: bne         $s0, $s4, L_80132644
    if (ctx->r16 != ctx->r20) {
        // 0x80132628: sll         $s1, $s1, 1
        ctx->r17 = S32(ctx->r17 << 1);
            goto L_80132644;
    }
    // 0x80132628: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x8013262C: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    // 0x80132630: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80132634: jal         0x800CCFDC
    // 0x80132638: addu        $a1, $t2, $s5
    ctx->r5 = ADD32(ctx->r10, ctx->r21);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132638: addu        $a1, $t2, $s5
    ctx->r5 = ADD32(ctx->r10, ctx->r21);
    after_4:
    // 0x8013263C: b           L_8013266C
    // 0x80132640: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
        goto L_8013266C;
    // 0x80132640: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_80132644:
    // 0x80132644: jal         0x80132430
    // 0x80132648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnMapsGetGroundKind(rdram, ctx);
        goto after_5;
    // 0x80132648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013264C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80132650: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x80132654: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80132658: lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X8);
    // 0x8013265C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80132660: jal         0x800CCFDC
    // 0x80132664: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132664: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    after_6:
    // 0x80132668: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_8013266C:
    // 0x8013266C: beq         $at, $zero, L_8013268C
    if (ctx->r1 == 0) {
        // 0x80132670: addiu       $t9, $s1, -0xDC
        ctx->r25 = ADD32(ctx->r17, -0XDC);
            goto L_8013268C;
    }
    // 0x80132670: addiu       $t9, $s1, -0xDC
    ctx->r25 = ADD32(ctx->r17, -0XDC);
    // 0x80132674: addiu       $t6, $s1, 0x1E
    ctx->r14 = ADD32(ctx->r17, 0X1E);
    // 0x80132678: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013267C: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80132680: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132684: b           L_8013269C
    // 0x80132688: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_8013269C;
    // 0x80132688: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_8013268C:
    // 0x8013268C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80132690: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x80132694: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132698: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
L_8013269C:
    // 0x8013269C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801326A0: bne         $s0, $s6, L_80132600
    if (ctx->r16 != ctx->r22) {
        // 0x801326A4: nop
    
            goto L_80132600;
    }
    // 0x801326A4: nop

    // 0x801326A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801326AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801326B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801326B4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801326B8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801326BC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801326C0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801326C4: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x801326C8: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x801326CC: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x801326D0: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x801326D4: jr          $ra
    // 0x801326D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801326D8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void mnPlayersVSMakePlayerKindCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013303C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133040: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133044: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133048: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013304C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80133050: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133054: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80133058: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013305C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133060: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133064: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133068: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013306C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133070: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133074: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133078: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013307C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133080: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133084: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133088: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013308C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133094: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133098: jal         0x8000B93C
    // 0x8013309C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013309C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801330A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801330A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801330A8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801330AC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801330B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801330B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801330B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801330BC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801330C0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801330C4: jal         0x80007080
    // 0x801330C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801330C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801330CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801330D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801330D4: jr          $ra
    // 0x801330D8: nop

    return;
    // 0x801330D8: nop

;}
RECOMP_FUNC void func_ovl8_80377244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037724C: jal         0x8037D28C
    // 0x80377250: nop

    func_ovl8_8037D28C(rdram, ctx);
        goto after_0;
    // 0x80377250: nop

    after_0:
    // 0x80377254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377258: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8037725C: lhu         $t6, 0x5470($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5470);
    // 0x80377260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377264: jr          $ra
    // 0x80377268: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    return;
    // 0x80377268: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
;}
RECOMP_FUNC void itGShellDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178B68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178B6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80178B70: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178B74: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178B78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80178B7C: sb          $v1, 0x352($v0)
    MEM_B(0X352, ctx->r2) = ctx->r3;
    // 0x80178B80: jal         0x80172EC8
    // 0x80178B84: sb          $v1, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r3;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80178B84: sb          $v1, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r3;
    after_0:
    // 0x80178B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178B90: jr          $ra
    // 0x80178B94: nop

    return;
    // 0x80178B94: nop

;}
RECOMP_FUNC void grWallpaperCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104838: jal         0x80104620
    // 0x8010483C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    grWallpaperCalcPersp(rdram, ctx);
        goto after_0;
    // 0x8010483C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x80104840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104848: jr          $ra
    // 0x8010484C: nop

    return;
    // 0x8010484C: nop

;}
RECOMP_FUNC void gcRunFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001783C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017844: lw          $v0, 0x88($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X88);
    // 0x80017848: beql        $v0, $zero, L_8001785C
    if (ctx->r2 == 0) {
        // 0x8001784C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001785C;
    }
    goto skip_0;
    // 0x8001784C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80017850: jalr        $v0
    // 0x80017854: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80017854: nop

    after_0:
    // 0x80017858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001785C:
    // 0x8001785C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017860: jr          $ra
    // 0x80017864: nop

    return;
    // 0x80017864: nop

;}
RECOMP_FUNC void mvOpeningKirbyPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9BC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D9C0: lw          $v1, -0x1DD8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1DD8);
    // 0x8018D9C4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D9C8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9CC: beq         $v1, $at, L_8018D9F4
    if (ctx->r3 == ctx->r1) {
        // 0x8018D9D0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9F4;
    }
    // 0x8018D9D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D9D4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D9D8: beq         $v0, $at, L_8018DA08
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9DC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA08;
    }
    // 0x8018D9DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9E0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9E4: beq         $v0, $at, L_8018DA1C
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9E8: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA1C;
    }
    // 0x8018D9E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9EC: b           L_8018DA2C
    // 0x8018D9F0: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
        goto L_8018DA2C;
    // 0x8018D9F0: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
L_8018D9F4:
    // 0x8018D9F4: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9FC: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA00: b           L_8018DA2C
    // 0x8018DA04: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA2C;
    // 0x8018DA04: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018DA08:
    // 0x8018DA08: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018DA0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA10: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA14: b           L_8018DA2C
    // 0x8018DA18: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA2C;
    // 0x8018DA18: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018DA1C:
    // 0x8018DA1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DA20: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA24: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA28: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA2C:
    // 0x8018DA2C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA30: bne         $at, $zero, L_8018DA50
    if (ctx->r1 != 0) {
        // 0x8018DA34: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA50;
    }
    // 0x8018DA34: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA38: beq         $at, $zero, L_8018DA50
    if (ctx->r1 == 0) {
        // 0x8018DA3C: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA50;
    }
    // 0x8018DA3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA40: lwc1        $f16, -0x1DF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1DF0);
    // 0x8018DA44: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA4C: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA50:
    // 0x8018DA50: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA54: bne         $at, $zero, L_8018DA74
    if (ctx->r1 != 0) {
        // 0x8018DA58: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA74;
    }
    // 0x8018DA58: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA5C: beq         $at, $zero, L_8018DA74
    if (ctx->r1 == 0) {
        // 0x8018DA60: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA74;
    }
    // 0x8018DA60: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA68: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA70: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA74:
    // 0x8018DA74: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA78: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA7C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DA80: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018DA84: jr          $ra
    // 0x8018DA88: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA88: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mnCongraGetPlayerTapButtons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131B70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131B74: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80131B78: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80131B7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131B80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131B84: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80131B88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80131B8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80131B90: addiu       $s2, $s2, 0x5228
    ctx->r18 = ADD32(ctx->r18, 0X5228);
    // 0x80131B94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80131B98: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80131B9C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80131BA0:
    // 0x80131BA0: jal         0x80131B00
    // 0x80131BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnCongraCheckPlayerControllerConnected(rdram, ctx);
        goto after_0;
    // 0x80131BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80131BA8: beql        $v0, $zero, L_80131BD8
    if (ctx->r2 == 0) {
        // 0x80131BAC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80131BD8;
    }
    goto skip_0;
    // 0x80131BAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80131BB0: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BB4: mflo        $t6
    ctx->r14 = lo;
    // 0x80131BB8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80131BBC: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80131BC0: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x80131BC4: beql        $t9, $zero, L_80131BD8
    if (ctx->r25 == 0) {
        // 0x80131BC8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80131BD8;
    }
    goto skip_1;
    // 0x80131BC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80131BCC: b           L_80131BE4
    // 0x80131BD0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_80131BE4;
    // 0x80131BD0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80131BD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80131BD8:
    // 0x80131BD8: bne         $s0, $s4, L_80131BA0
    if (ctx->r16 != ctx->r20) {
        // 0x80131BDC: nop
    
            goto L_80131BA0;
    }
    // 0x80131BDC: nop

    // 0x80131BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131BE4:
    // 0x80131BE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80131BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131BEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131BF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131BF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80131BF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80131BFC: jr          $ra
    // 0x80131C00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131C00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void unref_800162C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800162C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800162CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800162D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800162D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800162D8: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x800162DC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800162E0: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800162E4: beql        $s0, $zero, L_80016328
    if (ctx->r16 == 0) {
        // 0x800162E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80016328;
    }
    goto skip_0;
    // 0x800162E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800162EC: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
L_800162F0:
    // 0x800162F0: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800162F4: bnel        $t7, $zero, L_8001631C
    if (ctx->r15 != 0) {
        // 0x800162F8: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_8001631C;
    }
    goto skip_1;
    // 0x800162F8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x800162FC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80016300: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80016304: jal         0x80025100
    // 0x80016308: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    spDraw(rdram, ctx);
        goto after_0;
    // 0x80016308: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    after_0:
    // 0x8001630C: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x80016310: addiu       $t0, $t9, -0x8
    ctx->r8 = ADD32(ctx->r25, -0X8);
    // 0x80016314: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x80016318: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
L_8001631C:
    // 0x8001631C: bnel        $s0, $zero, L_800162F0
    if (ctx->r16 != 0) {
        // 0x80016320: lhu         $t6, 0x24($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X24);
            goto L_800162F0;
    }
    goto skip_2;
    // 0x80016320: lhu         $t6, 0x24($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X24);
    skip_2:
    // 0x80016324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80016328:
    // 0x80016328: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001632C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80016330: jr          $ra
    // 0x80016334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80016334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNStartProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801577F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801577F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801577FC: lhu         $t6, 0x1B6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80157800: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80157804: lhu         $t9, 0x1BE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80157808: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8015780C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80157810: beq         $t0, $zero, L_8015781C
    if (ctx->r8 == 0) {
        // 0x80157814: nop
    
            goto L_8015781C;
    }
    // 0x80157814: nop

    // 0x80157818: sw          $t1, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r9;
L_8015781C:
    // 0x8015781C: jr          $ra
    // 0x80157820: nop

    return;
    // 0x80157820: nop

;}
RECOMP_FUNC void func_ovl8_80371BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371BCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371BD4: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80371BD8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80371BDC: beq         $t6, $zero, L_80371BF0
    if (ctx->r14 == 0) {
        // 0x80371BE0: nop
    
            goto L_80371BF0;
    }
    // 0x80371BE0: nop

    // 0x80371BE4: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80371BE8: bnel        $t7, $zero, L_80371BFC
    if (ctx->r15 != 0) {
        // 0x80371BEC: lw          $v0, 0x58($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X58);
            goto L_80371BFC;
    }
    goto skip_0;
    // 0x80371BEC: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    skip_0:
L_80371BF0:
    // 0x80371BF0: b           L_80371C0C
    // 0x80371BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80371C0C;
    // 0x80371BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80371BF8: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
L_80371BFC:
    // 0x80371BFC: lw          $t9, 0x9C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C);
    // 0x80371C00: lh          $t8, 0x98($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X98);
    // 0x80371C04: jalr        $t9
    // 0x80371C08: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371C08: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_0:
L_80371C0C:
    // 0x80371C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371C14: jr          $ra
    // 0x80371C18: nop

    return;
    // 0x80371C18: nop

;}
RECOMP_FUNC void func_ovl26_80139DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139DD8: jr          $ra
    // 0x80139DDC: nop

    return;
    // 0x80139DDC: nop

;}
RECOMP_FUNC void dbCubeFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80131E04: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
    // 0x80131E08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131E0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E10: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x80131E14: beq         $t6, $zero, L_80131E44
    if (ctx->r14 == 0) {
        // 0x80131E18: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80131E44;
    }
    // 0x80131E18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80131E1C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80131E20: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80131E24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80131E28: addiu       $a3, $a3, 0x2DC8
    ctx->r7 = ADD32(ctx->r7, 0X2DC8);
    // 0x80131E2C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80131E30: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80131E34: jal         0x80369D78
    // 0x80131E38: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    dbMenuMakeMenu(rdram, ctx);
        goto after_0;
    // 0x80131E38: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_0:
    // 0x80131E3C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80131E40: lhu         $v0, 0x5472($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5472);
L_80131E44:
    // 0x80131E44: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    // 0x80131E48: beq         $t8, $zero, L_80131E5C
    if (ctx->r24 == 0) {
        // 0x80131E4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80131E5C;
    }
    // 0x80131E4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E50: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80131E54: jal         0x80022368
    // 0x80131E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    syDebugMakeMeterCamera(rdram, ctx);
        goto after_1;
    // 0x80131E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80131E5C:
    // 0x80131E5C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131E60: lw          $t9, 0x3138($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3138);
    // 0x80131E64: beql        $t9, $zero, L_80131E94
    if (ctx->r25 == 0) {
        // 0x80131E68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80131E94;
    }
    goto skip_0;
    // 0x80131E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80131E6C: jal         0x80369EC0
    // 0x80131E70: nop

    dbMenuDestroyMenu(rdram, ctx);
        goto after_2;
    // 0x80131E70: nop

    after_2:
    // 0x80131E74: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80131E78: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80131E7C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80131E80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131E84: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80131E88: jal         0x80005C74
    // 0x80131E8C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80131E8C: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
    // 0x80131E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80131E94:
    // 0x80131E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131E98: jr          $ra
    // 0x80131E9C: nop

    return;
    // 0x80131E9C: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801570A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801570AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801570B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801570B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801570B8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801570BC: jal         0x800DEEC8
    // 0x801570C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801570C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801570C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801570C8: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x801570CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801570D0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801570D4: lw          $a3, 0x78($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X78);
    // 0x801570D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801570DC: jal         0x800E6F24
    // 0x801570E0: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801570E0: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_1:
    // 0x801570E4: jal         0x800D8EB8
    // 0x801570E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801570E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801570EC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x801570F0: addiu       $t9, $t9, 0x6E98
    ctx->r25 = ADD32(ctx->r25, 0X6E98);
    // 0x801570F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801570F8: sw          $t9, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r25;
    // 0x801570FC: sw          $t0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r8;
    // 0x80157100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80157104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80157108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015710C: jr          $ra
    // 0x80157110: nop

    return;
    // 0x80157110: nop

;}
RECOMP_FUNC void func_ovl8_8037EE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037EE00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037EE04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037EE08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037EE0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8037EE10: jal         0x803717A0
    // 0x8037EE14: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037EE14: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x8037EE18: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EE1C: beq         $v0, $zero, L_8037EE4C
    if (ctx->r2 == 0) {
        // 0x8037EE20: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037EE4C;
    }
    // 0x8037EE20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037EE24: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x8037EE28: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8037EE2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8037EE30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037EE34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037EE38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8037EE3C: jal         0x8037EF0C
    // 0x8037EE40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8037EF0C(rdram, ctx);
        goto after_1;
    // 0x8037EE40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x8037EE44: b           L_8037EE50
    // 0x8037EE48: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8037EE50;
    // 0x8037EE48: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8037EE4C:
    // 0x8037EE4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037EE50:
    // 0x8037EE50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037EE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037EE58: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037EE5C: jr          $ra
    // 0x8037EE60: nop

    return;
    // 0x8037EE60: nop

;}
RECOMP_FUNC void sc1PTrainingModeDamageDisplayProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E1F8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E1FC: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018E200: lbu         $v0, 0xD0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD0);
    // 0x8018E204: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018E208: beq         $v0, $zero, L_8018E214
    if (ctx->r2 == 0) {
        // 0x8018E20C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8018E214;
    }
    // 0x8018E20C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8018E210: sb          $t6, 0xD0($v1)
    MEM_B(0XD0, ctx->r3) = ctx->r14;
L_8018E214:
    // 0x8018E214: jr          $ra
    // 0x8018E218: nop

    return;
    // 0x8018E218: nop

;}
RECOMP_FUNC void gcEndProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B39C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B3A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B3A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B3A8: bne         $a0, $zero, L_8000B3B8
    if (ctx->r4 != 0) {
        // 0x8000B3AC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000B3B8;
    }
    // 0x8000B3AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B3B0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B3B4: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000B3B8:
    // 0x8000B3B8: lw          $s0, 0x18($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X18);
    // 0x8000B3BC: beql        $s0, $zero, L_8000B3DC
    if (ctx->r16 == 0) {
        // 0x8000B3C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B3DC;
    }
    goto skip_0;
    // 0x8000B3C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000B3C4:
    // 0x8000B3C4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000B3C8: jal         0x8000848C
    // 0x8000B3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndGObjProcess(rdram, ctx);
        goto after_0;
    // 0x8000B3CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000B3D0: bne         $s1, $zero, L_8000B3C4
    if (ctx->r17 != 0) {
        // 0x8000B3D4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000B3C4;
    }
    // 0x8000B3D4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000B3D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000B3DC:
    // 0x8000B3DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B3E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B3E4: jr          $ra
    // 0x8000B3E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000B3E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpNessPKThunderHeadMakeTrail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AE64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016AE68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AE6C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8016AE70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016AE74: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016AE78: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8016AE7C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8016AE80: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8016AE84: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8016AE88: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8016AE8C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8016AE90: jal         0x8016B580
    // 0x8016AE94: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    wpNessPKThunderTrailMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016AE94: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8016AE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AE9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016AEA0: jr          $ra
    // 0x8016AEA4: nop

    return;
    // 0x8016AEA4: nop

;}
RECOMP_FUNC void func_ovl8_803758E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803758E8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803758EC: lw          $t6, -0x1034($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1034);
    // 0x803758F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803758F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803758F8: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x803758FC: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80375900: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80375904: lh          $t7, 0xF0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XF0);
    // 0x80375908: jalr        $t9
    // 0x8037590C: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037590C: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x80375910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80375914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80375918: jr          $ra
    // 0x8037591C: nop

    return;
    // 0x8037591C: nop

;}
RECOMP_FUNC void func_ovl8_803865D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803865D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803865D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803865D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803865DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803865E0: jal         0x80381C80
    // 0x803865E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_80381C80(rdram, ctx);
        goto after_0;
    // 0x803865E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x803865E8: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x803865EC: addiu       $a3, $a3, 0x3D4
    ctx->r7 = ADD32(ctx->r7, 0X3D4);
    // 0x803865F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x803865F4: lw          $a2, 0xAC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XAC);
    // 0x803865F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x803865FC: lw          $v1, 0x30($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X30);
    // 0x80386600: lw          $t9, 0x10C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10C);
    // 0x80386604: lh          $t7, 0x108($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X108);
    // 0x80386608: jalr        $t9
    // 0x8038660C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8038660C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80386610: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80386614: addiu       $s0, $s0, 0x3D0
    ctx->r16 = ADD32(ctx->r16, 0X3D0);
    // 0x80386618: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8038661C:
    // 0x8038661C: jal         0x8000B1E8
    // 0x80386620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_2;
    // 0x80386620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80386624: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80386628: beq         $t0, $zero, L_8038661C
    if (ctx->r8 == 0) {
        // 0x8038662C: nop
    
            goto L_8038661C;
    }
    // 0x8038662C: nop

    // 0x80386630: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80386634: lw          $s0, 0x3D4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3D4);
    // 0x80386638: lw          $t1, 0xA8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XA8);
    // 0x8038663C: beq         $t1, $zero, L_80386670
    if (ctx->r9 == 0) {
        // 0x80386640: nop
    
            goto L_80386670;
    }
    // 0x80386640: nop

    // 0x80386644: lw          $a1, 0xAC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XAC);
    // 0x80386648: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x8038664C: lw          $t9, 0x114($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X114);
    // 0x80386650: lh          $t2, 0x110($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X110);
    // 0x80386654: jalr        $t9
    // 0x80386658: addu        $a0, $t2, $a1
    ctx->r4 = ADD32(ctx->r10, ctx->r5);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80386658: addu        $a0, $t2, $a1
    ctx->r4 = ADD32(ctx->r10, ctx->r5);
    after_3:
    // 0x8038665C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80386660: jal         0x80376FFC
    // 0x80386664: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    stringCopy(rdram, ctx);
        goto after_4;
    // 0x80386664: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80386668: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8038666C: lw          $s0, 0x3D4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3D4);
L_80386670:
    // 0x80386670: beql        $s0, $zero, L_8038669C
    if (ctx->r16 == 0) {
        // 0x80386674: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8038669C;
    }
    goto skip_0;
    // 0x80386674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80386678: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x8038667C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80386680: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80386684: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x80386688: jalr        $t9
    // 0x8038668C: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8038668C: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    after_5:
    // 0x80386690: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x80386694: lw          $s0, 0x3D4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X3D4);
    // 0x80386698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8038669C:
    // 0x8038669C: lw          $v0, 0xA8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA8);
    // 0x803866A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803866A4: jr          $ra
    // 0x803866A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x803866A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpNessPKThunderHeadProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B1E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B1F0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016B1F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016B1F8: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016B1FC: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016B200: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8016B204: jal         0x800FE068
    // 0x8016B208: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016B208: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016B20C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016B210: jal         0x8016AD30
    // 0x8016B214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_1;
    // 0x8016B214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8016B218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B21C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B224: jr          $ra
    // 0x8016B228: nop

    return;
    // 0x8016B228: nop

;}

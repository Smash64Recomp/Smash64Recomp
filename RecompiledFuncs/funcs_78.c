#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grWallpaperSectorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104998: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010499C: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x801049A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801049A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801049A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801049AC: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x801049B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801049B4: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    // 0x801049B8: jal         0x8001902C
    // 0x801049BC: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x801049BC: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    after_0:
    // 0x801049C0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801049C4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801049C8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801049CC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801049D0: nop

    // 0x801049D4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801049D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801049DC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801049E0: jal         0x80033510
    // 0x801049E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801049E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x801049E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801049EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801049F0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801049F4: nop

    // 0x801049F8: bc1fl       L_80104AB0
    if (!c1cs) {
        // 0x801049FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80104AB0;
    }
    goto skip_0;
    // 0x801049FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80104A00: lwc1        $f14, 0xA44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XA44);
    // 0x80104A04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104A08: lwc1        $f18, 0xA48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XA48);
    // 0x80104A0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104A10: lwc1        $f4, 0xA4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA4C);
    // 0x80104A14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80104A18: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80104A1C: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80104A20: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80104A24: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80104A28: bc1fl       L_80104A3C
    if (!c1cs) {
        // 0x80104A2C: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80104A3C;
    }
    goto skip_1;
    // 0x80104A2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x80104A30: b           L_80104A54
    // 0x80104A34: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80104A54;
    // 0x80104A34: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80104A38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80104A3C:
    // 0x80104A3C: nop

    // 0x80104A40: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80104A44: nop

    // 0x80104A48: bc1fl       L_80104A58
    if (!c1cs) {
        // 0x80104A4C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80104A58;
    }
    goto skip_2;
    // 0x80104A4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_2:
    // 0x80104A50: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80104A54:
    // 0x80104A54: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_80104A58:
    // 0x80104A58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80104A5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80104A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80104A64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80104A68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80104A6C: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80104A70: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80104A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80104A78: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80104A7C: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80104A80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80104A84: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80104A88: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80104A8C: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80104A90: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80104A94: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80104A98: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80104A9C: sub.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80104AA0: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80104AA4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80104AA8: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x80104AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80104AB0:
    // 0x80104AB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80104AB4: jr          $ra
    // 0x80104AB8: nop

    return;
    // 0x80104AB8: nop

;}
RECOMP_FUNC void itTaruBombContainerSmashUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184A78: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80184A7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80184A80: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80184A84: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x80184A88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80184A8C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80184A90: bne         $t7, $zero, L_80184AB0
    if (ctx->r15 != 0) {
        // 0x80184A94: sw          $t7, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r15;
            goto L_80184AB0;
    }
    // 0x80184A94: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x80184A98: jal         0x800FD4F8
    // 0x80184A9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x80184A9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80184AA0: jal         0x80009A84
    // 0x80184AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80184AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80184AA8: b           L_80184B38
    // 0x80184AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80184B38;
    // 0x80184AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80184AB0:
    // 0x80184AB0: beq         $v0, $zero, L_80184B34
    if (ctx->r2 == 0) {
        // 0x80184AB4: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80184B34;
    }
    // 0x80184AB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184AB8: lwc1        $f0, -0x30C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X30C0);
    // 0x80184ABC: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
L_80184AC0:
    // 0x80184AC0: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80184AC4: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80184AC8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80184ACC: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80184AD0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80184AD4: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x80184AD8: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80184ADC: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80184AE0: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80184AE4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80184AE8: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80184AEC: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80184AF0: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x80184AF4: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x80184AF8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80184AFC: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80184B00: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80184B04: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80184B08: lwc1        $f4, 0x7C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80184B0C: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80184B10: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x80184B14: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80184B18: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80184B1C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80184B20: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x80184B24: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x80184B28: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80184B2C: bnel        $v0, $zero, L_80184AC0
    if (ctx->r2 != 0) {
        // 0x80184B30: lwc1        $f4, 0x44($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
            goto L_80184AC0;
    }
    goto skip_0;
    // 0x80184B30: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    skip_0:
L_80184B34:
    // 0x80184B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80184B38:
    // 0x80184B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80184B3C: jr          $ra
    // 0x80184B40: nop

    return;
    // 0x80184B40: nop

;}
RECOMP_FUNC void mnMapsSetNamePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801326E0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801326E4: addiu       $t7, $t7, 0x4694
    ctx->r15 = ADD32(ctx->r15, 0X4694);
    // 0x801326E8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801326EC: addiu       $t0, $t7, 0x48
    ctx->r8 = ADD32(ctx->r15, 0X48);
    // 0x801326F0: addiu       $t6, $sp, 0x0
    ctx->r14 = ADD32(ctx->r29, 0X0);
L_801326F4:
    // 0x801326F4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801326F8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801326FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132700: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132704: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132708: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013270C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132710: bne         $t7, $t0, L_801326F4
    if (ctx->r15 != ctx->r8) {
        // 0x80132714: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801326F4;
    }
    // 0x80132714: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132718: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x8013271C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132720: lui         $at, 0x4344
    ctx->r1 = S32(0X4344 << 16);
    // 0x80132724: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013272C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80132730: jr          $ra
    // 0x80132734: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80132734: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void wpBossBulletHardMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016DE2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016DE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DE34: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016DE38: addiu       $a1, $a1, -0x6BEC
    ctx->r5 = ADD32(ctx->r5, -0X6BEC);
    // 0x8016DE3C: jal         0x801655C8
    // 0x8016DE40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016DE40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8016DE44: bne         $v0, $zero, L_8016DE54
    if (ctx->r2 != 0) {
        // 0x8016DE48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016DE54;
    }
    // 0x8016DE48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016DE4C: b           L_8016DE8C
    // 0x8016DE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016DE8C;
    // 0x8016DE50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016DE54:
    // 0x8016DE54: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016DE58: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8016DE5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016DE60: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8016DE64: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8016DE68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016DE6C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016DE70: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x8016DE74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016DE78: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016DE7C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8016DE80: jal         0x80168428
    // 0x8016DE84: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorRotateWeaponModel(rdram, ctx);
        goto after_1;
    // 0x8016DE84: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8016DE88: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8016DE8C:
    // 0x8016DE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016DE94: jr          $ra
    // 0x8016DE98: nop

    return;
    // 0x8016DE98: nop

;}
RECOMP_FUNC void itLinkBombExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018656C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80186570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80186574: jal         0x801864E8
    // 0x80186578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itLinkBombExplodeInitAttackColl(rdram, ctx);
        goto after_0;
    // 0x80186578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018657C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80186580: addiu       $a1, $a1, -0x490C
    ctx->r5 = ADD32(ctx->r5, -0X490C);
    // 0x80186584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80186588: jal         0x80172EC8
    // 0x8018658C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018658C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80186590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80186598: jr          $ra
    // 0x8018659C: nop

    return;
    // 0x8018659C: nop

;}
RECOMP_FUNC void ftKirbyThrowFProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014A434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A438: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014A43C: jal         0x800D9480
    // 0x8014A440: addiu       $a1, $a1, -0x5B58
    ctx->r5 = ADD32(ctx->r5, -0X5B58);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014A440: addiu       $a1, $a1, -0x5B58
    ctx->r5 = ADD32(ctx->r5, -0X5B58);
    after_0:
    // 0x8014A444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014A448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014A44C: jr          $ra
    // 0x8014A450: nop

    return;
    // 0x8014A450: nop

;}
RECOMP_FUNC void gcGetDObjTempAnimTimeMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E8A8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8000E8AC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8000E8B0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000E8B4: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8000E8B8: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8000E8BC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8000E8C0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000E8C4: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x8000E8C8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8000E8CC: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8000E8D0: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8000E8D4: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8000E8D8: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8000E8DC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8000E8E0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8000E8E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000E8E8: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    // 0x8000E8EC: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
    // 0x8000E8F0: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8000E8F4: beq         $a1, $zero, L_8000E908
    if (ctx->r5 == 0) {
        // 0x8000E8F8: swc1        $f22, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->f22.u32l;
            goto L_8000E908;
    }
    // 0x8000E8F8: swc1        $f22, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f22.u32l;
    // 0x8000E8FC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8000E900: bnel        $t6, $zero, L_8000E928
    if (ctx->r14 != 0) {
        // 0x8000E904: lw          $t7, 0x6C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X6C);
            goto L_8000E928;
    }
    goto skip_0;
    // 0x8000E904: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    skip_0:
L_8000E908:
    // 0x8000E908: bnel        $s5, $zero, L_8000E928
    if (ctx->r21 != 0) {
        // 0x8000E90C: lw          $t7, 0x6C($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X6C);
            goto L_8000E928;
    }
    goto skip_1;
    // 0x8000E90C: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    skip_1:
    // 0x8000E910: jal         0x80008EE4
    // 0x8000E914: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcRemoveAObjFromDObj(rdram, ctx);
        goto after_0;
    // 0x8000E914: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8000E918: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000E91C: b           L_8000EC34
    // 0x8000E920: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_8000EC34;
    // 0x8000E920: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8000E924: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
L_8000E928:
    // 0x8000E928: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x8000E92C: beq         $a1, $zero, L_8000E968
    if (ctx->r5 == 0) {
        // 0x8000E930: sw          $zero, 0x6C($s2)
        MEM_W(0X6C, ctx->r18) = 0;
            goto L_8000E968;
    }
    // 0x8000E930: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x8000E934: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000E938: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E93C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000E940: beql        $v0, $zero, L_8000E96C
    if (ctx->r2 == 0) {
        // 0x8000E944: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000E96C;
    }
    goto skip_2;
    // 0x8000E944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x8000E948: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
    // 0x8000E94C: lwc1        $f4, -0x2058($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2058);
    // 0x8000E950: swc1        $f12, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f12.u32l;
    // 0x8000E954: jal         0x8000BFE8
    // 0x8000E958: swc1        $f4, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f4.u32l;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8000E958: swc1        $f4, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f4.u32l;
    after_1:
    // 0x8000E95C: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x8000E960: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x8000E964: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
L_8000E968:
    // 0x8000E968: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000E96C:
    // 0x8000E96C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8000E970: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E974: lwc1        $f24, -0x2054($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2054);
    // 0x8000E978: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000E97C: lwc1        $f20, 0xDC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8000E980: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000E984: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8000E988: lw          $s1, 0xD8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD8);
    // 0x8000E98C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8000E990:
    // 0x8000E990: beq         $s0, $at, L_8000EBDC
    if (ctx->r16 == ctx->r1) {
        // 0x8000E994: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000EBDC;
    }
    // 0x8000E994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000E998: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8000E99C: addiu       $t0, $sp, 0x80
    ctx->r8 = ADD32(ctx->r29, 0X80);
    // 0x8000E9A0: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x8000E9A4: swc1        $f22, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f22.u32l;
    // 0x8000E9A8: swc1        $f22, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f22.u32l;
    // 0x8000E9AC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8000E9B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8000E9B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000E9B8: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x8000E9BC: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x8000E9C0: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x8000E9C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000E9C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000E9CC: jal         0x8000E164
    // 0x8000E9D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    gcCheckGetDObjNoAxisTrack(rdram, ctx);
        goto after_2;
    // 0x8000E9D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x8000E9D4: bne         $v0, $zero, L_8000EBDC
    if (ctx->r2 != 0) {
        // 0x8000E9D8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000EBDC;
    }
    // 0x8000E9D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000E9DC: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x8000E9E0: addiu       $t3, $sp, 0x8C
    ctx->r11 = ADD32(ctx->r29, 0X8C);
    // 0x8000E9E4: addiu       $t4, $sp, 0x9C
    ctx->r12 = ADD32(ctx->r29, 0X9C);
    // 0x8000E9E8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8000E9EC: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8000E9F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000E9F4: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    // 0x8000E9F8: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    // 0x8000E9FC: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x8000EA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000EA04: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000EA08: jal         0x8000E164
    // 0x8000EA0C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    gcCheckGetDObjNoAxisTrack(rdram, ctx);
        goto after_3;
    // 0x8000EA0C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_3:
    // 0x8000EA10: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000EA14: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8000EA18: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8000EA1C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8000EA20: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x8000EA24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000EA28: bc1f        L_8000EA40
    if (!c1cs) {
        // 0x8000EA2C: nop
    
            goto L_8000EA40;
    }
    // 0x8000EA2C: nop

    // 0x8000EA30: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8000EA34: nop

    // 0x8000EA38: bc1tl       L_8000EBE0
    if (c1cs) {
        // 0x8000EA3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8000EBE0;
    }
    goto skip_3;
    // 0x8000EA3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
L_8000EA40:
    // 0x8000EA40: jal         0x80008E78
    // 0x8000EA44: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_4;
    // 0x8000EA44: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_4:
    // 0x8000EA48: beq         $s0, $s4, L_8000EA60
    if (ctx->r16 == ctx->r20) {
        // 0x8000EA4C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000EA60;
    }
    // 0x8000EA4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000EA50: beq         $s0, $s3, L_8000EA60
    if (ctx->r16 == ctx->r19) {
        // 0x8000EA54: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000EA60;
    }
    // 0x8000EA54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000EA58: bne         $s0, $at, L_8000EB14
    if (ctx->r16 != ctx->r1) {
        // 0x8000EA5C: nop
    
            goto L_8000EB14;
    }
    // 0x8000EA5C: nop

L_8000EA60:
    // 0x8000EA60: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000EA64: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8000EA68: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8000EA6C: add.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8000EA70: bc1fl       L_8000EA88
    if (!c1cs) {
        // 0x8000EA74: sub.s       $f14, $f2, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
            goto L_8000EA88;
    }
    goto skip_4;
    // 0x8000EA74: sub.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
    skip_4:
    // 0x8000EA78: sub.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8000EA7C: b           L_8000EA8C
    // 0x8000EA80: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
        goto L_8000EA8C;
    // 0x8000EA80: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x8000EA84: sub.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
L_8000EA88:
    // 0x8000EA88: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_8000EA8C:
    // 0x8000EA8C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000EA90: nop

    // 0x8000EA94: bc1fl       L_8000EAAC
    if (!c1cs) {
        // 0x8000EA98: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8000EAAC;
    }
    goto skip_5;
    // 0x8000EA98: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_5:
    // 0x8000EA9C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000EAA0: b           L_8000EAAC
    // 0x8000EAA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8000EAAC;
    // 0x8000EAA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8000EAA8: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_8000EAAC:
    // 0x8000EAAC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8000EAB0: nop

    // 0x8000EAB4: bc1fl       L_8000EAC8
    if (!c1cs) {
        // 0x8000EAB8: c.lt.s      $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
            goto L_8000EAC8;
    }
    goto skip_6;
    // 0x8000EAB8: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    skip_6:
    // 0x8000EABC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x8000EAC0: sub.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000EAC4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
L_8000EAC8:
    // 0x8000EAC8: sub.s       $f0, $f18, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x8000EACC: bc1fl       L_8000EAE0
    if (!c1cs) {
        // 0x8000EAD0: mov.s       $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
            goto L_8000EAE0;
    }
    goto skip_7;
    // 0x8000EAD0: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    skip_7:
    // 0x8000EAD4: b           L_8000EAE0
    // 0x8000EAD8: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
        goto L_8000EAE0;
    // 0x8000EAD8: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x8000EADC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_8000EAE0:
    // 0x8000EAE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000EAE4: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x8000EAE8: bc1fl       L_8000EB00
    if (!c1cs) {
        // 0x8000EAEC: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8000EB00;
    }
    goto skip_8;
    // 0x8000EAEC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_8:
    // 0x8000EAF0: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000EAF4: b           L_8000EB00
    // 0x8000EAF8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8000EB00;
    // 0x8000EAF8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8000EAFC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_8000EB00:
    // 0x8000EB00: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8000EB04: nop

    // 0x8000EB08: bc1f        L_8000EB14
    if (!c1cs) {
        // 0x8000EB0C: nop
    
            goto L_8000EB14;
    }
    // 0x8000EB0C: nop

    // 0x8000EB10: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
L_8000EB14:
    // 0x8000EB14: beql        $s1, $zero, L_8000EB38
    if (ctx->r17 == 0) {
        // 0x8000EB18: div.s       $f6, $f26, $f20
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
            goto L_8000EB38;
    }
    goto skip_9;
    // 0x8000EB18: div.s       $f6, $f26, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
    skip_9:
    // 0x8000EB1C: beql        $s1, $s4, L_8000EB80
    if (ctx->r17 == ctx->r20) {
        // 0x8000EB20: div.s       $f8, $f26, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
            goto L_8000EB80;
    }
    goto skip_10;
    // 0x8000EB20: div.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
    skip_10:
    // 0x8000EB24: beql        $s1, $s3, L_8000EB80
    if (ctx->r17 == ctx->r19) {
        // 0x8000EB28: div.s       $f8, $f26, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
            goto L_8000EB80;
    }
    goto skip_11;
    // 0x8000EB28: div.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
    skip_11:
    // 0x8000EB2C: b           L_8000EBE0
    // 0x8000EB30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8000EBE0;
    // 0x8000EB30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000EB34: div.s       $f6, $f26, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
L_8000EB38:
    // 0x8000EB38: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8000EB3C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000EB40: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8000EB44: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000EB48: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
    // 0x8000EB4C: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x8000EB50: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000EB54: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x8000EB58: lwc1        $f8, 0x78($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8000EB5C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000EB60: swc1        $f22, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f22.u32l;
    // 0x8000EB64: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000EB68: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000EB6C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8000EB70: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000EB74: b           L_8000EBDC
    // 0x8000EB78: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
        goto L_8000EBDC;
    // 0x8000EB78: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x8000EB7C: div.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
L_8000EB80:
    // 0x8000EB80: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8000EB84: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000EB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000EB8C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8000EB90: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000EB94: sb          $t6, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r14;
    // 0x8000EB98: addiu       $t7, $sp, 0xA4
    ctx->r15 = ADD32(ctx->r29, 0XA4);
    // 0x8000EB9C: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8000EBA0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8000EBA4: lwc1        $f10, 0x78($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8000EBA8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8000EBAC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8000EBB0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8000EBB4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x8000EBB8: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8000EBBC: bne         $s1, $s3, L_8000EBDC
    if (ctx->r17 != ctx->r19) {
        // 0x8000EBC0: swc1        $f8, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
            goto L_8000EBDC;
    }
    // 0x8000EBC0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8000EBC4: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x8000EBC8: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    // 0x8000EBCC: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x8000EBD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000EBD4: jal         0x8000E428
    // 0x8000EBD8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    gcGetAObjTrackAnimTimeMax(rdram, ctx);
        goto after_5;
    // 0x8000EBD8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_5:
L_8000EBDC:
    // 0x8000EBDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8000EBE0:
    // 0x8000EBE0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8000EBE4: bnel        $s0, $at, L_8000E990
    if (ctx->r16 != ctx->r1) {
        // 0x8000EBE8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8000E990;
    }
    goto skip_12;
    // 0x8000EBE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_12:
    // 0x8000EBEC: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8000EBF0: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8000EBF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000EBF8: jal         0x80008EE4
    // 0x8000EBFC: sw          $t8, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r24;
    gcRemoveAObjFromDObj(rdram, ctx);
        goto after_6;
    // 0x8000EBFC: sw          $t8, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r24;
    after_6:
    // 0x8000EC00: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8000EC04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000EC08: jal         0x80008EE4
    // 0x8000EC0C: sw          $t9, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r25;
    gcRemoveAObjFromDObj(rdram, ctx);
        goto after_7;
    // 0x8000EC0C: sw          $t9, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r25;
    after_7:
    // 0x8000EC10: lwc1        $f2, 0x78($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8000EC14: sw          $s0, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r16;
    // 0x8000EC18: sw          $zero, 0x70($s2)
    MEM_W(0X70, ctx->r18) = 0;
    // 0x8000EC1C: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8000EC20: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x8000EC24: swc1        $f10, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f10.u32l;
    // 0x8000EC28: swc1        $f4, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->f4.u32l;
    // 0x8000EC2C: lwc1        $f0, 0xA4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8000EC30: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8000EC34:
    // 0x8000EC34: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000EC38: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8000EC3C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8000EC40: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8000EC44: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8000EC48: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8000EC4C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8000EC50: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8000EC54: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EC58: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8000EC5C: jr          $ra
    // 0x8000EC60: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8000EC60: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void mpCommonProcFighterDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEA20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DEA24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DEA28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DEA2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DEA30: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800DEA34: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800DEA38: lw          $s1, 0x84($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X84);
    // 0x800DEA3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DEA40: jal         0x800DB838
    // 0x800DEA44: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x800DEA44: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x800DEA48: beq         $v0, $zero, L_800DEAEC
    if (ctx->r2 == 0) {
        // 0x800DEA4C: nop
    
            goto L_800DEAEC;
    }
    // 0x800DEA4C: nop

    // 0x800DEA50: jal         0x800DBF58
    // 0x800DEA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x800DEA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800DEA58: lhu         $t7, 0xB26($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XB26);
    // 0x800DEA5C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800DEA60: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800DEA64: bnel        $t8, $zero, L_800DEAD4
    if (ctx->r24 != 0) {
        // 0x800DEA68: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEAD4;
    }
    goto skip_0;
    // 0x800DEA68: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_0:
    // 0x800DEA6C: jal         0x800C7A84
    // 0x800DEA70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_2;
    // 0x800DEA70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x800DEA74: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800DEA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DEA7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800DEA80: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DEA84: nop

    // 0x800DEA88: bc1fl       L_800DEAD4
    if (!c1cs) {
        // 0x800DEA8C: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEAD4;
    }
    goto skip_1;
    // 0x800DEA8C: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_1:
    // 0x800DEA90: jal         0x800191FC
    // 0x800DEA94: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_3;
    // 0x800DEA94: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    after_3:
    // 0x800DEA98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEA9C: lwc1        $f6, -0x498($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X498);
    // 0x800DEAA0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800DEAA4: nop

    // 0x800DEAA8: bc1fl       L_800DEAD4
    if (!c1cs) {
        // 0x800DEAAC: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEAD4;
    }
    goto skip_2;
    // 0x800DEAAC: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_2:
    // 0x800DEAB0: lhu         $t9, 0xB24($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XB24);
    // 0x800DEAB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DEAB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DEABC: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800DEAC0: sh          $t0, 0xB24($s1)
    MEM_H(0XB24, ctx->r17) = ctx->r8;
    // 0x800DEAC4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800DEAC8: b           L_800DEAEC
    // 0x800DEACC: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
        goto L_800DEAEC;
    // 0x800DEACC: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
    // 0x800DEAD0: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
L_800DEAD4:
    // 0x800DEAD4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800DEAD8: bne         $t4, $zero, L_800DEAEC
    if (ctx->r12 != 0) {
        // 0x800DEADC: nop
    
            goto L_800DEAEC;
    }
    // 0x800DEADC: nop

    // 0x800DEAE0: lhu         $t5, 0xB28($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XB28);
    // 0x800DEAE4: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800DEAE8: sh          $t6, 0xB28($s1)
    MEM_H(0XB28, ctx->r17) = ctx->r14;
L_800DEAEC:
    // 0x800DEAEC: jal         0x800DC3C8
    // 0x800DEAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x800DEAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800DEAF4: beq         $v0, $zero, L_800DEB98
    if (ctx->r2 == 0) {
        // 0x800DEAF8: nop
    
            goto L_800DEB98;
    }
    // 0x800DEAF8: nop

    // 0x800DEAFC: jal         0x800DCAE8
    // 0x800DEB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x800DEB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800DEB04: lhu         $t7, 0xB26($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XB26);
    // 0x800DEB08: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800DEB0C: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800DEB10: bnel        $t8, $zero, L_800DEB80
    if (ctx->r24 != 0) {
        // 0x800DEB14: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEB80;
    }
    goto skip_3;
    // 0x800DEB14: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_3:
    // 0x800DEB18: jal         0x800C7A84
    // 0x800DEB1C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_6;
    // 0x800DEB1C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x800DEB20: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800DEB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800DEB28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800DEB2C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800DEB30: nop

    // 0x800DEB34: bc1fl       L_800DEB80
    if (!c1cs) {
        // 0x800DEB38: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEB80;
    }
    goto skip_4;
    // 0x800DEB38: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_4:
    // 0x800DEB3C: jal         0x800191FC
    // 0x800DEB40: addiu       $a1, $s0, 0xBC
    ctx->r5 = ADD32(ctx->r16, 0XBC);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_7;
    // 0x800DEB40: addiu       $a1, $s0, 0xBC
    ctx->r5 = ADD32(ctx->r16, 0XBC);
    after_7:
    // 0x800DEB44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEB48: lwc1        $f10, -0x494($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X494);
    // 0x800DEB4C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800DEB50: nop

    // 0x800DEB54: bc1fl       L_800DEB80
    if (!c1cs) {
        // 0x800DEB58: lhu         $t3, 0x54($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEB80;
    }
    goto skip_5;
    // 0x800DEB58: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
    skip_5:
    // 0x800DEB5C: lhu         $t9, 0xB24($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XB24);
    // 0x800DEB60: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DEB64: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DEB68: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x800DEB6C: sh          $t0, 0xB24($s1)
    MEM_H(0XB24, ctx->r17) = ctx->r8;
    // 0x800DEB70: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800DEB74: b           L_800DEB98
    // 0x800DEB78: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
        goto L_800DEB98;
    // 0x800DEB78: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
    // 0x800DEB7C: lhu         $t3, 0x54($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X54);
L_800DEB80:
    // 0x800DEB80: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x800DEB84: bne         $t4, $zero, L_800DEB98
    if (ctx->r12 != 0) {
        // 0x800DEB88: nop
    
            goto L_800DEB98;
    }
    // 0x800DEB88: nop

    // 0x800DEB8C: lhu         $t5, 0xB28($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XB28);
    // 0x800DEB90: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x800DEB94: sh          $t6, 0xB28($s1)
    MEM_H(0XB28, ctx->r17) = ctx->r14;
L_800DEB98:
    // 0x800DEB98: jal         0x800DCF58
    // 0x800DEB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_8;
    // 0x800DEB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800DEBA0: beq         $v0, $zero, L_800DEC5C
    if (ctx->r2 == 0) {
        // 0x800DEBA4: nop
    
            goto L_800DEC5C;
    }
    // 0x800DEBA4: nop

    // 0x800DEBA8: jal         0x800DD160
    // 0x800DEBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_9;
    // 0x800DEBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800DEBB0: lhu         $t7, 0x5A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DEBB4: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x800DEBB8: beql        $t8, $zero, L_800DEBCC
    if (ctx->r24 == 0) {
        // 0x800DEBBC: lhu         $t9, 0xB26($s1)
        ctx->r25 = MEM_HU(ctx->r17, 0XB26);
            goto L_800DEBCC;
    }
    goto skip_6;
    // 0x800DEBBC: lhu         $t9, 0xB26($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XB26);
    skip_6:
    // 0x800DEBC0: jal         0x800D99B8
    // 0x800DEBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_10;
    // 0x800DEBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800DEBC8: lhu         $t9, 0xB26($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XB26);
L_800DEBCC:
    // 0x800DEBCC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800DEBD0: andi        $t0, $t9, 0x400
    ctx->r8 = ctx->r25 & 0X400;
    // 0x800DEBD4: bnel        $t0, $zero, L_800DEC44
    if (ctx->r8 != 0) {
        // 0x800DEBD8: lhu         $t5, 0x54($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEC44;
    }
    goto skip_7;
    // 0x800DEBD8: lhu         $t5, 0x54($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X54);
    skip_7:
    // 0x800DEBDC: jal         0x800C7A84
    // 0x800DEBE0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_11;
    // 0x800DEBE0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_11:
    // 0x800DEBE4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800DEBE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DEBEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800DEBF0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800DEBF4: nop

    // 0x800DEBF8: bc1fl       L_800DEC44
    if (!c1cs) {
        // 0x800DEBFC: lhu         $t5, 0x54($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEC44;
    }
    goto skip_8;
    // 0x800DEBFC: lhu         $t5, 0x54($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X54);
    skip_8:
    // 0x800DEC00: jal         0x800191FC
    // 0x800DEC04: addiu       $a1, $s0, 0x94
    ctx->r5 = ADD32(ctx->r16, 0X94);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_12;
    // 0x800DEC04: addiu       $a1, $s0, 0x94
    ctx->r5 = ADD32(ctx->r16, 0X94);
    after_12:
    // 0x800DEC08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEC0C: lwc1        $f18, -0x490($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X490);
    // 0x800DEC10: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800DEC14: nop

    // 0x800DEC18: bc1fl       L_800DEC44
    if (!c1cs) {
        // 0x800DEC1C: lhu         $t5, 0x54($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X54);
            goto L_800DEC44;
    }
    goto skip_9;
    // 0x800DEC1C: lhu         $t5, 0x54($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X54);
    skip_9:
    // 0x800DEC20: lhu         $t1, 0xB24($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XB24);
    // 0x800DEC24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DEC28: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DEC2C: ori         $t2, $t1, 0x400
    ctx->r10 = ctx->r9 | 0X400;
    // 0x800DEC30: sh          $t2, 0xB24($s1)
    MEM_H(0XB24, ctx->r17) = ctx->r10;
    // 0x800DEC34: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800DEC38: b           L_800DEC5C
    // 0x800DEC3C: sw          $t4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r12;
        goto L_800DEC5C;
    // 0x800DEC3C: sw          $t4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r12;
    // 0x800DEC40: lhu         $t5, 0x54($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X54);
L_800DEC44:
    // 0x800DEC44: andi        $t6, $t5, 0x400
    ctx->r14 = ctx->r13 & 0X400;
    // 0x800DEC48: bne         $t6, $zero, L_800DEC5C
    if (ctx->r14 != 0) {
        // 0x800DEC4C: nop
    
            goto L_800DEC5C;
    }
    // 0x800DEC4C: nop

    // 0x800DEC50: lhu         $t7, 0xB28($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XB28);
    // 0x800DEC54: ori         $t8, $t7, 0x400
    ctx->r24 = ctx->r15 | 0X400;
    // 0x800DEC58: sh          $t8, 0xB28($s1)
    MEM_H(0XB28, ctx->r17) = ctx->r24;
L_800DEC5C:
    // 0x800DEC5C: jal         0x800DD578
    // 0x800DEC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_13;
    // 0x800DEC60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800DEC64: beq         $v0, $zero, L_800DED8C
    if (ctx->r2 == 0) {
        // 0x800DEC68: nop
    
            goto L_800DED8C;
    }
    // 0x800DEC68: nop

    // 0x800DEC6C: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x800DEC70: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800DEC74: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x800DEC78: beq         $t9, $zero, L_800DECB8
    if (ctx->r25 == 0) {
        // 0x800DEC7C: nop
    
            goto L_800DECB8;
    }
    // 0x800DEC7C: nop

    // 0x800DEC80: jal         0x800DD6A8
    // 0x800DEC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollideFloor(rdram, ctx);
        goto after_14;
    // 0x800DEC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800DEC88: lhu         $t0, 0x5A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DEC8C: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x800DEC90: beq         $t1, $zero, L_800DECA8
    if (ctx->r9 == 0) {
        // 0x800DEC94: nop
    
            goto L_800DECA8;
    }
    // 0x800DEC94: nop

    // 0x800DEC98: jal         0x800D9F84
    // 0x800DEC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_15;
    // 0x800DEC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800DECA0: b           L_800DED98
    // 0x800DECA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DED98;
    // 0x800DECA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DECA8:
    // 0x800DECA8: jal         0x800D9FCC
    // 0x800DECAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_16;
    // 0x800DECAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800DECB0: b           L_800DED98
    // 0x800DECB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DED98;
    // 0x800DECB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DECB8:
    // 0x800DECB8: jal         0x800191FC
    // 0x800DECBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_17;
    // 0x800DECBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_17:
    // 0x800DECC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DECC4: lwc1        $f4, -0x48C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X48C);
    // 0x800DECC8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DECCC: nop

    // 0x800DECD0: bc1f        L_800DED20
    if (!c1cs) {
        // 0x800DECD4: nop
    
            goto L_800DED20;
    }
    // 0x800DECD4: nop

    // 0x800DECD8: jal         0x800DD59C
    // 0x800DECDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_18;
    // 0x800DECDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800DECE0: jal         0x800DE368
    // 0x800DECE4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    mpCommonSetFighterLandingParams(rdram, ctx);
        goto after_19;
    // 0x800DECE4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_19:
    // 0x800DECE8: lhu         $t2, 0x5A($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DECEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DECF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DECF4: andi        $t3, $t2, 0x800
    ctx->r11 = ctx->r10 & 0X800;
    // 0x800DECF8: beql        $t3, $zero, L_800DED98
    if (ctx->r11 == 0) {
        // 0x800DECFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DED98;
    }
    goto skip_10;
    // 0x800DECFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x800DED00: jal         0x800D9F84
    // 0x800DED04: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_20;
    // 0x800DED04: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_20:
    // 0x800DED08: lhu         $t5, 0xB24($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XB24);
    // 0x800DED0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DED10: ori         $t6, $t5, 0x800
    ctx->r14 = ctx->r13 | 0X800;
    // 0x800DED14: sh          $t6, 0xB24($s1)
    MEM_H(0XB24, ctx->r17) = ctx->r14;
    // 0x800DED18: b           L_800DED94
    // 0x800DED1C: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
        goto L_800DED94;
    // 0x800DED1C: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_800DED20:
    // 0x800DED20: jal         0x800DD6A8
    // 0x800DED24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollideFloor(rdram, ctx);
        goto after_21;
    // 0x800DED24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800DED28: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DED2C: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x800DED30: beq         $t9, $zero, L_800DED7C
    if (ctx->r25 == 0) {
        // 0x800DED34: nop
    
            goto L_800DED7C;
    }
    // 0x800DED34: nop

    // 0x800DED38: jal         0x800D9F84
    // 0x800DED3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_22;
    // 0x800DED3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800DED40: lhu         $t0, 0x54($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X54);
    // 0x800DED44: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x800DED48: bnel        $t1, $zero, L_800DED98
    if (ctx->r9 != 0) {
        // 0x800DED4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DED98;
    }
    goto skip_11;
    // 0x800DED4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x800DED50: lhu         $t2, 0xB28($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XB28);
    // 0x800DED54: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x800DED58: sh          $t3, 0xB28($s1)
    MEM_H(0XB28, ctx->r17) = ctx->r11;
    // 0x800DED5C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800DED60: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800DED64: sw          $t6, 0xB2C($s1)
    MEM_W(0XB2C, ctx->r17) = ctx->r14;
    // 0x800DED68: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800DED6C: sw          $t5, 0xB30($s1)
    MEM_W(0XB30, ctx->r17) = ctx->r13;
    // 0x800DED70: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x800DED74: b           L_800DED94
    // 0x800DED78: sw          $t6, 0xB34($s1)
    MEM_W(0XB34, ctx->r17) = ctx->r14;
        goto L_800DED94;
    // 0x800DED78: sw          $t6, 0xB34($s1)
    MEM_W(0XB34, ctx->r17) = ctx->r14;
L_800DED7C:
    // 0x800DED7C: jal         0x800D9FCC
    // 0x800DED80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_23;
    // 0x800DED80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x800DED84: b           L_800DED98
    // 0x800DED88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DED98;
    // 0x800DED88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DED8C:
    // 0x800DED8C: jal         0x800D9FCC
    // 0x800DED90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_24;
    // 0x800DED90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_800DED94:
    // 0x800DED94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DED98:
    // 0x800DED98: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800DED9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DEDA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DEDA4: jr          $ra
    // 0x800DEDA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800DEDA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_8037CD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CD64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037CD68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CD6C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8037CD70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037CD74: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037CD78: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8037CD7C: nop

    // 0x8037CD80: bc1tl       L_8037CDAC
    if (c1cs) {
        // 0x8037CD84: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_8037CDAC;
    }
    goto skip_0;
    // 0x8037CD84: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_0:
    // 0x8037CD88: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x8037CD8C: beql        $v0, $zero, L_8037CDA0
    if (ctx->r2 == 0) {
        // 0x8037CD90: lw          $v1, 0x44($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X44);
            goto L_8037CDA0;
    }
    goto skip_1;
    // 0x8037CD90: lw          $v1, 0x44($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X44);
    skip_1:
    // 0x8037CD94: b           L_8037CDAC
    // 0x8037CD98: nop

        goto L_8037CDAC;
    // 0x8037CD98: nop

    // 0x8037CD9C: lw          $v1, 0x44($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X44);
L_8037CDA0:
    // 0x8037CDA0: b           L_8037CDAC
    // 0x8037CDA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8037CDAC;
    // 0x8037CDA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037CDA8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_8037CDAC:
    // 0x8037CDAC: beq         $v0, $zero, L_8037CE20
    if (ctx->r2 == 0) {
        // 0x8037CDB0: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_8037CE20;
    }
    // 0x8037CDB0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8037CDB4: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x8037CDB8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037CDBC: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037CDC0: lh          $t6, 0xA8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA8);
    // 0x8037CDC4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037CDC8: lw          $t9, 0xAC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XAC);
    // 0x8037CDCC: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x8037CDD0: jalr        $t9
    // 0x8037CDD4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037CDD4: nop

    after_0:
    // 0x8037CDD8: lh          $t7, 0x28($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X28);
    // 0x8037CDDC: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8037CDE0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8037CDE4: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
    // 0x8037CDE8: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // 0x8037CDEC: sh          $t7, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r15;
    // 0x8037CDF0: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x8037CDF4: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x8037CDF8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037CDFC: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x8037CE00: lh          $t0, 0xB8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB8);
    // 0x8037CE04: jalr        $t9
    // 0x8037CE08: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037CE08: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    after_1:
    // 0x8037CE0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8037CE10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8037CE14: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8037CE18: jal         0x803787C0
    // 0x8037CE1C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_ovl8_803787C0(rdram, ctx);
        goto after_2;
    // 0x8037CE1C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
L_8037CE20:
    // 0x8037CE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037CE24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037CE28: jr          $ra
    // 0x8037CE2C: nop

    return;
    // 0x8037CE2C: nop

;}
RECOMP_FUNC void sc1PBonusStageInitPlatforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D6A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018D6AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D6B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D6B4: jal         0x800FC72C
    // 0x8018D6B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    mpCollisionSetDObjNoID(rdram, ctx);
        goto after_0;
    // 0x8018D6B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D6BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018D6C0: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x8018D6C4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8018D6C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018D6CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D6D0: jal         0x8018D62C
    // 0x8018D6D4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    sc1PBonusStageGetPlatformKind(rdram, ctx);
        goto after_1;
    // 0x8018D6D4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8018D6D8: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8018D6DC: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D6E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018D6E4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8018D6E8: lw          $t1, 0x13F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X13F4);
    // 0x8018D6EC: lw          $t0, -0x104C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X104C);
    // 0x8018D6F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8018D6F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D6F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D6FC: addiu       $a3, $zero, 0x44
    ctx->r7 = ADD32(0, 0X44);
    // 0x8018D700: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D704: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018D708: jal         0x800C8B28
    // 0x8018D70C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonSetupTreeDObjs(rdram, ctx);
        goto after_2;
    // 0x8018D70C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x8018D710: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8018D714: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018D718: addiu       $t4, $t4, -0x104C
    ctx->r12 = ADD32(ctx->r12, -0X104C);
    // 0x8018D71C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8018D720: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8018D724: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018D728: lw          $t6, 0x13F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13F4);
    // 0x8018D72C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8018D730: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x8018D734: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8018D738: jal         0x800C9228
    // 0x8018D73C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonAddMObjForTreeDObjs(rdram, ctx);
        goto after_3;
    // 0x8018D73C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x8018D740: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D744: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018D748: lw          $v0, 0x13F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13F4);
    // 0x8018D74C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8018D750: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8018D754: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x8018D758: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018D75C: addu        $a1, $t7, $v0
    ctx->r5 = ADD32(ctx->r15, ctx->r2);
    // 0x8018D760: jal         0x800C88AC
    // 0x8018D764: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_4;
    // 0x8018D764: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    after_4:
    // 0x8018D768: jal         0x800C92C8
    // 0x8018D76C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    lbCommonPlayTreeDObjsAnim(rdram, ctx);
        goto after_5;
    // 0x8018D76C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_5:
    // 0x8018D770: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8018D774: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x8018D778: ori         $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 | 0X8000;
    // 0x8018D77C: sw          $t0, 0x84($t1)
    MEM_W(0X84, ctx->r9) = ctx->r8;
    // 0x8018D780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D784: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D788: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018D78C: jr          $ra
    // 0x8018D790: nop

    return;
    // 0x8018D790: nop

;}
RECOMP_FUNC void wpBossBulletProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DD7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016DD80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DD84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016DD88: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016DD8C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8016DD90: jal         0x801680EC
    // 0x8016DD94: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016DD94: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    after_0:
    // 0x8016DD98: jal         0x80168428
    // 0x8016DD9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainReflectorRotateWeaponModel(rdram, ctx);
        goto after_1;
    // 0x8016DD9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016DDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DDA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016DDA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016DDAC: jr          $ra
    // 0x8016DDB0: nop

    return;
    // 0x8016DDB0: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E68C: jal         0x800DEEC8
    // 0x8015E690: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015E690: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015E694: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E698: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015E69C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8015E6A0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E6A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015E6A8: jal         0x800E6F24
    // 0x8015E6AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E6AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015E6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E6B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E6B8: jr          $ra
    // 0x8015E6BC: nop

    return;
    // 0x8015E6BC: nop

;}
RECOMP_FUNC void ftCommonGuardProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148D4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80148D54: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80148D58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80148D5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80148D60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80148D64: jal         0x80148120
    // 0x80148D68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftCommonGuardCheckScheduleRelease(rdram, ctx);
        goto after_0;
    // 0x80148D68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80148D6C: jal         0x80148304
    // 0x80148D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonGuardUpdateShieldVars(rdram, ctx);
        goto after_1;
    // 0x80148D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80148D74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80148D78: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80148D7C: lw          $t6, 0x34($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X34);
    // 0x80148D80: bnel        $t6, $zero, L_80148D9C
    if (ctx->r14 != 0) {
        // 0x80148D84: lw          $t7, 0xB24($a1)
        ctx->r15 = MEM_W(ctx->r5, 0XB24);
            goto L_80148D9C;
    }
    goto skip_0;
    // 0x80148D84: lw          $t7, 0xB24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB24);
    skip_0:
    // 0x80148D88: jal         0x80149510
    // 0x80148D8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonShieldBreakFlyCommonSetStatus(rdram, ctx);
        goto after_2;
    // 0x80148D8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80148D90: b           L_80148DD0
    // 0x80148D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148DD0;
    // 0x80148D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80148D98: lw          $t7, 0xB24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XB24);
L_80148D9C:
    // 0x80148D9C: bne         $t7, $zero, L_80148DB4
    if (ctx->r15 != 0) {
        // 0x80148DA0: nop
    
            goto L_80148DB4;
    }
    // 0x80148DA0: nop

    // 0x80148DA4: lw          $t8, 0x18C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18C);
    // 0x80148DA8: sll         $t0, $t8, 26
    ctx->r8 = S32(ctx->r24 << 26);
    // 0x80148DAC: bltz        $t0, L_80148DC4
    if (SIGNED(ctx->r8) < 0) {
        // 0x80148DB0: nop
    
            goto L_80148DC4;
    }
    // 0x80148DB0: nop

L_80148DB4:
    // 0x80148DB4: jal         0x80148FF0
    // 0x80148DB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonGuardOffSetStatus(rdram, ctx);
        goto after_3;
    // 0x80148DB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80148DBC: b           L_80148DD0
    // 0x80148DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80148DD0;
    // 0x80148DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148DC4:
    // 0x80148DC4: jal         0x8014889C
    // 0x80148DC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonGuardInitJoints(rdram, ctx);
        goto after_4;
    // 0x80148DC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80148DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80148DD0:
    // 0x80148DD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80148DD4: jr          $ra
    // 0x80148DD8: nop

    return;
    // 0x80148DD8: nop

;}
RECOMP_FUNC void __sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800303F0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800303F4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800303F8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800303FC: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80030400: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80030404: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80030408: beq         $at, $zero, L_80030470
    if (ctx->r1 == 0) {
        // 0x8003040C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80030470;
    }
    // 0x8003040C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80030410: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x80030414: bne         $at, $zero, L_80030468
    if (ctx->r1 != 0) {
        // 0x80030418: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_80030468;
    }
    // 0x80030418: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8003041C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80030420: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80030424: addiu       $v1, $v1, -0xEA0
    ctx->r3 = ADD32(ctx->r3, -0XEA0);
    // 0x80030428: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x8003042C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x80030430: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x80030434: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80030438: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8003043C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x80030440: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x80030444: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80030448: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8003044C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x80030450: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80030454: nop

    // 0x80030458: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x8003045C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x80030460: jr          $ra
    // 0x80030464: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x80030464: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_80030468:
    // 0x80030468: jr          $ra
    // 0x8003046C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x8003046C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_80030470:
    // 0x80030470: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x80030474: beq         $at, $zero, L_80030588
    if (ctx->r1 == 0) {
        // 0x80030478: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80030588;
    }
    // 0x80030478: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8003047C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80030480: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80030484: ldc1        $f10, -0xE78($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0XE78);
    // 0x80030488: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x8003048C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80030490: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80030494: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80030498: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003049C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800304A0: nop

    // 0x800304A4: bc1fl       L_800304D4
    if (!c1cs) {
        // 0x800304A8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800304D4;
    }
    goto skip_0;
    // 0x800304A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800304AC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800304B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800304B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800304B8: nop

    // 0x800304BC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800304C0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800304C4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800304C8: b           L_800304F0
    // 0x800304CC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800304F0;
    // 0x800304CC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800304D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800304D4:
    // 0x800304D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800304D8: nop

    // 0x800304DC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800304E0: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800304E4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800304E8: nop

    // 0x800304EC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800304F0:
    // 0x800304F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800304F4: ldc1        $f18, -0xE70($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0XE70);
    // 0x800304F8: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800304FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80030500: ldc1        $f6, -0xE68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0XE68);
    // 0x80030504: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80030508: addiu       $v1, $v1, -0xEA0
    ctx->r3 = ADD32(ctx->r3, -0XEA0);
    // 0x8003050C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80030510: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x80030514: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x80030518: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8003051C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80030520: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80030524: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x80030528: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x8003052C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80030530: nop

    // 0x80030534: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80030538: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8003053C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x80030540: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x80030544: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80030548: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x8003054C: bne         $t9, $zero, L_8003056C
    if (ctx->r25 != 0) {
        // 0x80030550: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_8003056C;
    }
    // 0x80030550: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x80030554: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80030558: nop

    // 0x8003055C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x80030560: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x80030564: jr          $ra
    // 0x80030568: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80030568: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003056C:
    // 0x8003056C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80030570: nop

    // 0x80030574: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80030578: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x8003057C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80030580: jr          $ra
    // 0x80030584: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80030584: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80030588:
    // 0x80030588: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x8003058C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80030590: bc1t        L_800305A4
    if (c1cs) {
        // 0x80030594: nop
    
            goto L_800305A4;
    }
    // 0x80030594: nop

    // 0x80030598: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003059C: jr          $ra
    // 0x800305A0: lwc1        $f0, -0xC90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC90);
    return;
    // 0x800305A0: lwc1        $f0, -0xC90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC90);
L_800305A4:
    // 0x800305A4: lwc1        $f0, -0xE60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XE60);
    // 0x800305A8: jr          $ra
    // 0x800305AC: nop

    return;
    // 0x800305AC: nop

;}
RECOMP_FUNC void ftCommonAttackDashSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014F674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F678: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014F67C: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8014F680: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014F684: jal         0x800E6F24
    // 0x8014F688: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F688: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8014F68C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014F694: jr          $ra
    // 0x8014F698: nop

    return;
    // 0x8014F698: nop

;}
RECOMP_FUNC void lbRelocLoadAndRelocFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD854: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800CD858: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CD85C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800CD860: addiu       $s1, $s1, 0x6334
    ctx->r17 = ADD32(ctx->r17, 0X6334);
    // 0x800CD864: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800CD868: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CD86C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800CD870: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800CD874: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800CD878: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800CD87C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CD880: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CD884: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CD888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CD88C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800CD890: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CD894: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800CD898: lw          $t7, 0x62E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62E8);
    // 0x800CD89C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CD8A0: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800CD8A4: srl         $t9, $v0, 31
    ctx->r25 = S32(U32(ctx->r2) >> 31);
    // 0x800CD8A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CD8AC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800CD8B0: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800CD8B4: beq         $t9, $zero, L_800CD8CC
    if (ctx->r25 == 0) {
        // 0x800CD8B8: addu        $s4, $t7, $t8
        ctx->r20 = ADD32(ctx->r15, ctx->r24);
            goto L_800CD8CC;
    }
    // 0x800CD8B8: addu        $s4, $t7, $t8
    ctx->r20 = ADD32(ctx->r15, ctx->r24);
    // 0x800CD8BC: jal         0x80003690
    // 0x800CD8C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    syDmaReadVpk0(rdram, ctx);
        goto after_0;
    // 0x800CD8C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800CD8C4: b           L_800CD8DC
    // 0x800CD8C8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
        goto L_800CD8DC;
    // 0x800CD8C8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_800CD8CC:
    // 0x800CD8CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800CD8D0: jal         0x80002CA0
    // 0x800CD8D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    syDmaReadRom(rdram, ctx);
        goto after_1;
    // 0x800CD8D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x800CD8D8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_800CD8DC:
    // 0x800CD8DC: bne         $s2, $s7, L_800CD8F8
    if (ctx->r18 != ctx->r23) {
        // 0x800CD8E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CD8F8;
    }
    // 0x800CD8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD8E8: jal         0x800CD798
    // 0x800CD8EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    lbRelocAddForceStatusBufferFile(rdram, ctx);
        goto after_2;
    // 0x800CD8EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x800CD8F0: b           L_800CD904
    // 0x800CD8F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_800CD904;
    // 0x800CD8F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800CD8F8:
    // 0x800CD8F8: jal         0x800CD71C
    // 0x800CD8FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    lbRelocAddStatusBufferFile(rdram, ctx);
        goto after_3;
    // 0x800CD8FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x800CD900: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800CD904:
    // 0x800CD904: or          $s0, $sp, $zero
    ctx->r16 = ctx->r29 | 0;
    // 0x800CD908: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x800CD90C: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x800CD910: addiu       $s0, $s0, 0x63
    ctx->r16 = ADD32(ctx->r16, 0X63);
    // 0x800CD914: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CD918: beq         $s6, $a0, L_800CD948
    if (ctx->r22 == ctx->r4) {
        // 0x800CD91C: and         $s0, $s0, $at
        ctx->r16 = ctx->r16 & ctx->r1;
            goto L_800CD948;
    }
    // 0x800CD91C: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
L_800CD920:
    // 0x800CD920: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x800CD924: addu        $v1, $s5, $t0
    ctx->r3 = ADD32(ctx->r21, ctx->r8);
    // 0x800CD928: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    // 0x800CD92C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x800CD930: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800CD934: addu        $t3, $t2, $s5
    ctx->r11 = ADD32(ctx->r10, ctx->r21);
    // 0x800CD938: bne         $s6, $a0, L_800CD920
    if (ctx->r22 != ctx->r4) {
        // 0x800CD93C: sw          $t3, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r11;
            goto L_800CD920;
    }
    // 0x800CD93C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800CD940: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CD944: lw          $v0, 0x6334($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6334);
L_800CD948:
    // 0x800CD948: lhu         $t4, 0x6($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X6);
    // 0x800CD94C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x800CD950: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800CD954: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800CD958: beq         $s6, $v1, L_800CDA08
    if (ctx->r22 == ctx->r3) {
        // 0x800CD95C: addu        $s4, $s4, $t5
        ctx->r20 = ADD32(ctx->r20, ctx->r13);
            goto L_800CDA08;
    }
    // 0x800CD95C: addu        $s4, $s4, $t5
    ctx->r20 = ADD32(ctx->r20, ctx->r13);
L_800CD960:
    // 0x800CD960: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800CD964: addu        $s1, $s5, $t6
    ctx->r17 = ADD32(ctx->r21, ctx->r14);
    // 0x800CD968: lhu         $s3, 0x0($s1)
    ctx->r19 = MEM_HU(ctx->r17, 0X0);
    // 0x800CD96C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800CD970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CD974: jal         0x80002CA0
    // 0x800CD978: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    syDmaReadRom(rdram, ctx);
        goto after_4;
    // 0x800CD978: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x800CD97C: bne         $s2, $s7, L_800CD994
    if (ctx->r18 != ctx->r23) {
        // 0x800CD980: nop
    
            goto L_800CD994;
    }
    // 0x800CD980: nop

    // 0x800CD984: jal         0x800CD698
    // 0x800CD988: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    lbRelocFindForceStatusBufferFile(rdram, ctx);
        goto after_5;
    // 0x800CD988: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_5:
    // 0x800CD98C: b           L_800CD99C
    // 0x800CD990: nop

        goto L_800CD99C;
    // 0x800CD990: nop

L_800CD994:
    // 0x800CD994: jal         0x800CD620
    // 0x800CD998: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_6;
    // 0x800CD998: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_6:
L_800CD99C:
    // 0x800CD99C: bnel        $v0, $zero, L_800CD9F0
    if (ctx->r2 != 0) {
        // 0x800CD9A0: lhu         $t7, 0x2($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X2);
            goto L_800CD9F0;
    }
    goto skip_0;
    // 0x800CD9A0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
    skip_0:
    // 0x800CD9A4: beq         $s2, $zero, L_800CD9C4
    if (ctx->r18 == 0) {
        // 0x800CD9A8: nop
    
            goto L_800CD9C4;
    }
    // 0x800CD9A8: nop

    // 0x800CD9AC: beq         $s2, $fp, L_800CD9D4
    if (ctx->r18 == ctx->r30) {
        // 0x800CD9B0: nop
    
            goto L_800CD9D4;
    }
    // 0x800CD9B0: nop

    // 0x800CD9B4: beq         $s2, $s7, L_800CD9E4
    if (ctx->r18 == ctx->r23) {
        // 0x800CD9B8: nop
    
            goto L_800CD9E4;
    }
    // 0x800CD9B8: nop

    // 0x800CD9BC: b           L_800CD9F0
    // 0x800CD9C0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
        goto L_800CD9F0;
    // 0x800CD9C0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_800CD9C4:
    // 0x800CD9C4: jal         0x800CDC0C
    // 0x800CD9C8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    lbRelocGetExternBufferFile(rdram, ctx);
        goto after_7;
    // 0x800CD9C8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_7:
    // 0x800CD9CC: b           L_800CD9F0
    // 0x800CD9D0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
        goto L_800CD9F0;
    // 0x800CD9D0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_800CD9D4:
    // 0x800CD9D4: jal         0x800CDCAC
    // 0x800CD9D8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    lbRelocGetInternBufferFile(rdram, ctx);
        goto after_8;
    // 0x800CD9D8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_8:
    // 0x800CD9DC: b           L_800CD9F0
    // 0x800CD9E0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
        goto L_800CD9F0;
    // 0x800CD9E0: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_800CD9E4:
    // 0x800CD9E4: jal         0x800CDD5C
    // 0x800CD9E8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    lbRelocGetForceExternBufferFile(rdram, ctx);
        goto after_9;
    // 0x800CD9E8: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_9:
    // 0x800CD9EC: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_800CD9F0:
    // 0x800CD9F0: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x800CD9F4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800CD9F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CD9FC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800CDA00: bne         $s6, $s3, L_800CD960
    if (ctx->r22 != ctx->r19) {
        // 0x800CDA04: sw          $t9, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r25;
            goto L_800CD960;
    }
    // 0x800CDA04: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800CDA08:
    // 0x800CDA08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CDA0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CDA10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDA14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CDA18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CDA1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CDA20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800CDA24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800CDA28: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800CDA2C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800CDA30: jr          $ra
    // 0x800CDA34: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800CDA34: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void ftCommonAppearUpdateEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DA14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013DA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DA1C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013DA20: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x8013DA24: beql        $t6, $zero, L_8013DA6C
    if (ctx->r14 == 0) {
        // 0x8013DA28: lw          $t7, 0x184($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X184);
            goto L_8013DA6C;
    }
    goto skip_0;
    // 0x8013DA28: lw          $t7, 0x184($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X184);
    skip_0:
    // 0x8013DA2C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8013DA30: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8013DA34: addiu       $a0, $v1, 0x854
    ctx->r4 = ADD32(ctx->r3, 0X854);
    // 0x8013DA38: beq         $v0, $at, L_8013DA58
    if (ctx->r2 == ctx->r1) {
        // 0x8013DA3C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8013DA58;
    }
    // 0x8013DA3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013DA40: beq         $v0, $at, L_8013DA58
    if (ctx->r2 == ctx->r1) {
        // 0x8013DA44: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8013DA58;
    }
    // 0x8013DA44: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8013DA48: beq         $v0, $at, L_8013DA58
    if (ctx->r2 == ctx->r1) {
        // 0x8013DA4C: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8013DA58;
    }
    // 0x8013DA4C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8013DA50: bnel        $v0, $at, L_8013DA68
    if (ctx->r2 != ctx->r1) {
        // 0x8013DA54: sw          $zero, 0x180($v1)
        MEM_W(0X180, ctx->r3) = 0;
            goto L_8013DA68;
    }
    goto skip_1;
    // 0x8013DA54: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    skip_1:
L_8013DA58:
    // 0x8013DA58: jal         0x80102C28
    // 0x8013DA5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerMBallRaysMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8013DA5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013DA60: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013DA64: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
L_8013DA68:
    // 0x8013DA68: lw          $t7, 0x184($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X184);
L_8013DA6C:
    // 0x8013DA6C: beql        $t7, $zero, L_8013DA88
    if (ctx->r15 == 0) {
        // 0x8013DA70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013DA88;
    }
    goto skip_2;
    // 0x8013DA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8013DA74: lbu         $t8, 0x18E($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18E);
    // 0x8013DA78: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
    // 0x8013DA7C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8013DA80: sb          $t9, 0x18E($v1)
    MEM_B(0X18E, ctx->r3) = ctx->r25;
    // 0x8013DA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013DA88:
    // 0x8013DA88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013DA8C: jr          $ra
    // 0x8013DA90: nop

    return;
    // 0x8013DA90: nop

;}
RECOMP_FUNC void func_ovl8_80385D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385D90: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80385D94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80385D98: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80385D9C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80385DA0: nop

    // 0x80385DA4: bc1tl       L_80385DE8
    if (c1cs) {
        // 0x80385DA8: lw          $v0, 0xB4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB4);
            goto L_80385DE8;
    }
    goto skip_0;
    // 0x80385DA8: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
    skip_0:
    // 0x80385DAC: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x80385DB0: bnel        $t6, $zero, L_80385DC8
    if (ctx->r14 != 0) {
        // 0x80385DB4: lw          $v0, 0xB0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB0);
            goto L_80385DC8;
    }
    goto skip_1;
    // 0x80385DB4: lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB0);
    skip_1:
    // 0x80385DB8: lh          $t7, 0x1E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1E);
    // 0x80385DBC: beql        $t7, $zero, L_80385DE8
    if (ctx->r15 == 0) {
        // 0x80385DC0: lw          $v0, 0xB4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB4);
            goto L_80385DE8;
    }
    goto skip_2;
    // 0x80385DC0: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
    skip_2:
    // 0x80385DC4: lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB0);
L_80385DC8:
    // 0x80385DC8: beql        $v0, $zero, L_80385DDC
    if (ctx->r2 == 0) {
        // 0x80385DCC: lw          $v1, 0xB4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XB4);
            goto L_80385DDC;
    }
    goto skip_3;
    // 0x80385DCC: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
    skip_3:
    // 0x80385DD0: b           L_80385DEC
    // 0x80385DD4: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
        goto L_80385DEC;
    // 0x80385DD4: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
    // 0x80385DD8: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
L_80385DDC:
    // 0x80385DDC: b           L_80385DE8
    // 0x80385DE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80385DE8;
    // 0x80385DE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80385DE4: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
L_80385DE8:
    // 0x80385DE8: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
L_80385DEC:
    // 0x80385DEC: jal         0x803725DC
    // 0x80385DF0: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x80385DF0: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x80385DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385DFC: jr          $ra
    // 0x80385E00: nop

    return;
    // 0x80385E00: nop

;}
RECOMP_FUNC void syMatrixRotRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001BA7C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001BA80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001BA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BA88: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001BA8C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001BA90: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001BA94: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8001BA98: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8001BA9C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8001BAA0: jal         0x80035380
    // 0x8001BAA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    guNormalize(rdram, ctx);
        goto after_0;
    // 0x8001BAA4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8001BAA8: jal         0x800303F0
    // 0x8001BAAC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001BAAC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001BAB0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001BAB4: jal         0x80035CD0
    // 0x8001BAB8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001BAB8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8001BABC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001BAC0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BAC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001BAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BACC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001BAD0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8001BAD4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001BAD8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001BADC: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001BAE0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001BAE4: nop

    // 0x8001BAE8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001BAEC: nop

    // 0x8001BAF0: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001BAF4: nop

    // 0x8001BAF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001BAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BB00: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001BB04: nop

    // 0x8001BB08: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8001BB0C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001BB10: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8001BB14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001BB18: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001BB1C: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8001BB20: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001BB24: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001BB28: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8001BB2C: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x8001BB30: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001BB34: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001BB38: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001BB3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BB40: swc1        $f8, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f8.u32l;
    // 0x8001BB44: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BB48: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001BB4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001BB50: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8001BB54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001BB58: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001BB5C: swc1        $f4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f4.u32l;
    // 0x8001BB60: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BB64: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001BB68: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8001BB6C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001BB70: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x8001BB74: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001BB78: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001BB7C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001BB80: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8001BB84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001BB88: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x8001BB8C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001BB90: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001BB94: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8001BB98: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001BB9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001BBA0: add.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001BBA4: swc1        $f10, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f10.u32l;
    // 0x8001BBA8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001BBAC: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8001BBB0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8001BBB4: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
    // 0x8001BBB8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001BBBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BBC0: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBC4: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001BBC8: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBCC: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBD0: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBD4: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBD8: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8001BBDC: swc1        $f4, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f4.u32l;
    // 0x8001BBE0: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001BBE4: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x8001BBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BBEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001BBF0: jr          $ra
    // 0x8001BBF4: nop

    return;
    // 0x8001BBF4: nop

;}
RECOMP_FUNC void sc1PIntroGetAlliesNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132634: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80132638: beq         $a0, $at, L_80132650
    if (ctx->r4 == ctx->r1) {
        // 0x8013263C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80132650;
    }
    // 0x8013263C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80132640: beq         $a0, $at, L_80132658
    if (ctx->r4 == ctx->r1) {
        // 0x80132644: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80132658;
    }
    // 0x80132644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132648: b           L_80132660
    // 0x8013264C: nop

        goto L_80132660;
    // 0x8013264C: nop

L_80132650:
    // 0x80132650: jr          $ra
    // 0x80132654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132658:
    // 0x80132658: jr          $ra
    // 0x8013265C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x8013265C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80132660:
    // 0x80132660: jr          $ra
    // 0x80132664: nop

    return;
    // 0x80132664: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper2ProcUpdate0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191E30: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80191E34: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80191E38: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80191E3C: bne         $t6, $zero, L_80191E58
    if (ctx->r14 != 0) {
        // 0x80191E40: nop
    
            goto L_80191E58;
    }
    // 0x80191E40: nop

    // 0x80191E44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191E48: nop

    // 0x80191E4C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80191E50: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80191E54: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
L_80191E58:
    // 0x80191E58: lw          $t8, 0x38EC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X38EC);
    // 0x80191E5C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80191E60: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80191E64: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80191E68: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80191E6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80191E70: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80191E74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80191E78: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80191E7C: lw          $t1, 0x6C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6C);
    // 0x80191E80: slti        $at, $t1, 0x10F
    ctx->r1 = SIGNED(ctx->r9) < 0X10F ? 1 : 0;
    // 0x80191E84: bnel        $at, $zero, L_80191EC0
    if (ctx->r1 != 0) {
        // 0x80191E88: lw          $t2, 0x84($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X84);
            goto L_80191EC0;
    }
    goto skip_0;
    // 0x80191E88: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x80191E8C: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80191E90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191E94: ldc1        $f8, 0x2F88($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X2F88);
    // 0x80191E98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80191E9C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80191EA0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80191EA4: swc1        $f16, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f16.u32l;
    // 0x80191EA8: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    // 0x80191EAC: jal         0x8000BB4C
    // 0x80191EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcSetAllAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x80191EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80191EB4: b           L_80191F10
    // 0x80191EB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80191F10;
    // 0x80191EB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80191EBC: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
L_80191EC0:
    // 0x80191EC0: slti        $at, $t2, 0xFF
    ctx->r1 = SIGNED(ctx->r10) < 0XFF ? 1 : 0;
    // 0x80191EC4: beq         $at, $zero, L_80191F10
    if (ctx->r1 == 0) {
        // 0x80191EC8: nop
    
            goto L_80191F10;
    }
    // 0x80191EC8: nop

    // 0x80191ECC: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80191ED0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191ED4: ldc1        $f0, 0x2F90($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X2F90);
    // 0x80191ED8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80191EDC: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80191EE0: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80191EE4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80191EE8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80191EEC: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80191EF0: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x80191EF4: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x80191EF8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80191EFC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80191F00: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x80191F04: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80191F08: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80191F0C: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
L_80191F10:
    // 0x80191F10: jal         0x80191AEC
    // 0x80191F14: nop

    SC1PGameBossWallpaper3ProcUpdate0(rdram, ctx);
        goto after_1;
    // 0x80191F14: nop

    after_1:
    // 0x80191F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191F20: jr          $ra
    // 0x80191F24: nop

    return;
    // 0x80191F24: nop

;}
RECOMP_FUNC void syUtilsQSort2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018C14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80018C18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80018C1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80018C20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80018C24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80018C28: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80018C2C: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x80018C30: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018C34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018C38: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80018C3C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80018C40: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80018C44: addu        $s1, $a0, $a2
    ctx->r17 = ADD32(ctx->r4, ctx->r6);
    // 0x80018C48: beq         $a1, $zero, L_80018C8C
    if (ctx->r5 == 0) {
        // 0x80018C4C: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_80018C8C;
    }
    // 0x80018C4C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80018C50: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80018C54: beq         $v1, $zero, L_80018C8C
    if (ctx->r3 == 0) {
        // 0x80018C58: addiu       $s0, $v1, -0x1
        ctx->r16 = ADD32(ctx->r3, -0X1);
            goto L_80018C8C;
    }
    // 0x80018C58: addiu       $s0, $v1, -0x1
    ctx->r16 = ADD32(ctx->r3, -0X1);
L_80018C5C:
    // 0x80018C5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80018C60: jalr        $s4
    // 0x80018C64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80018C64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80018C68: blez        $v0, L_80018C7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80018C6C: or          $s2, $s1, $zero
        ctx->r18 = ctx->r17 | 0;
            goto L_80018C7C;
    }
    // 0x80018C6C: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80018C70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80018C74: b           L_80018C8C
    // 0x80018C78: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80018C8C;
    // 0x80018C78: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_80018C7C:
    // 0x80018C7C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80018C80: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    // 0x80018C84: bne         $s0, $zero, L_80018C5C
    if (ctx->r16 != 0) {
        // 0x80018C88: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80018C5C;
    }
    // 0x80018C88: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80018C8C:
    // 0x80018C8C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80018C90: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80018C94: addiu       $v0, $v0, -0x46B8
    ctx->r2 = ADD32(ctx->r2, -0X46B8);
    // 0x80018C98: beq         $t9, $zero, L_80018CCC
    if (ctx->r25 == 0) {
        // 0x80018C9C: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80018CCC;
    }
    // 0x80018C9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018CA0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80018CA4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80018CA8: sw          $s4, -0x46B4($at)
    MEM_W(-0X46B4, ctx->r1) = ctx->r20;
    // 0x80018CAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80018CB0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80018CB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80018CB8: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018CBC: mflo        $t4
    ctx->r12 = lo;
    // 0x80018CC0: addu        $a1, $t4, $a0
    ctx->r5 = ADD32(ctx->r12, ctx->r4);
    // 0x80018CC4: jal         0x80018AB8
    // 0x80018CC8: nop

    syUtilsQSortIntern(rdram, ctx);
        goto after_1;
    // 0x80018CC8: nop

    after_1:
L_80018CCC:
    // 0x80018CCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80018CD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80018CD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80018CD8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80018CDC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80018CE0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80018CE4: jr          $ra
    // 0x80018CE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80018CE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itStarRodWeaponStarProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801782D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801782D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801782DC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801782E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801782E4: jal         0x80167C04
    // 0x801782E8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x801782E8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801782EC: beq         $v0, $zero, L_80178318
    if (ctx->r2 == 0) {
        // 0x801782F0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80178318;
    }
    // 0x801782F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801782F4: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    // 0x801782F8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801782FC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x80178300: jal         0x80102070
    // 0x80178304: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80178304: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    after_1:
    // 0x80178308: jal         0x800269C0
    // 0x8017830C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017830C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_2:
    // 0x80178310: b           L_8017831C
    // 0x80178314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017831C;
    // 0x80178314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80178318:
    // 0x80178318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017831C:
    // 0x8017831C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178324: jr          $ra
    // 0x80178328: nop

    return;
    // 0x80178328: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BF50: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016BF54: lb          $t6, 0x29D($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X29D);
    // 0x8016BF58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016BF5C: bne         $t6, $zero, L_8016BF6C
    if (ctx->r14 != 0) {
        // 0x8016BF60: nop
    
            goto L_8016BF6C;
    }
    // 0x8016BF60: nop

    // 0x8016BF64: jr          $ra
    // 0x8016BF68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016BF68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BF6C:
    // 0x8016BF6C: jr          $ra
    // 0x8016BF70: nop

    return;
    // 0x8016BF70: nop

;}
RECOMP_FUNC void sc1PStageClearGetUpdateBonusStatPointsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336F8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801336FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133700: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80133704: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133708: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013370C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133710: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80133714: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80133718: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8013371C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80133720: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80133724: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133728: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013372C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80133730: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80133734: addiu       $v1, $v1, 0x5378
    ctx->r3 = ADD32(ctx->r3, 0X5378);
    // 0x80133738: addiu       $v0, $v0, 0x5358
    ctx->r2 = ADD32(ctx->r2, 0X5358);
    // 0x8013373C: sw          $zero, 0x5350($at)
    MEM_W(0X5350, ctx->r1) = 0;
    // 0x80133740: sw          $zero, 0x5354($at)
    MEM_W(0X5354, ctx->r1) = 0;
L_80133744:
    // 0x80133744: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80133748: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8013374C: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80133750: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80133754: bne         $v0, $v1, L_80133744
    if (ctx->r2 != ctx->r3) {
        // 0x80133758: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_80133744;
    }
    // 0x80133758: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8013375C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133760: sw          $zero, 0x5334($at)
    MEM_W(0X5334, ctx->r1) = 0;
    // 0x80133764: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80133768: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8013376C: addiu       $s0, $s0, 0x5330
    ctx->r16 = ADD32(ctx->r16, 0X5330);
    // 0x80133770: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80133774: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133778: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013377C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80133780: addiu       $s1, $s1, 0x532C
    ctx->r17 = ADD32(ctx->r17, 0X532C);
    // 0x80133784: addiu       $s6, $s6, 0x5320
    ctx->r22 = ADD32(ctx->r22, 0X5320);
    // 0x80133788: addiu       $s7, $zero, 0xB
    ctx->r23 = ADD32(0, 0XB);
    // 0x8013378C: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x80133790: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x80133794: addiu       $s3, $zero, 0x60
    ctx->r19 = ADD32(0, 0X60);
L_80133798:
    // 0x80133798: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8013379C: bne         $s3, $a1, L_801337B4
    if (ctx->r19 != ctx->r5) {
        // 0x801337A0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801337B4;
    }
    // 0x801337A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801337A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337A8: sw          $t6, 0x5338($at)
    MEM_W(0X5338, ctx->r1) = ctx->r14;
    // 0x801337AC: b           L_80133870
    // 0x801337B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_80133870;
    // 0x801337B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801337B4:
    // 0x801337B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801337B8: bne         $s4, $t7, L_801337F0
    if (ctx->r20 != ctx->r15) {
        // 0x801337BC: nop
    
            goto L_801337F0;
    }
    // 0x801337BC: nop

    // 0x801337C0: jal         0x80133668
    // 0x801337C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sc1PStageClearCheckHaveBonusStatID(rdram, ctx);
        goto after_0;
    // 0x801337C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801337C8: bne         $v0, $zero, L_801337E0
    if (ctx->r2 != 0) {
        // 0x801337CC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801337E0;
    }
    // 0x801337CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801337D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337D4: sw          $t8, 0x5338($at)
    MEM_W(0X5338, ctx->r1) = ctx->r24;
    // 0x801337D8: b           L_80133870
    // 0x801337DC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_80133870;
    // 0x801337DC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801337E0:
    // 0x801337E0: jal         0x801335A0
    // 0x801337E4: nop

    sc1PStageClearMakeBonusPageArrow(rdram, ctx);
        goto after_1;
    // 0x801337E4: nop

    after_1:
    // 0x801337E8: b           L_80133870
    // 0x801337EC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_80133870;
    // 0x801337EC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_801337F0:
    // 0x801337F0: jal         0x80132FF8
    // 0x801337F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    sc1PStageClearSetupBonusStats(rdram, ctx);
        goto after_2;
    // 0x801337F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x801337F8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801337FC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80133800: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133804: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80133808: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x8013380C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80133810: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80133814: and         $t6, $t2, $t5
    ctx->r14 = ctx->r10 & ctx->r13;
    // 0x80133818: beql        $t6, $zero, L_80133864
    if (ctx->r14 == 0) {
        // 0x8013381C: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_80133864;
    }
    goto skip_0;
    // 0x8013381C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80133820: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80133824: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80133828: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8013382C: multu       $a1, $s7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133830: mflo        $t7
    ctx->r15 = lo;
    // 0x80133834: addiu       $t8, $t7, 0x56
    ctx->r24 = ADD32(ctx->r15, 0X56);
    // 0x80133838: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8013383C: nop

    // 0x80133840: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133844: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80133848: jal         0x801331EC
    // 0x8013384C: nop

    sc1PStageClearGetAppendBonusStatPoints(rdram, ctx);
        goto after_3;
    // 0x8013384C: nop

    after_3:
    // 0x80133850: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80133854: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80133858: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8013385C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80133860: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_80133864:
    // 0x80133864: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80133868: b           L_80133798
    // 0x8013386C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
        goto L_80133798;
    // 0x8013386C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_80133870:
    // 0x80133870: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133874: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80133878: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013387C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80133880: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80133884: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80133888: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8013388C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80133890: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80133894: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80133898: jr          $ra
    // 0x8013389C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8013389C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void gmCameraSetStatusAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010D03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010D040: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010D044: jal         0x8010CEF4
    // 0x8010D048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010D048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8010D04C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8010D050: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010D054: addiu       $t6, $t6, 0x153C
    ctx->r14 = ADD32(ctx->r14, 0X153C);
    // 0x8010D058: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8010D05C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010D060: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8010D064: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010D068: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8010D06C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8010D070: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8010D074: lw          $t0, 0x1460($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1460);
    // 0x8010D078: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8010D07C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8010D080: jal         0x8000FA3C
    // 0x8010D084: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8010D084: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    after_1:
    // 0x8010D088: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010D08C: jal         0x8010CBE4
    // 0x8010D090: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    gmCameraUpdateAnimVel(rdram, ctx);
        goto after_2;
    // 0x8010D090: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    after_2:
    // 0x8010D094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D09C: jr          $ra
    // 0x8010D0A0: nop

    return;
    // 0x8010D0A0: nop

;}
RECOMP_FUNC void func_ovl8_80383A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383A80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80383A84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80383A88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80383A8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80383A90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80383A94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80383A98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80383A9C: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x80383AA0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80383AA4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80383AA8: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80383AAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80383AB0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80383AB4: beql        $t6, $zero, L_80383B38
    if (ctx->r14 == 0) {
        // 0x80383AB8: lh          $v0, 0x44($s2)
        ctx->r2 = MEM_H(ctx->r18, 0X44);
            goto L_80383B38;
    }
    goto skip_0;
    // 0x80383AB8: lh          $v0, 0x44($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X44);
    skip_0:
    // 0x80383ABC: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
L_80383AC0:
    // 0x80383AC0: jal         0x8037E6F4
    // 0x80383AC4: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    func_ovl8_8037E6F4(rdram, ctx);
        goto after_0;
    // 0x80383AC4: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    after_0:
    // 0x80383AC8: lw          $v1, 0x3C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X3C);
    // 0x80383ACC: addu        $t7, $v1, $s0
    ctx->r15 = ADD32(ctx->r3, ctx->r16);
    // 0x80383AD0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80383AD4: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x80383AD8: beql        $t9, $zero, L_80383AF4
    if (ctx->r25 == 0) {
        // 0x80383ADC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80383AF4;
    }
    goto skip_1;
    // 0x80383ADC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80383AE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80383AE4: addu        $t0, $v1, $s0
    ctx->r8 = ADD32(ctx->r3, ctx->r16);
    // 0x80383AE8: jal         0x8037E6F4
    // 0x80383AEC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_ovl8_8037E6F4(rdram, ctx);
        goto after_1;
    // 0x80383AEC: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_1:
    // 0x80383AF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80383AF4:
    // 0x80383AF4: bgez        $v0, L_80383B04
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80383AF8: sra         $t1, $v0, 1
        ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80383B04;
    }
    // 0x80383AF8: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80383AFC: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80383B00: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80383B04:
    // 0x80383B04: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80383B08: slt         $at, $t2, $s4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80383B0C: bnel        $at, $zero, L_80383B20
    if (ctx->r1 != 0) {
        // 0x80383B10: lw          $t3, 0x3C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X3C);
            goto L_80383B20;
    }
    goto skip_2;
    // 0x80383B10: lw          $t3, 0x3C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X3C);
    skip_2:
    // 0x80383B14: b           L_80383B38
    // 0x80383B18: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_80383B38;
    // 0x80383B18: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80383B1C: lw          $t3, 0x3C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X3C);
L_80383B20:
    // 0x80383B20: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80383B24: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80383B28: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x80383B2C: bne         $a0, $zero, L_80383AC0
    if (ctx->r4 != 0) {
        // 0x80383B30: nop
    
            goto L_80383AC0;
    }
    // 0x80383B30: nop

    // 0x80383B34: lh          $v0, 0x44($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X44);
L_80383B38:
    // 0x80383B38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80383B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80383B40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80383B44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80383B48: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80383B4C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80383B50: jr          $ra
    // 0x80383B54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80383B54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void n_alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002898C: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80028990: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80028994: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80028998: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002899C: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800289A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800289A4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800289A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800289AC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800289B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800289B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800289B8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800289BC: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800289C0: jal         0x80028884
    // 0x800289C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    n_alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800289C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800289C8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800289CC: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800289D0: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800289D4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800289D8:
    // 0x800289D8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800289DC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800289E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800289E4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800289E8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800289EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800289F0: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800289F4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800289F8: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800289FC:
    // 0x800289FC: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x80028A00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80028A04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80028A08: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x80028A0C: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x80028A10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80028A14: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80028A18: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x80028A1C: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x80028A20: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x80028A24: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x80028A28: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x80028A2C: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x80028A30: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x80028A34: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x80028A38: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80028A3C: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x80028A40: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x80028A44: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x80028A48: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x80028A4C: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x80028A50: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x80028A54: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x80028A58: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x80028A5C: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80028A60: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80028A64: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x80028A68: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80028A6C: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x80028A70: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x80028A74: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x80028A78: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x80028A7C: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x80028A80: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x80028A84: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x80028A88: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x80028A8C: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80028A90: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x80028A94: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x80028A98: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x80028A9C: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x80028AA0: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x80028AA4: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x80028AA8: bne         $a0, $s0, L_800289FC
    if (ctx->r4 != ctx->r16) {
        // 0x80028AAC: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800289FC;
    }
    // 0x80028AAC: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x80028AB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028AB4: jal         0x8002858C
    // 0x80028AB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    n_alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x80028AB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80028ABC: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x80028AC0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80028AC4: beq         $t0, $s5, L_80028AD4
    if (ctx->r8 == ctx->r21) {
        // 0x80028AC8: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_80028AD4;
    }
    // 0x80028AC8: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x80028ACC: bnel        $at, $zero, L_800289D8
    if (ctx->r1 != 0) {
        // 0x80028AD0: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800289D8;
    }
    goto skip_0;
    // 0x80028AD0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_80028AD4:
    // 0x80028AD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80028AD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80028ADC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80028AE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80028AE4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80028AE8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80028AEC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80028AF0: jr          $ra
    // 0x80028AF4: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x80028AF4: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_ovl8_8037E97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E97C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8037E980: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8037E984: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8037E988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037E98C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8037E990: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037E994: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8037E998: bne         $a0, $zero, L_8037E9B0
    if (ctx->r4 != 0) {
        // 0x8037E99C: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_8037E9B0;
    }
    // 0x8037E99C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8037E9A0: jal         0x803717A0
    // 0x8037E9A4: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037E9A4: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x8037E9A8: beq         $v0, $zero, L_8037EAE8
    if (ctx->r2 == 0) {
        // 0x8037E9AC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037EAE8;
    }
    // 0x8037E9AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037E9B0:
    // 0x8037E9B0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8037E9B4: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // 0x8037E9B8: addiu       $a1, $s0, 0x114
    ctx->r5 = ADD32(ctx->r16, 0X114);
    // 0x8037E9BC: bnel        $t6, $zero, L_8037E9E0
    if (ctx->r14 != 0) {
        // 0x8037E9C0: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_8037E9E0;
    }
    goto skip_0;
    // 0x8037E9C0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x8037E9C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037E9C8: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x8037E9CC: jal         0x803717E0
    // 0x8037E9D0: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037E9D0: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    after_1:
    // 0x8037E9D4: jal         0x8037C2D0
    // 0x8037E9D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037E9D8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8037E9DC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_8037E9E0:
    // 0x8037E9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037E9E4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8037E9E8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8037E9EC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8037E9F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8037E9F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8037E9F8: jal         0x8037C7D4
    // 0x8037E9FC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_ovl8_8037C7D4(rdram, ctx);
        goto after_3;
    // 0x8037E9FC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037EA00: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037EA04: addiu       $t8, $t8, -0x5760
    ctx->r24 = ADD32(ctx->r24, -0X5760);
    // 0x8037EA08: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x8037EA0C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8037EA10: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037EA14: addiu       $t9, $t9, -0x5680
    ctx->r25 = ADD32(ctx->r25, -0X5680);
    // 0x8037EA18: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x8037EA1C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8037EA20: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037EA24: addiu       $t1, $t1, -0x5528
    ctx->r9 = ADD32(ctx->r9, -0X5528);
    // 0x8037EA28: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037EA2C: addiu       $t3, $t3, -0x5500
    ctx->r11 = ADD32(ctx->r11, -0X5500);
    // 0x8037EA30: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8037EA34: sw          $t3, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r11;
    // 0x8037EA38: lhu         $t4, 0x4($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X4);
    // 0x8037EA3C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8037EA40: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8037EA44: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8037EA48: lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X6);
    // 0x8037EA4C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8037EA50: jal         0x8037B85C
    // 0x8037EA54: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_4;
    // 0x8037EA54: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    after_4:
    // 0x8037EA58: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8037EA5C: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x8037EA60: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x8037EA64: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8037EA68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8037EA6C: jal         0x8037ACAC
    // 0x8037EA70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_5;
    // 0x8037EA70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x8037EA74: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8037EA78: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x8037EA7C: sw          $v0, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r2;
    // 0x8037EA80: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x8037EA84: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8037EA88: lh          $t7, 0x70($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X70);
    // 0x8037EA8C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8037EA90: jalr        $t9
    // 0x8037EA94: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8037EA94: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    after_6:
    // 0x8037EA98: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8037EA9C: lui         $at, 0x5354
    ctx->r1 = S32(0X5354 << 16);
    // 0x8037EAA0: ori         $at, $at, 0x424E
    ctx->r1 = ctx->r1 | 0X424E;
    // 0x8037EAA4: beq         $v1, $at, L_8037EAD0
    if (ctx->r3 == ctx->r1) {
        // 0x8037EAA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037EAD0;
    }
    // 0x8037EAA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037EAAC: lui         $at, 0x5354
    ctx->r1 = S32(0X5354 << 16);
    // 0x8037EAB0: ori         $at, $at, 0x5442
    ctx->r1 = ctx->r1 | 0X5442;
    // 0x8037EAB4: beq         $v1, $at, L_8037EAD8
    if (ctx->r3 == ctx->r1) {
        // 0x8037EAB8: lui         $at, 0x5354
        ctx->r1 = S32(0X5354 << 16);
            goto L_8037EAD8;
    }
    // 0x8037EAB8: lui         $at, 0x5354
    ctx->r1 = S32(0X5354 << 16);
    // 0x8037EABC: ori         $at, $at, 0x4F42
    ctx->r1 = ctx->r1 | 0X4F42;
    // 0x8037EAC0: beq         $v1, $at, L_8037EAE0
    if (ctx->r3 == ctx->r1) {
        // 0x8037EAC4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8037EAE0;
    }
    // 0x8037EAC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037EAC8: b           L_8037EAE0
    // 0x8037EACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037EAE0;
    // 0x8037EACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037EAD0:
    // 0x8037EAD0: b           L_8037EAE0
    // 0x8037EAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037EAE0;
    // 0x8037EAD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037EAD8:
    // 0x8037EAD8: b           L_8037EAE0
    // 0x8037EADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037EAE0;
    // 0x8037EADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037EAE0:
    // 0x8037EAE0: jal         0x8037EBC8
    // 0x8037EAE4: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    func_ovl8_8037EBC8(rdram, ctx);
        goto after_7;
    // 0x8037EAE4: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    after_7:
L_8037EAE8:
    // 0x8037EAE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037EAEC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037EAF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8037EAF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8037EAF8: jr          $ra
    // 0x8037EAFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8037EAFC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftKirbySpecialLwUnkProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801616B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801616B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801616B8: jal         0x801615E4
    // 0x801616BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftKirbySpecialLwUnkDecideNextStatus(rdram, ctx);
        goto after_0;
    // 0x801616BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801616C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801616C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801616C8: jr          $ra
    // 0x801616CC: nop

    return;
    // 0x801616CC: nop

;}
RECOMP_FUNC void itMBallFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C790: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C794: lwc1        $f0, -0x3210($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3210);
    // 0x8017C798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C79C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C7A0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017C7A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8017C7A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017C7AC: jal         0x80173B24
    // 0x8017C7B0: addiu       $a3, $a3, -0x3838
    ctx->r7 = ADD32(ctx->r7, -0X3838);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x8017C7B0: addiu       $a3, $a3, -0x3838
    ctx->r7 = ADD32(ctx->r7, -0X3838);
    after_0:
    // 0x8017C7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C7BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C7C0: jr          $ra
    // 0x8017C7C4: nop

    return;
    // 0x8017C7C4: nop

;}
RECOMP_FUNC void gcPauseGObjProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B284: bne         $a0, $zero, L_8000B294
    if (ctx->r4 != 0) {
        // 0x8000B288: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000B294;
    }
    // 0x8000B288: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000B28C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B290: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000B294:
    // 0x8000B294: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8000B298: beq         $v0, $zero, L_8000B2B0
    if (ctx->r2 == 0) {
        // 0x8000B29C: nop
    
            goto L_8000B2B0;
    }
    // 0x8000B29C: nop

    // 0x8000B2A0: sb          $v1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r3;
L_8000B2A4:
    // 0x8000B2A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000B2A8: bnel        $v0, $zero, L_8000B2A4
    if (ctx->r2 != 0) {
        // 0x8000B2AC: sb          $v1, 0x15($v0)
        MEM_B(0X15, ctx->r2) = ctx->r3;
            goto L_8000B2A4;
    }
    goto skip_0;
    // 0x8000B2AC: sb          $v1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r3;
    skip_0:
L_8000B2B0:
    // 0x8000B2B0: jr          $ra
    // 0x8000B2B4: nop

    return;
    // 0x8000B2B4: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePortraitFlashCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D54: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132D58: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132D5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132D60: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132D64: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80132D68: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80132D6C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132D70: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132D74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132D78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132D7C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132D80: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132D84: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132D88: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132D8C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132D90: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132D94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132D9C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132DA0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132DA4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132DAC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132DB0: jal         0x8000B93C
    // 0x80132DB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132DB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132DB8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132DBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132DC0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132DC4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132DC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132DD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132DD4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132DD8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132DDC: jal         0x80007080
    // 0x80132DE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132DE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132DE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132DE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132DEC: jr          $ra
    // 0x80132DF0: nop

    return;
    // 0x80132DF0: nop

;}
RECOMP_FUNC void itLinkBombExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185A80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80185A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80185A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80185A8C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80185A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80185A94: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80185A98: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80185A9C: jal         0x80185CE4
    // 0x80185AA0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    itLinkBombCommonSetHitStatusNone(rdram, ctx);
        goto after_0;
    // 0x80185AA0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80185AA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80185AA8: jal         0x801005C8
    // 0x80185AAC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80185AAC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80185AB0: beq         $v0, $zero, L_80185AD4
    if (ctx->r2 == 0) {
        // 0x80185AB4: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80185AD4;
    }
    // 0x80185AB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80185AB8: lwc1        $f0, -0x3090($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3090);
    // 0x80185ABC: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x80185AC0: swc1        $f0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f0.u32l;
    // 0x80185AC4: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80185AC8: swc1        $f0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80185ACC: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x80185AD0: swc1        $f0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f0.u32l;
L_80185AD4:
    // 0x80185AD4: jal         0x801008F4
    // 0x80185AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80185AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80185ADC: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80185AE0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80185AE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80185AE8: sb          $t1, 0x54($t2)
    MEM_B(0X54, ctx->r10) = ctx->r9;
    // 0x80185AEC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80185AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80185AF4: jal         0x8017275C
    // 0x80185AF8: sh          $t3, 0x156($t4)
    MEM_H(0X156, ctx->r12) = ctx->r11;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_3;
    // 0x80185AF8: sh          $t3, 0x156($t4)
    MEM_H(0X156, ctx->r12) = ctx->r11;
    after_3:
    // 0x80185AFC: jal         0x8018656C
    // 0x80185B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itLinkBombExplodeSetStatus(rdram, ctx);
        goto after_4;
    // 0x80185B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80185B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80185B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80185B0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80185B10: jr          $ra
    // 0x80185B14: nop

    return;
    // 0x80185B14: nop

;}
RECOMP_FUNC void efManagerStockStealStartMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010399C: jal         0x80103918
    // 0x801039A0: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    efManagerStockCommonMakeEffectID(rdram, ctx);
        goto after_0;
    // 0x801039A0: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    after_0:
    // 0x801039A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801039A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801039AC: jr          $ra
    // 0x801039B0: nop

    return;
    // 0x801039B0: nop

;}
RECOMP_FUNC void syVectorAddScaled3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001912C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80019130: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019134: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019138: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001913C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80019140: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80019144: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80019148: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001914C: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80019150: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019154: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80019158: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8001915C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80019160: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019164: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80019168: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001916C: jr          $ra
    // 0x80019170: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x80019170: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_ovl8_80382670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382674: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80382678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038267C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382680: beq         $a0, $zero, L_803826F8
    if (ctx->r4 == 0) {
        // 0x80382684: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803826F8;
    }
    // 0x80382684: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382688: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8038268C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80382690: addiu       $t6, $t6, -0x4090
    ctx->r14 = ADD32(ctx->r14, -0X4090);
    // 0x80382694: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382698: addiu       $t7, $t7, -0x3FC0
    ctx->r15 = ADD32(ctx->r15, -0X3FC0);
    // 0x8038269C: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x803826A0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x803826A4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x803826A8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803826AC: addiu       $t9, $t9, -0x3E68
    ctx->r25 = ADD32(ctx->r25, -0X3E68);
    // 0x803826B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803826B4: jal         0x80382224
    // 0x803826B8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80382224(rdram, ctx);
        goto after_0;
    // 0x803826B8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x803826BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x803826C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803826C4: beql        $t1, $zero, L_803826E4
    if (ctx->r9 == 0) {
        // 0x803826C8: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_803826E4;
    }
    goto skip_0;
    // 0x803826C8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803826CC: jal         0x8037C30C
    // 0x803826D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x803826D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x803826D4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803826D8: jal         0x803718C4
    // 0x803826DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x803826DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x803826E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_803826E4:
    // 0x803826E4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x803826E8: beql        $t3, $zero, L_803826FC
    if (ctx->r11 == 0) {
        // 0x803826EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803826FC;
    }
    goto skip_1;
    // 0x803826EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x803826F0: jal         0x803717C0
    // 0x803826F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x803826F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_803826F8:
    // 0x803826F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803826FC:
    // 0x803826FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80382704: jr          $ra
    // 0x80382708: nop

    return;
    // 0x80382708: nop

;}
RECOMP_FUNC void wpNessPKFireProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016ABF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016ABF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016ABF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016ABFC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016AC00: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8016AC04: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8016AC08: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8016AC0C: jal         0x801680EC
    // 0x8016AC10: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016AC10: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    after_0:
    // 0x8016AC14: jal         0x80167F68
    // 0x8016AC18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x8016AC18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016AC1C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8016AC20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016AC24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016AC28: lw          $v1, 0x74($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X74);
    // 0x8016AC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016AC30: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8016AC34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016AC38: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
    // 0x8016AC3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AC40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016AC44: jr          $ra
    // 0x8016AC48: nop

    return;
    // 0x8016AC48: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151A14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151A1C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151A20: jal         0x800DE6E4
    // 0x80151A24: addiu       $a1, $a1, 0x1A38
    ctx->r5 = ADD32(ctx->r5, 0X1A38);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151A24: addiu       $a1, $a1, 0x1A38
    ctx->r5 = ADD32(ctx->r5, 0X1A38);
    after_0:
    // 0x80151A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151A2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151A30: jr          $ra
    // 0x80151A34: nop

    return;
    // 0x80151A34: nop

;}
RECOMP_FUNC void mpProcessRunRWallCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCAE8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800DCAEC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800DCAF0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800DCAF4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800DCAF8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DCAFC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DCB00: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DCB04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DCB08: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DCB0C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DCB10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DCB14: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800DCB18: jal         0x800D957C
    // 0x800DCB1C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    mpProcessSetLastWallCollideLeft(rdram, ctx);
        goto after_0;
    // 0x800DCB1C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800DCB20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DCB24: lw          $t7, 0xDE0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDE0);
    // 0x800DCB28: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800DCB2C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800DCB30: blez        $t7, L_800DCED4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800DCB34: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_800DCED4;
    }
    // 0x800DCB34: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x800DCB38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DCB3C: addiu       $v0, $v0, 0xDE8
    ctx->r2 = ADD32(ctx->r2, 0XDE8);
    // 0x800DCB40: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800DCB44: addiu       $s7, $s7, 0xDFC
    ctx->r23 = ADD32(ctx->r23, 0XDFC);
    // 0x800DCB48: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800DCB4C: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
    // 0x800DCB50: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
    // 0x800DCB54: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
L_800DCB58:
    // 0x800DCB58: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800DCB5C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCB60: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x800DCB64: jal         0x800F4690
    // 0x800DCB68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_1;
    // 0x800DCB68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800DCB6C: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCB70: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DCB74: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DCB78: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DCB7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DCB80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCB84: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DCB88: nop

    // 0x800DCB8C: bc1f        L_800DCBDC
    if (!c1cs) {
        // 0x800DCB90: nop
    
            goto L_800DCBDC;
    }
    // 0x800DCB90: nop

    // 0x800DCB94: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCB98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCB9C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCBA0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DCBA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DCBA8: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCBAC: bc1fl       L_800DCEB0
    if (!c1cs) {
        // 0x800DCBB0: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DCEB0;
    }
    goto skip_0;
    // 0x800DCBB0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x800DCBB4: jal         0x800F41C0
    // 0x800DCBB8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_2;
    // 0x800DCBB8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800DCBBC: beq         $v0, $zero, L_800DCEAC
    if (ctx->r2 == 0) {
        // 0x800DCBC0: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DCEAC;
    }
    // 0x800DCBC0: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DCBC4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCBC8: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCBCC: jal         0x800D95A4
    // 0x800DCBD0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_3;
    // 0x800DCBD0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x800DCBD4: b           L_800DCEB0
    // 0x800DCBD8: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DCEB0;
    // 0x800DCBD8: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DCBDC:
    // 0x800DCBDC: jal         0x800F46B0
    // 0x800DCBE0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    mpCollisionGetRWallEdgeD(rdram, ctx);
        goto after_4;
    // 0x800DCBE0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_4:
    // 0x800DCBE4: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCBE8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DCBEC: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DCBF0: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DCBF4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DCBF8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DCBFC: nop

    // 0x800DCC00: bc1fl       L_800DCC54
    if (!c1cs) {
        // 0x800DCC04: lwc1        $f6, 0x0($s6)
        ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DCC54;
    }
    goto skip_1;
    // 0x800DCC04: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800DCC08: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCC0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCC10: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCC14: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DCC18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DCC1C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCC20: bc1fl       L_800DCEB0
    if (!c1cs) {
        // 0x800DCC24: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DCEB0;
    }
    goto skip_2;
    // 0x800DCC24: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x800DCC28: jal         0x800F41C0
    // 0x800DCC2C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_5;
    // 0x800DCC2C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x800DCC30: beq         $v0, $zero, L_800DCEAC
    if (ctx->r2 == 0) {
        // 0x800DCC34: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DCEAC;
    }
    // 0x800DCC34: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DCC38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCC3C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCC40: jal         0x800D95A4
    // 0x800DCC44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_6;
    // 0x800DCC44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x800DCC48: b           L_800DCEB0
    // 0x800DCC4C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DCEB0;
    // 0x800DCC4C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800DCC50: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
L_800DCC54:
    // 0x800DCC54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCC58: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCC5C: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800DCC60: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DCC64: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCC68: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DCC6C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DCC70: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DCC74: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCC78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DCC7C: jal         0x800F41C0
    // 0x800DCC80: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_7;
    // 0x800DCC80: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800DCC84: beq         $v0, $zero, L_800DCCB8
    if (ctx->r2 == 0) {
        // 0x800DCC88: lwc1        $f18, 0x64($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DCCB8;
    }
    // 0x800DCC88: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCC8C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DCC90: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCC94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCC98: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DCC9C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCCA0: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800DCCA4: nop

    // 0x800DCCA8: bc1fl       L_800DCCBC
    if (!c1cs) {
        // 0x800DCCAC: lwc1        $f8, 0x0($s6)
        ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DCCBC;
    }
    goto skip_3;
    // 0x800DCCAC: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    skip_3:
    // 0x800DCCB0: jal         0x800D95A4
    // 0x800DCCB4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_8;
    // 0x800DCCB4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_8:
L_800DCCB8:
    // 0x800DCCB8: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
L_800DCCBC:
    // 0x800DCCBC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DCCC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCCC4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCCC8: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800DCCCC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DCCD0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCCD4: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800DCCD8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DCCDC: lwc1        $f16, 0x4($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCCE0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DCCE4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DCCE8: jal         0x800F41C0
    // 0x800DCCEC: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_9;
    // 0x800DCCEC: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800DCCF0: beq         $v0, $zero, L_800DCD24
    if (ctx->r2 == 0) {
        // 0x800DCCF4: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DCD24;
    }
    // 0x800DCCF4: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCCF8: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DCCFC: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCD00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCD04: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DCD08: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCD0C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800DCD10: nop

    // 0x800DCD14: bc1fl       L_800DCD28
    if (!c1cs) {
        // 0x800DCD18: lwc1        $f16, 0x0($s6)
        ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DCD28;
    }
    goto skip_4;
    // 0x800DCD18: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800DCD1C: jal         0x800D95A4
    // 0x800DCD20: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_10;
    // 0x800DCD20: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_10:
L_800DCD24:
    // 0x800DCD24: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
L_800DCD28:
    // 0x800DCD28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCD2C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DCD30: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800DCD34: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DCD38: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCD3C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DCD40: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DCD44: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800DCD48: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCD4C: jal         0x800F41C0
    // 0x800DCD50: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_11;
    // 0x800DCD50: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x800DCD54: beq         $v0, $zero, L_800DCD88
    if (ctx->r2 == 0) {
        // 0x800DCD58: lwc1        $f10, 0x64($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DCD88;
    }
    // 0x800DCD58: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCD5C: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DCD60: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCD64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCD68: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800DCD6C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCD70: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800DCD74: nop

    // 0x800DCD78: bc1f        L_800DCD88
    if (!c1cs) {
        // 0x800DCD7C: nop
    
            goto L_800DCD88;
    }
    // 0x800DCD7C: nop

    // 0x800DCD80: jal         0x800D95A4
    // 0x800DCD84: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_12;
    // 0x800DCD84: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_12:
L_800DCD88:
    // 0x800DCD88: jal         0x800FA518
    // 0x800DCD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetVertexCountLineID(rdram, ctx);
        goto after_13;
    // 0x800DCD8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x800DCD90: blez        $v0, L_800DCEAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800DCD94: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DCEAC;
    }
    // 0x800DCD94: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DCD98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800DCD9C:
    // 0x800DCD9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DCDA0: jal         0x800FA5E8
    // 0x800DCDA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_14;
    // 0x800DCDA4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x800DCDA8: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DCDAC: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DCDB0: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DCDB4: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DCDB8: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x800DCDBC: nop

    // 0x800DCDC0: bc1fl       L_800DCE08
    if (!c1cs) {
        // 0x800DCDC4: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DCE08;
    }
    goto skip_5;
    // 0x800DCDC4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x800DCDC8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DCDCC: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DCDD0: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800DCDD4: nop

    // 0x800DCDD8: bc1fl       L_800DCE08
    if (!c1cs) {
        // 0x800DCDDC: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DCE08;
    }
    goto skip_6;
    // 0x800DCDDC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x800DCDE0: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800DCDE4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DCDE8: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DCDEC: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800DCDF0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800DCDF4: div.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DCDF8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800DCDFC: b           L_800DCE58
    // 0x800DCE00: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_800DCE58;
    // 0x800DCE00: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800DCE04: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_800DCE08:
    // 0x800DCE08: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DCE0C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DCE10: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800DCE14: nop

    // 0x800DCE18: bc1fl       L_800DCEA0
    if (!c1cs) {
        // 0x800DCE1C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DCEA0;
    }
    goto skip_7;
    // 0x800DCE1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800DCE20: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DCE24: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DCE28: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x800DCE2C: nop

    // 0x800DCE30: bc1fl       L_800DCEA0
    if (!c1cs) {
        // 0x800DCE34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DCEA0;
    }
    goto skip_8;
    // 0x800DCE34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x800DCE38: sub.s       $f16, $f14, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800DCE3C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DCE40: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DCE44: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800DCE48: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800DCE4C: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800DCE50: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800DCE54: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800DCE58:
    // 0x800DCE58: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DCE5C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCE60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DCE64: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DCE68: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800DCE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DCE70: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DCE74: bc1fl       L_800DCEA0
    if (!c1cs) {
        // 0x800DCE78: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DCEA0;
    }
    goto skip_9;
    // 0x800DCE78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800DCE7C: jal         0x800F41C0
    // 0x800DCE80: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_15;
    // 0x800DCE80: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x800DCE84: beq         $v0, $zero, L_800DCE9C
    if (ctx->r2 == 0) {
        // 0x800DCE88: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DCE9C;
    }
    // 0x800DCE88: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCE8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DCE90: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DCE94: jal         0x800D95A4
    // 0x800DCE98: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_16;
    // 0x800DCE98: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_16:
L_800DCE9C:
    // 0x800DCE9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800DCEA0:
    // 0x800DCEA0: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DCEA4: bnel        $at, $zero, L_800DCD9C
    if (ctx->r1 != 0) {
        // 0x800DCEA8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800DCD9C;
    }
    goto skip_10;
    // 0x800DCEA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_10:
L_800DCEAC:
    // 0x800DCEAC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DCEB0:
    // 0x800DCEB0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800DCEB4: lw          $t0, 0xDE0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XDE0);
    // 0x800DCEB8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800DCEBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DCEC0: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DCEC4: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DCEC8: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800DCECC: bne         $at, $zero, L_800DCB58
    if (ctx->r1 != 0) {
        // 0x800DCED0: sw          $v0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r2;
            goto L_800DCB58;
    }
    // 0x800DCED0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_800DCED4:
    // 0x800DCED4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800DCED8: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800DCEDC: addiu       $a1, $t1, 0xB4
    ctx->r5 = ADD32(ctx->r9, 0XB4);
    // 0x800DCEE0: addiu       $a2, $t1, 0xB8
    ctx->r6 = ADD32(ctx->r9, 0XB8);
    // 0x800DCEE4: jal         0x800D95E0
    // 0x800DCEE8: addiu       $a3, $t1, 0xBC
    ctx->r7 = ADD32(ctx->r9, 0XBC);
    mpProcessGetLastWallCollideStats(rdram, ctx);
        goto after_17;
    // 0x800DCEE8: addiu       $a3, $t1, 0xBC
    ctx->r7 = ADD32(ctx->r9, 0XBC);
    after_17:
    // 0x800DCEEC: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DCEF0: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DCEF4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DCEF8: nop

    // 0x800DCEFC: bc1fl       L_800DCF1C
    if (!c1cs) {
        // 0x800DCF00: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_800DCF1C;
    }
    goto skip_11;
    // 0x800DCF00: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_11:
    // 0x800DCF04: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    // 0x800DCF08: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x800DCF0C: lhu         $t3, 0x5A($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X5A);
    // 0x800DCF10: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x800DCF14: sh          $t4, 0x5A($t2)
    MEM_H(0X5A, ctx->r10) = ctx->r12;
    // 0x800DCF18: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
L_800DCF1C:
    // 0x800DCF1C: lhu         $t6, 0x58($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X58);
    // 0x800DCF20: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800DCF24: sh          $t7, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r15;
    // 0x800DCF28: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800DCF2C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800DCF30: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800DCF34: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DCF38: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DCF3C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DCF40: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DCF44: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DCF48: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DCF4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DCF50: jr          $ra
    // 0x800DCF54: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800DCF54: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itDogasWeaponSmogProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801830DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801830E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801830E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801830E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801830EC: lw          $t6, 0x74($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X74);
    // 0x801830F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801830F4: lw          $t7, 0x29C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X29C);
    // 0x801830F8: lw          $v0, 0x10($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X10);
    // 0x801830FC: lhu         $t8, 0x24($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X24);
    // 0x80183100: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80183104: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80183108: bgez        $t8, L_8018311C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018310C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018311C;
    }
    // 0x8018310C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80183110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80183114: nop

    // 0x80183118: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8018311C:
    // 0x8018311C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80183120: jal         0x80167FE8
    // 0x80183124: swc1        $f16, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f16.u32l;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80183124: swc1        $f16, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f16.u32l;
    after_0:
    // 0x80183128: beq         $v0, $zero, L_80183138
    if (ctx->r2 == 0) {
        // 0x8018312C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80183138;
    }
    // 0x8018312C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183130: b           L_8018313C
    // 0x80183134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018313C;
    // 0x80183134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80183138:
    // 0x80183138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018313C:
    // 0x8018313C: jr          $ra
    // 0x80183140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80183140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnVSResultsSetTeamPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137068: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013706C: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80137070: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137074: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137078: beq         $t6, $zero, L_80137098
    if (ctx->r14 == 0) {
        // 0x8013707C: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80137098;
    }
    // 0x8013707C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80137080: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80137084: lbu         $t7, 0x4D2C($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D2C);
    // 0x80137088: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013708C: bne         $a0, $t7, L_80137098
    if (ctx->r4 != ctx->r15) {
        // 0x80137090: nop
    
            goto L_80137098;
    }
    // 0x80137090: nop

    // 0x80137094: sw          $a1, -0x6450($at)
    MEM_W(-0X6450, ctx->r1) = ctx->r5;
L_80137098:
    // 0x80137098: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x8013709C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x801370A0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x801370A4: beq         $t8, $zero, L_801370C0
    if (ctx->r24 == 0) {
        // 0x801370A8: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_801370C0;
    }
    // 0x801370A8: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x801370AC: lbu         $t9, 0x4DA0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4DA0);
    // 0x801370B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801370B4: bne         $a0, $t9, L_801370C0
    if (ctx->r4 != ctx->r25) {
        // 0x801370B8: nop
    
            goto L_801370C0;
    }
    // 0x801370B8: nop

    // 0x801370BC: sw          $a1, -0x644C($at)
    MEM_W(-0X644C, ctx->r1) = ctx->r5;
L_801370C0:
    // 0x801370C0: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x801370C4: beq         $t0, $zero, L_801370E0
    if (ctx->r8 == 0) {
        // 0x801370C8: nop
    
            goto L_801370E0;
    }
    // 0x801370C8: nop

    // 0x801370CC: lbu         $t1, 0x4E14($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4E14);
    // 0x801370D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801370D4: bne         $a0, $t1, L_801370E0
    if (ctx->r4 != ctx->r9) {
        // 0x801370D8: nop
    
            goto L_801370E0;
    }
    // 0x801370D8: nop

    // 0x801370DC: sw          $a1, -0x6448($at)
    MEM_W(-0X6448, ctx->r1) = ctx->r5;
L_801370E0:
    // 0x801370E0: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x801370E4: beq         $t2, $zero, L_80137100
    if (ctx->r10 == 0) {
        // 0x801370E8: nop
    
            goto L_80137100;
    }
    // 0x801370E8: nop

    // 0x801370EC: lbu         $t3, 0x4E88($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4E88);
    // 0x801370F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801370F4: bne         $a0, $t3, L_80137100
    if (ctx->r4 != ctx->r11) {
        // 0x801370F8: nop
    
            goto L_80137100;
    }
    // 0x801370F8: nop

    // 0x801370FC: sw          $a1, -0x6444($at)
    MEM_W(-0X6444, ctx->r1) = ctx->r5;
L_80137100:
    // 0x80137100: jr          $ra
    // 0x80137104: nop

    return;
    // 0x80137104: nop

;}
RECOMP_FUNC void wpProcessProcSearchHitWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80166954: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80166958: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8016695C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80166960: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80166964: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80166968: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8016696C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80166970: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80166974: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80166978: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8016697C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80166980: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80166984: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80166988: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x8016698C: lw          $t8, 0x148($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X148);
    // 0x80166990: addiu       $s3, $t6, 0x100
    ctx->r19 = ADD32(ctx->r14, 0X100);
    // 0x80166994: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x80166998: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8016699C: beql        $t9, $zero, L_80166BB8
    if (ctx->r25 == 0) {
        // 0x801669A0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80166BB8;
    }
    goto skip_0;
    // 0x801669A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x801669A4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x801669A8: beql        $t0, $zero, L_80166BB8
    if (ctx->r8 == 0) {
        // 0x801669AC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80166BB8;
    }
    goto skip_1;
    // 0x801669AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x801669B0: lbu         $t1, 0x44($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X44);
    // 0x801669B4: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x801669B8: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x801669BC: beql        $t2, $zero, L_80166BB8
    if (ctx->r10 == 0) {
        // 0x801669C0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80166BB8;
    }
    goto skip_2;
    // 0x801669C0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x801669C4: lw          $s5, 0x6704($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X6704);
    // 0x801669C8: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x801669CC: addiu       $fp, $zero, 0x20
    ctx->r30 = ADD32(0, 0X20);
    // 0x801669D0: beql        $s5, $zero, L_80166BB8
    if (ctx->r21 == 0) {
        // 0x801669D4: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80166BB8;
    }
    goto skip_3;
    // 0x801669D4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x801669D8: lw          $a2, 0x84($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X84);
L_801669DC:
    // 0x801669DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801669E0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x801669E4: addiu       $s2, $a2, 0x100
    ctx->r18 = ADD32(ctx->r6, 0X100);
    // 0x801669E8: bne         $s5, $s7, L_801669F8
    if (ctx->r21 != ctx->r23) {
        // 0x801669EC: or          $s6, $s2, $zero
        ctx->r22 = ctx->r18 | 0;
            goto L_801669F8;
    }
    // 0x801669EC: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x801669F0: b           L_80166BA8
    // 0x801669F4: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
        goto L_80166BA8;
    // 0x801669F4: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
L_801669F8:
    // 0x801669F8: beq         $t4, $zero, L_80166BA8
    if (ctx->r12 == 0) {
        // 0x801669FC: lw          $t6, 0x88($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X88);
            goto L_80166BA8;
    }
    // 0x801669FC: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80166A00: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x80166A04: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80166A08: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80166A0C: beql        $t5, $t7, L_80166BAC
    if (ctx->r13 == ctx->r15) {
        // 0x80166A10: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_4;
    // 0x80166A10: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_4:
    // 0x80166A14: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80166A18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80166A1C: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x80166A20: bnel        $t8, $at, L_80166A4C
    if (ctx->r24 != ctx->r1) {
        // 0x80166A24: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_80166A4C;
    }
    goto skip_5;
    // 0x80166A24: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x80166A28: lbu         $t9, 0x9($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X9);
    // 0x80166A2C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80166A30: bnel        $t9, $zero, L_80166A4C
    if (ctx->r25 != 0) {
        // 0x80166A34: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_80166A4C;
    }
    goto skip_6;
    // 0x80166A34: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_6:
    // 0x80166A38: lbu         $t0, 0x10($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X10);
    // 0x80166A3C: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x80166A40: beql        $t0, $t2, L_80166BAC
    if (ctx->r8 == ctx->r10) {
        // 0x80166A44: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_7;
    // 0x80166A44: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_7:
    // 0x80166A48: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
L_80166A4C:
    // 0x80166A4C: beql        $t3, $zero, L_80166BAC
    if (ctx->r11 == 0) {
        // 0x80166A50: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_8;
    // 0x80166A50: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_8:
    // 0x80166A54: lw          $t4, 0x48($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X48);
    // 0x80166A58: srl         $t6, $t4, 31
    ctx->r14 = S32(U32(ctx->r12) >> 31);
    // 0x80166A5C: beql        $t6, $zero, L_80166BAC
    if (ctx->r14 == 0) {
        // 0x80166A60: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_9;
    // 0x80166A60: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_9:
    // 0x80166A64: lbu         $t5, 0x44($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X44);
    // 0x80166A68: lbu         $t9, 0x74($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X74);
    // 0x80166A6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80166A70: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x80166A74: beq         $t7, $zero, L_80166BA8
    if (ctx->r15 == 0) {
        // 0x80166A78: ori         $t1, $t9, 0xE
        ctx->r9 = ctx->r25 | 0XE;
            goto L_80166BA8;
    }
    // 0x80166A78: ori         $t1, $t9, 0xE
    ctx->r9 = ctx->r25 | 0XE;
    // 0x80166A7C: sb          $t1, 0x74($sp)
    MEM_B(0X74, ctx->r29) = ctx->r9;
    // 0x80166A80: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80166A84: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_80166A88:
    // 0x80166A88: lw          $t0, 0x114($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X114);
    // 0x80166A8C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80166A90: bne         $s7, $t0, L_80166AA8
    if (ctx->r23 != ctx->r8) {
        // 0x80166A94: nop
    
            goto L_80166AA8;
    }
    // 0x80166A94: nop

    // 0x80166A98: lw          $t4, 0x118($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X118);
    // 0x80166A9C: addiu       $t2, $sp, 0x74
    ctx->r10 = ADD32(ctx->r29, 0X74);
    // 0x80166AA0: b           L_80166AB0
    // 0x80166AA4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
        goto L_80166AB0;
    // 0x80166AA4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80166AA8:
    // 0x80166AA8: bne         $v1, $a1, L_80166A88
    if (ctx->r3 != ctx->r5) {
        // 0x80166AAC: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80166A88;
    }
    // 0x80166AAC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80166AB0:
    // 0x80166AB0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80166AB4: lbu         $t9, 0x78($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X78);
    // 0x80166AB8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80166ABC: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x80166AC0: srl         $t7, $t5, 29
    ctx->r15 = S32(U32(ctx->r13) >> 29);
    // 0x80166AC4: bne         $t7, $at, L_80166BA8
    if (ctx->r15 != ctx->r1) {
        // 0x80166AC8: ori         $t1, $t9, 0xE
        ctx->r9 = ctx->r25 | 0XE;
            goto L_80166BA8;
    }
    // 0x80166AC8: ori         $t1, $t9, 0xE
    ctx->r9 = ctx->r25 | 0XE;
    // 0x80166ACC: sb          $t1, 0x78($sp)
    MEM_B(0X78, ctx->r29) = ctx->r9;
    // 0x80166AD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80166AD4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80166AD8:
    // 0x80166AD8: lw          $t0, 0x114($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X114);
    // 0x80166ADC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80166AE0: bne         $s5, $t0, L_80166AF8
    if (ctx->r21 != ctx->r8) {
        // 0x80166AE4: nop
    
            goto L_80166AF8;
    }
    // 0x80166AE4: nop

    // 0x80166AE8: lw          $t4, 0x118($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X118);
    // 0x80166AEC: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x80166AF0: b           L_80166B00
    // 0x80166AF4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
        goto L_80166B00;
    // 0x80166AF4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80166AF8:
    // 0x80166AF8: bne         $v1, $fp, L_80166AD8
    if (ctx->r3 != ctx->r30) {
        // 0x80166AFC: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80166AD8;
    }
    // 0x80166AFC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80166B00:
    // 0x80166B00: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80166B04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80166B08: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x80166B0C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x80166B10: srl         $t7, $t5, 29
    ctx->r15 = S32(U32(ctx->r13) >> 29);
    // 0x80166B14: bnel        $t7, $at, L_80166BAC
    if (ctx->r15 != ctx->r1) {
        // 0x80166B18: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_10;
    // 0x80166B18: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_10:
    // 0x80166B1C: lw          $t8, 0x50($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X50);
    // 0x80166B20: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80166B24: blezl       $t8, L_80166BAC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80166B28: lw          $s5, 0x4($s5)
        ctx->r21 = MEM_W(ctx->r21, 0X4);
            goto L_80166BAC;
    }
    goto skip_11;
    // 0x80166B28: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    skip_11:
    // 0x80166B2C: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
L_80166B30:
    // 0x80166B30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80166B34: blez        $t9, L_80166B94
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80166B38: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80166B94;
    }
    // 0x80166B38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80166B3C:
    // 0x80166B3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80166B40: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80166B44: jal         0x800F007C
    // 0x80166B48: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gmCollisionCheckWeaponAttacksCollide(rdram, ctx);
        goto after_0;
    // 0x80166B48: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x80166B4C: beql        $v0, $zero, L_80166B84
    if (ctx->r2 == 0) {
        // 0x80166B50: lw          $t1, 0x50($s4)
        ctx->r9 = MEM_W(ctx->r20, 0X50);
            goto L_80166B84;
    }
    goto skip_12;
    // 0x80166B50: lw          $t1, 0x50($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X50);
    skip_12:
    // 0x80166B54: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80166B58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80166B5C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80166B60: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80166B64: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80166B68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80166B6C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x80166B70: jal         0x80166854
    // 0x80166B74: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    wpProcessUpdateAttackStatWeapon(rdram, ctx);
        goto after_1;
    // 0x80166B74: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    after_1:
    // 0x80166B78: b           L_80166BAC
    // 0x80166B7C: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
        goto L_80166BAC;
    // 0x80166B7C: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
    // 0x80166B80: lw          $t1, 0x50($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X50);
L_80166B84:
    // 0x80166B84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80166B88: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80166B8C: bnel        $at, $zero, L_80166B3C
    if (ctx->r1 != 0) {
        // 0x80166B90: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80166B3C;
    }
    goto skip_13;
    // 0x80166B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_13:
L_80166B94:
    // 0x80166B94: lw          $t0, 0x50($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X50);
    // 0x80166B98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80166B9C: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80166BA0: bnel        $at, $zero, L_80166B30
    if (ctx->r1 != 0) {
        // 0x80166BA4: lw          $t9, 0x50($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X50);
            goto L_80166B30;
    }
    goto skip_14;
    // 0x80166BA4: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
    skip_14:
L_80166BA8:
    // 0x80166BA8: lw          $s5, 0x4($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X4);
L_80166BAC:
    // 0x80166BAC: bnel        $s5, $zero, L_801669DC
    if (ctx->r21 != 0) {
        // 0x80166BB0: lw          $a2, 0x84($s5)
        ctx->r6 = MEM_W(ctx->r21, 0X84);
            goto L_801669DC;
    }
    goto skip_15;
    // 0x80166BB0: lw          $a2, 0x84($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X84);
    skip_15:
    // 0x80166BB4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80166BB8:
    // 0x80166BB8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80166BBC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80166BC0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80166BC4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80166BC8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80166BCC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80166BD0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80166BD4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80166BD8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80166BDC: jr          $ra
    // 0x80166BE0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80166BE0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void itCapsuleFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017409C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801740A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801740A4: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x801740A8: lbu         $t7, 0x2CE($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2CE);
    // 0x801740AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801740B0: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801740B4: sb          $t8, 0x2CE($a3)
    MEM_B(0X2CE, ctx->r7) = ctx->r24;
    // 0x801740B8: jal         0x80173F78
    // 0x801740BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801740BC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801740C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x801740C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801740C8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801740CC: lbu         $t0, 0x2CF($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X2CF);
    // 0x801740D0: sw          $t2, 0x248($a3)
    MEM_W(0X248, ctx->r7) = ctx->r10;
    // 0x801740D4: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x801740D8: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x801740DC: sb          $t1, 0x2CF($a3)
    MEM_B(0X2CF, ctx->r7) = ctx->r9;
    // 0x801740E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801740E4: jal         0x80172EC8
    // 0x801740E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801740E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801740EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801740F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801740F4: jr          $ra
    // 0x801740F8: nop

    return;
    // 0x801740F8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckGameModeInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135800: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135804: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135808: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013580C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135810: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80135814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135818: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013581C: lui         $at, 0x434F
    ctx->r1 = S32(0X434F << 16);
    // 0x80135820: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135824: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80135828: nop

    // 0x8013582C: bc1f        L_80135854
    if (!c1cs) {
        // 0x80135830: nop
    
            goto L_80135854;
    }
    // 0x80135830: nop

    // 0x80135834: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135838: nop

    // 0x8013583C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135840: nop

    // 0x80135844: bc1f        L_80135854
    if (!c1cs) {
        // 0x80135848: nop
    
            goto L_80135854;
    }
    // 0x80135848: nop

    // 0x8013584C: b           L_80135854
    // 0x80135850: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135854;
    // 0x80135850: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135854:
    // 0x80135854: beq         $v1, $zero, L_801358B8
    if (ctx->r3 == 0) {
        // 0x80135858: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801358B8;
    }
    // 0x80135858: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013585C: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135860: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135864: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80135868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013586C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80135870: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80135874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135878: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8013587C: nop

    // 0x80135880: bc1f        L_801358A8
    if (!c1cs) {
        // 0x80135884: nop
    
            goto L_801358A8;
    }
    // 0x80135884: nop

    // 0x80135888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013588C: nop

    // 0x80135890: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135894: nop

    // 0x80135898: bc1f        L_801358A8
    if (!c1cs) {
        // 0x8013589C: nop
    
            goto L_801358A8;
    }
    // 0x8013589C: nop

    // 0x801358A0: b           L_801358A8
    // 0x801358A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801358A8;
    // 0x801358A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801358A8:
    // 0x801358A8: beql        $v1, $zero, L_801358BC
    if (ctx->r3 == 0) {
        // 0x801358AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801358BC;
    }
    goto skip_0;
    // 0x801358AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801358B0: jr          $ra
    // 0x801358B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801358B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801358B8:
    // 0x801358B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801358BC:
    // 0x801358BC: jr          $ra
    // 0x801358C0: nop

    return;
    // 0x801358C0: nop

;}
RECOMP_FUNC void __readVarLen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002852C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028534: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80028538: jal         0x80028468
    // 0x8002853C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_0;
    // 0x8002853C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x80028540: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80028544: beq         $t6, $zero, L_80028570
    if (ctx->r14 == 0) {
        // 0x80028548: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_80028570;
    }
    // 0x80028548: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8002854C: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_80028550:
    // 0x80028550: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80028554: jal         0x80028468
    // 0x80028558: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_1;
    // 0x80028558: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x8002855C: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x80028560: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x80028564: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x80028568: bne         $t9, $zero, L_80028550
    if (ctx->r25 != 0) {
        // 0x8002856C: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_80028550;
    }
    // 0x8002856C: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_80028570:
    // 0x80028570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028578: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8002857C: jr          $ra
    // 0x80028580: nop

    return;
    // 0x80028580: nop

    // 0x80028584: jr          $ra
    // 0x80028588: nop

    return;
    // 0x80028588: nop

;}
RECOMP_FUNC void grInishiePowerBlockSetDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109B54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80109B58: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80109B5C: addiu       $a1, $a1, -0x6474
    ctx->r5 = ADD32(ctx->r5, -0X6474);
    // 0x80109B60: jal         0x800E1DE8
    // 0x80109B64: lw          $a0, 0x142C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X142C);
    ftMainCheckAddGroundHazard(rdram, ctx);
        goto after_0;
    // 0x80109B64: lw          $a0, 0x142C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X142C);
    after_0:
    // 0x80109B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109B6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109B70: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109B74: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80109B78: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80109B7C: sh          $t6, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r14;
    // 0x80109B80: sb          $t7, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r15;
    // 0x80109B84: jr          $ra
    // 0x80109B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80109B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftParamLockPlayerControl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F14: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E7F18: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x800E7F1C: sb          $zero, 0x1C9($v0)
    MEM_B(0X1C9, ctx->r2) = 0;
    // 0x800E7F20: lb          $a1, 0x1C9($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1C9);
    // 0x800E7F24: sb          $t6, 0x26B($v0)
    MEM_B(0X26B, ctx->r2) = ctx->r14;
    // 0x800E7F28: lb          $a2, 0x26B($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X26B);
    // 0x800E7F2C: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
    // 0x800E7F30: sh          $zero, 0x1C6($v0)
    MEM_H(0X1C6, ctx->r2) = 0;
    // 0x800E7F34: sh          $zero, 0x1BE($v0)
    MEM_H(0X1BE, ctx->r2) = 0;
    // 0x800E7F38: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800E7F3C: sh          $zero, 0x1BC($v0)
    MEM_H(0X1BC, ctx->r2) = 0;
    // 0x800E7F40: sb          $t9, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r25;
    // 0x800E7F44: sb          $a1, 0x1C8($v0)
    MEM_B(0X1C8, ctx->r2) = ctx->r5;
    // 0x800E7F48: sb          $a1, 0x1C5($v0)
    MEM_B(0X1C5, ctx->r2) = ctx->r5;
    // 0x800E7F4C: sb          $a1, 0x1C4($v0)
    MEM_B(0X1C4, ctx->r2) = ctx->r5;
    // 0x800E7F50: sb          $a1, 0x1C3($v0)
    MEM_B(0X1C3, ctx->r2) = ctx->r5;
    // 0x800E7F54: sb          $a1, 0x1C2($v0)
    MEM_B(0X1C2, ctx->r2) = ctx->r5;
    // 0x800E7F58: sb          $a2, 0x26A($v0)
    MEM_B(0X26A, ctx->r2) = ctx->r6;
    // 0x800E7F5C: sb          $a2, 0x269($v0)
    MEM_B(0X269, ctx->r2) = ctx->r6;
    // 0x800E7F60: jr          $ra
    // 0x800E7F64: sb          $a2, 0x268($v0)
    MEM_B(0X268, ctx->r2) = ctx->r6;
    return;
    // 0x800E7F64: sb          $a2, 0x268($v0)
    MEM_B(0X268, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void ftCommonCliffAttackQuick1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014566C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145674: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80145678: jal         0x800D9480
    // 0x8014567C: addiu       $a1, $a1, 0x5754
    ctx->r5 = ADD32(ctx->r5, 0X5754);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014567C: addiu       $a1, $a1, 0x5754
    ctx->r5 = ADD32(ctx->r5, 0X5754);
    after_0:
    // 0x80145680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145688: jr          $ra
    // 0x8014568C: nop

    return;
    // 0x8014568C: nop

;}
RECOMP_FUNC void func_ovl8_8037C440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C448: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037C44C: beq         $a0, $zero, L_8037C488
    if (ctx->r4 == 0) {
        // 0x8037C450: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8037C488;
    }
    // 0x8037C450: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037C454: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C458: addiu       $t6, $t6, -0x5E60
    ctx->r14 = ADD32(ctx->r14, -0X5E60);
    // 0x8037C45C: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x8037C460: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x8037C464: jal         0x80009A84
    // 0x8037C468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8037C468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037C46C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8037C470: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8037C474: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8037C478: beql        $t8, $zero, L_8037C48C
    if (ctx->r24 == 0) {
        // 0x8037C47C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037C48C;
    }
    goto skip_0;
    // 0x8037C47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037C480: jal         0x803717C0
    // 0x8037C484: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_1;
    // 0x8037C484: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_8037C488:
    // 0x8037C488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037C48C:
    // 0x8037C48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C490: jr          $ra
    // 0x8037C494: nop

    return;
    // 0x8037C494: nop

;}

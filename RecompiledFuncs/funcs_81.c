#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_ovl8_80374C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374C98: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80374C9C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374CA0: lw          $t9, 0x13C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X13C);
    // 0x80374CA4: lh          $t6, 0x138($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X138);
    // 0x80374CA8: jalr        $t9
    // 0x80374CAC: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374CAC: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80374CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374CB8: jr          $ra
    // 0x80374CBC: nop

    return;
    // 0x80374CBC: nop

;}
RECOMP_FUNC void itMapSetGroundRebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173A48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80173A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173A50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80173A54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80173A58: jal         0x800C7A84
    // 0x80173A5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    lbCommonMag2D(rdram, ctx);
        goto after_0;
    // 0x80173A5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80173A60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80173A64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80173A68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80173A6C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80173A70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80173A74: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80173A78: bc1tl       L_80173B18
    if (c1cs) {
        // 0x80173A7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80173B18;
    }
    goto skip_0;
    // 0x80173A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80173A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80173A84: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80173A88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80173A8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80173A90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80173A94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80173A98: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80173A9C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80173AA0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x80173AA4: jal         0x800C7B08
    // 0x80173AA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    lbCommonReflect2D(rdram, ctx);
        goto after_1;
    // 0x80173AA8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80173AAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80173AB0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80173AB4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80173AB8: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80173ABC: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80173AC0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80173AC4: nop

    // 0x80173AC8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80173ACC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80173AD0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80173AD4: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80173AD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80173ADC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80173AE0: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80173AE4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80173AE8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80173AEC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80173AF0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80173AF4: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80173AF8: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80173AFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80173B00: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80173B04: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80173B08: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80173B0C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80173B10: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80173B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80173B18:
    // 0x80173B18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80173B1C: jr          $ra
    // 0x80173B20: nop

    return;
    // 0x80173B20: nop

;}
RECOMP_FUNC void func_ovl8_8037E818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E818: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037E81C: jr          $ra
    // 0x8037E820: lhu         $v0, -0xFBC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFBC);
    return;
    // 0x8037E820: lhu         $v0, -0xFBC($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFBC);
;}
RECOMP_FUNC void ftNessSpecialLwHitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015594C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155950: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80155954: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015595C: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x80155960: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155964: jal         0x800E6F24
    // 0x80155968: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155968: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015596C: jal         0x800E0830
    // 0x80155970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155970: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155974: jal         0x80155934
    // 0x80155978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialLwHitSetAbsorbTrue(rdram, ctx);
        goto after_2;
    // 0x80155978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015597C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155984: jr          $ra
    // 0x80155988: nop

    return;
    // 0x80155988: nop

;}
RECOMP_FUNC void itDisplayCheckItemVisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171C10: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80171C14: bnel        $v0, $zero, L_80171C28
    if (ctx->r2 != 0) {
        // 0x80171C18: lw          $t6, 0x2CC($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X2CC);
            goto L_80171C28;
    }
    goto skip_0;
    // 0x80171C18: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    skip_0:
    // 0x80171C1C: jr          $ra
    // 0x80171C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80171C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80171C24: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
L_80171C28:
    // 0x80171C28: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80171C2C: bltzl       $t8, L_80171C40
    if (SIGNED(ctx->r24) < 0) {
        // 0x80171C30: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_80171C40;
    }
    goto skip_1;
    // 0x80171C30: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_1:
    // 0x80171C34: jr          $ra
    // 0x80171C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80171C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80171C3C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_80171C40:
    // 0x80171C40: lw          $t9, 0x190($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X190);
    // 0x80171C44: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x80171C48: bltzl       $t1, L_80171C5C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80171C4C: lhu         $t2, 0x18C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X18C);
            goto L_80171C5C;
    }
    goto skip_2;
    // 0x80171C4C: lhu         $t2, 0x18C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X18C);
    skip_2:
    // 0x80171C50: jr          $ra
    // 0x80171C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80171C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80171C58: lhu         $t2, 0x18C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X18C);
L_80171C5C:
    // 0x80171C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80171C60: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80171C64: beq         $t3, $zero, L_80171C74
    if (ctx->r11 == 0) {
        // 0x80171C68: nop
    
            goto L_80171C74;
    }
    // 0x80171C68: nop

    // 0x80171C6C: jr          $ra
    // 0x80171C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80171C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80171C74:
    // 0x80171C74: jr          $ra
    // 0x80171C78: nop

    return;
    // 0x80171C78: nop

;}
RECOMP_FUNC void ifCommon1PGameInterfaceProcSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114C28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114C2C: addiu       $a1, $a1, 0x366C
    ctx->r5 = ADD32(ctx->r5, 0X366C);
    // 0x80114C30: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80114C34: jal         0x8000AEF0
    // 0x80114C38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_0;
    // 0x80114C38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80114C3C: jal         0x80104D30
    // 0x80114C40: nop

    grWallpaperResumeProcessAll(rdram, ctx);
        goto after_1;
    // 0x80114C40: nop

    after_1:
    // 0x80114C44: jal         0x80113F74
    // 0x80114C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_2;
    // 0x80114C48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80114C4C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80114C50: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80114C54: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80114C58: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80114C5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114C60: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80114C64: jal         0x8018F3AC
    // 0x80114C68: sh          $t8, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r24;
    sc1PGameSetCameraZoom(rdram, ctx);
        goto after_3;
    // 0x80114C68: sh          $t8, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r24;
    after_3:
    // 0x80114C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114C70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114C74: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
    // 0x80114C78: jr          $ra
    // 0x80114C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80114C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnPlayers1PBonusMakePuckAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013649C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801364A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801364A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801364A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801364AC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801364B0: jal         0x80009968
    // 0x801364B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801364B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801364B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801364BC: addiu       $a1, $a1, 0x6450
    ctx->r5 = ADD32(ctx->r5, 0X6450);
    // 0x801364C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801364C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801364C8: jal         0x80008188
    // 0x801364CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x801364CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801364D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801364D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801364D8: jr          $ra
    // 0x801364DC: nop

    return;
    // 0x801364DC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F6AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F6B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F6B4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F6B8: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015F6BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015F6C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F6C4: addiu       $a1, $zero, 0x12A
    ctx->r5 = ADD32(0, 0X12A);
    // 0x8015F6C8: jal         0x800E6F24
    // 0x8015F6CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F6CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015F6D0: jal         0x800E0830
    // 0x8015F6D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F6D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015F6D8: jal         0x8015F668
    // 0x8015F6DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyYoshiSpecialNCatchInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015F6DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015F6E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F6E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F6E8: jr          $ra
    // 0x8015F6EC: nop

    return;
    // 0x8015F6EC: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B82C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B830: jal         0x800DE80C
    // 0x8015B834: addiu       $a1, $a1, -0x47B8
    ctx->r5 = ADD32(ctx->r5, -0X47B8);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015B834: addiu       $a1, $a1, -0x47B8
    ctx->r5 = ADD32(ctx->r5, -0X47B8);
    after_0:
    // 0x8015B838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B83C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B840: jr          $ra
    // 0x8015B844: nop

    return;
    // 0x8015B844: nop

;}
RECOMP_FUNC void efManagerDustCollideMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FECBC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FECC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FECC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FECC8: jal         0x800FD4B8
    // 0x800FECCC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FECCC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FECD0: bne         $v0, $zero, L_800FECE0
    if (ctx->r2 != 0) {
        // 0x800FECD4: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FECE0;
    }
    // 0x800FECD4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FECD8: b           L_800FEE9C
    // 0x800FECDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEE9C;
    // 0x800FECDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FECE0:
    // 0x800FECE0: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FECE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FECE8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FECEC: jal         0x80009968
    // 0x800FECF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FECF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FECF4: bne         $v0, $zero, L_800FED0C
    if (ctx->r2 != 0) {
        // 0x800FECF8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FED0C;
    }
    // 0x800FECF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FECFC: jal         0x800FD4F8
    // 0x800FED00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FED00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FED04: b           L_800FEE9C
    // 0x800FED08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEE9C;
    // 0x800FED08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FED0C:
    // 0x800FED0C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FED10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FED14: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800FED18: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FED1C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FED20: jal         0x800CE9E8
    // 0x800FED24: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FED24: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FED28: beq         $v0, $zero, L_800FEE8C
    if (ctx->r2 == 0) {
        // 0x800FED2C: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FEE8C;
    }
    // 0x800FED2C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FED30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FED34: jal         0x800CE1DC
    // 0x800FED38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FED38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FED3C: beq         $v0, $zero, L_800FEE78
    if (ctx->r2 == 0) {
        // 0x800FED40: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FEE78;
    }
    // 0x800FED40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FED44: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FED48: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FED4C: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FED50: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FED54: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FED58: jal         0x800CEA14
    // 0x800FED5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FED5C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FED60: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FED64: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FED68: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FED6C: bne         $t9, $zero, L_800FED7C
    if (ctx->r25 != 0) {
        // 0x800FED70: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FED7C;
    }
    // 0x800FED70: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FED74: b           L_800FEE9C
    // 0x800FED78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEE9C;
    // 0x800FED78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FED7C:
    // 0x800FED7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FED80: jal         0x80008188
    // 0x800FED84: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FED84: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FED88: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FED8C: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FED90: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FED94: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FED98: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FED9C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FEDA0: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FEDA4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FEDA8: jal         0x80018948
    // 0x800FEDAC: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FEDAC: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FEDB0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800FEDB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEDB8: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FEDBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FEDC0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEDC4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FEDC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEDCC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800FEDD0: jal         0x80018948
    // 0x800FEDD4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FEDD4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_8:
    // 0x800FEDD8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800FEDDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEDE0: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FEDE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FEDE8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEDEC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FEDF0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEDF4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FEDF8: jal         0x80018948
    // 0x800FEDFC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x800FEDFC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x800FEE00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEE04: lwc1        $f4, 0x964($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X964);
    // 0x800FEE08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEE0C: lwc1        $f8, 0x968($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X968);
    // 0x800FEE10: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEE14: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEE18: jal         0x80035CD0
    // 0x800FEE1C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FEE1C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x800FEE20: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800FEE24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FEE28: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FEE2C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FEE30: swc1        $f16, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f16.u32l;
    // 0x800FEE34: jal         0x800303F0
    // 0x800FEE38: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_11;
    // 0x800FEE38: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x800FEE3C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800FEE40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FEE44: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FEE48: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FEE4C: jal         0x80018948
    // 0x800FEE50: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_12;
    // 0x800FEE50: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    after_12:
    // 0x800FEE54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FEE58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FEE5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FEE60: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FEE64: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FEE68: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x800FEE6C: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x800FEE70: b           L_800FEE98
    // 0x800FEE74: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
        goto L_800FEE98;
    // 0x800FEE74: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
L_800FEE78:
    // 0x800FEE78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FEE7C: jal         0x800FDB3C
    // 0x800FEE80: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_13;
    // 0x800FEE80: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x800FEE84: b           L_800FEE98
    // 0x800FEE88: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FEE98;
    // 0x800FEE88: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FEE8C:
    // 0x800FEE8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FEE90: jal         0x800FDB3C
    // 0x800FEE94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_14;
    // 0x800FEE94: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_14:
L_800FEE98:
    // 0x800FEE98: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FEE9C:
    // 0x800FEE9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FEEA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FEEA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FEEA8: jr          $ra
    // 0x800FEEAC: nop

    return;
    // 0x800FEEAC: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DED4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014DED8: jal         0x800DDDDC
    // 0x8014DEDC: addiu       $a1, $a1, -0x2180
    ctx->r5 = ADD32(ctx->r5, -0X2180);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8014DEDC: addiu       $a1, $a1, -0x2180
    ctx->r5 = ADD32(ctx->r5, -0X2180);
    after_0:
    // 0x8014DEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014DEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DEE8: jr          $ra
    // 0x8014DEEC: nop

    return;
    // 0x8014DEEC: nop

;}
RECOMP_FUNC void scStaffrollGetPauseStatusHighlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013341C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133420: lbu         $t6, -0x56FC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X56FC);
    // 0x80133424: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80133428: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013342C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80133430: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80133434: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80133438: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8013343C: lhu         $v0, 0x522A($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X522A);
    // 0x80133440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133448: andi        $t8, $v0, 0xC000
    ctx->r24 = ctx->r2 & 0XC000;
    // 0x8013344C: beq         $t8, $zero, L_801334D0
    if (ctx->r24 == 0) {
        // 0x80133450: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801334D0;
    }
    // 0x80133450: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133454: jal         0x8013330C
    // 0x80133458: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_ovl59_8013330C(rdram, ctx);
        goto after_0;
    // 0x80133458: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013345C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80133460: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133464: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x80133468: beql        $t9, $zero, L_801334D4
    if (ctx->r25 == 0) {
        // 0x8013346C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801334D4;
    }
    goto skip_0;
    // 0x8013346C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80133470: lw          $a0, -0x5738($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5738);
    // 0x80133474: beq         $a0, $zero, L_80133484
    if (ctx->r4 == 0) {
        // 0x80133478: nop
    
            goto L_80133484;
    }
    // 0x80133478: nop

    // 0x8013347C: jal         0x8000B284
    // 0x80133480: nop

    gcPauseGObjProcessAll(rdram, ctx);
        goto after_1;
    // 0x80133480: nop

    after_1:
L_80133484:
    // 0x80133484: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80133488: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8013348C: beq         $s0, $zero, L_801334A8
    if (ctx->r16 == 0) {
        // 0x80133490: nop
    
            goto L_801334A8;
    }
    // 0x80133490: nop

L_80133494:
    // 0x80133494: jal         0x8000B284
    // 0x80133498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPauseGObjProcessAll(rdram, ctx);
        goto after_2;
    // 0x80133498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013349C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x801334A0: bne         $s0, $zero, L_80133494
    if (ctx->r16 != 0) {
        // 0x801334A4: nop
    
            goto L_80133494;
    }
    // 0x801334A4: nop

L_801334A8:
    // 0x801334A8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801334AC: lw          $s0, 0x6700($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6700);
    // 0x801334B0: beql        $s0, $zero, L_801334D0
    if (ctx->r16 == 0) {
        // 0x801334B4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_801334D0;
    }
    goto skip_1;
    // 0x801334B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
L_801334B8:
    // 0x801334B8: jal         0x8000B284
    // 0x801334BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPauseGObjProcessAll(rdram, ctx);
        goto after_3;
    // 0x801334BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801334C0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x801334C4: bne         $s0, $zero, L_801334B8
    if (ctx->r16 != 0) {
        // 0x801334C8: nop
    
            goto L_801334B8;
    }
    // 0x801334C8: nop

    // 0x801334CC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_801334D0:
    // 0x801334D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801334D4:
    // 0x801334D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801334D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801334DC: jr          $ra
    // 0x801334E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801334E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayersVSCheckPlayerKindSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801365D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801365D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801365D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801365DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801365E0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x801365E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801365E8: jal         0x80135AB8
    // 0x801365EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    mnPlayersVSCheckPlayerKindSelectInRange(rdram, ctx);
        goto after_0;
    // 0x801365EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x801365F0: beq         $v0, $zero, L_80136754
    if (ctx->r2 == 0) {
        // 0x801365F4: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_80136754;
    }
    // 0x801365F4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x801365F8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801365FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80136600: lw          $t7, -0x4270($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4270);
    // 0x80136604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80136608: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8013660C: bne         $t7, $at, L_8013665C
    if (ctx->r15 != ctx->r1) {
        // 0x80136610: subu        $t1, $t1, $s1
        ctx->r9 = SUB32(ctx->r9, ctx->r17);
            goto L_8013665C;
    }
    // 0x80136610: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80136614: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80136618: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8013661C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80136620: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80136624: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80136628: addiu       $t9, $t9, -0x4578
    ctx->r25 = ADD32(ctx->r25, -0X4578);
    // 0x8013662C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80136630: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80136634: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80136638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013663C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80136640: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80136644: bne         $at, $zero, L_80136654
    if (ctx->r1 != 0) {
        // 0x80136648: nop
    
            goto L_80136654;
    }
    // 0x80136648: nop

    // 0x8013664C: b           L_80136694
    // 0x80136650: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
        goto L_80136694;
    // 0x80136650: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
L_80136654:
    // 0x80136654: b           L_80136694
    // 0x80136658: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
        goto L_80136694;
    // 0x80136658: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
L_8013665C:
    // 0x8013665C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80136660: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80136664: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136668: addiu       $t2, $t2, -0x4578
    ctx->r10 = ADD32(ctx->r10, -0X4578);
    // 0x8013666C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80136670: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80136674: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80136678: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8013667C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80136680: bnel        $at, $zero, L_80136694
    if (ctx->r1 != 0) {
        // 0x80136684: sw          $v0, 0x84($s0)
        MEM_W(0X84, ctx->r16) = ctx->r2;
            goto L_80136694;
    }
    goto skip_0;
    // 0x80136684: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    skip_0:
    // 0x80136688: b           L_80136694
    // 0x8013668C: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
        goto L_80136694;
    // 0x8013668C: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80136690: sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
L_80136694:
    // 0x80136694: jal         0x80135C84
    // 0x80136698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdatePlayerKind(rdram, ctx);
        goto after_1;
    // 0x80136698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8013669C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801366A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801366A4: jal         0x8013295C
    // 0x801366A8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSUpdatePlayerKindSelect(rdram, ctx);
        goto after_2;
    // 0x801366A8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_2:
    // 0x801366AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x801366B0: jal         0x80136038
    // 0x801366B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdatePuckDisplay(rdram, ctx);
        goto after_3;
    // 0x801366B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x801366B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801366BC: jal         0x801361F8
    // 0x801366C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSUpdateCursorDisplay(rdram, ctx);
        goto after_4;
    // 0x801366C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x801366C4: jal         0x80136128
    // 0x801366C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateFighter(rdram, ctx);
        goto after_5;
    // 0x801366C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801366CC: jal         0x80136300
    // 0x801366D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_6;
    // 0x801366D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x801366D4: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x801366D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801366DC: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    // 0x801366E0: beq         $v0, $zero, L_80136704
    if (ctx->r2 == 0) {
        // 0x801366E4: nop
    
            goto L_80136704;
    }
    // 0x801366E4: nop

    // 0x801366E8: beq         $v0, $at, L_80136714
    if (ctx->r2 == ctx->r1) {
        // 0x801366EC: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_80136714;
    }
    // 0x801366EC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801366F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801366F4: beq         $v0, $at, L_8013673C
    if (ctx->r2 == ctx->r1) {
        // 0x801366F8: nop
    
            goto L_8013673C;
    }
    // 0x801366F8: nop

    // 0x801366FC: b           L_80136744
    // 0x80136700: nop

        goto L_80136744;
    // 0x80136700: nop

L_80136704:
    // 0x80136704: jal         0x800269C0
    // 0x80136708: sw          $s1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r17;
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80136708: sw          $s1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r17;
    after_7:
    // 0x8013670C: b           L_80136744
    // 0x80136710: nop

        goto L_80136744;
    // 0x80136710: nop

L_80136714:
    // 0x80136714: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80136718: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013671C: jal         0x801367F0
    // 0x80136720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSAnnounceFighter(rdram, ctx);
        goto after_8;
    // 0x80136720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80136724: jal         0x80137004
    // 0x80136728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_9;
    // 0x80136728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8013672C: jal         0x8013647C
    // 0x80136730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSMakePortraitFlash(rdram, ctx);
        goto after_10;
    // 0x80136730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80136734: b           L_80136744
    // 0x80136738: nop

        goto L_80136744;
    // 0x80136738: nop

L_8013673C:
    // 0x8013673C: jal         0x800269C0
    // 0x80136740: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    func_800269C0_275C0(rdram, ctx);
        goto after_11;
    // 0x80136740: addiu       $a0, $zero, 0xA7
    ctx->r4 = ADD32(0, 0XA7);
    after_11:
L_80136744:
    // 0x80136744: jal         0x800269C0
    // 0x80136748: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x80136748: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_12:
    // 0x8013674C: b           L_80136758
    // 0x80136750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136758;
    // 0x80136750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136754:
    // 0x80136754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136758:
    // 0x80136758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013675C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136760: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136764: jr          $ra
    // 0x80136768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80136768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154CBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154CC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154CC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80154CC8: jal         0x800DEE98
    // 0x80154CCC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80154CCC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80154CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154CD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80154CD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80154CDC: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80154CE0: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80154CE4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154CE8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80154CEC: addiu       $t7, $zero, 0x93
    ctx->r15 = ADD32(0, 0X93);
    // 0x80154CF0: bc1fl       L_80154D04
    if (!c1cs) {
        // 0x80154CF4: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80154D04;
    }
    goto skip_0;
    // 0x80154CF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80154CF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80154CFC: nop

    // 0x80154D00: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80154D04:
    // 0x80154D04: jal         0x800E6F24
    // 0x80154D08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154D08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80154D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154D14: jr          $ra
    // 0x80154D18: nop

    return;
    // 0x80154D18: nop

;}
RECOMP_FUNC void ftDisplayMainDrawSkeleton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F21B4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F21B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F21BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F21C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F21C4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800F21C8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800F21CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F21D0: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800F21D4: addiu       $t1, $t1, 0x62D0
    ctx->r9 = ADD32(ctx->r9, 0X62D0);
    // 0x800F21D8: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x800F21DC: lbu         $t8, 0x54($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X54);
    // 0x800F21E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800F21E4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800F21E8: bnel        $t9, $zero, L_800F2464
    if (ctx->r25 != 0) {
        // 0x800F21EC: lw          $t6, 0xC($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XC);
            goto L_800F2464;
    }
    goto skip_0;
    // 0x800F21EC: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x800F21F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800F21F4: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x800F21F8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800F21FC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800F2200: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800F2204: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800F2208: beq         $v0, $zero, L_800F23C8
    if (ctx->r2 == 0) {
        // 0x800F220C: sw          $t3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r11;
            goto L_800F23C8;
    }
    // 0x800F220C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x800F2210: lbu         $v1, 0xD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD);
    // 0x800F2214: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800F2218: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800F221C: bne         $at, $zero, L_800F23C8
    if (ctx->r1 != 0) {
        // 0x800F2220: nop
    
            goto L_800F23C8;
    }
    // 0x800F2220: nop

    // 0x800F2224: lw          $t5, 0x9C8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X9C8);
    // 0x800F2228: lw          $t7, 0xA88($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XA88);
    // 0x800F222C: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x800F2230: lw          $t6, 0x344($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X344);
    // 0x800F2234: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800F2238: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x800F223C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800F2240: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x800F2244: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800F2248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F224C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F2250: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800F2254: addiu       $t4, $t5, -0x20
    ctx->r12 = ADD32(ctx->r13, -0X20);
    // 0x800F2258: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800F225C: lbu         $a0, 0x4($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X4);
    // 0x800F2260: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x800F2264: beq         $v0, $zero, L_800F227C
    if (ctx->r2 == 0) {
        // 0x800F2268: nop
    
            goto L_800F227C;
    }
    // 0x800F2268: nop

    // 0x800F226C: beq         $v0, $at, L_800F22F8
    if (ctx->r2 == ctx->r1) {
        // 0x800F2270: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_800F22F8;
    }
    // 0x800F2270: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800F2274: b           L_800F23E0
    // 0x800F2278: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
        goto L_800F23E0;
    // 0x800F2278: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
L_800F227C:
    // 0x800F227C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F2280: jal         0x80010D70
    // 0x800F2284: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800F2284: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    after_0:
    // 0x800F2288: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800F228C: lbu         $t7, 0x54($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X54);
    // 0x800F2290: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800F2294: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800F2298: bnel        $t8, $zero, L_800F23E0
    if (ctx->r24 != 0) {
        // 0x800F229C: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F23E0;
    }
    goto skip_1;
    // 0x800F229C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_1:
    // 0x800F22A0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800F22A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F22A8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F22AC: beql        $t6, $zero, L_800F23E0
    if (ctx->r14 == 0) {
        // 0x800F22B0: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F23E0;
    }
    goto skip_2;
    // 0x800F22B0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_2:
    // 0x800F22B4: jal         0x80012D90
    // 0x800F22B8: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x800F22B8: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    after_1:
    // 0x800F22BC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800F22C0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800F22C4: jal         0x800F1C08
    // 0x800F22C8: lbu         $a0, 0x4($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X4);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_2;
    // 0x800F22C8: lbu         $a0, 0x4($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X4);
    after_2:
    // 0x800F22CC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800F22D0: lw          $v0, 0x65B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65B0);
    // 0x800F22D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800F22D8: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800F22DC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800F22E0: sw          $t1, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r9;
    // 0x800F22E4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800F22E8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800F22EC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800F22F0: b           L_800F23DC
    // 0x800F22F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800F23DC;
    // 0x800F22F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800F22F8:
    // 0x800F22F8: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x800F22FC: beq         $s0, $zero, L_800F234C
    if (ctx->r16 == 0) {
        // 0x800F2300: nop
    
            goto L_800F234C;
    }
    // 0x800F2300: nop

    // 0x800F2304: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800F2308: beq         $t7, $zero, L_800F234C
    if (ctx->r15 == 0) {
        // 0x800F230C: nop
    
            goto L_800F234C;
    }
    // 0x800F230C: nop

    // 0x800F2310: lbu         $t8, 0x54($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X54);
    // 0x800F2314: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800F2318: bne         $t9, $zero, L_800F234C
    if (ctx->r25 != 0) {
        // 0x800F231C: nop
    
            goto L_800F234C;
    }
    // 0x800F231C: nop

    // 0x800F2320: jal         0x800F1C08
    // 0x800F2324: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_3;
    // 0x800F2324: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_3:
    // 0x800F2328: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F232C: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F2330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800F2334: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800F2338: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800F233C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F2340: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800F2344: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800F2348: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800F234C:
    // 0x800F234C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F2350: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F2354: jal         0x80010D70
    // 0x800F2358: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_4;
    // 0x800F2358: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800F235C: beq         $s0, $zero, L_800F23DC
    if (ctx->r16 == 0) {
        // 0x800F2360: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_800F23DC;
    }
    // 0x800F2360: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800F2364: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800F2368: beql        $t2, $zero, L_800F23E0
    if (ctx->r10 == 0) {
        // 0x800F236C: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F23E0;
    }
    goto skip_3;
    // 0x800F236C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_3:
    // 0x800F2370: lbu         $t3, 0x54($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X54);
    // 0x800F2374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F2378: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800F237C: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x800F2380: bnel        $t5, $zero, L_800F23E0
    if (ctx->r13 != 0) {
        // 0x800F2384: lw          $a0, 0x10($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X10);
            goto L_800F23E0;
    }
    goto skip_4;
    // 0x800F2384: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    skip_4:
    // 0x800F2388: jal         0x80012D90
    // 0x800F238C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    gcDrawMObjForDObj(rdram, ctx);
        goto after_5;
    // 0x800F238C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    after_5:
    // 0x800F2390: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800F2394: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800F2398: jal         0x800F1C08
    // 0x800F239C: lbu         $a0, 0x4($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X4);
    ftDisplayMainDecideFogDraw(rdram, ctx);
        goto after_6;
    // 0x800F239C: lbu         $a0, 0x4($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X4);
    after_6:
    // 0x800F23A0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800F23A4: lw          $v0, 0x65B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65B0);
    // 0x800F23A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800F23AC: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x800F23B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800F23B4: sw          $t7, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r15;
    // 0x800F23B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800F23BC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800F23C0: b           L_800F23DC
    // 0x800F23C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_800F23DC;
    // 0x800F23C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800F23C8:
    // 0x800F23C8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F23CC: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F23D0: jal         0x80010D70
    // 0x800F23D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_7;
    // 0x800F23D4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800F23D8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_800F23DC:
    // 0x800F23DC: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
L_800F23E0:
    // 0x800F23E0: beql        $a0, $zero, L_800F23F4
    if (ctx->r4 == 0) {
        // 0x800F23E4: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800F23F4;
    }
    goto skip_5;
    // 0x800F23E4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    skip_5:
    // 0x800F23E8: jal         0x800F21B4
    // 0x800F23EC: nop

    ftDisplayMainDrawSkeleton(rdram, ctx);
        goto after_8;
    // 0x800F23EC: nop

    after_8:
    // 0x800F23F0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
L_800F23F4:
    // 0x800F23F4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800F23F8: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800F23FC: beql        $t6, $zero, L_800F2448
    if (ctx->r14 == 0) {
        // 0x800F2400: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_800F2448;
    }
    goto skip_6;
    // 0x800F2400: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_6:
    // 0x800F2404: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    // 0x800F2408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F240C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800F2410: beq         $t0, $at, L_800F2424
    if (ctx->r8 == ctx->r1) {
        // 0x800F2414: addiu       $a0, $a0, 0x65B0
        ctx->r4 = ADD32(ctx->r4, 0X65B0);
            goto L_800F2424;
    }
    // 0x800F2414: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x800F2418: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x800F241C: beql        $t1, $zero, L_800F2448
    if (ctx->r9 == 0) {
        // 0x800F2420: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_800F2448;
    }
    goto skip_7;
    // 0x800F2420: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_7:
L_800F2424:
    // 0x800F2424: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800F2428: lui         $t3, 0xD838
    ctx->r11 = S32(0XD838 << 16);
    // 0x800F242C: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x800F2430: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800F2434: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800F2438: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800F243C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800F2440: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800F2444: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_800F2448:
    // 0x800F2448: addiu       $t4, $t4, 0x62D0
    ctx->r12 = ADD32(ctx->r12, 0X62D0);
    // 0x800F244C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800F2450: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800F2454: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800F2458: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x800F245C: sw          $t9, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r25;
    // 0x800F2460: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
L_800F2464:
    // 0x800F2464: bnel        $t6, $zero, L_800F2490
    if (ctx->r14 != 0) {
        // 0x800F2468: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F2490;
    }
    goto skip_8;
    // 0x800F2468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800F246C: lw          $s0, 0x8($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8);
    // 0x800F2470: beql        $s0, $zero, L_800F2490
    if (ctx->r16 == 0) {
        // 0x800F2474: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F2490;
    }
    goto skip_9;
    // 0x800F2474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
L_800F2478:
    // 0x800F2478: jal         0x800F21B4
    // 0x800F247C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainDrawSkeleton(rdram, ctx);
        goto after_9;
    // 0x800F247C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800F2480: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800F2484: bne         $s0, $zero, L_800F2478
    if (ctx->r16 != 0) {
        // 0x800F2488: nop
    
            goto L_800F2478;
    }
    // 0x800F2488: nop

    // 0x800F248C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F2490:
    // 0x800F2490: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F2494: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F2498: jr          $ra
    // 0x800F249C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F249C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_ovl27_80132794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132794: jr          $ra
    // 0x80132798: nop

    return;
    // 0x80132798: nop

;}
RECOMP_FUNC void ifCommonAnnounceGoMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801120D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801120D8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801120DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801120E0: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801120E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801120E8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801120EC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801120F0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801120F4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801120F8: lw          $s4, 0xD44($s4)
    ctx->r20 = MEM_W(ctx->r20, 0XD44);
    // 0x801120FC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80112100: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112108: jal         0x80009968
    // 0x8011210C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8011210C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x80112110: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80112114: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80112118: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8011211C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80112120: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80112124: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112128: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8011212C: jal         0x80009DF4
    // 0x80112130: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80112130: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80112134: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80112138: addiu       $a1, $a1, 0x1FF0
    ctx->r5 = ADD32(ctx->r5, 0X1FF0);
    // 0x8011213C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80112140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80112144: jal         0x80008188
    // 0x80112148: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80112148: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x8011214C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80112150: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80112154: addiu       $s3, $s3, -0x1284
    ctx->r19 = ADD32(ctx->r19, -0X1284);
    // 0x80112158: addiu       $s0, $s0, -0x129C
    ctx->r16 = ADD32(ctx->r16, -0X129C);
    // 0x8011215C: addiu       $s2, $zero, 0x1200
    ctx->r18 = ADD32(0, 0X1200);
L_80112160:
    // 0x80112160: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80112164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80112168: jal         0x800CCFDC
    // 0x8011216C: addu        $a1, $t7, $s4
    ctx->r5 = ADD32(ctx->r15, ctx->r20);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8011216C: addu        $a1, $t7, $s4
    ctx->r5 = ADD32(ctx->r15, ctx->r20);
    after_3:
    // 0x80112170: sh          $s2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r18;
    // 0x80112174: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80112178: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8011217C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80112180: nop

    // 0x80112184: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80112188: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8011218C: lh          $t9, -0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X6);
    // 0x80112190: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80112194: nop

    // 0x80112198: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8011219C: bne         $s0, $s3, L_80112160
    if (ctx->r16 != ctx->r19) {
        // 0x801121A0: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_80112160;
    }
    // 0x801121A0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801121A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801121A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801121AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801121B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801121B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801121B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801121BC: jr          $ra
    // 0x801121C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801121C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftSamusSpecialLwTransferStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015E174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015E178: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015E17C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015E180: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015E184: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015E188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E18C: jal         0x800DEEC8
    // 0x8015E190: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015E190: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x8015E194: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015E198: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015E19C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E1A0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E1A4: jal         0x800E6F24
    // 0x8015E1A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E1A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015E1AC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8015E1B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015E1B4: nop

    // 0x8015E1B8: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8015E1BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8015E1C0: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8015E1C4: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x8015E1C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015E1CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015E1D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015E1D4: jr          $ra
    // 0x8015E1D8: nop

    return;
    // 0x8015E1D8: nop

;}
RECOMP_FUNC void scAutoDemoSetFocusPlayer2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3D4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018D3D8: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018D3DC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018D3E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D3E8: lw          $t0, 0xEC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XEC);
    // 0x8018D3EC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D3F0: lw          $t7, -0x1B18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1B18);
    // 0x8018D3F4: lw          $t6, 0x84($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X84);
    // 0x8018D3F8: lw          $a0, 0x78($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X78);
    // 0x8018D3FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D400: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8018D404: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x8018D408: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x8018D40C: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x8018D410: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x8018D414: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8018D418: jal         0x800E9198
    // 0x8018D41C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_0;
    // 0x8018D41C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D420: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8018D424: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018D428: lw          $t2, 0x84($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X84);
    // 0x8018D42C: sb          $t1, 0xF($t2)
    MEM_B(0XF, ctx->r10) = ctx->r9;
    // 0x8018D430: jal         0x8018D1EC
    // 0x8018D434: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    scAutoDemoCheckStopFocusPlayer(rdram, ctx);
        goto after_1;
    // 0x8018D434: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8018D438: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018D43C: beq         $v0, $zero, L_8018D450
    if (ctx->r2 == 0) {
        // 0x8018D440: addiu       $a2, $a2, 0x50E8
        ctx->r6 = ADD32(ctx->r6, 0X50E8);
            goto L_8018D450;
    }
    // 0x8018D440: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018D444: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D448: b           L_8018D4E0
    // 0x8018D44C: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
        goto L_8018D4E0;
    // 0x8018D44C: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
L_8018D450:
    // 0x8018D450: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8018D454: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8018D458: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D45C: lw          $t5, 0xEC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XEC);
    // 0x8018D460: lw          $t6, 0x84($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X84);
    // 0x8018D464: sb          $t3, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r11;
    // 0x8018D468: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018D46C: lw          $t9, 0x1D4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1D4);
    // 0x8018D470: lw          $t1, 0x84($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X84);
    // 0x8018D474: sb          $t7, 0x13($t1)
    MEM_B(0X13, ctx->r9) = ctx->r15;
    // 0x8018D478: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018D47C: lw          $t2, 0x1D4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1D4);
    // 0x8018D480: lw          $t5, 0x160($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X160);
    // 0x8018D484: lw          $t4, 0x84($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X84);
    // 0x8018D488: lw          $t3, 0x84($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X84);
    // 0x8018D48C: lbu         $v1, 0x13($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X13);
    // 0x8018D490: sb          $v1, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r3;
    // 0x8018D494: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018D498: lw          $t8, 0x78($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X78);
    // 0x8018D49C: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8018D4A0: sb          $v1, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r3;
    // 0x8018D4A4: jal         0x8018D220
    // 0x8018D4A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    scAutoDemoSetCameraPlayerZoom(rdram, ctx);
        goto after_2;
    // 0x8018D4A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8018D4AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018D4B0: jal         0x800E9198
    // 0x8018D4B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_3;
    // 0x8018D4B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8018D4B8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D4BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D4C0: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018D4C4: sb          $t7, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r15;
    // 0x8018D4C8: lw          $t2, -0x1B18($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1B18);
    // 0x8018D4CC: lw          $t4, 0x74($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X74);
    // 0x8018D4D0: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x8018D4D4: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D4D8: andi        $t3, $t5, 0xFFFB
    ctx->r11 = ctx->r13 & 0XFFFB;
    // 0x8018D4DC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
L_8018D4E0:
    // 0x8018D4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D4E8: jr          $ra
    // 0x8018D4EC: nop

    return;
    // 0x8018D4EC: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiCatchProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801604D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801604DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801604E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801604E4: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x801604E8: lhu         $t6, 0xB18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XB18);
    // 0x801604EC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x801604F0: bnel        $t7, $zero, L_80160554
    if (ctx->r15 != 0) {
        // 0x801604F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80160554;
    }
    goto skip_0;
    // 0x801604F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801604F8: lw          $a1, 0x840($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X840);
    // 0x801604FC: jal         0x8014D0F0
    // 0x80160500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftCommonCaptureCaptainUpdatePositions(rdram, ctx);
        goto after_0;
    // 0x80160500: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160504: jal         0x80018F7C
    // 0x80160508: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x80160508: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8016050C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80160510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80160514: nop

    // 0x80160518: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8016051C: nop

    // 0x80160520: bc1fl       L_80160540
    if (!c1cs) {
        // 0x80160524: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_80160540;
    }
    goto skip_1;
    // 0x80160524: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80160528: jal         0x80018EE0
    // 0x8016052C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x8016052C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x80160530: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80160534: jal         0x800190B0
    // 0x80160538: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x80160538: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_3:
    // 0x8016053C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_80160540:
    // 0x80160540: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80160544: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x80160548: jal         0x80018FF4
    // 0x8016054C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    syVectorSub3D(rdram, ctx);
        goto after_4;
    // 0x8016054C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_4:
    // 0x80160550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80160554:
    // 0x80160554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160558: jr          $ra
    // 0x8016055C: nop

    return;
    // 0x8016055C: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttackShieldCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F044C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F0450: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800F0454: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800F0458: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F045C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F0460: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800F0464: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800F0468: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800F046C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x800F0470: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800F0474: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x800F0478: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800F047C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800F0480: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800F0484: lw          $t6, 0x84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X84);
    // 0x800F0488: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800F048C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F0490: jal         0x800EDE00
    // 0x800F0494: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800F0494: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    after_0:
    // 0x800F0498: jal         0x800EDE5C
    // 0x800F049C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800F049C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_1:
    // 0x800F04A0: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800F04A4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800F04A8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800F04AC: lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X2C);
    // 0x800F04B0: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800F04B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F04B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800F04BC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800F04C0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800F04C4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800F04C8: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x800F04CC: addiu       $t2, $sp, 0x4C
    ctx->r10 = ADD32(ctx->r29, 0X4C);
    // 0x800F04D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F04D4: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800F04D8: addiu       $t9, $t0, 0x9C
    ctx->r25 = ADD32(ctx->r8, 0X9C);
    // 0x800F04DC: addiu       $t3, $t0, 0x90
    ctx->r11 = ADD32(ctx->r8, 0X90);
    // 0x800F04E0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800F04E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800F04E8: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F04EC: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800F04F0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800F04F4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800F04F8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800F04FC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800F0500: jal         0x800EE750
    // 0x800F0504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    gmCollisionTestSphere(rdram, ctx);
        goto after_2;
    // 0x800F0504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_2:
    // 0x800F0508: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F050C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800F0510: jr          $ra
    // 0x800F0514: nop

    return;
    // 0x800F0514: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328FC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132900: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132904: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132908: addiu       $t7, $t7, -0x771C
    ctx->r15 = ADD32(ctx->r15, -0X771C);
    // 0x8013290C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80132910: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132914: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132918: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8013291C: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80132920:
    // 0x80132920: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132924: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132928: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013292C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132930: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132934: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132938: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013293C: bne         $t7, $t0, L_80132920
    if (ctx->r15 != ctx->r8) {
        // 0x80132940: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132920;
    }
    // 0x80132940: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013294C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132950: jal         0x80009968
    // 0x80132954: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132954: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132958: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013295C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132960: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132964: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132968: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8013296C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80132970: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132974: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132978: jal         0x80009DF4
    // 0x8013297C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013297C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132980: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132984: addiu       $a1, $a1, 0x255C
    ctx->r5 = ADD32(ctx->r5, 0X255C);
    // 0x80132988: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013298C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132990: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132994: jal         0x80008188
    // 0x80132998: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132998: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8013299C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801329A0: lw          $t2, -0x6950($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6950);
    // 0x801329A4: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801329A8: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x801329AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801329B0: jal         0x800CCFDC
    // 0x801329B4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801329B4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x801329B8: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801329BC: bne         $at, $zero, L_801329CC
    if (ctx->r1 != 0) {
        // 0x801329C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801329CC;
    }
    // 0x801329C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801329C4: b           L_801329D0
    // 0x801329C8: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
        goto L_801329D0;
    // 0x801329C8: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
L_801329CC:
    // 0x801329CC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_801329D0:
    // 0x801329D0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x801329D4: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x801329D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801329DC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x801329E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801329E4: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x801329E8: addiu       $t5, $t4, 0x19
    ctx->r13 = ADD32(ctx->r12, 0X19);
    // 0x801329EC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801329F0: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801329F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801329F8: bne         $at, $zero, L_80132A08
    if (ctx->r1 != 0) {
        // 0x801329FC: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80132A08;
    }
    // 0x801329FC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132A00: b           L_80132A0C
    // 0x80132A04: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132A0C;
    // 0x80132A04: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80132A08:
    // 0x80132A08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80132A0C:
    // 0x80132A0C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80132A10: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132A14: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132A18: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132A1C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132A20: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132A24: addiu       $t7, $t0, 0x24
    ctx->r15 = ADD32(ctx->r8, 0X24);
    // 0x80132A28: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80132A2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80132A30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132A34: jal         0x801325D8
    // 0x80132A38: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    mnPlayers1PGameSetPortraitWallpaperPosition(rdram, ctx);
        goto after_4;
    // 0x80132A38: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    after_4:
    // 0x80132A3C: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A48: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132A4C: jal         0x80009968
    // 0x80132A50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80132A50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80132A54: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A58: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132A5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132A60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A64: addiu       $a1, $a1, 0x283C
    ctx->r5 = ADD32(ctx->r5, 0X283C);
    // 0x80132A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A6C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132A70: jal         0x80009DF4
    // 0x80132A74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80132A74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x80132A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132A7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132A84: jal         0x80008188
    // 0x80132A88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80132A88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80132A8C: jal         0x8013279C
    // 0x80132A90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_8;
    // 0x80132A90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80132A94: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80132A98: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80132A9C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132AA0: lw          $t1, -0x6950($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6950);
    // 0x80132AA4: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x80132AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132AAC: jal         0x800CCFDC
    // 0x80132AB0: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x80132AB0: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_9:
    // 0x80132AB4: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132AB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132ABC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80132AC0: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132AC4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132AC8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132ACC: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132AD0: jal         0x801325D8
    // 0x80132AD4: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    mnPlayers1PGameSetPortraitWallpaperPosition(rdram, ctx);
        goto after_10;
    // 0x80132AD4: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    after_10:
    // 0x80132AD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132AE0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132AE4: jal         0x80009968
    // 0x80132AE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_11;
    // 0x80132AE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_11:
    // 0x80132AEC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132AF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132AF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132AF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132AFC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80132B00: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132B04: jal         0x80009DF4
    // 0x80132B08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_12;
    // 0x80132B08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_12:
    // 0x80132B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132B14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132B18: jal         0x80008188
    // 0x80132B1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x80132B1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x80132B20: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132B24: lw          $t7, -0x6950($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6950);
    // 0x80132B28: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132B2C: addiu       $t6, $t6, 0xF68
    ctx->r14 = ADD32(ctx->r14, 0XF68);
    // 0x80132B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B34: jal         0x800CCFDC
    // 0x80132B38: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_14;
    // 0x80132B38: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_14:
    // 0x80132B3C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B40: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x80132B44: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x80132B48: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80132B4C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132B50: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132B54: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x80132B58: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x80132B5C: addiu       $t7, $zero, 0xB9
    ctx->r15 = ADD32(0, 0XB9);
    // 0x80132B60: addiu       $t6, $zero, 0xA9
    ctx->r14 = ADD32(0, 0XA9);
    // 0x80132B64: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132B68: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x80132B6C: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x80132B70: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80132B74: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80132B78: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132B7C: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132B80: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132B84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B88: jal         0x801325D8
    // 0x80132B8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameSetPortraitWallpaperPosition(rdram, ctx);
        goto after_15;
    // 0x80132B8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x80132B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132B94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132B9C: jr          $ra
    // 0x80132BA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80132BA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void itPowerBlockCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C098: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017C09C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C0A0: lwc1        $f4, -0x3230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3230);
    // 0x8017C0A4: lwc1        $f6, 0x74($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X74);
    // 0x8017C0A8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017C0AC: nop

    // 0x8017C0B0: bc1fl       L_8017C0C4
    if (!c1cs) {
        // 0x8017C0B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017C0C4;
    }
    goto skip_0;
    // 0x8017C0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017C0B8: jal         0x8017C0D4
    // 0x8017C0BC: nop

    itPowerBlockWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017C0BC: nop

    after_0:
    // 0x8017C0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017C0C4:
    // 0x8017C0C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C0C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C0CC: jr          $ra
    // 0x8017C0D0: nop

    return;
    // 0x8017C0D0: nop

;}
RECOMP_FUNC void mvOpeningDonkeyMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCD8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DCDC: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DCE0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DCE4: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DCE8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DCEC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DCF0: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DCF4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DCF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DCFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD00: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD04: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD08: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD0C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD10: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD14: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD1C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD20: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD24: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD28: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD30: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD34: jal         0x8000B93C
    // 0x8018DD38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD3C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD40: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD48: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DD4C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DD50: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DD54: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD58: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD5C: jal         0x80007080
    // 0x8018DD60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DD64: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD68: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DD6C: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DD70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD78: jr          $ra
    // 0x8018DD7C: nop

    return;
    // 0x8018DD7C: nop

;}
RECOMP_FUNC void gmCameraPrepProjectionFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E10C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8010E110: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x8010E114: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x8010E118: ori         $t7, $t7, 0x7
    ctx->r15 = ctx->r15 | 0X7;
    // 0x8010E11C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8010E120: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8010E124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010E128: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8010E12C: jr          $ra
    // 0x8010E130: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x8010E130: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void itKabigonCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E684: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017E688: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017E68C: bnel        $a1, $zero, L_8017E6A8
    if (ctx->r5 != 0) {
        // 0x8017E690: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017E6A8;
    }
    goto skip_0;
    // 0x8017E690: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017E694: jal         0x8017E648
    // 0x8017E698: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itKabigonJumpSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017E698: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017E69C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E6A0: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017E6A4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017E6A8:
    // 0x8017E6A8: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017E6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E6B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E6B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E6B8: jr          $ra
    // 0x8017E6BC: nop

    return;
    // 0x8017E6BC: nop

;}
RECOMP_FUNC void func_80026594_27194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002659C: jal         0x80030350
    // 0x800265A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800265A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800265A4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800265A8: addiu       $a2, $a2, -0x1230
    ctx->r6 = ADD32(ctx->r6, -0X1230);
    // 0x800265AC: lw          $v1, 0x3C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X3C);
    // 0x800265B0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800265B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800265B8: beq         $v1, $zero, L_80026620
    if (ctx->r3 == 0) {
        // 0x800265BC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80026620;
    }
    // 0x800265BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800265C0:
    // 0x800265C0: lbu         $t6, 0x2B($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2B);
    // 0x800265C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800265C8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800265CC: beq         $t7, $zero, L_80026614
    if (ctx->r15 == 0) {
        // 0x800265D0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80026614;
    }
    // 0x800265D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800265D4: beql        $a0, $zero, L_800265E8
    if (ctx->r4 == 0) {
        // 0x800265D8: sw          $v0, 0x3C($a2)
        MEM_W(0X3C, ctx->r6) = ctx->r2;
            goto L_800265E8;
    }
    goto skip_0;
    // 0x800265D8: sw          $v0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r2;
    skip_0:
    // 0x800265DC: b           L_800265E8
    // 0x800265E0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_800265E8;
    // 0x800265E0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800265E4: sw          $v0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r2;
L_800265E8:
    // 0x800265E8: lbu         $t8, 0x2A($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2A);
    // 0x800265EC: bnel        $a3, $t8, L_80026608
    if (ctx->r7 != ctx->r24) {
        // 0x800265F0: lw          $t9, 0x5C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X5C);
            goto L_80026608;
    }
    goto skip_1;
    // 0x800265F0: lw          $t9, 0x5C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X5C);
    skip_1:
    // 0x800265F4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800265F8: beql        $v0, $zero, L_80026608
    if (ctx->r2 == 0) {
        // 0x800265FC: lw          $t9, 0x5C($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X5C);
            goto L_80026608;
    }
    goto skip_2;
    // 0x800265FC: lw          $t9, 0x5C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X5C);
    skip_2:
    // 0x80026600: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x80026604: lw          $t9, 0x5C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X5C);
L_80026608:
    // 0x80026608: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002660C: b           L_80026618
    // 0x80026610: sw          $v1, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r3;
        goto L_80026618;
    // 0x80026610: sw          $v1, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r3;
L_80026614:
    // 0x80026614: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80026618:
    // 0x80026618: bne         $a1, $zero, L_800265C0
    if (ctx->r5 != 0) {
        // 0x8002661C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800265C0;
    }
    // 0x8002661C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80026620:
    // 0x80026620: lw          $v0, 0x40($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X40);
    // 0x80026624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026628: beq         $v0, $zero, L_80026674
    if (ctx->r2 == 0) {
        // 0x8002662C: nop
    
            goto L_80026674;
    }
    // 0x8002662C: nop

L_80026630:
    // 0x80026630: lbu         $t1, 0x1F($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1F);
    // 0x80026634: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80026638: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8002663C: beq         $t2, $zero, L_80026668
    if (ctx->r10 == 0) {
        // 0x80026640: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80026668;
    }
    // 0x80026640: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80026644: beql        $a0, $zero, L_80026658
    if (ctx->r4 == 0) {
        // 0x80026648: sw          $v1, 0x40($a2)
        MEM_W(0X40, ctx->r6) = ctx->r3;
            goto L_80026658;
    }
    goto skip_3;
    // 0x80026648: sw          $v1, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r3;
    skip_3:
    // 0x8002664C: b           L_80026658
    // 0x80026650: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
        goto L_80026658;
    // 0x80026650: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80026654: sw          $v1, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r3;
L_80026658:
    // 0x80026658: lw          $t3, 0x60($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X60);
    // 0x8002665C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80026660: b           L_8002666C
    // 0x80026664: sw          $v0, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->r2;
        goto L_8002666C;
    // 0x80026664: sw          $v0, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->r2;
L_80026668:
    // 0x80026668: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8002666C:
    // 0x8002666C: bne         $a1, $zero, L_80026630
    if (ctx->r5 != 0) {
        // 0x80026670: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80026630;
    }
    // 0x80026670: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80026674:
    // 0x80026674: jal         0x80030350
    // 0x80026678: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026678: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
    // 0x8002667C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026684: jr          $ra
    // 0x80026688: nop

    return;
    // 0x80026688: nop

;}
RECOMP_FUNC void func_ovl8_803724B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803724B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803724B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803724BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803724C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803724C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803724C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x803724CC: bne         $a0, $zero, L_803724E4
    if (ctx->r4 != 0) {
        // 0x803724D0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_803724E4;
    }
    // 0x803724D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x803724D4: jal         0x803717A0
    // 0x803724D8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803724D8: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x803724DC: beq         $v0, $zero, L_80372540
    if (ctx->r2 == 0) {
        // 0x803724E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80372540;
    }
    // 0x803724E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803724E4:
    // 0x803724E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x803724E8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x803724EC: bnel        $t6, $zero, L_80372500
    if (ctx->r14 != 0) {
        // 0x803724F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80372500;
    }
    goto skip_0;
    // 0x803724F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x803724F4: jal         0x803717E0
    // 0x803724F8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803724F8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x803724FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80372500:
    // 0x80372500: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80372504: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80372508: jal         0x8037203C
    // 0x8037250C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037203C(rdram, ctx);
        goto after_2;
    // 0x8037250C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80372510: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80372514: addiu       $t7, $t7, -0x7360
    ctx->r15 = ADD32(ctx->r15, -0X7360);
    // 0x80372518: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8037251C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80372520: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80372524: addiu       $t8, $t8, -0x72F8
    ctx->r24 = ADD32(ctx->r24, -0X72F8);
    // 0x80372528: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x8037252C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80372530: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80372534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80372538: jal         0x8037277C
    // 0x8037253C: sw          $t0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r8;
    func_ovl8_8037277C(rdram, ctx);
        goto after_3;
    // 0x8037253C: sw          $t0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r8;
    after_3:
L_80372540:
    // 0x80372540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80372544: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80372548: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037254C: jr          $ra
    // 0x80372550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80372550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PTrainingModeUpdateOptionArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F630: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018F634: addiu       $a2, $a2, 0xB58
    ctx->r6 = ADD32(ctx->r6, 0XB58);
    // 0x8018F638: lw          $t6, 0x68($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X68);
    // 0x8018F63C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8018F640: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018F644: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8018F648: beq         $at, $zero, L_8018F710
    if (ctx->r1 == 0) {
        // 0x8018F64C: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_8018F710;
    }
    // 0x8018F64C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8018F650: lui         $at, 0x4309
    ctx->r1 = S32(0X4309 << 16);
    // 0x8018F654: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F658: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8018F65C: lui         $at, 0x436D
    ctx->r1 = S32(0X436D << 16);
    // 0x8018F660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F664: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8018F668: lw          $a1, 0x6C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X6C);
    // 0x8018F66C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018F670: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x8018F674: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018F678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018F67C: bnel        $t9, $at, L_8018F6C8
    if (ctx->r25 != ctx->r1) {
        // 0x8018F680: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8018F6C8;
    }
    goto skip_0;
    // 0x8018F680: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_0:
    // 0x8018F684: lw          $t0, 0x10($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X10);
    // 0x8018F688: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018F68C: bne         $t0, $at, L_8018F6C4
    if (ctx->r8 != ctx->r1) {
        // 0x8018F690: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8018F6C4;
    }
    // 0x8018F690: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018F694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F698: lwc1        $f8, 0x5C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x8018F69C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F6A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018F6A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8018F6A8: nop

    // 0x8018F6AC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8018F6B0: nop

    // 0x8018F6B4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F6B8: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8018F6BC: b           L_8018F6F4
    // 0x8018F6C0: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
        goto L_8018F6F4;
    // 0x8018F6C0: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
L_8018F6C4:
    // 0x8018F6C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8018F6C8:
    // 0x8018F6C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F6CC: lwc1        $f6, 0x5C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x8018F6D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018F6D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018F6D8: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8018F6DC: nop

    // 0x8018F6E0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8018F6E4: nop

    // 0x8018F6E8: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018F6EC: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8018F6F0: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
L_8018F6F4:
    // 0x8018F6F4: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8018F6F8: andi        $t6, $t5, 0xFFFB
    ctx->r14 = ctx->r13 & 0XFFFB;
    // 0x8018F6FC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8018F700: lhu         $t7, 0x24($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X24);
    // 0x8018F704: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x8018F708: jr          $ra
    // 0x8018F70C: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
    return;
    // 0x8018F70C: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
L_8018F710:
    // 0x8018F710: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8018F714: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8018F718: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018F71C: lhu         $t1, 0x24($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X24);
    // 0x8018F720: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8018F724: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x8018F728: jr          $ra
    // 0x8018F72C: nop

    return;
    // 0x8018F72C: nop

;}
RECOMP_FUNC void mvOpeningYoshiFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E018: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E01C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E020: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E024: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E028: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E02C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E030: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E034: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E038: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E03C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E040: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E044: jal         0x800FCB70
    // 0x8018E048: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E048: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E04C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E054: jr          $ra
    // 0x8018E058: nop

    return;
    // 0x8018E058: nop

;}
RECOMP_FUNC void func_ovl8_80372F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80372F08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80372F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80372F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372F14: beq         $a0, $zero, L_80372F20
    if (ctx->r4 == 0) {
        // 0x80372F18: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80372F20;
    }
    // 0x80372F18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80372F1C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80372F20:
    // 0x80372F20: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x80372F24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80372F28: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80372F2C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80372F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80372F34: addiu       $v1, $v1, 0x1FC
    ctx->r3 = ADD32(ctx->r3, 0X1FC);
    // 0x80372F38: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80372F3C: beq         $v1, $zero, L_80372F88
    if (ctx->r3 == 0) {
        // 0x80372F40: nop
    
            goto L_80372F88;
    }
    // 0x80372F40: nop

    // 0x80372F44: beq         $s0, $zero, L_80372F50
    if (ctx->r16 == 0) {
        // 0x80372F48: addiu       $a1, $zero, 0x1F
        ctx->r5 = ADD32(0, 0X1F);
            goto L_80372F50;
    }
    // 0x80372F48: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80372F4C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80372F50:
    // 0x80372F50: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80372F54: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80372F58: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80372F5C: jal         0x8037C518
    // 0x80372F60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_ovl8_8037C518(rdram, ctx);
        goto after_0;
    // 0x80372F60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80372F64: beq         $s0, $zero, L_80372F70
    if (ctx->r16 == 0) {
        // 0x80372F68: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80372F70;
    }
    // 0x80372F68: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80372F6C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80372F70:
    // 0x80372F70: lw          $t7, 0x48($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X48);
    // 0x80372F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80372F78: jal         0x8000A24C
    // 0x80372F7C: lw          $a0, 0x38($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X38);
    func_8000A24C(rdram, ctx);
        goto after_1;
    // 0x80372F7C: lw          $a0, 0x38($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X38);
    after_1:
    // 0x80372F80: b           L_80372FC4
    // 0x80372F84: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
        goto L_80372FC4;
    // 0x80372F84: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
L_80372F88:
    // 0x80372F88: beql        $s0, $zero, L_80372F98
    if (ctx->r16 == 0) {
        // 0x80372F8C: lw          $a0, 0x48($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X48);
            goto L_80372F98;
    }
    goto skip_0;
    // 0x80372F8C: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    skip_0:
    // 0x80372F90: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80372F94: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
L_80372F98:
    // 0x80372F98: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80372F9C: jal         0x8037C518
    // 0x80372FA0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    func_ovl8_8037C518(rdram, ctx);
        goto after_2;
    // 0x80372FA0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    after_2:
    // 0x80372FA4: beq         $s0, $zero, L_80372FB0
    if (ctx->r16 == 0) {
        // 0x80372FA8: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80372FB0;
    }
    // 0x80372FA8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80372FAC: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_80372FB0:
    // 0x80372FB0: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x80372FB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80372FB8: jal         0x8000A24C
    // 0x80372FBC: lw          $a0, 0x38($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X38);
    func_8000A24C(rdram, ctx);
        goto after_3;
    // 0x80372FBC: lw          $a0, 0x38($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X38);
    after_3:
    // 0x80372FC0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
L_80372FC4:
    // 0x80372FC4: lh          $t9, 0x70($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X70);
    // 0x80372FC8: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x80372FCC: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80372FD0: jalr        $t9
    // 0x80372FD4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80372FD4: nop

    after_4:
    // 0x80372FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80372FDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80372FE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80372FE4: jr          $ra
    // 0x80372FE8: nop

    return;
    // 0x80372FE8: nop

;}
RECOMP_FUNC void mnVSResultsInitFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801374F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801374F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801374FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137500: jal         0x8013392C
    // 0x80137504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    mnVSResultsMakeFighter(rdram, ctx);
        goto after_0;
    // 0x80137504: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80137508: jal         0x80133810
    // 0x8013750C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetSpot(rdram, ctx);
        goto after_1;
    // 0x8013750C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80137510: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137514: addiu       $t7, $t7, -0x6420
    ctx->r15 = ADD32(ctx->r15, -0X6420);
    // 0x80137518: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8013751C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80137520: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80137524: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80137528: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8013752C: jal         0x801331DC
    // 0x80137530: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnVSResultsSetFighterPosition(rdram, ctx);
        goto after_2;
    // 0x80137530: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80137534: jal         0x80133148
    // 0x80137538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80137538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013753C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80137540: jal         0x80133810
    // 0x80137544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetSpot(rdram, ctx);
        goto after_4;
    // 0x80137544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80137548: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8013754C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80137550: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80137554: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80137558: jal         0x801338EC
    // 0x8013755C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    mnVSResultsSetFighterScale(rdram, ctx);
        goto after_5;
    // 0x8013755C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_5:
    // 0x80137560: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80137564: subu        $t9, $t9, $s0
    ctx->r25 = SUB32(ctx->r25, ctx->r16);
    // 0x80137568: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8013756C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80137570: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80137574: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80137578: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8013757C: lbu         $a1, 0x4D30($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4D30);
    // 0x80137580: jal         0x80133C58
    // 0x80137584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsMakePlayerTag(rdram, ctx);
        goto after_6;
    // 0x80137584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80137588: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8013758C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80137590: jal         0x801334DC
    // 0x80137594: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    mnVSResultsSetFighterStatus(rdram, ctx);
        goto after_7;
    // 0x80137594: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_7:
    // 0x80137598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013759C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801375A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801375A4: jr          $ra
    // 0x801375A8: nop

    return;
    // 0x801375A8: nop

;}
RECOMP_FUNC void syMatrixFastCos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A09C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001A0A0: lwc1        $f4, -0x1C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C5C);
    // 0x8001A0A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001A0A8: lwc1        $f8, -0x1C58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C58);
    // 0x8001A0AC: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8001A0B0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001A0B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001A0B8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001A0BC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x8001A0C0: nop

    // 0x8001A0C4: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8001A0C8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001A0CC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A0D0: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x8001A0D4: beq         $t9, $zero, L_8001A0E4
    if (ctx->r25 == 0) {
        // 0x8001A0D8: lhu         $v1, -0x46B0($v1)
        ctx->r3 = MEM_HU(ctx->r3, -0X46B0);
            goto L_8001A0E4;
    }
    // 0x8001A0D8: lhu         $v1, -0x46B0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X46B0);
    // 0x8001A0DC: jr          $ra
    // 0x8001A0E0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    return;
    // 0x8001A0E0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8001A0E4:
    // 0x8001A0E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A0E8: jr          $ra
    // 0x8001A0EC: nop

    return;
    // 0x8001A0EC: nop

;}
RECOMP_FUNC void ftLinkSpecialNGetSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163ACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163AD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163AD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80163ADC: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80163AE0: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x80163AE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163AE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163AEC: bnel        $t6, $at, L_80163B18
    if (ctx->r14 != ctx->r1) {
        // 0x80163AF0: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80163B18;
    }
    goto skip_0;
    // 0x80163AF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80163AF4: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80163AF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163AFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163B00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163B04: jal         0x800E6F24
    // 0x80163B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163B0C: b           L_80163B20
    // 0x80163B10: nop

        goto L_80163B20;
    // 0x80163B10: nop

    // 0x80163B14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80163B18:
    // 0x80163B18: jal         0x800E6F24
    // 0x80163B1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163B1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
L_80163B20:
    // 0x80163B20: jal         0x800E0830
    // 0x80163B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163B24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80163B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163B2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163B30: jr          $ra
    // 0x80163B34: nop

    return;
    // 0x80163B34: nop

;}
RECOMP_FUNC void unref_80005C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C84: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80005C88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005C8C: sw          $t6, 0x65D0($at)
    MEM_W(0X65D0, ctx->r1) = ctx->r14;
    // 0x80005C90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005C94: jr          $ra
    // 0x80005C98: sw          $a0, 0x65D4($at)
    MEM_W(0X65D4, ctx->r1) = ctx->r4;
    return;
    // 0x80005C98: sw          $a0, 0x65D4($at)
    MEM_W(0X65D4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void itMainSetAppearSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172394: bne         $a1, $zero, L_801723F8
    if (ctx->r5 != 0) {
        // 0x80172398: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_801723F8;
    }
    // 0x80172398: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017239C: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
    // 0x801723A0: lhu         $v1, 0x46($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X46);
    // 0x801723A4: beql        $v1, $zero, L_801723F0
    if (ctx->r3 == 0) {
        // 0x801723A8: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_801723F0;
    }
    goto skip_0;
    // 0x801723A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x801723AC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801723B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801723B4: bgez        $v1, L_801723C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801723B8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801723C8;
    }
    // 0x801723B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801723BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801723C0: nop

    // 0x801723C4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801723C8:
    // 0x801723C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801723CC: lwc1        $f10, -0x3388($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3388);
    // 0x801723D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801723D4: lwc1        $f18, -0x3384($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3384);
    // 0x801723D8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801723DC: nop

    // 0x801723E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801723E4: jr          $ra
    // 0x801723E8: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x801723E8: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
    // 0x801723EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_801723F0:
    // 0x801723F0: jr          $ra
    // 0x801723F4: swc1        $f8, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x801723F4: swc1        $f8, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f8.u32l;
L_801723F8:
    // 0x801723F8: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x801723FC: lhu         $v1, 0x46($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X46);
    // 0x80172400: beql        $v1, $zero, L_8017244C
    if (ctx->r3 == 0) {
        // 0x80172404: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8017244C;
    }
    goto skip_1;
    // 0x80172404: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x80172408: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8017240C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80172410: bgez        $v1, L_80172424
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80172414: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80172424;
    }
    // 0x80172414: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80172418: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017241C: nop

    // 0x80172420: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80172424:
    // 0x80172424: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172428: lwc1        $f18, -0x3380($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3380);
    // 0x8017242C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172430: lwc1        $f8, -0x337C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X337C);
    // 0x80172434: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80172438: nop

    // 0x8017243C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80172440: jr          $ra
    // 0x80172444: swc1        $f6, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80172444: swc1        $f6, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f6.u32l;
    // 0x80172448: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8017244C:
    // 0x8017244C: nop

    // 0x80172450: swc1        $f16, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f16.u32l;
    // 0x80172454: jr          $ra
    // 0x80172458: nop

    return;
    // 0x80172458: nop

;}
RECOMP_FUNC void efManagerLinkEntryBeamMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102B4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102B50: jal         0x800FDAFC
    // 0x80102B54: addiu       $a0, $a0, -0x1AF4
    ctx->r4 = ADD32(ctx->r4, -0X1AF4);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102B54: addiu       $a0, $a0, -0x1AF4
    ctx->r4 = ADD32(ctx->r4, -0X1AF4);
    after_0:
    // 0x80102B58: bne         $v0, $zero, L_80102B68
    if (ctx->r2 != 0) {
        // 0x80102B5C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102B68;
    }
    // 0x80102B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102B60: b           L_80102B8C
    // 0x80102B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102B8C;
    // 0x80102B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102B68:
    // 0x80102B68: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102B6C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102B70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102B74: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102B78: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80102B7C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102B80: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80102B84: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102B88: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80102B8C:
    // 0x80102B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102B94: jr          $ra
    // 0x80102B98: nop

    return;
    // 0x80102B98: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156C38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156C3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156C40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156C44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80156C48: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80156C4C: lw          $v1, 0xADC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XADC);
    // 0x80156C50: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80156C54: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80156C58: beq         $v1, $zero, L_80156C70
    if (ctx->r3 == 0) {
        // 0x80156C5C: nop
    
            goto L_80156C70;
    }
    // 0x80156C5C: nop

    // 0x80156C60: beq         $v1, $at, L_80156C70
    if (ctx->r3 == ctx->r1) {
        // 0x80156C64: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80156C70;
    }
    // 0x80156C64: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80156C68: bne         $v1, $at, L_80156C78
    if (ctx->r3 != ctx->r1) {
        // 0x80156C6C: addiu       $a1, $zero, 0xEA
        ctx->r5 = ADD32(0, 0XEA);
            goto L_80156C78;
    }
    // 0x80156C6C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
L_80156C70:
    // 0x80156C70: b           L_80156C78
    // 0x80156C74: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
        goto L_80156C78;
    // 0x80156C74: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
L_80156C78:
    // 0x80156C78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80156C7C: jal         0x800E6F24
    // 0x80156C80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156C80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80156C84: jal         0x800E0830
    // 0x80156C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80156C88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80156C8C: jal         0x80156BB8
    // 0x80156C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyMarioSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156C90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156C9C: jr          $ra
    // 0x80156CA0: nop

    return;
    // 0x80156CA0: nop

;}
RECOMP_FUNC void ftCommonCatchWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014A004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014A008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014A00C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8014A010: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8014A014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014A018: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8014A01C: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    // 0x8014A020: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014A024: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014A028: jal         0x800E6F24
    // 0x8014A02C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014A02C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014A030: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A034: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8014A038: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8014A03C: jal         0x800E8098
    // 0x8014A040: sw          $t8, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r24;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x8014A040: sw          $t8, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r24;
    after_1:
    // 0x8014A044: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A048: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8014A04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A050: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8014A054: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x8014A058: beq         $v0, $at, L_8014A068
    if (ctx->r2 == ctx->r1) {
        // 0x8014A05C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8014A068;
    }
    // 0x8014A05C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8014A060: bnel        $v0, $at, L_8014A08C
    if (ctx->r2 != ctx->r1) {
        // 0x8014A064: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8014A08C;
    }
    goto skip_0;
    // 0x8014A064: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_0:
L_8014A068:
    // 0x8014A068: jal         0x800E8C70
    // 0x8014A06C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamSetModelPartID(rdram, ctx);
        goto after_2;
    // 0x8014A06C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8014A070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A074: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8014A078: jal         0x800E8C70
    // 0x8014A07C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    ftParamSetModelPartID(rdram, ctx);
        goto after_3;
    // 0x8014A07C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8014A080: b           L_8014A0AC
    // 0x8014A084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8014A0AC;
    // 0x8014A084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014A088: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_8014A08C:
    // 0x8014A08C: beq         $v0, $at, L_8014A09C
    if (ctx->r2 == ctx->r1) {
        // 0x8014A090: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014A09C;
    }
    // 0x8014A090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A094: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8014A098: bne         $v0, $at, L_8014A0A8
    if (ctx->r2 != ctx->r1) {
        // 0x8014A09C: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_8014A0A8;
    }
L_8014A09C:
    // 0x8014A09C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8014A0A0: jal         0x800E8C70
    // 0x8014A0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    ftParamSetModelPartID(rdram, ctx);
        goto after_4;
    // 0x8014A0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_8014A0A8:
    // 0x8014A0A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014A0AC:
    // 0x8014A0AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014A0B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014A0B4: jr          $ra
    // 0x8014A0B8: nop

    return;
    // 0x8014A0B8: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetArrowSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B74: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80133B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133B7C: beq         $v1, $zero, L_80133BB8
    if (ctx->r3 == 0) {
        // 0x80133B80: nop
    
            goto L_80133BB8;
    }
    // 0x80133B80: nop

    // 0x80133B84: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80133B88: bnel        $a1, $t6, L_80133B9C
    if (ctx->r5 != ctx->r14) {
        // 0x80133B8C: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_80133B9C;
    }
    goto skip_0;
    // 0x80133B8C: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x80133B90: jr          $ra
    // 0x80133B94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80133B94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80133B98: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_80133B9C:
    // 0x80133B9C: beq         $a0, $zero, L_80133BB8
    if (ctx->r4 == 0) {
        // 0x80133BA0: nop
    
            goto L_80133BB8;
    }
    // 0x80133BA0: nop

    // 0x80133BA4: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80133BA8: bne         $a1, $t7, L_80133BB8
    if (ctx->r5 != ctx->r15) {
        // 0x80133BAC: nop
    
            goto L_80133BB8;
    }
    // 0x80133BAC: nop

    // 0x80133BB0: jr          $ra
    // 0x80133BB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80133BB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80133BB8:
    // 0x80133BB8: jr          $ra
    // 0x80133BBC: nop

    return;
    // 0x80133BBC: nop

;}
RECOMP_FUNC void itNBumperThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B6A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B6A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B6AC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8017B6B0: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x8017B6B4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8017B6B8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x8017B6BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017B6C0: jal         0x80172558
    // 0x8017B6C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017B6C4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017B6C8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B6CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017B6D0: lhu         $v0, 0x354($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X354);
    // 0x8017B6D4: bnel        $v0, $zero, L_8017B6F8
    if (ctx->r2 != 0) {
        // 0x8017B6D8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8017B6F8;
    }
    goto skip_0;
    // 0x8017B6D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x8017B6DC: jal         0x8017279C
    // 0x8017B6E0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017B6E0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017B6E4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B6E8: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8017B6EC: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x8017B6F0: sh          $t7, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r15;
    // 0x8017B6F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8017B6F8:
    // 0x8017B6F8: beq         $v0, $at, L_8017B704
    if (ctx->r2 == ctx->r1) {
        // 0x8017B6FC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8017B704;
    }
    // 0x8017B6FC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8017B700: sh          $t8, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r24;
L_8017B704:
    // 0x8017B704: jal         0x801713F4
    // 0x8017B708: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_2;
    // 0x8017B708: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017B70C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B718: jr          $ra
    // 0x8017B71C: nop

    return;
    // 0x8017B71C: nop

;}
RECOMP_FUNC void grPupupuUpdateWhispyStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105EF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80105EF8: lbu         $t6, 0x1416($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1416);
    // 0x80105EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105F04: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80105F08: beq         $at, $zero, L_80105F7C
    if (ctx->r1 == 0) {
        // 0x80105F0C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80105F7C;
    }
    // 0x80105F0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80105F10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105F14: addu        $at, $at, $t6
    gpr jr_addend_80105F1C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80105F18: lw          $t6, 0xAA4($at)
    ctx->r14 = ADD32(ctx->r1, 0XAA4);
    // 0x80105F1C: jr          $t6
    // 0x80105F20: nop

    switch (jr_addend_80105F1C >> 2) {
        case 0: goto L_80105F24; break;
        case 1: goto L_80105F34; break;
        case 2: goto L_80105F44; break;
        case 3: goto L_80105F54; break;
        case 4: goto L_80105F64; break;
        case 5: goto L_80105F74; break;
        default: switch_error(__func__, 0x80105F1C, 0x80130AA4);
    }
    // 0x80105F20: nop

L_80105F24:
    // 0x80105F24: jal         0x80105AF0
    // 0x80105F28: nop

    grPupupuWhispyUpdateSleep(rdram, ctx);
        goto after_0;
    // 0x80105F28: nop

    after_0:
    // 0x80105F2C: b           L_80105F7C
    // 0x80105F30: nop

        goto L_80105F7C;
    // 0x80105F30: nop

L_80105F34:
    // 0x80105F34: jal         0x80105BE8
    // 0x80105F38: nop

    grPupupuWhispyUpdateWait(rdram, ctx);
        goto after_1;
    // 0x80105F38: nop

    after_1:
    // 0x80105F3C: b           L_80105F7C
    // 0x80105F40: nop

        goto L_80105F7C;
    // 0x80105F40: nop

L_80105F44:
    // 0x80105F44: jal         0x80105C70
    // 0x80105F48: nop

    grPupupuWhispyUpdateTurn(rdram, ctx);
        goto after_2;
    // 0x80105F48: nop

    after_2:
    // 0x80105F4C: b           L_80105F7C
    // 0x80105F50: nop

        goto L_80105F7C;
    // 0x80105F50: nop

L_80105F54:
    // 0x80105F54: jal         0x80105CAC
    // 0x80105F58: nop

    grPupupuWhispyUpdateOpen(rdram, ctx);
        goto after_3;
    // 0x80105F58: nop

    after_3:
    // 0x80105F5C: b           L_80105F7C
    // 0x80105F60: nop

        goto L_80105F7C;
    // 0x80105F60: nop

L_80105F64:
    // 0x80105F64: jal         0x80105D6C
    // 0x80105F68: nop

    grPupupuWhispyUpdateBlow(rdram, ctx);
        goto after_4;
    // 0x80105F68: nop

    after_4:
    // 0x80105F6C: b           L_80105F7C
    // 0x80105F70: nop

        goto L_80105F7C;
    // 0x80105F70: nop

L_80105F74:
    // 0x80105F74: jal         0x80105DD8
    // 0x80105F78: nop

    grPupupuWhispyUpdateStop(rdram, ctx);
        goto after_5;
    // 0x80105F78: nop

    after_5:
L_80105F7C:
    // 0x80105F7C: jal         0x80105E34
    // 0x80105F80: nop

    grPupupuWhispyUpdateBlink(rdram, ctx);
        goto after_6;
    // 0x80105F80: nop

    after_6:
    // 0x80105F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105F8C: jr          $ra
    // 0x80105F90: nop

    return;
    // 0x80105F90: nop

;}
RECOMP_FUNC void grWallpaperPausePerspUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104CB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80104CB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104CBC: jr          $ra
    // 0x80104CC0: sb          $t6, 0x13D0($at)
    MEM_B(0X13D0, ctx->r1) = ctx->r14;
    return;
    // 0x80104CC0: sb          $t6, 0x13D0($at)
    MEM_B(0X13D0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mn1PModeFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x30A0
    ctx->r24 = ADD32(ctx->r24, 0X30A0);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void syDebugGetFaultThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022FA0: jal         0x80035420
    // 0x80022FA4: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x80022FA4: nop

    after_0:
    // 0x80022FA8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80022FAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80022FB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80022FB4: beq         $a0, $t6, L_80022FF8
    if (ctx->r4 == ctx->r14) {
        // 0x80022FB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80022FF8;
    }
    // 0x80022FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022FBC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80022FC0:
    // 0x80022FC0: blez        $v0, L_80022FE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022FC4: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_80022FE8;
    }
    // 0x80022FC4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80022FC8: beql        $at, $zero, L_80022FEC
    if (ctx->r1 == 0) {
        // 0x80022FCC: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_80022FEC;
    }
    goto skip_0;
    // 0x80022FCC: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x80022FD0: lhu         $t7, 0x12($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X12);
    // 0x80022FD4: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80022FD8: beql        $t8, $zero, L_80022FEC
    if (ctx->r24 == 0) {
        // 0x80022FDC: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_80022FEC;
    }
    goto skip_1;
    // 0x80022FDC: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x80022FE0: b           L_80022FFC
    // 0x80022FE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80022FFC;
    // 0x80022FE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80022FE8:
    // 0x80022FE8: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
L_80022FEC:
    // 0x80022FEC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80022FF0: bne         $a0, $v0, L_80022FC0
    if (ctx->r4 != ctx->r2) {
        // 0x80022FF4: nop
    
            goto L_80022FC0;
    }
    // 0x80022FF4: nop

L_80022FF8:
    // 0x80022FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022FFC:
    // 0x80022FFC: jr          $ra
    // 0x80023000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80023000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ifCommonBattleInitPlacement(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113488: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011348C: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // 0x80113490: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
L_80113494:
    // 0x80113494: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80113498: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8011349C: bne         $at, $zero, L_80113494
    if (ctx->r1 != 0) {
        // 0x801134A0: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_80113494;
    }
    // 0x801134A0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801134A4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801134A8: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x801134AC: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x801134B0: beq         $v0, $zero, L_801134C8
    if (ctx->r2 == 0) {
        // 0x801134B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801134C8;
    }
    // 0x801134B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801134B8: beql        $v0, $at, L_8011352C
    if (ctx->r2 == ctx->r1) {
        // 0x801134BC: lbu         $t8, 0x22($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X22);
            goto L_8011352C;
    }
    goto skip_0;
    // 0x801134BC: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    skip_0:
    // 0x801134C0: b           L_801135C8
    // 0x801134C4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_801135C8;
    // 0x801134C4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
L_801134C8:
    // 0x801134C8: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x801134CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801134D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801134D4: beq         $a0, $t6, L_801134E4
    if (ctx->r4 == ctx->r14) {
        // 0x801134D8: lw          $t7, 0x10($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X10);
            goto L_801134E4;
    }
    // 0x801134D8: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x801134DC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801134E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
L_801134E4:
    // 0x801134E4: lbu         $t9, 0x96($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X96);
    // 0x801134E8: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x801134EC: beq         $a0, $t9, L_801134F8
    if (ctx->r4 == ctx->r25) {
        // 0x801134F0: addiu       $t1, $t0, 0x1
        ctx->r9 = ADD32(ctx->r8, 0X1);
            goto L_801134F8;
    }
    // 0x801134F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801134F4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
L_801134F8:
    // 0x801134F8: lbu         $t2, 0x10A($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10A);
    // 0x801134FC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80113500: beq         $a0, $t2, L_8011350C
    if (ctx->r4 == ctx->r10) {
        // 0x80113504: addiu       $t4, $t3, 0x1
        ctx->r12 = ADD32(ctx->r11, 0X1);
            goto L_8011350C;
    }
    // 0x80113504: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80113508: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
L_8011350C:
    // 0x8011350C: lbu         $t5, 0x17E($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17E);
    // 0x80113510: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80113514: beq         $a0, $t5, L_80113520
    if (ctx->r4 == ctx->r13) {
        // 0x80113518: addiu       $t7, $t6, 0x1
        ctx->r15 = ADD32(ctx->r14, 0X1);
            goto L_80113520;
    }
    // 0x80113518: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8011351C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80113520:
    // 0x80113520: b           L_801135C8
    // 0x80113524: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
        goto L_801135C8;
    // 0x80113524: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80113528: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
L_8011352C:
    // 0x8011352C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80113530: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80113534: beql        $a0, $t8, L_8011355C
    if (ctx->r4 == ctx->r24) {
        // 0x80113538: lbu         $t3, 0x96($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X96);
            goto L_8011355C;
    }
    goto skip_1;
    // 0x80113538: lbu         $t3, 0x96($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X96);
    skip_1:
    // 0x8011353C: lbu         $t9, 0x24($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X24);
    // 0x80113540: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80113544: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80113548: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
    // 0x8011354C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80113550: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80113554: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80113558: lbu         $t3, 0x96($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X96);
L_8011355C:
    // 0x8011355C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80113560: beql        $a0, $t3, L_80113584
    if (ctx->r4 == ctx->r11) {
        // 0x80113564: lbu         $t8, 0x10A($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X10A);
            goto L_80113584;
    }
    goto skip_2;
    // 0x80113564: lbu         $t8, 0x10A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10A);
    skip_2:
    // 0x80113568: lbu         $t4, 0x98($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X98);
    // 0x8011356C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80113570: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x80113574: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80113578: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8011357C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80113580: lbu         $t8, 0x10A($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10A);
L_80113584:
    // 0x80113584: beql        $a0, $t8, L_801135A8
    if (ctx->r4 == ctx->r24) {
        // 0x80113588: lbu         $t3, 0x17E($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X17E);
            goto L_801135A8;
    }
    goto skip_3;
    // 0x80113588: lbu         $t3, 0x17E($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17E);
    skip_3:
    // 0x8011358C: lbu         $t9, 0x10C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10C);
    // 0x80113590: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80113594: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
    // 0x80113598: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8011359C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801135A0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801135A4: lbu         $t3, 0x17E($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17E);
L_801135A8:
    // 0x801135A8: beql        $a0, $t3, L_801135CC
    if (ctx->r4 == ctx->r11) {
        // 0x801135AC: lw          $t8, 0x10($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X10);
            goto L_801135CC;
    }
    goto skip_4;
    // 0x801135AC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    skip_4:
    // 0x801135B0: lbu         $t4, 0x180($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X180);
    // 0x801135B4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801135B8: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x801135BC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801135C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801135C4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_801135C8:
    // 0x801135C8: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
L_801135CC:
    // 0x801135CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801135D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801135D4: beq         $t8, $zero, L_801135E0
    if (ctx->r24 == 0) {
        // 0x801135D8: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_801135E0;
    }
    // 0x801135D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801135DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801135E0:
    // 0x801135E0: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x801135E4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801135E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801135EC: beql        $t0, $zero, L_801135FC
    if (ctx->r8 == 0) {
        // 0x801135F0: lw          $t1, 0x4($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X4);
            goto L_801135FC;
    }
    goto skip_5;
    // 0x801135F0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    skip_5:
    // 0x801135F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801135F8: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
L_801135FC:
    // 0x801135FC: beql        $t1, $zero, L_8011360C
    if (ctx->r9 == 0) {
        // 0x80113600: lw          $t2, 0x8($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X8);
            goto L_8011360C;
    }
    goto skip_6;
    // 0x80113600: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    skip_6:
    // 0x80113604: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80113608: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
L_8011360C:
    // 0x8011360C: beql        $t2, $zero, L_8011361C
    if (ctx->r10 == 0) {
        // 0x80113610: lw          $t3, 0xC($v1)
        ctx->r11 = MEM_W(ctx->r3, 0XC);
            goto L_8011361C;
    }
    goto skip_7;
    // 0x80113610: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    skip_7:
    // 0x80113614: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80113618: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
L_8011361C:
    // 0x8011361C: beql        $t3, $zero, L_8011362C
    if (ctx->r11 == 0) {
        // 0x80113620: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_8011362C;
    }
    goto skip_8;
    // 0x80113620: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    skip_8:
    // 0x80113624: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80113628: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
L_8011362C:
    // 0x8011362C: sw          $t4, 0x17F4($at)
    MEM_W(0X17F4, ctx->r1) = ctx->r12;
    // 0x80113630: jr          $ra
    // 0x80113634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80113634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80375B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80375B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375B0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80375B10: beq         $a0, $zero, L_80375B7C
    if (ctx->r4 == 0) {
        // 0x80375B14: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80375B7C;
    }
    // 0x80375B14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80375B18: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80375B1C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375B20: addiu       $t6, $t6, -0x67D0
    ctx->r14 = ADD32(ctx->r14, -0X67D0);
    // 0x80375B24: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80375B28: addiu       $t7, $t7, -0x6768
    ctx->r15 = ADD32(ctx->r15, -0X6768);
    // 0x80375B2C: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80375B30: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80375B34: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80375B38: jal         0x803720D4
    // 0x80375B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803720D4(rdram, ctx);
        goto after_0;
    // 0x80375B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80375B40: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80375B44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80375B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80375B4C: beql        $t9, $zero, L_80375B68
    if (ctx->r25 == 0) {
        // 0x80375B50: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80375B68;
    }
    goto skip_0;
    // 0x80375B50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80375B54: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80375B58: jal         0x803718C4
    // 0x80375B5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_803718C4(rdram, ctx);
        goto after_1;
    // 0x80375B5C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80375B60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80375B64: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_80375B68:
    // 0x80375B68: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80375B6C: beql        $t1, $zero, L_80375B80
    if (ctx->r9 == 0) {
        // 0x80375B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80375B80;
    }
    goto skip_1;
    // 0x80375B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80375B74: jal         0x803717C0
    // 0x80375B78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_2;
    // 0x80375B78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80375B7C:
    // 0x80375B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80375B80:
    // 0x80375B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80375B84: jr          $ra
    // 0x80375B88: nop

    return;
    // 0x80375B88: nop

;}
RECOMP_FUNC void gmRumbleUpdateEventExecute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114E30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80114E34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80114E38: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80114E3C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80114E40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80114E44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80114E48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80114E4C: lhu         $a3, 0x2($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X2);
    // 0x80114E50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80114E54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80114E58: bne         $a3, $zero, L_80114F74
    if (ctx->r7 != 0) {
        // 0x80114E5C: or          $s2, $a2, $zero
        ctx->r18 = ctx->r6 | 0;
            goto L_80114F74;
    }
    // 0x80114E5C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80114E60: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80114E64: addiu       $s3, $s3, -0xE00
    ctx->r19 = ADD32(ctx->r19, -0XE00);
    // 0x80114E68: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80114E6C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_80114E70:
    // 0x80114E70: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80114E74: srl         $t6, $v1, 13
    ctx->r14 = S32(U32(ctx->r3) >> 13);
    // 0x80114E78: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80114E7C: beq         $at, $zero, L_80114F6C
    if (ctx->r1 == 0) {
        // 0x80114E80: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80114F6C;
    }
    // 0x80114E80: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80114E84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114E88: addu        $at, $at, $t6
    gpr jr_addend_80114E90 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80114E8C: lw          $t6, 0xCD0($at)
    ctx->r14 = ADD32(ctx->r1, 0XCD0);
    // 0x80114E90: jr          $t6
    // 0x80114E94: nop

    switch (jr_addend_80114E90 >> 2) {
        case 0: goto L_80114E98; break;
        case 1: goto L_80114EB4; break;
        case 2: goto L_80114EE8; break;
        case 3: goto L_80114F1C; break;
        case 4: goto L_80114F38; break;
        default: switch_error(__func__, 0x80114E90, 0x80130CD0);
    }
    // 0x80114E94: nop

L_80114E98:
    // 0x80114E98: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80114E9C: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
    // 0x80114EA0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80114EA4: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80114EA8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80114EAC: b           L_80114F6C
    // 0x80114EB0: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
        goto L_80114F6C;
    // 0x80114EB0: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
L_80114EB4:
    // 0x80114EB4: andi        $t1, $v1, 0x1FFF
    ctx->r9 = ctx->r3 & 0X1FFF;
    // 0x80114EB8: addiu       $t2, $v0, 0x2
    ctx->r10 = ADD32(ctx->r2, 0X2);
    // 0x80114EBC: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80114EC0: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
    // 0x80114EC4: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80114EC8: bne         $t3, $zero, L_80114EE0
    if (ctx->r11 != 0) {
        // 0x80114ECC: nop
    
            goto L_80114EE0;
    }
    // 0x80114ECC: nop

    // 0x80114ED0: jal         0x80004474
    // 0x80114ED4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syControllerStartRumble(rdram, ctx);
        goto after_0;
    // 0x80114ED4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80114ED8: sb          $s4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r20;
    // 0x80114EDC: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_80114EE0:
    // 0x80114EE0: b           L_80114F6C
    // 0x80114EE4: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
        goto L_80114F6C;
    // 0x80114EE4: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
L_80114EE8:
    // 0x80114EE8: andi        $t5, $v1, 0x1FFF
    ctx->r13 = ctx->r3 & 0X1FFF;
    // 0x80114EEC: addiu       $t6, $v0, 0x2
    ctx->r14 = ADD32(ctx->r2, 0X2);
    // 0x80114EF0: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x80114EF4: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
    // 0x80114EF8: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x80114EFC: beq         $t7, $zero, L_80114F14
    if (ctx->r15 == 0) {
        // 0x80114F00: nop
    
            goto L_80114F14;
    }
    // 0x80114F00: nop

    // 0x80114F04: jal         0x80004494
    // 0x80114F08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_1;
    // 0x80114F08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80114F0C: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x80114F10: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80114F14:
    // 0x80114F14: b           L_80114F6C
    // 0x80114F18: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
        goto L_80114F6C;
    // 0x80114F18: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
L_80114F1C:
    // 0x80114F1C: andi        $t9, $v1, 0x1FFF
    ctx->r25 = ctx->r3 & 0X1FFF;
    // 0x80114F20: addiu       $t0, $v0, 0x2
    ctx->r8 = ADD32(ctx->r2, 0X2);
    // 0x80114F24: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80114F28: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x80114F2C: sw          $t0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r8;
    // 0x80114F30: b           L_80114F6C
    // 0x80114F34: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
        goto L_80114F6C;
    // 0x80114F34: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
L_80114F38:
    // 0x80114F38: lhu         $t2, 0x4($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X4);
    // 0x80114F3C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80114F40: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80114F44: beq         $t4, $zero, L_80114F5C
    if (ctx->r12 == 0) {
        // 0x80114F48: sh          $t3, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r11;
            goto L_80114F5C;
    }
    // 0x80114F48: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x80114F4C: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80114F50: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
    // 0x80114F54: b           L_80114F6C
    // 0x80114F58: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
        goto L_80114F6C;
    // 0x80114F58: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
L_80114F5C:
    // 0x80114F5C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80114F60: lhu         $a3, 0x2($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2);
    // 0x80114F64: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80114F68: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_80114F6C:
    // 0x80114F6C: beql        $a3, $zero, L_80114E70
    if (ctx->r7 == 0) {
        // 0x80114F70: lw          $v0, 0x10($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X10);
            goto L_80114E70;
    }
    goto skip_0;
    // 0x80114F70: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    skip_0:
L_80114F74:
    // 0x80114F74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80114F78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80114F7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80114F80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80114F84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80114F88: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80114F8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80114F90: jr          $ra
    // 0x80114F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80114F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void itLizardonCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F98C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F994: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017F998: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8017F99C: jal         0x801737B8
    // 0x8017F9A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017F9A0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017F9A4: beq         $v0, $zero, L_8017F9B8
    if (ctx->r2 == 0) {
        // 0x8017F9A8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8017F9B8;
    }
    // 0x8017F9A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F9AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017F9B0: nop

    // 0x8017F9B4: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8017F9B8:
    // 0x8017F9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F9BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F9C4: jr          $ra
    // 0x8017F9C8: nop

    return;
    // 0x8017F9C8: nop

;}
RECOMP_FUNC void mvOpeningLinkPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D824: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D828: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D82C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D830: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D834: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D838: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D83C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D840: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D844: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D848: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D84C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D850: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D854: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D858: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D85C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D860: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D864: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D868: lui         $t7, 0x9678
    ctx->r15 = S32(0X9678 << 16);
    // 0x8018D86C: ori         $t7, $t7, 0xB4FF
    ctx->r15 = ctx->r15 | 0XB4FF;
    // 0x8018D870: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D874: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D878: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D87C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D880: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D884: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D888: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D88C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D890: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D894: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D898: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D89C: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8A8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8AC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8B0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D8B4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8B8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8BC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D8C0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D8C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D8C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D8CC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8D0: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8018D8D4: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8018D8D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8DC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8E0: ori         $t6, $t6, 0x8168
    ctx->r14 = ctx->r14 | 0X8168;
    // 0x8018D8E4: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D8E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8F0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8F4: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D8F8: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D8FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D900: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D904: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D908: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D90C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D910: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D914: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D918: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D91C: jr          $ra
    // 0x8018D920: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D920: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}

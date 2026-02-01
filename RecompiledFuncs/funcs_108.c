#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mpCollisionGetLWallEdgeU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4658: jal         0x800F4488
    // 0x800F465C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mpCollisionGetUDEdge(rdram, ctx);
        goto after_0;
    // 0x800F465C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800F4660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4668: jr          $ra
    // 0x800F466C: nop

    return;
    // 0x800F466C: nop

;}
RECOMP_FUNC void itStarRodThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017805C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178060: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80178068: addiu       $a1, $a1, -0x5EDC
    ctx->r5 = ADD32(ctx->r5, -0X5EDC);
    // 0x8017806C: jal         0x80172EC8
    // 0x80178070: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80178070: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80178074: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80178078: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017807C: lwc1        $f4, -0x32C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32C0);
    // 0x80178080: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80178084: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80178088: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x8017808C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178094: jr          $ra
    // 0x80178098: nop

    return;
    // 0x80178098: nop

;}
RECOMP_FUNC void efManagerFlashMiddleMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801016E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801016E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801016E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801016EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801016F0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801016F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801016F8: jal         0x800CE870
    // 0x801016FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x801016FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80101700: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101704: beq         $v0, $zero, L_80101724
    if (ctx->r2 == 0) {
        // 0x80101708: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80101724;
    }
    // 0x80101708: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010170C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80101710: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80101714: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80101718: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x8010171C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80101720: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_80101724:
    // 0x80101724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010172C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101730: jr          $ra
    // 0x80101734: nop

    return;
    // 0x80101734: nop

;}
RECOMP_FUNC void wpSamusChargeShotMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168DDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80168DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168DE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80168DE8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80168DEC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80168DF0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80168DF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80168DF8: beq         $a3, $zero, L_80168E08
    if (ctx->r7 == 0) {
        // 0x80168DFC: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80168E08;
    }
    // 0x80168DFC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80168E00: b           L_80168E0C
    // 0x80168E04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
        goto L_80168E0C;
    // 0x80168E04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
L_80168E08:
    // 0x80168E08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80168E0C:
    // 0x80168E0C: addiu       $a1, $a1, -0x6FD0
    ctx->r5 = ADD32(ctx->r5, -0X6FD0);
    // 0x80168E10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80168E14: jal         0x801655C8
    // 0x80168E18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80168E18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168E1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80168E20: bne         $v0, $zero, L_80168E30
    if (ctx->r2 != 0) {
        // 0x80168E24: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80168E30;
    }
    // 0x80168E24: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80168E28: b           L_80168EEC
    // 0x80168E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80168EEC;
    // 0x80168E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168E30:
    // 0x80168E30: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80168E34: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80168E38: sw          $a0, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r4;
    // 0x80168E3C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80168E40: beq         $a0, $zero, L_80168E64
    if (ctx->r4 == 0) {
        // 0x80168E44: sw          $t8, 0x2A4($v1)
        MEM_W(0X2A4, ctx->r3) = ctx->r24;
            goto L_80168E64;
    }
    // 0x80168E44: sw          $t8, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r24;
    // 0x80168E48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80168E4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80168E50: jal         0x80168B00
    // 0x80168E54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    wpSamusChargeShotLaunch(rdram, ctx);
        goto after_1;
    // 0x80168E54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80168E58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80168E5C: b           L_80168EA4
    // 0x80168E60: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_80168EA4;
    // 0x80168E60: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80168E64:
    // 0x80168E64: lw          $t0, 0x2A4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2A4);
    // 0x80168E68: sw          $zero, 0x100($v1)
    MEM_W(0X100, ctx->r3) = 0;
    // 0x80168E6C: sw          $zero, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = 0;
    // 0x80168E70: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80168E74: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80168E78: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80168E7C: sw          $t9, 0x2A8($v1)
    MEM_W(0X2A8, ctx->r3) = ctx->r25;
    // 0x80168E80: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80168E84: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80168E88: lhu         $a1, -0x70D6($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X70D6);
    // 0x80168E8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80168E90: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80168E94: jal         0x800E8190
    // 0x80168E98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftParamPlayLoopSFX(rdram, ctx);
        goto after_2;
    // 0x80168E98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80168E9C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80168EA0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80168EA4:
    // 0x80168EA4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80168EA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80168EAC: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x80168EB0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80168EB4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80168EB8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80168EBC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80168EC0: lwc1        $f4, -0x70F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X70F0);
    // 0x80168EC4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80168EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80168ECC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80168ED0: addiu       $t6, $t6, -0x7424
    ctx->r14 = ADD32(ctx->r14, -0X7424);
    // 0x80168ED4: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80168ED8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80168EDC: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x80168EE0: lw          $t5, 0x74($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X74);
    // 0x80168EE4: swc1        $f0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f0.u32l;
    // 0x80168EE8: sw          $t6, 0x298($v1)
    MEM_W(0X298, ctx->r3) = ctx->r14;
L_80168EEC:
    // 0x80168EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80168EF4: jr          $ra
    // 0x80168EF8: nop

    return;
    // 0x80168EF8: nop

;}
RECOMP_FUNC void ftNessSpecialHiJibakuSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154DFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80154E00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80154E04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80154E08: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80154E0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80154E10: lw          $t6, 0xF4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF4);
    // 0x80154E14: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80154E18: bne         $t7, $zero, L_80154F20
    if (ctx->r15 != 0) {
        // 0x80154E1C: nop
    
            goto L_80154F20;
    }
    // 0x80154E1C: nop

    // 0x80154E20: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80154E24: lwc1        $f6, 0xB30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB30);
    // 0x80154E28: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80154E2C: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80154E30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80154E34: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80154E38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80154E3C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80154E40: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80154E44: lwc1        $f4, 0xB34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XB34);
    // 0x80154E48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80154E4C: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x80154E50: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x80154E54: addiu       $a0, $a2, 0xF8
    ctx->r4 = ADD32(ctx->r6, 0XF8);
    // 0x80154E58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80154E5C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80154E60: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80154E64: jal         0x800191FC
    // 0x80154E68: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_0;
    // 0x80154E68: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80154E6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154E70: lwc1        $f10, -0x3A04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A04);
    // 0x80154E74: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80154E78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80154E7C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80154E80: nop

    // 0x80154E84: bc1t        L_80154F20
    if (c1cs) {
        // 0x80154E88: nop
    
            goto L_80154F20;
    }
    // 0x80154E88: nop

    // 0x80154E8C: lwc1        $f16, -0x3A00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A00);
    // 0x80154E90: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80154E94: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80154E98: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154E9C: bc1t        L_80154F38
    if (c1cs) {
        // 0x80154EA0: nop
    
            goto L_80154F38;
    }
    // 0x80154EA0: nop

    // 0x80154EA4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80154EA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80154EAC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80154EB0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80154EB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80154EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80154EBC: bc1fl       L_80154ED0
    if (!c1cs) {
        // 0x80154EC0: sw          $t1, 0x44($a2)
        MEM_W(0X44, ctx->r6) = ctx->r9;
            goto L_80154ED0;
    }
    goto skip_0;
    // 0x80154EC0: sw          $t1, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r9;
    skip_0:
    // 0x80154EC4: b           L_80154ED0
    // 0x80154EC8: sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
        goto L_80154ED0;
    // 0x80154EC8: sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
    // 0x80154ECC: sw          $t1, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r9;
L_80154ED0:
    // 0x80154ED0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80154ED4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80154ED8: nop

    // 0x80154EDC: bc1f        L_80154EEC
    if (!c1cs) {
        // 0x80154EE0: nop
    
            goto L_80154EEC;
    }
    // 0x80154EE0: nop

    // 0x80154EE4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80154EE8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
L_80154EEC:
    // 0x80154EEC: jal         0x80154DBC
    // 0x80154EF0: swc1        $f18, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f18.u32l;
    ftNessSpecialHiJibakuInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80154EF0: swc1        $f18, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f18.u32l;
    after_1:
    // 0x80154EF4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80154EF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80154EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80154F00: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80154F04: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80154F08: jal         0x800E6F24
    // 0x80154F0C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80154F0C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80154F10: jal         0x800E0830
    // 0x80154F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x80154F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80154F18: b           L_80154F44
    // 0x80154F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80154F44;
    // 0x80154F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80154F20:
    // 0x80154F20: jal         0x800DEEC8
    // 0x80154F24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_4;
    // 0x80154F24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80154F28: jal         0x80154F54
    // 0x80154F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftNessSpecialAirHiJibakuSetStatus(rdram, ctx);
        goto after_5;
    // 0x80154F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80154F30: b           L_80154F44
    // 0x80154F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80154F44;
    // 0x80154F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80154F38:
    // 0x80154F38: jal         0x80144498
    // 0x80154F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_6;
    // 0x80154F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80154F40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80154F44:
    // 0x80154F44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80154F48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80154F4C: jr          $ra
    // 0x80154F50: nop

    return;
    // 0x80154F50: nop

;}
RECOMP_FUNC void func_ovl59_80131DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DD0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80131DD4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80131DD8: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80131DDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80131DE0: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x80131DE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131DE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131DEC: swc1        $f12, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f12.u32l;
    // 0x80131DF0: swc1        $f12, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f12.u32l;
    // 0x80131DF4: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x80131DF8: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x80131DFC: swc1        $f14, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f14.u32l;
    // 0x80131E00: swc1        $f14, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80131E04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131E08: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80131E0C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x80131E10: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x80131E14: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131E18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80131E1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131E20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E24: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80131E28: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x80131E2C: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80131E30: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80131E34: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80131E38: nop

    // 0x80131E3C: bc1fl       L_80131E50
    if (!c1cs) {
        // 0x80131E40: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80131E50;
    }
    goto skip_0;
    // 0x80131E40: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x80131E44: b           L_80131E50
    // 0x80131E48: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80131E50;
    // 0x80131E48: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80131E4C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80131E50:
    // 0x80131E50: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80131E54: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80131E58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131E5C: nop

    // 0x80131E60: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80131E64: swc1        $f2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f2.u32l;
    // 0x80131E68: jr          $ra
    // 0x80131E6C: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    return;
    // 0x80131E6C: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
;}
RECOMP_FUNC void efManagerFlameRandgcMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE9B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE9B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FE9BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FE9C0: jal         0x800FD4B8
    // 0x800FE9C4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE9C4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FE9C8: bne         $v0, $zero, L_800FE9D8
    if (ctx->r2 != 0) {
        // 0x800FE9CC: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FE9D8;
    }
    // 0x800FE9CC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FE9D0: b           L_800FEB44
    // 0x800FE9D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEB44;
    // 0x800FE9D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE9D8:
    // 0x800FE9D8: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FE9DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE9E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FE9E4: jal         0x80009968
    // 0x800FE9E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FE9E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FE9EC: bne         $v0, $zero, L_800FEA04
    if (ctx->r2 != 0) {
        // 0x800FE9F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FEA04;
    }
    // 0x800FE9F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FE9F4: jal         0x800FD4F8
    // 0x800FE9F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FE9F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FE9FC: b           L_800FEB44
    // 0x800FEA00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEB44;
    // 0x800FEA00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEA04:
    // 0x800FEA04: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FEA08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FEA0C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800FEA10: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FEA14: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FEA18: jal         0x800CE9E8
    // 0x800FEA1C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FEA1C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FEA20: beq         $v0, $zero, L_800FEB34
    if (ctx->r2 == 0) {
        // 0x800FEA24: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FEB34;
    }
    // 0x800FEA24: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FEA28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FEA2C: jal         0x800CE1DC
    // 0x800FEA30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FEA30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FEA34: beq         $v0, $zero, L_800FEB20
    if (ctx->r2 == 0) {
        // 0x800FEA38: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FEB20;
    }
    // 0x800FEA38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FEA3C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FEA40: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FEA44: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FEA48: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FEA4C: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FEA50: jal         0x800CEA14
    // 0x800FEA54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FEA54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FEA58: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FEA5C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FEA60: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FEA64: bne         $t9, $zero, L_800FEA74
    if (ctx->r25 != 0) {
        // 0x800FEA68: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FEA74;
    }
    // 0x800FEA68: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FEA6C: b           L_800FEB44
    // 0x800FEA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FEB44;
    // 0x800FEA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FEA74:
    // 0x800FEA74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FEA78: jal         0x80008188
    // 0x800FEA7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FEA7C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FEA80: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FEA84: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FEA88: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FEA8C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FEA90: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FEA94: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FEA98: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FEA9C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FEAA0: jal         0x80018948
    // 0x800FEAA4: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FEAA4: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FEAA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEAAC: lwc1        $f4, 0x95C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X95C);
    // 0x800FEAB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FEAB4: lwc1        $f8, 0x960($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X960);
    // 0x800FEAB8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FEABC: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FEAC0: jal         0x80035CD0
    // 0x800FEAC4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_8;
    // 0x800FEAC4: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_8:
    // 0x800FEAC8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800FEACC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FEAD0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FEAD4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FEAD8: swc1        $f16, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f16.u32l;
    // 0x800FEADC: jal         0x800303F0
    // 0x800FEAE0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FEAE0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x800FEAE4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800FEAE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FEAEC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FEAF0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FEAF4: jal         0x80018948
    // 0x800FEAF8: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x800FEAF8: swc1        $f4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f4.u32l;
    after_10:
    // 0x800FEAFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FEB00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FEB04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FEB08: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FEB0C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FEB10: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x800FEB14: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x800FEB18: b           L_800FEB40
    // 0x800FEB1C: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
        goto L_800FEB40;
    // 0x800FEB1C: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
L_800FEB20:
    // 0x800FEB20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FEB24: jal         0x800FDB3C
    // 0x800FEB28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x800FEB28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x800FEB2C: b           L_800FEB40
    // 0x800FEB30: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FEB40;
    // 0x800FEB30: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FEB34:
    // 0x800FEB34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FEB38: jal         0x800FDB3C
    // 0x800FEB3C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FEB3C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_800FEB40:
    // 0x800FEB40: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FEB44:
    // 0x800FEB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FEB48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FEB4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FEB50: jr          $ra
    // 0x800FEB54: nop

    return;
    // 0x800FEB54: nop

;}
RECOMP_FUNC void ftBossCommonUpdateFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158528: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015852C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80158530: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158534: lw          $t6, 0x8E8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8E8);
    // 0x80158538: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8015853C: lwc1        $f0, 0x24($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80158540: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80158544: nop

    // 0x80158548: bc1f        L_80158560
    if (!c1cs) {
        // 0x8015854C: nop
    
            goto L_80158560;
    }
    // 0x8015854C: nop

    // 0x80158550: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80158554: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80158558: b           L_80158590
    // 0x8015855C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
        goto L_80158590;
    // 0x8015855C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_80158560:
    // 0x80158560: lwc1        $f14, -0x38E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X38E4);
    // 0x80158564: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158568: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8015856C: nop

    // 0x80158570: bc1fl       L_80158584
    if (!c1cs) {
        // 0x80158574: sub.s       $f4, $f0, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_80158584;
    }
    goto skip_0;
    // 0x80158574: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    skip_0:
    // 0x80158578: b           L_8015858C
    // 0x8015857C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8015858C;
    // 0x8015857C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80158580: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
L_80158584:
    // 0x80158584: lwc1        $f6, -0x38E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X38E0);
    // 0x80158588: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
L_8015858C:
    // 0x8015858C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_80158590:
    // 0x80158590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80158594: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80158598: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8015859C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801585A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801585A4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801585A8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x801585AC: nop

    // 0x801585B0: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x801585B4: bnel        $at, $zero, L_801585CC
    if (ctx->r1 != 0) {
        // 0x801585B8: sb          $v1, 0xA8C($v0)
        MEM_B(0XA8C, ctx->r2) = ctx->r3;
            goto L_801585CC;
    }
    goto skip_1;
    // 0x801585B8: sb          $v1, 0xA8C($v0)
    MEM_B(0XA8C, ctx->r2) = ctx->r3;
    skip_1:
    // 0x801585BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801585C0: b           L_801585CC
    // 0x801585C4: sb          $a0, 0xA8C($v0)
    MEM_B(0XA8C, ctx->r2) = ctx->r4;
        goto L_801585CC;
    // 0x801585C4: sb          $a0, 0xA8C($v0)
    MEM_B(0XA8C, ctx->r2) = ctx->r4;
    // 0x801585C8: sb          $v1, 0xA8C($v0)
    MEM_B(0XA8C, ctx->r2) = ctx->r3;
L_801585CC:
    // 0x801585CC: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x801585D0: bnel        $at, $zero, L_801585E4
    if (ctx->r1 != 0) {
        // 0x801585D4: sb          $v1, 0xA8D($v0)
        MEM_B(0XA8D, ctx->r2) = ctx->r3;
            goto L_801585E4;
    }
    goto skip_2;
    // 0x801585D4: sb          $v1, 0xA8D($v0)
    MEM_B(0XA8D, ctx->r2) = ctx->r3;
    skip_2:
    // 0x801585D8: b           L_801585E4
    // 0x801585DC: sb          $a0, 0xA8D($v0)
    MEM_B(0XA8D, ctx->r2) = ctx->r4;
        goto L_801585E4;
    // 0x801585DC: sb          $a0, 0xA8D($v0)
    MEM_B(0XA8D, ctx->r2) = ctx->r4;
    // 0x801585E0: sb          $v1, 0xA8D($v0)
    MEM_B(0XA8D, ctx->r2) = ctx->r3;
L_801585E4:
    // 0x801585E4: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x801585E8: bnel        $at, $zero, L_801585FC
    if (ctx->r1 != 0) {
        // 0x801585EC: sb          $v1, 0xA8E($v0)
        MEM_B(0XA8E, ctx->r2) = ctx->r3;
            goto L_801585FC;
    }
    goto skip_3;
    // 0x801585EC: sb          $v1, 0xA8E($v0)
    MEM_B(0XA8E, ctx->r2) = ctx->r3;
    skip_3:
    // 0x801585F0: jr          $ra
    // 0x801585F4: sb          $a0, 0xA8E($v0)
    MEM_B(0XA8E, ctx->r2) = ctx->r4;
    return;
    // 0x801585F4: sb          $a0, 0xA8E($v0)
    MEM_B(0XA8E, ctx->r2) = ctx->r4;
    // 0x801585F8: sb          $v1, 0xA8E($v0)
    MEM_B(0XA8E, ctx->r2) = ctx->r3;
L_801585FC:
    // 0x801585FC: jr          $ra
    // 0x80158600: nop

    return;
    // 0x80158600: nop

;}
RECOMP_FUNC void func_ovl8_80373988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373988: jr          $ra
    // 0x8037398C: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
    return;
    // 0x8037398C: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void itBatThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174F7C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174F80: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80174F84: jal         0x80172558
    // 0x80174F88: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174F88: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_0:
    // 0x80174F8C: jal         0x801713F4
    // 0x80174F90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80174F90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80174F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174F9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174FA0: jr          $ra
    // 0x80174FA4: nop

    return;
    // 0x80174FA4: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltAirProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801695B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801695B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801695B8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801695BC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x801695C0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x801695C4: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x801695C8: jal         0x801680EC
    // 0x801695CC: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x801695CC: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    after_0:
    // 0x801695D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801695D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801695D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801695DC: jr          $ra
    // 0x801695E0: nop

    return;
    // 0x801695E0: nop

;}
RECOMP_FUNC void ftParamSetHitStatusPartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8884: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8888: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800E888C: lw          $t6, 0x5BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5BC);
    // 0x800E8890: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E8894: addiu       $a0, $v1, 0x5BC
    ctx->r4 = ADD32(ctx->r3, 0X5BC);
    // 0x800E8898: beql        $t6, $zero, L_800E88CC
    if (ctx->r14 == 0) {
        // 0x800E889C: lw          $t2, 0x5E8($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X5E8);
            goto L_800E88CC;
    }
    goto skip_0;
    // 0x800E889C: lw          $t2, 0x5E8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5E8);
    skip_0:
    // 0x800E88A0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800E88A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E88A8: bnel        $a1, $t7, L_800E88CC
    if (ctx->r5 != ctx->r15) {
        // 0x800E88AC: lw          $t2, 0x5E8($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X5E8);
            goto L_800E88CC;
    }
    goto skip_1;
    // 0x800E88AC: lw          $t2, 0x5E8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5E8);
    skip_1:
    // 0x800E88B0: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E88B4: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E88B4: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800E88B8: lbu         $t9, 0x18C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E88BC: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x800E88C0: jr          $ra
    // 0x800E88C4: sb          $t1, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r9;
    return;
    // 0x800E88C4: sb          $t1, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r9;
    // 0x800E88C8: lw          $t2, 0x5E8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5E8);
L_800E88CC:
    // 0x800E88CC: addiu       $a0, $v1, 0x5E8
    ctx->r4 = ADD32(ctx->r3, 0X5E8);
    // 0x800E88D0: beql        $t2, $zero, L_800E8904
    if (ctx->r10 == 0) {
        // 0x800E88D4: lw          $t7, 0x614($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X614);
            goto L_800E8904;
    }
    goto skip_2;
    // 0x800E88D4: lw          $t7, 0x614($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X614);
    skip_2:
    // 0x800E88D8: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800E88DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E88E0: bnel        $a3, $t3, L_800E8904
    if (ctx->r7 != ctx->r11) {
        // 0x800E88E4: lw          $t7, 0x614($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X614);
            goto L_800E8904;
    }
    goto skip_3;
    // 0x800E88E4: lw          $t7, 0x614($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X614);
    skip_3:
    // 0x800E88E8: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E88EC: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E88EC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800E88F0: lbu         $t5, 0x18C($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E88F4: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x800E88F8: jr          $ra
    // 0x800E88FC: sb          $t6, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r14;
    return;
    // 0x800E88FC: sb          $t6, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r14;
    // 0x800E8900: lw          $t7, 0x614($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X614);
L_800E8904:
    // 0x800E8904: addiu       $a0, $v1, 0x614
    ctx->r4 = ADD32(ctx->r3, 0X614);
    // 0x800E8908: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    // 0x800E890C: beq         $t7, $zero, L_800E893C
    if (ctx->r15 == 0) {
        // 0x800E8910: addiu       $t0, $zero, 0x1E4
        ctx->r8 = ADD32(0, 0X1E4);
            goto L_800E893C;
    }
    // 0x800E8910: addiu       $t0, $zero, 0x1E4
    ctx->r8 = ADD32(0, 0X1E4);
    // 0x800E8914: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800E8918: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E891C: bnel        $a3, $t8, L_800E8940
    if (ctx->r7 != ctx->r24) {
        // 0x800E8920: addiu       $a0, $zero, 0x84
        ctx->r4 = ADD32(0, 0X84);
            goto L_800E8940;
    }
    goto skip_4;
    // 0x800E8920: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    skip_4:
    // 0x800E8924: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E8928: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E8928: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800E892C: lbu         $t1, 0x18C($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8930: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x800E8934: jr          $ra
    // 0x800E8938: sb          $t2, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r10;
    return;
    // 0x800E8938: sb          $t2, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r10;
L_800E893C:
    // 0x800E893C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
L_800E8940:
    // 0x800E8940: lw          $t3, 0x5BC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X5BC);
    // 0x800E8944: addiu       $v1, $a1, 0x5BC
    ctx->r3 = ADD32(ctx->r5, 0X5BC);
    // 0x800E8948: beql        $t3, $zero, L_800E8978
    if (ctx->r11 == 0) {
        // 0x800E894C: lw          $t8, 0x5E8($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X5E8);
            goto L_800E8978;
    }
    goto skip_5;
    // 0x800E894C: lw          $t8, 0x5E8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X5E8);
    skip_5:
    // 0x800E8950: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800E8954: bne         $a3, $t4, L_800E8974
    if (ctx->r7 != ctx->r12) {
        // 0x800E8958: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800E8974;
    }
    // 0x800E8958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E895C: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E8960: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E8960: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800E8964: lbu         $t6, 0x18C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8968: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800E896C: jr          $ra
    // 0x800E8970: sb          $t7, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r15;
    return;
    // 0x800E8970: sb          $t7, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r15;
L_800E8974:
    // 0x800E8974: lw          $t8, 0x5E8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X5E8);
L_800E8978:
    // 0x800E8978: addiu       $v1, $a1, 0x5E8
    ctx->r3 = ADD32(ctx->r5, 0X5E8);
    // 0x800E897C: beql        $t8, $zero, L_800E89AC
    if (ctx->r24 == 0) {
        // 0x800E8980: lw          $t4, 0x614($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X614);
            goto L_800E89AC;
    }
    goto skip_6;
    // 0x800E8980: lw          $t4, 0x614($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X614);
    skip_6:
    // 0x800E8984: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800E8988: bne         $a3, $t9, L_800E89A8
    if (ctx->r7 != ctx->r25) {
        // 0x800E898C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800E89A8;
    }
    // 0x800E898C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E8990: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E8994: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E8994: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800E8998: lbu         $t2, 0x18C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E899C: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800E89A0: jr          $ra
    // 0x800E89A4: sb          $t3, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r11;
    return;
    // 0x800E89A4: sb          $t3, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r11;
L_800E89A8:
    // 0x800E89A8: lw          $t4, 0x614($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X614);
L_800E89AC:
    // 0x800E89AC: addiu       $v1, $a1, 0x614
    ctx->r3 = ADD32(ctx->r5, 0X614);
    // 0x800E89B0: beql        $t4, $zero, L_800E89E0
    if (ctx->r12 == 0) {
        // 0x800E89B4: lw          $t9, 0x640($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X640);
            goto L_800E89E0;
    }
    goto skip_7;
    // 0x800E89B4: lw          $t9, 0x640($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X640);
    skip_7:
    // 0x800E89B8: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800E89BC: bne         $a3, $t5, L_800E89DC
    if (ctx->r7 != ctx->r13) {
        // 0x800E89C0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800E89DC;
    }
    // 0x800E89C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E89C4: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E89C8: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E89C8: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800E89CC: lbu         $t7, 0x18C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E89D0: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800E89D4: jr          $ra
    // 0x800E89D8: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    return;
    // 0x800E89D8: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
L_800E89DC:
    // 0x800E89DC: lw          $t9, 0x640($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X640);
L_800E89E0:
    // 0x800E89E0: addiu       $v1, $a1, 0x640
    ctx->r3 = ADD32(ctx->r5, 0X640);
    // 0x800E89E4: addiu       $a0, $a0, 0xB0
    ctx->r4 = ADD32(ctx->r4, 0XB0);
    // 0x800E89E8: beq         $t9, $zero, L_800E8A14
    if (ctx->r25 == 0) {
        // 0x800E89EC: nop
    
            goto L_800E8A14;
    }
    // 0x800E89EC: nop

    // 0x800E89F0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800E89F4: bne         $a3, $t1, L_800E8A14
    if (ctx->r7 != ctx->r9) {
        // 0x800E89F8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800E8A14;
    }
    // 0x800E89F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E89FC: beq         $a2, $at, L_800E8A1C
    if (ctx->r6 == ctx->r1) {
        // 0x800E8A00: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_800E8A1C;
    }
    // 0x800E8A00: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800E8A04: lbu         $t3, 0x18C($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8A08: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x800E8A0C: jr          $ra
    // 0x800E8A10: sb          $t4, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r12;
    return;
    // 0x800E8A10: sb          $t4, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r12;
L_800E8A14:
    // 0x800E8A14: bne         $a0, $t0, L_800E8940
    if (ctx->r4 != ctx->r8) {
        // 0x800E8A18: addiu       $a1, $a1, 0xB0
        ctx->r5 = ADD32(ctx->r5, 0XB0);
            goto L_800E8940;
    }
    // 0x800E8A18: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
L_800E8A1C:
    // 0x800E8A1C: jr          $ra
    // 0x800E8A20: nop

    return;
    // 0x800E8A20: nop

;}
RECOMP_FUNC void efManagerImpactAirWaveMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFDE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFDEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFDF0: jal         0x800FFD58
    // 0x800FFDF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    efManagerImpactWaveMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800FFDF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x800FFDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFE00: jr          $ra
    // 0x800FFE04: nop

    return;
    // 0x800FFE04: nop

;}
RECOMP_FUNC void syControllerReadDeviceData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003DD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80003DD8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80003DDC: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80003DE0: addiu       $s7, $s7, 0x50F0
    ctx->r23 = ADD32(ctx->r23, 0X50F0);
    // 0x80003DE4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80003DE8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80003DEC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80003DF0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80003DF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80003DF8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80003DFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80003E00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80003E04: jal         0x80031F70
    // 0x80003E08: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80003E08: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x80003E0C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80003E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003E14: jal         0x80030210
    // 0x80003E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80003E18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80003E1C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80003E20: jal         0x80031FF4
    // 0x80003E24: addiu       $a0, $a0, 0x5188
    ctx->r4 = ADD32(ctx->r4, 0X5188);
    osContGetReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x80003E24: addiu       $a0, $a0, 0x5188
    ctx->r4 = ADD32(ctx->r4, 0X5188);
    after_2:
    // 0x80003E28: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80003E2C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80003E30: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80003E34: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80003E38: addiu       $s3, $s3, 0x5178
    ctx->r19 = ADD32(ctx->r19, 0X5178);
    // 0x80003E3C: addiu       $s4, $s4, 0x52C8
    ctx->r20 = ADD32(ctx->r20, 0X52C8);
    // 0x80003E40: addiu       $s0, $s0, 0x51A8
    ctx->r16 = ADD32(ctx->r16, 0X51A8);
    // 0x80003E44: addiu       $s1, $s1, 0x5188
    ctx->r17 = ADD32(ctx->r17, 0X5188);
    // 0x80003E48: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80003E4C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80003E50: addiu       $s5, $zero, 0x68
    ctx->r21 = ADD32(0, 0X68);
L_80003E54:
    // 0x80003E54: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80003E58: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80003E5C: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80003E60: bnel        $v0, $zero, L_80003EA8
    if (ctx->r2 != 0) {
        // 0x80003E64: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80003EA8;
    }
    goto skip_0;
    // 0x80003E64: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    skip_0:
    // 0x80003E68: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x80003E6C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80003E70: beql        $t9, $zero, L_80003EA8
    if (ctx->r25 == 0) {
        // 0x80003E74: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80003EA8;
    }
    goto skip_1;
    // 0x80003E74: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    skip_1:
    // 0x80003E78: lbu         $t0, 0x1C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1C);
    // 0x80003E7C: beql        $t0, $zero, L_80003EA8
    if (ctx->r8 == 0) {
        // 0x80003E80: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80003EA8;
    }
    goto skip_2;
    // 0x80003E80: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    skip_2:
    // 0x80003E84: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80003E8C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80003E90: mflo        $t1
    ctx->r9 = lo;
    // 0x80003E94: addu        $a1, $s4, $t1
    ctx->r5 = ADD32(ctx->r20, ctx->r9);
    // 0x80003E98: jal         0x800318C4
    // 0x80003E9C: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80003E9C: nop

    after_3:
    // 0x80003EA0: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80003EA4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
L_80003EA8:
    // 0x80003EA8: bne         $t2, $zero, L_80003F50
    if (ctx->r10 != 0) {
        // 0x80003EAC: sb          $v0, 0x1C($s0)
        MEM_B(0X1C, ctx->r16) = ctx->r2;
            goto L_80003F50;
    }
    // 0x80003EAC: sb          $v0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r2;
    // 0x80003EB0: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x80003EB4: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x80003EB8: xor         $v0, $a1, $a0
    ctx->r2 = ctx->r5 ^ ctx->r4;
    // 0x80003EBC: and         $t3, $a1, $v0
    ctx->r11 = ctx->r5 & ctx->r2;
    // 0x80003EC0: and         $t4, $a0, $v0
    ctx->r12 = ctx->r4 & ctx->r2;
    // 0x80003EC4: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x80003EC8: beq         $v0, $zero, L_80003EE4
    if (ctx->r2 == 0) {
        // 0x80003ECC: sh          $t4, 0xA($s0)
        MEM_H(0XA, ctx->r16) = ctx->r12;
            goto L_80003EE4;
    }
    // 0x80003ECC: sh          $t4, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r12;
    // 0x80003ED0: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x80003ED4: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x80003ED8: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80003EDC: b           L_80003F10
    // 0x80003EE0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_80003F10;
    // 0x80003EE0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_80003EE4:
    // 0x80003EE4: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80003EE8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80003EEC: blez        $t7, L_80003F00
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80003EF0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80003F00;
    }
    // 0x80003EF0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80003EF4: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x80003EF8: b           L_80003F10
    // 0x80003EFC: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
        goto L_80003F10;
    // 0x80003EFC: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
L_80003F00:
    // 0x80003F00: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80003F04: sh          $a1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r5;
    // 0x80003F08: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80003F0C: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
L_80003F10:
    // 0x80003F10: lhu         $t2, 0x4($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X4);
    // 0x80003F14: lhu         $t4, 0xC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XC);
    // 0x80003F18: lhu         $t5, 0xA($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XA);
    // 0x80003F1C: lhu         $t7, 0x8($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X8);
    // 0x80003F20: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    // 0x80003F24: lb          $t0, 0x2($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X2);
    // 0x80003F28: lb          $t1, 0x3($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X3);
    // 0x80003F2C: or          $t3, $t2, $v0
    ctx->r11 = ctx->r10 | ctx->r2;
    // 0x80003F30: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80003F34: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80003F38: sh          $a1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r5;
    // 0x80003F3C: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x80003F40: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
    // 0x80003F44: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x80003F48: sb          $t0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r8;
    // 0x80003F4C: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
L_80003F50:
    // 0x80003F50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80003F54: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80003F58: bne         $s2, $s6, L_80003E54
    if (ctx->r18 != ctx->r22) {
        // 0x80003F5C: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_80003E54;
    }
    // 0x80003F5C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80003F60: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80003F64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80003F68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80003F6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80003F70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80003F74: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80003F78: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80003F7C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80003F80: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80003F84: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80003F88: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80003F8C: sw          $t0, 0x5250($at)
    MEM_W(0X5250, ctx->r1) = ctx->r8;
    // 0x80003F90: jr          $ra
    // 0x80003F94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80003F94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayers1PTrainingCheckBackInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013586C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135870: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135878: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013587C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80135880: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135884: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135888: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8013588C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80135890: nop

    // 0x80135894: bc1t        L_801358B4
    if (c1cs) {
        // 0x80135898: nop
    
            goto L_801358B4;
    }
    // 0x80135898: nop

    // 0x8013589C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801358A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801358A4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801358A8: nop

    // 0x801358AC: bc1f        L_801358BC
    if (!c1cs) {
        // 0x801358B0: nop
    
            goto L_801358BC;
    }
    // 0x801358B0: nop

L_801358B4:
    // 0x801358B4: b           L_801358BC
    // 0x801358B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801358BC;
    // 0x801358B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801358BC:
    // 0x801358BC: beq         $v1, $zero, L_801358CC
    if (ctx->r3 == 0) {
        // 0x801358C0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801358CC;
    }
    // 0x801358C0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801358C4: jr          $ra
    // 0x801358C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801358C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801358CC:
    // 0x801358CC: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801358D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801358D4: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801358D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801358DC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801358E0: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x801358E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801358E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801358EC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801358F0: nop

    // 0x801358F4: bc1f        L_8013591C
    if (!c1cs) {
        // 0x801358F8: nop
    
            goto L_8013591C;
    }
    // 0x801358F8: nop

    // 0x801358FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135900: nop

    // 0x80135904: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135908: nop

    // 0x8013590C: bc1f        L_8013591C
    if (!c1cs) {
        // 0x80135910: nop
    
            goto L_8013591C;
    }
    // 0x80135910: nop

    // 0x80135914: b           L_8013591C
    // 0x80135918: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013591C;
    // 0x80135918: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013591C:
    // 0x8013591C: beq         $v1, $zero, L_8013592C
    if (ctx->r3 == 0) {
        // 0x80135920: nop
    
            goto L_8013592C;
    }
    // 0x80135920: nop

    // 0x80135924: jr          $ra
    // 0x80135928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013592C:
    // 0x8013592C: jr          $ra
    // 0x80135930: nop

    return;
    // 0x80135930: nop

;}
RECOMP_FUNC void ifCommonPlayerScoreMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801149CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801149D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801149D4: lbu         $v0, 0xD($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD);
    // 0x801149D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801149DC: addiu       $v1, $v1, 0x1580
    ctx->r3 = ADD32(ctx->r3, 0X1580);
    // 0x801149E0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x801149E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801149E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801149EC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x801149F0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801149F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801149F8: lw          $t6, -0x13B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X13B8);
    // 0x801149FC: lhu         $t2, 0xC($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XC);
    // 0x80114A00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80114A04: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80114A08: addiu       $t3, $t2, 0xD
    ctx->r11 = ADD32(ctx->r10, 0XD);
    // 0x80114A0C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80114A10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80114A14: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80114A18: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80114A1C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80114A20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80114A24: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80114A28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80114A2C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80114A30: jal         0x801040E0
    // 0x80114A34: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    efManagerBattleScoreMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80114A34: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80114A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114A3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80114A40: jr          $ra
    // 0x80114A44: nop

    return;
    // 0x80114A44: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNWaitSetStatusFromTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80162FE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162FE8: jal         0x80162F60
    // 0x80162FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialNWaitUpdateLR(rdram, ctx);
        goto after_0;
    // 0x80162FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162FF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80162FF4: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    // 0x80162FF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80162FFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163000: jal         0x800E6F24
    // 0x80163004: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163004: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80163008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016300C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163010: jr          $ra
    // 0x80163014: nop

    return;
    // 0x80163014: nop

;}
RECOMP_FUNC void mnVSModeGetCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013394C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80133950: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80133954: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80133958: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013395C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80133960: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80133964: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80133968: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8013396C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80133970: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133974: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133978: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013397C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80133980: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80133984: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
L_80133988:
    // 0x80133988: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8013398C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80133990: bne         $at, $zero, L_80133988
    if (ctx->r1 != 0) {
        // 0x80133994: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80133988;
    }
    // 0x80133994: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80133998: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x8013399C: addiu       $s7, $s7, 0x4D08
    ctx->r23 = ADD32(ctx->r23, 0X4D08);
    // 0x801339A0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x801339A4: addiu       $fp, $zero, 0x74
    ctx->r30 = ADD32(0, 0X74);
    // 0x801339A8: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x801339AC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801339B0: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x801339B4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
L_801339B8:
    // 0x801339B8: beql        $s6, $t6, L_80133A0C
    if (ctx->r22 == ctx->r14) {
        // 0x801339BC: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80133A0C;
    }
    goto skip_0;
    // 0x801339BC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_0:
    // 0x801339C0: multu       $s6, $fp
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801339C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801339C8: mflo        $t7
    ctx->r15 = lo;
    // 0x801339CC: addu        $s1, $s7, $t7
    ctx->r17 = ADD32(ctx->r23, ctx->r15);
    // 0x801339D0: lbu         $t8, 0x23($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X23);
    // 0x801339D4: bne         $s5, $t8, L_80133A08
    if (ctx->r21 != ctx->r24) {
        // 0x801339D8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80133A08;
    }
    // 0x801339D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_801339DC:
    // 0x801339DC: jal         0x800EC0EC
    // 0x801339E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801339E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801339E4: lbu         $t9, 0x26($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X26);
    // 0x801339E8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x801339EC: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x801339F0: bnel        $v0, $t9, L_80133A00
    if (ctx->r2 != ctx->r25) {
        // 0x801339F4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133A00;
    }
    goto skip_1;
    // 0x801339F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801339F8: sw          $s3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r19;
    // 0x801339FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133A00:
    // 0x80133A00: bnel        $s0, $s4, L_801339DC
    if (ctx->r16 != ctx->r20) {
        // 0x80133A04: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_801339DC;
    }
    goto skip_2;
    // 0x80133A04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_2:
L_80133A08:
    // 0x80133A08: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80133A0C:
    // 0x80133A0C: slti        $at, $s6, 0x4
    ctx->r1 = SIGNED(ctx->r22) < 0X4 ? 1 : 0;
    // 0x80133A10: bnel        $at, $zero, L_801339B8
    if (ctx->r1 != 0) {
        // 0x80133A14: lw          $t6, 0x6C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X6C);
            goto L_801339B8;
    }
    goto skip_3;
    // 0x80133A14: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    skip_3:
    // 0x80133A18: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80133A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133A20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133A24: bne         $t2, $zero, L_80133A34
    if (ctx->r10 != 0) {
        // 0x80133A28: lw          $s2, 0x20($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X20);
            goto L_80133A34;
    }
    // 0x80133A28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133A2C: b           L_80133A68
    // 0x80133A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133A68;
    // 0x80133A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133A34:
    // 0x80133A34: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80133A38: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80133A3C: bne         $t3, $zero, L_80133A4C
    if (ctx->r11 != 0) {
        // 0x80133A40: nop
    
            goto L_80133A4C;
    }
    // 0x80133A40: nop

    // 0x80133A44: b           L_80133A68
    // 0x80133A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133A68;
    // 0x80133A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133A4C:
    // 0x80133A4C: bne         $t4, $zero, L_80133A5C
    if (ctx->r12 != 0) {
        // 0x80133A50: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_80133A5C;
    }
    // 0x80133A50: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80133A54: b           L_80133A68
    // 0x80133A58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80133A68;
    // 0x80133A58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80133A5C:
    // 0x80133A5C: bnel        $t5, $zero, L_80133A6C
    if (ctx->r13 != 0) {
        // 0x80133A60: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80133A6C;
    }
    goto skip_4;
    // 0x80133A60: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80133A64: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80133A68:
    // 0x80133A68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133A6C:
    // 0x80133A6C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80133A70: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80133A74: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80133A78: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80133A7C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80133A80: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80133A84: jr          $ra
    // 0x80133A88: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80133A88: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void mvOpeningRoomMakePencils(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131F84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F90: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131F94: jal         0x80009968
    // 0x80131F98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F9C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131FA0: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131FA4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131FA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FAC: addiu       $t7, $t7, -0x5148
    ctx->r15 = ADD32(ctx->r15, -0X5148);
    // 0x80131FB0: sw          $v0, 0x4D24($at)
    MEM_W(0X4D24, ctx->r1) = ctx->r2;
    // 0x80131FB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131FB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131FC0: jal         0x8000F120
    // 0x80131FC4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131FC4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131FC8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131FCC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131FD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131FD4: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FDC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131FE0: jal         0x80009DF4
    // 0x80131FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131FE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131FEC: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80131FF0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131FF4: addiu       $t0, $t0, -0x5090
    ctx->r8 = ADD32(ctx->r8, -0X5090);
    // 0x80131FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132000: jal         0x8000BD8C
    // 0x80132004: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80132004: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80132008: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013200C: addiu       $a1, $a1, 0x1E88
    ctx->r5 = ADD32(ctx->r5, 0X1E88);
    // 0x80132010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132018: jal         0x80008188
    // 0x8013201C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8013201C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80132020: jal         0x8000DF34
    // 0x80132024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80132024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80132028: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013202C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132034: jr          $ra
    // 0x80132038: nop

    return;
    // 0x80132038: nop

;}
RECOMP_FUNC void ftCommonDeadInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C120: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013C128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013C12C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013C130: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x8013C134: jal         0x800D9444
    // 0x8013C138: sw          $t6, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r14;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_0;
    // 0x8013C138: sw          $t6, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r14;
    after_0:
    // 0x8013C13C: lbu         $t8, 0x18D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18D);
    // 0x8013C140: lbu         $t1, 0x191($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X191);
    // 0x8013C144: lbu         $t4, 0x18E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18E);
    // 0x8013C148: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013C14C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8013C150: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8013C154: sb          $t9, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r25;
    // 0x8013C158: sb          $t2, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r10;
    // 0x8013C15C: sb          $t5, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r13;
    // 0x8013C160: jal         0x801008F4
    // 0x8013C164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8013C164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8013C168: jal         0x8013BC8C
    // 0x8013C16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadUpdateRumble(rdram, ctx);
        goto after_2;
    // 0x8013C16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013C170: jal         0x8013BD64
    // 0x8013C174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadUpdateScore(rdram, ctx);
        goto after_3;
    // 0x8013C174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013C178: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013C17C: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013C180: lhu         $a0, 0xB4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB4);
    // 0x8013C184: beql        $a0, $at, L_8013C19C
    if (ctx->r4 == ctx->r1) {
        // 0x8013C188: lhu         $a0, 0xB6($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0XB6);
            goto L_8013C19C;
    }
    goto skip_0;
    // 0x8013C188: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
    skip_0:
    // 0x8013C18C: jal         0x8013BC60
    // 0x8013C190: nop

    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_4;
    // 0x8013C190: nop

    after_4:
    // 0x8013C194: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013C198: lhu         $a0, 0xB6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB6);
L_8013C19C:
    // 0x8013C19C: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013C1A0: beql        $a0, $at, L_8013C1B4
    if (ctx->r4 == ctx->r1) {
        // 0x8013C1A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C1B4;
    }
    goto skip_1;
    // 0x8013C1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013C1A8: jal         0x8013BC60
    // 0x8013C1AC: nop

    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_5;
    // 0x8013C1AC: nop

    after_5:
    // 0x8013C1B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C1B4:
    // 0x8013C1B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013C1B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013C1BC: jr          $ra
    // 0x8013C1C0: nop

    return;
    // 0x8013C1C0: nop

;}
RECOMP_FUNC void ftComputerFollowObjectivePatrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139D6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80139D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139D74: jal         0x8013837C
    // 0x80139D78: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_8013837C(rdram, ctx);
        goto after_0;
    // 0x80139D78: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80139D7C: beq         $v0, $zero, L_8013A280
    if (ctx->r2 == 0) {
        // 0x80139D80: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8013A280;
    }
    // 0x80139D80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139D84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139D88: beql        $v0, $at, L_8013A28C
    if (ctx->r2 == ctx->r1) {
        // 0x80139D8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013A28C;
    }
    goto skip_0;
    // 0x80139D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80139D90: jal         0x80018948
    // 0x80139D94: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80139D94: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x80139D98: jal         0x80018948
    // 0x80139D9C: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80139D9C: nop

    after_2:
    // 0x80139DA0: jal         0x80018948
    // 0x80139DA4: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x80139DA4: nop

    after_3:
    // 0x80139DA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139DAC: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80139DB0: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80139DB4: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139DB8: lwc1        $f2, 0x1C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80139DBC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80139DC0: nop

    // 0x80139DC4: bc1fl       L_80139DE0
    if (!c1cs) {
        // 0x80139DC8: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_80139DE0;
    }
    goto skip_1;
    // 0x80139DC8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x80139DCC: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80139DD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80139DD4: beq         $t7, $at, L_80139DFC
    if (ctx->r15 == ctx->r1) {
        // 0x80139DD8: nop
    
            goto L_80139DFC;
    }
    // 0x80139DD8: nop

    // 0x80139DDC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_80139DE0:
    // 0x80139DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80139DE4: bc1f        L_80139E04
    if (!c1cs) {
        // 0x80139DE8: nop
    
            goto L_80139E04;
    }
    // 0x80139DE8: nop

    // 0x80139DEC: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x80139DF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139DF4: bne         $t8, $at, L_80139E04
    if (ctx->r24 != ctx->r1) {
        // 0x80139DF8: nop
    
            goto L_80139E04;
    }
    // 0x80139DF8: nop

L_80139DFC:
    // 0x80139DFC: b           L_80139E04
    // 0x80139E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80139E04;
    // 0x80139E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80139E04:
    // 0x80139E04: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80139E08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139E0C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80139E10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139E14: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80139E18: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80139E1C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80139E20: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80139E24: nop

    // 0x80139E28: bc1fl       L_8013A0A8
    if (!c1cs) {
        // 0x80139E2C: sb          $zero, 0x34($v1)
        MEM_B(0X34, ctx->r3) = 0;
            goto L_8013A0A8;
    }
    goto skip_2;
    // 0x80139E2C: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    skip_2:
    // 0x80139E30: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139E34: jal         0x80138EE4
    // 0x80139E38: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_80138EE4(rdram, ctx);
        goto after_4;
    // 0x80139E38: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_4:
    // 0x80139E3C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139E40: beq         $v0, $zero, L_80139E50
    if (ctx->r2 == 0) {
        // 0x80139E44: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139E50;
    }
    // 0x80139E44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139E48: b           L_8013A288
    // 0x80139E4C: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_8013A288;
    // 0x80139E4C: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_80139E50:
    // 0x80139E50: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80139E54: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139E58: jal         0x80132EC8
    // 0x80139E5C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    ftComputerCheckDetectTarget(rdram, ctx);
        goto after_5;
    // 0x80139E5C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x80139E60: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139E64: beq         $v0, $zero, L_80139E78
    if (ctx->r2 == 0) {
        // 0x80139E68: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139E78;
    }
    // 0x80139E68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139E6C: sh          $zero, 0x20($v1)
    MEM_H(0X20, ctx->r3) = 0;
    // 0x80139E70: b           L_8013A288
    // 0x80139E74: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_8013A288;
    // 0x80139E74: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_80139E78:
    // 0x80139E78: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x80139E7C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80139E80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139E84: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x80139E88: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80139E8C: nop

    // 0x80139E90: bc1fl       L_80139F34
    if (!c1cs) {
        // 0x80139E94: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139F34;
    }
    goto skip_3;
    // 0x80139E94: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_3:
    // 0x80139E98: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139E9C: jal         0x80018948
    // 0x80139EA0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x80139EA0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_6:
    // 0x80139EA4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139EA8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80139EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139EB0: lbu         $t0, 0x13($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X13);
    // 0x80139EB4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139EB8: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80139EBC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80139EC0: nop

    // 0x80139EC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80139EC8: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80139ECC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80139ED0: nop

    // 0x80139ED4: bc1fl       L_80139F34
    if (!c1cs) {
        // 0x80139ED8: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139F34;
    }
    goto skip_4;
    // 0x80139ED8: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_4:
    // 0x80139EDC: lw          $t2, 0x6C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X6C);
    // 0x80139EE0: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80139EE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80139EE8: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x80139EEC: beq         $v0, $at, L_80139F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80139EF0: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80139F1C;
    }
    // 0x80139EF0: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80139EF4: beq         $v0, $at, L_80139F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80139EF8: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_80139F1C;
    }
    // 0x80139EF8: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80139EFC: beq         $v0, $at, L_80139F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80139F00: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_80139F1C;
    }
    // 0x80139F00: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80139F04: beq         $v0, $at, L_80139F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80139F08: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80139F1C;
    }
    // 0x80139F08: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80139F0C: beq         $v0, $at, L_80139F1C
    if (ctx->r2 == ctx->r1) {
        // 0x80139F10: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_80139F1C;
    }
    // 0x80139F10: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80139F14: bnel        $v0, $at, L_80139F34
    if (ctx->r2 != ctx->r1) {
        // 0x80139F18: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139F34;
    }
    goto skip_5;
    // 0x80139F18: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_5:
L_80139F1C:
    // 0x80139F1C: jal         0x80132758
    // 0x80139F20: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_7;
    // 0x80139F20: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_7:
    // 0x80139F24: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139F28: b           L_8013A288
    // 0x80139F2C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A288;
    // 0x80139F2C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139F30: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
L_80139F34:
    // 0x80139F34: lwc1        $f2, 0x64($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80139F38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139F3C: lwc1        $f0, 0x20($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80139F40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80139F44: nop

    // 0x80139F48: bc1fl       L_80139F60
    if (!c1cs) {
        // 0x80139F4C: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80139F60;
    }
    goto skip_6;
    // 0x80139F4C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_6:
    // 0x80139F50: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80139F54: b           L_80139F60
    // 0x80139F58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80139F60;
    // 0x80139F58: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80139F5C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_80139F60:
    // 0x80139F60: lwc1        $f18, -0x4094($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4094);
    // 0x80139F64: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80139F68: nop

    // 0x80139F6C: bc1t        L_80139F80
    if (c1cs) {
        // 0x80139F70: nop
    
            goto L_80139F80;
    }
    // 0x80139F70: nop

    // 0x80139F74: lhu         $t4, 0x20($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X20);
    // 0x80139F78: beql        $t4, $zero, L_80139FA8
    if (ctx->r12 == 0) {
        // 0x80139F7C: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_80139FA8;
    }
    goto skip_7;
    // 0x80139F7C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_7:
L_80139F80:
    // 0x80139F80: jal         0x80134E98
    // 0x80139F84: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_8;
    // 0x80139F84: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_8:
    // 0x80139F88: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139F8C: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x80139F90: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139F94: beq         $v0, $zero, L_8013A288
    if (ctx->r2 == 0) {
        // 0x80139F98: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_8013A288;
    }
    // 0x80139F98: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80139F9C: b           L_8013A288
    // 0x80139FA0: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
        goto L_8013A288;
    // 0x80139FA0: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    // 0x80139FA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_80139FA8:
    // 0x80139FA8: jal         0x80018948
    // 0x80139FAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x80139FAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_9:
    // 0x80139FB0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139FB4: lwc1        $f6, -0x4090($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4090);
    // 0x80139FB8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139FBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139FC0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80139FC4: nop

    // 0x80139FC8: bc1f        L_8013A094
    if (!c1cs) {
        // 0x80139FCC: nop
    
            goto L_8013A094;
    }
    // 0x80139FCC: nop

    // 0x80139FD0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139FD4: jal         0x80018948
    // 0x80139FD8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x80139FD8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_10:
    // 0x80139FDC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80139FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139FE4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80139FE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139FEC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80139FF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80139FF4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80139FF8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139FFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013A000: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8013A004: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8013A008: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8013A00C: nop

    // 0x8013A010: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8013A014: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8013A018: nop

    // 0x8013A01C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8013A020: beql        $t7, $zero, L_8013A070
    if (ctx->r15 == 0) {
        // 0x8013A024: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_8013A070;
    }
    goto skip_8;
    // 0x8013A024: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x8013A028: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013A02C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013A030: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8013A034: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8013A038: nop

    // 0x8013A03C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8013A040: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8013A044: nop

    // 0x8013A048: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8013A04C: bne         $t7, $zero, L_8013A064
    if (ctx->r15 != 0) {
        // 0x8013A050: nop
    
            goto L_8013A064;
    }
    // 0x8013A050: nop

    // 0x8013A054: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8013A058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A05C: b           L_8013A07C
    // 0x8013A060: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8013A07C;
    // 0x8013A060: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8013A064:
    // 0x8013A064: b           L_8013A07C
    // 0x8013A068: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8013A07C;
    // 0x8013A068: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013A06C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_8013A070:
    // 0x8013A070: nop

    // 0x8013A074: bltz        $t7, L_8013A064
    if (SIGNED(ctx->r15) < 0) {
        // 0x8013A078: nop
    
            goto L_8013A064;
    }
    // 0x8013A078: nop

L_8013A07C:
    // 0x8013A07C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8013A080: jal         0x80134E98
    // 0x8013A084: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_11;
    // 0x8013A084: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    after_11:
    // 0x8013A088: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A08C: b           L_8013A288
    // 0x8013A090: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A288;
    // 0x8013A090: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A094:
    // 0x8013A094: jal         0x8013877C
    // 0x8013A098: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_12;
    // 0x8013A098: nop

    after_12:
    // 0x8013A09C: b           L_8013A28C
    // 0x8013A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A28C;
    // 0x8013A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013A0A4: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
L_8013A0A8:
    // 0x8013A0A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8013A0AC: jal         0x80138AA8
    // 0x8013A0B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_ovl3_80138AA8(rdram, ctx);
        goto after_13;
    // 0x8013A0B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_13:
    // 0x8013A0B4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A0B8: beq         $v0, $zero, L_8013A0C8
    if (ctx->r2 == 0) {
        // 0x8013A0BC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8013A0C8;
    }
    // 0x8013A0BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013A0C0: b           L_8013A288
    // 0x8013A0C4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A288;
    // 0x8013A0C4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A0C8:
    // 0x8013A0C8: lw          $t8, 0x5B4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5B4);
    // 0x8013A0CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013A0D0: beq         $t8, $at, L_8013A0F8
    if (ctx->r24 == ctx->r1) {
        // 0x8013A0D4: nop
    
            goto L_8013A0F8;
    }
    // 0x8013A0D4: nop

    // 0x8013A0D8: lw          $v0, 0x84C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84C);
    // 0x8013A0DC: beql        $v0, $zero, L_8013A110
    if (ctx->r2 == 0) {
        // 0x8013A0E0: lw          $t1, 0x8E8($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X8E8);
            goto L_8013A110;
    }
    goto skip_9;
    // 0x8013A0E0: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
    skip_9:
    // 0x8013A0E4: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x8013A0E8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8013A0EC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8013A0F0: bnel        $t0, $at, L_8013A110
    if (ctx->r8 != ctx->r1) {
        // 0x8013A0F4: lw          $t1, 0x8E8($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X8E8);
            goto L_8013A110;
    }
    goto skip_10;
    // 0x8013A0F4: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
    skip_10:
L_8013A0F8:
    // 0x8013A0F8: jal         0x80134E98
    // 0x8013A0FC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_14;
    // 0x8013A0FC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_14:
    // 0x8013A100: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A104: b           L_8013A288
    // 0x8013A108: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A288;
    // 0x8013A108: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x8013A10C: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
L_8013A110:
    // 0x8013A110: lwc1        $f2, 0x64($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X64);
    // 0x8013A114: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013A118: lwc1        $f0, 0x20($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8013A11C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8013A120: nop

    // 0x8013A124: bc1fl       L_8013A13C
    if (!c1cs) {
        // 0x8013A128: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8013A13C;
    }
    goto skip_11;
    // 0x8013A128: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_11:
    // 0x8013A12C: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8013A130: b           L_8013A13C
    // 0x8013A134: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8013A13C;
    // 0x8013A134: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8013A138: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_8013A13C:
    // 0x8013A13C: lwc1        $f6, -0x408C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X408C);
    // 0x8013A140: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8013A144: nop

    // 0x8013A148: bc1t        L_8013A15C
    if (c1cs) {
        // 0x8013A14C: nop
    
            goto L_8013A15C;
    }
    // 0x8013A14C: nop

    // 0x8013A150: lhu         $t2, 0x20($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X20);
    // 0x8013A154: beql        $t2, $zero, L_8013A184
    if (ctx->r10 == 0) {
        // 0x8013A158: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_8013A184;
    }
    goto skip_12;
    // 0x8013A158: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_12:
L_8013A15C:
    // 0x8013A15C: jal         0x80134E98
    // 0x8013A160: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_15;
    // 0x8013A160: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_15:
    // 0x8013A164: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A168: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x8013A16C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x8013A170: beq         $v0, $zero, L_8013A288
    if (ctx->r2 == 0) {
        // 0x8013A174: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8013A288;
    }
    // 0x8013A174: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8013A178: b           L_8013A288
    // 0x8013A17C: sh          $t3, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r11;
        goto L_8013A288;
    // 0x8013A17C: sh          $t3, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r11;
    // 0x8013A180: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_8013A184:
    // 0x8013A184: jal         0x80018948
    // 0x8013A188: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_16;
    // 0x8013A188: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_16:
    // 0x8013A18C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013A190: lwc1        $f8, -0x4088($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4088);
    // 0x8013A194: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A198: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013A19C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8013A1A0: nop

    // 0x8013A1A4: bc1f        L_8013A270
    if (!c1cs) {
        // 0x8013A1A8: nop
    
            goto L_8013A270;
    }
    // 0x8013A1A8: nop

    // 0x8013A1AC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8013A1B0: jal         0x80018948
    // 0x8013A1B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_17;
    // 0x8013A1B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_17:
    // 0x8013A1B8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8013A1BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013A1C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8013A1C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013A1C8: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8013A1CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013A1D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013A1D4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A1D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013A1DC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8013A1E0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8013A1E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8013A1E8: nop

    // 0x8013A1EC: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8013A1F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8013A1F4: nop

    // 0x8013A1F8: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8013A1FC: beql        $t5, $zero, L_8013A24C
    if (ctx->r13 == 0) {
        // 0x8013A200: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_8013A24C;
    }
    goto skip_13;
    // 0x8013A200: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_13:
    // 0x8013A204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013A208: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013A20C: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8013A210: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8013A214: nop

    // 0x8013A218: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8013A21C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8013A220: nop

    // 0x8013A224: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8013A228: bne         $t5, $zero, L_8013A240
    if (ctx->r13 != 0) {
        // 0x8013A22C: nop
    
            goto L_8013A240;
    }
    // 0x8013A22C: nop

    // 0x8013A230: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8013A234: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013A238: b           L_8013A258
    // 0x8013A23C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8013A258;
    // 0x8013A23C: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8013A240:
    // 0x8013A240: b           L_8013A258
    // 0x8013A244: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8013A258;
    // 0x8013A244: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8013A248: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_8013A24C:
    // 0x8013A24C: nop

    // 0x8013A250: bltz        $t5, L_8013A240
    if (SIGNED(ctx->r13) < 0) {
        // 0x8013A254: nop
    
            goto L_8013A240;
    }
    // 0x8013A254: nop

L_8013A258:
    // 0x8013A258: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8013A25C: jal         0x80134E98
    // 0x8013A260: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_18;
    // 0x8013A260: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    after_18:
    // 0x8013A264: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013A268: b           L_8013A288
    // 0x8013A26C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A288;
    // 0x8013A26C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A270:
    // 0x8013A270: jal         0x8013877C
    // 0x8013A274: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    func_ovl3_8013877C(rdram, ctx);
        goto after_19;
    // 0x8013A274: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    after_19:
    // 0x8013A278: b           L_8013A28C
    // 0x8013A27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A28C;
    // 0x8013A27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A280:
    // 0x8013A280: jal         0x8013877C
    // 0x8013A284: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_20;
    // 0x8013A284: nop

    after_20:
L_8013A288:
    // 0x8013A288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A28C:
    // 0x8013A28C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013A290: jr          $ra
    // 0x8013A294: nop

    return;
    // 0x8013A294: nop

;}
RECOMP_FUNC void mvOpeningLinkFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD80: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DD84: addiu       $v0, $v0, -0x1E38
    ctx->r2 = ADD32(ctx->r2, -0X1E38);
    // 0x8018DD88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DD8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DD90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DD94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DD98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DD9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDA0: jal         0x8039076C
    // 0x8018DDA4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDA4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDA8: beq         $v0, $zero, L_8018DDC8
    if (ctx->r2 == 0) {
        // 0x8018DDAC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DDC8;
    }
    // 0x8018DDAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDB0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDB4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDB8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDBC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DDC0: jal         0x80005C74
    // 0x8018DDC4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DDC4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DDC8:
    // 0x8018DDC8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDCC: lw          $v0, -0x1E38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E38);
    // 0x8018DDD0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DDD4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDD8: bnel        $v0, $at, L_8018DE0C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DDDC: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE0C;
    }
    goto skip_0;
    // 0x8018DDDC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DDE0: jal         0x80009A84
    // 0x8018DDE4: lw          $a0, -0x1E34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E34);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DDE4: lw          $a0, -0x1E34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E34);
    after_2:
    // 0x8018DDE8: jal         0x8018D5F4
    // 0x8018DDEC: nop

    mvOpeningLinkMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DDEC: nop

    after_3:
    // 0x8018DDF0: jal         0x8018D924
    // 0x8018DDF4: nop

    mvOpeningLinkMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DDF4: nop

    after_4:
    // 0x8018DDF8: jal         0x8018DA40
    // 0x8018DDFC: nop

    mvOpeningLinkMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DDFC: nop

    after_5:
    // 0x8018DE00: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE04: lw          $v0, -0x1E38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E38);
    // 0x8018DE08: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE0C:
    // 0x8018DE0C: bne         $v0, $at, L_8018DE2C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE10: addiu       $t1, $zero, 0x20
        ctx->r9 = ADD32(0, 0X20);
            goto L_8018DE2C;
    }
    // 0x8018DE10: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8018DE14: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE18: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE1C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE20: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE24: jal         0x80005C74
    // 0x8018DE28: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE28: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE2C:
    // 0x8018DE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE34: jr          $ra
    // 0x8018DE38: nop

    return;
    // 0x8018DE38: nop

;}
RECOMP_FUNC void ftBossDefaultSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80158788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015878C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80158790: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x80158794: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80158798: jal         0x800E6F24
    // 0x8015879C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015879C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801587A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801587A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801587A8: jr          $ra
    // 0x801587AC: nop

    return;
    // 0x801587AC: nop

;}
RECOMP_FUNC void scExplainUpdateTextBoxSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD18: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DD1C: addiu       $v1, $v1, -0x1618
    ctx->r3 = ADD32(ctx->r3, -0X1618);
    // 0x8018DD20: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018DD24: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DD28: addiu       $v0, $v0, -0x1610
    ctx->r2 = ADD32(ctx->r2, -0X1610);
    // 0x8018DD2C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8018DD30: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DD34: addiu       $t1, $t8, 0x3C
    ctx->r9 = ADD32(ctx->r24, 0X3C);
L_8018DD38:
    // 0x8018DD38: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018DD3C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018DD40: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DD44: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018DD48: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8018DD4C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018DD50: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x8018DD54: bne         $t8, $t1, L_8018DD38
    if (ctx->r24 != ctx->r9) {
        // 0x8018DD58: sw          $t0, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->r8;
            goto L_8018DD38;
    }
    // 0x8018DD58: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8018DD5C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018DD60: sw          $t0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r8;
    // 0x8018DD64: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8018DD68: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x8018DD6C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018DD70: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8018DD74: addiu       $t9, $zero, 0x201
    ctx->r25 = ADD32(0, 0X201);
    // 0x8018DD78: lbu         $t3, 0x4($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X4);
    // 0x8018DD7C: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8018DD80: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018DD84: nop

    // 0x8018DD88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DD8C: swc1        $f6, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f6.u32l;
    // 0x8018DD90: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018DD94: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DD98: lbu         $t1, 0x5($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X5);
    // 0x8018DD9C: addiu       $t8, $t1, 0xA0
    ctx->r24 = ADD32(ctx->r9, 0XA0);
    // 0x8018DDA0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8018DDA4: nop

    // 0x8018DDA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DDAC: swc1        $f10, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f10.u32l;
    // 0x8018DDB0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDB4: jr          $ra
    // 0x8018DDB8: sh          $t9, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r25;
    return;
    // 0x8018DDB8: sh          $t9, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void mnPlayers1PGameGetBonusCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134968: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x8013496C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134970: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80134974: jr          $ra
    // 0x80134978: lw          $v0, 0x4944($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4944);
    return;
    // 0x80134978: lw          $v0, 0x4944($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4944);
;}
RECOMP_FUNC void func_ovl8_8037FC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FC1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037FC20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037FC24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037FC28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037FC2C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8037FC30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037FC34: bne         $a0, $zero, L_8037FC4C
    if (ctx->r4 != 0) {
        // 0x8037FC38: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037FC4C;
    }
    // 0x8037FC38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037FC3C: jal         0x803717A0
    // 0x8037FC40: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037FC40: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x8037FC44: beq         $v0, $zero, L_8037FCC0
    if (ctx->r2 == 0) {
        // 0x8037FC48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037FCC0;
    }
    // 0x8037FC48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037FC4C:
    // 0x8037FC4C: bne         $s1, $zero, L_8037FC70
    if (ctx->r17 != 0) {
        // 0x8037FC50: addiu       $a0, $s0, 0x60
        ctx->r4 = ADD32(ctx->r16, 0X60);
            goto L_8037FC70;
    }
    // 0x8037FC50: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x8037FC54: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    // 0x8037FC58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037FC5C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8037FC60: jal         0x803717E0
    // 0x8037FC64: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037FC64: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_1:
    // 0x8037FC68: jal         0x8037C2D0
    // 0x8037FC6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037FC6C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_8037FC70:
    // 0x8037FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FC74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037FC78: jal         0x8037F300
    // 0x8037FC7C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037F300(rdram, ctx);
        goto after_3;
    // 0x8037FC7C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037FC80: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037FC84: jal         0x80372430
    // 0x8037FC88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_80372430(rdram, ctx);
        goto after_4;
    // 0x8037FC88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8037FC8C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037FC90: addiu       $t6, $t6, -0x4E60
    ctx->r14 = ADD32(ctx->r14, -0X4E60);
    // 0x8037FC94: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037FC98: addiu       $t7, $t7, -0x4D78
    ctx->r15 = ADD32(ctx->r15, -0X4D78);
    // 0x8037FC9C: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x8037FCA0: sw          $t7, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r15;
    // 0x8037FCA4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8037FCA8: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037FCAC: addiu       $t8, $t8, -0x4C20
    ctx->r24 = ADD32(ctx->r24, -0X4C20);
    // 0x8037FCB0: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037FCB4: addiu       $t0, $t0, -0x4BF8
    ctx->r8 = ADD32(ctx->r8, -0X4BF8);
    // 0x8037FCB8: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8037FCBC: sw          $t0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r8;
L_8037FCC0:
    // 0x8037FCC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037FCC4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037FCC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037FCCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037FCD0: jr          $ra
    // 0x8037FCD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037FCD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningRoomCloseUpOverlayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132BBC: addiu       $v0, $v0, 0x4D38
    ctx->r2 = ADD32(ctx->r2, 0X4D38);
    // 0x80132BC0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80132BC4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80132BC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132BCC: slti        $at, $v1, 0xA0
    ctx->r1 = SIGNED(ctx->r3) < 0XA0 ? 1 : 0;
    // 0x80132BD0: beq         $at, $zero, L_80132BF0
    if (ctx->r1 == 0) {
        // 0x80132BD4: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80132BF0;
    }
    // 0x80132BD4: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132BD8: addiu       $t6, $v1, 0x9
    ctx->r14 = ADD32(ctx->r3, 0X9);
    // 0x80132BDC: slti        $at, $t6, 0xA1
    ctx->r1 = SIGNED(ctx->r14) < 0XA1 ? 1 : 0;
    // 0x80132BE0: bne         $at, $zero, L_80132BF0
    if (ctx->r1 != 0) {
        // 0x80132BE4: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_80132BF0;
    }
    // 0x80132BE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132BE8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80132BEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80132BF0:
    // 0x80132BF0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132BF4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132BF8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80132BFC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132C00: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80132C04: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132C08: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132C0C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132C10: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80132C14: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132C18: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132C1C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132C20: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132C24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132C28: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132C2C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80132C30: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132C34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132C38: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132C3C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80132C40: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80132C44: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80132C48: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80132C4C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132C50: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80132C54: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80132C58: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80132C5C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132C60: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80132C64: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132C68: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132C6C: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80132C70: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132C74: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80132C78: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80132C7C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132C80: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x80132C84: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132C88: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80132C8C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132C90: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80132C94: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132C98: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132C9C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132CA0: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x80132CA4: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80132CA8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80132CAC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132CB0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132CB4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132CB8: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132CBC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132CC0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80132CC4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132CC8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132CCC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132CD0: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80132CD4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132CD8: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132CDC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132CE0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80132CE4: jr          $ra
    // 0x80132CE8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x80132CE8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void gcSetSObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800080B4: addiu       $v0, $v0, 0x6A3C
    ctx->r2 = ADD32(ctx->r2, 0X6A3C);
    // 0x800080B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800080BC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800080C0: addiu       $v1, $v1, 0x6A40
    ctx->r3 = ADD32(ctx->r3, 0X6A40);
    // 0x800080C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800080C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800080CC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800080D0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800080D4: jr          $ra
    // 0x800080D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x800080D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void sc1PTrainingModeMakeItemDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EA88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018EA8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018EA90: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EA94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EA98: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018EA9C: jal         0x80009968
    // 0x8018EAA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018EAA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018EAA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EAA8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EAAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018EAB0: sw          $v0, 0xBA4($at)
    MEM_W(0XBA4, ctx->r1) = ctx->r2;
    // 0x8018EAB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018EAB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EABC: addiu       $a1, $a1, -0x1654
    ctx->r5 = ADD32(ctx->r5, -0X1654);
    // 0x8018EAC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EAC4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018EAC8: jal         0x80009DF4
    // 0x8018EACC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018EACC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018EAD0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018EAD4: lw          $t7, 0xB80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XB80);
    // 0x8018EAD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018EADC: jal         0x800CCFDC
    // 0x8018EAE0: lw          $a1, 0x94($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X94);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018EAE0: lw          $a1, 0x94($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X94);
    after_2:
    // 0x8018EAE4: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x8018EAE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018EAEC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8018EAF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EAF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EAF8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018EAFC: jal         0x8018E300
    // 0x8018EB00: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_3;
    // 0x8018EB00: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018EB04: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018EB08: lw          $t8, 0xB80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XB80);
    // 0x8018EB0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018EB10: jal         0x800CCFDC
    // 0x8018EB14: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8018EB14: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_4:
    // 0x8018EB18: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8018EB1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EB20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EB24: jal         0x8018E300
    // 0x8018EB28: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_5;
    // 0x8018EB28: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    after_5:
    // 0x8018EB2C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018EB30: lw          $t9, 0xB80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XB80);
    // 0x8018EB34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018EB38: jal         0x800CCFDC
    // 0x8018EB3C: lw          $a1, 0x90($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X90);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8018EB3C: lw          $a1, 0x90($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X90);
    after_6:
    // 0x8018EB40: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8018EB44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EB48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EB4C: jal         0x8018E300
    // 0x8018EB50: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_7;
    // 0x8018EB50: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_7:
    // 0x8018EB54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EB58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018EB5C: jr          $ra
    // 0x8018EB60: nop

    return;
    // 0x8018EB60: nop

;}
RECOMP_FUNC void func_ovl61_80131D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D54: jr          $ra
    // 0x80131D58: nop

    return;
    // 0x80131D58: nop

;}
RECOMP_FUNC void ftDisplayLightsDrawReflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCB70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FCB74: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800FCB78: lwc1        $f4, 0x910($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X910);
    // 0x800FCB7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800FCB80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FCB84: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800FCB88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FCB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCB90: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FCB94: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800FCB98: div.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FCB9C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800FCBA0: jal         0x800C7840
    // 0x800FCBA4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_0;
    // 0x800FCBA4: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800FCBA8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800FCBAC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FCBB0: jal         0x800C78B8
    // 0x800FCBB4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    lbCommonCos(rdram, ctx);
        goto after_1;
    // 0x800FCBB4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800FCBB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FCBBC: lwc1        $f18, 0x914($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X914);
    // 0x800FCBC0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FCBC4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800FCBC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FCBCC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800FCBD0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800FCBD4: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800FCBD8: jal         0x800C7840
    // 0x800FCBDC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x800FCBDC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x800FCBE0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800FCBE4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FCBE8: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FCBEC: jal         0x800C78B8
    // 0x800FCBF0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x800FCBF0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800FCBF4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800FCBF8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800FCBFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800FCC00: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800FCC04: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FCC08: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FCC0C: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x800FCC10: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800FCC14: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800FCC18: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800FCC1C: lui         $t6, 0xDB02
    ctx->r14 = S32(0XDB02 << 16);
    // 0x800FCC20: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x800FCC24: ori         $t9, $t9, 0x60A
    ctx->r25 = ctx->r25 | 0X60A;
    // 0x800FCC28: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800FCC2C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800FCC30: nop

    // 0x800FCC34: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x800FCC38: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800FCC3C: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x800FCC40: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x800FCC44: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800FCC48: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800FCC4C: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800FCC50: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800FCC54: nop

    // 0x800FCC58: sb          $t0, 0x9($t1)
    MEM_B(0X9, ctx->r9) = ctx->r8;
    // 0x800FCC5C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800FCC60: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800FCC64: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800FCC68: nop

    // 0x800FCC6C: sb          $t3, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r11;
    // 0x800FCC70: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800FCC74: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800FCC78: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800FCC7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800FCC80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800FCC84: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800FCC88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FCC8C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800FCC90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FCC94: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x800FCC98: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800FCC9C: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x800FCCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCCA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FCCA8: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800FCCAC: jr          $ra
    // 0x800FCCB0: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    return;
    // 0x800FCCB0: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void sySchedulerSoftReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800029DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800029E0: sw          $t6, 0x5020($at)
    MEM_W(0X5020, ctx->r1) = ctx->r14;
    // 0x800029E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800029E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800029EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800029F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800029F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800029F8: jal         0x800392E0
    // 0x800029FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    osViSetYScale_recomp(rdram, ctx);
        goto after_0;
    // 0x800029FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80002A00: jal         0x80032860
    // 0x80002A04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80002A04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80002A08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80002A0C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80002A10:
    // 0x80002A10: jal         0x800044B4
    // 0x80002A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerInitRumble(rdram, ctx);
        goto after_2;
    // 0x80002A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80002A18: jal         0x80004494
    // 0x80002A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_3;
    // 0x80002A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80002A20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80002A24: bne         $s0, $s1, L_80002A10
    if (ctx->r16 != ctx->r17) {
        // 0x80002A28: nop
    
            goto L_80002A10;
    }
    // 0x80002A28: nop

    // 0x80002A2C: jal         0x80033520
    // 0x80002A30: nop

    osAfterPreNMI(rdram, ctx);
        goto after_4;
    // 0x80002A30: nop

    after_4:
    // 0x80002A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002A38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002A3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80002A40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002A44: sw          $v0, 0x5024($at)
    MEM_W(0X5024, ctx->r1) = ctx->r2;
    // 0x80002A48: jr          $ra
    // 0x80002A4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80002A4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonLiftTurnProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801461E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801461EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801461F0: jal         0x80146BE0
    // 0x801461F4: nop

    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x801461F4: nop

    after_0:
    // 0x801461F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801461FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146200: jr          $ra
    // 0x80146204: nop

    return;
    // 0x80146204: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134274: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134278: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8013427C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80134280: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134284: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x80134288: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8013428C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80134290: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134294: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134298: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013429C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801342A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801342A4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801342A8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801342AC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801342B0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801342B4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801342B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801342BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801342C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801342C4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801342C8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801342CC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801342D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801342D4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801342D8: jal         0x8000B93C
    // 0x801342DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801342DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801342E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801342E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801342E8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801342EC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801342F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801342F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801342F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801342FC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134300: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134304: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80134308: jal         0x80007080
    // 0x8013430C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013430C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134310: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80134314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013431C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80134320: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80134324: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80134328: lwc1        $f6, 0x7634($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7634);
    // 0x8013432C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134330: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134334: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x80134338: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8013433C: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80134340: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80134344: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80134348: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8013434C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80134350: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80134354: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134358: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013435C: jr          $ra
    // 0x80134360: nop

    return;
    // 0x80134360: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015C754: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015C758: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015C75C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015C760: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8015C764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8015C768: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015C76C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015C770: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C774: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015C778: bc1fl       L_8015C798
    if (!c1cs) {
        // 0x8015C77C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015C798;
    }
    goto skip_0;
    // 0x8015C77C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8015C780: lwc1        $f8, -0x3764($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3764);
    // 0x8015C784: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015C788: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015C78C: jal         0x801438F0
    // 0x8015C790: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    ftCommonFallSpecialSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015C790: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8015C794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015C798:
    // 0x8015C798: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015C79C: jr          $ra
    // 0x8015C7A0: nop

    return;
    // 0x8015C7A0: nop

;}
RECOMP_FUNC void sc1PStageClearFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void ftCommonShieldBreakStandProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801497A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801497A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801497A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801497AC: jal         0x800D9480
    // 0x801497B0: addiu       $a1, $a1, -0x675C
    ctx->r5 = ADD32(ctx->r5, -0X675C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801497B0: addiu       $a1, $a1, -0x675C
    ctx->r5 = ADD32(ctx->r5, -0X675C);
    after_0:
    // 0x801497B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801497B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801497BC: jr          $ra
    // 0x801497C0: nop

    return;
    // 0x801497C0: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F208: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F20C: jal         0x8015F1AC
    // 0x8015F210: addiu       $a1, $a1, -0x898
    ctx->r5 = ADD32(ctx->r5, -0X898);
    ftKirbyCopyYoshiSpecialNCatchUpdateProcStatus(rdram, ctx);
        goto after_0;
    // 0x8015F210: addiu       $a1, $a1, -0x898
    ctx->r5 = ADD32(ctx->r5, -0X898);
    after_0:
    // 0x8015F214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F21C: jr          $ra
    // 0x8015F220: nop

    return;
    // 0x8015F220: nop

;}
RECOMP_FUNC void wpLinkBoomerangClampAngle360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CC50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CC54: lwc1        $f2, -0x3490($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3490);
    // 0x8016CC58: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8016CC5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CC60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016CC64: nop

    // 0x8016CC68: bc1f        L_8016CC7C
    if (!c1cs) {
        // 0x8016CC6C: nop
    
            goto L_8016CC7C;
    }
    // 0x8016CC6C: nop

    // 0x8016CC70: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8016CC74: jr          $ra
    // 0x8016CC78: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8016CC78: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_8016CC7C:
    // 0x8016CC7C: lwc1        $f6, -0x348C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X348C);
    // 0x8016CC80: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8016CC84: nop

    // 0x8016CC88: bc1f        L_8016CC98
    if (!c1cs) {
        // 0x8016CC8C: nop
    
            goto L_8016CC98;
    }
    // 0x8016CC8C: nop

    // 0x8016CC90: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8016CC94: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_8016CC98:
    // 0x8016CC98: jr          $ra
    // 0x8016CC9C: nop

    return;
    // 0x8016CC9C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeReadyCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D08: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135D0C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135D10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135D14: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135D18: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80135D1C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80135D20: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80135D24: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135D28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135D2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135D30: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135D34: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135D38: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135D3C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135D40: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135D44: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135D48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135D4C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135D50: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135D54: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135D58: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80135D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135D60: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80135D64: jal         0x8000B93C
    // 0x80135D68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135D68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135D6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135D70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135D74: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135D78: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135D80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135D84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135D88: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135D8C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135D90: jal         0x80007080
    // 0x80135D94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135D94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135D98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135D9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135DA0: jr          $ra
    // 0x80135DA4: nop

    return;
    // 0x80135DA4: nop

;}
RECOMP_FUNC void ftDonkeySpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B74C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015B750: lui         $a2, 0x3CCC
    ctx->r6 = S32(0X3CCC << 16);
    // 0x8015B754: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B758: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8015B75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015B760: jal         0x800D89E0
    // 0x8015B764: lui         $a3, 0x41D0
    ctx->r7 = S32(0X41D0 << 16);
    ftPhysicsApplyClampGroundVelStickRange(rdram, ctx);
        goto after_0;
    // 0x8015B764: lui         $a3, 0x41D0
    ctx->r7 = S32(0X41D0 << 16);
    after_0:
    // 0x8015B768: jal         0x800D87D0
    // 0x8015B76C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8015B76C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015B770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B778: jr          $ra
    // 0x8015B77C: nop

    return;
    // 0x8015B77C: nop

;}
RECOMP_FUNC void ftCommonSquatProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142EFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80142F00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142F04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80142F08: jal         0x80151098
    // 0x80142F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80142F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80142F10: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_0;
    // 0x80142F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80142F18: jal         0x80151160
    // 0x80142F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80142F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80142F20: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_1;
    // 0x80142F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80142F28: jal         0x801511E0
    // 0x80142F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80142F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80142F30: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_2;
    // 0x80142F34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80142F38: jal         0x80149CE0
    // 0x80142F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x80142F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80142F40: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_3;
    // 0x80142F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80142F48: jal         0x80150470
    // 0x80142F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x80142F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80142F50: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_4;
    // 0x80142F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80142F58: jal         0x8015070C
    // 0x80142F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x80142F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80142F60: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_5;
    // 0x80142F64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80142F68: jal         0x80150838
    // 0x80142F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptSquat(rdram, ctx);
        goto after_6;
    // 0x80142F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80142F70: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_6;
    // 0x80142F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80142F78: jal         0x8014F8C0
    // 0x80142F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x80142F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80142F80: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_7;
    // 0x80142F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80142F88: jal         0x8014FB1C
    // 0x80142F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x80142F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80142F90: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142F94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_8;
    // 0x80142F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80142F98: jal         0x8014FD70
    // 0x80142F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x80142F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80142FA0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_9;
    // 0x80142FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80142FA8: jal         0x8014EC78
    // 0x80142FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x80142FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80142FB0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_10;
    // 0x80142FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80142FB8: jal         0x80148D0C
    // 0x80142FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x80142FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80142FC0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_11;
    // 0x80142FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80142FC8: jal         0x8014E764
    // 0x80142FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x80142FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80142FD0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_12;
    // 0x80142FD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80142FD8: jal         0x8013F4D0
    // 0x80142FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x80142FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80142FE0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_13;
    // 0x80142FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80142FE8: jal         0x80141F0C
    // 0x80142FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptSquat(rdram, ctx);
        goto after_14;
    // 0x80142FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80142FF0: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80142FF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_14;
    // 0x80142FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80142FF8: jal         0x80142258
    // 0x80142FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x80142FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80143000: bnel        $v0, $zero, L_80143014
    if (ctx->r2 != 0) {
        // 0x80143004: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143014;
    }
    goto skip_15;
    // 0x80143004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80143008: jal         0x80142E70
    // 0x8014300C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckGotoPass(rdram, ctx);
        goto after_16;
    // 0x8014300C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80143010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80143014:
    // 0x80143014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80143018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014301C: jr          $ra
    // 0x80143020: nop

    return;
    // 0x80143020: nop

;}
RECOMP_FUNC void mnPlayers1PGameInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801381D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801381DC: addiu       $v1, $v1, -0x708C
    ctx->r3 = ADD32(ctx->r3, -0X708C);
    // 0x801381E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801381E4: addiu       $t7, $zero, 0x4650
    ctx->r15 = ADD32(0, 0X4650);
    // 0x801381E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801381EC: sw          $t7, -0x7088($at)
    MEM_W(-0X7088, ctx->r1) = ctx->r15;
    // 0x801381F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801381F4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801381F8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801381FC: sw          $zero, -0x7064($at)
    MEM_W(-0X7064, ctx->r1) = 0;
    // 0x80138200: lbu         $t8, 0x16($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X16);
    // 0x80138204: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138208: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8013820C: sw          $t8, -0x7080($at)
    MEM_W(-0X7080, ctx->r1) = ctx->r24;
    // 0x80138210: lbu         $t9, 0x13($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X13);
    // 0x80138214: addiu       $a2, $a2, 0x44E0
    ctx->r6 = ADD32(ctx->r6, 0X44E0);
    // 0x80138218: lbu         $t0, 0x45A($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X45A);
    // 0x8013821C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80138220: addiu       $a1, $a1, -0x7058
    ctx->r5 = ADD32(ctx->r5, -0X7058);
    // 0x80138224: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138228: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8013822C: sw          $t0, -0x704C($at)
    MEM_W(-0X704C, ctx->r1) = ctx->r8;
    // 0x80138230: lbu         $t1, 0x45B($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X45B);
    // 0x80138234: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138238: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8013823C: sw          $t1, -0x7048($at)
    MEM_W(-0X7048, ctx->r1) = ctx->r9;
    // 0x80138240: lbu         $t2, 0x14($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X14);
    // 0x80138244: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138248: addiu       $a3, $a3, 0x4B18
    ctx->r7 = ADD32(ctx->r7, 0X4B18);
    // 0x8013824C: sw          $t2, -0x7034($at)
    MEM_W(-0X7034, ctx->r1) = ctx->r10;
    // 0x80138250: lbu         $t3, 0x15($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X15);
    // 0x80138254: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013825C: sw          $t3, -0x7030($at)
    MEM_W(-0X7030, ctx->r1) = ctx->r11;
    // 0x80138260: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138264: sw          $zero, -0x7054($at)
    MEM_W(-0X7054, ctx->r1) = 0;
    // 0x80138268: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013826C: sw          $zero, -0x7050($at)
    MEM_W(-0X7050, ctx->r1) = 0;
    // 0x80138270: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138274: sw          $zero, -0x7044($at)
    MEM_W(-0X7044, ctx->r1) = 0;
    // 0x80138278: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013827C: sw          $zero, -0x7040($at)
    MEM_W(-0X7040, ctx->r1) = 0;
    // 0x80138280: lbu         $t4, 0x2($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2);
    // 0x80138284: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013828C: sw          $t4, -0x7060($at)
    MEM_W(-0X7060, ctx->r1) = ctx->r12;
    // 0x80138290: lbu         $t5, 0x3($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X3);
    // 0x80138294: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138298: sw          $t5, -0x705C($at)
    MEM_W(-0X705C, ctx->r1) = ctx->r13;
    // 0x8013829C: jal         0x80138150
    // 0x801382A0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    mnPlayers1PGameInitPlayer(rdram, ctx);
        goto after_0;
    // 0x801382A0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x801382A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801382A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801382AC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801382B0: lhu         $t6, 0x4938($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4938);
    // 0x801382B4: sw          $zero, -0x70E4($at)
    MEM_W(-0X70E4, ctx->r1) = 0;
    // 0x801382B8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801382BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801382C0: jr          $ra
    // 0x801382C4: sh          $t6, -0x7038($at)
    MEM_H(-0X7038, ctx->r1) = ctx->r14;
    return;
    // 0x801382C4: sh          $t6, -0x7038($at)
    MEM_H(-0X7038, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void sc1PChallengerFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132118: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013211C: addiu       $v0, $v0, 0x2498
    ctx->r2 = ADD32(ctx->r2, 0X2498);
    // 0x80132120: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013212C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132130: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x80132134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132138: bne         $at, $zero, L_801321B0
    if (ctx->r1 != 0) {
        // 0x8013213C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801321B0;
    }
    // 0x8013213C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132140: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132144: addiu       $v1, $v1, 0x2494
    ctx->r3 = ADD32(ctx->r3, 0X2494);
    // 0x80132148: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013214C: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80132150: beq         $v0, $zero, L_8013215C
    if (ctx->r2 == 0) {
        // 0x80132154: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8013215C;
    }
    // 0x80132154: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132158: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8013215C:
    // 0x8013215C: jal         0x80390A04
    // 0x80132160: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132160: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x80132164: beq         $v0, $zero, L_80132180
    if (ctx->r2 == 0) {
        // 0x80132168: addiu       $a0, $zero, -0x1E
        ctx->r4 = ADD32(0, -0X1E);
            goto L_80132180;
    }
    // 0x80132168: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x8013216C: jal         0x80390AC0
    // 0x80132170: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132170: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x80132174: beq         $v0, $zero, L_80132180
    if (ctx->r2 == 0) {
        // 0x80132178: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132180;
    }
    // 0x80132178: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013217C: sw          $zero, 0x2494($at)
    MEM_W(0X2494, ctx->r1) = 0;
L_80132180:
    // 0x80132180: jal         0x8039076C
    // 0x80132184: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132184: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80132188: beq         $v0, $zero, L_801321B0
    if (ctx->r2 == 0) {
        // 0x8013218C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_801321B0;
    }
    // 0x8013218C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132190: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132194: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132198: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8013219C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801321A0: jal         0x80132110
    // 0x801321A4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    func_ovl23_80132110(rdram, ctx);
        goto after_3;
    // 0x801321A4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_3:
    // 0x801321A8: jal         0x80005C74
    // 0x801321AC: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x801321AC: nop

    after_4:
L_801321B0:
    // 0x801321B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801321B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801321B8: jr          $ra
    // 0x801321BC: nop

    return;
    // 0x801321BC: nop

;}
RECOMP_FUNC void itSpearAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FF74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017FF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FF7C: jal         0x8017FEB8
    // 0x8017FF80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itSpearAppearInitVars(rdram, ctx);
        goto after_0;
    // 0x8017FF80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017FF84: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017FF88: addiu       $a1, $a1, -0x51CC
    ctx->r5 = ADD32(ctx->r5, -0X51CC);
    // 0x8017FF8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017FF90: jal         0x80172EC8
    // 0x8017FF94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017FF94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017FF98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017FFA0: jr          $ra
    // 0x8017FFA4: nop

    return;
    // 0x8017FFA4: nop

;}
RECOMP_FUNC void itDogasCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182F94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182F9C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80182FA0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80182FA4: jal         0x801737B8
    // 0x80182FA8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80182FA8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80182FAC: beq         $v0, $zero, L_80182FC0
    if (ctx->r2 == 0) {
        // 0x80182FB0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80182FC0;
    }
    // 0x80182FB0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80182FB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182FB8: nop

    // 0x80182FBC: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_80182FC0:
    // 0x80182FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182FCC: jr          $ra
    // 0x80182FD0: nop

    return;
    // 0x80182FD0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingGetPuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80134EEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80134EF0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80134EF4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80134EF8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80134EFC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134F00: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80134F04: lw          $t7, -0x7AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7AA4);
    // 0x80134F08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134F10: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80134F14: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134F18: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134F20: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80134F24: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80134F28: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80134F2C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80134F30: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80134F34: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x80134F38: bne         $at, $zero, L_80134F54
    if (ctx->r1 != 0) {
        // 0x80134F3C: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80134F54;
    }
    // 0x80134F3C: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80134F40: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80134F44: beq         $at, $zero, L_80134F54
    if (ctx->r1 == 0) {
        // 0x80134F48: nop
    
            goto L_80134F54;
    }
    // 0x80134F48: nop

    // 0x80134F4C: b           L_80134F54
    // 0x80134F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134F54;
    // 0x80134F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134F54:
    // 0x80134F54: beq         $v0, $zero, L_80134FC8
    if (ctx->r2 == 0) {
        // 0x80134F58: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80134FC8;
    }
    // 0x80134F58: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80134F5C: bne         $at, $zero, L_80134F78
    if (ctx->r1 != 0) {
        // 0x80134F60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134F78;
    }
    // 0x80134F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134F64: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80134F68: beq         $at, $zero, L_80134F78
    if (ctx->r1 == 0) {
        // 0x80134F6C: nop
    
            goto L_80134F78;
    }
    // 0x80134F6C: nop

    // 0x80134F70: b           L_80134F78
    // 0x80134F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134F78;
    // 0x80134F74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134F78:
    // 0x80134F78: beq         $v0, $zero, L_80134FC8
    if (ctx->r2 == 0) {
        // 0x80134F7C: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80134FC8;
    }
    // 0x80134F7C: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80134F80: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80134F84: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134F88: mflo        $a0
    ctx->r4 = lo;
    // 0x80134F8C: jal         0x80131FD0
    // 0x80134F90: nop

    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80134F90: nop

    after_0:
    // 0x80134F94: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80134F98: jal         0x80131D84
    // 0x80134F9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckFighterCrossed(rdram, ctx);
        goto after_1;
    // 0x80134F9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80134FA0: bne         $v0, $zero, L_80134FB8
    if (ctx->r2 != 0) {
        // 0x80134FA4: nop
    
            goto L_80134FB8;
    }
    // 0x80134FA4: nop

    // 0x80134FA8: jal         0x80131EFC
    // 0x80134FAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PTrainingCheckFighterLocked(rdram, ctx);
        goto after_2;
    // 0x80134FAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80134FB0: beq         $v0, $zero, L_80134FC0
    if (ctx->r2 == 0) {
        // 0x80134FB4: nop
    
            goto L_80134FC0;
    }
    // 0x80134FB4: nop

L_80134FB8:
    // 0x80134FB8: b           L_80135064
    // 0x80134FBC: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_80135064;
    // 0x80134FBC: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80134FC0:
    // 0x80134FC0: b           L_80135064
    // 0x80134FC4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_80135064;
    // 0x80134FC4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80134FC8:
    // 0x80134FC8: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80134FCC: bne         $at, $zero, L_80134FE8
    if (ctx->r1 != 0) {
        // 0x80134FD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134FE8;
    }
    // 0x80134FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134FD4: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
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
    // 0x80134FE8: beq         $v0, $zero, L_80135060
    if (ctx->r2 == 0) {
        // 0x80134FEC: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80135060;
    }
    // 0x80134FEC: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80134FF0: bne         $at, $zero, L_8013500C
    if (ctx->r1 != 0) {
        // 0x80134FF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013500C;
    }
    // 0x80134FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134FF8: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80134FFC: beq         $at, $zero, L_8013500C
    if (ctx->r1 == 0) {
        // 0x80135000: nop
    
            goto L_8013500C;
    }
    // 0x80135000: nop

    // 0x80135004: b           L_8013500C
    // 0x80135008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013500C;
    // 0x80135008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013500C:
    // 0x8013500C: beq         $v0, $zero, L_80135060
    if (ctx->r2 == 0) {
        // 0x80135010: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80135060;
    }
    // 0x80135010: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80135014: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80135018: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x8013501C: mflo        $a0
    ctx->r4 = lo;
    // 0x80135020: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80135024: jal         0x80131FD0
    // 0x80135028: nop

    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80135028: nop

    after_3:
    // 0x8013502C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80135030: jal         0x80131D84
    // 0x80135034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckFighterCrossed(rdram, ctx);
        goto after_4;
    // 0x80135034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80135038: bne         $v0, $zero, L_80135050
    if (ctx->r2 != 0) {
        // 0x8013503C: nop
    
            goto L_80135050;
    }
    // 0x8013503C: nop

    // 0x80135040: jal         0x80131EFC
    // 0x80135044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PTrainingCheckFighterLocked(rdram, ctx);
        goto after_5;
    // 0x80135044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80135048: beq         $v0, $zero, L_80135058
    if (ctx->r2 == 0) {
        // 0x8013504C: nop
    
            goto L_80135058;
    }
    // 0x8013504C: nop

L_80135050:
    // 0x80135050: b           L_80135064
    // 0x80135054: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_80135064;
    // 0x80135054: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80135058:
    // 0x80135058: b           L_80135064
    // 0x8013505C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_80135064;
    // 0x8013505C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80135060:
    // 0x80135060: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80135064:
    // 0x80135064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013506C: jr          $ra
    // 0x80135070: nop

    return;
    // 0x80135070: nop

;}
RECOMP_FUNC void sc1PGameBossHidePlayerTagAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F540: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8018F544: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x8018F548: beq         $v0, $zero, L_8018F56C
    if (ctx->r2 == 0) {
        // 0x8018F54C: nop
    
            goto L_8018F56C;
    }
    // 0x8018F54C: nop

    // 0x8018F550: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_8018F554:
    // 0x8018F554: lbu         $t7, 0x18E($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18E);
    // 0x8018F558: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8018F55C: sb          $t8, 0x18E($v1)
    MEM_B(0X18E, ctx->r3) = ctx->r24;
    // 0x8018F560: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8018F564: bnel        $v0, $zero, L_8018F554
    if (ctx->r2 != 0) {
        // 0x8018F568: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_8018F554;
    }
    goto skip_0;
    // 0x8018F568: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_0:
L_8018F56C:
    // 0x8018F56C: jr          $ra
    // 0x8018F570: nop

    return;
    // 0x8018F570: nop

;}
RECOMP_FUNC void func_ovl8_80373684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373684: jr          $ra
    // 0x80373688: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    return;
    // 0x80373688: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
;}
RECOMP_FUNC void ftKirbySpecialNWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016282C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162830: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162834: jal         0x800DDDDC
    // 0x80162838: addiu       $a1, $a1, 0x2D80
    ctx->r5 = ADD32(ctx->r5, 0X2D80);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80162838: addiu       $a1, $a1, 0x2D80
    ctx->r5 = ADD32(ctx->r5, 0X2D80);
    after_0:
    // 0x8016283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162844: jr          $ra
    // 0x80162848: nop

    return;
    // 0x80162848: nop

;}

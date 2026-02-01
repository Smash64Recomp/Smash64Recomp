#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sc1PGameTryInitPlayerArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F1C0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018F1C4: lbu         $t6, 0x4AE7($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE7);
    // 0x8018F1C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F1CC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018F1D0: beq         $t6, $at, L_8018F1E8
    if (ctx->r14 == ctx->r1) {
        // 0x8018F1D4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018F1E8;
    }
    // 0x8018F1D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F1D8: jal         0x8010E2D4
    // 0x8018F1DC: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_0;
    // 0x8018F1DC: nop

    after_0:
    // 0x8018F1E0: jal         0x801118E4
    // 0x8018F1E4: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_1;
    // 0x8018F1E4: nop

    after_1:
L_8018F1E8:
    // 0x8018F1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F1F0: jr          $ra
    // 0x8018F1F4: nop

    return;
    // 0x8018F1F4: nop

;}
RECOMP_FUNC void wpLinkSpinAttackProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CA9C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016CAA0: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8016CAA4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8016CAA8: lb          $a1, 0x2B5($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X2B5);
    // 0x8016CAAC: lwc1        $f10, 0x1C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8016CAB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016CAB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8016CAB8: bgez        $a1, L_8016CACC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8016CABC: andi        $a1, $a1, 0x3
        ctx->r5 = ctx->r5 & 0X3;
            goto L_8016CACC;
    }
    // 0x8016CABC: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x8016CAC0: beq         $a1, $zero, L_8016CACC
    if (ctx->r5 == 0) {
        // 0x8016CAC4: nop
    
            goto L_8016CACC;
    }
    // 0x8016CAC4: nop

    // 0x8016CAC8: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
L_8016CACC:
    // 0x8016CACC: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8016CAD0: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x8016CAD4: lh          $t7, 0x29C($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X29C);
    // 0x8016CAD8: lh          $t8, 0x2A4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2A4);
    // 0x8016CADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016CAE0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8016CAE4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8016CAE8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016CAEC: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016CAF0: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8016CAF4: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8016CAF8: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x8016CAFC: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x8016CB00: lwc1        $f18, 0x20($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8016CB04: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8016CB08: jr          $ra
    // 0x8016CB0C: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x8016CB0C: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void sc1PStageClearMakeTextCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133B4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133B50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133B54: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133B58: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80133B5C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133B60: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80133B64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133B68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133B6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133B70: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133B74: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133B78: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133B7C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133B80: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133B84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133B88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133B8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133B90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133B94: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133B98: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133BA0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133BA4: jal         0x8000B93C
    // 0x80133BA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133BA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133BAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133BB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133BB4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133BB8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133BC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133BC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133BC8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133BCC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133BD0: jal         0x80007080
    // 0x80133BD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133BD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133BD8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133BDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133BE0: jr          $ra
    // 0x80133BE4: nop

    return;
    // 0x80133BE4: nop

;}
RECOMP_FUNC void itRShellSpinProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017ADD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017ADD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017ADDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017ADE0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017ADE4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017ADE8: addiu       $a1, $a1, -0x4E5C
    ctx->r5 = ADD32(ctx->r5, -0X4E5C);
    // 0x8017ADEC: jal         0x801735A0
    // 0x8017ADF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017ADF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017ADF4: beql        $v0, $zero, L_8017AE38
    if (ctx->r2 == 0) {
        // 0x8017ADF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017AE38;
    }
    goto skip_0;
    // 0x8017ADF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017ADFC: lhu         $t6, 0x8E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8E);
    // 0x8017AE00: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x8017AE04: beql        $t7, $zero, L_8017AE38
    if (ctx->r15 == 0) {
        // 0x8017AE08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017AE38;
    }
    goto skip_1;
    // 0x8017AE08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8017AE0C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8017AE10: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8017AE14: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x8017AE18: jal         0x80172508
    // 0x8017AE1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_1;
    // 0x8017AE1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017AE20: jal         0x8017279C
    // 0x8017AE24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_2;
    // 0x8017AE24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017AE28: lwc1        $f8, 0x358($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X358);
    // 0x8017AE2C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8017AE30: swc1        $f10, 0x358($s0)
    MEM_W(0X358, ctx->r16) = ctx->f10.u32l;
    // 0x8017AE34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017AE38:
    // 0x8017AE38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017AE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017AE40: jr          $ra
    // 0x8017AE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017AE44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void itKabigonCommonProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E4A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017E4A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017E4AC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8017E4B0: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8017E4B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E4B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017E4BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017E4C0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017E4C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8017E4C8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8017E4CC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8017E4D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8017E4D4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8017E4D8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8017E4DC: jal         0x80171C10
    // 0x8017E4E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x8017E4E0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017E4E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017E4E8: beq         $v0, $zero, L_8017E5D4
    if (ctx->r2 == 0) {
        // 0x8017E4EC: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8017E5D4;
    }
    // 0x8017E4EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8017E4F0: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x8017E4F4: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x8017E4F8: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x8017E4FC: beq         $v0, $zero, L_8017E518
    if (ctx->r2 == 0) {
        // 0x8017E500: lui         $t3, 0x55
        ctx->r11 = S32(0X55 << 16);
            goto L_8017E518;
    }
    // 0x8017E500: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x8017E504: lw          $t8, 0x2CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2CC);
    // 0x8017E508: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017E50C: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x8017E510: bgez        $t0, L_8017E540
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8017E514: nop
    
            goto L_8017E540;
    }
    // 0x8017E514: nop

L_8017E518:
    // 0x8017E518: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E51C: ori         $t3, $t3, 0x3078
    ctx->r11 = ctx->r11 | 0X3078;
    // 0x8017E520: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8017E524: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8017E528: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8017E52C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8017E530: jal         0x80014038
    // 0x8017E534: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_1;
    // 0x8017E534: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_1:
    // 0x8017E538: b           L_8017E5D8
    // 0x8017E53C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E5D8;
    // 0x8017E53C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E540:
    // 0x8017E540: bne         $v0, $at, L_8017E584
    if (ctx->r2 != ctx->r1) {
        // 0x8017E544: lui         $t5, 0xE200
        ctx->r13 = S32(0XE200 << 16);
            goto L_8017E584;
    }
    // 0x8017E544: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8017E548: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E54C: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8017E550: ori         $t6, $t6, 0x3078
    ctx->r14 = ctx->r14 | 0X3078;
    // 0x8017E554: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8017E558: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8017E55C: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8017E560: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8017E564: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8017E568: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8017E56C: jal         0x80014038
    // 0x8017E570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_2;
    // 0x8017E570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8017E574: jal         0x801719AC
    // 0x8017E578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x8017E578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8017E57C: b           L_8017E5D8
    // 0x8017E580: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E5D8;
    // 0x8017E580: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E584:
    // 0x8017E584: lw          $t7, 0x248($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X248);
    // 0x8017E588: bne         $t7, $zero, L_8017E5CC
    if (ctx->r15 != 0) {
        // 0x8017E58C: nop
    
            goto L_8017E5CC;
    }
    // 0x8017E58C: nop

    // 0x8017E590: lw          $t8, 0x10C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10C);
    // 0x8017E594: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x8017E598: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x8017E59C: bne         $t8, $zero, L_8017E5CC
    if (ctx->r24 != 0) {
        // 0x8017E5A0: lui         $t1, 0x55
        ctx->r9 = S32(0X55 << 16);
            goto L_8017E5CC;
    }
    // 0x8017E5A0: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x8017E5A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E5A8: ori         $t1, $t1, 0x3078
    ctx->r9 = ctx->r9 | 0X3078;
    // 0x8017E5AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8017E5B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8017E5B4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8017E5B8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8017E5BC: jal         0x80014038
    // 0x8017E5C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_4;
    // 0x8017E5C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_4:
    // 0x8017E5C4: b           L_8017E5D8
    // 0x8017E5C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E5D8;
    // 0x8017E5C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E5CC:
    // 0x8017E5CC: jal         0x80171410
    // 0x8017E5D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x8017E5D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_8017E5D4:
    // 0x8017E5D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E5D8:
    // 0x8017E5D8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8017E5DC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8017E5E0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8017E5E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8017E5E8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8017E5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E5F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017E5F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017E5F8: jr          $ra
    // 0x8017E5FC: nop

    return;
    // 0x8017E5FC: nop

;}
RECOMP_FUNC void ftParamSetThrowParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E80C4: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x800E80C8: sw          $a1, 0x278($a0)
    MEM_W(0X278, ctx->r4) = ctx->r5;
    // 0x800E80CC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800E80D0: sw          $t6, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = ctx->r14;
    // 0x800E80D4: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
    // 0x800E80D8: sb          $t7, 0x281($a0)
    MEM_B(0X281, ctx->r4) = ctx->r15;
    // 0x800E80DC: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x800E80E0: sw          $t8, 0x284($a0)
    MEM_W(0X284, ctx->r4) = ctx->r24;
    // 0x800E80E4: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x800E80E8: jr          $ra
    // 0x800E80EC: sb          $t9, 0x280($a0)
    MEM_B(0X280, ctx->r4) = ctx->r25;
    return;
    // 0x800E80EC: sb          $t9, 0x280($a0)
    MEM_B(0X280, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void mnOptionMakeOptionsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132B84: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132B88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132B8C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132B90: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132B94: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132B98: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80132B9C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132BA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132BA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132BA8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132BAC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132BB0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132BB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132BB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132BBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132BC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132BC4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132BC8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132BCC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132BD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132BD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132BDC: jal         0x8000B93C
    // 0x80132BE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132BE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132BE4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132BE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132BEC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132BF0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132BF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132BF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132BFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132C00: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132C04: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132C08: jal         0x80007080
    // 0x80132C0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132C0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132C10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132C14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132C18: jr          $ra
    // 0x80132C1C: nop

    return;
    // 0x80132C1C: nop

;}
RECOMP_FUNC void gmCameraAdjustFOV(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C70C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010C710: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010C714: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8010C718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C71C: lwc1        $f6, 0xC3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC3C);
    // 0x8010C720: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8010C724: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C728: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8010C72C: jr          $ra
    // 0x8010C730: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8010C730: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void ftCommonDeadUpdateRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BC8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013BC90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8013BC94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013BC98: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013BC9C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8013BCA0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8013BCA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8013BCA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013BCAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013BCB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013BCB4: jal         0x800E806C
    // 0x8013BCB8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    ftParamMakeRumble(rdram, ctx);
        goto after_0;
    // 0x8013BCB8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x8013BCBC: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8013BCC0: addiu       $s2, $s2, 0x50E8
    ctx->r18 = ADD32(ctx->r18, 0X50E8);
    // 0x8013BCC4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013BCC8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8013BCCC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8013BCD0: addiu       $s3, $zero, 0x74
    ctx->r19 = ADD32(0, 0X74);
    // 0x8013BCD4: lbu         $t6, 0xD($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XD);
L_8013BCD8:
    // 0x8013BCD8: beql        $s0, $t6, L_8013BD38
    if (ctx->r16 == ctx->r14) {
        // 0x8013BCDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013BD38;
    }
    goto skip_0;
    // 0x8013BCDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8013BCE0: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013BCE4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8013BCE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8013BCEC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8013BCF0: lbu         $t8, 0x22($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X22);
    // 0x8013BCF4: bnel        $t8, $zero, L_8013BD38
    if (ctx->r24 != 0) {
        // 0x8013BCF8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013BD38;
    }
    goto skip_1;
    // 0x8013BCF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8013BCFC: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x8013BD00: beql        $a0, $zero, L_8013BD38
    if (ctx->r4 == 0) {
        // 0x8013BD04: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013BD38;
    }
    goto skip_2;
    // 0x8013BD04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8013BD08: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8013BD0C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8013BD10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013BD14: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8013BD18: beq         $t0, $zero, L_8013BD2C
    if (ctx->r8 == 0) {
        // 0x8013BD1C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8013BD2C;
    }
    // 0x8013BD1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8013BD20: lb          $t1, 0x14($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X14);
    // 0x8013BD24: beql        $s4, $t1, L_8013BD38
    if (ctx->r20 == ctx->r9) {
        // 0x8013BD28: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013BD38;
    }
    goto skip_3;
    // 0x8013BD28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
L_8013BD2C:
    // 0x8013BD2C: jal         0x800E806C
    // 0x8013BD30: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    ftParamMakeRumble(rdram, ctx);
        goto after_1;
    // 0x8013BD30: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x8013BD34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8013BD38:
    // 0x8013BD38: bnel        $s0, $s5, L_8013BCD8
    if (ctx->r16 != ctx->r21) {
        // 0x8013BD3C: lbu         $t6, 0xD($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0XD);
            goto L_8013BCD8;
    }
    goto skip_4;
    // 0x8013BD3C: lbu         $t6, 0xD($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XD);
    skip_4:
    // 0x8013BD40: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8013BD44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013BD48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013BD4C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BD50: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8013BD54: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8013BD58: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8013BD5C: jr          $ra
    // 0x8013BD60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013BD60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itTaruCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179C80: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179C84: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80179C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179C8C: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80179C90: bne         $at, $zero, L_80179CA8
    if (ctx->r1 != 0) {
        // 0x80179C94: nop
    
            goto L_80179CA8;
    }
    // 0x80179C94: nop

    // 0x80179C98: jal         0x80179C20
    // 0x80179C9C: nop

    itTaruCommonProcHit(rdram, ctx);
        goto after_0;
    // 0x80179C9C: nop

    after_0:
    // 0x80179CA0: b           L_80179CAC
    // 0x80179CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80179CAC;
    // 0x80179CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80179CA8:
    // 0x80179CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80179CAC:
    // 0x80179CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179CB0: jr          $ra
    // 0x80179CB4: nop

    return;
    // 0x80179CB4: nop

;}
RECOMP_FUNC void syMatrixRotPyrRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C97C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001C980: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001C984: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8001C988: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001C98C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001C990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C994: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001C998: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8001C99C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001C9A0: jal         0x800303F0
    // 0x8001C9A4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C9A4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8001C9A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001C9AC: jal         0x80035CD0
    // 0x8001C9B0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C9B0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x8001C9B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8001C9B8: jal         0x800303F0
    // 0x8001C9BC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C9BC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x8001C9C0: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001C9C4: jal         0x80035CD0
    // 0x8001C9C8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C9C8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8001C9CC: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001C9D0: jal         0x800303F0
    // 0x8001C9D4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8001C9D4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8001C9D8: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001C9DC: jal         0x80035CD0
    // 0x8001C9E0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x8001C9E0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8001C9E4: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001C9E8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001C9EC: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001C9F0: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8001C9F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001C9F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001C9FC: mul.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x8001CA00: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001CA04: mul.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8001CA08: nop

    // 0x8001CA0C: mul.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001CA10: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001CA14: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8001CA18: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8001CA1C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8001CA20: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001CA24: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001CA28: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8001CA2C: mul.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001CA30: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8001CA34: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001CA38: mul.s       $f8, $f22, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8001CA3C: nop

    // 0x8001CA40: mul.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8001CA44: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001CA48: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001CA4C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8001CA50: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001CA54: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8001CA58: mul.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8001CA5C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8001CA60: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001CA64: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8001CA68: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001CA6C: swc1        $f12, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA70: swc1        $f12, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA74: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001CA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001CA7C: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA80: mul.s       $f8, $f22, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8001CA84: swc1        $f12, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA88: swc1        $f12, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA8C: swc1        $f12, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f12.u32l;
    // 0x8001CA90: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8001CA94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001CA98: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x8001CA9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CAA0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001CAA4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001CAA8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001CAAC: jr          $ra
    // 0x8001CAB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001CAB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void dbBattleFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void gmCameraCheckTargetInBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E5F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E5F8: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010E5FC: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8010E600: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
    // 0x8010E604: bgez        $t6, L_8010E614
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8010E608: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8010E614;
    }
    // 0x8010E608: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8010E60C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8010E610: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8010E614:
    // 0x8010E614: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010E618: nop

    // 0x8010E61C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010E620: bgez        $t8, L_8010E630
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010E624: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8010E630;
    }
    // 0x8010E624: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8010E628: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8010E62C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8010E630:
    // 0x8010E630: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8010E634: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010E638: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8010E63C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E640: bc1t        L_8010E67C
    if (c1cs) {
        // 0x8010E644: nop
    
            goto L_8010E67C;
    }
    // 0x8010E644: nop

    // 0x8010E648: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8010E64C: nop

    // 0x8010E650: bc1t        L_8010E67C
    if (c1cs) {
        // 0x8010E654: nop
    
            goto L_8010E67C;
    }
    // 0x8010E654: nop

    // 0x8010E658: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8010E65C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8010E660: nop

    // 0x8010E664: bc1t        L_8010E67C
    if (c1cs) {
        // 0x8010E668: nop
    
            goto L_8010E67C;
    }
    // 0x8010E668: nop

    // 0x8010E66C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8010E670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010E674: bc1f        L_8010E684
    if (!c1cs) {
        // 0x8010E678: nop
    
            goto L_8010E684;
    }
    // 0x8010E678: nop

L_8010E67C:
    // 0x8010E67C: jr          $ra
    // 0x8010E680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010E680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010E684:
    // 0x8010E684: jr          $ra
    // 0x8010E688: nop

    return;
    // 0x8010E688: nop

;}
RECOMP_FUNC void mnVSResultsPlayWinBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013871C: jal         0x8013234C
    // 0x80138720: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x80138720: nop

    after_0:
    // 0x80138724: jal         0x80133148
    // 0x80138728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80138728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8013872C: sltiu       $at, $v0, 0xC
    ctx->r1 = ctx->r2 < 0XC ? 1 : 0;
    // 0x80138730: beq         $at, $zero, L_80138818
    if (ctx->r1 == 0) {
        // 0x80138734: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80138818;
    }
    // 0x80138734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138738: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8013873C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138740: addu        $at, $at, $t6
    gpr jr_addend_80138748 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80138744: lw          $t6, -0x6798($at)
    ctx->r14 = ADD32(ctx->r1, -0X6798);
    // 0x80138748: jr          $t6
    // 0x8013874C: nop

    switch (jr_addend_80138748 >> 2) {
        case 0: goto L_80138750; break;
        case 1: goto L_80138764; break;
        case 2: goto L_80138778; break;
        case 3: goto L_8013878C; break;
        case 4: goto L_80138750; break;
        case 5: goto L_801387A0; break;
        case 6: goto L_801387B4; break;
        case 7: goto L_801387C8; break;
        case 8: goto L_801387F0; break;
        case 9: goto L_801387DC; break;
        case 10: goto L_801387DC; break;
        case 11: goto L_80138804; break;
        default: switch_error(__func__, 0x80138748, 0x80139868);
    }
    // 0x8013874C: nop

L_80138750:
    // 0x80138750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138754: jal         0x80020AB4
    // 0x80138758: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    syAudioPlayBGM(rdram, ctx);
        goto after_2;
    // 0x80138758: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
    // 0x8013875C: b           L_80138824
    // 0x80138760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x80138760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138764:
    // 0x80138764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138768: jal         0x80020AB4
    // 0x8013876C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syAudioPlayBGM(rdram, ctx);
        goto after_3;
    // 0x8013876C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x80138770: b           L_80138824
    // 0x80138774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x80138774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138778:
    // 0x80138778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013877C: jal         0x80020AB4
    // 0x80138780: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    syAudioPlayBGM(rdram, ctx);
        goto after_4;
    // 0x80138780: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x80138784: b           L_80138824
    // 0x80138788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x80138788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013878C:
    // 0x8013878C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138790: jal         0x80020AB4
    // 0x80138794: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    syAudioPlayBGM(rdram, ctx);
        goto after_5;
    // 0x80138794: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
    // 0x80138798: b           L_80138824
    // 0x8013879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x8013879C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801387A0:
    // 0x801387A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801387A4: jal         0x80020AB4
    // 0x801387A8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    syAudioPlayBGM(rdram, ctx);
        goto after_6;
    // 0x801387A8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_6:
    // 0x801387AC: b           L_80138824
    // 0x801387B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x801387B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801387B4:
    // 0x801387B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801387B8: jal         0x80020AB4
    // 0x801387BC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    syAudioPlayBGM(rdram, ctx);
        goto after_7;
    // 0x801387BC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_7:
    // 0x801387C0: b           L_80138824
    // 0x801387C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x801387C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801387C8:
    // 0x801387C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801387CC: jal         0x80020AB4
    // 0x801387D0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    syAudioPlayBGM(rdram, ctx);
        goto after_8;
    // 0x801387D0: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_8:
    // 0x801387D4: b           L_80138824
    // 0x801387D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x801387D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801387DC:
    // 0x801387DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801387E0: jal         0x80020AB4
    // 0x801387E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    syAudioPlayBGM(rdram, ctx);
        goto after_9;
    // 0x801387E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_9:
    // 0x801387E8: b           L_80138824
    // 0x801387EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x801387EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801387F0:
    // 0x801387F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801387F4: jal         0x80020AB4
    // 0x801387F8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    syAudioPlayBGM(rdram, ctx);
        goto after_10;
    // 0x801387F8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_10:
    // 0x801387FC: b           L_80138824
    // 0x80138800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x80138800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138804:
    // 0x80138804: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80138808: jal         0x80020AB4
    // 0x8013880C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    syAudioPlayBGM(rdram, ctx);
        goto after_11;
    // 0x8013880C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_11:
    // 0x80138810: b           L_80138824
    // 0x80138814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138824;
    // 0x80138814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138818:
    // 0x80138818: jal         0x80020AB4
    // 0x8013881C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    syAudioPlayBGM(rdram, ctx);
        goto after_12;
    // 0x8013881C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_12:
    // 0x80138820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138824:
    // 0x80138824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138828: jr          $ra
    // 0x8013882C: nop

    return;
    // 0x8013882C: nop

;}
RECOMP_FUNC void mnTitleLogoFireProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133CFC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133D00: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133D04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133D10: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133D14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133D18: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80133D1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133D20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133D24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D28: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80133D2C: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x80133D30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133D34: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133D38: ori         $t0, $t0, 0x49D8
    ctx->r8 = ctx->r8 | 0X49D8;
    // 0x80133D3C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80133D40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133D44: jal         0x800D0D34
    // 0x80133D48: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    lbParticleDrawTextures(rdram, ctx);
        goto after_0;
    // 0x80133D48: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x80133D4C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133D50: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133D54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D58: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x80133D5C: ori         $t2, $t2, 0xC00
    ctx->r10 = ctx->r10 | 0XC00;
    // 0x80133D60: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80133D64: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80133D68: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x80133D6C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80133D70: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80133D74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D78: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80133D7C: ori         $t5, $t5, 0x1D00
    ctx->r13 = ctx->r13 | 0X1D00;
    // 0x80133D80: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80133D84: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80133D88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133D8C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80133D90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D94: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80133D98: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80133D9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133DA0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133DA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133DA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133DAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133DB0: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x80133DB4: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x80133DB8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133DBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133DC0: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80133DC4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133DC8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80133DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133DD4: jr          $ra
    // 0x80133DD8: nop

    return;
    // 0x80133DD8: nop

;}
RECOMP_FUNC void efManagerNessPKThunderWaveMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801029F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801029FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102A00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80102A04: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80102A08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102A0C: addiu       $a0, $a0, -0x1B6C
    ctx->r4 = ADD32(ctx->r4, -0X1B6C);
    // 0x80102A10: jal         0x800FDAFC
    // 0x80102A14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102A14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80102A18: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80102A1C: bne         $v0, $zero, L_80102A2C
    if (ctx->r2 != 0) {
        // 0x80102A20: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80102A2C;
    }
    // 0x80102A20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80102A24: b           L_80102A78
    // 0x80102A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102A78;
    // 0x80102A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102A2C:
    // 0x80102A2C: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80102A30: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80102A34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80102A38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80102A3C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80102A40: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80102A44: lw          $t8, 0x8FC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8FC);
    // 0x80102A48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80102A4C: sw          $t8, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->r24;
    // 0x80102A50: lw          $t0, 0x44($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X44);
    // 0x80102A54: lwc1        $f8, 0xA10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA10);
    // 0x80102A58: lw          $t1, 0x74($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X74);
    // 0x80102A5C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80102A60: nop

    // 0x80102A64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80102A68: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80102A6C: swc1        $f10, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f10.u32l;
    // 0x80102A70: lw          $t2, 0x74($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X74);
    // 0x80102A74: swc1        $f16, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f16.u32l;
L_80102A78:
    // 0x80102A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102A7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80102A80: jr          $ra
    // 0x80102A84: nop

    return;
    // 0x80102A84: nop

;}
RECOMP_FUNC void syAudioDepth2Cents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EB9C: lwc1        $f0, -0x1BF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BF0);
    // 0x8001EBA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001EBA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EBA8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001EBAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EBB0: beq         $a0, $zero, L_8001EBDC
    if (ctx->r4 == 0) {
        // 0x8001EBB4: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_8001EBDC;
    }
    // 0x8001EBB4: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
L_8001EBB8:
    // 0x8001EBB8: beq         $t6, $zero, L_8001EBC8
    if (ctx->r14 == 0) {
        // 0x8001EBBC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8001EBC8;
    }
    // 0x8001EBBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001EBC0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001EBC4: nop

L_8001EBC8:
    // 0x8001EBC8: srl         $a0, $v0, 1
    ctx->r4 = S32(U32(ctx->r2) >> 1);
    // 0x8001EBCC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001EBD0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001EBD4: bnel        $a0, $zero, L_8001EBB8
    if (ctx->r4 != 0) {
        // 0x8001EBD8: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_8001EBB8;
    }
    goto skip_0;
    // 0x8001EBD8: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    skip_0:
L_8001EBDC:
    // 0x8001EBDC: jr          $ra
    // 0x8001EBE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001EBE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void itNyarsWeaponCoinProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F17C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017F180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F184: lw          $a1, 0x29C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X29C);
    // 0x8017F188: bne         $a1, $zero, L_8017F198
    if (ctx->r5 != 0) {
        // 0x8017F18C: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017F198;
    }
    // 0x8017F18C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8017F190: jr          $ra
    // 0x8017F194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8017F194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017F198:
    // 0x8017F198: sw          $t6, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r14;
    // 0x8017F19C: jr          $ra
    // 0x8017F1A0: nop

    return;
    // 0x8017F1A0: nop

;}
RECOMP_FUNC void ftCommonAttackLw3ProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FC40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014FC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FC48: jal         0x8014FC60
    // 0x8014FC4C: nop

    ftCommonAttackLw3CheckInterruptSelf(rdram, ctx);
        goto after_0;
    // 0x8014FC4C: nop

    after_0:
    // 0x8014FC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014FC58: jr          $ra
    // 0x8014FC5C: nop

    return;
    // 0x8014FC5C: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckLevelArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136788: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013678C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80136790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136794: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136798: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8013679C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801367A0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801367A4: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x801367A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801367AC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801367B0: nop

    // 0x801367B4: bc1f        L_801367DC
    if (!c1cs) {
        // 0x801367B8: nop
    
            goto L_801367DC;
    }
    // 0x801367B8: nop

    // 0x801367BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801367C0: nop

    // 0x801367C4: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x801367C8: nop

    // 0x801367CC: bc1f        L_801367DC
    if (!c1cs) {
        // 0x801367D0: nop
    
            goto L_801367DC;
    }
    // 0x801367D0: nop

    // 0x801367D4: b           L_801367DC
    // 0x801367D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801367DC;
    // 0x801367D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801367DC:
    // 0x801367DC: beq         $v1, $zero, L_80136840
    if (ctx->r3 == 0) {
        // 0x801367E0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80136840;
    }
    // 0x801367E0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801367E4: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801367E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801367EC: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    // 0x801367F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801367F4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801367F8: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x801367FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136800: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80136804: nop

    // 0x80136808: bc1f        L_80136830
    if (!c1cs) {
        // 0x8013680C: nop
    
            goto L_80136830;
    }
    // 0x8013680C: nop

    // 0x80136810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136814: nop

    // 0x80136818: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8013681C: nop

    // 0x80136820: bc1f        L_80136830
    if (!c1cs) {
        // 0x80136824: nop
    
            goto L_80136830;
    }
    // 0x80136824: nop

    // 0x80136828: b           L_80136830
    // 0x8013682C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136830;
    // 0x8013682C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136830:
    // 0x80136830: beql        $v1, $zero, L_80136844
    if (ctx->r3 == 0) {
        // 0x80136834: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136844;
    }
    goto skip_0;
    // 0x80136834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80136838: jr          $ra
    // 0x8013683C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013683C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136840:
    // 0x80136840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136844:
    // 0x80136844: jr          $ra
    // 0x80136848: nop

    return;
    // 0x80136848: nop

;}
RECOMP_FUNC void mvOpeningYosterFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_ovl8_80371474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371478: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037147C: addiu       $a2, $a2, -0x1190
    ctx->r6 = ADD32(ctx->r6, -0X1190);
    // 0x80371480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371484: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80371488: jal         0x80371460
    // 0x8037148C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    func_ovl8_80371460(rdram, ctx);
        goto after_0;
    // 0x8037148C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    after_0:
    // 0x80371490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371498: jr          $ra
    // 0x8037149C: nop

    return;
    // 0x8037149C: nop

;}
RECOMP_FUNC void __n_setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E2AC: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8002E2B0: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8002E2B4: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8002E2B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002E2BC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8002E2C0: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x8002E2C4: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8002E2C8: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x8002E2CC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8002E2D0: sb          $t8, 0x8($t0)
    MEM_B(0X8, ctx->r8) = ctx->r24;
    // 0x8002E2D4: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8002E2D8: lh          $t1, 0xC($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XC);
    // 0x8002E2DC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8002E2E0: sh          $t1, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r9;
    // 0x8002E2E4: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x8002E2E8: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8002E2EC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8002E2F0: jr          $ra
    // 0x8002E2F4: sb          $t4, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r12;
    return;
    // 0x8002E2F4: sb          $t4, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r12;
;}
RECOMP_FUNC void ftSamusSpecialNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DA60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DA64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015DA68: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015DA6C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015DA70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015DA74: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x8015DA78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DA7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015DA80: jal         0x800E6F24
    // 0x8015DA84: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015DA84: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015DA88: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015DA8C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015DA90: addiu       $t8, $t8, -0x2CC8
    ctx->r24 = ADD32(ctx->r24, -0X2CC8);
    // 0x8015DA94: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015DA98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DA9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DAA0: jr          $ra
    // 0x8015DAA4: nop

    return;
    // 0x8015DAA4: nop

;}
RECOMP_FUNC void mnVSResultsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801388AC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801388B0: lw          $t6, -0x6488($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6488);
    // 0x801388B4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801388B8: lw          $t8, -0x63BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X63BC);
    // 0x801388BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801388C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801388C4: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x801388C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801388CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801388D0: bne         $t8, $v0, L_80138904
    if (ctx->r24 != ctx->r2) {
        // 0x801388D4: sw          $v0, -0x6488($at)
        MEM_W(-0X6488, ctx->r1) = ctx->r2;
            goto L_80138904;
    }
    // 0x801388D4: sw          $v0, -0x6488($at)
    MEM_W(-0X6488, ctx->r1) = ctx->r2;
    // 0x801388D8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801388DC: lw          $t9, -0x63F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63F0);
    // 0x801388E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801388E4: beq         $t9, $at, L_801388F4
    if (ctx->r25 == ctx->r1) {
        // 0x801388E8: nop
    
            goto L_801388F4;
    }
    // 0x801388E8: nop

    // 0x801388EC: jal         0x80135204
    // 0x801388F0: nop

    mnVSResultsMakeWallpaperTint2(rdram, ctx);
        goto after_0;
    // 0x801388F0: nop

    after_0:
L_801388F4:
    // 0x801388F4: jal         0x80132EA8
    // 0x801388F8: nop

    mnVSResultsMakeWallpaper(rdram, ctx);
        goto after_1;
    // 0x801388F8: nop

    after_1:
    // 0x801388FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80138900: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_80138904:
    // 0x80138904: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80138908: lw          $t0, -0x63B8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X63B8);
    // 0x8013890C: bne         $t0, $v0, L_80138940
    if (ctx->r8 != ctx->r2) {
        // 0x80138910: nop
    
            goto L_80138940;
    }
    // 0x80138910: nop

    // 0x80138914: jal         0x8013457C
    // 0x80138918: nop

    mnVSResultsMakeResultsText(rdram, ctx);
        goto after_2;
    // 0x80138918: nop

    after_2:
    // 0x8013891C: jal         0x801366F0
    // 0x80138920: nop

    mnVSResultsMakeLabel(rdram, ctx);
        goto after_3;
    // 0x80138920: nop

    after_3:
    // 0x80138924: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80138928: lw          $t1, -0x63F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X63F0);
    // 0x8013892C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80138930: beq         $t1, $at, L_80138940
    if (ctx->r9 == ctx->r1) {
        // 0x80138934: nop
    
            goto L_80138940;
    }
    // 0x80138934: nop

    // 0x80138938: jal         0x80138830
    // 0x8013893C: nop

    mnVSResultsMakeConfetti(rdram, ctx);
        goto after_4;
    // 0x8013893C: nop

    after_4:
L_80138940:
    // 0x80138940: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138944: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80138948: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x8013894C: lw          $v1, -0x63B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X63B4);
    // 0x80138950: bnel        $v1, $v0, L_80138974
    if (ctx->r3 != ctx->r2) {
        // 0x80138954: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80138974;
    }
    goto skip_0;
    // 0x80138954: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x80138958: jal         0x801375AC
    // 0x8013895C: nop

    mnVSResultsInitFightersAll(rdram, ctx);
        goto after_5;
    // 0x8013895C: nop

    after_5:
    // 0x80138960: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80138964: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138968: lw          $v1, -0x63B4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X63B4);
    // 0x8013896C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80138970: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80138974:
    // 0x80138974: beq         $at, $zero, L_801389CC
    if (ctx->r1 == 0) {
        // 0x80138978: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_801389CC;
    }
    // 0x80138978: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8013897C: addiu       $v1, $v1, -0x63C0
    ctx->r3 = ADD32(ctx->r3, -0X63C0);
    // 0x80138980: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80138984: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80138988: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8013898C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80138990: beq         $at, $zero, L_801389B4
    if (ctx->r1 == 0) {
        // 0x80138994: addiu       $t4, $zero, 0xFF
        ctx->r12 = ADD32(0, 0XFF);
            goto L_801389B4;
    }
    // 0x80138994: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80138998: addiu       $t2, $v0, 0x16
    ctx->r10 = ADD32(ctx->r2, 0X16);
    // 0x8013899C: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x801389A0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801389A4: bne         $at, $zero, L_801389B4
    if (ctx->r1 != 0) {
        // 0x801389A8: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_801389B4;
    }
    // 0x801389A8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x801389AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801389B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801389B4:
    // 0x801389B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801389B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801389BC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801389C0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x801389C4: jal         0x803904E0
    // 0x801389C8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_6;
    // 0x801389C8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_6:
L_801389CC:
    // 0x801389CC: jal         0x80131EB0
    // 0x801389D0: nop

    mnVSResultsAnnounceWinner(rdram, ctx);
        goto after_7;
    // 0x801389D0: nop

    after_7:
    // 0x801389D4: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801389D8: lw          $t5, -0x63F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63F0);
    // 0x801389DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801389E0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801389E4: beq         $t5, $at, L_80138A0C
    if (ctx->r13 == ctx->r1) {
        // 0x801389E8: nop
    
            goto L_80138A0C;
    }
    // 0x801389E8: nop

    // 0x801389EC: lw          $t6, -0x6488($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6488);
    // 0x801389F0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x801389F4: bne         $t6, $at, L_80138A0C
    if (ctx->r14 != ctx->r1) {
        // 0x801389F8: nop
    
            goto L_80138A0C;
    }
    // 0x801389F8: nop

    // 0x801389FC: jal         0x80138714
    // 0x80138A00: nop

    mnVSResultsPlayWinBGM(rdram, ctx);
        goto after_8;
    // 0x80138A00: nop

    after_8:
    // 0x80138A04: jal         0x80137854
    // 0x80138A08: nop

    mnVSResultsMakeAudioThread(rdram, ctx);
        goto after_9;
    // 0x80138A08: nop

    after_9:
L_80138A0C:
    // 0x80138A0C: jal         0x80131E18
    // 0x80138A10: nop

    mnVSResultsCheckExit(rdram, ctx);
        goto after_10;
    // 0x80138A10: nop

    after_10:
    // 0x80138A14: beq         $v0, $zero, L_80138B60
    if (ctx->r2 == 0) {
        // 0x80138A18: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80138B60;
    }
    // 0x80138A18: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80138A1C: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x80138A20: lbu         $v0, 0x457($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X457);
    // 0x80138A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80138A28: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x80138A2C: bne         $t7, $zero, L_80138A50
    if (ctx->r15 != 0) {
        // 0x80138A30: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_80138A50;
    }
    // 0x80138A30: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x80138A34: lbu         $t8, 0x5DE($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X5DE);
    // 0x80138A38: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80138A3C: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x80138A40: bne         $at, $zero, L_80138A50
    if (ctx->r1 != 0) {
        // 0x80138A44: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80138A50;
    }
    // 0x80138A44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80138A48: sb          $t9, 0x4AD2($at)
    MEM_B(0X4AD2, ctx->r1) = ctx->r25;
    // 0x80138A4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80138A50:
    // 0x80138A50: bne         $t0, $zero, L_80138B18
    if (ctx->r8 != 0) {
        // 0x80138A54: nop
    
            goto L_80138B18;
    }
    // 0x80138A54: nop

    // 0x80138A58: lhu         $t1, 0x5DC($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X5DC);
    // 0x80138A5C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80138A60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80138A64: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80138A68: bne         $t2, $at, L_80138B18
    if (ctx->r10 != ctx->r1) {
        // 0x80138A6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80138B18;
    }
    // 0x80138A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138A70: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80138A74: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x80138A78: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80138A7C:
    // 0x80138A7C: lbu         $t3, 0x479($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X479);
    // 0x80138A80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80138A84: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80138A88: beq         $t3, $zero, L_80138A98
    if (ctx->r11 == 0) {
        // 0x80138A8C: sllv        $t5, $t4, $v1
        ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
            goto L_80138A98;
    }
    // 0x80138A8C: sllv        $t5, $t4, $v1
    ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x80138A90: or          $v0, $v0, $t5
    ctx->r2 = ctx->r2 | ctx->r13;
    // 0x80138A94: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80138A98:
    // 0x80138A98: lbu         $t6, 0x499($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X499);
    // 0x80138A9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80138AA0: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80138AA4: beq         $t6, $zero, L_80138AB4
    if (ctx->r14 == 0) {
        // 0x80138AA8: addiu       $t1, $v1, 0x2
        ctx->r9 = ADD32(ctx->r3, 0X2);
            goto L_80138AB4;
    }
    // 0x80138AA8: addiu       $t1, $v1, 0x2
    ctx->r9 = ADD32(ctx->r3, 0X2);
    // 0x80138AAC: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
    // 0x80138AB0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80138AB4:
    // 0x80138AB4: lbu         $t0, 0x4B9($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4B9);
    // 0x80138AB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138ABC: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80138AC0: beq         $t0, $zero, L_80138AD0
    if (ctx->r8 == 0) {
        // 0x80138AC4: addiu       $t5, $v1, 0x3
        ctx->r13 = ADD32(ctx->r3, 0X3);
            goto L_80138AD0;
    }
    // 0x80138AC4: addiu       $t5, $v1, 0x3
    ctx->r13 = ADD32(ctx->r3, 0X3);
    // 0x80138AC8: or          $v0, $v0, $t3
    ctx->r2 = ctx->r2 | ctx->r11;
    // 0x80138ACC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80138AD0:
    // 0x80138AD0: lbu         $t4, 0x4D9($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4D9);
    // 0x80138AD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80138AD8: sllv        $t8, $t6, $t5
    ctx->r24 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x80138ADC: beq         $t4, $zero, L_80138AEC
    if (ctx->r12 == 0) {
        // 0x80138AE0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80138AEC;
    }
    // 0x80138AE0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80138AE4: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x80138AE8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80138AEC:
    // 0x80138AEC: bne         $v1, $a1, L_80138A7C
    if (ctx->r3 != ctx->r5) {
        // 0x80138AF0: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_80138A7C;
    }
    // 0x80138AF0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x80138AF4: andi        $t7, $v0, 0x36F
    ctx->r15 = ctx->r2 & 0X36F;
    // 0x80138AF8: addiu       $at, $zero, 0x36F
    ctx->r1 = ADD32(0, 0X36F);
    // 0x80138AFC: bne         $t7, $at, L_80138B18
    if (ctx->r15 != ctx->r1) {
        // 0x80138B00: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80138B18;
    }
    // 0x80138B00: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80138B04: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80138B08: addu        $t0, $v0, $a2
    ctx->r8 = ADD32(ctx->r2, ctx->r6);
    // 0x80138B0C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80138B10: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80138B14: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80138B18:
    // 0x80138B18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80138B1C: beq         $a2, $zero, L_80138B38
    if (ctx->r6 == 0) {
        // 0x80138B20: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_80138B38;
    }
    // 0x80138B20: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80138B24: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80138B28: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80138B2C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80138B30: b           L_80138B48
    // 0x80138B34: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
        goto L_80138B48;
    // 0x80138B34: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
L_80138B38:
    // 0x80138B38: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80138B3C: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80138B40: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80138B44: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_80138B48:
    // 0x80138B48: jal         0x800266A0
    // 0x80138B4C: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_11;
    // 0x80138B4C: nop

    after_11:
    // 0x80138B50: jal         0x80020A74
    // 0x80138B54: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_12;
    // 0x80138B54: nop

    after_12:
    // 0x80138B58: jal         0x80005C74
    // 0x80138B5C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_13;
    // 0x80138B5C: nop

    after_13:
L_80138B60:
    // 0x80138B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80138B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80138B68: jr          $ra
    // 0x80138B6C: nop

    return;
    // 0x80138B6C: nop

;}
RECOMP_FUNC void itHeartDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017482C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174830: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174834: addiu       $a1, $a1, -0x67FC
    ctx->r5 = ADD32(ctx->r5, -0X67FC);
    // 0x80174838: jal         0x80172EC8
    // 0x8017483C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017483C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80174840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174848: jr          $ra
    // 0x8017484C: nop

    return;
    // 0x8017484C: nop

;}
RECOMP_FUNC void n_alFxPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B028: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002B02C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002B030: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002B034: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002B038: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8002B03C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002B040: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002B044: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8002B048: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8002B04C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002B050: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002B054: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8002B058: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002B05C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8002B060: lw          $s3, 0x20($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X20);
    // 0x8002B064: jal         0x8002A9C4
    // 0x8002B068: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    n_alAuxBusPull(rdram, ctx);
        goto after_0;
    // 0x8002B068: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x8002B06C: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x8002B070: lui         $t9, 0x7C0
    ctx->r25 = S32(0X7C0 << 16);
    // 0x8002B074: lui         $t0, 0xC00
    ctx->r8 = S32(0XC00 << 16);
    // 0x8002B078: lui         $t1, 0x930
    ctx->r9 = S32(0X930 << 16);
    // 0x8002B07C: ori         $t9, $t9, 0x7C0
    ctx->r25 = ctx->r25 | 0X7C0;
    // 0x8002B080: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x8002B084: ori         $t1, $t1, 0x7C0
    ctx->r9 = ctx->r9 | 0X7C0;
    // 0x8002B088: ori         $t0, $t0, 0x5A82
    ctx->r8 = ctx->r8 | 0X5A82;
    // 0x8002B08C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002B090: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002B094: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8002B098: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8002B09C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002B0A0: addiu       $s2, $zero, 0x170
    ctx->r18 = ADD32(0, 0X170);
    // 0x8002B0A4: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x8002B0A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B0AC: addiu       $a2, $zero, 0x7C0
    ctx->r6 = ADD32(0, 0X7C0);
    // 0x8002B0B0: jal         0x8002AA68
    // 0x8002B0B4: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    func_8002AA68_2B668(rdram, ctx);
        goto after_1;
    // 0x8002B0B4: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    after_1:
    // 0x8002B0B8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8002B0BC: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x8002B0C0: ori         $t2, $t2, 0x930
    ctx->r10 = ctx->r10 | 0X930;
    // 0x8002B0C4: addiu       $t3, $zero, 0x170
    ctx->r11 = ADD32(0, 0X170);
    // 0x8002B0C8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8002B0CC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8002B0D0: lbu         $t4, 0x24($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X24);
    // 0x8002B0D4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002B0D8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002B0DC: blez        $t4, L_8002B28C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002B0E0: lui         $fp, 0xC00
        ctx->r30 = S32(0XC00 << 16);
            goto L_8002B28C;
    }
    // 0x8002B0E0: lui         $fp, 0xC00
    ctx->r30 = S32(0XC00 << 16);
    // 0x8002B0E4: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_8002B0E8:
    // 0x8002B0E8: lw          $t5, 0x20($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X20);
    // 0x8002B0EC: sll         $t6, $s6, 2
    ctx->r14 = S32(ctx->r22 << 2);
    // 0x8002B0F0: addu        $t6, $t6, $s6
    ctx->r14 = ADD32(ctx->r14, ctx->r22);
    // 0x8002B0F4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002B0F8: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
    // 0x8002B0FC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8002B100: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x8002B104: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B108: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8002B10C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002B110: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8002B114: addu        $s4, $v0, $t9
    ctx->r20 = ADD32(ctx->r2, ctx->r25);
    // 0x8002B118: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B11C: bne         $s4, $v1, L_8002B13C
    if (ctx->r20 != ctx->r3) {
        // 0x8002B120: addu        $s7, $v0, $t2
        ctx->r23 = ADD32(ctx->r2, ctx->r10);
            goto L_8002B13C;
    }
    // 0x8002B120: addu        $s7, $v0, $t2
    ctx->r23 = ADD32(ctx->r2, ctx->r10);
    // 0x8002B124: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002B128: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x8002B12C: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
    // 0x8002B130: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8002B134: b           L_8002B154
    // 0x8002B138: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
        goto L_8002B154;
    // 0x8002B138: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_8002B13C:
    // 0x8002B13C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002B140: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002B144: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x8002B148: jal         0x8002AC48
    // 0x8002B14C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8002AC48_2B848(rdram, ctx);
        goto after_2;
    // 0x8002B14C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x8002B150: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B154:
    // 0x8002B154: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B158: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002B15C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002B160: jal         0x8002AE1C
    // 0x8002B164: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8002AE1C_2BA1C(rdram, ctx);
        goto after_3;
    // 0x8002B164: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x8002B168: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8002B16C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002B170: sll         $t7, $s5, 16
    ctx->r15 = S32(ctx->r21 << 16);
    // 0x8002B174: beq         $a0, $zero, L_8002B1C0
    if (ctx->r4 == 0) {
        // 0x8002B178: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_8002B1C0;
    }
    // 0x8002B178: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8002B17C: andi        $t8, $s2, 0xFFFF
    ctx->r24 = ctx->r18 & 0XFFFF;
    // 0x8002B180: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8002B184: or          $t5, $t4, $fp
    ctx->r13 = ctx->r12 | ctx->r30;
    // 0x8002B188: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8002B18C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002B190: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x8002B194: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x8002B198: bnel        $t0, $zero, L_8002B1C4
    if (ctx->r8 != 0) {
        // 0x8002B19C: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_8002B1C4;
    }
    goto skip_0;
    // 0x8002B19C: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_0:
    // 0x8002B1A0: lw          $t1, 0x20($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X20);
    // 0x8002B1A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B1A8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8002B1AC: bne         $t1, $zero, L_8002B1C0
    if (ctx->r9 != 0) {
        // 0x8002B1B0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_8002B1C0;
    }
    // 0x8002B1B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002B1B4: jal         0x8002AA68
    // 0x8002B1B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8002AA68_2B668(rdram, ctx);
        goto after_4;
    // 0x8002B1B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8002B1BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B1C0:
    // 0x8002B1C0: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_8002B1C4:
    // 0x8002B1C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002B1C8: addiu       $a3, $s0, 0x8
    ctx->r7 = ADD32(ctx->r16, 0X8);
    // 0x8002B1CC: beq         $v1, $zero, L_8002B200
    if (ctx->r3 == 0) {
        // 0x8002B1D0: andi        $t3, $v1, 0xFFFF
        ctx->r11 = ctx->r3 & 0XFFFF;
            goto L_8002B200;
    }
    // 0x8002B1D0: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x8002B1D4: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8002B1D8: andi        $t7, $s5, 0xFFFF
    ctx->r15 = ctx->r21 & 0XFFFF;
    // 0x8002B1DC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8002B1E0: or          $t4, $t3, $fp
    ctx->r12 = ctx->r11 | ctx->r30;
    // 0x8002B1E4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002B1E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002B1EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B1F0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002B1F4: jal         0x8002AA68
    // 0x8002B1F8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8002AA68_2B668(rdram, ctx);
        goto after_5;
    // 0x8002B1F8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x8002B1FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B200:
    // 0x8002B200: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8002B204: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002B208: beql        $a0, $zero, L_8002B220
    if (ctx->r4 == 0) {
        // 0x8002B20C: lw          $t9, 0x24($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X24);
            goto L_8002B220;
    }
    goto skip_1;
    // 0x8002B20C: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    skip_1:
    // 0x8002B210: jal         0x8002AB94
    // 0x8002B214: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _n_filterBuffer(rdram, ctx);
        goto after_6;
    // 0x8002B214: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8002B218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002B21C: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
L_8002B220:
    // 0x8002B220: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002B224: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8002B228: bne         $t9, $zero, L_8002B23C
    if (ctx->r25 != 0) {
        // 0x8002B22C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_8002B23C;
    }
    // 0x8002B22C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002B230: jal         0x8002AA68
    // 0x8002B234: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8002AA68_2B668(rdram, ctx);
        goto after_7;
    // 0x8002B234: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_7:
    // 0x8002B238: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8002B23C:
    // 0x8002B23C: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x8002B240: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8002B244: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8002B248: beq         $v1, $zero, L_8002B270
    if (ctx->r3 == 0) {
        // 0x8002B24C: sra         $s6, $s6, 16
        ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
            goto L_8002B270;
    }
    // 0x8002B24C: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8002B250: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8002B254: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x8002B258: sll         $t4, $s2, 16
    ctx->r12 = S32(ctx->r18 << 16);
    // 0x8002B25C: ori         $t5, $t4, 0x930
    ctx->r13 = ctx->r12 | 0X930;
    // 0x8002B260: or          $t2, $t1, $fp
    ctx->r10 = ctx->r9 | ctx->r30;
    // 0x8002B264: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8002B268: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8002B26C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002B270:
    // 0x8002B270: lbu         $t8, 0x24($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X24);
    // 0x8002B274: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8002B278: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x8002B27C: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002B280: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002B284: bne         $at, $zero, L_8002B0E8
    if (ctx->r1 != 0) {
        // 0x8002B288: addu        $v1, $v0, $t7
        ctx->r3 = ADD32(ctx->r2, ctx->r15);
            goto L_8002B0E8;
    }
    // 0x8002B288: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
L_8002B28C:
    // 0x8002B28C: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x8002B290: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x8002B294: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x8002B298: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8002B29C: addiu       $t0, $t9, 0x170
    ctx->r8 = ADD32(ctx->r25, 0X170);
    // 0x8002B2A0: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8002B2A4: sltu        $at, $t2, $t0
    ctx->r1 = ctx->r10 < ctx->r8 ? 1 : 0;
    // 0x8002B2A8: beq         $at, $zero, L_8002B2B8
    if (ctx->r1 == 0) {
        // 0x8002B2AC: sw          $t0, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r8;
            goto L_8002B2B8;
    }
    // 0x8002B2AC: sw          $t0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r8;
    // 0x8002B2B0: subu        $t3, $t0, $v1
    ctx->r11 = SUB32(ctx->r8, ctx->r3);
    // 0x8002B2B4: sw          $t3, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r11;
L_8002B2B8:
    // 0x8002B2B8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002B2BC: lui         $t4, 0xA00
    ctx->r12 = S32(0XA00 << 16);
    // 0x8002B2C0: lui         $t5, 0x7C0
    ctx->r13 = S32(0X7C0 << 16);
    // 0x8002B2C4: ori         $t5, $t5, 0x170
    ctx->r13 = ctx->r13 | 0X170;
    // 0x8002B2C8: ori         $t4, $t4, 0x930
    ctx->r12 = ctx->r12 | 0X930;
    // 0x8002B2CC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8002B2D0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8002B2D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002B2D8: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8002B2DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002B2E0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002B2E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B2E8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002B2F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002B2F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B2F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002B2FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002B300: jr          $ra
    // 0x8002B304: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002B304: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mvOpeningSectorStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132898: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013289C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801328A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328A4: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801328A8: addiu       $a0, $a0, 0x293C
    ctx->r4 = ADD32(ctx->r4, 0X293C);
    // 0x801328AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801328B0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801328B4: jal         0x80007024
    // 0x801328B8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801328B8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801328BC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801328C0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801328C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328C8: addiu       $t9, $t9, 0x2C10
    ctx->r25 = ADD32(ctx->r25, 0X2C10);
    // 0x801328CC: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801328D0: addiu       $a0, $a0, 0x2958
    ctx->r4 = ADD32(ctx->r4, 0X2958);
    // 0x801328D4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801328D8: jal         0x8000683C
    // 0x801328DC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801328DC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801328E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328E8: jr          $ra
    // 0x801328EC: nop

    return;
    // 0x801328EC: nop

;}
RECOMP_FUNC void ftCommonShieldBreakFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149728: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014972C: jal         0x800DE6E4
    // 0x80149730: addiu       $a1, $a1, -0x695C
    ctx->r5 = ADD32(ctx->r5, -0X695C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80149730: addiu       $a1, $a1, -0x695C
    ctx->r5 = ADD32(ctx->r5, -0X695C);
    after_0:
    // 0x80149734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014973C: jr          $ra
    // 0x80149740: nop

    return;
    // 0x80149740: nop

;}
RECOMP_FUNC void mnPlayersVSPortraitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131EEC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131EF0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80131EF4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80131EF8: lw          $a1, 0x58($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X58);
    // 0x80131EFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80131F00: jal         0x80131DC4
    // 0x80131F04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mnPlayersVSGetNextPortraitX(rdram, ctx);
        goto after_0;
    // 0x80131F04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80131F08: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80131F0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F10: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80131F14: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80131F18: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80131F1C: nop

    // 0x80131F20: bc1tl       L_80131F48
    if (c1cs) {
        // 0x80131F24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131F48;
    }
    goto skip_0;
    // 0x80131F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80131F28: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80131F2C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131F30: beql        $v1, $zero, L_80131F48
    if (ctx->r3 == 0) {
        // 0x80131F34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131F48;
    }
    goto skip_1;
    // 0x80131F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80131F38: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x80131F3C: lwc1        $f6, 0x58($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80131F40: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x80131F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131F48:
    // 0x80131F48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131F4C: jr          $ra
    // 0x80131F50: nop

    return;
    // 0x80131F50: nop

;}
RECOMP_FUNC void jtgt_ovl3_801601A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801601A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801601A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801601A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801601AC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801601B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801601B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801601B8: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x801601BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801601C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801601C4: jal         0x800E6F24
    // 0x801601C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801601C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801601CC: jal         0x800E0830
    // 0x801601D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801601D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801601D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801601D8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801601DC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x801601E0: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x801601E4: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x801601E8: addiu       $t8, $t8, -0x6374
    ctx->r24 = ADD32(ctx->r24, -0X6374);
    // 0x801601EC: addiu       $t9, $t9, -0x633C
    ctx->r25 = ADD32(ctx->r25, -0X633C);
    // 0x801601F0: sw          $t7, 0x9F8($v0)
    MEM_W(0X9F8, ctx->r2) = ctx->r15;
    // 0x801601F4: sw          $t8, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r24;
    // 0x801601F8: sw          $t9, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r25;
    // 0x801601FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160204: jr          $ra
    // 0x80160208: nop

    return;
    // 0x80160208: nop

;}
RECOMP_FUNC void randFloat2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800273F4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800273F8: addiu       $v0, $v0, -0x2CE0
    ctx->r2 = ADD32(ctx->r2, -0X2CE0);
    // 0x800273FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80027400: lui         $at, 0x26
    ctx->r1 = S32(0X26 << 16);
    // 0x80027404: ori         $at, $at, 0x9EC3
    ctx->r1 = ctx->r1 | 0X9EC3;
    // 0x80027408: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002740C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80027410: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80027414: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027418: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8002741C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027420: sll         $t7, $t7, 8
    ctx->r15 = S32(ctx->r15 << 8);
    // 0x80027424: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80027428: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002742C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027430: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80027434: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80027438: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8002743C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80027440: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80027444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002744C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80027450: jr          $ra
    // 0x80027454: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x80027454: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
;}
RECOMP_FUNC void ftHammerCheckStatusHammerAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F37CC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800F37D0: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800F37D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F37D8: slti        $at, $v1, 0x92
    ctx->r1 = SIGNED(ctx->r3) < 0X92 ? 1 : 0;
    // 0x800F37DC: bne         $at, $zero, L_800F37F4
    if (ctx->r1 != 0) {
        // 0x800F37E0: slti        $at, $v1, 0x98
        ctx->r1 = SIGNED(ctx->r3) < 0X98 ? 1 : 0;
            goto L_800F37F4;
    }
    // 0x800F37E0: slti        $at, $v1, 0x98
    ctx->r1 = SIGNED(ctx->r3) < 0X98 ? 1 : 0;
    // 0x800F37E4: beq         $at, $zero, L_800F37F4
    if (ctx->r1 == 0) {
        // 0x800F37E8: nop
    
            goto L_800F37F4;
    }
    // 0x800F37E8: nop

    // 0x800F37EC: jr          $ra
    // 0x800F37F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F37F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F37F4:
    // 0x800F37F4: jr          $ra
    // 0x800F37F8: nop

    return;
    // 0x800F37F8: nop

;}
RECOMP_FUNC void itMapCheckLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173C68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80173C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80173C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80173C74: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80173C78: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80173C7C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80173C80: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80173C84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80173C88: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80173C8C: jal         0x801737B8
    // 0x80173C90: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173C90: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80173C94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80173C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80173C9C: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80173CA0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80173CA4: jal         0x801737EC
    // 0x80173CA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80173CA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80173CAC: beql        $v0, $zero, L_80173CC0
    if (ctx->r2 == 0) {
        // 0x80173CB0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80173CC0;
    }
    goto skip_0;
    // 0x80173CB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80173CB4: jal         0x80172508
    // 0x80173CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80173CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80173CBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80173CC0:
    // 0x80173CC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173CC4: beq         $t7, $zero, L_80173D10
    if (ctx->r15 == 0) {
        // 0x80173CC8: nop
    
            goto L_80173D10;
    }
    // 0x80173CC8: nop

    // 0x80173CCC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80173CD0: addiu       $a0, $v0, 0x2C
    ctx->r4 = ADD32(ctx->r2, 0X2C);
    // 0x80173CD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80173CD8: jal         0x800C7B08
    // 0x80173CDC: addiu       $a1, $v0, 0xB8
    ctx->r5 = ADD32(ctx->r2, 0XB8);
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x80173CDC: addiu       $a1, $v0, 0xB8
    ctx->r5 = ADD32(ctx->r2, 0XB8);
    after_3:
    // 0x80173CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80173CE4: jal         0x800C7AE0
    // 0x80173CE8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    lbCommonScale2D(rdram, ctx);
        goto after_4;
    // 0x80173CE8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80173CEC: jal         0x80172508
    // 0x80173CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_5;
    // 0x80173CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80173CF4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80173CF8: beq         $v0, $zero, L_80173D08
    if (ctx->r2 == 0) {
        // 0x80173CFC: nop
    
            goto L_80173D08;
    }
    // 0x80173CFC: nop

    // 0x80173D00: jalr        $v0
    // 0x80173D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80173D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80173D08:
    // 0x80173D08: b           L_80173D10
    // 0x80173D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173D10;
    // 0x80173D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80173D10:
    // 0x80173D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80173D18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80173D1C: jr          $ra
    // 0x80173D20: nop

    return;
    // 0x80173D20: nop

;}
RECOMP_FUNC void gcLinkGObjSPAfter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007A44: lbu         $t6, 0xC($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC);
    // 0x80007A48: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007A4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80007A50: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80007A54: lw          $a1, 0x6778($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6778);
    // 0x80007A58: beq         $a1, $zero, L_80007A90
    if (ctx->r5 == 0) {
        // 0x80007A5C: nop
    
            goto L_80007A90;
    }
    // 0x80007A5C: nop

    // 0x80007A60: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80007A64: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80007A68: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x80007A6C: beq         $at, $zero, L_80007A90
    if (ctx->r1 == 0) {
        // 0x80007A70: nop
    
            goto L_80007A90;
    }
    // 0x80007A70: nop

    // 0x80007A74: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
L_80007A78:
    // 0x80007A78: beq         $a1, $zero, L_80007A90
    if (ctx->r5 == 0) {
        // 0x80007A7C: nop
    
            goto L_80007A90;
    }
    // 0x80007A7C: nop

    // 0x80007A80: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80007A84: sltu        $at, $t9, $v0
    ctx->r1 = ctx->r25 < ctx->r2 ? 1 : 0;
    // 0x80007A88: bnel        $at, $zero, L_80007A78
    if (ctx->r1 != 0) {
        // 0x80007A8C: lw          $a1, 0x8($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X8);
            goto L_80007A78;
    }
    goto skip_0;
    // 0x80007A8C: lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X8);
    skip_0:
L_80007A90:
    // 0x80007A90: jal         0x800079D4
    // 0x80007A94: nop

    gcLinkGObjAfter(rdram, ctx);
        goto after_0;
    // 0x80007A94: nop

    after_0:
    // 0x80007A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007AA0: jr          $ra
    // 0x80007AA4: nop

    return;
    // 0x80007AA4: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeCPOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EF78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018EF7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018EF80: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EF84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EF88: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018EF8C: jal         0x80009968
    // 0x8018EF90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018EF90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018EF94: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EF98: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018EF9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018EFA0: sw          $v0, 0xBB0($at)
    MEM_W(0XBB0, ctx->r1) = ctx->r2;
    // 0x8018EFA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018EFA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EFAC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018EFB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EFB4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018EFB8: jal         0x80009DF4
    // 0x8018EFBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018EFBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018EFC0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018EFC4: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018EFC8: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8018EFCC: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8018EFD0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018EFD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018EFD8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018EFDC: jal         0x800CCFDC
    // 0x8018EFE0: lw          $a1, 0x54($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X54);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018EFE0: lw          $a1, 0x54($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X54);
    after_2:
    // 0x8018EFE4: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8018EFE8: addiu       $t3, $zero, 0xBF
    ctx->r11 = ADD32(0, 0XBF);
    // 0x8018EFEC: addiu       $t5, $zero, 0x4A
    ctx->r13 = ADD32(0, 0X4A);
    // 0x8018EFF0: bgez        $t1, L_8018F000
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018EFF4: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8018F000;
    }
    // 0x8018EFF4: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8018EFF8: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8018EFFC: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8018F000:
    // 0x8018F000: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8018F004: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F008: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8018F00C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F010: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F014: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8018F018: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x8018F01C: sb          $t5, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r13;
    // 0x8018F020: sb          $t6, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r14;
    // 0x8018F024: sb          $t8, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r24;
    // 0x8018F028: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F02C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x8018F030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F038: jr          $ra
    // 0x8018F03C: nop

    return;
    // 0x8018F03C: nop

;}
RECOMP_FUNC void gcAddDObjRpyR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B590: jal         0x800092D0
    // 0x8000B594: nop

    gcAddDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8000B594: nop

    after_0:
    // 0x8000B598: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B59C: jal         0x8000B434
    // 0x8000B5A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyR(rdram, ctx);
        goto after_1;
    // 0x8000B5A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B5A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B5A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B5AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B5B0: jr          $ra
    // 0x8000B5B4: nop

    return;
    // 0x8000B5B4: nop

;}
RECOMP_FUNC void osEPiLinkHandle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032818: jal         0x80035820
    // 0x8003281C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8003281C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032820: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80032824: lw          $t6, -0x2BD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BD4);
    // 0x80032828: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8003282C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80032830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80032834: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80032838: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8003283C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80032840: jal         0x80035840
    // 0x80032844: sw          $t8, -0x2BD4($at)
    MEM_W(-0X2BD4, ctx->r1) = ctx->r24;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80032844: sw          $t8, -0x2BD4($at)
    MEM_W(-0X2BD4, ctx->r1) = ctx->r24;
    after_1:
    // 0x80032848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003284C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032854: jr          $ra
    // 0x80032858: nop

    return;
    // 0x80032858: nop

;}
RECOMP_FUNC void mvOpeningFoxMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCF0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DCF4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DCF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DCFC: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DD00: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD04: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD08: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD0C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD18: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD1C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD20: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD24: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD28: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD2C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD38: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD3C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD40: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD48: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD4C: jal         0x8000B93C
    // 0x8018DD50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD54: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD58: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD60: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DD64: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DD68: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DD6C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD70: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD74: jal         0x80007080
    // 0x8018DD78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DD7C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD80: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DD84: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DD88: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD8C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD90: jr          $ra
    // 0x8018DD94: nop

    return;
    // 0x8018DD94: nop

;}
RECOMP_FUNC void gcLinkGObjSPBefore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007AB0: lbu         $a2, 0xC($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XC);
    // 0x80007AB4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007AB8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007ABC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80007AC0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80007AC4: lw          $v0, 0x66F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66F0);
    // 0x80007AC8: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80007ACC: beq         $v0, $zero, L_80007B04
    if (ctx->r2 == 0) {
        // 0x80007AD0: nop
    
            goto L_80007B04;
    }
    // 0x80007AD0: nop

    // 0x80007AD4: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80007AD8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80007ADC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x80007AE0: beq         $at, $zero, L_80007B04
    if (ctx->r1 == 0) {
        // 0x80007AE4: nop
    
            goto L_80007B04;
    }
    // 0x80007AE4: nop

    // 0x80007AE8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80007AEC:
    // 0x80007AEC: beq         $v0, $zero, L_80007B04
    if (ctx->r2 == 0) {
        // 0x80007AF0: nop
    
            goto L_80007B04;
    }
    // 0x80007AF0: nop

    // 0x80007AF4: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80007AF8: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80007AFC: bnel        $at, $zero, L_80007AEC
    if (ctx->r1 != 0) {
        // 0x80007B00: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80007AEC;
    }
    goto skip_0;
    // 0x80007B00: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
L_80007B04:
    // 0x80007B04: beq         $v0, $zero, L_80007B14
    if (ctx->r2 == 0) {
        // 0x80007B08: nop
    
            goto L_80007B14;
    }
    // 0x80007B08: nop

    // 0x80007B0C: b           L_80007B18
    // 0x80007B10: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
        goto L_80007B18;
    // 0x80007B10: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
L_80007B14:
    // 0x80007B14: lw          $a1, 0x6778($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6778);
L_80007B18:
    // 0x80007B18: jal         0x800079D4
    // 0x80007B1C: nop

    gcLinkGObjAfter(rdram, ctx);
        goto after_0;
    // 0x80007B1C: nop

    after_0:
    // 0x80007B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007B28: jr          $ra
    // 0x80007B2C: nop

    return;
    // 0x80007B2C: nop

;}
RECOMP_FUNC void mnVSModeMakeTimeStockButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132D08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132D0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132D10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132D1C: jal         0x80009968
    // 0x80132D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132D20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D28: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132D2C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132D30: sw          $v0, 0x4938($at)
    MEM_W(0X4938, ctx->r1) = ctx->r2;
    // 0x80132D34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132D38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D3C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132D40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D44: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132D48: jal         0x80009DF4
    // 0x80132D4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132D4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D54: lui         $a1, 0x4294
    ctx->r5 = S32(0X4294 << 16);
    // 0x80132D58: lui         $a2, 0x42DA
    ctx->r6 = S32(0X42DA << 16);
    // 0x80132D5C: jal         0x80132024
    // 0x80132D60: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnVSModeMakeButton(rdram, ctx);
        goto after_2;
    // 0x80132D60: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80132D64: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132D68: lw          $t7, 0x4948($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4948);
    // 0x80132D6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D74: bne         $t7, $at, L_80132D84
    if (ctx->r15 != ctx->r1) {
        // 0x80132D78: nop
    
            goto L_80132D84;
    }
    // 0x80132D78: nop

    // 0x80132D7C: b           L_80132D84
    // 0x80132D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80132D84;
    // 0x80132D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80132D84:
    // 0x80132D84: jal         0x80131F4C
    // 0x80132D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSModeUpdateButton(rdram, ctx);
        goto after_3;
    // 0x80132D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80132D8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132D90: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x80132D94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D9C: beq         $v0, $zero, L_80132DAC
    if (ctx->r2 == 0) {
        // 0x80132DA0: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80132DAC;
    }
    // 0x80132DA0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132DA4: bne         $v0, $at, L_80132E50
    if (ctx->r2 != ctx->r1) {
        // 0x80132DA8: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132E50;
    }
    // 0x80132DA8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
L_80132DAC:
    // 0x80132DAC: lw          $t8, 0x4A4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4C);
    // 0x80132DB0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132DB4: addiu       $t9, $t9, 0x2EC8
    ctx->r25 = ADD32(ctx->r25, 0X2EC8);
    // 0x80132DB8: jal         0x800CCFDC
    // 0x80132DBC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132DBC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x80132DC0: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132DC4: lui         $at, 0x42C2
    ctx->r1 = S32(0X42C2 << 16);
    // 0x80132DC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DCC: lui         $at, 0x42E2
    ctx->r1 = S32(0X42E2 << 16);
    // 0x80132DD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DD4: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132DD8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132DDC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132DE0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132DE4: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132DE8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132DEC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132DF0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132DF4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132DF8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132DFC: lw          $t4, 0x4A4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4A4C);
    // 0x80132E00: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132E04: addiu       $t5, $t5, 0x2FC8
    ctx->r13 = ADD32(ctx->r13, 0X2FC8);
    // 0x80132E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132E0C: jal         0x800CCFDC
    // 0x80132E10: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132E10: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80132E14: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132E18: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x80132E1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132E20: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132E24: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132E28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132E2C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132E30: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132E34: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132E38: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132E3C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132E40: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132E44: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132E48: b           L_80132EA0
    // 0x80132E4C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_80132EA0;
    // 0x80132E4C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132E50:
    // 0x80132E50: lw          $t0, 0x4A4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4A4C);
    // 0x80132E54: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80132E58: addiu       $t1, $t1, 0x3248
    ctx->r9 = ADD32(ctx->r9, 0X3248);
    // 0x80132E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132E60: jal         0x800CCFDC
    // 0x80132E64: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132E64: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_6:
    // 0x80132E68: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80132E6C: lui         $at, 0x42D4
    ctx->r1 = S32(0X42D4 << 16);
    // 0x80132E70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132E74: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80132E78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132E7C: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80132E80: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132E84: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80132E88: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132E8C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132E90: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132E94: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132E98: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132E9C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
L_80132EA0:
    // 0x80132EA0: jal         0x80132964
    // 0x80132EA4: nop

    mnVSModeMakeTimeStockArrows(rdram, ctx);
        goto after_7;
    // 0x80132EA4: nop

    after_7:
    // 0x80132EA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132EAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132EB4: jr          $ra
    // 0x80132EB8: nop

    return;
    // 0x80132EB8: nop

;}
RECOMP_FUNC void gmCameraScreenFlashMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DDC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010DDC8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010DDCC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010DDD0: addiu       $t6, $t6, -0x23DC
    ctx->r14 = ADD32(ctx->r14, -0X23DC);
    // 0x8010DDD4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8010DDD8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010DDDC: lui         $t9, 0x40
    ctx->r25 = S32(0X40 << 16);
    // 0x8010DDE0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8010DDE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8010DDE8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010DDEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8010DDF0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8010DDF4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8010DDF8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010DDFC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010DE00: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010DE04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010DE08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010DE0C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010DE10: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010DE14: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8010DE18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010DE1C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010DE20: jal         0x8000B93C
    // 0x8010DE24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010DE24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010DE28: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8010DE2C: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x8010DE30: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8010DE34: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x8010DE38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010DE3C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010DE40: jr          $ra
    // 0x8010DE44: nop

    return;
    // 0x8010DE44: nop

;}
RECOMP_FUNC void func_ovl8_8037E824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037E824: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037E828: jr          $ra
    // 0x8037E82C: lhu         $v0, -0xFBA($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFBA);
    return;
    // 0x8037E82C: lhu         $v0, -0xFBA($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XFBA);
;}
RECOMP_FUNC void func_ovl8_8037D63C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D63C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037D640: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D648: addiu       $at, $at, -0x5770
    ctx->r1 = ADD32(ctx->r1, -0X5770);
    // 0x8037D64C: lwl         $t6, 0x0($at)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r1, 0X0);
    // 0x8037D650: lwr         $t6, 0x3($at)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r1, 0X3);
    // 0x8037D654: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D658: addiu       $at, $at, -0x576C
    ctx->r1 = ADD32(ctx->r1, -0X576C);
    // 0x8037D65C: swl         $t6, 0x1C($sp)
    do_swl(rdram, 0X1C, ctx->r29, ctx->r14);
    // 0x8037D660: swr         $t6, 0x1F($sp)
    do_swr(rdram, 0X1F, ctx->r29, ctx->r14);
    // 0x8037D664: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037D668: lwl         $t7, 0x0($at)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r1, 0X0);
    // 0x8037D66C: lwr         $t7, 0x3($at)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r1, 0X3);
    // 0x8037D670: addiu       $v0, $v0, -0x1000
    ctx->r2 = ADD32(ctx->r2, -0X1000);
    // 0x8037D674: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8037D678: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8037D67C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D680: swl         $t7, 0x18($sp)
    do_swl(rdram, 0X18, ctx->r29, ctx->r15);
    // 0x8037D684: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8037D688: sh          $zero, -0xFB8($at)
    MEM_H(-0XFB8, ctx->r1) = 0;
    // 0x8037D68C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8037D690: jal         0x8037D990
    // 0x8037D694: swr         $t7, 0x1B($sp)
    do_swr(rdram, 0X1B, ctx->r29, ctx->r15);
    func_ovl8_8037D990(rdram, ctx);
        goto after_0;
    // 0x8037D694: swr         $t7, 0x1B($sp)
    do_swr(rdram, 0X1B, ctx->r29, ctx->r15);
    after_0:
    // 0x8037D698: jal         0x8037D9D0
    // 0x8037D69C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_1;
    // 0x8037D69C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8037D6A0: jal         0x8037D9B4
    // 0x8037D6A4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_2;
    // 0x8037D6A4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8037D6A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8037D6AC: jal         0x8037D9EC
    // 0x8037D6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037D9EC(rdram, ctx);
        goto after_3;
    // 0x8037D6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8037D6B4: jal         0x8037D99C
    // 0x8037D6B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_ovl8_8037D99C(rdram, ctx);
        goto after_4;
    // 0x8037D6B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8037D6BC: jal         0x8037D9A8
    // 0x8037D6C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_ovl8_8037D9A8(rdram, ctx);
        goto after_5;
    // 0x8037D6C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8037D6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037D6C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037D6CC: jr          $ra
    // 0x8037D6D0: nop

    return;
    // 0x8037D6D0: nop

;}
RECOMP_FUNC void lbCommonAddMObjForFighterPartsDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C8CBC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C8CC0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C8CC4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C8CC8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C8CCC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800C8CD0: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800C8CD4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C8CD8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800C8CDC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C8CE0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C8CE4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C8CE8: beq         $a1, $zero, L_800C8D8C
    if (ctx->r5 == 0) {
        // 0x800C8CEC: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_800C8D8C;
    }
    // 0x800C8CEC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C8CF0: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x800C8CF4: beql        $a1, $zero, L_800C8D90
    if (ctx->r5 == 0) {
        // 0x800C8CF8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800C8D90;
    }
    goto skip_0;
    // 0x800C8CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800C8CFC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800C8D00: lwc1        $f20, 0x50($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X50);
L_800C8D04:
    // 0x800C8D04: jal         0x800090DC
    // 0x800C8D08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_0;
    // 0x800C8D08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800C8D0C: beq         $s1, $zero, L_800C8D48
    if (ctx->r17 == 0) {
        // 0x800C8D10: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8D48;
    }
    // 0x800C8D10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8D14: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800C8D18: beql        $a1, $zero, L_800C8D48
    if (ctx->r5 == 0) {
        // 0x800C8D1C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800C8D48;
    }
    goto skip_1;
    // 0x800C8D1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_1:
    // 0x800C8D20: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C8D24: jal         0x8000BD54
    // 0x800C8D28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x800C8D28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C8D2C: jal         0x8000CF6C
    // 0x800C8D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_2;
    // 0x800C8D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800C8D34: jal         0x8000DA40
    // 0x800C8D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_3;
    // 0x800C8D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800C8D3C: jal         0x80008FB0
    // 0x800C8D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveAObjFromMObj(rdram, ctx);
        goto after_4;
    // 0x800C8D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800C8D44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800C8D48:
    // 0x800C8D48: beql        $s2, $zero, L_800C8D80
    if (ctx->r18 == 0) {
        // 0x800C8D4C: lw          $a1, 0x4($s3)
        ctx->r5 = MEM_W(ctx->r19, 0X4);
            goto L_800C8D80;
    }
    goto skip_2;
    // 0x800C8D4C: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    skip_2:
    // 0x800C8D50: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800C8D54: beql        $a1, $zero, L_800C8D7C
    if (ctx->r5 == 0) {
        // 0x800C8D58: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800C8D7C;
    }
    goto skip_3;
    // 0x800C8D58: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_3:
    // 0x800C8D5C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800C8D60: jal         0x8000BD54
    // 0x800C8D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_5;
    // 0x800C8D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C8D68: jal         0x8000CF6C
    // 0x800C8D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_6;
    // 0x800C8D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800C8D70: jal         0x8000DA40
    // 0x800C8D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_7;
    // 0x800C8D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800C8D78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800C8D7C:
    // 0x800C8D7C: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
L_800C8D80:
    // 0x800C8D80: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800C8D84: bne         $a1, $zero, L_800C8D04
    if (ctx->r5 != 0) {
        // 0x800C8D88: nop
    
            goto L_800C8D04;
    }
    // 0x800C8D88: nop

L_800C8D8C:
    // 0x800C8D8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800C8D90:
    // 0x800C8D90: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C8D94: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C8D98: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C8D9C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8DA0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C8DA4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C8DA8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C8DAC: jr          $ra
    // 0x800C8DB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C8DB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mvOpeningMarioMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB60: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB68: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB6C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DB70: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DB74: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DB78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DB7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DB80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DB84: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DB88: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DB8C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DB90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DB94: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DB98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DB9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBA0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DBA4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DBA8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBAC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBB8: jal         0x8000B93C
    // 0x8018DBBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBC0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBC8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBCC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DBD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DBD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DBD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DBDC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DBE0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DBE4: jal         0x80007080
    // 0x8018DBE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DBE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DBEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DBF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DBF4: jr          $ra
    // 0x8018DBF8: nop

    return;
    // 0x8018DBF8: nop

;}
RECOMP_FUNC void func_ovl2_800FDBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDBFC: jr          $ra
    // 0x800FDC00: nop

    return;
    // 0x800FDC00: nop

;}
RECOMP_FUNC void itRShellCommonProcStatusWaitOrSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A96C: jal         0x8017A83C
    // 0x8017A970: nop

    itRShellCommonSetStatusWaitOrSpin(rdram, ctx);
        goto after_0;
    // 0x8017A970: nop

    after_0:
    // 0x8017A974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A97C: jr          $ra
    // 0x8017A980: nop

    return;
    // 0x8017A980: nop

;}
RECOMP_FUNC void func_ovl8_803751C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803751C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803751C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803751C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803751CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803751D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803751D4: bne         $a0, $zero, L_803751EC
    if (ctx->r4 != 0) {
        // 0x803751D8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803751EC;
    }
    // 0x803751D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803751DC: jal         0x803717A0
    // 0x803751E0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803751E0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x803751E4: beq         $v0, $zero, L_8037525C
    if (ctx->r2 == 0) {
        // 0x803751E8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037525C;
    }
    // 0x803751E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803751EC:
    // 0x803751EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803751F0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x803751F4: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    // 0x803751F8: bnel        $t6, $zero, L_8037521C
    if (ctx->r14 != 0) {
        // 0x803751FC: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8037521C;
    }
    goto skip_0;
    // 0x803751FC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80375200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80375204: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80375208: jal         0x803717E0
    // 0x8037520C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037520C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80375210: jal         0x8037C2D0
    // 0x80375214: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80375214: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80375218: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8037521C:
    // 0x8037521C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80375220: addiu       $t9, $t9, -0x6990
    ctx->r25 = ADD32(ctx->r25, -0X6990);
    // 0x80375224: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x80375228: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8037522C: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80375230: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80375234: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x80375238: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8037523C: addiu       $t0, $t0, -0x6958
    ctx->r8 = ADD32(ctx->r8, -0X6958);
    // 0x80375240: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80375244: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x80375248: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8037524C: addiu       $t2, $t2, -0x6800
    ctx->r10 = ADD32(ctx->r10, -0X6800);
    // 0x80375250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80375254: jal         0x8037588C
    // 0x80375258: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    func_ovl8_8037588C(rdram, ctx);
        goto after_3;
    // 0x80375258: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_3:
L_8037525C:
    // 0x8037525C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80375260: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80375264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80375268: jr          $ra
    // 0x8037526C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037526C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftKirbySpecialAirNWaitSetStatusFromEat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801634C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801634C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801634C8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801634CC: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801634D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801634D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801634D8: addiu       $a1, $zero, 0x11C
    ctx->r5 = ADD32(0, 0X11C);
    // 0x801634DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801634E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801634E4: jal         0x800E6F24
    // 0x801634E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801634E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801634EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801634F0: jal         0x800E8098
    // 0x801634F4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801634F4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x801634F8: jal         0x800E0830
    // 0x801634FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801634FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163508: jr          $ra
    // 0x8016350C: nop

    return;
    // 0x8016350C: nop

;}

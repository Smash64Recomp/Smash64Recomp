#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningRoomBackgroundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80131B5C: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
    // 0x80131B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B68: slti        $at, $v0, 0x439
    ctx->r1 = SIGNED(ctx->r2) < 0X439 ? 1 : 0;
    // 0x80131B6C: bne         $at, $zero, L_80131B84
    if (ctx->r1 != 0) {
        // 0x80131B70: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80131B84;
    }
    // 0x80131B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131B74: jal         0x8000DF34
    // 0x80131B78: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80131B78: nop

    after_0:
    // 0x80131B7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80131B80: lw          $v0, 0x4CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4CE4);
L_80131B84:
    // 0x80131B84: addiu       $at, $zero, 0x474
    ctx->r1 = ADD32(0, 0X474);
    // 0x80131B88: bnel        $v0, $at, L_80131B9C
    if (ctx->r2 != ctx->r1) {
        // 0x80131B8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131B9C;
    }
    goto skip_0;
    // 0x80131B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80131B90: jal         0x80009A84
    // 0x80131B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80131B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80131B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131B9C:
    // 0x80131B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131BA0: jr          $ra
    // 0x80131BA4: nop

    return;
    // 0x80131BA4: nop

;}
RECOMP_FUNC void mvOpeningDonkeyMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D93C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D944: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D948: jal         0x80009968
    // 0x8018D94C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D94C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D950: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D954: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D958: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D95C: addiu       $a1, $a1, -0x27CC
    ctx->r5 = ADD32(ctx->r5, -0X27CC);
    // 0x8018D960: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D964: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D968: jal         0x80009DF4
    // 0x8018D96C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D96C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D978: jr          $ra
    // 0x8018D97C: nop

    return;
    // 0x8018D97C: nop

;}
RECOMP_FUNC void itTomatoFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801744C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801744C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801744C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801744CC: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x801744D0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801744D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801744D8: jal         0x80172558
    // 0x801744DC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801744DC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x801744E0: jal         0x801713F4
    // 0x801744E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x801744E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801744E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801744EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801744F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801744F4: jr          $ra
    // 0x801744F8: nop

    return;
    // 0x801744F8: nop

;}
RECOMP_FUNC void ftCommonDashProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EA44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EA48: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013EA4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8013EA50: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013EA54: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8013EA58: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013EA5C: nop

    // 0x8013EA60: bc1fl       L_8013EA84
    if (!c1cs) {
        // 0x8013EA64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013EA84;
    }
    goto skip_0;
    // 0x8013EA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013EA68: lwc1        $f8, 0x60($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8013EA6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013EA70: nop

    // 0x8013EA74: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8013EA78: jal         0x8013E1C8
    // 0x8013EA7C: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013EA7C: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    after_0:
    // 0x8013EA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013EA84:
    // 0x8013EA84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EA88: jr          $ra
    // 0x8013EA8C: nop

    return;
    // 0x8013EA8C: nop

;}
RECOMP_FUNC void itMBallOpenClearAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C6F8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017C6FC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8017C700: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8017C704: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x8017C708: jr          $ra
    // 0x8017C70C: sw          $zero, 0x94($t8)
    MEM_W(0X94, ctx->r24) = 0;
    return;
    // 0x8017C70C: sw          $zero, 0x94($t8)
    MEM_W(0X94, ctx->r24) = 0;
;}
RECOMP_FUNC void itKamexFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801807DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801807E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801807E4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801807E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801807EC: jal         0x80172558
    // 0x801807F0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801807F0: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x801807F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801807F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801807FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180800: jr          $ra
    // 0x80180804: nop

    return;
    // 0x80180804: nop

;}
RECOMP_FUNC void ifCommonTimerMakeDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112F68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80112F6C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80112F70: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x80112F74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80112F78: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80112F7C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80112F80: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80112F84: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80112F88: beq         $t7, $zero, L_80112FA0
    if (ctx->r15 == 0) {
        // 0x80112F8C: nop
    
            goto L_80112FA0;
    }
    // 0x80112F8C: nop

    // 0x80112F90: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80112F94: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80112F98: bne         $t8, $at, L_80112FA8
    if (ctx->r24 != ctx->r1) {
        // 0x80112F9C: nop
    
            goto L_80112FA8;
    }
    // 0x80112F9C: nop

L_80112FA0:
    // 0x80112FA0: b           L_801130F0
    // 0x80112FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801130F0;
    // 0x80112FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80112FA8:
    // 0x80112FA8: jal         0x80112EBC
    // 0x80112FAC: nop

    ifCommonTimerSetAttr(rdram, ctx);
        goto after_0;
    // 0x80112FAC: nop

    after_0:
    // 0x80112FB0: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80112FB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80112FB8: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112FC0: jal         0x80009968
    // 0x80112FC4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80112FC4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_1:
    // 0x80112FC8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80112FCC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80112FD0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80112FD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80112FD8: addiu       $a1, $a1, 0x2C18
    ctx->r5 = ADD32(ctx->r5, 0X2C18);
    // 0x80112FDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112FE0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80112FE4: jal         0x80009DF4
    // 0x80112FE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80112FE8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x80112FEC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80112FF0: lw          $t0, 0xD4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD4C);
    // 0x80112FF4: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x80112FF8: addiu       $s0, $s0, 0x138
    ctx->r16 = ADD32(ctx->r16, 0X138);
    // 0x80112FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80113000: jal         0x800CCFDC
    // 0x80113004: addu        $a1, $t0, $s0
    ctx->r5 = ADD32(ctx->r8, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80113004: addu        $a1, $t0, $s0
    ctx->r5 = ADD32(ctx->r8, ctx->r16);
    after_3:
    // 0x80113008: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8011300C: lw          $t1, 0xD4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD4C);
    // 0x80113010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80113014: jal         0x800CCFDC
    // 0x80113018: addu        $a1, $t1, $s0
    ctx->r5 = ADD32(ctx->r9, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80113018: addu        $a1, $t1, $s0
    ctx->r5 = ADD32(ctx->r9, ctx->r16);
    after_4:
    // 0x8011301C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80113020: lw          $t2, 0xD4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XD4C);
    // 0x80113024: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80113028: jal         0x800CCFDC
    // 0x8011302C: addu        $a1, $t2, $s0
    ctx->r5 = ADD32(ctx->r10, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8011302C: addu        $a1, $t2, $s0
    ctx->r5 = ADD32(ctx->r10, ctx->r16);
    after_5:
    // 0x80113030: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80113034: lw          $t3, 0xD4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD4C);
    // 0x80113038: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8011303C: jal         0x800CCFDC
    // 0x80113040: addu        $a1, $t3, $s0
    ctx->r5 = ADD32(ctx->r11, ctx->r16);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80113040: addu        $a1, $t3, $s0
    ctx->r5 = ADD32(ctx->r11, ctx->r16);
    after_6:
    // 0x80113044: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80113048: lw          $t4, 0xD4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD4C);
    // 0x8011304C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80113050: addiu       $t5, $t5, 0xF08
    ctx->r13 = ADD32(ctx->r13, 0XF08);
    // 0x80113054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80113058: jal         0x800CCFDC
    // 0x8011305C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x8011305C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x80113060: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x80113064: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80113068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8011306C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80113070: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x80113074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80113078: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8011307C: lh          $t9, 0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X16);
    // 0x80113080: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80113084: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80113088: addiu       $a0, $a0, 0x17C8
    ctx->r4 = ADD32(ctx->r4, 0X17C8);
    // 0x8011308C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80113090: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80113094: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80113098: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8011309C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801130A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801130A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801130A8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x801130AC: nop

    // 0x801130B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801130B4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801130B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801130BC: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x801130C0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801130C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801130C8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801130CC: nop

    // 0x801130D0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801130D4: nop

    // 0x801130D8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801130DC: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x801130E0: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x801130E4: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x801130E8: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x801130EC: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
L_801130F0:
    // 0x801130F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801130F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801130F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801130FC: jr          $ra
    // 0x80113100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80113100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftBossDeadRightSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AE80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015AE84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015AE88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015AE8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AE90: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8015AE94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015AE98: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
    // 0x8015AE9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015AEA0: addiu       $a1, $zero, 0xFB
    ctx->r5 = ADD32(0, 0XFB);
    // 0x8015AEA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015AEA8: jal         0x800E6F24
    // 0x8015AEAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AEAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015AEB0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015AEB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015AEB8: nop

    // 0x8015AEBC: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x8015AEC0: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x8015AEC4: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8015AEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015AECC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015AED0: jr          $ra
    // 0x8015AED4: nop

    return;
    // 0x8015AED4: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800388B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800388B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800388B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800388BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800388C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800388C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800388C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800388CC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800388D0: jal         0x80030ABC
    // 0x800388D4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800388D4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800388D8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800388DC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800388E0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800388E4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800388E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800388EC: jal         0x80030B18
    // 0x800388F0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800388F0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800388F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800388F8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800388FC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80038900: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80038904: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80038908: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8003890C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x80038910: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80038914: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80038918: bgtz        $t0, L_80038978
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003891C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80038978;
    }
    // 0x8003891C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80038920: bltz        $t0, L_80038930
    if (SIGNED(ctx->r8) < 0) {
        // 0x80038924: nop
    
            goto L_80038930;
    }
    // 0x80038924: nop

    // 0x80038928: b           L_8003897C
    // 0x8003892C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_8003897C;
    // 0x8003892C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80038930:
    // 0x80038930: bltzl       $t8, L_8003897C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80038934: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8003897C;
    }
    goto skip_0;
    // 0x80038934: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x80038938: bgtz        $t8, L_80038948
    if (SIGNED(ctx->r24) > 0) {
        // 0x8003893C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_80038948;
    }
    // 0x8003893C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80038940: beql        $t9, $zero, L_8003897C
    if (ctx->r25 == 0) {
        // 0x80038944: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8003897C;
    }
    goto skip_1;
    // 0x80038944: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_80038948:
    // 0x80038948: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003894C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80038950: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80038954: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80038958: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x8003895C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80038960: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80038964: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80038968: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8003896C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80038970: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80038974: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80038978:
    // 0x80038978: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_8003897C:
    // 0x8003897C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80038980: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80038984: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80038988: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8003898C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80038990: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80038994: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80038998: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x8003899C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800389A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800389A8: jr          $ra
    // 0x800389AC: nop

    return;
    // 0x800389AC: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicapArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801359D8: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x801359DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x801359E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x801359E4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x801359E8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801359EC: addiu       $t6, $v1, 0x15
    ctx->r14 = ADD32(ctx->r3, 0X15);
    // 0x801359F0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801359F4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801359F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801359FC: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135A00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135A04: addiu       $t7, $v1, 0x2B
    ctx->r15 = ADD32(ctx->r3, 0X2B);
    // 0x80135A08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135A0C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135A10: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135A14: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80135A18: nop

    // 0x80135A1C: bc1f        L_80135A48
    if (!c1cs) {
        // 0x80135A20: nop
    
            goto L_80135A48;
    }
    // 0x80135A20: nop

    // 0x80135A24: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80135A28: nop

    // 0x80135A2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80135A30: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80135A34: nop

    // 0x80135A38: bc1f        L_80135A48
    if (!c1cs) {
        // 0x80135A3C: nop
    
            goto L_80135A48;
    }
    // 0x80135A3C: nop

    // 0x80135A40: b           L_80135A48
    // 0x80135A44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135A48;
    // 0x80135A44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135A48:
    // 0x80135A48: beql        $v1, $zero, L_80135AB0
    if (ctx->r3 == 0) {
        // 0x80135A4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135AB0;
    }
    goto skip_0;
    // 0x80135A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80135A50: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135A58: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x80135A5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135A60: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135A64: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80135A68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135A6C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80135A70: nop

    // 0x80135A74: bc1f        L_80135A9C
    if (!c1cs) {
        // 0x80135A78: nop
    
            goto L_80135A9C;
    }
    // 0x80135A78: nop

    // 0x80135A7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135A80: nop

    // 0x80135A84: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135A88: nop

    // 0x80135A8C: bc1f        L_80135A9C
    if (!c1cs) {
        // 0x80135A90: nop
    
            goto L_80135A9C;
    }
    // 0x80135A90: nop

    // 0x80135A94: b           L_80135A9C
    // 0x80135A98: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135A9C;
    // 0x80135A98: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135A9C:
    // 0x80135A9C: beql        $v1, $zero, L_80135AB0
    if (ctx->r3 == 0) {
        // 0x80135AA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135AB0;
    }
    goto skip_1;
    // 0x80135AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80135AA4: jr          $ra
    // 0x80135AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80135AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135AB0:
    // 0x80135AB0: jr          $ra
    // 0x80135AB4: nop

    return;
    // 0x80135AB4: nop

;}
RECOMP_FUNC void scExplainTapSparkProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D9BC: jal         0x8000DF34
    // 0x8018D9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x8018D9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018D9C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D9CC: lwc1        $f4, -0x1820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1820);
    // 0x8018D9D0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8018D9D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D9D8: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8018D9DC: lwc1        $f6, 0x98($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X98);
    // 0x8018D9E0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8018D9E4: nop

    // 0x8018D9E8: bc1fl       L_8018D9F8
    if (!c1cs) {
        // 0x8018D9EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D9F8;
    }
    goto skip_0;
    // 0x8018D9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D9F0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    // 0x8018D9F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D9F8:
    // 0x8018D9F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D9FC: jr          $ra
    // 0x8018DA00: nop

    return;
    // 0x8018DA00: nop

;}
RECOMP_FUNC void unref_80017E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017E14: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80017E18: addiu       $a1, $a1, 0x65B8
    ctx->r5 = ADD32(ctx->r5, 0X65B8);
    // 0x80017E1C: jal         0x80017D3C
    // 0x80017E20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80017D3C(rdram, ctx);
        goto after_0;
    // 0x80017E20: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80017E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017E2C: jr          $ra
    // 0x80017E30: nop

    return;
    // 0x80017E30: nop

;}
RECOMP_FUNC void itMapProcAllCheckCollEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801735E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801735E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801735E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801735EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801735F0: lw          $t6, 0x84($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X84);
    // 0x801735F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801735F8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801735FC: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x80173600: jal         0x800DB838
    // 0x80173604: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x80173604: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x80173608: beq         $v0, $zero, L_80173614
    if (ctx->r2 == 0) {
        // 0x8017360C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80173614;
    }
    // 0x8017360C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80173610: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_80173614:
    // 0x80173614: jal         0x800DC3C8
    // 0x80173618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x80173618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8017361C: beq         $v0, $zero, L_80173628
    if (ctx->r2 == 0) {
        // 0x80173620: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80173628;
    }
    // 0x80173620: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80173624: sw          $t9, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r25;
L_80173628:
    // 0x80173628: jal         0x800DCF58
    // 0x8017362C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x8017362C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80173630: beq         $v0, $zero, L_8017363C
    if (ctx->r2 == 0) {
        // 0x80173634: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8017363C;
    }
    // 0x80173634: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80173638: sw          $t0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r8;
L_8017363C:
    // 0x8017363C: jal         0x800DD578
    // 0x80173640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_3;
    // 0x80173640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80173644: beq         $v0, $zero, L_8017366C
    if (ctx->r2 == 0) {
        // 0x80173648: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8017366C;
    }
    // 0x80173648: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017364C: sw          $t1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r9;
    // 0x80173650: jal         0x800269C0
    // 0x80173654: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80173654: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_4:
    // 0x80173658: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017365C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80173660: swc1        $f0, 0x344($t2)
    MEM_W(0X344, ctx->r10) = ctx->f0.u32l;
    // 0x80173664: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80173668: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
L_8017366C:
    // 0x8017366C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173670: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80173674: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80173678: jr          $ra
    // 0x8017367C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8017367C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efManagerDefaultProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FDB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDB90: lw          $a1, 0xBC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XBC);
    // 0x800FDB94: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FDB98: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x800FDB9C: beq         $v0, $zero, L_800FDBB4
    if (ctx->r2 == 0) {
        // 0x800FDBA0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FDBB4;
    }
    // 0x800FDBA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FDBA4: jal         0x800FD4F8
    // 0x800FDBA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x800FDBA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FDBAC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800FDBB0: lw          $a1, 0xBC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XBC);
L_800FDBB4:
    // 0x800FDBB4: jal         0x80009A84
    // 0x800FDBB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800FDBB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800FDBBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDBC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FDBC4: jr          $ra
    // 0x800FDBC8: nop

    return;
    // 0x800FDBC8: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014DF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014DF1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014DF20: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8014DF24: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014DF28: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x8014DF2C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8014DF30: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x8014DF34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014DF38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014DF3C: bne         $t6, $zero, L_8014DF50
    if (ctx->r14 != 0) {
        // 0x8014DF40: nop
    
            goto L_8014DF50;
    }
    // 0x8014DF40: nop

    // 0x8014DF44: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x8014DF48: b           L_8014DF50
    // 0x8014DF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014DF50;
    // 0x8014DF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014DF50:
    // 0x8014DF50: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8014DF54: jal         0x800E6F24
    // 0x8014DF58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014DF58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014DF5C: jal         0x800E0830
    // 0x8014DF60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014DF60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8014DF64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014DF68: jal         0x800E8098
    // 0x8014DF6C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014DF6C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x8014DF70: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8014DF74: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8014DF78: beq         $v0, $zero, L_8014DF94
    if (ctx->r2 == 0) {
        // 0x8014DF7C: sw          $v0, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = ctx->r2;
            goto L_8014DF94;
    }
    // 0x8014DF7C: sw          $v0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r2;
    // 0x8014DF80: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x8014DF84: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8014DF88: sw          $t9, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r25;
    // 0x8014DF8C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8014DF90: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
L_8014DF94:
    // 0x8014DF94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014DF98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014DF9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014DFA0: jr          $ra
    // 0x8014DFA4: nop

    return;
    // 0x8014DFA4: nop

;}
RECOMP_FUNC void sc1PIntroGetVSNameOffsetX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801328F8: lw          $t6, 0x5C2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C2C);
    // 0x801328FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132900: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80132904: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80132908: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x8013290C: lh          $t9, 0x14($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X14);
    // 0x80132910: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80132914: jr          $ra
    // 0x80132918: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    return;
    // 0x80132918: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
;}
RECOMP_FUNC void ifCommonTimerFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80113108: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8011310C: lw          $t6, 0x1800($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1800);
    // 0x80113110: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80113114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80113118: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8011311C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80113120: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80113124: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80113128: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8011312C: beq         $t6, $zero, L_80113374
    if (ctx->r14 == 0) {
        // 0x80113130: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80113374;
    }
    // 0x80113130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80113134: jal         0x8000092C
    // 0x80113138: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_0;
    // 0x80113138: nop

    after_0:
    // 0x8011313C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80113140: lw          $t7, 0x17FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X17FC);
    // 0x80113144: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80113148: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8011314C: subu        $a1, $v0, $t7
    ctx->r5 = SUB32(ctx->r2, ctx->r15);
    // 0x80113150: beq         $a1, $zero, L_80113374
    if (ctx->r5 == 0) {
        // 0x80113154: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80113374;
    }
    // 0x80113154: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80113158: sw          $v0, 0x17FC($at)
    MEM_W(0X17FC, ctx->r1) = ctx->r2;
    // 0x8011315C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80113160: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x80113164: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80113168: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x8011316C: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80113170: lbu         $t0, 0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X3);
    // 0x80113174: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80113178: beql        $t1, $zero, L_80113378
    if (ctx->r9 == 0) {
        // 0x8011317C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80113378;
    }
    goto skip_0;
    // 0x8011317C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80113180: lbu         $t2, 0x6($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X6);
    // 0x80113184: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80113188: beql        $t2, $at, L_80113378
    if (ctx->r10 == ctx->r1) {
        // 0x8011318C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80113378;
    }
    goto skip_1;
    // 0x8011318C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80113190: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    // 0x80113194: beq         $v1, $zero, L_80113374
    if (ctx->r3 == 0) {
        // 0x80113198: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_80113374;
    }
    // 0x80113198: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8011319C: beq         $at, $zero, L_801131AC
    if (ctx->r1 == 0) {
        // 0x801131A0: subu        $t3, $v1, $a1
        ctx->r11 = SUB32(ctx->r3, ctx->r5);
            goto L_801131AC;
    }
    // 0x801131A0: subu        $t3, $v1, $a1
    ctx->r11 = SUB32(ctx->r3, ctx->r5);
    // 0x801131A4: b           L_801131B0
    // 0x801131A8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
        goto L_801131B0;
    // 0x801131A8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
L_801131AC:
    // 0x801131AC: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
L_801131B0:
    // 0x801131B0: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x801131B4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801131B8: lbu         $t4, 0x1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1);
    // 0x801131BC: bnel        $t4, $at, L_80113200
    if (ctx->r12 != ctx->r1) {
        // 0x801131C0: lw          $v1, 0x14($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X14);
            goto L_80113200;
    }
    goto skip_2;
    // 0x801131C0: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    skip_2:
    // 0x801131C4: lw          $t5, 0x14($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14);
    // 0x801131C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801131CC: addiu       $v1, $v1, 0x13A0
    ctx->r3 = ADD32(ctx->r3, 0X13A0);
    // 0x801131D0: sltiu       $at, $t5, 0x709
    ctx->r1 = ctx->r13 < 0X709 ? 1 : 0;
    // 0x801131D4: beql        $at, $zero, L_80113200
    if (ctx->r1 == 0) {
        // 0x801131D8: lw          $v1, 0x14($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X14);
            goto L_80113200;
    }
    goto skip_3;
    // 0x801131D8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    skip_3:
    // 0x801131DC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801131E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801131E4: beql        $v0, $t6, L_80113200
    if (ctx->r2 == ctx->r14) {
        // 0x801131E8: lw          $v1, 0x14($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X14);
            goto L_80113200;
    }
    goto skip_4;
    // 0x801131E8: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
    skip_4:
    // 0x801131EC: jal         0x800E7B54
    // 0x801131F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_1;
    // 0x801131F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_1:
    // 0x801131F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x801131F8: lw          $a0, 0x50E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50E8);
    // 0x801131FC: lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14);
L_80113200:
    // 0x80113200: sltiu       $at, $v1, 0x12D
    ctx->r1 = ctx->r3 < 0X12D ? 1 : 0;
    // 0x80113204: beql        $at, $zero, L_80113378
    if (ctx->r1 == 0) {
        // 0x80113208: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80113378;
    }
    goto skip_5;
    // 0x80113208: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x8011320C: bne         $v1, $zero, L_80113238
    if (ctx->r3 != 0) {
        // 0x80113210: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_80113238;
    }
    // 0x80113210: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80113214: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80113218: jalr        $t9
    // 0x8011321C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8011321C: nop

    after_2:
    // 0x80113220: jal         0x80009A84
    // 0x80113224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80113224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80113228: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8011322C: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80113230: b           L_801132A4
    // 0x80113234: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
        goto L_801132A4;
    // 0x80113234: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
L_80113238:
    // 0x80113238: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8011323C: addiu       $s3, $s3, -0x10B8
    ctx->r19 = ADD32(ctx->r19, -0X10B8);
    // 0x80113240: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80113244: addiu       $s1, $s1, 0x185C
    ctx->r17 = ADD32(ctx->r17, 0X185C);
    // 0x80113248: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8011324C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80113250: addiu       $s2, $zero, 0x3C
    ctx->r18 = ADD32(0, 0X3C);
L_80113254:
    // 0x80113254: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x80113258: bnel        $t8, $zero, L_8011329C
    if (ctx->r24 != 0) {
        // 0x8011325C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8011329C;
    }
    goto skip_6;
    // 0x8011325C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x80113260: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80113264: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x80113268: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x8011326C: mflo        $t0
    ctx->r8 = lo;
    // 0x80113270: addiu       $t1, $t0, 0x3C
    ctx->r9 = ADD32(ctx->r8, 0X3C);
    // 0x80113274: sltu        $at, $t1, $v1
    ctx->r1 = ctx->r9 < ctx->r3 ? 1 : 0;
    // 0x80113278: bnel        $at, $zero, L_8011329C
    if (ctx->r1 != 0) {
        // 0x8011327C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8011329C;
    }
    goto skip_7;
    // 0x8011327C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_7:
    // 0x80113280: jal         0x800269C0
    // 0x80113284: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80113284: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    after_4:
    // 0x80113288: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // 0x8011328C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80113290: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x80113294: lw          $v1, 0x14($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X14);
    // 0x80113298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8011329C:
    // 0x8011329C: bne         $s0, $s5, L_80113254
    if (ctx->r16 != ctx->r21) {
        // 0x801132A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80113254;
    }
    // 0x801132A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801132A4:
    // 0x801132A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801132A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801132AC: bgez        $v1, L_801132C4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801132B0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801132C4;
    }
    // 0x801132B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801132B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801132B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801132BC: nop

    // 0x801132C0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801132C4:
    // 0x801132C4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801132C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801132CC: lui         $at, 0x46A0
    ctx->r1 = S32(0X46A0 << 16);
    // 0x801132D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801132D4: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801132D8: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x801132DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801132E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801132E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801132E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801132EC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801132F0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801132F4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x801132F8: nop

    // 0x801132FC: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80113300: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80113304: nop

    // 0x80113308: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8011330C: beql        $a1, $zero, L_8011335C
    if (ctx->r5 == 0) {
        // 0x80113310: mfc1        $a1, $f10
        ctx->r5 = (int32_t)ctx->f10.u32l;
            goto L_8011335C;
    }
    goto skip_8;
    // 0x80113310: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    skip_8:
    // 0x80113314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80113318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8011331C: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80113320: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80113324: nop

    // 0x80113328: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8011332C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80113330: nop

    // 0x80113334: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80113338: bne         $a1, $zero, L_80113350
    if (ctx->r5 != 0) {
        // 0x8011333C: nop
    
            goto L_80113350;
    }
    // 0x8011333C: nop

    // 0x80113340: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80113344: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80113348: b           L_80113368
    // 0x8011334C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80113368;
    // 0x8011334C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80113350:
    // 0x80113350: b           L_80113368
    // 0x80113354: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80113368;
    // 0x80113354: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80113358: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
L_8011335C:
    // 0x8011335C: nop

    // 0x80113360: bltz        $a1, L_80113350
    if (SIGNED(ctx->r5) < 0) {
        // 0x80113364: nop
    
            goto L_80113350;
    }
    // 0x80113364: nop

L_80113368:
    // 0x80113368: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8011336C: jal         0x80020B38
    // 0x80113370: nop

    syAudioSetBGMVolume(rdram, ctx);
        goto after_5;
    // 0x80113370: nop

    after_5:
L_80113374:
    // 0x80113374: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80113378:
    // 0x80113378: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8011337C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80113380: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80113384: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80113388: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8011338C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80113390: jr          $ra
    // 0x80113394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80113394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80372DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372DE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372DEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372DF0: jal         0x80373160
    // 0x80372DF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x80372DF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80372DF8: beq         $v0, $zero, L_80372E2C
    if (ctx->r2 == 0) {
        // 0x80372DFC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80372E2C;
    }
    // 0x80372DFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80372E00: beql        $v0, $zero, L_80372E30
    if (ctx->r2 == 0) {
        // 0x80372E04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80372E30;
    }
    goto skip_0;
    // 0x80372E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80372E08: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_80372E0C:
    // 0x80372E0C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80372E10: lw          $t9, 0x114($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X114);
    // 0x80372E14: lh          $t6, 0x110($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X110);
    // 0x80372E18: jalr        $t9
    // 0x80372E1C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372E1C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x80372E20: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    // 0x80372E24: bnel        $s0, $zero, L_80372E0C
    if (ctx->r16 != 0) {
        // 0x80372E28: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80372E0C;
    }
    goto skip_1;
    // 0x80372E28: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_1:
L_80372E2C:
    // 0x80372E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80372E30:
    // 0x80372E30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80372E34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80372E38: jr          $ra
    // 0x80372E3C: nop

    return;
    // 0x80372E3C: nop

;}
RECOMP_FUNC void syMatrixTra(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B9C4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8001B9C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B9CC: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8001B9D0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B9D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B9D8: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001B9DC: lui         $a3, 0xFFFF
    ctx->r7 = S32(0XFFFF << 16);
    // 0x8001B9E0: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x8001B9E4: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001B9E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001B9EC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x8001B9F0: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8001B9F4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8001B9F8: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8001B9FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001BA00: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8001BA04: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8001BA08: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001BA0C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8001BA10: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8001BA14: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8001BA18: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8001BA1C: and         $t9, $v1, $a3
    ctx->r25 = ctx->r3 & ctx->r7;
    // 0x8001BA20: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x8001BA24: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x8001BA28: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8001BA2C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8001BA30: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8001BA34: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8001BA38: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8001BA3C: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x8001BA40: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8001BA44: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8001BA48: sw          $t4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r12;
    // 0x8001BA4C: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001BA50: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001BA54: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001BA58: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001BA5C: nop

    // 0x8001BA60: and         $t6, $a1, $a3
    ctx->r14 = ctx->r5 & ctx->r7;
    // 0x8001BA64: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8001BA68: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x8001BA6C: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8001BA70: jr          $ra
    // 0x8001BA74: sw          $t8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r24;
    return;
    // 0x8001BA74: sw          $t8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void ftCommonWalkProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E390: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013E394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013E39C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013E3A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013E3A4: jal         0x80151098
    // 0x8013E3A8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013E3A8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013E3AC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E3B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_0;
    // 0x8013E3B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013E3B4: jal         0x80151160
    // 0x8013E3B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013E3B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013E3BC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E3C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_1;
    // 0x8013E3C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013E3C4: jal         0x801511E0
    // 0x8013E3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013E3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013E3CC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E3D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_2;
    // 0x8013E3D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013E3D4: jal         0x80149CE0
    // 0x8013E3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x8013E3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013E3DC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E3E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_3;
    // 0x8013E3E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013E3E4: jal         0x80150470
    // 0x8013E3E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8013E3E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013E3EC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E3F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_4;
    // 0x8013E3F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8013E3F4: jal         0x8015070C
    // 0x8013E3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x8013E3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013E3FC: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_5;
    // 0x8013E400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8013E404: jal         0x80150884
    // 0x8013E408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x8013E408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013E40C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E410: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_6;
    // 0x8013E410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8013E414: jal         0x8014F8C0
    // 0x8013E418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x8013E418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013E41C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E420: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_7;
    // 0x8013E420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8013E424: jal         0x8014FB1C
    // 0x8013E428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8013E428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8013E42C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E430: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_8;
    // 0x8013E430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8013E434: jal         0x8014FD70
    // 0x8013E438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x8013E438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8013E43C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E440: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_9;
    // 0x8013E440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8013E444: jal         0x8014EC78
    // 0x8013E448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8013E448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8013E44C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E450: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_10;
    // 0x8013E450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8013E454: jal         0x80148D0C
    // 0x8013E458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8013E458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013E45C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E460: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_11;
    // 0x8013E460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8013E464: jal         0x8014E764
    // 0x8013E468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8013E468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8013E46C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E470: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_12;
    // 0x8013E470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x8013E474: jal         0x8013F4D0
    // 0x8013E478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8013E478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8013E47C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E480: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_13;
    // 0x8013E480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x8013E484: jal         0x8013ED64
    // 0x8013E488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x8013E488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8013E48C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E490: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_14;
    // 0x8013E490: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x8013E494: jal         0x8014310C
    // 0x8013E498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x8013E498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8013E49C: bnel        $v0, $zero, L_8013E538
    if (ctx->r2 != 0) {
        // 0x8013E4A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_15;
    // 0x8013E4A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x8013E4A4: jal         0x8013E2A0
    // 0x8013E4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWaitCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x8013E4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8013E4AC: bne         $v0, $zero, L_8013E534
    if (ctx->r2 != 0) {
        // 0x8013E4B0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8013E534;
    }
    // 0x8013E4B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8013E4B4: lb          $v0, 0x1C2($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X1C2);
    // 0x8013E4B8: bgez        $v0, L_8013E4C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8013E4BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8013E4C8;
    }
    // 0x8013E4BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013E4C0: b           L_8013E4C8
    // 0x8013E4C4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8013E4C8;
    // 0x8013E4C4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8013E4C8:
    // 0x8013E4C8: sll         $a0, $v1, 24
    ctx->r4 = S32(ctx->r3 << 24);
    // 0x8013E4CC: jal         0x8013E340
    // 0x8013E4D0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    ftCommonWalkGetWalkStatus(rdram, ctx);
        goto after_17;
    // 0x8013E4D0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_17:
    // 0x8013E4D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8013E4D8: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8013E4DC: beql        $v0, $a1, L_8013E538
    if (ctx->r2 == ctx->r5) {
        // 0x8013E4E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E538;
    }
    goto skip_16;
    // 0x8013E4E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x8013E4E4: jal         0x8013E2E0
    // 0x8013E4E8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    ftCommonWalkGetWalkAnimLength(rdram, ctx);
        goto after_18;
    // 0x8013E4E8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_18:
    // 0x8013E4EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8013E4F0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8013E4F4: jal         0x8013E2E0
    // 0x8013E4F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    ftCommonWalkGetWalkAnimLength(rdram, ctx);
        goto after_19;
    // 0x8013E4F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x8013E4FC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8013E500: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8013E504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013E508: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8013E50C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8013E510: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8013E514: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8013E518: nop

    // 0x8013E51C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8013E520: nop

    // 0x8013E524: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8013E528: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8013E52C: jal         0x8013E580
    // 0x8013E530: nop

    ftCommonWalkSetStatusParam(rdram, ctx);
        goto after_20;
    // 0x8013E530: nop

    after_20:
L_8013E534:
    // 0x8013E534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013E538:
    // 0x8013E538: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013E53C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013E540: jr          $ra
    // 0x8013E544: nop

    return;
    // 0x8013E544: nop

;}
RECOMP_FUNC void itSwordMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174DA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80174DA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80174DA8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80174DAC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80174DB0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80174DB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80174DB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80174DBC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174DC0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80174DC4: addiu       $a1, $a1, -0x6750
    ctx->r5 = ADD32(ctx->r5, -0X6750);
    // 0x80174DC8: jal         0x8016E174
    // 0x80174DCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80174DCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80174DD0: beq         $v0, $zero, L_80174E10
    if (ctx->r2 == 0) {
        // 0x80174DD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80174E10;
    }
    // 0x80174DD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80174DD8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80174DDC: lwc1        $f4, -0x3338($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3338);
    // 0x80174DE0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80174DE4: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80174DE8: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x80174DEC: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80174DF0: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80174DF4: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x80174DF8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80174DFC: jal         0x80111EC0
    // 0x80174E00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80174E00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80174E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80174E08: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80174E0C: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_80174E10:
    // 0x80174E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80174E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80174E18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80174E1C: jr          $ra
    // 0x80174E20: nop

    return;
    // 0x80174E20: nop

;}
RECOMP_FUNC void sc1PStageClearFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801349F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801349F4: addiu       $v1, $v1, 0x52CC
    ctx->r3 = ADD32(ctx->r3, 0X52CC);
    // 0x801349F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801349FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134A04: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80134A08: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x80134A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134A10: bne         $at, $zero, L_80134AE4
    if (ctx->r1 != 0) {
        // 0x80134A14: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80134AE4;
    }
    // 0x80134A14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134A18: jal         0x8039076C
    // 0x80134A1C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x80134A1C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x80134A20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134A24: beq         $v0, $zero, L_80134A90
    if (ctx->r2 == 0) {
        // 0x80134A28: addiu       $v1, $v1, 0x52CC
        ctx->r3 = ADD32(ctx->r3, 0X52CC);
            goto L_80134A90;
    }
    // 0x80134A28: addiu       $v1, $v1, 0x52CC
    ctx->r3 = ADD32(ctx->r3, 0X52CC);
    // 0x80134A2C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134A30: lw          $t9, 0x533C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X533C);
    // 0x80134A34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134A38: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80134A3C: beq         $t9, $zero, L_80134A68
    if (ctx->r25 == 0) {
        // 0x80134A40: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80134A68;
    }
    // 0x80134A40: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80134A44: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80134A48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134A4C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80134A50: jal         0x80133EEC
    // 0x80134A54: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    sc1PStageClearUpdateTotal1PGameScore(rdram, ctx);
        goto after_1;
    // 0x80134A54: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_1:
    // 0x80134A58: jal         0x80005C74
    // 0x80134A5C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x80134A5C: nop

    after_2:
    // 0x80134A60: b           L_80134A90
    // 0x80134A64: nop

        goto L_80134A90;
    // 0x80134A64: nop

L_80134A68:
    // 0x80134A68: lw          $t2, 0x5334($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5334);
    // 0x80134A6C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80134A70: beq         $t2, $zero, L_80134A90
    if (ctx->r10 == 0) {
        // 0x80134A74: nop
    
            goto L_80134A90;
    }
    // 0x80134A74: nop

    // 0x80134A78: lw          $t3, 0x5338($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5338);
    // 0x80134A7C: bne         $t3, $zero, L_80134A90
    if (ctx->r11 != 0) {
        // 0x80134A80: nop
    
            goto L_80134A90;
    }
    // 0x80134A80: nop

    // 0x80134A84: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80134A88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134A8C: sw          $t4, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r12;
L_80134A90:
    // 0x80134A90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134A94: lw          $v0, 0x52D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D4);
    // 0x80134A98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134A9C: beq         $v0, $zero, L_80134ACC
    if (ctx->r2 == 0) {
        // 0x80134AA0: nop
    
            goto L_80134ACC;
    }
    // 0x80134AA0: nop

    // 0x80134AA4: beq         $v0, $at, L_80134ABC
    if (ctx->r2 == ctx->r1) {
        // 0x80134AA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80134ABC;
    }
    // 0x80134AA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80134AAC: beq         $v0, $at, L_80134ADC
    if (ctx->r2 == ctx->r1) {
        // 0x80134AB0: nop
    
            goto L_80134ADC;
    }
    // 0x80134AB0: nop

    // 0x80134AB4: b           L_80134AE8
    // 0x80134AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134AE8;
    // 0x80134AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134ABC:
    // 0x80134ABC: jal         0x8013407C
    // 0x80134AC0: nop

    sc1PStageClearUpdateGameClearScore(rdram, ctx);
        goto after_3;
    // 0x80134AC0: nop

    after_3:
    // 0x80134AC4: b           L_80134AE8
    // 0x80134AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134AE8;
    // 0x80134AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134ACC:
    // 0x80134ACC: jal         0x80134340
    // 0x80134AD0: nop

    sc1PStageClearUpdateStageClearScore(rdram, ctx);
        goto after_4;
    // 0x80134AD0: nop

    after_4:
    // 0x80134AD4: b           L_80134AE8
    // 0x80134AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134AE8;
    // 0x80134AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134ADC:
    // 0x80134ADC: jal         0x80134604
    // 0x80134AE0: nop

    sc1PStageClearUpdateResultScore(rdram, ctx);
        goto after_5;
    // 0x80134AE0: nop

    after_5:
L_80134AE4:
    // 0x80134AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134AE8:
    // 0x80134AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134AEC: jr          $ra
    // 0x80134AF0: nop

    return;
    // 0x80134AF0: nop

;}
RECOMP_FUNC void efManagerDamageSpawnSparksProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100030: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80100034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100038: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010003C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80100040: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80100044: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x80100048: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8010004C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100050: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x80100054: addiu       $a0, $a0, -0x1FEC
    ctx->r4 = ADD32(ctx->r4, -0X1FEC);
    // 0x80100058: bgez        $v1, L_8010006C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8010005C: andi        $t7, $v1, 0x3
        ctx->r15 = ctx->r3 & 0X3;
            goto L_8010006C;
    }
    // 0x8010005C: andi        $t7, $v1, 0x3
    ctx->r15 = ctx->r3 & 0X3;
    // 0x80100060: beq         $t7, $zero, L_8010006C
    if (ctx->r15 == 0) {
        // 0x80100064: nop
    
            goto L_8010006C;
    }
    // 0x80100064: nop

    // 0x80100068: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_8010006C:
    // 0x8010006C: bnel        $t7, $zero, L_80100178
    if (ctx->r15 != 0) {
        // 0x80100070: lw          $t5, 0x18($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X18);
            goto L_80100178;
    }
    goto skip_0;
    // 0x80100070: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    skip_0:
    // 0x80100074: jal         0x800FDAFC
    // 0x80100078: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80100078: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8010007C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80100080: beq         $v0, $zero, L_80100174
    if (ctx->r2 == 0) {
        // 0x80100084: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80100174;
    }
    // 0x80100084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100088: lw          $v0, 0x74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74);
    // 0x8010008C: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x80100090: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80100094: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80100098: lw          $t8, 0x20($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X20);
    // 0x8010009C: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x801000A0: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x801000A4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x801000A8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x801000AC: jal         0x80018948
    // 0x801000B0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x801000B0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x801000B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801000B8: lwc1        $f4, 0x9B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9B0);
    // 0x801000BC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x801000C0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x801000C4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801000C8: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x801000CC: bgez        $v1, L_801000DC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801000D0: sra         $t0, $v1, 2
        ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
            goto L_801000DC;
    }
    // 0x801000D0: sra         $t0, $v1, 2
    ctx->r8 = S32(SIGNED(ctx->r3) >> 2);
    // 0x801000D4: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
    // 0x801000D8: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
L_801000DC:
    // 0x801000DC: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801000E0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801000E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801000E8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801000EC: lwc1        $f2, -0x2178($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2178);
    // 0x801000F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801000F4: lwc1        $f8, 0x9B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9B4);
    // 0x801000F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801000FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80100100: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80100104: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80100108: jal         0x80035CD0
    // 0x8010010C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8010010C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80100110: lw          $t3, 0x28($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X28);
    // 0x80100114: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80100118: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010011C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80100120: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80100124: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80100128: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010012C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80100130: jal         0x800303F0
    // 0x80100134: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80100134: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x80100138: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010013C: lwc1        $f12, 0x9B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X9B8);
    // 0x80100140: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80100144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80100148: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8010014C: addiu       $t4, $zero, 0xFA
    ctx->r12 = ADD32(0, 0XFA);
    // 0x80100150: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80100154: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80100158: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x8010015C: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80100160: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80100164: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x80100168: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8010016C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x80100170: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_80100174:
    // 0x80100174: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
L_80100178:
    // 0x80100178: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8010017C: bgez        $t6, L_80100194
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80100180: sw          $t6, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r14;
            goto L_80100194;
    }
    // 0x80100180: sw          $t6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r14;
    // 0x80100184: jal         0x800FD4F8
    // 0x80100188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_4;
    // 0x80100188: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8010018C: jal         0x80009A84
    // 0x80100190: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80100190: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
L_80100194:
    // 0x80100194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100198: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010019C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801001A0: jr          $ra
    // 0x801001A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801001A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void unref_80008304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008304: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000830C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80008310: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80008314: bne         $a0, $zero, L_80008324
    if (ctx->r4 != 0) {
        // 0x80008318: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80008324;
    }
    // 0x80008318: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8000831C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80008320: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80008324:
    // 0x80008324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80008328: jal         0x80007604
    // 0x8000832C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    gcGetGObjProcess(rdram, ctx);
        goto after_0;
    // 0x8000832C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80008330: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80008334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80008338: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000833C: sltiu       $at, $a2, 0x6
    ctx->r1 = ctx->r6 < 0X6 ? 1 : 0;
    // 0x80008340: bnel        $at, $zero, L_8000835C
    if (ctx->r1 != 0) {
        // 0x80008344: sw          $a2, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r6;
            goto L_8000835C;
    }
    goto skip_0;
    // 0x80008344: sw          $a2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r6;
    skip_0:
    // 0x80008348: jal         0x80023624
    // 0x8000834C: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, -0X2580);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8000834C: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, -0X2580);
    after_1:
L_80008350:
    // 0x80008350: b           L_80008350
    pause_self(rdram);
    // 0x80008354: nop

    // 0x80008358: sw          $a2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r6;
L_8000835C:
    // 0x8000835C: sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // 0x80008360: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80008364: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x80008368: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000836C: jal         0x800073E0
    // 0x80008370: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    gcGetGObjThread(rdram, ctx);
        goto after_2;
    // 0x80008370: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    after_2:
    // 0x80008374: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80008378: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8000837C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80008380: bne         $a0, $zero, L_80008398
    if (ctx->r4 != 0) {
        // 0x80008384: sb          $zero, 0x14($s0)
        MEM_B(0X14, ctx->r16) = 0;
            goto L_80008398;
    }
    // 0x80008384: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x80008388: jal         0x80007564
    // 0x8000838C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    gcGetDefaultGObjStack(rdram, ctx);
        goto after_3;
    // 0x8000838C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80008390: b           L_800083A4
    // 0x80008394: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_800083A4;
    // 0x80008394: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80008398:
    // 0x80008398: jal         0x80007488
    // 0x8000839C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    gcGetGObjStackOfSize(rdram, ctx);
        goto after_4;
    // 0x8000839C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800083A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800083A4:
    // 0x800083A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800083A8: sw          $t8, 0x1B8($v1)
    MEM_W(0X1B8, ctx->r3) = ctx->r24;
    // 0x800083AC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800083B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800083B4: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x800083B8: bne         $t9, $zero, L_800083D0
    if (ctx->r25 != 0) {
        // 0x800083BC: addiu       $a0, $v1, 0x8
        ctx->r4 = ADD32(ctx->r3, 0X8);
            goto L_800083D0;
    }
    // 0x800083BC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800083C0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800083C4: lw          $t0, 0x66BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X66BC);
    // 0x800083C8: b           L_800083D4
    // 0x800083CC: sw          $t0, 0x1BC($v1)
    MEM_W(0X1BC, ctx->r3) = ctx->r8;
        goto L_800083D4;
    // 0x800083CC: sw          $t0, 0x1BC($v1)
    MEM_W(0X1BC, ctx->r3) = ctx->r8;
L_800083D0:
    // 0x800083D0: sw          $t1, 0x1BC($v1)
    MEM_W(0X1BC, ctx->r3) = ctx->r9;
L_800083D4:
    // 0x800083D4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800083D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800083DC: beq         $v0, $at, L_800083EC
    if (ctx->r2 == ctx->r1) {
        // 0x800083E0: nop
    
            goto L_800083EC;
    }
    // 0x800083E0: nop

    // 0x800083E4: b           L_80008400
    // 0x800083E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80008400;
    // 0x800083E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800083EC:
    // 0x800083EC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800083F0: lw          $a1, -0x4790($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X4790);
    // 0x800083F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800083F8: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x800083FC: sw          $t2, -0x4790($at)
    MEM_W(-0X4790, ctx->r1) = ctx->r10;
L_80008400:
    // 0x80008400: lw          $t4, 0x1BC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1BC);
    // 0x80008404: lw          $t3, 0x1B8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1B8);
    // 0x80008408: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8000840C: srl         $t5, $t4, 3
    ctx->r13 = S32(U32(ctx->r12) >> 3);
    // 0x80008410: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80008414: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80008418: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8000841C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80008420: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80008424: jal         0x80031E20
    // 0x80008428: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    osCreateThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80008428: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8000842C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80008430: lui         $t1, 0xFEDC
    ctx->r9 = S32(0XFEDC << 16);
    // 0x80008434: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80008438: lw          $t9, 0x1B8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1B8);
    // 0x8000843C: ori         $t1, $t1, 0xBA98
    ctx->r9 = ctx->r9 | 0XBA98;
    // 0x80008440: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80008444: addiu       $v0, $v0, -0x4790
    ctx->r2 = ADD32(ctx->r2, -0X4790);
    // 0x80008448: sw          $t0, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r8;
    // 0x8000844C: sw          $t1, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r9;
    // 0x80008450: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80008454: lui         $at, 0x131
    ctx->r1 = S32(0X131 << 16);
    // 0x80008458: ori         $at, $at, 0x2D00
    ctx->r1 = ctx->r1 | 0X2D00;
    // 0x8000845C: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80008460: bne         $at, $zero, L_80008470
    if (ctx->r1 != 0) {
        // 0x80008464: lui         $t4, 0x98
        ctx->r12 = S32(0X98 << 16);
            goto L_80008470;
    }
    // 0x80008464: lui         $t4, 0x98
    ctx->r12 = S32(0X98 << 16);
    // 0x80008468: ori         $t4, $t4, 0x9680
    ctx->r12 = ctx->r12 | 0X9680;
    // 0x8000846C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80008470:
    // 0x80008470: jal         0x80007680
    // 0x80008474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcLinkGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80008474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80008478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000847C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80008480: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008484: jr          $ra
    // 0x80008488: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80008488: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wpKirbyCutterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BC50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016BC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BC58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016BC5C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016BC60: jal         0x80167FE8
    // 0x8016BC64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016BC64: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016BC68: beq         $v0, $zero, L_8016BC8C
    if (ctx->r2 == 0) {
        // 0x8016BC6C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8016BC8C;
    }
    // 0x8016BC6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016BC70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016BC74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016BC78: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8016BC7C: jal         0x800FF648
    // 0x8016BC80: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016BC80: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016BC84: b           L_8016BCB8
    // 0x8016BC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016BCB8;
    // 0x8016BC88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016BC8C:
    // 0x8016BC8C: lw          $t8, 0xFC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XFC);
    // 0x8016BC90: bnel        $t8, $zero, L_8016BCB8
    if (ctx->r24 != 0) {
        // 0x8016BC94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016BCB8;
    }
    goto skip_0;
    // 0x8016BC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8016BC98: lwc1        $f12, 0xAC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8016BC9C: jal         0x8001863C
    // 0x8016BCA0: lwc1        $f14, 0xB0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XB0);
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x8016BCA0: lwc1        $f14, 0xB0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XB0);
    after_2:
    // 0x8016BCA4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8016BCA8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8016BCAC: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8016BCB0: swc1        $f4, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f4.u32l;
    // 0x8016BCB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BCB8:
    // 0x8016BCB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BCBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016BCC0: jr          $ra
    // 0x8016BCC4: nop

    return;
    // 0x8016BCC4: nop

;}
RECOMP_FUNC void sc1PIntroGetVSFighterVelocityZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80132F44: bnel        $a0, $at, L_80132F74
    if (ctx->r4 != ctx->r1) {
        // 0x80132F48: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80132F74;
    }
    goto skip_0;
    // 0x80132F48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_0:
    // 0x80132F4C: bne         $a1, $zero, L_80132F64
    if (ctx->r5 != 0) {
        // 0x80132F50: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80132F64;
    }
    // 0x80132F50: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132F54: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132F58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F5C: jr          $ra
    // 0x80132F60: nop

    return;
    // 0x80132F60: nop

L_80132F64:
    // 0x80132F64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F68: jr          $ra
    // 0x80132F6C: nop

    return;
    // 0x80132F6C: nop

    // 0x80132F70: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80132F74:
    // 0x80132F74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132F78: nop

    // 0x80132F7C: jr          $ra
    // 0x80132F80: nop

    return;
    // 0x80132F80: nop

;}
RECOMP_FUNC void itRShellSpinProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017AD80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AD84: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017AD88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017AD8C: jal         0x8017A610
    // 0x8017AD90: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itRShellSpinUpdateGFX(rdram, ctx);
        goto after_0;
    // 0x8017AD90: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017AD94: jal         0x8017A534
    // 0x8017AD98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itRShellSpinSearchFollowPlayer(rdram, ctx);
        goto after_1;
    // 0x8017AD98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017AD9C: jal         0x8017AC84
    // 0x8017ADA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itRShellSpinCheckCollisionEdge(rdram, ctx);
        goto after_2;
    // 0x8017ADA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017ADA4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017ADA8: lw          $v0, 0x2C0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C0);
    // 0x8017ADAC: bne         $v0, $zero, L_8017ADBC
    if (ctx->r2 != 0) {
        // 0x8017ADB0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8017ADBC;
    }
    // 0x8017ADB0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8017ADB4: b           L_8017ADC4
    // 0x8017ADB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017ADC4;
    // 0x8017ADB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017ADBC:
    // 0x8017ADBC: sw          $t7, 0x2C0($v1)
    MEM_W(0X2C0, ctx->r3) = ctx->r15;
    // 0x8017ADC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017ADC4:
    // 0x8017ADC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017ADC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017ADCC: jr          $ra
    // 0x8017ADD0: nop

    return;
    // 0x8017ADD0: nop

;}
RECOMP_FUNC void efParticleInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115898: jal         0x800CE418
    // 0x8011589C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    lbParticleAllocStructs(rdram, ctx);
        goto after_0;
    // 0x8011589C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x801158A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801158A4: sw          $v0, 0x1A10($at)
    MEM_W(0X1A10, ctx->r1) = ctx->r2;
    // 0x801158A8: jal         0x800D2758
    // 0x801158AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    lbParticleAllocGenerators(rdram, ctx);
        goto after_1;
    // 0x801158AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x801158B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801158B4: sw          $v0, 0x1A14($at)
    MEM_W(0X1A14, ctx->r1) = ctx->r2;
    // 0x801158B8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x801158BC: jal         0x800CE040
    // 0x801158C0: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    lbParticleAllocTransforms(rdram, ctx);
        goto after_2;
    // 0x801158C0: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    after_2:
    // 0x801158C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801158C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801158CC: sw          $zero, 0x1A18($at)
    MEM_W(0X1A18, ctx->r1) = 0;
    // 0x801158D0: jr          $ra
    // 0x801158D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801158D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void sc1PChallengerFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DF4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131DFC: lwc1        $f2, 0x2460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X2460);
    // 0x80131E00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E04: lwc1        $f6, 0x2464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2464);
    // 0x80131E08: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80131E0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131E10: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80131E14: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131E18: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80131E1C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80131E20: nop

    // 0x80131E24: bc1f        L_80131E34
    if (!c1cs) {
        // 0x80131E28: nop
    
            goto L_80131E34;
    }
    // 0x80131E28: nop

    // 0x80131E2C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80131E30: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
L_80131E34:
    // 0x80131E34: jr          $ra
    // 0x80131E38: nop

    return;
    // 0x80131E38: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FBC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015FBC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015FBC8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015FBCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015FBD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015FBD4: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015FBD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015FBDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015FBE0: jal         0x800E6F24
    // 0x8015FBE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015FBE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015FBE8: jal         0x800E0830
    // 0x8015FBEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015FBEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015FBF0: jal         0x8015FB40
    // 0x8015FBF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCaptainSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015FBF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015FBF8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015FBFC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8015FC00: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8015FC04: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x8015FC08: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x8015FC0C: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x8015FC10: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x8015FC14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FC18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015FC1C: jr          $ra
    // 0x8015FC20: nop

    return;
    // 0x8015FC20: nop

;}
RECOMP_FUNC void gmCameraApplyFOV(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C6FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C700: lwc1        $f4, 0x14F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X14F0);
    // 0x8010C704: jr          $ra
    // 0x8010C708: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8010C708: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftMarioSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155F0C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155F10: jal         0x800DDE84
    // 0x80155F14: addiu       $a1, $a1, 0x5FA0
    ctx->r5 = ADD32(ctx->r5, 0X5FA0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80155F14: addiu       $a1, $a1, 0x5FA0
    ctx->r5 = ADD32(ctx->r5, 0X5FA0);
    after_0:
    // 0x80155F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155F20: jr          $ra
    // 0x80155F24: nop

    return;
    // 0x80155F24: nop

;}
RECOMP_FUNC void func_ovl8_803827A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803827A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803827AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803827B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803827B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803827B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803827BC: bne         $a0, $zero, L_803827D4
    if (ctx->r4 != 0) {
        // 0x803827C0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803827D4;
    }
    // 0x803827C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803827C4: jal         0x803717A0
    // 0x803827C8: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803827C8: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x803827CC: beq         $v0, $zero, L_8038285C
    if (ctx->r2 == 0) {
        // 0x803827D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8038285C;
    }
    // 0x803827D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803827D4:
    // 0x803827D4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803827D8: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x803827DC: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x803827E0: bnel        $t6, $zero, L_80382804
    if (ctx->r14 != 0) {
        // 0x803827E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80382804;
    }
    goto skip_0;
    // 0x803827E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x803827E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803827EC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803827F0: jal         0x803717E0
    // 0x803827F4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803827F4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x803827F8: jal         0x8037C2D0
    // 0x803827FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803827FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80382800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80382804:
    // 0x80382804: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80382808: jal         0x8037E8C8
    // 0x8038280C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037E8C8(rdram, ctx);
        goto after_3;
    // 0x8038280C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80382810: jal         0x80381130
    // 0x80382814: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    func_ovl8_80381130(rdram, ctx);
        goto after_4;
    // 0x80382814: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    after_4:
    // 0x80382818: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038281C: addiu       $t7, $t7, -0x3E40
    ctx->r15 = ADD32(ctx->r15, -0X3E40);
    // 0x80382820: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80382824: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80382828: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038282C: addiu       $t8, $t8, -0x3D60
    ctx->r24 = ADD32(ctx->r24, -0X3D60);
    // 0x80382830: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80382834: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80382838: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038283C: addiu       $t0, $t0, -0x3C08
    ctx->r8 = ADD32(ctx->r8, -0X3C08);
    // 0x80382840: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80382844: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80382848: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x8038284C: addiu       $t3, $t3, -0x3B78
    ctx->r11 = ADD32(ctx->r11, -0X3B78);
    // 0x80382850: addiu       $t2, $t2, -0x3BE0
    ctx->r10 = ADD32(ctx->r10, -0X3BE0);
    // 0x80382854: sw          $t2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r10;
    // 0x80382858: sw          $t3, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r11;
L_8038285C:
    // 0x8038285C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382860: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382868: jr          $ra
    // 0x8038286C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8038286C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PBonusStageGetPlatformKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D62C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018D630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D634: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018D638: jal         0x800F4428
    // 0x8018D63C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x8018D63C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8018D640: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018D644: jal         0x800F4408
    // 0x8018D648: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x8018D648: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8018D64C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018D650: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018D654: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D658: lwc1        $f8, -0xE74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XE74);
    // 0x8018D65C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D660: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D668: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8018D66C: nop

    // 0x8018D670: bc1f        L_8018D680
    if (!c1cs) {
        // 0x8018D674: nop
    
            goto L_8018D680;
    }
    // 0x8018D674: nop

    // 0x8018D678: b           L_8018D6A0
    // 0x8018D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018D6A0;
    // 0x8018D67C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018D680:
    // 0x8018D680: lwc1        $f10, -0xE70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XE70);
    // 0x8018D684: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8018D688: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8018D68C: nop

    // 0x8018D690: bc1f        L_8018D6A0
    if (!c1cs) {
        // 0x8018D694: nop
    
            goto L_8018D6A0;
    }
    // 0x8018D694: nop

    // 0x8018D698: b           L_8018D6A0
    // 0x8018D69C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018D6A0;
    // 0x8018D69C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D6A0:
    // 0x8018D6A0: jr          $ra
    // 0x8018D6A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018D6A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftKirbySpecialLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161B2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80161B30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161B34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80161B38: jal         0x800DEEC8
    // 0x80161B3C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80161B3C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80161B40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80161B44: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x80161B48: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161B4C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161B50: jal         0x800E6F24
    // 0x80161B54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80161B54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80161B58: jal         0x800E0830
    // 0x80161B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80161B5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80161B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80161B68: jr          $ra
    // 0x80161B6C: nop

    return;
    // 0x80161B6C: nop

;}
RECOMP_FUNC void lbRelocGetAllocSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDEEC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800CDEF0: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800CDEF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDEF8: sw          $t6, 0x633C($at)
    MEM_W(0X633C, ctx->r1) = ctx->r14;
    // 0x800CDEFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDF00: sw          $zero, 0x6340($at)
    MEM_W(0X6340, ctx->r1) = 0;
    // 0x800CDF04: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CDF08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CDF0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CDF10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDF14: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x800CDF18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CDF1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CDF20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDF24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CDF28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CDF2C: beq         $a1, $zero, L_800CDF58
    if (ctx->r5 == 0) {
        // 0x800CDF30: sw          $t7, 0x6344($at)
        MEM_W(0X6344, ctx->r1) = ctx->r15;
            goto L_800CDF58;
    }
    // 0x800CDF30: sw          $t7, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = ctx->r15;
    // 0x800CDF34: addiu       $s3, $zero, -0x10
    ctx->r19 = ADD32(0, -0X10);
L_800CDF38:
    // 0x800CDF38: addiu       $t8, $s2, 0xF
    ctx->r24 = ADD32(ctx->r18, 0XF);
    // 0x800CDF3C: and         $s2, $t8, $s3
    ctx->r18 = ctx->r24 & ctx->r19;
    // 0x800CDF40: jal         0x800CDA38
    // 0x800CDF44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    lbRelocGetExternBytesNum(rdram, ctx);
        goto after_0;
    // 0x800CDF44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800CDF48: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800CDF4C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x800CDF50: bne         $s0, $zero, L_800CDF38
    if (ctx->r16 != 0) {
        // 0x800CDF54: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800CDF38;
    }
    // 0x800CDF54: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800CDF58:
    // 0x800CDF58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDF5C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800CDF60: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDF64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CDF68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CDF6C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CDF70: jr          $ra
    // 0x800CDF74: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800CDF74: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void itSawamuraFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182638: lui         $a1, 0x4019
    ctx->r5 = S32(0X4019 << 16);
    // 0x8018263C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80182640: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80182644: jal         0x80172558
    // 0x80182648: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80182648: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x8018264C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182658: jr          $ra
    // 0x8018265C: nop

    return;
    // 0x8018265C: nop

;}
RECOMP_FUNC void grDisplayDObjSetNoAnimXObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801053CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801053D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801053D4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801053D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801053DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801053E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801053E4: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x801053E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801053EC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801053F0: beq         $s3, $zero, L_80105460
    if (ctx->r19 == 0) {
        // 0x801053F4: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_80105460;
    }
    // 0x801053F4: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_801053F8:
    // 0x801053F8: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x801053FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105400: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80105404: bne         $t6, $zero, L_80105450
    if (ctx->r14 != 0) {
        // 0x80105408: nop
    
            goto L_80105450;
    }
    // 0x80105408: nop

    // 0x8010540C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80105410: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80105414: bne         $t8, $zero, L_80105450
    if (ctx->r24 != 0) {
        // 0x80105418: nop
    
            goto L_80105450;
    }
    // 0x80105418: nop

    // 0x8010541C: lbu         $t9, 0x56($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X56);
    // 0x80105420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80105424: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80105428: blez        $t9, L_80105450
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8010542C: nop
    
            goto L_80105450;
    }
    // 0x8010542C: nop

    // 0x80105430: lw          $t0, 0x58($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X58);
L_80105434:
    // 0x80105434: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80105438: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8010543C: sb          $s1, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r17;
    // 0x80105440: lbu         $t1, 0x56($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X56);
    // 0x80105444: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80105448: bnel        $at, $zero, L_80105434
    if (ctx->r1 != 0) {
        // 0x8010544C: lw          $t0, 0x58($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X58);
            goto L_80105434;
    }
    goto skip_0;
    // 0x8010544C: lw          $t0, 0x58($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X58);
    skip_0:
L_80105450:
    // 0x80105450: jal         0x800C86E8
    // 0x80105454: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_0;
    // 0x80105454: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    after_0:
    // 0x80105458: bne         $v0, $zero, L_801053F8
    if (ctx->r2 != 0) {
        // 0x8010545C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801053F8;
    }
    // 0x8010545C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80105460:
    // 0x80105460: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80105464: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80105468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010546C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80105470: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80105474: jr          $ra
    // 0x80105478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80105478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftFoxSpecialHiHoldInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BFBC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BFC0: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x8015BFC4: jr          $ra
    // 0x8015BFC8: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    return;
    // 0x8015BFC8: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void mpCommonSetFighterProjectFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE32C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE330: jal         0x800D9FCC
    // 0x800DE334: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_0;
    // 0x800DE334: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE33C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE340: jr          $ra
    // 0x800DE344: nop

    return;
    // 0x800DE344: nop

;}
RECOMP_FUNC void mvOpeningClashWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323C8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801323CC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801323D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801323D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801323D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801323DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801323E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801323E4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801323E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801323EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801323F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801323F4: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801323F8: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x801323FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132400: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132404: ori         $t0, $t0, 0x2048
    ctx->r8 = ctx->r8 | 0X2048;
    // 0x80132408: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8013240C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132410: jal         0x80017DBC
    // 0x80132414: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    func_80017DBC(rdram, ctx);
        goto after_0;
    // 0x80132414: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x80132418: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013241C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132420: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132424: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80132428: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x8013242C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80132430: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80132434: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132438: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8013243C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132440: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x80132444: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x80132448: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8013244C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80132450: ori         $t4, $t4, 0x1C
    ctx->r12 = ctx->r12 | 0X1C;
    // 0x80132454: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80132458: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8013245C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132464: jr          $ra
    // 0x80132468: nop

    return;
    // 0x80132468: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E888: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E88C: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015E890: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015E894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E898: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8015E89C: jal         0x800E6F24
    // 0x8015E8A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E8A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015E8A4: jal         0x800E0830
    // 0x8015E8A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E8A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015E8AC: jal         0x8015E7F8
    // 0x8015E8B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialNCatchInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E8B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015E8B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E8B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E8BC: jr          $ra
    // 0x8015E8C0: nop

    return;
    // 0x8015E8C0: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016030C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80160310: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80160314: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80160318: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016031C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80160320: nop

    // 0x80160324: bc1tl       L_8016033C
    if (c1cs) {
        // 0x80160328: lw          $t7, 0x840($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X840);
            goto L_8016033C;
    }
    goto skip_0;
    // 0x80160328: lw          $t7, 0x840($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X840);
    skip_0:
    // 0x8016032C: lw          $t6, 0x17C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X17C);
    // 0x80160330: beql        $t6, $zero, L_80160364
    if (ctx->r14 == 0) {
        // 0x80160334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80160364;
    }
    goto skip_1;
    // 0x80160334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80160338: lw          $t7, 0x840($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X840);
L_8016033C:
    // 0x8016033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80160340: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x80160344: lhu         $t8, 0xB18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XB18);
    // 0x80160348: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8016034C: sh          $t9, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r25;
    // 0x80160350: jal         0x801008F4
    // 0x80160354: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80160354: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80160358: jal         0x80160730
    // 0x8016035C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCaptainSpecialHiThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016035C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80160360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80160364:
    // 0x80160364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80160368: jr          $ra
    // 0x8016036C: nop

    return;
    // 0x8016036C: nop

;}
RECOMP_FUNC void ftCommonCatchSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149BAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80149BB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80149BB4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80149BB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80149BBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80149BC0: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // 0x80149BC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80149BC8: jal         0x800E6F24
    // 0x80149BCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149BCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80149BD0: jal         0x800E0830
    // 0x80149BD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80149BD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80149BD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80149BDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80149BE0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80149BE4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80149BE8: sw          $t6, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r14;
    // 0x80149BEC: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80149BF0: addiu       $a3, $a3, -0x57A0
    ctx->r7 = ADD32(ctx->r7, -0X57A0);
    // 0x80149BF4: addiu       $a2, $a2, -0x60FC
    ctx->r6 = ADD32(ctx->r6, -0X60FC);
    // 0x80149BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149BFC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80149C00: swc1        $f0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f0.u32l;
    // 0x80149C04: jal         0x800E80A4
    // 0x80149C08: swc1        $f0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->f0.u32l;
    ftParamSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80149C08: swc1        $f0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80149C0C: lbu         $t7, 0x192($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X192);
    // 0x80149C10: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80149C14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80149C18: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x80149C1C: beq         $v0, $at, L_80149C30
    if (ctx->r2 == ctx->r1) {
        // 0x80149C20: sb          $t8, 0x192($s0)
        MEM_B(0X192, ctx->r16) = ctx->r24;
            goto L_80149C30;
    }
    // 0x80149C20: sb          $t8, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r24;
    // 0x80149C24: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80149C28: bnel        $v0, $at, L_80149C50
    if (ctx->r2 != ctx->r1) {
        // 0x80149C2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80149C50;
    }
    goto skip_0;
    // 0x80149C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80149C30:
    // 0x80149C30: jal         0x80101E80
    // 0x80149C34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSamusGrappleBeamGlowMakeEffect(rdram, ctx);
        goto after_3;
    // 0x80149C34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80149C38: beql        $v0, $zero, L_80149C50
    if (ctx->r2 == 0) {
        // 0x80149C3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80149C50;
    }
    goto skip_1;
    // 0x80149C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80149C40: lbu         $t0, 0x18F($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18F);
    // 0x80149C44: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80149C48: sb          $t1, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r9;
    // 0x80149C4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80149C50:
    // 0x80149C50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80149C54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149C58: jr          $ra
    // 0x80149C5C: nop

    return;
    // 0x80149C5C: nop

;}
RECOMP_FUNC void mnScreenAdjustFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013209C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801320A0: addiu       $v0, $v0, 0x2934
    ctx->r2 = ADD32(ctx->r2, 0X2934);
    // 0x801320A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801320A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801320AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320B0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801320B4: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801320B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801320BC: bne         $at, $zero, L_801326BC
    if (ctx->r1 != 0) {
        // 0x801320C0: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801326BC;
    }
    // 0x801320C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801320C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801320C8: addiu       $v1, $v1, 0x2930
    ctx->r3 = ADD32(ctx->r3, 0X2930);
    // 0x801320CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320D0: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x801320D4: beq         $v0, $zero, L_801320E0
    if (ctx->r2 == 0) {
        // 0x801320D8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801320E0;
    }
    // 0x801320D8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801320DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801320E0:
    // 0x801320E0: jal         0x80390A04
    // 0x801320E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x801320E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x801320E8: beq         $v0, $zero, L_80132104
    if (ctx->r2 == 0) {
        // 0x801320EC: addiu       $a0, $zero, -0x1E
        ctx->r4 = ADD32(0, -0X1E);
            goto L_80132104;
    }
    // 0x801320EC: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x801320F0: jal         0x80390AC0
    // 0x801320F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x801320F4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x801320F8: beq         $v0, $zero, L_80132104
    if (ctx->r2 == 0) {
        // 0x801320FC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132104;
    }
    // 0x801320FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132100: sw          $zero, 0x2930($at)
    MEM_W(0X2930, ctx->r1) = 0;
L_80132104:
    // 0x80132104: jal         0x8039076C
    // 0x80132108: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132108: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x8013210C: beq         $v0, $zero, L_80132140
    if (ctx->r2 == 0) {
        // 0x80132110: nop
    
            goto L_80132140;
    }
    // 0x80132110: nop

    // 0x80132114: jal         0x800269C0
    // 0x80132118: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80132118: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_3:
    // 0x8013211C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132120: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132124: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80132128: addiu       $t1, $zero, 0x39
    ctx->r9 = ADD32(0, 0X39);
    // 0x8013212C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80132130: jal         0x8013204C
    // 0x80132134: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    mnScreenAdjustBackupOffsets(rdram, ctx);
        goto after_4;
    // 0x80132134: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_4:
    // 0x80132138: jal         0x80005C74
    // 0x8013213C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x8013213C: nop

    after_5:
L_80132140:
    // 0x80132140: jal         0x8039076C
    // 0x80132144: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_6;
    // 0x80132144: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_6:
    // 0x80132148: beq         $v0, $zero, L_801321DC
    if (ctx->r2 == 0) {
        // 0x8013214C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801321DC;
    }
    // 0x8013214C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132150: addiu       $v0, $v0, 0x292C
    ctx->r2 = ADD32(ctx->r2, 0X292C);
    // 0x80132154: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80132158: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013215C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80132160: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132164: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80132168: nop

    // 0x8013216C: bc1f        L_801321DC
    if (!c1cs) {
        // 0x80132170: nop
    
            goto L_801321DC;
    }
    // 0x80132170: nop

    // 0x80132174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132178: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x8013217C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132180: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80132184: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80132188: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8013218C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80132190: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80132194: nop

    // 0x80132198: bc1f        L_801321B0
    if (!c1cs) {
        // 0x8013219C: nop
    
            goto L_801321B0;
    }
    // 0x8013219C: nop

    // 0x801321A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801321A4: nop

    // 0x801321A8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x801321AC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801321B0:
    // 0x801321B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801321B4: lwc1        $f18, 0x2928($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x801321B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801321BC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801321C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801321C4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801321C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801321CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801321D0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801321D4: jal         0x80131FB4
    // 0x801321D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_7;
    // 0x801321D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_7:
L_801321DC:
    // 0x801321DC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801321E0: lw          $t4, 0x2930($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2930);
    // 0x801321E4: bne         $t4, $zero, L_80132284
    if (ctx->r12 != 0) {
        // 0x801321E8: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_80132284;
    }
    // 0x801321E8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801321EC: jal         0x80390950
    // 0x801321F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_8;
    // 0x801321F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x801321F4: beq         $v0, $zero, L_80132284
    if (ctx->r2 == 0) {
        // 0x801321F8: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80132284;
    }
    // 0x801321F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801321FC: addiu       $v1, $v1, 0x292C
    ctx->r3 = ADD32(ctx->r3, 0X292C);
    // 0x80132200: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80132204: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132208: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8013220C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132210: nop

    // 0x80132214: bc1f        L_80132284
    if (!c1cs) {
        // 0x80132218: nop
    
            goto L_80132284;
    }
    // 0x80132218: nop

    // 0x8013221C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80132220: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80132224: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132228: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013222C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132230: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80132234: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80132238: swc1        $f4, 0x292C($at)
    MEM_W(0X292C, ctx->r1) = ctx->f4.u32l;
    // 0x8013223C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132240: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132244: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132248: nop

    // 0x8013224C: bc1f        L_8013225C
    if (!c1cs) {
        // 0x80132250: nop
    
            goto L_8013225C;
    }
    // 0x80132250: nop

    // 0x80132254: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x80132258: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_8013225C:
    // 0x8013225C: lwc1        $f6, 0x2928($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132260: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80132264: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80132268: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8013226C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80132270: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80132274: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80132278: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013227C: jal         0x80131FB4
    // 0x80132280: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_9;
    // 0x80132280: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_9:
L_80132284:
    // 0x80132284: jal         0x8039076C
    // 0x80132288: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_10;
    // 0x80132288: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_10:
    // 0x8013228C: beq         $v0, $zero, L_80132320
    if (ctx->r2 == 0) {
        // 0x80132290: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_80132320;
    }
    // 0x80132290: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80132294: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132298: addiu       $v0, $v0, 0x292C
    ctx->r2 = ADD32(ctx->r2, 0X292C);
    // 0x8013229C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801322A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801322A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801322A8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801322AC: nop

    // 0x801322B0: bc1f        L_80132320
    if (!c1cs) {
        // 0x801322B4: nop
    
            goto L_80132320;
    }
    // 0x801322B4: nop

    // 0x801322B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801322BC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801322C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801322C4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x801322C8: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801322CC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801322D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801322D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801322D8: nop

    // 0x801322DC: bc1f        L_801322F4
    if (!c1cs) {
        // 0x801322E0: nop
    
            goto L_801322F4;
    }
    // 0x801322E0: nop

    // 0x801322E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322E8: nop

    // 0x801322EC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801322F0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801322F4:
    // 0x801322F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322F8: lwc1        $f10, 0x2928($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x801322FC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80132300: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80132304: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80132308: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8013230C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80132310: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80132314: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80132318: jal         0x80131FB4
    // 0x8013231C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_11;
    // 0x8013231C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_11:
L_80132320:
    // 0x80132320: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132324: lw          $t9, 0x2930($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2930);
    // 0x80132328: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x8013232C: bne         $t9, $zero, L_801323CC
    if (ctx->r25 != 0) {
        // 0x80132330: nop
    
            goto L_801323CC;
    }
    // 0x80132330: nop

    // 0x80132334: jal         0x80390950
    // 0x80132338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_12;
    // 0x80132338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8013233C: beq         $v0, $zero, L_801323CC
    if (ctx->r2 == 0) {
        // 0x80132340: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_801323CC;
    }
    // 0x80132340: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132344: addiu       $v1, $v1, 0x292C
    ctx->r3 = ADD32(ctx->r3, 0X292C);
    // 0x80132348: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8013234C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132350: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132354: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132358: nop

    // 0x8013235C: bc1f        L_801323CC
    if (!c1cs) {
        // 0x80132360: nop
    
            goto L_801323CC;
    }
    // 0x80132360: nop

    // 0x80132364: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80132368: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8013236C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132370: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132378: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013237C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80132380: swc1        $f16, 0x292C($at)
    MEM_W(0X292C, ctx->r1) = ctx->f16.u32l;
    // 0x80132384: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132388: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013238C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132390: nop

    // 0x80132394: bc1f        L_801323A4
    if (!c1cs) {
        // 0x80132398: nop
    
            goto L_801323A4;
    }
    // 0x80132398: nop

    // 0x8013239C: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x801323A0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_801323A4:
    // 0x801323A4: lwc1        $f18, 0x2928($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x801323A8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801323AC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801323B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801323B4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x801323B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801323BC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801323C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801323C4: jal         0x80131FB4
    // 0x801323C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_13;
    // 0x801323C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_13:
L_801323CC:
    // 0x801323CC: jal         0x8039076C
    // 0x801323D0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_14;
    // 0x801323D0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_14:
    // 0x801323D4: beq         $v0, $zero, L_80132454
    if (ctx->r2 == 0) {
        // 0x801323D8: lui         $at, 0xC160
        ctx->r1 = S32(0XC160 << 16);
            goto L_80132454;
    }
    // 0x801323D8: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x801323DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801323E0: addiu       $v0, $v0, 0x2928
    ctx->r2 = ADD32(ctx->r2, 0X2928);
    // 0x801323E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801323E8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801323EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801323F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801323F4: nop

    // 0x801323F8: bc1f        L_80132454
    if (!c1cs) {
        // 0x801323FC: nop
    
            goto L_80132454;
    }
    // 0x801323FC: nop

    // 0x80132400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132404: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132408: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8013240C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80132410: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80132414: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132418: nop

    // 0x8013241C: bc1f        L_8013242C
    if (!c1cs) {
        // 0x80132420: nop
    
            goto L_8013242C;
    }
    // 0x80132420: nop

    // 0x80132424: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80132428: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_8013242C:
    // 0x8013242C: lwc1        $f18, 0x292C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x80132430: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80132434: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80132438: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8013243C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80132440: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80132444: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132448: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8013244C: jal         0x80131FB4
    // 0x80132450: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_15;
    // 0x80132450: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_15:
L_80132454:
    // 0x80132454: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132458: lw          $t4, 0x2930($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2930);
    // 0x8013245C: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80132460: bne         $t4, $zero, L_80132514
    if (ctx->r12 != 0) {
        // 0x80132464: nop
    
            goto L_80132514;
    }
    // 0x80132464: nop

    // 0x80132468: jal         0x8039089C
    // 0x8013246C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_16;
    // 0x8013246C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80132470: beq         $v0, $zero, L_80132514
    if (ctx->r2 == 0) {
        // 0x80132474: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80132514;
    }
    // 0x80132474: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132478: addiu       $v1, $v1, 0x2928
    ctx->r3 = ADD32(ctx->r3, 0X2928);
    // 0x8013247C: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80132480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132484: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132488: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8013248C: nop

    // 0x80132490: bc1f        L_80132514
    if (!c1cs) {
        // 0x80132494: nop
    
            goto L_80132514;
    }
    // 0x80132494: nop

    // 0x80132498: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8013249C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801324A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801324A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801324A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324AC: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801324B0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x801324B4: swc1        $f4, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f4.u32l;
    // 0x801324B8: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x801324BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801324C0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801324C4: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x801324C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801324CC: nop

    // 0x801324D0: bc1f        L_801324E8
    if (!c1cs) {
        // 0x801324D4: nop
    
            goto L_801324E8;
    }
    // 0x801324D4: nop

    // 0x801324D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801324DC: nop

    // 0x801324E0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801324E4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_801324E8:
    // 0x801324E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324EC: lwc1        $f16, 0x292C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x801324F0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801324F4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801324F8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801324FC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80132500: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80132504: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132508: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8013250C: jal         0x80131FB4
    // 0x80132510: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_17;
    // 0x80132510: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_17:
L_80132514:
    // 0x80132514: jal         0x8039076C
    // 0x80132518: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_18;
    // 0x80132518: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_18:
    // 0x8013251C: beq         $v0, $zero, L_801325A0
    if (ctx->r2 == 0) {
        // 0x80132520: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_801325A0;
    }
    // 0x80132520: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80132524: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132528: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013252C: lwc1        $f0, 0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132530: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132534: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132538: nop

    // 0x8013253C: bc1f        L_801325A0
    if (!c1cs) {
        // 0x80132540: nop
    
            goto L_801325A0;
    }
    // 0x80132540: nop

    // 0x80132544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132548: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013254C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80132550: swc1        $f6, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f6.u32l;
    // 0x80132554: lwc1        $f0, 0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132558: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013255C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132560: nop

    // 0x80132564: bc1f        L_80132574
    if (!c1cs) {
        // 0x80132568: nop
    
            goto L_80132574;
    }
    // 0x80132568: nop

    // 0x8013256C: swc1        $f2, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f2.u32l;
    // 0x80132570: lwc1        $f0, 0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2928);
L_80132574:
    // 0x80132574: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132578: lwc1        $f10, 0x292C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x8013257C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80132580: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80132584: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80132588: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8013258C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80132590: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132594: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80132598: jal         0x80131FB4
    // 0x8013259C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_19;
    // 0x8013259C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_19:
L_801325A0:
    // 0x801325A0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801325A4: lw          $t9, 0x2930($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2930);
    // 0x801325A8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801325AC: bne         $t9, $zero, L_8013265C
    if (ctx->r25 != 0) {
        // 0x801325B0: nop
    
            goto L_8013265C;
    }
    // 0x801325B0: nop

    // 0x801325B4: jal         0x8039089C
    // 0x801325B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_20;
    // 0x801325B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x801325BC: beq         $v0, $zero, L_8013265C
    if (ctx->r2 == 0) {
        // 0x801325C0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8013265C;
    }
    // 0x801325C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325C4: lwc1        $f0, 0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x801325C8: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x801325CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801325D0: nop

    // 0x801325D4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801325D8: nop

    // 0x801325DC: bc1f        L_8013265C
    if (!c1cs) {
        // 0x801325E0: nop
    
            goto L_8013265C;
    }
    // 0x801325E0: nop

    // 0x801325E4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801325E8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801325EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801325F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801325F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325F8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801325FC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80132600: swc1        $f16, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f16.u32l;
    // 0x80132604: lwc1        $f0, 0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132608: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8013260C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132610: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80132614: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80132618: nop

    // 0x8013261C: bc1f        L_80132630
    if (!c1cs) {
        // 0x80132620: nop
    
            goto L_80132630;
    }
    // 0x80132620: nop

    // 0x80132624: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132628: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013262C: swc1        $f0, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f0.u32l;
L_80132630:
    // 0x80132630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132634: lwc1        $f8, 0x292C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x80132638: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8013263C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132640: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80132644: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80132648: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8013264C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132650: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80132654: jal         0x80131FB4
    // 0x80132658: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_21;
    // 0x80132658: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_21:
L_8013265C:
    // 0x8013265C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132660: sw          $zero, 0x2930($at)
    MEM_W(0X2930, ctx->r1) = 0;
    // 0x80132664: jal         0x8039076C
    // 0x80132668: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_22;
    // 0x80132668: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_22:
    // 0x8013266C: beql        $v0, $zero, L_801326C0
    if (ctx->r2 == 0) {
        // 0x80132670: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801326C0;
    }
    goto skip_0;
    // 0x80132670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132674: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132678: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013267C: swc1        $f0, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f0.u32l;
    // 0x80132680: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132684: swc1        $f0, 0x292C($at)
    MEM_W(0X292C, ctx->r1) = ctx->f0.u32l;
    // 0x80132688: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013268C: lwc1        $f16, 0x2928($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2928);
    // 0x80132690: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132694: lwc1        $f4, 0x292C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X292C);
    // 0x80132698: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8013269C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801326A0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801326A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801326A8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x801326AC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801326B0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801326B4: jal         0x80131FB4
    // 0x801326B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    mnScreenAdjustApplyCenterOffsets(rdram, ctx);
        goto after_23;
    // 0x801326B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_23:
L_801326BC:
    // 0x801326BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801326C0:
    // 0x801326C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801326C4: jr          $ra
    // 0x801326C8: nop

    return;
    // 0x801326C8: nop

;}
RECOMP_FUNC void mnVSResultsGetPointsDirect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C08: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80136C0C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136C10: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136C14: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80136C18: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80136C1C: lw          $t6, -0x6480($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6480);
    // 0x80136C20: lw          $t7, -0x6470($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6470);
    // 0x80136C24: jr          $ra
    // 0x80136C28: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    return;
    // 0x80136C28: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void itMewCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017ED54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017ED58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017ED5C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017ED60: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017ED64: bnel        $a1, $zero, L_8017ED8C
    if (ctx->r5 != 0) {
        // 0x8017ED68: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017ED8C;
    }
    goto skip_0;
    // 0x8017ED68: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017ED6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017ED70: nop

    // 0x8017ED74: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017ED78: jal         0x8017ED20
    // 0x8017ED7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itMewFlySetStatus(rdram, ctx);
        goto after_0;
    // 0x8017ED7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017ED80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017ED84: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017ED88: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017ED8C:
    // 0x8017ED8C: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017ED90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017ED94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017ED98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017ED9C: jr          $ra
    // 0x8017EDA0: nop

    return;
    // 0x8017EDA0: nop

;}
RECOMP_FUNC void func_ovl8_8037FF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FF40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037FF44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037FF48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8037FF4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8037FF50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037FF54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037FF58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037FF5C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8037FF60: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8037FF64: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8037FF68: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8037FF6C: beq         $a0, $zero, L_8037FFA0
    if (ctx->r4 == 0) {
        // 0x8037FF70: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8037FFA0;
    }
    // 0x8037FF70: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037FF74: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8037FF78: beq         $t6, $zero, L_8037FFA0
    if (ctx->r14 == 0) {
        // 0x8037FF7C: nop
    
            goto L_8037FFA0;
    }
    // 0x8037FF7C: nop

    // 0x8037FF80: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8037FF84:
    // 0x8037FF84: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8037FF88: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8037FF8C: beq         $v0, $zero, L_8037FFA0
    if (ctx->r2 == 0) {
        // 0x8037FF90: sw          $t8, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r24;
            goto L_8037FFA0;
    }
    // 0x8037FF90: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8037FF94: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8037FF98: bnel        $t9, $zero, L_8037FF84
    if (ctx->r25 != 0) {
        // 0x8037FF9C: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8037FF84;
    }
    goto skip_0;
    // 0x8037FF9C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8037FFA0:
    // 0x8037FFA0: beql        $a0, $zero, L_8038002C
    if (ctx->r4 == 0) {
        // 0x8037FFA4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8038002C;
    }
    goto skip_1;
    // 0x8037FFA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8037FFA8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8037FFAC: beql        $t0, $zero, L_8038002C
    if (ctx->r8 == 0) {
        // 0x8037FFB0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8038002C;
    }
    goto skip_2;
    // 0x8037FFB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8037FFB4: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8037FFB8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x8037FFBC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8037FFC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8037FFC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037FFC8: blezl       $t1, L_80380014
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8037FFCC: lw          $t6, 0x0($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X0);
            goto L_80380014;
    }
    goto skip_3;
    // 0x8037FFCC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x8037FFD0: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
L_8037FFD4:
    // 0x8037FFD4: addiu       $t3, $t2, 0xC
    ctx->r11 = ADD32(ctx->r10, 0XC);
    // 0x8037FFD8: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8037FFDC: jal         0x8037E7A8
    // 0x8037FFE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_0;
    // 0x8037FFE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8037FFE4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8037FFE8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037FFEC: beql        $at, $zero, L_8037FFFC
    if (ctx->r1 == 0) {
        // 0x8037FFF0: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_8037FFFC;
    }
    goto skip_4;
    // 0x8037FFF0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x8037FFF4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8037FFF8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_8037FFFC:
    // 0x8037FFFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80380000: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80380004: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80380008: bnel        $at, $zero, L_8037FFD4
    if (ctx->r1 != 0) {
        // 0x8038000C: lw          $t2, 0x0($s4)
        ctx->r10 = MEM_W(ctx->r20, 0X0);
            goto L_8037FFD4;
    }
    goto skip_5;
    // 0x8038000C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    skip_5:
    // 0x80380010: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
L_80380014:
    // 0x80380014: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80380018: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x8038001C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80380020: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80380024: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80380028: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8038002C:
    // 0x8038002C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380030: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80380034: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80380038: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8038003C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80380040: jr          $ra
    // 0x80380044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80380044: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void scManagerRunPrintGObjStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3048: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A304C: jal         0x80023778
    // 0x800A3050: addiu       $a0, $a0, 0x2E84
    ctx->r4 = ADD32(ctx->r4, 0X2E84);
    syDebugRunFuncPrint(rdram, ctx);
        goto after_0;
    // 0x800A3050: addiu       $a0, $a0, 0x2E84
    ctx->r4 = ADD32(ctx->r4, 0X2E84);
    after_0:
    // 0x800A3054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A305C: jr          $ra
    // 0x800A3060: nop

    return;
    // 0x800A3060: nop

;}
RECOMP_FUNC void func_ovl8_80374A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374A30: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80374A34: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80374A38: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x80374A3C: jalr        $t9
    // 0x80374A40: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374A40: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374A4C: jr          $ra
    // 0x80374A50: nop

    return;
    // 0x80374A50: nop

;}
